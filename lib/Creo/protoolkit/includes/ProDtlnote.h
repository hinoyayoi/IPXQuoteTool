#ifndef PRODTLNOTE_H
#define PRODTLNOTE_H
			

#include <ProANSI.h>
#include <ProObjects.h> 
#include <ProDtlitem.h>
#include <ProDtlattach.h>
#include <ProDtlsymdef.h>
#include <ProDimension.h>
#include <ProGtol.h>
#include <ProNote.h>

typedef struct prodtl_text      *ProDtlnotetext;

typedef struct prodtl_text_line *ProDtlnoteline;

typedef struct pro_notedata     *ProDtlnotedata;

typedef enum horizontal_just
{
    PRO_HORZJUST_LEFT,
    PRO_HORZJUST_CENTER,
    PRO_HORZJUST_RIGHT,
    PRO_HORZJUST_DEFAULT  /* Indicates note with Creo Parametric default justification. */
}   ProHorizontalJustification;

typedef enum vertical_just
{
    PRO_VERTJUST_TOP,
    PRO_VERTJUST_MIDDLE,
    PRO_VERTJUST_BOTTOM,
    PRO_VERTJUST_DEFAULT  /* Indicates note with Creo Parametric default justification. */
} ProVerticalJustification;

PRO_BEGIN_C_DECLS
/*================================================================*\
    ProDtlnote  functions
\*=================================================================*/
extern ProError ProDrawingReadonlyselectionAllow(
    ProBoolean allow);
/*


  Purpose: Enables or disables the Creo Parametric user to select drawing 
           detail notes flagged as read-only.

  Input Arguments:

    allow       - Set to PRO_B_TRUE to enable selection, and PRO_B_FALSE
                  to disable it.

  Output Arguments:

    None

  Return Values:

    PRO_TK_NO_ERROR     - The function successfully set the flag.

*/

extern ProError ProDtlnoteCreate(ProMdl  owner,
                                 ProDtlsymdef *symbol,
                                 ProDtlnotedata notedata,
                                 ProDtlnote *note);
/*


  Purpose: Creates a note.

  Input Arguments:
    owner               - The owner handle.
    symbol              - If you are adding a note to the drawing, set the 
                          symbol to NULL. If you are adding a note to a
                          symbol definition, set the symbol to be that
                          symbol definition.
    notedata            - The note data.
  
  Output Arguments:

    note                - Created note.

  Return Values:

    PRO_TK_NO_ERROR      - The function successfully created the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The note could not be created.

*/

extern ProError ProDtlnoteDataGet(
    ProDtlnote *note,
    ProDtlsymdef *symbol,
    ProDisplayMode mode,
    ProDtlnotedata *notedata);
/*


  Purpose: Gets a note data for the specified note. The function allocates
           memory; user must release this memory with ProDtlnotedataFree

  Input Arguments:

    note                - The note.
    symbol              - If you are getting a note from the drawing, set the 
                          symbol to NULL. If you are getting a note from a
                          symbol definition, set the symbol to be that
                          symbol definition.
    mode                - The display mode. 
                          <p><b>Note:</b>Creo Parametric does not resolve and replace
                          symbolic callouts for notes, which are not displayed.
                          Therefore, for the value PRODISPMODE_NUMERIC, if the note is
                          not displayed or is hidden in a layer, the text retrieved may
                          contain the symbolic callouts. 
  
  Output Arguments:

    notedata            - The note data. Free the data using ProDtlnotedataFree.
  
  Return Values:

    PRO_TK_NO_ERROR      - The function successfully retrieved the note data.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.

*/

extern ProError ProDtlnoteDelete(
    ProDtlnote *note,
    ProDtlsymdef *symbol); 
/*


  Purpose: Deletes a note.

  Input Arguments:

    note                - The note.
    symbol              - If you are deleting a note from the drawing, set the 
                          symbol to NULL. If you are deleting a note from a
                          symbol definition, set the symbol to be that
                          symbol definition.
    
  Output Arguments:

    None
  
  Return Values:

    PRO_TK_NO_ERROR      - The function successfully deleted the note data.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The note could not be deleted.

*/

extern ProError ProDtlnoteModify(
    ProDtlnote *note,
    ProDtlsymdef *symbol,
    ProDtlnotedata notedata);
/*


  Purpose: Modifies a note.

  Input Arguments:

    note                - The note.
    symbol              - If you are modifying a note from the drawing, 
                          set the 
                          symbol to NULL. If you are modifying a note from a
                          symbol definition, set the symbol to be that
                          symbol definition.
    notedata            - The note data.

  Output Arguments:

    None
  
  Return Values:

    PRO_TK_NO_ERROR      - The function successfully modified the note data.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't modify the note.

*/

extern ProError ProDtlnoteDraw(
    ProDtlnote *note);
/*

Purpose: Draw a note. Make note in the database appear 
        on the drawing until the drawing is regenerated. 
	<B>NOTE: </B> The drawing must be current to use 
	this function
        

Input Arguments:

    note                - The note.
    

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully draw the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't draw the note.

*/ 

extern ProError ProDtlnoteErase(
    ProDtlnote *note);
/*

Purpose: Erase a note. Makes the note disappear 
        on the drawing until the drawing is regenerated. 
	<B>NOTE: </B> The drawing must be current to use 
	this function

Input Arguments:

    note                - The note.
    

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully erased the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't erase the note.

*/ 

extern ProError ProDtlnoteShow(
    ProDtlnote *note);
/*

Purpose: Show a note. Make note in the database appear 
        on the drawing and continue to appear after the 
	drawing is regenerated. 
        <B>NOTE: </B> The drawing must be current to use 
	this function; to set a note to be displayed in a non-current
	drawing using ProDtlnotedataDisplayedSet() and regenerate 
	the drawing. 

Input Arguments:

    note                 - The note.

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully show the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't show the note.

*/ 

extern ProError ProDtlnoteRemove(
    ProDtlnote *note);
/*

Purpose: Remove a note. Make note in the database 
        disappear on the drawing and continue to disappear after the 
        drawing is regenerated.  	
	<B>NOTE: </B> The drawing must be current to use 
	this function; to set a note to be undisplayed in a non-current
	drawing using ProDtlnotedataDisplayedSet() and regenerate 
	the drawing.

Input Arguments:

    note                 - The note.

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully removed the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't remove the note.

*/ 

extern ProError ProDrawingDtlnotesCollect(
    ProDrawing drawing,
    ProDtlsymdef *symbol, 
    int sheet,
    ProDtlnote **notes); 
/*

Purpose: Collect notes in the specified drawing.

Input Arguments:

    drawing     - The drawing handle.
    symbol      - If you are collecting a note from the drawing, set the 
                  symbol to NULL. If you are collecting a note from a
                  symbol definition, set the symbol to be that
                  symbol definition.
    sheet       - The sheet number. Set to PRO_VALUE_UNUSED for current sheet.

Output Arguments:

    notes       - The ProArray of notes. The function  allocates memory for
                  array. User must release memory by ProArrayFree.
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully collected the notes.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_OUT_OF_MEMORY - The function found too many entities to be contained in the output ProArray.  Use ProDrawingDtlnoteVisit instead.
    PRO_TK_E_NOT_FOUND   - No notes were found.
    
*/ 

extern ProError ProDrawingDtlnoteVisit(
    ProDrawing drawing,
    ProDtlsymdef *symbol,
    int sheet,
    ProDtlitemVisitAction visit_action,
    ProDtlitemFilterAction filter_action,
    ProAppData appdata);
/*

Purpose: Visit notes in the specified drawing.

Input Arguments:

    drawing         - The drawing handle.
    symbol          - If you are visiting a note in the drawing, set the 
                      symbol to NULL. If you are visiting a note in a
                      symbol definition, set the symbol to be that
                      symbol definition.
    visit_action    - Visit action function.
    filter_action   - Filter action function. If NULL, all notes are  
                      visited using the action function. 
    sheet           - The sheet number.
    appdata         - The application data.

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully visited the notes.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No notes were found.
    Other                - Return value passed by the caller's visit function.          
*/ 

extern ProError ProDtlnoteModelrefGet( ProDtlnote    *note,
                                       ProDtlsyminst *symbol_inst,
                                       int           line_index,
                                       int           text_index,
                                       ProMdl        *model );
/*
  Purpose:
  To provide the model to which parameterized text in a detail note refers.

  Input Arguments:
      note        - The note
      symbol_inst - Symbol instance whose definition contains the note.
                    Set to NULL if the note does not belong to a symbol.
      line_index  - The index into the note's line array of the line
                    containing the parameterized text.
      text_index  - The index into the line's text array of the text  item
                    containing the parameterized text.
 
  Output Arguments:
     model	  - The model which contains the parameters the
                    parameterized text refers to.

  Return Values:
       PRO_TK_NO_ERROR   - The function successfully found the model.
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


extern ProError ProDtlnoteNoteGet (ProDtlnote *dtl_note, 
                                   ProNote*    solid_model_note);

/*
Purpose: Return the solid model note that shown as a detail note.

Input Arguments:
  dtl_note         - The drawing detail note that displays the model note.

Output Arguments:
  solid_model_note - The solid model note.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - The input argument is invalid.
  PRO_TK_E_NOT_FOUND - The detail note does not show a solid model note.
*/

extern ProError ProDtlnoteGtolGet (ProDtlnote *dtl_note , ProGtol *gtol);

/*
Purpose: Return the geometric tolerance shown in a detail note.

Input Arguments:
  dtl_note - The drawing detail note that displays the model note.

Output Arguments:
  gtol     - The geometric tolerance handle.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_E_NOT_FOUND - The note is not showing a geometric tolerance.
*/


/*================================================================*\
    ProDtlnotedata  functions
\*=================================================================*/
extern ProError ProDtlnotedataAlloc(ProMdl owner,
                                    ProDtlnotedata *notedata);
/*

Purpose: Allocate and initialize memory for note data.
        User must release memory by ProDtlnotedataFree.

Input Arguments:
    owner           - The owner model of the note
    
Output Arguments:
    notedata        - The note data.
        
Return Values:
    PRO_TK_NO_ERROR         - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
*/ 

extern ProError ProDtlnotedataFree(
    ProDtlnotedata notedata);
/*

Purpose: Release memory allocated by ProDtlnotedataAlloc.
        (Also frees text lines, texts and leaders)

Input Arguments:
    notedata                - The note data.
    
Output Arguments:

    None
        
Return Values:
    PRO_TK_NO_ERROR         - The function successfully release memory.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/

extern ProError ProDtlnotedataIdGet(
    ProDtlnotedata notedata,
    int *id);
/*

Purpose: Gets a note id.

Input Arguments:
    notedata                - The note data.
    
Output Arguments:
    id                      - The note id.
       
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the note id.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataLineAdd(
    ProDtlnotedata notedata,
    ProDtlnoteline line);
/*

Purpose: Adds a text line to note.

Input Arguments:
    notedata                - The note data.
    line                    - The text line.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully added the text line.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnoteldataLinesSet(
    ProDtlnotedata notedata,
    ProDtlnoteline *line); 
/*

Purpose: Sets text lines to note.

Input Arguments:
    notedata                - The note data.
    line                    - ProArray of the text lines.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the text lines.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataLinesCollect(
    ProDtlnotedata notedata,
    ProDtlnoteline **lines);
/*

Purpose: Collect text lines in the specified note.

Input Arguments:
    notedata    - The note data.
    
Output Arguments:
    lines       - The ProArray of text lines. The function allocates memory for 
                  the array. User must release memory by ProArrayFree.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the text lines.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    PRO_TK_E_NOT_FOUND   - No text lines were found.
    
*/ 

extern ProError ProDtlnotedataMirrorSet(
    ProDtlnotedata notedata,
    ProBoolean mirror);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProTextStyleMirrorSet
Purpose: <b>Note:</b> This function is deprecated
         Use ProTextStyleMirrorSet instead.

         Sets a mirror flag for the specified note.

Input Arguments:
    notedata                - The note data.
    mirror                  - The mirror flag.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the mirror flag.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataIsMirrored(
    ProDtlnotedata data,
    ProBoolean *mirrored);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProTextStyleMirrorGet
Purpose: <b>Note:</b> This function is deprecated
         Use ProTextStyleMirrorGet instead.

         Gets a mirror flag for the specified note.

Input Arguments:
    data                - The note data.
    
Output Arguments:
    mirrored                - The mirror flag.
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully retrieved the mirror 
                              flag.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataColorGet(
    ProDtlnotedata notedata,
    ProColor *color);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProTextStyleColorGetWithDef()
Purpose: <b>Note:</b> This function is deprecated
         Use ProTextStyleColorGetWithDef() instead.

         Gets a color for the specified note.

Input Arguments:
    notedata                - The note data.
    
Output Arguments:
    color                   - The note color.
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully retrieved the note
                              color.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataColorSet(
    ProDtlnotedata notedata,
    ProColor *color);
/*

DEPRECATED: Since Creo 4.0
SUCCESSORS: ProTextStyleColorSet
Purpose: <b>Note:</b> This function is deprecated
         Use ProTextStyleColorSet instead.

         Sets a color for the specified note.

Input Arguments:
    notedata                - The note data.
    color                   - The note color.
    
Output Arguments:
    Note
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the note
                                color.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataAttachmentGet(
    ProDtlnotedata notedata,
    ProDtlattach *attachment);
/*

Purpose: Gets an attachment for the specified note.

Input Arguments:
    notedata                - The note data.
    
Output Arguments:
    attachment              - The note attachment. Release memory using 
                                ProDtlattachFree
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully retrieved the note
                                attachment.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataAttachmentSet(
    ProDtlnotedata notedata,
    ProDtlattach attachment);
/*

Purpose: Sets an attachment for the specified note.

Input Arguments:
    notedata                - The note data
    attachment              - The note color
    
Output Arguments:
    None 
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the note
                              attachment.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataLeadersCollect(
    ProDtlnotedata notedata,
    ProDtlattach **leaders); 
/*

Purpose: Collect leaders in the specified note.

Input Arguments:
    notedata        - The note data.
    
Output Arguments:
    leaders         - The ProArray of leaders. The function allocates memory 
                      for the array. User must release memory by ProArrayFree.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the leaders.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    PRO_TK_E_NOT_FOUND   - No leaders were found.
    
*/ 

extern ProError ProDtlnotedataLeadersSet(
    ProDtlnotedata notedata,
    ProDtlattach *leaders); 
/*

Purpose: Sets leaders for the note.

Input Arguments:
    notedata                - The note data.
    leaders                 - The ProArray of leaders.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the leaders.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataLeaderAdd(
    ProDtlnotedata data,
    ProDtlattach leader);
/*

Purpose: Adds a leader to the note.

Input Arguments:
    data                - The note data.
    leader              - The note leader.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully added the leader.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataElbowlengthGet(
    ProDtlnotedata  data,
    ProBoolean	*is_default,
    double *elbow_length);
/*

Purpose: Gets the elbow length for the specified note.

Input Arguments:
    data                - The note data.
    
Output Arguments:
    is_default          - The default flag. 
    elbow_length        - The note elbow length if is_default == PRO_B_FALSE.
     
Return Values:
    PRO_TK_NO_ERROR     - The function successfully retrieved the note
                          elbow.
    PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataElbowlengthSet(
    ProDtlnotedata data,
    ProBoolean	is_default,
    double elbow_length);
/*

Purpose: Sets the elbow length for the specified note.

Input Arguments:
    data                - The note data.
    is_default          - The default flag. 
    elbow_length        - The note elbow length if is_default == PRO_B_FALSE.
    
Output Arguments:
    None
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the note
                              elbow.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataAngleGet(
    ProDtlnotedata notedata,
    double *angle);
/*
DEPRECATED: Since Creo 4.0
SUCCESSORS: ProTextStyleAngleGet
Purpose: <b>Note:</b> This function is deprecated
         Use ProTextStyleAngleGet instead.

         Gets an angle for the specified note.

Input Arguments:
    notedata                - The note data.
    
Output Arguments:
    angle                   - The note angle.
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully retrieved the note
                              angle.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataAngleSet(
    ProDtlnotedata notedata,
    double angle);
/*

DEPRECATED: Since Creo 4.0
SUCCESSORS: ProTextStyleAngleSet
Purpose: <b>Note:</b> This function is deprecated
         Use ProTextStyleAngleSet instead.

         Sets an angle for the specified note.

Input Arguments:
    notedata                - The note data.
    angle                   - The note angle. 
    
Output Arguments:
    None
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the note
                              angle.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

/*================================================================*\
    ProDtlnotetext  functions
\*=================================================================*/
extern ProError ProDtlnotetextAlloc  (
    ProDtlnotetext *text );

/*  
    Purpose: 
	Allocate memory for the note text data.
	User must free memory with ProDtlnotetextFree().
	
    Input Arguments:
	None

    Output Arguments:
	text  - The note data handle

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_OUT_OF_MEMORY - The function can't allocate memory
*/


extern ProError ProDtlnotetextFree(
    ProDtlnotetext text);

/*  
    Purpose: 
	Free memory that is allocated by ProDtlnotetextAlloc.
	
    Input Arguments:
        text  - The note data handle. 
         
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextHeightSet (
    ProDtlnotetext text,
    double height);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleHeightSet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleHeightSet instead.
 
	     Setup the text height, in screen units.
	
    Input Arguments:
	text   - The handle to the text
	height - Height in world coordinates.
        
    Output Arguments:
	None
        
    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument(s) is invalid.
*/

extern ProError ProDtlnotetextHeightGet (
    ProDtlnotetext text,
    double *height);

/* 
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleHeightGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleHeightGet instead. 

	     Get the text height, in screen units.
	
    Input Arguments:
	text   - The handle to the text

    Output Arguments:
	height - Height in world coordinates.

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextWidthSet (
    ProDtlnotetext text,
    double width_factor);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleWidthSet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleWidthSet instead.

	    Setup the text width_factor.
	
    Input Arguments:
	text         - The handle to the text
	width_factor - The ratio between the width and height of each
		       character in the string. More correctly, this is 
		       the area each character occupies, including the 
		       space between them and the next character.
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextWidthGet (
    ProDtlnotetext text,
    double *width_factor);

/*
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleWidthGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleWidthGet instead.

	     Get the text width_factor.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	width_factor - The ratio between the width and height of each
		       character in the string. More correctly, this is 
		       the area each character occupies, including the 
		       space between them and the next character.

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextSlantSet (
    ProDtlnotetext text,
    double slant_angle);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleSlantAngleSet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleSlantAngleSet instead.

	     Setup the text slant_angle.
	
    Input Arguments:
	text         - The handle to the text
	slant_angle  - The lean of the character, in 
		       degrees clockwise

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextSlantGet (
    ProDtlnotetext text,
    double *slant_angle);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleSlantAngleGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleSlantAngleGet instead.

	     Get the text slant_angle.
	
    Input Arguments:
	text              - The handle to the text

    Output Arguments:
	slant_angle       - The lean of the character, in 
		            degrees clockwise

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextThicknessSet (
    ProDtlnotetext text,
    double thickness);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleThicknessSet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleThicknessSet instead.

	     Setup the text thickness.
	
    Input Arguments:
	text         - The handle to the text
	thickness    - The line thickness in screen coordinates. 
		       If the value is set to -1.0, this parameter is
                       controlled by the drawing setup file.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextThicknessGet (
    ProDtlnotetext text,
    double *thickness);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleThicknessGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleThicknessGet instead.

	     Get the text thickness.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	thickness    - The line thickness in screen coordinates. 
		       If the value is set to -1.0, this parameter
                       is controlled by the drawing setup file.  

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextFontSet (
    ProDtlnotetext text,
    ProName font);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleFontSet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleFontSet instead.

	     Setup the text font.
	
    Input Arguments:
	text         - The handle to the text
	font         - The text font

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextFontGet (
    ProDtlnotetext text,
    ProName font);

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleFontGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleFontGet instead.

	     Get the text font.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	font         - The text font

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextUlineSet (
    ProDtlnotetext text,
    ProBoolean underline);

/*  
    Purpose: 
	Setup the text underline attribute.
	
    Input Arguments:
	text         - The handle to the text
	underline    - The underline attribute.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextUlineGet (
    ProDtlnotetext text,
    ProBoolean *underline);

/*  
    Purpose: 
	Get the text underline attribute.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	underline    - The underline attribute.

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextStringSet (
    ProDtlnotetext text,
    ProLine string);

/*  
    Purpose: 
	Setup the string field in the text.
	
    Input Arguments:
	text         - The handle to the text
	string       - The content of the text part.
		       It can contain control characters
		       to introduce special symbols, as
		       described in the Drawing User's Guide.
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextStringGet (
    ProDtlnotetext text,
    ProLine string);

/* 
    Purpose: 
	Get the string field from the text.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	string       - The content of the text part.
		       It can contain control characters
		       to introduce special symbols, as
		       described in the Drawing User's Guide.

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

/*================================================================*\
    ProDtlnoteline  functions
\*=================================================================*/
extern ProError ProDtlnotelineAlloc (
    ProDtlnoteline *line);

/* 
    Purpose: 
	Allocate memory for the note text line data.
	User must free memory by ProDtlnotelineFree()
	
    Input Arguments:
	None

    Output Arguments:
	line  - The note text line handle.  

    Return Values:
	PRO_TK_NO_ERROR      - Success;
	PRO_TK_OUT_OF_MEMORY - The  function can't allocate memory.
*/

extern ProError ProDtlnotelineFree (
    ProDtlnoteline line);

/*  
    Purpose: 
	Free memory that was allocated by ProDtlnotelineAlloc.
	
    Input Arguments:
        line  - The note text line handle.  
        
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotelineTextAdd (
    ProDtlnoteline line,
    ProDtlnotetext text);

/*  
    Purpose: 
	Add text to the note text line data.
	
    Input Arguments:
        line  - The note text line handle. 
	text  - The handle to the text.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
	PRO_TK_OUT_OF_MEMORY    - Not enough memory.
*/

extern ProError ProDtlnotelineTextsSet (
    ProDtlnoteline line,
    ProDtlnotetext *texts);

/*  
    Purpose: 
	Setup the text for the note text line data.
	
    Input Arguments:
	line    - The note text line handle. 
	texts   - A ProArray of of text handles.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
        PRO_TK_OUT_OF_MEMORY    - Not enough memory.
*/


extern ProError ProDtlnotelineTextsCollect (
    ProDtlnoteline line,
    ProDtlnotetext **text);

/*  
    Purpose:  Returns text entities contained in the note line. Each text 
              entity can have its own properties and parametric references.
       

    Input Arguments:

        line  - Line in note returned by function ProDtlnotedataLinesCollect().

    Output Arguments:

        text  - ProArray of text entities. Free the array memory with 
                ProArayFree(). 

    Return Values:
        PRO_TK_NO_ERROR         - Function completed successfully
        PRO_TK_BAD_INPUTS       - One or more bad arguments
        Pro_E_TK_NOT_FOUND      - No text entities in specified line
*/



extern ProError ProDtlnotedataJustifSet(
    ProDtlnotedata notedata,
    ProHorizontalJustification hjust,
    ProVerticalJustification   vjust );

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleJustificationSet, ProTextStyleVertJustificationSet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleJustificationSet and
                 ProTextStyleVertJustificationSet instead.

             Sets justification for the specified note.

    Input Arguments:
        notedata	- The note data.
	hjust		- Horizontal justification value.
	vjust		- Vertical justification value.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
*/

extern ProError ProDtlnotedataJustifGet(
    ProDtlnotedata notedata,
    ProHorizontalJustification *hjust,
    ProVerticalJustification   *vjust );

/*  
    DEPRECATED: Since Creo 4.0
    SUCCESSORS: ProTextStyleJustificationGet, ProTextStyleVertJustificationGet
    Purpose: <b>Note:</b> This function is deprecated
             Use ProTextStyleJustificationGet and 
		 ProTextStyleVertJustificationGet instead.

             Gets note justification values.

    Input Arguments:
        notedata	- The note data.

    Output Arguments:
	hjust		- Horizontal justification value.
	vjust		- Vertical justification value.

    Return Values:
        PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
	PRO_TK_GENERAL_ERROR	- Error getting justification value.
*/

extern ProError ProDtlnotedataReadonlySet(
    ProDtlnotedata notedata,
    ProBoolean read_only );

/*  
    Purpose:
        Sets read-only flag for the specified note.

    Input Arguments:
        notedata	- The note data.
	read_only	- PRO_B_TRUE to make note read-only, 
			  PRO_B_FALSE otherwise

    Output Arguments:
	None

    Return Values:
        PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
*/

extern ProError ProDtlnotedataReadonlyGet(
    ProDtlnotedata notedata,
    ProBoolean *read_only );

/*  
    Purpose:
        Gets read-only flag for the specified note.

    Input Arguments:
        notedata	- The note data.

    Output Arguments:
	read_only	- PRO_B_TRUE if note is read-only, 
			  PRO_B_FALSE otherwise

    Return Values:
        PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
*/

extern ProError ProDtlnoteLineEnvelopeGet(
    ProDtlnote *note,
    int line,
    ProVector envel[4]);

/*  
    Purpose:
        Get the envelope of a line in specified note.

    Input Arguments:
        note  	        - The note.
        line            - The line number, counting from 0.

    Output Arguments:
        envel           - The envelope, in screen coordinates.
                          The order of coordinates are as:<pre><br>
                          
                          0 -------- 1<br>
                          |          |<br>
                          2 -------- 3</pre>
                      
                          This ordering of points is preserved even if
                          the note is mirrored and/or at an angle.

    Return Values:
        PRO_TK_NO_ERROR   - Success.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.  
		PRO_TK_EMPTY      - The note is a blank string.  
*/

extern ProError ProDtlnotedataIsDisplayed(
    ProDtlnotedata data,
    ProBoolean *is_displayed);

/*
   Purpose:   Checks if the draft note is displayed.

   Input Arguments:
      data              - The draft note data.

   Output Arguments:
      is_displayed      - PRO_B_TRUE if the note is displayed by default.
                          PRO_B_FALSE if the note is hidden by default.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlnotedataDisplayedSet(
    ProDtlnotedata data,
    ProBoolean displayed);

/*
   Purpose:   Marks the draft entity to be displayed

   Input Arguments:
      data                 - The draft note data.
      displayed            - PRO_B_TRUE if the draft note should be displayed
                             after every regeneration.  PRO_B_FALSE 
			     if it should be undisplayed after every 
			     regeneration.

   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlnoteDtlsyminstsCollect (
    ProDtlnote* note, 
    ProDtlsyminst** instances);
/*
   Purpose:   Returns a list of all symbol instances which are declared in a
              detail note via the "sym()" callout format.
              <P><B> Note: </B> The instances are returned in the order they are
              encountered in the note text.

   Input Arguments:
      note                 - The detail note.

   Output Arguments:
      instances            - ProArray of symbol instances. 
                             Free this using ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR      - The function succeeded.
      PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND   - There are no symbol instances generated as a
                             callout in this note.

*/


extern ProError  ProDtlnotetextStyleSet( ProDtlnotetext note_text,
                                         ProTextStyle r_text_style );

/*
  Purpose:
      Retrieves the text style of the specified text in the note

  Input Arguments:
     note_text    - The note text.
     r_text_style   - The text style of specified text in the note. 

  Output Arguments:
     none

  Return Values:

     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.  

*/

extern ProError  ProDtlnotetextStyleGet( ProDtlnotetext note_text,
                                         ProTextStyle *r_text_style );

/*
  Purpose:
      Retrieves the text style of the specified text in the note

  Input Arguments:
     note_text    - The note text.

  Output Arguments:
     r_text_style   - The text style of specified text in the note. You must free this memory 
                      when you are done using it. 

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.  

*/

extern ProError  ProDtlnotedataTextStyleSet(ProDtlnotedata  note_data,
                                            ProTextStyle r_text_style );

/*
  Purpose:
      Set text style in the note_data.

  Input Arguments:
     note_data    - The note data.
     r_text_style   - The text style of the note. 

  Output Arguments:

    None
        
  Return Values:

     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.  

*/

extern ProError  ProDtlnotedataTextStyleGet (ProDtlnotedata note_data,
                                             ProTextStyle *r_text_style);

/*
  Purpose:
        Retrieves the text style of the note. If the note has texts with
        different styles, the returned style will have a mixed state for
        attributes that aren't the same in all texts. Inquiry functions
        such as ProTextStyleFontGet will return PRO_TK_GENERAL_ERROR when
        the attribute is in a mixed state.

  Input Arguments:
     note_data    - The note data.

  Output Arguments:
     r_text_style   - The text style of the note. You must free this memory
                      when you are done using it.

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.

*/


extern ProError ProTextStyleVertJustificationSet (ProTextStyle text_style,
                                         ProVerticalJustification justification);

/*
    Purpose: Assigns the vertical justification applied to the text style.

    Input Arguments:
        text_style - The text style.
        justification - The justification.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProTextStyleVertJustificationGet (ProTextStyle text_style,
                                        ProVerticalJustification* justification);
/*
    Purpose: Obtains the vertical justification applied to the text style.

    Input Arguments:
        text_style - The text style.

    Output Arguments:
        justification - The justification.

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/




PRO_END_C_DECLS

#endif /* PRODTLNOTE_H */

