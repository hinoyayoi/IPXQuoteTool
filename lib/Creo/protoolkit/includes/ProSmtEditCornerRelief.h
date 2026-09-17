#ifndef PROEDITCORNERELIEF_H
#define PROEDITCORNERELIEF_H



#include <ProToolkit.h>
#include <ProSmtCornerRelief.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_STD_FEATURE_NAME
    |
    |--PRO_E_EDIT_CORNER_RELIEF
         |
         |--PRO_E_EDIT_CORNER_RELIEF_SEL_OPT
         |
         |--PRO_E_EDIT_CORNER_RELIEF_GEOMS
         |
         |--PRO_E_CORNER_RELIEF_DEFINE
             |
             |--PRO_E_SMT_CORNER_RELIEF
                |
                |-- PRO_E_SMT_CORNER_RELIEF_TYPE 
                |
                |-- PRO_E_SMT_CORNER_RELIEF_WIDTH 
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL
                |
                |-- PRO_E_SMT_CORNER_RELIEF_DEPTH
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL
                |
                |-- PRO_E_SMT_CORNER_RELIEF_ROTATE
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD 
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_ROTATE_VAL
                |
                |-- PRO_E_SMT_CORNER_RELIEF_OFFSET
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD
                |   |
                |   |-- PRO_E_SMT_CORNER_RELIEF_OFFSET_VAL
                |
                |-- PRO_E_CORNER_RELIEFS_DIM_SCHEME
         

===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------
  Element Id                      Element Name          Data Type
------------------------------------------------------------------------------  
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_EDIT_CORNER_RELIEF          Edit Corner Relief    Compound
PRO_E_EDIT_CORNER_RELIEF_SEL_OPT  Selection Option      PRO_VALUE_TYPE_INT
PRO_E_EDIT_CORNER_RELIEF_GEOMS    Corner Relief Geometry Multi Collector
PRO_E_CORNER_RELIEF_DEFINE        Edit Corner Relief Define   Compound
PRO_E_SMT_CORNER_RELIEF           Corner Relief               Compound
PRO_E_SMT_CORNER_RELIEF           Corner Relief               Compound
PRO_E_SMT_CORNER_RELIEF_TYPE        Corner Relief Type        PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_WIDTH       Corner Relief Width       Compound
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE  Corner Relief Width Type  PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL   Corner Relief Width Val   PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_DEPTH       Corner Relief Depth       Compound
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE  Corner Relief Depth Type  PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL   Corner Relief Depth Val   PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_ROTATE      Rotate                    Compound
PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD  Add Rotate                PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_ROTATE_VAL  Rotate Value              PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_OFFSET      Offset                    Compound
PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD  Add Offset                PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_OFFSET_VAL  Offset Value              PRO_VALUE_TYPE_DOUBLE
PRO_E_CORNER_RELIEFS_DIM_SCHEME     Corner relief anchor point  PRO_VALUE_TYPE_INT
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                      Element Name           Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE		         Feature Type         PRO_FEAT_EDIT_CORNER_RELIEF
PRO_E_STD_FEATURE_NAME           Feature Name                See Note 1
PRO_E_EDIT_CORNER_RELIEF_SEL_OPT Selection Option            ProCrnRelRefType
PRO_E_EDIT_CORNER_RELIEF_GEOMS   Corner Relief Geometry      See Note 2
PRO_E_SMT_CORNER_RELIEF_TYPE        Corner Relief Type        ProCornerRelType
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE  Corner Relief Width Type  ProSmdRelType
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE  Corner Relief Depth Type  ProCornerRlfDepthType
PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD  Add Rotate                PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_CORNER_RELIEF_ROTATE_VAL  Rotate Value              0 - 360
PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD  Add Offset                PRO_B_TRUE, PRO_B_FALSE
PRO_E_CORNER_RELIEFS_DIM_SCHEME     Corner relief anchor point  ProCrnRelDimRefType
===============================================================================*/


PRO_END_C_DECLS
#endif

