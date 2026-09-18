#ifndef PROEXCLCNTRSH
#define PROEXCLCNTRSH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_STD_EXCL_CNTRS
      |
      |-- PRO_E_STD_EXCL_CNTRS_ONE_CNTR
           |
           |-- PRO_E_STD_EXCL_CNTR_SRF_REF      
           |
           |-- PRO_E_STD_EXCL_CNTR_EDGE_REF      
           
===============================================================================

(2) Feature elements table

-----------------------------------------------------------------------------------------------
Element Id                     Element Name              Data Type                 Valid Values
-----------------------------------------------------------------------------------------------
PRO_E_STD_EXCL_CNTRS           Excluded contours         Array                     
PRO_E_STD_EXCL_CNTRS_ONE_CNTR  One excluded contour      Compound.
PRO_E_STD_EXCL_CNTR_SRF_REF    Excluded contour srf ref  PRO_VALUE_TYPE_SELECTION  Note-1   
PRO_E_STD_EXCL_CNTR_EDGE_REF   Excluded contour srf ref  PRO_VALUE_TYPE_SELECTION  Note-2
===============================================================================

(3) Notes

   Note-1 : Surface reference of one contour.
   
   Note-2 : Edge reference of one contour. Can be any edge of the contour.          
  
==============================================================================*/

PRO_END_C_DECLS

#endif
