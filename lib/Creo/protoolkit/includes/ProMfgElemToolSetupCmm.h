#ifndef PROMFGELEMTOOLSETUPCMM_H
#define PROMFGELEMTOOLSETUPCMM_H
/*
   Creo Parametric TOOLKIT declarations related to CMM probes setup specification.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
     
   -- PRO_E_MFG_CMM_TOOL_SETUP_ARR
         |
         |- PRO_E_MFG_CMM_TOOL_SETUP
             |
             |- PRO_E_MFG_CMM_TOOL_POCKET_NUM
             |
             |- PRO_E_MFG_CMM_TOOL_TOOL_ID
             |
             |- PRO_E_MFG_CMM_TOOL_TIP_NUM
             |
             |- PRO_E_MFG_CMM_TOOL_REGISTER
             |
             |- PRO_E_MFG_CMM_TOOL_COMMENT
             |
             |- PRO_E_MFG_CMM_TOOL_PITCH_ANGLE
             |
             |- PRO_E_MFG_CMM_TOOL_ROLL_ANGLE

==============================================================================

(2) Elements table

----------------------------------------------------------------------------------------
Element Id                       Element Name       Data Type               Valid Values
----------------------------------------------------------------------------------------
PRO_E_MFG_CMM_TOOL_SETUP_ARR     Probe Setup Array  Array                   Note-1 
PRO_E_MFG_CMM_TOOL_SETUP         Probe Setup        Compound                Note-2 
PRO_E_MFG_CMM_TOOL_POCKET_NUM    Probe Postion      PRO_VALUE_TYPE_INT      Note-3 
PRO_E_MFG_CMM_TOOL_TOOL_ID       Probe Id           PRO_VALUE_TYPE_WSTRING  Note-4 
PRO_E_MFG_CMM_TOOL_TIP_NUM       Controlled Tip     PRO_VALUE_TYPE_INT      Note-5 
PRO_E_MFG_CMM_TOOL_REGISTER      Probe Register     PRO_VALUE_TYPE_INT      Note-6 
PRO_E_MFG_CMM_TOOL_COMMENT       Probe Comment      PRO_VALUE_TYPE_WSTRING  Note-7 
PRO_E_MFG_CMM_TOOL_PITCH_ANGLE   Pitch Angle        PRO_VALUE_TYPE_DOUBLE   Note-8 
PRO_E_MFG_CMM_TOOL_ROLL_ANGLE    Roll Angle         PRO_VALUE_TYPE_DOUBLE   Note-9 

==============================================================================

(3) Notes

Note-1  : CMM probes setup array.
          Optional.

Note-2  : Probe setup compound specification.
          Optional.

Note-3  : Probe position in tool magazine.
          Mandatory.

Note-4  : Probe id. Tool with such id should exist in mfg model.
          Mandatory.

Note-5  : Tip number - identifies the tip (from array) to control by CL.
          Optional (if not defined - set to 1).

Note-6  : Register number.
          Optional.

Note-7  : Probe comments.
          Optional.

Note-8  : Pitch angle value.
          Optional.

Note-9  : Roll angle value.
          Optional.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMTOOLSETUPCMM_H*/
