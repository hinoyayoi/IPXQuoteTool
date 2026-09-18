

#ifndef PROTOOLKITDLL_H
#define PROTOOLKITDLL_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProValue.h>
#include <ProHardware.h>

#if ( PRO_OS == WINDOWS_32 )
#define PRO_TK_DLL_EXPORT  __declspec (dllexport)
#else
#define PRO_TK_DLL_EXPORT
#endif

typedef struct pro_argument
{
  ProName      label;
  ProValueData value;
} ProArgument;

typedef ProError (*ProTkdllFunction)( ProArgument* inputs,
				      ProArgument** outputs );
/*
  Purpose:    This is the function prototype for a function that can
              be called from a external application using 
	      ProToolkitTaskExecute().

  Input Arguments:
    inputs             - ProArray of input arguments passed to the function. 
                         The function must not free the array or any allocated
			 memory contained in this array.
  Output Arguments:
    outputs            - ProArray of output arguments passed by the function. 
                         The function must allocate memory for this array and 
			 its contents.

  Return Values:
    Any return value   - Passed as an output for ProToolkitTaskExecute().

  See Also:
    ProToolkitTaskExecute()
*/

typedef struct Userprog* ProToolkitDllHandle;

PRO_BEGIN_C_DECLS

extern ProError ProToolkitDllLoad( ProName app_name,
				   ProCharPath exec_file,
				   ProCharPath text_dir,
				   ProBoolean user_display,
				   ProToolkitDllHandle* handle,
				   ProError* user_error_ret,
				   ProPath user_string_ret );
/*
  Purpose:      Causes Creo Parametric to load a Creo Parametric TOOLKIT DLL and initialize
		it. The DLL's user_initialize() will be called.

  Input Arguments:
    app_name            - The name of the application to initialize.
    exec_file           - The DLL file to load, including its full path.
    text_dir            - The path to the applications' message and UI text
			  files.
    user_display        - PRO_B_TRUE if you want the interactive user to be
			  able to see the application registered in the
			  Creo Parametric UI and to see error messages if the
			  application fails in some manner.

  Output Arguments:
    handle              - A pointer to a structure representing a Creo Parametric TOOLKIT
			  DLL.
    user_error_ret      - The error return from the DLL's user_initialize
			  function. May be NULL.
    user_string_ret     - a message from ProE if there was a problem before
    			  the DLL's user_initialize function was run, or from
			  user_initialize() if it was run but returned an
			  error. Never written if user_error_ret is
			  PRO_TK_NO_ERROR. May be NULL.


  Return Values:
    PRO_TK_NO_ERROR     - The initialization succeeded.
    PRO_TK_USER_ABORT   - The DLL's user_initialize function returned an error
			  and the DLL was not initialized.  Check the values of
			  user_error_ret and user_string_ret for more details.
    PRO_TK_CANT_ACCESS  - The file specified could not be read.
    PRO_TK_INVALID_FILE - The file specified is not a proper DLL.
    PRO_TK_E_IN_USE     - The specified DLL is already loaded and may
			  not be loaded again.
    PRO_TK_E_NOT_FOUND  - exec_file did not exist or was not readable
    PRO_TK_CANT_WRITE   - Creo Parametric will not accept any more external
			  applications registered at this time.
    PRO_TK_BAD_CONTEXT  - The DLL was already registered and failed to
    			  start or stop cleanly the last time it was
			  loaded/unloaded.
    PRO_TK_APP_UNLOCK   - The DLL requires the Creo Parametric TOOLKIT Development 
                          License, but it is not available in the Creo Parametric
			  session.

*/

extern ProError ProToolkitDllIdGet( ProToolkitDllHandle application_handle,
				    ProName   application_id );
/*
  Purpose:    Returns an identifier for a particular DLL application.

  Input Arguments:
    application_handle - The handle to get the id for. In DLL mode <b>only</b>,
			 may be NULL, in which case the calling application's
			 id is returned.
  Output Arguments:
    application_id     - The application's identifying string.

  Return Values:
    PRO_TK_NO_ERROR    - Id was returned.
    PRO_TK_BAD_INPUTS  - Invalid application handle passed.
    PRO_TK_BAD_CONTEXT - application handle is valid but application was not
			 running.
*/

extern ProError ProToolkitDllHandleGet( ProName   application_id,
					ProToolkitDllHandle* app_handle );
/*
  Purpose:    Returns an application handle for a particular identifier.

  Input Arguments:
    application_id     - The application's identifying string.

  Output Arguments:
    app_handle - The handle.

  Return Values:
    PRO_TK_NO_ERROR    - Id was returned.
    PRO_TK_BAD_INPUTS  - Invalid application id passed.
    PRO_TK_E_NOT_FOUND - Application could not be found.
    PRO_TK_BAD_CONTEXT - Application was not active
*/

extern ProError ProToolkitTaskExecute( ProToolkitDllHandle handle,
				       ProCharPath function_name,
				       ProArgument* input_arguments,
				       ProArgument** output_arguments,
				       ProError* function_return );
/*
  Purpose: Causes Creo Parametric to execute a function in a DLL.
           <b>Note:</b> The DLL must have been compiled in Pro/ENGINEER 
           Wildfire 1.0 or later.
	   <b>Note:</b>When done reading output_arguments, call
	   ProArgumentProarrayFree to free the data.

  Input Arguments:
    handle             - The DLL handle.
    function_name      - The name of the function to call in the DLL. This
			 function must have been declared in the application
                         using the PRO_TK_DLL_EXPORT macro 
			 and it must have a signature identical to the
			 signature declared for ProTKDllFunction.
    input_arguments    - A ProArray of input arguments passed to the DLL
			 function. This array should not contain any
			 ProValueData structures of type
			 PRO_VALUE_TYPE_POINTER.

  Output Arguments:
    output_arguments   - A ProArray of output arguments outputted from the DLL
			 function. The called function should not populate
			 this array with any ProValueData structures of type
			 PRO_VALUE_TYPE_POINTER.
    function_return    - The return value of the DLL function.

  Return Values:
    PRO_TK_NO_ERROR    - The DLL function execution succeeded.
    PRO_TK_BAD_INPUTS  - one or more of the arguments was invalid.
    PRO_TK_BAD_CONTEXT - application handle is valid but the app was not
			 running.
    PRO_TK_USER_ABORT  - The DLL function returned something besides
			 PRO_TK_NO_ERROR. Check the value of function_return
			 for more details.
    PRO_TK_E_NOT_FOUND - The function named could not be found and called.
    PRO_TK_INVALID_PTR - One or more of the function argument arrays contain
			 value data of type PRO_VALUE_TYPE_POINTER. These
			 structures cannot be transferred.
*/

extern ProError ProToolkitDllUnload( ProToolkitDllHandle handle );
/*
  Purpose: Causes Creo Parametric to unload a previously loaded DLL.  The DLL's
	   user_terminate function will be called.

  Input Arguments:
   handle   - The DLL handle.

  Output Arguments:
    none

  Return Values:
    PRO_TK_NO_ERROR      - The DLL was successfully unloaded.
    PRO_TK_E_BUSY        - The application has active menus present in the UI.
    PRO_TK_NOT_VALID     - You attempted to unload a DLL that was loaded by
			   Creo Parametric upon startup.
    PRO_TK_BAD_INPUTS    - The handle is not valid
    PRO_TK_BAD_CONTEXT   - The handle is valid but the app is not active.
    PRO_TK_GENERAL_ERROR - The DLL was not successfully unloaded.
*/

extern ProError ProArgumentByLabelGet( ProArgument* arg_array,
				       ProName label,
				       ProValueData* data );
/*
  Purpose: Returns the value of a named argument in the list.

  Input Arguments:
    arg_array          - The ProArray of arguments.
    label              - The argument label.

  Output Arguments:
    data               - The argument value.

  Return Values:
    PRO_TK_NO_ERROR    - The argument value was returned.
    PRO_TK_BAD_INPUTS  - One or more input argument was invalid.
    PRO_TK_E_NOT_FOUND - The argument label was not found in the array.
*/

LIB_COREUTILS_API  ProError ProArgumentProarrayFree( ProArgument** array );
/*
  Purpose:  Frees the ProArray of ProArgument returned by ProToolkitTaskExecute,
            including any allocated memory in each ProArgument.
    
  Input Arguments:
    array - The ProArray to free

  Output Arguments:
    none

  Return Values:
    PRO_TK_NO_ERROR      - The free succeeded.
    PRO_TK_BAD_INPUTS    - The ProArray was invalid.
    PRO_TK_GENERAL_ERROR - The free failed. (Do not assume any of the data in
			   <b>array</b> is still readable.)
*/

PRO_END_C_DECLS

#endif /* PROTOOLKITDLL_H */
