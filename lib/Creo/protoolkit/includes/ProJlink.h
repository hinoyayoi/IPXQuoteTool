#ifndef PRO_JLINK_H
#define PRO_JLINK_H

#include <ProToolkitDll.h>

PRO_BEGIN_C_DECLS

typedef struct Userprog* ProJlinkAppHandle;


extern ProError ProJlinkApplicationStart (ProName app_name,
			    ProCharPath java_app_class,
			    ProCharPath java_app_start,
			    ProCharPath java_app_stop,
			    ProCharPath java_app_add_classpath,
			    ProCharPath text_dir,
			    ProBoolean user_display,
			    ProJlinkAppHandle* handle,
			    char ** startup_exception);
/*
  Purpose: Register and start a J-Link application.
  
  Input Arguments:
      app_name          - The application name.
      java_app_class    - The application Java class.
      java_app_start    - Static method used to intialize the application.
      java_app_stop     - Static method used to terminate the application.
      java_app_add_classpath - Additional elements to be added to the front 
                             of the system CLASSPATH. Can be NULL. If more
			     than one path is being added, they must be 
			     separated using the appropriate path separator
			     (';' on Windows and ':' on UNIX).
      text_dir          - The application text path for menus and messaging.
                          If NULL, the function uses the current directory.
      user_display      - PRO_B_TRUE to show application startup failure 
                          messages to the user, and to show the application in
			  the Auxiliary Applications dialog.
		     
  Output Arguments:
      handle            - Handle to the Jlink application.
      startup_exception - If the application start method threw an exception, 
                          the exception description is stored here.  Free this 
			  string using ProStringFree.  Pass NULL if you 
			  are not interested in this information.
			  
   Return Values:
      PRO_TK_NO_ERROR   - Initialization succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments are invalid.
      PRO_TK_USER_ABORT - The application failed to start properly. See the 
                          startup exception for more details.
      PRO_TK_GENERAL_ERROR - Initialization failed. See the startup exception
                             for more details.
      PRO_TK_E_AMBIGUOUS - The application class is already registered as 
                           another application, with different start and/or 
			   stop methods.
      PRO_TK_E_IN_USE   - The application with this configuration is already 
                           loaded, and may not be loaded again.
      PRO_TK_CANT_WRITE - Creo Parametric will not accept any more auxiliary 
                           applications at this time.

*/

extern ProError ProJlinkTaskExecute (ProJlinkAppHandle app_handle,
			      ProCharLine task_id, 
			      ProArgument* input_args,
			      ProArgument** output_args, 
			      char ** exception);
/*
  Purpose: Call a static method, with variable arguments, in a J-Link application.

  Input Arguments:
            app_handle         - Handle to the Jlink application.
            task_id            - The name of the task listener registered 
	                         using J-Link calls bt the application.
            input_args         - ProArray of input arguments.  This should not 
	                         include any arguments of type 
				 PRO_VALUE_TYPE_POINTER.

  Output Arguments:
            output_args         - ProArray of output arguments. 
            exception           - If the method threw an exception, the 
	                          exception description is stored here.  Free 
				  this string using ProStringFree(). Pass NULL
				  if you are not interested in this information.

  Return Values:
            PRO_TK_NO_ERROR     - Task executed successfully. 
            PRO_TK_BAD_INPUTS   - One or more input arguments are invalid.
            PRO_TK_USER_ABORT   - The application threw an exception. See the 
                                exception output argument for more details.
            PRO_TK_E_NOT_FOUND  - The task could not be found.
            PRO_TK_BAD_CONTEXT  - The handle is valid but the application is not active.
	    PRO_TK_GENERAL_ERROR - A virtual machine error occurred. See the 
                                exception output argument for more details.
*/


extern ProError ProJlinkApplicationStop (ProJlinkAppHandle app_handle,
			      char ** exception);


/*
  Purpose: Stop a previously loaded J-Link application. The application's stop
            method will be called.

  Input Arguments:
            app_handle         - Handle to the Jlink application.
	    
  Output Arguments:
            exception          - If the application stop method threw an 
	                          exception, the exception description is 
				  stored here.  Free this string using 
				  ProStringFree.
				  
  Return Values:
            PRO_TK_NO_ERROR    - Shutdown succeeded.
            PRO_TK_BAD_INPUTS  - The input argument is invalid.
            PRO_TK_USER_ABORT  - The application failed to shutdown properly. 
	                        See the output exception for more details.
            PRO_TK_E_BUSY      - The application has menus or UI components 
	                        active in the UI.
            PRO_TK_BAD_CONTEXT - The handle is valid but the application is 
	                        not active.
*/


PRO_END_C_DECLS

#endif
