
#ifndef PROUIDIALOG_H
#define PROUIDIALOG_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUIDialogCreate(
    char* dialog_name,
    char* resource);
/*
   Purpose:     Loads a dialog from a resource file into memory. If the resource file 
                name is NULL, creates an empty dialog.
   <P>
   Note:	The dialog name specified in the resource file must match
   		'dialog_name' input argument.
 
   Input Arguments:
      dialog_name       - The name of the dialog
      resource          - The name of the resource file
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully loaded and displayed
				the dialog
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIDialogActivate(
    char* dialog_name,
    int*  status);

/*
   Purpose:     Displays the dialog on the screen and makes it active.
		This function returns only after a call to ProUIDialogExit()
		applied to the same dialog.
 
   Input Arguments:
      dialog_name       - The name of the dialog
 
   Output Arguments:
      status            - The value of the input status argument to the
			  call to ProUIDialogExit() that caused the
			  function to return. May be NULL.
 
   Return Values:
      PRO_TK_NO_ERROR     - The function was successful
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIDialogExit(
    char* dialog_name,
    int   status);

/*
   Purpose:   Terminates the activation of the named dialog, and causes
		a return from the call to ProUIDialogActivate() that make
		it active.
 
   Input Arguments:
      dialog_name       - The name of the dialog
      status            - The value to be passed as the output status
			  argument to ProUIDialogActivate().
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIDialogDestroy(
    char* dialog_name);

/*
   Purpose:   Removes the named dialog from memory.
 
   Input Arguments:
      dialog_name       - The name of the dialog
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIDialogDefaultbuttonSet(
    char* dialog,
    char* default_button);

/*
   Purpose:    Sets the default button for a dialog
 
   Input Arguments:
      dialog            - The name of the dialog
      default_button    - The name of the default button
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIDialogTitleSet(
    char*    dialog,
    wchar_t* label);

/*
   Purpose:    Sets the label for a dialog
 
   Input Arguments:
      dialog            - The name of the dialog
      label             - The label
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIDialogCloseActionSet(
    char*	dialog,
    ProUIAction action,
    ProAppData  appdata);

/*
   Purpose:    Sets the close action for a dialog. This function is
		called after the dialog is closed by a call to 
		ProUIDialogExit()
 
   Input Arguments:
      dialog            - The name of the dialog
      action            - The action to be called on closing the dialog
      appdata 		- User data to be passed to the action function.
			  Can be NULL.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIDialogActivateActionSet (
    char         *dialog,
    ProUIAction  callback,
    ProAppData  data);
/*
    Purpose: Sets the function that is called when the dialog has become the
             current foreground window.
	     <p><b>Note:</b>
	     The callback for a given Dialog is generated <I>only on windows
	     platform</I> under the following conditions:
	     <br>
	     1. The dialog must not be the current foreground application.
	     <br>
	     2. The dialog (when it is not the foreground application) is 
	     activated using one of the following methods:
	     <br>
	     &nbsp - When the user clicks on the taskbar button for 
	     the given dialog. 
	     <br>
	     &nbsp - When the user switches to the given dialog using Alt+Tab.
	     <br>
	     &nbsp - When the user clicks within the given dialog.

    Input Arguments:
        dialog           - The name of the dialog.
        callback         - The action to perform
        data             - Data to be passed to callback function
			  Can be NULL.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIDialogPopupmenuSet (
    char       *dialog,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the dialog.

    Input Arguments:
        dialog             - The dialog name.
        value              - The name of the popup menu pane.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUIDialogPopupmenuGet (
    char       *dialog,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the dialog.

    Input Arguments:
        dialog             - The dialog name.       

    Output Arguments:
        value              - The name of the popup menu pane.  Free this string
	                      using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUIDialogHorzpointSet (char* dialog, ProUIHorzPosition value);
/*
    Purpose: Set the horizontal position of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Horizontal position of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzpointGet (char* dialog, ProUIHorzPosition* value);
/*
    Purpose: Get the horizontal position of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Current horizontal position.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzmethodSet (char* dialog, ProUIPositioningMethod value);
/*
    Purpose: Set the horizontal positioning method of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Horizontal positioning method.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzmethodGet (char* dialog, ProUIPositioningMethod* value);
/*
    Purpose: Get the horizontal positioning method of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Horizontal positioning method of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzdialogSet (char* dialog, char* value);
/*
    Purpose: Set the name of the existing dialog to which the dialog should be 
             relatively positioned in horizontal direction. This function should 
	     be used only if the horizontal positioning method of the 
	     dialog is PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog to be set.
        value - Name of the existing dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzdialogGet (char* dialog, char** value);
/*
    Purpose: Get the name of the existing dialog to which the dialog is 
             relatively positioned in horizontal direction. This function
	     should be used only if the horizontal positioning method of 
	     the dialog is PROUIPOSITIONING_RELATIVE. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Name of the existing dialog. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzatpointSet (char* dialog, ProUIHorzPosition value);
/*
    Purpose: Set the horizontal position of the dialog relative to the existing 
             dialog. This function should be used only if the horizontal positi
	     -oning method of the dialog is PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog to be set.
        value - Horizontal position with respect to the existing dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzatpointGet (char* dialog, ProUIHorzPosition* value);
/*
    Purpose: Get the horizontal position of the dialog relative to the existing 
             dialog. This function should be used only if the horizontal positi
	     -oning method of the dialog is  PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Horizontal position  with respect to the existing dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzposoffsetSet (char* dialog, int value);
/*
    Purpose: Set the horizontal offset to the dialog relative to the existing 
             dialog. This function should be used only if the horizontal 
	     positioning method of the dialog is  PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog to be set.
        value - Horizontal offset value. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzposoffsetGet (char* dialog, int* value);
/*
    Purpose: Get the horizontal offset to the dialog relative to the existing 
             dialog. This function should be used only if the horizontal 
	     positioning method of the dialog is  PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Horizontal offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertpointSet (char* dialog, ProUIVertPosition value);
/*
    Purpose: Set the vertical position of the dialog.

    Input Arguments:
        dialog - Name of the dialog to be set.
        value - Verticalposition of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertpointGet (char* dialog, ProUIVertPosition* value);
/*
    Purpose: Get the vertical position of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Vertical position of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertmethodSet (char* dialog, ProUIPositioningMethod value);
/*
    Purpose: Set the vertical positioning method of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Vertical positioning method.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertmethodGet (char* dialog, ProUIPositioningMethod* value);
/*
    Purpose: Get the vertical positioning method of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Vertical positioning method.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertdialogSet (char* dialog, char* value);
/*
    Purpose: Set the name of the existing dialog to which the dialog should be 
             relatively positioned in vertical direction.

    Input Arguments:
        dialog - Name of the dialog to be set.
        value - Name of the existing dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertdialogGet (char* dialog, char** value);
/*
    Purpose: Get the name of the existing dialog to which the dialog is 
             relatively positioned in vertical direction. This function
	     should be used only if the vertical positioning method of 
	     the dialog is PROUIPOSITIONING_RELATIVE. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Name of the existing dialog. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertatpointSet (char* dialog, ProUIVertPosition value);
/*
    Purpose: Set the vertical position of the dialog relative to the existing 
             dialog. This function should be used only if the vertical positi
	     -oning method of the dialog is PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog.
        value - Vertical position with respect to the existing dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertatpointGet (char* dialog, ProUIVertPosition* value);
/*
    Purpose: Get the vertical position of the dialog relative to the existing 
             dialog. This function should be used only if the vertical positi
	     -oning method of the dialog is PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Vertical position of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertposoffsetSet (char* dialog, int value);
/*
    Purpose: Set the vertical offset to the dialog relative to the existing 
	     dialog. This function should be used only if the vertical 
	     positioning method of the dialog is PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog.
        value - Vertical offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertposoffsetGet (char* dialog, int* value);
/*
    Purpose: Get the vertical offset value to the dialog relative to the 
	     existing dialog. This function should be used only if the 
	     vertical positioning method of the dialog is 
	     PROUIPOSITIONING_RELATIVE.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Vertical offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogWidthSet (char* dialog, int value);
/*
    Purpose: Set the width of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Width of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogWidthGet (char* dialog, int* value);
/*
    Purpose: Get the width of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Width of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHeightSet (char* dialog, int value);
/*
    Purpose: Set the height of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Height of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHeightGet (char* dialog, int* value);
/*
    Purpose: Get the height of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Height of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUIDialogHorzsizeSet (char* dialog, int value);
/*
    Purpose: Set the width of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Width of the dialog in units of 1/1000ths of the screen width.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHorzsizeGet (char* dialog, int* value);
/*
    Purpose: Get the width of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Width of the dialog in units of 1/1000ths of the screen width.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertsizeSet (char* dialog, int value);
/*
    Purpose: Set the height of the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Height of the dialog in units of 1/1000ths of the screen 
                height.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogVertsizeGet (char* dialog, int* value);
/*
    Purpose: Get the height of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Height of the dialog in units of 1/1000ths of the screen 
                height.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogMenubarAdd (char* dialog, char* name);
/*
    Purpose: Add a new menubar to the dialog. This function should be 
	     called before activating the dialog using the function 
	     ProUIDialogActivate.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the menubar to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogMenupaneAdd (char* dialog, char* name);
/*
    Purpose: To add the menupane to a cascade button in the menubar, use 
	ProUICascadebuttonChildnamesSet(). To add the menupane directly
	into the menubar, use ProUIMenubarNamesSet().

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the menupane to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogMenupaneRemove (char* dialog, char* name);
/*
    Purpose: If the menupane is added to a cascade button or menubar, it
	     should be removed from that item before using this function
	     to remove it from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the menupane to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIDialogCheckbuttonAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new checkbutton to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the checkbutton to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogDrawingareaAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new drawing area to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the drawing area to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogInputpanelAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new inputpanel to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the inputpanel to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogLabelAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new label to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the label to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogLayoutAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new layout to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the layout to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogListAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new list to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the list to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogOptionmenuAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new optionmenu to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the optionmenu to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogProgressbarAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new progressbar to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the progressbar to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogPushbuttonAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new pushbutton to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the pushbutton to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRadiogroupAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new radiogroup to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the radiogroup to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSeparatorAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new separator to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the separator to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSliderAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new slider to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the slider to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSpinboxAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new spinbox to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the spinbox to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTabAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new tab to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the tab to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTableAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new table to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the table to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTextareaAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new textarea to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the textarea to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogThumbwheelAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new thumbwheel to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the thumbwheel to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTreeAdd (char* dialog, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new tree to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the tree to be added.
        grid - Position of the added component in the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogCheckbuttonRemove (char* dialog, char* name);
/*
    Purpose: Remove the checkbutton from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogDrawingareaRemove (char* dialog, char* name);
/*
    Purpose: Remove the drawing area from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the drawing area to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogInputpanelRemove (char* dialog, char* name);
/*
    Purpose: Remove the inputpanel from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the inputpanel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogLabelRemove (char* dialog, char* name);
/*
    Purpose: Remove the label from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the label to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogLayoutRemove (char* dialog, char* name);
/*
    Purpose: Remove the layout from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the layout to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogListRemove (char* dialog, char* name);
/*
    Purpose: Remove the list from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the list to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogOptionmenuRemove (char* dialog, char* name);
/*
    Purpose: Remove the optionmenu from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the optionmenu to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogProgressbarRemove (char* dialog, char* name);
/*
    Purpose: Remove the progressbar from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the progressbar to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogPushbuttonRemove (char* dialog, char* name);
/*
    Purpose: Remove the pushbutton from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRadiogroupRemove (char* dialog, char* name);
/*
    Purpose: Remove the radiogroup from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSeparatorRemove (char* dialog, char* name);
/*
    Purpose: Remove the separator from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the separator to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSliderRemove (char* dialog, char* name);
/*
    Purpose: Remove the slider from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the slider to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSpinboxRemove (char* dialog, char* name);
/*
    Purpose: Remove the spinbox from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the spinbox to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTabRemove (char* dialog, char* name);
/*
    Purpose: Remove the tab from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the tab to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTableRemove (char* dialog, char* name);
/*
    Purpose: Remove the table from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the table to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTextareaRemove (char* dialog, char* name);
/*
    Purpose: Remove the textarea from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the textarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogThumbwheelRemove (char* dialog, char* name);
/*
    Purpose: Remove the thumbwheel from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the thumbwheel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTreeRemove (char* dialog, char* name);
/*
    Purpose: Remove the tree from the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        name - Name of the tree to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogSizeGet (char* dialog, int* width, int* height);
/*
    Purpose: Get the size of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        width - Width of the dialog.
        height - Height of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogMinimumsizeGet (char* dialog, int* width, int* height);
/*
    Purpose: Set the dialog minimum size in pixels.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        width - Width of the dialog.
        height - Height of the dialog.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogScreenpositionGet (char* dialog, int* x, int* y);
/*
    Purpose: Get the screen position in pixels of the dialog component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        x - X value.
        y - Y value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogReconfigure (char* dialog, int x, int y, int width, int height);
/*
    Purpose: Set the position and size of the dialog. If any of the 
	values are specified as PROUI_UNUSED then the current values 
	are used.

    Input Arguments:
        dialog - Name of the dialog.
        x - X value
        y - Y value
        width - Width of the dialog.
        height - Height of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogPositionReset (char* dialog);
/*
    Purpose: Recalculate and set the position of the dialog using the 
             positioning method attributes of the component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogComponentsCollect (char* dialog, char* component_type, int
* count, char*** component_array);
/*
    Purpose: Returns the names of components in this dialog.   This function
             can also filter components by their type.

    Input Arguments:
        dialog - Name of the dialog.
        component_type - One of the predefined component class types (see
                         ProUI.h).  Pass NULL to obtain all components.

    Output Arguments:
        count - The number of components found.
        component_array - The component array.  Free this using
                          ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No components of the given type were found.

*/


extern ProError ProUIDialogChildnamesGet (char *dialog, int *count, char ***values);
/*
     Purpose: Get the name of the children to the dialog component.

     Input Arguments:
         dialog - Name of the dialog.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUIDialogTitleGet (char* dialog, wchar_t** value);
/*
    Purpose: Get the title of the dialog component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - The title of the dialog. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogBitmapSet (char* dialog, char* value);
/*
    Purpose: Set the bitmap to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogBitmapGet (char* dialog, char** value);
/*
    Purpose: Get the bitmap of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - The name of the bitmap. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogDialogstyleSet (char* dialog, ProUIDialogStyle value);
/*
    Purpose: Set the dialog style to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - The dialog style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogDialogstyleGet (char* dialog, ProUIDialogStyle* value);
/*
    Purpose: Get the dialog style of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - The dialog style.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogStartlocationSet (char* dialog, ProUIStartLocation value);
/*
    Purpose: Set the start location for the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Value of the start location.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogStartlocationGet (char* dialog, ProUIStartLocation* value);
/*
    Purpose: Get the start location of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Value of the start location.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRememberPosition (char* dialog);
/*
    Purpose: Set the dialog to remember its position when it is destroyed.
	     So that when it is recreated it will display at the same 
	     location. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogForgetPosition (char* dialog);
/* 
    Purpose: Set the dialog to forget its position when it is destroyed.
	     So when it is recreated it will not display at the same 
	     location. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRemembersPosition (char* dialog, ProBoolean* state);
/*
    Purpose: Checks if the dialog remembers its old position.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
	state - PRO_B_TRUE when the dialog remembers its old position.
		PRO_B_FALSE when it does not.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIDialogDefaultbuttonGet (char* dialog, char** value);
/*
    Purpose: Get the default button of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - The name of the default button. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRememberSize (char* dialog);
/*
    Purpose: Set the flag of the dialog to remember its size when it is
	     destroyed. So that when it is recreated again it sets to the
	     the same size. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogForgetSize (char* dialog);
/*
    Purpose: Set the flag of the dialog to not remember its size when it is
	     destroyed. So that when it is recreated again it does'nt set to
	     the same size. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRemembersSize (char* dialog, ProBoolean* state);
/*
    Purpose: Checks if the dialog remembers its old size.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
	state - PRO_B_TRUE when the dialog remembers its size.
		PRO_B_FALSE when the dialog does'nt remember its size.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogEnableResizing (char* dialog);
/*
    Purpose: Enable the dialog to resize.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUIDialogDisableResizing (char* dialog);
/*
    Purpose: Disable the dialog to resize.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUIDialogIsResizeable (char* dialog, ProBoolean* state);
/*
    Purpose: Checks if the dialog can be resize or not. 

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        state - PRO_B_TRUE if the dialog can be resize.
		PRO_B_FALSE if the dialog can not be resize.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogAttachLeft (char* dialog);
/*
    Purpose: To attach the dialog at left side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogUnattachLeft (char* dialog);
/*
    Purpose: To not attach the dialog at left side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogIsAttachedLeft (char* dialog, ProBoolean* state);
/*
    Purpose: To check if the  dialog is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the dialog          
                is attached at left. PRO_B_FALSE if the dialog is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogAttachRight (char* dialog);
/*
    Purpose: To attach the dialog at right side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogUnattachRight (char* dialog);
/*
    Purpose: To not attach the dialog at right side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogIsAttachedRight (char* dialog, ProBoolean* state);
/*
    Purpose: To check if the  dialog is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the dialog         
                is attached at right. PRO_B_FALSE if the dialog is not   
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogAttachTop (char* dialog);
/*
    Purpose: To attach the dialog at top side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogUnattachTop (char* dialog);
/*
    Purpose: To not attach the dialog at top side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogIsAttachedTop (char* dialog, ProBoolean* state);
/*
    Purpose: To check if the  dialog is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the dialog           
                is attached at top. PRO_B_FALSE if the dialog is not       
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogAttachBottom (char* dialog);
/*
    Purpose: To attach the dialog at bottom side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogUnattachBottom (char* dialog);
/*
    Purpose: To not attach the dialog at bottom side of the parent component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogIsAttachedBottom (char* dialog, ProBoolean* state);
/*
    Purpose: To check if the  dialog is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the dialog        
                is attached at bottom. PRO_B_FALSE if the dialog is not 
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogLeftoffsetSet (char* dialog, int value);
/*
    Purpose: Set left offset to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogLeftoffsetGet (char* dialog, int* value);
/*
    Purpose: Get left offset of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRightoffsetSet (char* dialog, int value);
/*
    Purpose: Set right offset to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogRightoffsetGet (char* dialog, int* value);
/*
    Purpose: Get right offset of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTopoffsetSet (char* dialog, int value);
/*
    Purpose: Set top offset to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogTopoffsetGet (char* dialog, int* value);
/*
    Purpose: Get top offset of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogBottomoffsetSet (char* dialog, int value);
/*
    Purpose: Set bottom offset to the dialog.

    Input Arguments:
        dialog - Name of the dialog.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogBottomoffsetGet (char* dialog, int* value);
/*
    Purpose: Get bottom offset of the dialog.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDialogHide (char* dialog);
/*
    Purpose: To iconify the dialog. This function should be used for a
 	secondary window when the primary window is being minimized.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUIDialogShow (char* dialog);
/*
    Purpose: To show the dialog. This function should be used for a
        secondary window when the primary window is being restored.

    Input Arguments:
        dialog - Name of the dialog.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUIDialogDestroynotifyActionSet (
    char           *dialog, 
    ProUIAction function,  
    ProAppData data);

/*
    Purpose: Set the function to be called when a component is about
	     to be destroyed.

    Input Arguments:
        dialog - Name of the dialog.
	function - Function to be called when a component is about 
		   to be destroyed.
	data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

 

extern ProError ProUIDialogPremanagenotifyActionSet (
    char           *dialog,
    ProUIAction function,
    ProAppData data);

/*
    Purpose: Set the function to be called when a component is about
	     to be managed.

    Input Arguments:
        dialog - Name of the dialog.
	function - Function to be called when a component is about 
		   to be managed.
	data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

 
extern ProError ProUIDialogPostmanagenotifyActionSet (
    char           *dialog,
    ProUIAction function,
    ProAppData data);

/*
    Purpose: Set the function to be called when a component has just
	     been managed.

    Input Arguments:
        dialog - Name of the dialog.
	function - Function to be called when a component has just 
		   been managed.
	data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUIDialogAboveactivewindowSet(char *dialog, ProBoolean above_active_window);
/*
    Purpose:  Sets the dialog to be always above the dialog which is the 
              current active Creo Parametric window. This allows the Creo Parametric TOOLKIT 
              application to ensure that their dialog does not end up behind 
              the Creo Parametric window during window opening and closing events.
    <P>
    Important Note:  If the Creo Parametric user changes the current active window, 
                     you must call this function again to set the dialog to be
                     above the current active Creo Parametric window.

    Input Arguments: 
         dialog              - The dialog.
         above_active_window - PRO_B_TRUE to set it to be above the current 
                               active window, PRO_B_FALSE to remove this 
                               setting.

    Output Arguments: 
         none

    Return Values:
         PRO_TK_NO_ERROR     - The function succeeded.
         PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
*/


extern ProError ProUIDialogAboveactivewindowGet(char *dialog, ProBoolean *above_active_window);
/*
    Purpose:  Checks if the dialog is going to be always above the dialog 
              which is the current active Creo Parametric window.

    Input Arguments: 
         dialog              - The dialog.

    Output Arguments: 
         above_active_window - PRO_B_TRUE if the dialog is above the current 
                               active window,PRO_B_FALSE otherwise.

    Return Values: 
         PRO_TK_NO_ERROR     - The function succeeded.
         PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
*/

extern ProError ProUIDialogMappedSet (
    char *dialog);
/*
   Purpose: Set the dialog to occupy space when invisible.     
 
   Input Arguments:
      dialog                - The name of the dialog
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully loaded and displayed
				the dialog
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->


*/

extern ProError ProUIDialogMappedUnset (
    char *dialog);
/*
   Purpose: Set the dialog not to occupy space when invisible.     
 
   Input Arguments:
      dialog                - The name of the dialog
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully loaded and displayed
				the dialog
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIDialogIsMapped (
    char *dialog, 
    ProBoolean *state);
/*
   Purpose: Checks if the dialog occupies any space when it is 
            invisible.    
 
   Input Arguments:
      dialog                - The name of the dialog
 
   Output Arguments:
      state                 - PRO_B_TRUE when dialog occupies space
                              when it is invisible;
                              PRO_B_FALSE when dialog does not occupy  
                              any space when it is invisible.
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully loaded and displayed
				the dialog
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUIDialogFocusSet(
    char* dialog_name,
    char* component);

/*
   Purpose:   Sets focus to dialog's component
 
   Input Arguments:
      dialog_name          - The name of the dialog
      component            - The name of the component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR      - The function was successful
      PRO_TK_BAD_INPUTS    - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - The function failed

   <!-- Objectname: ProUI -->

*/

typedef void *ProUITimerID;


typedef void (*ProUITimerAction)(
        char* dialog,
        ProUITimerID  timer_id,
        ProAppData appdata);

		
extern ProError ProUITimerCreate( 
    ProUITimerAction action,
    ProAppData       appdata,
    ProName          timer_name,
    ProUITimerID *   timer_id);

/*
    Purpose: 
        Adds a new Timer to Creo Parametric.  
        A Timer can be used to defer an action to a later stage.

	This function registers the Timer object, to be done only once 
        during a Creo Parametric session for each timer. 
        Subsequent calls to this function for previously registered timer
        name return an error.
	 
        See also ProUIDialogTimerStart()
		
        Note: This function can be used only in dll mode, otherwise its
              behavior is unpredictable.
	
    Input Arguments:
       action -     See ProUITimerAction type definition.
                    Note that the action callback does not return a value. 
                    The action is invoked only once per each call of
                    ProUIDialogTimerStart.
                    If the application wants to be called again, 
                    it should invoke ProUIDialogTimerStart again,
                    possibly from the action callback.
                    Note that you must not Activate/Open a dialog from this
                    action CB.
       appdata -    User data to be passed to the action function.
       timer_name - Name of timer.

    Output Arguments:
          timer_id - The id of the timer to be used with ProUIDialogTimerStart

    Return Values:
      PRO_TK_NO_ERROR       - The function successfully create a timer.
      PRO_TK_BAD_INPUTS     - One of the input arguments is not valid.
      PRO_TK_LINE_TOO_LONG  - The timer_name is longer than 32 Characters.
      PRO_TK_E_IN_USE       - The timer_name is in use.

*/
	
extern ProError ProUITimerDestroy(
    ProUITimerID     timer_id);

/*
    Purpose: 
        Destroys a timer added via ProUITimerCreate.
        After the timer is destroyed, its name is available for reuse.
        If the timer has been started, it is first stopped.
		
        Note: This function can be used only in dll mode, otherwise its
              behavior is unpredictable.
	
    Input Arguments:
       timer_id  - Id of timer, as output by ProUITimerCreate.

    Output Arguments:
       None

    Return Values:
      PRO_TK_NO_ERROR       - The function successfully create a timer.
      PRO_TK_BAD_INPUTS     - One of the input arguments is not valid.
      PRO_TK_E_NOT_FOUND    - The timer_id was not found.

*/

extern ProError ProUIDialogTimerStart(
    char*         dialog,
    ProUITimerID  timer_id,
    int           duration,
    ProBoolean    write_in_trail_file);

/*
    Purpose:
        Start the timer. After duration has passed (or longer), 
        Creo will invoke the ProUITimerAction callback registered 
        in ProUITimerCreate.
        You can call ProUIDialogTimerStart() again, from the ProUITimerAction.

        Note: This function can be used only in dll mode, otherwise its
              behavior is unpredictable.

    Input Arguments:
       dialog              - The name of the dialog, each dialog can have only 
                             one timer simultaneously.
       timer_id            - the timer_id from ProUITimerCreate().
       duration            - In milliseconds, minimal value is 100
       write_in_trail_file - controls if the timer action happing to 
                             be recorded in trail - Must be FALSE in Creo 2.
    Output Arguments:
        none

    Return Values:
      PRO_TK_NO_ERROR       - The function successfully start a timer.
      PRO_TK_BAD_INPUTS     - One of the input arguments is not valid.
      PRO_TK_E_IN_USE       - There is an activae timer for this dialog.
      PRO_TK_E_NOT_FOUND    - The timer_id was not found.
      PRO_TK_GENERAL_ERROR  - The function failed to start a timer.
*/


extern ProError ProUIDialogTimerStop (
    ProUITimerID  timer_id);

/*
    Purpose:
        Cancels the pending timer that was started.
    
        Note: This function can be used only in dll mode, otherwise its
              behavior is unpredictable.

    Input Arguments:
       timer_id            - the timer_id from ProUITimerCreate().
        
    Output Arguments:
        none

    Return Values:
      PRO_TK_NO_ERROR       - The function successfully canceled a timer.
      PRO_TK_BAD_INPUTS     - The timer_id is not valid.
      PRO_TK_E_NOT_FOUND    - The timer_id was not found.
      PRO_TK_GENERAL_ERROR  - Failed to cancel the timer.
*/

PRO_END_C_DECLS
 
#endif  /* PROUIDIALOG_H */
