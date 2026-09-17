#ifndef PROMECHSHELL_H
#define PROMECHSHELL_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef struct pro_shell_prop_simple* ProMechShellSimpleData;
typedef struct pro_shell_prop_advanced* ProMechShellAdvancedData;

typedef enum
{
  PRO_MECH_SHELL_NONE     = PRO_VALUE_UNUSED,

  PRO_MECH_SHELL_SIMPLE   = 0,
  PRO_MECH_SHELL_ADVANCED = 1
}
ProMechShellDataType;

extern ProError  ProMechshellReferencesGet (ProMechItem* item,
				ProMechGeomref** references);
/*
	Purpose: Obtains the references for the shell.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		references	- ProArray of references.  Free this using 
		                  ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellMaterialGet (ProMechItem* item,
				ProName material);
/*
	Purpose: Obtains the material name.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		material	- The material name.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellMaterialIdGet (ProMechItem* item,
				int * matl_id);
/*
	Purpose: Obtains the material id.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		matl_id	- The material id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellTypeGet (ProMechItem* item,
				ProMechShellDataType* type);
/*
	Purpose: Obtains the type of the shell (simple or advanced).

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		type	- The shell type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellSimpledataGet (ProMechItem* item,
				ProMechShellSimpleData* data);
/*
	Purpose: Obtains the simple shell data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		data	- The data.  Free this using ProMechshellsimpleFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

	See Also:
	        ProMechshellTypeGet()
*/

extern ProError  ProMechshellAdvanceddataGet (ProMechItem* item,
				ProMechShellAdvancedData* data);
/*
	Purpose: Obtains the advanced shell data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		data	- The data.  Free this using ProMechshelladvancedFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

	See Also:
	        ProMechshellTypeGet()
*/

extern ProError  ProMechshellsimpleThicknessGet (ProMechShellSimpleData item,
				ProMechExpression thickness);
/*
	Purpose: Obtains the thickness for the shell.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		thickness	- The thickness.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshellsimpleFree (ProMechShellSimpleData data);
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

extern ProError  ProMechshelladvancedShellpropsGet (ProMechShellAdvancedData item,
				int* shell_props_id);
/*
	Purpose: Obtains the shell properties id for this shell.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		shell_props_id	- The shell properties id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshelladvancedMaterialorientGet (ProMechShellAdvancedData item,
				int* material_orient_id);
/*
	Purpose: Obtains the material orientation id for this shell.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell.

	Output Arguments:
		material_orient_id	- The material orientation id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshelladvancedFree (ProMechShellAdvancedData data);
/*
	Purpose: Frees the memory for a Creo Simulate advanced shell data handle.

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

extern ProError ProMechshellReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the references for the shell.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        references - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechshellMaterialIdSet (ProMechItem* item, int matl_id);
/*
    Purpose: Sets the material id for shell.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        matl_id - The Material id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshellSimpledataSet (ProMechItem* item, ProMechShellSimpleData data);
/*
    Purpose: Sets the simple shell data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshellAdvanceddataSet (ProMechItem* item, ProMechShellAdvancedData data);
/*
    Purpose: Sets the advanced shell data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshellsimpleThicknessSet (ProMechShellSimpleData item, ProMechExpression thickness);
/*
    Purpose: Sets the thickness for the shell.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        thickness - The thickness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshellsimpleAlloc (ProMechShellSimpleData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate simple shell data handle.

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

extern ProError ProMechshelladvancedShellpropsSet (ProMechShellAdvancedData item, int shell_props_id);
/*
    Purpose: Sets the shell properties id for this shell.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        shell_props_id - The shell properties id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshelladvancedMaterialorientSet (ProMechShellAdvancedData item, int material_orient_id);
/*
    Purpose: Sets the material orientation id for this shell.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell.
        material_orient_id - The material orientation id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshelladvancedAlloc (ProMechShellAdvancedData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate advanced shell data 
          handle.

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

#endif /* PROMECHSHELL_H */
