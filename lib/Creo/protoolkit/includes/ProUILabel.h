#ifndef PROUILABEL_H
#define PROUILABEL_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUILabelHelptextSet(
    char*	dialog,
    char*	label,
    wchar_t*	helptext);

/*
   Purpose:    Set the helptext of a label component
 
   Input Arguments:
      dialog            - The name of the dialog thet contains the label
      label             - The name of the label component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUILabelTextSet(
    char*	dialog,
    char*	label_component,
    wchar_t*	label);

/*
   Purpose:    Set the label of a label component
 
   Input Arguments:
      dialog            - The name of the dialog thet contains the label
      label_component   - The name of the label component
      label             - The label of the label component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUILabelIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Label is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog thet contains the label
       component         - The name of the label component
                          
    Output Arguments:
       state             - Whether or not the label is enabled.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUILabelEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Label to be enabled.

    Input Arguments:
       dialog            - The name of the dialog thet contains the label
       component         - The name of the label component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUILabelDisable(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the Label to be disabled, so the user cannot
		select it.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the Label
      component         - The name of the Label component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUILabelShow (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Makes the label visible.

    Input Arguments:
       dialog            - The name of the dialog thet contains the label
       component         - The name of the label component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/


extern ProError ProUILabelHide (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Makes the label invisible.

    Input Arguments:
       dialog            - The name of the dialog thet contains the label
       component         - The name of the label component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/


extern ProError ProUILabelIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose:  Returns the label visibility.

    Input Arguments:
       dialog            - The name of the dialog thet contains the label
       component         - The name of the label component
                          
    Output Arguments:
       state             - PRO_B_TRUE if the label is visible, PRO_B_FALSE if not.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/


extern ProError ProUILabelPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the label.

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


extern ProError ProUILabelPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the label.

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





extern ProError ProUILabelAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
     Purpose: Set the location to position the label with respect
              to its parent. This field is used only if the parent is a
              drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains label.
        component - The name of the label component.
        x - X value
        y - Y value
        anchor - Portion of the label.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the label. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the label's minimum size, the function will fail.
              The label's minimum size can be retrieved
              using ProUILabelMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains label.
        component - The name of the label component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the label with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains label.
        component - The name of the label component.
        x - X value
        y - Y value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the label with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains label.
        component - The name of the label component.

    Output Arguments:
        x - X value
        y - Y value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the label in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the label. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains label.
        component - The name of the label component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUILabelParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the label component.

     Input Arguments:
         dialog - The name of the dialog that contains the label.
         component - The name of the label component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUILabelHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over 
	     the label component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelTextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the text that is displayed in the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - Text displayed in the label. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelBitmapSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the bitmap to the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelBitmapGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the bitmap of the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - The name of the bitmap. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelColumnsSet (char* dialog, char* component, int value);
/*
    Purpose: Set the width of the label in character widths. A value of 0
	will size itself based upon its contents.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.
        value - Width of the label.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelColumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the width of the label in character widths. 

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - Width of the label.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the label at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the label at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  label is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the label           
                is attached at left. PRO_B_FALSE if the label is not
	        attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the label at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the label at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  label is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the label          
                is attached at right. PRO_B_FALSE if the label is not
	        attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the label at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the label at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  label is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the label            
                is attached at top. PRO_B_FALSE if the label is not
		attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the label at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the label at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  label is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the label         
                is attached at bottom. PRO_B_FALSE if the label is not
		attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILabelBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the label.

    Input Arguments:
        dialog - The name of the dialog that contains the label.
        component - The name of the label component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUILabelIsResizeable (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the label is resizeable or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the label
       component         - The name of the label component
                          
    Output Arguments:
        state            - Whether or not the label is resizeable.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUILabelEnableResizing (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the label to be resizeable.

    Input Arguments:
       dialog            - The name of the dialog that contains the label
       component         - The name of the label component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUILabelDisableResizing(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the label to be non-resizeable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the label.
      component         - The name of the label component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/



PRO_END_C_DECLS
 
#endif  /* PROUILABEL_H */
