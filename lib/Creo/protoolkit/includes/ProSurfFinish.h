#ifndef PROSURFFINISH_H
#define PROSURFFINISH_H



#include <ProObjects.h>
#include <ProSelection.h>
#include <ProDtlsyminst.h>

PRO_BEGIN_C_DECLS

typedef ProError (*ProSurffinishFilterAction) (ProSurfFinish* surf_finish,
                                               ProAppData   application_data);
/*
   Purpose:  The filter action for a surface finish item.

   Input Arguments:
           surf_finish - The surface finish item.
           application_data - Visit user data.

   Output Arguments:
           none

   Return Values:
           PRO_TK_CONTINUE - Do not call the visit action for this item.
           Other - Call the visit action for this item and pass this value
                   to the visit action.
*/

typedef ProError (*ProSurffinishVisitAction) (ProSurfFinish* surf_finish,
                                              ProError filter_status,
                                              ProAppData   appdata);
/*
  Purpose:  The visit action for a surface finish item.

  Input Arguments:
          surf_finish - The surface finish item.
          filter_status - The error return from the filter function.
          appdata - Visit user data.

  Output Arguments:
          none

  Return Values:
          PRO_TK_NO_ERROR - Continue visiting.
          Other - terminate visiting and pass this value as the return status
                  of the visit function.
*/

extern ProError  ProSolidSurffinishVisit (ProSolid solid,
                                          ProSurffinishVisitAction visit_action,
                                          ProSurffinishFilterAction filter_action,
                                          ProAppData appdata);
/*
   Purpose:  Visit the surface finishes in the model.

   Input Arguments:
           solid         - The solid model.
           visit_action  - Action performed for each surface finish visited.
           filter_action - Used to filter the search.  Pass NULL to visit all
                           surface finishes.
           appdata       - User data passed to the visit and filter functions. 

   Output Arguments:
           none

   Return Values:
           PRO_TK_NO_ERROR    - The function succeeded.
           PRO_TK_BAD_INPUTS  - One or more arguments is invalid.
           PRO_TK_E_NOT_FOUND - No surface finish entities were found in the model.
           Other              - Returned from the visit action.

*/

extern ProError  ProSurffinishNameGet (ProSurfFinish*  surface_finish,
                                       ProName name);
/*
   DEPRECATED: Since Creo 4.0
   SUCCESSORS: ProModelitemNameGet
   Purpose:  <b>Note:</b> This function is deprecated
			 Use ProModelitemNameGet instead.
			Retrieve the name of a surface finish annotation.

   Input Arguments:
           surface_finish - The surface finish item.

   Output Arguments:
           name - The name of the surface finish.

   Return Values:
           PRO_TK_NO_ERROR - The function succeeded.
           PRO_TK_BAD_INPUTS - One or more arguments is invalid.
           PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError  ProSurffinishNameSet (ProSurfFinish* surface_finish,
                                       ProName name);
/*
   DEPRECATED: Since Creo 4.0
   SUCCESSORS: ProModelitemNameSet
   Purpose: <b>Note:</b> This function is deprecated
			Use ProModelitemNameSet instead. 
			Set the name of a surface finish annotation.

   Input Arguments:
           surface_finish - The surface finish item.
           name - The new name of the surface finish.


   Output Arguments:
           none

   Return Values:
           PRO_TK_NO_ERROR - The function succeeded.
           PRO_TK_BAD_INPUTS - One or more arguments in invalid.
           PRO_TK_INVALID_NAME - Name is reserved by Creo Parametric.
           PRO_TK_NO_LICENSE - License check failure.
	   PRO_TK_BAD_CONTEXT - the name cannot be varied. 
           PRO_TK_CANT_WRITE - Could not modify the given item because
                               it has read-only access.
*/

extern ProError  ProSurffinishValueGet (ProSurfFinish*  surface_finish,
                                        double* value);
/*
   Purpose:  Retrieve the value of a surface finish annotation. 
             If getting the value of a surface finish based on a symbol, 
             this gets the value of the variable text "roughness_height".  
             Retrieve other values using ProSurffinishDataGet().

   Input Arguments:
           surface_finish - The surface finish item.

   Output Arguments:
           value - The value of the surface finish.

   Return Values:
           PRO_TK_NO_ERROR - The function succeeded.
           PRO_TK_BAD_INPUTS - One or more arguments is invalid.
           PRO_TK_NO_LICENSE - License check failure.
           PRO_TK_BAD_CONTEXT - The surface finish does not have a value 
                                named 'roughness_height' (for symbol 
                                based surface finishes).
           PRO_TK_INVALID_TYPE - The surface finish roughness height is
                                 not a numeric value.
*/

extern ProError  ProSurffinishValueSet (ProSurfFinish* surface_finish,
                                        double value);
/*
   Purpose:  Set the value of a surface finish annotation.
             If setting the value of a surface finish based on a symbol, 
             this sets the value of the variable text "roughness_height".  
             Modify other values using ProSurffinishModify().

   Input Arguments:
           surface_finish - The surface finish item.
           value - The value of the surface finish.


   Output Arguments:
           none

   Return Values:
           PRO_TK_NO_ERROR - The function succeeded.
           PRO_TK_BAD_INPUTS - One or more arguments is invalid.
           PRO_TK_NO_LICENSE - License check failure.
           PRO_TK_BAD_CONTEXT - The surface finish does not have a value 
                                named 'roughness_height' (for symbol 
                                based surface finishes).
           PRO_TK_INVALID_TYPE - The surface finish roughness height is
                                 not a numeric value.
           PRO_TK_CANT_WRITE - Could not modify the given item because
                               it has read-only access.
*/

extern ProError  ProSurffinishReferencesGet (ProSurfFinish* surface_finish,
                                             ProSelection**  surface);
/*
   Purpose:  Retrieve the surfaces referenced by a surface finish annotation.

   Licensing Requirement:
          TOOLKIT for 3D Drawings

   Input Arguments:
           surface_finish - The surface finish item.

   Output Arguments:
           surface - ProArray of surfaces referenced by the surface finish.
		             Free this array using ProSelectionarrayFree().

   Return Values:
           PRO_TK_NO_ERROR - The function succeeded.
           PRO_TK_BAD_INPUTS - The function failed.
           PRO_TK_NO_LICENSE - License check failure.
*/

extern ProError ProSurffinishCreate (ProMdl mdl, 
                                     ProDtlsyminstdata data, 
                                     ProSurfFinish* item);
/*
Purpose: Create a surface finish in the specified model. ProAnnotationShow() should be 
    called after creating the surface finish in order for the surface finish to be 
    displayed.

Licensing Requirement:
          TOOLKIT for 3D Drawings

Input Arguments:
    mdl     - The model handle.
    data      - The symbol instance data.  This data must contain:
		<UL>
		<LI> Zero or more leaders pointing to model surfaces,
		     or, a model surface used for the attachment point. 
		<LI> An annotation plane (for solid owned surface finishes).
		<LI> Optionally, variant texts for the surface finish.
		</UL>
	    Consult the Creo Parametric TOOLKIT user's guide for information about how 
            to find the standard surface finish symbols in order to use 
            them during creation.

Output Arguments:
    item   - The created surface finish.

Return Values:
    PRO_TK_NO_ERROR   - The function successfully created the surface finish.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_INVALID_TYPE  - Invalid type of leader or attachment for 
                           creation of a surface finish.
    PRO_TK_E_FOUND - Leader or attachment to surface which already has a
                     surface finish.
    PRO_TK_GENERAL_ERROR - Can't create the surface finish.
    PRO_TK_NO_LICENSE - License check failure
*/

extern ProError  ProSurffinishDelete (ProSurfFinish* surface_finish);
/* 
   Purpose:  Delete a surface finish.

   Input Arguments:  
           surface_finish - The surface finish item.

   Output Arguments:
           none

   Return Values:
           PRO_TK_NO_ERROR - The function succeeded.
           PRO_TK_BAD_INPUTS - The function failed.
           PRO_TK_NO_LICENSE - License check failure.
           PRO_TK_CANT_WRITE - Could not delete the given item because
                               it has read-only access.
*/

extern ProError ProSurffinishModify (ProSurfFinish* item, 
                                     ProDtlsyminstdata data);
/*
Purpose: Modify a surface finish.

Licensing Requirement:
          TOOLKIT for 3D Drawings

Input Arguments:
    item   - The surface finish.
    data   - The symbol instance data that governs the surface finish.

Output Arguments:
    none
   
Return Values:
    PRO_TK_NO_ERROR   - The function successfully modified the surface finish.
    PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
    PRO_TK_INVALID_TYPE  - Invalid type of leader or attachment for 
                           creation of a surface finish.
    PRO_TK_E_FOUND - Leader or attachment to surface which already has a
                     surface finish other than the one being modified.
    PRO_TK_GENERAL_ERROR - Can't modify the symbol instance.
    PRO_TK_BAD_CONTEXT - The surface finish is not based on a 
                         symbol (and cannot be modified using symbol data).
    PRO_TK_NO_LICENSE - License check failure
    PRO_TK_CANT_WRITE - Could not modify the given item because
                        it has read-only access.
*/

extern ProError ProSurffinishDataGet (ProSurfFinish* item, 
                                      ProDisplayMode mode, 
                                      ProDtlsyminstdata* data);
/*
Purpose: Retrieve the data from a surface finish.

Licensing Requirement:
          TOOLKIT for 3D Drawings

Input Arguments:
    item - The surface finish.
    mode -  The display mode for the symbol retrieval.  
            If PRODISPMODE_NUMERIC, callouts in test will be represented 
            by their values.  If PRODISPMODE_SYMBOLIC, callouts will 
            contain the names of the referenced parameters.

Output Arguments:
    data - The symbol instance data that governs the surface finish.
   
Return Values:
    PRO_TK_NO_ERROR  - The function successfully modified the surface finish.
    PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't modify the symbol instance.
    PRO_TK_BAD_CONTEXT - The surface finish is not based on a symbol 
                         (and cannot be represented using symbol data).
    PRO_TK_NO_LICENSE - License check failure

*/

extern ProError ProSurffinishSrfcollectionGet (ProSurfFinish* surf_finish,
                                               ProCollection* srf_collection);
/*
    Purpose: Obtains the surface collection reference assigned to the surface 
             finish.  
             <B>Note:</B>  surface collections may only be used for surface 
             finishes in annotation elements.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        surf_finish - The surface finish.

    Output Arguments:
        srf_collection - The surface collection assigned to the surface finish. 
                          Free this using ProCollectionFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The surface finish is not in an annotation element 
                             and cannot use a surface collection reference.
        PRO_TK_NO_LICENSE - License check failure.

    See Also:
        ProSurffinishSrfcollectionSet()
        ProSurffinishReferencesGet()
*/

extern ProError ProSurffinishSrfcollectionSet (ProSurfFinish* surf_finish,
                                               ProCollection srf_collection);
/*
    Purpose: Assigns the surface collection references assigned to the surface 
             finish.    This overwrites all current surface finish references.
             <B>Note:</B>  surface collections may only be used for surface 
             finishes in annotation elements.

    Licensing Requirement:
          TOOLKIT for 3D Drawings

    Input Arguments:
        surf_finish - The surface finish.
        srf_collection - The surface collection assigned to the surface finish.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The surface finish is not in an annotation element 
                             and cannot use a surface collection reference.
        PRO_TK_NO_LICENSE - License check failure.
        PRO_TK_CANT_WRITE - Could not modify the given item because
                            it has read-only access.

    See Also:
        ProSurffinishSrfcollectionGet()
*/


PRO_END_C_DECLS

#endif /* PROSURFFINISH_H */
