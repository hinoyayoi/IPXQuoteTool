#ifndef PROUIMENUBAR_H
#define PROUIMENUBAR_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIMenubarHelptextSet(
    char*	dialog,
    char*	menubar,
    wchar_t*    helptext);

/*
   Purpose: Set the helptext of a menu bar component.
            <p>
            Use this function only with a menu bar in a custom
            application-created UI dialog.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the menu bar
      menubar		- The name of the menu bar component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIMenubarNamesSet (
    char       *dialog,
    char       *menubar,
    int         count,
    char      **values);

/*
   Purpose: Set the list of names for menu panes in a menu bar.
            <p>
             Use this function only with a menu bar in a custom
             application-created UI dialog.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the menu bar
      menubar		- The name of the menu bar component
      count		- The number of items on the values array
      values		- Array of names of menu panes in the menu bar.
			  This list of names is used only by the function
			  ProUIMenubarItemhelptextSet().
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMenubarItemhelptextSet (
    char       *dialog,
    char       *menubar,
    int         count,
    wchar_t   **values);

/*
   Purpose: Set the help text on the menu panes in the menu bar.
            <p>  
             Use this function only with a menu bar in a custom
             application-created UI dialog.  
   
   Input Arguments:
      dialog            - The name of the dialog that contains the menu bar
      menubar		- The name of the menu bar component
      count		- The number of items on the values array
      values		- Array of help text lines for the menu panes
                          in the menu bar. Before setting item
                          help text, set names for the items using
                          ProUIMenubarNamesSet().
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMenubarSelectablenamesSet (
    char       *dialog,
    char       *menubar,
    int         count,
    char      **values);

/*
   Purpose: Set which buttons in the menu bar are currently selectable
            <p>  
            Use this function only with a menu bar in a custom
            application-created UI dialog.
   
   Input Arguments:
      dialog            - The name of the dialog that contains the menu bar
      menubar		- The name of the menu bar component
      count		- The number of items on the values array
      values		- Array of names of menu panes in the menu bar
                          which are to be selectable. An empty
                          list (or NULL) implies that all are
                          selectable. Unselectable menu panes are 
                          greyed out.
                          The names should be those of the menu pane
                          components themselves, not the item names
                          set using ProUIMenubarNamesSet().
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMenubarVisiblenamesSet (
    char       *dialog,
    char       *menubar,
    int         count,
    char      **values);

/*
   Purpose: Set which buttons in the menu bar are currently visible
            <p>  
            Use this function only with a menu bar in a custom
            application-created UI dialog.

   Input Arguments:
      dialog            - The name of the dialog that contains the
                          menu bar
      menubar		- The name of the menu bar component
      count		- The number of items on the values array
      values		- Array of names of menu panes in the menu bar
                          which are to be visible. An empty list
                          (or NULL) implies that all are visible.
                          The names should be those of the menu pane
                          components themselves, not the item names
                          set using ProUIMenubarNamesSet().
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIMenubarIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Menubar is visible in the dialog or not.
             <p>   
             Use this function only with a menu bar in a custom
             application-created UI dialog. 
    
    Input Arguments:
       dialog            - The name of the dialog that contains the menu bar
       component	 - The name of the menu bar component
                           
    Output Arguments:
        state            - Whether or not the menu bar is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenubarShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog.
            <p>   
             Use this function only with a menu bar in a custom
             application-created UI dialog.
 
    Input Arguments:
       dialog            - The name of the dialog that contains the menu bar
       component	 - The name of the menu bar component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenubarHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog.
             <p>   
             Use this function only with a menu bar in a custom
             application-created UI dialog. 

    Input Arguments:
       dialog            - The name of the dialog that contains the menu bar
       component	 - The name of the menu bar component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenubarIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Menubar is enabled or not.
             <p>   
             Use this function only with a menu bar in a custom
             application-created UI dialog.
 
    Input Arguments:
       dialog            - The name of the dialog that contains the menu bar
       component	 - The name of the menu bar component
                          
    Output Arguments:
        state            - Whether or not the menu bar is enabled.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenubarEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Menubar to be enabled.
              <p>    
              Use this function only with a menu bar in a custom
              application-created UI dialog.
 
    Input Arguments:
       dialog            - The name of the dialog that contains the menu bar
       component	 - The name of the menu bar component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIMenubarDisable(
    char* dialog,
    char* component);
/*
   Purpose: Sets the Menubar to be disabled, so the user cannot
	    select it.
            <p>    
            Use this function only with a menu bar in a custom
            application-created UI dialog.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component         - The name of the Menubar component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS      - An invalid argument was given

   <!-- Objectname: ProUI -->
*/




extern ProError ProUIMenubarHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarPopupmenuSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the popup menu for the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.
        value - The name of the popup menu.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarPopupmenuGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the popup menu for the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        value - The name of the popup menu. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the menubar at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the menubar at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menubar is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the menubar         
                is attached at left. PRO_B_FALSE if the menubar is not   
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the menubar at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the menubar at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menubar is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the menubar        
                is attached at right. PRO_B_FALSE if the menubar is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the menubar at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the menubar at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menubar is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the menubar          
                is attached at top. PRO_B_FALSE if the menubar is not     
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the menubar at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the menubar at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  menubar is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the menubar       
                is attached at bottom. PRO_B_FALSE if the menubar is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the menubar.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarNamesGet (
    char                   *dialog,
    char                   *component,
    int                    *count,
    char                 ***values);
/*
    Purpose: Get a list of menubar names.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
	count - Number of names in an array of values/menubar names.
	values - Array of menubar names. Free this using ProStringarrayFree (). 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIMenubarItemhelptextGet (
    char                   *dialog,
    char                   *component,
    int                    *count,
    wchar_t              ***values);

/*
    Purpose: Get a list of menubar helptexts.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
	count - Number of names in an array of values/menubar helptexts.
	values - Array of menubar helptexts. Free this using ProStringarrayFree (). 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIMenubarSelectablenamesGet (
    char                   *dialog,
    char                   *component,
    int                    *count,
    char                 ***values);

/*
    Purpose: Get names of the selectable items of the component. An empty
	array indicates that every item of the component may be selected.
 
    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.
 
    Output Arguments:
        count - Number of names in an array of values/selectable items.
        values - Array of menubar selectable names. Free this using ProStringarrayFree ().
 
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/

extern ProError ProUIMenubarVisiblenamesGet (
    char                   *dialog,
    char                   *component,
    int                    *count,
    char                 ***values);

/*
    Purpose: Get a list of visible  menubar names.

    Input Arguments:
        dialog - The name of the dialog that contains the menubar.
        component - The name of the menubar component.

    Output Arguments:
	count - Number of names in an array of values/visible menubar names.
	values - Array of visible menubar names. Free this using ProStringarrayFree (). 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

PRO_END_C_DECLS
 
#endif  /* PROUIMENUBAR_H */
