#ifndef PROMODELITEM_H
#define PROMODELITEM_H

/*
   Creo Parametric TOOLKIT declarations for ProModelitem actions
*/

#include <ProObjects.h>
#include <ProVerstamp.h>
#include <ProFeature.h>



PRO_BEGIN_C_DECLS

extern ProError ProModelitemInit  (ProMdl         p_owner_handle, 
                                   int            item_id, 
                                   ProType        item_type, 
                                   ProModelitem  *p_handle);
/*
   Purpose:     Initializes the <i>ProModelitem</i> handle. For better 
                performance, 
                use the type-specific functions (<b>Pro*Init()</b>) instead of
                this function.

   Input Arguments:
      p_owner_handle    - The model owner of the item. Cannot be NULL.
      item_id           - The item identifier
      item_type         - The item type

   Output Arguments:
      p_handle          - The handle to initialize. Cannot be NULL.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid 
                          or item was not found .
     PRO_TK_NOT_EXIST   - Item with such id and type does not exist.
*/

extern ProError ProModelitemMdlGet (ProModelitem    *p_model_item, 
                                    ProMdl          *p_owner);
/*
   Purpose:     Retrieves the model the owns the specified item.

   Input Arguments:
      p_model_item      - The model item

   Output Arguments:
      p_owner           - The handle to the owner model 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProModelitemNameGet (ProModelitem *p_item,
                                     ProName       name);
/*
   Purpose:     Retrieves the name of the specified model item.
<p>
                The valid types (<i>p_item->type</i>) are as follows:
                <ul>
                <li>PRO_EDGE 
                <li>PRO_SURFACE 
                <li>PRO_FEATURE 
                <li>PRO_CSYS 
                <li>PRO_AXIS 
                <li>PRO_POINT 
                <li>PRO_QUILT
                <li>PRO_CURVE 
                <li>PRO_LAYER
                <li>PRO_DIMENSION
                <li>PRO_REF_DIMENSION
		<li>PRO_NOTE
                <li>PRO_GTOL
                <li>PRO_SURF_FIN
                <li>PRO_SYMBOL_INSTANCE
                <li>PRO_SET_DATUM_TAG
		<li>PRO_SIMP_REP
		<li>PRO_EXPLD_STATE
		<li>PRO_ANNOTATION_ELEM
                </ul>
                <p>
                If you pass any other type, the function returns 
                PRO_TK_BAD_INPUTS.

   Input Arguments:
      p_item            - The model item

   Output Arguments:
      name              - The name

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the name.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The specified item does not have a name. 
*/


extern ProError ProModelitemNameSet (ProModelitem *p_item,
                                     ProName       name);
/*
   Purpose:     Sets or resets the name of the model item.
<p>
                The valid types (<i>p_item->type</i>) are as follows:
                <ul>
                <li>PRO_EDGE 
                <li>PRO_SURFACE 
                <li>PRO_FEATURE 
                <li>PRO_CSYS 
                <li>PRO_AXIS 
                <li>PRO_POINT 
                <li>PRO_QUILT
                <li>PRO_CURVE 
                <li>PRO_LAYER
                <li>PRO_DIMENSION
                <li>PRO_REF_DIMENSION
		<li>PRO_NOTE
                <li>PRO_GTOL
                <li>PRO_SURF_FIN
                <li>PRO_SYMBOL_INSTANCE
  		<li>PRO_SIMP_REP
		<li>PRO_EXPLD_STATE
		<li>PRO_ANNOTATION_ELEM
                </ul>
                <p>
                If you pass any other type, the function returns
                PRO_TK_BAD_INPUTS.

   Input Arguments:
      p_item            - The model item
      name              - The name to set

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully set the name.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_LINE_TOO_LONG - The string passed has exceeded the maximum size,
                             that is, PRO_NAME_SIZE.  
      PRO_TK_INVALID_NAME  - The name specified is not a valid name for
                             a model item in Creo Parametric.
*/

extern ProError ProModelitemByNameInit ( ProMdl         mdl, 
                                         ProType        type, 
                                         ProName        name, 
                                         ProModelitem*  p_item ); 
/* 
    Purpose:  Gets a model item handle, given the name and 
              type of the item ( p_item is pre allocated ). 

    Input Arguments: 
              mdl  - The model. 
              type - The type of item to find. 
              name - The name of the item to find. 

    Output Arguments: 
              p_item - Pointer to the item found. 

    Return Values: 
              PRO_TK_NO_ERROR    - The item was found. 
              PRO_TK_E_NOT_FOUND - The item was not found. 
              PRO_TK_BAD_INPUTS  - One or more input arguments was invalid. 

*/ 

extern ProError ProModelitemNameCanChange ( ProModelitem* item, 
                                            ProBoolean*   can_change ); 
/* 
    Purpose:  Identifies whether or not the item's name is readonly. 

    Input Arguments: 
              item -  The model item handle. 

    Output Arguments: 
              can_change - PRO_B_TRUE if the model item's name can be 
                           changed, PRO_B_FALSE if it is readonly. 

    Return Values: 
            PRO_TK_NO_ERROR   - The item was found. 
            PRO_TK_BAD_INPUTS - The input argument was invalid. 
*/ 

extern ProError ProModelitemDefaultnameGet ( ProModelitem   *item,
                                             ProName         name );
/*

    Purpose:   Gets the "default" name for the item.  This is the name
	           assigned by Creo Parametric to the item when it was created, before 
			   it may or may not have been modified by the user.  For feature
			   names where the default name would include spaces, this
			   function will substitute underscore characters ("_") for
			   spaces.

    Input Arguments:
               item - The model item handle.

    Output Arguments:
               name - The default name for this item.

    Return Values:
               PRO_TK_NO_ERROR        - Default name was found.
               PRO_TK_E_NOT_FOUND     - Default name was not found.
               PRO_TK_BAD_INPUTS      - The input argument was invalid.
               PRO_TK_NOT_IMPLEMENTED - Not supported for this item type.

	See Also:
            ProModelitemNameGet()
*/

extern ProError ProModelitemUsernameDelete( ProModelitem *item );
/*

    Purpose:   Removes the user-defined name from the object.  For objects
	           which must have some name in Creo Parametric, the default name
			   will be used instead.

    Input Arguments:
               item  -  The model item handle.

    Output Arguments:
               none

    Return Values:
            PRO_TK_NO_ERROR        - The item name was found and deleted.
            PRO_TK_E_NOT_FOUND     - Name was not deleted.
            PRO_TK_BAD_INPUTS      - The input argument was invalid.
            PRO_TK_NOT_IMPLEMENTED - Not supported for this item type.

	See Also:
            ProModelitemNameGet()
            ProModelitemDefaultnameGet()

*/

typedef ProError (*ProModelitemFilterAction) (ProModelitem* item, ProAppData app_data);
/*
    Purpose: Filter action for visiting model items.
             

    Input Arguments:
        item - The model item.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef ProError (*ProModelitemVisitAction) (ProModelitem* item, ProError error, ProAppData app_data);
/*
    Purpose: Visit action for visiting model items.
             

    Input Arguments:
        item - The model item.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
PRO_END_C_DECLS

#endif /* PROMODELITEM_H */

