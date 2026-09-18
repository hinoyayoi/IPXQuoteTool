#ifndef PROMFGELEMTOOLMTNTRAJSURF_H
#define PROMFGELEMTOOLMTNTRAJSURF_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Drive Surface Cut" (PRO_TM_TYPE_SURF_TRAJECTORY). 
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
          |-- PRO_E_MFG_TRAJ_SRFS
          |      |
          |      |-- PRO_E_STD_SURF_COLLECTION_APPL
          |      
          |-- PRO_E_MFG_CUT_START_PNT_REF
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

----------------------------------------------------------------------------------------------------
Element Id                      Element Name                  Data Type                 Valid Values
----------------------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                    Tool Motion                   Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID             Tool Motion Id                PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE               Tool Motion Type              PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR               Mfg Parameter Array           Array                     Note-4
PRO_E_MFG_HELICAL_CUT_OPT         Helical Cut                   PRO_VALUE_TYPE_INT        Note-5
PRO_E_MFG_START_HEIGHT            Start Height                  PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_MFG_HEIGHT                  Height                        PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_MFG_TRAJ_SRFS               Trajectory Surfaces           Compound                  Note-8
PRO_E_STD_SURF_COLLECTION_APPL    Traj Surface Collection       Surface Collection        Note-9
PRO_E_MFG_OFFSET                  Offset                        Compound                  Note-10
PRO_E_MFG_OFFSET_CUT              Offset Cut                    PRO_VALUE_TYPE_INT        Note-11
PRO_E_MFG_MAT_TO_RMV              Material To Remove            PRO_VALUE_TYPE_INT        Note-12
PRO_E_MFG_DRV_SRF_DIR             Flip Drive Surface Direction  PRO_VALUE_TYPE_INT        Note-13
PRO_E_CHECK_SURF_COLL             Check Surfaces                Compound                  Note-14
PRO_E_MFG_CUT_START_PNT_REF       Start Point Ref               PRO_VALUE_TYPE_SELECTION  Note-15
PRO_E_MFG_AXIS_DEF_COMP           Axis Definition               Compound                  Note-16
PRO_E_MFG_AXIS_DEF_TYPE           Axis Definition Type          PRO_VALUE_TYPE_INT        Note-17
PRO_E_MFG_AXIS_DEF_PIVOT_REF      Pivot Reference               PRO_VALUE_TYPE_SELECTION  Note-18
PRO_E_MFG_AXIS_DEF_NORM_SRF       Normal Surface                Compound                  Note-19
PRO_E_STD_CURVE_COLLECTION_APPL   Normal Surface Collection     Surface Collection        Note-20
PRO_E_MFG_AXIS_DEF_LOCATION_ARR   Location Array                Array                     Note-21
PRO_E_MFG_AXIS_DEF_LOCATION       Location Item                 Compound                  Note-22
PRO_E_MFG_AXIS_DEF_ORIGIN_REF     Origin Reference              PRO_VALUE_TYPE_SELECTION  Note-23
PRO_E_MFG_AXIS_DEF_ORIENT_COMP    Orientation                   Compound                  Note-24
PRO_E_MFG_AXIS_DEF_ORIENT_REF     Orientation Reference         PRO_VALUE_TYPE_SELECTION  Note-25
PRO_E_MFG_AXES_DEF_ANGLE_X        Lead angle                    PRO_VALUE_TYPE_DOUBLE     Note-26
PRO_E_MFG_AXES_DEF_ANGLE_Y        Tilt angle                    PRO_VALUE_TYPE_DOUBLE     Note-27
PRO_E_MFG_AXIS_DEF_LOC_FLIP_OPT   Direction Flip                PRO_VALUE_TYPE_INT        Note-28
PRO_E_MFG_AXIS_DEF_CURVE_COMP     Pivot Curve                   Compound                  Note-29
PRO_E_STD_CURVE_COLLECTION_APPL   Pivot Curve Collection        Chain Collection          Note-30
PRO_E_MFG_AXIS_DEF_SYNC_ARR       Synchronization Array         Array                     Note-31
PRO_E_MFG_AXIS_DEF_SYNC_COMP      Synchronization Item          Compound                  Note-32
PRO_E_MFG_AXIS_DEF_SYNC_PNT_1     Synchronization point 1       PRO_VALUE_TYPE_SELECTION  Note-33
PRO_E_MFG_AXIS_DEF_SYNC_PNT_2     Synchronization point 2       PRO_VALUE_TYPE_SELECTION  Note-34
PRO_E_MFG_AXIS_DEF_FLIP_OPT       Direction Flip                PRO_VALUE_TYPE_INT        Note-35
PRO_E_MFG_TRAJ_CORNER_COND        Corner Condition              Compound                  Note-36
PRO_E_MFG_TRAJ_CORNER_DFLT_TYPE   Default Corner Type           PRO_VALUE_TYPE_INT        Note-37
PRO_E_MFG_TRAJ_CORNER_ARR         Corner Condition Array        Array                     Note-38
PRO_E_MFG_TRAJ_CORNER             Corner Condition Item         Compound                  Note-39
PRO_E_MFG_TRAJ_CORNER_TYPE        Corner Type                   PRO_VALUE_TYPE_INT        Note-40
PRO_E_MFG_TRAJ_CORNER_PREV_ID     Previous Id                   PRO_VALUE_TYPE_INT        Note-41
PRO_E_MFG_TRAJ_CORNER_NEXT_ID     Next Id                       PRO_VALUE_TYPE_INT        Note-42
PRO_E_MFG_TRAJ_CORNER_VAL         Corner Value                  PRO_VALUE_TYPE_DOUBLE     Note-43
====================================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_SURF_TRAJECTORY
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-5  : Helical cut option.
          PRO_B_TRUE  - helical option and parameters will be applied.
          PRO_B_FALSE - helical option and parameters will not be applied.
          Optional.

Note-6  : Selection of Start Height surface.
          Optional.

Note-7  : Multiple selections of Height surfaces.
          Mandatory.

Note-8  : Drive Surfaces compaund definition.
          Mandatory.

Note-9  : Drive Surfaces collection.
          Mandatory.

Note-10 :  Offset compound definition.
          Optional.

Note-11 : Offset cut.
          PRO_B_TRUE - tool offset will be applied.
          PRO_B_FALSE - tool offset will not be applied.
          Optional.

Note-12 : Material side.
          PRO_MFG_DIR_SAME - default side will be used.
          PRO_MFG_DIR_OPPOSITE - the default side will be flipped.
          Optional.

Note-13 : Flip Drive Surface Direction.
          PRO_B_FALSE - default direction on the drive surface will be used.
          PRO_B_TRUE - opposite direction on the drive surface will be used .
          Optional.

Note-14 : Check surfaces compound definition.
          Please see ProMfgElemCheckSurf.h.
          Optional.

Note-15 : Selection of a datum point, or a point on the bottom edges of the 
          machining surfaces. 
          Applicable only when the machining surfaces form a closed loop.  
          Allows to start machining at the location nearest to the selected 
          point.
          Optional.

Note-16 : Axis definition compound element.
          Optional.
          
Note-17 : Values defined by ProAxisDefType:
             PRO_AXIS_DEF_TYPE_UNDEF,
             PRO_AXIS_DEF_BY_LOCATIONS,
          Please see ProMfgOptions.h
          Mandatory.
          
Note-18 : Array of locations. 
          Mandatory if PRO_E_MFG_AXIS_DEF_TYPE is set to PRO_AXIS_DEF_BY_LOCATIONS.
          Ignored in all other cases.
          
Note-19 : Location compound element.
          Mandatory.
          
Note-20 : Single reference selection (point on a curve or an edge).
          Mandatory.

Note-21 : Orientation compound element.
          Mandatory.
          
Note-22 : Single reference selection (point or axis ).
          Mandatory if PRO_E_MFG_AXES_DEF_ANGLE_X/Y are not defined.
          
Note-23 : Lead angle.
          Range -90 to +90.
          Mandatory if PRO_E_MFG_AXIS_DEF_ORIENT_REF is not defined.
          
Note-24 : Tilt angle.
          Range -90 to +90.
          Mandatory if PRO_E_MFG_AXIS_DEF_ORIENT_REF is not defined.
          
Note-25 : Direction flip at a location.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-26 : Direction flip.
          PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
                
Note-27 : Corner condition compound element.
          Optional.
                
Note-28 : Values defined by ProTmTrajCornerType:
             PRO_TM_TRAJ_CORNER_TYPE_SHARP,
             PRO_TM_TRAJ_CORNER_TYPE_FILLET,
             PRO_TM_TRAJ_CORNER_TYPE_CHAMFER,
             PRO_TM_TRAJ_CORNER_TYPE_LOOP,
             PRO_TM_TRAJ_CORNER_TYPE_STRAIGHT.
          Please see ProMfgOptions.h
          Mandatory.
                   
Note-29 : Corner Condition Array.
          Optional.
                   
Note-30 : Corner Condition Item.
          Optional.
                   
Note-31 : Values defined by ProTmTrajCornerType:
             PRO_TM_TRAJ_CORNER_TYPE_SHARP,
             PRO_TM_TRAJ_CORNER_TYPE_FILLET,
             PRO_TM_TRAJ_CORNER_TYPE_CHAMFER,
             PRO_TM_TRAJ_CORNER_TYPE_LOOP,
             PRO_TM_TRAJ_CORNER_TYPE_STRAIGHT.
          Please see ProMfgOptions.h
          Mandatory.

Note-32 : Previous id.
          Mandatory.
                   
Note-33 : Next id.
          Mandatory.

Note-34 : Fillet radius or chamfer dimension.  
          Range 0. to MAX_DIM_VALUE.
          Mandatory if corner type is PRO_TM_TRAJ_CORNER_TYPE_FILLET or
                                      PRO_TM_TRAJ_CORNER_TYPE_CHAMFER.
                                      
==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNTRAJSURF_H */
