#ifndef PROMECHYDIRECTION_H
#define PROMECHYDIRECTION_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechGeomref.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

typedef struct pro_y_direction* ProMechYDirection;

typedef enum
{
  PRO_MECH_YDIR_VECTOR    = 0,
  PRO_MECH_YDIR_REF       = 1,
  PRO_MECH_YDIR_CSYS      = 2,
  PRO_MECH_XDIR_ALONG_REF = 3  /* Only for 2D models */
} ProMechYDirectionType;

extern ProError  ProMechydirectionTypeGet (ProMechYDirection handle,
                                ProMechYDirectionType* type);
/*
        Purpose: Obtains the type of y-direction.

    Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                handle  - The y-direction handle.

        Output Arguments:
                type    - The type.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechydirectionCsysGet (ProMechYDirection handle,
                                ProMechGeomref* csys);
/*
   Purpose: Obtains the coordinate system of the y-direction, used for 'csys' types.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
           handle  - The y-direction.

   Output Arguments:
           csys    - The coordinate system.  Free this using ProMechgeomrefFree().

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - This type of y-direction does not use a coordinate system. 
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

     See Also:
        ProMechydirectionTypeGet()
*/

extern ProError  ProMechydirectionVectorGet (ProMechYDirection handle,
                                ProVector vector);
/*
    Purpose: Obtains the vector, if the y-direction type is 'vector'.

        Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        handle  - The y-direction.

    Output Arguments:
        vector  - The vector.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - This type of y-direction does not use a vector.

     See Also:
        ProMechydirectionTypeGet()
 */

extern ProError  ProMechydirectionReferenceGet (ProMechYDirection handle,
                                ProMechGeomref* reference);
/*
    Purpose: Obtains the reference entity, if the type is 'reference'.

        Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        handle  - The y-direction.

    Output Arguments:
        reference       - The reference entity.  Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - This type of y-direction does not use a reference entity.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechydirectionTypeGet()
*/

extern ProError  ProMechydirectionFree (ProMechYDirection handle);
/*
        Purpose: Frees the memory for a Creo Simulate y-direction handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                handle  - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechydirectionCsysSet (ProMechYDirection handle, ProMechGeomref csys);
/*
    Purpose: Sets the coordinate system of the y-direction, used for 'csys' types

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        handle - The ydirection.
        csys - The coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechydirectionVectorSet (ProMechYDirection handle, ProVector vector);
/*
    Purpose: Sets the vector, if the y-direction type is 'vector'.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        handle - The ydirection.
        vector - The vector.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechydirectionReferenceSet (ProMechYDirection handle, ProMechGeomref reference);
/*
    Purpose: Sets the reference entity, if the type is 'reference'.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        handle - The ydirection.
        reference - The reference entity. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechydirectionAlloc (ProMechYDirection* handle);
/*
    Purpose: Allocates the memory for a Creo Simulate y-direction handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        handle - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

PRO_END_C_DECLS

#endif /* PROMECHYDIRECTION_H */



