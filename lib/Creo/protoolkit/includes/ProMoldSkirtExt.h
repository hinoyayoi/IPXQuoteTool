#ifndef PROMOLDSKIRTEXT_H
#define PROMOLDSKIRTEXT_H

/*
   Creo Parametric TOOLKIT declarations related to skirt extension 
   surface feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_FEATURE_FORM
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SKIRT_REF_MODEL
      |
      |-- PRO_E_SKIRT_BOUNDARY_REF
      |
      |-- PRO_E_SKIRT_PULL_DIR_COMPOUND
      |      |
      |      |-- PRO_E_DIRECTION_COMPOUND
      |
      |-- PRO_E_SKIRT_EXT_SET_ARR
      |      |
      |      |-- PRO_E_SKIRT_EXT_SET_COMPOUND
      |             |
      |             |-- PRO_E_SKIRT_EXT_SET_REF_IDX
      |             |
      |             |-- PRO_E_SKIRT_EXT_SET_TYPE
      |             |
      |             |-- PRO_E_SKIRT_EXT_SET_CURVE_COMP
      |             |      |
      |             |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |             |
      |             |-- PRO_E_SKIRT_EXT_SET_DIR_COMPOUND
      |             |      |
      |             |      |-- PRO_E_DIRECTION_COMPOUND
      |             |
      |             |-- PRO_E_SKIRT_EXT_SET_NEXT_DIR_OPT
      |
      |-- PRO_E_SKIRT_SHUTOFF_EXT_COMPOUND
      |      |
      |      |-- PRO_E_SKIRT_SHUTOFF_EXT_TYPE
      |      |
      |      |-- PRO_E_SKIRT_SHUTOFF_EXT_DIST
      |      |
      |      |-- PRO_E_SKIRT_SHUTOFF_CURVE_COMP
      |      |      |
      |      |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |      |
      |      |-- PRO_E_SKIRT_DRAFT_ANGLE
      |      |
      |      |-- PRO_E_SKIRT_SHUTOFF_PLANE_REF
      |
      |-- PRO_E_SKIRT_CREATE_TRANS_OPT

==============================================================================

(2) Elements table

-------------------------------------------------------------------------------------------------------
Element Id                       Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Feature Type           PRO_VALUE_TYPE_INT        PRO_FEAT_DATUM_SURF
PRO_E_FEATURE_FORM               Feature Form           PRO_VALUE_TYPE_INT        PRO_SKIRT_EXT
PRO_E_STD_FEATURE_NAME           Feature Name           PRO_VALUE_TYPE_WSTRING    Wide character string
PRO_E_SKIRT_REF_MODEL            Reference Model        PRO_VALUE_TYPE_SELECTION  Note-1
PRO_E_SKIRT_BOUNDARY_REF         Boundary reference     PRO_VALUE_TYPE_SELECTION  Note-2
PRO_E_SKIRT_PULL_DIR_COMPOUND    Pull Direction         Compound                  Note-3
PRO_E_DIRECTION_COMPOUND         Direction Element      Compound                  Note-4
PRO_E_SKIRT_EXT_SET_ARR          Extension Set Array    Array                     Note-5
PRO_E_SKIRT_EXT_SET_COMPOUND     Extension Set Compound Compound                  Note-6
PRO_E_SKIRT_EXT_SET_REF_IDX      Ext Reference Index    PRO_VALUE_TYPE_INT        Note-7
PRO_E_SKIRT_EXT_SET_TYPE         Extension Type         PRO_VALUE_TYPE_INT        Note-8
PRO_E_SKIRT_EXT_SET_CURVE_COMP   Extension Set Curves   Compound                  Note-9
PRO_E_SKIRT_EXT_SET_DIR_COMPOUND Direction Compound     Compound                  Note-10
PRO_E_SKIRT_SHUTOFF_EXT_COMPOUND Shutoff Extenstion     Compound                  Note-11
PRO_E_SKIRT_SHUTOFF_EXT_TYPE     Extension Type         PRO_VALUE_TYPE_INT        Note-12
PRO_E_SKIRT_SHUTOFF_EXT_DIST     Shutoff Distance       PRO_VALUE_TYPE_DOUBLE     Note-13
PRO_E_SKIRT_SHUTOFF_CURVE_COMP   Shutoff Curve          Compound                  Note-14
PRO_E_SKIRT_DRAFT_ANGLE          Draft Angle            PRO_VALUE_TYPE_DOUBLE     Note-15
PRO_E_SKIRT_SHUTOFF_PLANE_REF    Shutoff Plane          PRO_VALUE_TYPE_SELECTION  Note-16
PRO_E_SKIRT_EXT_SET_NEXT_DIR_OPT Next ext dir           PRO_VALUE_TYPE_INT        Note-17   
PRO_E_SKIRT_CREATE_TRANS_OPT     Create Transtions      PRO_VALUE_TYPE_INT        Note-18
======================================================================================================= 

(3) Notes

Note-1  : Mandatory.  
          Reference model used for creating extension surfaces. Valid reference is a   
          single PRO_PART.   

Note-2  : Mandatory.     
          Boundary reference used for trimming the extension surfaces. Valid reference 
          is either a single PRO_PART or a single PRO_QUILT.
 
Note-3  : Optional if default pull direction exist.
          Reference for view direction. If not specified, default pull direction is 
          used provided the pull direction exist. Valid reference is PRO_E_DIRECTION_COMPOUND.

Note-4  : Direction Reference. For more details refer ProDirection.h 

Note-5  : Mandatory.
         An array element having PRO_E_SKIRT_EXT_SET_COMPOUND sets.

Note-6  : Mandatory.
          Compound element. One element per set present in PRO_E_SKIRT_EXT_SET_ARR.

Note-7  : Mandatory. 
          A unique value for each compound set PRO_E_SKIRT_EXT_SET_COMPOUND.

Note-8  : Mandatory.
          Type of an extension - defines extension direction.
          Possible values :
              PRO_SKIRT_EXT_TYPE_NORMAL           - normal to the pull direction and 
                                                    end directions normal to the curve.
              PRO_SKIRT_EXT_TYPE_PARALLEL         - parallel to the pull direction.
              PRO_SKIRT_EXT_TYPE_TANGENT          - tangent to the model.
              PRO_SKIRT_EXT_TYPE_USER             - defined by the specified direction.
              PRO_SKIRT_EXT_TYPE_NORMAL_TO_BNDRY  - normal to the pull direction and 
                                                    end directions normal to the boundary.

Note-9  : Mandatory.
          Compound element for extension curves collection.

Note-10 : Mandatory if ProSkirtExtType is PRO_SKIRT_EXT_TYPE_USER.
          User defined direction reference. For more details refer ProDirection.h

Note-11 : Mandatory.
          Compound element for shutoff options.

Note-12 : Mandatory. 
          Type of a shutoff. Valid values are ProSkirtShutoffExtType.

Note-13 : Mandatory if ProSkirtShutoffExtType is PRO_SKIRT_EXT_SHUTOFF_BY_DIST.
          Shutoff extention distance.

Note-14 : Mandatory if ProSkirtShutoffExtType is PRO_SKIRT_EXT_SHUTOFF_BY_BOUND.
          Shutoff by the selected boundary.

Note-15 : Optional. 
          Draft angle for shutoff. Default value is zero degrees.

Note-16 : Mandatory if ProSkirtShutoffExtType is PRO_SKIRT_EXT_SHUTOFF_BY_BOUND.
          A plane to create shutoff.

Note-17 : Optional. Valid values are ProSkirtExtNextDirOpt.
          Used in tangent and parallel extension cases.
          In tangent extension, this option used to switch between two tangent 
          extension solutions if available.
          In parallel extension, this option is used to flip the extension direction.

Note-18 : Optional.
          Required if transitions need to be created across sets.          

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMOLDSKIRTEXT_H */
