#ifndef PROSMTDRVSURF_H
#define PROSMTDRVSURF_H
/*
   Creo Parametric TOOLKIT declarations related to SheetMetal driving surface convert 
   feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/* ***************************************************************************

Feature element tree :

 PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_DTM_SRF_TYPE
     |
     |--PRO_E_SMT_DRV_SURF
     |
     |--PRO_E_STD_SMT_THICKNESS
     |
     |--PRO_E_STD_MATRLSIDE
     |
     |--PRO_E_STD_SMT_SWAP_DRV_SIDE

==============================================================================
Element Id                     Element Name             Data Type
==============================================================================

PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT
                                                       See Note 1.
PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING

PRO_E_DTM_SRF_TYPE             Datum surface type      PRO_VALUE_TYPE_INT
                                                       See Note 2.
PRO_E_SMT_DRV_SURF             Driving Surface         PRO_VALUE_TYPE_SELECTION
                                                        See Note 3.
PRO_E_STD_SMT_THICKNESS        SheetMetal thickness    PRO_ELEM_TYPE_DOUBLE

PRO_E_STD_MATRLSIDE            Material Side           PRO_VALUE_TYPE_INT

PRO_E_STD_SMT_SWAP_DRV_SIDE    Smt Swap Side           PRO_VALUE_TYPE_INT

-------------------------------------------------------------------------------
Note 1.
 PRO_E_FEATURE_TYPE must be of PRO_FEAT_DATUM_SURF

-------------------------------------------------------------------------------
Note 2.
 PRO_E_DTM_SRF_TYPE must be of PRO_DTM_SRF_AS_WALL type

-------------------------------------------------------------------------------
Note 3.
 PRO_E_SMT_DRV_SURF must be a surface type to be set as driving surface.

*****************************************************************************/

typedef enum Pro_Smt_DtmSrf_Type
{
  PRO_DTM_SRF_AS_WALL         = 15,
  PRO_DTM_SRF_AS_WALL_SHELL   = 24

}ProSmtDtmSrfType;


PRO_END_C_DECLS

#endif
