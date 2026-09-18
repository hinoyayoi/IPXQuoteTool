#ifndef PROCLCMDELEM_H
#define PROCLCMDELEM_H


#include <ProObjects.h>
#include <ProElement.h>



PRO_BEGIN_C_DECLS

extern ProError ProClcmdElemSet (ProElement ncl_commd_elem,
                          wchar_t **commd_lines,
                          int num_lines,
                          ProVector commd_loc,
                          ProVector commd_axis);
/*

  Purpose: Fills the specified CL command element with user data.
 
  Input Arguments:

    ncl_commd_elem - The CL command element
    commd_lines    - The array of command lines
    num_lines      - The number of command lines in the <i>commd_lines</i>
		     array
    commd_loc      - The XYZ coordinates of the CL command in the NC sequence 
		     coordinate system
    commd_axis     - The tool axis in the location 

  Output Arguments:
    
    None

  Return Values:

    PRO_TK_NO_ERROR   - The function successfully set the information 
                        for the element.
    PRO_TK_BAD_INPUTS - One or more of the arguments are invalid. 
*/
 
 
extern ProError ProClcmdElemCreate ( wchar_t    **commd_lines,
                                     int          num_lines,
                                     ProVector    commd_loc,
                                     ProVector    commd_axis,
			             ProElement  *r_ncl_cmd_elem);

/*

  Purpose: Allocates and sets up a CL command element.

  Input Arguments:

    commd_lines - The array of command lines
    num_lines   - The number command lines in the <i>commd_lines</i>
		  array
    commd_loc   - The XYZ coordinates of the CL command in the NC 
		  sequence coordinate system
    commd_axis  - The tool axis in the location


  Output Arguments:

    r_ncl_cmd_elem - The pointer to the CL command element 


  Return Values:

  PRO_TK_NO_ERROR   - The function successfully allocated the CL command 
		      element.
  PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern int ProClcmdElemNumberGet (ProElement feat_elem_tree, 
				  int *r_number);

/* 
  Purpose: Gets the number of CL command elements in the specified feature.

  Input Arguments:

  feat_elem_tree - The element tree of the customized (build path) feature


  Output Arguments:

  r_number - The number of CL command elements in the feature 


  Return Values:

  PRO_TK_NO_ERROR   - The function successfully retrieved the information.
  PRO_TK_BAD_INPUTS - The input argument is invalid.

*/


extern ProError ProClcmdElemAdd (ProElement feat_elem_tree,
                                 ProElement ncl_cmd_elem,
                                 int        index);

/* 

   Purpose: Adds the specified CL command element to the
	   feature element tree.
 
   Input Arguments:

     feat_elem_tree - The element tree of the customized (build path) feature.
     ncl_cmd_elem   - The CL command element to add.
     index          - The index in the CL command array at which to insert
	  	      the new element. Set this to -1 to add the element to
		      the end of the tree.


   Output Arguments:

      None


   Return Values:

     PRO_TK_NO_ERROR  - The function successfully added the element to
			the tree.
     Other            - The function failed.
*/
 
extern ProError ProClcmdElemGetByIndex (ProElement  feat_elem_tree,
                                        int         index,
                                        ProElement *r_ncl_cmd_elem);

/* 

  Purpose: Gets the pointer to the CL command element, given the index.

  Input Arguments:
    feat_elem_tree - The element tree of the customized (build path) feature
    index          - The index of the element in the CL command array
    r_ncl_cmd_elem - The CL command element
 

  Output Arguments:

    None


  Return Values:

    PRO_TK_NO_ERROR  - The function successfully retrieved the information.
    Other            - The function failed.
*/
 
 
extern ProError ProClcmdElemRemoveByIndex (ProElement  feat_elem_tree,
                                           int         index,
                                           ProElement *r_elem);

/* 

  Purpose: Removes the specified CL command element from the feature 
	   element tree.
 

  Input Arguments:

    feat_elem_tree - The element tree of the customized (build path) feature
    index          - The index of the element in the CL command array


  Output Arguments:

    r_elem         - The element removed. May be NULL


  Return Values:

     PRO_TK_NO_ERROR  - The function successfully removed the element from
			the element tree.
     Other            - The function did not remove the element from the
			element tree.
*/
 
 
 
extern ProError ProClcmdElemGet (ProElement   feat_elem_tree,
                                 wchar_t    **commd_lines,
                                 int          num_lines,
                                 ProVector    commd_loc,
                                 ProVector    commd_axis,
                                 ProElement  *r_ncl_cmd_elem);

/* 

  Purpose: Gets the pointer to the specified CL command element.

  Input Arguments:

   feat_elem_tree - The element tree of the customized (build path) feature
   commd_lines    - The array of command lines
   num_lines      - The number of command lines in the <i>commd_lines</i>
		    array
   commd_loc      - The XYZ coordinates of the CL command in the NC 
		    sequence coordinate system
   commd_axis     - The tool axis in the location


  Output Arguments:

   r_ncl_cmd_elem - The pointer to the element


  Return Values:

    PRO_TK_NO_ERROR  - The function successfully retrieved the information.
    Other            - The function failed.
*/
 
extern ProError ProClcmdElemRemove (ProElement  feat_elem_tree,
                                    wchar_t   **commd_lines,
                                    int         num_lines,
                                    ProVector   commd_loc,
                                    ProVector   commd_axis,
                                    ProElement *r_ncl_cmd_elem);

/*

 
  Purpose: Removes the specified CL command element, given its data.

  Input Arguments:

    feat_elem_tree - The element tree of the customized (build path) feature
    commd_lines    - The array of command lines
    num_lines      - The number of command lines in the <i>commd_lines</i>
		     array
    commd_loc      - The XYZ coordinates of the CL command in the NC 
		     sequence coordinate system
    commd_axis     - The tool axis in the location
    r_ncl_cmd_elem - The element to remove

  Output Arguments:

    None

  Return Values:

    PRO_TK_NO_ERROR  - The function successfully removed the element.
    Other            - The function failed.
*/

PRO_END_C_DECLS

#endif
