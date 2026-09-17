#ifndef PROTOOL_H_FILE
#define PROTOOL_H_FILE

/* ProTool.h: definitions and action functions for ProTool objects */

#include <ProMfg.h>
#include <ProParamval.h>
#include <ProToolinput.h>
#include <ProItemerr.h>
#include <ProMdl.h>





PRO_BEGIN_C_DECLS



/* Types and defines */


/* Publicly accessible tool attribute constants

     NOTE:  You should not depend on the presence or absence of other, internal
            tool attributes!
*/
typedef enum  ProToolAttributes  {
  PRO_TOOL_BY_REFERENCE = 1             /* ON = by reference, OFF = by copy */
}  ProToolAttribute;


/* Macros for dealing with tool attributes
*/
#define PRO_TOOL_ATTRIBUTE_ADD( attribute_int, one_attr_const )         \
           ( (attribute_int) |= ( 1 << ((one_attr_const)-1) ) )
#define PRO_TOOL_ATTRIBUTE_RMV( attribute_int, one_attr_const )          \
           ( (attribute_int) &= ~( 1 << ((one_attr_const)-1) ) )
#define PRO_TOOL_ATTRIBUTE_HAS( attribute_int, one_attr_const )          \
           ( (attribute_int) & ( 1 << ((one_attr_const)-1) ) )


/* Function prototypes */


extern ProError  ProToolInit  (PRO_CONST_ARG ProLine  tool_id,
                               ProMfg                   owner_mfg,
                               ProTool        *p_tool_ref);
/*
   Purpose:  Initializes a <i>ProTool</i> data structure.

   Input Arguments:
      tool_id        - The identifier of the tool (a string)
      owner_mfg      - The handle to the manufacturing model that owns
                       the tool
      p_tool_ref     - The <i>ProTool</i> structure to be initialized

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully initialized the
                           structure.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProToolTypeGet (PRO_CONST_ARG ProTool* tool_ref,
                                 ProToolType    *r_tool_type);
/*
   Purpose:  Retrieves the type of the specified tool.

   Input Arguments:
      tool_ref       - The handle to the tool

   Output Arguments:
      r_tool_type    - The type of tool

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The tool specified by <i>tool_ref</i> was not found.
*/


extern ProError  ProToolParamGet (PRO_CONST_ARG ProTool* tool_ref,
                                  PRO_CONST_ARG ProCharName    param_name,
                                  ProParamvalue *p_param_val);
/*
   Purpose:  Retrieves the value of one of the tool parameters.

   Input Arguments:
      tool_ref       - The handle to the tool
      param_name     - The name of the tool parameter

   Output Arguments:
      p_param_val    - The value of the specified parameter

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The tool specified by <i>tool_ref</i> was not found.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError  ProToolAttributesGet (
                                  PRO_CONST_ARG ProTool*  tool_ref,
                                  int*      r_attr);
/*
   Purpose:  Retrieves an integer that contains all the attributes of the 
             specified tool.

   Input Arguments:
      tool_ref       - The handle to the tool

   Output Arguments:
      r_attr         - An integer representation of the tool attributes

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the attributes.
      PRO_TK_E_NOT_FOUND - The tool specified by <i>tool_ref</i> was not found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError  ProToolVerify (PRO_CONST_ARG ProTool* tool_ref);
/*
   Purpose:  Verifies the existence of the specified tool.

   Input Arguments:
      tool_ref       - The handle to the tool

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The tool handle refers to an existing tool.
      PRO_TK_E_NOT_FOUND - The tool specified by <i>tool_ref</i> was not found.
      PRO_TK_BAD_INPUTS  - The argument is invalid.
*/


extern ProError  ProToolCreate (ProTool*           tool_ref,
                                ProConstToolinputPtr tool_input,
                                ProErrorlist        *p_errors);
/*
   Purpose:  Creates a new tool.
<p>
   NOTE:
<p>
        If <i>tool_ref -> tool_id</i> already exists, this function tries to
        adjust it until it is unique.

   Input Arguments:
      tool_ref       - The handle to the tool to be created.
      tool_input     - The tool information (parameters, attributes, type,
                       and so on).

   Output Arguments:
      p_errors       - The error list that explains where problems occurred.
                       This list is valid only until the next call to this
                       function. 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully created the tool.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError  ProToolRedefine (PRO_CONST_ARG ProTool* tool_ref,
                                  ProConstToolinputPtr tool_input,
                                  ProErrorlist        *p_errors);
/*
   Purpose:  Redefines an existing tool.

   Input Arguments:
      tool_ref       - The handle to the tool to be redefined.
      tool_input     - The new tool information.

   Output Arguments:
      p_errors       - The error list that explains where problems occurred.
                       This list is valid only until the next call to this
                       function. 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully redefined the tool.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

extern ProError ProToolModelGet (PRO_CONST_ARG ProTool      *p_tool_handle,
                                               ProFamilyName r_model_name,
                                               ProMdlType   *r_model_type);
/*
	DEPRECATED: Since Creo 3
    SUCCESSORS: ProToolModelMdlnameGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProToolModelMdlnameGet instead.
             This function does not support Multi-CAD models as solid tool models
             in the tool manager. This will be supported in a future release.

              Returns the model associated to the tool, if the tool references
              a model.

    Input Arguments:
       p_tool_handle     - The tool

    Output Arguments:
       r_model_name      - The name of the model associated to the tool
       r_model_type      - The model type

    Return Values:
       PRO_TK_NO_ERROR      - The function successfully returned the tool model.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_LINE_TOO_LONG - The name of model associated to the tool is
                              longer than PRO_FAMILY_NAME_SIZE
*/

extern ProError ProToolModelMdlnameGet (const ProTool *p_tool_handle,
                                              ProFamilyMdlName r_model_name,
                                              ProMdlfileType   *r_model_type);
/*
    Purpose:  Returns the model associated to the tool, if the tool references
              a model.

<b>Note:</b> This function does not support Multi-CAD models as solid tool models
             in the tool manager. This will be supported in a future release.

    Input Arguments:
       p_tool_handle     - The tool

    Output Arguments:
       r_model_name      - The name of the model associated to the tool.
                           Free this argument using ProWstringFree.
       r_model_type      - The model type

    Return Values:
       PRO_TK_NO_ERROR   - The function successfully returned the tool model.
       PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
       PRO_TK_E_NOT_FOUND - The tool specified by <i>p_tool_handle</i> was not found.
*/

extern ProError  ProToolFileRead (ProTool	*tool_handle,
                                  ProPath	input_file);
/*
   Purpose:  Creates a new tool or redefines an existing tool.

   Input Arguments:
      tool_handle    - The handle to the tool to be created or redefined.
      input_file     - The full path and name of the input file.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded.
      PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
      PRO_TK_INVALID_FILE - The input file does not have the correct format,
                            or data.

*/

extern ProError  ProToolFileWrite (ProTool	*tool_handle,
                                   ProPath	output_file);
/*
   Purpose:  Writes tool information into a file.

   Input Arguments:
      tool_handle - The handle to the tool to be saved in a file.
      output_file - The full path and name of the output file.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_CANT_WRITE - Could not write the output file to the designated
                          file name or path.

*/

PRO_END_C_DECLS

#endif  /* PROTOOL_H_FILE */

