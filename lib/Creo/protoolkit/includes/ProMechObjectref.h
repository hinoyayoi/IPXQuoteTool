#ifndef PROMECHOBJECTREF_H
#define PROMECHOBJECTREF_H

                                   
  
#include <ProToolkit.h>
#include <ProObjects.h>

typedef struct pro_mech_object_ref* ProMechObjectref;

PRO_BEGIN_C_DECLS

extern ProError ProMechobjectrefTypeGet (ProMechObjectref object, ProType* type);

/*
    Purpose: Obtains the object ref type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object    - The object ref.

    Output Arguments:
        type    - The type, this must be one of the PRO_SIMULATION* types.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechobjectrefTypeSet (ProMechObjectref object, ProType type);

/*
    Purpose: Sets the object ref type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object - The object ref.
        type - The type, this must be one of the PRO_SIMULATION* types.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.

*/

extern ProError  ProMechobjectrefIdGet (ProMechObjectref object, int* id);

/*
    Purpose: Obtains the object ref id.  

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object    - The object ref.

    Output Arguments:
        id    - The object ref id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechobjectrefIdSet (ProMechObjectref object, int id);

/*
    Purpose: Sets the object ref id.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object - The object ref.
        id - The object ref id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.

*/

extern ProError  ProMechobjectrefPathGet (ProMechObjectref object, ProAsmcomppath* path);

/*
    Purpose: Obtains the component path to the object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object    - The object ref.

    Output Arguments:
        path    - The component path. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError ProMechobjectrefPathSet (ProMechObjectref object, ProAsmcomppath* path);

/*
    Purpose: Sets the component path to the object ref.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object - The object ref.
        path - The component path.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.

*/

extern ProError ProMechobjectrefAlloc (ProMechObjectref* object);

/*
    Purpose: Allocates the memory for a Creo Simulate object ref.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         none

    Output Arguments:
         object - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/
extern ProError  ProMechobjectrefFree (ProMechObjectref object);

/*
    Purpose: Frees the memory for a Creo Simulate object ref.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object    - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

extern ProError  ProMechobjectrefProarrayFree (ProMechObjectref* object);

/*
    Purpose: Frees the memory for a ProArray of Creo Simulate object refs.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        object  - The array.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
*/

PRO_END_C_DECLS

#endif /* PROMECHOBJECTREF_H */
