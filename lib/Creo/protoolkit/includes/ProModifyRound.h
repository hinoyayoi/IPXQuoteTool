#ifndef PROMODIFYROUND_H
#define PROMODIFYROUND_H



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
    |--PRO_E_STD_SURF_COLLECTION_APPL
    |
    |--PRO_E_MODRND_REMOVE
    |
    |--PRO_E_MODRND_CONIC_OPT
    |
    |--PRO_E_MODRND_RAD_VAL
    |
    |--PRO_E_MODRND_DIM2_VAL
    |
    |--PRO_E_MODRND_CONIC_VAL
    |
    |--PRO_E_MODRND_OPTS
    |  |
    |  |-PRO_E_MODRND_ATTACH
    |  |
    |  |-PRO_E_MODRND_CLOSEGEOM
    |  |
    |  |-PRO_E_MODRND_RMV_INTERF_RND
    |
    |--PRO_E_STD_FLEX_PROPAGATION

===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------
  Element Id                     Element Name          Data Type
------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME           Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_MODRND_CONIC_OPT           Conic Type            PRO_VALUE_TYPE_INT
PRO_E_MODRND_RAD_VAL             New Radius Value      PRO_VALUE_TYPE_DOUBLE
PRO_E_MODRND_DIM2_VAL            New Secong Leg Value  PRO_VALUE_TYPE_DOUBLE
PRO_E_MODRND_CONIC_VAL           Nww Conic Dim value   PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_SURF_COLLECTION_APPL   Reference Surfaces    Surface Collection
PRO_E_MODRND_REMOVE              Remove geometry       PRO_VALUE_TYPE_INT
PRO_E_MODRND_OPTS                Options               Compound
PRO_E_MODRND_ATTACH              Attache Geometry      PRO_VALUE_TYPE_INT
PRO_E_MODRND_CLOSEGEOM           Close Geometry        PRO_VALUE_TYPE_INT
PRO_E_MODRND_RMV_INTERF_RND      Remove Interfering Rounds
                                                       PRO_VALUE_TYPE_INT
PRO_E_STD_FLEX_PROPAGATION       Propagation           PRO_VALUE_TYPE_SELECTION
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                      Element Name           Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type             PRO_FEAT_MOD_ROUND
PRO_E_STD_FEATURE_NAME           Feature Name                See Note 1
PRO_E_MODRND_CONIC_OPT           Conic Type                  See Note 9
PRO_E_MODRND_RAD_VAL             New Radius Value            See Note 2
PRO_E_MODRND_DIM2_VAL            New Secong Leg Value        See Note 10
PRO_E_MODRND_CONIC_VAL           New Radius Value            See Note 11
PRO_E_STD_SURF_COLLECTION_APPL   Reference Surfaces          See Note 3
PRO_E_MODRND_REMOVE              Remove geometry             See Note 8
PRO_E_MODRND_OPTS                Options               
PRO_E_MODRND_ATTACH              Attache Geometry            See Note 4
PRO_E_MODRND_CLOSEGEOM           Close Geometry              See Note 5
PRO_E_MODRND_RMV_INTERF_RND      Remove Interferring Rounds  See Note 6
PRO_E_STD_FLEX_PROPAGATION       Propagation                 See Note 7
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                                      Comment
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                                Mandatory
PRO_E_STD_FEATURE_NAME                            Mandatory
PRO_E_MODRND_CONIC_TYPE                           Mandatory
PRO_E_MODRND_RAD_VAL                              Mandatory
PRO_E_MODRND_DIM2_VAL                             Mandatory
PRO_E_MODRND_CONIC_VAL                            Mandatory
PRO_E_STD_SURF_COLLECTION_APPL                    Mandatory
PRO_E_MODRND_OPTS                                 Mandatory
PRO_E_MODRND_ATTACH                               Mandatory
PRO_E_MODRND_CLOSEGEOM                            Mandatory
PRO_E_MODRND_RMV_INTERF_RND                       Mandatory
PRO_E_STD_FLEX_PROPAGATION                        Optional
===============================================================================

(5) Notes

   Note-1  : Modify Round Radius feature name. Default is "MODIFY_ROUND"

   Note-2  : [(part epsilon / 10.0),  1.0e+06] for "D" schemas
             [-1.0e+06, 1.0e+06]               for "O" schemas

   Note-3  : Surface collection that includes round-like surfaces.

   Note-4  : Values from ProModRndAttach, described below.

   Note-5  : Values from ProModRndCloseGeom, described below.

   Note-6  : Values from ProModRndRmvRounds, described below.

   Note-7  : Header feature including Pattern header feature and
             Mirror header feature ( Symmetry Recognition )

   Note-8  : Values from ProModRndRmvGeom, described below. Determines whether
             to remove the round geometry or to edit it.

   Note-9  : Values from ProModRndConicOpt, described below.

   Note-10 : The range is identical to PRO_E_MODRND_RAD_VAL. The element
             is relevant only for independent (D1xD2 or O1xO2) conic options.

   Note-11 : The conic parameter's range is [0.05, 0.95], and it is relevant
             when the conic option is not PRO_MODRND_CONIC_NO.

==============================================================================*/

/* Valid values for PRO_E_MODRND_CONIC_OPT */
typedef enum pro_modrnd_conic_opt
{
  PRO_MODRND_CONIC_NO         = PRO_ROUND_CONIC_DISABLE,
  PRO_MODRND_CONIC_D_X_D      = PRO_ROUND_CONIC_ENABLE,
  PRO_MODRND_CONIC_D_X_D_C2   = PRO_ROUND_CURV_CONTINUOUS,
  PRO_MODRND_CONIC_D1_X_D2    = 4,
  PRO_MODRND_CONIC_D1_X_D2_C2 = 5
}ProModRndConicOpt;

/* Valid Values for PRO_E_MODRND_REMOVE */
typedef enum pro_modrnd_remove
{
   PRO_MODRND_REMOVE_GEOM       = PRO_B_TRUE,
   PRO_MODRND_EDIT_GEOM         = PRO_B_FALSE
}ProModRndRemove;

/* Valid Values for PRO_E_MODRND_ATTACH */
typedef enum pro_modrnd_attach
{
   PRO_MODRND_ATTACH_GEOM       = PRO_B_TRUE,
   PRO_MODRND_DONOT_ATTACH_GEOM = PRO_B_FALSE
}ProModRndAttach;


/* Valid Values for PRO_E_MODRND_CLOSEGEOM */
typedef enum pro_modrnd_close
{
   PRO_MODRND_CLOSE_GEOM       = PRO_B_TRUE,
   PRO_MODRND_DONOT_CLOSE_GEOM = PRO_B_FALSE 
}ProModRndCloseGeom;


/* Valid Values for PRO_E_MODRND_RMV_INTERF_RND */
typedef enum pro_modrnd_rmv_rounds
{
   PRO_MODRND_RMV_INTERF_RNDS       = PRO_B_TRUE,
   PRO_MODRND_DONOT_RMV_INTERF_RNDS = PRO_B_FALSE
}ProModRndRmvRounds;




PRO_END_C_DECLS
#endif

