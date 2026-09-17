


#ifndef PROCORE_H
#define PROCORE_H

#include <ProConst.h>
#include <ProToolkit.h>
#include <ProComm.h>

PRO_BEGIN_C_DECLS

typedef PeerIdx ProProcessHandle;

extern ProError ProAsynchronousMain( int argc, char **argv );

/*
  Purpose:  Called from an asynchronous program which will be started by 
            a Creo Parametric session.  This function should be called from 
	    the user-supplied main() as early as possible, to establish
	    the connection between the user application and the
	    Creo Parametric session which launched it.

  Input Arguments:
      argc  - You cannot modify this argument in any way.
      argv  - You cannot modify this argument in any way.

  Output Arguments:
      None
    
  Return Values:
     PRO_TK_NO_ERROR  -  The connection succeeded.
     Other            -  The connection failed.

*/

extern void ProToolkitMain( int argc, char** argv );

/* 

  Purpose:  Enables you to write your own <i>main()</i> without using asynchronous
            mode.
            <p>
            The rules and restrictions for a user-supplied <i>main()</i> are as 
            follows:
            <ul>
            <li> You can make other, non-Creo Parametric TOOLKIT calls before 
              <b>ProToolkitMain()</b>.
            <li> This process is spawned by Creo Parametric, and is therefore a 
              child process. The process operates like the standard 
              synchronous mode.
            <li> The process terminates when you exit Creo Parametric.
            </ul>

  Input Arguments:
      argc  - You cannot modify this argument in any way.
      argv  - You cannot modify this argument in any way.

  Output Arguments:
      None
    
  Return Values:
      None

*/

extern ProError ProEngineerStart( char* proe_path,
				  char* prodev_text_path );

/*

  Purpose:  Causes the Creo Parametric TOOLKIT program to spawn and connect to a new
            Creo Parametric session. It is intended for use in simple and
            full asynchronous modes.

  Input Arguments:
     proe_path        -  The path and file name of the Creo Parametric
                         executable, or a script that runs it.
     prodev_text_path -  The path under which the Creo Parametric TOOLKIT message
                         and menu files are held. This is used in full
                         asynchronous mode only. Otherwise, pass a null 
                         string.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - Creo Parametric started successfully.
     PRO_TK_GENERAL_ERROR  - There was a general error.
     PRO_TK_NO_LICENSE     - Creo Parametric could not get a license to run.
     PRO_TK_APP_NO_LICENSE - Creo Parametric was run without the licenses needed
			     to run this application.
     PRO_TK_INVALID_DIR    - prodev_text_path is not a valid directory.
     other                 - Error status returned by the application's
                             user_initialize().
			     <p>
			     <b>Special cases</b>:
			     <ul>
			     <li>if the application is running in native mode
			     instead of Unicode, PRO_TK_BAD_INPUTS may indicate
			     that prodev_text_path could not be converted to or
			     from Unicode.
			     <li>PRO_TK_APP_CREO_BARRED indicates that
			     <i>proe_path</i> pointed to a Creo application
			     that does not support Creo Parametric TOOLKIT.
*/

extern ProError ProEngineerConnect( char *proe_session_id, char *display,
                                    char *user, char *textpath,
                                    ProBoolean allow_random,
                                    unsigned int timeout_sec,
                                    ProBoolean *random_choice,
                                    ProProcessHandle *p_handle );

/*

  Purpose:  Causes the Creo Parametric TOOLKIT program to connect to an existing
            Creo Parametric process using a specified display. It is intended for
	    use in simple and full asynchronous modes.

  Input Arguments:
     proe_session_id  -  This argument can be either empty string or 
                         identification string returned by 
                         ProEngineerConnectIdExtract. If it is ID string, the
                         Creo Parametric TOOLKIT application will try to connect to the
			 specified Creo Parametric session; if this attempt fails,
			 the application will try to connect to any Creo Parametric
			 session.
     display          -  The name of the display Creo Parametric
                         is using. If this is NULL, match any display. 
                         If this is an empty string,
                         assume the local host.
     user             -  The name of the user running the Creo Parametric to
                         connect to. If this is NULL, match any user. If 
                         this is an empty string,
                         assume the current user.
     textpath         -  The path under which the Creo Parametric TOOLKIT message
                         and menu files are held. This is used in full
                         asynchronous mode, or in simple asynchronous mode if
			 text files are read (e.g., ProMessageToBuffer() is
			 called). Otherwise, pass a null string.
     allow_random     -  If there is more than one Creo Parametric matching the constraints
                         specified in arguments "display" and "user", choose one at random
                         if this argument is PRO_B_TRUE; if it is PRO_B_FALSE, return an
                         error.
     timeout_sec      -  The time, in seconds, to wait for Creo Parametric to
                         respond to the connection request.

  Output Arguments:
     random_choice    -  If this is PRO_B_TRUE, more than one Creo Parametric 
                         met the specified criteria (<i>allow_random</i> was TRUE)
                         and the function arbitrarily chose one Creo Parametric 
                         session.

     p_handle         -  A pointer to a process handle to be used in
                         subsequent calls to Creo Parametric.

  Return Values:
     PRO_TK_NO_ERROR      - The connection succeeded.
     PRO_TK_CANT_ACCESS   - No network access.
     PRO_TK_NOT_EXIST     - No Creo Parametric session exists.
     PRO_TK_E_IN_USE      - Creo Parametric session did not respond to request for
                            connection.
     PRO_TK_ABORT         - Call to Creo Parametric interrupted.
     PRO_TK_CANT_MODIFY   - Cannot register connection with name server. If the 
                            environment variable PRO_COMM_MSG_EXE is not set, 
                            this value is returned.
     PRO_TK_CANT_OPEN     - Cannot process request for connection to
                            Creo Parametric session.
     PRO_TK_E_DEADLOCK    - The application and Creo Parametric deadlocked while
                            trying to make a connection.
     PRO_TK_E_NOT_FOUND   - No Creo Parametric session with the specified
     			    characteristics could be found, or information on
     		 	    the session could not be read from the name server.
     PRO_TK_E_BUSY        - Creo Parametric session did not respond to request for
                            initialization within <b>timeout_sec</b> seconds.
     PRO_TK_E_AMBIGUOUS   - More than one Creo Parametric session with the specified
     			    characteristics was found and random_choice was
			    PRO_B_FALSE, preventing a session from being chosen.
     PRO_TK_OUT_OF_MEMORY - There was insufficient memory to build a query to
     			    the name server.
     PRO_TK_COMM_ERROR    - Creo Parametric session refused connection. (This
                            can happen if application initialization fails.)
     PRO_TK_INVALID_DIR   - textpath is not a valid directory.
     other                - Error status returned by the application's
                            user_initialize().
			    <p>
			    <b>Special cases</b>:
			    <ul>
			    <li>if the application is running in native mode
			    instead of Unicode, PRO_TK_BAD_INPUTS may indicate
			    that prodev_text_path could not be converted to or
			    from Unicode.
			    <li>PRO_TK_APP_CREO_BARRED indicates an attempt to
			    connect to a Creo application that does not
			    support Creo Parametric TOOLKIT.
*/

extern ProError ProEngineerConnectWS( char *proe_session_id, char *display,
                                      char *user, wchar_t *workspace,
                                      char *textpath,
                                      ProBoolean allow_random,
                                      unsigned int timeout_sec,
                                      ProBoolean *random_choice,
                                      ProProcessHandle *p_handle );
 
/*
 
  DEPRECATED: Since Creo 2
  SUCCESSORS: ProEngineerConnect
  Purpose:  <P><B>NOTE:</B> This function is deprecated. 
  	    Pro/INTRALINK 3.4 is not supported.  
            Please use ProEngineerConnect() to connect to Creo Parametric
            process that has a Pro/INTRALINK 10.0 server registered. </P>
            Causes the Creo Parametric TOOLKIT program to connect to an existing
            Creo Parametric process running on a host using a
            specified display. It is intended for use in simple and
            full asynchronous modes.

  Input Arguments:
     proe_session_id  -  This argument can be either an empty string or an
                         identification string returned by
                         ProEngineerConnectIdExtract. If it is an ID string,
                         the Creo Parametric TOOLKIT application will try to connect to the
			 specified Creo Parametric session; if this attempt fails,
			 the application will try to connect to any Creo Parametric
			 session.
     display          -  The name of the display Creo Parametric
                         is using. If this is NULL, match any display.
                         If this is an empty string,
                         assume the local host.
     user             -  The name of the user running the Creo Parametric to
                         connect to. If this is NULL, match any user. If
                         this is an empty string,
                         assume the current user.
     workspace        -  The name of the workspace Creo Parametric is using.
                         If this is NULL, match any workspace.
     textpath         -  The path under which the Creo Parametric TOOLKIT message
                         and menu files are held. This is used in full
                         asynchronous mode only. Otherwise, pass a null
                         string.
     allow_random     -  If this is PRO_B_TRUE, and more than one Creo Parametric
                         is running on the host using the specified display,
                         choose one at random and connect to it. If this is
                         PRO_B_FALSE, return an error in this case.
     timeout_sec      -  The time, in seconds, to wait for Creo Parametric to
                         respond to the connection request.
 
  Output Arguments:
     random_choice    -  If this is PRO_B_TRUE, more than one Creo Parametric
                         met the specified criteria (<i>allow_random</i> was
                         TRUE) and the function arbitrarily chose one
                         Creo Parametric session.
 
     p_handle         -  A pointer to a process handle to be used in
                         subsequent calls to Creo Parametric.
 
  Return Values:
     Any value        -  See description of this return value from 
                         ProEngineerConnect().

  See Also:
     ProEngineerConnect()
*/

extern ProError ProEngineerConnectionStart( char* proe_path,
                                            char* prodev_text_path,
                                            ProProcessHandle *p_handle );
                                  
/*
  Purpose:  Causes the Creo Parametric TOOLKIT program to spawn and connect to a new
            Creo Parametric session.  ProEngineerDisconnect can be called later
            to disconnect from created Creo Parametric session. It is intended 
            for use in full asynchronous mode.

  Input Arguments:
     proe_path        -  The path and file name of the Creo Parametric
                         executable, or a script that runs it.
     prodev_text_path -  The path under which the Creo Parametric TOOLKIT message
                         and menu files are held. This is used in full
                         asynchronous mode only. Otherwise, pass a null
                         string.

  Output Arguments:
     p_handle         -  A pointer to a process handle to be used in
                         subsequent calls to Creo Parametric.

  Return Values:
     PRO_TK_INVALID_PTR - Could not get a valid handle to connect to the
			  started Creo Parametric.
     Other -  see returns for ProEngineerStart() and ProEngineerConnect()

*/

typedef char ProConnectionId[PRO_CONNECTID_SIZE]; 

extern ProBoolean ProEngineerConnectIdExtract( ProProcessHandle p_handle,
                                               ProConnectionId proe_connect_id);

/*
   Purpose:  Extracts a connection identification string for the 
             Creo Parametric session represented by the given handle.
            Format of identification string is the following:
            "host:H:addr_ver:A:addr_type:T:rpcnum:R:rpcversion:V:netaddr:N"
             where the flags are as follows:
            <UL> 
                <LI>H: name of host where Creo Parametric runs
                <LI>A: address version
                <LI>T: address type
                <LI>R: RPC number
                <LI>V: RPC version
                <LI>N: net address
            </UL>
            The identification string can be used in subsequent calls to ProEngineerConnect to specify the Creo Parametric session it must connect to.

  Input Arguments:
     p_handle         -  A pointer to a process handle of Creo Parametric

  Output Arguments:
     proe_connect_id  -  Identification string to be used in subsequent
                         calls to ProEngineerConnect.
  Return Values:
     PRO_B_TRUE       -  Identification string was created successfully
     PRO_B_FALSE      -  There was a general error and proe_connect_id
                         is not valid
     
*/

extern ProError ProEngineerDisconnect( ProProcessHandle *p_handle,
                                       unsigned int timeout_sec );

/*

  Purpose:  Disconnects the Creo Parametric TOOLKIT program from a Creo Parametric
            process to which it had previously connected using
            <b>ProEngineerConnect()</b>. 

  Input Arguments:
     p_handle         -  The pointer to a process handle returned by
                         <b>ProEngineerConnect()</b>. The handle itself will be
                         invalidated as a result of the call.

     timeout_sec      -  The time, in seconds, to wait for Creo Parametric to
                         respond to the disconnect request.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  The disconnect request succeeded.
     PRO_TK_BAD_INPUTS - The argument <i>p_handle</i> is NULL, or points to 
                         an invalid process handle.
     Other             - An error occurred and the disconnect request failed.

  See Also:
     ProEngineerConnect()

*/

extern ProError ProWorkspaceStatusUpdate( void );
/*
  DEPRECATED: Since Creo 1
  SUCCESSORS: NONE
  Purpose:  <P><B>NOTE:</B> This function is deprecated. Pro/INTRALINK 3.4 is not supported.</P>
  	    Invalidates the object access status cache resulting in
            access status being read from Workspace next time it is
            needed.

  Input Arguments:
     None 

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully updated the
                          workspace status.
*/

extern void ProEventProcess( void );

/*

  Purpose:  Enables your process to respond to calls (functions within 
            your process) from Creo Parametric. You must call this function 
            within your control loop to let you readily process any 
            Creo Parametric calls.

  Input Arguments:
     None 

  Output Arguments:
     None

  Return Values:
     None

*/

extern ProError ProEngineerStatusGet( void );
/*
   Purpose:   Determines whether the application is currently connected to a 
              Creo Parametric session, and if that session is responding to 
              requests.

   Input Arguments:
      None
 
   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR      -  The Creo Parametric session is available.
      PRO_TK_GENERAL_ERROR -  There was no Creo Parametric session available, or 
                              the session did not respond.

*/

extern ProError ProEngineerEnd( void );
/*


  Purpose:  Terminates a Creo Parametric session. In synchronous mode, 
            the function also terminates any Creo Parametric TOOLKIT process 
            started by the current Creo Parametric session.

  Input Arguments:
     None

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR   - Creo Parametric was successfully terminated.
     PRO_TK_COMM_ERROR - The communications to Creo Parametric failed.
*/

typedef ProError (*ProTerminationAction) ( ProeTerminationStatus term_type );
/*
   Purpose:   This is the user's termination function called when
              Creo Parametric terminates normally.

   Input Arguments:
      term_type -  The Creo Parametric termination status

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function was successful.
*/

extern ProError ProTermFuncSet( ProTerminationAction term_function );
/*
   Purpose:  Binds the user function to be called when Creo Parametric
             terminates normally (using Exit).  To unbind the function,
             pass a null pointer.

<p>
             NOTES:  
             <ul>
             <li>The function is only valid while a Creo Parametric session 
                 spawned through <b>ProEngineerStart()</b> is running.
             <li>When it is outside the event loop, the application should
                 unbind the notification function to avoid blocking 
                 Creo Parametric upon exit.
	     <li>If the application calls ProEngineerEnd, term_function will
	         <b>not</b> be called.
             </ul>
 
   Input Arguments:
      term_function -  A pointer to the user's function, or NULL

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function was successful.
      PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProAsynchronousEventLoop ( void );
/*
    Purpose: Initiates an event loop which will call ProEventProcess 
             periodically(1sec) to handle events returned from Creo Parametric.  
             Applicable only for full asynchronous applications which are not 
             supposed to carry out any tasks while waiting for Creo Parametric events.
             <P>
             IMPORTANT NOTE: This function will not return until interrupted by 
             ProAsynchronousEventLoopInterrupt() or an error returns from 
             ProEngineerStatusGet().  No separate application processing is 
             possible until that time, except within Creo Parametric event callbacks.
             

    Input Arguments:
        none

    Output Arguments:
        none

    Return Values:
        PRO_TK_USER_ABORT - The function was interrupted by 
                            ProAsynchronousEventLoopInterrupt().
        Any other value - ProEngineerStatusGet() returned this error.

*/

extern ProError ProAsynchronousEventLoopInterrupt ( void );
/*
    Purpose: Call this function from within a Creo Parametric callback function to halt a 
             loop currently running in ProAsynchronousEventLoop().
             

    Input Arguments:
        none

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.

*/



extern ProError ProEngineerConnectIdGet (ProConnectionId proe_connect_id);
/*
    Purpose: Returns the connection id for the Creo Parametric session that this 
             application is connected to. The identification string
             can be passed to external asynchronous applications to allow them
             to connect to this Creo Parametric session. 

    Input Arguments:
        none

    Output Arguments:
        proe_connect_id - Identification string that can be used by an 
                          asynchronous process to connect to this Creo Parametric 
                          session.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - The argument was invalid.
        PRO_TK_E_NOT_FOUND - Communications are not correctly established for 
                             this session of Creo Parametric, and asynchronous 
                             connection is not possible.
*/

/* INTERNAL COMMENT

Format for Connection Id string is in the description for the 
ProEngineerConnectIdExtract()

*/

extern ProError ProToolkitUnicodeencodingDisable( void );
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Sets this application to run with legacy-encoded strings instead 
             of the default Unicode encoding.  
             <P>Valid only for asynchronous mode applications; must be called
	     before the first call to the Creo Parametric TOOLKIT API (e.g.,
             ProEngineerStart(), ProWstringToString, ProEngineerConnect(), 
             ProStringToWstring, ProEngineerConnectionStart()).
             <P><B>Note:</B> There is a possibility of data loss when using 
             legacy encoding mode with Creo Parametric.  

    Input Arguments:
        none

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The function cannot be used at this time.

*/

PRO_END_C_DECLS

#endif

