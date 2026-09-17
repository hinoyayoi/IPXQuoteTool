#ifndef PROUICASCADEBUTTON_H
#define PROUICASCADEBUTTON_H

#include <ProUI.h>



/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProUICascadebuttonTextSet(
    char       *dialog,
    char       *cascadebutton,
    wchar_t    *label);

/*
   Purpose:    Set the text to appear on the cascadebutton
 
   Input Arguments:
      dialog            - The name of the dialog that contains the cascadebutton
      cascadebutton		- The name of the cascadebutton
      label		- The text to appear on the button
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
*/

extern ProError ProUICascadebuttonHelptextSet (
    char       *dialog,
    char       *cascadebutton,
    wchar_t    *helptext);

/*
   Purpose:    Set the helptext of a cascade button component

   Input Arguments:
      dialog            - The name of the dialog that contains the cascade button
      cascadebutton     - The name of the cascade button component
      helptext          - The help text

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
*/

extern ProError ProUICascadebuttonIsVisible (
    char       *dialog,
    char       *cascadebutton,
    ProBoolean *state);
/*
    Purpose: Checks to see if the Cascadebutton is visible

    Input Arguments:
       dialog            - The name of the dialog that contains the cascade button
       cascadebutton     - The name of the cascade button component

    Output Arguments:
        state            - Whether or not the cascadebutton is visible.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given
*/


extern ProError ProUICascadebuttonShow (
    char       *dialog,
    char       *cascadebutton);

/*
   Purpose:  Makes the Cascadebutton visible

   Input Arguments:
      dialog            - The name of the dialog that contains the cascade button
      cascadebutton     - The name of the cascade button component

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful
      PRO_TK_GENERAL_ERROR    - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICascadebuttonHide (
    char       *dialog,
    char       *cascadebutton);

/*
   Purpose:    Makes the cascadebutton component invisible from the dialog

   Input Arguments:
      dialog            - The name of the dialog that contains the cascade button
      cascadebutton     - The name of the cascade button component

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICascadebuttonIsEnabled (
    char       *dialog,
    char       *cascadebutton,
    ProBoolean *state);
/*
   Purpose:    Checks to see if the button is enabled or not (greyed-out or active)

   Input Arguments:
      dialog            - The name of the dialog that contains the cascade button
      cascadebutton     - The name of the cascade button component

   Output Arguments:
      state             - True - Enabled
                          False - Disabled

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICascadebuttonEnable (
    char       *dialog,
    char       *cascadebutton);

/*
   Purpose:    Enables the cascade button

   Input Arguments:
      dialog            - The name of the dialog that contains the cascade button
      cascadebutton     - The name of the cascade button component
 
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given
*/

extern ProError ProUICascadebuttonDisable (
    char       *dialog,
    char       *cascadebutton);

/*
   Purpose:    Disables the button

   Input Arguments:
      dialog            - The name of the dialog that contains the cascade button
      cascadebutton     - The name of the cascade button component
      
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given
*/




extern ProError ProUICascadebuttonTextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the label of the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - Label of the cascadebutton. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonBitmapSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the bitmap to the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - The name of the bitmap.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonBitmapGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the bitmap of the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - The name of the cascadebutton. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the helptext that will display when the cursor is over 
	     the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - The helptext. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonCascadedirectionSet (char* dialog, char* component, ProUICascadeDirection value);
/*
    Purpose: Set the direction at which the cascadebutton should cascade.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - Cascade direction.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonCascadedirectionGet (char* dialog, char* component, ProUICascadeDirection* value);
/*
    Purpose: Get the direction at which the cascadebutton should cascade.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - Cascade direction. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonPopupmenuSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the popup menu to the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - The name of the popup menu.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonPopupmenuGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the popup menu for the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - The name of the popup menu. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the cascadebutton at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the cascadebutton at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  cascadebutton is attached at left side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the cascadebutton   
                is attached at left. PRO_B_FALSE if the cascadebutton is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the cascadebutton at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the cascadebutton at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  cascadebutton is attached at right side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the cascadebutton  
                is attached at right. PRO_B_FALSE if the cascadebutton is not
	   	attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the cascadebutton at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the cascadebutton at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  cascadebutton is attached at top side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the cascadebutton    
                is attached at top. PRO_B_FALSE if the cascadebutton is not
                 attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the cascadebutton at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the cascadebutton at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  cascadebutton is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the cascadebutton 
                is attached at bottom. PRO_B_FALSE if the cascadebutton is not
	        attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the cascadebutton.

    Input Arguments:
        dialog - The name of the dialog that contains the cascadebutton.
        component - The name of the cascadebutton component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonParentnameSet (char* dialog, char* component, char* value);
/*
     Purpose: Set the name of the parent to the cascadebutton component.

     Input Arguments:
         dialog - The name of the dialog that contains the cascadebutton.
         component - The name of the cascadebutton component.
         value - The name of the parent.
 
     Output Arguments:
	 none
 
     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonParentnameGet (char* dialog, char* component, char** value);
/*
     Purpose: Get the name of the parent to the cascadebutton component.
 
     Input Arguments:
         dialog - The name of the dialog that contains the cascadebutton.
         component - The name of the cascadebutton component.
 
     Output Arguments:
         value - The name of the parent. Free this output using ProStringFree().
 
     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUICascadebuttonChildnamesSet (char* dialog, char* component, int count, char** values);
/*
     Purpose: Set the name of the children to the cascadebutton component.

     Input Arguments:
         dialog - The name of the dialog that contains the cascadebutton.
         component - The name of the cascadebutton component.
         count - Number of children.
         values - Array of names of the children.

     Output Arguments:
	 none

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUICascadebuttonChildnamesGet (char* dialog, char* component, int* count, char*** values);
/*
     Purpose: Get the name of the children to the cascadebutton component.

     Input Arguments:
         dialog - The name of the dialog that contains the cascadebutton.
         component - The name of the cascadebutton component.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree(). 

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUICascadebuttonIsResizeable (
    char         *dialog,
    char         *component,
    ProBoolean   *state
);
/*
    Purpose: Checks to see if the cascadebutton is resizeable or not.

    Input Arguments:
       dialog            - The name of the dialog that contains the cascadebutton
       component         - The name of the cascadebutton component
                          
    Output Arguments:
        state            - Whether or not the cascadebutton is resizeable.

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUICascadebuttonEnableResizing (
    char   *dialog,
    char   *component
);
/*
    Purpose:  Sets the cascadebutton to be resizeable.

    Input Arguments:
       dialog            - The name of the dialog that contains the cascadebutton
       component         - The name of the cascadebutton component
                          
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - The function was successful
        PRO_TK_GENERAL_ERROR    - The function failed
        PRO_TK_BAD_INPUTS       - An invalid argument was given

    <!-- Objectname: ProUI -->
*/

extern ProError ProUICascadebuttonDisableResizing(
    char* dialog,
    char* component);
/*
   Purpose:    Sets the cascadebutton to be non-resizeable.
 
   Input Arguments:
      dialog            - The name of the dialog that contains the cascadebutton.
      component         - The name of the cascadebutton component
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS       - An invalid argument was given

   <!-- Objectname: ProUI -->
*/




PRO_END_C_DECLS
 
#endif  /* PROUICASCADEBUTTON_H */
