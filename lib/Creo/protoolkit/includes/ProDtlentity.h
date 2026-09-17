#ifndef PRODTLENTITY_H
#define PRODTLENTITY_H
			


#include <ProDtlitem.h>
#include <ProDtlattach.h>
#include <ProDtlsymdef.h>
#include <ProCurvedata.h>
#include <ProView.h>
#include <ProANSI.h>

PRO_BEGIN_C_DECLS
/*================================================================*\
    ProDtlentity  functions
\*================================================================*/
extern ProError ProDtlentityCreate (
    ProMdl owner,
    ProDtlsymdef *symbol, 
    ProDtlentitydata entdata,
    ProDtlentity *entity);
/*
   Purpose:  Creates a detail item (draft entity) in the Creo Parametric drawing.
             <p><b>Note : </b>The function cannot access symbol definitions
             for special symbols, such as, datum targets or parametric
             connector symbols.
                
   Input Arguments:
      owner        -  The owner model handle.
      symbol       -  If you are adding a detail item to the
                      owner, set this argument to NULL. If you 
                      are adding  draft entity to a symbol definition,
                      set this argument to be that symbol definition.
      entdata      -  The draft entity data.
       
   Output Arguments:
      entity       -  The entity handle.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProDtlentityDataGet (
    ProDtlentity *entity,
    ProDtlsymdef *symbol, 
    ProDtlentitydata *entdata);
/*
   Purpose:     Provides a full description of a specified detail item.
                <p><b>Note : </b>The function cannot access symbol
                definitions for special symbols, such as, datum targets
                or parametric connector symbols.
                
   Input Arguments:
      entity      - The drawing.
      symbol       - If you are examining a detail item in the
                     drawing, set the parent to NULL. If you are
                     examining draft entity in a symbol definition,
                     set the parent to be that symbol definition.

   Output Arguments:
      entdata      - The data structure that contains the item.
                     Free the data using ProDtlentitydataFree.   

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProDtlentityDelete (
    ProDtlentity *entity,
    ProDtlsymdef *symbol); 
/*
   Purpose:  Permanently deletes the specified detail item from the 
             Creo Parametric database.   
             <p><b>Note : </b>The function cannot access symbol definitions
             for special symbols, such as, datum targets or parametric
             connector symbols.
                
   Input Arguments:
      entity       - The entity handle.
      symbol       - If you are deleting a detail item in the
                     drawing, set the parent to NULL. If you are
                     deleting draft entity in a symbol definition,
                     set the parent to be that symbol definition.
                     
   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProDtlentityModify (
    ProDtlentity *entity,
    ProDtlsymdef *symbol, 
    ProDtlentitydata entdata);
/*
   Purpose:   Modifies any part of the description of an existing detail item.
              The function does not update the display.  
              <p><b>Note : </b>The function cannot access symbol definitions
              for special symbols, such as, datum targets or parametric
              connector symbols.
                
   Input Arguments:
      entity       - The drawing handle.
      symbol       - If you are modifying a detail item in the
                     drawing, set the parent to NULL. If you are
                     modifying draft entity in a symbol definition,
                     set the parent to be that symbol definition.
      entdata      - The draft entity data.

   Output Arguments:
      None     

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProDtlentityDraw(
    ProDtlentity *entity);
/*
   Purpose:   Draws a detail item.    
                
   Input Arguments:
      entity     - The entity handle. 

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProDtlentityErase(
    ProDtlentity *entity);
/*
   Purpose:   Erases a detail item.    
                
   Input Arguments:
      entity     - The entity handle. 

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProDrawingDtlentitiesCollect(
    ProDrawing drawing,
    ProDtlsymdef *symbol, 
    int sheet,
    ProDtlentity **entities);
/*
   Purpose:     Collect all entities in the specified  drawing and sheet.
                <p><b>Note : </b>The function cannot access symbol definitions
                for special symbols, such as, datum targets or parametric
                connector symbols.
                
   Input Arguments:
      drawing      - The drawing
      symbol       - If you are collecting a detail item in the
                     drawing, set the parent to NULL. If you are
                     collecting draft entity in a symbol definition,
                     set the parent to be that symbol definition.
      sheet        - The sheet number. If the value is
                     PRO_VALUE_UNUSED, the function uses the
                     current sheet.

   Output Arguments:
      entities     - A list of views. The function allocates the memory
                     for this argument. To free the memory, call ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR - Success
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_GENERAL_ERROR - The function failed.
      PRO_TK_E_NOT_FOUND - No entities were found.
      PRO_TK_OUT_OF_MEMORY - The function found too many entities to be contained in the output ProArray.  Use ProDrawingDtlentityVisit instead.
*/

extern ProError ProDrawingDtlentityVisit(
    ProDrawing drawing,
    ProDtlsymdef *symbol,
    int sheet,
    ProDtlitemVisitAction visit_action,
    ProDtlitemFilterAction filter_action,
    ProAppData appdata);
/*
   Purpose:   Visits all draft entities stored in the specified 
              drawing and sheet.  
              <p><b>Note : </b>The function cannot access symbol definitions
              for special symbols, such as, datum targets or parametric
              connector symbols.
              
   Input Arguments:
      drawing       - The drawing
      symbol        - If you are collecting a detail item in the
                      drawing, set the parent to NULL. If you are
                      collecting draft entity in a symbol definition,
                      set the parent to be that symbol definition.
      sheet         - The sheet number. If the value is PRO_VALUE_UNUSED,
                      the function uses the current sheet.
      visit_action  - the function that gets called for each draft
                      entities being visited.
      filter_action - the function that gets called for each draft
                      entities. This function decides whether the
                      entities should be visited or skipped.
                      If NULL, all entities are visited using the
                      action function.
      appdata       - caller-specified data that gets passed to the
                      action and filter functions.
    
   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all
                           the draft entities.
      PRO_TK_BAD_INPUTS  - One or more arguments was invalid.	
      PRO_TK_GENERAL_ERROR - The function failed.
      PRO_TK_E_NOT_FOUND - No entities were found.
      Other              - Return value passed by the caller's visit function.
*/

/*================================================================*\
    ProDtlentitydata functions
\*=================================================================*/
extern ProError ProDtlentitydataAlloc (ProMdl owner,
                                       ProDtlentitydata  *entdata);
/*
   Purpose:     Allocates the data structure of a new draft entity 
                
   Input Arguments:
	owner       - An owner model handle

   Output Arguments:
        entdata     - The draft entity data.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataFree (
    ProDtlentitydata entdata);
/*
   Purpose:     Frees the data structure that contains the item.
                
   Input Arguments:
      entdata      - The draft entity data.

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataIdGet(
    ProDtlentitydata entdata,
    int *id);
/*
   Purpose: Returns the identifier of the draft entity.  This is valid only
            for data describing an existing detail entity in Creo Parametric.
                
   Input Arguments:
      entdata      - The draft entity data.
      
   Output Arguments:
      id           - The identifier of the draft entity.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/


extern ProError ProDtlentitydataCurveGet (
    ProDtlentitydata entdata,
    ProCurvedata *curve);
/*
   Purpose:     Retrieves information from a curve data structure. 
                The curve geometry is specified using screen coordinates.
                <p><b>Note: </b>Creo Parametric represents circle detail entities 
                with the ProArcdata structure with a start angle of 0 and an 
                end angle of 2*PI.
                
   Input Arguments:
      entdata      - The draft entity data.

   Output Arguments:
      curve        - The curve data structure. 

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/


extern ProError ProDtlentitydataCurveSet (
    ProDtlentitydata entdata,
    ProCurvedata *curve);
/*
   Purpose:    Sets the curve data structure of the specified draft entity.
               The curve geometry is specified using screen coordinates.
               <p><b>Note:</b> When creating a "circle" detail entity, use an
               arc with a start angle of 0 and an end angle of 2*PI. 
               Creo Parametric represents circle detail entities with the 
               ProArcdata structure.

   Input Arguments:
      entdata      - The draft entity data.
      curve        - The curve data structure. 
       
   Output Arguments:
      None
        
   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/


extern ProError ProDtlentitydataColorGet(
    ProDtlentitydata entdata,
    ProColor *color);
/*
   Purpose:     Finds the color of the specified draft entity.
                
   Input Arguments:
      entdata     - The draft entity data.

   Output Arguments:
      color       - The retrieved color of the draft entity.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataColorSet (
    ProDtlentitydata entdata,
    ProColor *color);
/*
   Purpose:     Sets the color of the specified draft entity.
                
   Input Arguments:
      entdata     - The draft entity data.
      color       - The new color of the draft entity.
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataFontGet (
    ProDtlentitydata entdata,
    ProName font);
/*
   Purpose:   Finds the font of the specified draft entity.  
                
   Input Arguments:
      entdata     - The draft entity data.

   Output Arguments:
      font        - The font of the draft entity.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_E_NOT_FOUND    - No font name is specified.
*/

extern ProError ProDtlentitydataFontSet (
    ProDtlentitydata entdata,
    ProName font);
/*
   Purpose:   Sets the font of the specified draft entity.  
                
   Input Arguments:
      entdata    - The draft entity data.
      font       - The new font of the draft entity.
      
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataWidthGet (
    ProDtlentitydata entdata,
    double *width);
/*
   Purpose:   Finds the width of the specified draft entity.    
                
   Input Arguments:
      entdata    - The draft entity data.

   Output Arguments:
      width      - The retrieved width of the draft entity.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataWidthSet (
    ProDtlentitydata entdata,
    double width);
/*
   Purpose:  Sets the width of the specified draft entity.     
                
   Input Arguments:
      entdata    - The draft entity data.
      width      - The new width of the draft entity.
      
   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataViewGet (
    ProDtlentitydata entdata,
    ProView *view);
/*
   Purpose:   Finds the drawing view of the specified draft entity.  
                
   Input Arguments:
      entdata     - The draft entity data.
      
   Output Arguments:
      view        - The drawing view handle.

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
      PRO_TK_E_NOT_FOUND    - The entity is not attached to a drawing view.
*/

extern ProError ProDtlentitydataViewSet (
    ProDtlentitydata entdata,
    ProView view);
/*
   Purpose:   Sets the drawing view of the specified draft entity.     
                
   Input Arguments:
      entdata     - The draft entity data.
      view        - The drawing view handle.
      
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	    - The function completed successfully.
      PRO_TK_BAD_INPUTS	    - Invalid input argument(s).
*/

extern ProError ProDtlentitydataIsConstruction(
    ProDtlentitydata data,
    ProBoolean *is_construction); 
/*
   Purpose:   checks if the draft entity is construction type
      
   Input Arguments:
      data      	  - The draft entity data.
      
   Output Arguments:
      is_construction     - PRO_B_TRUE if the draft entity is construction type
      

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/


extern ProError ProDtlentitydataConstructionSet(
    ProDtlentitydata data,
    ProBoolean construction); 
/*
   Purpose:   Marks the draft entity to be construction type

   Input Arguments:
      data                - The draft entity data.
      construction        - PRO_B_TRUE if the draft entity is to be construction type

   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/




PRO_END_C_DECLS

#endif /* PRODTLENTITY_H */
