#ifndef PROMFGELEMTOOLREF_H
#define PROMFGELEMTOOLREF_H
/*
   Creo Parametric TOOLKIT declarations related to tool reference specification
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
     
     -- PRO_E_MFG_TOOL_REF_COMPOUND
           |
           |-- PRO_E_MFG_TOOL_REF_HEAD_NUM
           |
           |-- PRO_E_MFG_TOOL_REF_POCKET
           |
           |-- PRO_E_MFG_TOOL_REF_ID

==============================================================================

(2) Elements table

-------------------------------------------------------------------------------
Element Id                   Element Name   Data Type              Valid Values
-------------------------------------------------------------------------------
PRO_E_MFG_TOOL_REF_COMPOUND  Tool           Compound                Note-1 
PRO_E_MFG_TOOL_REF_HEAD_NUM  Head Number    PRO_VALUE_TYPE_INT      Note-2 
PRO_E_MFG_TOOL_REF_POCKET    Pocket Number  PRO_VALUE_TYPE_INT      Note-3 
PRO_E_MFG_TOOL_REF_ID        Tool Id        PRO_VALUE_TYPE_WSTRING  Note-4 

==============================================================================

(3) Notes

Note-1 : Compound element - head number, position, and tool id.
         Combination of properties must uniquely identify one of the tools 
         of corresponding work center.

Note-2 : Head (turret) number. 
         Possible values:
             PRO_MFG_TOOL_HEAD_1 - tool placed in head 1.
             PRO_MFG_TOOL_HEAD_2 - tool placed in head 2.
             PRO_MFG_TOOL_HEAD_3 - tool placed in head 3.
             PRO_MFG_TOOL_HEAD_4 - tool placed in head 4.

         Tools in head 1 can be specified for all types of workcells.
         Tools in head 2 can be specified for lathe and mill-turn workcells.
         Tools in heads 3 and 4 can be specified for mill-turn workcells.
         Mandatory.

Note-3 : Defines tool position in the head (turret).
         Mandatory.

Note-4 : Tool id.
         Mandatory.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMTOOLREF_H*/
