#ifndef PROCONTACT_3D_FEAT_H
#define PROCONTACT_3D_FEAT_H

/*
   Creo Parametric TOOLKIT declarations related to Contact3d feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS


/*****************************************************************************

Feature element tree for Contact3d Feature

   PRO_E_FEATURE_TREE
     |--PRO_E_FEATURE_TYPE
     |--PRO_E_STD_FEATURE_NAME
     |--PRO_E_C3D_MAT_OPTION1
     |--PRO_E_C3D_REF1_RECS
     |    |
     |    |--PRO_E_C3D_REF_REC
     |         |
     |         |--PRO_E_C3D_REF
     |         |--PRO_E_C3D_REF_FULL_GEOM
     |         |--PRO_E_C3D_REF_FLIP
     |
     |--PRO_E_C3D_MAT_NAME1
     |--PRO_E_C3D_POISSON1
     |--PRO_E_C3D_YOUNG1
     |--PRO_E_C3D_DAMPING1
     |--PRO_E_C3D_MAT_OPTION2
     |--PRO_E_C3D_REF2_RECS
     |    |
     |    |--PRO_E_C3D_REF_REC
     |         |
     |         |--PRO_E_C3D_REF
     |         |--PRO_E_C3D_REF_FULL_GEOM
     |         |--PRO_E_C3D_REF_FLIP
     |
     |--PRO_E_C3D_MAT_NAME2
     |--PRO_E_C3D_POISSON2
     |--PRO_E_C3D_YOUNG2
     |--PRO_E_C3D_DAMPING2
     |--PRO_E_C3D_VERT_RAD
     |--PRO_E_C3D_FRICTION
     |--PRO_E_C3D_STATIC_FRIC_COEF
     |--PRO_E_C3D_KINEM_FRIC_COEF

Feature elements table

------------------------------------------------------------------------
Element Id                  Element Name         Data Type
------------------------------------------------------------------------

PRO_E_FEATURE_TYPE          Feature Type         PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME      Feature Name         PRO_VALUE_TYPE_WSTRING
PRO_E_C3D_REF1_RECS         Side1 References     Array
PRO_E_C3D_REF_REC           Contact Ref Record   Compound
PRO_E_C3D_REF               Reference            PRO_VALUE_TYPE_SELECTION
PRO_E_C3D_REF_FULL_GEOM     Ref Full Geom        ProC3dFullGeomFlag
PRO_E_C3D_REF_FLIP          Ref Flip             PRO_VALUE_TYPE_BOOLEAN
PRO_E_C3D_MAT_OPTION1       Material Type        ProC3dMaterialType
PRO_E_C3D_MAT_NAME1         Material Name        PRO_VALUE_TYPE_WSTRING
PRO_E_C3D_POISSON1          Poisson coeff        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_YOUNG1            Young modulus        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_DAMPING1          Damping coeff        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_REF2_RECS         Side2 References     Array
PRO_E_C3D_MAT_OPTION2       Material Type        ProC3dMaterialType
PRO_E_C3D_MAT_NAME2         Material Name        PRO_VALUE_TYPE_WSTRING
PRO_E_C3D_POISSON2          Poisson coeff        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_YOUNG2            Young modulus        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_DAMPING2          Damping coeff        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_VERT_RAD          Vertex Radius        PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_FRICTION          Friction flag        PRO_VALUE_TYPE_BOOLEAN
PRO_E_C3D_STATIC_FRIC_COEF  Static friction coef PRO_VALUE_TYPE_DOUBLE
PRO_E_C3D_KINEM_FRIC_COEF   Kinetic frict coef   PRO_VALUE_TYPE_DOUBLE

*****************************************************************************/

typedef enum pro_c3d_full_geom_flag
{
 PRO_C3D_FULL_GEOM     = 0,
 PRO_C3D_PARTIAL_GEOM  = 1
} ProC3dFullGeomFlag;


typedef enum pro_c3d_material_type
{
 PRO_C3D_MAT_DEFAULT  = 0,
 PRO_C3D_MAT_SEL_MAT  = 1,
 PRO_C3D_MAT_USE_VALS = 2
} ProC3dMaterialType;


PRO_END_C_DECLS

#endif

