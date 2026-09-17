#ifndef PRO_IMM_H
#define PRO_IMM_H

#include <ProToolkit.h>
#include <ProObjects.h>



typedef struct Mopr_Toolkit_Data   *ProImmParams;

PRO_BEGIN_C_DECLS

/* Functions to initiate and set data to the ImmParam handle. */

extern ProError ProImmParamsAlloc ( ProImmParams *immparams );
/*

   Purpose:    Allocates the handle of a new ImmParam

   Input Arguments:
      none

   Output Arguments:
      immparams      - Pointer to the ImmParam handle

   Return Values:
      PRO_TK_NO_ERROR      - The handle is successfully allocated.
      PRO_TK_OUT_OF_MEMORY - Not enough memoryt to allocate the handle.

*/

extern ProError ProImmParamsFree ( ProImmParams *immparams );
/*
 
   Purpose:    Frees the handle of a ImmParam

   Input Arguments:
      immparams      - Pointer to the ImmParam handle

   Output Arguments:
      none
 
   Return Values:
      PRO_TK_NO_ERROR      - The handle is successfully freed;
      PRO_TK_BAD_INPUTS    - Can not free the handle
 
*/

extern ProError ProImmParamsDefaultSet ( ProName      machine_name,
                                         ProImmParams immparams );
/*
 
   Purpose:    Set default values for Imm selection dialog.

   Input Arguments:
      machine_name   - Injection machine name

   Output Arguments:
      immparams      - ImmParam handle
 
   Return Values:
      PRO_TK_NO_ERROR      - The values are successfully set;
      PRO_TK_BAD_INPUTS    - Specified parameters are incorrect.
*/

extern ProError ProImmDialog ( ProMdl        owner,
                               ProImmParams  immparams );
/*
 
 
   Purpose:    Invokes the regular Imm Selection dialog using defaults
               specified in immparams handle. Upon picking Ok in the dialog,
               all the data from it are set to the handle. Functions 
               ProImmParamsGet() and/or ProImmCreate() can be used 
               after this function is successfully completed.

   Input Arguments:
      owner         - Mold Layout Assembly handler

   Output Arguments:
      immparams      - ImmParam handle

   Return Values:
      PRO_TK_NO_ERROR      - The values are successfully set;
      PRO_TK_BAD_INPUTS    - Specified parameters are incorrect.
      PRO_TK_USER_ABORT    - User aborted the dialog

*/       

extern ProError ProImmParamsGet ( ProImmParams  immparams,
                                  ProName       machine_name,
                                  ProCharName **p_param_names,
                                  ProName     **p_param_values );
/*

   Purpose:  Retrieves the information about the Imm from immparams handle.
             The handle must be filled earlier by the functions 
             ProImmDialog() or ProImmGetFromModel().

 
   Input Arguments:
      immparams         - Pointer to the ImmParam handle
 

   Output Arguments:
      machine_name     - name of IMM (allocated by caller);

      p_param_names    - <i>ProArray</i> of Imm parameter names;
                         The user must pass a pre-allocated array. If the
			 array is reused, new elements will be appended to
			 the existing elements unless the array size is reset
			 to 0 with ProArraySizeSet.
      p_param_values   - <i>ProArray</i> of Imm parameter values;
                         The user must pass a pre-allocated array. If the
			 array is reused, new elements will be appended to
			 the existing elements unless the array size is reset
			 to 0 with ProArraySizeSet.
 
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/
 

extern ProError ProImmCreate ( ProImmParams immparams );
/*
 
 
   Purpose:    Retrieves and places Imm corresponding to parameters in 
               immparams handle. The handle must be filled earlier 
               by the function ProImmDialog().

   Input Arguments:
        immparams      - Pointer to the ImmParam handle

   Output Arguments:
        none
 
   Return Values:
        PRO_TK_NO_ERROR      - The specified Imm is successfully retrieved
                               and placed.
        PRO_TK_BAD_INPUTS    - Specified parameter is incorrect.
        
        PRO_TK_E_NOT_FOUND   - Cant retrieve the specified Imm;

        PRO_TK_ABORT         - Cant place the Imm. 

*/




extern ProError ProImmFromModelGet ( ProMdl        owner_model,
                                     ProImmParams *immparams );
/*
 
   Purpose:    Initialize the handle of ProImmParams using information
               about Imm assembled earlier into model owner_model.
 
   Input Arguments:
      owner_model   - Assembly containing Imm assembly as a subassembly;

   Output Arguments:
      immparams      - Pointer to the ImmParam handle.

   Return Values:
      PRO_TK_NO_ERROR      - The handle is successfully freed;
      PRO_TK_OUT_OF_MEMORY - Not enough memoryt to allocate the handle.
      PRO_TK_E_NOT_FOUND   - Imm is not found in owner_model.

*/

PRO_END_C_DECLS

#endif
