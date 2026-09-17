
#ifndef PROUIMESSAGE_H
#define PROUIMESSAGE_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

typedef enum pro_ui_message_button
{
  PRO_UI_MESSAGE_ABORT     = 0,      /* Abort from the appln */
  PRO_UI_MESSAGE_RETRY     = 1,      /* Retry the step */
  PRO_UI_MESSAGE_IGNORE    = 2,      /* Ignore the event */
  PRO_UI_MESSAGE_CONFIRM   = 3,      /* Confirm the event */
  PRO_UI_MESSAGE_YES       = 4,      /* confirm the event */
  PRO_UI_MESSAGE_NO        = 5,      /* disagree */
  PRO_UI_MESSAGE_OK        = 6,      /* acknowldge */
  PRO_UI_MESSAGE_CANCEL    = 7       /* disacknowledge */
} ProUIMessageButton;

extern ProError ProUIMessageDialogDisplay(
    ProUIMessageType type,
    wchar_t *title,
    wchar_t *msg_txt,
    ProUIMessageButton *buttons,
    ProUIMessageButton def_button,
    ProUIMessageButton *user_choice);
/*
   Purpose:     Displays the UI Message Dialog
 
   Input Arguments:
      type              - The type of the message
      title             - The text to display as the dialog title
      msg_txt           - The message text to be displayed in the dialog
      buttons           - A ProArray of possible button identifiers 
      def_button        - The identifier of the default button
 
   Output Arguments:
      user_choice       - The identifier of the button that the user pressed
                          to dismiss the dialog
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully loaded and displayed
				the dialog
      PRO_TK_BAD_INPUTS - Bad inputs
      PRO_TK_GENERAL_ERROR  - The function failed

   <!-- Objectname: ProUI -->

*/

PRO_END_C_DECLS
 
#endif  /* PROUIMESSAGE_H */
