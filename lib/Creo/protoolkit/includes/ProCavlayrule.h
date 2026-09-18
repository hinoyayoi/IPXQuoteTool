#ifndef PRO_MLDLAY_RULE_H
#define PRO_MLDLAY_RULE_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProGeomitem.h>



typedef void   *ProCvLayoutRule; /* wrapper for Mopr_layout_info - 
                                    this comment will be removed */

typedef enum
{
   PRO_CVLAYOUT_SINGLE,
   PRO_CVLAYOUT_RECTANG,
   PRO_CVLAYOUT_CIRCULAR,
   PRO_CVLAYOUT_VARIABLE
} ProCvLayoutType;

typedef enum
{
   PRO_CVLAYOUT_CONSTANT,
   PRO_CVLAYOUT_XSYMMETRIC,
   PRO_CVLAYOUT_YSYMMETRIC,
   PRO_CVLAYOUT_RADIAL
} ProCvLayoutOrient;

PRO_BEGIN_C_DECLS

/* Functions to initiate and manipulate data to the ProCvLayoutRule handle */


extern ProError ProCavlayruleAlloc (ProCvLayoutRule *cvlrule);
/*
   Purpose:    Allocates the handle of a new cavity layout rule structure
               and set it to the PRO_CVLAYOUT_SINGLE type.

   Input Arguments:
      none

   Output Arguments:
      cvlrule                - Pointer to the cavity layout rule handle 
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully allocated.
        PRO_TK_GENERAL_ERROR - Cannot allocate the handle
 
*/


extern ProError ProCavlayruleFree (ProCvLayoutRule cvlrule);
/*
   Purpose:    Free the memory and handle of a cavity layout rule structure.

   Input Arguments:
           cvlrule                - Pointer to the cavity layout rule handle

   Output Arguments:
           none
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully freed.
        PRO_TK_GENERAL_ERROR - Cannot free the handle
 
*/

extern ProError ProCavlayruleFileWrite (ProCvLayoutRule cvlrule,
                                        ProPath file_name);
/*
   Purpose:    Save the cavity layout rule to file. This file can be read both
               from UI and Toolkit to set the rule.

   Input Arguments:
           cvlrule                - Pointer to the cavity layout rule handle;
 
           file_name              - name of the file to save.

   Output Arguments:
           none

   Return Values:
        PRO_TK_NO_ERROR      - The rule is successfully saved.
        PRO_TK_GENERAL_ERROR - Cannot save the rule.
 
*/
 
extern ProError ProCavlayruleFileRead (ProCvLayoutRule cvlrule,
                                       ProPath file_name);
/*
   Purpose:    Get the cavity layout rule from the previously saved file.

   Input Arguments:
           cvlrule                - Pointer to the initiated cavity layout rule
                                    handle;
 
           file_name              - name of the file to save.

   Output Arguments:
           none
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully retrieved
        PRO_TK_GENERAL_ERROR - Cannot retrieve the handle
 
*/

 
extern ProError ProCavlayruleSingleSet (ProCvLayoutRule cvlrule);
/*
   Purpose:    Reset the information in a cavity layout rule structure
               to the PRO_CVLAYOUT_SINGLE type.

   Input Arguments:
      cvlrule                - Cavity layout rule handle.

   Output Arguments:
           none
 
   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully reset,
        PRO_TK_GENERAL_ERROR - Cannot inialize the handle
 
*/



extern ProError ProCavlayruleRectSet (ProCvLayoutRule cvlrule,
                                      ProCvLayoutOrient orient,
                                      int cavity_num_x, int cavity_num_y,
                                      double cavity_step_x,
                                      double cavity_step_y);



/*
   Purpose:    Reset the information in a cavity layout rule structure
               to the PRO_CVLAYOUT_RECTANG type.
 
   Input Arguments:
      cvlrule                - Cavity layout rule handle;
 
      orient                 - Layout orientation type;

      cavity_num_x           - Number of columns in the layout;

      cavity_num_y           - Number of rows in the layout;
 
      cavity_step_x          - Displacement step in x direction;

      cavity_step_y          - Displacement step in y direction.

   Output Arguments:
           none


   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully reset.
        PRO_TK_GENERAL_ERROR - Cannot inialize the handle
 
*/
 
extern ProError ProCavlayruleCircSet (ProCvLayoutRule cvlrule,
                                      ProCvLayoutOrient orient,
                                      int cavity_num,
                                      double cavity_step,
                                      double start_angle,
                                      double radius);
                                             
/*
   Purpose:    Reset the information in a cavity layout rule structure
               to the PRO_CVLAYOUT_CIRCULAR type.
 
   Input Arguments:
      cvlrule                - Cavity layout rule handle;
 
      orient                 - Layout orientation type;

      cavity_num             - number of components in the layout;

      cavity_step            - angular displacement;

      start_angle            - angle for the first component;

      radius                 - raduis of the layout;

   Output Arguments:
           none

   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully reset.
        PRO_TK_GENERAL_ERROR - Cannot inialize the handle
*/

extern ProError ProCavlayruleVarSet  (ProCvLayoutRule cvlrule,
                                      int cavity_num,
                                      double *increment1_arr,
                                      double *increment2_arr,
                                      double *increment3_arr);

/*
   Purpose:    Reset the information in a cavity layout rule structure
               to the PRO_CVLAYOUT_VARIABLE type. The function will use 
               the previously set simple type (sinle, rectangular or circular)
               as a base for variable type.
 
   Input Arguments:
      cvlrule                - Cavity layout rule handle;
 
      cavity_num             - Number of rows in Variable Layout Table;

      increment1_arr         - <i>ProArray</i> of increments for the first 
                               table dimension;
 
      increment2_arr         - <i>ProArray</i> of increments for the second
                               table dimension;
 
      increment3_arr         - <i>ProArray</i> of increments for the third 
                               table dimension;

   Output Arguments:
           none

   Return Values:
        PRO_TK_NO_ERROR      - The handle is successfully reset.
        PRO_TK_GENERAL_ERROR - Cannot inialize the handle
 
*/
 


extern ProError ProCavlayruleTypeGet (ProCvLayoutRule cvlrule,
                                      ProCvLayoutType *type, 
                                      ProCvLayoutType *basic_type);
/*
   Purpose:    Get the information about a cavity layout type from the 
               Cavity Layout Rule structure.

   Input Arguments:
      cvlrule                - Cavity layout rule handle.
 
   Output Arguments:
      type                   - pointer to actual rule type;

      basic_type             - pointer to basic rule type if actual rule type 
                
                               type as in first_type.

   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully retrieved;
        PRO_TK_GENERAL_ERROR - Cannot inialize the pointers.
 
*/
 
 
extern ProError ProCavlayruleRectDataGet (ProCvLayoutRule cvlrule,
                                          ProCvLayoutOrient *orient,
                                          int *cavity_num_x, 
                                          int *cavity_num_y,
                                          double *cavity_step_x,
                                          double *cavity_step_y);
/*
   Purpose:    Get the information about a rectangular rule from the
               Cavity Layout Rule structure.
 
   Input Arguments:
      cvlrule                - Cavity layout rule handle. It should be of 
                               rectangular or Variable built over rectangular 
                               type. A good programming style is to call first
                               function ProCavlayruleRuleTypeGet() and make 
                               sure that one of the types it returns is
                               Rectangular.

   Output Arguments:
      orient                 - pointer to layout orientation type;

      cavity_num_x           - pointer to number of columns in the layout;

      cavity_num_y           - pointer to number of rows in the layout;
 
      cavity_step_x          - pointer to displacement step in x direction;

      cavity_step_y          - pointer to displacement step in y direction.

 
                                               
   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully retrieved;
        PRO_TK_BAD_INPUTS    - The Rule is of uncompatible type.
        PRO_TK_GENERAL_ERROR - Cannot inialize the pointers.
 
*/
 
 
extern ProError ProCavlayruleCircDataGet (ProCvLayoutRule cvlrule,
                                          ProCvLayoutOrient *orient,
                                          int *cavity_num,
                                          double *cavity_step,
                                          double *start_angle,
                                          double *radius);
/*
   Purpose:    Get the information about a circular rule from the
               Cavity Layout Rule structure.
 
   Input Arguments:
      cvlrule                - Cavity layout rule handle. It should be of 
                               circular or Variable built over circular 
                               type. A good programming style is to call first
                               function ProCavlayruleRuleTypeGet() and make 
                               sure that one of the types it returns is 
                               Circular.

   Output Arguments:
      orient                 - pointer to layout orientation type;

      cavity_num             - pointer to number of components in the layout;

      cavity_step            - pointer to angular displacement;

      start_angle            - pointer to angle for the first component;

      radius                 - pointer to the radius of the rule.

   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully retrieved;
        PRO_TK_BAD_INPUTS    - The Rule is of uncompatible type.
        PRO_TK_GENERAL_ERROR - Cannot inialize the pointers.
*/ 
 


extern ProError ProCavlayruleVarDataGet (ProCvLayoutRule cvlrule,
                                         int    *cavity_num,
                                         double **increment1_arr,
                                         double **increment2_arr,
                                         double **increment3_arr);
/*
   Purpose:    Get the information about a variable rule from the
               Cavity Layout Rule structure. A good programming style is to 
               call first ProCavlayruleRuleTypeGet() make sure that
               the type it returns is variable.
 
   Input Arguments:
      cvlrule                - Cavity layout rule handle;

   Output Arguments:
      cavity_num             - pointer to number of rows in 
                               Variable Layout Table;

      increment1_arr         - pointer to <i>ProArray</i> of increments 
                               for the first table dimension; 
 
      increment2_arr         - pointer to <i>ProArray</i> of increments 
                               for the second table dimension;
 
      increment3_arr         - pointer to <i>ProArray</i> of increments
                               for the third table dimension;


   Return Values:
        PRO_TK_NO_ERROR      - The information is successfully retrieved;
        PRO_TK_BAD_INPUTS    - The Rule is of uncompatible type.
        PRO_TK_GENERAL_ERROR - Cannot inialize the pointers.
*/

PRO_END_C_DECLS

#endif
