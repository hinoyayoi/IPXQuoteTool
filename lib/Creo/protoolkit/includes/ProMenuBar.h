

#ifndef PROMENUBAR_H
#define PROMENUBAR_H

/*
   Creo Parametric TOOLKIT declarations for ProMenuBar actions
*/

#include <ProToolkit.h>

#include <ProUICmd.h>

PRO_BEGIN_C_DECLS

typedef char   ProMenuItemName[PRO_NAME_SIZE];
typedef char   ProMenuItemLabel[PRO_LINE_SIZE];
typedef char   ProMenuItemIcon[PRO_LINE_SIZE];
typedef char   ProMenuLineHelp[PRO_LINE_SIZE];
typedef char   ProMenuDescription[PRO_LINE_SIZE];

extern ProError ProMenubarMenuAdd ( 
                             ProMenuItemName         menu_name,
                             ProMenuItemLabel        untranslated_menu_label,
                             ProMenuItemName         neighbor,
                             ProBoolean              add_after_neighbor,
                             ProFileName             filename );
                                 
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: CONTEXTUAL
   Purpose: <b>Note:</b> This API is deprecated. Use Customize UI dialog to
            create menus in Creo Parametric Ribbon UI. 
            <p>
            Adds a new menu to the menu bar of Creo Parametric.  This menu can
            be used later to add another menus, push buttons, check 
            buttons, and radio groups.
            <p>
            This function affects the top-level Creo Parametric menu bar only.
            <p> 
            This function is executed only once during a Creo Parametric
            session for each menu. Subsequent calls to this function
            for a previously loaded menu are ignored.

   Input Arguments:
      menu_name 	        - The name of the menu (must be unique) 
      untranslated_menu_label   - The label of the menu
      neighbor                  - The neighbor menu in the menu bar. <p><b>Note: </b>
                                  If you are adding the first menu to the menu bar of
                                  Creo Parametric, set the <i>neighbor</i> argument to NULL.
      add_after_neighbor        - Defines whether to add the menu 
                                  to the left or right of the neighbor menu;
                                  PRO_B_TRUE specifies to the right.
      filename                  - Name of the message file containing the label

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the menu.
      PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the 
                                  message file.
      PRO_TK_E_FOUND            - a menubar entity with this name already exists.
      PRO_TK_GENERAL_ERROR      - The function failed to add the menu.
*/

extern ProError ProMenubarmenuMenuAdd ( 
                          ProMenuItemName         parent_menu,
                          ProMenuItemName         menu_name,
                          ProMenuItemLabel        menu_label,
                          ProMenuItemName         neighbor,
                          ProBoolean              add_after_neighbor,
                          ProFileName             filename );

/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: CONTEXTUAL
   Purpose: <b>Note:</b> This API is deprecated. Use Customize UI dialog to
            create menus in Creo Parametric Ribbon UI.
            <p>
            Adds a new menu to the menu of Creo Parametric.  This menu can
            be used later to add other menus, actions, and options.
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
            <p>
            This function is executed only once during a Creo Parametric
            session for each menu. Subsequent calls to this function
            for a previously loaded menu are ignored.

   Input Arguments:
      parent_menu          - The name of the parent menu      
      menu_name            - The name of the menu (must be unique)
      menu_label           - The label of the menu
      neighbor             - The neighbor item in the parent menu. <p><b>Note: </b>
                             If you are adding the first menu to the menu of 
                             Creo Parametric, set the <i>neighbor</i> argument to NULL.
      add_after_neighbor   - Defines whether to add the menu before or after
                             the neighbor item; PRO_B_TRUE specifies after.
      filename             - The name of the message file containing the label

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the menu.
      PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the 
                                  message file.
      PRO_TK_E_FOUND            - a menubar entity with this name already exists.
      PRO_TK_GENERAL_ERROR      - The function failed to add the menu.
*/

extern ProError ProMenubarmenuPushbuttonAdd ( ProMenuItemName         parent_menu,
                                ProMenuItemName         push_button_name,
                                ProMenuItemLabel        push_button_label,
                                ProMenuLineHelp         one_line_help,
                                ProMenuItemName         neighbor,
                                ProBoolean              add_after_neighbor,
                                uiCmdCmdId              action_id,
                                ProFileName             filename );

/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: CONTEXTUAL
   Purpose: <b>Note:</b> This API is deprecated. Use Customize UI dialog to
            create menus in Creo Parametric Ribbon UI. 
            <p>
            Adds a new push button to the menu of Creo Parametric.
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
            <p>
            This function is executed only once during a Creo Parametric
            session for each push button. Subsequent calls to this function
            for a previously loaded push button are ignored.
	    <p>
            Note:
	    <p>
             To find the name of an existing item to use as a neighbor, 
             select that item in Creo Parametric and look at your trail file.


   Input Arguments:
      parent_menu		- The name of the parent menu      
      push_button_name          - The name of the push button (must be unique)
      push_button_label         - The label of the push button
      one_line_help             - The one-line help for the push button
      neighbor                  - The neighbor item in the parent menu. <p><b>Note: </b>
                                  If you are adding the first item to a new menu 
                                  (created using either <b>ProMenubarMenuAdd()</b> or 
                                  <b>ProMenubarmenuMenuAdd()</b>), set the 
                                  <i>neighbor</i> argument to NULL.
      add_after_neighbor        - Defines whether to add the button before or
                                  after the neighbor item; PRO_B_TRUE 
                                  specifies after.
      action_id 		- The identifier of the action attached
                                  to the push button
      filename                  - The name of the message file that contains the
                                  label and help string
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added a push button.
      PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the 
                                  message file.
      PRO_TK_E_FOUND            - a menubar entity with this name already exists.
      PRO_TK_GENERAL_ERROR      - The function failed to add a push button.
*/

extern ProError ProMenubarmenuChkbuttonAdd ( ProMenuItemName         parent_menu,
                                 ProMenuItemName         check_button_name,
                                 ProMenuItemLabel        check_button_label,
                                 ProMenuLineHelp         one_line_help,
                                 ProMenuItemName         neighbor,
                                 ProBoolean              add_after_neighbor,
                                 uiCmdCmdId              option_id,
                                 ProFileName             filename );
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProCmdDesignate
   Purpose: <b>Note:</b> This API is deprecated. Use ProCmdDesignate()
            to designate a check button and Customize UI dialog to add it in 
            Creo Parametric Ribbon UI.
            <p>
            Adds a new check button to the menu of Creo Parametric.
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
            <p>
            This function is executed only once during a Creo Parametric
            session for each action. Subsequent calls to this function
            for a previously loaded check button are ignored.
	    <p>
	    Note:
            <p>
            To find the name of an existing item to use as a neighbor, 
            select that item in Creo Parametric and look at your trail file.


   Input Arguments:
      parent_menu               - The name of the parent menu
      check_button_name         - The name of the check button (must be unique)
      check_button_label        - The label of the check button
      one_line_help             - The one-line help for the menu
      neighbor                  - The neighbor item in the parent menu. <p><b>Note: </b>
                                  If you are adding the first item to a new menu 
                                  (created using either <b>ProMenubarMenuAdd()</b> or 
                                  <b>ProMenubarmenuMenuAdd()</b>), set the 
                                  <i>neighbor</i> argument to NULL.
      add_after_neighbor        - Defines whether to add the checkbutton 
                                  before or after the neighbor item; 
                                  PRO_B_TRUE specifies after.
      option_id                 - The identifier of the option attached
                                  to the check button
      filename                  - The name of the message file that
                                  contains the label and help string
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added a check button.
      PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the 
                                  message file.
      PRO_TK_E_FOUND            - a menubar entity with this name already exists.
      PRO_TK_GENERAL_ERROR      - The function failed to add a check button.
*/

extern ProError ProMenubarmenuChkbuttonValueSet (
                                 uiCmdValue             *cmd_value,
                                 ProBoolean              value );
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProCmdChkbuttonValueSet
   Purpose: <b>Note:</b> This API is deprecated. Use ProCmdChkbuttonValueSet() instead.
            <p>
            Sets a new value for the check button in the menu of Creo Parametric.
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
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

extern ProError ProMenubarmenuChkbuttonValueGet (
                                 uiCmdValue             *cmd_value,
                                 ProBoolean             *value );
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProCmdChkbuttonValueGet
   Purpose: <b>Note:</b> This API is deprecated. Use ProCmdChkbuttonValueGet()
            instead.
            <p>
            Gets a new value for the check button in the menu of Creo Parametric.
            This function is executed only in the <i>option_cb</i> specified
            by ProCmdOptionAdd().
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
   
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

extern ProError ProMenubarmenuRadiogrpAdd ( ProMenuItemName      parent_menu,
                                ProMenuItemName      radio_group_name,
                                int                  number_radio_group_items,
                                ProMenuItemName     *radio_group_items,
                                ProMenuItemLabel    *radio_group_labels,
                                ProMenuLineHelp     *one_line_helps,
                                ProMenuItemName      neighbor,
                                ProBoolean           add_after_neighbor,
                                uiCmdCmdId           option_id,
                                ProFileName          filename );
/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProCmdRadiogrpDesignate
   Purpose: <b>Note:</b> This API is deprecated. Use ProCmdRadiogrpDesignate()
            to designate a Radiogrp and Customize UI dialog to add it in 
            Creo Parametric Ribbon UI.
            <p>
            Adds a new radio group to the menu of Creo Parametric.
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
            <p>
            This function is executed only once during a Creo Parametric
            session for each radio group. Subsequent calls to this function
            for a previously loaded radio group are ignored.
	    <p>
	    Note: 
            <p>
            To find the name of an existing item to use as a neighbor, 
            select that item in Creo Parametric and look at your trail file.



   Input Arguments:
      parent_menu               - The name of the parent menu
      radio_group_name		- The name of the radio group (must be unique)
      radio_group_items         - The names of the items in the radio group
      number_radio_group_items	- The number of items in the radio group
      radio_group_labels        - The labels of the items in the radio group
      one_line_helps            - The one-line help strings for the radio group
      neighbor                  - The neighbor item in the parent menu. <p><b>Note: </b>
                                  If you are adding the first item to a new menu 
                                  (created using either <b>ProMenubarMenuAdd()</b> or
                                  <b>ProMenubarmenuMenuAdd()</b>), set the 
                                  <i>neighbor</i> argument to NULL.
      add_after_neighbor        - Defines whether to add the group before or
                                  after the  neighbor item; PRO_B_TRUE specifes
                                  after
      option_id                 - The identifier of the option
      filename                  - The name of the message file that contains
                                  labels and help strings

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR           - The function successfully added the radio group.
      PRO_TK_MSG_NOT_FOUND      - The specified message was not found in the 
                                  message file.      
      PRO_TK_E_FOUND            - a menubar entity with this name already exists.
      PRO_TK_GENERAL_ERROR      - The function failed to add the radio group.
*/

extern ProError ProMenubarMenuRadiogrpValueSet ( uiCmdValue      *cmd_value, 
                                     ProMenuItemName  selected_item );

/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProCmdRadiogrpValueSet
   Purpose: <b>Note:</b> This API is deprecated. Use ProCmdRadiogrpValueSet() instead.
            <p>
            Sets a new value for the radio group in the menu of Creo Parametric.
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
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

extern ProError ProMenubarMenuRadiogrpValueGet ( uiCmdValue      *cmd_value,
                                     ProMenuItemName  selected_item );

/*
   DEPRECATED: Since Creo 1
   SUCCESSORS: ProCmdRadiogrpValueGet
   Purpose: <b>Note:</b> This API is deprecated. Use ProCmdRadiogrpValueGet() instead.
            <p>
            Gets a value of the radio group in the menu of Creo Parametric.
            This function should be executed in the <i>option_cb</i>
            specified by ProCmdOptionAdd().
            <p> 
            This function affects the top-level Creo Parametric menu bar only.
            
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

PRO_END_C_DECLS

#endif /* PROMENUBAR_H */
