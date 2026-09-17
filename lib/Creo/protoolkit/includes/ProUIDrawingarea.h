#ifndef PROUIDRAWINGAREA_H_
#define PROUIDRAWINGAREA_H_



#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProUI.h>

PRO_BEGIN_C_DECLS

extern ProError ProUIDrawingareaHelptextSet (char* dialog, char* component, wchar_t* value);
/*
    Purpose: Set the help text to display when the cursor is over the drawing
             area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Help text to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the help text that will be displayed when the cursor is over
                        the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Help text for the drawing area. Free this using 
                ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEnable (char* dialog, char* component);
/*
    Purpose: Set the drawing area and all its children to be sensitive to 
             user input.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDisable (char* dialog, char* component);
/*
    Purpose: Set the drawing area  and all its children 
             to be insensitive to the user input.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the drawing area is sensitive or insensitive to the user 
                          input.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - PRO_B_TRUE if the drawing area is sensitive. PRO_B_FALSE if the  
                drawing area is insensitive.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaShow (char* dialog, char* component);
/*
    Purpose: Make the drawing area visible.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaHide (char* dialog, char* component);
/*
    Purpose: Make the drawing area invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsVisible (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Determines if the drawing area is visible or invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - PRO_B_TRUE if the drawing area is visible. PRO_B_FALSE if the    
                drawing area is invisible.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFontclassSet (char* dialog, char* component, ProUIFontClass value);
/*
    Purpose: Set font class to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Font class to be set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFontclassGet (char* dialog, char* component, ProUIFontClass* value);
/*
    Purpose: Get the font class of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current font class.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFontstyleSet (char* dialog, char* component, ProUIFontStyle value);
/*
    Purpose: Set font style to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Font style to be set. This can be a bitmask of multiple styles.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFontstyleGet (char* dialog, char* component, ProUIFontStyle* value);
/*
    Purpose: Get font style of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current font style.  This can be a bitmask of multiple styles.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFontsizeSet (char* dialog, char* component, double value);
/*
    Purpose: Set the size of the font in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Font size to be set.  

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFontsizeGet (char* dialog, char* component, double* value);
/*
    Purpose: Get the size of the font in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current font size.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUIDrawingareaBackgroundcolorSet (char* dialog, char* component, ProUIColor value);
/*
    Purpose: Set the background color to the drawing area.  This is the
             actual color of the background of the drawing area; it is not
	     used for application-drawn graphics.  

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Background color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

   See Also:
        ProUIDrawingareaFgcolorSet()
	ProUIDrawingareaBgcolorSet()

*/

extern ProError ProUIDrawingareaBackgroundcolorGet (char* dialog, char* component, ProUIColor* value);
/*
    Purpose: Get the background color of the drawing area.  This is the
             actual color of the background of the drawing area; it is not
	     used for application-drawn graphics.  

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Background color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUIDrawingareaFgcolorGet()
	ProUIDrawingareaBgcolorGet()

*/

extern ProError ProUIDrawingareaDrawingwidthSet (char* dialog, char* component, int value);
/*
    Purpose: Set width to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Drawing area width.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingwidthGet (char* dialog, char* component, int* value);
/*
    Purpose: Get width of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Drawing area width.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingheightSet (char* dialog, char* component, int value);
/*
    Purpose: Set height to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Drawing area height.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingheightGet (char* dialog, char* component, int* value);
/*
    Purpose: Get height of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Drawing area height.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaClipchildrenSet (char* dialog, char* component, ProBoolean value);
/*
    Purpose: Set the flag indicating whether drawing operations 
	     within the drawing area should be clipped so that they 
	     do not overlap any children contained within the drawing area.
	     <P><B>NOTE:</B> This option does not affect the initial
	     display of the drawing area graphics using 
	     ProUIDrawingareaPostmanagenotifyActionSet() because the children
	     are drawn after the graphics are drawn.  This can be used from 
	     within other drawing area action callbacks.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - PRO_B_TRUE to clip the drawing operation. PRO_B_FALSE to not 
                clip the drawing operation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaClipchildrenGet (char* dialog, char* component, ProBoolean* value);
/*
    Purpose: Get the flag indicating whether the drawing operations within 
             the drawing area are clipped or not.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - PRO_B_TRUE if the drawing operations are clipped. PRO_B_FALSE    
                if the drawing operations are not clipped.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFgcolorSet (char* dialog, char* component, ProUIColor value);
/*
    Purpose: Set the foreground drawing color for new graphics to be drawn
             in the drawing area.
             This color is used to draw lines, shapes, and text on the
	     drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Foreground drawing color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

   See Also:
        ProUIDrawingareaBackgroundcolorSet()
	ProUIDrawingareaBgcolorSet()

*/

extern ProError ProUIDrawingareaFgcolorGet (char* dialog, char* component, ProUIColor* value);
/*
    Purpose: Get the foreground drawing color of the drawing area.
             This color is used to draw lines, shapes, and text on the
	     drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Foreground drawing color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

   See Also:
        ProUIDrawingareaBackgroundcolorGet()
	ProUIDrawingareaBgcolorGet()

*/

extern ProError ProUIDrawingareaBgcolorSet (char* dialog, char* component, ProUIColor value);
/*
    Purpose: Set the current background drawing color for new graphics to be
             drawn to the drawing area.
             This color is sometimes used to fill shapes in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Background drawing color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

  See Also:
        ProUIDrawingareaBackgroundcolorSet()
	ProUIDrawingareaFgcolorSet()

*/

extern ProError ProUIDrawingareaBgcolorGet (char* dialog, char* component, ProUIColor* value);
/*
    Purpose: Get the current background drawing color of the drawing area.
             This color is sometimes used to fill shapes in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Background drawing color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUIDrawingareaBackgroundcolorGet()
	ProUIDrawingareaFgcolorGet()

*/

extern ProError ProUIDrawingareaLinestyleSet (char* dialog, char* component, ProUILineStyle value);
/*
    Purpose: Set the current line style of new graphics to be drawn in the 
             drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Line style to be set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLinestyleGet (char* dialog, char* component, ProUILineStyle* value);
/*
    Purpose: Get the current line style of graphics to be drawn in the 
             drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current line style.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingmodeSet (char* dialog, char* component, ProUIDrawingMode value);
/*
    Purpose: Set the drawing mode for new graphics to be drawn in the 
             drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Drawing mode to be set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingmodeGet (char* dialog, char* component, ProUIDrawingMode* value);
/*
    Purpose: Get the current drawing mode of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current drawing mode.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFillmodeSet (char* dialog, char* component, ProUIFillMode value);
/*
    Purpose: Set the fill mode for new Fill function calls drawn in  the 
             drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Drawing fill mode to be set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaFillmodeGet (char* dialog, char* component, ProUIFillMode* value);
/*
    Purpose: Get the current  fill mode for the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current drawing fill mode.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcdirectionSet (char* dialog, char* component, ProUIArcDirection value);
/*
    Purpose: Set the direction used to draw new arcs in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Arc direction to be set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcdirectionGet (char* dialog, char* component, ProUIArcDirection* value);
/*
    Purpose: Get  the direction used to draw new arcs in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Current arc direction.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcfillmodeSet (char* dialog, char* component, ProUIArcFillMode value);
/*
    Purpose: Set the fill mode used for drawing new filled arcs in the 
              drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Fill mode for the arcs.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcfillmodeGet (char* dialog, char* component, ProUIArcFillMode* value);
/*
    Purpose: Get the fill mode used for drawing new filled arcs in the 
             drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Fill mode for the arcs.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPolygonfillmodeSet (char* dialog, char* component, ProUIPolygonFillMode value);
/*
    Purpose: Set the fill mode used for drawing new polygons in the drawing 
             area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Fill mode for the polygons.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPolygonfillmodeGet (char* dialog, char* component, ProUIPolygonFillMode* value);
/*
    Purpose: Get the fill mode used for drawing new polygons in the drawing 
             area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Fill mode for the polygons.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEnableTracking (char* dialog, char* component);
/*
    Purpose: Sets the drawing area to generate a 'move action' whenever 
             the cursor is moved over a visible region of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
	ProUIDrawingareaMoveActionSet()
	ProUIDrawingareaEnterActionSet()
	ProUIDrawingareaExitActionSet()
*/

extern ProError ProUIDrawingareaDisableTracking (char* dialog, char* component);
/*
    Purpose: Sets the drawing area to not generate a 'move action' whenever 
             the cursor is moved over a visible region of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
	ProUIDrawingareaMoveActionSet()
	ProUIDrawingareaEnterActionSet()
	ProUIDrawingareaExitActionSet()
*/

extern ProError ProUIDrawingareaIsTrackingEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the drawing area will generate a 'move action' whenever 
             the cursor is moved over a visible region of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - PRO_B_TRUE if the movement of the cursor generates a 
	        'move action'.  PRO_B_FALSE if the movement of the cursor 
                does not generate a 'move action'.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
	ProUIDrawingareaMoveActionSet()
	ProUIDrawingareaEnterActionSet()
	ProUIDrawingareaExitActionSet()
*/

extern ProError ProUIDrawingareaImagesSet (char* dialog, char* component, int count, char** values);
/*
    Purpose: Set the names of the images to be drawn in the drawing area. 
             Each image may be a BIF (the .bif extension is optional) 
             file or a PCX, GIF, BMP, ICO or CUR file.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of images.
        values - Array of images name to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaImagesGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Get the names of the images that are in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        count - Number of images.
        values - Array of images name. Free this using ProStringarrayFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDecorate (char* dialog, char* component);
/*
    Purpose: Decorate the drawing area with shadow border.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaUndecorate (char* dialog, char* component);
/*
    Purpose: Undecorate the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsDecorated (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the drawing area is decorated or not.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - PRO_B_TRUE if the drawing area is decorated. PRO_B_FALSE if the  
                drawing area is not decorated.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError ProUIDrawingareaCheckbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new check button to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the check button to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingareaAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new drawing area to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the drawing area to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaInputpanelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new input panel to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the input panel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLabelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new label to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLayoutAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new layout to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaListAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new list to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the list to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaOptionmenuAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new optionmenu to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the optionmenu to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaProgressbarAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new progressbar to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the progressbar to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPushbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new pushbutton to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the pushbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRadiogroupAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new radiogroup to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the radiogroup to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaSliderAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new slider to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the slider to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaSpinboxAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new spinbox to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the spinbox to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTabAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new tab to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the tab to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTableAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new table to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the table to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTextareaAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new textarea to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the textarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaThumbwheelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new thumbwheel to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the thumbwheel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTreeAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new area to the drawing area.
             The item's position must be set before the drawing area will 
	     show the new child.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the area to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaCheckbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the checkbutton from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaDrawingareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the drawing area from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the drawing area to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaInputpanelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the inputpanel from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the inputpanel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLabelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the label from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the label to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLayoutRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the layout from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the layout to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaListRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the list from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the list to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaOptionmenuRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the optionmenu from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the optionmenu to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaProgressbarRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the progressbar from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the progressbar to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPushbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the pushbutton from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRadiogroupRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the radiogroup from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaSliderRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the slider from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the slider to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaSpinboxRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the spinbox from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the spinbox to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTabRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the tab from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the tab to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTableRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the table from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the table to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTextareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the textarea from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the textarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaThumbwheelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the thumbwheel from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the thumbwheel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTreeRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove the area from the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        name - Name of the area to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the drawing area with respect to a given 
             anchor location. This function is applicable  only if the parent 
             of the drawing area is another drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the drawing area used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the drawingarea. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the drawingarea's minimum size, the function will fail.
              The drawingarea's minimum size can be retrieved
              using ProUIDrawingareaMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains drawingarea.
        component - The name of the drawingarea component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the drawing area with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the drawing area with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the drawingarea in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawingarea.
        component - The name of the drawingarea component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the drawing area. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        width - Width of the drawing area.
        height - Height of the drawing area.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaClear (char* dialog, char* component);
/*
    Purpose: Clear the contents of the drawing area by painting it in the 
             drawing background color (ProUIDrawingareaBgcolorGet()).

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaCopyArea (char* dialog, char* component, ProUIRectangle* rect, ProUIPoint* position);
/*
    Purpose: Copy the contents within a given boundary at a location in the
             drawing area to another location.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rect - Rectangular boundary containing the graphics to be copied.
        position - Point at which the copied graphics should appear.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPointsDraw (char* dialog, char* component, int count, ProUIPoint* points);
/*
    Purpose: Draw an array of points in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of points to be drawn.
        points - Array of points to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPolygonDraw (char* dialog, char* component, int count, ProUIPoint* points);
/*
    Purpose: Draw a polygon in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of vertices in the polygon.
        points - Array of points to form the vertices of the polygon.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPolylineDraw (char* dialog, char* component, int count, ProUIPoint* points);
/*
    Purpose: Draw a series of connected lines in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of points in the polygonal line.
        points - Array of points in the polygonal line.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLinesDraw (char* dialog, char* component, int count, ProUIPoint* start_points, ProUIPoint* end_points);
/*
    Purpose: Draw a set of lines between in the drawing area.  Each line will
             be drawn from the indicated start point in the array to the
	     corresponding endpoint.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of lines to be drawn.
        start_points - Array of points from which the lines should start.
        end_points - Array of points at which the lines should end.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRectsDraw (char* dialog, char* component, int count, ProUIRectangle* rects);
/*
    Purpose: Draw a set of rectangles in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of rectangles to be drawn.
        rects - Array of rectangles to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEllipsesDraw (char* dialog, char* component, int count, ProUIRectangle* rects);
/*
    Purpose: Draw a set of ellipses in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of ellipses to be drawn.
        rects - Array containing the rectangles bounding each ellipse.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcsDraw (char* dialog, char* component, int count, ProUIArc* arcs);
/*
    Purpose: Draw a set of arcs in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of arcs that are to be drawn.
        arcs - Array of arcs.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPolygonFill (char* dialog, char* component, int count, ProUIPoint* points);
/*
    Purpose: Draw a filled polygon in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of vertices in the polygon.
        points - Array of points to draw vertices for the polygon.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRectsFill (char* dialog, char* component, int count, ProUIRectangle* rects);
/*
    Purpose: Draw a set of filled rectangles in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of rectangles that are to be drawn.
        rects - Array of rectangles.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEllipsesFill (char* dialog, char* component, int count, ProUIRectangle* rects);
/*
    Purpose: Draw a set of filled ellipses in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
	count - Number of rectangles.
        rects - Array of rectangles bounding each ellipse.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcsFill (char* dialog, char* component, int count, ProUIArc* arcs);
/*
    Purpose: Draw a set of filled arcs in the drawing.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of arcs that are to be drawn.
        arcs - Array of arcs to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaStringsizeGet (char* dialog, char* component, wchar_t* string, ProUISize* size);
/*
    Purpose: Get the size that the given text string will occupy in the 
             drawing area, given the current drawing area font settings.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        string - Text string.

    Output Arguments:
        size - Size that the text string will occupy in the drawing area.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaStringbaselineGet (char* dialog, char* component, wchar_t* string, int* baseline);
/*
    Purpose: Get the height from the top of the string border to the string 
             baseline for the given text string in the drawing area, given the
             current drawing area font settings.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        string - Text string.

    Output Arguments:
        baseline - Position from the baseline.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaStringsDraw (char* dialog, char* component, int count, wchar_t** strings, ProUIPoint* positions);
/*
    Purpose: Draw strings at the given positions in the drawing.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of strings that are to be drawn.
        strings - Array of strings to be drawn.
        positions - Array of points at which the strings should be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaImagesizeGet (char* dialog, char* component, char* image, ProUISize* size);
/*
    Purpose: Get the size of the image in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        image - Image for which the size should be obtained.

    Output Arguments:
        size - Size of the image.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaImagesDraw (char* dialog, char* component, int count, char** images, ProUIPoint* positions);
/*
    Purpose: Draw images at the given positions in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        count - Number of images that are to be drawn.
        images - Array of image names.
        positions - Array of points at which the images should be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaCursorposGet (char* dialog, char* component, ProUIPoint* position);
/*
    Purpose: Get the position of the cursor in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        position - Position of the cursor.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUIDrawingareaArcDraw (char* dialog, char* component, ProUIArc* arc);
/*
    Purpose: Draw an arc in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        arc - Arc to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEllipseDraw (char* dialog, char* component, ProUIRectangle* rect);
/*
    Purpose: Draw an ellipse in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rect - Rectangle bounding the ellipse.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaImageDraw (char* dialog, char* component, char* image, ProUIPoint* position);
/*
    Purpose: Draw an image in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        image - Name of the image to be drawn.
        position - Point at which the image should be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLineDraw (char* dialog, char* component, ProUIPoint* start_point, ProUIPoint* end_point);
/*
    Purpose: Draw a line in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        start_point - Start point of the line.
        end_point - End point of the line.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPointDraw (char* dialog, char* component, ProUIPoint* point);
/*
    Purpose: Draw a point in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        point - Point to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRectDraw (char* dialog, char* component, ProUIRectangle* rect);
/*
    Purpose: Draw a rectangle in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rect - Rectangle to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaShadowRectDraw (char* dialog, char* component, ProUIRectangle* rect);
/*
    Purpose: Draw a rectangle with a shadow border.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rect - Rectangle to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaShadowRectsDraw (char* dialog, char* component, ProUIRectangle* rects, int count);
/*
    Purpose: Draw a set of rectangles with shadow borders.
    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rects - Array of rectangles.
        count - Number of rectangles.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaStringDraw (char* dialog, char* component, wchar_t* string, ProUIPoint* position);
/*
    Purpose: Draw a string at the given position in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        string - String to be drawn.
        position - Position at which the string should be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaArcFill (char* dialog, char* component, ProUIArc* arc);
/*
    Purpose: Draw a filled arc in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        arc - Arc to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEllipseFill (char* dialog, char* component, ProUIRectangle* rect);
/*
    Purpose: Draw a filled ellipse in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rect - Rectangle bounding the ellipse.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRectFill (char* dialog, char* component, ProUIRectangle* rect);
/*
    Purpose: Draw a filled rectangle in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        rect - Rectangle to be drawn.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaCursorposSet (char* dialog, char* component, int x, int y);
/*
    Purpose: Set the cursor at the given location in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        x - X value.
        y - Y value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaEnterActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the user has moved the 
             cursor into the drawing area.  This action will be generated only
	     if tracking is enabled for the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the cursor is moved in to the 
                   drawing area.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

   See Also:
	ProUIDrawingareaEnableTracking()
	ProUIDrawingareaDisableTracking()
	ProUIDrawingareaIsTrackingEnabled()
*/

extern ProError ProUIDrawingareaExitActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the user has moved the cursor 
             out of the drawing area.  This action will be generated only if 
             tracking is enabled for the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the cursor is moved out of the 
                   drawing area.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

   See Also:
	ProUIDrawingareaEnableTracking()
	ProUIDrawingareaDisableTracking()
	ProUIDrawingareaIsTrackingEnabled()
*/

extern ProError ProUIDrawingareaMoveActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the cursor is moved over the 
             drawing area.  This action will be generated only if tracking
	     is enabled for the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the cursor is moved over the 
                   drawing area.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
	ProUIDrawingareaEnableTracking()
	ProUIDrawingareaDisableTracking()
	ProUIDrawingareaIsTrackingEnabled()

*/

extern ProError ProUIDrawingareaLbuttonarmActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the left mouse button is 
	     pressed in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the left mouse button is pressed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLbuttondisarmActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the left mouse button is 
             released in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the left mouse button is 
                   released.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLbuttonactivateActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the left mouse button is 
             pressed and released in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the left mouse button is pressed 
                   and released.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLbuttondblclkActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the left mouse button is 
             double-clicked in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the left mouse button is 
	           double-clicked.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaMbuttonarmActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the middle mouse button is 
	     pressed in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the middle mouse button is pressed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaMbuttondisarmActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the middle mouse button is 
	     released in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the middle mouse button is released.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaMbuttonactivateActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the middle mouse button is 
	     pressed and released in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the middle mouse button is pressed and released.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaMbuttondblclkActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the middle mouse button is 
	     double-clicked in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the middle mouse button is 
                   double-clicked.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRbuttonarmActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the right mouse button is 
	     pressed in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the right mouse button is pressed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRbuttondisarmActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the right mouse button is 
	     released in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the right mouse button is released.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRbuttonactivateActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the right mouse button is 
	     pressed and released in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the right mouse button is 
		   pressed and released.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRbuttondblclkActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the right mouse button is 
	     double-clicked in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the right mouse button is 
		   double-clicked.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaUpdateActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the drawing area needs to
             be updated due to a system-level color scheme change.  

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the drawing area needs to be 
	           updated.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaResizeActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the function to be called when the drawing area is resized.
             Note: the drawing area contents are typically cleared after
	     a resize.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the drawing area is resized.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPostmanagenotifyActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
     Purpose: Set the function to be called when the drawing area has just
              been displayed.  Use this callback to setup the initial
              graphics, text, and images in the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        callback - Function to be called when the drawing area has just been
	           managed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUIDrawingareaParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the drawing area component.

     Input Arguments:
         dialog - The name of the dialog that contains the drawing area.
         component - The name of the drawing area component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaChildnamesGet (char *dialog, char *component, int *count, char ***values);
/*
     Purpose: Get the names of the children to the drawing area component.

     Input Arguments:
         dialog - The name of the dialog that contains the drawing area.
         component - The name of the drawing area component.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPopupmenuSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the popup menu to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - The name of the popup menu.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaPopupmenuGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the popup menu for the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - The name of the popup menu. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the drawing area at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the drawing area at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  drawing area is attached at left side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the drawing area     
                is attached at left. PRO_B_FALSE if the drawing area is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the drawing area at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the drawing area at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  drawing area is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the drawing area    
                is attached at right. PRO_B_FALSE if the drawing area is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the drawing area at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the drawing area at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  drawing area is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the drawing area      
                is attached at top. PRO_B_FALSE if the drawing area is not
                attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the drawing area at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the drawing area at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  drawing area is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the drawing area   
                is attached at bottom. PRO_B_FALSE if the drawing area is not
                 attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIDrawingareaBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the drawing area.
        component - The name of the drawing area component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



PRO_END_C_DECLS

#endif
