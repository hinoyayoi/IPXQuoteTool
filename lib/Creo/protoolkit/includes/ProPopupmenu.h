#ifndef PROPOPUPMENU_H
#define PROPOPUPMENU_H



PRO_BEGIN_C_DECLS

#include <ProToolkit.h>
#include <ProMenuBar.h>
#include <ProSelection.h>


/*===========================================================*/
/* Type definitions                                          */
/*===========================================================*/

typedef int     ProPopupMenuId;

typedef uiCmdAccessState (*ProPopupmenuAccessFunction) (uiCmdCmdId command,
                                                        ProAppData appdata,
                                                        ProSelection* sel_buffer);
/*
    Purpose: Callback for the check of popup menu item access State.

    Input Arguments:
        command -               Command identifier.
        appdata -               User application data
        sel_buffer -            ProArray of selections in the selection buffer 

    Output Arguments:
        None
    Return Values:
        Return the uiCmdAccessState for the menu item for this situation.
*/

/*===========================================================*/
/* Notification callbacks definition                         */
/*===========================================================*/

typedef ProError (*ProPopupmenuCreatePostAction) (const char* name);
/*
    Purpose: This notification function is called after a popup menu is
             created internally in Creo Parametric. 
             Use this notification to assign application-specific buttons
             to the popup menu.
             Users must supply this function by calling 
             ProNotificationSet() with the notify type
             PRO_POPUPMENU_CREATE_POST.

    Input Arguments:
        name -                Popup menu name.

    Output Arguments:
        none 

    Return Values:   
        Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProPopupmenuDestroyPreAction) (const char* name);
/*
    Purpose: This notification function is called before a popup menu is 
             destroyed internally in Creo Parametric. 
             Use this notification to free application-allocated memory
             for the custom buttons in the popup menu.
             Users must supply this function by calling 
             ProNotificationSet() with the notify type
             PRO_POPUPMENU_DESTROY_PRE.

    Input Arguments:
                name -                Popup menu name.

    Output Arguments:
                none 

    Return Values:
        Return values are not interpreted by Creo Parametric.
*/


/*===========================================================*/
/*                        PROPOPUP TOOLKIT API               */
/*===========================================================*/


/*===========================================================*/

LIB_UITOOLS_API  ProError ProPopupmenuIdGet(const char* name, 
                                  ProPopupMenuId *menu_id);
/*
    Purpose: Gets the popup menu id given a popup menu name.

    Input Arguments:
        name                - Menu name.

    Output Arguments:
        menu_id             - Menu Id 

    Return Values:                                         
        PRO_TK_NO_ERROR     - The function successfully got the menu id.
        PRO_TK_E_NOT_FOUND  - No menu with that name.
*/


/*===========================================================*/

LIB_UITOOLS_API  ProError ProPopupmenuNameGet(ProPopupMenuId menu_id, char** p_name);
/*
    Purpose: Gets the popup menu name given a popup menu id.

        Input Arguments:
            menu_id             - Menu Id 

        Output Arguments:
            p_name              - The name of the menu. Free this string
                                  using ProStringFree.
        Return Values:  
            PRO_TK_NO_ERROR     - The function successfully got the menu id.
            PRO_TK_E_NOT_FOUND  - No menu with that name.
*/


/*===========================================================*/

LIB_UITOOLS_API  ProError ProPopupmenuButtonAdd(ProPopupMenuId menu_id, 
                int position,
                ProMenuName  button_name,
                ProLine  button_label,
                ProLine  button_helptext, 
                uiCmdCmdId  cmd_id,
                ProPopupmenuAccessFunction access_status,
                ProAppData appdata);
/*
    Purpose: Add a new item to a Creo Parametric popup menu.
             This function supports pushbutton and checkbutton commands
             created by ProCmdActionAdd() and ProCmdOptionAdd(). 

    Input Arguments:
        menu_id         - The id of the Popup menu.
        position        - Position at which to add the menubutton.
                          Pass PRO_VALUE_UNUSED to append to the
                          end of the relevant menu.
        button_name     - The button name in the Popup Menu (must be unique) 
        button_label    - The button label. To localize this obtain and
                          pass a message string from ProMessageToBuffer().
        button_helptext - The button helptext. To localize this obtain and
                          pass a message string from ProMessageToBuffer().
        cmd_id          - The command name.
        access_status   - The accessibility function for the 
                          added Menu Item. This function is in addition to
			  the command accessibility function.
			  This argument is allowed to be NULL, in which case 
			  the item accessibility will be the command 
			  accessibility.
        appdata         - Application data to be supplied to the 
                          access function. This argument is allowed to be NULL.

    Output Arguments:
        None

    Return Values: 
        PRO_TK_NO_ERROR     - The function successfully added a menu item.
        PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
        PRO_TK_E_FOUND      - Button already exists.
	PRO_TK_INVALID_TYPE - The command type is not supported.
	PRO_TK_INVALID_ITEM - Invalid command.
*/


/*===========================================================*/

LIB_UITOOLS_API  ProError ProPopupmenuCascadebuttonAdd(
                ProPopupMenuId menu_id,
                int position,
                ProMenuName cascade_menu_name,
                ProLine cascade_menu_label,
                ProLine cascade_menu_helptext,
                ProPopupmenuAccessFunction access_status,
                ProAppData appdata,
                ProPopupMenuId *casc_menuId);

/*
    Purpose: Adds cascade to the existing menu.

    Input Arguments:
        menu_id               - The id of the Popup menu.
        position              - Position at which to add the cascade button.
                                Pass PRO_VALUE_UNUSED to append to the end 
                                of the relevant menu.
        cascade_menu_name     - The cascade menu name (must be unique)  
        cascade_menu_label    - The cascade menu label. To localize this
                                obtain and pass a message string from 
                                ProMessageToBuffer().
        cascade_menu_helptext - The cascade menu helptext. To localize this 
                                obtain and pass a message string from 
                                ProMessageToBuffer().
        access_status         - The accessibility function for the added 
                                Menu Item. This argument is allowed to be NULL,
				in which case the item will be always accessible.
        appdata               - userdata to be given to any menu callback
                                This argument is allowed to be NULL.

    Output Arguments:
        casc_menuId           - menuId of the newly added  cascade menu.

    Return Values:
        PRO_TK_NO_ERROR     - The function successfully created a Cascade Menu.
        PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
        PRO_TK_E_FOUND      -    Cascade menu was already found.
*/

/* -------------------------------------------------------- */
PRO_END_C_DECLS
#endif
