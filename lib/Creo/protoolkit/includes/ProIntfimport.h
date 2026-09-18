#ifndef PROINTFIMPORT_DOT_H
#define PROINTFIMPORT_DOT_H

#include <ProToolkit.h>
#include <ProMdl.h>
#include <ProLayer.h>



PRO_BEGIN_C_DECLS
 
typedef enum
 {
        PRO_INTF_IMPORT_NONE = 0,
        PRO_INTF_IMPORT_IGES,
        PRO_INTF_IMPORT_SET,        /* This type is obsolete.   */
        PRO_INTF_IMPORT_VDA,
        PRO_INTF_IMPORT_NEUTRAL,
        PRO_INTF_IMPORT_CADDS,
        PRO_INTF_IMPORT_STEP,
        PRO_INTF_IMPORT_STL,
        PRO_INTF_IMPORT_VRML,
        PRO_INTF_IMPORT_POLTXT,
        PRO_INTF_IMPORT_CATIA,          /* This type is obsolete.   */
        PRO_INTF_IMPORT_CATIA_SESSION,
        PRO_INTF_IMPORT_CATIA_MODEL,
        PRO_INTF_IMPORT_DXF,
        PRO_INTF_IMPORT_ACIS,
        PRO_INTF_IMPORT_PARASOLID,
        PRO_INTF_IMPORT_ICEM,
        PRO_INTF_IMPORT_DESKTOP,        /* This type is obsolete.   */
        PRO_INTF_IMPORT_PDGS,           /* This type is obsolete.   */
        PRO_INTF_IMPORT_CATIA_PART,
        PRO_INTF_IMPORT_CATIA_PRODUCT, 
        PRO_INTF_IMPORT_UG,
        PRO_INTF_IMPORT_IDEAS_DESIGN,   /* This type is obsolete.   */
        PRO_INTF_IMPORT_IDEAS_PACKAGE,  /* This type is obsolete.   */
        PRO_INTF_IMPORT_PRODUCTVIEW,
        PRO_INTF_IMPORT_CATIA_CGR,
        PRO_INTF_IMPORT_JT,
        PRO_INTF_IMPORT_SW_PART,
        PRO_INTF_IMPORT_SW_ASSEM,
        PRO_INTF_IMPORT_INVENTOR_PART,
        PRO_INTF_IMPORT_INVENTOR_ASSEM,
        PRO_INTF_IMPORT_CC,
        PRO_INTF_IMPORT_SEDGE_PART,
        PRO_INTF_IMPORT_SEDGE_ASSEMBLY,
        PRO_INTF_IMPORT_SEDGE_SHEETMETAL_PART,
        PRO_INTF_IMPORT_AMF /* reserved for future use */
 } ProIntfImportType;

typedef enum
 {
        PRO_IMPORTREP_UNDEFINED       = PRO_VALUE_UNUSED,
        PRO_IMPORTREP_MASTER          = 0,    /* Master representation   */
        PRO_IMPORTREP_STRUCTURE       = 1,    /* Model structure         */
        PRO_IMPORTREP_GRAPHICS        = 2     /* Lightweight graphic rep */
 } ProImportRepType;

typedef void*  ProLayerfilterdata;

typedef ProError (*ProIntfimportLayerFilter) ( ProLayerfilterdata data, 
                                               ProAppData  application_data);
/*
   Purpose:  Filter function allowing the application to decide on the status
             of imported layers.

   Input Arguments:
        data            -  The imported layer information. 
        application_data - The user-supplied application data 
                           for layer filtering.
   Output Arguments:
        none

   Return Values:
        PRO_TK_NO_ERROR   - Continue the filtering action
        PRO_TK_USER_ABORT - Stop filtering, using the designated action returned
                            here for all remaining layers.
*/

extern ProError ProIntfimportSourceTypeGet ( ProPath import_file,
                                             ProIntfImportType type,
                                             ProMdlType *mdl_type );
/*
   Purpose:  Determines the type of model expected to be created by the
             import operation.

   Input Arguments:
        import_file     - Full path to file to be imported.
        type            - The type of file to be imported.

   Output Arguments:
        mdl_type        - The type of model that can be created from this import
                          file.
   Return Values:
        PRO_TK_NO_ERROR     - The function successfully returned the information
        PRO_TK_INVALID_TYPE - This function is not supported for this import
                              type.
*/

extern ProError  ProIntfimportModelCreate( ProPath  import_file, 
                                           ProIntfImportType type, 
                                           ProMdlType create_type,
                                           ProName  new_model_name, 
                                           ProIntfimportLayerFilter filter_func,
                                           ProAppData application_data,
                                           ProMdl* created_model);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProIntfimportModelWithOptionsMdlnameCreate
   Purpose:  Imports an external file, creating new models or a set of new
             models as required.
             <p><B>Note:</B>This function is deprecated. 
             Use ProIntfimportModelWithOptionsMdlnameCreate instead, with NULL profile
             and PRO_IMPORTREP_MASTER as the representation type.

   Input Arguments:
        import_file     - Full path to the file to be imported.
                   <b>Note</b>: When importing CADDS models, ensure that
                          the path is specified in lower case.
        type            - The type of file to be imported. 
        create_type     - The type of model to create.  This could be part,
                          assembly, or drawing (for STEP associative drawings).
        new_model_name  - The name of the new top level import model.
        filter_func     - Callback to a function that determines how to display
                          and map layers from the imported model. If this is
                          NULL, the default layer handling will take place.
        application_data - The application data to be passed to the
                           filter function. Can be NULL.

   Output Arguments:
        created_model   - Handle to the top level created model. This could be
                          a part, assembly, or drawing.
   Return Values:
        PRO_TK_NO_ERROR   - The import was successful.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_OPEN  - import_file can't be opened.
        PRO_TK_INVALID_FILE - The model file doesn't have correct format.
        PRO_TK_NO_LICENSE - Missing the required license to perform this import
                            operation.
        PRO_TK_UNSUPPORTED- Creo Parametric does not support import of the indicated file.
        PRO_TK_INVALID_TYPE - This combination of arguments is invalid.
        
*/

extern ProError  ProIntfimportModelWithProfileCreate( ProPath  import_file,
                                                      ProPath  profile,
                                                      ProIntfImportType type, 
                                                      ProMdlType create_type,
                                                      ProName  new_model_name, 
                                                      ProIntfimportLayerFilter filter_func,
                                                      ProAppData application_data,
                                                      ProMdl* created_model);
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProIntfimportModelWithOptionsMdlnameCreate
   Purpose:  Imports an external file using profile, creating a new model 
             or a set of new models as required.
             <p><B>Note:</B>This function is deprecated. 
             Use ProIntfimportModelWithOptionsMdlnameCreate instead, with
             PRO_IMPORTREP_MASTER as the representation type.

   Input Arguments:
        import_file     - Full path to the file to be imported.
                   <b>Note</b>: When importing CADDS models, ensure that
                          the path is specified in lower case.
        profile         - profile path. May be NULL.
        type            - The type of file to be imported. 
        create_type     - The type of model to create.  This could be part,
                          assembly, or drawing (for STEP associative drawings).
        new_model_name  - The name of the new top level import model.
        filter_func     - Callback to a function that determines how to display
                          and map layers from the imported model. If this is
                          NULL, the default layer handling will take place.
        application_data - The application data to be passed to the
                           filter function. Can be NULL.

   Output Arguments:
        created_model   - Handle to the top level created model. This could be
                          a part, assembly, or drawing.
                          If this is NULL the model will be created anyway.
   Return Values:
        PRO_TK_NO_ERROR         - The function successfully created
                                  the new import feature.
        PRO_TK_BAD_INPUTS       - One or more of the input arguments are invalid.
        PRO_TK_CANT_OPEN        - import_file can't be opened.
        PRO_TK_UNSUPPORTED      - Creo Parametric does not support import 
                                  of the indicated file.
        PRO_TK_NOT_EXIST        - No profile found.
        PRO_TK_INVALID_FILE     - profile is not readable.
        PRO_TK_INVALID_TYPE     - This combination of arguments is invalid.
        PRO_TK_NO_LICENSE       - Missing the required license to perform this 
                                  import operation.
*/

extern ProError  ProIntfimportModelWithOptionsCreate (ProPath  import_file, 
                                                      ProPath  profile, 
                                                      ProIntfImportType type, 
                                                      ProMdlType create_type, 
                                                      ProImportRepType rep_type, 
                                                      ProName  new_model_name, 
                                                      ProIntfimportLayerFilter filter_func, 
                                                      ProAppData application_data, 
                                                      ProMdl* created_model);
/* 
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProIntfimportModelWithOptionsMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProIntfimportModelWithOptionsMdlnameCreate instead.

             Imports an external file using profile, creating a new model, 
             or a set of new models as required, with a representation as required. 
        <p><b>Note:</b>
         Once a profile is set, it remains valid for the entire session unless it is reset with another profile.

   Input Arguments: 
        import_file     - Full path to the file to be imported. 
                          <b>Note</b>: When importing CADDS models, ensure that 
                          the path is specified in lower case. 
        profile         - Profile path. May be NULL. 
        type            - The type of file to be imported. 
        create_type     - The type of model to create.  This could be part, 
                          assembly, or drawing (for STEP associative drawings). 
        rep_type        - The representation type. Use PRO_IMPORTREP_MASTER
                          to import without special representations applied.
        new_model_name  - The name of the new top level import model. 
                          new_model_name length should be less than 32 chars.
        filter_func     - Callback to a function that determines how to display 
                          and map layers from the imported model. If this is 
                          NULL, the default layer handling will take place. 
        application_data - The application data to be passed to the 
                           filter function. Can be NULL. 
   Output Arguments: 
        created_model   - The handle to the created model. For an 
                          assembly, the handle to the top assembly.
                          If this is NULL the model will be created anyway. 
   Return Values: 
        PRO_TK_NO_ERROR         - The function successfully created 
                                  the new import feature. 
        PRO_TK_BAD_INPUTS       - One or more of the input arguments are invalid. 
        PRO_TK_CANT_OPEN        - import_file can't be opened. 
        PRO_TK_UNSUPPORTED      - Creo Parametric does not support import 
                                  of the indicated file. 
        PRO_TK_NOT_EXIST        - No profile found. 
        PRO_TK_INVALID_FILE     - profile is not readable. 
        PRO_TK_INVALID_TYPE     - This combination of arguments is invalid.
        PRO_TK_NO_LICENSE       - Missing the required license to perform this import
                                  operation.
*/ 

extern ProError  ProIntfimportModelWithOptionsMdlnameCreate (
                                             ProPath  import_file, 
                                             ProPath  profile, 
                                             ProIntfImportType type, 
                                             ProMdlType create_type, 
                                             ProImportRepType rep_type, 
                                             ProMdlName new_model_name, 
                                             ProIntfimportLayerFilter filter_func, 
                                             ProAppData application_data, 
                                             ProMdl* created_model);
/* 
   Purpose:  Imports an external file using profile, creating a new model, 
             or a set of new models as required, with a representation as required. 
        <p><b>Note:</b>
         Once a profile is set, it remains valid for the entire session unless it is reset with another profile.
		
		<b>Note: </b> In Creo 3 this function does not differ in behavior from 
		superseded ProIntfimportModelWithOptionsCreate. In particular,
		new_model_name can be only of ProName length. This function is reserved for future use.

   Input Arguments: 
        import_file     - Full path to the file to be imported. 
                          <b>Note</b>: When importing CADDS models, ensure that 
                          the path is specified in lower case. 
        profile         - Profile path. May be NULL. 
        type            - The type of file to be imported. 
        create_type     - The type of model to create.  This could be part, 
                          assembly, or drawing (for STEP associative drawings). 
                          Pass PRO_MDL_UNUSED to let Creo Parametric decide on 
                          the model type to be created.
        rep_type        - The representation type. Use PRO_IMPORTREP_MASTER
                          to import without special representations applied.
        new_model_name  - The name of the new top level import model. 
        filter_func     - Callback to a function that determines how to display 
                          and map layers from the imported model. If this is 
                          NULL, the default layer handling will take place. 
        application_data - The application data to be passed to the 
                           filter function. Can be NULL. 
   Output Arguments: 
        created_model   - The handle to the created model. For an 
                          assembly, the handle to the top assembly.
                          If this is NULL the model will be created anyway. 
   Return Values: 
        PRO_TK_NO_ERROR         - The function successfully created 
                                  the new import feature. 
        PRO_TK_BAD_INPUTS       - One or more of the input arguments are invalid. 
        PRO_TK_CANT_OPEN        - import_file can't be opened. 
        PRO_TK_UNSUPPORTED      - Creo Parametric does not support import 
                                  of the indicated file. 
        PRO_TK_NOT_EXIST        - No profile found. 
        PRO_TK_INVALID_FILE     - profile is not readable. 
        PRO_TK_INVALID_TYPE     - This combination of arguments is invalid.
		PRO_TK_LINE_TOO_LONG    - Name length of new model is more than 31 chars.
        PRO_TK_NO_LICENSE       - Missing the required license to perform this import
                                  operation.
*/ 


extern ProError  ProLayerfilterdataNameGet ( ProLayerfilterdata data,
                                             ProLine layer_name );
/* 
   Purpose:  Gets the layer name from a ProLayerfilterdata object passed to the
             ProIntfimportLayerFilter action.

   Input Arguments:
        data            - The imported layer information.

   Output Arguments:
        layer_name      - The layer name or number from the import file. 

   Return Values:
        PRO_TK_NO_ERROR   - The function successfully retrieved the information.
        PRO_TK_BAD_INPUTS - The function arguments were invalid.
*/

extern ProError   ProLayerfilterdataCountsGet ( ProLayerfilterdata data, 
                                                int* curve_count,
                                                int* surface_count,
                                                int* trimmed_surface_count );

/* 
   Purpose:  Gets the counts from a ProLayerfilterdata object passed to the
             ProIntfimportLayerFilter action.  These are the counts shown in the
             Creo Parametric layer import dialog.

   Input Arguments:
        data            - The imported layer information.

   Output Arguments:
        curve_count     - The curve count for the designated layer.
        surface_count   - The surface count for the designated layer.
        trimmed_surface_count - The trimmed surface count for the designated
                                layer.
   Return Values:
        PRO_TK_NO_ERROR   - The function successfully retrieved the information.
        PRO_TK_BAD_INPUTS - The function arguments were invalid.
*/

typedef enum _ProLayerImportOption
 {
        PRO_LAYER_IMPORT_NORMAL = PRO_LAYER_TYPE_NORMAL,
        PRO_LAYER_IMPORT_DISPLAY = PRO_LAYER_TYPE_DISPLAY,
        PRO_LAYER_IMPORT_BLANK = PRO_LAYER_TYPE_BLANK,
        PRO_LAYER_IMPORT_HIDDEN = PRO_LAYER_TYPE_HIDDEN,
        PRO_LAYER_IMPORT_SKIP = PRO_LAYER_TYPE_SKIP, /* Do not import the entities on this layer*/
        PRO_LAYER_IMPORT_IGNORE = 7 /* Create entities, but do not create this
                                       layer */
 } ProLayerImportOption;

extern ProError   ProLayerfilterdataActionSet ( ProLayerfilterdata data,
                                                ProLayerImportOption action);
/*
   Purpose:  Sets the layer action for a ProLayerfilterdata object passed to 
             the ProIntfimportLayerFilter action.

   Input Arguments:
        data            - The imported layer information.
        action          - The action to take for this layer (SKIP, BLANK,
                          DISPLAY, ISOLATE) 
   Output Arguments:
        none 

   Return Values:
        PRO_TK_NO_ERROR   - The function successfully retrieved the information.
        PRO_TK_BAD_INPUTS - The function arguments were invalid.
*/

extern ProError ProLayerfilterdataNameSet ( ProLayerfilterdata data,
                                            ProName   new_layer_name );
/*
   Purpose: Set the layer name for the newly imported layer.

   Input Arguments:
        data            - The imported layer information.
        new_layer_name  - The new layer name.

   Output Arguments:
        none

   Return Values:
        PRO_TK_NO_ERROR   - The function successfully set the name.
        PRO_TK_BAD_INPUTS - One or more function input was invalid.
*/

extern ProError ProIntfimportValidationpreferencesLoad (ProPath file);
/*
  Purpose: Loads validation preferences from a file.
           These preferences will be used during the validation until they 
           are reset.

  Input Arguments:
       file - The path to the file. Cannot be NULL.

  Output Arguments:
       none

  Return Values:
       PRO_TK_NO_ERROR    - The function successfully loaded the file.
       PRO_TK_BAD_INPUTS  - The argument file is NULL or not a solid.
       PRO_TK_E_NOT_FOUND - The file not found.
       PRO_TK_NOT_EXIST   - Improper format in the file.
*/

extern ProError ProIntfimportValidationscoreGet(ProMdl model, ProLine score);
/*
  Purpose: Gets the import validation score of the model.

  Input Arguments:
       model - The model from which the validation score should be retrieved.

  Output Arguments:
       score - The validation score value.

  Return Values:
       PRO_TK_NO_ERROR    - The function successfully returned the score.
       PRO_TK_BAD_INPUTS  - The argument model is NULL or not a solid.
       PRO_TK_INVALID_PTR - The model pointer is invalid.
       PRO_TK_NOT_EXIST   - The model is missing.
       PRO_TK_E_NOT_FOUND - The score does not exist on the model.
*/

extern ProError ProIntfimportValidationscoreCalculate(ProMdl model, 
                                                      ProLine score);
/*
  Purpose: Calculates the import validation score for the model.
           
  Input Arguments:
       model - The model for which the validation score should be calculated

  Output Arguments:
       score - The calculated validation score value

  Return Values:
       PRO_TK_NO_ERROR      - The function executed successfully.
       PRO_TK_BAD_INPUTS    - The argument model is NULL or not a solid.
       PRO_TK_NOT_EXIST     - The model is missing.
       PRO_TK_INVALID_PTR   - The model pointer is invalid.
       PRO_TK_GENERAL_ERROR - The function failed to calculate the score.
*/

PRO_END_C_DECLS

#endif /* PROINTFIMPORT_DOT_H */
