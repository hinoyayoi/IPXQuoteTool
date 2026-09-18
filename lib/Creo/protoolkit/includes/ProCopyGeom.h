#ifndef PROCOPYGEOM_H
#define PROCOPYGEOM_H




/* Creo Parametric TOOLKIT declarations for Pro<object> related data structures */

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProDataShareFeat.h>

PRO_BEGIN_C_DECLS

  /*****************************************************************************
    ProCopiedRefStateDetails should be kept fully synchronized with ProRefState.
   *****************************************************************************/
typedef enum
{
  PRO_COPIED_REF_DETAILS_NOT_FOUND  =  0,   /* copied references are not found      */

  PRO_COPIED_REF_DETAILS_ACTIVE     =  1,   /* copied reference is dependent on 
                                       	       the "master" model and is up to date */
  
  
  PRO_COPIED_REF_DETAILS_EXCLUDED   =  3,   /* copied reference is dependent on
                                               which currently is excluded
                                               by Simp Rep or by Family Table.      */
  PRO_COPIED_REF_DETAILS_FROZEN     =  4,   /* copied reference is dependent on 
                                               the "master" model,
                                               which currently is not in the session */
  PRO_COPIED_REF_DETAILS_SUPPRESSED =  5,   /* copied reference is dependent on
                                               an entity which is suppressed 
                                               in the "master" model                 */
  PRO_COPIED_REF_DETAILS_MISSING    =  6,   /* copied reference is dependent on
                                               an entity which is missing
                                               in the "master" model                 */
  PRO_COPIED_REF_DETAILS_FROZEN_PLACE= 7,   /* copied reference cannot update
                                               its location                          */
  
  
  PRO_COPIED_REF_DETAILS_QUILT      =  10,  /* copied reference solidification failed
                                               and restored to quilt                */
  PRO_COPIED_REF_DETAILS_CHANGED    =  11,  /* Locally copied reference is outdated,
                                               as the reference geometry has been changed.
                                               This status is supported only for
                                               copied references with dependency
                                               status set to manual update. */
  PRO_COPIED_REF_DETAILS_NO_DEPENDENCY   =  12  /* the dependency driven by the copied
                                                   reference to the reference model
                                                   is broken */

} ProCopiedRefStateDetails;    /* state of local copy of external reference in 
                                  CopyGeom feature or in a feature with
                                  a local backup.
                                  Should be synchronized with ProRefState */

extern ProError ProFeatureCopiedRefStateDetailsGet(ProFeature               *feature,
                                                   ProCopiedRefStateDetails *p_copref_state_details);
/*
  Purpose:  Retrieves the status of copied references for the specified feature.
            <p>
            <b>NOTE:</b>
            <p>
            This functions works for CopyGeom features or features 
            with a local backup of references.

   Input Arguments:
     feature        - The handle to a feature to be checked.

   Output Arguments:
     p_copref_state_details - The current state of the feature's copied references.

   Return Values:
     PRO_TK_NO_ERROR     -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler.
     PRO_TK_E_NOT_FOUND    -  The feature is not of type PRO_FEAT_GEOM_COPY 
                            and has no local backup.
     PRO_TK_INVALID_TYPE  - The feature is not of type PRO_FEAT_GEOM_COPY 
                            and has no local backup.
     PRO_TK_NOT_VALID    -  Required license not found.
*/

/*
  DEPRECATED: Since Creo 3
  SUCCESSORS: ProCopiedRefStateDetails
*/
typedef enum
{
  PRO_COPIED_REF_NOT_FOUND  =  PRO_COPIED_REF_DETAILS_NOT_FOUND,
  /* copied references are not found      */

  PRO_COPIED_REF_ACTIVE     =  PRO_COPIED_REF_DETAILS_ACTIVE,
  /* copied reference is dependent on 
     the "master" model and is up to date */

  PRO_COPIED_REF_INDEPEND   =  2,
  /* copied reference is not dependent
     on the "master" model                */

  PRO_COPIED_REF_EXCLUDED   =  PRO_COPIED_REF_DETAILS_EXCLUDED,
  /* copied reference is dependent on
     which currently is excluded
     by Simp Rep or by Family Table.      */

  PRO_COPIED_REF_FROZEN     =  PRO_COPIED_REF_DETAILS_FROZEN,
   /* copied reference is dependent on 
      the "master" model,
      which currently is not in the session */

  PRO_COPIED_REF_SUPPRESSED =  PRO_COPIED_REF_DETAILS_SUPPRESSED,
  /* copied reference is dependent on
     an entity which is suppressed 
     in the "master" model                 */

  PRO_COPIED_REF_MISSING    =  PRO_COPIED_REF_DETAILS_MISSING,
  /* copied reference is dependent on
     an entity which is missing
     in the "master" model                 */

  PRO_COPIED_REF_FROZEN_PLACE = PRO_COPIED_REF_DETAILS_FROZEN_PLACE,
  /* copied reference cannot update
     its location                          */

  
  
  PRO_COPIED_REF_QUILT      =  PRO_COPIED_REF_DETAILS_QUILT
  /* copied reference solidification failed
     and restored to quilt                */

} ProCopiedRefState;    /* state of local copy of external reference in 
                           CopyGeom feature or in a feature with
                           a local backup.
                           Should be synchronized with ProRefState */

extern ProError ProFeatureCopiedRefStateGet(ProFeature        *feature,
                                            ProCopiedRefState *p_copref_state);
/*
  DEPRECATED: Since Creo 3
  SUCCESSORS: ProFeatureCopiedRefStateDetailsGet
  Purpose:  Retrieves the status of copied references for the specified feature.
            <p>
            <b>NOTE:</b>
            <p>
            This functions works for CopyGeom features or features 
            with a local backup of references.

   Input Arguments:
     feature        - The handle to a feature to be checked.

   Output Arguments:
     p_copref_state - The current state of the feature's copied references.

   Return Values:
     PRO_TK_NO_ERROR     -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler.
     PRO_TK_E_NOT_FOUND    -  The feature is not of type PRO_FEAT_GEOM_COPY 
                            and has no local backup.
     PRO_TK_INVALID_TYPE  - The feature is not of type PRO_FEAT_GEOM_COPY 
                            and has no local backup.
     PRO_TK_NOT_VALID    -  Required license not found.
*/

extern ProError ProFeatureHasBackup (ProFeature *feature,
                                     ProBoolean *p_has_backup);
/*
 Purpose:  Determines whether the specified feature has a local backup
           of external reference(s) created by the system due to the Reference 
           Control settings.
          <p>
          <b> NOTE: </b>CopyGeom features have no local backups of reference data.
          <p>

   Input Arguments:
     feature      - The handle to a feature to be checked.

   Output Arguments:
     p_has_backup - PRO_B_TRUE if the feature has a local
                    backup; otherwise PRO_B_FALSE.

   Return Values:
     PRO_TK_NO_ERROR    -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS  -  Invalid feature handler.
     PRO_TK_NOT_VALID   -  Required license not found.
*/

extern ProError ProFeatureCopyGeomDependSet (ProFeature *feature);

/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProFeatureDSFDependencystateSet
   Purpose:  <P>
             <B>NOTE:</B> This function is deprecated. Use ProFeatureDSFDependencystateSet() instead.</P>
             Sets copied references of the specified CopyGeom feature to be
             dependent on corresponding entities in the "master" model. This 
             means the copy's references are updated when the "master" model is
             changed.

   Input Arguments:
     feature        - The handle to a feature to be checked.

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR     -  The action has been performed successfully.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler.
     PRO_TK_INVALID_TYPE -  The feature is not of type PRO_FEAT_GEOM_COPY.
     PRO_TK_E_FOUND      -  Copied references in the specified feature are 
                            already dependent on the master model.
     PRO_TK_NOT_VALID    -  Required license not found.
*/

extern ProError ProFeatureCopyGeomInDependSet (ProFeature *feature);

/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProFeatureDSFDependencystateSet
   Purpose: <P>
            <B>NOTE:</B> This function is deprecated. Use ProFeatureDSFDependencystateSet() instead.</P>
            Sets copied references of the specified CopyGeom feature to be 
            independent of corresponding entities in the "master" model. This
            means the copy's references are not updated when the "master" model
            is changed.

   Input Arguments:
     feature        - The handle to a feature to be checked.

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR     -  The action has been performed successfully.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler.
     PRO_TK_INVALID_TYPE -  The feature is not of type PRO_FEAT_GEOM_COPY.
     PRO_TK_E_FOUND      -  Copied references in the specified feature are 
                            already independent of the master model.
     PRO_TK_NOT_VALID    -  Required license not found.
*/

extern ProError ProFeatureDSFDependencystateSet (ProFeature       *feature,
                                                 ProDSFDependency  dependency);

/*
   Purpose:  Sets dependency status of data sharing feature. This status govern
             how DSF will behave, if referenced items have changed: update 
             itself automatically or give "out of date" notification or do nothing
             waiting for user to check for updates or disconnect itself
             from source entirely, including not reporting dependency to PDM.

   Input Arguments:
     feature        - The handle to a feature to be checked.
     dependency     - Status to set. See ProDSFDependency in ProDataShareFeat.h

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR     -  The action has been performed successfully.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler.
     PRO_TK_INVALID_TYPE -  The feature is not of type PRO_FEAT_GEOM_COPY.
     PRO_TK_E_FOUND      -  Copied references in the specified feature have
                            the specified input dependency already set.
     PRO_TK_NOT_VALID    -  Required license not found.

   See Also:
         ProFeatureDSFDependencystateGet()
*/

extern ProError ProFeatureDSFDependencystateGet (ProFeature       *feature,
                                                 ProDSFDependency *r_dependency);
/*
   Purpose: Gets current dependency status from data sharing feature.

   Input Arguments:
     feature        - The handle to a feature to be checked.

   Output Arguments:
     r_dependency   - The current status. See ProDSFDependency in ProDataShareFeat.h

   Return Values:
     PRO_TK_NO_ERROR     -  The action has been performed successfully.
     PRO_TK_BAD_INPUTS   -  Invalid feature handler.
     PRO_TK_INVALID_TYPE -  The feature is not of type PRO_FEAT_GEOM_COPY.
     PRO_TK_NOT_VALID    -  Required license not found.

   See Also:
         ProFeatureDSFDependencystateSet()
*/

extern ProError ProFeatureDSFDependencyNotifySet(ProFeature         *feature,
                                                 ProDsfNotifyUpdate  notify_status);
/*

    Purpose: Set notification to visually indicate data sharing feature's source
             geometry change. This is applicable only for a data sharing feature
             with dependency status PRO_DSF_UPDATE_MANUALLY.
  
    Input Arguments:
        feature        - The handle to a feature.
        notify_status  - Notification status on/off.
   
    Output Arguments:
        None.
   
    Return Values:
        PRO_TK_NO_ERROR     -  The function succeeded.
        PRO_TK_BAD_INPUTS   -  One or more arguments is invalid.
        PRO_TK_INVALID_TYPE -  The feature is not of type PRO_FEAT_GEOM_COPY.
        PRO_TK_NOT_VALID    -  Required license not found.
        PRO_TK_BAD_CONTEXT  -  The feature dependency is not PRO_DSF_UPDATE_MANUALLY
   
    See Also:
        ProFeatureDSFDependencyNotifyGet()
        ProFeatureDSFDependencystateGet()
        ProFeatureDSFDependencystateSet()
*/

extern ProError ProFeatureDSFDependencyNotifyGet(ProFeature         *feature,
                                                 ProDsfNotifyUpdate *r_notify_status);
/*

    Purpose: Get current notification status to visually indicate data sharing
             feature's source geometry change. This is applicable only for a data
             sharing feature with dependency status PRO_DSF_UPDATE_MANUALLY.
  
    Input Arguments:
        feature         - The handle to a feature.
   
    Output Arguments:
        r_notify_status - Current Notification status.
   
    Return Values:
        PRO_TK_NO_ERROR     -  The function succeeded.
        PRO_TK_BAD_INPUTS   -  One or more arguments is invalid.
        PRO_TK_INVALID_TYPE -  The feature is not of type PRO_FEAT_GEOM_COPY.
        PRO_TK_NOT_VALID    -  Required license not found.
        PRO_TK_BAD_CONTEXT  -  The feature dependency is not PRO_DSF_UPDATE_MANUALLY
   
    See Also:
        ProFeatureDSFDependencyNotifySet()
        ProFeatureDSFDependencystateGet()
        ProFeatureDSFDependencystateSet()
*/


PRO_END_C_DECLS

#endif /* PROCOPYGEOM_H */
