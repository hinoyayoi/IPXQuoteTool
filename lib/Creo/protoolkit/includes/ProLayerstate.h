
#ifndef PRO_LAYERSTATE_H
#define PRO_LAYERSTATE_H



#include <ProMdl.h>
#include <ProObjects.h>
#include <ProLayer.h>

PRO_BEGIN_C_DECLS

extern ProError ProLayerstatesGet(ProSolid p_solid, 
                                  ProLayerstate **p_state_array);

/*
   Purpose:  Get Layer state list.

   Input Arguments:
      p_solid -               Solid.
 
   Output Arguments:
      p_state_array -         ProArray of layer states.
                              Call the function <b>ProArrayFree()</b> to free
                              the array.

   Return Values:
      PRO_TK_NO_ERROR      -   Returned not empty array of states.
      PRO_TK_BAD_INPUTS    -   Invalid input arguments.
      PRO_TK_E_NOT_FOUND   -   No layer states in the model.
*/

extern ProError ProLayerstateCreate (ProSolid         p_solid, 
                              ProName          state_name, 
                              ProLayer        *layers, 
                              ProLayerDisplay *disp_arr,
                              ProLayerItem    *hidden_items,
                              ProAnnotation   *annotations,
                              int             *status_flags,
                              ProLayerstate   *p_state);

/*
   Purpose: Create Layer state from references.
            <b>Note:</b> ProLayerItem of type PRO_LAYER_LAYER cannot be added to 
            Layer States using ProLayerstateCreate.

   Input Arguments:
       p_solid -             Solid.
       state_name -          New layer state name. The name may consist of 
                             alphanumeric, underscore and hyphen characters only.
       layers -              ProArray of layers referenced by the new state.
       disp_arr -            ProArray of layer display statuses. Must be equal
                             in size to the layers array.
       hidden_items -        ProArray of hidden items. 
       annotations -         ProArray of annotations on a layer.
       status_flags -        ProArray of integers. Statuses of the annotations
                             in the layer state. The statuses are true/false
                             values. true = excluded from layer. Array size
                             must be equal to annotations' size. 

   Output Arguments:
       p_state -             Returned newly created layer state.

   Return Values:
       PRO_TK_NO_ERROR      - Layer state created successfully.
       PRO_TK_BAD_INPUTS    - Incorrect Input parameters.
       PRO_TK_INVALID_ITEM  - Size of arrays don't match. See description above.
       PRO_TK_GENERAL_ERROR - Layer state creation aborted.
       PRO_TK_INVALID_NAME  - Layer state name is invalid. The name may be too long or
							  contains invalid characters.
       PRO_TK_E_FOUND       - Provided layer state name already exists in the model.
*/
                             

extern ProError ProLayerstateLayersGet(ProLayerstate     *state,
                                ProName           state_name,
                                ProLayer        **p_layers,
                                ProLayerDisplay **p_disp_arr,
                                ProLayerItem    **p_hidden_items,
                                ProAnnotation   **p_annotations,
                                int             **p_status_flags);

/*
   Purpose:  Get layer state reference data.

   Input Arguments:
      state -                layer state.
  
   Output Arguments:        
      state_name -           layer state name. Can be NULL.
      p_layers -             ProArray of layers referenced by the layer state.
                             To free the array call <b>ProArrayFree()</b>.
      p_disp_arr -           ProArray of diplay statuses of the layers.
                             To free the array call <b>ProArrayFree()</b>.
      p_hidden_items -       ProArray of referenced hidden items.
                             To free the array call <b>ProArrayFree()</b>.
      p_annotations -        ProArray of referenced annotations.
                             To free the array call <b>ProArrayFree()</b>.
      p_status_flags -       ProArray of annotations' status flags.
                             To free the array call <b>ProArrayFree()</b>.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     -   Successfull function execution.
      PRO_TK_BAD_INPUTS   -   layer state is invalid.
*/

extern ProError ProLayerstateNameGet(ProLayerstate *state, ProName state_name);

/*
   Purpose:      return the name of the layer state.
 
   Input Arguments:
       state -            layer state.
 
   Output Arguments:
       state_name -       layer state name.

   Return Values:
       PRO_TK_NO_ERROR    Name returned successfully.
       PRO_TK_BAD_INPUTS  Incorrect layer state.
*/

extern ProError ProLayerstateDelete (ProLayerstate *p_state);

/*
  Purpose:   Delete specified layer state.

  Input Arguments:
     p_state -              layer state.

  Output Arguments:
     None

  Return Values: 
     PRO_TK_NO_ERROR      -  Layer state deleted.
     PRO_TK_BAD_INPUTS    -  Invalid layer state data.
     PRO_TK_E_NOT_FOUND   -  Layer state not found.
*/

extern ProError ProLayerstateActivate (ProLayerstate *p_state);

/*
  Purpose:   Activate specified layer state. Model of the layer state must be top
              model in window. Otherwise activate fails.

  Input Arguments:
     p_state -              layer state.

  Output Arguments:
     None

  Return Values: 
     PRO_TK_NO_ERROR      -  Layer state activated.
     PRO_TK_BAD_INPUTS    -  Invalid layer state data.
     PRO_TK_E_NOT_FOUND   -  Layer state not found.
     PRO_TK_GENERAL_ERROR -  Can't activate layer state.
*/

extern ProError ProLayerstateActiveGet (ProSolid p_solid, ProLayerstate *p_state);

/*
  Purpose:   Get active layer state on a model.

  Input Arguments:
     p_solid -                    Solid.

  Output Arguments:               
     p_state -                    Active layer state.

  Return Values:
     PRO_TK_NO_ERROR         -     Active layer state returned.
     PRO_TK_BAD_INPUTS       -     Wrong input parameters.
     PRO_TK_E_NOT_FOUND      -     No active layer state on the model.
*/

extern ProError ProLayerstateActivestateUpdate (ProSolid p_solid);
/*
  Purpose:   Update active layer state.

  Input Arguments:
     p_solid -                    Solid.

  Output Arguments:               

  Return Values:
     PRO_TK_NO_ERROR              Active layer state update.
     PRO_TK_BAD_INPUTS            Wrong input parameters.
     PRO_TK_E_NOT_FOUND           No active layer state on the model.
*/

extern ProError ProLayerstateLayerAdd (ProLayerstate   *layer_state, 
                                ProLayer        *layer,
                                ProLayerDisplay display_state);

/*
   Purpose: Add layer reference to a layer state.

   Input Arguments:
      layer_state -         Layer state.
      layer -               Layer to be added.
      display_state -       Display state of the layer to be added.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Layer added.
      PRO_TK_BAD_INPUTS    - Invalid input parameters.
      PRO_TK_BAD_CONTEXT   - Passed models of either layer state or the layer
                             are not of ProSolid type.
      PRO_TK_E_NOT_FOUND   - Layer state is not found.
      PRO_TK_NOT_EXIST     - Layer does not exist.
*/
 

extern ProError ProLayerstateLayerRemove (ProLayerstate *layer_state, 
                                   ProLayer      *layer);

/*
   Purpose: Remove layer reference from a layer state.

   Input Arguments:
      layer_state -         Layer state.
      layer -               Layer to be removed.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Layer removed.
      PRO_TK_BAD_INPUTS    - Invalid input parameters.
      PRO_TK_BAD_CONTEXT   - Passed models of either layer state or the layer
                             are not of ProSolid type.
      PRO_TK_E_NOT_FOUND   - Layer state or Layer is not found.
      PRO_TK_NOT_EXIST     - Layer does not exist.
*/

extern ProError ProLayerstateModelitemHide(ProLayerstate *layer_state, 
                                    ProLayerItem  *item);

/*
   Purpose:   Added an item to be hidden on the layer state.

   Input Arguments:
       layer_state -       Layer State.
       item -              Item to be hidden.
   
   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR    - Item added to the layer state.
       PRO_TK_BAD_INPUTS  - Invalid input arguments. Invalid item.
       PRO_TK_NOT_EXIST   - Layer state not found.
       PRO_TK_NO_CHANGE   - Item is already hidden on the layer state.
*/

extern ProError ProLayerstateModelitemUnhide(ProLayerstate *layer_state, 
                                      ProLayerItem  *item);

/*
   Purpose:   Remove the item from the layer state hidden items list.

   Input Arguments:
       layer_state -         Layer State.
       item -                Item to be unhidden.

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR     -  Item removed from the layer state.
       PRO_TK_BAD_INPUTS   -  Invalid input arguments.
       PRO_TK_NOT_EXIST    -  Layer state not found.
       PRO_TK_NO_CHANGE    -  Item is unhidden already.
*/

extern ProError ProLayerstateModelitemIsHidden(ProLayerstate *layer_state, 
                                        ProLayerItem  *item, 
                                        ProBoolean *p_value);

/*
   Purpose:  Check if the item is hidden on the layer state.

   Input Arguments:
      layer_state -         Layer state.
      item -                Item to be checked.

   Output Arguments:
      p_value -             True / False value.

   Return Values:
      PRO_TK_NO_ERROR     -  Value returned successfully.
      PRO_TK_BAD_INPUTS   -  Invalid input data. 
      PRO_TK_NOT_EXIST    -  Layer state not found. 
*/


PRO_END_C_DECLS

#endif
