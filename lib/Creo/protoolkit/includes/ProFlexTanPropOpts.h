#ifndef PROFLEXTANPROPOPTS_H
#define PROFLEXTANPROPOPTS_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*=========================================================================
  Generic Flexible Modeling Tangency Propagation options branch.

  The branch exists in: PRO_FEAT_FLEXMOVE
                        PRO_FEAT_FLX_OGF
                        PRO_FEAT_ANALYT_GEOM
===========================================================================*/

/*=========================================================================
=================================================================================================

(1) Element tree

  PRO_E_FLXSLV_PROP_CONSTRS
     |
     |-- PRO_E_FLXSLV_CONSTR
            |
            |-- PRO_E_FLXSLV_CONSTR_REFS
            |
            |-- PRO_E_FLXSLV_CONSTR_TYPE

=================================================================================================

(2) Elements table
-------------------------------------------------------------------------------------------------
 Element Id                       Element Name               Data Type                Valid Values
-------------------------------------------------------------------------------------------------
 PRO_E_FLXSLV_PROP_CONSTRS        FLX-MDL Propagation        Array                    Note-1
                                  conditions
 PRO_E_FLXSLV_CONSTR              Condition                  Compound                 Note-2
 PRO_E_FLXSLV_CONSTR_REFS         Reference                  PRO_VALUE_TYPE_SELECTION Note-3
 PRO_E_FLXSLV_CONSTR_TYPE         Condition Type             PRO_VALUE_TYPE_INTEGER   note-4

=================================================================================================

(3) Notes

   Note-1  : Optional.
             It is required to control the tangency propagation.
             It can conatin zero or more number of conditions.
   
   Note-2  : Mandatory.
             It constitutues a single condition element, which
             conatins a condition type and a reference.

   Note-3  : Mandatory.
             It contains the reference, that will be used in the condition.

   Note-4  : Mandatory.
             This represents the type of the condition.
             This uses one of the enumerated ProFlxmdlPropOptFlag type.

===========================================================================*/

 typedef enum pro_flxmdl_prop_opt_flag
 {
    PRO_FLXSLV_CONSTR_TYPE_UNDEFINED      = -1 ,
    PRO_FLXSLV_CONSTR_TYPE_FIXED          =  0 ,
    PRO_FLXSLV_CONSTR_TYPE_FIX_AXIS       =  13,
    PRO_FLXSLV_CONSTR_TYPE_FIX_CNTR       =  14,
    PRO_FLXSLV_CONSTR_TYPE_FIX_NORM       =  15,
    PRO_FLXSLV_CONSTR_TYPE_CONST_R1       =  16,
    PRO_FLXSLV_CONSTR_TYPE_CONST_R2       =  17,
    PRO_FLXSLV_CONSTR_TYPE_CONST_ANG      =  18,
    PRO_FLXSLV_CONSTR_TYPE_FIX_POLE       =  19,
    PRO_FLXSLV_CONSTR_TYPE_PRPG_THRU      =  21,
    PRO_FLXSLV_CONSTR_TYPE_FIX_RNDEDG_PNT =  23,
    PRO_FLXSLV_CONSTR_FIX_WITH_TNGCY      =  25,
    PRO_FLXSLV_CONSTR_TYPE_CONST_R        =  26,
    PRO_FLXSLV_CONSTR_TYPE_KEEP_SPHERICAL =  27
 }ProFlxmdlPropOptFlag;


PRO_END_C_DECLS

#endif
