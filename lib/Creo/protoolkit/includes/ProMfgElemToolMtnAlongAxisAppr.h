#ifndef PROMFGELEMTOOLMTNALONGAXISAPPR_H
#define PROMFGELEMTOOLMTNALONGAXISAPPR_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Approach Along Tool Axis" (PRO_TM_TYPE_ALONG_AXIS_APPROACH). 
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

===============================================================================

(2) Elements table

---------------------------------------------------------------------------------------
Element Id                 Element Name          Data Type                 Valid Values
---------------------------------------------------------------------------------------
PRO_E_TOOL_MTN             Tool Motion           Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID      Tool Motion Id        PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE        Tool Motion Type      PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR        Mfg Parameter Array   Array                     Note-4
PRO_E_TOOL_MTN_FEED_TYPE   Tool Motion Feed Type PRO_VALUE_TYPE_INT        Note-5

===============================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_ALONG_AXIS_APPROACH
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-5  : Type of feed type.
          Values defined by ProToolMtnFeedType.
          PRO_TM_FEED_FREE     - free feed type.
          PRO_TM_FEED_CUT      - cut feed type.
          PRO_TM_FEED_PLUNGE   - plunge feed type.
          PRO_TM_FEED_APPROACH - approach feed type.
          Optional.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNALONGAXISAPPR_H */
