#ifndef PROUISPINBOX_H
#define PROUISPINBOX_H

#include <ProUI.h>



/*===========================================================================*/

PRO_BEGIN_C_DECLS

extern ProError ProUISpinboxHelptextSet(
    char*       dialog,
    char*       spinbox,
    wchar_t*     helptext);

/*
   Purpose:    Set the helptext of a spin box component

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox          - The name of the spin box component
      helptext          - The help text

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxEditable(
    char   *dialog,
    char   *spinbox);

/*
   Purpose:    Makes the spin box editable

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxReadOnly(
    char   *dialog,
    char   *spinbox);

/*
   Purpose:    Makes the spin box read only.

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUISpinboxInputtypeSet (
    char		*dialog,
    char		*spinbox,
    ProUIInputtype	input_type);

/*
   Purpose:    Set the type of value expected by a spin box component

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox        - The name of the spin box component
      input_type        - The value type (must be INTEGER or DOUBLE)

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxIntegerSet (
    char       *dialog,
    char       *spinbox,
    int         value);

/*
   Purpose:    Sets the value of a spin box whose value type is integer

   Input Arguments:
      dialog		- The name of the dialog that contains the spin box
      spinbox		- The name of the spin box component
      value		- The integer value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxIntegerGet (
    char       *dialog,
    char       *spinbox,
    int        *value);

/*
   Purpose:    Gets the value of a spin box whose value type is integer

   Input Arguments:
      dialog		- The name of the dialog that contains the spin box
      spinbox		- The name of the spin box component

   Output Arguments:
      value	        - The integer value

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxMinintegerSet (
    char       *dialog,
    char       *spinbox,
    int         value);

/*
   Purpose:    Sets the minimum value of the integer in the spin box

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The minimum integer value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxMaxintegerSet (
    char       *dialog,
    char       *spinbox,
    int         value);

/*
   Purpose:    Sets the maximum value of the integer in the spin box

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The maximum integer value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxIncrementSet (
    char       *dialog,
    char       *spinbox,
    int         value);

/*
   Purpose:    Sets the increment value for a spin box with an integer format

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The increment value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxFastincrementSet (
    char       *dialog,
    char       *spinbox,
    int         value);

/*
   Purpose:    Sets the fast increment value for a spin box with an integer format.
		This is the increment that is applied after the user has held one
		of the arrow buttons down for a few moments.

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The increment value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxDoubleSet (
    char       *dialog,
    char       *spinbox,
    double      value);

/*
   Purpose: Sets the value of a spin box whose value type is double

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The double value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUISpinboxDoubleGet (
    char       *dialog,
    char       *spinbox,
    double     *value);

/*
   Purpose: Gets the value of a spin box whose value type is double

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component

   Output Arguments:
      value            - The double value

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUISpinboxMindoubleSet (
    char       *dialog,
    char       *spinbox,
    double      value);

/*
   Purpose: Sets the minimum value of a spin box whose value type is double

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The minimum value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxMaxdoubleSet (
    char       *dialog,
    char       *spinbox,
    double      value);

/*
   Purpose: Sets the maximum value of a spin box whose value type is double

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The maximum value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxDigitsSet (
    char       *dialog,
    char       *spinbox,
    int         digits);

/*
   Purpose: Sets the number of digits displayed in a spin box. If the
	value type is integer, this is the total number of digits.
	If the value type is double, it is the number of digits after
	the decimal point.

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      digits            - The number of digits

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxDoubleformatSet (
    char       *dialog,
    char       *spinbox,
    char       *format);

/*
   Purpose: Sets the format used to display a double in a spin box.
		The format specification has the same syntax as for
		printf(), but with these restrictions :
<UL>
<LI>			 do not specify the total field width,
<LI>			specify the number of digits after the decimal
			point in float format using the '*' character -
			the number of digits is specified using ProUISpinboxDigitsSet().
</UL>
		The default value is "%.*lf"

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      format            - The format specification

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxDoubleincrementSet (
    char       *dialog,
    char       *spinbox,
    double      value);

/*
   Purpose:    Sets the increment value for a spin box with a double format

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The increment value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxFastdoubleincrementSet (
    char       *dialog,
    char       *spinbox,
    double      value);

/*
   Purpose:    Sets the fast increment value for a spin box with a double format.
                This is the increment that is applied after the user has held one
                of the arrow buttons down for a few moments.

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      value             - The increment value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxUpdateActionSet (
    char         *dialog,
    char         *spinbox,
    ProUIAction  callback,
    ProAppData   data);

/*
   Purpose:    Sets the update action for a spin box

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      callback          - The update action for the spin box
      data              - User data to be passed to the action function.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxActivateActionSet (
    char         *dialog,
    char         *spinbox,
    ProUIAction  callback,
    ProAppData   data);

/*
   Purpose:    Sets the activate action for a spin box

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      spinbox           - The name of the spin box component
      callback          - The activate action for the spin box
      data              - User data to be passed to the action function.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUISpinboxIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Spinbox is visible in the dialog or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the spin box
       component         - The name of the spin box component
                           
    Output Arguments:
        state            - Whether or not the spinbox is visible. 

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the spin box
       component         - The name of the spin box component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog            - The name of the dialog that contains the spin box
       component         - The name of the spin box component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Spinbox is enabled or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the spin box
       component         - The name of the spin box component
                          
    Output Arguments:
        state            - Whether or not the spinbox is sensitive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Spinbox to be enabled.

    Input Arguments:
        dialog            - The name of the dialog that contains the spin box
        component         - The name of the spin box component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxDisable(
    char* dialog,
    char* Spinbox);
/*
   Purpose:    Sets the Spinbox to be disabled, so the user cannot
		select it.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the Spinbox
      Spinbox           - The name of the Spinbox component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUISpinboxPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the spinbox.

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


extern ProError ProUISpinboxPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the spinbox.

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




extern ProError ProUISpinboxAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the spinbox with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the spinbox is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the spinbox used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the spinbox. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the spinbox's minimum size, the function will fail.
              The spinbox's minimum size can be retrieved
              using ProUISpinboxMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains spinbox.
        component - The name of the spinbox component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the spinbox with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains spinbox.
        component - The name of the spinbox component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the spinbox with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the spinbox in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the spinbox. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUISpinboxParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the spinbox component.

     Input Arguments:
         dialog - The name of the dialog that contains the spinbox.
         component - The name of the spinbox component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUISpinboxHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	    the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the spinbox at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the spinbox at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  spinbox is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the spinbox         
                is attached at left. PRO_B_FALSE if the spinbox is not   
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the spinbox at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the spinbox at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  spinbox is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the spinbox        
                is attached at right. PRO_B_FALSE if the spinbox is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the spinbox at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the spinbox at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  spinbox is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the spinbox          
                is attached at top. PRO_B_FALSE if the spinbox is not     
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the spinbox at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the spinbox at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  spinbox is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the spinbox       
                is attached at bottom. PRO_B_FALSE if the spinbox is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxDigitsGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get number of digit displayed in value of spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Number of digits.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUISpinboxDoubleformatGet (
    char                   *dialog,
    char                   *component,
    char                  **value);

/*
    Purpose: Get double format of the contents of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Double format of the contents. Free this value using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxDoubleincrementGet (
    char                   *dialog,
    char                   *component,
    double                 *value);

/*
    Purpose: Get incremental value for double when spinbox value is double.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Incremental value for double in spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxIsEditable (
    char           *dialog,   
    char           *component,
    ProBoolean     *state
);

/*
    Purpose: Get editable state of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        state - PRO_B_TRUE when the spinbox is editable.
		PRO_B_FALSE when the spinbox is not editable.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxIncrementGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get incremental value of the spinbox when the value is integer.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Increment value of the spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxInputtypeGet (
    char                   *dialog,
    char                   *component,
    ProUIInputtype         *value);

/*
    Purpose: Get the input type (Integer/Double) of the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Input type of the spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxMaxintegerGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get maximum integer value that can be input to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Maximum integer value to the spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

 
extern ProError ProUISpinboxMaxdoubleGet (
    char                   *dialog,
    char                   *component,
    double                 *value);

/*
    Purpose: Get maximum double value that can be input to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Maximum double value to the spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxMinintegerGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
    Purpose: Get minimum integer value that can be input to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Minimum integer value to the spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern  ProError ProUISpinboxMindoubleGet (
    char                   *dialog, 
    char                   *component, 
    double                 *value);

/*
    Purpose: Get minimum double value that can be input to the spinbox.

    Input Arguments:
        dialog - The name of the dialog that contains the spinbox.
        component - The name of the spinbox component.

    Output Arguments:
        value - Minimum double value to the spinbox.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/    
     
extern ProError ProUISpinboxFastincrementGet (
    char                   *dialog,
    char                   *component,
    int                    *value);

/*
   Purpose:    Gets the fast increment value for a spin box with an integer format.
                This is the increment that is applied after the user has held one
                of the arrow buttons down for a few moments.

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      component         - The name of the spin box component

   Output Arguments:
      value             - The increment value

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISpinboxFastdoubleincrementGet (
    char                   *dialog,
    char                   *component,
    double                 *value);

/*
   Purpose:    Gets the fast increment value for a spin box with a double format.
                This is the increment that is applied after the user has held one
                of the arrow buttons down for a few moments.

   Input Arguments:
      dialog            - The name of the dialog that contains the spin box
      component         - The name of the spin box component
 
   Output Arguments:
      value             - The increment value
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/



PRO_END_C_DECLS

#endif  /* PROUISPINBOX_H */
