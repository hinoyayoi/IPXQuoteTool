#ifndef PROFLEXOFFSET_H
#define PROFLEXOFFSET_H

/*
   Creo Parametric TOOLKIT declarations related to the Offset Geometry feature.
*/



#include <ProToolkit.h>
#include <ProFlxmdlOpts.h>
#include <ProFlexTanPropOpts.h>

PRO_BEGIN_C_DECLS
/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_STD_SURF_COLLECTION_APPL
      |
      |-- PRO_E_OGF_OFFSET_VAL
      |
      |-- PRO_E_OGF_DIR_OPT
      |
      |-- PRO_E_FLEX_OPTS_CMPND     (General FLX-MDL options branch, see ProFlxmdlOpts.h)
      |   
      |-- PRO_E_FLXSLV_PROP_CONSTRS (General FLX-MDL tangency propagation branch,
      |                              see ProFlexTanPropOpts.h)
      |-- PRO_E_STD_FLEX_PROPAGATION
      
===============================================================================

(2) Feature elements table

---------------------------------------------------------------------------------------------
 Element Id                     Element Name            Data Type                Valid Values
---------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT        
 PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING
 PRO_E_STD_SURF_COLLECTION_APPL References              PRO_VALUE_TYPE_SELECTION Surfaces Set
 PRO_E_OGF_OFFSET_VAL           Offset Value            PRO_VALUE_TYPE_DOUBLE
 PRO_E_OGF_DIR_OPT              Offset Direction        PRO_VALUE_TYPE_INT       Note-1
 PRO_E_FLEX_OPTS_CMPND          FLX-MDL Options         Compound                 Note-2
 PRO_E_FLXSLV_PROP_CONSTRS      FLX-MDL Propagation     Array                    Note-3
 PRO_E_STD_FLEX_PROPAGATION     Propagation             PRO_VALUE_TYPE_SELECTION Note-4
=============================================================================================

(3) Notes

   Note-1  : Mandatory. 
             Possible values: PRO_FLXOGF_DIR_NORMAL, PRO_FLXOGF_DIR_FLIP

   Note-2  : Mandatory - a branch of general flexible modeling option elements.
             Contains integer and chain collection type elements.
             Please consult ProFlxmdlOpts.h to see which elements in the compound
             are relevant to the Offset Geometry feature.

   Note-3  : Optional - An array of conditions to control tangency propagation.
             This is applicable when the tangency propagation is active.
             This implies that PRO_E_FLEX_PROPAGATE_TANGENCY of PRO_E_FLEX_OPTS_CMPND 
             has value PRO_FLEXMODEL_OPT_YES.
             Please consult ProFlexTanPropOpts.h to see the more information about it.


   Note-4  : Optional - A pattern/mirror regonition feature to use, for patterning
             the Offset Geometry feature.

==============================================================================*/

#define PRO_FLXOGF_DIR_NORMAL   1
#define PRO_FLXOGF_DIR_FLIP    -1

/*===========================================================================*/

PRO_END_C_DECLS
#endif

