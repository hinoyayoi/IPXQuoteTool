#ifndef PRO_THICKEN_H
#define PRO_THICKEN_H

/*
   Creo Parametric TOOLKIT declarations related to Thicken feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_FEATURE_FORM
      |
      |-- PRO_E_FEAT_FORM_ALWAYS_THIN
      |
      |-- PRO_E_STD_USEQLT_QLT
      |
      |-- PRO_E_THICKEN_TYPE
      |
      |-- PRO_E_STD_USEQLT_SIDE
      |
      |-- PRO_E_USEQLT_SOLID_SIDE
      |
      |-- PRO_E_THICKNESS
      |
      |-- PRO_E_SRF_OFFS_METHOD
      |
      |-- PRO_E_SRF_OFFS_CTRLFIT
      |     |
      |     |-- PRO_E_SRF_OFFS_SCALINGCSYS
      |     |
      |     |-- PRO_E_SRF_OFFS_AXISES
      |
      |-- PRO_E_SRF_OFFS_HANDLINGS
      |    |
      |    |-- PRO_E_SRF_OFFS_HANDLING
      |         |
      |         |-- PRO_E_SRF_OFFS_REF_SEL
      |         |
      |         |-- PRO_E_SRF_OFFS_ACTION
      |
      |-- PRO_E_IS_SMT_CUT
      |
      |-- PRO_E_SMT_CUT_NORMAL_DIR
      |
      |-- PRO_E_STD_FEATURE_NAME


===============================================================================

(2) Feature Elements Table

-------------------------------------------------------------------------------
 Element Id                  Element Name                Data Type             
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type             PRO_VALUE_TYPE_INT       
 PRO_E_FEATURE_FORM          Feature Form             PRO_VALUE_TYPE_INT       
 PRO_E_FEAT_FORM_ALWAYS_THIN Thin Form                PRO_VALUE_TYPE_INT       
 PRO_E_STD_USEQLT_QLT        Reference Quilt          PRO_VALUE_TYPE_SELECTION 
 PRO_E_THICKEN_TYPE          Thicken type             PRO_VALUE_TYPE_INT
 PRO_E_STD_USEQLT_SIDE       Material Side            PRO_VALUE_TYPE_INT       
 PRO_E_USEQLT_SOLID_SIDE     Solid Material Side      PRO_VALUE_TYPE_INT
                                                      (See Note-6)       
 PRO_E_THICKNESS             Thickness                PRO_VALUE_TYPE_DOUBLE    
 PRO_E_SRF_OFFS_METHOD       Offset method            PRO_VALUE_TYPE_INT       
 PRO_E_SRF_OFFS_CTRLFIT      Control Fit              PRO_ELEM_COMPOUND        
 PRO_E_SRF_OFFS_SCALINGCSYS  Control Fit Csys         PRO_VALUE_TYPE_SELECTION 
 PRO_E_SRF_OFFS_AXISES       Control Fit Axes         PRO_VALUE_TYPE_INT       
 PRO_E_SRF_OFFS_HANDLINGS    Special Handlings        PRO_ELEM_ARRAY           
 PRO_E_SRF_OFFS_HANDLING     Special Handling item    PRO_ELEM_COMPOUND        
 PRO_E_SRF_OFFS_REF_SEL      Special Handling faces   PRO_VALUE_TYPE_SELECTION 
 PRO_E_SRF_OFFS_ACTION       Special Handling action  PRO_VALUE_TYPE_INT 
 PRO_E_IS_SMT_CUT            Is Smt Cut               PRO_VALUE_TYPE_INT 
 PRO_E_SMT_CUT_NORMAL_DIR    Normal Direction         PRO_VALUE_TYPE_INT
 PRO_E_STD_FEATURE_NAME      Feature Name             PRO_VALUE_TYPE_WSTRING   
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                  Element Name         Valid Values                 
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type         PRO_FEAT_PROTRUSION 
                                                   or PRO_FEAT_CUT
 PRO_E_FEATURE_FORM          Feature Form         PRO_USE_SURFS
 PRO_E_FEAT_FORM_ALWAYS_THIN Thin Form            PRO_THIN (See Note-1)
 PRO_E_STD_USEQLT_QLT        Reference Quilt      PRO_QUILT  
 PRO_E_THICKEN_TYPE          Thicken type         See Note-2
 PRO_E_STD_USEQLT_SIDE       Material Side        ProThickenSideOption
 PRO_E_USEQLT_SOLID_SIDE     Solid Material Side  See Note-6       
 PRO_E_SRF_OFFS_METHOD       Offset method        ProThickenOffMethodOpts
 PRO_E_SRF_OFFS_SCALINGCSYS  Control Fit Csys     PRO_CSYS  
 PRO_E_SRF_OFFS_AXISES       Control Fit Axes     ProThickenAxesOption
 PRO_E_SRF_OFFS_REF_SEL      Spl Handling faces   PRO_SURFACE (See Note-3)
 PRO_E_SRF_OFFS_ACTION       Spl Handling action  ProThickenHandlingAction
 PRO_E_IS_SMT_CUT            Is Smt Cut           See Note-7
 PRO_E_SMT_CUT_NORMAL_DIR    Normal Direction     See Note-8
 PRO_E_STD_FEATURE_NAME      Feature Name         See Note-4
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Variation                         Element Name                Comment
-------------------------------------------------------------------------------
 All types                         PRO_E_FEATURE_TYPE          Mandatory
                                   PRO_E_FEATURE_FORM          Mandatory
                                   PRO_E_FEAT_FORM_ALWAYS_THIN Mandatory
                                   PRO_E_STD_USEQLT_QLT        Mandatory
                                   PRO_E_THICKEN_TYPE          Optional(Note-2)
                                   PRO_E_STD_USEQLT_SIDE       Optional
                                   PRO_E_USEQLT_SOLID_SIDE     Optional(Note-6)
                                   PRO_E_THICKNESS             Mandatory
                                   PRO_E_SRF_OFFS_METHOD       Optional(Note-5)
                                   PRO_E_IS_SMT_CUT            Optional(Note-7)
                                   PRO_E_SMT_CUT_NORMAL_DIR    Optional(Note-8)
                                   PRO_E_STD_FEATURE_NAME      Optional(Note-4)
...............................................................................
Offset method is                   PRO_E_SRF_OFFS_HANDLINGS    N/A
PRO_OFFS_METH_NORMTOSURF           PRO_E_SRF_OFFS_HANDLING     N/A
                                   PRO_E_SRF_OFFS_REF_SEL      Optional
				   PRO_E_SRF_OFFS_ACTION       Optional
...............................................................................
Offset method is                   None
PRO_OFFS_METH_AUTOSCALE
...............................................................................
Offset method is                   PRO_E_SRF_OFFS_CTRLFIT      N/A
PRO_OFFS_METH_MANUALSCALE          PRO_E_SRF_OFFS_SCALINGCSYS  Mandatory
                                   PRO_E_SRF_OFFS_AXISES       Optional
===============================================================================
(5) Notes

   Note-1 : This is a non-redefinable mandatory element for Thicken.
            Its only valid value is PRO_THIN.
            The element should be set after PRO_E_FEATURE_FORM.

   Note-2 : This element is optional. If present this element should
            have same value as PRO_E_FEATURE_TYPE except the case
            of PRO_FEAT_CUT_SMT. For PRO_FEAT_CUT_SMT this element
            has the value PRO_FEAT_CUT and the element
            PRO_E_IS_SMT_CUT has the value PRO_B_TRUE.

   Note-3 : Surfaces should be from Reference Quilt

   Note-4 : Thicken feature name.
            Default value is:
              "PROTRUSION" if PRO_E_FEATURE_TYPE is PRO_FEAT_PROTRUSION
              "CUT"        if PRO_E_FEATURE_TYPE is PRO_FEAT_CUT

   Note-5 : Default Offset method is PRO_OFFS_METH_NORMTOSURF

   Note-6 : PRO_E_USEQLT_SOLID_SIDE will always be invisible for Thicken.
            Its value will always be ignored.
   
   Note-7 : This element is applicable only in sheetmetal parts.
            Controls cut type, SMT or SOLID.
            PRO_B_TRUE for SMT cut type.

   Note-8 : This element is applicable only in sheetmetal parts.
            SMT Cut geometry driving surface.
            This element can be PRO_SMT_CUT_DRVSIDE_GREEN for normal to
            Driven Surface or PRO_SMT_CUT_DRVSIDE_WHITE for normal to
            Offset Surface.
            ProSmtCutNormDir.

==============================================================================*/
/*
(6) Enum Declarations
*/

/* ========================= */
/* Side options of Thicken : */
/* ========================= */

typedef enum _ProThickenSideOption
{
 PRO_THICKEN_SIDE_ONE     = -1,
 PRO_THICKEN_BOTH_SIDES   = 0,
 PRO_THICKEN_SIDE_TWO     = 1
} ProThickenSideOption;


/* =========================== */
/* Offset Method for Thicken : */
/* =========================== */

typedef enum _ProThickenOffMethodOpts
{
   PRO_OFFS_METH_NORMTOSURF  = 1,
   PRO_OFFS_METH_AUTOSCALE   = 2,
   PRO_OFFS_METH_MANUALSCALE = 3
} ProThickenOffMethodOpts;

typedef enum _ProThickenAxesOption
{
    PRO_OFFS_TRF_NONE = 0,
    PRO_OFFS_TRF_X    = 1,
    PRO_OFFS_TRF_Y    = 2,
    PRO_OFFS_TRF_Z    = 4,
    PRO_OFFS_TRF_XY   = 3,
    PRO_OFFS_TRF_YZ   = 6,
    PRO_OFFS_TRF_ZX   = 5,
    PRO_OFFS_TRF_ALL  = 7
} ProThickenAxesOption;

typedef enum _ProThickenHandlingAction
{
    PRO_OFFS_ACTION_LEAVE  = -1,
    PRO_OFFS_ACTION_APPROX = 1
} ProThickenHandlingAction;

PRO_END_C_DECLS
#endif /* PRO_THICKEN_H */
