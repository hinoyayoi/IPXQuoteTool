#ifndef PROMFGELEMTOOLMTNPROFILEMILLCUT_H
#define PROMFGELEMTOOLMTNPROFILEMILLCUT_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Profile Mill Cut" (PRO_TM_TYPE_PROFILE_MILL_CUT). 
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
          |-- PRO_E_TOOL_MTN_PROFILE_TYPE
          |
          |-- PRO_E_MFG_PARAM_ARR
          |
          |-- PRO_E_MFG_CMP_APPROACH_EXIT
          |
          |-- PRO_E_MFG_START_HEIGHT
          |
          |-- PRO_E_MFG_HEIGHT

===============================================================================

(2) Elements table

----------------------------------------------------------------------------------------------
Element Id                    Element Name              Data Type                 Valid Values
----------------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                Tool Motion               Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID         Tool Motion Id            PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE           Tool Motion Type          PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR           Mfg Parameter Array       Array                     Note-4
PRO_E_MFG_CMP_APPROACH_EXIT   Approach/Exit             Compound                  Note-5
PRO_E_MFG_START_HEIGHT        Start Height              PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_MFG_HEIGHT              Height                    PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_TOOL_MTN_PROFILE_TYPE   Profile Cut Condition     PRO_VALUE_TYPE_INT        Note-8
==============================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_PROFILE_MILL_CUT.
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Optional. Inherited from NC Sequence if not specified.

Note-5  : Approach and exit compound definition.
          Please see ProMfgElemApproachExit.h.
          Optional.

Note-6  : Start height. Selection of a horizontal surface
          Mandatory if PRO_E_TOOL_MTN_PROFILE_TYPE is set to PRO_E_MILL_CUT_FROM_TO.
          Ignored otherwise.

Note-7  : Height. Single surface selection.
          Mandatory if PRO_E_TOOL_MTN_PROFILE_TYPE is set to PRO_E_MILL_CUT_FROM_TO,
          or PRO_E_MILL_CUT_UPTO, or PRO_E_MILL_CUT_ONE_SLICE. 
          Ignored otherwise.

Note-8  : Tool motion profile type - defined by Pro_MillProfCutType.


==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNPROFILEMILLCUT_H */
