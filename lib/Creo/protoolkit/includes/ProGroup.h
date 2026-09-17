#ifndef PROGROUP_H
#define PROGROUP_H

/* Creo Parametric TOOLKIT declarations for ProGroup related actions */

#include <ProObjects.h>




PRO_BEGIN_C_DECLS

typedef struct pro_model_item ProGroup;

/*===========================================================================*/
extern ProError ProLocalGroupCreate (ProSolid   solid,
                                     int       *feat_ids,
                                     int        n_feats,
                                     ProName    local_gp_name,
                                     ProGroup  *r_group);
/*
   Purpose:  Creates a local group out of the specified set of features.
	     <p>
	     NOTE:
	     <p>
             The supplied features should represent a contiguous
             set of features in the specified part or assembly. 

   Input Arguments:
      solid         - The part or assembly.
      feat_ids      - The <i>ProArray</i> of feature identifiers to be grouped.
                      They <i>must</i> be a contiguous set of features.
      n_feats       - The number of features to be grouped.
      local_gp_name - The name to be assigned to the created local group.

   Output Arguments:
      r_group        - The local group object.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created the requested
                          local group.
      PRO_TK_BAD_INPUTS - The specified data is invalid.
*/


/*===========================================================================*/
extern ProError ProGroupUngroup (ProGroup *group);
/*
   Purpose:  Dissolves a local group.
	     
   Input Arguments:
      group        - The group object.
      
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully dissolved the 
                          local group.
      PRO_TK_BAD_INPUTS - The input group is invalid.
*/

typedef ProError (*ProGroupUngroupPreAction) (ProGroup* group);
/*
    Purpose: This is the notification function prototype that should be used 
             for a notification corresponding to the ProNotifyType 
             PRO_GROUP_UNGROUP_PRE.

    Input Arguments:
        group - The feature group or UDF that is about to be ungrouped.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Proceed with the ungroup action.
        Any other value - Cancel the ungroup action.  The Creo Parametric TOOLKIT
                          application may supply an explanation to the user
                          via the user interface if the action is being cancelled.

    See Also:
        ProNotificationSet()
*/

typedef ProError (*ProGroupUngroupPostAction) (ProSolid solid, int group_id, ProName udf_name, int* feature_list);
/*
    Purpose: This is the function prototype used for a notification called 
             after a feature group is ungrouped, corresponding to the 
             ProNotifyType PRO_GROUP_UNGROUP_POST

    Input Arguments:
        solid - The solid model that owned the group.
        group_id - The former group id.
        udf_name - The UDF name, if the group was from a UDF, or NULL.
        feature_list - Ids of the features that were members of the group.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - Return values are not interpreted by Creo Parametric.

    See Also:
        ProNotificationSet()
*/

PRO_END_C_DECLS

#endif /* PROGROUP_H */
