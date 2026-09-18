#ifndef PROWELD_H
#define PROWELD_H



#include <ProToolkit.h>
#include <ProFeature.h>
#include <ProParameter.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef enum weld_type
{
    PRO_WELD_NONE		= -1,
    PRO_WELD_FILLET		= 0,
    PRO_WELD_GROOVE		= 1,
    PRO_WELD_PLUG		= 2,
    PRO_WELD_SLOT		= 3,
    PRO_WELD_SPOT		= 4,
    PRO_WELD_GROOVE_W_EDGE_PREP = 5 
} ProWeldtype;

typedef enum weld_subtype
{
    PRO_WELD_GROOVE_NONE                = -1,
    PRO_WELD_GROOVE_SQUARE		= 0,
    PRO_WELD_GROOVE_V			= 1,
    PRO_WELD_GROOVE_BEVEL		= 2,
    PRO_WELD_GROOVE_U			= 3,
    PRO_WELD_GROOVE_J			= 4,
    PRO_WELD_GROOVE_FLARED_V		= 5,
    PRO_WELD_GROOVE_FLARED_BEVEL 	= 6,
    PRO_WELD_GROOVE_Y               = 7,
    PRO_WELD_GROOVE_HY              = 8
} ProWeldsubtype;

typedef struct weld_info
{
    double size[2];
    double x_sec_area;
    double length;
    double volume;
    double mass;
    double time;
    double rod_length;
} ProWeldInfo;

typedef struct weld_intermittence
{
    ProBoolean  angular;
    ProBoolean  at_center;
    double      length;
    double      pitch;
    int         number_of_welds;
} ProWeldIntermittence;

typedef struct fillet_geom
{
    ProWeldtype weld_type;
    ProBoolean  all_around;
    double      trajectory_length;
} ProWeldFilletdata;

typedef struct groove_geom
{
    ProWeldtype weld_type;
    double      butt_width;
    double      face_offset;
    double      trajectory_length;
    double      penetration;
} ProWeldGroovedata;

typedef struct plug_geom
{
    ProWeldtype weld_type;
    double      depth;
} ProWeldPlugdata;

typedef struct slot_geom
{
    ProWeldtype weld_type;
    double      depth;
} ProWeldSlotdata;

typedef struct spot_geom
{
    ProWeldtype weld_type;
    int         number_of_points;
    double      diameter;
    double      penetration;
} ProWeldSpotdata;


typedef enum _pro_weld_geom_type_
{
  PRO_WELD_LIGHT  ,
  PRO_WELD_SURFACE,
  PRO_WELD_SOLID  
} ProWeldGeomType;


extern ProError ProWeldTypeGet(ProFeature *weld,
                               ProWeldtype *type,
                               ProWeldsubtype *subtype);

/*
    Purpose:	The get the type and subtype of the weld

    Input Arguments:
	weld		- The weld feature

    Output Arguments:
	type		- The weld type
	subtype		- The weld subtype, NULL is allowed if not interested.

    Return Values:
	PRO_TK_NO_ERROR
	PRO_TK_BAD_INPUTS       - weld feature handle is invalid or
                                  type is NULL pointer.
	PRO_TK_BAD_CONTEXT	- The feature is not a weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldInfoGet(ProFeature  *weld,
                               ProWeldInfo *info);

/*
    Purpose:	To get weld information

    Input Arguments:
	weld		- The weld feature

    Output Arguments:
	info		- A pointer to the allocated weld info structure.

    Return Values:
	PRO_TK_NO_ERROR         - The function successfully initialized
                                  weld info structure.
	PRO_TK_BAD_INPUTS       - weld feature handle is invalid.
	PRO_TK_BAD_CONTEXT	- The feature is not a weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/
extern ProError ProWeldIntermittenceGet(ProFeature *weld,
                                        ProStandard           standard,
				        ProWeldIntermittence *intermittence);

/*
    Purpose:	To get weld intermittence information

    Input Arguments:
	weld		- The weld feature
        standard        - PROSTANDARD_ISO or PROSTANDARD_ANSI

    Output Arguments:
	intermittence	- A pointer to allocated weld intermittence structure.

    Return Values:
	PRO_TK_NO_ERROR         - The function successfully initialized
                                  the intermittence structure.
	PRO_TK_BAD_INPUTS       - weld feature handle is invalid or
                                  intermittence is NULL pointer.
	PRO_TK_BAD_CONTEXT	- The feature is not a weld.
        PRO_TK_E_NOT_FOUND      - The weld is not intermittent.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldSequenceIdGet(ProFeature *weld,
				     int *sequence_id);

/*
    Purpose:	The get the sequence id of a weld feature

    Input Arguments:
	weld		- The weld feature

    Output Arguments:
	sequence_id	- The sequence id of the weld.

    Return Values:
	PRO_TK_NO_ERROR
	PRO_TK_BAD_INPUTS       - weld feature handle is invalid or
                                  sequence_id is NULL pointer.
	PRO_TK_BAD_CONTEXT	- The feature is not a weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldRodGet(ProFeature *weld,
			      ProFeature *rod);

/*
    Purpose:	To provide the feature handle of the rod for the specified
		weld feature

    Input Arguments:
	weld		- The weld feature

    Output Arguments:
	rod		- The rod feature.

    Return Values:
	PRO_TK_NO_ERROR
	PRO_TK_BAD_INPUTS       - weld or rod argument is invalid;
	PRO_TK_BAD_CONTEXT	- The feature is not a weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldRodNameGet(ProFeature *rod,
                                  ProName name);

/*
    Purpose:	To get the name of a weld rod

    Input Arguments:
	rod		- The weld rod feature handle

    Output Arguments:
	name		- The rod name

    Return Values:
	PRO_TK_NO_ERROR
	PRO_TK_BAD_INPUTS       - rod feature handle is invalid.
	PRO_TK_BAD_CONTEXT	- The feature is not a weld rod.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldCompoundGet(ProFeature  *weld,
                                   ProFeature **members,
                                   int         *n_members);

/*
    Purpose:	To get the list of welds in a a compound weld.

    Input Arguments:
	weld            - The weld feature

    Output Arguments:
	members		- A ProArray, allocated by the function, of weld
			  features that belong to the weld.
	n_members	- The number of welds in the compound.

    Return Values:
	PRO_TK_NO_ERROR
	PRO_TK_BAD_INPUTS       - weld is invalid feature handle or
                                  n_members is NULL pointer  or
                                  members   is NULL pointer  or
                                  *members  is not NULL pointer.
	PRO_TK_BAD_CONTEXT	- The feature is not weld.
        PRO_TK_E_NOT_FOUND      - The weld is not compound weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldFilletdataGet(ProFeature *fillet_weld,
				     ProWeldFilletdata *fillet_data);
/*
    Purpose:    To get the fillet weld specific information.

    Input Arguments:
        fillet_weld     - The fillet weld feature

    Output Arguments:
        fillet_data     - A pointer to the ProWeldFilletdata structure
                          provided by the caller.

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS       - fillet_weld is invalid feature handle or
                                  fillet_data is NULL pointer.
        PRO_TK_BAD_CONTEXT      - The feature is not a weld.
        PRO_TK_INVALID_TYPE     - The weld is not a fillet weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldGroovedataGet(ProFeature *groove_weld,
                                     ProWeldGroovedata *groove_data);
/*
    Purpose:    To get the groove weld specific information.

    Input Arguments:
        groove_weld     - The groove weld feature

    Output Arguments:
        groove_data     - A pointer to the ProWeldGroovedata structure
			  provided by the caller.

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS       - groove_weld is invalid feature handle or
                                  groove_data is NULL pointer.
        PRO_TK_BAD_CONTEXT      - The feature is not a weld.
        PRO_TK_INVALID_TYPE     - The weld is not a groove weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldPlugdataGet(ProFeature *plug_weld,
				   ProWeldPlugdata *plug_data);
/*
    Purpose:    To get the plug weld specific information.

    Input Arguments:
        plug_weld       - The plug weld feature

    Output Arguments:
        plug_data       - A pointer to the ProWeldPlugdata structure
			  provided by the caller.

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS       - plug_weld is invalid feature handle or
                                  plug_data is NULL pointer.
        PRO_TK_BAD_CONTEXT      - The feature is not a weld.
        PRO_TK_INVALID_TYPE     - The weld is not a plug weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldSlotdataGet(ProFeature *slot_weld,
				   ProWeldSlotdata *slot_data);
/*
    Purpose:    To get the slot weld specific information.

    Input Arguments:
        slot_weld       - The slot weld feature

    Output Arguments:
        slot_data       - A pointer to the ProWeldSlotdata structure
                          provided by the caller.

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS       - slot_weld is invalid feature handle or
                                  slot_data is NULL pointer.
        PRO_TK_BAD_CONTEXT      - The feature is not a weld.
        PRO_TK_INVALID_TYPE     - The weld is not a slot weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

extern ProError ProWeldSpotdataGet(ProFeature *spot_weld,
				   ProWeldSpotdata *spot_data);
/*
    Purpose:    To get the spot weld specific information.

    Input Arguments:
        spot_weld       - The spot weld feature

    Output Arguments:
        spot_data       - A pointer to the ProWeldSpotdata structure
                          provided by the caller.

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS       - spot_weld is invalid feature handle or
                                  spot_data is NULL pointer.
        PRO_TK_BAD_CONTEXT      - The feature is not a weld.
        PRO_TK_INVALID_TYPE     - The weld is not a spot weld.
        PRO_TK_NO_LICENSE       - Pro/Welding license is not found.

*/

typedef ProError (*ProDrawingWeldSympathGetAction)( ProDrawing p_draw,
						    ProMdl p_model,
						    int feat_id,
						    ProPath sym_def_file_path,
						    ProPath ptk_sym_def_path );
/*
   Purpose:
  	This is the notification function called when Creo Parametric is
	preparing to read a symbol definitions file.
<p>
	This function is to be supplied by the user by calling
	<b>ProNotificationSet()</b> with the notify type PRO_DRAWING_WELD_SYMPATH_GET

   Input Arguments:
	p_draw            - Drawing in which the symbols will be used.
	p_model           - Model on which the symbols will be used.
	feat_id           - Feature (of <i>p_model</i> to which the
			    symbols will be applied.
	sym_def_file_path - Symbol definition file path that Creo Parametric
			    found (full path to file on disk).

   Output Arguments:
	ptk_sym_def_path  - Symbol definition file that the application
			    directs Creo Parametric to use (full path to file on
			    disk).

   Return Values:
	PRO_TK_NO_ERROR    - Use the file returned in ptk_sym_def_path.
	PRO_TK_E_NOT_FOUND - Do not use the file returned in ptk_sym_def_path.
			     (In this case Creo Parametric will proceed as usual.)
                                                                            
   See Also:
        ProNotificationSet()
                                                                               
*/

typedef ProError (*ProDrawingWeldGroupsGetAction)( ProDrawing p_draw,
						   ProMdl p_model,
						   int feat_id,
						   int sym_def_id,
						   ProBoolean left_side,
						   int* group_ids,
						   ProName* group_names,
						   int n_groups,
						   ProBoolean* include_groups );
/*
   Purpose:
  	This is the notification function called when Creo Parametric is
	preparing to set symbol group IDs.
<p>
	This function is to be supplied by the user by calling
	<b>ProNotificationSet()</b> with the notify type PRO_DRAWING_WELD_GROUPS_GET

   Input Arguments:
	p_draw            - the drawing in which the symbols will be used.
	p_model           - the model on which the symbols will be used.
	feat_id           - the feature (of <i>p_model</i> to which the
			    symbols will be applied.
	sym_def_id        - ID of the symbol definition
	left_side         - whether the symbol's leader comes from the left
        group_ids         - IDs of the symbol groups
        group_names       - names of the symbol groups
        n_groups          - number of groups (size of arrays group_ids and
			    group_names)

   Output Arguments:
	include_groups    - Whether to include each of the groups listed in
			    p_group_ids and p_group_names. This array is
			    allocated and freed by Creo Parametric.

   Return Values:
	PRO_TK_NO_ERROR    - Use the group ID info returned in include_groups.
	PRO_TK_E_NOT_FOUND - Application did not supply group IDs for this
			     symbol. (In this case Creo Parametric will proceed
			     as usual.)
                                                                            
   See Also:
        ProNotificationSet()
                                                                               
*/

typedef ProError (*ProDrawingWeldSymtextGetAction)( ProDrawing p_draw,
						    ProMdl p_model,
						    int feat_id,
						    int sym_def_id,
						    wchar_t sym_prompt_name[],
						    int sym_prompt_nm_idx,
						    ProParamvalue* p_text,
						    ProParamvalue* p_ptk_text );

/*
   Purpose:
  	This is the notification function called when Creo Parametric is
	preparing to set symbol text values
<p>
	This function is to be supplied by the user by calling
	<b>ProNotificationSet()</b> with the notify type PRO_DRAWING_WELD_SYMTEXT_GET

   Input Arguments:
	p_draw            - Drawing in which the symbols will be used
	p_model           - Model on which the symbols will be used
	feat_id           - Feature (of <i>p_model</i> to which the
			    symbols will be applied
	sym_def_id        - Identifer of symbol definition
        sym_prompt_name   - Prompt name as defined in symbol definition
        sym_prompt_nm_idx - Identifier of note within symbol definition that
                            has this prompt
	p_text		  - Text value currently used by the symbol

   Output Arguments:
	p_ptk_text        - Text value supplied by the application for the
			    symbol; may be a double, int, or string.

   Return Values:
	PRO_TK_NO_ERROR    - Use the text value supplied by the application.
	PRO_TK_E_NOT_FOUND - Application did not supply text value for this
			     symbol. (In this case Creo Parametric will proceed
			     as usual.)

   See Also:
        ProNotificationSet()
                                                                               
*/

extern ProError ProMdlIsSolidWeld (ProMdl model, ProBool* r_ret);

/*
    Purpose:	Check that model is created by solid weld feature.

    Input Arguments:
	model		- The model to check.

    Output Arguments:
        r_ret           - Whether given model was created by solid weld.

    Return Values:
	PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS  - model is NULL.
        PRO_TK_INVALID_PTR - model is not real model but Object Name.

*/

extern ProError ProWeldGeomTypeGet (ProFeature *weld, ProWeldGeomType *type);

/*
    Purpose:	Checks the type of geometry representation for the specified weld.

    Input Arguments:
	weld		- The feature to check.

    Output Arguments:
        type            - Geom type (Light, Surface, Solid) of weld feature.

    Return Values:
	PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS  - type is NULL or weld is not a valid feature.

*/

PRO_END_C_DECLS
#endif /* PROWELD_H */
