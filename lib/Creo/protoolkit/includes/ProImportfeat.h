#ifndef PROIMPORTFEAT_H
#define PROIMPORTFEAT_H

#include   <ProObjects.h>
#include   <ProIntfData.h>



PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef struct pro_import_feat_attr
 {
	unsigned int	join_surfaces:1,
			attempt_make_solid:1, /* Make solids from every closed quilt  */
			cut_or_add:1;         /* Operation to apply when making solid */
                                              /* NOTE: set to 1 for cut; set to 0 for add */
 } ProImportfeatAttr;

typedef struct	pro_import_feat_data
 {
        ProIntfType             intf_type;
        ProPath                 filename;
        ProCsys                 csys;
        ProImportfeatAttr       attr;
 } ProImportfeatData;

typedef enum	pro_import_feat_redef_oper
 {
	PRO_IMPORT_FEAT_REDEF_CHANGE_ATTR,
	PRO_IMPORT_FEAT_REDEF_SUBSTITUTE
 } ProImportfeatRedefOper;

typedef enum	pro_import_feat_redef_source_type
 {
	PRO_IMPORT_FEAT_REDEF_DATA_SOURCE_NONE = 0,
	PRO_IMPORT_FEAT_REDEF_DATA_SOURCE_ATTR,
	PRO_IMPORT_FEAT_REDEF_DATA_SOURCE_NEW
 } ProImportfeatRedefSourceType;

typedef struct pro_import_feat_redef_source
 {
	ProImportfeatRedefOper	operation;
	union
	 {
		ProImportfeatAttr attr;		/* PRO_IMPORT_FEAT_REDEF_CHANGE_ATTR */
		ProIntfDataSource new_data;	/* PRO_IMPORT_FEAT_REDEF_SUBSTITUTE */
	 } choice;
 } ProImportfeatRedefSource;

typedef	struct pro_import_feat_id_map
 {
	int	item_id;
	ProType	item_type;
	int	user_id;
 } ProImportfeatIdMap;

/* MAIN FUNCTION TO CREATE NEW IMPORT FEATURE */

LIB_PTK_INTF_API  ProError ProImportfeatCreate( ProSolid		p_solid,
				     ProIntfDataSource	*data_source,
				     ProCsys		p_csys,
				     ProImportfeatAttr	*p_attributes,
				     ProFeature		*p_feat_handle );
/*
   Purpose:  Creates a new import feature in the solid.

   Input Arguments:
      p_solid		- The pointer to the solid (part). Assembly case is not supported.
      data_source	- The source of data from which to create
			  the import feature.
      p_csys		- The pointer to a reference coordinate system.
			  If this is NULL, the function uses the
                          default coordinate system. 
      p_attributes	- The attributes for creation of the new
			  import feature. If this pointer is NULL, the function
			  uses the default attributes.

   Output Arguments:
      p_feat_handle	- The handle to the new import feature.

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully created
			  the new import feature.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_NO_LICENSE - License check failure.
      PRO_TK_INVALID_FILE - The model file doesn't have correct format.
      PRO_TK_UNSUPPORTED- Creo Parametric does not support import of the indicated file.
*/

/* MAIN FUNCTION TO CREATE NEW IMPORT FEATURE CONTAINING DATUM CURVES */

extern ProError ProDatumcurveFromfileCreate ( ProSolid       p_solid,
                                              ProPath	     full_file_name,
                                              ProIntfType    file_type,
                                              ProCsys        p_csys,
                                              ProFeature     *p_feat_handle);
/*     
   Purpose:  Creates a new import feature in the solid to contain a datum curve.
       
   Input Arguments:
     p_solid            - The pointer to the solid.
     full_file_name     - The file name from which to create the import feature.
     file_type          - The file type
     p_csys             - The pointer to a reference coordinate system.
                          If this is NULL, the function uses the
                          default coordinate system.
   Output Arguments:
      p_feat_handle     - The handle to the new import feature.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created
                           the new import feature.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NO_LICENSE - License check failure.
      PRO_TK_INVALID_FILE - The curve file doesn't have correct format.
      PRO_TK_UNSUPPORTED- Creo Parametric does not support import of the indicated file.
*/

/* MAIN FUNCTION TO CREATE NEW IMPORT FEATURE WITH PROFILE */

extern ProError ProImportfeatWithProfileCreate( ProSolid		p_solid,
				                ProIntfDataSource	*data_source,
				                ProCsys			p_csys,
				                ProPath			profile,
                                                ProBoolean              cut_or_add, 
				                ProFeature		*p_feat_handle );
/*
   Purpose:  Creates a new import feature in the solid using profile.
   	<p><b>Note:</b>
	 Once a profile is set, it remains valid for the entire session unless it is reset with another profile.

   Input Arguments:
      p_solid		- The pointer to the solid (part). Assembly case is not supported.
      data_source	- The source of data from which to create
			  the import feature.
      p_csys		- The pointer to a reference coordinate system.
			  If this is NULL, the function uses the
                          default coordinate system. 
      profile		- Profile path. Can be NULL, in which case it works
                          identically with ProImportfeatCreate
      cut_or_add        - Set to PRO_B_TRUE for imported geometry representing a cut or
                          PRO_B_FALSE otherwise.

   Output Arguments:
      p_feat_handle	- The handle to the new import feature.
                          If this is NULL the feature will be created anyway.

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully created
			    the new import feature.
      PRO_TK_BAD_INPUTS	  - One or more of the input arguments are invalid.
      PRO_TK_UNSUPPORTED  - Creo Parametric does not support import 
                            of the indicated file.
      PRO_TK_NOT_EXIST    - No profile found.
      PRO_TK_INVALID_FILE - profile is not readable.
      PRO_TK_NO_LICENSE   - Missing the required license to perform this import
                            feature operation.
*/

extern ProError ProImportfeatDataGet( ProFeature	*p_feat_handle,
				      ProImportfeatData *p_import_feat_data );
/*
   Purpose:  Retrieves the current parameters of the specified import feature.

   Input Arguments:
      p_feat_handle	- The handle for the import feature

   Output Arguments:
      p_import_feat_data - The current parameters 

   Return Values:
      PRO_TK_NO_ERROR       - The function successfully retrieved the information. 
      PRO_TK_GENERAL_ERROR  - A problem occurred during retrieval.
      PRO_TK_BAD_INPUTS	    - The input argument is invalid.
*/

/* MAIN FUNCTION TO REDEFINE EXISTING IMPORT FEATURE */

extern ProError ProImportfeatRedefine( ProFeature		*p_feat_handle,
				       ProImportfeatRedefSource	*p_source );
/*
   Purpose:	Redefines an existing import feature from the data source.

   Input Arguments:
      p_feat_handle	- The handle for the import feature to be redefined
      p_source		- The pointer to the data source to be used for the
                          redefinition. Refer to the note about unsupported 
                          attributes for this operation in the description of the
                          function ProImportfeatRedefSourceInit().

   Output Arguments:
      none 

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully redefined the import
			  feature.
      PRO_TK_BAD_INPUTS	- One or more of the input arguments are invalid.
      PRO_TK_NOT_IMPLEMENTED - Not implemented.
      PRO_TK_BAD_CONTEXT   - no redefine could be done for ATB feature.
      PRO_TK_GENERAL_ERROR - The function could not regenerate the import
			     feature.
*/

LIB_PTK_INTF_API  ProError ProImportfeatRedefSourceInit( ProImportfeatRedefOper	operation,
					      void			*p_source,
					      ProImportfeatRedefSource	*p_redef_data_source );
/*
   Purpose:	Initializes the <I>ProImportfeatRedefSource</I>. <p><b>Note:</b>
                When the source type is PRO_IMPORT_FEAT_REDEF_CHANGE_ATTR, 
                Creo Parametric will not use the value of the attribute 
                "join_surfaces".

   Input Arguments:
      operation		- The type of operation
      p_source		- The pointer to the data source

   Output Arguments:
      p_redef_data_source	- The pointer to the
				  <I>ProImportfeatRedefSource</I> 
				  to be initialized

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized the
			  <I>ProImportfeatRedefSource</I>.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProImportfeatRedefSourceType ProImportfeatRedefSourceTypeGet( ProImportfeatRedefOper operation );
/*
   Purpose:	Determines the type of <I>ProImportfeatRedefSource</I>
		used to redefine an import feature, depending on
		the type of operation. This is an auxiliary function
		that helps you determine what kind of data source
		the function <B>ProImportfeatRedefine()</B> expects you to pass
		in the argument <I>p_source</I>.

   Input Arguments:

      operation            - The type of operation

   Output Arguments:

      None

   Return Values:
      ProImportfeatRedefSourceType	- The type of
					  <I>ProImportfeatRedefSource</I>

   See Also:

      ProImportfeatRedefine()
*/

LIB_PTK_INTF_API  ProError ProImportfeatIdArrayCreate ( ProFeature	*p_feat_handle,
					     ProImportfeatIdMap **pp_id_map_arr );
/*
   Purpose:	Gets an array of maps between the <I>item_id</I> and <I>user_id</I>.

   Input Arguments:
      p_feat_handle	- The handle of the import feature.

   Output Arguments:
      pp_id_map_arr	- An array of maps between <I>item_id</I> and <I>user_id</I>.
			  To access individual maps, use the function
			  <B>ProImportfeatIdArrayMapGet()</B>.
   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully got the array of maps.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - The input argument is invalid.

   See Also:

      ProImportfeatIdArrayMapGet()
*/

LIB_PTK_INTF_API  ProError ProImportfeatIdArrayMapCount ( ProImportfeatIdMap	*p_id_map_arr,
					       int			*n_maps );
/*
   Purpose:  Determines the number of maps between the <I>item_id</I> and <I>user_id</I>.

   Input Arguments:
      p_id_map_arr	- The array of maps between the <I>item_id</I> and <I>user_id</I>

   Output Arguments:
      n_maps		- The number of maps between the <I>item_id</I> and <I>user_id</I>

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully evaluated the number of maps.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProImportfeatIdArrayMapGet( ProImportfeatIdMap *p_id_map_arr, 
					    int index,
					    ProImportfeatIdMap *p_id_map );
/*
   Purpose: Gets the map with the specified index from the array of maps 
            between the <I>item_id</I> and <I>user_id</I>.
   
   Input Arguments:
      p_id_map_arr	- The array of maps between the <I>item_id</I> and <I>user_id</I>
      index		- The index (from 0 to (<I>number</I> - 1)) of the map in the 
                          array of maps

   Output Arguments:
      p_id_map		- The map

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully found the map.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProImportfeatIdArrayFree ( ProImportfeatIdMap *p_id_map_arr );
/*
   Purpose:     Frees the array of maps between the <I>item_id</I> and <I>user_id</I>.
   
   Input Arguments:
      p_id_map_arr	- The array of maps between the <I>item_id</I> and <I>user_id</I>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the array of maps.
*/

LIB_PTK_INTF_API  ProError ProImportfeatItemIdToUserId ( ProFeature	*p_feat_handle,
					      int		item_id,
					      ProType		item_type,
					      int		**user_id_pro_array );
/*
   Purpose:     Converts an <I>item_id</I> to a <I>user_id</I>.
   
   Input Arguments:
      p_feat_handle	- The handle of the import feature
      item_id		- The identifier of the geometry item
      item_type		- The type of geometry item (PRO_SURFACE, PRO_EDGE or PRO_QUILT)

   Output Arguments:
      user_id_pro_array	- The <I>ProArray</I> of user identifiers

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully converted the <I>item_id</I> to a
                            <I>user_id</I>.
      PRO_TK_E_NOT_FOUND  - The user identifiers was not found.
      PRO_TK_INVALID_TYPE - You specified an invalid type of geometry item.
      PRO_TK_BAD_INPUTS	  - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProImportfeatUserIdToItemId ( ProFeature	*p_feat_handle,
					      int		user_id,
					      ProType		item_type,
					      int		**item_id_pro_array );
/*   
   Purpose:  Converts a <I>user_id</I> to an <I>item_id</I>.
 
   Input Arguments:
      p_feat_handle	- The handle of the import feature
      user_id		- The user identifier
      item_type		- The type of geometry item (PRO_SURFACE, PRO_EDGE or PRO_QUILT)

   Output Arguments:
      item_id_pro_array	- The <I>ProArray</I> of identifiers of geometry items. 
                          You must preallocate this array using
                          the function <b>ProArrayAlloc()</b>.

   Return Values:
      PRO_TK_NO_ERROR	  - The function successfully converted the <I>user_id</I> to 
                            an <I>item_id</I>.
      PRO_TK_E_NOT_FOUND  - The identifiers of the geometry items were not found.
      PRO_TK_INVALID_TYPE - You specified an invalid type of geometry item.
      PRO_TK_BAD_INPUTS	  - One or more of the input arguments are invalid.
*/

PRO_END_C_DECLS

#endif /* PROIMPORTFEAT_H */
