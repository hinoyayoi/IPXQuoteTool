#ifndef PROMFG_H
#define PROMFG_H

/* ProMfg.h:  defines actions specific to manufacturing models */


#include <ProObjects.h>





PRO_BEGIN_C_DECLS

typedef struct mfg*  ProMfg;

typedef enum pro_mfg_types
{
 PRO_MFGTYPE_NONE         = -1,
 PRO_MFGTYPE_MACH_PART    = PRO_PART,           /* part machining mfg,
                                                   no longer supported       */
 PRO_MFGTYPE_MACH_ASSEM   = PRO_ASSEMBLY,       /* assembly machining mfg    */
 PRO_MFGTYPE_SHEET_METAL  = 81,                 /* sheetmetal mfg            */
 PRO_MFGTYPE_MOLD         = -10,                /* mold mfg                  */
 PRO_MFGTYPE_CAST         = -20,                /* cast mfg                  */
 PRO_MFGTYPE_CMM          = 420                 /* CMM mfg                   */
}       ProMfgType;

extern ProError ProMfgCreate (ProName           name,
                              ProMfgType        sub_type,
                              ProName           model_name,
                       ProMfg          *p_mfg);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMfgMdlCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMfgMdlCreate instead.

            Creates a manufacturing object.

   Input Arguments:
      name            - The name of the manufacturing object.
      sub_type        - The manufacturing subtype defined by the enum 
                        <i>ProMfgType</i>.
      model_name      - The name of the reference model prompted for 
                        during creation
                        of the manufacturing object.
                        For part machining, this should be the design part.
                        For sheet metal manufacturing, this should be the 
                        sheet metal workpiece. For all other types, this 
                        argument is ignored. 
 
   Output Arguments:
      p_mfg           - The newly created manufacturing object.

   Return Values:
      PRO_TK_NO_ERROR - The function successfully created the manufacturing 
                        object. 
      PRO_TK_E_FOUND  - A manufacturing object with the specified name 
                        already exists.
      PRO_TK_UNSUPPORTED - The function did not create the manufacturing
                        object with subtype PRO_MFGTYPE_MACH_PART. 
      Other           - One or more of the input arguments are invalid, so 
                        the function did not create the manufacturing object.
*/

extern ProError ProMfgMdlCreate (ProName            name,
                                 ProMfgType         sub_type,
                                 ProMdl             model,
                                 ProMfg            *p_mfg);
/*
   Purpose: Creates a manufacturing object.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      name            - The name of the manufacturing object.
      sub_type        - The manufacturing subtype defined by the enum 
                        <i>ProMfgType</i>.
      model           - The reference model prompted for 
                        during creation
                        of the manufacturing object.
                        For part machining, this should be the design part.
                        For sheet metal manufacturing, this should be the 
                        sheet metal workpiece. For all other types, this 
                        argument is ignored. 
 
   Output Arguments:
      p_mfg           - The newly created manufacturing object.

   Return Values:
      PRO_TK_NO_ERROR - The function successfully created the manufacturing 
                        object. 
      PRO_TK_E_FOUND  - A manufacturing object with the specified name 
                        already exists.
      PRO_TK_UNSUPPORTED - The function did not create the manufacturing
                        object with subtype PRO_MFGTYPE_MACH_PART. 
      Other           - One or more of the input arguments are invalid, so 
                        the function did not create the manufacturing object.
*/


extern ProError ProMfgTypeGet (ProMfg       mfg,
                               ProMfgType  *r_sub_type);
/*
   Purpose: Returns the type of the specified manufacturing object.

   Input Arguments:
      mfg             - The manufacturing object

   Output Arguments:
      r_sub_type      - The type of the manufacturing object

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the information.
      Other           - The input argument is invalid.
*/


typedef struct  Pro_Tool  
{                           /* absolute reference to mfg tool */
  ProLine  tool_id;
  ProMfg   owner_mfg;
}  ProTool;


/* "forward" typedefs for various manufacturing types defined elsewhere */

typedef                struct pro_model_item  ProFixture;
typedef                struct pro_model_item  *ProFixturePtr;
typedef PRO_CONST_ARG  struct pro_model_item  *ProConstFixturePtr;

typedef                struct Pro_Elem  *ProPecktable;
typedef PRO_CONST_ARG  struct Pro_Elem  *ProConstPecktable;


/* typedefs specific to the ProMfg object */


typedef ProError  (*ProMfgToolAction) ( PRO_CONST_ARG ProTool* tool,
                                        ProAppData app_data );
/*
   Purpose:  The generic user function for a tool.

   Input Arguments:
      tool     - The handle to the tool
      app_data - The application data passed to <b>ProMfgToolVisit()</b>

   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR - Visit the next tool, if present.
      Other values    - Stop visiting at the next tool.
*/

/*===========================================================================*/

extern ProError  ProMfgAssemGet  (   PRO_CONST_ARG ProMfg    mfg,
                                     ProAssembly    *r_assem_obj);
/*
   Purpose:  Retrieves the top-level assembly of the specified manufacturing 
             model.

   Input Arguments:
      mfg            - The handle to the manufacturing model

   Output Arguments:
      r_assem_obj    - The handle to the top-level assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The top-level assembly of the manufacturing
                           model was not found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError  ProMfgSolidGet  ( PRO_CONST_ARG ProMfg      mfg,
                                   ProSolid   *r_solid_obj);
/*
   Purpose:  Retrieves the solid in which a manufacturing model's features are
             placed.

   Input Arguments:
      mfg            - The handle to the manufacturing model

   Output Arguments:
      r_solid_obj    - The handle to the solid in which the
                       manufacturing features are stored

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The storage solid of the manufacturing model
                           was not found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError  ProMfgFeatureOwnerGet  ( PRO_CONST_ARG ProMfg           mfg,
                                          ProAsmcomppath  *p_mfg_feat_owner_path);
/*
   Purpose:  Retrieves the component path from the top level to the storage 
             solid of the specified manufacturing model. You retrieve
             the storage solid using the <b>ProMfgSolidGet()</b> function.

   Input Arguments:
      mfg                    - The handle to the manufacturing model

   Output Arguments:
      p_mfg_feat_owner_path  - The component path information

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The storage solid of the manufacturing model
                           was not found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProMfgSolidGet()
*/


extern ProError  ProMfgToolVisit  (PRO_CONST_ARG ProMfg            mfg,
                                   ProMfgToolAction  action_fnc,
                                   void             *app_data);
/*
   Purpose:  Visits all the tools in the specified manufacturing model.
<p>
   NOTE:
<p>
        The <i>action_fnc</i> callback should not attempt to add or remove tools
        from the manufacturing model. You should add or remove tools after
        this function has completed execution.
 

   Input Arguments:
      mfg            - The handle to the manufacturing model.
      action_fnc     - The callback function called for every tool
                       visited. If the function returns anything other than
                       PRO_TK_NO_ERROR, visiting stops immediately after
                       the current tool.
      app_data       - The user-specified data used by the action function. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - Visiting completed successfully, or there were no 
                           tools in the manufacturing model.
      PRO_TK_BAD_INPUTS  - One of the arguments is invalid.
      Other              - Any other value is the value returned by the
                           action function (visiting stopped).
*/


extern ProError  ProMfgPecktableSet (PRO_CONST_ARG ProMfg              mfg, 
                                     ProConstPecktable   peck_table);
/*
   Purpose:  Sets or replaces the peck table in the specified manufacturing 
             model.
<p>
   NOTE:
<p>
        This function does not free the peck table. To free the table,
        call the function <b>ProPecktableFree()</b>.


   Input Arguments:
      mfg            - The handle to manufacturing model

   Output Arguments:
      peck_table     - The handle to the peck table

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProPecktableFree()
*/


extern ProError  ProMfgFixtActivate  ( PRO_CONST_ARG ProMfg               mfg, 
                                       ProConstFixturePtr   fixture);
/*
   Purpose:  Sets the active feature for the specified manufacturing model.

   Input Arguments:
      mfg            - The handle to the manufacturing model.
      fixture        - The fixture to be activated (all others are then
                       deactivated). Pass NULL to deactivate all the
                       fixtures.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the active feature.
      PRO_TK_E_NOT_FOUND - The specified manufacturing model or solid was
                           not found.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


PRO_END_C_DECLS


#endif  /* PROMFG_H */
