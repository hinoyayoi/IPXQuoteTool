#ifndef PROREMOVESURFH
#define PROREMOVESURFH



#include <ProToolkit.h>
#include <ProExclCntrs.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_RM_SURF_REF_TYPE
      |
      |-- PRO_E_RM_SURF_ATTACH_TYPE
      |
      |-- PRO_E_RM_SURF_SRF_REFS
      |    |
      |    |-- PRO_E_STD_SURF_COLLECTION_APPL
      |    |
      |    |-- PRO_E_STD_EXCL_CNTRS
      |    |    |
      |    |    |-- PRO_E_STD_EXCL_CNTRS_ONE_CNTR
      |    |         |
      |    |         |-- PRO_E_STD_EXCL_CNTR_SRF_REF      
      |    |         |
      |    |         |-- PRO_E_STD_EXCL_CNTR_EDGE_REF      
      |    |
      |    |-- PRO_E_KEEP_REMOVED_SRFS_OPT
      |    
      |-- PRO_E_RM_SURF_CRV_REFS
      |    |
      |    |-- PRO_E_STD_CURVE_COLLECTION_APPL      
      |
      |-- PRO_E_RM_SURF_LEAVE_OPEN_OPT
      |
      |-- PRO_E_RM_SURF_AUTO_SPLIT_SRF
      |
      |-- PRO_E_RM_SURF_MAINTAIN_TOPO
     
===============================================================================

(2) Feature elements table

---------------------------------------------------------------------------------------------------
Element Id                     Element Name                  Data Type                 Valid Values
---------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type               PRO_VALUE_TYPE_INT        PRO_FEAT_RM_SURF
PRO_E_STD_FEATURE_NAME            Feature Name               PRO_VALUE_TYPE_WSTRING    Wide character string
PRO_E_RM_SURF_REF_TYPE            Reference type             PRO_VALUE_TYPE_INT        Note-1
PRO_E_RM_SURF_ATTACH_TYPE         Attachment type            PRO_VALUE_TYPE_INT        Note-2
PRO_E_RM_SURF_SRF_REFS            Surface references         Compound                  Note-3
PRO_E_STD_SURF_COLLECTION_APPL    Exclude surfaces           PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_STD_EXCL_CNTRS              Exclude loop               Array                     Note-5
PRO_E_RM_SURF_CRV_REFS            Curve-chain references     Compound                  Note-6
PRO_E_STD_CURVE_COLLECTION_APPL   Chains to remove           PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_KEEP_REMOVED_SRFS_OPT       Keep removed surfaces      PRO_VALUE_TYPE_BOOLEAN
PRO_E_RM_SURF_LEAVE_OPEN_OPT      Leave open                 PRO_VALUE_TYPE_BOOLEAN
PRO_E_RM_SURF_AUTO_SPLIT_SRF      Auto split shape surfaces  PRO_VALUE_TYPE_BOOLEAN
PRO_E_RM_SURF_MAINTAIN_TOPO       Maintain Solution Topology PRO_VALUE_TYPE_BOOLEAN    Note-8
===============================================================================

(3) Notes

   Note-1 : Value type is ProRmSurfRefType. The value of this element determines which
            references compound (PRO_E_RM_SURF_SRF_REFS/PRO_E_RM_SURF_CRV_REFS) is visible.
   
   Note-2 : Value type is ProRmSurfAttachType. The value of this element determines whether
            the geometry of the feature will created as a separate quilt or will be attached   
            to the selected surface/quilt.         
   
   Note-3 : Compound of surface references. 
            This element is required if PRO_E_RM_SURF_REF_TYPE is PRO_RM_SURF_SRF_REF.
   
   Note-4 : Select the surfaces to be removed from the part. 
            Multiple selection allowed. This element is required provided 
            PRO_E_RM_SURF_SRF_REFS compound is visible. See Note-1.
   
   Note-5 : Array of excluded contours. Optional. See ProExclCntrs.h
   
   Note-6 : Compound of crv references.
            This element is required if PRO_E_RM_SURF_REF_TYPE is PRO_RM_SURF_CRV_REF.

   Note-7 : Select a single closed loop of one sided edges. This element is required provided 
            PRO_E_RM_SURF_CRV_REFS compound is visible. See Note-1. 

   Note-8:  Value type is ProBool.
                                    
            If PRO_B_TRUE - The system will always attempt to generate feature geometry 
                            that is topologically similar to the solution selected by the 
                            user (The solution set using "Next/Previous" buttons in the 
                            feature UI). If such a solution cannot be created - the 
                            feature will fail.
 
            If PRO_B_FALSE  - The system will attempt to generate geometry that is
                              topologically similar to the solution selected by the user,
                              however if such a solution cannot be created - the system 
                              will attempt to generate ANY successful solution. If no
                              successful solution can be generated - the feature will 
                              fail.

==============================================================================*/


typedef enum pro_rm_surf_ref_type
{
   PRO_RM_SURF_SRF_REF  = 0,
   PRO_RM_SURF_CRV_REF  = 1
} 
ProRmSurfRefType;

typedef enum pro_rm_surf_attach_type
{
   FM_RM_SURF_ATTACH_SAME  = 2,
   FM_RM_SURF_ATTACH_SEP   = 3
} 
ProRmSurfAttachType;

PRO_END_C_DECLS

#endif
