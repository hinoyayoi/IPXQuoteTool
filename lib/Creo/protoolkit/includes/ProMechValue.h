#ifndef PROMECHVALUE_H
#define PROMECHVALUE_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechGeomref.h>
#include <ProMath.h>

PRO_BEGIN_C_DECLS

typedef ProLine ProMechExpression;

typedef struct pro_vector_value* ProMechVectoredValue;
typedef struct pro_direction_vector* ProMechDirectionVector;
typedef struct pro_scalar_value* ProMechValue;
typedef struct pro_interpolation_point* ProMechInterpolationPnt;
typedef struct pro_variation* ProMechVariation;

typedef enum
{
    PRO_MECH_DIRECTION_NONE        = PRO_VALUE_UNUSED,

    PRO_MECH_DIRECTION_BY_VECTOR   = 0,
    PRO_MECH_DIRECTION_BY_2_POINTS = 1
} ProMechDirectionType;

typedef enum
{
    PRO_MECH_VARIATION_NONE          = PRO_VALUE_UNUSED,

    PRO_MECH_VARIATION_UNIFORM       = 0,
    PRO_MECH_VARIATION_FUNCTION      = 1,
    PRO_MECH_VARIATION_INTERPOLATION = 2,
    PRO_MECH_VARIATION_EXTERN_FIELD  = 3
} ProMechVariationType;


extern ProError  ProMechvectoredvalueDirectiontypeGet (ProMechVectoredValue value,
                ProMechDirectionType* type);
/*
    Purpose: Obtains the type of direction assigned to this value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value    - The value.

    Output Arguments:
        type    - The direction type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechvectoredvalueDirectionvectorGet (ProMechVectoredValue value,
                ProMechDirectionVector* dir_vector);
/*
    Purpose: Obtains the direction vector structure assigned to this value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value    - The value.

    Output Arguments:
        dir_vector    - The direction vector.  Free this using
                        ProMechdirectionvectorFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The value does not contain a direction vector.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

    See Also:
        ProMechvectoredvalueTypeGet()
*/

extern ProError  ProMechvectoredvaluePointsGet (ProMechVectoredValue value,
                ProMechGeomref** points);
/*
    Purpose: Obtains the pair of points that determines the direction.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value    - The value.

    Output Arguments:
        points    - ProArray of points. The function allocates memory for this argument.
                          Use ProMechgeomrefProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The value does not contain a pair of points.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
        PRO_TK_GENERAL_ERROR - A general error was encountered.

    See Also:
        ProMechvectoredvalueTypeGet()
*/

extern ProError  ProMechvectoredvalueMagnitudeGet (ProMechVectoredValue value,
                ProMechValue* value_mag);
/*
    Purpose: Obtains the magnitude of this vectored value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value    - The value.

    Output Arguments:
        value_mag    - The variation.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_E_NOT_FOUND - The value does not use the magnitude settings.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechvectoredvalueFree (ProMechVectoredValue value);
/*
    Purpose: Frees the memory for a Creo Simulate handle containing a directed value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value    - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdirvectorComponentsGet (ProMechDirectionVector vector,
                ProMechValue** value);
/*
    Purpose: Obtains the component values of the vector (3 ProMechValue components).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vector    - The vector.

    Output Arguments:
        value    - ProArray of component values.  The function allocates memory for
                   this argument.  Free it using ProMechvalueProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechdirvectorVariationGet (ProMechDirectionVector vector,
                ProMechVariation* variation);
/*
    Purpose: Obtains the overall variation on the vector.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        vector    - The vector.

    Output Arguments:
        variation    - The variation.  Free this using ProMechvariationFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechdirvectorCsysGet (ProMechDirectionVector vector,
                ProMechGeomref* csys);
/*
    Purpose: Obtains the coordinate system used to calculate the vector.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        vector    - The vector.

    Output Arguments:
        csys    - The coordinate system reference.  Free this using
                    ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechdirvectorFree (ProMechDirectionVector vector);
/*
    Purpose: Frees the memory for a Creo Simulate handle containing a direction vector.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        vector    - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechvalueValueGet (ProMechValue value,
                ProMechExpression value_expr);
/*
    Purpose: Obtains the value.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        value    - The value handle.

    Output Arguments:
        value_expr    - The value expression.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechvalueVariationGet (ProMechValue value,
                ProMechVariation* variation);
/*
    Purpose: Obtains the variation assigned to this value.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        value    - The value handle.

    Output Arguments:
        variation    - The variation.  Free this using ProMechvariationFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechvalueFree (ProMechValue value);
/*
    Purpose: Frees the memory for a Creo Simulate value handle.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        value    - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechvalueProarrayFree (ProMechValue* value);
/*
    Purpose: Frees the memory for a ProArray of Creo Simulate value handles.

    Input Arguments:
        value    - The array.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechvariationTypeGet (ProMechVariation variation,
                ProMechVariationType* type);
/*
    Purpose: Obtains the type of variation assigned to a value.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        variation    - The variation handle.

    Output Arguments:
        type    - The variation type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


extern ProError  ProMechvariationFunctionidGet (ProMechVariation variation,
                                int* function_id);
/*
        Purpose: Obtains the function assigned to determine the variation of a value.

    Licensing Requirement:
          TOOLKIT for Mechanica


        Input Arguments:
                variation       - The variation handle.

        Output Arguments:
                function_id     - The function id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The variation does not contain a function.

        See Also:
                ProMechvariationTypeGet()
*/

extern ProError  ProMechvariationInterpolationGet (ProMechVariation variation,
                ProMechInterpolationPnt** interpolation);
/*
    Purpose: Obtains the interpolation points assigned to determine the variation
                of a value.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        variation    - The variation handle.

    Output Arguments:
        interpolation    - ProArray of interpolation points.
                          Use ProMechinterpolationpntProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The variation does not contain an interpolation.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

      See Also:
        ProMechvariationTypeGet()
*/

extern ProError  ProMechvariationFree (ProMechVariation variation);
/*
    Purpose: Frees the memory for a Creo Simulate variation handle.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        variation    - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechinterpolationpntMagnitudeGet (ProMechInterpolationPnt interpolation_pnt,
                ProMechExpression value);
/*
    Purpose: Obtains the magnitude assigned to the interpolation point.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        interpolation_pnt    - The interpolation point handle.

    Output Arguments:
        value    - The magnitude.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechinterpolationpntPointGet (ProMechInterpolationPnt interpolation_pnt,
                ProMechGeomref* value);
/*
    Purpose: Obtains the geometric point assigned to the interpolation point.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        interpolation_pnt    - The interpolation point handle.

    Output Arguments:
        value    - The point.  Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechinterpolationpntFree (ProMechInterpolationPnt interpolation_pnt);
/*
    Purpose: Frees the memory for a Creo Simulate interpolation point.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        interpolation_pnt    - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechinterpolationpntProarrayFree (ProMechInterpolationPnt* interpolation_pnt);
/*
    Purpose: Frees the memory for a ProArray of Creo Simulate interpolation points.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        interpolation_pnt    - The array.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


typedef struct pro_external_field* ProMechExternalFieldData;

extern ProError ProMechvectoredvalueDirectiontypeSet (ProMechVectoredValue value, ProMechDirectionType type);
/*
    Purpose: Sets the type of direction assigned to this value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value - The value.
        type - The direction type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechvectoredvalueDirectionvectorSet (ProMechVectoredValue value, ProMechDirectionVector dir_vector);
/*
    Purpose: Sets the direction vector structure assigned to this value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value - The value.
        dir_vector - The direction vector.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechvectoredvaluePointsSet (ProMechVectoredValue value, ProMechGeomref* points);
/*
    Purpose: Sets the pair of points that determines the direction.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value - The value.
        points - ProArray of points.
                 (NOTE: Only PRO_MECH_POINT_SINGLE type points are allowed)

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechvectoredvalueMagnitudeSet (ProMechVectoredValue value, ProMechValue value_mag);
/*
    Purpose: Sets the magnitude of this vectored value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value - The value.
        value_mag - The magnitude.
                    Use NULL to unset the magnitude for an existing
                    vectored value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechvectoredvalueAlloc (ProMechVectoredValue* value);
/*
    Purpose: Allocates the memory for a Creo Simulate handle containing a
             directed value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        value - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError ProMechdirvectorComponentsSet (ProMechDirectionVector vector, ProMechValue* value);
/*
    Purpose: Sets the component values of the vector (3 ProMechValue  components).

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        vector - The vector.
        value - ProArray of component values.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechdirvectorVariationSet (ProMechDirectionVector vector, ProMechVariation variation);
/*
    Purpose: Sets the overall variation on the vector.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vector - The vector.
        variation - The variation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechdirvectorCsysSet (ProMechDirectionVector vector, ProMechGeomref csys);
/*
    Purpose: Sets the coordinate system used to calculate the vector.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vector - The vector.
        csys - The coordinate system reference.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechdirvectorAlloc (ProMechDirectionVector* vector);
/*
    Purpose: Allocates the memory for a Creo Simulate handle containing a
             direction vector.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        vector - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError ProMechvalueValueSet (ProMechValue value, ProMechExpression value_expr);
/*
    Purpose: Sets the value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value - The value handle.
        value_expr - The value expression.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechvalueVariationSet (ProMechValue value, ProMechVariation variation);
/*
    Purpose: Sets the variation assigned to this value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        value - The value handle.
        variation - The variation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechvalueAlloc (ProMechValue* value);
/*
    Purpose: Allocates the memory for a Creo Simulate value handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        value - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError ProMechvariationFunctionidSet (ProMechVariation variation, int function_id);
/*
    Purpose: Sets the function assigned to determine the variation of a value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        variation - The variation handle.
        function_id - The function id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechvariationInterpolationSet (ProMechVariation variation, ProMechInterpolationPnt* interpolation);
/*
    Purpose: Sets the interpolation points assigned to determine the variation
            of a value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        variation - The variation handle.
        interpolation - ProArray of interpolation points.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechvariationAlloc ( ProMechVariation* variation);
/*
    Purpose: Allocates the memory for a Creo Simulate variation handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        variation - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError ProMechinterpolationpntMagnitudeSet (ProMechInterpolationPnt interpolation_pnt, ProMechExpression value);
/*
    Purpose: Sets the magnitude assigned to the interpolation point.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        interpolation_pnt - The interpolation point handle.
        value - The magnitude.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechinterpolationpntPointSet (ProMechInterpolationPnt interpolation_pnt, ProMechGeomref value);
/*
    Purpose: Sets the geometric point assigned to the interpolation point.


    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        interpolation_pnt - The interpolation point handle.
        value - The point.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechinterpolationpntAlloc (ProMechInterpolationPnt* interpolation_pnt);
/*
    Purpose: Allocates the memory for a Creo Simulate interpolation point.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        interpolation_pnt - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError ProMechvariationExternalfielddataGet (ProMechVariation variation, ProMechExternalFieldData *external_field);
/*
    Purpose: Obtains the external field assigned for variation of a value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
            variation - The variation handle.

    Output Arguments:
            external_field - The external field.

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_INVALID_TYPE - The variation does not contain external field.
            PRO_TK_OUT_OF_MEMORY - Insufficient memory.

    See Also:
            ProMechvariationTypeGet()
*/

extern ProError ProMechvariationExternalfielddataSet (ProMechVariation variation, ProMechExternalFieldData external_field);
/*
    Purpose: Sets the external field assigned for variation of a value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
            variation - The variation handle.
            external_field - The external field.

    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechexternalfielddataCsysGet (ProMechExternalFieldData data, ProMechGeomref* csys);
/*
    Purpose: Obtains the csys for ths external field data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
            data - The external field handle.

    Output Arguments:
            csys    - The csys. Free this using ProMechgeomrefFree()

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechexternalfielddataCsysSet (ProMechExternalFieldData data, ProMechGeomref csys);
/*
    Purpose: Sets the csys for ths external field data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
            data - The external field handle.
            csys - The csys.

    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechexternalfielddataFileGet (ProMechExternalFieldData data, ProPath value);
/*
    Purpose: Obtains the path to the fnf file for this external field data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
            data - The external field handle.

    Output Arguments:
            value   - The path.

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


extern ProError  ProMechexternalfielddataFileSet (ProMechExternalFieldData data, ProPath value);
/*
    Purpose: Sets the path of the fnf file for this external field data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
            data  - The external field handle.
            value - The path.

    Output Arguments:
            none

    Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechexternalfielddataAlloc (ProMechExternalFieldData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate external field data handle

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
            PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError  ProMechexternalfielddataFree (ProMechExternalFieldData data);
/*
    Purpose: Frees the memory for a Creo Simulate external field data handle

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

extern ProError  ProMechvariationUniformSet (ProMechVariation variation);
/*
    Purpose: Sets the variation uniform.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        variation - The variation handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

PRO_END_C_DECLS

#endif /* PROMECHVALUE_H */
