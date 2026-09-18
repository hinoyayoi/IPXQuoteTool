#ifndef PROMFGFEATWCELLMILL_H
#define PROMFGFEATWCELLMILL_H
/*
   Creo Parametric TOOLKIT declarations related to mfg mill workcell.
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
    |-- PRO_E_MFG_WCELL_NUM_AXES
    |
    |-- PRO_E_MFG_ENABLE_CMM_OPT
    |
    |-- PRO_E_MFG_PARAM_ARR
    |
    |-- PRO_E_MFG_WCELL_HEAD_1
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
PRO_E_MFG_WCELL_NUM_AXES        Number of Axes       PRO_VALUE_TYPE_INT        Note-4
PRO_E_MFG_ENABLE_CMM_OPT        Enable CMM           PRO_VALUE_TYPE_INT        Note-5
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-6
PRO_E_MFG_WCELL_HEAD_1          Tool Head 1          Compound                  Note-7
PRO_E_MFG_WCELL_TOOL_SETUP_ARR  Tool Setup Array     Array                     Note-8
PRO_E_MFG_WCELL_CMM_HEAD        CMM Tool Head        Compound                  Note-9
PRO_E_MFG_CMM_TOOL_SETUP_ARR    CMM Tool Setup Array Array                     Note-10
PRO_E_MFG_WCELL_CUST_CYCLE_ARR  Custom Cycles Array  Array                     Note-11
PRO_E_MFG_WCELL_CUST_CYCLE_COMP Cycle Name Compound  Compound                  Note-12
PRO_E_MFG_WCELL_CUST_CYCLE_NAME Cycle Name           PRO_VALUE_TYPE_WSTRING    Note-13
PRO_E_MFG_WCELL_ASSEM_COMPOUND  Assembly Compound    Compound                  Note-14
PRO_E_MFG_WCELL_ASSEMBLY_NAME   Assembly Name        PRO_VALUE_TYPE_WSTRING    Note-15
PRO_E_MFG_WCELL_LOCAL_CSYS_REF  Csys reference       PRO_VALUE_TYPE_SELECTION  Note-16
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-17

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_WORKCELL
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : PRO_WCELL_MILL
          Mandatory.

Note-4  : Number of controlled axes (number of programmable motion directions):
          PRO_WCELL_3_AXIS, PRO_WCELL_4_AXIS, PRO_WCELL_5_AXIS.
          Mandatory.

Note-5  : PRO_B_TRUE  - enables tool head with CMM probes and allows 
                        creation of CMM sequences.
          PRO_B_FALSE - disables CMM tool head and creation of CMM 
                        sequences.
          Optional (if not defined - CMM tool head is disabled).

Note-6  : Array of applicable manufacturing parameters.
          Optional.

          For new features: if the parameter array is not specified - default
          values are going to be assigned to the corresponding manufacturing
          parameters of the created feature.

          Please see ProMfgElemParam.h.

Note-7  : Tool head compound.
          Optional.

Note-8  : Tool setup array.
          Please see ProMfgElemToolSetup.h
          Optional.

Note-9  : CMM probes head compound.
          Optional. Ingnored if PRO_E_MFG_ENABLE_CMM_OPT set to
          PRO_B_FALSE.

Note-10 : CMM probes setup array.
          Please see ProMfgElemToolSetupCmm.h
          Optional.

Note-11 : Array of custom cycle names (to be used by holemaking 
          sequences).
          Optional.

Note-12 : Compound definition of a custom cycle name.
          Optional.

Note-13 : Custom cycle name.
          Mandatory child of PRO_E_MFG_WCELL_CUST_CYCLE_COMP element.

Note-14 : Simulation assembly compound definition.
          Optional.

Note-15 : Simulation assembly model name.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-16 : Coordinate system datum feature. It will be alligned with
          simulation assembly coordinate system during machining
          simulation.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-17 : Workcell comments.

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATWCELLMILL_H */
