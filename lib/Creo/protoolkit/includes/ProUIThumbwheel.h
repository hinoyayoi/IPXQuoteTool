#ifndef PROUITHUMBWHEEL_H
#define PROUITHUMBWHEEL_H

#include <ProUI.h>



/*===========================================================================*/

PRO_BEGIN_C_DECLS

extern ProError ProUIThumbwheelHelptextSet(
    char*       dialog,
    char*       thumbwheel,
    wchar_t*     helptext);

/*
   Purpose:    Set the helptext of a thumbwheel component

   Input Arguments:
      dialog            - The name of the dialog that contains the thumbwheel
      thumbwheel        - The name of the thumbwheel component
      helptext          - The help text

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIThumbwheelIntegerSet (
    char       *dialog,
    char       *thumbwheel,
    int         value);

/*
   Purpose:    Sets the value of a thumbwheel

   Input Arguments:
      dialog		- The name of the dialog that contains the thumbwheel
      thumbwheel	- The name of the thumbwheel component
      value		- The integer value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIThumbwheelIntegerGet (
    char       *dialog,
    char       *thumbwheel,
    int        *value);

/*
   Purpose:    Gets the value of a thumbwheel

   Input Arguments:
      dialog		- The name of the dialog that contains the thumbwheel
      thumbwheel	- The name of the thumbwheel component

   Output Arguments:
      value	        - The integer value

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIThumbwheelMinintegerSet (
    char       *dialog,
    char       *thumbwheel,
    int         value);

/*
   Purpose:    Sets the minimum value of the integer for the thumbwheel

   Input Arguments:
      dialog            - The name of the dialog that contains the thumbwheel
      thumbwheel        - The name of the thumbwheel component
      value             - The minimum integer value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIThumbwheelMaxintegerSet (
    char       *dialog,
    char       *thumbwheel,
    int         value);

/*
   Purpose:    Sets the maximum value of the integer for the thumbwheel

   Input Arguments:
      dialog            - The name of the dialog that contains the thumbwheel
      thumbwheel        - The name of the thumbwheel component
      value             - The maximum integer value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIThumbwheelUnitsperrotationSet (
    char       *dialog,
    char       *thumbwheel,
    int         value);

/*
   Purpose:    Sets the value by which the integer changes per
		revolution of the thumbwheel

   Input Arguments:
      dialog            - The name of the dialog that contains the thumbwheel
      thumbwheel        - The name of the thumbwheel component
      value             - The increment value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIThumbwheelUpdateActionSet (
    char         *dialog,
    char         *thumbwheel,
    ProUIAction  callback,
    ProAppData   data);

/*
   Purpose:    Sets the update action for a thumbwheel

   Input Arguments:
      dialog            - The name of the dialog that contains the thumbwheel
      thumbwheel        - The name of the thumbwheel component
      callback          - The update action for the thumbwheel
      data              - User data to be passed to the action function.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIThumbwheelIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Thumbwheel is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the thumbwheel
       component         - The name of the thumbwheel component
                           
    Output Arguments:
        state            - Whether or not the thumbwheel is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIThumbwheelShow (
    char   *dialog,
    char   *component
);
/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the thumbwheel
       component         - The name of the thumbwheel component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIThumbwheelHide (
    char   *dialog,
    char   *component
);
/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the thumbwheel
       component         - The name of the thumbwheel component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIThumbwheelIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Thumbwheel is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the thumbwheel
       component         - The name of the thumbwheel component
                          
    Output Arguments:
        state            - Whether or not the thumbwheel is sensitive to user input

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIThumbwheelEnable (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the Thumbwheel to be enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the thumbwheel
       component         - The name of the thumbwheel component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIThumbwheelDisable(
    char* dialog,
    char* Thumbwheel);
/*
   Purpose:    Sets the Thumbwheel to be disabled, so the user cannot
		select it.
 
   Input Arguments:
       dialog            - The name of the dialog that contains the thumbwheel
       Thumbwheel        - The name of the thumbwheel component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIThumbwheelPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the thumbwheel.

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


extern ProError ProUIThumbwheelPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the thumbwheel.

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




extern ProError ProUIThumbwheelAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the thumb wheel with respect to a given 
              anchor location. This function is applicable  only if the parent 
              of the thumb wheel is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the thumb wheel.
        component - The name of the thumb wheel component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the thumb wheel used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the thumbwheel. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the thumbwheel's minimum size, the function will fail.
              The thumbwheel's minimum size can be retrieved
              using ProUIThumbwheelMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains thumbwheel.
        component - The name of the thumbwheel component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the thumbwheel with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains thumbwheel.
        component - The name of the thumbwheel component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the thumbwheel with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the thumbwheel in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the thumbwheel. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIThumbwheelParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the thumbwheel component.

     Input Arguments:
         dialog - The name of the dialog that contains the thumbwheel.
         component - The name of the thumbwheel component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIThumbwheelHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: To get the helptext that will display when the cursor is
	     above the thumwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the thumbwheel at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the thumbwheel at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  thumbwheel is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the thumbwheel      
                is attached at left. PRO_B_FALSE if the thumbwheel is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the thumbwheel at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the thumbwheel at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  thumbwheel is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the thumbwheel     
                is attached at right. PRO_B_FALSE if the thumbwheel is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the thumbwheel at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the thumbwheel at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  thumbwheel is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the thumbwheel       
                is attached at top. PRO_B_FALSE if the thumbwheel is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the thumbwheel at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the thumbwheel at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  thumbwheel is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the thumbwheel    
                is attached at bottom. PRO_B_FALSE if the thumbwheel is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIThumbwheelMinintegerGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get minimum integer value of the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Minimum integer value of the thumbwheel.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError ProUIThumbwheelMaxintegerGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get maximum integer value of the thumbwheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Maximum integer value of the thumbwheel.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIThumbwheelUnitsperrotationGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get value of the thumbwheel that should be incremented for each complete rotation of the wheel.

    Input Arguments:
        dialog - The name of the dialog that contains the thumbwheel.
        component - The name of the thumbwheel component.

    Output Arguments:
        value - Increment value for one rotation of the wheel.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


PRO_END_C_DECLS

#endif  /* PROUITHUMBWHEEL_H */
