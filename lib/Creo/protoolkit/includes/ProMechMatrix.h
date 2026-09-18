#ifndef PROMECHMATRIX_H
#define PROMECHMATRIX_H



#include <ProToolkit.h>
#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef struct pro_mech_matrix* ProMechMatrix;

extern ProError ProMechMatrixAlloc (ProMechMatrix* matrix);
/*
    Purpose: Allocates the memory for a Creo Simulate matrix handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
       none

    Output Arguments:
        matrix - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.

*/

extern ProError ProMechMatrixFree (ProMechMatrix matrix);
/*
    Purpose: Frees the memory for a Creo Simulate matrix handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        matrix - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechMatrixComponentGet (ProMechMatrix     matrix,
                                           unsigned int      index1,
                                           unsigned int      index2,
                                           ProMechExpression comp);
/*
    Purpose: Obtains the component value by its indices.
             Use ProMathExpressionEvaluate() to evaluate it.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        matrix - The handle.
        index1 - Row index.
        index2 - Column index.

    Output Arguments:
        comp - The component expression at given indices.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechMatrixComponentSet (ProMechMatrix     matrix,
                                           unsigned int      index1,
                                           unsigned int      index2,
                                           ProMechExpression comp);
/*
    Purpose: Sets the component value at the given indices.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        matrix - The handle.
        index1 - Row index.
        index2 - Column index.
        comp   - The component expression to set, at given indices.

   Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

PRO_END_C_DECLS

#endif /* PROMECHMATRIX_H */
