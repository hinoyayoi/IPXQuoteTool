
#ifndef PROFOREIGNCURVE_H
#define PROFOREIGNCURVE_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSizeConst.h>
#include <ProSelection.h>




/*
        Function and element tree declarations for foreign datum curves.
Foreign datum curves will be represented as Creo Parametric datum curves of type
spline, unless there are only two points, in which case the curve will
be represented as a line.

*/

/**********************************************************************\

Foreign Datum Curve feature element tree:

   PRO_E_FEATURE_TREE
        |
        |--PRO_E_FEATURE_TYPE
        |
        |--PRO_E_CURVE_TYPE
        |
        |--PRO_E_FOREIGN_CURVE_CLASS
        |
        |--PRO_E_FOREIGN_CURVE_CSYS_REF
        |
        |--PRO_E_FOREIGN_CURVE_DATA_VAL
        |
        |--PRO_E_CURVE_CONTINUITY


Feature elements table

---------------------------------------------------------------------------------------------------------------------------
\***************************************************************************/

PRO_BEGIN_C_DECLS

/*====================================================================*/

typedef ProError (*ProForeignCurveEvalFunction) (ProName crv_class,
                                         wchar_t       *data_val,
                                         ProSelection   csys,
                                         double         curve_param,
                                         ProVector      xyz_point,
                                         ProVector      deriv1,
                                         ProVector      deriv2);


/*
        Purpose: Defines the format for a user-supplied function that
                 serves as a curve evaluator.

        Input Arguments:
                crv_class      - The class
                data_val       - The data passed from an element in
                                 the tree
                curve_param    - The normalized curve parameter
                csys           - The coordinate system

        Output Arguments:
                xyz_point      - The resulting XYZ point
                deriv1         - The first derivative
                deriv2         - The second derivative

        Return Values:
                PRO_TK_NO_ERROR    - The function successfully evaluated
                                     the curve.
                PRO_TK_BAD_INPUTS  - One or more of the input arguments are
                                     invalid.

*/

extern  ProError ProForeignCurveClassEvalSet  (ProName crv_class,
                                        ProForeignCurveEvalFunction  eval_func);

/*
        Purpose:  Binds the foreign curve class to the user's evaluation
                  function.
                  <p>
                  NOTE:
                  <p>
                  If you call this function with <I>eval_func</I> set to NULL,
                  the class will "unbind" from the previously bound
                  evaluation function.

        Input Arguments:
                crv_class   - The curve class
                eval_func   - The evaluation function

        Output Arguments:
                None

        Return Values:
           PRO_TK_NO_ERROR    - The function successfully bound the class.
           PRO_TK_BAD_INPUTS  - The specified class name is NULL, or the
                                class name is empty.
           PRO_TK_E_NOT_FOUND - The specified class name was not found,
                                when the <I>eval_func</I> is NULL.

*/

/*
Feature elements table

------------------------------------------------------------------------
Element Id                     Element Name Data Type                Valid Values
------------------------------------------------------------------------

PRO_E_FEATURE_TYPE             Feature Type PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE               Curve Type   PRO_VALUE_TYPE_INT       PRO_CURVE_TYPE_FOREIGN
PRO_E_FOREIGN_CURVE_CLASS      Class        PRO_VALUE_TYPE_WSTRING   wchar_t *w
PRO_E_FOREIGN_CURVE_CSYS_REF   Reference    PRO_VALUE_TYPE_SELECTION CSYS
PRO_E_FOREIGN_CURVE_DATA_VAL   Value        PRO_VALUE_TYPE_ WSTRING  wchar_t *w
PRO_E_FOREIGN_CURVE_CONTINUITY Continuity   PRO_VALUE_TYPE_INT       see ProForeignCrvCont
----------------------------------------------------------------------------*/

#define PRO_CURVE_TYPE_FOREIGN 43

typedef enum pro_foreign_crv_cont
{
   PRO_FOREIGN_CURVE_CALC_XYZ             = 0,
   PRO_FOREIGN_CURVE_CALC_XYZ_1_DER       = 1,
   PRO_FOREIGN_CURVE_CALC_XYZ_1_AND_2_DER = 2
} ProForeignCrvCont;


PRO_END_C_DECLS

#endif


