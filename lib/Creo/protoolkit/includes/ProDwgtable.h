#ifndef PRODRWTABLE_H
#define PRODRWTABLE_H 
			

#include <ProANSI.h>
#include <ProObjects.h>
#include <ProDrawing.h>
#include <ProDtlitem.h>
#include <ProWstring.h>
#include <ProDtlnote.h>

PRO_BEGIN_C_DECLS

typedef struct pro_draw_table *ProDwgtabledata;
typedef struct prodrw_tbl_info ProDwgtableInfo;

typedef enum
{
    PRODWGTABLESIZE_CHARACTERS,
    PRODWGTABLESIZE_SCREEN,
    PRODWGTABLESIZE_CHARS_TRUE
} ProDwgtableSizetype;

typedef enum
{
    PROHORZJUST_LEFT,
    PROHORZJUST_CENTER,
    PROHORZJUST_RIGHT
} ProHorzJust;

typedef enum
{
    PROVERTJUST_TOP,
    PROVERTJUST_MIDDLE,
    PROVERTJUST_BOTTOM
} ProVertJust;

typedef enum
{
    PRODWGTABLEFORMAT_TBL,
    PRODWGTABLEFORMAT_TXT,
    PRODWGTABLEFORMAT_CSV
} ProDwgtableFormattype;

typedef enum 
{
	PRODWGTABLEGROWTHDIR_DOWNRIGHT = 0,  
	PRODWGTABLEGROWTHDIR_DOWNLEFT,      
	PRODWGTABLEGROWTHDIR_UPRIGHT,      
	PRODWGTABLEGROWTHDIR_UPLEFT       
}ProDwgtableGrowthdirType;

typedef enum
{
  PRODWGTBLROWHEIGHT_AUTOADJUST_FALSE = 0,
  PRODWGTBLROWHEIGHT_AUTOADJUST_TRUE,
  PRODWGTBLROWHEIGHT_AUTOADJUST_TRUE_LEGACY
} ProDwgtableRowheightAutoadjusttype;

typedef ProError (*ProDwgtableVisitAction)(
                  ProDwgtable *table,
                  ProError    filter_status,
                  ProAppData  data);
/*

Purpose: 
       The action function called for each drawing table entity during 
       the call to ProDrawingTableVisit().

Input Arguments:
       table         -  Drawing table to be visited
       filter_status -  Return value from filter action function
       data          -  Application data passed to function 
                        ProDrawingTableVisit().
        
Output Arguments:
        None

Return Values:
        PRO_TK_NO_ERROR - Continue visiting drawing tables.
        Other           - Stop visiting drawing tables.

*/

typedef ProError (*ProDwgtableFilterAction)(
                   ProDwgtable *table,
                   ProAppData  data);

/*

Purpose: The filter function called for each drawing table entity during the 
         call to function ProDrawingTableVisit().

Input Arguments:
        table      -  Drawing table to be filtered
        data       -  Application data passed to function 
                      ProDrawingTableVisit().
        
Output Arguments:
        None

Return Values:
        PRO_TK_CONTINUE - Skip visiting this drawing table and go to the next.
        Other           - Call the visit action for this drawing table. The 
                          return value is passed as input to the visit action.

*/


typedef enum{
    PRODWGTABLE_NORMAL  =  1,
    PRODWGTABLE_FULL    =  2
} ProParamMode;


extern ProError ProDwgtabledataAlloc (
    ProDwgtabledata *data);
/*  
    Purpose:
	Allocated memory for ProDwgtabledata structure
    Input Arguments:
	None
    Output Arguments:
	data - pointer to the ProDwgtabledata structure
    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDwgtableSegMove (ProDwgtable *p_table,
                                    int segment,
                                    ProVector new_pos,
                                    ProBoolean display);

/*  
    Purpose:
	This function moves a table segment and optionally displays it in the
        new position.

    Input Arguments:
	p_table - The table whose segment you want to move
        segment - The ID of the segment you want to move (or -1 for a one-
                 segment table)
        new_pos - where you want to put the origin of the table, in world units
        display - whether to show the table in the new position.

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_BAD_INPUTS    - The table could not be moved.
        PRO_TK_BAD_CONTEXT   - A -1 segment ID was used for a multiple segment
                               table.
*/

extern ProError ProDwgtableSegCount (ProDwgtable *p_table,
                                     int *n_segs);

/* 
   Purpose: To determine how many segments a table has.

   Input Arguments:
       p_table - The table in question.

   Output Arguments:
       n_segs -  How many segments it has (-1 if there is an error).

   Return Values:
       PRO_TK_NO_ERROR   - The query succeeded.
       PRO_TK_BAD_INPUTS - The query did not succeed.

*/       

extern ProError ProDwgtableSegSheetGet (ProDwgtable *p_table,
                                        int segment,
                                        int *sheet);

/* 
   Purpose: To determine upon which sheet a table segment lies.

   Input Arguments:
       p_table  - The table in question.
       segment  - The segment ID you want to check (or -1 for a one seg. table).
       

   Output Arguments:
       sheet  - The sheet upon which the segment lies.

   Return Values:
       PRO_TK_NO_ERROR    - The query was successful.
       PRO_TK_BAD_INPUTS  - The table or segment did not exist.
       PRO_TK_BAD_CONTEXT - A -1 segment ID was used for a multiple segment
                            table.

*/
extern ProError ProDwgtabledataOriginSet (
    ProDwgtabledata data,
    ProPoint3d      origin);
/*
    Purpose:  Set the origin in the specified ProDwgtabledata structure

    Input Arguments:
		data - ProDwgtabledata structure
		origin - The origin for the table placement.

    Output Arguments:
		none

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDwgtabledataSizetypeSet (
    ProDwgtabledata     data,
    ProDwgtableSizetype size_type);
/*  
    Purpose:
	Setup sizetype in the given ProDwgtabledata structure

    Input Arguments:
	data       -  ProDwgtabledata structure
	size_type  -  size type

    Output Arguments:
	none

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDwgtabledataColumnsSet (
    ProDwgtabledata data,
    int             n_columns,
    double          *widths,
    ProHorzJust     *justifications);
/*  
    Purpose:
	Setup column properties

    Input Arguments:
	data           - The ProDwgtabledata structure
        n_columns      - Number of columns. The maximum number of
                         columns that can be specified is 50.
        widths         - Column width
        justifications - Justifications

    Output Arguments:
	none

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_BAD_INPUTS    - Bad input argument 
*/
extern ProError ProDwgtabledataRowsSet (
    ProDwgtabledata data,
    int             n_rows,
    double          *heights);
/*  
    Purpose:
	Setup rows properties

    Input Arguments:
	data          - The ProDwgtabledata structure
        n_rows        - Number of rows. The maximum number of
                        rows that can be specified is 100. 
        heights       - Row height 

    Output Arguments:
	none

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_BAD_INPUTS    - Bad input argument 
*/

extern ProError ProDrawingTableCreate (
    ProDrawing      drawing,   
    ProDwgtabledata table_data, 
    int             display,
    ProDwgtable     *table);
/*  
    Purpose: 
	Creates a table in an existing drawing. The function creates the 
	table on the current sheet.

    Input Arguments:
	drawing    - The drawing
	table_data - The table data
        display    - Boolean flag that specifies whether or not the table is to
                     be displayed after creation.  If display==TRUE, then the 
                     table is displayed (behavior as in releases prior to
                     Release 20). If display==FALSE, then the table is not
                     displayed.


    Output Arguments:
        table      - the table

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDwgtableTextEnter (
    ProDwgtable *table,
    int         column,
    int         row,
    ProWstring  *lines);
/*   
     Purpose: 
	Adds the specified lines of text into the appropriate column and row 
	of the table. Note that more than one line of text may be written 
        into a cell. If a line of text is too wide for the cell (too many 
        characters), the text overlaps the neighboring cells.

    Input Arguments:
	table   - The identifier of the table to which to add
		  the text for the cell.
	column  - The column number of the cell. The column
	          indices start at 1.
	row     - The row number of the cell. The row indices
	          start at 1.
	lines   - ProArray of text lines assigned to the table cell.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDwgtableDelete (
    ProDwgtable *table,
    int         display);
/*  
    Purpose: 
	Deletes the table specified by the table. 

    Input Arguments:
	table    - The table to delete.
        display  - Ignore this argument(Pass any integer)
    
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR  - The table was deleted.
	PRO_TK_NOT_EXIST - The specified <i>table_id</i> does not exist.
*/

extern ProError ProDwgtableDisplay (
    ProDwgtable *table);
/*  
    Purpose: 
	Displays the table.

    Input Arguments:
	table    - The table to display.
       
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - The table was deleted.
	PRO_TK_BAD_INPUTS    - The specified table was NULL.
	PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProDwgtableErase (
    ProDwgtable *table);
/*  
    Purpose: 
	Erases the table.

    Input Arguments:
	table    - The table to erase.
       
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - The table was deleted.
	PRO_TK_BAD_INPUTS    - The specified table was NULL.
	PRO_TK_GENERAL_ERROR - The function failed.
*/


extern ProError ProDwgtableCellNoteGet (
    ProDwgtable *table,
    int         column,
    int         row,
    ProDtlnote  *note);
/*   
     Purpose: 
	Returns the note identifier for a specified cell of a drawing table.

    Input Arguments:
	 table  - the reference to the table. 
	 column - The column index. Column indices start at 1.
         row    - The row index. Row indices start at 1.
	
    Output Arguments:
	note    - The note for the specified cell.

    Return Values:
	PRO_TK_NO_ERROR      - The note identifier for the specified cell.
	PRO_TK_EMPTY         - The cell is empty.
	PRO_TK_GENERAL_ERROR - Another error occurred and the function failed.
*/

extern ProError ProDrawingTableVisit (
    ProDrawing              drawing,
    ProDwgtableVisitAction  visit_action,
    ProDwgtableFilterAction filter_action,
    ProAppData              data);
/*
    Purpose:
	Visit tables in the specified drawing.

    Input Arguments:
	drawing       - drawing to visit
        visit_action  - visit action 
	filter_action - filter action. If NULL, 
	                all tables are visited 
                        using the action function.
	data          - ProAppData structure

    Output Arguments:
	none

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully visited the tables.
	PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
	PRO_TK_E_NOT_FOUND   - No tables were visited.
	Other                - Error return supplied by the visit action which
	                       caused visiting to stop.
*/

extern ProError ProDrawingTablesCollect (
    ProDrawing  drawing,
    ProDwgtable **tables);
/*  
    Purpose:
	collect all tables in the specified drawing

    Input Arguments:
	drawing - the drawing

    Output Arguments:
        tables   - the array of table. The function 
                   allocates the memory for this argument. 
	           To free the memory, call <b>ProArrayFree()</b>.

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully collected the tables.
	PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
	PRO_TK_E_NOT_FOUND   - No tables were found.
*/

extern ProError ProDwgtableColumnsCount (
    ProDwgtable *table,
    int *n_columns);
/*   
     Purpose: 
	Counts the table columns.

    Input Arguments:
	table - The table

    Output Arguments:
	n_columns - columns count

    Return Values:
	PRO_TK_NO_ERROR  - Success  .
	PRO_TK_NOT_EXIST - The specified table or drawing does not exist.
*/

extern ProError ProDwgtableRowsCount (
    ProDwgtable *table,
    int *n_rows);
/*  
    Purpose: 
	Counts the table columns.

    Input Arguments:
	table - The table

    Output Arguments:
	n_rows - rows count 

    Return Values:
	PRO_TK_NO_ERROR  - Success  .
	PRO_TK_NOT_EXIST - The specified table or drawing does not exist.
*/

extern ProError ProDwgtableRowAdd (
    ProDwgtable *table,
    int         insert_after_row,
    int         display,
    double      height_in_chars);
/*   
     Purpose: 
	Adds a row to a table.
	If you try to insert a row in the middle of a 
	nontemplate element of a repeat region,
	this function returns an error.

    Input Arguments:
	table            - the table;
	insert_after_row - insert the new row after this row;
			   Row numbers start with 1. Pass the
			   value 0 to insert the new row at the top of the table
	display          - Flag that specifies whether or not the table is to be
			   displayed after creation.
	height_in_chars  - the height of the row in characters.


    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - Success.
	PRO_TK_GENERAL_ERROR - Failure 
*/

extern ProError ProDwgtableColumnAdd (
    ProDwgtable *table,
    int         insert_after_col,
    int		display,
    double      width_in_chars);
/*   
     Purpose: 
	adds column to a table

     Input Arguments:
        table	         - the table;
	insert_after_col - insert the new column after this
			   column. Column numbers start with 1.
			   If you want the new column to be the 
			   first column, pass the value 0.
	display          - Flag that specifies whether or not the table is to
			   be displayed after creation.
	width_in_chars   - the width of the column, in characters.
    
     Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - Success.
	PRO_TK_GENERAL_ERROR - Failure 
*/

extern ProError ProDwgtableCellsMerge (
    ProDwgtable *table,
    int         start_column,
    int         start_row,
    int         end_column,
    int         end_row,
    int         display);
/*   
     Purpose: 
	Takes a rectangular region of cells and merges them 
	into a composite cell. The merged cells, rows, or 
	columns are deleted, and the table's appearance will be 
	restored using prodrw_remesh_table_cells(). This
	function is equivalent to the Creo Parametric option
	Drawing, Table, Mod Rows/Col, Merge.
	Restrictions placed in the user interface also apply 
	here. For example, borders of merge cannot intersect 
	the borders of another merge or repeat region.

    Input Arguments:
	table        - The table
	start_column - The leftmost column of the merged cell
	start_row    - The upper row of the merged cell
	end_column   - The rightmost column of the merged cell
	end_row      - The bottom row of the merged cell
	display          - Flag that specifies whether or not the table is to be
			   displayed after creation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success;
	PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProDwgtableCellsRemesh (
    ProDwgtable *table,
    int         start_column,
    int         start_row,
    int         end_column,
    int         end_row,
    int         display);
/*  
    Purpose: 
	Undoes all merges created in the specified rectangular region.

    Input Arguments:
	table        - the table;
	start_column - the leftmost column of the region to remesh;
	start_row    - the upper row of the region to remesh;
	end_column   - the rightmost column of the region to remesh; 
	end_row      - the bottom row of the region to remesh.
	display      - Flag that specifies whether or not the table is to be
                       displayed after creation.  If display==TRUE, then the 
                       table is displayed (behavior as in releases prior to
                       Release 20). If display==FALSE, then the table is not
                       displayed.

    Output Arguments:
        None

    Return Values:
         PRO_TK_NO_ERROR      - Success.
	 PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProDwgtableRowDelete (
    ProDwgtable *table,
    int         row,
    int         display);
/*  
    Purpose: 
	Delete the specified row from the table.

    Input Arguments:
	table   - the table;
	row     - the row index.
		  Row indices start at 1.
	display - Flag that specifies whether or not the table is to be
		  displayed after creation.

    Output Arguments:
        None

    Return Values:
         PRO_TK_NO_ERROR      - Success;
	 PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProDwgtableColumnDelete (
    ProDwgtable *table,
    int         column,
    int         display);
/*   
     Purpose:
	Deletes the specified column from the table.

    Input Arguments:
	table   - The table.
	column  - The column index. The indices start at 1.
	display - Flag that specifies whether or not the table is to be
                  displayed after creation.  If display==TRUE, then the 
                  table is displayed (behavior as in releases prior to Release 
                  20). If display==FALSE, then the table is not displayed.

    Output Arguments:
        None

    Return Values:
         PRO_TK_NO_ERROR      - Success;
	 PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProDwgtableCelltextGet (
    ProDwgtable  *table,
    int          column,
    int          row,
    ProParamMode mode,
    ProWstring   **lines);
/*  
    Purpose: 
	Places the text of the table into a string array.

    Input Arguments:
	table  - The table.
	row    - The row index. The row indices start at 1.
	column - The column index. The column indices start at 1.
	mode   - The mode type. Use 1 to get the text as displayed.
	         Use 2 to get the text as shown in the full note
	         editor, in n:&symbol notation.

    Output Arguments:
	lines   - The text of the table. Free this using
                  ProWstringproarrayFree().

    Return Values:
	PRO_TK_NO_ERROR        - Success
	PRO_TK_GENERAL_ERROR   - Failure or table cell does not have any
                                 entered text 
*/

extern ProError ProDwgtableRotate (
    ProDwgtable *table,
    int         display);
/*   
     Purpose: 
	Rotates table (clockwise) by 90 degree.
	The function does not perform a display.

    Input Arguments:
	table    - The table.
	display  - Flag that specifies whether or not the table is to be
		   displayed after creation.

    Output Arguments:
        none

    Return Values:
         PRO_TK_NO_ERROR      - Success;
	 PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProDwgtableCellIsComment (
    ProDwgtable *table,
    int         column,
    int         row,
    ProBoolean  *is_comment);
/*  
    Purpose: 
	Determines whether the specified cell 
	is a comment cell.

    Input Arguments:
		table  - the table;
		column - the column index. The column indices start at 1.
		row    - the row index.  The row indices start at 1.

    Output Arguments:
		is_comment - PRO_B_TRUE if the cell is a comment cell.  PRO_B_FALSE otherwise.

    Return Values:
		PRO_TK_NO_ERROR   - success.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDwgtableCellComponentGet (
    ProDwgtable* table, 
    int column, 
    int row, 
    ProAsmcomppath* component);
/*
    Purpose: 
        Returns the full path to the component referenced in a cell in a
	repeat region of a drawing table.
	<P>
	Note: this function will not return a valid result if the cell has
	the attribute "NO DUPLICATE" or "NO DUPLICATE/LEVEL" as there is
	no unique path available. In this case use the function
	ProDwgtableCellRefmodelGet().

    Input Arguments:
        table   -  The drawing table.
        column  -  The cell column. Column indices start at 1.
        row     -  The cell row. Row indices start at 1.

    Output Arguments:
        component   -  The full path to the component referenced by the cell.

    Return Values:
        PRO_TK_NO_ERROR       -  The function succeeded.
        PRO_TK_BAD_INPUTS     -  One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND    -  The table cell does not contain a reference to a
	                         component model.
        PRO_TK_GENERAL_ERROR  -  An error occurred and the function failed to
	                       construct the component path. This could be
                               because there is no unique path to a single
		               component available.

    See Also:
        ProDwgtableCellRefmodelGet()
*/

extern ProError ProDwgtableCellRefmodelGet (
    ProDwgtable* table, 
    int column, 
    int row, 
    ProAssembly* assembly, 
    ProMdl* model);
/*
    Purpose: 
        Returns the reference assembly and component referred to by this
	cell in a repeat region drawing table. Differs from
	ProDwgtableCellComponentGet in that this function will return the
	reference objects if the cell attribute is set to "NO DUPLICATE"
	or "NO DUPLICATE/LEVEL".

    Input Arguments:
        table   -   The drawing table.
	column  -   The cell column. Column indices start at 1.
	row     -   The cell row. Row indices start at 1.

    Output Arguments:
        assembly  -   The top model for the region.
	model     -   The model of record for the cell.

    Return Values:
        PRO_TK_NO_ERROR      -   The function succeeded.
        PRO_TK_BAD_INPUTS    -   One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND   -   The cell does not have an associated model.

    See Also:
        ProDwgtableCellComponentGet()
*/

extern ProError ProDwgtableIsFromFormat (
    ProDwgtable *table,
    ProBoolean  *from_format);
/*  
    Purpose:
	Determines whether the specified table is associated with 
	the format.    

    Input Arguments:
	table - The drawing table

    Output Arguments:
	from_format - PRO_B_TRUE if the table is associated with the format;
				  PRO_B_FALSE if the table is not associated with the format.
    Return Values: 
	PRO_TK_NO_ERROR	     - The function succeeded.
	PRO_TK_GENERAL_ERROR - The function failed. 	
*/

extern ProError ProDwgtableByOriginRetrieve (
    ProDrawing  drawing,
    ProName     file_name,
    ProPath     file_path,
    int         file_version,
    ProPoint3d  position,
    ProSolid    solid,
    ProSimprep  *simp_rep,
    ProDwgtable *table);
/*
    Purpose:
        Retrieves a stored Creo Parametric drawing table and
        places it in the specified drawing. This function
        is the same as the Creo Parametric command sequence
        Table tab, Table From File. It enables you to
	add a table to a drawing without having to specify 
	all the table properties in your programs.

    Input Arguments:
        drawing     -   The drawing into which to retrieve the table.
        file_name   -   Name of the Table file, excluding the extension.
        file_path   -   Path to the Table file, relative to working directory.
        file_version -  Table file version, where 0 represents latest version.
        position    -   The coordinates of the point on the drawing sheet,
                        where the table must be placed. The origin of the table
                        will be placed at this point on the drawing sheet.
                        Tables can be created with different origins by 
                        specifying the option Direction, in the Insert Table or
                        Table Properties dialog box.
                        Specify the value in screen coordinates.  
        solid       -   The solid model from which data must be copied into the
                        table. If NULL, the table will be created with no data.
        simp_rep    -   The handle to the simplified representation in the  
                        <i>solid</i>, from which data must be copied into the
                        table. If this is NULL and <i>solid</i> is not NULL,
                        all the model data will be copied into the table.

    Output Arguments:
        table - The handle to the retrieved table.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        Any other value - The function failed.
*/

extern ProError ProDwgtableRetrieve (
    ProDrawing  drawing,
    ProName     file_name,
    ProPath     file_path,
    int         file_version,
    ProPoint3d  position,
    ProSolid    solid,
    ProSimprep  *simp_rep,
    ProDwgtable *table);
/*  
    Purpose: 
	Retrieves a stored Creo Parametric drawing table and 
	places it in the specified drawing. This function 
	is the same as the Creo Parametric command sequence 
	Table tab, Table From File. It enables you to
	add a table to a drawing without having to specify 
	all the table properties in your programs.

        This function in similar to the function ProDwgtableByOriginRetrieve()
        except that it places the table in the drawing at the selected point 
        using the upper-left corner of the table as the attachment point.

    Input Arguments:
        drawing     -   The drawing into which to retrieve the table.
        file_name   -   Name of the Table file, excluding the extension.
        file_path   -   Path to the Table file, relative to working directory.
        file_version -  Table file version, where 0 represents latest version.
        position    -   The coordinates of the point on the drawing sheet,
                        where the table must be placed. The upper-left corner
                        of the table will be placed at this point on the 
                        drawing sheet. Specify the value in screen coordinates.  
        solid       -   The solid model from which data must be copied into the
                        table. If NULL, the table will be created with no data.
        simp_rep    -   The handle to the simplified representation in the  
                        <i>solid</i>, from which data must be copied into the
                        table. If this is NULL and <i>solid</i> is not NULL,
                        all the model data will be copied into the table.

    Output Arguments:
        table - The handle to the retrieved table.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        Any other value - The function failed.
*/


extern ProError ProDwgtableInfoGet (
    ProDwgtable *table,
    int segment,
    ProDwgtableInfo *table_info);
/* 
    Purpose: 
	Retrieves information about the specified drawing table.

    Input Arguments:
	table   - The table
	segment - The segment identifier

    Output Arguments:
	table_info     - The drawing table information

    Return Values:
	PRO_TK_NO_ERROR       - The function executed successfully.
	PRO_TK_GENERAL_ERROR  - The specified drawing or table was not found.
	PRO_TK_BAD_INPUTS     - One of more of the input arguments are invalid.  
*/


extern ProError ProDwgtableRowSizeGet (
    ProDwgtable *table,
    int segment,
    int row,
    double *size);
/* 
    Purpose:  
	Returns the size of the specified row, in world units.

    Input Arguments:
	table      - The drawing table 
	segment    - The segment identifier 
	row        - The row. The row index starts at 0

    Output Arguments:
        size       - The size of the row

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
	PRO_TK_GENERAL_ERROR  - One of more of the input arguments are invalid. 
*/

extern ProError ProDwgtableColumnSizeGet (
    ProDwgtable *table,
    int segment,
    int column,
    double *size);
/*  
    Purpose:  
	Returns the size of the specified column, in world units.

    Input Arguments:
	table      - The drawing table 
	segment    - The segment identifier 
	column     - The column. The column index starts at 0

    Output Arguments:
        size       - The size of the row

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully retrieved the 
                                information.
	PRO_TK_GENERAL_ERROR  - One of more of the input arguments are invalid. 
*/

extern ProError ProDrawingTablesUpdate (
    ProDrawing drawing);
/*   
     Purpose: 
	Updates all drawing tables.The drawing must be displayed in a window. Call ProMdlDisplay()
  to display drawing before using this function.

    Input Arguments:
	drawing  - The drawing

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR         - The function successfully updated the table.
	PRO_TK_BAD_INPUTS       - The function argument is invalid.
*/

extern ProError ProDwgtableSegExtentsGet (ProDwgtable* table, int segment_id, 
                                          int* first_row, 
					  int* last_row, 
					  int* first_column, 
					  int* last_column);
/*
    Purpose: Returns the start/end rows and columns of a particular table 
             segment.
             <P><B>Note:</B> Row and column numbers range from 1 to the total 
             number of rows and columns in the table.

    Input Arguments:
        table - The drawing table.
        segment_id - The table segment id. Pass PRO_VALUE_UNUSED for a single 
                     segment table.

    Output Arguments:
        first_row - The first row in the table segment.  Pass NULL if not 
                    interested in this value.
        last_row - The last row in the table segment.  Pass NULL if not 
                   interested in this value.
        first_column - The first column in the table segment.  Pass NULL if not 
                       interested in this value.
        last_column - The last column in the table segment.  Pass NULL if not 
                      interested in this value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - PRO_VALUE_UNUSED was used for multiple-segment 
                             table.

*/

typedef ProError (*ProDwgtableDeletePreAction) (ProDwgtable* table);
/*
    Purpose: This is the prototype for a notification to be called before 
             deletion of a drawing table. The ProNotifyType
	     value for the notification is PRO_DWGTABLE_DELETE_PRE.

    Input Arguments:
        table - The table that is about to be deleted.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Proceed with the deletion.
        Any other value - Cancel the deletion.  It is the application's 
                          responsibility to inform the user why the table will 
                          not be deleted.

    See Also:
        ProDwgtableDeletePostAction(), ProDwgtableRowDeletePreAction()
*/

typedef ProError (*ProDwgtableDeletePostAction) (ProDrawing drawing,
						 int table_id);
/*
    Purpose: This is the prototype for a notification to be called after 
             deletion of a drawing table. The ProNotifyType
	     value for the notification is PRO_DWGTABLE_DELETE_POST.

    Input Arguments:
        drawing - The drawing that owned the table.
        table_id - UNINITIALIZED

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.

    See Also:
        ProDwgtableDeletePreAction(), ProDwgtableRowDeletePostAction()
*/

typedef ProError (*ProDwgtableRowDeletePreAction) (ProDwgtable *table, int i_row);
/*
    Purpose: This is the prototype for a notification to be called before 
             deletion of row of a drawing table. The ProNotifyType
	     value for the notification is PRO_DWGTABLE_ROW_DELETE_PRE.
             

    Input Arguments:
        table - The table containing the row that is about to be deleted.
	i_row - The index of the row that is about to be deleted (1-based)

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Proceed with the deletion.
        Any other value - Cancel the deletion.  It is the application's 
                          responsibility to inform the user why the table will 
                          not be deleted.

    See Also:
        ProDwgtableRowDeletePostAction(), ProDwgtableDeletePreAction()
*/

typedef ProError (*ProDwgtableRowDeletePostAction) (ProDwgtable *table, int i_row);
/*
    Purpose: This is the prototype for a notification to be called after 
             deletion of a row of a drawing table. The ProNotifyType
	     value for the notification is PRO_DWGTABLE_ROW_DELETE_POST.

    Input Arguments:
       table - The table containing the row that was just deleted.
       i_row - The index of the row that was just deleted (1-based)

    Output Arguments:
        none

    Return Values:
        Return values are not interpreted by Creo Parametric.

    See Also:
        ProDwgtableDeletePostAction(), ProDwgtablRowDeletePreAction()
*/

extern ProError ProDwgtableColumnWidthSet (ProDwgtable* table, int  column, double column_width, ProDwgtableSizetype size_type);
/*
    Purpose: Set the column width of a drawing table
             

    Input Arguments:
        table - The reference to the table.
        column - The column index. Column indices start at 1.
        column_width - Column width
        size_type - Size type.  If PRODWGTABLESIZE_CHARACTERS, then
                    column_width will be rounded down.  To avoid this, use
                    PRODWGTABLESIZE_CHARS_TRUE.


    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The column width could not set

*/

extern ProError ProDwgtableRowHeightSet (ProDwgtable* table, int  row, double row_height, ProDwgtableSizetype size_type);
/*
    Purpose: Set the row height of a drawing table
             

    Input Arguments:
        table - the reference to the table.
        row - The row index
        row_height - Row height
        size_type - Size type.  If PRODWGTABLESIZE_CHARACTERS, then row_height
                    will be rounded down.  To avoid this, use
                    PRODWGTABLESIZE_CHARS_TRUE.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The row height could not set

*/

extern ProError ProDwgtableCelltextWrap (ProDwgtable* table, int  row, int column);
/*
    Purpose: Wrap text in cell
             

    Input Arguments:
        table - the reference to the table.
        row - The row index
        column - The column index

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDwgtableSegmentOriginSet (ProDwgtable* table, int  segment, ProPoint3d point);
/*
    Purpose: Set table segment origin
             

    Input Arguments:
        table - The reference to the table.
        segment - The segment identifier
        point - Point location of the segment

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDwgtableSave(ProDwgtable* table, ProPath path, ProDwgtableFormattype table_format, int segment_id );
/*
    Purpose: Save table in different format 
             

    Input Arguments:
        table - The reference to the table.
        path - Full path of the saved location
        table_format - Save format of the drawing table
	segment_id - segment of the table to save, if table_format is
		PRODWGTABLEFORMAT_CSV
    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingSetupOptionGet (ProDrawing drawing, ProName option, ProLine value);
/*
    Purpose: Get the drawing setup option
             
             

    Input Arguments:
       	drawing - The drawing
        option - The drawing option

    Output Arguments:
        value - The value of the drawing option

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingSetupOptionSet (ProDrawing drawing, ProName option, ProLine value);
/*
    Purpose: Set the drawing setup option
             
             

    Input Arguments:
    	drawing - The drawing
        option - The drawing option
        value - The value of the drawing option

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingMerge (ProDrawing drawing, ProDrawing merge_drawing);
/*
    Purpose: Merge two drawing
    <P>         
    <B>NOTE:</B> After using ProDrawingMerge(), the handle to the second drawing is lost.
     Use ProMdlRetrieve() to get the handle again.        
    <P> 
    Input Arguments:
        drawing - drawing handle
        merge_drawing - The drawing handle to be merged.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDwgtableGrowthdirectionGet (ProDwgtable *table, ProDwgtableGrowthdirType *p_dir);
/*
    Purpose: Gets the growth direction for the drawing table
    
	Input Arguments:
        table - The drawing table
       
    Output Arguments:
     	p_dir - The growth direction type
    
	Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        
*/

extern ProError ProDwgtableGrowthdirectionSet (ProDwgtable *table, ProDwgtableGrowthdirType p_dir);
/*
    Purpose: Sets the growth direction for the drawing table. 
    
	Input Arguments:
        table - The drawing table
        p_dir - The growth direction type
    
	Output Arguments:
     	none
    
	Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        
*/

extern ProError ProDwgtableRowheightAutoadjustSet(ProDwgtable *table, int row, ProDwgtableRowheightAutoadjusttype auto_adjust);
/*
    Purpose: Set the automatic row height adjustment property for a row of a drawing table.
    
    <P><B>NOTE: </B>Height changes (if any) will be visible only after next regeneration or a call to ProDrawingTablesUpdate()
 
  Input Arguments:
        table - The reference to the table.
        row - Row number for which the property is to be set. Row numbers start with 1.
        auto_adjust - PRODWGTBLROWHEIGHT_AUTOADJUST_TRUE to set the property, 
                      PRODWGTBLROWHEIGHT_AUTOADJUST_FALSE to unset it. 
 
  Output Arguments:
      none
 
  Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The automatic adjust property could not be set.
        PRO_TK_CANT_MODIFY - The row is a non-template repeat region row.
*/
 
extern ProError ProDwgtableRowheightAutoadjustGet(ProDwgtable* table, int row, ProDwgtableRowheightAutoadjusttype *auto_adjust);
/*
    Purpose: Get the automatic row height adjustment property for a row of a drawing table.
 
  Input Arguments:
        table - The reference to the table.
        row - Row number for which the property is to be retrieved. Row numbers start with 1.
 
  Output Arguments:
        auto_adjust - Retrieved value for auto-adjust property.
 
  Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The automatic adjust property could not be retrieved.
*/


PRO_END_C_DECLS

#endif /* DRWTABLE_H */
    

