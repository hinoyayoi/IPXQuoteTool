#ifndef PROMFGELEMTOOLMTNCLCMD_H
#define PROMFGELEMTOOLMTNCLCMD_H
/*
  Creo Parametric TOOLKIT declarations related to specification of tool motion
  of type "CL Command" (PRO_TM_TYPE_CL_COMMAND). 
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
                  |-- PRO_E_TOOL_MTN_CL_CMD
                  |      |
                  |      |-- PRO_E_TOOL_MTN_CL_CMD_LOC_TYPE
                  |      |
                  |      |-- PRO_E_TOOL_MTN_CL_CMD_STR
                  |      |
                  |      |-- PRO_E_TOOL_MTN_CL_CMD_PARAM
                  |      |
                  |      |-- PRO_E_TOOL_MTN_CL_CMD_GEOM_REF
                  |      |
                  |      |-- PRO_E_TOOL_MTN_CL_CMD_SRF_OPT
                  |      |
                  |      |-- PRO_E_TOOL_MTN_CL_CMD_ON_EXIST_PNT
                  |
                  |-- PRO_E_TOOL_MTN_PARENT_REF_ID

===============================================================================

(2) Elements table

----------------------------------------------------------------------------------------
Element Id                       Element Name          Data Type                 Valid Values
----------------------------------------------------------------------------------------
PRO_E_TOOL_MTN                      Tool Motion                   Compound                 Note-1
PRO_E_TOOL_MTN_REF_ID               Tool Motion Id                PRO_VALUE_TYPE_INT       Note-2
PRO_E_TOOL_MTN_TYPE                 Tool Motion Type              PRO_VALUE_TYPE_INT       Note-3
PRO_E_TOOL_MTN_CL_CMD               Cl Command                    Compound                 
PRO_E_TOOL_MTN_CL_CMD_LOC_TYPE      CL Command Location Type      PRO_VALUE_TYPE_INT       Note-4
PRO_E_TOOL_MTN_CL_CMD_STR           CL Command String             PRO_VALUE_TYPE_WSTRING   Note-5
PRO_E_TOOL_MTN_CL_CMD_PARAM         CL Command Parameter          PRO_VALUE_TYPE_DOUBLE    Note-6
PRO_E_TOOL_MTN_CL_CMD_GEOM_REF      CL Command Geometry Reference PRO_VALUE_TYPE_SELECTION Note-7
PRO_E_TOOL_MTN_CL_CMD_SRF_OPT       CL Command Surface Option     PRO_VALUE_TYPE_INT       Note-8
PRO_E_TOOL_MTN_CL_CMD_ON_EXIST_PNT  CL Command On Existing Point  PRO_VALUE_TYPE_INT       Note-9
PRO_E_TOOL_MTN_PARENT_REF_ID        Parent Reference Id           PRO_VALUE_TYPE_INT       Note-10

========================================================================================

(3) Notes

Note-1  : Tool motion definition.
          PRO_E_TOOL_MTN is a member of PRO_E_TOOL_MTN_ARR array.

Note-2  : Tool motion id.
          Internal use only. Should not be added or modified.

Note-3  : Tool motion type - PRO_TM_TYPE_CL_COMMAND
          Values defined by ProTmType. 
          Mandatory.

Note-4  : CL command location types:
             PRO_CL_CMD_LOC_TYPE_SEL        - CL command position is on tool path
                                              (PRO_E_TOOL_MTN_CL_CMD_PARAM must be assigned);
             PRO_CL_CMD_LOC_TYPE_BEGIN      - CL command position is at the beginning 
                                              of tool path;
             PRO_CL_CMD_LOC_TYPE_CURR       - CL command position at the last point of 
                                              the previous motion.
             PRO_CL_CMD_LOC_TYPE_DTM_PNT    - CL command position is at the projection of given 
                                              point on tool path
                                              (NCL_CMD_LOC_TYPE_DTM_PNT must be defined);
             PRO_CL_CMD_LOC_TYPE_ON_SURFACE - CL command positions are at intersections of given
                                              surface and tool path 
                                              (PRO_CL_CMD_LOC_TYPE_ON_SURFACE must be defined).
          Mandatory.

Note-5  : User specified string.
          Mandatory.
                   
Note-6  : Range [0., 1.].
          Mandatory for PRO_CL_CMD_LOC_TYPE_SEL location type.
                   
Note-7  : Reference to a datum point or a surface. 
          Mandatory for NCL_CMD_LOC_TYPE_DTM_PNT and PRO_CL_CMD_LOC_TYPE_ON_SURFACE
          location types.
          
Note-8  : CL command surface options:
             PRO_CL_COMMAND_ON_FIRST_PASS - only the first pass is considered for 
                                            surface/tool path intersection;
             PRO_CL_COMMAND_ON_LAST_PASS  - only the last pass;
             PRO_CL_COMMAND_ON_ALL_PASSES - all passes.
          Mandatory for NCL_CMD_LOC_TYPE_ON_SURFACE.
          
Note-9  : PRO_B_TRUE  - place the cl command at the nearest existing point of
                        the tool path;
          PRO_B_FALSE - new point will be added.
          Mandatory for PRO_CL_CMD_LOC_TYPE_DTM_PNT.
                
Note-10 : Tool motion id of the tool motion referred by this cl command tool motion.
          Mandatory for PRO_CL_CMD_LOC_TYPE_SEL.
          
==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMTOOLMTNCLCMD_H */
