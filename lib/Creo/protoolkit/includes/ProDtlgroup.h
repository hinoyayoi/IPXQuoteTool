#ifndef PRODTLGROUP_H 
#define PRODTLGROUP_H
			


#include <ProDtlitem.h>
#include <ProDtlattach.h>

typedef struct pro_groupdata *ProDtlgroupdata;

PRO_BEGIN_C_DECLS
/*================================================================*\
    ProDtlgroup  functions
\*=================================================================*/
extern ProError ProDtlgroupCreate(
    ProDrawing  drawing,
    ProDtlgroupdata data,
    ProDtlgroup *group);
/*

Purpose: Create the group of drawing draft entities, symbols, notes.  

Input Arguments:

    drawing   - The drawing handle.
    data      - The group data handle

Output Arguments:

    group     - Created group 

Return Values:

    PRO_TK_NO_ERROR      - The function successfully created the group.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't create the group with specified arguments.

*/ 

extern ProError ProDtlgroupDataGet(
    ProDtlgroup *group,
    ProDtlgroupdata *data);
/*

Purpose: Get a group data for the specified group.  

Input Arguments:

    group     - The group handle.

Output Arguments:

    data      - The group data.

Return Values:

    PRO_TK_NO_ERROR      - The function successfully retrieved the group data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't retrieve the group data with specified 
                            arguments.

*/ 

extern ProError ProDtlgroupDelete(
    ProDtlgroup *group);
/*

Purpose: Delete specified group.  

Input Arguments:

    group     - The group handle

Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR      - The function successfully deleted the group.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_GENERAL_ERROR - Can't delete the group.

*/ 

extern ProError ProDtlgroupModify(
    ProDtlgroup *group,
    ProDtlgroupdata data);
/*

Purpose: Modify the specified group.  

Input Arguments:

    group     - The group handle
    data      - The group data

Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR      - The function successfully modified the group.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't modify the group with specified arguments.

*/ 

extern ProError ProDrawingDtlgroupsCollect(
    ProDrawing drawing,
    int sheet,
    ProDtlgroup **groups);
/*

Purpose: Collect groups in the specified drawing.  

Input Arguments:

    drawing   - The drawing handle
    sheet     - The sheet number

Output Arguments:

    groups    - The pointer to ProArray of ProDtlgroup handles.
                The function allocates memory for the array, user must
                release the memory using ProArrayFree.

Return Values:

    PRO_TK_NO_ERROR      - The function successfully collected the groups.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No groups were found.
    PRO_TK_OUT_OF_MEMORY - The function found too many entities to be contained in the output ProArray.  Use ProDrawingDtlgroupVisit instead.
*/ 

extern ProError ProDrawingDtlgroupVisit(
    ProDrawing drawing,
    int sheet,
    ProDtlitemVisitAction visit_action,
    ProDtlitemFilterAction filter_action,
    ProAppData appdata);
/*

Purpose: Visit groups in the specified drawing.  

Input Arguments:

    drawing       - The drawing handle
    sheet         - The sheet number
    visit_action  - Visit action function
    filter_action - Filter action function. If NULL, 
                    all groups are visited using the 
                    action function.
    appdata       - The application data 
    
Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR      - The function successfully visited the groups.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No groups were found.
    Other                - Return value passed by the caller's visit function.
*/ 

/*================================================================*\
    ProDtlgroupdata functions
\*=================================================================*/
extern ProError ProDtlgroupdataAlloc(
    ProDrawing  drawing,
    ProName name,
    ProDtlgroupdata *groupdata);
/*

Purpose: Allocate and initialize memory for group data. User must 
        release memory using ProDtlgroupdataFree.  

Input Arguments:

    drawing   - The drawing handle.
    name      - Name of group.
    
Output Arguments:

    groupdata - group data handle.

Return Values:

    PRO_TK_NO_ERROR      - The function successfully allocate memory.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    PRO_TK_OUT_OF_MEMORY - Not enough memory for allocation.
*/ 

extern ProError ProDtlgroupdataFree(
    ProDtlgroupdata groupdata);
/*

Purpose: Release memory allocated by ProDtlgroupdataAlloc.  

Input Arguments:

    groupdata - The group data.
    
Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR      - The function successfully release memory.
    PRO_TK_BAD_INPUTS    - Bad input argument.
*/ 

extern ProError ProDtlgroupdataIdGet(
    ProDtlgroupdata groupdata,
    int *id);
/*

Purpose: Get group Id .  

Input Arguments:

    groupdata - The group data.
    
Output Arguments:

    id        - The group id

Return Values:

    PRO_TK_NO_ERROR      - The function successfully retrieved id.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
*/ 

extern ProError ProDtlgroupdataNameGet(
    ProDtlgroupdata groupdata,
    ProName name);
/*

Purpose: Get a group name.  

Input Arguments:
    groupdata - The group data.
    
Output Arguments:
    name      - The group name

Return Values:

    PRO_TK_NO_ERROR      - The function successfully retrieved the name.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    
*/ 

extern ProError ProDtlgroupdataItemAdd(
    ProDtlgroupdata groupdata,
    ProDtlitem *item);
/*

Purpose: Add an item to the group.  

Input Arguments:

    groupdata - The group data.
    item      - The detail item.
    
Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR      - The function successfully added the item.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_INVALID_TYPE  - Invalid type of item.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlgroupdataItemsSet(
    ProDtlgroupdata groupdata,
    ProDtlitem *items);
/*

Purpose: Set items to the group data.  

Input Arguments:

    groupdata - The group data handle.
    items     - A ProArray of detail items.
    
Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR      - The function successfully set the items.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_INVALID_TYPE  - Invalid type of one of item.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlgroupdataItemsCollect(
    ProDtlgroupdata groupdata,
    ProDtlitem **items);
/*

Purpose: Collect group data items in the specified group data.  

Input Arguments:

    groupdata - The group data.
    
Output Arguments:

    items     - Pointer to ProArray of detail items.
                Function allocates memory for argument, user must
                release the memory using ProArrayFree.
    
Return Values:

    PRO_TK_NO_ERROR      - The function successfully collected the items.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_INVALID_TYPE  - Invalid type of one of item.
    PRO_TK_E_NOT_FOUND   - The group does not contain any items.
    
*/ 

extern ProError ProDtlgroupErase(
    ProDtlgroup *group );
/*

Purpose: Makes a group disappear from the drawing until 
	 the drawing is regenerated.
	 
Input Arguments:
    group	- The group handle.

Output Arguments:
      none

Return Values:

    PRO_TK_NO_ERROR	- The function successfully erased the group.
    PRO_TK_BAD_INPUTS	- Invalid input argument.
    PRO_TK_GENERAL_ERROR- Cannot erase a group.

*/

extern ProError ProDtlgroupDraw(
    ProDtlgroup *group );
/*

Purpose: Makes a group appear on the drawing until
         the drawing is regenerated.

Input Arguments:
    group       - The group handle.

Output Arguments:
      none

Return Values:

    PRO_TK_NO_ERROR      - The function successfully displayed the group.
    PRO_TK_BAD_INPUTS    - Invalid input argument.
    PRO_TK_GENERAL_ERROR - Cannot draw a group.

*/

extern ProError ProDtlgroupdataIsDisplayed(
    ProDtlgroupdata data,
    ProBoolean *is_displayed);

/*
   Purpose:   checks if the draft group is displayed

   Input Arguments:
      data              - The draft group data.

   Output Arguments:
      is_displayed      - PRO_B_TRUE if the draft entity is displayed


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlgroupdataDisplayedSet(
    ProDtlgroupdata data,
    ProBoolean displayed);

/*
   Purpose:   Marks the draft entity to be displayed

   Input Arguments:
      data                 - The draft group data.
      displayed            - PRO_B_TRUE if the draft group is to be displayed

   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/



PRO_END_C_DECLS

#endif
