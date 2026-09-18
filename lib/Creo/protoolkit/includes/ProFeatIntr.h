#ifndef PROFEATINTR_H
#define PROFEATINTR_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS
 
/*****************************************************************************\
 
Feature element tree
 
   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |
     |
     |
     |
     |
     |
     |
     |--PRO_E_INT_PARTS
	  |--PRO_E_FEATURE_INTERSECTION
	       |--PRO_E_FEATURE_INTERSECT_PART
               |--PRO_E_FEATURE_INTERSECT_LEVEL


3. Feature elements table
 
--------------------------------------------------------------------------------------------
Element Id                       Element Name   Data Type			Valid Values
-----------------------------------------------------------------------------------------
PRO_E_INT_PARTS	 		 Intersections  Array 
PRO_E_FEATURE_INTERSECTION	 Intersections  Compound
PRO_E_FEATURE_INTERSECT_PART     Intersect Part	PRO_VALUE_TYPE_SELECTION  	See Note 1
PRO_E_FEATURE_INTERSECT_LEVEL    Visib level	PRO_VALUE_TYPE_INT        	See Note 2


\*****************************************************************************/

/*===========================================================================*/

/* Note 1.   Intersect Part Values */

/* The selection should be to the part which is to be intersected by
 * the assembly feature.  The selection must include the path from the 
 * owner assembly to the intersected part.  The actual selection can be to any
 * item in the part or to the entire part itself.
 *
 * Special Values:::
 * 
 *   If the Selection refers to the top level assembly (any object in the
 *   top level assembly is acceptable) or if the value is NULL, then 
 *   intersected parts will be selected automatically based on the value
 *   of Visib level.  If the visibility level is 0, then parts will be 
 *   automaticaly selected and the intersection will be visible in the
 *   top level assembly only.  If the visibility level is -1, then the
 *   intersections will be visible in the parts themselves.  Any other
 *   value for visiblity level with this special selection is invalid.
 */


/*===========================================================================*/

/*===========================================================================*/

/* Note 2.   Visib Level Values */

/* This integer value sets where the assembly feature is visible.  If the
 * value is 0, then the feature is only visible in the top level assembly.
 * That is, if you retrieve the part or any sub-assembly containing that part
 * the intersection is not visible.   If the value is the same as the depth to
 * the part (1 if part is directly assembled, 2 if it is contained in a 
 * sub-assembly of the top level assembly, etc.) the intersection is visible
 * in the part itself.  Any other value will make the intersection visible in
 * the corresponding sub-assembly and above.
 *
 * Special Values:::
 * 
 *   If the value of Visib level is -1 and the intersect part references
 *   a part which is currently intersected by the feature, then the
 *   intersection with this part is removed (this works for ProFeatureWithoptionsRedefine
 *   only).  If the Intersect Part is either NULL or refers to the top level
 *   assembly, then the value of -1 indicates that parts should be 
 *   automatically selected with the intersection visible in the part.  Any
 *   other values for Intersect Part selection are invalid when visibility
 *   level is -1.
 */

/*===========================================================================*/


PRO_END_C_DECLS

#endif /* PROFEATINTR_H */
