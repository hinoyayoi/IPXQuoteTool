

#ifndef PROGTOL_H
#define PROGTOL_H

#include <ProSelection.h>
#include <ProAnnotationElem.h>

PRO_BEGIN_C_DECLS

typedef struct gtol_dialog_info   *ProGtoldata;
typedef struct progtol_datum_ref  *ProGtoldatumref;
typedef struct pro_gtol_attach    *ProGtolAttach;
typedef struct progtol_leader     *ProGtolleader;

typedef enum
{
   PROGTOLSTATUS_MODEL_REF_ENT   =  0,
   PROGTOLSTATUS_PLACEMENT       =  1,
   PROGTOLSTATUS_INVALID_REF_ENT =  2,
   PROGTOLSTATUS_REF_DTM_NEEDED  =  3,
   PROGTOLSTATUS_ONE_REF_DTM     =  4,
   PROGTOLSTATUS_NONCOLL_AXIS    =  5,
   PROGTOLSTATUS_NONCOLL_SURF    =  6,
   PROGTOLSTATUS_NONPERP_SURF    =  7,
   PROGTOLSTATUS_NONPERP_ENT     =  8,
   PROGTOLSTATUS_NONPAR_ENT      =  9,
   PROGTOLSTATUS_ENT_DTM_NOT_ANG = 10,
   PROGTOLSTATUS_NO_REF_ENT      = 11,
   PROGTOLSTATUS_COMPLETE        = 12,
   PROGTOLSTATUS_NO_REF_GEOM     = 13
} ProGtoldataStatus;

typedef enum
{
   PROGTOLTYPE_UNKNOWN          =  0,
   PROGTOLTYPE_STRAIGHTNESS     =  1,
   PROGTOLTYPE_FLATNESS         =  2,
   PROGTOLTYPE_CIRCULAR         =  3,
   PROGTOLTYPE_CYLINDRICAL      =  4,
   PROGTOLTYPE_LINE             = 11,
   PROGTOLTYPE_SURFACE          = 12,
   PROGTOLTYPE_ANGULAR          = 21,
   PROGTOLTYPE_PERPENDICULAR    = 22,
   PROGTOLTYPE_PARALLEL         = 23,
   PROGTOLTYPE_POSITION         = 31,
   PROGTOLTYPE_CONCENTRICITY    = 32,
   PROGTOLTYPE_SYMMETRY         = 35,
   PROGTOLTYPE_CIRCULAR_RUNOUT  = 41,
   PROGTOLTYPE_TOTAL_RUNOUT     = 42
} ProGtolType;

typedef enum
{
   PROGTOLMATCOND_UNKNOWN     = 0,
   PROGTOLMATCOND_LMC         = 1,
   PROGTOLMATCOND_MMC         = 2,
   PROGTOLMATCOND_RFS         = 3,
   PROGTOLMATCOND_DEFAULT_RFS = 4,
   PROGTOLMATCOND_LMC_R       = 5,
   PROGTOLMATCOND_MMC_R       = 6
} ProGtolMaterialCond;

typedef enum
{
   PROGTOLRTYPE_NONE   = -1, /* Only available in drawings */
   PROGTOLRTYPE_EDGE   = 1,
   PROGTOLRTYPE_AXIS   = 2,
   PROGTOLRTYPE_SURF   = 3,
   PROGTOLRTYPE_FEAT   = 4,
   PROGTOLRTYPE_DATUM  = 5,  /* Datum plane or axis */
   PROGTOLRTYPE_ENTITY = 6   /* NOT IMPLEMENTED */
} ProGtolRefItemType;

typedef enum
{
   PROGTOLPTYPE_DATUM,
   PROGTOLPTYPE_DIMENSION,
   PROGTOLPTYPE_DIM_RELATED,
   PROGTOLPTYPE_FREENOTE,
   PROGTOLPTYPE_LEADERS,
   PROGTOLPTYPE_TANLEADER,
   PROGTOLPTYPE_NORMLEADER,
   PROGTOLPTYPE_GTOL
} ProGtolPlacementType;


typedef enum
{
   PROLEADERTYPE_ARROWHEAD   =  1,
   PROLEADERTYPE_DOT         =  2,
   PROLEADERTYPE_FILLEDDOT   =  3,
   PROLEADERTYPE_NOARROW     =  4,
   PROLEADERTYPE_CROSS       =  5,
   PROLEADERTYPE_SLASH       =  6,
   PROLEADERTYPE_INTEGRAL    =  7,
   PROLEADERTYPE_BOX         =  8,
   PROLEADERTYPE_FILLEDBOX   =  9,
   PROLEADERTYPE_DOUBLEARROW = 10,
   PROLEADERTYPE_TARGET      = 14, 
   PROLEADERTYPE_LEFTHALF    = 15,
   PROLEADERTYPE_RIGHTHALF   = 16, 
   PROLEADERTYPE_TRIANGLE    = 18,
   PROLEADERTYPE_AUTOMATIC   = 19
} ProLeaderType;

typedef enum
{
   PROGTOLREFTYPE_NONE      = 0,
   PROGTOLREFTYPE_PRIMARY   = 1,
   PROGTOLREFTYPE_SECONDARY = 2,
   PROGTOLREFTYPE_TERTIARY  = 3
} ProGtolReferenceType;

typedef enum
{
   PROGTOLPROJZONE_NONE       = 0,
   PROGTOLPROJZONE_BELOWGTOL  = 1,
   PROGTOLPROJZONE_INSIDEGTOL = 2
} ProGtolProjzone;

/* PROGTOLPROF_BILATERAL_IDX = 0 and PROGTOLPROF_UNILATERAL_IDX = 1 in order
 * to handle legacy code. */
typedef enum
{
   PROGTOLPROF_BILATERAL_IDX = 0,
   PROGTOLPROF_UNILATERAL_IDX = 1,
   PROGTOLPROF_UNEQUAL_IDX = 2
} ProGtolProfBoundIndex;

typedef enum
{
  PRO_TEXT_HRZJUST_DEFAULT,
  PRO_TEXT_HRZJUST_LEFT,
  PRO_TEXT_HRZJUST_CENTER,
  PRO_TEXT_HRZJUST_RIGHT
} ProTextHrzJustification;

typedef enum
{
	PRO_GTOL_SYMBOL_DIAMETER,
	PRO_GTOL_SYMBOL_FREE_STATE,	
	PRO_GTOL_SYMBOL_STAT_TOL,
	PRO_GTOL_SYMBOL_TANGENT_PLANE,

	/* Material condition symbols */
	PRO_GTOL_SYMBOL_LMC,
	PRO_GTOL_SYMBOL_MMC,
	PRO_GTOL_SYMBOL_RFS,
	PRO_GTOL_SYMBOL_DEFAULT_RFS,
	PRO_GTOL_SYMBOL_LMC_R,
	PRO_GTOL_SYMBOL_MMC_R,

  /* Indicator Symbol */
	PRO_INDICATOR_SYMBOL_ANGULARITY,
	PRO_INDICATOR_SYMBOL_PERPENDICULARITY,
	PRO_INDICATOR_SYMBOL_PARALLELISM,
	PRO_INDICATOR_SYMBOL_SYMMETRY

	/* Add new C4 sumbols */
} ProGtolSymbol;

typedef enum
{
	PRO_INDICATOR_DIRECTION_FEAT,
	PRO_INDICATOR_COLLECTION_PLANE,	
	PRO_INDICATOR_INTERSECTION_PLANE,
	PRO_INDICATOR_ORIENTATION_PLANE

} ProGtolIndicatorType;

typedef enum
{
  PRO_GTOL_SYNTAX_VALIDITY_CHECK

} ProGtolValidityCheckType;

typedef enum
{
  PRO_FONT_ASME,
  PRO_FONT_ISO,
  PRO_FONT_LEGACY

}ProSymbolFont;


extern ProError ProGtoldataAlloc(
   ProMdl      owner,
   ProGtoldata *data);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Allocates a new ProGtoldata structure in workspace.

   Input Arguments:
      owner      - The model (part, assembly, or drawing) that  
                   defines the origin of ProSelection structures used
                   in setting up gtol references. This should be a
                   drawing if the references are acquired using
                   ProSelect() in a drawing; otherwise it should be
                   the same model as set with ProGtoldataModelSet().

   Output Arguments:
      data        - The pointer to the workspace ProGtoldata structure.  After
                    using, free this using ProGtoldataFree().

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR  - An error occurred and the function failed.
*/

extern ProError ProGtoldataFree(
   ProGtoldata *data);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Frees a workspace ProGtoldata structure.

   Input Arguments:
      data      - Pointer to the workspace structure.

   Output Arguments:

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.

*/

extern ProError ProGtoldataOwnerGet(
   ProGtoldata data,
   ProMdl      *owner);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolTopModelGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolTopModelGet() instead.

            Provides the model which defines the origin of
            ProSelection structures used to define references
            inside the gtol. This will either be the solid
            that contains the gtol (as shown by
            ProGtoldataModelGet()) or a drawing that contains
            a view of that solid and was current when the gtol
            was created.

   Input Arguments:
      data     - Pointer to the gtol data

   Output Arguments:
      owner    - The model (part, assembly or drawing). 

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtoldataTypeSet(
   ProGtoldata data,
   ProGtolType type,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolTypeSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolTypeSet() instead.

            Sets the gtol type in a gtol data structure.

   Input Arguments:
      data     - Pointer to the gtol data
      type     - The gtol type

   Output Arguments:
      status   - Reports the resulting status of the gtol.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataTypeGet(
   ProGtoldata data,
   ProGtolType *type);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolTypeGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolTypeGet() instead.

            Gets the gtol type in a gtol data structure.

   Input Arguments:
      data     - Pointer to the gtol data

   Output Arguments:
      type     - The gtol type

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCreate(
   ProGtoldata data,
   ProGtol     *gtol);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProMdlGtolCreate

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProMdlGtolCreate() instead.
   
            Creates a gtol by using the description in a gtol data
            structure. ProAnnotationShow() should be called after 
            creating the gtol in order for the gtol to be displayed.

   Input Arguments:
      data     - Pointer to the gtol data

   Output Arguments:
      gtol     - The new gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolDataGet(
   ProGtol *gtol,
   ProGtoldata *data);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Gets a gtol data description for a specified gtol in a
	    Creo Parametric model. The gtol data structure is workspace copy 
	    of the gtol data in the Creo Parametric model; modifying it
	    does not change the gtol in Creo Parametric; use
	    ProGtoldataFree() to free the data after use.

   Input Arguments:
      gtol     - The gtol

   Output Arguments:
      data     - Pointer to the gtol data

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_E_NOT_FOUND
*/

extern ProError ProGtolValueSet(
   ProGtol *gtol,
   double  overall_value);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringSet() instead.
   
            Sets the overall value of the gtol.  

            <P>NOTE: This is the only way to modify the value of a 
	    gtol that is varied in an inheritance feature.
   

   Input Arguments:
      gtol     - The gtol
      overall_value   - The gtol overall value.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more input arguments is invalid.
      PRO_TK_BAD_CONTEXT    - The gtol value cannot be varied.
      PRO_TK_GENERAL_ERROR  - The gtol value cannot be modified.
*/

extern ProError ProGtolEditInit(
   ProGtol *gtol,
   ProGtoldata *data);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Gets a pointer to the gtol data description of a gtol in
            a Creo Parametric model. Use ProGtoldataFree() to free this data.
         
            <P><B>NOTE:</B>  Modifications to this data structure have an
                   immediate effect in the Creo Parametric model. 

   Input Arguments:
      gtol     - The gtol

   Output Arguments:
      data     - The pointer to the Creo Parametric ProGtoldata structure

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_CANT_WRITE     - Could not modify the given item because
                              it has read-only access.
      PRO_TK_E_NOT_FOUND
*/

extern ProError ProGtolEditCommit(
   ProGtol *gtol,
   ProGtoldata data);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Commits changes made to a gtol through the use of
            ProGtolEditInit() and ProGtol*Set() functions. 

   Input Arguments:
      gtol     - The gtol
      data     - The pointer to the Creo Parametric ProGtoldata structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
      PRO_TK_CANT_WRITE     - Could not modify the given item because
                              it has read-only access.
*/

extern ProError ProGtolEditCancel(
   ProGtol *gtol,
   ProGtoldata data);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Undoes changes made to a gtol through the use of
            ProGtolEditInit() and ProGtol*Set() functions. 

   Input Arguments:
      gtol     - The gtol
      data     - The pointer to the Creo Parametric ProGtoldata structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolDelete(
   ProGtol *gtol);

/*
   Purpose:   Deletes a gtol from its owning Creo Parametric model.

   Input Arguments:
      gtol     - The gtol

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_CANT_WRITE     - Could not delete the given item because
                              it has read-only access.
      PRO_TK_E_NOT_FOUND
*/

extern ProError ProGtolRightTextGet (ProGtol *gtol, wchar_t **p_text);

/*
Purpose: Retrieves the text of the specified geometrical tolerance.

Input Arguments:
  gtol - Pointer to the geometrical tolerance.

Output Arguments:
  p_text   - The string added to the right of the geometric tolerance.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the information.
  PRO_TK_BAD_INPUTS  - The input argument is invalid.
  PRO_TK_E_NOT_FOUND - There is no additional text for this geometric tolerance.
*/

extern ProError ProGtolRightTextSet (ProGtol *gtol, wchar_t *text);

/*
Purpose: Sets the text of the specified geometric tolerance.

Input Arguments:
  gtol - Pointer to the geometrical tolerance.
  text - The string added to the right of the geometric tolerance.

Output Arguments:
  None

Return Values:
  PRO_TK_NO_ERROR   - The function successfully retrieved the information.
  PRO_TK_BAD_INPUTS - One or more input argument is invalid.
  PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
  PRO_TK_CANT_WRITE - Could not modify the given item because
                      it has read-only access.
*/

extern ProError ProGtolDtlnoteGet (ProGtol    *solid_model_gtol,
                                   ProDrawing  drawing,
                                   ProDtlnote *dtl_note);
/*
Purpose: Return the detail note that represents a shown geometric tolerance.

Input Arguments:
  solid_model_gtol - The geometric tolerance handle.
  drawing          - The drawing where the note is displayed.

Output Arguments:
  dtl_note    - The drawing detail note that displays the model note.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_BAD_CONTEXT - The solid model is not contained in the drawing.
  PRO_TK_E_NOT_FOUND - The geometric tolerance is not displayed in the drawing
                       as a note.
*/



extern ProError ProGtoldataModelSet(
   ProGtoldata data,
   ProMdl model,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolOwnerSet() instead.

            Sets the model that will contain the gtol.

            <P><B>NOTE:</B> This function may not be used to modify an 
	        existing gtol by calling it with gtol data acquired by
                calling ProGtolEditInit().

   Input Arguments:
      data        - The pointer to the gtol data structure
      model       - Model that contains gtol.

   Output Arguments:
      status      - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The model may not be modified in this context.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataModelGet(
   ProGtoldata data,
   ProMdl *model);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolOwnerGet() instead.

            Gets the model that contains the gtol.

   Input Arguments:
      data        - The pointer to the gtol data structure

   Output Arguments:
      model       - The model that contains the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtoldataReferenceSet(
   ProGtoldata data,
   ProGtolRefItemType type,
   ProSelection     reference,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolReferencesSet() instead.

            Sets the item to which the gtol refers.

   Input Arguments:
      data      - The gtol data description
      type      - The type of item being referenced
      reference - The item being referenced. Ignore if type is
                  PROGTOLRTYPE_NONE

   Output Arguments:
      status    - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The reference may not be modified in this context.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataReferenceGet(
   ProGtoldata data,
   ProGtolRefItemType *type,
   ProSelection     *reference);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolReferencesGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolReferencesGet() instead.<br>
			Using this function on Creo 4.0 or newer gtol may not return all references.

            Gets the item to which the gtol refers.

   Input Arguments:
      data      - The gtol data description

   Output Arguments:
      type      - The type of item being referenced
      reference - The item being referenced

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
	  PRO_TK_E_NOT_FOUND    - GTol does not have reference.
*/

extern ProError ProGtoldataPlacementSet(
   ProGtoldata data,
   ProGtolPlacementType type,
   ProDimension *dimension,
   ProGtolleader *leaders,
   ProPoint3d location,
   ProGtol *gtol,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAttachSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolAttachSet() instead.

            Sets the placement of a gtol. Not applicable
            if the gtol reference type is PROGTOLRTYPE_DATUM.

   Input Arguments:
      data      - The gtol data description
      type      - The placement type
      dimension - The dimension to attach to, if type ==
               	  PROGTOLPTYPE_DIMENSION or PROGTOLPTYPE_DIM_RELATED
      leaders   - ProArray of leader structures. Contains only a single
               	  leader if the type is PROGTOLPTYPE_TANLEADER or
                  PROGTOLPTYPE_NORMLEADER
      location  - Location of the gtol label
                  If the type is PROGTOLPTYPE_*LEADER*,
                  PROGTOLPTYPE_DIM_RELATED, or
                  PROGTOLPTYPE_FREENOTE.  Location is in model coordinates.
      gtol      - The gtol to attach to, if type == PROGTOLPTYPE_GTOL
      
   Output Arguments:
      status    - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The placement may not be modified in this context.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataPlacementGet(
   ProGtoldata data,
   ProGtolPlacementType *type,
   ProDimension *dimension,
   ProGtolleader **leaders,
   ProPoint3d location,
   ProGtol *gtol);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAttachGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolAttachGet() instead.			
            
			Gets the placement of a gtol.

   Input Arguments:
      data      - The gtol data description

   Output Arguments:
      type      - The placement type
      dimension - The dimension the gtol is attached to,
                  if type==PROGTOLPTYPE_DIMENSION, or
                  PROGTOLPTYPE_DIM_RELATED
      leaders   - ProArray of leader structures, if type == 
	              PROGTOLPTYPE_LEADERS, PROGTOLPTYPE_TANLEADER or
                  PROGTOLPTYPE_NORMLEADER.
      location  - Location of the gtol label, if the placement type
               	  requires a location.  Location is in model coordinates.
      gtol      - The gtol the gtol is attached to, if type==PROGTOLPTYPE_GTOL.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
	  PRO_TK_NOT_IMPLEMENTED - The function does not support types of attachments introduced in Creo 4.0.
*/

extern ProError ProGtoldataGtoldatumrefSet(
   ProGtoldata  data,
   ProGtoldatumref  primary,
   ProGtoldatumref  secondary,
   ProGtoldatumref  tertiary,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolDatumReferencesSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolDatumReferencesSet() instead.

            Sets the datum references for a gtol.

   Input Arguments:
      data      - The gtol data description. 
      primary   - The primary datum reference. May be NULL.
      secondary - The secondary datum reference. May be NULL.
      tertiary  - The tertiary datum reference. May be NULL.

   Output Arguments:
      status    - The resulting gtol status

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The datum references may not be modified for this
                             gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataGtoldatumrefGet(
   ProGtoldata  data,
   ProGtoldatumref  *primary,
   ProGtoldatumref  *secondary,
   ProGtoldatumref  *tertiary);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolDatumReferencesGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolDatumReferencesGet() instead.<br>
			This function may not work for Creo 4.0 or newer gtols.

            Gets the datum references for a gtol.

   Input Arguments:
      data      - The gtol data description

   Output Arguments:
      primary   - The primary datum reference. May be NULL.
      secondary - The secondary datum reference. May be NULL.
      tertiary  - The tertiary datum reference. May be NULL.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtoldataCompositeSet(
   ProGtoldata data,
   ProBoolean is_composite,
   double value,
   ProGtolReferenceType type,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolCompositeSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolCompositeSet() instead.
   
            Sets the composite information for a gtol.
            Valid only for a gtol of type 
            PROGTOLTYPE_SURFACE or PROGTOLTYPE_POSITION.

   Input Arguments:
      data         - The gtol data description
      is_composite - Whether the gtol should be composite
      value        - The composite value
      type         - The reference type

   Output Arguments:
      status       - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY  - The composite flag is not valid for this gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataCompositeGet(
   ProGtoldata data,
   ProBoolean *is_composite,
   double *value,
   ProGtolReferenceType *type);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolCompositeGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolCompositeGet() instead.
   
            Gets the composite information for a gtol.
            Valid only for a gtol whose type is
            PROGTOLTYPE_SURFACE or PROGTOLTYPE_POSITION.

   Input Arguments:
      data         - The gtol data description

   Output Arguments:
      is_composite - Whether the gtol is composite
      value        - The composite value
      type         - The reference type

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataValueSet(
   ProGtoldata data,
   ProBoolean  overall_tolerance,
   double      overall_value,
   ProName     name,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringSet() instead.

            Sets the value of a gtol.

   Input Arguments:
      data              - The gtol data description
      overall_tolerance - Whether the value is the overall tolerance
      overall_value     - The overall tolerance value
      name              - The tolerance value name

   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY - The value may not be modified for this gtol data.
      PRO_TK_NOT_VALID - Values are not valid for this type of gtol.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataValueGet(
   ProGtoldata data,
   ProBoolean  *overall_tolerance,
   double      *overall_value,
   ProName     name);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet() instead.

            Gets the value of a gtol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      overall_tolerance - Whether the value is the overall tolerance
      overall_value     - The overall tolerance value
      name              - The tolerance value name

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataPerUnitSet(
   ProGtoldata data,
   ProBoolean  perunit_tolerance,
   double      value_per_unit,
   double      unit_area_or_length,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolCompositeShareRefSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolCompositeShareRefSet() instead.

            Sets the per unit tolerance of a gtol.

   Input Arguments:
      data              - The gtol data description
      perunit_tolerance - Whether the gtol has a per unit tolerance
      value_per_unit    - The value per unit, if perunit_tolerance=TRUE
      unit_area_or_length - The unit area, or length (depending upon
                            the tolerance type).
   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY - The per unit value may not be modified for this 
                           gtol data.
      PRO_TK_NOT_VALID - Values are not valid for this type of gtol.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataPerUnitGet(
   ProGtoldata data,
   ProBoolean  *perunit_tolerance,
   double      *value_per_unit,
   double      *unit_area_or_length);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolCompositeShareRefGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolCompositeShareRefGet() instead.

            Gets the per unit tolerance of a gtol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      perunit_tolerance - Whether the gtol has a per unit tolerance
      value_per_unit    - The value per unit, if perunit_tolerance=TRUE
                          unit_area_or_length
      unit_area_or_length - The unit area, or length (depending upon
                            the tolerance type).

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataMatCondSet(
   ProGtoldata data,
   ProGtolMaterialCond matcond,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolSymbolStringGet, ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolSymbolStringGet(), ProGtolValueStringSet() instead.

            Sets the material condition of a gtol.

   Input Arguments:
      data              - The gtol data description
      matcond           - The material condition

   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY - The material condition may not be modified for this 
                           gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataMatCondGet(
   ProGtoldata data,
   ProGtolMaterialCond *matcond);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet, ProGtolSymbolStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet(), ProGtolSymbolStringGet() instead.

            Gets the material condition of a gtol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      matcond           - The material condition

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataStatTolSet(
   ProGtoldata data,
   ProBoolean statistic_tolerance,
   ProGtoldataStatus    *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolSymbolStringGet, ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolSymbolStringGet(), ProGtolValueStringSet() instead.

            Sets whether a gtol shows or does not show the 
            statistical tolerance symbol.

   Input Arguments:
      data                -  The gtol data description
      statistic_tolerance -  Whether the gtol is a statistical tolerance

   Output Arguments:
      status              - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY - The statistical tolerance symbol may not be modified
                           for this gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataStatTolGet(
   ProGtoldata data,
   ProBoolean *statistic_tolerance);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet, ProGtolSymbolStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet(), ProGtolSymbolStringGet() instead.

            Reports whether a gtol shows or does not show the 
            statistical tolerace symbol.

   Input Arguments:
      data                - The gtol data description

   Output Arguments:
      statistic_tolerance - Whether the gtol is a statistical tolerance

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataDiameterSet(
   ProGtoldata data,
   ProBoolean diameter,
   ProGtoldataStatus    *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolSymbolStringGet, ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolSymbolStringGet(), ProGtolValueStringSet() instead.

            Sets whether a gtol shows or does not show the 
            diameter tolerance symbol.

   Input Arguments:
      data              - The gtol data description
      diameter          - Whether the gtol shows the diameter symbol

   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY  - The diameter symbol may not be modified for this
                            gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataDiameterGet(
   ProGtoldata data,
   ProBoolean *diameter);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet, ProGtolSymbolStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet(), ProGtolSymbolStringGet() instead.

            Reports whether a gtol shows or does not show 
            the diameter tolerance  symbol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      diameter          - Whether the gtol shows the diameter symbol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataFreeStateSet(
   ProGtoldata data,
   ProBoolean free_state,
   ProGtoldataStatus    *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolSymbolStringGet, ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolSymbolStringGet(), ProGtolValueStringSet() instead.

            Sets whether a gtol shows or does not show the free state symbol.

   Input Arguments:
      data              - The gtol data description
      free_state        - Whether the gtol is a free state

   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The free state symbol may not be modified for
                             this gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataFreeStateGet(
   ProGtoldata data,
   ProBoolean *free_state);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet, ProGtolSymbolStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet(), ProGtolSymbolStringGet() instead.

            Reports whether a gtol shows or does not show
            the free state symbol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      free_state        - Whether the gtol is a free state

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataAllAroundSet(
   ProGtoldata data,
   ProBoolean all_around,
   ProGtoldataStatus    *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAllAroundSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolAllAroundSet() instead.
   
            Sets whether a gtol shows or does not show the all around 
            symbol.

   Input Arguments:
      data              - The gtol data description
      all_around        - Whether the gtol is all around

   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The all around symbol may not be modified for this
                             gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataAllAroundGet(
   ProGtoldata data,
   ProBoolean *all_around);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAllAroundGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolAllAroundGet() instead.
   
            Reports whether a gtol shows or does not show the all around
            symbol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      all_around        - Whether the gtol is all around

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataTangentPlaneSet(
   ProGtoldata data,
   ProBoolean tangent_plane,
   ProGtoldataStatus    *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolSymbolStringGet, ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolSymbolStringGet(), ProGtolValueStringSet() instead.

            Sets whether a gtol shows or does not show the tangent plane
            symbol.

   Input Arguments:
      data              - The gtol data description
      tangent_plane     - Whether the gtol is tangent plane

   Output Arguments:
      status            - The resulting status of the gtol

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The tangent plane symbol may not be modified for
                             this gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataTangentPlaneGet(
   ProGtoldata data,
   ProBoolean *tangent_plane);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet, ProGtolSymbolStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet(), ProGtolSymbolStringGet() instead.

            Reports whether a gtol shows or does not show the tangent plane
            symbol.

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      tangent_plane        - Whether the gtol is tangent plane

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataProjZoneSet(
   ProGtoldata data,
   ProGtolProjzone projected_zone,
   ProBoolean specify_height,
   double zone_height,
   ProGtoldataStatus    *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringSet() instead.

            Sets the projected tolerance zone for a gtol. This function is
            valid for gtols with the following types:
            <UL>
                <LI>PROGTOLTYPE_ANGULAR
               	<LI>PROGTOLTYPE_PERPENDICULAR
                <LI>PROGTOLTYPE_PARALLEL
               	<LI>PROGTOLTYPE_POSITION
            </UL>

   Input Arguments:
      data              - The gtol data description
      projected_zone    - The type of projected zone, if any
      specify_height    - Whether the height of the zone is specified
      zone_height       - The zone height, if specify_height == PRO_B_TRUE

   Output Arguments:
      status            - The resulting gtol status

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataProjZoneGet(
   ProGtoldata data,
   ProGtolProjzone *projected_zone,
   ProBoolean *specify_height,
   double *zone_height);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet() instead.

            Gets the projected tolerance zone for a gtol. This function is
            valid for gtols with the following types:
            <UL>
                <LI>PROGTOLTYPE_ANGULAR
                <LI>PROGTOLTYPE_PERPENDICULAR
                <LI>PROGTOLTYPE_PARALLEL
                <LI>PROGTOLTYPE_POSITION
            </UL>

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      projected_zone    - The type of projected zone, if any
      specify_height    - Whether the height of the zone is specified
      zone_height       - The zone height, if specify_height == PRO_B_TRUE

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataProfBoundarySet(
   ProGtoldata data,
   ProGtolProfBoundIndex profile_idx,
   ProBoolean outside,
   ProGtoldataStatus *status);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolBoundaryDisplaySet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolBoundaryDisplaySet() instead.

            Sets the profile boundary for a gtol. This function is
            valid for gtols with the following types:
            <UL>
              <LI>PROGTOLTYPE_LINE
              <LI>PROGTOLTYPE_SURFACE
            </UL>

   Input Arguments:
      data              - The gtol data description
      profile_idx       - Index of the profile boundary (unilateral, bilateral,
                                                        unequal)
      outside           - Whether the tolerance refers to the outside of
                          the profile, if profile_idx == unilateral

   Output Arguments:
      status            - The resulting gtol status

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataProfBoundaryGet(
   ProGtoldata data,
   ProGtolProfBoundIndex *profile_idx,
   ProBoolean *outside);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolBoundaryDisplayGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolBoundaryDisplayGet() instead.

            Returns the profile boundary for a gtol. This function is
            valid for gtols with the following types:
            <UL>
               <LI>PROGTOLTYPE_LINE
               <LI>PROGTOLTYPE_SURFACE
            </UL>

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      profile_idx       - Index of the profile boundary (unilateral, bilateral,
                                                         unequal)
      outside           - Whether the tolerance refers to the outside of
                                the profile, if profile_idx == unilateral

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldatumrefAlloc(
   ProSelection        basic_datum,
   ProGtolMaterialCond basic_matcond,
   ProSelection        compound_datum,
   ProGtolMaterialCond compound_matcond,
   ProGtoldatumref     *datumref);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolDatumReferencesSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolDatumReferencesSet() instead

            Allocates and defines a datum reference structure.

   Input Arguments:
      basic_datum      - The basic datum (plane or axis) being referenced
                         Can be NULL.
      basic_matcond    - The basic material condition
      compound_datum   - The compound datum (plane or axis) being referenced
                         Can be NULL.
      compound_matcond - The compound material condition

   Output Arguments:
      datumref         - The allocated datum reference structure

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
*/

extern ProError ProGtoldatumrefFree(
   ProGtoldatumref     *datumref);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose:    <b>Note:</b> This function is deprecated.
               Frees a datum reference structure.

   Input Arguments:
      datumref    - Pointer to the datum reference structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
*/

extern ProError ProGtoldatumrefGet(
   ProGtoldatumref     datumref,
   ProSelection        *basic_datum,
   ProGtolMaterialCond *basic_matcond,
   ProSelection        *compound_datum,
   ProGtolMaterialCond *compound_matcond);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolDatumReferencesGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolDatumReferencesGet() instead

            Returns the information contained in a datum reference structure.

   Input Arguments:
      datumref         - The datum reference structure
      
   Output Arguments:
      basic_datum      - The basic datum (plane or axis) being referenced
                         Can be NULL.
      basic_matcond    - The basic material condition
      compound_datum   - The compound datum (plane or axis) being referenced
                         Can be NULL.
      compound_matcond - The compound material condition

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolleaderAlloc(
   ProLeaderType type,
   ProSelection attachment,
   ProGtolleader *leader);

/*
   Purpose:    Allocates and defines a gtol leader structure.

   Input Arguments:
      type        - The type which determinates the leader appearance
      attachment  - The item to which the leader is attached

   Output Arguments:
      leader      - The allocated gtol leader structure

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
*/

extern ProError ProGtolleaderFree(
   ProGtolleader *leader);

/*
   Purpose:    Frees a gtol leader structure.

   Input Arguments:
      leader      - Pointer to the leader structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolleadersFree(
   ProGtolleader **leaders);

/*
   Purpose:    Frees an array of gtol leader structures.

   Input Arguments:
      leaders     - Pointer to the leader structure array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolleaderGet(
   ProGtolleader leader,
   ProLeaderType *type,
   ProSelection *attachment);

/*
   Purpose:    Provides the information contained in a gtol leader structure.

   Input Arguments:
      leader      - The leader structure

   Output Arguments:
      type        - The type which determinates the leader appearance
      attachment  - The item to which the leader is attached

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGeomitemGtolrefSet(
   ProGeomitem  *geomitem,
   ProDimension *in_dim);

/*
   DEPRECATED: Wildfire 5.0
   SUCCESSORS: ProGeomitemSetdatumSet
   Purpose:    <B><P>Note: This function is deprecated.  Use 
               ProGeomitemSetdatumSet() instead. </P></B>
    
               Sets a datum plane or axis to be a gtol reference.

   Input Arguments:
      geomitem    - The datum plane or axis
      in_dim      - Identifies the dimension for an "In dim" tolerance;
                    set to NULL if the gtol is "Free".

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGeomitemGtolrefClear(
   ProGeomitem *geomitem);

/*
   DEPRECATED: Wildfire 5.0
   SUCCESSORS: ProGeomitemSetdatumClear
   Purpose:    <B><P>Note: This function is deprecated.  Use 
              ProGeomitemSetdatumClear() instead. </P></B>
    
   Clears a datum plane or axis so it is no longer a gtol reference.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_CANT_WRITE     - Could not delete the given item because
                              it has read-only access.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGeomitemIsGtolref(
   ProGeomitem *geomitem,
   ProBoolean  *ref_datum,
   ProBoolean  *is_in_dim,
   ProDimension *in_dim);

/*
   DEPRECATED: Wildfire 5.0
   SUCCESSORS: ProGeomitemSetdatumGet
   Purpose:    <B><P>Note: This function is deprecated.  Use 
              ProGeomitemSetdatumGet() instead. </P></B>
    
   Shows whether a datum plane or axis is a gtol reference.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      ref_datum  - TRUE is the datum is a gtol reference
      is_in_dim  - TRUE if the datum is "In dim", FALSE if "Free"
      in_dim     - If is_in_dim==TRUE, the dimension

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataPlaneSet (ProGtoldata data,
                                     ProAnnotationPlane *plane);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAttachSet

        Purpose: <b>Note:</b> This function is deprecated.
                 Use ProGtolAttachSet() instead.

                 Sets the annotation plane for the gtol.
	          <B>NOTE:</B> If creating  a new gtol, this function must
		        be called after the placement has been assigned using 
			ProGtoldataPlacementSet, but before the call to
			ProGtolCreate.

        Input Arguments:
                data - The data.
                plane - The annotation plane.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProGtoldataPlaneGet (ProGtoldata data,
                                     ProAnnotationPlane* plane);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAttachGet

        Purpose: <b>Note:</b> This function is deprecated.
                 Use ProGtolAttachGet() instead.

                 Gets the annotation plane for the gtol.

        Input Arguments:
                data - The data.

        Output Arguments:
                plane - The annotation plane.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more arguments was invalid.
                PRO_TK_GENERAL_ERROR - The gtol's annotation plane cannot be obtained.
*/

typedef enum
{
   PROGTOLUNITAREASTYLE_X    = 0, /* /7X7 */
   PROGTOLUNITAREASTYLE_BOX  = 1, /* /[box]7 */
   PROGTOLUNITAREASTYLE_DIA  = 2  /* /[diameter]7 */
} ProGtolUnitareaStyle;

typedef enum 
{
   PRO_GTOLREF_IN_DIM,
   PRO_GTOLREF_IN_GTOL,
   PRO_GTOLREF_IN_GEOM,
   PRO_GTOLREF_FREE
} ProGtolsetdatumRefType;

typedef struct
{
   ProGtolsetdatumRefType type;
   union 
   {
     ProDimension dim;
     ProGtol gtol;
     ProSelection geom;
   } ref;
}ProGtolsetdatumValue;

extern ProError ProGtoldataUnitareaStyleGet(
   ProGtoldata p_data,
   ProGtolUnitareaStyle *p_style);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet() instead.

            Gets the unit area style for a gtol.

   Input Arguments:
      p_data - The gtol data description

   Output Arguments:
      p_style - The gtol unit area style

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR  - Unit area style is not set.
*/

extern ProError ProGtoldataUnitareaStyleSet(
   ProGtoldata p_data,
   ProGtolUnitareaStyle new_style);

/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringSet() instead.

            Sets the unit area style for a gtol.

   Input Arguments:
      p_data - The gtol data description
      new_style - The gtol unit area style

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
*/

extern ProError ProGeomitemSetdatumSet(
   ProGeomitem  *geomitem,
   ProGtolsetdatumValue* value);

/*
   Purpose:    Sets a datum plane or axis to be a Set Datum.  
               This function supersedes ProGeomitemGtolrefSet.

   Input Arguments:
      geomitem    - The datum plane or axis
      value  - The type and reference object for the "Set Datum" to apply.  
               Pass NULL to make it a "Free" Set Datum.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_WRITE     - Could not modify the given item because
                              it has read-only access.
*/
extern ProError ProGeomitemSetdatumClear(
   ProGeomitem *geomitem);

/*
   Purpose:    Removes the Set Datum status of a datum plane or axis.  
               This function supersedes ProGeomitemGtolrefClear.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      	none

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGeomitemSetdatumGet(
   ProGeomitem *geomitem,
   ProBoolean  *set,
   ProGtolsetdatumValue* value);

/*
   Purpose:    Shows whether a datum plane or axis is a Set Datum.  
               This function supersedes ProGeomitemIsGtolref.

   Input Arguments:
      geomitem   - The datum plane or axis

   Output Arguments:
      set - TRUE is the datum is a Set Datum.
      value  - The type and reference object for the "Set Datum" to apply.  
               If type of ProGtolsetdatumValue is PRO_GTOLREF_IN_GEOM, 
               the caller should free the memory for value.ref.geom 
               by using ProSelectionFree(). 
      
   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolTextstyleSet (ProGtol* gtol,
                                     ProTextStyle text_style);
/*
	DEPRECATED: Creo 1
    SUCCESSORS: ProAnnotationTextstyleSet
    Purpose: <P><B>Note:</B> This function is deprecated. Use 
              ProAnnotationTextstyleSet() instead.</P> 
	      Assigns the text style assigned to a geometric tolerance.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The gtol.
        text_style - The text style. Free this using ProTextStyleFree().

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text style cannot be varied.
        PRO_TK_CANT_WRITE - Could not modify the given item because
                            it has read-only access.
*/

extern ProError ProGtolTextstyleGet (ProGtol* gtol,
                                     ProTextStyle* text_style);
/*
	DEPRECATED: Creo 1
    SUCCESSORS: ProAnnotationTextstyleGet
    Purpose: <P><B>Note:</B> This function is deprecated. Use 
              ProAnnotationTextstyleGet() instead.</P> 
	      Obtains the text style assigned to a geometric tolerance.

    Licensing Requirement:
          TOOLKIT for 3D Drawings
    
    Input Arguments:
        gtol - The gtol.
    
    Output Arguments:
        text_style - The text style.  Free this using ProTextStyleFree().
    
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProGtolElbowlengthGet (ProGtol* gtol,
                                       double* elbow_length,
                                       ProVector elbow_direction);
/*
    Purpose: Obtains the elbow properties of the geometric tolerance.
<p><b>Note:</b>
    This function only supports gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The gtol.

    Output Arguments:
        elbow_length - The elbow length, in model units.
        elbow_direction - The elbow direction, in the model's coordinate
                          system.  This is the
                          direction from the gtol text to the gtol leaders.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not use leaders.
        PRO_TK_INVALID_TYPE - This gtol was created in a release before 
                              Wildfire 2.0. Because of this, its internal 
                              structure is different and the elbow length 
                              cannot be obtained by this function.
*/

extern ProError ProGtolLineEnvelopeGet (ProGtol* note,
                                        int line_number,
                                        ProLineEnvelope envelope);
/*
    Purpose: Get the envelope of a line in a specified geometric tolerance.
<p><b>Note:</b>
    This function only supports gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The gtol.
        line_number - The line number of the gtol.

    Output Arguments:
        envelope - The envelope surrounding the text line, in the model's
                   coordinate system.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The indicated line does not exist.
*/

extern ProError ProGtoldataASMEY1441Set(
   ProGtoldata data,
   ProBoolean  asme_y1441,
   ProGtoldataStatus *status);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Sets ASME Y14.41 for a profile gtol.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
      data              - The gtol data description
      asme_y1441        - Set ASME Y14.41 standard.
   Output Arguments:
      status            - The resulting status of the gtol
                          If not interested in status pass NULL.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The ASME Y14.41 standard may not be modified for
                             this gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataASMEY1441Get(
   ProGtoldata data,
   ProBoolean  *asme_y1441);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

   Purpose: <b>Note:</b> This function is deprecated.
            Check if ASME Y14.41 is checked for a profile gtol.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      asme_y1441        - True when ASME Y14.41 is checked. 

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataDispositionValSet(
   ProGtoldata data,
   double      unequal_disposition_val,
   ProGtoldataStatus *status);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringSet() instead.
   
           Sets the amount of unequal disposition for a profile gtol.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
      data              - The gtol data description
      unequal_disposition_val - Amount of unequal disposition.
   Output Arguments:
      status            - The resulting status of the gtol
                          If not interested in status pass NULL.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The disposition value may not be modified for this
                             gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldataDispositionValGet(
   ProGtoldata data,
   double      *unequal_disposition_val);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolValueStringGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolValueStringGet() instead.
   
            Gets the unequal disposition amount for profile gtols.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      unequal_disposition_val - Amount of unequal disposition.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

typedef enum
{
   PRO_GTOLVALTYPE_VALUE               = 1,  /* ProGtoldataValueSet */
   PRO_GTOLVALTYPE_COMPOSITE           = 2,  /* ProGtoldataCompositeSet */
   PRO_GTOLVALTYPE_ZONE_HEIGHT         = 3,  /* ProGtoldataProjZoneSet */
   PRO_GTOLVALTYPE_PERUNIT             = 4,  /* ProGtoldataPerUnitSet */
   PRO_GTOLVALTYPE_UNIT_AREA_OR_LENGTH = 5,  /* ProGtoldataPerUnitSet */
   PRO_GTOLVALTYPE_DISPOSITION         = 6   /* ProGtoldataDispositionValSet */
} ProGtolValueType;

extern ProError ProGtoldataNumdigitsGet (ProGtoldata data,
                                         ProGtolValueType type,
                                         int* num_digits);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

     Purpose: <b>Note:</b> This function is deprecated.
              Returns the number of significant digits assigned to the
              indicated gtol value.

     Input Arguments:
          data - The gtol data handle.
          type - The type of value.

     Output Arguments:
          num_digits - The number of digits assigned to this value.

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
          PRO_TK_E_NOT_FOUND - The requested value is not set in the gtol data.
          PRO_TK_GENERAL_ERROR - The retrieval operation failed.
*/

extern ProError ProGtoldataNumdigitsSet (ProGtoldata data,
                                         ProGtolValueType type,
                                         int num_digits);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: NONE

     Purpose: <b>Note:</b> This function is deprecated.
              Sets the number of significant digits assigned to the indicated
              gtol value.

     Input Arguments:
          data - The gtol data handle.
          type - The type of value.
          num_digits - The number of digits assigned to this value.

     Output Arguments:
          none

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
          PRO_TK_BAD_CONTEXT - Number of digits was smaller than the minimum
            required for the current stored value of this type.
          PRO_TK_CANT_MODIFY - Cannot modify the contents of this data
            structure.
          PRO_TK_E_NOT_FOUND - The requested value is not set in the gtol data.
          PRO_TK_GENERAL_ERROR - The operation failed.
*/

typedef enum 
{
PRO_GTOLTEXT_ON_RIGHT,
PRO_GTOLTEXT_ON_TOP,
PRO_GTOLTEXT_ON_BOTTOM,
PRO_GTOLTEXT_ON_LEFT
} ProGtolTextType;

extern ProError ProGtolTopTextGet (ProGtol* gtol, wchar_t** above_text);
/*
    Purpose: Obtains the text added to the top of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        above_text - The text added to the top of the geometric tolerance.  If 
                   the text extends over multiple lines, the output string will 
                   contain '\n' characters indicating the line breaks.  Free 
                   this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have text on top.

*/

extern ProError ProGtolTopTextSet (ProGtol* gtol, wchar_t* above_text);
/*
    Purpose: Assigns the text added to the top of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        above_text - The text added to the top of the geometric tolerance.  If 
                   the text should extend over multiple lines, the input string 
                   should contain '\n' characters indicating the line breaks.  
                   Note that the top text cannot extend beyond the length of 
                   the gtol control frame, and so the function may 
                   automatically insert line breaks into the text when doing 
                   this assignment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the top text because the gtol has 
                            read-only access.

*/

extern ProError ProGtolBottomTextGet (ProGtol* gtol, wchar_t** below_text);
/*
    Purpose: Obtains the text added to the bottom of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        below_text - The text added to the bottom of the geometric tolerance. If 
                   the text extends over multiple lines, the output string will 
                   contain '\n' characters indicating the line breaks.  Free 
                   this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have text on bottom.

*/

extern ProError ProGtolBottomTextSet (ProGtol* gtol, wchar_t* below_text);
/*
    Purpose: Assigns the text added to the bottom of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        below_text - The text added to the bottom of the geometric tolerance. If 
                   the text should extend over multiple lines, the input string 
                   should contain '\n' characters indicating the line breaks.  
                   Note that the bottom text cannot extend beyond the length of 
                   the gtol control frame, and so the function may 
                   automatically insert line breaks into the text when doing 
                   this assignment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the bottom text because the gtol has 
                            read-only access.

*/

extern ProError ProGtolLeftTextGet (ProGtol* gtol, wchar_t** left_text);
/*
    Purpose: Obtains the text added to the left of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        left_text - The text added to the left of the geometric tolerance. If 
                   the text extends over multiple lines, the output string will 
                   contain '\n' characters indicating the line breaks.  Free 
                   this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have text to left.

*/

extern ProError ProGtolLeftTextSet (ProGtol* gtol, wchar_t* left_text);
/*
    Purpose: Assigns the text added to the left of the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        left_text - The text added to the left of the geometric tolerance. If 
                  the text should extend over multiple lines, the input string 
                  should contain '\n' characters indicating the line breaks.  
                  Note that the left text cannot extend beyond the length of 
                  the gtol control frame, and so the function may 
                  automatically insert line breaks into the text when doing 
                  this assignment.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the left text because the gtol has 
                            read-only access.

*/

extern ProError ProGtolAddlTextBoxedSet (ProGtol* gtol, ProGtolTextType text_type, ProBoolean is_boxed);
/*
    Purpose : Set Boxed to Additional text to a geometric tolerance with particular ProGtolTextType.
              Note that only Top and Bottom ProGtolTextType can have Boxed.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
            gtol - The geometric tolerance.
            text_type - The instance of additional text to access.
            is_boxed - Set boxed to the additional text. Pass PRO_B_TRUE to set the Boxed.
    
    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
            PRO_TK_CANT_WRITE - Cannot modify the gtol because it is read-only.

*/

extern ProError ProGtolAddlTextBoxedGet (ProGtol* gtol, ProGtolTextType text_type, ProBoolean* is_boxed);
/*
    Purpose : Get if Additional text to a geometric tolerance with particular ProGtolTextType is Boxed.
              Note that only Top and Bottom ProGtolTextType can have Boxed.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
            gtol - The geometric tolerance.
            text_type - The instance of additional text to access.

    Output Arguments:
            is_boxed - PRO_B_TRUE if Additional text to a gtol with particular ProGtolTextType is Boxed.

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
            PRO_TK_E_NOT_FOUND - The gtol does not have text on particular ProGtolTextType.

*/

extern ProError ProGtolPrefixGet (ProGtol* gtol, wchar_t** prefix);
/*
    Purpose: Obtains the prefix text for the geometric tolerance.
    
    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        prefix - The prefix text.  Free this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not contain prefix text.

*/

extern ProError ProGtolPrefixSet (ProGtol* gtol, wchar_t* prefix);
/*
    Purpose: Assigns the prefix text for the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        prefix - The prefix text.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol prefix cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the text because the gtol is read-only.

*/

extern ProError ProGtolSuffixGet (ProGtol* gtol, wchar_t** suffix);
/*
    Purpose: Obtains the suffix text for the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.

    Output Arguments:
        suffix - The suffix text.  Free this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not contain suffix text.

*/

extern ProError ProGtolSuffixSet (ProGtol* gtol, wchar_t* suffix);
/*
    Purpose: Assigns the suffix text for the geometric tolerance.

    Input Arguments:
        gtol - The geometric tolerance.
        suffix - The suffix text.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol suffix cannot be varied.
        PRO_TK_CANT_WRITE - Cannot set the text because the gtol is read-only.

*/

extern ProError ProGtoltextTextstyleGet (ProGtol* gtol, 
                                         ProGtolTextType text_type, 
					 ProTextStyle* text_style);
/*
    Purpose: Gets the text style for the additional text applied to a geometric
             tolerance.

    Licensing Requirement:	
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The geometric tolerance.
        text_type - The instance of additional text to access.

    Output Arguments:
        text_style - The text style.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The gtol does not have the additional text
                             specified.

*/

extern ProError ProGtoltextTextstyleSet (ProGtol* gtol, 
                                         ProGtolTextType text_type, 
					 ProTextStyle text_style);
/*
    Purpose: Sets the text style for the additional text applied to a geometric
             tolerance.  Note that not all text style properties are supported 
             for gtol additional text; unsupported properties are ignored by 
             this function.

    Licensing Requirement:	
          TOOLKIT for 3D Drawings

    Input Arguments:
        gtol - The geometric tolerance.
        text_type - The instance of additional text to access.
        text_style - The text style.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
	PRO_TK_BAD_CONTEXT    - The gtol text style cannot be varied.
        PRO_TK_CANT_WRITE - Cannot modify the gtol because it is read-only.

*/

extern ProError ProGtolRightTextEnvelopeGet (ProGtol* note,

                                        ProLineEnvelope envelope);

/*
    Purpose: Get the envelope of the right text in a specified geometric tolerance.

<p><b>Note:</b>
    This function only supports gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The gtol.

    Output Arguments:
        envelope - The envelope surrounding the right text, in the model's
                   coordinate system.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProGtoldataAlloverSet(
   ProGtoldata data,
   ProBoolean  all_over_symbol,
   ProGtoldataStatus *status);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAllOverSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolAllOverSet() instead.
   
            Sets All Over Symbol for Gtol Leader Elbows

   Input Arguments:
      data              - The gtol data description
      all_over_symbol   - Sets All Over Symbol. Pass PRO_B_TRUE to set the symbol
   Output Arguments:
      status            - The resulting status of the gtol
                          If not interested in status pass NULL.

   Return Values:
      PRO_TK_NO_ERROR       -The function completed successfully.
      PRO_TK_BAD_INPUTS     -One or more of the input arguments are invalid.
      PRO_TK_CANT_MODIFY   - The All Over Symbol may not be modified for
                             this gtol data.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/
	
extern ProError ProGtoldataAlloverGet (
   ProGtoldata data,
   ProBoolean  *all_over_symbol);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolAllOverGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolAllOverGet() instead.
   
            Gets All Over Symbol for Gtol Leader Elbows

   Input Arguments:
      data              - The gtol data description

   Output Arguments:
      all_over_symbol   - PRO_B_TRUE when All Over symbol is checked. 

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldatumrefTranslationSet (
   ProGtoldatumref data,
   ProBoolean  datum_ref_trans);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolDatumReferencesSet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolDatumReferencesSet() instead

            Sets Datum Translation Symbol for Gtol Datums

   Input Arguments:
      data            - The datum reference data
      datum_ref_trans - Sets Translation symbol. Pass PRO_B_TRUE to set the symbol

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       -The function completed successfully.
      PRO_TK_BAD_INPUTS     -One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtoldatumrefTranslationGet (
   ProGtoldatumref data,
   ProBoolean  *datum_ref_trans);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProGtolDatumReferencesGet

   Purpose: <b>Note:</b> This function is deprecated.
            Use ProGtolDatumReferencesGet() instead

            Gets Datum Translation Symbol for Gtol Datums

   Input Arguments:
      data              - The datum reference data

   Output Arguments:
      datum_ref_trans - PRO_B_TRUE when Translation symbol is checked. 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolTopTextHorizJustificationSet (
   ProGtol* gtol, ProTextHrzJustification justification);
/*
   Purpose:    Sets horizontal justification for additional gtol text at the top

   Input Arguments:
      gtol              - The gtol
      justification - Applied justification

   Output Arguments:
      none

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolTopTextHorizJustificationGet (
   ProGtol* gtol, ProTextHrzJustification *justification);
/*
   Purpose:    Gets horizontal justification for additional gtol text at the top

   Input Arguments:
      gtol              - The gtol

   Output Arguments:
      justification - Justification to apply. 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolBottomTextHorizJustificationSet (
   ProGtol* gtol, ProTextHrzJustification justification);
/*
   Purpose:    Sets horizontal justification for additional gtol text at the bottom

   Input Arguments:
      gtol              - The gtol
      justification - Applied justification

   Output Arguments:
      none

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProGtolBottomTextHorizJustificationGet (
   ProGtol* gtol, ProTextHrzJustification *justification);
/*
   Purpose:    Gets horizontal justification for additional gtol text at the bottom

   Input Arguments:
      gtol              - The gtol

   Output Arguments:
      justification - Justification to apply. 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred and the function failed.
*/

extern ProError ProMdlGtolCreate (ProMdl owner_mdl, ProGtolType type, ProGtolAttach gtol_attach, wchar_t* value_str, ProGtol *gtol);
/*
   Purpose:   Creates new Gtol with specified placement and value string

   Input Arguments:
     owner_mdl  - Owner of the gtol.
	   type       - type of gtol.
	   gtol_attach  - placement which includes attachment references and annotation plane.
	   value_str  - value string.

   Output Arguments:
		 gtol - newly created gtol.

   Return Values:
     PRO_TK_NO_ERROR      - The function completed successfully.
     PRO_TK_BAD_CONTEXT	  - Specified placement reference are invalid.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - Gtol could not be created.
     PRO_TK_UNSUPPORTED   - owner_mdl is not drawing for creating 
                            make dim or offset type gtol.
*/

extern ProError  ProGtolValueStringSet (ProGtol *gtol, wchar_t* value);
/*
   Purpose:   Set value string of gtol

   Input Arguments:
     gtol			  - valid gtol.
	   value      - value string.

   Output Arguments:
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError  ProGtolValueStringGet (ProGtol *gtol, wchar_t** value);
/*
   Purpose:   Get value string of gtol

   Input Arguments:
     gtol			 - valid gtol.	  

   Output Arguments:
	   value           - value string.Free it using ProWstringFree()
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
	   PRO_TK_E_NOT_FOUND    - No value string found
*/

extern ProError  ProGtolAllOverSet(ProGtol *gtol, ProBoolean all_over);
/*
   Purpose:   Set all over option for profile gtol

   Input Arguments:
      gtol			 - valid gtol.
      all_over   - Pass PRO_B_TRUE to set all over else pass PRO_B_FASLE
	
   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR      - The function completed successfully.
	   PRO_TK_CANT_MODIFY   - This type of gtol does not support all over.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
*/

extern ProError  ProGtolAllOverGet(ProGtol *gtol, ProBoolean *all_over);
/*
   Purpose:   Get all over option for profile gtol

   Input Arguments:
     gtol			 - valid gtol.	  

   Output Arguments:
	   all_over        - PRO_B_TRUE if all over is set else PRO_B_FASLE
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
	   PRO_TK_INVALID_TYPE   - This type of gtol does not support all over.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError  ProGtolAllAroundSet(ProGtol *gtol, ProBoolean all_around);
/*
   Purpose:   Set all around option for profile gtol

   Input Arguments:
     gtol			   - valid gtol.	  
     all_around  - Pass PRO_B_TRUE to set all around else pass PRO_B_FASLE

   Output Arguments:	   
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
	   PRO_TK_CANT_MODIFY    - This type of gtol does not support all around.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError  ProGtolAllAroundGet(ProGtol *gtol, ProBoolean *all_around);
/*
   Purpose:   Get all around option for profile gtol

   Input Arguments:
     gtol			   - valid gtol.	  

   Output Arguments:
	   all_around  - PRO_B_TRUE if all around is set else PRO_B_FASLE
	
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_INVALID_TYPE   - This type of gtol does not support all around.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeGet (ProGtol *gtol, wchar_t*** values ,wchar_t*** primary ,wchar_t*** secondary ,wchar_t*** tertiary);
/*
   Purpose:   Get composite tolerance frame

   Input Arguments:
      gtol			 - valid gtol.	  

   Output Arguments:
		 values    -  NULL or ProArray() of value strings. Free it using ProWstringproarrayFree()
		 primary   -  NULL or ProArray() of primary strings. Free it using ProWstringproarrayFree()
		 secondary -  NULL or ProArray() of secondary strings. Free it using ProWstringproarrayFree()
		 tertiary  -  NULL or ProArray() of tertiary strings. Free it using ProWstringproarrayFree()

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeSet(ProGtol *gtol, int index ,wchar_t* value ,wchar_t* primary ,wchar_t*  secondary ,wchar_t* tertiary);
/*
   Purpose:   Set composite tolerance

   Input Arguments:
     gtol   - valid gtol.
	   index  - position.Indices starts from 0. Pass PRO_VALUE_UNUSED to insert at end.
     value     -  value string. If NULL, row corresponding to input index will be removed.
     primary   -  primary datum string.
     secondary -  secondary datum string.
     tertiary  -  tertiary datum string.
   
   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	
     PRO_TK_OUT_OF_RANGE   - invalid index
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolDatumReferencesSet (ProGtol *gtol, wchar_t* primary,wchar_t* secondary,wchar_t* tertiary);
/*
   Purpose:   Set datum references to gtol.

   Input Arguments:
     gtol			 - valid gtol.
     primary   - primary datum ref. Can be NULL
     secondary - secondary datum ref. Can be NULL
     tertiary  - tertiary datum ref. Can be NULL

   Output Arguments:
		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	 
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolDatumReferencesGet (ProGtol *gtol, wchar_t** primary,wchar_t** secondary,wchar_t** tertiary);
/*
   Purpose:   Get datum references to gtol.

   Input Arguments:
     gtol			 - valid gtol.	  

   Output Arguments:
	   primary -  primary datum ref. Can be NULL.  Free it using ProWstringFree()
	   secondary -  secondary datum ref. Can be NULL. Free it using ProWstringFree()
	   tertiary -  tertiary datum ref. Can be NULL. Free it using ProWstringFree()
		

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.	 
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeShareRefSet(ProGtol *gtol,ProBoolean share);
/*
   Purpose:   Set Share datum references for composite frame

   Input Arguments:
     gtol		- valid gtol.	  
     share  - Pass PRO_B_TRUE to share else pass PRO_B_FALSE

   Output Arguments:

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolCompositeShareRefGet(ProGtol *gtol,ProBoolean *share);
/*
   Purpose:   Get Share datum references for composite frame

   Input Arguments:
     gtol - valid gtol.

   Output Arguments:
     share - share option.		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolTypeSet (ProGtol *gtol , ProGtolType type);
/*
   Purpose:   Set gtol type

   Input Arguments:
     gtol    - valid gtol.	
     type    - gtol type

   Output Arguments:      		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolTypeGet (ProGtol *gtol , ProGtolType *type);
/*
   Purpose:   Set gtol type

   Input Arguments:
     gtol    - valid gtol.

   Output Arguments:
     type    - gtol type

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.      
*/

extern ProError ProGtolBoundaryDisplaySet(ProGtol *gtol, ProBoolean boundary);
/*
   Purpose:   Set display of Boundary modifier.

   Input Arguments:
     gtol			 - valid gtol.
     boundary  - Pass PRO_B_TRUE to display else pass PRO_B_FALSE

   Output Arguments:		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_CANT_MODIFY    - This type of gtol cannot have boundary modifier
*/

extern ProError ProGtolBoundaryDisplayGet(ProGtol *gtol, ProBoolean *boundary);
/*
   Purpose:   Get display of Boundary modifier.

   Input Arguments:
     gtol	- valid gtol.

   Output Arguments:
     boundary -  boundary option.

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_INVALID_TYPE   - This type of gtol cannot have boundary modifier
 */

extern ProError ProGtolUnilateralSet(ProGtol *gtol, ProBoolean unilateral_set, ProBoolean outside);
/*
   Purpose:   Set Unilateral modifier.

   Input Arguments:
     gtol			      - valid gtol.
     unilateral_set - PRO_B_TRUE to set Unilateral modifier 
                      PRO_B_FALSE to remove Unilateral modifier 
     outside        - Whether the tolerance refers to the outside of
                      the profile, if unilateral_set == PRO_B_TRUE

   Output Arguments:		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_CANT_MODIFY    - This type of gtol cannot have unilateral modifier
*/

extern ProError ProGtolUnilateralGet(ProGtol *gtol, ProBoolean *unilateral_set, ProBoolean *outside);
/*
   Purpose:   Get Unilateral modifier.

   Input Arguments:
     gtol	- valid gtol.

   Output Arguments:
     unilateral_set -  unilateral modifier.
     outside        -  Whether the tolerance refers to the outside of
                       the profile, if unilateral_set == PRO_B_TRUE

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
	   PRO_TK_INVALID_TYPE   - This type of gtol cannot have unilateral modifier
 */

extern ProError  ProGtolTopModelGet(ProGtol *gtol,ProMdl *top_mdl);
/*
   Purpose:   Get top model of gtol

   Input Arguments:
     gtol		 - valid gtol.	  	  

   Output Arguments:
     top_mdl		 - The model (part, assembly, or drawing) that  
                           defines the origin of ProSelection structures used
                           in setting up gtol references.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.	  	  
      PRO_TK_BAD_INPUTS     - The input argument is invalid.
*/

extern ProError ProGtolElbowlengthSet (ProGtol* gtol, double elbow_length, ProVector elbow_direction);
/*
    Purpose: Set elbow to gtol.
<p><b>Note:</b>
    This function only supports leader type gtols which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
      gtol            - The gtol.
		  elbow_length    - The elbow length, in model units.
		  elbow_direction - The elbow direction, in the model's coordinate
		                    system.  This is the direction from the gtol text 
                        to the gtol leaders.

    Output Arguments:       

    Return Values:
      PRO_TK_NO_ERROR     - The function succeeded.
      PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.        
      PRO_TK_INVALID_TYPE - The gtol does not use leaders.
*/

extern ProError  ProGtolSymbolStringGet (ProGtolSymbol symbol, ProSymbolFont font, wchar_t **value);
/*
   Purpose:   Get value string of gtol

   Input Arguments:
      symbol			 - Type of symbol 
	  font			     - Symbol font type

   Output Arguments:
	  value           - value string. Free it using ProWstringFree()
	
   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.	  
      PRO_TK_BAD_INPUTS     - The input argument is invalid.	  
*/

extern ProError ProGtolReferencesAdd( ProGtol                    *gtol, 
                                      ProAnnotationReference     *refs );
/*
   Purpose:   Add gtol references

   Input Arguments:
      gtol  - valid gtol.
      refs  - ProArray of gtol references.

   Output Arguments:      
      

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
      PRO_TK_BAD_CONTEXT    - The gtol owner is drawing.
*/

extern ProError ProGtolReferencesGet( ProGtol                 *gtol, 
                                      ProAnnotationReference **p_refs );
/*
   Purpose:   Get gtol references

   Note:  
	This function only supports gtols which are not created as Annotation Elements.
	For Annotation Element Gtol use ProAnnotationelemReferencesCollect().
		
   Input Arguments:
     gtol        - valid gtol.
    
   Output Arguments:
     p_refs   - ProArray of gtol references. Free it using ProAnnotationreferencearrayFree()
    
   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_BAD_CONTEXT    - The gtol owner is drawing.
		  
	See Also:
     ProAnnotationElementGet()
*/

extern ProError ProGtolReferenceDelete( ProGtol *gtol, 
                                        int      index_ref );
/*
   Purpose:   Delete gtol reference

   Input Arguments:
      gtol    - valid gtol. 
 index_ref    - Indices start from 0. Get existing references from ProGtolReferencesGet()

   Output Arguments:       

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - The input argument is invalid.      
      PRO_TK_BAD_CONTEXT    - The gtol owner is drawing..
*/

extern ProError ProGtolIndicatorsSet (ProGtol *gtol, ProGtolIndicatorType *types, wchar_t **symbols, wchar_t **dfs);
/*
   Purpose:   Set indicators of gtol. Pass types, symbols and dfs as NULL to remove all indicators.

   Input Arguments:
    gtol     - valid gtol.
	  types    - ProArray() of indicator types. Maximum array size is 3.
	  symbols  - ProArray() of indicator symbols strings. Maximum array size is 3.
	  dfs			 - ProArray() of dfs strings. Maximum array size is 3.

   Output Arguments:		

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.	 
*/

extern ProError ProGtolIndicatorsGet (ProGtol *gtol, ProGtolIndicatorType **types, wchar_t ***symbols, wchar_t ***dfs);
/*
   Purpose:     Get indicators of gtol

   Input Arguments:
     gtol			- valid gtol.	  

   Output Arguments:
		 types    -  ProArray() of indicator types. Free it using ProArrayFree()
		 symbols  -  ProArray() of indicator symbols strings. Free it using ProWstringproarrayFree()
		 dfs      -  ProArray() of dfs strings. Free it using ProWstringproarrayFree()		 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
	   PRO_TK_E_NOT_FOUND    - No indicators found for specified gtol
*/

extern ProError  ProGtolNameGet (ProGtol *gtol, wchar_t **p_name);
/*
   Purpose:   Get name of gtol

   Input Arguments:
     gtol   - valid gtol.

   Output Arguments:
     p_name - name string.Free it using ProWstringFree()

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_E_NOT_FOUND    - Gtol is not found in database.
*/

extern ProError ProGtolValidate (ProGtol *gtol, ProGtolValidityCheckType type, ProBoolean *is_valid_gtol);
/*
   Purpose:     Check whether the gtol is valid or not

   Input Arguments:
     gtol     - gtol.
     type     - type of validity check

   Output Arguments:
     is_valid_gtol - PRO_B_TRUE if GTol is valid, PRO_B_FALSE otherwise 

   Return Values:
     PRO_TK_NO_ERROR       - The function completed successfully.	  
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR  - The function encountered an error.
*/

PRO_END_C_DECLS
#endif /* PROGTOL_H */
