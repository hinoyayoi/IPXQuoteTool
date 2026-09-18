#ifndef PROMFGFEATHOLEMAKING_H
#define PROMFGFEATHOLEMAKING_H
/*
   Creo Parametric TOOLKIT declarations related to mfg holemaking sequences:

      - drilling;
      - web drilling;
      - countersining;
      - counterboring;
      - reaming;
      - tapping;
      - custom cycle holemaking;
      - face holemaking.
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
    |-- PRO_E_HOLEMAKING_TYPE
    |
    |-- PRO_E_DRILL_MODE
    |
    |-- PRO_E_MFG_OPER_REF
    |
    |-- PRO_E_MFG_HOLEMAKING_CYCLE_TYPE
    |
    |-- PRO_E_MFG_SEQ_NUM_AXES_OPT
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
    |-- PRO_E_MFG_CUSTOM_CYCLE_NAME
    |
    |-- PRO_E_HOLESETS
    |
    |-- PRO_E_CHECK_SURF_COLL
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

(2) Elements table

-------------------------------------------------------------------------------------------
Element Id                      Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME          Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_NCSEQ_TYPE                Sequence Type        PRO_VALUE_TYPE_INT        Note-3
PRO_E_HOLEMAKING_TYPE           Holemaking Type      PRO_VALUE_TYPE_INT        Note-4
PRO_E_DRILL_MODE                Drill Mode           PRO_VALUE_TYPE_INT        Note-5
PRO_E_MFG_OPER_REF              Operation            PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_MFG_HOLEMAKING_CYCLE_TYPE Cycle Type           PRO_VALUE_TYPE_INT        Note-7
PRO_E_MFG_SEQ_NUM_AXES_OPT      Number of Axes       PRO_VALUE_TYPE_INT        Note-8
PRO_E_NCSEQ_CSYS                Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-9
PRO_E_RETR_SURF                 Retract Surface      Compound                  Note-10
PRO_E_MFG_TOOL_REF_COMPOUND     Tool                 Compound                  Note-11
PRO_E_MFG_TOOL_ADAPTER_NAME     Tool Attachment      PRO_VALUE_TYPE_WSTRING    Note-12
PRO_E_MFG_PARAM_SITE_NAME       Site Name            PRO_VALUE_TYPE_WSTRING    Note-13
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-14
PRO_E_MFG_CUSTOM_CYCLE_NAME     Custom Cycle Name    PRO_VALUE_TYPE_WSTRING    Note-15
PRO_E_HOLESETS                  Holeset Array        Array                     Note-16
PRO_E_CHECK_SURF_COLL           Check Surfaces       PRO_VALUE_TYPE_SELECTION  Note-17
PRO_E_TOOL_MTN_ARR              Tool Motion Array    Array                     Note-18
PRO_E_TOOL_MTN                  Tool Motion          Compound                  Note-19
PRO_E_MFG_START_PNT             Start Point          PRO_VALUE_TYPE_SELECTION  Note-20
PRO_E_MFG_END_PNT               End Point            PRO_VALUE_TYPE_SELECTION  Note-21
PRO_E_MFG_PREREQUISITE_ARR      Prerequisite Array   Array                     Note-22
PRO_E_MFG_PROCESS_REF           Process Reference    PRO_VALUE_TYPE_SELECTION  Note-23
PRO_E_MFG_FEAT_VIEW_NAME        View Name            PRO_VALUE_TYPE_WSTRING    Note-24
PRO_E_MFG_SIMP_REP_NAME         Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-25
PRO_E_MFG_TIME_ESTIMATE         Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-26
PRO_E_MFG_COST_ESTIMATE         Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-27
PRO_E_MFG_TIME_ACTUAL           Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-28
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-29
PRO_E_MFG_SUB_SPINDLE_OPT       Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-30

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_DRILL
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_HOLEMAKING
          Mandatory.

Note-4  : Type of holemaking sequence.
          Values defined by ProHolemakingType.
          Mandatory.

Note-5  : Holemaking mode - machining with rotating part or rotating tool.
          Values defined by ProDrillModeOption.
          Mandatory for drilling on mill-turn work center.

Note-6  : Operation feature selection.
          Mandatory.

Note-7  : Holemaking cycle type.
          Values defined by ProHmCycleType.
          Mandatory for drilling, tapping, counterboring, countersinking.
          For countersinking should be set to PRO_HM_CYCLE_TYPE_STANDARD. 
          Ignored for other types of holemaking.
         
Note-8  : 3 or 5. Can be set to 5 only if work center allows 5-axis 
          machining.

Note-9  : Coordinate system datum feature. To be used as a sequence coordinate 
          system.
          Mandatory.

Note-10 : Retract compound definition.
          Please see ProMfgElemRetract.h.
          Mandatory when PRO_E_DRILL_MODE set to PRO_DRILL_HOLE_ON_MILL.
          Ignored when PRO_E_DRILL_MODE set to PRO_DRILL_HOLE_ON_LATHE.

Note-11 : Tool reference compound definition.
          Please see ProMfgElemToolRef.h.
          Mandatory.

Note-12 : Tool adapter model name.
          Optional.

Note-13 : Name of site with default values for manufacturing parameters.
          Name is going to be ignored if site doesn't exist in the mfg model.
          Optional.
         
Note-14 : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-15 : Name of custom cycle which will be used to define machining strategy.
          A custom cycle with speified name must exists in mfg model.
          Mandatory for custom cycle holemaking (when PRO_E_HOLEMAKING_TYPE is 
          not set to PRO_HOLE_MK_CUSTOM). Ignored for other types of 
          holemaking.

Note-16 : Array of holesets - specification of holes to machine.
          Please see ProMfgElemHoleset.h
          Mandatory.

Note-17 : Check surfaces compound definition.
          Please see ProMfgElemCheckSurf.h.
          Optional.

Note-18 : Array of tool motions.
          Optional.

Note-19 : Tool motion compound specification. Optional.

          Applicable tool motion types:
            PRO_TM_TYPE_AUTOMATIC_CUT        (please see ProMfgElemToolMtnAutoCut.h)
            PRO_TM_TYPE_GOTO_POINT           (please see ProMfgElemToolMtnGotoPnt.h)
            PRO_TM_TYPE_GO_DELTA             (please see ProMfgElemToolMtnGoDelta.h)
            PRO_TM_TYPE_GOHOME               (please see ProMfgElemToolMtnGoHome.h)
            PRO_TM_TYPE_GO_RETRACT           (please see ProMfgElemToolMtnGoRetr.h)
            PRO_TM_TYPE_CONNECT              (please see ProMfgElemToolMtnConnect.h)
            PRO_TM_TYPE_CL_COMMAND           (please see ProMfgElemToolMtnClCmd.h)

Note-20 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-21 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-22 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-23 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-24 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-25 : Simplified representation name. Allows to associate specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-26 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-27 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-28 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-29 : Sequence comments.

Note-30 : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATHOLEMAKING_H */
