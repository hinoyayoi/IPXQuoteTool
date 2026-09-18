#ifndef PRO2DENTDEF_H
#define PRO2DENTDEF_H

#include <ProObjects.h>
#include <ProSizeConst.h>



PRO_BEGIN_C_DECLS

typedef enum
{
 PRO_2D_POINT         = 1,
 PRO_2D_LINE          = 2,
 PRO_2D_CENTER_LINE   = 3,
 PRO_2D_ARC           = 4,
 PRO_2D_CIRCLE        = 5,
 PRO_2D_COORD_SYS     = 6,
 PRO_2D_POLYLINE      = 7,
 PRO_2D_SPLINE        = 8,
 PRO_2D_TEXT          = 9,
 PRO_2D_CONSTR_CIRCLE = 10,
 PRO_2D_BLEND_VERTEX  = 11,
 PRO_2D_ELLIPSE       = 12,
 PRO_2D_CONIC         = 13,
 PRO_2D_SEC_GROUP     = 14,
 PRO_2D_B_SPLINE      = 15,

 /* Please consult with Creo Parametric TOOLKIT group before adding types. */
 PRO_2D_ENT_LAST      = 16 /* Please update PRO_2D_ENT_LAST when adding to 
                              here */
} Pro2dEntType;

#define PRO_2D_ENT_COUNT PRO_2D_ENT_LAST

typedef enum
{
 PRO_2D_SPLINE_TAN_NONE     = 0,
 PRO_2D_SPLINE_TAN_START    = 1,
 PRO_2D_SPLINE_TAN_END      = 2,
 PRO_2D_SPLINE_TAN_BOTH     = 3,
 PRO_2D_SPLINE_TAN_PERIODIC = 4
} Pro2dSplineTanType;

typedef struct
{
 Pro2dEntType    type;
} Pro2dEntdef;


typedef struct
{
 Pro2dEntType    type;	/* PRO_2D_POINT, PRO_2D_COORD_SYS */
 Pro2dPnt        pnt;
} Pro2dPointdef, Pro2dCoordSysdef;

typedef struct
{
 Pro2dEntType    type;	/* PRO_2D_LINE, PRO_2D_CENTER_LINE */
 Pro2dPnt        end1;
 Pro2dPnt        end2;
} Pro2dLinedef, Pro2dClinedef;
 
typedef struct
{
 Pro2dEntType    type;	/* PRO_2D_ARC */
 Pro2dPnt        center;
 ProAngle        start_angle;
 ProAngle        end_angle;
 double          radius;
} Pro2dArcdef;

typedef struct
{
 Pro2dEntType    type;      /* PRO_2D_CIRCLE */
 Pro2dPnt        center;
 double          radius;
} Pro2dCircledef;

typedef struct
{
 Pro2dEntType     type;      /* PRO_2D_POLYLINE */
 unsigned int     n_points;
 Pro2dPnt        *point_arr;
} Pro2dPolylinedef;


typedef struct
{
 Pro2dEntType           type;           /* PRO_2D_SPLINE */
 Pro2dSplineTanType     tangency_type;
 unsigned int	       	n_points;
 Pro2dPnt	             *point_arr;
 ProAngle               start_tang_angle;
 ProAngle               end_tang_angle;
} Pro2dSplinedef;

typedef struct
{
  Pro2dEntType     type;   /* PRO_2D_TEXT */
  Pro2dPnt         first_corner;
  Pro2dPnt         second_corner;
  ProComment       string;
  ProComment       font_name; /* For Creo Parametric default, leave this field blank */
} Pro2dTextdef;

typedef struct
{
  Pro2dEntType    type;	/* PRO_2D_BLEND_VERTEX */
  Pro2dPnt        pnt;
  int             depth_level; /* The index for a subsequent blend vertex
                                * at the specified point "pnt".
                                * Note: if "pnt" vectors of two or more blend
                                * vertices are not exactly same, they will be
                                * decided to belong to the same point based
                                * on "Same Points" assumption conditions.
                                */
} Pro2dBlendVertexdef;         /* This entity may not be explicitly created.
                                * Please use ProSectionBlendVertexSet() instead.
                                */

typedef struct
{
 Pro2dEntType    type;      /* PRO_2D_ELLIPSE */
 Pro2dPnt        origin;
 double          x_radius;
 double          y_radius;
} Pro2dEllipsedef;

typedef struct
{
 Pro2dEntType    type;      /* PRO_2D_CONIC */
 Pro2dPnt        first_end_point;
 Pro2dPnt        second_end_point;
 Pro2dPnt        shoulder_point; 
 double          parameter;
} Pro2dConicdef;

typedef struct
{
 Pro2dEntType    type;
 Pro2dPnt        att_point;
} Pro2dSecGroupdef;

typedef struct
{
  Pro2dEntType type;          /* PRO_2D_B_SPLINE */
  int          degree;        /* Basis functions degree */
  int          num_knots;     /* The size for the params array */
  double      *params;        /* ProArray of knots on the parameter line */
  int          num_c_points;  /* The size for c_pnts (and weights if not NULL) */
  Pro2dPnt    *c_pnts;        /* ProArray of control points */
  double      *weights;       /* In the case of rational B-splines, a
                                 ProArray of the same dimension as
                                 array of c_pnts. Otherwise == NULL */
} Pro2dBSplinedef;


PRO_END_C_DECLS

#endif
