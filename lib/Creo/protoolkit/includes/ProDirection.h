#ifndef PRODIRECTIONH
#define PRODIRECTIONH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Direction utility tree

  PRO_E_DIRECTION_COMPOUND
  |
  |-PRO_E_DIRECTION_REFERENCE
  |-PRO_E_DIRECTION_FLIP

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id               Element Name        Data Type             Valid Values
-------------------------------------------------------------------------------
PRO_E_DIRECTION_COMPOUND  Direction root      Compound
PRO_E_DIRECTION_REFERENCE Direction reference PRO_VALUE_TYPE_SELECTION Note-1
PRO_E_DIRECTION_FLIP      Direction side      PRO_VALUE_TYPE_INT       Note-2
==============================================================================

(3) Notes

Note-1: Direction Reference. Valid references are
        Straight Edge, Straight Curve, Planar Surface, Datum Plane,
	Datum axis, Datum Csys Axis.

Note-2: Direction flip.
        Normal direction ( PRO_DIRECTION_FLIP_ALONG ) or 
        Opposite direction ( PRO_DIRECTION_FLIP_AGAINST ).
        Default value is PRO_DIRECTION_FLIP_ALONG.
	 
=============================================================================*/

typedef enum 
{ 
    PRO_DIRECTION_FLIP_ALONG   =  1, 
    PRO_DIRECTION_FLIP_AGAINST = -1 
} ProDirectionFlipOption; 


PRO_END_C_DECLS

#endif
