#ifndef PROECADAREAH
#define PROECADAREAH



/*
   Creo Parametric TOOLKIT declarations related to ECAD area feature.
*/

PRO_BEGIN_C_DECLS

/*****************************************************************************\

###############################################################################
#################################### ECAD AREA ################################
###############################################################################

1.Feature element tree:
=======================
 
   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_IS_ECAD_AREA
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_ECAD_AREA_TYPE
     |
     |--PRO_E_STD_SECTION
     |
     |--PRO_E_ECAD_AREA_3D_VOLUME
     |
     |--PRO_E_ECAD_AREA_DEPTH_TYPE
     |
     |--PRO_E_ECAD_AREA_DEPTH
     |
     |--PRO_E_ECAD_AREA_DEPTH2
     |
     |--PRO_E_ECAD_AREA_XHATCH
     |
     |--PRO_E_ECAD_AREA_TRIM_BNDRS
     |
     |--PRO_E_ECAD_AREA_COLOR
     |
     |--PRO_E_ECAD_AREA_USER_DEF_TYPE


2.Feature elements table:
=========================

==================================================================================
Element Id                     Element Name                Data Type     
==================================================================================
PRO_E_FEATURE_TYPE             Feature Type                PRO_VALUE_TYPE_INT      
PRO_E_IS_ECAD_AREA             Is ECAD Area                PRO_VALUE_TYPE_INT   
PRO_E_STD_FEATURE_NAME         Feature Name                PRO_VALUE_TYPE_WSTRING    
PRO_E_ECAD_AREA_TYPE           Area Type                   PRO_VALUE_TYPE_INT       
PRO_E_STD_SECTION              Section                     Compound                 
PRO_E_ECAD_AREA_3D_VOLUME      3D Volume                   PRO_VALUE_TYPE_BOOLEAN
PRO_E_ECAD_AREA_DEPTH_TYPE     Depth Option                PRO_VALUE_TYPE_INT       
PRO_E_ECAD_AREA_DEPTH          Depth                       PRO_VALUE_TYPE_DOUBLE    
PRO_E_ECAD_AREA_DEPTH2         Depth2                      PRO_VALUE_TYPE_DOUBLE   
PRO_E_ECAD_AREA_XHATCH         Xhatch                      PRO_VALUE_TYPE_BOOLEAN
PRO_E_ECAD_AREA_TRIM_BNDRS     Trim To Boundaries          PRO_VALUE_TYPE_BOOLEAN
PRO_E_ECAD_AREA_COLOR          Color                       PRO_VALUE_TYPE_POINTER
PRO_E_ECAD_AREA_USER_DEF_TYPE  User defined area type name PRO_VALUE_TYPE_WSTRING
==================================================================================

+------------------------------------------------------------------------+
| Element Id                    | Value                                  |
|------------------------------------------------------------------------|
| PRO_E_FEATURE_TYPE            | PRO_FEAT_COSMETIC                      |
|...............................|........................................|
| PRO_E_IS_ECAD_AREA            | PRO_B_TRUE( must be true in order to   |
|                               | differ it from other cosmetic features)|
|...............................|........................................|
| PRO_E_STD_FEATURE_NAME        | Any                                    |
|...............................|........................................|
| PRO_E_ECAD_AREA_TYPE          | ProEcadAreaType                        |
|...............................|........................................|
| PRO_E_STD_SECTION             | Compound Element                       |
|...............................|........................................|
| PRO_E_ECAD_AREA_3D_VOLUME     | ProBoolean                             |
|...............................|........................................|
| PRO_E_ECAD_AREA_DEPTH_TYPE    | ProEcadAreaDepthType                   |
|...............................|........................................|
| PRO_E_ECAD_AREA_DEPTH         | Double                                 |
|...............................|........................................|
| PRO_E_ECAD_AREA_DEPTH2        | Double                                 |
|...............................|........................................|
| PRO_E_ECAD_AREA_XHATCH        | ProBoolean                             |
|...............................|........................................|
| PRO_E_ECAD_AREA_TRIM_BNDRS    | ProBoolean                             |
|...............................|........................................|
| PRO_E_ECAD_AREA_COLOR         | PRO_VALUE_TYPE_POINTER(void*)          |
|...............................|........................................|
| PRO_E_ECAD_AREA_USER_DEF_TYPE | Any                                    |
+------------------------------------------------------------------------+



******************************************************************************/

/* 1. PRO_E_ECAD_AREA_TYPE */

typedef enum pro_ecad_area_type
{
   PRO_ECAD_AREA_TYPE_PLACE_KEEPIN   = 0,
   PRO_ECAD_AREA_TYPE_PLACE_KEEPOUT  = 1,     
   PRO_ECAD_AREA_TYPE_PLACE_REGION   = 2,     
   PRO_ECAD_AREA_TYPE_ROUTE_KEEPIN   = 3,     
   PRO_ECAD_AREA_TYPE_ROUTE_KEEPOUT  = 4,     
   PRO_ECAD_AREA_TYPE_VIA_KEEPOUT    = 5,
   PRO_ECAD_AREA_TYPE_FLEX_REGION    = 6,
   PRO_ECAD_AREA_TYPE_USER_DEFINED   = 7
} ProEcadAreaType;


/* 2. PRO_E_ECAD_AREA_DEPTH_TYPE */

typedef enum pro_ecad_area_depth_type
{ 
   PRO_ECAD_AREA_DEPTH_ONE_SIDE           =  0,
   PRO_ECAD_AREA_DEPTH_TWO_SIDES_SYM      =  1,
   PRO_ECAD_AREA_DEPTH_TWO_SIDES_NOT_SYM  =  2
} ProEcadAreaDepthType;



extern ProError ProElementEcadAreaProColorSet( ProElement treeElement, 
                                               ProColor   *proColor );
/*
     Purpose:  Set the ProColor in the tree element.
               This should be used for PRO_E_ECAD_AREA_COLOR element.

     Input Arguments:
            treeElement     - The ecad area element tree
            proColor        - Specify a defined ProColor structure whose data 
                              will be copied to the PRO_E_ECAD_AREA_COLOR 
                              element data. On redefining the element tree, 
                              the data from the ProColor structure will be 
                              used for the ECAD area color.

     Output Arguments:
            none

     Return Values:
            PRO_TK_NO_ERROR     - The function succeeded.
            PRO_TK_NOT_VALID    - The element did not contain the right type.
            PRO_TK_INVALID_TYPE - The ProColortype is invalid.
            PRO_TK_OUT_OF_RANGE - The RGB values are out of range.
            PRO_TK_UNSUPPORTED  - The ecad area do not have color setting support.
            PRO_TK_BAD_INPUTS   - One or more input arguments are invalid.
*/


extern ProError ProElementEcadAreaProColorGet( ProElement treeElement, 
                                               ProColor   *proColor );
/*
     Purpose:  Get the ProColor from the tree element.
               This should be used for PRO_E_ECAD_AREA_COLOR element.

     Input Arguments:
            treeElement     - The ecad area element tree

     Output Arguments:
            proColor        - The ProColor used for ecad area. 

     Return Values:
            PRO_TK_NO_ERROR     - The function succeeded.
            PRO_TK_NOT_VALID    - The element did not contain the right type.
            PRO_TK_UNSUPPORTED  - The ecad area do not have color setting support.
            PRO_TK_BAD_INPUTS   - One or more input arguments are invalid.
*/
PRO_END_C_DECLS

#endif
