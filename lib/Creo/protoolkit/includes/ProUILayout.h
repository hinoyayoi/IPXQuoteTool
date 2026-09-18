#ifndef PROUILAYOUT_H
#define PROUILAYOUT_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUILayoutHelptextSet(
    char*	dialog,
    char*	layout,
    wchar_t*	helptext);

/*
   Purpose:    Set the helptext of a layout component
 
   Input Arguments:
      dialog            - The name of the dialog that contains the layout
      layout            - The name of the layout component
      helptext          - The help text
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUILayoutTextSet(
    char*	dialog,
    char*	layout,
    wchar_t*	label);
 
/*
   Purpose:    Set the label for a layout component.
               If the layout is displayed in a tab, this function will not 
	       change the displayed tab header.  To set this property use
	       the function ProUITabLabelsSet().
 
   Input Arguments:
      dialog            - The name of the dialog that contains the layout
      layout            - The name of the layout component
      label             - The label
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed

   <!-- Objectname: ProUI -->

*/

extern ProError ProUILayoutEnable (
    char   *dialog,
    char   *component
);
/*

    Purpose: If decorated, causes the Layout to be drawn normally rather than
             as disabled.

    Input Arguments:
        dialog -           The name of the dialog containing the layout.
        component -        The layout name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/



extern ProError ProUILayoutDisable (
    char   *dialog,
    char   *component
);
/*

    Purpose: If decorated, causes the Layout to be drawn as disabled

    Input Arguments:
        dialog -           The name of the dialog containing the layout.
        component -        The layout name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUILayoutIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Determines if the Layout is being drawn as enabled.

    Input Arguments:
        dialog -           The name of the dialog containing the layout.
        component -        The layout name.

    Output Arguments:
        state -            Whether or not the layout is being drawn as enabled.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/

extern ProError ProUILayoutShow (
    char   *dialog,
    char   *component
);
/*

    Purpose: Makes the specified layout and all its contents visible.

    Input Arguments:
        dialog -           The name of the dialog containing the layout.
        component -        The layout name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUILayoutHide (
    char   *dialog,
    char   *component
);
/*

    Purpose: Makes the specified layout and all its contents invisible.

    Input Arguments:
        dialog -           The name of the dialog containing the layout.
        component -        The layout name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUILayoutIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*

    Purpose: Determines if the specified layout is visible.

    Input Arguments:
        dialog -           The name of the dialog containing the layout.
        component -        The layout name.

    Output Arguments:
        state -            Whether or not the layout is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/


extern ProError ProUILayoutPopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the layout.

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


extern ProError ProUILayoutPopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the layout.

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





extern ProError ProUILayoutCheckbuttonAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new checkbutton to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the checkbutton to be added.
        grid - Position of the checkbutton in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutDrawingareaAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new drawingarea to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the drawingarea to be added.
        grid - Position of the drawingarea in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutInputpanelAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new inputpanel to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the inputpanel to be added.
        grid - Position of the inputpanel in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutLabelAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new label to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the label to be added.
        grid - Position of the label in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutLayoutAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new layout to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the layout to be added.
        grid - Position of the layout in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutListAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new list to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the list to be added.
        grid - Position of the list in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutOptionmenuAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new optionmenu to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the optionmenu to be added.
        grid - Position of the optionmenu in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutProgressbarAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new progressbar to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the progressbar to be added.
        grid - Position of the progressbar in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutPushbuttonAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new pushbutton to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the pushbutton to be added.
        grid - Position of the pushbutton in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutRadiogroupAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new radiogroup to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the radiogroup to be added.
        grid - Position of the radiogroup in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSeparatorAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new separator to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the separator to be added.
        grid - Position of the separator in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSliderAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new slider to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the slider to be added.
        grid - Position of the slider in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSpinboxAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new spinbox to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the spinbox to be added.
        grid - Position of the spinbox in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTabAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new tab to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the tab to be added.
        grid - Position of the tab in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTableAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new table to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the table to be added.
        grid - Position of the table in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTextareaAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new textarea to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the textarea to be added.
        grid - Position of the textarea in the layout.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutThumbwheelAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new thumbwheel to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the thumbwheel to be added.
        grid - Position of the thumbwheel in the layout. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTreeAdd (char* dialog, char* component, char* name, ProUIGridopts* grid);
/*
    Purpose: Add a new tree to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the tree to be added.
        grid - Position of the tree in the layout.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutCheckbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the checkbutton from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutDrawingareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the drawingarea from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the drawingarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutInputpanelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the inputpanel from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the inputpanel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutLabelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the label from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the label to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutLayoutRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the layout from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the layout to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutListRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the list from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the list to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutOptionmenuRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the optionmenu from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the optionmenu to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutProgressbarRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the progressbar from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the progressbar to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutPushbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the pushbutton from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutRadiogroupRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the radiogroup from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSeparatorRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the separator from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the separator to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSliderRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the slider from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the slider to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSpinboxRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the spinbox from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the spinbox to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTabRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the tab from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the tab to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTableRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the table from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the table to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTextareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the textarea from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the textarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutThumbwheelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the thumbwheel from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the thumbwheel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTreeRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the tree from the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        name - The name of the tree to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
  Purpose: Sets the position of the layout with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the layout is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the layout used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the layout. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the layout's minimum size, the function will fail.
              The layout's minimum size can be retrieved
              using ProUILayoutMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the layout with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
	x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the layout with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the layout in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the layout. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.

    Output Arguments:
        width - Width value
        height - Height value

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUILayoutParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the layout component.

     Input Arguments:
         dialog - The name of the dialog that contains the layout.
         component - The name of the layout component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutChildnamesGet (char *dialog, char *component, int *count, char ***values);
/*
     Purpose: Get the name of the children to the layout component.

     Input Arguments:
         dialog - The name of the dialog that contains the layout.
         component - The name of the layout component.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUILayoutBitmapSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the bitmap to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutBitmapGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the bitmap of the layout.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.

    Output Arguments:
        value - The name of the bitmap. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the layout component.

    Input Arguments:
        dialog - The name of the dialog that contains layout.
        component - The name of the layout component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the layout at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the layout at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  layout is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the layout          
                is attached at left. PRO_B_FALSE if the layout is not
	        attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the layout at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the layout at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  layout is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the layout         
                is attached at right. PRO_B_FALSE if the layout is not
		attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the layout at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the layout at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  layout is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the layout           
                is attached at top. PRO_B_FALSE if the layout is not
		attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the layout at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the layout at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  layout is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the layout        
                is attached at bottom. PRO_B_FALSE if the layout is not 
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the layout.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUILayoutDecorate (
    char   *dialog, 
    char   *component);
/*
    Purpose: Set the layout to be decorated.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUILayoutUndecorate (
    char   *dialog, 
    char   *component);
/*
    Purpose: Set the layout to be undecorated.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUILayoutIsDecorated (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state
);
/*
    Purpose: Retrieves the layout's "decorated" flag.

    Input Arguments:
        dialog - The name of the dialog that contains the layout.
        component - The name of the layout component.

    Output Arguments:
        state - PRO_B_TRUE if the layout is decorated, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUILayoutTextGet(
    char*	dialog,
    char*	layout,
    wchar_t**	label);
 
/*
   Purpose:    Get the label for a layout component.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the layout
      layout            - The name of the layout component
      
   Output Arguments:
      label             - The label.  Free this using ProWstringFree.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUILayoutMappedSet (
    char*       dialog,
    char*       component);
/*
   Purpose: When the Layout is hidden or Shown via the ProUILayoutHide and
            ProUILayoutShow functions, causes the Layout to show or hide its
            content without changing the Layout's size.

   Input Arguments:
      dialog            - The name of the dialog that contains the layout
      component         - The name of the layout component

   Output Arguments:
      none
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUILayoutMappedUnset (
    char*       dialog,
    char*       component);
/*
   Purpose: When the Layout is hidden or Shown via the ProUILayoutHide and
            ProUILayoutShow functions, causes the Layout to collapse down to
            zero size or to expand to its nominal size.

   Input Arguments:
      dialog            - The name of the dialog that contains the layout
      component         - The name of the layout component

   Output Arguments:
      none
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUILayoutIsMapped (
    char*       dialog,
    char*       component,
    ProBoolean* state);
/*
   Purpose: Determines the state of the "mapped" flag.

   Input Arguments:
      dialog            - The name of the dialog that contains the layout
      component         - The name of the layout component

   Output Arguments:
      state - PRO_B_TRUE if the layout is mapped, PRO_B_FALSE otherwise.

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

PRO_END_C_DECLS
 
#endif  /* PROUILAYOUT_H */
