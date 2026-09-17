#ifndef PROFLEXATTACH_H
#define PROFLEXATTACH_H

/*
   Creo Parametric TOOLKIT declarations related to flex attach feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS
/*****************************************************************************

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_REF_ATTACH_PRIM_QLT
     |
     |--PRO_E_REF_ATTACH_MERG_QLT
     |
     |--PRO_E_OPT_ATTACH_OPER
     |
     |--PRO_E_OPT_ATTACH_RMV_MAT
     |
     |--PRO_E_OPT_ATTACH_PQ_DIR
     |
     |--PRO_E_OPT_ATTACH_MGQ_DIR
     |
     |--PRO_E_FLEX_OPTS_CMPND

Feature elements table

Element Id                  Element Name         Data Type
------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type           PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME      Feature Name           PRO_VALUE_TYPE_WSTRING
PRO_E_REF_ATTACH_PRIM_QLT   Primary Quilt          PRO_VALUE_TYPE_SELECTION
PRO_E_REF_ATTACH_MERG_QLT   Quilt to merge         PRO_VALUE_TYPE_SELECTION
PRO_E_OPT_ATTACH_OPER       Operation type         PRO_VALUE_TYPE_BOOLEAN
PRO_E_OPT_ATTACH_RMV_MAT    Remove Material        PRO_VALUE_TYPE_BOOLEAN
PRO_E_OPT_ATTACH_PQ_DIR     Primary Direction      PRO_VALUE_TYPE_BOOLEAN
PRO_E_OPT_ATTACH_MGQ_DIR    Merge Direction        PRO_VALUE_TYPE_BOOLEAN
PRO_E_OPT_ATTACH_PIO        Use attach info        PRO_VALUE_TYPE_BOOLEAN
PRO_E_OPT_ATTACH_RNDCH      Attach rounds/chamfers PRO_VALUE_TYPE_BOOLEAN
PRO_E_FLEX_OPTS_CMPND       FLX-MDL Options        Compound

-------------------------------------------------------------------
Table Flex Attach :1
-------------------------------------------------------------------
| Element Id               | Comment                              |
-------------------------------------------------------------------
| PRO_E_FEATURE_TYPE       | Mandatory                            |
|.................................................................|
| PRO_E_REF_ATTACH_PRIM_QLT| Mandatory                            |
|.................................................................|
| PRO_E_REF_ATTACH_MERG_QLT| Optional                             |
|.................................................................|
| PRO_E_OPT_ATTACH_OPER    | Mandatory                            |
|                          | PRO_B_FALSE : Attach operation       |
|                          | PRO_B_TRUE  : No Attach operation    |
|.................................................................|
| PRO_E_OPT_ATTACH_RMV_MAT | Available when "Quilt to merge"      |
|                          | is empty                             |
|                          | PRO_B_FALSE : Add material           |
|                          | PRO_B_TRUE  : Remove material        |
|.................................................................|
| PRO_E_OPT_ATTACH_PQ_DIR  | Available when "Operation type"      |
|                          | is PRO_B_FALSE (Attach operation)    |
|                          | PRO_B_FALSE : Side1                  |
|                          | PRO_B_TRUE  : Side2                  |
|.................................................................|
| PRO_E_OPT_ATTACH_MGQ_DIR | Available when "Operation type"      |
|                          | is PRO_B_FALSE (Attach operation) and|
|                          | "Quilt to merge" has references.     |
|                          | PRO_B_FALSE : Side1                  |
|                          | PRO_B_TRUE  : Side2                  |
|.................................................................|
| PRO_E_OPT_ATTACH_PIO     | Available when attach info exists    |
|                          | PRO_B_FALSE : Don't use attach info  |
|                          | PRO_B_TRUE  : Use attach info        |
|.................................................................|
| PRO_E_OPT_ATTACH_RNDCH   | Available when attach info exists    |
|                          | PRO_B_FALSE : Don't recreate         |
|                          | PRO_B_TRUE  : Recreate rnds/chmfers  |
|.................................................................|
| PRO_E_FLEX_OPTS_CMPND    | Refer ProFlxmdlOpts.h                |
-------------------------------------------------------------------


Notes :
1) The value of the element PRO_E_FEATURE_TYPE
   must be PRO_FEAT_FLXATTACH.

*****************************************************************************/


PRO_END_C_DECLS

#endif

