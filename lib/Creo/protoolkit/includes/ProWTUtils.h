#ifndef PRO_WT_UTILS_H
#define PRO_WT_UTILS_H



# include <ProToolkit.h>
# include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef struct pro_server_checkin_options*  ProServerCheckinOptions;
typedef struct pro_server_checkout_options* ProServerCheckoutOptions;

typedef struct pro_server_conflicts* ProServerConflicts;
typedef struct pro_server_conflicts* ProServerCheckinConflicts;
typedef struct pro_server_conflicts* ProServerCheckoutConflicts;
typedef struct pro_server_conflicts* ProServerUploadConflicts;
typedef struct pro_server_conflicts* ProServerUndoCheckoutConflicts;
typedef struct pro_server_conflicts* ProServerRemoveConflicts;
typedef struct pro_server_conflicts* ProServerDeleteConflicts;

typedef struct pro_server_workspace_data*   ProServerWorkspaceData;

/*****************************************************************************/
extern ProError ProServerVersionGet ( wchar_t*  server, 
                                      wchar_t** server_version );
/*
    Purpose: Obtains the major version of the Windchill server e.g. 7, 6, X05 

    Input Arguments:
        server - A server codebase url or an alias

    Output Arguments:
        server_version - The server version

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The server couldn't be found at the given 
	                     location.
        PRO_TK_UNSUPPORTED - The server is not a Windchill server

    See Also:
        ProServerClassGet()

*/

extern ProError ProServerClassGet ( wchar_t*  server_url, 
                                    wchar_t** server_class );
/*
    Purpose: Obtains the class of the Windchill server as Windchill ( for WNC 
             and PDMLink ) or ProjectLink 

    Input Arguments:
        server_url - A server codebase url or an alias 

    Output Arguments:
        server_class - The server class

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The server couldn't be found at the given 
	                         location.

    See Also:
        ProServerVersionGet()

*/

extern ProError ProServerWorkspaceCreate (wchar_t* alias, 
                                          ProServerWorkspaceData data);
/* 
Purpose: Creates and activates a new workspace.  

	Input Arguments:
	 alias - The server alias.  Pass NULL to use the active server.
	 data  - Information about the given workspace. Use 
			 ProServerworkspacedataAlloc() to construct this.
		
			
			
	Output Arguments:
	 none
	
	Return Values:
	 PRO_TK_NO_ERROR    - The function succeeded.
	 PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
	 PRO_TK_E_NOT_FOUND - The server is not registered.
	 PRO_TK_E_FOUND     - The workspace already exists.
	 PRO_TK_CANT_WRITE  - Cannot create a workspace on this server.
*/

extern ProError ProServerworkspacedataAlloc (wchar_t* workspace_name, 
                                             wchar_t* context, 
                                             ProServerWorkspaceData* data);
/* 
Purpose: Allocates data used to describe a workspace.

	Input Arguments:
	 workspace_name - The name of the workspace.
	 context        - The name of the context in which the workspace is stored.
		
			
	Output Arguments:
	  data - The workspace data.
	
	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/


extern ProError ProServerworkspacedataNameGet (ProServerWorkspaceData data, 
                                               wchar_t** name);
/* 
Purpose: Returns the name of the workspace from the workspace data.

	Input Arguments:
	 data - The workspace data.
		
			
	Output Arguments:
	 name - The name used for the workspace.  Free this using ProWstringFree().

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/

extern ProError ProServerworkspacedataContextGet (ProServerWorkspaceData data,
                                                  wchar_t** context);
/* 
Purpose: Returns the name of the context from the workspace data.

	Input Arguments:
	 data - The workspace data.
		
			
	Output Arguments:
	 context - The context used for the workspace.  Free this using 
               ProWstringFree().

	Return Values:
	 PRO_TK_NO_ERROR    - The function succeeded.
	 PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
	 PRO_TK_E_NOT_FOUND - No context was found (the server was from WC 6.2.6)
*/


extern ProError ProServerworkspacedataFree (ProServerWorkspaceData data);
/* 
Purpose: Frees the memory associated with a given workspace data structure.

	Input Arguments:
	 data - The workspace data.
		
			
	Output Arguments:
	 none
	
    Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/

extern ProError ProServerworkspacedataProarrayFree (ProServerWorkspaceData* data_array);
/* 
Purpose: Frees the memory associated with a given workspace data ProArray.

	Input Arguments:
	 data_array - The workspace data array.
		
			
	Output Arguments:
	 none
	
	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more inputs was invalid.
*/

extern ProError ProServerWorkspaceDelete( wchar_t* server, wchar_t* ws_name,
                                          ProServerDeleteConflicts* conflicts);
/* 
Purpose: Deletes a workspace.

	Input Arguments:
     server - The server on which the workspace to be deleted exists.  
     Pass NULL to use the active server. This can be a alias or a server URL.
     This function is only usable in batch mode.

     <b>Note</b>: To delete any non-active WS: just delete it with this API.
     To delete a currently active WS: 

     <UL>
        <LI>set the other workspace as active and delete the first workspace or
        <LI>unregister the primary server and delete the workspace using the 
            server URL instead of alias
     </UL>

	 ws_name - The workspace name.
	 
			
	Output Arguments:
	 conflicts - The workspace could not be deleted.
                 NULL if the error return != PRO_TK_CHECKOUT_CONFLICT.  
                 Pass NULL if not interested in conflicts details.
	
	Return Values:
	 PRO_TK_NO_ERROR          - The function succeeded.
	 PRO_TK_BAD_INPUTS        - One or more inputs was invalid.
	 PRO_TK_E_NOT_FOUND       - The server is not registered.
	 PRO_TK_INVALID_DIR       - The workspace does not exist.
	 PRO_TK_CHECKOUT_CONFLICT - The workspace cannot be deleted due to checked
                                out objects in its contents.
     PRO_TK_E_IN_USE          - The workspace is active
*/

extern ProError ProServerWorkspacesCollect(wchar_t* server, 
                                           ProServerWorkspaceData** data);
/*
   Purpose: Gets the list of the workspaces for a given server.

   Input Arguments:
    server - The alias used by Creo Parametric to refer to the server, or the server
             base URL in http:// format.

   Output Arguments:
    data - The list of the workspaces for the server. Free this array 
              using ProServerworkspacedataProarrayFree().

   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
    PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND   - The server was not registered or couldn't be found 
                           at the given location.
    PRO_TK_EMPTY         - The server does not have any workspaces
    PRO_TK_CANT_ACCESS   - Server communication error, or user lacks 
                           permission to view workspaces on this server.
    PRO_TK_INVALID_TYPE  - The server version is not supported
*/

extern ProError ProServerContextsCollect(wchar_t* server, wchar_t*** data);
/*
   Purpose: Gets the list of the contexts for a given server.

   Input Arguments:
    server - The alias used by Creo Parametric to refer to the server, or the server 
             base URL in http:// format.

   Output Arguments:
    data - The list of the contexts for the server. Free this array 
              using ProWstringproarrayFree().

   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
    PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND   - The server was not registered or couldn't be found 
                           at the given location.
    PRO_TK_EMPTY         - The server does not have any contexts.
    PRO_TK_CANT_ACCESS   - Server communication error, or user lacks 
                           permission to view workspaces on this server.
    PRO_TK_INVALID_TYPE  - The server version is not supported
*/

extern ProError ProServerRegister (wchar_t* alias, wchar_t* location, 
								   wchar_t* workspace, wchar_t** aliased_url);
/* 
   Purpose: Registers a server in the session given its root location and 
   an alias.
  <B>NOTE</B>: To automate registration of servers
  in interactive mode, use the standard config.fld setup to preregister the 
  servers. To ensure that the servers are not preregistered when running 
  Creo Parametric in batch non-graphics mode, set the environment variable 
  PTC_WF_ROOT to an empty directory before starting Creo Parametric.

   Input Arguments:
    alias     - The name used by Creo Parametric to refer to this server.
    location  - The root location for the server.
    workspace - The name of the workspace to use.

   Output Arguments:
	aliased_url - Aliased url for the registered workspace. 
                  Free this string using ProWstringFree()
	
	Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
     PRO_TK_E_FOUND       - A server with this alias or location/workspace is 
                            already registered.
     PRO_TK_E_NOT_FOUND   - The server couldn't be found at the given 
                            location.
     PRO_TK_INVALID_NAME  - Authentication failed.
     PRO_TK_INVALID_DIR   - The workspace couldn't be found or created.
     PRO_TK_NO_LICENSE    - There is no license to work with the server.
     PRO_TK_INVALID_TYPE  - The server version is not supported.
     PRO_TK_GENERAL_ERROR - If any other error occures. 
*/


extern ProError ProServerWorkspaceSet (wchar_t* alias, wchar_t* workspace);
/* 
   Purpose: Sets the workspace to use for a given server.

   Input Arguments:
    alias     - The name used by Creo Parametric to refer to this server.
    workspace - The name of the workspace to use.  

   Output Arguments:
    none
	
	Return Values:
	 PRO_TK_NO_ERROR      - The function succeeded.
	 PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	 PRO_TK_E_NOT_FOUND   - The server was not registered.
	 PRO_TK_INVALID_DIR   - The workspace couldn't be found or created.
     PRO_TK_E_FOUND       - The workspace is already set.
	 PRO_TK_GENERAL_ERROR - If any other error occures. 
*/

extern ProError ProServerActivate (wchar_t* alias);
/* 
   Purpose: Sets the server to be active in session.

   Input Arguments:
    alias - The name used by Creo Parametric to refer to this server.

   Output Arguments:
    none
	
   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND   - The server was not registered.
	PRO_TK_GENERAL_ERROR - If any other error occures.
*/

extern ProError ProServerWorkspaceGet (wchar_t* alias, wchar_t** workspace);
/* 
   Purpose: Gets the workspace to use for a given server.

   Input Arguments:
    alias - The name used by Creo Parametric to refer to this server.
		
   Output Arguments:
    workspace - The name of the workspace in use. Free this string using 
                ProWstringFree(). 	

   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND   - The server was not registered.
	PRO_TK_GENERAL_ERROR - If any other error occures.
*/

extern ProError ProServerContextGet( wchar_t* alias, wchar_t** context );
/* 
   Purpose: Gets the context to use for a given server.
 
   Input Arguments:
    alias - The name used by Creo Parametric to refer to this server.
  
   Output Arguments:
    context - The name of the context in use. Free this string using 
              ProWstringFree().  
 
   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
    PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND   - The server was not registered.
    PRO_TK_GENERAL_ERROR - If any other error occurs.
*/

extern ProError ProServerUnregister( wchar_t* alias );
/* 
   Purpose: Unregisters a given server and cleans a local cache for the server.

   Input Arguments:
    alias - The name used by Creo Parametric to refer to this server.

   Output Arguments:
    none
	
   Return Values:
    PRO_TK_NO_ERROR          - The function succeeded.
	PRO_TK_BAD_INPUTS        - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND       - The server is not registered.
	PRO_TK_CANT_WRITE        - Cannot delete this workspace.
	PRO_TK_CHECKOUT_CONFLICT - The workspace cannot be deleted due to 
	                           checked out objects in its contents.
	PRO_TK_GENERAL_ERROR     - If any other error occures.
*/

extern ProError ProServerLocationGet(wchar_t* alias, wchar_t** location);
/* 
   Purpose: Gets the codebase url for a given server.

  Input Arguments: 
   alias - The name used by Creo Parametric to refer to this server.

  Output Arguments:
   location - The root location for the server.  Free this string using 
              ProWstringFree().

   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND   - The server was not registered.
	PRO_TK_GENERAL_ERROR - If any other error occures.
*/

extern ProError ProServerAliasGet(wchar_t* url, wchar_t* ws_name, 
								  wchar_t** alias);
/* 
   Purpose: Gets the alias for a given codebase url and workspace.

   Input Arguments:
    url       - The arbitrary url of the server.
	ws_name   - The workspace on the server. Could be NULL
		
   Output Arguments:
    alias - The alias of the server.  If workspace is NULL and more then one
            server with the url is registered, returns alias of one of the 
		    registered servers. Free this string using ProWstringFree().

   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND   - The server was not registered.
	PRO_TK_GENERAL_ERROR - If any other error occures.
*/

extern ProError ProServersCollect (wchar_t*** aliases);
/* 
   Purpose: Collects all of the registered servers.

   Input Arguments:
   none

   Output Arguments:
    aliases - ProArray of aliased servers. Free this string using 
	          ProWstringproarrayFree().
	
   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND   - No servers are currently registered.
	PRO_TK_GENERAL_ERROR - If any other error occures.
*/

extern ProError ProServerActiveGet (wchar_t** alias);
/* 
   Purpose: Gets the primary sever
   
   Input Arguments:
    none

   Output Arguments:
    alias - The name used by Creo Parametric to refer to this server.  
            Free this string using ProWstringFree().
   
   Return Values:
    PRO_TK_NO_ERROR    - The function succeeded.
	PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND - There is no active aliased server (Local Dir is 
	                     active).
*/

extern ProError ProServerAliasedURLToURL (wchar_t* aliased_url, wchar_t** url);
/* 
   Purpose: Converts an an aliased url (wtpub://alias/etc/p.prt) suitable for 
            use in functions like ProMdlLoad to an unaliased URL 
			(http://windchillserver.ptc.com/etc).

   Input Arguments:
	aliased_url - The aliased URL.
		
   Output Arguments:
    url - The unaliased URL.  Free this string using ProWstringFree().
    If the server is in offline mode url will be null string.
	
   Return Values:
	PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
	PRO_TK_E_NOT_FOUND   - The server listed in the given aliased URL is not 
                           registered in session.
    PRO_TK_GENERAL_ERROR - If any other error occures.
    PRO_TK_CANT_ACCESS   - If the server is in offline mode.
*/

extern ProError ProServerAliasedURLToModelName(wchar_t* aliased_url,
											   wchar_t** alias, 
											   wchar_t** model_name);
/* 
Purpose: Gets model name for a given aliased url.

  Input Arguments:
   aliased_url - The aliased url to the model.

  Output Arguments:
   alias      - an alias of the server where the model resides. 
                Free this string using ProWstringFree().
   model_name - model name for a given aliased url.
                Free this string using ProWstringFree().
	
  Return Values:
   PRO_TK_NO_ERROR      - The function succeeded.
   PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
   PRO_TK_E_NOT_FOUND   - The object was not found.
   PRO_TK_GENERAL_ERROR - If any other error occures.
*/

extern ProError ProServerModelNameToAliasedURL(wchar_t* alias, 
											   wchar_t* model_name,
											   wchar_t** aliased_url);
/* 
Purpose: Gets aliased url for a given model name.

  Input Arguments:
   alias      - an alias of the server where the model resides. 
   model_name - model name.

  Output Arguments:
   aliased_url - The aliased url to the model.
                 Free this string using ProWstringFree().
	
  Return Values:
   PRO_TK_NO_ERROR      - The function succeeded.
   PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
   PRO_TK_E_NOT_FOUND   - The object was not found.
   PRO_TK_GENERAL_ERROR - If any other error occures.
*/

/*                     UNDOCHECKOUT                                          */
extern ProError ProServerObjectsUndocheckout (ProMdl mdl,
									ProServerUndoCheckoutConflicts* conflicts);
/* 
Purpose: Undoes the checkout of the given object.

  Input Arguments:
   mdl - The top level model that was checked out.
			
  Output Arguments:
   conflicts - Information about undo checkoout conflicts.  NULL if the error 
			   return != PRO_TK_CHECKOUT_CONFLICT.  Pass NULL if not interested
			   in conflicts details.
	
  Return Values:
  PRO_TK_NO_ERROR          - The function succeeded.
  PRO_TK_E_NOT_FOUND       - The top level object was not found.
  PRO_TK_BAD_INPUTS        - One or more inputs was invalid.
  PRO_TK_BAD_CONTEXT       - The primary server is not set.
  PRO_TK_CHECKOUT_CONFLICT - Conflicts occurred.  Check the details in the 
                              conflicts return.
*/

/*                               CHECKIN                                    */
extern ProError ProServerObjectsCheckin (ProMdl mdl,
										 ProServerCheckinOptions options,
										 ProServerCheckinConflicts* conflicts);
/*
    Purpose: Checks in or uploads objects to the database.
             <P><B>NOTE:</B> The model must be saved to the workspace (using
             ProMdlSave() before it can be checked in or uploaded. This
             function does not save the model by default.
             <P><B>NOTE:</B>This function checks in the target objects by
             default.  To upload only use ProServercheckinoptsUploadonlySet().

    Input Arguments:
        mdl - The top level model to checkin or upload. Can be NULL (to check
              in or upload the entire workspace).
        options - An opaque handle to checkin or upload options. Pass NULL for
                  a default checkin (as per Creo Parametric's Checkin button in the File
                  menu).

    Output Arguments:
        conflicts - Information about checkin or upload conflicts. NULL if the
                    error return != PRO_TK_CHECKOUT_CONFLICT. Pass NULL if not
                    interested in conflicts details.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_BAD_CONTEXT - The primary server is not set and/or Design Test Mode 
                             is active - the function is not available in this mode.
        PRO_TK_CHECKOUT_CONFLICT - Conflicts occurred. Check the details in the
                                   conflicts return.
                                   

    See Also:
        ProServercheckinoptsAlloc()
        ProServercheckinoptsDeflocationSet()
        ProServercheckinoptsLocationAdd()
        ProServercheckinoptsBaselineSet()
        ProServercheckinoptsKeepcheckedoutSet()
        ProServercheckinoptsAutoresolveSet()
        ProServercheckinoptsUploadonlySet()
*/

extern ProError ProServercheckinoptsAlloc (ProServerCheckinOptions* opts);
/*
    Purpose: Allocates a new set of checkin/upload options. The properties of
             the options will match the default checkin/upload properties in
             Creo Parametric.

    Input Arguments:
        none

    Output Arguments:
        opts - The checkin/upload options.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProServercheckinoptsDeflocationSet (
                                                  ProServerCheckinOptions opts,
									              wchar_t* folder_location);
/*
    Purpose: Sets the default folder location in which objects not currently
             assigned a location will be assigned. Objects that already exist
             on the server and objects that are not checked in or uploaded will
             be unaffected by this option. Override specific object locations
             by using ProServercheckinoptsLocationAdd().

    Input Arguments:
        opts - The checkin/upload options.
        folder_location - The location folder path.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProServercheckinoptsLocationAdd (ProServerCheckinOptions opts,
									             wchar_t* model_name,
                                                 wchar_t* folder_location);
/*
    Purpose: Sets the folder location in which a particular object will be
             placed. If the object is not checked in or uploaded, setting this
             value will have no effect.

    Input Arguments:
        opts - The checkin/upload options.
        model_name - The name of the object.
        folder_location - The location folder path.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProServercheckinoptsBaselineSet (ProServerCheckinOptions opts,
                                                 ProBoolean create_baseline,
                                                 wchar_t* baseline_name,
                                                 wchar_t* baseline_number,
                                                 wchar_t* baseline_location,
                                                 wchar_t* baseline_lifecycle);
/*
    Purpose: Sets the baseline information to use for a given checkin
             operation.   Does not apply to upload operations.

    Input Arguments:
        opts - The checkin options.
        create_baseline - PRO_B_TRUE to create a new baseline upon checkin.
        baseline_name - The baseline name. This argument is mandatory and
                        cannot be NULL.
        baseline_number - The baseline number. Pass NULL to use the default
                          number.
        baseline_location - The baseline location. Pass NULL to use the default
                            location.
        baseline_lifecycle - The baseline lifecycle. Pass NULL to use the
                             default lifecycle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProServercheckinoptsKeepcheckedoutSet (
                                                  ProServerCheckinOptions opts,
									              ProBoolean keep_checked_out);
/*
    Purpose: Sets the keep checked out flag. If set to PRO_B_TRUE, checked-in
             objects would remain checked out after the checkin operation. The
             default value is false.  Does not apply to upload operations.


    Input Arguments:
        opts - The checkin options.
        keep_checked_out - The keep checked out flag.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProServercheckinoptsFree (ProServerCheckinOptions opts);
/*
    Purpose: Frees a set of checkin/upload options.

    Input Arguments:
        opts - The checkin options.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/


/*                     CHECKOUT                                             */
extern ProError ProServerObjectsCheckout (ProMdl mdl,  wchar_t* file, 
										ProBoolean checkout, 
										ProServerCheckoutOptions options,
										wchar_t** object_url, 
										ProServerCheckoutConflicts* conflicts);
/* 
Purpose: Checks out or downloads an object to the workspace.  Checkout rules 
are processed based on the Workspace config spec, unless the version is set 
using ProServercheckoutoptsVersionSet().  If the config spec is LATEST, 
for example, the latest version of the indicated object(s) will be checked out.
If an aliased URL path to the model is supplied, and more than one revision of 
the model is in the path, Creo Parametric will apply the workspace config spec 
rules against the objects which reside in that folder.

  Input Arguments:
   mdl         - The top level object to checkout.  Can be NULL.
   file        - The top level object to checkout or download.  Can be NULL. 
                 (One of mdl and aliased_url must not be NULL). This can be 
                 either an aliased URL to a given object or the object name. 
                 If an aliased URL path to the model is supplied, and more than
                 one revision of the model is in the path, Creo Parametric will 
                 apply the workspace config spec rules against the objects 
                 which reside in that folder.
   checkout    - PRO_B_TRUE to checkout and download, PRO_B_FALSE to download 
                 without checking out.
   options     - An opaque handle to checkout options. Pass NULL for a default
                 checkout (as per Creo Parametric's Checkout button in the File menu).
		
  Output Arguments:
   object_url - The url to the top level object in its downloaded/checked out
                location.  Free this string using ProWstringFree().
   conflicts  - Information about checkout conflicts. NULL if the error 
				return != PRO_TK_CHECKOUT_CONFLICT.  Pass NULL if not 
				interested in conflicts details.
	
  Return Values:
   PRO_TK_NO_ERROR          - The function succeeded.
   PRO_TK_BAD_INPUTS        - One or more inputs was invalid.
   PRO_TK_E_NOT_FOUND       - The top level object was not found.
   PRO_TK_BAD_CONTEXT       - The primary server is not set when mdl is passed.
   PRO_TK_CHECKOUT_CONFLICT - Conflicts occurred.  Check the details in the 
                              conflicts return.
*/

extern ProError ProServercheckoutoptsAlloc (ProServerCheckoutOptions* opts);
/*
	Purpose:  Allocates a new set of checkout options.  The properties of the 
              options will match the default checkout properties in 
              Creo Parametric.

	Input Arguments:
	 none
	
	Output Arguments:
	 opts - The checkout options.

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


typedef enum
{
	PRO_SERVER_DEPENDENCY_ALL,
	PRO_SERVER_DEPENDENCY_REQUIRED,
	PRO_SERVER_DEPENDENCY_NONE
} ProServerDependency;

extern ProError ProServercheckoutoptsDependencySet (ProServerCheckoutOptions opts, 
                                                    ProServerDependency dependency);
/*
	Purpose:  Sets the flag for the dependency rule used for the checkout 
              options.

    Input Arguments:
	 opts - The checkout options.
	 dependency - The dependency option.
	
	Output Arguments:
	 none

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


typedef enum
{
	PRO_SERVER_INCLUDE_ALL,
	PRO_SERVER_INCLUDE_SELECTED,
	PRO_SERVER_INCLUDE_NONE
} ProServerInclude;

extern ProError ProServercheckoutoptsIncludeinstancesSet (
                                              ProServerCheckoutOptions opts,
                                              ProServerInclude include_option,
                                              wchar_t** selected_includes);
/*
	Purpose:  Sets the flag for including instances in the checkout options.

	Input Arguments:
	 opts              - The checkout options.
	 include_option    - The include option.
	 selected_includes - ProArray of URL's to the selected includes, 
                         if include option = PRO_SERVER_INCLUDE_SELECTED.  
                         Can be NULL.
	
	Output Arguments:
	 none

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/



extern ProError ProServercheckoutoptsVersionSet (
                                              ProServerCheckoutOptions opts,
                                              wchar_t* version);
/*
	Purpose:  Sets the specific version of the object in the checkout options.
              Should be in the "Revision.Iteration" format. If the version
              is not set, it would be determinted based on the config spec.

	Input Arguments:
	 opts              - The checkout options.
	 version           - The version of the object to be checked out/added
                         to the workspace
	
	Output Arguments:
	 none

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


extern ProError ProServercheckoutoptsDownloadSet (
                                                ProServerCheckoutOptions opts,
                                                ProBoolean download);
/*
	Purpose:  Sets the flag for download or link in the checkout options 
              structure.  Applicable only if the application is checking 
              out the objects (PRO_B_TRUE passed to ProServerObjectsCheckout()
              argument checkout).

	Input Arguments:
	 opts     - The checkout options.
	 download - PRO_B_TRUE to download the checked out files,  
                PRO_B_FALSE to check out as a link.	
	
	Output Arguments:
	 none

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


extern ProError ProServercheckoutoptsReadonlySet (
                                                ProServerCheckoutOptions opts,
                                                ProBoolean readonly);
/*
	Purpose:  Sets the flag for readonly download or normal download
                  in the checkout options structure. 
                  Applicable only if the application is downloading 
                  without checking out (PRO_B_FALSE passed to 
                  ProServerObjectsCheckout() argument checkout).

	Input Arguments:
	 opts     - The checkout options.
	 readonly - PRO_B_TRUE to download as readonly, PRO_B_FALSE to download 
                    normally	
	
	Output Arguments:
	 none

	Return Values:
	 PRO_TK_NO_ERROR - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProServercheckoutoptsFree (ProServerCheckoutOptions opts);
/*
	Purpose:  Frees a set of checkout options.  

	Input Arguments:
	 opts - The checkout options.
	
	Output Arguments:
	 none

	Return Values:
	 PRO_TK_NO_ERROR   - The function succeeded.
	 PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProServerObjectStatusGet (wchar_t* server, wchar_t* workspace,
                                          wchar_t* object_name, 
                                          ProBoolean* checkout_status, 
                                          ProBoolean* modified);
/*
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProServerObjectIsModified
	Purpose:    <B><P>Note: This function is deprecated.  Use
                      ProServerObjectIsModified() instead. </P></B>

        Returns the status of the given object in the workspace.

	Input Arguments:
	 server            - The server alias.
	 workspace         - The workspace name.
     object_name       - The object name
	
	Output Arguments:
	 checkout_status   - PRO_B_TRUE if the object is currently checked out.
         modified          - PRO_B_TRUE if the object is modified locally.

	Return Values:
	 PRO_TK_NO_ERROR    - The function succeeded.
	 PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
	 PRO_TK_E_NOT_FOUND - The given object is not in the workspace.
     PRO_TK_BAD_CONTEXT - The server was not registered or 
                          the workspace couldn't be found on the server.

     See Also:
	 ProServerObjectsUpload()
*/

/*                        UPLOAD                                           */

extern ProError ProServerObjectsUpload (ProMdl mdl, 
										ProServerUploadConflicts* conflicts);
/*
    Purpose: Uploads an object to the database.
             <P><B>NOTE:</B> The model must be saved with ProMdlSave() prior to
             upload.
             <P><B>NOTE:</B> This function requires the object to be retrieved
             into memory; to upload all files in the workspace use
             ProServerObjectsCheckin() with the option
             ProServercheckinoptsUploadonlySet() as PRO_B_TRUE.


    Input Arguments:
        mdl - The top level model to upload.

    Output Arguments:
        conflicts - Information about upload conflicts. NULL if the error
                    return != PRO_TK_CHECKOUT_CONFLICT. Pass NULL if not
                    interested in conflicts details.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_E_NOT_FOUND - The top level object was not found.
        PRO_TK_BAD_CONTEXT - The primary server is not set.
        PRO_TK_CHECKOUT_CONFLICT - Conflicts occurred. Check the details in the
                                   conflicts return.
        PRO_TK_NOT_VALID - Upload called for an unsaved object. Please save and
                           then Upload.

*/

/*                                REMOVE                                     */
extern ProError ProServerObjectsRemove (wchar_t** model_names,
                                        ProServerRemoveConflicts* conflicts);
/*
  Purpose: Removes a list of models from a workspace.

  Input Arguments:
   model_names - A ProArray of model names to remove.
                 Pass NULL to remove all objects.

  Output Arguments:
   conflicts - Information about remove conflicts NULL if the error
               return != PRO_TK_CHECKOUT_CONFLICT or PRO_TK_E_NOT_FOUND.
               Pass NULL if not interested in conflicts details.

  Return Values:
   PRO_TK_NO_ERROR          - The function succeeded.
   PRO_TK_BAD_INPUTS        - One or more inputs was invalid.
   PRO_TK_E_NOT_FOUND       - One or more documents are not found.
                              Check the conflicts return.
   PRO_TK_BAD_CONTEXT       - The primary server is not set.
   PRO_TK_CHECKOUT_CONFLICT - Conflicts occurred.  Check the details in the
                              conflicts output.
*/

/*                              CONFLICTS                                  */
extern ProError ProServerconflictsDescriptionGet(ProServerConflicts conflict,
												 wchar_t** description);
/* 
   Purpose: Gets the description for a given conflict. This description is the
            exact string shown in Creo Parametric by the Server Console. This 
            description will be returned in the localized language of the 
            session.

   Input Arguments:
    conflict - Information about conflicts
		
   Output Arguments:
    description - The description of the conflict. Free this string using 
	              ProWstringFree().
   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
*/

extern ProError ProServerconflictsFree(ProServerConflicts conflict);
/* 
   Purpose: Frees the conflict structure returned by Creo Parametric TOOLKIT function.

   Input Arguments:
    conflict - the conflict structure

   Output Arguments:
    none
   
   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
	PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

extern ProError ProServerMultiobjectsCheckout (wchar_t** files,
                ProBoolean checkout,
                ProServerCheckoutOptions options,
                wchar_t*** object_url,
                ProServerCheckoutConflicts* conflicts);

/*
    Purpose: Checks out or downloads multiple objects to the workspace.
             Checkout rules are processed based on the Workspace config spec,
             unless the version is set using ProServercheckoutoptsVersionSet().
             If the config spec is LATEST, for example, the latest version of
             the indicated object(s) will be checked out.  If an aliased URL
             path to a model is supplied, and more than one revision of the
             model is in the path, Creo Parametric will apply the workspace
             config spec rules against the objects which reside in that folder.
 
    Input Arguments:
        files - ProArray of top level objects to checkout or download.  This
                can contain either aliased URLs to a given object or the object
                name. If an aliased URL path to the model is supplied, and more
                than one revision of the model is in the path, Creo Parametric
                will apply the workspace config spec rules against the objects
                which reside in that folder.
        checkout - PRO_B_TRUE to checkout and download, PRO_B_FALSE to download
                   without checking out.
        options - An opaque handle to checkout options. Pass NULL for a default
                  checkout (as per Creo Parametric's Checkout button in the File menu).
 
    Output Arguments:
        object_url - The url to the top level objects in its downloaded/checked
                     out location. Free this array using
                     ProWstringproarrayFree().
        conflicts - Information about checkout conflicts. NULL if the error
                    return != PRO_TK_CHECKOUT_CONFLICT. Pass NULL if not
                    interested in conflicts details.
 
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        PRO_TK_E_NOT_FOUND - The top level object was not found.
        PRO_TK_CHECKOUT_CONFLICT - Conflicts occurred. Check the details in the
                                   conflicts return.
 
    See Also:
        ProServerObjectsCheckout()
*/

typedef enum
  {
    PRO_SERVER_DONT_AUTORESOLVE, /* Don't autoresolve references to
				    models missing from the workspace,
				    which may result in a conflict. */
    PRO_SERVER_AUTORESOLVE_IGNORE, /* Autoresolve missing references
				     by ignoring them completely. */
    PRO_SERVER_AUTORESOLVE_UPDATE_IGNORE /* Autoresolve missing
                    references by looking for the models on the server,
                    and then ignoring any that cannot be matched. */
  } ProServerAutoresolveOption;



extern ProError ProServercheckinoptsAutoresolveSet (ProServerCheckinOptions options,
		    ProServerAutoresolveOption autoresolve);
/*
    Purpose: Sets the flag to autoresolve incomplete objects being checked in
             or uploaded.


    Input Arguments:
        options - The checkin/upload options.
        autoresolve - The autoresolve option to use. The default for this flag,
                      if not explicitly set, is PRO_SERVER_DONT_AUTORESOLVE,
                      which might cause a conflict if a model has a reference
                      to an object not in the workspace.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
extern ProError ProServercheckinoptsUploadonlySet (ProServerCheckinOptions options, ProBoolean upload_only);
/*
    Purpose: Sets the flag to fully checkin the target objects or only to
             upload them to the server.



    Input Arguments:
        options - The checkin/upload options.
        upload_only - PRO_B_TRUE to upload but not checkin the target objects,
                      PRO_B_FALSE to (possibly upload) and checkin the objects.
                      The default for this flag, if not explicitly set, is
                      PRO_B_FALSE, to cause a checkin..

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProServerObjectIsModified(wchar_t* server,
					  wchar_t* workspace,
                                          wchar_t* object_name, 
                                          ProBoolean* checkout_status, 
                                          ProBoolean* modifiedLocally,
					  ProBoolean* modifiedInWS);
/*
	Purpose:  Checks if the given object is modified in workspace/locally.

	Input Arguments:
	 server            - The server alias.
	 workspace         - The workspace name.
         object_name       - The object name

	Output Arguments:
	 checkout_status   - PRO_B_TRUE if the object is currently checked out to active workspace.
         		     PRO_B_FALSE for one of the following cases: 
                             <UL>
                             <LI>The object is not checked out.
                             <LI>The object is only uploaded to workspace, but was never checked in.
                             <LI>The object is only saved to local workspace cache, but was never uploaded.
                             </UL>
	 modifiedLocally   - PRO_B_TRUE if the object got modified locally.
	 modifiedInWS      - PRO_B_TRUE if the object got modified in Workspace.

	Return Values:
	 PRO_TK_NO_ERROR    - The function succeeded.
	 PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
	 PRO_TK_E_NOT_FOUND - The given object is not in the workspace.
         PRO_TK_BAD_CONTEXT - The server was not registered or 
                              the workspace couldn't be found on the server.

     See Also:
	 ProServerObjectsUpload()
*/

extern ProError ProServerIsOnline(wchar_t* serverAlias, ProBoolean* is_online);
/* 
   Purpose: Checks if specified server is online or offline.

   Input Arguments:
    serverAlias - The name used by Creo Parametric to refer to this server.

   Output Arguments:
    is_online -  PRO_B_TRUE if server is online, PRO_B_FALSE if server is offline.
                
   Return Values:
    PRO_TK_NO_ERROR      - The function succeeded.
    PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
    PRO_TK_E_NOT_FOUND   - The server was not registered.
    PRO_TK_GENERAL_ERROR - If any other error occurs.
*/

PRO_END_C_DECLS

#endif /*PRO_WT_UTILS_H*/
