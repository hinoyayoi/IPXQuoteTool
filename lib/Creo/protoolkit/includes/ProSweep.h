#ifndef PROSWEEP_H
#define PROSWEEP_H

#include <ProToolkit.h>




PRO_BEGIN_C_DECLS

/************************ SWEEP ********************************

Feature element tree

PRO_E_FEATURE_TREE 
 |
 |---PRO_E_FEATURE_FORM 
 |---PRO_E_SWEEP_TYPE
 |
 |---PRO_E_SWEEP_FRAME_COMP 
 |    |---PRO_E_FRM_OPT_TRAJ  
 |    |    |---PRO_E_OPT_TRAJ   
 |    |         |---PRO_E_STD_SEC_METHOD
 |    |         | 
 |    |         |---PRO_E_STD_SEC_SELECT  
 |    |              |---PRO_E_STD_CURVE_COLLECTION_APPL 
 |    |
 |    |         
 |    |---PRO_E_FRAME_SETUP 
 |    |    |---PRO_E_FRM_NORMAL
 |    |    |---PRO_E_FRM_PIVOT_DIR 
 |    |    |    |---PRO_E_DIRECTION_COMPOUND
 |    |    |         |---PRO_E_DIRECTION_REFERENCE
 |    |    |         |---PRO_E_DIRECTION_FLIP 
 |    |    |---PRO_E_FRM_CONST_Z 
 |    |    |    |---PRO_E_DIRECTION_COMPOUND 
 |    |    |         |---PRO_E_DIRECTION_REFERENCE 
 |    |    |         |---PRO_E_DIRECTION_FLIP
 |    |    |---PRO_E_FRM_ORIENT
 |    |    |---PRO_E_FRM_NORM_SURF   (COMPOUND) 
 |    |    |    |---PRO_E_SURF_CHAIN_CMPND 
 |    |    |    |    |---PRO_E_SURF_CHAIN_METHOD
 |    |    |    |    |---PRO_E_SURF_CHAIN_REF_SURFS
 |    |    |    |---PRO_E_FRM_NORM_SURF_SIDE
 |    |    |---PRO_E_FRM_USER_X
 |    |    |---PRO_E_FRM_START_X 
 |    |    |    |---PRO_E_DIRECTION_COMPOUND
 |    |    |         |---PRO_E_DIRECTION_REFERENCE
 |    |    |         |---PRO_E_DIRECTION_FLIP
 |---PRO_E_SWEEP_PROF_COMP
 |    |---PRO_E_SWP_SEC_TYPE
 |    |---PRO_E_SWEEP_SECTION 
 |         |
 |         |---PRO_E_SKETCHER  POINTER          
 |---PRO_E_SWP_ATTR 
 |    |---PRO_E_END_SRF_ATTR
 |    
 |---PRO_E_STD_FEATURE_NAME 
 |---PRO_E_EXT_SURF_CUT_SOLID_TYPE
 |---PRO_E_REMOVE_MATERIAL 
 |---PRO_E_FEAT_FORM_IS_THIN
 |---PRO_E_STD_MATRLSIDE
 |---PRO_E_THICKNESS 
 |---PRO_E_TRIM_QUILT
 |---PRO_E_TRIM_QLT_SIDE 
 | *** The Following elements are applicable only in sheetmetal parts ***
 |---PRO_E_STD_SMT_THICKNESS 
 |---PRO_E_STD_SMT_SWAP_DRV_SIDE
 |---PRO_E_SMT_WALL_SHARPS_TO_BENDS 
 |---PRO_E_SMT_FILLETS 
 |    |---PRO_E_SMT_FILLETS_SIDE 
 |    |---PRO_E_SMT_FILLETS_VALUE  
 |---PRO_E_SMT_DEV_LEN_CALCULATION 
 |    |---PRO_E_SMT_DEV_LEN_SOURCE 
 |    |---PRO_E_SMT_DEV_LEN_Y_FACTOR 
 |    |    |---PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE
 |    |    |---PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE 
 |    |---PRO_E_SMT_DEV_LEN_BEND_TABLE 
 |---PRO_E_SMT_MERGE_DATA
      |---PRO_E_SMT_MERGE_AUTO
      |---PRO_E_SMT_MERGE_KEEP_LINES 



*************************************************************************/

/*
------------------------------------------------------------------------------
Element Id                   Element Name           Data Type
------------------------------------------------------------------------------
PRO_E_FEATURE_FORM               Feature Form        PRO_VALUE_TYPE_INT
PRO_E_SWEEP_TYPE                 Sweep Type          PRO_VALUE_TYPE_INT
PRO_E_SWEEP_FRAME_COMP           Sweep Frame         Compound
PRO_E_FRM_OPT_TRAJ               Trajectories Array  Array
PRO_E_OPT_TRAJ                   Trajectory          Compound
PRO_E_FRAME_SETUP                Frame setup         Compound
PRO_E_FRM_NORMAL                 Sect. plane normal  PRO_VALUE_TYPE_INT
PRO_E_FRM_PIVOT_DIR              Proj Dir. holder    Compound
PRO_E_FRM_CONST_Z                Const Z Dir. holder Compound
PRO_E_DIRECTION_COMPOUND         Direction Element   Compound
PRO_E_FRM_Z_CHOICE_BTN           Normal traj index   PRO_VALUE_TYPE_INT
PRO_E_FRM_ORIENT                 Sect. Horiz/Vert    PRO_VALUE_TYPE_INT
PRO_E_FRM_NORM_SURF              Normal surf. holder Compound
PRO_E_SURF_CHAIN_CMPND           Surfaces from chain Compound 
PRO_E_FRM_NORM_SURF_SIDE         Normal surf. side   PRO_VALUE_TYPE_INT
PRO_E_FRM_USER_X                 User sel. start X   PRO_VALUE_TYPE_INT
PRO_E_FRM_START_X                Start X Dir holder  Compound
PRO_E_FRM_X_CHOICE_BTN           X traj. index       PRO_VALUE_TYPE_INT
PRO_E_FRM_TRAJS_APPENDIX         Hidden traj. block  PRO_VALUE_TYPE_SELECTION
PRO_E_SWEEP_PROF_COMP            Sweep Sect. holder  Compound
PRO_E_SWP_SEC_TYPE               Section type        PRO_VALUE_TYPE_INT
PRO_E_SWEEP_SECTION              Section             Compound
PRO_E_SWP_ATTR                   Sweep Attributes    Compound
PRO_E_END_SRF_ATTR               End Cap             PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME           Feature Name        PRO_VALUE_TYPE_WSTRING
PRO_E_EXT_SURF_CUT_SOLID_TYPE    Feature Type        PRO_VALUE_TYPE_INT
PRO_E_REMOVE_MATERIAL            Material Removal    PRO_VALUE_TYPE_INT
PRO_E_FEAT_FORM_IS_THIN          Feature Form        PRO_VALUE_TYPE_INT
PRO_E_STD_MATRLSIDE              Material Side       PRO_VALUE_TYPE_INT
PRO_E_THICKNESS                  Thin width          PRO_VALUE_TYPE_DOUBLE
PRO_E_TRIM_QUILT                 Trim Quilt          PRO_VALUE_TYPE_SELECTION
PRO_E_TRIM_QLT_SIDE              Quilt Side          PRO_VALUE_TYPE_INT
PRO_E_STD_SMT_THICKNESS          Smt Thickness       PRO_VALUE_TYPE_DOUBLE
PRO_E_STD_SMT_SWAP_DRV_SIDE      Smt Swap Side       PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_SHARPS_TO_BENDS   Edges to Bends      PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS                Smt Fillets         Compound
PRO_E_SMT_FILLETS_SIDE           Smt Radius Side     PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE          Smt Radius Value    PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_CALCULATION    Smt Develop Length  Compound
PRO_E_SMT_DEV_LEN_SOURCE         Smt Dev Len Source  PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_Y_FACTOR       Smt Dev Len Y Fact  Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE Y Factor Value      PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE  Y Factor Type       PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_BEND_TABLE     Smt Dev Bend Table  PRO_VALUE_TYPE_INT
PRO_E_SMT_MERGE_DATA             Smt Merge Wall Data Compound
PRO_E_SMT_MERGE_AUTO             Auto Merge Wall     PRO_VALUE_INT
PRO_E_SMT_MERGE_KEEP_LINES       Keep Merged Lines   PRO_VALUE_INT
*/

/************************************************************************

PRO_E_FEATURE_FORM          required type ProFeatFormType (see ProFeatForm.h)
                                  valid value  PRO_SWEEP 

PRO_E_SWEEP_TYPE            required type pro_sweep_type
                                  valid value  PRO_SWEEP_TYPE_MULTI_TRAJ

                               
PRO_E_STD_FEATURE_NAME      required Default given by application depending
                                on feature type.Can be modified by user.
                                
PRO_E_EXT_SURF_CUT_SOLID_TYPE  required  type  pro_sweep_feat_type
                                      valid values PRO_SWEEP_FEAT_TYPE_SOLID  
                                                   PRO_SWEEP_FEAT_TYPE_SURFACE
PRO_E_REMOVE_MATERIAL       requied   type    pro_sweep_rem_material 
                                      valid values PRO_SWEEP_MATERIAL_ADD
                                                   PRO_SWEEP_MATERIAL_REMOVE
PRO_E_FEAT_FORM_IS_THIN  requied for thin feature
                                     type pro_sweep_feat_form
                                     valid values  PRO_SWEEP_FEAT_FORM_NO_THIN (default)
                                                   PRO_SWEEP_FEAT_FORM_THIN 

PRO_E_STD_MATRLSIDE      requied for thin feature or cut
                                     type  pro_sweep_material_side
                                     valid values PRO_SWEEP_MATERIAL_SIDE_ONE 
                                                  PRO_SWEEP_MATERIAL_SIDE_TWO
                                                 PRO_SWEEP_MATERIAL_BOTH_SIDES
PRO_E_THICKNESS          required for thin feature      
                                      type PRO_VALUE_TYPE_DOUBLE
                                      valid value > 0.0
PRO_E_TRIM_QUILT         required for surface trim 
                                       type PRO_VALUE_TYPE_SELECTION
                                       selection of type Quilt
PRO_E_TRIM_QLT_SIDE      required for two sided surface trim i.e. 
                                         if  pro_sweep_material_side is 
                                         PRO_SWEEP_MATERIAL_BOTH_SIDES 
                                      type pro_sweep_trimqlt_side
                                      valid values PRO_SWEEP_TRIMQLT_SIDE_ONE
                                                   PRO_SWEEP_TRIMQLT_SIDE_TWO

PRO_E_FRM_OPT_TRAJ          required array of trajectories ( PRO_E_OPT_TRAJ ).
                                     Only one (origin) traj supported in Creo Parametric TOOLKIT.
PRO_E_OPT_TRAJ             trajectory  (selected section instance).                                     
                                              
PRO_E_FRM_NORMAL          required 
                                      type pro_frame_normal
                                      valid values  PRO_FRAME_NORM_ORIGIN  
                                                    PRO_FRAME_PIVOT_DIR
                                                    PRO_FRAME_CONST_Z_DIR
PRO_E_FRM_PIVOT_DIR  used and required only if PRO_E_FRM_NORMAL is 
                                               PRO_FRAME_PIVOT_DIR.
                              compound holder of direction elem.for pivot dir
                              of type PRO_E_DIRECTION_COMPOUND 
                              See ProDirection.h       
PRO_E_FRM_CONST_Z   used and required only if PRO_E_FRM_NORMAL is 
                                             PRO_FRAME_CONST_Z_DIR
                           compound holder of direction elem.for const Z dir.
                           of type PRO_E_DIRECTION_COMPOUND
                           See ProDirection.h  
                              
PRO_E_FRM_ORIENT     required 
                                      type enum pro_frame_orient
                                      valid values  PRO_FRAME_MIN      
                                                    PRO_FRAME_NORM_SURF
                                                    PRO_FRAME_CONSTANT
                                                   
 
PRO_E_FRM_NORM_SURF required if PRO_E_FRM_ORIENT is PRO_E_FRAME_NORM_SURF
                      holder of Surf Chain element 
                      Surf Chain Method should be populated 
                      Valid values PRO_SURF_CHAIN_METHOD_DEFAULT1, 
                                   PRO_SURF_CHAIN_METHOD_DEFAULT2 
                      PRO_E_SURF_CHAIN_METHOD_DEFAULT2 is the default. 
                      The other can be used only if 
                      the trajectory is comprised of two sided edges. 
                      see ProSurfchain.h
                      
PRO_E_FRM_NORM_SURF_SIDE required if PRO_E_FRM_ORIENT is PRO_E_FRAME_NORM_SURF
                                     type pro_frm_norm_srf_side
                                  valid values PRO_FRAME_NORM_SRF_SIDE_INSIDE 
                                               PRO_FRAME_NORM_SRF_SIDE_OUTSIDE
                                          
PRO_E_FRM_USER_X  needed if PRO_E_FRM_ORIENT is PRO_FRAME_MIN     
                               type pro_frame_start_x
                               valid values PRO_FRAME_DEFAULT_START_X (default)
                                            PRO_FRAME_USER_START_X  
                          If not default, then a direction must be provided 
                          in PRO_E_FRM_START_X.
                          
PRO_E_FRM_START_X  used and required only if PRO_E_FRM_USER_X is 
                                              PRO_FRAME_USER_START_X
                       compound holder of direction element for X direction 
                       at start, of type PRO_E_DIRECTION_COMPOUND.
                       See ProDirection.h  

PRO_E_SWEEP_PROF_COMP  compound holding Sweep Section related elements

PRO_E_SWP_SEC_TYPE     required  
                              type pro_sweep_sec_type
                              In Creo Parametric TOOLKIT only PRO_SWEEP_CONST_SECTION (= 8388608)
                              supported.
                                           
                                                                   
        
PRO_E_SWEEP_SECTION        required - Instance of PRO_E_STD_SECTION see
                                                               ProStdSection.h                                                         
                         
                       For more details refer ProStdSection.h 
                       See notes below for usage in Sweep
                       
PRO_E_END_SRF_ATTR     used only for surface feature.
                            type pro_sweep_end_srf_attr
                            valid values PRO_SWEEP_END_SRF_OPEN (default) 
                                         PRO_SWEEP_END_SRF_CAPPED

***********************************************************************/
                                
/************************************************************************
Direction elements holders: see ProDirection.h

PRO_E_FRM_PIVOT_DIR  used and required only if PRO_E_FRM_NORMAL is 
                     PRO_FRAME_PIVOT_DIR.
                     
PRO_E_FRM_CONST_Z   used and required only if PRO_E_FRM_NORMAL is 
                    PRO_FRAME_CONST_Z_DIR
                    
PRO_E_FRM_START_X   set and required only if PRO_E_FRM_USER_X is 
                    PRO_FRAME_USER_START_X                    

***********************************************************************/

/**************************

Element tree for sweep trajectories (selected section ).
This is one intance of selected section 
(others used in Swept Blend and Blends).

PRO_E_OPT_TRAJ 
 |---PRO_E_STD_SEC_METHOD 
 |
 |---PRO_E_STD_SEC_SELECT
 |    |---PRO_E_STD_CURVE_COLLECTION_APPL
 |
 |---PRO_E_SKETCHER  


------------------------------------------------------------------------------
Element Id                   Element Name           Data Type
------------------------------------------------------------------------------
PRO_E_OPT_TRAJ               Traj Holder           Compound
PRO_E_STD_SEC_METHOD         Section Method        PRO_VALUE_TYPE_INT
PRO_E_STD_SEC_SELECT         Selected section      Compound
PRO_E_STD_CURVE_COLLECTION_APPL Trajectory chain   PRO_VALUE_TYPE_SELECTION


PRO_E_STD_SEC_METHOD  required  valid value PRO_SEC_SELECT (= 26) defined in 
                                                           ProStdSection.h.
PRO_E_STD_SEC_SELECT  Selected trajectory holder     
PRO_E_STD_CURVE_COLLECTION_APPL required  chain reference 
                                          see ProCrvcollection.c    
                                                           
************************************************************************/


/************surf chain --  *******************/
   /* PRO_E_SURF_CHAIN_CMPND */ 
/*
 
PRO_E_SURF_CHAIN_CMPND
 |---PRO_E_SURF_CHAIN_METHOD 
 |---PRO_E_SURF_CHAIN_REF_SURFS
 |    |---PRO_E_SURF_CHAIN_SURF
 |    |    |---PRO_E_SURF_CHAIN_REF
 
 
*/


/*
------------------------------------------------------------------------------
Element Id                   Element Name           Data Type
------------------------------------------------------------------------------
PRO_E_SURF_CHAIN_CMPND       Surface from curve chain  Compound
PRO_E_SURF_CHAIN_METHOD      Method                    PRO_VALUE_TYPE_INT
PRO_E_SURF_CHAIN_REF_SURFS   Reference surfaces        Array
PRO_E_SURF_CHAIN_SURF        Reference surfaces        Compound
PRO_E_SURF_CHAIN_REF         Reference                 PRO_VALUE_TYPE_SELECTION
*/

/************************************************************************/
/* PRO_E_SURF_CHAIN_METHOD */

typedef enum pro_surf_chain_method
{
  PRO_SURF_CHAIN_METHOD_NOINIT    =       0,
  PRO_SURF_CHAIN_METHOD_DEFAULT1  =  (1<< 0),  /* side 1 of the chain */
  PRO_SURF_CHAIN_METHOD_DEFAULT2  =  (1<< 1),  /* side 2 of the chain */
  PRO_SURF_CHAIN_METHOD_SKETCH    =  (1<< 2),
  PRO_SURF_CHAIN_METHOD_SELECT    =  (1<< 3),
  PRO_SURF_CHAIN_METHOD_NONE      =  (1<< 4)
}ProSurfChainMethod;

/*
For PRO_E_FRM_NORM_SURF, needed if PRO_E_FRM_ORIENT is PRO_E_FRAME_NORM_SURF 
only  PRO_E_SURF_CHAIN_METHOD_DEFAULT1, PRO_E_SURF_CHAIN_METHOD_DEFAULT2 
are supported. Both are available only if the trajectory is comprised of 
two sided edges. 
*/


/***********************end of surf chain **********************************/


/***********************************************************************/

 /* PRO_E_SWEEP_PROF_COMP */  
 /* holder of section related elements, mostly PRO_E_SWEEP_SECTION */
 
 
 /* PRO_E_SWEEP_SECTION */
 /* Instance of standard section */
 /* For more details refer ProStdSection.h */
                              
 /* Note that for this feature the PRO_E_SEC_USE_SKETCH is not available, 
 and the setup plane is filled by the feature (based on location and frame 
 options). Thus only the sketch (PRO_E_SKETCHER) has to be defined by the 
 user 
 */
 
 /*
 PRO_E_STD_SEC_METHOD      Section Method             PRO_VALUE_TYPE_INT
 */

/* 
PRO_E_STD_SEC_METHOD  required  valid value PRO_SEC_SKETCH (= 25) defined in 
                                                           ProStdSection.h 
*/                                                           
/************************************************************************/


/************************************************************************/
/*  PRO_E_SWEEP_TYPE */


typedef enum pro_sweep_type
{
  PRO_SWEEP_TYPE_UNDEF      = 0,
  PRO_SWEEP_TYPE_MULTI_TRAJ = 128
}ProSweepType;

/************************************************************************/

/* PRO_E_FRM_NORM_SURF_SIDE */


typedef enum pro_frm_norm_srf_side
{
  PRO_FRAME_NORM_SRF_SIDE_INSIDE  = -1,
  PRO_FRAME_NORM_SRF_SIDE_OUTSIDE = 1
}ProFrmNormSrfSide;


/************************************************************************/
/* PRO_E_FRM_NORMAL */

typedef enum pro_frame_normal
{
  PRO_FRAME_NORM_ORIGIN    =        0, /* normal to the origin traj.       */
  PRO_FRAME_PIVOT_DIR      =   (1<<9), /* "normal to projection" option    */
  PRO_FRAME_NORM_TRAJ_DIR  =  (1<<22), /* normal given by additional traj  */
  PRO_FRAME_CONST_Z_DIR    =  (1<<26)  /* constant normal direction        */
}ProFrameNormal;

/*

PRO_FRAME_NORM_ORIGIN: default. Normal provided by the origin trajectory.
PRO_FRAME_PIVOT_DIR: a direction must be provided in PRO_E_FRM_PIVOT_DIR
                     and PRO_E_FRM_ORIENT must be PRO_FRAME_CONSTANT.
PRO_FRAME_NORM_TRAJ_DIR: the index of the traj must be provided in 
                         PRO_E_FRM_Z_CHOICE_BTN. Not supported in ProTK
PRO_FRAME_CONST_Z_DIR: a direction must be provided in PRO_E_FRM_CONST_Z

*/
/************************************************************************/


/************************************************************************/
/* PRO_E_FRM_ORIENT */

 typedef enum pro_frame_orient
{
  PRO_FRAME_MIN       =  1, /* Automatic                      */
  PRO_FRAME_NORM_SURF =  2, /* Normal to surface              */
  PRO_FRAME_CONSTANT  =  3, /* option for PRO_FRAME_PIVOT_DIR */
  PRO_FRAME_X_TRAJ    =  4 /* Orient from X trajectory       */ 
}ProFrameOrient;

/*
PRO_FRAME_MIN       : Used for "Automatic" option.
PRO_FRAME_NORM_SURF: can be used only if the chain is from curves on surfaces,  
                     such as edges, same feature projected curves, 
                     curves from intersection.
PRO_FRAME_CONSTANT:  must be set if and only if PRO_E_FRM_NORMAL is 
                     PRO_FRAME_PIVOT_DIR .                     
PRO_FRAME_X_TRAJ:    the index of the "X trajectory" must be filled in 
                     PRO_E_FRM_X_CHOICE_BTN. Not supported. 
*/                  

/************************************************************************/

/************************************************************************/
/* PRO_E_FRM_USER_X */

typedef enum pro_frame_start_x
{
  PRO_FRAME_DEFAULT_START_X  = 0,
  PRO_FRAME_USER_START_X     = (1<<27)  /* user pick start x */
}ProFrameStartX;

/* Relevant only if PRO_E_FRM_ORIENT is PRO_FRAME_MIN.
   If not default, then a direction must be provided in PRO_E_FRM_START_X.
   A direction may be required (default is not available) in some 
   circumstances, such as linear non-sketched trajectory.
*/

/************************************************************************/
/* PRO_E_SWP_SEC_TYPE */

 typedef enum pro_sweep_sec_type
{
  PRO_SWEEP_VARIABLE_SECTION =  0,      /* sweep variable section along the trajectory */
  PRO_SWEEP_CONST_SECTION    = (1<<23) /* sweep constant section along the trajectory */
}ProSweepSecType;

/* Only PRO_SWEEP_CONST_SECTION  supported in Creo Parametric TOOLKIT. */
/************************************************************************/

/************************************************************************/

/************************************************************************/
/* PRO_E_END_SRF_ATTR */

typedef enum pro_sweep_end_srf_attr
{
  PRO_SWEEP_END_SRF_OPEN    =  0,   /* Uncapped surface feature   */
  PRO_SWEEP_END_SRF_CAPPED  =  14   /* Capped ends                */
}ProSweepEndSrfAttr;

/************************************************************************/

/************************************************************************/
/* PRO_E_EXT_SURF_CUT_SOLID_TYPE */

 typedef enum pro_sweep_feat_type
 {
   PRO_SWEEP_FEAT_TYPE_SOLID          =  917, /* Solid Feature   */
   PRO_SWEEP_FEAT_TYPE_SURFACE        =  942  /* Surface Feature */
 } ProSweepFeatType;

/************************************************************************/

/************************************************************************/
/*  PRO_E_REMOVE_MATERIAL */

 typedef enum pro_sweep_rem_material
 {
   PRO_SWEEP_MATERIAL_ADD             = -1,   /* Protruded Feature */
   PRO_SWEEP_MATERIAL_REMOVE          =  916  /* Cut Feature       */
 } ProSweepRemMaterial;

/************************************************************************/
/************************************************************************/
/* PRO_E_FEAT_FORM_IS_THIN */

 typedef enum pro_sweep_feat_form
 {
   PRO_SWEEP_FEAT_FORM_NO_THIN        =  0,  /* "Solid" (not thin) Feature */
   PRO_SWEEP_FEAT_FORM_THIN           =  128 /* Thin  Feature              */
 } ProSweepFeatForm;

/************************************************************************/
/************************************************************************/
/* 4. PRO_E_STD_MATRLSIDE */

 typedef enum pro_sweep_material_side
 {
   PRO_SWEEP_MATERIAL_SIDE_ONE        =  1,  /* Side 1      */
   PRO_SWEEP_MATERIAL_SIDE_TWO        =  2,  /* Side 2      */
   PRO_SWEEP_MATERIAL_BOTH_SIDES      =  3   /* Both sides  */
 } ProSweepMatlSide;

/* Important : PRO_SWEEP_MATERIAL_BOTH_SIDES should be used with Thin and trim
               features only. */

/************************************************************************/

/************************************************************************/


/* PRO_E_TRIM_QLT_SIDE */

 typedef enum pro_sweep_trimqlt_side
 {
   PRO_SWEEP_TRIMQLT_SIDE_ONE         = -1,  /* Side 1 */
   PRO_SWEEP_TRIMQLT_SIDE_TWO         =  1   /* Side 2 */
 } ProSweepTrimQltSide;

/************************************************************************/


/********************** Pre-Creo 1.0 SWEEP **************************

Please Note: This element tree is obsolete from Creo Parametric 1.0 release
             Please use the tree documented at the start of this header file

Feature element tree

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_FEATURE_TYPE
     |   
     |--PRO_E_FEATURE_FORM
     |
     |--PRO_E_SWEEP_SPINE
     |   
     |--PRO_E_SWEEP_SECTION

---------------------------------------------------------------------------------------
Element Id                       Element Name    Data Type                Valid
Values
---------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_PROTRUSION
                                                                       PRO_FEAT_FIRST_FEAT,
                                                                       PRO_FEAT_CUT,
                                                                       PRO_FEAT_SLOT
PRO_E_FEATURE_FORM             Feature Form   PRO_VALUE_TYPE_INT       PRO_SWEEP
PRO_E_SWEEP_SPINE              Trajectory     Compound
PRO_E_SWEEP_SECTION            Section        Compound

 
	PRO_E_SWEEP_SPINE and PRO_E_SWEEP_SECTION use subset element tree
structure of PRO_E_STD_SECTION.

	In Rev. 20 sweep can be created under the default condition, i.e.,

	For solid:   solid not thin.
        For surface: open ends not closed ends.
        

*************************************************************************/

PRO_END_C_DECLS
 
#endif


