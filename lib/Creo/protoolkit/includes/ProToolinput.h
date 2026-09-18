#ifndef PROTOOLINPUT_H_FILE
#define PROTOOLINPUT_H_FILE

/* ProToolinput.h: definitions and action functions for ProToolinput object */

#include <ProToolElem.h>





PRO_BEGIN_C_DECLS


typedef                struct Pro_Toolinput  *ProWToolinput;
typedef PRO_CONST_ARG  struct Pro_Toolinput  *ProConstWToolinput;
typedef                struct Pro_Toolinput  *ProToolinputPtr;
typedef PRO_CONST_ARG  struct Pro_Toolinput  *ProConstToolinputPtr;


typedef enum Pro_Tool_Type  {
  PRO_TOOL_NONE        =        0,
  PRO_TOOL_DRILL       =        1,
  PRO_TOOL_TURN        =        2,
  PRO_TOOL_SAW         =        4,
  PRO_TOOL_MILL        =        8,
  PRO_TOOL_GROOVE      =       16,
  PRO_TOOL_NIBBLE      =       32,
  PRO_TOOL_PUNCH       =       64,
  PRO_TOOL_AUXILIARY   =      128,
  PRO_TOOL_FORM        =      256,
  PRO_TOOL_PUNPNT      =      512,
  PRO_TOOL_AREA_NIB    =     1024,
  PRO_TOOL_MFG_REFINE  =     2048,
  PRO_TOOL_BORE        =    16384,
  PRO_TOOL_TAP         =    32768,
  PRO_TOOL_CSINK       =    65536,
  PRO_TOOL_REAM        =   131072,
  PRO_TOOL_CENTER_DRL  =   262144,
  PRO_TOOL_TURN_GRV    =   524288,
  PRO_TOOL_MILL_THREAD =  1048576,
  PRO_TOOL_TURN_THREAD =  2097152,
  PRO_TOOL_SHEAR       =  4194304,
  PRO_TOOL_SIDE_MILL   =  8388608,
  PRO_TOOL_CMM_FIXED   = 16777216,
  PRO_TOOL_CMM_ROTATED = 33554432,       /* 1<<25 */
  PRO_TOOL_CMM_CAMERA  = 67108864,        
  PRO_TOOL_BACK        = 134217728,       /* 1<<27 */
  PRO_TOOL_PLUNGE_MILL = (1<<29),
  PRO_TOOL_TAPER       = (1<<30),
  PRO_TOOL_UD_PUNCH    =       3,
  PRO_TOOL_CROUND      =       5,
  PRO_TOOL_CHAMFER     =       6,
  PRO_TOOL_APT7        =       7,
  PRO_TOOL_MULTIPLE_TIP =      9,
  PRO_TOOL_END_MILL    =       10,
  PRO_TOOL_BALL_MILL   =       11,
  PRO_TOOL_BULL_MILL   =       12,
  PRO_TOOL_BASIC_DRILL =       13,
  PRO_TOOL_SPOT_DRILL  =       14,
  PRO_TOOL_BORING_BAR  =       15,
  PRO_TOOL_KEY_CUTTER  =       17,
  PRO_TOOL_LOLLIPOP    =       18,
  PRO_TOOL_MULTI_TASK  =       19,
  PRO_TOOL_TAPER_BALL_MILL =   20
}  ProToolType;


extern ProError ProToolinputAlloc  (ProToolinputPtr *r_tool_input);
/*
   Purpose:  Allocates a <i>ProToolinput</i> data structure.

   Input Arguments:
      None

   Output Arguments:
      r_tool_input   - The handle to the newly allocated structure

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully allocated the
                           structure.
      PRO_TK_BAD_INPUTS  - The argument is NULL.
*/


extern ProError ProToolinputFree  (ProToolinputPtr *r_tool_input);
/*
   Purpose:  Frees the memory occupied by a <i>ProToolinput</i> and its 
             dependents (the <i>ProToolElems</i> stored in it).

   Input Arguments:
      r_tool_input   - The address of the pointer to the tool input to be 
                       freed. This design allows you to use 
                       <i>*r_tool_input = NULL</i> safely.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully freed the memory.
*/


extern void   ProToolinputFreeAllElems  (ProToolinputPtr   tool_input);
/*
   Purpose:  Frees all the <i>ProToolElems</i> data structures stored within 
             the tool input.

   Input Arguments:
      tool_input     - The tool input from which to free the 
                       <i>ProToolElems</i>

   Output Arguments:
      None

   Return Values:
      None
*/


extern ProError ProToolinputTypeSet  (ProToolinputPtr  tool_input,
                                      ProToolType      tool_type);
/*
   Purpose:  Sets the tool type information in the tool input.

   Input Arguments:
      tool_input     - The tool input in which to set the type
      tool_type      - The tool type to be set

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the type.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProToolinputElemAdd  (ProToolinputPtr   tool_input,
                                      ProToolElem       tool_elem);
/*
   Purpose:  Adds a <i>ProToolElem</i> data structure to the tool input.

   Input Arguments:
      tool_input     - The tool input to which to add the element
      tool_elem      - The tool element to be added

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully added the element.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


PRO_END_C_DECLS


#endif  /* PROTOOLINPUT_H_FILE */
