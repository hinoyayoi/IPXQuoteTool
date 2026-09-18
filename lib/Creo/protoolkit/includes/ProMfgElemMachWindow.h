#ifndef PROMFGELEMMACHWINDOW_H
#define PROMFGELEMMACHWINDOW_H
/*
   Creo Parametric TOOLKIT declarations related to specification of surfaces collected
   with mill window
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
     
     -- PRO_E_MFG_CMP_MILL_WIND
           |
           |-- PRO_E_MFG_MILL_WIND
           |
           |-- PRO_E_MFG_CMP_CLOSED_LOOPS
           |       |
           |       |-- PRO_E_MFG_CLOSED_LOOP_ARR
           |           |
           |           |-- PRO_E_MFG_CLOSED_LOOP_REF_ITEM
           |                  |
           |                  |-- PRO_E_STD_CURVE_COLLECTION_APPL
           |                  |
           |                  |-- PRO_E_MFG_CLOSED_LOOP_ID
           |
           |-- PRO_E_MFG_EXCL_SRF_COLL
           |       |
           |       |-- PRO_E_STD_SURF_COLLECTION_APPL
           |
           |-- PRO_E_MFG_SURF_SIDE_COMPOUND
           |       |
           |       |-- PRO_E_MFG_SURF_SIDE_TOLERANCE
           |       |
           |       |-- PRO_E_MFG_SURF_SIDE_FLIP_QUILTS
           |

==============================================================================

(2) Elements table

------------------------------------------------------------------------------------------
Element Id                       Element Name        Data Type                 Valid Value
------------------------------------------------------------------------------------------
PRO_E_MFG_CMP_MILL_WIND          Mill Window         Compound                  Note-1 
PRO_E_MFG_MILL_WIND              Window Selection    PRO_VALUE_TYPE_SELECTION  Note-2 
PRO_E_MFG_CMP_CLOSED_LOOPS       Closed Loops        Compound                  Note-3 
PRO_E_MFG_CLOSED_LOOP_ARR        Closed Loop Array   Array                     Note-4 
PRO_E_MFG_CLOSED_LOOP_REF_ITEM   Closed Loop         Compound                  Note-5 
PRO_E_MFG_CLOSED_LOOP_ID         Closed Loop Id      PRO_VALUE_TYPE_INTEGER    Note-6 
PRO_E_STD_CURVE_COLLECTION_APPL  Chain               PRO_VALUE_TYPE_POINTER    Note-7 
PRO_E_MFG_EXCL_SRF_COLL          Excluded Surfaces   Compound                  Note-8 
PRO_E_STD_SURF_COLLECTION_APPL   Surfaces Collection PRO_VALUE_TYPE_SELECTION  Note-9 
PRO_E_MFG_SURF_SIDE_COMPOUND     Surface Side        Compound                  Note-10 
PRO_E_MFG_SURF_SIDE_TOLERANCE    Grouping Tolerance  PRO_VALUE_TYPE_DOUBLE     Note-11 
PRO_E_MFG_SURF_SIDE_FLIP_QUILTS  Flipped Quilts      PRO_VALUE_TYPE_SELECTION  Note-12

==============================================================================

(3) Notes

Note-1  : Mill window compound element.

Note-2  : Selection of mill window feature.
          Mandatory.

Note-3  : Closed loop compound specification.
          Optional.

Note-4  : Array of closed loop specifications.
          Optional.

Note-5  : Closed loop specification.
          Optional.

Note-6  : Closed loop id.
          Internal use only. Should not be added or modified.

Note-7  : Chain collection.
          Mandatory child of PRO_E_MFG_CLOSED_LOOP_REF_ITEM compound element.

Note-8  : Excluded surfaces compound specification.
          Applicable only for finishing and corner finishing sequences.
          Optional.

Note-9  : Surface collection.
          Optional.

Note-10 : Surface side compound specification.
          Applicable only if selected mill window feature created with property
          "Adjust geometry collection within window" activated and set for 
          quilt collection.
          Optional.

Note-11 : Tolerance used for grouping of quilts.
          Optional.

Note-12 : Selection of quilts with changed normal.
          Element supports multiple selections.
          Optional.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMMACHWINDOW_H*/
