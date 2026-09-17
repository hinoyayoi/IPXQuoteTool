#ifndef PROMECHSPRINGPROPS_H
#define PROMECHSPRINGPROPS_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechItem.h>
#include <ProMechMatrix.h>
#include <ProMechVector.h>

PRO_BEGIN_C_DECLS

typedef struct pro_spring_prop_data_int*  ProMechSpringPropsData; 

typedef enum
{
  PRO_MECH_SPRINGPROPS_EXTENSIONAL  = 0,  /* ProMechMatrix (3x3, symmetrical)
                                             [ Kxx  Kxy  Kxz ]
                                             [      Kyy  Kyz ]
                                             [           Kzz ]
                                          */
  PRO_MECH_SPRINGPROPS_TORSIONAL    = 1,  /* ProMechMatrix (3x3, symmetrical)
                                             [ Txx  Txy  Txz ]
                                             [      Tyy  Tyz ]
                                             [           Tzz ]
                                          */
  PRO_MECH_SPRINGPROPS_COUPLING     = 2,  /* ProMechMatrix (3x3, full)
                                             [ KTxx  KTxy  KTxz ]
                                             [ KTyx  KTyy  KTyz ]
                                             [ KTzx  KTzy  KTzz ]
                                          */
  PRO_MECH_SPRINGPROPS_DAMPING      = 3,  /* ProMechVector (3)
                                             [ Cxx  Cyy  Czz ]
                                          */
  PRO_MECH_SPRINGPROPS_AUTOCOUPLING = 4   /* ProBoolean */

}
ProMechSpringpropsPropertyType;

typedef double ProMechSpringPropValues [6];   /* deprecated */
typedef double ProMechSpringPropCoupling [9]; /* deprecated */

extern ProError  ProMechspringpropsDescriptionGet (ProMechItem* item,
				ProComment description);
/*
	Purpose: Obtains the spring properties description.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring properties.

	Output Arguments:
		description	- The description.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechspringpropsDataGet (ProMechItem* item,
				ProMechSpringPropsData* data);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechSpringpropsMatrixGet,ProMechSpringpropsVectorGet
	Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsMatrixGet(), ProMechSpringpropsVectorGet() instead.
                 <p>
                 Obtains the spring properties data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The spring properties.

	Output Arguments:
		data	- The data.  Free this using ProMechspringpropsdataFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechspringpropsdataDampingcoefficientsGet (ProMechSpringPropsData data,
				ProMechSpringPropValues coefficients);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechSpringpropsVectorGet
	Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsVectorGet() instead.
                 <p>
                 Obtains the damping coefficients (Cxx, Cyy, Czz) for the spring properties.
                 First 3 members of ProMechSpringPropValues are Cxx,Cyy,Cyy, remaining will be 0.0 

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The spring properties data.

	Output Arguments:
		coefficients	- The damping coefficients.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechspringpropsdataFree (ProMechSpringPropsData data);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: CONTEXTUAL
	Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Frees the memory for a Creo Simulate spring properties data handle.

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

extern ProError  ProMechspringpropsdataExtensionalcoefficientsGet (ProMechSpringPropsData data,
                                ProMechSpringPropValues coefficients);
/*
		DEPRECATED: Since Creo 1
		SUCCESSORS: ProMechSpringpropsMatrixGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsMatrixGet() instead.
                 <p>
                 Obtains the extensional coefficients (Kxx,Kyy,Kzz,Kxy,Kxz,Kyz) for the spring properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The spring properties data.

        Output Arguments:
                coefficients    - The extensional coefficients.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechspringpropsdataTorsionalcoefficientsGet (ProMechSpringPropsData data,
                                ProMechSpringPropValues coefficients);
/*
		DEPRECATED: Since Creo 1
		SUCCESSORS: ProMechSpringpropsMatrixGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsMatrixGet() instead.
                 <p>
                 Obtains the torsional coefficients (Txx,Tyy,Tzz,Txy,Txz,Tyz) for the spring properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The spring properties data.

        Output Arguments:
                coefficients    - The torsional coefficients.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechspringpropsdataCouplingcoefficientsGet (ProMechSpringPropsData data, ProMechSpringPropCoupling coefficients);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechSpringpropsMatrixGet
    Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsMatrixGet() instead.
                 <p>
                 Obtains the coupling coefficients (KTxx, KTxy, KTxz, KTyx, 
	         KTyy, KTyz, KTzx, KTzy, KTzz) for the spring properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The spring properties data.
    

    Output Arguments:
        coefficients - The coupling coefficients.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
	PRO_TK_E_NOT_FOUND - Auto-coupling is used, so there are no assigned values for coupling.

*/

extern ProError ProMechspringpropsdataAutocouplingGet (ProMechSpringPropsData data, ProBoolean* auto_coupling);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechSpringpropsBooleanGet
    Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsBooleanGet() instead.
                 <p>
                 Identifies whether Creo Simulate should calculate the coupling 
	        properties automatically for the spring properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The spring properties data.
    
    Output Arguments:
        auto_coupling - PRO_B_TRUE if it calculates the coupling automatically, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechspringpropsDescriptionSet (ProMechItem* item, ProComment description);
/*
    Purpose: Sets the spring properties description.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The spring properties.
        description - The description.

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

extern ProError ProMechspringpropsDataSet (ProMechItem* item, ProMechSpringPropsData data);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechSpringpropsMatrixSet,ProMechSpringpropsVectorSet
    Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechSpringpropsMatrixSet(), ProMechSpringpropsVectorSet() instead.
                 <p>
                 Sets the spring properties data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The spring properties.
        data - The data.

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

extern ProError ProMechspringpropsdataDampingcoefficientsSet (ProMechSpringPropsData data, ProMechSpringPropValues coefficients);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechSpringpropsVectorSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechSpringpropsVectorSet() instead.
             <p>
             Sets the damping coefficients (Cxx, Cyy, Czz) for the spring properties. 
             First 3 members of ProMechSpringPropValues are Cxx,Cyy,Cyy, remaining will be 0.0

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The spring properties data.
        coefficients - The damping coefficients.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechspringpropsdataAlloc (ProMechSpringPropsData* data);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: CONTEXTUAL
    Purpose: <B>Note</B>: This function is deprecated.
             <p>             
             Allocates the memory for a Creo Simulate spring properties data 
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

extern ProError ProMechspringpropsdataExtensionalcoefficientsSet (ProMechSpringPropsData data, ProMechSpringPropValues coefficients);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechSpringpropsMatrixGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechSpringpropsMatrixGet() instead.
             <p>
             Sets the extensional coefficients (Kxx, Kyy, Kzz, Kxy, Kxz, Kyz) for the spring 
             properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The spring properties data.
        coefficients - The extensional coefficients.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechspringpropsdataTorsionalcoefficientsSet (ProMechSpringPropsData data, ProMechSpringPropValues coefficients);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechSpringpropsMatrixGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechSpringpropsMatrixGet() instead.
             <p>
             Sets the torsional coefficients (Txx, Tyy, Tzz, Txy, Txz, Tyz) for the spring 
             properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The spring properties data.
        coefficients - The torsional coefficients.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechspringpropsdataCouplingcoefficientsSet (ProMechSpringPropsData data, ProMechSpringPropCoupling coefficients);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechSpringpropsMatrixGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechSpringpropsMatrixGet() instead.
             <p>
             Sets the coupling coefficients (KTxx, KTxy, KTxz, KTyx, 
	         KTyy, KTyz, KTzx, KTzy, KTzz) for the spring 
             properties.
			 <P>
			 These properties will be set if the data's
                         auto-coupling flag is not set to PRO_B_TRUE.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The spring properties data.
        coefficients - The coupling coefficients.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - data's auto-coupling flag is set to PRO_B_TRUE, unable to set the coupling coefficients.
*/

extern ProError ProMechspringpropsdataAutocouplingSet (ProMechSpringPropsData data, ProBoolean auto_coupling);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechSpringpropsBooleanSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechSpringpropsBooleanSet() instead.
             <p>
             Identifies whether Creo Simulate should calculate the coupling 
	        properties automatically for the spring properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data          - The spring properties data.
        auto_coupling - PRO_B_TRUE if it calculates the coupling automatically,
                        PRO_B_FALSE otherwise.
    
    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechSpringpropsBooleanGet (ProMechItem              * item,
                                        ProMechSpringpropsPropertyType   type,
                                        ProBoolean                     * value);
/*
    Purpose: Obtains the boolean value corresponding to 'type' of the spring property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item  - The spring property.
        type  - The spring property type.
    
    Output Arguments:
        value - The property value (bool).

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechSpringpropsMatrixGet (ProMechItem              * item,
                                       ProMechSpringpropsPropertyType   type,
                                       ProMechMatrix                  * matrix);
/*
    Purpose: Obtains the matrix corresponding to 'type' of the spring property object.
             Use ProMathExpressionEvaluate() to evaluate each component.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item   - The spring property.
        type   - The spring property type.

    Output Arguments:
        matrix - The property value (matrix).
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

extern ProError ProMechSpringpropsVectorGet (ProMechItem              * item,
                                       ProMechSpringpropsPropertyType   type,
                                       ProMechVector                  * vector);
/*
    Purpose: Obtains the vector corresponding to 'type' of the spring property object.
             Use ProMathExpressionEvaluate() to evaluate each component.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item   - The spring property.
        type   - The spring property type.

    Output Arguments:
        vector - The property value (vector).
                 The function allocates memory for this argument.
                 Use ProMechVectorFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechSpringpropsBooleanSet (ProMechItem              * item,
                                        ProMechSpringpropsPropertyType   type,
                                        ProBoolean                       value);
/*
    Purpose: Sets the boolean value corresponding to 'type' of the spring property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item  - The spring property.
        type  - The spring property type.
        value - The property value (bool).

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

extern ProError ProMechSpringpropsMatrixSet (ProMechItem              * item,
                                       ProMechSpringpropsPropertyType   type,
                                       ProMechMatrix                    matrix);
/*
    Purpose: Sets the matrix corresponding to 'type' of the spring property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item   - The spring property.
        type   - The spring property type.
        matrix - The property value (matrix).

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

extern ProError ProMechSpringpropsVectorSet (ProMechItem              * item,
                                       ProMechSpringpropsPropertyType   type,
                                       ProMechVector                    vector);
/*
    Purpose: Sets the vector corresponding to 'type' of the spring property object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item   - The spring property.
        type   - The spring property type.
        vector - The property value (vector).

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

#endif /* PROMECHSPRINGPROPS_H */
