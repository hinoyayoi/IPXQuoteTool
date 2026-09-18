#ifndef PROSMTPUNCHQUILT_H
#define PROSMTPUNCHQUILT_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Flange Wall feature
*/



#include <ProToolkit.h>
#include <ProShell.h>
#include <ProSheetmetal.h>
#include <ProSmtFlangeWall.h>

PRO_BEGIN_C_DECLS

/************************************************************************

Feature PRO_FEAT_PUNCH_QUILT element tree :

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_FORM_PUNCH_QUILT
     |
     |--PRO_E_FORM_PUNCH_SIDE
     |
     |--PRO_E_FORM_PUNCH_MATERIAL_SIDE
     |
     |--PRO_E_STD_SURF_COLLECTION_APPL
     |
     |--PRO_E_SMT_FILLET_INTERSECT
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_USEFLAG
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_VALUE
     |
     |--PRO_E_SMT_FILLET_QUILT
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_USEFLAG
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_VALUE
     |
     |--PRO_E_FORM_PUNCH_HIDE_QUILT

************************************************************************

================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_FORM_PUNCH_QUILT            Referenced Quilt      PRO_VALUE_TYPE_SELECTION
PRO_E_FORM_PUNCH_SIDE             Creation Side         PRO_VALUE_TYPE_INT
PRO_E_FORM_PUNCH_MATERIAL_SIDE    Material Side         PRO_VALUE_TYPE_INT
PRO_E_STD_SURF_COLLECTION_APPL    Exclude surfaces      Surface collection
PRO_E_SMT_FILLET_INTERSECT        Intersect fillet      Compound
PRO_E_SMT_FILLET_QUILT            Quilt fillet          Compound
PRO_E_SMT_FILLET_RADIUS_USEFLAG   Use Radius            PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLET_RADIUS_SIDE      Radius Side           PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLET_RADIUS_VALUE     Radius Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_FORM_PUNCH_HIDE_QUILT       Hide Quilt            PRO_VALUE_TYPE_INT

================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_PUNCH_QUILT
PRO_E_FORM_PUNCH_SIDE             ProSmtSurfType (PRO_SMT_SURF_FACE,
                                                  PRO_SMT_SURF_OFFSET)
PRO_E_FORM_PUNCH_MATERIAL_SIDE    ProSmdPunchMatSide
PRO_E_FORM_PUNCH_HIDE_QUILT       ProSmdPunchHideQuilt
PRO_E_SMT_FILLET_RADIUS_USEFLAG   PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_FILLET_RADIUS_SIDE      ProSmdRadType(PRO_BEND_RAD_INSIDE,
                                                 PRO_BEND_RAD_OUTSIDE)

================================================================================

************************************************************************/


typedef enum pro_smt_punch_hide_quilt
{
   PRO_SMT_PUNCH_HIDE_ORIGINAL       = 0,
   PRO_SMT_PUNCH_KEEP_ORIGINAL       = 1

} ProSmdPunchHideQuilt;

typedef enum pro_smt_punch_mat_side
{
   PRO_SMT_PUNCH_MAT_OUTSIDE         = 0,
   PRO_SMT_PUNCH_MAT_INSIDE          = 1

} ProSmdPunchMatSide;


PRO_END_C_DECLS

#endif
