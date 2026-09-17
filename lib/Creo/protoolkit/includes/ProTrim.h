#ifndef PRO_TRIM_H
#define PRO_TRIM_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) 
(1.1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_FEATURE_FORM
      |
      |-- PRO_E_SRF_TRIM_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SURF_TRIM_TYPE
      |
      |-- PRO_E_TRIM_QUILT
      |
      |-- PRO_E_STD_USEQLT_QLT
      |
      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |
      |-- PRO_E_TRIM_SILH_PLANE
      |
      |-- PRO_E_MATERIAL_SIDE
      |
      |-- PRO_E_PRIMARY_QLTSIDE
      |
      |-- PRO_E_STD_USEQLT_SIDE
      |
      |-- PRO_E_KEEP_TRIM_SURF_OPT
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

=========================================================================================================================

(1.2) Feature elements table

-------------------------------------------------------------------------------------------------------------------------
 Element Id                Element Name                Data Type                    Valid Values 
-------------------------------------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE        Feature Type                PRO_VALUE_TYPE_INT         PRO_FEAT_CUT
 PRO_E_FEATURE_FORM        Feature Form                PRO_VALUE_TYPE_INT         PRO_USE_SURFS,PRO_NOTYPE
 PRO_E_SRF_TRIM_TYPE       Trim Type Identity          PRO_VALUE_TYPE_INT         ProSurfTrimType ( See Note -1)
 PRO_E_STD_FEATURE_NAME    Feature Name                PRO_VALUE_TYPE_WSTRING     Optional
 PRO_E_SURF_TRIM_TYPE      Surface Trim Type           PRO_VALUE_TYPE_INT         ProSurfTrimType
 PRO_E_TRIM_QUILT          Trimmed Quilt               PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT
 PRO_E_STD_USEQLT_QLT      Trimming Quilt/plane        PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT, PRO_DATUM_PLANE
 PRO_E_STD_CURVE_COLLECTION_APPL Trimming Curves       PRO_VALUE_TYPE_SELECTION   PRO_CURVE, PRO_COMP_CRV, curve_chain 
 PRO_E_TRIM_SILH_PLANE     Silhouette Plane            PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_DATUM_PLANE
 PRO_E_MATERIAL_SIDE       Material Side Options       PRO_VALUE_TYPE_INT         ProTrimMatlSideOpts 
 PRO_E_PRIMARY_QLTSIDE     Primary Quilt Side Options  PRO_VALUE_TYPE_INT         ProTrimPrimaryQltSide 
 PRO_E_STD_USEQLT_SIDE     Thin Thickness direction options. PRO_VALUE_TYPE_INT   ProTrimStdQuiltSideOpts 
 PRO_E_KEEP_TRIM_SURF_OPT  Keeping Trim Surf. Option   PRO_VALUE_TYPE_INT         ProKeepTrimSurfOpts ( See Note-2)
 PRO_E_THICKNESS           Thin Thickness              PRO_VALUE_TYPE_DOUBLE 
 PRO_E_SRF_OFFS_METHOD     Offset Types                PRO_VALUE_TYPE_INT         ProTrimSurfOffMethodOpts
 PRO_E_SRF_OFFS_CTRLFIT    Control Fit                 PRO_ELEM_COMPOUND
 PRO_E_SRF_OFFS_SCALINGCSYS Control Fit Csys           PRO_VALUE_TYPE_SELECTION   PRO_CSYS
 PRO_E_SRF_OFFS_AXISES     Control Fit Axes            PRO_VALUE_TYPE_INT         ProThinTrimAxesOption
 PRO_E_SRF_OFFS_HANDLINGS  Special Handlings           PRO_ELEM_ARRAY
 PRO_E_SRF_OFFS_HANDLING   Special Handling item       PRO_ELEM_COMPOUND
 PRO_E_SRF_OFFS_REF_SEL    Special Handling faces      PRO_VALUE_TYPE_SELECTION   PRO_SURFACE (See Note-3)
 PRO_E_SRF_OFFS_ACTION     Special Handling action     PRO_VALUE_TYPE_INT       

=========================================================================================================================

(2)
(2.1) Feature element tree for Use Quilt

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_FEATURE_FORM
      |
      |-- PRO_E_SRF_TRIM_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SURF_TRIM_TYPE
      |
      |-- PRO_E_TRIM_QUILT
      |
      |-- PRO_E_STD_USEQLT_QLT
      |
      |-- PRO_E_MATERIAL_SIDE
      |
      |-- PRO_E_PRIMARY_QLTSIDE
      |
      |-- PRO_E_KEEP_TRIM_SURF_OPT

=========================================================================================================================

(2.2) Feature elements table for Use Quilt

-------------------------------------------------------------------------------------------------------------------------
 Element Id                Element Name                Data Type                    Valid Values 
-------------------------------------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE        Feature Type                PRO_VALUE_TYPE_INT         PRO_FEAT_CUT
 PRO_E_FEATURE_FORM        Feature Form                PRO_VALUE_TYPE_INT         PRO_USE_SURFS
 PRO_E_SRF_TRIM_TYPE       Trim Type Identity          PRO_VALUE_TYPE_INT         ProSurfTrimType ( See Note -1)
 PRO_E_STD_FEATURE_NAME    Feature Name                PRO_VALUE_TYPE_WSTRING     Optional
 PRO_E_SURF_TRIM_TYPE      Surface Trim Type           PRO_VALUE_TYPE_INT         ProSurfTrimType
 PRO_E_FEATURE_TYPE        Feature Type                PRO_VALUE_TYPE_INT         PRO_FEAT_CUT
 PRO_E_FEATURE_FORM        Feature Form                PRO_VALUE_TYPE_INT         PRO_USE_SURFS
 PRO_E_TRIM_QUILT          Trimmed Quilt               PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT
 PRO_E_STD_USEQLT_QLT      Trimming Quilt/plane        PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT, PRO_DATUM_PLANE
 PRO_E_MATERIAL_SIDE       Material Side Options       PRO_VALUE_TYPE_INT         ProTrimMatlSideOpts 
 PRO_E_PRIMARY_QLTSIDE     Primary Quilt Side Options  PRO_VALUE_TYPE_INT         ProTrimPrimaryQltSide
 PRO_E_KEEP_TRIM_SURF_OPT  Keeping Trim Surf. Option   PRO_VALUE_TYPE_INT         ProKeepTrimSurfOpts 
=========================================================================================================================

(3)
(3.1) Feature element tree for Use Curve

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_SRF_TRIM_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SURF_TRIM_TYPE
      |
      |-- PRO_E_TRIM_QUILT
      |
      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |
      |-- PRO_E_MATERIAL_SIDE
      |
      |-- PRO_E_PRIMARY_QLTSIDE

=========================================================================================================================

(3.2) Feature elements table for Use Curve

-------------------------------------------------------------------------------------------------------------------------
 Element Id                Element Name                Data Type                    Valid Values 
-------------------------------------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE        Feature Type                PRO_VALUE_TYPE_INT         PRO_FEAT_CUT
 PRO_E_SRF_TRIM_TYPE       Trim Type Identity          PRO_VALUE_TYPE_INT         ProSurfTrimType ( See Note -1)
 PRO_E_STD_FEATURE_NAME    Feature Name                PRO_VALUE_TYPE_WSTRING     Optional
 PRO_E_SURF_TRIM_TYPE      Surface Trim Type           PRO_VALUE_TYPE_INT         ProSurfTrimType
 PRO_E_TRIM_QUILT          Trimmed Quilt               PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT
 PRO_E_STD_CURVE_COLLECTION_APPL Trimming Curves       PRO_VALUE_TYPE_SELECTION   PRO_CURVE, PRO_COMP_CRV, curve_chain 
 PRO_E_MATERIAL_SIDE       Material Side Options       PRO_VALUE_TYPE_INT         ProTrimPrimaryQltSide 
 PRO_E_PRIMARY_QLTSIDE     Primary Quilt Side Options  PRO_VALUE_TYPE_INT         ProTrimStdQuiltSideOpts
=========================================================================================================================

(4) 
(4.1) Feature element tree for Thin

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_FEATURE_FORM
      |
      |-- PRO_E_SRF_TRIM_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SURF_TRIM_TYPE
      |
      |-- PRO_E_TRIM_QUILT
      |
      |-- PRO_E_STD_USEQLT_QLT
      |
      |-- PRO_E_STD_USEQLT_SIDE
      |
      |-- PRO_E_KEEP_TRIM_SURF_OPT
      |
      |-- PRO_E_THICKNESS
      |
      |-- PRO_E_SRF_OFFS_METHOD
      |
      |-- PRO_E_SRF_OFFS_CTRLFIT
      |
      |-- PRO_E_SRF_OFFS_HANDLINGS


(4.2) Feature elements table for Thin

-------------------------------------------------------------------------------------------------------------------------
 Element Id                Element Name                Data Type                    Valid Values 
-------------------------------------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE        Feature Type                PRO_VALUE_TYPE_INT         PRO_FEAT_CUT
 PRO_E_FEATURE_FORM        Feature Form                PRO_VALUE_TYPE_INT         PRO_USE_SURFS
 PRO_E_SRF_TRIM_TYPE       Trim Type Identity          PRO_VALUE_TYPE_INT         ProSurfTrimType ( See Note -1)
 PRO_E_STD_FEATURE_NAME    Feature Name                PRO_VALUE_TYPE_WSTRING     Optional
 PRO_E_SURF_TRIM_TYPE      Surface Trim Type           PRO_VALUE_TYPE_INT         ProSurfTrimType
 PRO_E_TRIM_QUILT          Trimmed Quilt               PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT
 PRO_E_STD_USEQLT_QLT      Trimming Quilt              PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT, PRO_DATUM_PLANE
 PRO_E_STD_USEQLT_SIDE     Thickness direction options PRO_VALUE_TYPE_INT         ProTrimStdQuiltSideOpts
 PRO_E_KEEP_TRIM_SURF_OPT  Keeping Trim Surf. Option   PRO_VALUE_TYPE_INT         ProKeepTrimSurfOpts
 PRO_E_THICKNESS           Thin Thickness              PRO_VALUE_TYPE_DOUBLE 
 PRO_E_SRF_OFFS_METHOD     Offset Types                PRO_VALUE_TYPE_INT         ProTrimSurfOffMethodOpts
 PRO_E_SRF_OFFS_SCALINGCSYS  Control Fit Csys          PRO_VALUE_TYPE_SELECTION   PRO_CSYS
 PRO_E_SRF_OFFS_AXISES       Control Fit Axes          PRO_VALUE_TYPE_INT         ProThinTrimAxesOption
 PRO_E_SRF_OFFS_REF_SEL      Special Handling faces    PRO_VALUE_TYPE_SELECTION   PRO_SURFACE 
 PRO_E_SRF_OFFS_ACTION     Special Handling action     PRO_VALUE_TYPE_INT       

=========================================================================================================================

(5)
(5.1) Feature element tree for Silhouette Trim 

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_SRF_TRIM_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SURF_TRIM_TYPE
      |
      |-- PRO_E_TRIM_QUILT
      |
      |-- PRO_E_TRIM_SILH_PLANE
      |
      |-- PRO_E_MATERIAL_SIDE
      |
      |-- PRO_E_PRIMARY_QLTSIDE
      |
      |-- PRO_E_KEEP_TRIM_SURF_OPT

=========================================================================================================================

(5.2) Feature elements table for Silhouette Trim

-------------------------------------------------------------------------------------------------------------------------
 Element Id                Element Name                Data Type                    Valid Values 
-------------------------------------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE        Feature Type                PRO_VALUE_TYPE_INT         PRO_FEAT_CUT
 PRO_E_SRF_TRIM_TYPE       Trim Type Identity          PRO_VALUE_TYPE_INT         ProSurfTrimType ( See Note -1)
 PRO_E_STD_FEATURE_NAME    Feature Name                PRO_VALUE_TYPE_WSTRING     Optional
 PRO_E_SURF_TRIM_TYPE      Surface Trim Type           PRO_VALUE_TYPE_INT         ProSurfTrimType
 PRO_E_TRIM_QUILT          Trimmed Quilt               PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_QUILT
 PRO_E_TRIM_SILH_PLANE     Silhouette plane            PRO_VALUE_TYPE_SELECTION   PRO_SURFACE, PRO_DATUM_PLANE
 PRO_E_MATERIAL_SIDE       Material Side Options       PRO_VALUE_TYPE_INT         ProTrimMatlSideOpts 
 PRO_E_PRIMARY_QLTSIDE     Primary Quilt Side Options  PRO_VALUE_TYPE_INT         ProTrimPrimaryQltSide
 PRO_E_KEEP_TRIM_SURF_OPT  Keeping Trim Surf. Option   PRO_VALUE_TYPE_INT         ProKeepTrimSurfOpts 
=========================================================================================================================

=========================================================================================================================
(6) Notes

    Note-1 : The element PRO_E_SRF_TRIM_TYPE is a non-redefinable mandatory element for Surface Trim. 
             The values for this element are listed as ProSurfTrimType.
             This element is useful to identify the exact surface trim type like use quilt, use curves etc..
 
    Note-2 : Keep Trimming Surface option is valid only when the trimming quilt is a surface/quilt.

    Note-3 : Surfaces should be from the Trimming Quilt. 

=========================================================================================================================
(7) Elements required for different type of Trims

----------------------------------------------------------------------------------
|          | Element Id                       | Comment                          |
---------------------------------------------------------------------------------|
|  Use     : PRO_E_FEATURE_TYPE               : Mandatory                        |
|  Quilt   : PRO_E_FEATURE_FORM               : Mandatory                        |
|          : PRO_E_SRF_TRIM_TYPE              : Mandatory                        | 
|          : PRO_E_STD_FEATURE_NAME           : Optional                         | 
|          : PRO_E_SURF_TRIM_TYPE             : Mandatory                        | 
|          : PRO_E_TRIM_QUILT                 : Mandatory                        |
|          : PRO_E_STD_USEQLT_QLT             : Mandatory                        |
|          : PRO_E_MATERIAL_SIDE              :                                  |
|          : PRO_E_PRIMARY_QLTSIDE            :                                  |
|          : PRO_E_KEEP_TRIM_SURF_OPT         :                                  |
|..........:..................................:..................................|
|  Use     : PRO_E_FEATURE_TYPE               : Mandatory                        |
|  Curve   : PRO_E_SRF_TRIM_TYPE              : Mandatory                        |
|          : PRO_E_STD_FEATURE_NAME           : Optional                         | 
|          : PRO_E_SURF_TRIM_TYPE             : Mandatory                        | 
|          : PRO_E_TRIM_QUILT                 : Mandatory                        |
|          : PRO_E_STD_CURVE_COLLECTION_APPL  : Mandatory                        |
|          : PRO_E_MATERIAL_SIDE              :                                  |
|          : PRO_E_PRIMARY_QLTSIDE            :                                  |
|..........:..................................:..................................|
|  Thin    : PRO_E_FEATURE_TYPE               : Mandatory                        |
|          : PRO_E_FEATURE_FORM               : Mandatory                        |
|          : PRO_E_SRF_TRIM_TYPE              : Mandatory                        | 
|          : PRO_E_STD_FEATURE_NAME           : Optional                         | 
|          : PRO_E_SURF_TRIM_TYPE             : Mandatory                        | 
|          : PRO_E_TRIM_QUILT                 : Mandatory                        |
|          : PRO_E_STD_USEQLT_QLT             : Mandatory                        |
|          : PRO_E_STD_USEQLT_SIDE            :                                  |
|          : PRO_E_KEEP_TRIM_SURF_OPT         :                                  |
|          : PRO_E_THICKNESS                  :                                  |
|          : PRO_E_SRF_OFFS_METHOD            :                                  |
|          : PRO_E_SRF_OFFS_CTRLFIT           :                                  |
|          : PRO_E_SRF_OFFS_HANDLINGS         :                                  |
|..........:..................................:..................................|
|Silhouette: PRO_E_FEATURE_TYPE               : Mandatory                        |
|          : PRO_E_SRF_TRIM_TYPE              : Mandatory                        | 
|          : PRO_E_STD_FEATURE_NAME           : Optional                         | 
|          : PRO_E_SURF_TRIM_TYPE             : Mandatory                        | 
|          : PRO_E_TRIM_QUILT                 : Mandatory                        |
|          : PRO_E_TRIM_SILH_PLANE            : Mandatory                        |
|          : PRO_E_MATERIAL_SIDE              :                                  |
|          : PRO_E_PRIMARY_QLTSIDE            :                                  |
|          : PRO_E_KEEP_TRIM_SURF_OPT         :                                  |
|..........:..................................:..................................|


*/

/* PRO_TRIM_TYPE */
typedef enum _ProSurfTrimType
{
   PRO_SURF_TRIM_TYPE_UNDEF = 0,
   PRO_SURF_TRIM_USE_CRV    = 1,
   PRO_SURF_TRIM_USE_QLT    = 2,
   PRO_SURF_TRIM_THIN       = 3,
   PRO_SURF_TRIM_SILH       = 4
}ProSurfTrimType;


/* PRO_E_MATERIAL_SIDE */ 
typedef enum _ProTrimMatlSideOpts
{
   PRO_TRIM_MATL_SIDE_ONE = 1,
   PRO_TRIM_MATL_SIDE_TWO = 2,
   PRO_TRIM_MATL_BOTH_SIDES = 3 
} ProTrimMatlSideOpts;


/* PRO_E_PRIMARY_QLTSIDE */
typedef enum _ProTrimPrimaryQltSide
{ 
   PRO_TRIM_PRIM_QLT_SIDE_ONE = -1, 
   PRO_TRIM_PRIM_QLT_SIDE_TWO = 1
} ProTrimPrimaryQltSide;


/* PRO_E_STD_QUILT_SIDE */ 
typedef enum _ProTrimStdQuiltSideOpts
{
   PRO_TRIM_STD_QUILT_SIDE_ONE = 1,
   PRO_TRIM_STD_QUILT_SIDE_TWO = 2,
   PRO_TRIM_STD_QUILT_BOTH_SIDES = 3
} ProTrimStdQuiltSideOpts;


/* PRO_E_KEEP_TRIM_SURF_OPT */ 
typedef enum _ProKeepTrimSurfOpts
{
   PRO_KEEP_TRIM_SURF_OPT_NO = 0,
   PRO_KEEP_TRIM_SURF_OPT_YES = 1
} ProKeepTrimSurfOpts;

/* PRO_E_SRF_OFFS_METHOD */  
typedef enum _ProTrimSurfOffMethodOpts 
{
   PRO_TRIM_SRF_OFFS_METH_NORMTOSURF = 1,
   PRO_TRIM_SRF_OFFS_METH_AUTOSCALE = 2,
   PRO_TRIM_SRF_OFFS_METH_MANUALSCALE = 3
} ProTrimSurfOffMethodOpts;

typedef enum _ProThinTrimAxesOption
{
    PRO_TRIM_OFFS_TRF_NONE = 0,
    PRO_TRIM_OFFS_TRF_X    = 1,
    PRO_TRIM_OFFS_TRF_Y    = 2,
    PRO_TRIM_OFFS_TRF_Z    = 4,
    PRO_TRIM_OFFS_TRF_XY   = 3,
    PRO_TRIM_OFFS_TRF_YZ   = 6,
    PRO_TRIM_OFFS_TRF_ZX   = 5,
    PRO_TRIM_OFFS_TRF_ALL  = 7
} ProThinTrimAxesOption;

typedef enum _ProThinTrimHandlingAction
{
    PRO_TRIM_OFFS_ACTION_LEAVE  = -1,
    PRO_TRIM_OFFS_ACTION_APPROX = 1
} ProThinTrimHandlingAction;



PRO_END_C_DECLS
#endif /* PRO_TRIM_H */
