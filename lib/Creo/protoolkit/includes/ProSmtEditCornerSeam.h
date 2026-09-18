#ifndef PROEDITCORNERSEAM_H
#define PROEDITCORNERSEAM_H



#include <ProToolkit.h>
#include <ProRound.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_STD_FEATURE_NAME
    |
    |--PRO_E_EDIT_CORNER_SEAM
         |
         |--PRO_E_EDIT_CORNER_SEAM_SEL_MODE
         |
         |--PRO_E_EDIT_CORNER_SEAM_GEOMS
         |
         |--PRO_E_REMOVE_CORNER_SEAM
         |
         |--PRO_E_EDIT_BEND_RCR_CRNR         |
         |
         |--PRO_E_EDIT_CORNER_SEAM_SHAPE
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_TYPE
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_ADD_GAP
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_CLOSE_CORNER
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_DIM_1
         |   |   |
         |   |   |--PRO_E_SMT_DIMENSION_TYPE
         |   |   |
         |   |   |--PRO_E_SMT_DIMENSION_VALUE
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_DIM_2
         |   |   |
         |   |   |--PRO_E_SMT_DIMENSION_TYPE
         |   |   |
         |   |   |--PRO_E_SMT_DIMENSION_VALUE
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_GAP
         |   |   |
         |   |   |--PRO_E_SMT_DIMENSION_TYPE
         |   |   |
         |   |   |--PRO_E_SMT_DIMENSION_VALUE
         |   |
         |   |
         |   |--PRO_E_SMT_EDGE_RIP_FLIP
         |
         |
         |--PRO_E_EDIT_CORNER_SEAM_TABLE
              |
              |--PRO_E_CORNER_SEAM_RMV_SETTINGS
                   |
                   |--PRO_E_EDIT_CORNER_SEAM_RMV_REFS
                   |    |
                   |    |--PRO_E_CORNER_SEAM_RMV_FLAT
                   |    |
                   |    |--PRO_E_CORNER_SEAM_RMV_BEND_1
                   |    |
                   |    |--PRO_E_CORNER_SEAM_RMV_BEND_2
                   |  
                   |
                   |--PRO_E_CORNER_SEAM_BOUNDARIES
                   |
                   |
                   |--PRO_E_CORNER_SEAM_RMV_SIDE_1
                   |    |
                   |    |--PRO_E_CORNER_SEAM_RMV_DEFAULT
                   |    |
                   |    |--PRO_E_CORNER_SEAM_RMV_METHOD
                   |
                   |--PRO_E_CORNER_SEAM_RMV_SIDE_2
                        |
                        |--PRO_E_CORNER_SEAM_RMV_DEFAULT
                        |
                        |--PRO_E_CORNER_SEAM_RMV_METHOD
                    
===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------
  Element Id                      Element Name          Data Type
------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_EDIT_CORNER_SEAM           Edit Corner Seam       Compound
PRO_E_EDIT_CORNER_SEAM_SEL_MODE   Selection Mode        PRO_VALUE_TYPE_INT
PRO_E_EDIT_CORNER_SEAM_GEOMS      Corner Seam Geometry  Multi Collector
PRO_E_REMOVE_CORNER_SEAM         Remove Corner Seam    PRO_VALUE_TYPE_BOOLEAN 
PRO_E_EDIT_CORNER_SEAM_SHAPE      Corner Seam Shape     Compound
PRO_E_SMT_EDGE_RIP_TYPE           Edge Rip Type         PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_ADD_GAP        Edge Rip Add Gap      PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER   Edge Rip Close Corner PRO_VALUE_TYPE_BOOLEAN
PRO_E_SMT_EDGE_RIP_DIM_1          Edge Rip Dim 1        Compound
PRO_E_SMT_DIMENSION_TYPE          Dim  Type             PRO_VALUE_TYPE_INT
PRO_E_SMT_DIMENSION_VALUE         Dim  Value            PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_EDGE_RIP_DIM_2          Edge Rip Dim 2        Compound
PRO_E_SMT_EDGE_RIP_GAP            Edge Rip Gap          Compound
PRO_E_SMT_EDGE_RIP_FLIP           Edge Rip Flip         PRO_VALUE_TYPE_BOOLEAN
PRO_E_EDIT_CORNER_SEAM_TABLE      Corner Seams List     Array
PRO_E_CORNER_SEAM_RMV_SETTINGS    Removal Settings      Compound
PRO_E_EDIT_CORNER_SEAM_RMV_REFS   Corner References     Compound
PRO_E_CORNER_SEAM_RMV_FLAT   Corner Reference Flat   PRO_VALUE_TYPE_SELECTION
PRO_E_CORNER_SEAM_RMV_BEND_1 Corner Reference Bend 1 PRO_VALUE_TYPE_SELECTION
PRO_E_CORNER_SEAM_RMV_BEND_2 Corner Reference Bend 2 PRO_VALUE_TYPE_SELECTION
PRO_E_CORNER_SEAM_BOUNDARIES Bounding Sides        Multi Collector
PRO_E_CORNER_SEAM_RMV_SIDE_1 Side One Removal      Compound
PRO_E_CORNER_SEAM_RMV_SIDE_2 Side Two Removal      Compound
PRO_E_CORNER_SEAM_RMV_DEFAULT Default Removal       PRO_VALUE_TYPE_BOOLEAN
PRO_E_EDIT_CORNER_SEM_RMV_METHOD Removal Method        PRO_VALUE_TYPE_INT

===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                      Element Name           Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE		 Feature Type         PRO_FEAT_EDIT_CORNER_SEAM
PRO_E_STD_FEATURE_NAME           Feature Name                See Note 1
PRO_E_EDIT_CORNER_SEAM           Edit Corner Seam
PRO_E_EDIT_CORNER_SEAM_SEL_MODE  Selection Mode              See Note 2
PRO_E_EDIT_CORNER_SEAM_GEOMS     Corner Seam Geometry        See Note 3

PRO_E_EDIT_CORNER_SEAM_SHAPE      Corner Seam Shape     
PRO_E_SMT_EDGE_RIP_TYPE           Edge Rip Type           ProEdgeRipType 
PRO_E_SMT_EDGE_RIP_DIM_1          Edge Rip Dim 1          
PRO_E_SMT_EDGE_RIP_DIM_2          Edge Rip Dim 2        
PRO_E_SMT_EDGE_RIP_GAP            Edge Rip Gap          
PRO_E_SMT_DIMENSION_TYPE          Dim  Type             See note 5 
PRO_E_SMT_DIMENSION_VALUE         Dim  Value            ProEdgeRipDimType See note 4
PRO_E_CORNER_SEAM_RMV_FLAT   Corner Reference Flat   See Note 6
PRO_E_CORNER_SEAM_RMV_BEND_1 Corner Reference Bend 1 See Note 6
PRO_E_CORNER_SEAM_RMV_BEND_2 Corner Reference Bend 2 See Note 6
PRO_E_CORNER_SEAM_BOUNDARIES Bounding Sides          See Note 7
PRO_E_CORNER_SEAM_RMV_DEFAULT Default Removal       PRO_B_TRUE, PRO_B_FALSE
PRO_E_CORNER_SEAM_RMV_METHOD Removal Method        ProEditCornerSeamRemoveType



===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                    Comment
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Mandatory
PRO_E_STD_FEATURE_NAME           Mandatory
PRO_E_EDIT_CORNER_SEAM           Mandatory
PRO_E_EDIT_CORNER_SEAM_SEL_MODE  Mandatory
PRO_E_EDIT_CORNER_SEAM_GEOMS     See Note 3
PRO_E_REMOVE_CORNER_SEAM         Mandatory
PRO_E_EDIT_CORNER_SEAM_SHAPE     Mandatory See note 8
PRO_E_SMT_EDGE_RIP_TYPE          Mandatory See note 8
PRO_E_SMT_EDGE_RIP_ADD_GAP       See Note 5 
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER  Optional? 
PRO_E_SMT_EDGE_RIP_DIM_1         See Note 4 
PRO_E_SMT_EDGE_RIP_DIM_2         See Note 4
PRO_E_SMT_EDGE_RIP_GAP           See Note 5 
PRO_E_SMT_EDGE_RIP_FLIP          See Note 5 
PRO_E_EDIT_CORNER_SEAM_TABLE     Optional 
===============================================================================

(5) Notes

  Note-1  : Edit Corner Seam feature name. Default is "EDIT_CORNER_SEAM".

  Note-2  : Selection Mode might be
            PRO_SMT_RECOGNITION_MANUAL_SEL or PRO_SMT_RECOGNITION_AUTO_SEL.

  Note-3  : Corner Seam Geometry is unnecessary when Selection Type is
            PRO_SMT_RECOGNITION_AUTO_SEL and it is mandatory otherwise.
	    Existing corner seams, surfaces, intent surfaces can be selected.
            TODO: (Describe what could be selected besides side sufaces from recognized seams)

  Note-4  : Could be removed afterwards. 

  Note-5  : Dim Value Steps under Dim 1 and Dim 2 
            are Mandatory if Rip type is Blind 
            and corresponding Dim Type is PRO_DIM_ENTER
            Gap Dim Value is mandatory if Rip type is Gap or else 
            if Rip Type is Overlap and Add Gap is True
            and corresponding Dim Type is PRO_DIM_ENTER.
            Gap is non-negative; Blind Dims could not be both positive.
             Flip and Add Gap are mandatory only if Rip type is Overlap.

  Note-6  : Corner Reference Flat, Bend 1 , Bend 2  - surfaces that determine the Corner to which the seam
            is attached; should be plane, cylinder and cylinder. Should describe Corner Relief.



  Note-7  :  Bounding Sides: Optional, one from each side.

  Note-8  :  if Remove Seam is false; if it is true, current seam is removed and no new seam is 
             created. Elements under Shape are net needed in that case.

==============================================================================*/
 typedef enum _ProEditCornerSeamRemoveType_ {

PRO_CORNER_SEAM_REMOVE_TANGENT  = 1,
PRO_CORNER_SEAM_REMOVE_SAME     = 2,
PRO_CORNER_SEAM_REMOVE_PARALLEL = 3,
PRO_CORNER_SEAM_REMOVE_COMMON_VERTEX = 4,
PRO_CORNER_SEAM_REMOVE_NORMAL   = 0
} ProEditCornerSeamRemoveType;
PRO_END_C_DECLS
#endif

