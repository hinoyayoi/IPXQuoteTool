#ifndef PROMFGFEAT2XCURVETRAJ_H
#define PROMFGFEAT2XCURVETRAJ_H
/*
   Creo Parametric TOOLKIT declarations related to mfg 2-axis curve trajectory sequence.
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
    |-- PRO_E_MFG_LOOP_SURF_REF
    |
    |-- PRO_E_MFG_TRAJ_CRV
    |      |
    |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
    |
    |-- PRO_E_FF_TRAJ_FLIP_OPT
    |
    |-- PRO_E_MFG_OFFSET
    |      |
    |      |-- PRO_E_MFG_OFFSET_CUT
    |      |
    |      |-- PRO_E_MFG_MAT_TO_RMV
    |      |
    |      |-- PRO_E_MFG_DRV_SRF_DIR
    |
    |-- PRO_E_MFG_START_HEIGHT
    |
    |-- PRO_E_MFG_HEIGHT
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
PRO_E_MFG_OPER_REF              Operation            PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_NCSEQ_CSYS                Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-5
PRO_E_RETR_SURF                 Retract Surface      Compound                  Note-6
PRO_E_MFG_TOOL_REF_COMPOUND     Tool                 Compound                  Note-7
PRO_E_MFG_TOOL_ADAPTER_NAME     Tool Attachment      PRO_VALUE_TYPE_WSTRING    Note-8
PRO_E_MFG_PARAM_SITE_NAME       Site Name            PRO_VALUE_TYPE_WSTRING    Note-9
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-10
PRO_E_MFG_TRAJ_CRV              Curve Compound       Compound                  Note-11
PRO_E_STD_CURVE_COLLECTION_APPL Curve Collection     Curve Collection          Note-12
PRO_E_MFG_OFFSET                Offset Compound      Compound                  Note-13
PRO_E_MFG_OFFSET_CUT            Offset Cut Type      PRO_VALUE_TYPE_INT        Note-14
PRO_E_MFG_MAT_TO_RMV            Material To Remove   PRO_VALUE_TYPE_INT        Note-15
PRO_E_MFG_DRV_SRF_DIR   Flip Drive Surface Direction PRO_VALUE_TYPE_INT        Note-16
PRO_E_MFG_START_HEIGHT          Start Height Ref     PRO_VALUE_TYPE_SELECTION  Note-17
PRO_E_MFG_HEIGHT                Height Ref           PRO_VALUE_TYPE_SELECTION  Note-18
PRO_E_TOOL_MTN_ARR              Tool Motion Array    Array                     Note-19
PRO_E_TOOL_MTN                  Tool Motion          Compound                  Note-20
PRO_E_MFG_START_PNT             Start Point          PRO_VALUE_TYPE_SELECTION  Note-21
PRO_E_MFG_END_PNT               End Point            PRO_VALUE_TYPE_SELECTION  Note-22
PRO_E_MFG_PREREQUISITE_ARR      Prerequisite Array   Array                     Note-23
PRO_E_MFG_PROCESS_REF           Process Reference    PRO_VALUE_TYPE_SELECTION  Note-24
PRO_E_MFG_FEAT_VIEW_NAME        View Name            PRO_VALUE_TYPE_WSTRING    Note-25
PRO_E_MFG_SIMP_REP_NAME         Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-26
PRO_E_MFG_TIME_ESTIMATE         Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-27
PRO_E_MFG_COST_ESTIMATE         Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-28
PRO_E_MFG_TIME_ACTUAL           Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-29
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-30
PRO_E_MFG_SUB_SPINDLE_OPT       Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-31
PRO_E_MFG_LOOP_SURF_REF         Loop Surfaces        PRO_VALUE_TYPE_SELECTION  Note-32
PRO_E_FF_TRAJ_FLIP_OPT          Flip Direction       PRO_VALUE_TYPE_INT        Note-33

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_MILL
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_FF_TRAJ_MILL
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

Note-11 : Machining curves compound definition.
          Mandatory.

Note-12 : Curve collection.
          Mandatory.

Note-13 : Offset compound definition.
          Optional. 

Note-14 : Offset cut.
          PRO_B_TRUE - tool offset will be applied.
          PRO_B_FALSE - tool offset will not be applied.
          Optional.

Note-15 : Material side.
          PRO_MFG_DIR_SAME - default side will be used.
          PRO_MFG_DIR_OPPOSITE - the default side will be flipped.
          Optional.

Note-16 : Flip Drive Surface Direction.
          PRO_B_FALSE - default direction on the drive surface will be used.
	  PRO_B_TRUE - opposite direction on the drive surface will be used .
          Optional. 

Note-17 : Selection of the plane where machining will begin.
          Optional.

Note-18 : Single selection of the plane for tool tip to follow.
          Optional.

Note-19 : Array of tool motions.
          Optional.

Note-20 : Tool motion compound specification.
          Optional.

Note-21 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-22 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-23 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-24 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-25 : View name. Allows to associated specific view with a machining step.
          Used only in special process application.
          Optional.

Note-26 : Simplified representation name. Allows to associated specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-27 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-28 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-29 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-30 : Sequence comments.

Note-31 : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

Note-32 : Selection of surface with loops to machine.
          Optional.

Note-33 : Flip Machining Direction.
          PRO_B_FALSE - default direction on the curve will be used.
	  PRO_B_TRUE  - opposite direction on the curve will be used .
          Optional. 

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEAT2XCURVETRAJ_H */
