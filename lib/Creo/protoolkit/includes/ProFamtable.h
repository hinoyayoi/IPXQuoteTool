#ifndef PROFAMTABLE_H
#define PROFAMTABLE_H

/* Creo Parametric TOOLKIT declarations of ProFamtable related data structures */

#include <ProObjects.h>





PRO_BEGIN_C_DECLS



typedef enum pro_famtab_types
{
  PRO_FAM_TYPE_UNUSED         =    PRO_VALUE_UNUSED,
  PRO_FAM_USER_PARAM          =    1 , 
  PRO_FAM_DIMENSION           =    2 , 
  PRO_FAM_IPAR_NOTE           =    3 , 
  PRO_FAM_FEATURE             =    4 , 
  PRO_FAM_ASMCOMP             =    5 , 
  PRO_FAM_UDF                 =    6 , 
  PRO_FAM_ASMCOMP_MODEL       =    8 ,
  PRO_FAM_GTOL                =    9 ,
  PRO_FAM_TOL_PLUS            =    10,
  PRO_FAM_TOL_MINUS           =    11,
  PRO_FAM_TOL_PLUSMINUS       =    12,
  PRO_FAM_SYSTEM_PARAM        =    13,
  PRO_FAM_EXTERNAL_REFERENCE  =    14,
  PRO_FAM_MERGE_PART_REF      =    19,
  PRO_FAM_MP_USER_PARAM       =    20,
  PRO_FAM_MP_SOURCE           =    22,
  PRO_FAM_INH_PART_REF        =    23,
  PRO_FAM_SIM_OBJ             =    24,
  PRO_FAM_FEATURE_PARAM       =    25,
  PRO_FAM_EDGE_PARAM          =    26,
  PRO_FAM_SURFACE_PARAM       =    27,
  PRO_FAM_CURVE_PARAM         =    28,
  PRO_FAM_COMP_CURVE_PARAM    =    29,
  PRO_FAM_QUILT_PARAM         =    30,
  PRO_FAM_ANNOT_ELEM_PARAM    =    31,
  PRO_FAM_CONNECTION_PARAM    =    32
} ProFamtabType;



typedef struct pro_model_item ProFamtable;

           
typedef struct profamtabitem
{
  ProFamtabType type;
  ProFamtabClmDesc string; 
  ProMdl        owner;
} ProFamtableItem;
  
/* The field "string" above should contain a family table column name 
   for this item (e.g., F27, M5, PARM, $d2). This name must be consistent 
   with the type field. To construct it automatically for some types 
   ProModelitemToFamtableItem() and ProParameterToFamtableItem() can be used;   
   in case when type is PRO_FAM_EXTERNAL_REFERENCE the "string" field
   should contain a reference assembly name */ 

typedef struct profamtabitem *ProFamtableitemList;



/* Data definitions */

/* Visit function prototype */

typedef ProError (*ProFamtableItemAction) 
                                   (ProFamtableItem   *famtable_item,
                                    ProError           status,
                                    ProAppData         app_data
                                   );

/*
   Purpose:  This is the generic function for visiting family tables.

   Input Arguments:
      famtable_item  - The family table item
      status         - The status from <i>filter_action</i>
      app_data       - The application data passed to 
                       <b>ProFamtableItemVisit()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR -  Continue visiting table table items.
      Other ProError  -  Stop visiting -- <b>ProFamtableItemVisit()</b> returns
                         with the status.
*/


/* Filter function prototype */

typedef ProError (*ProFamtableItemFilter) 
                                   (ProFamtableItem   *famtable_item,
                                    ProAppData         app_data
                                   );
/*
   Purpose:  This is the generic function for filtering family table items.

   Input Arguments:
      famtable_item  - The family table item
      app_data       - The application data passed to 
                       <b>ProFamtableItemVisit()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR -  Continue visiting table table items.
      PRO_TK_CONTINUE -  Skip to the next item.
      Other values    -  The status is passed to the visit function.
*/

/* Generic functions */


extern ProError ProFamtableInit  (ProMdl      model,
                                  ProFamtable  *p_famtab);

/*
   Purpose:     Initializes the family table of the specified model.

   Input Arguments:
      model              -  The model handle.

   Output Arguments:
      p_famtab           -  The handle to the family table.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully initialized
                            the handle.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
      PRO_TK_UNSUPPORTED  - Family table can't be created in the model.
*/



extern ProError ProFamtableCheck (ProFamtable  *p_famtab);

/* 
   Purpose: Determines whether the family table is valid and/or empty, given
            its handle.     

   Input Arguments:
      p_famtab           -  The handle to the family table 

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR         - The family table is found and is not empty.
      PRO_TK_BAD_INPUTS       - The input argument is invalid (for example,
                                the owner was not found).
      PRO_TK_E_NOT_FOUND      - The family table was not found for the 
                                specified owner.
      PRO_TK_EMPTY            - The family table is found and is empty.
*/

extern ProError ProFamtableErase (ProFamtable  *p_famtab);

/* 
   Purpose:     Clears the specified family table. 

   Input Arguments:
      p_famtab           -  The handle to the family table. If the function
                            is successful, the new values for the fields
                            are as follows:
                            <ul>
                            <li>type -- PRO_TYPE_UNUSED
                            <li>id -- PRO_VALUE_UNUSED
                            <li>owner -- NULL
                            </ul> 

   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR         - The function successfully cleared 
                                the family table.
      PRO_TK_E_NOT_FOUND      - The family table was not found.
      PRO_TK_GENERAL_ERROR    - There was a general error (for example,
                                the owner was not found).
*/


extern ProError ProFamtableShow (ProFamtable  *p_famtab);

/* 
   Purpose:     Displays the specified family table using Pro/TABLE
                or another text editor.

   Input Arguments:
      p_famtab           -  The handle to the family table 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully displayed
                                the family table. 
      PRO_TK_GENERAL_ERROR    - The family table was not found.
                                 
*/


extern ProError ProFamtableEdit (ProFamtable  *p_famtab);

/* 
   Purpose:     Edits the specified family table using Pro/TABLE 
                or another text editor.

   Input Arguments:
      p_famtab           -  The handle to the family table

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR         - The function successfully edited the 
                                family table.
      PRO_TK_GENERAL_ERROR    - There was a general error (for example,
                                the owner was not found).
                                  
*/

/* Generic functions to deal with family table items */


extern ProError ProFamtableItemAdd (ProFamtable    *p_famtab,
                                    ProFamtableItem *item);
/*
   Purpose:     Adds the specified item to the family table of the
                model.

   Input Arguments:
      p_famtab           -  The handle to the family table
      item           	 -  The item to add to the table

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      -  The function successfully added the item
                              to the family table.
      PRO_TK_NO_CHANGE     -  The specified item already exists in the
                              family table.
      PRO_TK_GENERAL_ERROR -  There was a general error (for
                              example, the owner of the item is not in 
                              session, or the family table was not 
                              found).
*/


extern ProError ProFamtableItemRemove (ProFamtable    *p_famtab,
                                       ProFamtableItem *item);
/*
   Purpose:     Deletes the specified item from the family table.
   
   Input Arguments:
      p_famtab           -  The handle to the family table
      item           	 -  The item to remove

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      -  The function successfully deleted the
                              item from the family table.
      PRO_TK_E_NOT_FOUND   -  The specified item was not found
                              in the family table.
      PRO_TK_GENERAL_ERROR -  There was a general error (for example,
                              the model is not in session). 
*/


extern ProError ProFamtableItemVisit (
                               ProFamtable           *p_famtab,
			       ProFamtableItemAction  visit_action,
			       ProFamtableItemFilter  filter_action,
			       ProAppData             app_data);
/*
    Purpose:   Visits all the items in a family table.

    Input Arguments:
	p_famtab 	- The handle to the family table.
	visit_action 	- The action to perform on each item. If it
                          returns anything other than PRO_TK_NO_ERROR,
                          visiting stops. 
	filter_action 	- The filter function. If NULL, all items are 
                          visited using the action function.
	app_data 	- The application data passed to the
			  visiting and filter functions.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR - The function successfully visited all 
                          the items.
	PRO_TK_BAD_INPUTS - One or more inputs was invalid.
        Other -           Any other value is the value returned by the 
                          action function (visiting stopped).

*/


extern ProError ProModelitemToFamtableItem (
                              ProModelitem     *p_item,
                              ProFamtableItem  *r_fam_item);
/*
   Purpose:  Converts a <i>ProModelitem</i> to a <i>ProFamtableItem</i>.

   <P>Types supported for conversion here:

   <table>
     <tr><td><b>ProType</b></td><td><b>ProFamtabType</b></td></tr>
     <tr><td>PRO_FEATURE</td><td>PRO_FAM_FEATURE</td></tr>
      <tr><td>PRO_DIMENSION</td><td>PRO_FAM_DIMENSION</td></tr>
      <tr><td>PRO_IPAR_NOTE</td><td>PRO_FAM_IPAR_NOTE</td></tr>
      <tr><td>PRO_UDF</td><td>PRO_FAM_UDF</td></tr>
      <tr><td>PRO_SUB_ASSEMBLY</td><td>PRO_FAM_ASMCOMP</td></tr>
      <tr><td>PRO_GTOL</td><td>PRO_FAM_GTOL</td></tr>
   </table>

   Input Arguments:
      p_item          - The model item

   Output Arguments:
      r_fam_item      - The family table item

   Return Values:
      PRO_TK_NO_ERROR - The family table item handler is successfully 
                        initiated.
      Other           - The conversion failed.

 
*/


extern ProError ProFamtableItemToModelitem (
                              ProFamtableItem  *p_fam_item,
                              ProModelitem     *r_item);

/*
   Purpose:  Converts a <i>ProFamtableItem</i> to a <i>ProModelitem</i>.

   <P>Types supported for conversion here:

   <table>
     <tr><td><b>ProType</b></td><td><b>ProFamtabType</b></td></tr>
     <tr><td>PRO_FEATURE</td><td>PRO_FAM_FEATURE</td></tr>
      <tr><td>PRO_DIMENSION</td><td>PRO_FAM_DIMENSION</td></tr>
      <tr><td>PRO_IPAR_NOTE</td><td>PRO_FAM_IPAR_NOTE</td></tr>
      <tr><td>PRO_UDF</td><td>PRO_FAM_UDF</td></tr>
      <tr><td>PRO_SUB_ASSEMBLY</td><td>PRO_FAM_ASMCOMP</td></tr>
      <tr><td>PRO_GTOL</td><td>PRO_FAM_GTOL</td></tr>
   </table>

   Input Arguments:
      p_fam_item      - The family table item

   Output Arguments:
      r_item          - The model item

   Return Values:
      PRO_TK_NO_ERROR - The model item is successfully initiated.
      Other           - The conversion failed.
*/


extern ProError ProFamtableItemToParameter (
                             ProFamtableItem    *p_item,
                             ProParameter       *r_parameter); 
/*
   Purpose:  Converts a <i>ProFamtableItem</i> to a <i>ProParameter</i>.

   <P>Types supported for conversion here:

   <ul>
     <li>PRO_FAM_USER_PARAM
     <li>PRO_FAM_SYSTEM_PARAM
     <li>PRO_FAM_MP_USER_PARAM
     <li>PRO_FAM_MP_SOURCE
     <li>PRO_FAM_FEATURE_PARAM
     <li>PRO_FAM_EDGE_PARAM
     <li>PRO_FAM_SURFACE_PARAM
     <li>PRO_FAM_CURVE_PARAM
     <li>PRO_FAM_COMP_CURVE_PARAM
     <li>PRO_FAM_QUILT_PARAM
     <li>PRO_FAM_ANNOT_ELEM_PARAM
     <li>PRO_FAM_CONNECTION_PARAM
   </ul>

   Input Arguments:
      p_item          - The family table item

   Output Arguments:
      r_parameter     - The parameter

   Return Values:
      PRO_TK_NO_ERROR - The function successfully converted the family 
                        table item.
      Other           - The conversion failed.
*/


extern ProError ProParameterToFamtableItem (
                             ProParameter       *p_parameter,
                             ProFamtableItem    *r_item);
/*
   Purpose:  Converts a <i>ProParameter</i> to a <i>ProFamtableItem</i>. 

  <P>Types supported for conversion here:

   <ul>
     <li>PRO_FAM_USER_PARAM
     <li>PRO_FAM_SYSTEM_PARAM
     <li>PRO_FAM_MP_USER_PARAM
     <li>PRO_FAM_MP_SOURCE
     <li>PRO_FAM_FEATURE_PARAM
     <li>PRO_FAM_EDGE_PARAM
     <li>PRO_FAM_SURFACE_PARAM
     <li>PRO_FAM_CURVE_PARAM
     <li>PRO_FAM_COMP_CURVE_PARAM
     <li>PRO_FAM_QUILT_PARAM
     <li>PRO_FAM_ANNOT_ELEM_PARAM
     <li>PRO_FAM_CONNECTION_PARAM
   </ul>
            
   Input Arguments:
      p_parameter     - The parameter

   Output Arguments:
      r_item          - The family table item

   Return Values:
      PRO_TK_NO_ERROR - The function successfully converted the parameter.
      Other           - The conversion failed.
*/


extern ProError ProFamtableIsModifiable (ProFamtable* p_famtab,
                                         ProBoolean show_ui,
                                         ProBoolean* can_modify);
/*
   Purpose: Check if a given Family table is modifiable.

   Input Arguments:
     p_famtab     - Family table to check access to.
     show_ui      - Indicates whether the Conflicts dialog should be shown to
                    user to resolve conflicts (if they are detected); when set
                    to PRO_B_FALSE no UI is enabled and the Family table is
                    considered as modifiable if there are no conflicts that
                    could not be overridden or resolved by default resolution
                    actions.

   Output Arguments:
      can_modify -  The access status. If it is PRO_B_TRUE, the family table is
                    modifiable.
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retieved the information.
      PRO_TK_BAD_INPUTS  - One or more arguments are invalid.
      PRO_TK_GENERAL_ERROR - The function could not check access to the
                             Family table.
*/

PRO_END_C_DECLS

#endif  /* PROFAMTABLE_H */

