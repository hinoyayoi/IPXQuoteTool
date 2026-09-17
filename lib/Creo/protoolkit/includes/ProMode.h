


#ifndef PROMODE_H
#define PROMODE_H

#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

typedef enum 
{
  PRO_MODE_UNUSED = PRO_VALUE_UNUSED,
  PRO_MODE_SKETCHER = 0,
  PRO_MODE_PART,
  PRO_MODE_SHEET_METAL,
  PRO_MODE_COMPOSITE,
  PRO_MODE_SCAN_MODEL,
  PRO_MODE_ASSEMBLY,
  PRO_MODE_DRAWING,
  PRO_MODE_MANUFACTURE,
  PRO_MODE_MOLD,
  PRO_MODE_CAST,
  PRO_MODE_DIEFACE,
  PRO_MODE_LAYOUT,
  PRO_MODE_FORMAT,
  PRO_MODE_REPORT,
  PRO_MODE_MARKUP,
  PRO_MODE_DIAGRAM,
  PRO_MODE_INTERCHANGE,
  PRO_MODE_LEGACY,
  PRO_MODE_USER_DEFINED,	/* no longer valid; kept as placeholder */
  PRO_MODE_VERIFY,
  PRO_MODE_PROCESS,
  PRO_MODE_NC_MODEL
} ProMode;


extern ProError ProModeCurrentGet ( ProMode* p_mode );

/*
   Purpose: Retrieves the current mode of Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      p_mode - The current mode 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The mode is NULL.
      PRO_TK_E_NOT_FOUND - The mode was not found.
*/

PRO_END_C_DECLS

#endif
