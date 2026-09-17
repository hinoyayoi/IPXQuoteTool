#ifndef PROPARAMETER_H
#define PROPARAMETER_H



#include 	<ProObjects.h>
#include  <ProMdlUnits.h>
#include	<ProParamval.h>

PRO_BEGIN_C_DECLS

typedef enum param_sel_context 
{
  PRO_PARAMSELECT_ANY                     = -1,
  PRO_PARAMSELECT_MODEL                   = 1<<0,
  PRO_PARAMSELECT_PART                    = 1<<1,
  PRO_PARAMSELECT_ASM                     = 1<<2,
  PRO_PARAMSELECT_FEATURE                 = 1<<3,
  PRO_PARAMSELECT_EDGE                    = 1<<4,
  PRO_PARAMSELECT_SURFACE                 = 1<<5,
  PRO_PARAMSELECT_QUILT                   = 1<<6,
  PRO_PARAMSELECT_CURVE                   = 1<<7,
  PRO_PARAMSELECT_COMPOSITE_CURVE         = 1<<8,
  PRO_PARAMSELECT_INHERITED               = 1<<9,
  PRO_PARAMSELECT_SKELETON                = 1<<10,
  PRO_PARAMSELECT_COMPONENT               = 1<<11,
  PRO_PARAMSELECT_ALLOW_SUBITEM_SELECTION = 1<<12,
  PRO_PARAMSELECT_SENSOR                  = 1<<13  /* for internal use */
} ProParameterSelectContext;

typedef enum 
{
  PRO_PARAM_UNLIMITED             = -1, 
  PRO_PARAM_LESS_THAN             = 0,
  PRO_PARAM_LESS_THAN_OR_EQUAL    = 1,
  PRO_PARAM_GREATER_THAN          = 2,
  PRO_PARAM_GREATER_THAN_OR_EQUAL = 3
} ProParamLimitType;

typedef struct 
{
  ProParamLimitType type;
  ProParamvalue     value;
} ProParamLimit;

typedef enum
{
  PRO_PARAMTABLE_EXPORT_TXT,
  PRO_PARAMTABLE_EXPORT_CSV
} ProParamTableExportType;

typedef enum
{
   PRO_PARAM_NAME_COLUMN            = 1 << 0, 
   PRO_PARAM_TYPE_COLUMN            = 1 << 1,
   PRO_PARAM_VALUE_COLUMN           = 1 << 2,
   PRO_PARAM_DESIGNATE_COLUMN       = 1 << 3,
   PRO_PARAM_ACCESS_COLUMN          = 1 << 4,
   PRO_PARAM_SOURCE_COLUMN          = 1 << 5,
   PRO_PARAM_DESCRIPTION_COLUMN     = 1 << 6,
   PRO_PARAM_COMPBASED_COLUMN       = 1 << 7,
   PRO_PARAM_REPORTINBOM_COLUMN     = 1 << 8,
   PRO_PARAM_RESTRICTED_COLUMN      = 1 << 9,
   PRO_PARAM_UNIT_COLUMN            = 1 << 10,
   PRO_PARAM_VARIABLE_COLUMN        = 1 << 11,
   PRO_PARAM_APPLICABILITY_COLUMN   = 1 << 12,
   PRO_PARAM_HYPERLINK_COLUMN       = 1 << 13,
   PRO_PARAM_OWNER_COLUMN           = 1 << 14,
   PRO_PARAM_MODEL_COLUMN           = 1 << 15,
   PRO_PARAM_OWNER_TYPE_COLUMN      = 1 << 16,
   PRO_PARAM_AE_TYPE_COLUMN         = 1 << 17,
   PRO_PARAM_UNIT_QTYPE_COLUMN      = 1 << 18
   /* (1 << 19) is used */  
} ProParamColumn;

typedef enum
{  
   PRO_PARAMLOCKSTATUS_UNLOCKED     = 0,
   PRO_PARAMLOCKSTATUS_LIMITED      = 1,
   PRO_PARAMLOCKSTATUS_LOCKED       = 2
} ProLockstatus;


/* Prototype for the action function used by the visiting function */
 
typedef ProError (*ProParameterAction) ( ProParameter *handle, 
                                         ProError status, 
                                         ProAppData data);
/*
   Purpose:  This is a generic function for visiting parameters.

   Input Arguments:
      handle - The handle to the parameter.
      status - The status returned from the filter function if the filter 
               function is not NULL. Otherwise, this is PRO_TK_NO_ERROR.
      data   - The application data passed to the function 
               <b>ProParameterVisit()</b>.

   Output Arguments:
      None

   Return Values:
     PRO_TK_NO_ERROR  - Continue to the next parameter.
     Other            - Any other value causes the function 
                        <b>ProParameterVisit()</b> to return.
*/

/* Prototype for the filter function used by the visiting function */

typedef ProError (*ProParameterFilter) ( ProParameter *handle, 
                                         ProAppData data );
/*
   Purpose:  This is a generic function for visiting parameters.

   Input Arguments:
      handle - The handle to the parameter
      data   - The application data passed to the function 
               <b>ProParameterVisit()</b>

   Output Arguments:
      None

   Return Values:
     PRO_TK_CONTINUE - Skips over the parameter (the action function
                       is not called).
     Other           - Passes this status to the action function, if present.
*/

/*===========================================================================*/

extern ProError ProParameterInit (ProModelitem *owner,
                                  ProName       name, 
                                  ProParameter *param);
/*
   Purpose:	Initializes a <i>ProParameter</i> data structure.

   Input Arguments:
   	owner		- The solid to which the <i>ProParameter</i> belongs
	name		- The name of the <i>ProParameter</i>

   Output Arguments:
	param		- The initialized <i>ProParameter</i> handle

   Return Values:
	PRO_TK_NO_ERROR		- The function successfully initialized
                                  the handle.
	PRO_TK_BAD_INPUTS	- One or more of the input arguments are
                                  invalid.
	PRO_TK_BAD_CONTEXT	- The owner is nonexistent.
	PRO_TK_E_NOT_FOUND	- The parameter was not found within the
                                  owner.

*/

extern ProError ProParameterCreate (ProModelitem  *owner, 
                                    ProName        name, 
                                    ProParamvalue *proval, 
				    ProParameter  *param);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterWithUnitsCreate
   Purpose:	<b>Note:</b> This function is deprecated
            Use ProParameterWithUnitsCreate instead

            Adds the specified parameter to the database and initializes
                the handle.

   Input Arguments:
   	owner			- The owner (a model item or solid)
	name			- The name of the <i>ProParameter</i>
	proval			- The initial data the 
                                  <i>ProParameter</i> will hold

   Output Arguments:
   	param			- The handle to create and initialize

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully added the 
                                  parameter.  
	PRO_TK_BAD_INPUTS	- One or more of the input arguments are
                                  invalid.
	PRO_TK_BAD_CONTEXT	- The owner is nonexistent.
	PRO_TK_E_FOUND		- The specified parameter already exists.
	PRO_TK_GENERAL_ERROR	- The function could not add the parameter 
                                  to the database.

   See Also:
        ProParameterWithUnitsCreate()   
*/

extern ProError ProParameterWithUnitsCreate (ProModelitem  *owner, 
                                             ProName        name, 
                                             ProParamvalue *proval,
                                             ProUnititem   *units, 
                                             ProParameter  *param);
/*
   Purpose:	Adds the specified parameter to the database and initializes
                the handle. The parameter will be created with units.

   Input Arguments:
   	owner			- The owner (a model item or solid)
    name      - The name of the <i>ProParameter</i>
    proval    - The initial data the 
                <i>ProParameter</i> will hold. 
    units     - The units assigned to this parameter.
                To create a parameter without units, pass NULL.
                                  
                                  

   Output Arguments:
   	param			- The handle to create and initialize

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully added the 
                                  parameter.  
	PRO_TK_BAD_INPUTS	- One or more of the input arguments are
                                  invalid.
	PRO_TK_BAD_CONTEXT	- The owner is nonexistent.
	PRO_TK_E_FOUND		- The specified parameter already exists.
	PRO_TK_GENERAL_ERROR	- The function could not add the parameter 
                                  to the database.
        PRO_TK_NOT_VALID        - The specified parameter is invalid.
        
   See Also:
        ProParameterCreate()
*/

extern ProError ProParameterDelete (ProParameter  *param);
/*
   Purpose:	Deletes the specified <i>ProParameter</i> from the database.

   Input Arguments:
	param	- The <i>ProParameter</i> to delete

   Output Arguments:
        None
   
   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully deleted the
                                  parameter.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the
				  function could not perform the action.
*/

extern ProError ProParameterValueSet (ProParameter   *param, 
                                      ProParamvalue  *proval);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterValueWithUnitsSet
   Purpose: <b>Note:</b> This function is deprecated. Use ProParameterValueWithUnitsSet().
   
            Sets the value of an existing <i>ProParameter</i>.

   Input Arguments:
   	param	  - The handle of the parameter to set
	proval    - The new value. The value is assumed to be in the units 
                    of the owner model, regardless of the units of this parameter.

   Output Arguments:
        None

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully set the value.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the function
				  could not perform the action.
*/

extern ProError ProParameterValueWithUnitsSet (ProParameter   *param, 
                                               ProParamvalue  *proval,
                                               ProUnititem    *units);
/*
   Purpose:	Sets the value given with units of an existing <i>ProParameter</i>.

   Input Arguments:
   	param	  - The handle of the parameter to set
	proval    - The new value. The value assumed to be in the units specified by 
                    units argument (when the units argument is not NULL) 
                    or in the units of the owner model, when argument units is NULL.                          	     
	units     - The new units. The units must be the same quantity type as the parameter's units
                    (i.e. if the units are "inch", a value can be expressed in "cm"). Can be NULL.
                    If you pass NULL, the function will assume the units of the owner model.

   Output Arguments:
        None

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully set the value and units.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
        PRO_TK_INVALID_TYPE     - The unit type provided does not match the units 
                                  of the parameter.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the function
				  could not perform the action.
*/

extern ProError ProParameterScaledvalueSet (ProParameter   *param, 
                                            ProParamvalue  *proval,
                                            ProUnititem    *units);
/*
   Purpose:	Sets the parameter value in terms of the units provided, instead of 
                using the units of the owner model.

   Input Arguments:
   	param	  - The handle of the parameter to set
	proval    - The value. 
        units     - The units in which the value is expressed. The units must be 
                    the same quantity type as the parameter's units (i.e. if the 
                    units are "inch", a value can be expressed in "cm"). Can be NULL.

   Output Arguments:
        None

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully set the value.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
        PRO_TK_INVALID_TYPE     - The unit type provided does not match the units 
                                  of the parameter.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the function
				  could not perform the action.
*/

extern ProError ProParameterValueGet (ProParameter   *param, 
                                      ProParamvalue  *proval);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterValueWithUnitsGet
   Purpose: <b>Note:</b> This function is deprecated. Use ProParameterValueWithUnitsGet().
   
            Retrieves the value of the specified <i>ProParameter</i>.

   Input Arguments:
   	param	 - The handle to the parameter to query

   Output Arguments:
   	proval	 - The value currently held in the <i>ProParameter</i>
                   The value is assumed to be in the units of the owner model,
                   regardless of the units of this parameter.

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully retrieved the
                                  information.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the
				  function could not perform the action.
*/

extern ProError ProParameterValueWithUnitsGet (ProParameter   *param, 
                                               ProParamvalue  *proval,
                                               ProUnititem *units);
/*
   Purpose:	Retrieves the value and units of the specified <i>ProParameter</i>.
   
   Input Arguments:
   	param	 - The handle to the parameter to query

   Output Arguments:
   	proval	 - The value currently held in the <i>ProParameter</i>
                   The value is assumed to be in the units of the owner model,
                   regardless of the units of this parameter.
	units    - The units in which the value is expressed.
                   If none found, an empty string will be returned.

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully retrieved the
                                  information. Parameter could be unitless.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
	PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the
				  function could not perform the action.
*/

extern ProError ProParameterScaledvalueGet (ProParameter   *param, 
                                            ProParamvalue  *proval);
/*
   Purpose:	Gets the parameter value in the units of the parameter, instead of
                the units of the owner model.
   
   Input Arguments:
   	param	 - The handle to the parameter to query

   Output Arguments:
   	proval	 - The value.

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully retrieved the
                                  information.
        PRO_TK_BAD_INPUTS       - One or more arguments are invalid.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the
				  function could not perform the action.

   See Also:
        ProParameterUnitsGet()
   
*/

extern ProError ProParameterValueReset (ProParameter *param);
/*
   Purpose:	Resets the value of the <i>ProParameter</i> to the value it had
                before it was last set.

   Input Arguments:
   	param	 - The handle of the parameter to reset

   Output Arguments:
        None

   Return Values:
   	PRO_TK_NO_ERROR		- The function successfully reset the value.
	PRO_TK_E_NOT_FOUND	- The owner was not found.
	PRO_TK_GENERAL_ERROR	- The parameter was not found, or the
				  function could not perform the action.
*/

extern ProError ProParameterIsModified (ProParameter   *param,
                                        ProBoolean     *r_is_modified);
/*
   Purpose:     Determines whether the specified parameter has been modified.
<p>
                NOTE: 
<p>
                A parameter is said to be "modified" if the value has been 
                changed but the parameter's owner has not yet been
                regenerated. This function can succeed only for solid models.
 
   Input Arguments:
        param              - The handle to the parameter to query.

   Output Arguments:
        r_is_modified      - This is PRO_B_TRUE if the specified parameter is
                             modified.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_E_NOT_FOUND    - The owner was not found.
        PRO_TK_GENERAL_ERROR  - The parameter was not found, or the
                                function could not perform the action.
*/

extern ProError ProParameterVisit (ProModelitem       *owner, 
                                   ProParameterFilter  filter,
                                   ProParameterAction  action, 
                                   ProAppData          data);
/*
   Purpose:	Performs a user-defined action on each parameter.
                <B>Note:</B> This function does not visit mass properties parameters.

   Input Arguments:
   	owner	- The owner of the parameters. For model parameters use the
                  function <b>ProMdlToModelitem</b>.
	filter	- The filter function. If NULL, all parameters are 
                  are visited using the action function. 
	action	- The action to perform on each <i>ProParameter</i>.
		  If the function returns anything other than 
                  PRO_TK_NO_ERROR, visiting ends.
	data	- The application data passed to the 
                  filter and action functions.

   Output Arguments:
	None

   Return Values:
	PRO_TK_NO_ERROR		- The function successfully visited all the
                                  parameters.
	PRO_TK_BAD_INPUTS	- One or more of the input arguments are 
                                  invalid, or the action function is 
                                  PRO_NO_FUNCTION.
	PRO_TK_GENERAL_ERROR	- The owner was not found.
        PRO_TK_E_NOT_FOUND      - No parameters were found.
        Other                   - Any other value is the value returned
                                  by the action function (visiting stopped).
*/

extern ProError ProParameterSelect (ProModelitem    *owner,
                                    ProMdl           top_model,
                                    int              context,
                                    ProBoolean       select_multiple,
                                    wchar_t         *button_label,
                                    ProParameter    *parameter,
                                    ProParameter   **multi_parameters);
/*
   Purpose:     Prompts the user to select one or more parameters from the parameter 
                dialog in Creo Parametric. <p><b>Note: </b>The top model from which the 
                parameters will be selected must be displayed in the current window.

   Input Arguments:
       owner              - The owner of the parameters to be selected. May be 
                            NULL if the parameter should be selected by context.

       top_model          - The top level model from which parameters will 
                            be selected.

       context            - A bitmask containing the context of parameter 
                            selection (Members of ProParameterSelectContext). 
                            Used only if "owner" is NULL.

       select_multiple    - PRO_B_TRUE to allow multiple selections.
                            PRO_B_FALSE otherwise.

       button_label       - Label for select button, or NULL to use default 
                            label.

   Output Arguments:
       parameter          - If select_multiple is PRO_B_FALSE should contain the
                            selected parameter. NULL should be passed if 
                            select_multiple is PRO_B_TRUE.

       multi_parameters   - If select_multiple is PRO_B_TRUE should contain
                            ProArray of selected parameters. ProArrayFree 
                            should be used to free this array.. NULL passed if
                            select_multiple is PRO_B_FALSE.

   Return Values:
       PRO_TK_NO_ERROR    - The user selected the parameter(s).
       PRO_TK_BAD_CONTEXT - The owner is invalid or not found.
       PRO_TK_E_NOT_FOUND - The owner does not contain parameteers.
       PRO_TK_USER_ABORT  - The user aborted the selection.
       PRO_TK_INVALID_TYPE - Invalid context for top_model argument.
       PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

extern ProError ProParameterDesignationAdd (ProParameter* param);

/*
   Purpose:    Adds the designation status for the specified model parameter, 
               making the parameter visible to PTC-provided PDM solutions.

   Input Arguments:
        param       - The parameter to add

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR    - The function successfully added the parameter.
        PRO_TK_BAD_INPUTS  - The input argument is invalid.
        PRO_TK_E_FOUND     - The specified parameter already exists.
*/

extern ProError ProParameterDesignationVerify (ProParameter* param,
                                                          ProBoolean* p_exist);

/*
   Purpose:    Obtains the specified model parameter's designation status,
               which determines whether the parameter is visible to 
               PTC-provided PDM solutions.

   Input Arguments:
        param      - The parameter to be verified.

   Output Arguments:
        p_exist    - If the parameter exists, this is
                     PRO_B_TRUE; otherwise, this is 
                     PRO_B_FALSE.

   Return Values:
        PRO_TK_NO_ERROR    - The function successfully verified the
                             parameter.
        PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/

extern ProError ProParameterDesignationRemove (ProParameter* param);

/*
   Purpose:    Removes the specified model parameter's designation status,
               making the parameter invisible to PTC-provided PDM solutions.

   Input Arguments:
        param       - The parameter to be removed 

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully removed the
                               parameter.
        PRO_TK_BAD_INPUTS    - The input argument is invalid.
        PRO_TK_E_NOT_FOUND   - The specified parameter was not found.
*/

typedef ProError (*ProParameterCreatePreAction) (ProModelitem   *param_owner,
                                                 ProName         param_name,
                                                 ProParamvalue  *param_value);

/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterCreateWithUnitsPreAction
   Purpose: <b>Note:</b> This function is deprecated. Use ProParameterCreateWithUnitsPreAction().
  
            This is the notification function called before a 
	    parameter is created.

<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_PARAM_CREATE_PRE.

  Input Arguments:
     param_owner   -  The model item handle of the parameter owner
     param_name    -  The name of the parameter to be created
     param_value   -  The value of this parameter
 
  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  Proceed with parameter creation.
     Other            -  Error encountered. Abort parameter creation.

  See Also:
     ProNotificationSet()
*/

typedef ProError (*ProParameterCreateWithUnitsPreAction)
                                        (ProModelitem   *param_owner,
                                         ProName         param_name,
                                         ProUnititem    *units,
                                         ProParamvalue  *param_value);

/*
  Purpose:  This is the notification function called before a 
	    parameter is created.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_PARAM_CREATE_W_UNITS_PRE.

  Input Arguments:
     param_owner   -  The model item handle of the parameter owner
     param_name    -  The name of the parameter to be created
	 units         -  The units of the value to be set
     param_value   -  The value of this parameter
 
  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  Proceed with parameter creation.
     Other            -  Error encountered. Abort parameter creation.

  See Also:
     ProNotificationSet()
*/

typedef ProError (*ProParameterModifyPreAction) (ProParameter   *param_handle,
                                                 ProParamvalue  *new_value);

/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterModifyWithUnitsPreAction
   Purpose: <b>Note:</b> This function is deprecated. Use ProParameterModifyWithUnitsPreAction().
  
            This is the notification function called before a parameter 
	    is modified.

<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_PARAM_MODIFY_PRE.

  Input Arguments:
     param_handle     -  The parameter to be modified
     new_value        -  The new value to assign

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  Proceed with the parameter modification.
     Other            -  Error encountered. Abort parameter modifiction.

  See Also:
     ProNotificationSet()

*/

typedef ProError (*ProParameterModifyWithUnitsPreAction)
                             (ProParameter   *new_param,
                              ProParamvalue  *new_value,
                              ProUnititem    *new_units,
                              ProParamvalue  *old_value,
                              ProUnititem    *old_units );

/*
  Purpose:  This is the notification function called before a parameter 
	    is modified.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_PARAM_MODIFY_W_UNITS_PRE.

  Input Arguments:
        new_param - The modified parameter.
		new_value - The value of the new parameter.
		new_units - The units of the new value.
		old_value - The value of the parameter before it was modified.
		old_units - The units of the value before it was modified.

    Output Arguments:
		none

  Return Values:
     PRO_TK_NO_ERROR  -  Proceed with the parameter modification.
     Other            -  Error encountered. Abort parameter modifiction.

  See Also:
     ProNotificationSet()

*/

typedef ProError (*ProParameterDeletePreAction) (ProParameter   *param_handle);

/*
  Purpose:  This is the notification function called before a parameter 
	    is deleted.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_PARAM_DELETE_PRE.


  Input Arguments:
     param_handle     -  The parameter to be deleted

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  Proceed with parameter deletion.
     Other            -  Error encountered. Abort parameter deletion.

  See Also:
     ProNoticationSet()

*/

extern ProError ProParameterUnitsGet (ProParameter* param, ProUnititem* units);

/* 
  Purpose: Gets the units assigned to a parameter.

  Input Arguments:
     param - The parameter.

  Output Arguments:
     units - The units.

  Return Values:
     PRO_TK_NO_ERROR    - The function succeeded.
     PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
     PRO_TK_E_NOT_FOUND - The parameter is unitless.
*/

extern ProError ProParameterIsEnumerated (ProParameter   *param, 
                                          ProBoolean     *is_enumerated,
                                          ProParamvalue **valid_values);

/* 
  Purpose: Identifies if a parameter is enumerated, and provides the values
           that may be assigned to it.

  Input Arguments:
     param - The parameter.

  Output Arguments:
     is_enumerated - PRO_B_TRUE if the parameter is enumerated, PRO_B_FALSE
		     if it is not.
     valid_values  - ProArray of values that may be assigned to this parameter.
                     Free this output using ProArrayFree(). Pass NULL if you are
                     not interested in this output argument.

  Return Values: 
     PRO_TK_NO_ERRORS  - The function succeded.
     PRO_TK_BAD_INPUTS - One or more arguments is invalid.
*/

extern ProError ProParameterRangeGet (ProParameter    *param, 
                                      ProBoolean      *has_range,
                                      ProParamLimit   *minimum,
                                      ProParamLimit   *maximum);
/*
  Purpose: Identifies if a parameter's value is restricted to a certain range.

  Input Arguments:
     param - The parameter.

  Output Arguments:
     has_range - PRO_B_TRUE if the parameter is restricted by range, 
                 PRO_B_FALSE if it is not.
     minimum   - The minimum value for this parameter. Pass NULL if not 
                 interested in actual value.
     maximum   - The maximum value for this parameter. Pass NULL if not 
                 interested in actual value.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments is invalid.
*/


/* ProParameter.h */
typedef struct pro_param_table_set   *ProParamtableSet;   
typedef struct pro_param_table_entry *ProParamtableEntry; 

extern ProError ProParamtablesetEntriesGet (ProParamtableSet     set,
                                            ProParamtableEntry **entry_array);
/*
  Purpose: Obtains the entries that are contained in this parameter table set.

  Input Arguments:
     set - The parameter table set.

  Output Arguments:
      entry_array - ProArray of table entries for the parameter table set.  

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParamtablesetTablepathGet (ProParamtableSet   set,
                                              ProPath            table_path);
/* 
  Purpose: Obtains the name of the table that owns this parameter table set.
           If the set is loaded from a certain table file, this is the full
           path. If the set has been stored in the model directly, this is
           the table name.

  Input Arguments:
     set - The parameter table set.

  Output Arguments:
      table_path - The name of the table.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParamtablesetLabelGet (ProParamtableSet   set,
                                          ProName            label);
/* 
  Purpose: Obtains the set label for a given parameter table set, if it 
           exists.

  Input Arguments:
     set - The parameter table set.

  Output Arguments:
      label - The set label.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParamtablesetFree (ProParamtableSet   set);
/*
  Purpose: Frees a parameter table set.

  Input Arguments:
     set - The parameter table set.

  Output Arguments:
      none

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParamtablesetProarrayFree (ProParamtableSet *set_array);
/*
  Purpose: Frees an array of parameter table sets.

  Input Arguments:
     set_array - ProArray of parameter table sets.

  Output Arguments:
      none

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParamtableentryValueGet (ProParamtableEntry  entry,
                                            ProParamvalue      *value);
/* 
  Purpose: Obtains the value for the parameter in this table set. 
           If the parameter also has a range applied, this is the default 
           value for the parameter.
   
  Input Arguments:
     entry - The parameter table entry.

  Output Arguments:
      value - The value for the parameter int this table set.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - The parameter is assigned the null value in this 
                          table set. 
*/

extern ProError ProParamtableentryRangeGet (ProParamtableEntry   entry,
                                            ProParamLimit       *minimum,
                                            ProParamLimit       *maximum);
/*
  Purpose: Obtains the permitted range for the parameter in this table set,
           if one is assigned.

  Input Arguments:
     entry - The parameter table entry.

  Output Arguments:
      minimum - The minimum value for the parameter, as enforced in this
                parameter set.
      maximum - The maximum value for the parameter, as enforced in this
                parameter set.         

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - No range is assigned to this parameter. 
*/

extern ProError ProParamtableentryNameGet (ProParamtableEntry   entry,
                                           ProName              name);
/*
  Purpose: Obtains the name for the parameter in this table set.

  Input Arguments:
     entry - The parameter table entry.

  Output Arguments:
      name - The name for the parameter in this table set.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParamtableentryProarrayFree (ProParamtableEntry *entry_array);
/*
  Purpose: Frees an array of parameter table entries.

  Input Arguments:
     entry_array - ProArray of table entries.

  Output Arguments:
      none

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParameterTablesetGet (ProParameter     *param,
                                         ProParamtableSet *table_set);
/*
  Purpose: Obtains the parameter table set that this parameter is governed by.

  Input Arguments:
     param - The parameter.

  Output Arguments:
      table_set - The parameter table set.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - The parameter is not governed by a parameter 
                          table set.
*/

extern ProError ProParamtablesetApply (ProModelitem      *owner,
                                       ProParamtableSet   set);
/*
  Purpose: Assigns this parameter set to the given parameter owner.
           Parameters called by the set will be created or modified, as
           appropriate. The parameter values will be set to the default 
           values. This function does not perform a regeneration.

  Input Arguments:
     owner - The owner for the parameter set.
     set  - The parameter table set.

  Output Arguments:
      none
      
  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - The parameter owner already has one or more
                          required parameters defined and they are not 
                          driven by this table.
*/

extern ProError ProParameterDescriptionGet (ProParameter  *param,
                                            wchar_t      **description);
/*
  Purpose: Obtains the parameter's description                                           .

  Input Arguments:
     param - The parameter.

  Output Arguments:
      description - The parameter description.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - The parameter's description is not set.
*/
    
extern ProError ProParameterDescriptionSet (ProParameter  *param,
                                            wchar_t       *description);
/*
  Purpose: Assigns the parameter's description                                           .

  Input Arguments:
     param - The parameter.
     description - The parameter description.

  Output Arguments:
      none

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


typedef ProError (*ProParameterCreatePostAction) (ProParameter *param);
/*
    Purpose: This is the notification function prototype for a function
             called after a parameter has been created (actions of type
             PRO_PARAM_CREATE_POST).

    Input Arguments:
        param - The created parameter.

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.
*/ 

typedef ProError (*ProParameterModifyPostAction) (ProParameter  *param,
                                                  ProParamvalue *old_value);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterModifyWithUnitsPostAction
   Purpose: <b>Note:</b> This function is deprecated. Use ProParameterModifyWithUnitsPostAction().
	
	         This is the notification function prototype for a function
             called after a parameter has been modified (actions of type
             PRO_PARAM_MODIFY_POST).

    Input Arguments:
        param - The created parameter.
        old_value - The value of the parameter (before it was modified).

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProParameterModifyWithUnitsPostAction)
                             (ProParameter   *new_param,
                              ProParamvalue  *new_value,
                              ProUnititem    *new_units,
                              ProParamvalue  *old_value,
                              ProUnititem    *old_units );

/*
    Purpose: This is the notification function prototype for a function
             called after a parameter has been modified (actions of type
             PRO_PARAM_MODIFY_W_UNITS_POST).

    Input Arguments:
        new_param - The modified parameter.
		new_value - The value of the new parameter.
		new_units - The units of the new value.
		old_value - The value of the parameter before it was modified.
		old_units - The units of the value before it was modified.

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProParameterDeletePostAction) (ProModelitem  *owner,
                                                  ProName        name, 
                                                  ProParamvalue *old_value);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProParameterDeleteWithUnitsPostAction
   Purpose: <b>Note:</b> This function is deprecated. Use ProParameterDeleteWithUnitsPostAction().
	
	         This is the notification function prototype for a function
             called after a parameter has been deleted (actions of type
             PRO_PARAM_DELETE_POST).

    Input Arguments:
        owner - The owner of the just-deleted parameter.
        name - The name of the parameter that was deleted.
        old_value - The value of the parameter (before it was deleted).

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProParameterDeleteWithUnitsPostAction)
                                        (ProModelitem  *owner,
                                         ProName        name,
                                         ProUnititem   *units,
                                         ProParamvalue *old_value);
/*
    Purpose: This is the notification function prototype for a function
             called after a parameter has been deleted (actions of type
             PRO_PARAM_DELETE_W_UNITS_POST).

    Input Arguments:
        owner     - The owner of the just-deleted parameter.
        name      - The name of the parameter that was deleted.
		units     - The units of the value of the parameter.
        old_value - The value of the parameter (before it was deleted).

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.
*/

extern ProError ProParameterReorder (ProParameter* param_to_reorder, 
                                     ProParameter* param_before);
/*
    Purpose: Reorders the given parameter to come just after the indicated
             parameter.

    Input Arguments:
        param_to_reorder - The parameter to reorder.
        param_before - The parameter to be just before the reordered parameter.
                       If NULL, the reordered parameter is moved to the first
                       position in the parameter list.

    Output Arguments:
        none

    Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
          PRO_TK_BAD_CONTEXT - Parameter 'param_before' does not have the same
                               owner as the parameter to be reordered.
          PRO_TK_NO_LICENSE - No license is available for this functionality.
 */


extern ProError ProMdlParamtablesetsCollect (ProMdl             mdl,
                                        ProParamtableSet **param_table_sets);
/*
  Purpose: Obtains an array of all of the table sets that are available for
           use in the given model. This includes all sets that are loaded
           from files setup in this session, and any sets that were 
           previously stored in the model.

  Input Arguments:
     mdl - The model.

  Output Arguments:
      param_table_sets - ProArray of the table sets that are available for
                         use in this model. Free this using 
                         ProParamtablesetProarrayFree().
                         
  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - No parameter table sets are available for this model.
*/


extern ProError ProParameterTableExport (ProModelitem           *owner,
                                         ProMdl                  top_model,
                                         int                     context,
                                         ProParamTableExportType file_type,
                                         ProPath                 file_path,
                                         ProParamColumn          column_list);
/*
   Purpose:     Exports a file containing information from the parameter 
                table in Creo Parametric in the CSV or TXT format.

   Input Arguments:
       owner              - The owner of the parameters to be exported. May be 
                            NULL if the parameter should be selected by context.

       top_model          - The top level model from which parameters will 
                            be exported.

       context            - A bitmask containing the context of 
                            parameters to list in the export.
                            (Members of ProParameterSelectContext).
                            Used only if "owner" is NULL.
                            The following options are supported:
                            <UL><LI>PRO_PARAMSELECT_ALLOW_SUBITEM_SELECTION alone,
                            all parameters of all subitems of top_model will be
                            exported. 
                            <LI>PRO_PARAMSELECT_ALLOW_SUBITEM_SELECTION and 
                            other contexts, only the indicated contexts' 
                            parameters will be exported. 
                            <LI>PRO_PARAMSELECT_MODEL, PRO_PARAMSELECT_PART or
                            PRO_PARAMSELECT_ASM: all model level parameters in 
                            top model will be exported. </UL>
                            No other combination is permitted.

       file_type          - The type of export file to create.
                            CSV format will export only local parameters
                            Use TXT format to export full list of parameters

       file_path          - Full path to the file to export (including name and
                            extension). 
                            
       column_list        - Bitmask containing one or more columns 
                            to include in the exported file. This applies only 
                            when the file is being exported in the CSV format, 
                            and not when the file is being exported in the TXT 
                            format (where the columns exported will match the 
                            columns and options set by the user in the active 
                            session, in accordance with the behavior of 
                            File->Export in the Parameter dialog box).

   Output Arguments:
       none

   Return Values:
       PRO_TK_NO_ERROR     - The function succeeded.
       PRO_TK_BAD_CONTEXT  - The owner is invalid or not found and/or
	                     Design Test Mode is active - the 
                             function is not available in this mode
       PRO_TK_E_NOT_FOUND  - The owner does not contain parameters.
       PRO_TK_CANT_WRITE   - Creo Parametric could not write to the file path
                             specified.
       PRO_TK_INVALID_TYPE - Invalid context for top_model argument. 
       PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
       
*/

extern ProError ProParameterLockstatusSet (ProParameter  *param,
                                           ProLockstatus  lock_status);
/*
  Purpose: Set parameter lock status.                                           .

  Input Arguments:
     param - The parameter.
     lock_status - The parameter lock status.

  Output Arguments:
      none

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProParameterLockstatusGet (ProParameter  *param,
                                           ProLockstatus *lock_status);
/*
  Purpose: Get parameter lock status.                                           .

  Input Arguments:
     param - The parameter.

  Output Arguments:
     lock_status - The parameter lock status. 

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

PRO_END_C_DECLS

#endif
