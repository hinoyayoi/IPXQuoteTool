#ifndef PROGEOMITEM__H
#define PROGEOMITEM__H

#include   <ProObjects.h>
#include   <ProSelection.h>
#include   <ProGeomitemdata.h>

/*
   Function declarations and specific data structures for ProGeomitem
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef ProEdge    *ProEdgelist; 
typedef ProSurface *ProSurflist;
typedef ProVector  *ProVectorlist; 

extern ProError ProGeomitemToSurface ( ProGeomitem *p_geom_item,
	          	               ProSurface  *r_surf_handle );
/*
   Purpose: Converts a surface <I>ProGeomitem</I> handle to a 
            <I>ProSurface</I> handle.

   Input Arguments:
      p_geom_item       - The surface geometry item handle

   Output Arguments:
      r_surf_handle     - The surface handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to a surface handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to a surface.
*/

extern ProError ProGeomitemToEdge ( ProGeomitem *p_geom_item,
		                    ProEdge     *r_edge_handle );
/*
   Purpose:     Converts an edge <I>ProGeomitem</I> handle to a <I>ProEdge</I> 
                handle.

   Input Arguments:
      p_geom_item       - The edge geometry item handle

   Output Arguments:
      r_edge_handle     - The edge handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to an edge handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to an edge.
*/

extern ProError ProGeomitemToQuilt ( ProGeomitem *p_geom_item,
		                     ProQuilt     *r_quilt_handle );
/*
   Purpose:     Converts a quilt <I>ProGeomitem</I> handle to a 
                <I>ProQuilt</I> handle.

   Input Arguments:
      p_geom_item       - The quilt geometry item handle

   Output Arguments:
      r_quilt_handle    - The quilt handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to a quilt handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to a quilt.
*/

extern ProError ProGeomitemToCurve ( ProGeomitem *p_geom_item,
		                     ProCurve     *r_curve_handle );
/*
   Purpose:     Converts a curve <I>ProGeomitem</I> handle to a 
                <I>ProCurve</I> handle.

   Input Arguments:
      p_geom_item       - The curve geometry item handle

   Output Arguments:
      r_curve_handle    - The curve handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to a curve handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to a curve.
*/

extern ProError ProGeomitemToCsys ( ProGeomitem *p_geom_item,
		                    ProCsys     *r_csys_handle);
/*
   Purpose:     Converts a coordinate system <I>ProGeomitem</I> handle to a 
                <I>ProCsys</I> handle.

   Input Arguments:
      p_geom_item       - The coordinate system geometry item handle

   Output Arguments:
      r_csys_handle     - The coordinate system handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to a coordinate system handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to a coordinate system.
*/

extern ProError ProGeomitemToAxis ( ProGeomitem *p_geom_item,
		                    ProAxis     *r_axis_handle);
/*
   Purpose:     Converts an axis <I>ProGeomitem</I> handle to a 
                <I>ProAxis</I> handle.

   Input Arguments:
      p_geom_item       - The axis geometry item handle

   Output Arguments:
      r_axis_handle     - The axis handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to an axis handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to an axis.
*/

extern ProError ProGeomitemToPoint ( ProGeomitem *p_geom_item,
		                     ProPoint     *r_point_handle);
/*
   Purpose:     Converts a point <I>ProGeomitem</I> handle to a 
                <I>ProPoint</I> handle.

   Input Arguments:
      p_geom_item       - The point geometry item handle

   Output Arguments:
      r_point_handle    - The point handle initialized, based on the
                          input geometry item handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          geometry item handle to a point handle.
      PRO_TK_BAD_INPUTS - The input geometry item handle is invalid, or does not
                          refer to a point.
*/

extern ProError ProSurfaceToGeomitem ( ProSolid      solid,
		                       ProSurface    surf_handle,
		                       ProGeomitem  *r_geom_item );
/*
   Purpose: Converts a <I>ProSurface</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <i>surf_handle</i>.
      surf_handle       - The <I>ProSurface</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the surface.
                          You must allocate the memory for this structure.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          surface handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProEdgeToGeomitem ( ProSolid      solid,
		                    ProEdge       edge_handle,
		                    ProGeomitem  *r_geom_item );
/*
   Purpose:     Converts a <I>ProEdge</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <i>edge_handle</i>.
      edge_handle       - The <I>ProEdge</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the edge.
                          You must allocate the memory for this structure. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          edge handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProQuiltToGeomitem ( ProSolid      solid,
		                     ProQuilt      quilt_handle,
		                     ProGeomitem  *r_geom_item);
/* 
   Purpose:     Converts a <I>ProQuilt</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <I>quilt_handle</I>.
      quilt_handle      - The <I>ProQuilt</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the quilt.
                          You must allocate the memory for this structure. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          quilt handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/ 
 
extern ProError ProCurveToGeomitem ( ProSolid      solid,
		                     ProCurve      curve_handle,
		                     ProGeomitem  *r_geom_item );
/* 
   Purpose:     Converts a <I>ProCurve</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <i>curve_handle</i>.
      curve_handle      - The <I>ProCurve</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the curve.
                          You must allocate the memory for this structure. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          curve handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProCsysToGeomitem ( ProSolid      solid,
		                    ProCsys       csys_handle,
		                    ProGeomitem  *r_geom_item );
/* 
   Purpose:     Converts a <I>ProCsys</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <I>csys_handle</I>.
      csys_handle       - The <I>ProCsys</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the coordinate system.
                          You must allocate the memory for this structure.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          coordinate system handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/ 
 
extern ProError ProAxisToGeomitem ( ProSolid      solid,
		                    ProAxis       axis_handle,
		                    ProGeomitem  *r_geom_item );
/* 
   Purpose:     Converts a <I>ProAxis</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <I>axis_handle</I>.
      axis_handle       - The <I>ProAxis</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the axis.
                          You must allocate the memory for this structure. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          axis handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/ 
 
extern ProError ProPointToGeomitem ( ProSolid      solid,
		                     ProPoint      point_handle,
		                     ProGeomitem  *r_geom_item );
/* 
   Purpose:     Converts a <I>ProPoint</I> handle to its <I>ProGeomitem</I> handle.

   Input Arguments:
      solid             - The owner of the <I>point_handle</I>.
      point_handle      - The <I>ProPoint</I> handle to convert.

   Output Arguments:
      r_geom_item       - The <I>ProGeomitem</I> handle for the point.
                          You must allocate the memory for this structure.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully converted the
                          point handle to its geometry item handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/ 
 
extern ProError ProGeomitemDistanceEval ( ProSelection p_selection1,
			                  ProSelection p_selection2,
			                  double       *p_result );
/*
   Purpose:     Evaluates the distance between two items.
 
   Input Arguments:
      p_selection1	- The first item. This can be a point, axis,
                          or planar surface.
      p_selection2	- The second item. This can be a point, axis, or
                          planar surface.
 
   Output Arguments:
      p_result          - The resulting distance between the two items.
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully evaluated the distance. 
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProGeomitemAngleEval ( ProSelection p_selection1,
		                       ProSelection p_selection2,
		                       double       *p_result );
/*
   Purpose:     Evaluates the angle between two items. Currently, only straight
                edges are supported.

   Input Arguments:
      p_selection1      - The first item
      p_selection2      - The second item

   Output Arguments:
      p_result          - The resulting angle
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully evaluated the angle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProGeomitemDiameterEval ( ProSelection p_selection,
			                  double       *p_result );
/*
   Purpose:     Finds the geometry item (surface) diameter. This function
                is similar to <B>ProSurfaceDiameterEval()</B>.

   Input Arguments:
      p_selection       - The geometry item. Only revolved surfaces
                          (cylinder, cone, and so on) are valid. 

   Output Arguments:
      p_result          - The diameter.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the diameter.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProSurfaceDiameterEval()
*/


extern ProError ProGeomitemFeatureGet ( ProGeomitem  *p_geom_item, 
			                ProFeature   *p_feat_handle );
/*
   Purpose:     Retrieves the feature that creates the specified geometry item.

   Input Arguments:
      p_geom_item       - The item handle

   Output Arguments:
      p_feat_handle	- The feature that creates the geometry item

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the feature.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern ProError ProGeomitemIsInactive ( ProGeomitem  *p_geom_item,
			                ProBoolean   *p_is_active );
/*
   Purpose:     Determines whether the specified geometry item is in visible 
                geometry. 
<p>
                NOTE:
<p>
                This function does not check whether the item is blanked by 
                a layer.

   Input Arguments:
      p_geom_item       - The geometry item.

   Output Arguments:
      p_is_active       - If the item is invisible, this is PRO_B_TRUE. 
                          Otherwise, this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully checked visibility.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern ProError ProGeometryAtPointFind ( ProPart part,
			                 Pro3dPnt point,
			                 ProSelection** p_sel_arr,
			                 int* p_count);

/*
   Purpose:     Determines the surfaces or edges on which the specified
                point is located.  If a point lies on an edge, the function
                does not return the neighboring surfaces.
  
   Input Arguments:
      part      -  The part handle.
      point     -  A three-dimensional point, in the coordinates of the part.
   
   Output Arguments:
      p_sel_arr - An array of <I>ProSelection</I>, which has information
                  about surfaces or edges on which the point is located.  
                  The function allocates space for this array; free it
		  using ProSelectionarrayFree().
      p_count   - The number of items on which the point lies.
 
  Return Values:
      PRO_TK_NO_ERROR    - The function successfully evaluated the point.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND - The surface or edge was not found.
*/

PRO_END_C_DECLS

#endif /* PROGEOMITEM__H */
