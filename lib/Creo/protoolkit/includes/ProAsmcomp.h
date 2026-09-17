#ifndef PROASMCOMP_H
#define PROASMCOMP_H

/* Creo Parametric TOOLKIT declarations for ProAsmcomp objects */

#include <ProObjects.h>
#include <ProMdl.h>




PRO_BEGIN_C_DECLS

/*****************************************************************************\

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_COMPONENT_MODEL
     |
     |--PRO_E_COMPONENT_MISC_ATTR
     |
     |--PRO_E_COMPONENT_INIT_POS
     |
     |--PRO_E_COMP_PLACE_INTERFACE
     |    |--PRO_E_COMP_PLACE_INTERFACE_TYPE
     |    |--PRO_E_COMP_PLACE_INTERFACE_COMP
     |    |--PRO_E_COMP_PLACE_INTERFACE_ASSEMS
     |         |--PRO_E_COMP_PLACE_INTERFACE_ASSEM
     !             |--PRO_E_COMP_PLACE_INTERFACE_ASSEM_REF
     |
     |--PRO_E_COMPONENT_SETS
     |    |--PRO_E_COMPONENT_SET
     |         |--PRO_E_COMPONENT_SET_ID
     |         |--PRO_E_COMPONENT_SET_TYPE
     |         |--PRO_E_COMPONENT_SET_NAME
     |         |--PRO_E_COMPONENT_SET_MISC_ATTR
     |         |--PRO_E_COMPONENT_SET_FLIP
     |         |--PRO_E_COMPONENT_JAS_SETS
     |              |--PRO_E_COMPONENT_JAS_SET
     |                   |--PRO_E_COMPONENT_JAS_ZERO_TYPE
     |                   |--PRO_E_COMPONENT_JAS_REFS
     |                   |    |--PRO_E_COMPONENT_JAS_ORANGE_REF
     |                   |    |--PRO_E_COMPONENT_JAS_GREEN_REF
     |                   |    |--PRO_E_COMPONENT_JAS_0_OFFSET_VAL
     |                   |--PRO_E_COMPONENT_JAS_REGEN_VALUE_GROUP
     |                   |    |--PRO_E_COMPONENT_JAS_REGEN_VALUE_FLAG
     |                   |    |--PRO_E_COMPONENT_JAS_REGEN_VALUE
     |                   |--PRO_E_COMPONENT_JAS_MIN_LIMIT
     |                   |    |--PRO_E_COMPONENT_JAS_MIN_LIMIT_FLAG
     |                   |    |--PRO_E_COMPONENT_JAS_MIN_LIMIT_VAL
     |                   |    |--PRO_E_COMPONENT_JAS_MIN_LIMIT_REF
     |                   |--PRO_E_COMPONENT_JAS_MAX_LIMIT
     |                   |    |--PRO_E_COMPONENT_JAS_MAX_LIMIT_FLAG
     |                   |    |--PRO_E_COMPONENT_JAS_MAX_LIMIT_VAL
     |                   |    |--PRO_E_COMPONENT_JAS_MAX_LIMIT_REF
     |                   |--PRO_E_COMPONENT_JAS_RESTITUTION
     |                   |    |--PRO_E_COMPONENT_JAS_RESTITUTION_FLAG
     |                   |    |--PRO_E_COMPONENT_JAS_RESTITUTION_COEF
     |                   |--PRO_E_COMPONENT_JAS_FRICTION
     |                   |    |--PRO_E_COMPONENT_JAS_FRICTION_FLAG
     |                   |    |--PRO_E_COMPONENT_JAS_STATIC_FRIC_COEF
     |                   |    |--PRO_E_COMPONENT_JAS_KINEM_FRIC_COEF
     |                   |    |--PRO_E_COMPONENT_JAS_RADIUS_VALUE
     |                   |--PRO_E_COMPONENT_JAS_CONE_FLIP
     |--PRO_E_COMPONENT_CONSTRAINTS       Array of PRO_E_COMPONENT_CONSTRAINT
     |    |--PRO_E_COMPONENT_CONSTRAINT
     |         |--PRO_E_COMPONENT_CONSTR_TYPE
     |         |--PRO_E_COMPONENT_COMP_CONSTR_REF
     |         |--PRO_E_COMPONENT_ASSEM_CONSTR_REF
     |         |--PRO_E_COMPONENT_CONSTR_REF_OFFSET (Mate/align offset)
     |         |--PRO_E_COMPONENT_USER_DATA
     |         |--PRO_E_COMPONENT_CONSTR_ATTR
     |         |--PRO_E_COMPONENT_COMP_ORIENT
     |         |--PRO_E_COMPONENT_ASSM_ORIENT
     |         |--PRO_E_COMPONENT_CONSTR_SET_ID
     |         |--PRO_E_COMPONENT_SLOT_EXTRA_CRV_REF
     |--PRO_E_COMPONENT_MOVEMENTS
          |--PRO_E_COMPONENT_MOVEMENT
               |--PRO_E_COMPONENT_MOVEMENT_TYPE
               |--PRO_E_COMPONENT_MOVEMENT_REF
               |--PRO_E_COMPONENT_MOVEMENT_VALUE



3. Feature elements table

-------------------------------------------------------------------------------------------------
Element Id                            Element Name   Data Type                Valid Values
-------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                    Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_COMPONENT
PRO_E_COMPONENT_MODEL                 Component      PRO_VALUE_TYPE_POINTER   ProSolid
PRO_E_COMP_PLACE_INTERFACE            Interface      Compound
PRO_E_COMP_PLACE_INTERFACE_TYPE       Type           PRO_VALUE_TYPE_INT       See IntfcPlaceType
PRO_E_COMP_PLACE_INTERFACE_COMP       Comp Intfc     PRO_VALUE_TYPE_SELECTION
PRO_E_COMP_PLACE_INTERFACE_ASSEMS     Asm  Intfcs    Array
PRO_E_COMP_PLACE_INTERFACE_ASSEM      Asm Intfc      compound
PRO_E_COMP_PLACE_INTERFACE_ASSEM_REF  Asm Intfc      PRO_VALUE_TYPE_SELECTION
PRO_E_COMPONENT_SETS                  Sets           Array
PRO_E_COMPONENT_SET                   Set            Compound
PRO_E_COMPONENT_SET_ID                Set Id         PRO_VALUE_TYPE_INT       Any
PRO_E_COMPONENT_SET_TYPE              Type           PRO_VALUE_TYPE_INT       See ProAsmCompSetType
PRO_E_COMPONENT_SET_NAME              Name           PRO_VALUE_TYPE_WSTRING
PRO_E_COMPONENT_SET_MISC_ATTR         Set Attr       PRO_VALUE_TYPE_INT       See PmConnectionAttr
PRO_E_COMPONENT_SET_FLIP              Set Flip       PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE
PRO_E_COMPONENT_JAS_SETS              JAS Sets       Array

PRO_E_COMPONENT_JAS_SET               Joint Axis Set Compound
PRO_E_COMPONENT_JAS_ZERO_TYPE         Zero Type      PRO_VALUE_TYPE_INT       Values of ProAxiszerotype
PRO_E_COMPONENT_JAS_REFS              JAS Refs       Compound
PRO_E_COMPONENT_JAS_ORANGE_REF        JAS Orange Ref PRO_VALUE_TYPE_SELECTION Component side selection
PRO_E_COMPONENT_JAS_GREEN_REF         JAS Green Ref  PRO_VALUE_TYPE_SELECTION Assembly side selection
PRO_E_COMPONENT_JAS_0_OFFSET_VAL      JAS 0 offset   PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_COMPONENT_JAS_REGEN_VALUE_GROUP JAS Regen      Compound
PRO_E_COMPONENT_JAS_REGEN_VALUE_FLAG  JAS Reg Flag   PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE
PRO_E_COMPONENT_JAS_REGEN_VALUE       JAS Regen Val  PRO_VALUE_TYPE_DOUBLE    Between Min Limit Val and Max Limit Val
PRO_E_COMPONENT_JAS_LIMITS            JAS Limits     Compound
PRO_E_COMPONENT_JAS_MIN_LIMIT         JAS Min Limit  Compound
PRO_E_COMPONENT_JAS_MIN_LIMIT_FLAG    Min Lim Flag   PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE
PRO_E_COMPONENT_JAS_MIN_LIMIT_VAL     Min Limit Val  PRO_VALUE_TYPE_DOUBLE    (-360,360] or Any (Note 2)
PRO_E_COMPONENT_JAS_MAX_LIMIT         JAS Max Limit  Compound
PRO_E_COMPONENT_JAS_MAX_LIMIT_FLAG    Max Lim Flag   PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE
PRO_E_COMPONENT_JAS_MAX_LIMIT_VAL     Max Limit Val  PRO_VALUE_TYPE_DOUBLE    (-360,360] or Any (Note 2)
PRO_E_COMPONENT_JAS_RESTITUTION       Restitution    Compound
PRO_E_COMPONENT_JAS_RESTITUTION_FLAG  Rest Flag      PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE
PRO_E_COMPONENT_JAS_RESTITUTION_COEF  Rest Coef      PRO_VALUE_TYPE_DOUBLE    [0., 1.]
PRO_E_COMPONENT_JAS_FRICTION          JAS Friction   Compound
PRO_E_COMPONENT_JAS_FRICTION_FLAG JAS Fric Flag      PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE
PRO_E_COMPONENT_JAS_STATIC_FRIC_COEF  JAS MuS        PRO_VALUE_TYPE_DOUBLE    [0., 1.]
PRO_E_COMPONENT_JAS_KINEM_FRIC_COEF   JAS MuK        PRO_VALUE_TYPE_DOUBLE    [0., 1.]
PRO_E_COMPONENT_JAS_RADIUS_VALUE      Radius Value   PRO_VALUE_TYPE_DOUBLE    Any non-negative value.
PRO_E_COMPONENT_JAS_CONE_FLIP         Cone flip      PRO_VALUE_TYPE_BOOLEAN   PRO_B_TRUE/PRO_B_FALSE

PRO_E_COMPONENT_CONSTRAINTS           Constraints    Array
PRO_E_COMPONENT_CONSTRAINT            Constraint     Compound
PRO_E_COMPONENT_CONSTR_TYPE           Type           PRO_VALUE_TYPE_INT       See ProAsmcompConstrType
PRO_E_COMPONENT_COMP_CONSTR_REF       Comp Ref       PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_COMPONENT_ASSEM_CONSTR_REF      Assem Ref      PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_COMPONENT_CONSTR_REF_OFFSET     Offset         PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_COMPONENT_CONSTR_ATTR           Constr Attr    PRO_VALUE_TYPE_INT       See Note 2
PRO_E_COMPONENT_ASSM_ORIENT           Assem Orient   PRO_VALUE_TYPE_INT       See Note 3
PRO_E_COMPONENT_COMP_ORIENT           Comp Orient    PRO_VALUE_TYPE_INT       See Note 3
PRO_E_COMPONENT_CONSTR_SET_ID      Constr Set Index  PRO_VALUE_TYPE_INT       Index to set constraint belongs to
PRO_E_COMPONENT_MISC_ATTR             Comp Attr      PRO_VALUE_TYPE_INT       See Note 5 
PRO_E_COMPONENT_USER_DATA             usr dat        PRO_VALUE_TYPE_WSTRING
PRO_E_COMPONENT_INIT_POS              Init Pos       PRO_VALUE_TYPE_TRANSFORM
PRO_E_COMPONENT_SLOT_EXTRA_CRV_REF    Crv Ref        PRO_VALUE_TYPE_SELECTION Edge, Curve multi value.

PRO_E_COMPONENT_MOVEMENTS             Movements      Array
PRO_E_COMPONENT_MOVEMENT              Movement       Compound
PRO_E_COMPONENT_MOVEMENT_TYPE         Type           PRO_VALUE_TYPE_INT       see ProAsmcompMoveType
PRO_E_COMPONENT_MOVEMENT_REF          Move Ref       PRO_VALUE_TYPE_SELECTION Csys
PRO_E_COMPONENT_MOVEMENT_VALUE        Value          PRO_VALUE_TYPE_DOUBLE    Any
--------------------------------------------------------------------------------------------



   Note 1.   Constraint reference types:

   Constraint Type     Valid Reference Types
   ---------------------------------------------------------------------
   PRO_ASM_MATE          PRO_SURFACE (Plane, Cone, Torus, Cylinder)
   PRO_ASM_MATE_OFF      PRO_SURFACE (Plane)
   PRO_ASM_ALIGN         PRO_POINT, PRO_AXIS, PRO_SURFACE (Plane)
   PRO_ASM_ALIGN_OFF     PRO_POINT, PRO_AXIS, PRO_SURFACE (Plane)
   PRO_ASM_INSERT        PRO_SURFACE (Cylinder, Cone, Torus)
   PRO_ASM_ORIENT        PRO_SURFACE (Plane), PRO_CSYS
   PRO_ASM_CSYS          PRO_CSYS
   PRO_ASM_TANGENT       PRO_SURFACE (Cylinder)
   PRO_ASM_PNT_ON_LINE   PRO_POINT, PRO_EDGE, PRO_AXIS
   PRO_ASM_PNT_ON_SRF    PRO_POINT, PRO_SURFACE (Plane)
   PRO_ASM_EDGE_ON_SRF   PRO_EDGE, PRO_SURFACE (Plane)
   PRO_ASM_DEF_PLACEMENT NONE
   PRO_ASM_SUBSTITUTE    (READ ONLY -> assembly ref is PRO_PART).
   PRO_ASM_ALIGN_ANG_OFF PRO_SURFACE (plane)
   PRO_ASM_MATE_ANG_OFF  PRO_SURFACE (plane)
   PRO_ASM_FIX           PRO_CSYS (Note that the reference status will be 
                                 PRO_REF_MISSING if the constraint references 
                                 the default assembly coordinate system 
                                 instead of a user-selected one).
   PRO_ASM_AUTO          (Note: Internal use, should not be set)
   PRO_ASM_CSYS_PNT      PRO_CSYS
   PRO_ASM_LINE_NORMAL   PRO_AXIS, PRO_EDGE
   PRO_ASM_LINE_COPLANAR PRO_AXIS, PRO_EDGE
   PRO_ASM_LINE_PARL     PRO_AXIS, PRO_EDGE
   PRO_ASM_LINE_DIST     PRO_AXIS, PRO_EDGE
   PRO_ASM_PNT_DIST      PRO_POINT
   PRO_ASM_INSERT_NORM   PRO_SURFACE (Cylinder, Cone, Torus)
   PRO_ASM_INSERT_PARL   PRO_SURFACE (Cylinder, Cone, Torus)
   PRO_ASM_PNT_ON_LINE_DIST     PRO_POINT, PRO_EDGE, PRO_AXIS
   PRO_ASM_PNT_ON_SRF_DIST      PRO_POINT, PRO_SURFACE (Plane)
   PRO_ASM_EDGE_ON_SRF_DIST     PRO_POINT, PRO_SURFACE (Plane)
   PRO_ASM_EDGE_ON_SRF_ANG      PRO_EDGE, PRO_SURFACE (Plane)
   PRO_ASM_EDGE_ON_SRF_NORMAL   PRO_EDGE, PRO_SURFACE (Plane)
   PRO_ASM_EDGE_ON_SRF_PARL     PRO_EDGE, PRO_SURFACE (Plane)
   PRO_ASM_ALIGN_NODEP_ANGLE    PRO_SURFACE (plane)
   PRO_ASM_MATE_NODEP_ANGLE     PRO_SURFACE (plane)
   PRO_ASM_LINE_ANGLE    PRO_AXIS, PRO_EDGE (Note this is the angle between two
                                             edge/axis that are also coplanar)
   PRO_ASM_SRF_NORMAL    PRO_SURFACE (plane)

   Note 2.   JAS Limits valid values:
   
   (-360, 360] is valid for rotational joint types. 
   Linear joint types may accept any value.

   Note 3.

   For connection constraint sets it means ProConnectionFlipState.


\*****************************************************************************/

/* 1. PRO_E_COMPONENT_CONSTR_TYPE */

typedef enum pro_asm_constraint_type
{
   PRO_ASM_MATE,
   PRO_ASM_MATE_OFF,
   PRO_ASM_ALIGN,
   PRO_ASM_ALIGN_OFF,
   PRO_ASM_INSERT,
   PRO_ASM_ORIENT,
   PRO_ASM_CSYS,
   PRO_ASM_TANGENT,
   PRO_ASM_PNT_ON_SRF,
   PRO_ASM_EDGE_ON_SRF,
   PRO_ASM_DEF_PLACEMENT,
   PRO_ASM_SUBSTITUTE,
   PRO_ASM_PNT_ON_LINE,
   PRO_ASM_FIX,
   PRO_ASM_AUTO,
   PRO_ASM_ALIGN_ANG_OFF,
   PRO_ASM_MATE_ANG_OFF,
   PRO_ASM_CSYS_PNT,
   PRO_ASM_LINE_NORMAL,
   PRO_ASM_LINE_COPLANAR,
   PRO_ASM_LINE_PARL,
   PRO_ASM_LINE_DIST,
   PRO_ASM_PNT_DIST,
   PRO_ASM_INSERT_NORM,
   PRO_ASM_INSERT_PARL,
   PRO_ASM_PNT_ON_LINE_DIST,
   PRO_ASM_PNT_ON_SRF_DIST,
   PRO_ASM_EDGE_ON_SRF_DIST,
   PRO_ASM_EDGE_ON_SRF_ANG,
   PRO_ASM_EDGE_ON_SRF_NORMAL,
   PRO_ASM_ALIGN_NODEP_ANGLE,
   PRO_ASM_MATE_NODEP_ANGLE,
   PRO_ASM_LINE_ANGLE,
   PRO_ASM_EDGE_ON_SRF_PARL,
   PRO_ASM_SRF_NORMAL

} Pro_asm_constraint_type, ProAsmcompConstrType;

/*
This is a secondary flip used for connections only and working together with 
constraint type (ProAsmcompConstrType). It should (mainly) be used 
when it is impossible to flip the ProAsmcompConstrType (mate vs align etc.).
*/
typedef enum {
    PRO_ASM_FLIP_UNDEFINED = 0,
    PRO_ASM_FLIPPED,
    PRO_ASM_NOT_FLIPPED
} ProConnectionFlipState;

typedef enum {
    PRO_ASM_SET_TYPE_FIXED = 0,
    PRO_ASM_SET_TYPE_PIN,
    PRO_ASM_SET_TYPE_SLIDER,
    PRO_ASM_SET_TYPE_CYLINDRICAL,
    PRO_ASM_SET_TYPE_PLANAR,
    PRO_ASM_SET_TYPE_BALL,
    PRO_ASM_SET_TYPE_WELD,
    PRO_ASM_SET_TYPE_BEARING,
    PRO_ASM_SET_TYPE_GENERAL,
    PRO_ASM_SET_TYPE_6DOF,
    PRO_ASM_SET_TYPE_SLOT,
    PRO_ASM_SET_TYPE_GIMBAL,
    PRO_ASM_SET_TYPE_DMA_DEFINED,         /* Reserved for internal use only */
    PRO_ASM_SET_TYPE_TRANSFORM,           /* Reserved for internal use only */
    PRO_ASM_SET_USER_DEFINED_TYPE = 5200
}ProAsmcompSetType;

typedef enum pro_comp_set_attr_type
{
   PRO_ASM_ENABLE_COMP_SET,
   PRO_ASM_DISABLE_COMP_SET
} PmConnectionAttr;

typedef enum pro_intfc_placement_type
{
   PRO_ASM_INTFC_NONE    = 0,
   PRO_ASM_INTFC_TO_GEOM = 1,
   PRO_ASM_INTFC_TO_INTFC
} IntfcPlaceType;

/* Symbol maintained for compatibility - use PRO_ASM_FIX instead. */
#define PRO_ASM_DEF_CSYS  PRO_ASM_FIX

typedef enum pro_asm_comp_movement_type
{
   PRO_ASM_TRANSLATE_X,
   PRO_ASM_TRANSLATE_Y,
   PRO_ASM_TRANSLATE_Z,
   PRO_ASM_ROTATE_X,
   PRO_ASM_ROTATE_Y,
   PRO_ASM_ROTATE_Z,
   PRO_ASM_TWIST_FIT
} ProAsmcompMoveType;

#define  PRO_ASM_TYPE_NOT_DEFINED  -777


/*===========================================================================*/

/* Note 2.   Constraint Attributes  */

#define PRO_ASM_CONSTR_ATTR_NONE      (0)     /* No constraint attributes */
#define PRO_ASM_CONSTR_ATTR_IGNORE    (1<<0)  /* Constraint is ignored during regeneration.  For PTC internal use only.  */
#define PRO_ASM_CONSTR_ATTR_FORCE     (1<<1) /* Constraint has to be forced for line, pnt align. */
#define PRO_ASM_CONSTR_ATTR_INTFC_DEPENDENT    (1<<2) /* When set in a component interface, the constraint cannot be changed by application of settings making it coincident, offset, or reoriented. */
#define PRO_ASM_CONSTR_ATTR_INACTIVE (1<<5) /* constraint has been set to be inactive */

/*===========================================================================*/

typedef                struct pro_model_item  ProAsmcomp;

typedef enum  ProAsmcompTypes  {
  PRO_ASM_COMP_TYPE_NONE        = 0,     /* "usual" (non-mfg/mold/cast) case */
  PRO_ASM_COMP_TYPE_WORKPIECE   = 1,
  PRO_ASM_COMP_TYPE_REF_MODEL   = 2,
  PRO_ASM_COMP_TYPE_FIXTURE     = 3,
  PRO_ASM_COMP_TYPE_MOLD_BASE   = 4,
  PRO_ASM_COMP_TYPE_MOLD_COMP   = 5,
  PRO_ASM_COMP_TYPE_MOLD_ASSEM  = 6,
  PRO_ASM_COMP_TYPE_GEN_ASSEM   = 7,
  PRO_ASM_COMP_TYPE_CAST_ASSEM  = 8,
  PRO_ASM_COMP_TYPE_DIE_BLOCK   = 9,
  PRO_ASM_COMP_TYPE_DIE_COMP    = 10,
  PRO_ASM_COMP_TYPE_SAND_CORE   = 11,
  PRO_ASM_COMP_TYPE_CAST_RESULT = 12,
  PRO_ASM_COMP_TYPE_FROM_MOTION = 13,           /* Replaced, see note 5 */
  PRO_ASM_COMP_TYPE_NO_DEF_ASSUM = 14           /* Replaced, see note 5 */
}  ProAsmcompType;

/*===========================================================================*/
/*   Note 5:   Component misc attributes.  
               PRO_ASM_COMP_ATTR_FROM_MOTION will replace PRO_ASM_COMP_TYPE_FROM_MOTION
               PRO_ASM_COMP_ATTR_NO_DEFAULT_ASSUMP will replace PRO_ASM_COMP_TYPE_NO_DEF_ASSUM */

#define PRO_ASM_COMP_ATTR_FROM_MOTION           (1<<5)
#define PRO_ASM_COMP_ATTR_NO_DEFAULT_ASSUMP     (1<<6)
#define PRO_ASM_COMP_ATTR_USE_CRITERIA_MISMATCH (1<<7)
#define PRO_ASM_COMP_ATTR_BACKUP_REFERENCES     (1<<8)
#define PRO_ASM_COMP_ATTR_SUSPEND_UPDATE        (1<<9)
/*===========================================================================*/




/*===========================================================================*/

typedef enum pro_asm_comp_motion_type {
        PRO_M_UNDEF,
        PRO_M_TRANSLATE,
        PRO_M_ROTATE,
        PRO_M_ADJUST,
        PRO_M_ORIENTMODE
} ProMotionType;

typedef enum pro_asm_comp_motion_ref_type {
        PRO_M_VIEW_PLANE,
        PRO_M_SEL_PLANE,
        PRO_M_ENTITY_EDGE,
        PRO_M_PLANE_NORMAL,
        PRO_M_2_POINTS,
        PRO_M_CSYS_X,
        PRO_M_CSYS_Y,
        PRO_M_CSYS_Z
} ProMotionRefType;

typedef enum pro_axis_zero_type 
{
  PRO_AXIS_ZERO_UNDEF_TYPE =  -1,
  PRO_AXIS_ZERO_TRANSLATE1 , /* 0 */
  PRO_AXIS_ZERO_TRANSLATE2 , /* 1 */
  PRO_AXIS_ZERO_TRANSLATE3 , /* 2 */
  PRO_AXIS_ZERO_ROTATION1 ,  /* 3 */
  PRO_AXIS_ZERO_ROTATION2 ,  /* 4 */
  PRO_AXIS_ZERO_ROTATION3 ,  /* 5 */
  PRO_AXIS_ZERO_SLOT ,       /* 6 */
  PRO_AXIS_ZERO_CONE,        /* 7 */
   /*______________________________________________________________________*/
  /* Add new motion limit zero types above the line ^                     */
  PRO_AXIS_ZERO_TYPE_COUNT
} ProAxiszerotype;

/*===========================================================================*/

extern ProError ProAsmcompVisibilityGet  (ProAsmcomppath *p_comp_path,
                                          ProSimprep     *p_simp_rep,
                                          ProBoolean     *p_visibility);
/*
   Purpose:  Returns the visibility of the specified component.

   Input Arguments:
      p_comp_path       - The path to the member.
      p_simp_rep        - The handle to the simplified representation. If 
                          this is NULL, the function uses the current, active 
                          representation of the current assembly.

   Output Arguments:
      p_visibility      - This is PRO_B_TRUE if the component is visible in
                          the simplified representation; otherwise, this is
                          PRO_B_FALSE.
                          
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT - The assembly is in the master representation.
*/

/*===========================================================================*/

extern ProError  ProAsmcompTypeGet  (ProAsmcomp*                 comp,
                                      PRO_CONST_ARG ProAssembly   top_assem,
                                     ProAsmcompType             *r_type );
/*
   Purpose: Retrieves the type of the specified component.

   Input Arguments:
      comp           - The handle to the component feature
      top_assem      - The handle to the top-level assembly

   Output Arguments:
      r_type         - The component type

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/

/*===========================================================================*/

extern ProError  ProAsmcompTypeSet (ProAsmcomp*                 comp,
                                     PRO_CONST_ARG ProAssembly   top_assem,
                                    ProAsmcompType              type );
/*
   Purpose: Sets the type of the specified component.

   Input Arguments:
      comp           - The handle to the component feature
      top_assem      - The handle to the top-level assembly
      type           - The component type

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the component type.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError ProAsmcompMdlGet (ProAsmcomp *p_feat_handle,
                                  ProMdl     *p_mdl_handle);
/*
   Purpose: Retrieves the component model, given a component feature.

   Input Arguments:
      p_feat_handle     - The handle to the component feature

   Output Arguments:
     p_mdl_handle       - The model handle to be initialized

   Return Values:
      PRO_TK_NO_ERROR     - The argument corresponds to a valid component
                            feature with a valid component model.
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid component 
                            feature.
      PRO_TK_E_NOT_FOUND  - Assembly component model is not a solid or 
                            is not in memory.
*/

extern ProError ProAsmcompIsBulkitem (ProAsmcomp *p_comp_handle,
                                      ProBoolean *p_is_bulk_item);
/*
   Purpose: Determines whether the specified component is a bulk item.

   Input Arguments:
     p_comp_handle    -  The component to be checked.

   Output Arguments:
     p_is_bulk_item   -  This is PRO_B_TRUE if the component 
                         is a bulk item; otherwise, this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProAsmcompConstrRedefUI (ProAsmcomp *p_feat_handle);
/*

   Purpose: Invokes the user interface to redefine component constraints.

   Input Arguments:
       p_feat_handle  -     The handle to the component to redefine. 
                            Note that this cannot be NULL.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The argument corresponds to a valid component
                            feature redefinition.
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid component
                            feature.
      PRO_TK_USER_ABORT   - The user aborted component redefinition.
*/

/*------------------------ CONSTRAINT RELATED API's ----------------------*/


typedef struct pro_asm_constraint_full* ProAsmcompconstraint;

typedef enum pro_datum_side
{
   PRO_DATUM_SIDE_RED = -1,
   PRO_DATUM_SIDE_NONE =  0,
   PRO_DATUM_SIDE_YELLOW = 1
} ProDatumside;

extern ProError ProAsmcompConstraintsGet (ProAsmcomp *component,
                                          ProAsmcompconstraint **pp_constraints );
/*
  Purpose:     retrieves an array of constraints for a given Assembly
component.

  Input Arguments:
     component       - The assembly component

  Output Arguments:
     pp_constraints  - ProArray of constraints

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully retrieved the information.
     PRO_TK_INVALID_TYPE - The component argument is not a valid assembly component.
     PRO_TK_BAD_INPUTS   - The input is invalid.
     PRO_TK_E_NOT_FOUND  - The assembly component does not have any constraints.
*/

extern ProError ProAsmcompConstraintsSet (ProAsmcomppath* component_path, 
                                          ProAsmcomp *component,
                                          ProAsmcompconstraint *p_constraints );
/*
  Purpose:     sets an array of constraints for a given Assembly component.
               This function modifies the component feature data and 
               regenerates the assembly component.              
               

  Input Arguments:
      component_path -  The path to the owner assembly, if the contstraints
                        have references to other members of the top level assembly.
                        If the constraints are only with respect to the assembly
                        owner in component, this should be NULL.
      component      -  The assembly component
      p_constraints  -  ProArray of constraints

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully set the information.
     PRO_TK_BAD_INPUTS   - The input is invalid.
     PRO_TK_INVALID_TYPE - The component argument is not a valid assembly component.
     PRO_TK_INVALID_PTR  - The p_constraints array is not a valid ProArray.
     
     PRO_TK_GENERAL_ERROR - Regeneration using the specified constraints failed; the component 
                            reverted to the previous configuration.

  See Also:
     ProWindowRepaint()
     ProTreetoolRefresh()

*/


extern  ProError ProAsmcompconstraintAlloc ( ProAsmcompconstraint *p_constraint );

/*
  Purpose:     Allocates memory for an assembly component constraint structure.

  Input Arguments:      None

  Output Arguments:
     p_constraint - The Asmcomp constraint structure

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully allocated memory for the
                            structure.
     PRO_TK_OUT_OF_MEMORY - Insufficient memory.
     PRO_TK_BAD_INPUTS    - The input is invalid.
*/

extern ProError ProAsmcompconstraintFree ( ProAsmcompconstraint constraint );

/* 
  Purpose:     Frees all underlying memory of the assembly component constraint structure.

  Input Arguments:
    constraint - The Asmcomp constraint structure.

  Output Arguments:
    None

  Return Values:
    PRO_TK_NO_ERROR   - The function successfully freed the memory.
    PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintArrayFree ( ProAsmcompconstraint* constraint_array );

/* 
  Purpose:     Frees all underlying memory of an assembly component 
               constraints array.

  Input Arguments:
    constraint_array - The Asmcomp constraint ProArray.

  Output Arguments:
    None

  Return Values:
    PRO_TK_NO_ERROR   - The function successfully freed the memory.
    PRO_TK_BAD_INPUTS - The argument is invalid.
*/


extern ProError ProAsmcompconstraintTypeGet ( ProAsmcompconstraint constraint,ProAsmcompConstrType *type );
/*
  Purpose:     retrieves the constraint type for the given constraint.

  Input Arguments:
    constraint - The Assembly component constraint.

  Output Arguments:
    type - The constraint type.

  Return Values:
    PRO_TK_NO_ERROR   - The function successfully retrieved the
                        information.
    PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintTypeSet ( ProAsmcompconstraint constraint,ProAsmcompConstrType type );
/*
  Purpose:     sets the constraint type for the specified constraint.

  Input Arguments:
     type       - The constraint type.
     constraint - The Assembly component constraint.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully set the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintAsmreferenceGet ( ProAsmcompconstraint constraint,
                                                      ProSelection *asm_ref,
                                                      ProDatumside *asm_orient);
/*
  Purpose:     retrieves the constraint references and orientations for 
               the given constraint.

  Input Arguments:
    constraint - The Assembly component constraint.

  Output Arguments:
    asm_ref    - The assembly reference.
    asm_orient - assembly orientation

  Return Values:
     PRO_TK_NO_ERROR       -   The function successfully retrieved the 
                               information.
     PRO_TK_BAD_INPUTS     -   The argument is invalid.
     PRO_TK_E_NOT_FOUND    -   Assembly reference not found .
     PRO_TK_GENERAL_ERROR  -   Information retrieval failed .
*/

extern ProError ProAsmcompconstraintAsmreferenceSet ( ProAsmcompconstraint constraint,
                                                      ProSelection asm_ref,
                                                      ProDatumside asm_orient);
/*
  Purpose:     sets the constraint references and orientations to the 
specified constraint.

  Input Arguments:
    constraint   - The Assembly component constraint.
    asm_ref      - The assembly reference.
    asm_orient   - assembly orientation

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully set the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintCompreferenceGet ( ProAsmcompconstraint constraint,
                                                       ProSelection *comp_ref,
                                                       ProDatumside *comp_orient);
/*
  Purpose:     retrieves the constraint references and orientations for 
               the given constraint.

  Input Arguments:
    constraint - The Assembly component constraint.

  Output Arguments:
    comp_ref    - The component reference.
    comp_orient - component orientation

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS     - The argument is invalid.
     PRO_TK_E_NOT_FOUND    - Component reference not found .
     PRO_TK_GENERAL_ERROR  - Information retrieval failed .
*/

extern ProError ProAsmcompconstraintCompreferenceSet ( ProAsmcompconstraint constraint,
                                                       ProSelection comp_ref,
                                                       ProDatumside comp_orient);
/*
  Purpose:     sets the constraint references and orientations to the 
               specified constraint.

  Input Arguments:
    constraint   - The Assembly component constraint.
    comp_ref     - The component reference.
    comp_orient  - component orientation

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully set the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintOffsetGet ( ProAsmcompconstraint constraint,
                                                double *offset);
/*
  Purpose:     retrieves the mate/align offset value for the given
               constraint.

  Input Arguments:
     constraint - The Assembly component constraint.

  Output Arguments:
     offset - The mate/align offset value.

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintOffsetSet (ProAsmcompconstraint constraint,
                                               double offset);
/*
  Purpose:     sets the mate/align offset value to the specified
constraint.

  Input Arguments:
     offset     - The offset value.
     constraint - The Assembly component constraint.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR - The function successfully set the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintAttributesGet ( ProAsmcompconstraint constraint,
                                                    int *attributes);
/*
  Purpose:     retrieves the constraint attributes for the given
constraint.

  Input Arguments:
     constraint - The Assembly component constraint.

  Output Arguments:
     attributes - The constraint attributes.

  Return Values:
     PRO_TK_NO_ERROR - The function successfully retrieved the 
information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompconstraintAttributesSet ( ProAsmcompconstraint constraint ,
                                                    int attributes);
/*
  Purpose:     sets the constraint attributes to the specified
constraint.

  Input Arguments:
     constraint - The Assembly component constraint.
     attributes - The constraint attributes.

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR - The function successfully set the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/


extern ProError ProAsmcompconstraintUserdataGet ( ProAsmcompconstraint constraint,
                                                  wchar_t** usr_data);


/*
  Purpose:     retrieves the user data for the given constraint.

  Input Arguments:
     constraint - The Assembly component constraint.

  Output Arguments:
     usr_data - User data.  Free the memory for this string using 
                ProWstringFree().

  Return Values:
     PRO_TK_NO_ERROR - The function successfully retrieved the
information.
     PRO_TK_BAD_INPUTS     - The argument is invalid.
     PRO_TK_E_NOT_FOUND    - User data not found .
*/

extern ProError ProAsmcompconstraintUserdataSet ( ProAsmcompconstraint constraint,
                                                  wchar_t* usr_data);
/*
  Purpose:     sets the user data to the specified constraint.

  Input Arguments:
     constraint - The Assembly component constraint.
     usr_data   - User data.

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR - The function successfully set the information.
     PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProAsmcompAssemble ( ProAssembly   owner_assembly,
                                     ProSolid           component_model,
                                     ProMatrix           init_pos,
                                     ProAsmcomp *feature );
/*
  Purpose:     Adds a component to a specified assembly or sub-assembly at
               the specified initial position.

  Input Arguments:
               owner_assembly      - The assembly/sub-assembly into which the 
                                     component is added.
                                     NULL is a valid argument.Current Assembly is used 
                                     in this case .
               component_model     - The assembly component model
               init_pos            - The component initial position

  Output Arguments:
               feature             - handle to the newly created assembly componennt.

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully created an assembly =
component.
     PRO_TK_BAD_INPUTS  - The input is invalid.
     PRO_TK_UNSUPPORTED - Unsupported model. For instance, models which come
                          from Multi-CAD model approach,
                          are not supported in this release.
*/

extern ProError   ProAsmcompPositionGet (ProAsmcomp*     component,
                                         ProMatrix    position);
/* 
   Purpose:   Retrieves the component's initial position before
              constraints and movements have been applied.  If
              the component is fully packaged this position is
              the same as the constraint's actual position.

   Input Arguments:
              component     - The assembly component

   Output Arguments:
              position      - The position

   Return Values:
              PRO_TK_NO_ERROR      -  The function successfully retrieved the information.
              PRO_TK_BAD_INPUTS    -  The input argument was invalid.
              PRO_TK_E_NOT_FOUND   -  The input argument was of type - bulk item .
*/


/**********************************************************************/

extern ProError   ProAsmcompPositionSet (ProAsmcomppath* component_path,
                                  ProAsmcomp*     component,
                                  ProMatrix      position);

/* 
   Purpose:   Sets the component's initial position before
              constraints and movements have been applied.  If
              the component is packaged this position helps to
              determine the component's actual position.

              This function modifies the assembly component data but does
              not regenerate the assembly component.  To regenerate the 
              component, use ProAsmcompRegenerate().

   Input Arguments:
      component_path - The path from the top level assembly to the component
                       feature.  Required if the component has external
                       references to geometry outside of the immediate
                       assembly. If the component does not have any external
                       references, NULL is allowed.
      component      - The assembly component
      position       - The position

    Output Arguments:
       none

    Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the information.
       PRO_TK_BAD_INPUTS - An input argument was invalid or component is of 
                           type - bulk item .
*/

extern ProError ProAsmcompRegenerate  (ProAsmcomp *p_comp_handle,
                                       ProBoolean  update_soft);
/*

   Purpose: Regenerates placement instructions.

   Input Arguments:
       p_comp_handle  - The component to regenerate. 
       update_soft    - Reserved for future use. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The argument corresponds to a valid component
                            feature with a valid component model.
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid component
                            feature.
*/

extern ProError ProAsmcompPackageMove (ProAsmcomp *p_feat_handle,
                                       ProMotionType motion_type,
                                       ProBoolean    showui,
                                       ProMotionRefType motion_ref_type,
                                       ProSelection         motion_ref[],
                                       int                  sel_sz);
/*

   Purpose: Invokes the package move interface for the specified component.
            Default values for the old behavior:
                        <UL>
                                <LI>p_feat_handle: The component to be "moved"
                                <LI>motion_type: PRO_M_UNDEF
                                <LI>showui: PRO_B_TRUE
                                <LI>motion_ref_type: PRO_M_VIEW_PLANE
                                <LI>motion_ref[]: NULL
                                <LI>sel_sz: 0
                        </UL>

   Input Arguments:
       p_feat_handle   - The component to be "moved" 
       motion_type     - See the enum ProMotionType
       showui          - Dialog or action only
       motion_ref_type - See the enum ProMotionRefType
       motion_ref      - Array of sel ptrs
       sel_sz          - Array size.

   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR     - The argument corresponds to a valid component
                            feature with a valid component model.
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid component
                            feature.
      PRO_TK_USER_ABORT   - The package move was aborted by the user.
*/

extern ProError ProAsmcompMdlNameGet (ProAsmcomp     *p_asm_comp_handle,
                                      ProMdlType     *r_mdl_type,
                                      ProFamilyName  r_mdl_name);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProAsmcompMdlMdlnameGet
   Purpose: <b>Note:</b> This function is deprecated
            Use ProAsmcompMdlMdlnameGet instead.

            Retrieves the name and type of the model, given the
            handle to the assembly component. 

   Input Arguments:
       p_asm_comp_handle  - The handle to the assembly component 

   Output Arguments:
       r_mdl_type         - The model type
       r_mdl_name         - The name of the model 

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProAsmcompMdlMdlnameGet (ProAsmcomp      *p_asm_comp_handle,
                                         ProMdlfileType  *r_mdl_type,
                                         ProFamilyMdlName r_mdl_name);
/*

   Purpose: Retrieves the name and type of the model, given the
            handle to the assembly component. 

            <b>Note:</b> In Creo 3 this function does not support names longer 
            than 80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
            The support for ProFamilyMdlName will be added in a future release. 

   Input Arguments:
       p_asm_comp_handle  - The handle to the assembly component 

   Output Arguments:
       r_mdl_type         - The model type
       r_mdl_name         - The name of the model. Free this argument using
                            ProWstringFree.

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProAsmcompMdldataGet (ProAsmcomp      *p_asm_comp_handle,
                                      ProMdlType      *r_mdl_type,
                                      ProMdlfileType  *r_mdl_filetype,
                                      ProFamilyMdlName r_mdl_name);
/*

   Purpose: Retrieves the name and type of the model, given the
            handle to the assembly component. 

            <b>Note:</b> In Creo 3 this function does not support names longer 
            than 80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
            The support for ProFamilyMdlName will be added in a future release. 

   Input Arguments:
       p_asm_comp_handle  - The handle to the assembly component.
                            Cannot be NULL.

   Output Arguments:
       r_mdl_type         - The model type. Can be NULL.
       r_mdl_filetype     - The model filetype. Can be NULL.
       r_mdl_name         - The name of the model. Free this argument using
                            ProWstringFree. Can be NULL.

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProAsmcompConstrRemove  (ProAsmcomp *p_feat_handle,
                                                    int         index);
/*
   Purpose: Removes a component constraint, given a handle to the assembly
            component and the index of the constraint to remove.
            Intrfc constraint remains intact since main intrfc plin couldn't
            be removed whence all plins will be restored upon regen.

   Input Arguments:
       p_feat_handle  - The handle to the assembly component. 

       index          - The index of component to be removed.
                        Indexing begins with 0 and continues
                                    to (<i>number of constraints</i>-1).  An
                                index of -1 removes all the constraints. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully removed the constraint. 
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid component
                            feature.
      PRO_TK_E_NOT_FOUND  - The specified constraint does not exist.
*/

extern ProError ProAsmcompAllConstrRemove (ProAsmcomp *p_feat_handle);
/*
      Purpose: Removes all component constraints, given a handle to the assembly
            component.

   Input Arguments:
       p_feat_handle  - The handle to the assembly component.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully removed all constraints.
      PRO_TK_BAD_INPUTS   - The specified feature is not a valid component
                            feature.
*/

extern ProError ProAsmcompCreateCopy (ProAssembly  assembly,
                                      ProName      comp_name,
                                      ProMdlType   comp_type,
                                      ProMdl       template_model,
                                      ProBoolean   leave_unplaced,
                                      ProAsmcomp  *p_comp_handle);
/*
 DEPRECATED: Since Creo 3
 SUCCESSORS: ProAsmcompMdlnameCreateCopy
 Purpose: <b>Note:</b> This function is deprecated
          Use ProAsmcompMdlnameCreateCopy instead.

          Create a new component in the specified assembly by copying
          from the specified model. If no model is specified, the new
          component is created empty. This function either places the new 
          component at a default location in the assembly or leaves it unplaced.
          This function also initializes the component handle.

  Input Arguments:
     assembly       - The specified assembly.
     comp_name      - The new component name.
     comp_type      - The new component type; must be either
                      PRO_MDL_ASSEMBLY or PRO_MDL_PART.
     template_model - Handle to model to be used as a template.
                      If NULL, empty component will be created.
     leave_unplaced - If PRO_B_TRUE, the component is left unplaced.
                      If PRO_B_FALSE, the component is placed by default.

  Output Arguments:
     p_comp_handle  - Handle to the new component to be initialized.

  Return Values:
     PRO_TK_NO_ERROR      - Component add was successful.
     PRO_TK_BAD_INPUTS    - Invalid name or type for assembly handle or 
                            component; or invalid template handle.
     PRO_TK_INVALID_TYPE  - Template type does not correspond to component type.
     PRO_TK_ABORT         - The model can not be used as a template or has
                            external dependencies. Copy is aborted.
     PRO_TK_GENERAL_ERROR - Component creation failed.
     PRO_TK_NOT_VALID     - Required license not found.
     PRO_TK_LINE_TOO_LONG - comp_name length of the new component is 
                            more than 31 chars.
     PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come
                            from Multi-CAD model approach,
                            are not supported in this release.
*/

extern ProError ProAsmcompMdlnameCreateCopy (ProAssembly  assembly,
                                             ProMdlName   comp_name,
                                             ProMdlType   comp_type,
                                             ProMdl       template_model,
                                             ProBoolean   leave_unplaced,
                                             ProAsmcomp  *p_comp_handle);
/*
 Purpose: Create a new component in the specified assembly by copying
          from the specified model. If no model is specified, the new
          component is created empty. This function either places the new 
          component at a default location in the assembly or leaves it unplaced.
          This function also initializes the component handle.

		  <b>Note:</b> In Creo 3 this function does not support names longer than 
		  31 characters. It will return PRO_TK_LINE_TOO_LONG for longer names. 
		  The support for ProMdlName will be added in a future release. 


  Input Arguments:
     assembly       - The specified assembly.
     comp_name      - The new component name.
     comp_type      - The new component type; must be either
                      PRO_MDL_ASSEMBLY or PRO_MDL_PART.
     template_model - Handle to model to be used as a template.
                      If NULL, empty component will be created.
     leave_unplaced - If PRO_B_TRUE, the component is left unplaced.
                      If PRO_B_FALSE, the component is placed by default.

  Output Arguments:
     p_comp_handle  - Handle to the new component to be initialized.

  Return Values:
     PRO_TK_NO_ERROR      - Component add was successful.
     PRO_TK_BAD_INPUTS    - Invalid name or type for assembly handle or 
                            component; or invalid template handle.
     PRO_TK_INVALID_TYPE  - Template type does not correspond to component type.
     PRO_TK_ABORT         - The model can not be used as a template or has
                            external dependencies. Copy is aborted.
     PRO_TK_GENERAL_ERROR - Component creation failed.
     PRO_TK_NOT_VALID     - Required license not found.
     PRO_TK_LINE_TOO_LONG - comp_name length of the new component is 
                            more than 31 chars. This restriction will be removed
                            in future releases.
     PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come
                            from Multi-CAD model approach,
                            are not supported in this release.

*/

extern ProError ProAsmcompIsUnplaced  (ProAsmcomp *comp_handle,
                                             ProBoolean *p_comp_is_unplaced);
/*
    Purpose: Determine if the specified component is unplaced.

   Input Arguments:
     comp_handle        - Handle to the component to be checked.

   Output Arguments:
     p_comp_is_unplaced - PRO_B_TRUE if the component is unplaced,
                          otherwise PRO_B_FALSE.

   Return Values:
     PRO_TK_NO_ERROR    -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS  -  The component handle is invalid.
     PRO_TK_NOT_VALID   -  Required license not found.

*/

extern ProError ProAsmcompFillFromMdl (ProAsmcomp *comp_handle,
                                       ProMdl      template_model);
/*
  Purpose: Copy specified template into a model of the specified component.

   Input Arguments:
     comp_handle    - Handle to the component.
     template_model - Handle to the model to be used as the copy template.

   Output Arguments:
     None

   Return Values:
     PRO_TK_NO_ERROR      -  The action has been successfully performed.
     PRO_TK_BAD_INPUTS    -  The component handle is invalid; or the template
                             handle is invalid; or the template type does not
                             correspond to that of the component model.
     PRO_TK_INVALID_TYPE  -  The template type does not correspond
                             to the component type.
     PRO_TK_E_FOUND       -  Features exist in a model of the component;
                             copying the template to this model is not allowed.
     PRO_TK_ABORT         -  The model can not be used as a template or has
                             external dependencies. Copy is aborted.
     PRO_TK_GENERAL_ERROR -  Component creation failed.
     PRO_TK_NOT_VALID     -  Required license not found.
*/

extern ProError ProAsmcompIsPlaced (ProAsmcomp *p_comp,
                                    ProBoolean *p_is_placed);
/*
   Purpose: Determine whether the specified component is placed.
 
   Input Arguments:
     p_comp           - The component to be checked.
 
   Output Arguments:
     p_is_placed      - This is PRO_B_TRUE if the component is placed;
                        otherwise, this is PRO_B_FALSE.
 
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
 
*/

extern ProError ProAsmcompSetPlaced (ProAsmcomp *p_comp,
                                     ProBoolean  p_is_placed);
/*
   Purpose: Set the placed flag for the specified component.
 
   Input Arguments:
     p_comp           - The component to set the placed flag.
     p_is_placed      - The flag that needs to be set. It is either PRO_B_TRUE
                        or PRO_B_FALSE.
 
   Output Arguments:
      None 
 
   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded in setting the value.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
 
*/

extern ProError ProAsmcompMakeUniqueSubasm (ProAsmcomppath *p_path);
 
/*
   Purpose: Make a new instance of a sub-assembly, given its path. 
 
   Input Arguments:
      p_path         - The path from the top level assembly to the
                       specified unique sub-assembly.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created a new instance.
      PRO_TK_BAD_INPUTS - The path is invalid.
 
*/

extern ProError ProAsmcompRmvUniqueSubasm  (ProAsmcomppath *p_path);
 
/*
   Purpose:     Remove the run-time instance of a unique sub-assembly,
                given its path.
 
   Input Arguments:
      p_path            - The path from top level assembly to the unique
                          sub-assembly which is to be removed.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully removed the new instance.
      PRO_TK_BAD_INPUTS - The path is invalid.
 
*/

extern ProError ProAsmcompIsSubstitute (ProAsmcomp *p_comp,
                                        ProBoolean *p_is_sub);
/*
   Purpose: Determine whether the specified component is substituted.
 
   Input Arguments:
     p_comp           - The component to be checked.
 
   Output Arguments:
     p_is_sub         - This is PRO_B_TRUE if the component is substituted;
                        otherwise, this is PRO_B_FALSE.
 
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
 
*/



extern ProError ProAsmcompIsPackaged (ProAsmcomp  *comp_handle,
                                      ProBoolean  *p_comp_is_packaged );

/*
    Purpose: Determine if the specified component is packaged.

   Input Arguments:
     comp_handle        - Handle to the component to be checked.

   Output Arguments:
     p_comp_is_packaged - PRO_B_TRUE if the component is packaged,
                          otherwise PRO_B_FALSE.

   Return Values:
     PRO_TK_NO_ERROR    -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS  -  The component handle is invalid.

*/



extern ProError ProAsmcompIsFrozen (ProAsmcomp  *comp_handle,
                                    ProBoolean  *p_comp_is_frozen );

/*
   Purpose: Determine if the specified component is frozen.

   Input Arguments:
     comp_handle        - Handle to the component to be checked.

   Output Arguments:
     p_comp_is_frozen   - PRO_B_TRUE if the component is frozen,
                          otherwise PRO_B_FALSE.

   Return Values:
     PRO_TK_NO_ERROR    -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS  -  The component handle is invalid.

*/



extern ProError ProAsmcompIsUnderconstrained(ProAsmcomp *comp_handle,
                                             ProBoolean *p_comp_is_underconstrained);
/*
   Purpose: Determine if the specified component is underconstrained.
 
   Input Arguments:
     comp_handle        - Handle to the component to be checked.
 
   Output Arguments:
     p_comp_is_underconstrained - PRO_B_TRUE if the component is underconstrained,                                otherwise PRO_B_FALSE.
 
   Return Values:
     PRO_TK_NO_ERROR    -  The function successfully returned the information.
     PRO_TK_BAD_INPUTS  -  The component handle is invalid.
 
*/

extern ProError ProAsmcompAsmitemInit (ProMdl p_owner_handle, int item_id,
  ProType item_type, ProName name, ProAsmcomppath *path,
  ProAsmitem  *p_handle);
/*
Purpose:     Initializes the ProAsmitem handle. 

   Input Arguments:
      p_owner_handle    - The model owner of the item
      item_id           - The item identifier
      item_type         - The item type
      name              - The parameter name :
                          used for PRO_PARAMETER in 
                          this case item_type should be PRO_PART or PRO_ASSEMBLY
      path              - The item path. To set a component as flexible, the path of this ProAsmitem 
                          should not contain the ID of a component which is
                          <ul>                         
                           <li>out of flexible context.
                           <li>to be made flexible.
                          </ul>

   Output Arguments:
      p_handle          - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid 
                          or item was not found .
*/

extern ProError ProAsmcompIsFlexible (ProAsmcomp *p_comp_handle,
                                      ProBoolean *p_is_flex_comp);
/*
   Purpose: Determines whether the specified component is a flexible component.

   Input Arguments:
     p_comp_handle    -  The component to be checked.

   Output Arguments:
     p_is_flex_comp   -  This is PRO_B_TRUE if the component 
                         is a flexible component; otherwise, this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully returned the information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProAsmcompFlexiblemodelAdd (ProAsmcomp *comp, 
                ProAsmcomppath *p_flex_mdl_path,
                ProMdl *p_flex_model);
/*
   Purpose: Creates a flexible model from the specified model of the flexible component.

   Input Arguments:
     comp               -  flexible component
     p_flex_mdl_path    -  relative path to flexible model from the top model of the flexible
                           component

   Output Arguments:
     p_flex_model   -  the created flexible model

   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProAsmcompVarieditemsToModelAdd (ProMdl model, ProAsmitem  *varied_items);
/*
   Purpose: Add pre-defined flexible items to the regular component model to be used 
            later when calling ProAsmcompFlexibleWithPredefineditemsSet()

   Input Arguments:
     model        -  model which will contains the specified varied items
     varied_items -  ProArray of varied items to be added as predefined flexibility
                     for the specified model. Path of varied items should start from "model".

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/
extern ProError ProAsmcompFlexibleWithPredefineditemsSet (ProAsmcomp *comp);
/*
   Purpose: convert the specified component to flexible one using the predefined
            flexibility varied items defined on its component model.

   Input Arguments:
     comp    -  The component to be converted to flexible one

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProAsmcompFlexibleSet (ProAsmcomp *comp, 
                                       ProAsmitem *varied_items);
/*
   Purpose: convert the component to flexible one using the 
            specified varied items 

   Input Arguments:
     comp         -  The component to be converted to flexible one
     varied_items -  ProArray of varied items to be used for the
                     flexible component definition. Path of varied items should start from "comp".

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

extern ProError ProAsmcompFlexibleUnset (ProAsmcomp *flexible_comp);
/*
   Purpose: convert a flexible component to the regular one

   Input Arguments:
      flexible_comp  -  The component to be converted to regular one

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function succeeded
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
*/

PRO_END_C_DECLS


#endif  /* PROASMCOMP_H */
