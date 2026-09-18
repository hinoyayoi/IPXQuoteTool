#ifndef PROUIMENUPANE_H
#define PROUIMENUPANE_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIMenupaneTextSet(
    char       *dialog,
    char       *menupane,
    wchar_t    *text);

/*
   Purpose: Set the text to appear on the button in a menu bar
            activating a menu pane
<p>    
             Use this function only with a menu bar in a custom
             application-created UI dialog.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the menu pane
      menupane		- The name of the menu pane
      text		- The new text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMenupaneIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Menupane is visible in the dialog or not.
<p>    
             Use this function only with a menu bar in a custom
             application-created UI dialog.

    Input Arguments:
       dialog            - The name of the dialog that contains the menu pane
       component	 - The name of the menu pane
                           
    Output Arguments:
        state            - Whether or not the menu pane is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenupaneShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog.
<p>    
             Use this function only with a menu bar in a custom
             application-created UI dialog.

    Input Arguments:
       dialog            - The name of the dialog that contains the menu pane
       component	 - The name of the menu pane
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenupaneHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog.
<p>    
             Use this function only with a menu bar in a custom
             application-created UI dialog.

    Input Arguments:
       dialog            - The name of the dialog that contains the menu pane
       component	 - The name of the menu pane
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/



extern ProError ProUIMenupaneCheckbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new checkbutton to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the checkbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupanePushbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new pushbutton to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the pushbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneRadiogroupAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new radiogroup to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the radiogroup to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneSeparatorAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new separator to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the separator to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneCascadebuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new cascadebutton to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the cascadebutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneCheckbuttonInsert (char* dialog, char* component, ProUIPosition pos, char* sibling, char* name);
/*
    Purpose: Insert a new check button in the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        pos - Position of the check button with respect to the sibling.
        sibling - The name of the existing reference component.
        name - The name of the new check button inserted.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupanePushbuttonInsert (char* dialog, char* component, ProUIPosition pos, char* sibling, char* name);
/*
    Purpose: Insert a new push button in the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        pos - Position of the  push button with respect to the sibling.
        sibling - The name of the existing reference component.
        name - The name of the inserted push button.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneRadiogroupInsert (char* dialog, char* component, ProUIPosition pos, char* sibling, char* name);
/*
    Purpose: Insert a new radio group in the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        pos - Position of the radio group with respect to the sibling.
        sibling - The name of the existing reference component.
        name - The name of the inserted radio group.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneSeparatorInsert (char* dialog, char* component, ProUIPosition pos, char* sibling, char* name);
/*
    Purpose: Insert a new separator in the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        pos - Position of the separator with respect to the sibling.
        sibling - The name of the existing reference component.
        name - The name of the inserted separator.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneCascadebuttonInsert (char* dialog, char* component, ProUIPosition pos, char* sibling, char* name);
/*
    Purpose: Insert a new cascade button in the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        pos - Position of the cascade button with respect to the sibling.
        sibling - The name of the existing reference component.
        name - The name of the inserted cascade button.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneCheckbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the checkbutton from the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupanePushbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the pushbutton from the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneRadiogroupRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the radiogroup from the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneSeparatorRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the separator from the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the separator to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneCascadebuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the cascadebutton from the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains menupane
        component - The name of the menupane component.
        name - Name of the cascadebutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIMenupaneChildnamesGet (char *dialog, char *component, int *count, char ***values);
/*
     Purpose: Get the name of the children to the menupane component.

     Input Arguments:
         dialog - The name of the dialog that contains the menupane.
         component - The name of the menupane component.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIMenupaneBitmapSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the bitmap to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneBitmapGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the bitmap to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - The name of the menupane. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupanePopupmenuSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the popup menu to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.
        value - The name of the popup menu.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupanePopupmenuGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the popup menu for the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - The name of the menupane. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the menupane at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the menupane at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menupane is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the menupane        
                is attached at left. PRO_B_FALSE if the menupane is not 
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the menupane at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the menupane at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menupane is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the menupane       
                is attached at right. PRO_B_FALSE if the menupane is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the menupane at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the menupane at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menupane is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the menupane         
                is attached at top. PRO_B_FALSE if the menupane is not  
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the menupane at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the menupane at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menupane is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the menupane      
                is attached at bottom. PRO_B_FALSE if the menupane is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenupaneTextGet (
    char                   *dialog,
    char                   *component,
    wchar_t               **value);

/*
    Purpose: Get label of the menupane.

    Input Arguments:
        dialog - The name of the dialog that contains the menupane.
        component - The name of the menupane component.

    Output Arguments:
        value - Label of the menupane.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


PRO_END_C_DECLS
 
#endif  /* PROUIMENUPANE_H */
