#ifndef PROMECHVECTOR_H
#define PROMECHVECTOR_H


#include <ProToolkit.h>
#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef struct pro_mech_vector* ProMechVector;

extern ProError ProMechVectorAlloc (ProMechVector* vector);
/*
    Purpose: Allocates the memory for a Creo Simulate vector handle.

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

extern ProError ProMechVectorFree (ProMechVector vector);
/*
    Purpose: Frees the memory for a Creo Simulate vector handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vector - The handle.

    Output Arguments:
       none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechVectorComponentGet (ProMechVector     vector,
                                           unsigned int      index,
                                           ProMechExpression comp);
/*
    Purpose: Obtains the vector component by its index.
             Use ProMathExpressionEvaluate() to evaluate it.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        vector - The handle.
        index  - The index.

    Output Arguments:
        comp - The component expression at given index.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechVectorComponentSet (ProMechVector     vector,
                                           unsigned int      index,
                                           ProMechExpression comp);
/*                                  
    Purpose: Sets the vector component value at the given index.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        vector - The handle.
        index  - The index.
        comp   - The component expression to set, at given index.

   Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

PRO_END_C_DECLS

#endif /* PROMECHVECTOR_H */
