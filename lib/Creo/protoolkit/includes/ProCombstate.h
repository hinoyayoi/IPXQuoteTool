
#ifndef PRO_COMBSTATE_H
#define PRO_COMBSTATE_H



#include <ProMdl.h>

PRO_BEGIN_C_DECLS

typedef int ProCrossecClipOpt;

/* Possible values of ProCrossecClipOpt: */

/* cross-section/zone is not clipped */
#define PRO_VIS_OPT_NONE                0      
/* cross-section/zone is clipped with the material on the front side removed
(the front side is where the positive normals of cross-section/zone planes 
are directed) */
#define PRO_VIS_OPT_FRONT               (1<<0)
/* cross-section/zone is clipped with the material on the back side removed */
#define PRO_VIS_OPT_BACK                (1<<1)


extern ProError ProMdlCombstatesGet(ProSolid p_solid, ProCombstate **p_cs_array);

/*
   Purpose: Returns list of combined states of a solid.

   Input Arguments:
         p_solid -          Solid.
      
   Output Arguments:
         p_cs_array -       ProArray of ProCombstate structures.
                            To free the Array call <b>ProArrayFree()</b> 

   Return Values:
         PRO_TK_NO_ERROR    - Function successefully returned not empty array.
         PRO_TK_E_NOT_FOUND - No combined states found in the model. 
         PRO_TK_BAD_INPUTS  - One of the arguments is Zero pointer.
*/

extern ProError ProCombstateDelete(ProCombstate *cs_item);

/*
   Purpose: Deletes a combined state.

   Input Arguments:
         cs_item -     pointer to a combined state item to be deleted.

   Output Arguments:   
         None.

   Return Values:
      PRO_TK_NO_ERROR      - Combined state deleted.
      PRO_TK_BAD_INPUTS    - Invalid combined state item.
                             Model passed in cs_item is NULL, or the type
                             of the item is not of PRO_COMBINED_STATE.
      PRO_TK_E_NOT_FOUND   - No such combined states in the specified model.
      PRO_TK_E_IN_USE      - Can't delete active combined state.
*/

extern ProError ProCombstateActivate(ProCombstate *cs_item);

/*
   Purpose: Activates a combined state. The owner of the combined state must be top
            model in current active window. Otherwise error will be returned.

   Input Arguments:
         cs_item -     pointer to a combined state item to be activated.

   Output Arguments:
         None.

   Return Values:
      PRO_TK_NO_ERROR      - Combined state Activated.
      PRO_TK_BAD_INPUTS    - Invalid combined state item.
                             Model passed in cs_item is NULL, or the type
                             of the item is not of PRO_COMBINED_STATE.
      PRO_TK_E_NOT_FOUND   - No such combined states in the specified model.
      PRO_TK_GENERAL_ERROR - The model in cs_item->owner is not a top model in current
                             active window.
*/

extern ProError ProCombstateActiveGet(ProSolid p_solid,  
                                      ProCombstate *p_cs_item);

/*
   Purpose: Gets the active combined state on a model.

   Input Arguments:
      p_solid  -           Solid.

   Output Arguments:
      p_cs_item -          Pointer to combined state item.

   Return Values:
      PRO_TK_NO_ERROR    - Active state returned.
      PRO_TK_BAD_INPUTS  - One of the arguments is invalid.
      PRO_TK_E_NOT_FOUND - No active combined state found.
*/

extern ProError ProCombstateDataGet(ProCombstate *cs_item, ProName cs_name,
                             ProModelitem **cs_ref_arr,
                             ProCrossecClipOpt *p_clip_opt, 
                             ProBool *p_is_expld);

/*
  Purpose: Getting combined state info.
 
  Input Arguments: 
       cs_item -            Combined state item.
   
  Output Arguments:       
       cs_name -            Combined state name.
       cs_ref_arr -         ProArray of reference states. Notes:
                            <p>1. This array may contain items of these types:
                            <ul>
                            <li>PRO_VIEW, 
                            <li>PRO_LAYER_STATE, 
                            <li>PRO_SIMP_REP, 
                            <li>PRO_EXPLD_STATE, 
                            <li>PRO_XSEC, 
                            <li>PRO_STYLE_STATE
                            </ul>
                            <p>2. A combined state may include the default view 
                            and/or the default simplified representation, 
                            which have their id equal to (-1).</p>
                            <p>3. The PRO_XSEC item
                            may represent either a valid ProXsec handle or a 
                            zone feature. Use ProModelitemIsZone to check it
                            and, if it returns TRUE, change the item type to 
                            PRO_FEATURE and use ProFeatureZoneGet instead.
                            To free the array call <b>ProArrayFree()<b/>.</p>
       p_clip_opt -         pointer to cross section clip option value. The returned 
                            value is valid only in case when PRO_XSEC reference exists
                            inside cs_ref_arr, meaning that combined state has valid
                            cross section reference.
       p_is_expld -         pointer to value. Is state exploded. Not used
                            in part mode, since explode state does not exist
                            in part mode. 

  Return Values:
       PRO_TK_NO_ERROR    - Function successfully returned. The values of 
                            p_clip_opt, and p_is_expld are not assigned in 
                            case that cs_ref_arr is NULL. 
       PRO_TK_E_NOT_FOUND - No such combined state in the specified model.
       PRO_TK_BAD_INPUTS  - Model pointer is NULL.
*/ 

extern ProError ProMdlCombStateCreate(ProSolid p_solid, ProName new_name,
                                      ProModelitem *ref_arr,
                                      ProCrossecClipOpt clip_opt,  
                                      ProBool is_expld,
                                      ProCombstate *cs_item );

/* 
   Purpose: Create combined state from references.

   Input Arguments:
      p_solid -              Solid.
      new_name -             Name of the new state.
      ref_arr -              ProArray of references. Must be non empty array.
                             See ProCombstateDataGet for possible types 
                             of items in this array.
                             The PRO_XSEC item may represent either a valid 
                             ProXsec handle or a zone feature. Use 
                             ProModelitemIsZone to check it and, if it returns 
                             TRUE, change the item type to PRO_FEATURE and use 
                             ProFeatureZoneGet instead.
      clip_opt -             Cross section clip option. Not used if PRO_XSEC reference
                             is not passed.
      is_expld -             Is state exploded or not. Not relevant in Part.

   Output Arguments:  
      cs_item -              Created combined state item. Allowed to be NULL.

   Return Values:
      PRO_TK_NO_ERROR      - Combined state created.
      PRO_TK_BAD_INPUTS    - Invalid solid or name (including that combined
                             state with such name exists. Reference array is NULL or
                             it's size is zero. 
      PRO_TK_INVALID_TYPE  - Invalid references.
                             Possible errors:
                             - The type of one of the references is not valid.
                             - Reference of some type appears twice or more. 
                             - Id and type of a reference don't match.
*/ 

extern ProError ProCombstateRedefine(ProCombstate *cs_item, 
                                     ProModelitem *ref_arr,
                                     ProCrossecClipOpt clip_opt, 
                                     ProBool is_expld );

/*
   Purpose: redefine existing combined state.

   Input Arguments:
      cs_item -          Combined state item to redefine.
      ref_arr -          ProArray of reference items to redefine. 
                         See ProCombstateDataGet for possible types of items 
                         in this array. The new references override 
                         the existing ones. If a reference
                         shouldn't be changed it should be passed with same ID.
                         Not passing references, will result in redefining a
                         state to NO_STATE. NO_STATE means, that activation
                         of a combined state won't affect this particular state. 
                         The reference array must be non empty.
      clip_opt -         Cross section clipping option of a state.
      is_expld -         State exploded/unexploded?

   Output Arguments:
      None.

   Return Values:
      PRO_TK_NO_ERROR      - Combined state redefined.
      PRO_TK_BAD_INPUTS    - Invalid solid or cs_item.
      PRO_TK_INVALID_TYPE  - Invalid references.
                             Possible errors:
                             - The type of one of the references is not valid.
                             - Reference of some type appears twice or more. 
                             - Id and type of a reference don't match.
*/

/********************************************************/
/**  API for manipulating annotation in Combined State **/
/********************************************************/

extern ProError ProCombstateAnnotationsAdd (ProCombstate *cs_item, 
                                            ProAnnotation *annotations, 
                                            int *status_flags);
/*
   Purpose:
        Adds annotations to provided combined state item.

   Input Arguments:
        cs_item - The handle to a combined state item.
        annotations - ProArray of annotations.
        status_flags - ProArray of integers. Each annotation can be included, 
                       or excluded in the combined state. 0 value means that
                       annotation is included in the combined state, 1 excluded.

   Output Arguments:
        None.

   Return Values:
        PRO_TK_NO_ERROR        - The function successfully added annotations.
        PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
        PRO_TK_INVALID_ITEM    - size of status_flags' array differs from
                                 the size of annotations' array.
        PRO_TK_E_NOT_FOUND     - This legacy  combined state doesn't have 
                                 annotation state. Annotations cannot be added.
        PRO_TK_NO_CHANGE       - Status of some annotations wasn't changed. Some 
                                 annotations existed in the combined state already and
                                 their status was same as the one in the input.
        Other                  - Another error occurred and the function failed.
*/

extern ProError ProCombstateAnnotationsRemove (ProCombstate *cs_item, 
                                               ProAnnotation *annotations, 
                                               int **not_found_indices);
/*
   Purpose:
        Removes annotations from provided combined state item.

   Input Arguments:
        cs_item - The handle to a combined state item.
        annotations - ProArray of annotations.

   Output Arguments:
        not_found_indices - ProArray of integers, representing annotation ids,
                            which are not included in the combined state.
                            To free the array call <b>ProArrayFree()<b/>.
                            The parameter is allowed to be NULL.

   Return Values:
        PRO_TK_NO_ERROR        - The function successfully removed annotations.
        PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
        PRO_TK_E_NOT_FOUND     - This legacy  combined state doesn't have 
                                 annotation state. Annotations cannot be Removed. 
        Other                  - Another error occurred and the function failed.
*/

extern ProError ProCombstateAnnotationsGet(ProCombstate *cs_item, 
                                           ProAnnotation **p_annotations,  
                                           int **p_status_flags);

/*
   Purpose:
        Retrieves annotations of provided combined state item.

   Input Arguments:
        cs_item - The handle to a combined state item.

   Output Arguments:
        p_annotations - ProArray of annotations.
                        To free the array call <b>ProArrayFree()<b/>.
        p_status_flags - ProArray of status flags.
                         To free the array call <b>ProArrayFree()<b/>.

   Return Values:
        PRO_TK_NO_ERROR        - The function successfully removed annotations.
        PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
        PRO_TK_E_NOT_FOUND     - This legacy  combined state doesn't have 
                                 annotation state. Annotations cannot be added.
        Other                  - Another error occurred and the function failed.
*/

extern ProError ProCombstateAnnotationErase (ProCombstate *cs_item, 
                                             ProAnnotation* annotation);
/*  Purpose:  Sets an annotation to be erased from specified combined state.  
                  This changes the model database to not show the annotation 
                  until it is explicitly shown again.	 

	Input Arguments:
		 cs_item - The handle to a combined state item.
		 annotation - The annotation (note, gtol, surface finish, 
                                symbol, ref. dim., driven dim, dimension).  
	       <P>Note:  regular dimensions may only be erased from a drawing.

	Output Arguments:
        none
    
	Return Values:
	    PRO_TK_NO_ERROR  - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more arguments was invalid.
		PRO_TK_NO_CHANGE - The annotation is not shown in the target model.
		PRO_TK_NO_LICENSE - License check failure.

	See Also:
		ProAnnotationErase()
		
*/

extern ProError  ProCombstateAnnotationsStateGet(ProCombstate *cs_item,
                                                 ProBool      *p_state);

/*  Purpose: Checks if Annotations are controlled by layers or 
             specified combined state.

    Input Arguments:
        cs_item              - Pointer to a combined state item to retrieve the 
                               state from.
    Output Arguments:
        p_state              - Flag to determine whether the given combined 
                               state’s Annotations are controlled by layers or 
                               combined state.
                               PRO_B_TRUE when the display is controlled by combined state.
                               PRO_B_FALSE when the display is controlled by layers.
    Return Values:
        PRO_TK_NO_ERROR      - Combined state ‘Annotation’ State was retrieved 
                               successfully.
        PRO_TK_BAD_INPUTS    - Invalid combined state item. Model passed in 
                               cs_item is NULL, or the type of the item is not  
                               of PRO_COMBINED_STATE.
*/

extern ProError  ProCombstateSupplGeomStateGet(ProCombstate *cs_item, 
                                               ProBool      *p_state);

/*  Purpose: Checks if Supplementary Geometry is controlled by layers or 
             specified combined state.

    Input Arguments:
        cs_item              - Pointer to a combined state item to retrieve the 
                               state from.
    Output Arguments:
        p_state              - Flag to determine whether the given combined 
                               state’s Supplementary Geometry is controlled by
                               layers or combined state.
                               PRO_B_TRUE when the display is controlled by combined state.
                               PRO_B_FALSE when the display is controlled by layers.
    Return Values:
        PRO_TK_NO_ERROR      - The ‘Supplementary Geometry’ State was retrieved 
                               successfully.
        PRO_TK_BAD_INPUTS    - Invalid combined state item. Model passed in 
                               cs_item is NULL, or the type of the item is not 
                               of PRO_COMBINED_STATE.
*/

extern ProError  ProCombstateIsPublished(ProCombstate *cs_item, 
										 ProBool      *p_state);

/*  Purpose: Checks if the given combined state is published.

    Input Arguments:
        cs_item              - Pointer to a combined state item to retrieve the
		                       state from.
    Output Arguments:
        p_state              - Flag to determine whether the given combined 
		                       state is published.
    Return Values:
        PRO_TK_NO_ERROR      - The ‘Published’ State was retrieved successfully.
        PRO_TK_BAD_INPUTS    - Invalid combined state item. Model passed in 
		                       cs_item is NULL, or the type of the item is not 
							   of PRO_COMBINED_STATE.
*/

extern ProError  ProCombstateIsDefault(ProCombstate *cs_item, ProBool *p_state);

/*  Purpose: Checks if the given combined state is default.

    Input Arguments:
        cs_item              - Pointer to a combined state item to retrieve the
		                       the state from.
    Output Arguments:
        p_state              - Flag to determine whether the given combined 
		                       state is default.
    Return Values:
        PRO_TK_NO_ERROR      - The 'Default' State was retrieved successfully.
        PRO_TK_BAD_INPUTS    - Invalid combined state item, or CS owner passed  
		                       in cs_item is NULL, or the type of the item is not 
							   of PRO_COMBINED_STATE.
*/

PRO_END_C_DECLS

#endif
