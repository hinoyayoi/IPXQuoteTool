#ifndef PROSYMMETRYRECOGNITION_H
#define PROSYMMETRYRECOGNITION_H

/*
   Creo Parametric TOOLKIT declarations related to the Symmetry Recognition.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS
/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |--PRO_E_STD_FEATURE_NAME
      |
      |--PRO_E_PSR_PLN_REF
      |
      |--PRO_E_PSR_DTM_REF
      |
      |--PRO_E_PSR_RCG_OPT


(2) Feature elements table

-----------------------------------------------------------------------------------------
 Element Id             Element Name                Data Type                Valid Values
-----------------------------------------------------------------------------------------
 PRO_E_STD_FEATURE_NAME Feature Name                 PRO_VALUE_TYPE_WSTRING  
 PRO_E_PSR_PLN_REF      Seeds/Seed & Symmetry Plane  PRO_ELEM_TYPE_MULTI_VALUE Note1
 PRO_E_PSR_DTM_REF      Curves and Datums (1st Seed) PRO_ELEM_TYPE_MULTI_VALUE Note2
 PRO_E_PSR_RCG_OPT      Recognition Option           PRO_VALUE_TYPE_INT       Note3 
=============================================================================================
(3) Notes

   Note1  : Mandatory
            selection of two seed surfaces or one seed surface and a plane for symmetry
   Note2  : Optional
            selection of associated curves and datums
   Note3  : Mandatory.
            Possible values: PRO_PSR_IDENTICAL, PRO_PSR_SIMILAR 
==============================================================================*/

/* PRO_E_PSR_RCG_OPT Possible Values */
#define PRO_PSR_IDENTICAL   0
#define PRO_PSR_SIMILAR     1

/*===========================================================================*/

PRO_END_C_DECLS
#endif
