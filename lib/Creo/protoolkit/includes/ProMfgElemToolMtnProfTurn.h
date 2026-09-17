#ifndef PROMFGELEMTOOLMTNPROFTURN_H
#define PROMFGELEMTOOLMTNPROFTURN_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "Profile Turning" (PRO_TM_TYPE_PROF_TURNING). 
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
                  |-- PRO_E_TOOL_MTN_TURN_PROF
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_REF
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_S_VAL
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_E_VAL
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_S_REF
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_E_REF
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_S_ORIENT
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_E_ORIENT
                         |
                         |-- PRO_E_TOOL_MTN_TURN_PROF_OFFSET_CUT
                         |
                         |-- PRO_E_TOOL_MTN_TURN_DFLT_CORNER_TYPE
                         |
                         |-- PRO_E_TOOL_MTN_TURN_CORNER_ARR
                         |      |
                         |      |-- PRO_E_TOOL_MTN_TURN_CORNER
                         |             |
                         |             |-- PRO_E_TOOL_MTN_TURN_CORNER_TYPE
                         |             |
                         |             |-- PRO_E_TOOL_MTN_TURN_PREV_ENT_ID
                         |             |
                         |             |-- PRO_E_TOOL_MTN_TURN_NEXT_ENT_ID
                         |             |
                         |             |-- PRO_E_TOOL_MTN_TURN_CORNER_VAL
                         |
                         |-- PRO_E_TURN_STK_ALLW_PROF_ARR
                         |      |
                         |      |-- PRO_E_TURN_STK_ALLOWANCE
                         |             |
                         |             |-- PRO_E_TURN_STK_ALLW_FIRST_ENT_ID
                         |             |
                         |             |-- PRO_E_TURN_STK_ALLW_LAST_ENT_ID
                         |             |
                         |             |-- PRO_E_TURN_STK_ALLOWANCE_VAL
                         |
                         |-- PRO_E_TURN_STK_ALLW_ROUGH_ARR
                                |
                                |-- PRO_E_TURN_STK_ALLOWANCE
                                       |
                                       |-- PRO_E_TURN_STK_ALLW_FIRST_ENT_ID
                                       |
                                       |-- PRO_E_TURN_STK_ALLW_LAST_ENT_ID
                                       |
                                       |-- PRO_E_TURN_STK_ALLOWANCE_VAL
                         

===============================================================================

(2) Elements table

---------------------------------------------------------------------------------------------------------
Element Id                           Element Name                    Data Type                 Valid Values
---------------------------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                       Tool Motion                     Compound                  Note-1
PRO_E_TOOL_MTN_REF_ID                Tool Motion Id                  PRO_VALUE_TYPE_INT        Note-2
PRO_E_TOOL_MTN_TYPE                  Tool Motion Type                PRO_VALUE_TYPE_INT        Note-3
PRO_E_MFG_PARAM_ARR                  Mfg Parameter Array             Array                     Note-4
PRO_E_TOOL_MTN_TURN_PROF             Turning Profile                 Compound                  Note-5
PRO_E_TOOL_MTN_TURN_PROF_REF         Turning Profile Refrence        PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_TOOL_MTN_TURN_PROF_S_VAL       Start Point Offset              PRO_VALUE_TYPE_DOUBLE     Note-7
PRO_E_TOOL_MTN_TURN_PROF_E_VAL       End Point Offset                PRO_VALUE_TYPE_DOUBLE     Note-8
PRO_E_TOOL_MTN_TURN_PROF_S_REF       Start Point Ajustment Refrence  PRO_VALUE_TYPE_SELECTION  Note-9
PRO_E_TOOL_MTN_TURN_PROF_E_REF       End Point Ajustment Refrence    PRO_VALUE_TYPE_SELECTION  Note-10
PRO_E_TOOL_MTN_TURN_PROF_S_ORIENT    Start Orientation               PRO_VALUE_TYPE_INT        Note-11
PRO_E_TOOL_MTN_TURN_PROF_E_ORIENT    End Orientation                 PRO_VALUE_TYPE_INT        Note-12
PRO_E_TOOL_MTN_TURN_PROF_OFFSET_CUT  Offset Cut                      PRO_VALUE_TYPE_INT        Note-13
PRO_E_TOOL_MTN_TURN_DFLT_CORNER_TYPE Default Corner Type             PRO_VALUE_TYPE_INT        Note-14
PRO_E_TOOL_MTN_TURN_CORNER_ARR       Corner Conditions Array         Array                     Note-15
PRO_E_TOOL_MTN_TURN_CORNER           Corner Conditions               Compound                  
PRO_E_TOOL_MTN_TURN_CORNER_TYPE      Corner Type                     PRO_VALUE_TYPE_INT        Note-16
PRO_E_TOOL_MTN_TURN_PREV_ENT_ID      Previous Entity Id              PRO_VALUE_TYPE_INT        Note-17
PRO_E_TOOL_MTN_TURN_NEXT_ENT_ID      Next Entity Id                  PRO_VALUE_TYPE_INT        Note-18
PRO_E_TOOL_MTN_TURN_CORNER_VAL       Corner Value                    PRO_VALUE_TYPE_DOUBLE     Note-19
PRO_E_TURN_STK_ALLW_PROF_ARR         Profile Stock Allowance         Array                     Note-20
PRO_E_TURN_STK_ALLW_ROUGH_ARR        Rough Stock Allowance           Array                     Note-21
PRO_E_TURN_STK_ALLOWANCE             Stock Allowance                 Compound
PRO_E_TURN_STK_ALLW_FIRST_ENT_ID     Segment First Entity Id         PRO_VALUE_TYPE_INT        Note-22
PRO_E_TURN_STK_ALLW_LAST_ENT_ID      Segment Last Entity Id          PRO_VALUE_TYPE_INT        Note-23
PRO_E_TURN_STK_ALLOWANCE_VAL         Stock Allowance Value           PRO_VALUE_TYPE_DOUBLE     Note-24
=========================================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_PROF_TURNING
          Values defined by ProTmType. 
          Mandatory.

Note-4  : Array of manufacturing parameters.
          Please see ProMfgElemParam.h.
          Mandatory.

Note-5  : Turning profile definition.

Note-6  : Turning profile refrence.
          Mandatory.
          
Note-7  : Start point offset.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.

Note-8  : End point offset.
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Optional.
          
Note-9  : Start point ajustment refrence.
          Optional.

Note-10 : End point ajustment refrence.
          Optional.
          
Note-11 : Orientation of axis if csys is selected as start point ajustment.
             PRO_TM_TURN_CSYS_X; 
             PRO_TM_TURN_CSYS_Y; 
             PRO_TM_TURN_CSYS_Z.
          Mandatory if csys is selected for cylindrical retract reference. 
          Ingnored in all other cases.

Note-12 : Orientation of axis if csys is selected as end point ajustment:
             PRO_TM_TURN_CSYS_X; 
             PRO_TM_TURN_CSYS_Y; 
             PRO_TM_TURN_CSYS_Z.
          Mandatory if csys is selected for cylindrical retract reference. 
          Ingnored in all other cases.
                   
Note-13 : Offset from turn profile by the tool radius.
             PRO_B_TRUE;
             PRO_B_FALSE.
          Mandatory.

Note-14 : Default corner type:
             PRO_TM_TURN_CORNER_TYPE_SHARP; 
             PRO_TM_TURN_CORNER_TYPE_FILLET; 
             PRO_TM_TURN_CORNER_TYPE_CHAMFER.
          Mandatory.
                   
Note-15 : Corner Conditions Array.
          Optional.
                   
Note-16 : Corner type:
             PRO_TM_TURN_CORNER_TYPE_SHARP; 
             PRO_TM_TURN_CORNER_TYPE_FILLET; 
             PRO_TM_TURN_CORNER_TYPE_CHAMFER.
          Mandatory.

Note-17 : Previous entity id.
          Mandatory.
                   
Note-18 : Next entity id.
          Mandatory.

Note-19 : Fillet radius or chamfer dimension.  
          Range -MAX_DIM_VALUE to MAX_DIM_VALUE.
          Mandatory if corner type is PRO_TM_TURN_CORNER_TYPE_FILLET or
                                      PRO_TM_TURN_CORNER_TYPE_CHAMFER.
                  
Note-20 : Profile Stock Allowance Array.
          Optional.
          
Note-21 : Rough Stock Allowance Array.
          Optional.
          
Note-22 : Id of the first entity of the turn profile segment with stock
          allowance.
          Mandatory.
          
Note-23 : Id of the last entity of the turn profile segment with stock
          allowance.
          Mandatory.

Note-24 : Stock allowance value
          Mandatory.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNPROFTURN_H */
