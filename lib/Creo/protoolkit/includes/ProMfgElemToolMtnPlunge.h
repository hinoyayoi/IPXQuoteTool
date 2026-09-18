#ifndef PROMFGELEMTOOLMTNPLUNGE_H
#define PROMFGELEMTOOLMTNPLUNGE_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Plunge" (PRO_TM_TYPE_PLUNGE). 
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
                  |-- PRO_E_TOOL_MTN_OFFSET
                  |      |
                  |      |-- PRO_E_TOOL_MTN_X_OFFSET
                  |      |
                  |      |-- PRO_E_TOOL_MTN_Y_OFFSET
                  |      |
                  |      |-- PRO_E_TOOL_MTN_Z_OFFSET
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
PRO_E_TOOL_MTN_OFFSET      Tool Motion Offset    Compound                  Note-5
PRO_E_TOOL_MTN_X_OFFSET    Tool Motion X Offset  PRO_VALUE_TYPE_DOUBLE     Note-6 
PRO_E_TOOL_MTN_Y_OFFSET    Tool Motion Y Offset  PRO_VALUE_TYPE_DOUBLE     Note-7 
PRO_E_TOOL_MTN_Z_OFFSET    Tool Motion Z Offset  PRO_VALUE_TYPE_DOUBLE     Note-8 
PRO_E_TOOL_MTN_AXIS_REF    Axis Reference        PRO_VALUE_TYPE_SELECTION  Note-9        
PRO_E_TOOL_MTN_FEED_TYPE   Tool Motion Feed Type PRO_VALUE_TYPE_INT        Note-10

===============================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_PLUNGE
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          CLEAR_DIST is used to define Plunge Motion. Please see ProMfgElemParam.h.
          Mandatory.

Note-5  : Offset.
          Optional.
          
Note-6  : Offset along X-axis.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.

Note-7  : Offset along Y-axis.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.
          
Note-8  : Offset along Z-axis.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.
          
Note-9  : Axis selection.
          By default Z-axis of the nc sequence is used to define 
          the constraint plane.
          Optional.

Note-10 : Type of feed type.
          Values defined by ProToolMtnFeedType.
          PRO_TM_FEED_FREE     - free feed type.
          PRO_TM_FEED_CUT      - cut feed type.
          PRO_TM_FEED_PLUNGE   - plunge feed type.
          Optional.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNPLUNGE_H */
