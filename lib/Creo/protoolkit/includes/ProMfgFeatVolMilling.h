#ifndef PROMFGFEATVOLMILL_H
#define PROMFGFEATVOLMILL_H
/*
   Creo Parametric TOOLKIT declarations related to mfg volume milling sequence.
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
    |-- PRO_E_MFG_WIN_VOL_REF_COMPOUND
    |      |
    |      |-- PRO_E_MFG_WIN_VOL_REF
    |      |
    |      |-- PRO_E_MFG_CMP_CLOSED_LOOPS
    |      |      |
    |      |      |-- PRO_E_MFG_CLOSED_LOOP_ARR
    |      |             |
    |      |             |-- PRO_E_MFG_CLOSED_LOOP_REF_ITEM
    |      |                    |
    |      |                    |-- PRO_E_MFG_CLOSED_LOOP_ID
    |      |                    |
    |      |                    |-- PRO_E_STD_CURVE_COLLECTION_APPL
    |      |
    |      |-- PRO_E_MFG_WIN_VOL_EXCL_SURF_COMP
    |      |      |
    |      |      |-- PRO_E_STD_SURF_COLLECTION_APPL
    |      |
    |      |-- PRO_E_MFG_APPR_WALLS_SURF_COMP
    |      |      |
    |      |      |-- PRO_E_STD_SURF_COLLECTION_APPL
    |      |
    |      |-- PRO_E_MFG_APPR_WALLS_CHAIN_COMP
    |      |      |
    |      |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
    |      |
    |      |-- PRO_E_MFG_MILL_VOL_TOP_SURF_REF
    |
    |-- PRO_E_SCALLOP_SURF_COLL
    |      |
    |      |-- PRO_E_STD_SURF_COLLECTION_APPL
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
PRO_E_FEATURE_TYPE               Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME           Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_NCSEQ_TYPE                 Sequence Type        PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_OPER_REF               Operation            PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_NCSEQ_CSYS                 Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-5
PRO_E_RETR_SURF                  Retract Surface      Compound                  Note-6
PRO_E_MFG_SUB_SPINDLE_OPT        Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-7
PRO_E_MFG_TOOL_REF_COMPOUND      Tool                 Compound                  Note-8
PRO_E_MFG_TOOL_ADAPTER_NAME      Tool Attachment      PRO_VALUE_TYPE_WSTRING    Note-9
PRO_E_MFG_PARAM_SITE_NAME        Site Name            PRO_VALUE_TYPE_WSTRING    Note-10
PRO_E_MFG_PARAM_ARR              Mfg Parameter Array  Array                     Note-11
PRO_E_MFG_WIN_VOL_REF_COMPOUND   Volume Reference     Compound                  Note-12
PRO_E_MFG_WIN_VOL_REF            Window Volume        PRO_VALUE_TYPE_SELECTION  Note-13
PRO_E_MFG_CMP_CLOSED_LOOPS       Closed Loops         Compound                  Note-14
PRO_E_MFG_CLOSED_LOOP_ARR        Closed Loops Array   Array                     Note-15
PRO_E_MFG_CLOSED_LOOP_REF_ITEM   Closed Loop          Compound                  Note-16
PRO_E_MFG_CLOSED_LOOP_ID         Closed Loop Id       PRO_VALUE_TYPE_INT        Note-17
PRO_E_STD_CURVE_COLLECTION_APPL  Closed Loop Chain    Chain Collection          Note-18
PRO_E_MFG_WIN_VOL_EXCL_SURF_COMP Excluded Compound    Compound                  Note-19
PRO_E_STD_SURF_COLLECTION_APPL   Excluded Surfaces    Surface Collection        Note-20
PRO_E_MFG_APPR_WALLS_SURF_COMP   Approach Walls       Compound                  Note-21
PRO_E_STD_SURF_COLLECTION_APPL   Walls Surfaces       Surface Collection        Note-22
PRO_E_MFG_APPR_WALLS_CHAIN_COMP  Approach Walls Chain Compound                  Note-23
PRO_E_STD_CURVE_COLLECTION_APPL  Wall Chains          Chain Collection          Note-24
PRO_E_MFG_MILL_VOL_TOP_SURF_REF  Volume Top           PRO_VALUE_TYPE_SELECTION  Note-25
PRO_E_SCALLOP_SURF_COLL          Scallop Surfaces     Compound                  Note-26
PRO_E_STD_SURF_COLLECTION_APPL   Surface Collection   Surface Collection        Note-27
PRO_E_CHECK_SURF_COLL            Check Surfaces       PRO_VALUE_TYPE_SELECTION  Note-28
PRO_E_TOOL_MTN_ARR               Tool Motion Array    Array                     Note-30
PRO_E_TOOL_MTN                   Tool Motion          Compound                  Note-31
PRO_E_MFG_START_PNT              Start Point          PRO_VALUE_TYPE_SELECTION  Note-32
PRO_E_MFG_END_PNT                End Point            PRO_VALUE_TYPE_SELECTION  Note-33
PRO_E_MFG_PREREQUISITE_ARR       Prerequisite Array   Array                     Note-34
PRO_E_MFG_PROCESS_REF            Process Reference    PRO_VALUE_TYPE_SELECTION  Note-35
PRO_E_MFG_FEAT_VIEW_NAME         View Name            PRO_VALUE_TYPE_WSTRING    Note-36
PRO_E_MFG_SIMP_REP_NAME          Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-37
PRO_E_MFG_TIME_ESTIMATE          Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-38
PRO_E_MFG_COST_ESTIMATE          Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-39
PRO_E_MFG_TIME_ACTUAL            Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-40
PRO_E_MFG_COMMENTS               Comments             PRO_VALUE_TYPE_WSTRING    Note-41

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_MILL
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_VOL_MILL
          Mandatory.

Note-4  : Operation feature selection.
          Mandatory.

Note-5  : Coordinate system datum. To be used as a sequence coordinate system.
          Mandatory.

Note-6  : Retract compound definition.
          Please see ProMfgElemRetract.h.
          Mandatory.

Note-7  : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

Note-8  : Tool reference compound definition.
          Please see ProMfgElemToolRef.h.
          Mandatory.

Note-9  : Tool adapter model name.
          Optional.

Note-10 : Name of site with default values for manufacturing parameters.
          Name is going to be ignored if site doesn't exist in the mfg
          model.
          Optional.

Note-11 : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-12 : Machining reference compound specification.
          Mandatory.

Note-13 : Selection of mill window feature, or mill volume feature.
          Mandatory. 

Note-14 : Closed loop compound specification.
          Optional.

Note-15 : Array of closed loop specifications.
          Optional.

Note-16 : Closed loop specification.
          Optional.

Note-17 : Closed loop id.
          Internal use only. Should not be added or modified.

Note-18 : Excluded surfaces compound specification.
          Optional.

Note-19 : Excluded surfaces compound specification.
          Optional.

Note-20 : Surface collection.
          Optional.

Note-21 : Approach walls surfaces compound specification.
          Applicable only if mill volume is selected as a machining
          reference (element PRO_E_MFG_WIN_VOL_REF).
          Optional.

Note-22 : Surface collection.
          Optional.

Note-23 : Approach walls chain compound specification.
          Applicable only if mill window is selected as a machining
          reference (element PRO_E_MFG_WIN_VOL_REF).
          Optional.

Note-24 : Chain collection.
          Optional.

Note-25 : Selection of top surface.
          Applicable only if mill volume is selected as a machining
          reference (element PRO_E_MFG_WIN_VOL_REF).
          Optional.

Note-26 : Scallop surfaces compound definition.
          Optional.

Note-27 : Scallop surfaces collection.
          Optional.

Note-28 : Check surfaces compound definition.
          Please see ProMfgElemCheckSurf.h.
          Optional.
         
Note-29 : Array of tool motions.
          Optional.

Note-30 : Tool motion compound specification. Optional.

          Applicable tool motion types:
	    PRO_TM_TYPE_VOLUME_MILLING       (please see ProMfgElemToolMtnVolMillCut.h)
            PRO_TM_TYPE_FOLLOW_CUT           (please see ProMfgElemToolMtnFollowCut.h)
            PRO_TM_TYPE_FOLLOW_CURVE         (please see ProMfgElemToolMtnFollowCrv.h)
            PRO_TM_TYPE_GOTO_POINT           (please see ProMfgElemToolMtnGotoPnt.h)
            PRO_TM_TYPE_GO_DELTA             (please see ProMfgElemToolMtnGoDelta.h)
            PRO_TM_TYPE_GOHOME               (please see ProMfgElemToolMtnGoHome.h)
            PRO_TM_TYPE_PLUNGE               (please see ProMfgElemToolMtnPlunge.h)
            PRO_TM_TYPE_GO_RETRACT           (please see ProMfgElemToolMtnGoRetr.h)
            PRO_TM_TYPE_TANGENT_APPROACH     (please see ProMfgElemToolMtnTanAppr.h)
            PRO_TM_TYPE_TANGENT_EXIT         (please see ProMfgElemToolMtnTanExit.h)
            PRO_TM_TYPE_NORMAL_APPROACH      (please see ProMfgElemToolMtnNormAppr.h)
            PRO_TM_TYPE_NORMAL_EXIT          (please see ProMfgElemToolMtnNormExit.h)
            PRO_TM_TYPE_LEAD_IN              (please see ProMfgElemToolMtnLeadIn.h)
            PRO_TM_TYPE_LEAD_OUT             (please see ProMfgElemToolMtnLeadOut.h)
            PRO_TM_TYPE_HELICAL_APPROACH     (please see ProMfgElemToolMtnHelAppr.h)
            PRO_TM_TYPE_HELICAL_EXIT         (please see ProMfgElemToolMtnHelExit.h)
            PRO_TM_TYPE_CL_COMMAND           (please see ProMfgElemToolMtnFollowCrv.h)
            
          Follow Cut motion must be placed just after PRO_TM_TYPE_VOLUME_MILLING motion or 
          another Follow Cut motion.
          
Note-31 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-32 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-33 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-34 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-35 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-36 : Simplified representation name. Allows to associate specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-37 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-38 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-39 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-40 : Sequence comments.


=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATVOLMILL_H */
