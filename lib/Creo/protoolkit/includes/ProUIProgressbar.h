#ifndef PROUIPROGRESSBAR_H
#define PROUIPROGRESSBAR_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIProgressbarHelptextSet(
    char*	dialog,
    char*	progressbar,
    wchar_t*	helptext);

/*
   Purpose:    Set the helptext of a progress bar component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the progress bar
      progressbar       - The name of the progress bar component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR
			- The function failed - use ProUILasterrorGet()
*/

extern ProError ProUIProgressbarLengthSet(
    char*	dialog,
    char*	progressbar,
    int         length);
/*
   Purpose:    Set the length of a progress bar component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the progress bar
      progressbar       - The name of the progress bar component
      length            - The length of the progress bar component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR
                        - The function failed - use ProUILasterrorGet()
*/
 
extern ProError ProUIProgressbarMinintegerSet(
    char*	dialog,
    char*	progressbar,
    int         min);
/*
   Purpose:    Set the minimum integer for a progress bar component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the progress bar
      progressbar       - The name of the progress bar component
      min               - The minimum integer value (default = -32768)
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR
                        - The function failed - use ProUILasterrorGet()
*/

extern ProError ProUIProgressbarMaxintegerSet(
    char*	dialog,
    char*	progressbar,
    int         max);
/*
   Purpose:    Set the maximum integer for a progress bar component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the progress bar
      progressbar       - The name of the progress bar component
      max               - The maximum integer value (default = 32767)
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR
                        - The function failed - use ProUILasterrorGet()
*/
 
extern ProError ProUIProgressbarProgressstyleSet(
    char*               dialog,
    char*               progressbar,
    ProUIProgressstyle  style);

/*
   Purpose:    Set the progress style of a progress bar
 
   Input Arguments:
      dialog            - The name of the dialog that contains the progress bar
      progressbar       - The name of the progress bar component
      style             - The progress style
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR
                        - The function failed - use ProUILasterrorGet()
*/
 
extern ProError ProUIProgressbarIntegerSet(
    char*	dialog,
    char*	progressbar,
    int         position);
 
/*
   Purpose:    Sets the current position of the progress bar
               <p><b>Note:</b> The default min and max limits for the 
	       Progress bar integer are -32768 and 32768. 
	       Please use ProUIProgressbarMinintegerSet & 
	       ProUIProgressbarMaxintegerSet to change these as required.  
   Input Arguments:
      dialog            - The name of the dialog that contains the progress bar
      progressbar       - The name of the progress bar component
      position          - The current position of the progress bar
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR
                        - The function failed - use ProUILasterrorGet()
*/

extern ProError ProUIProgressbarIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Progressbar is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the progress bar
       component         - The name of the progress bar component
                           
    Output Arguments:
        state            - Whether or not the progressbar is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIProgressbarShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the progress bar
       component         - The name of the progress bar component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIProgressbarHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the progress bar
       component         - The name of the progress bar component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIProgressbarPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the progressbar.

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


extern ProError ProUIProgressbarPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the progressbar.

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




extern ProError ProUIProgressbarAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
  Purpose: Sets the position of the progressbar with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the progressbar is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the progressbar used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the progressbar. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the progressbar's minimum size, the function will fail.
              The progressbar's minimum size can be retrieved
              using ProUIProgressbarMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains progressbar.
        component - The name of the progressbar component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the progressbar with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains progressbar.
        component - The name of the progressbar component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the progressbar with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the progressbar in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the progressbar. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIProgressbarParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the progressbar component.

     Input Arguments:
         dialog - The name of the dialog that contains the progressbar.
         component - The name of the progressbar component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIProgressbarHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarIntegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the integer value of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Value of the progressbar.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarMinintegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum integer value of progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Minimum value of the progressbar.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarMaxintegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the maximum integer value of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Maximum value of the progressbar.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarProgressstyleGet (char* dialog, char* component, ProUIProgressstyle* value);
/*
    Purpose: Get the progress style of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Progress style of the progressbar.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarOrientationSet (char* dialog, char* component, ProUIOrientation value);
/*
    Purpose: Set the orientation of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.
        value - Orientation of the progressbar.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarOrientationGet (char* dialog, char* component, ProUIOrientation* value);
/*
    Purpose: Get the orientation of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Orientation of the progressbar.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarLengthGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the length of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Length of the progressbar.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the progressbar at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the progressbar at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  progressbar is attached at left side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the progressbar     
                is attached at left. PRO_B_FALSE if the progressbar is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the progressbar at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the progressbar at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  progressbar is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the progressbar    
                is attached at right. PRO_B_FALSE if the progressbar is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the progressbar at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the progressbar at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  progressbar is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the progressbar      
                is attached at top. PRO_B_FALSE if the progressbar is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the progressbar at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the progressbar at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  progressbar is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the progressbar   
                is attached at bottom. PRO_B_FALSE if the progressbar is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIProgressbarBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the progressbar.

    Input Arguments:
        dialog - The name of the dialog that contains the progressbar.
        component - The name of the progressbar component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




PRO_END_C_DECLS
 
#endif  /* PROUIPROGRESSBAR_H */
