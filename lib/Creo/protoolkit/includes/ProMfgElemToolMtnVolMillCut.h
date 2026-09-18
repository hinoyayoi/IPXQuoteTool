#ifndef PROMFGELEMTOOLMTNVOLMILLCUT_H
#define PROMFGELEMTOOLMTNVOLMILLCUT_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Volume Mill Cut" (PRO_TM_TYPE_VOLUME_MILLING). 
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
          |
          |-- PRO_E_VOL_MILL_REGION_ARR
                 |
                 |-- PRO_E_VOL_MILL_REGION
                        |
                        |-- PRO_E_VOL_MILL_REGION_IDX
                        |
                        |-- PRO_E_VOL_MILL_REGION_SKIP_OPT
                        |
                        |-- PRO_E_VOL_MILL_AP_REF
                        |
                        |-- PRO_E_VOL_MILL_EX_REF

===============================================================================

(2) Elements table

----------------------------------------------------------------------------------------------
Element Id                     Element Name             Data Type                 Valid Values
----------------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                 Tool Motion              Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID          Tool Motion Id           PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE            Tool Motion Type         PRO_VALUE_TYPE_INT        Note-3
PRO_E_TOOL_MTN_PROFILE_TYPE    Profile Cut Condition    PRO_VALUE_TYPE_INT        Note-4
PRO_E_MFG_PARAM_ARR            Mfg Parameter Array      Array                     Note-5
PRO_E_MFG_CMP_APPROACH_EXIT    Approach/Exit            Compound                  Note-6
PRO_E_MFG_START_HEIGHT         Start Height             PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_MFG_HEIGHT               Height                   PRO_VALUE_TYPE_SELECTION  Note-8
PRO_E_VOL_MILL_REGION_ARR      Region Array             Array                     Note-9
PRO_E_VOL_MILL_REGION          Region                   Compound                  Note-10
PRO_E_VOL_MILL_REGION_IDX      Region Index             PRO_VALUE_TYPE_INT        Note-11
PRO_E_VOL_MILL_REGION_SKIP_OPT Skip Option              PRO_VALUE_TYPE_INT        Note-12
PRO_E_VOL_MILL_AP_REF          Approach Reference       PRO_VALUE_TYPE_SELECTION  Note-13
PRO_E_VOL_MILL_EX_REF          Exit Reference           PRO_VALUE_TYPE_SELECTION  Note-14
==============================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_VOLUME_MILLING.
          Mandatory.

Note-4  : Tool motion cut type.
          PRO_E_MILL_CUT_FULL_DEPTH - full depth is machined.
          PRO_E_MILL_CUT_FROM_TO    - depth of machining is limited by "start" and "end" 
                                      references (see Note-7 and Note-8).
          PRO_E_MILL_CUT_UPTO       - depth of machining is limited by "end" reference
                                      (see Note-8).
          PRO_E_MILL_CUT_ONE_SLICE  - single slice cut.

Note-5  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Optional. Inherited from NC Sequence if not specified.

Note-6  : Approach and exit compound definition.
          Please see ProMfgElemApproachExit.h.
          Optional.

Note-7  : Start height. Selection of a horizontal surface
          Mandatory if PRO_E_TOOL_MTN_PROFILE_TYPE is set to PRO_E_MILL_CUT_FROM_TO.
          Ignored otherwise.

Note-8  : Height. Single surface selection.
          Mandatory if PRO_E_TOOL_MTN_PROFILE_TYPE is set to PRO_E_MILL_CUT_FROM_TO,
          or PRO_E_MILL_CUT_UPTO, or PRO_E_MILL_CUT_ONE_SLICE. Ignored otherwise.

Note-9  : Array of region specifications. Can be defined to overwrite the default order 
          of machinining of different areas.
          Optional.

Note-10 : Region compound definition.

Note-11 : Region id.
          Internal use only. Should not be added or modified.

Note-12 : Skip option.  
          PRO_B_TRUE  - region will be skipped.
          PRO_B_FALSE - region will not be skipped.
          Optional.

Note-13 : Selection of a vertical datum axis, or a datum point. 
          Defines a location of an approach move to the region.
          Optional.

Note-14 : Selection of a vertical datum axis, or a datum point.
          Defines a location of an exit move from the region.
          Optional.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNVOLMILLCUT_H */
