#ifndef PRO_EXTOBJCB_H
#define PRO_EXTOBJCB_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProExtobj.h>
#include <ProExtobjRef.h>



PRO_BEGIN_C_DECLS

/* Creo Parametric TOOLKIT external object callbacks - related stuff */

/* Callbacks */

typedef ProError (*ProExtobjCBAct)(ProExtobj      **extobjects,
                                  ProExtobjClass *extobjclass,
                                  ProAppData     *ntf_data,
                                  int            n_objects);
/* 
   Purpose:  This is the generic callback for the user function.

   Input Arguments:
     extobjects    - An array of <i>n_objects</i> pointers to external 
                     object handles
     extobjclass   - A pointer to the external object class handle (common for all 
                     the passed objects)
     ntf_data      - An array of <i>n_objects</i> pointers to application data
     n_objects     - The number of <i>ntf_data</i> and <i>extobjects</i>

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR - The function was successful.
*/
  

typedef struct
{
   int             enabled_cbs;           /* to enable/disable callbacks */

   /* Alternate display / selection functions
      (beware of performance penalties) */
   ProExtobjCBAct  display_CB;    /* not implemented yet */
   ProExtobjCBAct  select_CB;     /* not implemented yet */

   /* Reference / owner event notification functions */
   ProExtobjCBAct  owner_modify_CB;   /* not implemented yet */
   ProExtobjCBAct  owner_suppress_CB; /* not implemented yet */
   ProExtobjCBAct  owner_delete_CB;   /* not implemented yet */
   ProExtobjCBAct  ref_modify_CB;
   ProExtobjCBAct  ref_suppress_CB;
   ProExtobjCBAct  ref_delete_CB;
} ProExtobjCallbacks;


/* Specific structures to be passed by callback as user data -
   depending on event type 
*/

typedef struct 
{
  ProExtobjRefInfo  *ref_infos; /*array of infos on affected refs*/
  int               n_refs;     /* number of affected refs */
} ProEONtf_RefData;


/* Function prototypes */

extern ProError ProExtobjCallbacksSet (ProExtobjClass     *extobjclass,
                                       ProExtobjCallbacks *callbacks);

/* 

   Purpose:  Sets the <i>ProExtobjCallbacks</i> structure for objects of the 
             specified class of external objects. If callbacks for this class 
             are already set, this function resets them.

   Input Arguments:

      extobjclass    - The class of external objects
      callbacks      - The callback information

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR  -  The function successfully set the information.
      PRO_BAD_INPUTS   -  One or more of the arguments are invalid.

 
*/

/* In release 19.0 only callbacks for the following actions
   can be enabled: PRO_EO_ACT_REF_MODIF, PRO_EO_ACT_REF_SUPPR,
   PRO_EO_ACT_REF_DELETE */

extern ProError ProExtobjCBEnable (ProExtobjClass   *extobjclass,
                                   int               action_attr,
                                   int               to_enable);
        
/*

   Purpose:  Updates the enabled_cbs field in the data structure 
             <i>ProExtobjCallbacks</i>, which governs which callbacks are active. 
<pre>
             If    to_enable == TRUE,     enabled_cbs | action_attr
             else  enabled_cbs & ~action_attr
</pre> 


   Input Arguments:

      extobjclass  -  The handle to the external object class 
      action_attr  -  A bitmask constructed from types of notify
                      actions (such as PRO_EO_ALT_DISPLAY or
                      PRO_EO_ALT_SELECT)
      to_enable    -  A Boolean flag that specifies whether to perform
                      the action 

   Output Arguments:

      None

   Return Values:

     PRO_TK_NO_ERROR - The function successfully updated the information. 
     PRO_BAD_INPUTS  - The external class handle is invalid or you attempted to
                       enable callback for an unsupported action.
                       
 */
        
PRO_END_C_DECLS

#endif /* PRO_EXTOBJCB_H */

