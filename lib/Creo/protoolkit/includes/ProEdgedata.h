#ifndef PROEDGEDATA_H
#define PROEDGEDATA_H

#include   <ProObjects.h>
#include   <ProCurvedata.h>

/*
   Function declarations and specific data structures for ProEdgedata
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef enum
{
	PRO_EDGE_NO_FLIP = 0,
	PRO_EDGE_FLIP
} ProEdgeDir;

typedef struct pro_edge_data
{
    int			id;			/* Edge id */
    int			surf_ids[2];		/* Ids of each side surface */
    ProEdgeDir		directions[2];		/* Directions on each side
						   surface */
    ProUvParam		(*uv_points)[2];	/* ProArray of curve UV-points
	on each side surface:
	uv_points[i][0] - uv-coordinates of point "i" on one surface
	uv_points[i][1] - uv_coordinates of point "i" on another surface */
    ProCurvedata	*p_uv_curve_data[2];	/* UV-curves on each side
						   surface */
    ProCurvedata	*p_curve_data;		/* XYZ-curve */
} ProEdgedata;


LIB_PTK_INTF_API  ProError ProEdgedataAlloc ( ProEdgedata **pp_edge_data );
/*
   Purpose:     Allocates memory for the edge data structure.

   Input Arguments:
      None

   Output Arguments:
      pp_edge_data      - The edge data structure

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated memory for the
                             edge data structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProEdgedataFree ( ProEdgedata *p_edge_data );
/*
   Purpose:     Frees all the underlying memory for the edge data structure.
   
   Input Arguments:
      p_edge_data	- The edge data structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProEdgedataMemoryFree ( ProEdgedata *p_edge_data );
/*
   Purpose:     Frees the top-level memory used by the edge data structure.
   
   Input Arguments:
      p_edge_data	- The edge data structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProEdgedataInit ( int			edge_id,
				  int			edge_surf_ids[2],
				  ProEdgeDir		edge_directions[2],
				  ProUvParam		(*edge_uv_point_arr)[2],
				  ProCurvedata		*p_edge_uv_curve_data[2],
				  ProCurvedata		*p_edge_curve_data,
				  ProEdgedata *p_edge_data );
/*
   Purpose:     Initializes the edge data structure.

   Input Arguments:
      edge_id              - The edge identifier.
      edge_surf_ids        - The edge identifiers of the surfaces.
      edge_directions      - The edge directions on the surfaces.
      edge_uv_point_arr    - The <i>ProArray</i> of UV-points on the surfaces. 
                             This can be NULL.
      p_edge_uv_curve_data - The edge UV-curves on the surfaces. This can be NULL.
      p_edge_curve_data    - The edge XYZ-curve. This can be NULL.

   Output Arguments:
      p_edge_data          - The edge data structure.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully initialized the 
                             data structure.
      PRO_TK_BAD_INPUTS	   - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProEdgedataGet ( ProEdgedata *p_edge_data,
				 int		*p_edge_id,
				 int		edge_surf_ids[2],
				 ProEdgeDir	edge_directions[2],
				 ProUvParam	(**p_edge_uv_point_arr)[2],
				 ProCurvedata	*p_edge_uv_curve_data[2],
				 ProCurvedata	*p_edge_curve_data );
/*
   Purpose:  Retrieves information from the edge data structure.
             <p>
             NOTE:
             <p>
             The function ignores the output argument pointers that are NULL.

   Input Arguments:
      p_edge_data           - The edge data structure

   Output Arguments:
      p_edge_id             - The edge identifier
      edge_surf_ids         - The edge identifiers of the surfaces
      edge_directions       - The edge directions on the surfaces
      p_edge_uv_point_arr   - The pointer to a <i>ProArray</i> of UV-points on 
                              the surfaces
      p_edge_uv_curve_data  - The edge UV-curves on the surfaces
      p_edge_curve_data     - The edge XYZ-curve

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/


PRO_END_C_DECLS

#endif /* PROEDGEDATA_H */

