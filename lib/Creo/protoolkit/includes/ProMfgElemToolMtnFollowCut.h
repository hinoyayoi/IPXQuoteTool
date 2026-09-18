#ifndef PROMFGELEMTOOLMTNFOLLOWCUT_H
#define PROMFGELEMTOOLMTNFOLLOWCUT_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Follow Cut" (PRO_TM_TYPE_TRIM). 
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
                  |-- PRO_E_MFG_PARAM_ARR
                  |
                  |-- PRO_E_TOOL_MTN_PARENT_REF_ID
                  |
                  |-- PRO_E_TOOL_MTN_TRIM_VAL_OPT
                  |
                  |-- PRO_E_TOOL_MTN_TRIM_START_VAL
                  |
                  |-- PRO_E_TOOL_MTN_TRIM_END_VAL
                  |
                  |-- PRO_E_TOOL_MTN_TRIM_FLIP_DIR

===============================================================================

(2) Elements table

----------------------------------------------------------------------------------------
Element Id                       Element Name         Data Type                Valid Values
----------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                   Tool Motion          Compound                 Note-1
PRO_E_TOOL_MTN_REF_ID            Tool Motion Id       PRO_VALUE_TYPE_INT       Note-2
PRO_E_TOOL_MTN_TYPE              Tool Motion Type     PRO_VALUE_TYPE_INT       Note-3
PRO_E_MFG_PARAM_ARR              Mfg Parameter Array  Array                    Note-4
PRO_E_TOOL_MTN_PARENT_REF_ID     Parent Reference Id  PRO_VALUE_TYPE_INT       Note-5
PRO_E_TOOL_MTN_TRIM_VAL_OPT      Value Option         PRO_VALUE_TYPE_INT       Note-6
PRO_E_TOOL_MTN_TRIM_START_VAL    Start Value          PRO_VALUE_TYPE_DOUBLE    Note-7
PRO_E_TOOL_MTN_TRIM_END_VAL      End Value            PRO_VALUE_TYPE_DOUBLE    Note-8
PRO_E_TOOL_MTN_TRIM_FLIP_DIR     Direction Option     PRO_VALUE_TYPE_INT       Note-9

========================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.
          "Follow Cut" tool motions must follow in array the following types of 
          tool motions:

          PRO_TM_TYPE_CURVE_TRAJECTORY
          PRO_TM_TYPE_AREA_TURNING
          PRO_TM_TYPE_GROOVE_TURNING
          PRO_TM_TYPE_PROF_TURNING
          PRO_TM_TYPE_SURF_TRAJECTORY
          PRO_TM_TYPE_EDGE_TRAJECTORY

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_TRIM
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.

Note-5  : Tool motion id of the tool motion referred by this tool motion.
          Internal use only. Should not be added or modified.
          
Note-6  : Value Options:
            PRO_TM_TRIM_VAL_PARAM - value is a ratio parameter;
            PRO_TM_TRIM_VAL_DIST  - value is a distance.
          Mandatory.

Note-7  : Start parameter on tool path. Range [0., 1.].
          Mandatory.

Note-8  : End parameter on tool path. Range [0., 1.].
          PRO_E_TOOL_MTN_TRIM_END_VAL must be greater then 
          PRO_E_TOOL_MTN_TRIM_START_VAL
          Mandatory.
          
Note-9  : PRO_B_TRUE  - Reversed direction;
          PRO_B_FALSE - Same direction.
          Mandatory.
          
==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNFOLLOWCUT_H */
