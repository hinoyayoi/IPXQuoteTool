#ifndef PROREGULARUNBENDH
#define PROREGULARUNBENDH

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Regular Unbend feature
*/




#include <ProToolkit.h>


PRO_BEGIN_C_DECLS

/*****************************************************************************

Feature element tree:

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_UNBEND_TYPE
     |
     |--PRO_E_SMT_UNBEND_SUB_TYPE
     |				
     |--PRO_E_SMT_PRIMARY_FIXED_GEOM
     |    |
     |    |--PRO_E_SMT_FIXED_REF
     |    |
     |    |--PRO_E_SMT_FIXED_REF_SIDE
     |
     |--PRO_E_SMT_UNBEND_REF_ARR
     |    |			
     |    |--PRO_E_SMT_UNBEND_REF
     |         |
     |         |--PRO_E_SMT_UNBEND_SINGLE_REF
     |                                        
     |--PRO_E_SMT_DEFORM_SURFACES
     |    |
     |    |--PRO_E_STD_SURF_COLLECTION_APPL
     |
     |--PRO_E_SMT_ADD_CORNER_RELIEFS_OPTS
     |    |
     |    |--PRO_E_SMT_ADD_CORNER_RELIEFS
     |    |
     |    |--PRO_E_SMT_ADD_CORNER_RELIEFS_TYPE
     |
     |--PRO_E_SMT_FLATTEN_FORM_WALLS
     |
     |--PRO_E_SMT_FLATTEN_ALL_FORMS
     |
     |--PRO_E_SMT_FLATTEN_PROJ_CUTS
     |
     |--PRO_E_SMT_MERGE_SAME_SIDES

*****************************************************************************



===============================================================================
Element Id                        Element Name            Data Type
===============================================================================
PRO_E_FEATURE_TYPE		  Feature Type	          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME		  Feature Name            PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_UNBEND_TYPE		  Unbend Type             PRO_VALUE_TYPE_INT
PRO_E_SMT_UNBEND_SUB_TYPE         Auto/Select Unbend      PRO_VALUE_TYPE_INT
PRO_E_SMT_PRIMARY_FIXED_GEOM      Primary fixed geom      Compound
PRO_E_SMT_FIXED_REF		  Fixed Geom or Edge      PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_FIXED_REF_SIDE	  Fixed Side for Edge     PRO_VALUE_TYPE_INT
PRO_E_SMT_UNBEND_REF_ARR	  Geometry arr to unbend  Array
PRO_E_SMT_UNBEND_REF		  Reference to unbend     Compound
PRO_E_SMT_UNBEND_SINGLE_REF	  Reference to unbend     PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_DEFORM_SURFACES         Deformation surfaces    Compound
PRO_E_STD_SURF_COLLECTION_APPL	  Deformation surfaces    Surface collection
PRO_E_SMT_ADD_CORNER_RELIEFS_OPTS Add corner reliefs opts Compound
PRO_E_SMT_ADD_CORNER_RELIEFS	  Add corner reliefs      PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_ADD_CORNER_RELIEFS_TYPE Add corner reliefs type PRO_VALUE_TYPE_INT
PRO_E_SMT_FLATTEN_FORM_WALLS      Unbend form geometry    PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_FLATTEN_ALL_FORMS	  Flatten all forms       PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_FLATTEN_PROJ_CUTS       Project form cuts       PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_MERGE_SAME_SIDES        Merge colocated sides   PRO_VALUE_TYPE_BOOLEAN

*****************************************************************************



===============================================================================
Element Id                        	Valid Values
===============================================================================
PRO_E_FEATURE_TYPE                	PRO_FEAT_UNBEND    ( Not redefinable )
PRO_E_SMT_UNBEND_TYPE		  	ProSmtUnbendType   ( Not redefinable )
PRO_E_SMT_UNBEND_SUB_TYPE               ProUnbendSubType
PRO_E_SMT_FIXED_REF		  	Surface, Edge
PRO_E_SMT_FIXED_REF_SIDE		ProSmtFixedRefSide
PRO_E_SMT_UNBEND_SINGLE_REF		Surface, Edge, Intent surface/chain
PRO_E_STD_SURF_COLLECTION_APPL		Surfaces, Intent surfaces.
PRO_E_SMT_ADD_CORNER_RELIEFS		PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_ADD_CORNER_RELIEFS_TYPE       ProSmtAddCornRelType
PRO_E_SMT_FLATTEN_FORM_WALLS            PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_FLATTEN_ALL_FORMS		PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_FLATTEN_PROJ_CUTS             PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_MERGE_SAME_SIDES              PRO_B_TRUE, PRO_B_FALSE

*****************************************************************************/



/* PRO_E_SMT_UNBEND_TYPE */
typedef enum pro_smt_unbend_type
{
  PRO_SMT_REGULAR_UNBEND	=  1,
  PRO_SMT_FLAT_PATTERN		=  2
  
} ProSmtUnbendType;


/* PRO_E_SMT_UNBEND_SUB_TYPE */
typedef enum _ProUnbendSubType
{
  PRO_UNBEND_SUB_TYPE_UNDEF  = -1,
  PRO_UNBEND_ALL             =  0,
  PRO_UNBEND_SELECTED        =  1

} ProUnbendSubType;


/* PRO_E_SMT_FIXED_REF_SIDE */
typedef enum _ProSmtFixedRefSide
{
  PRO_SMT_FIXED_SIDE_UNDEF      = -1, /* Side Not Applicable ( e.g Surface ) */
  PRO_SMT_FIXED_SIDE_ONE        =  1, /* Edge Side Flipped                   */
  PRO_SMT_FIXED_SIDE_TWO        =  2  /* Edge Side Not Flipped               */

} ProSmtFixedRefSide;


/* PRO_E_SMT_ADD_CORNER_RELIEFS_TYPE */
typedef enum _ProSmtAddCornRelType
{
  PRO_SMT_ADD_CORN_REL_UNDEF       = -1,
  PRO_SMT_ADD_CORN_REL_BY_FLAT_PAT =  0,
  PRO_SMT_ADD_CORN_REL_BY_PARAMS   =  1

} ProSmtAddCornRelType;


PRO_END_C_DECLS


#endif	/* PROREGULARUNBENDH */
