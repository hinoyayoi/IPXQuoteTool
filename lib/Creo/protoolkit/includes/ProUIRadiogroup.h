#ifndef PROUIRADIOGROUP_H
#define PROUIRADIOGROUP_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIRadiogroupHelptextSet(
    char*	dialog,
    char*	radiogroup,
    wchar_t*    helptext);

/*
   Purpose:    Set the helptext of a radio group component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupItemhelptextSet(
    char*	dialog,
    char*	radiogroup,
    int         n_items,
    wchar_t**   help_lines );

/*
   Purpose:    Set the help text of the buttons in a radio group component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
      n_items           - The number in the array of help lines
      help_lines        - An array of helptext lines, one for each button
				in the radio group
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupLabelsSet(
    char*	dialog,
    char*	radiogroup,
    int         n_labels,
    wchar_t**   labels);

/*
   Purpose:    Set the labels on the buttons in a radio group component.
		The labels are the identifiers for the button in a radio
		group that are displayed on the dialog. Before defining
		the labels, you must specify the internal names using
		ProUIRadiogroupNamesSet().
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
      n_labels          - The number in the array of labels
      labels            - An array of labels, one for each button in the radio group
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupNamesSet(
    char*	dialog,
    char*	radiogroup,
    int         n_names,
    char**	names);

/*
   Purpose:    Set the names on the buttons in a radio group component. The
		names are the internal identifiers for the buttons in a radio
		group.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
      n_names           - The number in the array of names
      names             - An array of names, one for each button in the radio group
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupSelectActionSet(
    char*	dialog,
    char*	radiogroup,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the select action for a radio group. This function is
                called when the user selects one of the buttons in the
		radio group.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
      action            - The action to be called on selecting a button
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupSelectednamesGet(
    char*   dialog,
    char*   radiogroup,
    int*    n_name,
    char*** names);
 
/*
   Purpose:    Reports the name of the currently selected button in a
	       radio group.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
 
   Output Arguments:
      n_name		- The number of names
      names		- The array of names. The memory for this array is
			  allocated by the function and should be freed with
			  ProStringarrayFree().
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupSelectednamesSet(
    char*  dialog,
    char*  radiogroup,
    int    n_names,
    char** names);
 
/*
   Purpose:    Selects a specified button in a radio group
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      radiogroup        - The name of the radio group component
      n_names		- The number of names
      names		- The array of names
 
   Output Arguments:
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIRadiogroupIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Radiogroup is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component
                           
    Output Arguments:
        state            - Whether or not the radiogroup is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Radiogroup is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component
                          
    Output Arguments:
       state             - Whether or not the radiogroup is enabled.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Radiogroup to be enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupDisable(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the Radiogroup to be disabled, so the user cannot
		select it.
 
   Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupNamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose: Get an array of names on the items in a Radiogroup component.
             The names are the internal identifiers for the buttons in a list.

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component

    Output Arguments:
        count            - Number of items in returned array
        values            - Array of names, allocated by the function.  Use 
	                   ProStringarrayFree() to release it.
                           
    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUIRadiogroupLabelsGet (
    char       *dialog,
    char       *component,
    int        *count,
    wchar_t  ***values);
/*
    Purpose: Get the array of labels on the buttons in a Radiogroup
             component. The labels are the identifiers for the items in a 
	     radiogroup that are displayed on the dialog. 

    Input Arguments:
       dialog            - The name of the dialog that contains the radio group
       component         - The name of the radio group component
                           
    Output Arguments:
        count            - number of items in returned array
        values            - Array of labels, allocated by the function.  Use 
	                   ProWstringarrayFree() to release it.
                           
    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUIRadiogroupPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the radiogroup.

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


extern ProError ProUIRadiogroupPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the radiogroup.

    Input Arguments:
        dialog             - The dialog name.
        component          - The component name.
        

    Output Arguments:
        value              - The name of the popup menu pane. Free this string
	                      using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/




extern ProError ProUIRadiogroupAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the radiogroup with respect to a given 
              anchor location. This function is applicable  only if the parent 
              of the radiogroup is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the radiogroup used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the radiogroup. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the radiogroup's minimum size, the function will fail.
              The radiogroup's minimum size can be retrieved
              using ProUIRadiogroupMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains radiogroup.
        component - The name of the radiogroup component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the radiogroup with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains radiogroup.
        component - The name of the radiogroup component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the radiogroup with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the radiogroup in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the radiogroup. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIRadiogroupParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the radiogroup component.

     Input Arguments:
         dialog - The name of the dialog that contains the radiogroup.
         component - The name of the radiogroup component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIRadiogroupHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the radiogroup at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the radiogroup at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  radiogroup is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the radiogroup      
                is attached at left. PRO_B_FALSE if the radiogroup is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the radiogroup at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the radiogroup at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  radiogroup is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the radiogroup     
                is attached at right. PRO_B_FALSE if the radiogroup is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the radiogroup at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the radiogroup at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  radiogroup is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the radiogroup       
                is attached at top. PRO_B_FALSE if the radiogroup is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the radiogroup at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the radiogroup at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  radiogroup is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the radiogroup    
                is attached at bottom. PRO_B_FALSE if the radiogroup is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIRadiogroupBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIRadiogroupIsResizeable (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the radiogroup is resizeable or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the radiogroup
       component         - The name of the radiogroup component
                          
    Output Arguments:
        state            - Whether or not the radiogroup is resizeable.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupEnableResizing (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the radiogroup to be resizeable.

    Input Arguments:
       dialog            - The name of the dialog that contains the radiogroup
       component         - The name of the radiogroup component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupDisableResizing(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the radiogroup to be non-resizeable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radiogroup.
      component         - The name of the radiogroup component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupButtonstyleSet (
    char                   *dialog, 
    char                   *component, 
    ProUIButtonStyle        value);
/*
   Purpose:    Sets the radiogroup button style.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radiogroup.
      component         - The name of the radiogroup component
      value             - The button style to use.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIRadiogroupButtonstyleGet (
    char                   *dialog, 
    char                   *component, 
    ProUIButtonStyle       *value);
/*
   Purpose:    Gets the radiogroup button style.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radiogroup.
      component         - The name of the radiogroup component  
 
   Output Arguments:
      value             - The button style to use.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupOrientationSet (
    char                   *dialog, 
    char                   *component, 
    ProUIOrientation        value);
/*
   Purpose:    Sets the radiogroup orientation.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radiogroup.
      component         - The name of the radiogroup component  
      value             - The orientation to use.
 
 
   Output Arguments:
      none
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIRadiogroupOrientationGet (
    char                   *dialog, 
    char                   *component, 
    ProUIOrientation       *value);
/*
   Purpose:    Gets the radiogroup orientation.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radiogroup.
      component         - The name of the radiogroup component  
 
   Output Arguments:
      value             - The orientation to use.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIRadiogroupItemimageSet (
    char                   *dialog, 
    char                   *component, 
    int                     count, 
    char                  **values);
/*
    Purpose: Set the image names used for display of the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.
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


extern ProError ProUIRadiogroupItemimageGet (
    char                   *dialog, 
    char                   *component, 
    int                    *count, 
    char                 ***values);
/*
    Purpose: Get the image names used for display of the radiogroup.

    Input Arguments:
        dialog - The name of the dialog that contains the radiogroup.
        component - The name of the radiogroup component.

    Output Arguments:
        count  - The number of items.
        values - The image names.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUIRadiogroupItemhelptextGet (
    char                   *dialog, 
    char                   *component, 
    int                    *count, 
    wchar_t              ***values);

/*    
   Purpose:    Returns the help text associated with the items in a
	       radio group.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the radio group
      component         - The name of the radio group component
 
   Output Arguments:
      count             - The number of items.
      values            - The help text. The memory for this array is
			  allocated by the function and should be freed with
			  ProWstringarrayFree().

 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


PRO_END_C_DECLS
 
#endif  /* PROUIRADIOGROUP_H */
