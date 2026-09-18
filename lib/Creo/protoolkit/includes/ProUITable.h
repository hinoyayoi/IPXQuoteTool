#ifndef PROUITABLE_H
#define PROUITABLE_H
#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

/*===========================================================================*\
 TABLE ATTRIBUTES
\*===========================================================================*/

extern ProError ProUITableRownamesSet (
    char       *dialog,
    char       *component,
    int         count,
    char      **values);

/*
    Purpose: Sets the name of the rows in the table.  
    <p>
             If adding new rows - labels must be assigned using 
	     ProUITableRowlabelsSet() or ProUITableRowLabelSet().
    </p>

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -             Number of items in the values array
        values -            Array of row names.  

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableRownamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*


    Purpose:  Gets the names of the rows in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -             Number of items in returned array
        values -            Array of row names allocated by the function.
	                    Use ProStringarrayFree() to release it.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableRowlabelsSet (
    char       *dialog,
    char       *component,
    int         count,
    wchar_t   **values);
/*
    Purpose:  Sets the names of the user-visible row labels in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array.  This must 
	                    match the number of row names in the table.	
        values -           Array of row labels. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowlabelsGet (
    char       *dialog,
    char       *component,
    int        *count,
    wchar_t  ***values);
/*
    Purpose: Gets the names of the user-visible row labels in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -            Number of items in returned array
        values -           Array of row labels allocated by the function.
	                   Use ProWstringarrayFree() to release it.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnnamesSet (
    char       *dialog,
    char       *component,
    int         count,
    char      **values);
/*
    Purpose:  Sets the names of the columns in the table.

    <p>
             If adding new columns - labels must be assigned using 
	     ProUITableColumnlabelsSet() or ProUITableColumnLabelSet().
    </p>


    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array
        values -           Array of column names. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnnamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose:  Gets the names of the columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -             Number of items in returned array
        values -             Array of column names allocated by the function.
	                    Use ProStringarrayFree() to release it.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnlabelsSet (
    char       *dialog,
    char       *component,
    int         count,
    wchar_t   **values);
/*
    Purpose:  Sets the user-visible labels of the columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array.  This must 
	                   match the number of column names in the table.
        values -           Array of column labels.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnlabelsGet (
    char       *dialog,
    char       *component,
    int        *count,
    wchar_t  ***values);
/*
    Purpose:  Gets the user-visible labels of the columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -             Number of items in returned array
        values -             Array of column labels allocated by the function.
                            Use ProWstringarrayFree() to release it.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnwidthsSet (
    char       *dialog,
    char       *component,
    int         count,
    int        *values);
/*
    Purpose:  Sets the widths of the columns in the table, in characters.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array
        values -           Array of column widths.            

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUITableColumnresizingsSet (
    char       *dialog,
    char       *component,
    int         count,
    int        *values);
/*


    Purpose:  Sets the resizing policies of the columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array
        values -           Array of resizing factors.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableLockedcolumnsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
    Purpose:  Sets the number of columns to repeat at the left of the table while scrolling.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The number of columns.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableLockedrowsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
    Purpose: Sets the number of rows to repeat at the top of the table while scrolling.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The number of rows.  This should not include 
	                   the title row.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableSelectednamesSet (
    char       *dialog,
    char       *component,
    int         count,
    char      **values);
/*
    Purpose:  Sets the selected cells in the table.  

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array
        values -           Array of selected names.  This array should consist of (2 * the number of selections), organized in pairs:
    <UL>
	<LI><P>element [0, 2, 4...] = row name of the selected cell </P>
	<LI><P>element [1, 3, 5...] = column name of the selected cell </P>
   </UL>

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableSelectednamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose: Gets the selected cells in the table.  This array should consist of (2 * the number of selections), organized in pairs:
    <UL>
	<LI><P>element [0, 2, 4...] = row name of the selected cell </P>
	<LI><P>element [1, 3, 5...] = column name of the selected cell </P>
   </UL>

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -             Number of items in returned array
        values -            Array of selected names allocated by the function.
	                    Use ProStringarrayFree() to release it.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableSelectedcolumnnamesSet (
    char       *dialog,
    char       *component,
    int         count,
    char      **values);
/*
    Purpose: Sets the selected columns in the table. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array
        values -           Array of selected column names. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableSelectedcolumnnamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose: Gets the selected columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -             Number of items in returned array
        values -            Array of selected column names allocated by the 
	                    function.  Use ProStringarrayFree() to release it.


    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableSelectionpolicySet (
    char       *dialog,
    char       *component,
    ProUISelectionpolicy  value);
/*
    Purpose:  Sets the table selection policy.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The table selection policy:
<UL>
	<LI><P>PROUISELPOLICY_NONE = Do not allow item selection. </P>
	<LI><P>PROUISELPOLICY_SINGLE = Select 0 or 1 items. </P>
	<LI><P>PROUISELPOLICY_BROWSE = Always select exactly 1 item. </P>
	<LI><P>PROUISELPOLICY_MULTIPLE = Select any number of items. </P>
	<LI><P>PROUISELPOLICY_EXTENDED = Select any number of items, including ranges of items. </P>
</UL>

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnselectionpolicySet (
    char       *dialog,
    char       *component,
    ProUISelectionpolicy     value);
/*
    Purpose: Sets the table column selection policy.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The table column selection policy:
<UL>
	<LI><P>PROUISELPOLICY_NONE = Do not allow column selection. </P>
	<LI><P>PROUISELPOLICY_SINGLE = Select 0 or 1 columns. </P>
	<LI><P>PROUISELPOLICY_BROWSE = Always select exactly 1 column. </P>
	<LI><P>PROUISELPOLICY_MULTIPLE = Select any number of columns. </P>
	<LI><P>PROUISELPOLICY_EXTENDED = Select any number of columns, including ranges of columns. </P>
</UL>

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableHelptextSet (
    char       *dialog,
    char       *component,
    wchar_t    *value);
/*
    Purpose:  Sets the helptext for the table.  This will be used by all 
              elements of the table except for cells assigned a helptext 
	      value using ProUITableCellHelptextStringSet().

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The help text for the table component.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUITableColumnsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
    Purpose:  Sets the width of the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The table width, in characters.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnsGet (
    char       *dialog,
    char       *component,
    int        *value);
/*
    Purpose:  Gets the width of the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        value -            The table width, in characters.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableMincolumnsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
    Purpose:  Sets the minimum width of the table. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The width, in characters.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUITableVisiblerowsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
    Purpose: Sets the number of rows visible in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The number of rows.  This number should >= 1 (where
	                   1 is the title row).

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableMinrowsSet (
    char       *dialog,
    char       *component,
    int         value);
/*
    Purpose:  Sets the minimum number of rows to display in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The number of rows.  This value should not include
	                   the title row.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableAutohighlightEnable (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Turns on autohighlighting of rows when cells are selected.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableAutohighlightDisable (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Turns off autohighlighting of rows when cells are selected.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableIsAutohighlightEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose:  Identifies whether or not autohighlighting is enabled in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        state -            PRO_B_TRUE is autohighlighting is enabled, 
	                   PRO_B_FALSE if it is not.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableTruncatelabelSet (
    char       *dialog,
    char       *component,
    ProBoolean  value);
/*
    Purpose: Identifies whether or not to truncate the label in a newly 
             created cell based on the cell width.  

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        value -            The setting for new cells: PRO_B_TRUE = truncate the
	                   new labels, PRO_B_FALSE = do not truncate the new 
			   label.  This setting does not affect existing cells.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableShow (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Causes the table to be visible.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableHide()
	PrOUITableIsVisible()
*/


extern ProError ProUITableHide (
    char   *dialog,
    char   *component
);
/*
    Purpose: Causes the table to be invisible.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableShow()
	PrOUITableIsVisible()
*/


extern ProError ProUITableIsVisible (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*


    Purpose:

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        state -            Whether or not the table is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableEnable (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the table to be sensitive to user input.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableDisable()
	ProUITableIsEnabled()
*/


extern ProError ProUITableDisable (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the table to be insensitive to user input.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableEnable()
	ProUITableIsEnabled()
*/


extern ProError ProUITableIsEnabled (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose:  Determines whether or not the table is sensitive to user input. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        state -            Whether or not the table is sensitive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableEnable()
	ProUITableDisable()
*/


extern ProError ProUITableComponentCopy (
    char       *dialog,
    char       *component,
    char       *source_device,
    char       *source_component,
    char       *name);
/*
    Purpose:  Copies a predefined component and places it in the table.  
              The component will not be displayed until it is assigned to a 
              table cell using ProUITableCellComponentNameSet().  However, you
              can update the component's properties as needed and display it 
              at a later time.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
	source_device -    The name of the dialog from which to copy the 
                           component.
	source_component - The name of the component to copy.
	name -             The name for the copied component in the table.

    Output Arguments:
        None.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableCellComponentNameSet()
        ProUITableCellComponentCopy()
	ProUITableComponentDelete()
*/


extern ProError ProUITableComponentDelete (
    char       *dialog,
    char       *component,
    char       *name);
/*
    Purpose:  Deletes a component from the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
	name -             The name of the component in the table.

    Output Arguments:
        None.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
	ProUITableComponentCopy()
*/


/*===========================================================================*\
 TABLE CELLS
\*===========================================================================*/


extern ProError ProUITableCellLabelSet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    wchar_t    *label);
/*
    Purpose:  Sets the text contained in the table cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.
        label -            The cell label string.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableCellLabelGet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    wchar_t   **label);
/*
    Purpose:  Gets the text contained in the table cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        label -            The cell label string, allocated by the function.
                           Use ProWstringFree to release it.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUITableCellHelpTextSet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    wchar_t    *help_text);
/*
    Purpose: Sets the help text for the table cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.
        help_text -        The cell help text.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUITableIsCellSensitive (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    ProBoolean *state);
/*
    Purpose: Determines if the table cell is sensitive to user input.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        state -            Whether or not the cell is sensitive to user input.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableCellEnable (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column);
/*
    Purpose:  Sets the table cell to be sensitive to user input.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableCellDisable (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column);
/*
    Purpose: Sets the table cell to be insensitive to user input.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableCellComponentNameSet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    char       *name);
/*
    Purpose: Sets the component name contained in the table cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.
        name -             The name of the component contained in the cell.  

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableCellComponentNameGet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    char      **name);
/*
    Purpose:  Gets the component name contained in the table cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        name -             The name of the component contained in the cell.  
	                   Use ProStringFree to release this string.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableCellComponentCopy (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column,
    char       *source_device,
    char       *source_component,
    char       *name);
/*
    Purpose:  Copies a predefined component and places it in the table in the 
              designated cell. The component will be displayed in this cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The row containing the target cell.
	column -           The column containing the target cell.
	source_device -    The name of the dialog from which to copy the 
                           component.
	source_component - The name of the component to copy.
	name -             The name for the copied component in the table.

    Output Arguments:
        None.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    See Also:
        ProUITableCellComponentDelete()
        ProUITableComponentCopy()
*/


extern ProError ProUITableCellComponentDelete (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column);
/*
    Purpose: Removes the component contained in the table cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableAnchorCellSet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column);
/*
    Purpose: Sets the coordinates of the table selection anchor cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableAnchorCellGet (
    char       *dialog,
    char       *component,
    char      **row,
    char      **column);
/*
    Purpose:  Gets the coordinates of the table selection anchor cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        row -              The table row name.  Use ProStringFree to release this string.
        column -           The table column name. Use ProStringFree to release this string.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableFocusCellSet (
    char       *dialog,
    char       *component,
    char       *row,
    char       *column);
/*
    Purpose: Sets the coordinates of the table selection focus cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        column -           The table column name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableFocusCellGet (
    char       *dialog,
    char       *component,
    char      **row,
    char      **column);
/*
    Purpose:  Gets the coordinates of the table selection focus cell.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        row -              The table row name. Use ProStringFree to release this string.
        column -           The table column name. Use ProStringFree to release this string.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


/*===========================================================================*\
 TABLE ROWS
\*===========================================================================*/

extern ProError ProUITableRowIndexGet (
    char       *dialog,
    char       *component,
    char       *row,
    int        *index);
/*
    Purpose:  Gets the index of the table row with the given name.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.

    Output Arguments:
        index -            The table row index.  The indices start at 0.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowRename (
    char       *dialog,
    char       *component,
    char       *row,
    char       *name);
/*
    Purpose: Renames the table row.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        name -             The new name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowLabelSet (
    char       *dialog,
    char       *component,
    char       *row,
    wchar_t    *label);
/*
    Purpose:  Sets the user-visible label for the table row.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        label -            The new row label.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowLabelGet (
    char       *dialog,
    char       *component,
    char       *row,
    wchar_t   **label);
/*
    Purpose:  Gets the user-visible label for the table row.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.

    Output Arguments:
        label -            The row name.  Use ProWstringFree to release this string.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowsInsert (
    char       *dialog,
    char       *component,
    char       *row,
    int         count,
    char      **names);
/*
    Purpose:  Inserts one or more new rows into the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.  The new rows will be inserted 
	                   after this row.  If NULL, new rows will be inserted 
			   at the top of the table.
        count -            Number of items in the names array
        names -            Array of new row names.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowsDelete (
    char       *dialog,
    char       *component,
    int         count,
    char      **names);
/*
    Purpose:  Deletes one or more rows from the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the names array
        names -            Array of row names to delete.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowCellsSelect (
    char       *dialog,
    char       *component,
    int         count,
    char      **names);
/*
    Purpose:  Selects the cells of the given rows of the table.
    <p>
    NOTE: The table selection policy must be either Multiple or Extended.
    </p>

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the names array
        names -            Names of the rows to select. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowCellsDeselect (
    char       *dialog,
    char       *component,
    int         count,
    char      **names);
/*
    Purpose:  Deselect the cells of the given rows of the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the names array
        names -            Names of the rows to deselect. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableRowCellLabelsSet (
    char       *dialog,
    char       *component,
    char       *row,
    wchar_t    *labels);
/*
    Purpose:  Sets the contents of the cells of the rows using a single string.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        row -              The table row name.
        labels -           String to use when setting the labels in the row.  
	                   Use the tab character to separate individual 
			   labels into the separate columns.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

/*===========================================================================*\
 TABLE COLUMNS
\*===========================================================================*/

extern ProError ProUITableColumnIndexGet (
    char       *dialog,
    char       *component,
    char       *column,
    int        *index);
/*
    Purpose: Gets the column index for a given column.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.

    Output Arguments:
        index -            The table column index.  The indices start at 0.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnRename (
    char       *dialog,
    char       *component,
    char       *column,
    char       *name);
/*
    Purpose:  Renames a table column.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.
        name -             The new name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnLabelSet (
    char       *dialog,
    char       *component,
    char       *column,
    wchar_t    *label);
/*
    Purpose:  Sets the user visible label for the column.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.
        label -            The new column label.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnLabelGet (
    char       *dialog,
    char       *component,
    char       *column,
    wchar_t   **label);
/*
    Purpose:  Gets the user-visible label for the column.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.

    Output Arguments:
        label -            The column label. Use ProWstringFree to release this string.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/




extern ProError ProUITableColumnWidthSet (
    char       *dialog,
    char       *component,
    char       *column,
    int         width);
/*
    Purpose:  Sets the width of the column in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.
        width -            The new column width.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnWidthGet (
    char       *dialog,
    char       *component,
    char       *column,
    int        *width);
/*
    Purpose:  Gets the width of the column in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.

    Output Arguments:
        width -            The column width, in characters.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnResizingFactorSet (
    char       *dialog,
    char       *component,
    char       *column,
    int         resizing);
/*
    Purpose:   Sets the resizing factor of the column in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.
        resizing -         The new resizing factor.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/



extern ProError ProUITableColumnResizingFactorGet (
    char       *dialog,
    char       *component,
    char       *column,
    int        *resizing);
/*
    Purpose:  Gets the resizing factor of the column in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.

    Output Arguments:
        resizing -         The column resizing factor.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnsInsert (
    char       *dialog,
    char       *component,
    char       *column,
    int         count,
    char      **names);
/*
    Purpose:  Inserts one or more columns into the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.  The new columns will be 
	                   inserted after this column.
        count -            Number of items in the names array
        names -            Array of new column names to insert.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnsDelete (
    char       *dialog,
    char       *component,
    int         count,
    char      **names);
/*
    Purpose:  Deletes one or more columns from the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the names array
        names -            Array of column names to delete.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnCellsSelect (
    char       *dialog,
    char       *component,
    int         count,
    char      **names);
/*
    Purpose:  Selects the cells of the given columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the names array
        names -            Array of column names to select. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableColumnCellsDeselect (
    char       *dialog,
    char       *component,
    int         count,
    char      **names);
/*
    Purpose: Deselects the cells of the given columns in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the names array
        names -            Array of column names to deselect.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableResetColumnWidth (
    char       *dialog,
    char       *component,
    char       *column);
/*
    Purpose:  Sets the column width to the default.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        column -           The table column name.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

/*===========================================================================*\
 TABLE ACTIONS
\*===========================================================================*/

extern ProError ProUITableArmActionSet (
    char         *dialog,
    char         *component,
    ProUIAction  callback,
    ProAppData  data);
/*
    Purpose: Sets the arm action for a table. This function is called 
                when the user changes the selection anchor cell and focus cell
		in the table. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -         The action function.
        data -             Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableDisarmActionSet (
    char         *dialog,
    char         *component,
    ProUIAction  callback,
    ProAppData  data);
/*
    Purpose: Sets the disarm action for a table. This function is called 
                when the user changes the selection focus cell in the table. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -          The action function.
        data -          Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableSelectActionSet (
    char         *dialog,
    char         *component,
    ProUIAction  callback,
    ProAppData  data);
/*
    Purpose: Sets the select action for a table. This function is called 
                when the user changes the selected cells in the table. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -          The action function.
        data -          Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableActivateActionSet (
    char         *dialog,
    char         *component,
    ProUIAction  callback,
    ProAppData  data);
/*
    Purpose: Sets the activate action for a table. This function is called 
                when the user presses the return key or double-clicks the 
		left mouse button in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -          The action function.
        data -          Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableFocusinActionSet (
    char         *dialog,
    char         *component,
    ProUIAction  callback,
    ProAppData  data);
/*
    Purpose: Sets the focus in action for a table. This function is called 
                when the user when the user moves the cursor onto the table
		using the mouse or [TAB] key.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -          The action function.
        data -          Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUITableFocusoutActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData  data);
/*
    Purpose: Sets the focus out action for a table. This function is called 
                when the user when the user moves the cursor off of the table
		using the mouse or [TAB] key.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -         The action function.
        data -             Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableColumnselectActionSet (
    char         *dialog,
    char         *component,
    ProUIAction   callback,
    ProAppData  data);
/*
    Purpose: Sets the column selection action for the table. This function is 
                called  when the user changes the currently selected table
		columns.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        callback -         The action function.
        data -             Data to be passed to callback function

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITablePopupmenuSet (
    char       *dialog,
    char       *component,
    char       *value);
/*
    Purpose:  Sets the name of the popup menu for the table.

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


extern ProError ProUITablePopupmenuGet (
    char       *dialog,
    char       *component,
    char      **value);
/*
    Purpose: Gets the name of the popup menu for the table.

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



extern ProError ProUITableCheckbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new checkbutton to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the checkbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableDrawingareaAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new drawingarea to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the drawingarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableInputpanelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new inputpanel to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the inputpanel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLabelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new label to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLayoutAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new layout to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the layout to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableListAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new list to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the list to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableOptionmenuAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new optionmenu to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the optionmenu to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableProgressbarAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new progressbar to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the progressbar to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITablePushbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new pushbutton to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the pushbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableRadiogroupAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new radiogroup to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the radiogroup to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSliderAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new slider to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the slider to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSpinboxAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new spinbox to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the spinbox to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTabAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new tab to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the tab to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTableAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new table to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the table to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTextareaAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new textarea to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the textarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableThumbwheelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new thumbwheel to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the thumbwheel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTreeAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new tree to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the tree to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCheckbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the checkbutton from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableDrawingareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the drawingarea from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the drawingarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableInputpanelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the inputpanel from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the inputpanel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLabelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the label from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the label to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLayoutRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the layout from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the layout to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableListRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the list from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the list to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableOptionmenuRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the optionmenu from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the optionmenu to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableProgressbarRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the progressbar from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the progressbar to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITablePushbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the pushbutton from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableRadiogroupRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the radiogroup from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSliderRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the slider from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the slider to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSpinboxRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the spinbox from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the spinbox to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTabRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the tab from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the tab to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTableRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the table from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the table to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTextareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the textarea from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the textarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableThumbwheelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the thumbwheel from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the thumbwheel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTreeRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the tree from the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        name - Name of the tree to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the table with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the table is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the table used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the table. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the table's minimum size, the function will fail.
              The table's minimum size can be retrieved
              using ProUITableMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains table.
        component - The name of the table component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITablePositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the table with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITablePositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the table with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the table in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the table. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.

    Output Arguments:
        width - Width value.
        height - Height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCellHelptextStringGet (char* dialog, char* component, char* row, char* column, wchar_t** help_text);
/*
    Purpose: Get the help-text that is displayed while the cursor is over the 
             table cell.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        row - Row of the table.
        column - Column of the table.

    Output Arguments:
        help_text - Help text displayed. Free this using ProWstringFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCellHelptextStringSet (char* dialog, char* component, char* row, char* column, wchar_t* help_text);
/*
    Purpose: Set the help-text to be displayed when the cursor is over the 
             table cell.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        row - Row of the table.
        column - Column of the table.
        help_text - Help text to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCellForegroundColorGet (char* dialog, char* component, char* row, char* column, ProUIColor* color);
/*
    Purpose: Get the foreground color of the table cell.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        row - Row of the table.
        column - Column of the table.

    Output Arguments:
        color - foreground color of the cell.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCellForegroundColorSet (char* dialog, char* component, char* row, char* column, ProUIColor color);
/*
    Purpose: Set the foreground color of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        row - Row of the table.
        column - Column of the table.
        color - foreground color of the cell.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCellBackgroundColorGet (char* dialog, char* component, char* row, char* column, ProUIColor* color);
/*
    Purpose: Get the background color of the table cell.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        row - Row of the table.
        column - Column of the table.

    Output Arguments:
        color - background color of the cell.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableCellBackgroundColorSet (char* dialog, char* component, char* row, char* column, ProUIColor color);
/*
    Purpose: Set the background color of the table cell.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The table name.
        row - Row of the table.
        column - Column of the table.
        color - background color of the cell.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITableParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the table component.

     Input Arguments:
         dialog - The name of the dialog that contains the table.
         component - The name of the table component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableChildnamesGet (char *dialog, char *component, int *count, char ***values);
/*
     Purpose: Get the name of the children to the table component.

     Input Arguments:
         dialog - The name of the dialog that contains the table.
         component - The name of the table component.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError ProUITableColumnwidthsGet (char* dialog, char* component, int* count, int** values);
/*
    Purpose: Get the width of all columns in the table in character widths.
	     If the width is not set, then the default width is used. 

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        count - Number of columns.
        values - Array of column width values.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITableDefaultcolumnwidthSet()
	ProUITableDefaultcolumnwidthGet()

*/

extern ProError ProUITableColumnresizingsGet (char* dialog, char* component, int* count, int** values);
/*
    Purpose: Get the resizing factor of all the columns in the tabel. The
	     default value is 0.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        count - Number of columns.
        values - Array of resizing factor for all the columns.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableDefaultcolumnwidthSet (char* dialog, char* component, int value);
/*
    Purpose: Set the default column width of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - Default width of the column.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableDefaultcolumnwidthGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the default column width of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Default width of the column.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLockedcolumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of locked columns in the table. Width of the 
	     locked columns can not be changed.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Number of locked columns.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLockedrowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of locked rows in the table. Height of the 
	     locked rows can not be changed.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Number of locked rows.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableColumnselectionpolicyGet (char* dialog, char* component, ProUISelectionpolicy* value);
/*
    Purpose: Get the selection policy of the column in the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Selection policy of the table.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over
	     the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableMincolumnsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum width of the column in the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Minimum width of the column.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableVisiblerowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of visible rows in the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Number of visible rows.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableMinrowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the minimum height of the row in the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Minimum height of the row.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableUseScrollbarswhenNeeded (char* dialog, char* component);
/*
    Purpose: Set the table to use scrollbar only when the total row 
	     height and column width of the table is greater than 
	     height and column of the table respectively.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAlwaysUsescrollBars (char* dialog, char* component);
/*
    Purpose: Set the table to use scrollbar always. 

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITableUsesScrollbarswhenneeded (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the table uses scrollbar or not.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        state - PRO_B_TRUE when the table uses scrollbar only when needed.
		PRO_B_FALSE when the table use scrollbar always.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITableAlignmentSet (char* dialog, char* component, int value);
/*
    Purpose: Set the given value to align the text in the row and column
	     header label of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - alignment value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAlignmentGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the value used to align the text in the row and column
	     header label of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - alignment value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableShowgridSet (char* dialog, char* component, ProBoolean value);
/*
    Purpose: Set the table to show or hide the grid based on the given 
	     value.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - PRO_B_TRUE to show the grid. PRO_B_FALSE to hide the grid.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableShowgridGet (char* dialog, char* component, ProBoolean* value);
/*
    Purpose: Get the flag to know if the grid of the table is shown or
	     hidden.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - PRO_B_TRUE if the grid is shown. PRO_B_FALSE if the grid
	        is hidden.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTruncatelabelGet (char* dialog, char* component, ProBoolean* value);
/*
    Purpose: Get the flag to know if the label in the cell is truncated
	     or not.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - PRO_B_TRUE if the label is truncated. PRO_B_FALSE if the
		label is not truncated.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableActivateonreturnEnable (char* dialog, char* component);
/*
    Purpose: Set the table to generate "activate action" when the user
	press the RETURN key.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
	ProUITableActivateActionSet()

*/

extern ProError ProUITableActivateonreturnDisable (char* dialog, char* component);
/*
    Purpose: Set the table to press the default button when the user
	press the RETURN key.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableIsActivateonreturnEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the user RETURN key press will generate the 
	     "activate action" or set the default button to be pressed.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        state - PRO_B_TRUE if the RETURN key press generates "activate action"
		PRO_B_FALSE if the RETURN key press set the default button to
		be pressed.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the table at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the table at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  table is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the table           
                is attached at left. PRO_B_FALSE if the table is not       
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the table at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the table at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  table is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the table          
                is attached at right. PRO_B_FALSE if the table is not     
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the table at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the table at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  table is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the table            
                is attached at top. PRO_B_FALSE if the table is not         
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the table at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the table at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  table is attached at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the table         
                is attached at bottom. PRO_B_FALSE if the table is not   
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSelectionpolicyGet (
    char                   *dialog,
    char                   *component,
    ProUISelectionpolicy   *value);

/*
    Purpose: Get selection policy of the table.

    Input Arguments:
        dialog - The name of the dialog that contains the table.
        component - The name of the table component.

    Output Arguments:
        value - Selection policy of the table.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITableSelectedrownamesSet (
    char       *dialog,
    char       *component,
    int         count,
    char      **values);
/*
    Purpose: Sets the selected rows in the table. 

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.
        count -            Number of items in the values array
        values -           Array of selected row names. 

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUITableSelectedrownamesGet (
    char       *dialog,
    char       *component,
    int        *count,
    char     ***values);
/*
    Purpose: Gets the selected rows in the table.

    Input Arguments:
        dialog -           The name of the dialog that contains the table.
        component -        The table name.

    Output Arguments:
        count -             Number of items in returned array
        values -            Array of selected row names allocated by the 
	                    function.  Use ProStringarrayFree() to release it.


    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

PRO_END_C_DECLS
 
#endif /* PROUITABLE_H */
