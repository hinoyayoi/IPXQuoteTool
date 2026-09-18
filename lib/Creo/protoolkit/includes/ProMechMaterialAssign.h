#ifndef PROMECHMATERIALASSIGN_H
#define PROMECHMATERIALASSIGN_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechGeomref.h>

PRO_BEGIN_C_DECLS

typedef struct pro_matlassign_data* ProMechMatlAssignData;

extern ProError ProMechmatlassignReferencesGet (ProMechItem* item,
                                ProMechGeomref** references);
/*
    Purpose: Obtains the references for the material assignment object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material assignment object.

    Output Arguments:
        references      - ProArray of references.  Free this using
                          ProMechgeomrefProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmatlassignDataGet (ProMechItem* item,
                                          ProMechMatlAssignData* data);
/*
    Purpose: Obtains the data of the material assignment object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material assignment object.

    Output Arguments:
        data    - The data.  Free this using
                   ProMechmatlassigndataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechmatlassigndataMaterialidGet (ProMechMatlAssignData item,
                                                    int* matl_id);
/*
    Purpose: Obtains the material id.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material assignment object.

    Output Arguments:
        matl_id - The material id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmatlassigndataMaterialorientidGet (
                                                     ProMechMatlAssignData item,
                                                     int* matlori_id);
/*
    Purpose: Obtains the material orientation id.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material assignment object.

    Output Arguments:
        matlori_id - The material orientation id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmatlassigndataFree (ProMechMatlAssignData data);
/*
    Purpose: Frees the memory for a Creo Simulate material assignment data handle.

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

extern ProError ProMechmatlassignReferencesSet (ProMechItem* item,
                                                ProMechGeomref* references);
/*
    Purpose: Sets the references for the material assignment object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item       - The material assignment object.
        references - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operati
on.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

*/

extern ProError ProMechmatlassignDataSet (ProMechItem* item,
                                          ProMechMatlAssignData data);
/*
    Purpose: Sets the material assignment data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The material assignment object.
        data - The data.

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

extern ProError ProMechmatlassigndataMaterialidSet (ProMechMatlAssignData item,
                                                    int matl_id);
/*
    Purpose: Sets the material id for material assignment object.


    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The material assignment data.
        matl_id - The Material id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmatlassigndataMaterialorientidSet (ProMechMatlAssignData item,
                                                          int matlori_id);
/*
    Purpose: Sets the material orient id for material assignment object.


    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The material assignment data.
        matlori_id - The material orient id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmatlassigndataAlloc (ProMechMatlAssignData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate material assignment data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operati
on.

*/

PRO_END_C_DECLS

#endif /* PROMECHMATERIALASSIGN_H */
