#ifndef PROMECHLOADSET_H
#define PROMECHLOADSET_H


#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef enum
{
        PRO_MECH_LOADSET_NONE       = PRO_VALUE_UNUSED,

    PRO_MECH_LOADSET_STRUCTURAL = 0,
    PRO_MECH_LOADSET_THERMAL    = 1
} ProMechLoadSetType;


extern ProError  ProMechloadsetTypeGet (ProMechItem* item,
                ProMechLoadSetType* value);
/*
    Purpose: Obtains the type of the load set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The load set.

    Output Arguments:
        value    - The type. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechloadsetDescriptionGet (ProMechItem* item,
                ProComment value);
/*
    Purpose: Obtains the description of the load set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The load set.

    Output Arguments:
        value    - The description 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechloadsetLoadsGet (ProMechItem* item,
                ProMechItem** loads);
/*
    Purpose: Obtains the loads in this load set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The load set.

    Output Arguments:
        loads    - ProArray of loads. The function allocates memory for this argument.
                          Use ProArrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_E_NOT_FOUND - The set does not contain any loads.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechloadsetDescriptionSet (ProMechItem* item, ProComment value);
/*
    Purpose: Sets the description of the load set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The load set.
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

#endif /* PROMECHLOADSET_H */
