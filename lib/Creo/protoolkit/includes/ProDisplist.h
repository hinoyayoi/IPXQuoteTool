

#ifndef PRODISPLIST_H
#define PRODISPLIST_H

#include <ProObjects.h>


typedef ProError (*ProDisplistCallback) ( void* arg1,
                                          void* arg2,
                                          void* arg3,
                                          void* arg4,
                                          void* arg5,
                                          void* arg6);


/*
   Purpose: This is the user display function that gets called when
            you create a display list.

   Input Arguments:
      arg1 - User data <i>arg1</i> passed to <b>ProDisplist2dCreate()</b> or  
             <b>ProDisplist3dCreate()</b>
      arg2 - User data <i>arg2</i> passed to <b>ProDisplist2dCreate()</b> or 
             <b>ProDisplist3dCreate()</b>
      arg3 - User data <i>arg3</i> passed to <b>ProDisplist2dCreate()</b> or
             <b>ProDisplist3dCreate()</b>
      arg4 - User data <i>arg4</i> passed to <b>ProDisplist2dCreate()</b> or
             <b>ProDisplist3dCreate()</b>
      arg5 - User data <i>arg5</i> passed to <b>ProDisplist2dCreate()</b> or
             <b>ProDisplist3dCreate()</b>
      arg6 - User data <i>arg6</i> passed to <b>ProDisplist2dCreate()</b> or
             <b>ProDisplist3dCreate()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR  - The function was successful. 
*/

PRO_BEGIN_C_DECLS

/*===========================================================================*/
extern ProError ProDisplist2dCreate (
#ifdef PRO_USE_VAR_ARGS
                                                 int       id,
                                                 ProMatrix transform,
                                                 ProDisplistCallback function,
                                                 ...
#endif
                                                 );

/*
   Purpose: Creates a 2-D display list using the specified user-supplied
            create function.
<p>
            NOTES: 
<p>
            <ul>
            <li> A typical user-supplied create function would call the
                 Creo Parametric TOOLKIT graphics functions.
            <li> A view must be present for display list creation. To
                 do this, retrieve an empty part, assembly, or drawing 
                 file during the session.
            <li>The display is not stored with the model.
            </ul>
  
   Input Arguments:
      id               - The unique identifier of the display list 
                         to be created.
      transform        - The transformation matrix to be applied to the points
                         of the display list.
      function         - The user-defined function that calls graphics
                         functions to create a display list.  It must
                         return PRO_TK_NO_ERROR if successful, and non-zero
                         for error.
      ...              - The arguments to the user-supplied function.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR  - The function successfully created the 2-D display
                         list. 
      Other            - Any other value is the status returned by the 
                         user create function.
*/
 
extern ProError ProDisplist2dDisplay (int id, 
                                      ProMatrix transform);
/*
   Purpose: Displays the 2-D display list using the specified transformation
            matrix.

   Input Arguments:
      id        - The identifier of the display list to be drawn.
      transform - The transformation matrix to be used with the display list.
                  This matrix should be similar to the one used when
                  creating the display list (that is, only translation and 
                  scaling can be changed).

   Output Arguments:
      None
   
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully displayed the 
                             2-D display list. 
      PRO_TK_NOT_EXIST     - The display list is empty.
      PRO_TK_E_NOT_FOUND   - The function could not find a display list 
                             with the specified identifier.
      PRO_TK_CANT_OPEN     - The use of display lists is disabled.
      PRO_TK_ABORT         - The display was aborted.
      PRO_TK_NOT_VALID     - The specified display list is invalid.
      PRO_TK_INVALID_ITEM  - There is an invalid item in the display list.
      PRO_TK_GENERAL_ERROR - The specified display list is already in the 
                             process of being displayed. 
*/

extern ProError ProDisplist2dDelete ( int id );
/*
   Purpose: Deletes the specified display list.

   Input Arguments:
      id            -  The identifier of the display list to delete
    
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully deleted the display list. 
      PRO_TK_E_NOT_FOUND - The function could not find a display list with 
                           the specified identifier. 
*/

extern ProError ProDisplist3dCreate (
#ifdef PRO_USE_VAR_ARGS
                                                 int                 id,
                                                 ProDisplistCallback function,
                                                 ...
#endif
                                                 );
/*
   Purpose: Creates a 3-D display list using the specified user-supplied
            create function.
<p>
            NOTES: 
<p>
            <ul>
            <li>A typical user-supplied create function would call the
              Creo Parametric TOOLKIT graphics functions.
            <li>A view must be present for display list creation. To
              do this, retrieve an empty part, assembly, or drawing file
              during the session.
            <li>The display is not stored with the model.
            </ul>

   Input Arguments:
      id               - The unique identifier of the display list
                         to be created. 
      function         - The user-defined function that calls appropriate
                         graphics functions to create a display list.
                         It must return PRO_TK_NO_ERROR if successful, and 
                         non-zero for error.
      ...              - The arguments to the user-defined function.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR  - The function successfully created the 3-D display
                         list.
      Other            - Any other value is the status returned by the user 
                         create function.
*/


extern ProError ProDisplist3dDisplay (int       id,
                                      ProMatrix transform);

/*
   Purpose: Displays the 3-D display list using the specified transformation
            matrix.

   Input Arguments:
      id        - The identifier of the display list to be drawn
      transform - The transformation matrix to be used with the display list

   Output Arguments:
      None
   
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully displayed the 
                             3-D display list.
      PRO_TK_NOT_EXIST     - The display list is empty.
      PRO_TK_E_NOT_FOUND   - The function could not find a display list with 
                             the specified identifier.
      PRO_TK_CANT_OPEN     - The use of display lists is disabled.
      PRO_TK_ABORT         - The display was aborted.
      PRO_TK_NOT_VALID     - The specified display list is invalid.
      PRO_TK_INVALID_ITEM  - There is an invalid item in the display list.
      PRO_TK_GENERAL_ERROR - The specified display list is already in the 
                             process of being displayed.
*/


extern ProError ProDisplist3dDelete ( int id );
/*
   Purpose: Deletes the specified display list.

   Input Arguments:
      id -  The identifier of the display list to delete
    
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully deleted the display list.
      PRO_TK_E_NOT_FOUND - The function could not find a display list with 
                           the specified identifier. 
*/

extern ProError ProDisplistInvalidate ( ProMdl model );
/*
   Purpose: Invalidates the two- or three-dimensional display list.

   Input Arguments:
      model - The handle to a part, assembly, or drawing

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully invalidated the 
                             display list. 
      PRO_TK_INVALID_TYPE  - The specified model is not a part, assembly, 
                             or drawing.
      PRO_TK_NOT_EXIST     - The function cannot find the window associated 
                             with the object. 
      PRO_TK_GENERAL_ERROR - The function cannot find the name of the object.
*/

PRO_END_C_DECLS

#endif

