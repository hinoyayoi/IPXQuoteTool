#ifndef PROUITAB_H
#define PROUITAB_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUITabHelptextSet(
    char*	dialog,
    char*	tab,
    wchar_t*    helptext);

/*
   Purpose:    Set the helptext of a tab component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the tab
      tab               - The name of the tab component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed


   <!-- Objectname: ProUI -->

*/

extern ProError ProUITabItemhelptextSet(
    char*	dialog,
    char*	tab,
    int         n_items,
    wchar_t**	itemhelptext);

/*
   Purpose:    Set the item help text for the tab
 
   Input Arguments:
      dialog            - The name of the dialog that contains the tab
      tab               - The name of the tab component
      itemhelptext      - An array of item help texts
      n_items           - The number in the array
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUITabSelectActionSet(
    char*	dialog,
    char*	tab,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the select action for a tab. This function is
                called when the user selects the tab.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the tab
      tab               - The name of the tab component
      action            - The action to be called on selecting the tab
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUITabIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Tab is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the tab
       component         - The name of the tab component
                           
    Output Arguments:
       state             - Whether or not the tab is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITabShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the tab
       component         - The name of the tab component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITabHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the tab
       component         - The name of the tab component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITabIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Tab is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the tab
       component         - The name of the tab component
                          
    Output Arguments:
       state             - Whether or not the tab is sensitive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITabEnable (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the Tab to be enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the tab
       component         - The name of the tab component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITabDisable(
    char* dialog,
    char* Tab);
/*
   Purpose:    Sets the Tab to be disabled, so the user cannot
		select it.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the tab
      Tab         - The name of the tab component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUITabLabelsSet (
    char       *dialog,
    char       *component,
    int         count,
    wchar_t   **values);

/*
    Purpose:  Sets the labels assigned to the Tab component.  This is the
              set of labels shown in the tab panes.

    Input Arguments:
        dialog -           The name of the dialog.
        component -        The tab component.
	count -            Number of items in the value array.
        values -            Array of label names to use on the tab component.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->	
*/


extern ProError ProUITabLabelsGet (
    char       *dialog,
    char       *component,
    int        *count,
    wchar_t  ***values);

/*
    Purpose:  Gets the labels assigned to the Tab component.  This is the
              set of labels shown in the tab panes.

    Input Arguments:
        dialog -           The name of the dialog.
        component -        The tab component.

    Output Arguments:
        count -            Number of items in the value array.
        values -            Array of label names used on the tab component.
                           Free this argument using ProWstringarrayFree().     

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUITabSelectednamesSet (
    char       *dialog,
    char       *component,
    int         count,
    char      **values);
/*
    Purpose:  Sets the selected layout in the Tab component.  This is the
              layout shown in the tab pane.

    Input Arguments:
        dialog -           The name of the dialog.
        component -        The tab component.
        count -            Number of items in the values array.
        values -           Array of layouts selected (shown) on the tab 
	                   component (should contain only 1).	

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUITabSelectednamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose:  Gets the selected layout in the Tab component.  This is the
              layout that is shown in the Tab.

    Input Arguments:
        dialog -           The name of the dialog.
        component -        The tab component.

    Output Arguments:
        count -            Number of items in the values array.
        values -           Array of layouts selected on the tab component 
	                   (typically 1).  Free this argument using 
			   ProStringarrayFree().     

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUITabPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the tab.

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


extern ProError ProUITabPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the tab.

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




extern ProError ProUITabAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the tab with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the tab is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the tab used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the tab. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the tab's minimum size, the function will fail.
              The tab's minimum size can be retrieved
              using ProUITabMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the tab with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the tab with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the tab in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the tab. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabLayoutAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new layout to the tab. Even if the layout has a label 
             assigned, you must set the tab labels with ProUITabLabelsSet() 
	     for the decorated tab to show the appropriate labels.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        name - The name of the layout to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabLayoutsInsert (char* dialog, char* component, char* item, int count, char** names);
/*
    Purpose: Insert a new layout after an existing component in the tab.  Even
             if the layouts have labels assigned, you must set the tab labels 
             with ProUITabLabelsSet() for the decorated tab to show the 
             appropriate labels.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the component after which the layouts to be 
               inserted.
        count - Number of layouts to be added.
        names - Array of names of the layouts.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemNameSet (char* dialog, char* component, char* item, char* name);
/*
    Purpose: Set a new name to the item in the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the tab item.
        name - New name of the item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemLabelSet (char* dialog, char* component, char* item, wchar_t* label);
/*
    Purpose: Set the label of the item in the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The nameof the item.
        label - The label of the item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemImageSet (char* dialog, char* component, char* item, char* image);
/*
    Purpose: Set the image of the item in the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the item.
        image - The name of the image.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemHelptextStringSet (char* dialog, char* component, char* item, wchar_t* help_text);
/*
    Purpose: Set the text that should be displayed when the cursor is over the 
             item in the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the item.
        help_text - The help-text that should display.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUITabItemLabelGet (char* dialog, char* component, char* item, wchar_t** label);
/*
    Purpose: Get the label of the item in the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the item.

    Output Arguments:
        label - The label of the item. Free this using ProWstringFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemImageGet (char* dialog, char* component, char* item, char** image);
/*
    Purpose: Get the image of the item in the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the item.

    Output Arguments:
        image - The name of the image. Free this using ProStringFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemHelptextStringGet (char* dialog, char* component, char* item, wchar_t** help_text);
/*
    Purpose: Get the text that is displayed when the cursor is over the item in 
             the tab.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the item.

    Output Arguments:
        help_text - The help-text that is displayed. Free this using ProWstringFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemExtentsGet (char* dialog, char* component, char* item, ProUIRectangle* extent);
/*
    Purpose: Get the boundary of the item that is in the tab relative to the 
             top left corner of the dialog.

    Input Arguments:
        dialog - The name of the dialog that contains tab.
        component - The name of the tab component.
        item - The name of the item.

    Output Arguments:
        extent - Rectangle of the item.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITabParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the tab component.

     Input Arguments:
         dialog - The name of the dialog that contains the tab.
         component - The name of the tab component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUITabHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the tab component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabItemhelptextGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the helptexts of the items contained in the tab that
	    will display when the cursor is over the item.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        count - Number of helptexts.	
        values - Array of helptexts corresponding to each item in the tab.
		Free this using ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabDecorate (char* dialog, char* component);
/*
    Purpose: Set the decorated shadow border to the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
	none.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabUndecorate (char* dialog, char* component);
/*
    Purpose: To not set the decorated shadow border to the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUITabIsDecorated (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the tab has decorated border or not.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        state - PRO_B_TRUE when the tab has decorated border.
		PRO_B_TRUE when the tab has not decorated border.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the tab at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the tab at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  tab is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the tab             
                is attached at left. PRO_B_FALSE if the tab is not           
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the tab at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the tab at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  tab is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the tab            
                is attached at right. PRO_B_FALSE if the tab is not         
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the tab at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the tab at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  tab is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the tab              
                is attached at top. PRO_B_FALSE if the tab is not             
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the tab at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the tab at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  tab is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the tab           
                is attached at bottom. PRO_B_FALSE if the tab is not       
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITabBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the tab.

    Input Arguments:
        dialog - The name of the dialog that contains the tab.
        component - The name of the tab component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




PRO_END_C_DECLS
 
#endif  /* PROUITAB_H */
