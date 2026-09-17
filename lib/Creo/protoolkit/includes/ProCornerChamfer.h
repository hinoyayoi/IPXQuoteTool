#ifndef PROCORNERCHAMFER_H
#define PROCORNERCHAMFER_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree
 
  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_STD_FEATURE_NAME
    |
    |--PRO_E_STD_CORNER_CHAMF_CORNER
    |
    |--PRO_E_STD_CORNER_CHAMF_EDGE1
    |
    |--PRO_E_STD_CORNER_CHAMF_EDGE2
    |
    |--PRO_E_STD_CORNER_CHAMF_EDGE3

===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------  Element Id                    Element Name      Data Type             
------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE            Feature Type        PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME        Feature Name        PRO_VALUE_TYPE_WSTRING
PRO_E_STD_CORNER_CHAMF_CORNER Corner              PRO_VALUE_TYPE_SELECTION
PRO_E_STD_CORNER_CHAMF_EDGE1  First Dimension     PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_CORNER_CHAMF_EDGE2  Second Dimension    PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_CORNER_CHAMF_EDGE3  Third Dimension     PRO_VALUE_TYPE_DOUBLE
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                    Element Name         Valid Values
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE            Feature Type         PRO_FEAT_CORN_CHAMF

 PRO_E_STD_CORNER_CHAMF_CORNER Corner               PRO_EDGE
                                                    PRO_EDGE_START,
                                                    PRO_EDGE_END,
                                                    PRO_EDGE_PNT
 PRO_E_STD_CORNER_CHAMF_EDGE1  First Dimension      Double Value
 PRO_E_STD_CORNER_CHAMF_EDGE2  Second Dimension     Double Value
 PRO_E_STD_CORNER_CHAMF_EDGE3  Third Dimension      Double Value
 PRO_E_STD_FEATURE_NAME        Feature Name         Default value is 
                                                     "CORNER_CHAMFER".
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                                      Comment
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE                                Mandatory
 PRO_E_STD_CORNER_CHAMF_CORNER                     Mandatory
 PRO_E_STD_CORNER_CHAMF_EDGE1                      Mandatory
 PRO_E_STD_CORNER_CHAMF_EDGE2                      Mandatory
 PRO_E_STD_CORNER_CHAMF_EDGE3                      Mandatory
==============================================================================*/

PRO_END_C_DECLS
#endif
