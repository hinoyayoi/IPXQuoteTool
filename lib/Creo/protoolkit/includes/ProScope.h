#ifndef PROSCOPE_H
#define PROSCOPE_H




/* Creo Parametric TOOLKIT declarations for Pro<object> related data structures */

#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS


/* Data definitions */

typedef enum
{
  PRO_REFCTRL_ALLOW_ALL           = 0, /* all external references allowed    */

  PRO_REFCTRL_ALLOW_SUBASSEMBLY   = 1, /* allowed only external references
                                          inside the same higher level
                                          subassembly as that
                                          of the modified object             */

  PRO_REFCTRL_ALLOW_SKELETON      = 2, /* only external references to
                                          skeleton models allowed            */

  PRO_REFCTRL_ALLOW_NONE          = 3  /* no external references allowed     */

} ProExtRefScope;                      /* definition of allowed scope
                                          for external referencing           */


typedef enum
{
  PRO_REFCTRL_BACKUP_REF       = 0,   /* create a local backup for
                                         out-of-scope references             */

  PRO_REFCTRL_PROHIBIT_REF     = 1    /* prohibit out-of-scope external
                                         references                          */

} ProInvalidRefBehavior;              /* definition of the system handling
                                         of out-of-scope external references */


extern ProError ProRefCtrlSolidSet ( ProSolid              solid,
                                     ProExtRefScope        scope,
                                     ProInvalidRefBehavior behavior );
/*
   Purpose: Set a specified external reference control for solid, that is, for a 
            part or assembly.

   Input Arguments:
     solid       - The scope owner where reference control options are embedded. 
     scope       - External reference scope criterion.
     behavior    - Defines behavior on scope violation.

   Output Arguments:
    None

   Return Values:
     PRO_TK_NO_ERROR      -  External reference control successfully set.
     PRO_TK_BAD_INPUTS    -  The solid handle is invalid.
     PRO_TK_INVALID_TYPE  -  The settings are invalid.
     PRO_TK_NOT_VALID     -  Config options setting disallows changing
                             object reference control; or  
                             required license not found.
*/

extern ProError ProRefCtrlSolidGet ( ProSolid               solid,
                                     ProExtRefScope        *p_scope,
                                     ProInvalidRefBehavior *p_behavior );
/*
   Purpose: Return the external reference control defined for the specified 
            solid (part or assembly).

   Input Arguments:
     solid       - The scope owner where the reference control options are set.

   Output Arguments:
     p_scope     - External reference scope criterion.
     p_behavior  - Defines behavior on scope violation. 

   Return Values:
     PRO_TK_NO_ERROR     -  Reference control information successfully returned.
     PRO_TK_BAD_INPUTS   -  The solid handle is invalid.
     PRO_TK_E_NOT_FOUND  -  No reference control options are set in the model.
     PRO_TK_NOT_VALID    -  Required license not found.
*/

extern ProError ProRefCtrlEnvirSet ( ProExtRefScope         scope,
                                     ProInvalidRefBehavior  behavior );
/*
  Purpose: Set run-time environment options for external reference control.

   Input Arguments:
     scope       - External reference scope criterion.
     behavior    - Defines behavior on scope violation.

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR      -  Environment information successfully set.
     PRO_TK_BAD_INPUTS    -  The settings are invalid.
     PRO_TK_NOT_VALID     -  Config options setting disallows changing
                             reference control; or  
                             required license not found.
*/

extern ProError ProRefCtrlEnvirGet ( ProExtRefScope        *p_scope,
                                     ProInvalidRefBehavior *p_behavior );
/*
   Purpose: Return run-time environment options for external reference control.

   Input Arguments:
     None

   Output Arguments:
     p_scope     - External reference scope criterion.
     p_behavior  - Defines behavior on scope violation.

   Return Values:
     PRO_TK_NO_ERROR      -  Environment information successfully returned.
     PRO_TK_NOT_VALID     -  Required license not found.
*/

extern ProError ProRefCtrlCheckScope ( ProSolid        solid,
                                       ProAsmcomppath *own_comp,
                                       ProSolid        ref_solid,
                                       ProAsmcomppath *ref_comp,
                                       ProMdl         *p_scope_owner );

/*
   Purpose: Check if object-specific reference control settings for the specified
            model (independent object or assembly component) allow that model to
            reference information belonging to a different model. The top-level
            assembly for the component being modified and for the component being 
            referenced must be the same. 

   Input Arguments:
       solid       - Handle to solid (part or assembly) being modified.         
                     Must not be NULL.
       own_comp    - Handle to path for component being modified (in context of
                     its top assembly). Must not be NULL.
       ref_solid   - Handle to the solid being referenced. Must not be NULL.
       ref_comp    - Handle to path for the component being referenced (in
                     context of its top assembly). Must not be NULL.
      <p>
      <b>NOTE:</b>
      <p> 
      The top assembly in own_comp and ref_comp must be the same. If the
      owner of own_comp is NULL and ref_solid is not a sub model or solid,
      then the reference is checked as an "Out of Assembly Context" reference. An
      example is references through relations.

   Output Arguments:
       p_scope_owner - Handle to solid that owns scope being violated.
                       If NULL but there is a violation, then the
                       environment scope setting is violated.

   Return Values:
     PRO_TK_NO_ERROR      -  No scope violation, reference is allowed.
     PRO_TK_E_FOUND       -  Reference control violation found.
     PRO_TK_BAD_INPUTS    -  Bad input arguments. Top assemblies in
                             own_comp and in ref_comp are not the same. 
     PRO_TK_NOT_VALID     -  Required license not found.
     PRO_TK_GENERAL_ERROR -  The check failed.
*/


PRO_END_C_DECLS

#endif /* PROSCOPE_H */
