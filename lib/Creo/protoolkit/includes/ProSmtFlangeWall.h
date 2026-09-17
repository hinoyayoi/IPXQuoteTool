#ifndef PROSMTFLANGEWALL_H
#define PROSMTFLANGEWALL_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Flange Wall feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :

   PRO_E_FEATURE_TREE
     |   
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_SMT_WALL_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_FLANGE_TYPE
     |
     |--PRO_E_STD_CURVE_COLLECTION_APPL
     |    
     |--PRO_E_SMT_FLANGE_TRAJ_CRV_NORM
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_SMT_WALL_SHARPS_TO_BENDS
     |
     |--PRO_E_SMT_FLANGE_SEC_FLIP
     |
     |--PRO_E_SMT_FLANGE_DEPTH
     |    |
     |    |--PRO_E_SMT_FLANGE_SIDE_1_DEPTH
     |    |    |
     |    |    |--PRO_E_SMT_FLANGE_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_FLANGE_DEPTH_OFFSET
     |    |    |
     |    |    |--PRO_E_SMT_FLANGE_DEPTH_REF
     |    |   
     |    |--PRO_E_SMT_FLANGE_SIDE_2_DEPTH
     |    |    |
     |    |    |--PRO_E_SMT_FLANGE_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_FLANGE_DEPTH_OFFSET
     |    |    |
     |    |    |--PRO_E_SMT_FLANGE_DEPTH_REF
     |
     |--PRO_E_SMT_FILLETS
     |    |
     |    |--PRO_E_SMT_FILLETS_USE_RAD
     |    |
     |    |--PRO_E_SMT_FILLETS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLETS_VALUE
     |
     |--PRO_E_SMT_WALL_HEIGHT
     |    |
     |    |----PRO_E_SMT_WALL_HEIGHT_TYPE
     |    |
     |    |----PRO_E_SMT_WALL_HEIGHT_VALUE
     |
     |--PRO_E_SMT_BEND_RELIEF
     |    |
     |    |--PRO_E_SMT_BEND_RELIEF_SIDE1
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_WIDTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_ANGLE
     |    |
     |    |--PRO_E_SMT_BEND_RELIEF_SIDE2
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_WIDTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH_TYPE
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_DEPTH
     |    |    |
     |    |    |--PRO_E_BEND_RELIEF_ANGLE
     |
     |--PRO_E_SMT_WALL_THICKNESS_FLIP
     |
     |--PRO_E_SMT_CORNER_RELIEF
     |    |
     |    |--PRO_E_SMT_CORNER_RELIEF_TYPE
     |    |
     |    |--PRO_E_SMT_CORNER_RELIEF_WIDTH
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL
     |    |
     |    |--PRO_E_SMT_CORNER_RELIEF_DEPTH
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE
     |    |    |  
     |    |    |--PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL
     |
     |--PRO_E_SMT_MTR_CUTS
     |    |
     |    |--PRO_E_SMT_MTR_CUTS_ADD
     |    |
     |    |--PRO_E_SMT_MTR_CUTS_KEEP_DEF_AREAS
     |    |
     |    |--PRO_E_SMT_MTR_CUTS_WIDTH
     |    |    |  
     |    |    |--PRO_E_SMT_MTR_CUTS_WIDTH_TYPE
     |    |    |  
     |    |    |--PRO_E_SMT_MTR_CUTS_WIDTH_VAL
     |    |
     |    |--PRO_E_SMT_MTR_CUTS_OFFSET
     |    |    |  
     |    |    |--PRO_E_SMT_MTR_CUTS_OFFSET_TYPE
     |    |    |  
     |    |    |--PRO_E_SMT_MTR_CUTS_OFFSET_VAL
     |
     |--PRO_E_SMT_AUTO_EXLD_EDGE
     |
     |--PRO_E_SMT_CORNERS_ARR
     |    |
     |    |--PRO_E_SMT_CORNER
     |    |    |  
     |    |    |--PRO_E_SMT_EDGE_RIP
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_TYPE
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_ADD_GAP
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_CLOSE_CORNER
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_DIM_1
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_1_TYPE
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_1_VAL
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_DIM_2
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_2_TYPE
     |    |    |   |   |
     |    |    |   |   |--PRO_E_SMT_EDGE_RIP_DIM_2_VAL
     |    |    |   |
     |    |    |   |--PRO_E_SMT_EDGE_RIP_FLIP
     |
     |--PRO_E_SMT_DEV_LEN_CALCULATION
     |    |
     |    |--PRO_E_SMT_DEV_LEN_SOURCE
     |    |
     |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR
     |    |    |  
     |    |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE
     |    |    |
     |    |    |--PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE
     |    |
     |    |--PRO_E_SMT_DEV_LEN_BEND_TABLE

************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_TYPE               Wall Type             PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_FLANGE_TYPE             Flange Type           PRO_VALUE_TYPE_INT
PRO_E_STD_CURVE_COLLECTION_APPL   Attachment Edge Chain PRO_VALUE_TYPE_POINTER 
PRO_E_SMT_FLANGE_TRAJ_CRV_NORM    Edge Chain Normal     PRO_VALUE_TYPE_INT
PRO_E_STD_SECTION                 Wall Section          See: ProStdSection.h
PRO_E_SMT_FLANGE_SEC_FLIP         Flip Section Side     PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_SHARPS_TO_BENDS    Convert Sharp Edges 
                                  to Bends              PRO_VALUE_TYPE_INT
PRO_E_SMT_FLANGE_DEPTH            Depth                 Compound
PRO_E_SMT_FLANGE_SIDE_1_DEPTH     Side 1                Compound
PRO_E_SMT_FLANGE_SIDE_2_DEPTH     Side 1                Compound
PRO_E_SMT_FLANGE_DEPTH_TYPE       Depth Type            PRO_VALUE_TYPE_INT 
PRO_E_SMT_FLANGE_DEPTH_OFFSET     Depth Offset          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_FLANGE_DEPTH_REF        Depth Placement Ref   PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_FILLETS                 Fillets               Compound
PRO_E_SMT_FILLETS_USE_RAD         Use Radius            PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_SIDE            Radius Side           PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE           Radius Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_WALL_HEIGHT             Wall Height           Compound
PRO_E_SMT_WALL_HEIGHT_TYPE        Height Type           PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_HEIGHT_VALUE       Height Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_RELIEF             Bend Relief           Compound
PRO_E_SMT_BEND_RELIEF_SIDE1       Side 1 Relief         Compound
PRO_E_SMT_BEND_RELIEF_SIDE2       Side 2 Relief         Compound
PRO_E_BEND_RELIEF_TYPE            Relief Type           PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_WIDTH           Relief Width          PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_DEPTH_TYPE      Relief Depth type     PRO_VALUE_TYPE_INT
							See Note 1.
PRO_E_BEND_RELIEF_DEPTH           Relief Depth value    PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_ANGLE           Relief Angle          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_WALL_THICKNESS_FLIP     Flip Thickness        PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF           Corner Relief               Compound
PRO_E_SMT_CORNER_RELIEF_TYPE      Corner Relief Type          PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_WIDTH     Corner Relief Width         Compound
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE Corner Relief Width Type   PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL  Corner Relief Width Val    PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_CORNER_RELIEF_DEPTH      Corner Relief Depth        Compound
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE Corner Relief Depth Type   PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL  Corner Relief Depth Val    PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_MTR_CUTS                Miter Cuts            Compound
PRO_E_SMT_MTR_CUTS_ADD            Add Miter Cuts        PRO_VALUE_TYPE_INT
PRO_E_SMT_MTR_CUTS_KEEP_DEF_AREAS Keep Deformation Areas      PRO_VALUE_TYPE_INT
PRO_E_SMT_MTR_CUTS_WIDTH          Miter Cuts Width      Compound
PRO_E_SMT_MTR_CUTS_WIDTH_TYPE     Miter Cuts Width Type PRO_VALUE_TYPE_INT
PRO_E_SMT_MTR_CUTS_WIDTH_VAL      Miter Cuts Width Val  PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_MTR_CUTS_OFFSET         Miter Cuts Offset     Compound
PRO_E_SMT_MTR_CUTS_OFFSET_TYPE    Miter Cuts Offset Type PRO_VALUE_TYPE_INT
PRO_E_SMT_MTR_CUTS_OFFSET_VAL     Miter Cuts Offset Val PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_AUTO_EXLD_EDGE          Auto Exclude Edges    PRO_VALUE_TYPE_INT
PRO_E_SMT_CORNERS_ARR             Corners               Array
PRO_E_SMT_CORNER                  Corner                Compound
PRO_E_SMT_EDGE_RIP                Edge Rip              Compound
PRO_E_SMT_EDGE_RIP_TYPE           Edge Rip Type         PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_ADD_GAP        Edge Rip Add Gap      PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER   Edge Rip Close Corner PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_1          Edge Rip Dim 1        Compound
PRO_E_SMT_EDGE_RIP_DIM_1_TYPE     Edge Rip Dim 1 Type   PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_1_VAL      Edge Rip Dim 1 Value  PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_EDGE_RIP_DIM_2          Edge Rip Dim 2        Compound
PRO_E_SMT_EDGE_RIP_DIM_2_TYPE     Edge Rip Dim 2 Type   PRO_VALUE_TYPE_INT
PRO_E_SMT_EDGE_RIP_DIM_2_VAL      Edge Rip Dim 2 Value  PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_EDGE_RIP_FLIP           Edge Rip Flip         PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_CALCULATION     Developed Length      Compound
PRO_E_SMT_DEV_LEN_SOURCE          Dev Length Source     PRO_VALUE_TYPE_INT 
PRO_E_SMT_DEV_LEN_Y_FACTOR        Dev Length Y Factor   Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE  Y Factor Value        PRO_VALUE_TYPE_DOUBLE  
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   Y Factor Type         PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_BEND_TABLE      Dev Length Bend Table PRO_VALUE_TYPE_INT

Note 1.
  The element PRO_E_BEND_RELIEF_DEPTH_TYPE has been added in Creo Parametric.
This element rules the visibility of the bend relief depth element
PRO_E_BEND_RELIEF_DEPTH. The old element PRO_E_BEND_RELIEF_DEPTH will be used
if PRO_E_BEND_RELIEF_DEPTH_TYPE is PRO_BEND_RLF_DEPTH_BLIND or
PRO_BEND_RLF_DEPTH_TYPE_PARAM and part parameter SMT_DFLT_BEND_REL_DEPTH_TYPE
is "Blind". It is recommended to define PRO_E_BEND_RELIEF_DEPTH_TYPE explicitly
for all Creo Parametric TOOLKIT applications. Otherwise the element will be automatically
filled by the default value. The default value in Creo Parametric depends on
the part parameter SMT_DFLT_BEND_REL_DEPTH_TYPE and the configuration option
smt_drive_tools_by_parameters Yes/No. If the value of the option is No,
then the default value will be the last bend relief type, as selected
by the user in the dashboard UI during creation of a new feature.
If the default value is not "Blind", Creo Parametric TOOLKIT applications prior to this
release will not use the element PRO_E_BEND_RELIEF_DEPTH.
To fix it, set PRO_E_BEND_RELIEF_DEPTH_TYPE to PRO_BEND_RLF_DEPTH_BLIND.

================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_WALL
PRO_E_SMT_WALL_TYPE               ProSmtWallWallType
PRO_E_SMT_FLANGE_TYPE             ProFlangeWallType
PRO_E_SMT_FLANGE_TRAJ_CRV_NORM    PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_FLANGE_SEC_FLIP         PRO_B_TRUE, PRO_B_FALSE 
PRO_E_SMT_WALL_SHARPS_TO_BENDS    PRO_B_TRUE, PRO_B_FALSE 
PRO_E_SMT_FLANGE_DEPTH_TYPE       ProWallLenType
PRO_E_SMT_FLANGE_DEPTH_REF        Point, Curve, Plane, Surface 
PRO_E_SMT_FILLETS_USE_RAD         PRO_B_TRUE, PRO_B_FALSE   
PRO_E_SMT_FILLETS_SIDE            ProSmdRadType
PRO_E_SMT_WALL_HEIGHT_TYPE        ProSmdHeightType
PRO_E_BEND_RELIEF_TYPE            ProBendRlfType
PRO_E_BEND_RELIEF_DEPTH_TYPE      ProBendRlfDepthType
PRO_E_SMT_WALL_THICKNESS_FLIP     PRO_B_TRUE, PRO_B_FALSE    
PRO_E_SMT_CORNER_RELIEF_TYPE      ProCornerRelType
PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE ProSmdRelType
PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE ProCornerRlfDepthType
PRO_E_SMT_MTR_CUTS_ADD            PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_MTR_CUTS_KEEP_DEF_AREAS PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_MTR_CUTS_WIDTH_TYPE     ProMiterCutWidthType
PRO_E_SMT_MTR_CUTS_OFFSET_TYPE    ProMiterCutOffsetType
PRO_E_SMT_AUTO_EXLD_EDGE          PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_EDGE_RIP_TYPE           ProEdgeRipType
PRO_E_SMT_EDGE_RIP_ADD_GAP        PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_EDGE_RIP_CLOSE_CORNER   PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_EDGE_RIP_DIM_1_TYPE     ProEdgeRipDimType
PRO_E_SMT_EDGE_RIP_DIM_2_TYPE     ProEdgeRipDimType
PRO_E_SMT_EDGE_RIP_FLIP           PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_DEV_LEN_SOURCE          ProDvlLenSrcType
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   ProDvlLenFactor
PRO_E_SMT_DEV_LEN_BEND_TABLE      int (bend table ID)




================================================================================

************************************************************************/

typedef enum _ProSmtWallWallType
{
  PRO_SMT_WALL_TYPE_EXTEND =  9,
  PRO_SMT_WALL_TYPE_FLANGE =  17,
  PRO_SMT_WALL_TYPE_FLAT   =  20
} ProSmtWallWallType;

typedef enum _ProFlangeWallType
{
  PRO_FLANGE_WALL_TYPE_2D_SWEPT =  1,
  PRO_FLANGE_WALL_TYPE_3D_SWEPT =  2,
  PRO_FLANGE_WALL_TYPE_EXTRUDE  =  3
  
} ProFlangeWallType;

typedef enum _ProFlangeTrajNorm
{
  PRO_FLANGE_TRAJ_NORM_NO_FLIP =  1,
  PRO_FLANGE_TRAJ_NORM_FLIP    = -1
  
} ProFlangeTrajNorm;


typedef enum _ProWallLenTypes
{
  PRO_WALL_LEN_TYPE_NOT_DEFINED     = -1,
  PRO_WALL_LEN_TYPE_NONE            =  0,
  PRO_WALL_LEN_TYPE_BLIND           =  1,
  PRO_WALL_LEN_TYPE_BLIND_SYM       =  2,
  PRO_WALL_LEN_TYPE_TO_REF          =  3,
  PRO_WALL_LEN_TYPE_TO_END          =  4
  
} ProWallLenType;


typedef enum _ProBendRlfType
{   
  PRO_BEND_RLF_NONE        = 0,
  PRO_BEND_RLF_RIP         = 1,
  PRO_BEND_RLF_STRETCH     = 2,
  PRO_BEND_RLF_RECTANGULAR = 3,
  PRO_BEND_RLF_OBROUND     = 4,
  PRO_BEND_RLF_PARAM	   = 5

} ProBendRlfType;

typedef enum _ProDvlLenSrcType
{ 
  PRO_DVL_SRC_NOT_DEFINED           = -1, 
  PRO_DVL_SRC_PART_YF_AND_BTAB      = -2, 
  PRO_DVL_SRC_PART_YF_ONLY          = -3, 
  PRO_DVL_SRC_FEAT_YF_AND_BTAB      = -4, 
  PRO_DVL_SRC_FEAT_BTAB_ONLY        = -5,
  PRO_DVL_SRC_FEAT_YF_ONLY          = -6, 
  PRO_DVL_SRC_USE_ORIGINAL          = -7

} ProDvlLenSrcType;

typedef enum _ProDvlLenFactor
{
  PRO_FACTOR_NOT_DEFINED    = -1,
  PRO_FACTOR_Y              =  0,
  PRO_FACTOR_K              =  1

} ProDvlLenFactor;

typedef enum _ProSmdRadType
{    
  PRO_BEND_RAD_FACE    		= -1,     
  PRO_BEND_RAD_OUTSIDE 		=  0,
  PRO_BEND_RAD_INSIDE  		=  1,
  PRO_BEND_RAD_OFFS    		=  2,   
  PRO_BEND_RAD_NONE    		=  3,    
  PRO_BEND_RAD_NEUTRAL 		=  4,
  PRO_BEND_RAD_PARAMETER	=  5

} ProSmdRadType;

typedef enum _ProSmdHeightType
{    
  PRO_SMT_WALL_HEIGHT_NOT_DEF  = -1,     
  PRO_SMT_WALL_HEIGHT_NONE     =  0,
  PRO_SMT_WALL_HEIGHT_AUTO     =  1,
  PRO_SMT_WALL_HEIGHT_VALUE    =  2, /* Legacy */
  PRO_SMT_WALL_HEIGHT_APP_BEND =  3,
  PRO_SMT_WALL_HEIGHT_OFFSET_FROM_ORIG    =  PRO_SMT_WALL_HEIGHT_VALUE,
  PRO_SMT_WALL_HEIGHT_OFFSET_FROM_BEND    =  4

} ProSmdHeightType;


typedef enum _Pro_corner_relief_type
{
  PRO_CORNER_RELIEF_UNDEFINED	= -1,
  PRO_CORNER_RELIEF_V_NOTCH	=  0,
  PRO_CORNER_RELIEF_CIRCULAR	=  1,
  PRO_CORNER_RELIEF_RECTANGULAR =  2,
  PRO_CORNER_RELIEF_OBROUND	=  3,
  PRO_CORNER_RELIEF_NO		=  5,
  PRO_CORNER_RELIEF_PARAM	=  6

} ProCornerRelType;

typedef enum _Pro_edge_rip_type
{
  PRO_EDGE_RIP_UNDEFINED	= 0,
  PRO_EDGE_RIP_OPEN		= 0x10,
  PRO_EDGE_RIP_BLIND		= 0x20,
  PRO_EDGE_RIP_MITER_CUT	= 0x30,  /* Gap */
  PRO_EDGE_RIP_OVERLAP		= 0x40,
  PRO_EDGE_RIP_PARAM		= 0x50

} ProEdgeRipType;

typedef enum _ProSmdRelType_
{
  PRO_DIM_NOT_USED		= -1,
  PRO_DIM_THICK			= -2,
  PRO_DIM_DOUBLE_THICK		= -3,
  PRO_DIM_ENTER			= -4,
  PRO_DIM_DEF_BEND_RAD		= -5,
  PRO_DIM_UP_TO_BEND		= -7,
  PRO_DIM_TAN_TO_BEND		= -8,
  PRO_DIM_DEF_BEND_ANGLE	= -9,
  PRO_DIM_DEF_CRN_REL_WIDTH	= -10, /* only for 
					  PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE */
  PRO_DIM_DEF_CRN_REL_DEPTH	= -11, /* only for 
					  PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE */
  PRO_DIM_DEF_BEND_REL_WIDTH	= -12,
  PRO_DIM_DEF_BEND_REL_DEPTH	= -13,
  PRO_DIM_DEF_BEND_REL_ANGLE	= -14,
  PRO_DIM_MINUS_THICK		= -15,
  PRO_DIM_MINUS_DOUBLE_THICK	= -16,
  PRO_DIM_DFLT_EDGE_TREA_WIDTH	= -17, /* only for 
					   PRO_E_SMT_EDGE_RIP_DIM_1_TYPE/2_TYPE */
  PRO_DIM_DFLT_MITER_CUT_WIDTH	= -18, /* only for 
					  PRO_E_SMT_MTR_CUTS_WIDTH_TYPE */
  PRO_DIM_DFLT_MITER_CUT_OFFSET	= -19, /* only for 
					  PRO_E_SMT_MTR_CUTS_OFFSET_TYPE */
  PRO_DIM_THICK_1_1		= -20,
  PRO_DIM_THICK_05		= -21,
  PRO_DIM_SMT_GAP		= -22,
  PRO_DIM_MINUS_THICK_05	= -23,
  PRO_DIM_CRN_RLF_DEPTH_TYPE    = -24,
  PRO_DIM_BEND_RLF_DEPTH_TYPE   = -25,
  PRO_DIM_MINUS_SMT_GAP         = -26,
  PRO_DIM_THICK_6		= -27,
  PRO_DIM_THICK_12		= -28,
  PRO_DIM_THICK_24		= -29

} ProSmdRelType;


typedef enum _ProCornerRlfDepthType_
{
  PRO_CRN_RLF_DEPTH_BLIND	= PRO_DIM_ENTER,
  PRO_CRN_RLF_DEPTH_UP_TO_BEND	= PRO_DIM_UP_TO_BEND,
  PRO_CRN_RLF_DEPTH_TAN_TO_BEND	= PRO_DIM_TAN_TO_BEND,
  PRO_CRN_RLF_DEPTH_TYPE_PARAM	= PRO_DIM_CRN_RLF_DEPTH_TYPE

} ProCornerRlfDepthType;


typedef enum _ProBendRlfDepthType_
{
  PRO_BEND_RLF_DEPTH_NOT_USED       = PRO_DIM_NOT_USED,
  PRO_BEND_RLF_DEPTH_BLIND          = PRO_DIM_ENTER,
  PRO_BEND_RLF_DEPTH_UP_TO_BEND     = PRO_DIM_UP_TO_BEND,
  PRO_BEND_RLF_DEPTH_TAN_TO_BEND    = PRO_DIM_TAN_TO_BEND,
  PRO_BEND_RLF_DEPTH_TYPE_PARAM	    = PRO_DIM_BEND_RLF_DEPTH_TYPE

} ProBendRlfDepthType;


typedef enum _ProMiterCutWidthType_
{
  PRO_MITER_CUT_WIDTH_TYPE_BLIND    = PRO_DIM_ENTER,
  PRO_MITER_CUT_WIDTH_TYPE_GAP      = PRO_DIM_SMT_GAP,
  PRO_MITER_CUT_WIDTH_TYPE_PARAM    = PRO_DIM_DFLT_MITER_CUT_WIDTH

} ProMiterCutWidthType;


typedef enum _ProMiterCutOffsetType_
{
  PRO_MITER_CUT_OFFSET_TYPE_BLIND   = PRO_DIM_ENTER,
  PRO_MITER_CUT_OFFSET_TYPE_GAP     = PRO_DIM_SMT_GAP,
  PRO_MITER_CUT_OFFSET_TYPE_PARAM   = PRO_DIM_DFLT_MITER_CUT_OFFSET

} ProMiterCutOffsetType;


typedef enum _ProEdgeRipDimType_
{
  PRO_EDGE_RIP_DIM_TYPE_BLIND   = PRO_DIM_ENTER,
  PRO_EDGE_RIP_DIM_TYPE_GAP     = PRO_DIM_SMT_GAP,
  PRO_EDGE_RIP_DIM_TYPE_PARAM   = PRO_DIM_DFLT_EDGE_TREA_WIDTH

} ProEdgeRipDimType;








PRO_END_C_DECLS

#endif

