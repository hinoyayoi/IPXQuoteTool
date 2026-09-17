#ifndef PROSMTCONNRIP_H
#define PROSMTCONNRIP_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Connect Rip feature
*/



#include <ProToolkit.h>
#include <ProSmtSurfaceRip.h>

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
     |--PRO_E_SMT_RIP_CONNECT_COMP
           |
           |--PRO_E_SMT_RIP_CONNECT_SETS
                 |
                 |--PRO_E_SMT_RIP_CONNECT_SET
                       |
                       |--PRO_E_SMT_RIP_CONN_REFS
                       |     |
                       |     |--PRO_E_SMT_RIP_CONN_REF
                       |           |
                       |           |--PRO_E_SMT_RIP_CONN_END
                       |                
                       |--PRO_E_SMT_RIP_CONN_GAP_COMP
                             |
                             |--PRO_E_SMT_RIP_CONN_ADD_GAP
                             |
                             |--PRO_E_SMT_RIP_CONN_GAP_VAL


==============================================================================
Element Id                     Element Name             Data Type
==============================================================================

PRO_E_FEATURE_TYPE              Feature Type            PRO_VALUE_TYPE_INT
                                 See Note 1.

PRO_E_STD_FEATURE_NAME          Feature Name           PRO_VALUE_TYPE_WSTRING


PRO_E_SMT_RIP_TYPE            Sheet Metal Rip Type        PRO_VALUE_TYPE_INT
                                                              See Note 2.

PRO_E_SMT_RIP_CONNECT_COMP      Rip Connect Comp              Compound


PRO_E_SMT_RIP_CONNECT_SETS      Rip Connect Sets               Array


PRO_E_SMT_RIP_CONNECT_SET       Rip Connect Set               Compound


PRO_E_SMT_RIP_CONN_REFS         Rip Connect Refs               Array 
                                                              See Note 3.

PRO_E_SMT_RIP_CONN_REF          Rip Connect Ref               Compound


PRO_E_SMT_RIP_CONN_END          Rip Connect End Ref    PRO_VALUE_TYPE_SELECTION
                                                              See Note 4.

PRO_E_SMT_RIP_CONN_GAP_COMP     Rip Connect Gap Comp          Compound


PRO_E_SMT_RIP_CONN_ADD_GAP      Rip Connect Add Gap    PRO_VALUE_TYPE_BOOLEAN 
                                                              See Note 5.

PRO_E_SMT_RIP_CONN_GAP_VAL      Rip Connect Gap Val    PRO_VALUE_TYPE_DOUBLE
                                                              See Note 6. 

-------------------------------------------------------------------------------

Note 1.
  PRO_E_FEATURE_TYPE must be of PRO_FEAT_RIP.

-------------------------------------------------------------------------------

Note 2.
  PRO_E_SMT_RIP_TYPE must be of PRO_SMT_RIP_CONNECT.

-------------------------------------------------------------------------------

Note 3.
  Number of elements in the array can not be more then 2.

-------------------------------------------------------------------------------

Note 4.
  The reference need to be a vertex selection or a datum point
  selection, that is placed on edge, which is between Face/offset surface
  to side surface.

-------------------------------------------------------------------------------

Note 5.
   TRUE  - for having gap dimension.
   FALSE - for not having gap dimension.

-------------------------------------------------------------------------------

Note 6.
   The gap value.

*****************************************************************************/

PRO_END_C_DECLS

#endif /* PROSMTCONNRIP_H */
