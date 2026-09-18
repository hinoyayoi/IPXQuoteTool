#ifndef PROSIMPREP_H
#define PROSIMPREP_H

/* Creo Parametric TOOLKIT declarations for ProSimprep related actions */

#include <ProObjects.h>
#include <ProSimprepdata.h>
#include <ProRule.h>
#include <ProAsmcomp.h>



PRO_BEGIN_C_DECLS

/*
   Types of simplified representations
*/
typedef enum pro_simprep_types
{
    PRO_SIMPREP_MASTER_REP,   /* Master Representation */
    PRO_SIMPREP_USER_DEFINED, /* User Defined Simplified Representation */
    PRO_SIMPREP_GRAPH_REP,    /* Graphics only representation */
    PRO_SIMPREP_GEOM_REP,     /* Geometry only representation */
    PRO_SIMPREP_SYMB_REP,     /* Symbolic only representation */
    PRO_SIMPREP_BOUNDBOX_REP, /* Boundary Box representation */ /* obsolete */
    PRO_SIMPREP_DEFENV_REP,   /* Default Envelope representation */
    PRO_SIMPREP_LIGHT_GRAPH_REP,/* Light Graphics representation */
    PRO_SIMPREP_ASSEM_ONLY_REP /* Reserved for internal use */
} ProSimprepType;


typedef enum pro_lwg_simprep_expand_type
{

    PRO_LWG_SIMPREP_LEVEL_SELECTED = 0,   /* Expand 3D Thumbnail to Selected */ /*Reserved for future use*/
    PRO_LWG_SIMPREP_LEVEL_NEXT,           /* Expand 3D Thumbnail to Next Level */
    PRO_LWG_SIMPREP_LEVEL_ALL             /* Expand 3D Thumbnail to All Levels */

}ProLightweightGraphicsSimprepLevel;


/*===========================================================================*/

extern ProError ProSimprepCreate (ProSolid          p_solid,
                                  ProSimprepdata   *p_data,
                                  ProSimprep       *p_new_rep);

/*
   Purpose:  Creates a simplified representation based on the supplied data.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      p_solid           - The solid in which to create the simplified
                          representation
      p_data            - The data for the simplified representation

   Output Arguments:
      p_new_rep         - The handle to the new simplified representation

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully created the simplified
                           representation.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

extern ProError ProSimprepActivate (ProSolid    p_solid, 
                                    ProSimprep *p_simp_rep);
/*
   Purpose:  Activates the specified simplified representation.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      p_solid           - The solid that corresponds to the representation
      p_simp_rep        - The simplified representation

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully activated the simplified 
                           representation.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - The specified simplified representation was not 
                           found in the model.
*/

extern ProError ProSimprepActiveGet (ProSolid      solid, 
                                     ProSimprep   *p_simp_rep);
/*
   Purpose:  Returns the current active simplified representation.


   Input Arguments:
      solid             - The solid 

   Output Arguments:
      p_simp_rep        - The current active simplified representation

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/

extern ProError ProGraphicsSimprepRetrieve (ProName        assem_name,
                                            ProAssembly   *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSimprepMdlnameRetrieve instead.

             Retrieves the graphics simplified representation of an assembly.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      assem_name        - The name of the assembly to retrieve

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
*/

extern ProError ProGeomSimprepRetrieve (ProName        assem_name,
                                        ProAssembly   *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSimprepMdlnameRetrieve instead.

             Retrieves the geometry simplified representation of an assembly.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      assem_name        - The name of the assembly to retrieve

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
*/

extern ProError ProSymbSimprepRetrieve (ProName        assem_name,
                                        ProAssembly   *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSimprepMdlnameRetrieve instead.

             Retrieves the symbolic simplified representation of an assembly.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      assem_name        - The name of the assembly to retrieve

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
*/

extern ProError ProBoundaryBoxSimprepRetrieve (ProName        assem_name,
                                               ProAssembly   *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSimprepMdlnameRetrieve instead.

             Retrieves the boundary box simplified representation of an assembly.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      assem_name        - The name of the assembly to retrieve

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
*/

extern ProError ProDefaultEnvelopeSimprepRetrieve (ProName        assem_name,
                                                   ProAssembly   *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSimprepMdlnameRetrieve instead.

             Retrieves the Default Envelope  simplified representation of an assembly.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      assem_name        - The name of the assembly to retrieve

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
*/

extern ProError ProLightweightGraphicsSimprepRetrieve (ProName      assem_name, 
                                                       ProAssembly *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
           Use ProSimprepMdlnameRetrieve instead.

            Retrieves the light-weight graphics simplified representation of 
            an assembly.
  <p><b>
         NOTE: 
  </b><p>             
         Operates on assemblies only, not parts.

  Input Arguments:
     assem_name - The name of the assembly to retrieve
  Output Arguments:
     p_assem            - The handle to the assembly

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the 
                            information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
     PRO_TK_NO_PERMISSION - The function does not have permission to operate
                            on this assembly.
*/

extern ProError ProAssemblySimprepRetrieve( ProFamilyName    assem_name, 
                                            ProName          simp_rep_name,
                                            ProSimprepdata  *simp_rep_data,
                                            ProAssembly     *p_assem);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProAssemblySimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProAssemblySimprepMdlnameRetrieve instead.

             Retrieves the specified simplified representation.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.
              <p>
              If errors occur in regeneration, the assembly will include 
              suppressed features.  The function
              ProSolidRetrievalErrorsGet identifies if errors occurred.


   Input Arguments:
      assem_name        - The name of the assembly to retrieve
      simp_rep_name     - The name of the simplified representation. Can be
                          NULL; the instructions in the data will be used
                          to create a new representation on the fly.
      simp_rep_data     - The simplified representation data. Can be NULL.

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
      PRO_TK_E_NOT_FOUND - The function did not find the simplified 
                           representation in the solid.

  See Also:
      ProSolidRetrievalErrorsGet()
*/

extern ProError ProAssemblySimprepMdlnameRetrieve( ProFamilyMdlName assem_name, 
						   ProMdlfileType   file_type,
						   ProName          simp_rep_name,
						   ProSimprepdata  *simp_rep_data,
						   ProAssembly     *p_assem);
/*
   Purpose:  Retrieves the specified simplified representation.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.
              <p>
              If errors occur in regeneration, the assembly will include 
              suppressed features.  The function
              ProSolidRetrievalErrorsGet identifies if errors occurred.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProFamilyMdlName will be added in a future release. 

   Input Arguments:
      assem_name        - The name of the assembly to retrieve
      file_type         - the file type of the assembly to retrieve.
      simp_rep_name     - The name of the simplified representation. Can be
                          NULL; the instructions in the data will be used
                          to create a new representation on the fly.
      simp_rep_data     - The simplified representation data. Can be NULL.

   Output Arguments:
      p_assem           - The handle to the assembly

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.
      PRO_TK_E_NOT_FOUND - The function did not find the simplified 
                           representation in the solid.

  See Also:
      ProSolidRetrievalErrorsGet()
*/

extern ProError ProPartSimprepRetrieve (ProFamilyName   part_name, 
                                        ProSimprepType  type,
                                        ProName         simp_rep_name,
                                        ProPart        *p_part);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSimprepMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSimprepMdlnameRetrieve instead.

             Retrieves the specified part simplified representation.
             If a higher representation of the model exists in the memory,
             then the simplified representation of type rep_type will be ignored
             and the higher representation of the model will be retrieved.


   Input Arguments:
      part_name         - The name of the part to retrieve
      type              - The type of simplified rep to retrieve
                              (PRO_SIMPREP_USER_DEFINED, PRO_SIMPREP_GRAPH_REP,
                               PRO_SIMPREP_GEOM_REP, PRO_SIMPREP_SYMB_REP,
                               PRO_SIMPREP_BOUNDARYBOX)
      simp_rep_name     - The name of the simplified representation, if the
                          type is PRO_SIMPREP_USER_DEFINED.  Otherwise, this 
                          can be NULL.

   Output Arguments:
      p_part            - The pointer to the part retrieved

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the part.
      PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND  - The Part was not found.
      PRO_TK_INVALID_NAME - The specified user defined rep was not found. 
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this assembly.

*/

extern ProError ProSimprepDelete (ProSimprep *p_simp_rep);

/*
   Purpose:  Deletes the specified simplified representation from its owner 
             model.

   Input Arguments:
      p_simp_rep        - The simplified representation to delete

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully deleted the simplified
                           representation.
      PRO_TK_BAD_INPUTS  - The argument is invalid.
*/

extern ProError ProSimprepInit (ProName      rep_name,
                                int          rep_id,
                                ProSolid     p_solid,
                                ProSimprep  *p_simp_rep);

/*
   Purpose:  Returns the handle to the specified simplified representation.


   Input Arguments:
      rep_name          - The name of the simplified representation in the
                          solid. If you specify this argument, the function
                          ignores <i>rep_id</i>.
      rep_id            - The identifier of the simplified representation, if
                          you did not specify the name (you specified NULL).
      p_solid           - The solid that contains the simplified representation.

   Output Arguments:
      p_simp_rep        - The handle to the simplified representation, if found.

   Return Values:
      PRO_TK_NO_ERROR    - The function found the simplified representation in 
                           the solid.
      PRO_TK_E_NOT_FOUND - The function did not find the simplified 
                           representation in the solid.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

extern ProError ProSimprepdataGet (ProSimprep       *p_simp_rep,
                                   ProSimprepdata  **p_data);

/*
   Purpose:  Retrieves the data for the specified simplified representation. 

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      p_simp_rep        - The simplified representation

   Output Arguments:
      p_data            - The simplified representation data, the memory
                          is allocated by the function and the user is
                          responsible for freeing this by calling 
                          <b>ProSimprepdataFree()</b>

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError ProSimprepdataSet (ProSimprep       *p_simp_rep,
                                   ProSimprepdata   *p_data);

/*
   Purpose:  Sets the specified data in the owner model of the specified
             simplified representation.

<p><b>
             NOTE: 
<p></b>
             Operates on assemblies only, not parts.

   Input Arguments:
      p_simp_rep        - The simplified representation
      p_data            - The data for the simplified representation

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the data.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError ProSolidSimprepVisit (ProSolid           p_solid,
                                      ProGeomitemFilter  filter,
                                      ProGeomitemAction  action,
                                      ProAppData         app_data);
/*
   Purpose:  Visits all the user-defined simplified representations in the specified solid.
			 This will not visit built-in representations.

   Input Arguments:
      p_solid           - The solid.
      filter            - The filter function. If NULL, all representations 
                          are visited using the action function.
      action            - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the simplified
                           representations.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - No simplified representations were found.
      Other              - Any other value is the value returned by the action 
                           function (visiting stopped). 
*/

extern ProError ProSimprepSelect (ProSolid     p_solid, 
                                  ProSimprep  *p_simp_rep);
/*
   Purpose:  Enables the user to select a simplified representation.

   Input Arguments:
      p_solid           - The solid that contains the simplified representation

   Output Arguments:
      p_simp_rep        - The selected simplified representation

   Return Values:
      PRO_TK_NO_ERROR    - The user selected a simplified representation.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_USER_ABORT  - The user aborted simplified representation selection.
      PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProSimprepTypeGet (ProSimprep     *p_simp_rep, 
                                   ProSimprepType *p_type);
/*
   Purpose:  Returns the special type for the specified simplified
             representation.

   Input Arguments:
      p_simp_rep        - The simplified representation.

   Output Arguments:
      p_type            - The simplified representation type.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError ProSimprepSubstitutionNameGet (ProSimprep   *p_simp_rep,
                                               ProSimprepitemPath *p_item_path,
                                               ProName   sub_name);
/*
   Purpose:  Returns the name of the substituted rep at the given path.

   Input Arguments:
      p_simp_rep        - The simplified representation
      p_item_path       - The path to the substituted rep

   Output Arguments:
      sub_name          - The name of the substituted rep.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more arguments is invalid.
      PRO_TK_BAD_CONTEXT - There is no substituted rep at the given item path.
*/

extern ProError ProSimprepIsDefault (ProSimprep *p_simp_rep, 
                                     ProBoolean *p_is_default);
/*
   Purpose:  Determines if the specified simplified representation is default.

   Input Arguments:
      p_simp_rep        - The simplified representation.
 
   Output Arguments:
     p_is_default        - PRO_B_TRUE if the simplified representation is the 
                           Default rep. PRO_B_FALSE otherwise.
 
  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


extern ProError ProCompdisplayActivate  (ProSolid    p_solid,
                                         ProCompdisp *p_compdisp, 
                                         int no_redisp);
/*

   Purpose: Similar to ProSimprepActivate, except this is for Comp Displays. 

   Input Arguments:
       p_solid         - The solid that contains the Comp Disp. 
       p_compdisp      - Comp Display pointer. 
       no_redisp       - Flag to specify whether or not user needs 
                         to redisplay assembly in the window inside
                         this call. If set to TRUE, user is solely
                         responsible for calling ProWindowRefresh()
                         or something else to refresh assembly view.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully activated CompDisp. 
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid or
                           activation failed.

*/

extern ProError ProCompdisplayActiveGet (ProSolid  p_solid, 
                                         ProCompdisp *p_compdisp);
/*

   Purpose: Similar to ProSimprepActiveGet, except this is for Comp Displays. 

   Input Arguments:
       p_solid           - The solid that contains the Comp Disp. 

   Output Arguments:
       p_compdisp        - Found CompDisplay pointer. 

   Return Values:
       PRO_TK_NO_ERROR    - The function successfully activated CompDisp.
       PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid or
                            did not get active Comp Disp.

*/

extern ProError ProCompdisplayInit (ProName rep_name, int rep_id,
                                    ProSolid p_solid, ProCompdisp *p_handle);
/*

   Purpose: Similar to ProSimprepInit, except for this is for Comp Displays. 

   Input Arguments:
       rep_name          - The name of the Comp Display. If you specify 
                            this argument, the function ignores rep_id.
       rep_id            - The identifier of Comp Disp if you did not
                            specify the name (you specified NULL). 
       p_solid           - The solid that contains the Comp Display. 

   Output Arguments:
       p_handle           - The handle to the Comp Display if found. 

   Return Values:
      PRO_TK_NO_ERROR   - The function found the simplified representation
                          in the solid.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.

*/

extern ProError ProCompdisplayIsDefault (ProCompdisp *p_compdisp, 
                                         ProBoolean  *p_is_default);
/*
   Purpose: Similar to ProSimprepIsDefault, except this is for Comp Displays. 

   Input Arguments:
      p_compdisp         - The Comp Display pointer.

   Output Arguments:
     p_is_default        - PRO_B_TRUE if the Comp Display is the Default.
                           PRO_B_FALSE otherwise.
 
  Return Values:
     PRO_TK_NO_ERROR     - The function succeeded.
     PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
*/



extern ProError ProSolidCompdisplayVisit (ProSolid p_solid, 
                ProGeomitemFilter filter, ProGeomitemAction action, 
                ProAppData app_data);
/*

   Purpose: Similar to ProSolidSimprepVisit, except this is for Comp Displays. 

   Input Arguments:
       p_solid            - The solid. 
       filter             - The filter function. If NULL, all items are 
                            visited using the action function.
       action             - The visiting function. If it returns anything 
                            other than PRO_TK_NO_ERROR, visiting stops.
       app_data           - The application data passed to the filter 
                            and visiting functions.  

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the Comp Displays.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND - No Comp Displays were found.
      Other              - Any other value is the value returned by the action
                           function (visiting stopped). 
*/


extern ProError ProAsmcompSubstitutionTypeGet(ProSimprep     *p_simp_rep,
                                              ProAsmcomppath *path_to_orig_comp,
                                              ProSubstType   *substituteType);
/*
    Purpose: if given component is substituted one then give type 
             of substitution performed on it.

    Input Arguments:

        p_simp_rep          - The handle to the simplified representation.
        path_to_orig_comp   - The component path, which is being substituted,
                              including component id (may NOT be NULL).
 
    Output Arguments:
        substituteType      -  Type of substitution peformed on component.

    Return Values:
        PRO_TK_NO_ERROR     - The function works fine.
        PRO_TK_BAD_INPUTS   - One or more of the arguments are invalid.
        PRO_TK_E_NOT_FOUND  - The component is not a substitute.
*/

extern ProError ProAsmcompSubstituteGet (ProSimprep         *p_simp_rep,
                                         ProAsmcomppath     *path_to_orig_comp,
                                         ProAsmcomppath     *path_to_subst_comp,
                                         ProAsmcomp         *substitute);
/*                                               
    Purpose: If a component is substituted with a given simplified rep, 
             then get the path and the handle of the substituted component.

    Input Arguments:

        p_simp_rep          - The handle to the simplified representation.
        path_to_orig_comp   - The component path, which is being substituted,
                              including component id (may NOT be NULL).
 
    Output Arguments:
        path_to_subst_comp  - Path to the substitute component, NOT including 
                              component.
        substitute          - Handle to the substitute component.

    Return Values:
        PRO_TK_NO_ERROR     - The function works fine.
        PRO_TK_BAD_INPUTS   - One or more of the arguments are invalid.
        PRO_TK_E_NOT_FOUND  - The component is not a substitute.
*/



extern ProError ProLightweightGraphicsSimprepExpand (ProAssembly   lwg_rep, 
                                     ProSelection tree_item, 
                                     ProLightweightGraphicsSimprepLevel lwg_level);
/*
  Purpose:  Expands the light weight graphics representation to the specified level

  Input Arguments:

    lwg_rep    - The lightweight graphic representation of assembly
    tree_item  -  The model feature whose light weight graphic representation is to be expanded
    lwg_level  -  The level up to which expand should take place

  Output Arguments:
    None

  Return Values:

    PRO_TK_NO_ERROR        - The function succeeded.
    PRO_TK_BAD_INPUTS      - One or more arguments was invalid.
    PRO_TK_E_FOUND           - The expand already exists till the selected level.
    PRO_TK_GENERAL_ERROR   - The function failed.

*/


extern ProError ProSimprepMdlnameRetrieve (ProMdlName model_name,
					   ProMdlfileType file_type,
					   ProSimprepType rep_type,
					   ProName rep_name,
					   ProSolid *p_solid);
/*
   Purpose:  Retrieves the specified simplified representation.
             If a higher representation of the model exists in the memory,
             then the simplified representation of type rep_type will be ignored
             and the higher representation of the model will be retrieved.

              <p><b>NOTE: </p></b>If errors occur in regeneration, 
              the model will include suppressed features.  The function
              ProSolidRetrievalErrorsGet identifies if errors occurred.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      model_name        - The name of the model to retrieve. NULL is not allowed.
      file_type         - The file type of the model to retrieve.
      rep_type          - The representation type. 
                          PRO_SIMPREP_MASTER_REP and PRO_SIMPREP_USER_DEFINED
                          can be used only if file_type is PRO_MDLFILE_PART
      rep_name          - The name of the simplified representation, if the rep_type
                          is PRO_SIMPREP_USER_DEFINED. Otherwise, this can be NULL.

   Output Arguments:
      p_solid           - The handle to the model. NULL is allowed.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.

  See Also:
      ProSolidRetrievalErrorsGet()
*/


PRO_END_C_DECLS
#endif /* PROSIMPREP_H */
