#ifndef PROUIPUSHBUTTON_H
#define PROUIPUSHBUTTON_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIPushbuttonHelptextSet(
    char*	dialog,
    char*	pushbutton,
    wchar_t*    helptext);

/*
   Purpose:    Set the helptext of a pushbutton component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the pushbutton
      pushbutton        - The name of the pushbutton component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIPushbuttonActivateActionSet(
    char*	dialog,
    char*	pushbutton,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the activate action for a pushbutton. This function is
                called when the user selects the pushbutton.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the pushbutton
      pushbutton        - The name of the pushbutton component
      action            - The action to be called on activating the pushbutton
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIPushbuttonIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Pushbutton is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                           
    Output Arguments:
        state            - Whether or not the pushbutton is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Pushbutton is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                          
    Output Arguments:
        state            - Whether or not the pushbutton is enabled.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Pushbutton to be enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonDisable(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the Pushbutton to be disabled, so the user cannot
		select it.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the pushbutton
      component         - The name of the Pushbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonTextSet (
    char       *dialog,
    char       *component,
    wchar_t    *value);
/*
    Purpose: Sets the label on the pushbutton

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
       value             - The new label

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUIPushbuttonTextGet (
    char       *dialog,
    char       *component,
    wchar_t   **value);
/*
    Purpose: Gives the label of the pushbutton

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component

    Output Arguments:
       value             - The new label, allocated by the function.  Use 
                           ProWstringFree to release this string.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUIPushbuttonPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the pushbutton.

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


extern ProError ProUIPushbuttonPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the pushbutton.

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




extern ProError ProUIPushbuttonAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
  Purpose: Sets the position of the pushbutton with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the pushbutton is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the pushbutton used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the pushbutton. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the pushbutton's minimum size, the function will fail.
              The pushbutton's minimum size can be retrieved
              using ProUIPushbuttonMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains pushbutton.
        component - The name of the pushbutton component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the pushbutton with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains pushbutton.
        component - The name of the pushbutton component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the pushbutton with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the pushbutton in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the pushbutton. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIPushbuttonParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the pushbutton component.

     Input Arguments:
         dialog - The name of the dialog that contains the pushbutton.
         component - The name of the pushbutton component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIPushbuttonHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonBitmapSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the bitmap to the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonBitmapGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the bitmap of the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        value - The name of the bitmap. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the pushbutton at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the pushbutton at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  pushbutton is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the pushbutton      
                is attached at left. PRO_B_FALSE if the pushbutton is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the pushbutton at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the pushbutton at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  pushbutton is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the pushbutton     
                is attached at right. PRO_B_FALSE if the pushbutton is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the pushbutton at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the pushbutton at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  pushbutton is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the pushbutton       
                is attached at top. PRO_B_FALSE if the pushbutton is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the pushbutton at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the pushbutton at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  pushbutton is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the pushbutton    
                is attached at bottom. PRO_B_FALSE if the pushbutton is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the pushbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the pushbutton.
        component - The name of the pushbutton component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIPushbuttonIsResizeable (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the pushbutton is resizeable or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                          
    Output Arguments:
        state            - Whether or not the pushbutton is resizeable.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonEnableResizing (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the pushbutton to be resizeable.

    Input Arguments:
       dialog            - The name of the dialog that contains the pushbutton
       component         - The name of the pushbutton component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonDisableResizing(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the pushbutton to be non-resizeable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the pushbutton.
      component         - The name of the pushbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIPushbuttonButtonstyleSet (
    char                   *dialog, 
    char                   *component, 
    ProUIButtonStyle        value);
/*
   Purpose:    Sets the pushbutton button style.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the pushbutton.
      component         - The name of the pushbutton component
      value             - The button style to use.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIPushbuttonButtonstyleGet (
    char                   *dialog, 
    char                   *component, 
    ProUIButtonStyle       *value);
/*
   Purpose:    Gets the pushbutton button style.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the pushbutton.
      component         - The name of the pushbutton component  
 
   Output Arguments:
      value             - The button style to use.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/



PRO_END_C_DECLS
 
#endif  /* PROUIPUSHBUTTON_H */
