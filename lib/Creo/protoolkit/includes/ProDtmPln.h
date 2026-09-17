#ifndef PRODTMPLNH
#define PRODTMPLNH





PRO_BEGIN_C_DECLS


 
/*****************************************************************************\

Feature element tree
 
   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_DTMPLN_CONSTRAINTS             Array of PRO_E_DTMPLN_CONSTRAINT
     |    |--PRO_E_DTMPLN_CONSTRAINT
     |         |--PRO_E_DTMPLN_CONSTR_TYPE
     |         |--PRO_E_DTMPLN_CONSTR_REF
     |         |--PRO_E_DTMPLN_CONSTR_REF_OFFSET    If Constr Type = Offset
     |         |--PRO_E_DTMPLN_CONSTR_REF_ANGLE     If Constr Type = Angle
     |         |--PRO_E_DTMPLN_SEC_IND              If Constr Type = Section
     |         |--PRO_E_DTMPLN_OFF_CSYS      If Constr Type = Offset, Ref = Csys
     |         |--PRO_E_DTMPLN_OFF_CSYS_OFFSET  If C. Type = Offset, Ref = Csys
     |
     |--PRO_E_DTMPLN_FLIP_DIR           Optional element
     |
     |--PRO_E_DTMPLN_FIT                Optional element
          |--PRO_E_DTMPLN_FIT_TYPE
          |--PRO_E_DTMPLN_FIT_REF       If Fit Type is not Default or Fit Radius
          |--PRO_E_DTMPLN_FIT_DTM_RAD   If Fit Type = Fit Radius
          |--PRO_E_DTMPLN_FIT_OUTLINE   If Fit Type = Fit Outline
 
 
3. Feature elements table
 
--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type             Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_DATUM
PRO_E_STD_FEATURE_NAME         Feature Name   PRO_VALUE_TYPE_WSTRING    
PRO_E_DTMPLN_CONSTRAINTS       Constraints    Array
PRO_E_DTMPLN_CONSTRAINT        Constraint     Compound
PRO_E_DTMPLN_CONSTR_TYPE       Type           PRO_VALUE_TYPE_INT       See ProDtmplnConstrType
PRO_E_DTMPLN_CONSTR_REF        References     PRO_VALUE_TYPE_SELECTION See Note 1
PRO_E_DTMPLN_CONSTR_REF_OFFSET Offset         PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_DTMPLN_CONSTR_REF_ANGLE  Angle          PRO_VALUE_TYPE_DOUBLE    (-360.0, 360.0)
PRO_E_DTMPLN_SEC_IND           Section Index  PRO_VALUE_TYPE_INT       [0,sec num - 1]
PRO_E_DTMPLN_OFF_CSYS          Off Csys       PRO_VALUE_TYPE_INT       See ProDtmplnOffCsysAxis
PRO_E_DTMPLN_OFF_CSYS_OFFSET   Off Csys Value PRO_VALUE_TYPE_DOUBLE    Any
PRO_E_DTMPLN_FLIP_DIR          Flip Direction PRO_VALUE_TYPE_INT       ProDtmplnFlipDir 
PRO_E_DTMPLN_FIT               Fit            Compound
PRO_E_DTMPLN_FIT_TYPE          Fit Type       PRO_VALUE_TYPE_INT       ProDtmplnFitType
PRO_E_DTMPLN_FIT_REF           Reference      PRO_VALUE_TYPE_SELECTION See Note 2
PRO_E_DTMPLN_FIT_DTM_RAD       Datum Radius   PRO_VALUE_TYPE_DOUBLE    >= 0.0
PRO_E_DTMPLN_FIT_OUTLINE       Fit Outline    The element is not accessible through Creo Parametric TOOLKIT
--------------------------------------------------------------------------------------------
 
 
   Note 1.   Constraint reference types:
 
   Constraint Type     Valid Reference Types
   ---------------------------------------------------------------------
   PRO_DTMPLN_THRU       PRO_AXIS, PRO_EDGE, PRO_CURVE, Channel, PRO_POINT,
                         PRO_EDGE_START, PRO_EDGE_END, PRO_CRV_START,
                         PRO_CRV_END, PRO_SURFACE (Plane, Cylinder)
   PRO_DTMPLN_NORM       PRO_AXIS, PRO_EDGE, PRO_CURVE, Channel,
                         PRO_SURFACE (Plane)
   PRO_DTMPLN_PRL        PRO_SURFACE (Plane)
   PRO_DTMPLN_OFFS       PRO_SURFACE (Plane), PRO_CSYS
   PRO_DTMPLN_ANG        PRO_SURFACE (Plane)
   PRO_DTMPLN_TANG       PRO_SURFACE (Cylinder)
   PRO_DTMPLN_SEC        PRO_FEATURE (Blend)
   PRO_DTMPLN_DEF_X      No reference needed
   PRO_DTMPLN_DEF_Y      No reference needed
   PRO_DTMPLN_DEF_Z      No reference needed
   PRO_DTMPLN_MIDPLN     Planar Reference Type: PRO_SURFACE,
                         Linear Reference Types: PRO_AXIS, PRO_EDGE, PRO_CURVE,
                         Point Reference Types: PRO_POINT, PRO_EDGE_START,
                         PRO_EDGE_END, PRO_CRV_START, PRO_CRV_END
   PRO_DTMPLN_BISECTOR1  Planar Reference Type: PRO_SURFACE,
                         Linear Reference Types: PRO_AXIS, PRO_EDGE, PRO_CURVE
   PRO_DTMPLN_BISECTOR2  Planar Reference Type: PRO_SURFACE,
                         Linear Reference Types: PRO_AXIS, PRO_EDGE, PRO_CURVE

 
   Note 2.   Fit reference types:
 
   Fit Type                Valid Reference Types
   ----------------------------------------------
   PRO_DTMPLN_FIT_DEFAULT  --
   PRO_DTMPLN_FIT_PART     PRO_PART
   PRO_DTMPLN_FIT_FEATURE  PRO_FEATURE
   PRO_DTMPLN_FIT_SURFACE  PRO_SURFACE
   PRO_DTMPLN_FIT_EDGE     PRO_EDGE
   PRO_DTMPLN_FIT_AXIS     PRO_AXIS
   PRO_DTMPLN_FIT_RADIUS   --
   PRO_DTMPLN_FIT_OUTLINE  --

\*****************************************************************************/

/* 1. PRO_E_DTMPLN_CONSTR_TYPE */

typedef enum pro_dtmpln_constr_type
{
   PRO_DTMPLN_THRU = 0,
   PRO_DTMPLN_NORM,
   PRO_DTMPLN_PRL,
   PRO_DTMPLN_OFFS,
   PRO_DTMPLN_ANG,
   PRO_DTMPLN_TANG,
   PRO_DTMPLN_SEC,
   PRO_DTMPLN_DEF_X,
   PRO_DTMPLN_DEF_Y,
   PRO_DTMPLN_DEF_Z,
   PRO_DTMPLN_THRU_CSYS_XY,
   PRO_DTMPLN_THRU_CSYS_YZ,
   PRO_DTMPLN_THRU_CSYS_ZX,
   PRO_DTMPLN_MIDPLN,
   PRO_DTMPLN_BISECTOR1,
   PRO_DTMPLN_BISECTOR2
} ProDtmplnConstrType;

/* 2. PRO_E_DTMPLN_OFF_CSYS */

typedef enum pro_dtmpln_off_csys_axis
{
   PRO_DTMPLN_OFF_CSYS_X = 1,
   PRO_DTMPLN_OFF_CSYS_Y,
   PRO_DTMPLN_OFF_CSYS_Z
} ProDtmplnOffCsysAxis;

/* PRO_E_DTMPLN_FLIP_DIR */

typedef enum pro_dtmpln_flip_dir 
{
   PRO_DTMPLN_FLIP_DIR_NO = 0 ,
   PRO_DTMPLN_FLIP_DIR_YES = 1
} ProDtmplnFlipDir ;

/* 3. PRO_E_DTMPLN_FIT_TYPE */

typedef enum pro_dtmpln_fit_type
{
   PRO_DTMPLN_FIT_DEFAULT = -1,
   PRO_DTMPLN_FIT_PART,
   PRO_DTMPLN_FIT_FEATURE,
   PRO_DTMPLN_FIT_SURFACE,
   PRO_DTMPLN_FIT_EDGE,
   PRO_DTMPLN_FIT_AXIS,
   PRO_DTMPLN_FIT_RADIUS,

   PRO_DTMPLN_FIT_OUTLINE = 12 

} ProDtmplnFitType;


PRO_END_C_DECLS
 
#endif
