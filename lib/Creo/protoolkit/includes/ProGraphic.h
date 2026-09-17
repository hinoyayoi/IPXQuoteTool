


#ifndef PROGRAPHICS_H
#define PROGRAPHICS_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProColor.h>

PRO_BEGIN_C_DECLS

#define PRO_CONTROL_MASK 0x20000      /* Not used in Creo Parametric TOOLKIT */
#define PRO_SHIFT_MASK 0x10000        /* Not used in Creo Parametric TOOLKIT */
#define PRO_ALT_MASK   0x080000       /* Not used in Creo Parametric TOOLKIT */
#define PRO_MODIFIERS_MASK (PRO_CONTROL_MASK | PRO_SHIFT_MASK | PRO_ALT_MASK)  

#define  PRO_MOUSETRACK_OPT_NO_OPTIONS    (0)
#define  PRO_MOUSETRACK_OPT_GRID_SNAP     (1<<0) /*Snap mouse position to grid*/
#define  PRO_MOUSETRACK_OPT_ALLOW_VIEWING (1<<1) /* Allow user to move the model using MMB and dragging (don't pass this action to ProMouseTrack) */

typedef enum
{
  PRO_NO_BUTTON = 0,
  PRO_LEFT_BUTTON = 1,
  PRO_RIGHT_BUTTON = 2,
  PRO_MIDDLE_BUTTON = 4,
  PRO_LEFT_BUTTON_REL = 8,     /* Not used in Creo Parametric TOOLKIT */
  PRO_RIGHT_BUTTON_REL = 16,   /* Not used in Creo Parametric TOOLKIT */
  PRO_MIDDLE_BUTTON_REL = 32,  /* Not used in Creo Parametric TOOLKIT */
  PRO_MOUSE_MOVE = 64,
  PRO_LEFT_DOUBLECLICK = 512,
  PRO_ANY_BUTTON   = 8191
} ProMouseButton;

typedef enum
{
  PRO_DRAW_NO_MODE = -1,
  PRO_DRAW_COMPLEMENT_MODE = 0,
  PRO_DRAW_SET_MODE = 1
} ProDrawMode;

typedef struct pro_text_attribute
{
  int font_id;
  double height;
  double width_factor;
  double  rot_angle;
  double slant_angle;
} ProTextAttribute;

/*===========================================================================*/

extern void ProGraphicsPenPosition ( ProPoint3d point );
/*

  Purpose:  

     Prepares for a series of calls to <B>ProGraphicsLineDraw()</B>. This 
     function enables you to move to a point without any graphical 
     output.
<p>
     These points are in the coordinate system of the current object. 
     For example, if the current object is a part, the points must be 
     in the part's coordinate system. If the current object is an 
     assembly, the points must be in the assembly's coordinate system.

  Input Arguments:
     point  - The point to which to move 

  Output Arguments:
     None

  Return Values: 
     None

  See Also:
     ProGraphicsLineDraw() 
  
*/

extern void ProGraphicsLineDraw ( ProPoint3d point );
/*  

  Purpose:  

     Draws a line on the screen from the last position to the position 
     specified by the <I>xyz</I> argument.
  <p>
      NOTE:
  <p>
      These points are in the coordinate system of the current 
      object. For example, if the current object is a part, the points 
      must be in the part's coordinate system. If the current object is 
      an assembly, the points must be in the assembly's coordinate 
      system.

  Input Arguments:
     point   - The 3-D point to draw the line to, defined as (X, Y, Z)

  Output Arguments:
     None

  Return Values:
     None
*/

extern void ProGraphicsPolylineDraw ( ProPoint3d* point_arr,
                                      int         num_points );
/* 

  Purpose:
     Draws a series of connected line segments (polylines) on the screen.
<p>
     NOTES:
<ul>
      <li>These points are in the coordinate system of the current 
       object. For example, if the current object is a part, the 
       points must be in the part's coordinate system. If the 
       current object is an assembly, the points must be in the 
       assembly's coordinate system.

      <li>The total number of points must be less than 200.
</ul>

  Input Arguments:
     point_arr   - The 3-D points to connect with line segments.
     num_points  - The number of points in the points array.

  Output Arguments:
     None

  Return Values:
     None

*/

extern void ProGraphicsMultiPolylinesDraw ( ProPoint3d* point_arr,
                                            int*        span,
                                            int         num_lines );
/*  
  Purpose:
     Draws a set of polylines on the screen.
<p>
     NOTES:
<ul>
      <li>These points are in the coordinate system of the current 
       object. If the current object is a part, they must be in the 
       part's coordinate system. If the current object is an 
       assembly, they must be in the assembly's coordinate 
       system.

      <li>The total number of points (the sum of the span elements) 
       must be less than 200.
</ul>
<p>
EXAMPLE:
<p>
This example draws a 3-point polyline, a 2-point polyline, and a 
4-point polyline.
<p>
<pre>static double points = { {0.0, 0.0, 0.0},</pre>
                         <pre>{1.0, 0.0, 0.0},</pre>
                         <pre>{1.0, 1.0, 0.0},</pre>
                         <pre>{7.1, 2.3, -12.0},</pre>
                         <pre>{7.1, 10.9, -5.1},</pre>
                         <pre>{4.1, 9.2, 2.0},</pre>
                         <pre>{3.8, 9.2, 4.5},</pre>
                         <pre>{0.4, 9.2, 3.2},</pre>
                         <pre>{2.1, 9.2, 0.5}}</pre>
<pre>static int span = {3, 2, 4}</pre>
<pre>static int num_lines = 3</pre>


  Input Arguments:
     point_arr  - The 3-D points that define
                  the segments of the polylines
     span       - The number of points in each polyline
     num_lines  - The number of polylines (the number of
                  elements in <I>span</I>)  

  Output Arguments:
     None

  Return Values:
     None

*/

extern ProError ProGraphicsArcDraw ( ProPoint3d center,
                                     double     radius,
                                     ProVector  vector1,
                                     ProVector  vector2 );
/*

  Purpose:
     Draws an arc on the screen.
<p>
     NOTE: 
<p>
     All points are in logical screen coordinates.

  Input Arguments:
     center   - The center point of the arc
     radius   - The radius of the arc
     vector1  - The starting point
     vector2  - The endpoint

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully drew the arc. 
     PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.

*/

extern void ProGraphicsCircleDraw ( ProPoint3d center,
                                    double     radius );
/*

  Purpose:
     Draws a circle on the screen.
<p>
     NOTE: 
<p>
     These points are in the coordinate system of the current 
     object. For example, if the current object is a part, the points 
     must be in the part's coordinate system. If the current object is 
     an assembly, the points must be in the assembly's coordinate 
     system.

  Input Arguments:
     center   - The center
     radius   - The radius

  Output Arguments:
     None

  Return Values:
     None

*/

extern ProError ProGraphicsPolygonDraw ( ProPoint2d*   point_array,
                                         int           num_points,
                                         ProColortype fill_color );
/*

  Purpose:
     Draws filled or unfilled polygons in the window.
<p>
     NOTE:
<p>
     This function is intended primarily to clear areas in 
     Creo Parametric windows. It does not affect any Creo Parametric 
     interface.

  Input Arguments:
     point_array   - An array of X and Y coordinates, in logical window
                     coordinates.
     num_points    - The number of points in the point array. The maximum
                     size of the array is 100 points.
     fill_color    - The fill color.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully drew the polygon.
     PRO_TK_LINE_TOO_LONG - You specified more than 100 points.

*/
      
extern ProError ProGraphicsTextDisplay ( ProPoint3d point,
                                         wchar_t*   text );
/* 

  Purpose:
     Draws text on the screen.
<p>
     NOTES:
<ul>
      <li>All points are in logical screen coordinates.

      <li>You can call the function <b>ProText*CurrentSet()</b> to
       set the text attributes before calling this function.
</ul>

  Input Arguments:
     point   - The starting point for the text
     text    - The text string

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully drew the text.
     PRO_TK_E_NOT_FOUND  - The font specified in a previous call to
                           <b>ProtText*CurrentSet()</b> was not found.
*/

extern ProError ProGraphicsColorSet ( ProColortype new_color,
                                      ProColortype *p_old_color );
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProGraphicsColorModify
   Purpose: Changes the color used to draw any subsequent graphics.
<p>
            NOTE: 
<p>
            This function is deprecated.  Use ProGraphicsColorModify() instead.

   Input Arguments:
      new_color    - The new color to use when drawing a graphics
                     entity.  The default color is white.

   Output Arguments:
      p_old_color  - The previous color.  May be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully changed the color.
      PRO_TK_NO_CHANGE  - The current color is the same as the new color.
*/


extern ProError ProGraphicsColorModify ( ProColor* new_color,
                                         ProColor *p_old_color );
/*
   Purpose: Changes the color used to draw any subsequent graphics.

   Input Arguments:
      new_color    - The new color to use when drawing a graphics
                     entity.  If the method is PRO_COLOR_METHOD_DEFAULT,
		     graphics will be drawn using PRO_DRAWING_COLOR.
		     If NULL, no change will be made, but the function
		     outputs the current color in the output argument.

   Output Arguments:
      p_old_color  - The previous color.  May be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully changed the color.
      PRO_TK_NO_CHANGE  - The current color is the same as the new color.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProTextAttributesCurrentGet (
                                           ProTextAttribute* attribute);
/*
 
  Purpose:
     Retrieves the current text attributes. If the current text attributes have
     not already been modified by Creo Parametric TOOLKIT, this function returns the 
     default text parameters.
<p>
     The text attributes apply only to text that is output by 
     <b>ProGraphicsTextDisplay()</b>.

  Input Arguments:
     None    

  Output Arguments:
     attribute          - The current text attributes

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully retrieved the
                          information.
     PRO_TK_BAD_INPUTS  - The attribute argument is NULL. 
     PRO_TK_E_NOT_FOUND - The attributes were not set.

  See Also:

     ProTextFontIdCurrentSet()
     ProTextHeightCurrentSet()
     ProTextWidthFactorCurrentSet()
     ProTextRotationAngleCurrentSet()
     ProTextSlantAngleCurrentSet()     
     ProGraphicsTextDisplay()
*/

extern ProError ProTextFontIdCurrentSet ( int font_id );
/*

   Purpose:   Sets the font identifier of Creo Parametric text output.

   Input Arguments:
      font_id - The font identifier

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the value.
*/

extern ProError ProTextHeightCurrentSet ( double height );
/*

   Purpose:   Sets the height of Creo Parametric text output.

   Input Arguments:
      height         - The current text height for drawn graphics.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the height.
*/


extern ProError ProTextWidthFactorCurrentSet ( double width_factor );
/*

   Purpose:   Sets the width factor of Creo Parametric text output.

   Input Arguments:
      width_factor    - The current text width for drawn graphics.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the width factor.
*/

extern ProError ProTextRotationAngleCurrentSet ( double rotation_angle );
/*

   Purpose:   Sets the rotational angle of Creo Parametric text output.

   Input Arguments:
      rotation_angle    - The current text rotation angle for drawn graphics.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the rotational angle.
*/

extern ProError ProTextSlantAngleCurrentSet( double slant_angle );
/*

   Purpose:   Sets the slant angle of Creo Parametric text output.

   Input Arguments:
      slant_angle    - The current text slant angle for drawn graphics.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the slant angle.
*/

extern ProError ProTextAttributesCurrentUnset ( void );
/*

   Purpose:  Unsets the text attributes set using the function 
             <b>ProText*CurrentSet()</b>. After unsetting the attributes,
             the function restores the default values
             (as given by <b>ProTextAttributesCurrentGet()</b>).

   Input Arguments:
      None

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully reset all the settings
                        to their default values.

   See Also:
      ProTextFontIdCurrentSet()
      ProTextHeightCurrentSet()
      ProTextWidthFactorCurrentSet()
      ProTextRotationAngleCurrentSet()
      ProTextSlantAngleCurrentSet()
      ProTextAttributesCurrentGet() 
*/

extern void ProTextFontDefaultIdGet ( int* font_id );
/* 

  Purpose:
     Returns the default text font identifier.
<p>
     NOTE:
<p>
     The correspondence between font names and font 
     identifiers stays constant during a Creo Parametric session, but 
     may be different for different sessions.

  Input Arguments:
     None
 
  Output Arguments:
     font_id    - The default font identifier

  Return Values:
     None

*/

extern ProError ProTextFontNameToId (ProLine font_name, 
                                     int*    font_id);
/*

  Purpose:
     Returns the identifier for the specified text font name.
<p>
     NOTES:
<ul>
     <li>The correspondence between font names and font 
       identifiers stays constant during a Creo Parametric session, 
       but may be different for different sessions.
     <li>To the Creo Parametric user, fonts are identified by names; 
       in Creo Parametric TOOLKIT, they are identified by integer identifiers. 
       This function translates between names and identifiers. 
       The names must have the file extension <I>.ndx</I> added to them, 
       such as <I>font.ndx</I>, <I>filled.ndx</I>.
</ul>

  Input Arguments:
       font_name          -  The name of the text font

  Output Arguments:
       font_id            -  The font identifier

  Return Values:
       PRO_TK_NO_ERROR    - The function successfully retrieved the
                            information.
       PRO_TK_BAD_INPUTS  - The input argument is invalid, or the
                            font identifier is NULL.
       PRO_TK_E_NOT_FOUND - The function could not find a font identifier
                            for the specified font name.

*/

extern ProError ProTextFontNameGet (int     font_id, 
                                     ProLine font_name);
/* 
  
  Purpose:
     Retrieves the font name for the specified font identifier.
     <p>
     NOTE:
     <p>
     The correspondence between font names and font 
     identifiers stays constant during a Creo Parametric session, but 
     may be different for different sessions.

  Input Arguments:
     font_id             - The identifier of the text font

  Output Arguments:
     font_name           - The name of the font

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully retrieved the
                           information.
     PRO_TK_E_NOT_FOUND  - The function could not find a font name for
                           the specified font identifier.

*/

extern ProError ProGraphicsModeSet ( ProDrawMode new_mode,
                                     ProDrawMode* old_mode );
/* 

  Purpose:  Sets the drawing mode.

  Input Arguments:
     new_mode        - The new drawing mode

  Output Arguments:
     old_mode        - The previous mode

  Return Values:
     PRO_TK_NO_ERROR - The function successfully set the value.

*/

extern ProError ProMousePickGet ( ProMouseButton expected_button,
                                  ProMouseButton* button_pressed,
                                  ProPoint3d      position );
/*

  Purpose:
     Reports the mouse position when the user presses one of the mouse 
     buttons. It does not return until the user presses a button.
<p>
     NOTE:
<p>
     You must check the return value to make sure the user did not 
     select a command.

  Input Arguments:
     expected_button  -  The identifier of the mouse button the user is
                         expected to use to make the pick. If the user can pick
                         with any button, use PRO_ANY_BUTTON.

  Output Arguments:
     button_pressed   - The identifier of the button used to
                        make the pick.
     position         - The coordinates of the picked point.

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the
                            information.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function
                            failed.

*/
 
extern ProError ProMouseTrack ( int options,
                                ProMouseButton* button_pressed,
                                ProPoint3d      position );
/* 

  Purpose:
     Reports the current mouse position immediately, regardless of 
     whether any buttons are pressed.
   
  Input Arguments:
     options     - The mouse tracking options.  Supply one or more of the
                   PRO_MOUSETRACK_OPT constants OR'd together for this argument.
                   This bitmask allows you to track using grid snap, 
                   and also to allow viewing operations using the middle mouse
                   button while tracking.
                   If <i>options</i> is 0, the function returns the exact mouse
                   coordinates while disabling all viewing operations
                   (this is the usual type of call).

  Output Arguments:
     button_pressed  - Specifies which mouse buttons were pressed.
     position        - The logical window coordinates of the current
                       mouse position.

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully retrieved the 
                             information.
     PRO_TK_ABORT          - The user aborted input. 
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                             failed. 

*/

extern ProError ProMouseBoxInput ( ProPoint3d point,
                                   ProOutline outline );
/*

  Purpose:
     Draws a dynamic rectangle from the specified point (in screen 
     coordinates) to the current mouse position, until the user presses 
     the left mouse button. The function then returns the coordinates of 
     the box entered.
     <p>
     If you hit the middle or right mouse button instead of picking 
     the first vertex, the function aborts. 

  Input Arguments:
     point     - If not equal to NULL, this specifies the coordinates
                 of one of the corners of the box. If this is NULL,
                 the function obtains the placement of both corners
                 of the box.

  Output Arguments:
     outline   - The coordinates of the box, as selected by the user.

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully returned the box
                            outline.
     PRO_TK_GENERAL_ERROR - The user picked a command.

*/

PRO_END_C_DECLS

#endif
