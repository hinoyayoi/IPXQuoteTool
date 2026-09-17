

#ifndef PRO_COLOR_H
#define PRO_COLOR_H

#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef enum
{
    PRO_COLORMAP_STANDARD = 0,
    PRO_COLORMAP_PRE_WILDFIRE = 1
} ProColormapVersion;

typedef enum
{
    PRO_COLORMAP_ALT_DEFAULT = 0,
    PRO_COLORMAP_ALT_BLACK_ON_WHITE = 1,
    PRO_COLORMAP_ALT_WHITE_ON_BLACK = 2,
    PRO_COLORMAP_ALT_WHITE_ON_GREEN = 3,
    PRO_COLORMAP_OPTIONAL1 = 4,
    PRO_COLORMAP_OPTIONAL2 = 5,
    PRO_COLORMAP_CLASSIC_WF = 6

} ProColormapAlternatescheme;

typedef enum pro_line_style
{
   PRO_LINESTYLE_UNDEFINED = PRO_VALUE_UNUSED,
   PRO_LINESTYLE_SOLID = 0,           /* solid line style                   */
   PRO_LINESTYLE_DOT   = 1,           /* dotted line style                  */
   PRO_LINESTYLE_CENTERLINE = 2,      /* alternating long & short dashes    */
   PRO_LINESTYLE_PHANTOM = 3,         /* alternating long dash and two dots */
   PRO_LINESTYLE_DASH = 4,
   PRO_LINESTYLE_CTRL_S_L = 5,
   PRO_LINESTYLE_CTRL_L_L = 6,
   PRO_LINESTYLE_CTRL_S_S = 7,
   PRO_LINESTYLE_DASH_S_S = 8,
   PRO_LINESTYLE_PHANTOM_S_S = 9,
   PRO_LINESTYLE_CTRL_MID_L = 10,
   PRO_LINESTYLE_INTMIT_LWW_HIDDEN = 11,
   PRO_LINESTYLE_PDFHIDDEN_LINESTYLE = 12   
} ProLinestyle;

typedef struct pro_color_map
{
 double  red;          /* percentage of red from 0.0 to 1.0     */
 double  green;        /* percentage of green from 0.0 to 1.0   */
 double  blue;         /* percentage of blue from 0.0 to 1.0    */
} ProColormap;

typedef enum pro_color_method
{
    PRO_COLOR_METHOD_DEFAULT,
    PRO_COLOR_METHOD_TYPE,
    PRO_COLOR_METHOD_RGB
} ProColorMethod;

typedef struct pro_color
{
    ProColorMethod method;
    union {
	ProColortype type;
	ProColormap map;
    } value;
} ProColor;

typedef struct pro_linestyle
{
   ProName        line_style_name;
   ProName        line_definition;
   ProName        cap_style;
   ProName        join_style;
   double         dash_offset;
   int            len_of_dash_list;
   double        *dash_list;
   ProName        fill_style;
   ProName        fill_rule;
} ProLinestyleData;

/*===========================================================================*/

extern ProError ProTextColorSet ( ProColortype  new_text_color,
                                  ProColortype *p_old_text_color);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProTextColorModify
   Purpose: Enables you to change the text color so any subsequent
            graphics window text is drawn in the specified color.
<p>
            NOTE: 
<p>
            This function is deprecated.  Use ProTextColorModify instead.

   Input Arguments:
      new_text_color    - The new color to use to display text.
                          The default color is yellow.

   Output Arguments:
      p_old_text_color  - The previous text color.  May be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully changed the color.
      PRO_TK_NO_CHANGE  - The current color is the same as the new color.
*/


/*===========================================================================*/

extern ProError ProTextColorModify ( ProColor *new_text_color,
                                             ProColor *p_old_text_color);
/*

   Purpose: Enables you to change the text color so any subsequent
            graphics window text is drawn in the specified color.

   Input Arguments:
      new_text_color    - The new color to use to display text.
                          If the color method is PRO_COLOR_METHOD_DEFAULT,
			  the color used will be PRO_TEXT_COLOR. May be NULL,
			  in which case the current text color will be 
			  returned.

   Output Arguments:
      p_old_text_color  - The previous text color.  May be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully changed the color.
      PRO_TK_NO_CHANGE  - The current color is the same as the new color.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid. 
*/

extern ProError ProColormapGet ( ProColortype color_type, 
                                 ProColormap* color);
/*

   Purpose: Retrieves the RGB values for the specified color value.

   Input Arguments:
      color_type    - The color type 

   Output Arguments:
      color         - The RGB value

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the RGB values.
      PRO_TK_BAD_INPUTS - Either the color identifier is invalid or the 
                          color is NULL.
*/

extern ProError ProColorByTypeGet ( ProDisplayedType object_type, 
				    ProColortype* color);
/*

   Purpose: Retrieves the standard color used for the specified object type.

   Input Arguments:
      object_type   - The object type.

   Output Arguments:
      color         - The color typically used by Creo Parametric to render the 
                       object.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the color.
      PRO_TK_BAD_INPUTS  - One or more arguments are invalid.
      PRO_TK_E_NOT_FOUND - No default color entry exists for this entity type.
      
*/

extern ProError ProColormapSet ( ProColortype            color_type, 
                                 PRO_CONST_ARG ProColormap* color);
/*

   Purpose: Enables you to set the values of the three color components
            for a specified color value.

   Input Arguments:
      color_type    - The color type 
      color         - The RGB value

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully set the color values.
      PRO_TK_BAD_INPUTS - Either the color identifier is invalid or the 
                          color is NULL.
*/

extern ProError ProLinestyleSet ( ProLinestyle line_style, 
                                  ProLinestyle* old_style);
/*

   Purpose: Sets the line style for the graphics drawn by Creo Parametric TOOLKIT.

   Input Arguments:
      line_style  - The new line style.

   Output Arguments:
      old_style   - The previous line style. This can be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully set the color.
      PRO_TK_NO_CHANGE  - The new line style is the same as the old line style.
*/


extern ProError ProLinestyleDataGet ( ProLinestyle style,
                                              ProLinestyleData* style_info);
/*

   Purpose: Provides a description of the specified line style.

   Input Arguments:
      style        - The style type.

   Output Arguments:
      style_info   - The line style information. Note that the field
                     <i>dash_list</i> is allocated by the function. 
                     To free the data,
                     call the function <b>ProArrayFree()</b>.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully returned the information.
      PRO_TK_BAD_INPUTS  - The specified style is invalid.
      PRO_TK_INVALID_PTR - The <i>style_info</i> == NULL.

   See Also:
      ProArrayFree()
*/

extern ProError ProColormapVersionGet (ProColormapVersion *current_version);
/*

   Purpose: Get the current color map version.

   Input Arguments:
      None

   Output Arguments:
      current_version   - Pointer to current color map version.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the color map
                          version.
      PRO_TK_BAD_INPUTS - Current color map version pointer is NULL.

   See Also:
      ProColormapVersionSet()
*/

extern ProError ProColormapVersionSet (ProColormapVersion current_version);
/*

   Purpose: Set the current color map version.

   Input Arguments:
      current_version - New color map version.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully set the color map version.
      PRO_TK_BAD_INPUTS   - Color map version is invalid.
      PRO_TK_GENERAL_ERROR - Unable to set the color map version.

   See Also:
      ProColormapVersionGet()
*/

extern ProError ProColormapAlternateschemeGet(ProColormapAlternatescheme *alt_scheme);
/*

   Purpose: Get the current color map alternate scheme.

   Input Arguments:
      None

   Output Arguments:
      alt_scheme - Pointer to current color map alternate scheme.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the color map
                             alternate scheme.
      PRO_TK_BAD_INPUTS    - Current color map alternate scheme pointer is NULL.
      PRO_TK_GENERAL_ERROR - Current color map alternate scheme is invalid.

   See Also:
      ProColormapAlternateschemeSet()
*/

extern ProError ProColormapAlternateschemeSet(
                                        ProColormapAlternatescheme alt_scheme);
/*

   Purpose: Set the current color map alternate scheme.

   Input Arguments:
      alt_scheme           - New color map alternate scheme.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully set the color map
                             alternate scheme.
      PRO_TK_BAD_INPUTS    - New color map alternate scheme is invalid.
      PRO_TK_GENERAL_ERROR - Unable to set the color map alternate scheme.

   See Also:
      ProColormapAlternateschemeGet()
*/

PRO_END_C_DECLS

#endif
