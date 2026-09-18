#ifndef PROVARIANTFEAT_H_
#define PROVARIANTFEAT_H_


/* Creo Parametric TOOLKIT declarations for Inheritance/Flexible feature related actions */

#include <ProObjects.h>
#include <ProParameter.h>
#include <ProReference.h>
#include <ProModelitem.h>
#include <ProAsmcomppath.h>



PRO_BEGIN_C_DECLS

typedef void* ProVariantref;

extern ProError ProVariantfeatMdlGet (ProFeature* feature, ProMdl* mdl);
/*
    Purpose: Obtains a special model pointer from an inheritance feature or 
             flexible component.  This pointer is  for use in accessing 
             properties that can be modified by the presence of an inheritance 
             feature or flexible component.  Other functions will return an 
             error if provided with this pointer.  To read or modify values not 
             accessible from this pointer, retrieve the parent model using the 
             model name and type using ProMdlRetrieve() or the equivalent.  
             Consult the Creo Parametric TOOLKIT User's Guide for details on the functions 
             that are supported by this pointer.
             

    Input Arguments:
        feature - The variant feature.

    Output Arguments:
        mdl - The inheritance feature model handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or arguments was invalid.

*/

extern ProError ProMdlIsVariantfeatMdl (ProMdl mdl, 
                                        ProBoolean* is_var_feat_mdl);
/*
    Purpose: Identifies if a model pointer is from an inheritance feature or 
             flexible component.

    Input Arguments:
        mdl - The model handle.

    Output Arguments:
        is_var_feat_mdl - PRO_B_TRUE if the model is obtained from a variant  
                          feature.  

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or arguments was invalid.

    See Also:
        ProVariantfeatMdlGet()
*/


extern ProError ProVariantfeatItemStandardize (ProFeature* variant_feature, 
                                               ProModelitem* varied_item);
/*
    Purpose: Removes a varied item from the inheritance feature or flexible 
             component.

    Input Arguments:
        variant_feature - The variant feature handle.
        varied_item - The item which is currently varied in the feature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The item is not varied in the feature.

*/


extern ProError ProVariantfeatItemCopyGet (ProFeature* feature, 
                                           ProModelitem* item, 
                                           ProBoolean* copy);
/*
    Purpose: Obtains the copy flag for a given item in the inheritance feature 
             or flexible component.

    Input Arguments:
        feature - The variant feature
        item - The item.

    Output Arguments:
        copy - Whether or not to copy the item into the variant feature.  If 
               set, this overrides the "copy all" setting for the feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The item is not varied in the feature.
        PRO_TK_E_NOT_FOUND - The copy flag is not set (so the behavior is 
                             governed by the feature's "copy all" flag).

*/

extern ProError ProVariantfeatItemCopySet (ProFeature* feature, 
                                           ProModelitem* item, 
                                           ProBoolean copy);
/*
    Purpose: Assigns the copy flag for a given item in the inheritance feature 
             or flexible component.  After making a change using this 
	     function, you should regenerate the feature's owner to
	     completely update the status of the item.

    Input Arguments:
        feature - The variant feature
        item - The item.  If the item is not currently varied in the feature 
               this will force it to become varied.
        copy - Whether or not to copy the item into the variant feature.  If 
               set, this overrides the "copy all" setting for the feature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProSolidRegenerate()

*/

extern ProError ProVariantfeatItemCopyUnset (ProFeature* feature, 
                                             ProModelitem* item);
/*
    Purpose: Removes the copy flag for a given item in the inheritance feature 
             or flexible component.

    Input Arguments:
        feature - The variant feature
        item - The item.  

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The item is not currently varied in the feature.

*/

extern ProError ProVariantfeatItemsVisit (ProFeature* feature, 
                                         ProModelitemVisitAction visit_action, 
                                         ProModelitemFilterAction filter_action, 
                                         ProAppData application_data);
/*
    Purpose: Visits the variant items (dimensions, features, annotations) owned 
             by an inheritance feature or flexible component.   The dimension 
             handles will contain the variant feature model pointer, which has 
             limited access. For more details see ProVariantfeatMdlGet().

    Input Arguments:
        feature - The variant feature.
        visit_action - The visit action.
        filter_action - The filter action.  Pass NULL to skip the filter.
        application_data - The application data passed to the filter and visit 
                           action.  Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or arguments was invalid.
        PRO_TK_E_NOT_FOUND - No variant dimensions were found.
        Other - Returned by the visit action.

*/

extern ProError ProVariantfeatParamsVisit (ProFeature* feature, 
                                           ProParameterAction visit_action, 
                                           ProParameterFilter filter_action, 
                                           ProAppData application_data);
/*
    Purpose: Visits only the variant parameters owned by an inheritance feature 
             or flexible component.   The parameter handles will contain the 
             variant feature model pointer, which has limited access. For more 
             details see ProVariantfeatMdlGet().

    Input Arguments:
        feature - The variant feature.
        visit_action - The visit action.
        filter_action - The filter action.  Pass NULL to skip the filter.
        application_data - The application data passed to the filter and visit 
                           action.  Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or arguments was invalid.
        PRO_TK_E_NOT_FOUND - No variant annotations were found.
        Other - Returned by the visit action.

*/

extern ProError ProVariantfeatParamStandardize (ProFeature* variant_feature, 
                                                ProParameter* varied_param);
/*
    Purpose: Removes a varied parameter from the inheritance feature or 
             flexible component.

    Input Arguments:
        variant_feature - The variant feature handle.
        varied_param - The parameter which is currently varied in the feature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The parameter is not varied in the feature.

*/

extern ProError ProVariantrefAlloc (ProReference original_ref, 
                                    ProReference replacement_ref, 
                                    int* feat_ids, ProVariantref* variant_ref);
/*
    Purpose: Allocates a handle used to describe a variant reference assigned 
             to a variant feature (like inheritance features).

    Input Arguments:
        original_ref - The initial reference handle.
        replacement_ref - The replacement reference handle.
        feat_ids - ProArray of feature ids (from the base model) which will be 
                   assigned this reference replacment action.

    Output Arguments:
        variant_ref - The variant reference handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefFree (ProVariantref variant_ref);
/*
    Purpose: Frees a handle used to describe a variant reference assigned to a 
             variant feature (like inheritance features).

    Input Arguments:
        variant_ref - The variant reference handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefProarrayFree (ProVariantref* variant_ref);
/*
    Purpose: Frees an array of handles used to describe a variant reference 
             assigned to a variant feature (like inheritance features).

    Input Arguments:
        variant_ref - The variant reference handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefOriginalrefGet (ProVariantref variant_ref, 
                                             ProReference* original_ref);
/*
    Purpose: Obtains the original reference (to be replaced).

    Input Arguments:
        variant_ref - The variant reference handle.

    Output Arguments:
        original_ref - The original reference.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefOriginalrefSet (ProVariantref variant_ref, 
                                             ProReference original_ref);
/*
    Purpose: Assigns the original reference (to be replaced).

    Input Arguments:
        variant_ref - The variant reference handle.
        original_ref - The original reference.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefReplacementrefGet (ProVariantref variant_ref, 
                                                ProReference* replacement_ref);
/*
    Purpose: Obtains the replacement reference (which replaces the original 
             reference in this variant feature).

    Input Arguments:
        variant_ref - The variant reference handle.

    Output Arguments:
        replacement_ref - The replacement reference handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefReplacementrefSet (ProVariantref variant_ref, 
                                                ProReference replacement_ref);
/*
    Purpose: Assigns the replacement reference (which replaces the original 
             reference in this variant feature).

    Input Arguments:
        variant_ref - The variant reference handle.
        replacement_ref - The replacement reference handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefFeatidsGet (ProVariantref variant_ref, 
                                         int** feat_ids);
/*
    Purpose: Obtains an array of the feature ids (taken from the base model) 
             which will be assigned the reference replacement.

    Input Arguments:
        variant_ref - The variant reference handle.

    Output Arguments:
        feat_ids - ProArray of feature ids (in the base model).  Free this 
                   using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantrefFeatidsSet (ProVariantref variant_ref, 
                                         int* feat_ids);
/*
    Purpose: Obtains an array of the feature ids (taken from the base model) 
             which will be assigned the reference replacement.
             
             Note: It is not required that the features listed actually use the 
             replacement reference.  If they do, this rule will be applied.
             

    Input Arguments:
        variant_ref - The variant reference handle.
        feat_ids - ProArray of feature ids (in the base model).

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProVariantfeatVariantrefsGet (ProFeature* variant_feat, 
                                              ProVariantref** variant_refs);
/*
    Purpose: Obtains the variant reference assignments stored by this variant 
             feature (inheritance feature).

    Input Arguments:
        variant_feat - The variant feature handle.

    Output Arguments:
        variant_refs - ProArray of the variant reference assignments for the 
                       feature.  Free this using ProVariantrefProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No variant references are assigned.

*/

extern ProError ProVariantfeatVariantrefsSet (ProFeature* variant_feat, 
                                              ProVariantref* variant_refs);
/*
    Purpose: Assigns the variant reference assignments stored by this variant 
             feature (inheritance feature).

    Input Arguments:
        variant_feat - The variant feature handle.
        variant_refs - ProArray of the variant reference assignments for the 
                       feature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProDatasharingfeatCopiedgeomitemFind(
		 ProFeature* p_datasharing_feature,
		 ProAsmcomppath *p_orig_path,
		 ProGeomitem *p_orig_item,
		 ProGeomitem *p_copied_item);
/*
  Purpose:  Retrieves the geometry item owned by the data sharing feature 
  that is actually the copy of the indicated geometry item in the parent 
  model. Currently, this function supports Inheritance, Merge and 
  Cutout features only.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     p_datasharing_feature - the data sharing feature.
     p_orig_path - The component path from the top level assembly to the 
                 subcomponent owning the geometry. Pass NULL if the geometry
                 is owned by the top level model in the datasharing feature.
     p_orig_item - The Geometry item in the original model.

  Output Arguments:
     p_copied_item - The geometry item owned by the data sharing feature that 
                    is a copy of the original item.

  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
     PRO_TK_BAD_CONTEXT - The indicated geometry item is not copied by the
                         data sharing feature.
     PRO_TK_INVALID_TYPE - Feature type is unsupported.
*/

extern ProError ProMdlVariantfeatAsmcomppathGet (ProMdl mdl,
                                                 ProAsmcomppath *p_handle);
/*
    Purpose: Obtains a special model pointer from an inheritance feature or 
             flexible component.  This pointer is  for use in accessing 
             properties that can be modified by the presence of an inheritance 
             feature or flexible component.  Other functions will return an 
             error if provided with this pointer.  To read or modify values not 
             accessible from this pointer, retrieve the parent model using the 
             model name and type using ProMdlRetrieve() or the equivalent.  
             Consult the Creo Parametric TOOLKIT User's Guide for details on the functions 
             that are supported by this pointer.
             

    Input Arguments:
        mdl - The inheritance feature model handle.

    Output Arguments:
        p_handle - The component path from the top level 
                 inheritance feature or to the flexible component model owner.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or arguments was invalid.

*/

PRO_END_C_DECLS
#endif  /* PROVARIANTFEAT_H_ */
