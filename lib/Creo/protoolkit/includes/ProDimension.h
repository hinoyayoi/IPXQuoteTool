/* PRODIMENSION.H */

#ifndef PRODIMENSION_H
#define PRODIMENSION_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProView.h>
#include <ProSelection.h>
#include <ProAnnotationElem.h>
#include <ProPoint.h> /* For ProPointType (dimension sense) */
#include <ProGtol.h> /* For ProLeaderType */



PRO_BEGIN_C_DECLS

typedef struct dim_location* ProDimlocation;

typedef enum 
{
  

  PROTOLTABLE_NONE = 0,
  PROTOLTABLE_GENERAL = 1,
  PROTOLTABLE_BROKEN_EDGE = 2,
  PROTOLTABLE_SHAFTS = 3,
  PROTOLTABLE_HOLES = 4
} ProToleranceTable;

typedef enum pro_dim_bound
{
  

  PRODIMBOUND_NOMINAL = 20, 
  PRODIMBOUND_UPPER = 21,
  PRODIMBOUND_LOWER = 22,
  PRODIMBOUND_MIDDLE = 24

} ProDimbound;

typedef enum pro_dim_sense_type
{
  PRO_DIM_SNS_TYP_NONE =	0,

  /* used to specify point type */
  PRO_DIM_SNS_TYP_PNT, 
					/* use ProPointType to specify
					   the point */
  PRO_DIM_SNS_TYP_SPLN_PNT, 
					/* specify the index of the
					   spline point */

  /* used to specify tangent location */ 
  PRO_DIM_SNS_TYP_TGT_IDX, 
					/* specify the index of the
					   tangent */
  PRO_DIM_SNS_TYP_LIN_AOC_TGT, 
					/* use ProDimLinAocTgtSense */

  /* specifies how to measure angle */
  PRO_DIM_SNS_TYP_ANGLE, 
					/* use ProDimAngleSense */
  PRO_DIM_SNS_TYP_PNT_ANGLE
					/* use ProPointType and
					   ProDimAngleSense */

} ProDimSenseType;

/* specifies how the angle of an angular dimension is measured */
typedef struct pro_dim_angle_sense
{

  ProBoolean	is_first;
                                        /* angle is measured starting
                                           from this entity (line).
                                           must be set for only one
                                           entity. */
  ProBoolean	should_flip;
                                        /* flip entity direction
                                           to measure the angle. */
  ProBoolean	pic_vec_dir;
                                        /* currently unused. */

} ProDimAngleSense;

typedef enum pro_dim_lin_aoc_tgt_sense
{

  PRO_DIM_LIN_AOC_TGT_LEFT0 =	4,
					/* when dimensioning between a line
					   & the tangent of a(n) arc/circle, 
					   there may be two valid tangents to 
					   the line. specifies the tangent to
					   the left which is on the same 
					   side of center as the line. */
  PRO_DIM_LIN_AOC_TGT_RIGHT0 =	5,
					/* tangent to the right on the same 
					   side of the arc/circle center */
  PRO_DIM_LIN_AOC_TGT_LEFT1 =	6,
					/* tangent to the left on the other 
					   side of the arc/circle center */
  PRO_DIM_LIN_AOC_TGT_RIGHT1 =	7
					/* tangent to the right on the other
					   side of the arc/circle center. */ 

} ProDimLinAocTgtSense;

/* during dimension creation, when the selected entities
   can be dimensioned in more than one way, the orientation
   of the dimension must be specified as below */ 
  
typedef enum pro_dim_orient
{

  PRO_DIM_ORNT_NONE = 		0,	/* do not change this value. */
  PRO_DIM_ORNT_VERT = 		1,	/* do not change this value.*/
  PRO_DIM_ORNT_HORIZ = 		2,	/* do not change this value.*/
  PRO_DIM_ORNT_SLANTED =	3,

  /* specifies which radius to dimension for an ellipse */
  PRO_DIM_ORNT_ELPS_RAD1 = 	4,
  PRO_DIM_ORNT_ELPS_RAD2 = 	5,

  /* for an arc, the arc radius will be dimensioned by default.
     use the two values below to dimension the arc length or the
     arc angle. */
  PRO_DIM_ORNT_ARC_ANG = 	6,
  PRO_DIM_ORNT_ARC_LENGTH =	7,

  /* for a dimension between a line and a point on a curve, the 
     default dimension will be a linear dimension measuring the
     distance between the line and the point. to dimension the
     angle between the line and the tangent at the curve point
     (the point on the curve must be an endpoint), use the
     value below. */ 
  PRO_DIM_ORNT_LIN_TANCRV_ANG = 8,

  /* linear dimension of the radial distance between two concentric
     arcs or circles */
  PRO_DIM_ORNT_RAD_DIFF = 9,

  /* Linear point-point dimension with orientation 'normal to the
     specified reference'. */
  PRO_DIM_ORNT_NORMAL = 11,

  /* Linear point-point dimension with orientation 'parallel to the
     specified reference'.*/
  PRO_DIM_ORNT_PARALLEL = 12



} ProDimOrient;

typedef struct pro_dim_sense
{
  /* specify type of sense here */
  ProDimSenseType	type;

  /* use one or both according to type */
  int 			sense;
  ProDimAngleSense	angle_sense;

  /* optional hint. when entities of the dimension can be
     dimensioned in more than one way, specifies exactly
     which way. if left unspecified for dimension creation,
     a default orientation will be chosen considering the
     entities to be dimensioned. */ 

  ProDimOrient		orient_hint;

} ProDimSense;

typedef ProSelection ProDimAttachment[2];


typedef ProError (*ProDimModifyValuePreAction)( ProDimension *dimension );
/*
  Purpose: This is the notification function called before a dimension
           value is modified in Creo Parametric.
           If the user supplied function returns anything other than
           PRO_TK_NO_ERROR, the value will NOT be modified by Creo Parametric.

           This function is to be supplied by the user by calling
           ProNotificationSet() with the type PRO_DIM_MODIFY_VALUE_PRE.

  Input Arguments:
     dimension   -   The dimension about to be modified.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR/PRO_TK_GENERAL_ERROR
*/

typedef enum pro_dimensiontype
{
    PRODIMTYPE_UNKNOWN    = -1, /* ((== DIM_TYPE_UNKNOWN)) */
    PRODIMTYPE_LINEAR     =  9, /* ((== DIM_LINEAR      )) */
    PRODIMTYPE_RADIUS     =  3, /* ((== DIM_RAD         )) */
    PRODIMTYPE_DIAMETER   =  4, /* ((== DIM_DIA         )) */
    PRODIMTYPE_ANGLE      = 21, /* ((== DIM_ANGULAR     )) */
    PRODIMTYPE_ARC_LENGTH = 72  /* ((== DIM_TRUE_ARC_LENGTH )) */
} ProDimensiontype;



typedef enum pro_display_mode
{
    PRODISPMODE_NUMERIC  = 0,
    PRODISPMODE_SYMBOLIC = 1
    
} ProDisplayMode;

typedef enum pro_tolerance_type
{
   PROTOLERANCE_LINEAR = 0,
   PROTOLERANCE_ANGULAR = 1    
} ProToleranceType;

typedef enum pro_dim_tol_types
 {
  PRO_TOL_DEFAULT = 1,  /*Indicates Nominal Tolerance*/
  PRO_TOL_PLUS_MINUS = 2,
  PRO_TOL_LIMITS = 3,
  PRO_TOL_PLUS_MINUS_SYM = 4,
  PRO_DIM_TOL_SYM_SUPERSCRIPT = 8,
  PRO_DIM_TOL_BASIC = 12
 } Pro_dim_tol_types, ProDimToleranceType;

typedef enum pro_dim_ordinate_standard
{
  PRO_DIM_ORDSTD_DEFAULT = 0,  /* The default standard */
  PRO_DIM_ORDSTD_ANSI,
  PRO_DIM_ORDSTD_JIS,
  PRO_DIM_ORDSTD_ISO,
  PRO_DIM_ORDSTD_DIN,
  PRO_DIM_ORDSTD_SAME_AS_3D  /* In drawing. Set the standard same as in 3D */
} ProDimOrdinateStandard;

typedef enum {
  PRO_SECONDARY_DIM_DISPLAY_OFF,     /* Turns Off Dual Dimension display                                */
  PRO_SECONDARY_DIM_DISPLAY_BOTTOM,  /* Displays secondary dimension to the bottom of primary dimension */
  PRO_SECONDARY_DIM_DISPLAY_RIGHT    /* Displays secondary dimension to the right of primary dimension  */
} ProDualDimensionDisplayType;

typedef enum
{
  PRO_DIM_REF_FIRST = 	0,
  PRO_DIM_REF_SECOND = 	1
} ProDimensionReferenceType;

typedef enum
{
  PRO_DIM_DISPLAY_DECIMAL = 0,
  PRO_DIM_DISPLAY_FRACTIONAL = 1
} ProDimensionDisplayFormat;

extern ProError ProDimensionNomvalueGet(ProDimension *dim, 
                                        double *nominal_value);

/*
  Purpose: retrieves the dimension's nominal value
           <B>Note: </B>the value is always returned in degrees for angular 
              dimension and in the unit of system for other types 
              of the dimension.

  Input Arguments:
    dim                 -  The input dimension's handle

  Output Arguments:
    nominal_value       -  The nominal value of the dimension

  Return Values:
    PRO_TK_NO_ERROR     -  The function retrieved the nominal 
                           value successfully.
    PRO_TK_BAD_INPUTS   -  The input dimension handle was not valid.
*/

extern ProError ProDimensionBoundSet(ProDimension *dim, ProMdl TableModel,
                                     ProDimbound bound);

/*
  Purpose: set the dimension's bound

  Input Arguments:
    dim                - The dimension's handle
    TableModel         - The model whose table is to be updated
    bound              - The new bound for the dimension

  Output Arguments:
    None.

  Return Values:
    PRO_TK_NO_ERROR    - The function set the dimension's bound
                         successfully.
    PRO_TK_BAD_INPUTS  - The dimension handle or the TableModel were invalid
    PRO_TK_CANT_MODIFY - The dimension's owner model or the TableModel are
                         read-only.
    PRO_TK_BAD_CONTEXT - cannot set bound for this dimension.
    PRO_TK_CANT_WRITE  - Could not modify the given item because
                         it has read-only access.

*/

extern ProError ProDimensionBoundGet(ProDimension *dim, ProDimbound *r_bound);

/*
  Purpose: retrieve the dimension's bound.

  Input Arguments:
    dim                  -  The dimension's handle

  Output Arguments:
    r_bound              -  The dimension's bound.

  Return Values:
    PRO_TK_NO_ERROR      -  The function retrieved the bound successfully.
    PRO_TK_BAD_INPUTS    -  The dimension was not a valid prodimension.
*/

extern ProError ProDimensionSymtextGet(ProDimension *dim, ProLine **r_text);

/*
  Purpose: Retrieves the dimension's text in symbol mode.

  Input Arguments:
    dim                 -  The input handle.

  Output Arguments:
    r_text              -  ProArray of text.
							To free the memory, call <b>ProArrayFree()</b>.

  Return Values:
    PRO_TK_NO_ERROR     - The function successfully retrieved the
                          information.
    PRO_TK_BAD_INPUTS   - The dimension supplied was not valid
                          or did not have a valid line array.
*/

extern ProError ProDimensionTollabelGet(ProDimension *dimension,
                                        ProToleranceTable *type,
                                        ProName table,
                                        int *column);
/*
      Purpose: Retrieves the ISO/DIN tolerance label on the specified dim.     
      Input Arguments:
          dimension    - The dimension handle.
  
      Output Arguments:
          type        - The tolerance type assigned to the dimension (general,
                        broken edge, hole, or shaft)
          table       - The table name assigned to the dimension, e.g. "X",  
                        if the type is hole or shaft.
          column      - The table column assigned to the dimension, if the type
                        is hole or shaft.

      Return Values:
          PRO_TK_NO_ERROR       - The function successfully retrieved the
                                  information.
          PRO_TK_E_NOT_FOUND    - There was no tolerance label.
          PRO_TK_BAD_INPUTS     - The dimension handle was invalid.
          PRO_TK_BAD_CONTEXT    - The model is not in the ISO/DIN standard.
*/

extern ProError ProDimensionTollabelSet (ProDimension *dimension,
                                         ProToleranceTable type,
                                         ProName table,
                                         int column);

/*
   Purpose: Sets the ISO/DIN tolerance label on the specified dimension.

   Input Arguments:
      dimension - The dimension handle.
      type      - The tolerance type to be assigned to the dimension.
      table     - The table name to be assigned to the dimension.  Used only
                  if type is PROTOLTABLE_HOLES or PROTOLTABLE_SHAFTS.
      column    - The table column to be assigned to the dimension.  Used only
                  if type is PROTOLTABLE_HOLES or PROTOLTABLE_SHAFTS.

   Output Arguments:
      None.

   Return Values:
      PRO_TK_NO_ERROR	 - The operation was successful.
      PRO_TK_E_NOT_FOUND - There was no corresponding tolerance table.
      PRO_TK_BAD_CONTEXT - The dimension has no tolerance (a driven dim) or
                           the model is not in the ISO/DIN standard.
      PRO_TK_BAD_INPUTS  - The dimension was invalid or an input was NULL.
      PRO_TK_CANT_MODIFY - The model is locked and cannot be modified.
      PRO_TK_CANT_ACCESS - The table was valid but could not be accessed
                           because it had not yet been loaded.
*/

typedef ProError (*ProDimensionFilterAction)(
    ProDimension *dimension,
    ProAppData   data);
/*
   Purpose: Prototype of the caller supplied function which is called
            for every model dimension.
 
   Input Arguments:
      dimension      -  the dimension being visited.
      data           -  caller supplied data
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_CONTINUE    - skip this dimension, do not call
                           the visit function.
        other            - pass this error status into the
                           visit function.
*/
 
typedef ProError (*ProDimensionVisitAction)(
    ProDimension  *dimension,
    ProError      status,
    ProAppData     data);
/*
   Purpose: Prototype of the caller-supplied function which is called
            for every solid dimension approved by the filter function.
 
   Input Arguments:
      dimension      -  the dimension being visited.
      status         -  error status from the filter function.
      data           -  caller supplied data
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR    - Continue visiting.
         other           - visiting will stop and this error will be
                           returned back by ProMdlDimVisit().
*/
 
extern ProError ProDimensionSymbolGet  (
    ProDimension *dimension,
    ProName      symbol);
    
/* 
    Purpose: Retrieves the symbol of a specified dimension. 
   
    Input Arguments:
      dimension        - The  dimension handle.         
 
    Output Arguments:    
      symbol           - the dimension symbol.
 
    Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the symbol.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
*/
 
extern ProError ProDimensionValueGet  (
    ProDimension *dimension,
    double       *value);
    
/*
   Purpose: Retrieves the value of a specified dimension.  
   
   Input Arguments:
      dimension       - The  dimension handle.        
 
   Output Arguments:
      value           - The value of the dimension. If the model is fully 
                        regenerated, this value is always positive. Use 
                        ProDimensionIsRegenednegative() to see if the 
                        dimension is flipped direction compared to the 
                        default for the feature.
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the value.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 

   See Also:
      ProDimensionIsRegenednegative()
      ProDimensionValueSet()
*/

extern ProError ProDimensionToltypeGet  (
    ProDimension *dimension,
    ProDimToleranceType  *type);
    
/*
    Purpose: Retrieves the tolerance of the specified dimension
             of the object.

    Input Arguments:
        dimension        - The dimension handle.

    Output Arguments:
        type             - The dimension tolerance type.

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the tolerance.
      PRO_TK_BAD_CONTEXT  - The input dimension is reference.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/
 
extern ProError ProDimensionToleranceGet  (
    ProDimension *dimension,
    double       *upper_limit,
    double       *lower_limit);
/*
   Purpose: Retrieves parameters of a specified dimension.
   
   Input Arguments: 
      dimension       - The  dimension handle.      
 
   Output Arguments:
      upper_limit     - the dimension upper limit.
      lower_limit     - the dimension lower limit.
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved parameters.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
                           
*/
 
extern ProError ProDimensionTypeGet  (
    ProDimension     *dimension,
    ProDimensiontype *type);
/*
   Purpose: Retrieves the type of a specified dimension.
   
   Input Arguments:
      dimension       - The  dimension handle.        
 
   Output Arguments:
      type            - the dimension type.
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the type.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
*/
 
extern ProError ProDimensionIsFractional  (
    ProDimension *dimension,
    ProBoolean   *fractional);
    
/*
   Purpose: Determines whether the specified dimension is fractional.
   
   Input Arguments:
      dimension       - The  dimension handle.          
 
   Output Arguments:
      fractional      - The  dimension fractional (PRO_B_TRUE or PRO_B_FALSE).
 
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the information.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
*/
 
extern ProError ProDimensionDecimalsGet  (
    ProDimension *dimension,
    int          *decimals);
    
/*
   Purpose: Retrieves the number of significant digits of a specified dimension.
   
   Input Arguments:
      dimension       - The  dimension handle.          
 
   Output Arguments:
       decimals       - the number of significant digits.
 
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the information.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
                           
*/
 
extern ProError ProDimensionDenominatorGet  (
    ProDimension *dimension,
    int          *denominator);
    
/*
   Purpose: Retrieves the denominator of a specified dimension.
   
   Input Arguments:
      dimension       - The  dimension handle.          
 
   Output Arguments:
      denominator     - The  dimension denominator.
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the 
                              information.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
*/
 
extern ProError ProDimensionIsReldriven  (
    ProDimension *dimension,
    ProBoolean   *rel_driven);
    
/*
   Purpose: Determines whether the specified dimension is rel_driven.
   
   Input Arguments:
      dimension       - The  dimension handle.          
 
   Output Arguments:
      rel_driven      - The  dimension rel_driven ((PRO_B_TRUE or PRO_B_FALSE)).
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the 
                              information.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 
*/
 
extern ProError ProDimensionIsRegenednegative  (
    ProDimension *dimension,
    ProBoolean   *regened_negative);
    
/*
   Purpose: Identifies if the dimension is currently considered to have a 
            negative "sign" in generating its direction. If the dimension 
            has a negative sign then the dimension is oriented in the 
            opposite manner to the default for the feature.
   
   Input Arguments:
      dimension        - The dimension handle.          
 
   Output Arguments:
      regened_negative - The dimension regened_negative
                         ((PRO_B_TRUE or PRO_B_FALSE)).
 
   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the 
                              information.
      PRO_TK_GENERAL_ERROR  - The data structure was not set. 

   See Also:
      ProDimensionValueSet()
      ProDimensionValueGet()
*/

extern ProError ProDimensionSymbolSet  (
    ProDimension *dimension,
    ProName      symbol);
    
/*  
    Purpose: Sets the symbol of the specified dimension of the object.

    Input Arguments:
        dimension        - The dimension handle.
        symbol           - The dimension symbol.

    Output Arguments:
        None

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the symbol.
      PRO_TK_NO_CHANGE    - The function could not set the symbol to new value
                            as the new symbol name already exists for other 
                            dimension in the model.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

*/

extern ProError ProDimensionValueSet  (
    ProDimension *dimension,
    double       value);
    
/*  
    Purpose: Sets the value of the specified dimension of the object.

    Input Arguments:
        dimension        - The dimension handle.
        value            - The new value of the dimension. 
                           If a negative number is passed, this 
                           will flip the direction of the dimension.

    Output Arguments:
        None

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the value.
      PRO_TK_BAD_CONTEXT  - The input dimension is reference.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

    See Also:
      ProDimensionIsRegenednegative()
      ProDimensionValueGet()

*/
 
extern ProError ProDimensionToltypeSet  (
    ProDimension *dimension,
    ProDimToleranceType  type);
    
/*
    Purpose: Sets the tolerance of the specified dimension of the object.

    Input Arguments:
        dimension        - The dimension handle.
        type             - The dimension tolerance type.

    Output Arguments:
        None

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the tolerance.
      PRO_TK_BAD_CONTEXT  - The input dimension is reference.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/


extern ProError ProDimensionToleranceSet  (
    ProDimension *dimension,
    double       upper_limit,
    double       lower_limit);
    
/*
    Purpose: Sets the tolerance of the specified dimension of the object.

    Input Arguments:
        dimension        - The dimension handle.
        upper_limit      - The dimension upper limit.
        lower_limit      - The dimension lower limit.

    Output Arguments:
        None

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the tolerance.
      PRO_TK_BAD_CONTEXT  - The input dimension is reference.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/
 
extern ProError ProDimensionDecimalsSet  (
    ProDimension *dimension,
    int          decimals);

/*  
    Purpose: For a non-rounded dimension, sets the number of significant
             digits. For a rounded dimension, sets the number of displayed digits.
             <B>Note:</B> A rounded dimension should be un-rounded to allow
            the number of significant digits to be set. 
                    

    Input Arguments:
        dimension        - The dimension handle.
        decimals         - The number of significant digits; has to be non-negative.
                           <B>Note:</B> This argument must be such that
                           the total number of symbols (in the mmm.ddd format)
                           will not exceed 13 for the both (dimension-tolerance)
                           and (dimension+tolerance) values.

    Output Arguments:
        None

    Return Values:
    
      PRO_TK_NO_ERROR     - The function successfully set the number of 
                            significant digits.
      PRO_TK_BAD_INPUTS   - The input "dimension" argument is invalid.
      PRO_TK_BAD_CONTEXT  - The dimension is fractional, so this value cannot
                            be set.
      
      PRO_TK_NOT_VALID    - The input "decimals" argument is out-of-range .
*/
 
extern ProError ProDimensionDenominatorSet  (
    ProDimension *dimension,
    int          denominator);

/*  
    Purpose: Sets the denominator of the specified dimension of the object.

    Input Arguments:
        dimension        - The dimension handle.
        denominator     - The dimension denominator.

    Output Arguments:
        None

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the denominator.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProDimensionDimensionReset  (
    ProDimension *dimension);
    
/*  
    Purpose: Resets the dimensions of the object to the values they had at the 
             time the last regeneration was done.
   
    Input Arguments:
      dimension            - The dimension handle.         
 
    Output Arguments:
      None
 
    Return Values:
      PRO_TK_NO_ERROR       - The function successfully reset the dimensions. 
      PRO_TK_GENERAL_ERROR  - The function did not reset the dimensions.
*/

extern ProError ProDimensionDisplayUpdate  (
    ProDimension *dimension);

/* 
    DEPRECATED: Since Creo 2
    SUCCESSORS: ProAnnotationDisplay, ProAnnotationUndisplay
    Purpose: <B>Note:</B> This function is superseded by a combination of
               ProAnnotationDisplay() and ProAnnotationUndisplay().

           Redisplays the dimension, as long as it is already being displayed
           in the current window.
   
    Input Arguments:
      dimension       - The dimension handle.          
 
    Output Arguments:
      None
 
    Return Values:
      PRO_TK_NO_ERROR      - The function successfully redisplayed the dimension.
      PRO_TK_GENERAL_ERROR - dimension is not a valid object.
*/

extern ProError ProDimensionShow  (
    ProDimension   *dimension,
    ProView        view,       
    ProDrawing     drawing,        
    ProAsmcomppath *path);   
 
/*  
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProAnnotationDisplay,ProAnnotationShow
    Purpose:  <B>Note:</B> This function is deprecated.  To force the 
                temporary display of a dimension in a solid model, use 
		ProAnnotationDisplay().  To force the permanent disply of
		a dimension in a drawing view, use ProAnnotationShow().

           Forces the display of the specified dimension.
 
   Input Arguments:
      dimension          - The dimension handle.
      view               - The drawing view in which to display the dimension. 
                           If you are in part or  assembly mode, 
                           set this to NULL. 
      drawing            - The drawing that contains the view of the model in
                           which the dimension is to be displayed. If you are 
                           not, set this argument to NULL. 
      path               - The path from the assembly in the specified view
                           to the owner of the dimension to be displayed.
			   If the current model is an assembly, and the 
			   dimension belongs to assembly, set this argument
			   to NULL. 
 
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully displayed the dimension.
      PRO_TK_GENERAL_ERROR - The function did not displayed the dimension.
*/

extern ProError ProDimensionErase  (
    ProDimension *dimension,
    ProDrawing drawing);

/* 
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProAnnotationUndisplay,ProAnnotationErase
    Purpose: <B>Note:</B> This function is deprecated.  To force the 
                temporary erasure of a dimension in a solid model, use 
		ProAnnotationUndisplay().  To force the permanent disply of
		a dimension in a drawing view, use ProAnnotationErase().

             Erases a previously displayed dimension in a model.
   
    Input Arguments:
      dimension          - The dimension handle.        
      drawing            - The drawing that contains the view of the model in
                           which the dimension is to be displayed. If you are 
                           not, set this argument to NULL. 
 
    Output Arguments:
      None
 
    Return Values:
      PRO_TK_NO_ERROR      - The function successfully erased the dimension.
      PRO_TK_GENERAL_ERROR - The function did not erased the dimension.
*/

extern ProError ProDisplaymodeGet(
    ProDisplayMode *mode);

/*  
    Purpose: Retrieves the current dimension display mode.
   
    Input Arguments:
      None          
 
    Output Arguments:
      mode             - Dimension display mode.
 
   Return Values:
      PRO_TK_NO_ERROR  - The function successfully retrieved the information.
*/

extern ProError ProDisplaymodeSet(
    ProDisplayMode mode);
    
/*  
    Purpose: Sets the current dimension value display mode to symbolic or
             numeric.
   
    Input Arguments:
      mode             - The new dimension display mode.      
 
    Output Arguments:
      None
 
    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set display mode.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProDimensionCanRegen  (
    ProDimension *dimension,
    ProBoolean *can_regen);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProDimensionCanRegenerate
    Purpose: Checks whether a driven dimension can be regenerated. 
             <B>Note:</B> This function is superseded by
             ProDimensionCanRegenerate, and is equivalent to
             ProDimensionCanRegenerate(dimension, NULL, can_regen).

    Input Arguments:
        dimension        - The dimension handle.         
    Output Arguments:
        can_regen        - PRO_B_TRUE or PRO_B_FALSE.
        
    Return Values:
        PRO_TK_NO_ERROR  - The function successfully retrieved the
                           information.
        Other            - The input argument is invalid.         
*/

extern ProError ProDimensionCanRegenerate  (
    ProDimension *dimension,
    ProDrawing   drawing,
    ProBoolean *can_regen);

/* 
    Purpose: Checks whether a driven dimension can be regenerated. 

    Input Arguments:
        dimension        - The dimension handle.
        drawing          - Can the dimension be regenerated in the
                           context of this drawing?  If NULL, check
                           is made in the context of the dimension's model.
    Output Arguments:
        can_regen        - PRO_B_TRUE or PRO_B_FALSE.

    Return Values:
        PRO_TK_NO_ERROR  - The function successfully retrieved the
                           information.
        Other            - The input argument is invalid.        
*/

extern ProError ProDimensionPrefixGet(
    ProDimension *dimension,
    ProLine prefix);

/*  
    Purpose: Get the dimension prefix.
    
    Input Arguments:
        dimension        - The dimension handle.         
    Output Arguments:
        prefix           - The dimension prefix in a ProLine.
        
    Return Values:
        PRO_TK_NO_ERROR     - The function successfully retrieved the
                              information.
        PRO_TK_BAD_INPUTS   - An argument is invalid.
        PRO_TK_INVALID_TYPE - The dimension type is invalid.
        PRO_TK_E_NOT_FOUND  - The dimension or prefix is not found.
*/

extern ProError ProDimensionSuffixGet(
    ProDimension *dimension,
    ProLine suffix);

/*  
    Purpose: Get the dimension suffix.
    
    Input Arguments:
        dimension        - The dimension handle.         
    Output Arguments:
        suffix           - The dimension suffix in a ProLine.
        
    Return Values:
        PRO_TK_NO_ERROR     - The function successfully retrieved the
                              information.
        PRO_TK_BAD_INPUTS   - An argument is invalid.
        PRO_TK_INVALID_TYPE - The dimension type is invalid.
        PRO_TK_E_NOT_FOUND  - The dimension or suffix is not found.
*/

extern ProError ProDimensionPrefixSet(
    ProDimension *dimension,
    ProLine prefix);

/*  
    Purpose: Set the dimension prefix.
    
    Input Arguments:
        dimension        - The dimension handle.         
        prefix           - The dimension prefix in a ProLine.
        
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR     - The function successfully set the prefix.
        PRO_TK_BAD_INPUTS   - An argument is invalid.
        PRO_TK_INVALID_TYPE - The dimension type is invalid.
        PRO_TK_E_NOT_FOUND  - The dimension isn't found.
        PRO_TK_CANT_MODIFY  - The dimension isn't modifiable.
*/

extern ProError ProDimensionSuffixSet(
    ProDimension *dimension,
    ProLine suffix);

/*  
    Purpose: Set the dimension suffix.
    
    Input Arguments:
        dimension        - The dimension handle.         
        suffix           - The dimension suffix in a ProLine.
        
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR     - The function successfully set the suffix.
        PRO_TK_BAD_INPUTS   - An argument is invalid.
        PRO_TK_INVALID_TYPE - The dimension type is invalid.
        PRO_TK_E_NOT_FOUND  - The dimension isn't found.
        PRO_TK_CANT_MODIFY  - The dimension isn't modifiable.
*/

extern ProError ProDimensionTextGet  (
    ProDimension *dimension,
    ProLine **p_text);

/*  
	DEPRECATED: Since Wildfire 5.0
	SUCCESSORS: ProDimensionTextWstringsGet
    Purpose: <B>Note:</B> This function is deprecated. It only works for 
             text with less than 80 characters. Use 
             ProDimensionTextWstringsGet() for text with any number of 
             characters.

             Retrieves the text of the specified dimension.
    
    Input Arguments:
        dimension       - The dimension handle.
               
    Output Arguments:
        p_text         - ProArray. The function allocates the memory for this
                         argument. To free the memory, call 
                         <b>ProArrayFree()</b>.
                       
    Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the 
                                information.
        Other                 - The input argument is invalid.
*/

extern ProError ProDimensionTextSet  (
    ProDimension *dimension,
    ProLine *text);
    
/*  
	DEPRECATED: Since Wildfire 5.0
	SUCCESSORS: ProDimensionTextWstringsSet
    Purpose: <B>Note:</B> This function is deprecated. It only works for 
             text with less than 80 characters. Use 
             ProDimensionTextWstringsSet() for text with any number of 
             characters.
 
             Sets the text of the specified dimension. This is equivalent to 
             the Creo Parametric command Modify, Text.
             
    Input Arguments:
        dimension     - The dimension handle.
        text          - The dimension text. Each line must be null-terminated.
 
    Output Arguments:
        None
 
    Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the 
                                information.
        Other                 - The input argument is invalid.     
*/

extern ProError ProToleranceDefaultGet  (
    ProToleranceType type,
    int              n_decimals,
    double           *tolerance);
    
/*  
    Purpose: Retrieves the current Creo Parametric default tolerance value for 
             the specified number of decimal places.
   
    Input Arguments:
        type             - The tolerance type. 
        n_decimals       - The number of decimal places used to identify the
                           tolerance.  
 
    Output Arguments:
        tolerance        - The default tolerance.
 
    Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the 
                                information.
        Other                 - The input argument is invalid.     
                           
*/

extern ProError ProDimensionIsToleranceDisplayed  (
    ProDimension *dimension,
    ProBoolean *tolerance_displayed);

/*  
   Purpose: Determines the tolerance display mode of a dimension.
   
   Input Arguments:
      dimension             - The dimension handle.
 
   Output Arguments:
      tolerance_displayed   - PRO_B_TRUE or PRO_B_FALSE.
 
   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved 
                                information.
        Other                 - The input argument is invalid.     
*/

extern ProError ProDimensionIsBasic  (
    ProDimension *dimension,
    ProBoolean *basic);

/*
   Purpose: Determines if the dimension is of Basic type.

   Input Arguments:
      dimension             - The dimension handle.

   Output Arguments:
      basic                 - PRO_B_TRUE or PRO_B_FALSE.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved
                                information.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProDimensionIsInspection (
    ProDimension *dimension,
    ProBoolean *inspection);

/*
   Purpose: Determines if the dimension if of Inspection type

   Input Arguments:
      dimension             - The dimension handle.

   Output Arguments:
      inspection   	    - PRO_B_TRUE or PRO_B_FALSE.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved
                                information.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProDrawingDimensionIsDisplayed (
    ProDrawing   drawing,
    ProDimension *dimension,
    ProBoolean   *displayed);

/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProAnnotationIsShown
   Purpose: <B>Note:</B> This function is deprecated.  Use 
                ProAnnotationIsShown().

		Determines if the dimension is displayed

   Input Arguments:
      drawing               - The owner drawing.
      dimension             - The dimension handle.

   Output Arguments:
      displayed             - PRO_B_TRUE or PRO_B_FALSE.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved
                                information.
        PRO_TK_BAD_INPUTS     - The input arguments are invalid.
*/

extern ProError ProDrawingDimensionIsToleranceDisplayed(
    ProDrawing   p_draw,
    ProDimension *dimension, 
    ProBoolean   *tolerance_displayed);
/*
   Purpose: Indicates whether a drawing dimension's tolerance is visible or not.
 
   Input Arguments:
      p_draw    - The owner drawing.
      dimension - The dimension handle.

   Output Arguments:
      tolerance_displayed - PRO_B_TRUE/PRO_B_FALSE

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved
                               information.
      PRO_TK_BAD_INPUTS   - The input arguments are invalid.
*/

extern ProError   ProSymbolDesignationVerify (ProMdl mdl, ProName symbol,
ProBoolean* p_is_designated);
/*
    Purpose:   Determine if a dimension, dimension tolerance, gtol, or surface
finish has been designated in the model.

    Input Arguments:
                    mdl -        The model.
                   symbol -   The symbol of the model entity.

    Output Arguments:
                    p_is_designated - PRO_B_TRUE if the symbol is designated,
                                      PRO_B_FALSE if not.

    Return Values:
                    PRO_TK_NO_ERROR - The function succeeded.
                    PRO_TK_BAD_INPUTS - Invalid input arguments provided.
*/

extern ProError   ProSymbolDesignate (ProMdl  mdl, ProName symbol);
/*
    Purpose:   Designate a dimension, dimension tolerance, geometric tolerance
or surface finish symbol.

    Input Arguments:
                    mdl -        The model.
                   symbol -   The symbol of the model enity.

    Output Arguments:
                    None.

    Return Values:
                    PRO_TK_NO_ERROR - The function succeeded.
                    PRO_TK_NO_CHANGE - The symbol  is already designated.
                    PRO_TK_BAD_INPUTS - Invalid input arguments provided.
*/

extern ProError   ProSymbolUndesignate (ProMdl mdl, ProName symbol);
/*
    Purpose:  Undesignate a dimension, dimension tolerance, geometric tolerance,
or surface finish.

   Input Arguments:
                    mdl -         The model.
                   symbol -   The symbol of the model entity.

    Output Arguments:
                    None.

    Return Values:
                    PRO_TK_NO_ERROR - The function succeeded.
                    PRO_TK_NO_CHANGE - The symbol  is not currently designated.
                    PRO_TK_BAD_INPUTS - Invalid input arguments provided.
*/

extern ProError ProDimensionLocationGet (ProDimension* dim, ProView view,
                                         ProDrawing drawing,
                                         ProDimlocation* data);
/*
        Purpose:
                Returns a structure containing the location of elements making
                up a solid model/drawing dimension or reference dimension.

                NOTE: In a solid model, dimension location values will always
                be extracted by this function with respect to the indicated
                model orientation. The locations and values will be different
                for the same dimension when that model has a different
                orientation and scaling factor applied.
                This does not apply for drawings.

                NOTE: In the event of a PRO_TK_NOT_DISPLAYED error, the
                argument "data" still contains location information.

        Input Arguments:
                dim - The dimension handle.
		view - The orientation of the model that will be applied before
                       calculating the locations. Pass NULL to use the current
                       model view, if the model is current, or a default model
                       orientation otherwise.
                       Pass NULL if using a drawing.
                drawing - The drawing handle. Pass NULL if not using a drawing.

        Output Arguments:
                data - The dimension location data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_NOT_DISPLAYED - The function succeeded, but only after
                                  internally selecting a default orientation
                                  where one was not supplied, for a dimension
                                  which could have different locations given
                                  different views. This error can only occur
                                  if both drawing and view are NULL.
                PRO_TK_BAD_INPUTS - One or more arguments is invalid. For
                                   example, if drawing != NULL && view != NULL.
                PRO_TK_E_NOT_FOUND - This dimension is not displayable.
		PRO_TK_NOT_VALID - A drawing view was passed with a drawing.
*/

extern ProError ProDimlocationFree (ProDimlocation data);
/*
        Purpose:
                Frees the dimension location data.

        Input Arguments:
                data - The dimension location data, extracted using 
                       ProDimensionLocationGet().
        
        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more arguments is invalid.
*/

extern ProError ProDimlocationTextGet (ProDimlocation data,
                                       ProBoolean* has_elbow, ProPoint3d pnt,
                                       double* elbow_length);
/*
	Purpose:
                Returns the location of the dimension text in a dimension. If
                the dimension contains an elbow, the function provides the
                elbow joint location along with the elbow length for locating
                the dimension text with respect to any model orientation.

	Input Arguments:
		data - The dimension location data, extracted using
                       ProDimensionLocationGet().

	Output Arguments:
		has_elbow    - PRO_B_TRUE if the dimension text has an elbow
                               joint, PRO_B_FALSE if not.
		pnt          - The location, in model coordinates, of the
                               dimension text (if has_elbow is PRO_B_FALSE)
                               or the elbow joint (if has_elbow is
                               PRO_B_TRUE). Pass NULL when not required.
		elbow_length - The length of the elbow, in model coordinates.
                               The sign of the value indicates whether the text
                               is to the left of the elbow joint (elbow_length
                               < 0) or to the right (elbow_length > 0). This
                               length is based upon no scaling being applied to
                               the model. See ProDimensionLocationGet() for more
                               information.

    <B>Note:</B> From Creo 4.0, ProDimensionElbowlengthSet() has been superseded
                 by ProDimensionElbowSet().

                               <B>WARNING: </B> If the elbow length value was
                               set by ProDimensionElbowSet() function,
                               then the elbow_length value retrieved by this
                               function would be equal to the value set in the
                               ProDimensionElbowSet() function minus the
                               padding around the text, for all dimension types.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more arguments is invalid.

	See Also:
		ProDimensionLocationGet()
*/

extern ProError ProDimlocationArrowsGet (ProDimlocation data, 
                                      ProPoint3d arrow_1, ProPoint3d arrow_2);
/*
        Purpose:
                Returns the location of the dimension arrow heads in a
                dimension.
                Consult the online documentation for diagrams explaining where
                the arrow heads are located for each dimension type. 

        Input Arguments:
                data - The dimension location data, extracted using 
                       ProDimensionLocationGet().
        
        Output Arguments:
                arrow_1 - The location, in model coordinates, of the first
                          dimension arrowhead. This location is based upon no
                          scaling being applied to the model. See
                          ProDimensionLocationGet() for more information.
                          Pass NULL when not interested in this output. 
                arrow_2 - The location, in model coordinates, of the second
                          dimension arrowhead. Should be ignored if the
                          dimension type would have only one arrowhead. This 
                          location is based upon no scaling being applied to the
                          model. See ProDimensionLocationGet() for more
                          information. Pass NULL if not interested in this
                          output. 

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more arguments is invalid.

	See Also:
		ProDimensionLocationGet()
*/
                                                                
extern ProError ProDimlocationWitnesslinesGet (ProDimlocation data, 
                                               ProPoint3d witness_line_1,
                                               ProPoint3d witness_line_2);
/*
        Purpose:
                Returns the location of the dimension witness line ends in a
                dimension.
                Consult the online documentation for diagrams explaining where
                the witness line endpoints are located for each dimension type.

        Input Arguments:
                data - The dimension location data, extracted using 
                       ProDimensionLocationGet().
        
        Output Arguments:
                witness_line_1 - The location, in model coordinates, of the
                                 first dimension witness line end. Pass NULL
                                 when not required.
                witness_line_2 - The location, in model coordinates, of the
                                 second dimension witness line end. Pass NULL
                                 when not required.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more arguments is invalid.
                PRO_TK_INVALID_TYPE - This type of dimension does not have
                                      witness line endpoints.

	See Also:
		ProDimensionLocationGet()
*/



extern ProError ProDimlocationZExtensionlinesGet (ProDimlocation data,
                                              ProBoolean* has_z_ext_line_end_1,
                                              ProPoint3d z_ext_line_end_1,
                                              ProBoolean* has_z_ext_line_end_2,
                                              ProPoint3d z_ext_line_end_2);
/*
    Purpose: Obtains the Z-Extension line endpoints for the dimension.  Consult
             the diagram in the documentation for information about how
             Z-Extension line endpoints describe the layout of the dimension.

    Input Arguments:
        data - The dimension location data, extracted using
               ProDimensionLocationGet

    Output Arguments:
        has_z_ext_line_end_1 - PRO_B_TRUE if the dimension has a Z-Extension
                               line from the first end of the dimension
                               PRO_B_FALSE otherwise.
        z_ext_line_end_1 - The end point of the first z-Extension line, if
                           has_z_ext_line_1 is PRO_B_TRUE.
        has_z_ext_line_end_2 - PRO_B_TRUE if the dimension has a Z-Extension
                               line from the second end of the dimension
                               PRO_B_FALSE otherwise.
        z_ext_line_end_2 - The end point of the second z-Extension line, if
                           has_z_ext_line_2 is PRO_B_TRUE.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/



extern ProError ProDimlocationNormalGet (ProDimlocation location,
                                         ProVector normal);
/*
    Purpose: For a dimension which is of type diameter or radial, this returns 
             the normal for the dimensioning plane.  This should correspond to 
             the axis normal to the arc being measured by the radial or 
             diameter dimension.
             

    Input Arguments:
        location - The dimension location object.

    Output Arguments:
        normal - The normal vector to the dimensioning plane.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - The dimension is not a radial or diameter 
                              dimension.
*/



extern ProError ProDimensionDelete (
  ProDimension*     dimension);
/*
   Purpose:  Deletes a reference or driven dimension.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
     dimension	- The dimension (type must be PRO_REF_DIMENSION or PRO_DIMENSION)

   Output Arguments:
      none 

   Return Values:
      PRO_TK_NO_ERROR	- The function succeeded.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_CANT_WRITE - Could not delete the given item because 
                          it has read-only access.
      PRO_TK_INVALID_ITEM - The input dimension is invalid (non-driven).
*/

extern ProError ProDimensionInspectionSet  (
  ProDimension *dimension,
  ProBoolean inspection);

/*
   Purpose: Sets if the dimension is of Inspection type.

   Input Arguments:
     dimension         - The dimension handle.
     inspection        - PRO_B_TRUE or PRO_B_FALSE.

   Output Arguments:
      none

   Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved information.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
     PRO_TK_CANT_WRITE - Could not modify the given item because 
                         it has read-only access.
*/


extern ProError ProDimensionBasicSet  (
  ProDimension *dimension,
  ProBoolean basic);

/*
   Purpose: Sets if the dimension is of Basic type.

   Input Arguments:
     dimension      - The dimension handle.
     basic          - PRO_B_TRUE or PRO_B_FALSE.

   Output Arguments:
     none

   Return Values:
     PRO_TK_NO_ERROR - The function successfully retrieved information.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
     PRO_TK_CANT_WRITE - Could not modify the given item because 
                         it has read-only access.
*/

extern ProError ProDimensionCreate (
  ProSolid		model,
  ProType       dimension_type,
  ProAnnotationPlane      *annotation_plane,
  ProDimAttachment	*attachments_arr,
  ProDimSense		*dsense_arr,
  ProDimOrient      orient_hint, 
  Pro3dPnt		location,
  ProDimension		*dimension);
/*
   Purpose:  Creates a new reference or driven dimension in the solid model.
   	     ProAnnotationShow() should be called after creating the 
             dimension in order for the dimension to be displayed.
             
   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
     model	- The solid model.
     annotation_plane  - The annotation plane for the dimension.
     dimension_type    - The dimension type (PRO_REF_DIMENSION or PRO_DIMENSION)
     attachments_arr	- ProArray of attachments.
     dsense_arr		- ProArray of dimension sense.
     orient_hint     - The orientation hint for the dimension.
     location	- initial location of the dimension text.

  Output Arguments:
      dimension			- the newly created dimension

  Return Values:
      PRO_TK_NO_ERROR	- The function succeeded.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_BAD_DIM_ATTACH	- A dimension could not be created with
                                  the attachments and sense specified.
*/

extern ProError ProDimensionAttachmentsGet (
  ProDimension   *dimension,
  ProAnnotationPlane *annotation_plane,
  ProDimAttachment	**attachments_arr,
  ProDimSense		**dsense_arr,
  ProDimOrient      *orient_hint);
/*
   Purpose:  Retrieves the attachment information for a reference or driven 
             dimension.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
     dimension		- The dimension (type must be PRO_REF_DIMENSION 
                          or PRO_DIMENSION)

  Output Arguments:
      annotation_plane  - The annotation plane for the dimension.
      attachments_arr	- ProArray of attachments.  
                          Free this result using ProDimattachmentarrayFree().  
			  Pass NULL if not interested in this output.
      dsense_arr	- ProArray of dimension sense.  
                          Free this result using ProArrayFree().  
			  Pass NULL if not interested in this output.
      orient_hint       - The orientation hint for the dimension. Pass NULL if 
                          not interested in this output. 

  Return Values:
      PRO_TK_NO_ERROR		- The function succeeded.
      PRO_TK_BAD_INPUTS		- One or more of the input arguments are
                                  invalid.
      PRO_TK_INVALID_ITEM       - The input dimension is invalid (non-driven). 
*/

extern ProError ProDimattachmentarrayFree (ProDimAttachment *attachments_arr);
/*
   Purpose: Frees the memory owned by an array of dimension attachments.

   Input Arguments:
     attachments_arr	- The dimension attachments array.

  Output Arguments:
     none

  Return Values:
      PRO_TK_NO_ERROR		- The function succeeded.
      PRO_TK_BAD_INPUTS		- One or more of the input arguments are
                                  invalid.
*/


extern ProError ProDimensionAttachmentsSet (
  ProDimension*     dimension,
  ProAnnotationPlane      *annotation_plane,
  ProDimAttachment	*attachments_arr,
  ProDimSense		*dsense_arr,
  ProDimOrient      orient_hint);
/*
   Purpose:  Modifies the attachment information for a reference or driven 
             dimension.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
     dimension		- The dimension (type must be PRO_REF_DIMENSION 
                          or PRO_DIMENSION)
     annotation_plane  - The annotation plane for the dimension.
     attachments_arr	- ProArray of attachments.  
     dsense_arr		- ProArray of dimension sense.  
     orient_hint       - The orientation hint for the dimension. 

  Output Arguments:
      none

  Return Values:
      PRO_TK_NO_ERROR		- The function succeeded.
      PRO_TK_BAD_INPUTS		- One or more of the input arguments are
                                  invalid.
      PRO_TK_BAD_DIM_ATTACH	- A dimension could not be created with
                                  the attachments and sense specified.
      PRO_TK_CANT_WRITE		- Could not modify the given item because
                                  it has read-only access.
*/

extern ProError ProDimensionIsDriving (
    ProDimension *dimension,
    ProBoolean* is_driving);

/*
   Purpose: Returns whether or not the dimension drives solid model geometry 
            or is driven by it.  If the dimension drives solid model geometry 
            it cannot be deleted, its attachments cannot be modified or 
            obtained, and it cannot be added to an annotation element.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
      dimension    - The dimension handle.
	
   Output Arguments:
      is_driving   - PRO_B_TRUE if the dimension drives solid model 
                     geomretry, PRO_B_FALSE if it is a driven dimension.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved
                                information.
        PRO_TK_BAD_INPUTS     - One or more arguments was invalid.
*/

extern ProError ProDimensionTextstyleSet (ProDimension* dimension,
                                          ProTextStyle text_style);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProAnnotationTextstyleSet
    Purpose: <P><B>Note:</B> This function is deprecated. Use 
              ProAnnotationTextstyleSet() instead.</P> 
	      Assigns the text style assigned to a dimension or reference dimension.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.
        text_style - The text style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_WRITE - Could not modify the given item because
                            it has read-only access.
*/

extern ProError ProDimensionTextstyleGet (ProDimension* dimension,
                                          ProTextStyle* text_style);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProAnnotationTextstyleGet
    Purpose: <P><B>Note:</B> This function is deprecated. Use 
              ProAnnotationTextstyleGet() instead.</P> 
	      Obtains the text style assigned to a dimension or reference dimension.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:

        dimension - The dimension.

    Output Arguments:
        text_style - The text style. Free this using ProTextStyleFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDimensionFeatureGet (ProDimension* dimension,
                                        ProFeature* feature);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProDimensionOwnerfeatureGet
    Purpose: <B>Note:</B> This function is deprecated. For dimensions or 
             reference dimensions, if owner feature is in group, group feature 
             is returned which isn't the originally documented, inteded behaviour. 
             Use ProDimensionOwnerfeatureGet() to get the owner feature that  
             directly owns that element.
 
             Obtains the feature that owns this dimension.  For dimensions or
             reference dimensions in annotation elements, this will return
             the annotation feature that owns that element, but if the owning
             feature is in group, it will return the group feature instead 

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        feature - The feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension is not owned by a particular feature.
*/

extern ProError ProDimensionOwnerfeatureGet (ProDimension* dimension,
                                        ProFeature* feature);
/*
    Purpose: Obtains the feature that owns this dimension.  For dimensions or
             reference dimensions in annotation elements, this will return
             the owner feature that directly owns that element. 

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        feature - The feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension is not owned by a particular feature.
*/

extern ProError ProDimensionAnnotationelemCreate (ProDimension* dim,
                                                  ProAnnotationPlane* plane,
                                                  ProAnnotationElem* elem);
/*
    Purpose: Create an annotation element for the given driving dimension.  
             This will trigger a regeneration.
             
             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dim - The dimension.
        plane - The dimension orientation.
	        event of a regeneration failure, PRO_B_FALSE to abort 
		the modification.

    Output Arguments:
        elem - The newly created annotation element.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE  - The dimension is not a driving dimension.
	PRO_TK_INVALID_ITEM  - This type of driving dimension is not suitable
	                       for incorporation into a driving dimension
			       annotation element.
        PRO_TK_E_FOUND       - The dimension already has an annotation element.
        PRO_TK_INVALID_MATRIX - The orientation provided cannot be used for 
                                this dimension.
		PRO_TK_NOT_VALID    -  For a driving dimension annotation element, the
							   annotation orientation provided is not frozen.
        PRO_TK_GENERAL_ERROR - The annotation element could not be constructed
                               in the owner feature.

*/

extern ProError ProDimensionAnnotationelemDelete (ProDimension* dim);
/*
    Purpose: Removes the annotation element containing a driving dimension.  
             This will remove all parameters and relations associated to the 
             annotation element.
             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dim - The dimension.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension does not have an annotation element.

*/

extern ProError ProDimensionPlaneSet (ProDimension* dimension,
                                      ProAnnotationPlane* plane);
/*
    Purpose: Assigns the orientation of the dimension.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.
        plane - The orientation of the dimension.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_MATRIX - The orientation cannot be used for the input 
                                dimension.
        PRO_TK_NOT_VALID - For a driving dimension annotation element, the
                           annotation orientation provided is not frozen.
        PRO_TK_BAD_CONTEXT - The driving dimension is not in an annotation
                             element.
*/

extern ProError ProDimensionPlaneGet (ProDimension* dimension,
                                      ProAnnotationPlane* plane);
/*
    Purpose: Obtains the orientation of the dimension.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        plane - The orientation of the dimension. For dimensions which are not
                assigned a specific orientation, this may include
                PRO_ID_NO_ANNOTATION_PLANE as its id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProDimensionOrdinateCreate (
    ProSolid model,
    ProType type,
    ProAnnotationElem* baseline,
    ProDimAttachment reference,
    ProDimSense* sense,
    Pro3dPnt location,
    ProDimension* dimension);
/*
    Purpose: Creates a new ordinate driven or reference dimension in solid 
             model. ProAnnotationShow() should be called after creating the 
             dimension in order for the dimension to be displayed.
         
    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        model - The target model.
        type - The dimension type (PRO_DIMENSION or PRO_REF_DIMENSION)
        baseline - The baseline dimension to reference.
        reference - The geometry reference(s) for the ordinate dimension.
        sense - The dimension sense to use for the attachment geometry.
        location - The initial location of the dimension text.

    Output Arguments:
        dimension - The newly created dimension.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_DIM_ATTACH - The dimension cannot be created referencing the 
                                given baseline and attachment geometry.

    See Also:
        ProDimensionCreate()
*/

extern ProError ProDimensionOrdinatestandardGet (
    ProDimension* dimension,
    ProDimOrdinateStandard* ordinate_standard);
/*
    Purpose: Obtains the ordinate standard used by the given dimension.  All of 
             the related ordinate dimensions in a set must use the same 
             standard.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        ordinate_standard - The ordinate standard.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionOrdinatestandardSet (
    ProDimension* dimension,
    ProDimOrdinateStandard ordinate_standard);
/*
    Purpose: Assigns the ordinate standard used by the given dimension.  All of 
             the related ordinate dimensions in a set must use the dame 
             standard.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.
        ordinate_standard - The ordinate standard.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_MODIFY - The input ordinate dimension is not a baseline dimension.

*/

extern ProError ProDimensionOrdinatereferencesSet (
    ProDimension* dimension,
    ProDimAttachment ordinate_reference,
    ProDimSense* dimension_sense);
/*
    Purpose: Assigns the geometric reference for the ordinate dimension.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.
        ordinate_reference - The ordinate dimension reference.
        dimension_sense - Dimension sense used for the attachment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_DIM_ATTACH - Invalid attachment geometry for this ordinate 
                                dimension.
        PRO_TK_INVALID_TYPE - The dimension is not an ordinate dimension.

*/

extern ProError ProDimensionMove (ProDimension* dimension, Pro3dPnt location);
/*
    Purpose: Moves the dimension to the given position within its owner model.
             Note that the dimension position may not be exactly at the
             location specified, as it will be affected by the annotation plane
             if it has one.
 
     Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.
        location  - The new location for the dimension.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionIsOrdinate (
    ProDimension* dimension,
    ProBoolean* is_ordinate,
    ProDimension* baseline);
/*
    Purpose: Identifies if a dimension is ordinate.
             
    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        is_ordinate - PRO_B_TRUE if the dimension is ordinate, PRO_B_FALSE 
                      otherwise.
        baseline - The baseline, if the dimension is ordinate.
                   Valid only if the is_ordinate is PRO_B_TRUE.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionIsBaseline (
    ProDimension* dimension,
    ProBoolean* is_baseline);
/*
    Purpose: Identifies if a dimension is baseline.
             
    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        is_baseline - PRO_B_TRUE if the dimension is a baseline dimension, 
                      PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/
extern ProError ProDimensionDisplayedValueGet(
    ProDimension *dimension,
    double       *value);   
/*
   Purpose: 
       Retrieves the displayed rounded value of a specified dimension.
  
   Input Arguments:
       dimension       - The  dimension handle.

   Output Arguments:
       value           - The rounded value of the dimension.

   Return Values:
       PRO_TK_NO_ERROR       - The function successfully retrieved the value.
       PRO_TK_E_AMBIGUOUS    - The displayed format is not decimal
       PRO_TK_BAD_INPUTS     - The input arguments are invalid.
       PRO_TK_GENERAL_ERROR  - The data structure was not set.

   See Also:
      ProDimensionValueGet()
*/
extern ProError ProDimensionDisplayedToleranceGet  (
    ProDimension *dimension,
    double       *upper_limit,
    double       *lower_limit);
/*
   Purpose: 
       Retrieves displayed rounded values of limits of a specified dimension.

   Input Arguments:
       dimension       - The  dimension handle.

   Output Arguments:
       upper_limit     - The rounded value of the dimension upper limit.
                         This can be NULL if lower_limit is not NULL.
       lower_limit     - The rounded value of the dimension lower limit.
                         This can be NULL if upper_limit is not NULL.       

   Return Values:
       PRO_TK_NO_ERROR       - The function successfully retrieved limits.
       PRO_TK_E_AMBIGUOUS    - The displayed format is not decimal
       PRO_TK_BAD_INPUTS     - The input arguments are invalid or 
                               both the output arguments are NULL.
       PRO_TK_GENERAL_ERROR  - The data structure was not set.

   See Also:
       ProDimensionToleranceGet()
*/

extern ProError ProDimensionDisplayRoundedValueSet(
    ProDimension *dimension,
    ProBoolean    display_rounded);
/*
   Purpose: 
       Sets the attribute to toggle whether the dimension displays
       rounded values.
   Input Arguments:
       dimension - The dimension handle
       display_rounded - PRO_B_TRUE to set the attribute
   Output Arguments:
       None
   Return Values:
       PRO_TK_NO_ERROR    - The function successfully changed the attribute
       PRO_TK_NO_CHANGE   - The input attribute is the same as an existing one
       PRO_TK_CANT_MODIFY - Modification of the attribute is not allowed
       PRO_TK_BAD_INPUTS  - The input argument is invalid      

*/    




extern ProError ProDimensionIsDisplayRoundedValue(
    ProDimension *dimension,
    ProBoolean *p_is_display_rounded);    
/*    
   Purpose:
       Determines if the dimension has been set to display rounded values.
   Input Arguments:
       dimension - The dimension handle.
      
   Output Arguments:
       p_is_display_rounded - Placeholder for PRO_B_TRUE/PRO_B_FALSE
   Return Values:
       PRO_TK_NO_ERROR    - The function successfully retrieved information
       PRO_TK_BAD_INPUTS  - Data structures cannot be retrieved
       PRO_ TK_NOT_VALID  - Option is non-applicable for the dimension
       PRO_TK_BAD_CONTEXT - Option is set, but the display is not decimal
*/

extern ProError ProDimlocationArrowtypesGet (ProDimlocation location, 
                                               ProLeaderType* arrow_1, 
					       ProLeaderType* arrow_2);
/*
    Purpose: Returns the type of arrows used for each of the dimension arrows.  
             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        location - The dimension location structure obtained from 
                   ProDimensionLocationGet().

    Output Arguments:
        arrow_1 - The arrow type used for the first dimension arrow.  Pass NULL 
                  if not interested in this output.
        arrow_2 - The arrow type used for the second dimension arrow.  Should 
                  be ignored if the dimension type would have only one 
                  arrowhead.  Pass NULL if not interested in this output.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProDimensionLocationGet()
        ProDimlocationArrowsGet()
*/

extern ProError ProDimensionArrowtypeSet(ProDimension *dimension,
                                         ProDrawing drawing,
                                         int arrow_index,
                                         ProLeaderType arrow_type);
/* Purpose: Set the type of one of a dimension's arrows.

   Input Arguments:
     dimension    - The dimension for which we wish to set an arrow type.
     drawing      - A drawing in which the dimension is shown, in which to
                    set the arrow type. May be NULL to set the arrow type
                    in the dimension's owner model.
     arrow_index  - Either 1 or 2. For ordinate and radius dimensions, this
                    value is ignored. For diameter dimensions, this determines
                    which of the two arrows to change. For other dimensions,
                    a value of 1 indicates the arrow on the first witness line,
                    and a value of 2 indicates the arrow on the second.
     arrow_type   - The type to which the arrow is set.

   Output Arguments:
     none

   Return Values:
     PRO_TK_NO_ERROR    - The function succeeded.
     PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
     PRO_TK_E_NOT_FOUND - The dimension does not exist.
     PRO_TK_INVALID_PTR - The dimension owner is invalid.
     PRO_TK_CANT_MODIFY - The dimension cannot be modified.
*/

typedef enum {
PRO_DIMVALUEDISPLAY_NOMINAL,
PRO_DIMVALUEDISPLAY_OVERRIDE,
PRO_DIMVALUEDISPLAY_HIDE
} ProDimensionValueDisplay;


extern ProError ProDimensionTolerancedecimalsGet (ProDimension* dimension, 
                                                  int* tolerance_decimals);
/*
    Purpose: Obtains the number of decimal places shown for the tolerance 
             values.

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        tolerance_decimals - The number of decimal places.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The number of decimals is driven by the number of 
                             decimals for the dimension. 
        PRO_TK_BAD_CONTEXT - The dimension is fractional.

    See Also:
        ProDimensionDecimalsGet()
        ProDimensionIsFractional()
        ProDimensionDenominatorGet()
        ProDimensionTolerancedenominatorGet()
*/

extern ProError ProDimensionTolerancedecimalsSet (ProDimension* dimension, 
                                                  int tolerance_decimals);
/*
    Purpose: Assigns the number of decimal places shown for the tolerance 
             values.  
             <P> Note: This will make the dimension tolerance decimals no 
             longer be driven by the number of dimension decimals.

    Input Arguments:
        dimension - The dimension.
        tolerance_decimals - The number of decimal places; has to be non-negative..
                             <B>Note:</B> This argument must be such that
                             the total number of symbols (in the mmm.ddd format)
                             will not exceed 13 for the both (dimension-tolerance)
                             and (dimension+tolerance) values..                             

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - Input "dimension" argument was invalid.
        PRO_TK_BAD_CONTEXT - The dimension is fractional, so this value cannot
                             be set.
        PRO_TK_NOT_VALID    - The input "decimals" argument is out-of-range . 


    See Also:
        ProDimensionDecimalsSet()
        ProDimensionIsFractional()
        ProDimensionDenominatorSet()
        ProDimensionTolerancedenominatorSet()
*/

extern ProError ProDimensionTolerancedenominatorGet (ProDimension* dimension, 
                                                     int* tolerance_denominator);
/*
    Purpose: Obtains the value for the denominator for the tolerance values.

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        tolerance_denominator - The tolerance denominator value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The denominator is driven by the denominator for 
                             the dimension.
        PRO_TK_BAD_CONTEXT - The dimension is not fractional.

    See Also:
        ProDimensionIsFractional()
        ProDimensionDenominatorGet()
*/

extern ProError ProDimensionTolerancedenominatorSet (ProDimension* dimension, 
                                                     int tolerance_denominator);
/*
    Purpose: Assigns the value for the denominator for the tolerance values.

    Input Arguments:
        dimension - The dimension.
        tolerance_denominator - The tolerance denominator value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The dimension is not fractional.

    See Also:
        ProDimensionIsFractional()
        ProDimensionDenominatorSet()
*/

extern ProError ProDimensionOverridevalueGet (ProDimension* dimension, 
                                              double* override_value);
/*
    Purpose: Obtains the override value for the dimension.  

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        override_value - The override value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The override value is not set.

*/

extern ProError ProDimensionOverridevalueSet (ProDimension* dimension, 
                                              double override_value);
/*
    Purpose: Assigns the override value for the dimension.  

    Input Arguments:
        dimension - The dimension.
        override_value - The override value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionValuedisplayGet (ProDimension* dimension, 
                                             ProDimensionValueDisplay* value_display);
/*
    Purpose: Obtains the type of value displayed for the dimension.

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        value_display - The type of value displayed.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionValuedisplaySet (ProDimension* dimension, 
                                             ProDimensionValueDisplay value_display);
/*
    Purpose: Assigns the type of value displayed for the dimension.

    Input Arguments:
        dimension - The dimension.
        value_display - The type of value displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionIsAccessibleInModel (
    ProDimension* dimension,
    ProBoolean* is_accessible);
/*
    Purpose: Identifies if a dimension is owned by the model.

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        is_accessible - PRO_B_TRUE if dimension is accessible in model, 
	                PRO_B_FALSE otherwise.
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDimensionElbowlengthSet( ProDimension* dimension,
                                            double elbow_length );
/*
DEPRECATED: Since Creo 4.0

SUCCESSORS:
    ProDimensionElbowSet

Purpose: Sets the elbow length of the dimension
         <B>Note:</B> This function is deprecated.

<B>Note:</B>
    The function ProDimensionElbowLengthSet does not work on dimension that were
    created in Solid mode, and shown in the drawing mode. You cannot set a value
    for elbow length in drawing mode using this API.

Input Arguments:
    dimension - The dimension
    elbow_length - The elbow length

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded. 
    PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid 
    PRO_TK_NOT_DISPLAYED - If dimension is not displayed
    PRO_TK_INVALID_ITEM - If dimension does not have an elbow
*/



typedef enum pro_dim_center_leader_types
{
  PRO_DIM_CLEADER_CENTERED_ELBOW,
  PRO_DIM_CLEADER_ABOVE_ELBOW,
  PRO_DIM_CLEADER_ABOVE_EXT_ELBOW,
  PRO_DIM_PARALLEL_ABOVE,
  PRO_DIM_PARALLEL_BELOW
} ProDimCenterLeaderType;

extern ProError ProDimlocationCenterleadertypeGet (ProDimlocation data, 
                                    ProDimCenterLeaderType* center_leader_type,
                                    ProLeaderType* leader_type, 
                                    double* elbow_length, 
                                    ProVector elbow_direction);
/*
    Purpose: Obtains the type of center leader used for the dimension, if this 
             dimension uses a center leader.

    Input Arguments:
        data - The dimension location data, extracted from 
               ProDimensionLocationGet()

    Output Arguments:
        center_leader_type - The type of center leader used for the dimension.
        leader_type - The leader end symbol.
        elbow_length - The length of the elbow.  If the type is "Parallel 
                       above" or "Parallel below" this value should be ignored.
        elbow_direction - The direction of the elbow, from the dimension text 
                          to the dimension leader.  If the type is "Parallel 
                          above" or "Parallel below", this should be ignored.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - This dimension does not use a center leader type 
                             of construction.
*/

/* Following enum represents dimension text formats for chamfer dimensions */
typedef enum
{
     PRO_DIM_CHMFRSTYLE_CD, /* Show chamfer dimension text
                               in "C(Dimension value)" format */
     PRO_DIM_CHMFRSTYLE_D_X_45, /* Show chamfer dimension text
                                   in "(Dimension value) X 45" format */
     PRO_DIM_CHMFRSTYLE_DEFAULT = 4, /* Show chamfer dimension text in format
                                        specified by detail setup option */
     PRO_DIM_CHMFRSTYLE_45_X_D = 6 /* Show chamfer dimension text
                                      in "45 X (Dimension value)" format */
} ProDimChamferStyle;

extern ProError ProDimensionChamferstyleGet (ProDimension* dimension,
                                             ProDimChamferStyle* chamfer_style);
/*
    DEPRECATED: Since Creo 4.0

    SUCCESSORS:
        ProDimensionChamferTextGet

    Purpose: Obtains the chamfer dimension style for the chamfer dimension.
             <B>Note:</B> This function is deprecated.

	<B>Note: </B>
        The function ProDimensionChamferstyleGet does not work on dimensions that
        were created in Solid mode, and shown in the drawing mode. You cannot get
        value for chamfer text style in drawing mode using this API.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        chamfer_style - The chamfer dimension style.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension is not a chamfer dimension.
*/

extern ProError ProDimensionChamferstyleSet (ProDimension* dimension,
                                             ProDimChamferStyle chamfer_style);
/*
    DEPRECATED: Since Creo 4.0

    SUCCESSORS:
        ProDimensionChamferTextSet

    Purpose: Assigns the chamfer dimension style for the chamfer dimension.
             <B>Note:</B> This function is deprecated.

	<B>Note: </B>
        The function ProDimensionChamferstyleSet does not work on dimensions that
        were created in Solid mode, and shown in the drawing mode. You set a value
        for chamfer text style in drawing mode using this API.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension - The dimension.
        chamfer_style - The chamfer dimension style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension style is not chamfer.
*/

typedef enum
{
     PRO_DIM_CHMFR_LEADER_STYLE_NORMAL, /* for ASME/ANSI, JIS, ISO */
     PRO_DIM_CHMFR_LEADER_STYLE_LINEAR = 6,
     PRO_DIM_CHMFR_LEADER_STYLE_DEFAULT = 12
} ProDimChamferLeaderStyle;

extern ProError ProDimensionChamferLdrstyleGet (ProDimension* dimension,
                                                ProDimChamferLeaderStyle* chamfer_leader_style);
/*
    DEPRECATED: Since Creo 4.0

    SUCCESSORS:
        ProDimensionChamferLeaderGet

    Purpose: Obtains the chamfer dimension leader style for the chamfer
             dimension.
             <B>Note:</B> This function is deprecated.

	<B>Note: </B>
       The function ProDimensionChamferLdrstyleGet does not work on dimension that
       were created in Solid mode, and shown in the drawing mode. You cannot get a
       value for chamfer leader style in drawing mode using this API.

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        chamfer_leader_style - The chamfer dimension leader style.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension is not a chamfer dimension.
*/

extern ProError ProDimensionChamferLdrstyleSet (ProDimension* dimension,
                                                ProDimChamferLeaderStyle chamfer_leader_style);
/*
    DEPRECATED: Since Creo 4.0

    SUCCESSORS:
        ProDimensionChamferLeaderSet

    Purpose: Assigns the chamfer dimension leader style for the chamfer
             dimension.
             <B>Note:</B> This function is deprecated.

	<B>Note: </B>
       The function ProDimensionChamferLdrstyleSet does not work on dimension that
       were created in Solid mode, and shown in the drawing mode. You cannot set a
       value for chamfer leader style in drawing mode using this API.

    Input Arguments:
        dimension - The dimension.
        chamfer_leader_style - The chamfer dimension leader style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The dimension style is not chamfer.
*/

typedef enum
{
  PRO_DIMCONFIG_LEADER, /* for chamfer dims (DIN standard) */
  PRO_DIMCONFIG_LINEAR, /* for linear, chamfer dims */
  PRO_DIMCONFIG_CENTER_LEADER, /* for linear dims */
  DIM_CONFIGURATION_ANGULAR  /* angular dims */
} ProDimensionconfig;

extern ProError ProDimensionConfigurationGet (ProDimension* dimension,
                                              ProDimensionconfig *config);
/*
    DEPRECATED: Since Creo 4.0

    SUCCESSORS:
        ProDimensionConfigGet

    Purpose: Obtains the dimension configuration.
             <B>Note:</B> This function is deprecated.

    <B>Note:</B>
       The function ProDimensionConfigurationGet does not work on dimension that
       were created in Solid mode, and shown in the drawing mode. You cannot get
       a value for dimension configuration in drawing mode using this API.

    Input Arguments:
        dimension - The dimension.

    Output Arguments:
        config - The dimension configuration.

    Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
         PRO_TK_E_NOT_FOUND - Dimension not found.
*/

extern ProError ProDimensionConfigurationSet (ProDimension* dimension,
                                              ProDimensionconfig config);
/*
    DEPRECATED: Since Creo 4.0

    SUCCESSORS:
        ProDimensionConfigSet

    Purpose: Assigns the dimension configuration.
             <B>Note:</B> This function is deprecated.

    <B>Note:</B>
       The function ProDimensionConfigurationSet does not work on dimension that
       were created in Solid mode, and shown in the drawing mode. You cannot set
       a value for dimension configuration in drawing mode using this API.

    Input Arguments:
        dimension - The dimension.
        config - The dimension configuration.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProDimensionTextWstringsGet  (
    ProDimension *dimension,
    wchar_t ***p_text);

/*
    Purpose: Retrieves the text of the specified dimension.
  
    Input Arguments:
        dimension       - The dimension handle.

    Output Arguments:
        p_text         - ProArray of wstrings. The function allocates the memory for this
                         argument. To free the memory, call
                         <b>ProWstringproarrayFree().</b>.

    Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_BAD_INPUTS     - Input argument dimension is NULL or 
                                Output argument p_text is NULL.
        PRO_TK_E_NOT_FOUND    - Dimension text is not found.
        PRO_TK_GENERAL_ERROR  - Operation is terminated incompletely.
*/

extern ProError ProDimensionTextWstringsSet  (
    ProDimension *dimension,
    wchar_t **text);
  
/*
    Purpose: Sets the text of the specified dimension. This is equivalent to
             the Creo Parametric command Modify, Text.

    Input Arguments:
        dimension     - The dimension handle.
        text          - ProArray of wstrings. The dimension text. Each line must be null-terminated.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_BAD_INPUTS     - Input arguments dimension or text is NULL.
        PRO_TK_GENERAL_ERROR  - Operation gets terminated unsuccessfully.
*/

extern ProError ProDimensionSimpleBreakCreate ( ProDimension *dimension,
                                                ProDrawing drawing,
                                                int index,
                                                Pro3dPnt break_start,
                                                Pro3dPnt break_end );

/*
    Purpose: Create a simple break in an existing dimension witness line.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension   - The dimension whose witness line is being broken.
        drawing     - The drawing in which the dimension is shown. May be NULL.
        index       - For a non-ordinate, non-radius dimension, the witness line
                      index is 1 or 2 otherwise this is not used.
        break_start - The starting point of the break.
        break_end   - The ending point of the break.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR     - The dimension witness line break was created.
        PRO_TK_BAD_INPUTS   - The dimension object or cosmetic model is not valid.
        PRO_TK_CANT_MODIFY  - The object or cosmetic model can't be modified.
        PRO_TK_INVALID_ITEM - The dimension is not valid.
        PRO_TK_INVALID_TYPE - The dimension can't have a witness line break.
        PRO_TK_ABORT        - The dimension witness line couldn't be broken.
*/

extern ProError ProDimensionJogCreate ( ProDimension *dimension,
                                        ProDrawing drawing,
                                        int index,
                                        Pro3dPnt *jog_points );

/*
    Purpose: Create a witness line jog in an existing dimension witness line.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dimension   - The dimension whose witness line is being jogged.
        drawing     - The drawing in which the dimension is shown. May be NULL.
        index       - For a non-ordinate dimension, the witness line index : 1
                      or 2.  For an ordinate dimension, this is not used.
        jog_points  - A ProArray of jog points. There must be at least two
                      points if the witness line does not yet have any jogs.
                      Angular and arc length dimension may not have more than
                      two jog points per witness line.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR     - The dimension witness line jog was created.
        PRO_TK_BAD_INPUTS   - The dimension object or cosmetic model is not valid.
        PRO_TK_CANT_MODIFY  - The object or cosmetic model can't be modified.
        PRO_TK_INVALID_ITEM - The dimension is not valid for this operation.
        PRO_TK_INVALID_TYPE - The dimension can't have a witness line jog.
        PRO_TK_ABORT        - The dimension witness line couldn't be jogged.
*/

extern ProError ProDimensionIsSignDriven(ProDimension *dimension,
                                         ProBoolean *is_sign_driven);

/*
   Purpose: Identifies if the dimension always uses a true sign.
            <b>Note: </b>for dimensions which use the sign to flip the
            direction, this behavior can be overridden by setting the config
            option 'show_dim_sign' to 'yes'.  By default it is set to 'no'.

   Input Arguments:
      dimension      - The dimension handle.         

   Output Arguments:
      is_sign_driven - Cannot be NULL.
                       PRO_B_TRUE : This dimension uses sign to flip the direction.
                       PRO_B_FALSE : This dimension always uses a true sign.  That is, a negative value is literally negative.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS   - One or more inputs are not valid.

   See Also:
      ProDimensionValueSet()
      ProDimensionValueGet()
*/

extern ProError ProDimensionAutoOrdinateCreate ( ProDrawing drawing,
                                                 ProSelection *surface_array,
                                                 ProSelection baseline,
                                                 ProDimension **dimensions );

/*
    Purpose: Creates ordinate dimensions in a drawing.

    Input Arguments:
        drawing     - Target drawing (This must be displayed in the window.)
        surface_array - The array of parallel surfaces to be dimensioned.
                        It must be a ProArray of ProSelection.
                                                Selections must contain view information.
                        Use ProSelectionViewSet() to set view.
                                                All selections must be from same view and same solid.
        baseline    - Reference for creating baseline dimension.
                                Valid types are PRO_EDGE,PRO_DATUM_PLANE,PRO_CURVE

    Output Arguments:
        dimensions - ProArray of created dimensions. This is a ProArray.
                     Use ProArrayFree to free it from memory.

    Return Values:
        PRO_TK_NO_ERROR     - The function successfully created the ordinate dimensions.
        PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.

      See Also:
      ProMdlDisplay()
      ProSelectionViewSet()
*/

extern ProError ProDimensionParentGet (ProDimension* dim, ProDimension* parent_dim);
/*
    Purpose: Retrieves the parent dimension of the value dependent dimension.

    Input Arguments:
        dim - The dimension's handle.

    Output Arguments:
        parent_dim - The parent dimension.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - The input argument is invalid.
        PRO_TK_E_NOT_FOUND - The dimension is not value dependent or parent 
                             dimension is not retrieved.

*/

extern ProError ProSolidDimensionToOrdinate (ProDimension *dimension,
                                             ProDimension *base_dimension);
/*
  Purpose: Converts a linear dimension to ordinate using the base dimension specified.
		   A Dimension must be ordinate when created first time and then converted to ordinate
		   It will not work on dimension which were created as linear.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    dimension		- linear dimension to be converted to ordinate.
    base_dimension	- the ordinate baseline dimension to be used.

  Output Arguments:
    None 

  Return Values:
	PRO_TK_NO_ERROR - successfully converted the linear 
					  dimension to ordinate.
    PRO_TK_BAD_INPUTS - one or more of the input arguments are 
                        invalid.
    PRO_TK_GENERAL_ERROR - failed to convert the linear dimension
                           to ordinate.   
    PRO_TK_CANT_WRITE - Could not modify the given item because
                        it has read-only access.
*/

extern ProError ProSolidDimensionToLinear (ProDimension *dimension);
/*
  Purpose: Converts an ordinate dimension to linear.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    dimension		- ordinate dimension to be converted to linear.

  Output Arguments:
    None 

  Return Values:
    PRO_TK_NO_ERROR - successfully converted the ordinate dimension
					  to linear. 
    PRO_TK_BAD_INPUTS - one or more of the input arguments are 
                        invalid.
    PRO_TK_GENERAL_ERROR - failed to convert the ordinate dimension
                           to linear.
    PRO_TK_CANT_WRITE - Could not modify the given item because
                        it has read-only access.
--------------------------------------------------------------------------*/

extern ProError ProDrawingOrdinateDimensionsCreate (
    ProDrawing drawing,
    ProType pro_type,    
    ProDimAttachment *attachment_array,
    ProDimSense* sense_array,
    Pro3dPnt  location,
    ProDimension* dim_array);
/*
    Purpose: Creates multiple ordinate driven or reference dimension in drawing.
         
    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        drawing - The target drawing.
        pro_type - T_DIMENSION or T_REF_DIMENSION.
        attachment_array - ProArray of dimension attachments. First attachment will be used to create baseline dimension.
        sense_array - ProArray of dimension sense to use for the attachment.
        location - ProArray of location of the dimension text.

    Output Arguments:
        dim_array - ProArray of created dimension. Free this using ProArrayFree()

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_DIM_ATTACH - The dimension cannot be created referencing the 
                                 attachment geometry.
*/

extern ProError ProDimensionWitnesslineShow (ProDimension *dimension,
                                             ProDrawing drawing);

/*
    Purpose: Show the erased witnessline of the input dimension. This API
             should work in 2D and 3D modes for dimension and reference
             dimension.

    Input Arguments:
        dimension - The dimension whose witnessline is to be shown,
                    always non NULL.
        drawing - The drawing in which dimension is displayed, can be
                  NULL if witness line is to be shown in a solid.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR     - The dimension witnessline is shown.
        PRO_TK_BAD_INPUTS   - The dimension object is not valid.
        PRO_TK_NO_CHANGE    - The dimension witnessline could not be shown or
                              input dimension does not have erased witnessline.
*/

extern ProError ProDimensionWitnesslineErase (ProDimension *dimension,
                                              ProDrawing drawing,
                                              int WitnesslineIndex);

/*
    Purpose: Erase the witnessline of the input dimension given its side.
             This API should work in 2D and 3D modes for dimension and
             reference dimension.

    Input Arguments:
        dimension - The dimension whose witnessline is to be erased,
                    always non NULL.
        drawing - The drawing in which dimension is displayed, can be
                  NULL if witness line is to be erased in a solid.
        WitnesslineIndex - Witnessline side, can be 1 or 2 only.

    Output Arguments:

        none

    Return Values:
        PRO_TK_NO_ERROR     - The dimension witnessline is erased.
        PRO_TK_BAD_INPUTS   - The dimension object or witnessline index
                              is not valid.
        PRO_TK_NO_CHANGE  - The dimension witnessline could not be erased.
*/

extern ProError ProDimensionConfigGet(ProDimension *dimension,
                                      ProDrawing drawing,
                                      ProDimensionconfig *config);
/*
    Purpose: Obtains the dimension configuration.

    Input Arguments:
        dimension - The dimension.
        drawing   - The Drawing
                    Pass NULL for dimension displayed in solid.

    Output Arguments:
        config    - The dimension configuration.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - Dimension not found.
*/

extern ProError ProDimensionConfigSet(ProDimension *dimension,
                                      ProDrawing drawing,
                                      ProDimensionconfig config);
/*
    Purpose: Assigns the dimension configuration.
    Input Arguments:
        dimension - The dimension.
        drawing   - The Drawing
                    Pass NULL for dimension displayed in solid.
        config    - The dimension configuration.

    Output Arguments:
        none
]
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded 
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - Dimension not found.
*/

extern ProError ProDimensionChamferLeaderGet(ProDimension *dimension,
                                             ProDrawing drawing,
                                             ProDimChamferLeaderStyle *chamfer_leader_style);
/*
    Purpose: Obtains the chamfer dimension leader style for the chamfer   
             dimension.                                                   
                                                                          
    Input Arguments:
        dimension            - The Dimension.
        drawing              - The Drawing
                               Pass NULL for dimension displayed in solid.

    Output Arguments:
        chamfer_leader_style - The chamfer dimension leader style.
                                                                          
                                                                          
    Return Values:                                                        
        PRO_TK_NO_ERROR - The function succeeded.                         
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.      
        PRO_TK_E_NOT_FOUND - The dimension style is not chamfer.          
*/

extern ProError ProDimensionChamferLeaderSet(ProDimension* dimension,
                                             ProDrawing drawing,
                                             ProDimChamferLeaderStyle chamfer_leader_style);
/*
    Purpose: Assigns the chamfer dimension leader style for the chamfer   
             dimension.                                                   
                                                                          
    Input Arguments:
        dimension            - The Dimension.
        drawing              - The Drawing
                               Pass NULL for dimension displayed in solid.
        chamfer_leader_style - The chamfer dimension leader style.
                                                                          
    Output Arguments:                                                     
        none                                                              
                                                                          
    Return Values:                                                        
        PRO_TK_NO_ERROR - The function succeeded.                         
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.      
        PRO_TK_E_NOT_FOUND - The dimension style is not chamfer.          
*/

extern ProError ProDimensionChamferTextGet(ProDimension *dimension,
                                                ProDrawing drawing,
                                                ProDimChamferStyle *chamfer_style);
/*
    Purpose: Obtains the chamfer dimension style for the              
             chamfer dimension.                                       
                                                                      
    Input Arguments:
        dimension - The dimension.
        drawing   - Drawing where dimension is displayed.
                    Pass NULL for dimension displayed in solid.
                                                                      
    Output Arguments:                                                 
        chamfer_style - The chamfer dimension style.                  
                                                                      
    Return Values:                                                    
        PRO_TK_NO_ERROR - The function succeeded.                     
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_E_NOT_FOUND - The dimension is not a chamfer dimension.
*/


extern ProError ProDimensionChamferTextSet(ProDimension *dimension,
                                                ProDrawing drawing,
                                                ProDimChamferStyle chamfer_style);
/*
    Purpose: Assigns the chamfer dimension style for the              
             chamfer dimension.                                       
                                                                      
    Input Arguments:
        dimension     - The dimension.
        drawing       - Drawing where dimension is displayed.
                        Pass NULL for dimension displayed in solid.
        chamfer_style - The chamfer dimension style.

    Output Arguments:                                                 
          None                                                        
                                                                      
    Return Values:                                                    
        PRO_TK_NO_ERROR - The function succeeded.                     
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_E_NOT_FOUND - The dimension is not a chamfer dimension.
*/


extern ProError ProDimensionElbowSet(ProDimension* dimension,
                                     ProDrawing drawing,
                                     double elbow_length);
/*
    Purpose: Sets elbow length of the dimension.                      
                                                                      
    Input Arguments:
        dimension     - The dimension.
        drawing       - Drawing where dimension is displayed.
                        Pass NULL for dimension displayed in solid.
        elbow_length  - The elbow length.

    Output Arguments:                                                 
          None                                                        
                                                                      
    Return Values:                                                    
        PRO_TK_NO_ERROR - The function succeeded.                     
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_E_NOT_FOUND - The dimension is not a chamfer dimension.
*/

extern ProError ProDimensionDualOptionsSet (ProDimension                *dimension,
                                            ProDrawing                   drawing,
                                            ProDualDimensionDisplayType  type,
                                            ProName                      secondary_unit,
                                            int                          dim_decimals,
                                            int                          tol_decimals);
/*
   Purpose:
       Sets the dual dimension display using specified options

   Input Arguments:
       dimension     - The dimension or reference dimension handle.
       drawing       - The drawing handle. Pass NULL if not using a drawing.
       type          - Specifies how to display primary and secondary dimension.
       secondary_unit - Specifies name of the secondary dimension unit.
       dim_decimals  - Specifies number of significant digits for secondary
                       dimension; has to be non-negative.
       tol_decimals  - Specifies number of significant digits for tolerance;
                       has to be non-negative.

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded.
       PRO_TK_BAD_INPUTS  - One or more arguments is invalid.
       PRO_TK_E_NOT_FOUND - Dimension not found.
*/

extern ProError ProDimensionDualOptionsGet (ProDimension                 *dimension,
                                            ProDrawing                    drawing,
                                            ProDualDimensionDisplayType  *type,
                                            ProName                       secondary_unit,
                                            int                          *dim_decimals,
                                            int                          *tol_decimals);
/*
   Purpose:
       Gets the dual dimension display options
 
   Input Arguments:
       dimension     - The dimension or reference dimension handle.
       drawing       - The drawing handle. Pass NULL if not using a drawing.
 
   Output Arguments:
      type          - Display type of primary and secondary dimension.
      secondary_unit - Name of the secondary dimension unit. Can be NULL.
      dim_decimals  - Number of significant digits for secondary dimension.
                      Can be NULL.
      tol_decimals  - Number of significant digits for tolerance.
                      Can be NULL.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments is invalid.
*/

extern ProError ProDimensionOriginSideSet (ProDimension *dimension, 
                                           int           dim_side);

/*
    Purpose: Sets origin side to dimension

    Input Arguments:
        dimension   - The dimension      
        dim_side    - The witness line index : 1 or 2.
                      Pass -1 to remove origin set on either side.
        
    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR     - Origin side has been set.
        PRO_TK_BAD_INPUTS   - The dimension object is invalid.       
        PRO_TK_NO_CHANGE    - The dimension already have origin set on specified side.
        PRO_TK_INVALID_TYPE - The dimension can't have origin side        
*/
extern ProError ProDimensionOriginSideGet (ProDimension *dimension,
                                           int          *dim_side);

/*
    Purpose: Identify if dimension has an origin side

    Input Arguments:
        dimension   - The dimension             
        
    Output Arguments:
        dim_side    - The witness line index : 1 or 2. 
                      Function will return -1 if dimension has no origin side                      

    Return Values:
        PRO_TK_NO_ERROR     - Successfully retrieved information.
        PRO_TK_BAD_INPUTS   - The dimension object is invalid.
        PRO_TK_E_NOT_FOUND  - The Dimension has no origin side
        PRO_TK_INVALID_TYPE - The dimension can't have origin side.       

*/ 

extern ProError ProDimensionAdditionalRefsAdd( ProDimension             *dim, 
                                               ProDimensionReferenceType type,
                                               ProAnnotationReference    *refs );
/*
   Purpose:   Add dimension references

   Input Arguments:
     dim   - valid dimension. 
	   type  - type of reference. FIRST or SECOND.
	   refs  - ProArray of references. Currently it supports PRO_ANNOT_REF_SINGLE only.

   Output Arguments:      

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProDimensionAdditionalRefsGet( ProDimension             *dim, 
                                               ProDimensionReferenceType type,
                                               ProAnnotationReference  **refs );
/*
   Purpose:   Get dimension references

   Input Arguments:
   dim  - valid dimension. 
   type - type of reference. FIRST or SECOND.   

   Output Arguments:      
	refs  - ProArray of references. Free this using ProArrayFree();
			Currently it supports PRO_ANNOT_REF_SINGLE only.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProDimensionAdditionalRefDelete( ProDimension             *dim, 
                                                 ProDimensionReferenceType type,
                                                 int                       index );
/*
   Purpose:   Delete dimension reference

   Input Arguments:
      dim    - valid dimension. 
	    type   - type of reference. FIRST or SECOND.
      index  - Indices start from 0. Get existing references from ProDimensionAdditionalRefsGet()

   Output Arguments:       

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProDimensionDisplayFormatSet (ProDimension *dimension,
                                              ProDimensionDisplayFormat  type);
    
/*
    Purpose: Set format display of dimension.

    Input Arguments:
        dimension        - The dimension handle.
        type             - The dimension format type.

    Output Arguments:
        

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the format type.      
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProDimensionDisplayFormatGet (ProDimension *dimension,
                                              ProDimensionDisplayFormat  *type);
    
/*
    Purpose: Get format display of dimension.

    Input Arguments:
        dimension        - The dimension handle.

    Output Arguments:
        type             - The dimension format type.

    Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned format type. 
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

PRO_END_C_DECLS

#endif
