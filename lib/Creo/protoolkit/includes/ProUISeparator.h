#ifndef PROUI_SEPARATOR_H_
#define PROUI_SEPARATOR_H_



#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProUI.h>

PRO_BEGIN_C_DECLS

extern ProError ProUISeparatorShow (char* dialog, char* component);
/*
    Purpose: Set the separator visible.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorHide (char* dialog, char* component);
/*
    Purpose: Set the separator not visible.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorIsVisible (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the separator is visible or hidden.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        state - PRO_B_TRUE when the separator is visible.
		PRO_B_FALSE when the separator is hidden.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorPopupmenuSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the popup menu to the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.
        value - The name of the popup menu.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorPopupmenuGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the popup menu of the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        value - The name of the separator. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorAttachLeft (char* dialog, char* component);
/*
    Purpose: To attach the separator at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorUnattachLeft (char* dialog, char* component);
/*
    Purpose: To not attach the separator at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorIsAttachedLeft (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  separator is attached at left side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        state - state of the left attachment. PRO_B_TRUE if the separator       
                is attached at left. PRO_B_FALSE if the separator is not
                attached at left.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorAttachRight (char* dialog, char* component);
/*
    Purpose: To attach the separator at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorUnattachRight (char* dialog, char* component);
/*
    Purpose: To not attach the separator at right side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorIsAttachedRight (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  separator is attached at right side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        state - state of the right attachment. PRO_B_TRUE if the separator      
                is attached at right. PRO_B_FALSE if the separator is not
                attached at right.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorAttachTop (char* dialog, char* component);
/*
    Purpose: To attach the separator at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorUnattachTop (char* dialog, char* component);
/*
    Purpose: To not attach the separator at top side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorIsAttachedTop (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  separator is attached at top side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        state - state of the top attachment. PRO_B_TRUE if the separator        
                is attached at top. PRO_B_FALSE if the separator is not 
	   	attached at top.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorAttachBottom (char* dialog, char* component);
/*
    Purpose: To attach the separator at bottom side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorUnattachBottom (char* dialog, char* component);
/*
    Purpose: To not attach the separator at bottom side of the parent 
             component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorIsAttachedBottom (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: To check if the  separator is attached at bottom side of the 
             parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        state - state of the bottom attachment. PRO_B_TRUE if the separator     
                is attached at bottom. PRO_B_FALSE if the separator is not
                attached at bottom.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorLeftoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set left offset to the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.
        value - Left offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorLeftoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get left offset of the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorRightoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set right offset to the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.
        value - Right offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorRightoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get right offset of the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorTopoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set top offset to the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.
        value - Top offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorTopoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get top offset of the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorBottomoffsetSet (char* dialog, char* component, int value);
/*
    Purpose: Set bottom offset to the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUISeparatorBottomoffsetGet (char* dialog, char* component, int* value);
/*
    Purpose: Get bottom offset of the separator.

    Input Arguments:
        dialog - The name of the dialog that contains the separator.
        component - The name of the separator component.

    Output Arguments:
        value - Bottom offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


PRO_END_C_DECLS

#endif
