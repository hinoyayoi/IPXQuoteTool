#ifndef PROSMTTWIST_H
#define PROSMTTWIST_H

/*
  Creo Parametric TOOLKIT declarations related to SheetMetal Twist feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_TWIST_ATT_EDGE
     |
     |--PRO_E_SMT_TWIST_TYPE
     |
     |--PRO_E_SMT_TWIST_TRIM_EDGES
     |    |
     |    |--PRO_E_SMT_TWIST_SIDE_1_OFFSET
     |    |    |
     |    |    |--PRO_E_SMT_TWIST_OFFSET_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_TWIST_OFFSET_VAL
     |    |
     |    |--PRO_E_SMT_TWIST_SIDE_2_OFFSET
     |    |    |
     |    |    |--PRO_E_SMT_TWIST_OFFSET_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_TWIST_OFFSET_VAL
     |
     |--PRO_E_SMT_TWIST_AXIS_POINT
     |    |
     |    |--PRO_E_SMT_TWIST_POINT_TYPE
     |    |
     |    |--PRO_E_SMT_TWIST_START_WIDTH_VAL
     |    |
     |    |--PRO_E_SMT_TWIST_ATT_POINT_REF
     |
     |--PRO_E_SMT_TWIST_ANGLE_VAL
     |
     |--PRO_E_SMT_TWIST_WALL_LENGTH_VAL
     |
     |--PRO_E_SMT_TWIST_END_WIDTH
     |    |
     |    |--PRO_E_SMT_TWIST_END_WIDTH_TYPE
     |    |
     |    |--PRO_E_SMT_TWIST_END_WIDTH_VAL
     |
     |--PRO_E_SMT_TWIST_DEV_LEN_VAL


************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_TWIST_ATT_EDGE          Attachment Edge       PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_TWIST_TYPE              Twist Type            PRO_VALUE_TYPE_INT
PRO_E_SMT_TWIST_TRIM_EDGES        Twist trim edges      Compound
See Note 1. 
PRO_E_SMT_TWIST_SIDE_1_OFFSET     Side 1                Compound
PRO_E_SMT_TWIST_SIDE_2_OFFSET     Side 2                Compound
PRO_E_SMT_TWIST_OFFSET_TYPE       Offset Type           PRO_VALUE_TYPE_INT
PRO_E_SMT_TWIST_OFFSET_VAL        Offset Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_TWIST_POINT_TYPE        Point Type            PRO_VALUE_TYPE_INT
PRO_E_SMT_TWIST_AXIS_POINT        Twist Axis Point      Compound
See Note 2.
PRO_E_SMT_TWIST_START_WIDTH_VAL   Start Width           PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_TWIST_ATT_POINT_REF     point on edge         PRO_VALUE_TYPE_SELECTION
See Note 3.
PRO_E_SMT_TWIST_ANGLE_VAL         Twist angle value     PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_TWIST_WALL_LENGTH_VAL   Twist Wall Length     PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_TWIST_END_WIDTH         Twist End width       Compound
PRO_E_SMT_TWIST_END_WIDTH_TYPE    end width type        PRO_VALUE_TYPE_INT
PRO_E_SMT_TWIST_END_WIDTH_VAL     end width             PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_TWIST_DEV_LEN_VAL       len in unbent state   PRO_VALUE_TYPE_DOUBLE

-------------------------------------------------------------------------------
Note 1.
The Element PRO_E_SMT_TWIST_TRIM_EDGES is availble when PRO_E_SMT_TWIST_TYPE
is PRO_SMT_TWIST_TRIM_EDGES .

-------------------------------------------------------------------------------
Note 2.
The Elements PRO_E_SMT_TWIST_AXIS_POINT is availble when PRO_E_SMT_TWIST_TYPE
is PRO_SMT_TWIST_TYPE_PNT  
-------------------------------------------------------------------------------
Note 3.
The Element PRO_E_SMT_TWIST_ATT_POINT_REF is availble when 
PRO_E_SMT_TWIST_POINT_TYPE is PRO_SMT_TWIST_DTM_PNT
-------------------------------------------------------------------------------

================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_TWIST
PRO_E_SMT_TWIST_TYPE              ProSmtTwistType
PRO_E_SMT_TWIST_POINT_TYPE        ProSmtTwistPointType
PRO_E_SMT_TWIST_ATT_EDGE          Edge   
PRO_E_SMT_TWIST_ATT_POINT_REF     Datum point   
PRO_E_SMT_TWIST_OFFSET_TYPE       ProSmtTwistOffsetType
PRO_E_SMT_TWIST_END_WIDTH_TYPE    ProSmtTwistEndWidthType

================================================================================

************************************************************************/

typedef enum _ProSmtTwistType
{
  PRO_SMT_TWIST_TYPE_NOT_DEF = -1, 
  PRO_SMT_TWIST_TRIM_EDGES   =  0, /* Trim the edge from the sides */
  PRO_SMT_TWIST_TYPE_PNT     =  1  /* point on the att edge */

} ProSmtTwistType;

typedef enum _ProSmtTwistPointType
{
  PRO_SMT_TWIST_PNT_NOT_DEF  = -1, 
  PRO_SMT_TWIST_MID_PNT      =  0, /* Middle point on the att edge */
  PRO_SMT_TWIST_DTM_PNT      =  1  /* Datum  point on the att edge */

} ProSmtTwistPointType;


typedef enum _ProSmtTwistOffsetType
{
  PRO_TWIST_OFFSET_TYPE_NOT_DEFINED     = -1,
  PRO_TWIST_OFFSET_TYPE_TO_END          =  0,
  PRO_TWIST_OFFSET_TYPE_BLIND           =  1
} ProSmtTwistOffsetType;

typedef enum _ProSmtTwistEndWidthType
{
  PRO_TWIST_END_WIDTH_TYPE_NOT_DEFINED     = -1,
  PRO_TWIST_END_WIDTH_SAME_AS_START        =  0,
  PRO_TWIST_END_WIDTH_BLIND                =  1

} ProSmtTwistEndWidthType;




PRO_END_C_DECLS

#endif
