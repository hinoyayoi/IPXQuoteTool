/* PRODRAWING.H */



#ifndef PRODRAWINGDOTH
#define PRODRAWINGDOTH

PRO_BEGIN_C_DECLS

#include <ProUtil.h>
#include <ProDimension.h>
#include <ProObjects.h>
#include <ProSelection.h>
#include <ProToolkit.h>
#include <ProView.h>
#include <ProMdlUnits.h>
#include <ProModelitem.h>
#include <ProDtlitem.h>
#include <ProMdlUnits.h>


typedef struct prodrw_cell_info
{
  ProDrawing	p_draw;
  int table_id;
  int row_id;
  int col_id;
  int readonly;
  int seg_id;
  int note_id;
} Prodrw_cell_info;

typedef struct prodrw_sheet_info
{
  ProPlotPaperSize type;
  int width;
  int height;
  ProUnitLength units;
  int orientation;
} Prodrw_sheet_info;

typedef struct prodrw_sheet_info ProDrawingSheetInfo;

typedef struct prodrw_tbl_info
{
  int rotation;
  double seg_origin[3];
  int nrows;
  int ncols;
  double outline[2][3];
  double seg_char_height;
  double table_char_height;
  double char_width;
} Prodrw_tbl_info;

typedef enum 
{
  PRO_ORIENTATION_UNDEFINED = -1,
  PRO_ORIENTATION_LANDSCAPE = 0,
  PRO_ORIENTATION_PORTRAIT = 1
} ProSheetOrientation;

#define PRODEV_ORIENTATION_LANDSCAPE PRO_ORIENTATION_LANDSCAPE
#define PRODEV_ORIENTATION_PORTRAIT PRO_ORIENTATION_PORTRAIT
#define PRODEV_ORIENTATION_UNDEFINED PRO_ORIENTATION_UNDEFINED

typedef enum hlr_disp
{
   PRO_DISPSTYLE_DEFAULT = 0,
   PRO_DISPSTYLE_WIREFRAME,
   PRO_DISPSTYLE_HIDDEN_LINE,
   PRO_DISPSTYLE_NO_HIDDEN,
   PRO_DISPSTYLE_SHADED,
   PRO_DISPSTYLE_FOLLOW_ENVIRONMENT,
   PRO_DISPSTYLE_SHADED_WITH_EDGES
} ProDisplayStyle;

typedef enum tan_disp 
{
   PRO_TANEDGE_DEFAULT = 10,
   PRO_TANEDGE_NONE,
   PRO_TANEDGE_CENTERLINE,
   PRO_TANEDGE_PHANTOM,
   PRO_TANEDGE_DIMMED,
   PRO_TANEDGE_SOLID
} ProTanedgeDisplay;

typedef enum cable_disp
{
   PRO_CABLEDISP_DEFAULT = 20,
   PRO_CABLEDISP_CENTERLINE,
   PRO_CABLEDISP_THICK
} ProCableDisplay;

typedef enum piping_disp
{
 PRO_PIPINGDISP_DEFAULT,
 PRO_PIPINGDISP_CENTERLINE,
 PRO_PIPINGDISP_THICK_PIPES,
 PRO_PIPINGDISP_THICK_PIPES_AND_INSULATION
} ProPipingDisplay;

typedef struct proDrawingViewDisplay
{
   ProDisplayStyle style;
   ProBoolean quilt_hlr;
   ProTanedgeDisplay tangent_edge_display;
   ProCableDisplay cable_display;
   ProBoolean concept_model;
   ProBoolean weld_xsec;
} ProDrawingViewDisplay;

#define  PRODWGCREATE_DISPLAY_DRAWING       (1<<0)
#define  PRODWGCREATE_SHOW_ERROR_DIALOG     (1<<1)
#define  PRODWGCREATE_WRITE_ERRORS_TO_FILE  (1<<2)
#define  PRODWGCREATE_PROMPT_UNKNOWN_PARAMS (1<<3)

typedef int ProDwgcreateOptions;

typedef enum {
    PRODWGCRTERR_SAVED_VIEW_DOESNT_EXIST        = 1,
    PRODWGCRTERR_X_SEC_DOESNT_EXIST             = 2,
    PRODWGCRTERR_EXPLODE_DOESNT_EXIST           = 3,
    PRODWGCRTERR_MODEL_NOT_EXPLODABLE           = 4,
    PRODWGCRTERR_SEC_NOT_PERP                   = 5,
    PRODWGCRTERR_NO_RPT_REGIONS                 = 6,
    PRODWGCRTERR_FIRST_REGION_USED              = 7,
    PRODWGCRTERR_NOT_PROCESS_ASSEM              = 8,
    PRODWGCRTERR_NO_STEP_NUM                    = 9,
    PRODWGCRTERR_TEMPLATE_USED                  = 10,
    PRODWGCRTERR_NO_PARENT_VIEW_FOR_PROJ        = 11,
    PRODWGCRTERR_CANT_GET_PROJ_PARENT           = 12,
    PRODWGCRTERR_SEC_NOT_PARALLEL               = 13,
    PRODWGCRTERR_SIMP_REP_DOESNT_EXIST          = 14,
    PRODWGCRTERR_COMB_STATE_DOESNT_EXIST        = 15,
    PRODWGCRTERR_TOOL_DOESNT_EXIST              = 16,
    PRODWGCRTERR_NOT_ALL_BALLOONS_CLEANED_WRN   = 17
    
}  ProDwgcreateErrType;

typedef struct dwg_template_error**  ProDwgcreateErrs;

typedef enum {
  PRO_VIEWDISP_NOT_SHOWN,  /* Never shown */
  PRO_VIEWDISP_SHOWN,      /* Shown */
  PRO_VIEWDISP_ERASED      /* Once shown, but has since been erased
                             (equivalent to Erased/Never Shown option
                              in Show/Erase dialog */
} ProViewItemdisplayStatus;

typedef enum {
    PRO_DUALDIM_OFF,
    PRO_DUALDIM_PRIMARY_SECONDARY,
    PRO_DUALDIM_SECONDARY_PRIMARY,
    PRO_DUALDIM_SECONDARY
} ProDualDimensionType;

typedef enum 
{
  PRO_DECLARE_INTERACTIVE    = 0, /* Switch to interactive mode */
  PRO_DECLARE_OBJECT_SYMBOLS = 1, /* Keep the symbols from the object */
  PRO_DECLARE_LAYOUT_SYMBOLS = 2, /* Keep the symbols from the notebook */
  PRO_DECLARE_ABORT          = 3  /* Abort the notebook declaration process
                                     and return an error */
}ProDeclareOptions;

typedef enum 
{
  PRO_UNDECLARE_FORCE  = 0, /* Continue undeclaring the notebook if references exist*/ 
  PRO_UNDECLARE_CANCEL = 1  /* Do not undeclare the notebook if references exist */
}ProUndeclareOptions;

typedef struct notebook*  ProLayout;


extern ProError ProDrawingViewDisplayGet(
    ProDrawing            drawing,
    ProView               view,
    ProDrawingViewDisplay *display_status);
/*
    Purpose:
       Outputs information about the display status of a drawing view
 
    Input Arguments:
       drawing         - The drawing
       view            - The drawing view
 
    Output Arguments:
       display_status  - A structure containing the display status information.
 
    Return Values:
       PRO_TK_NO_ERROR    - Success
       PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

extern ProError ProDrawingViewDisplaySet(
    ProDrawing            drawing,
    ProView               view,
    ProDrawingViewDisplay *display_status);
/*
    Purpose:
       Sets the display status of a drawing view. The function does not 
       repaint the view - use ProWindowRepaint() to do this.
       
       If the function returns an error, none of the properties are set.
       
        <b>NOTE:</b>
        
        Note the following restrictions :
        <ul>
          <li>Changing the concept_model field requires a Pro/ASSEMBLY license.
          </ul>

    Input Arguments:
       drawing         - The drawing
       view            - The drawing view
       display_status  - A structure containing the display status information.
                         Initialize this structure by a call to
                         ProDrawingViewDisplayGet() on the same view.
 
    Output Arguments:
       None
 
    Return Values:
       PRO_TK_NO_ERROR    - Success
       PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid,
                            or style was set to PRO_DISPSTYLE_SHADED.
       PRO_TK_BAD_CONTEXT - The drawing view is a child of another view and
                            inherits its display from its parent.
       PRO_TK_NO_LICENSE  - The function attempted to set the concept_model
                            field, but no Pro/ASSEMBLY license is available.
*/

extern ProError ProDrawingViewonlyOpen(ProPath path, ProMdl *mdl);

/*
    Purpose:  Open a drawing in view only mode.

    Input Arguments:
         path - Path to the drawing.

    Output Arguments:
        mdl - The drawing handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingViewIdGet( ProDrawing drawing, ProView view, 
                                     int* view_id);

/*
    Purpose: Retrieves the view ID given the drawing and the view.

    Input Arguments:
        drawing - The drawing handle.
        view - The view handle.

    Output Arguments:
        view_id - The view ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDrawingViewInit(ProDrawing drawing, int view_id, ProView* view);

/*
    Purpose: Retrieves the view handle given the drawing and the view ID.

    Input Arguments:
        drawing - The drawing handle.
        view_id - The view ID.

    Output Arguments:
       view - The view handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingViewPipingdisplayGet (
                                             ProDrawing drawing, 
					     ProView view, 
					     ProPipingDisplay* piping_display);
/*

Purpose: Gets the piping display option for a drawing view.


Input Arguments:

   drawing - The drawing.

   view - The drawing view.


Output Arguments:

   piping_display - The piping display setting.


Return Values:

   PRO_TK_NO_ERROR - The function succeeded.

   PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDrawingViewPipingdisplaySet (
                                              ProDrawing drawing, 
					      ProView view, 
                                              ProPipingDisplay piping_display);

/*
Purpose: Sets the piping display option for a drawing view.


Input Arguments:

   drawing - The drawing.

   view - The drawing view.

   piping_display - The piping display setting.


Output Arguments:

   none


Return Values:

   PRO_TK_NO_ERROR - The function succeeded.

   PRO_TK_BAD_INPUTS - One or more input arguments was invalid.


*/

extern ProError ProDwgDraftRegenerate (ProDrawing p_draw);
/*

Purpose: Regenerates the specified drawing draft entities.  

Input Arguments:

    p_draw   - The drawing handle

Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR - The function successfully regenerated the draft entities.
    PRO_TK_GENERAL_ERROR - The specified drawing is not valid for Creo Parametric TOOLKIT.

*/ 

extern ProError ProDwgSheetRegenerate (ProDrawing p_draw, int sheet_id);
/*

Purpose: Regenerates the specified drawing sheet.
         <p>
         <b>NOTE:</b>
         <p>
         For the regeneration to be successful, the specified sheet
         must be displayed in a window.

Input Arguments:

    p_draw    - The drawing handle
    sheet_id  - The sheet identifier

Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR  - The function successfully regenerated the drawing sheet.
    PRO_TK_GENERAL_ERROR - The regeneration failed.  

*/

extern ProError ProDwgViewRegenerate (ProDrawing p_draw, int view_id);
/*

Purpose: Regenerates the specified view.
         <p>
         <b>NOTE:</b>
         <p>
         For the regeneration to be successful, the specified view 
         must be showing in a window.

Input Arguments:
    p_draw    - The drawing handle
    view_id   - The view identifier

Output Arguments:
    None

Return Values:
    PRO_TK_NO_ERROR - The function successfully regenerated the drawing view. 
    PRO_TK_GENERAL_ERROR  - The regeneration failed. 

See Also:
    ProDrawingViewRegenerate()  
*/

extern ProError ProDrawingViewRegenerate (ProDrawing p_draw, ProView p_view);
/*

Purpose: Regenerates the view specified by the specified view handle.
         <p>
         <b>NOTE:</b>
         <p>
         For the regeneration to be successful, the specified view
         must be showing in a window.
         </b>

Input Arguments:

    p_draw    - The drawing handle
    p_view    - The view handle

Output Arguments:

    None

Return Values:

    PRO_TK_NO_ERROR        - The function successfully regenerated the 
                             drawing view.
    PRO_TK_GENERAL_ERROR   - The regeneration failed.
*/


extern ProError ProDrawingFormatGet(
    ProDrawing drawing,
    int sheet,
    ProName format_name);
/*
 
  Purpose: Outputs the name of the drawing format for the specified sheet.
 
  Input Arguments:
 
    drawing   - The drawing
    sheet     - The sheet number
 
  Output Arguments:
 
    format_name - The name of the drawing sheet's format
 
  Return Values:
 
    PRO_TK_NO_ERROR     - Success
    PRO_TK_E_NOT_FOUND  - Format for the sheet was not found.
    PRO_TK_BAD_INPUTS   - One or more of the arguments is invalid.
    PRO_TK_E_NOT_EXIST  - A user-defined format does not exist for the sheet.


------------------------------------------------------------------------*/

extern ProError ProDrawingDimensionViewGet( ProDrawing      drawing,
                                            ProDimension   *dimension,
                                            ProView        *view );
/*
  Purpose: Reports which drawing view a dimension is displayed in.
           Applies to dimensions stored in the solid or in the drawing.

  Input Arguments:
     drawing         - The drawing in which the dimension is displayed.
     dimension       - The dimension.

  Output Arguments:
     view            - The drawing view in which the dimension is displayed.

  Return Values:
     PRO_TK_NO_ERROR - The function successfully retrieved the view
                       displaying the drawing.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NOT_DISPLAYED - The dimension is not displayed in the drawing.

--------------------------------------------------------------------------*/ 

extern ProError ProDrawingDimIsAssociative( ProDrawing    drawing,
                                            ProDimension *dimension,
                                            ProBoolean   *associative);
/*
  Purpose: Checks if dimension is associative.

  Input Arguments:
     drawing         - The drawing in which the dimension is displayed.
     dimension       - The dimension.

  Output Arguments:
     associative     - The predicate which is TRUE when the dim is associative

  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/
   
/*--------------------------------------------------------------------------*/

extern ProError ProDrawingDimSwitchView( ProDrawing      drawing,
                                         ProDimension   *dimension,
                                         ProView         target_view );
/*
  Purpose: Applies to dimensions stored in the solid or in the drawing.

  Input Arguments:
     drawing      - The drawing in which the dimension is displayed.
     dimension    - The dimension.
     target_view  - The drawing view in which the dimension is to be displayed.

  Output Arguments:
      None
      
  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
     PRO_TK_CANT_WRITE - Could not delete the given item because
                         it has read-only access.
  
*/

extern ProError ProDrawingDimAttachsGet(
  ProDrawing		drawing,
  ProDimension		*dimension,
  ProSelection		**p_attachments_arr,
  ProDimSense		**p_dsense_arr
);
/*
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProDrawingDimAttachpointsGet
  Purpose: 
  <B>Note: </B> This function is <B>deprecated</B> and replaced by:
             <B>ProDrawingDimAttachpointsGet()</B>.
   
    <P>
           Retrieves the attachments and the sense of the specified
           drawing dimension. only applicable for dimensions created
           in drawing mode.
           This function does not support drawing dimensions created from
           intersections of geometric entities.


  Input Arguments:
    drawing		- the drawing.
    dimension		- the dimension.

  Output Arguments:
    p_attachments_arr   - pointer to a ProArray of ProSelection.
                          Will be allocated by function.
                          Free this using ProSelectionarrayFree().
    p_dsense_arr	- pointer to a ProArray of ProDimSense.
                          Will be allocated by function.
                          Free this using ProArrayFree().

  Return Values:
    PRO_TK_BAD_INPUTS	- one or more of the input arguments are
                          invalid.
    PRO_TK_INVALID_ITEM	- the dimension specified is not a valid
                          dimension created in drawing mode. 
    PRO_TK_NO_ERROR	- successfully retrieved the attachments
                          and the sense.
    PRO_TK_INVALID_TYPE - the  dimension   sense   type  is  not
                          supported with this function.
    PRO_TK_NOT_IMPLEMENTED - If the dimension is placed on
                             intersection of two entities.
  
*/

extern ProError ProDrawingDimCreate(
  ProDrawing		drawing,
  ProSelection		*attachments_arr,
  ProDimSense		*dsense_arr,
  ProVector		location,
  ProBoolean		ref_dim,
  ProDimension		*dimension
);
/*
  DEPRECATED: Since Creo 4.0

  SUCCESSORS:
    ProDrawingDimensionCreate

  Purpose: Creates a dimension in drawing mode with the specified
           attachments and sense, at the specified location.
           <B>Note:</B> This function is deprecated.

  <B>Note:</B>
      From Creo 4.0 onwards ProDrawingDimCreate() has been superseded by
      ProDrawingDimensionCreate(). ProDrawingDimCreate() uses orient hint
      from dsense_arr, which is replaced by single argument orient_hint
      in the superseded API.

  Input Arguments:
    drawing		- the drawing.
    attachments_arr	- ProArray of attachments.
    dsense_arr		- ProArray of sense.
    location		- specifies where to put the dimension text.
    ref_dim		- indicates whether a PRO_DIMENSION or a 
                          PRO_REF_DIMENSION should be created.

  Output Arguments:
    dimension		- the newly created dimension

  Return Values:
    PRO_TK_BAD_INPUTS	    - one or more of the input arguments are
                              invalid.
    PRO_TK_BAD_DIM_ATTACH   - a dimension could not be created with
                              the attachments and sense specified.
    PRO_TK_NO_ERROR	    - successfully created a dimension
                              with the specified attachments and sense.
*/

extern ProError ProDrawingDimIsOrdinate(
  ProDrawing		drawing,
  ProDimension		*dimension,
  ProBoolean		*ordinate,
  ProDimension		*base_dim
);
/*
  Purpose: Queries whether a dimension is ordinate.

  Input Arguments:
    drawing		- the drawing.
    dimension		- the dimension.

  Output Arguments:
    ordinate		- whether the dimension is ordinate or not.
    base_dim		- the baseline dimension corresponding to the
                          input ordinate dimension. will be the same as
                          the input ordinate dimension if the input 
                          dimension is itself a baseline dimension. 

  Return Values:
    PRO_TK_BAD_INPUTS	- one or more of the input arguments are invalid.
    PRO_TK_NO_ERROR	- successfully determined whether dimension is 
                          ordinate. 
*/

extern ProError ProDrawingOrdbaselineCreate(
  ProDrawing		drawing,
  ProDimension		*dimension,
  ProVector		location,
  ProDimension		*base_dimension
);
/*
  Purpose: Creates an ordinate baseline dimension from an existing
           linear dimension. Available only in drawing mode. The
           drawing must be displayed.

  Input Arguments:
    drawing		- the drawing.
    dimension		- the linear dimension from which the ordinate
                          baseline is to be created. As a side-effect,
                          this dimension will be converted to ordinate.
    location		- a point on one of the extension lines of the
                          linear dimension.

  Output Arguments:
    base_dimension	- the newly created ordinate baseline dimension.

  Return Values:
    PRO_TK_BAD_INPUTS	  - one or more of the input arguments are 
                            invalid.
    PRO_TK_GENERAL_ERROR  - failed to create an ordinate baseline
                            using the specified dimension and point.
    PRO_TK_NO_ERROR	  - successfully created an ordinate 
                            baseline dimension.
*/

extern ProError ProDrawingDimToOrdinate(
  ProDrawing		drawing,
  ProDimension		*dimension,
  ProDimension		*base_dimension
);
/*
  Purpose: Converts a linear dimension to ordinate using the base dimension
           specified. Available only in drawing mode. The drawing must be
           displayed.

  Input Arguments:
    drawing		- the drawing.
    dimension		- linear dimension to be converted to ordinate.
    base_dimension	- the ordinate baseline dimension to be used.

  Output Arguments:
    None 

  Return Values:
    PRO_TK_BAD_INPUTS		- one or more of the input arguments are 
                                  invalid.
    PRO_TK_GENERAL_ERROR	- failed to convert the linear dimension
                                  to ordinate.
    PRO_TK_NO_ERROR		- successfully converted the linear 
                                  dimension to ordinate.
    PRO_TK_CANT_WRITE           - Could not modify the given item because
                                  it has read-only access.
*/

extern ProError ProDrawingDimToLinear(
  ProDrawing            drawing,
  ProDimension          *dimension
);
/*
  Purpose: Converts an ordinate dimension to linear. Available only in
           drawing mode. The drawing must be displayed.

  Input Arguments:
    drawing		- the drawing.
    dimension		- ordinate dimension to be converted to linear.

  Output Arguments:
    None 

  Return Values:
    PRO_TK_BAD_INPUTS		- one or more of the input arguments are 
                                  invalid.
    PRO_TK_GENERAL_ERROR	- failed to convert the ordinate dimension
                                  to linear.
    PRO_TK_NO_ERROR		- successfully converted the ordinate dimension
                                  to linear. 
    PRO_TK_CANT_WRITE           - Could not modify the given item because
                                  it has read-only access.
--------------------------------------------------------------------------*/
extern ProError ProDrawingDimensionPosGet( ProDrawing    drawing,
                                           ProDimension *dimension,
                                           ProVector     location);
/*
  Purpose: <B>Note:</B> The coordinates returned by this function are offset 
                        from the coordinates needed by ProDrawingDimensionMove(). 
                        Use ProDimlocationTextGet() instead

           Gets dimension position in drawing (the center of the text box ).

  Input Arguments:
     drawing         - The drawing in which the dimension is displayed.
     dimension       - The dimension.

  Output Arguments:
     location        - 3D vector representing the dimension position

  Return Values:
    PRO_TK_BAD_INPUTS		- one or more of the input arguments are 
                                  invalid.
    PRO_TK_GENERAL_ERROR	- failed to get dimension text coordinate.
    PRO_TK_NO_ERROR		- the location is found. 
   
--------------------------------------------------------------------------*/

extern ProError ProDrawingDimensionTextstyleGet( ProDrawing drawing,
                                                 ProDimension* dimension,
                                                 ProTextStyle* text_style );
/*
    DEPRECATED:Since Creo 4.0
    SUCCESSORS:ProAnnotationTextstyleGet
    Purpose: Obtains the text style assigned to a dimension or reference
             dimension. If drawing is NULL, the display model will be
             taken from the dimension argument.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        drawing - The drawing in which the dimension is displayed.
        dimension - The dimension.

    Output Arguments:
        text_style - The text style. Free this using ProTextStyleFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDrawingDimensionMove( ProDrawing    drawing,
                                         ProDimension *dimension,
                                         ProVector     location );
/*
  Purpose: Move the dimension to the specified position in the drawing.
           The position before and after the move can be found by
           ProDimlocationTextGet().

  Input Arguments:
     drawing         - The drawing in which the dimension is displayed.
     dimension       - The dimension.
     location        - 3D vector representing the new dimension position.

  Output Arguments:
     None
     
  Return Values:
    PRO_TK_BAD_INPUTS		- one or more of the input arguments are 
                                  invalid.
    PRO_TK_NO_ERROR		- the location is found. 
    PRO_TK_CANT_WRITE           - Could not modify the given item because
                                  it has read-only access.
      
--------------------------------------------------------------------------*/

extern ProError ProDrawingDimensionPathGet ( ProDrawing drawing,
					     ProDimension* dimension,
					     ProAsmcomppath* path);
/*
     Purpose: Extracts the component path for a dimension shown from a 
              solid model in the drawing.

     Input Arguments:
          drawing - The drawing in which the dimension is displayed.
          dimension - The dimension.

     Output Arguments:
          path - The component path.

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more arguments was invalid.
          PRO_TK_NOT_DISPLAYED - The dimension is not displayed in the drawing.
          PRO_TK_GENERAL_ERROR - The function failed to obtain the shown
                                 dimension.
*/

extern ProError ProDrawingAxisToDtlaxis(
  ProDrawing p_draw, 
  ProSelection p_sel3d,
  ProVector location, 
  ProSelection *r_p_sel2d
);
/*
  Purpose: Converts a 3d axis selection into a dtl-axis selection in 
           the drawing. The 3d axis selection should have the following info:
           <OL>
             <LI>the drawing view
             <LI>the memb-id table
           </OL>
           The output selection will be the corresponding dtl-axis selection.
           the location (in screen coordinates) is needed to identify the line
           of the cosmetic.
           <P>
           Output selection will be allocated by function and will have to
           be managed/released by caller.

  Input Arguments:
    p_draw		- the drawing.
    p_sel3d		- the 3d axis selection. 
    location		- in screen coordinates, a point on one of
                          the axis lines.

  Output Arguments:
    r_p_sel2d		- handle to the converted selection.

  Return Values:
    PRO_TK_BAD_INPUTS		- one or more of the input arguments are 
                                  invalid.
    PRO_TK_GENERAL_ERROR	- failed to convert the input axis selection
                                  into a dtl_axis selection.
    PRO_TK_NO_ERROR		- successfully converted the input axis
                                  selection into a dtl_axis selection.
*/

extern ProError ProDrawingDtlaxisToAxis(
  ProDrawing p_draw, 
  ProSelection p_sel2d,
  ProSelection *r_p_sel3d, 
  ProVector r_location
);
/*
  Purpose: Converts a dtl_axis selection into a 3d axis selection.
           performs the reverse operation of ProDrawingAxisToDtlaxis().

  Input Arguments:
    p_draw		- the drawing.
    p_sel2d		- the 2d axis selection. 

  Output Arguments:
    r_p_sel3d		- handle to the converted selection.
    r_location		- in screen coordinates, the selected point on the
                          input dtl_axis.


  Return Values:
    PRO_TK_BAD_INPUTS         - one or more of the input arguments are 
                                invalid.
    PRO_TK_GENERAL_ERROR      - failed to convert the input dtl_axis selection
                                into an axis selection.
    PRO_TK_NO_ERROR	      - successfully converted the input dtl_axis
                                selection into a axis selection.
*/


extern ProError ProDrawingSheetsCount (
	ProDrawing drawing,
	int        *n_sheets);

/*   
    Purpose: 
	Returns the total number of sheets in the specified drawing.

    Input Arguments:
        drawing    - The drawing

    Output Arguments:
	n_sheets - A positive integer representing the sheet number. 

    Return Values:
	PRO_TK_NO_ERROR   - The function succeeded.
	PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProDrawingSheetInfoGet(
 ProDrawing drawing,
 int sheet,
 ProDrawingSheetInfo *sheet_info);
/*  
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProDrawingSheetSizeGet,ProDrawingSheetUnitsGet,ProDrawingSheetOrientationGet
    Purpose:
        <B>Note: </B> This function is deprecated and replaced by:
	<UL><LI> ProDrawingSheetSizeGet()
            <LI> ProDrawingSheetUnitsGet()
            <LI> ProDrawingSheetOrientationGet()
        </UL>
	<P>
	Returns the sheet info for the specified sheet.

    Input Arguments:
	drawing      - The drawing
        sheet        - The sheet number

    Output Arguments:
        sheet_info - the sheet info structure

    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - Failure (the drawing handle or sheet number 
                            is invalid)
 */

extern ProError ProDrawingSheetSizeGet(
 ProDrawing drawing,
 int sheet,
 ProPlotPaperSize* type,
 double* width,
 double* height);
/*  
    Purpose: 
	Returns the size for the specified sheet.

    Input Arguments:
	drawing      - The drawing
        sheet        - The sheet number

    Output Arguments:
        type         - The sheet size type.
        width        - The sheet width, in the sheet units 
	height       - The sheet height, in the sheet units
        
    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - Failure (the drawing handle or sheet number 
                            is invalid)
    
    See Also: 
        ProDrawingSheetUnitsGet()
 */

extern ProError ProDrawingSheetUnitsGet(
 ProDrawing drawing,
 int sheet,
 ProUnititem* units);
/*  
    Purpose: 
	Returns the units for the specified sheet.

    Input Arguments:
	drawing      - The drawing
        sheet        - The sheet number

    Output Arguments:
        units        - The units used for measurements in this sheet.
        
    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - Failure (the drawing handle or sheet number 
                            is invalid)
 */

extern ProError ProDrawingSheetOrientationGet(
 ProDrawing drawing,
 int sheet,
 ProSheetOrientation* orientation);
/*  
    Purpose: 
	Returns the orientation for the specified sheet.

    Input Arguments:
	drawing      - The drawing
        sheet        - The sheet number

    Output Arguments:
        orientation  - The sheet orientation (portrait or landscape).
        
    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - Failure (the drawing handle or sheet number 
                            is invalid)
 */

extern ProError ProDrawingSheetTrfGet(
 ProDrawing drawing,
 int sheet,
 ProName    sheet_size, 
 ProMatrix  transform);
/*  
    Purpose: 
	Returns the transformation matrix for the drawing sheet.

    Input Arguments:
	drawing      - The drawing
        sheet        - The sheet number

    Output Arguments:
        sheet_size   - a string identifying the sheet size
        transform    - the transformation matrix for the sheet

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
	PRO_TK_BAD_INPUTS    - The drawing handle or sheet number 
                               is invalid
 */



extern ProError ProDrawingSheetNameGet (
        ProDrawing drawing,
        int sheet,
        ProName sheet_name);
/*  
    Purpose:
        Retrieves the name of the specified sheet of the drawing.

    Input Arguments:
	drawing      - The drawing
        sheet        - The sheet number

    Output Arguments:
	sheet_name - The name

    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - One or more arguments is invalid.
 */



extern ProError ProDrawingSheetFromFormatGet (ProDrawing drawing, 
                                              int drawing_sheet, 
                                              int *format_sheet);
/*
    Purpose: Get the sheet used from the format.
 
    Input Arguments:
        drawing - The drawing handle. Set this to NULL for the current drawing.
        drawing_sheet - The sheet number of the drawing.
 
    Output Arguments:
        format_sheet - The sheet number of the format.
 
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_E_NOT_FOUND - The sheet does not have a format
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProDrawingCurrentSheetGet (
	ProDrawing drawing,
	int *current_sheet);
/*  
    Purpose: 
	Returns the current sheet number of the specified drawing.

    Input Arguments:
	drawing      - The drawing

    Output Arguments:
	current_sheet - A positive integer representing the sheet number, or
		       0  if the input argument is invalid.

    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - One or more arguments is invalid.
 */

extern ProError ProDrawingViewScaleIsUserdefined (
        ProDrawing drawing,
        ProView view,
        ProBoolean *p_is_userdefined);
/* 
    Purpose:
        Checks whether the input view has user scale assigned.

    Input Arguments:
        drawing      - The drawing
        view         - The view

    Output Arguments:
        p_is_userdefined  - returns TRUE if the view has user scale assigned 
                            returns FALSE otherwise

    Return Values:
        PRO_TK_BAD_INPUTS - When drawing or view or NULL
        PRO_TK_NO_ERROR   - Success
*/


extern ProError ProDrawingCurrentSheetSet (
        ProDrawing drawing,
	int current_sheet);
/*  
    Purpose: 
	Sets the current sheet number of the specified drawing.

    Input Arguments:
	drawing       - The drawing
	current_sheet - The new current sheet number

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - Failure (Either drawing or sheetnum 
			    is invalid in the drawing.)
*/

extern ProError ProDrawingSheetCreate (
        ProDrawing drawing,
	int *new_sheet);
/*  
    Purpose: 
	Adds a sheet to a drawing-type model. The valid drawing-type 
        models are as follows: Notebook, Format, Drawing, Diagram, Report.

    Input Arguments:
	drawing   - The drawing-type model.

    Output Arguments:
	new_sheet - The number of the sheet, if the function successfully
                     created it. Otherwise, this is -1.

    Return Values:
    PRO_TK_NO_ERROR      - The function successfully 
                           added the sheet to the model.
    PRO_TK_GENERAL_ERROR - The function failed because of an 
                           internal error.
    PRO_TK_BAD_INPUTS    - One of the arguments is bad (NULL or invalid).
    PRO_TK_E_NOT_FOUND   - The function failed because you do not 
                           have the required modules.
    PRO_TK_INVALID_ITEM  - The function did nothing because 
                           the model already has the maximum 
                           number of sheets allowed.
*/

extern ProError ProDrawingSheetDelete (
        ProDrawing drawing,
	int sheet);
/*  
    Purpose: Deletes the specified sheet from a drawing-type model. The valid 
             drawing-type models are as follows: Notebook, Format, Drawing,
             Diagram, Report.

    Input Arguments:
	drawing - The drawing-type model 
	sheet   - The number of the sheet to delete 

    Output Arguments:
	None

    Return Values:
    PRO_TK_NO_ERROR      - The function successfully 
                           deleted the drawing sheet.
    PRO_TK_GENERAL_ERROR - The function failed because of an 
                           internal error.
    PRO_TK_BAD_INPUT     - The function failed because one or 
                           more of the input arguments are invalid.
    PRO_TK_E_NOT_FOUND   - The function failed because you do not 
                           have the required modules.
    PRO_TK_INVALID_ITEM  - The function did nothing because the 
                           specified sheet is not in the specified
                           drawing.
    PRO_TK_E_DEADLOCK    - The Creo Parametric user interface is not prepared
                           to handle this request (because it is blocked by
                           another process such as an OLE container activation).
*/

extern ProError ProDrawingFormatAdd (
        ProDrawing drawing,
	int        drawing_sheet,
	ProSolid   solid,
	ProMdl     format,
	int        format_sheet);
/*  
    Purpose: Adds or replaces a drawing format in a drawing.

    Input Arguments:
	drawing       - The drawing. Set this to NULL for the 
			current drawing.
	drawing_sheet - The sheet number of the drawing. Set this to a 
                        value less than 1 for the current sheet.
        solid         - The model. 
        format        - The drawing format. 
	format_sheet  - The sheet number of the drawing format. Set this to
                        a value less than 1 for the first format sheet.

    Output Arguments:
        none.

    Return Values:    
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

typedef ProError (*ProViewVisitAction) (
        ProDrawing drawing,
	ProView    view,
	ProError   filter_status,
	ProAppData data);
/*
   Purpose:  The generic function for visiting a drawing view.

   Input Arguments:
       drawing      -  The drawing handle
       view         -  The view handle
       filter_status - The status returned by a filter function
       data     -      The application data passed to the function 
                       <b>ProDrawingViewVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/

typedef ProError (*ProViewFilterAction) (
	ProDrawing drawing,
	ProView    view,
	ProAppData data);
/*
   Purpose:  The generic function for filtering a drawing view.

   Input Arguments:
       drawing  -  The drawing handle
       view     -  The view handle
       data     -  The application data passed to the function 
                   <b>ProDrawingViewVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_CONTINUE - Skip visiting this drawing view and go to the next.
       Other           - Call the visit action for this drawing view. The 
                         return value is passed as input to the visit action.

*/


extern ProError ProDrawingViewVisit (
	ProDrawing          drawing,
	ProViewVisitAction  visit_action,
	ProViewFilterAction filter_action,
	ProAppData          data);
/*
    Purpose: Visits views in the specified  drawing.

    Input Arguments:

	drawing       - the drawing
	visit_action  - the visit action
	filter_action - the filter action. If NULL, visits
                        all views using the action function. 
	data          - the data 

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR - Success
        PRO_TK_BAD_INPUTS - One or more arguments was invalid
	PRO_TK_E_NOT_FOUND - No views were found
	Other           - Visiting was stopped by the caller supplied
			    functions with this error return.
*/
extern ProError ProDrawingViewsCollect (
    ProDrawing drawing,
    ProView    **views);
/*
   Purpose: Collects all views in the specified  drawing.

    Input Arguments:
	drawing       - the drawing

    Output Arguments:
	views   - a list of views. The function 
                  allocates the memory for this argument. 
	          To free the memory, call <b>ProArrayFree()</b>.

    Return Values:
	PRO_TK_NO_ERROR - Success
        PRO_TK_BAD_INPUTS - One or more arguments was invalid
	PRO_TK_E_NOT_FOUND - No views were found
*/

extern ProError ProDrawingViewSheetGet (
    ProDrawing drawing,
    ProView    view,
    int*        sheet);
/*  
    Purpose: Retrieves the sheet containing the drawing view
    Input Arguments:
	drawing - The drawing
	view    - The view 

    Output Arguments:
	sheet   - The sheet

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - The view no longer exists or was erased
	PRO_TK_BAD_INPUTS    - The drawing or view handles are invalid
*/

extern ProError ProDrawingErasedviewSheetGet (
    ProDrawing  drawing,
    ProView     erased_view,
    int*        sheet);
/*
    Purpose: Retrieves the sheet containing the erased drawing view.
    <b>Note: </b>the returned sheet number can be PRO_VALUE_UNUSED
    if the sheet, from which the view was erased, was subsequently removed.
 
    Input Arguments:
        drawing     - The drawing
        erased_view - The erased view
 
    Output Arguments:
        sheet   - The sheet number. Cannot be NULL.
 
    Return Values:
        PRO_TK_NO_ERROR    - Success
        PRO_TK_BAD_CONTEXT - The view is not erased, ProDrawingViewSheetGet should be used
        PRO_TK_BAD_INPUTS  - The drawing or view handles are invalid
*/

extern ProError ProDrawingViewOutlineGet (
    ProDrawing drawing,
    ProView    view,
    ProPoint3d outline[2]);
/*  
    Purpose: Retrieves the view outline, in logical screen coordinates. 

    Input Arguments:
	drawing - The drawing
	view    - The view 

    Output Arguments:
	outline   - The view outline

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_BAD_INPUTS    - The drawing or view handles are invalid
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewScaleGet (
	ProDrawing drawing,
	ProView    view,
	double     *scale);
/*   
    Purpose:  Retrieves the scale of the specified view.

    Input Arguments:
	drawing - The drawing
	view    - The view

    Output Arguments:
	scale - The view scale

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewScaleSet (
	ProDrawing drawing,
	ProView    view,
	double     scale);
/*   
    Purpose: Sets the scale of a view. This function works for views 
             displayed in the current window only.

    Input Arguments:
	drawing - The drawing
	view    - The view 
	scale   - The view scale

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewMove (
        ProDrawing drawing,
	ProView    view,
	ProVector  move_vector);
/*   
    Purpose: Moves a view (by a vector) to a new position, in logical screen 
             coordinates.

    <b>NOTE: </b>
       Use only for views displayed in the current window.

    Input Arguments:
        drawing     - The drawing
	view        - The view
	move_vector - A vector describing the view translation

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewDelete (
        ProDrawing drawing,
        ProView    view,
        ProBoolean delete_children);
/*  
    Purpose: Deletes the specified view from the drawing. 

    Input Arguments:
	drawing         - The drawing.
	view            - The view.
	delete_children - Set this to TRUE if child views are to be
                          deleted; otherwise, set this to FALSE.
                          If delete_children is FALSE and child views
                          exist, the parent view will not be deleted.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewTransformGet (
	ProDrawing drawing,
	ProView    view,  
	ProBoolean view_to_drawing, 
	ProMatrix  transform);
/*  
    Purpose: Return a transformation matrix from view csys to drawing csys 
             and vice versa.

    Input Arguments:
	drawing         - The drawing.
	view            - The view.
	view_to_drawing - The direction for transformation
  
  Output Arguments:
	transform       - The transformation matrix between the view and the drawing.

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/


typedef ProError (*ProSolidVisitAction)  (
    ProSolid   solid,
    ProError   filter_status,
    ProAppData data);
/*
   Purpose:  The generic function for visiting a solid.

   Input Arguments:
       solid          -  Solid handle
       filter_status  -  Value returned bya filter function
       data           -  Application data passed to the function 
                         <b>ProDrawingSolidsVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/


typedef ProError (*ProSolidFilterAction)  (
    ProSolid   solid,
    ProAppData data);
/*
   Purpose:  The generic function for filtering a solid.

   Input Arguments:
       solid    -  The solid handle
       data     -  The application data passed to the function 
                   <b>ProDrawingSolidsVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_CONTINUE - Skip visiting this solid and go to the next.
       Other           - Call the visit action for this solid. The return 
                         value is passed as input to the visit action.
 
*/

extern ProError ProDrawingSolidsVisit (
    ProDrawing           drawing,
    ProSolidVisitAction  visit_action,
    ProSolidFilterAction filter_action,
    ProAppData           app_data);
/*   
    Purpose: Visits models in the specified drawing.

    Input Arguments:
	drawing       - the drawing
	visit_action  - visit action 
	filter_action - filter action. If NULL, visits
                        all drawings using the action function.
	app_data      - data for this action 

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR  - Success
	PRO_TK_BAD_INPUTS - One or more arguments was invalid
	PRO_TK_E_NOT_FOUND - No drawing models were found
	Other           - Visiting was stopped by the caller supplied
			    functions with this error return.
*/

extern ProError ProDrawingSolidsCollect (
    ProDrawing drawing,
    ProSolid   **solids);
/*   
    Purpose: Retrieves an array of pointers to the models that belong
             to a drawing.
    <p>
    <b>NOTES: </b>
	<p>A model is in a drawing if it has been explicitly added by the 
        user. For assemblies, only the root assembly appears in the 
        list. 

    Input Arguments:
	drawing         - The drawing.

    Output Arguments:
	solids          - A list of models. The function 
	                  allocates the memory for this argument. 
                          To free the memory, call <b>ProArrayFree()</b>.

    Return Values:
	PRO_TK_NO_ERROR  - Success
	PRO_TK_BAD_INPUTS - One or more arguments was invalid
	PRO_TK_E_NOT_FOUND - No drawing models were found
*/

extern ProError ProDrawingViewSolidGet (
    ProDrawing drawing,
    ProView    view,
    ProSolid   *solid);
/*   
    Purpose: Returns the model displayed in a view. In simplified views, the 
             normal model pointer will be returned, not a pointer to the 
             invisible simplified instance.

    Input Arguments:
	drawing - the drawing 
	view    - the view identifier

    Output Arguments:
	 solid - the model displayed in a view.

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingScaleGet (
    ProDrawing drawing,
    ProSolid   solid,
    int        sheet,
    double     *scale);
/*  
    Purpose: Retrieves the scale of the model on the specified 
	     sheet of the drawing. 

    Input Arguments:
	drawing - The drawing. 
	solid   - The model in the drawing. If this is NULL, the function
	          uses the default model in the drawing. If there is no
		  model, the function sets the scale to 1.0.
	sheet   - The sheet number.  If the value is less than 1, the 
		  function uses the current sheet.

    Output Arguments:
	scale   - The scale of the model in the drawing.

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_BAD_INPUTS    - One or more of the arguments is invalid.
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingScaleSet (
    ProDrawing drawing,
    ProSolid   solid,
    int        sheet,
    double     scale);
/*   
    Purpose: 
	Sets the scale of the specified model on the 
	specified sheet of the drawing.

    Input Arguments:
	drawing - The drawing.
	solid   - The model in the drawing. If this is NULL, the function 
	          uses the default model in the drawing. If there is no
		  model, the function sets the scale to 1.0. 
	sheet   - The sheet number. If the value is less than 1, the 
                  function uses the current sheet.
	scale   - The scale of the model in the drawing. 

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingSolidAdd (
    ProDrawing drawing,
    ProSolid   solid);
/*   
    Purpose: 
	Adds the specified model to the drawing.

    Input Arguments:
	drawing - The drawing
	solid   - The model to add to the drawing

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR          - The function successfully 
	                           added the model to the drawing.
	PRO_TK_GENERAL_ERROR     - The function failed because of an 
	                           internal error.
	PRO_TK_BAD_INPUTS        - The function failed because one or 
	                           more of the input arguments are invalid.
	PRO_TK_E_IN_USE          - The function did nothing because the   
	                           specified model already exists.
*/

extern ProError ProDrawingSolidDelete (
    ProDrawing drawing,
    ProSolid   solid);
/*   
    Purpose: 
	Deletes the specified model from the drawing.

    Input Arguments:
	drawing    - The drawing 
	solid   - The model to delete

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully 
                               deleted the model.
	PRO_TK_GENERAL_ERROR - The function failed because of an 
                               internal error.
	PRO_TK_BAD_INPUTS    - The function failed because one 
                               or more of the input arguments are 
                               invalid.
	PRO_TK_BAD_CONTEXT   - The function did nothing because 
                               the model is NULL.
	PRO_TK_E_NOT_FOUND   - The function failed because the 
                               specified model is not in the drawing.
	PRO_TK_E_IN_USE      - The function failed because the 
                               specified model is referenced by 
                               a view.
*/

extern ProError ProDrawingGeneralviewCreate (
    ProDrawing drawing,
    ProSolid   solid,
    int        sheet_number,
    ProBoolean exploded,
    ProPoint3d position,
    double     scale,
    ProMatrix  orientation,
    ProView    *view);
/*  
    Purpose: 
	Creates a nonparametric general drawing view.
        <p><b>NOTE:</b>Display the drawing using ProMdlDisplay() before
                       calling this function.

    Input Arguments:
	drawing      -	The drawing. 
	solid        -  The drawing model of which to create 
			the view
	sheet_number -	The number of the sheet on which 
			to place the view  
	exploded     -	Set to TRUE to make an exploded view 
			of an assembly model.
	position     -	The position of the view on the screen
	scale        -	If scale >0, the view has an associated
			scale. If scale<=0, the view has the 
			default scale.
	orientation  -  The orientation of the model in the view

    Output Arguments:
	view  -  The view.

    Return Values:
	PRO_TK_NO_ERROR             - The function succeeded.
        PRO_TK_BAD_INPUTS           - One or more input arguments was invalid,
                                      or the drawing was not displayed.
        PRO_TK_CRE_VIEW_BAD_SHEET   - The specified sheet does not exist. 
        PRO_TK_CRE_VIEW_BAD_MODEL   - The specified model is not in the list of
                                      drawing models, or the function cannot
                                      make the specified view of this model.
        PRO_TK_CRE_VIEW_BAD_EXPLODE - The function cannot explode the view 
                                      model.
	PRO_TK_GENERAL_ERROR        - A miscellaneous error occured, and the 
                                      function failed.
*/

extern ProError ProDrawingProjectedviewCreate (
    ProDrawing drawing,
    ProView    parent_view,
    ProBoolean exploded,
    ProPoint3d position,
    ProView    *view);
/*   
    Purpose:  Creates a projected drawing view. The projection view parent 
              must be any of the following types: broken, unfolded xsec, 
              align xsec, of surface, or of flat ply.
              <p><b>NOTE:</b>Display the drawing using ProMdlDisplay() before
                             calling this function. 

    Input Arguments:
	drawing      -  The drawing. 
	parent_view  -  The  parent view
	exploded     -	Set to TRUE to make an exploded view 
			of an assembly model.
	position     -	The position of the view on the screen

    Output Arguments:
	view  -  The view.

    Return Values:
	PRO_TK_NO_ERROR             - The function succeeded. 
        PRO_TK_BAD_INPUTS           - One or more input arguments was invalid,
                                      or the drawing was not displayed.
        PRO_TK_CRE_VIEW_BAD_SHEET   - The specified sheet does not exist.
        PRO_TK_CRE_VIEW_BAD_MODEL   - The specified model is not in the list of
                                      drawing models, or the function cannot
                                      make the specified view of this model.
        PRO_TK_CRE_VIEW_BAD_PARENT  - The parent view for project does not
                                      exist, or is of unsupported type, or
                                      does not align with the selected position.
        PRO_TK_CRE_VIEW_BAD_EXPLODE - The function cannot explode the view 
                                      model.
	PRO_TK_GENERAL_ERROR        - A miscellaneous error occured, and the 
                                      function failed.

*/

extern ProError ProDrawingViewIsOverlay (
    ProDrawing drawing,
    ProView    view,
    ProBoolean *is_overlay);
/*   
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProDrawingViewIsBackground
    Purpose: 
<P><B>NOTE : This function is superseded by 
	ProDrawingViewIsBackground()
</B></P>
	Determines if the view specified by view is an 
	overlay view.

    Input Arguments:
	drawing - The drawing
	view    - The view identifier

    Output Arguments:
	is_overlay - TRUE if the view specified by view is an 
		     overlay view.

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully retrieved 
                               the information.
	PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProDrawingOverlayviewGet (
    ProDrawing drawing,
    int        sheet,
    ProView    *overlay_view);
/*   
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProDrawingBackgroundViewGet
    Purpose: 
<P><B>NOTE : This function is superseded by 
	ProDrawingBackgroundViewGet ()
</B></P>
	Returns the overlay view identifier of the specified sheet. 
        All sheets have exactly one overlay view.

    Input Arguments:
	drawing        - The drawing
	sheet          - The drawing sheet number

    Output Arguments:
	overlay_view  - output overlay view

    Return Values:
	PRO_TK_NO_ERROR      - Success 
	PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingAsmsimprepAdd (
    ProDrawing drawing,
    ProSimprep *simp_rep);
/*   
    Purpose: 
	Adds the specified simplified representation to the drawing.

    Input Arguments:
        drawing          - The drawing handle
	simp_rep         - The the simplified representation

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully added the simplified
	                       representation to the drawing.
	PRO_TK_GENERAL_ERROR - The simplified representation was not
                               added to the drawing.
	PRO_TK_BAD_INPUTS    - The function failed because one or more of
                               the input arguments are invalid.
	PRO_TK_E_FOUND       - The function did nothing because the
                               specified simplified representation already
                               exists.
*/

extern ProError ProDrawingAsmsimprepDelete (
    ProDrawing drawing,
    ProSimprep *simp_rep);
/*  
    Purpose: 
	Deletes the specified simplified representation 
	from the drawing.

    Input Arguments:
        drawing  - The drawing handle
	simp_rep - The simplified representation

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      - The function successfully deleted the
                               simplified representation from the
                               drawing.
	PRO_TK_GENERAL_ERROR - The function failed because of an
                               internal error.
	PRO_TK_BAD_INPUTS    - The function failed because one or
                               more of the input arguments are
                               invalid.
	PRO_TK_BAD_CONTEXT   - The function did nothing because the
                               simplified representation is null.
	PRO_TK_E_NOT_FOUND   - The function failed because the
                               specified simplified representation
                               is not in the drawing.
	PRO_TK_E_IN_USE      - The function failed because the 
                               specified model and simplified
                               representation are referenced by
                               another view in the drawing.
*/

extern ProError ProDrawingSimprepsCollect (
    ProDrawing drawing,
    ProSolid   solid,
    ProSimprep **simpreps);
/*  
    Purpose:  
	Returns the number of simplified representations that belong
        to the specified model and that are referenced by the specified
        drawing.

    Input Arguments:
	drawing  - The drawing handle
	solid    - The model handle

    Output Arguments:
	simpreps   - The list of simplified representations. The function 
	             allocates the memory for this argument. 
	             To free the memory, call <b>ProArrayFree()</b>.

	n_simpreps - The number of simplified representations of the
                     specified model found in the drawing.

    Return Values:
	PRO_TK_NO_ERROR       - Success
	PRO_TK_GENERAL_ERROR  - Failure (NULL drawing or solid, invalid 
                                drawing, model not referenced by drawing, 
                                or bad input.)
*/

extern ProError ProDrawingSheetsReorder (
    ProDrawing drawing,
    int from_sheet,
    int to_sheet);
/*  
    Purpose:  
	Changes a drawing sheet to a new sheet number.

    Input Arguments:
	drawing    - The drawing handle
	from_sheet - The current drawing sheet number
        to_sheet   - The sheet number to move the sheet to.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - Success
	PRO_TK_BAD_INPUTS - Failure (NULL drawing or solid, or invalid 
	                    'from' or 'to' sheet number.)
*/


extern ProError ProDrawingDimensionVisit(
   ProDrawing               drawing,
   ProType                  type,
   ProDimensionVisitAction  action,
   ProDimensionFilterAction filter,
   ProAppData               data );
/*
    Purpose:
	Visits all dimensions stored in the specified drawing,
	i.e. all dimensions whose default names start with
	"dd", "rdd" or "add", therefore all dimensions created in
	the drawing when the config.pro option "create_drawing_dims_only"
	was set to YES.

    Input Arguments:
	drawing		-  Handle of the drawing whose dimensions are to
			   be visited.
	type		-  PRO_DIMENSION or PRO_REF_DIMENSION 
	action		-  the function that gets called for each drawing
			   dimension being visited.
	filter		-  the function that gets called for each drawing
			   dimension. This function decides whether the
			   dimension should be visited or skipped. If NULL,
                           all dimensions are visited using the action function.
	data		-  caller-specified data that gets passed to the
			   action and filter functions.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - The function successfully visited all
			    the model's dimensions.
	PRO_TK_BAD_INPUTS - The function failed because one or
			    more of the input arguments are invalid.
	PRO_TK_E_NOT_FOUND - No drawing dimensions were visited.
	PRO_TK_GENERAL_ERROR - An error occurred while locating the dimensions.
	other	          - Visiting was stopped by the caller supplied
			    functions with this error return.
*/ 

extern ProError ProDrawingSolidReplace(
        ProDrawing      drawing,
        ProSolid        from,
        ProSolid        to,
        ProBoolean      unrepresent_ok);

/*
   Purpose: Replaces a drawing model solid with another solid.
            The old and new solids must be members of the same
            family table.

   Input Arguments:
      drawing           - The drawing
      from              - The solid to be replaced
      to                - The solid to replace it
      unrepresent_ok    - TRUE = unrepresent any simplified views
                          of the 'from' solid in drawing.
                          FALSE = fail if the 'from' solid has
                          at least one simplified view in drawing.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR 
      PRO_TK_BAD_INPUTS         - One of the first three arguments
                                  was NULL.
      PRO_TK_E_NOT_FOUND        - The 'from' model is not in the
                                  drawing.
      PRO_TK_E_FOUND            - The 'to' model is already in the
                                  drawing.
      PRO_TK_BAD_CONTEXT        - unrepresent_ok was FALSE, but
                                  the "from" solid had a
                                  simplified view.
				  OR 'from' and 'to' solids were not
                                  from the same family table.
*/


extern ProError ProDrawingPosToLocgrid( ProDrawing p_draw,
                                        int sheet,
                                        ProVector pos,
                                        ProName column_label,
                                        ProName row_label);
/*
  Purpose: Outputs the location grid column and row for
           a specified location in screen coordinates.

   Input Arguments:
      p_draw            - The drawing
      sheet             - The sheet number
      pos               - The location in screen coordinates

   Output Arguments:
      column_label      - The label on the corresponding location grid column.
      row_label         - The label on the corresponding location grid row.

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS - Drawing is invalid, or specified sheet does not exist
      PRO_TK_NOT_EXIST  - No location grid is defined on the specified sheet
      PRO_TK_OUT_OF_RANGE - 'pos' is outside of the location grid
*/ 

extern ProError  ProDwgcreateErrsFree (
	ProDwgcreateErrs* errors);
/*
 
   Purpose:  Frees an existing errors table.

   Input Arguments:
      errors		- A pointer to the errors table.
     

   Output Arguments:
       None.

   Return Values:
      PRO_TK_NO_ERROR   -  The error structure was freed.
      PRO_TK_BAD_INPUTS -  The argument is invalid.
*/

extern ProError  ProDwgcreateErrsCountGet (
	ProDwgcreateErrs errors, 
 	int* count);
/*
 
   Purpose: Returns the number of drawing creation errors in the table.

   Input Arguments:
      errors	  	-  The errors table.
     
   Output Arguments:
       count            - The number of errors in the table.

   Return Values:
      PRO_TK_NO_ERROR   -  The function successfully counted the number of 
                           errors.
      PRO_TK_BAD_INPUTS - The argument is invalid.
*/


extern ProError  ProDwgcreateErrTypeGet (
	ProDwgcreateErrs errors, 
	int error_num, 
	ProDwgcreateErrType* type);
/*
 
   Purpose:  Returns the type of a drawing creation error.

   Input Arguments:
      errors		-  The errors table.
      error_num         -  The error number.
     
   Output Arguments:
       type             - The error type.

   Return Values:
      PRO_TK_NO_ERROR   -  The function successfully found error and
                           initialized type
      PRO_TK_BAD_INPUTS -  The errors argument is invalid.
      PRO_TK_E_NOT_FOUND - The error specified by error_num was not found.
*/

extern ProError    ProDwgcreateErrViewNameGet (
        ProDrawing drawing,
	ProDwgcreateErrs errors, 
	int error_num, 
	ProName template_view_name);
/*
 
   Purpose:  Returns the name of the template view where the error occurred.

   Input Arguments:
      drawing           -  The instantiated drawing
      errors		-  The errors table.
      error_num         -  The error number.
     
   Output Arguments:
       template_view_name  -  The view template name.

   Return Values:
     PRO_TK_NO_ERROR     - The function successfully returned the view template
                           name.
     PRO_TK_BAD_INPUTS   - The errors argument is invalid.
     PRO_TK_E_NOT_FOUND  - The error specified by error_num was not found.
     PRO_TK_INVALID_TYPE - The error specified by error_num was the wrong type
                            for a view name.
*/

extern ProError    ProDwgcreateErrSheetGet (
        ProDrawing drawing,
	ProDwgcreateErrs errors, 
	int error_num, 
	int* sheet_num);
/*
 
   Purpose:  Returns the drawing sheet number where the error occurred.

   Input Arguments:
      drawing           -  The instantiated drawing
      errors		-  The errors table.
      error_num         -  The error number.
     
   Output Arguments:
       sheet_num      -  The sheet number.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully returned the sheet number.
      PRO_TK_BAD_INPUTS  - The errors argument is invalid.
      PRO_TK_E_NOT_FOUND - The error specified by error_num was not found.
      PRO_TK_INVALID_TYPE - The error specified by error_num was the wrong type
                            for a sheet number.
*/

extern ProError  ProDwgcreateErrViewGet (
        ProDrawing drawing,
	ProDwgcreateErrs errors, 
	int error_num, 
	ProView* view);
/*
 
   Purpose:  Returns the drawing view where the error occurred.  This function
             is valid for the following error types:
    		PRODWGCRTERR_EXPLODE_DOESNT_EXIST
    		PRODWGCRTERR_MODEL_NOT_EXPLODABLE
    		PRODWGCRTERR_SEC_NOT_PERP
    		PRODWGCRTERR_NO_RPT_REGIONS
    		PRODWGCRTERR_FIRST_REGION_USED
    		PRODWGCRTERR_NOT_PROCESS_ASSEM
    		PRODWGCRTERR_TEMPLATE_USED
    		PRODWGCRTERR_SEC_NOT_PARALLEL
    		PRODWGCRTERR_SIMP_REP_DOESNT_EXIST      

   Input Arguments:
      drawing           -  The instantiated drawing
      errors		-  The errors table.
      error_num         -  The error number.
     
   Output Arguments:
       view             - The view, or NULL if the view was not created at all.

   Return Values:
      PRO_TK_NO_ERROR -  The function successfully returned the view.
      PRO_TK_BAD_INPUTS - The errors argument is invalid.
      PRO_TK_E_NOT_FOUND - The error specified by error_num was not found.
      PRO_TK_INVALID_TYPE - The error specified by error_num was the wrong type
                            for a view.
*/

extern ProError  ProDwgcreateErrObjNameGet (
        ProDrawing drawing,
	ProDwgcreateErrs errors, 
	int error_num, 
	ProName  inv_obj_name);
/*
 
   Purpose:  Returns the name of the model entity which was not found or 
             invalid.  This function is valid for the following error types:
	 	PRODWGCRTERR_SAVED_VIEW_DOESNT_EXIST
    		PRODWGCRTERR_X_SEC_DOESNT_EXIST
    		PRODWGCRTERR_EXPLODE_DOESNT_EXIST
    		PRODWGCRTERR_SEC_NOT_PERP
    		PRODWGCRTERR_SEC_NOT_PARALLEL
    		PRODWGCRTERR_SIMP_REP_DOESNT_EXIST      	

   Input Arguments:
      drawing           -  The instantiated drawing
      errors		-  The errors table.
      error_num         -  The error number.
     
   Output Arguments:
       inv_obj_name   - The name of the invalid object, or NULL, if not 
                          applicable to this error type.

   Return Values:
      PRO_TK_NO_ERROR -  The function successfully returned the invalid object
                         name.
      PRO_TK_BAD_INPUTS - The errors argument is invalid.
      PRO_TK_E_NOT_FOUND - The error specified by error_num was not found.
*/

extern ProError ProDrawingFromTmpltCreate(
    ProName new_name,
    ProName dwg_template,
    ProModel* new_model,
    ProDwgcreateOptions options,  
    ProDrawing* drawing,
    ProDwgcreateErrs* errors);

/*
 
   Purpose:  Creates a new drawing from a template

   Input Arguments:

      new_name		- The name for the new drawing
      dwg_template	- The name of the drawing template
      new_model		- The name and type of the solid model
                          to be used in the new drawing. 
      options           - Flags for drawing creation.  Options include:
                          <UL>
                          <LI>PRODWGCREATE_DISPLAY_DRAWING: display new drawing
                                                           in a window.
                          <LI>PRODWGCREATE_SHOW_ERROR_DIALOG: display template
                                                             error dialog to 
                                                             the user.
                          <LI>PRODWGCREATE_WRITE_ERRORS_TO_FILE: write errors 
                                                                to disk file.
                          </UL>
    
   Output Arguments:
 
     drawing		- The new drawing

      errors            - The list of warnings and errors caused by the 
                          creation.      

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully created the drawing,
                                without errors.
      PRO_TK_E_FOUND          - The drawing with name new_name already exists.
      PRO_TK_E_NOT_FOUND      - The template and/or the drawing model was not 
                                found.
      PRO_TK_DWGCREATE_ERRORS - The function created the drawing, but there 
                                were one or more errors.
      PRO_TK_NO_PERMISSION    - The function does not have permission to open
				the template or the solid model.
*/

extern ProError ProDrawingViewIsBackground (
    ProDrawing drawing,
    ProView    view,
    ProBoolean *is_background);
/*
    Purpose:
        Determines if the view specified by view is an
        overlay view. 

    Input Arguments:
        drawing - The drawing
        view    - The view identifier

    Output Arguments:
        is_background - TRUE if the view specified by view is an
                        overlay view.

    Return Values:
        PRO_TK_NO_ERROR      - Success (The specified view identifier is
                               an overlay view.)
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewNameGet (ProDrawing drawing,
                                       ProView view,
                                       ProName name);

/* 
   Purpose:  Returns the name of a view in the drawing.

   Input Arguments:
      drawing      - The handle to the drawing.
      view         - The view handle.  

   Output Arguments:
      name  - The view name.

   Return Values:
      PRO_TK_NO_ERROR      - Function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The view did not have a name.

*/

extern ProError ProDrawingBackgroundViewGet (
    ProDrawing drawing,
    int        sheet,
    ProView    *background_view);
/*   
    Purpose: 
        Returns the overlay view identifier of the specified sheet. 
        All sheets have exactly one overlay view.

    Input Arguments:
        drawing       - The drawing
        sheet  - The drawing sheet number

    Output Arguments:
        background_view  - output overlay view

    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProDrawingViewZclippingSet (ProDrawing drawing, 
                			    ProView view, 
                                            ProSelection zclip_geometry);
/*
    Purpose:  Sets the Z-clipping on the drawing view to reference the
              given edge, datum, or point on surface.

    Input Arguments:
            drawing        - The drawing handle.
            view           - The view handle.
            zclip_geometry - The edge, datum, or point on surface used to
                             calculate Z-clipping.

    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR     - The function succeeded.
            PRO_TK_BAD_INPUTS   - One or more invalid arguments was supplied.
            PRO_TK_INVALID_TYPE - This type of view cannot be assigned
                                  Z-clipping.
*/

extern ProError ProDrawingViewZclippingGet (ProDrawing drawing, 
                                            ProView view, 
				  	    ProSelection* zclip_geometry);
/*
    Purpose:  Gets the drawing view Z-clipping reference (the edge, datum
              or point on surface).

    Input Arguments:
            drawing - The drawing handle.
            view - The view handle.

    Output Arguments:
            zclip_geometry - The edge, datum, or point on surface used
                             to calculate Z-clipping.

    Return Values:
            PRO_TK_NO_ERROR     - The function succeeded.
            PRO_TK_BAD_INPUTS   - One or more invalid arguments was supplied.
            PRO_TK_INVALID_TYPE - This type of view cannot be assigned
                        	  Z-clipping.
            PRO_TK_E_NOT_FOUND  - The view has not been assigned Z-clipping.
*/

extern ProError ProDrawingCurrentsolidGet (ProDrawing drawing, ProSolid* solid);
/*
Purpose: 
Gets the current drawing solid model for the drawing.

Input Arguments: 
		drawing  -  The drawing handle.

Output Arguments:
        solid    -  The current solid model.  
 
Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND - No current model is assigned to the drawing.
*/

extern ProError ProDrawingCurrentsolidSet (ProDrawing drawing, ProSolid solid);
/*
Purpose: 
Sets the current drawing solid model for the drawing.  To see changes to parameters and fields reflecting the change of the current solid model, regenerate the drawing using ProDwgSheetRegenerate().

Input Arguments: 
		drawing - The drawing handle.
        solid   - The current solid model.  

Output Arguments:
        none
 
Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND - The solid is not included in the drawing.
*/




extern ProError ProDrawingViewDatumdisplayGet (ProDrawing   drawing,
                                               ProView      view,
                                               ProSelection datum,
                                               ProViewItemdisplayStatus *status);

/*
Purpose: Determines if the specified datum is displayed in the drawing view.

Input Arguments:
  drawing  - The drawing handle.
  view     - The view handle.
  datum    - The handle to a datum plane, axis, or cosmetic feature.
             If the view display contains an assembly, and the datum is in a
             component in that assembly, this must include the component path.

Output Arguments:
  status  - Whether or not the item is shown in this view.

Return Values:
  PRO_TK_NO_ERROR    - The function returned the information.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_BAD_CONTEXT - The top level assembly in the selection does not match
                       the model shown in this view.
*/


extern ProError ProDrawingDualDimensionGet (ProDrawing  drawing,
                                            ProDualDimensionType *dual_dimensioning,
                                            ProName     dual_secondary_units,
                                            int        *dual_digits_diff,
                                            ProBoolean *dual_dimension_brackets);

/*
Purpose: Returns the current status of dual dimensioning in a drawing.

Input Arguments:
  drawing - The drawing handle.

Output Arguments:
  dual_dimensioning    - The type of dual dimensioning shown.
  dual_secondary_units - The type of units used for the secondary dimension.
  dual_digits_diff     - The number of digits shown in the secondary value,
                         with respect to the primary.
  dual_dimension_brackets - Whether or not to use brackets in dual dimensioning.

Return Values:
  PRO_TK_NO_ERROR - The function successfully retrieved the information.
  PRO_TK_BAD_INPUTS - The input argument is invalid.
*/




extern ProError ProDrawingOLEobjectsVisit( ProDrawing               drawing, 
					   ProModelitemVisitAction  action,
					   ProModelitemFilterAction filter, 
					   ProAppData               app_data );

/*
    Purpose: Visits the OLE objects embedded in the model.

    Input Arguments:
        drawing  - The drawing, notebook, format, report, or diagram.
        action   - The visit action
        filter   - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No items were found.
        Any other value    - Visiting stopped due to this error return from the 
                             visit action.

*/


extern ProError ProDrawingOLEobjectSheetGet( ProModelitem* ole_object, int* sheet );

/*
    Purpose: Returns the sheet index on which the OLE object is embedded.

    Input Arguments:
        ole_object - The OLE object.

    Output Arguments:
        sheet - The sheet number.

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProDrawingOLEobjectPathGet( ProModelitem* ole_object, ProPath path );

/*
    Purpose: Returns the path to the file which is referenced by the OLE 
             object.

    Input Arguments:
        ole_object - The OLE object.

    Output Arguments:
        path - The path to the external file.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The object refers to a fully embedded object and 
                             not an external file.
*/

extern ProError ProDrawingOLEobjectApplicationtypeGet( ProModelitem* ole_object, ProPath type );
/*
    Purpose: Returns the type of the object embedded in the model.
             
             

    Input Arguments:
        ole_object - The OLE object.

    Output Arguments:
        type - The type of application used for the object.  

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingOLEobjectOutlineGet( ProModelitem* ole_object, ProPoint3d outline[2] );
/*
    Purpose: Obtains the extents of the OLE object in the drawing.

    Input Arguments:
        ole_object - The OLE object.

    Output Arguments:
        outline - The upper left and lower right coordinates of the OLE object.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDtlentityIsOLEObject( ProDtlentity* entity, ProBoolean* is_ole_object );
/*
    Purpose: Identifies whether a given detail entity is an OLE object.
 
    Input Arguments:
        entity - The detail entity.
 
    Output Arguments:
        is_ole_object -  PRO_B_TRUE if the object is an OLE object, PRO_B_FALSE otherwise.
 
    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid

    See Also:
        ProDrawingOLEobjectSheetGet()
        ProDrawingOLEobjectPathGet()
        ProDrawingOLEobjectApplicationtypeGet()
        ProDrawingOLEobjectOutlineGet()
*/


typedef struct pro_edgedispdata* ProDrawingEdgeDisplay;

extern ProError ProDrawingEdgeDisplayGet (ProSelection edge_sel, ProDrawingEdgeDisplay* edge_display);
/*
    Purpose: Gets the edge display properties of a given edge.

    Input Arguments:
        edge_sel - Selection of the edge; must include the drawing view.

    Output Arguments:
        edge_display - The edge display properties.  Free this using 
                       ProDrawingedgedisplayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingEdgeDisplaySet (ProSelection edge_sel, ProDrawingEdgeDisplay edge_display);
/*
    Purpose: Sets the edge display properties of a given edge.  You must 
             repaint the drawing to update the display.

    Input Arguments:
        edge_sel - Selection of the edge; must include the drawing view.
        edge_display - The edge display properties.  

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayColorGet (ProDrawingEdgeDisplay edge_display, ProColor* color);
/*
    Purpose: Obtains the color to use for the edge display.

    Input Arguments:
        edge_display - The edge display object.

    Output Arguments:
        color - The color to use for edge display.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayColorSet (ProDrawingEdgeDisplay edge_display, ProColor* color);
/*
    Purpose: Assigns the color to use for the edge display.

    Input Arguments:
        edge_display - The edge display object.
        color - The color to use for edge display.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayFontGet (ProDrawingEdgeDisplay edge_display, ProName font);
/*
    Purpose: Obtains the line font to use for edge display.

    Input Arguments:
        edge_display - The edge display object.

    Output Arguments:
        font - The name of the font to use for edge display.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The edge display uses the default font.

*/

extern ProError ProDrawingedgedisplayFontSet (ProDrawingEdgeDisplay edge_display, ProName font);
/*
    Purpose: Assigns the line font to use for edge display.

    Input Arguments:
        edge_display - The edge display object.
        font - The name of the font to use for edge display  Pass NULL to use 
               the default font.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayWidthGet (ProDrawingEdgeDisplay edge_display, double* width);
/*
    Purpose: Obtains the width in screen coordinates to use for the edge display.
<p><b>Note: </b>The width obtained can be different from the value displayed in 
the UI, which is in drawing coordinates. To convert the width value into drawing 
coordinates, use the sheet transformation matrix obtained using ProDrawingSheetTrfGet().

    Input Arguments:
        edge_display - The drawing edge display object.

    Output Arguments:
        width - The width in screen coordinates to use for the edge display.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The default edge width is used.

*/

extern ProError ProDrawingedgedisplayWidthSet (ProDrawingEdgeDisplay edge_display, double width);
/*
    Purpose: Assigns the width in screen coordinates to use for the edge display.
<p><b>Note: </b>The width assigned can be different from the value assigned in 
the UI, which is in drawing coordinates. To convert the width value into drawing 
coordinates, use the sheet transformation matrix obtained using ProDrawingSheetTrfGet().

    Input Arguments:
        edge_display - The drawing edge display object.
        width - The width in screen coordinates to use for the edge display. Pass 
                a value less than 0 to use the default width.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayIsGlobal (ProDrawingEdgeDisplay edge_display, ProBoolean* is_global);
/*
    Purpose: Identifies if the edge display properties (color, font, and width) 
             are applied globally to all views in the drawing sheet.

    Input Arguments:
        edge_display - The drawing edge display.

    Output Arguments:
        is_global - PRO_B_TRUE if the edge display properties (color, font, and 
                    width) are applied globally to all views on the sheet 
                    showing the edge.  PRO_B_FALSE if the display is applied 
                    only on the single selected edge.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayGlobalSet (ProDrawingEdgeDisplay edge_display, ProBoolean is_global);
/*
    Purpose: Assigns if the edge display properties (color, font, and width) 
             are applied globally to all views in the drawing sheett.

    Input Arguments:
        edge_display - The drawing edge display.
        is_global - PRO_B_TRUE if the edge display properties (color, font, and 
                    width) are applied globally to all views on the sheet 
                    showing the edge.  PRO_B_FALSE if the display is applied 
                    only on the single selected edge.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingedgedisplayFree (ProDrawingEdgeDisplay edge_display);
/*
    Purpose: Frees the memory used by an edge display object.

    Input Arguments:
        edge_display - The edge display object.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingViewNeedsRegen (ProDrawing drawing, ProView view, ProBoolean *needs_regen);
/*
Purpose: Identifies whether the drawing or the given drawing view needs to
         be regenerated.

Input Arguments:
  drawing - The drawing.
  view    - The drawing view, if checking on update for a specific view.
            Pass NULL to check for the whole drawing.

Output Arguments:
  needs_regen - PRO_B_TRUE if the drawing or view needs regeneration,
                PRO_B_FALSE otherwise.

Return Values:
  PRO_TK_NO_ERROR   - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDrawingSheetFormatIsBlanked (ProDrawing drawing, int sheet, ProBoolean *is_blanked);
/*
    Purpose: Checks if the sheet format is blanked.

    Input Arguments:
        drawing    - The drawing handle. Set this to NULL for the current
                     drawing.
        sheet      - The sheet number. Set this to a value less than 1 for
                     the current sheet.

    Output Arguments:
        is_blanked - PRO_B_TRUE if sheet format is blanked,
                     PRO_B_FALSE if sheet format is not blanked

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDrawingSheetCopy (ProDrawing drawing, int sheet_to_copy, int *sheet_copy);
/*
    Purpose: Create a copy of a drawing sheet.

    Input Arguments:
        drawing    - The drawing handle. Set this to NULL for the current drawing.
        sheet_to_copy - The sheet number of the sheet to create a copy of.
                        Set this to a value less than 1 for the current sheet.
    Output Arguments:
        sheet_copy - The sheet number of the copy.

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - Invalid model type specified.
        PRO_TK_CANT_MODIFY - Drawing can't be modified.
        PRO_TK_CANT_WRITE - Drawing sheet copy attempt failed.
*/

extern ProError ProDrawingtreeRefresh(ProDrawing drawing, int window_id);
/*
    Purpose: Rebuild the tree for the drawing and the window_id

    Input Arguments:
        drawing    - Handle to the drawing which contains the drawing tree.
        window_id  - Id of the window which contains the drawing 
                     Use PRO_VALUE_UNUSED to refresh the drawing tree in the 
		     active window

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid
        PRO_TK_NO_CHANGE - There is no change in the drawing tree
*/


extern ProError ProDrawingDimAttachpointsGet (
                                              ProDrawing         drawing,
                                              ProDimension       *dimension,
                                              ProDimAttachment   **attachments_arr,
                                              ProDimSense        **dsense_arr);
/*
Purpose:  Retrieves the attachments and the sense of the specified
          drawing dimension. Only applicable for dimensions created
          in drawing mode.
          This function also supports drawing dimensions created
          from intersections of geometric entities.

Input Arguments:
          drawing           - The drawing.
          dimension         - The dimension.

Output Arguments:
          attachments_arr   - ProArray of attachments. Each attach point
                              is described by two consecutive array elements,
                              of which the second one may be null.
                              If both elements are not null then the attach
                              point refers to the intersection of the elements.
                              If the second element is null then
                              the attach point refers to the first one.

                              Free this result using ProDimattachmentarrayFree().
                              Pass NULL if not interested in this output.

           dsense_arr       - ProArray of dimension sense.
                              Free this result using ProArrayFree().
                              Pass NULL if not interested in this output.

Return Values:
         PRO_TK_BAD_INPUTS   - one or more of the input arguments are
                               invalid or if both the output arguments
                               are NULL.
         PRO_TK_INVALID_ITEM - the dimension specified is not a valid
                               dimension created in drawing mode.
         PRO_TK_NO_ERROR     - successfully retrieved the attachments
                               and the sense.
         PRO_TK_INVALID_TYPE - the  dimension   sense   type  is  not
                               supported with this function.
*/


extern ProError ProDrawingtreeExpand(ProDrawing drawing, int window_id);
/*
    Purpose: Expand the tree for the drawing and the window_id

    Input Arguments:
        drawing    - Handle to the drawing which contains the drawing tree.
        window_id  - Id of the window which contains the drawing
                     Use PRO_VALUE_UNUSED to refresh the drawing tree in the
                     active window

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid
        PRO_TK_NO_CHANGE - There is no change in the drawing tree
*/

extern ProError ProDrawingtreeCollapse(ProDrawing drawing, int window_id);
/*
    Purpose: Collapse the tree for the drawing and the window_id

    Input Arguments:
        drawing    - Handle to the drawing which contains the drawing tree.
        window_id  - Id of the window which contains the drawing
                     Use PRO_VALUE_UNUSED to refresh the drawing tree in the
                     active window

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid
        PRO_TK_NO_CHANGE - There is no change in the drawing tree
*/

extern ProError ProLayoutDeclare (
			ProLayout notebook,
			ProMdl  model,
			ProDeclareOptions option
			);

/*
 Purpose:  Declares a notebook name to the specified Creo Parametric model or notebook.

 Input Arguments:
 notebook - The notebook to be declared.
     model  - The model or notebook to which the notebook is declared.
     option - The conflict resolution.

 Output Arguments:
     none
    
 Return Values:
     PRO_TK_NO_ERROR       - The function succeeded
     PRO_TK_BAD_INPUTS     - One or more arguments are invalid.
     PRO_TK_USER_ABORT     - There was a conflict between the symbols in the
                             notebook and in the object with option
                             PRO_DECLARE_ABORT.
     PRO_TK_E_DEADLOCK     - There was a circular declaration between the
                             two notebooks.
*/

extern ProError ProLayoutUndeclare (
			ProLayout notebook,
			ProMdl  model,
			ProUndeclareOptions option
			);

/*
 Purpose:  Undeclares a notebook name to the specified Creo Parametric model or notebook.

 Input Arguments:
     notebook - The notebook to be undeclared.
     model  - The model or notebook to which the notebook is undeclared.
     option  - The conflict resolution.

 Output Arguments:
     none
    
 Return Values:
     PRO_TK_NO_ERROR       - The function succeeded
     PRO_TK_BAD_INPUTS     - One or more arguments are invalid.
     PRO_TK_CANT_MODIFY    - Cant undeclare the notebook.
*/

extern ProError ProLayoutRegenerate  (ProMdl notebook);
/*
   Purpose:  Regenerates the specified notebook (A model of type PRO_MDL_LAYOUT)
 
   Input Arguments:
     notebook        - The <i>ProLayout</i> to regenerate.
     
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR         - The function successfully regenerated the
                                notebook
      PRO_TK_GENERAL_ERROR    - Failure in regeneration
      PRO_TK_BAD_INPUTS       - Bad inputs.
	  PRO_TK_INVALID_TYPE     - Model is not a notebook
*/

extern ProError ProDrawingToleranceStandardGet(ProDrawing p_draw,
                                               ProStandard *p_standard);
/*
   Purpose:  Get the assigned tolerance standard of a drawing.

   Input Arguments:
     p_draw          - The <i>ProDrawing</i> to get the tol standard for.

   Output Arguments:
     p_standard      - The tolerance standard, NULL not allowed.

   Return Values:
      PRO_TK_NO_ERROR         - Success
      PRO_TK_BAD_INPUTS       - p_draw or p_standard was invalid
*/

extern ProError ProDrawingToleranceStandardSet(ProDrawing p_draw,
                                               ProStandard new_standard);

/*
   Purpose:  Set the assigned tolerance standard of a drawing.
             Note that in the regular UI, this operation asks whether
             to regenerate the drawing.  This function will not
             itself perform regeneration.

   Input Arguments:
     p_draw          - The <i>ProDrawing</i> to set the tol standard for.
     new_standard    - The tolerance standard to set.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - Success
      PRO_TK_BAD_INPUTS       - p_draw or new_standard was invalid
      PRO_TK_GENERAL_ERROR    - An error occurred trying to set the standard.
*/

extern ProError ProDrawingSheetFormatShow (ProDrawing drawing, int sheet);
/*
    Purpose: Shows the given drawing sheet's format.

    Input Arguments:
        drawing - The drawing handle. Set this to NULL for the current drawing.
        sheet - The sheet number. Set this to a value less than 1 for the current sheet.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDrawingSheetFormatHide (ProDrawing drawing, int sheet);
/*
    Purpose: Hides the given drawing sheet's format.

    Input Arguments:
        drawing - The drawing handle. Set this to NULL for the current drawing.
        sheet - The sheet number. Set this to a value less than 1 for the current sheet.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProDrawingSheetFormatIsShown (ProDrawing drawing, int sheet, ProBoolean *is_shown);
/*
    Purpose:  Checks if the given drawing sheet's format is shown.

    Input Arguments:
        drawing - The drawing handle. Set this to NULL for the current drawing.
        sheet - The sheet number. Set this to a value less than 1 for the current sheet.

    Output Arguments:
        is_shown - PRO_B_TRUE if sheet format is shown, PRO_B_FALSE if sheet format is not shown

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDrawingFormatSizeGet (ProDrawing drawing, int drawing_sheet, ProPlotPaperSize *p_size, double *p_width, double *p_height);
/*
    Purpose: Gets the size of the format in a drawing.

    Input Arguments:
        drawing - The drawing.
        drawing_sheet - The sheet number of the drawing. Set this to a value less than 1 for the current sheet.

    Output Arguments:
        p_size - drawing size i.e. F_SIZE_PLOT, A4_SIZE_PLOT etc.
        p_width - drawing width in inch
        p_height - drawing height in inch

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProDrawingFormatSizeSet (ProDrawing drawing, int drawing_sheet, ProPlotPaperSize size, double width, double height);
/*
    Purpose: Adds or replaces a standard or custom size format in a drawing.

    Input Arguments:
        drawing - The drawing.
        drawing_sheet - The sheet number of the drawing. Set this to a value less than 1 for the current sheet.
        size - drawing size i.e. F_SIZE_PLOT, A4_SIZE_PLOT etc.
        width - drawing width in inch if size is VARIABLE_SIZE_PLOT,
                in mm if size is VARIABLE_SIZE_IN_MM_PLOT,
                ignored otherwise
        height - drawing height in inch if size is VARIABLE_SIZE_PLOT,
                 in mm if size is VARIABLE_SIZE_IN_MM_PLOT,
                 ignored otherwise

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProDrawingDimensionCreate(ProDrawing        drawing,
                                          ProDimAttachment *attachment_arr,
                                          ProDimSense      *dsense_arr,
                                          ProDimOrient      orinet_hint,
                                          ProVector         location,
                                          ProBoolean        ref_dim,
                                          ProDimension     *dimension);

/*
   Purpose: Creates dimension in drawing mode with the specified attachments
            and sense, at the specified location.This function also supports
            intersection of geometric entities and attachment.
			

   Input Arguments:
        drawing         - The Drawing
        attachment_arr  - ProArray of Attachments
        dsense_arr      - ProArray of sense
        orient_hint     - Orientation hint for dimension
        location        - Specifies the location for putting dimension text
        ref_dim         - Pass PRO_B_TRUE to create PRO_DIMENSION
                               PRO_B_FALSE to create PRO_REF_DIMENSION.
   
   Output Arguments:
        dimension       - The newly created dimension.

   Return Values:
        PRO_TK_BAD_INPUTS     - One or more arguments are invalid,
        PRO_TK_BAD_DIM_ATTACH - A dimension could not be created with specified
                                attachments and sense
        PRO_TK_NO_ERROR       - Successfully created a dimension with specified
                                attachments and sense.
*/


PRO_END_C_DECLS

#endif
