#ifndef PRONOTE_H
#define PRONOTE_H



#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProGraphic.h>
#include <ProSelection.h>
#include <ProDtlnote.h>
#include <ProDimension.h>

PRO_BEGIN_C_DECLS



typedef enum pro_text_style_obj_type 
{
 /*Following enums represents ProDtlnote */ 
 PRO_DTL_NOTE_DATA_TEXTSTYLE,
 PRO_DTL_NOTE_TEXT_TEXTSTYLE, 
 
 /*Following enum represents ProNote*/ 
 PRO_NOTE_TEXTSTYLE,

 PRO_DIMENSION_TEXTSTYLE, 
 PRO_DIMENSION_2D_TEXTSTYLE, 

 PRO_GTOL_TOP_TEXT_TEXTSTYLE,
 PRO_GTOL_BOTTOM_TEXT_TEXTSTYLE,
 PRO_GTOL_LEFT_TEXT_TEXTSTYLE,
 PRO_GTOL_RIGHT_TEXT_TEXTSTYLE,

 PRO_SET_DATUM_TAG_TEXTSTYLE,
 PRO_SYMBOL_INSTANCE_TEXTSTYLE


} ProTextStyleObjectType;


typedef wchar_t ProURL[PRO_LINE_SIZE];

/* 
 * this is an opaque handle for note attachment, the user should not dereference 
 */
typedef struct pro_note_attach *ProNoteAttach;

typedef enum pro_note_attach_attr{
  PRO_NOTE_ATT_NONE    = 0,
  PRO_NOTE_ATT_NORMAL  = 1,
  PRO_NOTE_ATT_TANGENT = 2
} ProNoteAttachAttr;

/* If the justification is default, the justification of the text style is
 * dependent on the leader of the text note.
 * If the leader is on right, the default means right justification;
 * If the leader is on left, the default means left justification.
 */

typedef ProLine *ProLinelist;

typedef ProError (*ProMdlNoteFilterAction)(ProNote *note_item,
                                           ProAppData app_data);
/*
   Purpose:  This a generic user filter function for visiting notes.

   Input Arguments:
      note_item - The <i>ProNote</i> being visited
      app_data  - The user data passed to the visit function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Call the visit function.
      PRO_TK_CONTINUE      - Skip this note and don't call the visit function.
      PRO_TK_GENERAL_ERROR - Stop visiting.
*/

typedef ProError (*ProMdlNoteVisitAction)(ProNote *note_item,
                                          ProError status,
                                          ProAppData app_data);
/*
   Purpose:  This is the generic visit function for visiting notes.

   Input Arguments:
      note_item - The <i>ProNote</i> being visited
      status    - The <i>ProError</i> status from the filter function
      app_data  - The user data passed to the visit function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Call the visit function.
      PRO_TK_GENERAL_ERROR - Stop visiting.
*/



extern ProError ProNoteCreate ( ProMdl mdl_handle, 
			ProModelitem *p_owner_item,
			ProLinelist line_list,
                        ProNote *note_item);

/* 
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProSolidNoteCreate
  Purpose: Creates a note in the specified model.
  <P><B>NOTE:</B> This function is superseded by ProSolidNoteCreate().

  Input Arguments:
     mdl_handle     - The model owner.
     p_owner_item   - The parent/owner of the note.  If the owner is a part or 
                      assembly, this is the model itself (use
		      ProMdlToModelitem()). If the owner is a feature, this is 
		      a feature/component that belongs to the model.
     line_list      - The line list, which is a <i>ProArray</i>.  Use the
                      <i>ProArray</i> functions to manipulate the data.

  Output Arguments:
     note_item      - The new note.

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully created the note. 
     PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

  See Also:
     ProArrayAlloc()
     ProArrayFree()
 
*/


extern ProError ProSolidNoteCreate ( ProMdl 	    mdl_handle, 
				     ProModelitem  *p_owner_item,
			             wchar_t      **p_note_text,
                        	     ProNote       *note_item );

/* 

  Purpose: Creates a note in the specified solid model. ProAnnotationShow() 
    should be called after creating the note in order for the note to be 
    displayed.

  Input Arguments:
     mdl_handle     - The owner model for the note (part or assembly).
     p_owner_item   - The owner of the note.  If the note is to be owned by a 
		      feature, pass the feature here.  If the note is to be 
		      owned by the model, pass NULL.
     p_note_text    - The ProArray of note text lines.

  Output Arguments:
     note_item      - The new note.

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully created the note. 
     PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
 
*/



extern ProError ProNoteDelete ( ProNote *note_item );

/*

  Purpose: Deletes a note in the specified model. The valid model types
           are PRO_PART and PRO_ASSEMBLY.

  Input Arguments:
     note_item   - The note to delete

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully deleted the note.
     PRO_TK_BAD_INPUTS - The argument is invalid.
     PRO_TK_CANT_WRITE - Could not delete the given item because
                         it has read-only access.
*/


extern ProError ProNoteLinelistGet (ProNote *note_item, 
                                    ProLinelist *p_line_list);
/*

  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProNoteTextGet
  Purpose: Copies the specified note to the line list.
  <P><B>NOTE:</B> This function is superseded by ProNoteTextGet().

  Input Arguments:
     note_item    - The note to copy. 

  Output Arguments:
     p_line_list  - The line list of the <i>ProArray</i> to which to copy 
                    the note. Use <b>ProArrayFree()</b> to free the memory.

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully copied the note.
     PRO_TK_BAD_INPUTS - The input argument is invalid.

  See Also:
     ProArrayFree()
*/

        
extern ProError ProNoteLinelistSet ( ProNote *note_item, 
                                     ProLinelist line_list );

/*

  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProNoteTextSet
  Purpose: Copies the specified line list to the note.
  <P><B>NOTE:</B> This function is superseded by ProNoteTextSet().

  Input Arguments:   
     note_item     - The note to which to copy the line list
     line_list     - The line list of the <i>ProArray</i>

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully copied the line list.
     PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
     PRO_TK_CANT_WRITE - Could not modify the given item because
                         it has read-only access.
*/


extern ProError ProNoteTextGet ( ProNote          *p_note, 
				 ProDisplayMode    display_mode, 
				 wchar_t        ***p_note_text );
/*
  Purpose: Returns the note text for a 3d model note.  

  Input Arguments:  
     p_note         - The solid model note.
     display_mode   - The method used to return the text.   
		      If PRODISPMODE_NUMERIC, the note callout values are 
		      given.  If PRODISPMODE_SYMBOLIC, the note callout 
		      names are given.

  Output Arguments:
     p_note_text    - ProArray of wide strings.  Free this using 
		      ProWstringproarrayFree().

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProNoteTextSet ( ProNote  *p_note, 
				 wchar_t **p_note_text );
/*
  Purpose: Sets the note text for a 3d model note.  This function does 
	   not update the note display. Use ProNoteDisplay() to hide the
	   note, then set the text, then use ProNoteDisplay() to show it
	   again to accomplish this.

  Input Arguments:  
     p_note          - The solid model note.
     p_note_text     - ProArray of wide strings. 

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_BAD_CONTEXT   - The note text cannot be varied.
*/


extern ProError ProMdlNoteVisit ( ProMdl mdl_handle,
                          ProMdlNoteVisitAction visit_action,
                          ProMdlNoteFilterAction filter_action,
                          ProAppData app_data );

/*

  Purpose:
     Calls the specified filter and action functions for each note in the 
     model. 

  Input Arguments:
     mdl_handle     - The model (PRO_PART or PRO_ASSEMBLY).
     visit_action   - The action to perform on each note. If it
                      returns anything other than PRO_TK_NO_ERROR,
                      visiting stops.
     filter_action  - The filter function. If NULL, all notes are  
                      visited using the action function.
     app_data       - The application data passed to the visiting and
                      filter functions.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully visited all the notes.
     PRO_TK_BAD_INPUTS - One or more inputs was invalid.
     PRO_TK_GENERAL_ERROR - Visiting was stopped by the return from the 
                            visit action.
     PRO_TK_E_NOT_FOUND - There are no valid notes in the model. 

*/

extern ProError ProNoteDisplay( ProNote *p_note_item,
			ProDrawMode  draw_mode );

/*

  Purpose:
     Displays the specified note.

  Input Arguments:
     p_note_item    - The note to display
     draw_mode      - Specifies how to display the note

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully displayed the note.
     PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
*/

extern ProError ProNotePlacementSet( ProNote *p_note_item,
			ProNoteAttach note_att );

/*

  Purpose:
     Places the note at the specified location.

  Input Arguments:
     p_note_item    - The note to place
     note_att       - An opaque handle for the note attachment

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR        - The function successfully placed the note.
     PRO_TK_BAD_INPUTS      - One or more of the arguments are invalid.
     PRO_TK_GENERAL_ERROR   - A general error occurred and the function failed.
     PRO_TK_CANT_WRITE      - Could not modify the given item because
                              it has read-only access.
     PRO_TK_BAD_CONTEXT     - The note has a flat to screen annotation plane
                              incompatible with the placement.

*/

extern ProError ProNotePlacementGet( ProNote *p_note_item,
			ProNoteAttach  *r_note_att );

/*

  Purpose:
     Retrieves the placement information for the specified note.

  Input Arguments:
     p_note_item    - The note.

  Output Arguments:
     r_note_att     - The placement information. You must free this memory
                      when you are done using it. 

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully retrieved the 
                             information.
     PRO_TK_BAD_INPUTS     - The input argument is invalid.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.

*/

extern ProError ProNoteURLSet( ProNote *p_note_item,
			ProURL  url );

/*

  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProNoteURLWstringSet
  Purpose:
    <P><B>NOTE:</B> This function is deprecated.  Use 
                 ProNoteURLWstringSet() instead. </P>

    Sets the associated Uniform Resource Locator (URL) for the specified note.

  Input Arguments:
     p_note_item    - The note
     url	    - The URL 

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully set the URL.
     PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
     PRO_TK_BAD_CONTEXT   - The note url cannot be varied.
     PRO_TK_CANT_WRITE     - Could not modify the given item because
                             it has read-only access.

*/

extern ProError ProNoteURLGet( ProNote *p_note_item,
			ProURL  r_url );

/*

  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProNoteURLWstringGet
  Purpose:
     <P><B>NOTE:</B> This function is deprecated.  Use 
                 ProNoteURLWstringGet() instead. </P>
                                    
     Retrieves the Uniform Resource Locator (URL) associated with the 
     specified note.

  Input Arguments:
     p_note_item    - The note

  Output Arguments:
     r_url          - The URL 

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.

*/

extern ProError ProNoteURLWstringSet( ProNote *p_note_item,
			wchar_t *r_url );
/*

  Purpose:
     Sets the associated Uniform Resource Locator (URL), as wide string, 
     for the specified note.

  Input Arguments:
     p_note_item    - The note
     r_url	    - The URL wide string or name of the valid combined state to be activated.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully set the URL.
     PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
     PRO_TK_CANT_WRITE     - Could not modify the given item because
                             it has read-only access.

*/

extern ProError ProNoteURLWstringGet( ProNote *p_note_item,
			wchar_t  **r_url );
/*

  Purpose:
     Retrieves the Uniform Resource Locator (URL), as wide string,
     associated with the specified note.

  Input Arguments:
     p_note_item    - The note

  Output Arguments:
     r_url          - The URL wide string. Free this using ProWstringFree()

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.

*/                                                
  
extern ProError ProNoteOwnerGet( ProNote *p_note_item,
			ProModelitem *r_note_owner );

/*

  Purpose:
     Retrieves the owner of the specified note.

  Input Arguments:
     p_note_item    - The note

  Output Arguments:
     r_note_owner   - The owner of the note (feature or an annotation element).

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
 
*/

extern ProError ProNoteTextStyleSet( ProNote *p_note_item,
			ProTextStyle  text_style);

/*
  Purpose:
      Sets the text style of the specified note.

  Input Arguments:
     p_note_item    - The note.
     text_style     - The text style. Note that height and width factor
                      do not apply to three-dimensional notes.

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR  - The function successfully set the text style.
     PRO_TK_BAD_CONTEXT   - The note text style cannot be varied.
     PRO_TK_CANT_WRITE - Could not modify the given item because
                         it has read-only access.  

*/

extern ProError ProNoteTextStyleGet( ProNote *p_note_item,
			ProTextStyle *r_text_style );

/*
  Purpose:
      Retrieves the text style of the specified note.

  Input Arguments:
     p_note_item    - The note.

  Output Arguments:
     r_text_style   - The text style of the note. You must free this memory 
                      when you are done using it. 

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
*/

extern ProError ProTextStyleAlloc( ProTextStyle *r_text_style );

/*
  Purpose:
     Allocates the opaque handle for a <i>ProTextStyle</i> data structure.

  Input Arguments:
     None

  Output Arguments:
     r_text_style   - The pointer to the handle for the <i>ProTextStyle</i> 
                      structure. You should free this memory when you are 
                      done using it.

  Return Values:

     PRO_TK_NO_ERROR  - The function successfully allocated the handle.
*/

extern ProError ProTextStyleFree( ProTextStyle *p_text_style );

/*
  Purpose:
     Releases the opaque handle to the <i>ProTextStyle</i> data structure.

  Input Arguments:
     p_text_style   - The pointer to the handle for the <i>ProTextStyle</i>

  Output Arguments:
     None

  Return Values:
    
     PRO_TK_NO_ERROR  - The function successfully freed the handle.

*/

extern ProError ProTextStyleHeightSet( ProTextStyle text_style,
			double height );
/*
  Purpose:
     Sets the text style height.

  Input Arguments:
     text_style      - The text style
     height          - The height

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully set the height.
     PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
*/

extern ProError ProTextStyleHeightGet( ProTextStyle text_style,
                        double *r_height );
/* 
  Purpose:
     Retrieves the text style height.

  Input Arguments:
     text_style     - The text style.

  Output Arguments:
     r_height       - The returned height. This could be invalid if the 
                      height is the default value.

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully retrieved the information.
	 PRO_TK_GENERAL_ERROR - The text style uses the default height.
*/

extern ProError ProTextStyleHeightInModelUnitsSet (ProTextStyle text_style,
                                         ProBoolean is_height_in_model_units);
/*
    Purpose: Assigns if the text height will be in relation to the model units 
             or a fraction of the screen size.  Used for flat-to-screen 
             annotations.

    Input Arguments:
        text_style - The text style.
        is_height_in_model_units - PRO_B_TRUE if the text height is in model 
                                   units, PRO_B_FALSE if the text height is 
                                   relative to the screen size.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProTextStyleIsHeightInModelUnits (ProTextStyle text_style,
                                        ProBoolean* is_height_in_model_units);
/*
    Purpose: Obtains if the text height will be in relation to the model units 
             or a fraction of the screen size.  Used for flat-to-screen 
             annotations.  The default value is as a fraction of the screen
	     size.

    Input Arguments:
        text_style - The text style.

    Output Arguments:
        is_height_in_model_units - PRO_B_TRUE if the text height is in model 
                                   units, PRO_B_FALSE if the text height is 
                                   relative to the screen size.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_GENERAL_ERROR - The text style uses the default value.

*/

extern ProError ProTextStyleWidthSet( ProTextStyle  text_style,
                                      double        width_factor);
/*
  Purpose:
     Sets the width factor of the text style.

  Input Arguments:
     text_style      - The text style
     width_factor    - The width factor

  Output Arguments:
     None

  Return Values:
     
     PRO_TK_NO_ERROR  - The function successfully set the width factor.
     PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.

*/

extern ProError ProTextStyleWidthGet( ProTextStyle text_style,
                        double *r_width_factor );
/* 
  Purpose:
     Retrieves the width factor of the text style.

  Input Arguments:
     text_style     - The text style

  Output Arguments:
     r_width_factor - The width factor 

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully retrieved the information.
	 PRO_TK_GENERAL_ERROR - The text style uses the default width.
*/

extern ProError ProTextStyleAngleSet(   ProTextStyle  text_style,
                                        double        angle);
/*
  Purpose:
     Sets the angle of the text style.

  Input Arguments:
     text_style      - The text style
     angle           - The angle

  Output Arguments:
     None

  Return Values:
 
     PRO_TK_NO_ERROR  - The function successfully set the angle.

*/

extern ProError ProTextStyleAngleGet( ProTextStyle text_style,
                        double *r_angle );
/* 
  Purpose:
     Retrieves the angle of the text style.

  Input Arguments:
     text_style     - The text style

  Output Arguments:
     r_angle        - The angle 

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully retrieved the information.
	 PRO_TK_GENERAL_ERROR - The text style uses the default angle.
*/

extern ProError ProTextStyleSlantAngleSet( ProTextStyle text_style,
                        double slant_angle );
/*
  Purpose:
     Sets the slant angle of the text style.
     For non-ttf fonts you can set slant_angle to 20, to make the text italic.

  Input Arguments:
     text_style      - The text style
     slant_angle     - The slant angle

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully set the slant angle.
     PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.

*/

extern ProError ProTextStyleSlantAngleGet( ProTextStyle text_style,
                        double *r_slant_angle );
/* 
  Purpose:
     Retrieves the slant angle of the specified text style.

  Input Arguments:
     text_style     - The text style

  Output Arguments:
     r_slant_angle  - The slant angle 

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
	 PRO_TK_GENERAL_ERROR - The text style uses the default slant angle.
*/

extern ProError ProTextStyleThicknessSet(  ProTextStyle text_style,
                        double thickness );
/*
  Purpose:
     Sets the thickness of the text style. For non-ttf fonts it can be used
     to make text appears as Bold.

  Input Arguments:
     text_style      - The text style
     thickness       - The thickness

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR  - The function successfully set the thickness.
     PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.

*/

extern ProError ProTextStyleThicknessGet( ProTextStyle text_style,
                        double *r_thickness );
/* 
  Purpose:
     Retrieves the thickness of the specified text style.

  Input Arguments:
     text_style     - The text style.

  Output Arguments:
     r_thickness    - The thickness. This could be invalid if the 
                      thickness is the default value.

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully retrieved the information.
	 PRO_TK_GENERAL_ERROR - The text style uses the default thickness
*/

extern ProError ProTextStyleUnderlineSet( ProTextStyle text_style,
			int underline );
/*
  Purpose:
     Sets the text underlining.

  Input Arguments:
     text_style      - The text style.
     underline       - Set this to true to underline the text. 
                       Otherwise, set this to false.

  Output Arguments:
     None

  Return Values:

      PRO_TK_NO_ERROR  - The function successfully set the underlining.

*/

extern ProError ProTextStyleUnderlineGet( ProTextStyle text_style,
                        int *r_underline );
/* 
  Purpose:
     Retrieves the underlining for the specified text style.

  Input Arguments:
     text_style     - The text style

  Output Arguments:
     r_underline    - The underlining 

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully retrieved the information.
	 PRO_TK_GENERAL_ERROR - The text style uses the default underline setting.
*/

extern ProError ProTextStyleMirrorSet( ProTextStyle text_style,
                        int mirror );
/*
  Purpose:
     Sets the text mirroring.

  Input Arguments:
     text_style      - The text style.
     mirror          - Set this to true to mirror the text. Otherwise,
                       set this to false.

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully set the mirroring.

*/

extern ProError ProTextStyleMirrorGet( ProTextStyle text_style,
                        int *r_mirror );
/* 
  Purpose:
     Retrieves the mirroring for the specified text style.

  Input Arguments:
     text_style     - The text style

  Output Arguments:
     r_mirror       - The mirroring 

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully retrieved the information. 
     PRO_TK_GENERAL_ERROR - The text style uses the default mirror setting.
*/

extern ProError ProTextStyleJustificationSet (ProTextStyle text_style,
                                         ProTextHrzJustification justification);
/*
    Purpose: Assigns the justification applied to the text style.

    Input Arguments:
        text_style - The text style.
        justification - The justification.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProTextStyleJustificationGet (ProTextStyle text_style,
                                        ProTextHrzJustification* justification);
/*
    Purpose: Obtains the justification applied to the text style.

    Input Arguments:
        text_style - The text style.

    Output Arguments:
        justification - The justification.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProTextStyleColorSet (ProTextStyle text_style,
                                      ProColor* color);
/*
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleColorSetWithDef
    Purpose: Assigns The color applied to this text style.  If
             PRO_COLOR_METHOD_DEFAULT is passed, this function
             will assign PRO_COLOR_DRAWING, not default color.

    Input Arguments:
        text_style - The text style.
        color - The color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProTextStyleColorGet (ProTextStyle text_style,
                                      ProColor* color);
/*
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleColorGetWithDef
    Purpose: Obtains the color applied to this text style.  If the
             text style has default color, this function will
             return PRO_COLOR_METHOD_TYPE with an undefined color.

    Input Arguments:
        text_style - The text style.

    Output Arguments:
        color - The color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProTextStyleColorSetWithDef (ProTextStyle text_style,
                                      ProColor* color);
/*
    Purpose: Assigns The color applied to this text style.

    Input Arguments:
        text_style - The text style.
        color - The color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProTextStyleColorGetWithDef (ProTextStyle text_style,
                                      ProColor* color);
/*
    Purpose: Obtains The color applied to this text style.

    Input Arguments:
        text_style - The text style.

    Output Arguments:
        color - The color. 
                If color method is PRO_COLOR_METHOD_DEFAULT its value will be null.
                If color method is PRO_COLOR_METHOD_TYPE its value is ProColortype.
                If color method is PRO_COLOR_METHOD_RGB its value is ProColormap

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProNoteAttachAlloc( ProNoteAttach *r_note_att );

/*

  Purpose:
     Allocates the opaque handle for the <i>ProNoteAttach</i>.

  Input Arguments:
     None

  Output Arguments:
     r_note_att     - The pointer to the handle for the <i>ProNoteAttach</i>

  Return Values:
 
     PRO_TK_NO_ERROR   - The function successfully allocated the data structure.

*/

extern ProError ProNoteAttachRelease( ProNoteAttach *p_note_att );

/*
  Purpose:
     Releases the opaque <i>ProNoteAttach</i> handle.

  Input Arguments:
     p_note_att     - The pointer to the handle for the <i>ProNoteAttach</i>

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR  - The function successfully freed the memory. 

*/

extern ProError ProNoteAttachFreeSet( ProNoteAttach note_att,
			double  p1,
			double  p2,
			double  p3 );

/*

  Purpose:
     Sets the location of the note text -- 
     at a parametric point with respect to the model display outline.
     For example, (0.5, 0.5, 0.5) would be the center, whereas 
     (0.0, 0.0, 1.1) would be just outside one of the corners.
     Obtain the display outline from ProSolidDispoutlineGet().
     <P><B> Note:</B> For notes outside of annotation planes, the note
                  location is stored as relative coordinates and will update 
                  with changes to the model outline.  Notes in annotation 
                  planes are placed at fixed locations with respect to the 
                  model and will not move when the model size changes.
     <P><B> Note: </B> For notes placed on a flat-to-screen annotation plane, 
                  the coordinates should be screen coordinates instead of the 
                  parameters discussed above, and the Z entry is ignored.  

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>
     p1             - The parameter in the X direction
     p2             - The parameter in the Y direction
     p3             - The parameter in the Z direction

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully set the note text location.
 

*/

extern ProError ProNoteAttachFreeGet( ProNoteAttach note_att,
			double *r_p1,
			double *r_p2,
			double *r_p3 );

/*
  Purpose:
     Retrieves the location of the note text. 
     The attachment point is a  parametric point with respect to the 
     model display outline.  For example, (0.5, 0.5, 0.5) would be the 
     center, whereas (0.0, 0.0, 1.1) would be just outside one of the corners.
     Obtain the display outline from ProSolidDispoutlineGet().
     <P><B> Note: </B> For notes placed on a flat-to-screen annotation plane, 
                  the coordinates will be screen coordinates instead of the 
                  parameters discussed above, and the Z entry should be 
		  ignored.  

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>

  Output Arguments:
     r_p1           - The pointer to the the parameter in the X direction
     r_p2           - The parameter in the Y direction
     r_p3           - The parameter in the Z direction
 
  Return Values:
     PRO_TK_NO_ERROR        - The function successfully retrieved the 
                              information.
     PRO_TK_E_NOT_FOUND     - The note attachment does not contain a free
                              attachment.
     PRO_TK_GENERAL_ERROR   - A general error occurred and the function 
                              failed.
*/

extern ProError ProNoteAttachAddend( ProNoteAttach note_att,
			ProSelection one_end_sel,
			ProNoteAttachAttr attr );
/*

  Purpose:
     Adds a leader to the specified note.
     <B>Note:</B><P>Additional functionality is available in ProNoteAttachLeaderAdd()
     </P>

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>
     one_end_sel    - The selection for the end of the leader
     attr           - The attribute of this end attachment (normal, 
                      tangent, and so on)

  Output Arguments:
     None

  Return Values:

     PRO_TK_NO_ERROR  - The function successfully added a leader to the note.
*/

extern ProError ProNoteDtlnoteGet (ProNote    *solid_model_note,
                                   ProDrawing  drawing,
                                   ProDtlnote *dtl_note);
/*
Purpose: Return the detail note that represents a shown model note.

Input Arguments:
  solid_model_note - The solid model note.
  drawing          - The drawing where the note is displayed.

Output Arguments:
  dtl_note         - The drawing detail note that displays the model note.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_BAD_CONTEXT - The solid model is not contained in the drawing.
  PRO_TK_E_NOT_FOUND - The solid model note is not displayed in the drawing.

*/

typedef enum
{
        PRO_LEADER_STANDARD,
        PRO_LEADER_ISO
} ProLeaderStyle;

extern ProError ProNoteAttachOnitemSet (ProNoteAttach note_att,
                		        ProSelection on_item);
/*

  Purpose:  Sets a note attachment to be "On item" and assigns the item.
         This clears previous settings of leaders and location assigned
         to this note attachment structure.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>
     on_item        - The selection item for the note attachment.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully added a leader to the note.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProNoteAttachOnitemGet (ProNoteAttach note_att,
		                        ProSelection* on_item);
/*

  Purpose:  Gets a note attachment's "On item" reference.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>

  Output Arguments:
     on_item        - The selection item for the note attachment.

  Return Values:

     PRO_TK_NO_ERROR    - The function successfully added a leader to the note.
     PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - The note attachment does not contain an on item 
                          attachment.
     PRO_TK_NO_LICENSE  -  License check failure.

     PRO_TK_GENERAL_ERROR - Other error.
  
*/

extern ProError ProNoteLeaderstyleSet (ProNote *note,
                                       ProLeaderStyle type);
/*

  Purpose:  Sets the note leader style (standard or ISO).

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note       - The handle for the <i>Note</i>
     type       - The note leader type.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
     PRO_TK_BAD_CONTEXT   - The note leader style cannot be varied.
     PRO_TK_CANT_WRITE - Could not modify the given item because
                         it has read-only access.
*/
extern ProError ProNoteLeaderstyleGet (ProNote *note,
                                       ProLeaderStyle* type);
/*

  Purpose:  Gets the note leader style (standard or ISO).

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note       - The handle for the <i>Note</i>

  Output Arguments:
     type       - The note leader type.


  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProNoteAttachLeaderAdd (ProNoteAttach note_att,
					ProSelection one_end_sel,
					ProNoteAttachAttr attr,
					ProLeaderType arrow_type);
/*

  Purpose:  Adds a leader to the specified note.  This function supersedes the
            function ProNoteAttachAddend().

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>
     one_end_sel    - The selection for the end of the leader
     attr           - The attribute of this end attachment (normal,
                      tangent, and so on)
     arrow_type     - The arrow type. If the note is in the annotation plane,
                      this must be PROLEADERTYPE_ARROWHEAD type.
                      
  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
     PRO_TK_BAD_CONTEXT - Invalid leader type for this note attachment.
*/

extern ProError ProNoteAttachLeaderRemove (ProNoteAttach note_att,
					   int leader_index);
/*

  Purpose:  Removes a leader from the note attachment structure.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>
     leader_index   - The index of the leader endpoint (obtain through 
                      the endpoints array returned by 
                      ProNoteAttachLeadersGet()).
  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProNoteAttachLeadersGet (ProNoteAttach note_att,
					 ProSelection** endpoints,
   					 ProNoteAttachAttr** attrs,
					 ProLeaderType** arrow_types);
/*

  Purpose:  Retrieves the leaders for the specified note.
  <p><b>Note:</b>Requires the owner of the note to be displayed.          

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>


  Output Arguments:
     endpoints      - ProArray of leader endpoints.  Free this array using 
                      ProSelectionarrayFree().  Pass NULL if not interested in
		      this value.
     attrs          - ProArray of attachment attributes for each endpoint.
                      Free this array using ProArrayFree(). Pass NULL if not
                      interested in this value.
     arrow_types    - ProArray of arrow types for each endpoint.
                      Free this array using ProArrayFree(). Pass NULL if not
                      interested in this value.

  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more inputs was invalid.
     PRO_TK_E_NOT_FOUND - The note attachment structure does not have any 
                          leader endpoints.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProNoteAttachPlaneSet (ProNoteAttach note_att,
                                       ProAnnotationPlane *annotation_plane);

/*

  Purpose:  Sets the note annotation plane.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>
     annotation_plane - The annotation plane.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProNoteAttachPlaneGet (ProNoteAttach note_att,
                                       ProAnnotationPlane* annotation_plane);
/*

  Purpose:  Gets the note annotation plane.

  Licensing Requirement:
          TOOLKIT for 3D Drawings

  Input Arguments:
     note_att       - The handle for the <i>ProNoteAttach</i>

  Output Arguments:
     annotation_plane - The annotation plane.


  Return Values:
     PRO_TK_NO_ERROR  - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProNoteElbowlengthSet (ProNote* note,
                                       double elbow_length,
                                       ProVector elbow_direction);
/*
    Purpose: Assigns the elbow properties of the note.  This is equivalent to
             the 'Move Text' command.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The note.
        elbow_length - The elbow length, in model units (for notes in annotation
                       planes), or in screen coordinates (for notes that are
                       flat-to-screen).
        elbow_direction - The elbow direction, in the model's coordinate
                          system (for notes in annotation planes), or in the
                          screen coordinate system  (for notes that are
                          flat-to-screen).   This is the
                          direction from the note text to the note leaders.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_MATRIX - Invalid direction vector supplied for this
                                notes elbow.
        PRO_TK_BAD_CONTEXT   - The note elbow length cannot be varied.
        PRO_TK_CANT_WRITE - Could not modify the given item because
                            it has read-only access.
*/

extern ProError ProNoteElbowlengthGet (ProNote* note,
                                       double* elbow_length,
                                       ProVector elbow_direction);
/*
    Purpose: Obtains the elbow properties of the note.
<p><b>Note:</b>
    This function only supports notes which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The note.

    Output Arguments:
        elbow_length - The elbow length, in model units (for notes in
                       annotation planes).  This value will be in screen
                       coordinates (for flat-to-screen notes).
        elbow_direction - The elbow direction, in the model's coordinate
                          system, ), or in the screen coordinate system  (for
                          notes that are flat-to-screen).  This is the
                          direction from the note text to the note leaders.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The note is not placed, or does not use leaders.
        PRO_TK_CANT_ACCESS -  The note uses the default elbow length (this is
                              possible for flat-to-screen notes only).
*/

extern ProError ProNoteLineEnvelopeGet (ProNote* note,
                                        int line_number,
                                        ProLineEnvelope envelope);
/*
    Purpose: Get the envelope of a line in a specified note.
<p><b>Note:</b>
    This function only supports notes which are placed on an annotation plane.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        note - The note.
        line_number - The line number of the note.

    Output Arguments:
        envelope - The envelope surrounding the text line, in the model's
                   coordinate system.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The indicated line does not exist.
*/

extern ProError ProNoteAttachNormtanleaderGet (ProNoteAttach note_attach,
                                               ProNoteAttachAttr* leader_type,
                                               double* length,
                                               ProVector direction);
/*
  Purpose: Extracts the properties of a normal/tangent leadered note.

  Input Arguments:

      note_attach - The note attachment structure.

  Output Arguments:

      leader_type - The leader type.
      length      - The nominal length of the leader line, in the coordinates
                    of the note owner model. Note that depending on the 
                    orientation of the model, this length may not reflect the
                    perceived length of the leader on the screen. Pass NULL
                    if not interested in this information.
      direction   - The nominal direction of the leader line, from the
                    attachement point to the note text. This is in the
                    coordinates of the note owner model. Note that depending
                    on the orientation of the model, this direction may not
                    reflect the perceived direction of the leader on the 
                    screen. Pass NULL if not interested in this information.

  Return Values:

      PRO_TK_NO_ERROR     - The function succeeded.
      PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
      PRO_TK_INVALID_TYPE - This note is not a directed (normal or tangent)
                            leader type note or is in an annotaton plane.
*/ 





extern ProError ProTextStyleValidate( ProTextStyleObjectType obj_type ,ProTextStyle r_text_style,wchar_t*** error_message_lines );

/*
  Purpose:
     Validates text style properties for specified object type

  Input Arguments:
     obj_type - Type of the object on which text style will be applied
     r_text_style - Text Style to be applied

  Output Arguments:
     error_message_lines   - Array of lines of messages. Each line tells about
                        an attribute not applicable on the object type
                        You should free this memory using ProWstringArrayFree()

  Return Values:

     PRO_TK_NO_ERROR  - The function successfully perform necessary checks.
     PRO_TK_BAD_INPUTS -  One or more input arguments are NULL or invalid.
*/


extern ProError ProTextStyleFontSet( ProTextStyle text_style, wchar_t* font);
/*
  Purpose:
     Sets the font of the text. For ttf fonts, we have seperate fonts 
     for italic/bold. Use proper font to set text as italic or Bold.

  Input Arguments:
     text_style      - The text style
     font           -  Name of the font.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully set the font.
     PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
*/

extern ProError ProTextStyleFontGet( ProTextStyle text_style, wchar_t** font);
/*
  Purpose:
     Gets the font of the text. 

  Input Arguments:
     text_style      - The text style     

  Output Arguments:
      font       -  Name of the font. Free this using ProWstringFree()
  

  Return Values:
     PRO_TK_NO_ERROR  - The function successfully got the font.
     PRO_TK_GENERAL_ERROR - The text style has a mixed state for the font.
     PRO_TK_E_NOT_FOUND - The text style uses the default font setting.
     PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
*/



PRO_END_C_DECLS



#endif /* PRONOTE_H */

