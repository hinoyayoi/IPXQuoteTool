#ifndef PROFLEXMIRROR_H
#define PROFLEXMIRROR_H

/*
   Creo Parametric TOOLKIT declarations related to the Mirror Geometry Feature in
   Flexible Modeling.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS
/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |--PRO_E_STD_FEATURE_NAME
      |
      |--PRO_E_MGF_REFS
      |    |
      |    |--PRO_E_STD_SURF_COLLECTION_APPL
      |    |
      |    |--PRO_E_MGF_MIRROR_PLANE
      |    |
      |    |--PRO_E_MGF_DATUMS
      |
      |--PRO_E_FLEX_OPTS_CMPND
           |
           |......

(2) Feature elements table

-----------------------------------------------------------------------------------------
 Element Id             Element Name                Data Type                Valid Values
-----------------------------------------------------------------------------------------
 PRO_E_STD_FEATURE_NAME Feature Name                PRO_VALUE_TYPE_WSTRING  
 PRO_E_MGF_REFS         Mirror References           Compound
 PRO_E_STD_SURF_COLLECTION_APPL Mirror Surfaces     PRO_VALUE_TYPE_SELECTION Note1
 PRO_E_MGF_MIRROR_PLANE Mirror Plane                PRO_VALUE_TYPE_SELECTION Note2
 PRO_E_MGF_DATUMS       Mirror Curves and Datums    PRO_VALUE_TYPE_SELECTION Note3
 PRO_E_FLEX_OPTS_CMPND  FLX-MDL Options             Compound                 Note4
=============================================================================================
(3) Notes

   Note1  : Mandatory
            selection of a surface set
   Note2  : Mandatory
            datum plane selection
   Note3  : Optional
            selection of curves and datums
   Note4  : see detailed info in ProFlxmdlOpts.h.
==============================================================================*/

/*===========================================================================*/

PRO_END_C_DECLS
#endif
