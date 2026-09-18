#ifndef PROSELBUFFER_H 
#define PROSELBUFFER_H

#include <ProSelection.h>



PRO_BEGIN_C_DECLS

extern  ProError ProSelbufferSelectionsGet (ProSelection **ret_buff);                                
/*
   Purpose:  Get contents of the active selection buffer

   Input Arguments:
      none
   
   Output Arguments:
      ret_buff - ProArray of ProSelection.  Free this array using
                                               ProSelectionarrayFree.
      
   Return Values: 
    PRO_TK_NO_ERROR - buffer is in session and was returned.
    PRO_TK_BAD_INPUTS - The argument was invalid (NULL).
    PRO_TK_CANT_ACCESS - There is no Object/Action selection tool active.  
    PRO_TK_E_NOT_FOUND - There are no objects in the current selection tool.   
*/

 
extern  ProError ProSelbufferClear ( void );
/*
   Purpose:  Clear the currently active selection buffer of all contents. 

   Input Arguments:
      None
      
   Output Arguments:
      None
      
   Return Values:
  PRO_TK_NO_ERROR - The buffer was successfully cleared.
  PRO_TK_CANT_ACCESS - There is no Object/Action selection tool active.
  PRO_TK_CANT_MODIFY - Buffer modification is prohibited.        
*/ 

extern  ProError ProSelbufferSelectionRemove (int index);
/*
   Purpose:  Removes the selection at the indicated location from the 
             selection tool buffer.

   Input Arguments:
      index       - Index of the item to remove from the currently active 
                    selection tool.  This index would be obtained from the 
                    index that the item resides in after a call to 
                    ProSelbufferSelectionsGet().
            
   Output Arguments:
      None

   Return Values:
  PRO_TK_NO_ERROR - The function succeeded.
  PRO_TK_BAD_INPUTS - The index input was invalid.
  PRO_TK_CANT_ACCESS - There is no Object/Action selection tool active. 
  PRO_TK_CANT_MODIFY - Buffer modification is prohibited.
                               

*/

extern  ProError  ProSelbufferSelectionAdd (ProSelection object);
/*
   Purpose:  Programmatically add an item to the buffer of the currently 
             active selection tool.

   Input Arguments:
      object - The object to add to the buffer.  This selection must 
               reference an item that could have been selected in the 
	       current model (its owner, component path, and/or drawing view 
	       values must be properly constructed).
      
   Output Arguments:
      None
      
   Return Values:
  	PRO_TK_NO_ERROR - The function succeeded.
      	PRO_TK_BAD_INPUTS - The input argument was invalid.
	PRO_TK_CANT_ACCESS - There is no Object/Action selection tool active.
    	PRO_TK_INVALID_ITEM - The selection does not correctly reference the 
                              current model.
	PRO_TK_NOT_DISPLAYED - The item is not currently displayed and so 
                               cannot be added to the buffer.
	PRO_TK_BAD_CONTEXT - The selection cannot be added to the buffer in 
	                     combination with one or more objects that are 
			     already in the buffer (e.g. geometry and 
			     features selected at the same time).
	PRO_TK_GENERAL_ERROR - The function failed to add the requested item 
	                       to the buffer.
        PRO_TK_CANT_MODIFY - Buffer modification is prohibited.		
*/



extern  ProError  ProSelbufferCollectionAdd( ProCollection collection );
/*
    Purpose: Add a collection (chain or surface collection) to the 
	     current active selection buffer.

    Input Arguments:
	  collection - The collection object
	
    Output Arguments:
none

    Return Values:
	PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed to add the requested item 
                               to the buffer.

See Also:
		ProSelectionCollectionGet()
*/

PRO_END_C_DECLS
#endif /* PROSELBUFFER_H */




