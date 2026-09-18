#ifndef PROMFGELEMTOOLMTNTRAJCURVE_H
#define PROMFGELEMTOOLMTNTRAJCURVE_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Curve Cut" (PRO_TM_TYPE_CURVE_TRAJECTORY). 
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
    
    -- PRO_E_TOOL_MTN
          |
          |-- PRO_E_TOOL_MTN_REF_ID
          |
          |-- PRO_E_TOOL_MTN_TYPE
          |
          |-- PRO_E_MFG_PARAM_ARR
          |
          |-- PRO_E_MFG_TRAJ_CRV
          |      |
          |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
          |
          |-- PRO_E_NCD_CURVE_POINT
          |      |
          |      |-- PRO_E_NCD_CURVE_POINT_REF
          |      |
          |      |-- PRO_E_NCD_CURVE_POINT_OFFSET_TYPE
          |      |
          |      |-- PRO_E_NCD_CURVE_POINT_OFFSET
          |
          |-- PRO_E_MFG_HELICAL_CUT_OPT
          |
          |-- PRO_E_MFG_START_HEIGHT
          |
          |-- PRO_E_MFG_HEIGHT
          |
          |-- PRO_E_MFG_OFFSET
          |      |
          |      |-- PRO_E_MFG_OFFSET_CUT
          |      |
          |      |-- PRO_E_MFG_MAT_TO_RMV
          |      |
          |      |-- PRO_E_MFG_DRV_SRF_DIR
          |
          |-- PRO_E_CHECK_SURF_COLL
          |
          |-- PRO_E_MFG_AXIS_DEF_COMP
          |      |
          |      |-- PRO_E_MFG_AXIS_DEF_TYPE
          |      |
          |      |-- PRO_E_MFG_AXIS_DEF_PIVOT_REF
          |      |
          |      |-- PRO_E_MFG_AXIS_DEF_NORM_SRF_COMP
          |      |      |
          |      |      |-- PRO_E_MFG_AXIS_DEF_NORM_SRF
          |      |      |
          |      |      |-- PRO_E_MFG_AXDEF_NORM_SURF_DIR
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
                 |             |
                 |             |-- PRO_E_MFG_AXIS_DEF_LOC_ALIGN_Z
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
          |-- PRO_E_MFG_TRAJ_CORNER_COND
                 |
                 |-- PRO_E_MFG_TRAJ_CORNER_DFLT_TYPE
                 |
                 |-- PRO_E_MFG_TRAJ_CORNER_ARR
                        |
                        |-- PRO_E_MFG_TRAJ_CORNER
                               |
                               |-- PRO_E_MFG_TRAJ_CORNER_TYPE
                               |
                               |-- PRO_E_MFG_TRAJ_CORNER_PREV_ID
                               |
                               |-- PRO_E_MFG_TRAJ_CORNER_NEXT_ID
                               |
                               |-- PRO_E_MFG_TRAJ_CORNER_VAL
                 
===============================================================================

(2) Elements table

-------------------------------------------------------------------------------------------------------
Element Id                         Element Name                  Data Type                 Valid Values
-------------------------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                     Tool Motion                   Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID              Tool Motion Id                PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE                Tool Motion Type              PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR                Mfg Parameter Array           Array                     Note-4
PRO_E_MFG_TRAJ_CRV                 Trajectory Curve              Compound                  Note-5
PRO_E_STD_CURVE_COLLECTION_APPL    Curve Collection              Curve Collection          Note-6
PRO_E_NCD_CURVE_POINT              Curve Point                   Compound                  Note-7
PRO_E_NCD_CURVE_POINT_REF          Curve Point Reference         PRO_VALUE_TYPE_SELECTION  Note-8
PRO_E_NCD_CURVE_POINT_OFFSET_TYPE  Curve Point Offset Type       PRO_VALUE_TYPE_INT        Note-9
PRO_E_NCD_CURVE_POINT_OFFSET       Curve Point Offset            PRO_VALUE_TYPE_DOUBLE     Note-10
PRO_E_MFG_HELICAL_CUT_OPT          Helical Cut                   PRO_VALUE_TYPE_INT        Note-11
PRO_E_MFG_START_HEIGHT             Start Height                  PRO_VALUE_TYPE_SELECTION  Note-12
PRO_E_MFG_HEIGHT                   Height                        PRO_VALUE_TYPE_SELECTION  Note-13
PRO_E_MFG_OFFSET                   Offset                        Compound                  Note-14
PRO_E_MFG_OFFSET_CUT               Offset Cut                    PRO_VALUE_TYPE_INT        Note-15
PRO_E_MFG_MAT_TO_RMV               Material To Remove            PRO_VALUE_TYPE_INT        Note-16
PRO_E_MFG_DRV_SRF_DIR              Flip Drive Surface Direction  PRO_VALUE_TYPE_INT        Note-17
PRO_E_CHECK_SURF_COLL              Check Surfaces                Compound                  Note-18
PRO_E_MFG_AXIS_DEF_COMP            Axis Definition               Compound                  Note-19
PRO_E_MFG_AXIS_DEF_TYPE            Axis Definition Type          PRO_VALUE_TYPE_INT        Note-20
PRO_E_MFG_AXIS_DEF_PIVOT_REF       Pivot Reference               PRO_VALUE_TYPE_SELECTION  Note-21
PRO_E_MFG_AXIS_DEF_NORM_SRF_COMP   Normal Surface  Compound      Compound                  Note-22
PRO_E_MFG_AXIS_DEF_NORM_SRF        Normal Surface                PRO_VALUE_TYPE_SELECTION  Note-23
PRO_E_MFG_AXDEF_NORM_SURF_DIR      Normal Surface Direction      PRO_VALUE_TYPE_INT        Note-24
PRO_E_MFG_AXIS_DEF_LOCATION_ARR    Location Array                Array                     Note-25
PRO_E_MFG_AXIS_DEF_LOCATION        Location Item                 Compound                  Note-26
PRO_E_MFG_AXIS_DEF_ORIGIN_REF      Origin Reference              PRO_VALUE_TYPE_SELECTION  Note-27
PRO_E_MFG_AXIS_DEF_ORIENT_COMP     Orientation                   Compound                  Note-28
PRO_E_MFG_AXIS_DEF_ORIENT_REF      Orientation Reference         PRO_VALUE_TYPE_SELECTION  Note-29
PRO_E_MFG_AXES_DEF_ANGLE_X         Lead angle                    PRO_VALUE_TYPE_DOUBLE     Note-30
PRO_E_MFG_AXES_DEF_ANGLE_Y         Tilt angle                    PRO_VALUE_TYPE_DOUBLE     Note-31
PRO_E_MFG_AXIS_DEF_LOC_FLIP_OPT    Direction Flip                PRO_VALUE_TYPE_INT        Note-32
PRO_E_MFG_AXIS_DEF_LOC_ALIGN_Z     Align with the Z Axis         PRO_VALUE_TYPE_INT        Note-33
PRO_E_MFG_AXIS_DEF_CURVE_COMP      Pivot Curve                   Compound                  Note-34
PRO_E_STD_CURVE_COLLECTION_APPL    Pivot Curve Collection        Chain Collection          Note-35
PRO_E_MFG_AXIS_DEF_SYNC_ARR        Synchronization Array         Array                     Note-36
PRO_E_MFG_AXIS_DEF_SYNC_COMP       Synchronization Item          Compound                  Note-37
PRO_E_MFG_AXIS_DEF_SYNC_PNT_1      Synchronization point 1       PRO_VALUE_TYPE_SELECTION  Note-38
PRO_E_MFG_AXIS_DEF_SYNC_PNT_2      Synchronization point 2       PRO_VALUE_TYPE_SELECTION  Note-39
PRO_E_MFG_AXIS_DEF_SYNC_FLIP_OPT   Direction Flip                PRO_VALUE_TYPE_INT        Note-40
PRO_E_MFG_AXIS_DEF_FLIP_OPT        Direction Flip                PRO_VALUE_TYPE_INT        Note-41
PRO_E_MFG_TRAJ_CORNER_COND         Corner Condition              Compound                  Note-42
PRO_E_MFG_TRAJ_CORNER_DFLT_TYPE    Default Corner Type           PRO_VALUE_TYPE_INT        Note-43
PRO_E_MFG_TRAJ_CORNER_ARR          Corner Condition Array        Array                     Note-44
PRO_E_MFG_TRAJ_CORNER              Corner Condition Item         Compound                  Note-45
PRO_E_MFG_TRAJ_CORNER_TYPE         Corner Type                   PRO_VALUE_TYPE_INT        Note-46
PRO_E_MFG_TRAJ_CORNER_PREV_ID      Previous Id                   PRO_VALUE_TYPE_INT        Note-47
PRO_E_MFG_TRAJ_CORNER_NEXT_ID      Next Id                       PRO_VALUE_TYPE_INT        Note-48
PRO_E_MFG_TRAJ_CORNER_VAL          Corner Value                  PRO_VALUE_TYPE_DOUBLE     Note-49
=======================================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_CURVE_TRAJECTORY
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-5 :  Machining curves compound definition.
          Mandatory.

Note-6 :  Curve collection.
          Mandatory.

Note-7 :  Compound Start Point definition.
          Applicable for closed loops only.
          Optional.

Note-8 :  Start Point vertex definition to offset from.
          Optional.

Note-9 :  Start Point offset type definition.
          PRO_CURVE_POINT_OFFSET_TYPE_RATIO - offset by parameter.
          PRO_CURVE_POINT_OFFSET_TYPE_REAL - offset by length.
          Optional.

Note-10 : Start Point offset definition.
          Optional.

Note-11 : Helical cut option.
          PRO_B_TRUE  - helical option and parameters will be applied.
          PRO_B_FALSE - helical option and parameters will not be applied.
          Optional.

Note-12 : Selection of Start Height surface.
          Optional.

Note-13 : Multiple selections of Height surfaces.
          Optional.

Note-14 : Offset compound definition.
          Optional.

Note-15 : Offset cut.
          PRO_B_TRUE - tool offset will be applied.
          PRO_B_FALSE - tool offset will not be applied.
          Optional.

Note-16 : Material side.
          PRO_MAT_RMV_LEFT    - Cut on left from curve.
          PRO_MAT_RMV_RIGHT   - Cut on right from curve.
          Optional.

Note-17 : Flip Drive Surface Direction.
          PRO_B_FALSE - default direction on the drive surface will be used.
          PRO_B_TRUE - opposite direction on the drive surface will be used .
          Optional.

Note-18 : Check surfaces compound definition.
          Please see ProMfgElemCheckSurf.h.
          Optional.

Note-19 : Axis definition compound element.
          Optional.
          
Note-20 : Values defined by ProAxisDefType:
             PRO_AXIS_DEF_TYPE_UNDEF,
             PRO_AXIS_DEF_BY_PIVOT_REF,
             PRO_AXIS_DEF_BY_LOCATIONS,
             PRO_AXIS_DEF_BY_TWO_CONTOURS,
             PRO_AXIS_DEF_BY_NORM_SURF.
          Please see ProMfgOptions.h
          Mandatory.
          
Note-21 : Single reference selection (point or axis ).
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_PIVOT_REF.
          Ignored in all other cases.
          
Note-22 : Normal Surface compound element.
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_NORM_SURF.
          Ignored in all other cases.
          
Note-23 : Multiple reference selection ( surface or quilt or feature. Quilt or feature 
          must represent Mill Surface ).
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_NORM_SURF.
          Ignored in all other cases.

Note-24 : Normal Surface Direction.
          PRO_B_TRUE  - Direction opposite to the normal to the surface selected for
                        PRO_E_MFG_AXIS_DEF_NORM_SRF.
          PRO_B_FALSE - Same direction as the normal to the surface selected for
                        PRO_E_MFG_AXIS_DEF_NORM_SRF.
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_NORM_SURF.
          Ignored in all other cases.

Note-25 : Array of locations. 
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_LOCATIONS.
          Ignored in all other cases.
          
Note-26 : Location compound element.
          Mandatory.
          
Note-27 : Single reference selection (point on a curve or an edge).
          Mandatory.

Note-28 : Orientation compound element.
          Mandatory.
          
Note-29 : Single reference selection (point or axis ).
          Mandatory if PRO_E_MFG_AXES_DEF_ANGLE_X/Y are not defined.
          
Note-30 : Lead angle.
          Range -90 to +90.
          Mandatory if PRO_E_MFG_AXIS_DEF_ORIENT_REF is not defined.
          
Note-31 : Tilt angle.
          Range -90 to +90.
          Mandatory if PRO_E_MFG_AXIS_DEF_ORIENT_REF is not defined.
          
Note-32 : Direction flip at a location.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-33 : Align with the Z Axis option.
          PRO_B_TRUE  - Align the tool axis with the Z axis of the step coordinate system;
          Mandatory.
                
Note-34 : Pivot Curve compound element.
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_TWO_CONTOURS.
          Ignored in all other cases.
          
Note-35 : Chain collection general compound element.
          Mandatory.
                
Note-36 : Synchronization Array.
          Optional.
          
Note-37 : Synchronization compound element.
          Optional.
          
Note-38 : Single reference selection (point on the trajectory curve).
          Mandatory.
          
Note-39 : Single reference selection (point on the pivot curve).
          Mandatory.
          
Note-40 : Direction flip.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-41 : Direction flip.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-42 : Corner condition compound element.
          Optional.
                
Note-43 : Values defined by ProTmTrajCornerType:
             PRO_TM_TRAJ_CORNER_TYPE_SHARP,
             PRO_TM_TRAJ_CORNER_TYPE_FILLET,
             PRO_TM_TRAJ_CORNER_TYPE_CHAMFER,
             PRO_TM_TRAJ_CORNER_TYPE_LOOP,
             PRO_TM_TRAJ_CORNER_TYPE_STRAIGHT.
          Please see ProMfgOptions.h
          Mandatory.
                   
Note-44 : Corner Condition Array.
          Optional.
                   
Note-45 : Corner Condition Item.
          Optional.
                   
Note-46 : Values defined by ProTmTrajCornerType:
             PRO_TM_TRAJ_CORNER_TYPE_SHARP,
             PRO_TM_TRAJ_CORNER_TYPE_FILLET,
             PRO_TM_TRAJ_CORNER_TYPE_CHAMFER,
             PRO_TM_TRAJ_CORNER_TYPE_LOOP,
             PRO_TM_TRAJ_CORNER_TYPE_STRAIGHT.
          Please see ProMfgOptions.h
          Mandatory.

Note-47 : Previous id.
          Mandatory.
                   
Note-48 : Next id.
          Mandatory.

Note-49 : Fillet radius or chamfer dimension.  
          Range 0. to MAX_DIM_VALUE.
          Mandatory if corner type is PRO_TM_TRAJ_CORNER_TYPE_FILLET or
                                      PRO_TM_TRAJ_CORNER_TYPE_CHAMFER.
                                      
==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNTRAJCURVE_H */
