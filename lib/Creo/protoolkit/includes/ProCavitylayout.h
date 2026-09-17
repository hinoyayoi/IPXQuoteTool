#ifndef PRO_MLDLAY_H
#define PRO_MLDLAY_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProGeomitem.h>
#include <ProCavlayrule.h>



typedef void   *ProCavityLayout; 


PRO_BEGIN_C_DECLS

/* Functions to initiate and set data to the Cavity Layout handle */

extern ProError ProCavitylayoutAlloc (ProMdl           owner,
                                      ProCavityLayout *cvlayout);
/*
   Purpose:    Allocates the handle of a new cavity layout 

   Input Arguments:
      owner                  - The top assembly to own the layout
                               (may be either regular assembly or
                                mold/casting model)
 
   Output Arguments:
      cvlayout               - Pointer to the layout handle
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully allocated.
        PRO_TK_E_NOT_FOUND    - The owner handle is invalid
        PRO_TK_OUT_OF_MEMORY - Cannot allocate the handle
  
*/

extern ProError ProCavitylayoutFree (ProCavityLayout *cvlayout);
/*
   Purpose:    Frees the handle of a cavity layout 

   Input Arguments:
      cvlayout               - Pointer to the layout handle

   Output Arguments:
      none
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully freed.
        PRO_TK_BAD_INPUTS    - Can not free the handle
  
*/

extern ProError ProCavitylayoutGetByNumber (ProMdl     owner_assem,
                              int  n,  ProCavityLayout *cvlayout);
/*
   Purpose:    Initializes the handle
               of the n-th cavity layout.
               The function ProCavitylayoutCountGet() should be called first 
               to find out the number of existing layouts.   
 
   Input Arguments:
      owner_assem            - The top assembly to own the layout
                               (may be either regular assembly or
                                mold/casting model)
      n                      - the number identifying the layout
 
   Output Arguments:
      cvlayout               - Pointer to the layout handle
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully initialized.
        PRO_TK_BAD_INPUTS    - The owner type is not allowed
        PRO_TK_GENERAL_ERROR  - The selected component does not belong
                               to any cavity layout.
*/
 


extern ProError ProCavitylayoutSelect (ProMdl           owner_assem,
                                       ProCavityLayout *cvlayout);
/*
   Purpose:    Upon selection of a component initializes the handle
               of the cavity layout where this component belongs
 
   Input Arguments:
      owner_assem            - The top assembly to own the layout
                               (may be either regular assembly or
                                mold/casting model)
 
   Output Arguments:
      cvlayout               - Pointer to the layout handle
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully initialized.
        PRO_TK_BAD_INPUTS    - The owner type is not allowed
        PRO_TK_E_NOT_FOUND   - The selected component does not belong
                               to any cavity layout.
        PRO_TK_GENERAL_ERROR - Cannot initialize the handle
 
*/

extern ProError ProCavitylayoutLeaderSet (ProCavityLayout cvlayout,
                                          ProMdl        in_leader,
                                          ProName      ref_name,
                                          ProMdl      *out_leader);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProCavitylayoutLeaderMdlnameSet
   Purpose: <b>Note:</b> This function is deprecated
            Use ProCavitylayoutLeaderMdlnameSet instead.

               Sets a leader model for the cavity layout
               (NOTE: The leader model cannot be reset in the
                      handle of the existing cavity layout)

 
   Input Arguments:
      cvlayout               - Pointer to the layout handle;

      in_leader              - The leader model (must be a mold/casting
                               model if the layout owner is a regular
                               assembly, and mold/casting design model
                               if the owner is mold/casting);

      ref_name               - Unique name for the reference model to be created
                               for the design model in_leader. This argument
                               has sense only if the owner is mold/casting.

   Output Arguments:
      out_leader             - The result leader model set. It is the same as
                               in_leader if if the layout owner is a regular
                               assembly, and mold/casting reference model
                               if the owner is mold/casting)

 
   Return Values:
        PRO_TK_NO_ERROR      - The model is successfully set.
        PRO_TK_BAD_INPUTS    - The layout handle is not initialized or
                               the leader type is not allowed or 
                               does not correspond to the owner type.
        PRO_TK_GENERAL_ERROR - Cannot set the leader model.
  
*/

extern ProError ProCavitylayoutLeaderMdlnameSet (ProCavityLayout cvlayout,
                                                 ProMdl        in_leader,
                                                 ProMdlName    ref_name,
                                                 ProMdl      *out_leader);
/*
   Purpose:    Sets a leader model for the cavity layout
               (NOTE: The leader model cannot be reset in the
                      handle of the existing cavity layout)

			   <b>Note: </b> In Creo 3 this function does not differ in behavior 
			   from superseded ProCavitylayoutLeaderSet. In particular, ref_name 
			   can be only of ProName length. This function is reserved for future use.


   Input Arguments:
      cvlayout               - Pointer to the layout handle;

      in_leader              - The leader model (must be a mold/casting
                               model if the layout owner is a regular
                               assembly, and mold/casting design model
                               if the owner is mold/casting);

      ref_name               - Unique name for the reference model to be created
                               for the design model in_leader. This argument
                               has sense only if the owner is mold/casting.

   Output Arguments:
      out_leader             - The result leader model set. It is the same as
                               in_leader if if the layout owner is a regular
                               assembly, and mold/casting reference model
                               if the owner is mold/casting)

 
   Return Values:
        PRO_TK_NO_ERROR      - The model is successfully set.
        PRO_TK_BAD_INPUTS    - The layout handle is not initialized or
                               the leader type is not allowed or 
                               does not correspond to the owner type.
        PRO_TK_GENERAL_ERROR - Cannot set the leader model.
  
*/

extern ProError ProCavitylayoutOriginSet (ProCavityLayout cvlayout,
                                          ProAsmcomppath *csys_comp_path,
                                          ProCsys          owner_csys);
/*
   Purpose:    Sets the cavity layout origin
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle;

      csys_comp_path         - component path from the layout owner to the Csys
                               owner;
 
      owner_csys             - Coordinate system belonging to the model set
                               by csys_comp_path.
 
   Output Arguments:
      NONE
 
   Return Values:
        PRO_TK_NO_ERROR      - The origin is successfully set.
        PRO_TK_BAD_INPUTS    - The given csys does not belong to 
                               the specified owner.
        PRO_TK_GENERAL_ERROR - Cannot set the layout origin.
 
*/

extern ProError ProCavitylayoutLeaderCsysSet (ProCavityLayout cvlayout,
                                              ProAsmcomppath *csys_comp_path,
                                              ProCsys       leader_csys);
/*
   Purpose:    Sets coordinate system in the leader model
               to be used for placement of the layout members
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle;

      csys_comp_path         - component path from the layout leader to the Csys
                               owner.
 
      leader_csys            - Coordinate system belonging to the model set
                               by csys_comp_path.

 
   Output Arguments:
      NONE
 
   Return Values:
        PRO_TK_NO_ERROR      - The layout leader csys is successfully set.
        PRO_TK_BAD_INPUTS    - The given csys does not belong to
                               the layout leader model.
        PRO_TK_GENERAL_ERROR - Cannot set the layout leader csys.
 
*/

extern ProError ProCavitylayoutRuleSet (ProCavityLayout cvlayout,
                                        ProCvLayoutRule rule);
/*
   Purpose:    Sets a rule for the cavity layout
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
      rule                   - The cavity layout rule
 
   Output Arguments:
      NONE
 
   Return Values:
        PRO_TK_NO_ERROR      - The rule is successfully set.
        PRO_TK_BAD_INPUTS    - The rule has invalid data
        PRO_TK_GENERAL_ERROR - Cannot set the layout rule.
 
*/


extern ProError ProCavitylayoutModelnamesSet (ProCavityLayout cvlayout,
                                              ProName *repl_models);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProCavitylayoutModelMdlnamesSet
   Purpose: <b>Note:</b> This function is deprecated
            Use ProCavitylayoutModelMdlnamesSet instead.

               For Cavity Layout with Rule set to Variable replaces patern
               models with their family table instances. The leader model
               will not be replaced.


   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
      repl_models            - <i>ProArray</i> of instance names replacing
                               layout model. Number of elements in the array
                               should be equal to the number of rows in variable
                               layout table. The name coresponding to the layout
                               leader will be ignored.

   Output Arguments:
      none 

   Return Values:
        PRO_TK_NO_ERROR      - The models are successfully replaced.
        PRO_TK_BAD_INPUTS    - The entered data is incorrect.
        PRO_TK_GENERAL_ERROR - Cannot replace the layout models.
 
*/

extern ProError ProCavitylayoutModelMdlnamesSet (ProCavityLayout cvlayout,
						 ProMdlName *repl_models);
/*
   Purpose:    For Cavity Layout with Rule set to Variable replaces patern
               models with their family table instances. The leader model
               will not be replaced.


			   <b>Note: </b> In Creo 3 this function does not differ in behavior 
			   from superseded ProCavitylayoutModelnamesSet. In particular, 
			   repl_models can be only of ProName length. 
			   This function is reserved for future use.

   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
      repl_models            - <i>ProArray</i> of instance names replacing
                               layout model. Number of elements in the array
                               should be equal to the number of rows in variable
                               layout table. The name coresponding to the layout
                               leader will be ignored.

   Output Arguments:
      none 

   Return Values:
        PRO_TK_NO_ERROR      - The models are successfully replaced.
        PRO_TK_BAD_INPUTS    - The entered data is incorrect.
        PRO_TK_GENERAL_ERROR - Cannot replace the layout models.
 
*/
                                               

extern ProError ProCavitylayoutCreate (ProCavityLayout cvlayout);
/*
   Purpose:    Creates a new Cavity Layout (component pattern) according to 
               the data from the handle.  
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      NONE
 
   Return Values:
        PRO_TK_NO_ERROR      - The layout is successfully created.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_FOUND       - The cavity layout corresponding to the handle
                               already exists.
        PRO_TK_GENERAL_ERROR - Cannot create the cavity layout
 
*/

extern ProError ProCavitylayoutRedefine (ProCavityLayout cvlayout);
/*
   Purpose:    Recreates an existing Cavity Layout according to the data 
               from its handle.  
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      NONE
 
   Return Values:
        PRO_TK_NO_ERROR      - The layout is successfully recreated.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_NOT_FOUND   - The cavity layout corresponding to the handle
                               does not exists.
        PRO_TK_GENERAL_ERROR - Cannot create the cavity layout
 
*/


/*  Functions to get data from the Cavity Layout handle  */

extern ProError ProCavitylayoutLeaderCompGet (ProCavityLayout cvlayout,
                                             ProAsmcomppath *leader_comp);
/*
   Purpose:    Given the Cavity Layout handle of an existing layout,
               gets the leader component of the layout 
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      leader_comp            - Component path to the leader component
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_NOT_FOUND   - The cavity layout corresponding to the handle
                               does not exists.
 
*/

extern ProError ProCavitylayoutLeaderGet (ProCavityLayout cvlayout,
                                          ProMdl   *leader_model);
/*
   Purpose:    Given the Cavity Layout handle of an existing layout,
               gets the model of the pattern leader component 
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      leader_model            - model of the pattern leader component
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_NOT_FOUND   - The cavity layout corresponding to the handle
                               does not exists.
 
*/

extern ProError ProCavitylayoutOriginGet (ProCavityLayout cvlayout,
                                          ProAsmcomppath *csys_comp_path,
                                          ProCsys         *owner_csys);
/*
   Purpose:    Given the Cavity Layout handle of an existing layout,
               gets the coordinate system of the top assembly used
               for the placement of layout
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      csys_comp_path        -  component path to coordinate system
      owner_csys            -  top assembly coordinate system      
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_NOT_FOUND   - The cavity layout corresponding to the handle
                               does not exists.
 
*/

extern ProError ProCavitylayoutLeaderCsysGet (ProCavityLayout cvlayout,
                                              ProAsmcomppath *csys_comp_path,
                                              ProCsys         *owner_csys);
/*
   Purpose:    Given the Cavity Layout handle of an existing layout,
               gets the coordinate system of the model used for
               the placement of layout
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      csys_comp_path        -  component path to coordinate system
      owner_csys            -  coordinate system of the model     
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_NOT_FOUND   - The cavity layout corresponding to the handle
                               does not exists.
 
*/

extern ProError ProCavitylayoutRuleGet (ProCavityLayout cvlayout,
                                        ProCvLayoutRule *rule);
/*
   Purpose:    Given the Cavity Layout handle of an existing layout,
               gets the coordinate system of the model used for
               the placement of layout
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle
 
   Output Arguments:
      rule                   - Rule currently used by the layout    
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The handle has invalid data or not initiated
        PRO_TK_E_NOT_FOUND   - The cavity layout corresponding to the handle
                               does not exists.
*/
 

extern ProError ProCavitylayoutModelnamesGet (ProCavityLayout cvlayout,
                                              ProName **repl_models);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProCavitylayoutModelMdlnamesGet
   Purpose: <b>Note:</b> This function is deprecated
            Use ProCavitylayoutModelMdlnamesGet instead.

               For Cavity Layout with Rule set to Variable gets the information
               about patern models replacement.
 
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle

   Output Arguments:
      repl_models            - <i>ProArray</i> of instance names replacing
                               layout model. Number of elements in the array
                               will be equal to the number of rows in variable
                               layout table.
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The entered data is incorrect.
        PRO_TK_GENERAL_ERROR - Cannot get the requested info.
*/

extern ProError ProCavitylayoutModelMdlnamesGet (ProCavityLayout cvlayout,
						 ProMdlName    **repl_models);
/*
   Purpose:    For Cavity Layout with Rule set to Variable gets the information
               about patern models replacement.
 
 
   Input Arguments:
      cvlayout               - Pointer to the layout handle

   Output Arguments:
      repl_models            - <i>ProArray</i> of instance names replacing
                               layout model. Number of elements in the array
                               will be equal to the number of rows in variable
                               layout table. Free this argument using
                               ProArrayFree.
 
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The entered data is incorrect.
        PRO_TK_GENERAL_ERROR - Cannot get the requested info.
*/
 
extern ProError ProCavitylayoutOutlineGet (ProCavityLayout cvlayout,
                            double *min_x, double *min_y, double *min_z,
                            double *max_x, double *max_y, double *max_z);
/*
   Purpose:    Given the Cavity Layout handle of an existing layout 
               get the information about its outline.

   Input Arguments:
      cvlayout               - Pointer to the layout handle

   Output Arguments:
      min_x                  - minimal value along X axis

      min_y                  - minimal value along Y axis

      min_z                  - minimal value along Z axis

      max_x                  - maximal value along X axis

      max_y                  - maximal value along Y axis

      max_z                  - maximal value along Z axis

   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The entered data is incorrect.
        PRO_TK_GENERAL_ERROR - Cannot get the requested info.
*/

extern ProError  ProCavitylayoutCountGet (ProMdl  owner_assem, 
                                          int *count);
/*
    Purpose:    Gets the number of layouts owned by
                given top assembly.

    Input Arguments:
     owner_assem            - The top assembly to own the layout
                               (may be either regular assembly or
                                mold/casting model)
    Output Arguments:
     count                  - number of layouts  
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully received.
        PRO_TK_BAD_INPUTS    - The entered data is incorrect.

*/

/*  Notification functions  */

PRO_END_C_DECLS

#endif
