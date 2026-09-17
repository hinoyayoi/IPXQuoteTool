#ifndef PRO_DATUM_TARGET_H
#define PRO_DATUM_TARGET_H



#include <ProANSI.h>
#include <ProObjects.h>
#include <ProMdl.h>
#include <ProSelection.h>

PRO_BEGIN_C_DECLS

typedef ProSelection ProDatumTargetAttach[2];

typedef enum
{
  PRO_DATUM_TARGET_NONE,
  PRO_DATUM_TARGET_POINT,
  PRO_DATUM_TARGET_CIRCLE,
  PRO_DATUM_TARGET_RECTANGLE
}ProDatumTargetType;

extern ProError ProMdlDatumTargetCreate (ProMdl                 p_owner_mdl,
                                         ProDatumTargetType     type,
                                         ProAnnotationPlane    *annot_plane,
                                         ProDatumTargetAttach   attach_sels,
                                         Pro3dPnt               text_pnt,
                                         ProDtlsyminst         *p_datum_target);
/*
    Purpose:   Creates new datum target with specified attachment and value strings

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        p_owner_mdl  - Owner model of the datum target. Cannot be NULL.
        type         - type of datum target
        annot_plane  - The annotation plane.
                       For drawing, annotation plane should be NULL.
        attach_sels  - For single reference pass non-null selection for index 0 and NULL for index 1.
                       Pass pair of non-null selections to get intersection of both.
        text_pnt     - text point.

    Output Arguments:
        p_datum_target - newly created datum target.

    Return Values:
        PRO_TK_NO_ERROR      - The function completed successfully.
        PRO_TK_BAD_CONTEXT   - Specified selection reference is invalid.
        PRO_TK_BAD_INPUTS    - The input argument is invalid.
        PRO_TK_GENERAL_ERROR - datum target could not be created.
*/

PRO_END_C_DECLS

#endif /* PRO_DATUM_TARGET_H */
