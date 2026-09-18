#ifndef PROUICHECKBUTTON_H
#define PROUICHECKBUTTON_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUICheckbuttonHelptextSet(
    char*	dialog,
    char*	checkbutton,
    wchar_t*	helptext);

/*
   Purpose:    Set the helptext of a checkbutton component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR - The function failed

   <!-- Objectname: ProUI -->
    
*/

extern ProError ProUICheckbuttonTextSet(
    char*	dialog,
    char*	checkbutton,
    wchar_t*	label);

/*
   Purpose:    Set the label of a checkbutton component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
      label             - The label of the checkbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonActivateActionSet(
    char*	dialog,
    char*	checkbutton,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the activate action for a checkbutton. This function is
                called when the user selects the checkbutton.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
      action            - The action to be called on activating the checkbutton
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonEnable(
    char* dialog,
    char* checkbutton);
 
/*
   Purpose:    Sets the checkbutton to be enabled.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonDisable(
    char* dialog,
    char* checkbutton);
/*
   Purpose:    Sets the pushbutton to be disabled, so the user cannot
		select it.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonSet(
    char* dialog,
    char* checkbutton);
 
/*
   Purpose:    Sets the checkbutton to TRUE

   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonUnset(
    char* dialog,
    char* checkbutton);
/*
   Purpose:    Sets the checkbutton to FALSE

   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonGetState(
    char* dialog,
    char* checkbutton,
    ProBoolean  *set);
 
/*
   Purpose:    Inquires whether the checkbutton is currently set.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton
      checkbutton       - The name of the checkbutton component
 
   Output Arguments:
      set               - Whether the checkbutton is set
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the checkbutton is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the checkbutton
       component         - The name of the checkbutton component

    Output Arguments:
        state            - PRO_B_TRUE if the checkbutton is enabled.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICheckbuttonIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Checkbutton is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the checkbutton
       component         - The name of the checkbutton component
                           
    Output Arguments:
        state            - Whether or not the checkbutton is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICheckbuttonShow (
    char   *dialog,
    char   *component
);
/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the checkbutton
       component         - The name of the checkbutton component
                          

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICheckbuttonHide (
    char   *dialog,
    char   *component
);
/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the checkbutton
       component         - The name of the checkbutton component

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICheckbuttonPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the checkbutton.

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


extern ProError ProUICheckbuttonPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the checkbutton.

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




extern ProError ProUICheckbuttonAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
   Purpose: Sets the position of the checkbutton with respect to a given 
              anchor location. This function is applicable  only if the parent 
              of the checkbutton is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the checkbutton used to set the position.


    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the checkbutton. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the checkbutton's minimum size, the function will fail.
              The checkbutton's minimum size can be retrieved
              using ProUICheckbuttonMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains checkbutton.
        component - The name of the checkbutton component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the checkbutton with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the checkbutton with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the checkbutton in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the checkbutton. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUICheckbuttonParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the checkbutton component.

     Input Arguments:
         dialog - The name of the dialog that contains the checkbutton.
         component - The name of the checkbutton component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUICheckbuttonHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over the 
	    checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonTextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the label of the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - The name of the checkbutton. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonBitmapSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the bitmap to the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonBitmapGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the bitmap of the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - The name of the bitmap. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the checkbutton at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the checkbutton at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  checkbutton is attached at left side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the checkbutton     
                is attached at left. PRO_B_FALSE if the checkbutton is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the checkbutton at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the checkbutton at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  checkbutton is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the checkbutton    
                is attached at right. PRO_B_FALSE if the checkbutton is not
                 attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the checkbutton at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the checkbutton at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  checkbutton is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the checkbutton      
                is attached at top. PRO_B_FALSE if the checkbutton is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the checkbutton at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the checkbutton at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  checkbutton is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the checkbutton   
                is attached at bottom. PRO_B_FALSE if the checkbutton is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the checkbutton.

    Input Arguments:
        dialog - The name of the dialog that contains the checkbutton.
        component - The name of the checkbutton component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICheckbuttonIsResizeable (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the checkbutton is resizeable or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the checkbutton
       component         - The name of the checkbutton component
                          
    Output Arguments:
        state            - Whether or not the checkbutton is resizeable.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonEnableResizing (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the checkbutton to be resizeable.

    Input Arguments:
       dialog            - The name of the dialog that contains the checkbutton
       component         - The name of the checkbutton component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonDisableResizing(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the checkbutton to be non-resizeable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton.
      component         - The name of the checkbutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUICheckbuttonButtonstyleSet (
    char                   *dialog, 
    char                   *component, 
    ProUIButtonStyle        value);
/*
   Purpose:    Sets the checkbutton button style.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton.
      component         - The name of the checkbutton component
      value             - The button style to use.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUICheckbuttonButtonstyleGet (
    char                   *dialog, 
    char                   *component, 
    ProUIButtonStyle       *value);
/*
   Purpose:    Gets the checkbutton button style.  
 
   Input Arguments:
      dialog            - The name of the dialog that contains the checkbutton.
      component         - The name of the checkbutton component  
 
   Output Arguments:
      value             - The button style to use.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

PRO_END_C_DECLS
 
#endif  /* PROUICHECKBUTTON_H */
