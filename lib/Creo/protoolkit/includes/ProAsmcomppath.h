

#ifndef PROASMCOMPPATH_H
#define PROASMCOMPPATH_H

#include <ProObjects.h>


PRO_BEGIN_C_DECLS

extern ProError ProAsmcomppathInit (ProSolid       p_solid_handle,
                                    ProIdTable     memb_id_tab,
                                    int            table_size,
                                    ProAsmcomppath *p_handle);

/*
   Purpose:     Initializes the <i>ProAsmcompath</i> data structure.

   Input Arguments:
      p_solid_handle    - The top-level assembly
      memb_id_tab       - The member identifier table
      table_size        - The table size

   Output Arguments:
      p_handle          - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data
                          structure.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProAsmcomppathTrfGet (ProAsmcomppath *p_path,
                                      ProBoolean   bottom_up,
                                      ProMatrix    transformation);
/*
   Purpose:    Retrieves the transformation matrix, given the component path.

   Input Arguments:
      p_path       - The component path.
      bottom_up    - If you request the transformation from the member to the
                     assembly, this is PRO_B_TRUE. Otherwise, this is
                     PRO_B_FALSE.

   Output Arguments:
      transformation    - The transformation matrix.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_GENERAL_ERROR - The specified component path was wrong, or
                             contained missing members.
*/

extern ProError ProAsmcomppathTrfSet (ProAsmcomppath *p_path,
                                      ProBoolean   bottom_up,
                                      ProMatrix    transformation);
/*
   Purpose:    Assigns the transformation matrix, given the component path.
               The assignment is run-time only, and takes affect only when
               <b>ProAssemblyDynPosSet()</b> is PRO_B_TRUE.

   Input Arguments:
      p_path         - The component path.
      bottom_up      - If you request the transformation from the member to the
                       assembly, this is PRO_B_TRUE. Otherwise, this is
                       PRO_B_FALSE.
      transformation - The transformation matrix to assign.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully set the
                             information.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - The specified component path was wrong, or
                             contained missing members.

   See Also:

      ProAssemblyDynPosSet()
*/

extern ProError ProAsmcomppathMdlGet (ProAsmcomppath *p_path,
                                      ProMdl         *p_model);
/*
   Purpose:    Retrieves the model specified by the component path.

   Input Arguments:
      p_path       - The component path

   Output Arguments:
      p_model      - The model found at the end of the component path

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS    - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - The specified component path was wrong, or
                             contained missing members.
*/

extern ProError ProVectorTrfEval  (ProVector   in_vector,
                                   ProMatrix   trf,
                                   ProVector   out_vector);

/*
   Purpose:   Transforms the <I>in_vector</I> to the <I>out_vector</I> by the
              specified transformation matrix (rotation only).

   Input Arguments:
      in_vector   - The vector to transform.
      trf         - The transformation matrix.

   Output Arguments:
      out_vector  - The result. This can be the same as <I>in_vector</I>.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully transformed the
                             <I>in_vector</I>.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid
                             (NULL).
*/

extern ProError ProPntTrfEval  (ProVector   in_point,
                                ProMatrix   trf,
                                ProVector   out_point);

/*
   Purpose:   Transforms the <I>in_point</I> to the <I>out_point</I> by the 
              specified transformation matrix (both shift and rotation).

   Input Arguments:
      in_point   - The vector to transform.
      trf        - The transformation matrix.

   Output Arguments:
      out_point  - The result. This can be the same as <I>in_point</I>.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully transformed the 
                             <I>in_point</I>.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid
                             (NULL).
*/

extern ProError ProMatrixInit ( ProVector x_vector,
                                ProVector y_vector,
                                ProVector z_vector,
                                ProPoint3d origin,
                                ProMatrix  matrix );
/*
   Purpose:   Constructs the transformation matrix from the specified three 
              vectors and the origin.

   Input Arguments:
      x_vector - The X-axis vector, defined as (X, Y, Z)
      y_vector - The Y-axis vector, defined as (X, Y, Z)
      z_vector - The Z-axis vector, defined as (X, Y, Z)
      origin   - The origin point, defined as (X, Y, Z)

   Output Arguments:
      matrix   - The transformation matrix

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully constructed the matrix. 
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProAsmcomppathDispPointVisit (ProAsmcomppath       *p_path,
                                              ProSolid              handle,
                                            ProPointFilterAction  filter_action,
                                             ProPointVisitAction   visit_action,
                                              ProAppData            app_data);

/*
   Purpose:     Visits all the displayed datum points in the solid handle. 

   Input Arguments:
      p_path            - The solid handle's assembly component path.
      handle            - The solid handle. Passed in for performance reasons.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL,
                          visits all items using the action function. 
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the items.
      PRO_TK_E_NOT_FOUND - Either no displayed datum points exist, or they
                           were all filtered out by the filter function.
      Other              - Any other value is the value returned by the action
			   function (visiting stopped).
*/

extern ProError ProAsmcomppathDispCurveVisit (ProAsmcomppath       *p_path,
                                              ProSolid              handle,
                                            ProCurveFilterAction  filter_action,
                                             ProCurveVisitAction   visit_action,
                                              ProAppData            app_data);
/*
   Purpose:     Visits all the displayed datum curves in the solid handle. 

   Input Arguments:
      p_path            - The solid handle's assembly component path.
      handle            - The solid handle. Passed in for performance reasons.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL,
                          visits all items using the action function.
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the items.
      PRO_TK_E_NOT_FOUND - Either no displayed datum curves exist, or they
                           were all filtered out by the filter function.
      Other              - Any other value is the value returned by the action
			   function (visiting stopped).
*/

extern ProError ProAsmcomppathDispCsysVisit (ProAsmcomppath        *p_path,
                                             ProSolid               handle,
                                           ProCsysFilterAction    filter_action,
                                            ProCsysVisitAction     visit_action,
                                             ProAppData             app_data);
/*
   Purpose:     Visits all the displayed coordinate systems in the solid handle. 

   Input Arguments:
      p_path            - The solid handle's assembly component path.
      handle            - The solid handle. Passed in for performance reasons.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL,
                          visits all items using the action function.
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the items.
      PRO_TK_E_NOT_FOUND - Either no displayed coordinate systems exist, or they
                           were all filtered out by the filter function.
      Other              - Any other value is the value returned by the action
			   function (visiting stopped).
*/

 
extern ProError ProAsmcomppathDispQuiltVisit (ProAsmcomppath       *p_path,
                                              ProSolid              handle,
                                            ProQuiltFilterAction  filter_action,
                                             ProQuiltVisitAction   visit_action,
                                              ProAppData            app_data);
/*
   Purpose:     Visits all the displayed datum quilts in the solid handle. 

   Input Arguments:
      p_path            - The solid handle's assembly component path.
      handle            - The solid handle. Passed in for performance reasons.
      visit_action      - The visiting function. If it returns anything other 
                          than PRO_TK_NO_ERROR, visiting stops.
      filter_action     - The filter function. If NULL,
                          visits all items using the action function.
      app_data          - The application data passed to the filter 
                          and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully visited all the items.
      PRO_TK_E_NOT_FOUND - Either no displayed datum quilt exist, or they
                           were all filtered out by the filter function.
      Other              - Any other value is the value returned by the action
			   function (visiting stopped).
*/

typedef ProError (*ProAsmcompActivatePreAction) (ProAsmcomppath*  active_path, 
                                                 ProSolid         active_model);
/*
        Purpose:  This is the notification function that is called when the user 
                  chooses to activate a model from the model tree using 
                  "Activate", befor any actions are taken. This function is to 
                  be supplied by the user by calling <b>ProNotificationSet()</b> 
                  with the notify type PRO_ASMCOMP_ACTIVATION_PRE.

        Input Arguments:
                active_path - The path to the new active model. 
                active_model - The newly activated model.

        Output Arguments: 
                none
        
        Return Values:
                PRO_TK_NO_ERROR    - Continue activation.
                Other              - Error happend. Abort the activation.
*/

typedef ProError (*ProAsmcompActivatePostAction) (ProAsmcomppath*  active_path, 
                                                  ProSolid         active_model,
                                                  ProError         in_err);
/*
        Purpose:  This is the notification function that is called when the user 
                  chooses to activate a model from the model tree using 
                  "Activate", after actual activation was done. This function 
                  is to be supplied by the user by calling 
                  <b>ProNotificationSet()</b> with the notify type 
                  PRO_ASMCOMP_ACTIVATION_POST.

        Input Arguments:
                active_path - The path to the new active model. 
                active_model - The newly activated model.
                in_err - PRO_TK_NO_ERROR if the user accepted activation of 
                                         the component;
                         PRO_TK_ABORT if the user cancelled activation.

        Output Arguments: 
                none
        
        Return Values:
                PRO_TK_NO_ERROR    - Activation was successfully finished.
                Other              - Activation finished, but with problems.
*/

PRO_END_C_DECLS
#endif

