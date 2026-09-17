#ifndef PRODTLSYMDEF_H 
#define PRODTLSYMDEF_H
			

#include <ProDtlitem.h>
#include <ProDtlattach.h>
#include <ProCurvedata.h>
#include <ProObjects.h>
#include <ProWstring.h>

typedef struct prodtl_sym_def_attach *ProDtlsymdefattach;
typedef struct pro_symdefdata *ProDtlsymdefdata; 
typedef struct pro_symgroupdata *ProDtlsymgroupdata; 

typedef struct pro_entitydata *ProDtlentitydata;

typedef enum
{
    PROSYMDEFATTACHTYPE_FREE,
    PROSYMDEFATTACHTYPE_LEFT_LEADER,
    PROSYMDEFATTACHTYPE_RIGHT_LEADER,
    PROSYMDEFATTACHTYPE_RADIAL_LEADER,
    PROSYMDEFATTACHTYPE_ON_ITEM,
    PROSYMDEFATTACHTYPE_NORM_ITEM
} ProDtlsymdefattachType;

typedef enum
{
    PRODTLSYMDEFHGHTTYPE_FIXED,
    PRODTLSYMDEFHGHTTYPE_VARIABLE,
    PRODTLSYMDEFHGHTTYPE_TEXTRELATED,
    PRODTLSYMDEFHGTTTYPE_MODELUNITS
} ProDtlsymdefdataHeighttype;

PRO_BEGIN_C_DECLS
/*================================================================*\
    ProDtlsymdef  functions
\*=================================================================*/
extern ProError ProDtlsymdefCreate(
    ProMdl          model,
    ProDtlsymdefdata data,
    ProDtlsymdef *symdef);
/*

Purpose: Create a symbol definition in the specified model.  

Input Arguments:
    model     - The model handle.
    data      - The symbol definition data.

Output Arguments:
    symdef    - Created symbol definition.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully created the symbol 
                            definition.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't create the symbol definition.
    
*/ 

extern ProError ProDtlsymdefDataGet(
    ProDtlsymdef *symdef,
    ProDtlsymdefdata *data);
/*

Purpose: Get a symbol definition data.  

Input Arguments:
    symdef    - The symbol definition.

Output Arguments:
    data      - The symbol definition data.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the symbol 
                            definition data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't get the symbol definition data.
    
*/ 

extern ProError ProDtlsymdefDelete(
    ProDtlsymdef *symdef);
/*

Purpose: Delete a symbol definition.  

Input Arguments:
    symdef    - The symbol definition.

Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR      - The function successfully deleted the symbol 
                            definition data.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't delete the symbol definition data.
    
*/ 

extern ProError ProDtlsymdefModify(
    ProDtlsymdef *symdef,
    ProDtlsymdefdata data);
/*

Purpose: Modify a symbol definition.  

Input Arguments:
    symdef    - The symbol definition.
    data      - The symbol definition data.

Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR      - The function successfully modify the symbol 
                            definition. 
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't modify the symbol definition data.
    
*/ 

extern ProError ProDrawingDtlsymdefsCollect(
    ProDrawing drawing,
    ProDtlsymdef **symdefs);
/*

Purpose: Collect symbol definitions in the specified drawing.  

Input Arguments:
    drawing   - The drawing handle.

Output Arguments:
    symdefs   - The pointer to the array of symbol definitions.
                The function allocates ProArray. User must release the 
                memory by ProArrayFree.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the symbol 
                            definitions. 
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No symbol definitions were found.
    PRO_TK_OUT_OF_MEMORY - The function found too many items to be contained in the output ProArray.  Use ProDrawingDtlsymdefVisit instead.
    
*/ 

extern ProError ProDrawingDtlsymdefVisit(
    ProMdl model,
    ProDtlitemVisitAction visit_action,
    ProDtlitemFilterAction filter_action,
    ProAppData appdata);
/*

Purpose: Visit symbol definitions in the specified model.  

Input Arguments:
    model         - The model handle.
    visit_action  - Symbol definition visit action function.
    filter_action - Symbol definition filter action function.
                    If NULL, all symbol definitions are visited
                    using the action function.
    appdata       - The application data.
    
Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR      - The function successfully visited the symbol 
                            definitions. 
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No symbol definitions were found.
    Other                - Return value passed by the caller's visit function.
    
*/ 

extern ProError ProDrawingSystemDtlsymdefRetrieve(
    ProMdl  model,
    ProPath filepath,
    ProName filename,
    int version,
    ProBoolean update,
    ProDtlsymdef *symdef);
/*

Purpose: Retrieve a symbol definition from the system symbol directory
	to the specified drawing.  

Input Arguments:
    model   - The drawing handle.
    filepath  - The path to the file with a symbol definition. This path is
                a relative path to the user symbol directory which is defined
                as either the value of the configuration option 'pro_symbol_dir'
                or the Creo Parametric working directory if 'pro_symbol_dir'
                is not set. 
    filename  - The name of the symbol definition file.
    version   - The version of the symbol definition file. Use PRO_VALUE_UNUSED
                to retrieve the latest version of the symbol definition file.
    update    - Update flag. PRO_B_TRUE- Update the existing symbol definition
                unconditionally. PRO_B_FALSE- Do not load new definition if the
                same symbol exist in the drawing.
    
Output Arguments:
    symdef    - Retrieved symbol definition.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the symbol 
                            definition. 
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't retrieve the symbol definition.
    PRO_TK_E_NOT_FOUND   - The specified symbol does not exist.
    PRO_TK_E_FOUND       - The specified symbol exist but was not retrieved.
    
*/ 

extern ProError ProDrawingDtlsymdefRetrieve(
    ProMdl  model,
    ProPath filepath,
    ProName filename,
    int version,
    ProBoolean update,
    ProDtlsymdef *symdef);
/*

Purpose: Retrieve a symbol definition from a location relative to the directory
	 set for the configuration option: "pro_symbol_dir". If this 
         configuration option is not set, then the relative path is with
	 respect to the working directory.

Input Arguments:
    model   - The drawing handle.
    filepath  - The path to the file with a symbol definition.
                If this is NULL, then the symbol definition is located 
                in the designated directory.
    filename  - The name of the symbol definition file.
    version   - The version of the symbol definition file. Use PRO_VALUE_UNUSED
                to retrieve the latest version of the symbol definition file.
    update    - Update flag. PRO_B_TRUE- Update the existing symbol definition
                unconditionally. BRO_B_FALSE- Do not load new definition if the
                same symbol exist in the drawing.
    
Output Arguments:
    symdef    - Retrieved symbol definition.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the symbol 
                            definition. 
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't retrieve the symbol definition.
    PRO_TK_E_NOT_FOUND   - The specified symbol does not exist.
    PRO_TK_E_FOUND       - The specified symbol exist but was not retrieved.
    
*/ 

/*================================================================*\
    ProDtlsymdefattach functions
\*=================================================================*/
extern ProError ProDtlsymdefattachAlloc(
    ProDtlsymdefattachType type,
    int entity_id,
    double entity_parameter,
    ProVector location,
    ProDtlsymdefattach *attach);
/*

Purpose: Allocate and initialize the memory for symbol definition attachment. 
        User must release the memory by ProDtlsymdefattachFree

Input Arguments:
    type             - The attachment type.
    entity_id        - The index in the symbol definition entity array at
                       which you are attached. Can be -1 if type is "free".
    entity_parameter - The location along the entity at which the attachment
                       occurs. (Ignored for free attachment and radial leaders).
    location         - Attachment location.
    
Output Arguments:
    attach           - The symbol definition attachment.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_INVALID_TYPE  - Bad type.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsymdefattachGet(
    ProDtlsymdefattach attach,
    ProDtlsymdefattachType *type,
    int *entity_id,
    double *entity_parameter,
    ProVector location);
/*

Purpose: Get a symbol definition attachment data.  

Input Arguments:
    attach    - The symbol definition attachment.
    
    
Output Arguments:
    type              - The attachment type.
    entity_id         - The index in the symbol definition entity array at which
                        you are attached. Can be -1 if type is "free".
    entity_parameter  - location along the entity at which the attachment
                        occurs.(Ignored for free attachment and radial leaders).
    location          - The attachment location.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefattachFree(
    ProDtlsymdefattach attach);
/*

Purpose: Release the memory that was allocated by ProDtlsymdefattachAlloc.  

Input Arguments:
    attach    - The symbol definition attachment.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully released memory.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    
*/ 

/*================================================================*\
    ProDtlsymdefdata functions
\*=================================================================*/
extern ProError ProDtlsymdefdataAlloc(
    ProMdl           model,
    ProDtlsymdefdata *symdefdata);
/*

Purpose: Allocate and initialize memory for symbol definition data. User
        must release memory by ProDtlsymdefdataFree

Input Arguments:
    model       - The model handle.
    
Output Arguments:
    symdefdata    - The symbol definition data.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS    - Bad argument.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsymdefdataFree(
    ProDtlsymdefdata symdefdata);
/*

Purpose: Release the memory allocated by ProDtlsymdefdataAlloc. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully released memory.
    PRO_TK_BAD_INPUTS    - Bad argument.
    
*/ 

extern ProError ProDtlsymdefdataIdGet(
    ProDtlsymdefdata symdefdata,
    int *id);
/*

Purpose: Get a symbol definition id. 

Input Arguments:
    symdefdata           - The symbol definition data.
    
Output Arguments:
    id                   - The symbol definition id.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved id.
    PRO_TK_BAD_INPUTS    - Bad one or more arguments.
    
*/ 

extern ProError ProDtlsymdefdataHeighttypeGet(
    ProDtlsymdefdata symdefdata,
    ProDtlsymdefdataHeighttype *type);
/*

Purpose: Get a symbol definition height type. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    type          - The symbol definition height type.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the type.
    PRO_TK_BAD_INPUTS    - Bad one or more arguments.
    PRO_TK_GENERAL_ERROR - Can't retrieved the type.
    
*/ 

extern ProError ProDtlsymdefdataHeighttypeSet(
    ProDtlsymdefdata symdefdata,
    ProDtlsymdefdataHeighttype type);
/*

Purpose: Set a symbol definition height type. 

Input Arguments:
    symdefdata    - The symbol definition data.
    type          - The symbol definition height type.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the type.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_INVALID_TYPE  - Invalid symbol definition height type.
    
*/ 

extern ProError ProDtlsymdefdataElbowGet(
    ProDtlsymdefdata symdefdata,
    ProBoolean *elbow);
/*

Purpose: Get a symbol definition elbow. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    elbow         - The elbow flag.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved elbow flag.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataElbowSet(
    ProDtlsymdefdata symdefdata,
    ProBoolean elbow);
/*

Purpose: Set a symbol definition elbow. 

Input Arguments:
    symdefdata    - The symbol definition data.
    elbow         - The elbow flag.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set an elbow flag.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataTextangfixedGet(
    ProDtlsymdefdata symdefdata,
    ProBoolean *text_angle_fixed);
/*

Purpose: Get a symbol definition text angle flag. 

Input Arguments:
    symdefdata           - The symbol definition data.
    
Output Arguments:
    text_angle_fixed     - The text angle flag.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the flag.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataTextangfixedSet(
    ProDtlsymdefdata symdefdata,
    ProBoolean text_angle_fixed);
/*

Purpose: Set a symbol definition text angle flag. 

Input Arguments:
    symdefdata       - The symbol definition data.
    text_angle_fixed - The text angle flag.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the flag.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataAttachAdd(
    ProDtlsymdefdata symdefdata,
    ProDtlsymdefattach attach);
/*

Purpose: Add an attachment to the symbol definition. 

Input Arguments:
    symdefdata    - The symbol definition data.
    attach        - The attachment.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully added the attachment.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_OUT_OF_MEMORY - Number of attachments more than 
                            PRODTL_SYM_DEF_MAX_ATTACHES
    
*/ 

extern ProError ProDtlsymdefdataAttachSet(
    ProDtlsymdefdata symdefdata,
    ProDtlsymdefattach *attaches); 
/*

Purpose: Set attachments to the symbol definition. 

Input Arguments:
    symdefdata    - The symbol definition data.
    attaches      - The ProArray of symbol definition attachments.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the attachments.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_OUT_OF_MEMORY - Number of attachments more than 
                            PRODTL_SYM_DEF_MAX_ATTACHES
    
*/ 

extern ProError ProDtlsymdefdataAttachGet(
    ProDtlsymdefdata symdefdata,
    ProDtlsymdefattach **attaches); 
/*

Purpose: Get attachments of the symbol definition. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    attaches      - The pointer to the ProArray of symbol definition
                    attachments. Function allocates memory for array.
                    User must release memory by ProArrayFree.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the attachments.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_E_NOT_FOUND   - No attachments were found.
    
*/ 

extern ProError ProDtlsymdefdataHeightGet(
    ProDtlsymdefdata symdefdata,
    double *height);
/*
DEPRECATED: Since Wildfire 5.0
SUCCESSORS: ProDtlsymdefdataScaledheightGet
Purpose: Get a symbol definition height. 
         <P><B>Note:</B> This function is superseded by
         ProDtlsymdefdataScaledheightGet(). This function does not
         consistently return a value capable of being related
         mathematically to the symbol definition height in inches.

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    height        - The symbol definition height.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the height.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataScaledheightGet(
    ProDtlsymdefdata symdefdata,
    double *height);
/*
Purpose: Get the symbol definition height in inches. (Inches are
always used for the units in the symbol definition).
 
Input Arguments:
    symdefdata - The symbol definition data.
 
Output Arguments:
    height - The height in inches.
 
Return Values:
    PRO_TK_NO_ERROR - The function successfully retrieved the height.
    PRO_TK_BAD_INPUTS - One or more arguments were invalid.
 
*/

extern ProError ProDtlsymdefdataPathSet(
    ProDtlsymdefdata symdefdata,
    ProPath path);
/*

Purpose: Set a symbol definition path. 

Input Arguments:
    symdefdata    - The symbol definition data.
    path          - The path to symbol definition.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the path.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataNameGet(
    ProDtlsymdefdata	symdefdata,
    ProName             name);
/*

Purpose: Get a symbol definition name. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    name          - The name of the symbol definition.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the name.
    PRO_TK_BAD_INPUTS    - One or more input arguments is invalid.
    PRO_TK_E_NOT_FOUND   - Symbol not found in session.
    
*/ 


extern ProError ProDtlsymdefdataPathGet(
    ProDtlsymdefdata symdefdata,
    ProPath path);
/*

Purpose: Get a symbol definition path. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    path          - The path to the symbol definition, for example:
                    "/home/user/symbols/my_symbol_3.sym"
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved path.
    PRO_TK_BAD_INPUTS    - One or more input arguments is invalid.
    PRO_TK_E_NOT_FOUND   - Symbol not found in session.
    PRO_TK_GENERAL_ERROR - Problem parsing path.
    
*/ 

extern ProError ProDtlsymdefdataTextrefSet(
    ProDtlsymdefdata symdefdata,
    int text_entity,
    int text_line,
    int text_text);
/*

Purpose: Set a symbol definition reference text data. 

Input Arguments:
    symdefdata    - The symbol definition data.
    text_entity   - The symbol entity identifier of the reference text.
    text_line     - The line in the note of the referenced text.
    text_text     - The index of the line array of referenced text.
    
Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the referenced text 
                            data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymdefdataTextrefGet(
    ProDtlsymdefdata symdefdata,
    int *text_entity,
    int *text_line,
    int *text_text);
/*

Purpose: Get a symbol reference text data. 

Input Arguments:
    symdefdata    - The symbol definition data.
    
Output Arguments:
    text_entity   - The symbol entity identifier of the reference text.
    text_line     - The line in the note of the referenced text.
    text_text     - The index of the line array of referenced text.
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully get reference text data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlsymgroupSubgroupsCollect (ProDtlsymgroup* parent_group,
                                                ProDtlsymgroup** group_array);
/*
Purpose:  Gets the names of subgroups stored in the symbol definition at the
          indicated level.
        
Input Arguments:
    parent_group - The parent symbol definition group from which to collect
                   the subgroups. If the sym_group_id field is set to -1
                   the top level of groups in the symbol definition will
                   be collected.

Output Arguments:
    group_array - ProArray of subgroups.  Free this output using
                  ProArrayFree ().

Return Values:
    PRO_TK_NO_ERROR - The function successfully set the information.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_E_NOT_FOUND - No groups are stored in the symbol definition at
                         this level.

*/ 

extern ProError ProDtlsymgroupLevelIsExclusive (ProDtlsymgroup* parent_group,
                                                ProBoolean* is_exclusive);
/*
Purpose:  Determines if the subgroups stored in the symbol definition on the
          indicated level are exclusive.
        
Input Arguments:
    parent_group - The parent symbol definition group from which to collect
                   the subgroups. If the sym_group_id field is set to -1
                   the attribute will be obtained for the top level of
                   groups in the symbol definition.

Output Arguments:
    is_exclusive - PRO_B_TRUE if the level is Exclusive,
                   PRO_B_FALSE if the level is Independent.

Return Values:
    PRO_TK_NO_ERROR - The function successfully set the information.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDtlsymgroupParentGet ( ProDtlsymgroup *group,
                                          ProDtlsymgroup *parent_group);
/*
Purpose: Gets the parent group of the level to which the given group belongs. 
        
Input Arguments:
    group            - The symbol group.
 
Output Arguments:
    parent_group     - The parent group at the next higher level in the symbol
                       definition.

Return Values:
    PRO_TK_NO_ERROR    - The function successfully retrieved the information.
    PRO_TK_E_NOT_FOUND - The group is a top level group and does not have a
                         parent.
    PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
*/

extern ProError ProDtlsymgroupDataGet (ProDtlsymgroup* group_level,
                                       ProDtlsymgroupdata* data);
/*
Purpose:  Gets the group data for a group stored in the symbol definition.
        
Input Arguments:
    group_level        - The group in the symbol definition.

Output Arguments:
    data               - The group data.

Return Values:
    PRO_TK_NO_ERROR    - The function successfully set the information.
    PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.

*/

extern ProError ProDtlsymgroupSubgroupCreate (ProDtlsymgroup* parent_group,
                                            ProDtlsymgroupdata new_group_data,
                                              ProDtlsymgroup* new_group);
/*
Purpose:  Creates a variant group in a symbol definition.

Input Arguments:
    parent_group   - The parent symbol definition group from which to collect
                     the subgroups. If the sym_group_id field is set to -1 the
                     new group will be in the top level of groups in the
symbol definition.
    new_group_data - The group data (should include ProDtlitems belonging to
                     the symbol definition).
        
Output Arguments:
    new_group      - The new group created in the definition.

Return Values:
    PRO_TK_NO_ERROR     - The function succeeded.
    PRO_TK_BAD_INPUTS   - One or more input arguments is invalid.
    PRO_TK_INVALID_NAME - A group with the provided name already exists at
                          this level.
*/

extern ProError ProDtlsymgroupModify (ProDtlsymgroup* group,
                                      ProDtlsymgroupdata group_data);
/*
Purpose:  Modifies a variant group in a symbol definition.

Input Arguments:
    group      - The group in the symbol definition.
    group_data - The group data (should include ProDtlitems belonging to the
                 symbol definition).
        
Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

extern ProError ProDtlsymgroupDelete (ProDtlsymgroup* group);
/*
Purpose:  Deletes a group in a symbol definition.

Input Arguments:
    group - The group in the symbol definition.
                
Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

extern ProError ProDtlsymgroupLevelExclusiveSet (ProDtlsymgroup* group_level,
                                                 ProBoolean is_exclusive);
/*
Purpose:  Causes a group level in the symbol definition to be exclusive or
          independent.

Input Arguments:
    group_level  - The parent symbol definition group where the attribute will
                   be set. If the sym_group_id field is set to -1 the function
                   will set the attribute for the top level of variant groups
                   in the symbol definition.
    is_exclusive - PRO_B_TRUE to make the level exclusive,
                   PRO_B_FALSE to make it Independent.
        
Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
    PRO_TK_NO_CHANGE  - The status was already set to the designated value.
*/

extern ProError ProDtlsymgroupdataAlloc ( ProMdl       model,
                                          ProName group_name,
                                          ProDtlsymgroupdata *symgroupdata);
/*
Purpose:  Allocates a new symbol group data object.

Input Arguments:
    model             - The model handle.
    group_name        - The group name.
        
Output Arguments:
    symgroupdata      - The symbol group data.           

Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

extern ProError ProDtlsymgroupdataFree ( ProDtlsymgroupdata symgroupdata);
/*
Purpose:  Frees the memory used by the symbol group data handle.
        
Input Arguments:
    symgroupdata - The group data.

Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR   - The function successfully freed the memory.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDtlsymgroupdataNameGet ( ProDtlsymgroupdata symgroupdata,
                                            ProName group_name);
/*
Purpose:  Gets the group name from the symbol group data.
        
Input Arguments:
    symgroupdata - The group data.

Output Arguments:
    group_name - The group name.

Return Values:
    PRO_TK_NO_ERROR   - The function successfully retrieved the information.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDtlsymgroupdataNameSet ( ProDtlsymgroupdata symgroupdata,
                                            ProName group_name);
/*
Purpose:  Sets the symbolic group data name.

Input Arguments:
    symgroupdata - The symbol group data.
    group_name   - The group name.
        
Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

extern ProError ProDtlsymgroupdataItemsCollect ( ProDtlsymgroupdata data,
                                                 ProDtlitem** item_array);
/*
Purpose:  Gets the group members from the symbol group data.
        
Input Arguments:
    data - The group data.

Output Arguments:
    item_array - ProArray of detail items (entities and notes) contained in
                 the symbol definition. Free this output using ProArrayFree().
                 Note this does not find subgroups owned by the parent group
                 - use ProDtlsymgroupSubgroupsCollect to find these.

Return Values:
    PRO_TK_NO_ERROR   - The function successfully retrieved the information.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDtlsymgroupdataItemAdd ( ProDtlsymgroupdata data,
                                            ProDtlitem* item);
/*
Purpose:  Adds an item to the symbolic group data.

Input Arguments:
    data - The symbol group data.
    item - The item (detail entity or note). This item must belong to the
           symbol definition.
        
Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

extern ProError ProDtlsymgroupdataItemsSet ( ProDtlsymgroupdata data,
                                             ProDtlitem* item_array);
/*
Purpose:  Sets the symbolic group data to contain the specified detail items.

Input Arguments:
    data       - The symbol group data.
    item_array - ProArray of items (detail entities and/or notes). All items
                 must belong to the symbol definition.
        
Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

extern ProError ProSolidDtlsymdefVisit( ProSolid solid,
                                        ProDtlitemVisitAction visit_action,
                                        ProDtlitemFilterAction filter_action,
                                        ProAppData appdata);
/* 
Purpose: Visit symbol definitions in the specified solid model.

Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          solid         - The solid model handle.
          visit_action  - Symbol definition visit action function.
          filter_action - Symbol definition filter action function.
                          If NULL, all symbol definitions are visited
                          using the action function.
          appdata - The application data.

   Output Arguments:
          None

   Return Values:
          PRO_TK_NO_ERROR      - The function successfully visited the symbol
                  definitions.
          PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
          PRO_TK_GENERAL_ERROR - The function failed.
          PRO_TK_E_NOT_FOUND   - No symbol definitions were found.
          Other                - Return value passed by the caller's visit function.
*/


typedef enum
{
  PRO_DTLSYMDEF_SRC_SYSTEM, /* system symbol directory ([Creo Parametric load point]/
                               symbols/library_syms) */
  PRO_DTLSYMDEF_SRC_SURF_FINISH_DIR, /* system symbol directory ([Creo Parametric load point]/symbols/surffins) */
  PRO_DTLSYMDEF_SRC_SYMBOL_DIR, /* 'pro_symbol_dir' */
  PRO_DTLSYMDEF_SRC_PATH /* absolute path */
} ProDtlsymdefSource;

extern ProError ProSolidDtlsymdefRetrieve( ProSolid solid,
                                           ProDtlsymdefSource location,
                                           ProPath filepath,
                                           ProName filename,
                                           int version,
                                           ProBoolean update,
                                           ProDtlsymdef *symdef);
/*
   Purpose: Retrieve a symbol definition.

   Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          solid  - The solid model handle.
          location - The location to search for the symbol definition file.
          filepath - The path to the file with a symbol definition.
                     If this is NULL, then the symbol definition is located
                     in the designated directory.
          filename - The name of the symbol definition file.
          version  - The version of the symbol definition file. Pass PRO_VALUE_UNUSED to get the latest version.
          update   - Update flag. PRO_B_TRUE- Update the existing symbol definition
                     unconditionally. BRO_B_FALSE- Do not load new definition if the
                     same symbol exist in the drawing.

   Output Arguments:
          symdef - Retrieved symbol definition.

   Return Values:
          PRO_TK_NO_ERROR      - The function successfully retrieved the symbol
                  definition.
          PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
          PRO_TK_GENERAL_ERROR - Can't retrieve the symbol definition.
          PRO_TK_E_NOT_FOUND   - The specified symbol does not exist.
          PRO_TK_E_FOUND       - The specified symbol exist but was not retrieved.
*/

typedef ProError (*ProDtlsymdefItemVisitAction) (ProDtlsymdef* symdef, ProDtlitem* item, 
                                                 ProError filter_status, ProAppData appdata);
/* 
   Purpose: Visit action for entities and notes in a symbol definition. 

   Input Arguments:
          symdef - The symbol definition.
          item - The item.
          filter_status - Error status passed to the filter action.
          appdata - Application data passed to the visit function. 

   Output Arguments:
          None 

   Return Values:
          PRO_TK_NO_ERROR - Continue visiting.
          Other - Stop visiting and pass this error status to the visit function call. 
*/ 

typedef ProError (*ProDtlsymdefItemFilterAction) (ProDtlsymdef* symdef, ProDtlitem* item, 
                                                                          ProAppData appdata);
/* 
   Purpose: Filter action for entities and notes in a symbol definition. 

   Input Arguments:
          symdef - The symbol definition.
          item - The item.
          appdata - Application data passed to the visit function. 

   Output Arguments:
          None 

   Return Values:
          PRO_TK_CONTINUE - Skip this item and continue visiting.
          Other - Visit the item and pass this status to the visit action.
*/ 
           

extern ProError ProSolidDtlsymdefEntityVisit(ProDtlsymdef* def,
          ProDtlsymdefItemVisitAction visit_action,
          ProDtlsymdefItemFilterAction filter_action,
          ProAppData appdata);
/* 
   Purpose: Visit entities in the specified symbol definition.

   Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          def - The symbol definition.
          visit_action - Entity visit action function.
          filter_action - Entity filter action function.
          If NULL, all symbol definitions are visited
          using the action function.
          appdata - The application data. 

   Output Arguments:
          None 

   Return Values:
          PRO_TK_NO_ERROR - The function successfully visited the entities.
          PRO_TK_BAD_INPUTS - One or more arguments was invalid.
          PRO_TK_GENERAL_ERROR - The function failed.
          PRO_TK_E_NOT_FOUND - No entities were found.
          Other - Return value passed by the caller's visit function. 
*/ 

extern ProError ProSolidDtlsymdefNoteVisit(
          ProDtlsymdef* def,
          ProDtlsymdefItemVisitAction visit_action,
          ProDtlsymdefItemFilterAction filter_action,
          ProAppData appdata);
	  	  
/* 
Purpose: Visit notes in the specified symbol definition. 

Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          def - The symbol definition.
          visit_action - Note visit action function.
          filter_action - Note filter action function.
          If NULL, all symbol definitions are visited
          using the action function.
          appdata - The application data. 

   Output Arguments:
          None 

   Return Values:
          PRO_TK_NO_ERROR - The function successfully visited the notes.
          PRO_TK_BAD_INPUTS - One or more arguments was invalid.
          PRO_TK_GENERAL_ERROR - The function failed.
          PRO_TK_E_NOT_FOUND - No notes were found.
          Other - Return value passed by the caller's visit function. 
*/ 

extern ProError ProDtlsymdefToModelCopy(
     ProDtlsymdef *sourceDef, 
     ProSolid      target, 
     ProDtlsymdef *targetDef);

/* 
Purpose: Copies symbol definition from one model to the other

Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          sourceDef - The source symbol definition.
          target - The target model. 

   Output Arguments:
          targetDef - The target model symbol definition. 

   Return Values:
          PRO_TK_NO_ERROR - Copies symbol definition successfully.
          PRO_TK_BAD_INPUTS - One or more arguments was invalid.
          PRO_TK_GENERAL_ERROR - The function failed. 
*/

extern ProError ProSolidDtlsymdefsCollect(
    ProSolid       p_solid,
    ProDtlsymdef **px_sym_defs);

/*
Purpose: Collect symbol definitions in the specified solid.  

Licensing Requirement:
          TOOLKIT for 3D Drawings

Input Arguments:
    p_solid     - The solid handle.

Output Arguments:
    px_sym_defs - The pointer to the array of symbol definitions.
                  The function allocates ProArray. Use the function
                  ProArrayFree to release the memory.

.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the symbol 
                            definitions. 
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No symbol definitions were found.
    PRO_TK_OUT_OF_MEMORY - The function found too many items to be contained in the output ProArray.  Use ProSolidDtlsymdefVisit instead.
*/

PRO_END_C_DECLS

#endif
