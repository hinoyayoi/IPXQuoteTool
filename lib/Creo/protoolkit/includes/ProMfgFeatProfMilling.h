#ifndef PROMFGFEATPROFMILL_H
#define PROMFGFEATPROFMILL_H
/*
   Creo Parametric TOOLKIT declarations related to mfg profile milling sequence.
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
    |-- PRO_E_MACH_SURFS
    |
    |-- PRO_E_MFG_SURF_SIDE_COMPOUND
    |
    |-- PRO_E_MFG_4_AXIS_PLANE
    |
    |-- PRO_E_SCALLOP_SURF_COLL
    |      |
    |      |-- PRO_E_STD_SURF_COLLECTION_APPL
    |
    |-- PRO_E_CHECK_SURF_COLL
    |
    |-- PRO_E_MFG_CMP_APPROACH_EXIT
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
PRO_E_MFG_SEQ_NUM_AXES_OPT      Number of Axes       PRO_VALUE_TYPE_INT        Note-5
PRO_E_NCSEQ_CSYS                Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_RETR_SURF                 Retract Surface      Compound                  Note-7
PRO_E_MFG_TOOL_REF_COMPOUND     Tool                 Compound                  Note-8
PRO_E_MFG_TOOL_ADAPTER_NAME     Tool Attachment      PRO_VALUE_TYPE_WSTRING    Note-9
PRO_E_MFG_PARAM_SITE_NAME       Site Name            PRO_VALUE_TYPE_WSTRING    Note-10
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-11
PRO_E_MACH_SURFS                Machining Surfaces   Compound                  Note-12
PRO_E_MFG_SURF_SIDE_COMPOUND    Surface Side         Compound                  Note-13
PRO_E_MFG_4_AXIS_PLANE          Tool Orient Plane    PRO_VALUE_TYPE_SELECTION  Note-14
PRO_E_SCALLOP_SURF_COLL         Scallop Surfaces     Compound                  Note-15
PRO_E_STD_SURF_COLLECTION_APPL  Surface Collection   Surface Collection        Note-16
PRO_E_CHECK_SURF_COLL           Check Surfaces       PRO_VALUE_TYPE_SELECTION  Note-17
PRO_E_MFG_CMP_APPROACH_EXIT     Approach and Exit    Compound                  Note-18
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

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_MILL
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_PROF_SURF_MILL
          Mandatory.

Note-4  : Operation feature selection.
          Mandatory.

Note-5  : Number of controlled axes (3, 4, 5).
          Use 4 for machining with tool axis parallel to the plane
          specified in PRO_E_MFG_4_AXIS_PLANE (applicable if work center 
          allows 4-axis, or 5-axis machining).
          Use 5 for 5-axis machining (applicable if work center allows 
          5-axis machining.
          Optional. 3 will be used if the element doesn't exist.

Note-6  : Coordinate system datum. To be used as a sequence coordinate system.
          Mandatory.

Note-7  : Retract compound definition.
          Please see ProMfgElemRetract.h.
          Mandatory.

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

Note-12 : Machining surfaces compound definition.
          Please see ProMfgElemMachSurf.h.
          Mandatory.

Note-13 : Surfaces side compound definition.
          Please see ProMfgElemSurfSide.h.
          Optional.

Note-14 : Selection of datum plane or planar surface.  
          Mandatory for 4-axis machining (PRO_E_MFG_SEQ_NUM_AXES_OPT set to 4). 
          Ignored for 3-axis and 5-axis machining.

Note-15 : Scallop surfaces compound definition.
          Optional.

Note-16 : Scallop surfaces collection.
          Optional.

Note-17 : Check surfaces compound definition.
          Please see ProMfgElemCheckSurf.h.
          Optional.
         
Note-18 : Approach and exit compound definition.
          Please see ProMfgElemApproachExit.h.
          Optional.

Note-19 : Array of tool motions.
          Optional.

Note-20 : Tool motion compound specification. Optional.

          Applicable tool motion types:
	    PRO_TM_TYPE_PROFILE_MILL_CUT     (please see ProMfgElemToolMtnProfileMillCut.h)
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
            
          Applicable tool motion types for 4-axis and 5-axis machining:
            PRO_TM_TYPE_ALONG_AXIS_APPROACH  (please see ProMfgElemToolMtnAlongAxisAppr.h)
            PRO_TM_TYPE_ALONG_AXIS_EXIT      (please see ProMfgElemToolMtnAlongAxisExit.h)     

          Follow Cut motion must be placed just after PRO_TM_TYPE_PROFILE_MILL_CUT
          motion or another Follow Cut motion.
          
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

Note-25 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-26 : Simplified representation name. Allows to associate specific 
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

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATPROFMILL_H */
