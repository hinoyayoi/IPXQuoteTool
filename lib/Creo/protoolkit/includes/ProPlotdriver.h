#ifndef PROPLOTDRIVER_H
#define PROPLOTDRIVER_H



#include	<ProToolkit.h>
#include	<ProObjects.h>
#include        <ProColor.h>

PRO_BEGIN_C_DECLS 

extern ProError ProPlotdriverInterfaceCreate (ProName interf_name);
/* 
    Purpose:  Finds an interface with <i>name</i>, 
              or creates a new interface if it does not exist yet. 

    Input Arguments:
       interf_name - The name of the new interface. Cannot be NULL.
                     The name must begin with a letter.

    Output Arguments:
       none

    Return Values:
       PRO_TK_NO_ERROR      - interface successfully created.
       PRO_TK_BAD_INPUTS    - name is NULL.
       PRO_TK_NOT_VALID     - name is not valid (does not start with a letter)
       PRO_TK_OUT_OF_MEMORY - no more available slots to create a new interface.
*/

extern ProError ProPlotdriverInterfaceobjectsSet (ProName interf_name, 
                                                  ProName *object_types);
/* 
    Purpose:  Sets object types with which the interface can work. 
           The interface <i>interf_name</i> can work only with objects of
           specified types.

    Input Arguments:

       interf_name      - The name of the interface. Cannot be NULL.
       object_types     - ProArray of names representing object types 
                          (examples: "PRT", "ASM", "DRW").
                          Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - object types successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
*/


typedef ProError (*ProPlotdriverLinePlot) (ProAppData data,
                                           Pro3dPnt point1, Pro3dPnt point2, int color);

/*
    Purpose:  This is the generic function for plotting a line.

    Input Arguments:
       data   - The application data.
       point1 - Start of the line.
       point2 - End of the line.
       color  - Color index. The possible values are as follows:
                   <ul>
                   <li>PRO_LETTER_COLOR
                   <li>PRO_HIGHLITE_COLOR
                   <li>PRO_DRAWING_COLOR
                   <li>PRO_BACKGROUND_COLOR
                   <li>PRO_HALF_TONE_COLOR
                   <li>PRO_EDGE_HIGHLITE_COLOR
                   <li>PRO_DIMMED_COLOR
                   <li>PRO_ERROR_COLOR
                   <li>PRO_WARNING_COLOR
                   </ul>

    Output Arguments:
       None

    Return Values:
       Ignored.
*/

extern ProError ProPlotdriverLinefunctionSet (ProName interf_name,
                                              ProPlotdriverLinePlot function);
/* 
    Purpose:  Sets line plotting function.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       function     - Line plotting function. Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - function successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
       PRO_TK_GENERAL_ERROR - internal error.
*/


typedef ProError (*ProPlotdriverPolylinePlot) (ProAppData data,
                                               int n_points, Pro3dPnt *points, 
                                               int color, 
                                               ProLinestyle line_style, double line_width);

/*
    Purpose:  This is the generic function for plotting a polyline.

    Input Arguments:
       data       - The application data.
       n_points   - number of points,
       points     - Array of points.
       color      - Color index. The possible values are as follows:
                   <ul>
                   <li>PRO_LETTER_COLOR
                   <li>PRO_HIGHLITE_COLOR
                   <li>PRO_DRAWING_COLOR
                   <li>PRO_BACKGROUND_COLOR
                   <li>PRO_HALF_TONE_COLOR
                   <li>PRO_EDGE_HIGHLITE_COLOR
                   <li>PRO_DIMMED_COLOR
                   <li>PRO_ERROR_COLOR
                   <li>PRO_WARNING_COLOR
                   </ul>
       line_style - Line style.
       line_width - Line width.

    Output Arguments:
       None

    Return Values:
       Ignored.
*/

extern ProError ProPlotdriverPolylinefunctionSet (ProName interf_name,
                                                  ProPlotdriverPolylinePlot function);
/* 
    Purpose:  Sets polyline plotting function.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       function     - Polyline plotting function. Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - function successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
       PRO_TK_GENERAL_ERROR - internal error.
*/


typedef ProError (*ProPlotdriverPolygonPlot) (ProAppData data,
                                              int n_points, Pro3dPnt *points, 
                                              int color, 
                                              ProLinestyle line_style, double line_width);

/*
    Purpose:  This is the generic function for filling a polygon.

    Input Arguments:
       n_points   - number of points,
       points     - Array of points.
       color      - Color index. The possible values are as follows:
                   <ul>
                   <li>PRO_LETTER_COLOR
                   <li>PRO_HIGHLITE_COLOR
                   <li>PRO_DRAWING_COLOR
                   <li>PRO_BACKGROUND_COLOR
                   <li>PRO_HALF_TONE_COLOR
                   <li>PRO_EDGE_HIGHLITE_COLOR
                   <li>PRO_DIMMED_COLOR
                   <li>PRO_ERROR_COLOR
                   <li>PRO_WARNING_COLOR
                   </ul>
       line_style - Line style.
       line_width - Line width.
       data       - The application data.

    Output Arguments:
       None

    Return Values:
       Ignored.
*/

extern ProError ProPlotdriverPolygonfunctionSet (ProName interf_name,
                                                 ProPlotdriverPolygonPlot function);
/* 
    Purpose:  Sets polygon plotting function.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       function     - Polygon plotting function. Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - function successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
       PRO_TK_GENERAL_ERROR - internal error.
*/


typedef ProError (*ProPlotdriverCirclePlot) (ProAppData data,
                                             Pro3dPnt point, double radius, int color);

/*
    Purpose:  This is the generic function for plotting a circle.

    Input Arguments:
       data   - The application data.
       point  - Center of the circle.
       radius - Radius.
       color  - Color index. The possible values are as follows:
                   <ul>
                   <li>PRO_LETTER_COLOR
                   <li>PRO_HIGHLITE_COLOR
                   <li>PRO_DRAWING_COLOR
                   <li>PRO_BACKGROUND_COLOR
                   <li>PRO_HALF_TONE_COLOR
                   <li>PRO_EDGE_HIGHLITE_COLOR
                   <li>PRO_DIMMED_COLOR
                   <li>PRO_ERROR_COLOR
                   <li>PRO_WARNING_COLOR
                   </ul>

    Output Arguments:
       None

    Return Values:
       Ignored.
*/

extern ProError ProPlotdriverCirclefunctionSet (ProName interf_name,
                                                ProPlotdriverCirclePlot function);

/* 
    Purpose:  Sets line plotting function.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       function     - Circle plotting function. Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - function successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
       PRO_TK_GENERAL_ERROR - internal error.
*/


typedef ProError (*ProPlotdriverArcPlot) (ProAppData data,
                                          Pro3dPnt center, double radius,
                                          Pro3dPnt end1, Pro3dPnt end2,
                                          double t1, double t2,
                                          int color);

/*
    Purpose:  This is the generic function for plotting a circle.

    Input Arguments:
       data   - The application data.
       center - Center of the circle.
       radius - Radius.
       end1   - The starting point, defined as (X, Y, Z). The function
                ignores the Z value.
       end2   - The ending point, defined as (X, Y, Z). The function
                ignores the Z value.
       t1     - The start angle, in radians.
       t2     - The end angle, in radians.
       color  - Color index. The possible values are as follows:
                   <ul>
                   <li>PRO_LETTER_COLOR
                   <li>PRO_HIGHLITE_COLOR
                   <li>PRO_DRAWING_COLOR
                   <li>PRO_BACKGROUND_COLOR
                   <li>PRO_HALF_TONE_COLOR
                   <li>PRO_EDGE_HIGHLITE_COLOR
                   <li>PRO_DIMMED_COLOR
                   <li>PRO_ERROR_COLOR
                   <li>PRO_WARNING_COLOR
                   </ul>

    Output Arguments:
       None

    Return Values:
       Ignored.
*/

extern ProError ProPlotdriverArcfunctionSet (ProName interf_name,
                                             ProPlotdriverArcPlot function);
/* 
    Purpose:  Sets line plotting function.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       function     - Arc plotting function. Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - function successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
       PRO_TK_GENERAL_ERROR - internal error.
*/


typedef ProError (*ProPlotdriverTextPlot) (ProAppData data,
                                           Pro3dPnt point, ProLine text, double size, double angle,
                                           double slant_angle, double  width_factor, 
                                           int font_id, int color);

/*
    Purpose:  This is the generic function for plotting a text line.

    Input Arguments:
       data          - The application data. Can be NULL.
       point         - The starting point of the text, defined as
                       (X, Y, Z). The function should ignore the Z value.
       text          - The text line.
       size          - The character size. If this is less than or equal to
                       0, the function may use the default character size.
       angle         - The angle of the text, in degrees.
       slant_angle   - The angle of the characters, in degrees.
       width_factor  - The character width scale factor (character width
                       divided by character height)
       font_id       - The font identifier.
       color         - Color index. The possible values are as follows:
                   <ul>
                   <li>PRO_LETTER_COLOR
                   <li>PRO_HIGHLITE_COLOR
                   <li>PRO_DRAWING_COLOR
                   <li>PRO_BACKGROUND_COLOR
                   <li>PRO_HALF_TONE_COLOR
                   <li>PRO_EDGE_HIGHLITE_COLOR
                   <li>PRO_DIMMED_COLOR
                   <li>PRO_ERROR_COLOR
                   <li>PRO_WARNING_COLOR
                   </ul>

    Output Arguments:
       None

    Return Values:
       Ignored.
*/

extern ProError ProPlotdriverTextfunctionSet (ProName interf_name,
                                              ProPlotdriverTextPlot function);

/* 
    Purpose:  Sets line plotting function.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       function     - Text plotting function. Cannot be NULL.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR      - function successfully set.
       PRO_TK_BAD_INPUTS    - input arguments are not correct.
       PRO_TK_E_NOT_FOUND   - interface with this name not found.
       PRO_TK_GENERAL_ERROR - internal error.
*/


extern ProError ProPlotdriverExecute (ProName interf_name,
                                      ProAppData data);
/* 
    Purpose:  Executes the driver on the current object using plotting functions.

    Input Arguments:

       interf_name  - The name of the interface. Cannot be NULL.
       data         - The application data. Can be NULL.
                      This data is passed into plotting functions of this interface.

    Output Arguments:
       None

    Return Values:
       PRO_TK_NO_ERROR        - Function successfully executed.
       PRO_TK_BAD_INPUTS      - Name is NULL.
       PRO_TK_E_NOT_FOUND     - Interface with this name not found.
       PRO_TK_BAD_CONTEXT     - No current object found.
       PRO_TK_NOT_IMPLEMENTED - This interface does not work for this type of object.
       PRO_TK_INVALID_TYPE    - The current object has a type not supported by 
                                ProPlotdriver interfaces.
       PRO_TK_GENERAL_ERROR   - Internal error.
*/

PRO_END_C_DECLS

#endif /* PROPLOTDRIVER_H */
