#ifndef PROUITREE_H_
#define PROUITREE_H_


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProUI.h>

PRO_BEGIN_C_DECLS



extern ProError ProUITreeTreecolumnorderSet (char* dialog, char* component, int count, char** values);
/*
    Purpose: Set the column order of attribute window in a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of columns.
        values - Array of columns in order which they should appear in the 
                 attribute window. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecolumnorderGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Get the column order of the attribute window in a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of columns.
        values - Array of columns displayed in attribute window. Free this 
                 using ProStringarrayFree ().  If this array is empty, this
                 indicates that the columns will be displayed in the order
                 in which they were created.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreeredrawSet (char* dialog, char* component, ProBoolean value);
/*
    Purpose: Set the flag indicating whether redraw is allowed.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Flag to redraw the tree. PRO_B_TRUE to redraw the tree;
                PRO_B_FALSE to not redraw the tree.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreeredrawGet (char* dialog, char* component, ProBoolean* value);
/*
    Purpose: Get the flag indicating whether redraw is allowed.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Redraw flag of tree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecurrentnodeSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the name of the current node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Name of the node.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecurrentnodeGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the name of the current node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Name of the current node. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreeexpcolnodeGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the node that was expanded or collapsed to generate a 'expand 
             action' or 'collapse action' respectively.

    Input Arguments:
        dialog - The dialog in which tree exists.
        component - The tree component.

    Output Arguments:
        value - Name of the node. Free this using ProStringFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeExpandActionSet()
        ProUITreeCollapseActionSet()
*/

extern ProError ProUITreeTreerootnodeSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the name of the root node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The tree component.
        value - Name of the node set to be root.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreerootnodeGet (char* dialog, char* component, char** value);
/*
    Purpose: Obtain the name of the root node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Name of the root node in a tree. Free this using 
                ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSelectednamesSet (char* dialog, char* component, int count, char** values);
/*
    Purpose: Set the names of the currently selected nodes.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of node names.
        values - Array of node names that are to be set as selected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSelectednamesGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Obtain the names of the currently selected nodes.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of node names.
        values - Array of node names that are selected. Free this using 
                 ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSelectionpolicySet (char* dialog, char* component, ProUISelectionpolicy value);
/*
    Purpose: Set the selection policy for the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Selection policy for the tree.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSelectionpolicyGet (char* dialog, char* component, ProUISelectionpolicy* value);
/*
    Purpose: Get the selection policy that is already set to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Selection policy for the tree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeEnable (char* dialog, char* component);
/*
    Purpose: Set the tree to be sensitive to user input.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeDisable (char* dialog, char* component);
/*
    Purpose: Set the tree to be insensitive to user input.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeIsEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if a tree is tree is sensitive or insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the tree is enabled; PRO_B_FALSE when the tree 
                is disabled.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeHelptextSet (char* dialog, char* component, wchar_t* value);
/*
    Purpose: Set the help text to display when the cursor is over the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Help text to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeHelptextGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the help text that will be displayed when the cursor is over a 
             tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Help text for the tree. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellselnodeSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the node which governs the selected cell in the attribute 
             window of a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Name of the node in a cell in attribute window.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellselnodeGet (char* dialog, char* component, char** value);
/*
    Purpose: Obtain the node which governs the selected cell in the attribute 
             window of a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Name of the selected node in a cell in attribute window. Free 
                this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellselcolSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the node which governs the selected column in the attribute 
             window of a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Name of the column that should be selected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellselcolGet (char* dialog, char* component, char** value);
/*
    Purpose: Obtain the node which governs the selected column in the attribute 
             window of a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Name of the column in a cell in attribute window. Free this using ProStringFree ().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellinputGet (char* dialog, char* component, wchar_t** value);
/*
    Purpose: Get the changed cell text that caused a cell input action.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Text in a cell in attribute window. Free this using 
                ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreecellinputActionSet()
*/



extern ProError ProUITreeForegroundcolorSet (char* dialog, char* component, ProUIColor value);
/*
    Purpose: Set the foreground color to a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - The foreground color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeForegroundcolorGet (char* dialog, char* component, ProUIColor* value);
/*
    Purpose: Get the foreground color to a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - The foreground color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeBackgroundcolorSet (char* dialog, char* component, ProUIColor value);
/*
    Purpose: Set the background color type to a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - The background color.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeBackgroundcolorGet (char* dialog, char* component, ProUIColor* value);
/*
    Purpose: Get the background color type of a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - The background color.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeShow (char* dialog, char* component);
/*
    Purpose: Make the tree visible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeHide (char* dialog, char* component);
/*
    Purpose: Make the tree invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeIsVisible (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Determines if the tree is visible or invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the tree is shown; PRO_B_FALSE when the tree is 
                hidden.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreenodetypeexpandedimagesSet (char* dialog, char* component, int count, char** values);
/*
    Purpose: Set the images to be displayed with the expanded node of the node 
             types of the tree.     Note: The order matches the order of the 
             node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of images.
        values - Array of images to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypeexpandedimagesGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Get the images displayed with the expanded node of the node types 
             of the tree.     Note: The order matches the order of the node 
             type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of images.
        values - Array of images displayed. Free this using 
                 ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypecollapsedimagesSet (char* dialog, char* component, int count, char** values);
/*
    Purpose: Set the images to be displayed with the collapsed nodes of the 
             node types of the tree.     Note: The order matches the order of 
             the node type names. 

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of images.
        values - Array of images to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypecollapsedimagesGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Get the images displayed with the collapsed nodes of the node 
             types of the tree.     Note: The order matches the order of the 
             node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of images.
        values - Array of images displayed. Free this using 
                 ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypenamesSet (char* dialog, char* component, int count, char** values);
/*
    Purpose: Set the name of the node types of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of node type names.
        values - Array of name of the node type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreenodetypenamesGet (char* dialog, char* component, int* count, char*** values);
/*
    Purpose: Get the name of the node types of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of node type names.
        values - Array of name of the node types. Free this using 
                 ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreenodetypehelptextsSet (char* dialog, char* component, int count, wchar_t** values);
/*
    Purpose: Set the help text of the nodes of the node types of the tree.     
             Note: The order matches the order of the node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of help texts.
        values - Array of help text of the nodes of the node types.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypehelptextsGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the help text of the nodes of the node types of the tree.     
             Note: The order matches the order of the node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of help texts.
        values - Array of help text of the nodes of the node types. Free this 
                 using ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypeprefixesSet (char* dialog, char* component, int count, wchar_t** values);
/*
    Purpose: Set the text to be prepended to the labels of the nodes of the 
             node types of the tree.     Note: The order matches the order of 
             the node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of texts.
        values - Array of text to be prepended to the labels.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypeprefixesGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the text prepended to the labels of the nodes of the node 
             types of the tree.     Note: The order matches the order of the 
             node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of texts.
        values - Array of text prepended to the labels. Free this using 
                 ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypeappendsSet (char* dialog, char* component, int count, wchar_t** values);
/*
    Purpose: Set the text to be appended to the labels of the nodes of the node 
             types of the tree.     Note: The order matches the order of the 
             node type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        count - Number of texts.
        values - Array of text to be appended to the labels.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeTreenodetypeappendsGet (char* dialog, char* component, int* count, wchar_t*** values);
/*
    Purpose: Get the text appended to the labels of the nodes of the node types 
             of the tree.     Note: The order matches the order of the node 
             type names.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        count - Number of texts.
        values - Array of text appended to the labels. Free this using 
                 ProWstringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreenodetypenamesGet()
*/

extern ProError ProUITreeShowRootnode (char* dialog, char* component);
/*
    Purpose: Show the root node of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeHideRootnode (char* dialog, char* component);
/*
    Purpose: Hide the root node of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeIsRootnodeVisible (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the root node of the tree is shown or hidden.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the root node is shown; PRO_B_FALSE when the 
                root node is hidden.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeRowsSet (char* dialog, char* component, int value);
/*
    Purpose: Set the number of rows of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Number of rows in the tree.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeRowsGet (char* dialog, char* component, int* value);
/*
    Purpose: Get the number of rows in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Number of rows in the tree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeEnableCellkeyboardinput (char* dialog, char* component);
/*
    Purpose: Set the attribute window of the tree respond to keyboard input and 
             generate a 'input action'.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreecellinputActionSet()
*/

extern ProError ProUITreeDisableCellkeyboardinput (char* dialog, char* component);
/*
    Purpose: Set the attribute window of the tree not to respond for the 
             keyboard input.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreecellinputActionSet()
*/

extern ProError ProUITreeIsCellkeyboardinputEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the attribute window of the tree respond or not respond 
             to the keyboard input.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the attribute window respond to the keyboard 
                input; PRO_B_FALSE when the attribute window not respond to the 
                keyboard input.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreecellinputActionSet()
*/

extern ProError ProUITreeUseScrollbarswhenNeeded (char* dialog, char* component);
/*
    Purpose: Display scrollbars in tree only when they are required.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeAlwaysUsescrollBars (char* dialog, char* component);
/*
    Purpose: Display scrollbars in tree always.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeUsesScrollbarswhenneeded (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if scrollbars in tree are displayed only when they are 
             needed or always.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the scrollbars are displayed only when they are 
                needed; PRO_B_FALSE when the scrollbars are displayed always.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeActivateonreturnEnable (char* dialog, char* component);
/*
    Purpose: Set the tree to generate an activate action by pressing the RETURN 
             key while the tree is in focus.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeActivateActionSet()
*/

extern ProError ProUITreeActivateonreturnDisable (char* dialog, char* component);
/*
    Purpose: Set the tree to not generate an activate action by pressing the 
             RETURN key while the tree is in focus.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeActivateActionSet()
*/

extern ProError ProUITreeIsActivateonreturnEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Identify if the tree is set to generate an activate action by 
             pressing the RETURN key while the tree is in focus.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the press of RETURN key enabled; PRO_B_FALSE 
                when the press of RETURN key disabled.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeActivateActionSet()
*/

extern ProError ProUITreeMappedSet (char* dialog, char* component);
/*
    Purpose: Set the tree to occupy space when invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeMappedUnset (char* dialog, char* component);
/*
    Purpose: Set the tree not to occupy space when invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeIsMapped (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks if the tree occupies any space when it is invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when tree occupy space when it is invisible; 
                PRO_B_FALSE when tree does not occupy any space when it is 
                invisible.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSelectcbregardlessSet (char* dialog, char* component, ProBoolean value);
/*
    Purpose: Set the flag to consider or ignore the reselection of a currently 
             selected item in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - PRO_B_TRUE to invoke a selection action when the currently 
                selected item is reselected; PRO_B_FALSE to ignore the 
                reselection of the currently selected item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeSelectActionSet()
*/

extern ProError ProUITreeSelectcbregardlessGet (char* dialog, char* component, ProBoolean* value);
/*
    Purpose: To know if the reselection of the currently selected item will be 
             considered or ignored.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - PRO_B_TRUE when the reselection of currently selected item will 
                call callback function; PRO_B_FALSE when the reselection of 
                currently selected item in tree will be ignored.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeSelectActionSet()
*/

extern ProError ProUITreePopupmenuSet (char* dialog, char* component, char* value);
/*
    Purpose: Set the name of the menupane to be displayed when the user presses 
             the right mouse button over the component. A value of "" indicates 
             that the parent's own popup menu should be displayed.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Name of the popup menu to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreePopupmenuGet (char* dialog, char* component, char** value);
/*
    Purpose: Get the name of the menupane that is displayed when the user 
             presses the right mouse button over the component.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Name of the popup menu that is displayed. Free this using 
                ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeEnablePopupwheninsensitive (char* dialog, char* component);
/*
    Purpose: Shows the popup menu when the tree is insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeDisablePopupwheninsensitive (char* dialog, char* component);
/*
    Purpose: Hides the popup menu when the tree is insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeIsPopupwheninsensitiveEnabled (char* dialog, char* component, ProBoolean* state);
/*
    Purpose: Checks the status (shown/hidden) of the popup menu when the tree is 
             insensitive.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        state - PRO_B_TRUE when the popup menu is shown for the insensitive 
                tree; PRO_B_FALSE when the popup menu is hidden for the 
                insensitive tree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeCheckbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new checkbutton to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the checkbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeDrawingareaAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new drawingarea to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the drawingarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeInputpanelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new inputpanel to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the inputpanel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeLabelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new label to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeLayoutAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new layout to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the label to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeListAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new list to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the list to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeOptionmenuAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new optionmenu to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the optionmenu to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeProgressbarAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new progressbar to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the progressbar to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreePushbuttonAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new pushbutton to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the pushbutton to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeRadiogroupAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new radiogroup to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the radiogroup to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSliderAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new slider to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the slider to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSpinboxAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new spinbox to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the spinbox to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTabAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new tab to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the tab to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTableAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new table to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the table to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTextareaAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new textarea to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the textarea to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeThumbwheelAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new thumbwheel to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the thumbwheel to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreeAdd (char* dialog, char* component, char* name);
/*
    Purpose: Add a new tree to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the tree to be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeCheckbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a checkbutton from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the checkbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeDrawingareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a drawingarea from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the drawingarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeInputpanelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a inputpanel from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the inputpanel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeLabelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a label from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the label to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeLayoutRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a layout from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the layout to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeListRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a list from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the tree to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeOptionmenuRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a optionmenu from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the optionmenu to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeProgressbarRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a progressbar from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the progressbar to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreePushbuttonRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a pushbutton from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the pushbutton to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeRadiogroupRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a radiogroup from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the radiogroup to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSliderRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a slider from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the slider to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSpinboxRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a spinbox from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the spinbox to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTabRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a tab from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the tab to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTableRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a table from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the table to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTextareaRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a textarea from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the textarea to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeThumbwheelRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a thumbwheel from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the thumbwheel to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreeRemove (char* dialog, char* component, char* name);
/*
    Purpose: Remove a tree from the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the tree to be removed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeAnchorSet (char* dialog, char* component, int x, int y, ProUIAnchor anchor);
/*
    Purpose: Sets the position of the tree with respect to a given anchor 
              location. This function is applicable  only if the parent of 
	      the tree is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.
        anchor - Location on the tree used to set the position.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSizeSet (
    char               *dialog, 
    char               *component, 
    int                 width, 
    int                 height);

/*
     Purpose: Set the size of the tree. This field is used only
              if the parent is a drawing area.
              If the width or the height parameter is passed a value smaller
              than the tree's minimum size, the function will fail.
              The tree's minimum size can be retrieved
              using ProUITreeMinimumsizeGet.

    Input Arguments:
        dialog - The name of the dialog that contains tree.
        component - The name of the tree component.
        width - Width value
        height - Height value

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreePositionSet (char* dialog, char* component, int x, int y);
/*
     Purpose: Set the position to the tree with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreePositionGet (char* dialog, char* component, int* x, int* y);
/*
     Purpose: Get the position of the tree with respect to its parent.
              This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        x - X value with respect to the upper left corner of the parent.
        y - Y value with respect to the upper left corner of the parent.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeMinimumsizeGet (
    char               *dialog, 
    char               *component, 
    int                *min_width, 
    int                *min_height);

/*
    Purpose: Get the minimum size of the tree in pixels. 
             This field is used only if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        min_width - Minimum width value.
        min_height - Minimum height value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSizeGet (char* dialog, char* component, int* width, int* height);
/*
     Purpose: Get the size of the tree. This field is used only 
              if the parent is a drawing area.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        width - Width of the tree.
        height - Height of the tree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeComponentSet (char* dialog, char* component, char* name, char* node_component, char* column);
/*
    Purpose: Set the component to be displayed in the given column 
             corresponding to the given node name of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.
        node_component - Node component to be displayed.
        column - Column in which the node component should display. If "", the 
                 component is displayed for the node itself. If the
		 column is NULL, then the node component will display 
		 over the node.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeChildrenGet (char* dialog, char* component, char* name, int* count, char*** children);
/*
    Purpose: Get the child nodes for the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        count - Number of child nodes.
        children - Array of children. Free this using ProStringarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeLabelGet (char* dialog, char* component, char* name, wchar_t** label);
/*
    Purpose: Get the label of the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        label - Label name. Free this using ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeLabelSet (char* dialog, char* component, char* name, wchar_t* label);
/*
    Purpose: Set the label of the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.
        label - Label name.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeParentGet (char* dialog, char* component, char* name, char** parent);
/*
    Purpose: Get the parent of the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node. 

    Output Arguments:
        parent - Name of the parent. If the node is the tree root node, this
	       value will be NULL.  Otherwise, free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeGet (char* dialog, char* component, char* name, char** type);
/*
    Purpose: Get the name of the node type associated with the node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        type - Name of the node type. Free this using ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeSet (char* dialog, char* component, char* name, char* type);
/*
    Purpose: Set the name of the node type associated with the node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.
        type - Name of the node type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeExtentsGet (char* dialog, char* component, char* name, ProUIRectangle* extents);
/*
    Purpose: Get the boundary of the node of the tree relative to the top-left 
             corner of the dialog.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        extents - Rectangle of the node.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnCreate (char* dialog, char* component, char* name, wchar_t* title, int width, ProUITreeColumnJustification justify);
/*
    Purpose: Create a column of the given name in the attribute window of the 
             tree. The name must be unique within the scope of the columns of 
             the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the attribute window in which column should be added.
        title - Title that should be displayed above the column.
        width - Width of the column in character widths.
        justify - Left/Right/Center justification.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError ProUITreeNodesOfTypeGet (char* dialog, char* component, char* name, char*** nodes, int* count);
/*
    Purpose: Get the name of all nodes of the tree associated with the node 
             type.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node type.

    Output Arguments:
        nodes - Array of nodes. Free using ProStringarrayFree().
        count - Number of nodes.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSashPositionGet (char* dialog, char* component, int* position);
/*
    Purpose: Get the position of the sash between the tree hierarchy and the 
             attribute window.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        position - Position of the sash.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnTitleGet (char* dialog, char* component, char* name, wchar_t** title);
/*
    Purpose: Obtain the title of a column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.

    Output Arguments:
        title - Title that will be displayed above the column. Free this using 
                ProStringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnWidthGet (char* dialog, char* component, char* name, int* width);
/*
    Purpose: Obtain the width of a column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.

    Output Arguments:
        width - Width of the column in character widths.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnVisibilityGet (char* dialog, char* component, char* name, ProBoolean* visible);
/*
    Purpose: Obtain the visibility of a column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.

    Output Arguments:
        visible - PRO_B_TRUE when the column is visible; PRO_B_FALSE when the 
                  column is not visible.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnJustificationGet (char* dialog, char* component, char* name, ProUITreeColumnJustification* justify);
/*
    Purpose: Obtain the justification of a column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.

    Output Arguments:
        justify - Justification of the node attributes displayed in the column.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnTitleSet (char* dialog, char* component, char* name, wchar_t* title);
/*
    Purpose: Set a title to the column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.
        title - Title to be displayed above the column.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITreeColumnWidthSet (char* dialog, char* component, char* name, int width);
/*
    Purpose: Set a width to the column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.
        width - Width of the column in character widths.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnVisibilitySet (char* dialog, char* component, char* name, ProBoolean visible);
/*
    Purpose: Set visibility of the column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.
        visible - PRO_B_TRUE to set the column to be visible; PRO_B_FALSE to set 
                  the column not to be visible.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeColumnJustificationSet (char* dialog, char* component, char* name, ProUITreeColumnJustification justify);
/*
    Purpose: Set justification to the column in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the column.
        justify - Justification of the node attributes to be displayed in the 
                  column.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeAdd (char* dialog, char* component, char* name, wchar_t* label, char* parent, char* type);
/*
    Purpose: Add a new node to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.
        label - Label to be displayed for the node.
        parent - Name of the parent. If parent is NULL then the root node is 
                 created if it does not already exist.
        type - Node type to which the node should be associated.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeInsert (char* dialog, char* component, char* name, wchar_t* label, char* parent, char* type, char* sibling);
/*
    Purpose: Insert a new node before a node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be inserted.
        label - Label to be displayed for the inserted node.
        parent - Name of the parent node. If parent is NULL then the root node 
                 is created if it does not already exist.
        type - Node type to which the inserted node is associated.
        sibling - Name of the node before which the new node should be 
                  inserted.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeCollapse (char* dialog, char* component, char* name);
/*
    Purpose: Collapse a node in the tree making its children invisible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node that is to be collapsed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeDelete (char* dialog, char* component, char* name);
/*
    Purpose: Delete the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be deleted.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeExists (char* dialog, char* component, char* name, ProBoolean* exist);
/*
    Purpose: Checks if the given node exists or not.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node for which existence should be checked.

    Output Arguments:
        exist - PRO_B_TRUE when the given node exists; PRO_B_FALSE when the 
                given node doesn't exists.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeExpand (char* dialog, char* component, char* name, ProBoolean recurse);
/*
    Purpose: Expand the node of the tree making all of its children visible.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be expanded.
        recurse - Flag representing whether the expansion should be recursive 
                  and expand all of the descendents of the node.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeHelptextGet (char* dialog, char* component, char* name, wchar_t** helptext);
/*
    Purpose: Get the help text of the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        helptext - Helptext of the given node. Free this using 
                   ProWstringFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeIsVisible (char* dialog, char* component, char* name, ProBoolean* visible);
/*
    Purpose: Checks if the node is shown or hidden.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        visible - PRO_B_TRUE when the node is visible; PRO_B_FALSE when the node 
                  is hidden.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeIsExpanded (char* dialog, char* component, char* name, ProBoolean* expanded);
/*
    Purpose: Checks if the node is expanded or collapsed.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        expanded - PRO_B_TRUE when the node is expanded; PRO_B_FALSE when the 
                   node is collapsed.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeIsSelected (char* dialog, char* component, char* name, ProBoolean* selected);
/*
    Purpose: Checks if the node is selected or not.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        selected - PRO_B_TRUE when the node is selected; PRO_B_FALSE when the 
                   node is not selected.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeFontstyleGet (char* dialog, char* component, char* name, ProUIFontStyle* fontstyle);
/*
    Purpose: Get the fontstyle of the node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.

    Output Arguments:
        fontstyle - Fontstyle of the node.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeHelptextSet (char* dialog, char* component, char* name, wchar_t* helptext);
/*
    Purpose: Set the helptext of the node in tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.
        helptext - Helptext of the node.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeShow (char* dialog, char* component, char* name);
/*
    Purpose: Display the node in a tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeHide (char* dialog, char* component, char* name);
/*
    Purpose: Hide the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be displayed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeSelect (char* dialog, char* component, char* name);
/*
    Purpose: Select the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be selected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeDeselect (char* dialog, char* component, char* name);
/*
    Purpose: Unselect the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node to be unselected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeFontstyleSet (char* dialog, char* component, char* name, ProUIFontStyle fontstyle);
/*
    Purpose: Set fontstyle to the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node for which fontstyle should be set.
        fontstyle - Font.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeMove (char* dialog, char* component, char* name, char* new_parent);
/*
    Purpose: Move the node in the tree to a child of the given parent node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the child which is to be moved.
        new_parent - Node that should be parent to the moved node.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeRename (char* dialog, char* component, char* name, char* new_name);
/*
    Purpose: Rename the given node of the tree using the given name.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node that should be renamed.
        new_name - New name to the node,.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodetypeAdd (char* dialog, char* component, ProUITreeNodeType data);
/*
    Purpose: Add a new node type to the tree using the information supplied in 
             the given data structure. Use ProUITreeNodeTypeAlloc to fill the
	     ProUITreeNodeType.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        data - Node type that should be added.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodetypeDelete (char* dialog, char* component, char* node_type);
/*
    Purpose: Delete a node type from the tree using the information supplied in 
             the given data structure.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        node_type - Name of the node type to be deleted.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeColumntextSet (char* dialog, char* component, char* name, wchar_t* text, char* column);
/*
    Purpose: Set the given text to be displayed in the given column 
             corresponding to the given node of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        name - Name of the node.
        text - Text to be displayed.
        column - Column name at which the text should display.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodesSelect (char* dialog, char* component, char** nodes, int count);
/*
    Purpose: Select an array of nodes in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        nodes - Array of names of the nodes which are to be selected.
        count - Number of nodes.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodetypeSelect (char* dialog, char* component, char* identifier);
/*
    Purpose: Select all the nodes corresponding to a given node type.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        identifier - Node type to be selected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeAllnodesSelect (char* dialog, char* component);
/*
    Purpose: Select all nodes in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodesDeselect (char* dialog, char* component, char** nodes, int count);
/*
    Purpose: Unselect an array of nodes in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        nodes - An array of nodes that should be unselected.
        count - Number of nodes to be unselected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodetypeDeselect (char* dialog, char* component, char* identifier);
/*
    Purpose: Unselect all the nodes corresponding to a given node type.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        identifier - Node type that should be unselected.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeAllnodesDeselect (char* dialog, char* component);
/*
    Purpose: Unselect all the nodes in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeSelectActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the tree is selected. 
             The left mouse button, the SPACE key and the navigation keys (if 
             the selection policy is PROUISELPOLICY_BROWSE or 
             PROUISELPOLICY_EXTENDED) can be used to make a selection in the 
             tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when the tree is selected.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeSelectcbregardlessSet()
        ProUITreeSelectcbregardlessGet()
*/

extern ProError ProUITreeActivateActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the tree is activated. 
             The tree is activated by the press of RETURN key or the double 
             click of LEFT mouse button over the node in the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when the tree is activated.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeActivateonreturnEnable()
        ProUITreeActivateonreturnDisable()
        ProUITreeIsActivateonreturnEnabled()
*/

extern ProError ProUITreeExpandActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the user attempts 
             to expand a tree node by clicking on the '+' sign.
	     <P><B>NOTE:</B>  You must make this callback call 
             ProUITreeNodeExpand() to actually expand the node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when node is expanded.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreeexpcolnodeGet()
*/

extern ProError ProUITreeCollapseActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the user attempts 
             to collapse a tree node by clicking on the '-' sign.
	     <P><B>NOTE:</B>  You must make this callback call 
             ProUITreeNodeCollapse() to actually collapse the node.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when node is collapsed.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreeexpcolnodeGet()
*/

extern ProError ProUITreeFocusinActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the tree has got 
             keyboard input focus.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when treenode has got focus.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeFocusoutActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the tree has lost 
             keyboard input focus.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when treenode has lost focus.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellselectActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the cell of the 
             attribute window of the tree has been selected.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when the cell of attribute window is 
                   selected.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellactivateActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the cell of the 
             attribute window of the tree has been activated.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when the cell of the attribute is activated.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeTreecellinputActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when text has been entered 
             into a cell of the attribute window of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when the text is input to the cell.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUITreeTreecellinputGet()
        ProUITreeEnableCellkeyboardinput()
        ProUITreeDisableCellkeyboardinput()
        ProUITreeIsCellkeyboardinputEnabled()
*/

extern ProError ProUITreeTreecelldeleteActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the DELETE key has been 
             pressed in a cell of the attribute window of the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when DELETE key has been pressed in a cell.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeMoveActionSet (char* dialog, char* component, ProUIAction callback, ProAppData data);
/*
    Purpose: Set the action function to be called when the sash of the tree 
             between the tree hierarchy and the attribute window has been 
             moved.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        callback -  Function to be called when sash has been moved.
        data - Action data passed to the callback function. Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeUpdateActionSet (
    char           *dialog,
    char           *component,
    ProUIAction     callback,
    ProAppData      data);


/*
   Purpose:    Sets the update action for a tree

   Input Arguments:
      dialog            - The name of the dialog that contains the tree
      component         - The name of the tree component
      callback          - The update action for the tree
      data              - User data to be passed to the action function.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR   - The function failed
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUITreeParentnameGet (char *dialog, char *component, char **value);
/*
     Purpose: Get the name of the parent to the tree component.

     Input Arguments:
         dialog - The name of the dialog that contains the tree.
         component - The name of the tree component.

     Output Arguments:
         value - The name of the parent. Free this using ProStringFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeChildnamesGet (char *dialog, char *component, int *count, char ***values);
/*
     Purpose: Get the name of the children to the tree component.

     Input Arguments:
         dialog - The name of the dialog that contains the tree.
         component - The name of the tree component.

     Output Arguments:
         count - Number of children.
         values - Array of names of the children. Free this using ProStringarrayFree ().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef  ProError (*ProUITreeNodeVisitAction) (char* dialog, char* component,
		char* node_name, ProError err, ProAppData appdata);
/*
     Purpose: This is a function for visiting nodes.

     Input Arguments:
         dialog - The name of the dialog that contains the tree.
         component - The name of the tree component.
         node_name - The name of the node under which all nodes should be visited.
	 err - The status of action on the visiting node.
	 appdata - The application data passed to the function
		<b>ProUITreeNodesVisit</b>

     Output Arguments:
	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef ProError (*ProUITreeNodeFilterAction) (char* dialog, char* component,
		char* node_name, ProAppData appdata);

/*
     Purpose: This is a function for filtering nodes.

     Input Arguments:
         dialog - The name of the dialog that contains the tree.
         component - The name of the tree component.
         node_name - The name of the node under which all nodes should be visited.
	 appdata - The application data passed to the function
		<b>ProUITreeNodesVisit</b>

     Output Arguments:
	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodesVisit (char* dialog, char* component,
        char* node_name, ProUITreeNodeVisitAction action,
        ProUITreeNodeFilterAction filter,
        ProAppData appdata);
/*
     Purpose: Visits all the descendent nodes of the given node in the tree.

     Input Arguments:
         dialog - The name of the dialog that contains the tree.
         component - The name of the tree component.
	 node_name - The name of the node under which all nodes should be visited.
	 action - The visiting function. If it returns anything other than
			PRO_TK_NO_ERROR, then visiting stops.
	 filter - The filter function. If NULL all nodes will be visited by
			the visiting function.
	 appdata - The application data passed to the filter and visiting function. Can be NULL.

     Output Arguments:
	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeAlloc (char* node_type_name, 
					ProUITreeNodeType* data);
/*
     Purpose: To allocate ProUITreeNodeType data.  

     Input Arguments:
	 node_type_name - Name of the node type.

     Output Arguments:
	 data - The allocated node type data. Free this using 
	        ProUITreeNodeTypeFree().

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeFree ( ProUITreeNodeType data);
/*
     Purpose: To free ProUITreeNodeType data. 

     Input Arguments:
	 data - Nodetype data that is to be freed.

     Output Arguments:
 	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeExpandImageSet (ProUITreeNodeType data, char* image);
/*
     Purpose: Set the image to appear when the nodetype is expanded. 

     Input Arguments:
	 data - Nodetype data.
         image - Name of the image to be set.

     Output Arguments:
 	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeExpandImageGet (ProUITreeNodeType data, char** image);
/*
     Purpose: Get the image that appears when the nodetype is expanded.

     Input Arguments:
	 data - Nodetype data.

     Output Arguments:
	 image - Name of the expanded image.

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProUITreeNodeTypeCollapseImageSet (ProUITreeNodeType data, char* image);
/*
     Purpose: Set the image to appear when the nodetype is collapsed.

     Input Arguments:
	 data - Nodetype data.
	 image - Name of the collapsed image to be set.

     Output Arguments:
 	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITreeNodeTypeCollapseImageGet (ProUITreeNodeType data, char** image);
/*
     Purpose: Get the image that appears when the nodetype is collapsed. 

     Input Arguments:
	 data - Nodetype data.

     Output Arguments:
	 image - Name of the collapsed image.

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITreeNodeTypePrefixSet (ProUITreeNodeType data, wchar_t* prefix);
/*
     Purpose: Set prefix to the nodetype.

     Input Arguments:
	 data - Nodetype data.
	 prefix - String to be added as prefix to the nodetype.

     Output Arguments:
 	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypePrefixGet (ProUITreeNodeType data, wchar_t** prefix);
/*
     Purpose: Get prefix of the nodetype.

     Input Arguments:
	 data - Nodetype data.

     Output Arguments:
	 prefix - prefix string to the nodetype.

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeAppendStringSet (ProUITreeNodeType data, wchar_t* append);
/*
     Purpose: Append the string to the nodetype.

     Input Arguments:
	 data - Nodetype data.
	 append - String to be appended.

     Output Arguments:
 	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeAppendStringGet (ProUITreeNodeType data, wchar_t** append);
/*
     Purpose:  Get the Appended string to the nodetype.

     Input Arguments:
	 data - Nodetype data.

     Output Arguments:
	 append - Appended string.

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeNodeTypeNodesSet ( ProUITreeNodeType data, int num_nodes, char** array_nodes);
/*
     Purpose: Set the nodes to the nodetype.

     Input Arguments:
	 data - Nodetype data.
	 num_nodes - Number of nodes to be added.
	 array_nodes - List of node named added to the nodetype.

     Output Arguments:
 	 None

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITreeNodeTypeNodesGet ( ProUITreeNodeType data, int *num_nodes, char*** array_nodes);
/*
     Purpose: Get the nodes to the nodetype.

     Input Arguments:
	 data - Nodetype data.

     Output Arguments:
	 num_nodes - Number of nodes.
	 array_nodes - List of nodes to a nodetype.

     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_GENERAL_ERROR - The function failed.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITreeAttachLeft (
    char   *dialog, 
    char   *component);

/*
    Purpose: To attach the tree at left side of the parent component.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        none
 
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/


extern ProError ProUITreeUnattachLeft (
    char   *dialog, 
    char   *component);

/* 
    Purpose: To not attach the tree at left side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeIsAttachedLeft (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state
);

/* 
    Purpose: To check if the tree is attached at left side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
	state - PRO_B_TRUE when the tree is attached at left side of the parent component.
		PRO_B_FALSE when the tree is not attached at left side of the parent component.
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeAttachRight (
    char   *dialog, 
    char   *component);
 
/* 
    Purpose: To attach the tree at right side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/


extern ProError ProUITreeUnattachRight (
    char   *dialog, 
    char   *component);

/* 
    Purpose: To not attach the tree at right side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeIsAttachedRight (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state
);

/* 
    Purpose: To check if the tree is attached at right side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
	state - PRO_B_TRUE when tree is attached at right side of the parent component.
		PRO_B_FALSE when tree is not attached at right side of the parent component.
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeAttachTop (
    char   *dialog, 
    char   *component);

/* 
    Purpose: To attach the tree at top side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeUnattachTop (
    char   *dialog, 
    char   *component);

/* 
    Purpose: To not attach the tree at top side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeIsAttachedTop (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state
);

/* 
    Purpose: To check if the tree is attached at top side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
	state - PRO_B_TRUE when the tree is attached at top side of the parent component.
		PRO_B_FALSE when the tree is not attached at top side of the parent component.
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeAttachBottom (
    char   *dialog, 
    char   *component);

/* 
    Purpose: To attach the tree at bottom side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/



extern ProError ProUITreeUnattachBottom (
    char   *dialog, 
    char   *component);

/* 
    Purpose: To attach the tree at bottom side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
        none 
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUITreeIsAttachedBottom (
    char           *dialog, 
    char           *component, 
    ProBoolean     *state
);

/* 
    Purpose: To check if the tree is attached at bottom side of the parent component. 
 
    Input Arguments: 
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
 
    Output Arguments: 
	state - PRO_B_TRUE when the tree is attached at bottom side of the parent component.
		PRO_B_FALSE when the tree is not attached at bottom side of the parent component.
  
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
  
*/

extern ProError ProUITreeLeftoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);

/*
    Purpose: Set left offset to the tree.
 
    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
	value - Left offset value.

    Output Arguments:
	none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeLeftoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);

/*
    Purpose: Get left offset to the tree.
 
    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
	value - Left offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeRightoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);

/* 
    Purpose: Set right offset to the tree.
  
    Input Arguments: 
        dialog - The name of the dialog that contains the tree. 
        component - The name of the tree component. 
        value - Right offset value.
 
    Output Arguments:
        none
 
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid. 
 
*/ 



extern ProError ProUITreeRightoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);

/*
    Purpose: Get right offset to the tree.
 
    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
	value - Right offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/


extern ProError ProUITreeTopoffsetSet (
    char                   *dialog, 
    char                   *component, 
    int                     value);

/* 
    Purpose: Set top offset to the tree.
  
    Input Arguments: 
        dialog - The name of the dialog that contains the tree. 
        component - The name of the tree component. 
        value - Top offset value.
 
    Output Arguments:
        none
 
    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - The function failed. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid. 
 
*/ 

extern ProError ProUITreeTopoffsetGet (
    char                   *dialog, 
    char                   *component, 
    int                    *value);

/*
    Purpose: Get top offset to the tree.
 
    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
	value - Top offset value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeBottomoffsetSet (
    char                   *dialog,
    char                   *component,
    int                     value);

/*
    Purpose: Set bottom offset to the tree.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        value - Bottom offset value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeBottomoffsetGet (
    char                   *dialog,
    char                   *component,
    int                    *value);
 
/*
    Purpose: Get bottom offset to the tree.
 
    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - Bottom offset value.
 
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/

extern ProError ProUITreeStateSet (
    char               *dialog,
    char               *component,
    char               *item,
    ProBoolean          state);
/*
    Purpose: Set the state of the item in the tree. The state is applicable
             only for a "check" type of tree and refers to the checked or
             unchecked status of the item.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        item - The name of the item in the tree.
        state - State of the item. PRO_B_TRUE if the item is to be checked.
                PRO_B_FALSE if the item is to be unchecked. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeStateGet (
    char               *dialog,
    char               *component,
    char               *item,
    ProBoolean         *state);
/*
    Purpose: Get the state of the item in the tree. The state is applicable
             only for a "check" type of tree and refers to the checked or
             unchecked status of the item.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        item - The name of the item in the tree.

    Output Arguments:
        state - State of the item. PRO_B_TRUE if the item is checked.
                PRO_B_FALSE if the item is unchecked. 
                This argument is not allowed to be NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeMixedStateSet (
    char               *dialog,
    char               *component,
    char               *item,
    ProBoolean          state);

/*
    Purpose: Get the "mixed" state of the item in the tree. 
             This flag indicating whether the component has no selection
             at this time and is therefore in an indeterminate "mixed" state.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        item - The name of the item in the tree.
        state - Mixed State of the item. PRO_B_TRUE if the item has mixed state.
                PRO_B_FALSE if the item has no mixed state. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeMixedStateGet (
    char               *dialog,
    char               *component,
    char               *item,
    ProBoolean         *state);

/*
    Purpose: Get the "mixed" state of the item in the tree. 
             This flag indicating whether the component has no selection
             at this time and is therefore in an indeterminate "mixed" state.
             
    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.
        item - The name of the item in the tree.

    Output Arguments:
        state - Mixed State of the item. PRO_B_TRUE if the item has mixed state.
                PRO_B_FALSE if the item has no mixed state. 
                This argument is not allowed to be NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUITreeLastentereditemGet (
    char                   *dialog,
    char                   *component,
    char                  **value);

/*
    Purpose: Gets the name of the tree item last pointed to by the mouse
             cursor.  This value is important when interpreting a
             TriggerHighlight event.

    Input Arguments:
        dialog - The name of the dialog that contains the tree.
        component - The name of the tree component.

    Output Arguments:
        value - The name of the tree item last pointed to by the
                cursor.  Free this string using ProStringFree.
                This argument is not allowed to be NULL.
                            
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


PRO_END_C_DECLS

#endif
