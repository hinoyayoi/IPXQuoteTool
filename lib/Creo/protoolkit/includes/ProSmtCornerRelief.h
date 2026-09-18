#ifndef PROSMTCORNERRELIEF_H
#define PROSMTCORNERRELIEF_H


/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Corner Relief feature
*/




#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/********************************************************************************

PRO_E_FEATURE_TREE
  |
  |-- PRO_E_STD_FEATURE_NAME
  |
  |-- PRO_E_CORNER_RELIEFS (compound)
      |
      |-- PRO_E_CORNER_RELIEFS_CR_STATE (option)
      |
      |-- PRO_E_CORNER_RELIEFS_ARR (array)
  	  |
	  |-- PRO_E_CORNER_RELIEF_SET (compound)
	      |
	      |-- PRO_E_CORNER_RELIEF_REF_ARR (array)
	      |   |
	      |   |-- PRO_E_CORNER_RELIEF_REF_SET (compound)
	      |       |
	      |       |-- PRO_E_CORNER_RELIEF_REF_TYPE (option)
	      |       |
	      |       |-- PRO_E_CORNER_RELIEF_REF_FLAT (geom)
	      |       |
	      |       |-- PRO_E_CORNER_RELIEF_REF_BND_1 (geom)
	      |       |
	      |       |-- PRO_E_CORNER_RELIEF_REF_BND_2 (geom)
	      |
	      |-- PRO_E_CORNER_RELIEF_DEFINE (compound)
	          |
		  |-- PRO_E_SMT_CORNER_RELIEF (compound)
		      |
		      |-- PRO_E_SMT_CORNER_RELIEF_TYPE (option)
		      |
		      |-- PRO_E_SMT_CORNER_RELIEF_WIDTH (compound)
		      |   |
		      |	  |-- PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE (option)
		      |   |
		      |   |-- PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL (double)
		      |
		      |-- PRO_E_SMT_CORNER_RELIEF_DEPTH (compound)
		      |   |
		      |   |-- PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE (option)
		      |	  |
		      |	  |-- PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL (double)
		      |
		      |-- PRO_E_SMT_CORNER_RELIEF_ROTATE (compound)
		      |	  |
		      |   |-- PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD (option)
		      |   |
		      |   |-- PRO_E_SMT_CORNER_RELIEF_ROTATE_VAL (double)
		      |
		      |-- PRO_E_SMT_CORNER_RELIEF_OFFSET (compound)
		      |	  |
		      |   |-- PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD (option)
		      |	  |
		      |	  |-- PRO_E_SMT_CORNER_RELIEF_OFFSET_VAL (double)
		      |
      		      |-- PRO_E_CORNER_RELIEFS_DIM_SCHEME (option)

*******************************************************************

================================================================================
Element Id                           	Element Name 		Data Type
================================================================================
PRO_E_STD_FEATURE_NAME       	     	Feature Name  		PRO_VALUE_TYPE_WSTRING
PRO_E_CORNER_RELIEFS		     	Corner reliefs 		compound
PRO_E_CORNER_RELIEFS_CR_STATE 	     	Create state		PRO_VALUE_TYPE_INT
PRO_E_CORNER_RELIEFS_DIM_SCHEME      	Dimension scheme	PRO_VALUE_TYPE_INT
PRO_E_CORNER_RELIEFS_ARR 		Corner sets array	Array
PRO_E_CORNER_RELIEF_SET 		Corner set		compound
PRO_E_CORNER_RELIEF_REF_ARR 		Corner references array	Array
PRO_E_CORNER_RELIEF_REF_SET 		Corner reference	compound
PRO_E_CORNER_RELIEF_REF_TYPE 		Reference type		PRO_VALUE_TYPE_INT
PRO_E_CORNER_RELIEF_REF_FLAT 		Flat surface reference	PRO_VALUE_TYPE_SELECTION
PRO_E_CORNER_RELIEF_REF_BND_1 		First Bend surface	PRO_VALUE_TYPE_SELECTION
PRO_E_CORNER_RELIEF_REF_BND_2 		Second Bend surface	PRO_VALUE_TYPE_SELECTION
PRO_E_CORNER_RELIEF_DEFINE 		Corner definition	compound
PRO_E_SMT_CORNER_RELIEF 		Corner Relief		compound
PRO_E_SMT_CORNER_RELIEF_TYPE 		Corner Relief Type	PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_WIDTH 		Corner Relief Width	compound
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE     Corner Relief Width Type PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL 	Corner Relief Width Val	PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_DEPTH 		Corner Relief Depth	compound
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE     Corner Relief Depth Type PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL 	Corner Relief Depth Val	PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_ROTATE 		Rotate			compound
PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD	Add Rotate		PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_ROTATE_VAL	Rotate Value		PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_OFFSET 		Offset			compound
PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD	Add Offset		PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_OFFSET_VAL	Offset Value		PRO_VALUE_TYPE_DOUBLE



================================================================================
Element Id                        	Valid Values
================================================================================
PRO_E_CORNER_RELIEFS_CR_STATE 	     	ProCrnRelCrState
PRO_E_CORNER_RELIEFS_DIM_SCHEME      	ProCrnRelDimRefType
PRO_E_CORNER_RELIEF_REF_TYPE 		ProCrnRelRefType
PRO_E_CORNER_RELIEF_REF_FLAT 		Flat Surface	
PRO_E_CORNER_RELIEF_REF_BND_1 		Cylinder Surface
PRO_E_CORNER_RELIEF_REF_BND_2 		Cylinder Surface
PRO_E_SMT_CORNER_RELIEF_TYPE 		ProCornerRelType	
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE     	ProSmdRelType
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE  ProCornerRlfDepthType 
PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD	PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD	PRO_B_TRUE, PRO_B_FALSE


*/


typedef enum
{
  PRO_CRN_REL_3_SURFACES		= 0,
  PRO_CRN_REL_ALL 			= 1

} ProCrnRelRefType;


typedef enum
{
  PRO_CRN_REL_CR_IN_FORMED 		= 0 ,
  PRO_CRN_REL_CR_IN_UNBEND_ONLY 	= 1 

} ProCrnRelCrState;

typedef enum
{
  PRO_CRN_REL_DIM_REF_BEND_AXES_XSECTION = 0,
  PRO_CRN_REL_DIM_REF_CORNER_VERTEX = 2 

} ProCrnRelDimRefType;



PRO_END_C_DECLS

#endif
