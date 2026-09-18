#ifndef PROMFGFEATWCELLCMM_H
#define PROMFGFEATWCELLCMM_H
/*
   Creo Parametric TOOLKIT declarations related to mfg CMM workcell.
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
    |-- PRO_E_MFG_PARAM_ARR
    |
    |-- PRO_E_MFG_WCELL_CMM_HEAD
    |      |
    |      |-- PRO_E_MFG_CMM_TOOL_SETUP_ARR
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
PRO_E_MFG_PARAM_ARR             Mfg Parameter Array  Array                     Note-4
PRO_E_MFG_WCELL_CMM_HEAD        CMM Tool Head        Compound                  Note-5
PRO_E_MFG_CMM_TOOL_SETUP_ARR    CMM Tool Setup Array Array                     Note-6
PRO_E_MFG_WCELL_ASSEM_COMPOUND  Assembly Compound    Compound                  Note-7 
PRO_E_MFG_WCELL_ASSEMBLY_NAME   Assembly Name        PRO_VALUE_TYPE_WSTRING    Note-8
PRO_E_MFG_WCELL_LOCAL_CSYS_REF  Csys reference       PRO_VALUE_TYPE_SELECTION  Note-9 
PRO_E_MFG_COMMENTS              Comments             PRO_VALUE_TYPE_WSTRING    Note-10

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_WORKCELL
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : PRO_WCELL_CMM
          Mandatory.

Note-4  : Array of applicable manufacturing parameters.
          Optional.

          For new features: if the parameter array is not specified - default
          values are going to be assigned to the corresponding manufacturing
          parameters of the created feature.

          Please see ProMfgElemParam.h.

Note-5  : CMM probes head compound.
          Optional.

Note-6  : CMM probes setup array.
          Please see ProMfgElemToolSetupCmm.h
          Optional.

Note-7  : Simulation assembly compound definition.
          Optional.

Note-8  : Simulation assembly model name.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-9  : Coordinate system datum feature. It will be alligned with
          simulation assembly coordinate system during machining
          simulation.
          Mandatory child of PRO_E_MFG_WCELL_ASSEM_COMPOUND element.

Note-10 : Workcell comments.

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATWCELLCMM_H */
