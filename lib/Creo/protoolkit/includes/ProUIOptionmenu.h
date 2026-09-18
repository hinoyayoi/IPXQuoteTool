#ifndef PROUIOPTIONMENU_H
#define PROUIOPTIONMENU_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIOptionmenuHelptextSet(
    char*	dialog,
    char*	optionmenu,
    wchar_t*    helptext);

/*
   Purpose:    Set the helptext of an option menu component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuColumnsSet(
    char*	dialog,
    char*	optionmenu,
    int         columns);
/*
   Purpose:    Set the number of columns of an option menu component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
      columns           - The number of columns
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUIOptionmenuItemhelptextSet(
    char*	dialog,
    char*	optionmenu,
    int         n_items,
    wchar_t**   itemhelptext);

/*
   Purpose:    Set the help text on the items in an option menu
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
      n_items           - The number of text items
      itemhelptext      - An array of help text items
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuLabelsSet(
    char*	dialog,
    char*	optionmenu,
    int         n_labels,
    wchar_t**   labels);
 
/*
   Purpose:    Set the labels on the options in an option menu component.
                The labels are the identifiers for the options in an option
                menu that are displayed on the dialog. Before defining
                the labels, you must specify the internal names using
                ProUIOptionmenuNamesSet().
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      optionmenu        - The name of the radio group component
      n_labels          - The number in the array of labels
      labels            - An array of labels, one for each option in the option
                                menu
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUIOptionmenuNamesSet(
    char*	dialog,
    char*	optionmenu,
    int         n_names,
    char**	names);
 
/*
   Purpose:    Set the names on the options in an option menu component. The
                names are the internal identifiers for the options in an
                option menu.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      optionmenu        - The name of the option menu component
      n_names           - The number in the array of names
      names             - The array of names
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuVisiblerowsSet(
    char*	dialog,
    char*	optionmenu,
    int         visible_rows);
 
/*
   Purpose:    Set the number of rows to be visible in an option menu
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      optionmenu        - The name of the option menu component
      visible_rows      - The number of rows to be visible
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed


   <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuActivateActionSet(
    char*	dialog,
    char*	optionmenu,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the activate action for an option menu. This function is
                called only for an editable option menu, and the callback is 
                invoked when the RETURN key has been pressed in the input panel 
                of the option menu.
               See ProUIOptionmenuSelectActionSet() for setting an action to be called
                when the user selects an item in the option menu.

   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
      action            - The action to be called on selecting a button
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuEnable(
    char* dialog,
    char* optionmenu);
 
/*
   Purpose:    Enables the option menu
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed


   <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuDisable(
    char* dialog,
    char* optionmenu);
/*
   Purpose:    Disables the option menu
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuSelectActionSet(
    char*	dialog,
    char*	optionmenu,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the select action for an option menu. 
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      optionmenu        - The name of the option menu component
      action            - The action to be called.
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuValueSet(
    char*	dialog,
    char*	component,
    wchar_t*	value);
/*
   Purpose:    Sets the current value of an option menu. 
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      component        - The name of the option menu component
      value		- The new value
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed


   <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuValueGet(
    char*	dialog,
    char*	component,
    wchar_t**	value);
/*
   Purpose:    Gets the label of the option item.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the option menu
      component        - The name of the option menu component
 
   Output Arguments:
      value		- The label of the option item
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Optionmenu is visible in the dialog or not.

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
                           
    Output Arguments:
        state           - Whether or not the optionmenu is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -List->
*/

extern ProError ProUIOptionmenuEditable (
    char   *dialog,
    char   *component
);
/*
    Purpose: Makes the optionmenu editable

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUIOptionmenuReadOnly (
    char                   *dialog, 
    char                   *component);
    
/*
    Purpose: Make the optionmenu read only.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
	PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/    

extern ProError ProUIOptionmenuIsEditable (
    char                   *dialog, 
    char                   *component, 
    ProBoolean             *state);

/*
    Purpose: Check if optionmenu is editable.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        state  - Optionmenu editable state

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/    

extern ProError ProUIOptionmenuSelectednamesGet(
    char*	dialog,
    char*	optionmenu,
    int*        n_selections,
    char***     selections);
/*
   Purpose:    Gives the names of the currently selected items in a optionmenu

   Input Arguments:
      dialog            - The name of the dialog that contains the opt6ionmenu
      optionmenu        - The name of the optionmenu component
 
   Output Arguments:
      n_selections      - The number of selections
      selections        - An array of strings containing the names of items
			  in the optionmenu currently selected. 
			  The memory for this array is allocated by the
                          function and should be freed with 
                          ProStringarrayFree().
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIOptionmenuSelectednamesSet(
    char*	dialog,
    char*	optionmenu,
    int         n_selections,
    char**	selections);
/*
   Purpose:    Gives the names of the currently selected items in a optionmenu

   Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu
      optionmenu        - The name of the optionmenu component
      n_selections      - The number of selections
      selections        - An array of strings containing the names of items
				in the optionmenu currently selected
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed


   <!-- Objectname: ProUI -->
*/


extern ProError ProUIOptionmenuInputActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the input action for an optionmenu. This 
                function is called when the user changes the contents of the 
		option menu.  This is only valid for Editable optionmenus.

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
      callback          - The action to perform when the user changes the contents.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIOptionmenuTriggerhighlightActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the trigger highlight action for an optionmenu. This 
                function is called when the user moves the mouse onto an item
		on the drop down list of the optionmenu.

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
      callback          - The action to perform when the user highlights the item.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUIOptionmenuLastentereditemGet()
   <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuLastentereditemGet (char *dialog, 
					     char *component, 
					     char **value);

/*
    Purpose: Gets the name of the optionmenu item last pointed to by the 
             mouse cursor.  This value is impportant when interpreting a
	     TriggerHighlight event.

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
   
    Output Arguments:
      value             - The name of the optionmenu item last pointed to by 
                           the cursor.  Free this string using ProStringFree.
                          

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIOptionmenuFocusinActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the focus out action for an optionmenu. This function is
                called when the user moves the cursor onto the optionmenu
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
      callback          - The action to perform when the optionmenu gains user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIOptionmenuFocusoutActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the focus out action for an optionmenu. This function is
                called when the user moves the cursor off of the optionmenu
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the optionmenu.
      component         - The name of the optionmenu component
      callback          - The action to perform when the optionmenu loses user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIOptionmenuPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the optionmenu.

    Input Arguments:
        dialog             - The dialog name.
        component          - The component name.
        value              - The name of the popup menu pane.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIOptionmenuPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the optionmenu.

    Input Arguments:
        dialog             - The dialog name.
        component          - The component name.
        

    Output Arguments:
        value              - The name of the popup menu pane.  Free this string
	                      using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

 



extern ProError ProUIOptionmenuAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
   Purpose: Sets the position of the option menu with respect to a given 
              anchor location. This function is applicable  only if the parent 
              of the option menu is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the option menu.
        component - The name of the option menu component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the option menu used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the optionmenu. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the optionmenu's minimum size, the function will fail.
              The optionmenu's minimum size can be retrieved
              using ProUIOptionmenuMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the optionmenu with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the optionmenu with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the optionmenu in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the optionmenu. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIOptionmenuParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the optionmenu component.

     Input Arguments:
         dialog - The name of the dialog that contains the optionmenu.
         component - The name of the optionmenu component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIOptionmenuHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that should display when the cursor is over
	    the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuIsEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the optionmenu is sensitive to the user input or
	     not.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        state - PRO_B_TRUE if the optionmenu is sensitive.
		PRO_B_FALSE if the optionmenu is not sensitive.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuColumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the width of the optionmenu in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Width of the optionmenu.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuMincolumnsSet (char* dialog, char* component, int value);
/*
    Purpose: Set the minimum width of the optionmenu in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.
        value - Minimum width of the optionmenu.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuMincolumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum width of the optionmenu in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Minimum width of the optionmenu.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuVisiblerowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of visible rows in the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Number of visible rows.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuNamesGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Get the names of the items in the option menu. 

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        count - Number of items.
        values - Array of names of the items. Free this using ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuLabelsGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the label names of the items in the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        count - Number of labels.
        values - Array of labels text. Free this using ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuItemhelptextGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the helptexts that will display when the cursor is over 
	     the items in the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        count - Number of helptexts.
        values - Array of helptexts corresponding to each item in the 
		optionmenu. Free this using ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the optionmenu at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the optionmenu at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  optionmenu is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the optionmenu      
                is attached at left. PRO_B_FALSE if the optionmenu is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the optionmenu at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the optionmenu at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  optionmenu is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the optionmenu     
                is attached at right. PRO_B_FALSE if the optionmenu is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the optionmenu at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the optionmenu at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  optionmenu is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the optionmenu       
                is attached at top. PRO_B_FALSE if the optionmenu is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the optionmenu at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the optionmenu at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  optionmenu is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the optionmenu    
                is attached at bottom. PRO_B_FALSE if the optionmenu is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIOptionmenuItemimageSet (
    char                   *dialog, 
    char                   *component, 
    int                     count, 
    char                  **values);
/*
    Purpose: Set the image names used for display of the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.
        count  - The number of items (should match the number of names set 
	         in this component).
        values - The image names.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUIOptionmenuItemimageGet (
    char                   *dialog, 
    char                   *component, 
    int                    *count, 
    char                 ***values);
/*
    Purpose: Get the image names used for display of the optionmenu.

    Input Arguments:
        dialog - The name of the dialog that contains the optionmenu.
        component - The name of the optionmenu component.

    Output Arguments:
        count  - The number of items.
        values - The image names.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/



PRO_END_C_DECLS
 
#endif  /* PROUIOPTIONMENU_H */
