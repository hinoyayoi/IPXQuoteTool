#ifndef PROSRF_H
#define PROSRF_H


#include   <ProObjects.h>
#include   <ProGeomitem.h>
#include   <ProUvStat.h>
#include   <ProPart.h>
/*
   Function declarations for ProSurface.
*/




PRO_BEGIN_C_DECLS

typedef struct pro_surface_tessellation_input* ProSurfaceTessellationInput; 
typedef struct pro_tessellation* ProTessellation;
typedef enum
{
  PRO_SRFTESS_DEFAULT_PROJECTION,  /* Default projection; this will provide UV params for the
				      tessellation points which map to a plane whose 
				      U and V extents are each [0,1] */
  PRO_SRFTESS_PLANAR_PROJECTION, /* Project the UV params using a planar transform, where
				    u = x, v = y, z is ignored. */
  PRO_SRFTESS_CYLINDRICAL_PROJECTION, /* Project the UV params using a cylindrical transform,
					 where where x = r*cos(theta) and y = r*sin(theta);
					 u = theta, v = z, r is ignored */
  PRO_SRFTESS_SPHERICAL_PROJECTION, /* Project the UV params onto a sphere, 
				      where x = r*cos(theta)*sin(phi), y = r*sin(theta)*sin(phi), 
				      z = r*cos(phi); u = theta, v = phi, r is ignored */
  PRO_SRFTESS_NO_PROJECTION,   /* no projection; this will provide unmodified UV params for the
				      tessellation points  */
  PRO_SRFTESS_BOX_PROJECTION  /* Project the UV params using a box transform, where we project 
                      point on face of box which intersects normal. u = x in local coordinate 
                      system of face of box, v = y in local coordinate system of face of box, z is ignored.*/


} ProSurfaceTessellationProjection;

typedef enum
{
   PRO_TK_LIGHT_AMBIENT = 0, /* Read only, not allowed to set */
   PRO_TK_LIGHT_DIRECTION,
   PRO_TK_LIGHT_POINT,
   PRO_TK_LIGHT_SPOT,
   PRO_TK_LIGHT_HDRI, /* Image Map / HDRI Lighting / Read only, not allowed to set */
   PRO_TK_LIGHT_SKY
} ProLightType;

typedef enum pro_texture_projection_type
{
  PRO_TEXTURE_PROJECTION_UNSET = 0,
  PRO_TEXTURE_PROJECTION_PLANER = 1,
  PRO_TEXTURE_PROJECTION_SPHERICAL = 2,
  PRO_TEXTURE_PROJECTION_CYLINDRICAL = 3,
  PRO_TEXTURE_PROJECTION_APPLICATION = 4,
  PRO_TEXTURE_PROJECTION_BOX = 5
} ProTextureProjectionType;

typedef struct pro_tk_light
{
   wchar_t name[PRO_NAME_SIZE];
   ProLightType type;
   ProBoolean status;   /* active or inactive */
   double rgb[3]; /* for all types */
   double position[3]; /* for point and spot */
   double direction[3]; /* for direction and spot */
   double spread_angle; /* for spot, in radian */
   ProBoolean cast_shadows;
} ProLightInfo;

typedef struct pro_surface_texture_properties
{
  ProCharPath       decal;
  double            decal_intensity;      /* future use only */
  ProCharPath       texture_map;
  ProCharPath       bump_map;
  double            bump_height;          /* future use only */
  ProTextureProjectionType   projection;
  double            local_csys[4][3];
  int               copies;               /* future use only */
  float             horizontal_offset;
  float             vertical_offset;
  float             rotate;
  float             horizontal_scale;
  float             vertical_scale;
} ProSurfaceTextureProperties;

typedef struct pro_surface_texture_props
{
  ProCharPath       decal;
  ProCharPath       texture_map;
  ProCharPath       bump_map;
} ProSurfaceTextureProps;

typedef enum pro_texture_type
{
  PRO_NULL_TEXTURE = -1,
  PRO_BUMP_TEXTURE = 0,
  PRO_COLOR_TEXTURE = 1,
  PRO_DECAL_TEXTURE = 2
} ProTextureType;

typedef struct pro_surface_texture_placement_props
{

  ProTextureProjectionType   projection;
  ProTextureType    texture_type;
  ProLineEnvelope            local_csys;
  double             horizontal_offset;
  double             vertical_offset;
  double             rotate;
  double             horizontal_scale;
  double             vertical_scale;
  double            bump_height;
  double            decal_intensity;
  ProBoolean        flip_horizontal;
  ProBoolean        flip_vertical;
} ProSurfaceTexturePlacementProps;

typedef struct pro_surf_appearance_props
{
  double ambient;
  double diffuse;
  double highlite;
  double shininess;
  double transparency;
  ProVector color_rgb;
  ProVector highlight_color;
  double reflection;
  ProPath name;
  ProPath label;
  ProPath description;
  ProPath keywords;
} ProSurfaceAppearanceProps;


/*===========================================================================*/
   
extern ProError ProSurfaceInit     (ProMdl        p_owner_handle,
				    int           surf_id,
				    ProSurface   *p_surface);
/* 
   Purpose: Initializes the <i>ProSurface</i> handle.

   Input Arguments:
      p_owner_handle	- The solid owner of the surface
      surf_id		- The surface identifier

   Output Arguments:
      p_surface		- The handle being initialized
   
   Return Values: 
      PRO_TK_NO_ERROR 	- The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProSurfaceIdGet (ProSurface   surface,
                                int       *p_id);

/*
   Purpose: Retrieves the identifier of the curve object.
<p>
            NOTE: 
<p>
            Although the pointer can be reallocated, the identifier
            will not change.

   Input Arguments:
      surface         - The surface handle

   Output Arguments:
      p_id            - The identifier of the coordinate
                        system object

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

#define ProSurfaceDatatypeGet() (PRO_SURFACE)

extern ProError ProSurfaceDataGet  (ProSurface         p_surface,
				    ProGeomitemdata  **p_data_ptr);
/*
   Purpose:     Retrieves the geometric representation data of the specified
                surface.

   Input Arguments:
      p_surface       	- The surface handle.
 
   Output Arguments:
      p_data_ptr        - The surface data. The function allocates the
                          memory for this argument. Use the function
			  <b>ProGeomitemdataFree()</b> to free the memory.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProGeomitemdataFree()
*/


extern ProError ProSurfaceXyzdataEval (ProSurface   p_surface,
				       ProUvParam   uv_point,
				       ProVector    xyz_point,
				       ProVector    deriv1[2],
				       ProVector    deriv2[3],
				       ProVector    normal);
/*
   Purpose:     Evaluates the surface in the specified UV point.
 
   Input Arguments:
      p_surface       	- The surface handle
      uv_point		- The UV parameter on the surface
 
   Output Arguments:
      xyz_point         - The resulting XYZ point
      deriv1		- The first derivative in the UV point
      deriv2		- The second derivative in the UV point
      normal		- The outward normal to the surface in the UV point
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully evaluated the surface.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProSurfaceParamEval  (ProSolid      solid_handle,
                                      ProSurface    surface,
				      ProVector     xyz_point,
				      ProUvParam    uv_point);
/*
   Purpose:     Finds the closest corresponding UV point on the surface,
                given the xyz point.

                NOTE:  This function returns the closest point in the 
                       geometric surface, not the closest point inside
                       the surface contour (face) specified.
                       
 
   Input Arguments:
      solid_handle      - The owner of the surface.
      surface           - The surface handle.
      xyz_point		- The XYZ point. The point does not necessarily have
			  to lie on the surface. If the point is off the
                          surface, the function finds the closest surface point.
 
   Output Arguments:
      uv_point          - The corresponding UV point on the surface.
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully evaluated the point.
      PRO_TK_BAD_INPUTS - One or more of input arguments are invalid.
      PRO_TK_E_NOT_FOUND - Projection of the point to the surface was not found.
*/


extern ProError ProSurfaceAreaEval   (ProSurface      p_surface,
				       double         *p_area);
/*
   Purpose:     Finds the surface area.
 
   Input Arguments:
      p_surface         - The surface handle
 
   Output Arguments:
      p_area            - The surface area
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully found the surface area.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
      PRO_TK_OUT_OF_RANGE - Surface area is too small (almost zero).
*/


extern ProError ProSurfaceUvpntVerify (ProSolid       solid_handle,
                                       ProSurface     p_surface, 
				       ProUvParam     uv_point,
				       ProUvStatus   *p_result);
/*
   Purpose:  Verifies whether the specified UV point lies within the surface
             boundaries.
 
   Input Arguments:
      solid_handle      - The owner of the surface
      p_surface         - The surface handle
      uv_point		- The UV point to test
 
   Output Arguments:
      p_result          - The resulting status
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully verified the point.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProSurfaceDiameterEval (ProSurface    p_surface,
					ProUvParam    uv_point,
					double       *p_diameter);
/*
   Purpose:     Finds the surface diameter in the specified UV point. 
 
   Input Arguments:
      p_surface         - The surface handle. Only revolved surfaces are 
			  allowed (cylinder, cone, and so on).
      uv_point		- The UV point. This is ignored when the surface 
                          diameter is constant.
 
   Output Arguments:
      p_diameter        - The resulting diameter.
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully evaluated the diameter.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProSurfaceExtremesEval (ProSurface   p_surface,
				        ProVector    dir,
				        ProVector    xyz_min,
				        ProVector    xyz_max);
/*
   Purpose:     Finds the coordinates of the surface edges at the extremes, 
                in the specified direction. The accuracy of this result
                is limited to the accuracy of the edge tessellation.
 
   Input Arguments:
      p_surface         - The surface handle
      dir		- The direction of projection
 
   Output Arguments:
      xyz_min           - The coordinates of the point where the
                          function finds the minimum projection
      xyz_max           - The coordinates of the point where the
                          function finds the maximum projection
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully evaluated the surface.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProSurfaceTypeGet      (ProSurface    p_surface, 
				        ProSrftype   *p_srf_type);
/*
   Purpose:     Retrieves the surface type.
 
   Input Arguments:
      p_surface         - The surface handle
 
   Output Arguments:
      p_srf_type        - The surface type
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully retrieved the surface type.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProSurfaceQuiltGet  (ProSolid       owner_handle,
                                     ProSurface    p_surface, 
                                     ProQuilt     *p_quilt);
/*
   Purpose:    Retrieves the quilt that owns the specified surface. 
 
   Input Arguments:
      owner_handle      - The owner of the surface
      p_surface         - The surface handle
 
   Output Arguments:
      p_quilt	        - The handle to the owner quilt
 
   Return Values: 
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_E_NOT_FOUND - The specified surface does not belong to any quilt.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

typedef ProError (*ProSurfaceContourVisitAction) 
                           ( ProContour  p_contour,
                             ProError    status,
                             ProAppData  app_data
                           );

/*
   Purpose:  This is the generic function for visiting contours on surfaces.

   Input Arguments:
       p_contour   -  The contour handle
       status      -  The status
       app_data    -  The application data passed to the function
                      <b>ProSurfaceContourVisit()</b>

   Output Arguments:
       None
   
   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/

typedef ProError (*ProSurfaceContourFilterAction) 
                           ( ProContour  p_contour,
                             ProAppData  app_data
                           );

/*
   Purpose:  This is the generic function for filtering contours. 

   Input Arguments:
       p_contour   -  The contour handle
       app_data    -  The application data passed to the function
                      <b>ProSurfaceContourVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_CONTINUE      - Skip visiting this contour and go to the next
                              contours.
       Other                - Call the visit action for this contour. The return
                              value is passed as input to the visit action.  
*/


extern ProError ProSurfaceContourVisit    (ProSurface   p_surface, 
					   ProSurfaceContourVisitAction  action,
				           ProSurfaceContourFilterAction filter,
				           ProAppData   app_data);
						    
/*
   Purpose:   Visits all the contours of the specified surface.

   Input Arguments:
      p_surface    - The surface handle.
      action       - The action function called for each contour being visited.
                     Visiting stops if this function returns
                     anything other than PRO_TK_NO_ERROR.
      filter       - The filter function called for each contour before the 
                     action is taken. If this function returns PRO_TK_CONTINUE,
                     the action function skips that contour. Any other return
                     value is passed to the action function. If NULL, all 
                     contours are visited using the action function.
     app_data      - The application data passed to the action and filter 
                     functions.
 
   Output Arguments:
      None
 
   Return Values: 
      PRO_TK_NO_ERROR    - The function successfully visited all the contours. 
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - No contours were visited (either because of the 
                           filter or for another reason).
      Other              - Any other value is the value returned from the 
                           action function (visiting stopped).
*/

extern ProError ProSldsurfaceVolumesFind ( ProPart part,
                                           int    *p_count,
                                           int   **p_count_array,
                                           int  ***p_surface_id_array );

/*
   Purpose:   Analyzes and returns the number of connect volumes of a part,
              and the surfaces that bound them.
<p>
              Free the memory for the <i>p_surface_id_array</i> as follows:

                 <pre>for (i = 0; i < p_count; i++)</pre>
                      <pre>ProArrayFree((ProArray) p_surface_id_array[i]);</pre>


   Input Arguments:
      part -  The part handle.

   Output Arguments:
      p_count             - The number of distinct volumes found.
      p_count_array       - The array that contains the number of surfaces in
                            each identified volume.  The function allocates
                            the memory for this argument, but you must free it. 
      p_surface_id_array  - An array of arrays of surface identifiers
                            that contains the connected volumes 
                            found. The function allocates the memory for this
                            argument.
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully performed the analysis.  
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The specified volume was not found.

   See Also:
      ProArrayFree()
*/

extern ProError ProSurfaceToNURBS (ProSurface surface,
                                   ProSurfacedata** p_nurb_surf_data);

/*
   Purpose:   Generates the NURBS surface representation, given the
              surface handle.

   Input Arguments:
      surface          - The surface handle.
 
   Output Arguments:
      p_nurb_surf_data - A pointer to a <i>ProSurfacedata</i> structure. The
                         function allocates the memory for this argument. To 
                         free it, call the function 
                         <b>ProSurfacedataFree()</b>.
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully generated the NURBS
                          surface. 
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProSurfacedataFree()

*/

extern ProError ProSurfaceDataFree ( ProSurfacedata** p_curve_data );
/*
   Purpose:  Frees the memory for the <i>ProSurface</i> structure.

   Input Arguments:
      p_curve_data - The address to the <i>ProCurvedata*</i>, allocated 
                     by <b>ProSurfaceToNURBS()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the memory.
      PRO_TK_BAD_INPUTS - The input is invalid. 

   See Also:
      ProSurfaceToNURBS()
*/

extern ProError ProSurfaceSameSrfsFind (ProSolid      solid,
                                        ProSurface    surface,
                                        ProSurface  **r_surf_arr,
                                        int          *r_size);
/*
   Purpose: Finds and returns an array of surfaces that are the same as the
            input surface. For example, in the case of a cylinder, Creo Parametric
            creates two half-cylindrical surfaces. If you input one half, the
            other half is returned by this function.

   Input Arguments:
        solid		- The owner of the surface.
	surface		- The surface whose same surfaces are to be found.

   Output Arguments:
        r_surf_arr	- The returned array of surfaces. This will include 
	                  the input surface.  You must preallocate this array 
			  using <b>ProArrayAlloc()</b>.  Free it using 
			  <b>ProArrayFree()</b>			  
	r_size		- The size of the array. This argument is optional 
                          (can be NULL).

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.

   See Also:
      ProArrayAlloc()
*/


extern   ProError ProSurfacePrincipalCrvtEval 
        (
        ProSurface       p_srf_handle,
        ProUvParam       uv_point,
        double           *r_max_curvature,
        double           *r_min_curvature,
        ProVector        r_curv_dirs[2]
        );
/*
   Purpose:     Finds principal curvatures and directions of the surface
                at the given UV point.

   Input Arguments:
      p_srf_handle      - The surface handle
      uv_point          - The point on the surface

   Output Arguments:
      r_max_curvature   - Maximum curvature at the point
      r_min_curvature   - Minimum curvature at the point
      r_curv_dirs	- Principal directions at the point

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully found the surface area.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/

extern ProError ProSurfacetessellationinputAlloc (ProSurfaceTessellationInput* input_data);
/*
    Purpose: Allocates the handle to the input data used for surface 
             tessellation.

    Input Arguments:
        none

    Output Arguments:
        input_data - The input data handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSurfacetessellationinputFree (ProSurfaceTessellationInput input_data);
/*
    Purpose: Frees the handle to the input data used for surface tessellation.

    Input Arguments:
        input_data - The input data handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

#define PRO_SRFTESS_CHORD_HT_DEFAULT 0.0

extern ProError ProSurfacetessellationinputChordheightSet (ProSurfaceTessellationInput input_data, double chord_height);
/*
    Purpose: Assigns the chord height used for the surface tessellation.
             

    Input Arguments:
        input_data - The input data handle.
        chord_height - The chord height used for the tessellation.  Pass 
                    PRO_SRFTESS_CHORD_HT_DEFAULT to use the tessellation 
                    routine used by Creo Parametric to perform shading operations.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSurfacetessellationinputAnglecontrolSet (ProSurfaceTessellationInput input_data, double angle_control);
/*
    Purpose: Assigns the angle control value used for the tessellation.

    Input Arguments:
        input_data - The input data handle.
        angle_control - The angle control value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSurfacetessellationinputStepsizeSet (ProSurfaceTessellationInput input_data, double step_size);
/*
    Purpose: Assigns the maximum step size value used for the tessellation.

    Input Arguments:
        input_data - The input data handle.
        step_size - The maximum step size value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSurfaceTessellationGet (ProSurface surface,
                                           ProSurfaceTessellationInput input,
                                           ProTessellation* tessellation);
/*
    Purpose: Calculates the tessellation of a given surface.

    Input Arguments:
        surface - The surface.
        input - Input instructions for the tessellation.

    Output Arguments:
        tessellation - The tessellation data.  Free this using
                       ProTessellationFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_OUT_OF_MEMORY - Creo Parametric could not allocate memory for the 
	                      output.
        PRO_TK_GENERAL_ERROR - The function could not generate the tessellation
	                       for the input surface.  
*/

extern ProError ProTessellationFree (ProTessellation tessellation);
/*
    Purpose: Frees the tessellation data for an individual surface.

    Input Arguments:
        tessellation - The tessellation data handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProTessellationVerticesGet (ProTessellation tessellation, Pro3dPnt** vertices);
/*
    Purpose: Obtains the vertices that make up this tessellation.

    Input Arguments:
        tessellation - The tessellation data handle.

    Output Arguments:
        vertices - ProArray of vertices.  Free this using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProTessellationNormalsGet (ProTessellation tessellation, ProVector** normals);
/*
    Purpose: Obtains the normal vectors for each of the tessellation vertices.


    Input Arguments:
        tessellation - The tessellation data handle.

    Output Arguments:
        normals - ProArray of normal vectors for the tessellation.  Free this
                  using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProTessellationParamsGet (ProTessellation tessellation, ProUvParam** params);
/*
    Purpose: Obtains the UV parameters for each of the tessellation vertices.

    Input Arguments:
        tessellation - The tessellation data handle.

    Output Arguments:
        params - ProArray of UV parameters for the tessellation points.  Free
                 this using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The UV projection was not calculated for this tessellation 
	                   operation. Call ProSurfacetessellationinputUvprojectionSet()
			   before ProSurfaceTessellationGet(). 
*/

extern ProError ProTessellationFacetsGet (ProTessellation tessellation, ProTriangle** facets);
/*
    Purpose: Obtains the indices indicating the vertices used for each facet
             for the tessellated item.

    Input Arguments:
        tessellation - The tessellation data handle.

    Output Arguments:
        facets - ProArray of indices for the facets in the tessellation.  Free
                 this using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSurfaceIsDatumPlane (ProSolid p_solid, ProSurface p_surface, ProBoolean* p_is_datum_plane);
/*
    Purpose: Identifies if the given surface is a datum plane. 

    Input Arguments:
	p_solid - The surface owner.
	p_surface - The surface.

    Output Arguments:
	p_is_datum_plane - PRO_B_TRUE if the surface is a datum plane, PRO_B_FALSE if the surface is a solid or quilt surface.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSurfacetessellationinputUvprojectionSet (ProSurfaceTessellationInput input_data,
                                                            ProSurfaceTessellationProjection projection_type,
                                                            ProCsysdata* projection_csys);
/*
   Purpose: Assigns the parameters used to calculate a UV projection for 
            texture mapping to the tessellation inputs.

   Input Arguments:
       input_data - The input data handle.
       projection_type - The type of projection to use for the UV 
                         calculations.
       projection_csys - The csys data to use for the projection, if 
                         applicable. Pass NULL for a default projection.

   Output Arguments:
       none

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProLightSourcesGet( int window_id, 
                                    ProLightInfo** light_info);
/*

Purpose: Retrieves the light information associated with the specified window in
         model space. 

Input Arguments:
    window_id - The identifier of the Creo Parametric window.
                Use PRO_VALUE_UNUSED (or a value less than 0)for the 
                current window.

Output Arguments:
    light_info - ProArray of structures of light properties. The function 
                 allocates memory for this argument. To free it, call the 
                 function ProArrayFree.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - The argument is invalid.

*/

extern ProError ProLightSourcesSet( int window_id,
                                    ProLightInfo* light_info);
/*

Purpose: Sets the light information associated with the specified window in
         model space.
 
Input Arguments:
    window_id - The identifier of the Creo Parametric window. 
                Use PRO_VALUE_UNUSED (or a value less than 0)for the 
                current window.
    light_info - ProArray of structures of light properties. Since the number
                 of user defined lights cannot exceed 5, this array must have
                 no more than 5 elements.

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - The argument is invalid.
    PRO_TK_CANT_MODIFY - This type of light is not allowed to be set.
                         (PRO_TK_LIGHT_AMBIENT, PRO_TK_LIGHT_HDRI).
    PRO_TK_UNSUPPORTED - light_info has more than 5 elements.

*/

typedef struct pro_sldsurface_shell_order
{
  int orientation;   /* 1 if the shell is oriented outward; -1 if inward      */
                     /* (in which case the shell is actually a void)          */
  int first_face;    /* index in shell_faces array                            */
  int number_of_faces;
  int ambient_shell; /* index in shell_order array                            */
                     /* if the shell is external this field is equal to -1    */
} ProSldsurfaceShellorder;


typedef struct pro_sldsurface_shell_face
{
  int        surf_id;
  ProContour contour; /* NULL if face is fully in the shell */
} ProSldsurfaceShellface;


extern ProError ProSldsurfaceShellsAndVoidsFind(
 ProSolid solid,
 ProSldsurfaceShellorder **shell_order,
 ProSldsurfaceShellface  **shell_faces
);
/*
   Purpose:   For each shell and void of this solid, returns surface-contour
               pairs which describe them.
              <p>NOTE: When the surface is split into a few pieces
              (has more than one external contour) these pieces may belong 
              to different shells. Hence, each shell face has to be described by
              a pair (surface id, ProContour) - see ProSldsurfaceShellface.

   Input Arguments:
      solid              -   The solid handle. Cannot be NULL.

   Output Arguments:
      shell_order       -   ProArray of ProSldsurfaceShellorder structures. 
                            The function allocates the memory for this
                            argument. Cannot be NULL.
                            Free this output using ProArrayFree().
      shell_faces       -   ProArray of ProSldsurfaceShellface structures.
                            For each shell or void, their faces take 
                            a contingent segment in this array.
                            The function allocates the memory for this
                            argument. Cannot be NULL.
                            Free this output using ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully performed the task.
      PRO_TK_BAD_INPUTS  - NULL was passed for some arguments.
      PRO_TK_E_NOT_FOUND - The solid has no geometry.
      PRO_TK_NOT_VALID   - the topology of solid is not valid.
*/

extern ProError ProSurfaceAppearancepropsGet(
  ProModelitem* item,
  ProSurfaceAppearanceProps *appearance_properties
);
/*
Purpose: Gets the appearance properties of the surface.

Input Arguments:
    item - The modelitem representing the part, assembly component, 
           subassembly, quilt or surface.

Output Arguments:
    appearance_properties - Structure containing appearance related properties.
Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_NOT_EXIST - The property does not exists.
*/

extern ProError ProSurfaceAppearancepropsSet(
  ProModelitem* item,
  ProSurfaceAppearanceProps *appearance_properties
);
/*
Purpose: Sets the appearance properties of the surface.

Input Arguments:
    item - The modelitem representing the part, assembly component, 
           subassembly, quilt or surface.
    appearance_properties - Structure containing surface appearance properties.
                            Pass NULL to set default surface appearance 
                            properties.

Output Arguments:
    none
    
Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_CANT_MODIFY - The property cannot be modified.
    
*/
   
extern ProError ProSurfaceTextureplacementpropsGet(
  ProModelitem *item,
  ProSurfaceTexturePlacementProps **texture_placement_properties
);

/*

Purpose: Gets the texture placement related properties of the surface.

Input Arguments:
    item - The modelitem representing the part, assembly component,
           subassembly, quilt or surface.

Output Arguments:
    texture_placement_properties - ProArray of structures containing texture 
                         placement properties. The function allocates memory
                         for this argument. To free it, call the function
                         ProArrayFree.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_NOT_EXIST - Properties does not exist on item.

*/

extern ProError ProSurfaceTextureplacementpropsSet(
  ProModelitem *item,
  ProSurfaceTexturePlacementProps *texture_placement_properties
);

/*

Purpose: Sets the texture placement placement properties of the surface.

Input Arguments:
    item - The modelitem representing the part, assembly component, subassembly,
           quilt or surface.
    texture_placement_properties - ProArray of structures containing texture
                                   placement properties.


Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_CANT_MODIFY - The property cannot be modified.

*/

extern ProError ProSurfaceTexturepropsGet(
  ProModelitem *item,
  ProSurfaceTextureProps *texture_properties
);

/*

Purpose: Gets the texture related properties of the surface.

Input Arguments:
    item - The modelitem representing the part, assembly component,
           subassembly, quilt or surface.

Output Arguments:
    texture_properties - Pointer to structure containing texture 
                         related properties.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_NOT_EXIST - Properties does not exist on item.

*/

extern ProError ProSurfaceTexturepropsSet(
  ProModelitem *item,
  ProSurfaceTextureProps *texture_properties
);

/*

Purpose: Sets the texture related properties of the surface.

Input Arguments:
    item - The modelitem representing the part, assembly component, subassembly,
           quilt or surface.
    texture_properties - Structure containing texture related properties. 

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_CANT_MODIFY - The property cannot be modified.

*/

extern ProError ProSurfaceNextGet (
  ProSurface this_surface,
  ProSurface *p_next_surface
);
/*

Purpose: Returns the next surface in the surface list 
         (or NULL, if there is no next surface)
         <B>Note:</B> If the model geometry has changed, 
         the next surface must be obtained again.

Input Arguments:
    this_surface  - the surface for which the next surface is queried;
                    can be NULL.

Output Arguments:
    p_next_surface - a non-NULL pointer for returning the next surface; 
                     if this_surface is the last in the list (or this_surface
                     is NULL) then the returned surface will be NULL

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - p_next_surface is passed NULL.
*/


/* ====================================================================== */
extern ProError ProSurfacePeriodicityGet(ProSurface surface, 
                                         ProBoolean *periodic_in_u,
                                         double     *period_in_u,
                                         ProBoolean *periodic_in_v,
                                         double     *period_in_v);
/*
Purpose: Provides the periodicity data of a surface.
         <b>Warning: </b>. The function only returns periodicity flags
         as stored by Creo, not the actual geometric periodicity.
         Even if the actual geometry of the surface is periodic in u or v
         direction but is not marked as periodic by Creo, this function
         will not attempt to recognize it and will return PRO_B_FALSE.

Input Arguments:
    surface - the surface. Cannot be NULL.

Output Arguments:
    periodic_in_u - periodicity in u-direction. Can be NULL.
    period_in_u   - the value of the period in u-direction. Can be NULL.
    periodic_in_v - periodicity in v-direction. Can be NULL.
    period_in_v   - the value of the period in v-direction. Can be NULL.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - surface is NILL.

*/


/*===========================================================================*/


PRO_END_C_DECLS
#endif /* PROSRF_H */

