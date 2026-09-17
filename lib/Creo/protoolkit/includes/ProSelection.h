#ifndef PROSELECTION_H 
#define PROSELECTION_H

/* 
   Creo Parametric TOOLKIT declarations for ProSelection, ProSellist and 
   ProCompPath related actions
*/

#include <ProObjects.h>
#include <ProView.h>
#include <ProAsmcomppath.h>



PRO_BEGIN_C_DECLS

/* this is an opaque handle, which the user should not dereference */
typedef struct select3d *ProSelection;

typedef ProError (*ProSelectionPreFilter) ( ProSelection selection,
					    Pro3dPnt     point,
					    ProMatrix    transform,
					    char        *option,
					    int          level,
					    ProAppData   app_data );
/*
   Purpose: This is the user-defined, pre-filter function.
            Every selection candidate will be called.

   Input Arguments:
      selection - The selection handle.
      point     - The selected point in screen coords.
      transform - The current view matrix.
      option    - Tells how far through the Creo Parametric selection process 
                  to go.  The value is the same as is passed to 
		  <b>ProSelect()</b> with the
                  addition to a view, part, or assembly.
      level     - The current depth of the assembly hierarchy.
      app_data  - The user data passed to <b>ProSelect()</b>.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Accept the selection.
      Other           - Ignore the selection.
*/


typedef ProError (*ProSelectionPostFilter) ( ProSelection selection,
					     ProAppData   app_data) ;
/*
   Purpose:  This is the user-defined, post-filter function.
             Called before being added to the stack for QUERY_SELCT
             every potential selection is validated by calling the
             ProSelectionPostFilter.

   Input Arguments:
      selection - The handle to the selection made
      app_data  - The user data passed to <b>ProSelect()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Accept the selection.
      Other           - Ignore the selection.
*/
	
typedef ProError (*ProSelectionPostSelact) ( Pro3dPnt     point,
					     ProSelection selection,
					     ProAppData   app_data) ;
/*
   Purpose:  This is the user-defined, post-selection callback function.
             Called on a selection after QUERY_SELECT

   Input Arguments:
      point     - The selected point
      selection - The handle to the selection made
      app_data  - The user data passed to <b>ProSelect()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Accept the selection.
      Other           - Ignore the selection.
*/

typedef struct pro_sel_functions
{
   ProSelectionPreFilter   pre_filter;
   ProSelectionPostFilter  post_filter;
   ProSelectionPostSelact  post_selact;
   ProAppData              app_data;
} ProSelFunctions;

typedef void (*ProSelectionStartNotify) ( ProAppData   ext_data) ;
/*
   Purpose:  Allows applications to make their media ready for ProSelect
			interaction.This is called once upon entering ProSelect().

   Input Arguments:
      ext_data  - The user data passed to <b>ProSelect()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Accept the selection.
      Other           - Ignore the selection.
*/


typedef void (*ProSelectionExtHighlightAct) ( ProSelection selection,
                                              ProBoolean highlight,
                                             ProAppData   ext_data) ;
/*
   Purpose:  This is called when an item is selected/unselected and asks
					external application to highlight/unhighlight an entry in their
					media corresponding to the passed selection.
					In case selection is NULL and highlight is  PRO_B_FALSE application 
					should clear all highlighting.

   Input Arguments:      
      selection - The handle to the selection made
	  highlight   - The user's choice to highlight/unhighlight
      ext_data  - The user data passed to <b>ProSelect()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Accept the selection.
      Other           - Ignore the selection.
*/

					     
typedef void (*ProSelectionEndNotify) ( ProAppData   ext_data) ;
/*
   Purpose:  Allows applications to clean their media.
					Called once upon exiting ProSelect().


   Input Arguments:
      ext_data  - The user data passed to <b>ProSelect()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Accept the selection.
      Other           - Ignore the selection.
*/

typedef struct pro_select_ext_highlight_functions
{
   ProSelectionStartNotify   sel_start;
   ProSelectionExtHighlightAct  highlight;
   ProSelectionEndNotify    sel_end;
   ProAppData              ext_data;
} ProSelectExternalhighlightFunctions;

typedef enum
{
   PRO_SELECT_DONE_REQUIRED    = 50,
   PRO_SELECT_BY_MENU_ALLOWED  = 51,
   PRO_SELECT_BY_BOX_ALLOWED   = 52,
   PRO_SELECT_ACTIVE_COMPONENT_IGNORE   = 53,
   PRO_SELECT_HIDE_SEL_DLG   = 54
} ProSelectionEnvAttr;

typedef struct
{
   ProSelectionEnvAttr   attribute;
   int                   value;
} ProSelectionEnvOption;

typedef enum
{
  PRO_SELECT_OVERRIDE,
  PRO_SELECT_TOGGLE
} ProSelectRecordAction;

typedef void *ProSelAppAction;

typedef struct appl_sel_env* ProSelectionEnv;

extern ProError ProSelectionAlloc( ProAsmcomppath *p_cmp_path,
				   ProModelitem *p_mdl_itm,
				   ProSelection *p_selection );

/*
   Purpose: Allocates and optionally fills in a selection object.
            <p>
            The allowed combinations of input arguments are as follows:
            <table> 
            <tr>
                <td><b>p_cmp_path</b></td>   
                <td><b>p_mdl_itm</b></td>
            </tr>

            <tr>
            <td>!NULL</td><td>!NULL</td>
            </tr>

            <tr>
            <td>NULL</td><td>!NULL</td>
            </tr>

            <tr>
            <td>NULL</td><td>NULL</td>
            </tr>
            </table>

   Input Arguments:
      p_cmp_path - The component path. Can be NULL only in case of parts. 
				   Cannot be NULL in case of assemblies.
      p_mdl_itm  - The model item (can be NULL)

   Output Arguments:
      p_selection - The allocated selection object

   Return Values:
      PRO_TK_NO_ERROR - The function successfully allocated the selection.
      PRO_TK_BAD_INPUTS - The allocation failed.
*/


extern ProError ProSelectionCopy( ProSelection  from_selection,
				  ProSelection  *p_to_selection );

/*
   Purpose: Copies a selection object.

   Input Arguments:
      from_selection - The selection object to copy

   Output Arguments:
      p_to_selection - The copied selection object

   Return Values:
      PRO_TK_NO_ERROR - The function successfully copied the selection.
      PRO_TK_BAD_INPUTS - The copy failed.
*/

extern ProError ProSelectionFree( ProSelection *p_selection );

/*
   Purpose: Frees a preallocated selection object.

   Input Arguments:
      p_selection - The address of the selection object

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the selection.
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/

extern ProError ProSelectionarrayFree( ProSelection *sel_array );

/*
   Purpose: Frees a ProArray of allocated selection objects (also frees 
            each member ProSelection).

   Input Arguments:
      sel_array - The selection object array.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the selection.
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/



extern ProError ProSelectionSet( ProSelection  selection,
				 ProAsmcomppath *p_cmp_path,
				 ProModelitem *p_mdl_itm );
/*
   Purpose: Sets the model item (and optionally a component path) for a 
            selection object.

   Input Arguments:
      selection  - The selection object 
      p_cmp_path - The component path (can be null)
      p_mdl_itm  - The model item

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the component path.
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/


extern ProError ProSelectionAsmcomppathGet( ProSelection  selection,
					    ProAsmcomppath *p_cmp_path );

/*
   Purpose: Gets the component path from a selection object.

   Input Arguments:
      selection  - The selection object.
      p_cmp_path - The component path. You must allocate the memory for this 
                   structure.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the component path.
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/



extern ProError ProSelectionModelitemGet( ProSelection selection,
					  ProModelitem *p_mdl_item );

/*
   Purpose: Gets the model item from a selection object.

   Input Arguments:
      selection  - The selection object.

   Output Arguments:
      p_mdl_item - The model item.

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the model item.
      PRO_TK_NOT_EXIST - The model item doesn't exist.
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/


extern ProError ProSelectionUvParamSet( ProSelection selection,
					ProUvParam uv_param );


/*
   Purpose: Sets the UV-parameters to a selection object.
            <p>
            NOTE: 
            <p> 
            This applies to surface selections only.

   Input Arguments:
      selection - The selection object
      uv_param  - The UV-parameters

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set the UV-parameters
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/

extern ProError ProSelectionUvParamGet( ProSelection selection,
					ProUvParam uv_param );

/*
   Purpose: Gets the UV-parameters from a selection object.

   Input Arguments:
      selection - The selection object
      uv_param - The UV-parameters

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the UV-paramters.
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/

extern ProError ProSelectionViewGet( ProSelection selection,
				     ProView* p_view );
/*
   Purpose: Gets the handle to the view from the selection object.

   Input Arguments:
      selection - The selection object
  
   Output Arguments:
      p_view    - The view handle

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS - The supplied inputs were incorrect.
*/

extern ProError ProSelectionPoint3dGet( ProSelection selection,
					ProPoint3d   point  );
/*
   Purpose: Retrieves the coordinates of the selected point in the member 
            coordinate system.

   Input Arguments:
      selection - The selection object

   Output Arguments:
      point     - The point coordinates  

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The selection or depth is NULL.
      PRO_TK_INVALID_PTR - The selection argument is an invalid pointer.
*/

extern ProError ProSelectionWindowIdGet( ProSelection selection,
					 int*         window_id  );
/*
   Purpose: Retrieves the window id in which selection was made.

   Input Arguments:
      selection - The selection object

   Output Arguments:
      window_id - The window id

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The selection or depth is NULL.
      PRO_TK_INVALID_PTR - The selection argument is an invalid pointer.
*/

extern ProError ProSelectionDepthGet( ProSelection selection,
				      double*      depth  );
/*
   Purpose: Gets the selection depth, in screen coordinates.

   Input Arguments:
      selection - The selection object

   Output Arguments:
      depth     - The selection depth, in screen coordinates

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The selection or depth is NULL.
      PRO_TK_INVALID_PTR - The selection argument is an invalid pointer.
*/
 
extern ProError ProSelect( char              option[],
			   int               max_count,
			   ProSelection     *p_in_sel,
			   ProSelFunctions  *sel_func,
			   ProSelectionEnv   sel_env,
			   ProSelAppAction   appl_act_data,
			   ProSelection    **p_sel_array,
			   int              *p_n_sels );


/*
   Purpose: Selects an object in a Creo Parametric window.
   <p>
   NOTE: If the user ends the selection without actually making any, 
   ProSelect will return PRO_TK_NO_ERROR with (*p_n_sels) as zero and 
   p_sel_array  as NULL.
   <p>
   
   Input Arguments:
      option    - The selection filter. See the 
		  <i>Creo Parametric TOOLKIT User's Guide</i>
		  for more information.
      max_count - The maximum number of selections allowed.
      p_in_sel  - A <i>ProArray</i> of pointers to 
		  <i>ProSelection</i> structures
                  (from a previous call to selection)
                  used to initialize the array of selections. This
                  can be NULL.
      sel_func  - A pointer to a structure of filter functions. This
                  can be NULL.
      sel_env   - Use ProSelectionEnvAlloc() to allocate this argument. Can be NULL.
      appl_act_data - NULL in Release 18 and higher.

   Output Arguments:
      p_sel_array - A pointer to an array of 
		    <i>ProSelection</i> structures. This
                    argument points to static memory allocated by the function.
                    It is reallocated on subsequent calls to this function.

      p_n_sels    - The actual number of selections made.

   Return Values:
      PRO_TK_NO_ERROR   - The user made a selection, or chose <b>Done</b>.
      PRO_TK_USER_ABORT - The user chose <b>Quit</b>.
      PRO_TK_PICK_ABOVE - Selection was interrupted by a user's pick on
                          any button from above menus.
      PRO_TK_E_DEADLOCK - The Creo Parametric user interface is not prepared
                          to handle this request (because it is blocked by
                          another process such as an OLE container activation).
                            
   See Also: 
      ProSelectionEnvAlloc()
*/


extern ProError ProSelectionVerify( ProSelection selection  );

/*
   Purpose:     Verifies the validity of the <i>ProSelection</i>.

   Input Arguments:
      selection         - The selection to verify

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully verified the selection.
      PRO_TK_INVALID_TYPE - Selection is invalid.
      PRO_TK_BAD_INPUTS   - The verification failed.
*/

extern ProError ProSelectionHighlight( ProSelection selection,
				       ProColortype color );

/*
   Purpose:     Highlights the selection in the current window. 
                The selection remains highlighted until you call the 
		function <b>ProSelectionUnhighlight()</b>.

   Input Arguments:
      selection         - The selection to highlight
      color             - The highlight color

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully highlighted the selection.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProSelectionDisplay( ProSelection selection  );

/*
   Purpose:     Displays the selection. Note that this is a one-time action
                (the next repaint will erase this display).

   Input Arguments:
      selection         - The selection to display
      unused            - Reserved for future use

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully displayed the selection.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProSelectionUnhighlight( ProSelection selection  );

/*
   Purpose:     Removes the highlighting from the selection, which was
                highlighted by a previous call to <b>ProSelectionHighlight()</b>.

   Input Arguments:
      selection         - The selection from which to remove the highlighting

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully removed the highlighting.
      PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProSelectionEnvAlloc( ProSelectionEnvOption*  sel_env_array,
				      int                     count,
				      ProSelectionEnv*        p_sel_env );
/*
   Purpose: Allocates a <i>ProSelectionEnv</i>, which is a set of attributes that
            can be passed to <b>ProSelect()</b>.

   Input Arguments:
      sel_env_array - An array of the attributes (the type and value)
                      assigned to it
      count         - The number of items in <i>sel_env_array</i>

   Output Arguments:
      p_sel_env      - The handle to the <i>ProSelectionEnv</i>

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully allocated the structure. 
      PRO_TK_BAD_INPUTS - The specified attributes are invalid.
*/

extern ProError ProSelectionEnvFree( ProSelectionEnv p_sel_env  );
          
/*
   Purpose:     Frees the <i>ProSelectionEnv</i> allocated by 
                <b>ProSelectionEnvAlloc()</b>.

   Input Arguments:
     p_sel_env    - A valid handle to the <i>ProSelectionEnv</i>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully freed the memory.
      PRO_TK_BAD_INPUTS  - The argument <i>p_sel_env</i> is NULL.
*/



extern ProError  ProSelectionViewSet( ProView view, 
                                      ProSelection *p_prosel);
/*
   Purpose:    Sets the view of the ProSelection to the user provided ProView.
                 
   Input Arguments:
       view -      user-provided ProView.
       p_prosel -  pointer to user-provided ProSelection.

   Output Arguments:
       none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the view.
      PRO_TK_BAD_INPUTS  - One of the arguments is NULL.
*/




extern ProError ProSelectionPoint3dSet( ProPoint3d point, 
                                        ProSelection *p_prosel);
/*
   Purpose:   Uses user-provided ProPoint3d to set the selected-point of the ProSelection.
                
   Input Arguments:
       point    -  User-provided ProPoint3d.
       p_prosel -  Pointer to user-provided ProSelection.

   Output Arguments:
       none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the selected-point
                           of the ProSelection.
      PRO_TK_BAD_INPUTS  - One of the arguments is NULL.

*/                                                                              
  
                                      
extern ProError ProSelectionDwgtblcellGet(ProSelection selection, 
                                          int *table_segment, 
                                          int *row, 
                                          int *column);
/*
   Purpose: For a ProSelection representing a cell of a drawing table,
            returns the table segment, row and column of the cell.
            <p>
            This function returns row and column indices starting from 0.0.
            Add one to these values to obtain the correct row and column 
            indices for use with other ProDwgtable functions.
    
   Input Arguments:
       selection - ProSelection representing a cell of a drawing table.

   Output Arguments:
         table_segment - Corresponding table segment, equals sel_elem_id of selection.
         row - row of table which contains the cell.
         column - column of the table which contains the cell.
   
 
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the selected-point of the ProSelection.

*/  



extern ProError ProSelectionDwgtableGet( ProSelection selection, 
                                         ProDwgtable * table);

/*
   Purpose: For a ProSelection representing a cell of a drawing table,
            returns the table from which the cell was selected.
                
   Input Arguments:
       selection - ProSelection representing a cell of a drawing table.

   Output Arguments:
         table - The table from which the cell was selected.
   
 
   Return Values:
      PRO_TK_BAD_INPUTS - selection not provided, selection not a table cell,
                          or ProDwgtable for output not provided.
      PRO_TK_NO_ERROR    - Successfully found table corresponding to the table cell.

*/  

extern ProError ProSelectionDrawingGet( ProSelection selection, 
                                        ProDrawing * drawing);

/*
   Purpose: For a ProSelection representing a entities selected in a drawing
            returns the drawing model handle from which the entities were selected
      
   Input Arguments:
       selection - ProSelection representing an entity selected in a drawing

   Output Arguments:
         drawing - The drawing model handle from which the selection was made
   

   Return Values:
      PRO_TK_BAD_INPUTS  - invalid inputs 
      PRO_TK_E_NOT_FOUND - no associated drawing found
      PRO_TK_NO_ERROR    - Successfully in finding the drawing for the selection

*/ 


extern  ProError  ProSelectionCollectionGet( ProSelection sel,
                                             ProCollection* collection );
/*
	Purpose: Get the ProCollection object from a ProSelection.
	Input Arguments:
		sel - The selection object
	
	Output Arguments:
		collection - The collection object

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more arguments was invalid.
		PRO_TK_INVALID_TYPE - The selection object does not contain a collection.
		PRO_TK_INVALID_PTR - The selection object contains a chain, but this chain reference is no longer valid.   Chain references contained in ProSelections are only valid for as long as the chain is selected in the selection buffer.

See Also:
		ProSelbufferCollectionAdd()
*/

extern ProError ProSelectionDistanceEval (ProSelection p_selection1,
					  ProSelection p_selection2,
					  Pro2dPnt param_1,
					  Pro2dPnt param_2,
					  Pro3dPnt pnt_1,
					  Pro3dPnt pnt_2,
					  double *p_result );
/*
   DEPRECATED: since Creo 4.0
   SUCCESSORS: ProSelectionWithOptionsDistanceEval
   Purpose: Evaluate the distance between two items. Objects can be surfaces,
            entities, surface-curves, surface-nodes, or points. The selected
            points on the objects are used as the initial guesses. In case of
            error, p_result will be set to -1.0 and all params will be set 
            to 0.0.

            <b>Note: </b> This function works incorrectly for datum planes
            and axes. The resulted distance is measured to the selected point
            instead of the projection to the datum/axis. Please use instead 
            ProSelectionWithOptionsDistanceEval.
      	    	
   Input Arguments:
       p_selection1 - The first selection.
       p_selection2 - The second selection.

   Output Arguments:
       param_1 - UV params of the critical point on the first item.
       param_2 - UV params of the critical point on the second item.
       pnt_1   - Critical point on the first item.
       pnt_2   - Critical point on the second item.
       p_result - The resulting distance between the two items.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully evaluated the distance.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid. 
      PRO_TK_BAD_CONTEXT - Not applicable to the input selections.
*/

extern ProError ProSelectionWithOptionsDistanceEval (
                   ProSelection p_selection1,
                   ProBool option1, 
                   ProSelection p_selection2,
                   ProBool option2,
                   Pro2dPnt param_1,
                   Pro2dPnt param_2,
                   Pro3dPnt pnt_1,
                   Pro3dPnt pnt_2,
                   double *p_result );
/*
   Purpose: Evaluate the distance between two items. Objects can be surfaces,
            edges, entities, vertices or datums. The selected
            points on the objects are used as the initial guesses. In case of
            error, p_result will be set to -1.0 and all parameters will be set 
            to 0.0. option1 and option2 can be specified to alter the desired
            behavior for the corresponded selection.

   Input Arguments:
       p_selection1 - The first selection.
       option1 - The option related to the first selection.
                 The usage is analogical to the checkbox in the measure
                 distance UI.
                 For the PRO_B_TRUE value:
                 - if selection is cylinder surface, treat it as axis.
                 - if selection is planar, treat it as borderless plane.
                 - if selection is arc, treat it as its center point,
                 - if selection is linear, treat it as borderless line.
       p_selection2 - The second selection.
       option2 - The option related to the second selection analogical to
                 option1.

   Output Arguments:
       param_1  - UV parameters of the critical point on the first item.
       param_2  - UV parameters of the critical point on the second item.
       pnt_1    - Critical point on the first item.
       pnt_2    - Critical point on the second item.
       p_result - The resulting distance between the two items.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully evaluated the distance.
      PRO_TK_OUT_OF_RANGE - The function successfully evaluated the distance,
                            but UV parameters could not be evaluated. It may
                            happen when dealing with borderless items and
                            the calculated critical point is outside of the
                            item boundaries.
      PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT  - Not applicable to the input selections.
*/

extern ProError  ProSelectExternalselectionRecord (ProSelection selection,  
                                              ProSelectRecordAction  action);
/*
   Purpose:  Places external selection into ProSelect() buffer.
	     Together with ProSelectExternalhighlightRegister() provides 
             interaction between external application media 
	     like a tree and ProSelect().  Upon an object selection
	     in their media, applications should create ProSelection
	     and use ProSelectExternalselectionRecord to 
	     pass it to ProSelect().
      	    	
   Input Arguments:
       selection - Created by an external application.
       action - PRO_SELECT_OVERRIDE for unmodified selection.
                PRO_SELECT_TOGGLE for CTRL modified selection.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully placed selection.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid. 
      PRO_TK_INVALID_ITEM - Rejected by ProSelect() filters.
*/

extern ProError ProSelectExternalhighlightRegister (
                                ProSelectExternalhighlightFunctions *show_func);
/*
   Purpose:  Register external application highlighting callbacks
             in order to let application media like a tree react
	     on selections made while ProSelect() is active.
	     Together with ProSelectExternalselectionRecord() provides 
             interaction between external application media and
	     ProSelect().  
      	    	
   Input Arguments:
       show_func - callbacks.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully registered callbacks.
      PRO_TK_GENERAL_ERROR - The function failed to register callbacks.     
*/
PRO_END_C_DECLS
#endif /* PROSELECTION_H */
