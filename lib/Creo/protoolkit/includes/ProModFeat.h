#ifndef PROMODFEATH
#define PROMODFEATH



#include <ProToolkit.h>


PRO_BEGIN_C_DECLS


 
/*****************************************************************************\

1. Feature elements table
 
--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type             Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_PROTRUSION,
                                                                       PRO_FEAT_FIRST_FEAT,
                                                                       PRO_FEAT_CUT,
                                                                       PRO_FEAT_SLOT
PRO_E_FEATURE_FORM             Feature Form   PRO_VALUE_TYPE_INT       PRO_EXTRUDE, PRO_REVOLVE
PRO_E_ATTRIBUTES               Attributes     Compound
PRO_E_STD_SIDES                ExtruAttr,     PRO_VALUE_TYPE_INT       ProSides
PRO_E_ATTR_SRF_END_COND        EndCond        PRO_VALUE_TYPE_INT       ProSrfEndCond
PRO_E_STD_SECTION              Section        Compound
PRO_E_STD_MATRLSIDE            Mat Side       PRO_VALUE_TYPE_INT       ProStdMatSide
PRO_E_STD_DIRECTION            Direction      PRO_VALUE_TYPE_INT       ProStdDir
--------------------------------------------------------------------------------------------

   Note 1. If the feature is first feature, feature type should be PRO_FEAT_FIRST_FEAT
          even though it is a protrusion; PRO_FEAT_FIRST_FEAT must have 2d section.

   Note 2. PRO_FEAT_SLOT does not use Mat Side.
 
\*****************************************************************************/

/* 1. PRO_E_STD_SIDES */

typedef enum pro_sides
{
   PRO_SIDES_ONE_SIDE   = (1 << 12),
   PRO_SIDES_BOTH_SIDES = 0
} ProSides;

/* 2. PRO_E_STD_SECTION */
  /* PRO_E_STD_SECTION element tree and constants are in ProStdSection.h */

/* 3. PRO_E_STD_MATRLSIDE */

typedef enum pro_std_mat_side
{
   PRO_MAT_SIDE_ONE = 1,
   PRO_MAT_SIDE_TWO = -1
} ProStdMatSide;

/* 4. PRO_E_STD_DIRECTION */

typedef enum pro_std_dir
{
   PRO_STD_DIR_SIDE_ONE = 1,
   PRO_STD_DIR_SIDE_TWO = -1
} ProStdDir;

typedef enum pro_end_cond
{
   PRO_SRF_OPEN = -1,
   PRO_SRF_CAPPED = 14
} ProSrfEndCond;

PRO_END_C_DECLS
 
#endif
