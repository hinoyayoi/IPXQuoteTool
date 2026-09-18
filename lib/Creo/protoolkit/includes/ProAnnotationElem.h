#ifndef PROANNOTATIONELEM_H
#define PROANNOTATIONELEM_H



#include <ProObjects.h>
#include <ProSelection.h>
#include <ProAsmcomppath.h>
#include <ProReference.h>
#include <ProCollect.h>

PRO_BEGIN_C_DECLS

typedef enum 
{
    PRO_ANNOT_REF_SINGLE,
    PRO_ANNOT_REF_CRV_COLLECTION,
    PRO_ANNOT_REF_SRF_COLLECTION
} ProAnnotationRefType;

typedef struct pro_annot_reference
{
    ProAnnotationRefType type;
    union
    {
       ProReference reference;
       ProCollection collection;
    } object;
} ProAnnotationReference;


typedef enum 
{
    PRO_ANNOT_TYPE_NONE          = 0,
    PRO_ANNOT_TYPE_NOTE          = PRO_NOTE,
    PRO_ANNOT_TYPE_GTOL          = PRO_GTOL,
    PRO_ANNOT_TYPE_SRFFIN        = PRO_SURF_FIN,
    PRO_ANNOT_TYPE_SYMBOL        = PRO_SYMBOL_INSTANCE,
    PRO_ANNOT_TYPE_DRVDIM        = PRO_DIMENSION,
    PRO_ANNOT_TYPE_REFDIM        = PRO_REF_DIMENSION,
    PRO_ANNOT_TYPE_SET_DATUM_TAG = PRO_SET_DATUM_TAG,
    PRO_ANNOT_TYPE_CUSTOM        = PRO_CUSTOM_ANNOTATION,
    PRO_ANNOT_TYPE_DRIVINGDIM    = PRO_ANNOT_ELEM_DRIVING_DIM
} ProAnnotationType;

typedef enum 
{
    PRO_ANNOTATION_REF_ALL,
    PRO_ANNOTATION_REF_WEAK,
    PRO_ANNOTATION_REF_STRONG
} ProAnnotationRefFilter;

typedef enum
{
    PRO_ANNOT_REF_FROM_ALL,
    PRO_ANNOT_REF_FROM_ANNOTATION,
    PRO_ANNOT_REF_FROM_USER
} ProAnnotationRefFromType;



typedef ProError (*ProAnnotationelemVisitAction) (ProAnnotationElem *element,
						  ProError     filter_status,
						  ProAppData   data);
/*
  Purpose:  This is the generic function for visiting an annotation element.

  Input Arguments:
    element  -  The annotation element
    filter_status   -  The filter function status
    data     -  The application data passed to the calling function

  Output Arguments:
    None

  Return Values:
    PRO_TK_NO_ERROR - Continue visiting.
    Other           - Stop visiting and pass this error status to the calling
                      function.
*/


typedef ProError (*ProAnnotationelemFilterAction) (ProAnnotationElem *element,
						   ProAppData data);
/*
  Purpose:  This is the generic function for filtering an annotation element.

  Input Arguments:
    element  -  The annotation element 
    data     -  The application data passed to the calling function
  
  Output Arguments:
    None
  
  Return Values:
    PRO_TK_CONTINUE - Skip visiting this element and go to the next.
    Other           - Call the visit action for this element. The return
                      value is passed as input to the visit action.
*/


extern ProError ProFeatureAnnotationelemsVisit (ProFeature* feat, 
				  ProAnnotationelemVisitAction visit_action, 
				  ProAnnotationelemFilterAction filter_action, 
                                  ProAppData data);
/*
  Purpose:  Visits the annotation elements in a given feature.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    feat          - The feature.
    visit_action  - The visit function for the annotation elements.
    filter_action - The filter function for the annotation elements.
                    Can be NULL.
    data          - Application data passed to the visit and filter actions.

  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - No annotation elements were found in the feature.
    Other              - Error returned by the visit action.
*/


extern ProError ProSolidAnnotationelemsVisit (ProSolid solid,   
				  ProAnnotationelemVisitAction visit_action, 
                                  ProAnnotationelemFilterAction filter_action, 
                                  ProAppData data);
/*
  Purpose:  Visits the annotation elements in a given model.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    solid         - The solid model.
    visit_action  - The visit function for the annotation elements.
    filter_action - The filter function for the annotation elements.
                    Can be NULL.
    data          - Application data passed to the visit and filter actions.

  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - No annotation elements were found in the model.
    Other              - Error returned by the visit action.
*/

extern ProError ProAnnotationelemFeatureGet (ProAnnotationElem       *element,
					     ProFeature                 *feat);
/*
  Purpose:  Gets the feature that owns an annotation element.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
  
  Output Arguments:
    feat          - The feature that owns the element.
    
  Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/


extern ProError ProAnnotationelemTypeGet( ProAnnotationElem          *element,
					  ProAnnotationType           *type);
/*
  Purpose:  Gets the type of annotation contained in an annotation element.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element. 

  Output Arguments:
    type          - The annotation type.
    
  Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/



extern ProError ProAnnotationelemAnnotationGet( ProAnnotationElem    *element,
						ProAnnotation     *annotation);
/*
  Purpose:  Gets the annotation contained in an annotation element.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
  
  Output Arguments:
    annotation    - The annotation.
  
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - The annotation element does not contain an annotation.
*/

extern ProError ProAnnotationelemAnnotationSet (ProSelection       element, 
						ProAnnotation     *annotation);
/*
  Purpose:  Sets the annotation contained in an annotation element.
            <B>Note:</B>If the annotation element already had an annotation 
            assigned to it, that annotation will be detached from the element 
            and owned at the model level.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    annotation    - The annotation. Pass NULL to set the element to be
                    general.

  Output Arguments:
    none
    
  Return Values:
    PRO_TK_NO_ERROR         - The function succeeded.
    PRO_TK_BAD_INPUTS       - One or more inputs was invalid.
    PRO_TK_NO_CHANGE        - The annotation is already contained in this 
                              element.
    PRO_TK_UNATTACHED_FEATS - Modification was aborted due to regeneration
                              failure.
    PRO_TK_INVALID_TYPE     - You cannot assign this type of annotation to 
                              the annotation element
    PRO_TK_CANT_MODIFY      - datum target annotation element or annotation
                              are not permitted for this function
*/

extern ProError 
       ProAnnotationelemReferencesCollect( ProAnnotationElem        *element,
				           ProAnnotationRefFilter    ref_type,
					   ProAnnotationRefFromType  source,
					   ProAnnotationReference  **references);
/*
  Purpose:  Gets the references contained in an annotation element.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
    ref_type      - The type of references to collect (weak, strong, or all).
    source        - The source of the references (from the annotation, from
                    the user, or all).

  Output Arguments:
    references    - The annotation references.  Free this using 
                    ProAnnotationreferencearrayFree().
 
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - The annotation element does not contain any references
                         of the indicated type.
    PRO_TK_INVALID_TYPE - References from driving dimension annotation 
                          elements cannot be accessed.
*/

extern ProError ProAnnotationreferencearrayFree (ProAnnotationReference* reference_array);
/*
  Purpose:  Frees all memory owned by the annotation reference array.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    reference_array     - The reference array.
 
  Output Arguments:
    none
 
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
*/


extern ProError ProAnnotationelemReferenceAdd( ProSelection            element,
					       ProBoolean         allow_fix_ui,
			                    ProAnnotationReference *reference);
/*
  Purpose:  Adds a strong reference to the annotation element.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of
                    regeneration failure; PRO_B_FALSE to abort the reference
	            adding.		
    reference     - The item to use as a strong reference.

  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_FOUND     - The annotation element already has a reference to this
                         item.
    PRO_TK_CANT_MODIFY - User defined references are not permitted for 
                         driving dimension annotation elements.
*/


extern ProError ProAnnotationelemReferenceRemove( ProSelection       element,
						  ProBoolean    allow_fix_ui,
					   ProAnnotationReference *reference);
/*
  Purpose:  Removes a user-added reference from the annotation element.  

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of
                    regeneration failure; PRO_B_FALSE to abort the reference
	            removal.
    reference     - The reference to remove.		    


  Output Arguments:
    none
    
  Return Values:
    PRO_TK_NO_ERROR         - The function succeeded.
    PRO_TK_BAD_INPUTS       - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND      - The annotation element does not contain this 
                              reference.
    PRO_TK_BAD_CONTEXT      - This reference is provided from the annotation
                              and cannot be removed.
    PRO_TK_UNATTACHED_FEATS - Removal was aborted due to regeneration failure.
*/



extern ProError ProAnnotationelemReferencesSet( ProSelection          element,
						ProBoolean        allow_fix_ui,
					   ProAnnotationReference   *references);
/*
  Purpose:  Replaces all of the annotation element's user-defined references
            with the indicated sets.  

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                    regeneration failure; PRO_B_FALSE to abort the reference
	            setting.
    references    - ProArray of annotation references. 

  Output Arguments:
    none
    
  Return Values:
    PRO_TK_NO_ERROR         - The function succeeded.
    PRO_TK_BAD_INPUTS       - One or more inputs was invalid.
    PRO_TK_BAD_CONTEXT      - The reference array contains the same reference
                              more than once.
    PRO_TK_UNATTACHED_FEATS - Reference modification was aborted due to 
                              regeneration failure.
    PRO_TK_CANT_MODIFY      - User defined references are not permitted for 
                              driving dimension annotation elements.
*/



extern ProError ProAnnotationelemReferenceStrengthen( ProSelection           element,
					       ProBoolean        allow_fix_ui,
					    ProAnnotationReference *reference);
/*
  Purpose:  Converts a weak reference to a strong reference.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                    regeneration failure; PRO_B_FALSE to abort the reference's
	            attribute changing.
    reference     - The item to use as a strong reference.
	 
  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - The annotation element doesn't contain this weak 
                         reference.
    PRO_TK_CANT_WRITE  - This weak reference may not be strengthened due to
                         the rules for the individual annotation.
*/



extern ProError ProAnnotationelemReferenceWeaken( ProSelection        element,
						  ProBoolean     allow_fix_ui,
				            ProAnnotationReference *reference);
/*
  Purpose:  Converts a strong reference to a weak reference.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                    regeneration failure; PRO_B_FALSE to abort the reference's
	            attribute changing.
    reference     - The item to use as a weak reference.

  Output Arguments:
    none
    
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - The annotation element doesn't contain this strong
                         reference.
    PRO_TK_CANT_WRITE  - This strong reference may not be weakened due to the
                         rules for the individual annotation.
*/


extern ProError ProAnnotationelemIsDependent (ProAnnotationElem       *element,
					      ProBoolean           *dependent);
/*
  Purpose:  Gets the dependency flag of the specified annotation element.
            Applicable only for annotation elements owned by data sharing 
            features. 

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.

  Output Arguments:
    dependent     - PRO_B_TRUE if the annotation element is dependent on its 
                    parent, PRO_B_FALSE if not.
    
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_CANT_ACCESS - The element is not owned by a data sharing feature.
*/

extern ProError ProAnnotationelemDependencySet( ProSelection        element,
						ProBoolean     allow_fix_ui,
						ProBoolean       dependent);
/*
  Purpose:  Sets the dependency flag of the specified annotation element.
            Applicable only for annotation elements owned by data sharing 
            features. 

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                    regeneration failure; PRO_B_FALSE to abort the reference's
	            attribute changing.
    dependent     - PRO_B_TRUE if the annotation element is dependent on its 
                    parent, PRO_B_FALSE if not.
  
  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_NO_CHANGE   - The input flag is the same as the current value.
    PRO_TK_CANT_ACCESS - The element is not owned by a data sharing feature.
    PRO_TK_E_NOT_FOUND - The data sharing feature's parent model is not 
                         in memory. 
    PRO_TK_NOT_VALID   - The element is owned by an independent feature.                      
*/



extern ProError ProAnnotationelemCopyGet (ProAnnotationElem          *element,
                                          ProBoolean                    *copy);
/*
  Purpose:  Gets the copy flag of the specified annotation element (determines
             if references will be copied into the element).

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element    - The annotation element.

  Output Arguments:
    copy       - PRO_B_TRUE if the annotation element contains copies of its 
                 references, PRO_B_FALSE if not.
    
  Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/

extern ProError ProAnnotationelemCopySet ( ProSelection           element,
					   ProBoolean         allow_fix_ui,
					   ProBoolean                 copy);
/*
  Purpose:  Sets the copy flag of the specified annotation element.  

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
                    If the annotation element belongs to an assembly, 
		    component path must be specified.
    allow_fix_ui  - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                    regeneration failure; PRO_B_FALSE to abort the reference's
	            attribute changing.
    copy          - PRO_B_TRUE if the annotation element is dependent on its
                    parent, PRO_B_FALSE if not.

  Output Arguments:
    none
  
  Return Values:
    PRO_TK_NO_ERROR         - The function succeeded.
    PRO_TK_BAD_INPUTS       - One or more inputs was invalid.
    PRO_TK_NO_CHANGE        - The input flag is the same as the current value.
    PRO_TK_UNATTACHED_FEATS - Reference modification was aborted due to 
                              regeneration failure.
*/

extern ProError ProAnnotationelemIsIncomplete( ProAnnotationElem     *element,
                                               ProBoolean      *is_incomplete);

/*
  Purpose:  Identifies if the annotation element is incomplete due to missing
            strong references.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     element    - The annotation element. 

  Output Arguments:
     is_incomplete  - PRO_B_TRUE if the annotation element has missing strong
                      references, PRO_B_FALSE overvise.

  Return Values:
         PRO_TK_NO_ERROR   - The function succeeded.
         PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/

extern ProError ProAnnotationelemReferenceIsStrong( ProAnnotationElem *element,
					     ProAnnotationReference *reference,
						    ProBoolean     *is_strong);
/*
    Purpose: Identifies if a reference is weak or strong in a given annotation
             element.

    Licensing Requirement:
          TOOLKIT for 3D Drawings
	     
    Input Arguments:
        element - The annotation element. 
        reference - The reference item.

    Output Arguments:
        is_strong - PRO_B_TRUE if the reference is strong, PRO_B_FALSE if it is
                    weak.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_E_NOT_FOUND - The annotation element doesn't contain this
                             reference.

*/

extern ProError 
          ProAnnotationelemReferenceDescriptionSet( ProAnnotationElem* element,
		                             ProAnnotationReference *reference,
							  ProLine description);
/*
    Purpose: Sets the description property for a given annotation element
             reference.

   Licensing Requirement:
          TOOLKIT for 3D Drawings
	     
    Input Arguments:
        element - The annotation element. If the annotation element belongs to
                  an assembly, component path must be specified.
        reference - The reference.
        description - The description for the annotation element.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_E_NOT_FOUND - The annotation element doesn't contain this
                             reference.

*/

extern ProError 
          ProAnnotationelemReferenceDescriptionGet( ProAnnotationElem* element,
				             ProAnnotationReference* reference,
						    ProLine description);
/*
    Purpose: Gets the description property for a given annotation element
             reference.

    Licensing Requirement:
          TOOLKIT for 3D Drawings
	     
    Input Arguments:
        element   - The annotation element.
        reference - The reference.

    Output Arguments:
        description - The description for the annotation element.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_E_NOT_FOUND - The annotation element doesn't contain this
                             reference.

*/

extern ProError ProAnnotationelemReferenceAutopropagateGet(
					       ProSelection          element,
					   ProAnnotationReference *reference,
					       ProBoolean    *autopropagate);
/*
  Purpose: Gets the autopropagate flag of the specified annotation element
  reference.Applicable only for annotation elements owned in annotation 
  features.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
    reference     - The annotation element reference.

  Output Arguments:
    autopropagate     - PRO_B_TRUE if the annotation element reference will 
                      be  automatically propagated when data sharing features
		      are created, PRO_B_FALSE if not.
   
  Return Values:
    PRO_TK_NO_ERROR     - The function succeeded.
    PRO_TK_BAD_INPUTS   - One or more inputs was invalid.
    PRO_TK_BAD_CONTEXT  - The element is not owned by an annotation feature.
    PRO_TK_E_NOT_FOUND  - The annotation element doesn't contain this reference
    PRO_TK_INVALID_TYPE - This type of reference does not have an autopropagate
                          flag.
    PRO_TK_NO_LICENSE   - License check failure.
*/

extern ProError ProAnnotationelemReferenceAutopropagateSet( 
                                                  ProSelection         element,
					     ProAnnotationReference *reference,
						  ProBoolean    autopropagate);
/*
  Purpose:  Sets the autopropagate flag of the specified annotation element 
  reference. Applicable only for annotation elements owned in annotation 
  features.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    element       - The annotation element.
    reference     - The annotation element reference.
    autopropagate - PRO_B_TRUE if the annotation element reference will be 
                    automatically propagated when data sharing features are
		    created, PRO_B_FALSE if not.

  Output Arguments:
     none
   
  Return Values:
    PRO_TK_NO_ERROR     - The function succeeded.
    PRO_TK_BAD_INPUTS   - One or more inputs was invalid.
    PRO_TK_BAD_CONTEXT  - The element is not owned by an annotation feature.
    PRO_TK_E_NOT_FOUND  - The annotation element doesn't contain this reference
    PRO_TK_NO_CHANGE    - Reference autopropagate flag is already set to the 
                          input value.
    PRO_TK_INVALID_TYPE - This type of reference does not have an autopropagate
                          flag.
    PRO_TK_NO_LICENSE   - License check failure.
*/

extern ProError ProAnnotationelemAutopropagate ( void );
/* 
   Purpose: Automatically propagates annotation elements within the current 
   model to the currently selected feature based on the standard Creo Parametric
   algorithm. The behavior is based on the current contents of the selection
   buffer.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments: 
     none
	
   Output Arguments:
     none

   Return Values:
     PRO_TK_NO_ERROR    - Annotation elements were successfully propagated to
                          the selected feature.
     PRO_TK_BAD_CONTEXT - The current selections do not allow propagation of
                          annotation elements.
     PRO_TK_NO_LICENSE  - No license is available for this function.

     See Also:
     ProSelbufferSelectionsGet()
*/

extern ProError ProAnnotationelemQuiltreferenceSurfacesCollect(
                                                    ProAnnotationElem* elem,
                                          ProAnnotationReference* reference,
                                                    ProSelection** surfaces);
/*
     Purpose:  Returns the surfaces which make up a quilt surface collection
               reference for the annotation element. This will even return
               the surfaces for a quilt which has been made inactive by
               features occurring after the annotation element in the model
               regeneration.
 
    Input Arguments:
               elem - The annotation element.
               reference - The reference (obtained from 
                           ProAnnotationelemReferencesCollect()), which must
                           contain a surface collection of type
			   PRO_SURFCOLL_QUILT_SRFS.
 
   Output Arguments:
                surfaces - ProArray of selections of surface references,
		           suitable for use for highlighting.  Free this
                           using ProSelectionarrayFree().
 
   Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_INVALID_TYPE - The input reference type was not valid.
*/

typedef ProAppData ProAnnotationReferenceSet;

extern ProError 
 ProAnnotationelemArrayReferencesSet(ProSelection               feature,
				     ProAnnotationElem         *element,
				     ProBoolean                 allow_fix_ui,
				     ProAnnotationReferenceSet *reference_set);
/*
    Purpose: Replaces all of the each of the annotation elements' user-defined 
             references with the indicated sets. 

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        feature - The feature which owns all of the annotation elements.
	          If the feature's references are to other members of 
		  an assembly, the component path must be specified.
        element - ProArray of annotation elements. All of these elements must 
                  belong to the same feature.
        allow_fix_ui - PRO_B_TRUE to bring up the Fix Model UI in the event of 
                       regeneration failure; PRO_B_FALSE to abort the reference
                       setting.
        reference_set - ProArray of annotation reference sets. The number of 
                        sets should match the number of elements to be 
                        modified.


    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_BAD_CONTEXT - The reference array contains the same reference 
                             more than once.
        PRO_TK_UNATTACHED_FEATS - Reference modification was aborted due to 
                                  regeneration failure.
        PRO_TK_CANT_MODIFY - User defined references are not permitted for 
                             driving dimension annotation elements.
        PRO_TK_E_AMBIGUOUS - The number of reference sets does not match the 
                             number of elements supplied.
        PRO_TK_INVALID_ITEM - One or more annotation elements do not belong to 
                              the owner feature.

*/

extern ProError 
    ProAnnotationreferencesetAlloc( ProAnnotationReferenceSet* reference_set);
/*
    Purpose: Allocates a set of references to be assigned to an annotation 
             element.

    Input Arguments:
        none

    Output Arguments:
        reference_set - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError 
    ProAnnotationreferencesetFree( ProAnnotationReferenceSet reference_set);
/*
    Purpose: Frees a set of references to be assigned to an annotation element.

    Input Arguments:
        reference_set - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError 
ProAnnotationreferencesetProarrayFree( ProAnnotationReferenceSet* reference_set);
/*
    Purpose: Frees an array of a set of references to be assigned to an 
             annotation element.

    Input Arguments:
        reference_set - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError 
ProAnnotationreferencesetReferenceAdd( ProAnnotationReferenceSet  reference_set,
				   ProAnnotationReference    *reference,
				   ProBoolean                 strong,
				   ProLine                    description,    
				   ProBoolean                 autopropagate);
/*
    Purpose: Adds a reference to the annotation set.

    Input Arguments:
        reference_set - The annotation reference set.
        reference - The reference to add.
        strong - PRO_B_TRUE if the reference is to be strong; PRO_B_FALSE if it 
                 is to be weak.
        description   - The reference description. Can be NULL.
        autopropagate - PRO_B_TRUE if the reference will be autopropagated into 
                        data sharing features, PRO_B_FALSE otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

PRO_END_C_DECLS

#endif /* PROANNOTATIONELEM_H */
