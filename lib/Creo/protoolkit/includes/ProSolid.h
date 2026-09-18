#ifndef PROSOLID_H
#define PROSOLID_H

/* Creo Parametric TOOLKIT declarations for ProSolid object related actions */

#include <ProObjects.h>
#include <ProMdl.h>
#include <ProFeature.h>
#include <ProSelection.h>
#include <ProColor.h>
#include <ProAnalysis.h>
#include <ProDimension.h>



typedef enum
{
   PROMODELCLASS_NONE = -1,
   PROMODELCLASS_FINE = 0,
   PROMODELCLASS_MEDIUM = 1,
   PROMODELCLASS_COARSE = 2,
   PROMODELCLASS_VERY_COARSE = 3
} ProModelClass;

typedef enum pro_solid_outline_exclude
{
   PRO_OUTL_EXC_NOT_USED     = 1,
   PRO_OUTL_EXC_DATUM_PLANE  = 2,
   PRO_OUTL_EXC_DATUM_POINT  = 3,
   PRO_OUTL_EXC_DATUM_CSYS   = 4,
   PRO_OUTL_EXC_DATUM_AXES   = 5,
   PRO_OUTL_EXC_FACETS       = 6,
   PRO_OUTL_EXC_ALL_CRVS     = 7


} ProSolidOutlExclTypes;

typedef struct
{
   Pro3dPnt start_point;
   ProVector dir_vector;
} ProRay;


typedef struct pro_mass_property
{
   double   volume;
   double   surface_area;
   double   density;
   double   mass;

   /* center of gravity with respect to coordinate frame */
   double   center_of_gravity[3];

   /* inertia matrix with respect to coordinate frame */
   /* (Element ij is the integral of x_i x_j over the object) */
   double   coor_sys_inertia[3][3];

   /* inertia tensor with respect to coordinate frame */
   /* inertia_tensor = trace(inertia) * identity - inertia */
   double   coor_sys_inertia_tensor[3][3];

   /* inertia tensor translated to center of gravity */
   double   cg_inertia_tensor[3][3];

   /* principal moments of inertia (eigenvalues of cg_inertia_tensor) */
   double   principal_moments[3];

   /* principal axes (the eigenvectors of cg_inertia_tensor) */
   /* The vectors are stored in columns */
   double   principal_axes[3][3];
} ProMassProperty;

/* ProSolidRegenerate() bit_flags */
#define PRO_REGEN_NO_FLAGS                  0
#define PRO_REGEN_CAN_FIX                   1  /* Allow UI in FixModel        */
#define PRO_REGEN_SKIP_DISALLOW_SYS_RECOVER 2 
#define PRO_REGEN_UPDATE_INSTS              4  /* Update instances in memory. */
                                               /* May cause slower performance*/
#define PRO_REGEN_RGN_BCK_USING_DISK        8  /* Use disk for regen backup   */
/* Note: The flag PRO_REGEN_RGN_BCK_USING_DISK is obsolete */

#define PRO_REGEN_FORCE_REGEN               16 /* Force full object           */
                                               /* regeneration                */
#define PRO_REGEN_UPDATE_ASSEMBLY_ONLY      32 /* Update assembly and sub-asm */
/* placements, regenerate assembly features and intersected parts.            */
/* This flag is affected by the following config options: */
/* - bump_revnum_on_retr_regen -- If no, the assembly will not be marked as   */
/* modified when updating the component placements using this option. This is */
/* similar to retrieval regeneration in the Creo Parametric UI.                  */
/* - regen_int_mdls_on_retr -- If yes, assembly features are updated during   */
/* regeneration.                                                              */
/* CANNOT be used with PRO_REGEN_FORCE_REGEN                                  */

#define PRO_REGEN_RESUME_EXCL_COMPS         64 /* This option will make       */
/* Creo Parametric resume simplified-rep excluded components (if the models are  */
/* in memory) during regeneration. This could result in a more accurate       */
/* regeneration of the components in the simplified representation.           */

#define PRO_REGEN_NO_RESOLVE_MODE    128 /* regenerate in no resolve mode     */
#define PRO_REGEN_RESOLVE_MODE       256 /* regenerate in resolve mode        */
/* The above flags allow temporary override default settings, which control   */
/* regeneration behavior                                                      */
#define PRO_REGEN_ALLOW_CONFIRM      512 /* Allows Regen Failure popup dialog */
#define PRO_REGEN_UNDO_IF_FAIL      1024 /* Undo, if possible, in case of fail*/
/* The above two flags should be used only with PRO_REGEN_NO_RESOLVE_MODE or  */
/* if the current mode is 'No Resolve'.  Also, they cannot be used together.  */
/* If one breaks these rules ProSolidRegenerate will return PRO_TK_BAD_CONTEXT*/
#define PRO_REGEN_SKIP_INSTS_REMAKE 2048 /*Skip remake of instances in memory*/
/* Don't forget to change PRO_REGEN_LAST_USED if you add a flag!              */

#define PRO_REGEN_LAST_USED  PRO_REGEN_SKIP_INSTS_REMAKE

/*===========================================================================*/

PRO_BEGIN_C_DECLS

extern ProError ProSolidInit   (ProName     name, 
                                ProType     type,
                                ProSolid   *p_handle);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSolidMdlnameInit
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSolidMdlnameInit instead.
   <b>Note: <b>This function accepts only ProType values which are listed
            in ProMdlType. Passing any other values may result in unpredictable 
            behavior.

                Initializes the <i>ProSolid</i> handle.

   Input Arguments:
      name              - The solid name
      type              - The solid type

   Output Arguments:
      p_handle          - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProSolidMdlnameInit( ProMdlName  name, 
                                     ProMdlfileType     type,
                                     ProSolid   *p_handle);
/*
   Purpose:     Initializes the <i>ProSolid</i> handle.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      name              - The solid name
      type              - The solid type

   Output Arguments:
      p_handle          - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProSolidCreate  (ProName     name, 
                                 ProType     type,
                                 ProSolid   *p_handle);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProSolidMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProSolidMdlnameCreate instead.

                Creates a new Creo Parametric object of the specified type,
                and initializes the <i>ProSolid</i> handle. 
 

   Input Arguments:
      name         - The name of the new object
      type         - The solid type (PRO_PART or PRO_ASSEMBLY)

   Output Arguments:
      p_handle     - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the new object.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_FOUND       - An object of the specified name and type already
                             exists.
      PRO_TK_GENERAL_ERROR - The object could not be created.
	  PRO_TK_LINE_TOO_LONG - Name length of the new object is more than 31 chars.
*/

extern ProError ProSolidMdlnameCreate ( ProMdlName  name, 
                                        ProMdlfileType     type,
                                        ProSolid   *p_handle);
/*
   Purpose:     Creates a new Creo Parametric object of the specified type,
                and initializes the <i>ProSolid</i> handle. 
 
 			<b>Note:</b> In Creo 3 this function does not support names longer than 
 			31 characters. It will return PRO_TK_LINE_TOO_LONG for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      name         - The name of the new object
      type         - The solid type (PRO_PART or PRO_ASSEMBLY)

   Output Arguments:
      p_handle     - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the new object.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_FOUND       - An object of the specified name and type already
                             exists.
      PRO_TK_GENERAL_ERROR - The object could not be created.
      PRO_TK_LINE_TOO_LONG - Name length of the new object is more than 31 chars.
*/


extern ProError ProSolidRegenerate  (ProSolid    p_handle,
                                                  int  flags);
/*
   Purpose:  Regenerates the specified <i>ProSolid</i>. 

   Input Arguments:
     p_handle           - The <i>ProSolid</i> to regenerate.
     flags              - Bitmask containing one or more of 
                             the bit flags PRO_REGEN_*

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully regenerated the
                                <i>ProSolid</i>.
      PRO_TK_UNATTACHED_FEATS - Unattached features were detected, but there
                                 was no regeneration failure
      PRO_TK_REGEN_AGAIN      - The model is too complex to regenerate the
                                 first time
      PRO_TK_GENERAL_ERROR    - Failure in regeneration
      PRO_TK_BAD_INPUTS       - Incompatible flags used.
      PRO_TK_BAD_CONTEXT      - Invalid regen flags and/or combination of
                                regeneration flags if
                                mixed with PRO_REGEN_FORCE_REGEN.
*/


extern ProError ProSolidToPostfixId   (ProSolid    handle,
                                       int        *p_id);
/*
   Purpose: Retrieves an internal postfix identifier for the specified solid
           (to be used in relations). 

   Input Arguments:
     handle            -  The <i>ProSolid</i> for which to retrieve the postfix 
                          identifier
    
   Output Arguments:
     p_id              -  The postfix identifier 

   Return Values:
    PRO_TK_NO_ERROR      -  The function successfully retrieved the information.
    PRO_TK_BAD_INPUTS    -  The specified <i>p_handle</i> does not correspond 
                            to any valid model in session.
    PRO_TK_GENERAL_ERROR -  There was a general internal failure.
*/
     
extern ProError ProPostfixIdToSolid  (int         id,
                                      ProSolid   *p_handle);
/*
   Purpose: Retrieves the solid handle, given the postfix identifier. 

   Input Arguments:
     id                -  The postfix identifier of the solid
    
   Output Arguments:
     p_handle          -  The address of the <i>ProSolid</i> handle

   Return Values:
    PRO_TK_NO_ERROR      -  The function successfully retrieved the information.
    PRO_TK_BAD_INPUTS    -  The specified identifier does not correspond to any
                            valid model in session.
    PRO_TK_GENERAL_ERROR -  There was a general internal failure.
*/


extern ProError ProSolidDisplay       (ProSolid   p_handle);

/*
   Purpose: Displays the specified object.
            <b>Note</b>:
<ul>
            <li>If no model is currently displayed, the specified model will
              be placed in the base window.
            <li>If a model is already displayed in the base window, the specified 
              model will be placed in an accessory window. The current window 
              will not be affected.
            <li>If the specified model has been assigned a new window, the model
              will be displayed in the new window provided a model is present
              in the base window, else the model is displayed in the base
              window.
</ul> 

   Input Arguments:
     p_handle    -  The object to display

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR      - The function successfully displayed the object.
     PRO_TK_GENERAL_ERROR - The system failed to create a window.
     PRO_TK_BAD_INPUTS    - The specified argument is invalid.
     PRO_TK_E_FOUND       - The model is already in a window (from
                            calling <b>ProObjectwindowMdlnameCreate()</b>).

   See Also:
     ProObjectwindowMdlnameCreate()
*/ 

/*===========================================================================*/
/*                        Modelitem Visit actions                            */
/*===========================================================================*/

typedef ProError (*ProAxisVisitAction) ( ProAxis  axis,
                                         ProError status,
                                         ProAppData app_data );
/*
   Purpose:  This is the generic function for visiting an axis.

   Input Arguments:
       axis     -  The axis handle
       status   -  The status
       app_data -  The application data passed to the function 
                   <b>ProSolidAxisVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/

typedef ProError (*ProAxisFilterAction) ( ProAxis  axis,
                                          ProAppData app_data );

/*
   Purpose:  This is the generic function for filtering an axis.

   Input Arguments:
       axis     -  The axis handle
       app_data -  The application data passed to the function 
                   <b>ProSolidAxisVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_CONTINUE - Skip visiting this axis and go to the next axis.
       Other           - Call the visit action for this axis. The return
                         value is passed as input to the visit action. 
*/
       
extern ProError ProSolidAxisVisit  (ProSolid     p_handle, 
                                    ProAxisVisitAction  visit_action,
                                    ProAxisFilterAction filter_action,
                                    ProAppData   app_data);

/*
   Purpose:     Visits all the axes in the specified <i>ProSolid</i>. 

   Input Arguments:
      p_handle          - The solid handle.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL, all
                          axes are visited using the action function. 
      app_data          - The application data passed to the filter and
                          visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the axes. 
      PRO_TK_E_NOT_FOUND - Either no axes exist, or they were all filtered out 
                           by the filter function.
      Other              - Any other value is the value returned by the 
                           action function (visiting stopped). 
*/

extern ProError ProSolidCsysVisit  (ProSolid     p_handle, 
                                    ProCsysVisitAction  visit_action,
                                    ProCsysFilterAction filter_action,
                                    ProAppData   app_data);
/*
   Purpose:     Visits all the coordinate systems in the specified solid. 

   Input Arguments:
      p_handle          - The solid handle.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL, all items are
                          visited using the action function.
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the items.
      PRO_TK_E_NOT_FOUND - Either no coordinate systems exist, or they were all
                           filtered out by the filter function.
      Other              - Any other value is the value returned by the action
                           function (visiting stopped).
*/


typedef ProError (*ProSurfaceVisitAction) (ProSurface p_surface,
                                           ProError status,
                                           ProAppData app_data );
/*
   Purpose:  This is the generic function for visiting a surface.

   Input Arguments:
       p_surface -  The surface handle
       status    -  The status
       app_data  -  The application data passed to the function 
                    <b>ProSolidSurfaceVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/

typedef ProError (*ProSurfaceFilterAction) (ProSurface p_surface,
                                            ProAppData app_data );

/*
   Purpose:  This is the generic function for filtering a surface.

   Input Arguments:
       p_surface -  The surface handle
       app_data  -  The application data passed to the function 
                    <b>ProSolidSurfaceVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_CONTINUE - Skip visiting this surface and go to the next surface.
       Other           - Call the visit action for this surface. The return 
                         value is passed as input to the visit action.
*/

extern ProError ProSolidSurfaceVisit (ProSolid     p_handle, 
                                      ProSurfaceVisitAction visit_action,
                                      ProSurfaceFilterAction filter_action,
                                      ProAppData   app_data);
/*
   Purpose:     Visits all the surfaces in the specified solid. 

   Input Arguments:
      p_handle          - The solid handle.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL, all surfaces are
                          are visited using the action function.
      app_data          - The application data passed to the filter and
                          visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the surfaces.
      PRO_TK_E_NOT_FOUND - Either no surfaces exist, or they were all filtered 
                           out by the filter function.
      Other              - Any other value is the value returned by the 
                           action function (visiting stopped).
*/


extern ProError ProSolidQuiltVisit    (ProSolid     p_handle, 
                                       ProQuiltVisitAction  visit_action,
                                       ProQuiltFilterAction  filter_action,
                                       ProAppData            app_data);
/*
   Purpose:     Visits all the quilts in the specified solid. 

   Input Arguments:
      p_handle          - The solid handle.
      visit_action      - The visiting function. If it returns anything other
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL, all quilts are
                          visited using the action function.
      app_data          - The application data passed to the filter and
                          visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the quilts.
      PRO_TK_E_NOT_FOUND - Either no quilts exist, or they were all filtered 
                           out by the filter function.
      Other              - Any other value is the value returned by the action 
                           function (visiting stopped). 
*/

typedef ProError (*ProFeatureVisitAction) ( ProFeature* p_feature,
                                            ProError status,
                                            ProAppData app_data );
/*
   Purpose:  This is the generic function for visiting a feature. 

   Input Arguments:
       p_feature   -  The feature handle
       status      -  The status
       app_data    -  The application data passed to the function 
                      <b>ProSolidFeatVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/

typedef ProError (*ProFeatureFilterAction) ( ProFeature* p_feature,
                                             ProAppData app_data );

/*
   Purpose:  This is the generic function for filtering features.

   Input Arguments:
       p_feature   -  The feature handle 
       app_data    -  The application data passed to the function 
                      <b>ProSolidFeatVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_CONTINUE - Skip visiting this feature and go to the next feature.
       Other           - Call the visit action for this feature. The return 
                         value is passed as input to the visit action.
*/

extern ProError ProSolidFeatVisit     (ProSolid     p_handle, 
                                       ProFeatureVisitAction  visit_action,
                                      ProFeatureFilterAction  filter_action,
                                       ProAppData   app_data);
/*
   Purpose:     Visits all the features in the specified solid.
   
   <P>
   <B>NOTE:</B> Internal features are also visited. 
      Use <B>ProFeatureVisibilityGet()</B> to filter/skip them if required.
   

   Input Arguments:
      p_handle          - The solid handle.
      visit_action      - The visiting function. If it returns anything other
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL, all features in the
                          specified solid are visited using the action function. 
      app_data          - The application data passed to the filter and
                          visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the features.
      PRO_TK_E_NOT_FOUND - Either no features exist, or they were all filtered 
                           out by the filter function.
      Other              - Any other value is the value returned by the 
                           action function (visiting stopped).
   
   See Also:      
      ProFeatureVisibilityGet() 
*/

typedef ProError (*ProSolidDispCompFilterAction) (ProAsmcomppath *p_path,
                                                  ProSolid        handle,
                                                  ProAppData      app_data);
/*
   Purpose:  This is used to filter assembly components. If it returns
             PRO_TK_CONTINUE, all the SUB-COMPONENTS of handle will not
             be visited.

   Input Arguments:
       p_path      -  The assembly component path
       handle      -  The component solid handle 
       app_data    -  The application data passed to the function 
                      <b>ProSolidDispCompVisit()</b>

   Output Arguments:
       None

   Return Values:
   PRO_TK_CONTINUE - Skip visiting this assembly component and go to the next.
   Other           - Call the visit action for this assembly component. The 
                     return value is passed as input to the visit action.
*/

typedef ProError (*ProSolidDispCompVisitAction) (ProAsmcomppath *p_path,
                                                 ProSolid        handle,
                                                 ProBoolean      down,
                                                 ProAppData      app_data);
/*
   Purpose:  This is used to visit assembly components. If it returns anything
             other than PRO_TK_NO_ERROR, assembly traversal stops.

   Input Arguments:
       p_path      -  The assembly component path
       handle      -  The component solid handle
       down        -  Use PRO_B_TRUE when going down to this component and
                      PRO_B_FALSE when going up from this component.
       app_data    -  The application data passed to the function 
                      <b>ProSolidDispCompVisit()</b>

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR - Continue visiting.
       Any other value - Stop visiting and return this error from the visit function.
*/

extern ProError ProSolidDispCompVisit ( ProSolid  handle,
                                      ProSolidDispCompVisitAction  visit_action,
                                     ProSolidDispCompFilterAction filter_action,
                                        ProAppData                   app_data);
/*
   Purpose:     Visits all the displayed components in the solid handle.

   Input Arguments:
      handle            - The solid handle.
      visit_action      - Visiting function applied to a displayed component
                          solid. See comments for ProSolidDispCompVisitAction.
      filter_action     - The filter function. If NULL, all displayed
                          components in the solid handle are visited using
                          the action function.         
      app_data          - The application data to be passed to the filter and
                          visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the solids.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      Other              - Any other value returned by the visit action
                           (visiting stopped).
  
*/

typedef ProError (*ProAnalysisVisitAction)(ProAnalysis analysis,
                                           ProError    filter_status,
                                           ProAppData  appdata);

/*

Purpose:  Action function called while visiting Creo Parametric analyses using  
          the function ProSolidAnalysisVisit().

Input Arguments:

        analysis      -  Analysis or measurement performed
        filter_status -  Return value from filter action function
        appdata       -  Application data passed to the function 
                         ProSolidAnalysisVisit()
Output Arguments:

        None

Return Values:

        PRO_TK_NO_ERROR - Continue visiting analyses
        Other           - Stop visiting analyses
 
*/


typedef ProError (*ProAnalysisFilterAction)(ProAnalysis analysis,
                                            ProAppData  appdata);

/*

Purpose:  Filter function called while visiting Creo Parametric analysis using  
          the function ProSolidAnalysisVisit().

Input Arguments:

        analysis      -  Analysis or measurement performed
        appdata       -  Application data passed to the function
                         ProSolidAnalysisVisit()
        
Output Arguments:

        None

Return Values:

        PRO_TK_CONTINUE - Do not call visit action function for this object.
        Other           - Call visit action function for this object. The
                          return value is passed as input to the visit action.
*/

extern ProError ProSolidAnalysisVisit(ProSolid                solid,
                                      ProAnalysisVisitAction  visit_action,
                                      ProAnalysisFilterAction filter_action,
                                      ProAppData                appdata);

/*

Purpose:   Visits External Analyses in the Creo Parametric solid model. 

Input Arguments:

        solid         -  Handle to visited solid 
        visit_action  -  Callback visit function 
        filter_action -  Callback filter function. If NULL, all items are  
                         visited using the action function.
        appdata       -  Application data passed to visit and filter
                         callback functions      
Output Arguments:

        None

Return Values:

         PRO_TK_NO_ERROR      - Successful completion of filter and visit functions.
        PRO_TK_BAD_INPUTS    - An input argument is invalid.       
        PRO_TK_E_NOT_FOUND   - Nothing to visit
        PRO_TK_GENERAL_ERROR - Function failed 
        Other                - Return value from visit action function that stops ProSolidAnalysisVisit

*/

extern ProError ProSolidDimensionVisit(
   ProSolid                 solid,
   ProBoolean               refdim,
   ProDimensionVisitAction  action,
   ProDimensionFilterAction filter,
   ProAppData               data);

/*

  Purpose: Visits all dimensions stored in the specified solid.
       i.e. all dimensions whose default names are of the
       form "d#", "rd#" or "ad#". This includes dimensions created
       in drawing mode when the config.pro option
       "create_drawing_dims_only" was set to NO (the default).

  Input Arguments:
     solid           -  Handle of the solid (part or assembly) whose
                        dimensions are to be visited.
     refdim          -  TRUE if the reference dimensions are to be
                        visited, FALSE for standard dimensions. 

     action          -  the function that gets called for each solid
                        dimension being visited.
     filter          -  the function that gets called for each solid
                        dimension. This function decides whether the
                        dimension should be visited or skipped.
                        If NULL, all dimensions are visited using the 
                        action function.
     data            -  caller-specified data that gets passed to the
                        action and filter functions.

  Output Arguments:
     None


  Return Values:
     PRO_TK_NO_ERROR   - The function successfully visited all
                            the model's dimensions.
     PRO_TK_BAD_INPUTS - The function failed because one or
                            more of the input arguments are invalid.
     PRO_TK_E_NOT_FOUND - No model dimensions were visited.
     PRO_TK_GENERAL_ERROR - An error occurred while locating the dimensions.
     other                - Visiting was stopped by the caller supplied
                            functions with this error return.
*/ 

extern ProError ProSolidFeatstatusflagsGet (ProSolid  solid,
                                           int          **p_feat_id_array,
                                           unsigned int **p_status_bitflag_arr);
/*
   Purpose: 
      Returns a list of features of the specified solid and the array of
      unsigned int values representing their statuses. Each item in
      status array represents the status of corresponding feature as a
      bit flag. Bit flag contains as many status values as feature can
      have at the same time.
      Status values are among 
      PRO_FEAT_STAT_... defined in ProFeature.h

   Input Arguments:
      solid                 - The solid

   Output Arguments:
      p_feat_id_array       - An array of feature ids. The function allocates
                              the memory for this argument. Free this array
                              using <b>ProArrayFree()</b>.
      p_status_bitflag_arr  - An array of feature statuses. The function
                              allocates the memory for this argument.Free this
                              array using <b>ProArrayFree()</b>.
             
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the features. 
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

   See Also:
      ProArrayFree()

*/


extern ProError ProSolidFeatstatusGet (ProSolid  solid,
                                       int           **p_feat_id_array,
                                       ProFeatStatus **p_status_array,
                                       int            *p_num_features);
/*
   Purpose: 
      Returns a list of features of the specified solid and their statuses
      (PRO_FEAT_ACTIVE, PRO_FEAT_SUPPRESSED, or PRO_FEAT_PROG_SUPPRESSED).

   Input Arguments:
      solid               - The solid

   Output Arguments:
      p_feat_id_array     - An array of features (preallocated by a call to
                            <b>ProArrayAlloc()</b>). If you reuse the array,
                            new elements will be appended to the existing
                            elements unless you reset the array size to 0 with
                            ProArraySizeSet.
      p_status_array      - An array of feature statuses (preallocated by
                            a call to <b>ProArrayAlloc()</b>). If you reuse
                            the array, new elements will be appended to the
                            existing elements unless you reset the array size
                            to 0 with ProArraySizeSet.
      p_num_features      - The size of the above arrays
       
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the features. 
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProSolidFeatstatusSet   (ProSolid  solid,
                                         int           *feat_id_array,
                                         ProFeatStatus *status_array,
                                         int            num_features,
                                         ProBoolean     can_fix);
/*
   Purpose: 
      Assigns the feature order and status of the specified solid based on 
      the input (PRO_FEAT_ACTIVE, PRO_FEAT_SUPPRESSED, or 
      PRO_FEAT_PROG_SUPPRESSED).
<p>
      NOTES:
<ul>
          <li>You can change the status of active or user-suppressed 
              features only.
          <li>Upon assignment of the order and status, the system regenerates
           the model. If it fails, the model is restored to its original
           state.
</ul>

   Input Arguments:
      solid               - The solid.
      feat_id_array       - An array of features. 
      status_array        - An array of feature statuses. If this is NULL,
                            the statuses are not changed.
      num_features        - The size of the above arrays.
      can_fix             - If regeneration fails, invoke the Fix Model user
                            interface. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully assigned the feature 
                             order and statuses.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - There were regeneration errors. The 
                             <i>p_errors</i> argument supplies a detailed
                             description of the errors.
*/

extern ProError ProSolidFeatstatusWithoptionsSet (ProSolid  solid,
                                                  int      *feat_id_array,
                                                  int      *status_array,
                                                  int       flags);
/*
   Purpose: 
      Assigns the feature order and status of the specified solid based on 
      the input (PRO_FEAT_ACTIVE, PRO_FEAT_SUPPRESSED, or 
      PRO_FEAT_PROG_SUPPRESSED).
<p>
      NOTES:
<ul>
          <li>You can change the status of active or user-suppressed 
              features only.
          <li>Upon assignment of the order and status, the system regenerates
           the model. If it fails, the model is restored to its original
           state.
</ul>

   Input Arguments:
      solid               - The solid.
      feat_id_array       - A ProArray of features. 
      status_array        - A ProArray of feature statuses in the form of bit
                            mask statuses like PRO_FEAT_STAT_*. If this is NULL,
                            the statuses are not changed. 
      flags               - The regeneration control flags. Pass as bitmask containing 
                            one or more of the bit flags PRO_REGEN* defined in ProSolid.h

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully assigned the feature 
                             order and statuses.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - There were regeneration errors. The 
                             <i>p_errors</i> argument supplies a detailed
                             description of the errors.
                             
   See Also:
       ProArrayAlloc()
       ProArrayObjectAdd()
       ProArrayFree()    
                             
*/

extern ProError  ProSolidDispoutlineGet (ProSolid solid, 
                                         ProMatrix transform,
                                         double r_outline_points[2][3]);
/*
  Purpose:
     Computes the display outline of a solid.  The display outline would be
     used to calculate how to refit the model in a window, the extents of a
     drawing view, or the coordinates of a note free attachment.

  Input Arguments:
     solid        - The solid whose outline is to be computed.
     transform    - The orientation matrix (with respect to the base 
                    coordinate system) to which the outline is to be computed.

  Output Arguments:
     r_outline_points - The two points that define the display outline of the
                        solid in the specified orientation.
  Return Values:
     PRO_TK_NO_ERROR      - The function successfully computed the 
                            outline.
     PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

  See Also:
     ProNoteAttachFreeGet()
     ProNoteAttachFreeSet()
*/

extern ProError ProSolidOutlineCompute (    ProSolid              p_solid, 
                                            ProMatrix             matrix,
                                            ProSolidOutlExclTypes excludes[],
                                            int                   num_excludes,
                                            Pro3dPnt r_outline_points[2]);
/*
  Purpose:
     Computes the outline of a solid.  This outline can include external
     datums.

  Input Arguments:
     p_solid      - The solid whose outline is to be computed.
     matrix       - The orientation matrix (with respect to the base coordinate 
                    system) to which the outline is to be computed.
     excludes     - An array of types to exclude from outline computation
                    (such as nongeometric features). If you set this to
                    PRO_OUTL_EXC_NOT_USED, nothing is excluded.
     num_excludes - The number of exclusions in the array.

  Output Arguments:
     r_outline_points - The two points that define the boundary box of the
                        solid in the specified orientation.
  Return Values:
     PRO_TK_NO_ERROR      - The function successfully computed the 
                            outline.
     PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
*/

extern ProError ProSolidOutlineGet (ProSolid  p_solid,
                                    Pro3dPnt  r_outline_points[2]);
/*
  Purpose:
     Retrieves the regeneration outline of a solid, with respect to the 
     base coordinate system orientation.  The regeneration outline does 
     not include datums, annotations, or other non-geometric items.
     This outline is used to compute part accuracy.

  Input Arguments:
     p_solid          - The solid whose outline is to be determined 

  Output Arguments:
     r_outline_points - The two points that define the boundary box
                         of the solid, in the orientation of the base
                         coordinate system

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the 
                            information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
     PRO_TK_GENERAL_ERROR - A general error occurred and the function
                            failed.
*/

typedef enum 
{
  PRO_ACCURACY_RELATIVE = 1,
  PRO_ACCURACY_ABSOLUTE = 2
} ProAccuracyType;

extern ProError ProSolidAccuracySet (ProSolid         solid,
                                     ProAccuracyType  type,
                                     double           accuracy);
/*
  Purpose:
     Sets either the relative or absolute accuracy of a part or an assembly.
<p>
     NOTE: 
<p>
     This function does not regenerate the solid. You must
     perform this action separately.
 
  Input Arguments:
     solid    - The solid whose accuracy is to be changed.
     type     - The relative or absolute accuracy.
     accuracy - If you are setting the relative accuracy, this number 
                has no dimension because the accuracy will be scaled
                by the part size. If you are setting absolute accuracy,
                the number is based on the solid units.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully set the accuracy of
                          the solid.
     PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/ 

extern ProError ProSolidAccuracyGet (ProSolid         solid,
                                     ProAccuracyType *r_type,
                                     double          *r_accuracy);
/*
  Purpose:
     Retrieves the accuracy of the specified part or assembly.
 
  Input Arguments:
     solid   - The part or assembly
 
  Output Arguments:
     r_type     - The type of accuracy
     r_accuracy - The accuracy value
 
  Return Values:
     PRO_TK_NO_ERROR      - The function successfully retrieved the
                            information.
     PRO_TK_BAD_INPUTS    - The input argument is invalid.
*/

extern ProError ProSolidRayIntersectionCompute ( ProMdl model,
                                            double         aperture_radius,
                                            ProRay*        p_ray,
                                            ProSelection** p_sel_arr,
                                            int*           p_count
                                         );
/*
   Purpose: Returns a list of ray intersections with a model.
            The function computes the intersection points of both the
            original ray and its "negative" with the geometry of the
            model.  The output array is sorted in order of increasing
            signed distance.  It is the responsibility of the user
            to find whether the ray is inside or outside the model.
<p>
            If a ray hits in the middle of a face on the model,
            the face is selected.  If however, the intersection point
            is very close (within an internally determined selection
            aperture) to an edge is also selected.  Thus, more than
            one entry of type surface or edge in the <i>ProSelection</i>
            array may correspond to one actual piercing of the model by
            the ray.
<p>
            In an assembly, each part is processed separately.
            Therefore, if two coincident mating faces are hit, these
            will be recorded as two separate hits, because they are
            on two distinct faces.
<p> 
            You can set the default value of the <i>aperture_radius</i> 
            using the configuration file option "pick_aperture_radius value"
            (the default is 7). This is the radius, in pixels, that controls
            whether a ray is close enough to an edge for it to be
            counted as a ray hit.


   Input Arguments:
      model           - The part or assembly through which the ray is shot.
      aperture_radius - The value of <i>pick_aperture_radius</i>. If the
                        value is less than or equal to 0.0, the function 
                        uses the default value (7.0), or the current value 
                        in the configuration file.
      p_ray           - The starting point of the ray and the
                        direction vector (defined as
                        X,Y,Z).  The vector is normalized
                        within the function before it is being used.

   Output Arguments:
      p_sel_arr - An array of <i>ProSelection</i>, one for each selection made.
                  The geometry is in terms of the coordinate system of
                  the part being intersected, not the parent assembly.
                  The function allocates the memory for this argument,
                  and reuses it on subsequent calls.

      p_count   - The number of selections in <i>p_sel_arr</i>. If the ray 
                  does not intersect the model, <i>p_count</i> is 0.

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the information.
      PRO_TK_E_NOT_FOUND - No objects were found in the workspace.
      PRO_TK_BAD_INPUTS - One or more of the invalid arguments are invalid.
*/


extern ProError ProSolidFamtableCheck (ProSolid       handle);

/* 
   Purpose: Determines whether the specified solid has a family table,
            and if that family table is valid and/or empty.     

   Input Arguments:
      handle            -  The <i>ProSolid</i> to check. 

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR         - The family table is found and is not empty.
      PRO_TK_BAD_INPUTS       - The input argument is invalid.
      PRO_TK_E_NOT_FOUND      - The family table was not found for the 
                                specified owner.
      PRO_TK_EMPTY            - The family table is found and is empty.
*/

extern ProError ProSolidMassPropertyGet ( ProSolid solid,
                                          ProName  csys_name,
                                          ProMassProperty* mass_prop );
/*
   Purpose:  Calculates the mass properties of a part or an assembly in
             the specified coordinate system.

   Input Arguments:
      solid - The handle to a part or an assembly.
      csys_name - The name of the coordinate system. If this is NULL, the
                  function uses the default coordinate system.

   Output Arguments:
      mass_prop - The mass property.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the 
                             information.
      PRO_TK_BAD_INPUTS    - The solid handle is invalid.
      PRO_TK_E_NOT_FOUND   - The specified coordinate system was not found.
      PRO_TK_GENREAL_ERROR - A general error occurred and the function
                             failed.

*/

extern ProError ProSolidFailedFeatsList (ProSolid    solid,
                                         int   **r_failed_feat_ids);
 
/*
 DEPRECATED: Since Wildfire 5.0
 SUCCESSORS: ProSolidFailedfeaturesList
 Purpose: Retrieves the list of failed features in the 
          specified part or assembly. 
<p><b>
          NOTE: 
</b><p>
          This function is deprecated.  Use ProSolidFailedfeaturesList()
          to get the list of failed, child of failed and child of external
          failed feature ids.  In Resolve mode pass NULL each 
          for "co_failed_ids" and "co_x_failed_ids" arguments.
 
 
  Input Arguments:
     solid              - The part or assembly.
 
  Output Arguments:
     r_failed_feat_ids  - An array of failed feature identifiers.
                          You must preallocate this array 
                          using the function <b>ProArrayAlloc()</b>.
 
  Return Values:
     PRO_TK_NO_ERROR    - The failed features were found and returned.
     PRO_TK_E_NOT_FOUND - No failed feature was found.
     Other              - The input was invalid.

  See Also:
     ProArrayAlloc()
*/

typedef ProError (*ProSolidRegeneratePreAction) (ProSolid    solid_handle,
                                                 ProFeature *feat_handle);

/*
  Purpose: This is the notification function called before 
           regenerating a solid.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type 
           PRO_SOLID_REGEN_PRE.

  Input Arguments:
     solid_handle     -  The handle to the solid about to be regenerated
     feat_handle      -  The start feature for regeneration

  Output Arguments:
     None

   Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

typedef ProError (*ProSolidRegeneratePostAction) (ProSolid    solid_handle,
                                                  ProFeature *feat_handle,
                                                  ProError    status);

/*
  Purpose: This is the notification function called after 
           regeneration of a solid.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type 
           PRO_SOLID_REGEN_POST.

  Input Arguments:
     solid_handle     -  The handle to the solid that was regenerated
     feat_handle      -  The feature where regeneration started
     status           -  The internal status generated as a result of
                         regeneration

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

extern ProError ProSolidProjectPoint ( ProSolid     p_handle,
                                       Pro3dPnt     xyz,
                                       double       tolerance,
                                       ProSurface   *p_surface,
                                       ProUvParam   uv_point );
/*
   Purpose: Given a solid, a point, and a maximum distance, this function  
            finds a surface from the solid within the maximum distance, and
            returns the UV point of the projection of the point to that 
            surface.  This does not necessarily find the nearest surface on
            the solid; any surface within the tolerance could be returned.
<p><b>
            NOTE:  
</b><p>
            This function supports parts only, not assemblies.

   Input Arguments:
         p_handle  - Solid handle.
         xyz       - The point to project.
         tolerance - Maximum allowed distance from the point to the solid.

   Output Arguments:
         p_surface - Surface where the point is projected.
         uv_point  - The corresponding UV point on the surface.

  Return Values:
      PRO_TK_NO_ERROR - The function found a point on a surface within
                        the tolerance.
      PRO_TK_NOT_EXIST - The function failed to find a point on a surface 
                        within the tolerance.
      PRO_TK_BAD_INPUTS - One or more of the Input arguments being invalid.
                 
      
*/

extern ProError ProSolidToleranceGet ( ProSolid         solid,
                                       ProToleranceType type,
                                       int              n_decimals,
                                       double           *tolerance);
/*
   Purpose: Retreives the tolerance value for the specified solid, for
            the specified number of decimal places.

   Input Arguments:
        solid      - The solid handle.
        type       - The tolerance type.
        n_decimals - The number of decimal places used to identify 
                     the tolerance.

   Output Arguments:
        tolerance  - The tolerance, at the specified number of decimal places.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_BAD_INPUTS    - The solid handle is invalid.
      PRO_TK_GENREAL_ERROR - A general error occurred and the function
                             failed.

*/

extern ProError ProSolidToleranceSet ( ProSolid         solid,
                                       ProToleranceType type,
                                       int              n_decimals,
                                       double           tolerance);
/*
   Purpose: Sets the solid's tolerance, at the specified number of 
            decimal places, to the specified value.

   Input Arguments:
        solid      - The solid handle.
        type       - The tolerance type.
        n_decimals - The number of decimal places used to identify
                     the tolerance.
        tolerance  - The tolerance, at the specified number of decimal places.
 
   Output Arguments:
        none

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully set the tolerance.
      PRO_TK_BAD_INPUTS    - The solid handle is invalid.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function
                             failed.

*/

extern ProError ProSolidTolclassLoad (ProSolid p_model, ProName name);

/*
   Purpose:     This will load a tolerance class for Hole or Shaft ISO tols.

   Input Arguments:
      p_model           - The model for which the tolerance should be loaded.
      name              - The letter(s) indicating the tolerance class, with
                          Hole tolerances CAPITALIZED and Shaft tolerances in
                          lowercase.
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The tolerance table loaded successfully.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND- Creo Parametric TOOLKIT could not find the table.
*/

extern ProError ProSolidModelclassGet(ProSolid solid,
                                      ProModelClass *model_class);
/*
   Purpose: Gets the ISO/DIN model class type for a solid model.

   Input Arguments:
     solid           - The solid model.

   Output Arguments:
     model_class     - The model class.

   Return Values:
     PRO_TK_NO_ERROR - The class was retrieved successfully.
     PRO_TK_BAD_INPUTS - The solid was invalid or the class was NULL.
     PRO_TK_BAD_CONTEXT - The solid was not using ISO/DIN tolerance tables.
*/

extern ProError ProSolidModelclassSet(ProSolid solid,
                                      ProModelClass model_class);
/*
   Purpose: Sets the ISO/DIN model class type for a solid model.

   Input Arguments:
     solid          - The solid model.
     model_class    - The model class.

   Output Arguments:
     None.

   Return Values:
     PRO_TK_NO_ERROR - The class was set successfully.
     PRO_TK_BAD_INPUTS - The solid or class was invalid.
     PRO_TK_CANT_MODIFY - The model was locked.
     PRO_TK_BAD_CONTEXT - The model was not using ISO/DIN tolerance tables.
*/    

typedef struct pro_solid_retr_errs*  ProSolidretrievalerrs;

extern ProError  ProSolidRetrievalErrorsGet (ProSolid solid,
                                             ProSolidretrievalerrs* errs);
/*
   Purpose: Returns the data structure containing errors that 
         occurred during retrieval.

         <p><b>
         Notes:
         <p></b>
         The retrieval error information is not persistent and should be 
         accessed immediately after the call to ProMdlRetrieve or an 
         equivalent retrieval function.
         <p>
         Creo Parametric TOOLKIT currently does not return specific information from
         the retrieval errors structure - this is reserved for 
         future expansion.

   Input Arguments:
     solid          - The top-level solid model that was retrieved.

   Output Arguments:
     errs           - Pointer to the retrieval errors.

   Return Values:
     PRO_TK_NO_ERROR - Errors were found for this model.
     PRO_TK_E_NOT_FOUND - Errors were not found for this model.
     PRO_TK_BAD_INPUTS - The inpurt argument is invalid.

   See Also:
    ProMdlRetrieve()
    ProMdlMultipleRetrieve()
    ProAssemblySimprepRetrieve()
*/

extern ProError  ProSolidRetrievalerrsCount (ProSolidretrievalerrs errs,
                                             int* count);
/*
   Purpose: Returns the number of errors that occurred during retrieval.

   Input Arguments:
     errs           - The retrieval errors structure.

   Output Arguments:
     count          - The number of errors found.

   Return Values:
     PRO_TK_NO_ERROR - The function successfully returned the data.
     PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProSolidDefaulttextheightGet (ProSolid solid,
                                              double* default_text_height);
/*
    Purpose: Obtains the default text height used for text in annotations and
             dimensions in the solid model.

    Input Arguments:
        solid - The solid model.

    Output Arguments:
        default_text_height - The default text height.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


typedef enum
{
     PRO_SOLID_REGENERATED,
     PRO_SOLID_NEEDS_REGENERATION,
     PRO_SOLID_FAILED_REGENERATION,
     PRO_SOLID_CONNECT_FAILED     /* The model has been successfully 
                                     regenerated, but the mechanism connect of 
                                     the model has failed. This status is 
                                     applicable only for assemblies with movable
                                     components. */
} ProSolidRegenerationStatus;

extern ProError ProSolidRegenerationstatusGet (
                                      ProSolid                    solid,
                                      ProSolidRegenerationStatus* regen_status);
/*
    Purpose: Returns the regeneration status of the solid model. This is
             analogous to the regen status indicator 
             (Green/Disconnected/Yellow/Red) in the Creo Parametric UI.
             <P>
             <B>Note:</B> Models with certain contents, like circular
             references or assembly analysis features, will never return a
             PRO_SOLID_REGENERATED status. So this flag should not provide an
             absolute restriction; if the flag remains at the
             PRO_SOLID_NEEDS_REGENERATION status through two successful 
             regenerations, the model could be considered up to date.

    Input Arguments:
        solid - The solid model.

    Output Arguments:
        regen_status - The current regeneration status for the solid model.

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProSolidRegenerate()
*/

extern ProError ProSolidFailedfeaturesList (ProSolid    solid,
                                            int       **failed_ids,
                                            int       **co_failed_ids,
                                            int       **co_x_failed_ids);
/*
 Purpose: Retrieves the list of failed and/or child of failed and/or 
          child of external failed features in the specified part or assembly.

 Input Arguments:
     solid            - The part or assembly.
 
 Output Arguments:
     failed_ids       - An array of failed feature identifiers.
                        The function allocates the memory for this argument.
                        Free this array using <b>ProArrayFree()</b>.
                        Pass NULL if not requesting this type.
     co_failed_ids    - An array of child of failed feature identifiers.
                        The function allocates the memory for this argument.
                        Free this array using <b>ProArrayFree()</b>.
                        Pass NULL if not requesting this type.
     co_x_failed_ids  - An array of child of external failed feature identifiers.
                        The function allocates the memory for this argument.
                        Free this array using <b>ProArrayFree()</b>.
                        Pass NULL if not requesting this type.                       
                  

 Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.          
     PRO_TK_E_NOT_FOUND   - No feature of requested type(s) was found.
     PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
     PRO_TK_GENERAL_ERROR - The function failed.

 See Also:
     ProArrayAlloc()
*/

extern ProError ProSolidToleranceStandardGet(ProSolid p_solid,
                                             ProStandard *p_standard);
/*
   Purpose:  Get the assigned tolerance standard of a solid.

   Input Arguments:
     p_solid         - The <i>ProSolid</i> to get the tol standard for.

   Output Arguments:
     p_standard      - The tolerance standard, NULL not allowed.

   Return Values:
      PRO_TK_NO_ERROR         - Success
      PRO_TK_BAD_INPUTS       - p_solid or p_standard was invalid
*/

extern ProError ProSolidToleranceStandardSet(ProSolid p_solid,
                                             ProStandard new_standard);

/*
   Purpose:  Set the assigned tolerance standard of a solid.
             Note that in the regular UI, this operation asks whether
             to regenerate the solid.  This function will not
             itself perform regeneration.

   Input Arguments:
     p_solid         - The <i>ProSolid</i> to set the tol standard for.
     new_standard    - The tolerance standard to set.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - Success
      PRO_TK_BAD_INPUTS       - p_solid or new_standard was invalid
      PRO_TK_GENERAL_ERROR    - An error occurred trying to set the standard.
*/

extern ProError ProSolidRegenerationIsNoresolvemode (
                        ProBoolean *is_no_resolve);
/*
 Purpose:     Check the current Creo Parametric regeneration mode.

 Input Arguments:
     none

 Output Arguments:
     is_no_resolve         - PRO_B_TRUE if the current Creo Parametric regeneration 
                             mode is No Resolve Mode; PRO_B_FALSE if it is 
                             Resolve Mode.

 Return Values:
     PRO_TK_NO_ERROR       - The function succeeded
     PRO_TK_BAD_INPUTS     - One or more arguments are invalid.
*/

PRO_END_C_DECLS

#endif  /* PROSOLID_H */




