#ifndef PROPOINT_H
#define PROPOINT_H


#include   <ProObjects.h>
#include   <ProGeomitem.h>

/*
   Function declarations for ProPoint.
*/




PRO_BEGIN_C_DECLS

typedef enum pro_point_type
{

  PRO_POINT_TYP_END1 =		1,
  PRO_POINT_TYP_END2 =		2,
  PRO_POINT_TYP_CENTER = 	3,  /* for arcs/circles only */
  PRO_POINT_TYP_NONE =		4,  
  PRO_POINT_TYP_MIDPT = 	5

} ProPointType;

/*===========================================================================*/

extern ProError ProPointInit  (ProSolid   owner_handle,
                               int        point_id,
                               ProPoint  *p_handle);
/*
   Purpose:     Initializes the <i>ProPoint</i> handle.

   Input Arguments:
      owner_handle      - The solid owner of the point
      point_id          - The point identifier

   Output Arguments:
      p_handle          - The handle being initialized

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProPointIdGet (ProPoint   point,
                               int       *p_id
			      );

/*
   Purpose: Gets the identifier of the point object.
<p>
   <b>     NOTE:</b> 
<p>
            Although the pointer can be reallocated, the identifier 
            will not change.

   Input Arguments:
      point            - The point handle

   Output Arguments:
      p_id             - The returned identifier of the coordinate
                         system object

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

#define ProPointDatatypeGet   (PRO_POINT)

extern ProError ProPointCoordGet (ProPoint    point,
				  ProVector   xyz_point);
/*
   Purpose:  Retrieves the XYZ coordinates of the specified point.     

   Input Arguments:
      point             - The point handle

   Output Arguments:
      xyz_point		- The XYZ coordinates of the point

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProPoint3dOnsurfaceFind(
        ProPoint3d      xyz,        
        ProSurface      surface,   
        ProBoolean     *on_surf,  
        ProPoint3d      closest_pt);
/*
   Purpose: Determines if distance between the specified point and the specified
            surface is less than the Creo Parametric model accuracy set in the
            active Creo Parametric session. You can also set accuracy with function
            ProSolidAccuracySet().
<p>
            For more details on setting accuracy, refer to Technical Documents
            "Detailed Information Regarding Model Accuracy", number 32869, and
            "New Config.pro Option "Enable_Assembly_Accuracy" is Available in
            Release 20 9823 or Later", number 22077. These documents are
            available at HTTP://WWW.PTC.COM.

   Input Arguments:
       xyz             - Handle for specified point, must not be NULL.
       surface         - Handle for specified surface, must not be NULL.

   Output Arguments:
       on_surf         - The point is ON (PRO_B_TRUE) or OFF (PRO_B_FALSE)
                          the surface; must not be NULL.
       closest_pt      - Handle for location of closest point to surface;
                          may be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS - An input argument is invalid.
*/

extern ProBoolean ProPoint3dIntoleranceFind(
        ProPoint3d      xyz_1,  
        ProPoint3d      xyz_2, 
        double         *exceed_tol);
/*

   Purpose: Determines if two points are co-incident, that is, if the  
            distance between two points is within the Creo Parametric tolerances
            as set in ProSolidToleranceGet().

   Input Arguments:
       xyz_1          - Handle for the first specified point; must not be NULL.
       xyz_2          - Handle for second specified point; must not be NULL.

   Output Arguments:
       exceed_tol     - Amount by which the distance between the points
                         exceeds tolerance; can be NULL.

   Return Values:
      PRO_B_TRUE        - Points are within tolerance.
      PRO_B_FALSE       - Points are not within tolerance.
*/

/*===========================================================================*/
				   
PRO_END_C_DECLS
#endif /* PROPOINT_H */
