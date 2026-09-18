#ifndef PRODTMCRV
#define PRODTMCRV

/*
   Creo Parametric TOOLKIT declarations related to datum curve feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************\

////////////////////////////// SKETCHED /////////////////////////////////////////
Feature - sketched

(1) Feature element tree 

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_ATTRIBUTES
     |    |--PRO_E_DTMCRV_DISPLAY_HATCH     if type = sketch (optional)
     |    |--PRO_E_DTMCRV_HATCH_DENSITY     if type = sketch and display hatch = yes.
     
(2) Feature elements table

--------------------------------------------------------------------------------
Element Id                  Element Name   Data Type                Valid Values
--------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE            Curve Type     PRO_VALUE_TYPE_INT       ProCurveType
PRO_E_STD_FEATURE_NAME      Feature Name   PRO_VALUE_TYPE_WSTRING   
PRO_E_STD_SECTION           Section        Compound                 see ProStdSection.h
PRO_E_ATTRIBUTES            Attributes     Compound                 see Note 1
PRO_E_DTMCRV_DISPLAY_HATCH  X-hatching     PRO_VALUE_TYPE_INT       PRO_B_TRUE, PRO_B_FALSE
PRO_E_DTMCRV_HATCH_DENSITY  Density        PRO_VALUE_TYPE_DOUBLE
--------------------------------------------------------------------------------

(3) Notes

Note 1: The element PRO_E_ATTRIBUTES and its subelements are directly
	dependent upon the presence of a fully defined PRO_E_STD_SECTION
	element tree (including PRO_E_SKETCHER).
	Values assigned to these elements before fully defining the
	PRO_E_STD_SECTION will be ignored.


Table 1 Notes for Elements required for Sketch Datum Curve
-----------------------------------------------------------------------
| Element Id                 | Comment                                |
-----------------------------------------------------------------------
| PRO_E_STD_SECTION          : Mandatory. Its following sub-elements  |
|                            : must be defined to complete feature:   |
|                            : |                                      |
|                            : |-PRO_E_STD_SEC_SETUP_PLANE            |
|                            : |   |--PRO_E_STD_SEC_PLANE             |
|                            : |   |--PRO_E_STD_SEC_PLANE_VIEW_DIR    |
|                            : |   |--PRO_E_STD_SEC_PLANE_ORIENT_DIR  |
|                            : |   |--PRO_E_STD_SEC_PLANE_ORIENT_REF  |
|                            : |-PRO_E_SKETCHER                       |
|............................:........................................|
| PRO_E_ATTRIBUTES           : Optional. Defined only                 |
|                            : if PRO_E_STD_SECTION is defined.       |
|                            : |                                      |
|                            : |-PRO_E_ATTRIBUTES                     |
|                            : |   |--PRO_E_DTMCRV_DISPLAY_HATCH      |
|                            : |   |--PRO_E_DTMCRV_HATCH_DENSITY      |
|---------------------------------------------------------------------|

Table 2 Notes for Attributes (PRO_E_ATTRIBUTES)
-----------------------------------------------------------------------
| Element Id                 | Comment                                |
-----------------------------------------------------------------------
| PRO_E_DTMCRV_DISPLAY_HATCH : Optional of type PRO_VALUE_TYPE_INT.   |
|                            : It can be PRO_B_TRUE or PRO_B_FALSE    |
|............................:........................................|
| PRO_E_DTMCRV_HATCH_DENSITY : It is of type PRO_VALUE_TYPE_DOUBLE.   |
|                            : Defined only if                        |
|                            : PRO_E_DTMCRV_DISPLAY_HATCH is set to   |
|                            : PRO_B_TRUE                             |
|---------------------------------------------------------------------|



////////////////////////////// TRIM ////////////////////////////////////////////
Feature - Trim Curve ( aliases: Split Curve )

(1) Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_TRIM_SPLIT_CURVE
     |
     |--PRO_E_CRV_TRIM_DIVIDER    
     |
     |--PRO_E_CRV_TRIM_SPLIT_SIDE 

(2) Feature elements table

----------------------------------------------------------------------------------
Element Id                  Element Name   Data Type                Valid Values
----------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE            Curve Type     PRO_VALUE_TYPE_INT       ProCurveType
PRO_E_STD_FEATURE_NAME      Feature Name   PRO_VALUE_TYPE_WSTRING   
PRO_E_STD_CRV_SPLIT_CURVE   Curve          PRO_VALUE_TYPE_SELECTION PRO_CURVE
PRO_E_STD_CRV_SPLIT_DIVIDER Divider        PRO_VALUE_TYPE_SELECTION PRO_EDGE,PRO_QUILT,
                                                                    PRO_SURFACE, PRO_CURVE,
                                                                    PRO_POINT, PRO_DATUM_PLANE 
PRO_E_STD_CRV_SPLIT_SIDE    Side To Keep   PRO_VALUE_TYPE_INT       ProSplitSides
----------------------------------------------------------------------------------

(3) Notes

-----------------------------------------------------------------------
Element Id                    Comment
-----------------------------------------------------------------------
PRO_E_CURVE_TYPE             =PRO_CURVE_TYPE_SPLIT
.......................................................................
PRO_E_CRV_TRIM_SPLIT_SIDE    Mandatory. See ProSplitSides     
.......................................................................
PRO_E_CRV_TRIM_SPLIT_CURVE   Mandatory. Trimmed Curve reference
.......................................................................
PRO_E_CRV_TRIM_DIVIDER       Mandatory. Divider reference      
-----------------------------------------------------------------------


////////////////////////////// INTERSECT ////////////////////////////////////////
Feature - Intersect Curve ( aliases: Intersect Surfaces Curve and 
                                     Two Projections Curve)
(1) Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_IP_REF_TYPE
     |
     |--PRO_E_CRV_IP_COMP_REF1
     |    |--PRO_E_CRV_IP_REF1
     |    |--PRO_E_CRV_IP_REF_SEL1_TYPE
     |
     |--PRO_E_CRV_IP_COMP_REF2
     |    |--PRO_E_CRV_IP_REF2
     |    |--PRO_E_CRV_IP_REF_SEL2_TYPE
     |
     |--PRO_E_CRV_IP_COMP_SEC1
     |    |--PRO_E_STD_SECTION
     |--PRO_E_CRV_IP_COMP_SEC2
     |    |--PRO_E_STD_SECTION
     
(2) Feature elements table

-----------------------------------------------------------------------------------
Element Id                  Element Name    Data Type                Valid Values
-----------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type    PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE            Curve Type      PRO_VALUE_TYPE_INT       ProCurveType
PRO_E_STD_FEATURE_NAME      Feature Name    PRO_VALUE_TYPE_WSTRING   
PRO_E_CRV_IP_REF_TYPE       Reference Type  PRO_VALUE_TYPE_INT
PRO_E_CRV_IP_COMP_REF1      Comp ref1       Compound
PRO_E_CRV_IP_REF1           Surfaces1       PRO_VALUE_TYPE_SELECTION PRO_QUILT,PRO_SURFACE,
                                                                     PRO_DATUM_PLANE,
                                                                     PRO_SOLID_GEOMETRY 
PRO_E_CRV_IP_REF_SEL1_TYPE  Selection type1 PRO_VALUE_TYPE_INT       ProCrvIpSelType
PRO_E_CRV_IP_COMP_REF2      Comp ref2       Compound
PRO_E_CRV_IP_REF2           Surfaces2       PRO_VALUE_TYPE_SELECTION PRO_QUILT,PRO_SURFACE,
                                                                     PRO_DATUM_PLANE,
                                                                     PRO_SOLID_GEOMETRY
PRO_E_CRV_IP_REF_SEL2_TYPE  Selection type2 PRO_VALUE_TYPE_INT       ProCrvIpSelType
PRO_E_CRV_IP_COMP_SEC1      Comp sec1       Compound
PRO_E_STD_SECTION           Section1        Compound
PRO_E_CRV_IP_COMP_SEC2      Comp sec2       Compound
PRO_E_STD_SECTION           Section2        Compound
-----------------------------------------------------------------------------------

(3) Notes

Table 1 Notes for common elements
-----------------------------------------------------------------------------
Element Id                    Comment
-----------------------------------------------------------------------------
PRO_E_CURVE_TYPE              =PRO_CURVE_TYPE_INTSRF   for Intersect Surfaces
                              =PRO_CURVE_TYPE_TWO_PROJ for Two Projections
..............................................................................                              
PRO_E_CRV_IP_REF_TYPE         same value as PRO_E_CURVE_TYPE
                              PRO_CURVE_TYPE_INTSRF/PRO_CURVE_TYPE_TWO_PROJ              
-----------------------------------------------------------------------------


Table 2 Notes for Intersect Surfaces ( PRO_CURVE_TYPE_INTSRF )
---------------------------------------------------------------------------------------
Element Id                    Comment
---------------------------------------------------------------------------------------
PRO_E_CRV_IP_COMP_REF1        Compound
.......................................................................................                              
PRO_E_CRV_IP_REF1             Reference 1  (multiple selections if
                              PRO_E_CRV_IP_REF_SEL1_TYPE = PRO_CURVE_TYPE_MULTIPLE_SEL) 
.......................................................................................                              
PRO_E_CRV_IP_REF_SEL1_TYPE    See ProCrvIpSelType
                              PRO_CURVE_TYPE_WHOLE indicates that PRO_E_CRV_IP_REF1
                              contains only one selection of types PRO_QUILT,
                              PRO_DATUM_PLANE,PRO_SOLID_GEOMETRY
                              PRO_CURVE_TYPE_MULTIPLE_SEL indicates that PRO_E_CRV_IP_REF1
                              contains any number of selections of type PRO_SURFACE
........................................................................................                              
PRO_E_CRV_IP_COMP_REF2        Compound
........................................................................................                              
PRO_E_CRV_IP_REF2             Reference 2  
                              see comment for PRO_E_CRV_IP_REF1
........................................................................................                              
PRO_E_CRV_IP_REF_SEL2_TYPE    See ProCrvIpSelType 
                              see comment for PRO_E_CRV_IP_REF_SEL1_TYPE
---------------------------------------------------------------------------------------


Table 3 Notes for Two Projections ( PRO_CURVE_TYPE_TWO_PROJ )
-----------------------------------------------------------------------------
Element Id                    Comment
-----------------------------------------------------------------------------
PRO_E_CRV_IP_COMP_SEC1        Compound
..............................................................................                              
PRO_E_STD_SECTION             Section 1
..............................................................................                              
PRO_E_CRV_IP_COMP_SEC2        Compound
..............................................................................                              
PRO_E_STD_SECTION             Section 2
------------------------------------------------------------------------------


//////////////////////////////// WRAP /////////////////////////////////////////
Feature - Wrap Curve ( aliases: Formed Curve)

(1) Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_WRAP_SRF_TYPE
     |
     |--PRO_E_CRV_WRAP_SRF
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_CRV_WRAP_FLIP
     |
     |--PRO_E_CRV_WRAP_COORD_SYS
     |
     |--PRO_E_CRV_WRAP_TRIM
     |
     |--PRO_E_CRV_WRAP_STAY_ON_SURF

(2) Feature elements table

-----------------------------------------------------------------------------------
Element Id                  Element Name    Data Type                Valid Values
-----------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type    PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE            Curve Type      PRO_VALUE_TYPE_INT       ProCurveType
PRO_E_STD_FEATURE_NAME      Feature Name    PRO_VALUE_TYPE_WSTRING   
PRO_E_CRV_WRAP_SRF_TYPE     Surface type    PRO_VALUE_TYPE_INT       ProWrapSrfType
PRO_E_CRV_WRAP_SRF          Wrap Surface    PRO_VALUE_TYPE_SELECTION PRO_QUILT,
                                                                     PRO_SOLID_GEOMETRY
PRO_E_STD_SECTION           Section         Compound
PRO_E_CRV_WRAP_FLIP         Direction flip  PRO_VALUE_TYPE_INT       ProWrapFlip
PRO_E_CRV_WRAP_COORD_SYS    Coord System Id PRO_VALUE_TYPE_INT
PRO_E_CRV_WRAP_TRIM         Trim curve      PRO_VALUE_TYPE_INT       ProWrapTrim
PRO_E_CRV_WRAP_STAY_ON_SURF Stay on surface PRO_VALUE_TYPE_INT       proWrapStay
------------------------------------------------------------------------------------

(3) Notes

-----------------------------------------------------------------------
Element Id                    Comment
-----------------------------------------------------------------------
PRO_E_CURVE_TYPE              =PRO_CURVE_TYPE_WRAP
.......................................................................
PRO_E_CRV_WRAP_SRF_TYPE       Mandatory, see ProWrapSrfType
.......................................................................
PRO_E_CRV_WRAP_SRF            Mandatory, destination of Wrap,
                              Solid or Quilt surface
.......................................................................
PRO_E_STD_SECTION             Mandatory, curve to wrap
.......................................................................
PRO_E_CRV_WRAP_FLIP           Required if ambiguity of wrap direction 
                              exists
.......................................................................
PRO_E_CRV_WRAP_COORD_SYS      Mandatory, start point of wrapping -
                              external id of Coordinate Systemin Sketch, 
                              or 0 if Center of Sketch is used

Important: This element is dependent upon the presence of a fully defined
           PRO_E_STD_SECTION element tree. Values assigned to this element
           before fully defining the PRO_E_STD_SECTION will be ignored.
.......................................................................
PRO_E_CRV_WRAP_TRIM           Mandatory, stop wrapping on non-developing
                              edge or fail a feature, yes or no
.......................................................................
PRO_E_CRV_WRAP_STAY_ON_SURF   Mandatory, indicates whether to ignore inner
                              contours and shells for fake lines, yes or no
-----------------------------------------------------------------------



////////////////////////////// OFFSET //////////////////////////////////////////
Feature - Offset Curve ( aliases: Offset From Surface, Offset Curve = Offset Quilt(aka HULL) )

(1) Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_OFFS_FEAT_TYPE
     |
     |--PRO_E_DATUM_CURVE_REF_TO_CRV
     |
     |--PRO_E_CRV_OFFS_CRV_REF
     |
     |--PRO_E_CRV_OFFS_SRF_REF
     |
     |--PRO_E_STD_CURVE_COLLECTION_APPL
     |
     |--PRO_E_CRV_OFFS_DIR_FLIP
     |
     |--PRO_E_CRV_OFFS_GRAPH_REF
     |
     |--PRO_E_CRV_OFFS_ST_END
     |
     |--PRO_E_DATUM_CURVE_OFFSET_VAL
     |
     |--PRO_E_DATUM_CURVE_CURVE_MENU
     |    |--PRO_E_STD_CURVE_COLLECTION_APPL
     |    |--PRO_E_DATUM_CURVE_IS_CONSTANT
     |    |--PRO_E_DATUM_CURVE_NO_OF_CURVES
     |    |--PRO_E_DATUM_CURVE_M_DIR
     |    |--PRO_E_DATUM_CURVE_REF_PLANE
     |    |--PRO_E_DATUM_CURVE_VAR_OFFSET_TAB
     |         |--PRO_E_DATUM_CURVE_VAR_OFFSET_CMP
     |              |--PRO_E_DATUM_CURVE_VAR_OFFSET_REF
     |              |--PRO_E_DATUM_CURVE_VAR_OFFSET_VAL
     
(2) Feature elements table

--------------------------------------------------------------------------------------
Element Id                        Element Name     Data Type                Valid Values
--------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type     PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE                  Curve Type       PRO_VALUE_TYPE_INT       ProCurveType
PRO_E_STD_FEATURE_NAME            Feature Name     PRO_VALUE_TYPE_WSTRING   
PRO_E_CRV_OFFS_FEAT_TYPE          Feat Subtype     PRO_VALUE_TYPE_INT       ProOffsetFeatType
PRO_E_DATUM_CURVE_REF_TO_CRV      Ref to crv       PRO_VALUE_TYPE_INT       ProHullDtmcrvRefCurvesOpts
PRO_E_CRV_OFFS_CRV_REF            Curve Select     PRO_VALUE_TYPE_SELECTION PRO_CURVE
PRO_E_CRV_OFFS_SRF_REF            Quilt/Surface    PRO_VALUE_TYPE_SELECTION PRO_QUILT,PRO_SURFACE
PRO_E_STD_CURVE_COLLECTION_APPL   Curve Offset     PRO_VALUE_TYPE_POINTER   Curve collection
PRO_E_CRV_OFFS_DIR_FLIP           Direction Flip   PRO_VALUE_TYPE_INT       ProOffsetDirFlip
PRO_E_CRV_OFFS_GRAPH_REF          Graph Select     PRO_VALUE_TYPE_SELECTION PRO_FEATURE
PRO_E_CRV_OFFS_ST_END             Start Graph Pnt  PRO_VALUE_TYPE_INT       ProOffsetStEnd
PRO_E_DATUM_CURVE_OFFSET_VAL      Offset value     PRO_VALUE_TYPE_DOUBLE
PRO_E_DATUM_CURVE_CURVE_MENU      Curve Menu       Compound
PRO_E_STD_CURVE_COLLECTION_APPL   Second fan curve PRO_VALUE_TYPE_POINTER   Curve collection
PRO_E_DATUM_CURVE_IS_CONSTANT     Is_constant      PRO_VALUE_TYPE_INT
PRO_E_DATUM_CURVE_NO_OF_CURVES    Number of curves PRO_VALUE_TYPE_INT
PRO_E_DATUM_CURVE_M_DIR           Measurement Dir  PRO_VALUE_TYPE_INT       ProHullDtmcrvMeasureDirOpts
PRO_E_DATUM_CURVE_REF_PLANE       Reference Plane  PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_DATUM_CURVE_VAR_OFFSET_TAB  Var Offset Table Array
PRO_E_DATUM_CURVE_VAR_OFFSET_CMP  Variable Offset  Compound
PRO_E_DATUM_CURVE_VAR_OFFSET_REF  Plane/Point      PRO_VALUE_TYPE_SELECTION PRO_SURFACE, PRO_POINT
PRO_E_DATUM_CURVE_VAR_OFFSET_VAL  Value            PRO_VALUE_TYPE_DOUBLE
-------------------------------------------------------------------------------------

(3) Notes

Table 1 Notes for common elements
---------------------------------------------------------------------------------------
Element Id                        Comment
---------------------------------------------------------------------------------------
PRO_E_CURVE_TYPE                 =PRO_CURVE_TYPE_OFFSET_IN_QUILT
                                 =PRO_CURVE_TYPE_OFFSET
.......................................................................................
PRO_E_CRV_OFFS_FEAT_TYPE         see ProOffsetFeatType
                                 PRO_OFFSET_TANGENT same as PRO_CURVE_TYPE_OFFSET_IN_QUILT
                                 PRO_OFFSET_FROM_SURFACE same as PRO_CURVE_TYPE_OFFSET
........................................................................................
PRO_E_CRV_OFFS_SRF_REF           Mandatory, surface or quilt
........................................................................................
PRO_E_CRV_OFFS_DIR_FLIP          Mandatory, see ProOffsetDirFlip
........................................................................................
PRO_E_DATUM_CURVE_OFFSET_VAL     Mandatory constant offset or scale
----------------------------------------------------------------------------------------

Table 2 Notes for  PRO_CURVE_TYPE_OFFSET 
-----------------------------------------------------------------------------
Element Id                       Comment
-----------------------------------------------------------------------------
PRO_E_CRV_OFFS_CRV_REF           Mandatory.
.............................................................................
PRO_E_CRV_OFFS_GRAPH_REF         Mandatory. Pass NULL to use the unit graph as a reference.
.............................................................................
PRO_E_CRV_OFFS_ST_END            Mandatory, see ProOffsetStEnd
-----------------------------------------------------------------------------

All other elements in the element tree are ignored when PRO_E_CURVE_TYPE is
PRO_CURVE_TYPE_OFFSET.



Table 3 Notes for  PRO_CURVE_TYPE_OFFSET_IN_QUILT 
----------------------------------------------------------------------------------------
Element Id                       Comment
----------------------------------------------------------------------------------------
This curve type contains data not yet accessible in Creo Parametric TOOLKIT.  
Creation, access and redefinition are not yet supported.
----------------------------------------------------------------------------------------



////////////////////////////// TANGENT OFFSET //////////////////////////////////////////
Feature - Offset Curve ( aliases: From Curve  )

This curve type is preserved for accessing legacy data created in 
previous Creo Parametric releases.  Creation of new Tangent Offset features 
is not supported.

(1) Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_TANG_OFFSET_CURVE
     |
     |--PRO_E_CRV_TANG_OFFSET_SURF
     |
     |--PRO_E_CRV_TANG_OFFSET_DIST
     |
     |--PRO_E_CRV_TANG_OFFSET_DIR
     
(2) Feature elements table

--------------------------------------------------------------------------------------
Element Id                        Element Name     Data Type                Valid Values
--------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE                Feature Type     PRO_VALUE_TYPE_INT       PRO_FEAT_CURVE
PRO_E_CURVE_TYPE                  Curve Type       PRO_VALUE_TYPE_INT       ProCurveType
PRO_E_STD_FEATURE_NAME            Feature Name     PRO_VALUE_TYPE_WSTRING   
PRO_E_CRV_TANG_OFFSET_CURVE       Curve Select     PRO_VALUE_TYPE_SELECTION PRO_CURVE
PRO_E_CRV_TANG_OFFSET_SURF        Quilt/Surface    PRO_VALUE_TYPE_SELECTION PRO_QUILT,PRO_SURFACE
PRO_E_CRV_TANG_OFFSET_DIR         Direction Flip   PRO_VALUE_TYPE_INT       ProOffsetDirection      
PRO_E_CRV_TANG_OFFSET_DIST        Offset value     PRO_VALUE_TYPE_DOUBLE
-------------------------------------------------------------------------------------

(3) Notes

---------------------------------------------------------------------------------------
Element Id                        Comment
---------------------------------------------------------------------------------------
PRO_E_CURVE_TYPE                 =PRO_CURVE_TYPE_TANGENT_OFFSET
........................................................................................
PRO_E_CRV_TANG_OFFSET_CURVE       Mandatory, curve
........................................................................................
PRO_E_CRV_TANG_OFFSET_SURF        Mandatory, surface or quilt
........................................................................................
PRO_E_CRV_TANG_OFFSET_DIR         Mandatory flip, see ProOffsetDirection
........................................................................................
PRO_E_CRV_TANG_OFFSET_DIST        Mandatory constant offset
----------------------------------------------------------------------------------------

//////////////////// FROM XSEC     /////////////////////////////////////////////////
Feature : Curve from Xsec

(1) Feature element tree

  PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_FROM_XSEC_REF_XSEC

(2) Feature element table

------------------------------------------------------------------------------------------
Element Id                    Element Name        Data Type                  Valid Values
------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE            Feature Type        PRO_VALUE_TYPE_INT         PRO_FEAT_CURVE
PRO_E_CURVE_TYPE              Curve Type          PRO_VALUE_TYPE_INT         ProCurveType
PRO_E_STD_FEATURE_NAME        Feature Name        PRO_VALUE_TYPE_WSTRING   
PRO_E_CRV_FROM_XSEC_REF_XSEC  Xsec Reference      PRO_VALUE_TYPE_SELECTION   PRO_XSEC
------------------------------------------------------------------------------------------

(3) Notes

-----------------------------------------------------------------------
Element Id                    Comment
-----------------------------------------------------------------------
PRO_E_CRV_FROM_XSEC_REF_XSEC  Mandatory.  Xsec reference
-----------------------------------------------------------------------


//////////////////// FROM EQUATION /////////////////////////////////////////////////
Feature : Curve from equation

(1) Feature element tree

  PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_CURVE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_CRV_FR_EQ_REF_CSYS
     |
     |--PRO_E_CRV_FR_EQ_CSYS_TYPE
     |
     |--PRO_E_CRV_FR_EQ_PARAM_MIN
     |
     |--PRO_E_CRV_FR_EQ_PARAM_MAX
     |
     |--PRO_E_CRV_ENTER_EQUATION
     
(2) Feature element table

---------------------------------------------------------------------------------------
Element Id                  Element Name        Data Type                  Valid Values
---------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE          Feature Type        PRO_VALUE_TYPE_INT         PRO_FEAT_CURVE
PRO_E_CURVE_TYPE            Curve Type          PRO_VALUE_TYPE_INT         ProCurveType
PRO_E_STD_FEATURE_NAME      Feature Name        PRO_VALUE_TYPE_WSTRING   
PRO_E_CRV_FR_EQ_REF_CSYS    CSYS                PRO_VALUE_TYPE_SELECTION   PRO_CSYS
PRO_E_CRV_FR_EQ_CSYS_TYPE   Coord System Type   PRO_VALUE_TYPE_INT         ProCrvFrEquatCsysTypes  
PRO_E_CRV_FR_EQ_PARAM_MIN   Parameter minimum   PRO_VALUE_TYPE_DOUBLE
PRO_E_CRV_FR_EQ_PARAM_MAX   Parameter maximum   PRO_VALUE_TYPE_DOUBLE
PRO_E_CRV_ENTER_EQUATION    Equations           PRO_VALUE_TYPE_WSTRING
---------------------------------------------------------------------------------------

(3) Notes

-----------------------------------------------------------------------
Element Id                    Comment
-----------------------------------------------------------------------
PRO_E_CRV_FR_EQ_REF_CSYS      Mandatory.  Curve reference
.......................................................................
PRO_E_CRV_FR_EQ_CSYS_TYPE     Mandatory.  Coordinate system type    
.......................................................................
PRO_E_CRV_FR_EQ_PARAM_MIN     Mandatory.  Parameter minimum
.......................................................................
PRO_E_CRV_FR_EQ_PARAM_MAX     Mandatory.  Parameter maximum
.......................................................................
PRO_E_CRV_ENTER_EQUATION      Mandatory.  Curve equations      
-----------------------------------------------------------------------



Note:   More types to follow.
\*****************************************************************************/

typedef enum Pro_Curve_Type
{
   PRO_CURVE_TYPE_NONE            = -1,
   PRO_CURVE_TYPE_SKETCHED        =  0,
   PRO_CURVE_TYPE_INTSRF          =  2,
   PRO_CURVE_TYPE_FROM_XSEC       =  6,
   PRO_CURVE_TYPE_WRAP            =  9,
   PRO_CURVE_TYPE_SPLIT           = 12,
   PRO_CURVE_TYPE_OFFSET          = 13,
   PRO_CURVE_TYPE_TWO_PROJ        = 15,
   PRO_CURVE_TYPE_TANGENT_OFFSET  = 18,
   PRO_CURVE_TYPE_FROM_EQUATION   = 27,
   PRO_CURVE_TYPE_OFFSET_IN_QUILT = 52
} ProCurveType;

typedef enum pro_split_sides
{
   PRO_SPLIT_SIDES_SIDE_ONE   = 1,
   PRO_SPLIT_SIDES_BOTH_SIDES = 0,
   PRO_SPLIT_SIDES_SIDE_TWO   = -1
} ProSplitSides;

typedef enum pro_offset_start_pnt
{
   PRO_OFFSET_START_PNT_START = 1,
   PRO_OFFSET_START_PNT_END   = -1
} ProOffsetStartPnt;

typedef enum pro_offset_direction
{
   PRO_OFFSET_DIR_SIDE_ONE   = 1,
   PRO_OFFSET_DIR_SIDE_TWO   = -1
} ProOffsetDirection;


typedef enum pro_crv_ip_sel_type
{
   PRO_CURVE_TYPE_MULTIPLE_SEL = 1,
   PRO_CURVE_TYPE_WHOLE = 2 
} ProCrvIpSelType;

typedef enum pro_wrap_srf_type
{
   PRO_WRAP_SOLID_SRF = 1,
   PRO_WRAP_QUILT = 2 
} ProWrapSrfType;

typedef enum pro_wrap_flip
{
   PRO_WRAP_FLIP_POS = 0,
   PRO_WRAP_FLIP_NEG = 1 
} ProWrapFlip;

typedef enum pro_wrap_trim
{
   PRO_WRAP_DONT_TRIM = 0,
   PRO_WRAP_TRIM      = 1
} ProWrapTrim;

typedef enum pro_wrap_stay
{
   PRO_WRAP_STAY      = 0,
   PRO_WRAP_DONT_STAY = 1
} ProWrapStay;

typedef enum pro_compst_crv_type
{
   PRO_COMPST_EXACT  = 1,
   PRO_COMPST_APPROX = 2 
} ProCompstCrvType;

typedef enum pro_compst_crv_chain_index
{
   PRO_COMPST_CHAIN_INDEX = 0
} ProCompstCrvChainIndex;

typedef enum pro_projcrv_crv_type
{
  PRO_PROJCRV_CURVE       = 0,
  PRO_PROJCRV_SKETCH      = 1,
  PRO_PROJCRV_COSM_SKETCH = 2
} ProProjCrvCrvType;

typedef enum pro_projcrv_follow_srf_opt
{
   PRO_PROJCRV_FOLLOW_SRF_NO   = 0,
   PRO_PROJCRV_FOLLOW_SRF_YES  = 1
} ProProjCrvFollowSrfOpt;

typedef enum pro_proj_sel_dir_type
{
   PRO_PROJ_SEL_DIR_ALONGDIR     = 0,
   PRO_PROJ_SEL_DIR_NORM2SRF     = 1 
} ProProjSelDirType;

typedef enum pro_proj_sketch_dir_type
{
   PRO_PROJ_SKETCH_DIR_NORM2SKETCH     = 0,
   PRO_PROJ_SKETCH_DIR_NORM2SRF        = 1 
} ProProjSketchDirType;

typedef enum pro_offset_feat_type
{
   PRO_OFFSET_TANGENT        = 0,
   PRO_OFFSET_FROM_SURFACE   = 1,
   PRO_OFFSET_BOUNDARY       = 2
} ProOffsetFeatType;

typedef enum pro_proj_offset_dir_flip
{
   PRO_OFFSET_DIR_FLIP_OK     = 0,
   PRO_OFFSET_DIR_FLIP_FLIP   = 1 
} ProOffsetDirFlip;

typedef enum pro_proj_offset_st_end
{
   PRO_OFFSET_ST_GRAPH     = 0,
   PRO_OFFSET_END_GRAPH   = 1 
} ProOffsetStEnd;

typedef enum _ProHullDtmcrvRefCurvesOpts
{
    PRO_HULL_DTMCRV_REF_CURVES_OPTS_ONE_CURVE   =  40,
    PRO_HULL_DTMCRV_REF_CURVES_OPTS_TWO_CURVES  =  41
} ProHullDtmcrvRefCurvesOpts;

typedef enum _ProHullDtmcrvMeasureDirOpts
{
    PRO_HULL_DTMCRV_MEASURE_DIR_OPTS_NORMAL_TO_CURVE    =  46,
    PRO_HULL_DTMCRV_MEASURE_DIR_OPTS_ALONG_YOZ_PLANE    =  47,
    PRO_HULL_DTMCRV_MEASURE_DIR_OPTS_PARALLEL_TO_PLANE  =  48
} ProHullDtmcrvMeasureDirOpts;

typedef enum _ProCrvFrEquatCsysTypes
{
    PRO_CRV_FR_EQ_CSYS_TYPE_CARTESIAN   = 0,
    PRO_CRV_FR_EQ_CSYS_TYPE_CYLINDRICAL = 1,
    PRO_CRV_FR_EQ_CSYS_TYPE_SPHERICAL   = 2
}ProCrvFrEquatCsysTypes;

PRO_END_C_DECLS

#endif
