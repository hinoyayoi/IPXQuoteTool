#ifndef PROCONTOUR_H
#define PROCONTOUR_H


#include   <ProObjects.h>
#include   <ProUvStat.h>

/*
   Function declarations for ProCurve.
*/




PRO_BEGIN_C_DECLS

typedef enum
{
   PRO_CONTOUR_TRAV_NONE     =  0,
   PRO_CONTOUR_TRAV_INTERNAL = -1,
   PRO_CONTOUR_TRAV_EXTERNAL =  1
} ProContourTraversal;

/*===========================================================================*/

typedef ProError (*ProContourEdgeVisitAction) ( ProEdge p_edge,
                                                ProError status,
                                                ProAppData app_data);
/*
   Purpose:  This is the generic function for visiting an edge in a contour.

   Input Arguments:
      p_edge   -  The handle to the edge
      status   -  The status from the filter function
      app_data -  The application data passed to <b>ProContourEdgeVisit()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Visit the next edge.
      Other           - Stop visiting, and the function returns.

*/

typedef ProError (*ProContourEdgeFilterAction) ( ProEdge p_edge,
                                                 ProAppData app_data);
/*
   Purpose: This is the filter function used by the visit function.

   Input Arguments:
      p_edge   -  The handle to the edge
      app_data -  The application data passed to <b>ProContourEdgeVisit()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Call the visit function.
      PRO_TK_CONTINUE      - Skip to the next edge (call the filter function
                             for the next edge, if present).
      PRO_TK_GENERAL_ERROR - Stop the visit function.
*/

extern ProError ProContourEdgeVisit   ( ProSurface surface,
                                        ProContour        p_contour,
                                        ProContourEdgeVisitAction action,
                                        ProContourEdgeFilterAction filter,
                                        ProAppData        app_data);
/*
   Purpose: Visits all the edges of the specified contour.

   Input Arguments:
      surface           - The surface of the contour.
      p_contour         - The contour handle.
      action            - The action function to be called for each edge.
                          If it returns anything other than PRO_TK_NO_ERROR,
                          visiting stops. Note that you must specify this 
                          argument.
      filter            - The filter function. If NULL, visits all edges
                          using the action function.
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR        - The function successfully visited the edges.
      PRO_TK_BAD_INPUTS      - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND     - No edges were visited, either because of the
                               filter or for another reason.
      Other                  - Any other value is the value returned by the 
                               action function (visiting stopped).
*/


extern ProError ProContourTraversalGet (ProContour    p_contour,
				        ProContourTraversal*   p_traversal);
/*
   Purpose: Retrieves the contour traversal.   

   Input Arguments:
      p_contour      - The contour handle

   Output Arguments:
      p_traversal    - The traversal

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProContainingContourFind ( ProSolid solid,
                                           ProContour contour,
                                           ProContour* p_containing_contour);


/*
   Purpose:  Finds a pointer to the innermost contour that closes the specified
             contour. If the specified contour is internal, the returned
             contour will be external, and vice versa. If the specified contour
             is the outermost contour for the surface, the output will be NULL.

   Input Arguments:
      solid          - The solid owner of the contour (of type PRO_PART
                       or PRO_ASSEMBLY)
      contour        - The contour handle 

   Output Arguments:
      p_containing_contour    - The pointer to the contour

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The specified contour was not found.
      PRO_TK_INVALID_PTR - The specified pointer is not a solid pointer.
*/

extern   ProError ProContourAreaEval
        (
        ProSurface        p_srf_handle,
        ProContour        p_cntr_handle,
        double           *r_area
        );
/*
   Purpose:     Finds the inside surface area of the specified outer contour,
                taking into account internal voids.

   Input Arguments:
      p_srf_handle      - The surface handle
      p_cntr_handle     - The outer contour handle

   Output Arguments:
      r_area            - The contour area

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully found the surface area.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/



extern  ProError ProContourBoundbox2dCompute
        (
        ProSurface       p_srf_handle,
        ProContour       p_cntr_handle,
        Pro2dPnt         r_outline_points[2]
        );
/*
   Purpose: Finds the 2d bounding box for the inside surface of the given outer
            contour.

   Input Arguments:
      p_srf_handle       - The surface handle, may be NULL.
      p_cntr_handle      - The outer contour handle, may be NULL.

   Output Arguments:
      r_outline_points   - The contour 2d bounding box, may be NULL.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully found the surface area.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/


extern   ProError ProContourUvpntVerify
        (
        ProSurface       p_srf_handle,
        ProContour       p_cntr_handle,
        Pro2dPnt         uv_point,
        ProUvStatus      *r_result
        );
/*
   Purpose:  Verifies whether the specified UV point lies within the
             given contour.

   Input Arguments:
      p_srf_handle      - The surface handle
      p_cntr_handle     - The contour handle
      uv_point          - The UV point to test

   Output Arguments:
      r_result          - The resulting status:
                          PRO_UV_AMBIGUOUS - point is on the contour
                          PRO_UV_OUTSIDE   - point is outside the contour
                          PRO_UV_INSIDE    - point is inside the contour

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully verified the point.
      PRO_TK_BAD_SRF_CRV - One or more of the input arguments are invalid.
*/

extern   ProError ProContourBoundbox3dCompute 
        (
        ProSurface       p_srf_handle,
        ProContour       p_cntr_handle,
        Pro3dPnt         r_outline_points[2] 
        );

/*
   Purpose:  Finds the 3d bounding box for the inside surface of the specified 
             outer contour, taking into account internal voids.
             <P>
             <B>Note:</B> The outline returned by the function 
             ProContourBoundbox3dCompute() represents the outline box used by 
             Creo Parametric embedded algorithms, and hence it can be slightly 
             bigger than the outline computed directly from the surface parameters.

   Input Arguments:
      p_srf_handle      - The surface handle
      p_cntr_handle     - The contour handle

   Output Arguments:
      r_outline_points  - The contour 3d bounding box

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully found the 3d bounding box.
      PRO_TK_BAD_SRF_CRV - One or more of the input arguments are invalid.
*/

PRO_END_C_DECLS

#endif /* PROCONTOUR_H */


