#ifndef PROMECHBEAMORIENT_H
#define PROMECHBEAMORIENT_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechItem.h>
#include <ProMechVector.h>

PRO_BEGIN_C_DECLS

typedef struct pro_beam_orient_data_int* ProMechBeamOrientData;

typedef enum
{
  PRO_MECH_BEAM_ORIENT_OFFSET_TYPE = 0,  /* ProMechBeamOrientType (int) */

  PRO_MECH_BEAM_ORIENT_ANGLE       = 1,  /* ProMechExpression */

  PRO_MECH_BEAM_ORIENT_OFFSET      = 2   /* ProMechVector (3)
                                            [ Dx Dy Dz ]
                                         */
}
ProMechBeamorientPropertyType;

typedef enum
{
  PRO_MECH_BEAM_ORIENT_OFFSET_SHAPE_ORIGIN = 0,
  PRO_MECH_BEAM_ORIENT_OFFSET_CENTROID     = PRO_MECH_BEAM_ORIENT_OFFSET_SHAPE_ORIGIN,
  PRO_MECH_BEAM_ORIENT_OFFSET_SHEAR_CENTER = 1
}
ProMechBeamOrientType;

extern ProError  ProMechbeamorientDescriptionGet (ProMechItem* item,
                                ProComment description);
/*
        Purpose: Obtains the beam orientation description.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam orientation.

        Output Arguments:
                description     - The description.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamorientDataGet (ProMechItem* item,
                                ProMechBeamOrientData* value);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientVectorGet,ProMechBeamorientExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientVectorGet(), ProMechBeamorientExpressionGet() instead.
                 <p>
                 Obtains the beam orientation data from a beam orientation item.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam orientation.

        Output Arguments:
                value   - The beam orientation data.  Free this using
                           ProMechbeamorientdataFree()

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamorientdataTypeGet (ProMechBeamOrientData data,
                                ProMechBeamOrientType* type);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientIntegerGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientIntegerGet() instead.
                 <p>
                 Obtains the type of orientation used in the beam orientation data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam orientation data.

        Output Arguments:
                type    - The orientation type.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamorientdataVectorGet (ProMechBeamOrientData data,
                                ProVector vector);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientVectorGet() instead.
                 <p>
                 Obtains the direction of the beam orientation.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam orientation data.

        Output Arguments:
                vector  - The orientation vector.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamorientdataAngleGet (ProMechBeamOrientData data,
                                double* angle);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientExpressionGet() instead.
                 <p>
                 Obtains the angle of the beam orientation.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam orientation data.

        Output Arguments:
                angle   - The angle in degrees.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamorientdataFree (ProMechBeamOrientData data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: CONTEXTUAL
        Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Frees the memory for a Creo Simulate beam data handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


extern ProError ProMechbeamorientDescriptionSet (ProMechItem* item, ProComment description);
/*
        Purpose: Sets the beam orientation description.

        Licensing Requirement:
          TOOLKIT for Mechanica
        Input Arguments:
                item - The beam orientation.
                description - The description.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechbeamorientDataSet (ProMechItem* item, ProMechBeamOrientData value);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientVectorSet,ProMechBeamorientExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientVectorSet(), ProMechBeamorientExpressionSet() instead.
                 <p>
                 Sets the beam orientation data from a beam orientation item.

        Licensing Requirement:
          TOOLKIT for Mechanica
        Input Arguments:
                item - The beam orientation.
                value - The beam orientation data.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechbeamorientdataTypeSet (ProMechBeamOrientData data, ProMechBeamOrientType type);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientIntegerSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientIntegerSet() instead.
                 <p>
                 Sets the type of orientation used in the beam orientation data.

        Licensing Requirement:
          TOOLKIT for Mechanica
        Input Arguments:
                data - The beam orientation data.
                type - The orientation type.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamorientdataVectorSet (ProMechBeamOrientData data, ProVector vector);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientVectorSet() instead.
                 <p>
                 Sets the direction of the beam orientation.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data - The beam orientation data.
                vector - The orientation vector.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamorientdataAngleSet (ProMechBeamOrientData data, double angle);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamorientExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamorientExpressionSet() instead.
                 <p>
                 Sets the angle of the beam orientation.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data - The beam orientation data.
                angle - The angle in degrees.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamorientdataAlloc (ProMechBeamOrientData* data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: CONTEXTUAL
        Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Allocates the memory for a Creo Simulate beam data handle.

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

extern ProError ProMechBeamorientIntegerSet (ProMechItem               * item,
                                         ProMechBeamorientPropertyType   type,
                                         int                             data);
/*
    Purpose: Sets the integer value corresponding to 'type' of
             the beam orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The beam orientation.
        type - The property type.
               (Allowed property types: PRO_MECH_BEAM_ORIENT_OFFSET_TYPE)
        data - The property value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot modify the item.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechBeamorientIntegerGet (ProMechItem               * item,
                                         ProMechBeamorientPropertyType   type,
                                         int                           * data);
/*
    Purpose: Obtains the integer value corresponding to 'type' of
             the beam orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The beam orientation.
        type - The property type.
               (Allowed property types: PRO_MECH_BEAM_ORIENT_OFFSET_TYPE)

    Output Arguments:
        data - The property value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechBeamorientExpressionSet (
                                         ProMechItem                   * item,
                                         ProMechBeamorientPropertyType   type,
                                         ProMechExpression               expr);
/*
    Purpose: Obtains the value corresponding to 'type' of the beam orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The beam orientation.
        type - The beam orientation property type.
               (Allowed property types: PRO_MECH_BEAM_ORIENT_ANGLE)
        expr - The expression.

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

extern ProError ProMechBeamorientExpressionGet (
                                         ProMechItem                   * item,
                                         ProMechBeamorientPropertyType   type,
                                         ProMechExpression               expr);
/*
    Purpose: Obtains the value corresponding to 'type' of the beam orientation.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The beam orientation.
        type - The beam orientation property type.
               (Allowed property types: PRO_MECH_BEAM_ORIENT_ANGLE)

    Output Arguments:
        expr - The expression.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechBeamorientVectorSet (ProMechItem               * item,
                                        ProMechBeamorientPropertyType   type,
                                        ProMechVector                   vector);
/*
    Purpose: Sets the Vector corresponding to 'type' of the beam orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item   - The beam orientation.
        type   - The beam orientation property type.
                 (Allowed property types: PRO_MECH_BEAM_ORIENT_OFFSET)
        vector - The vector

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

extern ProError ProMechBeamorientVectorGet (
                                        ProMechItem                   * item,
                                        ProMechBeamorientPropertyType   type,
                                        ProMechVector                 * vector);
/*
    Purpose: Obtains the vector corresponding to 'type' of the beam orientation object.
             Use ProMathExpressionEvaluate() to evaluate each moment.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The beam orientation.
        type - The beam orientation property type.
               (Allowed property types: PRO_MECH_BEAM_ORIENT_OFFSET)

    Output Arguments:
        vector - The vector.
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

PRO_END_C_DECLS

#endif /* PROMECHBEAMORIENT_H */
