#ifndef _PRO_NAVIGATOR_H_
#define _PRO_NAVIGATOR_H_



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

extern ProError ProNavigatorpaneBrowserAdd (ProCharName pane_name,
                                            ProCharName icon_file_name,
                                            wchar_t *url);
/*
  Purpose: Add navigator pane

  Input Arguments:
  pane_name - Name of the new navigator pane
  icon_file_name - Icon file name. Pass NULL to use default icon.
  url - URL of the pane

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Function failed.


*/


extern ProError ProNavigatorpaneBrowsericonSet (ProCharName pane_name,
                                                ProCharName icon_file_name);
/*
  Purpose: Set pane icon (.BIF/.GIF)

  Input Arguments:
  pane_name - Name of the new navigator pane
  icon_file_name - Icon file name

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Not able to set the Icon

*/


extern ProError ProNavigatorpaneBrowserURLSet (ProCharName pane_name,
                                               wchar_t*    url);
/*
  Purpose: Set pane URL

  Input Arguments:
  pane_name - Name of the new navigator pane
  url - URL to set in the pane

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Navigator URL not set

*/


extern ProError ProNavigatorpanePHolderAdd (ProCharName pane_name,
                                            ProCharName resource_name,
                                            ProCharName icon_file_name);
/*
  Purpose: Add pane name on the Navigator pane

  Input Arguments:
  pane_name - Name of the navigator pane
  resource_name - name of the resource
  icon_file_name - Name of the icon file. Pass NULL to use default icon.

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Function failed.

*/



extern ProError ProNavigatorpanePHolderDelete (ProCharName pane_name);
/*
  Purpose: Delete pane from the Navigator pane

  Input Arguments:
  pane_name - Name of the navigator pane

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_GENERAL_ERROR - Function failed.

*/


extern ProError ProNavigatorpanePHolderShow (ProCharName pane_name);
/*
  Purpose: Show pane on the Navigator pane

  Input Arguments:
  pane_name - Name of the navigator pane

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_GENERAL_ERROR - Function failed.

*/

extern ProError ProNavigatorpanePHolderHide (ProCharName pane_name);
/*
  Purpose: Hide pane fron the Navigator pane

  Input Arguments:
  pane_name - Name of the navigator pane

  Output Arguments:
  none

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_GENERAL_ERROR - Function failed.

*/

extern ProError ProNavigatorpanePHolderHelptextSet(ProCharName pane_name,
                                                   wchar_t* helptext);

/*
  Purpose: Set Helptext from input to all Tab PHs 

  Input Arguments:
  pane_name - Name of the navigator pane
  helptext - the new helptext

  Output Arguments:

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - helptext input argument is NULL.
  PRO_TK_GENERAL_ERROR - Function failed.

*/


extern ProError ProNavigatorpanePHolderDevicenameGet (int    win_id,
                                                      char **device_name);
/*
  Purpose: Get the device name 

  Input Arguments:
  win_id - Window identifier

  Output Arguments:
  device_name - The device name. Free this string using ProStringFree().

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Function failed.

*/



extern ProError ProNavigatorpanePHolderLayoutGet (ProCharName pane_name,
                                                  char      **layout_name);
/*
  Purpose: Get pane layout name

  Input Arguments:
  pane_name - Name of the navigator pane

  Output Arguments:
  layout_name - Layout of the pane, Free this string using ProStringFree().

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Function failed.

*/


extern ProError ProNavigatorpanePHolderComponentnameGet (ProCharName pane_name,
                                                         char  *nominal_name,
                                                         char **comp_name);
/*
  Purpose: Get the full name of a component in the pane

  Input Arguments:
  pane_name - Name of the navigator pane
  nominal_name - Local name of component

  Output Arguments:
  comp_name - full component name, Free this string using ProStringFree().

  Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  PRO_TK_GENERAL_ERROR - Function failed.

*/

PRO_END_C_DECLS

#endif // _PRO_NAVIGATOR_H_
