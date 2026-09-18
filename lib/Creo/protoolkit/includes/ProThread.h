#ifndef PROTHREAD_H
#define PROTHREAD_H

/*
   Creo Parametric TOOLKIT declarations related to cosmetic thread feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS
/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |--PRO_E_FEATURE_TYPE
      |
      |--PRO_E_FEATURE_FORM
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_THRD_TYPE_OPT_NEW
      |
      |-- PRO_E_THRD_SERIES_NEW 
      |
      |-- PRO_E_THRD_SCREWSIZE_NEW
      |
      |-- PRO_E_THRD_SURF_NEW
      |
      |-- PRO_E_THRD_DIAM_NEW
      |
      |-- PRO_E_THRD_START_REF_NEW
      |
      |-- PRO_E_THRD_DEP_COMP_NEW
      |      | 
      |      |-- PRO_E_THRD_DEP_OPT_NEW
      |      |
      |      |-- PRO_E_THRD_FLIP_OPT_NEW
      |      |
      |      |-- PRO_E_THRD_DEP_VAL_NEW
      |      |
      |      |-- PRO_E_THRD_END_REF
      |
      |-- PRO_E_THRD_NOTE_PARAMS_NEW

===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------------------
 Element Id                  Element Name            Data Type                Valid Values
------------------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE          Feature Type            PRO_VALUE_TYPE_INT        Note-1
 PRO_E_FEATURE_FORM          Feature Form            PRO_VALUE_TYPE_INT        Note-2
 PRO_E_STD_FEATURE_NAME      Feature Name            PRO_VALUE_TYPE_WSTRING    Note-3
 PRO_E_THRD_TYPE_OPT_NEW     Thread Type             PRO_VALUE_TYPE_BOOLEAN    Note-4
 PRO_E_THRD_SERIES_NEW       Thread Series           PRO_VALUE_TYPE_INT        Note-5
 PRO_E_THRD_SCREWSIZE_NEW    Screw Size              PRO_VALUE_TYPE_INT        Note-6
 PRO_E_THRD_SURF_NEW         Threaded surface        PRO_VALUE_TYPE_SELECTION  Note-7
 PRO_E_THRD_DIAM_NEW         Thread diameter         PRO_VALUE_TYPE_DOUBLE     Note-8
 PRO_E_THRD_START_REF_NEW    Thread start reference  PRO_VALUE_TYPE_SELECTION  Note-9
 PRO_E_THRD_DEP_COMP_NEW     Thread Depth            Compound                  
 PRO_E_THRD_DEP_OPT_NEW      Thread depth option     PRO_VALUE_TYPE_BOOLEAN    Note-10
 PRO_E_THRD_FLIP_OPT_NEW     Thread depth direction  PRO_VALUE_TYPE_INT        Note-11
 PRO_E_THRD_DEP_VAL_NEW      Thread Depth Value      PRO_VALUE_TYPE_DOUBLE     Note-12
 PRO_E_THRD_END_REF          Thread depth reference  PRO_VALUE_TYPE_SELECTION  Note-13
 PRO_E_THRD_NOTE_PARAMS_NEW  Parameters              PRO_VALUE_TYPE_POINTER    Note-14

=========================================================================================

(3) Notes

   Note-1  : PRO_FEAT_THREAD. Mandatory.

   Note-2  : PRO_EXTRUDE or PRO_REVOLVE depending on Threaded surface. Optional.

   Note-3  : Cosmetic Thread feature name.
             Default value is "COSMETIC_THREAD". Optional.

   Note-4  : FALSE for simple thread, TRUE for standard thread. Optional.
   
   Note-5  : From the *.hol files, different THREAD_SERIES information are gathered
             and a list is formed. The current index to the list stored in this element.

   Note-6  : Stores the index to the screw_size list. The screw_size list extracted from the
             *.hol corresponding to the thread series. Optional.

   Note-7  : Stores threaded surface. Mandatory.

   Note-8  : If the referenced threaded surface is conical, [0.0, diam/4],
             where "diam" is the estimate largest diameter of the cone;
             otherwise, [0.1, MAX_DIM_VALUE]. Optional. 

   Note-9  : Stores start thread location. Mandatory.

   Note-10 : FALSE for "Blind" depth option, TRUE for "To Selected" depth option. Optional.

   Note-11 : The flip direction of type ProThreadFlip. Optional.

   Note-12 : [0.1, MAX_DIM_VALUE] when PRO_E_THRD_DEP_OPT_NEW is FALSE. Optional.
             The node is invisible if PRO_E_THRD_DEP_OPT_NEW is TRUE.
   
   Note-13 : Stores the upto reference when PRO_E_THRD_DEP_OPT_NEW is TRUE,
             The node is invisible if PRO_E_THRD_DEP_OPT_NEW is FALSE.
             Mandatory when PRO_E_THRD_DEP_OPT_NEW is TRUE.

   Note-14 : ProThreadParams. Optional.

==============================================================================*/

/* PRO_E_THRD_FLIP_OPT_NEW */
typedef enum pro_thd_flip
{
   PRO_COSTHREAD_THD_FLIP_OPT_FLIP = -1,
   PRO_COSTHREAD_THD_FLIP_OPT_NORM = 1
}ProThreadFlip;

typedef struct named_param ** ProThreadParams; 

PRO_END_C_DECLS
#endif

