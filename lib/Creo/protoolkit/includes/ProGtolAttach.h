

#ifndef PROGTOLATTACH_H
#define PROGTOLATTACH_H

#include <ProObjects.h>
#include <ProGtol.h>
#include <ProDimension.h>

PRO_BEGIN_C_DECLS

typedef enum
{
	PRO_GTOL_ATTACH_DATUM,
	PRO_GTOL_ATTACH_ANNOTATION,
	PRO_GTOL_ATTACH_ANNOTATION_ELBOW,   
	PRO_GTOL_ATTACH_FREE,   
	PRO_GTOL_ATTACH_LEADERS,
	PRO_GTOL_ATTACH_OFFSET,
	PRO_GTOL_ATTACH_MAKE_DIM
} ProGtolAttachType;

typedef enum
{
	PRO_GTOL_LEADER,
	PRO_GTOL_NORMAL_LEADER,
	PRO_GTOL_TANGENT_LEADER

} ProGtolLeaderAttachType;

extern ProError ProGtolAttachAlloc(ProMdl top_model, ProGtolAttach *r_gtol_attach);
/*
   Purpose:    Allocates ProGtolAttach structure

   Input Arguments:  	   
     top_model    - Top Model

   Output Arguments:
     r_gtol_attach  - attach structure.

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/
extern ProError ProGtolAttachFree (ProGtolAttach *p_gtol_attach);
/*
   Purpose:    Free  ProGtolAttach structure

   Input Arguments:
     p_gtol_attach  - attach structure.	  

   Output Arguments:      	

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/
extern ProError ProGtolAttachFreeSet (ProGtolAttach gtol_attach, ProAnnotationPlane *plane, Pro3dPnt location);
/*
   Purpose:  Set Free type attachment

   Input Arguments:
    gtol_attach - attach structure.
	  plane       - annotation plane. Can be NULL for drawing gtols
	  location    - location of gtol text. (in model co-ordinates)

   Output Arguments:      

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachFreeGet (ProGtolAttach gtol_attach, ProAnnotationPlane *plane, Pro3dPnt location);
/*
   Purpose:    Get Annotation Plane and location from Free type ProGtolAttach

   Input Arguments:
     gtol_attach    - attach structure.	  

   Output Arguments:
     plane    - annotation plane. 
     location - location of gtol text. (in model co-ordinates)

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachLeadersSet(ProGtolAttach gtol_attach, ProAnnotationPlane* plane, ProGtolLeaderAttachType type, ProGtolleader *leaders, Pro3dPnt location);
/*
   Purpose:    Set leader type attachment

   Input Arguments:
     gtol_attach - attach structure.
	   plane       - annotation plane. Can be NULL for drawing gtols
	   type        - type of leader
	   leaders     - ProArray of ProGtolleader. Pass single leader for type PRO_GTOL_NORMAL_LEADER and PRO_GTOL_TANGENT_LEADER
	   location    - location of gtol text (in model co-ordinates)

   Output Arguments:      

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachLeadersGet(ProGtolAttach gtol_attach, ProAnnotationPlane* plane, ProGtolLeaderAttachType *type, ProGtolleader** leaders, Pro3dPnt location);
/*
   Purpose:    Get leader attachment info.

   Input Arguments:
     gtol_attach    - attach structure.	  

   Output Arguments:
     plane    - annotation plane. Can be NULL for drawing gtols
     type     - type of leader
     leaders  - NULL or ProArray of ProGtolleader . Free it using ProArrayFree()
     location - location of gtol text (in model co-ordinates)

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachOnDatumSet (ProGtolAttach gtol_attach, ProModelitem *datum);
/*
   Purpose:   Set datum gtol Attach

   Input Arguments:
     gtol_attach - attach structure.
     datum - Datum Feature Symbol annotation or Legacy Set datum tag annotation.

   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/
extern ProError ProGtolAttachOnDatumGet (ProGtolAttach gtol_attach, ProModelitem *datum);
/*
   Purpose:   Get datum from gtol Attach

   Input Arguments:
     gtol_attach - attach structure.	 

   Output Arguments: 
     datum - Datum Feature Symbol annotation or Legacy Set datum tag annotation.

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/
extern ProError ProGtolAttachTypeGet (ProGtolAttach gtol_attach, ProGtolAttachType *type);
/*
   Purpose:    Gets type of ProGtolAttach.

   Input Arguments:
     gtol_attach - attach structure.

   Output Arguments:
     type - type of Attach

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachSet (ProGtol *gtol, ProGtolAttach gtol_attach);
/*
   Purpose:   Change gtol Attach

   Input Arguments:
     gtol         - Valid gtol.
     gtol_attach  - ProGtolAttach structure.

   Output Arguments:      

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_CANT_MODIFY    - Gtol Attach is invalid.
     PRO_TK_GENERAL_ERROR  - An error occurred and the function failed.
     PRO_TK_NOT_VALID      - Gtol Attach is not valid for Gtol.
*/

extern ProError ProGtolAttachGet (ProGtol *gtol, ProGtolAttach *r_gtol_attach);
/*
   Purpose:   get gtol Attach

   Input Arguments:
      gtol  - valid gtol.	 

   Output Arguments:      
	   r_gtol_attach - ProGtolAttach structure. Free it using ProGtolAttachFree();

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.  	  
*/

extern ProError ProGtolAttachOnAnnotationSet(ProGtolAttach gtol_attach, ProAnnotation *p_annot, ProBoolean elbow);
/*
   Purpose:   Set annotation related gtol Attach

   Input Arguments:
     gtol_attach - attach structure.     
     p_annot     - PRO_DIMENSION, PRO_GTOL, PRO_NOTE for solid gtols.
                   PRO_DIMENSION, PRO_GTOL, PRO_NOTE for drawing gtols.
     elbow       - attach to elbow instead of text. elbow should be PRO_B_TRUE
                   if p_annot is of type PRO_NOTE
     
   Output Arguments:      

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachOnAnnotationGet(ProGtolAttach gtol_attach, ProAnnotation *p_annot);
/*
   Purpose:   Get annotation from gtol Attach

   Input Arguments:
     gtol_attach - attach structure.
	 
   Output Arguments: 
     p_annot - annotation     

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachOffsetItemSet(ProGtolAttach gtol_attach, ProSelection offset_ref, ProVector offset);
/*
   Purpose:   Set offset gtol Attach
   Use this function along with ProMdlGtolCreate for creating offset
   type gtol, only in drawing.

   Input Arguments:
     gtol_attach     - attach structure.     
     offset_ref - dimension,dimension arrow,gtol,note,symbol instance
     offset     - offset location (in model co-ordinates)

   Output Arguments:      

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/
extern ProError ProGtolAttachOffsetItemGet(ProGtolAttach gtol_attach, ProSelection *offset_ref, ProVector offset);
/*
   Purpose:   Get offset ref from gtol Attach

   Input Arguments:
     gtol_attach - attach structure.
	 
   Output Arguments:     
     offset_ref - ref, NULL or valid ProSelection
     offset     - offset location (in model co-ordinates)

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolAttachMakeDimSet(ProGtolAttach gtol_attach, ProAnnotationPlane *plane, ProDimAttachment *attachments_arr, ProDimSense *dsense_arr, ProDimOrient orient_hint, Pro3dPnt location);
/*
   Purpose:   Set make dim type gtol attach
   Use this function along with ProMdlGtolCreate for creating make-dim
   type gtol, only in drawing.

   Input Arguments:
     gtol_attach     - attach structure.
     plane           - annotation plane.
     attachments_arr - ProArray of pair of selections.
     dsense_arr      - ProArray of ProDimSense
     orient_hint     - orientation hint
     location        - text location.

   Output Arguments:      

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolAttachMakeDimGet(ProGtolAttach gtol_attach, ProAnnotationPlane *plane, ProDimAttachment **attachments_arr, ProDimSense **dsense_arr, ProDimOrient *orient_hint, Pro3dPnt location);
/*
   Purpose:   Get make dim information from gtol attach

   Input Arguments:
     gtol_attach     - attach structure.	 

   Output Arguments: 
     plane           - annotation plane.
     attachments_arr - ProArray of pair of selections.
     dsense_arr      - ProArray of ProDimSense
     orient_hint     - orientation hint
     location        - text location.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

PRO_END_C_DECLS
#endif /* PROGTOLATTACH_H */
