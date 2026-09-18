
#ifndef PROANNOTATIONFEAT_H
#define PROANNOTATIONFEAT_H



#include <ProObjects.h>
#include <ProSelection.h>
#include <ProDtlsyminst.h>

PRO_BEGIN_C_DECLS

extern ProError ProAnnotationfeatCreate ( ProSelection            model, 
					  ProBoolean             use_ui,
					  ProFeature            *p_feat);
/*
  Purpose:  Creates a new annotation feature in the model.

  Licensing Requirement:
          TOOLKIT for 3D Drawings


  Input Arguments:
    model  - The part on which the feature is being created.
             If the feature is created in an assembly, 
	     component path must be specified.

    use_ui - PRO_B_TRUE to invoke the annotation feature creation User
             Interface. PRO_B_FALSE to create a feature automatically 
	     containing a single general annotation element.

  Output Arguments:
    p_feat - The new annotation feature.

  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
    PRO_TK_USER_ABORT  - The user cancelled the feature creation
    (if use_ui = TRUE).
    PRO_TK_BAD_CONTEXT - The owner is not the current model (if use_ui = TRUE).
*/

extern ProError ProAnnotationfeatElementAdd (ProSelection             feature,
					     ProBoolean          allow_fix_ui,
					     ProAnnotationElem       *element);
/*
  Purpose:  Adds a new general annotation element to the annotation feature.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    feature       - The annotation feature.
                    If the feature belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of
                    regeneration failure; PRO_B_FALSE to abort the element
	            adding.		

  Output Arguments:
    element  -  The new annotation element.

  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
    PRO_TK_CANT_MODIFY - Datum Target annotation feature cannot be modified.
*/

extern ProError ProAnnotationfeatElementCopy (ProSelection             feature,
                                              ProAnnotationElem       *element);
/*
  Purpose:  Copy and add an existing annotation element to the annotation 
            feature.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    feature       - The annotation feature.
                    If the feature belongs to an assembly,
                    component path must be specified.
    element       - The annotation element to copy and add.

  Output Arguments:
    None

  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/


extern ProError ProAnnotationfeatElementArrayAdd( ProSelection       feature, 
					       ProBoolean         allow_fix_ui,
					       ProAnnotation     *annotations,
					       ProAnnotationElem **elements);
/*
    Purpose: Adds a series of new elements to the annotation feature. Each 
             element may be created as general, or may contain a preexisting 
             annotation. 
	     if feature is datum target annotation feature only one set datum
             tag annotation can be added.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        feature - The annotation feature. If the feature belongs to an 
                  assembly, component path must be specified.
        allow_fix_ui - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                       regeneration failure; PRO_B_FALSE to abort the element 
                       adding.
        annotations - ProArray of ProAnnotation to use in the new elements.
                      The size of this array indicates the number of new
                      elements to create. Any individual ProAnnotation whose
                      type is set to PRO_TYPE_UNUSED will be used to create
                      a general annotation element instead of an annotation
                      element which references an annotation.

    Output Arguments:
        elements - ProArray of new annotation elements. Free this using 
                   ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
	PRO_TK_CANT_MODIFY - Only one set datum tag can exist in Datum Target
	                     annotation feature 
*/

extern ProError ProAnnotationfeatElementDelete ( ProSelection    element,
						 ProBoolean      allow_fix_ui);
/*
  Purpose: Removes an annotation element from an annotation feature or data 
           sharing feature. For annotation feature elements, the element will
	   be deleted, but the annotation that it contains (if applicable) will
           remain in the model but not be a part of any feature. For data 
	   sharing features, this annotation element will no longer be 
	   propagated in this feature. The parent model of the data sharing 
	   feature must be in memory to allow this removal to succeed.

  Licensing Requirement:
          TOOLKIT for 3D Drawings


  Input Arguments:
    element       - The annotation element.  Include the assembly path if in 
                    the context of an assembly subcomponent.
    allow_fix_ui  - PRO_B_TRUE to go to the Fix Model UI on regeneration 
                    failure, PRO_B_FALSE to undo changes on regeneration 
		    failure.

  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR         - The function succeeded.
    PRO_TK_BAD_INPUTS       - The argument was invalid.
    PRO_TK_BAD_CONTEXT      - The annotation element is readonly and cannot be 
                              deleted.
    PRO_TK_UNATTACHED_FEATS - Deletion was aborted due to regeneration failure.
    PRO_TK_E_NOT_FOUND      - The data sharing feature's parent model is not 
                              in memory; 
    PRO_TK_NOT_VALID        - The element is owned by an independent feature.
    PRO_TK_NO_PERMISSION    - Deletion of set datum tag from datum target 
                              annotation feature is not allowed.

*/

extern ProError ProAnnotationfeatElementArrayDelete ( ProSelection     feature,
                                                      ProSelection    *elements,
                                                      ProBoolean      allow_fix_ui);
/*
  Purpose: Removes a series of annotation elements from an annotation feature or data
           sharing feature. For annotation feature elements, the element will
           be deleted, but the annotation that it contains (if applicable) will
           remain in the model but not be a part of any feature. For data
           sharing features, this annotation element will no longer be
           propagated in this feature. The parent model of the data sharing
           feature must be in memory to allow this removal to succeed.

  Licensing Requirement:
          TOOLKIT for 3D Drawings


  Input Arguments:
    feature       - The annotation feature. If the feature belongs to an 
                    assembly, component path must be specified.
    elements      - ProArray of the annotation elements.  Include the assembly path if in
                    the context of an assembly subcomponent.
    allow_fix_ui  - PRO_B_TRUE to go to the Fix Model UI on regeneration
                    failure, PRO_B_FALSE to undo changes on regeneration
                    failure.

  Output Arguments:
    none

  Return Values:
    PRO_TK_NO_ERROR         - The function succeeded.
    PRO_TK_BAD_INPUTS       - The argument was invalid.
	PRO_TK_INVALID_ITEM     - Feature is invalid for this operation.
    PRO_TK_BAD_CONTEXT      - The annotation element is readonly and cannot be
                              deleted.
    PRO_TK_UNATTACHED_FEATS - Deletion was aborted due to regeneration failure.
    PRO_TK_E_NOT_FOUND      - The data sharing feature's parent model is not
                              in memory;
    PRO_TK_NOT_VALID        - The element is owned by an independent feature.
    PRO_TK_NO_PERMISSION    - Deletion of set datum tag from datum target
                              annotation feature is not allowed.

*/


extern ProError 
ProAnnotationfeatBaselineCreate( ProSelection         feature,
				 ProSelection         reference,
				 ProSelection         direction_reference, 
				 ProAnnotationPlane  *plane, 
				 ProAnnotationElem   *baseline_ae );
/*
  Purpose: Creates a new ordinate baseline annotation element in the 
           annotation feature.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments: 
     feature   - The annotation feature. If the feature belongs to a 
                 subcomponent of the active assembly, the component path must
                 be specified.
        
     reference - The reference geometry for the ordinate baseline dim.

     direction_reference - A straight entity indicating the direction of 
                           dimension witness lines.

                           If the attachment reference is a csys, this must be
                           a csys axis.
  
                           If the dimension reference is a plane or linear 
                           entity, this can be NULL.

     plane     - The annotation plane for the baseline dim and all of its 
                 related dimensions.

  Output Arguments: 
     baseline_ae         - The baseline annotation element.

  Return Values: 
     PRO_TK_NO_ERROR       - The function succeeded.
     PRO_TK_BAD_INPUTS     - One or more input arguments was invalid.
     PRO_TK_BAD_DIM_ATTACH - Invalid reference geometry specified for the
                             baseline dimension.
     PRO_TK_INVALID_MATRIX - Invalid annotation plane specified with respect
                             to the reference geometry.
*/


extern ProError ProDatumtargetAnnotationfeatureCreate ( ProSelection   model,
							ProBoolean     use_ui,
							ProFeature    *p_feat);
/*
  Purpose:  Creates a new datum target annotation feature in the model.

  Licensing Requirement:
          TOOLKIT for 3D Drawings


  Input Arguments:
    model  - The part on which the feature is being created.
             If the feature is created in an assembly, 
	     component path must be specified.

    use_ui - PRO_B_TRUE to invoke the datum target annotation feature creation
             User Interface. PRO_B_FALSE to create a feature automatically.

  Output Arguments:
    p_feat - The new datum target annotation feature.

  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
    PRO_TK_USER_ABORT  - The user cancelled the feature creation
    (if use_ui = TRUE).
    PRO_TK_BAD_CONTEXT - The owner is not the current model (if use_ui = TRUE).
*/

extern ProError ProAnnotationfeatDatumtargetCreate(
                                               ProSelection        feature,
					       ProDtlsyminstdata   data,
					       ProDimension       *dim,
					       ProAnnotationElem  *dtm_trg_ae);
/*
 DEPRECATED:Since Creo 4.0
 SUCCESSORS:ProMdlDatumTargetCreate,ProAnnotationElementGet
 Purpose: Creates a new datum target annotation element in the 
          datum target annotation feature.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments: 
     feature   - The datum target annotation feature. If the feature belongs 
                 to a subcomponent of the active assembly, the component path 
		 must be specified.
     data      - The symbol instance data.
     dim       - Dimension to be called out

  Output Arguments: 
     dtm_trg_ae         - The datum target annotation element.

  Return Values: 
     PRO_TK_NO_ERROR       - The function succeeded.
     PRO_TK_BAD_INPUTS     - One or more input arguments was invalid.
*/



PRO_END_C_DECLS

#endif /* PROANNOTATIONFEAT_H */
