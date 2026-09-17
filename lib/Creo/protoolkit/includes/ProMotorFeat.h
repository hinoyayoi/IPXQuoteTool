#ifndef PRO_MOTOR_FEAT_H
#define PRO_MOTOR_FEAT_H



#include <ProFeature.h>

PRO_BEGIN_C_DECLS

/******************************************************************************
Feature element tree of motor features

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_MOTOR_MOTION_TYPE
     |
     |--PRO_E_MOTOR_DRIVEN_ENT_REF
     |--PRO_E_MOTOR_REF_ENT
     |
     |--PRO_E_MOTOR_DIR_MODE
     |
     |--PRO_E_MOTOR_VEC_DIR_DATA
     |    |
     |    |--PRO_E_MOTOR_VEC_DIR_CSYS
     |    |--PRO_E_MOTOR_VEC_DIR_X
     |    |--PRO_E_MOTOR_VEC_DIR_Y
     |    |--PRO_E_MOTOR_VEC_DIR_Z
     |
     |--PRO_E_DIRECTION_COMPOUND
     |    |
     |    |--PRO_E_DIRECTION_REFERENCE
     |    |--PRO_E_DIRECTION_FLIP
     |
     |--PRO_E_MOTOR_PT_TO_PT_DIR
     |
     |--PRO_E_MOTOR_DIR_RELATIVITY
     |--PRO_E_MOTOR_FLIP_DIR
     |
     |--PRO_E_MOTOR_PROFILE
          |
          |--PRO_E_MOTOR_DRIVEN_QUANTITY
          |
          |--PRO_E_MOTOR_INIT_STATE_DATA
          |    |
          |    |--PRO_E_MOTOR_USE_CURR_POS
          |    |--PRO_E_MOTOR_INIT_POS
          |    |--PRO_E_MOTOR_INIT_VEL
          |
          |--PRO_E_MOTOR_FUNC_TYPE
          |
          |--PRO_E_MOTOR_FUNC_COEFF_A
          |--PRO_E_MOTOR_FUNC_COEFF_B
          |--PRO_E_MOTOR_FUNC_COEFF_C
          |--PRO_E_MOTOR_FUNC_COEFF_D
          |--PRO_E_MOTOR_FUNC_COEFF_L
          |--PRO_E_MOTOR_FUNC_COEFF_H
          |--PRO_E_MOTOR_FUNC_COEFF_T
          |
          |--PRO_E_MOTOR_TABLE_DATA
          |    |
          |    |--PRO_E_MOTOR_TBL_INTERPOL_TYPE
          |    |--PRO_E_MOTOR_TBL_ROWS
          |    |    |
          |    |    |--PRO_E_MOTOR_TBL_ROW
          |    |         |
          |    |         |--PRO_E_MOTOR_TBL_VAR_VAL
          |    |         |--PRO_E_MOTOR_TBL_FUNC_VAL
          |    |         |--PRO_E_MOTOR_TBL_DERIV_GIVEN
          |    |         |--PRO_E_MOTOR_TBL_DERIV_VAL
          |    |
          |    |--PRO_E_MOTOR_TBL_DEPEND_ON_FILE
          |    |--PRO_E_MOTOR_TBL_FILE_NAME
          |    |--PRO_E_MOTOR_TBL_DEPEND_ON_SERIES
          |    |--PRO_E_MOTOR_TBL_SERIES_NAME
          |
          |--PRO_E_MOTOR_UD_PROFILE_DATA
          |    |
          |    |--PRO_E_MOTOR_UD_EXPR_ARR
          |         |
          |         |--PRO_E_MOTOR_UD_EXPR_DATA
          |              |
          |              |--PRO_E_MOTOR_UD_EXPR
          |              |--PRO_E_MOTOR_UD_DOM_TYPE
          |              |--PRO_E_MOTOR_UD_DOM_LOWER_BOUND
          |              |--PRO_E_MOTOR_UD_DOM_UPPER_BOUND
          |
          |--PRO_E_MOTOR_CUST_LOAD_NAME

Feature elements table

==========================================================================================
Element Id                       | Element description          | Data Type
=================================+==============================+=========================
PRO_E_FEATURE_TYPE               | Feature type                 | PRO_VALUE_TYPE_INT
---------------------------------+------------------------------+-------------------------
PRO_E_STD_FEATURE_NAME           | Feature name                 | PRO_VALUE_TYPE_WSTRING
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_MOTION_TYPE          | Motor motion type (Transla-  | PRO_VALUE_TYPE_INT
                                 | tional, Rotational, Slot)    |
---------------------------------+------------------------------+-------------------------
                                 | Driven entity reference (a   |
PRO_E_MOTOR_DRIVEN_ENT_REF       | connection axis or a geomet- | PRO_VALUE_TYPE_SELECTION
                                 | ric entity(s))               |
---------------------------------+------------------------------+-------------------------
                                 | Motion reference entity for  |
PRO_E_MOTOR_REF_ENT              | geometric driven entity (in  | PRO_VALUE_TYPE_SELECTION
                                 | geometric servo motors only) |
---------------------------------+------------------------------+-------------------------
                                 | Motion direction definition  |
                                 | mode (in geometric force mo- |
PRO_E_MOTOR_DIR_MODE             | tors with non-point-to-point | PRO_VALUE_TYPE_INT
                                 | driven entity); see          |
                                 | ProMotorFMDirMode below      |
---------------------------------+------------------------------+-------------------------
                                 | Compound element containing  |
PRO_E_MOTOR_VEC_DIR_DATA         | data which defines direction | PRO_VALUE_TYPE_POINTER
                                 | by explicit vector (geometric|
                                 | force motors only)           |
---------------------------------+------------------------------+-------------------------
                                 | Reference frame for explicit |
PRO_E_MOTOR_VEC_DIR_CSYS         | vector (optional, will use   | PRO_VALUE_TYPE_SELECTION
                                 | World ref. frame if absent)  |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_VEC_DIR_X            | X component of explicit vec. | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_VEC_DIR_Y            | Y component of explicit vec. | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_VEC_DIR_Z            | Z component of explicit vec. | PRO_VALUE_TYPE_DOUBLE
---------------------------------+------------------------------+-------------------------
                                 | Compound element holding the |
                                 | "standard" direction defini- |
PRO_E_DIRECTION_COMPOUND         | tion by straight line/plane  | PRO_VALUE_TYPE_POINTER
                                 | normal (in geometric servo or|
                                 | force motors)                |
---------------------------------+------------------------------+-------------------------
PRO_E_DIRECTION_REFERENCE        | Direction reference          | PRO_VALUE_TYPE_SELECT
---------------------------------+------------------------------+-------------------------
PRO_E_DIRECTION_FLIP             | Direction flip flag          | PRO_VALUE_TYPE_INT
---------------------------------+------------------------------+-------------------------
                                 | A pair of point selections   |
PRO_E_MOTOR_PT_TO_PT_DIR         | defining a point-to-point mo-| PRO_VALUE_TYPE_SELECT
                                 | tion direction (in geometric |
                                 | force motors)                |
---------------------------------+------------------------------+-------------------------
                                 | Relativity of defined motion |
PRO_E_MOTOR_DIR_RELATIVITY       | direction in non-point-to-po-| PRO_VALUE_TYPE_INT
                                 | int geometric force motors   |
                                 | (to Ground or to moved body) |
---------------------------------+------------------------------+-------------------------
                                 | Motion direction flip flag   |
PRO_E_MOTOR_FLIP_DIR             | (in connection axis motors or| PRO_VALUE_TYPE_INT
                                 | geometric motors not using   |
                                 | PRO_E_DIRECTION_COMPOUND)    |
---------------------------------+------------------------------+-------------------------
                                 | Compound element holding all |
                                 | the data pertaining to the   |
PRO_E_MOTOR_PROFILE              | motor feature's profile (ty- | PRO_VALUE_TYPE_POINTER
                                 | pe of driven quantity and its|
                                 | function versus time or mea- |
                                 | sure values)                 |
---------------------------------+------------------------------+-------------------------
                                 | Driven quantity type (positi-|
PRO_E_MOTOR_DRIVEN_QUANTITY      | on, velocity, acceleration or| PRO_VALUE_TYPE_INT
                                 | force; the first three define|
                                 | a servo motor)               | 
---------------------------------+------------------------------+-------------------------
                                 | Compound element holding the |
PRO_E_MOTOR_INIT_STATE_DATA      | initial state information (in| PRO_VALUE_TYPE_POINTER
                                 | velocity/acceleration servo  |
                                 | motors only)                 |
---------------------------------+------------------------------+-------------------------
                                 | Use current position of dri- |
PRO_E_MOTOR_USE_CURR_POS         | ven entity as initial (Yes or| PRO_VALUE_TYPE_INT
                                 | No; default is Yes)          |
---------------------------------+------------------------------+-------------------------
                                 | Initial position of driven   |
PRO_E_MOTOR_INIT_POS             | entity (used only when       | PRO_VALUE_TYPE_DOUBLE
                                 | PRO_E_MOTOR_USE_CURR_POS is  |
                                 | set to No")                  |
---------------------------------+------------------------------+-------------------------
                                 | Initial velocity of driven   |
PRO_E_MOTOR_INIT_VEL             | entity (in acceleration servo| PRO_VALUE_TYPE_DOUBLE
                                 | motors only)                 |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_FUNC_TYPE            | Profile function type (see   | PRO_VALUE_TYPE_INT
                                 | ProMotorFuncType below)      |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_FUNC_COEFF_A         | Function coefficient "A"     | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_FUNC_COEFF_B         | Function coefficient "B"     | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_FUNC_COEFF_C         | Function coefficient "C"     | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_FUNC_COEFF_D         | Function coefficient "D"     | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_FUNC_COEFF_L         | Function coefficient "L"     | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_FUNC_COEFF_H         | Function coefficient "H"     | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_FUNC_COEFF_T         | Function coefficient "T"     | PRO_VALUE_TYPE_DOUBLE
---------------------------------+------------------------------+-------------------------
                                 | Compound element holding all |
PRO_E_MOTOR_TABLE_DATA           | the information for table-   | PRO_VALUE_TYPE_POINTER
                                 | based profiles               |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_TBL_INTERPOL_TYPE    | Table interpolation type (li-| PRO_VALUE_TYPE_INT
                                 | near, spline or monotonic)   |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_TBL_ROWS             | Array element for table rows | PRO_VALUE_TYPE_POINTER
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_TBL_ROW              | Individual table row compound| PRO_VALUE_TYPE_POINTER
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_TBL_VAR_VAL          | Variable value in table row  | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_TBL_FUNC_VAL         | Function value in table row  | PRO_VALUE_TYPE_DOUBLE
---------------------------------+------------------------------+-------------------------
                                 | Flag indicating whether the  |
PRO_E_MOTOR_TBL_DERIV_GIVEN      | derivative value in table row| PRO_VALUE_TYPE_INT
                                 | is specified by the user (in |
                                 | monotonic interpolation only)|
---------------------------------+------------------------------+-------------------------
                                 | Function derivative value in |
PRO_E_MOTOR_TBL_DERIV_VAL        | table row (user-specified or | PRO_VALUE_TYPE_DOUBLE
                                 | auto-calculated; in monotonic|
                                 | interpolation only)          |
---------------------------------+------------------------------+-------------------------
                                 | Flag specifying whether the  |
PRO_E_MOTOR_TBL_DEPEND_ON_FILE   | table contents completely    | PRO_VALUE_TYPE_INT
                                 | depend on an external file   |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_TBL_FILE_NAME        | Table file name              | PRO_VALUE_TYPE_WSTRING
---------------------------------+------------------------------+-------------------------
                                 | Flag specifying whether the  |
PRO_E_MOTOR_TBL_DEPEND_ON_SERIES | table contents completely    | PRO_VALUE_TYPE_INT
                                 | depend on a Time Series      |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_TBL_SERIES_NAME      | Time Series name             | PRO_VALUE_TYPE_WSTRING
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_UD_PROFILE_DATA      | Compound element holding the | PRO_VALUE_TYPE_POINTER
                                 | data for User Defined profile|
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_UD_EXPR_ARR          | Array element holding set of | PRO_VALUE_TYPE_POINTER
                                 | user-defined expressions     |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_UD_EXPR_DATA         | Compound element with infor- | PRO_VALUE_TYPE_POINTER
                                 | mation about a single UD expr|
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_UD_EXPR              | Single UD expression string  | PRO_VALUE_TYPE_WSTRING
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_UD_DOM_TYPE          | UD expr. domain type (see    | PRO_VALUE_TYPE_INT
                                 | ProMotorUDExprDomainType)    |
---------------------------------+------------------------------+-------------------------
PRO_E_MOTOR_UD_DOM_LOWER_BOUND   | Lower limit of expr. domain  | PRO_VALUE_TYPE_DOUBLE
PRO_E_MOTOR_UD_DOM_UPPER_BOUND   | Upper limit of expr. domain  | PRO_VALUE_TYPE_DOUBLE
---------------------------------+------------------------------+-------------------------
                                 | Name of custom load used to  |
PRO_E_MOTOR_CUST_LOAD_NAME       | specify the profile function | PRO_VALUE_TYPE_WSTRING
                                 | (in custom load force motors |
                                 | only)                        |
------------------------------------------------------------------------------------------
*******************************************************************************/

typedef enum pro_motor_motion_type
{
   PRO_MOTOR_TRANSLATIONAL = 0,
   PRO_MOTOR_ROTATIONAL    = 1,
   PRO_MOTOR_SLOT          = 2
} ProMotorMotionType;

typedef enum pro_motor_driven_quantity
{
   PRO_MOTOR_POSITION     = 0,
   PRO_MOTOR_VELOCITY     = 1,
   PRO_MOTOR_ACCELERATION = 2,
   PRO_MOTOR_FORCE        = 3
} ProMotorDrivenQuantity;

/* direction definition mode for force motors with non-joint-axis,
   non-point-to-point driven entities */
typedef enum pro_motor_fm_dir_mode
{
   PRO_MOTOR_FM_VEC_DIR     = 0, /* defined by explicit vector in a coordinate
                                    system */
   PRO_MOTOR_FM_STD_DIR     = 1, /* defined by standard direction reference
                                    (straight edge/curve/axis, plane normal) */
   PRO_MOTOR_FM_P2P_DIR     = 2  /* defined by a pair of point/vertex
                                    selections */
} ProMotorFMDirMode;

typedef enum pro_motor_func_type
{
   PRO_MOTOR_CONSTANT     = 0, /* constant */
   PRO_MOTOR_RAMP         = 1, /* linear ("ramp") */
   PRO_MOTOR_COSINE       = 2, /* cosine */
   PRO_MOTOR_SCCA         = 3, /* Sine Constant Cosine Acceleration (for
                                  acceleration servo motors only) */
   PRO_MOTOR_CYCLOIDAL    = 4, /* cycloidal */
   PRO_MOTOR_PARABOLIC    = 5, /* quadratic ("parabolic") */
   PRO_MOTOR_POLYNOMIAL   = 6, /* polynomial (up to 3rd degree) */
   PRO_MOTOR_TABLE        = 7, /* function defined by interpolated table */
   PRO_MOTOR_USER_DEFINED = 8, /* function defined by user-supplied set of
                                  expressions */
   PRO_MOTOR_CUSTOM_LOAD  = 9  /* function defined by named custom load */
} ProMotorFuncType;

typedef enum pro_motor_table_interp_type
{
   PRO_MOTOR_TBL_LINEAR    = 0,
   PRO_MOTOR_TBL_SPLINE    = 1,
   PRO_MOTOR_TBL_MONOTONIC = 2
} ProMotorTableInterpType;

/*
   Domain (interval) types for user-defined expressions:
   (1) Abbreviations:
       OPN = Open (for a finite lower/upper bound)
       CLS = Closed (for a finite lower/upper bound)
       INFIN = Infinity (for infinite upper bound)
   (2) PRO_MOTOR_DOM_INFINITE (the whole real number axis) can be used only
       when the user-defined profile function consists of a single expression.
   (3) PRO_MOTOR_DOM_OPN_TO_INFIN and PRO_MOTOR_DOM_CLS_TO_INFIN can be used
       only in the last expression segment of any user-defined profile.
       
*/
typedef enum pro_motor_ud_expr_domain_type
{
   PRO_MOTOR_DOM_INFINITE     = 0, /* (-infinity, +infinity)     */
   PRO_MOTOR_DOM_OPN_TO_OPN   = 1, /* (lower_bound, upper_bound) */
   PRO_MOTOR_DOM_CLS_TO_OPN   = 2, /* [lower_bound, upper_bound) */
   PRO_MOTOR_DOM_OPN_TO_CLS   = 3, /* (lower_bound, upper_bound] */
   PRO_MOTOR_DOM_CLS_TO_CLS   = 4, /* [lower_bound, upper_bound] */
   PRO_MOTOR_DOM_OPN_TO_INFIN = 5, /* (lower_bound, +infinity)   */
   PRO_MOTOR_DOM_CLS_TO_INFIN = 6  /* [lower_bound, +infinity)   */
} ProMotorUDExprDomainType;

PRO_END_C_DECLS

#endif /* PRO_MOTOR_FEAT_H */
