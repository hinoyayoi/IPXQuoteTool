#ifndef PROMFGFEATTURNING_H
#define PROMFGFEATTURNING_H
/*
   Creo Parametric TOOLKIT declarations related to mfg turning sequences:

      - area turning;
      - profile turning;
      - groove turning.
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
    |-- PRO_E_MFG_SUB_SPINDLE_OPT
    |
    |-- PRO_E_MFG_TOOL_REF_COMPOUND
    |
    |-- PRO_E_MFG_PARAM_SITE_NAME
    |
    |-- PRO_E_MFG_PARAM_ARR
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
PRO_E_MFG_TOOL_REF_COMPOUND     Tool                 Compound                  Note-6
PRO_E_MFG_PARAM_SITE_NAME       Site Name            PRO_VALUE_TYPE_WSTRING    Note-7
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-8
PRO_E_TOOL_MTN_ARR              Tool Motion Array    Array                     Note-9
PRO_E_TOOL_MTN                  Tool Motion          Compound                  Note-10
PRO_E_MFG_START_PNT             Start Point          PRO_VALUE_TYPE_SELECTION  Note-11
PRO_E_MFG_END_PNT               End Point            PRO_VALUE_TYPE_SELECTION  Note-12
PRO_E_MFG_PREREQUISITE_ARR      Prerequisite Array   Array                     Note-13
PRO_E_MFG_PROCESS_REF           Process Reference    PRO_VALUE_TYPE_SELECTION  Note-14
PRO_E_MFG_FEAT_VIEW_NAME        View Name            PRO_VALUE_TYPE_WSTRING    Note-15
PRO_E_MFG_SIMP_REP_NAME         Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-16
PRO_E_MFG_TIME_ESTIMATE         Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-17
PRO_E_MFG_COST_ESTIMATE         Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-18
PRO_E_MFG_TIME_ACTUAL           Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-19
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-20
PRO_E_MFG_SUB_SPINDLE_OPT       Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-21

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_TURN
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_AREA_TURN   - for an area turning sequence,
          PRO_NCSEQ_GROOVE_TURN - for a groove turning sequence,
          PRO_NCSEQ_PROF_TURN   - for a profile turning sequence,
          Mandatory.

Note-4  : Operation feature selection.
          Mandatory.

Note-5  : Coordinate system datum feature. To be used as a sequence coordinate 
          system.
          Mandatory.

Note-6  : Tool reference compound definition.
          Please see ProMfgElemToolRef.h.
          Mandatory.

Note-7  : Name of site with default values for manufacturing parameters.
          Name is going to be ignored if site doesn't exist in the mfg model.
          Optional.
         
Note-8  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-9  : Array of tool motions.
          Optional.

Note-10 : Tool motion compound specification. Optional.

          Applicable tool motion types:
          
            PRO_TM_TYPE_AREA_TURNING         (for an area turning sequence, please see ProMfgElemToolMtnAreaTurn.h)
            PRO_TM_TYPE_GROOVE_TURNING       (for a groove turning sequence, please see ProMfgElemToolMtnGrooveTurn.h)
            PRO_TM_TYPE_PROF_TURNING         (for a profile turning sequence, please see ProMfgElemToolMtnProfTurn.h)
            PRO_TM_TYPE_FOLLOW_CUT           (please see ProMfgElemToolMtnFollowCut.h)
            PRO_TM_TYPE_FOLLOW_CURVE         (please see ProMfgElemToolMtnFollowCrv.h)
            PRO_TM_TYPE_GOTO_POINT           (please see ProMfgElemToolMtnGotoPnt.h)
            PRO_TM_TYPE_GO_DELTA             (please see ProMfgElemToolMtnGoDelta.h)
            PRO_TM_TYPE_GOHOME               (please see ProMfgElemToolMtnGoHome.h)
            PRO_TM_TYPE_TANGENT_APPROACH     (please see ProMfgElemToolMtnTanAppr.h)
            PRO_TM_TYPE_TANGENT_EXIT         (please see ProMfgElemToolMtnTanExit.h)
            PRO_TM_TYPE_NORMAL_APPROACH      (please see ProMfgElemToolMtnNormAppr.h)
            PRO_TM_TYPE_NORMAL_EXIT          (please see ProMfgElemToolMtnNormExit.h)
            PRO_TM_TYPE_LEAD_IN              (please see ProMfgElemToolMtnLeadIn.h)
            PRO_TM_TYPE_LEAD_OUT             (please see ProMfgElemToolMtnLeadOut.h)
            PRO_TM_TYPE_RAMP_APPROACH        (please see ProMfgElemToolMtnRampAppr.h)
            PRO_TM_TYPE_RAMP_EXIT            (please see ProMfgElemToolMtnRampExit.h)
            PRO_TM_TYPE_CONNECT              (please see ProMfgElemToolMtnConnect.h)
            PRO_TM_TYPE_CL_COMMAND           (please see ProMfgElemToolMtnClCmd.h)
          
          Follow Cut motion must be placed just after Area/Groove/Profile Turning motions
          or another Follow Cut motion.
          
Note-11 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-12 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-13 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-14 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-15 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-16 : Simplified representation name. Allows to associate specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-17 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-18 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-19 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-20 : Sequence comments.

Note-21 : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATTURNING_H */
