#ifndef PROMFGFEATOPERATION_H
#define PROMFGFEATOPERATION_H
/*
   Creo Parametric TOOLKIT declarations related to mfg operation.
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
    |-- PRO_E_OPER_CSYS
    |
    |-- PRO_E_OPER_SUBSP_CSYS
    |
    |-- PRO_E_MFG_WCELL_REF
    |
    |-- PRO_E_RETR_SURF
    |
    |-- PRO_E_MFG_FROM1_PNT
    |
    |-- PRO_E_MFG_HOME1_PNT
    |
    |-- PRO_E_MFG_FROM2_PNT
    |
    |-- PRO_E_MFG_HOME2_PNT
    |
    |-- PRO_E_MFG_FROM3_PNT
    |
    |-- PRO_E_MFG_HOME3_PNT
    |
    |-- PRO_E_MFG_FROM4_PNT
    |
    |-- PRO_E_MFG_HOME4_PNT
    |
    |-- PRO_E_MFG_PARAM_ARR
    |
    |-- PRO_E_MFG_OPER_STOCK_MATERIAL
    |
    |-- PRO_E_MFG_FIXTURE_REF
    |
    |-- PRO_E_FIXTURE_COMPONENT_REF
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

-------------------------------------------------------------------------------------------
Element Id                      Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME          Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_OPER_CSYS                 Output Csys          PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_MFG_WCELL_REF             Workcell             PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_RETR_SURF                 Retract Surface      Compound                  Note-5
PRO_E_MFG_FROM1_PNT             From Point 1         PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_MFG_HOME1_PNT             Home Point 1         PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_MFG_FROM2_PNT             From Point 2         PRO_VALUE_TYPE_SELECTION  Note-8
PRO_E_MFG_HOME2_PNT             Home Point 2         PRO_VALUE_TYPE_SELECTION  Note-9 
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-10
PRO_E_MFG_OPER_STOCK_MATERIAL   Stock Material       PRO_VALUE_TYPE_WSTRING    Note-11
PRO_E_MFG_FIXTURE_REF           Fixture Reference    PRO_VALUE_TYPE_SELECTION  Note-12
PRO_E_MFG_TIME_ESTIMATE         Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-13
PRO_E_MFG_COST_ESTIMATE         Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-14
PRO_E_MFG_TIME_ACTUAL           Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-15
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-16
PRO_E_FIXTURE_COMPONENT_REF     Fixture Components   Array                     Note-17
PRO_E_OPER_SUBSP_CSYS           Sub-spindle Csys     PRO_VALUE_TYPE_SELECTION  Note-18
PRO_E_MFG_FROM3_PNT             From Point 3         PRO_VALUE_TYPE_SELECTION  Note-19
PRO_E_MFG_HOME3_PNT             Home Point 3         PRO_VALUE_TYPE_SELECTION  Note-20
PRO_E_MFG_FROM4_PNT             From Point 4         PRO_VALUE_TYPE_SELECTION  Note-21
PRO_E_MFG_HOME4_PNT             Home Point 4         PRO_VALUE_TYPE_SELECTION  Note-22 
===============================================================================

(3) Notes

Note-1  : PRO_FEAT_OPERATION
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : Coordinate system geometry item selection. To be used as an 
          operation coordinate system.
          Mandatory.

Note-4  : Workcell feature selection.
          Mandatory.

Note-5  : Retract compound definition.
          Please see ProMfgElemRetract.h.
          Optional.

Note-6  : Datum point geometry item selection. Allows to start machining by 
          head 1 tool at the specified position.
          Optional.

Note-7  : Datum point geometry item selection. Allows to end machining by 
          head 1 tool at the specified position.
          Optional.

Note-8  : Datum point geometry item selection. Allows to start machining by 
          head 2 tool at the specified position.
          Optional. Ignored for workcells with single head.

Note-9  : Datum point geometry item selection. Allows to end machining by 
          head 2 tool at the specified position.
          Optional. Ignored for workcells with single head.

Note-10 : Array of applicable manufacturing parameters.
          Optional.

          For new features: if the parameter array is not specified - default
          values are going to be assigned to the corresponding manufacturing
          parameters of the created feature.

          Please see ProMfgElemParam.h.

Note-11 : Stock material name.
          Optional.

Note-12 : Selection of a fixture setup feature. 
          Optional.

Note-13 : Time estimate. Allows to specify time estimate for the 
          operation.
          Used only in special process application.
          Optional.

Note-14 : Cost estimate. Allows to specify cost estimate for the 
          operation.
          Used only in special process application.
          Optional.

Note-15 : Actual time. Allows to specify actual time for the operation.
          Used only in special process application.
          Optional.

Note-16 : Operation comments.

Note-17 : Array of fixture components. 
          Element supports multiple selections.
          Allows specification of operation fixture setup components 
          (inserted into the top assembly).
          Can be specified either in combination with or without a fixture 
          setup reference specified by PRO_E_MFG_FIXTURE_REF.
          Optional.

Note-18 : Coordinate system geometry item selection. To be used as a
          sub-spindle coordinate system.
          Optional.

Note-19 : Datum point geometry item selection. Allows to start machining by
          head 3 tool at the specified position.
          Optional. Ignored for workcells with number of heads less than 3.

Note-20 : Datum point geometry item selection. Allows to end machining by
          head 3 tool at the specified position.
          Optional. Ignored for workcells with number of heads less than 3.

Note-21 : Datum point geometry item selection. Allows to start machining by
          head 4 tool at the specified position.
          Optional. Ignored for workcells with number of heads less than 4.

Note-22 : Datum point geometry item selection. Allows to end machining by
          head 4 tool at the specified position.
          Optional. Ignored for workcells with number of heads less than 4.
=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATOPERATION_H */
