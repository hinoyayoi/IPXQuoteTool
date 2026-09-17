#ifndef PROSURFACEDATA_H
#define PROSURFACEDATA_H

#include   <ProObjects.h>
#include   <ProContourdata.h>
#include   <ProEdgedata.h>

/*
   Function declarations and specific data structures for ProSurfacedata
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

/* -----------------------------------------------------------------------
                  Surface shape data structures
   ----------------------------------------------------------------------- */

typedef struct Ptc_plane
{
    ProVector  e1, e2, e3;
    Pro3dPnt   origin;
                                /* Local coordinate system. */
} ProPlanedata;

typedef struct ptc_cylinder
{
    ProVector  e1, e2, e3;
    Pro3dPnt   origin;
    double     radius;
} ProCylinderdata;

typedef struct ptc_cone
{
    ProVector  e1, e2, e3;
    Pro3dPnt   origin;
    double     alpha;
} ProConedata;

typedef struct ptc_torus
{
    ProVector  e1, e2, e3;
    Pro3dPnt   origin;
    double     radius1;
    double     radius2;
} ProTorusdata;

typedef struct ptc_srfrev
{
    ProVector    e1, e2, e3;
    Pro3dPnt     origin;
    ProCurvedata curve;
} ProSrfrevdata;

typedef struct ptc_rulsrf
{
    ProVector      e1, e2, e3;
    Pro3dPnt       origin;
    ProCurvedata   curve_1;
    ProCurvedata   curve_2;
} ProRulsrfdata;

typedef struct ptc_tabcyl
{
    ProVector    e1, e2, e3;
    Pro3dPnt     origin;
    ProCurvedata curve;
} ProTabcyldata;

typedef struct ptc_coons
{
    ProCurvedata  le_curve;               /* u = 0 boundary. */
    ProCurvedata  ri_curve;               /* u = 1 boundary. */
    ProCurvedata  dn_curve;               /* v = 0 boundary. */
    ProCurvedata  up_curve;               /* v = 1 boundary. */
    Pro3dPnt      point_matrix[2][2];     /* Corner points. */
    Pro3dPnt      uvder_matrix[2][2];     /* Corner mixed derivatives. */
} ProCoonsdata;

typedef struct ptc_filsrf
{
    ProSplinedata  pnt_spline;    /* Spline running along u = 0 boundary. */
    ProSplinedata  ctr_spline;    /* Spline running along "axis".         */
    ProSplinedata  tan_spline;    /* Spline of unit tangents along axis.  */
} ProFilsrfdata;

typedef struct ptc_splsrf
{
    double   *u_par_arr;    /* Array of U parameter grid */
    double   *v_par_arr;    /* Array of V parameter grid */
    Pro3dPnt *point_arr;    /* Array of interpolant points */
    Pro3dPnt *u_tan_arr;    /* Array of U derivatives at these points */
    Pro3dPnt *v_tan_arr;    /* Array of V derivatives at these points */
    Pro3dPnt *uvder_arr;    /* Array of UV derivatives at the interpolant points */    
    int       num_u;        /* Size in U */
    int       num_v;        /* Size in V */
} ProSplinesrfdata;

typedef struct ptc_splsrf2ndDer
{
    double    *u_par_arr;    /* Array of U parameter grid */
    double    *v_par_arr;    /* Array of V parameter grid */
    Pro3dPnt  *point_arr;    /* Array of interpolant points */
    Pro3dPnt  *u_tan_arr;    /* Array of U derivatives at these points */
    Pro3dPnt  *v_tan_arr;    /* Array of V derivatives at these points */
    Pro3dPnt  *uvder_arr;    /* Array of UV derivatives at the interpolant points */
    Pro3dPnt  *u_der2_arrs[2]; /* Array of U 2nd derivatives in V bound. point */
    Pro3dPnt  *v_der2_arrs[2]; /* Array of V 2nd derivatives in U bound. point */
    Pro3dPnt  *uuv_der[2];     /* Array of UUV 3rd derivatives */
    Pro3dPnt  *vvu_der[2];     /* Array of VVU 3rd derivatives */
    Pro3dPnt  *der4[4];        /* UUVV derivatives at the corners */
    int       num_u;        /* Size in U */
    int       num_v;        /* Size in V */
} ProSpline2ndDersrfdata;

typedef struct ptc_gen_splsrf
{
    ProVector         e1, e2, e3;
    Pro3dPnt          origin; /* Local coordinate system. */
    ProSplinesrfdata  splsrf;                /* In appropriate coordinates */
} ProCylsplsrfdata, ProSphsplsrfdata;

typedef struct ptc_b_splsrf
{
    int       deg[2];        /* Basis functions degrees (in directions
                                U and V). */
    double   *u_par_arr;     /* Expandable array of knots on the
                                parameter line, U. */
    double   *v_par_arr;     /* Expandable array of knots on the
                                parameter line, V*/
    double   *wghts;         /* In the case of rational B-splines, this is
                                an expandable array of the same dimension
                                as the array of c_point_arr. Otherwise,
				this is NULL. */
    Pro3dPnt *c_point_arr;   /* Expandable array of control points. */
    int       num_u;         /* The size in U. */
    int       num_v;         /* The size in V. */
    int       num_c_point;   /* The number of control points. */
} ProBsplinesrfdata;

typedef struct Ptc_frgnsrf
{
    ProVector  e1, e2, e3;
    Pro3dPnt   origin;
                                 /* Local coordinate system. */
    int        foreign_id;       /* foreign_id returned from user_init_surf*/
} ProFrgnsrfdata;

typedef union ptc_srfshape
{
    ProPlanedata      plane;
    ProCylinderdata   cylinder;
    ProConedata       cone;
    ProTorusdata      torus;
    ProSrfrevdata     srfrev;
    ProTabcyldata     tabcyl;
    ProRulsrfdata     rulsrf;
    ProCoonsdata      coons;
    ProFilsrfdata     filsrf;
    ProSplinesrfdata  spl_srf;
    ProBsplinesrfdata b_spl_srf;
    ProCylsplsrfdata  cyl_splsrf;
    ProFrgnsrfdata    frgnsrf;
    ProSpline2ndDersrfdata splsrf_2ndder;
} ProSurfaceshapedata;

typedef enum pro_srf_type
{
    PRO_SRF_NONE =     -3,
    PRO_SRF_PLANE =    34,
    PRO_SRF_CYL =      36,
    PRO_SRF_CONE =     37,
    PRO_SRF_TORUS =    38,
    PRO_SRF_COONS =    39,
    PRO_SRF_SPL =      40,
    PRO_SRF_FIL =      41,
    PRO_SRF_RUL =      42,
    PRO_SRF_REV =      43,
    PRO_SRF_TABCYL =   44,
    PRO_SRF_B_SPL =    45,
    PRO_SRF_FOREIGN =  46,
    PRO_SRF_CYL_SPL =  48,
    PRO_SRF_SPL2DER =  50
} ProSrftype;

typedef enum pro_surf_orient
{
    PRO_SURF_ORIENT_NONE	=  0,
    PRO_SURF_ORIENT_OUT		=  1,	/* if du x dv points outside */
    PRO_SURF_ORIENT_IN		= -1	/* if du x dv points inside */ 
} ProSurfaceOrient;

typedef struct ptc_surf
{
    ProSrftype          type;           /* Surface type */         
    ProUvParam          uv_min;         /* Minimum UV extents */
    ProUvParam          uv_max;         /* Maximum UV extents */
    ProPoint3d          xyz_min;        /* Minimum XYZ extents (approximate) */ 
                                        /* Use only for output (from 
                                           Creo Parametric TOOLKIT) purpose only */
    ProPoint3d          xyz_max;        /* Maximum XYZ extents (approximate) */ 
                                        /* Use only for output (from 
                                           Creo Parametric TOOLKIT) purpose only */
    ProSurfaceOrient    orient;
    ProSurfaceshapedata srf_shape;
    int                 user_int[4];    /* Space for user integer data */
    int                 id;             /* The surface identifier */
    char               *user_ptr[4];    /* Space for user pointer data */
    ProContourdata     *contour_arr;    /* ProArray of ProContourdata 
					   structures */
} ProSurfacedata;

LIB_PTK_INTF_API  ProError ProSurfacedataAlloc ( ProSurfacedata **pp_surf_data );
/*
   Purpose:     Allocates memory for a surface data structure.

   Input Arguments:
      None

   Output Arguments:
      pp_surf_data	- The surface data structure

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated memory for the 
                             data structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - The input is invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfacedataFree ( ProSurfacedata *p_surf_data );
/*
   Purpose:     Frees all underlying memory of the surface data structure.
   
   Input Arguments:
      p_surf_data	- The surface data structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfacedataMemoryFree ( ProSurfacedata *p_surf_data );
/*
   Purpose:     Frees the top-level memory used by the surface data structure.
   
   Input Arguments:
      p_surf_data	- The surface data structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfacedataInit ( ProSrftype			surf_type,
				     ProUvParam			surf_uv_min,
				     ProUvParam			surf_uv_max,
				     ProSurfaceOrient		surf_orient,
				     ProSurfaceshapedata	*p_surf_shape,
				     int			surf_id,
				     ProSurfacedata *p_surf_data );
/*
   Purpose:     Initializes a surface data structure.

   Input Arguments:
      surf_type		- The surface type
      surf_uv_min	- The surface minimum UV extents.
                          <P>If you are using this data to create a feature 
			  via ProImportfeatCreate(), the extents are not
			  used and can be set to {0.0, 0.0}
      surf_uv_max	- The surface maximum UV extents
                          <P>If you are using this data to create a feature 
			  via ProImportfeatCreate(), the extents are not
			  used and can be set to {0.0, 0.0}
      surf_orient	- The surface orientation
      p_surf_shape	- The surface shape
      surf_id		- The surface identifier

   Output Arguments:
      p_surf_data	- The surface data structure

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the data structure.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProSurfacedataGet ( ProSurfacedata *p_surf_data,
				    ProSrftype			*p_surf_type,
				    ProUvParam			surf_uv_min,
				    ProUvParam			surf_uv_max,
				    ProSurfaceOrient		*p_surf_orient,
				    ProSurfaceshapedata		*p_surf_shape,
				    int				*p_surf_id );
/*
   Purpose:     Retrieves information from the surface data structure.
<p>
                NOTE:
<p>
                The function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_data	- The surface data structure

   Output Arguments:
      p_surf_type	- The surface type
      surf_uv_min	- The surface minimum UV extents
      surf_uv_max	- The surface maximum UV extents
      p_surf_orient	- The surface orientation
      p_surf_shape	- The surface shape
      p_surf_id		- The surface identifier

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfacedataContourArrayGet ( ProSurfacedata *p_surf_data,
						ProContourdata **r_contour_array );
/*
   Purpose:     Retrieves an array of contours on the specified surface.
   
   Input Arguments:
      p_surf_data	- The surface

   Output Arguments:
      r_contour_array   - The <i>ProArray</i> of contours on the surface

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the array of contours.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfacedataContourArraySet ( ProSurfacedata *p_surf_data,
						ProContourdata *contour_array );
/*
   Purpose:     Sets an array of contours on the surface.
   
   Input Arguments:
      p_surf_data	- The surface
      contour_array	- The <i>ProArray</i> of contours on the surface
	
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully set the array of contours.
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

extern ProError ProPlanedataInit ( ProVector	e1,
				   ProVector	e2,
				   ProVector	e3,
				   Pro3dPnt	origin,
				   ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a plane surface data structure.

   Input Arguments:
      e1            - The X-axis of the coordinate system
      e2            - The Y-axis of the coordinate system
      e3            - The Z-axis of the coordinate system
      origin        - The origin of the coordinate system

   Output Arguments:
      p_surf_shape  - The plane surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the plane surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProPlanedataGet ( ProSurfaceshapedata *p_surf_shape,
				  ProVector	e1,
				  ProVector	e2,
				  ProVector	e3,
				  Pro3dPnt	origin );
/*
   Purpose:     Retrieves information from the plane surface data structure.
<p>
                NOTE:
<p>
                The function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape      - The plane surface data structure

   Output Arguments:
      e1     - The X-axis of the coordinate system
      e2     - The Y-axis of the coordinate system
      e3     - The Z-axis of the coordinate system
      origin - The origin of the coordinate system

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProCylinderdataInit ( ProVector	e1,
				      ProVector	e2,
				      ProVector	e3,
				      Pro3dPnt	origin,
				      double		radius,
				      ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a cylinder surface data structure.

   Input Arguments:
      e1      - The X-axis of the coordinate system
      e2      - The Y-axis of the coordinate system
      e3      - The Z-axis of the coordinate system
      origin  - The origin of the coordinate system
      radius  - The radius of the cylinder

   Output Arguments:
      p_surf_shape   - The cylinder surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the cylinder surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProCylinderdataGet ( ProSurfaceshapedata *p_surf_shape,
				     ProVector	e1,
				     ProVector	e2,
				     ProVector	e3,
				     Pro3dPnt	origin,
				     double	*p_radius );
/*
   Purpose:  Retrieves information from the cylinder surface data structure.
<p>
             NOTE:
<p>
             The function ignores the output arguments with NULL pointers.


   Input Arguments:
      p_surf_shape  - The cylinder surface data structure

   Output Arguments:
      e1     - The X-axis of the coordinate system
      e2     - The Y-axis of the coordinate system
      e3     - The Z-axis of the coordinate system
      origin - The origin of the coordinate system
      p_radius - The radius of the cylinder

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProConedataInit ( ProVector	e1,
				  ProVector	e2,
				  ProVector	e3,
				  Pro3dPnt	origin,
				  double	alpha,
				  ProSurfaceshapedata	*p_surf_shape );
/*
   Purpose:     Initializes a cone surface data structure.

   Input Arguments:
      e1      - The X-axis of the coordinate system
      e2      - The Y-axis of the coordinate system
      e3      - The Z-axis of the coordinate system
      origin  - The origin of the coordinate system
      alpha   - The alpha value

   Output Arguments:
      p_surf_shape   - The cone surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the cone surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProConedataGet ( ProSurfaceshapedata *p_surf_shape,
				 ProVector	e1,
				 ProVector	e2,
				 ProVector	e3,
				 Pro3dPnt	origin,
				 double		*p_alpha );
/*
   Purpose:   Retrieves information from the cone surface data structure.
<p> 
              NOTE: 
<p>
              The function ignores the output arguments with NULL pointers.


   Input Arguments:
      p_surf_shape       - The cone surface data structure

   Output Arguments:
      e1      - The X-axis of the coordinate system
      e2      - The Y-axis of the coordinate system
      e3      - The Z-axis of the coordinate system
      origin  - The origin of the coordinate system
      p_alpha - The alpha value

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProTorusdataInit ( ProVector	e1,
				   ProVector	e2,
				   ProVector	e3,
				   Pro3dPnt	origin,
				   double	radius1,
				   double	radius2,
				   ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a torus surface data structure.

   Input Arguments:
      e1       - The X-axis of the coordinate system
      e2       - The Y-axis of the coordinate system
      e3       - The Z-axis of the coordinate system
      origin   - The origin of the coordinate system
      radius1  - The value of the first radius 
      radius2  - The value of the second radius

   Output Arguments:
      p_surf_shape   -  The torus surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the torus surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProTorusdataGet ( ProSurfaceshapedata *p_surf_shape,
				  ProVector	e1,
				  ProVector	e2,
				  ProVector	e3,
				  Pro3dPnt	origin,
				  double	*p_radius1,
				  double	*p_radius2 );
/*
   Purpose:  Retrieves information from the torus surface data structure.
<p>
             NOTE:
<p>
             The function ignores the output arguments with NULL pointers.


   Input Arguments:
      p_surf_shape     - The torus surface data structure

   Output Arguments:
      e1         - The X-axis of the coordinate system
      e2         - The Y-axis of the coordinate system
      e3         - The Z-axis of the coordinate system
      origin     - The origin of the coordinate system
      p_radius1	 - The value of the first radius 
      p_radius2	 - The value of the second radius

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProSrfrevdataInit ( ProVector	e1,
				    ProVector	e2,
				    ProVector	e3,
				    Pro3dPnt	origin,
				    ProCurvedata *p_curve,
				    ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a revolved surface data structure.

   Input Arguments:
      e1        - The X-axis of the coordinate system
      e2        - The Y-axis of the coordinate system
      e3        - The Z-axis of the coordinate system
      origin    - The origin of coordinate system
      p_curve   - The curve data

   Output Arguments:
      p_surf_shape   - The revolved surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the revolved surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_BAD_SRF_CRV - Invalid type of curve.
      PRO_TK_BSPL_MULTI_INNER_KNOTS - The curve is a B-spline with multiple
				      inner knots. 
*/

extern ProError ProSrfrevdataGet ( ProSurfaceshapedata *p_surf_shape,
				   ProVector	e1,
				   ProVector	e2,
				   ProVector	e3,
				   Pro3dPnt	origin,
				   ProCurvedata	*p_curve );
/*
   Purpose:    Retrieves information from the revolved surface data structure.
<p>
               NOTE:
<p>
               The function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape  - The revolved surface data structure

   Output Arguments:
      e1            - The X-axis of the coordinate system
      e2            - The Y-axis of the coordinate system
      e3            - The Z-axis of the coordinate system
      origin        - The origin of the coordinate system
      p_curve       - The curve 

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProTabcyldataInit ( ProVector	e1,
				    ProVector	e2,
				    ProVector	e3,
				    Pro3dPnt	origin,
				    ProCurvedata *p_curve,
				    ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a tabulated cylinder surface data structure.

   Input Arguments:
      e1      - The X-axis of the coordinate system
      e2      - The Y-axis of the coordinate system 
      e3      - The Z-axis of the coordinate system
      origin  - The origin of coordinate system
      p_curve - The curve data

   Output Arguments:
      p_surf_shape - The tabulated cylinder surface

   Return Values:
      PRO_TK_NO_ERROR          - The function successfully initialized the 
                                 tabulated cylinder surface.
      PRO_TK_BAD_INPUTS	       - One or more of the input arguments are 
				 invalid.
      PRO_TK_BAD_SRF_CRV       - Invalid type of curve.
      PRO_TK_BSPL_MULTI_INNER_KNOTS - The curve is a B-spline with multiple
                                      inner knots.
*/

extern ProError ProTabcyldataGet ( ProSurfaceshapedata *p_surf_shape,
				   ProVector	e1,
				   ProVector	e2,
				   ProVector	e3,
				   Pro3dPnt	origin,
				   ProCurvedata	*p_curve );
/*
   Purpose: Retrieves information from a tabulated cylinder surface data structure.
<p>
            NOTE:
<p>
            The function ignores the output arguments with NULL pointers.


   Input Arguments:
      p_surf_shape   - The tabulated cylinder surface data structure

   Output Arguments:
      e1       - The X-axis of the coordinate system
      e2       - The Y-axis of the coordinate system
      e3       - The Z-axis of the coordinate system
      origin   - The origin of the coordinate system
      p_curve  - The curve data

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProRulsrfdataInit ( ProVector	e1,
				    ProVector	e2,
				    ProVector	e3,
				    Pro3dPnt	origin,
				    ProCurvedata *p_curve1,
				    ProCurvedata *p_curve2,
				    ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a ruled surface data structure.

   Input Arguments:
      e1        - The X-axis of the coordinate system
      e2        - The Y-axis of the coordinate system
      e3        - The Z-axis of the coordinate system
      origin    - The origin of the coordinate system
      p_curve1  - The first curve 
      p_curve2  - The second curve

   Output Arguments:
      p_surf_shape  - The ruled surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the ruled surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_BAD_SRF_CRV - Invalid type of curve.
      PRO_TK_BSPL_MULTI_INNER_KNOTS - The curve is a B-spline with multiple
                                      inner knots.
*/

extern ProError ProRulsrfdataGet ( ProSurfaceshapedata *p_surf_shape,
				   ProVector	e1,
				   ProVector	e2,
				   ProVector	e3,
				   Pro3dPnt	origin,
				   ProCurvedata	*p_curve1,
				   ProCurvedata	*p_curve2 );
/*
   Purpose:   Retrieves information from the ruled surface data structure.
<p> 
              NOTE:
<p>
              This function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape   - The ruled surface data structure

   Output Arguments:
      e1        - The X-axis of the coordinate system
      e2        - The Y-axis of the coordinate system
      e3        - The Z-axis of the coordinate system
      origin    - The origin of the coordinate system
      p_curve1  - The first curve 
      p_curve2  - The second curve

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
      PRO_TK_BAD_SRF_CRV - Invalid type of curve.
      PRO_TK_BSPL_MULTIPLE_INNER_KNOTS - The curve is a B-spline with multiple
                                         inner knots.
*/

LIB_PTK_INTF_API  ProError ProSplinesrfdataInit ( double	*u_par_arr,
				       double	*v_par_arr,
				       Pro3dPnt *points_arr,
				       ProVector *u_tan_arr,
				       ProVector *v_tan_arr,
				       ProVector *uvdev_arr,
				       int	num_u,
				       int	num_v,
				       ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:   Initializes a spline surface data structure.

   Input Arguments:
      u_par_arr	   - A <i>ProArray</i> of U parameter grids
      v_par_arr	   - A <i>ProArray</i> of V parameter grids
      points_arr   - A <i>ProArray</i> of interpolant points
      u_tan_arr	   - A <i>ProArray</i> of U derivatives at these points
      v_tan_arr	   - A <i>ProArray</i> of V derivatives at these points
      uvdev_arr	   - A <i>ProArray</i> of UV derivatives at the interpolant 
		     points
      num_u        - The size in U  
      num_v        - The size in V 

   Output Arguments:
      p_surf_shape  - The spline surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the 
			  spline surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProSplinesrfdataGet ( ProSurfaceshapedata *p_surf_shape,
				      double	**p_u_par_arr,
				      double	**p_v_par_arr,
				      Pro3dPnt	**p_points_arr,
				      ProVector **p_u_tan_arr,
				      ProVector **p_v_tan_arr,
				      ProVector **p_uvdev_arr,
		 		      int	*p_num_u,
		  		      int	*p_num_v );
/*
   Purpose:  Retrieves information from the spline surface data structure.
<p>
             NOTE:
<p>
             This function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape - The spline surface data structure

   Output Arguments:
      p_u_par_arr  - The pointer to a <i>ProArray</i> of U parameter grids
      p_v_par_arr  - The pointer to a <i>ProArray</i> of V parameter grids
      p_points_arr - The pointer to a <i>ProArray</i> of interpolant points
      p_u_tan_arr  - The pointer to a <i>ProArray</i> of U derivatives at 
		     these points
      p_v_tan_arr  - The pointer to a <i>ProArray</i> of V derivatives at 
		     these points
      p_uvdev_arr  - The pointer to a <i>ProArray</i> of UV derivatives at 
		     the interpolant points
      p_num_u      - The size in U   
      p_num_v      - The size in V

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProCylsplsrfdataInit ( ProVector	e1,
				       ProVector	e2,
				       ProVector	e3,
				       Pro3dPnt		origin,
				       ProSplinesrfdata *p_splinesrf,
				       ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a cylindrical-spline surface data structure.

   Input Arguments:
      e1           - The X-axis of the coordinate system
      e2           - The Y-axis of the coordinate system
      e3           - The Z-axis of the coordinate system
      origin       - The origin of the coordinate system
      p_splinesrf  - The spline surface

   Output Arguments:
      p_surf_shape   - The cylindrical-spline surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the 
			  cylindrical-spline surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProCylsplsrfdataGet ( ProSurfaceshapedata *p_surf_shape,
				      ProVector		e1,
				      ProVector		e2,
				      ProVector		e3,
				      Pro3dPnt		origin,
				      ProSplinesrfdata	*p_splinesrf );
/*
   Purpose:  Retrieves information from the cylindrical-spline surface data structure.
<p>
             NOTE:
<p>
             This function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape   - The cylindrical-spline surface data structure

   Output Arguments:
      e1          - The X-axis of the coordinate system
      e2          - The Y-axis of the coordinate system
      e3          - The Z-axis of the coordinate system
      origin      - The origin of the coordinate system
      p_splinesrf - The spline surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProBsplinesrfdataInit ( int		deg[2],
					double		*u_par_arr,
					double		*v_par_arr,
					double		*wghts_arr,
					Pro3dPnt	*c_point_arr,
					int		num_u,
					int		num_v,
					int		num_c_point,
					ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes the B-spline surface data structure.

   Input Arguments:
      deg             - The basis function's degrees (in the U and V 
			directions).
      u_par_arr	      - The <i>ProArray</i> of knots on the parameter line, U.
      v_par_arr	      - The <i>ProArray</i> of knots on the parameter line, V.
      wghts_arr	      - In the case of rational B-splines, this is a 
                        <i>ProArray</i> of the same
                        dimension as the array of <i>c_point_arr</i>. 
                        Otherwise, this is NULL.
      c_point_arr     - The <i>ProArray</i> of control points.
      num_u           - The size in U.
      num_v           - The size in V.
      num_c_point     - The number of control points.

   Output Arguments:
      p_surf_shape     - The B-spline surface.

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the 
			  B-spline surface. 
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_BSPL_UNSUITABLE_DEGREE - The degree is greater than effectively
                                      supported maximum (3).
      PRO_TK_BSPL_NON_STD_END_KNOTS - The end knots do not have 
				      <i>degree + 1</i> multiplicity.
      PRO_TK_BSPL_MULTI_INNER_KNOTS - Some of the inner knots are multiple.
*/

LIB_PTK_INTF_API  ProError ProBsplinesrfdataGet ( ProSurfaceshapedata *p_surf_shape,
				       int		deg[2],
				       double		**p_u_par_arr,
				       double		**p_v_par_arr,
				       double		**p_wghts_arr,
				       ProVector 	**p_c_point_arr,
 				       int		*p_num_u,
				       int		*p_num_v,
				       int		*p_num_c_point );
/*
   Purpose:   Retrieves information from the B-spline surface data structure.
<p>
              NOTE: 
<p>
              This function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape     - The B-spline surface data structure.

   Output Arguments:
      deg               - The basis function's degrees (in the U and V 
			  directions).
      p_u_par_arr       - The pointer to a <i>ProArray</i> of knots on the 
			  parameter line, U.
      p_v_par_arr       - The pointer to a <i>ProArray</i> of knots on the 
			  parameter line, V.
      p_wghts_arr       - In the case of rational B-splines, this is the 
			  pointer to a
                          <i>ProArray</i> of the same dimensions as the array of
                          <i>c_point_arr</i>. Otherwise, this is NULL.
      p_c_point_arr     - The <i>ProArray</i> of control points.
      p_num_u           - The size in U.
      p_num_v           - The size in V.
      p_num_c_point     - The number of control points.


   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProFilsrfdataInit ( ProSplinedata *p_pnt_spline,
				    ProSplinedata *p_ctr_spline,
				    ProSplinedata *p_tan_spline,
				    ProSurfaceshapedata *p_surf_shape );
/*
   Purpose:     Initializes a fillet surface data structure.

   Input Arguments:
      p_pnt_spline    - The spline running along the U = 0 boundary
      p_ctr_spline    - The spline running along the "axis"
      p_tan_spline    - The spline of unit tangents along the axis

   Output Arguments:
      p_surf_shape    - The fillet surface

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the fillet surface.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProFilsrfdataGet ( ProSurfaceshapedata *p_surf_shape,
				   ProSplinedata	*p_pnt_spline,
				   ProSplinedata	*p_ctr_spline,
				   ProSplinedata	*p_tan_spline );
/*
   Purpose:  Retrieves information from the fillet surface data structure.
<p>
             NOTES:
<p>
             This function ignores the output arguments with NULL pointers.

   Input Arguments:
      p_surf_shape    - The fillet surface data structure

   Output Arguments:
      p_pnt_spline    - The spline running along the U = 0 boundary
      p_ctr_spline    - The spline running along the "axis"
      p_tan_spline    - The spline of unit tangents along the axis

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

PRO_END_C_DECLS

#endif /* PROSURFACEDATA_H */
