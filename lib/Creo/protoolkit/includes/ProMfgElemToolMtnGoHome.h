#ifndef PROMFGELEMTOOLMTNGOHOME_H
#define PROMFGELEMTOOLMTNGOHOME_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Go Home" (PRO_TM_TYPE_GOHOME). 
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
                  |-- PRO_E_TOOL_MTN_FEED_TYPE
                  |
                  |-- PRO_E_MFG_PARAM_ARR
                  |
                  |-- PRO_E_TOOL_MTN_AXIS_REF

===============================================================================

(2) Elements table

---------------------------------------------------------------------------------------
Element Id                 Element Name          Data Type                 Valid Values
---------------------------------------------------------------------------------------
PRO_E_TOOL_MTN             Tool Motion           Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID      Tool Motion Id        PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE        Tool Motion Type      PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR        Mfg Parameter Array   Array                     Note-4
PRO_E_TOOL_MTN_AXIS_REF    Axis Reference        PRO_VALUE_TYPE_SELECTION  Note-5        
PRO_E_TOOL_MTN_FEED_TYPE   Tool Motion Feed Type PRO_VALUE_TYPE_INT        Note-6

===============================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_GOHOME
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-5  : Axis selection. Optional for 5-axis nc sequences.
          By default Z-axis of the nc sequence is used to define 
          the constraint plane. For 5-axis nc sequences an user can
          select an alternative axis.

Note-6  : Type of feed type.
          Values defined by ProToolMtnFeedType.
          PRO_TM_FEED_FREE     - free feed type.
          PRO_TM_FEED_CUT      - cut feed type.
          PRO_TM_FEED_RETRACT  - retract feed type.
          PRO_TM_FEED_EXIT     - exit feed type.
          Optional.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNGOHOME_H */
