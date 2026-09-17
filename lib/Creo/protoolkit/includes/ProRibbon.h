

#ifndef PRO_RIBBON_H
#define PRO_RIBBON_H

#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

extern ProError ProRibbonDefinitionfileLoad ( wchar_t *file_name );
/*
Purpose: Loads ribbon definition file from a default path.

Input Arguments:
    file_name -  Name of ribbon definition file including extension name.

  <p><b>Note:</b>
     The default search paths for finding the ribbon definition file are:
    <ul>
     <li> Current directory</li>
     <li> Application text dir/ribbon</li>
     <li> Application text dir/(language)/ribbon</li>
    </ul>
     The location of the application text directory is specified in the
     registry file.</p>


Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - The input arguments are invalid.
    PRO_TK_E_NOT_FOUND  - The ribbon definition file was not found.
    PRO_TK_INVALID_FILE - The file specified was not a ribbon definition file.
    PRO_TK_IN_USE       - The file is already loaded.
*/

PRO_END_C_DECLS

#endif /* PRO_RIBBON_H */
