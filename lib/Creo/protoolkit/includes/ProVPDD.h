#ifndef PROVPDDH
#define PROVPDDH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

  PRO_E_FEATURE_TREE
      |
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_VPDD_PULL_DIR_CMP
      |    |   
      |    |-- PRO_E_VPDD_PULL_DIR_REF
      |    |   
      |    |-- PRO_E_VPDD_PULL_DIR_FLIP
      |      
      |-- PRO_E_VPDD_SETS_ARR
      |    |   
      |    |-- PRO_E_VPDD_SET_CMP
      |         |
      |         |-- PRO_E_VPDD_HINGES_ARR
      |         |    |
      |         |    |-- PRO_E_VPDD_HINGE_CMP
      |         |         |
      |         |         |-- PRO_E_STD_CURVE_COLLECTION_APPL 
      |         |         |
      |         |         |-- PRO_E_VPDD_HINGE_FLIP 
      |         |
      |         |-- PRO_E_VPDD_SPLIT_SRFS_OPTS
      |         |     
      |         |-- PRO_E_VPDD_SPLIT_SRFS_REFS
      |         |  
      |         |-- PRO_E_VPDD_CONST_OR_VAR
      |         |
      |         |-- PRO_E_VPDD_ANGLES_AND_POINTS_ARR
      |              |
      |              |-- PRO_E_VPDD_POINT_AND_ANGLES_CMP
      |                   |
      |	                 |-- PRO_E_STD_POINT_COLLECTION_APPL  
      |                   |     
      |                   |-- PRO_E_VPDD_ANGLES_ARR
      |                        |
      |	        	             |-- PRO_E_VPDD_ONE_ANGLE_CMP
      |                             |
      |	        	                  |-- PRO_E_VPDD_ANG_VAL 
      |
      |-- PRO_E_VPDD_ATTACH_OPTS
      |
      |-- PRO_E_VPDD_EXTENT_CMP 
           |
           |-- PRO_E_VPDD_EXT_OPTS
           |
           |-- PRO_E_VPDD_EXT_LENGTH
           |
           |-- PRO_E_VPDD_EXT_REF
    
===============================================================================

(2) Feature elements table

-----------------------------------------------------------------------------------------------
Element Id                     Element Name              Data Type                    Valid Values
-----------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type           PRO_VALUE_TYPE_INT           PRO_FEAT_VPDD
PRO_E_STD_FEATURE_NAME            Feature Name           PRO_VALUE_TYPE_WSTRING       Wide character string
PRO_E_VPDD_PULL_DIR_CMP           Pull direction         Compound
PRO_E_VPDD_PULL_DIR_REF           Reference              PRO_ELEM_TYPE_MULTI_VALUE    Note-1 
PRO_E_VPDD_PULL_DIR_FLIP          Flip                   PRO_VALUE_TYPE_BOOLEAN       TRUE/FALSE 
PRO_E_VPDD_SETS_ARR               Sets                   Array
PRO_E_VPDD_SET_CMP                Set                    Compound
PRO_E_VPDD_HINGES_ARR             Hinges                 Array
PRO_E_VPDD_HINGE_CMP              Hinge                  Compound
PRO_E_STD_CURVE_COLLECTION_APPL   Chain                  PRO_VALUE_TYPE_SELECTION
PRO_E_VPDD_HINGE_FLIP             Hinge Flip             PRO_VALUE_TYPE_BOOLEAN       TRUE/FALSE
PRO_E_VPDD_SPLIT_SRFS_OPTS        Split                  PRO_VALUE_TYPE_BOOLEAN       TRUE/FALSE, Note-2
PRO_E_VPDD_SPLIT_SRFS_REFS        Splitting Surfaces     PRO_ELEM_TYPE_MULTI_VALUE    Note-3
PRO_E_VPDD_CONST_OR_VAR           Constant or variable   PRO_ELEM_TYPE_OPTION         Pro_vpdd_const_var_type, Note-4 
PRO_E_VPDD_ANGLES_AND_POINTS_ARR  Angles and points      Array
PRO_E_VPDD_POINT_AND_ANGLES_CMP   Point and angles       Compound
PRO_E_STD_POINT_COLLECTION_APPL   Point                  PRO_VALUE_TYPE_SELECTION     
PRO_E_VPDD_ANGLES_ARR             Angles                 Array                        Note-5
PRO_E_VPDD_ONE_ANGLE_CMP          Angle                  Compound
PRO_E_VPDD_ANG_VAL                Value                  PRO_VALUE_TYPE_DOUBLE        [-90:90]
PRO_E_VPDD_ATTACH_OPTS            Attachment type        PRO_ELEM_TYPE_OPTION         Pro_vpdd_attach_type
PRO_E_VPDD_EXTENT_CMP             Extent                 Compound                     Note-8
PRO_E_VPDD_EXT_OPTS               Type                   PRO_ELEM_TYPE_OPTION         Pro_vpdd_extent_type, Note-6
PRO_E_VPDD_EXT_LENGTH             Length                 PRO_VALUE_TYPE_DOUBLE        
PRO_E_VPDD_EXT_REF                Bottom Surface         PRO_VALUE_TYPE_SELECTION     Note-7
===============================================================================

(3) Notes

   Note-1 : The valid references are either a single PRO_QUILT or a single PRO_DATUM_PLANE or a single PRO_LOG_SRF or 
            multiple PRO_SURFACE references tangent to each other.
   
   Note-2 : If the node's value is FALSE the node PRO_E_VPDD_SPLIT_SRFS_REFS becomes invisible. 
            The default value is FALSE.
   
   Note-3 : The node can contain upto 2 references that are either PRO_QUILT or PRO_DATUM_PLANE. 
   
   Note-4 : If the node's value is PRO_VPDD_CONST the node PRO_E_STD_POINT_COLLECTION_APPL becomes invisible and  
            the array PRO_E_VPDD_ANGLES_AND_POINTS_ARR shall contain only a single element.          
   
   Note-5 : The size of the angles array is 1 + the number of split references. 
   
   Note-6 : If the node's value is PRO_VPDD_EXT_LENGTH the node PRO_E_VPDD_EXT_LENGTH becomes visible.
            If the node's value is PRO_VPDD_EXT_TO_SEL the node PRO_E_VPDD_EXT_REF becomes visible.
            Otherwise, the nodes PRO_E_VPDD_EXT_LENGTH and PRO_E_VPDD_EXT_REF are invisible.
    
   Note-7 : The valid references are PRO_QUILT, PRO_SURFACE, PRO_DATUM_PLANE.
   
   Note-8 : The node is visible only if PRO_E_VPDD_ATTACH_OPTS node's value is PRO_VPDD_ATTACH_NEW_QUILT.  
==============================================================================*/

typedef enum pro_vpdd_const_var_type
{
   PRO_VPDD_CONST = 0,
   PRO_VPDD_VAR   = 1
} 
Pro_vpdd_const_var_type;

typedef enum pro_vpdd_attach_type
{
   PRO_VPDD_ATTACH_NEW_QUILT     = -1,
   PRO_VPDD_ATTACH_SAME_QUILT    =  0
} 
Pro_vpdd_attach_type;

typedef enum pro_vpdd_extent_type
{
   PRO_VPDD_EXT_LENGTH        = 3,
   PRO_VPDD_EXT_TO_SEL        = 4,
   PRO_VPDD_EXT_TO_NEXT       = 5,
   PRO_VPDD_EXT_UNATTACHED    = 6
} 
Pro_vpdd_extent_type;

PRO_END_C_DECLS

#endif
