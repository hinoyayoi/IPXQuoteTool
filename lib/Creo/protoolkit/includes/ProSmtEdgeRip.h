#ifndef PROSMTEDGERIP_H
#define PROSMTEDGERIP_H
/*
   Creo Parametric TOOLKIT declarations related to SheetMetal EdgeRip feature
*/


#include <ProToolkit.h>
#include <ProSmtSurfaceRip.h>
#include <ProSmtFlangeWall.h>
PRO_BEGIN_C_DECLS

/************************************************************************



Feature element tree :

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_RIP_TYPE
     |
     |--PRO_E_SMT_EDGE_RIP_ARRAY
              |
            PRO_E_SMT_EDGE_RIP_SET
                 |
                 |--PRO_E_SMT_EDGE_RIP_REFERENCES
                 |        |
                 |        |--PRO_E_SMT_EDGE_REFERENCES
                 |                |
                 |                |--PRO_E_STD_CURVE_COLLECTION_APPL
                 |
                 |
                 |-- PRO_E_SMT_EDGE_RIP
                           |
                           |--PRO_E_SMT_EDGE_RIP_TYPE
                           |
                           |--PRO_E_SMT_EDGE_RIP_FLIP
                           |
                           |--PRO_E_SMT_EDGE_RIP_ADD_GAP
                           |
                           |--PRO_E_SMT_EDGE_RIP_CLOSE_CORNER
                           |
                           |--PRO_E_SMT_EDGE_RIP_DIM_1
                           |        |
                           |        |--PRO_E_SMT_DIMENSION_TYPE
                           |        |
                           |        |--PRO_E_SMT_DIMENSION_VALUE
                           |
                           |--PRO_E_SMT_EDGE_RIP_DIM_2
                                    |
                                    |--PRO_E_SMT_DIMENSION_TYPE
                                    |
                                    |--PRO_E_SMT_DIMENSION_VALUE



************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_RIP_TYPE                Sheet Metal Rip Type  PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_ARRAY          Edge Rip Sets         Array
PRO_E_SMT_EDGE_RIP_SET            Edge Rip Set          Compound
PRO_E_SMT_EDGE_RIP_REFERENCES     Edge Rip References   Array
PRO_E_SMT_EDGE_REFERENCES         Rip Reference         Compound
PRO_E_STD_CURVE_COLLECTION_APPL   Chain                 PRO_VALUE_TYPE_POINTER
PRO_E_SMT_EDGE_RIP                Edge Rip Data         Compound
PRO_E_SMT_EDGE_RIP_TYPE           Edge Rip Type         PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_ADD_GAP        Edge Rip Add Gap      PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER   Edge Rip Close Corner PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_1          Edge Rip Dim 1        Compound
PRO_E_SMT_EDGE_RIP_DIM_2          Edge Rip Dim 2        Compound
PRO_E_SMT_DIMENSION_TYPE          Edge Rip Dim  Type    PRO_VALUE_TYPE_INT
PRO_E_SMT_DIMENSION_VALUE         Edge Rip Dim  Value   PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_EDGE_RIP_FLIP           Edge Rip Flip         PRO_VALUE_TYPE_INT
================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_RIP
PRO_E_SMT_RIP_TYPE                PRO_SMT_RIP_EDGE
PRO_E_SMT_EDGE_RIP_TYPE           ProEdgeRipType
PRO_E_SMT_EDGE_RIP_ADD_GAP        PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER   PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_DIMENSION_TYPE          ProEdgeRipDimType
PRO_E_SMT_EDGE_RIP_FLIP           PRO_B_TRUE, PRO_B_FALSE

================================================================================

************************************************************************/
PRO_END_C_DECLS

#endif /*PROSMTEDGERIP_H*/
