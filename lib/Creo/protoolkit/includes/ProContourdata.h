#ifndef PROCONTOURDATA_H
#define PROCONTOURDATA_H

#include   <ProObjects.h>
#include   <ProContour.h>

/*
   Function declarations and specific data structures for ProContourdata
*/




PRO_BEGIN_C_DECLS

typedef struct pro_contour_data
{
    ProContourTraversal     trav;
    int	                *edge_id_arr;	/* ProArray of identifiers of edges */
} ProContourdata;

LIB_PTK_INTF_API  ProError ProContourdataAlloc ( ProContourdata **pp_contour_data );
/*
   Purpose:     Allocates memory for the contour data structure.

   Input Arguments:
      None

   Output Arguments:
      pp_contour_data	- The contour data structure

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated memory for 
                             the contour.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProContourdataFree ( ProContourdata *p_contour_data );
/*
   Purpose: Frees the memory for the contour data structure.
   
   Input Arguments:
      p_contour_data	- The contour data structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProContourdataEdgeIdArrayGet ( ProContourdata *p_contour_data,
			  		       int **r_edge_id_arr );
/*
   Purpose:  Gets an array of edge identifiers for the contour.
   
   Input Arguments:
      p_contour_data	- The contour

   Output Arguments:
      r_edge_id_arr	- A <i>ProArray</i> of edge identifiers for the contour

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully got the array of edge 
                          identifiers.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


LIB_PTK_INTF_API  ProError ProContourdataEdgeIdArraySet ( ProContourdata	*p_contour_data,
					       int		*edge_id_arr );
/*
   Purpose:  Sets an array of edge identifiers for the contour.
   
   Input Arguments:
      p_contour_data	- The contour
      edge_id_arr	- The <i>ProArray</i> of edge identifiers for the contour

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully set the array of 
                          edge identifiers for the contour. 
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProContourdataInit ( ProContourTraversal	contour_trav,
				     ProContourdata *p_contour_data );
/*
   Purpose: Initializes the contour data structure.

   Input Arguments:
      contour_trav	- The contour traversal

   Output Arguments:
      p_contour_data	- The contour data structure

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the data structure.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/


extern ProError ProContourdataGet ( ProContourdata *p_contour_data,
				    ProContourTraversal		*p_contour_trav );
/*
   Purpose: Retrieves information from the contour data structure.

   Input Arguments:
      p_contour_data	- The contour data structure

   Output Arguments:
      p_contour_trav	- The contour traversal

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

PRO_END_C_DECLS

#endif /* PROCONTOURDATA_H */


