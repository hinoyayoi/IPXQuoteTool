#ifndef PRO_EXTOBJ_H
#define PRO_EXTOBJ_H

/* Creo Parametric TOOLKIT declarations for Pro<object> related data structures */

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProGeomitem.h>



PRO_BEGIN_C_DECLS


/* Data definitions */

typedef enum
{
   PRO_EXTOBJDAT_DISPLAY        = 1,
   PRO_EXTOBJDAT_SELBOX         = 2
} ProExtobjdataType;


typedef enum
{
   PRO_EO_ALT_DISPLAY     = (1 << 6), /* alternate display */
   PRO_EO_ALT_SELECT      = (1 << 7), /* alternate selection */
   PRO_EO_ACT_OWN_MODIF   = (1 << 9),
   PRO_EO_ACT_OWN_SUPPR   = (1 << 10),
   PRO_EO_ACT_OWN_DELETE  = (1 << 11),
   PRO_EO_ACT_REF_MODIF   = (1 << 13),
   PRO_EO_ACT_REF_SUPPR   = (1 << 14),
   PRO_EO_ACT_REF_DELETE  = (1 << 15)
} ProExtobjAction;


/* ATTENTION: Adding a new action to be supported by the warning mechanism,
              it must be also added to PRO_EO_ALL_ACTIONS mask */

#define  PRO_EO_ALL_ACTIONS  (PRO_EO_ACT_OWN_MODIF | PRO_EO_ACT_OWN_SUPPR |  \
                               PRO_EO_ACT_OWN_DELETE | PRO_EO_ACT_REF_MODIF | \
                               PRO_EO_ACT_REF_SUPPR | PRO_EO_ACT_REF_DELETE)

/*===========================================================================*/

typedef struct Pro_Extobjdata *ProWExtobjdata;


/* Generic functions */

extern ProError ProExtobjClassCreate (ProExtobjClass *extobjclass);

/*
   Purpose:     Registers a new external object class.

   Input Arguments:
      extobjclass       - The handle to the external object class

   Output Arguments:
        None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully registered the external
                             object class.
      PRO_TK_E_FOUND       - The external object class already exists.
      PRO_TK_BAD_INPUTS    - There was an empty name or a negative 
                             type in the handle.
      PRO_TK_GENERAL_ERROR - The registration of the external object class was
                             aborted.
*/

extern ProError ProExtobjClassDelete (ProExtobjClass *extobjclass);

/*
   Purpose:     Deletes the specified external object class.

   Input Arguments:
      extobjclass       - The handle to the external object class.
                          If <i>extobjclass->type</i> == PRO_VALUE_UNUSED, the
                          function deletes all the classes that have
                          <i>extobjclass->name</i>.

   Output Arguments:
        None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully deleted the external
                             object class.
      PRO_TK_E_NOT_FOUND   - The external object class was not found.
      PRO_TK_BAD_INPUTS    - There was an empty name in the class handle.
      PRO_TK_GENERAL_ERROR - The registration of the external object class
                             was aborted.
*/


extern ProError ProExtobjCreate (ProExtobjClass  *extobjclass,
                                          ProModelitem    *owner,
                                          ProExtobj       *result_obj);
/*
   Purpose:     Creates a new external object.

   Input Arguments:
      extobjclass       - The handle to the external object class.
      owner             - The handle to the owner solid or item.


   Output Arguments:
      result_obj        - The handle to the newly created external object. You
                          must have previously allocated the memory for this
                          argument. 
   Return Values:
      PRO_TK_NO_ERROR           - The function successfully created the 
                                  external object.
      PRO_TK_E_NOT_FOUND        - The external object class is not registered,
                                  or the owner was not found.
      PRO_TK_GENERAL_ERROR      - The external object creation was aborted.
                 
*/

extern ProError ProExtobjDelete (ProExtobj      *object,
                                 ProExtobjClass *extobjclass);
/*
   Purpose:     Deletes the specified external object.

   Input Arguments:
      extobjclass       - The handle to the external object class

      object            - The handle of the external object to delete

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully deleted the
                                  external object.
        PRO_TK_E_NOT_FOUND      - The owner was not found.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not delete the object.
*/

typedef ProError (*ProExtobjVisitAction) ( ProExtobj *p_extobj, 
                                           ProError status, 
                                           ProAppData app_data );

/*
   Purpose:  This is the user function prototype called
             for visiting external objects.

   Input Arguments:
      p_extobj          - The handle to the model
      status            - The status
      app_data          - The application data passed from the function
                          <b>ProExtobjVisit()</b>
   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR    - Continue.
*/

typedef ProError (*ProExtobjFilterAction) ( ProExtobj *p_extobj, 
                                            ProError status, 
                                            ProAppData app_data );
/*
   Purpose:  This is the user function prototype called
             for visiting external objects.

   Input Arguments:
      p_extobj          - The handle to the model
      status            - The status
      app_data          - The application data passed from the function
                          <b>ProExtobjVisit()</b>
   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR    - Continue.

*/

extern ProError ProExtobjVisit (ProMdl                model, 
                                ProExtobjClass       *extobjclass,
                                ProExtobjVisitAction  visit_action,
                                ProExtobjFilterAction filter_action, 
                                ProAppData            app_data);
/*
   Purpose:    Performs an action on several external objects.

   Input Arguments:
      model                     - The handle to the model.
      extobjclass               - The handle to the external object class. 
      visit_action              - The action to perform on each external 
                                  object. If the function returns anything
                                  other than PRO_TK_NO_ERROR, visiting ends.
      filter_action             - The filter function. If NULL, all external 
                                  objects are visited using the action function.
      app_data                  - The application data passed to the
                                  visiting and action functions.

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully visited all
                                  the parameters.
        PRO_TK_E_NOT_FOUND      - The function could not find the needed 
                                  objects.
        PRO_TK_BAD_INPUTS       - One or more of the input arguments are 
                                  invalid.
        PRO_TK_BAD_CONTEXT      - The owner was not found.
        Other                   - The action function returned an error.
*/


/* Owner object (local) - related functions */
 
extern ProError ProExtobjOwnerobjGet (ProExtobj      *object,
                                      ProExtobjClass *extobjclass,
                                      ProModelitem   *owner);
/*
   Purpose:     Retrieves the owner of an existing external object.

   Input Arguments:
      object            - The handle to the external object

      extobjclass       - The handle to the external object class

   Output Arguments:
      owner             - The handle to the owner 

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully retrieved the
                                  information.
        PRO_TK_E_NOT_FOUND      - The owner was not found.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not retrieve the
                                  information.
*/

extern ProError ProExtobjOwnerobjSet (ProExtobj      *object,
                                      ProExtobjClass *extobjclass,
                                      ProModelitem   *owner);
/*
   Purpose:     Sets the owner of an existing external object.

   Input Arguments:
      object            - The handle to the external object

      extobjclass       - The handle to the external object class

      owner             - The handle to the owner solid or item

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully set the owner.
        PRO_TK_E_NOT_FOUND      - The owner was not found.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not set the owner.
*/


extern ProError ProExtobjReusableSet (ProExtobj        *object);
/*
   Purpose:     Sets the reuse attribute for the specified external object.

   Input Arguments:
      object            - The handle to the external object

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully set the attribute.
        PRO_TK_BAD_INPUTS       - The specified handle was incorrect.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not set the attribute.
*/
                
extern ProError ProExtobjReusableGet (ProExtobj        *object);
/*
   Purpose:     Checks for the existence of the reuse attribute of the
                specified external object.

   Input Arguments:
      object            - The handle to the external object

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The reuse attribute is set.
        PRO_TK_NOT_FOUND        - The reuse attribute is not set.
        PRO_TK_BAD_INPUTS       - The specified handle was incorrect.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not retrieve information.
*/

extern ProError ProExtobjReusableClear (ProExtobj        *object);

/*
   Purpose:     Clears the reuse attribute from the specified
                external object.

   Input Arguments:
      object            - The handle to the external object

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully cleared the
                                  attribute.
        PRO_TK_BAD_INPUTS       - The specified handle was incorrect.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not clear the attribute.
*/


/* Generic data-related functions */

extern ProError ProExtobjdataAdd (ProExtobj        *object, 
                                  ProExtobjClass   *extobjclass,
                                  ProWExtobjdata    obj_data);
/*
   Purpose:     Adds data to an existing external object.

   Input Arguments:
      object            - The handle to the external object

      extobjclass       - The handle to the external object class

      obj_data          - The data to add

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully added the data.
        PRO_TK_BAD_INPUTS       - One or more of the input arguments are
                                  invalid.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or the
                                  function could not add the data. 
*/ 

extern ProError ProExtobjdataSet (ProExtobj        *object,
                                  ProExtobjClass   *extobjclass,
                                  ProWExtobjdata    obj_data);
/*
   Purpose:     Modifies the existing data in the specified object.

   Input Arguments:
      object            - The handle to the external object
      extobjclass       - The handle to the external object class 
      obj_data          - The data pointer to add

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully set the data.
        PRO_TK_BAD_INPUTS       - The data was incorrect.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not set the data.
*/

extern ProError ProExtobjdataRemove (ProExtobj        *object,
                                     ProExtobjClass   *extobjclass,
                                     ProExtobjdataType type);
/*
   Purpose:     Removes object data from an existing external object.

   Input Arguments:
      object            - The handle to the external object
      extobjclass       - The handle to the external object class
      type              - The data type to be removed

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully deleted the data.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not delete the data.
*/

extern ProError ProExtobjdataGet (ProExtobj         *object, 
                                  ProExtobjClass    *extobjclass,
                                  ProExtobjdataType  type,
                                  ProWExtobjdata    *obj_data);
/*
   Purpose:     Retrieves the object data from an existing external object. 

   Input Arguments:
      object            - The handle to the external object
      extobjclass       - The handle to the external object class
      type              - The data type

   Output Arguments:
      obj_data          - The pointer to the object data.  Free this data 
                          using ProExtobjdataFree().

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully retrieved the data.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not retrieve the data.
*/
            
extern ProError ProExtobjdataFree (ProWExtobjdata   *disp_data);
/*
   Purpose:     Clears the display data for the specified external object.

   Input Arguments:
      disp_data         - The pointer to the object data

   Output Arguments:
      None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully cleared the data.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not clear the data.
*/


/* Class of External object */

extern ProError ProExtobjClassGet (ProExtobj         *object,
                                   ProExtobjClass    *extobjclass);
/*
   Purpose:     Retrieves the handle to the object class of the specified
                external object. 

   Input Arguments:
      object          -  The handle to the external object.

   Output Arguments:
      extobjclass     -  The handle to the object class. You must allocate
                         the memory for this argument.

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully retrieved the handle.
      PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                the function could not retrieve the handle. 
*/

/* External owner identifier and type */

extern ProError ProExtobjExtidSet (ProExtobj     *object,
                                   int            external_id);
/*
   Purpose:     Sets the external owner identifier of the specified
                external object.

   Input Arguments:
     object          - The handle to the external object
     external_id     - The external owner identifier

   Output Arguments:
     None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully set the identifier.
        PRO_TK_BAD_INPUTS       - The identifier was incorrect.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not set the identifier.
*/


extern ProError ProExtobjExtidGet (ProExtobj  *object,
                                   int        *p_external_id);
/*
   Purpose:     Retrieves the external owner identifier for the
                specified external object.
 
   Input Arguments:
     object            - The handle to the external object

   Output Arguments:
     p_external_id     - The external owner identifier

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully retrieved the
                                  information.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not retrieve the
                                  information.
*/


extern ProError ProExtobjExttypeSet (ProExtobj   *object,
                                     int          external_type);
/*
   Purpose:     Sets the external owner type for the specified external
                object.
 
   Input Arguments:
     object          - The handle to the external object
     external_type   - The type of external owner

   Output Arguments:
     None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully set the type.
        PRO_TK_BAD_INPUTS       - One or more of the arguments are invalid.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or the
                                  function could not set the type.
*/


extern ProError ProExtobjExttypeGet (ProExtobj   *object,
                                     int         *p_external_type);
/*
   Purpose:     Retrieves the owner type of the specified external 
                object.

   Input Arguments:
     object          - The handle to the external object

   Output Arguments:
     p_external_type   - The type of the external owner

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully retrieved the
                                  information.
        PRO_TK_GENERAL_ERROR    - The external object was not found, or
                                  the function could not retrieve the
                                  information.
*/


/* External Object Warnings */
/* Enabling warnings upon actions with owner/reference of Extobj 
    (In Release 19.0, only warnings for PRO_EO_ACT_REF_SUPPR and 
     PRO_EO_ACT_REF_DELETE actions are supported.)
*/

extern ProError ProExtobjClassWarningEnable (ProExtobjClass   *extobjclass, 
                                             ProExtobjAction  extobjaction);

/*
   Purpose:     Enables warnings upon the specified action
                for the external object class (so any objects of this
                class that are subsequently created will inherit 
                the enabled warning).
 
   Input Arguments:
     extobjclass       - The handle to the external object class
     extobjaction      - The action type for which the warning is enabled
 
   Output Arguments:
     None
 
   Return Values:
        PRO_TK_NO_ERROR         - The warning is enabled for the specified
                                  external object class.
        PRO_TK_BAD_INPUTS       - You specified an invalid class handle or an
                                  unsupported action.
        PRO_TK_GENERAL_ERROR    - The external object class was not found, 
                                  or another problem occurred.
*/


extern ProError ProExtobjClassWarningDisable (ProExtobjClass   *extobjclass,
                                              ProExtobjAction  extobjaction);

/*
   Purpose:     Disables warnings upon the specified action
                for the external object class (so created objects of this class
                that are subsequently created will inherit the disabled warning). 
 
   Input Arguments:
     extobjclass       - The handle to the external object class
 
     extobjaction      - The action type for which the warning is disabled
 
   Output Arguments:
     None
 
   Return Values:
        PRO_TK_NO_ERROR         - The warning is disabled for the specified
                                  external object class.
        PRO_TK_BAD_INPUTS       - You specified an invalid class handle or an
                                  unsupported action.
        PRO_TK_GENERAL_ERROR    - The external object class was not found, 
                                  or another problem occurred.
*/


extern ProError ProExtobjWarningEnable (ProExtobj        *object, 
                                        ProExtobjAction  extobjaction);
 
/*
   Purpose:     Enables warnings upon the specified action
                for the specified external object.
 
   Input Arguments:
     object            - The handle to the external object
     extobjaction      - The action type for which the warning is enabled
 
   Output Arguments:
     None
 
   Return Values:
        PRO_TK_NO_ERROR         - The warning is enabled for the specified 
                                  external object.
        PRO_TK_BAD_INPUTS       - You specified an invalid external object
                                  handle or an unsupported action.
        PRO_TK_GENERAL_ERROR    - The external object was not found,
                                  or another problem occurred.
*/


extern ProError ProExtobjWarningDisable (ProExtobj        *object,
                                         ProExtobjAction  extobjaction);
 
/*
   Purpose:     Disables warnings upon the specified action
                for the specified external object.
 
   Input Arguments:
     object            - The handle to the external object
     extobjaction      - The action type for which the warning is disabled
 
   Output Arguments:
     None
 
   Return Values:
        PRO_TK_NO_ERROR         - The warning is disabled for the specified 
                                  external object.
        PRO_TK_BAD_INPUTS       - You specified an invalid external object
                                  handle or an unsupported action.
        PRO_TK_GENERAL_ERROR    - The external object was not found,
                                  or another problem occurred.
*/



PRO_END_C_DECLS

#endif /* PRO_EXTOBJ_H */

