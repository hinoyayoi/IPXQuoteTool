#ifndef PRO_BUSHING_LOAD_FEAT_H
#define PRO_BUSHING_LOAD_FEAT_H



/*****************************************************************************
Feature element tree of bushing load feature
 NOTES:
 1. The default units of the spring stiffnesses and the damping coefficients on
    the three rotational axes are degree-based.
 2. If (and only if) the reference is a weld connection, any axis can be locked.
    In this case, both the spring stiffness and the damping coefficient on the
    locked axis should have a value of -1.0 (regardless of the current units).

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_BUSHLD_REF
     |
     |--PRO_E_BUSHLD_T1_STF_COEFF
     |--PRO_E_BUSHLD_T1_DMP_COEFF
     |
     |--PRO_E_BUSHLD_T2_STF_COEFF
     |--PRO_E_BUSHLD_T2_DMP_COEFF
     |
     |--PRO_E_BUSHLD_T3_STF_COEFF
     |--PRO_E_BUSHLD_T3_DMP_COEFF
     |
     |--PRO_E_BUSHLD_R1_STF_COEFF
     |--PRO_E_BUSHLD_R1_DMP_COEFF
     |
     |--PRO_E_BUSHLD_R2_STF_COEFF
     |--PRO_E_BUSHLD_R2_DMP_COEFF
     |
     |--PRO_E_BUSHLD_R3_STF_COEFF
     |--PRO_E_BUSHLD_R3_DMP_COEFF

Feature elements table

-----------------------------------------------------------------------------------
Element Id                | Element description          | Data Type
--------------------------+------------------------------+-------------------------
PRO_E_FEATURE_TYPE        | Feature type                 | PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME    | Feature name                 | PRO_VALUE_TYPE_WSTRING
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_REF          | Weld or 6DOF conn. reference | PRO_VALUE_TYPE_SELECTION
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_T1_STF_COEFF | Stiffness on 1st trans. axis | PRO_VALUE_TYPE_DOUBLE
PRO_E_BUSHLD_T1_DMP_COEFF | Damping   on 1st trans. axis | PRO_VALUE_TYPE_DOUBLE
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_T2_STF_COEFF | Stiffness on 2nd trans. axis | PRO_VALUE_TYPE_DOUBLE
PRO_E_BUSHLD_T2_DMP_COEFF | Damping   on 2nd trans. axis | PRO_VALUE_TYPE_DOUBLE
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_T3_STF_COEFF | Stiffness on 3rd trans. axis | PRO_VALUE_TYPE_DOUBLE
PRO_E_BUSHLD_T3_DMP_COEFF | Damping   on 3rd trans. axis | PRO_VALUE_TYPE_DOUBLE
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_R1_STF_COEFF | Stiffness on 1st rotat. axis | PRO_VALUE_TYPE_DOUBLE
PRO_E_BUSHLD_R1_DMP_COEFF | Damping   on 1st rotat. axis | PRO_VALUE_TYPE_DOUBLE
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_R2_STF_COEFF | Stiffness on 2nd rotat. axis | PRO_VALUE_TYPE_DOUBLE
PRO_E_BUSHLD_R2_DMP_COEFF | Damping   on 2nd rotat. axis | PRO_VALUE_TYPE_DOUBLE
--------------------------+------------------------------+-------------------------
PRO_E_BUSHLD_R3_STF_COEFF | Stiffness on 3rd rotat. axis | PRO_VALUE_TYPE_DOUBLE
PRO_E_BUSHLD_R3_DMP_COEFF | Damping   on 3rd rotat. axis | PRO_VALUE_TYPE_DOUBLE
-----------------------------------------------------------------------------------

*****************************************************************************/

#endif /* PRO_BUSHING_LOAD_FEAT_H */
