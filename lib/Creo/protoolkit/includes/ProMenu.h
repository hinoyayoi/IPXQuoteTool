

#ifndef PROMENU_H
#define PROMENU_H

/*
   Internal Creo Parametric TOOLKIT declarations for ProMenu actions
*/

#include <ProToolkit.h>

/* for ProMenuName, ProMenufileName, . . . */
#include <ProSizeConst.h>

/* for ProAppData */
#include <ProObjects.h>

/* for ProMode */
/* NO LONGER BELONGS HERE, but ~90 sample files don't build without it */
#include <ProMode.h>


PRO_BEGIN_C_DECLS

typedef enum
{
  PROMENUTYPE_MAIN,
  PROMENUTYPE_SUB
} ProMenuType;

typedef enum
{
  PROMENUMODE_OPERATIONAL,
  PROMENUMODE_DATA
} ProMenuMode;

/*===========================================================================*/

extern ProError ProMenuFileRegister(ProMenuName     menuname,
				    ProMenufileName filename,
				    int             *menu_id);
/*
   Purpose: Defines a new Creo Parametric menu by reading in a menu file.
	    This function is executed only once during a Creo Parametric
	    session for each menu. Subsequent calls to this function
	    for a previously loaded menu are ignored.
<p>
             This function affects Menu-Manager (mode-specific) menus only.


   Input Arguments:
      menuname		- The name of the menu.
      filename		- The name of the menu file.

   Output Arguments:
      menu_id		- The identifier of the created menu.
                          This argument can be NULL.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully defined the menu.
      PRO_TK_GENERAL_ERROR - The menu file was not found.
*/

extern ProError ProMenuAuxfileRegister(ProMenuName menuname,
				       ProMenufileName filename,
				       int *menu_id);
/*
    Purpose: Extends an existing Creo Parametric menu by reading in an
	     auxiliary menu file. This enables you to maintain
	     additions to standard Creo Parametric menus in separate
	     files, but have them appear as part of the Creo Parametric
	     menu file.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
	     The recommended way of adding new items to the standard
	     Creo Parametric menus is as follows:
<ul>
             <li>The menu <I>menuname</I> must have been loaded via
               <B>ProMenuFileRegister()</B> before this function can be called,
               and it cannot be active on the screen at the time of this call.

              <li>The argument <I>filename</I> must be different from the 
                  standard Creo Parametric menu name.

              <li>The contents of <I>filename</I> must adhere to the 
	       Creo Parametric menu standards. Specifically, the first three 
               lines must be the
               same as the Creo Parametric menu file, after which this file
               need only contain your additions.
</ul> 

   Input Arguments:
      menuname		- The name of the menu.
      filename		- The name of the auxiliary menu file.

   Output Arguments:
      menu_id		- The identifier of the extended menu
                          This argument can be NULL.

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully extended the menu.
      PRO_TK_GENERAL_ERROR - The auxiliary menu file was not found.

   See Also:
      ProMenuFileRegister()  
 
*/

typedef int (*ProMenubuttonAction)(ProAppData app_data,
				   int app_int);

/*
   Purpose: This is the prototype for the callback functions attached to 
            the Creo Parametric menu buttons by a call to the function
            <b>ProMenubuttonActionSet()</b>.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

   Input Arguments:
      app_data	- General application data as provided by the call to 
		  <b>ProMenubuttonActionSet()</b> that defines this button
      app_int	- Integer application data as provided by the call to 
		  <b>ProMenubuttonActionSet()</b> that defines this button

   Output Arguments:
      None

   Return Values:
	Ignored
*/


extern ProError ProMenubuttonActionSet(ProMenuName menuname,
				       ProMenubuttonName button,
				       ProMenubuttonAction action,
				       ProAppData app_data,
				       int app_int);
/*
   Purpose: 
            Specifies the action to perform when the user selects a 
            particular menu button added by the Creo Parametric TOOLKIT
            application.
<p>
           This function affects Menu-Manager (mode-specific) menus only.   
<p>
	    The action is defined by passing a pointer to a C function 
	    (the callback function) in the Creo Parametric TOOLKIT application that
	    is to be called when the user selects that button.
<p>
	    If the button name supplied is the name of the menu, instead
	    of one of the buttons on it, the function defines the exit
	    action for the menu (the function to be called when the user
	    selects a command from a different menu).
<p>
	    The arguments <i>app_data</i> and <i>app_int</i> are passed as 
	    input arguments to the command function whenever it is called. Use
	    the function <b>ProMenubuttonGenactionSet()</b> when you need to
            pass more than two arguments.
<p>
	    NOTES:
<ul>
             <li>The arguments <i>app_data</i> and <i>app_int</i> must be one 
                 of the following types:
               <ul>
               <li>Statically allocated variables.
               <li>Constants.
               <li>Dynamically allocated local variables, but only
                if a local command loop is activated in the
                routine that contains the declarations. The
                location of the variable is unknown if the
                routine making the declaration is not
                on the stack.
               </ul>
             <li>The menu must be loaded (via <b>ProMenuFileRegister()</b>) 
                 before the actions are specified. 
</ul>

   Input Arguments:
      menuname		- The name of the menu
      button		- The name of the menu button
      action		- The callback function
      app_data	        - The general application data passed to the
		          callback function when it is called
      app_int	        - The integer application data passed to the
                          callback function when it is called

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully defined the button 
                             action.
      PRO_TK_GENERAL_ERROR - Either the menu or the button does not exist.
    
*/

typedef int (*ProMenubuttonGenaction)(ProAppData app_data,
				      int        app_int);
/*
   Purpose: This is the prototype for the callback functions attached to 
            Creo Parametric menu buttons by a call to the function
	    <b>ProMenubuttonGenactionSet()</b>.
            <p>
            This function affects Menu-Manager (mode-specific) menus only.
 
   Input Arguments:
      app_data - The general application data as provided by the call to 
                  <b>ProMenubuttonActionSet()</b> that defines this button
      app_int  - The integer application data as provided by the call to 
                  <b>ProMenubuttonActionSet()</b> that defines this button

   Output Arguments:
      None

   Return Values:
	Ignored
*/

extern ProError ProMenubuttonGenactionSet(ProMenuName menuname,
					  ProMenubuttonName button,
					  ProMenubuttonGenaction action,
					  ProAppData app_data1,
					  ProAppData app_data2,
					  ProAppData app_data3,
					  ProAppData app_data4,
					  ProAppData app_data5,
					  ProAppData app_data6);

/*
   Purpose: 
      Specifies the action to perform when the user selects a particular
      menu button added by the Creo Parametric TOOLKIT application.
      This function performs the same task as <b>ProMenubuttonActionSet()</b>,
      but provides for more application data. 
<p>
      This function affects Menu-Manager (mode-specific) menus only.
<p>
      See the function <b>ProMenubuttonActionSet()</b> for more information on 
      these two functions.

   Input Arguments:
      menuname		- The name of the menu
      button		- The name of the menu button
      action		- The callback function
      app_data1		- The general application data passed to the
			  callback function when it is called
      app_data2		- The general application data passed to the
			  callback function when it is called
      app_data3		- The general application data passed to the
			  callback function when it is called
      app_data4		- The general application data passed to the
			  callback function when it is called
      app_data5		- The general application data passed to the
			  callback function when it is called
      app_data6		- The general application data passed to the
			  callback function when it is called

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully defined the button 
                             action.
      PRO_TK_GENERAL_ERROR - Either the menu or the button does not exist.
 
   See Also:
      ProMenubuttonActionSet()
   
*/

extern ProError ProMenuProcess(ProMenuName menuname,
			       int *action);

/*
    Purpose: Makes the specified menu active. Creo Parametric allows the user to
	     pick the buttons on it until the menu closes.
<p>
             This function affects Menu-Manager (mode-specific) menus only.  
<p>
	     The function returns only when the menu is closed as a result
	     of a call to <b>ProMenuDelete()</b> or 
             <b>ProMenuDeleteWithStatus()</b>, in
	     one of the actions defined for that menu.

    Input Arguments:
	menuname	- The name of the menu.

    Output Arguments:
	action		- If you used <b>ProMenuDeleteWithStatus()</b> to 
                          delete the menu, this is the status value
                          passed to that function.
                          If you used <b>ProMenuDelete()</b> to delete the menu,
		          this value is undefined.
    Return Values:
	PRO_TK_NO_ERROR - You used <b>ProMenuDeleteWithStatus()</b> to delete 
                          the menu.
	PRO_TK_E_FOUND  - You used <b>ProMenuDelete()</b> to delete the menu, 
                          so no status is set.

    See Also:
        ProMenuDelete()
        ProMenuDeleteWithStatus()  
*/

extern ProError ProMenuDelete ( void );

/*
    Purpose: Closes the currently active menu. The current menu is the menu
	     referenced from the last call to <B>ProMenuProcess()</B>. Control
	     returns from that call as a result of the call to 
             <B>ProMenuDelete()</B>
	     or <B>ProMenuDeleteWithStatus()</B>.
<p>
             This function affects Menu-Manager (mode-specific) menus only.   
<p>

	     The menu that becomes active after this one is closed is the
	     menu immediately above it in the menu hierarchy. This is also
	     the menu made active by the previous call to 
             <B>ProMenuProcess()</B>.

    Input Arguments:
       None

    Output Arguments:
       None

    Return Values:
	PRO_TK_NO_ERROR - The function successfully closed the current menu.

    See Also:
        ProMenuDeleteWithStatus()
        ProMenuProcess()

    <b>NOTE:</b> Do not use this function for exit buttons on compound menus;
    use <b>ProMenuDeleteWithStatus()</b> instead.
*/

extern ProError ProMenuCreate(ProMenuType type,
			      ProMenuName menuname,
			      int *menu_id);

/*

    Purpose: 
       Displays the menu on the screen. A menu must be loaded before
       it can be displayed; when a menu is redisplayed, all menu
       items are accessible.
<p>
       This function affects Menu-Manager (mode-specific) menus only.   
<p>

       The menu type is almost always a main menu (type PROMENUTYPE_MAIN).
       An example of a submenu (type PROMENUTYPE_SUB) is the Done/Quit
       submenu below the Sketcher menu. Done/Quit has no title and
       serves only as an extension of the Sketcher menu (the
       PROMENUTYPE_MAIN menu).

    Input Arguments:
	type		- The menu type (PROMENUTYPE_MAIN for a main menu,
			  PROMENUTYPE_SUB for a submenu).
	menuname	- The name of the menu.
    
    Output Arguments:
	menu_id		- The identifier of the menu displayed.
                          This argument can be NULL.

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully displayed the menu. 
	PRO_TK_GENERAL_ERROR - The specified menu does not exist.

    See Also:
        ProMenuFromStringsRegister()
*/

extern ProError ProMenuHold (void);

/*
    Purpose: Prevents the menu from being closed when the user selects
	     from another menu, if this function is defined as the exit
	     action for a menu. Use this function if you want the user
	     to take some definite action before leaving the current menu.
<p>
             This function affects Menu-Manager (mode-specific) menus only.   
<p>
	     To use this function, you must ensure that at least one of
	     the buttons on the menu results in a call to either
	     <b>ProMenuDelete()</b> or <b>ProMenuDeleteWithStatus()</b>. 
	     Otherwise, there will be no route out of the menu.
    
    Input Arguments:
             None
	
    Output Arguments:
             None

    Return Values:
	PRO_TK_NO_ERROR - The function was successful.

    See Also:
        ProMenuDelete()
        ProMenuDeleteWithStatus()
*/


extern ProError ProMenuDeleteWithStatus(int exit_status);

/*
    Purpose: Closes the currently active menu. The current menu is the menu
	     referenced from the last call to <B>ProMenuProcess()</B>, 
	     and control returns from that call as a result of the call to
	     <B>ProMenuDeleteWithStatus()</B>. The integer value supplied as an
	     argument is returned from the call to <B>ProMenuProcess()</B>.
	     This can be used to distinguish several possible ways of 
             closing a menu.
<p>
             This function affects Menu-Manager (mode-specific) menus only.   
<p>
	     The menu that becomes active after this one is closed is the
	     menu immediately above it in the menu hierarchy. This is also
	     the menu made active by the previous call to 
             <b>ProMenuProcess()</b>.


    Input Arguments:
	exit_status	- The value to be returned from the call to
                          <b>ProMenuProcess()</b> for the current menu

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR - The function successfully closed the currently active
                          menu.
 
    See Also:
        ProMenuProcess()
*/


extern ProError ProCompoundmenuCreate(char **menus,
				      int *n_submenus);

/*
    Purpose: Takes an array of previously loaded menus and appends them
	     into one menu.

    Input Arguments:
	menus          - An array of menu names, terminated by an empty string
    
    Output Arguments:
	n_submenus     - The number of menus in the compound menu

    Return Values:
	PRO_TK_NO_ERROR - The function successfully created the compound menu.

    <b>NOTE</b>: use <b>ProMenuDeleteWithStatus()</b> as the action to
    perform when the user selects an exit button from a compound menu, rather
    than <b>ProMenuDelete()</b>.
*/

extern ProError ProMenubuttonPreactionSet(ProMenuName menuname,
					  ProMenubuttonName button,
					  ProMenubuttonAction action,
					  ProAppData app_data,
					  int app_int);

/*
    Purpose: Enables you to interpose your own function into an existing
	     Creo Parametric menu button. When the user selects that button,
	     your function is called first, instead of the Creo Parametric
	     function. The Creo Parametric function may or may not get called
	     afterwards, depending on what value your functions returns (0
	     for success and 1 for failure).
<p>
             This function affects Menu-Manager (mode-specific) menus only.   
<p>

	     Note that this has the same arguments as 
             <b>ProMenubuttonActionSet()</b>,
	     and, like that function, modifies the Creo Parametric definition of
	     the menu. Therefore, you must call this function after
	     <b>ProMenuFileRegister()</b>, which loads the menu into memory.

    Input Arguments:
	menuname	- The name of the menu
	button		- The name of the menu button
	action		- The callback function to be called before the
			  Creo Parametric command
        app_data	- The general application data passed to the
			  callback function when it is called
        app_int		- The integer application data passed to the
			  callback function when it is called
    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully set the pre-action.
	PRO_TK_GENERAL_ERROR - There was a general error and the function
                               failed.

    See Also:
        ProMenubuttonActionSet() 
        ProMenuFileRegister()

*/

extern ProError ProMenubuttonPostactionSet(ProMenuName menuname,
					   ProMenubuttonName button,
					   ProMenubuttonAction action,
					   ProAppData app_data,
					   int app_int);
/*
    Purpose: Binds a user function so it is called after Creo Parametric has
	     finished executing the action associated with the specified
	     button.
<p>
             This function affects Menu-Manager (mode-specific) menus only.   
<p>

    Input Arguments:
	menuname	- The name of the menu.
	button		- The name of the menu button.
	action		- The callback function to be called before the
			  Creo Parametric command. This function must return a
                          value of 0 to return control to Creo Parametric.
        app_data	- The general application data passed to the
			  callback function when it is called.
        app_int		- The integer application data passed to the
			  callback function when it is called.

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully set the post-action.
	PRO_TK_GENERAL_ERROR - There was a general error and the function
                               failed.
*/

extern ProError ProMenubuttonLocationSet(ProMenuName menuname,
					 ProMenubuttonName button,
					 int location);

/*
    Purpose: Enables you to determine where in the menu the new button is
	     placed, relative to the existing entries, which are referenced
	     by their sequence number. You can also use this to move
	     existing Creo Parametric menu buttons.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
	     The possible location positions are as follows:
<ul>
        <li>-1 -- After the last item in the menu

        <li>0 -- Before the first item in the menu

        <li>1 -- Before the second item

        <li>n -- Before the <i>n</i>th + 1 item
</ul>
<p>
	    All other items in the menu stay in the same order as before. 
	    You can call this function after creating a menu name with
	    <b>ProMenuFileRegister()</b>, but before it appears on the screen.
	    Otherwise, this function fails.

    Input Arguments:
	menuname        - The name of the menu
	button          - The name of the menu button
	location	- The new location

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully set the location.
	PRO_TK_GENERAL_ERROR  - There was a general error and the function
                                failed.

    See Also:
        ProMenuFileRegister()

*/

extern ProError ProMenubuttonVisibilitySet(ProMenuName menuname,
					   ProMenubuttonName button,
					   ProBoolean visible);

/*
    Purpose: Controls the display status by removing a menu item from a
	     menu. This function must be called after the menu was created
	     (<b>ProMenuFileRegister()</b>) and before the menu is displayed
	     (<b>ProMenuCreate()</b>).
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
             The function cannot be used for menus created by Creo Parametric, 
             only those defined by the Pro/TOOKIT application.

    Input Arguments:
	menuname        - The name of the menu
	button          - The name of the menu button
	visible		- Specifies whether to make the menu item 
                          visible or invisible

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully set the visibility.
	PRO_TK_GENERAL_ERROR  - There was a general error and the function
                                failed.

    See Also:
        ProMenuCreate()
        ProMenuFileRegister()
*/

extern ProError ProMenubuttonDelete(ProMenuName menuname,
				    ProMenubuttonName button,
				    int* result);
/*
    Purpose: Permanently disables a menu item by removing a specified button
	     from a menu. It can be called only after the menu has been
	     read in by <b>ProMenuFileRegister()</b> and while the menu is not
	     active.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu.
	button          - The name of the menu button. 

    Output Arguments:
	result		- The result. The possible values are as follows:
                          <ul>
                          <li>1 -- Everything worked.
			  <li>0 -- The menu has not been created (see
                          the function <b>ProMenuFileRegister()</b>).
			  <li>-1 -- The menu is already active.
			  <li>-2 -- The specified button does not exist in
                          the specified menu.
                          </ul>

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully deleted the menu
                               button.
	PRO_TK_GENERAL_ERROR - There was a general error and the function
                               failed.

    See Also:
        ProMenuFileRegister()

*/

extern ProError ProMenuModeSet(ProMenuName menuname,
			       ProMenuMode mode);
/*
    Purpose: Sets the mode of the specified menu. You must call this function
	     after <b>ProMenuFileRegister()</b>, but before 
             <b>ProMenuCreate()</b>.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu.
	mode		- The menu mode. The possible values are
                          PROMENUMODE_OPERATIONAL (the
                          selected button remains highlighted only
                          during the action of the command) and 
                          PROMENUMODE_DATA (the menu buttons are
                          alternately highlighted and
                          unhighlighted on selection).

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully set the mode.
	PRO_TK_GENERAL_ERROR  - A general error occurred and the
                                function failed.

    See Also:
        ProMenuCreate()
        ProMenuFileRegister()
*/

extern ProError ProMenuDatamodeSet(ProMenuName menuname,
				   ProBoolean checkmark);
/*
    Purpose: Sets the mode of a data menu to use either normal highlighting,
	     or check-mark highlighting. Call this function before calling
	     <B>ProMenuCreate()</B>.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu
	checkmark	- Specifies whether to use a check mark or 
                          ordinary highlighting

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully set the mode.
	PRO_TK_GENERAL_ERROR - There was a general error and the function
                               failed.

    See Also:
        ProMenuCreate()
*/

extern ProError ProMenubuttonHighlight(ProMenuName menuname,
				       ProMenubuttonName button);
/*
    Purpose: Makes the specified button active and highlighted. Use this 
             to show a default choice to the user. This function must be
	     called after <b>ProMenuFileRegister()</b>, but before 
             <b>ProMenuCreate()</b>.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu
	button		- The name of the menu button

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully highlighted the
                                button. 
	PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.

    See Also:
        ProMenuCreate()
        ProMenuFileRegister()

*/


extern ProError ProMenubuttonUnhighlight(ProMenuName menuname,
				         ProMenubuttonName button);
/*
    Purpose: Makes the specified button inactive, and removes the highlighting.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu
	button		- The name of the menu button

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully made the button
                                inactive.
	PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
*/

extern ProError ProMenubuttonActivate(ProMenuName menuname,
				      ProMenubuttonName button);
/*
    Purpose: Sets a menu item to be accessible.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    NOTE:  
<p>
    Only items of menus currently displayed on the screen can be set
    to accessible. You cannot make accessible a menu item that
    Creo Parametric itself has made inaccessible.

    Input Arguments:
	menuname        - The name of the menu
	button          - The name of the menu button

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully made the button
                               accessible.
	PRO_TK_GENERAL_ERROR - A general error occurred and the function 
                               failed.
*/

extern ProError ProMenubuttonDeactivate(ProMenuName menuname,
				        ProMenubuttonName button);
/*
    Purpose: Sets a menu item to be inaccessible. 
	     Only items of menus currently displayed
	     on the screen can be set to be inaccessible.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu
	button          - The name of the menu button

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully made the button 
                               inaccessible.
	PRO_TK_GENERAL_ERROR - A general error occurred and the function
                               failed.
*/

extern ProError ProMenuVisibilityGet (ProMenuName menuname,
				      ProBoolean *visible);
/*
    Purpose: Determines whether the specified menu is currently displayed.
<p>
             This function affects Menu-Manager (mode-specific) menus only.

    Input Arguments:
	menuname        - The name of the menu

    Output Arguments:
	visible		- Specifies whether the menu is visible

    Return Values:
	PRO_TK_NO_ERROR - The function successfully retrieved the
                          information.
*/

extern ProError ProMenuPush(void);
/*
    Purpose: Temporarily hides the last menu created, even though it is 
	     strictly still in context, to make room for lower-level menus.
	     The functions <b>ProMenuPush()</b>, <b>ProMenuPop()</b>, and
	     <b>ProMenuVisibilityGet()</b> let you push a menu, pop a menu, 
	     and ask whether a menu is currently visible.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
	     An example of this is when you select Make Datum during
	     feature creation. This is called pushing menus because they are
	     put on a LIFO stack from which they can be popped to make them
	     reappear.
<p>
	     It is the responsibility of the application developer to use
	     the correct sequence of calls to <b>ProMenuCreate()</b>,
	     <b>ProMenuDeleteWithStatus()</b>, <b>ProMenuPush()</b>, 
             and <b>ProMenuPop()</b>.
<p>
	     If a main menu has submenus, they are treated as one and are
	     pushed together with one call to <b>ProMenuPush()</b>.


    Input Arguments:
       None

    Output Arguments:
       None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully pushed the
                                menu.
	PRO_TK_GENERAL_ERROR  - A general error occurred and the
                                function failed.

    See Also:
        ProMenuCreate()
        ProMenuDeleteWithStatus()
        ProMenuPop()
        ProMenuVisibilityGet()
 
*/

extern ProError ProMenuPop(void);
/*
    Purpose: Puts the menu last pushed onto the stack back onto the screen.
	     You can only pop the menu back to the same position from which
	     it was pushed.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
	     It is the responsibility of the application developer to use
	     the correct sequence of calls to <b>ProMenuCreate()</b>,
	     <b>ProMenuDeleteWithStatus()</b>, <b>ProMenuPush()</b>, 
             and <b>ProMenuPop()</b>.
<p>
	     If a main menu has submenus, they are treated as one and are
	     popped together with one call to <b>ProMenuPop()</b>.
<p>
	     If there is more than one menu in a frame (a compound menu),
	     all the menus in the frame are popped by one call to 
             <b>ProMenuPop()</b>.


    Input Arguments:
       None

    Output Arguments:
       None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully popped the menu.
	PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.

    See Also:
        ProMenuCreate()
        ProMenuDeleteWithStatus()
        ProMenuPush()
        
*/


extern ProError ProMenuStringsSelect(ProName title,
				     wchar_t **strings,
				     int max_count,
				     wchar_t **help,
				     wchar_t ***selected,
				     int *n_selected);
/*
    Purpose: Sets up a menu containing buttons defined by an array of
	     strings. The function makes the menu active, closes it after a
	     specified number of selections (or quit), and returns a list of
	     the selected strings.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
	     This function is intended for menus that depend on run-time data.
	     You do not need to define a menu file for this type of menu, and
	     you do not attach actions to its buttons using
	     <b>ProMenubuttonActionSet()</b>.


    Input Arguments:
	title		- A wide string containing the menu title to be
			  displayed.

	strings		- A list of wide strings defining the menu buttons,
			  terminated by an empty string. Individual strings
                          can be no longer than PRO_NAME_SIZE-1.

	max_count	- The maximum number of selections allowed. Use the
			  value PRO_VALUE_UNUSED for an unlimited number of selections.

	help		- A list of wide strings defining the one-line help
			  strings for the menu buttons.

    Output Arguments:
	selected	- The wide strings selected by the user. The function
			  allocates memory for these strings, and reuses the
			  memory on subsequent calls.
	n_selected	- The number of strings selected.

    Return Values:
	PRO_TK_NO_ERROR   - The function successfully set up the menu.
	PRO_TK_USER_ABORT - The user selected no strings (selected Quit, or
			    Done with no strings selected, or some other menu).
   
    See Also:
        ProMenubuttonActionSet()

*/

extern ProError ProMacroLoad (wchar_t* macro);
/*
    Purpose: Loads a sequence of Creo Parametric commands. A command sequence
	     is placed on the stack and is executed once control returns to
	     Creo Parametric.
<p>
	     The sequence correctness is the user's responsibility; it is
	     not guaranteed that a sequence will be valid from one revision
	     of Creo Parametric to another. It may be possible that a certain
	     macro cannot be executed because a command specified in
	     the macro is currently inaccessible in the menus (dimmed).
<p>
	     This function only uses the "original" menu item name in a command
	     sequence. The alternate item name, if present, is not recognized
	     by this function.


    Input Arguments:
	macro	- A wide string representation of the command macro

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully loaded the command
                               sequence.
	PRO_TK_GENERAL_ERROR - A general error occurred and the function
                               failed.

*/

extern ProError ProMenuCommandPush (ProMenubuttonName command);
/*
    Purpose: Puts the specified menu button in the command input buffer
	     for Creo Parametric, so that command will be executed as soon as
	     control returns to Creo Parametric from the Creo Parametric TOOLKIT
	     application, exactly as if the user has selected that button.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
	     The button must be one that is currently selectable -- that is, on
	     a menu currently being displayed.

    Input Arguments:
	command		- The command to be pushed

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR       - The function successfully pushed the command. 
	PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.

*/

extern ProError ProMenuFromStringsRegister( ProMenuName menu_name, 
                                            ProName     alt_name,
                                            wchar_t    *item_names[],
                                            wchar_t    *alt_names[],
                                            wchar_t    *short_help[],
                                            int        *menu_id );


/*
   Purpose:  Defines a new Creo Parametric menu by creating a menu on-the-fly.
             This function is executed only once during a Creo Parametric
             session for each menu. Subsequent calls to this function
             for a previously loaded menu are ignored.
<p>
             This function affects Menu-Manager (mode-specific) menus only.
<p>
             NOTE:
<p>
             If <i>short_help</i> or <i>alt_names</i> is not NULL, 
             the number of 
             elements in the array should be the same as the 
	     number of menu items in
             <i>item_names</i>.


   Input Arguments:
      menu_name  -  The name of the menu.  If <i>alt_name</i> is NULL,
                    <i>menu_name</i> is used as the menu title when
                    the menu is displayed.  You should use <i>menu_name</i> 
                    to set button actions.
      alt_name   -  An alternate name for the menu. This is used for 
                    foreign languagues.
      item_names -  The menu item names. This list is terminated by a NULL 
                    string. If <i>alt_names</i> is NULL, the function
                    uses <i>item_names</I> as menu items.
      alt_names  -  The alternate names for the menu items.
      short_help -  The one-line help for each menu item. This list is 
                    terminated by a NULL string. 
                    This can be NULL if no short help is needed.



   Output Arguments:
      menu_id - The identifier of the created menu.
                This argument can be NULL.


   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the menu.  
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed. 
*/

extern ProError ProMacroExecute ( void );
/*
    Purpose: Executes a macro from within a Creo Parametric TOOLKIT application, 
             and returns the control back to Creo Parametric TOOLKIT. It executes the 
             macros previously loaded using the function ProMacroLoad().

<p>
	     Note that this function is not supported for the following 
	     situations and tasks

	     <OL START=1 TYPE="1">
	     <LI>Activating windows or setting the current model
	     <LI>Erasing the current model 
	     <LI>Completing dialog commands ending with an "OK" button press. 
		It will cancel some dialogs after showing them.
	     <LI>Executing macros during a trail file replay. 
	     </OL>

    Input Arguments:
	None

    Output Arguments:
        None

    Return Values:
	PRO_TK_NO_ERROR      - The function successfully loaded the command
                               sequence.
	PRO_TK_NOT_VALID     - The specified macro is not valid. 

*/

PRO_END_C_DECLS

#endif /* PROMENU_H */
