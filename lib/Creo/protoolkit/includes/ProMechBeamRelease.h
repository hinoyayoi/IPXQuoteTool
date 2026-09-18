#ifndef PROMECHBEAMRELEASE_H
#define PROMECHBEAMRELEASE_H


#include <ProToolkit.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef struct pro_beam_release_data* ProMechBeamReleaseData;
typedef ProBoolean ProMechBeamReleaseFlags [3];

extern ProError  ProMechbeamreleaseDescriptionGet (ProMechItem* item,
                                ProComment description);
/*
        Purpose: Obtains the beam release description.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam release.

        Output Arguments:
                description     - The description.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamreleaseDataGet (ProMechItem* item,
                                ProMechBeamReleaseData* value);
/*
        Purpose: Obtains the beam release data from a beam release item.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam release.

        Output Arguments:
                value   - The beam release data.  Free this using ProMechbeamreleasedataFree().

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamreleasedataFree (ProMechBeamReleaseData data);
/*
        Purpose: Frees the memory for a Creo Simulate beam data handle.

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

extern ProError  ProMechbeamreleasedataTranslationflagsGet (ProMechBeamReleaseData data,
                                ProMechBeamReleaseFlags flags);
/*
        Purpose: Obtains the release flags for the translation directions.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam release data.

        Output Arguments:
                flags   - The translation flags.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/
extern ProError  ProMechbeamreleasedataRotationflagsGet (ProMechBeamReleaseData data,
                                ProMechBeamReleaseFlags flags);
/*
        Purpose: Obtains the release flags for the rotation directions.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam release data.

        Output Arguments:
                flags   - The rotation flags.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


extern ProError ProMechbeamreleaseDescriptionSet (ProMechItem* item, ProComment description);
/*
        Purpose: Sets the beam release description.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item - The beam release.
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

extern ProError ProMechbeamreleaseDataSet (ProMechItem* item, ProMechBeamReleaseData value);
/*
        Purpose: Sets the beam release data from a beam release item.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item - The beam release.
                value - The beam release data. 

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechbeamreleasedataAlloc (ProMechBeamReleaseData *data);
/*
        Purpose: Allocates the memory for a Creo Simulate beam data handle.

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
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechbeamreleasedataTranslationflagsSet (ProMechBeamReleaseData data, ProMechBeamReleaseFlags flags);
/*
        Purpose: Sets the release flags for the translation directions.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data - The beam release data.
                flags - The translation flags.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamreleasedataRotationflagsSet (ProMechBeamReleaseData data, ProMechBeamReleaseFlags flags);
/*
        Purpose: Sets the release flags for the rotation directions.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data - The beam release data.
                flags - The rotation flags.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

PRO_END_C_DECLS

#endif /* PROMECHBEAMRELEASE_H */
