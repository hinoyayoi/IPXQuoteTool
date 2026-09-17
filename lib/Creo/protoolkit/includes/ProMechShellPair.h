#ifndef PROMECHSHELLPAIR_H
#define PROMECHSHELLPAIR_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechShell.h>

PRO_BEGIN_C_DECLS

typedef struct pro_shellpair_refs* ProMechShellPairRefs;

typedef enum 
{
  PRO_MECH_SHELL_PAIR_NONE           = PRO_VALUE_UNUSED,

  PRO_MECH_SHELL_PAIR_CONSTANT       = 0,
  PRO_MECH_SHELL_PAIR_VARIABLE       = 1,
  PRO_MECH_SHELL_PAIR_MULTI_CONSTANT = 2  /* OBSOLETED; same as "variable" */
}
ProMechShlpairType;

typedef enum 
{
  PRO_MECH_SHELL_PAIR_PLACEMENT_NONE     = PRO_VALUE_UNUSED,

  PRO_MECH_SHELL_PAIR_PLACEMENT_TOP      = 0,
  PRO_MECH_SHELL_PAIR_PLACEMENT_BOTTOM   = 1,
  PRO_MECH_SHELL_PAIR_PLACEMENT_MIDDLE   = 2,
  PRO_MECH_SHELL_PAIR_PLACEMENT_SELECTED = 3
}
ProMechShlpairPlacementType;

extern ProError  ProMechshellpairMaterialGet (ProMechItem* item,
				ProName material);
/*
	Purpose: Obtains the material name.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair.

	Output Arguments:
		material	- The material name.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellpairMaterialIdGet (ProMechItem* item,
				int * matl_id);
/*
	Purpose: Obtains the material id.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair.

	Output Arguments:
		matl_id	- The material id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellpairMaterialOrientIdGet (ProMechItem* item,
                    int *matl_orient_id);
/*
     Purpose: Obtains the Material Orientation Id.

     Licensing Requirement:
          TOOLKIT for Mechanica

     Input Arguments:
          item - The shell pair.

     Output Arguments:
          matl_orient_id  - The Material Orientation Id.

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
          PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
          PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
          PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellpairReferencesGet (ProMechItem* item,
				ProMechShellPairRefs* refs);
/*
	Purpose: Obtains the references of the shell pair item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair.

	Output Arguments:
		refs	- The references.  Free this using 
		          ProMechshlpairrefsFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshlpairrefsTypeGet (ProMechShellPairRefs item,
				ProMechShlpairType* type);
/*
	Purpose: Obtains the type of the shell pair references..

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair references handle.

	Output Arguments:
		type	- The shell pair refererence type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlpairrefsTopreferencesGet (ProMechShellPairRefs item,
				ProMechGeomref** top_refs);
/*
	Purpose: Obtains the top-side references for the shell pair.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair references handle.

	Output Arguments:
		top_refs	- ProArray of top-side references.  Free this
		                  using ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshlpairrefsBottomreferencesGet (ProMechShellPairRefs item,
				ProMechGeomref** bottom_refs);
/*
	Purpose: Obtains the bottom-side references for the shell pair.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair references handle.

	Output Arguments:
		bottom_refs	- ProArray of bottom-side references. Free this
		                  using ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshlpairrefsPlacementtypeGet (ProMechShellPairRefs item,
				ProMechShlpairPlacementType* placement_type);
/*
	Purpose: Obtains the placement type for the shell pair references.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair references handle.

	Output Arguments:
		placement_type	- The placment type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlpairrefsSelectedplacementGet (ProMechShellPairRefs item,
				ProMechGeomref* placement);
/*
	Purpose: Obtains the selected surface for a SELECTED type of placement for the shell pair.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell pair references handle.

	Output Arguments:
		placement	- The surface.  Free this using 
		                  ProMechgeomrefFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - The shell pair references does not contain this type of placement data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

        See Also:
                ProMechshlpairrefsPlacementtypeGet()
*/

extern ProError  ProMechshlpairrefsExtendAdjacentSurfacesGet (ProMechItem * item,
				                 ProBool* flag);
/*
	Purpose: Obtains the "Extend Adjacent Surfaces" flag of the shell pair.

	Input Arguments:
		item	- The shell pair.

	Output Arguments:
		flag	- The flag.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshlpairrefsFree (ProMechShellPairRefs data);
/*
	Purpose: Frees the memory for a Creo Simulate simple shell data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechshellpairMaterialOrientIdSet (ProMechItem* item, int matl_orient_id);
/*
    Purpose: Sets the Material Orientation Id of the shell pair item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair.
        matl_orient_id - The Material Orientation Id. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechshellpairMaterialIdSet (ProMechItem* item, int matl_id);
/*
    Purpose: Sets the material id of the shell pair item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair.
        matl_id - The material id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshellpairReferencesSet (ProMechItem* item, ProMechShellPairRefs refs);
/*
    Purpose: Sets the references of the shell pair item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair.
        refs - The references. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechshlpairrefsTypeSet (ProMechShellPairRefs item, ProMechShlpairType type);
/*
    Purpose: Sets the type of the shell pair references..

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair references handle.
        type - The shell pair refererence type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlpairrefsTopreferencesSet (ProMechShellPairRefs item, ProMechGeomref* top_refs);
/*
    Purpose: Sets the top-side references for the shell pair.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair references handle.
        top_refs - ProArray of topside references. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechshlpairrefsBottomreferencesSet (ProMechShellPairRefs item, ProMechGeomref* bottom_refs);
/*
    Purpose: Sets the bottom-side references for the shell pair.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair references handle.
        bottom_refs - ProArray of bottomside references. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechshlpairrefsPlacementtypeSet (ProMechShellPairRefs item, ProMechShlpairPlacementType placement_type);
/*
    Purpose: Sets the placement type for the shell pair references.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair references handle.
        placement_type - The placment type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlpairrefsSelectedplacementSet (ProMechShellPairRefs item, ProMechGeomref placement);
/*
    Purpose: Sets the selected surface for a SELECTED type of placement for the shell pair.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair references handle.
        placement - The surface. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechshlpairrefsPlacementtypeSet()
*/

extern ProError ProMechshlpairrefsExtendAdjacentSurfacesSet (ProMechItem * item,
                                                             ProBool       flag);
/*
    Purpose: Sets the "Extend Adjacent Surfaces" flag for the shell pair.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell pair.
        flag - The flag. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshlpairrefsAlloc (ProMechShellPairRefs* data);
/*
    Purpose: Allocates the memory for a Creo Simulate lsimple shell data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/


PRO_END_C_DECLS

#endif /* PROMECHSHELLPAIR_H */
