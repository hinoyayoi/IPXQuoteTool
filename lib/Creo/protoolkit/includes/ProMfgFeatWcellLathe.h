#ifndef PROMFGFEATWCELLLATHE_H
#define PROMFGFEATWCELLLATHE_H
/*
   Creo Parametric TOOLKIT declarations related to mfg lathe workcell.
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
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-7
PRO_E_MFG_WCELL_HEAD_1          Tool Head 1          Compound                  Note-8
PRO_E_MFG_WCELL_HEAD_2          Tool Head 2          Compound                  Note-9
PRO_E_MFG_WCELL_TOOL_SETUP_ARR  Tool Setup Array     Array                     Note-10
PRO_E_MFG_WCELL_CMM_HEAD        CMM Tool Head        Compound                  Note-11
PRO_E_MFG_CMM_TOOL_SETUP_ARR    CMM Tool Setup Array Array                     Note-12
PRO_E_MFG_WCELL_CUST_CYCLE_ARR  Custom Cycles Array  Array                     Note-13
PRO_E_MFG_WCELL_CUST_CYCLE_COMP Cycle Name Compound  Compound                  Note-14
PRO_E_MFG_WCELL_CUST_CYCLE_NAME Cycle Name           PRO_VALUE_TYPE_WSTRING    Note-15
PRO_E_MFG_WCELL_ASSEM_COMPOUND  Assembly Compound    Compound                  Note-16
PRO_E_MFG_WCELL_ASSEMBLY_NAME   Assembly Name        PRO_VALUE_TYPE_WSTRING    Note-17
PRO_E_MFG_WCELL_LOCAL_CSYS_REF  Csys reference       PRO_VALUE_TYPE_SELECTION  Note-18
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-19
PRO_E_MFG_WCELL_NUM_SPINDLES    Num Spindles         PRO_VALUE_TYPE_INT        Note-20

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_WORKCELL
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : PRO_WCELL_LATHE
          Mandatory.

Note-4  : Number of tool heads (turrets) - one head/two heads.
          Values defined by ProMfgWcellNumHeads.
          Optional (if not defined - PRO_MFG_ONE_HEAD_WCELL is set 
          by default)

Note-5  : Lathe orientation (horizontal/vertical).
          Values defined by ProWcellLatheDir.
          Optional (if not defined - PRO_WCELL_LATHE_HORIZONTAL is 
          set by default)

Note-6  : PRO_B_TRUE  - enables tool head with CMM probes and allows 
                        creation of CMM sequences.
          PRO_B_FALSE - disables CMM tool head and creation of CMM 
                        sequences.
          Optional (if not defined - CMM tool head is disabled).

Note-7  : Array of applicable manufacturing parameters.
          Optional.

          For new features: if the parameter array is not specified - default
          values are going to be assigned to the corresponding manufacturing
          parameters of the created feature.

          Please see ProMfgElemParam.h.

Note-8  : Tool head 1 compound.
          Optional.

Note-9  : Tool head 2 compound.
          Optional. Ingnored if PRO_E_MFG_WCELL_NUM_HEADS set to
          PRO_MFG_ONE_HEAD_WCELL.

Note-10 : Tool setup array.
          Please see ProMfgElemToolSetup.h
          Optional.

Note-11 : CMM probes head compound.
          Optional. Ingnored if PRO_E_MFG_ENABLE_CMM_OPT set to
          PRO_B_FALSE.

Note-12 : CMM probes setup array.
          Please see ProMfgElemToolSetupCmm.h
          Optional.

Note-13 : Array of custom cycle names (to be used by holemaking 
          sequences).
          Optional.

Note-14 : Compound definition of a custom cycle name.
          Optional.

Note-15 : Custom cycle name.
          Mandatory child of PRO_E_MFG_WCELL_CUST_CYCLE_COMP element.

Note-16 : Simulation assembly compound definition.
          Optional.

Note-17 : Simulation assembly model name.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-18 : Coordinate system datum feature. It will be alligned with
          simulation assembly coordinate system during machining
          simulation.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-19 : Workcell comments.

Note-20 : Number of spindles.
          Values defined by ProMfgWcellNumSpindles.
          Optional (if not defined - PRO_MFG_ONE_SPINDLE_WCELL is set 
          by default)
 

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATWCELLLATHE_H */
