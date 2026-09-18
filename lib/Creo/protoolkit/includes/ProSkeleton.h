#ifndef PROSKELETON_H
#define PROSKELETON_H




/* Creo Parametric TOOLKIT declarations for Pro<object> related data structures */

#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS


/* Data definitions */

extern ProError ProAsmSkeletonCreate (ProAssembly   assembly,
                                      ProName       skel_name,
                                      ProMdl        template_model,
                                      ProMdl       *p_skel);
/*
  DEPRECATED: Since Creo 3
  SUCCESSORS: ProAsmSkeletonMdlnameCreate
  Purpose: <b>Note:</b> This function is deprecated
           Use ProAsmSkeletonMdlnameCreate instead.

             Create a new skeleton model with specified name
             and adds it to the specified assemby. This function also  
             initializes the model handle.

  Input Arguments:
     assembly   -     Handle to the assembly.
     skel_name  -     Name of the skeleton model.
     template_model - Handle to a part or skeleton to be used as a
                      template. The template is copied into the created
                      skeleton model. If the handler to the template is
                      NULL, the new skeleton is created empty.

  Output Arguments:
     p_skel   -     Handle to the created skeleton model.

  Return Values:
     PRO_TK_NO_ERROR      -  Skeleton creation was successful.
     PRO_TK_BAD_INPUTS    -  Invalid assembly handle, skeleton name,
                             or template handle.
     PRO_TK_E_FOUND       -  Skeleton model already exists in the assembly.
     PRO_TK_ABORT         -  Template type is invalid (for example, is a 
                             manufacturing part), or has external
                             external dependencies. Copying is aborted.
     PRO_TK_GENERAL_ERROR -  Skeleton could not be created.
     PRO_TK_NOT_VALID     -  Required license is absent.
     PRO_TK_UNSUPPORTED   -  Models which come from Multi-CAD
                              approach are not supported as template model.
*/

extern ProError ProAsmSkeletonMdlnameCreate (ProAssembly   assembly,
                                             ProMdlName    skel_name,
                                             ProMdl        template_model,
                                             ProMdl       *p_skel);
/*
  Purpose:   Create a new skeleton model with specified name
             and adds it to the specified assemby. This function also  
             initializes the model handle.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

  Input Arguments:
     assembly   -     Handle to the assembly.
     skel_name  -     Name of the skeleton model.
     template_model - Handle to a part or skeleton to be used as a
                      template. The template is copied into the created
                      skeleton model. If the handler to the template is
                      NULL, the new skeleton is created empty.

  Output Arguments:
     p_skel   -     Handle to the created skeleton model.

  Return Values:
     PRO_TK_NO_ERROR      -  Skeleton creation was successful.
     PRO_TK_BAD_INPUTS    -  Invalid assembly handle, skeleton name,
                             or template handle.
     PRO_TK_E_FOUND       -  Skeleton model already exists in the assembly.
     PRO_TK_ABORT         -  Template type is invalid (for example, is a 
                             manufacturing part), or has external
                             external dependencies. Copying is aborted.
     PRO_TK_GENERAL_ERROR -  Skeleton could not be created.
     PRO_TK_NOT_VALID     -  Required license is absent.
     PRO_TK_UNSUPPORTED   -  Models which come from Multi-CAD
                              approach are not supported as template model.
	 PRO_TK_LINE_TOO_LONG -  Name length of skeleton model is more than 31 chars.

*/

extern ProError ProAsmSkeletonAdd (ProAssembly   assembly,
                                   ProMdl        skeleton);
/*

  Purpose:  Add an existing skeleton model as a skeleton in 
            the specified assembly.

  Input Arguments:
     assembly   -  Handle to the assembly.
     skeleton   -  Handle to the skeleton model.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      -  Skeleton addition is successful.
     PRO_TK_BAD_INPUTS    -  Invalid assembly handle or skeleton handle.
     PRO_TK_INVALID_TYPE  -  Skeleton is a handle not to a skeleton model.
     PRO_TK_E_FOUND       -  Skeleton model already exists in the assembly.
     PRO_TK_GENERAL_ERROR -  Skeleton could not be created.
     PRO_TK_NOT_VALID     -  Required license not found.
*/

extern ProError ProAsmSkeletonGet (ProAssembly   assembly,
                                   ProMdl       *p_skel);
/*
  Purpose:  Get a skeleton model of the specified assembly and
            initializes the model handle.

  Input Arguments:
     assembly  -  Handle to the assembly.

  Output Arguments:
     p_skel    -  Pointer to the assembly skeleton model handle.

  Return Values:
     PRO_TK_NO_ERROR      -  The skeleton handle is initiated.
     PRO_TK_BAD_INPUTS    -  Invalid assembly handle.
     PRO_TK_E_NOT_FOUND   -  The specified assembly has no
                             skeleton model.
     PRO_TK_CANT_ACCESS   -  The skeleton exists, but can not be used.
     PRO_TK_NOT_VALID     -  Required license not found.
*/

extern ProError ProMdlIsSkeleton (ProMdl        model,
                                  ProBoolean   *p_is_skel);
/*
  Purpose:  Determine whether the specified model is a skeleton model.

   Input Arguments:
     model   - Handle to the model to be checked.

   Output Arguments:
     p_is_skel - PRO_B_TRUE if specified model is a skeleton model,
                 otherwise PRO_B_FALSE.

   Return Values:
     PRO_TK_NO_ERROR      -  The function successfully returned
                             the information.
     PRO_TK_BAD_INPUTS    -  Invalid model handler.
     PRO_TK_NOT_VALID     -  Required license not found.
*/

extern ProError ProAsmSkeletonDelete (ProAssembly   assembly);
/*
   Purpose:  Delete a skeleton model component from the assembly.

   Input Arguments:
     assembly  -  Handle to the assembly.

   Output Arguments:
     none


   Return Values:
     PRO_TK_NO_ERROR     -  Skeleton model component successfully deleted.
     PRO_TK_BAD_INPUTS   -  Invalid assembly handler.
     PRO_TK_E_NOT_FOUND  -  The specified assembly has no skeleton model. 
     PRO_TK_NOT_VALID    -  Required license not found.
     PRO_TK_GENERAL_ERROR - Skeleton component could not be deleted.

*/

PRO_END_C_DECLS

#endif /* PROSKELETON_H */
