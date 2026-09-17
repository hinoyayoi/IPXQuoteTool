#ifndef PROMOLDSHUTSRF_H
#define PROMOLDSHUTSRF_H

/*
 * Creo Parametric TOOLKIT declarations related to shut-off surface feature.
 */



#include <ProToolkit.h>

typedef enum pro_shut_srf_ref_type
{
    PRO_SHUT_SRF_SRF_REF,
    PRO_SHUT_SRF_CRV_REF
}ProShutSrfRefType;

#define PRO_SHUT_SRF_SHUT_ALL  2

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SHUT_SRF_REF_TYPE
      |
      |-- PRO_E_SHUT_SRF_SRF_REFS
      |    |
      |    |-- PRO_E_STD_SURF_COLLECTION_APPL
      |
      |-- PRO_E_SHUT_SRF_COLL_CRV_CMP
      |    |
      |    |-- PRO_E_SHUT_SRF_ARR_COLL_CRV
      |          |
      |          |--PRO_E_STD_CURVE_COLLECTION_APPL
      |
      |-- PRO_E_SHUT_SRF_CAP_SRFS
      |    |
      |    |-- PRO_E_STD_SURF_COLLECTION_APPL
      |
      |-- PRO_E_SHUT_SRF_CLOSE_ALL

==========================================================================================

(2) Elements table

-------------------------------------------------------------------------------------------
Element Id                      Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type           PRO_VALUE_TYPE_INT        PRO_MOLD_SHUTOFF_SRF
PRO_E_STD_FEATURE_NAME          Feature Name           PRO_VALUE_TYPE_WSTRING    Wide character string
PRO_E_SHUT_SRF_REF_TYPE         References type        PRO_VALUE_TYPE_INT        Note-1
PRO_E_SHUT_SRF_SRF_REFS         Surface References     Compound                  Note-2
PRO_E_STD_SURF_COLLECTION_APPL  Reference Surfaces     PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_SHUT_SRF_COLL_CRV_CMP     Include/Exclude loops  Compound                  Note-4
PRO_E_SHUT_SRF_ARR_COLL_CRV     collect curves array   Array                     Note-5
PRO_E_SHUT_SRF_CAP_SRFS         Cap Surfaces           Compound                  Note-6
PRO_E_STD_SURF_COLLECTION_APPL  Reference Surfaces     PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_STD_CURVE_COLLECTION_APPL Include/Exclude        PRO_VALUE_TYPE_SELECTION  Note-8
                                Curve-Chains
PRO_E_SHUT_SRF_CLOSE_ALL        Close Loops            PRO_VALUE_TYPE_BOOLEAN    Note-9
=============================================================================================

(3) Notes

Note-1  : Type of references for selection. Either surface references or curve references 
          can be selected.
	  Valid value for this element PRO_E_SHUT_SRF_REF_TYPE is ProShutSrfRefType.
          Mandatory.

Note-2  : Compund of surface references.
          Mandatory.

Note-3  : Select surfaces for which shut-off surfaces need to be created. Multiple selection
          is allowed. The selection of surfaces is required only when PRO_E_SHUT_SRF_REF_TYPE
          is PRO_SHUT_SRF_SRF_REF. The surfaces would be automatically populated if the value
          of PRO_E_SHUT_SRF_REF_TYPE is PRO_SHUT_SRF_CRV_REF.


Note-4  : Compund of curve chains. Curve chains to either include or exclude from creating
          shut-off surfaces.

Note-5  : Array of curve chain loops to include or exclude from creating shut-off surfaces.
          Optional if the value of PRO_E_SHUT_SRF_CLOSE_ALL is PRO_SHUT_SRF_SHUT_ALL.
          if the value of element PRO_E_SHUT_SRF_CLOSE_ALL is PRO_SHUT_SRF_SHUT_ALL,
          then selected loops are excluded for creating shut-off surfaces. Otherwise
          shut-off surfaces are created only on these selected loops (include loops).

Note-6  : Compund of cap surface references.
          Optional.

Note-7  : Select reference surfaces for capping open loops. Multiple selection is allowed.
          If the datum plane is selected, then multiple selection is not allowed. This
          element is required only when open curve-chain loops are selected. 
          Optional.

Note-8  : Select reference chain loops to include or exclude when creating shut-off 
          surfaces. Selected reference chain loops would be excluded when 
          PRO_E_SHUT_SRF_CLOSE_ALL is true. Both closed and open loops can be selected. 
          If the value of PRO_E_SHUT_SRF_REF_TYPE is PRO_SHUT_SRF_CRV_REF, then only 
          one-sided edges can be selected as curve chain loops.

Note-9  : Option to include all loops when creating shutoff surfaces. Valid value is
          PRO_SHUT_SRF_SHUT_ALL 

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMOLDSHUTSRF_H */
