#ifndef PROMFGELEMPREREQUISITE_H
#define PROMFGELEMPREREQUISITE_H
/*
   Creo Parametric TOOLKIT declarations related to sequence prerequisites specification
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree

      
     -- PRO_E_MFG_PREREQUISITE_ARR
           |
           |- PRO_E_MFG_PREREQUISITE_COMPOUND
                 |
                 |- PRO_E_MFG_PREREQUISITE_ID
      
==============================================================================

(2) Elements table

-----------------------------------------------------------------------------
Element Id                       Element Name       Data Type          Values
-----------------------------------------------------------------------------
PRO_E_MFG_PREREQUISITE_ARR       Prerequisite Array Array              Note-1 
PRO_E_MFG_PREREQUISITE_COMPOUND  Prerequisite       Compound           Note-2 
PRO_E_MFG_PREREQUISITE_ID        Prerequisite Id    PRO_VALUE_TYPE_INT Note-3 

=============================================================================

(3) Notes

Note-1 : Array of ids of prerequisite sequences.
         Optional

Note-2 : Compound element.
         Optional

Note-3 : Id of prerequisite sequence.
         Mandatory child of PRO_E_MFG_PREREQUISITE_COMPOUND element.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMPREREQUISITE_H*/
