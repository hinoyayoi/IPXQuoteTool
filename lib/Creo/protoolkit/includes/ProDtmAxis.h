#ifndef PRODTMAXISH
#define PRODTMAXISH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************\

     PRO_E_FEATURE_TREE
       |
       |--PRO_E_FEATURE_TYPE
       |
       |--PRO_E_STD_FEATURE_NAME         (Optional)
       |
       |--PRO_E_DTMAXIS_CONSTRAINTS      (Array of PRO_E_DTMAXIS_CONSTRAINT)
       |    |--PRO_E_DTMAXIS_CONSTRAINT
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE
       |         |--PRO_E_DTMAXIS_CONSTR_REF
       |
       |--PRO_E_DTMAXIS_DIM_CONSTRAINTS  (Array of PRO_E_DTMAXIS_DIM_CONSTRAINT)
       |    |--PRO_E_DTMAXIS_DIM_CONSTRAINT
       |         |--PRO_E_DTMAXIS_DIM_CONSTR_REF
       |         |--PRO_E_DTMAXIS_DIM_CONSTR_VAL 
       |--PRO_E_DTMAXIS_FIT              (Optional)
            |--PRO_E_DTMAXIS_FIT_TYPE
            |--PRO_E_DTMAXIS_FIT_REF  If FIT_TYPE = PRO_DTMAXIS_FIT_REFERENCE
            |--PRO_E_DTMAXIS_FIT_LEN  If FIT_TYPE = PRO_DTMAXIS_FIT_LENGTH


Feature elements table
--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type                Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_DATUM_AXIS
PRO_E_STD_FEATURE_NAME         Feature Name   PRO_VALUE_TYPE_WSTRING
PRO_E_DTMAXIS_CONSTRAINTS      Constraints    Array
PRO_E_DTMAXIS_CONSTRAINT       Constraint     Compound
PRO_E_DTMAXIS_CONSTR_TYPE      Type           PRO_VALUE_TYPE_INT       See ProDtmaxisConstrType
PRO_E_DTMAXIS_CONSTR_REF       Reference      PRO_VALUE_TYPE_SELECTION See Table 1 below.
PRO_E_DTMAXIS_DIM_CONSTRAINTS  Constraints    Array
PRO_E_DTMAXIS_DIM_CONSTRAINT   Constraint     Compound
PRO_E_DTMAXIS_DIM_CONSTR_VAL   Offset         PRO_VALUE_TYPE_DOUBLE    Valid dimension value. 
PRO_E_DTMAXIS_DIM_CONSTR_REF   Reference      PRO_VALUE_TYPE_SELECTION PRO_AXIS, PRO_EDGE, PRO_SURFACE
PRO_E_DTMAXIS_FIT              Fit            Compound
PRO_E_DTMAXIS_FIT_TYPE         Fit Type       PRO_VALUE_TYPE_INT       See ProDtmaxisFitType
PRO_E_DTMAXIS_FIT_REF          Reference      PRO_VALUE_TYPE_SELECTION PRO_PART, PRO_FEATURE, PRO_SURFACE, PRO_EDGE, PRO_AXIS
PRO_E_DTMAXIS_FIT_LEN          Length         PRO_VALUE_TYPE_DOUBLE    Valid dimension value.


---------------------------------------------------------------------
---------------------------------------------------------------------
Table 1:   Valid Values for PRO_E_DTMAXIS_CONSTR_REF:

Constraint Type                   Valid Reference Types
---------------------------------------------------------------------
PRO_DTMAXIS_CONSTR_TYPE_THRU     PRO_AXIS, PRO_EDGE (Straight), PRO_CURVE, PRO_POINT,
                                  PRO_EDGE_START, PRO_EDGE_END, PRO_CRV_START,
                                  PRO_CRV_END, PRO_SURFACE (Cylinder)
PRO_DTMAXIS_CONSTR_TYPE_NORMAL   PRO_SURFACE 
PRO_DTMAXIS_CONSTR_TYPE_TANGENT  PRO_EDGE, PRO_CURVE

---------------------------------------------------------------------
---------------------------------------------------------------------
Table 2: Mapping between legacy elements (below) and constraints elements

Legacy Element                   Constraints Element
----------------------------------------------------------
PRO_E_DTMAXIS_PNTVTX1            PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS) 
PRO_E_DTMAXIS_PNTVTX2            PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_PLANE1             PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_PLANE2             PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_CURVE_EDGE         PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_PNTVTX             PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_PLANE              PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_SURF               PRO_E_DTMAXIS_CONSTR_REF (Constraint 1 or 2 in PRO_E_DTMAXIS_CONSTRAINTS)
PRO_E_DTMAXIS_TYPE               See PRO_E_DTMAXIS_TYPE Mapping below
PRO_E_DIM_REF1                   PRO_E_DTMAXIS_DIM_CONSTR_REF (Constraint 1 in PRO_E_DTMAXIS_DIM_CONSTRAINTS)
PRO_E_DIM_REF2                   PRO_E_DTMAXIS_DIM_CONSTR_REF (Constraint 2 in PRO_E_DTMAXIS_DIM_CONSTRAINTS)
PRO_E_DIM_REF_DIST1              PRO_E_DTMAXIS_DIM_CONSTR_VAL (Constraint 1 in PRO_E_DTMAXIS_DIM_CONSTRAINTS)
PRO_E_DIM_REF_DIST2              PRO_E_DTMAXIS_DIM_CONSTR_VAL (Constraint 2 in PRO_E_DTMAXIS_DIM_CONSTRAINTS)

PRO_E_DTMAXIS_TYPE Mapping:
----------------------------------
There is no single element that indicates type in constraints element tree. 
Instead, type is determined implicitly according to the following:

1.   PRO_DTMAXIS_PNT_SURF:
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 1)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU 
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_POINT
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 2)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_NORMAL
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_SURFACE

2.   PRO_DTMAXIS_TANGENT:
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 1)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_TANGENT
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_EDGE, PRO_CURVE
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 2)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_POINT, PRO_EDGE_START, PRO_EDGE_END, 
                                                                  PRO_CRV_START, PRO_CRV_END

3.   PRO_DTMAXIS_THROUGH:
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 1)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU 
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_EDGE (Straight), PRO_SURFACE(Cylinder)  

4.   PRO_DTMAXIS_TWO_PLN:
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 1)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_SURFACE (Planar)
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 2)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_SURFACE (Planar)

5.   PRO_DTMAXIS_TWO_PNT:
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 1)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_POINT, PRO_EDGE_START, PRO_EDGE_END,
                                                                  PRO_CRV_START, PRO_CRV_END
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 2)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_THRU
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_POINT, PRO_EDGE_START, PRO_EDGE_END,
                                                                  PRO_CRV_START, PRO_CRV_END

6.   PRO_DTMAXIS_NORM_PLN:
       |    |--PRO_E_DTMAXIS_CONSTRAINT                        (Constraint 1)
       |         |--PRO_E_DTMAXIS_CONSTR_TYPE                  PRO_DTMAXIS_CONSTR_TYPE_NORMAL
       |         |--PRO_E_DTMAXIS_CONSTR_REF                   PRO_SURFACE (Planar)
       |    |--PRO_E_DTMAXIS_DIM_CONSTRAINT                    (Constraint 1)
       |         |--PRO_E_DTMAXIS_DIM_CONSTR_REF               PRO_SURFACE (Planar), PRO_AXIS, PRO_EDGE 
       |         |--PRO_E_DTMAXIS_DIM_CONSTR_VAL               Valid dimension
       |    |--PRO_E_DTMAXIS_DIM_CONSTRAINT                    (Constraint 2)
       |         |--PRO_E_DTMAXIS_DIM_CONSTR_REF               PRO_SURFACE (Planar), PRO_AXIS, PRO_EDGE
       |         |--PRO_E_DTMAXIS_DIM_CONSTR_VAL               Valid dimension

\*****************************************************************************/



typedef enum  pro_dtmaxis_constraint_type
{
  PRO_DTMAXIS_CONSTR_TYPE_NORMAL
, PRO_DTMAXIS_CONSTR_TYPE_THRU
, PRO_DTMAXIS_CONSTR_TYPE_TANGENT
, PRO_DTMAXIS_CONSTR_TYPE_CENTER
, PRO_DTMAXIS_CONSTR_TYPE_PARALLEL
} ProDtmaxisConstrType;

typedef enum pro_dtmaxis_fit_type
{
   PRO_DTMAXIS_FIT_DEFAULT
,  PRO_DTMAXIS_FIT_REFERENCE
,  PRO_DTMAXIS_FIT_LENGTH
} ProDtmaxisFitType;


/*****************************************************************************\
The following element tree was used in release 2001 and earlier 
and is provided for legacy purposes only.  Users are advised 
not to use this element tree for feature creation or modification
activities anymore.
 
Feature element tree
 
   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_DTMAXIS_TYPE
     |
     |--PRO_E_DTMAXIS_REFS
          |--PRO_E_DTMAXIS_PNTVTX1        If type == Two points
          |--PRO_E_DTMAXIS_PNTVTX2        If type == Two points
          |--PRO_E_DTMAXIS_PLANE1         If type == Two planes
          |--PRO_E_DTMAXIS_PLANE2         If type == Two planes
          |--PRO_E_DTMAXIS_EDGE_SRF_CSYS  If type == Through
          |--PRO_E_DTMAXIS_CSYS_AXIS      If type == Through
          |--PRO_E_DTMAXIS_CURVE_EDGE     If type == Tangent
          |--PRO_E_DTMAXIS_PNTVTX         If type == Tangent
          |--PRO_E_DTMAXIS_PLANE          If type == Normal plane
          |--PRO_E_DTMAXIS_DIM_REF1       If type == Normal plane
          |--PRO_E_DTMAXIS_DIM_REF_DIST1  If type == Normal plane
          |--PRO_E_DTMAXIS_DIM_REF2       If type == Normal plane
          |--PRO_E_DTMAXIS_DIM_REF_DIST2  If type == Normal plane
          |--PRO_E_DTMAXIS_PNT            If type == Point and surface
          |--PRO_E_DTMAXIS_SURF           If type == Point and surface
 
Feature elements table
 
--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type                Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_DATUM_AXIS
PRO_E_DTMAXIS_TYPE             Type           PRO_VALUE_TYPE_INT       see ProDtmAxisType
PRO_E_DTMAXIS_REFS             References     Compound                
PRO_E_DTMAXIS_PNTVTX1          Point/Vertex 1 PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_PNTVTX2          Point/Vertex 2 PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_PLANE1           Plane 1        PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_PLANE2           Plane 2        PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_EDGE_SRF_CSYS    Edge/Surface/Csys PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_CSYS_AXIS        Csys Axis      PRO_VALUE_TYPE_INT       see ProDtmAxisCsysAxis
PRO_E_DTMAXIS_CURVE_EDGE       Curve/Edge     PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_PNTVTX           Point/Vertex   PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_PLANE            Plane          PRO_VALUE_TYPE_SELECTION
PRO_E_DIM_REF1                 Dimension Ref1 PRO_VALUE_TYPE_SELECTION
PRO_E_DIM_REF_DIST1            Distance 1     PRO_VALUE_TYPE_DOUBLE
PRO_E_DIM_REF2                 Dimension Ref2 PRO_VALUE_TYPE_SELECTION
PRO_E_DIM_REF_DIST2            Distance 2     PRO_VALUE_TYPE_DOUBLE
PRO_E_DTMAXIS_PNT              Point          PRO_VALUE_TYPE_SELECTION
PRO_E_DTMAXIS_SURF             Surface        PRO_VALUE_TYPE_SELECTION

\*****************************************************************************/

/* 1. PRO_E_DTMAXIS_TYPE */

typedef enum pro_dtm_axis_type
{
   PRO_DTMAXIS_NORM_PLN = 0,
   PRO_DTMAXIS_PNT_SURF,
   PRO_DTMAXIS_TANGENT,
   PRO_DTMAXIS_THROUGH,
   PRO_DTMAXIS_TWO_PLN,
   PRO_DTMAXIS_TWO_PNT,
   PRO_DTMAXIS_CENTER
} ProDtmAxisType;

/* 2. PRO_E_DTMAXIS_CSYS_AXIS */

typedef enum pro_dtm_axis_csys_axis
{
   PRO_DTMAXIS_CSYS_AXIS_X = 1,
   PRO_DTMAXIS_CSYS_AXIS_Y,
   PRO_DTMAXIS_CSYS_AXIS_Z
} ProDtmAxisCsysAxis;


PRO_END_C_DECLS
 
#endif
