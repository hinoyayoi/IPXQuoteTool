#ifndef PRODAMPERFEAT_H
#define PRODAMPERFEAT_H

/*
   Creo Parametric TOOLKIT declarations related to damper feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS

/* ===========================================================================
   IMPORTANT UNITS NOTE!!!
   ---------------------------------------------------------------------------
   Three of the below real-number elements (PRO_E_DMP_CVAL, PRO_E_SPRING_K
   and PRO_E_SPRING_U) represent coefficients that have variable quantity type
   depending on PRO_E_SPRING_DAMPER_TYPE element. That is, translational and
   rotational springs/dampers have different q. types for these coefficients. 
   In rotational springs/dampers, the main units of these coeffs are DEGREE-
   based: they are almost identical to the principal unit in the unit system
   of the feature's owner model - except the radian sub-unit being replaced
   by degree. E. g. they are not considered principal for their respective
   q. type in most standard Creo Parametric unit systems.
   
   Example (assumes the owner has default Creo Parametric unit system (lbm/in/sec):
   ------------------------------------------------------------------------- 
                  | Translational               | Rotational               
   ---------------+-----------------------------+---------------------------
   PRO_E_DMP_CVAL | "lbm / sec"                 | "in^2 lbm / (sec deg)"   
                  | (Q_DAMPING_COEFFICIENT)     | (Q_ROT_DAMPING_COEFF)    
   ---------------+-----------------------------+---------------------------
   PRO_E_SPRING_K | "lbm / sec^2"               | "in^2 lbm / (sec^2 deg)"
                  | (Q_TRANSLATIONAL_STIFFNESS) | (Q_ROTATIONAL_STIFFNESS)
   ---------------+-----------------------------+---------------------------
   PRO_E_SPRING_U | "in"                        | "deg"
                  | (Q_LENGTH)                  | (Q_ANGLE)
   -------------------------------------------------------------------------
   ========================================================================= */

/*****************************************************************************

Feature element tree for Damper Feature

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SPRING_DAMPER_TYPE
     |
     |--PRO_E_SPRING_DAMPER_REF
     |
     |--PRO_E_DMP_CVAL


Feature elements table

------------------------------------------------------------------------
Element Id                  Element Name         Data Type
------------------------------------------------------------------------

PRO_E_FEATURE_TYPE          Feature Type         PRO_VALUE_TYPE_INT
PRO_E_DMP_FEAT_NAME         Feature Name         PRO_VALUE_TYPE_WSTRING
PRO_E_SPRING_DAMPER_TYPE    Base Ref Type        PRO_E_SPRING_DAMPER_TYPE
PRO_E_SPRING_DAMPER_REF     references           PRO_VALUE_TYPE_SELECTION
PRO_E_DMP_CVAL              Damping coeff        PRO_VALUE_TYPE_DOUBLE

*****************************************************************************/


/*****************************************************************************
Feature element tree for Spring Feature

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SPRING_DAMPER_TYPE
     |
     |--PRO_E_SPRING_DAMPER_REF
     |
     |--PRO_E_SPRING_K
     |
     |--PRO_E_SPRING_U
     |
     |--PRO_E_SPRING_DIAMETER
     |
     |--PRO_E_SPRING_USE_DIAMETER
     |
     |--PRO_E_SPRING_ATTACH_POINTS
     |
     |--PRO_E_SPRING_ATTACH_REF
     |
     |--PRO_E_SPRING_FLIP_U_ANGLE


Feature elements table

---------------------------------------------------------------------------------------------------------
Element Id                       Element Name         Data Type                Valid Values
---------------------------------------------------------------------------------------------------------

PRO_E_FEATURE_TYPE               Feature Type         PRO_VALUE_TYPE_INT      
PRO_E_DMP_FEAT_NAME              Feature Name         PRO_VALUE_TYPE_WSTRING
PRO_E_SPRING_DAMPER_TYPE         Base Ref Type        PRO_E_SPRING_DAMPER_TYPE See ProSpringDamperFeatType
PRO_E_SPRING_DAMPER_REF          references           PRO_VALUE_TYPE_SELECTION
PRO_E_SPRING_K                   Stiffness coeff      PRO_VALUE_TYPE_DOUBLE
PRO_E_SPRING_U                   Unstretched length   PRO_VALUE_TYPE_DOUBLE
PRO_E_SPRING_DIAMETER            Icon diameter value  PRO_VALUE_TYPE_DOUBLE
PRO_E_SPRING_USE_DIAMETER        Adjust Icon Diameter PRO_VALUE_TYPE_INT       See ProSpringUseDiaOpts
PRO_E_SPRING_ATTACH_POINTS       Attachment Points    PRO_VALUE_TYPE_INT       See ProSpringAttachmentPoints
PRO_E_SPRING_ATTACH_REF          Attachment Refs      PRO_VALUE_TYPE_SELECTION
PRO_E_SPRING_FLIP_U_ANGLE        Flip unstetch angle  PRO_VALUE_TYPE_BOOLEAN

*****************************************************************************/


typedef enum dmp_damper_feat_type
{
 PRO_SPRING_DAMPER_FORCE,
 PRO_SPRING_DAMPER_TORQUE
} ProSpringDamperFeatType;

typedef enum spring_use_diameter_opts
{
   PRO_SPRING_USE_DIAMETER_NO = 0,
   PRO_SPRING_USE_DIAMETER_YES = 1
} ProSpringUseDiaOpts;

typedef enum spring_attachment_points
{
   PRO_SPRING_USE_MOTION_AXIS_ZERO = 0,
   PRO_SPRING_CUSTOM_ATTACHMENT_POINTS = 1 
} ProSpringAttachmentPoints;

PRO_END_C_DECLS

#endif
