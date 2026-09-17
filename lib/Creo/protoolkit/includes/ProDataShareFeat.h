#ifndef PRO_DATA_SHARE_FEAT_H
#define PRO_DATA_SHARE_FEAT_H



#include <ProToolkit.h>
#include <ProAsmcomp.h>
#include <ProDtmPln.h>
#include <ProDtmAxis.h>
#include <ProSrfcopyOpts.h>

PRO_BEGIN_C_DECLS
/*============================================================================*/
/* common Data Sharing declarations */
/*============================================================================*/

typedef enum Pro_Dsf_Ext_Local_Type
{
  PRO_DSF_PLACE_LOCAL,
  PRO_DSF_PLACE_EXTERNAL
} ProDsfExtLocalType;

/* WARNING: This is an old type, left for toolkit compatibility only.
   Please do not use it in new development */
typedef enum Pro_Dsf_Dependency
{
  PRO_DSF_DEPENDENT,
  PRO_DSF_INDEPENDENT
} ProDsfDependency;

typedef enum Pro_DSF_Dependency
{
  PRO_DSF_UPDATE_AUTOMATICALLY = PRO_DSF_DEPENDENT,
  PRO_DSF_UPDATE_MANUALLY = PRO_DSF_INDEPENDENT,
  PRO_DSF_NO_DEPENDENCY
} ProDSFDependency;

typedef enum Pro_Dsf_Annot_Dependency
{
  PRO_DSF_ANNOT_INDEPENDENT,
  PRO_DSF_ANNOT_DEPENDENT
} ProDsfAnnotDependency;

typedef enum Pro_Gcpy_Update_Control
{
  PRO_DSF_NOTIFY_UPDATE_OFF = 0,
  PRO_DSF_NOTIFY_UPDATE_ON = 1
} ProDsfNotifyUpdate;

typedef enum Pro_Dsf_Annot_Cpy_Status
{
  PRO_DSF_ANNOT_DONT_COPY,
  PRO_DSF_ANNOT_COPY
} ProDsfAnnotCpyStatus;


/*============================================================================*/
/* Gen Merge Declarations and tree*/
/*============================================================================*/
/* Types Declarations */

typedef enum Pro_Gen_Merge_Type
{
  PRO_GEN_MERGE_TYPE_MERGE,
  PRO_GEN_MERGE_TYPE_INHERITANCE
} ProGenMergeType;

typedef enum Pro_Gen_Merge_Material_Opt
{
  PRO_GEN_MERGE_RMV_MATERIAL,
  PRO_GEN_MERGE_ADD_MATERIAL,
  PRO_GEN_MERGE_INT_MATERIAL
} ProGenMergeMaterialOpt;

 /*============================================================================
  
 (1) Feature element tree

 PRO_E_FEATURE_TREE
 |
 |-PRO_E_FEATURE_TYPE
 |-PRO_E_STD_FEATURE_NAME
 |-PRO_E_GMRG_FEAT_TYPE
 |-PRO_E_DSF_REF_MDL
 |   |--PRO_E_DSF_EXT_LOCAL_TYPE
 |   |--PRO_E_DSF_SEL_REF_MDL
 |   |--PRO_E_DSF_PLACEMENT
 |       |--PRO_E_COMPONENT_CONSTRAINTS
 |           |--PRO_E_COMPONENT_CONSTRAINT
 |               |--PRO_E_COMPONENT_CONSTR_TYPE
 |               |--PRO_E_COMPONENT_COMP_CONSTR_REF
 |               |--PRO_E_COMPONENT_ASSEM_CONSTR_REF
 |               |--PRO_E_COMPONENT_CONSTR_REF_OFFSET (Mate/align offset)
 |               |--PRO_E_COMPONENT_USER_DATA
 |               |--PRO_E_COMPONENT_CONSTR_ATTR
 |               |--PRO_E_COMPONENT_COMP_ORIENT
 |               |--PRO_E_COMPONENT_ASSM_ORIENT
 |               |--PRO_E_COMPONENT_CONSTR_SET_ID
 |               |--PRO_E_COMPONENT_SLOT_EXTRA_CRV_REF
 |-PRO_E_GMRG_MATERIAL_OPT
 |-PRO_E_GMRG_VARIED_ITEMS
 |-PRO_E_GMRG_COPY_DATUMS    
 |-PRO_E_DSF_PROPAGATE_ANNOTS
 |    |-PRO_E_DSF_ANNOT_CPY_ALL
 |    |-PRO_E_DSF_ANNOT_DEPEND_ALL
 |    |-PRO_E_DSF_ANNOT_AUTO_CPY_DTM
 |    |-PRO_E_DSF_ANNOT_SELECTIONS
 |         |-PRO_E_DSF_ANNOT_SELECTION
 |              |-PRO_E_DSF_ANNOT_SEL_ANNOTS
 |              |-PRO_E_DSF_ANNOT_CPY_STATUS
 |              |-PRO_E_DSF_ANNOT_DEPENDENCY
 |--PRO_E_DSF_DTMS_FIT
 |      |-PRO_E_DSF_DTM_FIT  
 |           |-PRO_E_DSF_DTM_SELECTION
 |           |-PRO_E_DTMPLN_FIT      
 |           |    |-PRO_E_DTMPLN_FIT_TYPE
 |           |    |-PRO_E_DTMPLN_FIT_REF       If Fit Type is not Default or Fit
 |           |    |-PRO_E_DTMPLN_FIT_DTM_RAD   If Fit Type = Fit Radius
 |           |    |-PRO_E_DTMPLN_FIT_OUTLINE   If Fit Type = Fit Outline 
 |           |-PRO_E_DTMAXIS_FIT
 |                |-PRO_E_DTMAXIS_FIT_TYPE
 |                |-PRO_E_DTMAXIS_FIT_REF  If FIT_TYPE = PRO_DTMAXIS_FIT_REFERENCE
 |                |-PRO_E_DTMAXIS_FIT_LEN  If FIT_TYPE = PRO_DTMAXIS_FIT_LENGTH
 |-PRO_E_DSF_DEPENDENCY
 |-PRO_E_DSF_NOTIFY_UPDATE
 |
 |-PRO_E_IS_SMT_CUT
 |
 |-PRO_E_SMT_CUT_NORMAL_DIR

===============================================================================

(2) Feature elements table

---------------------------------------------------------------------------------------------
Element Id                   Element Name     Data Type                Valid Values
---------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE           Feature Type     PRO_VALUE_TYPE_INT       PRO_FEAT_GEN_MERGE
PRO_E_STD_FEATURE_NAME       Feature Name     PRO_VALUE_TYPE_STRING    Any wstring

PRO_E_GMRG_FEAT_TYPE         Gen Merge feat type PRO_VALUE_TYPE_INT    ProGenMergeType
PRO_E_DSF_REF_MDL            Reference Model compound           
PRO_E_DSF_EXT_LOCAL_TYPE     DSF location Type PRO_VALUE_TYPE_INT      ProDsfExtLocalType
PRO_E_DSF_SEL_REF_MDL        Select Reference Model  PRO_VALUE_TYPE_SELECTION Any model
PRO_E_DSF_PLACEMENT          DSF placement    compound                 if PRO_E_DSF_EXT_LOCAL_TYPE == 
                                                                       PRO_DSF_PLACE_EXTERNAL
PRO_E_COMPONENT_CONSTRAINTS  Constraints      Array                    See ProAsmcomp.h
PRO_E_GMRG_MATERIAL_OPT      Material option  PRO_VALUE_TYPE_INT       ProGenMergeMaterialOpt
PRO_E_GMRG_VARIED_ITEMS      Inheritance Varied Items Dlg              See Note 1
PRO_E_GMRG_COPY_DATUMS       Copy datums opt  PRO_VALUE_TYPE_INT       PRO_B_TRUE / PRO_B_FALSE
PRO_E_DSF_PROPAGATE_ANNOTS   Propagate Annotations  compound
PRO_E_DSF_ANNOT_CPY_ALL      Copy all p.a     PRO_VALUE_TYPE_INT       PRO_B_TRUE / PRO_B_FALSE
PRO_E_DSF_ANNOT_DEPEND_ALL   Depend all p.a.  PRO_VALUE_TYPE_INT       PRO_B_TRUE / PRO_B_FALSE
PRO_E_DSF_ANNOT_AUTO_CPY_DTM Copy datum an    PRO_VALUE_TYPE_INT       PRO_B_TRUE / PRO_B_FALSE
PRO_E_DSF_ANNOT_SELECTIONS   Select Annots    array
PRO_E_DSF_ANNOT_SELECTION    Select Annot     compound
PRO_E_DSF_ANNOT_SEL_ANNOTS   Manual sel       PRO_VALUE_TYPE_SELECTION Any annotaion
PRO_E_DSF_ANNOT_CPY_STATUS   Status           PRO_VALUE_TYPE_INT       PRO_B_TRUE / PRO_B_FALSE       
PRO_E_DSF_ANNOT_DEPENDENCY   Depend           PRO_VALUE_TYPE_INT       ProDSFDependency
PRO_E_DSF_DTMS_FIT           Datums Fit       array
PRO_E_DSF_DTM_FIT            Datum Fit        compound
PRO_E_DSF_DTM_SELECTION      Select Axis/Srf  PRO_VALUE_TYPE_SELECTION axis, srfs
PRO_E_DTMPLN_FIT             Fit              compound                 See ProDtmPln.h
PRO_E_DTMAXIS_FIT            Fit              compound                 See ProDtmAxis.h
PRO_E_DSF_DEPENDENCY         Dependency       PRO_VALUE_TYPE_INT       ProDSFDependency
PRO_E_DSF_NOTIFY_UPDATE      Upd Ctrl On/Off  PRO_VALUE_TYPE_INT   
PRO_E_IS_SMT_CUT             Is Smt Cut       PRO_VALUE_TYPE_BOOLEAN   See Note 3
PRO_E_SMT_CUT_NORMAL_DIR   Smt Cut Normal Dir PRO_VALUE_TYPE_INT       See Note 4
--------------------------------------------------------------------------------------------

Note 1.   Inheritance feature varied items

Varied items cannot be set or accessed directly through the element tree.

To read varied items use the Visit functions available in ProVariantFeat.h.

To set varied items (after the feature has been created), use the appropriate
modification function (e.g. ProDimensionValueSet, ProParameterValueSet) on an
item whose owner is the variant feature model handle (ProVariantfeatMdlGet).

Note 2. For PRO_E_COMPONENT... types, please see ProAsmcomp.h.

Note 3. This element is applicable only in sheetmetal parts.
        Controls cut type, SMT or SOLID.
        PRO_B_TRUE for SMT cut type.

Note 4. This element is applicable only in sheetmetal parts.
        SMT Cut geometry driving surface.
        This element can be PRO_SMT_CUT_DRVSIDE_GREEN for normal to
        Driven Surface or PRO_SMT_CUT_DRVSIDE_WHITE for normal to
        Offset Surface. 
        See ProExtrude.h for ProSmtCutNormDir.
*/

/*============================================================================*/
/* Copy Geometry, Publish Geometry and Shrinkwrap declarations and tree */
/*============================================================================*/

/* Types Declarations */

typedef enum Pro_Gcpy_Place_Type
{
  PRO_CG_PLC_UNDEFINED,
  PRO_CG_PLC_DEFAULT,
  PRO_CG_PLC_CSYS_CSYS,
  PRO_CG_PLC_CURRENT
}
ProGcpyPlaceType;

typedef enum Pro_Gcpy_Refs_Type
{
  PRO_CG_PG_REFS,
  PRO_CG_COLL_REFS
}
ProGcpyRefsType;

typedef enum Pro_Gcpy_Sub_Type
{
  PRO_CG_COPY_GEOM,  /* Copy Geometry */
  PRO_CG_SHRINKWRAP, /* ShrinkWrap */
  PRO_CG_PUB_GEOM    /* Publish Geometry */
}
ProGcpySubType;

#define PRO_MAX_SHRINKWRAP_QUALITY_LVL 10

typedef enum Pro_Shrinkwrap_Collection_Order
{
  PRO_SW_SHRINKWRAP_AND_SELECT,
  PRO_SW_SELECT_AND_SHRINKWRAP
}
ProShrinkwrapCollectionOrder;

typedef enum Pro_Shrinkwrap_Collection_type
{
  PRO_SW_OUTER_SHELL,
  PRO_SW_ALL_SOLID_SURFS,
  PRO_SW_MANUAL
}
ProShrinkwrapCollectionType;

typedef enum Pro_Shrinkwrap_ResGeom_opt
{
  PRO_SW_RES_GEOM_QUILT,
  PRO_SW_RES_GEOM_SOLID
}
ProShrinkwrapResGeomOpt;

typedef enum Pro_Shrinkwrap_FailedSld_opt
{
  PRO_SW_FAILED_SLD_FAIL,
  PRO_SW_FAILED_SLD_TO_QUILT
}
ProShrinkwrapFailedSldOpt;

/*============================================================================
 
(1) Feature element tree
 
PRO_E_FEATURE_TREE
|
|-PRO_E_FEATURE_TYPE
|-PRO_E_STD_FEATURE_NAME
|-PRO_E_CG_FEAT_SUB_TYPE
|-PRO_E_CG_REFS_TYPE
|-PRO_E_CG_LOCATION
|     |-PRO_E_DSF_EXT_LOCAL_TYPE
|     |-PRO_E_DSF_SEL_REF_MDL
|     |-PRO_E_CG_PLACEMENT
|          |-PRO_E_CG_PLACE_TYPE
|          |-PRO_E_CG_CSYS_PLACE
|               |-PRO_E_CG_PLC_LOCAL_CSYS
|               |-PRO_E_CG_PLC_EXT_CSYS
|-PRO_E_CG_PG_OR_REFS
|    |-PRO_E_CG_PUBD_GEOM
|    |-PRO_E_CG_REFS_COLL
|         |-PRO_E_STD_SURF_COLLECTION_APPL
|         |-PRO_E_STD_CURVE_COLLECTION_APPL
|         |-PRO_E_CG_OBJS_COLL 
|-PRO_E_SW_COLLECTION_TYPE
|-PRO_E_SW_OPTIONS 
|   |-PRO_E_SW_QUALITY
|   |-PRO_E_SW_FILL_HOLES
|   |-PRO_E_SW_COLLECT_QUILTS
|   |-PRO_E_SW_SKIP_SURF_SIZE
|   |-PRO_E_SW_COLLECT_ORDER
|   |-PRO_E_SW_RES_GEOM_OPT
|   |-PRO_E_SW__FAILED_SLD_OPT
|   |-PRO_E_SW_FILL_CNTRS_ARR
|   |  |-PRO_E_SW_FILL_CNTRS
|   |     |-PRO_E_SW_FILL_CNTRS_SRF_SEL
|   |-PRO_E_SW_FILL_CNTRS_DISP_CRV
|-PRO_E_SW_COMP_SUBSET 
|   |-PRO_E_SW_COMPONENT
|       |-PRO_E_SW_INCLUDE_COMP
|       |-PRO_E_SW_SEL_COMPONENT
|-PRO_E_SW_REFS_COLL
|     |-PRO_E_STD_SURF_COLLECTION_APPL
|     |-PRO_E_SW_EXCLUDE_SURF_COLL_APPL
|     |-PRO_E_STD_CURVE_COLLECTION_APPL
|     |-PRO_E_CG_OBJS_COLL
|-PRO_E_DSF_PROPAGATE_ANNOTS
|    |-PRO_E_DSF_ANNOT_CPY_ALL
|    |-PRO_E_DSF_ANNOT_DEPEND_ALL
|    |-PRO_E_DSF_ANNOT_AUTO_CPY_DTM
|    |-PRO_E_DSF_ANNOT_SELECTIONS
|         |-PRO_E_DSF_ANNOT_SELECTION
|              |-PRO_E_DSF_ANNOT_SEL_ANNOTS
|              |-PRO_E_DSF_ANNOT_CPY_STATUS
|              |-PRO_E_DSF_ANNOT_DEPENDENCY
|-PRO_E_CG_SRFS_COPY
|    |-PRO_E_SRF_COPY_TYPE
|    |-PRO_E_SRF_COPY_EXCL
|    |-PRO_E_SRF_COPY_FILL
|    |-PRO_E_STD_CURVE_COLLECTION_APPL
|--PRO_E_DSF_DTMS_FIT 
|     |-PRO_E_DSF_DTM_FIT 
|          |-PRO_E_DSF_DTM_SELECTION
|          |-PRO_E_DTMPLN_FIT          
|          |    |-PRO_E_DTMPLN_FIT_TYPE
|          |    |-PRO_E_DTMPLN_FIT_REF     If Fit Type is not Default or Fit Radius
|          |    |-PRO_E_DTMPLN_FIT_DTM_RAD If Fit Type = Fit Radius
|          |    |-PRO_E_DTMPLN_FIT_OUTLINE If Fit Type = Fit Outline 
|          |-PRO_E_DTMAXIS_FIT
|               |-PRO_E_DTMAXIS_FIT_TYPE
|               |-PRO_E_DTMAXIS_FIT_REF  If FIT_TYPE = PRO_DTMAXIS_FIT_REFERENCE
|               |-PRO_E_DTMAXIS_FIT_LEN  If FIT_TYPE = PRO_DTMAXIS_FIT_LENGTH
|-PRO_E_DSF_DEPENDENCY
|-PRO_E_DSF_NOTIFY_UPDATE

---------------------------------------------------------------------
Element Id                   Element Name     Data Type             
---------------------------------------------------------------------
PRO_E_FEATURE_TYPE           Feature Type     PRO_VALUE_TYPE_INT    
PRO_E_STD_FEATURE_NAME       Feature Name     PRO_VALUE_TYPE_STRING
PRO_E_CG_FEAT_SUB_TYPE       Sub feature Type PRO_VALUE_TYPE_INT    
PRO_E_CG_REFS_TYPE           Refs or PG type  PRO_VALUE_TYPE_INT   
PRO_E_CG_LOCATION            Location Method  compound            
PRO_E_DSF_EXT_LOCAL_TYPE     Location Type    PRO_VALUE_TYPE_INT 
PRO_E_DSF_SEL_REF_MDL        External Model   PRO_VALUE_TYPE_SELECTION
PRO_E_CG_PLACEMENT           Copy Geom placement compound             
                                                                      
PRO_E_CG_PLACE_TYPE          Copy Geom Location PRO_VALUE_TYPE_INT    
PRO_E_CG_CSYS_PLACE          Csys-Csys Location  compound
PRO_E_CG_PLC_LOCAL_CSYS      Local Csys       PRO_VALUE_TYPE_SELECTION
PRO_E_CG_PLC_EXT_CSYS        External Csys    PRO_VALUE_TYPE_SELECTION

PRO_E_CG_PG_OR_REFS          Pub.Geom or Refs compound 
PRO_E_CG_PUBD_GEOM           Select Pub. Geom PRO_VALUE_TYPE_SELECTION

PRO_E_CG_REFS_COLL           Select Refs      compound  
PRO_E_STD_SURF_COLLECTION_APPL  Selected surfaces   Surface collection
PRO_E_STD_CURVE_COLLECTION_APPL Curves or/and edges Chain collection
PRO_E_CG_OBJS_COLL           Misc Refs        PRO_VALUE_TYPE_SELECTION

PRO_E_SW_COLLECTION_TYPE     Shrinkwrap collection types   PRO_VALUE_TYPE_OPTION 
PRO_E_SW_RES_GEOM_OPT        Shrinkwrap result geomtery options PRO_VALUE_TYPE_OPTION
PRO_E_SW_FAILED_SLD_OPT      Shrinkwrap failed solidification options PRO_VALUE_TYPE_OPTION
PRO_E_SW_REFS_COLL           Select Refs      compound  
PRO_E_SW_OPTIONS             Shrinkwrap options       compound 
PRO_E_SW_QUALITY             Shrinkwrap quality level PRO_VALUE_TYPE_INT
PRO_E_SW_FILL_HOLES          Shrinkwrap auto fill holes PRO_VALUE_TYPE_INT
PRO_E_SW_COLLECT_QUILTS      Shrinkwrap collect quilts  PRO_VALUE_TYPE_INT
PRO_E_SW_SKIP_SURF_SIZE      Shrinkwrap skip surfaces size PRO_VALUE_TYPE_INT
PRO_E_SW_COLLECT_ORDER       Shrinkwrap collect order PRO_VALUE_TYPE_INT
PRO_E_SW_COMP_SUBSET         Shrinkwrap components subset array
PRO_E_SW_COMPONENT           Shrinkwrap one component compound
PRO_E_SW_INCLUDE_COMP        Include comp. to collection PRO_VALUE_TYPE_INT
PRO_E_SW_SEL_COMPONENT       Select component PRO_VALUE_TYPE_SELECTION
PRO_E_SW_EXCLUDE_SURF_COLL_APPL  Excluded surfaces   Surface collection
PRO_E_SW_FILL_CNTRS_ARR      Internal countours to be filled prior to surface collection   array
PRO_E_SW_FILL_CNTRS          Internal countours to be filled prior to surface collection   compound
PRO_E_SW_FILL_CNTRS_SRF_SEL  Surface selection to fill countours  PRO_VALUE_TYPE_SELECTION
PRO_E_SW_FILL_CNTRS_DISP_CRV Display curve in place of filled contour PRO_ELEM_TYPE_OPTION

PRO_E_DSF_PROPAGATE_ANNOTS   Propagate Annots compound
PRO_E_DSF_ANNOT_CPY_ALL      Copy all p.a     PRO_VALUE_TYPE_INT
PRO_E_DSF_ANNOT_DEPEND_ALL   Depend all p.a.  PRO_VALUE_TYPE_INT
PRO_E_DSF_ANNOT_AUTO_CPY_DTM Copy datum an    PRO_VALUE_TYPE_INT
PRO_E_DSF_ANNOT_SELECTIONS   Select Annots    array
PRO_E_DSF_ANNOT_SELECTION    Select Annot     compound
PRO_E_DSF_ANNOT_SEL_ANNOTS   Manual sel       PRO_VALUE_TYPE_SELECTION 
PRO_E_DSF_ANNOT_CPY_STATUS   Status           PRO_VALUE_TYPE_INT      
PRO_E_DSF_ANNOT_DEPENDENCY   Depend           PRO_VALUE_TYPE_INT       
PRO_E_CG_SRFS_COPY           Surfaces Copy    compound
PRO_E_SRF_COPY_TYPE          Type             PRO_VALUE_TYPE_INT      
                                                                     

PRO_E_SRF_COPY_EXCL          Exclude Loop     PRO_VALUE_TYPE_SELECTION 
PRO_E_SRF_COPY_FILL          Fill Loop        array of selections
PRO_E_STD_CURVE_COLLECTION_APPL  Boundary     Chain collection
PRO_E_DSF_DTMS_FIT           Datums Fit       array
PRO_E_DSF_DTM_FIT            Datum Fit        compound
PRO_E_DSF_DTM_SELECTION      Select Axis/Srf  PRO_VALUE_TYPE_SELECTION
PRO_E_DTMPLN_FIT             Fit              compound                 
PRO_E_DTMAXIS_FIT            Fit              compound                
PRO_E_DSF_DEPENDENCY         Dependency       PRO_VALUE_TYPE_INT      
PRO_E_DSF_NOTIFY_UPDATE      Notif Upd On/Off  PRO_VALUE_TYPE_INT   
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
Table 1 : Elements for all types of Copy Geometry features and sub feature
          types for whose it is visible. 
=====================================================================
   CG  : Copy Geometry feature (internal placement type)
   PG  : Publish Geometry feature 
   SW  : Shrinkwrap feature (internal placement type)
   ECG : External CG (see note below)
   ESW : External SW (see note below)
      note : when PRO_E_DSF_EXT_LOCAL_TYPE == PRO_DSF_PLACE_EXTERNAL
   All Copy Geom. feats : CG, ECG, SW, ESW, PG
   All CG or SW features : CG, ECG, SW, ESW
----------------------------------------------------------------------------
| Element Id                  | Value               | Is Visible For       |
----------------------------------------------------------------------------
| PRO_E_FEATURE_TYPE          | PRO_FEAT_GEOM_COPY  | All Copy Geom. feats |
|.............................|.....................|......................|
| PRO_E_STD_FEATURE_NAME      | Any wstring         | All Copy Geom. feats |
|.............................|.....................|......................|
| PRO_E_CG_FEAT_SUB_TYPE      | ProGcpySubType      | All Copy Geom. feats |
|                             | Mandatory step      |                      |
|.............................|.....................|......................|
| PRO_E_CG_REFS_TYPE          | ProGcpyRefsType     | CG or ECG            |
|.............................|.....................|......................|
| PRO_E_CG_LOCATION           | compound            | All CG or SW features|
| |-PRO_E_DSF_EXT_LOCAL_TYPE  | ProDsfExtLocalType  | All CG or SW features|
| |-PRO_E_DSF_SEL_REF_MDL     | Any model           | All CG or SW features|
| |-PRO_E_CG_PLACEMENT        | compound            | ECG or ESW           |
|  |-PRO_E_CG_PLACE_TYPE      | ProGcpyPlaceType    | ECG or ESW           |
|    |-PRO_E_CG_CSYS_PLACE    | compound            | ECG or ESW           |
|     |-PRO_E_CG_PLC_LOCAL_CSYS| local coord. system| ECG or ESW           |
|     |-PRO_E_CG_PLC_EXT_CSYS | external coord. sys | ECG or ESW           |
|.............................|.....................|......................|
| PRO_E_CG_PG_OR_REFS         | compound            | CG or ECG            |
| |-PRO_E_CG_PUBD_GEOM        | Any Copy Geom feat. | CG or ECG            |
| |-PRO_E_CG_REFS_COLL          | compound          | CG, ECG, PG          |
|  |-PRO_E_STD_SURF_COLLECTION_APPL Surface collect | CG, ECG, PG          |
|  |-PRO_E_STD_CURVE_COLLECTION_APPL Chain collect  | CG, ECG, PG          |
|  |-PRO_E_CG_OBJS_COLL       | Datums, Axes, etc.  | CG, ECG, PG          |
|.............................|.....................|......................|
| PRO_E_SW_COLLECTION_TYPE    | ProShrinkwrapCollectionType    | SW, ESW   |
|.............................|.....................|......................|
| PRO_E_SW_REFS_COLL          | compound            | SW, ESW              |
| |-PRO_E_STD_SURF_COLLECTION_APPL Surface collect  | SW, ESW              |
| |-PRO_E_SW_EXCLUDE_SURF_COLL_APPL Surface collect | SW, ESW              |
| |-PRO_E_STD_CURVE_COLLECTION_APPL Chain collect   | SW, ESW              |
| |-PRO_E_CG_OBJS_COLL        | Datums, Axes, etc.  | SW, ESW              |
|.............................|.....................|......................|
| PRO_E_SW_OPTIONS            | compound            | SW, ESW              |
| |-PRO_E_SW_QUALITY | [1-PRO_MAX_SHRINKWRAP_QUALITY_LVL]| SW, ESW         |
| |-PRO_E_SW_FILL_HOLES       | PRO_B_TRUE/FALSE    | SW, ESW              |
| |-PRO_E_SW_COLLECT_QUILTS   | PRO_B_TRUE/FALSE    | SW, ESW              |
| |-PRO_E_SW_SKIP_SURF_SIZE | 0 - do not skip [1-100] % | SW, ESW          |
| |-PRO_E_SW_COLLECT_ORDER  | ProShrinkwrapCollectionOrder| SW, ESW        |
| |-PRO_E_SW_COMP_SUBSET      | array               | SW, ESW              |
| | |-PRO_E_SW_COMPONENT      | compound            | SW, ESW              |
| |   |-PRO_E_SW_INCLUDE_COMP | PRO_B_TRUE/FALSE    | SW, ESW              |
| |   |-PRO_E_SW_SEL_COMPONENT| Any component from  | SW, ESW              |
| |                           | ref model           |                      |
| |-PRO_E_SW_RES_GEOM_OPT     | ProShrinkwrapResGeomOpt | SW, ESW          |
| |-PRO_E_SW_FAILED_SLD_OPT   | ProShrinkwrapFailedSldOpt | SW, ESW        |
| |- PRO_E_SW_FILL_CNTRS_ARR  | array               | SW, ESW              |
| |     |-PRO_E_SW_FILL_CNTRS | compound            | SW, ESW              |
| |          |-PRO_E_SW_FILL_CNTRS_SRF_SEL  | face  | SW, ESW              |
| |- PRO_E_SW_FILL_CNTRS_DISP_CRV  | PRO_B_TRUE/FALSE  | SW, ESW           |
|.............................|.....................|......................|
| PRO_E_DSF_PROPAGATE_ANNOTS  | compound            | All Copy Geom. feats |
| |-PRO_E_DSF_ANNOT_CPY_ALL   | PRO_B_TRUE/FALSE    | All Copy Geom. feats |
| |-PRO_E_DSF_ANNOT_DEPEND_ALL| PRO_B_TRUE/FALSE    | All Copy Geom. feats |
| |-PRO_E_DSF_ANNOT_AUTO_CPY_DTM| PRO_B_TRUE/FALSE  | All Copy Geom. feats |
| |-PRO_E_DSF_ANNOT_SELECTIONS| array               | All Copy Geom. feats |
|  |-PRO_E_DSF_ANNOT_SELECTION| compound            | All Copy Geom. feats |
|   |-PRO_E_DSF_ANNOT_SEL_ANNOTS | Any annotaion    | All Copy Geom. feats |
|   |-PRO_E_DSF_ANNOT_CPY_STATUS | PRO_B_TRUE/FALSE | All Copy Geom. feats |
|   |-PRO_E_DSF_ANNOT_DEPENDENCY | ProDSFDependency | All Copy Geom. feats |
|.............................|.....................|......................|
| PRO_E_CG_SRFS_COPY          | compound            | CG or ECG            |
| |-PRO_E_SRF_COPY_TYPE       | PRO_SRFCOPY_AS_IS,  | CG or ECG            |
| |                           | PRO_SRFCOPY_EXCLD_FILL,|                   |
| |                           | PRO_SRFCOPY_INSIDE_BNDRY|                  |
| |-PRO_E_SRF_COPY_EXCL       | Surfaces            | CG or ECG            |
| |-PRO_E_SRF_COPY_FILL       | Loops               | CG or ECG            |
| |-PRO_E_STD_CURVE_COLLECTION_APPL| Chain collection | CG or ECG          |
|.............................|.....................|......................|
| PRO_E_DSF_DTMS_FIT          | array               | All CG or SW features|
| |-PRO_E_DSF_DTM_FIT         | compound            | All CG or SW features|
|   |-PRO_E_DSF_DTM_SELECTION | axis, srfs          | All CG or SW features|
|     |-PRO_E_DTMPLN_FIT      | compound            | All CG or SW features|
|     |                       | See ProDtmPln.h     |                      |
|     |-PRO_E_DTMAXIS_FIT     | compound            | All CG or SW features|
|                             | See ProDtmAxis.h    |                      |
|.............................|.....................|......................|
| PRO_E_DSF_DEPENDENCY        | ProDSFDependency    | Copy Geom. feats     |
|.............................|.....................|......................|
| PRO_E_DSF_NOTIFY_UPDATE     | ProDsfNotifyUpdate  | Notify Update On/Off |
----------------------------------------------------------------------------

*/

extern ProError ProDatasharingfeatureIsQuerydriven (ProFeature* feature, 
                                                    ProBoolean* is_query_driven);
/*
    Purpose: Identifies if the copy geometry or publish geometry's references 
             are wholly or partially driven by a saved query.

    Input Arguments:
        feature - The data sharing feature.

    Output Arguments:
        is_query_driven - PRO_B_TRUE if the feature's references are query 
                          driven, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - The feature is not a copy geometry or publish 
                              geometry feature.
        PRO_TK_NO_LICENSE   - License check failure.

    See Also:
        ProDatasharingfeatureQueryUpdate()
*/

extern ProError ProDatasharingfeatureQueryUpdate (ProFeature* feature, 
                                                  ProBoolean allow_fix_ui);
/*
    Purpose: Updates the results of the saved query stored within the 
             references of the copy geometry or publish geometry' feature.

    Input Arguments:
        feature - The data sharing feature.
        allow_fix_ui - PRO_B_TRUE to show the Fix Model UI if regeneration 
                       fails due to this update, PRO_B_FALSE to recover from 
                       the failure automatically.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - The feature is not a copy geometry or publish 
                              geometry feature.
        PRO_TK_E_NOT_FOUND - The feature is not query driven.
        PRO_TK_GENERAL_ERROR - The feature query update is failed.
        PRO_TK_NO_LICENSE   - License check failure.
        PRO_TK_BAD_CONTEXT  - The feature is query driven, but is set as        
                              independent of the parent model.

    See Also:
        ProDatasharingfeatureIsQueryDriven()
*/

PRO_END_C_DECLS
#endif /*PRO_DATA_SHARE_FEAT_H*/
