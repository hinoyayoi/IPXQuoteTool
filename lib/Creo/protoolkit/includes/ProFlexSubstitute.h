#ifndef PROFLEXSUBSTITUTE_H
#define PROFLEXSUBSTITUTE_H

/*
   Creo Parametric TOOLKIT declarations related to flex substitute feature.
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
     |--PRO_E_CMP_SUBSTITUTED
     |  |
     |  |--PRO_E_FLXSUBST_METHOD
     |  |
     |  |--PRO_E_STD_SURF_COLLECTION_APPL
     |  |
     |  |--PRO_E_FLXSUBST_EDGELOOPS
     |
     |--PRO_E_CMP_SUBTITUTING
     |  |
     |  |--PRO_E_STD_SURF_COLLECTION_APPL
     |
     |--PRO_E_OPT_SUBST_SRF_NORM_SIDE
     |
     |--PRO_E_FLEX_OPTS_CMPND  (General FLX-MDL options branch, see ProFlxmdlOpts.h)



Feature elements table

Element Id                      Element Name           Data Type
------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type           PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME          Feature Name           PRO_VALUE_TYPE_WSTRING
PRO_E_CMP_SUBSTITUTED           Substituted            Compound
PRO_E_CMP_SUBTITUTING           Substituting           Compound
PRO_E_FLXSUBST_METHOD           Substitute method      PRO_VALUE_TYPE_INT
PRO_E_STD_SURF_COLLECTION_APPL
(In PRO_E_CMP_SUBSTITUTED)      Substituted Surfaces   Surface Collection
PRO_E_FLXSUBST_EDGELOOPS        Substituted edge loops PRO_VALUE_TYPE_SELECTION
PRO_E_STD_SURF_COLLECTION_APPL
(In PRO_E_CMP_SUBTITUTING)      Substituting Surfaces  Surface Collection
PRO_E_OPT_SUBST_SRF_NORM_SIDE   Normal direction       PRO_VALUE_TYPE_BOOLEAN
PRO_E_FLEX_OPTS_CMPND           FLX-MDL Options        Compound

--------------------------------------------------------------------------
Table Flex Substitute :1
--------------------------------------------------------------------------
| Element Id                      | Comment                              |
--------------------------------------------------------------------------
| PRO_E_FEATURE_TYPE              | Mandatory                            |
|........................................................................|
| PRO_E_CMP_SUBSTITUTED           | Mandatory                            |
|........................................................................|
| PRO_E_CMP_SUBTITUTING           | Mandatory                            |
|........................................................................|
| PRO_E_FLXSUBST_METHOD           | Mandatory                            |
|........................................................................|
| PRO_E_STD_SURF_COLLECTION_APPL  | Mandatory for PRO_FLEXSUBST_SURFACES |
|........................................................................|
| PRO_E_FLXSUBST_EDGELOOPS        | Mandatory for PRO_FLEXSUBST_LOOPS    |
|........................................................................|
| PRO_E_OPT_SUBST_SRF_NORM_SIDE   | Mandatory                            |
|........................................................................|
| PRO_E_FLEX_OPTS_CMPND           | Refer ProFlxmdlOpts.h                |
--------------------------------------------------------------------------


Notes :
1) The value of the element PRO_E_FEATURE_TYPE
   must be PRO_FEAT_FLEXSUBST.
2) The value of the element PRO_E_FLXSUBST_METHOD
   must be PRO_FLEXSUBST_SURFACES or PRO_FLEXSUBST_LOOPS.
3) When PRO_E_OPT_SUBST_SRF_NORM_SIDE is PRO_B_FALSE, it implies Side 1 normal,
   otherwise it is Side 2.


*****************************************************************************/

#define PRO_FLEXSUBST_SURFACES     0
#define PRO_FLEXSUBST_LOOPS        1

PRO_END_C_DECLS

#endif
