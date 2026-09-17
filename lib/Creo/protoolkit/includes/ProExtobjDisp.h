#ifndef PRO_EXTOBJDISP_H
#define PRO_EXTOBJDISP_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProExtobj.h>
#include <ProColor.h>




PRO_BEGIN_C_DECLS

/* Creo Parametric TOOLKIT external object display - related functions */

typedef enum
{
   PRO_EXTOBJ_ZOOM_INVARIANT  = 1,
   PRO_EXTOBJ_SPIN_INVARIANT  = 2,
   PRO_EXTOBJ_BLANKED         = 3,
   PRO_EXTOBJ_ZBUFFERED       = 4
} ProExtobjDispprops;


/* Display data - related functions */

extern ProError ProDispdatAlloc (ProWExtobjdata *disp_data);
/*
   Purpose:     Initializes the display data structure.

   Input Arguments:
      disp_data          - The display data

   Output Arguments:
      None 

   Return Values:
        PRO_TK_NO_ERROR       -  The function successfully initialized the
                                 structure.
        PRO_TK_BAD_INPUTS     -  The input argument is invalid.
        PRO_TK_GENERAL_ERROR  -  The function could not initialize the
                                 structure.
*/

extern ProError ProDispdatTrfSet  (ProWExtobjdata   disp_data,
                                   ProMatrix        trf);
/*
   Purpose:     Sets the transformation matrix to the display data.
                This matrix is used to transform entities and selection boxes 
                from the local coordinates of the external object to
                model coordinates. Its origin is used to figure out 
                the proper display of spin- and zoom-invariant entities.


   Input Arguments:
      disp_data          - The display data

      trf                - The transformation matrix

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR       -  The function successfully set the data.
      PRO_TK_BAD_INPUTS     -  One or more of the arguments are
                               invalid.
      PRO_TK_GENERAL_ERROR  -  The function could not set the data.
*/

extern ProError ProDispdatTrfGet (ProWExtobjdata   disp_data,
                                  ProMatrix        trf);
/*
   Purpose:  Retrieves the transformation matrix, given the display data.

   Input Arguments:
      disp_data         - The display data

   Output Arguments:
      trf               - The transformation matrix 
 

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully retrieved the
                               information.
      PRO_TK_GENERAL_ERROR -   The function could not retrieve the
                               information.
*/


extern ProError ProDispdatEntsSet (ProWExtobjdata  disp_data,
                                  ProCurvedata   *entities,
                                  int             num_ents);
/*
   Purpose:     Sets the display data for a list of entities. The
                entities are specified in the local coordinates of 
                the external object. To transform them to model
                coordinates, use the <i>disp_data</i> transformation matrix
                (see the function <b>ProDispdatTrfSet()</b>).

		NOTE: The only entities for which this is supported are
		PRO_ENT_LINE and PRO_ENT_ARC. (Polygons may be drawn as
		multiple lines, and circles as arcs of extent 2 * pi.)

   Input Arguments:
      disp_data          - The display data
 
      entities           - The list of entities

      num_ents           - The length of the list of entities

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully set the display data.
      PRO_TK_BAD_INPUTS    -   One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR -   The entity was not found, or the function
                               could not set the data.

   See Also:
      ProDispdatTrfSet()

*/

extern ProError ProDispdatEntsGet (ProWExtobjdata   disp_data,
                                   ProCurvedata   **entities,
                                   int             *num_ents);
/*
   Purpose:     Retrieves the list of entities, given the display data.

   Input Arguments:
      disp_data          - The display data.

   Output Arguments:
      entities           - The list of entities. Use <b>ProCurvedataArrayFree()</b>
                           to release the memory.

      num_ents           - The length of the list of entities.
 
   Return Values:
      PRO_TK_NO_ERROR      -  The function successfully retrieved the
                              information.
      PRO_TK_BAD_INPUTS    -  The input argument is invalid.
      PRO_TK_GENERAL_ERROR -  The entity was not found, or the function
                              could not retrieve the information.

   See Also:
      ProCurvedataArrayFree()
*/

extern ProError ProCurvedataArrayFree (ProCurvedata    **entities,
                                       int               num_ents);
/*
   Purpose:  Frees the memory used by the specified list of entities.

   Input Arguments:
      entities           - The address to the list of entities

      num_ents           - The length of the list of entities 

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR      -  The memory was freed successfully.
        PRO_TK_BAD_INPUTS    -  One or more of the arguments invalid.
        PRO_TK_GENERAL_ERROR -  The function could not free the memory.
*/


extern ProError ProDispdatScaleSet (ProWExtobjdata disp_data, 
                                    double         scale);
/*
   Purpose:     Sets the scale for the display data.

   Input Arguments:
      disp_data            - The display data
 
      scale                - The scale

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully set the scale.
      PRO_TK_BAD_INPUTS    -   One or more of the arguments are
                               invalid.
      PRO_TK_GENERAL_ERROR -   The function could not set the scale.
*/

extern ProError ProDispdatScaleGet (ProWExtobjdata disp_data, 
                                    double         *p_scale);
/*
   Purpose:     Retrieves the scale for the display data.

   Input Arguments:
      disp_data          - The display data
 
   Output Arguments:
      p_scale            - The scale

   Return Values:
      PRO_TK_NO_ERROR       -  The function successfully retrieved the
                               information.
      PRO_TK_BAD_INPUTS     -  The input argument is invalid.
      PRO_TK_GENERAL_ERROR  -  The function could not retrieve the
                               information.
*/

extern ProError ProDispdatPropsSet (ProWExtobjdata      disp_data,
                                    ProExtobjDispprops *properties,
                                    int                 prop_num);
/*
   Purpose:     Sets the properties for the display data.

   Input Arguments:
     disp_data         - The display data
 
     properties        - The properties

     prop_num          - The number of properties

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully set the properties.
      PRO_TK_BAD_INPUTS    -   One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR -   The function could not set the properties.
*/

extern ProError ProDispdatPropsGet (ProWExtobjdata       disp_data,
                                    ProExtobjDispprops **properties,
                                    int                 *prop_num);
/*
   Purpose:     Retrieves the properties of the display data.

   Input Arguments:
      disp_data      - The display data.

   Output Arguments:
     properties      - The array of display properties. The array is
                       allocated by the function. Use <b>ProArrayFree()</b>
                       to free the allocated memory.

     prop_num        - The number of properties.


   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully retrieved the
                               information.
      PRO_TK_BAD_INPUTS    -   The input argument is invalid.
      PRO_TK_GENERAL_ERROR -   The function could not retrieve the data.

   See Also:
      ProArrayFree()
*/


extern ProError ProDispdatColorSet (ProWExtobjdata disp_data,
                                    ProColortype   color);
/*
   Purpose:     Sets the color for the display data.

   Input Arguments:
     disp_data           - The display data

     color               - The color

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully set the color.
      PRO_TK_BAD_INPUTS    -   One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR -   The function could not set the color.
*/

extern ProError ProDispdatColorGet (ProWExtobjdata disp_data,
                                    ProColortype   *p_color);
/*
   Purpose:     Retrieves the display color.
 
   Input Arguments:
      disp_data           - The display data

   Output Arguments:
      p_color             - The color

   Return Values:
      PRO_TK_NO_ERROR       -  The function successfully retrieved the 
                               information.
      PRO_TK_BAD_INPUTS     -  The input argument is invalid.
      PRO_TK_GENERAL_ERROR  -  The function could not retrieve the
                               information.
*/

extern ProError ProDispdatLinestyleSet (ProWExtobjdata disp_data,  
                                        ProLinestyle   line_style);
/*
   Purpose:     Sets the line style for the display data.

   Input Arguments:
     disp_data           - The display data

     line_style          - The line style

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully set the line style.
      PRO_TK_BAD_INPUTS    -   One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR -   The function could not set the line style.
*/

extern ProError ProDispdatLinestyleGet (ProWExtobjdata disp_data, 
                                        ProLinestyle   *p_line_style);
/*
   Purpose:     Retrieves the display line style.

   Input Arguments:
      disp_data           - The display data

   Output Arguments:
      p_line_style        - The line style

   Return Values:
      PRO_TK_NO_ERROR       -  The function successfully retrieved the
                               information.
      PRO_TK_BAD_INPUTS     -  The input argument is invalid.
      PRO_TK_GENERAL_ERROR  -  The function could not retrieve the
                               information.
*/

extern ProError ProExtobjScreentrfGet (ProExtobj    *object,
                                       ProMatrix    trf);

/*
   Purpose:  Retrieves the screen transformation.
   <p><b>Note: </b>In the assembly mode, ProExtobjScreentrfGet() is applicable
   for external objects owned only by the top assembly model. However, in the
   part mode, this function is applicable for all objects. 

   Input Arguments:
      object         - The external object
     
   Output Arguments:
      trf            - The transformation matrix

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_GENERAL_ERROR - The function could not retrieve the
                             information.
*/
extern ProError ProDispdatEntsWithColorSet (ProWExtobjdata  disp_data,
                         			ProCurvedata    **entities,
                                                ProColortype    *colors);
/*
   Purpose:     Sets the display data for a list of entities and the color 
   		for each entity. The entities are specified in the local 
                coordinates of the external object. To transform them to 
                model coordinates, use the <i>disp_data</i> transformation 
                matrix (see the function <b>ProDispdatTrfSet()</b>).

		NOTE: The only entities for which this is supported are
		PRO_ENT_LINE and PRO_ENT_ARC. (Polygons may be drawn as
		multiple lines, and circles as arcs of extent 2 * pi.)


   Input Arguments:
      disp_data - The display data.
      entities  - ProArray of pointers to ProCurvedata allocated by the user.
      colors    - Corresponding ProArray of colors (ProColortype) allocated by the user.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR      -   The function successfully set the display data.
      PRO_TK_BAD_INPUTS    -   One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR -   The entity was not found, or the function
                               could not set the data.
*/

PRO_END_C_DECLS
 
#endif /* PRO_EXTOBJDISP_H */
