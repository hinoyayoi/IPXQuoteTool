


#ifndef PROLAYER_H
#define PROLAYER_H

#include <ProObjects.h>
#include <ProView.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_LAYER_SOLID_GEOM        = PRO_SOLID_GEOMETRY,
  PRO_LAYER_PART              = PRO_PART,    /* This layer item type is no 
                                                longer supported */
  PRO_LAYER_FEAT              = PRO_FEATURE,
  PRO_LAYER_DIMENSION         = PRO_DIMENSION,
  PRO_LAYER_REF_DIMENSION     = PRO_REF_DIMENSION,
  PRO_LAYER_GTOL              = PRO_GTOL,
  PRO_LAYER_SUB_ASSEMBLY      = PRO_SUB_ASSEMBLY,
  PRO_LAYER_QUILT             = PRO_QUILT,
  PRO_LAYER_CURVE             = PRO_CURVE,
  PRO_LAYER_POINT             = PRO_POINT,
  PRO_LAYER_NOTE              = PRO_NOTE,
  PRO_LAYER_IPAR_NOTE         = PRO_IPAR_NOTE,
  PRO_LAYER_SYMBOL            = PRO_SYMBOL_INSTANCE,
  PRO_LAYER_DRAFT             = PRO_DRAFT_ENTITY,
  PRO_LAYER_DGM_OBJECT        = PRO_DIAGRAM_OBJECT,
  PRO_LAYER_DRAFT_GROUP       = PRO_DRAFT_GROUP,
  PRO_LAYER_LAYER             = PRO_LAYER,
  PRO_LAYER_DATUM_PLANE       = PRO_DATUM_PLANE,
  PRO_LAYER_DRAW_TABLE        = PRO_DRAW_TABLE,
  PRO_LAYER_DATUM_TEXT        = PRO_DATUM_TEXT, /* Supports datum plane tags. 
                                                   Use the feature id. */
  PRO_LAYER_ENTITY_TEXT       = PRO_ENTITY_TEXT,/* Supports datum entity tags 
                                                   (except for datum plane). 
                                                   Use the item id. */
  PRO_LAYER_SURF_FIN          = PRO_SURF_FIN,
  PRO_LAYER_DRAFT_DATUM       = PRO_DRAFT_DATUM,
  PRO_LAYER_SNAP_LINE         = PRO_SNAP_LINE,
  PRO_LAYER_ANNOT_ELEM        = PRO_ANNOTATION_ELEM,
  PRO_LAYER_XSEC              = PRO_XSEC,        /* Reserved for internal use */
  PRO_LAYER_SET_DATUM_TAG     = PRO_SET_DATUM_TAG,
  PRO_LAYER_SKETCH_ENTITY     = PRO_SKETCH_ENTITY,
  PRO_LAYER_SKETCH_CONSTRAINT = PRO_SKETCH_CONSTRAINT,
  PRO_LAYER_LAYOUT_TAG        = PRO_LAYOUT_TAG,   /* for internal use */
  PRO_LAYER_LAYOUT_NODE       = PRO_LAYOUT_NODE,  /* for internal use */
  PRO_LAYER_LAYOUT_WP         = PRO_LAYOUT_WP     /* for internal use */

} ProLayerType;

typedef enum default_layer_type
{
   PRO_DEFLAYER_NONE = -1,
   PRO_DEFLAYER_ASSEM_MEMBER = 0,
   PRO_DEFLAYER_COMP_DESIGN_MODEL,
   PRO_DEFLAYER_COMP_WORKPIECE,
   PRO_DEFLAYER_COMP_FIXTURE,
   PRO_DEFLAYER_GEOM_FEAT,
   PRO_DEFLAYER_NOGEOM_FEAT,
   PRO_DEFLAYER_COSM_SKETCH,
   PRO_DEFLAYER_AXIS,
   PRO_DEFLAYER_SURFACE,
   PRO_DEFLAYER_DATUM,
   PRO_DEFLAYER_POINT,
   PRO_DEFLAYER_CURVE,
   PRO_DEFLAYER_CSYS,
   PRO_DEFLAYER_FEATURE,
   PRO_DEFLAYER_HOLE_FEAT,
   PRO_DEFLAYER_ROUND_FEAT,
   PRO_DEFLAYER_CHAMFER_FEAT,
   PRO_DEFLAYER_SLOT_FEAT,
   PRO_DEFLAYER_CUT_FEAT,
   PRO_DEFLAYER_PROTRUSION_FEAT,
   PRO_DEFLAYER_RIB_FEAT,
   PRO_DEFLAYER_DRAFT_FEAT,
   PRO_DEFLAYER_SHELL_FEAT,
   PRO_DEFLAYER_CORN_CHAMF_FEAT,
   PRO_DEFLAYER_ASSY_CUT_FEAT,
   PRO_DEFLAYER_TRIM_LINE_FEAT,
   PRO_DEFLAYER_COSM_ROUND_FEAT,
   PRO_DEFLAYER_COPY_GEOM_FEAT,
   PRO_DEFLAYER_WELD,
   PRO_DEFLAYER_DIM,
   PRO_DEFLAYER_PARAMETER_DIM,
   PRO_DEFLAYER_DRIVEN_DIM,
   PRO_DEFLAYER_DRAFT_DIM,
   PRO_DEFLAYER_REFDIM,
   PRO_DEFLAYER_PART_REFDIM,
   PRO_DEFLAYER_DRAFT_REFDIM,
   PRO_DEFLAYER_CURVE_ENT,
   PRO_DEFLAYER_NOTE,
   PRO_DEFLAYER_GTOL,
   PRO_DEFLAYER_SYMBOL,
   PRO_DEFLAYER_SFIN,
   PRO_DEFLAYER_DRAFT_ENTITY,
   PRO_DEFLAYER_DRAFT_CONSTR,
   PRO_DEFLAYER_DRAFT_GEOM,
   PRO_DEFLAYER_DRAFT_HIDDEN,
   PRO_DEFLAYER_DRAFT_OTHERS,
   PRO_DEFLAYER_DRAFT_GRP,
   PRO_DEFLAYER_DRAFT_DTM,
   PRO_DEFLAYER_QUILT,
   PRO_DEFLAYER_DGM_WIRE,
   PRO_DEFLAYER_DGM_CONN_COMP,
   PRO_DEFLAYER_DGM_RAIL,
   PRO_DEFLAYER_DGM_HIGHWAY,
   PRO_DEFLAYER_DETAIL_ITEM,
   PRO_DEFLAYER_DATUM_POINT,
   PRO_DEFLAYER_DATUM_PLANE,
   PRO_DEFLAYER_SNAP_LINE,
   PRO_DEFLAYER_DWG_TABLE,
   PRO_DEFLAYER_THREAD_FEAT,
   PRO_DEFLAYER_SOLID_GEOM,
   PRO_DEFLAYER_EXT_GCPY_FEAT,
   PRO_DEFLAYER_SKELETON,
   PRO_DEFLAYER_RIBBON_FEAT,
   PRO_DEFLAYER_INTCHG_FUNCT,
   PRO_DEFLAYER_INTCHG_SIMP,
   PRO_DEFLAYER_ALL_2D_ITEMS,
   PRO_DEFLAYER_ANNOT_ELEM, 
   PRO_DEFLAYER_AXIS_ENT, 
   PRO_DEFLAYER_CSYS_ENT,     
   PRO_DEFLAYER_3D_ITEMS,
   PRO_DEFLAYER_SET_DATUM_TAG,
   PRO_DEFLAYER_HOLE_QUILT,
   PRO_DEFLAYER_AE_DRIVING_DIM,
   PRO_DEFLAYER_DRAFT_XSEC
}  ProDefLayerType;

typedef enum layer_item_owner_type
{
   PRO_LAYITEM_FROM_MODEL = 0,
   PRO_LAYITEM_FROM_PATH
}  ProLayerItemOwnerType;

typedef struct layer_item_owner
{
   ProLayerItemOwnerType    owner_type;
   union
   {
      ProMdl                layitem_model;
      ProAsmcomppath        layitem_path;
   }  owner_union;
}  ProLayerItemOwner;

typedef struct
{
  ProLayerType       type;
  int                id;
  ProLayerItemOwner  owner;
} ProLayerItem;

typedef enum
{
  PRO_LAYER_TYPE_NONE      =  -1, /* The selected layer is displayed. This is
                                     the default display status. */ 
  PRO_LAYER_TYPE_NORMAL    =   1, /* Shows the selected layer */
  PRO_LAYER_TYPE_DISPLAY   =   2, /* Isolates the selected layer */ 
  PRO_LAYER_TYPE_BLANK     =   3, /* Blanks the selected layer */
  PRO_LAYER_TYPE_HIDDEN    =   5, /* Makes the components in the hidden layers
                                     blanked. Applicable in the assembly
                                     mode only. */ 
  PRO_LAYER_TYPE_SKIP    =  6     /* Reserved for future use. */ 
} ProLayerDisplay;


/*===========================================================================*/

extern ProError ProLayerCreate (
    ProMdl owner,
    ProName layer_name,
    ProLayer* layer );

/*

  Purpose: Creates a new layer in the specified object.

  Input Arguments:
     owner      - The model in which to create the layer.
     layer_name - The name of the layer.
     layer      - The structure into which Creo Parametric will write 
                  the layer information.
     		  You must allocate the space for this structure. 

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully created the new
                             layer.
     PRO_TK_INVALID_NAME   - You specified an invalid layer name.
     PRO_TK_E_FOUND        - A layer with the specified name already
                             exists.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                             failed.

*/

extern ProError ProLayerDelete ( ProLayer* layer );

/*

  Purpose: Deletes the specified layer from the object.

  Input Arguments:
     layer - The name of the layer to delete

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully deleted the layer.
     PRO_TK_INVALID_NAME  - You specified an invalid layer name.
     PRO_TK_E_NOT_FOUND   - The system could not find a layer with the
                            specified name.   
     PRO_TK_GENERAL_ERROR - A general error occurred and the function
                            failed.

*/

extern ProError ProLayerItemsGet ( ProLayer*      layer,
                                   ProLayerItem** p_layeritem,
                                   int*           p_count);

/*
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProLayerItemsPopulate
  Purpose: This function is deprecated.Use ProLayerItemsPopulate() instead.
           Retrieves the items on the specified layer.

  Input Arguments:
     layer         - The name of the layer.

  Output Arguments:
     p_layeritem   - An array that contains the types and identifiers
                     of the items on the layer. The function 
                     allocates the memory for this argument.
                     Use ProArrayFree() to free the allocated memory.
     p_count       - The number of items on the specified layer.

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully retrieved the
                          information.
     PRO_TK_BAD_INPUTS  - The input argument is invalid.
     PRO_TK_E_NOT_FOUND - A layer with the specified name was not found.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function
                            failed.
     PRO_TK_OUT_OF_MEMORY - The layer has too many items to report.
                            p_layer_item and p_count are filled with
                            the maximum number of items.
*/

extern ProError ProLayerDisplaystatusGet ( ProLayer*        layer,
                                           ProLayerDisplay* display_status);

/*

  Purpose: Retrieves the visibility status for the specified layer.

  Input Arguments:
     layer           -  The layer whose status you want to retrieve

  Output Arguments:
     display_status  -  The display status

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully retrieved the
                           information.
     PRO_TK_BAD_INPUTS   - The input argument is invalid.
     PRO_TK_E_NOT_FOUND  - The specified layer was not found.
     PRO_TK_INVALID_NAME - You specified an invalid layer name.

*/

extern ProError ProLayerItemAdd ( ProLayer*     layer,
                                  ProLayerItem* layer_item );

/* 

  Purpose:
     Adds the specified item to a layer.

  Input Arguments:
     layer       - The layer to which to add the item
     layer_item  - The item to add 

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully added the item.
     PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                             invalid.
     PRO_TK_INVALID_NAME   - You specified an invalid layer name.
     PRO_TK_INVALID_TYPE   - You specified an invalid type in the 
                             <i>ProLayerItem</i> structure.
     PRO_TK_GENERAL_ERROR  - The specified layer was not found.
     

*/

extern ProError ProLayerItemAddNoUpdate ( ProLayer*     layer,
                                          ProLayerItem* layer_item );

/* 

  Purpose:
     Adds the specified item to a layer and does not do model tree update.

  Input Arguments:
     layer       - The layer to which to add the item
     layer_item  - The item to add 

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully added the item.
     PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                             invalid.
     PRO_TK_INVALID_NAME   - You specified an invalid layer name.
     PRO_TK_INVALID_TYPE   - You specified an invalid type in the 
                             <i>ProLayerItem</i> structure.
     PRO_TK_GENERAL_ERROR  - The specified layer was not found.
     

*/

extern ProError ProLayerItemRemove ( ProLayer* layer,
                                     ProLayerItem* layer_item );
/*
   Purpose:
      Removes the specified item from the layer.

   Input Arguments:
      layer      - The layer from which to remove the item
      layer_item - The layer item to be deleted

   Output Arguments:
      None

   Return Values:
     PRO_TK_NO_ERROR       - The function successfully removed the item.
     PRO_TK_E_NOT_FOUND    - The specified layer was not found.
     PRO_TK_INVALID_NAME   - You specified an invalid layer name.
     PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
     PRO_TK_INVALID_TYPE   - You specified an invalid layer item type.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
*/

extern ProError ProLayerItemRemoveNoUpdate ( ProLayer* layer,
                                             ProLayerItem* layer_item );
/*
   Purpose:
      Removes the specified item from the layer and does not do model tree
      update.

   Input Arguments:
      layer      - The layer from which to remove the item
      layer_item - The layer item to be deleted

   Output Arguments:
      None

   Return Values:
     PRO_TK_NO_ERROR       - The function successfully removed the item.
     PRO_TK_E_NOT_FOUND    - The specified layer was not found.
     PRO_TK_INVALID_NAME   - You specified an invalid layer name.
     PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
     PRO_TK_INVALID_TYPE   - You specified an invalid layer item type.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
*/

extern ProError ProLayerDisplaystatusSet ( 
                                            ProLayer*       layer,
                                            ProLayerDisplay display_status);

/*

  Purpose: Sets the display status of the specified layer.
<p> 
	   NOTE: 
<p>
           This is a temporary setting. It will be lost
	   after you save or retrieve a model. To change the display
	   status permanently, call the function 
           <b>ProLayerDisplaystatusSave()</b>.


  Input Arguments:
     layer          - The layer whose status you want to set
     display_status - The display status

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully set the status.
     PRO_TK_BAD_INPUTS    - Either one or more of the input arguments are
                            invalid, or <i>layer->owner</i> is NULL.
     PRO_TK_INVALID_NAME  - You specified an invalid layer name.
     PRO_TK_GENERAL_ERROR - The specified layer was not found.
     PRO_TK_CANT_MODIFY   - display status of the layer cannot be changed

  See Also:
     ProLayerDisplaystatusSave()
*/

extern ProError ProLayerDisplaystatusNoUpdateSet( 
                                 ProLayer        *layer,
                                 ProLayerDisplay display_status,
                                 ProBoolean      *is_update_tree_needed);

/*

  Purpose: Sets the layer display status but does not update the model tree.

  Input Arguments:
     layer          - The layer whose status you want to set
     display_status - The display status

  Output Arguments:
     is_update_tree_needed - Model tree should be update. 

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully set the status.
     PRO_TK_BAD_INPUTS    - One or more of the input arguments are
                            invalid
     PRO_TK_E_NOT_FOUND   - The specified layer was not found.
     PRO_TK_CANT_MODIFY   - display status of the layer cannot be changed

*/

extern ProError ProLayerDisplaystatusUpdate( ProMdl owner_model );

/*

  Purpose: Updates the model tree for the changes to the display status of
           layers.

  Input Arguments:
     owner_model - The layer owner model.

  Output Arguments:
     None.

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully update the tree.
*/

typedef ProError (*ProLayerAction)( ProLayer* layer,
				    ProAppData app_data);
/*
   Purpose:  This is the generic function for visiting and filtering 
             <i>ProLayers</i>.

   Input Arguments:
      layer     - The <i>ProLayer</i> being visited
      app_data  - The user data passed to the visit function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Call the visit function.
      PRO_TK_GENERAL_ERROR - Stop visiting.
*/


extern ProError ProMdlLayerVisit ( ProMdl model,
				   ProLayerAction visit_action,
				   ProLayerAction filter_action,
				   ProAppData app_data );

/*

  Purpose:
     Calls the specified filter and action functions for each layer in the
     model.

  Input Arguments:
     model          - The model.
     visit_action   - The action to perform on each layer. If it
                      returns anything other than PRO_TK_NO_ERROR,
                      visiting stops.
     filter_action  - The filter function. If NULL, all layers are
                      visited using the action function. 
     app_data       - The application data passed to the visiting and
                      filter functions.

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR   - The function visited all the layers.
     PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
     Other             - Any other value is the status returned by the last executed
			 callback (<i>filter_action</i> or <i>visit_action</i>).
*/

extern ProError ProMdlLayerGet( ProMdl owner,
				ProName layer_name,
				ProLayer* layer );
/*
  Purpose:
     Returns the handle of a layer, given its name and owner. 


  Input Arguments:
     owner         - The model that contains the layer
     layer_name    - The name of the layer

  Output Arguments:
     layer	   - The layer

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully retrieved the layer.
     PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
     PRO_TK_E_NOT_FOUND - The specified <i>layer_name</i> does not exist 
                          in <i>owner</i>.
*/

extern ProError ProLayerItemInit( ProLayerType    type,
                                  int             id,
				  ProMdl          owner,
				  ProLayerItem   *item );

/*
  Purpose:
     Initializes the layer item structure. You should
     use this function in all situations except one special case, which is
     covered by the function <b>ProDwgLayerItemInit()</b>.

  Input Arguments:
     type          - The item type 
     id            - The item identifier
     owner         - The model that owns the item. Cannot be NULL

  Output Arguments:
     item          - The layer item. Cannot be NULL.

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully initialized the structure.
     PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
     PRO_TK_NOT_EXIST   - Item with such identifier and type does not exist.

  See Also:
     ProDwgLayerItemInit()
*/

extern ProError ProDwgLayerItemInit( ProLayerType    type,
                                     int             id,
				     ProAsmcomppath *owner,
				     ProLayerItem   *item );

/*
  Purpose:
     Initializes a layer item structure for the singular case when 
     all of the following are true:

<ul> 
     <li>The layer owner is a drawing.
     <li>The layer item owner is an assembly.
     <li>The layer item is a component.
     <li>You want to control the display status of this component
         only in a subassembly specified by the given path (<i>owner</i>).
</ul>
<p>
     In all other situations, use the function <b>ProLayerItemInit()</b>.


  Input Arguments:
     type          - The item type.
     id            - The item identifier.
     owner         - The owner of the item. You 
		     can have <i>table_num</i> greater than 0 for type 
                     PRO_LAYER_SUB_ASSEMBLY only.

  Output Arguments:
     item          - The layer item.

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully initialized the structure.
     PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.

  See Also:
     ProLayerItemInit()
*/

extern ProError ProLayerDisplaystatusSave( ProMdl owner );

/*
  Purpose:
     Permanently saves all the changes to the display status of all layers
     in the owner, and all its submodels (and views, for drawings).

  Input Arguments:
     owner         - The model/layer owner

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully saved all the layer status
                          changes.
     PRO_TK_NO_CHANGE   - No layers have been changed since the last save.
     PRO_TK_BAD_INPUTS  - Wrong argument. A model cannot have layers.
*/

extern ProError ProDwgLayerDisplaystatusGet( ProLayer        *layer,
					     ProView          view,
                                             ProLayerDisplay *display_status );

/*

  Purpose: Retrieves the visibility status for the specified layer and view.

  Input Arguments:
     layer           -  The layer whose status you want to retrieve
     view            -  The view of drawing whose layer display status
			is requested

  Output Arguments:
     display_status  -  The display status

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully retrieved the
                           information.
     PRO_TK_BAD_INPUTS   - The input argument is invalid.
     PRO_TK_E_NOT_FOUND  - The specified layer was not found.

*/

extern ProError ProDwgLayerDisplaystatusSet( ProLayer        *layer,
					     ProView          view,
                                             ProLayerDisplay  display_status );

/*

  Purpose: Sets the display status of the specified layer and view. 

  Input Arguments:
     layer          - The layer whose status you want to set
     view           - The view in which you want to set the layer status 
     display_status - The display status

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully set the status.
     PRO_TK_BAD_INPUTS    - One or more of the input arguments are
                            invalid
     PRO_TK_E_NOT_FOUND   - The specified layer was not found.
     PRO_TK_CANT_MODIFY   - display status of the layer cannot be changed

*/

extern ProError ProLayerViewDependencySet( ProView          view,
					   ProBoolean       depend );

/*

  Purpose: Sets the display status of the view to either
	   follow the display status in the drawing, or 
	   be independent from the drawing.

  Input Arguments:
     view           - The view whose display status you want to set.
     depend         - If this is PRO_B_TRUE, the view display status 
                      should follow the 
                      display status in the
                      drawing. If this is PRO_B_FALSE, the view 
                      display status should be 
                      independent from the drawing.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully set the dependency.
     PRO_TK_BAD_INPUTS    - You specified an invalid view.

*/

extern ProError ProLayerViewDependencyGet( ProView          view,
					   ProBoolean      *depend );

/*

  Purpose: Returns the dependency of the view layer display from the drawing
	   layer display.

  Input Arguments:
     view           - The view whose display status you want. 
 
  Output Arguments:
     depend         - If this is PRO_B_TRUE, the view display follows 
                      the drawing display. 
		      If this is PRO_B_FALSE, the view display is independent.

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully returned the dependency.
     PRO_TK_BAD_INPUTS    - You specified an invalid view.

*/

extern ProError ProLayerDefLayerSet( ProDefLayerType  def_layer_type,
				     ProName          def_layer_name );

/*

  Purpose: Sets up a default layer of the specified type.
          <b>Note:</b> This function is equivalent to setting the default layer
           name for the session using the configuration option <i>"def_layer"</i>. 
           This does not save the status to a particular model. The default layer
           status does not remain on a layer if it is renamed.
 
  Input Arguments:
     def_layer_type   - The type of default layer to set up.
     def_layer_name   - The name of the default layer to set up. If this is
                        an empty name, the function unsets the default layer.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully set up the default layer.
     PRO_TK_INVALID_NAME  - def_layer_name contains invalid characters.
     PRO_TK_BAD_INPUTS    - def_layer_type is invalid.

*/

extern ProError ProLayerDefLayerGet( ProDefLayerType  def_layer_type,
				     ProName          def_layer_name );

/*

  Purpose: Retrieves the name of the default layer of the specified type.

  Input Arguments:
     def_layer_type        - The type of default layer.

  Output Arguments:
     def_layer_name        - The name of the default layer. This argument is
			     empty if a default layer is not set.

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.

*/

extern ProError ProLayeritemStatusGet( ProLayerItem  *pro_layer_item,
				       ProView        pro_view, 
				       ProBoolean    *p_item_visible );

/*

  Purpose: Returns the visibility status for the specified item.

  Input Arguments:
     pro_layer_item    - The layer item which visibility is evaluated.
     pro_view          - The drawing view in which visibility of the item 
			 is evaluated.
			 NULL in 3d modes.

  Output Arguments:
     p_item_visible    - Visibility status of the item.

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved the
                         information.
     PRO_TK_BAD_INPUTS - The input argument is invalid.

*/

extern ProError ProLayeritemLayersGet( ProDrawing     pro_drawing,
				       ProLayerItem  *pro_layer_item,
				       ProLayer     **pro_layers );
/*

  Purpose: Finds all layers containing the given item.

  Input Arguments:
     pro_drawing       - The drawing that owns the layers where the item 
	                     resides. If NULL, layers residing in the same model 
                         as the given layer item will be found.
     pro_layer_item    - The layer item.  If the type is PRO_LAYITEM_FROM_PATH,
			             you must supply the pro_drawing argument.

  Output Arguments:
     pro_layers        - ProArray of layers which contain the item.  Free this
                         array using ProArrayFree().

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved the
                         information.
     PRO_TK_E_NOT_FOUND - The item is not found on any layers in the 
	                      designated model.
     PRO_TK_BAD_INPUTS - The input argument is invalid.

*/

extern ProError ProModelitemIsHidden ( ProModelitem  *item, 
                                       ProBoolean    *is_hidden);
/*
  Purpose: Identifies if the item is hidden via the "Hide" menu choice in
           Creo Parametric or the related function ProModelitemHide().


  Input Arguments:
     item      - The item.
  
  Output Arguments:
     is_hidden - PRO_B_TRUE if the item is hidden, PRO_B_FALSE otherwise.
  
  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
     PRO_TK_INVALID_TYPE  - The item is not permitted to be shown or hidden.

*/

extern ProError ProModelitemHide (ProModelitem* item);
/*
  Purpose: Hides the item, similar to the Creo Parametric menu choice "Hide".

  Input Arguments:
     item                 - The layer item.

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
     PRO_TK_NO_CHANGE     - The item was already hidden.
     PRO_TK_INVALID_TYPE  - The item is not permitted to be hidden.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.

*/

extern ProError ProModelitemUnhide (ProModelitem* item);
/*
  Purpose: Unhides the item, similar to the Creo Parametric menu choice
           "Unhide".

  Input Arguments:
     item                 - The layer item.
  
  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
     PRO_TK_NO_CHANGE     - The item was already shown.
     PRO_TK_INVALID_TYPE  - The item is not permitted to be shown or hidden.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.

*/

extern ProError ProMdlLayersCollect (ProMdl mdl, ProLayer** p_layers_array);
/*
  Purpose: Collects an array containing the layers in this model.

  Input Arguments:
     mdl - The model.

  Output Arguments:
     p_layers_array - ProArray of collected layers. Free this using
     ProArrayFree().

  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
     PRO_TK_E_NOT_FOUND - No layers were found and collected.

*/

extern ProError ProLayerItemsPopulate ( ProLayer      *layer,
                                        ProLayerItem **p_layeritem,
                                        int*           p_count);
/*

  Purpose: Retrieves the items on the specified layer.

  Input Arguments:
     layer         - The name of the layer.

  Output Arguments:
     p_layeritem   - An array that contains the types and identifiers
                     of the items on the layer. The function 
                     allocates the memory for this argument.
                     Use ProLayeritemarrayFree() to free the allocated memory.
     p_count       - The number of items on the specified layer.

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully retrieved the
                          information.
     PRO_TK_BAD_INPUTS  - The input argument is invalid.
     PRO_TK_E_NOT_FOUND - A layer with the specified name was not found.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function
                            failed.
     PRO_TK_OUT_OF_MEMORY - The layer has too many items to report.
                            p_layer_item return NULL and p_count
                            return 0.
*/

extern ProError ProLayeritemarrayFree (ProLayerItem **array);
/*
   Purpose:   Frees an array of ProLayerItem returned from 
              ProLayerItemsPopulate().

   Input Arguments:
      array   - The address of the array to be freed

   Output Arguments:
      None

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully freed the array.
   
*/

extern ProError ProLayerRuleExecute(ProMdl CurrentModel);
/*
   Purpose:   Execute the layer rules on the CurrentModel if rules are enabled.

   Input Arguments:
      CurrentModel - The model upon which the layer rules will be executed.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully excuted the rules.
      PRO_TK_BAD_INPUTS    - CurrentModel is NULL.
      PRO_TK_INVALID_PTR   - CurrentModel is not a handle to a model.
      PRO_TK_GENERAL_ERROR - Execution of all the rules failed.
   
*/

extern ProError ProLayerRuleCopy(ProMdl CurrentModel, ProName LayerName, ProMdl ReferenceModel);
/*
   Purpose:   Copy the rules of a layer LayerName in ReferenceModel into
              a layer LayerName in CurrentModel, overwriting any rules
	
	<p><b>Note: </b>This function copies both the rules definitions 
	and the rules options set interactively (including option "Associative")


   Input Arguments:
      CurrentModel   - The model into which the layer rule will be copied.
      LayerName      - The name of an existing layer in both models.
      ReferenceModel - The model from which the layer rules will be copied.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully copied the rules.
      PRO_TK_BAD_INPUTS    - CurrentModel or ReferenceModel is NULL.
      PRO_TK_INVALID_PTR   - CurrentModel or ReferenceModel is not a handle to a model.
      PRO_TK_NOT_EXIST     - Layer LayerName does not exist in one or both models.
   
*/

extern ProError ProLayerRuleMatch(ProMdl CurrentModel, ProName LayerName,
                                  ProMdl ReferenceModel, ProBoolean* p_match);
/*
   Purpose:   Compare the rules of a layer LayerName in ReferenceModel to
              the rules in layer LayerName in CurrentModel.

   Input Arguments:
      CurrentModel   - The current model for comparison.
      LayerName      - The name of an existing layer in both models.
      ReferenceModel - The reference model for comparison.

   Output Arguments:
      p_match - The result of the comparison. PRO_B_TRUE if a match, otherwise
                PRO_B_FALSE. Must not be NULL.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully compared the rules.
      PRO_TK_BAD_INPUTS    - CurrentModel, ReferenceModel or p_match is NULL.
      PRO_TK_INVALID_PTR   - CurrentModel or ReferenceModel is not a handle to a model.
      PRO_TK_NOT_EXIST     - Layer LayerName does not exist in one or both models.
   
*/

PRO_END_C_DECLS

#endif   /* PROLAYER_H */
