#ifndef PRODTMPNT
#define PRODTMPNT

/*
   Creo Parametric TOOLKIT declarations related to datum point feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

typedef enum Pro_DPoint_Type
{
   PRO_DPOINT_TYPE_GENERAL            = -1,
   PRO_DPOINT_TYPE_OFFSET_CSYS        = 6,
   PRO_DPOINT_TYPE_FIELD              = 21,
   PRO_DPOINT_TYPE_SKETCHED           = 22
} ProDPointType;

typedef enum pro_dtmpnt_constr_type
{
  PRO_DTMPNT_CONSTR_TYPE_NONE         = -1,
  PRO_DTMPNT_CONSTR_TYPE_ON           =  0,
  PRO_DTMPNT_CONSTR_TYPE_OFFSET       =  1,
  PRO_DTMPNT_CONSTR_TYPE_CENTER       =  2,
  PRO_DTMPNT_CONSTR_TYPE_NORMAL       =  3,
  PRO_DTMPNT_CONSTR_TYPE_PARALLEL     =  4,
  PRO_DTMPNT_CONSTR_TYPE_LENGTH       =  5, /* Length From Start */
  PRO_DTMPNT_CONSTR_TYPE_LENGTH_END   =  6, /* Length From End   */
  PRO_DTMPNT_CONSTR_TYPE_RATIO        =  7, /* Ratio  From Start */
  PRO_DTMPNT_CONSTR_TYPE_RATIO_END    =  8, /* Ratio  From End   */
  PRO_DTMPNT_CONSTR_TYPE_ALONG_X      =  9,
  PRO_DTMPNT_CONSTR_TYPE_ALONG_Y      = 10,
  PRO_DTMPNT_CONSTR_TYPE_ALONG_Z      = 11,
  PRO_DTMPNT_CONSTR_TYPE_CARTESIAN    = 12,
  PRO_DTMPNT_CONSTR_TYPE_CYLINDRICAL  = 13,
  PRO_DTMPNT_CONSTR_TYPE_SPHERICAL    = 14

} ProDtmpntConstrType;

typedef enum pro_dtmpnt_offcsys_type
{
   PRO_DTMPNT_OFFCSYS_CARTESIAN   = 0,
   PRO_DTMPNT_OFFCSYS_CYLINDRICAL = 2,
   PRO_DTMPNT_OFFCSYS_SPHERICAL   = 4
} ProDtmpntOffCsysType;

/* ***************************************************************************

################################################################################
############################# SKETCHED DATUM POINT #############################
################################################################################

Note: The element tree below is only meant for querying purposes.
      Sketched Datum Points migrated to Sketched Curve feature
      starting with Wildfire 5, so users should employ the element tree of
      Sketched Curve feature in ProDtmCrv.h for creating new sketched datum points.

================================================================================
Element Id                     Element Name             Data Type
================================================================================
|--PRO_E_FEATURE_TYPE          Feature Type             PRO_VALUE_TYPE_INT
|--PRO_E_DPOINT_TYPE           Datum Point Type         PRO_VALUE_TYPE_INT
|--PRO_E_STD_FEATURE_NAME      Feature Name             PRO_VALUE_TYPE_WSTRING
|--PRO_E_STD_SECTION           Section                  Compound
================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_DATUM_POINT
PRO_E_DPOINT_TYPE                 PRO_DPOINT_TYPE_SKETCHED  
PRO_E_STD_SECTION                 see ProStdSection.h
================================================================================

The following sub-elements of PRO_E_STD_SECTION must be defined to 
complete feature:

|--PRO_E_STD_SECTION
     |--PRO_E_STD_SEC_SETUP_PLANE            
          |--PRO_E_STD_SEC_PLANE             
          |--PRO_E_STD_SEC_PLANE_VIEW_DIR    
          |--PRO_E_STD_SEC_PLANE_ORIENT_DIR  
          |--PRO_E_STD_SEC_PLANE_ORIENT_REF 
     |--PRO_E_SKETCHER                      

################################################################################
############################# FIELD   DATUM POINT ##############################
################################################################################
================================================================================
Element Id                     Element Name             Data Type
================================================================================
|--PRO_E_FEATURE_TYPE          Feature Type             PRO_VALUE_TYPE_INT
|--PRO_E_DPOINT_TYPE           Datum Point Type         PRO_VALUE_TYPE_INT
|--PRO_E_STD_FEATURE_NAME      Feature Name             PRO_VALUE_TYPE_WSTRING
|--PRO_E_DPOINT_FIELD_REF      Placement Reference      PRO_VALUE_TYPE_SELECTION
================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_DATUM_POINT
PRO_E_DPOINT_TYPE                 PRO_DPOINT_TYPE_FIELD  
PRO_E_DPOINT_FIELD_REF            Surface / Edge / Curve / Quilt.
                                  Note: UV is used to specify exact location.
================================================================================

################################################################################
########################### OFFSET CSYS DATUM POINT ############################
################################################################################
 |--PRO_E_FEATURE_TYPE
 |
 |--PRO_E_DPOINT_TYPE            
 |
 |--PRO_E_STD_FEATURE_NAME
 |
 |--PRO_E_DPOINT_OFST_CSYS_TYPE
 |
 |--PRO_E_DPOINT_OFST_CSYS_REF
 |
 |--PRO_E_DPOINT_OFST_CSYS_WITH_DIMS
 |
 |--PRO_E_DPOINT_OFST_CSYS_PNTS_ARRAY        (Array of points within DP feature)
      |--PRO_E_DPOINT_OFST_CSYS_PNT
           |--PRO_E_DPOINT_OFST_CSYS_PNT_NAME
           |--PRO_E_DPOINT_OFST_CSYS_DIR1_VAL
           |--PRO_E_DPOINT_OFST_CSYS_DIR2_VAL
           |--PRO_E_DPOINT_OFST_CSYS_DIR3_VAL
================================================================================

================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_DPOINT_TYPE                 Datum Point Type      PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_DPOINT_OFST_CSYS_TYPE       Reference Csys Type   PRO_VALUE_TYPE_INT
PRO_E_DPOINT_OFST_CSYS_REF        Reference Csys        PRO_VALUE_TYPE_SELECTION
PRO_E_DPOINT_OFST_CSYS_WITH_DIMS  Parametric/Explicit   PRO_VALUE_TYPE_INT
                                  with or without dims.
PRO_E_DPOINT_OFST_CSYS_PNTS_ARRAY Points List           Array
PRO_E_DPOINT_OFST_CSYS_PNT        One Point             Compound
PRO_E_DPOINT_OFST_CSYS_PNT_NAME   Point Name            PRO_VALUE_TYPE_WSTRING
PRO_E_DPOINT_OFST_CSYS_DIR1_VAL   X /   R   /  RHO      PRO_VALUE_TYPE_DOUBLE
PRO_E_DPOINT_OFST_CSYS_DIR2_VAL   Y / THETA /  PHI      PRO_VALUE_TYPE_DOUBLE
PRO_E_DPOINT_OFST_CSYS_DIR3_VAL   Z /   Z   / THETA     PRO_VALUE_TYPE_DOUBLE
================================================================================

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_DATUM_POINT
PRO_E_DPOINT_TYPE                 PRO_DPOINT_TYPE_OFFSET_CSYS
PRO_E_DPOINT_OFST_CSYS_TYPE       see ProDtmpntOffCsysType
PRO_E_DPOINT_OFST_CSYS_REF        Csys
PRO_E_DPOINT_OFST_CSYS_WITH_DIMS  PRO_B_TRUE or PRO_B_FALSE
PRO_E_DPOINT_OFST_CSYS_DIR1_VAL   Depend on PRO_E_DPOINT_OFST_CSYS_TYPE
PRO_E_DPOINT_OFST_CSYS_DIR2_VAL   Depend on PRO_E_DPOINT_OFST_CSYS_TYPE
PRO_E_DPOINT_OFST_CSYS_DIR3_VAL   Depend on PRO_E_DPOINT_OFST_CSYS_TYPE
================================================================================

################################################################################
############################# GENERAL DATUM POINT ##############################
################################################################################
 |--PRO_E_FEATURE_TYPE
 |
 |--PRO_E_DPOINT_TYPE
 |
 |--PRO_E_STD_FEATURE_NAME
 |
 |--PRO_E_DPOINT_POINTS_ARRAY                (Array of points within DP feature)
 |    |--PRO_E_DPOINT_POINT
 |         |--PRO_E_DPOINT_POINT_NAME
 |         |--PRO_E_DPOINT_PLA_CONSTRAINTS   (Array of placement constraints   )
 |              |--PRO_E_DPOINT_PLA_CONSTRAINT
 |                   |--PRO_E_DPOINT_PLA_CONSTR_REF
 |                   |--PRO_E_DPOINT_PLA_CONSTR_TYPE
 |                   |--PRO_E_DPOINT_PLA_CONSTR_VAL
 |         |--PRO_E_DPOINT_DIM_CONSTRAINTS   (Array of dimension constraints   )
 |              |--PRO_E_DPOINT_DIM_CONSTRAINT
 |                   |--PRO_E_DPOINT_DIM_CONSTR_REF
 |                   |--PRO_E_DPOINT_DIM_CONSTR_TYPE
 |                   |--PRO_E_DPOINT_DIM_CONSTR_VAL
================================================================================

================================================================================
Element Id                     Element Name             Data Type
================================================================================
PRO_E_FEATURE_TYPE             Feature Type             PRO_VALUE_TYPE_INT
PRO_E_DPOINT_TYPE              Datum Point Type         PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME         Feature Name             PRO_VALUE_TYPE_WSTRING
PRO_E_DPOINT_POINTS_ARRAY      Points List              Array
PRO_E_DPOINT_POINT             One Point                Compound
PRO_E_DPOINT_POINT_NAME        Point Name               PRO_VALUE_TYPE_WSTRING
PRO_E_DPOINT_PLA_CONSTRAINTS   Placement Constraints    Array
PRO_E_DPOINT_PLA_CONSTRAINT    One Placement Constraint Compound
PRO_E_DPOINT_PLA_CONSTR_REF    Placement Ref.           PRO_VALUE_TYPE_SELECTION
PRO_E_DPOINT_PLA_CONSTR_TYPE   Constraint Type          PRO_VALUE_TYPE_INT
PRO_E_DPOINT_PLA_CONSTR_VAL    Value                    PRO_VALUE_TYPE_DOUBLE
PRO_E_DPOINT_DIM_CONSTRAINTS   Dim. Constraints         Array
PRO_E_DPOINT_DIM_CONSTRAINT    One Dim. Constraint      Compound
PRO_E_DPOINT_DIM_CONSTR_REF    Dim. Ref.                PRO_VALUE_TYPE_SELECTION
PRO_E_DPOINT_DIM_CONSTR_TYPE   Constraint Type          PRO_VALUE_TYPE_INT
PRO_E_DPOINT_DIM_CONSTR_VAL    Value                    PRO_VALUE_TYPE_DOUBLE
================================================================================

================================================================================
Element Id                     Valid Values
================================================================================
PRO_E_FEATURE_TYPE             PRO_FEAT_DATUM_POINT
PRO_E_DPOINT_TYPE              PRO_DPOINT_TYPE_GENERAL
PRO_E_STD_FEATURE_NAME
PRO_E_DPOINT_POINTS_ARRAY      N/A
PRO_E_DPOINT_POINT             N/A
PRO_E_DPOINT_POINT_NAME
PRO_E_DPOINT_PLA_CONSTRAINTS   N/A
PRO_E_DPOINT_PLA_CONSTRAINT    N/A
PRO_E_DPOINT_PLA_CONSTR_REF    Depend on context. See below.
PRO_E_DPOINT_PLA_CONSTR_TYPE   See ProDtmpntConstrType
PRO_E_DPOINT_PLA_CONSTR_VAL
PRO_E_DPOINT_DIM_CONSTRAINTS   N/A
PRO_E_DPOINT_DIM_CONSTRAINT    N/A
PRO_E_DPOINT_DIM_CONSTR_REF    Depend on context. See below.
PRO_E_DPOINT_DIM_CONSTR_TYPE   See ProDtmpntConstrType
PRO_E_DPOINT_DIM_CONSTR_VAL
================================================================================
  *************************************************************************** */

/*============================================================================*/
/*                                                                            */
/* PRO_E_DPOINT_PLA_CONSTR_REF                                                */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                */
/* Valid values for the placement reference are as following:                 */
/*                                                                            */
/* Curve   -    SEL_3D_CURVE, SEL_3D_CABLE, SEL_IGES_WF                       */
/* Edge     | - SEL_3D_EDG                                                    */
/* Axis    -    SEL_3D_AXIS                                                   */
/* Vertex     - SEL_3D_VERT or SEL_CURVE_END                                  */
/* CSYS       - SEL_3D_CSYS                                                   */
/* CSYS_AXIS  - SEL_3D_CSYS_AXIS                                              */
/* Surface    - SEL_3D_SRF, SEL_3D_SRF_LIST                                   */
/* Datum Pnt  - SEL_3D_PNT                                                    */
/*                                                                            */
/* PRO_E_DPOINT_PLA_CONSTR_TYPE                                               */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                               */
/* Valid values for PRO_E_DPOINT_PLA_CONSTR_TYPE are as following:            */
/*                                                                            */
/* PRO_DTMPNT_CONSTR_TYPE_ON                                                  */
/* PRO_DTMPNT_CONSTR_TYPE_OFFSET                                              */
/* PRO_DTMPNT_CONSTR_TYPE_CENTER                                              */
/* PRO_DTMPNT_CONSTR_TYPE_PARALLEL                                            */
/* PRO_DTMPNT_CONSTR_TYPE_NORMAL                                              */
/* PRO_DTMPNT_CONSTR_TYPE_CARTESIAN                                           */
/* PRO_DTMPNT_CONSTR_TYPE_CYLINDRICAL                                         */
/* PRO_DTMPNT_CONSTR_TYPE_SPHERICAL                                           */
/*                                                                            */
/* PRO_E_DPOINT_DIM_CONSTR_REF                                                */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                */
/* Valid values for the dimension references are as following:                */
/*                                                                            */
/* Curve   -    SEL_3D_CURVE, SEL_3D_CABLE, SEL_CRV_PNT, SEL_IGES_WF          */
/* Edge     | - SEL_3D_EDG, SEL_EDG_PNT                                       */
/* Axis    -    SEL_3D_AXIS                                                   */
/* CSYS       - SEL_3D_CSYS                                                   */
/* Surface    - SEL_3D_SRF, SEL_SRF_PNT, SEL_3D_SRF_LIST                      */
/*                                                                            */
/* PRO_E_DPOINT_DIM_CONSTR_TYPE                                               */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                */
/* Valid values for PRO_E_DPOINT_DIM_CONSTR_TYPE are as following:            */
/*                                                                            */
/* PRO_DTMPNT_CONSTR_TYPE_OFFSET                                              */
/* PRO_DTMPNT_CONSTR_TYPE_LENGTH                                              */
/* PRO_DTMPNT_CONSTR_TYPE_RATIO                                               */
/* PRO_DTMPNT_CONSTR_TYPE_LENGTH_END                                          */
/* PRO_DTMPNT_CONSTR_TYPE_RATIO                                               */
/* PRO_DTMPNT_CONSTR_TYPE_RATIO_END                                           */
/* PRO_DTMPNT_CONSTR_TYPE_ALONG_X                                             */
/* PRO_DTMPNT_CONSTR_TYPE_ALONG_Y                                             */
/* PRO_DTMPNT_CONSTR_TYPE_ALONG_Z                                             */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                             EXAMPLES                                       */
/*                             ========                                       */
/*                                                                            */
/*                           At Vertex                                        */
/*                           ~~~~~~~~~                                        */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Vertex                                  */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/*                           Offset Point                                     */
/*                           ~~~~~~~~~~~~                                     */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Vertex / CSys / DPnt                    */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_OFFSET           */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    Offset Value                            */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Curve / Edge / Axis                     */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_PARALLEL         */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/*                                 OR                                         */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Surface                                 */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_NORMAL           *//*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/*                                 OR                                         */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Csys Axis                               */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_PARALLEL         */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/*                                 OR                                         */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Csys                                    */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_CARTESIAN or     */
/*                                    PRO_DTMPNT_CONSTR_TYPE_CYLINDRICAL or   */
/*                                    PRO_DTMPNT_CONSTR_TYPE_SPHERICAL        */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    N/A                                     */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ALONG_X          */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Offset Value                            */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    N/A                                     */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ALONG_Y          */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Offset Value                            *//*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    N/A                                     */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ALONG_Z          */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Offset Value                            */
/*                                                                            */
/*     Note:  The ALONG_X/Y/Z above would be used as :                        */
/*            X,   Y,     Z     when offset type is CARTESIAN;                */
/*            R,   THETA, Z     when offset type is CYLINDRICAL;              */
/*            RHO, PHI,   THETA when offset type is SPHERICAL offsting type.  */
/*                                                                            */
/*                                                                            */
/*                           Three Surfaces                                   */
/*                           ~~~~~~~~~~~~~~                                   */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Surface                                 */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               *//*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Surface                                 */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               *//*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Surface                                 */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               *//*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/*                           On/Offset Surface                                */
/*                           ~~~~~~~~~~~~~~~~~                                */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Surface                                 */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON or            */
/*                                    PRO_DTMPNT_CONSTR_TYPE_OFFSET           */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A - for ON, offset value - for OFFSET */
/* PRO_E_DPOINT_DIM_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    Edge/Surface                            */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_OFFSET           */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Offset Value                            */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    Edge/Surface                            */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_OFFSET           */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Offset Value                            */
/*                                                                            */
/*                           Curve  X  Surface                                */
/*                           ~~~~~~~~~~~~~~~~~                                */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Curve / Axis / Edge or Surface          */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Surface or Curve / Axis / Edge          */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/* Note: If MORE than one intersections exist - The point will be             */
/*       created at the intersection nearest to the curve reference           */
/*       t-parameter value from the ProSelection object. use                  */
/*       ProSelectionUvParamSet() for setting it programmatically.            */
/*                                                                            */
/*                           At Curve's / Surface's Center                    */
/*                           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                    */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Curve / Edge / Surface (Sphere)         */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_CENTER           */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/*                           Curve X Curve                                    */
/*                           ~~~~~~~~~~~~~                                    */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Curve / Edge / Axis                     */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Curve / Edge / Axis                     */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/*                                                                            */
/* Note: If MORE than one intersections exist - The point will be             */
/*       created at the intersection nearest to the SECOND reference          */
/*       t-parameter value from the ProSelection object. use                  */
/*       ProSelectionUvParamSet() for setting it programmatically.            */
/*                                                                            */
/*                           On Curve                                         */
/*                           ~~~~~~~~                                         */
/* PRO_E_DPOINT_PLA_CONSTRAINTS                                               */
/*   PRO_E_DPOINT_PLA_CONSTRAINT                                              */
/*     PRO_E_DPOINT_PLA_CONSTR_REF    Curve / Edge/ Axis(valid with ofst pln) */
/*     PRO_E_DPOINT_PLA_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_ON               */
/*     PRO_E_DPOINT_PLA_CONSTR_VAL    N/A                                     */
/* PRO_E_DPOINT_DIM_CONSTRAINTS                                               */
/*                                    [Length on Curve]:                      */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    Curve (THE SAME)                        */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_LENGTH  or       */
/*                                    PRO_DTMPNT_CONSTR_TYPE_LENGTH_END       */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Length Value (from curve start or end)  */
/*                                                                            */
/*                                 OR [Ratio on Curve]:                       */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    Curve (THE SAME)                        */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_RATIO  or        */
/*                                    PRO_DTMPNT_CONSTR_TYPE_RATIO_END        */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Ratio Value (from curve start or end)   */
/*                                                                            */
/*                                 OR [On curve, offset plane]:               */
/*   PRO_E_DPOINT_DIM_CONSTRAINT                                              */
/*     PRO_E_DPOINT_DIM_CONSTR_REF    Surface                                 */
/*     PRO_E_DPOINT_DIM_CONSTR_TYPE   PRO_DTMPNT_CONSTR_TYPE_OFFSET           */
/*     PRO_E_DPOINT_DIM_CONSTR_VAL    Offset Value                            */
/*                                                                            */
/*                                                                            */
/*                   *** ADD MORE EXAMPLES ***                                */
/*                                                                            */
/*============================================================================*/


typedef enum pro_dtmpnt_type
{
   PRO_DTMPNT_TYPE_ON_SURF        = 3,
   PRO_DTMPNT_TYPE_ONVERTEX       = 5,
   PRO_DTMPNT_TYPE_OFFSET_CSYS    = 6,
   PRO_DTMPNT_TYPE_OFFS_SURF      = 14
} ProDtmpntType;

typedef enum pro_dtmpnt_csystype
{
   PRO_DTMPNT_CSYSTYPE_CARTESIAN   = 0,
   PRO_DTMPNT_CSYSTYPE_CYLINDRICAL = 1,
   PRO_DTMPNT_CSYSTYPE_SPHERICAL   = 2
} ProDtmpntCsystype;

typedef enum pro_dtmpnt_dimensions
{
   PRO_DTMPNT_DIMENSIONS_WITH      = 0,
   PRO_DTMPNT_DIMENSIONS_WITHOUT   = 47
} ProDtmpntDimensions;

/*############################################################################*/
/*   The following element tree was used in release 2001 and earlier          */
/*   and is provided for reference purposes only.  Users are advised          */
/*   not to use this element tree for feature creation or modification        */
/*   activities anymore beginning in this release.                            */
/*############################################################################*/

/*****************************************************************************\

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_DTMPNT_PNTS            Array of PRO_E_DTMPNT_PNT
          |--PRO_E_DTMPNT_PNT
               |--PRO_E_DTMPNT_TYPE
         if PRO_E_DTMPNT_TYPE = PRO_DTMPNT_TYPE_ONSURF
                   |--PRO_E_DTMPNT_PLACE_SURF
                   |--PRO_E_DTMPNT_DIM_REF1
                   |--PRO_E_DTMPNT_DIM_REF2
                   |--PRO_E_DTMPNT_DIM_DIST1
                   |--PRO_E_DTMPNT_DIM_DIST2
         if PRO_E_DTMPNT_TYPE = PRO_DTMPNT_TYPE_OFFS_SURF
                   |--PRO_E_DTMPNT_PLACE_SURF
                   |--PRO_E_DTMPNT_DIM_REF1
                   |--PRO_E_DTMPNT_DIM_REF2
                   |--PRO_E_DTMPNT_DIM_DIST1
                   |--PRO_E_DTMPNT_DIM_DIST2
                   |--PRO_E_DTMPNT_OFFSET_DIST
         if PRO_E_DTMPNT_TYPE = PRO_DTMPNT_TYPE_OFFSET_CSYS
                   |--PRO_E_DTMPNT_CSYSTYPE
                   |--PRO_E_DTMPNT_DIMENSIONS
                   |--PRO_E_DTMPNT_CSYS
                   |--PRO_E_DTMPNT_X
                   |--PRO_E_DTMPNT_Y
                   |--PRO_E_DTMPNT_RADIUS
                   |--PRO_E_DTMPNT_THETA
                   |--PRO_E_DTMPNT_Z
                   |--PRO_E_DTMPNT_PHI
         if PRO_E_DTMPNT_TYPE = PRO_DTMPNT_TYPE_ONVERTEX
                   |--PRO_E_DTMPNT_ONV_VTX


Feature elements table

--------------------------------------------------------------------------------
Element Id                  Element Name   Data Type                Valid Values
--------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_DTMPNT_PNTS           Points List    Array
PRO_E_DTMPNT_PNT            Point          Compound
PRO_E_DTMPNT_TYPE           Point Type     PRO_VALUE_TYPE_INT       See ProDtmpntType
PRO_E_DTMPNT_PLACE_SURF     Placement Surf PRO_VALUE_TYPE_SELECTION
PRO_E_DTMPNT_DIM_REF1       Dim Ref1       PRO_VALUE_TYPE_SELECTION
PRO_E_DTMPNT_DIM_REF2       Dim Ref2       PRO_VALUE_TYPE_SELECTION
PRO_E_DTMPNT_DIM_DIST1      Ref1 Dist      PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_DTMPNT_DIM_DIST2      Ref2 Dist      PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_DTMPNT_OFFSET_DIST    Offset Dist    PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_DTMPNT_CSYSTYPE       Csys Type      PRO_VALUE_TYPE_INT       See ProDtmpntCsystype
PRO_E_DTMPNT_DIMENSIONS     Dimensions     PRO_VALUE_TYPE_INT       See ProDtmpntDimensions
PRO_E_DTMPNT_CSYS           Ref Csys       PRO_VALUE_TYPE_SELECTION
PRO_E_DTMPNT_X              X              PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMPNT_Y       	    Y              PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMPNT_RADIUS         Radius         PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMPNT_THETA          Theta          PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMPNT_Z              Z              PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMPNT_PHI            Phi            PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMPNT_ONV_VTX        Vertex         PRO_VALUE_TYPE_SELECTION
--------------------------------------------------------------------------------


\*****************************************************************************/

PRO_END_C_DECLS

#endif
