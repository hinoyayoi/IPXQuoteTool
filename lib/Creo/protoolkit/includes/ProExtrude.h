#ifndef PROEXTRUDEH
#define PROEXTRUDEH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************\

1  Summary of Element Tree Changes as compared to pre- Pro/E Wildfire releases :
====================================================
     The Element tree for Extrude has been updated to incorporate
 the following feature creation using the same element tree.

 1]  Solid Protrusion
 2]  Thin Protrusion
 3]  Solid/SMT Cut
 4]  Thin Solid/Smt Cut
 5]  Surface
 6]  Surface Trim
 7]  Thin Surface Trim
 8]  Solid Protrusion as First feature 
 9]  Thin Protrusion as First feature 
 10] Smt unattached wall
    
\*****************************************************************************/
/*****************************************************************************\

2  Feature element tree:
========================

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_STD_FEATURE_NAME
     |   
     |--PRO_E_EXT_SURF_CUT_SOLID_TYPE
     |   
     |--PRO_E_REMOVE_MATERIAL
     |
     |--PRO_E_IS_SMT_CUT              ( applicable only in sheetmetal parts )
     | 
     |--PRO_E_SMT_CUT_NORMAL_DIR      ( applicable only in sheetmetal parts )
     |
     |--PRO_E_FEATURE_FORM
     |   
     |--PRO_E_STD_SECTION             ( Section )
     |   
     |--PRO_E_FEAT_FORM_IS_THIN       ( Feature Form )
     |   
     |--PRO_E_STD_MATRLSIDE           ( Material Side )
     |   
     |--PRO_E_THICKNESS               ( Thickness )
     |   
     |--PRO_E_SRF_END_ATTRIBUTES
     |   
     |--PRO_E_TRIM_QLT_SIDE
     |   
     |--PRO_E_TRIM_QUILT
     |   
     |--PRO_E_STD_DIRECTION
     |   
     |--PRO_E_STD_EXT_DEPTH
     |    | 
     |    |--PRO_E_EXT_DEPTH_FROM
     |         |--PRO_E_EXT_DEPTH_FROM_TYPE
     |         |--PRO_E_EXT_DEPTH_FROM_REF
     |         |--PRO_E_EXT_DEPTH_FROM_REF_TRF
     |         |--PRO_E_EXT_DEPTH_FROM_REF_TRF_VAL
     |         |--PRO_E_EXT_DEPTH_FROM_VALUE
     |    |  
     |    |--PRO_E_EXT_DEPTH_TO
     |         |--PRO_E_EXT_DEPTH_TO_TYPE
     |         |--PRO_E_EXT_DEPTH_TO_REF
     |         |--PRO_E_EXT_DEPTH_TO_REF_TRF
     |         |--PRO_E_EXT_DEPTH_TO_REF_TRF_VAL
     |         |--PRO_E_EXT_DEPTH_TO_VALUE
     |
     |--PRO_E_STD_SMT_THICKNESS  ( applicable only in sheetmetal parts )
     |
     |--PRO_E_STD_SMT_SWAP_DRV_SIDE  ( applicable only in sheetmetal parts )
     |
     |--PRO_E_SMT_WALL_SHARPS_TO_BENDS  ( applicable only in sheetmetal parts )
     |
     |--PRO_E_SMT_PUNCH_AXIS_PNT ( applicable only in sheetmetal parts )
     |
     |--PRO_E_SMT_FILLETS  ( applicable only in sheetmetal parts )
     |    |
     |    |--PRO_E_SMT_FILLETS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLETS_VALUE
     |
     |--PRO_E_SMT_DEV_LEN_CALCULATION  ( applicable only in sheetmetal parts )
     |    |
     |    |--PRO_E_SMT_DEV_LEN_SOURCE
     |    |
     |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR
     |    |    |
     |    |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE
     |    |
     |    |--PRO_E_SMT_DEV_LEN_BEND_TABLE
     |
     |--PRO_E_SMT_PUNCH_TOOL_DATA ( applicable only in sheetmetal parts )
     |    |
     |    |--PRO_E_SMT_PUNCH_TOOL_ATTR
     |    |
     |    |--PRO_E_SMT_PUNCH_TOOL_NAME
     |
     |--PRO_E_SMT_MERGE_DATA ( applicable only in sheetmetal parts )
     |    |
     |    |--PRO_E_SMT_MERGE_AUTO
     |    |
     |    |--PRO_E_SMT_MERGE_KEEP_LINES
     |  
     |--PRO_E_EXT_COMP_DRFT_ANG
     |    |
     |    |--PRO_E_EXT_DRFT_ANG
     |    |
     |    |--PRO_E_EXT_DRFT_ANG_VAL
     |
     |--PRO_E_FEAT_THIN
     |    |
     |    |--PRO_E_FEAT_THIN_STRT
     |    |   |
     |    |   |--PRO_E_FEAT_THIN_STRT_OPT
     |    |   |
     |    |   |--PRO_E_FEAT_THIN_STRT_REF
     |    |
     |    |--PRO_E_FEAT_THIN_END
     |    |   |
     |    |   |--PRO_E_FEAT_THIN_END_OPT
     |    |   |
     |    |   |--PRO_E_FEAT_THIN_END_REF


\*****************************************************************************/
/*****************************************************************************\

3. Feature elements table and Mapping with Old Element Tree:
============================================================

------------------------------------------------------------------------------
Element Id                       Element Name        Data Type             
------------------------------------------------------------------------------
PRO_E_STD_FEATURE_NAME           Feature Name        PRO_VALUE_TYPE_WSTRING
PRO_E_EXT_SURF_CUT_SOLID_TYPE    Feature Type        PRO_VALUE_TYPE_INT   
PRO_E_REMOVE_MATERIAL            Material            PRO_VALUE_TYPE_INT
PRO_E_IS_SMT_CUT                 Is Smt Cut          PRO_VALUE_TYPE_INT
PRO_E_SMT_CUT_NORMAL_DIR         Normal Direction    PRO_VALUE_TYPE_INT
PRO_E_FEATURE_FORM               Feature Form        PRO_VALUE_TYPE_INT   
PRO_E_STD_SECTION                Section             Compound             
PRO_E_FEAT_FORM_IS_THIN          Feature Form        PRO_VALUE_TYPE_INT      
PRO_E_STD_MATRLSIDE              Material Side       PRO_VALUE_TYPE_INT 
PRO_E_THICKNESS                  Thin width          PRO_VALUE_TYPE_DOUBLE
PRO_E_SRF_END_ATTRIBUTES         End Cap             PRO_VALUE_TYPE_INT
PRO_E_TRIM_QLT_SIDE              Quilt Side          PRO_VALUE_TYPE_INT
PRO_E_TRIM_QUILT                 Trim Quilt          PRO_VALUE_TYPE_SELECTION 
PRO_E_STD_DIRECTION              Direction           PRO_VALUE_TYPE_INT
PRO_E_STD_EXT_DEPTH              Depth               Compound
PRO_E_EXT_DEPTH_FROM             Depth From          Compound
PRO_E_EXT_DEPTH_FROM_TYPE        Type                PRO_VALUE_TYPE_INT
PRO_E_EXT_DEPTH_FROM_REF         References          PRO_VALUE_TYPE_SELECTION
PRO_E_EXT_DEPTH_FROM_VALUE       Value               PRO_VALUE_TYPE_DOUBLE
PRO_E_EXT_DEPTH_FROM_REF_TRF     Transform           PRO_VALUE_TYPE_INT
PRO_E_EXT_DEPTH_FROM_REF_TRF_VAL Value               PRO_VALUE_TYPE_DOUBLE
PRO_E_EXT_DEPTH_TO               Depth To            Compound
PRO_E_EXT_DEPTH_TO_TYPE          Type                PRO_VALUE_TYPE_INT
PRO_E_EXT_DEPTH_TO_REF           References          PRO_VALUE_TYPE_SELECTION
PRO_E_EXT_DEPTH_TO_VALUE         Value               PRO_VALUE_TYPE_DOUBLE
PRO_E_EXT_DEPTH_TO_REF_TRF       Transform           PRO_VALUE_TYPE_INT
PRO_E_EXT_DEPTH_TO_REF_TRF_VAL   Value               PRO_VALUE_TYPE_DOUBLE
PRO_E_INT_PARTS                  Intsct Parts        Compound
PRO_E_PATTERN                    Pattern             Compound
PRO_E_STD_SMT_THICKNESS          Smt Thickness       PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_SMT_SWAP_DRV_SIDE      Smt Swap Side       PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_SHARPS_TO_BENDS   Edges to Bends      PRO_VALUE_TYPE_INT
PRO_E_SMT_PUNCH_AXIS_PNT         Punch Axis Point    PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS                Smt Fillets         Compound
PRO_E_SMT_FILLETS_SIDE           Smt Radius Side     PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE          Smt Radius Value    PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_CALCULATION    Smt Develop Length  Compound
PRO_E_SMT_DEV_LEN_SOURCE         Smt Dev Len Source  PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_Y_FACTOR       Smt Dev Len Y Fact  Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE Y Factor Value      PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE  Y Factor Type       PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_BEND_TABLE     Smt Dev Bend Table  PRO_VALUE_TYPE_INT
PRO_E_SMT_PUNCH_TOOL_DATA        Punch Tool Data     Compound
PRO_E_SMT_PUNCH_TOOL_ATTR        Punch Tool Attribs  PRO_VALUE_INT
PRO_E_SMT_PUNCH_TOOL_NAME        Punch Tool Name     PRO_VALUE_WSTRING
PRO_E_SMT_MERGE_DATA             Smt Merge Wall Data Compound
PRO_E_SMT_MERGE_AUTO             Auto Merge Flag     PRO_VALUE_INT
PRO_E_SMT_MERGE_KEEP_LINES       Keep Merged Lines   PRO_VALUE_INT
PRO_E_EXT_COMP_DRFT_ANG          Draft               Compound
PRO_E_EXT_DRFT_ANG               Add Draft           PRO_VALUE_TYPE_INT
PRO_E_EXT_DRFT_ANG_VAL           Draft Angle         PRO_VALUE_TYPE_DOUBLE
PRO_E_FEAT_THIN                  Thin Def            Compound
PRO_E_FEAT_THIN_STRT             Thin Start          Compound
PRO_E_FEAT_THIN_STRT_OPT         Thin Option         PRO_VALUE_TYPE_INT
PRO_E_FEAT_THIN_STRT_REF         Reference           PRO_VALUE_TYPE_SELECTION
PRO_E_FEAT_THIN_END              Thin Start          Compound
PRO_E_FEAT_THIN_END_OPT          Thin Option         PRO_VALUE_TYPE_INT
PRO_E_FEAT_THIN_END_REF          Reference           PRO_VALUE_TYPE_SELECTION


-----------------------------------------------------------------------------
3.1 Mapping given only for changed Element Ids.
------------------------------------------------------------------------------
New Element Id                        Old Element ID 
------------------------------------------------------------------------------
PRO_E_EXT_SURF_CUT_SOLID_TYPE         PRO_E_FEATURE_TYPE 
PRO_E_SRF_END_ATTRIBUTES              PRO_E_ATTRIBUTES->PRO_E_ATTR_SRF_END_COND
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
3.2 New Element IDs in the element tree .
------------------------------------------------------------------------------
New Element Id                        
------------------------------------------------------------------------------
PRO_E_EXT_SURF_CUT_SOLID_TYPE
PRO_E_SRF_END_ATTRIBUTES
PRO_E_THICKNESS
PRO_E_STD_MATRLSIDE
PRO_E_REMOVE_MATERIAL
PRO_E_STD_FEATURE_NAME
PRO_E_TRIM_QUILT
PRO_E_TRIM_QLT_SIDE
PRO_E_STD_DIRECTION

-----------------------------------------------------------------------------
\*****************************************************************************/
/*****************************************************************************\

The Elements mentioned in the table below are for Solid Protrusion.
For other features, additional elements required, are mentioned below in
table 4.2.
-----------------------------------------------------------------------------
Table 4.1 : Common elements for all type of Extrusions and it's value
-----------------------------------------------------------------------------
| Element Id                  | Value                                  |
---------------------------------------------------------------------
|PRO_E_EXT_SURF_CUT_SOLID_TYPE| Mandatory                              |
|                             | Of type ProExtFeatType                 |
|                             | = PRO_EXT_FEAT_TYPE_SOLID              |
|                             |        for Solid feat type             |
|                             | = PRO_EXT_FEAT_TYPE_SURFACE            |
|                             |        for Surface feat type           |
|.............................|........................................|
| PRO_E_REMOVE_MATERIAL       | Material Removal                       |
|                             | Of type ProExtRemMaterial              |
|                             | = PRO_EXT_MATERIAL_ADD                 |
|                             |        for Protruded feature           |
|                             | = PRO_EXT_MATERIAL_REMOVE              |
|                             |        for Cut feature                 |
|.............................|........................................|
| PRO_E_FEATURE_FORM          | Feature Form                           |
|                             | Valid Value : PRO_EXTRUDE              |
|.............................|........................................|
| PRO_E_STD_SECTION           | For more details refer ProStdSection.h |
|.............................|........................................|
| PRO_E_STD_DIRECTION         | Direction of creation.                 |
|                             | Depends on PRO_E_STD_SECTION           |
|                             | See Note 3 for details.                |
|                             | Of type ProExtDirection                |
|                             | = PRO_EXT_CR_IN_SIDE_ONE               |
|                             |        for depth in side one           |
|                             | = PRO_EXT_CR_IN_SIDE_TWO               |
|                             |        for depth in side two           |
|.............................|........................................|
| PRO_E_STD_MATRLSIDE         | Required if open section and if        |
|                             | ProExtFeatType  is                     |
|                             | PRO_EXT_FEAT_TYPE_SOLID                |
|                             | Depends on PRO_E_STD_SECTION           |
|                             | See Note 3 for details.                |
|                             | Of type ProExtMatlSide.                |
|.............................|........................................|
| PRO_E_STD_EXT_DEPTH         | Compound Element                       |
|                             |                                        |
|.............................|........................................|
| PRO_E_EXT_DEPTH_TO          | Compound Element                       |
|                             |                                        |
|.............................|........................................|
| PRO_E_EXT_DEPTH_TO_TYPE     | Mandatory                              |
|                             | Of type ProExtDepthToType              |
|.............................|........................................|
| PRO_E_EXT_DEPTH_TO_VALUE    | Depends on PRO_E_EXT_DEPTH_TO_TYPE     |
|                             | Of type  PRO_VALUE_TYPE_DOUBLE         |
|.............................|........................................|
| PRO_E_EXT_DEPTH_TO_REF      | Depends on PRO_E_EXT_DEPTH_TO_TYPE     |
|                             | Of type  See Note 1.                   |
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM        | Compound Element                       |
|                             |                                        |
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM_TYPE   | Mandatory                              |
|                             | Of type ProExtDepthFromType            |
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM_VALUE  | Depends on PRO_E_EXT_DEPTH_FROM_TYPE   |
|                             | Of type  PRO_VALUE_TYPE_DOUBLE         |
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM_REF    | Depends on PRO_E_EXT_DEPTH_FROM_TYPE   |
|                             | Of type   See Note 1.                  |
|.............................|........................................|
| PRO_E_STD_FEATURE_NAME      | Default given by application depending |
|                             | on feature type.Can be modified by user|
|.............................|........................................|

-----------------------------------------------------------------------------
Table Extrude:4.2 : Elements required for each feature in addition to 
                     those mentioned above. 
-----------------------------------------------------------------------------
|          | Element Id                     | Comment                         |
------------------------------------------------------------------------------
| Solid    :                                :                                 |
|          : PRO_E_EXT_COMP_DRFT_ANG        : Compound Element                |                |
|          : PRO_E_EXT_DRFT_ANG             : Of type ProExtDrftAng           |
|          :                                : = PRO_EXT_DRFT_ANG_NO_DRAFT     |
|          :                                : for feature not having Draft    |
|          :                                : = PRO_EXT_DRFT_ANG_DRAFT        |
|          :                                : for Tapered feature             |
|          : PRO_E_EXT_DRFT_ANG_VAL         : [-89.9,89.9]                    |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|..........:................................:.................................|
| Thin     :                                :                                 |
|          : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProExtMatlSide          |
|          : PRO_E_THICKNESS                : Mandatory   >= 0.0              |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProExtFeatForm          |
|          :                                : = PRO_EXT_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_EXT_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|          :                                :                                 |
|          : PRO_E_FEAT_THIN                : Compound Element                |
|          :                                : Available only for open section |
|          : PRO_E_FEAT_THIN_STRT           : Compound Element                |
|          : PRO_E_FEAT_THIN_END            : Compound Element                |
|          : PRO_E_FEAT_THIN_STRT_OPT       : Of type ProFeatThinOpt          |
|          :                                : = PRO_FEAT_THIN_IGNORE          |
|          :                                : for feature ignoring solution   |
|          :                                : = PRO_FEAT_THIN_DEFAULT         |
|          :                                : for feature using default       | 
|          :                                : solution.                       |
|          : PRO_E_FEAT_THIN_END_OPT        : Of type ProFeatThinOpt          |
|          :                                : = PRO_FEAT_THIN_IGNORE          |
|          :                                : for feature ignoring solution   |
|          :                                : = PRO_FEAT_THIN_DEFAULT         |
|          :                                : for feature using default       | 
|          :                                : solution.                       |
|          : PRO_E_FEAT_THIN_STRT_REF       : Stores the reference found from |
|          :                                : the start section point when    |
|          :                                : PRO_E_FEAT_THIN_STRT_OPT =      |
|          :                                : PRO_FEAT_THIN_DEFAULT           |
|          : PRO_E_FEAT_THIN_END_REF        : Stores the reference found from |
|          :                                : the end section point when      |
|          :                                : PRO_E_FEAT_THIN_END_OPT =       |
|          :                                : PRO_FEAT_THIN_DEFAULT           |
|..........:................................:.................................|
| Solid Cut:                                :                                 |
|          : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProExtMatlSide          |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProExtFeatForm          |
|          :                                : = PRO_EXT_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_EXT_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|          :                                :                                 |
|          : PRO_E_IS_SMT_CUT               : Controls cut type, SMT or SOLID |
|          :                                : PRO_B_TRUE / PRO_B_FALSE        |
|          :                                :                                 |
|          : PRO_E_SMT_CUT_NORMAL_DIR       : SMT Cut geometry driving surface|
|          :                                : See: ProSmtCutNormDir           |
|          :                                :                                 |
|          : PRO_E_SMT_PUNCH_TOOL_ATTR      : SMT Cut punch tool attributes   |
|          :                                : See: ProPunchToolAttr           |
|          :                                :                                 |
|          : PRO_E_SMT_PUNCH_TOOL_NAME      : SMT Cut punch tool name         |
|          :                                :                                 |
|          : PRO_E_SMT_PUNCH_AXIS_PNT       : SMT Cut punch axis point        |
|          :                                : PRO_B_TRUE / PRO_B_FALSE        |
|          :				                :	                              |
|          : PRO_E_EXT_COMP_DRFT_ANG        : Compound Element                |  
|          :                                : for feature not having Thin     |
|          :                                : See: Table Extrude:4.2, Solid   |
|..........:................................:.................................|
| Thin Cut :                                :                                 |
|          : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProExtMatlSide          |
|          : PRO_E_THICKNESS                : Mandatory  >= 0.0               |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProExtFeatForm          |
|          :                                : = PRO_EXT_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_EXT_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|          :                                :                                 |
|          : PRO_E_IS_SMT_CUT               : Controls cut type, SMT or SOLID |
|          :                                : PRO_B_TRUE / PRO_B_FALSE        |
|          :                                :                                 |
|          : PRO_E_SMT_CUT_NORMAL_DIR       : SMT Cut geometry driving surface|
|          :                                : See: ProSmtCutNormDir           |
|          :                                :                                 |
|          : PRO_E_SMT_PUNCH_TOOL_ATTR      : SMT Cut punch tool attributes   |
|          :                                : See: ProPunchToolAttr           |
|          :                                :                                 |
|          : PRO_E_SMT_PUNCH_TOOL_NAME      : SMT Cut punch tool name         |
|          :                                :                                 |
|          : PRO_E_FEAT_THIN                : Compound Element                |
|          :                                : See: Table Extrude:4.2, Thin    |
|..........:................................:.................................|
| Surface  :                                :                                 |
|          : PRO_E_SRF_END_ATTRIBUTES       :                                 |
|          :                                : Of type ProExtSurfEndAttr       |
|          :                                : Depends on PRO_E_STD_SECTION    |
|          :                                : See Note 3 for details.         |
|          :                                : Required only for closed section|
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProExtFeatForm          |
|          :                                : = PRO_EXT_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_EXT_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|          : PRO_E_EXT_COMP_DRFT_ANG        : Compound Element                |  
|          :                                : for feature not having Thin     |
|          :                                : See: Table Extrude:4.2, Solid   |
|..........:................................:.................................|
| Surface  :                                :                                 |
| Trim     : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProExtMatlSide          |
|          : PRO_E_TRIM_QUILT               : Mandatory                       |
|          :                                : Of type Quilt.                  |
|          : PRO_E_TRIM_QLT_SIDE            :                                 |
|          :                                : Of type ProExtTrimQltSide       |
|          :                                : Depends on PRO_E_STD_MATRLSIDE  |
|          :                                : See Note 3 for details.         |
|          :                                : Required only if ProExtMatlSide |
|          :                                :  is PRO_EXT_MATERIAL_BOTH_SIDES |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProExtFeatForm          |
|          :                                : = PRO_EXT_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_EXT_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|          : PRO_E_EXT_COMP_DRFT_ANG        : Compound Element                |  
|          :                                : for feature not having Thin     |
|          :                                : See: Table Extrude:4.2, Solid   |
|..........:................................:.................................|
| Thin     :                                :                                 |
| Surface  : PRO_E_STD_MATRLSIDE            : Mandatory                       |
| Trim     :                                : Of type ProExtMatlSide          |
|          : PRO_E_THICKNESS                : Mandatory    >= 0.0             |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          : PRO_E_TRIM_QUILT               : Mandatory                       |
|          :                                : Of type Quilt.                  |
|          : PRO_E_TRIM_QLT_SIDE            :                                 |
|          :                                : Of type ProExtTrimQltSide       |
|          :                                : Depends on PRO_E_STD_MATRLSIDE  |
|          :                                : See Note 3 for details.         |
|          :                                : Required only if ProExtMatlSide |
|          :                                :  is PRO_EXT_MATERIAL_BOTH_SIDES |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProExtFeatForm          |
|          :                                : = PRO_EXT_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_EXT_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|..........:................................:.................................|
| SMT      :                                :                                 |
|Unattached: PRO_E_STD_SMT_THICKNESS        : Non-relevant for non first wall.|
| Wall     :                                : DOUBLE  >= 0.0                  |
|          : PRO_E_STD_SMT_SWAP_DRV_SIDE    : PRO_B_TRUE, PRO_B_FALSE         |
|          :                                :                                 |
|          : PRO_E_SMT_WALL_SHARPS_TO_BENDS : PRO_B_TRUE, PRO_B_FALSE         |
|          :                                :                                 |
|          : PRO_E_SMT_FILLETS_SIDE         : ProSmdRadType                   |
|          :                                :                                 |
|          : PRO_E_SMT_FILLETS_VALUE        : DOUBLE                          |
|          :                                :                                 |
|          : PRO_E_SMT_DEV_LEN_SOURCE       : see :ProDvlLenSrcType           |
|          :                                :                                 |
|          : PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE: see :ProDvlLenFactor            |
|          :                                :                                 |
|          : PRO_E_SMT_DEV_LEN_BEND_TABLE   : int (bend table ID)             |
|          :                                :                                 |
|          : PRO_E_SMT_MERGE_AUTO           : PRO_B_TRUE, PRO_B_FALSE         |
|          :                                :                                 |
|          : PRO_E_SMT_MERGE_KEEP_LINES     : PRO_B_TRUE, PRO_B_FALSE         |
|..........:................................:.................................|


-----------------------------------------------------------------------------------
Table Extrude:4.3 : Which subelements of Depth compound element are valid
                     and when? 
-----------------------------------------------------------------------------------
|          | Element Id                      | Comment                            |
-----------------------------------------------------------------------------------
| Depth    :                                 :                                    |
| Elements :......................................................................|
|          : PRO_E_STD_EXT_DEPTH             : Depth compound Element             |
|          :                                 :....................................|
|          : PRO_E_EXT_DEPTH_TO              : Info of First Side depth in UI     |
|          :                                 : ( compound element )               |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_TO_TYPE         : of type ProExtDepthToType          |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_TO_VALUE        : Variable depth double value >= 0.0 |
|          :                                 : when PRO_E_EXT_DEPTH_TO_TYPE       |
|          :                                 :      == PRO_EXT_DEPTH_TO_BLIND   OR|
|          :                                 :      == PRO_EXT_DEPTH_SYMMETRIC    |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_TO_REF          : Stores the upto reference          |
|          :                                 : when PRO_E_EXT_DEPTH_TO_TYPE       |
|          :                                 :  == PRO_EXT_DEPTH_TO_REF       OR  |
|          :                                 :  == PRO_EXT_DEPTH_TO_UNTIL         |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_TO_REF_TRF      : of type ProExtDepthRefOpt          |
|          :                                 : when PRO_E_EXT_DEPTH_TO_TYPE       |
|          :                                 :  == PRO_EXT_DEPTH_TO_REF           |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_TO_REF_TRF_VAL  : Offset/translation double value    |
|          :                                 : when PRO_E_EXT_DEPTH_TO_REF_TRF    |
|          :                                 :  != PRO_EXT_DEPTH_REF_NONE         |
|          :                                 :                                    |
|          :                                 :....................................|
|          : PRO_E_EXT_DEPTH_FROM            : Info of Second Side depth in UI    |
|          :                                 : ( Compound Element  )              |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_FROM_TYPE       : of ProExtDepthFromType             |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_FROM_VALUE      : Variable depth double value >= 0.0 |
|          :                                 : when PRO_E_EXT_DEPTH_FROM_TYPE     |
|          :                                 :      == PRO_EXT_DEPTH_FROM_BLIND   |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_FROM_REF        : stores the upto reference          |
|          :                                 : when PRO_E_EXT_DEPTH_FROM_TYPE     |
|          :                                 :  == PRO_EXT_DEPTH_FROM_REF     OR  |
|          :                                 :  == PRO_EXT_DEPTH_FROM_UNTIL       |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_FROM_REF_TRF    : of type ProExtDepthRefOpt          |
|          :                                 : when PRO_E_EXT_DEPTH_FROM_TYPE     |
|          :                                 :  == PRO_EXT_DEPTH_FROM_REF         |
|          :                                 :                                    |
|          : PRO_E_EXT_DEPTH_FROM_REF_TRF_VAL: Offset/translation double value    |
|          :                                 : when PRO_E_EXT_DEPTH_FROM_REF_TRF  |
|          :                                 :  != PRO_EXT_DEPTH_REF_NONE         |
|          :                                 :                                    |
|..........:.................................:....................................|

-------------------------------------------------------------------------------
Table Extrude:4.4 :  Values of Specific Elements for each feature
-------------------------------------------------------------------------------
|          | Element Id                     | Value                           |
-------------------------------------------------------------------------------
| Solid    :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_ADD            |
|..........:................................:.................................|
| Thin     :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_THIN          |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_ADD            |
|..........:................................:.................................|
| Solid Cut:                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_REMOVE         |
|..........:................................:.................................|
| Thin Cut :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_THIN          |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_REMOVE         |
|..........:................................:.................................|
| Surface  :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SURFACE       |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_ADD            |
|..........:................................:.................................|
| Surface  :                                :                                 |
| Trim     : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SURFACE       |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_REMOVE         |
|..........:................................:.................................|
| Thin     :                                :                                 |
| Surface  : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SURFACE       |
| Trim     : PRO_E_FEAT_FORM_IS_THIN        : PRO_EXT_FEAT_FORM_THIN          |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_REMOVE         |
|..........:................................:.................................|
| SMT      :                                :                                 |
|Unattached: PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SOLID         |
| Wall     : PRO_E_FEAT_FORM_IS_THIN        : Non-relevant                    |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_ADD            |
|..........:................................:.................................|


-------------------------------------------------------------------------------
Table Extrude:4.5 :  Non SMT Extrude Vs. Sheet Metal Extrude (Unattached Wall)|
------------------------------------------------------------------------------
| Elements that are common to both features                                   |
|-----------------------------------------------------------------------------|
| PRO_E_STD_FEATURE_NAME                                                      |
| PRO_E_EXT_SURF_CUT_SOLID_TYPE                                               |
| PRO_E_REMOVE_MATERIAL                                                       |
| PRO_E_FEATURE_FORM                                                          |
| PRO_E_STD_SECTION                                                           |
| PRO_E_STD_MATRLSIDE                                                         |
| PRO_E_STD_DIRECTION                                                         |
| PRO_E_STD_EXT_DEPTH                                                         |
|.............................................................................|
| Extrude specific                      | Wall specific                       |
|-----------------------------------------------------------------------------|
|.......................................:.....................................|
| PRO_E_IS_SMT_CUT                      :  PRO_E_STD_SMT_THICKNESS            |
| PRO_E_SMT_CUT_NORMAL_DIR              :  PRO_E_STD_SMT_SWAP_DRV_SIDE        |
| PRO_E_FEAT_FORM_IS_THIN               :  PRO_E_SMT_WALL_SHARPS_TO_BENDS     |
| PRO_E_THICKNESS                       :  PRO_E_SMT_FILLETS                  |
| PRO_E_SRF_END_ATTRIBUTES              :  PRO_E_SMT_DEV_LEN_CALCULATION      |
| PRO_E_TRIM_QLT_SIDE                   :  PRO_E_SMT_MERGE_DATA               |
| PRO_E_TRIM_QUILT                      :                                     |
| PRO_E_EXT_COMP_DRFT_ANG               :                                     |
| PRO_E_FEAT_THIN                       :                                     |
|.......................................:.....................................|


5  Feature element tree for first feat:
=======================================
 
   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_FEATURE_FORM
     |   
     |--PRO_E_SKETCHER                ( Section )
     |   
     |--PRO_E_FEAT_FORM_IS_THIN       ( Feature Form )
     |   
     |--PRO_E_STD_MATRLSIDE           ( Material Side )
     |   
     |--PRO_E_THICKNESS               ( Thickness )
     |   
     |--PRO_E_STD_EXT_DEPTH
     |    |
     |    |--PRO_E_EXT_DEPTH_FROM
     |         |--PRO_E_EXT_DEPTH_FROM_TYPE
     |         |--PRO_E_EXT_DEPTH_FROM_VALUE
   
-----------------------------------------------------------------------------
Table 5.1 : Common element for all First feat Extrusions and it's value
-----------------------------------------------------------------------------
| Element Id                  | Value                                  | 
---------------------------------------------------------------------
| PRO_E_FEATURE_FORM          | Feature Form                           | 
|                             | Valid Value : PRO_EXTRUDE              | 
|.............................|........................................|
| PRO_E_FEATURE_TYPE          | Feature type                           | 
|                             | Valid Value : PRO_FEAT_FIRST_FEAT      | 
|.............................|........................................|
| PRO_E_SKETCHER              | 2D section.  Must be closed for solid  | 
|                             | first features.i.e ProExtFeatForm ==   | 
|                             | PRO_EXT_FEAT_FORM_NO_THIN.             | 
|.............................|........................................|
| PRO_E_FEAT_FORM_IS_THIN     | Feature Form                           | 
|                             | Of type ProExtFeatForm                 | 
|                             | = PRO_EXT_FEAT_FORM_NO_THIN            | 
|                             |        for Solid feature               | 
|                             | = PRO_EXT_FEAT_FORM_THIN               | 
|                             |        for Thin feature                | 
|.............................|........................................|
| PRO_E_STD_EXT_DEPTH         | Compound Element                       | 
|                             |                                        |
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM        | Compound Element                       | 
|                             |                                        |
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM_TYPE   | Mandatory                              | 
|                             | = PRO_EXT_DEPTH_FROM_BLIND             | 
|.............................|........................................|
| PRO_E_EXT_DEPTH_FROM_VALUE  | Of type  PRO_VALUE_TYPE_DOUBLE         |
|.............................|........................................|
| PRO_E_STD_FEATURE_NAME      | Default given by application depending |
|                             | on feature type.Can be modified by user|
|.............................|........................................|



-----------------------------------------------------------------------------
Table Extrude:5.2 : Elements required for each First feature in addition to
                    those mentioned above.
-----------------------------------------------------------------------------
|          | Element Id                     | Comment                         |
------------------------------------------------------------------------------
| Solid    :                                : No Additional Elements Required |
|..........:................................:.................................|
| Thin     :                                :                                 |
|          : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProExtMatlSide          |
|          :                                : Dependent on PRO_E_SKETCHER     |
|          :                                : See Note 6 for details.         |
|          :                                :                                 |
|          : PRO_E_THICKNESS                : Mandatory   >= 0.0              |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          :                                : Dependent on PRO_E_SKETCHER     |
|          :                                : See Note 6 for details.         |
|..........:................................:.................................|

\*****************************************************************************/
/*****************************************************************************/


/* 1. PRO_E_EXT_DEPTH_FROM_TYPE */ 

typedef enum pro_ext_depth_from_type
{
   PRO_EXT_DEPTH_FROM_BLIND    = (1 << 7),
   PRO_EXT_DEPTH_FROM_NEXT     = (1 << 8),
   PRO_EXT_DEPTH_FROM_ALL      = (1 << 9),
   PRO_EXT_DEPTH_FROM_UNTIL    = (1 << 10),
   PRO_EXT_DEPTH_FROM_REF      = (1 << 11),
   PRO_EXT_DEPTH_FROM_NONE     = (1 << 12)
} ProExtDepthFromType;

/* 2. PRO_E_EXT_DEPTH_TO_TYPE */

typedef enum pro_depth_to_type
{
   PRO_EXT_DEPTH_TO_BLIND    = (1 << 18),
   PRO_EXT_DEPTH_TO_NEXT     = (1 << 19),
   PRO_EXT_DEPTH_TO_ALL      = (1 << 20),
   PRO_EXT_DEPTH_TO_UNTIL    = (1 << 21),
   PRO_EXT_DEPTH_TO_REF      = (1 << 22),
   PRO_EXT_DEPTH_TO_NONE     = (1 << 23), /* Obsoleted. See Note Below*/
   PRO_EXT_DEPTH_SYMMETRIC   = (1 << 28)
} ProExtDepthToType;
/* PRO_EXT_DEPTH_TO_NONE should not be used as depth type. 
   Instead use PRO_EXT_DEPTH_FROM_NONE and proper PRO_E_STD_DIRECTION */

/* 3. PRO_E_TRIM_QLT_SIDE */

 typedef enum pro_ext_trimqlt_side 
 {
   PRO_EXT_TRIMQLT_SIDE_ONE         = -1,  /* Side 1 */ 
   PRO_EXT_TRIMQLT_SIDE_TWO         =  1   /* Side 2 */ 
 } ProExtTrimQltSide;


/* 4. PRO_E_STD_MATRLSIDE */

 typedef enum pro_ext_material_side
 {
   PRO_EXT_MATERIAL_SIDE_ONE        =  1,  /* Side 1      */ 
   PRO_EXT_MATERIAL_SIDE_TWO        =  2,  /* Side 2      */ 
   PRO_EXT_MATERIAL_BOTH_SIDES      =  3   /* Both sides  */ 
 } ProExtMatlSide;

/* Important : PRO_EXT_MATERIAL_BOTH_SIDES should be used with Thin and trim
               features only. */

/* 5. PRO_E_EXT_SURF_CUT_SOLID_TYPE */

 typedef enum pro_ext_feat_type 
 {
   PRO_EXT_FEAT_TYPE_SOLID          =  917, /* Solid Protrusion */
   PRO_EXT_FEAT_TYPE_SURFACE        =  942  /* Surface Protrusion */
 } ProExtFeatType;


/* 6. PRO_E_REMOVE_MATERIAL */

 typedef enum pro_ext_rem_material 
 {
   PRO_EXT_MATERIAL_ADD             = -1,   /* Solid protrusion */ 
   PRO_EXT_MATERIAL_REMOVE          =  916  /* Solid Cut protrusion */ 
 } ProExtRemMaterial;


/* 7. PRO_E_STD_DIRECTION */

 typedef enum pro_ext_direction 
 {
   PRO_EXT_CR_IN_SIDE_ONE           = -1, /* Protrusion in Side 1 */ 
   PRO_EXT_CR_IN_SIDE_TWO           =  1  /* Protrusion in Side 2 */ 
 } ProExtDirection;


/* 8. PRO_E_FEAT_FORM_IS_THIN */

 typedef enum pro_ext_feat_form 
 {
   PRO_EXT_FEAT_FORM_NO_THIN        =  0,  /* Solid protrusion */ 
   PRO_EXT_FEAT_FORM_THIN           =  128 /* Thin protrusion */ 
 } ProExtFeatForm;


/* 9. PRO_E_SRF_END_ATTRIBUTES */

 typedef enum pro_ext_surf_end_attr 
 {
   PRO_EXT_SURF_END_ATTR_OPEN       =  1, 
   PRO_EXT_SURF_END_ATTR_CAPPED     =  14 
 } ProExtSurfEndAttr;

/* 10. PRO_E_SMT_CUT_NORMAL_DIR */

 typedef enum pro_smt_cut_norm_dir 
 {
   PRO_SMT_CUT_DRVSIDE_GREEN        = 2,
   PRO_SMT_CUT_DRVSIDE_WHITE        = 3,
   PRO_SMT_CUT_DRVSIDE_BOTH         = 4 
 } ProSmtCutNormDir;


/* 11. PRO_E_SMT_PUNCH_TOOL_ATTR */

 typedef enum pro_punch_tool_attr 
 {
   PRO_PUNCH_TOOL_ATTR_SYM_NONE     = 0,  /* No symmetry                */
   PRO_PUNCH_TOOL_ATTR_SYM_X        = 1,  /* Symmetry around X axis     */
   PRO_PUNCH_TOOL_ATTR_SYM_Y        = 2,  /* Symmetry around Y axis     */
   PRO_PUNCH_TOOL_ATTR_SYM_XY       = 3   /* Symmetry around both X & Y */
 } ProPunchToolAttr;

/* 12. PRO_E_EXT_DRFT_ANG */

 
 typedef enum pro_ext_drft_ang
 {
   PRO_EXT_DRFT_ANG_NO_DRAFT        = -1,
   PRO_EXT_DRFT_ANG_DRAFT           = 80
 } ProExtDrftAng; 

/* 13. PRO_E_FEAT_THIN */

typedef enum pro_thin_opts
{
   PRO_FEAT_THIN_IGNORE           = -1, /* Ignore thin ending references */
   PRO_FEAT_THIN_DEFAULT          = 1  /* Use Default Algorithm */
} ProFeatThinOpt;

/* 14. PRO_E_EXT_DEPTH_FROM/TO_REF_TRF */
typedef enum pro_ext_depth_ref_opts
{
   PRO_EXT_DEPTH_REF_NONE      = -1, /* Use Depth Reference */
   PRO_EXT_DEPTH_REF_OFFS      = 90, /* Offset Depth Reference */
   PRO_EXT_DEPTH_REF_TRNSLT    = 95  /* Translate Depth Regerence */
} ProExtDepthRefOpt;


/*****************************************************************************/
/*****************************************************************************\
 
   Note 1.   Depth reference types:
 
   Depth Type              Valid Reference Types
   ---------------------------------------------------------------------
   PRO_EXT_DEPTH_FROM_REF       PRO_SURFACE, PRO_AXIS, PRO_EDGE, PRO_CURVE,
                                PRO_POINT, PRO_EDGE_START, PRO_EDGE_END, 
                                PRO_CRV_START, PRO_CRV_END

   PRO_EXT_DEPTH_TO_REF         PRO_SURFACE, PRO_AXIS, PRO_EDGE, PRO_CURVE,
                                PRO_POINT, PRO_EDGE_START, PRO_EDGE_END, 
                                PRO_CRV_START, PRO_CRV_END

   Note 2.  Extrude  with symetric depth option

            Following elements needs to be set:
            PRO_E_EXT_DEPTH_FROM_TYPE  -> PRO_EXT_DEPTH_FROM_NONE
            PRO_E_EXT_DEPTH_TO_TYPE    -> PRO_EXT_DEPTH_SYMMETRIC
            PRO_E_EXT_DEPTH_TO_VALUE   -> The symmetric depth double value.

            Other depth related elements are ignored.

   Note 3. Important: The elements PRO_E_STD_DIRECTION, PRO_E_STD_MATRLSIDE,
           PRO_E_TRIM_QLT_SIDE and PRO_E_SRF_END_ATTRIBUTES, are  directly
           dependent upon the presence of a fully defined PRO_E_STD_SECTION
           element tree (including PRO_E_SKETCHER).  
           Values assigned to these elements before fully defining the 
           PRO_E_STD_SECTION will be ignored.


   Note 4. Depth Type values valid for Surface feature are as below.

           ProExtDepthFromType:
             PRO_EXT_DEPTH_FROM_BLIND  
             PRO_EXT_DEPTH_FROM_REF   
             PRO_EXT_DEPTH_FROM_NONE 

           ProExtDepthToType:
             PRO_EXT_DEPTH_TO_BLIND 
             PRO_EXT_DEPTH_TO_REF  
             PRO_EXT_DEPTH_SYMMETRIC
          
   Note 5. Depth Type values valid for Surface Trim feature are as below.

           ProExtDepthFromType:
             PRO_EXT_DEPTH_FROM_BLIND  
             PRO_EXT_DEPTH_FROM_REF   
             PRO_EXT_DEPTH_FROM_NONE 
             PRO_EXT_DEPTH_FROM_ALL 

           ProExtDepthToType:
             PRO_EXT_DEPTH_TO_BLIND 
             PRO_EXT_DEPTH_TO_REF  
             PRO_EXT_DEPTH_SYMMETRIC
             PRO_EXT_DEPTH_TO_ALL

   Note 6. Important: In First feature, the elements PRO_E_STD_MATRLSIDE
           and PRO_E_THICKNESS, are  directly dependent upon the presence
           of a defined PRO_E_SKETCHER element.
           Values assigned to these elements before fully defining the 
           PRO_E_SKETCHER will be ignored.

\*****************************************************************************/
/*========= OLD IMPLEMENTATION prior to Pro/E Wildfire 1.0 ==================*/
/*****************************************************************************\

Feature element tree
 
   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_FEATURE_FORM
     |
     |--PRO_E_ATTRIBUTES
     |    |--PRO_E_ATTR_SRF_END_COND
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_STD_EXT_DEPTH 
     |    |--PRO_E_EXT_DEPTH_FROM
     |         |--PRO_E_EXT_DEPTH_FROM_TYPE
     |         |--PRO_E_EXT_DEPTH_FROM_REF   If Type = Reference
     |         |--PRO_E_EXT_DEPTH_FROM_VALUE If Type = Blind
     |
     |    |--PRO_E_EXT_DEPTH_TO
     |         |--PRO_E_EXT_DEPTH_TO_TYPE
     |         |--PRO_E_EXT_DEPTH_TO_REF     If Type = Reference
     |         |--PRO_E_EXT_DEPTH_TO_VALUE    If Type = Blind
     |

3. Feature elements table
 
--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type             Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_PROTRUSION
                                                                       PRO_FEAT_FIRST_FEAT,
                                                                       PRO_FEAT_CUT,
                                                                       PRO_FEAT_SLOT
PRO_E_FEATURE_FORM             Feature Form   PRO_VALUE_TYPE_INT       PRO_EXTRUDE
PRO_E_ATTRIBUTES               Attributes     Compound
PRO_E_ATTR_SRF_END_COND        EndCond        PRO_VALUE_TYPE_INT       ProSrfEndCond
PRO_E_STD_SECTION              Section        Compound
PRO_E_STD_EXT_DEPTH            Depth          Compound
PRO_E_EXT_DEPTH_FROM           Depth From     Compound
PRO_E_EXT_DEPTH_FROM_TYPE      Type           PRO_VALUE_TYPE_INT       ProExtDepthFromType
PRO_E_EXT_DEPTH_FROM_REF       References     PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_EXT_DEPTH_FROM_VALUE     Value          PRO_VALUE_TYPE_DOUBLE    >= 0.0
PRO_E_EXT_DEPTH_TO             Depth To       Compound
PRO_E_EXT_DEPTH_TO_TYPE        Type           PRO_VALUE_TYPE_INT       ProExtDepthToType
PRO_E_EXT_DEPTH_TO_REF         References     PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_EXT_DEPTH_TO_VALUE       Value          PRO_VALUE_TYPE_DOUBLE    >= 0.0
--------------------------------------------------------------------------------------------
 
\*****************************************************************************/
PRO_END_C_DECLS
 
#endif

