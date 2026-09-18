#ifndef PROINTF3DEXPORT_H
#define PROINTF3DEXPORT_H

#include   <ProSizeConst.h>
#include   <ProQuilt.h>
#include   <ProLayer.h>

/*
   Function declarations and specific data structures for export files
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef	enum pro_intf3d_export_type {
	PRO_INTF_EXPORT_STEP = 1,
	PRO_INTF_EXPORT_SET,            /* This type is obsolete.   */
	PRO_INTF_EXPORT_VDA,
	PRO_INTF_EXPORT_IGES,
	PRO_INTF_EXPORT_CATIA,		/* This type is obsolete.   */
	PRO_INTF_EXPORT_CATIA_MODEL,
	PRO_INTF_EXPORT_SAT,
	PRO_INTF_EXPORT_NEUTRAL,
	PRO_INTF_EXPORT_CADDS,
	PRO_INTF_EXPORT_CATIA_SESSION,  /* Not currently supported; */
	                                /* reserved for future use. */
	PRO_INTF_EXPORT_PDGS,           /* This type is obsolete.   */
	PRO_INTF_EXPORT_PARASOLID,
	PRO_INTF_EXPORT_UG,

        PRO_INTF_EXPORT_RESERVED,
        PRO_INTF_EXPORT_CATIA_PART,
        PRO_INTF_EXPORT_CATIA_PRODUCT,
	PRO_INTF_EXPORT_CATIA_CGR,
	PRO_INTF_EXPORT_JT,
	PRO_INTF_EXPORT_DXF,
	PRO_INTF_EXPORT_DWG,
	PRO_INTF_EXPORT_SW_PART,
	PRO_INTF_EXPORT_SW_ASSEM
} ProIntf3DExportType;

typedef enum pro_output_assembly_configuration {
   PRO_OUTPUT_ASSEMBLY_FLAT_FILE,
   PRO_OUTPUT_ASSEMBLY_SINGLE_FILE,
   PRO_OUTPUT_ASSEMBLY_MULTI_FILES,
   PRO_OUTPUT_ASSEMBLY_PARTS
} ProOutputAssemblyConfiguration;


typedef struct pro_output_brep_representation* ProOutputBrepRepresentation;
typedef struct pro_output_inclusion* ProOutputInclusion;
typedef struct pro_output_layer_options* ProOutputLayerOptions;

extern ProError ProOutputBrepRepresentationIsSupported(
           		ProIntf3DExportType file_type,
          		ProOutputBrepRepresentation representation,
			ProBoolean*  is_supported);
/*  
Purpose:	Checks if the specified brep representation may be used
		for the export file type.  Use this function before calling
		ProIntf3DFileWrite() to confirm that the configuration is supported.

Input Arguments:
file_type       -  The type of output file to produce.
representation  -  Specifies the type of geometric representation to create.

Output Arguments:
is_supported    -  PRO_B_TRUE if the representation type is supported in Creo Parametric,
		   PRO_B_FALSE if not.

Return Values:
PRO_TK_NO_ERROR        - The function successfully returned the information.
PRO_TK_BAD_INPUTS      - One or more input arguments was invalid.
PRO_TK_NOT_IMPLEMENTED - file_type interface is currently not supported. 
PRO_TK_INVALID_TYPE    - invalid file_type.

*/

extern ProError ProOutputAssemblyConfigurationIsSupported(
           		ProIntf3DExportType file_type,
           		ProOutputAssemblyConfiguration configuration,
			ProBoolean*  is_supported);

/*  
Purpose:	Checks if the specified assembly configuration may be used
		for the export file type.  Use this function before calling
		ProIntf3DFileWrite() to confirm that the configuration is supported.

Input Arguments:
file_type           -   The type of output file to produce.
configuration 	    -   Specifies the number and type of output files to produce.

Output Arguments:
is_supported 	    - 	PRO_B_TRUE if the option is supported in Creo Parametric,
		  	PRO_B_FALSE if not

Return Values:
PRO_TK_NO_ERROR        - The function successfully returned the information.
PRO_TK_BAD_INPUTS      - One or more input arguments was invalid.
PRO_TK_NOT_IMPLEMENTED - file_type interface is currently not supported. 
PRO_TK_INVALID_TYPE    - invalid file_type.

*/

extern ProError  ProOutputBrepRepresentationAlloc(
			ProOutputBrepRepresentation* representation);

/*  
Purpose:	Allocate a brep representation data structure for 
		use in ProIntf3DFileWrite.

Input Arguments:  
none 

Output Arguments:
representation        -  The allocated brep representation structure.

Return Values:
PRO_TK_NO_ERROR    -    The function allocated the options.
PRO_TK_BAD_INPUTS  -    The argument was invalid.
*/

extern ProError  ProOutputBrepRepresentationFree(
			ProOutputBrepRepresentation representation);

/*  
Purpose:	Free a brep representation data structure.

Input Arguments:  
representation            -    The brep representation structure.

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR    -    The function freed the options.
PRO_TK_BAD_INPUTS  -    The argument was invalid.
*/

extern ProError  ProOutputBrepRepresentationFlagsSet(
			ProOutputBrepRepresentation representation,
			ProBoolean as_wireframe,
			ProBoolean as_surfaces,
			ProBoolean as_solid,
			ProBoolean as_quilts);
/*  
Purpose:	Set the brep representation flags.
		Note: not all combinations of flags are valid for all export 
		types. The function ProOutputBrepRepresentationIsSupported 
		indicates if a particular representation is supported by
		Creo Parametric for a certain export type.

Input Arguments:  
        representation         -    The brep representation structure.
        as_wireframe    -    Whether or not to export geometry as wireframe.
	as_surfaces     -    Whether or not to export geometry as surfaces.
	as_solid        -    Whether or not to export geometry as solid.
	as_quilts       -    Whether or not to export geometry as quilts.

Output Arguments:
        none

Return Values:
        PRO_TK_NO_ERROR    -    The function set the flags.
        PRO_TK_BAD_INPUTS  -    The arguments were invalid. 
*/

extern ProError ProOutputInclusionAlloc(
			ProOutputInclusion* inclusion);
/*  
Purpose:	Allocate an inclusion structure for use with the function
		ProIntf3DFileWrite.

Input Arguments:  
none

Output Arguments:
inclusion            -    The allocated inclusion structure.

Return Values:
PRO_TK_NO_ERROR    -    The function allocated the options.
PRO_TK_BAD_INPUTS  -    The argument was invalid.
*/

extern ProError ProOutputInclusionFree (ProOutputInclusion inclusion);
/*  
Purpose:	Free an inclusion structure.

Input Arguments:  
inclusion            -    The inclusion structure.

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR    -    The function freed the structure.
PRO_TK_BAD_INPUTS  -    The argument was invalid.
*/

extern ProError ProOutputInclusionFlagsSet(
			ProOutputInclusion inclusion,
			ProBoolean include_datums,
			ProBoolean include_blanked,
			ProBoolean include_facetted);
/*  
Purpose:	Set the inclusion flags in the inclusion structure.

Input Arguments:  
      inclusion            -    The inclusion structure.
      include_datums     -    Whether or not to include datums. 
      include_blanked    -    Whether or not to include blanked entities.
                        If PRO_B_TRUE, entities assigned to blanked 
                        layers will be exported. This is equivalent 
                        to the config option "intf_out_blanked_entities"
                        being set to "yes". If PRO_B_FALSE, entities 
                        assigned to blanked layers will not be exported.
                        This is equivalent to the config option
                        "intf_out_blanked_entities" being set to "no".

      include_facetted   -    Whether or not to include facets.

Output Arguments:
      none

Return Values:
      PRO_TK_NO_ERROR    -    The function allocated the options.
      PRO_TK_BAD_INPUTS  -    The input arguments were invalid.
*/


extern ProError  ProOutputLayerOptionsAlloc(
			ProOutputLayerOptions* layer_options);
/*  
Purpose:	Allocate the layer options structure for use in the function 
		ProIntf3DFileWrite.

Input Arguments:  
none

Output Arguments:
layer_options            -   The layer options.

Return Values:
PRO_TK_NO_ERROR    -   The function allocated the options.
PRO_TK_BAD_INPUTS  -   The arguments were invalid.

*/

extern ProError  ProOutputLayerOptionsAutoidSet(
			ProOutputLayerOptions options, 
			ProBoolean auto_ids);
/*  
Purpose:	Set the layer options flag for automatic layer identifiers.

Input Arguments:  
options      -    The layer options.
auto_ids            -    If PRO_B_TRUE, layers not specifically included in
			the layer options will be automatically assigned ids
			and   exported.  If PRO_B_FALSE, only the layers 
			specified in the layer options will be exported 
			from the model.

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR    -    The function freed the options.
PRO_TK_BAD_INPUTS  -    The arguments were invalid.

*/

extern ProError  ProOutputLayerOptionsSetupfileSet(
			ProOutputLayerOptions options, 
			ProPath layer_setup_file);
/*  
Purpose:	Set the layer options flag for automatic layer identifiers.

Input Arguments:  
options            -    The layer options.
layer_setup_file   -    The layer setup file, which includes layer
			assignment information.

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR    -    The function freed the options.
PRO_TK_BAD_INPUTS  -    The arguments were invalid.

*/


extern ProError  ProOutputLayerOptionsFree(
			ProOutputLayerOptions options);
/*
Purpose:	Frees the layer options structure.

Input Arguments:  
options            -    The layer options structure.

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR    -    The function freed the data.
PRO_TK_BAD_INPUTS  -    The argument was invalid.

*/

extern ProError ProIntf3DFileWrite (
	           ProSolid solid,
        	   ProIntf3DExportType file_type,
	           ProPath output_file,
        	   ProOutputAssemblyConfiguration configuration,
	           ProSelection  reference_csys, 
        	   ProOutputBrepRepresentation brep_representation, 
	           ProOutputInclusion inclusion, 
        	   ProOutputLayerOptions layer_options);
/*  
SUCCESSORS: ProIntf3DFileWriteWithDefaultProfile
Purpose:	Exports a Creo Parametric model using the specified options.
            This API will be deprecated in future release.

Input Arguments:
solid             -     The solid model used for export.
file_type         -     The type of output file to produce.
output_file       -     The output file name to produce.  Optionally, this includes
			the path for the file location.  The filename should not 
			include the file extension, this will be added automatically 
			by Creo Parametric.
configuration     -     Specifies the number and type of output files to produce.
     			Users should check that this option is valid for the type 
     			of output specified in file_type by using the function 
			ProOutputAssemblyConfigurationIsSupported().
			If file_type == PRO_INTF_EXPORT_CADDS or PRO_INTF_EXPORT_NEUTRAL,
                        this value is ignored by Creo Parametric. 
			An assembly is exported as a single file for 
			PRO_INTF_EXPORT_DXF and PRO_INTF_EXPORT_DWG formats
reference_csys    -     The reference coordinate system.  If NULL, the system uses 
			the default coordinate system.
			If file_type == PRO_INTF_EXPORT_CADDS or PRO_INTF_EXPORT_NEUTRAL,
                        this should be NULL.
brep_representation  -  The options that specify the type of representation to create.
			Users should check that these options are valid for 
			the type of output specified in file_type by using the function
			ProOutputBrepRepresentationIsSupported().
			If file_type == PRO_INTF_EXPORT_CADDS or PRO_INTF_EXPORT_NEUTRAL,
                        this should be NULL.
inclusion         -     The options for:
                        <p>entity inclusion or exclusion in the output file(s);
                        <p>quality control values;
                        <p>config flags.
                        <p>If file_type == PRO_INTF_EXPORT_CADDS or PRO_INTF_EXPORT_NEUTRAL,
                        this should be NULL.
                        <p>If this is NULL, the facet export will  be governed by
                        Creo Parametric config options and default quality control values.
layer_options     -     The options that specify how layers are to be output.
			If file_type == PRO_INTF_EXPORT_CADDS or PRO_INTF_EXPORT_NEUTRAL,
                        this should be NULL.

Output Arguments:
none
 
Return Values:
PRO_TK_NO_ERROR        - The function successfully exported the Creo Parametric model.
PRO_TK_BAD_INPUTS      - The input arguments are invalid.
PRO_TK_NOT_IMPLEMENTED - file_type interface is currently not supported.
PRO_TK_INVALID_TYPE    - invalid file_type.
PRO_TK_BAD_CONTEXT     - The function is not available in
          		 Design Test Mode.
PRO_TK_NO_CHANGE       - The function did not export the source model as
			 the up-to-date image in HDIC context already exists
			 for the specified Creo Parametric source model.
PRO_TK_NO_LICENSE      - Missing the required license to perform this export
                         operation.

*/

extern ProError  ProOutputInclusionFacetparamsSet(
			ProOutputInclusion inclusion,
			double chord_height, double angle_control);
/*  
Purpose:	Sets the values to use while exporting the model to a faceted 
                format such as PRO_INTF_EXPORT_CATIA_CGR.
<p>
                This API will be deprecated - use ProOutputInclusionWithOptionsSet instead.
                This API is equivalent to ProOutputInclusionWithOptionsSet with
                only PRO_FACET_STEP_SIZE_OFF set for config_flags

Input Arguments:  
      inclusion		-    The inclusion structure.
      chord_height	-    The chord height to use for the exported facets.
      angle_control	-    The angle control to use for the exported facets.
                             Value is from 0.0 to 1.0.
Output Arguments:
      none

Return Values:
      PRO_TK_NO_ERROR    -    The function succeeded.
      PRO_TK_BAD_INPUTS  -    The input arguments were invalid.
*/

extern ProError  ProOutputInclusionWithOptionsSet(
			ProOutputInclusion inclusion,
			double             *parameters,
                        int                config_flags);

/*  
Purpose:	Sets the values to use while exporting the model to a faceted 
                format such as PRO_INTF_EXPORT_CATIA_CGR.

Input Arguments:  
      inclusion      - The inclusion structure.
      parameters     - ProArray of parameters to be set; 
                       in this version this array always has 3 elements,
                       which are interpreted as: 
                       chord_height, angle_control, step_size
                       (in future this array may be expanded).

                       angle_control must be from 0.0 to 1.0

                       Setting chord_height or step_size to values too big or 
                       too small (for instance, bigger than the model 
                       size or smaller than the model absolute accuracy)
                       may cause an error, or other API which accept 
                       ProOutputInclusion as an input may instead use 
                       some smallest (biggest) values acceptable to 
                       them without returning an error.

      config_flags   - Bit flags (PRO_FACET_STEP_SIZE_ADJUST and others) to control
                       facet export. See comments against these flags
                       for how to use them.

Output Arguments:
      none

Return Values:
      PRO_TK_NO_ERROR     -   The function succeeded.
      PRO_TK_BAD_INPUTS   -   The input arguments were invalid
                              (for instance, parameters array is NULL
                              or its size is not 3).
      PRO_TK_OUT_OF_RANGE -   Some parameters are out of range.
                              If PRO_FACET_FORCE_INTO_RANGE is set, 
                              the inclusion still will be properly
                              initialized.
*/



extern ProError ProIntf3DFileWriteWithDefaultProfile(
	ProSolid		solid,
	ProIntf3DExportType	file_type,
	ProPath			output_file);
/*
Purpose:	Exports a Creo Parametric model using default export profile.

Input Arguments:
solid             -     The solid model used for export.
file_type         -     The type of output file to produce.
output_file       -     The output file name to produce.  Optionally, this includes
                        the path for the file location.  The filename should not
                        include the file extension, this will be added automatically
                        by Creo Parametric.

Output Arguments:
none

Return Values:
PRO_TK_NO_ERROR        - The function successfully exported the Creo Parametric model.
PRO_TK_BAD_INPUTS      - The input arguments are invalid.
PRO_TK_NOT_IMPLEMENTED - file_type interface is currently not supported.
PRO_TK_INVALID_TYPE    - invalid file_type.
PRO_TK_BAD_CONTEXT     - The function is not available in
Design Test Mode.
PRO_TK_NO_CHANGE       - The function did not export the source model as
the up-to-date image in HDIC context already exists
for the specified Creo Parametric source model.
PRO_TK_NO_LICENSE      - Missing the required license to perform this export
operation.

*/

PRO_END_C_DECLS

#endif /* PROINTF3DEXPORT_H */
