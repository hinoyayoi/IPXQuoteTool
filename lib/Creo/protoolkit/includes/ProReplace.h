#ifndef PROREPLACEH
#define PROREPLACEH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS



/*****************************************************************************\

Feature element tree

  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_STD_REPLACED_SURF
    |
    |--PRO_E_STD_REPLACEMENT_SURF
    |
    |--PRO_E_STD_KEEP_QUILT


Feature elements table

------------------------------------------------------------------------------------------------
Element Id                     Element Name             Data Type                  Valid Values
------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type             PRO_VALUE_TYPE_INT         PRO_FEAT_REPLACE_SURF
PRO_E_STD_REPLACED_SURF        Replace surf             PRO_VALUE_TYPE_SELECTION   PRO_SURFACE
PRO_E_STD_REPLACEMENT_SURF     Quilt                    PRO_VALUE_TYPE_SELECTION   PRO_QUILT
PRO_E_STD_KEEP_QUILT           Keep  quilt              PRO_VALUE_TYPE_INT         See note 2


Note 1
   PRO_SURFACE  -- Replace PRO_E_STD_REPLACED_SURF with the surface. Leave the quilt this surface 
                   belongs to intact.
   PRO_QUILT    -- Replace PRO_E_STD_REPLACED_SURF with the quilt.  
Note 2
   This option applied only if PRO_E_STD_REPLACEMENT_SURF is of PRO_QUILT type.
   1            -- Keep quilt
   NULL_CHOICE  -- Use quilt in replacement


\*****************************************************************************/

PRO_END_C_DECLS

#endif


