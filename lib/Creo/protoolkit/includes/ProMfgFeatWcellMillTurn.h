#ifndef PROMFGFEATWCELLMILLTURN_H
#define PROMFGFEATWCELLMILLTURN_H
/*
   Creo Parametric TOOLKIT declarations related to mfg mill-turn workcell.
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
    |-- PRO_E_WCELL_TYPE
    |
    |-- PRO_E_MFG_WCELL_NUM_HEADS
    |
    |-- PRO_E_MFG_WCELL_NUM_SPINDLES
    |
    |-- PRO_E_MFG_LATHE_DIR_OPT
    |
    |-- PRO_E_MFG_ENABLE_CMM_OPT
    |
    |-- PRO_E_MFG_WCELL_ENABLE_TURN_OPT
    |
    |-- PRO_E_MFG_WCELL_NUM_AXES
    |
    |-- PRO_E_MFG_MILLTURN_HEADS
    |       |
    |       |--PRO_E_MFG_MILLTURN_HEAD_1
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_MILL_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_TURN_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_BELOW_CLINE
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_FLASH_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_ROT_POS_OPT
    |       |
    |       |--PRO_E_MFG_MILLTURN_HEAD_2
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_MILL_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_TURN_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_BELOW_CLINE
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_FLASH_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_ROT_POS_OPT
    |       |       
    |       |--PRO_E_MFG_MILLTURN_HEAD_3
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_MILL_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_TURN_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_BELOW_CLINE
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_FLASH_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_ROT_POS_OPT
    |       |       
    |       |--PRO_E_MFG_MILLTURN_HEAD_4
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_MILL_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_TURN_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_BELOW_CLINE
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_FLASH_OPT
    |       |      |
    |       |      |--PRO_E_WCELL_HEAD_ROT_POS_OPT
    |       |
    |       |--PRO_E_MILLTURN_TOOL_ROT_DIR_OPT
    |
    |-- PRO_E_MFG_PARAM_ARR
    |
    |-- PRO_E_MFG_WCELL_HEAD_1
    |      |
    |      |-- PRO_E_MFG_WCELL_TOOL_SETUP_ARR
    |
    |-- PRO_E_MFG_WCELL_HEAD_2
    |      |
    |      |-- PRO_E_MFG_WCELL_TOOL_SETUP_ARR
    |
    |-- PRO_E_MFG_WCELL_HEAD_3
    |      |
    |      |-- PRO_E_MFG_WCELL_TOOL_SETUP_ARR
    |
    |-- PRO_E_MFG_WCELL_HEAD_4
    |      |
    |      |-- PRO_E_MFG_WCELL_TOOL_SETUP_ARR
    |
    |-- PRO_E_MFG_WCELL_CMM_HEAD
    |      |
    |      |-- PRO_E_MFG_CMM_TOOL_SETUP_ARR
    |
    |-- PRO_E_MFG_WCELL_CUST_CYCLE_ARR
    |      |
    |      |-- PRO_E_MFG_WCELL_CUST_CYCLE_COMP
    |             |
    |             |-- PRO_E_MFG_WCELL_CUST_CYCLE_NAME
    | 
    |-- PRO_E_MFG_WCELL_ASSEM_COMPOUND
    |      |
    |      |-- PRO_E_MFG_WCELL_ASSEMBLY_NAME
    |      |
    |      |-- PRO_E_MFG_WCELL_LOCAL_CSYS_REF
    |
    |-- PRO_E_MFG_COMMENTS

===============================================================================

(2) Elements table

-------------------------------------------------------------------------------------------
Element Id                      Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME          Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_WCELL_TYPE                Workcell Type        PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_WCELL_NUM_HEADS       Number of Heads      PRO_VALUE_TYPE_INT        Note-4
PRO_E_MFG_LATHE_DIR_OPT         Lathe Orientation    PRO_VALUE_TYPE_INT        Note-5
PRO_E_MFG_ENABLE_CMM_OPT        Enable CMM           PRO_VALUE_TYPE_INT        Note-6
PRO_E_MFG_WCELL_NUM_AXES        Number of Axes       PRO_VALUE_TYPE_INT        Note-7
PRO_E_MFG_MILLTURN_HEADS        Turret Options       Compound                  Note-8
PRO_E_MFG_MILLTURN_HEAD_1       Turret 1 Options     Compound                  Note-9
PRO_E_WCELL_HEAD_MILL_OPT       Mill Tool Option     PRO_VALUE_TYPE_INT        Note-10
PRO_E_WCELL_HEAD_FLASH_OPT      Flash Tool Option    PRO_VALUE_TYPE_INT        Note-11
PRO_E_WCELL_HEAD_ROT_POS_OPT    Rotation Option      PRO_VALUE_TYPE_INT        Note-12
PRO_E_MFG_MILLTURN_HEAD_2       Turret 2 Options     Compound                  Note-13
PRO_E_MILLTURN_TOOL_ROT_DIR_OPT Rotation Direction   PRO_VALUE_TYPE_INT        Note-14
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-15
PRO_E_MFG_WCELL_HEAD_1          Head 1 Tools         Compound                  Note-16
PRO_E_MFG_WCELL_HEAD_2          Head 2 Tools         Compound                  Note-17
PRO_E_MFG_WCELL_TOOL_SETUP_ARR  Tool Setup Array     Array                     Note-18
PRO_E_MFG_WCELL_CMM_HEAD        CMM Tool Head        Compound                  Note-19
PRO_E_MFG_CMM_TOOL_SETUP_ARR    CMM Tool Setup Array Array                     Note-20
PRO_E_MFG_WCELL_CUST_CYCLE_ARR  Custom Cycles Array  Array                     Note-21
PRO_E_MFG_WCELL_CUST_CYCLE_COMP Cycle Name Compound  Compound                  Note-22
PRO_E_MFG_WCELL_CUST_CYCLE_NAME Cycle Name           PRO_VALUE_TYPE_WSTRING    Note-23
PRO_E_MFG_WCELL_ASSEM_COMPOUND  Assembly Compound    Compound                  Note-24
PRO_E_MFG_WCELL_ASSEMBLY_NAME   Assembly Name        PRO_VALUE_TYPE_WSTRING    Note-25
PRO_E_MFG_WCELL_LOCAL_CSYS_REF  Csys reference       PRO_VALUE_TYPE_SELECTION  Note-26
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-27
PRO_E_MFG_WCELL_NUM_SPINDLES    Num Spindles         PRO_VALUE_TYPE_INT        Note-28
PRO_E_MFG_WCELL_ENABLE_TURN_OPT Enable Turning       PRO_VALUE_TYPE_INT        Note-29
PRO_E_MFG_MILLTURN_HEAD_3       Turret 3 Options     Compound                  Note-30
PRO_E_MFG_MILLTURN_HEAD_4       Turret 4 Options     Compound                  Note-31
PRO_E_WCELL_HEAD_TURN_OPT       Turning Tool Option  PRO_VALUE_TYPE_INT        Note-32
PRO_E_MFG_WCELL_HEAD_3          Head 3 Tools         Compound                  Note-33
PRO_E_MFG_WCELL_HEAD_4          Head 4 Tools         Compound                  Note-34
PRO_E_WCELL_HEAD_BELOW_CLINE    Below Centerline     PRO_VALUE_TYPE_INT        Note-35

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_WORKCELL
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : PRO_WCELL_MILL_N_TRN
          Mandatory.

Note-4  : Number of tool heads (turrets) - one/two/three/four heads.
          Values defined by ProMfgWcellNumHeads.
          Optional (if not defined - PRO_MFG_ONE_HEAD_WCELL is set 
          by default).

Note-5  : Lathe orientation (horizontal/vertical).
          Values defined by ProWcellLatheDir.
          Optional (if not defined - PRO_WCELL_LATHE_HORIZONTAL is 
          set by default)

Note-6  : PRO_B_TRUE  - enables tool head with CMM probes and allows 
                        creation of CMM sequences.
          PRO_B_FALSE - disables CMM tool head and creation of CMM 
                        sequences.
          Optional (if not defined - CMM tool head is disabled).

Note-7  : Number of controlled axes enabled for milling sequences:
          PRO_WCELL_3_AXIS, PRO_WCELL_4_AXIS, PRO_WCELL_5_AXIS.
          Mandatory.

Note-8  : Turrets options compound
          Optional.

Note-9  : Turret 1 options compound
          Optional.

Note-10 : Turret milling option.
          PRO_B_TRUE  - milling operations enabled  for turret.
          PRO_B_FALSE - milling operations disabled for turret.
          Optional. If not defined - turning by the turret is disabled.

Note-11 : Turret flash tool option.
          PRO_B_TRUE  - flash tool enabled for  turret.
          PRO_B_FALSE - flash tool disabled for turret.
          Optional.

Note-12 : Turret rotation positioning option.
          PRO_B_TRUE  - rotation positioning enabled  for turret.
          PRO_B_FALSE - rotation positioning disabled for turret.
          Optional.

Note-13 : Turret 2 options compound
          Optional. Ignored if PRO_E_MFG_WCELL_NUM_HEADS set to
          PRO_MFG_ONE_HEAD_WCELL.

Note-14 : Turrets rotation positioning direction (standard/reverse).
          PRO_B_TRUE  - standard direction enabled for both turrets.
          PRO_B_FALSE - reverse  direction enabled for both turrets.
          Ignored if PRO_E_WCELL_HEAD_ROT_POS_OPT set to PRO_B_FALSE
          for both heads.
          Optional.

Note-15 : Array of applicable manufacturing parameters.
          Optional.

          For new features: if the parameter array is not specified - default
          values are going to be assigned to the corresponding manufacturing
          parameters of the created feature.

          Please see ProMfgElemParam.h.

Note-16 : Tools specification for head 1.
          Optional.

Note-17 : Tools specification for head 2.
          Optional. Ignored if PRO_E_MFG_WCELL_NUM_HEADS set to
          PRO_MFG_ONE_HEAD_WCELL.

Note-18 : Tool setup array.
          Please see ProMfgElemToolSetup.h
          Optional.

Note-19 : CMM probes head compound.
          Optional. Ignored if PRO_E_MFG_ENABLE_CMM_OPT set to
          PRO_B_FALSE.

Note-20 : CMM probes setup array.
          Please see ProMfgElemToolSetupCmm.h
          Optional.

Note-21 : Array of custom cycle names (to be used by holemaking 
          sequences).
          Optional.

Note-22 : Compound definition of a custom cycle name.
          Optional.

Note-23 : Custom cycle name.
          Mandatory child of PRO_E_MFG_WCELL_CUST_CYCLE_COMP element.

Note-24 : Simulation assembly compound definition.
          Optional.

Note-25 : Simulation assembly model name.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-26 : Coordinate system datum feature. It will be alligned with
          simulation assembly coordinate system during machining
          simulation.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-27 : Workcell comments.

Note-28 : Number of spindles.
          Values defined by ProMfgWcellNumSpindles.
          Optional (if not defined - PRO_MFG_ONE_SPINDLE_WCELL is set
          by default)

Note-29 : PRO_B_TRUE  - enables turning machining on the workcell.
          PRO_B_FALSE - disables turning machining on the workcell.
          Optional. If not defined - turning is enabled.

Note-30 : Turret 3 options compound
          Optional.

Note-31 : Turret 4 options compound
          Optional.

Note-32 : Turret turning option.
          PRO_B_TRUE  - turning operations enabled  for the turret.
          PRO_B_FALSE - turning operations disabled for the turret.
          Optional. If not defined - turning is enabled for the turret.
          Ignored if PRO_E_MFG_WCELL_ENABLE_TURN_OPT set to PRO_B_FALSE.

Note-33 : Tools specification for head 3.
          Optional. Ignored for workcells with number of heads less than 3 
          (PRO_E_MFG_WCELL_NUM_HEADS set to PRO_MFG_ONE_HEAD_WCELL or 
          PRO_MFG_TWO_HEAD_WCELL).

Note-34 : Tools specification for head 4.
          Optional. Ignored for workcells with number of heads less than 4 
          (PRO_E_MFG_WCELL_NUM_HEADS set to PRO_MFG_ONE_HEAD_WCELL,
          PRO_MFG_TWO_HEAD_WCELL or PRO_MFG_THREE_HEAD_WCELL).

Note-35 : Turret below centerline option.
          PRO_B_TRUE  - turning below the spindle centerline is enabled.
          PRO_B_FALSE - turning below the spindle centerline is disabled.
          Optional.

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATWCELLMILLTURN_H */
