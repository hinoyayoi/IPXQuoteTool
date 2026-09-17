#ifndef PROAXIS_H
#define PROAXIS_H


#include   <ProObjects.h>
#include   <ProGeomitem.h>

/*
   Function declarations for ProAxis.
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

extern ProError ProAxisInit     (ProSolid    owner_handle,
				 int         axis_id,
				 ProAxis     *p_handle);
/*
   Purpose: Initializes the <i>ProAxis</i> handle.
 
   Input Arguments:
      owner_handle      - The solid owner of the axis
      axis_id           - The axis identifier
 
   Output Arguments:
      p_handle          - The handle to initialize
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProAxisIdGet (ProAxis   axis,
                              int       *p_id);

/*
   Purpose: Gets the identifier of the axis object.
<p>
            NOTE:
<P>
            Although the pointer can be reallocated, the identifier
            will not change.


   Input Arguments:
      axis            - The axis handle

   Output Arguments:
      p_id             - The returned identifier of the coordinate
                         system object

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

#define ProAxisDatatypeGet()   (PRO_AXIS)

extern ProError ProAxisDataGet  (ProAxis            axis,
				 ProGeomitemdata  **p_data_ptr);
/*
   Purpose: Retrieves the geometric representation data for the 
            specified axis.
 
   Input Arguments:
      axis            - The axis handle.
 
   Output Arguments:
      p_data_ptr        - The axis data. The function allocates the memory
                          for this argument. Use the function
                          <b>ProGeomitemdataFree()</b> to free the memory.

   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully retrieved the data. 
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProGeomitemdataFree()
*/

extern ProError ProAxisSurfaceGet (ProMdl     owner,
                                   ProAxis    axis, 
				   ProSurface *p_surface);
/*
   Purpose: Retrieves the surface that owns the specified axis.
 
   Input Arguments:
      owner             - The owner of the axis
      axis              - The axis handle
 
   Output Arguments:
      p_surface         - The surface handle to be filled in

   Return Values: 
      PRO_TK_NO_ERROR    - The function successfully retrieved the surface.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The owner surface does not exist, or is not in 
                           the geometry.
*/

/*===========================================================================*/
				   
PRO_END_C_DECLS
#endif /* PROCURVE_H */


