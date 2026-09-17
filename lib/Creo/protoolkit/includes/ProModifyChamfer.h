#ifndef PROMODIFYCHAMFER_H
#define PROMODIFYCHAMFER_H



#include <ProToolkit.h>
#include <ProModifyRound.h>
#include <ProChamfer.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

    Mostly, Edit Chamfer feature is  based on Edit Round feature, therefore
    there are a lot of mutual elements between them.


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
    |--PRO_E_MODRND_DIMENSIONAL_SCHEMA
    |
    |--PRO_E_MODRND_RAD_VAL
    |
    |--PRO_E_MODRND_DIM2_VAL
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
PRO_E_STD_SURF_COLLECTION_APPL   Reference Surfaces    Surface Collection
PRO_E_MODRND_REMOVE              Remove                PRO_VALUE_TYPE_INT
PRO_E_MODRND_DIMENSIONAL_SCHEMA  Dimension Schema      PRO_VALUE_TYPE_INT
PRO_E_MODRND_RAD_VAL             Distance              PRO_VALUE_TYPE_DOUBLE
PRO_E_MODRND_DIM2_VAL            Second Distance       PRO_VALUE_TYPE_DOUBLE
PRO_E_MODRND_OPTS                Options               Compound
PRO_E_MODRND_ATTACH              Attach  Geometry      PRO_VALUE_TYPE_INT
PRO_E_MODRND_CLOSEGEOM           Close Geometry        PRO_VALUE_TYPE_INT
PRO_E_MODRND_RMV_INTERF_RND      Remove Interfering Geometry
                                                       PRO_VALUE_TYPE_INT
PRO_E_STD_FLEX_PROPAGATION       Propagation           PRO_VALUE_TYPE_SELECTION
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                      Element Name           Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type             PRO_FEAT_MOD_CHAMFER
PRO_E_STD_FEATURE_NAME           Feature Name                 See Note 1
PRO_E_STD_SURF_COLLECTION_APPL   Reference Surfaces           See Note 2
PRO_E_MODRND_REMOVE              Remove                       See Note 9
PRO_E_MODRND_DIMENSIONAL_SCHEMA  Dimension Schema             See Note 3
PRO_E_MODRND_RAD_VAL             New Radius Value             See Note 4
PRO_E_MODRND_DIM2_VAL            Second Distance              See Note 4
PRO_E_MODRND_OPTS                Options               
PRO_E_MODRND_ATTACH              Attache Geometry             See Note 5
PRO_E_MODRND_CLOSEGEOM           Close Geometry               See Note 6
PRO_E_MODRND_RMV_INTERF_RND      Remove Interfering Geometry  See Note 7
PRO_E_STD_FLEX_PROPAGATION       Propagation                  See Note 8
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                                      Comment
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                                Mandatory
PRO_E_STD_FEATURE_NAME                            Mandatory
PRO_E_STD_SURF_COLLECTION_APPL                    Mandatory
PRO_E_MODRND_REMOVE                               Mandatory
PRO_E_MODRND_DIMENSIONAL_SCHEMA                   Mandatory
PRO_E_MODRND_RAD_VAL                              Mandatory
PRO_E_MODRND_DIM2_VAL                             Mandatory for D1xD2, O1xO2 and ANGxD
PRO_E_MODRND_OPTS                                 Mandatory
PRO_E_MODRND_ATTACH                               Mandatory
PRO_E_MODRND_CLOSEGEOM                            Mandatory
PRO_E_MODRND_RMV_INTERF_RND                       Mandatory
PRO_E_STD_FLEX_PROPAGATION                        Optional
===============================================================================

(5) Notes

   Note-1  : Edit Chamfer feature name. Default is "EDIT_CHAMFER"

   Note-2  : Surface collection that includes chamfer-like surfaces.

   Note-3  : Values from ProChmSchema. See ProChamfer.h.

   Note-4  : [(part epsilon / 10.0),  1.0e+06] for "D" schemas.
             [ -1.0e+06,  1.0e+06]             for "O" schemas.

   Note-5  : Values from ProModRndAttach. See ProModifyRound.h.

   Note-6  : Values from ProModRndCloseGeom, See ProModifyRound.h.

   Note-7  : Values from ProModRndRmvRounds, See ProModifyRound.h.

   Note-8  : Header feature including Pattern header feature and
             Mirror header feature ( Symmetry Recognition )

   Note-9  : Values from ProModRndRemove. See ProModifyRound.h.

==============================================================================*/

PRO_END_C_DECLS
#endif

