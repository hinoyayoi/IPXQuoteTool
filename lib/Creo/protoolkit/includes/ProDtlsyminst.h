#ifndef PRODTLSYMINST_H
#define PRODTLSYMINST_H
			

#include <ProDtlitem.h>
#include <ProDtlsymdef.h>
#include <ProDimension.h>
#include <ProDtlnote.h>

typedef struct pro_syminstdata_new *ProDtlsyminstdata;
typedef struct prodtl_var_text_value *ProDtlvartext;

typedef enum {
PRO_DTLSYMINST_GROUP_INTERACTIVE,
PRO_DTLSYMINST_GROUP_ALL,
PRO_DTLSYMINST_GROUP_NONE,
PRO_DTLSYMINST_GROUP_CUSTOM
} ProDtlsyminstGroupOption;

typedef enum {
PRO_DTLSYMINST_GROUPS_ALL,
PRO_DTLSYMINST_GROUPS_ACTIVE,
PRO_DTLSYMINST_GROUPS_INACTIVE
} ProDtlsyminstGroupStatus;

PRO_BEGIN_C_DECLS
/*================================================================*\
    ProDtlsyminst  functions
\*=================================================================*/
extern ProError ProDtlsyminstCreate(
    ProMdl            model,
    ProDtlsyminstdata data,
    ProDtlsyminst    *syminst);
/*

Purpose: Create a symbol instance in the specified model. ProAnnotationShow() 
	 should be called after creating the instance in order for the 
         instance to be displayed. 

Input Arguments:
    model     - The model handle.
    data      - The symbol instance data.

Output Arguments:
    syminst   - Created symbol instance

Return Values:
    PRO_TK_NO_ERROR      - The function successfully created the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't create the symbol instance.

*/ 

extern ProError ProDtlsyminstDataGet(
    ProDtlsyminst *syminst,
    ProDisplayMode mode,
    ProDtlsyminstdata *data);
/*

Purpose: Get a symbol instance data.  

Input Arguments:
    syminst   - The symbol instance.
    mode      - The display mode

Output Arguments:
    data      - The symbol instance data.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved symbol instance 
                            data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't retrieve the symbol instance data.

*/ 

extern ProError ProDtlsyminstDimattachGet(ProDtlsyminst *syminst, 
                                          ProDimension *dim);
/*

Purpose: Finds the dimension to which the symbol instance is directly attached.

Input Arguments:  
    syminst   - The symbol instance

Output Arguments: 
    dim       - Cannot be NULL. The dimension to which the symbol instance is
                directly attached.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully found the dimension attachment.
                       It is in dim
  PRO_TK_BAD_INPUTS  - Bad input arguments
  PRO_TK_NOT_EXIST   - The symbol instance is not placed on item to a dimension
  PRO_TK_BAD_CONTEXT - The symbol instance is placed on a dim but we are unable
                       to fill in the output structure on account of the 
                       dimension's model being missing (perhaps it was 
                       suppressed in the assembly).

*/

extern ProError ProDtlsyminstDelete(
    ProDtlsyminst *syminst);
/*

Purpose: Delete a symbol instance.  

Input Arguments:
    syminst   - The symbol instance 

Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully deleted the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't delete symbol instance.
    PRO_TK_CANT_WRITE    - Could not delete the given item because
                           it has read-only access.

*/ 

extern ProError ProDtlsyminstModify(
    ProDtlsyminst *syminst,
    ProDtlsyminstdata syminstdata);
/*

Purpose: Modify a symbol instance.  

Input Arguments:
    syminst   - The symbol instance.
    syminstdata - The symbol instance data.

Output Arguments:
    None
    
Return Values:
    PRO_TK_NO_ERROR      - The function successfully modified the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't modify the symbol instance.
    PRO_TK_CANT_WRITE    - Could not modify the given item because
                           it has read-only access.

*/ 

extern ProError ProDtlsyminstDraw(
    ProDtlsyminst *syminst);
/*

Purpose: Draw a symbol instance. Make symbol instance in the database appear 
        on the drawing until the drawing is regenerated. 

Input Arguments:
    syminst   - The symbol instance
    
Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully draw the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't draw the symbol instance.

*/ 

extern ProError ProDtlsyminstErase(
    ProDtlsyminst *syminst);
/*

Purpose: Erase a symbol instance. Make symbol instance in the database
        disappear on the drawing until the drawing is regenerated. 

Input Arguments:
    syminst   - The symbol instance
    
Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully erased the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't erase the symbol instance.

*/ 

extern ProError ProDtlsyminstShow(
    ProDtlsyminst *syminst);
/*

Purpose: Show a symbol instance. Make symbol instance in the database appear 
        on the drawing and continue to appear after the drawing is regenerated.

Input Arguments:
    syminst              - The symbol instance
    
Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully show the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't show symbol instance.

*/ 

extern ProError ProDtlsyminstRemove(
    ProDtlsyminst *syminst);
/*

Purpose: Remove a symbol instance. Make symbol instance in the database 
        disappear on the drawing and continue to disappear after the 
        drawing is regenerated.

Input Arguments:
    syminst   - The symbol instance

Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully removed the symbol 
                            instance.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't remove the symbol instance.

*/ 

extern ProError ProDrawingDtlsyminstsCollect(
    ProDrawing drawing,
    int sheet,
    ProDtlsyminst **syminsts);
/*

Purpose: Collect symbol instances in the specified drawing

Input Arguments:
    drawing   - The drawing handle.
    sheet     - The sheet number. If the value is PRO_VALUE_UNUSED,
                the function uses the current sheet. 

Output Arguments:
    syminsts  - The pointer to ProArray of ProDtlsyminst. The function 
                allocates memory for array. User must release memory by
                ProArrayFree.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the symbol 
                            instances.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No symbol instances were found.
    PRO_TK_OUT_OF_MEMORY - The function found too many instances to be contained in the output ProArray.  Use ProDrawingDtlsyminstVisit instead.
    
*/ 

extern ProError ProDrawingDtlsyminstVisit(
    ProDrawing drawing,
    int sheet,
    ProDtlitemVisitAction visit_action,
    ProDtlitemFilterAction filter_action,
    ProAppData appdata);
/*

Purpose: Visit symbol instances in the specified drawing

Input Arguments:
    drawing       - The drawing handle.
    sheet         - The sheet number.
    visit_action  - Dtlitem visit action function.
    filter_action - Dtlitem filter action function. If NULL, 
                    all symbol instances are visited using
                    the action function.
    appdata       - The application data.
    
Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully visited the symbol 
                            instances.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No symbol instances were found.
    Other                - Return value passed by the caller's visit function.
    
*/ 

/*================================================================*\
    ProDtlsyminstdata functions
\*=================================================================*/
extern ProError ProDtlsyminstdataAlloc(
    ProMdl	           model,
    ProDtlsyminstdata *data);
/*

Purpose: Allocate and initialize memory for ProDtlsyminstdata structure.
        User must release memory by ProDtlsyminstdataFree.

Input Arguments:
    model   - A model handle
    
Output Arguments:
    data      - The pointer to ProDtlsyminstdata structure.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully allocate memory.
    PRO_TK_BAD_INPUTS    - Bad argument.
    
*/ 

extern ProError ProDtlsyminstdataFree(
    ProDtlsyminstdata data);
/*

Purpose: Release memory allocated by ProDtlsyminstdataAlloc.

Input Arguments:
    data      - The symbol instance data.
    
Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully release memory.
    PRO_TK_BAD_INPUTS    - Bad argument.
    
*/ 

extern ProError ProDtlsyminstdataColorSet(
    ProDtlsyminstdata data,
    ProColor *color);
/*

Purpose: Set a symbol instance color.

Input Arguments:
    data      - The symbol instance data.
    color     - The color.
    
Output Arguments:
    None
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the color.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataColorGet(
    ProDtlsyminstdata data,
    ProColor *color);
/*

Purpose: Get a symbol instance color.

Input Arguments:
    data      - The symbol instance data.
    
Output Arguments:
    color     - The color.
       
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the color.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataDefSet(
    ProDtlsyminstdata data,
    ProDtlsymdef *definition);
/*

Purpose: Set a symbol definition.

Input Arguments:
    data       - The symbol instance data.
    definition - The symbol definition.
    
Output Arguments:
    None
           
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the symbol definition.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataDefGet(
    ProDtlsyminstdata data,
    ProDtlsymdef *definition);
/*

Purpose: Get a symbol definition.

Input Arguments:
    data       - The symbol instance data.
    
Output Arguments:
    definition - The symbol definition.
           
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the symbol 
                            definition.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataAttachtypeSet(
    ProDtlsyminstdata data,
    ProDtlsymdefattachType type);
/*

Purpose: Set an attachment type.

Input Arguments:
    data       - The symbol instance data.
    type       - The attachment type.
    
Output Arguments:
    None
               
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the attachment type.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataAttachtypeGet(
    ProDtlsyminstdata data,
    ProDtlsymdefattachType *type);
/*

Purpose: Get an attachment type.

Input Arguments:
    data       - The symbol instance data.
    
Output Arguments:
    type       - The attachment type.
               
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the attachment 
                            type.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataDefattachSet(
    ProDtlsyminstdata data,
    ProDtlsymdefattach attach);
/*

Purpose: Set a symbol definition attachment.

Input Arguments:
    data       - The symbol instance data.
    attach     - The symbol definition attachment.
    
Output Arguments:
    None
               
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the attachment.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataDefattachGet(
    ProDtlsyminstdata data,
    ProDtlsymdefattach *attach);
/*

Purpose: Get a symbol definition attachment.

Input Arguments:
    data       - The symbol instance data.
    
Output Arguments:
    attach     - The symbol definition attachment.
               
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the attachment.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_E_NOT_FOUND   - No symbol definition for the specified symbol 
                            instance.
    
*/ 

extern ProError ProDtlsyminstdataAttachmentGet(
    ProDtlsyminstdata data,
    ProDtlattach *attachment);
/*

Purpose: Get a symbol instance attachment.

Input Arguments:
    data       - The symbol instance data.
    
Output Arguments:
    attachment - The symbol instance attachment.
               
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the attachment.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataAttachmentSet(
    ProDtlsyminstdata data,
    ProDtlattach attachment);
/*

Purpose: Set a symbol definition attachment.

Input Arguments:
    data       - The symbol instance data.
    attachment - The symbol definition attachment.
    
Output Arguments:
    None
                   
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the attachment.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataLeadersCollect(
    ProDtlsyminstdata data,
    ProDtlattach **leaders); 
/*

Purpose: Collect leaders for the specified symbol instance.

Input Arguments:
    data       - The symbol instance data.
    
Output Arguments:
    leaders    - The pointer to ProArray of ProDtlattach structures. The 
                function allocates memory for array. User must release memory by
                ProArrayFree.
                   
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the attachments.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_E_NOT_FOUND   - No leaders were found.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataLeadersSet(
    ProDtlsyminstdata data,
    ProDtlattach *leaders);
/*

Purpose: Set leaders for the specified symbol instance.

Input Arguments:
    data       - The symbol instance data.
    leaders    - ProArray of ProDtlattach structures. If this is NULL all leaders from data are removed. 
                 In this case attachment type must be changed to PROSYMDEFATTACHTYPE_FREE using ProDtlsyminstdataAttachmentSet()
Output Arguments:
    None    
                  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the leaders.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataLeaderAdd(
    ProDtlsyminstdata data,
    ProDtlattach leader);
/*

Purpose: Add a leader to the specified symbol instance.

Input Arguments:
    data       - The symbol instance data.
    leader     - The leader. 
                
Output Arguments:
    None    
                  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully added the leader.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataElbowlengthGet(
    ProDtlsyminstdata data,
    ProBoolean *is_default,
    double *elbow_length);
/*

Purpose: Get an elbow length .

Input Arguments:
    data       - The symbol instance data.
                
Output Arguments:
    is_default   - The default flag.
    elbow_length - The elbow length (if is_default == PRO_B_FALSE).
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the elbow.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataElbowlengthSet(
    ProDtlsyminstdata data,
    ProBoolean is_default,
    double elbow_length);
/*

Purpose: Set an elbow length .

Input Arguments:
    data         - The symbol instance data.
    is_default   - The default flag.
    elbow_length - The elbow length (if is_default == PRO_B_FALSE).

Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the elbow.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataAngleSet(
    ProDtlsyminstdata data,
    double angle);
/*

Purpose: Set a symbol instance angle.

Input Arguments:
    data        - The symbol instance data.
    angle       - The angle.

Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the angle.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataAngleGet(
    ProDtlsyminstdata data,
    double *angle);
/*

Purpose: Get a symbol instance angle.

Input Arguments:
    data        - The symbol instance data.

Output Arguments:
    angle       - The angle.
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the angle.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataHeightSet(
    ProDtlsyminstdata data,
    double height);
/*
DEPRECATED: Since Wildfire 5.0
SUCCESSORS: ProDtlsyminstdataScaledheightSet
Purpose: Set a symbol instance height.
<P><B>Note:</B> This function is superseded by
ProDtlsyminstdataScaledheightSet(). This function does not consistently
use the input value in a way that it can be related mathematically to
the symbol height in drawing or model coordinates.

Input Arguments:
    data        - The symbol instance data.
    height      - The height in screen coordinates.
  
Output Arguments:
    None
      
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the height.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataHeightGet(
    ProDtlsyminstdata data,
    double *height);
/*
DEPRECATED: Since Wildfire 5.0
SUCCESSORS: ProDtlsyminstdataScaledheightGet
Purpose: Get a symbol instance height.
<P><B>Note:</B> This function is superseded by
ProDtlsyminstdataScaledheightGet(). This function does not consistently
return a value capable of being related mathematically to the symbol
height in drawing or model coordinates.

Input Arguments:
    data        - The symbol instance data.

Output Arguments:
    height      - The height in screen coordinates.
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the height.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataVartextAdd(
    ProDtlsyminstdata data,
    ProDtlvartext vartext);
/*

Purpose: Add variable text to the symbol instance.

Input Arguments:
    data        - The symbol instance data.
    vartext     - The variable text.
    
Output Arguments:
    None
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully added the text.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataVartextsSet(
    ProDtlsyminstdata data,
    ProDtlvartext *vartexts); 
/*

Purpose: Set variable text.

Input Arguments:
    data        - The symbol instance data.
    vartexts    - ProArray of ProDtlvartext.
    
Output Arguments:
    None
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the text.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlsyminstdataVartextsCollect(
    ProDtlsyminstdata data,
    ProDtlvartext **vartexts); 
/*

Purpose: Get the variable text from the symbol instance data.

Input Arguments:
    data        - The symbol instance data.
    
Output Arguments:
    vartexts    - ProArray of ProDtlvartext. Free this output using
                  ProArrayFree().
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the text.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_E_NOT_FOUND   - No variant text values were found.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/


extern ProError ProDtlsyminstdataTransformGet(
    ProDtlsyminstdata data,
    ProMatrix transform);
/*

Purpose: Get a transformation matrix.

Input Arguments:
    data        - The symbol instance data.
    
Output Arguments:
    transform   - The transformation matrix.
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the matrix.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataScaledheightSet(
    ProDtlsyminstdata data,
    double height);
/*
Purpose: Set the symbol instance height in the units of the drawing or
model, consistent with the values shown in the Properties dialog
for the symbol instance.
<P><B>Note:</B> The scaled height is partially determined based on
the properties of the symbol definition (see ProDtlsyminstdataDefSet()).
Changing the symbol definition may change the calculated value for the
scaled height.

Input Arguments:
    data        - The symbol instance data.
    height      - The height in the drawing or model coordinates.

Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the height.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_E_NOT_FOUND   - The symbol definition assigned to this data was
                           not yet initialized so the scaled value cannot be
                           accurately assigned.

*/

extern ProError ProDtlsyminstdataScaledheightGet(
    ProDtlsyminstdata data,
    double* height);
/*
Purpose: Get the symbol instance height in the units of the drawing or
model, consistent with the values shown in the Properties dialog
for the symbol instance.
<P><B>Note:</B> The scaled height is partially determined based on
the properties of the symbol definition (see
ProDtlsyminstdataDefSet()). Changing the symbol definition may
change the calculated value for the scaled height.

Input Arguments:
    data        - The symbol instance data.

Output Arguments:
    height      - The height in drawing or model coordinates.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the height.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_E_NOT_FOUND   - The symbol definition assigned to this data was
                           not yet initialized so the scaled value cannot be
                           accurately retrieved.
 
*/


/*================================================================*\
    ProDtlvartext functions
\*=================================================================*/
extern ProError ProDtlvartextAlloc(
    ProLine prompt,
    ProLine value,
    ProDtlvartext *vartext);
/*

Purpose: Allocate and initialize memory for variable text structure.

Input Arguments:
    prompt    - The prompt.
    value     - The value.
    
Output Arguments:
    vartext   - The pointer to allocated variable text structure.
                User must release memory by ProDtlvartextFree.
  
Return Values:
    PRO_TK_NO_ERROR      - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlvartextFree(
    ProDtlvartext vartext);
/*

Purpose: Release memory allocated by ProDtlvartextAlloc.

Input Arguments:
    vartext   - The pointer to variable text structure.
    
Output Arguments:
    None
      
Return Values:
    PRO_TK_NO_ERROR      - The function successfully release memory.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/
 
extern ProError ProDtlvartextDataGet (
    ProDtlvartext vartext, 
    ProLine prompt,
    ProLine value);
/*

Purpose: Get var text data.

Input Arguments:
    vartext   - The pointer to variable text structure.
    
Output Arguments:
    prompt    - The prompt.
    value     - The value.

Return Values:
    PRO_TK_NO_ERROR      - The function retrieve data.
    PRO_TK_BAD_INPUTS    - One or more arguments were invalid.
    
*/ 

extern ProError ProDtlsyminstdataIsDisplayed(
    ProDtlsyminstdata data,
    ProBoolean *is_displayed);

/*
   Purpose:   checks if the symbol instance is displayed (not marked as erased).
<P><B>Note:</B>  This is a necessary but not sufficient condition for a
symbol instance to appear on the screen -- a symbol instance may also be
'invisible' (see ProDtlsyminstdataIsInvisible), or attached to or placed in
another item which is missing.

   Input Arguments:
      data              - The symbol instance data.

   Output Arguments:
      is_displayed      - PRO_B_TRUE if the symbol instance is displayed


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlsyminstdataIsInvisible(
    ProDtlsyminstdata data,
    ProBoolean *is_invisible);

/*
   Purpose:   checks if the symbol instance is invisible.  This can
occur if the symbol instance is in a suppressed draft group, or if it
depends on a solid database (such as a BOM balloon, weld symbol, or
datum target symbol does), and the necessary information is missing.

   Input Arguments:
      data              - The symbol instance data.

   Output Arguments:
      is_invisible      - PRO_B_TRUE if the symbol instance is invisible


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlsyminstdataDisplayedSet(
    ProDtlsyminstdata data,
    ProBoolean displayed);

/*
   Purpose:   Marks the symbol instance to be displayed

   Input Arguments:
      data               - The symbol instance  data.
      displayed          - PRO_B_TRUE if the symbol instance is to be displayed

   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlsyminstdataIdGet(
    ProDtlsyminstdata data,
    int *id);
/*
   Purpose:   Get a symbol instance id

   Input Arguments:
      data                 - The symbol instance  data.

   Output Arguments:
      id                   - id of the symbole instance

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlsyminstdataGroupoptionsSet(
    ProDtlsyminstdata data,
    ProDtlsyminstGroupOption option,
    ProDtlsymgroup* group_array);
/*
   Purpose:  Sets the option for displaying groups in the symbol instance.
       
   Input Arguments:
      data        - The symbol instance data.
      option      - The rule to use for group placement. The default (for new
                    placements, when this function is not used) is
                    PRO_DTLSYMINST_GROUP_INTERACTIVE, except in non-graphics
                    mode, the default is PRO_DTLSYMINST_GROUP_ALL.
      group_array - ProArray of variant groups to include in the instance, if
                    option == PRO_DTLSYMINST_GROUP_CUSTOM.  Otherwise, can
                    be NULL.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the information.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/



extern ProError ProDtlsyminstSymgroupsCollect(
    ProDtlsyminst*  sym_inst,
    ProDtlsyminstGroupStatus status,
    ProDtlsymgroup**  group_array);
/*
   Purpose:  Gets the groups included in the symbol instance.
        
   Input Arguments:
      sym_inst - The symbol instance.
      status   - The rule for getting symbol groups.

   Output Arguments:
      group_array - ProArray of groups included in the instance.  Free this
                    output using ProArrayFree ().

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the information.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND - No groups with the designated status were found
                           in the symbol instance.
*/



extern ProError ProDtlsyminstFeatureGet (ProDtlsyminst *symbol_instance,
                                         ProFeature    *symbol_owner);

/*
Purpose: Return the feature that is shown the detail symbol instance.

Input Arguments:
  symbol_instance - The symbol instance that displays the solid model symbol.

Output Arguments:
  symbol_owner    - The feature (i.e. weld feature) that produces the symbol.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the symbol instance.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_E_NOT_FOUND - The symbol instance is not generated from a solid model 
                       feature.
*/


extern ProError ProDtlsyminstdataPlaneSet (ProDtlsyminstdata data, ProAnnotationPlane *plane);
/* 
Purpose: Sets the annotation plane for the 3D symbol data (not applicable to 2D symbols).

  Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          data - The data.
          plane - The annotation plane.

   Output Arguments:
          none

   Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more arguments was invalid.
          PRO_TK_BAD_CONTEXT - Annotation plane is not appropriate for this data.
*/

extern ProError ProDtlsyminstdataPlaneGet (ProDtlsyminstdata data, ProAnnotationPlane* plane);
/*
Purpose: Gets the annotation plane for the 3D symbol data (not applicable to 2D symbols).

  Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          data - The data. 

   Output Arguments:
          plane - The annotation plane.

   Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more arguments was invalid.
          PRO_TK_BAD_CONTEXT - Annotation plane is not appropriate for this data.
*/

extern ProError ProSolidDtlsyminstVisit (ProSolid solid,  
                                         ProDtlitemVisitAction visit_action, 
                                         ProDtlitemFilterAction filter_action, 
                                         ProAppData data);
/*
Purpose: Visits the 3D symbols in a given solid model.

  Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
           solid - The solid model.
          visit_action - The visit function for the symbols.
          filter_action - The filter function for the symbols. Can be NULL.
          data - Application data passed to the visit and filter actions.

   Output Arguments:
          none

   Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more inputs was invalid.
          PRO_TK_E_NOT_FOUND - No symbols were found in the model.
          Other - Error returned by the visit action.
*/

extern ProError ProDtlsymInstnoteDataGet (ProDtlnote* note,
                                          ProDtlsyminstdata data,
                                          ProDisplayMode mode,
                                          ProDtlnotedata *notedata);
/*
  Purpose: Gets data of a note in the symbol instance.

  Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          note - The note attached to symbol instance.
          data - The symbol instance data.
          mode - The display mode.

   Output Arguments:
          notedata - The note data in symbol instance space.
                     Free using ProDtlnotedataFree.

   Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more inputs was invalid.
          PRO_TK_E_NOT_FOUND - No symbols were found in the model.
*/
 

extern ProError ProDtlsymInstentityDataGet( ProDtlentity* entity,
                                            ProDtlsyminstdata data,
                                            ProDtlentitydata *entdata);
/*
  Purpose: Gets data of an entity in the symbol instance.

  Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
          entity - The entity attached to symbol instance.
          data - The symbol instance data.

   Output Arguments:
          entdata - The entity data in symbol instance space.
                     Free using ProDtlentitydataFree.

   Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more inputs was invalid.
          PRO_TK_E_NOT_FOUND - No symbols were found in the model.
*/

extern ProError ProSolidDtlsyminstsCollect(
    ProSolid        p_solid,
    ProDtlsyminst **px_sym_insts);

/*
Purpose: Collect symbol instances in the specified solid

Licensing Requirement:
          TOOLKIT for 3D Drawings

Input Arguments:
    p_solid      - The solid handle.   

Output Arguments:
    px_sym_insts - The pointer to ProArray of ProDtlsyminst. The function 
                   allocates memory for array. Use the function 
                   ProArrayFree to release the memory.

.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the symbol 
                            instances.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No symbol instances were found.
    PRO_TK_OUT_OF_MEMORY - The function found too many instances to be contained in the output ProArray.  Use ProSolidDtlsyminstVisit instead.
*/ 


PRO_END_C_DECLS

#endif
