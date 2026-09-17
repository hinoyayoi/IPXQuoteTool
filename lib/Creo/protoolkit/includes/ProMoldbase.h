#ifndef PRO_MLD_BASE_H
#define PRO_MLD_BASE_H

#include <ProToolkit.h>
#include <ProObjects.h>



typedef struct Mopr_Toolkit_Data   *ProMoldbaseParams;

PRO_BEGIN_C_DECLS

/* Functions to initiate and set data to the MoldbaseParam handle. */

extern ProError ProMoldbaseParamsAlloc ( ProMoldbaseParams *mbparams );
/*

   Purpose:    Allocates the handle of a new MoldbaseParam

   Input Arguments:
      none

   Output Arguments:
      mbparams      - Pointer to the MoldbaseParam handle

   Return Values:
      PRO_TK_NO_ERROR      - The handle is successfully allocated.
      PRO_TK_OUT_OF_MEMORY - Not enough memoryt to allocate the handle.

*/

extern ProError ProMoldbaseParamsFree ( ProMoldbaseParams *mbparams );
/*
 
   Purpose:    Frees the handle of a MoldbaseParam

   Input Arguments:
      mbparams      - Pointer to the MoldbaseParam handle

   Output Arguments:
      none
 
   Return Values:
      PRO_TK_NO_ERROR      - The handle is successfully freed;
      PRO_TK_BAD_INPUTS    - Can not free the handle
 
*/

extern ProError ProMoldbaseParamsDefaultSet ( ProName           vendor,
                                              ProName           series,
                                              ProName           length,
                                              ProName           width,
                                              ProMoldbaseParams mbparams );
/*
 
   Purpose:    Set default values for Moldbase selection dialog.

   Input Arguments:
      vendor        - vendor name

      series        - series name

      length        - length value
 
      width         - width value

   Output Arguments:
      mbparams      - MoldbaseParam handle
 
   Return Values:
      PRO_TK_NO_ERROR      - The values are successfully set;
      PRO_TK_BAD_INPUTS    - Specified parameters are incorrect.
*/

extern ProError ProMoldbaseDialog ( ProMdl            owner,
                                    ProMoldbaseParams mbparams );
/*
 
 
   Purpose:    Invokes the regular Mold Base Selection dialog using defaults
               specified in mbparams handle. Upon picking Ok in the dialog,
               all the data from it are set to the handle. Functions 
               ProMoldbaseParamsGet() and/or ProMoldbaseCreate() can be used 
               after this function is successfully completed.

   Input Arguments:
      owner         - Mold Layout Assembly handler

   Output Arguments:
      mbparams      - MoldbaseParam handle

   Return Values:
      PRO_TK_NO_ERROR      - The values are successfully set;
      PRO_TK_BAD_INPUTS    - Specified parameters are incorrect.
      PRO_TK_USER_ABORT    - User aborted the dialog

*/       

extern ProError ProMoldbaseParamsGet ( ProMoldbaseParams mbparams,
                                       ProMdl            *owner,
                                       ProName           vendor,
                                       ProName           series,
                                       ProName           length,
                                       ProName           width,
                                       ProCharName     **p_param_names,
                                       ProName         **p_param_values,
                                       double           *rotation_angle );
/*

   Purpose:  Retrieves the information about the Moldbase from mbparams handle.
             The handle must be filled earlier by the functions 
             ProMoldbaseDialog() or ProMoldbaseGetFromModel().

 
   Input Arguments:
      mbparams         - Pointer to the MoldbaseParam handle
 

   Output Arguments:
      owner            - Mold Layout Assembly handler
	  vendor           - The vendor
      series           - The series
      length           - The length
      width            - The width
      p_param_names    - <i>ProArray</i> of Moldbase parameter names;
                         The user must pass a pre-allocated array. If the
			 array is reused, new elements will be appended to
			 the existing elements unless the array size is
			 reset to 0 with ProArraySizeSet.
      p_param_values   - <i>ProArray</i> of Moldbase parameter values;
                         The user must pass a pre-allocated array. If the
			 array is reused, new elements will be appended to
			 the existing elements unless the array size is
			 reset to 0 with ProArraySizeSet.
      rotation_angle   - rotation angle used in Moldbase placement.
 
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/
 

extern ProError ProMoldbaseCreate ( ProMoldbaseParams mbparams );
/*
 
 
   Purpose:    Retrieves and places Mold Base corresponding to parameters in 
               mbparams handle. The handle must be filled earlier 
               by the function ProMoldbaseDialog().

   Input Arguments:
        mbparams      - Pointer to the MoldbaseParam handle

   Output Arguments:
        none
 
   Return Values:
        PRO_TK_NO_ERROR      - The specified Moldbase is successfully retrieved
                               and placed.
        PRO_TK_BAD_INPUTS    - Specified parameter is incorrect.
        
        PRO_TK_E_NOT_FOUND   - Cant retrieve the specified Moldbase;

        PRO_TK_ABORT         - Cant place the Moldbase. 

*/




extern ProError ProMoldbaseFromModelGet ( ProMdl             owner_model,
                                          ProMoldbaseParams *mbparams );
/*
 
   Purpose:    Initialize the handle of ProMoldbaseParams using information
               about Moldbase assembled earlier into model owner_model.
 
   Input Arguments:
      owner_model   - Assembly containing Moldbase assembly as a subassembly;

   Output Arguments:
      mbparams      - Pointer to the MoldbaseParam handle.

   Return Values:
      PRO_TK_NO_ERROR      - The handle is successfully freed;
      PRO_TK_OUT_OF_MEMORY - Not enough memoryt to allocate the handle.
      PRO_TK_E_NOT_FOUND   - Moldbase is not found in owner_model.

*/

PRO_END_C_DECLS

#endif
