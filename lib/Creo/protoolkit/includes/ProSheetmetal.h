#ifndef	PROSHEETMETAL_H
#define	PROSHEETMETAL_H


#include	<ProObjects.h>
#include        <ProFaminstance.h>

/*
   Creo Parametric TOOLKIT declarations related to sheetmetal.
*/
 




PRO_BEGIN_C_DECLS


typedef enum pro_smt_surf_types
{
   PRO_SMT_SURF_NON_SMT	= 0,	/* surface created by solid feature	*/
   PRO_SMT_SURF_SIDE	= 1,	/* side surface created by smt feature	*/
   PRO_SMT_SURF_FACE	= 2,	/* face (green) surface created by smt	*/
				/* feature				*/
   PRO_SMT_SURF_OFFSET	= 3	/* offset (white) surface created by smt*/
				/* feature				*/
} ProSmtSurfType;


typedef enum pro_smt_dev_len_method
{
  PRO_DVL_LEN_DRIVEN_BY_UNKNOWN		= 0,

  PRO_DVL_LEN_DRIVEN_BY_Y_FACTOR	= 1,
  /* A developed length value is calculated using Y-factor or K-factor. */

  PRO_DVL_LEN_DRIVEN_BY_BEND_TABLE	= 2,
  /* A bend allowance (A) value for 90 degrees is found or interpolated from
     a bend table for given thickness and inside radius. A developed length (L)
     is calculated using a formula from Conversion section of the bend table.
     If Conversion section is missing, L = A. */

  PRO_DVL_LEN_DRIVEN_BY_FORMULA		= 3,
  /* A developed length (L) is calculated using a formula from Formula section
     of a bend table. */

  PRO_DVL_LEN_DRIVEN_BY_DIMENSION	= 4
  /* A developed length value is specified by a user in a dimension. */

} ProDvlLenMethod;


typedef struct _ProSmtDvlLenCalcInfo
{
  ProDvlLenMethod	  method;
  ProMdl		  model;	/* Model that rules developed length. */
  double		  y_factor_value;
  ProName		  bend_table;
  ProLine		  formula;	/* Formula that is used to calculate
					   developed length. */
  double		  allowance;	/* Bend allowance (A) from bend table.*/
  ProDimension		  dimension;
  ProBool		  driven_by_part_settings;

} ProSmtDvlLenCalcInfo;


/*======================================================================*/
 
extern ProError ProSmtSurfaceTypeGet(
   ProPart		sheetmetal_part,
   ProSurface		surface,
   ProSmtSurfType	*r_smt_surf_type );

/*
   Purpose: Returns the type of the sheet metal surface.

   Input Arguments:
      sheetmetal_part	- The sheet metal part
      surface           - The surface to check

   Output Arguments:
      r_smt_surf_type	- The type of sheet metal surface

   Return Values:
      PRO_TK_NO_ERROR 	 - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid..
      PRO_TK_BAD_CONTEXT - Input argument is not a sheetmetal part

*/

/*======================================================================*/

extern ProError ProSmtedgeContourGet(
   ProPart		smt_part,
   ProEdge		edge,
   ProEdge		**edges );

/*
   Purpose:	Outputs an array of edges that form the complete contour of
		the entire green (or white) surface that contains the
		specified edge.

   Input Arguments:
      smt_part		- The sheet metal part
      edge  		- The edge (on white or green surface) that is
			  contained in the contour sought.

   Output Arguments:
      edges		- Pointer to ProArray of edges. The edges are
			  ordered exactly as for a regular surface contour.
			  The array will be allocated and filled by
			  Creo Parametric. Free it by calling ProArrayFree()
			  when you no longer need it.

   Return Values:
      PRO_TK_NO_ERROR	 - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS	 - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part, or the
			   specified edge is not on the green or white surface.
*/

/*======================================================================*/

extern ProError ProSmtOppedgeGet(
   ProPart		smt_part,
   ProEdge		edge,
   ProEdge		*opposing_edge );

/*
   Purpose:	Outputs the edge on the white (or green) face which
		opposes the one specified on the green (or white) face.

   Input Arguments:
      smt_part		- The sheet metal part
      edge		- The edge whose opposing edge is to be found.

   Output Arguments:
      opposing_edge	- The opposing edge

   Return Values:
      PRO_TK_NO_ERROR	 - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS	 - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part.
      PRO_TK_E_NOT_FOUND - There is no matching edge.
*/

/*======================================================================*/

extern ProError ProSmtOppsurfGet(
   ProPart		smt_part,
   ProSurface		surface,
   ProSurface		*opposing_surf );

/*
   Purpose:	Outputs the surface on the white (or green) face which
		opposes the one specified on the green (or white) face.

   Input Arguments:
      smt_part		- The sheet metal part
      surface		- The surface whose opposing surface is to be found.

   Output Arguments:
      opposing_surf	- The opposing surface

   Return Values:
      PRO_TK_NO_ERROR	 - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS	 - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part.
      PRO_TK_E_NOT_FOUND - There is no matching surface.
*/

/*======================================================================*/

extern ProError ProSmtBendsrfParentGet(
   ProPart		smt_part,
   ProSurface		surface,
   ProSurface		*parent );

/*
   Purpose:	Provides the most recent unbent (bent) equivalent to a
		specified surface in a currently bent (unbent) bend.

   Input Arguments:
      smt_part		- The sheet metal part
      surface		- The bend surface

   Output Arguments:
      parent		- The most recent unbent (bent) equivalent to
			  the specified (bent) unbent surface.

   Return Values:
      PRO_TK_NO_ERROR	 - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part, or the surface
			   is not a bend surface.
*/

/*======================================================================*/

extern ProError ProSmtBendsrfChildGet(
   ProPart		smt_part,
   ProSurface		surface,
   ProSurface		*child );

/*
   Purpose:	Provides the active child surface of a sheet metal
		surface which is currently inactive due to subsequent
		bends/unbends.

   Input Arguments:
      smt_part		- The sheet metal part
      surface		- The surface

   Output Arguments:
      child		- The active child of the specified invisible surface.

   Return Values:
      PRO_TK_NO_ERROR	 - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part.
      PRO_TK_E_NOT_FOUND - input surface is inactive, but there is no active
			   bent/unbent child
*/

/*======================================================================*/

extern ProError ProSmtBendsrfInfoGet ( 
   ProPart              smt_part,
   ProSurface           surface,
   double		*radius,
   ProBool		*is_inside_radius,
   double		*angle,
   double		*dev_length,
   ProSmtDvlLenCalcInfo	*dev_len_info );
/*
   Purpose:	Collects information about sheetmetal bend surface.

   Input Arguments:
      smt_part	- The sheetmetal part.
      surface	- The sheetmetal bend surface of PRO_SMT_SURF_FACE or
		  PRO_SMT_SURF_OFFSET type. Only cylindrical surfaces and
                  planar surfaces created by unbend of cylindrical surfaces
                  are allowed. The surface might be inactive.

   Output Arguments:
      radius		- Bend radius. Pass NULL if this data is not needed.
      is_inside_radius	- If PRO_B_TRUE, the radius is inside.
			  If PRO_B_FALSE, the radius is outside.
			  Pass NULL if this data is not needed.
      angle		- Bend angle in degrees.
			  Pass NULL if this data is not needed.
      dev_length	- Developed length of surface.
			  Pass NULL if this data is not needed.
      dev_len_info	- Development length info.
			  Pass NULL if this data is not needed.

   Return Values:
      PRO_TK_NO_ERROR	   - The function collected all required information.
      PRO_TK_BAD_INPUTS	   - The model is not a sheet metal part or
                             the surface is not a bend sutface.
      PRO_TK_BAD_CONTEXT-    The bend table that is used to calculate
			     the developed length is invalid or
			     the bend table formula can't be calculated.
      PRO_TK_NOT_VALID	   - The developed length is zero or negative.
      PRO_TK_GENERAL_ERROR - Some other error.
*/

/*======================================================================*/

extern ProError ProSmtBendedgeParentGet(
   ProPart		smt_part,
   ProEdge		edge,
   ProEdge		*parent );

/*
   Purpose:	Provides the most recent unbent (bent) equivalent to a specified
		edge in a currently bent (unbent) bend.

   Input Arguments:
      smt_part		- The sheet metal part
      edge		- The bend edge

   Output Arguments:
      parent		- The most recent unbent (bent) equivalent to
			  the specified (bent) unbent edge.

   Return Values:
      PRO_TK_NO_ERROR    - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part, or the edge
			   is not a bend edge.
*/

/*======================================================================*/

extern ProError ProSmtBendedgeChildGet(
   ProPart		smt_part,
   ProEdge		edge,
   ProEdge		*child );

/*
   Purpose:	Provides the active child edge of a sheet metal
		edge which is currently inactive due to subsequent
		bends/unbends.

   Input Arguments:
      smt_part		- The sheet metal part
      edge		- The edge

   Output Arguments:
      child		- The active child of the specified invisible edge.
			  (If the input edge is itself active,
			  the same edge will be output.)

   Return Values:
      PRO_TK_NO_ERROR    - The function sucessfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The model is not a sheet metal part.
      PRO_TK_E_NOT_FOUND - input edge is inactive, but there is no active
			   bent/unbent child
*/

/*======================================================================*/


extern ProError ProSmtPartThicknessGet(
   ProPart smt_part,
   ProDimension *thickness);

/*
  Purpose: Outputs the dimension which defines the thickness of
	a sheet metal part.

  Input Arguments:
     smt_part - The sheet metal part

  Output Arguments:
     thickness - The handle to the dimension that specifies
the thickness.

  Return Values:
     PRO_TK_NO_ERROR   - The function sucessfully retrieved the information.
     PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid..
     PRO_TK_BAD_CONTEXT - The model is not a sheet metal part.
*/

/*======================================================================*/


extern ProError ProSmtPartBendtableApply(
        ProPart smt_part,
        ProName bend_name,
        ProBoolean from_file);

/*
   Purpose: Applies a specified bend table to a sheet metal part and
                causes a regeneration.

   Input Arguments:
      smt_part         - The sheet metal part
      bend_name        - The name of the bend table
                          The name of the bend table has to be specified
                          without the extension .bnd of the bend table file.
                          Set the config option "pro_sheet_met_dir" to point
                          to the directory that contains the bend tables. 
      from_file        - If PRO_B_TRUE, the table is loaded from the file,
                         and supersedes any table that is already in memory.
                         If PRO_B_FALSE, the table is loaded from the file
                         only if it is not already in memory.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_CONTEXT        - The part is not sheet metal
      PRO_TK_CANT_OPEN          - Couldn't find such a table in memory,
                                  nor could open the file.

======================================================================*/


extern ProError ProSmtPartBendtableRemove( ProPart smt_part );

/*
   Purpose: Removes the part bend table, so the Y-factor will be used
                instead. Also causes a regeneration.

   Input Arguments:
      smt_part              - The sheet metal part

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_CONTEXT        - The part is not sheet metal
      
      
======================================================================*/



extern ProError ProSmtFeatureBendtableApply(
        ProFeature *feature,
        ProName bend_name,
        ProBoolean from_file);

/*
   Purpose: Applies a specified bend table to a sheet metal part feature
                and causes a regeneration.

   Input Arguments:
      feature           - The sheet metal feature (must be a bend or wall)
      bend_name         - The name of the bend table.
      from_file         - If TRUE, the table is loaded from file, even if
                                it is already in memory.
                          If FALSE, the table is loaded from file only if
                                it is not already in memory.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_CONTEXT        - The feature is not a bend or wall.
      PRO_TK_CANT_OPEN          - Couldn't find such a table in memory,
                                        nor could open the file.
					
					
======================================================================*/


extern ProError ProSmtFeatureBendtableRemove( ProFeature *feature );

 /*
    Purpose: Sets a sheet metal feature to use the part bend table instead of a
                 feature bend table. Also causes a regeneration.

    Input Arguments:
       feature           - The sheet metal feature (must be a bend or wall)

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR
       PRO_TK_BAD_CONTEXT        - The feature is not a bend or wall.

======================================================================*/




extern ProError ProSmtFeatureDevldimsGet(
     ProFeature *feature,
     ProDimension **devl_dims,
     ProGeomitem **surfaces );

 /*
    Purpose: Outputs the DEV.L dimensions for the specified sheet
                 metal feature, and the corresponding surfaces whose
                 developed lengths they define.

    Input Arguments:
       feature           - The sheet metal feature (must be a Bend or Wall)

    Output Arguments:
       devl_dims         - The DEV.L dimensions. This is a ProArray allocated
                                 by the function. Free it using ProArrayFree().
       surfaces          - The surfaces referenced by the DEV.L dimensions.
                                 This is also a ProArray allocated by the
                                 function.

    Return Values:
       PRO_TK_NO_ERROR
       PRO_TK_BAD_CONTEXT
       
======================================================================*/


extern ProError ProSmtDevldimIsDriven(
     ProDimension *devl_dim,
     ProBoolean *driven);

 /*
    Purpose: Tells whether the specified DEV.L dimension
                 is currently driven.

    Input Arguments:
       devl_dim          - The DEV.L dimension

    Output Arguments:
       driven            - Whether driven

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_CONTEXT
	PRO_TK_BAD_INPUTS	 - any of input arg is NULL

======================================================================*/


extern ProError ProSmtDevldimDrivenSet(
     ProDimension *devl_dim,
     ProBoolean driven);

 /*
    Purpose: Sets whether the specified DEV.L dimension
                 is currently driven.

    Input Arguments:
       devl_dim          - The DEV.L dimension
       driven            - Whether driven

    Output Arguments:
        None

    Return Values:
       	PRO_TK_NO_ERROR
       	PRO_TK_BAD_CONTEXT 
	PRO_TK_BAD_INPUTS	 - devl_dim eq. NULL
	
======================================================================*/      


extern ProError ProSmtMdlIsFlatStateInstance ( 
  ProMdl smt_model, 
  ProBoolean *is_instance_model, 
  ProMdl *generic_model ); 


 /* 
 Purpose: Checks if the model is a sheetmetal flat state instance model 

 Input Arguments: 
       smt_model - model to be checked, if it is a flat state instance 

 Output Arguments: 
       is_instance_model -  PRO_B_TRUE if smt_model is a sheetmetal flat instance model,
					PRO_B_FALSE  otherwise

 generic_model - handle to the generic model, if is_instance_model is PRO_B_TRUE 
   

 Return Values: 

      PRO_TK_NO_ERROR        - The function is successful 
      PRO_TK_BAD_INPUTS      - The input argument is invalid. 
      PRO_TK_BAD_CONTEXT     - The model is not of sheetmetal type 

 =====================================================================*/ 


extern ProError ProFaminstanceIsFlatState ( 
  ProFaminstance  *instance, 
  ProBoolean *is_flat_instance );


 /*
 Purpose: Checks if the family instance is a sheetmetal flat state instance or not. 

 Input Arguments: 
 instance          - handle to the flate state instance 

 Output Arguments: 
 is_flat_instance  -  PRO_B_TRUE    -  instance is a flat state instance 
                      PRO_B_FALSE   -  instance is not a flat state instance 

 Return Values: 

      PRO_TK_NO_ERROR       - The function successfully checked the 
                              instance to be flat
 state or not 
      PRO_TK_BAD_INPUTS  - The input argument is invalid. 
      PRO_TK_BAD_CONTEXT - The instance is not of flat state type, but 
                           normal family table
 instance 
 ===========================================================================*/ 


PRO_END_C_DECLS

#endif /* PROSHEETMETAL_H */
