#ifndef PROPATTERN_H
#define PROPATTERN_H

#include <ProFeature.h>
#include <ProSolid.h>


/* Creo Parametric TOOLKIT declarations for pattern related data structures */



PRO_BEGIN_C_DECLS


typedef enum pro_patt_type
{
  PRO_PAT_REF_DRIVEN      = 1,   /* Reference pattern */
  PRO_PAT_DIM_DRIVEN      = 2,   /* Dimension pattern */
  PRO_PAT_TABLE_DRIVEN    = 3    /* Table-driven pattern */
} ProPatternType;

typedef enum pro_pattern_regen_method
{
  PRO_PAT_GENERAL         = 4,   /* General pattern */
  PRO_PAT_VARYING         = 8,   /* Varying pattern */
  PRO_PAT_IDENTICAL       = 32   /* Identical pattern */
} ProPatternRegMethod;

typedef enum pro_pattern_variation_type
{
  PRO_PAT_RELATION_DRIVEN  = 2048,   /* Relation Driven pattern */
  PRO_PAT_VALUE_DRIVEN     = 4096    /* Value Driven pattern */
} ProPatternVariationType;

typedef enum pro_pattern_ref_type
{
  PRO_PAT_FEATURE      = 260,    /* Use feature pattern references */
  PRO_PAT_GROUP        = 2052,   /* Use group pattern references */
  PRO_PAT_BOTH         = 2308    /* Use feature and group pattern references */
} ProPatternRefType;

typedef enum pro_gen_patt_type
{
  PRO_GENPAT_DIM_DRIVEN      = 1,   /* Dimension pattern */
  PRO_GENPAT_TABLE_DRIVEN    = 2,   /* Table-driven pattern */
  PRO_GENPAT_REF_DRIVEN      = 3,   /* Reference pattern */
  PRO_GENPAT_FILL_DRIVEN     = 4,   /* Fill pattern */
  PRO_GENPAT_DIR_DRIVEN      = 5,   /* Direction pattern */
  PRO_GENPAT_AXIS_DRIVEN     = 6,   /* Axis pattern */
  PRO_GENPAT_CRV_DRIVEN      = 40,  /* Curve pattern */
  PRO_GENPAT_POINT_DRIVEN    = 55   /* Point pattern */  
} ProGenPatternType;

typedef enum pro_gen_patt_direction_type
{
  PRO_GENPAT_TRANSLATIONAL      = -1,  /* Translational pattern*/
  PRO_GENPAT_DIR1_ROTATIONAL    = 58,  /* 1st direction rotational */
  PRO_GENPAT_DIR2_ROTATIONAL    = 60   /* 2nd direction rotational */
} ProGenPatternDirectionType;

typedef enum pro_gen_pattern_fill_type         
{
   PRO_GENPAT_SQUARE_FILL   = 10,   /*Square shaped Template*/
   PRO_GENPAT_DIAMOND_FILL  = 11,   /*Diamond shaped Template*/
   PRO_GENPAT_TRIANGLE_FILL = 12,   /*Triangle shaped Template*/
   PRO_GENPAT_CIRCLE_FILL   = 13,   /*Circle shaped Template*/
   PRO_GENPAT_CURVE_FILL    = 14,   /*Curve shaped Template*/
   PRO_GENPAT_SPIRAL_FILL   = 15    /*Spiral shaped Template*/
} ProGenPatternFillType;

typedef enum pro_gen_pattern_point_type         
{
   PRO_GENPAT_REF_SKETCH =  0, /*Pattern points are created from ref sketch*/
   PRO_GENPAT_REF_POINT  = 56  /*Pattern points are created from ref datum point*/
} ProGenPatternPointType;

/*===========================================================================*/
extern ProError ProFeaturePatternGet ( ProFeature       *pattern_feature,
                                       ProPatternClass   pat_class,
                                       ProPattern       *p_pattern );
/*
   Purpose: Gets the pattern object from a feature that is part of a
            pattern.
	    <p>
	    NOTE:
	    <p>
	    Because a feature can be part of both a group pattern and 
	    feature pattern, you must specify the pattern object for
	    this function.
	    Use the functions <b>ProFeatureGroupStatusGet()</b> and
	    <b>ProFeatureGrppatternStatusGet()</b> to get the
	    appropriate information. Alternatively, you can
	    use the feature element tree to get the information.
 
   Input Arguments:
       pattern_feature - The input feature (part of a pattern).
       pat_class       - The pattern class
 
  Output Arguments:
       p_pattern       - The pattern object
 
   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           pattern information.
       PRO_TK_BAD_INPUTS - The specified feature is invalid or is not part of
                           a pattern.
*/

extern ProError ProPatternCreate ( ProFeature     *pattern_feature,
                                   ProPatternClass pat_class,
                                   ProElement      elem_tree );
/*
   Purpose: Creates a pattern, given the element tree.
	    <p>
	    NOTE:
	    <p>
	     Because a feature can be part of both a group pattern and
             feature pattern, you must specify the pattern object for
             this function. Use the functions <b>ProFeatureGroupStatusGet()</b>
             and <b>ProFeatureGrppatternStatusGet()</b> to get the
             appropriate information. Alternatively, you can use the
             feature element tree to get this information.

 
   Input Arguments:
       pattern_feature - The feature
       pat_class       - The pattern class
       elem_tree       - The root element of the pattern element tree

   Output Arguments:
       None
 
   Return Values:
       PRO_TK_NO_ERROR    -  The function successfully created the pattern.
       PRO_TK_BAD_INPUTS  -  One or more of the arguments are invalid.
       PRO_TK_UNSUPPORTED -  Unsupported model. For instance, models which come
                             from Multi-CAD assemblies are not supported in this release.
*/
 

extern ProError ProPatternElemtreeCreate ( ProFeature  *pattern_feature,
                                           ProPatternClass pat_class,
                                           ProElement  *p_elem_tree );
/*
   Purpose: Creates a copy of the pattern element tree. 
            <p>
	    NOTE:
	    <p>
            Because a feature can be part of both a group pattern and
            feature pattern, you must specify the pattern object for
            this function. Use the functions <b>ProFeatureGroupStatusGet()</b>
            and <b>ProFeatureGrppatternStatusGet()</b> to get the
            appropriate information. Alternatively, you can use the
            feature element tree to get this information.

   Input Arguments:
       pattern_feature - The input feature (part of a pattern)
       pat_class       - The pattern class

   Output Arguments:
       p_elem_tree     - The root element of the pattern element tree

   Return Values:
       PRO_TK_NO_ERROR    -  The function successfully created the pattern 
			     element tree.
       PRO_TK_BAD_INPUTS  -  One or more of the input arguments are invalid.
       PRO_TK_NOT_IMPLEMENTED - Returned for fill, axis and directional 
                                patterns, as these element trees are not yet 
				available.
*/

extern ProError ProPatternDelete ( ProPattern *p_pattern );
 
/*
   Purpose: Deletes the specified pattern.
 
   Input Arguments:
       p_pattern - The pattern object
 
   Output Arguments:
       None
 
   Return Values:
       PRO_TK_NO_ERROR   - The function successfully deleted the pattern.
       PRO_TK_BAD_INPUTS - The specified pattern object is invalid.
*/

extern ProError ProPatternLeaderGet ( ProPattern *p_pattern,
                                      ProFeature *r_pat_lead_feat );

/*
   Purpose: Gets the leader of the specified pattern object.

   Input Arguments:
       p_pattern       - The pattern object

   Output Arguments:
       r_pat_lead_feat - The pattern leader

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The specified pattern object is invalid.
*/

extern ProError ProPatmembLeaderGet ( ProPatmemb *p_pat_memb,
                                      ProFeature *r_pat_lead_feat );
/*
   Purpose: Gets the leader of the specified pattern member object.
 
   Input Arguments:
       p_pat_memb       - The pattern member object
 
   Output Arguments:
       r_pat_lead_feat  - The pattern leader
 
   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The specified pattern member object is invalid.
*/

extern ProError ProFeaturePatternleaderGet ( ProFeature* member_feat, 
                                             ProFeature* leader_feat );
/*

   Purpose: Gets the leader of the specified pattern member feature.


   Input Arguments:
      member_feat - Pattern member feature.

   Output Arguments:
      leader_feat - Pattern leader feature.

   Return Values:

      PRO_TK_NO_ERROR - The function successfully returned leader feature of pattern

      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

      PRO_TK_BAD_CONTEXT - Input feature is not a member of pattern or group
*/

extern ProError ProPatternHeaderGet ( ProPattern *p_pattern,
                                      ProFeature *r_pat_head_feat );
/*
   Purpose: Gets the Header of the specified pattern object.

   Input Arguments:
       p_pattern - The pattern object

   Output Arguments:
       r_pat_head_feat - The pattern header

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the header.
       PRO_TK_BAD_INPUTS - The specified pattern object is invalid.
*/

extern ProError ProPatternMembersGet (ProPattern  *p_pattern,                                               
                                      ProFeature **feat_members);
/*
    Purpose: Get the member features in pattern. 

    Input Arguments:
        p_pattern - The pattern handle

    Output Arguments:
        feat_members - Feature members inside the pattern 
                       For a group pattern, this is the group header feature only.
                       Free this memory using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function completed successfully.
        PRO_TK_BAD_INPUTS - Invalid input argument(s).
        PRO_TK_GENERAL_ERROR - The function failed.

*/

extern ProError ProPatternMemberVisit (ProPattern            *pattern, 
                                       ProFeatureVisitAction  visit,
                                       ProFeatureFilterAction filter,
                                       ProAppData             app_data);
/*
    Purpose: Visits the features in a pattern.

    Input Arguments:
        pattern  - The pattern handle
        visit    - The visit action function
        filter   - The filter function. If NULL, all the features in a pattern 
        	   are visited using the action function.
        app_data - User defined data passed to the visit and filter functions. 
        	   May be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - All members of the pattern were visited.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        Other - The visit was terminated by an error from the visit function

*/

PRO_END_C_DECLS

/* 

Pattern element tree
 
PRO_E_PATTERN_ROOT
|
|--- PRO_E_GENPAT_TYPE
|
|--- PRO_E_GENPAT_REGEN_METHOD
|
|--- PRO_E_STD_FEATURE_NAME
|
|      * Dim Pattern *
|
|--- PRO_E_GENPAT_DIM
|      |
|      |___ PRO_E_GENPAT_DIM_FIRST_DIR
|      |      |
|      |      |_ PRO_E_GENPAT_DIM_DIR_COMPOUND
|      |           |
|      |           |_ PRO_E_GENPAT_DIR_DIMENSION
|      |           |_ PRO_E_GENPAT_DIR_VAR_TYPE
|      |           |_ PRO_E_GENPAT_DIR_VAR_VALUE
|      |           |_ PRO_E_GENPAT_RELATION_EDIT
|      |
|      |___ PRO_E_GENPAT_DIM_FIRST_DIR_NUM_INST
|      |
|      |___ PRO_E_GENPAT_DIM_SECOND_DIR
|      |      |
|      |      |_ PRO_E_GENPAT_DIM_DIR_COMPOUND
|      |           |
|      |           |_ PRO_E_GENPAT_DIR_DIMENSION
|      |           |_ PRO_E_GENPAT_DIR_VAR_TYPE
|      |           |_ PRO_E_GENPAT_DIR_VAR_VALUE
|      |           |_ PRO_E_GENPAT_RELATION_EDIT
|      |
|      |___ PRO_E_GENPAT_DIM_SECOND_DIR_NUM_INST
|
|
|      * Table Pattern *
|
|--- PRO_E_GENPAT_TABLE
|      |--- PRO_E_GENPAT_TABLE_DIMS
|      |      |--- PRO_E_GENPAT_TABLE_DIM_ENTRY
|      |             |
|      |             |- PRO_E_GENPAT_TABLE_DIM
|      |
|      |--- PRO_E_GENPAT_TABLE_LIST
|      |      |--- PRO_E_GENPAT_TABLE_ENTRY
|      |             |- PRO_E_GENPAT_TABLE_NAME
|      |             |--PRO_E_GENPAT_TABLE_INSTANCES
|      |                |--PRO_E_GENPAT_TABLE_INSTANCE
|      |                   |--PRO_E_GENPAT_TABLE_INSTANCE_INDEX
|      |                   |--PRO_E_GENPAT_TABLE_INSTANCE_DIMS
|      |                        |--PRO_E_GENPAT_TABLE_INSTANCE_DIM_VALUE
|      | 
|      |--- PRO_E_GENPAT_TABLE_SET_ACTIVE
|
|
|      * Ref Pattern *
|
|--- PRO_E_GENPAT_REF
|      |
|      |--- PRO_E_GENPAT_REF_TYPE
|
|
|      * Fill Pattern *
|
|--- PRO_E_GENPAT_FILL
|      |--- PRO_E_GENPAT_FILL_TEMPLATE_TYPE
|      |--- PRO_E_GENPAT_FILL_SPACING
|      |--- PRO_E_GENPAT_FILL_BORDERING
|      |--- PRO_E_GENPAT_FILL_ROT_ANG
|      |--- PRO_E_GENPAT_FILL_RADIUS_INC
|
|      * Curve Pattern *
|
|--- PRO_E_GENPAT_CURVE
|      |--- PRO_E_GENPAT_CRV_PNT_REF
|      |--- PRO_E_GENPAT_CRV_PLC_TYPE
|      |--- PRO_E_GENPAT_CRV_SPACING
|      |--- PRO_E_GENPAT_CRV_NUMBER
|      |--- PRO_E_GENPAT_CRV_FLIP
|
|      * Dir Pattern *
|
|--- PRO_E_GENPAT_DIR
|      |--- PRO_E_DIR_PAT_DIR1_OPT
|      |--- PRO_E_GENPAT_DIR1
|      |      |
|      |      |--- PRO_E_DIRECTION_COMPOUND
|      |             |
|      |             |--- PRO_E_DIRECTION_REFERENCE
|      |             |--- PRO_E_DIRECTION_FLIP
|      |
|      |--- PRO_E_DIR_PAT_DIR1_FLIP
|      |--- PRO_E_GENPAT_DIR1_INC
|      |--- PRO_E_DIR_PAT_DIR2_OPT
|      |--- PRO_E_GENPAT_DIR2
|      |      |
|      |      |--- PRO_E_DIRECTION_COMPOUND
|      |             |
|      |             |--- PRO_E_DIRECTION_REFERENCE
|      |             |--- PRO_E_DIRECTION_FLIP
|      |
|      |--- PRO_E_DIR_PAT_DIR2_FLIP
|      |--- PRO_E_GENPAT_DIR2_INC
|      |
|      |--- PRO_E_GENPAT_DIM_FIRST_DIR
|      |      |
|      |      |--- PRO_E_GENPAT_DIM_DIR_COMPOUND
|      |             |
|      |             |--- PRO_E_GENPAT_DIR_DIMENSION
|      |             |--- PRO_E_GENPAT_DIR_VAR_TYPE
|      |             |--- PRO_E_GENPAT_DIR_VAR_VALUE
|      |             |--- PRO_E_GENPAT_RELATION_EDIT
|      |
|      |--- PRO_E_GENPAT_DIM_FIRST_DIR_NUM_INST
|      |
|      |--- PRO_E_GENPAT_DIM_SECOND_DIR
|      |      |
|      |      |--- PRO_E_GENPAT_DIM_DIR_COMPOUND
|      |             |
|      |             |--- PRO_E_GENPAT_DIR_DIMENSION
|      |             |--- PRO_E_GENPAT_DIR_VAR_TYPE
|      |             |--- PRO_E_GENPAT_DIR_VAR_VALUE
|      |             |--- PRO_E_GENPAT_RELATION_EDIT
|      |
|      |--- PRO_E_GENPAT_DIM_SECOND_DIR_NUM_INST
|
|      * Axis Pattern *
|
|--- PRO_E_GENPAT_AXIS
|      |
|      |--- PRO_E_GENPAT_AXIS_REF
|      |--- PRO_E_GENPAT_AXIS1_INC
|      |--- PRO_E_AXIS_PAT_DIR1_FLIP
|      |--- PRO_E_GENPAT_AXIS2_INC
|      |--- PRO_E_AXIS_PAT_DIR2_FLIP
|      |--- PRO_E_GENPAT_AXIS_ANG_WHOLE
|      |--- PRO_E_GENPAT_DIM_FIRST_DIR
|      |      |
|      |      |--- PRO_E_GENPAT_DIM_DIR_COMPOUND
|      |             |
|      |             |--- PRO_E_GENPAT_DIR_DIMENSION
|      |             |--- PRO_E_GENPAT_DIR_VAR_TYPE
|      |             |--- PRO_E_GENPAT_DIR_VAR_VALUE
|      |             |--- PRO_E_GENPAT_RELATION_EDIT
|      |
|      |--- PRO_E_GENPAT_DIM_FIRST_DIR_NUM_INST
|      |
|      |--- PRO_E_GENPAT_DIM_SECOND_DIR
|      |      |
|      |      |--- PRO_E_GENPAT_DIM_DIR_COMPOUND
|      |             |
|      |             |--- PRO_E_GENPAT_DIR_DIMENSION
|      |             |--- PRO_E_GENPAT_DIR_VAR_TYPE
|      |             |--- PRO_E_GENPAT_DIR_VAR_VALUE
|      |             |--- PRO_E_GENPAT_RELATION_EDIT
|      |
|      |--- PRO_E_GENPAT_DIM_SECOND_DIR_NUM_INST
|
|      * Point Pattern *
|
|--- PRO_E_GENPAT_POINT
|      |--- PRO_E_GENPAT_POINT_REF_TYPE
|      |--- PRO_E_GENPAT_POINT_REF
|
|
|--- PRO_E_STD_SECTION 
|
|
|--- PRO_E_PAT_GEOM_REFS
|      |
|      |_ PRO_E_STD_SURF_COLLECTION_APPL
|      |
|      |_ PRO_E_PAT_CRV_DTM_REFS
|
|
|-- PRO_E_FLEX_OPTS_CMPND
|     |
|     |- PRO_E_FLEX_TRF_SEL_ATT_GEOM
|     |
|     |_ PRO_E_FLEX_ATTACH_GEOM
|     |
|     |_ PRO_E_FLEX_CR_RND_GEOM
|
|
|--- PRO_E_PAT_APPLICATIONS
|      |
|      |-- PRO_E_PAT_MFG_TOOL_PATH
|      |     |
|      |     |-- PRO_E_PAT_MFG_ORD_LEADER
|      |     |-- PRO_E_PAT_MFG_ORDER_OPT
|      |     |-- PRO_E_PAT_MFG_ORD_REVERSE
|      |     |-- PRO_E_PAT_MFG_ORD_ALT_ROWS
|      |     |-- PRO_E_PAT_MFG_ORD_ALT_DIR
|      |     |-- PRO_E_PAT_MFG_ORD_SHARED
|      |     |-- PRO_E_PAT_MFG_FIX_OFFSET
|      |     |-- PRO_E_PAT_MFG_FIX_OFF_INIT
|      |     |-- PRO_E_PAT_MFG_FIX_OFF_INCR
|      |     |-- PRO_E_PAT_MFG_SUB_OUTPUT
|      |     |-- PRO_E_PAT_MFG_SUB_OUT_MODE
|      |     |-- PRO_E_PAT_MFG_SUB_OUT_MULTAX
|      |
|      |
|      |-- PRO_E_PAT_GPRF
|      |     |
|      |     |-- PRO_E_PAT_GPRF_TYPE
|      |     |-- PRO_E_PAT_GPRF_TRF_TYPE
|      |     |-- PRO_E_PAT_GPRF_DIR1_TRF
|      |     |-- PRO_E_PAT_GPRF_DIR1_NUM_INST
|      |     |-- PRO_E_PAT_GPRF_DIR1_SPACING
|      |     |-- PRO_E_PAT_GPRF_DIR2_TRF
|      |     |-- PRO_E_PAT_GPRF_DIR2_NUM_INST
|      |     |-- PRO_E_PAT_GPRF_DIR2_SPACING
|      |     |-- PRO_E_DIR_GPRF_MOVE_OPT
|      |     |-- PRO_E_PAT_GPRF_USE_SRF
|      |     |-- PRO_E_STD_SURF_COLLECTION_APPL
|      |     |-- PRO_E_PAT_GPRF_USE_SEC
|      |
|
|

---------------------------------------------------------------------------------------------------------------
Element Id                               Element Name         Data Type                   Valid Values
---------------------------------------------------------------------------------------------------------------
PRO_E_GENPAT_TYPE                        Type                 PRO_VALUE_TYPE_INT          PRO_GENPAT_DIM_DRIVEN  
                                                                                          PRO_GENPAT_TABLE_DRIVEN
                                                                                          PRO_GENPAT_REF_DRIVEN  
                                                                                          PRO_GENPAT_FILL_DRIVEN 
                                                                                          PRO_GENPAT_DIR_DRIVEN  
                                                                                          PRO_GENPAT_AXIS_DRIVEN 
                                                                                          PRO_GENPAT_CRV_DRIVEN
                                                                                          PRO_GENPAT_POINT_DRIVEN
                                                                                          
                                                                                          
PRO_E_GENPAT_REF                         Ref Pattern          PRO_VALUE_TYPE_INT          PRO_PAT_FEATURE
                                                                                          PRO_PAT_GROUP
                                                                                          PRO_PAT_BOTH
                                                                                          
PRO_E_GENPAT_REGEN_METHOD                Regen Method         PRO_VALUE_TYPE_INT          PRO_PAT_IDENTICAL
                                                                                          PRO_PAT_VARYING
                                                                                          PRO_PAT_GENERAL
                                                                                          
PRO_E_GENPAT_DIM_FIRST_DIR               1st Dir Dimensions   Array
PRO_E_GENPAT_DIM_DIR_COMPOUND            Dimension-Variation  Compound
PRO_E_GENPAT_DIR_DIMENSION               Dimension            PRO_VALUE_TYPE_SELECTION
PRO_E_GENPAT_DIR_VAR_TYPE                Variation Type       PRO_VALUE_TYPE_INT          PRO_PAT_RELATION_DRIVEN
                                                                                          PRO_PAT_VALUE_DRIVEN
PRO_E_GENPAT_DIR_VAR_VALUE               Increment            PRO_VALUE_TYPE_DOUBLE       
PRO_E_GENPAT_RELATION_EDIT               Relation             Application                            
PRO_E_GENPAT_DIM_FIRST_DIR_NUM_INST      1st Dir Instances    PRO_VALUE_TYPE_INT          >= 2 
PRO_E_GENPAT_DIM_SECOND_DIR_NUM_INST     2nd Dir Instances    PRO_VALUE_TYPE_INT          >= 0

PRO_E_GENPAT_TABLE_DIMS                  Dimensions           Array
PRO_E_GENPAT_TABLE_DIM_ENTRY             Table Dim            Compound
PRO_E_GENPAT_TABLE_INSTANCE_DIMS         Dimension Variations Array
PRO_E_GENPAT_TABLE_DIM                   Table Dim            PRO_VALUE_TYPE_SELECTION
PRO_E_GENPAT_TABLE_LIST                  Tables               Array
PRO_E_GENPAT_TABLE_ENTRY                 Table                Compound
PRO_E_GENPAT_TABLE_NAME                  Name                 PRO_VALUE_TYPE_WSTRING
PRO_E_GENPAT_TABLE_SET_ACTIVE            Active Table         PRO_VALUE_TYPE_INT          0 <= value < # of tables

PRO_E_GENPAT_FILL_TEMPLATE_TYPE          Fill Template        PRO_VALUE_TYPE_INT          PRO_GENPAT_SQUARE_FILL  
                                                                                          PRO_GENPAT_DIAMOND_FILL 
                                                                                          PRO_GENPAT_TRIANGLE_FILL
                                                                                          PRO_GENPAT_CIRCLE_FILL  
                                                                                          PRO_GENPAT_CURVE_FILL   
                                                                                          PRO_GENPAT_SPIRAL_FILL  
PRO_E_GENPAT_FILL_SPACING                Fill Spacing         PRO_VALUE_TYPE_DOUBLE 
PRO_E_GENPAT_FILL_BORDERING              Fill Bordering       PRO_VALUE_TYPE_DOUBLE 
PRO_E_GENPAT_FILL_ROT_ANG                Fill angle           PRO_VALUE_TYPE_DOUBLE 
PRO_E_GENPAT_FILL_RADIUS_INC             Fill radius inc      PRO_VALUE_TYPE_DOUBLE

PRO_E_GENPAT_POINT_REF_TYPE              Point type           PRO_VALUE_TYPE_INT          PRO_GENPAT_REF_SKETCH 
                                                                                          PRO_GENPAT_REF_POINT  
PRO_E_GENPAT_POINT_REF                   Point reference      PRO_VALUE_TYPE_SELECTION
                                                              
PRO_E_GENPAT_CRV_PNT_REF                 Curve Refrence       PRO_VALUE_TYPE_SELECTION
PRO_E_GENPAT_CRV_PLC_TYPE                Curve type           PRO_VALUE_TYPE_INT           0 or 1
PRO_E_GENPAT_CRV_SPACING                 Curve spacing        PRO_VALUE_TYPE_DOUBLE        
PRO_E_GENPAT_CRV_NUMBER                  Curve Number         PRO_VALUE_TYPE_INT           >0 ignored if PRO_E_GENPAT_CRV_PLC_TYPE =0
PRO_E_GENPAT_CRV_FLIP                    Curve flip           PRO_VALUE_TYPE_INT           0 or 1
                                                              
PRO_E_GENPAT_AXIS_REF                    Axis Reference       PRO_VALUE_TYPE_SELECTION
PRO_E_GENPAT_AXIS1_INC                   Axis 1st Increment   PRO_VALUE_TYPE_DOUBLE        -360 <= value <= 360
PRO_E_AXIS_PAT_DIR1_FLIP                 Axis 1st dir flip    PRO_VALUE_TYPE_INT           0 or 1
PRO_E_GENPAT_AXIS2_INC                   Axis 2nd Increment   PRO_VALUE_TYPE_DOUBLE 
PRO_E_AXIS_PAT_DIR2_FLIP                 Axis 2nd dir flip    PRO_VALUE_TYPE_INT           0 or 1
PRO_E_GENPAT_AXIS_ANG_WHOLE              Axis angle           PRO_VALUE_TYPE_DOUBLE 

PRO_E_DIR_PAT_DIR1_OPT                   Dir 1st option       PRO_VALUE_TYPE_INT           PRO_GENPAT_TRANSLATIONAL
                                                                                           PRO_GENPAT_DIR1_ROTATIONAL

PRO_E_GENPAT_DIR1                        1st Direction        Compound
PRO_E_DIRECTION_COMPOUND                 Direction            Compound
PRO_E_DIRECTION_REFERENCE                Direction Ref        PRO_VALUE_TYPE_SELECTION       
PRO_E_DIRECTION_FLIP                     Direction Flip       PRO_VALUE_TYPE_INT           Value Ignored  
PRO_E_DIR_PAT_DIR1_FLIP                  1st dir flip         PRO_VALUE_TYPE_INT           0 or 1
PRO_E_GENPAT_DIR1_INC                    1st dir inc          PRO_VALUE_TYPE_DOUBLE
PRO_E_DIR_PAT_DIR2_OPT                   Dir 2nd option       PRO_VALUE_TYPE_INT           PRO_GENPAT_TRANSLATIONAL       
                                                                                           PRO_GENPAT_DIR2_ROTATIONAL

PRO_E_GENPAT_DIR2                        2nd Direction        Compound
PRO_E_DIR_PAT_DIR2_FLIP                  2nd dir flip         PRO_VALUE_TYPE_INT           0 or 1
PRO_E_GENPAT_DIR2_INC                    2nd dir inc          PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_FEATURE_NAME                   Feature Name         PRO_VALUE_TYPE_WSTRING
PRO_E_STD_SECTION                        Reference Section    Compound                     For more details refer
                                                                                           ProStdSection.h

* For now, elements under PRO_E_PAT_GEOM_REFS are not used for feature creation in Creo Parametric TOOLKIT *

PRO_E_PAT_GEOM_REFS                      Pattern References            Compound
PRO_E_STD_SURF_COLLECTION_APPL           Reference Surfaces            PRO_VALUE_TYPE_SELECTION
PRO_E_PAT_CRV_DTM_REFS                   Reference Curves and Datums   PRO_VALUE_TYPE_SELECTION


* For now, elements under PRO_E_FLEX_OPTS_CMPND are not used for feature creation in Creo Parametric TOOLKIT *

PRO_E_FLEX_OPTS_CMPND                    Attachment Options                      Compound
PRO_E_FLEX_TRF_SEL_ATT_GEOM              Transform Selected Attachment Geometry  PRO_VALUE_TYPE_INT   0 or 1
PRO_E_FLEX_ATTACH_GEOM                   Attachment Option                       PRO_VALUE_TYPE_INT   0 or 1
PRO_E_FLEX_CR_RND_GEOM                   Round Option                            PRO_VALUE_TYPE_INT   0 or 1


PRO_E_PAT_APPLICATIONS                   Pattern Applications Compound

PRO_E_PAT_MFG_TOOL_PATH                  Patt. of NC sequence Compound
PRO_E_PAT_MFG_ORD_LEADER                 Number of the leader PRO_VALUE_TYPE_INT           0 <= value < # of instances
PRO_E_PAT_MFG_ORDER_OPT                  Order options        PRO_VALUE_TYPE_INT           Pattern Order - 1, Shortest - 2, Pick Order - 3
PRO_E_PAT_MFG_ORD_REVERSE                Reverse option       PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_ORD_ALT_ROWS               Alternate Rows       PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_ORD_ALT_DIR                Alternate Direction  PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_ORD_SHARED                 Shared Orientation   PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_FIX_OFFSET                 Fixture Offsets      PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_FIX_OFF_INIT               Initial Fixt. Offs.  PRO_VALUE_TYPE_INT           1 <= value
PRO_E_PAT_MFG_FIX_OFF_INCR               Fixt. Offs. incr.    PRO_VALUE_TYPE_INT           1 <= value
PRO_E_PAT_MFG_SUB_OUTPUT                 Subroutine option    PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_SUB_OUT_MODE               Subroutine mode      PRO_VALUE_TYPE_INT           Absolute - 1, Incremental - 2
PRO_E_PAT_MFG_SUB_OUT_MULTAX             Subroutine multax    PRO_VALUE_TYPE_INT           0 or 1
PRO_E_PAT_MFG_SUB_OUT_COPYCL             Subroutine copy cl   PRO_VALUE_TYPE_INT           0 or 1
* For now, elements under PRO_E_PAT_GPRF are not used for feature creation in Creo Parametric TOOLKIT *

PRO_E_PAT_GPRF                 Pattern Recognition               Compound
PRO_E_PAT_GPRF_TYPE            Type of Recognized Pattern        PRO_VALUE_TYPE_INT        0 or 1
PRO_E_PAT_GPRF_TRF_TYPE        Type of Transformation            PRO_VALUE_TYPE_INT        0, 1, 2
PRO_E_PAT_GPRF_DIR1_TRF        First Dir Transformation          PRO_VALUE_TYPE_INT       -1, 58
PRO_E_PAT_GPRF_DIR1_NUM_INST   First Dir Number of Instances     PRO_VALUE_TYPE_INT
PRO_E_PAT_GPRF_DIR1_SPACING    Spacing in the First Direction    PRO_VALUE_TYPE_DOUBLE
PRO_E_PAT_GPRF_DIR2_TRF        Second Dir Transformation         PRO_VALUE_TYPE_INT       -1, 60
PRO_E_PAT_GPRF_DIR2_NUM_INST   Second Dir Number of Instances    PRO_VALUE_TYPE_INT
PRO_E_PAT_GPRF_DIR2_SPACING    Spacing in the Second Direction   PRO_VALUE_TYPE_DOUBLE
PRO_E_DIR_GPRF_MOVE_OPT        Create Pattern of Move Features   PRO_VALUE_TYPE_INT        0 or 1
PRO_E_PAT_GPRF_USE_SRF         Use Surface for region definition PRO_VALUE_TYPE_INT        0 or 1
PRO_E_STD_SURF_COLLECTION_APPL Reference Surface                 PRO_VALUE_TYPE_SELECTION
PRO_E_PAT_GPRF_USE_SEC         Sketch for region definition      PRO_VALUE_TYPE_INT        0 or 1

---------------------------------------------------------------------------------------------------------------

Note:-
PRO_E_DIRECTION_FLIP value is ignored while pattern creation.



The following element tree was used in release WildFire 4.0 and earlier 
and is provided for legacy purposes only.  Users are advised 
not to use this element tree for pattern creation or modification
activities anymore.


Pattern element tree (OLD)
 
   PRO_E_PATTERN_ROOT
     |
     |--PRO_E_PAT_TYPE
     |
     |--PRO_E_PAT_REF
     |
     |--PRO_E_PAT_REGEN_METHOD
     |
     |--PRO_E_PAT_FIRST_DIR
     |    |--PRO_E_PAT_DIR_DIM_COMPOUND
     |         |--PRO_E_PAT_DIR_DIMENSION
     |         |--PRO_E_PAT_DIR_VAR_TYPE
     |         |--PRO_E_PAT_DIR_VAR_VALUE
     |         |--PRO_E_PAT_RELATION_EDIT
     |
     |--PRO_E_PAT_FIRST_DIR_NUM_INST
     |
     |--PRO_E_PAT_SECOND_DIR
     |    |--PRO_E_PAT_DIR_DIM_COMPOUND
     |         |--PRO_E_PAT_DIR_DIMENSION
     |         |--PRO_E_PAT_DIR_VAR_TYPE
     |         |--PRO_E_PAT_DIR_VAR_VALUE
     |         |--PRO_E_PAT_RELATION_EDIT
     |
     |--PRO_E_PAT_SECOND_DIR_NUM_INST
     |
     |--PRO_E_PAT_TABLE_DIMS
     |    |--PRO_E_PAT_TABLE_DIM
     |
     |--PRO_E_PAT_TABLE_LIST
     |    |--PRO_E_PAT_TABLE
     |         |--PRO_E_PAT_TABLE_NAME
     |         |--PRO_E_PAT_TABLE_INSTANCES
     |              |--PRO_E_PAT_TABLE_INSTANCE
     |                   |--PRO_E_PAT_TABLE_INSTANCE_INDEX
     |                   |--PRO_E_PAT_TABLE_INSTANCE_DIMS
     |                        |--PRO_E_PAT_TABLE_INSTANCE_DIM_VALUE
     |
     |--PRO_E_PAT_TABLE_SET_ACTIVE
 
---------------------------------------------------------------------------------------------------------
Element Id                         Element Name         Data Type                Valid Values
---------------------------------------------------------------------------------------------------------
PRO_E_PAT_TYPE                     Type                 PRO_VALUE_TYPE_INT       PRO_PAT_REF_DRIVEN
                                                                                 PRO_PAT_DIM_DRIVEN
                                                                                 PRO_PAT_TABLE_DRIVEN
PRO_E_PAT_REF                      Ref Pattern          PRO_VALUE_TYPE_INT       PRO_PAT_FEATURE
                                                                                 PRO_PAT_GROUP
                                                                                 PRO_PAT_BOTH
PRO_E_PAT_REGEN_METHOD             Regen Method         PRO_VALUE_TYPE_INT       PRO_PAT_IDENTICAL
                                                                                 PRO_PAT_VARYING
                                                                                 PRO_PAT_GENERAL
PRO_E_PAT_FIRST_DIR                1st Dir Dimensions   Array
PRO_E_PAT_DIR_DIM_COMPOUND         Dimension-Variation  Compound
PRO_E_PAT_DIR_DIMENSION            Dimension            PRO_VALUE_TYPE_SELECTION
PRO_E_PAT_DIR_VAR_TYPE             Variation Type       PRO_VALUE_TYPE_INT       PRO_PAT_RELATION_DRIVEN
                                                                                 PRO_PAT_VALUE_DRIVEN
PRO_E_PAT_DIR_VAR_VALUE            Increment            PRO_VALUE_TYPE_DOUBLE
PRO_E_PAT_RELATION_EDIT            Relation             
PRO_E_PAT_FIRST_DIR_NUM_INST       1st Dir Instances    PRO_VALUE_TYPE_INT       >= 2 Creation
                                                                                 >= 1 Redefinition
PRO_E_PAT_SECOND_DIR               2nd Dir Dimensions   Array
PRO_E_PAT_SECOND_DIR_NUM_INST      2nd Dir Instances    PRO_VALUE_TYPE_INT       >= 0
PRO_E_PAT_TABLE_DIMS               Table Dims           Array
PRO_E_PAT_TABLE_DIM                Table Dim            PRO_VALUE_TYPE_SELECTION
PRO_E_PAT_TABLE_LIST               Tables               Array
PRO_E_PAT_TABLE                    Table                Compound
PRO_E_PAT_TABLE_NAME               Name                 PRO_VALUE_TYPE_WSTRING
PRO_E_PAT_TABLE_INSTANCES          Instances            Array
PRO_E_PAT_TABLE_INSTANCE           Instance             Compound
PRO_E_PAT_TABLE_INSTANCE_INDEX     Index                PRO_VALUE_TYPE_INT        
PRO_E_PAT_TABLE_INSTANCE_DIMS      Dimension Variations Compound
PRO_E_PAT_TABLE_INSTANCE_DIM_VALUE Value                PRO_VALUE_TYPE_DOUBLE
PRO_E_PAT_TABLE_SET_ACTIVE         Active Table         PRO_VALUE_TYPE_INT       0 <= value < # of tables
---------------------------------------------------------------------------------------------------------

*/


#endif
