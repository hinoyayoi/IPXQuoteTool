#ifndef PROSMTSHELLH
#define PROSMTSHELLH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*=============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_DTM_SRF_TYPE
      |
      |-- PRO_E_SHELL_SRF
      |
      |-- PRO_E_STD_SMT_THICKNESS
      |
      |-- PRO_E_STD_MATRLSIDE
      |
      |-- PRO_E_STD_SMT_SWAP_DRV_SIDE

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
Element Id                     Element Name           Data Type              
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type           PRO_VALUE_TYPE_INT  
                                                      See Note 1
PRO_E_STD_FEATURE_NAME         Feature Name           PRO_VALUE_TYPE_WSTRING

PRO_E_DTM_SRF_TYPE             Datum surface type     PRO_VALUE_TYPE_INT
                                                      See Note 2.
PRO_E_SHELL_SRF                Remove Surfaces        PRO_VALUE_TYPE_SELECTION
                                                      See Note 3
PRO_E_STD_SMT_THICKNESS        SheetMetal thickness   PRO_ELEM_TYPE_DOUBLE

PRO_E_STD_MATRLSIDE            Material Side          PRO_VALUE_TYPE_INT

PRO_E_STD_SMT_SWAP_DRV_SIDE    Smt Swap Side          PRO_VALUE_TYPE_INT
===============================================================================

(3) Notes

-------------------------------------------------------------------------------
Note 1.
 PRO_E_FEATURE_TYPE must be of PRO_FEAT_DATUM_SURF

-------------------------------------------------------------------------------
Note 2.
 PRO_E_DTM_SRF_TYPE must be of PRO_DTM_SRF_AS_WALL_SHELL type

-------------------------------------------------------------------------------
Note 3.
  Select the surfaces to be removed from the part to create smt shell
  feature. Multiple selection allowed. This element is optional.
*****************************************************************************/

PRO_END_C_DECLS

#endif
