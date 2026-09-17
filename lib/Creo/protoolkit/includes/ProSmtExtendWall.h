#ifndef PROSMTEXTENDWALL_H
#define PROSMTEXTENDWALL_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Wall Extend feature
*/




PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :

   PRO_E_FEATURE_TREE
     |
     |-- PRO_E_FEATURE_TYPE
     |
     |-- PRO_E_SMT_WALL_TYPE
     |
     |-- PRO_E_STD_FEATURE_NAME
     |
     |-- PRO_E_SMT_EXTEND_WALL_EDGE
     |
     |-- PRO_E_SMT_EXTEND_WALL_DIST
     |     |
     |     |-- PRO_E_SMT_EXTEND_DIST_TYPE
     |     |
     |     |-- PRO_E_SMT_EXTEND_DIST_VALUE
     |     |
     |     |-- PRO_E_SMT_EXTEND_DIST_REF
     |
     |-- PRO_E_SMT_EXTEND_WALL_EXTENSIONS_CMP
     |     |
     |     |-- PRO_E_SMT_EXTEND_SIDE1_EXTENSION_CMP
     |     |     |
     |     |     |-- PRO_E_SMT_EXTEND_EXTENSION_TYPE_OPT
     |     |     |
     |     |     |-- PRO_E_SMT_EXTEND_ADJUST_SRF
     |     |
     |     |-- PRO_E_SMT_EXTEND_SIDE2_EXTENSION_CMP
     |     |     |
     |     |     |-- PRO_E_SMT_EXTEND_EXTENSION_TYPE_OPT
     |     |     |
     |     |     |-- PRO_E_SMT_EXTEND_ADJUST_SRF
     |     |     |

************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                   Feature Type       PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_TYPE                  Wall Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME               Feature Name       PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_EXTEND_WALL_EDGE           Edge to Extend     PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_EXTEND_WALL_DIST           Distance           Compound
PRO_E_SMT_EXTEND_DIST_TYPE           Distance Type      OUI_STEP_GET_OPTS
PRO_E_SMT_EXTEND_DIST_VALUE          Distance Value     PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_EXTEND_DIST_REF            Distance Reference PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_EXTEND_WALL_EXTENSIONS_CMP Extensions         Compaund
PRO_E_SMT_EXTEND_SIDE1_EXTENSION_CMP Side 1 Extension   Compaund
PRO_E_SMT_EXTEND_SIDE2_EXTENSION_CMP Side 2 Extension   Compaund
PRO_E_SMT_EXTEND_EXTENSION_TYPE_OPT  Extension Type     OUI_STEP_GET_OPTS
PRO_E_SMT_EXTEND_ADJUST_SRF          Adjacent Surfaces  OUI_STEP_GET_OPTS

================================================================================

================================================================================
Element Id                            Valid Values
================================================================================
PRO_E_FEATURE_TYPE                    PRO_FEAT_WALL
PRO_E_SMT_WALL_TYPE                   PRO_SMT_WALL_TYPE_EXTEND
                                                     //See ProSmtFlangeWall.h
PRO_E_SMT_EXTEND_WALL_EDGE            Edge
PRO_E_SMT_EXTEND_DIST_TYPE            ProExtendDistance       
PRO_E_SMT_EXTEND_DIST_REF             Plane, Surface
PRO_E_SMT_EXTEND_EXTENSION_TYPE_OPT   ProExtendExtensionType
PRO_E_SMT_EXTEND_ADJUST_SRF           ProExtendAdjSrf
================================================================================

************************************************************************/

typedef enum _ProExtendDistance 
{
  PRO_EXTEND_DIST_UNDEF            = -1,//The option is invalid from this release onwards.
  PRO_EXTEND_DIST_BY_VALUE         =  0,
  PRO_EXTEND_DIST_TO_THROUGH_UNTIL =  1,
  PRO_EXTEND_DIST_TO_SELECTED      =  2
}ProExtendDistance;

typedef enum _ProExtendAdjSrf 
{ 
  PRO_EXTEND_ADJ_SRF_FALSE = 0,
  PRO_EXTEND_ADJ_SRF_TRUE  = 1
}ProExtendAdjSrf;

typedef enum _ProExtendExtensionType
{ 
  PRO_EXTEND_EXT_NORMAL_TO_EDGE   = 0,
  PRO_EXTEND_EXT_ALONG_BOUND_EDGE = 1
}ProExtendExtensionType;


PRO_END_C_DECLS

#endif
