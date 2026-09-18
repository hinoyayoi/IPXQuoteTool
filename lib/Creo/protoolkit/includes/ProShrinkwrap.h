#ifndef PROSHRINKWRAP_H
#define PROSHRINKWRAP_H

#include <ProToolkit.h>
#include <ProToolkitErrors.h>
#include <ProSelection.h>
#include <ProObjects.h>
#include <ProSizeConst.h>



PRO_BEGIN_C_DECLS

typedef struct sw_options* ProShrinkwrapOptions; 
typedef struct sw_specific_options* ProShrinkwrapSpecificOptions;
typedef struct sw_merged_solid_options* ProShrinkwrapMergedSolidOptions;
typedef struct sw_faceted_solid_options* ProShrinkwrapFacetedSolidOptions;  
typedef struct sw_surf_subset_options* ProShrinkwrapSurfSubsetOptions; 

typedef enum {
   PRO_SWFACETED_PART,
   PRO_SWFACETED_LIGHTWEIGHT_PART,
   PRO_SWFACETED_STL,
   PRO_SWFACETED_VRML
} ProShrinkwrapFacetedFormat;

typedef enum {
   PRO_SWCREATE_SURF_SUBSET,
   PRO_SWCREATE_FACETED_SOLID,
   PRO_SWCREATE_MERGED_SOLID
} ProShrinkwrapCreationMethod;

extern ProError ProSolidShrinkwrapCreate (ProSolid solid,
                                          ProSolid output_model,
                                          ProName output_file,
                                          ProShrinkwrapOptions output_options);
/*
	DEPRECATED: Since Creo 3
    SUCCESSORS: ProSolidShrinkwrapMdlnameCreate
    Purpose: <b>Note:</b> This function is deprecated
             Use ProSolidShrinkwrapMdlnameCreate instead.

               Exports a shrinkwrap version of the provided model.

    Input Arguments:
            solid - The model to be exported as a shrinkwrap.
            output_model - The model where the shrinkwrap geometry will
                      be created.  This could be an empty model produced
                      by ProSolidCreate(), or a template model with 
                      predefined geometry.  If exporting VRML or STL, this
                      can be NULL.
            output_file - The name of the file to create, if exporting 
                      VRML or STL. (The ".stl" or ".wrl" extension will be 
                      appended automatically, and the file created in the 
                      current directory.) If exporting as a Creo Parametric 
                      model, this can be NULL.
            output_options - The structure defining the shrinkwrap
                      options.

    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function successfully produced the
                      shrinkwrap model.
            PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
            PRO_TK_BAD_CONTEXT - Invalid combination of input arguments.
            PRO_TK_GENERAL_ERROR - an error occurred and the function failed.
*/

extern ProError ProSolidShrinkwrapMdlnameCreate (ProSolid solid,
                                                 ProSolid output_model,
                                                 ProMdlName output_file,
                                                 ProShrinkwrapOptions output_options);
/*
    Purpose:   Exports a shrinkwrap version of the provided model.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

    Input Arguments:
            solid - The model to be exported as a shrinkwrap.
            output_model - The model where the shrinkwrap geometry will
                      be created.  This could be an empty model produced
                      by ProSolidMdlnameCreate(), or a template model with 
                      predefined geometry.  If exporting VRML or STL, this
                      can be NULL.
            output_file - The name of the file to create, if exporting 
                      VRML or STL. (The ".stl" or ".wrl" extension will be 
                      appended automatically, and the file created in the 
                      current directory.) If exporting as a Creo Parametric 
                      model, this can be NULL.
            output_options - The structure defining the shrinkwrap
                      options.

    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function successfully produced the
                      shrinkwrap model.
            PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
            PRO_TK_BAD_CONTEXT - Invalid combination of input arguments.
            PRO_TK_GENERAL_ERROR - an error occurred and the function failed.
            PRO_TK_LINE_TOO_LONG - Name length of the output file is more than 31 chars.
*/

extern ProError ProShrinkwrapoptionsAlloc (ProShrinkwrapCreationMethod method,
                                           ProShrinkwrapOptions* p_options);
/* 

Purpose: Allocates memory to the options. 

Input Arguments: 

   method         - Creation method

Output Arguments: 

   p_options        - option handle

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/ 

extern ProError ProShrinkwrapoptionsFree (ProShrinkwrapOptions options); 
/* 

Purpose: Frees memory allocated for the shrinkwrap options structure

Input Arguments: 

   options                - options handle

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/    

extern ProError ProShrinkwrapoptionsQualitySet (ProShrinkwrapOptions options, 
                                                int quality);
/* 

Purpose: Sets the quality of the shrinkwrap option (between 1 and 10; default: 1)

Input Arguments: 

   options        - options handle

   quality        - Quality

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/  

extern ProError ProShrinkwrapoptionsAutoholefillingSet (ProShrinkwrapOptions options,
                                                        ProBoolean auto_hole_filling);
/* 

Purpose: Sets the auto_hole_filling option to TRUE or FALSE (default: TRUE)

Input Arguments: 

   options            - options handle

   auto_hole_filling   - the auto_hole_filling option

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/  

extern ProError ProShrinkwrapoptionsIgnoreskeletonsSet (ProShrinkwrapOptions options,
                                                        ProBoolean ignore_skeletons);
/* 

Purpose: Sets the ignore_skeletons option to TRUE or FALSE (default: TRUE)

Input Arguments: 

   options            - options handle

   ignore_skeletons   - the skeleton_ignore option

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/  

extern ProError ProShrinkwrapoptionsIgnorequiltsSet (ProShrinkwrapOptions options,
                                                     ProBoolean ignore_quilts);
/* 

Purpose: Sets the ignore_quilts option to TRUE or FALSE (default: TRUE)

Input Arguments: 

   options            - options handle

   ignore_quilts      - the quilts_ignore option

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/   

extern ProError ProShrinkwrapoptionsIgnoresmallsurfsSet (ProShrinkwrapOptions options, 
                                                         ProBoolean ignore_small_surfs, 
                                                         double percentage);
/* 

Purpose: Sets the ignore_small_surfs option to TRUE or FALSE (default: FALSE)

Input Arguments: 

   options              - options handle

   ignore_small_surfs   - the ignore_small_surfs option

   percentage           - percentage (of model size) 

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/     

extern ProError ProShrinkwrapoptionsAssignmasspropsSet (ProShrinkwrapOptions options, 
                                                        ProBoolean assign_mass_props);
/* 

Purpose: Sets the assign_mass_props option to TRUE or FALSE (default: FALSE)
Note: the default density of 1.0 will be used for components whose density has not been set

Input Arguments: 

   options              - options handle

   assign_mass_props    - the assign_mass_props option

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/     
 
extern ProError ProShrinkwrapoptionsDatumrefsSet (ProShrinkwrapOptions options, 
                                                  ProSelection* datum_refs);
/* 

Purpose: Sets a ProArray of Datum references in the shrinkwrap options structure (default: none)

Input Arguments: 

   options              - options handle

   datum_refs           - ProArray of Datum references

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/   

extern ProError ProShrinkwrapoptionsAdditionalsurfacesSet (ProShrinkwrapOptions options,
                                                           ProSelection* additional_surfaces); 
/* 

Purpose: Sets a ProArray of selections of surfaces in the shrinkwrap options structure (default: none). Valid only for PRO_SWCREATE_SURF_SUBSET creation method

Input Arguments: 

   options              - options handle

   additional_surfaces  - ProArray of surface selections

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/ 

extern ProError ProShrinkwrapoptionsFacetedformatSet (ProShrinkwrapOptions options, 
                                                      ProShrinkwrapFacetedFormat format);
/* 

Purpose: Sets a format for shrinkwrap creation (default: PRO_SWFACETED_PART). Valid only for the PRO_SWCREATE_FACETED_SOLID method.

Input Arguments: 

   options              - options handle

   format               - format for shrinkwrap creation

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/     

extern ProError ProShrinkwrapoptionsFramesFileSet (ProShrinkwrapOptions options, 
                                                   ProPath frames_file);
/* 

Purpose: Sets a frames file (name or path) to be used for motion envelope creation (default: none). Valid only for the PRO_SWCREATE_FACETED_SOLID method.

Input Arguments: 

   options              - options handle

   frames_file           - frames file (name or path) for motion envelope creation

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/     

extern ProError ProShrinkwrapoptionsAdditionalcomponentsSet (ProShrinkwrapOptions options, 
                                                             ProSelection* additional_components);
/* 

Purpose: Sets a ProArray of additional components required for shrinkwrap creation (default: none). Valid only for the PRO_SWCREATE_MERGED_SOLID method.

Input Arguments: 

   options                - options handle

   additional_components  - ProArray of additional component selections

Output Arguments: 

   none

Return Values: 

   PRO_TK_NO_ERROR - function completed successfully. 
   
   PRO_TK_BAD_INPUTS - improper inputs

*/      

PRO_END_C_DECLS
#endif
