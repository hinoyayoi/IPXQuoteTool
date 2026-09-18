#ifndef PROMFGELEMTOOLMTNGOTOPNT_H
#define PROMFGELEMTOOLMTNGOTOPNT_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Goto Point" (PRO_TM_TYPE_GOTO_POINT). 
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
                  |-- PRO_E_TOOL_MTN_PNT_REF
                  |
                  |-- PRO_E_TOOL_MTN_OFFSET
                  |      |
                  |      |-- PRO_E_TOOL_MTN_X_OFFSET
                  |      |
                  |      |-- PRO_E_TOOL_MTN_Y_OFFSET
                  |      |
                  |      |-- PRO_E_TOOL_MTN_Z_OFFSET
                  |
                  |-- PRO_E_TOOL_MTN_AXIS_MOVES
                  |
                  |-- PRO_E_MFG_TM_TOOL_AXIS_COMPOUND
                         |
                         |-- PRO_E_MFG_TM_TOOL_AXIS_OPT
                         |
                         |-- PRO_E_MFG_TM_TOOL_AXIS_REF
                         |
                         |-- PRO_E_MFG_TM_TOOL_AXIS_FLIP_OPT

===============================================================================

(2) Elements table

---------------------------------------------------------------------------------------------
Element Id                       Element Name          Data Type                 Valid Values
---------------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                   Tool Motion           Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID            Tool Motion Id        PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE              Tool Motion Type      PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR              Mfg Parameter Array   Array                     Note-4
PRO_E_TOOL_MTN_PNT_REF           Point Reference       PRO_VALUE_TYPE_SELECTION  Note-5        
PRO_E_TOOL_MTN_OFFSET            Tool Motion Offset    Compound                  Note-6
PRO_E_TOOL_MTN_X_OFFSET          Tool Motion X Offset  PRO_VALUE_TYPE_DOUBLE     Note-7 
PRO_E_TOOL_MTN_Y_OFFSET          Tool Motion Y Offset  PRO_VALUE_TYPE_DOUBLE     Note-8 
PRO_E_TOOL_MTN_Z_OFFSET          Tool Motion Z Offset  PRO_VALUE_TYPE_DOUBLE     Note-9 
PRO_E_TOOL_MTN_AXIS_MOVES        Axis Move Attributs   PRO_VALUE_TYPE_INT        Note-10
PRO_E_MFG_TM_TOOL_AXIS_COMPOUND  Tool Axis             Compound                  Note-11
PRO_E_MFG_TM_TOOL_AXIS_OPT       Tool Axis Option      PRO_VALUE_TYPE_INT        Note-12
PRO_E_MFG_TM_TOOL_AXIS_REF       Tool Axis Reference   PRO_VALUE_TYPE_SELECTION  Note-13
PRO_E_MFG_TM_TOOL_AXIS_FLIP_OPT  Tool Axis Flip Option PRO_VALUE_TYPE_INT        Note-14
PRO_E_TOOL_MTN_FEED_TYPE         Tool Motion Feed Type PRO_VALUE_TYPE_INT        Note-15
=============================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_GOTO_POINT
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-5  : Datum point reference.
          Mandatory.

Note-6  : Offset.
          Optional.
          
Note-7  : Offset along X-axis.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.

Note-8  : Offset along Y-axis.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.
          
Note-9  : Offset along Z-axis.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.
          
Note-10 : Mandatory if PRO_E_TOOL_MTN_OFFSET is defined.

Note-11 : Tool Axis.
          Optional.
          
Note-12 : Tool Axis Option.
          Values defined by ProTmToolAxisOpt: 
          PRO_TM_ALONG_Z,
          PRO_TM_USE_PREV,
          PRO_TM_AXIS_SEL.
          Optional.
          
Note-13 : Axis selection. 
          Mandatory if PRO_E_MFG_TM_TOOL_AXIS_OPT is set to PRO_TM_AXIS_SEL.
          
Note-14 : Flip Option:
          TRUE or FALSE;
          Mandatory if PRO_E_MFG_TM_TOOL_AXIS_OPT is set to PRO_TM_AXIS_SEL.
          
Note-15 : Type of feed type.
          Values defined by ProToolMtnFeedType.
          PRO_TM_FEED_FREE     - free feed type.
          PRO_TM_FEED_CUT      - cut feed type.
          PRO_TM_FEED_PLUNGE   - plunge feed type.
          PRO_TM_FEED_RETRACT  - retract feed type.
          PRO_TM_FEED_APPROACH - approach feed type.
          PRO_TM_FEED_EXIT     - exit feed type.
          Optional.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNGOTOPNT_H */
