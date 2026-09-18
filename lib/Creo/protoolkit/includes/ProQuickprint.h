

#ifndef PROQUICKPRINT_H_
#define PROQUICKPRINT_H_

PRO_BEGIN_C_DECLS


#include <ProToolkit.h>
#include <ProDrawing.h>
#include <ProPrint.h>
#include <ProObjects.h>

typedef struct dtlqp_print_drawing_info*  ProQuickprintOptions;

typedef enum
{
   PRO_QPRINT_LAYOUT_PROJ,
   PRO_QPRINT_LAYOUT_MANUAL,
   PRO_QPRINT_LAYOUT_TEMPLATE
} ProQuickprintLayoutType;

typedef enum
{
   PRO_QPRINTMANUAL_3VIEW_1_23VERT,
   PRO_QPRINTMANUAL_3VIEW_23_VERT1,
   PRO_QPRINTMANUAL_3VIEW_123_HORIZ
}  ProQuickprintmanual3ViewLayoutType;

typedef enum
{
   PRO_QPRINTPROJ_TOP_VIEW,
   PRO_QPRINTPROJ_RIGHT_VIEW,
   PRO_QPRINTPROJ_LEFT_VIEW,
   PRO_QPRINTPROJ_BOTTOM_VIEW,
   PRO_QPRINTPROJ_BACK_NORTH,
   PRO_QPRINTPROJ_BACK_EAST,
   PRO_QPRINTPROJ_BACK_SOUTH,
   PRO_QPRINTPROJ_BACK_WEST
} ProQuickprintprojectedProjViewLocation;

typedef enum
{
   PRO_QPRINTPROJ_GENVIEW_MAIN,
   PRO_QPRINTPROJ_GENVIEW_NW,
   PRO_QPRINTPROJ_GENVIEW_SW,
   PRO_QPRINTPROJ_GENVIEW_SE,
   PRO_QPRINTPROJ_GENVIEW_NE
} ProQuickprintprojectedGeneralViewLocation;



extern ProError ProQuickprintoptionsAlloc (ProQuickprintOptions* options);
/*
    Purpose: Allocates a quick print options handle.
 
    Input Arguments:
      None

    Output Arguments:
        options - The quick print options handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProQuickprintoptionsFree (ProQuickprintOptions options);
/*
    Purpose: Frees a quick print options handle.
 
    Input Arguments:
        options - The quick print options handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProQuickprintoptionsLayouttypeSet (ProQuickprintOptions options,
                                           ProQuickprintLayoutType layout_type);

/*
    Purpose: Assigns the layout type to use for the quick print.
 
    Input Arguments:
        options - The options handle.
        layout_type - The layout type to use for the quick print.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProQuickprintoptionsOrientationSet (
                                                   ProQuickprintOptions options, 
                                                    int orientation);
/*
    Purpose: Assigns the sheet orientation for the quick print operation.
 
    Input Arguments:
        options - The quick print options.
        orientation - The orientation.  Valid values are 
                      PRODEV_ORIENTATION_PORTRAIT or 
                      PRODEV_ORIENTATION_LANDSCAPE.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The layout type is not 'projection' or 'manual'.

*/

extern ProError ProQuickprintoptionsSizeSet (ProQuickprintOptions options, 
                                             ProPrintSize* size);
/*
    Purpose: Assigns the size of the print for the quick print operation.
 
    Input Arguments:
        options - The quick print options.
        size - The size of the print for the quick print operation.  

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The layout type is not 'projection' or 'manual'.
        PRO_TK_INVALID_TYPE - Variable size quick prints are not currently 
                              supported.

*/

extern ProError ProQuickprintoptionsViewAdd (ProQuickprintOptions options, 
                            ProQuickprintprojectedGeneralViewLocation location, 
                            ProLine view_name, double scale, 
                            ProDrawingViewDisplay *display_style);
/*
    Purpose: Adds a new general view to be printed. 
             <P>
             <B>Note:</B>
             For manual view layouts, the order in which the views are added 
             determine their final location in the drawing.
             
    Input Arguments:
        options - The options handle.
        location - For projected view layout, this is the location of the view 
                   being added.  Ignored for manual view layout.
        view_name - Name of the saved model view.
        scale - The view scale to use.
        display_style - The view display style to use.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - No more than 4 views may be used in a manual 
                               layout.
        PRO_TK_BAD_CONTEXT - The layout type is not 'projection' or 'manual'.

*/

extern ProError ProQuickprintoptionsThreeviewlayoutSet (
                                ProQuickprintOptions options, 
                                ProQuickprintmanual3ViewLayoutType layout_type);
/*
    Purpose: Assigns the layout type to use, when three views are being used in 
             a manual layout (the layout type is PRO_QPRINT_LAYOUT_MANUAL).
 
    Input Arguments:
        options - The options handle.
        layout_type - The layout type to use.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The layout type is not 'manual', or there are not 
                             exactly three views stored in the layout.

*/

extern ProError ProQuickprintoptionsProjectionsSet (
                           ProQuickprintOptions options, 
                           ProQuickprintprojectedProjViewLocation* projections);
/*
    Purpose: Assigns the list of the projection to include in this quick print 
             operation, if the layout type is PRO_QPRINT_LAYOUT_PROJ.
 
    Input Arguments:
        options - The options handle.
        projections - ProArray of the projections to include.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The layout type is not 'projection'.

*/

extern ProError ProQuickprintoptionsTemplateSet (ProQuickprintOptions options, 
                                                 ProPath dwg_template);
/*
    Purpose: Assigns the path to the drawing template file, if the layout type 
             is PRO_QPRINT_LAYOUT_TEMPLATE.
 
    Input Arguments:
        options      - The options handle.
        dwg_template - Path to the drawing template file to use for the quick
	               print operation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The layout type is not 'template'.

*/

extern ProError ProQuickprintExecute (ProSolid solid, ProPath pcf_path, 
                                      ProQuickprintOptions options);
/*
    Purpose: Executes  a quick print of a given solid model.
 
    Input Arguments:
        solid - The solid model to print.  The model's simplified rep and layer 
                status will be maintained.
        pcf_path - Path to the plotter configuration file to use.  If NULL, the 
                   value of the config option 'quick_print_plotter_config_file'.
        options - Details on how the quick print should be carried out.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - pcf_path is null, and no default plotter config 
                             file is set.
        PRO_TK_GENERAL_ERROR - Could not complete the printing operation.
        PRO_TK_NO_PERMISSION - The function does not have permission to operate
			        on this model.
        PRO_TK_BAD_CONTEXT   - The function is not available in 
        		       Design Test Mode. 
                                
*/

extern ProError ProQuickprintoptionsPrintFlatToScreenAnnotsSet (ProQuickprintOptions options, ProBoolean print_flat_to_screen);
/*
    Purpose: Set the option to print flat_to_screen annotations.

    Input Arguments:
        options - The options handle.
        print_flat_to_screen - The print flat_to_screen annotations flag

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProAnnotationplaneFlatToScreenCreate()
*/

PRO_END_C_DECLS

#endif
