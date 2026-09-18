#ifndef PRODRAFT_H
#define PRODRAFT_H
/*
   Creo Parametric TOOLKIT declarations related to draft feature.
*/



#include <ProToolkit.h>
#include <ProDirection.h>

PRO_BEGIN_C_DECLS


/*****************************************************************************

Feature element tree

PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_DRAFT_TWEAK_OR_INTERSEC
     |
     |--PRO_E_DRAFT_EXTEND
     |
     |--PRO_E_DRAFT_SPLIT
     |
     |--PRO_E_STD_SURF_COLLECTION_APPL
     |
     |--PRO_E_DIRECTION_COMPOUND
     |
     |--PRO_E_DRAFT_CONSTANT_OR_VARIABLE
     |
     |--PRO_E_STD_CURVE_COLLECTION_APPL
     |
     |--PRO_E_DRAFT_SPLIT_GEOM
     |
     |--PRO_E_STD_SECTION
     |  |--PRO_E_SEC_USE_SKETCH
     |
     |--PRO_E_DRAFT_INCLUDE_TANGENT 
     |
     |--PRO_E_DRAFT_SIDE_1
     |  |--PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_1
     |  |--PRO_E_DRAFT_NEUTRAL_PLANE_1
     |  |--PRO_E_STD_CURVE_COLLECTION_APPL
     |  |--PRO_E_DRAFT_DEPENDENT_1
     |  |--PRO_E_DRAFT_ANGLE_1
     |  |--PRO_E_DRAFT_ANGLES
     |  |  |--PRO_E_DRAFT_ANG_PNT
     |  |     |--PRO_E_STD_POINT_COLLECTION_APPL
     |  |     |--PRO_E_DRAFT_ANGLE
     |  |
     |  |--PRO_E_DRAFT_NEUTRAL_QUILT_1
     |
     |--PRO_E_DRAFT_SIDE_2
        |--PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_2
        |--PRO_E_DRAFT_NEUTRAL_PLANE_2
        |--PRO_E_STD_CURVE_COLLECTION_APPL
        |--PRO_E_DRAFT_DEPENDENT_2
        |--PRO_E_DRAFT_ANGLE_2
        |--PRO_E_DRAFT_ANGLES
        |  |--PRO_E_DRAFT_ANG_PNT
        |  |  |--PRO_E_STD_POINT_COLLECTION_APPL
        |  |  |--PRO_E_DRAFT_ANGLE
        |   
        |--PRO_E_DRAFT_NEUTRAL_QUILT_2

Feature elements table

-------------------------------------------------------------------------------------
Element Id                         Element Name              Data Type
-------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                 Feature Type             PRO_VALUE_TYPE_INT (PRO_FEAT_DRAFT)
PRO_E_STD_FEATURE_NAME             Feature Name             PRO_VALUE_TYPE_WSTRING
PRO_E_DRAFT_TWEAK_OR_INTERSEC      Tweak or Intersect       PRO_VALUE_TYPE_INT 
				    - See Note 1. 
PRO_E_DRAFT_EXTEND                 Extend                   PRO_VALUE_TYPE_INT
				    - See Note 2. 
PRO_E_STD_SURF_COLLECTION_APPL     Drafted Surfaces         PRO_VALUE_TYPE_SELECTION
				    - Refer ProSrfcollection.h

PRO_E_DRAFT_SPLIT                  Split                    PRO_VALUE_TYPE_INT
PRO_E_DIRECTION_COMPOUND           Direction Utility        Compound
				    - See ProDirection.h
PRO_E_DRAFT_CONSTANT_OR_VARIABLE   Constant or Variable     PRO_VALUE_TYPE_INT
PRO_E_STD_CURVE_COLLECTION_APPL    Exclude Loop (optional)  PRO_VALUE_TYPE_SELECTION
                                   Draft hinge(s) 
				    - See ProCrvcollection.h 

PRO_E_STD_SECTION                  Split Sketch (optional)  Compound
				    - See ProStdSection.h
PRO_E_SEC_USE_SKETCH               Split Sketch (optional)  PRO_VALUE_TYPE_SELECTION
PRO_E_DRAFT_SPLIT_GEOM             Split Geom (optional)    PRO_VALUE_TYPE_SELECTION
PRO_E_DRAFT_INCLUDE_TANGENT        Include Tangent          PRO_VALUE_TYPE_INT

PRO_E_DRAFT_SIDE_1                 1st draft's side         Compound 
PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_1  Type of Draft hinge      PRO_VALUE_TYPE_INT
PRO_E_DRAFT_NEUTRAL_PLANE_1        Draft hinge              PRO_VALUE_TYPE_SELECTION
PRO_E_DRAFT_DEPENDENT_1            Dependence               PRO_VALUE_TYPE_INT
PRO_E_DRAFT_ANGLE_1                Draft Angle (constant)   PRO_VALUE_TYPE_DOUBLE
PRO_E_DRAFT_SIDE_2                 1st draft's side         Compound 
PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_2  Typr of Draft hinge      PRO_VALUE_TYPE_INT
PRO_E_DRAFT_NEUTRAL_PLANE_2        Draft hinge              PRO_VALUE_TYPE_SELECTION
PRO_E_DRAFT_DEPENDENT_2            Dependence               PRO_VALUE_TYPE_INT
PRO_E_DRAFT_ANGLE_2                Draft Angle (constant)   PRO_VALUE_TYPE_DOUBLE 
PRO_E_DRAFT_ANGLES                 Draft Angles and Points  Array
PRO_E_DRAFT_ANG_PNT                Draft Angle and Point    Compound
PRO_E_STD_POINT_COLLECTION_APPL    Point for Angle          PRO_VALUE_TYPE_SELECTION
				    - See ProCrvcollection.h 

PRO_E_DRAFT_ANGLE                  Draft angle (variable)   PRO_VALUE_TYPE_DOUBLE 

PRO_E_DRAFT_NEUTRAL_QUILT_1
PRO_E_DRAFT_NEUTRAL_QUILT_2        Hinge quilt              PRO_VALUE_TYPE_SELECTION     
-------------------------------------------------------------------------------------


Table Draft 1 : Common elements and their values

 ---------------------------------------------------------------------
 |      Element ID 			  Correponding enum          |
 |-------------------------------------------------------------------|
 |  PRO_E_DRAFT_TWEAK_OR_INTERSEC 	  ProDraftTweakOrIntsctOpts  |
 |  PRO_E_DRAFT_EXTEND			  ProDraftExtendOpts         |
 |  PRO_E_DRAFT_SPLIT			  ProDraftSplitOpts          |
 |  PRO_E_DRAFT_CONSTANT_OR_VARIABLE	  ProDraftConstOrVarOpts     |
 |  PRO_E_DRAFT_INCLUDE_TANGENT		  ProDraftIncludeTangentOpts |
 |  PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_1/_2  ProDraftHingeType;	     |
 |  PRO_E_DRAFT_DEPENDENT_1/_2		  ProDraftDependenceOpts     |
 ---------------------------------------------------------------------


 Notes :
 ******

Note 1. PRO_E_DRAFT_TWEAK_OR_INTERSEC option is available for features created 
	Pro/E Version prior to WildFire 2.0. 

Note 2. PRO_E_DRAFT_EXTEND - For features created using Pro/E Version prior to 
        WildFire 2.0 - is available only for 
        PRO_E_DRAFT_TWEAK_OR_INTERSEC ==  PRO_DRAFT_UI_INTERSECT

Note 3. PRO_E_DRAFT_DEPENDENT_1 / _2 :: control whether corresponding side 
	is drafted. Depends upon the type of Draft hinge the 
	PRO_E_STD_CURVE_COLLECTION_APPL or if PRO_E_DRAFT_NEUTRAL_PLANE_... 
	is used for Draft hinge.


*/     


/* Include Tangent  :: PRO_E_DRAFT_INCLUDE_TANGENT */
typedef enum  
{
 PRO_DRAFT_UI_NOT_INC_TANG = 0,  /* Not include tangrnts */
 PRO_DRAFT_UI_INC_TANG = 1  /* Include tangrnts */
} ProDraftIncludeTangentOpts;

/* Constant or Variable :: PRO_E_DRAFT_CONSTANT_OR_VARIABLE  */
typedef enum 
{
 PRO_DRAFT_UI_VARIABLE = 0, /* Variable */
 PRO_DRAFT_UI_CONSTANT = 1 /* Constant */
} ProDraftConstOrVarOpts;

/* Tweak or Intersect :: PRO_E_DRAFT_TWEAK_OR_INTERSEC */
typedef enum 
{
 PRO_DRAFT_UI_TWEAK = 0,             /* Tweak */
 PRO_DRAFT_UI_INTERSECT = 1         /* Intersect */
} ProDraftTweakOrIntsctOpts;

/* Extend :: PRO_E_DRAFT_EXTEND */
typedef enum 
{
 PRO_DRAFT_UI_NO_EXTEND = 0,  /* Intersect with Extend */
 PRO_DRAFT_UI_EXTEND =   1         /* Intersect with Extend */
} ProDraftExtendOpts;


/* Split :: PRO_E_DRAFT_SPLIT */
typedef enum 
{
 PRO_DRAFT_UI_SPLIT_NONE = 0,   /* No Split */
 PRO_DRAFT_UI_SPLIT_NEUT = 1,   /* Split on Draft hinge */
 PRO_DRAFT_UI_SPLIT_SURF = 2,   /* Split at Surface */
 PRO_DRAFT_UI_SPLIT_SCTCH = 3  /* Split at Sketch */
} ProDraftSplitOpts;

/* Dependence :: PRO_E_DRAFT_DEPENDENT_1 / _2 */
typedef enum 
{
 PRO_DRAFT_UI_INDEPENDENT = 0,  /* Side drafted independently */ 
 PRO_DRAFT_UI_DEPENDENT = 1,    /* Side drafted dependently */ 
 PRO_DRAFT_UI_NONE = 2         /* Side is not drafted */
} ProDraftDependenceOpts;

/* Type of Draft hinge :: PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_1 / _2 */
typedef enum 
{
 PRO_DRAFT_UI_NO_NEUT = 0,      /* None, use draft hinge for an other side */
 PRO_DRAFT_UI_PLANE = 1,        /* Plane */
 PRO_DRAFT_UI_CURVE = 2,        /* Curve */
 PRO_DRAFT_UI_QUILT = 3
} ProDraftHingeType;   

PRO_END_C_DECLS

#endif
