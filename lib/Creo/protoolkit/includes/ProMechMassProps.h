#ifndef PROMECHMASSPROPS_H
#define PROMECHMASSPROPS_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechItem.h>
#include <ProMechMatrix.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_MASSPROPS_MASS    = 0,  /* ProMechExpression */

  PRO_MECH_MASSPROPS_MOMENTS = 1   /* ProMechMatrix (3x3, symmetrical)
                                     [ Ixx  Ixy  Ixz ]
                                     [      Iyy  Iyz ]
                                     [           Izz ]
                                   */
}
ProMechMasspropsPropertyType;

typedef double ProMechMassMoments[6];  /* deprecated */

extern ProError  ProMechmasspropsDescriptionGet (ProMechItem* item,
				ProComment description);
/*
	Purpose: Obtains the description of the mass property object.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass property.

	Output Arguments:
		description	- The description.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechmasspropsMassGet (ProMechItem* item,
				double* mass);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechMasspropsExpressionGet
	Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechMasspropsExpressionGet() instead.
                 <p>
                 Obtains the mass value of the mass property object.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass property.

	Output Arguments:
		mass	- The mass.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechmasspropsMomentsGet (ProMechItem* item,
				ProMechMassMoments moments);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechMasspropsMatrixGet
	Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechMasspropsMatrixGet() instead.
                 <p>
                 Obtains the moments of intertia of the mass property object.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mass property.

	Output Arguments:
		moments	- "The moments of intertia (Ixx, Ixy, Ixz, Iyy, Iyz, Izz)."

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmasspropsDescriptionSet (ProMechItem* item, ProComment description);
/*
    Purpose: Sets the description of the mass property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass property.
        description - The description.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechmasspropsMassSet (ProMechItem* item, double mass);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechMasspropsExpressionSet
    Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechMasspropsExpressionSet() instead.
                 <p>
                 Sets the mass value of the mass property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass property.
        mass - The mass.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmasspropsMomentsSet (ProMechItem* item, ProMechMassMoments moments);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechMasspropsMatrixSet
    Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechMasspropsMatrixSet() instead.
                 <p>
                 Sets the moments of intertia of the mass property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass property.
        moments - "The moments of intertia (Ixx, Ixy, Ixz, Iyy, Iyz, Izz)."

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechMasspropsExpressionGet (ProMechItem*              item,
                                            ProMechMasspropsPropertyType type,
                                            ProMechExpression            expr);
/*
    Purpose: Obtains the value corresponding to 'type' of the mass property object.
             Use ProMathExpressionEvaluate() to evaluate the value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass property.
        type - The mass property type.

    Output Arguments:
        expr - The property value (expression).

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechMasspropsExpressionSet (ProMechItem*              item,
                                            ProMechMasspropsPropertyType type,
                                            ProMechExpression            expr);
/*
    Purpose: Sets the value corresponding to 'type' of the mass property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mass property.
        type - The mass property type.
        expr - The property value (expression).

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechMasspropsMatrixGet (ProMechItem               * item,
                                        ProMechMasspropsPropertyType   type,
                                        ProMechMatrix                * matrix);
/*
    Purpose: Obtains the matrix corresponding to 'type' of the mass property object.
             Use ProMathExpressionEvaluate() to evaluate each component.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item      - The mass property.
        type      - The mass property type.

    Output Arguments:
        matrix    - The property value (matrix).
                    The function allocates memory for this argument.
                    Use ProMechMatrixFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechMasspropsMatrixSet (ProMechItem               * item,
                                        ProMechMasspropsPropertyType   type,
                                        ProMechMatrix                  matrix);
/*
    Purpose: Sets the matrix corresponding to 'type' of the mass property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The mass property.
        type    - The mass property type.
        matrix  - The property value (martix).

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

PRO_END_C_DECLS

#endif /* PROMECHMASSPROPS_H */
