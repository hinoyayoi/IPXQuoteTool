#ifndef PROMECHCONSTRSET_H
#define PROMECHCONSTRSET_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechLoadset.h>

PRO_BEGIN_C_DECLS

extern ProError  ProMechconstrsetTypeGet (ProMechItem* item,
                ProMechLoadSetType* value);
/*
    Purpose: Obtains the type of the constraint set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The constraint set.

    Output Arguments:
        value    - The type. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechconstrsetDescriptionGet (ProMechItem* item,
                ProComment value);
/*
    Purpose: Obtains the description of the constraint set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The constraint set.

    Output Arguments:
        value    - The description 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechconstrsetConstrsGet (ProMechItem* item,
                ProMechItem** constrs);
/*
    Purpose: Obtains the constraints in this constraint set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The constraint set.

    Output Arguments:
        constrs    - ProArray of constraints.  The function allocates 
                  memory for this argument. 
                  Use ProArrayFree to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_E_NOT_FOUND - The set does not have any constraints.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/


extern ProError ProMechconstrsetDescriptionSet (ProMechItem* item, ProComment value);
/*
    Purpose: Sets the description of the constraint set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The constraint set.
        value - The description

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

*/
PRO_END_C_DECLS

#endif /* PROMECHCONSTRSET_H */
