#ifndef PROCURVE_H
#define PROCURVE_H

/* Function declarations for ProCurve. */



#include   <ProObjects.h>
#include   <ProGeomitem.h>
#include   <ProColor.h>

PRO_BEGIN_C_DECLS

/*===========================================================================*/

extern ProError ProCurveInit(ProSolid  owner_handle,
                             int       curve_id,
                             ProCurve *p_handle);
/*
   Purpose: Initializes the <i>ProCurve</i> handle.

   Input Arguments:
      owner_handle      - The solid owner of the curve
      curve_id          - The curve identifier

   Output Arguments:
      p_handle          - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProCurveIdGet(ProCurve  curve,
                              int      *p_id);
/*
   Purpose: Retrieves the identifier of the curve object.
<p>
            NOTE:
<p> 
            Although the pointer can be reallocated, the identifier
            will not change.

   Input Arguments:
      curve            - The curve handle

   Output Arguments:
      p_id             - The returned identifier of the curve 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


#define ProCurveDatatypeGet() (PRO_CURVE)


extern ProError ProCurveDataGet(ProCurve          curve,
                                ProGeomitemdata **p_data_ptr);
/*
   Purpose: Retrieves the geometric representation data for the 
            specified curve.
<p>
            Note that this function is not implemented for composite
            curves.

   Input Arguments:
      curve                 - The curve handle.

   Output Arguments:
      p_data_ptr            - The curve data. The function allocates the
                              memory for this argument. Use the function
                              <b>ProGeomitemdataFree()</b> to free the memory.

   Return Values:
      PRO_TK_NO_ERROR        - The function successfully retrieved the
                               information.
      PRO_TK_BAD_INPUTS      - The input argument is invalid.
      PRO_TK_NOT_IMPLEMENTED - You passed a composite curve in <i>curve</i>.

   See Also:
      ProGeomitemdataFree()
*/


extern ProError ProCurveXyzdataEval(ProCurve  p_curve,
                                    double    curve_param,
                                    ProVector xyz_point,
                                    ProVector deriv1,
                                    ProVector deriv2);
/*
   Purpose: Evaluates the specified curve at the parameter. If you pass
	    a composite curve in <i>p_curve</i>, both <i>deriv1</i> and 
            <i>deriv2</i> should be NULL.

   Input Arguments:
      p_curve           - The curve handle
      curve_param       - The normalized parameter on the curve

   Output Arguments:
      xyz_point         - The resulting XYZ point
      deriv1            - The first derivative 
      deriv2            - The second derivative

   Return Values:
      PRO_TK_NO_ERROR        - The function successfully evaluated the
                               curve.
      PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
      PRO_TK_NOT_IMPLEMENTED - The argument <i>p_curve</i> represents a 
                               composite curve, while <i>deriv1</i> or 
                               <i>deriv2</i> is not NULL. 
*/


extern ProError ProCurveParamEval(ProCurve   p_curve,
                                  ProVector  xyz_point,
                                  double    *p_param);
/*
   Purpose: Finds the corresponding normalized parameter on the curve,
            given the XYZ point.

   Input Arguments:
      p_curve           - The curve handle.
      xyz_point         - The XYZ point. The point does not necessarily have
                          to lie on the curve. If the point is off the
                          curve, the function finds the closest curve point.

   Output Arguments:
      p_param           - The corresponding normalized parameter on the curve.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the point.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProCurveLengthEval(ProCurve  p_curve, 
                                   double   *p_length);
/*
   Purpose: Finds the length of the specified curve.

   Input Arguments:
      p_curve           - The curve handle

   Output Arguments:
      p_length          - The length of the curve

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the curve.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern ProError ProCurveTypeGet(ProCurve    p_curve,
                                ProEnttype *p_curve_type);
/*
   Purpose: Finds the type of the specified curve. 

   Input Arguments:
      p_curve           - The curve handle

   Output Arguments:
      p_curve_type      - The curve type 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the curve type.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


typedef ProError (*ProCurveCompFilter)(ProCurve   p_curve,
                                       ProCurve   p_comp,
                                       int        comp_idx,
                                       ProBoolean comp_flip,
                                       ProAppData app_data);
/*
   Purpose:  This is the filter function for <b>ProCurveCompVisit()</b>.

   Input Arguments:
      p_curve   - The composite curve being processed.
      p_comp    - The current component being visited.
      comp_idx  - The index of the current component in the curve.
      comp_flip - This is PRO_TK_TRUE if the current component is flipped.
      app_data  - The data being passed to <b>ProCurveCompVisit()</b> 
                  by the caller.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Call the visit action.
      PRO_TK_CONTINUE      - Skip to the next curve.
      PRO_TK_GENERAL_ERROR - Stop visiting.
*/

/*===========================================================================*/

typedef ProError (*ProCurveCompAction)(ProCurve   p_curve, 
                                       ProCurve   p_comp,
                                       int        comp_idx,
                                       ProBoolean comp_flip,
                                       ProError   status,
                                       ProAppData app_data);

/*
   Purpose: This is the visiting function for <b>ProCurveCompVisit()</b>.

   Input Arguments:
      p_curve   - The composite curve being processed.
      p_comp    - The current component being visited.
      comp_idx  - The index of the current component in the curve.
      comp_flip - This is PRO_TK_TRUE if the current component is flipped.
      status    - The status returned by the filter, or PRO_TK_NO_ERROR if 
                  the filter is not specified.
      app_data  - The data being passed to <b>ProCurveCompVisit()</b> 
                  by the caller.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Continue visiting the next curve.
      PRO_TK_GENERAL_ERROR - Stop visiting.
*/

/*===========================================================================*/

extern ProError ProCurveCompVisit(ProCurve           p_curve,
                                  ProCurveCompAction action,
                                  ProCurveCompFilter filter,
                                  ProAppData         app_data);
/*
   Purpose: Visits the components of the specified composite curve. 

   Input Arguments:
      p_curve           - The curve handle.
      action            - The action function to be called for each
                          component. If the function returns anything
                          other than PRO_TK_NO_ERROR, visiting stops.
                          This can be NULL, which will cause only the
                          filter function to be called for each curve.
      filter            - The filter function. If NULL, all components
                          are visited using the action function.
      app_data          - The application data passed to the filter and 
                          visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR        - The function successfully visited the
                               components.
      PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
      PRO_TK_NOT_IMPLEMENTED - The <i>p_curve</i> is a valid geometry item, 
                               but not a composite curve.
      PRO_TK_E_NOT_FOUND     - No components were visited, either because of 
                               the filter or for another reason.
      Other                  - Any other value is the value returned by the
                               action function (visiting stopped).

*/


extern ProError ProCurveToNURBS(ProCurve       curve,
                                ProCurvedata **p_nurb_curve_data);
/*
   Purpose: Generates the NURBS surface representation, given the curve
            handle.

   Input Arguments:
      curve             -  The curve handle.

   Output Arguments:
      p_nurb_curve_data -  The curve data. The function allocates the
                           memory for this structure. To free the memory, 
                           call the function <b>ProCurvedataFree()</b>.
                           
   Return Values:
      PRO_TK_NO_ERROR       -  The function successfully generated the 
                               NURBS surface representation.
      PRO_TK_GENERAL_ERROR  -  A general error occurred and the function
                               failed.

   See Also:
      ProCurvedataFree()
*/


extern ProError ProCurveDataFree(ProCurvedata **p_curve_data);
/*
   Purpose:  Frees the memory for the specified <i>ProCurvedata</i> structure.

   Input Arguments:
      p_curve_data - The address to <i>ProCurvedata*</i>, allocated by 
                     a previous call to <b>ProCurveToNURBS()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the
                          memory. 
      PRO_TK_BAD_INPUTS - The argument is invalid.

   See Also:
      ProCurveToNURBS()
*/


extern  ProError ProCurveLengthT1T2Eval(ProCurve  p_curve_handle,
                                        double    t1,
                                        double    t2,
                                        double   *r_length);
/*
   Purpose: Finds the length of the specified curve between two given 
            parameters.

   Input Arguments:
      p_curve_handle    - The curve handle
      t1                - The start parameter
      t2                - The end parameter

   Output Arguments:
      r_length          - The curve length

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully evaluated the edge length.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/


extern ProError ProCurveParamByLengthEval(ProCurve  p_curve_handle,
                                          double    t_start,
                                          double    length,
                                          double   *r_t,
                                          Pro3dPnt  r_point);
/*
   Purpose: Finds the parameter of the point located at the given length
            from the given parameter.

   Input Arguments:
      p_curve_handle     - The curve handle
      t_start            - The start parameter
      length             - The given length

   Output Arguments:
      r_t                - The output parameter
      r_point            - The point

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully evaluated the edge length.
      PRO_TK_BAD_SRF_CRV - The input argument is invalid.
*/


extern  ProError ProCurveColorGet(ProCurve      p_curve,
                                  ProColortype *p_color);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProCurvePersistentColorGet
   Purpose: <b>NOTE:</b>
            <p>
            This function is <b>deprecated</b>.
            Use ProCurvePersistentColorGet() instead.
            </p>
            Finds the color of the specified curve.

   Input Arguments:
      p_curve           - The curve handle

   Output Arguments:
      p_color           - The retrieved color of the curve

   Return Values:
      PRO_TK_NO_ERROR   - The function completed successfully.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern  ProError ProCurvePersistentColorGet(ProCurve      p_curve,
                                            ProColortype *p_color);
/*
   Purpose: Finds the color of the specified curve.

   Input Arguments:
      p_curve           - The curve handle

   Output Arguments:
      p_color           - The retrieved color of the curve

   Return Values:
      PRO_TK_NO_ERROR   - The function completed successfully.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern  ProError ProCurveColorSet(ProCurve      p_curve,
                                  ProColortype  new_color,
                                  ProColortype *p_old_color);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProCurvePersistentColorSet
   Purpose: <b>NOTE:</b>
            <p>
            This function is <b>deprecated</b>.
            Use ProCurvePersistentColorSet() instead.
            </p>
            Sets the color of the specified curve, and returns the
            original color.
            <B>Note:</B><P> In order to see the change made to the color,
            use the function ProDisplistInvalidate() on the owner model.</P>

   Input Arguments:
      p_curve           - The curve handle
      new_color         - The new color for the curve

   Output Arguments:
      p_old_color       - The color of the curve before the change

   Return Values:
      PRO_TK_NO_ERROR   - The function completed successfully.
      PRO_TK_BAD_INPUTS - Invalid input argument(s).
*/

extern ProError ProCurvePersistentColorSet(ProSolid     p_solid,
                                           ProCurve     p_curve,
                                           ProColortype new_color);
/*
    Purpose: Sets the color of the specified curve.
             <B>Note:</B><P> In order to see the change made to the color,
             use the function ProDisplistInvalidate() on the owner model.</P>


    Input Arguments:
       p_solid              - The solid owner of the curve
       p_curve              - The curve handle
       new_color            - The new color for the curve

    Output Arguments:
       none

    Return Values:
       PRO_TK_NO_ERROR      - The function succeeded.
       PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
       PRO_TK_GENERAL_ERROR - There was a general error and the function failed.
*/


extern  ProError ProCurveLinestyleGet(ProCurve      p_curve,
                                      ProLinestyle *p_linestyle);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProCurvePersistentLinestyleGet
   Purpose: <b>NOTE:</b>
            <p>
            This function is <b>deprecated</b>.
            Use ProCurvePersistentLinestyleGet() instead.
            </p> 
            Finds the linestyle of the specified curve.

   Input Arguments:
      p_curve           - The curve handle

   Output Arguments:
      p_linestyle       - The retrieved linestyle of the curve

   Return Values:
      PRO_TK_NO_ERROR   - The function completed successfully.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern  ProError ProCurvePersistentLinestyleGet(ProCurve      p_curve,
                                                ProLinestyle *p_linestyle);
/*
   Purpose: Finds the linestyle of the specified curve.

   Input Arguments:
      p_curve           - The curve handle

   Output Arguments:
      p_linestyle       - The retrieved linestyle of the curve

   Return Values:
      PRO_TK_NO_ERROR   - The function completed successfully.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


extern  ProError ProCurveLinestyleSet(ProCurve      p_curve,
                                      ProLinestyle  new_linestyle,
                                      ProLinestyle *p_old_linestyle);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProCurvePersistentLinestyleSet
   Purpose: <b>NOTE:</b>
            <p>
            This function is <b>deprecated</b>.
            Use ProCurvePersistentLinestyleSet() instead.
            </p> 
            Sets the linestyle of the specified curve, and returns
            the original linestyle.
            <B>Note:</B><P>In order to see the change made to the linestyle,
            use the function ProDisplistInvalidate() on the owner model.</P>

   Input Arguments:
      p_curve           - The curve handle
      new_linestyle     - The new linestyle for the curve

   Output Arguments:
      p_old_linestyle   - The linestyle of the curve before the change

   Return Values:
      PRO_TK_NO_ERROR   - The function completed successfully.
      PRO_TK_BAD_INPUTS - Invalid input argument(s).
*/

extern ProError ProCurvePersistentLinestyleSet(ProSolid     p_solid,
                                               ProCurve     p_curve,
                                               ProLinestyle new_linestyle);
/*
    Purpose: Sets the linestyle of the specified curve.
             <B>Note:</B><P> In order to see the change made to the linestyle,
             use the function ProDisplistInvalidate() on the owner model.</P>


    Input Arguments:
       p_solid              - The solid owner of the curve
       p_curve              - The curve handle
       new_linestyle        - The new linestyle for the curve

    Output Arguments:
       none

    Return Values:
       PRO_TK_NO_ERROR      - The function succeeded.
       PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
       PRO_TK_GENERAL_ERROR - There was a general error and the function failed.
*/


extern ProError ProCurveTessellationGet(ProCurve   p_curve_handle,
                                        double     tolerance,
                                        Pro3dPnt **p_points,
                                        int       *p_count);
/*
   Purpose: Retrieves the curve tessellation for the specified datum curve.

   Input Arguments:
      p_curve_handle    - The curve handle
      tolerance         - The maximum distance between the tessellation
                          polyline and the curve.
   Output Arguments:
      p_points          - The list of tessellation points (to be released
                          by ProArrayFree()). If not required, this
                          argument can be NULL.
      p_count           - The number of tessellation points.

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input argument was invalid.
*/

				   
PRO_END_C_DECLS
#endif /* PROCURVE_H */
