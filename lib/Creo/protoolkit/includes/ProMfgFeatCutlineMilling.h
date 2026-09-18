#ifndef PROMFGFEATCUTLINE_H
#define PROMFGFEATCUTLINE_H
/*
   Creo Parametric TOOLKIT declarations related to mfg cutline milling sequence.
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
    |-- PRO_E_CUTLINE_TP_OPTIONS
    |      |
    |      |-- PRO_E_CUTLINE_TP_TOOL_CENTER_OPT
    |
    |-- PRO_E_CUTLINE_CUT_DEFINITION
    |      |
    |      |-- PRO_E_CUTLINE_ALT_SRFS
    |      |      |
    |      |      |-- PRO_E_STD_SURF_COLLECTION_APPL
    |      |      |
    |      |      |-- PRO_E_CUTLINE_USE_ALT_SRFS
    |      |
    |      |-- PRO_E_CUTLINE_AUTO_OUTER_OPT
    |      |
    |      |-- PRO_E_CUTLINE_INNER_POINT
    |      |
    |      |-- PRO_E_CUTLINE_INNER_FIRST_OPT
    |      |
    |      |-- PRO_E_CUTLINE_REF_ARR
    |      |      |
    |      |      |-- PRO_E_CUTLINE_REF_ITEM
    |      |             |
    |      |             |-- PRO_E_CUTLINE_ID
    |      |             |
    |      |             |-- PRO_E_STD_CURVE_COLLECTION_APPL
    |      |             |
    |      |             |-- PRO_E_NCD_CURVE_POINT
    |      |             |      |
    |      |             |      |-- PRO_E_NCD_CURVE_POINT_REF
    |      |             |      |
    |      |             |      |-- PRO_E_NCD_CURVE_POINT_OFFSET_TYPE
    |      |             |      |
    |      |             |      |-- PRO_E_NCD_CURVE_POINT_OFFSET
    |      |             |
    |      |             |-- PRO_E_CUTLINE_PROJ_PLN
    |      |
    |      |-- PRO_E_CUTLINE_SYNC_ARR
    |             |
    |             |-- PRO_E_CUTLINE_SYNC_ITEM
    |                     |
    |                     |-- PRO_E_CUTLINE_SYNC_ID
    |                     |
    |                     |-- PRO_E_CUTLINE_SYNC_NAME
    |                     |
    |                     |-- PRO_E_CUTLINE_SYNC_TYPE
    |                     |
    |                     |-- PRO_E_CUTLINE_SYNC_POINT_ARR
    |                     |      |
    |                     |      |-- PRO_E_CUTLINE_SYNC_POINT
    |                     |             |
    |                     |             |-- PRO_E_CUTLINE_SYNC_POINT_REF_ID
    |                     |             |
    |                     |             |-- PRO_E_CUTLINE_SYNC_POINT_RATIO
    |                     |
    |                     |-- PRO_E_STD_CURVE_COLLECTION_APPL
    |
    |-- PRO_E_MFG_SURF_SIDE_COMPOUND
    |
    |-- PRO_E_MFG_4_AXIS_PLANE
    |
    |-- PRO_E_SCALLOP_SURF_COLL
    |
    |-- PRO_E_CHECK_SURF_COLL
    |
    |-- PRO_E_MFG_AXIS_DEF_COMP
    |      |
    |      |-- PRO_E_MFG_AXIS_DEF_TYPE
    |      |
    |      |-- PRO_E_MFG_AXIS_DEF_PIVOT_REF
    |      |
    |      |-- PRO_E_MFG_AXIS_DEF_NORM_SRF
    |      |
    |      |-- PRO_E_MFG_AXIS_DEF_LOCATION_ARR
    |      |      |
    |      |      |-- PRO_E_MFG_AXIS_DEF_LOCATION
    |      |             |
    |      |             |-- PRO_E_MFG_AXIS_DEF_ORIGIN_REF
    |      |             |
    |      |             |-- PRO_E_MFG_AXIS_DEF_ORIENT_COMP
    |      |             |      |
    |      |             |      |-- PRO_E_MFG_AXIS_DEF_ORIENT_REF
    |      |             |      |
    |      |             |      |-- PRO_E_MFG_AXES_DEF_ANGLE_X
    |      |             |      |
    |      |             |      |-- PRO_E_MFG_AXES_DEF_ANGLE_Y
    |      |             |
    |      |             |-- PRO_E_MFG_AXIS_DEF_LOC_FLIP_OPT
    |      |
    |      |-- PRO_E_MFG_AXIS_DEF_CURVE_COMP
    |      |      |
    |      |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
    |      |      |
    |      |      |-- PRO_E_MFG_AXIS_DEF_SYNC_ARR
    |      |             |
    |      |             |-- PRO_E_MFG_AXIS_DEF_SYNC_COMP
    |      |                    |
    |      |                    |-- PRO_E_MFG_AXIS_DEF_SYNC_PNT_1
    |      |                    |
    |      |                    |-- PRO_E_MFG_AXIS_DEF_SYNC_PNT_2
    |      |                    |
    |      |                    |-- PRO_E_MFG_AXIS_DEF_SYNC_FLIP_OPT
    |      |
    |      |-- PRO_E_MFG_AXIS_DEF_FLIP_OPT
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
Element Id                        Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME            Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_NCSEQ_TYPE                  Sequence Type        PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_OPER_REF                Operation            PRO_VALUE_TYPE_SELECTION  Note-4
PRO_E_MFG_SEQ_NUM_AXES_OPT        Number of Axes       PRO_VALUE_TYPE_INT        Note-5
PRO_E_NCSEQ_CSYS                  Sequence Csys        PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_RETR_SURF                   Retract Surface      Compound                  Note-7
PRO_E_MFG_TOOL_REF_COMPOUND       Tool                 Compound                  Note-8
PRO_E_MFG_TOOL_ADAPTER_NAME       Tool Attachment      PRO_VALUE_TYPE_WSTRING    Note-9
PRO_E_MFG_PARAM_SITE_NAME         Site Name            PRO_VALUE_TYPE_WSTRING    Note-10
PRO_E_MFG_PARAM_ARR               Mfg Parameter Array  Array                     Note-11
PRO_E_MACH_SURFS                  Machining Surfaces   Compound                  Note-12
PRO_E_CUTLINE_TP_OPTIONS          Tool Path Opts       Compound                  Note-13
PRO_E_MFG_SURF_SIDE_COMPOUND      Surface Side         Compound                  Note-14
PRO_E_CUTLINE_TP_TOOL_CENTER_OPT  Tool Center Curve    PRO_VALUE_TYPE_INT        Note-15
PRO_E_CUTLINE_CUT_DEFINITION      Cut Definition       Compound                  Note-16
PRO_E_CUTLINE_REF_ARR             Reference Arr        Array                     Note-17
PRO_E_CUTLINE_REF_ITEM            Reference Item       Compound                  Note-18
PRO_E_CUTLINE_ID                  Cutline Id           PRO_VALUE_TYPE_INT        Note-19
PRO_E_STD_CURVE_COLLECTION_APPL   Chain                Chain Collection          Note-20
PRO_E_NCD_CURVE_POINT             Curve Point          Compound                  Note-21
PRO_E_NCD_CURVE_POINT_REF         Curve Point Ref      PRO_VALUE_TYPE_SELECTION  Note-22
PRO_E_NCD_CURVE_POINT_OFFSET_TYPE Point Offset Type    PRO_VALUE_TYPE_INT        Note-23
PRO_E_NCD_CURVE_POINT_OFFSET      Curve Point Offset   PRO_VALUE_TYPE_DOUBLE     Note-24
PRO_E_CUTLINE_PROJ_PLN            Project To Plane     PRO_VALUE_TYPE_SELECTION  Note-25
PRO_E_CUTLINE_CUT_STYLE_OPT       Cut Style            PRO_VALUE_TYPE_INT        Note-26
PRO_E_CUTLINE_ALT_SRFS            Alt Srfs             Compound                  Note-27
PRO_E_STD_SURF_COLLECTION_APPL    Alt Srfs Coll        Surface Collection        Note-28
PRO_E_CUTLINE_USE_ALT_SRFS        Use Alt Srfs         PRO_VALUE_TYPE_INT        Note-29
PRO_E_CUTLINE_SYNC_ARR            Sync Array           Array                     Note-30
PRO_E_CUTLINE_SYNC_ITEM           Sync Item            Compound                  Note-31
PRO_E_CUTLINE_SYNC_ID             Sync Id              PRO_VALUE_TYPE_INT        Note-32
PRO_E_CUTLINE_SYNC_NAME           Sync Name            PRO_VALUE_TYPE_WSTRING    Note-33
PRO_E_CUTLINE_SYNC_TYPE           Sync Type            PRO_VALUE_TYPE_INT        Note-34
PRO_E_CUTLINE_SYNC_POINT_ARR      Sync Points          Array                     Note-35
PRO_E_CUTLINE_SYNC_POINT          Sync Point           Compound                  Note-36
PRO_E_CUTLINE_SYNC_POINT_REF_ID   Sync Point Ref Id    PRO_VALUE_TYPE_INT        Note-37
PRO_E_CUTLINE_SYNC_POINT_RATIO    Sync Point Ratio     PRO_VALUE_TYPE_DOUBLE     Note-38
PRO_E_STD_CURVE_COLLECTION_APPL   Sync Ref Chain       Chain Collection          Note-39
PRO_E_MFG_4_AXIS_PLANE            Tool Orient Plane    PRO_VALUE_TYPE_SELECTION  Note-40
PRO_E_SCALLOP_SURF_COLL           Scallop Surfaces     Compound                  Note-41
PRO_E_CHECK_SURF_COLL             Check Surfaces       PRO_VALUE_TYPE_SELECTION  Note-42
PRO_E_MFG_AXIS_DEF_COMP           Axis Definition      Compound                  Note-43
PRO_E_MFG_AXIS_DEF_TYPE           Axis Definition Type PRO_VALUE_TYPE_INT        Note-44
PRO_E_MFG_AXIS_DEF_PIVOT_REF      Pivot Reference      PRO_VALUE_TYPE_SELECTION  Note-45
PRO_E_MFG_AXIS_DEF_NORM_SRF       Normal Surface       Compound                  Note-46
PRO_E_STD_CURVE_COLLECTION_APPL   Surface Collection   Surface Collection        Note-47
PRO_E_MFG_AXIS_DEF_LOCATION_ARR   Location Array       Array                     Note-48
PRO_E_MFG_AXIS_DEF_LOCATION       Location Item        Compound                  Note-49
PRO_E_MFG_AXIS_DEF_ORIGIN_REF     Origin Reference     PRO_VALUE_TYPE_SELECTION  Note-50
PRO_E_MFG_AXIS_DEF_ORIENT_COMP    Orientation          Compound                  Note-51
PRO_E_MFG_AXIS_DEF_ORIENT_REF     Orientation Ref      PRO_VALUE_TYPE_SELECTION  Note-52
PRO_E_MFG_AXES_DEF_ANGLE_X        Lead angle           PRO_VALUE_TYPE_DOUBLE     Note-53
PRO_E_MFG_AXES_DEF_ANGLE_Y        Tilt angle           PRO_VALUE_TYPE_DOUBLE     Note-54
PRO_E_MFG_AXIS_DEF_LOC_FLIP_OPT   Direction Flip       PRO_VALUE_TYPE_INT        Note-55
PRO_E_MFG_AXIS_DEF_CURVE_COMP     Pivot Curve          Compound                  Note-56
PRO_E_STD_CURVE_COLLECTION_APPL   Curve Collection     Chain Collection          Note-57
PRO_E_MFG_AXIS_DEF_SYNC_ARR       Sync Array           Array                     Note-58
PRO_E_MFG_AXIS_DEF_SYNC_COMP      Sync Item            Compound                  Note-59
PRO_E_MFG_AXIS_DEF_SYNC_PNT_1     Sync point 1         PRO_VALUE_TYPE_SELECTION  Note-60
PRO_E_MFG_AXIS_DEF_SYNC_PNT_2     Sync point 2         PRO_VALUE_TYPE_SELECTION  Note-61
PRO_E_MFG_AXIS_DEF_SYNC_FLIP_OPT  Direction Flip       PRO_VALUE_TYPE_INT        Note-62
PRO_E_MFG_AXIS_DEF_FLIP_OPT       Direction Flip       PRO_VALUE_TYPE_INT        Note-63
PRO_E_TOOL_MTN_ARR                Tool Motion Array    Array                     Note-64
PRO_E_TOOL_MTN                    Tool Motion          Compound                  Note-65
PRO_E_MFG_START_PNT               Start Point          PRO_VALUE_TYPE_SELECTION  Note-66
PRO_E_MFG_END_PNT                 End Point            PRO_VALUE_TYPE_SELECTION  Note-67
PRO_E_MFG_PREREQUISITE_ARR        Prerequisite Array   Array                     Note-68
PRO_E_MFG_PROCESS_REF             Process Reference    PRO_VALUE_TYPE_SELECTION  Note-69
PRO_E_MFG_FEAT_VIEW_NAME          View Name            PRO_VALUE_TYPE_WSTRING    Note-70
PRO_E_MFG_SIMP_REP_NAME           Simp Rep Name        PRO_VALUE_TYPE_WSTRING    Note-71
PRO_E_MFG_TIME_ESTIMATE           Time Estimate        PRO_VALUE_TYPE_DOUBLE     Note-72
PRO_E_MFG_COST_ESTIMATE           Cost Estimate        PRO_VALUE_TYPE_DOUBLE     Note-73
PRO_E_MFG_TIME_ACTUAL             Actual Time          PRO_VALUE_TYPE_DOUBLE     Note-74
PRO_E_MFG_COMMENTS                Comments             PRO_VALUE_TYPE_WSTRING    Note-75
PRO_E_CUTLINE_AUTO_OUTER_OPT      Auto Cutline Option  PRO_VALUE_TYPE_INT        Note-76
PRO_E_CUTLINE_INNER_POINT         Inner Point          PRO_VALUE_TYPE_SELECTION  Note-77
PRO_E_CUTLINE_INNER_FIRST_OPT     Inner First Option   PRO_VALUE_TYPE_INT        Note-78
PRO_E_MFG_SUB_SPINDLE_OPT         Sub-spindle Option   PRO_VALUE_TYPE_INT        Note-79

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_MILL
          Mandatory.

Note-2  : Sequence feature name.
          Optional.

Note-3  : PRO_NCSEQ_CUTLINE_MILL
          Mandatory.

Note-4  : Operation feature selection.
          Mandatory.

Note-5  : Number of controlled axes (3 is the only applicable value).
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

Note-13 : Tool path options.
          Optional.

Note-14 : Surface side definition.
          Please see ProMfgElemSurfSide.h.
          Optional.

Note-15 : Tool center curve option.
          Optional.

Note-16 : Cutline array compound definition.
          Mandatory.

Note-17 : Array of cutlines. 
          Mandatory.

Note-18 : Cutline compound definition.
          Mandatory if PRO_E_CUTLINE_AUTO_OUTER_OPT is PRO_B_FALSE.
          Is not used if PRO_E_CUTLINE_AUTO_OUTER_OPT is PRO_B_TRUE.

Note-19 : Cutline id.
          Mandatory.

Note-20 : Cutline chain collection.
          Mandatory.

Note-21 : Cutline start point compound definition.
          Optional.

Note-22 : Cutline start point reference.
          Optional.

Note-23 : Cutline start point offset type.
          Optional.

Note-24 : Cutline start point offset definition.
          Optional.

Note-25 : Cutline project plane definition.
          Optional.

Note-26 : Cutline style definition.
          Optional.

Note-27 : Cutline alternate surface compound definition.
          Optional.

Note-28 : Cutline alternate surface collection.
          Optional.

Note-29 : Cutline alternate surface option definition.
          Optional.

Note-30 : Array of cutline synch lines.
          Optional.

Note-31 : Cutline synch line compound definition.
          Optional.

Note-32 : Cutline synch line id.
          Optional.

Note-33 : Cutline synch line name.
          Optional.

Note-34 : Cutline synch line type.
          PRO_E_CUTLINE_SYNC_TYPE_POINTS - synch between points on cutlines,
          PRO_E_CUTLINE_SYNC_TYPE_REF - synch on reference chains.
          Optional.

Note-35 : Array of cutline synch points. 
          Optional.

Note-36 : Cutline synch point compound definition.
          Optional.

Note-37 : Cutline synch point reference id.
          Optional.

Note-38 : Cutline synch point ratio.
          Optional.

Note-39 : Cutline synch line chain collection.
          Optional.

Note-40 : Reserved for future use.

Note-41 : Scallop surfaces compound definition.
          Optional.

Note-42 : Check surfaces collection.
          Please see ProMfgElemCheckSurf.h.
          Optional.

Note-43 : Axis definition compound element.
          Optional.
          
Note-44 : Values defined by ProAxisDefType:
             PRO_AXIS_DEF_TYPE_UNDEF,
             PRO_AXIS_DEF_BY_PIVOT_REF,
             PRO_AXIS_DEF_BY_LOCATIONS,
             PRO_AXIS_DEF_BY_TWO_CONTOURS,
             PRO_AXIS_DEF_BY_NORM_SURF.
          Please see ProMfgOptions.h
          Mandatory.
          
Note-45 : Single reference selection (point or axis ).
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_PIVOT_REF.
          Ignored in all other cases.
          
Note-46 : Normal Surface compound element.
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_NORM_SURF.
          Ignored in all other cases.
          
Note-47 : Surface collection general compound element.
          Mandatory.

Note-48 : Array of locations. 
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_LOCATIONS.
          Ignored in all other cases.
          
Note-49 : Location compound element.
          Mandatory.
          
Note-50 : Single reference selection (point on a curve or an edge).
          Mandatory.

Note-51 : Orientation compound element.
          Mandatory.
          
Note-52 : Single reference selection (point or axis ).
          Mandatory if PRO_E_MFG_AXES_DEF_ANGLE_X/Y are not defined.
          
Note-53 : Lead angle.
          Range -90 to +90.
          Mandatory if PRO_E_MFG_AXIS_DEF_ORIENT_REF is not defined.
          
Note-54 : Tilt angle.
          Range -90 to +90.
          Mandatory if PRO_E_MFG_AXIS_DEF_ORIENT_REF is not defined.
          
Note-55 : Direction flip at a location.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-56 : Pivot Curve compound element.
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_TWO_CONTOURS.
          Ignored in all other cases.
          
Note-57 : Chain collection general compound element.
          Mandatory.
                
Note-58 : Synchronization Array.
          Optional.
          
Note-59 : Synchronization compound element.
          Optional.
          
Note-60 : Single reference selection (point on the trajectory curve).
          Mandatory.
          
Note-61 : Single reference selection (point on the pivot curve).
          Mandatory.
          
Note-62 : Direction flip.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-63 : Direction flip.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-64 : Array of tool motions.
          Optional.

Note-65 : Tool motion compound specification. Optional.

          Applicable tool motion types:
            PRO_TM_TYPE_CUTLINE_MILLING      (please see ProMfgElemToolMtnCutlineMill.h)
            PRO_TM_TYPE_FOLLOW_CURVE         (please see ProMfgElemToolMtnFollowCrv.h)
            PRO_TM_TYPE_GOTO_POINT           (please see ProMfgElemToolMtnGotoPnt.h)
            PRO_TM_TYPE_GO_DELTA             (please see ProMfgElemToolMtnGoDelta.h)
            PRO_TM_TYPE_GOHOME               (please see ProMfgElemToolMtnGoHome.h)
            PRO_TM_TYPE_PLUNGE               (please see ProMfgElemToolMtnLeadIn.h)
            PRO_TM_TYPE_GO_RETRACT           (please see ProMfgElemToolMtnGoRetr.h)
            PRO_TM_TYPE_TANGENT_APPROACH     (please see ProMfgElemToolMtnTanAppr.h)
            PRO_TM_TYPE_TANGENT_EXIT         (please see ProMfgElemToolMtnTanExit.h)
            PRO_TM_TYPE_NORMAL_APPROACH      (please see ProMfgElemToolMtnNormAppr.h)
            PRO_TM_TYPE_NORMAL_EXIT          (please see ProMfgElemToolMtnNormExit.h)
            PRO_TM_TYPE_LEAD_IN              (please see ProMfgElemToolMtnLeadIn.h)
            PRO_TM_TYPE_LEAD_OUT             (please see ProMfgElemToolMtnLeadOut.h)
            PRO_TM_TYPE_HELICAL_APPROACH     (please see ProMfgElemToolMtnHelAppr.h)
            PRO_TM_TYPE_HELICAL_EXIT         (please see ProMfgElemToolMtnHelExit.h)
            PRO_TM_TYPE_RAMP_APPROACH        (please see ProMfgElemToolMtnRampAppr.h)
            PRO_TM_TYPE_RAMP_EXIT            (please see ProMfgElemToolMtnRampExit.h)
            PRO_TM_TYPE_CONNECT              (please see ProMfgElemToolMtnConnect.h)
            PRO_TM_TYPE_CL_COMMAND           (please see ProMfgElemToolMtnFollowCrv.h)
            
          Applicable tool motion types for 4-axis and 5-axis machining:
            PRO_TM_TYPE_ALONG_AXIS_APPROACH  (please see ProMfgElemToolMtnAlongAxisAppr.h)
            PRO_TM_TYPE_ALONG_AXIS_EXIT      (please see ProMfgElemToolMtnAlongAxisExit.h)     

Note-66 : Datum point selection. Allows to start machining at the specified 
          position.
          Optional.

Note-67 : Datum point selection. Allows to end machining at the specified 
          position.
          Optional.

Note-68 : Array of ids of prerequisite sequences. For information purpose only.
          Please see ProMfgElemPrerequisite.h.
          Optional.

Note-69 : Reference selections (part, feature, curve, surface, edge, 
          datum plane, axis, point, datum csys). Allows to create 
          additional geometry references to be used only in special process
          application.
          Element supports multiple selections.
          Optional.

Note-70 : View name. Allows to associate specific view with a machining step.
          Used only in special process application.
          Optional.

Note-71 : Simplified representation name. Allows to associate specific 
          simplified representation with a machining step.
          Used only in special process application.
          Optional.

Note-72 : Time estimate. Allows to specify time estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-73 : Cost estimate. Allows to specify cost estimate for the 
          machining step.
          Used only in special process application.
          Optional.

Note-74 : Actual time. Allows to specify actual time for the machining step.
          Used only in special process application.
          Optional.

Note-75 : Sequence comments.

Note-76 : Auto cutline option definition.
          PRO_B_FALSE - cutlines are being defined manually.
          PRO_B_TRUE  - cutlines are being defined automatically.
          Optional.

Note-77 : Auto cutline inner point selection. 
          Optional.

Note-78 : Auto cutline inner first option definition.
          PRO_B_FALSE - outer auto cutline is first.
          PRO_B_TRUE  - innner auto cutline is first.
          Optional. 

Note-79 : Type of spindle assigned to the sequence.
          Values are defined by ProSubSpindleOpt.
          Optional (if not defined - PRO_MFG_MAIN_SPINDLE is set
          by default)

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATCUTLINE_H */
