#ifndef PROMFGELEMSURFSIDE_H
#define PROMFGELEMSURFSIDE_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree

  -- PRO_E_MFG_SURF_SIDE_COMPOUND
             |
             |-- PRO_E_MFG_SURF_SIDE_TOLERANCE
             |
             |-- PRO_E_MFG_SURF_SIDE_FLIP_QUILTS

===============================================================================

(2) Elements table

----------------------------------------------------------------------------------------------
Element Id                    Element Name              Data Type                 Valid Values
----------------------------------------------------------------------------------------------

PRO_E_MFG_SURF_SIDE_COMPOUND    Surface Side            Compound                   Note-1
PRO_E_MFG_SURF_SIDE_TOLERANCE   Grouping Tolerance      PRO_VALUE_TYPE_DOUBLE      Note-2
PRO_E_MFG_SURF_SIDE_FLIP_QUILTS Flipped Quilts          PRO_VALUE_TYPE_SELECTION   Note-3
==============================================================================================

(3) Notes

Note-1  :  Surface Side compound.
Note-2  :  Tolerance used for composing groups of adjacent quilts. Value should be nonnegative.
           Mandatory.
Note-3  :  Selection of quilts to be flipped. 
           Element supports multiple selections.
           Optional.

==============================================================================*/

PRO_END_C_DECLS


#endif /* PROMFGELEMSURFSIDE */
