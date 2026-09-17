#ifndef PROCHAMFERH
#define PROCHAMFERH


#include <ProToolkit.h>
 


PRO_BEGIN_C_DECLS
 
/*

Feature element tree for Chamfer

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |--PRO_E_RNDCH_SETS
     |    |
     |    |--PRO_E_RNDCH_SET
     |         |
     |         |--PRO_E_RNDCH_DIMENSIONAL_SCHEMA
     |         |--PRO_E_RNDCH_CHAMFER_SHAPE
     |         |--PRO_E_RNDCH_REFERENCES
     |         |    |
     |         |    |--PRO_E_RNDCH_REFERENCE_TYPE
     |         |    |--PRO_E_STD_CURVE_COLLECTION_APPL
     |         |    |--PRO_E_RNDCH_REFERENCE_SURFACE1
     |         |    |--PRO_E_RNDCH_REFERENCE_SURFACE2
     |         |    |--PRO_E_RNDCH_REFERENCE_EDGE1
     |         |    |--PRO_E_RNDCH_REFERENCE_SURFACE
     |         |
     |         |--PRO_E_RNDCH_COMPOUND_EXT_OPTIONS
     |         |    |
     |         |    |--PRO_E_RNDCH_AUTO_BLEND
     |         |    |--PRO_E_RNDCH_TERM_SURFACE
     |         |
     |         |--PRO_E_RNDCH_RADII
     |         |    |
     |         |    |--PRO_E_RNDCH_RADIUS
     |         |         |
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
     |         |--PRO_E_RNDCH_AMBIGUITY
     |
     |--PRO_E_RNDCH_ATTACH_TYPE
     |--PRO_E_RNDCH_TRANSITIONS
          |
          |--PRO_E_RNDCH_TRANSITION
               |
               |--PRO_E_RNDCH_TRANS_TYPE
               |--PRO_E_RNDCH_TRANS_CAP
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
PRO_E_FEATURE_TYPE               Feature Type        PRO_VALUE_TYPE_INT       PRO_FEAT_CHAMFER
PRO_E_STD_FEATURE_NAME           Feature Name        PRO_VALUE_TYPE_WSTRING   Wide character string
PRO_E_RNDCH_SETS                 Sets                Array
PRO_E_RNDCH_SET                  Set                 Compound
PRO_E_RNDCH_DIMENSIONAL_SCHEMA   Dimensional Schema  PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_CHAMFER_SHAPE        Chamfer shape       PRO_VALUE_TYPE_INT       See below
PRO_E_RNDCH_REFERENCES           References          Compound
PRO_E_RNDCH_REFERENCE_TYPE       Reference type      PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_STD_CURVE_COLLECTION_APPL  Reference Edges     Chain Collection
PRO_E_RNDCH_REFERENCE_SURFACE1   Reference Surface1  PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_REFERENCE_SURFACE2   Reference Surface2  PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_REFERENCE_EDGE1      Reference Edge1     PRO_VALUE_TYPE_SELECTION PRO_EDGE
PRO_E_RNDCH_REFERENCE_SURFACE    Reference Surface   PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_COMPOUND_EXT_OPTIONS Ext options         Compound
PRO_E_RNDCH_AUTO_BLEND           Auto Blend          PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_RNDCH_TERM_SURFACE         Terminating Surface PRO_VALUE_TYPE_SELECTION See ProRound.h
PRO_E_RNDCH_RADII                Radii               Array
PRO_E_RNDCH_RADIUS               Radius              Compound
PRO_E_RNDCH_LEG1                 Leg1                Compound
PRO_E_RNDCH_LEG2                 Leg2                Compound
PRO_E_RNDCH_LEG_TYPE             Leg Type            PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_RNDCH_LEG_VALUE            Leg Value           PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_REFERENCE_EDGE       Reference Edge      PRO_VALUE_TYPE_SELECTION PRO_EDGE
PRO_E_RNDCH_REFERENCE_POINT      Reference Point     PRO_VALUE_TYPE_SELECTION PRO_POINT
PRO_E_RNDCH_AMBIGUITY            Ambiguity
PRO_E_RNDCH_ATTACH_TYPE          Attach type         PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_RNDCH_TRANSITIONS          Transitions         Array
PRO_E_RNDCH_TRANSITION           Transition          Compound
PRO_E_RNDCH_TRANS_TYPE           Type                PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_RNDCH_TRANS_CAP            Capping surface     PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_RNDCH_TRANS_PATCH_DATA     Patch Data          Compound
PRO_E_RNDCH_TRANS_PATCH_REF_SURF Arc Surface         PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_RNDCH_TRANS_PATCH_RAD_OPT  Arc Radius options  PRO_VALUE_TYPE_INT       See ProNewRound.h
PRO_E_RNDCH_TRANS_ARC_RADIUS     Arc Radius          PRO_VALUE_TYPE_DOUBLE
PRO_E_RNDCH_TRANS_STOP_DATA      Capping surface     Compound
PRO_E_RNDCH_TRANS_STOP_REF_TYPE  Reference Type      PRO_VALUE_TYPE_INT       See ProRound.h
PRO_E_RNDCH_TRANS_STOP_REFERENCE Stop Reference      PRO_VALUE_TYPE_SELECTION PRO_SURFACE,
                                                                              PRO_POINT,
                                                                              PRO_DATUM_PLANE


 *****************************************************************************
         DIFFERENT TYPES OF CHAMFERS AND ELEMENTS REQUIRED FOR THEM
 *****************************************************************************

 Elements required for all types of chamfer
-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_FEATURE_TYPE                   | PRO_FEAT_CHAMFER                     |
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
| PRO_E_RNDCH_DIMENSIONAL_SCHEMA       | Chamfer type                         |
| PRO_E_RNDCH_CHAMFER_SHAPE            | Chamfer shape                        |
| PRO_E_RNDCH_REFERENCES               | Compound element                     |
| PRO_E_RNDCH_RADII                    | Array element                        |
| PRO_E_RNDCH_RADIUS                   | Compound element. Only one should be |
|                                      | present in each set                  |
| PRO_E_RNDCH_AMBIGUITY                |                                      |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_REFERENCES should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_REFERENCE_TYPE           | Mandatory                            |
| PRO_E_STD_CURVE_COLLECTION_APPL      | Required for edge chamfer            |
| PRO_E_RNDCH_REFERENCE_SURFACE1       | Required for surf surf chamfer       |
|                                      | Required if                          |
|                                      | PRO_E_RNDCH_REFERENCE_TYPE ==        |
|                                      | PRO_ROUND_REF_SURF_SURF              |
| PRO_E_RNDCH_REFERENCE_SURFACE2       | Required for edge surf or surf surf  |
|                                      | chamfer                              |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_SURF_SURF ||         |
|                                      |   PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      |   PRO_ROUND_REF_EDGE_SURF )          |
| PRO_E_RNDCH_REFERENCE_EDGE1          | Required for edge surf chamfer       |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_REFERENCE_TYPE ==      |
|                                      | PRO_ROUND_REF_EDGE_SURF)             |
| PRO_E_RNDCH_REFERENCE_SURFACE        | Required if                          |
|                                      | ( PRO_E_RNDCH_DIMENSIONAL_SCHEMA ==  |
|                                      |   PRO_CHM_D1_X_D2  ||                |
|                                      | ( PRO_E_RNDCH_DIMENSIONAL_SCHEMA ==  |
|                                      |   PRO_CHM_ANG_X_D ) ||               |
|                                      | ( PRO_E_RNDCH_DIMENSIONAL_SCHEMA ==  |
|                                      |   PRO_CHM_O1_X_O2 )                  |
-------------------------------------------------------------------------------

 Each PRO_E_RNDCH_RADIUS should have the following elements

-------------------------------------------------------------------------------
|  Element Id                          | Value                                |
-------------------------------------------------------------------------------
| PRO_E_RNDCH_LEG1                     | Compound                             |
| PRO_E_RNDCH_LEG2                     | Required for D1xD2 and AnglexD       ||                                      | chamfers                             |
|                                      | Required if                          |
|                                      | ( PRO_E_RNDCH_DIMENSIONAL_SCHEMA ==  |
|                                      |   PRO_CHM_D1_X_D2  ||                |
|                                      | ( PRO_E_RNDCH_DIMENSIONAL_SCHEMA ==  |
|                                      |   PRO_CHM_ANG_X_D ) ||               |
|                                      | ( PRO_E_RNDCH_DIMENSIONAL_SCHEMA ==  |
|                                      |   PRO_CHM_O1_X_O2 )                  |
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
| PRO_E_RNDCH_TRANS_PATCH_DATA         | Required if PRO_E_RNDCH_TRANS_TYPE ==|
|                                      | PRO_ROUND_TRANS_PATCH                |
| PRO_E_RNDCH_TRANS_STOP_DATA          | Required if PRO_E_RNDCH_TRANS_TYPE ==|
|                                      | PRO_ROUND_TRANS_STOP_AT_REF          |
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

*/

/* Valid values for PRO_E_RNDCH_DIMENSIONAL_SCHEMA */

typedef enum pro_chamfer_schema
{
   PRO_CHM_45_X_D    = 601,
   PRO_CHM_D_X_D     = 602,
   PRO_CHM_D1_X_D2   = 603,
   PRO_CHM_ANG_X_D   = 604,
   PRO_CHM_O_X_O     = 607, 
   PRO_CHM_O1_X_O2   = 608
} ProChmSchema;

/* Valid values for PRO_E_RNDCH_CHAMFER_SHAPE */
typedef enum pro_chamfer_shape
{
   PRO_CHM_TANGENT_LEGS      = PRO_B_FALSE,
   PRO_CHM_OFFSET_SURFACE    = PRO_B_TRUE
} ProChamferShape;

PRO_END_C_DECLS

#endif
