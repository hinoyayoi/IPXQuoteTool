#ifndef PRO_VOL_INTF
#define PRO_VOL_INTF



#include <ProSelection.h>
#include <ProObjects.h>
#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

typedef struct volume_intf_data *ProVolumeInterferenceData;  

typedef struct ProVolumeIntfInfo
{
  ProAsmcomppath comp;                  /*component interfering with the quilt*/
  ProVolumeInterferenceData intf_data; /* Resulting volume interference data */
} ProVolumeInterferenceInfo;

extern ProError ProVolumeInterferenceCompute (ProSelection quilt, 
                    ProVolumeInterferenceInfo **p_intf_infos);
/*
  Purpose: This function computes volume interference of the selected closed 
           quilt with the assembly as it is done in the Volume Interference UI.

      
Input Argument:
           quilt - The quilt with which the interefrance should be computed
      
Output Argument:
           p_intf_infos - pointer to a ProArray (allocated inside) where
                          the interference results will be stored,
                          users need to free the allocated array using 
                          ProVolumeInterferenceInfoArrayFree


Return Values:
           PRO_TK_NO_ERROR      - The function succeeded.
           PRO_TK_GENERAL_ERROR - An error is encountered.
           PRO_TK_BAD_INPUTS    - The input argument is invalid.
See Also:
        ProVolumeInterferenceInfoArrayFree ()
*/


extern ProError ProVolumeInterferenceDisplay (
                    ProVolumeInterferenceData interf_data,
                    ProColortype color, ProBool hilite);
/*
  Purpose: 
          This function should be called after ProVolumeInterferenceCompute().
          It will display/hide the curves and surfaces that interfere 
          with the closed quilt that was selected by user. 
      
Input Arguments:
          inetrf_data - pointer to the interference data for the corresponding 
                        component that interfere with the quilt
          color       - The preferred color for highlighting the ineterference
          hilite      - PRO_B_TRUE for displaying or PRO_B_FALSE for hiding
                        the current component interference data.
             
Output Arguments:
                  None
      
Return Values:
              PRO_TK_NO_ERROR      - The function succeeded.
              PRO_TK_GENERAL_ERROR - A general error is encountered.
              PRO_TK_BAD_INPUTS    - The input argument is invalid.
*/
        
extern ProError ProVolumeInterferenceInfoArrayFree (
                    ProVolumeInterferenceInfo *p_intf_infos);
/*
  Purpose: This function frees the memory that was allocated by 
           ProVolumeInterferenceCompute().
           Call this API to remove the interference 
           highlighted by the function ProVolumeInterferenceDisplay.
           This function also refreshes the screen

      
Input Arguments:
       p_intf_infos - pointer to the interference data array that is no longer 
	              needed and should be freed.
		  
Output Arguments:
                  None
      
Return Values:
             PRO_TK_NO_ERROR      - The function succeeded.
             PRO_TK_GENERAL_ERROR - A general error is encountered.
             PRO_TK_BAD_INPUTS    - Pointer to the interference data array is invalid.

*/

PRO_END_C_DECLS

#endif 

