#ifndef PROMFGOPTIONS_H
#define PROMFGOPTIONS_H
/*
   Creo Parametric TOOLKIT declarations of manufacturing options.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

typedef enum pro_ncseq_type
{
 PRO_NCSEQ_PROF_SURF_MILL          = 1,
 PRO_NCSEQ_VOL_MILL                = 2,
 PRO_NCSEQ_CONV_SURF_MILL          = 3,
 PRO_NCSEQ_FACE_MILL               = 4,
 PRO_NCSEQ_HOLEMAKING              = 5,
 PRO_NCSEQ_PREV_TOOL_MILL          = 6,        
 PRO_NCSEQ_TRAJ_MILL               = 7,
 PRO_NCSEQ_AREA_TURN               = 8,
 PRO_NCSEQ_4X_AREA_TURN            = 9,
 PRO_NCSEQ_GROOVE_TURN             = 10,
 PRO_NCSEQ_TRAJ_TURN               = 11,
 PRO_NCSEQ_THREAD_TURN             = 12,
 PRO_NCSEQ_CONTOUR_MILL            = 13,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_PENCIL_TRACING_MILL     = 14,
 PRO_NCSEQ_PROF_TURN               = 15,
 PRO_NCSEQ_THREAD_MILL             = 16,
 PRO_NCSEQ_POCKET_MILL             = 17,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_PLUNGE_MILL             = 18,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_LOCAL_PREV_SEQ          = 19,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_LOCAL_CORNER_EDGE       = 20,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_LOCAL_PENCIL_TRACING    = 21,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_CUTLINE_MILL            = 22,
 PRO_NCSEQ_LOC_SURF_MILL           = 23,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_HUB_MILL                = 24,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_ENC_ROUGH_MILL          = 25,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_GROOVE_MILL             = 26,
 PRO_NCSEQ_ROUGHVOL_MILL           = 27,
 PRO_NCSEQ_REROUGH_MILL            = 28,
 PRO_NCSEQ_FF_TRAJ_MILL            = 29,
 PRO_NCSEQ_MIRROR_MILL             = 30,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_MANUAL_CYCLE_MILL       = 31,
 PRO_NCSEQ_TRAJ_MILL_STEP          = 32,
 PRO_NCSEQ_AUXILIARY_ON_TURN       = 33,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_AUXILIARY_ON_MILL       = 34,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_AUXILIARY_ON_DRILL      = 35,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_AUXILIARY_ON_SAW        = 36,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_AUXILIARY_ON_PUNCH      = 37,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_AUXILIARY_ON_MEAS       = 38,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_CVNC_CORN_MILL          = 39,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_CVNC_FINISH_MILL        = 40,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_FLOWLINE_MILL           = 41,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_PTM_RESTFIN_MILL        = 42,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_SWARF_MILL              = 43,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_ROUND_MILL              = 44,
 PRO_NCSEQ_CHAMFER_MILL            = 45,
 PRO_NCSEQ_MANUAL_CYCLE_TURN       = 46,
 PRO_NCSEQ_WEDM_DESTRUCT           = 47,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_WEDM_UV_TYPE            = 48,   /* NOT IMPLEMENTED */
 PRO_NCSEQ_WEDM_TAPER              = 49    /* NOT IMPLEMENTED */
} ProNcseqType;


typedef enum Pro_MfgToolHeadType
{
  PRO_MFG_TOOL_HEAD_UNDEF = -1,
  PRO_MFG_TOOL_HEAD_1     =  1,
  PRO_MFG_TOOL_HEAD_2     =  2,
  PRO_MFG_TOOL_HEAD_3     =  3,
  PRO_MFG_TOOL_HEAD_4     =  4,
  PRO_MFG_TOOL_HEAD_CMM   =  11 
}  ProMfgToolHeadType;

typedef enum Pro_MfgParamAttr
{
  PRO_MFG_PRM_ATTR_DEFAULT      = 1,
  PRO_MFG_PRM_ATTR_MODIFIED     = 2,
  PRO_MFG_PRM_ATTR_INHERITED    = 3,
  PRO_MFG_PRM_ATTR_AUTOMATIC    = 4

} ProMfgParamAttr;

typedef enum Pro_DrillModOption
{
 PRO_DRILL_HOLE_ON_MILL  = 0, /* drilling by rotating tool */
 PRO_DRILL_HOLE_ON_LATHE = 1  /* drilling with rotating part */

} ProDrillModeOption;

typedef enum  Pro_HolemakingType  
{
  PRO_HOLE_MK_CSINK  = 2,
  PRO_HOLE_MK_DRILL  = 4,
  PRO_HOLE_MK_BORE   = 6,
  PRO_HOLE_MK_TAP    = 7,
  PRO_HOLE_MK_FACE   = 9,
  PRO_HOLE_MK_REAM   = 10,
  PRO_HOLE_MK_CUSTOM = 13,
  PRO_HOLE_MK_WEB    = 15

}  ProHolemakingType;

typedef enum  Pro_HmCycleType  
{
  PRO_HM_CYCLE_TYPE_STANDARD     = 1,
  PRO_HM_CYCLE_TYPE_PECK_CONST   = 2,
  PRO_HM_CYCLE_TYPE_PECK_VAR     = 3,
  PRO_HM_CYCLE_TYPE_BREAKCHIP    = 4,
  PRO_HM_CYCLE_TYPE_TAP_FIXED    = 5,
  PRO_HM_CYCLE_TYPE_TAP_FLOAT    = 6,
  PRO_HM_CYCLE_TYPE_BACK         = 7

}  ProHmCycleType;

typedef enum Pro_HolesetType  
{
  PRO_HOLESET_DRILL_AXES   = 4,
  PRO_HOLESET_DRILL_POINTS = 5,
  PRO_HOLESET_DRILL_GEOM   = 6

}  ProHolesetType;

typedef enum Pro_DrillStartType
{
  PRO_DRILL_FROM_SURFACE    = 1,
  PRO_DRILL_AUTO_START      = 2,
  PRO_DRILL_START_OFFSET_FROM_CSYS	= 3

}  ProDrillStartType;

typedef enum Pro_DrillEndType
{
  PRO_DRILL_UPTO_SURFACE        = 1,
  PRO_DRILL_THRU_ALL_PARTS      = 2,
  PRO_DRILL_AUTO_END            = 3,
  PRO_DRILL_OFFSET_FROM_START   = 4,
  PRO_DRILL_END_OFFSET_FROM_CSYS	= 5 

}  ProDrillEndType;

typedef enum Pro_DrillDepthByType  
{
  PRO_DRILL_BY_SHOULDER = 1,
  PRO_DRILL_BY_TIP      = 2

}  ProDrillDepthByType;

typedef enum Pro_DrillDepthType
{
  PRO_DRILL_BLIND    = 5,
  PRO_DRILL_THRU_ALL = 58,
  PRO_DRILL_AUTO     = 172

}  ProDrillDepthType;

typedef enum Pro_CustomRefOption
{
  PRO_CUSTOM_DRILL_SELECT_REFERENCE     = 1,
  PRO_CUSTOM_DRILL_OFFSET_FROM_START    = 2,
  PRO_CUSTOM_DRILL_OFFSET_FROM_CSYS	= 3

}  ProCustomRefOption;

typedef enum Pro_HolesetParamOper
{
  PRO_DRILL_QUERY_EQUAL         = 1,
  PRO_DRILL_QUERY_NOT_EQUAL     = 2,
  PRO_DRILL_QUERY_LARGER        = 3,
  PRO_DRILL_QUERY_SMALLER       = 4

}  ProDrillParamOper;

typedef enum Pro_HolesetOrientType
{
  PRO_DRILL_ORIENT_TO_REF       = 1,
  PRO_DRILL_ORIENT_FROM_REF     = 2

}  ProDrillOrientType;

typedef enum Pro_MillThreadType  
{
  PRO_E_MILL_THREAD_EXTERNAL   = 1,
  PRO_E_MILL_THREAD_INTERNAL   = 2

}  ProMillThreadType;

typedef enum Pro_WcellNumAxes
{
  PRO_WCELL_2_AXIS = 2,
  PRO_WCELL_3_AXIS = 3,
  PRO_WCELL_4_AXIS = 4,
  PRO_WCELL_5_AXIS = 5
} ProWcellNumAxes;

typedef enum Pro_MfgWcellNumSpindles
{
  PRO_MFG_ONE_SPINDLE_WCELL  = 1,
  PRO_MFG_TWO_SPINDLE_WCELL  = 2

}  ProMfgWcellNumSpindles;

typedef enum Pro_MfgWcellNumHeads
{
  PRO_MFG_ONE_HEAD_WCELL   = 1,
  PRO_MFG_TWO_HEAD_WCELL   = 2,
  PRO_MFG_THREE_HEAD_WCELL = 3,
  PRO_MFG_FOUR_HEAD_WCELL  = 4

}  ProMfgWcellNumHeads;

typedef enum Pro_WcellLatheDir
{
  PRO_WCELL_LATHE_HORIZONTAL = 0,
  PRO_WCELL_LATHE_VERTICAL   = 1

} ProWcellLatheDir;

typedef enum pro_retr_surf_type  
{
   PRO_RETR_SURF_UNDEFINED =  -1,
   PRO_RETR_SURF_PLANE     =   0,
   PRO_RETR_SURF_CYLINDER  =   1,
   PRO_RETR_SURF_SPHERE    =   2,
   PRO_RETR_SURF_REVOLVED  =   3

}  ProRetrSurfType;

typedef enum pro_retr_surf_orient 
{
   PRO_RETR_SURF_X_DIR  =  0,
   PRO_RETR_SURF_Y_DIR  =  1,
   PRO_RETR_SURF_Z_DIR  =  2

} ProRetrSurfOrient;

typedef enum Pro_TurnOptionType  
{
  PRO_E_TURN_OPTION_OUT        = 0,
  PRO_E_TURN_OPTION_IN         = 1,
  PRO_E_TURN_OPTION_FACE       = 2
}  ProTurnOptionType;

typedef enum Pro_TurnThreadOutputType  
{
  PRO_E_TURN_THREAD_ISO        = 0,
  PRO_E_TURN_THREAD_AI_MACRO   = 1
} ProTurnThreadOutputType;

typedef enum Pro_TurnThreadType  
{
  PRO_E_TURN_THREAD_GENERAL        = 0,
  PRO_E_TURN_THREAD_UNIFIED        = 1,
  PRO_E_TURN_THREAD_BUTTRESS       = 2,
  PRO_E_TURN_THREAD_ACME           = 3

}  ProTurnThreadType;

typedef enum Pro_MillThreadTaperType  
{
  PRO_E_MILL_THREAD_TAPER_NONE        = 0,
  PRO_E_MILL_THREAD_TAPER_NPT         = 1,
  PRO_E_MILL_THREAD_TAPER_CUSTOM      = 2

}  ProMillThreadTaperType;

typedef enum Pro_HolesetDiamType  
{
  PRO_HSET_ALL_DIAMS      = 1,
  PRO_HSET_HOLE_DIAMS     = 2,
  PRO_HSET_THREAD_DIAMS   = 3

}  ProHolesetDiamType;

typedef enum Pro_HsetParamRuleOpt  
{
  PRO_HSET_BOOL_OPER_OR    = 1,
  PRO_HSET_BOOL_OPER_AND   = 2

}  ProHsetParamRuleOpt;

typedef enum Pro_ToolMtnFeedType  
{
  PRO_TM_FEED_FREE         = 1,
  PRO_TM_FEED_CUT          = 2,
  PRO_TM_FEED_PLUNGE       = 3,
  PRO_TM_FEED_RETRACT      = 4,
  PRO_TM_FEED_APPROACH     = 5,
  PRO_TM_FEED_EXIT         = 6

}  ProToolMtnFeedType;

typedef enum pro_tm_type {
   PRO_TM_TYPE_UNDEFINED         =-1,
   PRO_TM_TYPE_GOTO_POINT        = 0,
   PRO_TM_TYPE_GO_DELTA          = 1,
   PRO_TM_TYPE_CL_COMMAND        = 2,
   PRO_TM_TYPE_FOLLOW_CURVE      = 3,
   PRO_TM_TYPE_GOTO_SURFACE      = 4,
   PRO_TM_TYPE_GOTO_AXIS         = 5,
   PRO_TM_TYPE_GOHOME            = 6,
   PRO_TM_TYPE_PLUNGE            = 7,
   PRO_TM_TYPE_AUTO_PLUNGE       = 8,
   PRO_TM_TYPE_GO_RETRACT        = 9,
   PRO_TM_TYPE_TANGENT_APPROACH  = 10,
   PRO_TM_TYPE_TANGENT_EXIT      = 11,
   PRO_TM_TYPE_NORMAL_APPROACH   = 12,
   PRO_TM_TYPE_NORMAL_EXIT       = 13,
   PRO_TM_TYPE_LEAD_IN           = 14,
   PRO_TM_TYPE_LEAD_OUT          = 15,
   PRO_TM_TYPE_HELICAL_APPROACH  = 16,
   PRO_TM_TYPE_HELICAL_EXIT      = 17,
   PRO_TM_TYPE_AREA_TURNING      = 18,
   PRO_TM_TYPE_GROOVE_TURNING    = 19,
   PRO_TM_TYPE_PROF_TURNING      = 20,
   PRO_TM_TYPE_FULL_DEPTH_CUT    = 21,
   PRO_TM_TYPE_FROM_TO_DEPTH_CUT = 22,
   PRO_TM_TYPE_TO_DEPTH_CUT      = 23,
   PRO_TM_TYPE_ONE_SLICE_CUT     = 24,
   PRO_TM_TYPE_CURVE_TRAJECTORY  = 25,
   PRO_TM_TYPE_SURF_TRAJECTORY   = 26,
   PRO_TM_TYPE_EDGE_TRAJECTORY   = 27,
   PRO_TM_TYPE_AUTOMATIC_CUT     = 28,
   PRO_TM_TYPE_TRIM              = 29,
   PRO_TM_TYPE_CUTLINE_MILLING   = 30,
   PRO_TM_TYPE_GROOVE_MILLING    = 31,
   PRO_TM_TYPE_FACE_MILLING      = 32,
   PRO_TM_TYPE_THREAD_MILLING    = 33,
   PRO_TM_TYPE_PROFILE_MILL_CUT  = 34,
   PRO_TM_TYPE_ALONG_AXIS_APPROACH = 35,
   PRO_TM_TYPE_ALONG_AXIS_EXIT   = 36,
   PRO_TM_TYPE_RAMP_APPROACH     = 37,
   PRO_TM_TYPE_RAMP_EXIT         = 38,
   PRO_TM_TYPE_CONNECT           = 39,
   PRO_TM_TYPE_ROUND_MILLING     = 40,
   PRO_TM_TYPE_CHAMFER_MILLING   = 41,
   PRO_TM_TYPE_ROUGH_MILL	 = 42,
   PRO_TM_TYPE_REROUGH_MILL 	 = 43,
   PRO_TM_TYPE_CVNC_CORN_MILL	 = 44,
   PRO_TM_TYPE_CVNC_FINISH_MILL  = 45,
   PRO_TM_TYPE_2X_TRAJ_MILL	 = 46,
   PRO_TM_TYPE_THREAD_TURN	 = 47,
   PRO_TM_TYPE_PTM_RESTFIN_MILL  = 48,
   PRO_TM_TYPE_LOCAL_PENCIL_TRACING = 49,
   PRO_TM_TYPE_LOCAL_CORNER_EDGE    = 50,
   PRO_TM_TYPE_LOCAL_PREV_SEQ    = 51,
   PRO_TM_TYPE_LOCAL_PREV_TOOL_MILL    = 52,
   PRO_TM_TYPE_VOLUME_MILLING    = 53,
   PRO_TM_TYPE_CONV_SURF_MILL    = 54

} ProTmType;
   
typedef enum pro_mfg_crv_dir {
   PRO_MFG_DIR_OPPOSITE = -1,
   PRO_MFG_DIR_SAME     =  1
} ProMfgCrvDir;
      
typedef enum pro_tm_side_dir {
   PRO_TM_DIR_LEFT_SIDE = -1,
   PRO_TM_DIR_RIGHT_SIDE = 1
} ProTmSideDir;

typedef enum pro_mfg_surf_ref_type 
{
   PRO_SURF_REF_TYPE_NONE          =  0,
   PRO_SURF_REF_TYPE_REFPART       =  1,
   PRO_SURF_REF_TYPE_WORKPIECE     =  2,
   PRO_SURF_REF_TYPE_MILL_VOLUME   =  3,
   PRO_SURF_REF_TYPE_MILL_MVOLSRF  =  4,
   PRO_SURF_REF_TYPE_PREV_STEP     =  5,
   PRO_SURF_REF_TYPE_MILL_WINDOW   =  6,
   PRO_SURF_REF_TYPE_TOP_ASSEM_SRF =  7

} ProMfgSurfRefType;

typedef enum Pro_curve_point_offset_type
{
  PRO_CURVE_POINT_OFFSET_TYPE_RATIO = 0,
  PRO_CURVE_POINT_OFFSET_TYPE_REAL  = 1 

}  ProCurvePointOffsetType;

typedef enum Pro_mach_surf_ref_type
{
  PRO_MACH_SURF_OPT_SURFACES    = 1,
  PRO_MACH_SURF_OPT_MILL_WIND   = 2,
  PRO_MACH_SURF_OPT_PREV_STEP   = 3

}  ProMachSurfRefType;
  
typedef enum pro_cl_cmd_loc_type
{
   PRO_CL_CMD_LOC_TYPE_SEL        = 1,
   PRO_CL_CMD_LOC_TYPE_BEGIN      = 2,
   PRO_CL_CMD_LOC_TYPE_CURR       = 4,
   PRO_CL_CMD_LOC_TYPE_DTM_PNT    = 10,
   PRO_CL_CMD_LOC_TYPE_ON_SURFACE = 11

} ProClCmdLocType;
      
typedef enum pro_cl_cmd_srf_opt
{
   PRO_CL_COMMAND_ON_FIRST_PASS = 0,
   PRO_CL_COMMAND_ON_LAST_PASS  = 1,
   PRO_CL_COMMAND_ON_ALL_PASSES = 2

} ProClCmdSrfOpt;    
      
typedef enum pro_tm_turn_corner_type {
   PRO_TM_TURN_CORNER_TYPE_SHARP   = 0,
   PRO_TM_TURN_CORNER_TYPE_FILLET  = 1,
   PRO_TM_TURN_CORNER_TYPE_CHAMFER = 2
} ProTmTurnCornerType;

typedef enum pro_tm_trim_val_opt {
   PRO_TM_TRIM_VAL_PARAM = 0,
   PRO_TM_TRIM_VAL_DIST = 1
} ProTmTrimValOpt;

typedef enum pro_tm_turn_orient {
   PRO_TM_TURN_CSYS_X = 0,
   PRO_TM_TURN_CSYS_Y = 1,
   PRO_TM_TURN_CSYS_Z = 2
} ProTmTurnOrient;

typedef enum Pro_MachHead
{
  PRO_MACH_HEAD_NONE = -1,
  PRO_MACH_HEAD1     =  1,    /* refers to machining head 1               */
  PRO_MACH_HEAD2     =  2,    /* refers to machining head 2               */
  PRO_MACH_HEAD3     =  3, 
  PRO_MACH_HEAD4     =  4,
  PRO_MACH_HEAD_CMM  =  11    /* refers to inprocess cmm probing          */
                              
} ProMachHead;

typedef enum Pro_WcellType
{
  PRO_WCELL_NONE       = 0,
  PRO_WCELL_LATHE      = 2,     /* a Lathe Workcell                          */
  PRO_WCELL_MILL       = 4,     /* a Mill Workcell                           */
  PRO_WCELL_MILL_N_TRN = 8,     /* a Mill/Turn Workcell                      */
  PRO_WCELL_WEDM       = 16,    /* a Wire-EDM Workcell                       */
  PRO_WCELL_HOLEMAKING = 32,    /* a Holemaking Workcell                     */
  PRO_WCELL_PUNCH      = 64,    /* a Punch Workcell                          */
  PRO_WCELL_HYBRID     = 128,   /* a Laser & Punch Workcell                  */
  PRO_WCELL_CMM        = 256,   /* a CMM Workcell                            */
  PRO_WCELL_SURFACE    = 512,   /* a Grinding/Plating Workcell (ref: PPFM)   */
  PRO_WCELL_VOLUME     = 1024,  /* a Heat treating Workcell (ref: PPFM)      */
  PRO_WCELL_GENERAL    = 2048   /* for misc. operations such as painting     */
} ProWcellType;

typedef enum Pro_MaterialRmvSide
{
  PRO_MAT_RMV_LEFT     = 0,  /* Material to remove on left  */
  PRO_MAT_RMV_RIGHT    = 1   /* Material to remove on right */

} ProMaterialRmvSide;

typedef enum pro_tm_tool_axis_opt {
   PRO_TM_ALONG_Z  = 0,
   PRO_TM_USE_PREV = 1,
   PRO_TM_AXIS_SEL = 2
} ProTmToolAxisOpt;

typedef enum pro_cutline_sync_type_opt 
{
   PRO_CUTLINE_SYNC_TYPE_POINTS  = 0,
   PRO_CUTLINE_SYNC_TYPE_REF     = 1

} ProCutlineSyncTypeOpt;

typedef enum Pro_FixtureType
{
  PRO_E_FIXTURE_TYPE_OPER_DEFAULT  = 1,
  PRO_E_FIXTURE_TYPE_INPROCESS     = 2

}  ProFixtureType;

typedef enum Pro_AxisDefType
{
  PRO_AXIS_DEF_TYPE_UNDEF        = -1, 
  PRO_AXIS_DEF_BY_PIVOT_REF      = 0,
  PRO_AXIS_DEF_BY_LOCATIONS      = 1,
  PRO_AXIS_DEF_BY_TWO_CONTOURS   = 2,
  PRO_AXIS_DEF_BY_NORM_SURF      = 3,
  PRO_AXIS_DEF_BY_DRIVE_SURF     = 4

} ProAxisDefType;

typedef enum Pro_AxisDefLocOrientType
{
  PRO_AXIS_DEF_LOC_ORIENT_BY_REFERENCE  = 1,
  PRO_AXIS_DEF_LOC_ORIENT_BY_ANGLE      = 2

}  ProAxisDefLocOrientType;

typedef enum Pro_SubSpindleOpt
{
  PRO_MFG_MAIN_SPINDLE     = 1,
  PRO_MFG_SUB_SPINDLE      = 2

}  ProSubSpindleOpt;

typedef enum pro_tm_traj_corner_type {
   PRO_TM_TRAJ_CORNER_TYPE_SHARP    = 0,
   PRO_TM_TRAJ_CORNER_TYPE_FILLET   = 1,
   PRO_TM_TRAJ_CORNER_TYPE_CHAMFER  = 2,
   PRO_TM_TRAJ_CORNER_TYPE_LOOP     = 3,
   PRO_TM_TRAJ_CORNER_TYPE_STRAIGHT = 4
} ProTmTrajCornerType;

typedef enum Pro_MillProfCutType 
{
  PRO_E_MILL_CUT_FULL_DEPTH       = 1,
  PRO_E_MILL_CUT_FROM_TO          = 2,
  PRO_E_MILL_CUT_UPTO             = 3,
  PRO_E_MILL_CUT_ONE_SLICE        = 4

} ProMillProfCutType;
   
typedef enum pro_vol_mill_ap_ex_type {
   PRO_VOL_MILL_APPROACH = 0,
   PRO_VOL_MILL_EXIT     = 1
} ProVolMillApExType;

typedef enum pro_conv_cut_dir_opt {
   PRO_CNVTL_CUT_DIR_ANGLE        = 1,
   PRO_CNVTL_CUT_DIR_REF          = 2
} ProConvCutDirOpt;
   
PRO_END_C_DECLS

#endif /*PROMFGOPTIONS_H*/
