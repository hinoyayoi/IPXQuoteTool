#ifndef PROFAMINSTANCE_H
#define PROFAMINSTANCE_H

/* Creo Parametric TOOLKIT declarations of ProFamtable related data structures */

#include <ProObjects.h>
#include <ProValue.h>
#include <ProParamval.h>
#include <ProMdl.h>

#include <ProFamtable.h>




PRO_BEGIN_C_DECLS


/* Data definitions */

typedef struct profaminstance
{
   ProName        name;
   ProFamtable    famtab;   /* handler of family table that keeps 
                               the instance */
} ProFaminstance;

typedef struct profaminstance  *ProFaminstanceList;

/* */
typedef enum famtab_inst_verify_status
{
  PRO_INST_SUCCESS_VERIFIED = 0,
  PRO_INST_FAILED_VERIFIED  = 1,
  PRO_INST_NOT_VERIFIED     =2
} ProFaminstanceVerifyStatus;

/* Function prototype for the action function for visiting instances */

typedef ProError (*ProFamtableInstanceAction) 
                                     (ProFaminstance    *instance,
                                      ProError          status,
                                      ProAppData        app_data
                                     );

/*
   Purpose:  This is a generic function for visiting family instances.

   Input Arguments:
      instance - The family instance
      status   - The status from the filter function
      app_data - The application data passed to the function
   
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR - Go to the next family instance.
      Other           - Causes visiting to stop and 
                        <b>ProFamtableInstanceVisit()</b> returns with the status.
*/

/* Function prototype for the filter function for visiting instances */

typedef ProError (*ProFamtableInstanceFilter) 
                                     (ProFaminstance    *mdl_item,
                                      ProAppData        app_data
                                     );

/*
   Purpose:  This is a generic function for visiting family instances.

   Input Arguments:
      mdl_item - The family instance
      app_data - The application data passed to the function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Call the visit function.
      PRO_TK_CONTINUE - Skip to next family instance -- do not call the
                        visit function.
*/

/************************************************************/

extern ProError ProFamtableInstanceVisit (ProFamtable *p_famtab,
        ProFamtableInstanceAction       visit_action,
        ProFamtableInstanceFilter       filter_action,
        ProAppData                      app_data);

/*
    Purpose: Visits all the instances in a family table.

    Input Arguments:
        p_famtab        - The handle to the family table.
        visit_action    - The action to perform on each instance. If
                          it returns anything other than
                          PRO_TK_NO_ERROR, visiting stops. 
        filter_action   - The filter function. If NULL, all instances 
                          are visited using the action function.
        app_data        - The application data passed to the
                          visiting and filter functions.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR - The function successfully visited all the instances.
        PRO_TK_BAD_INPUTS - One or more inputs was invalid.

        Other           - Any other value is the value returned by the action
                          function (visiting stopped). 
*/

/* Generic functions */

extern ProError ProFaminstanceInit (ProName        inst_name,
                                    ProFamtable    *p_famtab,
                                    ProFaminstance  *p_inst);

/*
   Purpose:     Initializes the instance handle. 

   Input Arguments:
      inst_name          -  The name of the instance.
      p_famtab           -  The handle to the family table.

   Output Arguments:
      p_inst             -  The pointer to the instance handle. You
                            must allocate the space for this argument.

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully initialized 
                                the handle.
      PRO_TK_BAD_INPUTS       - One or more of the input arguments 
                                are invalid.
*/



extern ProError ProFaminstanceCheck (ProFaminstance *p_inst,
                                     int           *locked);

/*
   Purpose:  Determines whether the specified instance exists in the family
             table and, if it exists, returns its lock status.     

   Input Arguments:
      p_inst             -  The instance handle.

   Output Arguments:
      locked             -  The lock status. If this is TRUE, the
                            instance is locked. 

   Return Values:
      PRO_TK_NO_ERROR         - The instance exists, and the function
                                successfully returned its lock status.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed (for example, the generic does not
                                exist in session, or the function could
                                not find the family table).
*/


extern ProError ProFaminstanceIsVerified (ProFaminstance   *p_inst,
                                          ProFaminstanceVerifyStatus *verified);

/*
   Purpose:  Determines whether the specified instance exists in the family
             table and, if it exists, returns its verify status.     

   Input Arguments:
      p_inst             -  The instance handle.

   Output Arguments:
      verified           -  The verify status:
                 PRO_INST_SUCCESS_VERIFIED - instance verified successfully
                 PRO_INST_FAILED_VERIFIED  - instance verified unsuccessfully
                 PRO_INST_NOT_VERIFIED     - instance ihas not been verified yet

   Return Values:
      PRO_TK_NO_ERROR         - The instance exists, and the function
                                successfully returned its verify status.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed (for example, the generic does not
                                exist in session, or the function could
                                not find the family table).
*/


extern ProError ProFaminstanceIsExtLocked (ProFaminstance *p_inst,
                                           ProBoolean     *locked);

/*
   Purpose:  Determines whether the specified instance exists in the family
             table and, if it exists, returns its lock status
             by external application.     

   Input Arguments:
      p_inst             -  The instance handle.

   Output Arguments:
      locked             -  The external lock status. If this is TRUE, the
                            instance is locked by external application. 

   Return Values:
      PRO_TK_NO_ERROR         - The instance exists, and the function
                                successfully returned its external lock status.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed (for example, the generic does not
                                exist in session, or the function could
                                not find the family table).
*/


extern ProError ProFaminstanceLock (ProFaminstance *p_inst,
                                    int           lock_it);

/*
   Purpose:     Locks or unlocks the specified instance.

   Input Arguments:
      p_inst             -  The instance handle.
      lock_it            -  If this is TRUE, lock the instance;
                            otherwise, unlock it.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully locked or unlocked
                                the instance. 
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed (for example, the generic does not
                                exist in session, or the function could
                                not find the family table).
*/


extern ProError ProFaminstanceAdd (ProFaminstance *p_inst);
/*
   Purpose:     Adds the specified instance to the family table.

   Input Arguments:
      p_inst             -  The instance handle

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully added the instance.
      PRO_TK_E_FOUND          - The specified instance already exists in the 
                                family table.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed (for example, the generic does not
                                exist in session, or the function could not 
                                find the family table).
      PRO_TK_ABORT            - Operation of adding instance is aborted
                                since the supplied name was already in use.
*/


extern ProError ProFaminstanceRemove (ProFaminstance *p_inst);
/*
   Purpose:     Deletes the specified instance from the family table.

   Input Arguments:
      p_inst             -  The instance handle

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully deleted the 
                                instance.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function 
                                failed (for example, the generic does not
                                exist in session, or the function could 
                                not find the family table).

*/


extern ProError ProFaminstanceValueGet (ProFaminstance *p_inst,
                                        ProFamtableItem *p_item,
                                        ProParamvalue *proval);

/*
   Purpose: Retrieves the value for the specified item for the instance.     

   Input Arguments:
      p_inst             -  The instance handle
      p_item             -  The model item

   Output Arguments:
      proval             -  The value in the family table of an item
                            that corresponds to the specified model
                            item for that instance 

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully retrieved the
                                information.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table, or the specified model
                                item is not table-driven.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the
                                function failed (for example, the function 
                                could not find the family table, or
                                the generic model).

*/


extern ProError ProFaminstanceValueSet (ProFaminstance *p_inst,
                                        ProFamtableItem *p_item,
                                        ProParamvalue *proval);

/*
   Purpose:  Modifies the value of the specified item for the instance.     

   Input Arguments:
      p_inst             -  The instance handle
      p_item             -  The model item
      proval             -  The value to set

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully modified the value.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table, or the specified model
                                item is not table-driven.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function 
                                failed (for example, the generic does not 
                                exist in session, or the function could 
                                not find the family table).
*/


extern ProError ProFaminstanceSelect( ProFamtable       *p_famtab,
                                      int                multiselect,
                                      int                *num_sels,
                                      ProFaminstanceList *instances );

/*
   Purpose:     Enables the user to select one or more instances in the specified
                family table.

   Input Arguments:
      p_famtab          -  The handle to the family table.
      multiselect       -  If you set this to TRUE, you can select more
                           than one instance.

   Output Arguments:
      num_sels          -  The number of instances selected.
      instances         -  The list of selected instances. The user must
                           allocate a ProArray for this argument, and call
                           ProArrayFree() when done with the data.

   Return Values:
      PRO_TK_NO_ERROR         - The user selected instances. 
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed (for example, the specified model
                                is not generic).
                                  
*/

extern ProError ProFaminstanceMdlGet (ProFaminstance *p_inst,
                                      ProMdl       *pp_model);

/*
   Purpose: Retrieves the handle to the instance model, if it is in session.    

   Input Arguments:
      p_inst             -  The handle to the instance.

   Output Arguments:
      pp_model           -  The handle to the instance model. You must
                            allocate the space for this argument.

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully retrieved the
                                handle. 
      PRO_TK_E_NOT_FOUND      - The specified instance model is not in 
                                session.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed.
*/

extern ProError ProFaminstanceGenericGet (ProMdl   inst_model,
                                          int       immediate,
                                          ProMdl   *gen_model);
/*
   Purpose:    Retrieves the generic model, given its handle. 

   Input Arguments:
      inst_model         - The handle to the instance model.
      immediate          - If you set this to TRUE, the system searches
                           for the immediate generic. If this is FALSE,
                           the system searches for the top-level generic.

   Output Arguments:
      gen_model          - The handle to the top-level or immediate generic 
                           model.

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully retrieved the
                                handle.
      PRO_TK_E_NOT_FOUND      - The specified model is not an instance --  
                                it has no generic model.
      PRO_TK_CANT_OPEN        - The immediate generic is not in session
                                ('immediate' is set to TRUE). Use
                                 <b>ProFaminstanceImmediategenericinfoGet()</b>
                                to obtain the name and modeltype of immediate
                                generic in such case.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the
                                function failed.
*/

extern ProError ProFaminstanceImmediategenericinfoGet (ProMdl      inst_model,
                                                       ProName     gen_name,
                                                       ProMdlType *p_gen_type);
/*
  Purpose:    Retrieves the name and model type of the immediate generic model.

  Input Arguments:
     inst_model       -  The handle to the instance model.

  Output Arguments:
     gen_name         -  The name of the immediate generic model.
     p_gen_type       -  The model type of immediate generic model.
                         If the function fails, this is
                         set to PRO_TYPE_UNUSED.

  Return Values:
     PRO_TK_NO_ERROR         - The function successfully retrieved the
                               name and model type.
     PRO_TK_E_NOT_FOUND      - The specified model is not an instance --
                               it has no generic model.
     PRO_TK_GENERAL_ERROR    - The function failed.
*/


extern ProError ProFaminstanceCreate (ProFaminstance    *proinst,
                                      ProMdl            *inst_model);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProFaminstanceRetrieve 
   Purpose:     Creates an instance model of the specified instance 
                handle.
                <P> Note: if this succeeds, this also verifies the
                    instance in the family table.
                <P> Note: This function is deprecated. Use ProFaminstanceRetrieve 
                    instead.

   Input Arguments:
      proinst           - The instance handle

   Output Arguments:
      inst_model        - The handle to the instance model

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully created the 
                                instance model.
      PRO_TK_E_NOT_FOUND      - The specified instance does not exist in
                                the family table, or the specified model
                                item is not table-driven.
      PRO_TK_GENERAL_ERROR    - A general error occurred and the function
                                failed.
      PRO_TK_CANT_OPEN        - Creo Parametric cannot regenerate the instance.
                                The instance has been created but the failed
                                features have been suppressed.
*/

extern ProError ProFaminstanceErase (ProFaminstance   *proinst);

/*
   Purpose:    Erases the specified instance model from memory. 

   Input Arguments:
      proinst           - The instance handle

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully erased the model.
        PRO_TK_E_NOT_FOUND      - The specified instance model is not in 
                                  session.
        PRO_TK_GENERAL_ERROR    - A general error occurred and the
                                  function failed. 
*/

extern ProError ProFaminstanceRetrieve (
                              ProFaminstance   *p_inst,
                              ProMdl           *pp_model);
/*
   Purpose:  Retrieves an instance of a model from disk.

   Input Arguments:
     p_inst                - The instance to retrieve.
 
   Output Arguments:
      pp_model             -  The handle to the instance model. You must
                              allocate the space for this argument.
 
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             model.
      PRO_TK_E_NOT_FOUND   - The specified instance model was not found
                             on disk.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function
                             failed.
*/
 
extern ProError ProFaminstanceIsModifiable (ProFaminstance* p_inst, 
                                            ProBoolean show_ui,
                                            ProBoolean* can_modify);
/*
   Purpose: Check if a given instance is modifiable.

   Input Arguments:
     p_inst       - instance to check access to.
     show_ui      - Indicates whether the Conflicts dialog should be shown to
                    user to resolve conflicts (if they are detected); when set
                    to PRO_B_FALSE no UI is enabled and the instance is 
                    considered as modifiable if there are no conflicts that 
                    could not be overridden or resolved by default resolution 
                    actions.
                              
   Output Arguments:
      can_modify  -  The access status. If it is PRO_B_TRUE, the
                     instance is modifiable. 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more arguments are invalid.
      PRO_TK_GENERAL_ERROR - The function could not check access to the
                             instance.
*/


extern ProError ProFaminstanceFamtableItemIsDefault (ProFaminstance  *p_inst,
                                                     ProFamtableItem *p_item,
                                                     ProBoolean      *is_default);
/*
   Purpose: Determines if the value of the specified item for the
            specified instance is the default value.

   Input Arguments:
      p_inst - The instance handle.
      p_item - The family table item

   Output Arguments:
      is_default - This is PRO_B_TRUE, if the instance has default
                  value for specified item.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The specified instance does not exist in
                             the family table, or the specified model
                             item is not table-driven.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed
                             (for example, the function could not find
                             the family table, or the generic model).
*/


PRO_END_C_DECLS

#endif  /* PROFAMINSTANCE_H */

