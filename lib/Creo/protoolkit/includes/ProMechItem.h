#ifndef PRO_MECH_ITEM
#define PRO_MECH_ITEM



#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef enum 
{
  PRO_MECH_ACTIVE              = 0,  /* The object is ok */

  PRO_MECH_SUPPR_BY_PRODUCT    = 1,  /* FEM-specific object in Creo Simulate, or
                                       Creo Simulate-specific object in FEM */
  PRO_MECH_SUPPR_BY_MODE       = 2,  /* Structure-specific object in Thermal, or
                                       Thermal-specific object in Structure */
  PRO_MECH_SUPPR_BY_GEOM_REF   = 3,  /* Some/all of object's geometrical refs
                                       have been suppressed */
  PRO_MECH_SUPPR_BY_VALUE      = 4,  /* An expression used in object's definition
                                       cannot be evaluated */
  PRO_MECH_SUPPR_INVALID       = 5,  /* Object is not valid - some of its data
                                       are corrupted or wrong */
  PRO_MECH_SUPPR_INCOMPLETE    = 6   /* Object doesn't have all data defined
                                       (for the first time after creation) */
} ProMechStatus;


typedef enum
{
  PRO_MECH_ERROBJ_ERROR   = 0,
  PRO_MECH_ERROBJ_WARNING = 1,
  PRO_MECH_ERROBJ_INFO    = 2
} ProMechErrobjType;

typedef struct pro_sim_err_obj* ProMechErrobj;


typedef ProError (*ProMechitemFilterAction) (ProMechItem* item, 
					    ProAppData app_data);
/*
  Purpose:   The filter action used for visiting Creo Simulate items.

  Input Arguments:
      item - The Creo Simulate simulation item.
      app_data - Application data passed to the Visit function.

  Output Arguments:
      none

  Return Values:
      PRO_TK_CONTINUE - Do not call the visit action for this item.
      Any other value - Call the visit action for this item.
 */

typedef ProError (*ProMechitemVisitAction) (ProMechItem* item, 
					    ProError filter_status,
					    ProAppData app_data);
/*
  Purpose:   The visit action used for visiting Creo Simulate items.

  Input Arguments:
      item - The Creo Simulate simulation item.
      filter_status - The return status from the filter action.
      app_data - Application data passed to the Visit function.

  Output Arguments:
      none

  Return Values:
      PRO_TK_NO_ERROR - Continue visiting.
      Any other value - Stop visiting and return this error.
 */

extern ProError ProSolidMechitemVisit (ProSolid solid,
				       ProType type,
				       ProMechitemVisitAction visit_action,
				       ProMechitemFilterAction filter_action,
				       ProAppData app_data);
/*
  Purpose:  Visits Creo Simulate items in the solid model.

  Licensing Requirement:
          TOOLKIT for Mechanica
  
  Input Arguments:
      solid - The solid model.
      type - The type of item.  This must be one of the PRO_SIMULATION* types.
            Pass PRO_VALUE_UNUSED to visit all types of Creo Simulate items.
      visit_action - The visit action to be called for each item.
      filter_action - The filter action to be called for each item. Can be NULL.
      app_data - The application data passed to each callback. Can be NULL.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
      PRO_TK_E_NOT_FOUND - No items were found.
      PRO_TK_GENERAL_ERROR - A general error is encountered.
      PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
      Other - Error status returned by the visit action function.
 */

extern ProError ProMechitemNameGet (ProMechItem* item, ProName name);
/*
  Purpose: Returns the name of a Creo Simulate item.

  Licensing Requirement:
          TOOLKIT for Mechanica

  Input Arguments:
       item - The item.

  Output Arguments:
       name - The item name.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
      PRO_TK_GENERAL_ERROR - A general error is encountered.
      PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
      PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
 */


extern ProError ProMechitemStatusGet (ProMechItem* item, ProMechStatus* status);
/*
  Purpose: Returns the current status of a Creo Simulate item.

  Licensing Requirement:
          TOOLKIT for Mechanica

  Input Arguments:
       item - The item.

  Output Arguments:
       status - The item status.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
      PRO_TK_GENERAL_ERROR - A general error is encountered.
      PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
      PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
 */


extern ProError ProMechitemNameSet (ProMechItem* item, ProName name);
/*
    Purpose: Returns the name of a Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        name - The item name.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

*/

extern ProError ProMechitemCreate (ProSolid solid, ProType type, ProMechItem* item);
/*
    Purpose: Creates a new Creo Simulate item

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        solid - The handle of top Creo Parametric model ( part/assembly )
        type - The mech item type.

    Output Arguments:
        item - The created mech item

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_GENERAL_ERROR - A general error is encountered..
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechitemValidate (ProMechItem    * item,
                                     ProMechErrobj  * err_obj);
/*
    Purpose: Validates given Creo Simulate item and returns the error object
             that collected found errors and warnings.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mech item.

    Output Arguments:
        err_obj - The error object.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMecherrobjDataGet (ProMechErrobj       err_obj,
                                      ProMechErrobjType   type,
                                      int               * p_num);
/*
    Purpose: Returns number of the error object's events of given type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        err_obj - The error object.
        type - The error object event type.

    Output Arguments:
        p_num - Pointer to number of events of given type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMecherrobjMessageGet (ProMechErrobj        err_obj,
                                         ProMechErrobjType    type, 
                                         int                  index,
                                         wchar_t           ** message);
/*
    Purpose: Returns the error object's event message at given index.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        err_obj - The error object.
        type - The error object event type.
        index - The event index.

    Output Arguments:
        message - The message at given index.
                  Free the memory for this string using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError   ProMechitemUpdateComplete (ProMechItem*     item);
/*
   Purpose:
        This function notifies Creo Parametric that all desired changes have been made to a given
        simulation item.  Calling this function:
        <UL> 
        <LI>Forces a recalculation of the item's status.
        <LI>Updates the display of the simulation object, if it is currently displayed.
        <LI>May also trigger showing or hiding other dependent items because of the changes made.
        </UL>
        <P>This function MUST be called after ALL properties of a new/modified
         simulation item have been set by the appropriate Set functions.

    Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        item - The simulation item that has just been modified.

   Output Arguments:
        None.

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
      PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
      PRO_TK_GENERAL_ERROR - A general error is encountered. 
*/

extern ProError ProMechitemRemove ( ProMechItem* item );

/*
   Purpose:
        Removes a Creo Simulate item from the model.

    Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        item   - The item to be deleted.

   Output Arguments:
        None.

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_IN_USE - Another simulation item is dependent on this item.  
                          Use ProMechitemDependenciesGet() to find the
                          dependent items.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
*/

extern ProError ProMechitemDependenciesGet (ProMechItem* item, 
                                            ProAsmcomppath* component_path, 
                                            ProMechItem** dependencies);
/*
   Purpose:
        Returns the Creo Simulate items dependent upon the
        input Creo Simulate item.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        item - The Creo Simulate item.
        component_path - The component path from the top level
        Creo Simulate model (the model used in ProMechanicaEnable())
        down to the item. Can be NULL if the item is in the
        top level model.

   Output Arguments:
        dependencies - The dependent items. Free this array using
        ProArrayFree().

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_E_NOT_FOUND - No dependent items were found.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        
*/

PRO_END_C_DECLS

#endif
