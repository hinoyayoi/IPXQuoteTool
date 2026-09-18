#ifndef PRO_EXTOBJREF_H
#define PRO_EXTOBJREF_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSelection.h>



PRO_BEGIN_C_DECLS

/* Creo Parametric TOOLKIT external object reference - related functions */

typedef struct attach_point *ProWExtobjRef;

typedef struct
{
  ProSelection    prosel;
  int             user_type;
} ProExtobjRefInfo;

typedef enum
{
  PRO_EXTOBJREF_ACTIVE      = 1,
  PRO_EXTOBJREF_SUPPRESSED  = 2,
  PRO_EXTOBJREF_MISSING     = 3
} ProExtobjrefStatus;

extern ProError ProExtobjRefAlloc (ProWExtobjRef *ext_obj_ref);
/*
   Purpose:   Allocates the memory for the external object reference.

   Input Arguments:
     None

   Output Arguments:
     ext_obj_ref          - The pointer to the external object reference 

   Return Values:
        PRO_TK_NO_ERROR       -  The function successfully allocated the
                                 memory.
        PRO_TK_GENERAL_ERROR  -  The function could not allocate the
                                 memory.
*/


extern ProError ProExtobjRefFree (ProWExtobjRef *ext_obj_ref);
/*
   Purpose:     Frees the memory allocated for the external object reference.

   Input Arguments:
     ext_obj_ref          - The pointer to the external object reference 

   Output Arguments:
     None

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully freed the memory.
        PRO_TK_BAD_INPUTS     - The external object reference was not found.
        PRO_TK_GENERAL_ERROR  - The function could not free the memory.
*/


extern ProError ProExtobjRefselectionSet(ProWExtobjRef  ext_obj_ref, 
                                         ProSelection   reference);
/*
   Purpose:     Sets the external object references for selection.

   Input Arguments:
     ext_obj_ref         - The external object reference
     reference           - The references

   Output Arguments:
     None

   Return Values:
        PRO_TK_NO_ERROR       -  The function successfully set the references.
        PRO_TK_BAD_INPUTS     -  The external object reference was not found.
        PRO_TK_GENERAL_ERROR  -  The references were not found, or the function
                                 could not set the references.
*/


extern ProError ProExtobjRefselectionGet(ProExtobj      *object, 
                                         ProWExtobjRef   ext_obj_ref,
                                         ProSelection    *reference);
/*
   Purpose:     Retrieves the references for selection.

   Input Arguments:
     object              - The handle to which the external object reference
                           belongs
     ext_obj_ref         - The external object reference

   Output Arguments:
     reference           - The references

   Return Values:
        PRO_TK_NO_ERROR       -  The function successfully retrieved the
                                 information.
        PRO_TK_BAD_INPUTS     -  The external object reference was not found.
        PRO_TK_GENERAL_ERROR  -  The function could not retrieve the
                                 information.
*/


extern ProError ProExtobjReftypeSet (ProWExtobjRef  ext_obj_ref,
                                    int            ext_obj_reftype);
/*
   Purpose:     Sets the type for the specified external object reference.

   Input Arguments:
     ext_obj_ref         - The external object reference
     ext_obj_reftype     - The type of reference

   Output Arguments:
     None

   Return Values:
        PRO_TK_NO_ERROR       -  The function successfully set the type.
        PRO_TK_BAD_INPUTS     -  One or more of the arguments are invalid.
        PRO_TK_GENERAL_ERROR  -  The external object reference was not found, or
                                 the function could not set the type.
*/


extern ProError ProExtobjReftypeGet (ProWExtobjRef  ext_obj_ref,
                                    int           *ext_obj_reftype);
/*
   Purpose:     Retrieves the type of the external object reference.

   Input Arguments:
     ext_obj_ref         - The reference

   Output Arguments:
     ext_obj_reftype     - The reference type

   Return Values:
     PRO_TK_NO_ERROR       -  The function successfully retrieved the
                              information.
     PRO_TK_GENERAL_ERROR  -  The external object reference was not found,
                              or the function could not retrieve the
                              information.
*/


extern ProError ProExtobjRefAdd (ProExtobj       *object, 
                               ProWExtobjRef     ext_obj_ref);
/*
   Purpose:     Adds the specified reference to the external object.

   Input Arguments:
     object          - The handle to the external object 
     ext_obj_ref     - The reference

   Output Arguments:
     None  

   Return Values:
     PRO_TK_NO_ERROR       -  The function successfully added the
                              reference.
     PRO_TK_GENERAL_ERROR  -  The external object was not found, or
                              the function could not add the reference.
*/

extern ProError ProExtobjRefRemove(ProExtobj       *object,
                                   ProWExtobjRef    ext_obj_ref);
/*
   Purpose:     Removes the specified reference from the external object.

   Input Arguments:
     object          - The handle to the external object
     ext_obj_ref     - The reference to remove

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR       -  The function successfully removed the
                              reference.
     PRO_TK_BAD_INPUTS     -  One or more of the input arguments are
                              invalid.
     PRO_TK_GENERAL_ERROR  -  The external object was not found, or
                              the function could not remove the reference.
*/

typedef ProError (*ProExtobjRefVisitAction) (    ProExtobj         *p_extobj, 
                                                 ProWExtobjRef      ext_obj_ref,
                                                 ProError           status,
                                                 ProExtobjrefStatus ref_status,
                                                 ProAppData         app_data );

/*
   Purpose:  This is the user function prototype called
             for visiting external objects references.

   Input Arguments:
      p_extobj          - The handle to the model
      ext_obj_ref       - The reference
      status            - The status
      ref_status        - Reference status
      app_data          - The application data passed from the function
                          <b>ProExtobjRefVisit()</b>
   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR    - Continue.
*/

typedef ProError (*ProExtobjRefFilterAction) (    ProExtobj     *p_extobj, 
                                                  ProWExtobjRef  extobj_ref,
                                                  ProAppData     app_data);
/*
   Purpose:  This is the user function prototype called
             for visiting external objects references.

   Input Arguments:
      p_extobj          - The handle to the model
      extobj_ref        - The reference
      app_data          - The application data passed from the function
                          <b>ProExtobjRefVisit()</b>
   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR    - Continue.
*/

extern ProError ProExtobjRefVisit (ProExtobj                 *object, 
                                  ProExtobjRefVisitAction    visit_action,
                                  ProExtobjRefFilterAction   filter_action,
                                  ProAppData                 app_data);
/*
   Purpose:     Visits a number of external object references.

   Input Arguments:
     object        - The handle to the external object
     visit_action  - The visiting function
     filter_action - The filter function. If NULL, all external object
                     references are visited using the action function. 
     app_data      - The application data passed to the visiting and
                     action functions

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR       -  The function successfully visited the
                              references.
     PRO_TK_BAD_INPUTS     -  One or more of the arguments are
                              invalid.
     PRO_TK_GENERAL_ERROR  -  The external object was not found, or the
                              function could not visit the references.
*/

PRO_END_C_DECLS

#endif /* PRO_EXTOBJREF_H */

