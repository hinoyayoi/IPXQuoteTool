#ifndef PROROUNDH
#define PROROUNDH
 

 
#include <ProToolkit.h>
 
PRO_BEGIN_C_DECLS


/*****************************************************************************

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |--PRO_E_RNDCH_SETS
     |    |
     |    |--PRO_E_RNDCH_SET
     |         |
     |         |--PRO_E_RNDCH_SHAPE_OPTIONS
     |         |--PRO_E_RNDCH_VARIABLE_RADIUS
     |         |--PRO_E_RNDCH_COMPOUND_CONIC
     |         |    |
     |         |    |--PRO_E_RNDCH_CONIC_TYPE
     |         |    |--PRO_E_RNDCH_CONIC_VALUE
     |         |    |--PRO_E_RNDCH_CONIC_DEP_OPT
     |         |
     |         |--PRO_E_RNDCH_REFERENCES
     |         |    |
     |         |    |--PRO_E_RNDCH_REFERENCE_TYPE
     |         |    |--PRO_E_STD_CURVE_COLLECTION_APPL
     |         |    |--PRO_E_RNDCH_REFERENCE_SURFACE1
     |         |    |--PRO_E_RNDCH_REFERENCE_SURFACE2
     |         |    |--PRO_E_RNDCH_REFERENCE_EDGE1
     |         |    |--PRO_E_RNDCH_REFERENCE_EDGE2
     |         |    |--PRO_E_RNDCH_REPLACE_SURFACE
     |         |
     |         |--PRO_E_RNDCH_COMPOUND_SPINE
     |         |    |
     |         |    |--PRO_E_RNDCH_BALL_SPINE
     |         |    |--PRO_E_STD_CURVE_COLLECTION_APPL
     |         |
     |         |--PRO_E_RNDCH_AUTO_CONTINUE
     |         |--PRO_E_RNDCH_COMPOUND_EXT_OPTIONS
     |         |    |
     |         |    |--PRO_E_RNDCH_AUTO_BLEND
     |         |    |--PRO_E_RNDCH_TERM_SURFACE
     |         |
     |         |--PRO_E_RNDCH_RADII
     |         |    |
     |         |    |--PRO_E_RNDCH_RADIUS
     |         |         |
     |         |         |--PRO_E_STD_POINT_COLLECTION_APPL
     |         |         |--PRO_E_RNDCH_LEG1
     |         |         |    |
     |         |         |    |--PRO_E_RNDCH_LEG_TYPE
     |         |         |    |--PRO_E_RNDCH_LEG_VALUE
     |         |         |    |--PRO_E_RNDCH_REFERENCE_EDGE
     |         |         |    |--PRO_E_RNDCH_REFERENCE_POINT
     |         |         |
     |         |         |--PRO_E_RNDCH_LEG2
     |         |              |
     |         |              |--PRO_E_RNDCH_LEG_TYPE
     |         |              |--PRO_E_RNDCH_LEG_VALUE
     |         |              |--PRO_E_RNDCH_REFERENCE_EDGE
     |         |              |--PRO_E_RNDCH_REFERENCE_POINT
     |         |
     |         |--PRO_E_STD_CURVE_COLLECTION_APPL
     |         |--PRO_E_RNDCH_AMBIGUITY
     |
     |--PRO_E_RNDCH_ATTACH_TYPE
     |--PRO_E_RNDCH_TRANSITIONS
          |
          |--PRO_E_RNDCH_TRANSITION
               |
               |--PRO_E_RNDCH_TRANS_TYPE
               |--PRO_E_RNDCH_TRANS_CAP
               |--PRO_E_RNDCH_TRANS_SPHERE_DATA
               |    |
               |    |--PRO_E_RNDCH_TRANS_RADIUS_OPTIONS
               |    |--PRO_E_RNDCH_TRANS_SPHERE_RADIUS
               |    |--PRO_E_RNDCH_TRANS_LEG1_OPTIONS
               |    |--PRO_E_RNDCH_TRANS_LEG1_VALUE
               |    |--PRO_E_RNDCH_TRANS_LEG2_OPTIONS
               |    |--PRO_E_RNDCH_TRANS_LEG2_VALUE
               |    |--PRO_E_RNDCH_TRANS_LEG3_OPTIONS
               |    |--PRO_E_RNDCH_TRANS_LEG3_VALUE
               |
               |--PRO_E_RNDCH_TRANS_PATCH_DATA
               |    |
               |    |--PRO_E_RNDCH_TRANS_PATCH_REF_SURF
               |    |--PRO_E_RNDCH_TRANS_PATCH_RAD_OPT
               |    |--PRO_E_RNDCH_TRANS_ARC_RADIUS
               |
               |--PRO_E_RNDCH_TRANS_STOP_DATA
                    |
                    |--PRO_E_RNDCH_TRANS_STOP_REF_TYPE
                    |--PRO_E_RNDCH_TRANS_STOP_REFERENCE


---------------------------------------------------------------------------------------------------
Element Id                       Element Name        Data Type                Valid Values
---------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type        PRO_VALUE_TYPE_INT       PRO_FEAT_ROUND
PRO_E_STD_FEATURE_NAME           Feature Name        PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_RNDCH_SETS                 Sets                Array
PRO_E_RNDCH_SET                  Set                 Compound
PRO_E_RNDCH_SHAPE_OPTIONS        Shape options       PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_VARIABLE_RADIUS      Variable Radius     PRO_VALUE_TYPE_INT       Not Used
PRO_E_RNDCH_COMPOUND_CONIC       Conic               Compound
PRO_E_RNDCH_CONIC_TYPE           Conic Type          PRO_VALUE_TYPE_INT       See Below
PRO_E_RNDCH_CONIC_VALUE          Conic value         PRO_VALUE_TYPE_DOUBLE    Range 0.05 to 0.95
PRO_E_RNDCH_CONIC_DEP_OPT        Independent         PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_REFERENCES           References          Compound
PRO_E_RNDCH_REFERENCE_TYPE       Reference type      PRO_VALUE_TYPE_INT       See below
PRO_E_STD_CURVE_COLLECTION_APPL  Reference Edges     Chain Collection
PRO_E_RNDCH_REFERENCE_SURFACE1   Reference Surface1  PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_REFERENCE_SURFACE2   Reference Surface2  PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_REFERENCE_EDGE1      Reference Edge1     PRO_VALUE_TYPE_SELECTION PRO_EDGE
PRO_E_RNDCH_REFERENCE_EDGE2      Reference Edge2     PRO_VALUE_TYPE_SELECTION PRO_EDGE
PRO_E_RNDCH_REPLACE_SURFACE      Replace Surface     PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_COMPOUND_SPINE       Spine               Compound
PRO_E_RNDCH_BALL_SPINE           Ball/Spine          PRO_VALUE_TYPE_INT       See below
PRO_E_STD_CURVE_COLLECTION_APPL  Spine curve         Chain Collection
PRO_E_RNDCH_AUTO_CONTINUE        Auto Continue       PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_COMPOUND_EXT_OPTIONS Ext options         Compound
PRO_E_RNDCH_AUTO_BLEND           Auto Blend          PRO_VALUE_TYPE_INT       Not Used
PRO_E_RNDCH_TERM_SURFACE         Terminating Surface PRO_VALUE_TYPE_SELECTION Not Used
PRO_E_RNDCH_RADII                Radii               Array
PRO_E_RNDCH_RADIUS               Radius              Compound
PRO_E_STD_POINT_COLLECTION_APPL  Radius Point        Point Collection         Single point
PRO_E_RNDCH_LEG1                 Leg1                Compound
PRO_E_RNDCH_LEG2                 Leg2                Compound
PRO_E_RNDCH_LEG_TYPE             Leg Type            PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_LEG_VALUE            Leg Value           PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_REFERENCE_EDGE       Reference Edge      PRO_VALUE_TYPE_SELECTION PRO_EDGE
PRO_E_RNDCH_REFERENCE_POINT      Reference Point     PRO_VALUE_TYPE_SELECTION PRO_POINT
PRO_E_STD_CURVE_COLLECTION_APPL  Rad Curve           Chain Collection
PRO_E_RNDCH_AMBIGUITY            Ambiguity
PRO_E_RNDCH_ATTACH_TYPE          Attach type         PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANSITIONS          Transitions         Array
PRO_E_RNDCH_TRANSITION           Transition          Compound
PRO_E_RNDCH_TRANS_TYPE           Type                PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_CAP            Capping surface     PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_SPHERE_DATA    Sphere Data         Compound
PRO_E_RNDCH_TRANS_RADIUS_OPTIONS Radius options      PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_SPHERE_RADIUS  Sphere Radius       PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_TRANS_LEG1_OPTIONS   Leg1 Options        PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_LEG2_OPTIONS   Leg2 Options        PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_LEG3_OPTIONS   Leg3 Options        PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_LEG1_VALUE     Leg1 Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_TRANS_LEG2_VALUE     Leg2 Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_TRANS_LEG3_VALUE     Leg3 Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_TRANS_PATCH_DATA     Patch Data          Compound
PRO_E_RNDCH_TRANS_PATCH_REF_SURF Arc Surface         PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_TRANS_PATCH_RAD_OPT  Arc Radius options  PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_ARC_RADIUS     Arc Radius          PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_TRANS_STOP_DATA      Capping surface     Compound
PRO_E_RNDCH_TRANS_STOP_REF_TYPE  Reference Type      PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_TRANS_STOP_REFERENCE Stop Reference      PRO_VALUE_TYPE_SELECTION PRO_SURFACE,
                                                                              PRO_POINT,
                                                                              PRO_DATUM_PLANE

*****************************************************************************/

/******************************************************************************
         DIFFERENT TYPES OF ROUNDS AND ELEMENTS REQUIRED FOR THEM
 *****************************************************************************

 Elements required for all types of rounds
-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_FEATURE_TYPE                   | PRO_FEAT_ROUND                       |
| PRO_E_STD_FEATURE_NAME               | Name of the feature                  |
| PRO_E_RNDCH_SETS                     | Array element                        |
| PRO_E_RNDCH_SET                      | Compound element                     |
|                                      | One element per set present in       |
|                                      | PRO_E_RNDCH_SETS                     |
| PRO_E_RNDCH_ATTACH_TYPE              | Attachment type                      |
| PRO_E_RNDCH_TRANSITIONS              | Array element                        |
-------------------------------------------------------------------------------

 Each set (PRO_E_RNDCH_SET) should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_SHAPE_OPTIONS            | Shape type                           |
| PRO_E_RNDCH_COMPOUND_CONIC           | Compound element                     |
| PRO_E_RNDCH_CONIC_TYPE               | Conic or circular                    |
| PRO_E_RNDCH_REFERENCES               | Compound element                     |
| PRO_E_RNDCH_COMPOUND_SPINE           | Compound element                     |
| PRO_E_RNDCH_BALL_SPINE               | Rolling Ball or normal to spine      |
| PRO_E_RNDCH_AUTO_CONTINUE            | Enabled or Disabled                  |
|                                      | Required if                          |
|                                      | PRO_E_RNDCH_REFERENCE_TYPE ==        |
|                                      | PRO_ROUND_REF_EDGE                   |
| PRO_E_RNDCH_RADII                    | Array element                        |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_SHAPE_OPTIONS !=       |
|                                      |   PRO_ROUND_TYPE_THROUGH_CURVE  &&   |
|                                      |   PRO_E_RNDCH_SHAPE_OPTIONS !=       |
|                                      |   PRO_ROUND_TYPE_FULL )              |
| PRO_E_RNDCH_RADIUS                   | Compound element. Should be one per  |
|                                      | radius present                       |
| PRO_E_STD_CURVE_COLLECTION_APPL      | Required if                          |
|                                      | PRO_E_RNDCH_SHAPE_OPTIONS ==         |
|                                      | PRO_ROUND_TYPE_THROUGH_CURVE         |
| PRO_E_RNDCH_AMBIGUITY                |                                      |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_COMPOUND_CONIC should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_CONIC_VALUE              | Required if PRO_E_RNDCH_CONIC_TYPE ==|
|                                      | PRO_ROUND_CONIC_ENABLE               |
| PRO_E_RNDCH_CONIC_DEP_OPT            | Required if PRO_E_RNDCH_CONIC_TYPE ==|
|                                      | PRO_ROUND_CONIC_ENABLE               |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_REFERENCES should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_REFERENCE_TYPE           | Mandatory                            |
| PRO_E_STD_CURVE_COLLECTION_APPL      | Required for edge chain round        |
|                                      | Required if                          |
|                                      | PRO_E_RNDCH_REFERENCE_TYPE ==        |
|                                      | PRO_ROUND_REF_EDGE                   |
| PRO_E_RNDCH_REFERENCE_SURFACE1       | Required for surf surf or surf surf  |
|                                      | surf full round                      |
|                                      | Required if                          |
|                                      | PRO_E_RNDCH_REFERENCE_TYPE ==        |
|                                      | PRO_ROUND_REF_SURF_SURF              |
| PRO_E_RNDCH_REFERENCE_SURFACE2       | Required for edge surf, surf surf or |
|                                      | surf surf surf full round            |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_SURF_SURF ||         |
|                                      |   PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_EDGE_SURF )          |
| PRO_E_RNDCH_REFERENCE_EDGE1          | Required for edge surf or edge pair  |
|                                      | full round                           |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      | PRO_ROUND_REF_EDGE_SURF)  ||         |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_EDGE_EDGE &&         |
|                                      |   PRO_E_RNDCH_SHAPE_OPTIONS ==       |
|                                      |   PRO_ROUND_TYPE_FULL)               |
| PRO_E_RNDCH_REFERENCE_EDGE2          | Required for edge pair full round    |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_EDGE_EDGE &&         |
|                                      |   PRO_E_RNDCH_SHAPE_OPTIONS ==       |
|                                      |   PRO_ROUND_TYPE_FULL)               |
| PRO_E_RNDCH_REPLACE_SURFACE          | Required for surf surf surf full     |
|                                      | round                                |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_SURF_SURF &&         |
|                                      |   PRO_E_RNDCH_SHAPE_OPTIONS ==       |
|                                      |   PRO_ROUND_TYPE_FULL)               |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_COMPOUND_SPINE should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_STD_CURVE_COLLECTION_APPL      | Required for normal to spine round   |
|                                      | Required if                          |
|                                      | PRO_E_RNDCH_BALL_SPINE ==            |
|                                      | PRO_ROUND_NORMAL_TO_SPINE            |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_RADIUS should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_STD_POINT_COLLECTION_APPL      | Required for variable rounds         |
|                                      | required if                          |
|                                      | PRO_E_RNDCH_SHAPE_OPTIONS ==         |
|                                      | PRO_ROUND_TYPE_VARIABLE              |
| PRO_E_RNDCH_LEG1                     | Compound                             |
| PRO_E_RNDCH_LEG2                     | Required for conic rounds            |
|                                      | Required if                          |
|                                      | PRO_E_RNDCH_CONIC_DEP_OPT ==         |
|                                      | PRO_ROUND_CONIC_INDEPENDENT          |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_LEG1 or PRO_E_RNDCH_LEG2 should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_LEG_TYPE                 | Mandatory                            |
| PRO_E_RNDCH_LEG_VALUE                | Required if PRO_E_RNDCH_LEG_TYPE ==  |
|                                      | PRO_ROUND_RADIUS_TYPE_VALUE          |
| PRO_E_RNDCH_REFERENCE_EDGE           | Required if PRO_E_RNDCH_LEG_TYPE ==  |
|                                      | PRO_ROUND_RADIUS_THROUGH_POINT       |
| PRO_E_RNDCH_REFERENCE_POINT          | Required if PRO_E_RNDCH_LEG_TYPE ==  |
|                                      | PRO_ROUND_RADIUS_THROUGH_POINT       |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_TRANSITIONS can have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_TRANSITION               | One element for each user defined    |
|                                      | transition                           |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_TRANSITION should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_TRANS_TYPE               | Mandatory                            |
| PRO_E_RNDCH_TRANS_CAP                | Mandatory                            |
| PRO_E_RNDCH_TRANS_SPHERE_DATA        | Required if PRO_E_RNDCH_TRANS_TYPE ==|
|                                      | PRO_ROUND_TRANS_SPHERE_CORNER        |
| PRO_E_RNDCH_TRANS_PATCH_DATA         | Required if PRO_E_RNDCH_TRANS_TYPE ==|
|                                      | PRO_ROUND_TRANS_PATCH                |
| PRO_E_RNDCH_TRANS_STOP_DATA          | Required if PRO_E_RNDCH_TRANS_TYPE ==|
|                                      | PRO_ROUND_TRANS_STOP_AT_REF          |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_TRANS_SPHERE_DATA should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_TRANS_RADIUS_OPTIONS     | Mandatory                            |
| PRO_E_RNDCH_TRANS_SPHERE_RADIUS      | Required if                          |
|                                      | PRO_E_RNDCH_TRANS_RADIUS_OPTIONS ==  |
|                                      | PRO_ROUND_TRANS_RADIUS_ENTER_VALUE   |
| PRO_E_RNDCH_TRANS_LEG1_OPTIONS       | Mandatory                            |
| PRO_E_RNDCH_TRANS_LEG1_VALUE         | Required if                          |
|                                      | PRO_E_RNDCH_TRANS_LEG1_OPTIONS ==    |
|                                      | PRO_ROUND_TRANS_RADIUS_ENTER_VALUE   |
| PRO_E_RNDCH_TRANS_LEG2_OPTIONS       | Mandatory                            |
| PRO_E_RNDCH_TRANS_LEG2_VALUE         | Required if                          |
|                                      | PRO_E_RNDCH_TRANS_LEG2_OPTIONS ==    |
|                                      | PRO_ROUND_TRANS_RADIUS_ENTER_VALUE   |
| PRO_E_RNDCH_TRANS_LEG3_OPTIONS       | Mandatory                            |
| PRO_E_RNDCH_TRANS_LEG3_VALUE         | Required if                          |
|                                      | PRO_E_RNDCH_TRANS_LEG3_OPTIONS ==    |
|                                      | PRO_ROUND_TRANS_RADIUS_ENTER_VALUE   |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_TRANS_PATCH_DATA should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_TRANS_PATCH_REF_SURF     | Mandatory                            |
| PRO_E_RNDCH_TRANS_PATCH_RAD_OPT      | Mandatory                            |
| PRO_E_RNDCH_TRANS_ARC_RADIUS         | Required if                          |
|                                      | PRO_E_RNDCH_TRANS_PATCH_RAD_OPT ==   |
|                                      | PRO_ROUND_TRANS_RADIUS_ENTER_VALUE   |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_TRANS_STOP_DATA should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_TRANS_STOP_REF_TYPE      | Mandatory                            |
| PRO_E_RNDCH_TRANS_STOP_REFERENCE     | Mandatory                            |
-------------------------------------------------------------------------------


******************************************************************************/

/* Valid values for PRO_E_RNDCH_SHAPE_OPTIONS */
typedef enum pro_round_shape_type
{
   PRO_ROUND_TYPE_CONSTANT        = 0,
   PRO_ROUND_TYPE_VARIABLE        = 2,
   PRO_ROUND_TYPE_FULL            = 8,
   PRO_ROUND_TYPE_THROUGH_CURVE   = 16,
   PRO_ROUND_TYPE_CHORDAL         = (1<<18)
} ProRoundShapeType;

/* Valid values for PRO_E_RNDCH_AUTO_CONTINUE */
typedef enum pro_round_auto_cont_type
{
   PRO_ROUND_AUTO_CONT_DISABLE     = PRO_B_FALSE,
   PRO_ROUND_AUTO_CONT_ENABLE      = PRO_B_TRUE /* Reserved for future use. Not currently supported.  */
} ProRoundAutoContType; 



/* Valid values for PRO_E_RNDCH_CONIC_TYPE */
typedef enum pro_round_conic_type
{
   PRO_ROUND_CONIC_ENABLE         = 1,
   PRO_ROUND_CONIC_DISABLE        = 2,
   PRO_ROUND_CURV_CONTINUOUS      = 3 
} ProRoundConicType;

/* Valid values for PRO_E_RNDCH_CONIC_DEP_OPT */
typedef enum pro_round_conic_Independent_type
{
   PRO_ROUND_CONIC_DEPENDENT      = PRO_B_FALSE,
   PRO_ROUND_CONIC_INDEPENDENT    = PRO_B_TRUE
} ProRoundConicIndependentType;

/* Valid values for PRO_E_RNDCH_REFERENCE_TYPE */
typedef enum pro_round_reference_type
{
   PRO_ROUND_REF_EDGE             = 1,   /* For round and chamfer */
   PRO_ROUND_REF_SURF_SURF        = 2,   /* For round and chamfer */
   PRO_ROUND_REF_EDGE_SURF        = 3,   /* For round and chamfer */
   PRO_ROUND_REF_EDGE_EDGE        = 4    /* Only for round */
} ProRoundReferenceType;

/* Valid values for PRO_E_RNDCH_BALL_SPINE */
typedef enum pro_round_cross_section_type
{
   PRO_ROUND_ROLLING_BALL         = PRO_B_FALSE,
   PRO_ROUND_NORMAL_TO_SPINE      = PRO_B_TRUE
} ProRoundCrossSectionType;

/* Valid values for PRO_E_RNDCH_LEG_TYPE */
typedef enum pro_round_radius_type
{
   PRO_ROUND_RADIUS_TYPE_VALUE    = 1,
   PRO_ROUND_RADIUS_THROUGH_POINT = 2
} ProRoundRadiusType;

/* Valid values for PRO_E_RNDCH_ATTACH_TYPE */
typedef enum pro_round_attach_type
{
   PRO_ROUND_ATTACHED             = 0,
   PRO_ROUND_UNATTACHED           = 9,
   PRO_ROUND_CAPPED_ENDS          = 15
} ProRoundAttachType;

/* Valid values for PRO_E_RNDCH_TRANS_TYPE */
typedef enum pro_round_trans_type
{
   PRO_ROUND_TRANS_INTERSECT      = 1,
   PRO_ROUND_TRANS_BLEND          = 2,
   PRO_ROUND_TRANS_STOP           = 3,
   PRO_ROUND_TRANS_CONTINUE       = 4,
   PRO_ROUND_TRANS_SPHERE_CORNER  = 5,   /* For Round Only */
   PRO_ROUND_TRANS_PATCH          = 6,
   PRO_ROUND_TRANS_BLEND_3SRF     = 7,
   PRO_ROUND_TRANS_PLANE_CORNER   = 10,  /* For Chamfer Only */
   PRO_ROUND_TRANS_RBALL          = 12,
   PRO_ROUND_TRANS_STOP_0_SIDE    = 13,
   PRO_ROUND_TRANS_STOP_1_SIDE    = 14,
   PRO_ROUND_TRANS_STOP_2_SIDE    = 15,
   PRO_ROUND_TRANS_STOP_AT_REF    = 16,
   PRO_ROUND_TRANS_STOP_FULL      = 18,  /* For Round Only */
   PRO_ROUND_TRANS_STOP_2_WE      = 19   /* For Round Only */
} ProRoundTransType;

/* Valid values for PRO_E_RNDCH_TRANS_CAP */
typedef enum pro_round_trans_cap_type
{
   PRO_ROUND_CAPPING_SURF_DISABLE = PRO_B_FALSE,
   PRO_ROUND_CAPPING_SURF_ENABLE  = PRO_B_TRUE
} ProRoundTransCapType;

/* Valid values for PRO_E_RNDCH_TRANS_RADIUS_OPTIONS,
                    PRO_E_RNDCH_TRANS_LEG1_OPTIONS,
                    PRO_E_RNDCH_TRANS_LEG2_OPTIONS,
                    PRO_E_RNDCH_TRANS_LEG3_OPTIONS,
                    PRO_E_RNDCH_TRANS_PATCH_RAD_OPT */
typedef enum pro_round_trans_radius_type
{
   PRO_ROUND_TRANS_RADIUS_ENTER_VALUE = PRO_B_FALSE,
   PRO_ROUND_TRANS_RADIUS_AUTOMATIC   = PRO_B_TRUE
} ProRoundTransRadiusType;

/* Valid values for PRO_E_RNDCH_TRANS_STOP_REF_TYPE */
typedef enum pro_round_trans_stop_ref_type
{
   PRO_ROUND_TRANS_REF_NO_REF      = 0,
   PRO_ROUND_TRANS_REF_GEOM        = 1,
   PRO_ROUND_TRANS_REF_PNTVTX      = 2,
   PRO_ROUND_TRANS_REF_DTMPLN      = 3,
   PRO_ROUND_TRANS_REF_ISOLINE     = 4

} ProRoundTransStopRefType;

extern ProError ProRoundIsAutoRoundMember ( ProFeature *p_feat_handle,
                                            ProBoolean *p_is_auto_round_member);
/*
   Purpose:  Determines whether the specified feature is a member of the Auto
             Round Feature.

   Input Arguments:
      p_feat_handle          - The feature to check for completeness.

   Output Arguments:
      p_is_auto_round_member - If the feature is an Auto Round Member,
                               this is PRO_B_TRUE. Otherwise,
                               this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR    -  The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  -  The input argument is invalid.
*/

PRO_END_C_DECLS
 
#endif
 
 

