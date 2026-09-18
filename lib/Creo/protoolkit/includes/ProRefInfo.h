#ifndef PROREFINFO_H
#define PROREFINFO_H




/* Creo Parametric TOOLKIT declarations for Pro<object> related data structures */

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProCopyGeom.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_EXT_GEOM_REF    = 1,       /* all out of solid references,
                                    created in assembly context, kept in
                                      plins, sections, draft sections        */
  PRO_LOC_GEOM_REF    = 2,       /* local for solid references, kept in
                                      plins, sections, draft sections        */
  PRO_MERGE_REF       = 3,       /* reference models of merge by ref feats  */
  PRO_EXT_REL_REF     = 4,       /* out of solid references, , kept in
                                      symbols used for relations.
                                      Can be "to solid" or feature,
                                      geometry references.                   */
  PRO_LOC_REL_REF     = 5,       /* local for solid references, kept in
                                      symbols used for relations.
                                      Can be "to solid" or feature, 
                                      geometry references.                   */
  PRO_PRGM_REF        = 6,       /* out of solid references, , kept in
                                      symbols used in Pro/Program.
                                      Always solid references                */
  PRO_MOVE_COMP_REF   = 7,       /* Move Components external references.
                                     Kept in components and always "to solid".
									 This reference is not present in models 
									 created after Creo Elements/Pro 5.0    */
  PRO_SUBS_REF        = 8,       /* Substitute Component references.
                                     Kept in components and always "to solid"*/
  PRO_MFG_INFO_REF    = 9,       /* Mfg Info references.  Kept in
                                     mfg feat, always "to solid"             */
  PRO_INTRCH_REF      = 10,      /* Interchange Assembly references.
                                      Kept in the solid itself.
                                      Always "to solid"                      */
  PRO_HARN_REF        = 11,      /* Harness references.
                                      Kept in the solid itself.
                                      Always "to solid"                      */
  PRO_FEAT_PAT_REF    = 12,      /* Feature pattern references.
                                     Does not include pattern relation
                                     references.  Always "to solid"          */
  PRO_NON_ASSY_GEOM_REF = 13,    /* Out of solid external geometry refs,
                                    created not in assembly context,
                                    kept in plins. (used in external geom
                                    copy feature).                           */
  PRO_DIM_BOUND_REF     = 14,    /* Dim. bound references.
                                    Kept in the solid itself.
                                    Always "to solid"                        */
  PRO_HIDDEN_FEM_REFS   = 15,    /* Hidden Simulate features references.
                                    Kept in the solid itself.
                                    Always "to solid"                        */
  PRO_ANALYSIS_REF      = 16,    /* Hidden analysis features references.
                                    Kept in the solid itself.
                                    Always "to solid"                        */
  PRO_FEAT_PAT_LOC_REF  = 17,    /* References between pat. leader and member
                                    or between pat. group headers            */
  PRO_DEPENDENCY_REFS   = 18,    /* All types of references collected via
                                    collect dependencies mechanism. This type 
									is not included in COLL_ALL_REFS_TYPE, it 
									should be invoked separately.            */
  PRO_IN_CIRCLE_REFS    = 19,    /* References encountered in assembly loops. 
									This is reserved for future use			 */                                  
  PRO_MEMBER_REFS       = 20,    /* Component models of assembly members. 
									This type is not included in 
									COLL_ALL_REFS_TYPE, it should be invoked 
									separately.								 */
  PRO_LOC_MERGE_REF     = 21,    /* Merge reference of mirror geom. 
                                    Always "to solid"                        */
  PRO_ALL_EXT_REF_TYPES = 100,   /* Same as PRO_ALL_REF_TYPES except for 
									PRO_LOC_GEOM_REF, PRO_LOC_REL_REF, 
									PRO_LOC_MERGE_REF, PRO_FEAT_PAT_LOC_REF  */
  PRO_ALL_REF_TYPES     = 101    /* All known types of references, except for
									PRO_DEPENDENCY_REFS,PRO_IN_CIRCLE_REFS and
									PRO_MEMBER_REFS.			             */
} ProExtRefType;                 /* types of references */


  /******************************************************************************
    ProRefState should be kept fully synchronized with ProCopiedRefStateDetails.
   *****************************************************************************/
typedef enum
{
  PRO_REF_NOT_FOUND  = PRO_COPIED_REF_DETAILS_NOT_FOUND,
                           /* references are not found                       */

  PRO_REF_ACTIVE     = PRO_COPIED_REF_DETAILS_ACTIVE,
                           /* referenced entity on the "master" model
                              is up to date                                  */
  PRO_REF_EXCLUDED   = PRO_COPIED_REF_DETAILS_EXCLUDED,
                           /* "master" model currently is excluded
                               by Simp Rep or by Family Table.               */
  PRO_REF_FROZEN     = PRO_COPIED_REF_DETAILS_FROZEN,
                           /* "master" model currently is not in the session */

  PRO_REF_SUPPRESSED = PRO_COPIED_REF_DETAILS_SUPPRESSED,
                           /* referenced entity is suppressed
                              in the "master" model                          */
  PRO_REF_MISSING    = PRO_COPIED_REF_DETAILS_MISSING,
                           /* referenced entity is missing
                              in the "master" model                          */
  PRO_REF_FROZEN_PLACE=PRO_COPIED_REF_DETAILS_FROZEN_PLACE,
                           /* referenced entity on the "master" model
                              is up to date but location of
                              "target" model according to "master" model
                              can not be updated                             */
  PRO_REF_INVALID     = 8,
                           /* Referenced entity is not valid. For example:
                              - Straight edge becomes non straight;
                              - Planar surface becomes non planar; */        
  PRO_REF_ALTERNATE   = 9,

  PRO_REF_QUILT       = PRO_COPIED_REF_DETAILS_QUILT  

} ProRefState;           /* state of referenced entity in the "master" model */


typedef enum _pro_dep_report_type
{
  PRO_REPORT_TYPE_CSV,
  PRO_REPORT_TYPE_XML
} ProDepReportType;

/* NOTE: values 2, 11, 12  are intentionally skipped in ProRefState for
         consistency sake with ProCopiedRefStateDetail. ProRefState should be
         synchronized with ProCopiedRefStateDetail 			    */ 

typedef struct ext_feat_ref *ProExtFeatRef; /* opaque pointer */

typedef struct 
{
   ProExtRefType    type;
   ProExtFeatRef   *ext_refs;
   int              n_refs;
} ProExtRefInfo;

extern ProError ProFeatureExternChildrenGet   (ProFeature     *feature,
                                               ProExtRefType   child_type,
                                               ProExtRefInfo **r_child_infos,
                                               int            *n_infos);
/*
   Purpose:   Collect data on external (and local) children of the specified 
              feature according to the specified reference type.

   Input Arguments:
     feature        - The handle to a feature to be checked.
     child_type     - The type of required references.
                      PRO_ALL_REF_TYPES means both local and external references
                      will be collected.
                      PRO_LOC_GEOM_REF, PRO_LOC_REL_REF, PRO_FEAT_PAT_LOC_REF 
                      and PRO_LOC_MERGE_REF means only local references will
                      be collected. The rest types causes only external 
                      references to be collected.

   Output Arguments:
     r_child_infos  - Array of children found.  Allocated inside function
                      when any children are of child_type are found.
     n_infos        - Number of elements in r_child_infos.

   Return Values:
     PRO_TK_NO_ERROR     -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler or invalid reference type,
                            r_child_infos is NULL, or n_infos is NULL.
     PRO_TK_NOT_VALID    -  Required license not found.
     PRO_TK_E_NOT_FOUND  -  No children of child_type are found.
     PRO_TK_E_IN_USE     -  (*r_infos) is not NULL.
     PRO_TK_OUT_OF_MEMORY - There are too many references in model to fit them
                            into an array. Some references will be excluded.
     PRO_TK_GENERAL_ERROR - The operation failed.
*/

extern ProError ProFeatureExternParentsGet    (ProFeature     *feature,
                                               ProExtRefType   parent_type,
                                               ProExtRefInfo **r_parent_infos,
                                               int            *n_infos);
/*
   Purpose:   Collect data on external (and local) parents of the specified 
              feature according to the specified reference type.

   Input Arguments:
     feature        - The handle to a feature to be checked.
     parent_type    - The type of required references.
                      PRO_ALL_REF_TYPES means both local and external references
                      will be collected.
                      PRO_LOC_GEOM_REF, PRO_LOC_REL_REF, PRO_FEAT_PAT_LOC_REF 
                      and PRO_LOC_MERGE_REF means only local references will
                      be collected. The rest types causes only external 
                      references to be collected.

   Output Arguments:
     r_parent_infos - Array of parents found.  Allocated inside function
                      when any parents are of parent_type are found.
     n_infos        - Number of elements in r_parent_infos.

   Return Values:
     PRO_TK_NO_ERROR     -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler or invalid reference type,
                            or r_parent_infos is NULL, or n_infos is NULL.
     PRO_TK_NOT_VALID    -  Required license not found.
     PRO_TK_E_NOT_FOUND  -  No parents of parent_type are found.
     PRO_TK_E_IN_USE     -  (*r_infos) is not NULL.
     PRO_TK_OUT_OF_MEMORY - There are too many references in model to fit them
                            into an array. Some references will be excluded.
     PRO_TK_GENERAL_ERROR - The operation failed.
*/

extern ProError ProSolidExternChildrenGet     (ProSolid        solid,
                                               ProExtRefType   child_type,
                                               ProExtRefInfo **r_child_infos,
                                               int            *n_infos);
/*
   Purpose:   Collect data on external children of the features of the specified
              solid according to the specified reference type. <p><b>Note:</b>This
              function requires the Pro/ASSEMBLY module license. This 
              functionality is only available in the Global Reference Viewer, 
              available under that license.

   Input Arguments:
     solid          - The handle to a solid to be checked.
     child_type     - The type of required references.
                      PRO_ALL_REF_TYPES means both local and external references
                      will be collected.
                      PRO_LOC_GEOM_REF, PRO_LOC_REL_REF, PRO_FEAT_PAT_LOC_REF 
                      and PRO_LOC_MERGE_REF means only local references will
                      be collected. The rest types causes only external 
                      references to be collected.

   Output Arguments:
     r_child_infos  - Array of children found.  Allocated inside function
                      when any children are of child_type are found.
     n_infos        - Number of elements in r_child_infos.

   Return Values:
     PRO_TK_NO_ERROR     -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS   -  Invalid solid handler or invalid reference type,
                            or r_child_infos is NULL, or n_infos is NULL.
     PRO_TK_NOT_VALID    -  Required license not found.
     PRO_TK_E_NOT_FOUND  -  No children of child_type are found.
     PRO_TK_E_IN_USE     -  (*r_infos) is not NULL.
     PRO_TK_OUT_OF_MEMORY - There are too many references in model to fit them
                            into an array. Some references will be excluded.
     PRO_TK_GENERAL_ERROR - The operation failed.
*/

extern ProError ProSolidExternParentsGet      (ProSolid        solid,  
                                               ProExtRefType   parent_type,
                                               ProExtRefInfo **r_parent_infos,
                                               int            *n_infos);
/*
   Purpose:  Collect data on external parents of the features of the specified
             solid according to the specified reference type. <p><b>Note:</b>This
             function requires the Pro/ASSEMBLY module license. This functionality
             is only available in the Global Reference Viewer, available under 
             that license.

   Input Arguments:
     solid          - The handle to a solid to be checked.
     parent_type    - The type of required references.
                      PRO_ALL_REF_TYPES means both local and external references
                      will be collected.
                      PRO_LOC_GEOM_REF, PRO_LOC_REL_REF, PRO_FEAT_PAT_LOC_REF 
                      and PRO_LOC_MERGE_REF means only local references will
                      be collected. The rest types causes only external 
                      references to be collected.

   Output Arguments:
     r_parent_infos - Array of parents found.  Allocated inside function
                      when any parents are of parent_type are found.
     n_infos        - Number of elements in r_parent_infos.

   Return Values:
     PRO_TK_NO_ERROR     -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS   -  Invalid solid handler or invalid reference type,
                            or r_parent_infos is NULL, or n_infos is NULL.
     PRO_TK_NOT_VALID    -  Required license not found.
     PRO_TK_E_NOT_FOUND  -  No parents of parent_type are found.
     PRO_TK_E_IN_USE     -  (*r_infos) is not NULL.
     PRO_TK_OUT_OF_MEMORY - There are too many references in model to fit them
                            into an array. Some references will be excluded.
     PRO_TK_GENERAL_ERROR - The operation failed.
*/

extern ProError ProExtRefInfoFree (ProExtRefInfo  **p_ext_feat_ref_arr);
/*
   Purpose:  Releases the memory allocated to the specified array of external
             reference data for a feature or a solid. 

   Input Arguments:
     p_ext_feat_ref_arr - The pointer to array of external reference data
                          returned by a ProFeature or ProSolid external  
                          reference "get" such as ProSolidExternChildrenGet.

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully released
                           the specified array.

      PRO_TK_BAD_INPUTS  - p_ext_feat_ref_arr is NULL.
*/

/* Functions to get data from  ProExtFeatRef : */

extern ProError ProExtRefTypeGet (ProExtFeatRef    ext_ref,
                                  ProType         *r_ref_type);
/*
   Purpose:  Gets type of the external (or local) reference.

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      r_ref_type        - Type of specified reference.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully got the reference type.
      PRO_TK_E_NOT_FOUND - The type of reference is not found.
      PRO_TK_BAD_INPUTS  - ext_ref is NULL or bad pointer.
*/

extern ProError ProExtRefAsmcompsGet (ProExtFeatRef     ext_ref,
                                      ProAsmcomppath   *own_comp,
                                      ProAsmcomppath   *ref_comp);
/*
   Purpose:  Gets from the external reference a path to the component from which 
             the reference was created. Also returns a path to the component 
             that owns the specified external reference.

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      own_comp          - Handle to path to model to be initialized that uses 
                          the specified reference. Can be NULL.

      ref_comp          - Handle to path to top-level (master) model 
                          to be initialized. This is the model in which
                          the specified reference was created.  
                          Can be NULL. 

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully returned the information.
      PRO_TK_BAD_INPUTS    - ext_ref is NULL or bad pointer.
      PRO_TK_E_NOT_FOUND   - own_comp or ref_comp not found in current session.
      PRO_TK_GENERAL_ERROR - The operation failed.
*/

extern ProError ProExtRefOwnMdlGet (ProExtFeatRef    ext_ref,
                                    ProSolid        *p_ref_owner);
/*
   Purpose:  Gets from the external reference a solid that is active in the
             current session and that uses the reference. 

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      p_ref_owner       - Pointer to the model which uses the reference.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - ext_ref is NULL or bad pointer.
      PRO_TK_E_NOT_FOUND  - Required model not found in current session.
*/

extern ProError ProExtRefMdlGet (ProExtFeatRef    ext_ref,
                                ProSolid         *p_ref_model);
/*
   Purpose:  Gets from the external reference a solid that is active in the current 
             session and that is referred to by the specified reference.

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      p_ref_model       - Pointer to the model which was referenced.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - ext_ref is NULL or bad pointer.
      PRO_TK_E_NOT_FOUND  - Required model not found in current session.
*/

extern ProError ProExtRefOwnFeatGet (ProExtFeatRef    ext_ref,
                                     ProFeature      *p_own_feat);
/*

   Purpose:  Gets from the external reference a feature that uses the reference. 

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      p_own_feat        - The handle to the feature which uses the reference.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - ext_ref is NULL or bad pointer.
      PRO_TK_E_NOT_FOUND  - The reference is used by solid itself and not
                            by some specific feature.
*/

extern ProError ProExtRefFeatGet (ProExtFeatRef    ext_ref,
                                  ProFeature      *p_ref_feat);
/*
   Purpose:  Gets from the external reference a feature that is referred to by
             the external reference.

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      p_ref_feat        - The referenced feature handle to be initialized.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - ext_ref is NULL or bad pointer.
      PRO_TK_E_NOT_FOUND  - The reference does not belong to any existing 
                            component in the "master" model feature.
*/

extern ProError ProExtRefModelitemGet (ProExtFeatRef    ext_ref,
                                       ProModelitem    *p_ref_item);
/*
   Purpose:  Gets from the external reference a model item that is referred to
             by the external reference.

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      p_ref_item        - The item handle to be initialized.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - ext_ref is NULL or bad pointer.
      PRO_TK_E_NOT_FOUND  - The referenced item is not active.
*/

extern ProError ProExtRefStateGet (ProExtFeatRef    ext_ref,
                                   ProRefState     *p_ref_state);
/*
   Purpose:  Retrieves the external reference status of the referenced item of 
             the specified reference. 

   Input Arguments:
      ext_ref           - The opaque pointer to the feature reference
                          structure.

   Output Arguments:
      p_ref_state       - The current state of the referenced item in
                          the "master" model.

   Return Values:
      PRO_TK_NO_ERROR     -  The function successfully returned the information.
      PRO_TK_BAD_INPUTS   -  ext_ref is NULL or bad pointer.
      PRO_TK_GENERAL_ERROR - The operation failed.
*/

extern ProError ProExtRefInfoExport (ProExtRefInfo     *info_arr,
                                     ProPath            w_fname,
                                     ProDepReportType   n_rep_type);
/*
   Purpose:  Prints out dependency report in different formats.

   Input Arguments:
      info_arr          - Collected references from ProSolidExternParentsGet /
                          ProFeatureExternParentsGet called with PRO_DEPENDENCY_REFS
                          flag (not PRO_ALL_EXT_REF_TYPES/PRO_ALL_REF_TYPES).
                          Array, must be freed by caller. References that are
                          not dependencies will be ignored.
      w_fname           - File name to print report to.
      n_rep_type        - Type of report format. Currently only csv and basic
                          XML are supported.

   Output Arguments:
      NONE

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully performed the operation.
      PRO_TK_CANT_OPEN    - Can not open report file.
      PRO_TK_E_NOT_FOUND  - Unrecognized report type.
*/

extern ProError ProExtRefIsDependency (ProExtFeatRef    p_ext_ref,
                                       ProBool         *r_status);
/*
   Purpose:  Returns indication whether given reference is dependency.

   Input Arguments:
      p_ext_ref         - The opaque pointer to the feature reference
                          structure, taken from output of
                          ProSolidExternParentsGet / ProFeatureExternParentsGet.

   Output Arguments:
      r_status          - Pointer to status indicating whether reference
                          is dependency.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully performed the operation.
      PRO_TK_BAD_INPUTS   - If no reference was given (NULL pointer).
*/

extern ProError ProExtRefDependencyIsBreakable (ProExtFeatRef *ext_ref_arr,
                                                ProBool       *r_status);
/*
   Purpose:  Returns indication that some of the given dependencies can be broken.

   Input Arguments:
      ext_ref_arr       - The array of opaque pointers to the feature reference
                          structure, taken from output of
                          ProSolidExternParentsGet / ProFeatureExternParentsGet.

   Output Arguments:
      r_status          - Pointer to status indicating whether dependency
                          is breakable.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully performed the operation.
      PRO_TK_BAD_INPUTS   - If no references was given (NULL pointer or empty array).

*/

extern ProError ProExtRefBreakDependency (ProExtFeatRef *ext_ref_arr);
/*
   Purpose:  From given proarray of references, break those which are breakable.

   Input Arguments:
      ext_ref_arr       - The array of opaque pointers to the feature reference
                          structure.

   Output Arguments:
      NONE

   Return Values:
      PRO_TK_NO_ERROR     -  The function successfully performed the operation.
      PRO_TK_BAD_INPUTS   - If no references was given (NULL pointer or empty array).
*/

PRO_END_C_DECLS

#endif /* PROREFINFO_H */
