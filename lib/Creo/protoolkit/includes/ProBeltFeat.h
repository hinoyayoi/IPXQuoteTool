#ifndef PROBELTFEAT_H
#define PROBELTFEAT_H

/*
 * Creo Parametric TOOLKIT declarations related to belt feature; feature's element tree
 * sketch
 */



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************

Feature element tree for Belt Feature

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_BELT_PULLEYS
     |    |
     |    |--PRO_E_BELT_PULLEY_RECORD
     |         |--PRO_E_BELT_PULLEY_SEL
     |         |--PRO_E_BELT_PULLEY_WRAP_SIDE
     |         |--PRO_E_BELT_PULLEY_DIAMETER
     |         |--PRO_E_BELT_PULLEY_DIAM_COINCIDENT
     |         |--PRO_E_BELT_PULLEY_CONN_NUM
     |         |--PRO_E_BELT_PULLEY_FLIP_CONN_BODIES
     |         |--PRO_E_BELT_PULLEY_NUM_WRAPS
     |
     |--PRO_E_BELT_PLANE
     |
     |--PRO_E_BELT_DEFINE_CUSTOM_U_LENGTH
     |--PRO_E_BELT_UNSTRETCHED_LENGTH
     |--PRO_E_BELT_STIFFNESS_COEFF


Feature elements table

================================================================================================
Element Id                         | Element Description              | Data Type
================================================================================================
PRO_E_FEATURE_TYPE                 | Feature type                     | PRO_VALUE_TYPE_INT
-----------------------------------|----------------------------------|-------------------------
PRO_E_STD_FEATURE_NAME             | Feature name                     | PRO_VALUE_TYPE_WSTRING
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEYS                 | Belt pulleys                     | Array
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_RECORD           | Individual belt pulley           | Compound
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_SEL              | Pulley reference                 | PRO_VALUE_TYPE_SELECTION
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_WRAP_SIDE        | Pulley wrapping side (left (-1)  | PRO_VALUE_TYPE_INT
                                   | or right (+1), relative to the   |
                                   | previous pulley)                 |
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_DIAMETER         | Pulley Diameter                  | PRO_VALUE_TYPE_DOUBLE
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_DIAM_COINCIDENT  | Is pulley diameter coincident    | PRO_VALUE_TYPE_BOOLEAN
                                   | to the pulley reference          |
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_CONN_NUM         | Pulley connection number (among  | PRO_VALUE_TYPE_INT
                                   | (available valid connections for |
                                   | geometrical reference's body)    |
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_FLIP_CONN_BODIES | Flip connection bodies at pulley | PRO_VALUE_TYPE_BOOLEAN
                                   | (swap pulley and carrier bodies, |
                                   | for connection references only)  |
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PULLEY_NUM_WRAPS        | Number of full wraps at pulley   | PRO_VALUE_TYPE_INT
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_PLANE                   | Plane reference (optional)       | PRO_VALUE_TYPE_SELECTION
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_DEFINE_CUSTOM_U_LENGTH  | Define custom unstretched belt   | PRO_VALUE_TYPE_BOOLEAN
                                   | length                           |
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_UNSTRETCHED_LENGTH      | Unstretched belt length          | PRO_VALUE_TYPE_DOUBLE
-----------------------------------|----------------------------------|-------------------------
PRO_E_BELT_STIFFNESS_COEFF         | Belt stiffness coefficient       | PRO_VALUE_TYPE_DOUBLE
================================================================================================

********************************************************************************************/

PRO_END_C_DECLS

#endif // PROBELTFEAT_H
