#ifndef  PRO_MECHANICA_H
#define  PRO_MECHANICA_H

#include  <ProToolkit.h>
#include  <ProObjects.h>



PRO_BEGIN_C_DECLS

/******************************************************************************/

typedef enum
{
  PRO_MECHANICA_STRUCTURE = 1,
  PRO_MECHANICA_THERMAL   = 2
}
ProMechanicaMode;

/******************************************************************************/

extern ProError ProMechanicaEnter ( ProSolid         solid,
                                    ProMechanicaMode mode,
                                    ProBool          fem );

/*
   Purpose:  Enter Creo Simulate for current model (part/assembly)
        in session. Required licenses will be obtained, if available.
        <B>Notes:</B>
        <P>The solid model must be displayed in a window. Call ProMdlDisplay()
        to display model in current active window before using this function.
        <P>No control should be passed to UI between calls to
        ProMechanicaEnter() and ProMechanicaLeave(). Only Creo Parametric TOOLKIT
        functions dealing with the Simulation Database can be called.
	<P>Calling ProMechanicaEnter() in user_initialize() is not supported.
        
   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        solid - The solid model.
        mode - The mode (Structure/Thermal) of Creo Simulate.
        fem  - The FEM mode (PRO_B_TRUE), or regular Creo Simulate (PRO_B_FALSE).

   Output Arguments:
        None.

   Return Values:
        PRO_TK_NO_ERROR - Creo Simulate is entered successfully.
        PRO_TK_INVALID_PTR - The input solid pointer is invalid.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_NOT_DISPLAYED - Specified model was not displayed.
        PRO_TK_NO_LICENSE - Could not obtain required licenses.
        PRO_TK_BAD_CONTEXT - Current Application is already Creo Simulate.
        PRO_TK_INVALID_ITEM - Could not activate Creo Simulate for this model.
        PRO_TK_CANT_ACCESS - Creo Simulate model is "lite", access denied.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

/******************************************************************************/

extern ProError ProMechanicaLeave ( void );

/*
   Purpose: Leave Creo Simulate (exit to Standard Application).
        This function must be called after all communication with
        Simulation Database is finished. Licenses previously obtained by
        ProMechanicaEnter() will be released.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        None

   Output Arguments:
        None.

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

/******************************************************************************/

extern ProError ProMechanicaIsActive ( ProBool* active );

/*
   Purpose: Returns a flag indicating whether Creo Simulate Application is
        currently active.

   Input Arguments:
        None.

   Output Arguments:
        active - The flag indicating whether Creo Simulate Application is active.

   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
*/

/******************************************************************************/

PRO_END_C_DECLS

#endif  /* PRO_MECHANICA_H */
