#ifndef PROMECHSPRING_H
#define PROMECHSPRING_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechYDirection.h>
#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef struct pro_spring_prop_simple* ProMechSimpleSpringData;
typedef struct pro_spring_prop_ground* ProMechGroundSpringData;
typedef struct pro_spring_prop_advanced_int* ProMechAdvancedSpringData;

typedef enum {
  PRO_MECH_SPRING_SIMPLE    = 0,
  PRO_MECH_SPRING_GROUND    = 1,
  PRO_MECH_SPRING_ADVANCED  = 2
} ProMechSpringType;

extern ProError  ProMechspringReferencesGet (ProMechItem* item,
				ProMechGeomref** references);
/*
	Purpose: Obtains the spring reference objects.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring.

	Output Arguments:
		references	- ProArray of reference objects.The function allocates memory for 
						this argument. Use ProMechgeomrefProarrayFree() to free it.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechspringTypeGet (ProMechItem* item,
				ProMechSpringType* type);
/*
	Purpose: Obtains the spring type (simple, ground, advanced).

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring.

	Output Arguments:
		type	- The spring type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechspringSimpledataGet (ProMechItem* item,
				ProMechSimpleSpringData* value);
/*
	Purpose: Obtains the simple spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring.

	Output Arguments:
		value	- The simple spring data.  Free this using 
					ProMechsimplespringdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

	See Also:
		ProMechspringTypeGet()
*/

extern ProError  ProMechsimplespringdataTorsionalstiffnessGet (ProMechSimpleSpringData data,
				ProMechExpression value);
/*
	Purpose: Obtains the torsional stiffness.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The simple spring data.

	Output Arguments:
		value	- The torsional stiffness.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsimplespringdataFree (ProMechSimpleSpringData data);
/*
	Purpose: Frees the memory for a Creo Simulate simple spring data handle.

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

extern ProError  ProMechspringGrounddataGet (ProMechItem* item,
				ProMechGroundSpringData* value);
/*
	Purpose: Obtains the 'to ground' spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring.

	Output Arguments:
		value	- The 'to ground' spring data.  Free this using 
					ProMechgroundspringdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

	See Also:
		ProMechspringTypeGet()
*/

extern ProError  ProMechgroundspringdataPropertiesGet (ProMechGroundSpringData data,
				int* property_id);
/*
	Purpose: Obtains the spring properties id for the 'to ground' spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The 'to ground' spring data.

	Output Arguments:
		property_id	- The spring properties id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechgroundspringdataCsysGet (ProMechGroundSpringData data,
				ProMechGeomref* csys);
/*
	Purpose: Obtains the coordinate system for the to ground spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The 'to ground' spring data.

	Output Arguments:
		csys	- The reference coordinate system.  Free this using 
					ProMechgeomrefFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechgroundspringdataFree (ProMechGroundSpringData data);
/*
	Purpose: Frees the memory for a Creo Simulate ground spring data handle.

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

extern ProError  ProMechspringAdvanceddataGet (ProMechItem* item,
				ProMechAdvancedSpringData* value);
/*
	Purpose: Obtains the advanced spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring.

	Output Arguments:
		value	- The advanced spring data.  Free this using 
				ProMechadvancedspringdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

    See Also:
		ProMechspringTypeGet()
*/

extern ProError  ProMechadvancedspringdataPropertiesGet (ProMechAdvancedSpringData data,
				int* property_id);
/*
	Purpose: Obtains the spring properties id for the advanced spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The advanced spring data.

	Output Arguments:
		property_id	- The spring properties id. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechadvancedspringdataYdirectionGet (ProMechAdvancedSpringData data,
				ProMechYDirection* ydir);
/*
	Purpose: Obtains the Orientation handle for the advanced spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The advanced spring data.

	Output Arguments:
		ydir	- The Orientation handle.  Free this using ProMechydirectionFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechadvancedspringdataRotationGet (ProMechAdvancedSpringData data,
				double* rotation);
/*
	Purpose: Obtains the additional rotation value of the advanced spring data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The advanced spring data.

	Output Arguments:
		rotation	- The additional rotation (in degrees). 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechadvancedspringdataFree (ProMechAdvancedSpringData data);
/*
	Purpose: Frees the memory for a Creo Simulate advanced spring data handle.

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

extern ProError  ProMechsimplespringdataExtensionalstiffnessGet (ProMechSimpleSpringData data,
                                ProMechExpression value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechsimplespringdataExtensionalstiffnessValueGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechsimplespringdataExtensionalstiffnessValueGet() instead.
             <p>
             Obtains the extensional stiffness.
             Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The simple spring data.

        Output Arguments:
                value   - The extensional stiffness.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsimplespringdataExtensionalstiffnessValueGet (
                                             ProMechSimpleSpringData data,
                                             ProMechValue* value);
/*
    Purpose: Obtains the extensional stiffness.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechspringReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the spring reference objects.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The spring.
        references - ProArray of reference objects.

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

extern ProError ProMechspringSimpledataSet (ProMechItem* item, ProMechSimpleSpringData value);
/*
    Purpose: Sets the simple spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The spring.
        value - The simple spring data.

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
                               unable to set principal stiffness units.
*/

extern ProError ProMechsimplespringdataTorsionalstiffnessSet (ProMechSimpleSpringData data, ProMechExpression value);
/*
    Purpose: Sets the torsional stiffness.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The simple spring data.
        value - The torsional stiffness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplespringdataExtensionalstiffnessSet (ProMechSimpleSpringData data, ProMechExpression value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechsimplespringdataExtensionalstiffnessValueSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechsimplespringdataExtensionalstiffnessValueSet() instead.
             <p>
             Sets the extensional stiffness.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The simple spring data.
        value - The extensional stiffness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplespringdataExtensionalstiffnessValueSet (
                                            ProMechSimpleSpringData data,
                                            ProMechValue        value);
/*
    Purpose: Sets extensional stiffness.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplespringdataAlloc (ProMechSimpleSpringData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate simple spring data handle.

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

extern ProError ProMechspringGrounddataSet (ProMechItem* item, ProMechGroundSpringData value);
/*
    Purpose: Sets the 'to ground' spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The spring.
        value - The 'to ground' spring data.

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

extern ProError ProMechgroundspringdataPropertiesSet (ProMechGroundSpringData data, int property_id);
/*
    Purpose: Sets the spring properties id for the 'to ground' spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The 'to ground' spring data.
        property_id - The spring properties id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechgroundspringdataCsysSet (ProMechGroundSpringData data, ProMechGeomref csys);
/*
    Purpose: Sets the coordinate system for the to ground spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The 'to ground' spring data.
        csys - The reference coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechgroundspringdataAlloc (ProMechGroundSpringData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate ground spring data handle.

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

extern ProError ProMechspringAdvanceddataSet (ProMechItem* item, ProMechAdvancedSpringData value);
/*
    Purpose: Sets the advanced spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The spring.
        value - The advanced spring data.

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

extern ProError ProMechadvancedspringdataPropertiesSet (ProMechAdvancedSpringData data, int property_id);
/*
    Purpose: Sets the spring properties id for the advanced spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The advanced spring data.
        property_id - The spring properties id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechadvancedspringdataYdirectionSet (ProMechAdvancedSpringData data, ProMechYDirection ydir);
/*
    Purpose: Sets the Orientation handle for the advanced spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The advanced spring data.
        ydir - The Orientation handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechadvancedspringdataRotationSet (ProMechAdvancedSpringData data, double rotation);
/*
    Purpose: Sets the additional rotation value of the advanced spring data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The advanced spring data.
        rotation - The additional rotation (in degrees).

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechadvancedspringdataAlloc (ProMechAdvancedSpringData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate advanced spring data 
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

#endif /* PROMECHSPRING_H */
