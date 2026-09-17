#ifndef PROUIINPUTPANEL_H
#define PROUIINPUTPANEL_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIInputpanelHelptextSet(
    char*	dialog,
    char*	inputpanel,
    wchar_t*	helptext);

/*
   Purpose:    Set the helptext of an input panel component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelColumnsSet(
    char* dialog,
    char* inputpanel,
    int   columns);
/*
   Purpose:    Set the number of columns of an input panel component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
      columns           - The number of columns
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/
 
extern ProError ProUIInputpanelEditable(
    char*	dialog,
    char*	inputpanel);

/*
   Purpose:    Sets the input panel as editable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelReadOnly(
    char*	dialog,
    char*	inputpanel);

/*
   Purpose:    Sets the input panel as not-editable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelInputtypeSet(
    char*	   dialog,
    char*	   inputpanel,
    ProUIInputtype input_type);

/*
   Purpose:    Set the type of value expected by an input panel component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
      input_type        - The value type
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelActivateActionSet(
    char*	dialog,
    char*	inputpanel,
    ProUIAction action,
    ProAppData  appdata);
 
/*
   Purpose:    Sets the activate action for a input panel. This function is
                called when the user hits return in the input panel.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
      action            - The action to be called on selecting a button
      appdata           - User data to be passed to the action function.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelValueGet(
    char*	dialog,
    char*	inputpanel,
    wchar_t**	value);
 
/*
   Purpose:    Reports the current value of the input panel
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
 
   Output Arguments:
      value             - The current value of the input panel. The memory
			  for this wide string is allocated by the function
			  and should be freed with ProWstringFree().
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelValueSet(
    char*	dialog,
    char*	inputpanel,
    wchar_t*    value);
 
/*
   Purpose:    Sets the current value of the input panel
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      inputpanel        - The name of the input panel component
      value             - The new value of the input panel
 
   Output Arguments:
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Inputpanel is visible in the dialog or not.

    Input Arguments:
       dialog           - The name of the dialog that contains the input panel
       component        - The name of the input panel component
                           
    Output Arguments:
        state           - Whether or not the input panel is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelShow (
    char   *dialog,
    char   *component
);

/*
    Purpose: Makes the component visible in the dialog

    Input Arguments:
       dialog           - The name of the dialog that contains the input panel
       component        - The name of the input panel component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelHide (
    char   *dialog,
    char   *component
);

/*
    Purpose: Hides the component from the dialog

    Input Arguments:
       dialog           - The name of the dialog that contains the input panel
       component        - The name of the input panel component
                           
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the Inputpanel is enabled or not.

    Input Arguments:
       dialog           - The name of the dialog that contains the input panel
       component        - The name of the input panel component
                          
    Output Arguments:
        state           - Whether or not the input panel is sensitive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelEnable (
    char   *dialog,
    char   *component
);

/*
    Purpose:  Sets the Inputpanel to be enabled.

    Input Arguments:
       dialog            - The name of the dialog that contains the input panel
       component        - The name of the input panel component

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelDisable(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the Inputpanel to be disabled, so the user cannot
		select it.
 
   Input Arguments:
        dialog           - The name of the dialog that contains the input panel
        component        - The name of the input panel component

   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelInputActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);

/*
    Purpose: Sets the input action for an input panel. This function is
                called when the user modifies the contents of the input panel.

    Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component         - The name of the input panel component
      callback          - The action to perform when the input panel contents are modified.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIInputpanelFocusinActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);

/*
    Purpose: Sets the focus in action for an input panel. This function is
                called when the user moves the cursor onto the input panel 
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component         - The name of the input panel component
      callback          - The action to perform when the input panel gains user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIInputpanelFocusoutActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData    data);

/*
    Purpose: Sets the focus out action for an input panel. This function is
                called when the user moves the cursor off of the input panel 
		using the mouse or [TAB] key.

    Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component         - The name of the input panel component
      callback          - The action to perform when the input panel loses user focus.
      data              - Application data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIInputpanelIntegerSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the integer value of the input panel, if the input
               type is PROUIINPUTTYPE_INTEGER.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The integer value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelIntegerGet (
    char       *dialog,
    char       *component,
    int        *value);
/*
   Purpose:    Reports the integer value of the input panel, if the input
               type is PROUIINPUTTYPE_INTEGER.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The integer value of the input panel.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelMinintegerSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the minimum value of the input panel, if the input
               type is PROUIINPUTTYPE_INTEGER.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The minimum value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/



extern ProError ProUIInputpanelMaxintegerSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the maximum value of the input panel, if the input
               type is PROUIINPUTTYPE_INTEGER.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The maximum value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelDoubleSet (
    char       *dialog,
    char       *component,
    double      value);
/*
   Purpose:    Sets the double value of the input panel, if the input
               type is PROUIINPUTTYPE_DOUBLE.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The double value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelDoubleGet (
    char       *dialog,
    char       *component,
    double     *value);
/*
   Purpose:    Reports the double value of the input panel, if the input
               type is PROUIINPUTTYPE_DOUBLE.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The double value of the input panel.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelMindoubleSet (
    char       *dialog,
    char       *component,
    double      value);
/*
   Purpose:    Sets the minimum value of the input panel, if the input
               type is PROUIINPUTTYPE_DOUBLE.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The minimum value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelMaxdoubleSet (
    char       *dialog,
    char       *component,
    double      value);
/*
   Purpose:    Sets the maximum value of the input panel, if the input
               type is PROUIINPUTTYPE_DOUBLE.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The maximum value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIInputpanelDigitsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the number of digits to show in the input panel, if the 
               input type is PROUIINPUTTYPE_DOUBLE.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The number of digits to show in the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelStringSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
   Purpose:    Sets the string value of the input panel, if the 
               input type is PROUIINPUTTYPE_STRING.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The string value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelStringGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
   Purpose:    Reports the string value of the input panel, if the input
               type is PROUIINPUTTYPE_STRING.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The string value of the input panel. Free this
                          argument with ProStringFree()
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelWidestringSet (
    char       *dialog,
    char       *component,
    wchar_t    *value);
/*
   Purpose:    Sets the wide string value of the input panel, if the 
               input type is PROUIINPUTTYPE_WSTRING.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The wide string value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelWidestringGet (
    char       *dialog,
    char       *component,
    wchar_t   **value);
/*
   Purpose:    Reports the wide string value of the input panel, if the input
               type is PROUIINPUTTYPE_WSTRING.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The wide string value of the input panel.  Free this
                          argument with ProWstringFree()
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelOrdinalSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the ordinal value of the input panel, if the 
               input type is PROUIINPUTTYPE_FRACTION.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The ordinal value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelOrdinalGet (
    char       *dialog,
    char       *component,
    int        *value);
/*
   Purpose:    Reports the ordinal value of the input panel, if the input
               type is PROUIINPUTTYPE_FRACTION.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The ordinal value of the input panel.  
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelNumeratorSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the numerator value of the input panel, if the 
               input type is PROUIINPUTTYPE_FRACTION.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The numerator value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelNumeratorGet (
    char       *dialog,
    char       *component,
    int        *value);
/*
   Purpose:    Reports the numerator value of the input panel, if the input
               type is PROUIINPUTTYPE_FRACTION.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The numerator value of the input panel.  
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/



extern ProError ProUIInputpanelDenominatorSet (
    char       *dialog,
    char       *component,
    int         value);
/*
   Purpose:    Sets the denominator value of the input panel, if the 
               input type is PROUIINPUTTYPE_FRACTION.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
      value             - The denominator value of the input panel.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelDenominatorGet (
    char       *dialog,
    char       *component,
    int        *value);
/*
   Purpose:    Reports the denominator value of the input panel, if the input
               type is PROUIINPUTTYPE_FRACTION.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the input panel
      component        - The name of the input panel component
 
   Output Arguments:
      value             - The denominator value of the input panel.  
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/


extern ProError ProUIInputpanelPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the inputpanel.

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


extern ProError ProUIInputpanelPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the inputpanel.

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




extern ProError ProUIInputpanelAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the input panel with respect to a given 
              anchor location. This function is applicable  only if the parent 
              of the input panel is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the input panel.
        component - The name of the input panel component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the input panel used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the inputpanel. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the inputpanel's minimum size, the function will fail.
              The inputpanel's minimum size can be retrieved
              using ProUIInputpanelMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains inputpanel.
        component - The name of the inputpanel component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the inputpanel with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The Name of the dialog that contains input panel.
        component - The name of the input panel component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the inputpanel with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The Name of the dialog that contains input panel.
        component - The name of the input panel component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the inputpanel in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the inputpanel. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The Name of the dialog that contains input panel.
        component - The name of the input panel component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_GENERAL_ERROR   - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIInputpanelParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the inputpanel component.

     Input Arguments:
         dialog - The name of the dialog that contains the inputpanel.
         component - The name of the inputpanel component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIInputpanelMaxlenSet (char* dialog, char* component, int value);
/*
    Purpose: Set the maximum length of the text that the inputpanel can
		contain.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Length of the text.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMaxlenGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the maximum length of the text that the inputpanel can
	contain.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Length of the text.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over 
	     the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelColumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the width of the inputpanel in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Width of the inputpanel.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMincolumnsSet (char* dialog, char* component, int value);
/*
    Purpose: Set the minimum width of the inputpanel in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Minimum width of the inputpanel.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMincolumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum width of the inputpanel in character widths.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Minimum width of the inputpanel.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIInputpanelUsePasswordchars (char* dialog, char* component);
/*
    Purpose: Set the inputpanel to be used for password entry.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelUseNormalchars (char* dialog, char* component);
/*
    Purpose: Set the inputpanel to be used for Normal characters entry.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIInputpanelContainsPassword (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the inputpanel can be used for password entry or normal
	     characters entry.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - PRO_B_TRUE, if the inputpanal is for password entry.
		PRO_B_FALSE, if the inputpanel is for normal characters
		entry.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelPasswordcharSet (char* dialog, char* component, int value);
/*
    Purpose: Set the inputpanel to display the given ASCII value for password 
	     entry.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - ASCII value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelPasswordcharGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the ASCII value that is displayed for the password entry.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - ASCII value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelInputtypeGet (char* dialog, char* component, ProUIInputtype* value);
/*
    Purpose: Get the input type of the inputpane.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - input type of the inputpanel.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMinintegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum integer value that can be entered in the 
	inputpanelf the input type is PROUIINPUTTYPE_INTEGER.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Minimum integer value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMaxintegerGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the maximum integer value that can be entered in the 
	inputpanel if the input type is PROUIINPUTTYPE_INTEGER.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Maximum integer value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMindoubleGet (char* dialog, char* component, double* value);
/*
    Purpose: Get the minimum double value that can be entered in the
	inputpanel if the input type is PROUIINPUTTYPE_DOUBLE.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Minimum double value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelMaxdoubleGet (char* dialog, char* component, double* value);
/*
    Purpose: Get the maximum double value that can be entered in the
	inputpanel if the input type is PROUIINPUTTYPE_DOUBLE.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Maximum double value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelDigitsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of digits that the user can eneter. If this value
	is 0, then the value will be ignored for formatting.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Number of digits.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelDoubleformatSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the format of the double value entered in the inputpanel if
	the input type of the inputpanel is PROUIINPUTTYPE_DOUBLE.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Format of the double value.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelDoubleformatGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the format of the double value entered in the inputpanel if
	the input type of the inputpanel is PROUIINPUTTYPE_DOUBLE.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Format of the double value. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the inputpanel at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the inputpanel at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  inputpanel is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the inputpanel      
                is attached at left. PRO_B_FALSE if the inputpanel is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the inputpanel at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the inputpanel at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  inputpanel is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the inputpanel     
                is attached at right. PRO_B_FALSE if the inputpanel is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the inputpanel at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the inputpanel at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  inputpanel is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the inputpanel       
                is attached at top. PRO_B_FALSE if the inputpanel is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the inputpanel at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the inputpanel at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  inputpanel is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the inputpanel    
                is attached at bottom. PRO_B_FALSE if the inputpanel is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIInputpanelIsEditable (
    char           *dialog,
    char           *component, 
    ProBoolean     *state
);

/*
    Purpose: Get editabale status of Inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - PRO_B_TRUE when inputpanel is editable.
		PRO_B_FALSE when inputpanel is not editable.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/



extern ProError ProUIInputpanelAutohighlightEnable (
    char   *dialog, 
    char   *component);

/*
    Purpose: The contents of the inputpanel will be highlighted when the component gains the focus.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
	None

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/


extern ProError ProUIInputpanelAutohighlightDisable (
    char   *dialog,
    char   *component);

/*
    Purpose: The  contents of the inputpanel will not be highlighted  when the component gains the focus.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
	None

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/


extern ProError ProUIInputpanelIsAutohighlightEnabled (
    char           *dialog,
    char           *component,
    ProBoolean     *state
);

/*
    Purpose: To obtain the autohighlight status of the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
        state - PRO_B_TRUE when inputpanel contents are autohighlighted.
		PRO_B_FALSE when inputpanel contents are not autohighlighted.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUIInputpanelTabcharsAllow (
    char   *dialog, 
    char   *component);

/*
    Purpose: Insert tab key press into the text of inputpanel as tab character.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
	None

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/


extern ProError ProUIInputpanelTabcharsDisallow (
    char   *dialog,
    char   *component);

/*
    Purpose: Tab key press will be ignored by inputpanel and will be used for focus traversal.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
	None

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/

 
extern ProError ProUIInputpanelAllowsTabchars (
    char           *dialog,
    char           *component,
    ProBoolean     *state
);

/*
    Purpose: To obtain the  behavior of the inputpanel when the Tab key is pressed.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.

    Output Arguments:
	    state  - PRO_B_TRUE when tab key press is inserted as a tab character in inputpanel text.
		PRO_B_FALSE when tab key press is used for focus traversal.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/
extern ProError ProUIInputpanelBackgroundcolorSet (
    char *dialog, 
    char *component, 
    ProUIColor value);
/*
    Purpose: Change the background color of the inputpanel.

    Input Arguments:
        dialog - The name of the dialog that contains the inputpanel.
        component - The name of the inputpanel component.
	value - Background color value.
    Output Arguments:
	none
        
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
*/    
    

PRO_END_C_DECLS
 
#endif  /* PROUIINPUTPANEL_H */
