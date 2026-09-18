#ifndef PROFLEXMAG_H
#define PROFLEXMAG_H

/*
   Creo Parametric TOOLKIT declarations related to the Modify Analytic Geometry feature.
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
      |-- PRO_E_STD_FLEX_PROPAGATION
      |
      |-- PRO_E_FLEX_OPTS_CMPND   (General FLX-MDL options branch, see ProFlxmdlOpts.h)
      |      
      |-- PRO_E_FLXSLV_PROP_CONSTRS (General FLX-MDL tangency propagation branch,
      |                              see ProFlexTanPropOpts.h)
      |-- PRO_E_MAG_ANGLE_VAL     (Conic surface)
      |      
      |-- PRO_E_MAG_RADII_VAL     (Cylindric and toroidal surface)
      |      
      |-- PRO_E_MAG_RADII2_VAL    (Toroidal surface)
      
===============================================================================

(2) Feature elements table

---------------------------------------------------------------------------------------------
 Element Id                     Element Name            Data Type                Valid Values
---------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT        
 PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING
 PRO_E_STD_SURF_COLLECTION_APPL Surface                 PRO_VALUE_TYPE_SELECTION Note-1
 PRO_E_STD_FLEX_PROPAGATION     Propagation             PRO_VALUE_TYPE_SELECTION Note-2
 PRO_E_FLEX_OPTS_CMPND          FLX-MDL Options         Compound                 Note-3
 PRO_E_FLXSLV_PROP_CONSTRS      FLX-MDL Propagation     Array                    Note-4
 PRO_E_MAG_ANGLE_VAL            Angle                   PRO_VALUE_TYPE_DOUBLE    Note-5
 PRO_E_MAG_RADII_VAL            Radius                  PRO_VALUE_TYPE_DOUBLE    Note-6
 PRO_E_MAG_RADII2_VAL           Second Radius           PRO_VALUE_TYPE_DOUBLE    Note-7
=============================================================================================

(3) Notes

    Note-1  : Mandatory - the surface to modify. Valid selections are Cylindric
              Conic or Toroidal surface.

    Note-2  : Optional - A pattern/mirror regonition feature to use, for patterning
              the Modify Analytic Surface feature.

    Note-3  : Mandatory - a branch of general flexible modeling option elements.
              Contains integer and chain collection type elements.
              Please consult ProFlxmdlOpts.h to see which elements in the compound
              are relevant to the Modify Analytic Surface feature.

    Note-4  : Optional - An array of conditions to control tangency propagation.
              This is applicable when the tangency propagation is active.
              This implies that PRO_E_FLEX_PROPAGATE_TANGENCY of PRO_E_FLEX_OPTS_CMPND 
              has value PRO_FLEXMODEL_OPT_YES.
              Please consult ProFlexTanPropOpts.h to see the more information about it.

    Note-5  : Mandatory for a conic surface -  The angle value.

    Note-6  : Mandatory for a cylindric and a toroidal surface - The primary radius value.

    Note-7  : Mandatory for a toroidal surface - The secondary radius value.

==============================================================================*/


PRO_END_C_DECLS
#endif

