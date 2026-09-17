#ifndef PROMFGFEATFIXTURE_H
#define PROMFGFEATFIXTURE_H
/*
   Creo Parametric TOOLKIT declarations related to mfg fixture setup feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Feature element tree

 PRO_E_FEATURE_TREE
    |   
    |-- PRO_E_FEATURE_TYPE
    |
    |-- PRO_E_STD_FEATURE_NAME
    |
    |-- PRO_E_MFG_OPER_REF
    |
    |-- PRO_E_FIXTURE_COMPONENT_REF
    |
    |-- PRO_E_MFG_FEAT_VIEW_NAME
    |
    |-- PRO_E_MFG_SIMP_REP_NAME
    |
    |-- PRO_E_MFG_TIME_ESTIMATE
    |
    |-- PRO_E_MFG_COST_ESTIMATE
    |
    |-- PRO_E_MFG_TIME_ACTUAL
    |
    |-- PRO_E_MFG_COMMENTS

===============================================================================

(2) Elements table

---------------------------------------------------------------------------------------
Element Id                  Element Name         Data Type                 Valid Values
---------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME      Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_MFG_OPER_REF          Operation            PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_FIXTURE_COMPONENT_REF Components Reference PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_MFG_FEAT_VIEW_NAME    View Name            PRO_VALUE_TYPE_WSTRING    Note-5
PRO_E_MFG_SIMP_REP_NAME     Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-6
PRO_E_MFG_TIME_ESTIMATE     Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-7
PRO_E_MFG_COST_ESTIMATE     Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-8
PRO_E_MFG_TIME_ACTUAL       Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-9
PRO_E_MFG_COMMENTS          Comments             PRO_VALUE_TYPE_WSTRING    Note-10

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_FIXSETUP
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : Operation feature selection.
          Mandatory.

Note-4  : Selection of components. 
          Element supports multiple selections.
          Components have to exist (inserted) in mfg assembly. 
          Optional.

Note-5  : View name. Allows to associated specific view with a machining step.
          Used only in special process application.
          Optional.

Note-6  : Simplified representation name. Allows to associated specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-7  : Time estimate. Allows to specify time estimate for the 
          fixture setup step.
          Used only in special process application.
          Optional.

Note-8  : Cost estimate. Allows to specify cost estimate for the 
          fixture setup step.
          Used only in special process application.
          Optional.

Note-9  : Actual time. Allows to specify actual time for the fixture setup 
          step.
          Used only in special process application.
          Optional.

Note-10 : Fixture setup comments.

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATFIXTURE_H */
