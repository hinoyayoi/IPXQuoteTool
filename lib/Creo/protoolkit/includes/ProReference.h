#ifndef PRO_REFERENCE_H
#define PRO_REFERENCE_H



PRO_BEGIN_C_DECLS

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProRefInfo.h>
#include <ProSelection.h>

typedef void* ProReference;

/*===========================================================================*/
extern ProError ProReferenceAlloc (ProReference* reference);
/* 
   Purpose: Allocates a reference handle.

   Input Arguments: 
         none
        
   Output Arguments:
         reference          - The allocated reference handle.

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - The argument was invalid.
*/

/*===========================================================================*/
extern ProError ProReferenceTypeGet (ProReference reference, ProType* type);
/* 
   Purpose: Gets the type of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         type               - The item type that is referenced.
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceOriginaltypeGet( ProReference reference,
                                             ProType*     type );
/*
   Purpose: Gets the original type of a reference handle.
            This could be different from the actively used type
            if the reference has been backed up, copied locally,
            or replaced  with an alternate.

   Input Arguments:
         reference          - The reference handle.

   Output Arguments:
         type               - The original item type that was referenced.

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference
                              (it is the same as the current type).

   See Also:
                ProReferenceIsLocalcopy()
                ProReferenceIsAlternate()
                ProReferenceStatusGet()
*/

/*===========================================================================*/
extern ProError ProReferenceIdGet (ProReference reference, int* id);
/* 
   Purpose: Gets the item id of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         id                 - The item id that is referenced.
           
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceOriginalidGet( ProReference reference, int* id );
/* 
   Purpose: Gets the original id of a reference handle. 
            This could be different from the actively used id 
            if the reference has been backed up, copied locally, 
            or replaced  with an alternate.  
  
   Input Arguments: 
         reference          - The reference handle.
      
   Output Arguments:
         id                 - The original item id that is referenced.
            
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference 
                              (it is the same as the current id).

   See Also:
                ProReferenceIsLocalcopy()
                ProReferenceIsAlternate()
                ProReferenceStatusGet()
*/

/*===========================================================================*/
extern ProError ProReferenceOwnerGet (ProReference reference, ProMdl* mdl);
/* 
   Purpose: Gets the reference owner model of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
   
   Output Arguments:
         mdl                - The item owner model that is referenced.
           
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceOriginalownerGet( ProReference reference, 
                                              ProMdl*      mdl );
/* 
   Purpose:  Gets the original owner model of a reference handle. 
             This could be different from the actively used owner 
             if the reference has been backed up, copied locally, 
             or replaced  with an alternate.  
 
   Input Arguments: 
         reference          - The reference handle.
      
   Output Arguments:
         mdl                - The original owner model that is referenced.  
            
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference 
                              (it is the same as the current owner).
         PRO_TK_E_NOT_FOUND - The original reference model is not in session.

   See Also:
                ProReferenceIsLocalcopy()
                ProReferenceIsAlternate()
                ProReferenceStatusGet()
*/

/*===========================================================================*/
extern ProError ProReferenceOwnernameGet (ProReference  reference, 
                                          ProFamilyName mdl_name);
/* 
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProReferenceOwnerMdlnameGet
   Purpose: <b>Note:</b> This function is deprecated
            Use ProReferenceOwnerMdlnameGet instead.

            Gets the reference owner model name of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         mdl_name           - The item owner model name that is referenced.
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

extern ProError ProReferenceOwnerMdlnameGet (ProReference  reference, 
						 ProFamilyMdlName mdl_name);
/* 
   Purpose: Gets the reference owner model name of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         mdl_name           - The item owner model name that is referenced.

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceOriginalownernameGet( ProReference  reference, 
                                                  ProFamilyName mdl_name );
/* 
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProReferenceOriginalownerMdlnameGet
   Purpose: <b>Note:</b> This function is deprecated
            Use ProReferenceOriginalownerMdlnameGet instead.

            Gets the original owner model name of a reference handle. 
            This could be different from the actively used owner name 
            if the reference has been backed up, copied locally, 
            or replaced  with an alternate.  
 
   Input Arguments: 
         reference          - The reference handle.
      
   Output Arguments:
         mdl_name           - The item owner model name that is referenced.
            
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference 
                              (it is the same as the current owner).

   See Also:
                ProReferenceIsLocalcopy()
                ProReferenceIsAlternate()
                ProReferenceStatusGet()
*/

extern ProError ProReferenceOriginalownerMdlnameGet( ProReference  reference, 
							 ProFamilyMdlName mdl_name );
/* 
   Purpose: Gets the original owner model name of a reference handle. 
            This could be different from the actively used owner name 
            if the reference has been backed up, copied locally, 
            or replaced  with an alternate.  
 
   Input Arguments: 
         reference          - The reference handle.
      
   Output Arguments:
         mdl_name           - The item owner model name that is referenced.

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference 
                              (it is the same as the current owner).

   See Also:
                ProReferenceIsLocalcopy()
                ProReferenceIsAlternate()
                ProReferenceStatusGet()
*/

/*===========================================================================*/
extern ProError ProReferenceSet (ProReference    reference, 
                                 ProAsmcomppath* path,
                                 ProModelitem*   item);
/* 
   Purpose: Sets the referenced model item and path in the reference handle.

   Input Arguments: 
         reference          - The reference handle.
         path               - The component path. If NULL, reference handle will
                            be set as local reference.
         item               - The model item handle. If NULL, model item from 
                            ProAsmcomppathMdlGet() -> ProMdlToModelitem()
                            will be set to reference handle. 
       
                            Both item and path cannot be NULL.
        
   Output Arguments:
         none
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/*===========================================================================*/
extern ProError ProReferenceAsmcomppathGet (ProReference    reference, 
                                            ProAsmcomppath* path);
/* 
   Purpose: Gets the component path of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         path               - The component path that is referenced.
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceParamsGet (ProReference reference, 
                                       ProUvParam   params);
/* 
   Purpose: Gets the uv parameters of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         params             - The uv parameters.
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceParamsSet (ProReference reference, 
                                       ProUvParam   params);
/* 
   Purpose: Sets the uv parameters of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
         params             - The uv parameters.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/*===========================================================================*/
extern ProError ProReferencePointGet (ProReference reference, 
                                      Pro3dPnt     point);
/* 
   Purpose: Gets the selected point of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         point              - The point, in coordinates of the owner model.
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferencePointSet (ProReference reference, 
                                      Pro3dPnt     point);
/* 
   Purpose: Sets the selected point of a reference handle.

   Input Arguments: 
         reference          - The reference handle.
         point              - The point, in coordinates of the owner model.
        
   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/*===========================================================================*/
extern ProError ProReferenceIsLocalcopy (ProReference reference, 
                                         ProBoolean*  is_local);
/* 
   Purpose: Identifies if the reference is a local copy of the 
            external reference

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         is_local           - PRO_B_TRUE if the reference contains a local copy 
                            of an external reference.
                            PRO_B_FALSE if the reference contains the true 
                            reference item (local or external)
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/ 

/*===========================================================================*/
extern ProError ProReferenceIsAlternate (ProReference reference,
                                         ProBoolean*  is_alternate);
/*
   Purpose: Identifies if the reference is a alternate to original reference

   Input Arguments:
         reference          - The reference handle.

   Output Arguments:
         is_alternate       - PRO_B_TRUE if the reference is alternate to
                            original reference.
                            PRO_B_FALSE if the reference is the true
                            reference item.

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceStatusGet (ProReference reference, 
                                       ProRefState* status);
/* 
   Purpose:  Identifies the status of the reference.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         status             - The reference status.
                
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
*/

/*===========================================================================*/
extern ProError ProReferenceToSelection (ProReference  reference, 
                                         ProSelection* selection);
/* 
   Purpose: Gets and allocates a ProSelection containing a representation 
            for this reference.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         selection          - The resulting ProSelection handle.  
                            Note that this does not contain reference specific 
                            information like local copy flags, and status.
                            This selection is separately allocated and 
                            should be freed using ProSelectionFree().
                                               
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
         PRO_TK_EMPTY       - This value is not set in the reference.
         PRO_TK_INVALID_PTR - The reference cannot be converted to a 
                            viable selection. 
*/

/*===========================================================================*/
extern ProError ProSelectionToReference (ProSelection  selection, 
                                         ProReference* reference);
/* 
   Purpose: Gets and allocates a ProReference containing a representation
            for this selection.

   Input Arguments: 
         selection          - The selection handle.
        
   Output Arguments:
         reference          - The resulting ProReference handle.  
                            This reference is separately allocated and 
                            should be freed using ProReferenceFree().            
   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/*===========================================================================*/
extern ProError ProReferencearrayToSelections ( ProReference*  references, 
                                                ProBoolean     skip_unusable, 
                                                ProSelection** selections);
/* 
   Purpose: Converts a reference ProArray to a selection ProArray.

   Input Arguments: 
         references         - The ProArray of reference handles.
         skip_unusable      - PRO_B_TRUE to skip the processing of missing
                            references that cannot be valid selections.  
                            PRO_B_FALSE to process all references.
        
   Output Arguments:
         selections         - ProArray of selection handles.
                            Free this array using ProSelectionarrayFree().

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/*===========================================================================*/
extern ProError ProSelectionarrayToReferences (ProSelection*  selections, 
                                               ProReference** references);
/* 
   Purpose: Converts a selection ProArray to a reference ProArray.

   Input Arguments: 
         selections         - ProArray of selection handles.  
                
   Output Arguments:
         references         - The ProArray of reference handles.  
                            Free this array using ProReferencearrayFree().

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/


/*===========================================================================*/
extern ProError ProReferenceFree (ProReference reference);
/* 
   Purpose: Frees a reference handle.

   Input Arguments: 
         reference          - The reference handle.
        
   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/*===========================================================================*/
extern ProError ProReferencearrayFree (ProReference* references);
/* 
   Purpose:  Frees a reference ProArray.  
             This function also free each ProReference handle using 
             ProReferenceFree.

   Input Arguments: 
         references         - The ProArray of reference handles.
        
   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

PRO_END_C_DECLS
#endif /* PRO_REFERENCE_H */
