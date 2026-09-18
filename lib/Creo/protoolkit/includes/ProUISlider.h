#ifndef PROUISLIDER_H
#define PROUISLIDER_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUISliderHelptextSet(
    char*	dialog,
    char*	slider,
    wchar_t*    helptext);

/*
   Purpose:    Set the helptext of a slider component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISliderLengthSet(
    char*	dialog,
    char*	slider,
    int         length);
/*
   Purpose:    Set the length of a slider component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
      length            - The length of the slider component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUISliderMinintegerSet(
    char*	dialog,
    char*	slider,
    int         min);
/*
   Purpose:    Set the minimum integer for a slider component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
      min               - The minimum integer value (default = -32768)
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUISliderMaxintegerSet(
    char*	dialog,
    char*	slider,
    int         max);
/*
   Purpose:    Sets the maximum integer for a slider component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
      max               - The minimum integer value (default = -32768)
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
                     
   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUISliderDisableTracking(
    char*	dialog,
    char*	slider);

/*
   Purpose:    Disables tracking for a slider component. If the slider is
		tracking the update action is called for each change in
                position.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUISliderEnableTracking(
    char*	dialog,
    char*	slider);

/*
   Purpose:    Enables tracking for a slider component. If the slider is
		tracking the update action is called for each change in
                position.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderUpdateActionSet(
    char*	dialog,
    char*	slider,
    ProUIAction action,
    ProAppData appdata);
 
/*
   Purpose:    Sets the update action for a slider. 
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
      action            - The action to be called on selecting the slider
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISliderIntegerGet(
    char*	dialog,
    char*	slider,
    int         *position);

/*
   Purpose:    Gets the current position of the slider
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
 
   Output Arguments:
      position          - The current position of the slider
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUISliderIntegerSet(
    char*	dialog,
    char*	slider,
    int         position);
 
/*
   Purpose:    Sets the current position of the slider
 
   Input Arguments:
      dialog            - The name of the dialog that contains the slider
      slider            - The name of the slider component
      position          - The current position of the slider
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISliderIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);

/*
    Purpose: Checks to see if the Slider is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the slider
       component         - The name of the slider component
                           
    Output Arguments:
       state             - Whether or not the slider is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the slider
       component         - The name of the slider component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the slider
       component         - The name of the slider component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Slider is enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the slider
       component         - The name of the slider component
                          
    Output Arguments:
        state            - Whether or not the slider is sensitive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Slider to be enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the slider
       component         - The name of the slider component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderDisable(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the slider to be disabled, so the user cannot
		select it.
 
   Input Arguments:
       dialog            - The name of the dialog that contains the slider
       component         - The name of the slider component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUISliderPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the slider.

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


extern ProError ProUISliderPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the slider.

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




extern ProError ProUISliderAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
 Purpose: Sets the position of the slider with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the slider is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the slider used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the slider. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the slider's minimum size, the function will fail.
              The slider's minimum size can be retrieved
              using ProUISliderMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains slider.
        component - The name of the slider component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the slider with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains slider.
        component - The name of the slider component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the slider with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains slider.
        component - The name of the slider component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the slider in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the slider. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains slider.
        component - The name of the slider component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUISliderParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the slider component.

     Input Arguments:
         dialog - The name of the dialog that contains the slider.
         component - The name of the slider component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUISliderHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over the
	     slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderMinintegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum integer value of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Minimum integer value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderMaxintegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the maximum integer value of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Maximum integer value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderOrientationSet (char* dialog, char* component, ProUIOrientation value);
/*
    Purpose: Set the orientation of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.
        value - Orientation of the slider.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderOrientationGet (char* dialog, char* component, ProUIOrientation* value);
/*
    Purpose: Get the orientation of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Orientation of the slider.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderLengthGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the length of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Length of the slider.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the slider at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the slider at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  slider is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the slider          
                is attached at left. PRO_B_FALSE if the slider is not     
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the slider at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the slider at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  slider is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the slider         
                is attached at right. PRO_B_FALSE if the slider is not   
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the slider at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the slider at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  slider is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the slider           
                is attached at top. PRO_B_FALSE if the slider is not       
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the slider at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the slider at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  slider is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the slider        
                is attached at bottom. PRO_B_FALSE if the slider is not 
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the slider.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISliderIsTrackingEnabled (
    char           *dialog,
    char           *component,
    ProBoolean     *state  
);

/*
    Purpose: Get the state of slider tracking.

    Input Arguments:
        dialog - The name of the dialog that contains the slider.
        component - The name of the slider component.

    Output Arguments:
	state - PRO_B_TRUE when slider tracking is enabled. 
		PRO_B_FALSE when slider tracking is disabled.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


PRO_END_C_DECLS
 
#endif  /* PROUISLIDER_H */
