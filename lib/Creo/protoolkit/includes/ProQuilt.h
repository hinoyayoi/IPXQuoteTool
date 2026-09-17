#ifndef PROQUILT_H
#define PROQUILT_H


#include   <ProObjects.h>
#include   <ProGeomitem.h>

/*
   Function declarations for ProQuilt.
*/




PRO_BEGIN_C_DECLS

typedef ProError (*ProQuiltSurfaceVisitAction) ( ProSurface surface,
                                        ProError status,
                                        ProAppData app_data );

/*
   Purpose:  This is the user generic function for visiting surfaces in a quilt.

   Input Arguments:
      surface  - The handle to the surface.
      status   - The status from the filter function. If the filter 
                 function is NULL,
                 this is PRO_TK_NO_ERROR.
      app_data - The user data passed to <b>ProQuiltSurfaceVisit()</b>.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Visit the next surface.
      Other           - Causes the function to stop visiting and returns.
*/

typedef ProError (*ProQuiltSurfaceFilterAction) ( ProSurface surface,
                                        ProAppData app_data );

/*
   Purpose:  This is the user generic function for filtering surfaces in 
             a quilt.

   Input Arguments:
      surface  - The handle to the surface
      app_data - The user data passed to <b>ProQuiltSurfaceVisit()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Visit the next surface.
      PRO_TK_CONTINUE      - Skip this surface and do not call the 
                             visit function.
      PRO_TK_GENERAL_ERROR - Stop visiting and the function returns.
*/

/*===========================================================================*/

extern ProError ProQuiltInit  (ProSolid     p_owner_handle,
                               int          quilt_id,
                               ProQuilt    *p_handle);
/*
   Purpose:     Initializes the <i>ProQuilt</i> handle.

   Input Arguments:
      p_owner_handle    - The solid owner of the quilt
      quilt_id          - The quilt identifier

   Output Arguments:
      p_handle          - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProQuiltIdGet (ProQuilt   quilt,
                               int       *p_id);

/*
   Purpose: Gets the identifier of the quilt object.
<p>
            NOTE: 
<p>
            Although the pointer can be reallocated, the identifier
            will not change.

   Input Arguments:
      quilt            - The quilt handle

   Output Arguments:
      p_id             - The returned identifier of the coordinate
                         system object

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

#define ProQuiltDatatypeGet()  (PRO_QUILT)

extern ProError ProQuiltSurfaceVisit (ProQuilt           p_quilt,
				      ProQuiltSurfaceVisitAction  action,
				      ProQuiltSurfaceFilterAction  filter,
				      ProAppData         app_data);
/*
   Purpose:   Visits the surfaces of the specified quilt.

   Input Arguments:
      p_quilt           - The quilt handle
      filter            - The filter function. If NULL, all surfaces of the
                          quilt are visited using the action function. 
      action            - The action function 
      app_data          - The application data passed to the filter 
                          and visiting functions

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR        - The function successfully visited the surfaces.
      PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
      PRO_TK_NOT_IMPLEMENTED - The specified <i>p_curve</i> is a valid geometry 
                               item, but not a composite curve. 
      PRO_TK_E_NOT_FOUND     - The function did not visit any of the components,
                               either because of the filter or for another
			       reason.
      Other                  - Any other value means the action function 
                               returned something other than 
			       PRO_TK_NO_ERROR and stopped 
                               visiting the surfaces. 
*/

extern ProError ProQuiltVolumeEval   (ProQuilt      p_quilt,
				       double       *p_volume);
/*
    Purpose: Finds the quilt volume.

    Input Arguments:
        p_quilt - The quilt handle

    Output Arguments:
        p_volume - The quilt volume

    Return Values:
        PRO_TK_NO_ERROR - The function successfully found the volume.
        PRO_TK_BAD_INPUTS - The input argument is invalid.
        PRO_TK_INVALID_TYPE - The quilt supplied is not a closed quilt.
		PRO_TK_INCOMPLETE  - Maximum number of iterations was reached while
							 evaluating volume. 

*/

extern ProError ProQuiltIsBackupgeometry (ProQuilt quilt, ProBoolean *ret);
/*
    Purpose: Checks whether quilt belongs to invisible internal Copy Geom 
             Backup feature.

    Input Arguments:
        quilt - The quilt handle

    Output Arguments:
        ret   - PRO_B_TRUE if the quilt belongs to the invisible internal 
                Copy Geom Backup feature,
              - PRO_B_FALSE otherwise.  

    Return Values:
        PRO_TK_NO_ERROR - The function successfully retrieved the information.
        PRO_TK_BAD_INPUTS - The input argument is invalid.

*/

/*===========================================================================*/

PRO_END_C_DECLS
#endif /* PROQUILT_H */
