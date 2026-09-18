#ifndef PROSMTREGULARRIP_H
#define PROSMTREGULARRIP_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Regular rip feature
*/



#include <ProToolkit.h>
#include <ProSmtSurfaceRip.h>
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
     |--PRO_E_SMT_RIP_TYPE
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_SMT_CUT_NORMAL_DIR
     |
     |--PRO_E_SMT_PROJ_DIR
     |
     |--PRO_E_STD_MATRLSIDE
     |
     |--PRO_E_STD_SURF_COLLECTION_APPL



==============================================================================
Element Id                     Element Name             Data Type
==============================================================================

PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT
                                See Note 1.


PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING


PRO_E_SMT_RIP_TYPE             Sheet Metal Rip Type      PRO_VALUE_TYPE_INT
                                                            See Note 2.


PRO_E_STD_SECTION              Sheet Rip Sketch Selection   See Note 3.


PRO_E_SMT_CUT_NORMAL_DIR         Normal Of The           PRO_VALUE_TYPE_INT  
                                   Projection               See Note 4.

PRO_E_SMT_PROJ_DIR                 Sheet Rip             PRO_VALUE_TYPE_INT
                                 Projection Side            See Note 5.

PRO_E_STD_MATRLSIDE                Sheet Rip             PRO_VALUE_TYPE_INT
                                 Area Direction             See Note 6

PRO_E_STD_SURF_COLLECTION_APPL Sheet Rip Boundary      PRO_VALUE_TYPE_SELECTION
  see Note 8.                   Surface Collection          See Note 7.


-------------------------------------------------------------------------------
Note 1. 
  PRO_E_FEATURE_TYPE must be of PRO_FEAT_RIP.

-------------------------------------------------------------------------------
Note 2.
  PRO_E_SMT_RIP_TYPE must be of PRO_SMT_RIP_REGULAR type.

-------------------------------------------------------------------------------
Note 3.
  See: ProStdSection.h  

-------------------------------------------------------------------------------
Note 4.
  ProSmtCutNormDir.
  PRO_E_SMT_CUT_NORMAL_DIR can be PRO_SMT_CUT_DRVSIDE_GREEN for normal to
  Driven surface or PRO_SMT_CUT_DRVSIDE_WHITE for normal to Offset surface.
-------------------------------------------------------------------------------
Note 5.
  See: ProSmtSplitArea.h.

-------------------------------------------------------------------------------
Note 6.
  ProSketchRipMatSide.
  PRO_E_STD_MATRLSIDE can be PRO_SKETCHRIP_MATSIDE_ONE to 
  specify the rip in one direction or PRO_SKETCHRIP_MATSIDE_TWO
  to specify the rip in the opposite direction.
-------------------------------------------------------------------------------
Note 7.
  See ProSrfcollection.h 
-------------------------------------------------------------------------------
Note 8.
  This element is not Mandatory ( optional ). 


*****************************************************************************/

typedef enum _ProSketchRipMatSide_
{
  PRO_SKETCHRIP_MATSIDE_ONE  = 1,
  PRO_SKETCHRIP_MATSIDE_TWO  = 2
}ProSketchRipMatSide;

PRO_END_C_DECLS

#endif /* PROSMTREGULARRIP_H */                    
