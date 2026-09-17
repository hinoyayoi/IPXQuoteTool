#ifndef PROQUILTDATA_H
#define PROQUILTDATA_H

#include   <ProObjects.h>
#include   <ProSurfacedata.h>

/*
   Function declarations and specific data structures for ProQuiltdata
*/




PRO_BEGIN_C_DECLS


typedef struct ptc_quilt
{
    int                 id;             /* the quilt identifier */
    ProSurfacedata	**arr_p_surf;	/* ProArray of pointers to surface data structures of quilt */
} ProQuiltdata;

/*===========================================================================*/
LIB_PTK_INTF_API  ProError ProQuiltdataAlloc ( ProQuiltdata **pp_quilt_data );
/*
   Purpose:     Allocates memory for the quilt data structure.

   Input Arguments: 
      none

   Output Arguments:
      pp_quilt_data	- The quilt data structure

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated memory for the
                             data structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProQuiltdataFree ( ProQuiltdata *p_quilt_data );
/*
   Purpose:    Frees all the underlying memory used by the quilt data structure.
   
   Input Arguments:
      p_quilt_data	- The quilt data structure
 
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProQuiltdataMemoryFree ( ProQuiltdata *p_quilt_data );
/*
   Purpose:     Frees the top-level memory used by the quilt data structure.
   
   Input Arguments:
      p_quilt_data	- The quilt data structure

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProQuiltdataInit ( int	quilt_id,
		                   ProQuiltdata *p_quilt_data );
/*
   Purpose:     Initializes the quilt data structure.

   Input Arguments:
      quilt_id		- The quilt identifier

   Output Arguments:
      p_quilt_data	- The quilt data structure

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the data structure.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProQuiltdataGet ( ProQuiltdata *p_quilt_data,
		                  int	*p_quilt_id );
/*
   Purpose: Retrieves information from the quilt data structure.

   Input Arguments:
      p_quilt_data	- The quilt data structure

   Output Arguments:
      p_quilt_id	- The quilt identifier

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProQuiltdataSurfArrayGet ( ProQuiltdata *p_quilt_data,
			   ProSurfacedata ***r_arr_p_surf );
/*
   Purpose:  Retrieves an array of pointers to surfaces of the quilt.
   
   Input Arguments:
      p_quilt_data	- The quilt

   Output Arguments:
      r_arr_p_surf	- A <i>ProArray</i> of pointers to surfaces of the quilt

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProQuiltdataSurfArraySet ( ProQuiltdata	*p_quilt_data,
	           		           ProSurfacedata **arr_p_surf );
/*
   Purpose:     Sets an array of pointers to surfaces of the quilt.
   
   Input Arguments:
      p_quilt_data	- The quilt
      arr_p_surf	- The <i>ProArray</i> of pointers to surfaces of the quilt
   
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully set the information. 
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

PRO_END_C_DECLS

#endif /* PROQUILTDATA_H */
