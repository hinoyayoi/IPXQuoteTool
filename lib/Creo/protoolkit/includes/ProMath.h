#ifndef  PRO_MATH_H
#define  PRO_MATH_H

#include  <ProObjects.h>
#include  <ProMdlUnits.h>



PRO_BEGIN_C_DECLS

/******************************************************************************/

extern ProError ProMathExpressionEvaluate ( ProSolid        pro_solid,
                                            const wchar_t * expression,
                                            double        * result,
                                            ProUnititem   * unit );
/*
   Purpose:
        Evaluates given math expression in the context of given solid.
        The expression may include parameters, dimensions, embedded functions,
        predefined constants, etc.

   Input Arguments:
        pro_solid  - Handle of Creo Parametric model (part/assembly).
        expression - The math expression string.

   Output Arguments:
        result     - The pointer to calculated result.
                     Can be NULL if not interested.
                     If this argument is NULL, this function can be used to
                     check validity of the expression syntax - for example,
                     it will return PRO_TK_NO_ERROR for the expression "1/A"
                     where "A" is a parameter with value 0.
        unit       - The pointer to the unit item of calculated result.
                     If the expression is unitized, use this output to convert
                     the result to another unit, if desired.
                     Can be NULL if not interested.

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_NOT_VALID - The expression is not valid and cannot be evaluated.
*/

/******************************************************************************/

PRO_END_C_DECLS

#endif  /* PRO_MATH_H */
