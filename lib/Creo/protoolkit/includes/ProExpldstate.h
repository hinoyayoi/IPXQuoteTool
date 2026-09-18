#ifndef PROEXPLDSTATE_H
#define PROEXPLDSTATE_H

/* Por/TOOLKIT declarations for ProExpldstate related actions */

#include <ProObjects.h>
#include <ProSolid.h>
#include <ProSimprepdata.h>
#include <ProRule.h>



PRO_BEGIN_C_DECLS

typedef enum
{
     PRO_EXPLDANIM_MOVE_TRANSLATE = 0,
     PRO_EXPLDANIM_MOVE_ROTATE    = 1
} ProExpldAnimMoveType;

typedef struct _pro_expld_anim_move
{
  ProExpldAnimMoveType move_type;
  ProRay               direction;  /* translation direction or rotation axis */
  double               value;      /* distance or angle */
} ProExpldAnimMove;
        
typedef struct _pro_expld_anim_move_data
{
     ProAsmcomppath         *comp_set;
     ProExpldAnimMove        move;    
} ProExpldAnimMoveData;        
        


extern ProError ProExpldstateInit (ProName expld_name, 
                                   int expld_id, 
                                   ProSolid p_solid, 
                                   ProExpldstate *p_handle);
/*

   Purpose: Returns the handle to the specified explode state.

   Input Arguments:
      expld_name        - The name of the specified explode state in the solid.
                          If you specify this argument, the function
                          ignores <i>expld_id</i>.
      expld_id          - The identifier of the explode state, if
                          you did not specify the name (you specified NULL).
      p_solid           - The solid that contains the explode state. Cannot be NULL.
      
   Output Arguments:
      p_handle          - The handle to the explode state, if found.

   Return Values:
      PRO_TK_E_FOUND     - The function found the explode state in
                           the solid.
      PRO_TK_E_NOT_FOUND - The function did not find the explode state
                           in the solid.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid -
                           for instance, p_solid is NULL or not PRO_ASSEMBLY.
      PRO_TK_INVALID_PTR - p_solid is not a correct ProSolid pointer.
*/


extern ProError ProExpldstateActivate (ProSolid p_solid,
                                       ProExpldstate *p_expl_state);
/*

   Purpose: Activates the specified explode state representation.

   Input Arguments:
      p_solid		- The solid that corresponds to the explode state
      p_expl_state	- The explode state representation

   Output Arguments:
      None

   Return Values:	
      PRO_TK_NO_ERROR	 - The function successfully activated the explode
                           state representation.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - The specified explode state was not found in the
                           model. 
*/

extern ProError ProSolidExpldstateVisit  (ProSolid  p_solid,
						   ProGeomitemAction action,
                                                   ProGeomitemFilter filter,
						   ProAppData  app_data);
/*
   Purpose: Visits all the explode states in the specified solid,
	    but does not visit the default state.

   Input Arguments:
      p_solid		- The model containing the explode states.
      action            - The visiting function.  If it returns anything other
                          than PRO_TK_NO_ERROR, visiting stops. 
      filter	        - The filter function. If NULL, visits all explode 
			  states using the action function.
      app_data          - The application data passed to the filter
			  and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully visited all the explode 
			  states.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
      Other		- Any other valus is the value returned by the 
			  action function (visiting stopped).
*/

extern ProError ProExpldstateSelect  (ProSolid	p_solid,
						 ProExpldstate *p_expl_state);
/*
   Purpose: Enables the user to select an explode state.

   Input Arguments:
      p_solid		- The solid that contains the explode state

   Output Arguments:
      p_expl_state	- The selected explode state

   Return Values:
      PRO_TK_NO_ERROR	- The user selected a valid explode state.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProExpldstateActiveGet (ProSolid	p_solid,
						 ProExpldstate *p_expl_state);
/*
   Purpose:  Returns the current active explode state.

   Input Arguments:
      p_solid		- The solid that contains the explode state

   Output Arguments:
      p_expl_state	- The current active explode state

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully retrieved the current
			  active explode state.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProExpldstateCreate (ProSolid              p_solid,
                                     ProName               name,   
                                     ProExpldAnimMoveData *p_move_arr,
                                     ProExpldstate        *p_new_expl_state);
/*
   Purpose:  Creates an explode state.

   Input Arguments:
      p_solid           - The assembly where the explode state will be created.
                          Cannot be NULL.
      name              - The name of the state. Cannot be NULL.
      p_move_arr        - ProArray of the state moves. Can be NULL.
                          <p>Each ProExpldAnimMoveData element
                          describes the set of assembly components and how
                          they should be moved. The moves are applied in 
                          the same order as they go in the array.

   Output Arguments:
      p_new_expl_state  - The new explode state

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the explode state.
      PRO_TK_BAD_INPUTS    - Some of the input argument is invalid (see also errors
                             for ProExpldstateInit and ProArraySizeGet).
      PRO_TK_INVALID_NAME  - The explode state with given name cannot be created 
                             (there is an explode state with such name; or name
                             contains invalid characters)
      PRO_TK_GENERAL_ERROR - Failed to create the state.
      PRO_TK_E_NOT_FOUND   - Some ProAsmcomppath in comp_set for some moves do not
                             correspond to any component (this error may be also 
                             returned for other non-specified cases).
*/

extern ProError ProExpldstateDelete (ProExpldstate *p_expl_state);
/*
   Purpose:  Deletes an explode state.

   Input Arguments:
      p_expl_state      - The explode state to delete. Cannot be NULL.
   Output Arguments:
      none       
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully deleted the explode state.
      PRO_TK_BAD_INPUTS    - Not a valid explode state handle 
                             (other errors are also possible).
      PRO_TK_E_NOT_FOUND   - explode state was not found.
*/


extern ProError ProExpldstateNameGet (ProExpldstate *p_expl_state, 
                                      ProName        name);
/*
   Purpose:  Returns the name of an explode state.

   Input Arguments:
      p_expl_state       - The explode state. Cannot be NULL.
   Output Arguments:
      name               - The name of the explode state.  Cannot be NULL.
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully returned the name.
      PRO_TK_BAD_INPUTS  - Not a valid explode state handle 
                             (other errors are also possible).
      PRO_TK_E_NOT_FOUND - explode state was not found.
*/

extern ProError ProExpldstateNameSet (ProExpldstate *p_expl_state, 
                                      ProName        name);
/*
   Purpose:  Sets the name of an explode state.

   Input Arguments:
      p_expl_state      - The explode state. Cannot be NULL.
      name              - The name of the explode state.  Cannot be NULL.
   Output Arguments:
      none
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the name.
      PRO_TK_BAD_INPUTS  - Not a valid explode state handle 
                           (other errors are also possible).
      PRO_TK_E_NOT_FOUND - explode state was not found.
*/

extern ProError ProExpldstateExplodedcomponentsGet (ProExpldstate   *p_expl_state,
                                                    ProAsmcomppath **pp_comp_paths);
/*
   Purpose:  Gets the components of an explode state.

   Input Arguments:
      p_expl_state      - The explode state. Cannot be NULL.
   Output Arguments:
      pp_comp_paths     - ProArray of paths to components which are included 
                          in this explode state. Cannot be NULL.
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully returned the component paths.
      PRO_TK_BAD_INPUTS    - Some arguments are invalid.
      PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProExpldstateMovesGet (ProExpldstate          *p_expl_state, 
                                       ProExpldAnimMoveData  **pp_move_arr);
/*
   Purpose:  Gets the moves of an explode state.

   Input Arguments:
      p_expl_state      - The explode state. Cannot be NULL.
   Output Arguments:
      pp_move_arr       - ProArray of moves. Cannot be NULL.
                          Free this data using ProExpldanimmovedataProarrayFree().
   Return Values:
      PRO_TK_NO_ERROR      - The successfully returned the moves.
      PRO_TK_BAD_INPUTS    - Some arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The explode state was not found.
      PRO_TK_GENERAL_ERROR - Unspecified error.
*/

extern ProError ProExpldstateMovesSet (ProExpldstate         *p_expl_state, 
                                       ProExpldAnimMoveData  *p_move_arr);
/*
   Purpose:  Sets the moves of an explode state.

   Input Arguments:
      p_expl_state      - The explode state. Cannot be NULL.
      p_move_arr        - ProArray of moves. Can be NULL.
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR      - The successfully returned the moves.
      PRO_TK_BAD_INPUTS    - Some arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The explode state was not found, or 
                             some ProAsmcomppath in comp_set for some moves do not
                             correspond to any component (this error may be also 
                             returned for other non-specified cases).
      PRO_TK_GENERAL_ERROR - Unspecified error.
*/

LIB_COREUTILS_API  ProError ProExpldAnimDataRotatemoveInit (ProRay               direction, 
                                                ProAngle             angle, 
                                                ProAsmcomppath       *comp_set, 
                                                ProExpldAnimMoveData *p_move_data);
/*
   Purpose:  Creats a rotational move.

   Input Arguments:
      direction            - The axis of the rotation. Cannot be NULL.
      angle                - The angle of the rotation. Cannot be NULL.
      comp_set             - ProArray of components to which this move will be applied.
                             cannot be NULL or empty.
   Output Arguments:
      p_move_data          - The move. Cannot be NULL.

   Return Values:
      PRO_TK_NO_ERROR      - The move is created successfully.
      PRO_TK_BAD_INPUTS    - Some arguments are invalid.
*/

LIB_COREUTILS_API  ProError ProExpldAnimDataTranslatemoveInit (ProVector            trans_vec, 
                                                   ProAsmcomppath       *comp_set, 
                                                   ProExpldAnimMoveData *p_move_data);
/*
   Purpose:  Creats a translational move.

   Input Arguments:
      trans_vec            - The direction of the translation. Cannot be NULL.
      comp_set             - ProArray of components to which this move will be applied.
                             cannot be NULL or empty.
   Output Arguments:
      p_move_data          - The move. Cannot be NULL.

   Return Values:
      PRO_TK_NO_ERROR      - The move is created successfully.
      PRO_TK_BAD_INPUTS    - Some arguments are invalid.
*/

LIB_COREUTILS_API  ProError ProExpldanimmovedataProarrayFree (ProExpldAnimMoveData *p_move_arr);
/*
   Purpose:  In each element of ProArray of moves, frees its ProArray comp_set, 
             then frees the ProArray of moves.

   Input Arguments:
      p_move_arr           - ProArray of moves. Cannot be NULL.
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR      - The array is freed successfully.
      PRO_TK_BAD_INPUTS    - Some arguments are invalid. 
                             Other errors are the same as for ProArrayFree
*/

PRO_END_C_DECLS

#endif /* PROEXPLDSTATE_H */


