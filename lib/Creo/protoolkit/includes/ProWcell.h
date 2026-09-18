#ifndef PROWCELL_H
#define PROWCELL_H

/* ProWcell.h: This include file contains the following details of the
               workcell feature:

                  * workcell feature definition
                  * some utility functions for a workcell feature
*/



#include <ProObjects.h>
#include <ProMfgOptions.h>

/*****************************************************************************\

WARNING: This Feature element tree is deprecated and will be removed in subsequent
releases. Refer to these headers for replacement:

ProMfgFeatWcellCmm.h
ProMfgFeatWcellLathe.h
ProMfgFeatWcellMill.h
ProMfgFeatWcellMillTurn.h
ProMfgFeatWcellWedm.h


Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEAT_TYPE
     |
     |--PRO_E_WCELL_TYPE
     |
     |--PRO_E_NUM_AXES
     |
     |--PRO_E_LATHE_DIR          Required if WCELL_TYPE = LATHE or MILL_N_TRN
     |
     |--PRO_E_MACH_NUM_HEADS     Required if WCELL_TYPE = LATHE or MILL_N_TRN
     |
     |--PRO_E_MFG_PARAMS         Optional element, Array of PRO_E_MFG_PARAM
     |    |
     |    |--PRO_E_MFG_PARAM
     |         |
     |         |--PRO_E_MFG_PARAM_NAME
     |         |
     |         |--PRO_E_MFG_PARAMVAL
     |
     |--PRO_E_FEAT_NAME              Optional element
     |
     |--PRO_E_TOOL_TABLES            Optional element,
     |    |                          Array of PRO_E_MFG_TOOL_TABLE
     |    |--PRO_E_MFG_TOOL_TABLE
     |         |
     |         |--PRO_E_MACH_HEAD
     |         |
     |         |--PRO_E_MFG_TABLE    Expanded below
     |
     |--PRO_E_SITE_NAMES             Optional element
 
   PRO_E_MFG_TABLE                   Array of PRO_E_MFG_TABLE_ROW
     |
     |--PRO_E_MFG_TABLE_ROW          Array of PRO_E_MFG_TABLE_CELL
          |
          |--PRO_E_MFG_TABLE_CELL
               |
               |--PRO_E_MFG_TABLE_CELL_TYPE
               |
               |--PRO_E_MFG_TABLE_CELL_VALUE

WORKCELL ELEMENTS TABLE
--------------------------------------------------------------------------------
Element Id            Element Name     Data Type          Valid Values
                                       (PRO_VALUE_TYPE)
--------------------------------------------------------------------------------
PRO_E_FEAT_TYPE       Feature type     INT                PRO_FEAT_WORKCELL
PRO_E_WCELL_TYPE      Workcell type    INT                ProWcellType
PRO_E_NUM_AXES        Number of axes   INT                See note 1
PRO_E_LATHE_DIR       Lathe type       INT                ProWcellLatheDir
PRO_E_MACH_NUM_HEADS  Number of heads  INT                ProWcellMachHeads
PRO_E_MFG_PARAMS      Workcell params  ARRAY
PRO_E_MFG_PARAM       Mfg param        COMPOUND
PRO_E_MFG_PARAM_NAME  Mfg param name   STRING             User-visible
                                                          mfg param names
PRO_E_MFG_PARAMVAL    Mfg param value  INT/DOUBLE/WSTRING See note 2
PRO_E_FEAT_NAME       Feature Name     WSTRING            Feature name
PRO_E_TOOL_TABLES     Tool Tables      ARRAY              Array of tool tables
PRO_E_MFG_TOOL_TABLE  Tool table       COMPOUND           See note 3
PRO_E_MACH_HEAD       Machining head   INT                ProMachHead

PRO_E_MFG_TABLE       Mfg table        ARRAY              Array of table rows
PRO_E_MFG_TABLE_ROW   Row of table     ARRAY              Array of table cells  
PRO_E_MFG_TABLE_CELL                   COMPOUND           
PRO_E_MFG_TABLE_CELL_TYPE
                      Cell type        INT                ProTooltableCol
PRO_E_MFG_TABLE_CELL_VALUE
                      Cell value       INT/DOUBLE/WSTRING See note 2
PRO_E_SITE_NAMES      Workcell sites   MULTIPLE WSTRINGS  Site names array

--------------------------------------------------------------------------------

NOTES:

1. The range of the valid number of axes is dependent on the workcell type:

   Lathe     -  2 or 4
   Milling   -  3, 4, or 5
   Mill/Turn -  2, 3, 4, or 5
   Wedm      -  2 or 4   

2. This type of element can have an integer value, a double value, or a
   wide string value. Please refer to the Pro/MFG User's Guide for
   appropriate values.

3. For most workcells, the tool table consists of two pieces of information:

      (i) The machine head: this is applicable only when the element
                            PRO_E_MACH_NUM_HEADS has been specified.
      (ii) The table containing information of tools setup for the workcell.

Most workcell tool tables have the following form:

--------------------------------------------------------------------------------
   POSITION TOOL_ID   REGISTER  COMMENTS
--------------------------------------------------------------------------------

EXCEPTIONS:
  For a CMM workcell, (WCELL_TYPE == PRO_WCELL_CMM) the tool table is of the form:

--------------------------------------------------------------------------------
   POSITION TOOL_ID   REGISTER  TIP_NUM  PITCH_ANG  ROLL_ANG  COMMENTS
--------------------------------------------------------------------------------

\******************************************************************************/

PRO_BEGIN_C_DECLS

typedef struct pro_model_item ProWcell;
typedef                struct pro_model_item  *ProWcellPtr;
typedef PRO_CONST_ARG  struct pro_model_item  *ProConstWcellPtr;

typedef enum Pro_WcellMachHeads
{
  PRO_WCELL_MACH_NO_HEADS    = -1,
  PRO_WCELL_MACH_HEAD1       = 0,     /* machining done on head 1            */
  PRO_WCELL_MACH_HEAD2       = 1,     /* machining done on head 2            */
  PRO_WCELL_MACH_BOTH_HEADS  = 2      /* machining done on both heads        */
} ProWcellMachHeads;

typedef enum tool_table_col
{
  PRO_TOOL_TABLE_INDEX    =   1,      /* tool position in workcell(head)     */
                                      /* value type: INT                     */
  PRO_TOOL_TABLE_TOOL_ID  =   2,      /* the tool identifier                 */
                                      /* value type: WSTRING                 */
  PRO_TOOL_TABLE_REGISTER =   3,      /* the gauge length register           */
                                      /* value type: INT                     */
  PRO_TOOL_TABLE_COMMENTS =   4,      /* comments for the tool               */
                                      /* value type: WSTRING                 */
  PRO_TOOL_TABLE_TIP_NUM  =   5,      /* tip number of a multi-tip tool      */
                                      /* value type: INT                     */
  PRO_TOOL_TABLE_PITCH_ANG=   6,      /* pitch angle of the tool             */
                                      /* value type: DOUBLE                  */
  PRO_TOOL_TABLE_ROLL_ANG =   7       /* roll angle of the tool              */
                                      /* value type: DOUBLE                  */
} ProTooltableCol;

extern ProError  ProWcellMaxToolPosGet ( ProWcell         *wcell,  
                                        ProMachHead       head,
                                        int              *r_max_tool_pos);
/*
   Purpose:  Retrieves the maximum tool position number for the specified
             machine head of a workcell feature.

   Input Arguments:
      wcell          - The handle to the workcell feature
      head           - The machine head being queried

   Output Arguments:
      r_max_tool_pos - The maximum tool position being used on the
                       specified machine head

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError  ProWcellToolGet  (ProWcell       *wcell,
                                   ProMachHead       head, 
                                   int               tool_pos,
                                   ProLine           tool_id);
/*
   Purpose:  Retrieves the identifier of the tool at the specified machine
             head and position for a workcell feature.

   Input Arguments:
      wcell          - The handle to the workcell feature
      head           - The machine head being queried
      tool_pos       - The tool position being queried

   Output Arguments:
      tool_id        - The tool identifier (a string)

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_GENERAL_ERROR - There is no tool at the specified head and 
                             position.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/


PRO_END_C_DECLS


#endif  /* PROWCELL_H */
