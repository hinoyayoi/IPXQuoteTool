#ifndef PROMECHGEOMETRY_H
#define PROMECHGEOMETRY_H



PRO_BEGIN_C_DECLS

#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProGeomitem.h>
#include <ProSurface.h>
#include <ProSurfacedata.h>
#include <ProEdge.h>
#include <ProEdgedata.h>
#include <ProContour.h>
#include <ProContourdata.h>
#include <ProCurve.h>
#include <ProCurvedata.h>
#include <ProSurface.h>
#include <ProMechGeomref.h>

typedef struct pro_sim_model* ProMechModel;
typedef struct pro_sim_solid* ProMechSolid;
typedef struct pro_sim_face* ProMechSurface;
typedef struct pro_sim_contour* ProMechContour;
typedef struct pro_sim_edge* ProMechEdge;
typedef struct pro_sim_vertex* ProMechVertex;
typedef struct pro_sim_point* ProMechPoint;
typedef struct pro_sim_compcurve* ProMechCompositeCurve;
typedef struct pro_sim_curve* ProMechCurve;

typedef struct pro_sim_model_data* ProMechModelData;

typedef double ProUvTransform[2][3];

typedef enum
{
  /* Solid surfaces + shells on quilt surfaces. */
  PRO_MECH_MODEL_SOLID    = 0,

  /* Shell-compressed surfaces + shells on quilt surfaces.
     Requires the Creo Simulate license to be available.  */
  PRO_MECH_MODEL_SHELL    = 1,

  /* Solid and Shell-compressed surfaces + shells on quilt surfaces.
     Requires the Creo Simulate license to be available.  */
  PRO_MECH_MODEL_MIXED    = 2,

  /* Shell surfaces on solid boundary + shells on quilt surfaces. */
  PRO_MECH_MODEL_BOUNDARY = 3,

  /* Shells on quilt surfaces. */
  PRO_MECH_MODEL_QUILT    = 4,

  /* Bars on given datum curves. */
  PRO_MECH_MODEL_BAR      = 5
}
ProMechModelType;

typedef enum
{
  PRO_MECH_MODEL_SUCCESS          = 0,  /* Success */
  PRO_MECH_MODEL_GENERAL_FAILURE  = 1,  /* General failure */
  PRO_MECH_MODEL_USER_INTERRUPT   = 2,  /* User interrupt */
  PRO_MECH_MODEL_SHELL_NO_PAIRS   = 3,  /* No shell pairs were defined */
  PRO_MECH_MODEL_SHELL_SOME_PAIRS = 4,  /* Some paired and some unpaired srfs
                                           found for type PRO_MECH_MODEL_SHELL
                                           (where every portion of the model
                                           should compress to shell surfs) */
  PRO_MECH_MODEL_NO_MESHABLE_GEOM = 5   /* No meshable geometry
                                           or idealizations */
}
ProMechModelStatus;

typedef enum
{
  PRO_MECH_SOLID_PART     = 1,
  PRO_MECH_SOLID_ASSEMBLY = 2
}
ProMechSolidType;

typedef enum
{
  PRO_MECH_FACE_SOLID         = 0,  /* A solid surface */
  PRO_MECH_FACE_SHELL         = 1,  /* A shell mid-plane surface */
  PRO_MECH_FACE_SIDE          = 2,  /* A shell side surface (will have zero
                                       surface area) */
  PRO_MECH_FACE_SHELL_QLT     = 3,  /* A quilt surface */
  PRO_MECH_FACE_BOUNDARY      = 4,  /* A solid boundary surface for
                                       type PRO_MECH_MODEL_BOUNDARY */
  PRO_MECH_FACE_PERIM_WELD    = 5,  /* A generated surface for a perimeter
                                       weld idealization */
  PRO_MECH_FACE_PROWELD_WELD  = 6,  /* A generated surface for a Pro/WELD
                                       weld idealization */
  PRO_MECH_FACE_2P5D_INTERNAL = 7   /* An internal planar surface for
                                       2.5D meshing */
}
ProMechSurfaceType;

typedef enum
{
  PRO_MECH_PNT_FREE   = 0,    /* Point is not attached to a solid/shell */
  PRO_MECH_PNT_FACE   = 1,    /* Point lies on a ProMechSurface */
  PRO_MECH_PNT_EDGE   = 2,    /* Point lies on a ProMechEdge */
  PRO_MECH_PNT_VERTEX = 3     /* Point lies on a ProMechVertex */
}
ProMechpointPlacementType;

typedef enum
{
  PRO_MECH_SEGMENT_FREE    = 0,   /* Curve is not on any edge */
  PRO_MECH_SEGMENT_ON_EDGE = 1    /* Curve lies on an edge */
}
ProMechCurveType;

typedef ProError (*ProMechsolidFilterAction) (ProMechSolid solid, ProAppData app_data);
/*
    Purpose: Filter action for the solid volumes that make up a Creo Simulate
             model.

    Input Arguments:
        solid - The solid volumes in the geometry.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechsolidVisitAction) (ProMechSolid solid, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the solid volumes that make up a Creo Simulate
             model.

    Input Arguments:
        solid - The solid volumes in the geometry.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechpointFilterAction) (ProMechPoint point, ProAppData app_data);
/*
    Purpose: Filter action for the datum points that are included in a
             Creo Simulate geometry model.

    Input Arguments:
        point - The datum points.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechpointVisitAction) (ProMechPoint point, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the datum points that are included in a
             Creo Simulate geometry model.

    Input Arguments:
        point - The datum points.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechcompositecurveFilterAction) (ProMechCompositeCurve curve, ProAppData app_data);
/*
    Purpose: Filter action for the composite curves that are included in a
             Creo Simulate geometry model.

    Input Arguments:
        curve - The composite curve handle.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechcompositecurveVisitAction) (ProMechCompositeCurve curve, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the composite curves that are included in a
             Creo Simulate geometry model.

    Input Arguments:
        curve - The composite curve handle.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechsurfaceFilterAction) (ProMechSurface surface, ProAppData app_data);
/*
    Purpose: Filter action for the surfaces that are included in a given solid
             volume.

    Input Arguments:
        surface - The surfaces for a given solid volume.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechsurfaceVisitAction) (ProMechSurface surface, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the surfaces that are included in a given solid
             volume.

    Input Arguments:
        surface - The surfaces for a given solid volume.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechedgeFilterAction) (ProMechEdge edge, ProAppData app_data);
/*
    Purpose: Filter action for the edges that are included in a given solid
             volume, surface, or contour.

    Input Arguments:
        edge - The edge.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechedgeVisitAction) (ProMechEdge edge, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the edges that are included in a given solid
             volume, surface, or contour.

    Input Arguments:
        edge - The edge.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechcontourFilterAction) (ProMechContour contour, ProAppData app_data);
/*
    Purpose: Filter action for the contours that are included in a given
             surface.

    Input Arguments:
        contour - The contour.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechcontourVisitAction) (ProMechContour contour, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the contours that are included in a given
             surface.

    Input Arguments:
        contour - The contour.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechcurveFilterAction) (ProMechCurve curve, ProAppData app_data);
/*
    Purpose: Filter action for the curves that make up this composite curve.

    Input Arguments:
        curve - The curve.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechcurveVisitAction) (ProMechCurve curve, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the curves that make up this composite curve.

    Input Arguments:
        curve - The curve.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

typedef ProError (*ProMechvertexFilterAction) (ProMechVertex vertex, ProAppData app_data);
/*
    Purpose: Filter action for the vertices that are included in a given solid
             volume.

    Input Arguments:
        vertex - The vertex.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Don't pass the item to the visit action.
        PRO_TK_NO_ERROR - Pass the item to the visit action, and pass this
                          value as filter status.
*/

typedef ProError (*ProMechvertexVisitAction) (ProMechVertex vertex, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for the vertices that are included in a given solid
             volume.

    Input Arguments:
        vertex - The vertex.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and pass this value as a return from
                          the visit function.
*/

extern ProError ProMechmodelGet (ProSolid solid, ProMechModelData data,
                                 ProMechModel* mech_model, ProMechModelStatus* status);
/*
    Purpose: Obtains the root handle to a Creo Simulate geometry model.

             <b>NOTE: Call ProMdlDisplay() to display model in current active
               window before using this function.</b>
             <p> If the type of geometry generated is PRO_MECH_MODEL_SHELL
               or PRO_MECH_MODEL_MIXED, the function requires the Creo Simulate
               license (and will attempt to obtain it if its not in session).
             <p> If the input solid (or any of its components) contains
               Creo Simulate Volume Region or Surface Region features, the
               function requires the Creo Simulate license (and will attempt
               to obtain it if its not in session).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The root solid model (part or assembly).
        data - Options for the generation of geometry.

    Output Arguments:
        mech_model - Root handle to the generated geometry.
        status - The status of generation.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_NOT_DISPLAYED - Specified model was not displayed.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmodelFree (ProMechModel model);
/*
    Purpose: Frees a Creo Simulate model handle.  This invalidates all
             geometric entities obtained from this handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        model - The Creo Simulate model handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechmodeldataAlloc (ProMechModelData* data);
/*
    Purpose: Allocates a data handle used for genereation of a Creo Simulate
             geometry model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The data handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmodeldataFree (ProMechModelData data);
/*
    Purpose: Frees a data handle used for genereation of a Creo Simulate
             geometry model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechmodeldataTypeSet (ProMechModelData data, ProMechModelType type);
/*
    Purpose: Assigns the type of model to be generated.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data handle.
        type - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechmodeldataEntitiesSet (ProMechModelData data, ProMechGeomref* entities);
/*
    Purpose: Assigns the additional datum points, curves, quilts and individual
             quilt surfaces to include in the geometric processing.
             Typically Creo Simulate uses only the entities which have
             a simulation item assigned to them.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data handle.
        entities - ProArray of the geometric entities.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmodeldataPreserveidsSet (ProMechModelData data, ProBoolean preserve_ids);

/*
    Purpose: Set the flag that controls preservation of IDs.
             When "Preserve IDs" flag is set, Creo Simulate will try to preserve
             IDs of surfaces and edges in simulation geometry between
             different calls to ProMechmodelGet(), even if original geometry
             of the model has changed slightly. The success of this attempt
             to preserve geometry IDs is not guaranteed, though.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data handle.
        preserve_ids - PRO_B_TRUE if the IDs are to be preserved.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechmodeldataMergeCoincSolidEdgesSet (ProMechModelData data,
                                                         ProBoolean merge_coinc_solid_edges);

/*
    Purpose: Set the flag that controls whether coincident solid edges
             will be merged. By default they will not be merged.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data handle.
        merge_coinc_solid_edges - PRO_B_TRUE if solid edges to be merged.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechmodelMdlGet (ProMechModel model, ProSolid* mdl);
/*
    Purpose: Obtains gets the root solid model used for generation of this
             Creo Simulate model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        model - The Creo Simulate root model.

    Output Arguments:
        mdl - The root solid model used for generation of this Creo Simulate
              model.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechmodelSolidVisit (ProMechModel model, ProMechsolidVisitAction action, ProMechsolidFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the solid volumes that make up a Creo Simulate geometry
             model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        model - The Creo Simulate root model.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No solid models were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechmodelPointVisit (ProMechModel model, ProMechpointVisitAction action, ProMechpointFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the datum points that are included in a Creo Simulate
             geometry model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        model - The Creo Simulate root model.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No points were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechmodelCurveVisit (ProMechModel model, ProMechcompositecurveVisitAction action, ProMechcompositecurveFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the composite curves that are included in a  Creo Simulate
             geometry model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        model - The Creo Simulate root model.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No curves were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechmodelToleranceGet (ProMechModel model, double* tolerance);
/*
   Purpose: Obtains the overall tolerance/epsilon value used  for the
            preparation of the Creo Simulate geometry.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
       model - The Creo Simulate root model.

   Output Arguments:
       tolerance - The tolerance.

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsolidIdGet (ProMechSolid solid, int* id);
/*
    Purpose: Obtains the ID of the solid volume.  This is just an index in the
             array of generated solid volumes and is not persistent among
             different calls to ProMechmodelCreate().

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volume.

    Output Arguments:
        id - The ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsolidModelGet (ProMechSolid solid, ProMechModel* model);
/*
    Purpose: Obtains the root Creo Simulate geometry model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volume.

    Output Arguments:
        model - The root model.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsolidTypeGet (ProMechSolid solid, ProMechSolidType* type);
/*
    Purpose: Obtains the solid volume type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volume.

    Output Arguments:
        type - The type (part or assembly).

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsolidAsmcomppathGet (ProMechSolid solid, ProAsmcomppath* comp_path);
/*
    Purpose: Obtains the assembly component path from the top assembly to this
             model.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volume.

    Output Arguments:
        comp_path - The assembly component path.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsolidSurfaceVisit (ProMechSolid solid, ProMechsurfaceVisitAction action, ProMechsurfaceFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the surfaces that are included in a given solid volume.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volume.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No surfaces were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechsolidEdgeVisit (ProMechSolid solid, ProMechedgeVisitAction action, ProMechedgeFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the edges that are included in a given solid volume.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volumne.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No edges were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechsolidVertexVisit (ProMechSolid solid, ProMechvertexVisitAction action, ProMechvertexFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the vertices that are included in a given solid volume.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The solid volume.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No vertices were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechsurfaceIdGet (ProMechSurface surface, int* id);
/*
    Purpose: Obtains the ID of the surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.

    Output Arguments:
        id - The surface ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsurfaceOwnerGet (ProMechSurface surface, ProMechSolid* owner);
/*
    Purpose: Obtains the owner volume for the surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.

    Output Arguments:
        owner - The owner volume.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsurfaceTypeGet (ProMechSurface surface, ProMechSurfaceType* type);
/*
    Purpose: Obtains the type of surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.

    Output Arguments:
        type - The type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsurfaceContourVisit (ProMechSurface surface, ProMechcontourVisitAction action, ProMechcontourFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the contours that are included in a given surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No contours were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechsurfaceEdgeVisit (ProMechSurface surface, ProMechedgeVisitAction action, ProMechedgeFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the edges that are included in a given surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No edges were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechsurfaceVertexVisit (ProMechSurface surface, ProMechvertexVisitAction action, ProMechvertexFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the vertices that are included in a given surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No vertices were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechsurfaceIncontactfacesGet (ProMechSurface surface, ProMechSurface** in_contact_faces);
/*
    Purpose: Obtains the list of surfaces which have been combined by the
             geometry evaluation because they are in contact with one another.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.

    Output Arguments:
        in_contact_faces - ProArray of the surfaces which are in contact with
                           the given surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No other surfaces were found in contact with this
                             one.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceDataGet (ProMechSurface surface, ProGeomitemdata** data);
/*
   Purpose: Obtains the geometric representation of the surface.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
       surface - The surface.

   Output Arguments:
       data - The surface data. The function allocates the memory for this
              argument. Use the function <b>ProGeomitemdataFree()</b> to free
              the memory.

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
       PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontourIdGet (ProMechContour contour, int* id);
/*
    Purpose: Obtains the ID for a given contour (unique within the surface that
             owns the contour).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.

    Output Arguments:
        id - The ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcontourSurfaceGet (ProMechContour contour, ProMechSurface* surface);
/*
    Purpose: Obtains the surface that contains the contour.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.

    Output Arguments:
        surface - The surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcontourTraversalGet (ProMechContour contour, ProContourTraversal* traversal);
/*
    Purpose: Obtains the contour traversal.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.

    Output Arguments:
        traversal - The contour traversal.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No traversals were found for the given contour.
*/

extern ProError ProMechcontourContainingContourGet (ProMechContour contour, ProMechContour* containing);
/*
    Purpose: Obtains the contour's containing contour.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.

    Output Arguments:
        containing - The containing contour. NULL if there is no containing contour.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcontourEdgeVisit (ProMechContour contour, ProMechedgeVisitAction action, ProMechedgeFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the edges that make up a given contour.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No edges were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechedgeDirectionGet (ProMechEdge edge, ProMechContour contour, ProEdgeDirection* direction);
/*
    Purpose: Obtains the edge direction with respect to the given contour.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        contour - The contour.

    Output Arguments:
        direction - The edge direction in the given contour.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - The edge is not contained in the given contour.
*/

extern ProError ProMechedgeIdGet (ProMechEdge edge, int* id);
/*
    Purpose: Obtains the ID of the given edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.

    Output Arguments:
        id - The ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechedgeOwnerGet (ProMechEdge edge, ProMechSolid* owner);
/*
    Purpose: Obtains the owner volume of a given edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.

    Output Arguments:
        owner - The owner volume.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechedgeSurfaceVisit (ProMechEdge edge, ProMechsurfaceVisitAction action, ProMechsurfaceFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the surfaces that share this edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No surfaces were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechedgeContourVisit (ProMechEdge edge, ProMechcontourVisitAction action, ProMechcontourFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the contours that contain this edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No contours were found to visit because the edge
                             is not a part of any surface's contours.
        Other - Error return from the visit action.
*/

extern ProError ProMechedgeEndpointsGet (ProMechEdge edge, ProMechVertex* endpoint_1, ProMechVertex* endpoint_2);
/*
    Purpose: Obtains the endpoints of the given edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.

    Output Arguments:
        endpoint_1 - The start point for the edge (t = 0.0).
        endpoint_2 - The end point for the edge (t = 1.0).

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechedgeIncontactedgesGet (ProMechEdge edge, ProMechEdge** in_contact_edges);
/*
    Purpose: Obtains a list of the edges which have been combined by the
             geometry evaluation because they are in contact.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.

    Output Arguments:
        in_contact_edges - ProArray of the edges in contact with this one.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No other edges were found that were in contact
                             with this one.
*/

extern ProError ProMechedgeDataGet (ProMechEdge edge, ProGeomitemdata** data);
/*
   Purpose: Obtains the geometric representation of the edge.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
       edge - The edge.

   Output Arguments:
       data - The edge data. The function allocates the memory for this
              argument. Use the function <b>ProGeomitemdataFree()</b> to
              free the memory.

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechvertexIdGet (ProMechVertex vertex, int* id);
/*
    Purpose: Obtains the ID of a given vertex.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vertex - The vertex.

    Output Arguments:
        id - The ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechvertexOwnerGet (ProMechVertex vertex, ProMechSolid* owner);
/*
    Purpose: Obtains the volume that owns the vertex.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vertex - The vertex.

    Output Arguments:
        owner - The solid volume owner.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechvertexPointGet (ProMechVertex vertex, Pro3dPnt point);
/*
    Purpose: Obtains the coordinate point for a given vertex.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vertex - The vertex.

    Output Arguments:
        point - The point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechvertexSurfaceVisit (ProMechVertex vertex, ProMechsurfaceVisitAction action, ProMechsurfaceFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the surfaces that include this vertex.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vertex - The vertex.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No surfaces were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechvertexEdgeVisit (ProMechVertex vertex, ProMechedgeVisitAction action, ProMechedgeFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the edges that contain this vertex.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vertex - The vertex.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No edges were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechvertexIncontactverticesGet (ProMechVertex vertex, ProMechVertex** in_contact_vertices);
/*
    Purpose: Obtains the list of the vertices that the geometry evaluation has
             combined because they are in contact with this one.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vertex - The vertex.

    Output Arguments:
        in_contact_vertices - ProArray of vertices that are in contact with
                              this one.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No other vertices were found in contact with this
                             one.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechpointIdGet (ProMechPoint point, int* id);
/*
    Purpose: Obtains the ID of the point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        id - The ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechpointOwnerGet (ProMechPoint point, ProMechModel* owner);
/*
    Purpose: Obtains the owner model for a given point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        owner - The owner.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechpointPointGet (ProMechPoint point, Pro3dPnt out_point);
/*
    Purpose: Obtains the coordinates of the point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        out_point - The coordinates of the point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechpointPlacementtypeGet (ProMechPoint point, ProMechpointPlacementType* placement_type);
/*
    Purpose: Obtains the placement type for the point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        placement_type - The placement type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechpointPlacementsurfaceGet (ProMechPoint point, ProMechSurface* placement_surface, ProUvParam param);
/*
    Purpose: Obtains the placment surface, if the placement type is
             PRO_MECH_POINT_FACE.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        placement_surface - The placement surface.
        param - The UV coordinates of the placement on the surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of surface.
*/

extern ProError ProMechpointPlacementedgeGet (ProMechPoint point, ProMechEdge* placement_edge, double* parameter);
/*
    Purpose: Obtains the placement edge, if placement type is
             PRO_MECH_POINT_EDGE.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        placement_edge - The placement edge.
        parameter - The parameter along the edge that identifies the placement.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of edge.
*/

extern ProError ProMechpointPlacementvertexGet (ProMechPoint point, ProMechVertex* placement_vertex);
/*
    Purpose: Obtains the placement vertex, if the placement type is
             PRO_MECH_POINT_VERTEX.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point.

    Output Arguments:
        placement_vertex - The placement vertex.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of vertex.
*/

extern ProError ProMechpointAncestorsGet (ProMechPoint point, ProMechGeomref** ancestors);
/*
    Purpose: Obtains the ancestor point for the given point.   These are the
             actual Creo Parametric geometry point used to construct this Creo Simulate
             point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        point - The point handle.

    Output Arguments:
        ancestors - ProArray of the ancestor geometry for the point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcompositecurveIdGet (ProMechCompositeCurve composite_curve, int* id);
/*
    Purpose: Obtains the ID of the composite curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        composite_curve - The composite curve.

    Output Arguments:
        id - The ID.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcompositecurveOwnerGet (ProMechCompositeCurve composite_curve, ProMechModel* owner);
/*
    Purpose: Obtains the owner model for the composite curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        composite_curve - The composite curve.

    Output Arguments:
        owner - The owner model.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcompositecurveCurveVisit (ProMechCompositeCurve composite_curve, ProMechcurveVisitAction action, ProMechcurveFilterAction filter, ProAppData app_data);
/*
    Purpose: Visits the curves that make up this composite curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        composite_curve - The composite curve.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No curves were found to visit.
        Other - Error return from the visit action.
*/

extern ProError ProMechcompositecurveAncestorsGet (ProMechCompositeCurve curve, ProMechGeomref** ancestors);
/*
    Purpose: Obtains the ancestor curves for the given composite curve.   These
             are the actual Creo Parametric geometry curves used to construct this
             Creo Simulate curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve handle.

    Output Arguments:
        ancestors - ProArray of the ancestor geometry for the curve.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveTypeGet (ProMechCurve curve, ProMechCurveType* type);
/*
    Purpose: Obtains the curve's type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        type - The curve type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcurveParentGet (ProMechCurve curve, ProMechCompositeCurve* parent);
/*
    Purpose: Obtains the parent composite curve for this curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        parent - The composite curve parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcurveParamGet (ProMechCurve curve, double* param);
/*
    Purpose: Obtains the parameter along the parent composite curve at  which
             this curve begins.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        param - The parameter.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcurveEndpointsGet (ProMechCurve curve, ProMechPoint* endpoints1, ProMechPoint* endpoints2);
/*
    Purpose: Obtains the endpoints of the curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        endpoints1 - The first endpoint.  May be NULL, if the curve doesn't
                    end at a designated point.
        endpoints2 - The second endpoint.  May be NULL, if the curve doesn't
                    end at a designated point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcurveEdgeGet (ProMechCurve curve, ProMechEdge* edge, ProEdgeDirection* rel_direction);
/*
    Purpose: Obtains the edge, if the curve type is PRO_MECH_CURVE_EDGE.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        edge - The edge.
        rel_direction - Relative direction of the curve with respect to the
                        edge.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of edge.
*/

extern ProError ProMechcurveAncestorsGet (ProMechCurve curve, ProMechGeomref** ancestors);
/*
    Purpose: Obtains the ancestor curves for the given simple curve.   These
             are the actual Creo Parametric geometry curves used to construct this
             Creo Simulate curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve handle.

    Output Arguments:
        ancestors - ProArray of the ancestor geometry for the curve.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveDataGet (ProMechCurve curve, ProGeomitemdata** data);
/*
   Purpose: Obtains the geometric representation of the curve.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
       curve - The curve.

   Output Arguments:
       data - The curve data. The function allocates the memory for this
              argument. Use the function <b>ProGeomitemdataFree()</b> to
              free the memory.

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
       PRO_TK_NOT_IMPLEMENTED - The function does not support composite curves.
       PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceParamEval (ProMechSurface surface, Pro3dPnt xyz_point, ProUvParam uv_point);
/*
    Purpose: Finds the corresponding UV point on the Creo Simulate surface,
             given the XYZ point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        xyz_point - The XYZ point.  The point does not necessarily have to lie
                    on the surface.  If the point is off of the surface, the
                    function finds the closest point.

    Output Arguments:
        uv_point - The corresponding UV point on the surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfacePrincipalCrvtEval (ProMechSurface surface, ProUvParam uv_point, double* max_curvature, double* min_curvature,ProVector curv_dirs[2]);
/*
    Purpose: Finds principal curvatures and directions of the Creo Simulate
             surface at the given UV point.

    Input Arguments:
        surface - The surface.
        uv_point - The UV point.

    Output Arguments:
        max_curvature - Maximum curvature at the point.
        min_curvature - Minimum curvature at the point.
        curv_dirs - Principal directions at the point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceXyzdataEval (ProMechSurface surface, ProUvParam param, Pro3dPnt xyz_point, ProVector deriv1[2], ProVector deriv2[3], ProVector normal);
/*
    Purpose: Evaluates the Creo Simulate surface at the specified UV point.

    Input Arguments:
        surface - The surface.
        param - The UV params.

    Output Arguments:
        xyz_point - The resulting XYZ point.
        deriv1 - The first derivative in the UV point.
        deriv2 - The second derivative in the UV point.
        normal - The normal to the surface in the UV point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechsurfaceUvpntVerify (ProMechSurface surface, ProUvParam uv_point, ProUvStatus *status);
/*
    Purpose: Verifies whether the specified UV point lies within the boundaries
             of the Creo Simulate surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        uv_point - The UV point.
        status - The resulting status.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceTessellationGet (ProMechSurface surface,
                                               ProSurfaceTessellationInput input_data,
                                               ProTessellation* tessellation);
/*
    Purpose: Calculates the tessellation for the provided Creo Simulate
             surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        input_data - The input data for the tessellation.

    Output Arguments:
        tessellation - The tessellation for the surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceToNURBS (ProMechSurface surface, ProSurfacedata** nurbs_data);
/*
    Purpose: Obtains the NURBS representation of the Creo Simulate surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.

    Output Arguments:
        nurbs_data - The NURBS data.  Free this using ProSurfacedataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceTransformGet (ProMechSurface surface_1, ProMechSurface surface_2, ProUvTransform transform);
/*
    Purpose: Obtains the UV transform between two surfaces in contact.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface_1 - The first surface.
        surface_2 - The second surface.

    Output Arguments:
        transform - The UV transformation.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceThicknessEval (ProMechSurface surface, ProUvParam uv_point, double* thickness);
/*
    Purpose: Obtains the thickness of the shell Creo Simulate surface at the
             given UV point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface.
        uv_point - The UV parameter on the surface.

    Output Arguments:
        thickness - The shell thickness at the given point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsurfaceAncestorsGet (ProMechSurface surface, ProMechGeomref** ancestors);
/*
    Purpose: Obtains the ancestor surfaces for the given surface.   These are
             the actual Creo Parametric geometry surfaces used to construct this
             Creo Simulate surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        surface - The surface handle.

    Output Arguments:
        ancestors - ProArray of the ancestor geometry for the surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontourUvpntVerify (ProMechContour contour, ProUvParam uv_point, ProUvStatus* status);
/*
    Purpose: Verifies whether the specified UV point lies within the given
             Creo Simulate contour.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.
        uv_point - The UV point.

    Output Arguments:
        status - The status of the point.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontourAreaEval (ProMechContour contour, double* area);
/*
    Purpose: Finds the surface area inside the given outer contour, accounting
             for internal voids.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        contour - The contour.

    Output Arguments:
        area - The area.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of contour.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontourBoundbox2dCompute (ProMechContour contour, ProUvParam outline_points[2]);

/*
    Purpose: Finds the 2d bounding box of the Creo Simulate outer contour.

    Input Arguments:
        contour - The contour.

    Output Arguments:
        outline_points - The 2d bounding box.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontourBoundbox3dCompute (ProMechContour contour, Pro3dPnt outline_points[2]);
/*
    Purpose: Finds the 3d bounding box of the Creo Simulate outer contour.

    Input Arguments:
        contour - The contour.

    Output Arguments:
        outline_points - The 3d bounding box for the contour.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeUvdataEval (ProMechEdge edge, ProMechSurface surface, double edge_param, ProUvParam uv_point, ProUvParam deriv1, ProUvParam deriv2);
/*
    Purpose: Evaluates the Creo Simulate edge in the UV space of the given
             surface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        surface - The surface.
        edge_param - The normalized parameter on the edge.

    Output Arguments:
        uv_point - The resulting UV point, pass NULL if not interested in
                   this data.
        deriv1 - The first UV derivative, pass NULL if not interested in
                 this data.
        deriv2 - The second UV derivative, pass NULL if not interested in
                 this data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeXyzdataEval (ProMechEdge edge, double edge_param, Pro3dPnt xyz_point, ProVector deriv1, ProVector deriv2, ProVector normal);
/*
    Purpose: Evaluates the Creo Simulate edge parameter point in XYZ space.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        edge_param - The normalized parameter on the edge.

    Output Arguments:
        xyz_point - The resulting XYZ point, pass NULL if not interested in
                    this data.
        deriv1 - The first derivative at the point, pass NULL if not
                 interested in
                 this data.
        deriv2 - The second derivative at the point, pass NULL if not
                 interested in
                 this data.
        normal - The normal at the point, pass NULL if not interested
                 in this data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechedgeParamEval (ProMechEdge edge, Pro3dPnt xyz_point, double* param);
/*
    Purpose: Finds the corresponding normalized parameter on the Creo Simulate
             Edge by XYZ point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        xyz_point - The XYZ point.  The point does not necessarily have to lie
                    on the edge.  If the point is not the edge, the function
                    finds the closest point.

    Output Arguments:
        param - The normalized parameter.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeLengthEval (ProMechEdge edge, double* length);
/*
    Purpose: Obtains the length of the edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.

    Output Arguments:
        length - The length.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechedgeLengthT1T2Eval (ProMechEdge edge, double t1, double t2, double* length);
/*
    Purpose: Finds the length of the Creo Simulate edge between the given
             parameters.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        t1 - The start parameter.
        t2 - The end parameter.

    Output Arguments:
        length - The length between t1 and t2.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeParamByLengthEval (ProMechEdge edge, double t_start, double length, double* t_eval, Pro3dPnt point);
/*
    Purpose: Finds the parameter of the point located at the given length from
             the given parameter.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        t_start - The start parameter.
        length - The length.

    Output Arguments:
        t_eval - The evaluated parameter.
        point - The XYZ point at that location.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeTessellationGet (ProMechEdge edge,
                                            ProMechSurface surface,
                                            ProUvParam** uv_points,
                                            Pro3dPnt** points);
/*
    Purpose: Returns the edge tessellation  for the specified Creo Simulate
             edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.
        surface - The surface used to evaluate UV results.  Can be NULL.

    Output Arguments:
        uv_points - ProArray of UV points on the specified surface.  Can be
                    NULL.  If surface is NULL, this will contain NULL.  Free
                    this using ProArrayFree().
        points - ProArray of tessellation points.  Can be NULL.  Free this
                 using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeToNURBS (ProMechEdge edge, ProCurvedata** nurbs);
/*
    Purpose: Obtains the NURBS representation of the Creo Simulate edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge.

    Output Arguments:
        nurbs - The NURBS representation of the edge.  Free this using
                ProCurvedataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeReldirGet (ProMechEdge edge_1, ProMechEdge edge_2, ProEdgeDirection* rel_dir);
/*
    Purpose: Obtains the relative direction of two Creo Simulate edges in
             contact.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge_1 - The first edge.
        edge_2 - The second edge.

    Output Arguments:
        rel_dir - The relative direction.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechedgeAncestorsGet (ProMechEdge edge, ProMechGeomref** ancestors, ProEdgeDirection** relative_directions);
/*
    Purpose: Obtains the ancestor edges for the given edge.   These are the
             actual Creo Parametric geometry edges used to construct this Creo Simulate
             edge.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        edge - The edge handle.

    Output Arguments:
        ancestors - ProArray of the ancestor geometry for the edge.
        relative_directions - ProArray of the relative edge direction for each
                              edge.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveXyzdataEval (ProMechCurve curve, double curve_param,
                                         Pro3dPnt xyz_point,
                                         ProVector deriv1, ProVector deriv2);
/*
    Purpose: Evaluates the Creo Simulate curve parameter point in XYZ space.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.
        curve_param - The normalized parameter on the curve.

    Output Arguments:
        xyz_point - The resulting XYZ point, pass NULL if not interested in
                    this data.
        deriv1 - The first derivative at the point, pass NULL if not
                 interested in this data.
        deriv2 - The second derivative at the point, pass NULL if not
                 interested in this data.
        normal - The normal at the point, pass NULL if not interested
                 in this data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechcurveParamEval (ProMechCurve curve, Pro3dPnt xyz_point, double* param);
/*
    Purpose: Finds the corresponding normalized parameter on the Creo Simulate
             curve by XYZ point.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.
        xyz_point - The XYZ point.  The point does not necessarily have to lie
                    on the curve.  If the point is not the curve, the function
                    finds the closest point.

    Output Arguments:
        param - The normalized parameter.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveLengthEval (ProMechCurve curve, double* length);
/*
    Purpose: Obtains the length of the curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        length - The length.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveLengthT1T2Eval (ProMechCurve curve, double t1, double t2, double* length);
/*
    Purpose: Finds the length of the Creo Simulate curve between the given
             parameters.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.
        t1 - The start parameter.
        t2 - The end parameter.

    Output Arguments:
        length - The length between t1 and t2.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveParamByLengthEval (ProMechCurve curve, double t_start, double length, double* t_eval, Pro3dPnt point);
/*
    Purpose: Finds the parameter of the point located at the given length from
             the given parameter.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.
        t_start - The start parameter.
        length - The length.

    Output Arguments:
        t_eval - The evaluated parameter.
        point - The XYZ point at that location.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcurveToNURBS (ProMechCurve curve, ProCurvedata** nurbs);
/*
    Purpose: Obtains the NURBS representation of the Creo Simulate curve.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        curve - The curve.

    Output Arguments:
        nurbs - The NURBS representation of the curve.  Free this using
                ProCurvedataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

PRO_END_C_DECLS

#endif
