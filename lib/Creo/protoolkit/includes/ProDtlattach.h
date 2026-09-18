#ifndef PRODTLATTACH_H
#define PRODTLATTACH_H
			


#include <ProDtlitem.h>
#include <ProView.h>
#include <ProSelection.h>
#include <ProGtol.h>

typedef struct prodtl_attach_new *ProDtlattach;

typedef enum pro_dtlattach_type
{
    PRO_DTLATTACHTYPE_FREE = 1,
    PRO_DTLATTACHTYPE_PARAMETRIC = 2,
    PRO_DTLATTACHTYPE_UNIMPLEMENTED = 3,
    PRO_DTLATTACHTYPE_OFFSET = 4
} ProDtlattachType;

PRO_BEGIN_C_DECLS

extern ProError ProDtlattachAlloc(
    ProDtlattachType type, 
    ProView    view, 
    ProVector   location, 
    ProSelection   attach_point, 
    ProDtlattach   *attachment);
/*

Purpose: Allocate and initialize the memory for a detail attachment. 
        User must release the memory by ProDtlattachFree.

Input Arguments:

    type            - The attachment type (FREE, PARAMETRIC or OFFSET).
    view            - The view.  Use only if the attachment type is set to 
                       PRO_DTLATTACHTYPE_FREE, to make an attachment relative 
		       to a drawing view. Use NULL to attach to a point 
		       unconnected to a drawing view and for solid model 
		       annotations.
    location        - The attachment location.  Use if
                       the attachment type is set to PRO_DTLATTACHTYPE_FREE 
		       or PRO_DTLATTACHTYPE_OFFSET.
		       For drawing objects and symbols and surface finish on
		       flat-to-screen annotation planes, this should be in
		       screen coordinates.  For symbols and surface finish on
		       3D model annotation planes, this should be in model 
		       coordinates.
    attach_point    - The attachment point.  Use if the attachment type is
                       PRO_DTLATTACHTYPE_PARAMETRIC or 
		       PRO_DTLATTACHTYPE_OFFSET.
		       For drawing attachments, the drawing view and 
		       attachment reference must be specified as a part of 
		       this structure created using ProSelect(), or by using 
		       ProSelectionAlloc () plus ProSelectionViewSet() and 
		       ProSelectionPoint3dSet().
    
Output Arguments:
    attachment      - The new detail attachment.

Return Values:

    PRO_TK_NO_ERROR      - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_INVALID_TYPE  - Bad type.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlattachFree(
    ProDtlattach attachment);
/*

Purpose: Release the memory that was allocated by ProDtlattachAlloc.  

Input Arguments:
    attachment    - The detail attachment.
    
Output Arguments:

    None
    
Return Values:

    PRO_TK_NO_ERROR      - The function successfully released memory.
    PRO_TK_BAD_INPUTS    - Bad input argument.
    
*/ 

extern ProError ProDtlattachGet(
    ProDtlattach attachment,
    ProDtlattachType *type,
    ProView    *view,
    ProVector   location,
    ProSelection   *attach_point);
/*

Purpose: Gets a detail attachment data.

Input Arguments:

    attachment      - The detail attachment.
    
Output Arguments:

    type            - The attachment type (FREE, PARAMETRIC, OFFSET
                      or UNIMPLEMENTED).
    view            - The view if type == PRO_DTLATTACHTYPE_FREE or type == 
                      PRO_DTLATTACHTYPE_UNIMPLEMENTED. Could be NULL.
    location        - The attachment location if 
                       type == PRO_DTLATTACHTYPE_FREE, 
		       PRO_DTLATTACHTYPE_OFFSET or 
		       PRO_DTLATTACHTYPE_UNIMPLEMENTED.  
		       For drawing objects and symbols and surface finish on
		       flat-to-screen annotation planes, this should be in
		       screen coordinates.  For symbols and surface finish on
		       3D model annotation planes, this should be in model 
		       coordinates.
    attach_point    - The attachment point 
                        if type == PRO_DTLATTACHTYPE_PARAMETRIC or 
			PRO_DTLATTACHTYPE_OFFSET.

Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved data.
    PRO_TK_BAD_INPUTS    - Bad one or more input arguments.
    PRO_TK_GENERAL_ERROR - Can't get data.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/ 

extern ProError ProDtlattachArrowtypeGet (ProDtlattach attach,
                                            ProLeaderType* arrow_type);
/*
    Purpose: Returns the type of arrowhead used for this particular detail item 
             attachment.  Valid only for ProDtlattach which were obtained from 
             ProDtlsyminstdataLeadersCollect and ProDtlnotedataLeadersCollect.  
             Other types of detail attachments would not have arrows.
             

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        attach - The leader attachment structure.

    Output Arguments:
        arrow_type - The type of arrowhead used for the attached leader.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - This attachment is not a leader and does not 
                             include an arrow.

*/

extern ProError ProDtlattachArrowtypeSet (ProDtlattach attach, 
                                          ProLeaderType arrow_type);

/*

    Purpose: Sets the type of arrowhead to be used for this particular detail 
             item attachment. Valid only for ProDtlattach which were obtained 
             from ProDtlsyminstdataLeadersCollect and 
             ProDtlnotedataLeadersCollect.
             Other types of detail attachments would not have arrows.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        attach - The leader attachment structure.
        arrow_type - The type of arrowhead to be used for the attached leader.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

PRO_END_C_DECLS

#endif  /* PRODTLATTACH_H */
