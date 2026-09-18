#ifndef PRO_PROCSTEP_H
#define PRO_PROCSTEP_H



#include <ProObjects.h>
#include <ProRule.h>

/*****************************************************************************\

1. Feature element tree

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_FEATURE_TYPE
     |   
     |--PRO_E_PROCESS_STEP_TYPE   
     |   
     |--PRO_E_COMPONENTS
     |
     |--PRO_E_DESCRIPTION
     |
     |--PRO_E_POSITION
     |
     |--PRO_E_SIMPLFD_REP
     |
     |--PRO_E_EXPLD_STATE
     |
     |--PRO_E_GEN_STEP_TYPE
     |
     |--PRO_E_GEN_STEP_REFS
     |   
     |--PRO_E_TIME_ESTIMATE   
     |
     |--PRO_E_COST_ESTIMATE   


2. Feature elements table

--------------------------------------------------------------------------------------------
Element Id                Element Name    Data Type                 Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE        Feature Type    PRO_VALUE_TYPE_INT        PRO_FEAT_PROCESS_STEP
PRO_E_PROCESS_STEP_TYPE   Step Type       PRO_VALUE_TYPE_INT        See ProProcStepType 
PRO_E_COMPONENTS          Components      PRO_VALUE_TYPE_SELECTION  Component
PRO_E_DESCRIPTION         Description     PRO_VALUE_TYPE_WSTRING    any value
PRO_E_POSITION            Position        PRO_VALUE_TYPE_TRANSFORM  any value
PRO_E_GEN_STEP_TYPE       Type            PRO_VALUE_TYPE_WSTRING    any value
PRO_E_GEN_STEP_REFS       References      PRO_VALUE_TYPE_SELECTION  See Note 1
PRO_E_SIMPLFD_REP         Simplfd Rep     PRO_VALUE_TYPE_INT        Id for rep
PRO_E_EXPLODE_STATE       Explode State   PRO_VALUE_TYPE_INT        Id for state
PRO_E_TIME_ESTIMATE       Time Estimate   PRO_VALUE_TYPE_DOUBLE     > 0.0
PRO_E_COST_ESTIMATE       Cost Estimate   PRO_VALUE_TYPE_DOUBLE     any value
--------------------------------------------------------------------------------------------

   Note 1.   Step References types:

   Step Reference          Valid Reference Valus
   -----------------------------------------------------------------------
   PRO_E_GEN_STEP_REFS     PRO_PART, PRO_FEATURE, PRO_SURFACE, PRO_EDGE,
                           PRO_CURVE, PRO_AXIS, PRO_CSYS, PRO_POINT

\*****************************************************************************/

/*  PRO_E_PROCESS_STEP_TYPE */

typedef enum pro_proc_step_type
{
   PRO_PROCSTEP_ASSEMBLE = 0,
   PRO_PROCSTEP_DISASSEMBLE,
   PRO_PROCSTEP_REASSEMBLE,
   PRO_PROCSTEP_REPOSITION,
   PRO_PROCSTEP_GENERAL,
   PRO_PROCSTEP_SURFACE,
   PRO_PROCSTEP_VOLUME,
   PRO_PROCSTEP_MFG_MODEL
} ProProcStepType;


PRO_BEGIN_C_DECLS

/* Creo Parametric TOOLKIT declarations for ProProcStep related actions */

/*===========================================================================*/

extern ProError ProProcstepActiveSet  (ProSolid     p_solid, 
                                       ProProcstep *p_proc_step);
/*
   Purpose:  Activates the process step.

   Input Arguments:
      p_solid		- The solid that corresponds to the process step
      p_proc_step	- The process step

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully activated the process step.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - The specified process step was not found 
                           in the model.
*/

extern ProError ProProcstepActiveGet (ProSolid      solid, 
                                      ProProcstep  *p_proc_step);
/*
   Purpose:  Returns the current active process step.

   Input Arguments:
      solid             - The solid that contains the current process step

   Output Arguments:
      p_proc_step	- The current active process step

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/

extern ProError ProProcstepInit  (ProSolid     p_solid,
                                  int          step_number,
                                  int          step_id,
                                  ProProcstep *p_proc_step);
/*
   Purpose:  Returns the handle to the specified process step.

   Input Arguments:
      step_number       - The number of the process step in the active
                          step list.  If you specify this argument,
		          the function ignores <i>step_id</i>.
      step_id           - The identifier of the process step, if
                          you did not specify the number (you specified 
			  PRO_VALUE_UNUSED).
      p_solid		- The solid that contains the process step.

   Output Arguments:
      p_proc_step	- The handle to the process step, if found.

   Return Values:
      PRO_TK_E_FOUND	 - The function found the process step in
                           the solid.
      PRO_TK_E_NOT_FOUND - The function did not find the process step
                           in the solid.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

extern ProError ProProcstepNumberGet ( ProSolid        p_solid,
	  			       ProProcstep    *p_proc_step,
                                       int            *r_step_number );
/*
   Purpose:  Retrieves the process step number from the specified solid.

   Input Arguments:
      p_solid		- The solid that corresponds to the process step.
      p_proc_step	- The process step handle.
                          
   Output Arguments:
      r_step_number     - The step number in the active step list. If there 
                          is an error, this is initialized to PRO_VALUE_UNUSED.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the 
                             information. 
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_NOT_VALID     - The specified <i>p_proc_step</i> is invalid.
*/

extern ProError ProProcstepVisit  (ProSolid     p_solid,
                                   ProGeomitemAction  action,
                                   ProGeomitemFilter filter,
                                   ProAppData   app_data);
/*
   Purpose:  Visits all the process steps in the specified solid.

   Input Arguments:
      p_solid		- The solid.
      action		- The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter		- The filter function. If NULL, all process steps 
                          are visited using the action function.
      app_data		- The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the process 
			   steps.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - No process steps were found.
      Other              - Any other value is the value returned by the action 
                           function (visiting stopped). 
*/

PRO_END_C_DECLS

#endif /* PRO_PROCSTEP_H */
