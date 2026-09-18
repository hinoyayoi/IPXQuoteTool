#ifndef PROMFGELEMHOLESET_H
#define PROMFGELEMHOLESET_H
/*
   Creo Parametric TOOLKIT declarations related to mfg holemaking holeset
*/



#include <ProToolkit.h>
#include <ProMfgOptions.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
    
     -- PRO_E_HOLESETS
           |
           |-- PRO_E_HOLESET
                  |
                  |-- PRO_E_HOLESET_ID
                  |
                  |-- PRO_E_HOLESET_TYPE
                  |
                  |-- PRO_E_HOLESET_START
                  |      |
                  |      |--PRO_E_HOLESET_START_TYPE
                  |      |
                  |      |--PRO_E_HOLESET_START_SURFACE
                  |      |
                  |      |--PRO_E_HOLESET_START_Z_OFFSET
                  |
                  |-- PRO_E_HOLESET_END
                  |      |
                  |      |--PRO_E_HOLESET_END_TYPE
                  |      |
                  |      |--PRO_E_HOLESET_END_MEASURE_BY
                  |      |
                  |      |--PRO_E_HOLESET_END_SURFACE
                  |      |
                  |      |--PRO_E_HOLESET_DEPTH_VALUE
                  |      |
                  |      |--PRO_E_HOLESET_END_Z_OFFSET
                  |      |
                  |      |--PRO_E_HOLESET_CSINK_DIAM
                  |      |
                  |      |--PRO_E_HOLESET_USE_BRKOUT_DIST
                  |
                  |-- PRO_E_HOLESET_DEPTH
                  |      |
                  |      |--PRO_E_HOLESET_DEPTH_TYPE
                  |      |
                  |      |--PRO_E_HOLESET_DEPTH_BY_TYPE
                  |      |
                  |      |--PRO_E_HOLESET_DEPTH_PLATES
                  |            |
                  |            |--PRO_E_HOLESET_DEPTH_PLATE
                  |                  |
                  |                  |--PRO_E_HOLESET_PLATE_START
                  |                  |
                  |                  |--PRO_E_HOLESET_PLATE_END_OPT
                  |                  |
                  |                  |--PRO_E_HOLESET_PLATE_END
                  |                  |
                  |                  |--PRO_E_HOLESET_PLATE_DEPTH
                  |                  |
                  |                  |--PRO_E_HOLESET_PLATE_BRKOUT
                  |
                  |-- PRO_E_HOLESET_CUSTOM_CYCLE_PLATES
                  |      |
                  |      |--PRO_E_HOLESET_CUSTOM_CYCLE_REFERENCES
                  |      |     |
                  |      |     |--PRO_E_HOLESET_CUSTOM_CYCLE_REF
                  |      |           |
                  |      |           |--PRO_E_MFG_CUST_CYCLE_PLATE_NAME
                  |      |           |
                  |      |           |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT
                  |      |           |
                  |      |           |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_SEL
                  |      |           |
                  |      |           |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_Z_OFFSET
                  |      |           |
                  |      |           |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_DEPTH
                  |      |
                  |      |--PRO_E_HOLESET_CUSTOM_CYCLE_VARIABLES
                  |            |
                  |            |--PRO_E_HOLESET_CUSTOM_CYCLE_VAR
                  |                  |
                  |                  |--PRO_E_MFG_CUST_CYCLE_VAR_NAME
                  |                  |
                  |                  |--PRO_E_HOLESET_CUSTOM_CYCLE_VAR_VALUE
                  |
                  |-- PRO_E_DRILL_PART_DATA
                  |      |
                  |      |--PRO_E_AUTO_SEL_DRILL_PARTS
                  |      |
                  |      |--PRO_E_DRILL_PARTS
                  |
                  |-- PRO_E_AUTODRILL_INFO
                  |      |
                  |      |--PRO_E_HOLESET_AUTODRILL_REF_INDEX
                  |      |
                  |      |--PRO_E_AUTODRILL_DEPTH_BY_TABLE
                  |
                  |-- PRO_E_HOLESET_ORIENT_TYPE
                  |
                  |-- PRO_E_HOLESET_ORIENT_REF
                  |
                  |-- PRO_E_HOLESET_TIP_CTRL_PNT
                  |
                  |-- PRO_E_HOLESET_SELECTION_RULES
                  |      |
                  |      |--PRO_E_HOLESET_SEL_PNTS_ON_SURFACES
                  |      |
                  |      |--PRO_E_HOLESET_SEL_PNTS_BY_FEATURE
                  |      |
                  |      |--PRO_E_HOLESET_SEL_PROJECT_SURFACES
                  |      |
                  |      |--PRO_E_HOLESET_SEL_MAX_PROJECT_DIST
                  |      |
                  |      |--PRO_E_HOLESET_SEL_UNSEL_PNTS
                  |      |
                  |      |--PRO_E_HOLESET_SEL_INDIV_PNTS
                  |      |
                  |      |--PRO_E_HOLESET_SEL_AUTO_CHAMFER
                  |      |
                  |      |--PRO_E_HOLESET_SEL_AXIS_PATTS
                  |      |
                  |      |--PRO_E_MFG_HSET_DRILL_GROUP_REF
                  |      |
                  |      |--PRO_E_HOLESET_SEL_BY_SURFACES
                  |      |
                  |      |--PRO_E_MFG_HSET_DIAM_TYPE_OPT
                  |      |
                  |      |--PRO_E_MFG_HSET_DIAM_ARR
                  |      |     |
                  |      |     |--PRO_E_MFG_HSET_DIAM_COMPOUND
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_HOLE_DIAM
                  |      |
                  |      |--PRO_E_MFG_HSET_PARAM_RULE_OPT
                  |      |
                  |      |--PRO_E_MFG_HSET_PARAM_ARR
                  |      |     |
                  |      |     |--PRO_E_MFG_HSET_PARAM_COMPOUND
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_NAME
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_DTYPE
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_OPER
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_DBL
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_INT
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_STR
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_BOOL
                  |      |
                  |      |--PRO_E_HOLESET_SEL_UNSEL_AXES
                  |      |
                  |      |--PRO_E_HOLESET_SEL_INDIV_AXES
                  |      |
                  |      |--PRO_E_HOLESET_SEL_UNSEL_GEOMETRY
                  |      |
                  |      |--PRO_E_HOLESET_SEL_INDIV_GEOMETRY
                  |
                  |-- PRO_E_MFG_HSET_START_HOLE_REF
                  |
                  |-- PRO_E_HOLESET_UNFLIPPED_AXES
                  |
                  |-- PRO_E_HOLESET_FLIPPED_AXES
                  |
                  |-- PRO_E_HOLESET_GANG_TOOL_INFO
                         |
                         |--PRO_E_HSET_GANG_TOOL_PARENT_ID
                         |
                         |--PRO_E_HSET_IS_GANG_TOOL_LEADER
     

===============================================================================

(2) Elements table

--------------------------------------------------------------------------------------------------
Element Id                              Element Name         Data Type                 Valid Value
--------------------------------------------------------------------------------------------------
PRO_E_HOLESETS                          Holeset Array        Array                     Note-1
PRO_E_HOLESET                           Holeset              Compound                  Note-2
PRO_E_HOLESET_ID                        Holeset Id           PRO_VALUE_TYPE_INT        Note-3
PRO_E_HOLESET_TYPE                      Holeset Type         PRO_VALUE_TYPE_INT        Note-4
PRO_E_HOLESET_START                     Holeset Start        Compound                  Note-5
PRO_E_HOLESET_START_TYPE                Start Type           PRO_VALUE_TYPE_INT        Note-6
PRO_E_HOLESET_START_SURFACE             Start Surface        PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_HOLESET_END                       Holeset End          Compound                  Note-8
PRO_E_HOLESET_END_TYPE                  Depth Type Option    PRO_VALUE_TYPE_INT        Note-9
PRO_E_HOLESET_END_MEASURE_BY            Measure By Option    PRO_VALUE_TYPE_INT        Note-10
PRO_E_HOLESET_END_SURFACE               End Surface          PRO_VALUE_TYPE_SELECTION  Note-11
PRO_E_HOLESET_DEPTH_VALUE               Depth Value          PRO_VALUE_TYPE_DOUBLE     Note-12
PRO_E_HOLESET_CSINK_DIAM                Countersink Diameter PRO_VALUE_TYPE_DOUBLE     Note-13
PRO_E_HOLESET_USE_BRKOUT_DIST           Breakout Distance    PRO_VALUE_TYPE_DOUBLE     Note-14
PRO_E_HOLESET_DEPTH                     Holeset Depth        Compound                  Note-15
PRO_E_HOLESET_DEPTH_TYPE                Depth Type           PRO_VALUE_TYPE_INT        Note-16
PRO_E_HOLESET_DEPTH_BY_TYPE             Depth By Type        PRO_VALUE_TYPE_INT        Note-17
PRO_E_HOLESET_DEPTH_PLATES              Holeset Plates       Array                     Note-18
PRO_E_HOLESET_DEPTH_PLATE               Plate                Compound                  Note-19
PRO_E_HOLESET_PLATE_START               Plate Start Surface  PRO_VALUE_TYPE_SELECTION  Note-20
PRO_E_HOLESET_PLATE_END_OPT             Plate End Type       PRO_VALUE_TYPE_INT        Note-21
PRO_E_HOLESET_PLATE_END                 Plate End Surface    PRO_VALUE_TYPE_SELECTION  Note-22
PRO_E_HOLESET_PLATE_DEPTH               Plate Depth Offset   PRO_VALUE_TYPE_DOUBLE     Note-23
PRO_E_HOLESET_PLATE_BRKOUT              Plate Breakout Value PRO_VALUE_TYPE_DOUBLE     Note-24
PRO_E_HOLESET_CUSTOM_CYCLE_PLATES       Custom Cycle Plates  Compound                  Note-25
PRO_E_HOLESET_CUSTOM_CYCLE_REFERENCES   Cycle References     Array                     Note-26
PRO_E_HOLESET_CUSTOM_CYCLE_REF          Cycle Ref Compound   Compound                  Note-27
PRO_E_MFG_CUST_CYCLE_PLATE_NAME         Cycle Plate Name     Compound                  Note-28
PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT      Cycle Ref Type       PRO_VALUE_TYPE_INT        Note-29
PRO_E_HOLESET_CUSTOM_CYCLE_REF_SEL      Cycle Reference      PRO_VALUE_TYPE_SELECTION  Note-30
PRO_E_HOLESET_CUSTOM_CYCLE_REF_Z_OFFSET Cycle Offset         PRO_VALUE_TYPE_DOUBLE     Note-31
PRO_E_HOLESET_CUSTOM_CYCLE_VARIABLES    Cycle Variables      Array                     Note-32
PRO_E_HOLESET_CUSTOM_CYCLE_VAR          Cycle Variable       Compound                  Note-33
PRO_E_MFG_CUST_CYCLE_VAR_NAME           Variable Name        PRO_VALUE_TYPE_WSTRING    Note-34
PRO_E_HOLESET_CUSTOM_CYCLE_VAR_VALUE    Variable Value       PRO_VALUE_TYPE_DOUBLE     Note-35
PRO_E_DRILL_PART_DATA                   Part Data            Compound                  Note-36
PRO_E_AUTO_SEL_DRILL_PARTS              Auto Option          PRO_VALUE_TYPE_INT        Note-37
PRO_E_DRILL_PARTS                       Parts                PRO_VALUE_TYPE_SELECTION  Note-38
PRO_E_HOLESET_SELECTION_RULES           Holes Compound       Compound                  Note-39
PRO_E_HOLESET_SEL_PNTS_ON_SURFACES      Points Surface       PRO_VALUE_TYPE_SELECTION  Note-40
PRO_E_HOLESET_SEL_PNTS_BY_FEATURE       Point Features       PRO_VALUE_TYPE_SELECTION  Note-41
PRO_E_HOLESET_SEL_PROJECT_SURFACES      Points Proj Surface  PRO_VALUE_TYPE_SELECTION  Note-42
PRO_E_HOLESET_SEL_MAX_PROJECT_DIST      Max Proj Dist        PRO_VALUE_TYPE_DOUBLE     Note-43
PRO_E_HOLESET_SEL_UNSEL_PNTS            Excluded Points      PRO_VALUE_TYPE_SELECTION  Note-44
PRO_E_HOLESET_SEL_INDIV_PNTS            Individual Points    PRO_VALUE_TYPE_SELECTION  Note-45
PRO_E_HOLESET_SEL_AUTO_CHAMFER          Auto Chamfer         PRO_VALUE_TYPE_INT        Note-46
PRO_E_HOLESET_SEL_AXIS_PATTS            Patterns             PRO_VALUE_TYPE_SELECTION  Note-47
PRO_E_MFG_HSET_DRILL_GROUP_REF          Drill Groups         PRO_VALUE_TYPE_SELECTION  Note-48
PRO_E_HOLESET_SEL_BY_SURFACES           Surfaces with holes  PRO_VALUE_TYPE_SELECTION  Note-49
PRO_E_MFG_HSET_DIAM_ARR                 Diameter Array       Array                     Note-50
PRO_E_MFG_HSET_DIAM_COMPOUND            Diameter Compound    Compound                  Note-51
PRO_E_MFG_HSET_HOLE_DIAM                Diameter             PRO_VALUE_TYPE_DOUBLE     Note-52
PRO_E_MFG_HSET_PARAM_ARR                Parameter Array      Array                     Note-53
PRO_E_MFG_HSET_PARAM_COMPOUND           Parameter Compound   Compound                  Note-54
PRO_E_MFG_HSET_PARAM_NAME               Parameter Name       PRO_VALUE_TYPE_WSTRING    Note-55
PRO_E_MFG_HSET_PARAM_DTYPE              Data Type            PRO_VALUE_TYPE_INT        Note-56
PRO_E_MFG_HSET_PARAM_OPER               Operator             PRO_VALUE_TYPE_INT        Note-57
PRO_E_MFG_HSET_PARAM_VAL_DBL            Double Value         PRO_VALUE_TYPE_DOUBLE     Note-58
PRO_E_MFG_HSET_PARAM_VAL_INT            Integer Value        PRO_VALUE_TYPE_INT        Note-59
PRO_E_MFG_HSET_PARAM_VAL_STR            String Value         PRO_VALUE_TYPE_WSTRING    Note-60
PRO_E_MFG_HSET_PARAM_VAL_BOOL           Boolean Value        PRO_VALUE_TYPE_INT        Note-61
PRO_E_HOLESET_SEL_UNSEL_AXES            Excluded Axes        PRO_VALUE_TYPE_SELECTION  Note-62
PRO_E_HOLESET_SEL_INDIV_AXES            Individual Axes      PRO_VALUE_TYPE_SELECTION  Note-63
PRO_E_HOLESET_SEL_UNSEL_GEOMETRY        Excluded Holes       PRO_VALUE_TYPE_SELECTION  Note-64
PRO_E_HOLESET_SEL_INDIV_GEOMETRY        Individual Holes     PRO_VALUE_TYPE_SELECTION  Note-65
PRO_E_HOLESET_TIP_CTRL_PNT              Tool Tip Number      PRO_VALUE_TYPE_INT        Note-66
PRO_E_MFG_HSET_START_HOLE_REF           Start Hole           PRO_VALUE_TYPE_SELECTION  Note-67
PRO_E_HOLESET_UNFLIPPED_AXES            Unflipped Axes       PRO_VALUE_TYPE_SELECTION  Note-68
PRO_E_HOLESET_FLIPPED_AXES              Flipped Axes         PRO_VALUE_TYPE_SELECTION  Note-69
PRO_E_HOLESET_ORIENT_TYPE               Orientation Type     PRO_VALUE_TYPE_INT        Note-70
PRO_E_HOLESET_ORIENT_REF                Orient Reference     PRO_VALUE_TYPE_SELECTION  Note-71
PRO_E_HOLESET_START_Z_OFFSET            Start Z Offset       PRO_VALUE_TYPE_DOUBLE     Note-72
PRO_E_HOLESET_END_Z_OFFSET              End Z Offset         PRO_VALUE_TYPE_DOUBLE     Note-73
PRO_E_HOLESET_CUSTOM_CYCLE_REF_DEPTH    Cust Cycle Ref Depth PRO_VALUE_TYPE_DOUBLE     Note-74
PRO_E_AUTODRILL_INFO                    Autodrill Compound   Compound                  Note-75
PRO_E_HOLESET_AUTODRILL_REF_INDEX       Autodrill Ref Index  PRO_VALUE_TYPE_INT        Note-76
PRO_E_AUTODRILL_DEPTH_BY_TABLE          Autodrill Depth Type PRO_VALUE_TYPE_INT        Note-77
PRO_E_HOLESET_GANG_TOOL_INFO            Gang Tool Info       Compound                  Note-78
PRO_E_HSET_GANG_TOOL_PARENT_ID          Gang Tool Parent Id  PRO_VALUE_TYPE_INT        Note-79
PRO_E_HSET_IS_GANG_TOOL_LEADER          Gang Tool Leader Opt PRO_VALUE_TYPE_INT        Note-80
PRO_E_MFG_HSET_DIAM_TYPE_OPT            Diameter Types       PRO_VALUE_TYPE_INT        Note-81
PRO_E_MFG_HSET_PARAM_RULE_OPT           Parameter Rule Opt   PRO_VALUE_TYPE_INT        Note-82


===============================================================================

(3) Notes


Note-1  : Array of holesets - specification of machining references.

Note-2  : Holeset definition.
          Mandatory (holeset array should have at least one member).

Note-3  : Holeset id.
          Internal use only. Should not be added or modified.

Note-4  : Holeset type - axes or points.
          Values defined by ProHolesetType.  
          Mandatory.

Note-5  : Holemaking start compound specification.
          Ignored for web drilling. Mandatory for other types of holemaking.

Note-6  : Start surface option.
          Values defined by ProDrillStartType.
          Ignored for web drilling and counersinking (when 
          PRO_E_HOLEMAKING_TYPE is set to PRO_HOLE_MK_CSINK or 
          PRO_HOLE_MK_WEB). Mandatory for other types of holemaking.

Note-7  : Starting surface or quilt selection.
          For countersink it is optional if auto_chamfer rule is set and there 
          is no explicit axes selection.
          For web drilling it is ignored.  For other holemaking types it is 
          mandatory if PRO_E_HOLESET_START_TYPE is set to
          PRO_DRILL_FROM_SURFACE.  

Note-8  : Holemaking depth compound specification.
          Ignored for web drilling. Mandatory for other types of holemaking.

Note-9  : End type option.
          Values defined by ProDrillEndType.
          Ignored for counersinking. Mandatory for other types of holemaking.

Note-10 : Depth calculation option - tip/shoulder.
          Values defined by ProDrillDepthByType.
          Ignored for counersinking and web drilling.
          Mandatory for other types of holemaking.

Note-11 : End surface or quilt selection.
	  Ignored for countersinking and web drilling.
	  Ignored for custom drilling if cycle definition does not use end 
          surface.
          Mandatory if PRO_E_HOLESET_END_TYPE is set to 
          PRO_DRILL_UPTO_SURFACE. Ignored in all other cases.

Note-12 : Depth to drill from start.
          Mandatory if PRO_E_HOLESET_END_TYPE is set to 
          PRO_DRILL_OFFSET_FROM_START. Ignored in all other cases.

Note-13 : Countersink diameter.
          Mandatory for countersink sequence (when PRO_E_HOLEMAKING_TYPE is 
          set to PRO_HOLE_MK_CSINK). Ignored in all other cases.

Note-14 : Depth breakout option.
	  Ignored if end_type is PRO_DRILL_THRU_ALL_PARTS or 
          PRO_DRILL_AUTO_END.

          TRUE - to drill an additional BREAKOUT_DISTANCE (manufacturing 
          parameter) deeper.
          FALSE - do not drill deeper than defined by depth specification.
          Optional. Ignored for countersink sequences.

Note-15 : Web drilling depth compound specification.
          Mandatory for web drilling. Ignored for other types of holemaking.

Note-16 : Web drilling depth type option - blind/auto/through.
          Values defined by ProDrillDepthType.
          Mandatory for web drilling. Ignored for other types of holemaking.

Note-17 : Web drilling depth calculation option - tip/shoulder.
          Values defined by ProDrillDepthByType.
          Mandatory for web drilling. Ignored for other types of holemaking.

Note-18 : Array of web drilling plates.
          Mandatory for web drilling. Ignored for other types of holemaking.

Note-19 : Web drilling plate definition.
          Mandatory (at least one plate should be defiined in array of plates).

Note-20 : Web drilling plate starting surface or quilt selection.
          Mandatory if PRO_E_HOLESET_DEPTH_TYPE is set to PRO_DRILL_BLIND. 
          Ignored in all other cases.

Note-21 : Web drilling plate depth type option.
          Values defined by ProDrillEndType.
          Mandatory for web drilling. Ignored for other types of holemaking.

Note-22 : Web drilling plate end surface or quilt selection.
          Mandatory for web drilling if PRO_E_HOLESET_PLATE_END_OPT is set to 
          PRO_DRILL_UPTO_SURFACE. Ignored in all other cases.

Note-23 : Web drilling depth from plate start.
          Mandatory for web drilling if PRO_E_HOLESET_PLATE_END_OPT is set to 
          PRO_DRILL_OFFSET_FROM_START. Ignored in all other cases.

Note-24 : Web drilling depth breakout option.
          TRUE - to drill an additional BREAKOUT_DISTANCE (manufacturing 
          parameter) deeper.
          FALSE - do not drill deeper than defined by depth specification.
          Optional. Ignored for countersink sequences.

Note-25 : Compound definition of custom cycle.
          Mandatory for custom cycle holemaking. Ignored for other types of 
          holemaking.

Note-26 : Array of custom cycle references.
          Number of members in array should match with number of references in 
          custom cycle definition (stored in mfg model).
          Mandatory if references are used in the custom cycle definition(see 
          PRO_E_MFG_CUSTOM_CYCLE_NAME).

Note-27 : Compound definition of a custom cycle reference.
          Mandatory for custom cycle with references.

Note-28 : Name of custom cycle reference.
          Mandatory for reference definition.

Note-29 : Type of reference specification.
          Values defined by ProCustomRefOption.
          Mandatory for reference definition.

Note-30 : Custom cycle reference surface or quilt selection.
          Mandatory if PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT is set to 
          PRO_CUSTOM_DRILL_SELECT_REFERENCE. Ignored in all other cases.

Note-31 : Custom cycle reference specification by offset value from sequence
          csys origin.
          Mandatory if PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT is set to 
          PRO_CUSTOM_DRILL_OFFSET_FROM_CSYS. Ignored in all other cases.

Note-32 : Array of custom cycle variables.
          Number of members in array should match with number of variables in 
          custom cycle definition (stored in mfg model).
          Mandatory if variables are used in named custom cycle (see 
          PRO_E_MFG_CUSTOM_CYCLE_NAME).

Note-33 : Compound definition of a custom cycle variable.
          Mandatory for custom cycle with variables.

Note-34 : Name of custom cycle variable.
          Mandatory for variable definition.

Note-35 : Custom cycle variable value.
          Mandatory for variable definition.

Note-36 : Compound information about components used in depth computation.
          Mandatory if start or end of machining has to be 
          computed - either (1) or (2) or (3):
          (1). PRO_E_HOLESET_START_TYPE is set to PRO_DRILL_AUTO_START. 
          (2). PRO_E_HOLESET_END_TYPE is set to PRO_DRILL_AUTO or 
               PRO_DRILL_THRU_ALL 
          (3). PRO_E_HOLESET_DEPTH_TYPE is set to PRO_DRILL_AUTO or 
               PRO_DRILL_THRU_ALL 


Note-37 : Option defines the way components are collected.
          TRUE - all components of type "reference part" or "workpiece"
		 are considered for depth calculation.
          FALSE - Only selected components are considered in depth calculation.
          Mandatory.

Note-38 : Components selections.
          Element supports multiple selections.
          Mandatory if PRO_E_AUTO_SEL_DRILL_PARTS is set to FALSE. 
          Ignored if PRO_E_AUTO_SEL_DRILL_PARTS is set to FALSE.

Note-39 : Compound information about location of holes to drill.
          Mandatory. At least one of the following children elements 
          has to be defined:
             PRO_E_HOLESET_SEL_PNTS_ON_SURFACES,
             PRO_E_HOLESET_SEL_INDIV_PNTS,
             PRO_E_HOLESET_SEL_PNTS_BY_FEATURE,
             PRO_E_HOLESET_SEL_AUTO_CHAMFER,
             PRO_E_HOLESET_SEL_INDIV_AXES,
             PRO_E_HOLESET_SEL_AXIS_PATTS,
             PRO_E_MFG_HSET_DRILL_GROUP_REF,
             PRO_E_HOLESET_SEL_BY_SURFACES,
             PRO_E_MFG_HSET_DIAM_ARR,
             PRO_E_MFG_HSET_PARAM_ARR.

Note-40 : Selection of surfaces (or quilts) with points.
          Element supports multiple selections.
          Optional for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).
          Ignored for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).


Note-41 : Selection of datum point features.
          Element supports multiple selections.
          Optional for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).
          Ignored for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES)

Note-42 : Selection of surfaces/quilts.
          Element supports multiple selections.
          Mandatory for five-axis holemaking (PRO_E_MFG_SEQ_NUM_AXES_OPT is
          set to 5) if at least one point selection is set for one of the 
          following elements:
             PRO_E_HOLESET_SEL_INDIV_PNTS,
             PRO_E_HOLESET_SEL_PNTS_BY_FEATURE.
          Only points placed on selected surface will be considered for 
          machining in the direction normal to the surface (at the location
          defined by the point).
          Ignored for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).

Note-43 : Accuracy used to determine whether a point lies on a surface.
          Mandatory for five-axis holemaking (PRO_E_MFG_SEQ_NUM_AXES_OPT is
          set to 5) if at least one point selection is set for one of the 
          following elements:
             PRO_E_HOLESET_SEL_INDIV_PNTS,
             PRO_E_HOLESET_SEL_PNTS_BY_FEATURE.
          Only points placed on selected surface will be considered for 
          machining in the direction normal to the surface (at the location
          defined by the point).
          Ignored for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).

Note-44 : Selection of points for holes to be excluded for machining.
          Element supports multiple selections.
          Optional for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).
          Ignored for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).

Note-45 : Selection of points.
          Element supports multiple selections.
          Mandatory for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS) if none of the following elements is 
          defined:
             PRO_E_HOLESET_SEL_PNTS_ON_SURFACES,
             PRO_E_HOLESET_SEL_PNTS_BY_FEATURE.
          Ignored for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES)


Note-46 : Auto chamfer option.

          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS)
          Optional for countersinking. Ignored for other types of holemaking.

          TRUE  - collect holes with chamfers matching chamfer angle with 
                  angle of cutting tool (see PRO_E_MFG_TOOL_REF_COMPOUND for 
                  tool reference).
          FALSE - do not collect holes by chamfer dimensions.

Note-47 : Selection of axes of patterned holes. 
          Element supports multiple selections.
	  If a pattern leader is selected, all holes in pattern
	     will be collected. 
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-48 : Selection of drill group features.
          Element supports multiple selections.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-49 : Selection of surfaces (or quilts) with holes.
          Element supports multiple selections.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-50 : Array of diameters of holes to machine.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-51 : Compound definition of a hole diameter.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-52 : Diameter of a hole to machine.
          Mandatory child of PRO_E_MFG_HSET_DIAM_COMPOUND element.

Note-53 : Array of search conditions to collect holes to machine.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-54 : Compound definition of a condition to match with hole features
          user defined parameters.
          Each condition defines expression with user defined parameter 
          name on the left side of the expression and value to compare on 
          the right side.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-55 : Name of user defined parameter.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element.

Note-56 : Data type of value.
          Values defined by ProParamvalueType.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element.

Note-57 : Type of expression operator.
          Values defined by ProDrillParamOper.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element.

Note-58 : Value of type double.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for double data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_DOUBLE).  Ignored for other data types.

Note-59 : Value of type integer.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for integer data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_INTEGER).  Ignored for other data types.

Note-60 : Value of type string.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for integer data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_STRING).  Ignored for other data types.

Note-61 : Value of type ProBoolean.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for integer data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_BOOLEAN).  Ignored for other data types.

Note-62 : Selection of axes of holes to be excluded for machining.
          Element supports multiple selections.
          Optional for axes holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_AXES).
          Ignored for points holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_POINTS).

Note-63 : Selection of datum axes.
          Element supports multiple selections.
          Mandatory for geometry holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_GEOM) if none of the following elements is 
          defined:
             PRO_E_HOLESET_SEL_AUTO_CHAMFER,
             PRO_E_HOLESET_SEL_AXIS_PATTS,
             PRO_E_MFG_HSET_DRILL_GROUP_REF,
             PRO_E_HOLESET_SEL_BY_SURFACES,
             PRO_E_MFG_HSET_DIAM_ARR,
             PRO_E_MFG_HSET_PARAM_ARR.
          Ignored for points holeset and geometry holeset.

Note-64 : Selection of holes to be excluded for machining.
          Element supports multiple selections.
          Optional for geometry holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_GEOM).
          Ignored for points holeset and axes holeset.

Note-65 : Selection of Holes.
          Element supports multiple selections.
          Mandatory for geometry holeset (PRO_E_HOLESET_TYPE is set to 
          PRO_HOLESET_DRILL_GEOMETRY) if none of the following elements is 
          defined:
             PRO_E_HOLESET_SEL_AUTO_CHAMFER,
             PRO_E_HOLESET_SEL_BY_SURFACES,
             PRO_E_MFG_HSET_DIAM_ARR.
          Ignored for points holeset and axis holeset.


Note-66 : Cutting tool control tip number - defines point on the cutting tool
          to be controlled during machining of the holeset. 
          Optional. First point of the tool will be used in element doesn't 
          exist.

Note-67 : Axis selection (for axes holeset) or point selection (for points 
          holeset) for the hole to be drilled first.
          Optional.

Note-68 : Axis selections for holes that should be drilled as per orientation 
          of the axis entities.
          Element supports multiple selections.
          For 5-axis holemaking the system will attempt (usually 
          successfully) to determine the appropriate machining approach 
          directions for all selected axes whose approach direction is not 
          specified by these elements. These elements therefore usually 
          do not need to be specified.  
          Optional for axes holeset for 5-axis holemaking.  Ignored in all 
          other cases.

Note-69 : Axis selections for holes that should be drilled in the direction
          opposite to the orientation of the axis entities.
          Element supports multiple selections.
          For 5-axis holemaking the system will attempt (usually 
          successfully) to determine the appropriate machining approach 
          directions for all selected axes whose approach direction is not 
          specified by these elements. These elements therefore usually 
          do not need to be specified.  
          Optional for axes holeset for 5-axis holemaking.  Ignored in all 
          other cases.

Note-70 : Machining direction option for 5-axis holemaking - away/toward the
          selected reference.
          Values defined by ProDrillOrientType.
          Optional for axes holeset for 5-axis holemaking.  Ignored in all 
          other cases.

Note-71 : Single reference selection (surface, point, axis) to define 
          direction of machining for 5-axis holemaking. System will determine
          direction of machining relatively to the selected reference (away 
          from the reference if PRO_E_HOLESET_ORIENT_TYPE is set to
          PRO_DRILL_ORIENT_TO_REF, or toward the refernce if it is set to
          PRO_DRILL_ORIENT_FROM_REF).
          Optional for axes holeset for 5-axis holemaking.  Ignored in all 
          other cases.

Note-72 : Drilling will start at this offset from sequence csys origin.
          Mandatory if PRO_E_HOLESET_START_TYPE is set to 
          PRO_DRILL_START_OFFSET_FROM_CSYS. Ignored in all other cases.

Note-73 : Drilling will end at this offset from sequence csys origin.
          Mandatory if PRO_E_HOLESET_END_TYPE is set to 
          PRO_DRILL_END_OFFSET_FROM_CSYS. Ignored in all other cases.

Note-74 : Custom cycle reference specification by offset value from start
          surface.
          Mandatory if PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT is set to 
          PRO_CUSTOM_DRILL_OFFSET_FROM_START. Ignored in all other cases.

Note-75 : Autodrilling information.
          Mandatory for autodrilling holesets.

Note-76 : Internal Use Only

Note-77 : For autodrilling holesets.
	  TRUE: Read depth information from autodrilling table.
          FALSE: Take depth information from holeset definition.
          Mandatory for autodrilling holesets.

Note-78 : Compound specification of gang tool properties.
          Optional

Note-79 : Parent step id. 
          Mandatory for gang tool specification.

Note-80 : TRUE  - Holeset is a leader of the gang tool.
          FALSE - Holeset is not a leader of the gang tool.
          Mandatory for gang tool specification.

Note-81 : Type of diameters collected in PRO_E_MFG_HSET_DIAM_ARR.
          Ignored for points holeset and geometry holeset.
          Values defined by ProHolesetDiamType.
          PRO_HSET_ALL_DIAMS - all diameter, including diameters of 
                               solid surfaces and diameters of 
                               cosmetic threads.
          PRO_HSET_HOLE_DIAMS - diameters of solid surfaces.
          PRO_HSET_THREAD_DIAMS - diameters of cosmetic threads.
          Optional (PRO_HSET_ALL_DIAMS is used if the element is not defined).

Note-82 : Type of query applied for search.
          Ignored for points holeset.
          Values defined by ProHsetParamRuleOpt.
          PRO_HSET_BOOL_OPER_OR  - Collects holes with at least one parameter.
          PRO_HSET_BOOL_OPER_AND - Collect holes with with combination of all 
                                   parameters.
          Optional (PRO_HSET_BOOL_OPER_OR is used if the element is not 
          defined).

=============================================================================*/



PRO_END_C_DECLS

#endif /* PROMFGELEMHOLESET_H */
