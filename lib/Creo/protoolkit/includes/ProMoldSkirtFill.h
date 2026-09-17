#ifndef PROMOLDSKIRTFILL_H
#define PROMOLDSKIRTFILL_H

/*
   Creo Parametric TOOLKIT declarations related to skirt extension 
   surface feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SKIRT_REF_MODEL
      |
      |-- PRO_E_SKIRT_PULL_DIR_COMPOUND
      |      |
      |      |-- PRO_E_DIRECTION_COMPOUND
      |
      |-- PRO_E_SKIRT_FILL_SET_ARR
             |
             |-- PRO_E_SKIRT_FILL_SET_COMPOUND
                    |
                    |-- PRO_E_SKIRT_FILL_SET_REF_IDX
                    |
                    |-- PRO_E_SKIRT_FILL_CURVES_COMPOUND
                    |      |
                    |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
                    |
                    |-- PRO_E_SKIRT_FILL_TYPE
                    |
                    |-- PRO_E_SKIRT_FILL_PLANE
                    |
                    |-- PRO_E_SKIRT_FILL_SURF_COMPOUND
                    |      |
                    |      |-- PRO_E_STD_SURF_COLLECTION_APPL
                    |
                    |-- PRO_E_SKIRT_FILL_LOOP_OFFSET

==============================================================================

(2) Elements table

-------------------------------------------------------------------------------------------------------
Element Id                       Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type           PRO_VALUE_TYPE_INT        PRO_FEAT_DATUM_SURF
PRO_E_FEATURE_FORM               Feature Form           PRO_VALUE_TYPE_INT        PRO_SKIRT_FILL
PRO_E_STD_FEATURE_NAME           Feature Name           PRO_VALUE_TYPE_WSTRING    Wide character string
PRO_E_SKIRT_REF_MODEL            Reference Model        PRO_VALUE_TYPE_SELECTION  Note-1
PRO_E_SKIRT_PULL_DIR_COMPOUND    Pull Direction         Compound                  Note-2
PRO_E_DIRECTION_COMPOUND         Direction Element      Compound                  Note-3
PRO_E_SKIRT_FILL_SET_ARR         Fill Set Array         Array                     Note-4
PRO_E_SKIRT_FILL_SET_COMPOUND    Fill Set               Compound                  Note-5
PRO_E_SKIRT_FILL_SET_REF_IDX     Fill Reference Index   PRO_VALUE_TYPE_INT        Note-6
PRO_E_SKIRT_FILL_CURVES_COMPOUND Fill Curves Compound   Compound                  Note-7
PRO_E_SKIRT_FILL_TYPE            Fill Type              PRO_VALUE_TYPE_INT        Note-8
PRO_E_SKIRT_FILL_PLANE           Fill Plane             PRO_VALUE_TYPE_SELECTION  Note-9
PRO_E_SKIRT_FILL_SURF_COMPOUND   Fill Surfaces Compound Compound                  Note-10
PRO_E_SKIRT_FILL_LOOP_OFFSET     Loop Offset            PRO_VALUE_TYPE_DOUBLE     Note-11
=======================================================================================================

(3) Notes

Note-1  : Mandatory.  
          Reference model used for creating extension surfaces. Valid reference is a   
          single PRO_PART.

Note-2  : Optional if default pull direction exist.
          Reference for view direction. If not specified, default pull direction is 
          used provided the pull direction exist. Valid reference is PRO_E_DIRECTION_COMPOUND.

Note-3  : Direction Reference. For more details refer ProDirection.h

Note-4  : Mandatory.
         An array element having PRO_E_SKIRT_FILL_SET_COMPOUND sets.

Note-5  : Mandatory. 
          A unique value for each compound set PRO_E_SKIRT_FILL_SET_COMPOUND.

Note-6  : Mandatory. 
          A unique value for each compound set PRO_E_SKIRT_EXT_SET_COMPOUND.

Note-7  : Mandatory.
          Compound element for closure curves collection.

Note-8  : Mandatory.
          Type of closure. The valid values are ProSkirtFillType.
  
Note-9  : Mandatory for the closure types - PRO_SKIRT_FILL_MID_PLANE and PRO_SKIRT_FILL_CAP_PLANE.
          Valid selection is a planar surface.

Note-10 : Mandatory for the closure types - PRO_SKIRT_FILL_MID_SURF and PRO_SKIRT_FILL_CAP_SURF
          Valid selections are surfaces other than those from reference part.

Note-11 : Optional.
          Used for the closure types - PRO_SKIRT_FILL_MID_PLANE and PRO_SKIRT_FILL_CAP_PLANE.

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMOLDSKIRTFILL_H */
