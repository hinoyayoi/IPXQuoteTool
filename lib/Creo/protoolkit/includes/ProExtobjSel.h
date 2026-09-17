#ifndef PRO_EXTOBJSEL_H
#define PRO_EXTOBJSEL_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProExtobj.h>



PRO_BEGIN_C_DECLS

/* Creo Parametric TOOLKIT external object selection - related functions */


/* Selection data - related functions */

extern ProError ProSeldatAlloc (ProWExtobjdata *sel_data);
/*
   Purpose:     Allocates the memory for the selection data.

   Input Arguments:
      None
 
   Output Arguments:
      sel_data    - The pointer to the pointer to the selection data structure

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully allocated the
                                memory.  
        PRO_TK_GENERAL_ERROR  - The function could not allocate the memory.
*/

extern ProError ProSeldatSelboxesSet(ProWExtobjdata      sel_data, 
                                        ProSelbox          *sel_boxes,
                                        int                 box_num);
/*
   Purpose:     Sets the selection data with a list of selection boxes. The 
                selection boxes are specified in the local coordinates of 
                the external object. The transformation matrix of the
                display data transforms them to model coordinates. See
                the function <b>ProDispdatTrfSet()</b> for more information on
                the transformation.

   Input Arguments:
     sel_data          - The selection data

     sel_boxes         - The list of selection boxes 

     box_num           - The number of selection boxes

   Output Arguments:
     None

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully set the 
                                information.       
        PRO_TK_BAD_INPUTS     - One or more of the arguments are
                                invalid.
        PRO_TK_GENERAL_ERROR  - The function could not set the specified
                                information.

   See Also:
        ProDispdatTrfSet()   
*/


extern ProError ProSeldatSelboxesGet (ProWExtobjdata   sel_data,
                                        ProSelbox      **p_selbox_arr,
                                        int             *p_selbox_num);
/*
   Purpose:     Retrieves the selection box list and its length, given the
                selection data.

   Input Arguments:
     sel_data          - The selection data.

   Output Arguments:
     p_selbox_arr          - The allocated array of selection boxes.
                             Use <b>ProArrayFree()</b> to free the allocated memory.

     p_selbox_num          - The number of selection boxes.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.             
        PRO_TK_BAD_INPUTS     - The input argument is invalid. 
        PRO_TK_GENERAL_ERROR  - The function could not retrieve the
                                information.

   See Also:
        ProArrayFree() 
*/

PRO_END_C_DECLS

#endif /* PRO_EXTOBJSEL_H */

