#ifndef PROSMTEDGEBEND_H
#define PROSMTEDGEBEND_H
/*
   Creo Parametric TOOLKIT declarations related to SheetMetal EdgeBend feature
*/


#include <ProToolkit.h>
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
     |--PRO_E_SMT_EDGE_BEND_ARRAY
     |        |
     |      PRO_E_SMT_EDGE_BEND_SET
     |           |
     |           |--PRO_E_SMT_EDGE_BEND_REFERENCES
     |           |        |
     |           |        |--PRO_E_SMT_EDGE_REFERENCES
     |           |                |
     |           |                |--PRO_E_STD_CURVE_COLLECTION_APPL
     |           |
     |           |
     |           |-- PRO_E_SMT_FILLET_SELECT
     |           |    |
     |           |    |--PRO_E_SMT_FILLET_RADIUS_SIDE
     |           |    |
     |           |    |--PRO_E_SMT_FILLET_RADIUS_VALUE
     |
     |--PRO_E_SMT_BEND_RELIEF
     |    |
     |    |--PRO_E_SMT_BEND_RELIEF_SIDE1
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_WIDTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_ANGLE
     |
     |--PRO_E_SMT_DEV_LEN_CALCULATION
              |
              |-- PRO_E_SMT_DEV_LEN_SOURCE
              |
              |-- PRO_E_SMT_DEV_LEN_Y_FACTOR
              |   |
              |   |-- PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE
              |   |
              |   |-- PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE
              |
              |-- PRO_E_SMT_DEV_LEN_BEND_TABLE



************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_EDGE_BEND_ARRAY         Edge Bend Sets        Array
PRO_E_SMT_EDGE_BEND_SET           Edge Bend Set         Compound
PRO_E_SMT_EDGE_BEND_REFERENCES    Edge Bend References  Array
PRO_E_SMT_EDGE_REFERENCES         Bend Reference        Compound
PRO_E_STD_CURVE_COLLECTION_APPL   Chain                 PRO_VALUE_TYPE_POINTER
PRO_E_SMT_FILLET_SELECT           Edge Bend Data        Compound
PRO_E_SMT_FILLET_RADIUS_SIDE      Radius Side           PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLET_RADIUS_VALUE     Radius Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_RELIEF             Bend Relief           Compound
PRO_E_SMT_BEND_RELIEF_SIDE1       Side 1 Relief         Compound
PRO_E_BEND_RELIEF_TYPE            Relief Type           PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_WIDTH           Relief Width          PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_DEPTH_TYPE      Relief Depth type     PRO_VALUE_TYPE_INT
                                                        See Note 1.
PRO_E_BEND_RELIEF_DEPTH           Relief Depth value    PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_ANGLE           Relief Angle          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_CALCULATION     Developed Length      Compound
PRO_E_SMT_DEV_LEN_SOURCE          Dev Length Source     PRO_VALUE_TYPE_INT 
PRO_E_SMT_DEV_LEN_Y_FACTOR        Dev Length Y Factor   Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE  Y Factor Value        PRO_VALUE_TYPE_DOUBLE  
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   Y Factor Type         PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_BEND_TABLE      Dev Length Bend Table PRO_VALUE_TYPE_INT

-------------------------------------------------------------------------------
Note 1.
  The element PRO_E_BEND_RELIEF_DEPTH_TYPE has been added in Creo Parametric.
This element rules the visibility of the bend relief depth element
PRO_E_BEND_RELIEF_DEPTH. The old element PRO_E_BEND_RELIEF_DEPTH will be used
if PRO_E_BEND_RELIEF_DEPTH_TYPE is PRO_BEND_RLF_DEPTH_BLIND or
PRO_BEND_RLF_DEPTH_TYPE_PARAM and part parameter SMT_DFLT_BEND_REL_DEPTH_TYPE
is "Blind". It is recommended to define PRO_E_BEND_RELIEF_DEPTH_TYPE explicitly
for all Creo Parametric TOOLKIT applications. Otherwise the element will be automatically
filled by the default value. The default value in Creo Parametric depends on
the part parameter SMT_DFLT_BEND_REL_DEPTH_TYPE and the configuration option
smt_drive_tools_by_parameters Yes/No. If the value of the option is No,
then the default value will be the last bend relief type, as selected
by the user in the dashboard UI during creation of a new feature.
If the default value is not "Blind", Creo Parametric TOOLKIT applications prior to this
release will not use the element PRO_E_BEND_RELIEF_DEPTH.
To fix it, set PRO_E_BEND_RELIEF_DEPTH_TYPE to PRO_BEND_RLF_DEPTH_BLIND.


================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_EDGE_BEND
PRO_E_SMT_DEV_LEN_SOURCE          ProDvlLenSrcType
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   ProDvlLenFactor
PRO_E_SMT_DEV_LEN_BEND_TABLE      int (bend table ID)
PRO_E_SMT_FILLET_RADIUS_SIDE      ProSmdRadType(PRO_BEND_RAD_INSIDE,
                                                 PRO_BEND_RAD_OUTSIDE)
PRO_E_BEND_RELIEF_TYPE            ProBendRlfType      (See ProSmtFlangeWall.h)
PRO_E_BEND_RELIEF_DEPTH_TYPE      ProBendRlfDepthType (See ProSmtFlangeWall.h)

================================================================================

************************************************************************/



PRO_END_C_DECLS

#endif

