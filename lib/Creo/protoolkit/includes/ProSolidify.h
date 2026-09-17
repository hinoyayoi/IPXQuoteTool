#ifndef PRO_SOLIDIFY_H
#define PRO_SOLIDIFY_H

/*
   Creo Parametric TOOLKIT declarations related to Solidify feature.
*/



#include <ProToolkit.h>
#include <ProExtrude.h>

PRO_BEGIN_C_DECLS

/*=============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_FEATURE_FORM
      |
      |-- PRO_E_PATCH_QUILT
      |
      |-- PRO_E_PATCH_TYPE
      |
      |-- PRO_E_PATCH_MATERIAL_SIDE
      |
      |-- PRO_E_IS_SMT_CUT
      |
      |-- PRO_E_SMT_CUT_NORMAL_DIR
      |
      |-- PRO_E_STD_FEATURE_NAME

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id                  Element Name           Data Type
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type           PRO_VALUE_TYPE_INT         
 PRO_E_FEATURE_FORM          Feature Form           PRO_VALUE_TYPE_INT         
 PRO_E_PATCH_QUILT           Reference              PRO_VALUE_TYPE_SELECTION
 PRO_E_PATCH_TYPE            Solidify Type          PRO_VALUE_TYPE_INT
 PRO_E_PATCH_MATERIAL_SIDE   Material Side          PRO_VALUE_TYPE_INT
 PRO_E_IS_SMT_CUT            Is Smt Cut             PRO_VALUE_TYPE_INT
 PRO_E_SMT_CUT_NORMAL_DIR    Normal Direction       PRO_VALUE_TYPE_INT
 PRO_E_STD_FEATURE_NAME      Feature Name           PRO_VALUE_TYPE_WSTRING
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                  Element Name         Valid Values                 
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type         See Note-1
 PRO_E_FEATURE_FORM          Feature Form         See Note-2
 PRO_E_PATCH_QUILT           Reference            PRO_QUILT
                                                   or PRO_DATUM_PLANE
 PRO_E_PATCH_TYPE            Solidify Type        See Note-3
 PRO_E_PATCH_MATERIAL_SIDE   Material Side        ProSolidifySideOption
 PRO_E_IS_SMT_CUT            Is Smt Cut           See Note-4
 PRO_E_SMT_CUT_NORMAL_DIR    Normal Direction     See Note-5
 PRO_E_STD_FEATURE_NAME      Feature Name         See Note-6
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Variation                         Element Name                Comment
-------------------------------------------------------------------------------
 All types                         PRO_E_FEATURE_TYPE          Mandatory
                                   PRO_E_FEATURE_FORM          Mandatory
                                   PRO_E_PATCH_QUILT           Mandatory
                                   PRO_E_PATCH_TYPE            Optional(Note-3)
                                   PRO_E_PATCH_MATERIAL_SIDE   Optional
                                   PRO_E_IS_SMT_CUT            Optional(Note-4)
                                   PRO_E_SMT_CUT_NORMAL_DIR    Optional(Note-5)
                                   PRO_E_STD_FEATURE_NAME      Optional(Note-6)
===============================================================================

(5) Notes

   Note-1 : PRO_E_FEATURE_TYPE can be PRO_FEAT_PROTRUSION 
                              or PRO_FEAT_CUT 
                              or PRO_FEAT_PATCH
                              or PRO_FEAT_CUT_SMT ( only in sheetmetal parts ).

   Note-2 : PRO_E_FEATURE_FORM can be :
            PRO_USE_SURFS if PRO_E_FEATURE_TYPE is PRO_FEAT_PROTRUSION 
                                                    or PRO_FEAT_CUT
                                                    or PRO_FEAT_CUT_SMT
            PRO_NOTYPE if PRO_E_FEATURE_TYPE is PRO_FEAT_PATCH

   Note-3 : This element is optional. If present this element should
            have same value as PRO_E_FEATURE_TYPE except the case 
            of PRO_FEAT_CUT_SMT. For PRO_FEAT_CUT_SMT this element
            has the value PRO_FEAT_CUT and the element
            PRO_E_IS_SMT_CUT has the value PRO_B_TRUE.
          
   Note-4 : This element is applicable only in sheetmetal parts.
            Controls cut type, SMT or SOLID.
            PRO_B_TRUE for SMT cut type.

   Note-5 : This element is applicable only in sheetmetal parts.
            SMT Cut geometry driving surface.
            This element can be PRO_SMT_CUT_DRVSIDE_GREEN for normal to 
            Driven Surface or PRO_SMT_CUT_DRVSIDE_WHITE for normal to
            Offset Surface.
            ProSmtCutNormDir.

   Note-6 : Solidify feature name.
            Default value is:
              "PROTRUSION" if PRO_E_FEATURE_TYPE is PRO_FEAT_PROTRUSION
              "CUT"        if PRO_E_FEATURE_TYPE is PRO_FEAT_CUT
              "PATCH"      if PRO_E_FEATURE_TYPE is PRO_FEAT_PATCH
              
=============================================================================*/

/* 
(6) Enum Declarations 
*/

/* ==================== */
/* Side options of Solidify: */
/* ==================== */

typedef enum _ProSolidifySideOption
{
 PRO_SOLIDIFY_SIDE_ONE     = -1,
 PRO_SOLIDIFY_SIDE_TWO     = 1
} ProSolidifySideOption;


PRO_END_C_DECLS
#endif /* PRO_SOLIDIFY_H */
