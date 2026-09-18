

#ifndef PROWINDOW_H
#define PROWINDOW_H

#include <ProToolkit.h>
#include <ProSizeConst.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

extern ProError ProWindowSizeGet (int win_id, 
                                  double *width, double *height);

/*
  Purpose: Returns the size of the Creo Parametric window.
           The size is normalized to values from 0 to 1.
           This is the size of the window including the dialog.

  Input Arguments:
     win_id - The identifier of the Creo Parametric window

  Output Arguments:   
    width   - The width of the window
    height  - The height of the window

  Return Values:   
     PRO_TK_BAD_INPUTS - The function could not find the size of the
                         specified window.
     PRO_TK_NO_ERROR   - The function successfully returned values.
*/

extern ProError  ProGraphicWindowSizeGet (int win_id, 
                                          double *width, double *height);

/*
  Purpose: Returns the size of the Creo Parametric graphics window.
           The size is normalized to values from 0 to 1.
           This is the size of the window without the border.

  Input Arguments:
     win_id - The identifier of the Creo Parametric window

  Output Arguments:   
    width   - The width of the window
    height  - The height of the window

  Return Values:   
     PRO_TK_BAD_INPUTS - The function could not find the size of the
                         specified window.
     PRO_TK_NO_ERROR   - The function successfully returned values.
*/

extern ProError ProWindowPositionGet (int win_id, 
                                      double *x, double *y);

/*
   Purpose:  Returns the position of the upper, left corner of
             the Creo Parametric window dialog from the upper, left corner
             of the screen.
             The position is normalized to values from 0 to 1.

   Input Arguments:    
      win_id - The identifier of the Creo Parametric window
 
   Output Arguments:   
      x - The X position of the window, normalized between 0 and 1
      y - The Y position of the window, normalized between 0 and 1
   
   Return Values:   
      PRO_TK_BAD_INPUTS - The function could not return the position 
                          of the specified window.
      PRO_TK_NO_ERROR   - The function successfully returned the values.
*/

extern ProError ProWindowClear ( int window_id );
/*
   Purpose: Clears the Creo Parametric window. 
            The function temporarily removes all graphics from the
            window until you call one of the drawing functions, such as
            <b>ProSolidDisplay()</b>.

   Input Arguments: 
      window_id  -  The identifier of the window to be cleared.
                    If this argument is PRO_VALUE_UNUSED, the function 
                    clears the current window.
 
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully cleared the window.    
      PRO_TK_BAD_INPUTS - The argument is invalid.

   See Also:
      ProSolidDisplay()
*/

extern ProError ProWindowRepaint ( int window_id );
/*
   Purpose: Is the equivalent of the Creo Parametric command View, Repaint.  
            This function enables you to perform several operations
            and update the view when necessary.

   Input Arguments:
      window_id -  The identifier of the window to be cleared.
                   If this argument is PRO_VALUE_UNUSED, the function clears
                   the current window.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully repainted the window. 
      PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProWindowRefresh ( int window_id );
/*
   Purpose:  Refreshes the screen.  The function does not clear
             highlights.  This is the most efficient function to use if you
             want to clear "temporary" graphics only (that is, graphics
             that you have inserted into a 2-D or 3-D display list).

   Input Arguments:
      window_id -  The identifier of the window to be cleared.
                   If this argument is PRO_VALUE_UNUSED, the function redraws
                   the current window.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully refreshed the window.
      PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProWindowCurrentGet ( int* p_window_id );
/*
   Purpose:  Retrieves the current window identifier.

   Input Arguments:
      None

   Output Arguments:
      p_window_id - The current window identifier.  If the current window is
                    the message area, the function returns PRO_VALUE_UNUSED.
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the 
                             information. 
      PRO_TK_BAD_INPUTS    - The window identifier is NULL.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function
                             failed.
*/

extern ProError ProWindowCurrentSet ( int window_id );
/*
   Purpose:  Sets the current window to the one specified by the
             <i>window_id</i> argument.
<p>
             NOTE:
<p>
             This function is <i>not</i> equivalent to the Creo Parametric option
             to change the window, and has no effect on the object returned
             by <b>ProMdlCurrentGet()</b>.

   Input Arguments:
      window_id - The identifier of the window that becomes current

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully set the window to be
                          current. 
      PRO_TK_BAD_INPUTS - The argument is invalid.

   See Also:
      ProMdlCurrentGet()
*/

extern ProError ProObjectwindowCreate (ProName object_name,
                                       ProType object_type,
                                       int* p_window_id);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProObjectwindowMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProObjectwindowMdlnameCreate instead.

             Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.
<p>
             NOTE:
<p>
             This function should be used <b>only</b> when the application
             must display more than one object simultaneously. Under normal
             circumstances, use ProMdlDisplay() to show an object in the
             current or base window.

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY, 
                    and so on)

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.  
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
      PRO_TK_E_DEADLOCK   - The Creo Parametric user interface is not prepared
                            to handle this request (because it is blocked by
                            another process such as an OLE container activation).
*/

extern ProError ProObjectwindowMdlnameCreate (ProMdlName object_name,
                                              ProType object_type,
                                              int* p_window_id);
/*
   Purpose:  Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.
<p>
             NOTE:
<p>
             This function should be used <b>only</b> when the application
             must display more than one object simultaneously. Under normal
             circumstances, use ProMdlDisplay() to show an object in the
             current or base window.
             This function should be used on model present in the session.             

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY, PRO_CATIA_PART,
                    PRO_SW_ASSEM and so on)

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.  
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
      PRO_TK_E_DEADLOCK   - The Creo Parametric user interface is not prepared
                            to handle this request (because it is blocked by
                            another process such as an OLE container activation).
	  PRO_TK_E_NOT_FOUND  - The application is trying to open an embedded model 
                            (that is, a model representing a single body of a multi-body foreign object)
                            in a separate window. This operation is not supported.

*/

extern ProError ProAccessorywindowCreate (ProName object_name,
                                          ProType object_type,
                                          int* p_window_id);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProAccessorywindowWithTreeMdlnameCreate
   Purpose:  <B>Note:</B> This function is deprecated. 
             Use ProAccessorywindowWithTreeMdlnameCreate() with tree_flag as 
             PRO_B_FALSE instead.

             <p>
             Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.

             The window created is smaller than the one created by
             ProObjectwindowMdlnameCreate().  This window doesn't have the toolbar
             and model tree. It doesn't allow any options and has restricted
             options under Windows menu.
          

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY,
                    and so on)

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
*/

extern ProError ProAccessorywindowWithTreeCreate (ProName object_name,
                                                  ProType object_type,
                                                  ProBoolean tree_flag,
                                                  int* p_window_id);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProAccessorywindowWithTreeMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProAccessorywindowWithTreeMdlnameCreate instead.

             Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.

             The window created is smaller than the one created by
             ProObjectwindowMdlnameCreate().  This window doesn't have the toolbar.
             It doesn't allow any options and has restricted options under 
             Windows menu.
        

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY,
                    and so on)
      tree_flag   - if PRO_B_TRUE enables model tree or disables otherwise.

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
*/

extern ProError ProAccessorywindowWithTreeMdlnameCreate (ProMdlName object_name,
                                                         ProType object_type,
                                                         ProBoolean tree_flag,
                                                  int* p_window_id);
/*
   Purpose:  Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.

             The window created is smaller than the one created by
             ProObjectwindowMdlnameCreate().  This window doesn't have the toolbar.
             It doesn't allow any options and has restricted options under 
             Windows menu.
<p>
             NOTE:
<p>             
             This function should be used on model present in the session.
        
			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY, PRO_CATIA_PART,
                    PRO_SW_ASSEM and so on)
      tree_flag   - if PRO_B_TRUE enables model tree or disables otherwise.

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
	  PRO_TK_E_NOT_FOUND  - The application is trying to open an embedded model 
                            (that is, a model representing a single body of a multi-body foreign object)
                            in a separate window. This operation is not supported.
*/

extern ProError ProBarewindowCreate (ProName object_name,
                                     ProType object_type,
                                     int* p_window_id);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProBarewindowMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProBarewindowMdlnameCreate instead.

             Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.

             The window created doesn't have any toolbars or menus. It
             can be minimized or closed and it has all the regular 
             mouse-driven view capabilites like zoom, rotation and panning.

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY,
                    and so on)

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
*/

extern ProError ProBarewindowMdlnameCreate (ProMdlName object_name,
                                            ProType object_type,
                                            int* p_window_id);
/*
   Purpose:  Retrieves a window and attaches the object to it.
             If the window is already open with the object attached,
             the function returns the window identifier.  If there is an
             empty window up, the function attaches the object to it.
             Otherwise, the function creates a new window and attaches
             the object to it.

             The window created doesn't have any toolbars or menus. It
             can be minimized or closed and it has all the regular 
             mouse-driven view capabilites like zoom, rotation and panning.
<p>
             NOTE:
<p>             
             This function should be used on model present in the session.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      object_name - The name of the object to be retrieved
      object_type - The type of the object (PRO_PART, PRO_ASSEMBLY, PRO_CATIA_PART,
                    PRO_SW_ASSEM and so on)

  Output Arguments:
      p_window_id - The window identifier in which the object was retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the window
                            and attached the object to it.
      PRO_TK_INVALID_TYPE - You specified an invalid object type.
      PRO_TK_BAD_INPUTS   - Either you specified an invalid object name,
                            or the window identifier is NULL.
	  PRO_TK_E_NOT_FOUND  - The application is trying to open an embedded model 
                            (that is, a model representing a single body of a multi-body foreign object)
                            in a separate window. This operation is not supported.
*/

extern ProError ProWindowDelete ( int window_id );
/*
   Purpose:  Closes a window and breaks the object-to-window attachment.
             The function deletes the window, if it is not the base window.
<p>
             You cannot break the attachment for the currently active window.
             Use the function <b>ProWindowCurrentSet()</b> to make a different 
             window be the active window before calling this function.
<p>
             This function is equivalent to the Creo Parametric option 
             to quit the window.

   Input Arguments:
      window_id - The window to delete

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully deleted the window. 
      PRO_TK_BAD_INPUTS    - The argument is invalid.
      PRO_TK_BAD_CONTEXT   - The window you are trying to delete is the
                             current window.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
 
   See Also:
      ProWindowCurrentSet()   
*/

extern ProError ProAccessorywindowAboveactivewindowSet(
  int  window_id,
  ProBoolean above_active_window);
/*
    Purpose:  Sets the accessory window to be always above the dialog which
              is the current active Creo Parametric window.
              This allows the Creo Parametric TOOLKIT application to ensure
              that their dialog does not end up behind the Creo Parametric
              window during window opening and closing events.

    Input Arguments: 
         window_id           - The window id.
         above_active_window - PRO_B_TRUE to set it to be above the current 
                               active window, PRO_B_FALSE to remove this 
                               setting.

    Output Arguments: 
         none

    Return Values:
         PRO_TK_NO_ERROR     - The function succeeded.
         PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
*/

extern ProError ProWindowCurrentMatrixGet ( ProMatrix matrix );
/*
   Purpose:  Retrieves the pan and zoom matrix of the current window.

   Input Arguments:
      None

   Output Arguments:
      matrix - The pan and zoom matrix

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The matrix is NULL.
      PRO_TK_BAD_CONTEXT - There is no current window.
*/

typedef ProError (*ProWindowVisitAction) (int  window_id,
                                          ProAppData data);
/*
   Purpose:  This is the user-supplied callback function 
             invoked for each Creo Parametric window.

   Input Arguments:
      window_id - The identifier of the Creo Parametric window being visited  
      data      - The application data

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR -  Continue visiting.
      Other           -  Stop visiting and propagate this
                         error.
*/

extern ProError ProWindowsVisit (ProWindowVisitAction  visit_func,
                                 ProAppData            app_data);
/*

   Purpose: Visits all the Creo Parametric windows.  

   Input Arguments:
       visit_func - The function invoked for each Creo Parametric window 
       app_data   - The application data

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully visited all the Creo Parametric
                          windows.
      Other             - An error was encountered and visiting stopped. 
*/

extern ProError ProWindowMdlGet (int  window, 
                                 ProMdl    *r_mdl);

/*
   Purpose:  Retrieves the Creo Parametric model that owns the specified window.

   Input Arguments:

      window - The handle to the Creo Parametric window 

   Output Arguments:

      r_mdl  - The model that owns the window

   Return Values:

      PRO_TK_BAD_INPUTS - The specified window handle is invalid.
      PRO_TK_NO_ERROR   - The function returned the model.
*/

extern ProError ProWindowPanZoomMatrixSet(int window, 
                                          ProMatrix Matrix);
/*
   Purpose:  Sets the matrix for the current window.

   Input Arguments:
      window - The handle to the Creo Parametric window 
      Matrix - The matrix to set

   Output Arguments:
      None

   Return Values:
      PRO_TK_BAD_INPUTS - The specified window handle is invalid.
      PRO_TK_NO_ERROR   - The function successfully set the matrix.
*/


extern ProError ProWindowActivate( int window );

/*
   Purpose: Activates the specified window.
            <p>
            NOTES:
            <p>
            This does not take effect until control returns to Creo Parametric.
            <p>
            This function works in asynchronous graphic mode only.
            <p>When a call is made to this function, 
            the control should be returned to Creo Parametric 
            to activate the current window.</p>

   Input Arguments:
      window - The handle to the Creo Parametric window

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully activated the window.
      PRO_TK_BAD_INPUTS    - The input argument is invalid.
      PRO_TK_BAD_CONTEXT   - The function was called in RPC input (non-graphic)
                             mode
      PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProWindowCurrentClose( void );

/*
   Purpose: Closes the currently active window.
            This function duplicates the behavior of the 
            Close pick on the Window
            pull-down menu from the menu bar.
            <p>
            If the current window is the original window created when
            Creo Parametric started, the function clears the window. Otherwise, 
            the function removes the window from the screen.
            <p>
            NOTES:
            <ul>
            <li>Any work done since the last save will be lost.
            <li>This function does not take effect until control returns to 
                Creo Parametric.
            <li>When a call is made to this function, 
            the control should be returned to Creo Parametric 
            to close the current window.
            </ul>

   Input Arguments:
      None

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully activated the window.
      PRO_TK_GENERAL_ERROR - The function failed.
      PRO_TK_E_DEADLOCK   - The Creo Parametric user interface is not prepared
                            to handle this request (because it is blocked by
                            another process such as an OLE container activation).
*/


extern ProError ProWindowRefit(int window_id); 

/*
   Purpose: Refits the display of an  object in the window 
            specified by the window_id.
            The type of the object should be either drawing, part or assembly.  

   Input Arguments:
      window_id          -  The handle to the Creo Parametric window. 
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    -  The function successfully refits the model to the
                              window.
      PRO_TK_BAD_INPUTS  -  The window does not contain valid object or view. 
      PRO_TK_E_NOT_FOUND -  Either view  or model was not found.
*/

extern  ProError ProWindowURLShow (int window_id,  wchar_t* url );
/*
   Purpose: Set the URL displayed in the window's embedded browser.
 
   Input Arguments:
        window_id - The window identifier (containing the embedded
         browser)
        url - The URL to display in the embedded browser.
 
   Output Arguments:
        none
 
   Return Values:
 
   PRO_TK_NO_ERROR - The function retrieved the information.
   PRO_TK_GENERAL_ERROR - The function failed.
   PRO_TK_BAD_INPUTS - The window identifier was invalid.
*/
 
extern  ProError ProWindowURLGet ( int window_id , wchar_t **url );
/*
   Purpose: Get the URL displayed in the window's embedded browser.
 
   Input Arguments:
        window_id - The window identifier (containing the embedded
           browser)
 
   Output Arguments:
        url - The URL displayed in the embedded browser.

              NULL if the browser has not loaded a page yet
              Free this string using ProWstringFree() .
 
   Return Values:
 
   PRO_TK_NO_ERROR - The function retrieved the information.
   PRO_TK_BAD_INPUTS - The window identifer was invalid.
   PRO_TK_GENERAL_ERROR - The function failed .
*/
 
 
extern ProError ProWindowBrowserSizeGet ( int window_id ,
    double *percent );
/*
    Purpose:  Get information about the visible size of the embedded
          browser in this window.
    <p><b>NOTE: </b>Not applicable if browser is open in separate window.
 
    Input Arguments:
        window_id - The window identifier (containing the embedded
             browser)
 
    Output Arguments:
        percent - The percent of the Creo Parametric window covered by the
             browser, from 0.0 (the window is minimized)
             to 100.0 (the window covers the entire window)
 
    Return Values:
 
    PRO_TK_NO_ERROR - The function returned the information.
    PRO_TK_BAD_INPUTS - Invalid window identifier specified.
    PRO_TK_GENERAL_ERROR - The function failed  
*/
 
extern ProError ProWindowBrowserSizeSet ( int window_id ,
   double percent );
/*
    Purpose:  Set the visible size of the embedded browser
              in this window.
    <p><b>NOTE: </b>Not applicable if browser is open in separate window.
 
    Input Arguments:
    window_id - The window identifier (containing the embedded browser)
    percent - The percent of the Creo Parametric window covered by the
              browser, from 0.0 (the window is minimized) to 100.0
              (the window covers the entire window)
 
    Output Arguments:
    none
 
    Return Values:
    PRO_TK_NO_ERROR - The function set the value.
    PRO_TK_BAD_INPUTS - Invalid window identifier or percentage
        specified.
    PRO_TK_GENERAL_ERROR - The function failed .
*/     
 

typedef ProError (*ProWindowOccupyPostAction) (int win_id);
/*
    Purpose: This is the notification function called after a model has been loaded into a Creo Parametric Window.
             <p> The user supplies this function by calling
             <b>ProNotificationSet()</b> with the notify type
             PRO_WINDOW_OCCUPY_POST.
             <p> <b> 
 
    Input Arguments:   
        win_id - The identifier of the Creo Parametric window
    Output Arguments:
        none
 
    Return Values:
        Return values are not interpreted by Creo Parametric.
 
    See Also:
        ProNotificationSet , ProObjectwindowMdlnameCreate
*/
 
typedef ProError (*ProWindowVacatePreAction) (int win_id);
/*
    Purpose: This is the notification function called before a Creo Parametric window is closed or cleared.
             <p> The user supplies this function by calling
             <b>ProNotificationSet()</b> with the notify type
             PRO_WINDOW_VACATE_PRE.
             <p> <b> 
 
    Input Arguments:
         win_id - The identifier of the Creo Parametric window

    Output Arguments:
        none
 
    Return Values:
        Return values are not interpreted by Creo Parametric.
 
    See Also:
        ProNotificationSet, ProWindowDelete, ProWindowCurrentClose
*/

extern ProError ProWindowDeviceFlush( ProAppData win);
/* 
   Purpose: This function forces the flush of pending display commands
   on the given window.

   <B>Note:</B> IMPORTANT: Excessive calls to this API will cause major
   slow down on systems running Vista or Windows 7. It is recommended 
   to call this API only <b>after</b> completing all display operations.
   
   Input Arguments:
      win         - Handle to the window to flush to.
                    If this is NULL the function will flush to current window.  
   Output Arguments:
      None
   
   Return Values:

      PRO_TK_NO_ERROR       - The function successfully flushed pending
                              display commands.
      PRO_TK_GENERAL_ERROR  - A general error occurred and the
                              function failed.

*/  
 
 

PRO_END_C_DECLS

#endif /* PRO_WINDOW_H */

