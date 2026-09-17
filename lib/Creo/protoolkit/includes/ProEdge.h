#ifndef PROEDGE_H
#define PROEDGE_H


#include   <ProObjects.h>
#include   <ProGeomitem.h>

/*
   Function declarations for ProEdge.
*/




PRO_BEGIN_C_DECLS

typedef enum
  {
    PRO_EDGE_SAME_DIRECTION =1,
    PRO_EDGE_OPPOSITE_DIRECTION =-1
  } ProEdgeDirection;
/*===========================================================================*/

extern ProError ProEdgeInit     (ProSolid    owner_handle,
				 int         edge_id,
				 ProEdge    *p_handle);
/*
   Purpose: Initializes the <i>ProEdge</i> handle.

   Input Arguments:

      owner_handle      - The solid owner of the edge

      edge_id           - The edge identifier

   Output Arguments:

      p_handle          - The handle being initialized

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle. 
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProEdgeIdGet (ProEdge   edge,
                              int*      p_id);

/*
   Purpose: Retrieves the identifier of the edge.

   Input Arguments:
      edge            - The edge handle

   Output Arguments:
      p_id             - The returned identifier of the edge 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

#define ProEdgeDatatypeGet()  (PRO_EDGE)


extern ProError ProEdgeDataGet  (ProEdge           edge,
				 ProGeomitemdata  **p_data_ptr);
/*
   Purpose: Retrieves the geometric representation data for the specified
            edge.
 
   Input Arguments:
      edge              - The edge handle.

   Output Arguments:
      p_data_ptr        - The edge data. The function allocates the memory
                          for this argument. Use the function
                          <b>ProGeomitemdataFree()</b> to free the memory.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProGeomitemdataFree()
*/


extern ProError ProEdgeXyzdataEval (ProEdge      edge,
				    double       edge_param,
				    ProVector    xyz_point,
				    ProVector    deriv1,
				    ProVector    deriv2,
				    ProVector    direction);
/*
   Purpose: Evaluates the edge at the specified parameter.

   Input Arguments:
      edge              - The edge handle
      edge_param        - The normalized parameter on the edge

   Output Arguments:
      xyz_point         - The resulting XYZ point
      deriv1            - The first derivative
      deriv2            - The second derivative
      direction		- The edge direction

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the edge.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProEdgeUvdataEval  (ProEdge       edge,
				    double        edge_param,
				    ProUvParam    uv_point[2],
				    ProUvParam    deriv1[2],
				    ProUvParam    deriv2[2]);
/*
   Purpose: Evaluates the edge in the UV-space.

   Input Arguments:
      edge              - The edge handle
      edge_param        - The normalized parameter on the edge

   Output Arguments:
      uv_point          - The resulting UV point
      deriv1            - The first UV derivative
      deriv2            - The second UV derivative

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the edge.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProEdgeParamEval  (ProEdge     edge,
				   ProVector   xyz_point,
				  double     *p_param);
/*
   Purpose: Finds a corresponding normalized parameter on the edge,
            given the XYZ point.
	    <B>Note:</B> The function is intended to be used when the point is on, 
	    or very nearly on, the edge.	    
 
   Input Arguments:
      edge              - The edge handle.
      xyz_point         - The XYZ point. The point does not necessarily have
                          to lie on the edge. If the point is not on the
                          edge, the function finds the closest edge point.

   Output Arguments:
      p_param           - The corresponding normalized parameter on the edge.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the edge.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProEdgeDirGet (ProEdge      edge,
			       ProSurface   face_handle,
			        int         *p_direction); 
/*
   Purpose: Finds the edge direction in the specified surface.
 
   Input Arguments:
      edge		- The edge handle
      face_handle       - The surface handle (adjacent to the edge)
 
   Output Arguments:
      p_direction       - The direction
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully retrieved the direction.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProEdgeLengthEval (ProEdge   edge, 
				   double    *p_length);
/*
   Purpose: Finds the length of the specified edge. 

   Input Arguments:
      edge              - The edge handle

   Output Arguments:
      p_length          - The edge length

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the edge length.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern ProError ProEdgeNeighborsGet (ProEdge       edge,
			             ProEdge      *p_edge1,
				     ProEdge      *p_edge2,
				     ProSurface   *p_face1,
				     ProSurface   *p_face2);
/*
   Purpose: Retrieves information about the neighboring surfaces and
	    edges of the specified edge.
 
   Input Arguments:
      edge              - The edge handle
 
   Output Arguments:
      p_edge1           - The next edge in the contour on <i>p_face1</i>
      p_edge2           - The next edge in the contour on <i>p_face2</i>
      p_face1		- The first adjacent surface
      p_face2		- The second adjacent surface
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern ProError ProEdgeVertexdataGet (ProEdge       edge_end,
                                      ProType       param_type,
				      ProEdgelist  *p_vertex_arr,
                                      ProType     **p_end_type_arr,
				      ProSurflist  *p_surf_arr,
				      int          *p_count);
/*
   Purpose: Finds the neighbors of the edge at the specified end.
 
   Input Arguments:
      edge_end          - The edge "end" handle.
      param_type        - PRO_EDGE_START or PRO_EDGE_END.

   Output Arguments:
      p_vertex_arr      - The array of edges meeting at the specified edge
                          end. Use the function <b>ProArrayFree()</b> to free 
                          the memory for this argument. If not required, this
                          argument can be NULL.
                        
      p_end_type_arr    - An array of end types of the neighboring edges
                          given by <i>p_vertex_arr</i>. Each end type can either
                          be PRO_EDGE_START or PRO_EDGE_END. Use the function
                          <b>ProArrayFree()</b> to free the memory for this
                          argument. If not required, this argument can be NULL.

      p_surf_arr        - The array of surface adjacent to the edges.
                          Use the function <b>ProArrayFree()</b> to free the 
                          memory for this argument. If not required, this 
                          argument can be NULL.
 
      p_count           - The size of the <i>p_vertex_arr</i>, 
                          <i>p_end_type_arr</i>, and
                          <i>p_surf_arr</i> arrays. If not required, this 
                          argument can be NULL.
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully retrieved the data.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
	  PRO_TK_INVALID_TYPE - The edge is not in visible geometry.

   See Also:
      ProArrayFree()
*/


extern ProError ProEdgeTessellationGet (ProEdge          edge,
				        Pro3dPnt**       p_points,
                                        ProSurface       adj_srfs[2],
                                        ProUvParam**     p_uv_arr1,
                                        ProUvParam**     p_uv_arr2,
					int*             p_count);
/*
   Purpose: Retrieves the edge tessellation for the specified edge.
 
   Input Arguments:
      edge              - The edge handle.
 
   Output Arguments:
      p_points          - The list of tessellation points (to be released by
                          <b>ProArrayFree()</b>). If not required, this argument
                          may be NULL.
      adj_srfs          - The adjacent surfaces.  If not required, this argument
                          may be NULL. This will contain only 1 surface if the edge 
						  is a 1-sided edge.
      p_uv_arr1         - The first array of UV points (to be released by
                          <b>ProArrayFree()</b>). If not required, this argument
                          may be NULL.
      p_uv_arr2         - The second array of UV points (to be released by
                          <b>ProArrayFree()</b>). If not required, this argument
                          may be NULL.
      p_count           - The size of the <i>p_points</i> array. If not 
                          required, this argument may be NULL.
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProArrayFree()
*/


extern ProError ProEdgeTypeGet   (ProEdge      edge, 
				  ProEnttype  *p_edge_type);
/*
   Purpose: Retrieves the type of the specified edge.

   Input Arguments:
      edge              - The edge handle

   Output Arguments:
      p_edge_type       - The edge type

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern ProError ProEdgeToNURBS (ProEdge edge,
                                ProCurvedata** p_curve_data);

/*
   Purpose: Generates the NURBS curve representation, given the edge
            handle.

   Input Arguments:
      edge              - The edge handle.

   Output Arguments:
      p_curve_data      - The curve data. The function allocates the memory 
                          for this argument, but you must free it by calling
                          the function <b>ProCurvedataFree()</b>.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProCurvedataFree()
*/

extern ProError  ProEdgeLengthT1T2Eval (ProEdge p_handle, double t1,  double t2,
                                                double  *p_length);
/*
   Purpose: Finds the length of the specified edge between two given parameters.

   Input Arguments:
      p_handle     - The edge handle
      t1		- The start parameter
      t2		- The end parameter

   Output Arguments:
      p_length          - The edge length

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully evaluated the edge length.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/

extern ProError ProEdgeParamByLengthEval
        (
        ProEdge          p_handle,
        double           t_start,
        double           length,
        double           *r_t,
        Pro3dPnt         r_point
        );
/*
   Purpose: Finds the parameter of the point located at the given length
            from the given parameter.

   Input Arguments:
      p_handle     - The edge handle
      t_start           - The start parameter
      length            - The given length

   Output Arguments:
      r_t               - The output parameter
      r_point           - The point

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the edge length.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/

/*===========================================================================*/
				   
PRO_END_C_DECLS
#endif /* PROEDGE_H */

