#ifndef PROSETDATUMTAG_H_
#define PROSETDATUMTAG_H_


#include <ProToolkit.h>
#include <ProSelection.h>
#include <ProNote.h>


PRO_BEGIN_C_DECLS



typedef struct pro_model_item ProSetDatumTag;

typedef enum pro_dtm_feat_addl_text_pos
{
  PRO_DTM_FEAT_ADDL_TEXT_RIGHT,
  PRO_DTM_FEAT_ADDL_TEXT_BOTTOM,
  PRO_DTM_FEAT_ADDL_TEXT_LEFT,
  PRO_DTM_FEAT_ADDL_TEXT_TOP,
  PRO_DTM_FEAT_ADDL_TEXT_DEFAULT
}ProDtmFeatAddlTextPos;


extern ProError ProGeomitemSetdatumtagGet (ProGeomitem* item,
                                           ProSetDatumTag* set_datum_tag);
/*
    Purpose: Obtains the set datum tag referring to this geometry item, if it
             exists.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        item - The geometry item.

    Output Arguments:
        set_datum_tag - The set datum tag annotation.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - There is no set datum tag annotation  for the
                             given geometry.

*/

extern ProError ProSetdatumtagPlaneGet (ProSetDatumTag* tag,
                                        ProAnnotationPlane* plane);
/*
    Purpose: Obtains the annotation plane for a set datum tag.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag annotation.

    Output Arguments:
        plane - The annotation plane.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagAttachmentGet (ProSetDatumTag* tag,
                                             ProSelection* attachment);
/*
    Purpose: Obtains the item to which the set datum tag is attached
             (dimension, gtol, or geometry).

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        attachment - The attachment. (Caller should free memory of
                     *attachment by using ProSelectionFree().)

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The set datum tag attachment is to the datum
                             itself.

*/

extern ProError ProSetdatumtagReferenceGet (ProSetDatumTag* tag,
                                            ProGeomitem* reference);
/*
    Purpose: Obtains the geometry item used as the set datum.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        reference - The geometry of the set datum.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagReferencesAdd( ProSetDatumTag         *dfs, 
                                             ProAnnotationReference *refs );
/*
   Purpose:   Add DFS semantic references

   Input Arguments:
      dfs   - valid DFS.
      refs  - ProArray of DFS references.

   Output Arguments:


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProSetdatumtagReferencesGet( ProSetDatumTag          *dfs,
                                             ProAnnotationReference **refs );
/*
   Purpose:  Get DFS semantic references

   Input Arguments:
      dfs    - valid DFS.

   Output Arguments:
      refs   - ProArray of DFS references. Free it using ProArrayFree()

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProSetdatumtagReferenceDelete( ProSetDatumTag *dfs, 
                                               int             index );
/*
   Purpose:   Delete DFS semantic reference

   Input Arguments:
      dfs    - valid DFS.
   index     - Indices start from 0. Get existing references from 
               ProSetdatumtagReferencesGet()

   Output Arguments:

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/


extern ProError ProSetdatumtagTextstyleGet (ProSetDatumTag* tag,
                                            ProTextStyle* text_style);
/*
        DEPRECATED: Since Creo 1
    SUCCESSORS: ProAnnotationTextstyleGet
    Purpose: <P><B>Note:</B> This function is deprecated. Use
              ProAnnotationTextstyleGet() instead.</P>
              Obtains the text style for the set datum tag.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.

    Output Arguments:
        text_style - The text style.  Free this using ProTextstyleFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagTextstyleSet (ProSetDatumTag* tag,
                                            ProTextStyle text_style);
/*
        DEPRECATED: Since Creo 1
    SUCCESSORS: ProAnnotationTextstyleSet
    Purpose: <P><B>Note:</B> This function is deprecated. Use
              ProAnnotationTextstyleSet() instead.</P>
              Assigns the text style for the set datum tag.
            <P><B>Note:</B>Angle and Mirror properties cannot be set.
                They can be set only for Notes and Dimensions.</P>

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.
        text_style - The text style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProSetdatumtagPlaneSet (ProSetDatumTag* tag,
                                        ProAnnotationPlane* plane);
/*
    Purpose: Assigns the annotation plane for a set datum tag.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag annotation.
        plane - The annotation plane.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSetdatumtagAttachmentSet (ProSetDatumTag* tag,
                                             ProSelection attachment);
/*
    Purpose: Assigns the item to which the set datum tag is attached.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.
        attachment - The attachment. Use NULL to attach the tag to its
              datum plane, or to the default position on its axis.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef ProError (*ProSetdatumtagFilterAction) (ProSetDatumTag* set_datum_tag,
                                                ProAppData app_data);
/*
    Purpose: Filter action for visiting set datum tags.

    Input Arguments:
        set_datum_tag - The set datum tag.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Skip the visit action for this annotation.
        Any other value - Calll the vist action for this annotation.  This
                          status will be passed to the visit action.

*/

typedef ProError (*ProSetdatumtagVisitAction) (ProSetDatumTag* set_datum_tag,
                                               ProError error,
                                               ProAppData app_data);
/*
    Purpose: Visit action for visiting set datum tags.

    Input Arguments:
        set_datum_tag - The set datum tag.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProSolidSetdatumtagVisit (ProSolid solid,
                                          ProSetdatumtagVisitAction action,
                                          ProSetdatumtagFilterAction filter,
                                          ProAppData app_data);
/*
    Purpose: Visits the set datum tag annotations in a solid model.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        solid - The part or assembly.
        action - The visit action
        filter - The filter action.  Can be NULL.
        app_data - Application data passed to the action functions.  Can be
                   NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No set datum tag annotations were found in the
                             model.
        Any other value - The value returned by the visit action to stop
                          visiting.

*/

extern ProError ProSetdatumtagCreate (ProGeomitem* reference,
                                      ProAnnotationPlane* annotation_plane,
                                      ProSelection attachment,
                                      ProSetDatumTag* tag);
/*
	DEPRECATED: Since Creo 4.0
	SUCCESSORS: ProMdlSetdatumtagCreate
    Purpose: Create a new set datum tag annotation. ProAnnotationShow()
    should be called after creating the annotation in order for the annotation
    to be displayed.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        reference - The set datum tag annotation reference.
        annotation_plane - The annotation plane. If the attachment is to a
                           dimension or gtol, can be NULL.
        attachment - The attachment location, for set datum tags on geometry.
                     Can be NULL.

    Output Arguments:
        tag - The new set datum tag.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - Invalid reference type for a set datum.
        PRO_TK_E_AMBIGUOUS - The annotation plane cannot be used in conjunction
                             with the properties of the reference item or
                             attachment.
        PRO_TK_E_FOUND - The geometry reference is already a set datum.

*/


extern ProError ProMdlSetdatumtagCreate (ProMdl p_mdl, ProSelection attachment,
                                         ProAnnotationPlane* annotation_plane,
                                         wchar_t *label,
                                         ProSetDatumTag *r_dfs);
/*
    Purpose: Create a new datum feature symbol annotation. ProAnnotationShow()
    should be called after creating the annotation in order for the annotation
    to be displayed.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        p_mdl - solid or drawing.
        attachment - attachment reference.
        annotation_plane - The annotation plane. If the attachment is to a
                           dimension or gtol, can be NULL.
                           For drawing, annotation plane should be NULL.
        label - label of datum feature symbol

    Output Arguments:
        r_dfs - new datum feature symbol

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        
        PRO_TK_E_AMBIGUOUS - The annotation plane cannot be used in conjunction
                             with the properties of the
                             attachment.        

*/

extern ProError ProMdlSetdatumtagDelete (ProSetDatumTag* symbol);
/*
    Purpose: Delete a new datum feature symbol annotation.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        symbol - new datum feature symbol

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        
        PRO_TK_CANT_MODIFY - Cannot delete set datum tag.    

*/

extern ProError ProSetdatumtagLabelSet (ProSetDatumTag* dfs, wchar_t* lbl);
/*
    Purpose: Sets label to datum feature symbol annotation             

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
              lbl - label of datum feature symbol             

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagLabelGet (ProSetDatumTag* dfs, wchar_t** lbl);
/*
    Purpose: Get label of datum feature symbol annotation             

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.         

    Output Arguments:
        lbl - label of datum feature symbol. Free it using ProWstringFree()

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagAdditionalTextSet (ProSetDatumTag* dfs, wchar_t* lbl,
                                                 ProDtmFeatAddlTextPos  addlTextPos);
/*
    Purpose: Sets Additional text and Position to datum feature symbol annotation             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        lbl - label of datum feature symbol.
		addlTextPos - position where the Additional text Appears. Default position is Right

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagAdditionalTextGet (ProSetDatumTag* dfs, wchar_t** lbl,
                                                 ProDtmFeatAddlTextPos*  addlTextPos);
/*
    Purpose: Gets Additional text and Position to datum feature symbol annotation             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        
    Output Arguments:
       lbl - label of datum feature symbol. Free it using ProWstringFree()
       addlTextPos - position where the Additional text Appears.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.        

*/
extern ProError ProSetdatumtagElbowSet (ProSetDatumTag* dfs, ProBoolean elbow);
/*
    Purpose: Sets or unset Elbow to datum feature symbol annotation             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        elbow - leader - Pass PRO_B_TRUE to set Elbow display otherwise PRO_B_FALSE

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.     
        PRO_TK_CANT_MODIFY - datum feature symbol annotation can't be modified.

*/
extern ProError ProSetdatumtagElbowGet (ProSetDatumTag* dfs, ProBoolean* elbow);
/*
    Purpose: Outputs whether a specified datum feature symbol annotation Elbow is set. 

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        

    Output Arguments:
        elbow - PRO_B_TRUE if dfs has Elbow display otherwise PRO_B_FALSE

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_CANT_ACCESS - datum feature symbol annotation can't be accessed.

*/
extern ProError ProSetdatumtagASMEDisplayGet (ProSetDatumTag* dfs, ProBoolean *asme);
/*
    Purpose: Outputs whether a specified datum feature symbol annotation ASME is set.         

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.

    Output Arguments:
        asme - PRO_B_TRUE if symbol has ASME display otherwise PRO_B_FALSE

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.    
        PRO_TK_CANT_ACCESS - datum feature symbol annotation can't be accessed.

*/
extern ProError ProSetdatumtagASMEDisplaySet (ProSetDatumTag* dfs, ProBoolean asme);
/*
    Purpose: Set or unset ASME display of datum feature symbol annotation.            

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        dfs - datum feature symbol annotation.
        asme - Pass PRO_B_TRUE to set ASME display otherwise PRO_B_FALSE

    Output Arguments:
        none
       
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.  
        PRO_TK_CANT_MODIFY - datum feature symbol annotation can't be modified.

*/
extern ProError ProSetdatumtagTextLocationGet (ProSetDatumTag* dfs,ProDrawing drw, Pro3dPnt pnt);
/*
    Purpose: Gets text point of datum feature symbol.

        Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        tag - The set datum tag.
        drw - Pass drawing for dfs owned by solid and shown in drawing. Pass NULL otherwise. 

    Output Arguments:
        pnt - point

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

PRO_END_C_DECLS

#endif
