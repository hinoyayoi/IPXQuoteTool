#ifndef PROCURVEDATA_H
#define PROCURVEDATA_H

#include   <ProObjects.h>

/*
   Function declarations and specific data structures for ProCurvedata
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef enum
{
        PRO_CURVE_NO_FLIP = 0,
        PRO_CURVE_FLIP
} ProCurveDir;

typedef struct ptc_point 
{
    int      type;
    Pro3dPnt position;
} ProPointdata;

typedef struct ptc_line
{
    int type;
    Pro3dPnt  end1;
    Pro3dPnt  end2;
} ProLinedata;

typedef struct ptc_arrow
{
    int       type;
    Pro3dPnt  end1;
    Pro3dPnt  end2;
} ProArrowdata;

typedef struct ptc_arc
{
    int        type;
    ProVector  vector1;        /* First vector of the arc coordinate system*/
    ProVector  vector2;        /* Second vector of the arc coordinate system*/
    Pro3dPnt   origin;         /* Center of the arc coordinate system */
    double     start_angle;    /* Starting angle (in radians) of the arc */
    double     end_angle;      /* End angle (in radians) of the arc */
    double     radius;         /* Radius of the arc */
} ProArcdata;

typedef struct ptc_spline
{
    int         type;
    double     *par_arr;        /* ProArray of spline parameters */
    ProPoint3d *pnt_arr;        /* ProArray of spline interpolant points */
    ProPoint3d *tan_arr;        /* ProArray of tangent vectors at each point */
    int         num_points;     /* Size for all the arrays */
} ProSplinedata;

typedef struct ptc_b_spline
{
    int          type;
    int          degree;        /* Basis functions degree */
    double      *params;        /* ProArray of knots on the parameter line */
    double      *weights;       /* In the case of rational B-splines, a
                                   ProArray of the same dimension as
                                   array of c_pnts. Otherwise == NULL */
    ProPoint3d  *c_pnts;        /* ProArray of control points */
    int          num_knots;     /* The size for the params array */
    int          num_c_points;  /* The size for c_pnts (and weights if not 
                                   NULL) */
} ProBsplinedata;      

typedef struct ptc_circle
{
    int        type;
    ProPoint3d center;
    ProPoint3d norm_axis_unit_vect;
    double     radius;
} ProCircledata;

/* Ellipse parametric equation in the local coordinates is:
   x = x_radius * cos(phi)
   y = y_radius * sin(phi)
where "phi" is "angular parameter" */

typedef struct ptc_ellipse 
{
   int        type;
   Pro3dPnt   center;               /* Center of ellipse. */
   ProVector  major_axis_unit_vect; /* This is the first (x) axis vector of the ellipse.*/
   ProVector  norm_axis_unit_vect;  /* This is the normal to the ellipse plane.*/
   double     major_len;            /* This is the radius in the direction of major_axis_unit_vect */
                                    /* (that is, the x-radius of the ellipse). */
   double     minor_len;            /* This is the radius of the ellipse in the direction of */
                                    /* the other (y) axis.*/
   double     start_ang;            /* Starting angular parameter (in radians) of ellipse.*/
   double     end_ang;              /* End angular parameter (in radians) of ellipse. */
} ProEllipsedata;

/*
The other (y) axis can be found as a vector product of norm_axis_unit_vect on major_axis_unit_vect.
In actual examples major_len can be less than minor_len. 
*/

typedef struct ptc_polygon 
{
    int         type;
    int         fill_color;
    ProPoint3d *vertices;
    int         num_vertices;
} ProPolygondata;

typedef struct ptc_text 
{
    int          type;
    ProPath      text_line;
    ProPoint3d   location;
    double       angle;
    int          attributes;
    ProName      font_name;
    double       height;
    double       width_factor;
    double       slant_angle;
    double       thickness;
} ProTextdata;

typedef struct ptc_composite_curve 
{
    int          type;
    struct ptc_component_curve *component_arr; /* ProArray of components */
} ProCompositeCurvedata;

typedef struct ptc_surface_curve
{
    int              type;
    ProSurface       surface;
    union ptc_curve  *curve;	/* 3d shapes such as lines, splines, etc are	*/
				/* interpreted as 2d functions of U and V in	*/
				/* the surface					*/
} ProSurfcurvedata;

typedef union ptc_curve
{
    ProLinedata         	line;
    ProArrowdata        	arrow;
    ProArcdata          	arc;
    ProSplinedata       	spline;
    ProBsplinedata      	b_spline;
    ProCircledata       	circle;
    ProEllipsedata      	ellipse;
    ProPointdata        	point;
    ProPolygondata      	polygon;
    ProTextdata         	text;
    ProCompositeCurvedata	comp_curve;
    ProSurfcurvedata		surf_curve;
} ProCurvedata;

typedef struct ptc_component_curve 
{
    ProCurvedata	curve;
    ProCurveDir		direction;
} ProComponentCurvedata;

LIB_PTK_INTF_API  ProError ProCurvedataAlloc ( ProCurvedata **pp_curve );
/*
   Purpose:     Allocates memory for a curve data structure.

   Input Arguments:
      none

   Output Arguments:
      pp_curve		- The curve data structure

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated memory for the
                             curve data structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - The input is invalid.
*/

LIB_PTK_INTF_API  ProError ProCurvedataFree ( ProCurvedata *p_curve );
/*
   Purpose: Frees the underlying memory of the specified curve data structure.
   
   Input Arguments:
      p_curve		- The curve data structure

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProCurvedataMemoryFree ( ProCurvedata *p_curve );

/*
   Purpose:     Frees the top-level memory used by the specified 
                curve data structure.

   Input Arguments:
      p_curve		- The curve data structure

  Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProCurvedataTypeGet ( ProCurvedata *p_curve,
				      ProEnttype *p_curve_type );
/*
   Purpose:     Gets the curve type.
   
   Input Arguments:
      p_curve		- The curve data structure

   Output Arguments:
      p_curve_type	- The curve type

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the
                          information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProPointdataInit ( Pro3dPnt position, ProCurvedata *p_curve );
/*
   Purpose:     Initializes a point data structure.

   Input Arguments:
      position		- The point position

   Output Arguments:
      p_curve		- The point data structure

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the point 
                          data structure.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProPointdataGet ( ProCurvedata *p_curve, Pro3dPnt position );
/*
   Purpose: Retrieves information from the point data structure.

   Input Arguments:
      p_curve	 - The point data structure

   Output Arguments:
      position	 - The point position

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully retrieved the 
                            information. 
      PRO_TK_INVALID_TYPE - The specified data is not a point data structure.
      PRO_TK_BAD_INPUTS	  - The input argument is invalid.
*/

extern ProError ProLinedataInit ( Pro3dPnt      end1,
                                  Pro3dPnt      end2,
                                  ProCurvedata *p_curve );
/*
   Purpose:     Initializes a line data structure.

   Input Arguments:
      end1     - The beginning of the line
      end2     - The end of the line   

   Output Arguments:
      p_curve  - The line data structure

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully initialized the line 
                            data structure.
      PRO_TK_BAD_INPUTS	  - One or more of the input arguments are invalid.
*/

extern ProError ProLinedataGet ( ProCurvedata *p_curve,
	                   	 Pro3dPnt	end1,
                   		 Pro3dPnt	end2 );
/*
   Purpose:     Retrieves information from the line data structure.
                <p>
                NOTE:
                <p>
                The function ignores the output arguments with null pointers.
 
   Input Arguments:
      p_curve	- The line data structure

   Output Arguments:
      end1 - The beginning of the line
      end2 - The end of the line 

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully retrieved the 
                            information.
      PRO_TK_INVALID_TYPE - The specified data is not a line data structure.
      PRO_TK_BAD_INPUTS	  - The input argument is invalid.
*/

extern ProError ProArcdataInit ( ProVector	vector1,
	                 	 ProVector	vector2,
				 Pro3dPnt	origin,
				 double		start_angle,
				 double		end_angle,
				 double		radius,
				 ProCurvedata *p_curve );
/*
   Purpose:     Initializes an arc data structure.

   Input Arguments:
      vector1      - The first vector of the arc coordinate system
      vector2      - The second vector of the arc coordinate system
      origin       - The center of the arc coordinate system
      start_angle  - The starting angle (in radians) of the arc
      end_angle	   - The end angle (in radians) of the arc
      radius       - The radius of the arc

   Output Arguments:
      p_curve      - The arc data structure

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully initialized the arc 
                            data structure.
      PRO_TK_BAD_INPUTS	  - One or more of the input arguments are invalid.
*/

extern ProError ProArcdataGet ( ProCurvedata *p_curve,
				ProVector	vector1,
				ProVector	vector2,
				Pro3dPnt	origin,
				double		*p_start_angle,
				double		*p_end_angle,
				double		*p_radius );
/*
   Purpose:  Retrieves information from the arc data structure.
             <p>
             NOTE:
             <p>
             The function ignores the output arguments with null pointers.

   Input Arguments:
      p_curve           - The arc data structure

   Output Arguments:
      vector1		- The first vector of the arc coordinate system
      vector2		- The second vector of the arc coordinate system
      origin		- The center of the arc coordinate system
      p_start_angle	- The starting angle (in radians) of the arc
      p_end_angle	- The end angle (in radians) of the arc
      p_radius		- The radius of the arc

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully retrieved the
                            information.
      PRO_TK_INVALID_TYPE - The specified data is not an arc data structure.
      PRO_TK_BAD_INPUTS	  - The input argument is invalid.
*/

extern ProError ProEllipsedataInit ( Pro3dPnt	center,
				     ProVector	x_axis,
				     ProVector	plane_normal,
				     double	x_radius,
				     double	y_radius,
                                     double     start_ang,
                                     double     end_ang,
                                     ProCurvedata *p_curve );
/*
   Purpose:     Initializes an ellipse data structure.

   Input Arguments:
      center	   - The center of the ellipse
      x_axis       - First (x) axis vector of the ellipse
      plane_normal - The axis vector which is normal to the plane of ellipse
      x_radius     - The radius of the ellipse in the direction of 'x' axis
      y_radius     - The radius of the ellipse in the direction of 'y' axis
      start_ang    - The starting angular parameter (in radians) of the ellipse
      end_ang      - The end angular parameter (in radians) of the ellipse

      (The 'y' axis can found as a vector product of plane_normal on x_axis.)

   Output Arguments:
      p_curve      - The ellipse data structure

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully initialized the ellipse
                            data structure.
      PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
*/

extern ProError ProEllipsedataGet ( ProCurvedata *p_curve,
				    Pro3dPnt    center,
                                    ProVector   x_axis,
                                    ProVector   plane_normal,
                                    double      *p_x_radius,
                                    double      *p_y_radius,
                                    double      *p_start_ang,
                                    double      *p_end_ang );
/*
   Purpose:  Retrieves information from the ellipse data structure.
             <p>
             NOTE:
             <p>  
             The function ignores the output arguments with null pointers.

   Input Arguments:
      p_curve         - The ellipse data structure

   Output Arguments:
      center	     - The center of the ellipse
      x_axis         - First (x) axis vector of the ellipse
      plane_normal   - The axis vector which is normal to the plane of ellipse
      p_x_radius     - The radius of the ellipse in the direction of 'x_axis'
      p_y_radius     - The radius of the ellipse in the direction of 'y_axis'
      p_start_ang    - The starting angular parameter (in radians) of the ellipse
      p_end_ang	     - The end angular parameter (in radians) of the ellipse

      (The 'y' axis can found as a vector product of plane_normal on x_axis.)

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the
                            information.
      PRO_TK_INVALID_TYPE - The specified data is not an ellipse data structure.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProSplinedataInit ( double	*par_arr,
				    ProPoint3d	*pnt_arr,
				    ProPoint3d	*tan_arr,
				    int		num_points,
				    ProCurvedata *p_curve );

/*
   Purpose:     Initializes a spline data structure.

   Input Arguments:
      par_arr     - A <i>ProArray</i> of spline parameters
      pnt_arr     - A <i>ProArray</i> of spline interpolant points
      tan_arr     - A <i>ProArray</i> of tangent vectors at each point
      num_points  - The size for all the arrays

   Output Arguments:
      p_curve     - The spline data structure

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully initialized the spline 
                            data structure.
      PRO_TK_BAD_INPUTS	  - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProSplinedataGet ( ProCurvedata *p_curve,
				   double	**p_par_arr,
				   ProPoint3d	**p_pnt_arr,
				   ProPoint3d	**p_tan_arr,
				   int		*p_num_points );
/*
   Purpose:  Retrieves information from the spline data structure.
             <p>
             NOTE:
             <p>
             The function ignores the output arguments with null
             pointers.

   Input Arguments:
      p_curve      - The spline data structure

   Output Arguments:
      p_par_arr	   - The pointer to a <i>ProArray</i> of spline parameters.
                     Free this output using ProArrayFree().  
      p_pnt_arr	   - The pointer to a <i>ProArray</i> of spline interpolant 
                     points. Free this output using ProArrayFree().
      p_tan_arr	   - The pointer to a <i>ProArray</i> of tangent vectors 
                     at each point. Free this output using ProArrayFree().
      p_num_points - The size for all the arrays

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully retrieved the
                            information. 
      PRO_TK_INVALID_TYPE - The specified data is not a spline data structure.
      PRO_TK_BAD_INPUTS	  - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProBsplinedataInit ( int		degree,
				     double		*params,
				     double		*weights,
				     ProPoint3d		*c_pnts,
				     int		num_knots,
				     int		num_c_points,
				     ProCurvedata *p_curve );

/*
   Purpose:     Initializes a B-spline data structure.

   Input Arguments:
      degree       - The basis function's degree.
      params       - The <i>ProArray</i> of knots on the parameter line.
      weights      - In the case of rational B-splines, this is a 
                     <i>ProArray</i> of the same dimension as the
                     array of <i>c_pnts</i>. Otherwise, this is NULL.
      c_pnts       - The <i>ProArray</i> of knots on control points.
      num_knots	   - The size of the <i>params</i> array.
      num_c_points - The size of the <i>c_pnts</i> (and <i>weights</i>,
                     if not NULL).

   Output Arguments:
      p_curve      - The B-spline data structure.

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized 
			  the B-spline data structure. 
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_BSPL_UNSUITABLE_DEGREE - The degree is greater than the effectively
				      supported maximum (3).
      PRO_TK_BSPL_NON_STD_END_KNOTS - The end knots do not have 
				      <i>degree + 1</i> multiplicity.
*/

LIB_PTK_INTF_API  ProError ProBsplinedataGet ( ProCurvedata *p_curve,
				    int		*p_degree,
		   		    double	**p_params,
				    double	**p_weights,
				    ProPoint3d	**p_c_pnts,
				    int		*p_num_knots,
				    int		*p_num_c_points );
/*
   Purpose:    Retrieves information from a B-spline data structure.
               <p>
               NOTE:
               <p>
               The function ignores the output arguments with null
               pointers.

   Input Arguments:
      p_curve	- The B-spline data structure.

   Output Arguments:
      p_degree	- The basis function's degree.
      p_params	- The pointer to a <i>ProArray</i> of knots on the 
                  parameter line. Free this output using ProArrayFree(). 
      p_weights	- In the case of rational B-splines, this is the pointer 
                  to a <i>ProArray</i> of the same dimension as the
                  array of <i>c_pnts</i>. Otherwise, this is NULL. 
                  Free this output using ProArrayFree(). 
      p_c_pnts	      - The pointer to a <i>ProArray</i> of knots on 
                        control points. Free this output using ProArrayFree().
      p_num_knots     - The size of the <i>params</i> array.
      p_num_c_points  - The size of <i>c_pnts</i> (and <i>weights</i>, 
                        if not NULL).

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully retrieved the 
                            information. 
      PRO_TK_INVALID_TYPE - The specified data is not a B-spline data structure.
      PRO_TK_BAD_INPUTS	  - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProCompositeCurvedataInit ( 
				    ProComponentCurvedata *component_arr,
				    ProCurvedata          *p_curve );
/*
   Purpose:     Initializes a composite curve data structure.

   Input Arguments:
      component_arr - The <i>ProArray</i> of components

   Output Arguments:
      p_curve	    -  The composite curve data structure

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the composite 
                          curve data structure.
      PRO_TK_BAD_INPUTS	- The input argument is invalid. 
*/

LIB_PTK_INTF_API  ProError ProCompositeCurvedataGet ( 
				      ProCurvedata *p_curve,
				      ProComponentCurvedata **p_component_arr);
/*
   Purpose:  Retrieves information from the composite curve data structure.

   Input Arguments:
      p_curve   - The composite curve data structure

   Output Arguments:
      p_component_arr	- The pointer to a <i>ProArray</i> of components

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully retrieved the 
                            information. 
      PRO_TK_INVALID_TYPE - The specified data is not a composite curve 
                            data structure.
      PRO_TK_BAD_INPUTS	  - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProComponentCurvedataAlloc ( ProComponentCurvedata **pp_component );
/*
   Purpose:     Allocates memory for a component of a composite curve.

   Input Arguments:
      none

   Output Arguments:
      pp_component  - The component of a composite curve

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated the memory.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - The input was invalid. 
*/

LIB_PTK_INTF_API  ProError ProComponentCurvedataFree ( ProComponentCurvedata *p_component );
/*
   Purpose:     Frees the memory of a component of a composite curve.
   
   Input Arguments:
      p_component  - The component of a composite curve

  Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProComponentCurvedataInit (ProCurvedata          *p_curve,
                                           ProCurveDir            direction,
                                           ProComponentCurvedata *p_component);
/*
   Purpose:     Initializes a component of a composite curve data structure.

   Input Arguments:
      p_curve	- The component curve data structure
      direction	- The direction of the component

   Output Arguments:
      p_component - The component of the composite curve

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the component. 
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
*/

extern ProError ProComponentCurvedataGet ( ProComponentCurvedata *p_component,
					   ProCurvedata	*p_curve,
					   ProCurveDir	*p_direction );
/*
   Purpose:  Retrieves information from a component of a composite curve.
             <p>
             NOTE:
             <p>
             The function ignores the output arguments with null
             pointers.

   Input Arguments:
      p_component   - The component of the composite curve

   Output Arguments:
      p_curve	   - The component curve
      p_direction  - The direction of the component

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the
                          information. 
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfcurvedataInit ( ProSurface surface,
				       ProCurvedata *p_surfcurve,
                                       ProCurvedata *p_curve );

/*
   Purpose:     Initializes a surface curve data structure.

   Input Arguments:
      surface     - The surface onto which the curve fits.
      p_surfcurve - Pointer to the curve contained in the surface
			curve.

   Output Arguments:
      
      p_curve     - The resulting curve data structure

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully initialized the
                            data structure.
      PRO_TK_INVALID_TYPE - The specified curve type is not supported
      PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProSurfcurvedataGet ( ProCurvedata     *p_curve,
				      ProSurface       *p_surface,
				      ProCurvedata    **p_surfcurve);
/*
   Purpose:  Retrieves information from the surface curve data structure.
             <p>
             NOTE:
             <p>
             The function ignores the output arguments with null
             pointers.

   Input Arguments:
      p_curve      - The curve data structure that contains the surface
				curve

   Output Arguments:
      p_surface    - The surface
      p_surfcurve  - The UV curve geometry.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the
                            information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

PRO_END_C_DECLS

#endif /* PROCURVEDATA_H */

