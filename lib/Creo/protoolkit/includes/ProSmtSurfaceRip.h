#ifndef PROSMTSURFACERIP_H
#define PROSMTSURFACERIP_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Surface rip feature
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
     |--PRO_E_SMT_RIP_TYPE
     |
     |--PRO_E_STD_SURF_COLLECTION_APPL




==============================================================================
Element Id                     Element Name             Data Type
==============================================================================

PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT
                                See Note 1.

PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING

PRO_E_SMT_RIP_TYPE             Sheet Metal Rip Type      PRO_VALUE_TYPE_INT
                                                            See Note 2.

PRO_E_STD_SURF_COLLECTION_APPL Surface Collections     PRO_VALUE_TYPE_SELECTION
                                                            See Note 3.


-------------------------------------------------------------------------------
Note 1.
  PRO_E_FEATURE_TYPE must be of PRO_FEAT_RIP.

-------------------------------------------------------------------------------
Note 2.
  PRO_E_SMT_RIP_TYPE must be of PRO_SMT_RIP_SURFACE type.
-------------------------------------------------------------------------------
Note 3.
  See ProSrfcollection.h.

*****************************************************************************/

typedef enum Pro_Smt_Rip_Type
{
  PRO_SMT_RIP_REGULAR = 1,
  PRO_SMT_RIP_SURFACE = 3,
  PRO_SMT_RIP_EDGE    = 4,
  PRO_SMT_RIP_CONNECT = 5
}ProSmtRipType;

PRO_END_C_DECLS

#endif /* PROSMTSURFACERIP_H */
