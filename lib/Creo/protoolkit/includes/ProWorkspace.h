

#ifndef PROWORKSPACE_H
#define PROWORKSPACE_H

#include <ProANSI.h>
#include <ProSizeConst.h>

PRO_BEGIN_C_DECLS

typedef struct pro_impex_message*  ProWSImpexMessage;

typedef enum
{
  PRO_WSIMPEX_MSG_INFO     = 0,   /* no problem, just an information */
  PRO_WSIMPEX_MSG_WARNING  = 1,   /* a low severity problem resolved according 
                                     to some configured rules */
  PRO_WSIMPEX_MSG_CONFLICT = 2,   /* an overridable conflict */
  PRO_WSIMPEX_MSG_ERROR    = 3    /* a non overridable conflict or another 
                                     serious problem preventing from processing
                                     an object */
} ProWSImpexMessageType;

extern ProError ProWorkspaceRegister (ProName WorkspaceName);
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProServerRegister
   Purpose: <P><B>NOTE:</B> This function is deprecated. 
   	    Pro/INTRALINK 3.4 is not supported.  Please use 
            Pro/INTRALINK 10.0 function ProServerRegister() instead.</P>
            Registers a Workspace in Creo Parametric.  Only one is allowed
	    at a time, so if one is already registered, the new one will
	    substitute the current one, but only if there are no objects in
	    session (see error status descriptions).

   Input Arguments:
      WorkspaceName     - The name of the Workspace

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully registered the Workspace.
      PRO_TK_BAD_INPUTS - The argument is invalid.
      PRO_TK_E_BUSY     - When another workspace is already registered,
			  cannot de-register because there are objects in
			  Creo Parametric session.
*/


extern ProError ProCurrentWorkspaceGet(ProName rCurrentWorkspace);
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProServerWorkspaceGet,ProServerWorkspacesCollect
   Purpose: <P><B>NOTE:</B> This function is deprecated.
   Pro/INTRALINK 3.4 is not supported.   
   Please use Pro/INTRALINK 10.0 function ProServerWorkspaceGet() or 
   ProServerWorkspacesCollect() instead.</P>
	    Returns the name of the Workspace currently registered 
	    in Creo Parametric. 
		
   Input Arguments:
      None

   Output Arguments:
      rCurrentWorkspace - The returned name

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully returned the name.
      PRO_TK_E_NOT_FOUND - There was no Workspace registered.
*/


extern ProError ProObjModelsCheckOut ( ProBoolean linkOrCopy,
                                ProName       workspaceName,
                                int           objNo,
                                ProFileName   *objNames,
                                int           *objVersions,
                                int           relCriteria );
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProServerObjectsCheckout,ProServerMultiobjectsCheckout
   Purpose: <P><B>NOTE:</B> This function is deprecated.
   		Pro/INTRALINK 3.4 is not supported.   
                Please use Pro/INTRALINK 10.0 functions 
                ProServerObjectsCheckout() or 
                ProServerMultiobjectsCheckout() instead.</P>
            Checks out the latest version of Pro/INTRALINK objects
            from the Commonspace to a Workspace using a  
            a non-Pro/INTRALINK process.


   Input Arguments:
      linkOrCopy    - If this is PRO_B_TRUE, check out the object as a copy;
		      otherwise, check out as a link.
      workspaceName - The name of the Workspace to which the objects are
		      checked out.
      objNo         - The number of objects to check out.
      objNames      - An array of names of objects to check out, in the format
                      "object.ext".
      objVersions   - Reserved for future use. Pass NULL.
      relCriteria   - The relationship criteria. This argument identifies which
                      dependents should be checked out with the <i>objNames</i>.
                      The possible values are as follows:
                      <ul>
                      <li>1 -- Include all the dependents.
                      <li>2 -- Include the required dependents only.
                      <li>3 -- Do not include any dependents.
                      </ul>

   Output Arguments:
      None

   Return Values:
     PRO_TK_NO_ERROR        - The function successfully checked out the 
                              objects.
     PRO_TK_BAD_INPUTS      - The specified number of objects is less than zero,
			      the relationship criteria is not valid, the 
                              Workspace name is invalid, or the object versions 
                              do not exist.
     PRO_TK_E_NOT_FOUND     - The specified objects were not found in the 
                              Commonspace; or the Pro/INTRALINK Client is not in
                              the latest frame when attempting the checkout.  
     PRO_TK_COMM_ERROR      - A Pro/INTRALINK Client is not available, and the
                              Creo Parametric user has not registered Pro/INTRALINK
                              as a server. (This function will work if the
                              Pro/INTRALINK client has been authenticated
                              previously through the Creo Parametric dialog.) 
     PRO_TK_NOT_IMPLEMENTED - Initially, some of the options above might not 
                              be implemented.
     PRO_TK_GENERAL_ERROR   - Another problem occurred and the function failed.
*/


extern ProError ProObjRenamedInWSSessionSync ( 
                            ProFileName  objOldName,
                            ProFileName  objNewName,
                            ProFileName  genericName );
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: NONE
   Purpose: <P><B>NOTE:</B> This function is deprecated. Pro/INTRALINK 3.4 is not supported.</P>
            Renames the object in Creo Parametric memory space when an object is
            renamed in Pro/Intralink's Workspace from "objOldName" to
            "objNewName". If the object is an instance then it's
            generic object's name "genericName" must be passed in.
		
   Input Arguments:
      objOldName		- The original name of the object.
	  objNewName		- The new name to which object has to be renamed to.
	  genericName		- name of the generic if the object being renamed is
						  an instance or NULL.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully updated the name.
      PRO_TK_INVALID_NAME  - One or more of the input name is not correct.
                             They are null, have null or unsupported
                             extensions or all three do not have the same
                             extension.
      PRO_TK_GENERAL_ERROR -  Another problem occurred and the function failed.
*/

typedef enum
{
  PRO_WS_IMPEX_ALL        = 0,
  PRO_WS_IMPEX_REQUIRED   = 1,
  PRO_WS_IMPEX_NONE       = 2

} ProWorkspaceImpExDepCriterion;

extern ProError ProCurrentWorkspaceImport(ProWorkspaceImpExDepCriterion dep_criterion,
                                          wchar_t** source_objects);
/*
  Purpose:  Import specified objects from a disk to the current workspace in
            a linked session of Creo Parametric. Can be called only when there 
            are no objects in session (see error status descriptions). The
            specified objects may be imported along with all or required by
            Creo Parametric dependents (recursively), according to a specified
            dependency criterion. All problems (warnings, conflicts or errors)
            of processing individual objects are logged in proimpex.errors 
            file created in the Creo Parametric run directory. In addition,
            warnings and information messages are logged in proimpex.log file.

  Input Arguments:
            dep_criterion   - the dependency criterion,
            source_objects  - a ProArray of paths (absolute or relative to 
                              current working directory) to objects to import.

  Output Arguments:
            None

  Return Values:
            PRO_TK_NO_ERROR   - all the specified objects and their specified
                                dependents have been processed; proimpex.errors
                                still to be checked for possible problems with
                                individual objects
            PRO_TK_BAD_INPUTS - one or more arguments was invalid
            PRO_TK_E_BUSY     - cannot import because there are objects in
                                Creo Parametric session
            PRO_TK_E_NOT_FOUND - no workspace registered as current 
                                (or non linked session)
            PRO_TK_GENERAL_ERROR - an error caused the entire operation to fail.
*/

extern ProError ProCurrentWorkspaceExport(ProWorkspaceImpExDepCriterion dep_criterion,
                                          wchar_t** source_objects,
                                          ProPath   target_path);
/*
  Purpose:  Export specified objects from the current workspace to a disk in
            a linked session of Creo Parametric. Can be called only when there 
            are no objects in session (see error status descriptions). The
            specified objects may be exported along with all or required by
            Creo Parametric dependents (recursively), according to a specified
            dependency criterion. All problems (warnings, conflicts or errors)
            of processing individual objects are logged in proimpex.errors 
            file created in the Creo Parametric run directory. In addition,
            warnings and information messages are logged in proimpex.log file.

  Input Arguments:
            dep_criterion   - the dependency criterion,
            source_objects  - a ProArray of names of objects to export,
            target_path     - the export target directory.

  Output Arguments:
            None

  Return Values:
            PRO_TK_NO_ERROR   - all the specified objects and their specified
                                dependents have been processed; proimpex.errors
                                still to be checked for possible problems with
                                individual objects
            PRO_TK_BAD_INPUTS - one or more arguments was invalid
            PRO_TK_E_BUSY     - cannot export because there are objects in
                                Creo Parametric session
            PRO_TK_E_NOT_FOUND - no workspace registered as current 
                                (or non linked session)
            PRO_TK_INVALID_DIR - bad or inaccessible target_path
            PRO_TK_GENERAL_ERROR - an error caused the entire operation to fail.
*/

extern ProError ProCurrentWorkspaceImpexMessagesGet (ProWSImpexMessage** messages);
/*
    Purpose: Returns an array of messages generated by the last call to
             ProCurrentWorkspaceImport() or ProCurrentWorkspaceExport().

    Input Arguments:
        none

    Output Arguments:
        messages - ProArray of messages.  Free this using 
                   ProWsimpexmessageArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No messages are available.

*/

extern ProError ProWsimpexmessageDataGet (ProWSImpexMessage msg, ProWSImpexMessageType* type, ProPath object, ProComment description, ProComment resolution, ProBoolean* succeeded);
/*
    Purpose: Extract the contents of an import/export message (returned by
             ProWorkspaceImpexMessagesGet()).

    Input Arguments:
        msg - The message.

    Output Arguments:
        type - Severity of this message. Can be NULL.
        object - The object name or pathname. Can be NULL.
        description - Specific description of the problem or information. Can be
                      NULL.
        resolution - Resolution applied to resolve an overridable conflict 
                     (applicable when type returned PRO_IMPEX_MSG_CONFLICT),
                     Can be NULL.
        succeeded - indicates whether the above resolution succeded or not 
                    (applicable when type returned PRO_IMPEX_MSG_CONFLICT).
                    Can be NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProWsimpexmessageArrayFree (ProWSImpexMessage* msg_array);
/*
    Purpose: Free memory associated with the array of message objects returned 
             by ProWorkspaceImpexMessagesGet().

    Input Arguments:
        msg_array - ProArray of messages.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - The argument was invalid.

*/


extern ProError ProWsexportSecondarycontentoptionSet (ProBoolean flag);
/*
    Purpose: Set option controlling export of secondary contents.

    Input Arguments:
        flag - PRO_B_TRUE if export of secondary contents is on (default 
	       behavior), PRO_B_FALSE if export of secondary contents is off

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.

*/

extern ProError  ProWsimpexFolderoptionSet (wchar_t* folder);
/*
   Purpose: Set a workspace folder to import/export data to/from
            (when applicable).

   Input Arguments:
        folder - relative path to a workspace folder (from workspace root). Can be NULL.

   Output Arguments:
       none

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
*/

PRO_END_C_DECLS

#endif /* PROWORKSPACE_H */
