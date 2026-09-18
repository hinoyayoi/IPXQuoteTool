#ifndef PROFIT_H
#define PROFIT_H

/* Creo Parametric declarations for ProFit object related actions */
#include <ProObjects.h>
#include <ProMdl.h>
#include <ProToolkit.h>
#include <ProSelection.h>

/* History */



typedef  enum 
{
  PRO_FIT_WHOLE_SURFACE,
  PRO_FIT_NEAR_PICK_SURFACE
}ProFitPickType;	

typedef  enum 
{
  PRO_FIT_PART,
  PRO_FIT_SUB_ASSEMBLY, 
  PRO_FIT_PART_DETAILED, /* include pairs for which volume can't be calculated */ 
  PRO_FIT_SUB_ASSEMBLY_DETAILED
}ProFitComputeSetup;

typedef  enum 
{
  PRO_FIT_INCLUDE_NONE = 0,
  PRO_FIT_INCLUDE_FROM_QUILTS = 1,
  PRO_FIT_INCLUDE_TO_QUILTS = 2,  
  PRO_FIT_INCLUDE_FROM_FACETS = 3,
  PRO_FIT_INCLUDE_TO_FACETS = 4,   
  PRO_FIT_INCLUDE_FROM_FACETS_N_QUILTS = 5, 
  PRO_FIT_INCLUDE_TO_FACETS_N_QUILTS = 6 , 
  PRO_FIT_INCLUDE_FROM_QUILTS_X_HID = 7, /* X_HID stands for exclude hidden */
  PRO_FIT_INCLUDE_TO_QUILTS_X_HID = 8,   /* quilts from calculation         */ 
  PRO_FIT_INCLUDE_FROM_FACETS_N_QUILTS_X_HID = 9, 
  PRO_FIT_INCLUDE_TO_FACETS_N_QUILTS_X_HID = 10  
}ProFitComputeOptions;

typedef void *ProInterferenceData;  

typedef struct ProInterferenceinfo
{
  ProSelection part_1;
  ProSelection part_2;
  ProInterferenceData interf_data;
}ProInterferenceInfo;


/*===========================================================================*/
PRO_BEGIN_C_DECLS

typedef  enum 
{
  PRO_FIT_SURFACE_CLEARANCE,
  PRO_FIT_PART_CLEARANCE,
  PRO_FIT_PART_CLEARANCE_INCL_QUILTS  
}ProFitClearanceType;

extern ProError ProFitClearanceCompute(
    ProSelection    sel1,
    ProFitComputeOptions comp_opt_1,
    ProSelection    sel2,
    ProFitComputeOptions comp_opt_2, 
    ProFitPickType  pick_type, 
    ProSelection proj_reference,
    ProBoolean   view_plane,
    double          *clearance_dist,
    double          *proj_distance,
    ProBoolean      *is_interference_found,
    Pro3dPnt        pnt_arr[2]
    );
/*
   Purpose:       Computes the clearance between two objects. If the function
   		   is computing clearance between two parts then it also tries to 
                   determine if there is interfernece.      
    
   Input Arguments:
       sel1       -   The first selection. Not allowed to be NULL.
       comp_opt_1 -   The option for first selection.             
       sel2       -   The second selection whose clearance is to be calculated 
       		       with the first. Not allowed to be NULL.      
       comp_opt_2 -   The option for second selection.
       pick_type  -   The option to select the pick type.
       proj_reference - The  selection to calculate the projected clearance.
       view_plane -   If this is PRO_B_TRUE, the clearance calculated is with reference flat to screen.
       			If PRO_B_FALSE, the clearance calculated is with reference to proj_reference.
                        
   Output Arguments:
       clearance_dist  -   The total clearance between the selections.
       proj_distance   -   The clearance from the projection reference.
       is_interference_found - The interference between the selection. 
       				If this is PRO_B_TRUE, interference detected. 
                                In case of surface clearance, this value is undefined.
       pnt_arr         -    The co-ordinates of the closest points
                             with reference to the top-level assembly.

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully computed the clearance.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The clearance could not be computed.
*/

extern ProError ProFitGlobalinterferenceCompute(
    ProAssembly assem,
    ProFitComputeSetup comp_setup,
    ProBoolean set_facets,
    ProBoolean set_quilts,
    ProBoolean fast_calculation, 
    ProInterferenceInfo **interf_info
    );
/*
   Purpose:   Computes the interference in the specified assembly.  
   	      If the assembly is regenerated, the interference should be 
              recalculated.
    
   Input Arguments:
       assem      -   The assembly to be checked for interference.        
       comp_setup -   The setup to compute interference.
       set_facets -   The options to include facets.
       set_quilts -   The options to include quilts.       
       fast_calculation - The option to set the calculation to be either exact or fast.
                          Results of fast calculation may contain interferences which are
                          degenerate i.e. touching surfaces or vertices. In the exact 
                          calculation these cases are discarded. Interference information obtained
                          by fast calculation contains only the pairs of interfering components
                          and not the interference data. This data <b>must</b> be obtained by using 
                          ProFitInterferenceCompute() for each pair of interfering components before
                          it can be passed to ProFitInterferencevolumeCompute() 
                          or ProFitInterferencevolumeDisplay().
       
   Output Arguments:
       interf_info -   ProArray of structure containing information about interfering components. 
       			Free this using ProInterferenceInfoProarrayFree().

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully computed the interference.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The interference could not be computed.    
*/

extern ProError ProFitInterferenceCompute(
    ProSelection solid_1,
    ProSelection solid_2,
    ProBoolean set_facets,
    ProBoolean set_quilts,
    ProInterferenceData *interf_data
   );
/*
   Purpose:        Returns the interference information between two specified components. 
                   The data obtained using this API can be passed to 
                   ProFitInterferencevolumeCompute() and ProFitInterferencevolumeDisplay(). 
                   If the components are regenerated, the interferences should be recalculated.
    
   Input Arguments:
       solid_1    -   The first part.       
       solid_2    -   The second part. 
       set_facets -   The options to include facets.
       set_quilts -   The options to include quilts.

   Output Arguments:
      interf_data -   The interference data. 
                      If no interference detected, NULL value will be returned.
                       Free this using ProInterferenceDataFree().

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully computed the interference.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The interference could not be computed.     
*/

extern ProError ProFitInterferencevolumeCompute(    
   ProInterferenceData interf_data,
   double *volume
   );
/*
   Purpose:        Calculates volume of interference between two components. 
                   The interference volume can only be calculated if 
                   the interference data is obtained by using ProFitInterferenceCompute()
                   or ProFitGlobalinterferenceCompute() without including facets or quilts, 
                   that is only for interfering solids.
                   
    
   Input Arguments:
       interf_data -   The interference data. This is obtained using either 
                       ProFitGlobalinterferenceCompute() or ProFitInterferenceCompute().

   Output Arguments:
       volume     -   The volume of interference between the components.

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully computed the volume.
       PRO_TK_BAD_INPUTS    - Input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The volume could not be computed.
       PRO_TK_BAD_CONTEXT   - The interference data contains interference information 
                              obtained by including quilts and/or facets.
*/

extern ProError ProFitInterferencevolumeDisplay(    
   ProInterferenceData interf_data,
   ProColortype color
   );
/*
   Purpose:        Displays the volume of interference between the two specified components. 
    
   Input Arguments:
       interf_data -   The interference data. This is obtained using either 
                       ProFitGlobalinterferenceCompute() or ProFitInterferenceCompute(). 
       color       -   The color to display the interference between the components in.            

   Output Arguments: 
       none

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully displayed the interference.
       PRO_TK_BAD_INPUTS    - Input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The interference could not be displayed.
 */


extern ProError ProInterferenceDataFree( ProInterferenceData interf_data );
 /*
   Purpose:        Free the interference data obtained using ProFitInterferenceCompute() 
    
   Input Arguments:
       interf_data -   The interference data. 

   Output Arguments: 
       none

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully freed the memory.
       PRO_TK_BAD_INPUTS    - Input arguments are invalid.
 */
 
extern ProError ProInterferenceInfoProarrayFree( ProInterferenceInfo *interf_info );
 /*
   Purpose:        Free the interference information obtained using ProFitGlobalinterferenceCompute().
    
   Input Arguments:
       interf_info -   The ProArray of interference information.
       

   Output Arguments: 
       none

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully freed the memory.
       PRO_TK_BAD_INPUTS    - Input arguments are invalid.
 */
 
PRO_END_C_DECLS

#endif  /* PROFIT_H */
