#ifndef PROSMTSPLITAREA_H
#define PROSMTSPLITAREA_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Split Area feature
*/



#include <ProToolkit.h>
#include <ProExtrude.h>

PRO_BEGIN_C_DECLS

/* ***************************************************************************


Feature element tree :

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME 
     |
     |--PRO_E_SMT_CUT_NORMAL_DIR
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_SMT_PROJ_DIR
     |
     |--PRO_E_STD_MATRLSIDE




==============================================================================
Element Id                     Element Name             Data Type
==============================================================================

PRO_E_FEATURE_TYPE             Feature Type              PRO_VALUE_TYPE_INT
                                See Note 1.


PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING


PRO_E_SMT_CUT_NORMAL_DIR       Normal of the             PRO_VALUE_TYPE_INT
                                 projection                 See Note 2.


PRO_E_STD_SECTION          Sheet Split Area Sketch          See Note 3.
                                 Selection 


PRO_E_SMT_PROJ_DIR            Projection Side            PRO_VALUE_TYPE_INT
                                                            See Note 4.

PRO_E_STD_MATRLSIDE            Area Direction            PRO_VALUE_TYPE_INT
                                                            See Note 5.
                                                             
-------------------------------------------------------------------------------
Note 1.
  PRO_E_FEATURE_TYPE must be of PRO_FEAT_DEFORM_AREA.

-------------------------------------------------------------------------------
Note 2.
  ProSmtCutNormDir.
  PRO_E_SMT_CUT_NORMAL_DIR can be PRO_SMT_CUT_DRVSIDE_GREEN for normal to
  Driven surface or PRO_SMT_CUT_DRVSIDE_WHITE for normal to Offset surface.
-------------------------------------------------------------------------------
Note 3.
  See ProStdSection.h.
-------------------------------------------------------------------------------
Note 4.
  ProSmtProjDir.
  PRO_E_SMT_PROJ_DIR can be PRO_SMT_PROJ_DIR_ONE for projection
  to side one or PRO_SMT_PROJ_DIR_TWO for projection to side two or
  PRO_SMT_PROJ_DIR_BOTH for projection to both sides.
-------------------------------------------------------------------------------
Note 5.
  ProSplitAreaMatSide.
  PRO_E_STD_MATRLSIDE can be PRO_SPLITAREA_MATSIDE_ONE for split in one
  direction or PRO_SPLITAREA_MATSIDE_TWO for split in the opposite direction.

*****************************************************************************/

typedef enum Pro_Smt_proj_Dir
{
  PRO_SMT_PROJ_DIR_ONE  = 0,
  PRO_SMT_PROJ_DIR_TWO  = 1,
  PRO_SMT_PROJ_DIR_BOTH = 2
}ProSmtProjDir;


typedef enum _ProSplitAreaMatSide_
{
  PRO_SPLITAREA_MATSIDE_ONE  = 1,
  PRO_SPLITAREA_MATSIDE_TWO  = 2
}ProSplitAreaMatSide;

PRO_END_C_DECLS

#endif /* PROSMTSPLITAREA_H */
