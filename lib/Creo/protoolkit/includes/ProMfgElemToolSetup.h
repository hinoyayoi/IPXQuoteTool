#ifndef PROMFGELEMTOOLSETUP_H
#define PROMFGELEMTOOLSETUP_H
/*
   Creo Parametric TOOLKIT declarations related to tool setup specification.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
     
   -- PRO_E_MFG_WCELL_TOOL_SETUP_ARR
         |
         |- PRO_E_MFG_WCELL_TOOL_SETUP
             |
               |- PRO_E_MFG_WCELL_TOOL_POCKET_NUM
               |
               |- PRO_E_MFG_WCELL_TOOL_ID
               |
               |- PRO_E_MFG_WCELL_TOOL_OUTPUT_TIP
               |
               |- PRO_E_MFG_TOOL_TIP_ARR
                     |
                     |- PRO_E_MFG_TOOL_TIP_COMPOUND
                           |
                           |- PRO_E_MFG_TOOL_TIP_REGISTER
                           |
                           |- PRO_E_MFG_TOOL_TIP_COMMENT
                           |
                           |- PRO_E_MFG_TOOL_TIP_OFFSET_Z
                           |
                           |- PRO_E_MFG_TOOL_TIP_OFFSET_X
                           |
                           |- PRO_E_MFG_TOOL_TIP_OFFSET_ANGLE
                           |
                           |- PRO_E_MFG_TOOL_TIP_FLASH_OPT
                           |
                           |- PRO_E_MFG_TOOL_TIP_FLSH_REGISTER
                           |
                           |- PRO_E_MFG_TOOL_TIP_FLSH_COMMENT
                           |
                           |- PRO_E_MFG_TOOL_TIP_FLSH_OFFSET_Z
                           |
                           |- PRO_E_MFG_TOOL_TIP_FLSH_OFFSET_X

==============================================================================

(2) Elements table

---------------------------------------------------------------------------------------
Element Id                       Element Name      Data Type               Valid Values
---------------------------------------------------------------------------------------
PRO_E_MFG_WCELL_TOOL_SETUP_ARR   Tool Setup Array  Array                   Note-1 
PRO_E_MFG_WCELL_TOOL_SETUP       Tool Setup        Compound                Note-2 
PRO_E_MFG_WCELL_TOOL_POCKET_NUM  Pocket Number     PRO_VALUE_TYPE_INT      Note-3 
PRO_E_MFG_WCELL_TOOL_ID          Tool Id           PRO_VALUE_TYPE_WSTRING  Note-4 
PRO_E_MFG_WCELL_TOOL_OUTPUT_TIP  Controlled Tip    PRO_VALUE_TYPE_INT      Note-5 
PRO_E_MFG_TOOL_TIP_ARR           Tip Array         Array                   Note-6 
PRO_E_MFG_TOOL_TIP_COMPOUND      Tip Compound      Compound                Note-7 
PRO_E_MFG_TOOL_TIP_REGISTER      Tip Register      PRO_VALUE_TYPE_INT      Note-8 
PRO_E_MFG_TOOL_TIP_COMMENT       Tip Comment       PRO_VALUE_TYPE_WSTRING  Note-9 
PRO_E_MFG_TOOL_TIP_OFFSET_Z      Tip Z Offset      PRO_VALUE_TYPE_DOUBLE   Note-10 
PRO_E_MFG_TOOL_TIP_OFFSET_X      Tip X Offset      PRO_VALUE_TYPE_DOUBLE   Note-11 
PRO_E_MFG_TOOL_TIP_OFFSET_ANGLE  Tip Angle Offset  PRO_VALUE_TYPE_DOUBLE   Note-12 
PRO_E_MFG_TOOL_TIP_FLASH_OPT     Tip Flash Option  PRO_VALUE_TYPE_INT      Note-13 
PRO_E_MFG_TOOL_TIP_FLSH_REGISTER Flash Register    PRO_VALUE_TYPE_INT      Note-14 
PRO_E_MFG_TOOL_TIP_FLSH_COMMENT  Flash Comment     PRO_VALUE_TYPE_WSTRING  Note-15 
PRO_E_MFG_TOOL_TIP_FLSH_OFFSET_Z Flash Z Offset    PRO_VALUE_TYPE_DOUBLE   Note-16 
PRO_E_MFG_TOOL_TIP_FLSH_OFFSET_X Flash X Offset    PRO_VALUE_TYPE_DOUBLE   Note-17 

==============================================================================

(3) Notes

Note-1  : Tool setup array.
          Optional.

Note-2  : Tool setup compound specification.
          Optional.

Note-3  : Tool position in head (turret). 
          Mandatory.

Note-4  : Tool id. Tool with such id should exist in mfg model.
          Mandatory.

Note-5  : Tip number - identifies the tip (from array) to control by CL.
          The number should not be greater than number of children in 
          PRO_E_MFG_TOOL_TIP_ARR
          Optional (if not defined - set to 1).

Note-6  : Array of tips.
          Optional.

Note-7  : Tip specification.
          Optional.

Note-8  : Tip register number.
          Optional.

Note-9  : Tip comment.
          Optional.

Note-10 : Tip Z offset value.
          Optional.

Note-11 : Tip X offset value.
          Optional.

Note-12 : Tip angle offset value.
          Optional.

Note-13 : PRO_B_TRUE  - enables flashing capability.
          PRO_B_FALSE - disables flashing capability.
          Optional (if not defined - set to PRO_B_FALSE).

Note-14 : Flash tool alternate tip register number.
          Optional. Ignored if PRO_E_MFG_TOOL_TIP_FLASH_OPT
          set to PRO_B_FALSE;

Note-15 : Flash tool alternate tip comments.
          Optional. Ignored if PRO_E_MFG_TOOL_TIP_FLASH_OPT
          set to PRO_B_FALSE;

Note-16 : Flash tool alternate tip Z offset.
          Optional. Ignored if PRO_E_MFG_TOOL_TIP_FLASH_OPT
          set to PRO_B_FALSE;

Note-17 : Flash tool alternate tip X offset.
          Optional. Ignored if PRO_E_MFG_TOOL_TIP_FLASH_OPT
          set to PRO_B_FALSE;

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMTOOLSETUP_H*/
