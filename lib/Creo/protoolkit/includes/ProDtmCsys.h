#ifndef PROCSYSH
#define PROCSYSH



#include <ProToolkit.h>
#include <ProElement.h>

PRO_BEGIN_C_DECLS

/*
 
PRO_E_FEATURE_TREE 
      | 
      |--PRO_E_FEATURE_TYPE 
      |
      |--PRO_E_STD_FEATURE_NAME
      |
      |--PRO_E_CSYS_ORIGIN_CONSTRS                   Array of origin constraints 
      |      |--PRO_E_CSYS_ORIGIN_CONSTR 
      |           |--PRO_E_CSYS_ORIGIN_CONSTR_REF 
      |
      |--PRO_E_CSYS_OFFSET_TYPE
      |
      |--PRO_E_CSYS_ONSURF_TYPE
      |
      |--PRO_E_CSYS_DIM_CONSTRS
      |     |--PRO_E_CSYS_DIM_CONSTR
      |          |--PRO_E_CSYS_DIM_CONSTR_REF
      |          |--PRO_E_CSYS_DIM_CONSTR_TYPE
      |          |--PRO_E_CSYS_DIM_CONSTR_VAL                         
      |
      |--PRO_E_CSYS_ORIENTMOVES                      Array of orientation constraints 
      |     |--PRO_E_CSYS_ORIENTMOVE 
      |         |--PRO_E_CSYS_ORIENTMOVE_MOVE_TYPE
      |         |--PRO_E_CSYS_ORIENTMOVE_MOVE_VAL
      |
      |--PRO_E_CSYS_NORMAL_TO_SCREEN
      |
      |--PRO_E_CSYS_ORIENT_BY_METHOD
      |
      |--PRO_E_CSYS_ORIENTSELAXIS1_REF               Orientation direction 1 reference     
      |--PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT           To use csys origin, x, y, or z axis 
      |--PRO_E_CSYS_ORIENTSELAXIS1_OPT               Axis option of direction 1 reference 
      |--PRO_E_CSYS_ORIENTSELAXIS1_FLIP 
      |--PRO_E_CSYS_ORIENTSELAXIS2_REF               Orientation direction 2 reference 
      |--PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT           To use csys origin, x, y, z or axis 
      |--PRO_E_CSYS_ORIENTSELAXIS2_OPT               Axis option of direction 2 reference 
      |--PRO_E_CSYS_ORIENTSELAXIS2_FLIP
      |--PRO_E_CSYS_ORIENTSELAXIS2_ROT_OPT           Rotation angle option about the First Axis
      |--PRO_E_CSYS_ORIENTSELAXIS2_ROT               Rotation angle about the First Axis 
      |
      |--PRO_E_CSYS_TYPE_MECH                        csys type in Creo Simulate environment ( ONLY )
      |--PRO_E_CSYS_FOLLOW_SRF_OPT                   csys follow option in sheetmetal environment ( ONLY )
      |
      |--PRO_E_CSYS_NAME_DISPLAY_OPT                 Csys name display option ( yes/no )
      |--PRO_E_CSYS_DISPLAY_ZOOM_DEP_OPT             Csys display zoom dependent option ( yes/no )
      |--PRO_E_CSYS_AXIS_LENGTH                      Csys axis length

3. Feature elements table 
-------------------------------------------------------------------------------------------- ----------------
Element Id                            Element Name                  Data Type                  Valid Values 
-------------------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                    Feature Type                  PRO_VALUE_TYPE_INT         PRO_FEAT_CSYS  
PRO_E_STD_FEATURE_NAME                Feature Name                  PRO_VALUE_TYPE_WSTRING
PRO_E_CSYS_ORIGIN_CONSTRS             Origin Constraints            Array 
PRO_E_CSYS_ORIGIN_CONSTR              Compound 
PRO_E_CSYS_ORIGIN_CONSTR_REF          Origin Reference              PRO_VALUE_TYPE_SELECTION   
PRO_E_CSYS_OFFSET_TYPE                Origin Offset Type            PRO_VALUE_TYPE_INT         ProCsysOffsetType
PRO_E_CSYS_ONSURF_TYPE                Onsurf Type                   PRO_VALUE_TYPE_INT         ProCsysOnSurfType
PRO_E_CSYS_DIM_CONSTRS                Dim Constraints               Array
PRO_E_CSYS_DIM_CONSTR                                               Compound
PRO_E_CSYS_DIM_CONSTR_REF             Dim Constraint Reference      PRO_VALUE_TYPE_SELECTION  
PRO_E_CSYS_DIM_CONSTR_TYPE            Dim Constraint Type           PRO_VALUE_TYPE_INT         ProCsysDimConstrType
PRO_E_CSYS_DIM_CONSTR_VAL             Dim Constraint Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_CSYS_ORIENTMOVES                Orientation Moves             Array 
PRO_E_CSYS_ORIENTMOVE                                               Compound 
PRO_E_CSYS_ORIENTMOVE_MOVE_TYPE       Move Type                     PRO_VALUE_TYPE_INT         ProCsysOrientMoveMoveOpt 
PRO_E_CSYS_ORIENTMOVE_MOVE_VAL        Move Value                    PRO_VALUE_TYPE_DOUBLE 
PRO_E_CSYS_NORMAL_TO_SCREEN           Set Z Normal To Screen        PRO_VALUE_TYPE_INT         ProCsysOrientMovesNrmScrnOpt
PRO_E_CSYS_ORIENT_BY_METHOD           Orient By Method              PRO_VALUE_TYPE_INT         ProCsysOrientByMethod
PRO_E_CSYS_ORIENTSELAXIS1_REF         First Axis Reference          PRO_VALUE_TYPE_SELECTION   
PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT     First Axis Ref Option         PRO_VALUE_TYPE_INT         ProCsysDirCsysRefOpt 
PRO_E_CSYS_ORIENTSELAXIS1_OPT         First Axis Option             PRO_VALUE_TYPE_INT         ProCsysOrientMoveAxisOpt 
PRO_E_CSYS_ORIENTSELAXIS1_FLIP        Flip first direction    
PRO_E_CSYS_ORIENTSELAXIS2_REF         Second Axis Reference         PRO_VALUE_TYPE_SELECTION   
PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT     Second Axis Ref Option        PRO_VALUE_TYPE_INT         ProCsysDirCsysRefOpt 
PRO_E_CSYS_ORIENTSELAXIS2_OPT         Second Axis Option            PRO_VALUE_TYPE_INT         ProCsysOrientMoveAxisOpt 
PRO_E_CSYS_ORIENTSELAXIS2_FLIP        Flip second direction
                                                                                               Axisopt1 != AxisOpt2
PRO_E_CSYS_ORIENTSELAXIS2_ROT_OPT     Second Axis Rotation Opt      PRO_VALUE_TYPE_INT         ProCsysOrientSelAxisRotOpt
PRO_E_CSYS_ORIENTSELAXIS2_ROT         Second Axis Rotation          PRO_VALUE_TYPE_DOUBLE     
PRO_E_CSYS_TYPE_MECH                  Csys type in Creo Simulate    PRO_VALUE_TYPE_INT         ProCsysType 
PRO_E_CSYS_FOLLOW_SRF_OPT             Csys smt follow option        PRO_ELEM_TYPE_OPTION       ProCsysFollowSrfOpt
PRO_E_CSYS_NAME_DISPLAY_OPT           Name Display Option           PRO_VALUE_TYPE_INT         ProCsysNameDisplayOpt
PRO_E_CSYS_AXIS_LENGTH                Axis Length                   PRO_VALUE_TYPE_DOUBLE
PRO_E_CSYS_DISPLAY_ZOOM_DEP_OPT       Display Zoom Dependent Option PRO_VALUE_TYPE_INT         ProCsysDisplayZoomDepOpt
*/

/* Table Csys:1 : Common elements for all cases and their values
---------------------------------------------------------------------------------------
| Element Id                             | Value                         |  Comments  |
---------------------------------------------------------------------------------------
| PRO_E_FEATURE_TYPE                     | PRO_FEAT_CSYS                 |  Mandatory |
| PRO_E_STD_FEATURE_NAME                 | Feature Name                  |  Optional  |
| PRO_E_CSYS_TYPE_MECH                   | ProCsysType                   |  ONLY for Creo Simulate users |
| PRO_E_CSYS_FOLLOW_SRF_OPT              | ProCsysFollowSrfOpt           |  ONLY for sheetmetal users |
| PRO_E_CSYS_NAME_DISPLAY_OPT            | ProCsysNameDisplayOpt         |  Optional  |
| PRO_E_CSYS_DISPLAY_ZOOM_DEP_OPT        | ProCsysDisplayZoomDepOpt      |  optional  |
| PRO_E_CSYS_AXIS_LENGTH                 | PRO_VALUE_TYPE_DOUBLE         |  Optional  |
---------------------------------------------------------------------------------------

Table Csys:2: If three planes or two edges/axes are used to determine the origin 
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_ORIGIN_CONSTRS         | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR          | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR_REF      | Mandatory                                                |
| PRO_E_CSYS_ORIENTSELAXIS1_REF     | Optional, using default if not set                       | 
| PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT | Optional, using default if not set                       | 
| PRO_E_CSYS_ORIENTSELAXIS1_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS1_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS1_FLIP    | Optional                                                 |
| PRO_E_CSYS_ORIENTSELAXIS2_REF     | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT | Optional, using default if not set                       | 
| PRO_E_CSYS_ORIENTSELAXIS2_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS2_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS2_FLIP    | Optional                                                 |
| Others                            | Not Applied                                              |
------------------------------------------------------------------------------------------------

Table Csys:3: If plane + edge/axis/curve or edge/axis/curve + plane are used to determine the origin
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_ORIGIN_CONSTRS         | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR          | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR_REF      | Mandatory                                                |
| PRO_E_CSYS_ORIENTSELAXIS1_REF     | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS1_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS1_FLIP    | Optional                                                 |
| PRO_E_CSYS_ORIENTSELAXIS2_REF     | Mandatory                                                |
| PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS2_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS2_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS2_FLIP    | Optional                                                 |
| Others                            | Not Applied                                              |
------------------------------------------------------------------------------------------------

Table Csys:4: If vertex/datum point is used to determine the origin
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_ORIGIN_CONSTRS         | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR          | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR_REF      | Mandatory                                                |
| PRO_E_CSYS_ORIENTSELAXIS1_REF     | Mandatory                                                | 
| PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS1_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS1_FLIP    | Optional                                                 |
| PRO_E_CSYS_ORIENTSELAXIS2_REF     | Mandatory                                                |
| PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS2_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS2_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS2_FLIP    | Optional                                                 |
| Others                            | Not Applied                                              |
------------------------------------------------------------------------------------------------

Table Csys:5: If a csys is used to determine the origin
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_ORIGIN_CONSTRS         | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR          | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR_REF      | Mandatory                                                |
| PRO_E_CSYS_OFFSET_TYPE            | Optional, using default PRO_CSYS_OFFSET_CARTESIAN if not set |
| PRO_E_CSYS_ORIENTMOVES            | Mandatory for non PRO_CSYS_OFFSET_CARTESIAN 
| PRO_E_CSYS_ORIENTMOVE             | Mandatory for non PRO_CSYS_OFFSET_CARTESIAN              |
| PRO_E_CSYS_ORIENTMOVE_MOVE_TYPE   | Mandatory for non PRO_CSYS_OFFSET_CARTESIAN              |
| PRO_E_CSYS_ORIENTMOVE_MOVE_VAL    | Mandatory for non PRO_CSYS_OFFSET_CARTESIAN              |
                        For PRO_CSYS_OFFSET_CYLINDRICAL, PRO_CSYS_ORIENTMOVE_MOVE_OPT_RAD,
                        PRO_CSYS_ORIENTMOVE_MOVE_OPT_THETA , PRO_CSYS_ORIENTMOVE_MOVE_OPT_ZI are required;  
                        For PRO_CSYS_OFFSET_SPHERICAL, PRO_CSYS_ORIENTMOVE_MOVE_OPT_RAD ,  
                        PRO_CSYS_ORIENTMOVE_MOVE_OPT_PHI, PRO_CSYS_ORIENTMOVE_MOVE_OPT_THETA are required. 
                         
| PRO_E_CSYS_ORIENT_BY_METHOD       | Mandatory, using default PRO_CSYS_ORIENT_BY_SEL_REFS if not set

Sub-Table Csys:5.1: If PRO_E_CSYS_ORIENT_BY_METHOD is PRO_CSYS_ORIENT_BY_SEL_REFS 
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_ORIENTSELAXIS1_REF     | Mandatory
| PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_OPT     | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_FLIP    | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS2_REF     | Mandatory                                                | 
| PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS2_OPT     | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS2_FLIP    | Optional, using default if not set                       |
| Others                            | Not applied                                              |
------------------------------------------------------------------------------------------------

Sub-Table Csys:5.2: If PRO_E_CSYS_ORIENT_BY_METHOD is PRO_CSYS_ORIENT_BY_SEL_CSYS_AXES 
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_NORMAL_TO_SCREEN       | Optional,Meaningful only if PRO_E_CSYS_ORIENT_BY_METHOD = | 
                                      PRO_CSYS_ORIENT_BY_SEL_CSYS_AXES. Otherwise, it'll be ignored  |
| Others                            | Not applied                                              | 
------------------------------------------------------------------------------------------------

Table Csys:6: OnSurf Csys - If 1 Surface/Quilt + 2 Dim edge/axis/curve/plane are used to determine the origin
------------------------------------------------------------------------------------------------
| Element Id                        | Comments                                                 |
------------------------------------------------------------------------------------------------
| PRO_E_CSYS_ORIGIN_CONSTRS         | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR          | Mandatory                                                |
| PRO_E_CSYS_ORIGIN_CONSTR_REF      | Mandatory                                                |
| PRO_E_CSYS_ONSURF_TYPE            | Optional, using default PRO_CSYS_ONSURF_LINEAR if not set |
| PRO_E_CSYS_DIM_CONSTRS            | Mandatory                                                |
| PRO_E_CSYS_DIM_CONSTR             | Mandatory                                                |
| PRO_E_CSYS_DIM_CONSTR_REF         | Mandatory                                                |
| PRO_E_CSYS_DIM_CONSTR_TYPE        | Optional, using default PRO_CSYS_DIM_CONSTR_TYPE_OFFSET if not set |
| PRO_E_CSYS_DIM_CONSTR_VALUE       | Mandatory if PRO_E_CSYS_DIM_CONSTR_TYPE is OFFSET        |
| PRO_E_CSYS_ORIENTSELAXIS1_REF     | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS1_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS1_FLIP    | Optional                                                 |
| PRO_E_CSYS_ORIENTSELAXIS2_REF     | Mandatory                                                |
| PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT | Optional, using default if not set                       |
| PRO_E_CSYS_ORIENTSELAXIS1_OPT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS2_REF is a csys ref |
| PRO_E_CSYS_ORIENTSELAXIS2_FLIP    | Optional                                                 |
| PRO_E_CSYS_ORIENTSELAXIS2_ROT_OPT | Optional, using default PRO_CSYS_ORIENTSELAXIS_ROT_NO if not set |
| PRO_E_CSYS_ORIENTSELAXIS2_ROT     | Mandatory if PRO_E_CSYS_ORIENTSELAXIS2_ROT_OPT is YES    |
| Others                            | Not Applied                                              |
------------------------------------------------------------------------------------------------
*/

/* ProCsysDirCsysRefOpt is ONLY valid for csys as dir ref */

typedef enum pro_csys_dircsysref_opt  
{
   PRO_CSYS_DIRCSYSREF_OPT_ORIGIN = 0,
   PRO_CSYS_DIRCSYSREF_OPT_X ,
   PRO_CSYS_DIRCSYSREF_OPT_Y ,
   PRO_CSYS_DIRCSYSREF_OPT_Z
} ProCsysDirCsysRefOpt ;

typedef enum pro_csys_orientationmove_axis_opt
{
   PRO_CSYS_ORIENTMOVE_AXIS_OPT_X = 0 ,
   PRO_CSYS_ORIENTMOVE_AXIS_OPT_Y ,
   PRO_CSYS_ORIENTMOVE_AXIS_OPT_Z
} ProCsysOrientMoveAxisOpt ;

typedef enum pro_csys_orientationmove_move_opt 
{ 
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_TRAN_X =  0 , 
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_TRAN_Y, 
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_TRAN_Z ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_ROT_X ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_ROT_Y ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_ROT_Z ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_RAD ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_PHI ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_ZI ,
   PRO_CSYS_ORIENTMOVE_MOVE_OPT_THETA
} ProCsysOrientMoveMoveOpt ; 

typedef enum pro_csys_orientmoves_nrmscrn_opt
{
   PRO_CSYS_ORIENTMOVES_NRMSCRN_NO = 0 ,
   PRO_CSYS_ORIENTMOVES_NRMSCRN_YES
} ProCsysOrientMovesNrmScrnOpt ;

typedef enum pro_csys_orientselaxis_flip_opt
{
   PRO_CSYS_ORIENTSELAXIS_FLIP_NO = 0 ,
   PRO_CSYS_ORIENTSELAXIS_FLIP_YES
} ProCsysOrientSelAxisFlipOpt ;

typedef enum pro_csys_offset_type 
{
   PRO_CSYS_OFFSET_CARTESIAN = 0 , 
   PRO_CSYS_OFFSET_CYLINDRICAL ,
   PRO_CSYS_OFFSET_SPHERICAL , 
   PRO_CSYS_OFFSET_FROMFILE      /* This value is not supported. */ 
} ProCsysOffsetType ;

typedef enum pro_csys_orient_by_method
{
   PRO_CSYS_ORIENT_BY_SEL_REFS = 0 ,
   PRO_CSYS_ORIENT_BY_SEL_CSYS_AXES 
} ProCsysOrientByMethod ;

typedef enum pro_csys_type
{
   PRO_CSYS_UNIVERSAL   = 0,
   PRO_CSYS_CARTESIAN,
   PRO_CSYS_CYLINDRICAL,
   PRO_CSYS_SPHERICAL
} ProCsysType;


/* Function Prototypes */

extern ProError ProDtmcsysTransformfileRead (wchar_t* file_name, ProElement elem_tree );
/*
   Purpose: Allocates required steps of the element tree to create CSYS from 
            transformation file.
            <P>
            Attention: the created csys may be different from releases 
	    prior to Pro/E Wildfire 1.0.
	    <P>
	    Note: format of transformation file
	    <P>
	    The input file name to ProDtmcsysTransformfileRead should 
	    have the name of a .trf file, with the extension. 
	    The name must be lowercase only. The file should
	    contain a coordinate transform such as:
	    <PRE>X1    X2    X3    Tx</PRE><BR>
	    <PRE>Y1    Y2    Y3    Ty</PRE><BR>
	    <PRE>Z1    Z2    Z3    Tz</PRE><BR>
	    where X1 Y1 Z1 is the X-axis direction, 
	    X2 Y2 Z2 is the Y-axis direction,
	    X3 Y3 Z3 is not used (the right hand rule 
	    determines the Z direction), and
	    Tx Ty Tz is the origin of the coordinate system.

   Input Arguments:
       file_name         -  Name of the transformation file (with 
                            the extension .trf). Both absolute and relative 
			    paths are supported.
       elem_tree         -  Element tree root element

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR    - The function successfully allocated the elements.
       PRO_TK_BAD_INPUTS  - The input argument is invalid.
       PRO_TK_NOT_FOUND   - The transform file could not be read.
*/



/*
The following element tree was used in release 2001 and earlier 
and is provided for reference purposes only.  Users are advised 
not to use this element tree for feature creation or modification
activities anymore beginning with Wildfire version 1.0.

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CSYS_METHOD
     |
     |--PRO_E_CSYS_REFS
     |    |--PRO_E_CSYS_PLANE1            If Method == Three planes
     |    |--PRO_E_CSYS_PLANE2            If Method == Three planes
     |    |--PRO_E_CSYS_PLANE3            If Method == Three planes
     |    |--PRO_E_CSYS_PLANE             If Method == 2Refs+Plane
     |    |--PRO_E_CSYS_REF1              If Method == 2 References or
     |    |                                  Method == 2Refs+Plane
     |    |--PRO_E_CSYS_REF2              If Method == 2 References or
     |    |                                  Method == 2Refs+Plane
     |    |--PRO_E_CSYS_ORIGIN            If Method == Orig+2dir
     |    |--PRO_E_CSYS_DIR1              If Method == Orig+2dir
     |    |--PRO_E_CSYS_DIR2              If Method == Orig+2dir
     |    |--PRO_E_CSYS_CSYS              If Method == Offset or
     |                                       Method == Offset by view or
     |                                       Method == From file or
     |--PRO_E_CSYS_TRAN_FILE              If Method == From file
     |--PRO_E_CSYS_MOVES                  If Method == Offset
     |    |                               Array of PRO_E_CSYS_MOVE
     |    |--PRO_E_CSYS_MOVE
     |         |--UIE_CSYS_MOVE_METHOD
     |         |--UIE_CSYS_MOVE_VALUE
     |--PRO_E_CSYS_ROT                    If Method == Offset by view
     |    |--PRO_E_CSYS_1ROT
     |    |--PRO_E_CSYS_2ROT
     |--PRO_E_CSYS_MOVES_VIEW             If Method == Offset by view
     |    |                               Array of PRO_E_CSYS_MOVE
     |    |--PRO_E_CSYS_MOVE
     |         |--UIE_CSYS_MOVE_METHOD
     |         |--UIE_CSYS_MOVE_VALUE
     |--PRO_E_CSYS_SEL_AXES               If Method == Three planes or
          |                                  Method == 2 References or
          |                                  Method == 2Refs+Plane  or
          |                                  Method == Orig+2dir
          |--PRO_E_CSYS_X_DIR
          |--PRO_E_CSYS_Y_DIR


Feature elements table

--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type                Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_CSYS
PRO_E_CSYS_METHOD              Method         PRO_VALUE_TYPE_INT       see ProCsysMethod
PRO_E_DTMAXIS_REFS             References     Compound
PRO_E_CSYS_PLANE1              Plane 1        PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_PLANE2              Plane 2        PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_PLANE3              Plane 3        PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_PLANE               Plane          PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_REF1                Reference 1    PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_REF2                Reference 2    PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_ORIGIN              Origin         PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_DIR1                Direction 1    Compound
PRO_E_CSYS_DIR2                Direction 2    Compound
PRO_E_CSYS_CSYS                Csys           PRO_VALUE_TYPE_SELECTION
PRO_E_CSYS_TRAN_FILE           Transform file PRO_VALUE_TYPE_WSTRING
PRO_E_CSYS_MOVES               Moves          Array
PRO_E_CSYS_MOVE                Move           Compound
PRO_E_CSYS_MOVE_METHOD         Method         PRO_VALUE_TYPE_INT       see ProCsysMvMethod
PRO_E_CSYS_MOVE_VALUE          Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_CSYS_ROT                 Rotation       Compound
PRO_E_CSYS_1ROT                1st Rotation   PRO_VALUE_TYPE_INT       see ProCsysRotAxis
PRO_E_CSYS_2ROT                2nd Rotation   PRO_VALUE_TYPE_INT       see ProCsysRotAxis
PRO_E_CSYS_MOVES_VIEW          Moves          Array
PRO_E_CSYS_SEL_AXES            Select Axes    Compound
PRO_E_CSYS_X_DIR               X Axis         PRO_VALUE_TYPE_INT       see ProCsysAxisDir
PRO_E_CSYS_Y_DIR               Y Axis         PRO_VALUE_TYPE_INT       see ProCsysAxisDir

*/

/* 1. PRO_E_CSYS_METHOD */

typedef enum pro_csys_method
{
   PRO_CSYS_3PLANE = 0,
   PRO_CSYS_2REFS,
   PRO_CSYS_2REFS_PLANE,
   PRO_CSYS_ORIGIN_2DIR,
   PRO_CSYS_OFFSET,
   PRO_CSYS_OFFSET_BYVIEW,
   PRO_CSYS_DEFAULT,
   PRO_CSYS_FROM_FILE ,
   PRO_CSYS_PNT_2AX ,
   PRO_CSYS_PNT_ZAXIS ,
   PRO_CSYS_ONSURF
} ProCsysMethod;

/*
NOTE:

   Using the option PRO_CSYS_FROM_FILE requires a reference coordinate system
   (PRO_E_CSYS_CSYS) and a filename (PRO_E_CSYS_TRAN_FILE).

   The element PRO_E_CSYS_TRAN_FILE should have the name of a .trf file,
   without the extension. The name must be lowercase only. The file should
   contain a coordinate transform such as:

      X1    X2    X3    Tx
      Y1    Y2    Y3    Ty
      Z1    Z2    Z3    Tz

   where X1 Y1 Z1 is the X-axis direction, X2 Y2 Z2 is the Y-axis direction,
   X3 Y3 Z3 is not used (the right hand rule determines the Z direction), and
   Tx Ty Tz is the origin of the coordinate system.

   PRO_CSYS_ONSURF is a read only option.

*/

typedef enum pro_csys_rot_axis
{
   PRO_CSYS_ROT_X_VIEW = 0,
   PRO_CSYS_ROT_Y_VIEW,
   PRO_CSYS_ROT_Z_VIEW
} ProCsysRotAxis;

typedef enum pro_csys_mv_method
{
   PRO_CSYS_TRAN_X = 0,
   PRO_CSYS_TRAN_Y,
   PRO_CSYS_TRAN_Z,
   PRO_CSYS_ROT_X,
   PRO_CSYS_ROT_Y,
   PRO_CSYS_ROT_Z
} ProCsysMvMethod;

typedef enum pro_csys_axis_dir
{
   PRO_CSYS_ORIG_X = 0,
   PRO_CSYS_ORIG_Y,
   PRO_CSYS_ORIG_Z,
   PRO_CSYS_ORIG_X_REV,
   PRO_CSYS_ORIG_Y_REV,
   PRO_CSYS_ORIG_Z_REV
} ProCsysAxisDir;

/*  PRO_E_CSYS_FOLLOW_SRF_OPT is ONLY valid in sheet metal environment  */

typedef enum pro_csys_follow_srf_opt  
{                                  
   PRO_CSYS_FOLLOW_SRF_NO   = 0,
   PRO_CSYS_FOLLOW_SRF_YES  = 1
} ProCsysFollowSrfOpt;

typedef enum pro_csys_onsurf_type
{
   PRO_CSYS_ONSURF_LINEAR = 1,
   PRO_CSYS_ONSURF_RADIAL = 2,
   PRO_CSYS_ONSURF_DIAMETER = 3
} ProCsysOnSurfType ;

typedef enum pro_csys_dim_contsr_type
{
   PRO_CSYS_DIM_CONSTR_TYPE_OFFSET = 0,
   PRO_CSYS_DIM_CONSTR_TYPE_ALIGN 
} ProCsysDimConstrType ;

typedef enum pro_csys_orientselaxis_rot_opt
{
   PRO_CSYS_ORIENTSELAXIS_ROT_NO = 0,
   PRO_CSYS_ORIENTSELAXIS_ROT_YES
} ProCsysOrientSelAxisRotOpt ;

typedef enum pro_csys_name_display_opt
{
   PRO_CSYS_NAME_DISPLAY_NO = 0,
   PRO_CSYS_NAME_DISPLAY_YES
} ProCsysNameDisplayOpt ;

typedef enum pro_csys_pln
{
   PRO_CSYS_PLN_XY = 0,
   PRO_CSYS_PLN_YZ,
   PRO_CSYS_PLN_ZX,
   PRO_CSYS_PLN_FLAT_TO_SCRN
} ProCsysPln, ProCsysNameDisplayPln;

typedef enum pro_csys_display_zoom_dep_opt
{
   PRO_CSYS_DISPLAY_ZOOM_DEP_NO = 0,
   PRO_CSYS_DISPLAY_ZOOM_DEP_YES
} ProCsysDisplayZoomDepOpt ;


PRO_END_C_DECLS

#endif
