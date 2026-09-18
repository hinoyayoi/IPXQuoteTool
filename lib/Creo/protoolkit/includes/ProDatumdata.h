#ifndef PRODATUMDATA_H
#define PRODATUMDATA_H

#include <ProSurfacedata.h>
#include <ProCurvedata.h>
#include <ProCsysdata.h>

/*
   Function declarations and specific data structures for ProDatumdata
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef union pro_datum_obj {
    ProCurvedata	curve;
    ProPlanedata	plane;
    ProCsysdata		csys;
} ProDatumobject;

typedef struct pro_datum
{
    int			id;	/* Datum ID */
    ProType		type;	/* Datum type:
				    PRO_CURVE, PRO_DATUM_PLANE or PRO_CSYS */
    ProName		name;	/* Datum name */
    ProDatumobject	obj;	/* Datum object */
} ProDatumdata;

LIB_PTK_INTF_API  ProError ProDatumdataAlloc ( ProDatumdata **pp_datum_data );
/*
   Purpose:     Allocates memory for the datum data structure.
 
   Input Arguments:
      None
 
   Output Arguments:
      pp_datum_data   - The datum data structure
 
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully allocated memory for the
                             datum data structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - The input is invalid.
*/
 
LIB_PTK_INTF_API  ProError ProDatumdataFree ( ProDatumdata *p_datum_data );
/*
   Purpose:   Frees the memory for the datum data structure.

   Input Arguments:
      p_datum_data    - The datum data structure
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the memory.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProDatumdataInit ( int			datum_id,
				   ProType		datum_type,
				   wchar_t		*datum_name,
				   ProDatumobject	*p_datum_obj,
				   ProDatumdata *p_datum_data );
/*
   Purpose:  Initializes the datum data structure.
 
   Input Arguments:
      datum_id        - The datum identifier
      datum_type      - The datum type
      datum_name      - The datum name
      p_datum_obj     - The datum object
 
   Output Arguments:
      p_datum_data    - The datum data structure
 
   Return Values:
      PRO_TK_NO_ERROR  - The function successfully initialized the data structure.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProDatumdataGet ( ProDatumdata *p_datum_data,
				  int			*p_datum_id,
				  ProType		*p_datum_type,
				  ProName		 datum_name,
				  ProDatumobject	*p_datum_obj );
/*
   Purpose:  Retrieves information from the datum data structure.
             <p>
             NOTE:
             <p>
             The function ignores the output argument pointers that are NULL.
 
   Input Arguments:
      p_datum_data  - The datum data structure
 
   Output Arguments:
      p_datum_id    - The datum identifier
      p_datum_type  - The datum type
      datum_name    - The datum name
      p_datum_obj   - The datum object
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProDatumCurvedataInit ( ProCurvedata	*p_curve,
					ProDatumobject	*p_datum_obj );
/*
   Purpose:     Initializes the data structure for the datum curve object.
 
   Input Arguments:
      p_curve     - The datum curve
 
   Output Arguments:
      p_datum_obj - The datum object
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid. 
      PRO_TK_BSPL_MULTI_INNER_KNOTS - The curve is a B-spline with multiple
                                      inner knots.
*/

extern ProError ProDatumCurvedataGet ( ProDatumobject	*p_datum_obj,
				       ProCurvedata	*p_curve );
/*
   Purpose:  Retrieves information from the data structure for the datum 
             curve object.

   Input Arguments:
      p_datum_obj    - The datum object
 
   Output Arguments:
      p_curve	     - The datum curve
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProDatumPlanedataInit ( ProPlanedata	*p_plane,
					ProDatumobject	*p_datum_obj );
/*
   Purpose:  Initializes the data structure for the datum plane object.
   
   Input Arguments:
      p_plane	   - The datum plane
 
   Output Arguments:
      p_datum_obj  - The datum object
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the structure. 
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/

extern ProError ProDatumPlanedataGet ( ProDatumobject	*p_datum_obj,
				       ProPlanedata	*p_plane );
/*
   Purpose:  Retrieves information from the data structure for the 
             datum plane object.

   Input Arguments:
      p_datum_obj   - The datum object
 
   Output Arguments:
      p_plane	    - The datum plane
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProDatumCsysdataInit ( ProCsysdata	*p_csys,
				       ProDatumobject	*p_datum_obj );
/*
   Purpose:   Initializes the data structure for the datum 
	      coordinate system object.
 
   Input Arguments:
      p_csys       - The coordinate system
 
   Output Arguments:
      p_datum_obj  - The datum object
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid. 
*/

extern ProError ProDatumCsysdataGet ( ProDatumobject	*p_datum_obj,
				      ProCsysdata	*p_csys );
/*
   Purpose:  Retrieves information from the data structure for the datum 
             coordinate system object.

   Input Arguments:
      p_datum_obj       - The datum object
 
   Output Arguments:
      p_csys	 	- The coordinate system
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


LIB_PTK_INTF_API  ProError ProDatumdataMemoryFree ( ProDatumdata *p_datum_data );
/*
   Purpose:     Frees the top-level memory used by the datum data structure.
   
   Input Arguments:
      p_datum_data	- The datum data structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

PRO_END_C_DECLS

#endif /* PRODATUMDATA_H */
