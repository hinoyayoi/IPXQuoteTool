#ifndef PROMFGFEATTURNTHREAD_H
#define PROMFGFEATTURNTHREAD_H
/*
   Creo Parametric TOOLKIT declarations related to mfg thread turning sequences.
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
    |--PRO_E_TURN_THREAD_LOCATION_TYPE
    |
    |--PRO_E_TURN_THREAD_OUTPUT_TYPE
    |
    |--PRO_E_TURN_THREAD_FORM_TYPE
    |
    |-- PRO_E_NCSEQ_CSYS
    |
    |-- PRO_E_MFG_SUB_SPINDLE_OPT
    |
    |-- PRO_E_MFG_TOOL_REF_COMPOUND
    |
    |-- PRO_E_MFG_PARAM_SITE_NAME
    |
    |-- PRO_E_MFG_PARAM_ARR
    |
    |--PRO_E_TURN_PROFILE
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
PRO_E_TURN_THREAD_LOCATION_TYPE Location Type        PRO_VALUE_TYPE_INT        Note-5
PRO_E_TURN_THREAD_OUTPUT_TYPE   Output Type          PRO_VALUE_TYPE_INT        Note-6
PRO_E_TURN_THREAD_FORM_TYPE     Form Type            PRO_VALUE_TYPE_INT        Note-7
PRO_E_NCSEQ_CSYS                Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-8
PRO_E_MFG_TOOL_REF_COMPOUND     Tool                 Compound                  Note-9
PRO_E_MFG_PARAM_SITE_NAME       Site Name            PRO_VALUE_TYPE_WSTRING    Note-10
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-11
PRO_E_TURN_PROFILE              Turning Profile      PRO_VALUE_TYPE_SELECTION  Note-12
PRO_E_TOOL_MTN_ARR              Tool Motion Array    Array                     Note-13
PRO_E_TOOL_MTN                  Tool Motion          Compound                  Note-14
PRO_E_MFG_START_PNT             Start Point          PRO_VALUE_TYPE_SELECTION  Note-15
PRO_E_MFG_END_PNT               End Point            PRO_VALUE_TYPE_SELECTION  Note-16
PRO_E_MFG_PREREQUISITE_ARR      Prerequisite Array   Array                     Note-17
PRO_E_MFG_PROCESS_REF           Process Reference    PRO_VALUE_TYPE_SELECTION  Note-18
PRO_E_MFG_FEAT_VIEW_NAME        View Name            PRO_VALUE_TYPE_WSTRING    Note-19
PRO_E_MFG_SIMP_REP_NAME         Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-20
PRO_E_MFG_TIME_ESTIMATE         Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-21
PRO_E_MFG_COST_ESTIMATE         Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-22
PRO_E_MFG_TIME_ACTUAL           Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-23
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-24
PRO_E_MFG_SUB_SPINDLE_OPT       Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-25

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_TURN
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_THREAD_TURN
          Mandatory.

Note-4  : Operation feature selection.
          Mandatory.

Note-5  : PRO_E_TURN_OPTION_OUT - external thread;
          PRO_E_TURN_OPTION_IN  - internal thread;
          Mandatory.

Note-6  : Output type (ISO or AI MACRO).
          PRO_E_TURN_THREAD_ISO       - ISO;
          PRO_E_TURN_THREAD_AI_MACRO  - AI MACRO;
          Mandatory.

Note-7  : Thread type (Unified, Acme, Buttress, or General).
          PRO_E_TURN_THREAD_UNIFIED   - Unified;
          PRO_E_TURN_THREAD_GENERAL   - General;
          PRO_E_TURN_THREAD_BUTTRESS  - Buttress;
          PRO_E_TURN_THREAD_ACME      - Acme;
          Mandatory.

Note-8  : Coordinate system datum feature. To be used as a sequence 
          coordinate system.
          Mandatory.

Note-9  : Tool reference compound definition.
          Please see ProMfgElemToolRef.h.
          Mandatory.

Note-10 : Name of site with default values for manufacturing parameters.
          Name is going to be ignored if site doesn't exist in the mfg 
          model.
          Optional.
         
Note-11 : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-12 : Turn profile selection.
          Mandatory.

Note-13 : Array of tool motions.
          Mandatory.

Note-14 : Tool motion compound specification.
          Optional.

Note-15 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-16 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-17 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-18 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-19 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-20 : Simplified representation name. Allows to associate specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-21 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-22 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-23 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-24 : Sequence comments.

Note-25 : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATTURNTHREAD_H */
