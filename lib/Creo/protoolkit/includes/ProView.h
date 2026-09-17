
#ifndef PROVIEW_H
#define PROVIEW_H

#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef struct view* ProView;

typedef enum
{
   PRO_X_ROTATION = 101,
   PRO_Y_ROTATION = 102,
   PRO_Z_ROTATION = 103
} ProRotate;

/*===========================================================================*/

extern ProError ProViewMatrixGet (ProMdl model,
                                  ProView view_handle,
                                  ProMatrix matrix);
/*
   Purpose: Retrieves the transformation matrix for the specified view.
            This matrix provides the transformation from the object's
            coordinate system to logical screen coordinates.  This
            matrix does not contain any transformation for the members of an
            assembly.

   Input Arguments:
      model        - The handle to a part, assembly, or drawing.  If this is 
		     NULL, the function uses the current object.
      view_handle  - The view handle.  If the view is NULL, the function uses
                     the current view.

   Output Arguments:
      matrix - The view transformation matrix.

   Return Values:
      PRO_TK_NO_ERROR      - Function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
*/

extern ProError ProViewMatrixSet (ProMdl         model,
                                  ProView        view_handle,
                                  ProMatrix matrix);
/*
   Purpose: Sets the orientation of a model in a view.  The matrix argument
            specifies the transformation between model coordinates and screen
            coordinates. Each row of the matrix must have a length of 1.0,
            and the bottom row must be 0,0,0,1.
<p>
            Creo Parametric applies its own shift and scaling to the specified
            view matrix to ensure that the model fits properly into the view.
            Thus, subsequent calls to <b>ProViewMatrixGet()</b> don't return
            the original matrix, though its rotation will be the same.

<p>
            NOTE:
<p>
            You must normalize the matrix you pass to ProViewMatrixSet() so that
            it has no scaling or origin shift. ProViewMatrixSet() rejects 
            non-normalized matrices. See function UserMatrixNormalize. 

   Input Arguments:
      model         - The handle to part, assembly, or drawing.  If this is 
		      NULL, the function uses the current object.
      view_handle   - The view handle.  If the view is NULL, the function uses
                      the current view.
      matrix        - The view transformation matrix.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function successfully set the orientation. 
      PRO_TK_INVALID_MATRIX - The matrix is invalid or NULL.
      PRO_TK_BAD_INPUTS     - The specified object pointer is not a handle to a
                              part, assembly, or drawing.
*/

extern ProError ProViewReset (ProMdl model,
                              ProView view_handle);
/*
   Purpose:  Resets the view orientation to the default orientation.

   Input Arguments:
      model        - The handle to a part, assembly, or drawing, If the object 
		     is NULL, the function uses the current object.
      view_handle  - The handle to the view. If this is NULL, the function uses
		     the current view.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully reset the view. 
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProViewRotate (ProMdl model,
                               ProView view_handle,
                               ProRotate rotation_axis,
                               double angle);
/*
   Purpose: Rotates an object in the specified view with respect to
            the X-, Y-, or Z-axis.

   Input Arguments:
       model         - The object. If NULL, function uses the curren object.
       view_handle   - The view. If NULL, the function uses the current view.
       rotation_axis - The axis specification.
       angle         - The rotation angle, in degrees.

   Output Arguments:
       None

   Return Values:
      PRO_TK_NO_ERROR       - The function successfully rotated the object. 
      PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
*/

extern ProError ProViewStore (ProMdl model, 
                              ProLine view_name,
                              ProView* p_view);
/*
   Purpose:  Stores the current view in the specifed name.
             This is equivalent to the Creo Parametric command
	     View, Saved Views, Save.

   Input Arguments:
      model     - The handle to a part, assembly, or drawing. If this is NULL,
                  the function uses the current object.
      view_name - The name under which the view will be stored in the
                  object database.

   Output Arguments:
      p_view    - The handle to the view stored.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully stored the view. 
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
*/


extern ProError ProViewRetrieve ( ProMdl model,
                                  ProLine view_name, 
                                  ProView* p_view);
/*
   Purpose:  Retrieves the current view (the orientation) of the
             specified object, as stored under the given name.
             The function is equivalent to the Creo Parametric 
             View, Saved Views, Set. 

   Input Arguments:
      model     - The handle to a part, assembly, or drawing. If this is NULL,
                  the function uses the current object.
      view_name - The name of the view to be retrieved.

   Output Arguments:
      p_view    - The handle to the retrieved view.
      

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the view.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The function was unable to retrieve a view with
                             the specified name.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
*/

extern ProError ProViewNamesGet (ProMdl model, 
                                 ProLine** view_names,
                                 ProLine** alternate_names,
                                 int* p_count);
/*
   Purpose:  Retrieves the names of the views in the specified model.
             Views in a drawing are predefined PAN/ZOOM locations of
             the drawing that are given a name. This is different from
             a drawing view.
<P>
             To get a list of names of drawing views use the functions
             ProDrawingViewsCollect() and ProDrawingViewNameGet().

   Input Arguments:
      model -  The handle to a part, assembly, or drawing. 

   Output Arguments:
      view_names      - The list of view names. You can pass NULL for this
                        argument. The function allocates
                        the memory for this argument. To free the memory,
                        call <b>ProArrayFree()</b>. 
      alternate_names - The list of alternate names. You can pass NULL
                        for this argument. The function allocates the memory
                        for this argument. To free the memory, call
                        <b>ProArrayFree()</b>.
      p_count         - The number of names in the <i>view_names</i> array.

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



extern ProError ProViewNameToView (ProMdl model, 
                                   ProLine view_name, 
                                   ProView* p_view);
/*
   Purpose: Returns a pointer to the specified view, given the model 
            and view name.

   Input Arguments:
      model     - The handle to the model whose view you want to
                  find
      view_name - The view name

   Output Arguments:
      p_view    - The pointer to the view

   Return Values:

      PRO_TK_NO_ERROR       - The function successfully returned the 
                              information.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND    - A view was not found for the specified name.
      PRO_TK_INVALID_ITEM   - The specified view is not retrievable; e.g. the
      			      model is sheet metal at a certain stage of
			      bending or unbending.
      PRO_TK_GENERAL_ERROR  - A general error occurred and the 
                              function failed.
*/

extern ProError ProViewRefit(ProMdl model, ProView view);

/*
   Purpose: Refits the display of an object in the window specified 
            by the model and view. 
            The type of the object should be either drawing, part or  assembly.

   Input Arguments:
      model     - Handle to the object which is displayed in a window. The type
                  of  the object should be either drawing, part or assembly.
      view - Handle to the view used to display the object. 

   Output Arguments:
      None 

   Return Values:

      PRO_TK_NO_ERROR       - The function successfully refits the model to the
                              window.
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                              invalid. 
      PRO_TK_E_NOT_FOUND    - Either view  or model was not found.
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.
*/

extern ProError ProViewFromModelitemGet(ProModelitem *p_model_item, ProView *p_view);
/*
   Purpose: Retrieves the view handle from the model item handle

   Input Arguments:
      p_model_item     - The model item, must be of type PRO_VIEW.


   Output Arguments:
      p_view - Handle to the view 

   Return Values:

      PRO_TK_NO_ERROR       - The function succeeded
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                              invalid. 
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.
      PRO_TK_NOT_VALID      - View with id -1 was passed. This is the default view.
      			      
*/

extern ProError ProViewNameGet(ProView p_view, ProName p_name);
/*
   DEPRECATED: Since Creo 4.0
   SUCCESSORS: ProViewNameLineGet
   Purpose: This function is deprecated. Use ProViewNameLineGet() instead.
            Retrieves the view name.

   Input Arguments:
      p_view                - The view handle


   Output Arguments:
      p_name                - The view name

   Return Values:

      PRO_TK_NO_ERROR       - The function succeeded
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                              invalid. 
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.
      PRO_TK_E_NOT_FOUND    - The view did not have a name
      PRO_TK_NOT_VALID      - View with id -1 was passed. This is the default view.
      
*/

extern ProError ProViewIdFromNameGet(ProMdl model, ProName view_name, int *p_view_id);
/*
   DEPRECATED: Since Creo 4.0
   SUCCESSORS: ProViewIdFromNameLineGet
   Purpose: This function is deprecated. Use ProViewIdFromNameLineGet() instead.
            Retrieves the view id from model and view name

   Input Arguments:
      model                 -  The handle to a part, assembly, or drawing. Cannot be NULL.
      view_name             -  View name. Cannot be NULL.

   Output Arguments:
      p_view_id             -  View ID. Cannot be NULL.

   Return Values:

      PRO_TK_NO_ERROR       - The function succeeded
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                              invalid. 
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.
*/

extern ProError ProViewNameLineGet(ProView p_view, ProLine p_name);
/*
   Purpose: Retrieves the view name

   Input Arguments:
      p_view                - The view handle


   Output Arguments:
      p_name                - The view name

   Return Values:

      PRO_TK_NO_ERROR       - The function succeeded
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                              invalid. 
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.
      PRO_TK_E_NOT_FOUND    - The view did not have a name
      PRO_TK_NOT_VALID      - View with id -1 was passed. This is the default view.
      
*/

extern ProError ProViewIdFromNameLineGet(ProMdl model, ProLine view_name, int *p_view_id);
/*
   Purpose: Retrieves the view id from model and view name

   Input Arguments:
      model                 -  The handle to a part, assembly, or drawing. Cannot be NULL.
      view_name             -  View name. Cannot be NULL.

   Output Arguments:
      p_view_id             -  View ID. Cannot be NULL.

   Return Values:

      PRO_TK_NO_ERROR       - The function succeeded
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                              invalid. 
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.
*/


PRO_END_C_DECLS

#endif /* PROVIEW_H */
