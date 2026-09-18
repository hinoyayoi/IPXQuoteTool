#ifndef PROMFGFEATFINISHING_H
#define PROMFGFEATFINISHING_H
/*
   Creo Parametric TOOLKIT declarations related to mfg milling finishing sequence.
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
    |-- PRO_E_NCSEQ_TYPE
    |
    |-- PRO_E_MFG_OPER_REF
    |
    |-- PRO_E_NCSEQ_CSYS
    |
    |-- PRO_E_RETR_SURF
    |
    |-- PRO_E_MFG_SUB_SPINDLE_OPT
    |
    |-- PRO_E_MFG_TOOL_REF_COMPOUND
    |
    |-- PRO_E_MFG_TOOL_ADAPTER_NAME
    |
    |-- PRO_E_MFG_PARAM_SITE_NAME
    |
    |-- PRO_E_MFG_PARAM_ARR
    |
    |-- PRO_E_MFG_CMP_MILL_WIND
    |
    |-- PRO_E_TOOL_MTN_ARR
    |      |
    |      |-- PRO_E_TOOL_MTN
    |
    |-- PRO_E_MFG_START_PNT
    |
    |-- PRO_E_MFG_END_PNT
    |
    |-- PRO_E_MFG_PREREQUISITE_ARR
    |
    |-- PRO_E_MFG_PROCESS_REF
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

(2) Feature elements table

-------------------------------------------------------------------------------------------
Element Id                      Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME          Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_NCSEQ_TYPE                Sequence Type        PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_OPER_REF              Operation            PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_NCSEQ_CSYS                Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-5
PRO_E_RETR_SURF                 Retract Surface      Compound                  Note-6
PRO_E_MFG_TOOL_REF_COMPOUND     Tool                 Compound                  Note-7
PRO_E_MFG_TOOL_ADAPTER_NAME     Tool Attachment      PRO_VALUE_TYPE_WSTRING    Note-8
PRO_E_MFG_PARAM_SITE_NAME       Site Name            PRO_VALUE_TYPE_WSTRING    Note-9
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-10
PRO_E_MFG_CMP_MILL_WIND         Mill Window          Compound                  Note-11
PRO_E_TOOL_MTN_ARR              Tool Motion Array    Array                     Note-12
PRO_E_TOOL_MTN                  Tool Motion          Compound                  Note-13
PRO_E_MFG_START_PNT             Start Point          PRO_VALUE_TYPE_SELECTION  Note-14
PRO_E_MFG_END_PNT               End Point            PRO_VALUE_TYPE_SELECTION  Note-15
PRO_E_MFG_PREREQUISITE_ARR      Prerequisite Array   Array                     Note-16
PRO_E_MFG_PROCESS_REF           Process Reference    PRO_VALUE_TYPE_SELECTION  Note-17
PRO_E_MFG_FEAT_VIEW_NAME        View Name            PRO_VALUE_TYPE_WSTRING    Note-18
PRO_E_MFG_SIMP_REP_NAME         Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-19
PRO_E_MFG_TIME_ESTIMATE         Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-20
PRO_E_MFG_COST_ESTIMATE         Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-21
PRO_E_MFG_TIME_ACTUAL           Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-22
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-23
PRO_E_MFG_SUB_SPINDLE_OPT       Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-24

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_MILL
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_CVNC_FINISH_MILL
          Mandatory.

Note-4  : Operation feature selection.
          Mandatory.

Note-5  : Coordinate system datum feature. To be used as a sequence coordinate 
          system.
          Mandatory.

Note-6  : Retract compound definition.
          Please see ProMfgElemRetract.h.
          Mandatory.

Note-7  : Tool reference compound definition.
          Please see ProMfgElemToolRef.h.
          Mandatory.

Note-8  : Tool adapter model name.
          Optional.

Note-9  : Name of site with default values for manufacturing parameters.
          Name is going to be ignored if site doesn't exist in the mfg model.
          Optional.
         
Note-10 : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-11 : Mill window compound definition.
          Please see ProMfgElemMachWindow.h.
          Mandatory.

Note-12 : Array of tool motions.
          Mandatory.

Note-13 : Tool motion compound specification. Mandatory.

          Applicable tool motion types:
            PRO_TM_TYPE_AUTOMATIC_CUT (please see ProMfgElemToolMtnAutoCut.h)

Note-14 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-15 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-16 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-17 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-18 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-19 : Simplified representation name. Allows to associate specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-20 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-21 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-22 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-23 : Sequence comments.

Note-24 : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATFINISHING_H */
