#ifndef PROMFGELEMCHECKSURF_H
#define PROMFGELEMCHECKSURF_H
/*
   Creo Parametric TOOLKIT declarations related to specification of check surfaces.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
     
     -- PRO_E_CHECK_SURF_COLL
           |
           |-- PRO_E_ADD_REF_PARTS
           |
           |-- PRO_E_USE_MILL_STK
           |
           |-- PRO_E_STD_SURF_COLLECTION_APPL

==============================================================================

(2) Elements table

-----------------------------------------------------------------------------------------
Element Id                     Element Name           Data Type               Valid Value
-----------------------------------------------------------------------------------------
PRO_E_CHECK_SURF_COLL          Check Surfaces         Compound                Note-1 
PRO_E_ADD_REF_PARTS            Parts Option           PRO_VALUE_TYPE_INTEGER  Note-2 
PRO_E_USE_MILL_STK             Stock Allowance Option PRO_VALUE_TYPE_INTEGER  Note-3 
PRO_E_STD_SURF_COLLECTION_APPL Selected Surfaces      Surface Collection      Note-4 

==============================================================================

(3) Notes

Note-1  : Check surfaces compound element.
          Defines surfaces to be checked for collisions.

Note-2  : TRUE  - All reference parts surfaces will be checked for 
                  collisions.
          FALSE - Reference parts surfaces will not be added for 
                  collision checking.

          Optional. FALSE will be used if element doesn't exist.

Note-3  : TRUE  - Mill surface stock allowance parameter will be applied to 
                  check surfaces. Value of stock allowance is defined by 
                  sequence mfg parameter.
          FALSE - Mill surface stock allowance parameter will not be applied.

          Optional. FALSE will be used if element doesn't exist.

Note-4  : Collection of selected surfaces to be checked for collisions.
          Optional.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMCHECKSURF_H*/
