#ifndef PROMECHMASS_H
#define PROMECHMASS_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechItem.h>
#include <ProMechGeomref.h>
#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_MASS_NONE             = PRO_VALUE_UNUSED,

  PRO_MECH_MASS_SIMPLE           = 0,
  PRO_MECH_MASS_ADVANCED         = 1,
  PRO_MECH_MASS_COMPONENT        = 2,
  PRO_MECH_MASS_COMP_AT_POINT    = PRO_MECH_MASS_COMPONENT,
  PRO_MECH_MASS_COMP_DISTRIBUTED = 3
}ProMechMassType;

typedef enum 
{
  PRO_MECH_MASS_DISTR_NONE     = PRO_VALUE_UNUSED,

  PRO_MECH_MASS_DISTR_AT_POINT = 1,
  PRO_MECH_MASS_DISTR_TOTAL    = 2,
  PRO_MECH_MASS_DISTR_PER_UNIT = 3
}ProMechMassDistribution;

typedef struct pro_mass_prop_simple* ProMechSimpleMassData;
typedef struct pro_mass_prop_advanced* ProMechAdvancedMassData;
typedef struct pro_mass_prop_component* ProMechComponentMassData;

extern ProError  ProMechmassReferencesGet (ProMechItem* item,
				ProMechGeomref** references);
/*
	Purpose: Obtains the mass reference objects.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass.

	Output Arguments:
		references	- ProArray of reference objects.The function allocates memory 
						for this argument. Use ProMechgeomrefProarrayFree() to free it.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechmassDistributionGet (ProMechItem* item,
				ProMechMassDistribution* type);
/*
	Purpose: Obtains the mass distribution type.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass.

	Output Arguments:
		type	- The distribution type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechmassTypeGet (ProMechItem* item,
				ProMechMassType* type);
/*
	Purpose: Obtains the mass type (simple, advance, component).

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass.

	Output Arguments:
		type	- The mass type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechmassSimpledataGet (ProMechItem* item,
				ProMechSimpleMassData* value);
/*
	Purpose: Obtains the simple mass data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass.

	Output Arguments:
		value	- The simple mass data.  Free this using ProMechsimplemassdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                                       unable to convert mass data to principal units.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
		ProMechmassTypeGet()
*/

extern ProError  ProMechsimplemassdataMassGet (ProMechSimpleMassData data,
				ProMechExpression mass);
/*
	Purpose: Obtains the mass value for the simple mass data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The simple mass data.

	Output Arguments:
		mass	- The mass.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsimplemassdataFree (ProMechSimpleMassData data);
/*
	Purpose: Frees the memory for a Creo Simulate simple mass data handle.

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

extern ProError  ProMechmassAdvanceddataGet (ProMechItem* item,
				ProMechAdvancedMassData* value);
/*
	Purpose: Obtains the advanced mass data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass.

	Output Arguments:
		value	- The advanced mass data.  Free this using 
					ProMechadvancedmassdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
		ProMechmassTypeGet()
*/

extern ProError  ProMechadvancedmassdataCsysGet (ProMechAdvancedMassData data,
				ProMechGeomref* csys);
/*
	Purpose: Obtains the reference coordinate system for the advanced mass data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The advanced mass data.

	Output Arguments:
		csys	- The coordinate system.  Free this using ProMechgeomrefFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechadvancedmassdataPropertiesGet (ProMechAdvancedMassData data,
				int* properties_id);
/*
	Purpose: Obtains the mass properties id from the advanced mass data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The advanced mass data.

	Output Arguments:
		properties_id	- The mass properties id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechadvancedmassdataFree (ProMechAdvancedMassData data);
/*
	Purpose: Frees the memory for a Creo Simulate advanced mass data handle.

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

extern ProError  ProMechmassComponentdataGet (ProMechItem* item,
				ProMechComponentMassData* value);
/*
    Purpose: Obtains the component mass data.

	Note: This function operates on masses of type PRO_MECH_MASS_COMP_AT_POINT and PRO_MECH_COMP_DISTRIBUTED.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass.

	Output Arguments:
		value	- The component mass data.  Free this using 
					ProMechcomponentmassdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

     See Also:
		ProMechmassTypeGet()
*/

extern ProError  ProMechcomponentmassdataComponentGet (ProMechComponentMassData data,
				ProMechGeomref* component);
/*
	Purpose: Obtains the reference component for the component mass data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The component mass data.  

	Output Arguments:
		component	- The component.  Free this using ProMechgeomrefFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechcomponentmassdataFree (ProMechComponentMassData data);
/*
	Purpose: Frees the memory for a Creo Simulate advanced mass data handle.

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

extern ProError ProMechmassReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the mass reference objects.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mass.
        references - ProArray of reference objects.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
	PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechmassDistributionSet (ProMechItem* item, ProMechMassDistribution type);
/*
    Purpose: Sets the mass distribution type.
             Setting this type is necessary for creation of mass object.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mass.
        type - The distribution type. For point references, this type
               should be set to PRO_MECH_MASS_DISTR_AT_POINT.

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

extern ProError ProMechmassSimpledataSet (ProMechItem* item, ProMechSimpleMassData data);
/*
    Purpose: Sets the simple mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mass.
        data - The simple mass data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsimplemassdataMassSet (ProMechSimpleMassData data, ProMechExpression mass);
/*
    Purpose: Sets the mass value for the simple mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The simple mass data.
        mass - The mass.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplemassdataAlloc (ProMechSimpleMassData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate simple mass data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechmassAdvanceddataSet (ProMechItem* item, ProMechAdvancedMassData data);
/*
    Purpose: Sets the advanced mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass.
        data - The advanced mass data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechadvancedmassdataCsysSet (ProMechAdvancedMassData data, ProMechGeomref csys);
/*
    Purpose: Sets the reference coordinate system for the advanced mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The advanced mass data.
        csys - The coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechadvancedmassdataPropertiesSet (ProMechAdvancedMassData data, int properties_id);
/*
    Purpose: Sets the mass properties id from the advanced mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The advanced mass data.
        properties_id - The mass properties id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechadvancedmassdataAlloc (ProMechAdvancedMassData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate advanced mass data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechmassComponentpointdataSet (ProMechItem* item, ProMechComponentMassData data);
/*
    Purpose: Sets the component at point mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass.
        data - The component at point mass data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmassComponentdistributeddataSet (ProMechItem* item, ProMechComponentMassData data);
/*
    Purpose: Sets the component distributed mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass.
        data - The component distributed mass data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcomponentmassdataComponentSet (ProMechComponentMassData data, ProMechGeomref component);
/*
    Purpose: Sets the reference component for the component mass data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The component mass data.
        component - The component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcomponentmassdataAlloc (ProMechComponentMassData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate advanced mass data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/
PRO_END_C_DECLS

#endif /* PROMECHMASS_H */
