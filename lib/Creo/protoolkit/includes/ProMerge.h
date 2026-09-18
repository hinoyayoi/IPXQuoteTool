#ifndef PRO_MERGE_H
#define PRO_MERGE_H

/*
   Creo Parametric TOOLKIT declarations related to Surface Merge feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*=============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |--PRO_E_FEATURE_TYPE
      |
      |--PRO_E_SRF_MRG_QUILT_ARR
      |   |
      |   |--PRO_E_SRF_MRG_QUILT_CMPD
      |       |
      |       |--PRO_E_SRF_MRG_QUILT_REF
      |       |--PRO_E_SRF_MRG_QUILT_SIDE
      |
      |--PRO_E_SRF_MRG_TYPE
      |--PRO_E_STD_FEATURE_NAME

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id                  Element Name          Data Type             
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type          PRO_VALUE_TYPE_INT          
 PRO_E_SRF_MRG_QUILT_ARR     Quilts                Array
 PRO_E_SRF_MRG_QUILT_CMPD    Quilt                 Compound
 PRO_E_SRF_MRG_QUILT_REF     Quilt                 PRO_VALUE_TYPE_SELECTION
 PRO_E_SRF_MRG_QUILT_SIDE    Quilt Side            PRO_VALUE_TYPE_INT
 PRO_E_SRF_MRG_TYPE          Merge Type            PRO_VALUE_TYPE_INT
 PRO_E_STD_FEATURE_NAME      Feature Name          PRO_VALUE_TYPE_WSTRING
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                  Element Name          Valid Values                 
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type          PRO_FEAT_DATUM_QUILT
 PRO_E_SRF_MRG_QUILT_ARR     Quilts                Array element
 PRO_E_SRF_MRG_QUILT_CMPD    Quilt                 Compound element
 PRO_E_SRF_MRG_QUILT_REF     Quilt                 PRO_QUILT
 PRO_E_SRF_MRG_QUILT_SIDE    Quilt Side            ProSrfMrgQltSide
 PRO_E_SRF_MRG_TYPE          Merge Type            ProSrfMrgType
 PRO_E_STD_FEATURE_NAME      Feature Name          See Note-4
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                                      Comment
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE                                Mandatory
 PRO_E_SRF_MRG_QUILT_ARR                           Array element (Note-1)
 PRO_E_SRF_MRG_QUILT_CMPD                          Compound element
 PRO_E_SRF_MRG_QUILT_REF                           Mandatory
 PRO_E_SRF_MRG_QUILT_SIDE                          Optional (Note-2)
 PRO_E_SRF_MRG_TYPE                                Optional (Note-2, Note-3)
 PRO_E_STD_FEATURE_NAME                            Optional (Note-4)
===============================================================================

(5) Notes

   Note-1 : Must have at least two elements to create a feature.

   Note-2 : Unavailible when the "Quilts" array contains more than 2 elements.

   Note-3 : Default Merge Type is PRO_MRG_TYPE_INTERSECT.

   Note-4 : Merge feature name.
            Default value is "SURFACE_MERGE".

=============================================================================*/

/*
(6) Enum Declarations
*/

/* ==================== */
/* Merge Type Options   */
/* ==================== */

typedef enum pro_srf_mrg_type
{
   PRO_SRF_MRG_JOIN   = 1,
   PRO_SRF_MRG_INTSCT = 2
} ProSrfMrgType;

/* ==================== */
/* Side options of Merge: */
/* ==================== */

typedef enum pro_srf_mrg_qlt_side
{
   PRO_SRF_MRG_QLT_SIDE_1 =  1,
   PRO_SRF_MRG_QLT_SIDE_2 = -1
} ProSrfMrgQltSide;


/*=============================================================================
  Legacy Surface Merge element tree.
=============================================================================*/
/*=============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |--PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_SRF_MRG_PRNT_QLT
      |
      |-- PRO_E_SRF_MRG_ADTL_QLT
      |
      |-- PRO_E_SRF_MRG_TYPE
      |
      |-- PRO_E_SRF_MRG_PRNT_QLT_SIDE
      |
      |-- PRO_E_SRF_MRG_ADTL_QLT_SIDE
      |
      |-- PRO_E_STD_FEATURE_NAME

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id                  Element Name          Data Type             
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type          PRO_VALUE_TYPE_INT          
 PRO_E_SRF_MRG_PRNT_QLT      Parent Quilt          PRO_VALUE_TYPE_SELECTION
 PRO_E_SRF_MRG_ADTL_QLT      Additional Quilt      PRO_VALUE_TYPE_SELECTION
 PRO_E_SRF_MRG_TYPE          Merge Type            PRO_VALUE_TYPE_INT
 PRO_E_SRF_MRG_PRNT_QLT_SIDE Parent Quilt Side     PRO_VALUE_TYPE_INT
 PRO_E_SRF_MRG_ADTL_QLT_SIDE Additional Quilt Side PRO_VALUE_TYPE_INT
 PRO_E_STD_FEATURE_NAME      Feature Name          PRO_VALUE_TYPE_WSTRING
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                  Element Name          Valid Values                 
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type          PRO_FEAT_DATUM_QUILT
 PRO_E_SRF_MRG_PRNT_QLT      Parent Quilt          PRO_QUILT
 PRO_E_SRF_MRG_ADTL_QLT      Additional Quilt      PRO_QUILT
 PRO_E_SRF_MRG_TYPE          Merge Type            ProSrfMrgType
 PRO_E_SRF_MRG_PRNT_QLT_SIDE Parent Quilt Side     ProSrfMrgQltSide
 PRO_E_SRF_MRG_ADTL_QLT_SIDE Additional Quilt Side ProSrfMrgQltSide
 PRO_E_STD_FEATURE_NAME      Feature Name          See Note-4
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                                        Comment
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE                                  Mandatory
 PRO_E_SRF_MRG_PRNT_QLT                              Mandatory
 PRO_E_SRF_MRG_ADTL_QLT                              Mandatory
 PRO_E_SRF_MRG_TYPE                                  Optional(Note-3)
 PRO_E_SRF_MRG_PRNT_QLT_SIDE                         Optional
 PRO_E_SRF_MRG_ADTL_QLT_SIDE                         Optional
 PRO_E_STD_FEATURE_NAME                              Optional(Note-4)
===============================================================================

=============================================================================*/

PRO_END_C_DECLS
#endif /* PRO_MERGE_H */
