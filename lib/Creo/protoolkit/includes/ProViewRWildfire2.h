

#ifndef PROVIEWRWILDFIRE2_H
#define PROVIEWRWILDFIRE2_H

/* Please note that this header file would be removed in a subsequent  release. */
#include	<ProView.h>

PRO_BEGIN_C_DECLS
extern ProError ProViewNamesGetRWildfire2 (ProMdl model, ProName** view_names, ProName** alternate_names, int* p_count);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: ProViewNamesGet
    Purpose: <p><b>Note:</b> This function is deprecated. Use ProViewNamesGet() instead. </p>
    
    	     Retrieves the names of the views in the specified model. Views in
             a drawing are predefined PAN/ZOOM locations of the drawing that
             are given a name. This is different from a drawing view.
             <P>To get a list of names of drawing views use the functions
             ProDrawingViewsCollect() and ProDrawingViewNameGet().

             This function is provided for users who don't wish to change their
             code to the new ProViewNamesGet. Note that using this may result
             in some view names being truncated.

    Input Arguments:
              model - The handle to a part, assembly, or drawing.

    Output Arguments:
              view_names      - The list of view names. You can pass NULL for 
                                this argument. The function allocates the 
                                memory for this argument. To free the memory, 
                                call <b>ProArrayFree()</b>.
              alternate_names - The list of alternate names. You can pass NULL
                                for this argument. The function allocates the
                                memory for this argument. To free the memory,
                                call<b>ProArrayFree()</b>.
              p_count         - The number of names in the <i>view_names</i> 
                                array.

   Return Values:
              PRO_TK_NO_ERROR      - The function successfully retrieved the
                                     information.
              PRO_TK_E_NOT_FOUND   - No view names were found for the
                                     specified model.
              PRO_TK_GENERAL_ERROR - A general error occurred and the
                                     function failed.

    See Also:
             ProArrayFree()
*/

PRO_END_C_DECLS

#endif
