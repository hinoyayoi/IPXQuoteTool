#ifndef PROUILIST_H
#define PROUILIST_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIListHelptextSet(
    char*	dialog,
    char*	list,
    wchar_t*    helptext);

/*
   Purpose:    Set the helptext of a list component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListColumnsSet(
    char*	dialog,
    char*	list,
    int         columns);
/*
   Purpose:    Set the number of columns in a list component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      columns           - The number of columns
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListColumnlabelSet(
    char*	dialog,
    char*	list,
    wchar_t*	column_label);

/*
   Purpose:    Set the column label for a tabulated list.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      column_label      - The text of the column label. The labels for
				separate columns should be separated by
				tab characters.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListItemhelptextSet(
    char*	dialog,
    char*	list,
    int		n_items,
    wchar_t**	itemhelptext);

/*
   Purpose:    Set the help text of the list
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      n_items           - The number of lines in the array.
      itemhelptext      - An array of help lines, one for each item
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListLabelsSet(
    char*	dialog,
    char*	list,
    int         n_labels,
    wchar_t**	labels);

/*
   Purpose:    Set the labels on the buttons in a list component.
		The labels are the identifiers for the items in a list
		that are displayed on the dialog. Before defining
		the labels, you must specify the internal names using
		ProUIListNamesSet().
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      n_labels		- The number of labels
      labels		- An array of labels.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListListtypeSet(
    char*	  dialog,
    char*	  list,
    ProUIListtype type);
 
/*
   Purpose:    Set type of display for the list component.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      type              - The type of display for the list component.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListMinrowsSet(
    char*	dialog,
    char*	list,
    int         minrows);

/*
   Purpose:    Set the minimum number of rows for a list
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      minrows           - The minimum number of rows 
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListNamesSet(
    char*	dialog,
    char*	list,
    int         n_names,
    char**	names);

/*
   Purpose:    Set the names on the items in a list component. The
		names are the internal identifiers for the buttons in a list.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      n_names           - The number of names
      names             - The array of names
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListSelectionpolicySet(
    char*                dialog,
    char*                list,
    ProUISelectionpolicy policy);

/*
   Purpose:    Set the selection policy for a list component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      policy            - The selection policy
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListVisiblerowsSet(
    char*	dialog,
    char*	list,
    int         visible_rows);

/*
   Purpose:    Set the number of visible rows in a list component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
      visible_rows      - The number of visible rows
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListActivateActionSet(
    char*	dialog,
    char*	list,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose: Sets the activate action for a list. This function is
                called when the return key is pressed or the mouse is 
		double-clicked in the list.

    Input Arguments:
      dialog            - The name of the dialog that contains the list.
      list              - The name of the list component
      action            - The action to perform when the list is activated.
      appdata           - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR   - The function was successful
        PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
        PRO_TK_GENERAL_ERROR - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIListEnable(
    char* dialog,
    char* list);
 
/*
   Purpose:    Makes the list enabled

   Input Arguments:
      dialog        - The name of the dialog that contains the list
      list          - The name of the list component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListDisable(
    char* dialog,
    char* list);
 
/*
   Purpose:    Make the list disabled

   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list          - The name of the list component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListSelectActionSet(
    char*	dialog,
    char*	list,
    ProUIAction	action,
    ProAppData	appdata);
 
/*
   Purpose:    Sets the select action for a list component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      list              - The name of the list component
      action            - The select action for the text area
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed


   <!-- Objectname: ProUI -->
*/
 
extern ProError ProUIListSelectednamesGet(
    char*	dialog,
    char*	list,
    int*        n_selections,
    char***     selections);

/*
   Purpose:    Gives the names of the currently selected items in a list

   Input Arguments:
      dialog            - The name of the dialog that contains the list
      list              - The name of the list component
 
   Output Arguments:
      n_selections      - The number of selections
      selections        - An array of strings containing the names of items
			  in the list currently selected. The memory for this
			  array is allocated by the function and should be
			  freed with ProStringarrayFree().
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIListSelectednamesSet(
    char*	dialog,
    char*	list,
    int         n_selections,
    char**	selections);

/*
   Purpose:    Sets the currently selected items in a list.

   Input Arguments:
      dialog            - The name of the dialog that contains the list.
      list              - The name of the list component.
      n_selections      - The number of selections.
                          <b>Note</b>: The list selection policy may prevent
                          selection of more than one item simultaneously.
      selections        - An array of strings containing the names of items
			  in the list that should be selected.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR        - The function was successful
      PRO_TK_BAD_INPUTS      - One or more of the arguments are invalid
      PRO_TK_GENERAL_ERROR   - The function failed

   See Also:
   ProUIListSelectionpolicySet()


   <!-- Objectname: ProUI -->
*/

extern ProError ProUIListIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the List is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the list
       component         - The name of the list component
                           
    Output Arguments:
        state            - Whether or not the list is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_BAD_INPUTS - One or more of the arguments are invalid
        PRO_TK_GENERAL_ERROR    - The function failed

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIListShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the list
       component         - The name of the list component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIListHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the list
       component         - The name of the list component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIListIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the List is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the list
       component         - The name of the list component
                          
    Output Arguments:
        state            - Whether or not the list is senstive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIListNamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose: Get an array of names on the items in a list component. The
	     names are the internal identifiers for the items in a list.

    Input Arguments:
       dialog            - The name of the dialog that contains the list
       component         - The name of the list component
                           
    Output Arguments:
        count            - number of items in returned array
        values           - Array of internal names allocated by the function.  
	                   Use ProStringarrayFree to release this.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIListLabelsGet (
    char       *dialog,
    char       *component,
    int        *count,
    wchar_t  ***values);
/*
    Purpose:    Get an array of names on the items in a list component.
        	The labels are the identifiers for the items in a list
		that are displayed on the dialog. 

    Input Arguments:
       dialog            - The name of the dialog that contains the list
       component         - The name of the list component
                           
    Output Arguments:
        count            - number of items in returned array
        values           - Array of internal names allocated by the function.  
	                   Use ProWstringarrayFree to release this.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIListTriggerhighlightActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the trigger highlight action for a list. This function is
                called when the user moves the mouse over an item on the list.

    Input Arguments:
      dialog            - The name of the dialog that contains the list.
      component         - The name of the list component
      callback          - The action to perform when the mouse moves on the item.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUIListLastentereditemGet()

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIListLastentereditemGet (char *dialog, 
					     char *component, 
					     char **value);

/*
    Purpose: Gets the name of the list item last pointed to by the mouse
             cursor.  This value is impportant when interpreting a
	     TriggerHighlight event.

    Input Arguments:
      dialog            - The name of the dialog that contains the list.
      component         - The name of the list component
   
    Output Arguments:
      value             - The name of the list item last pointed to by the 
                           cursor.  Free this string using ProStringFree.
                          

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIListFocusinActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the focus in action for a list. This function is
                called when the user moves the cursor onto of the list 
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the list.
      component         - The name of the list component
      callback          - The action to perform when the list gains user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIListFocusoutActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the focus out action for a list. This function is
                called when the user moves the cursor off of the list
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the list.
      component         - The name of the list component
      callback          - The action to perform when the list loses user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIListPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the list.

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


extern ProError ProUIListPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the list.

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





extern ProError ProUIListAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
     Purpose: Sets the position of the list with respect to a given anchor 
              location. This function is applicale  only if the parent of 
	      the list is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the list used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the list. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the list's minimum size, the function will fail.
              The list's minimum size can be retrieved
              using ProUIListMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains list.
        component - The name of the list component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the list with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the list with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the list in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the list. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListStateGet (char* dialog, char* component, char* item, ProUIMixedState* state);
/*
    Purpose: Get the state of the item in the list. The state is applicable 
             only for a "check" type of list and refers to the checked or 
             unchecked status of the item.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        item - The name of the item in the list.

    Output Arguments:
        state - State of the item. PROUI_SET if the item is checked.
		PROUI_UNSET if the item is checked. PROUI_MIXED
                if the item is in an indeterminate state.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListStateSet (char* dialog, char* component, char* item, ProUIMixedState state);
/*
    Purpose: Set the state of the item in the list.
	     The state is applicable only for a "check" type of list and 
             refers to the checked or unchecked status of the item.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        item - The name of the item in the list.
        state - State of the item. PROUI_SET if the item is to be checked.
		PROUI_UNSET if the item is to be unchecked. PROUI_MIXED
                if the item is to be in an indeterminate state.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIListParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the list component.

     Input Arguments:
         dialog - The name of the dialog that contains the list.
         component - The name of the list component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIListSelectionpolicyGet (char* dialog, char* component, ProUISelectionpolicy* value);
/*
    Purpose: Get the selection policy of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Selection policy.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over 
	     the list component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListItemhelptextGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the helptexts to the set of items in the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        count - Number of helptexts.
        values - Array of helptexts corresponding the items in the list. Free
	        this using ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListListtypeGet (char* dialog, char* component, ProUIListtype* value);
/*
    Purpose: Get the list type of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Type of the list.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListColumnlabelGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the label to the column in the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Label to the column in the list. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListColumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the width of the list in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Width of the column.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListMincolumnsSet (char* dialog, char* component, int value);
/*
    Purpose: Set the minimum width of the column in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        value - Minimum width of the column.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListMincolumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum width of the column in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Minimum width of the column.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListMinrowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum number of rows that can be in the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Minimum number of rows.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListVisiblerowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of rows that are visible.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Number of visible rows.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the list at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the list at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  list is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the list            
                is attached at left. PRO_B_FALSE if the list is not         
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the list at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the list at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  list is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the list           
                is attached at right. PRO_B_FALSE if the list is not       
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the list at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the list at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  list is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the list             
                is attached at top. PRO_B_FALSE if the list is not           
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the list at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the list at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  list is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the list          
                is attached at bottom. PRO_B_FALSE if the list is not     
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIListItemimageSet (
    char                   *dialog, 
    char                   *component, 
    int                     count, 
    char                  **values);
/*
    Purpose: Set the image names used for display of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
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


extern ProError ProUIListItemimageGet (
    char                   *dialog, 
    char                   *component, 
    int                    *count, 
    char                 ***values);
/*
    Purpose: Get the image names used for display of the list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.

    Output Arguments:
        count  - The number of items.
        values - The image names.  Free this using ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/
extern ProError ProUIListBackgroundcolorSet (
    char *dialog, 
    char *component, 
    ProUIColor value);
/*
    Purpose: Change the background color of list.

    Input Arguments:
        dialog - The name of the dialog that contains the list.
        component - The name of the list component.
	value - Background color value.
    Output Arguments:
	none
        
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
*/




PRO_END_C_DECLS
 
#endif  /* PROUILIST_H */
