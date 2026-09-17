

#ifndef _PRO_UICMD_
#define _PRO_UICMD_

#include <ProToolkit.h>
#include <ProWchar.h>

PRO_BEGIN_C_DECLS

typedef char   ProCmdItemName[PRO_NAME_SIZE];
typedef char   ProCmdItemLabel[PRO_LINE_SIZE];
typedef char   ProCmdItemIcon[PRO_LINE_SIZE];
typedef char   ProCmdLineHelp[PRO_LINE_SIZE];
typedef char   ProCmdDescription[PRO_LINE_SIZE];


/*
** Command value types enum
*/

typedef enum
{
    UI_CMD_VAL_NONE,
    UI_CMD_VAL_INT,
    UI_CMD_VAL_BOOL,
    UI_CMD_VAL_DOUBLE,
    UI_CMD_VAL_STRING,
    UI_CMD_VAL_WSTRING,
    UI_CMD_VAL_STRING_ARRAY
} uiCmdValueType;

/*
** Command access mode enum
*/

typedef enum
{
    MODE_BLIND,
    MODE_ERROR_MSG_ALLOWED
} uiCmdAccessMode;

/*
** Command priority enum
*/

typedef int uiCmdPriority;

#define uiCmdPrioDefault   ((uiCmdPriority) 0)   /* Normal-highest priority
                                              For Creo Parametric TOOLKIT users, this
                                              priority should typically not
                                              be used.  The priority dismisses
                                              the context of other
                                              Creo Parametric commands and can
                                              cause interactive acitivities
                                              like ProSelect() to fail.
                                              Applications should
                                              typically use uiProeImmediate
                                              or uiProeAsynch  */
#define uiProeImmediate    ((uiCmdPriority) 2)   /* Immediate priority -
                                                    lower than normal*/
#define uiProeAsynch       ((uiCmdPriority) 3)   /* Asynchronous - operates
                                                    without dismissing other
                                                    menus or dialogs.*/
#define uiProe2ndImmediate ((uiCmdPriority) 5)   /* 2nd immediate priority -
                                                    lower than immediate */
#define uiProe3rdImmediate ((uiCmdPriority) 6)   /* 3rd immediate priority -
                                                    lower than 2nd immediate */
#define uiProeSpinImmediate ((uiCmdPriority) 7)   /* Spin immediate priority -
                                                    lower than 3nd immediate */

#define uiCmdNoPriority    ((uiCmdPriority) 999)

/*
** Command access state enum
*/

typedef enum
{
    ACCESS_REMOVE = -1,  /* Used when the button is not visible, and the     */
                         /* containing menus might also be removed from the  */
                         /* menu, if all of the menu buttons in the contain- */
                         /* ing menu possess an access function returning    */
                         /* ACCESS_REMOVE.                                   */

    ACCESS_INVISIBLE,    /* Used when the button is not visible.              */

    ACCESS_UNAVAILABLE,  /* Used when the button is visible, but grayed-out   */
                         /* and cannot be selected.                           */

    ACCESS_DISALLOW,     /* Used when the button shows as available, but the  */
                         /* command will not be executed when chosen.         */

    ACCESS_AVAILABLE     /* Used when the button is not grayed-out and can    */
                         /* be selected by the user.                          */
} uiCmdAccessState;

/*
** Structure and union typedefs
*/

typedef union
{
    int               i_val;
    int               l_val;
    struct
    {
        double        val;
        int           n_digits;         /* -1 if unknown. */
        int           denominator;      /* -1 if unknown. */
    } d_val;
    wchar_t          *p_wsval;      /* Note not embedded string! */
    char             *p_sval;       /* Note not embedded string! */
    char            **p_sval_array; /* ProArray */
} _uiCmdValue;

typedef struct
{
    uiCmdValueType    type;
    _uiCmdValue       value;
} uiCmdValue;

/*
** Opaque typedefs
*/

typedef void *uiCmdCmdId;
typedef void *uiCmdAccessId;

/*
** function typedefs for commands
*/

typedef int   (*uiCmdCmdActFn)  (uiCmdCmdId  command,
                                 uiCmdValue *p_value,
                                 void       *p_push_command_data);

/*
  Purpose:
      The callback function attached to Creo Parametric commands by calls to
      ProCmdOptionAdd() or ProCmdActionAdd(). The callback is called when
      the command is executed.
<p>
      For pushbuttons, the callback must define the logic of the command.
<p>
      For checkbuttons, the callback must get the value of the button with
      ProMenubarmenuChkbuttonvalueGet(), then define the logic of the command.
<p>
      For radio groups, the callback must get the selected item with
      ProMenubarmenuRadiogrpValueGet(), then define the logic of the command.

   Input Arguments:

      command - The identifier of the action or option
      p_value - For options passed to ValueGet functions. Ignored for actions.
      p_push_command_data  -  Not used

   Output Arguments:

      None

   Return Values:

     The return value is ignored.
*/

typedef int   (*uiCmdCmdValFn) (uiCmdCmdId  command,
                                uiCmdValue *p_value);

/*
   Purpose:
       The callback function attached to ProENGINEER option commands by passing
       it to ProCmdOptionAdd().  The callback is used to set the option value.

<p>    For checkbuttons, set option values with function
       ProMenubarmenuCheckButtonValueSet().

<p>    For radio buttons, set option values with function
       ProMenubarmenuCheckRadiogrpValueSet().

    Input Arguments:

       command    - Identifier of the option command.
       p_value    - Value passed to the ValueSet function.

    Output Arguments:

       None

    Return Values:

       The return value is ignored.
*/

typedef int   (*uiCmdCmdBktFn)   ( uiCmdCmdId   command,
                                   uiCmdValue  *p_new_value,
                                   int          entering_command,
                                   void       **pp_bracket_data);

/*
   Purpose:
        The callback function attached to the Creo Parametric menubar buttons
        by a call to the function <b>ProCmdBracketFuncAdd()</b>.
        This function is called before and after execution.

   Input Arguments:
      command          - The identifier of the action or option.
      entering_command - The value is 1 when called before execution
                         and 0 when called after execution
      pp_bracket_data  - General application data as provided by the call to
                         <b>ProCmdBracketFuncAdd()</b> that defines this
                         menu item.

   Output Arguments:
      p_new_value      - Not used; argument ignored.

   Return Values:
      Non-Zero   - Call the action function associated with the command.
      Zero         - Don't call the action function associated with the command.

*/

/*
** function typedefs for access
*/

typedef uiCmdAccessState (*uiCmdAccessFn) (uiCmdAccessMode access_mode);

/*
   Purpose:

       The callback function attached to a Creo Parametric command by passing it to
       either ProCmdOptionAdd, ProCmdActionAdd, or ProCmdAccessFuncAdd.
       uiCmdAccessFn specifies the access allowed to the command.

    Input Arguments:

       access_mode   - Whether or not to allow error messages. Can be ignored
                       by the callback function.

    Output Arguments:

       None

    Return Values:

      One of the values of uiCmdAccessState, showing which access is permitted.
*/

/*
** function prototypes
*/

/*---------------------------------------------------------------------------*/

extern ProError ProCmdActionAdd ( char      *action_name,
                                  uiCmdCmdActFn     action_cb,
                                  uiCmdPriority     priority,
                                  uiCmdAccessFn     access_func,
                                  ProBoolean        allow_in_non_active_window,
                                  ProBoolean        allow_in_accessory_window,
                                  uiCmdCmdId       *action_id );

/*
   Purpose: Adds a new action to Creo Parametric.  This action can be later
            associated with a push button command in the Creo Parametric
            Ribbon UI.
            <p>
            This function is executed only once during a Creo Parametric
            session for each action. Subsequent calls to this function
            for previously loaded actions return an error.

   Input Arguments:
      action_name                - The name of the action (must be unique)
      action_cb                  - The callback function
      priority                   - Defines the priority of the action with
                                   respect to other actions that can be
                                   invoked during the execution of the
                                   action callback function
      access_func                - The function that defines the accessibility
                                   of the action
      allow_in_non_active_window - Defines whether this action can be
                                   executed in a nonactive Creo Parametric window
      allow_in_accessory_window  - Defines whether this action can be
                                   executed in an accessory Creo Parametric window
   Output Arguments:
      action_id                  - The identifier of the action

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the action.
      PRO_TK_GENERAL_ERROR      - The function failed to add the action.
      PRO_TK_E_FOUND            - An action already exists under
                                  <i>action_name</i>.
*/

extern ProError ProCmdOptionAdd ( char      *option_name,
                                  uiCmdCmdActFn     option_cb,
                                  ProBoolean        boolean_operation,
                                  uiCmdCmdValFn     set_value_cb,
                                  uiCmdAccessFn     access_func,
                                  ProBoolean        allow_in_non_active_window,
                                  ProBoolean        allow_in_accessory_window,
                                  uiCmdCmdId       *option_id );

/*
   Purpose: Adds a new option to Creo Parametric.  This option can be later
            associated with a checkbutton or radio button group in the
            Creo Parametric Ribbon UI.
            <p>
            This function is executed only once during a Creo Parametric
            session for each option. Subsequent calls to this function
            for previously loaded options are ignored.

   Input Arguments:
      option_name                - The name of the option (must be unique)
      option_cb                  - The callback function activated when the
                                   button is clicked (Radio type) or checked
                                   (Check type).
      boolean_operation          - When PRO_B_TRUE, button is Check type.
                                   When PRO_B_FALSE, button is Radio type.
      set_value_cb               - The callback function that sets the
                                   initial value of the option.
      access_func                - The function that defines the
                                   accessibility of
                                   the option
      allow_in_non_active_window - Defines whether this option can be
                                   changed in a nonactive Creo Parametric window
      allow_in_accessory_window  - Defines whether this option can be
                                   changed in an accessory Creo Parametric window

   Output Arguments:
      option_id                  - The identifier of the option

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the option.
      PRO_TK_GENERAL_ERROR      - The function failed to add the option.
      PRO_TK_E_FOUND            - An option already exists under
                                  <i>option_name</i>.
*/

extern ProError ProCmdBracketFuncAdd ( uiCmdCmdId        cmd_id,
                                       uiCmdCmdBktFn     bracket_func,
                                       char             *bracket_func_name,
                                       void            **pp_bracket_data );

/*
   Purpose: Adds a function to be called before and after the callback
            function when the specified action or option is executed.

   Input Arguments:
      cmd_id                    - The identifier of the action or option
      bracket_func              - The function to be called before and after
                                  execution
      bracket_func_name         - The name of the function to be called
                                  before and after execution
      pp_bracket_data           - The pointer to the data to be passed
                                  to the function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the bracket
                                  function.
      PRO_TK_GENERAL_ERROR      - The function failed to add the bracket
                                  function.
*/

extern ProError ProCmdCmdIdFind ( char      *cmd_name,
                                  uiCmdCmdId       *cmd_id );
/*
   Purpose: Finds the identifier of the specified action or option.

   Input Arguments:
      cmd_name                  - The name of the action or option.

   Output Arguments:
      cmd_id                    - The address of the identifier of an
                                  action or option. This can be a null pointer.

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully found the identifier.
      PRO_TK_GENERAL_ERROR      - The function failed to find the identifier.
*/

extern ProError ProCmdAccessFuncAdd ( uiCmdCmdId        cmd_id,
                                      uiCmdAccessFn     access_func,
                                      uiCmdAccessId    *access_id );
/*
   Purpose: Adds an accessibility function to the specified action or option.

   Input Arguments:
      cmd_id                    - The identifier of the action or option
      access_func               - The function to be called to determine
                                  the accessibility of the action or option

   Output Arguments:
      access_id                 - The pointer to the identifier of the
                                  accessibility function

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the
                                  accessibility function.
      PRO_TK_GENERAL_ERROR      - The function failed to add the accessibility
                                  function.
*/

extern ProError ProCmdAccessFuncRemove ( uiCmdCmdId        cmd_id,
                                         uiCmdAccessId     access_id );
/*
   Purpose: Removed an accessibility function of the specified action or option.

   Input Arguments:
      cmd_id                    - The identifier of the action or option
      access_id                 - The identifier of the accessibility function

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully removed the
                                  accessibility function.
      PRO_TK_GENERAL_ERROR      - The function failed to remove the
                                  accessibility function.
*/

extern ProError ProCmdChkbuttonValueSet ( uiCmdValue             *cmd_value,
                                          ProBoolean              value );
/*
   Purpose: Sets a new value for the check button in the menu of Creo Parametric.
            <p>
            This function affects the top-level Creo Parametric Ribbon UI only.
            <p>
            This function is executed only in the <i>set_value_cb</i> specified
            by ProCmdOptionAdd().

   Input Arguments:
      cmd_value                 - The second argument of the <i>set_value_cb</i>
                                  function
      value                     - The status of the check button:
                                  PRO_B_TRUE (on) or PRO_B_FALSE (off)

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully set the value.
      PRO_TK_GENERAL_ERROR      - The function failed to set the value.
*/

extern ProError ProCmdChkbuttonValueGet ( uiCmdValue             *cmd_value,
                                          ProBoolean             *value );
/*
   Purpose: Gets a new value for the check button in the menu of Creo Parametric.
            This function is executed only in the <i>option_cb</i> specified
            by ProCmdOptionAdd().
            <p>
            This function affects the top-level Creo Parametric Ribbon UI only.

   Input Arguments:
      cmd_value                 - The second argument of the <i>option_cb</i>
                                  function

   Output Arguments:
      value                     - The address of the status of the check button:
                                  PRO_B_TRUE (on) or PRO_B_FALSE (off)

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully got the value.
      PRO_TK_GENERAL_ERROR      - The function failed to get the value.
*/

extern ProError ProCmdRadiogrpDesignate ( uiCmdCmdId           option_id,
                                          int                  number_radio_group_items,
                                          ProCmdItemName      *radio_group_items,
                                          ProCmdItemLabel     *radio_group_labels,
                                          ProCmdLineHelp      *one_line_helps,
                                          ProCmdItemIcon      *radio_group_icons,
                                          ProCmdDescription    description,
                                          ProFileName          filename );
/*
   Purpose: Designates the radio button to appear as placeable in the Screen
            Customization dialog. This may not be used for existing
            Creo Parametric system radio buttons.

   Input Arguments:
      option_id                 - The identifier of the option
      number_radio_group_items  - The number of items in the radio group
      radio_group_items         - ProArray of names of the items in the radio group
      radio_group_labels        - ProArray of labels of the items in the radio group
      one_line_helps            - ProArray of one-line help strings for the radio group
      radio_group_icons         - ProArray of names of the icon file including the
                                  extension. It can be either a .PNG, .GIF,
                                  .JPG, .PCX, .BMP, .ICO, .CUR file or a
                                  Creo Parametric .BIF file. Make sure to provide
                                  the filename including a valid file extension,
                                  denoting the type of the image as one of the
                                  standard formats listed above. PTC
                                  recommends using .PNG file. All icons in
                                  Creo Parametric Ribbon are either 16x16 (small)
                                  or 32x32 (large) size. As a standard naming
                                  convention icon name should not have 32x32 or
                                  20x20 or 16x16 postfix. When Creo Parametric
                                  wants to display small icon it looks for
                                  iconname.ext and when it looks for large icon
                                  it looks for iconname_large.ext file. In order
                                  to support legacy applications if iconname.ext
                                  is not of 16x16 or 20x20 then Creo Parametric
                                  looks iconname16x16.ext or iconname20x20.ext.
                                  This support will go away in future releases.
                                  PTC recommends using standard icon naming
                                  conventions i.e. iconname.ext or
                                  iconname_large.ext.  For example in order to
                                  designate both small and large icon to a
                                  command, place both my_icon.png and
                                  my_icon_large.png in the resource directory
                                  and use my_icon.png as icon file name.
    <p><b>Note:</b>
     The default search paths for finding the icons are:
    <ul>
     <li> Creo Parametric Loadpoint/text/resource</li>
     <li> Application text dir/resource</li>
     <li> Application text dir/(language)/resource</li>
    </ul>
     The location of the application text directory is specified in the
     registry file.</p>
     description                - Message in the customization dialog and click
                                   on "Description"
      filename                  - The name of the message file that contains
                                  labels and help strings

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the radio group.
      PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the
                                  message file.
      PRO_TK_E_FOUND            - a menu item with this name already exists.
      PRO_TK_GENERAL_ERROR      - The function failed to add the radio group.
*/

extern ProError ProCmdRadiogrpValueSet ( uiCmdValue      *cmd_value,
                                         ProCmdItemName   selected_item );

/*
   Purpose: Sets a new value for the radio group in the menu of Creo Parametric.
            <p>
            This function affects the top-level Creo Parametric Ribbon UI only.
            <p>
            This function is executed only in the <i>set_value_cb</i> specified
            by ProCmdOptionAdd().

   Input Arguments:
      cmd_value                 - The second argument of the <i>set_value_cb</i>
                                  function.
      selected_item             - The name of the item in the radio group
                                  to be selected.  The memory must be
                                  static or preallocated.  In the second
                                  case, do not free the memory.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully set the value.
      PRO_TK_GENERAL_ERROR      - The function failed to set the value.
*/

extern ProError ProCmdRadiogrpValueGet ( uiCmdValue      *cmd_value,
                                         ProCmdItemName   selected_item );

/*
   Purpose: Gets a value of the radio group in the menu of Creo Parametric.
            This function should be executed in the <i>option_cb</i>
            specified by ProCmdOptionAdd().
            <p>
            This function affects the top-level Creo Parametric Ribbon UI only.

   Input Arguments:
      cmd_value                 - The second argument of the <i>option_cb</i>
                                  function

   Output Arguments:
      selected_item             - The name of the selected item in the
                                  radio group

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully returned the value.
      PRO_TK_GENERAL_ERROR      - The function failed to return the value.
*/

extern ProError ProCmdIconSet( uiCmdCmdId              cmd_id,
                               ProCmdItemIcon          cmd_icon );
/*
   Purpose: Designates the icon to be used with a user-created command.
            Adds the icon to the command of Creo Parametric.

   Input Arguments:
      cmd_id            - The command identifier.

      cmd_icon          - The name of the icon file including the extension.
                          It can be either a .PNG, .GIF, .JPG, .PCX, .BMP,
                          .ICO, .CUR file or a Creo Parametric .BIF file.
                          Make sure to provide the filename including a
                          valid file extension, denoting the type of the image
                          as one of the standard formats listed above.
                          PTC recommends using .PNG file.
                          All icons in Creo Parametric Ribbon are either 16x16
                          (small) or 32x32 (large) size. As a standard naming
                          convention icon name should not have 32x32 or 20x20
                          or 16x16 postfix. When Creo Parametric wants to
                          display small icon it looks for iconname.ext and
                          when it looks for large icon it looks for
                          iconname_large.ext file. In order to support legacy
                          applications if iconname.ext is not of 16x16 or 20x20
                          then Creo Parametric looks iconname16x16.ext or
                          iconname20x20.ext. This support will go away in
                          future releases. PTC recommends using standard icon
                          naming conventions i.e. iconname.ext or
                          iconname_large.ext. For example in order to designate
                          both small and large icon to a command, place both
                          my_icon.png and my_icon_large.png in the resource
                          directory and use my_icon.png as icon file name.
  <p><b>Note:</b>
     The default search paths for finding the icons are:
    <ul>
     <li> Creo Parametric Loadpoint/text/resource</li>
     <li> Application text dir/resource</li>
     <li> Application text dir/(language)/resource</li>
    </ul>
     The location of the application text directory is specified in the
     registry file.</p>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The icon was assigned.
      PRO_TK_BAD_INPUTS   - The input arguments were invalid.
      PRO_TK_E_NOT_FOUND  - The icon file was not found.
      PRO_TK_INVALID_FILE - The file specified was not a Creo Parametric .BIF file
                            or a custom .GIF file.
      PRO_TK_INVALID_FILE - The file specified was not of required format.
*/

extern ProError ProCmdDesignate ( uiCmdCmdId         cmd_id,
                                  ProCmdItemLabel    button_label,
                                  ProCmdLineHelp     one_line_help,
                                  ProCmdDescription  description,
                                  ProFileName        msg_file);
/*

   Purpose: Designates the command or Chkbutton option to appear as placeable
            in the Screen Customization dialog. This may not be used for
            existing Creo Parametric system commands.
            Use ProCmdRadiogropDesignate() for designating Radiogrp option.

   Input Arguments:
       cmd_id               - The command identifier.

       button_label         - Message keystring referring to the button label .
                              If the command was not assigned an icon,
                              the button name will appear on the menu
                              button by default.

       one_line_help        - Message keystring referring to the button
                              one line help.
       description          - Message in the customization dialog and click
                              on "Description"
       msg_file             - Message file name for the two keystrings.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The command was designated. Use the Screen Customization
                                  dialog box to place it.
      PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND   - The message file was not found.
      PRO_TK_MSG_NOT_FOUND - One or more messages was not found in the message file.

*/

PRO_END_C_DECLS

#endif
