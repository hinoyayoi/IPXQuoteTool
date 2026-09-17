#ifndef PROSMTBENDBACK_H
#define PROSMTBENDBACK_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Bend Back feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE		
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_BEND_BACK_SUB_TYPE	
     |				
     |--PRO_E_SMT_PRIMARY_FIXED_GEOM	
     |    |
     |    |--PRO_E_SMT_FIXED_REF	
     |    |
     |    |--PRO_E_SMT_FIXED_REF_SIDE   
     |
     |--PRO_E_SMT_BBACK_REF_ARR		
     |    |			
     |    |--PRO_E_SMT_BBACK_REF
     |         |
     |         |--PRO_E_SMT_BBACK_SINGLE_REF	
     |          			
     |
     |--PRO_E_SMT_BBACK_FLAT_CONTOURS_ARR
          |
          |--PRO_E_SMT_GEOM_CONTOUR
               |
               |--PRO_E_SMT_GEOM_CONTOUR_GEOM	
	       |			
               |
               |--PRO_E_SMT_GEOM_CONTOUR_EDGE   
					

*****************************************************************************



===============================================================================
Element Id                        Element Name            Data Type
===============================================================================
PRO_E_FEATURE_TYPE		  Feature Type	          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME		  Feature Name            PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_BEND_BACK_SUB_TYPE	  Auto/Select Unbend      PRO_VALUE_TYPE_INT
PRO_E_SMT_PRIMARY_FIXED_GEOM      Primary fixed geom      Compound
PRO_E_SMT_FIXED_REF		  Fixed Geom or Edge      PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_FIXED_REF_SIDE	  Fixed Side for Edge     PRO_VALUE_TYPE_INT
PRO_E_SMT_BBACK_REF_ARR	          Geometry arr to unbend  Array
PRO_E_SMT_BBACK_REF		  Reference to unbend     Compound
PRO_E_SMT_BBACK_SINGLE_REF	  Reference to unbend     PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_BBACK_FLAT_CONTOURS_ARR Contours to keep flat   Array
PRO_E_SMT_GEOM_CONTOUR            Contours to keep flat   Compound
PRO_E_SMT_GEOM_CONTOUR_GEOM                               PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_GEOM_CONTOUR_EDGE                               PRO_VALUE_TYPE_SELECTION

*****************************************************************************



===============================================================================
Element Id                        	Valid Values
===============================================================================
PRO_E_FEATURE_TYPE                	PRO_FEAT_BEND_BACK ( Not redefinable )
PRO_E_SMT_BEND_BACK_SUB_TYPE            ProBendBackSubType
PRO_E_SMT_FIXED_REF		  	Surface, Edge
PRO_E_SMT_FIXED_REF_SIDE		ProSmtFixedRefSide
PRO_E_SMT_BBACK_SINGLE_REF		Surface, Edge, Intent surface/chain
PRO_E_SMT_GEOM_CONTOUR_GEOM             Driven/Offset Surface, one of PRO_E_SMT_BBACK_SINGLE_REF.
PRO_E_SMT_GEOM_CONTOUR_EDGE             Edge that belongs to PRO_E_SMT_GEOM_CONTOUR_GEOM



*/
typedef enum _ProBendBackSubType	
{
  PRO_BEND_BACK_SUB_TYPE_UNDEF	= -1,
  PRO_BEND_BACK_ALL		=  0,
  PRO_BEND_BACK_SELECTED	=  1

} ProBendBackSubType;

PRO_END_C_DECLS
#endif /*PROSMTBENDBACK_H*/
