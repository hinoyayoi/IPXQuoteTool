#ifndef PROANNOTATION_H
#define PROANNOTATION_H

/* Creo Parametric TOOLKIT declarations for ProAnnotation-related actions */

#include <ProObjects.h>
#include <ProSurfacedata.h>
#include <ProSelection.h>
#include <ProAnnotationElem.h>



PRO_BEGIN_C_DECLS

#define PRO_ID_NO_ANNOTATION_PLANE (-2)

typedef enum
{
  PRO_ANNOTATIONPLANE_REFERENCE,  /* This could be frozen or associative to the
                                     reference */
  PRO_ANNOTATIONPLANE_NAMED_VIEW,  /* The plane was created from a named view
                                      or a view in a drawing. */
  PRO_ANNOTATIONPLANE_FLATTOSCREEN_BY_MODELPNT, /* The plane is flat-to-screen
                                                   and annotations will be
                                                   located by model point. 
                                                   This will use the text
                                                   height option indicated by 
                                          ProTextStyleIsHeightInModelUnits() */
  PRO_ANNOTATIONPLANE_FLATTOSCREEN_BY_SCREENPNT, /* The plane is flat-to-screen
                                                    and annotations will be
                                                    located by screen point. */
  PRO_ANNOTATIONPLANE_FLATTOSCREEN_LEGACY /* The annotation uses a legacy
                                             flat-to-screen format (located in
                                             model space). */
} ProAnnotationPlaneType;

typedef enum
{
  PRO_ANNOTATTACH_ASSOCIATIVITY_NONE,
  PRO_ANNOTATTACH_ASSOCIATIVITY_PARTIAL,
  PRO_ANNOTATTACH_ASSOCIATIVITY_FULL
} ProAnnotationAttachmentAssociativity;

extern ProError ProAnnotationplaneCreate (ProSelection reference,
                                          ProVector direction,
                                          ProAnnotationPlane* plane);
/*
  Purpose:  Creates an annotation plane structure from either a datum plane,
            a flat surface, or an existing annotation.

  Input Arguments:
     reference    - The datum plane to use as the annotation plane,
                    or an annotation whose plane should be used for
                    the annotation plane.
     direction  - The viewing direction of the annotation plane.  Pass NULL when
                  copying an annotation plane from another annotation.

  Output Arguments:
     plane - The annotation plane handle.

  Return Values:
      PRO_TK_NO_ERROR  - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_INVALID_MATRIX - Invalid combination of the planar surface
                              and the direction vector.

  See Also:
      ProAnnotationplaneFromViewCreate()
      ProAnnotationplaneFlatToScreenCreate()
*/

extern ProError ProAnnotationplaneReferenceGet (ProAnnotationPlane *plane,
                                                ProSelection* reference);
/*
  Purpose:  Accesses the planar surface used as an annotation plane.

  Input Arguments:
        plane - The annotation plane handle.

  Output Arguments:
       reference    - The planar surface to use as the annotation plane.

  Return Values:
      PRO_TK_NO_ERROR  - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_E_NOT_FOUND - The annotation plane does not contain a reference
                           plane (annotation was created using a drawing
                           view's default orientation as its annotation plane).
      PRO_TK_EMPTY - The annotation plane orientation is frozen with respect 
                     to the reference, and the reference is currently missing 
                     from the model.

  See Also:
      ProAnnotationplaneTypeGet()
*/

extern ProError ProAnnotationplanePlaneGet (ProAnnotationPlane *plane,
                                            ProPlanedata* data);
/*
  Purpose:  Accesses the geometry of the annotation plane.

  Input Arguments:
        plane - The annotation plane handle.


  Output Arguments:
        data - Structure containing the plane origin and orientation.

  Return Values:
      PRO_TK_NO_ERROR  - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_BAD_CONTEXT - The annotation plane is flat-to-screen.

  See Also:
      ProAnnotationplaneTypeGet()
*/

extern ProError ProAnnotationplaneVectorGet (ProAnnotationPlane *plane,
                                             ProVector direction);
/*
  Purpose:  Accesses the direction vector used to determine the viewing
            side of the annotation plane.

  Input Arguments:
        plane - The annotation plane handle.


  Output Arguments:
        direction - The normal vector determining the front side of the
                    annotation plane.

  Return Values:
      PRO_TK_NO_ERROR  - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_BAD_CONTEXT - The annotation plane is flat-to-screen.

  See Also:
      ProAnnotationplaneTypeGet()
*/

extern ProError ProAnnotationplaneAngleGet (ProAnnotationPlane* plane,
                                            ProVector orientation,
                                            double* angle);
/*
    Purpose: Obtains the default orientation and the rotation angle for 
             annotations which will be placed on a given annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        plane - The annotation plane.

    Output Arguments:
        orientation - The default orientation of annotations which belong to 
                      this annotation plane.  (If no angle is applied, this is 
                      the direction that an underline would be drawn).
        angle - The assigned rotation angle in degrees for the annotation plane.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProAnnotationplaneVectorGet()
        ProAnnotationRotate()
*/

extern ProError ProAnnotationplaneFromViewCreate (ProSolid solid, ProView view,
                                                  ProAnnotationPlane* plane);
/*
  Purpose: Creates a new annotation plane from a saved model view.

  Input Arguments:
      solid - The solid model.
      view - The solid model view.

  Output Arguments:
      plane - The annotation plane.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

  See Also:
      ProAnnotationplaneCreate()
      ProAnnotationplaneFlatToScreenCreate()
*/

extern ProError ProAnnotationplaneFrozenGet (ProAnnotationPlane* plane,
                                             ProBoolean* frozen);
/*
  Purpose: Obtains whether the annotation plane orientation is frozen or not. 
           Applicable only to annotation planes governed by references.
             
  Input Arguments:
      plane - The annotation plane.

  Output Arguments:
      frozen - PRO_B_TRUE if the annotation plane is frozen, PRO_B_FALSE if 
               its driven by a reference to the plane geometry.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_BAD_CONTEXT - The annotation plane is not governed by a 
                           reference.

  See Also:
      ProAnnotationplaneTypeGet()
*/

extern ProError ProAnnotationplaneFrozenSet (ProAnnotationPlane* plane,
                                             ProBoolean frozen,
                                             ProAnnotationPlane* new_plane);
/*
  Purpose: Assigns whether the annotation plane orientation is frozen or not. 
           Applicable only to annotation planes governed by references.

  Input Arguments:
      plane - The annotation plane.
      frozen - PRO_B_TRUE if the annotation plane is frozen, PRO_B_FALSE if 
               its driven by a reference to the plane geometry.

  Output Arguments:
      new_plane - The new annotation plane after the frozen property
                  was changed.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_BAD_CONTEXT - The annotation plane is not governed by a 
                           reference.
      PRO_TK_NO_CHANGE - The annotation plane is already frozen (or
                         not frozen), no change was made.

  See Also:
      ProAnnotationplaneTypeGet()
*/

extern ProError ProAnnotationplaneViewnameGet (ProAnnotationPlane* plane,
                                               ProLine view_name);
/*
  Purpose: Obtains the name of the view that was originally used to determine 
           the orientation of the annotation plane.
           <P> Note: if the named view orientation has been changed since the 
           annotation plane was created, the orientation of the plane will 
           not match the current orientation of the view.  Use 
           ProAnnotationplanePlaneGet() to obtain the orientation of the 
           plane.

  Input Arguments:
      plane - The annotation plane.

  Output Arguments:
      view_name - The named view.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND - The annotation plane was created from a named view 
                           in the model or drawing, but that view is no 
                           longer accessible.
      PRO_TK_BAD_CONTEXT - The annotation plane was not created from a named 
                           view in the model or drawing.

  See Also:
      ProAnnotationplaneTypeGet()
*/

extern ProError ProAnnotationplaneTypeGet (ProAnnotationPlane* plane,
                                           ProAnnotationPlaneType* type);
/*
  Purpose: Obtains the annotation plane type.

  Input Arguments:
      plane - The annotation plane.

  Output Arguments:
      type - The annotation plane type.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

  See Also:
      ProAnnotationplaneReferenceGet()
      ProAnnotationplaneViewnameGet()
*/

extern ProError ProAnnotationplaneFlatToScreenCreate (ProSolid solid,
                                                   ProBoolean by_screen_point,
                                                   ProAnnotationPlane* plane);
/*
  Purpose: Returns the annnotation plane item representing a flat-to-screen 
           annotation in the model.

  Input Arguments:
      solid - The model.
      by_screen_point - PRO_B_TRUE if annotations on this plane will be 
                        located by screen point, PRO_B_FALSE if they will be 
                        located by model point

  Output Arguments:
      plane - The annotation plane.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

  See Also:
      ProAnnotationplaneCreate()
      ProAnnotationplaneFromViewCreate()
*/

extern ProError ProAnnotationRotate (ProAnnotation* annotation,
                                     double rotation);
/*
    Purpose: Assigns a rotation angle to a given annotation. 
             <P>
             <B>Note:</B> A change in rotation angle can cause a given 
             annotation to change the assigned value for its annotation plane. 
             Applications should reacquire the annotation's plane after a call 
             to this function.
             
    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        annotation - The annotation.
        rotation - The rotation angle in degrees to apply to the given annotation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The annotation does not support assigned rotation 
                             angles.
        PRO_TK_CANT_WRITE  - Could not modify the given item because
                             it has read-only access.   

    See Also:
        ProAnnotationplaneAngleGet()
*/

extern ProError ProAnnotationIsInactive (ProAnnotation* annotation, ProBoolean* is_inactive);
/*
  Purpose:  Identifies if the annotation is inactive due to missing references.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     annotation    - The annotation (note, gtol, surface finish, symbol, ref. dim., driven dim).

  Output Arguments:
     is_inactive   - PRO_B_TRUE if the annotation cannot be displayed due 
                     to missing references, PRO_B_FALSE if it can be displayed.
    
  Return Values:
         PRO_TK_NO_ERROR  - The function succeeded.
         PRO_TK_BAD_INPUTS - One or more inputs was invalid.
         PRO_TK_NO_LICENSE - License check failure.
*/


extern ProError ProAnnotationShow (ProAnnotation* annotation, 
                                   ProAsmcomppath* comp_path, 
                                   ProView view);
/*
	Purpose:  Sets an annotation to be shown.  This changes the model 
	           database to show the annotation until it is explicitly 
                   erased.

	Input Arguments:
		annotation    - The annotation (note, gtol, surface finish, 
                                symbol, ref. dim., driven dim, dimension). 
                <P>Note:  regular dimensions may only be shown in a drawing.
		comp_path     - The assembly component path.  Applicable only 
                                 if view != NULL and the view contains an 
                                 assembly including the owner model of the 
                                 annotation. Pass NULL when not required.
		view          - The drawing view.  Pass NULL to toggle the 
                                 state in the solid model.

	Output Arguments:
		none
    
	Return Values:
		PRO_TK_NO_ERROR  - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more arguments was invalid.
		PRO_TK_NO_CHANGE - The annotation is already shown in the target model.
		PRO_TK_INVALID_MATRIX - The annotation cannot be shown due to orientation conflicts in the view.
		PRO_TK_NO_LICENSE - License check failure.
                PRO_TK_NOT_DISPLAYED - Annotation is present on hidden or blank layer and so can't be shown.

	See Also:
		ProAnnotationErase()
		ProAnnotationIsShown()
		
*/

extern ProError ProAnnotationErase (ProAnnotation* annotation, ProDrawing drawing);
/*
	DEPRECATED:Since Creo 4.0
    SUCCESSORS:ProCombstateAnnotationErase
	Purpose:  Sets an annotation to be erased.  This changes the model
              database to not show the annotation until it is explicitly
              shown again.
     	 <b>Note: </b> Annotation will be erased from all combined state.
     	 You can use ProCombstateAnnotationErase() to erase annotation from particular combined state.
     
     	Input Arguments:
     		annotation    - The annotation (note, gtol, surface finish,
                            symbol, ref. dim., driven dim, dimension).
     	       <P>Note:  regular dimensions may only be erased from a drawing.
             drawing      - The drawing that shows the annotation.  Pass NULL to
                             erase the annotation in the solid model.
     
     	Output Arguments:
             none
     
     	Return Values:
     		PRO_TK_NO_ERROR  - The function succeeded.
    		PRO_TK_BAD_INPUTS - One or more arguments was invalid.
     		PRO_TK_NO_CHANGE - The annotation is not shown in the target model.
     		PRO_TK_NO_LICENSE - License check failure.
     


*/

extern ProError ProAnnotationIsShown (ProAnnotation* annotation, 
                                      ProDrawing drawing, 
                                      ProBoolean* is_shown);
/*
	Purpose:  Determines if an annotation is shown in a particular model.

	Input Arguments:
		annotation    - The annotation (note, gtol, surface finish, 
                                symbol, ref. dim., driven dim, dimension).  
		<P>Note: regular dimensions may only be shown in a drawing.
        drawing       - The drawing that shows the annotation.  Pass NULL to 
                         inquire about the annotation in the solid model.

	Output Arguments:
		is_shown      - PRO_B_TRUE if the annotation is shown, 
                                PRO_B_FALSE if it is not shown in the target 
                                 model.
    
	Return Values:
         PRO_TK_NO_ERROR  - The function succeeded.
         PRO_TK_BAD_INPUTS - One or more arguments was invalid.
         PRO_TK_NO_LICENSE - License check failure.

  	See Also:
		ProAnnotationShow()
		ProAnnotationErase()
*/

extern ProError ProAnnotationDisplay (ProAnnotation* annotation, 
                                      ProAsmcomppath* comp_path, 
                                      ProDrawing drawing, 
                                      ProView view);
/*
	Purpose:  Sets an annotation to be temporarily displayed or repainted.
                  This change is in effect only until the next window repaint.
                  The target model (owner, comp_path->owner, or drawing) must 
                  be the current model.

                  <b>Note: </b>Functions ProAnnotationDisplay and ProAnnotationUndisplay
                  should be used together. To edit a shown annotation, it must
                  be first undisplayed using ProAnnotationUndisplay, followed
                  by the editing function calls, and finally must be
                  redisplayed by calling ProAnnotationDisplay.

	Input Arguments:
		annotation    - The annotation (note, gtol, surface finish, 
                                symbol, ref. dim., driven dim, dimension). 
                comp_path     - The assembly component path. Pass NULL when 
                                not required.
                drawing	      - The drawing where the annotation should be 
                                displayed or repainted.  Pass NULL when not 
                                required.
		view          - The drawing view.  Pass NULL to when not 
                                required.  Required if the annotation is not 
                                already shown in the target drawing (determines
                                which view will house the temporary display).

	Output Arguments:
		none
    
	Return Values:
		PRO_TK_NO_ERROR  - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more arguments was invalid.
		PRO_TK_GENERAL_ERROR - The target model is not the current model.
		PRO_TK_INVALID_MATRIX - The annotation cannot be shown due to orientation conflicts in the
view.
		PRO_TK_NO_LICENSE - License check failure.
                PRO_TK_NOT_DISPLAYED - Annotation is present on hidden or blank layer and so can't be shown.
*/

extern ProError ProAnnotationUndisplay (ProAnnotation* annotation, 
                                        ProAsmcomppath* comp_path, 
                                        ProDrawing drawing);
/*
  Purpose:  Sets an annotation to be erased.  This change is in effect 
            only until the next regeneration or a corresponding call to 
            ProAnnotationDisplay.  The target model (owner , 
            comp_path->owner, or drawing) must be the current model.

  Input Arguments:
     annotation  - The annotation (note, gtol, surface finish, 
                   symbol, ref. dim., driven dim, dimension).
     comp_path   - The assembly component path.  Pass NULL when not required.
     drawing     - The drawing that displays the annotation.  
                   Pass NULL to undisplay the annotation from a solid model.

  Output Arguments:
     none
    
  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
     PRO_TK_GENERAL_ERROR - The target model is not the current model.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProAnnotationElementGet (ProAnnotation             *annotation,
					 ProAnnotationElem           *element);
/*
  Purpose:  Gets the annotation element that contains a given annotation.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
    annotation    - The annotation (note, gtol, surface finish, symbol,
                    ref. dim, driven dim).

  Output Arguments:
    element       - The annotation element that contains the annotation.
    
  Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
    PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - The annotation is not contained in any annotation 
                         element.
    PRO_TK_NOT_EXIST   - The annotation element owner of the annotation 
                         does not exist.
*/

extern ProError ProAnnotationelemHasMissingrefs( ProAnnotationElem   *element,
						 ProAnnotationRefFilter  type,
					      ProAnnotationRefFromType source,
						 ProBoolean      at_least_one,
						 ProBoolean* has_missing_refs);
/*
    Purpose: Identifies if the annotation element has a missing references 
             of mentioned type.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        element          - The annotation element.
	type             - The type of references to check 
	                   (weak, strong, or all).
        source           - The source of the references
	                   (from the annotation, from the user, or all).
        at_least_one     - For the references of specified type and source:
                           PRO_B_TRUE  -  at least one reference missed
			   PRO_B_FALSE - all references are missed.
	   
    Output Arguments:
        has_missing_refs - PRO_B_TRUE if the annotation element has missing 
                           references, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR     - The function succeeded.
        PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND  - The element has no references of the given 
type and source.

*/

extern ProError ProAnnotationelemIsReadonly( ProAnnotationElem *p_element,
					     ProBoolean        *is_readonly);
/*
    Purpose: Obtains the readonly status for the given annotation element.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        p_element   - The annotation element.

    Output Arguments:
        is_readonly - PRO_B_TRUE if the element is readonly, based on the
                      current session authentication settings.  PRO_B_FALSE if
                      the element allows full access.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProAnnotationIsAssociative (ProAnnotation* annotation,
                                            ProDrawing drawing,
                                            ProBoolean* assoc_position,
			    ProAnnotationAttachmentAssociativity* assoc_attach,
                                            ProBoolean* future_use);
/*
    Purpose: Identifies if the given annotation is associative.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        annotation - The shown annotation.
        drawing - The drawing.

    Output Arguments:
        assoc_position - PRO_B_TRUE if the position of the annotation is 
                         associative, PRO_B_FALSE otherwise.  Pass NULL if not 
                         interested in this property.
        assoc_attach - The attachment associativity.  Pass NULL if not 
                       interested in this property.
        future_use - This argument is for future use.  Pass NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The annotation is not shown in the drawing.

*/

extern ProError ProAnnotationPositionUpdate (ProAnnotation* annotation,
                                             ProDrawing drawing);
/*
    Purpose: Updates the position of the drawing annotation and makes it 
             associative to the position of the annotation in the 3D model.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        annotation - The annotation.
        drawing - The drawing.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The annotation is not shown in the drawing.

*/

extern ProError ProAnnotationAttachmentUpdate (ProAnnotation* annotation,
                                               ProDrawing drawing);
/*
    Purpose: Updates the attachment of the drawing annotation and makes it 
             associative to the attachment of the annotation in the 3D model.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        annotation - The annotation.
        drawing - The drawing.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The annotation is not shown in the drawing.

*/

extern ProError ProAnnotationUpdate (ProAnnotation* annotation, 
                                     ProDrawing drawing);
/*
  Purpose: Updates the display of the annotation, but does not actually
           display it anywhere. If the annotation is not currently displayed
           (because its hidden by layer status or inactive geometry) the text
           extracted from the annotation with mode PRODISPMODE_NUMERIC may
           include callout symbols instead of the text shown to the user.
           This method will tell Creo Parametric to update the contents of the
           annotation to cross-reference these callout values.
   	   <P>
              This function currently supports:
           <UL>
            <LI>  3D model notes (ProNote)
            <LI>  Detail notes   (ProDtlnote)
           </UL>

  Input Arguments:
    annotation - The annotation handle.
    drawing    - The drawing where it is to be displayed. Pass NULL if the
                 owner of the annotation is the same as the model where it
                 would be displayed.

  Output Arguments:
    none

  Return Values:
    PRO_TK_NO_ERROR   - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.



*/

extern ProError ProAnnotationplaneForcetoplaneflagGet (ProAnnotationPlane* plane,
                                                       ProBoolean* force_to_plane);
/*
  Purpose: Get the force-to-plane property of an annotation plane.

  Input Arguments:
      plane - The annotation plane.

  Output Arguments:
      force_to_plane - PRO_B_TRUE if the annotations are to be forced to this plane,
                       PRO_B_FALSE otherwise.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_BAD_CONTEXT - The annotation plane is not governed by a reference.
*/

extern ProError ProAnnotationplaneForcetoplaneflagSet (ProAnnotationPlane* plane,
                                                       ProBoolean force_to_plane,
                                                       ProAnnotationPlane* new_plane);
/*
  Purpose: Set the force-to-plane property of an annotation plane.

  Input Arguments:
      plane - The annotation plane.
      force_to_plane - PRO_B_TRUE if the annotations are to be forced to this plane,
                        PRO_B_FALSE otherwise.

  Output Arguments:
      new_plane - The new annotation plane after the force-to-plane property was changed.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_BAD_CONTEXT - The annotation plane is not governed by a reference.
      PRO_TK_NO_CHANGE - No change was made - the same value of the force-to-plane  property is already set.
*/

extern ProError ProAnnotationTextstyleSet (ProAnnotation* annotation,
                                           ProDrawing drawing,
                                           ProAsmcomppath* comp_path,
                                           ProView view,
                                           ProTextStyle text_style);
/*
   Purpose: Assigns the text style to an annotation.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
       annotation - The annotation.
       drawing - If the annotation is owned by solid but displayed in drawing,
                 pass the drawing here. Else pass NULL.
       comp_path - The assembly component path. Only needed for symbols that
                   are shown more than once at different component paths.
                   Otherwise, pass NULL.
       view - Reserved for future expansion. Pass NULL.
       text_style - The text style.

   Output Arguments:
       none
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
       PRO_TK_E_NOT_FOUND - No shown version of annotation was found in the drawing
*/
 
extern ProError ProAnnotationTextstyleGet (ProAnnotation* annotation,
                                           ProDrawing drawing,
                                           ProAsmcomppath* comp_path,
                                           ProView view,
                                           ProTextStyle* text_style);
/*
   Purpose: Obtains the text style assigned to an annotation.

   Licensing Requirement:
          TOOLKIT for 3D Drawings
 
   Input Arguments:
       annotation - The annotation.
       drawing - If the annotation is owned by solid but displayed in drawing,
                 pass the drawing here. Else pass NULL.
       comp_path - The assembly component path. Only needed for symbols that
                   are shown more than once at different component paths.
                   Otherwise, pass NULL.
       view - Reserved for future expansion. Pass NULL.
 
   Output Arguments:
       text_style - The text style.  Free this using ProTextStyleFree().
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
       PRO_TK_E_NOT_FOUND - No shown version of annotation was found in the drawing
       PRO_TK_E_AMBIGUOUS - Multiple shown versions of the annotation were
                             found with different text styles.
*/

extern ProError ProDetailtreeRefresh (ProSolid solid, int window_id);
/*
   Purpose: Rebuild the tree for the solid and the window_id.

   Input Arguments:
         solid - Handle to the solid which contains the detail tree.
         window_id - Id of the window which contains the solid. Use
                     PRO_VALUE_UNUSED to refresh the detail tree in the active
                     window.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
         PRO_TK_NO_CHANGE - There is no change in the detail tree.

*/

extern ProError ProDetailtreeCollapse (ProSolid solid, int window_id);
/*
    Purpose: Collapse the tree for the solid and the window_id.

    Input Arguments:
        solid - Handle to the solid which contains the detail tree.
        window_id - Id of the window which contains the solid. Use
                    PRO_VALUE_UNUSED to refresh the detail tree in the active
                    window.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_NO_CHANGE - There is no change in the detail tree.
*/


extern ProError ProDetailtreeExpand(ProSolid solid, int window_id);
/*
   Purpose: Expand the tree for the solid and the window_id.

    Input Arguments:
        solid - Handle to the solid which contains the detail tree.
        window_id - Id of the window which contains the solid. Use
                    PRO_VALUE_UNUSED to refresh the detail tree in the active
                    window.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_NO_CHANGE - There is no change in the detail tree.
*/


extern ProError ProAnnotationByViewShow ( 
   ProDrawing      draw,
   ProView         view,
   ProType         annot_type_to_show);
/*
   Purpose: Show model annotations of given type on selected drawing view. 
   <b>Note: </b> If an annotation is dependent on another annotation for 
   its display in a drawing, then the application must first show 
   the parent annotation on the drawing, followed by showing the dependent 
   annotation. For instance, if a gtol is placed on a dimension, then 
   first call ProAnnotationByViewShow for PRO_DIMENSION type and then 
   call ProAnnotationByViewShow for PRO_GTOL. If the application does not 
   show the dimension before the specified gtol, then the gtol will not be 
   displayed on the drawing.

   Input Arguments:
      draw - Drawing to show annotations on.
      view - View for which annotations need to be shown in drawing.
      annot_type_to_show - Db_type of annotations to be shown.
                           The supported ProType (of annotations) are,
                           PRO_DIMENSION
                           PRO_REF_DIMENSION
                           PRO_NOTE
                           PRO_GTOL
                           PRO_SURF_FIN
                           PRO_AXIS
                           PRO_SET_DATUM_TAG
                           PRO_SYMBOL_INSTANCE
                           PRO_DATUM_TARGET
     
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function could successfully show 
                          annotations of given type on the selected view.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - Drawing in which annotation will be shown is
                             not displayed in the current session.
      PRO_TK_INVALID_TYPE - Input annotation type not supported.
*/

extern ProError ProAnnotationByFeatureShow ( 
   ProDrawing      draw,
   ProSelection    sel_feat,
   ProView         view,
   ProType         annot_type_to_show);
/*
   Purpose: Show model annotations of given type for selected feature. 
   <b>Note: </b> If an annotation is dependent on another annotation for 
   its display in a drawing, then the application must first show 
   the parent annotation on the drawing, followed by showing the dependent 
   annotation. For instance, if a gtol is placed on a dimension, then 
   first call ProAnnotationByViewShow for PRO_DIMENSION type and then 
   call ProAnnotationByViewShow for PRO_GTOL. If the application does not 
   show the dimension before the specified gtol, then the gtol will not be 
   displayed on the drawing.

   Input Arguments:
      draw - Drawing to show annotations on.
      sel_feat -  Feature for which annotations need to be shown in drawing.
      view     -  For selected feature show valid annotations in given 
                  input view.  This is same as doing "ShowByFeatureAndView" 
                  If view is NULL, the behavior is the same as for 
                  ProAnnotationByFeatureShow.
                  This argument is reserved for future use. 
                  Pass NULL in Creo2 M050 release
      annot_type_to_show - Db_type of annotations to be shown.
                           The supported ProType (of annotations) are,
                           PRO_DIMENSION
                           PRO_REF_DIMENSION
                           PRO_NOTE
                           PRO_GTOL
                           PRO_SURF_FIN
                           PRO_AXIS
                           PRO_SET_DATUM_TAG
                           PRO_SYMBOL_INSTANCE
                           PRO_DATUM_TARGET

     
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function could successfully show 
                          annotations of given type on
                          the selected target.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - Drawing in which annotation will be shown is
                             not displayed in the current session.
      PRO_TK_INVALID_TYPE - Input annotation type not supported.
*/

extern ProError ProAnnotationByComponentShow ( 
   ProDrawing      draw,
   ProSelection    sel_component,
   ProView         view,
   ProType         annot_type_to_show);
/*
   Purpose: Show model annotations of given type for selected component. 
   <b>Note: </b> If an annotation is dependent on another annotation for 
   its display in a drawing, then the application must first show 
   the parent annotation on the drawing, followed by showing the dependent 
   annotation. For instance, if a gtol is placed on a dimension, then 
   first call ProAnnotationByViewShow for PRO_DIMENSION type and then 
   call ProAnnotationByViewShow for PRO_GTOL. If the application does not 
   show the dimension before the specified gtol, then the gtol will not be 
   displayed on the drawing.

   Input Arguments:
     draw - Drawing to show annotations on.
     sel_component -  Component for which annotations need to be shown 
                      in drawing.
     view     -  For selected component show valid annotations in given 
                 input view.  This is same as doing "ShowByComponentAndView" 
                 If view is NULL, the behavior is the same as for 
                 ProAnnotationByComponentShow.
                 This argument is reserved for future use. 
                 Pass NULL in Creo2 M050 release
     annot_type_to_show - Db_type of annotations to be shown.
                          The supported ProType (of annotations) are,
                          PRO_DIMENSION
                          PRO_REF_DIMENSION
                          PRO_NOTE
                          PRO_GTOL
                          PRO_SURF_FIN
                          PRO_AXIS
                          PRO_SET_DATUM_TAG
                          PRO_SYMBOL_INSTANCE
                          PRO_DATUM_TARGET
     
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function could successfully show 
                          annotations of given type on
                          the selected target.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - Drawing in which annotation will be shown is
                             not displayed in the current session.
      PRO_TK_INVALID_TYPE - Input annotation type not supported.
*/

extern ProError ProDrawingDimensionsCleanup ( 
   ProDrawing        draw,
   ProView           view);
/*
   Purpose: Clean up dimensions for input view if p_view is a valid view. Else,
            clean up dimensions view-by-view for each view of the input drawing
            if input p_view is NULL

            <p><b>NOTE:</b> Use ProMdlDetailOptionSet() to set options before
            calling this API. If not used, the API will use current detail options.</p>	

   Input Arguments:
      draw - Drawing to clean up dimensions for.
      view - View for which dimensions should be cleaned up.
             If NULL, clean up the dimensions for 
             all the views of the drawing.
     
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function could successfully 
                          clean up dimensions of the drawing.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - Drawing in which dimensions will be cleaned up
                             is not displayed in the current session.
*/

extern ProError ProDrawingAnnotationErase (ProDrawing drawing,ProAnnotation* annotation);
/*
	Purpose:  Sets an annotation to be erased from drawing.  This changes the drawing
                  database to not show the annotation until it is explicitly
                  shown again.
	 
	Input Arguments:		
		drawing      - The drawing that shows the annotation.
		annotation    - The annotation (note, gtol, surface finish,
                                symbol, ref. dim., driven dim, dimension).	         

	Output Arguments:
        none

	Return Values:
		PRO_TK_NO_ERROR  - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more arguments was invalid.
		PRO_TK_NO_CHANGE - The annotation is not shown in the target model.		

	See Also:
		ProAnnotationShow()
		ProAnnotationIsShown()
		ProCombstateAnnotationErase()
*/

extern ProError ProAnnotationLegacyConvert (ProAnnotation* annotation);
/*
Purpose:  Converts annotation created before Creo 4.0 or 
          created using deprecated APIs ProGtolCreate or ProSetdatumtagCreate.
 
Input Arguments: 
annotation    - The annotation ( gtol, ref. dim., driven dim, 
                                 set datum tag ).         

Output Arguments:
        none

Return Values:
PRO_TK_NO_ERROR  - The function succeeded.
PRO_TK_BAD_INPUTS - One or more arguments was invalid.
PRO_TK_NO_CHANGE - The annotation is not legacy
 
*/

PRO_END_C_DECLS
#endif /* PROANNOTATION_H */
