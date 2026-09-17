#ifndef PROUITEXTAREA_H
#define PROUITEXTAREA_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUITextareaHelptextSet(
    char*	dialog,
    char*	textarea,
    wchar_t*     helptext);

/*
   Purpose:    Set the helptext of a text area component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaColumnsSet(
    char*	dialog,
    char*	textarea,
    int         columns);
/*
   Purpose:    Set the number of columns in a text area component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
      columns           - The number of columns
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/
 
extern ProError ProUITextareaEditable(
    char*	dialog,
    char*	textarea);
/*
   Purpose:    Set a text area to be editable
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaReadOnly(
    char*	dialog,
    char*	textarea);
/*
   Purpose:    Set a text area to be readonly
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaMaxlenSet(
    char*	dialog,
    char*	textarea,
    int         maxlen);

/*
   Purpose:    Set the maximum length of a text area.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
      maxlen            - The maximum length of the text area
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaMinrowsSet(
    char*	dialog,
    char*	textarea,
    int         minrows);

/*
   Purpose:    Set the minimum number of rows for a text area
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
      minrows           - The minimum number of rows 
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaRowsSet(
    char*	dialog,
    char*	textarea,
    int         rows);

/*
   Purpose:    Set the number of rows for a text area
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
      rows              - The number of rows 
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaValueSet(
    char*	dialog,
    char*	textarea,
    wchar_t*    value);
 
/*
   Purpose:    Sets the value of the text in the text area
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
      value		- A wide string containing the text, lines separated
				by (wchar_t)'\n'.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaValueGet(
    char*	dialog,
    char*	textarea,
    wchar_t**   lines);
 
/*
   Purpose:    Gets the value of the text in the text area
 
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
 
   Output Arguments:
      lines             - Wide string containing the text, lines separated
			  by (wchar_t)'\n'. The memory for this wide string
			  is allocated by the function and should be freed
			  with ProWstringFree().
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaActivateActionSet(
    char*	dialog,
    char*	textarea,
    ProUIAction action,
    ProAppData  appdata);

/*
    Purpose: Sets the activate action for a text area. This function is
                called when the user presses return in the text area.

    Input Arguments:
      dialog            - The name of the dialog that contains the text area.
      textarea          - The name of the text area component
      action            - The action to perform when the text area is activated.
      appdata           - Application data to be passed to callback function
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUITextareaEnable(
    char* dialog,
    char* textarea);
 
/*
   Purpose:    Enables the text area
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaDisable(
    char* dialog,
    char* textarea);
/*
   Purpose:    Disables the text area
   Input Arguments:
      dialog            - The name of the dialog that contains the text area
      textarea          - The name of the text area component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUITextareaInputActionSet(
    char*	dialog,
    char*	textarea,
    ProUIAction action,
    ProAppData  appdata);
 
/*
    Purpose: Sets the activate action for a text area. This function is
                called when the user changes the conents of the text area.

    Input Arguments:
      dialog            - The name of the dialog that contains the text area.
      textarea          - The name of the text area component
      action            - The action to perform when the text area contents are changed.
      appdata           - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUITextareaIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Textarea is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the text area.
       component         - The name of the text area component 
                           
    Output Arguments:
        state            - Whether or not the text area is visible

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITextareaShow (
    char   *dialog,
    char   *component
);
/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the text area.
       component         - The name of the text area component

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITextareaHide (
    char   *dialog,
    char   *component
);
/*
    Purpose: Hides the component from the dialog

    Input Arguments:
        dialog         -   name of dialog
        component      -   name of component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUITextareaFocusinActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the focus in action for a text area. This function is
                called when the user moves the cursor onto the text area
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the text area.
      component         - The name of the text area component
      callback          - The action to perform when the text area gains user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUITextareaFocusoutActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);
/*
    Purpose: Sets the focus out action for a text area. This function is
                called when the user moves the cursor off of the text area
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the text area.
      component         - The name of the text area component
      callback          - The action to perform when the text area loses user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUITextareaPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the textarea.

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


extern ProError ProUITextareaPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the textarea.

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

 



extern ProError ProUITextareaAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the textarea with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the textarea is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the textarea used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the textarea. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the textarea's minimum size, the function will fail.
              The textarea's minimum size can be retrieved
              using ProUITextareaMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains textarea.
        component - The name of the textarea component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the textarea with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains textarea.
        component - The name of the textarea component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the textarea with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains textarea.
        component - The name of the textarea component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the textarea in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the textarea. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains textarea.
        component - The name of the textarea component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITextareaParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the textarea component.

     Input Arguments:
         dialog - The name of the dialog that contains the textarea.
         component - The name of the textarea component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUITextareaHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaIsEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the textarea is sensitive to the user input or not.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        state - PRO_B_TRUE when the textarea is sensitive.
		PRO_B_FALSE when the textarea is insensitive.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the textarea at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the textarea at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  textarea is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the textarea        
                is attached at left. PRO_B_FALSE if the textarea is not 
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the textarea at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the textarea at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  textarea is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the textarea       
                is attached at right. PRO_B_FALSE if the textarea is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the textarea at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the textarea at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  textarea is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the textarea         
                is attached at top. PRO_B_FALSE if the textarea is not   
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the textarea at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the textarea at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  textarea is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the textarea      
                is attached at bottom. PRO_B_FALSE if the textarea is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITextareaColumnsGet (
    char                   *dialog,
    char                   *component,
    int                    *value);
/*
    Purpose: Get width of the textarea in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Column width of the textarea.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError ProUITextareaIsEditable (
    char           *dialog,    
    char           *component,
    ProBoolean     *state
);

/*
    Purpose: Get editable state of textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        state - PRO_B_TRUE when the textarea is editable.
		PRO_B_FALSE when the textarea is not editable.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


 
extern ProError ProUITextareaMinrowsGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get minimum number of rows of the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Minimum number of rows of the textarea.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

 
extern ProError ProUITextareaMaxlenGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get maximum length of the text contents in textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Maximum length of the text contents.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITextareaRowsGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get number of rows of the textarea.

    Input Arguments:
        dialog - The name of the dialog that contains the textarea.
        component - The name of the textarea component.

    Output Arguments:
        value - Number of rows in textarea.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


PRO_END_C_DECLS
 
#endif  /* PROUITEXTAREA_H */
