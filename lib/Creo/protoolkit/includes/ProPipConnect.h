#ifndef PROCONNECT
#define PROCONNECT



#include <ProToolkit.h>

/*

1. Feature element tree for Connect

PRO_E_FEATURE_TREE
      |
      |--PRO_E_FEATURE_TYPE
      |
      |--PRO_E_STD_PIPE_LINE_ENV
      |      |--PRO_E_STD_PIPE_LINE_ID
      |      |--PRO_E_STD_PIPE_LINE_LNSTK
      |      |--PRO_E_STD_PIPE_LINE_CORNER_TYPE
      |      |--PRO_E_STD_PIPE_LINE_BEND_RAD
      |      |--PRO_E_STD_PIPE_LINE_MITER_NUM
      |      |--PRO_E_STD_PIPE_LINE_MITER_LEN
      |
      |--PRO_E_PIPE_CONNECT_FROM_MAIN_REF
      |--PRO_E_PIPE_CONNECT_TO_MAIN_REF
      |
      |--PRO_E_PIPE_CONNECT_DIMS_SCHEME
      |
      |--PRO_E_PIPE_ROUTE_ENDS
      |     |--PRO_E_PIPE_ROUTE_END_FIRST
      |          |--PRO_E_PIPE_ROUTE_END_OPT
      |          |--PRO_E_PIPE_ROUTE_END_LENGTH
      |          |--PRO_E_PIPE_ROUTE_END_REF
      |          |--PRO_E_PIPE_CONNECT_END_ANGLE
      |     |--PRO_E_PIPE_ROUTE_END_SECOND
      |          |--PRO_E_PIPE_ROUTE_END_OPT
      |          |--PRO_E_PIPE_ROUTE_END_LENGTH
      |          |--PRO_E_PIPE_ROUTE_END_REF
      |          |--PRO_E_PIPE_CONNECT_END_ANGLE


2. Feature elements table
--------------------------------------------------------------------------------------------
Element Id                        Element Name            Data Type                Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type            PRO_VALUE_TYPE_INT       PRO_FEAT_PIPE_JOIN
PRO_E_STD_PIPE_LINE_ENV           Pipe Line Environment   PRO_ELEM_TYPE_COMPOUND
PRO_E_STD_PIPE_LINE_ID            Pipe Line Id            PRO_ELEM_TYPE_INT                                 
PRO_E_STD_PIPE_LINE_LNSTK         Pipe Line Stock Id      PRO_ELEM_TYPE_INT        
PRO_E_STD_PIPE_LINE_CORNER_TYPE   Pipe Line Corner Type   PRO_ELEM_TYPE_OPTION     ProPipeCornerType
PRO_E_STD_PIPE_LINE_BEND_RAD      Pipe Line Bend Radius   PRO_ELEM_TYPE_DOUBLE 
PRO_E_STD_PIPE_LINE_MITER_NUM     Pipe Line miter number  PRO_ELEM_TYPE_INT       
PRO_E_STD_PIPE_LINE_MITER_LEN     Pipe Line miter length  PRO_ELEM_TYPE_DOUBLE    
PRO_E_PIPE_CONNECT_FROM_MAIN_REF  main from reference     PRO_ELEM_TYPE_SELECT
PRO_E_PIPE_CONNECT_TO_MAIN_REF    main from reference     PRO_ELEM_TYPE_SELECT
PRO_E_PIPE_CONNECT_DIMS_SCHEME    dims scheme             PRO_ELEM_TYPE_OPTION     ProPipeConnDimScheme
PRO_E_PIPE_ROUTE_ENDS             connect ends            PRO_ELEM_TYPE_COMPOUND
PRO_E_PIPE_ROUTE_END_FIRST        first end               PRO_ELEM_TYPE_COMPOUND
PRO_E_PIPE_ROUTE_END_SECOND       second end              PRO_ELEM_TYPE_COMPOUND
PRO_E_PIPE_ROUTE_END_OPT          end opt                 PRO_ELEM_TYPE_OPTION     ProPipeEndOffsetOpt
PRO_E_PIPE_ROUTE_END_LENGTH       end length              PRO_ELEM_TYPE_DOUBLE
PRO_E_PIPE_ROUTE_END_REF          end reference           PRO_ELEM_TYPE_SELECT
PRO_E_PIPE_CONNECT_END_ANGLE      end angle               PRO_ELEM_TYPE_DOUBLE


3. Mandatory or Optional

------------------------------------------------------------------------------------------------
|           Element Id              |                   Mandatory                              |
------------------------------------------------------------------------------------------------
| PRO_E_STD_PIPE_LINE_ID            | Mandatory, unless working under route environment        |
|----------------------------------------------------------------------------------------------|
| PRO_E_STD_PIPE_LINE_LNSTK         | Optional, default is taken from the related pipeline     |
|----------------------------------------------------------------------------------------------|
| PRO_E_STD_PIPE_LINE_CORNER_TYPE   | Optional ( must be set in the related linestock),        |
|                                   | default is taken from the related pipeline.              |
|----------------------------------------------------------------------------------------------|
| PRO_E_STD_PIPE_LINE_BEND_RAD      | Optional (Relevant only if corner type is bend),         |
|                                   | default is taken from related linestock. If spec driven, |
|                                   | value must be defined in the related linestock.          |
|----------------------------------------------------------------------------------------------|
| PRO_E_STD_PIPE_LINE_MITER_NUM     | Optional (Relevant only if corner type is miter),        |
|                                   | default is taken from related linestock. If spec driven, |
|                                   | value must be defined in the related linestock.          |
|----------------------------------------------------------------------------------------------|
| PRO_E_STD_PIPE_LINE_MITER_LEN     | Optional (Relevant only if corner type is miter),        |
|                                   | default is taken from related linestock. If spec driven, |
|                                   | value must be defined in the related linestock.          |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_CONNECT_FROM_MAIN_REF  | Mandatory                                                |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_CONNECT_TO_MAIN_REF    | Mandatory                                                |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_CONNECT_DIMS_SCHEME    | Optional, default is PRO_PIPE_DIM_SCHEME_L1_L2.          |
|                                   | If one of the parameters ( length or angle ) is missing  |
|                                   | the scheme will be the default.                          |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_ROUTE_END_OPT          | Optional, default is PRO_PIPE_OFFSET_END                 |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_ROUTE_END_LENGTH       | Optional, length_1 is needed if dim scheme includes L1   |
|                                   |           length_2 is needed if dim scheme includes L2   |
|                                   | Default is 0.0                                           |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_ROUTE_END_REF          | Mandatory if end_offset_opt = PRO_PIPE_OFFSET_REFERENCE  |
|----------------------------------------------------------------------------------------------|
| PRO_E_PIPE_CONNECT_END_ANGLE      | Optional, angle_1 is needed if dim scheme includes A1    |
|                                   |           angle_2 is needed if dim scheme includes A2    |
|                                   | Default is 0.0                                           |
------------------------------------------------------------------------------------------------
*/

/* Valid values  */

typedef enum pro_pipe_corner_type
{
  PRO_PIPE_CORNER_TYPE_FITTING = 0,
  PRO_PIPE_CORNER_TYPE_MITER   = 1,
  PRO_PIPE_CORNER_TYPE_BEND    = 2
}ProPipeCornerType;

typedef enum pro_pipe_end_offset_opt
{
  PRO_PIPE_OFFSET_REFERENCE   = 1,
  PRO_PIPE_OFFSET_END         = 2
}ProPipeEndOffsetOpt;

typedef enum pro_pipe_dims_scheme
{
  PRO_PIPE_DIM_SCHEME_L1_L2   = 1,
  PRO_PIPE_DIM_SCHEME_L1_A1   = 2,
  PRO_PIPE_DIM_SCHEME_L1_A2   = 3,
  PRO_PIPE_DIM_SCHEME_L2_A1   = 4,
  PRO_PIPE_DIM_SCHEME_L2_A2   = 5,
  PRO_PIPE_DIM_SCHEME_A1_A2   = 6
} ProPipeDimScheme;

#endif


