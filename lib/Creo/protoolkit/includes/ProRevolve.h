#ifndef PROREVOLVEH
#define PROREVOLVEH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************\

1  Summary of Element Tree Changes as compared to pre- Pro/E Wildfire releases :
====================================================
     The Element tree for Revolve has been updated to incorporate
 the following feature creation using the same element tree.

 1]  Solid Protrusion
 2]  Thin Protrusion
 3]  Solid Cut
 4]  Thin Cut
 5]  Surface
 6]  Surface Trim
 7]  Thin Surface Trim
 8]  Solid Protrusion as First Feature
 9]  Thin Protrusion as First Feature
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
     |--PRO_E_FEATURE_FORM
     |   
     |--PRO_E_STD_SECTION             ( Sketch )
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
     |--PRO_E_REVOLVE_AXIS 
     |   
     |--PRO_E_REVOLVE_AXIS_OPT 
     |   
     |--PRO_E_REV_ANGLE
     |    |
     |    |--PRO_E_REV_ANGLE_FROM
     |         |--PRO_E_REV_ANGLE_FROM_TYPE
     |         |--PRO_E_REV_ANGLE_FROM_REF
     |         |--PRO_E_REV_ANGLE_FROM_VAL
     |    |
     |    |--PRO_E_REV_ANGLE_TO
     |         |--PRO_E_REV_ANGLE_TO_TYPE
     |         |--PRO_E_REV_ANGLE_TO_REF
     |         |--PRO_E_REV_ANGLE_TO_VAL
     |
     |--PRO_E_STD_SMT_THICKNESS  ( applicable only in sheetmetal parts )
     |
     |--PRO_E_STD_SMT_SWAP_DRV_SIDE  ( applicable only in sheetmetal parts )
     |
     |--PRO_E_SMT_WALL_SHARPS_TO_BENDS  ( applicable only in sheetmetal parts )
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
     |--PRO_E_SMT_MERGE_DATA ( applicable only in sheetmetal parts )
     |    |
     |    |--PRO_E_SMT_MERGE_AUTO
     |    |
     |    |--PRO_E_SMT_MERGE_KEEP_LINES
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
Element Id                     Element Name        Data Type             
------------------------------------------------------------------------------
PRO_E_STD_FEATURE_NAME           Feature Name        PRO_VALUE_TYPE_WSTRING
PRO_E_EXT_SURF_CUT_SOLID_TYPE    Feature Type        PRO_VALUE_TYPE_INT   
PRO_E_REMOVE_MATERIAL            Material            PRO_VALUE_TYPE_INT
PRO_E_FEATURE_FORM               Feature Form        PRO_VALUE_TYPE_INT
PRO_E_STD_SECTION                Section             Compound 
PRO_E_FEAT_FORM_IS_THIN          Feature Form        PRO_VALUE_TYPE_INT      
PRO_E_STD_MATRLSIDE              Material Side       PRO_VALUE_TYPE_INT 
PRO_E_THICKNESS                  Thin width          PRO_VALUE_TYPE_DOUBLE
PRO_E_SRF_END_ATTRIBUTES         End Cap             PRO_VALUE_TYPE_INT
PRO_E_TRIM_QLT_SIDE              Quilt Side          PRO_VALUE_TYPE_INT
PRO_E_TRIM_QUILT                 Trim Quilt          PRO_VALUE_TYPE_SELECTION 
PRO_E_STD_DIRECTION              Direction           PRO_VALUE_TYPE_INT
PRO_E_REVOLVE_AXIS               Revolve Axis        PRO_VALUE_TYPE_SELECTION
PRO_E_REVOLVE_AXIS_OPT           Axis Type           PRO_VALUE_TYPE_INT
PRO_E_REV_ANGLE                  Angle               Compound
PRO_E_REV_ANGLE_FROM             Angle From          Compound
PRO_E_REV_ANGLE_FROM_TYPE        Type                PRO_VALUE_TYPE_INT
PRO_E_REV_ANGLE_FROM_REF         References          PRO_VALUE_TYPE_SELECTION
PRO_E_REV_ANGLE_FROM_VAL         Value               PRO_VALUE_TYPE_DOUBLE
PRO_E_REV_ANGLE_TO               Angle To            Compound
PRO_E_REV_ANGLE_TO_TYPE          Type                PRO_VALUE_TYPE_INT
PRO_E_REV_ANGLE_TO_REF           References          PRO_VALUE_TYPE_SELECTION
PRO_E_REV_ANGLE_TO_VAL           Value               PRO_VALUE_TYPE_DOUBLE
PRO_E_INT_PARTS                  Intsct Parts        Compound
PRO_E_PATTERN                    Pattern             Compound
PRO_E_STD_SMT_THICKNESS          Smt Thickness       PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_SMT_SWAP_DRV_SIDE      Smt Swap Side       PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_SHARPS_TO_BENDS   Edges to Bends      PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS                Smt Fillets         Compound
PRO_E_SMT_FILLETS_SIDE           Smt Radius Side     PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE          Smt Radius Value    PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_CALCULATION    Smt Develop Length  Compound
PRO_E_SMT_DEV_LEN_SOURCE         Smt Dev Len Source  PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_Y_FACTOR       Smt Dev Len Y Fact  Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE Y Factor Value      PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE  Y Factor Type       PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_BEND_TABLE     Smt Dev Bend Table  PRO_VALUE_TYPE_INT
PRO_E_SMT_MERGE_DATA             Smt Merge Wall Data Compound
PRO_E_SMT_MERGE_AUTO             Auto Merge Wall     PRO_VALUE_INT
PRO_E_SMT_MERGE_KEEP_LINES       Keep Merged Lines   PRO_VALUE_INT
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
PRO_E_REVOLVE_AXIS 
PRO_E_REVOLVE_AXIS_OPT

-----------------------------------------------------------------------------
\*****************************************************************************/
/*****************************************************************************\
The Elements mentioned in the table below are for Solid Protrusion.
For other features, additional elements required, are mentioned below in
table 4.2.
-----------------------------------------------------------------------------
Table 4.1 : Common elements for all type of Revolve and their values
-----------------------------------------------------------------------------
| Element Id                  | Value                                  |
---------------------------------------------------------------------
|PRO_E_EXT_SURF_CUT_SOLID_TYPE| Mandatory                              |
|                             | Of type ProRevFeatType                 |
|                             | = PRO_REV_FEAT_TYPE_SOLID              |
|                             |        for Solid feat type             |
|                             | = PRO_REV_FEAT_TYPE_SURFACE            |
|                             |        for Surface feat type           |
|.............................|........................................|
| PRO_E_REMOVE_MATERIAL       | Material Removal                       |
|                             | Of type ProRevRemMaterial              |
|                             | = PRO_REV_MATERIAL_ADD                 |
|                             |        for Protruded feature           |
|                             | = PRO_REV_MATERIAL_REMOVE              |
|                             |        for Cut feature                 |
|.............................|........................................|
| PRO_E_FEATURE_FORM          | Feature Form                           | 
|                             | Valid Value : PRO_REVOLVE              | 
|.............................|........................................|
| PRO_E_STD_SECTION           | For more details refer ProStdSection.h |
|.............................|........................................|
| PRO_E_STD_DIRECTION         | Direction of creation.                 |
|			      | Depends on PRO_E_STD_SECTION	       |
|			      | See note 3 for details .
|                             | Of type ProRevDirection                |
|                             | = PRO_REV_CR_IN_SIDE_ONE               |
|                             |        for angle in side one           |
|                             | = PRO_REV_CR_IN_SIDE_TWO               |
|                             |        for angle in side two           |
|.............................|........................................|
| PRO_E_STD_MATRLSIDE	      | Required if open section and if	       |
| 			      | ProRevFeatType is 		       |
|			      | PRO_REV_FEAT_TYPE_SOLID		       |
|			      | Depends on PRO_E_STD_SECTION	       |
|			      | See note 3 for details		       |
|			      | Of type ProRevMatlSide		       |
|.............................|........................................|  
| PRO_E_REVOLVE_AXIS          | Optional                               |
|                             | Depends on ProRevAxisOptAttr           |
|                             | External Axis reference should be      |
|                             | specified if ProRevAxisOptAttr is set  |
|                             | to PRO_REV_AXIS_EXT_REF                |
|                             | Axis reference may be of the type      |
|                             | Axis, Straight Edge, Straight Curve,   |
|                             | Coordinate system axis                 |
|.............................|........................................|
| PRO_E_REVOLVE_AXIS_OPT      | Optional                               |
|                             | Of type ProRevAxisOptAttr              |
|.............................|........................................|
| PRO_E_REV_ANGLE             | Compound Element                       |
|                             |                                        |
|.............................|........................................|
| PRO_E_REV_ANGLE_TO          | Compound Element                       |
|                             |                                        |
|.............................|........................................|
| PRO_E_REV_ANGLE_TO_TYPE     | Mandatory                              |
|                             | Of type ProRevAngleToType              |
|.............................|........................................|
| PRO_E_REV_ANGLE_TO_VAL      | Depends on PRO_E_REV_ANGLE_TO_TYPE     |
|                             | Of type  PRO_VALUE_TYPE_DOUBLE         |
|.............................|........................................|
| PRO_E_REV_ANGLE_TO_REF      | Depends on PRO_E_REV_ANGLE_TO_TYPE     |
|                             | Of type  See Note 1.                   |
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM        | Compound Element                       |
|                             |                                        |
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM_TYPE   | Mandatory                              |
|                             | Of type ProRevAngleFromType            |
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM_VAL    | Depends on PRO_E_REV_ANGLE_FROM_TYPE   |
|                             | Of type  PRO_VALUE_TYPE_DOUBLE         |
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM_REF    | Depends on PRO_E_REV_ANGLE_FROM_TYPE   |
|                             | Of type   See Note 1.                  |
|.............................|........................................|
| PRO_E_STD_FEATURE_NAME      | Default given by application depending |
|                             | on feature type.Can be modified by user|
|.............................|........................................|

-----------------------------------------------------------------------------
Table Revolve:4.2 : Elements required for each feature in addition to 
                     those mentioned above. 
-----------------------------------------------------------------------------
|          | Element Id                     | Comment                         |
------------------------------------------------------------------------------
| Solid    :                                : No Additional Elements Required |
|..........:................................:.................................|
| Thin     :                                :                                 |
|	   : PRO_E_STD_MATRLSIDE	    : Mandatory			      |
|	   : 				    : Of type ProRevMatlSide	      |
|          : PRO_E_THICKNESS                : Mandatory   >= 0.0              |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProRevFeatForm          |
|          :                                : = PRO_REV_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_REV_FEAT_FORM_THIN        |
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
|          :                                : Of type ProRevMatlSide          |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProRevFeatForm          |
|          :                                : = PRO_REV_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_REV_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|..........:................................:.................................|
| Thin Cut :                                :                                 |
|          : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProRevMatlSide          |
|          : PRO_E_THICKNESS                : Mandatory  >= 0.0               |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProRevFeatForm          |
|          :                                : = PRO_REV_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_REV_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|          :                                :                                 |
|          : PRO_E_FEAT_THIN                : Compound Element                |
|          :                                : See: Table Revolve:4.2, Thin    |
|..........:................................:.................................|
| Surface  :                                :                                 |
|          : PRO_E_SRF_END_ATTRIBUTES       :                                 |
|          :                                : Of type ProRevSurfEndAttr       |
|          :                                : Depends on PRO_E_STD_SECTION    |
|          :                                : See Note 3 for details.         |
|          :                                : Required only for closed section|
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProRevFeatForm          |
|          :                                : = PRO_REV_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_REV_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|..........:................................:.................................|
| Surface  :                                :                                 |
| Trim     : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProRevMatlSide          |
|          : PRO_E_TRIM_QUILT               : Mandatory                       |
|          :                                : Of type Quilt.                  |
|          : PRO_E_TRIM_QLT_SIDE            :                                 |
|          :                                : Of type ProRevTrimQltSide       |
|          :                                : Depends on PRO_E_STD_MATRLSIDE  |
|          :                                : See Note 3 for details.         |
|          :                                : Required only if ProRevMatlSide |
|          :                                :  is PRO_REV_MATERIAL_BOTH_SIDES |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProRevFeatForm          |
|          :                                : = PRO_REV_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_REV_FEAT_FORM_THIN        |
|          :                                : for Thin feature                |
|..........:................................:.................................|
| Thin     :                                :                                 |
| Surface  : PRO_E_STD_MATRLSIDE            : Mandatory                       |
| Trim     :                                : Of type ProRevMatlSide          |
|          : PRO_E_THICKNESS                : Mandatory    >= 0.0             |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          : PRO_E_TRIM_QUILT               : Mandatory                       |
|          :                                : Of type Quilt.                  |
|          : PRO_E_TRIM_QLT_SIDE            :                                 |
|          :                                : Of type ProRevTrimQltSide       |
|          :                                : Depends on PRO_E_STD_MATRLSIDE  |
|          :                                : See Note 3 for details.         |
|          :                                : Required only if ProRevMatlSide |
|          :                                :  is PRO_REV_MATERIAL_BOTH_SIDES |
|          :                                :                                 |
|          : PRO_E_FEAT_FORM_IS_THIN        : Of type ProRevFeatForm          |
|          :                                : = PRO_REV_FEAT_FORM_NO_THIN     |
|          :                                : for feature not having Thin     |
|          :                                : = PRO_REV_FEAT_FORM_THIN        |
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


------------------------------------------------------------------------------
Table Revolve:4.3 : Which subelements of Angle compound element are valid
                     and when? 
------------------------------------------------------------------------------
|          | Element Id                 | Comment                            |
------------------------------------------------------------------------------
| Angle    :                            :                                    |
| Elements :.................................................................|
|          : PRO_E_REV_ANGLE            : Angle compound Element             |
|          :                            :....................................|
|          : PRO_E_REV_ANGLE_TO         : Info of First side angle in UI     |
|          :                            : ( compound element )               |
|          :                            :                                    |
|          : PRO_E_REV_ANGLE_TO_TYPE    : of type ProRevAngleToType          |
|          :                            :                                    |
|          : PRO_E_REV_ANGLE_TO_VAL     : Variable angle double value >= 0.0 |
|          :                            : when PRO_E_REV_ANGLE_TO_TYPE       |
|          :                            :      == PRO_REV_ANG_TO_ANGLE     OR|
|          :                            :      == PRO_REV_ANG_SYMMETRIC      |
|          :                            :                                    |
|          : PRO_E_REV_ANGLE_TO_REF     : Stores the upto reference          |
|          :                            : when PRO_E_REV_ANGLE_TO_TYPE       |
|          :                            :  == PRO_REV_ANG_TO_REF             |
|          :                            :....................................|
|          : PRO_E_REV_ANGLE_FROM       : Info of Second side angle in UI    |
|          :                            : ( Compound Element  )              |
|          :                            :                                    |
|          : PRO_E_REV_ANGLE_FROM_TYPE  : of ProRevAngleFromType             |
|          :                            :                                    |
|          : PRO_E_REV_ANGLE_FROM_VAL   : Stores Variable angle double value |
|          :                            : when PRO_E_REV_ANGLE_FROM_TYPE     |
|          :                            :      == PRO_REV_ANG_FROM_ANGLE     |
|          :                            :                                    |
|          : PRO_E_REV_ANGLE_FROM_REF   : stores the upto reference          |
|          :                            : when PRO_E_REV_ANGLE_FROM_TYPE     |
|          :                            :  == PRO_REV_ANG_FROM_REF           |
|..........:............................:....................................|

-------------------------------------------------------------------------------
Table Revolve:4.4 :  Values of Specific Elements for each feature
-------------------------------------------------------------------------------
|          | Element Id                     | Value                           |
-------------------------------------------------------------------------------
| Solid    :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_ADD            |
|..........:................................:.................................|
| Thin     :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_THIN          |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_ADD            |
|..........:................................:.................................|
| Solid Cut:                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_REMOVE         |
|..........:................................:.................................|
| Thin Cut :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SOLID         |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_THIN          |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_REMOVE         |
|..........:................................:.................................|
| Surface  :                                :                                 |
|          : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SURFACE       |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_ADD            |
|..........:................................:.................................|
| Surface  :                                :                                 |
| Trim     : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SURFACE       |
|          : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_NO_THIN       |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_REMOVE         |
|..........:................................:.................................|
| Thin     :                                :                                 |
| Surface  : PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_REV_FEAT_TYPE_SURFACE       |
| Trim     : PRO_E_FEAT_FORM_IS_THIN        : PRO_REV_FEAT_FORM_THIN          |
|          : PRO_E_REMOVE_MATERIAL          : PRO_REV_MATERIAL_REMOVE         |
|..........:................................:.................................|
| SMT      :                                :                                 |
|Unattached: PRO_E_EXT_SURF_CUT_SOLID_TYPE  : PRO_EXT_FEAT_TYPE_SOLID         |
| Wall     : PRO_E_FEAT_FORM_IS_THIN        : Non-relevant                    |
|          : PRO_E_REMOVE_MATERIAL          : PRO_EXT_MATERIAL_ADD            |
|..........:................................:.................................|


-------------------------------------------------------------------------------
Table Revolve:4.5 :  Non SMT Revolve Vs. Sheet Metal Revolve (Unattached Wall)|
-------------------------------------------------------------------------------
| Elements that are common to both features                                   |
|-----------------------------------------------------------------------------|
| PRO_E_STD_FEATURE_NAME                                                      |
| PRO_E_EXT_SURF_CUT_SOLID_TYPE                                               |
| PRO_E_REMOVE_MATERIAL                                                       |
| PRO_E_FEATURE_FORM                                                          |
| PRO_E_STD_SECTION                                                           |
| PRO_E_STD_MATRLSIDE                                                         |
| PRO_E_STD_DIRECTION                                                         |
| PRO_E_REVOLVE_AXIS                                                          |
| PRO_E_REVOLVE_AXIS_OPT                                                      |
| PRO_E_REV_ANGLE                                                             |
|.............................................................................|
| Revolve specific                      | Wall specific                       |
|-----------------------------------------------------------------------------|
|.......................................:.....................................|
| PRO_E_FEAT_FORM_IS_THIN               : PRO_E_STD_SMT_THICKNESS             |
| PRO_E_THICKNESS                       : PRO_E_STD_SMT_SWAP_DRV_SIDE         |
| PRO_E_SRF_END_ATTRIBUTES              : PRO_E_SMT_WALL_SHARPS_TO_BENDS      |
| PRO_E_TRIM_QLT_SIDE                   : PRO_E_SMT_FILLETS                   |
| PRO_E_TRIM_QUILT                      : PRO_E_SMT_DEV_LEN_CALCULATION       |
|                                       : PRO_E_SMT_MERGE_DATA                |
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
     |--PRO_E_REV_ANGLE
     |    |
     |    |--PRO_E_REV_ANGLE_FROM
     |         |--PRO_E_REV_ANGLE_FROM_TYPE
     |         |--PRO_E_REV_ANGLE_FROM_VAL



-----------------------------------------------------------------------------
Table 5.1: Common elements for all First feat Revolve features and their values
-----------------------------------------------------------------------------
| Element Id                  | Value                                  | 
---------------------------------------------------------------------
| PRO_E_FEATURE_FORM          | Feature Form                           | 
|                             | Valid Value : PRO_REVOLVE              | 
|.............................|........................................|
| PRO_E_FEATURE_TYPE          | Feature type                           | 
|                             | Valid Value : PRO_FEAT_FIRST_FEAT      | 
|.............................|........................................|
| PRO_E_SKETCHER              | 2d Section. Must be closed for first   |
|                             | features.                              | 
|.............................|........................................|
| PRO_E_FEAT_FORM_IS_THIN     | Feature Form                           | 
|                             | Of type ProRevFeatForm                 | 
|                             | = PRO_REV_FEAT_FORM_NO_THIN            | 
|                             |        for Solid feature               | 
|                             | = PRO_REV_FEAT_FORM_THIN               | 
|                             |        for Thin feature                | 
|.............................|........................................|
| PRO_E_REV_ANGLE             | Compound Element                       | 
|                             |                                        |
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM        | Compound Element                       | 
|                             |                                        |
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM_TYPE   | Mandatory                              | 
|                             | = PRO_REV_ANG_FROM_ANGLE               | 
|.............................|........................................|
| PRO_E_REV_ANGLE_FROM_VAL    | Of type  PRO_VALUE_TYPE_DOUBLE         | 
|.............................|........................................|
| PRO_E_STD_FEATURE_NAME      | Default given by application depending |
|                             | on feature type.Can be modified by user|
|.............................|........................................|

-----------------------------------------------------------------------------
Table Revolve:5.2 : Elements required for each First feature in addition to
                    those mentioned above.
-----------------------------------------------------------------------------
|          | Element Id                     | Comment                         |
------------------------------------------------------------------------------
| Solid    :                                : No Additional Elements Required |
|..........:................................:.................................|
| Thin     :                                :                                 |
|          : PRO_E_STD_MATRLSIDE            : Mandatory                       |
|          :                                : Of type ProRevMatlSide          |
|          :                                : Dependent on PRO_E_SKETCHER     |
|          :                                : See Note 4 for details.         |
|          :                                :                                 |
|          : PRO_E_THICKNESS                : Mandatory   >= 0.0              |
|          :                                : Of type PRO_VALUE_TYPE_DOUBLE   |
|          :                                : Dependent on PRO_E_SKETCHER     |
|          :                                : See Note 4 for details.         |
|          :                                :                                 |
|..........:................................:.................................|

\*****************************************************************************/
/*****************************************************************************/

/* 1. PRO_E_REV_ANGLE_FROM_TYPE */

typedef enum pro_rev_angle_from_type
{
   PRO_REV_ANG_FROM_ANGLE    = (1<<12),
   PRO_REV_ANG_FROM_90       = (1<<13), /* Obsoleted */
   PRO_REV_ANG_FROM_180      = (1<<14), /* Obsoleted */
   PRO_REV_ANG_FROM_270      = (1<<15), /* Obsoleted */
   PRO_REV_ANG_FROM_360      = (1<<16), /* Obsoleted */
   PRO_REV_ANG_FROM_REF      = (1<<17),
   PRO_REV_ANG_FROM_NONE     = (1<<18)
} ProRevAngleFromType;

/* 2. PRO_E_REV_ANGLE_TO_TYPE */
typedef enum pro_rev_angle_to_type
{
   PRO_REV_ANG_TO_ANGLE    = (1<<22),
   PRO_REV_ANG_TO_90       = (1<<23), /* Obsoleted */
   PRO_REV_ANG_TO_180      = (1<<24), /* Obsoleted */
   PRO_REV_ANG_TO_270      = (1<<25), /* Obsoleted */
   PRO_REV_ANG_TO_REF      = (1<<27),
   PRO_REV_ANG_TO_NONE     = (1<<28), /* Obsoleted. See Note Below. */
   PRO_REV_ANG_SYMMETRIC   = (1<<29)
} ProRevAngleToType;
/* PRO_REV_ANG_TO_NONE should not be used as depth type.
   Instead use PRO_REV_ANG_FROM_NONE and proper PRO_E_STD_DIRECTION */

/* 3. PRO_E_TRIM_QLT_SIDE */

 typedef enum pro_rev_trimqlt_side 
 {
   PRO_REV_TRIMQLT_SIDE_ONE         = -1,  /* Side 1 */ 
   PRO_REV_TRIMQLT_SIDE_TWO         =  1   /* Side 2 */ 
 } ProRevTrimQltSide;


/* 4. PRO_E_STD_MATRLSIDE */

 typedef enum pro_rev_material_side
 {
   PRO_REV_MATERIAL_SIDE_ONE        =  1,  /* Side 1      */ 
   PRO_REV_MATERIAL_SIDE_TWO        =  2,  /* Side 2      */ 
   PRO_REV_MATERIAL_BOTH_SIDES      =  3   /* Both sides  */ 
 } ProRevMatlSide;

/* Important : PRO_REV_MATERIAL_BOTH_SIDES should be used with Thin and trim
               features only. */

/* 5. PRO_E_EXT_SURF_CUT_SOLID_TYPE */

 typedef enum pro_rev_feat_type 
 {
   PRO_REV_FEAT_TYPE_SOLID          =  917, /* Solid Protrusion */
   PRO_REV_FEAT_TYPE_SURFACE        =  942  /* Surface Protrusion */
 } ProRevFeatType;


/* 6. PRO_E_REMOVE_MATERIAL */

 typedef enum pro_rev_rem_material 
 {
   PRO_REV_MATERIAL_ADD             = -1,   /* Solid protrusion */ 
   PRO_REV_MATERIAL_REMOVE          =  916  /* Solid Cut protrusion */ 
 } ProRevRemMaterial;


/* 7. PRO_E_STD_DIRECTION */

 typedef enum pro_rev_direction 
 {
   PRO_REV_CR_IN_SIDE_ONE           = -1, /* Protrusion in Side 1 */ 
   PRO_REV_CR_IN_SIDE_TWO           =  1  /* Protrusion in Side 2 */ 
 } ProRevDirection;


/* 8. PRO_E_FEAT_FORM_IS_THIN */

 typedef enum pro_rev_feat_form 
 {
   PRO_REV_FEAT_FORM_NO_THIN        =  0,  /* Solid protrusion */ 
   PRO_REV_FEAT_FORM_THIN           =  128 /* Thin protrusion */ 
 } ProRevFeatForm;


/* 9. PRO_E_SRF_END_ATTRIBUTES */

 typedef enum pro_rev_surf_end_attr 
 {
   PRO_REV_SURF_END_ATTR_OPEN       =  1, 
   PRO_REV_SURF_END_ATTR_CAPPED     =  14 
 } ProRevSurfEndAttr;

/* 10. PRO_E_REVOLVE_AXIS_OPT */

 typedef enum pro_rev_axis_opt 
 {
   PRO_REV_AXIS_EXT_REF       =  -1, 
   PRO_REV_AXIS_INT_REF       =   1 
 } ProRevAxisOptAttr;


/*****************************************************************************/
/*****************************************************************************\
 
   Note 1.   Angle reference types:
 
   Angle Type                   Valid Reference Types
   ---------------------------------------------------------------------
   PRO_REV_ANGLE_FROM_REF  PRO_POINT, PRO_EDGE_START, PRO_EDGE_END,
                           PRO_CRV_START,PRO_CRV_END
                           PRO_SURFACE (Plane)

   PRO_REV_ANGLE_TO_REF    PRO_POINT, PRO_EDGE_START, PRO_EDGE_END,
                           PRO_CRV_START,PRO_CRV_END
                           PRO_SURFACE (Plane)
  
  IMPORTANT: For PRO_SURFACE type of ProSelection object using datum planes  
           For  PRO_SURFACE type of ProSelection object, when datum planes 
           passing through the revolve axis are selected,  since two possible 
           solutions will exist for creation, the direction will be decided 
           on the basis of the location from the ProSelection object.      
           Use ProSelectionPoint3dSet() for setting it programmatically.  

           The selection object has to pass through the revolve axis   


   Note 2.  Revolve  with symetric depth option 

            Following elements needs to be set:
            PRO_E_REV_ANGLE_FROM_TYPE  -> PRO_REV_ANG_FROM_NONE
            PRO_E_REV_ANGLE_TO_TYPE    -> PRO_REV_ANG_SYMMETRIC
            PRO_E_REV_ANGLE_TO_VAL     -> The symmetric angle double value.

            Other angle related elements are ignored.

   Note 3. Important: The elements PRO_E_STD_DIRECTION, PRO_E_STD_MATRLSIDE,
           PRO_E_TRIM_QLT_SIDE and PRO_E_SRF_END_ATTRIBUTES, are  directly
           dependent upon the presence of a fully defined PRO_E_STD_SECTION
           element tree (including PRO_E_SKETCHER).
           Values assigned to these elements before fully defining the
           PRO_E_STD_SECTION will be ignored.

   Note 4. Important: In First feature, the elements PRO_E_STD_MATRLSIDE
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
     |--PRO_E_REV_ANGLE
     |    |--PRO_E_REV_ANGLE_FROM
     |         |--PRO_E_REV_ANGLE_FROM_TYPE
     |         |--PRO_E_REV_ANGLE_FROM_VAL     If Type = Angle
     |         |--PRO_E_REV_ANGLE_FROM_REF     If Type = To Reference
     |         |--PRO_E_REV_ANGLE_FROM_LIMIT   If Reference = datum-plane.
     |
     |    |--PRO_E_REV_ANGLE_TO
     |         |--PRO_E_REV_ANGLE_TO_TYPE
     |         |--PRO_E_REV_ANGLE_TO_VAL     If Type = Angle
     |         |--PRO_E_REV_ANGLE_TO_REF     If Type = To Reference
     |         |--PRO_E_REV_ANGLE_TO_LIMIT   If Reference = datum-plane.
 

3. Feature elements table

--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type             Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_PROTRUSION
                                                                       PRO_FEAT_FIRST_FEAT,
                                                                       PRO_FEAT_CUT,
                                                                       PRO_FEAT_SLOT
PRO_E_FEATURE_FORM             Feature Form   PRO_VALUE_TYPE_INT       PRO_REVOLVE
PRO_E_ATTRIBUTES               Attributes     Compound
PRO_E_ATTR_SRF_END_COND        EndCond        PRO_VALUE_TYPE_INT       ProSrfEndCond
PRO_E_STD_SECTION              Section        Compound
PRO_E_REV_ANGLE                Angle          Compound
PRO_E_REV_ANGLE_FROM           Angle From     Compound
PRO_E_REV_ANGLE_TO             Angle To       Compound
PRO_E_REV_ANGLE_FROM_TYPE      Type           PRO_VALUE_TYPE_INT       ProRevAngleType
PRO_E_REV_ANGLE_TO_TYPE        Type           PRO_VALUE_TYPE_INT       ProRevAngleType
PRO_E_REV_ANGLE_FROM_REF       References     PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_REV_ANGLE_TO_REF         References     PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_REV_ANGLE_FROM_LIMIT     Type           PRO_VALUE_TYPE_INT       ProRevAngleLimit
PRO_E_REV_ANGLE_TO_LIMIT       Type           PRO_VALUE_TYPE_INT       ProRevAngleLimit
PRO_E_REV_ANGLE_FROM_VAL       Value          PRO_VALUE_TYPE_DOUBLE    >= 0.0
PRO_E_REV_ANGLE_TO_VAL         Value          PRO_VALUE_TYPE_DOUBLE    >= 0.0
--------------------------------------------------------------------------------------------
 
   Note 1. PRO_E_REV_ANGLE_FROM_LIMIT and PRO_E_REV_ANGLE_TO_LIMIT

             To determine the side of the datum plane to end the revolution.
             Called only if the Reference is a datum plane.


 
\*****************************************************************************/
/* 3. PRO_E_REV_ANGLE_FROM_LIMIT and PRO_E_REV_ANGLE_TO_LIMIT */

typedef enum pro_rev_angle_limit
{
   PRO_REV_ANG_LIMIT_SIDE1 =  1,
   PRO_REV_ANG_LIMIT_SIDE2 = -1
} ProRevAngleLimit;

PRO_END_C_DECLS
 
#endif

