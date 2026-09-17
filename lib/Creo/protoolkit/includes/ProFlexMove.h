#ifndef PROFLEXMOVE_H
#define PROFLEXMOVE_H

/*
   Creo Parametric TOOLKIT declarations related to the Flex Move feature.
*/



#include <ProToolkit.h>
#include <ProFlxmdlOpts.h>
#include <ProFlexTanPropOpts.h>
#include <ProAsmcomp.h>

PRO_BEGIN_C_DECLS
/*================================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_FLEXMOVE_MOVED_GEOMETRY
      |      |
      |      |-- PRO_E_STD_SURF_COLLECTION_APPL
      |      |
      |      |-- PRO_E_FLEXMOVE_EXCLUDED_GEOMETRY
      |      |      |
      |      |      |-- PRO_E_STD_SURF_COLLECTION_APPL
      |      |   
      |      |-- PRO_E_FLEXMOVE_DTM_REF
      |
      |-- PRO_E_FLEXMOVE_MOVED_COMPS
      |
      |-- PRO_E_FLEXMOVE_DEFINE_METHOD
      |
      |-- PRO_E_D3ELEM_SETS (D3Elem branch, see ProD3Elem.h)
      |
      |-- PRO_E_FLEXMOVE_DIMS_COMPOUND
      |      |
      |      |-- PRO_E_FLEXMOVE_DIMS_ARRAY
      |             |
      |             |-- PRO_E_FLEXMOVE_DIM_COMPOUND
      |                    |
      |                    |-- PRO_E_FLEXMOVE_DIM_TYPE
      |                    |
      |                    |-- PRO_E_FLEXMOVE_DIM_REFS
      |                    |
      |                    |-- PRO_E_FLEXMOVE_DIM_VALUE      
      |
      |-- PRO_E_FLEX_OPTS_CMPND   (General FLX-MDL options branch, see ProFlxmdlOpts.h)
      |
      |-- PRO_E_FLXSLV_PROP_CONSTRS (General FLX-MDL tangency propagation branch,
      |                              see ProFlexTanPropOpts.h)
      |-- PRO_E_COMPONENT_MISC_ATTR
      |
      |-- PRO_E_COMPONENT_INIT_POS
      |
      |-- PRO_E_COMP_PLACE_INTERFACE
      |
      |-- PRO_E_COMPONENT_SETS    (Placemet sets branch, see ProAsmcomp.h)
      |
      |-- PRO_E_COMPONENT_CONSTRAINTS (Placement constraints branch see ProAsmcomp.h)
      |   
      |-- PRO_E_STD_FLEX_PROPAGATION
      
===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------------------------------
 Element Id                       Element Name                  Data Type                 Valid Values
------------------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE               Feature Type                  PRO_VALUE_TYPE_INT        
 PRO_E_STD_FEATURE_NAME           Feature Name                  PRO_VALUE_TYPE_WSTRING
 PRO_E_FLEXMOVE_MOVED_GEOMETRY    Moved Geometry                Compound
 PRO_E_STD_SURF_COLLECTION_APPL   Geometry                      PRO_VALUE_TYPE_SELECTION  Note-1
 PRO_E_FLEXMOVE_EXCLUDED_GEOMETRY Excluded Geometry             Compound
 PRO_E_STD_SURF_COLLECTION_APPL   Geometry                      PRO_VALUE_TYPE_SELECTION  Note-2
 PRO_E_FLEXMOVE_DTM_REF           Datums                        PRO_ELEM_TYPE_MULTI_VALUE Note-3
 PRO_E_FLEXMOVE_MOVED_COMPS       Component references          PRO_ELEM_TYPE_MULTI_VALUE Note-4
 PRO_E_FLEXMOVE_DEFINE_METHOD     Definition Method             PRO_VALUE_TYPE_INT        Note-5
 PRO_E_D3ELEM_SETS                Sets                          Array Holder              Note-6
 PRO_E_FLEXMOVE_DIMS_COMPOUND     Constraining Dimensions       Compound
 PRO_E_FLEXMOVE_DIMS_ARRAY        Dimensions Array              Array holder              Note-7
 PRO_E_FLEXMOVE_DIM_COMPOUND      Constraining Dimension        Compound
 PRO_E_FLEXMOVE_DIM_TYPE          Dimension Type                PRO_VALUE_TYPE_INT        Note-8
 PRO_E_FLEXMOVE_DIM_REFS          Dimension References          PRO_ELEM_TYPE_MULTI_VALUE Note-9
 PRO_E_FLEXMOVE_DIM_VALUE         Dimension Value               PRO_VALUE_TYPE_DOUBLE     Note-10
 PRO_E_FLEX_OPTS_CMPND            FLX-MDL Options               Compound                  Note-11
 PRO_E_FLXSLV_PROP_CONSTRS        FLX-MDL Propagation           Array                     Note-12
 PRO_E_COMPONENT_MISC_ATTR        Comp Set Misc Attr            PRO_VALUE_TYPE_INT        Note-13
 PRO_E_COMPONENT_INIT_POS         Component Initial Pos         PRO_VALUE_TYPE_TRANSFORM
 PRO_E_COMP_PLACE_INTERFACE       Compoment Interface Placement Compound                  Note-13
 PRO_E_COMPONENT_SETS             Component Sets                Array holder              Note-13     
 PRO_E_COMPONENT_CONSTRAINTS      Constraints                   Array holder              Note-13
 PRO_E_STD_FLEX_PROPAGATION       Propagation                   PRO_VALUE_TYPE_SELECTION  Note-14
================================================================================================

(3) Notes

    Note-1  : Mandatory - A surface set of the moved geometry. May include surface regions.

    Note-2  : Optional - A surface set of geometry that is excluded from the moved geometry.
              Valid Selections: Surfaces in the moved geometry.

    Note-3  : Optional - Datums to move along with the moved geometry.

    Note-4  : Optional - (Assembly Move only) Component references to move in this assembly.
 
    Note-5  : Mandatory - The definition method of the Flex Move Feature.

              Valid Values:
              -------------
                PRO_FLEXMOVE_DEF_METHOD_3D_DRAG     - The Flex Move feature is defined using
                                                      3D transformations sets (3D Dragger in UI).
                PRO_FLEXMOVE_DEF_METHOD_DIMENSIONS  - The Flex Move feature is defined using
                                                      up to three constraining dimensions.
                PRO_FLEXMOVE_DEF_METHOD_CONSTRAINTS - The Flex Move feature is defined using
                                                      Component-like constraints.

    Note-6  : Mandatory* - The D3 sets branch is relevant when the definition method
                           is PRO_FLEXMOVE_DEF_METHOD_3D_DRAG. Please refer to ProD3Elem.h
                           for information regarding the D3 elements.

    Note-7  : Mandatory* - The dimensions array may contain up to three dimensions
                           of PRO_FLEXMOVE_DIM_TYPE_LINEAR type. Or a single dimension of
                           PRO_FLEXMOVE_DIM_TYPE_ANGULAR type. 
                           This array, like all dimension related elements, is relevant only
                           when the definition method is PRO_FLEXMOVE_DEF_METHOD_DIMENSIONS

    Note-8  : Mandatory* - The type of the given Flex Move dimension.

              PLEASE NOTE:
                The value of this element is set automatically according to the
                selected dimension references.
                DO NOT SET THIS VALUE MANUALLY.
             
              Valid Values:
              -------------
                PRO_FLEXMOVE_DIM_TYPE_UNDEFINED - A dimension cannot be created using the 
                                                  given dimension references.
                PRO_FLEXMOVE_DIM_TYPE_LINEAR    - A linear dimension.
                PRO_FLEXMOVE_DIM_TYPE_ANGULAR   - An angular dimension.

    Note-9  : Mandatory* - Two references for the given dimension.

              Valid Selections:
              -----------------
                surfaces : SEL_3D_SRF
                lines    : SEL_3D_EDG, SEL_3D_CURVE, SEL_3D_AXIS
                points   : SEL_3D_VERT, SEL_3D_PNT, SEL_CURVE_END
           
              Valid Selections Combinations:
              ------------------------------
                surface - surface
                surface - line
                surface - point
                line    - line
                line    - point
              
              Additional Restriction:
              -----------------------
                One of the two selections must belong to the moved geometry,
                while the other must belong to the unaffected geometry.

    Note-10  : Mandatory* - The given dimension value.
              
              Valid values:
              -------------
                Linear dimensions : [-1e6,1e6]
                Angular dimensions: [0,360]
                           
    Note-11 : Mandatory - a branch of general flexible modeling option elements.
              Contains integer and chain collection type elements.
              Please consult ProFlxmdlOpts.h to see which elements in the compound
              are relevant to the Flex Move feature.

    Note-12 : Optional - An array of conditions to control tangency propagation.
              This is applicable when the tangency propagation is active.
              This implies that PRO_E_FLEX_PROPAGATE_TANGENCY of PRO_E_FLEX_OPTS_CMPND 
              has value PRO_FLEXMODEL_OPT_YES.
              Please consult ProFlexTanPropOpts.h to see the more information about it.

    Note-13 : Mandatory* - The ASM-Component-like constraints elements are relevant
                           when the definition method is 
                           PRO_FLEXMOVE_DEF_METHOD_CONSTRAINTS

              PRO_E_COMPONENT_SETS and PRO_E_COMPONENT_CONTRAINTS are two arrays
              that hold the constraints sets and the constraints themselves
              respectively.

              Each set may contain several constraints which are associated with it
              in the following manner: The set has a unique, zero-based id, 
              in PRO_E_COMPONENT_SET_ID and constraints are linked to the set by
              specifying this id in PRO_E_COMPONENT_CONSTR_SET_ID.

              FOR MORE INFORMATION REGARDING SETS AND CONSTRAINTS, PLEASE REFER
              TO ProAsmcomp.h

              The following three elements SHOULD NOT BE ACCESSED MANUALLY:
              -------------------------------------------------------------
              PRO_E_COMPONENT_MISC_ATTR  - Constrained placement misc attrs.
              PRO_E_COMPONENT_INIT_POS   - Initial constrained placement.
              PRO_E_COMP_PLACE_INTERFACE - Placement by assembly interfaces.

    Note-14 : Optional - A pattern/mirror regonition feature to use, for patterning
              the Flex Move feature.

==============================================================================*/

#define PRO_FLEXMOVE_DEF_METHOD_3D_DRAG     0
#define PRO_FLEXMOVE_DEF_METHOD_DIMENSIONS  1
#define PRO_FLEXMOVE_DEF_METHOD_CONSTRAINTS 2

#define PRO_FLEXMOVE_DIM_TYPE_UNDEFINED     0
#define PRO_FLEXMOVE_DIM_TYPE_LINEAR        1
#define PRO_FLEXMOVE_DIM_TYPE_ANGULAR       2


/*===========================================================================*/


PRO_END_C_DECLS
#endif

