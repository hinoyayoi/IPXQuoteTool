

#ifndef PROTOOLKIT_DIMENSION_TYPES
#define PROTOOLKIT_DIMENSION_TYPES

/* point types for specifying in dimension creation function */
typedef enum
{
  PRO_ENT_WHOLE           = 1,
  PRO_ENT_START           = 2,
  PRO_ENT_END             = 3,
  PRO_ENT_CENTER          = 4,
  PRO_ENT_LEFT_TANGENT    = 5,
  PRO_ENT_RIGHT_TANGENT   = 6,
  PRO_ENT_TOP_TANGENT     = 7,
  PRO_ENT_BOTTOM_TANGENT  = 8
}
ProSectionPointType;


typedef enum
{
  PRO_TK_DIM_TYPE_UNKNOWN       = -1, /* a trap for errors */
  PRO_TK_DIM_NONE               = 0, /* a place saver */
  PRO_TK_DIM_LINE               = 1, /* length of a line */
  PRO_TK_DIM_LINE_POINT 	= 2, /* distance between a line and a vertex  */
  PRO_TK_DIM_RAD 		= 3, /* radius of an arc or a circle */
  PRO_TK_DIM_DIA                = 4, /* diameter of an arc or a circle */
  PRO_TK_DIM_LINE_LINE          = 5, /* distance between two lines */
  PRO_TK_DIM_PNT_PNT            = 6, /* distance between two points */
  PRO_TK_DIM_PNT_PNT_HORIZ      = 7, /* distance between two points (x
				   coords) */
  PRO_TK_DIM_PNT_PNT_VERT       = 8, /* distance between two points (y
				   coords) */
  PRO_TK_DIM_AOC_AOC_TAN_HORIZ  = 9, /* horizontal distance between
					   two arcs/cir */
  PRO_TK_DIM_AOC_AOC_TAN_VERT   = 10,/* horizontal distance between
					   two arcs/cir */
  PRO_TK_DIM_ARC_ANGLE          = 11,
  PRO_TK_DIM_LINES_ANGLE        = 12,
  PRO_TK_DIM_LINE_AOC           = 13,
  PRO_TK_DIM_LINE_CURVE_ANGLE   = 14,
  PRO_TK_DIM_CONIC_PARAM        = 15, /* 0.05 < ellipse < 0.5; parabola = 0.5;
                                         0.5 < hyperbola < 0.95 */
  PRO_TK_DIM_EXT_APP            = 16,
  PRO_TK_DIM_LIN_MULTI_OFFSET = 17,
  PRO_TK_DIM_PNT_OFFSET       = 18,
  PRO_TK_DIM_ELLIPSE_X_RADIUS = 19,
  PRO_TK_DIM_ELLIPSE_Y_RADIUS = 20,
  PRO_TK_DIM_3_PNT_ANGLE      = 21, /* angular dimension defined by 3 points */
  PRO_TK_DIM_DIA_LINEAR       = 22, /* linear diameter dimension */
  PRO_TK_DIM_PNT_PNT_ORI      = 23, /* distance between two points 
                                       in specified orientation */
  PRO_TK_DIM_AOC_AOC_ORI      = 24, /* distance between two arcs/circles 
                                       in specified orientation */
  PRO_TK_DIM_TOT_INC_ANG      = 25, /* total included angle */
  PRO_TK_DIM_ANG_POLAR        = 26  /* dimension measuring angle between a x axis and vector defined by two points */
}               ProSecdimType;

#endif


