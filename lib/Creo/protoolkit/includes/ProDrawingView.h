/* PRODRAWINGVIEW.H */



#ifndef PRODRAWINGVIEWDOTH
#define PRODRAWINGVIEWDOTH

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
#include <ProDrawing.h>
#include <ProXsec.h>


/*ENUMS*/


typedef enum 
{
PRO_VIEW_GENERAL = 0,
PRO_VIEW_PROJECTION = 1,
PRO_VIEW_AUXILIARY = 2,
PRO_VIEW_DETAIL = 3,
PRO_VIEW_REVOLVE = 4,
PRO_VIEW_COPY_AND_ALIGN = 6,
PRO_VIEW_OF_FLAT_TYPE = 8
} ProViewType;

typedef enum 
{
PRO_VIEW_ORIENT_NAME = 1,
PRO_VIEW_ORIENT_GEOM_REF = 2,
PRO_VIEW_ORIENT_ANGLE = 3
} ProDrawingViewOrientationType;

typedef enum 
{
PRO_DETAIL_BOUNDARY_CIRCLE = 1,
PRO_DETAIL_BOUNDARY_ELLIPSE = 2,
PRO_DETAIL_BOUNDARY_HORZ_VER_ELLIPSE = 3,
PRO_DETAIL_BOUNDARY_SPLINE = 4,
PRO_DETAIL_BOUNDARY_ASME_CIRCLE = 5
} ProViewDetailBoundaryType;



typedef enum 
{
  PRO_VIEW_FULL_AREA = 0,
  PRO_VIEW_HALF_AREA = 1,
  PRO_VIEW_BROKEN_AREA = 2,
  PRO_VIEW_PARTIAL_AREA = 3
} ProDrawingViewVisibleareaType;

typedef enum 
{
PRO_VIEW_BROKEN_LINE_STRAIGHT = 0,
PRO_VIEW_BROKEN_LINE_SKETCH = 1,
PRO_VIEW_BROKEN_LINE_S_CURVE_OUTLINE = 2,
PRO_VIEW_BROKEN_LINE_S_CURVE_GEOMETRY = 3,
PRO_VIEW_BROKEN_LINE_HEART_BEAT_OUTLINE = 4,
PRO_VIEW_BROKEN_LINE_HEART_BEAT_GEOMETRY = 5
} ProViewBrokenLineStyle;

typedef enum 
{
PRO_VIEW_BROKEN_DIR_HORIZONTAL = 1,
PRO_VIEW_BROKEN_DIR_VERTICAL = 2
}ProViewBrokenDir;


typedef enum 
{
PRO_VIEW_ALIGN_HORIZONTAL = 1,
PRO_VIEW_ALIGN_VERTICAL = 2
}ProDrawingViewAlignStyle;


typedef enum 
{
PRO_VIEW_SECTION_AREA_FULL = 1,
PRO_VIEW_SECTION_AREA_HALF = 2,
PRO_VIEW_SECTION_AREA_LOCAL = 3,
PRO_VIEW_SECTION_AREA_UNFOLD = 4,
PRO_VIEW_SECTION_AREA_ALIGNED = 5
}ProDrawingViewSectionAreaType;

typedef enum
{
PRO_VIEW_MODEL_COLOR = 1,
PRO_VIEW_DRAWING_COLOR = 2
}ProDrawingViewColorSource;


typedef enum
{
PRO_VIEW_NO_SECTION = -1,
PRO_VIEW_TOTAL_SECTION = 0,
PRO_VIEW_AREA_SECTION = 1,
PRO_VIEW_PART_SURF_SECTION = 2,
PRO_VIEW_3D_SECTION = 3
}ProDrawingViewSectionType;

typedef enum
{
PRO_HVL_NONE = 1,
PRO_HVL_SOLID = 2,
PRO_HVL_SYMMETRY = 3,
PRO_HVL_SYMMETRY_ISO = 4,
PRO_HVL_SYMMETRY_ASME = 5
}ProDrawingLineStandardType;

/*APIs*/

extern ProError ProDrawingViewNameSet (ProDrawing drawing, ProView view, ProName name);
/*
    Purpose: Set the drawing view name

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        name - Name of the view to be set

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view name could not set

*/

extern ProError ProDrawingViewOrientationFromNameSet (ProDrawing drawing, ProView view, ProName mdl_view_name, ProName orientation_name, double  x_angle, double  y_angle);
/*
    Purpose: Set the view orientation of a general view from the view name

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        mdl_view_name - Name of the model view
        orientation_name - Name of the orientation
        x_angle - X angle for the user defined orientation 
        y_angle - Y angle for the user defined orientation

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The orientation from names could not set

*/

extern ProError ProDrawingViewOrientationFromReferenceSet (ProDrawing drawing, ProView view, ProName ref_name_1, ProSelection ref_sel_1, ProName ref_name_2, ProSelection ref_sel_2);
/*
    Purpose: Set the view orientation of a general view from the reference selection

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        ref_name_1 - Name of the first model orientation
        ref_sel_1 - Selection of the first reference selection
        ref_name_2 - Name of the second model orientation
        ref_sel_2 - Selection of the second reference selection

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The orientation from reference could not set

*/


extern ProError ProDrawingViewOrientationFromAngleSet (ProDrawing drawing, ProView view, ProName rot_ref_name, ProSelection sel, double  angle);
/*
    Purpose: Set the view orientation of a general view from the angle 

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        rot_ref_name - Rotational angle reference name
		               It can be "Normal" or "Horizontal" or "Vertical" or "Edge/Axis" 
        sel - Selection of the axis or edge, can be NULL for other type
        angle - angle with the reference 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The orientation from angle could not set

*/

extern ProError ProDrawingViewProjectionSet (ProDrawing drawing,
	 ProView parent_view, ProView view);
/*
    Purpose: Set view as projection

    Input Arguments:
        drawing - Drawing handle
        parent_view - The view handle of the parent view
        view - view to be projected

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view projection could not set

*/

extern ProError ProDrawingViewFlagSet (ProDrawing drawing, ProView view, ProBoolean flag);
/*
    Purpose: Set projection arrow flag for the projection and detail views.

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        flag - TRUE, if flag is set

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view flag could not set

*/

extern ProError ProDrawingViewDetailReferenceSet (ProDrawing drawing, ProView view, ProSelection ref_sel);
/*
    Purpose: Set reference point of detail view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        ref_sel - Reference selection of the detailed view

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The reference could not set

*/

extern ProError ProDrawingViewDetailCurvedataSet (ProDrawing drawing, ProView view, ProCurvedata* curve_data);
/*
    Purpose: Set spline for detail view parent

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        curve_data - Spline data (see Notes: below)

    Output Arguments:
        none

    Notes:
        The curve_data spline is in the space defined by 0,0 mapping to the
        detail view's reference point, the X and Y directions mapping to
        X and Y on the screen, and the unit length being one inch in the
        top model of the view.  To map this to world space, first scale
        the spline by inch-to-top-model-unit, then by model-to-world
        (that is, the scale of the view's transformation matrix), then
        translate it by the reference point.  To map a spline in world
        space for use here, translate it by the reference point, then
        scale by world-to-model (inverse of the scale of the view's
        transformation matrix), and scale by top-model-unit-to-inch.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The spline data could not set

*/

extern ProError ProDrawingViewAuxiliaryCreate (ProDrawing drawing, ProSelection selection, ProPoint3d point, ProView* view);
/*
    Purpose: Create a auxiliary view

    Input Arguments:
        drawing - Drawing handle
        selection - selection reference
        point - point location of the new view 

    Output Arguments:
        view - The auxiliary view created 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The auxiliary view could not be created

*/

extern ProError ProDrawingViewAuxiliarySet (ProDrawing drawing, ProView view, ProSelection  selection);
/*
    Purpose: Set view as auxiliary

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        selection - selection

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The auxiliary view could not set

*/

extern ProError ProDrawingViewFullVisibleAreaSet (ProDrawing drawing, ProView view);
/*
    Purpose: Set the full visible area for a view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The visible area could not set

*/

extern ProError ProDrawingViewBrokenVisibleAreaSet (ProDrawing drawing, 
	ProView parent_view, ProViewBrokenDir dir, ProSelection first_sel,
	ProSelection second_sel, ProViewBrokenLineStyle line_style, 
	ProCurvedata* curve_data);

/*
    Purpose: Set the partial visible area for a drawing view
             

    Input Arguments:
        drawing - Drawing handle
        parent_view - Parent view
        dir - direction of the broken line
        first_sel - First selection point 
        second_sel - Second selection point
        line_style - Broken line style
	curve_data - spline curve data, valid for the 
		line style PRO_VIEW_BROKEN_LINE_S_CURVE_GEOMETRY
		
    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The visible area of the broken view could not 
                               set

*/

extern ProError ProDrawingView3DSectionSet (ProDrawing drawing, ProView view, ProName sec_name, ProBoolean show_x_hatch);
/*
    Purpose: Set the 3D section for a view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        sec_name - Name of the 3D section
        show_x_hatch - PRO_B_TRUE, is X-hatching is to be shown

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewSinglepartSectionSet (ProDrawing drawing, ProView view, ProSelection ref_sel);
/*
    Purpose: Set the single part section for a view.

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        ref_sel - Selection reference of part surface

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewSimplifiedSet (ProDrawing drawing, ProView view, ProSimprep* simplified_ref);
/*
    Purpose: Set view simplified rep

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        simplified_ref - Simplified representation 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewExplodedSet (ProDrawing drawing, ProView view, ProBoolean exploded_state);
/*
    Purpose: Set the exploded state of the view 

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        exploded_state - The exploded state  

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The exploded state could not set

*/

extern ProError ProDrawingViewOriginSet (ProDrawing drawing, ProView view, ProPoint3d location, ProSelection sel_ref);
/*
    Purpose: Set the view origin

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        location - The location of the view origin
        sel_ref - selection reference

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view origin could not be set

*/

extern ProError ProDrawingViewAlignmentSet (ProDrawing drawing, ProView view_reference, ProView view, ProDrawingViewAlignStyle align_style, ProSelection align_ref_1, ProSelection align_ref_2);
/*
    Purpose: Set view alignment to view

    Input Arguments:
        drawing - Drawing handle
        view_reference - The reference view
        view - The view to be aligned
        align_style - Horizontal or vetrical style
        align_ref_1 - Alignment reference of the reference view, NULL if view 
                      origin
        align_ref_2 - Alignment reference of the aligned view, NULL if view 
                      origin

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view alignment could not set

*/

extern ProError ProDrawingViewErase (ProDrawing drawing, ProView view);
/*
    Purpose: Erase the view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view could not be erased

*/

extern ProError ProDrawingViewResume (ProDrawing drawing, ProView view);
/*
    Purpose: Resume the view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view could not be resumed

*/



extern ProError ProDrawingViewTypeGet (ProDrawing drawing, ProView view, ProViewType* type);
/*
    Purpose: Get view type

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        type - view type (General, projection, detailed, auxiliary, revolved, 
               copy and align, of flat ply)

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The drawing view type could not get

*/

extern ProError ProDrawingViewFlagGet (ProDrawing drawing, ProView view, ProBoolean* flag);
/*
    Purpose: Get projection arrow flag for the projection and detail views.

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        flag - TRUE, if flag is set

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view flag could not get

*/

extern ProError ProDrawingViewAuxiliaryInfoGet (ProDrawing drawing, ProView view, 
			ProSelection* selection, ProPoint3d view_location);
/*
    Purpose: Get the auxiliary view information

    Input Arguments:
        drawing - Drawing handle
	view - the view
	
    Output Arguments:
        selection - selection reference
        view_location - point location of the new view 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - Could not get auxiliary view information.

*/

extern ProError ProDrawingViewParentGet (ProDrawing drawing, ProView view, ProView* parent_view);
/*
    Purpose: Get the parent view of a view
             

    Input Arguments:
        drawing - Drawing handle
        view - The view handle


    Output Arguments:
        parent_view - Parent view

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed
        PRO_TK_E_NOT_FOUND - Parent view was not found

*/

extern ProError ProDrawingViewChildrenGet (ProDrawing drawing, ProView view, ProView** view_children, int* no_children);
/*
    Purpose: Get the children of a view
             

    Input Arguments:
        drawing - Drawing handle
        view - The view handle


    Output Arguments:
        view_children - Children of views
        no_children - number of children

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed
        PRO_TK_E_NOT_FOUND - No children found

*/

extern ProError ProDrawingViewSimplifiedGet (ProDrawing drawing, ProView view, ProSimprep* simplified_ref);
/*
    Purpose: Get the simplified rep
             

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        simplified_ref - Simplified representation 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed
		PRO_TK_INVALID_TYPE - The top model for the view is not a solid.

*/

extern ProError ProDrawingViewDetailReferenceGet (ProDrawing drawing, ProView view, ProSelection* ref_sel);
/*
    Purpose: Get reference point of detail view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        ref_sel - Reference selection of the detailed view

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The reference could not set
        PRO_TK_E_NOT_FOUND   - Could not found reference selection.

*/

extern ProError ProDrawingViewDetailCurvedataGet (ProDrawing drawing, ProView view, ProCurvedata* curve_data);
/*
    Purpose: Get spline for detail view parent

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        curve_data - Spline data (see Notes: below)

    Notes:
        The curve_data spline is in the space defined by 0,0 mapping to the
        detail view's reference point, the X and Y directions mapping to 
        X and Y on the screen, and the unit length being one inch in the 
        top model of the view.  To map this to world space, first scale
        the spline by inch-to-top-model-unit, then by model-to-world  
        (that is, the scale of the view's transformation matrix), then 
        translate it by the reference point.  To map a spline in world  
        space for use here, translate it by the reference point, then
        scale by world-to-model (inverse of the scale of the view's  
        transformation matrix), and scale by top-model-unit-to-inch.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The spline data could not get

*/

extern ProError ProDrawingViewDetailBoundaryGet (ProDrawing drawing, ProView view, ProViewDetailBoundaryType* type, ProBoolean* show);
/*
    Purpose: Get boundary for detail view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        type - supported boundary type
        show - geometry data

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The boundary could not set for the detail view

*/

extern ProError ProDrawingViewVisibleareaTypeGet (ProDrawing drawing, ProView view, ProDrawingViewVisibleareaType* visible_area);
/*
    Purpose: Get the visible area type 
             

    Input Arguments:
        drawing - drawing handle
        view - view handle
        visible_area - Visible area type

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewPartialVisibleAreaGet (ProDrawing drawing, ProView parent_view, ProSelection* ref_point, ProCurvedata* curve_data, ProBoolean* show_boundary);
/*
    Purpose: Get the partial visible area for a drawing view
             

    Input Arguments:
        drawing - Drawing handle
        parent_view - Parent view

    Output Arguments:
        ref_point - reference selection point on the view
        curve_data - spline curve data
        show_boundary - PRO_B_TRUE, to show the boundary

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewBrokenNumberGet (ProDrawing drawing, ProView broken_view, int* number);
/*
    Purpose: Get the number of settings for a broken view 
             
             

    Input Arguments:
        drawing - Drawing handle
        broken_view - Broken view handle

    Output Arguments:
        number - Number of setting for the broken view

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewBrokenVisibleAreaGet (ProDrawing drawing, 
	ProView parent_view, int index, ProViewBrokenDir* dir, 
	ProSelection* first_sel, ProSelection* second_sel, 
	ProViewBrokenLineStyle* line_style, ProCurvedata* curve_data);

/*
    Purpose: Get the partial visible area setting for the broken view 
             
             

    Input Arguments:
        drawing - Drawing handle
        parent_view - Parent view
        index - Index of the broken view. Here index starts with 1.

    Output Arguments:
        dir - direction of the broken line
        first_sel - First selection point 
        second_sel - Second selection point
        line_style - Broken line style
	curve_data - spline curve data, valid for the 
		line style PRO_VIEW_BROKEN_LINE_S_CURVE_GEOMETRY
		
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The visible area of the broken view could not 
                               set

*/

extern ProError ProDrawingViewSectionTypeGet (ProDrawing drawing, ProView view, ProDrawingViewSectionType* section_type);
/*
    Purpose: Get section type for a view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle


    Output Arguments:
        section_type - section type

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/


extern ProError ProDrawingView2DSectionNumberGet (ProDrawing drawing, ProView view, int* number);
/*
    Purpose: Get the number of setting for the 2D section view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        number - Number of setting for the 2D section

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/


extern ProError ProDrawingView2DSectionGet (ProDrawing drawing, ProView view, int index, ProName sec_name, ProDrawingViewSectionAreaType *sec_area_type, ProSelection *ref_sel, ProCurvedata *curve_data, ProView *arrow_display_view);
/*
    Purpose: Get the 2D section for a view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        index - Index of the setting


    Output Arguments:
        sec_name - Name of the section
        sec_area_type - Type of section area
        ref_sel - Reference selection
        curve_data - The spline curve data
        arrow_display_view - The view, where section arrow to be displayed

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/


extern ProError ProDrawingView3DSectionGet (ProDrawing drawing, ProView view, ProName sec_name, ProBoolean* show_x_hatch);
/*
    Purpose: Get the 3D section for a view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        sec_name - Name of the 3D section
        show_x_hatch - PRO_B_TRUE, is X-hatching is to be shown

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewSinglepartSectionGet (ProDrawing drawing, ProView view, ProSelection* ref_sel);
/*
    Purpose: Get the single part section for a view.

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        ref_sel - Selection reference of part surface

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewExplodedGet (ProDrawing drawing, ProView view, ProBoolean* exploded_state);
/*
    Purpose: Get the exploded state of the view 

    Input Arguments:
        drawing - Drawing handle
        view - The view handle


    Output Arguments:
        exploded_state - The exploded state  

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The exploded state could not get

*/

extern ProError ProDrawingViewOriginGet (ProDrawing drawing, ProView view, ProPoint3d location, ProSelection* sel_ref);
/*
    Purpose: Get the view origin

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        location - The location of the view origin
        sel_ref - selection reference

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view origin could not be get

*/

extern ProError ProDrawingViewAlignmentGet (ProDrawing drawing, ProView view, ProDrawingViewAlignStyle* align_style, ProView* view_reference, ProSelection* align_ref_1, ProSelection* align_ref_2);
/*
    Purpose: Get view alignment to view

    Input Arguments:
        drawing - Drawing handle
        view - The aligned view

    Output Arguments:
        align_style - Horizontal or vetrical style
        view_reference - The reference view
        align_ref_1 - Alignment reference of the reference view, NULL if view 
                      origin
        align_ref_2 - Alignment reference of the aligned view, NULL if view 
                      origin

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The view alignment could not get

*/


extern ProError ProDrawingViewColorSourceGet (ProDrawing drawing, ProView view, ProDrawingViewColorSource* color_source);
/*
    Purpose: Get the color source of the view representation
             

    Input Arguments:
        drawing - drawing handle
        view - view handle


    Output Arguments:
        color_source - The color source of the drawing

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewPerspectiveScaleGet (ProDrawing drawing, ProView view, double* eye_dist, double* view_dia);
/*
    Purpose: Get the perspective scale 
             

    Input Arguments:
        drawing - drawing handle
        view - view handle


    Output Arguments:
        eye_dist - Eye point distance
        view_dia - View Diameter

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed
        PRO_TK_E_NOT_FOUND - The current scale is not in the perspective scale

*/

extern ProError ProDrawingViewIsErased (ProDrawing drawing, ProView view, ProBoolean* is_erased);
/*
    Purpose: Find the view is erased or not

    Input Arguments:
        drawing - Drawing handle
        view - The view handle


    Output Arguments:
        is_erased - Pro_B_TRUE, is view erased

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/
extern ProError ProDrawingViewRevolveInfoGet (ProDrawing drawing, ProView view, ProXsec *x_sec, ProSelection* selection, ProPoint3d view_location);
/*
    Purpose: Get the revolved view information

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        x_sec - Cross section 
        selection - selection
        view_location - point location of new revolved view

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The revolve view could not be created

*/
extern ProError ProDrawingViewRevolveCreate (ProDrawing drawing,ProXsec* x_sec, ProSelection selection, ProPoint3d view_location, ProView* view);				       
/*
    Purpose: Create revolved view

    Input Arguments:
        drawing - Drawing handle
        x_sec - Cross section 
        selection - selection
        view_location - point location of new revolved view

    Output Arguments:
        view - New revolved view

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The revolve view could not be created

*/				       

extern ProError ProDrawingViewDetailCreate( ProDrawing drawing, ProView parent_view, ProSelection ref_point, ProCurvedata* curve_data, ProPoint3d location, ProView* view);
/*
    Purpose: Create a detailed view

    Input Arguments:
        drawing - Drawing handle
        parent_view - Parent view
        ref_point - reference point on the parent view
        curve_data - spline curve data (see Notes: below)
        location - location of the new view

    Output Arguments:
        view - New detailed view

    Notes:
        The curve_data spline is in world space, and must enclose the
        reference point (in world space, on the parent view).

        In particular, if you have a spline from another detail view
        retrieved by ProDrawingViewDetailCurvedataGet, and wish to make
        this detail view with 'the same spline shape', driven by a
        different reference point in the same parent view, you would
        scale that spline by inches-to-top-model-units, and scale it by
        model-to-world, and translate it by the new reference point
        (in world space, on the parent view).

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The detail view could not be created

*/
extern ProError ProDrawingViewHalfVisibleAreaSet(
                                      ProDrawing drawing, ProView view, 
                                      ProSelection plane_ref,
				      ProBoolean keep_side,
                                      ProDrawingLineStandardType line_standard);
/*
    Purpose: Set view half visible area for a drawing view
             

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        plane_ref - Selection reference for the half visible area
        keep_side -  The side of view to display. 
	             PRO_B_TRUE: Left half of the view will be displayed
		     PRO_B_FALSE: Right half of the view will be displayed.
        line_standard - Type of line

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The visible area could not set

*/

extern ProError ProDrawingView2DSectionSet (ProDrawing drawing, ProView view, ProName sec_name, 
		ProDrawingViewSectionAreaType sec_area_type, ProSelection ref_sel, 
		ProCurvedata *curve_data, ProView arrow_display_view);
/*
    Purpose: Set the 2D section for a view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        sec_name - Name of the section
        sec_area_type - Type of section area
        ref_sel - Reference selection. NULL can be passed only if sec_area_type is
                  PRO_VIEW_SECTION_AREA_FULL or PRO_VIEW_SECTION_AREA_UNFOLD.
        curve_data - The spline curve data. NULL can be passed in all types of sec_area_type
                     other than PRO_VIEW_SECTION_AREA_LOCAL.
        arrow_display_view - The view, where section arrow to be displayed.This can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewHalfVisibleAreaGet (ProDrawing drawing, ProView view,
                                           ProSelection* plane_ref,
					   ProBoolean* keep_side,
					   ProDrawingLineStandardType* line_standard);
/*
    Purpose: Get view half visible area for a drawing view
             

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        plane_ref - Selection reference for the half visible area
        keep_side -  The side of the view displayed
	             PRO_B_TRUE: Left half of the view is displayed.
		     PRO_B_FALSE: Right half of the view is displayed.
        line_standard - Type of line


    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The visible area could not set

*/

extern ProError ProDrawingViewPartialVisibleAreaSet (ProDrawing drawing,
                                              ProView view,
					      ProSelection ref_point,
					      ProCurvedata* curve_data,
					      ProBoolean show_boundary);
/*
    Purpose: Set the partial visible area for a drawing view
             

    Input Arguments:
        drawing - Drawing handle
        view - Parent view
        ref_point - Reference selection point on the view
        curve_data - Spline curve data
        show_boundary - PRO_B_TRUE, to show the boundary

    Output Arguments:
         none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingViewDetailBoundarySet (ProDrawing drawing, ProView view,
                                           ProViewDetailBoundaryType type,
					   ProBoolean show);
/*
    Purpose: Set boundary for detail view

    Input Arguments:
        drawing - Drawing handle
        view - The view handle
        type - Supported boundary type
        show - Geometry data

    Output Arguments:
    	none
	
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The boundary could not set for the detail view

*/

extern ProError ProDrawingView2DSectionTotalSet (ProDrawing drawing, ProView view);
/*
    Purpose: Set the model edge visibility to Total for a 2D section in a view.

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        None.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_CHANGE -  Visibility is already set to Total.
        PRO_TK_CANT_MODIFY - Total Visibility cannot be set because there may be multiple section or section is not a full section.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProDrawingView2DSectionAreaSet  (ProDrawing drawing, ProView view);
/*
    Purpose: Set the model edge visibility to Area for a 2D section in a view.

    Input Arguments:
        drawing - Drawing handle
        view - The view handle

    Output Arguments:
        None.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_CHANGE -  Visibility is already set to Area.
        PRO_TK_CANT_MODIFY - Total Visibility cannot be set because there may be multiple section or section is not a full section.
        PRO_TK_GENERAL_ERROR - The function failed

*/


PRO_END_C_DECLS

#endif
