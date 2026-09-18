#ifndef PROD3ELEM_H
#define PROD3ELEM_H



#include <ProToolkit.h>
#include <ProElement.h>
#include <ProObjects.h>

PRO_BEGIN_C_DECLS

/*===========================================================================
  D3 Tree branch. 

  Used by features which utilize 3d transformation steps, usually using the
  3D Dragger. (e.g. FlexMove)
 
=============================================================================*/



/*===============================================================================================

(1) Element tree

    PRO_E_D3ELEM_SETS
       |
       |-- PRO_E_D3ELEM_SET
              |
              |-- PRO_E_D3ELEM_PLACEMENT_REFERENCE
              |
              |-- PRO_E_D3ELEM_ORIENTATION_REFERENCE
              |
              |-- PRO_E_D3ELEM_LOCATION
              |
              |-- PRO_E_D3ELEM_MOVES
                     |
                     |-- PRO_E_D3ELEM_MOVE
                            |
                            |-- PRO_E_D3ELEM_MOVE_TYPE
                            |
                            |-- PRO_E_D3ELEM_MOVE_VALUE

=================================================================================================

(2) Elements table

-------------------------------------------------------------------------------------------------
 Element Id                        Element Name            Data Type                 Valid Values
-------------------------------------------------------------------------------------------------
PRO_E_D3ELEM_SETS                  Sets                    Array holder
PRO_E_D3ELEM_SET                   Set                     Compound
PRO_E_D3ELEM_PLACEMENT_REFERENCE   Placement Reference     PRO_VALUE_TYPE_SELECTION  Note-1
PRO_E_D3ELEM_ORIENTATION_REFERENCE Orientation Reference   PRO_VALUE_TYPE_SELECTION  Note-2
PRO_E_D3ELEM_LOCATION              Location                PRO_VALUE_TYPE_INT        Note-3
PRO_E_D3ELEM_MOVES                 Moves                   Array holder
PRO_E_D3ELEM_MOVE                  Move                    Compound
PRO_E_D3ELEM_MOVE_TYPE             Move Type               PRO_VALUE_TYPE_INT        Note-4
PRO_E_D3ELEM_MOVE_VALUE            Move Value              PRO_VALUE_TYPE_DOUBLE     Note-5

=================================================================================================

(3) Notes

   Note-1  : PRO_E_D3ELEM_PLACEMENT_REFERENCE: Optional.
             ===========================================

             Possible selection types are

             SEL_3D_SRF,  SEL_3D_EDG, SEL_3D_AXIS, SEL_3D_CSYS,  
             SEL_3D_PNT,  SEL_3D_VERT, SEL_3D_CURVE, SEL_CURVE_END.

             In case of an empty value for the placement reference, the default 
             placement reference will be used.


   Note-2  : PRO_E_D3ELEM_ORIENTATION_REFERENCE: Optional.
             =============================================

             Possible selection types are

             SEL_3D_SRF,  SEL_3D_EDG, SEL_3D_AXIS, SEL_3D_CSYS, SEL_3D_CURVE.

             In case of an empty value for the orientation reference, the default 
             orientation reference will be used, according to the placement reference.

   Note-3  : PRO_E_D3ELEM_LOCATION: Optional.
             =================================

             Possible values are:

             PRO_D3_LOCATION_MOVING - The default value, the Set's coordinate 
                                      system moves with each "Move" made in the set.

             PRO_D3_LOCATION_FIXED  - This value can be set only if the placement
                                      reference and the orientation reference are
                                      selected both to be the same coordinate
                                      system. (SEL_3D_CSYS).
                                      
                                      When this value is set, the Set's coordinate system
                                      retains its position and orientation, as "Moves" are
                                      being made. Each "Move" begins from this fixed coordinate
                                      system.


   Note-4  : PRO_E_D3ELEM_MOVE_TYPE: Mandatory.
             ==================================
        
             Possible values are:

             PRO_D3_MOVE_TYPE_UNDEFINED

             PRO_D3_MOVE_TYPE_XMOVE     - Move along the current coordinate
                                          system's X vector.

             PRO_D3_MOVE_TYPE_YMOVE     - Move along the current coordinate
                                          system's Y vector.

             PRO_D3_MOVE_TYPE_ZMOVE     - Move along the current coordinate
                                          system's Z vector.

             PRO_D3_MOVE_TYPE_XROTATE   - Rotate around the current coordinate
                                          system's X vector.

             PRO_D3_MOVE_TYPE_YROTATE   - Rotate around the current coordinate
                                          system's Y vector.

             PRO_D3_MOVE_TYPE_ZROTATE   - Rotate around the current coordinate
                                          system's Z vector.

             PRO_D3_MOVE_TYPE_SURF      - Move to a uv coordinate on a surface.
                                          This move type is relevant only if the
                                          move set is placed on a surface.
                                          Please use these API functions:
                                            ProFeatureD3elemUvSet()
                                            ProFeatureD3elemUvGet()

             PRO_D3_MOVE_TYPE_EDGE      - Move to a u (ratio parameter) coordinate
                                          on an edge.
                                          This move type is possible only if the
                                          move set is placed on an edge.
                                          Please use these API functions:
                                            ProFeatureD3elemRatioSet()
                                            ProFeatureD3elemRatioGet()

             PRO_D3_MOVE_TYPE_FREE      - Move using a transformation matrix.
                                          This move type is relevant if the
                                          placement and orientation references
                                          of the set are empty (default).

             PRO_D3_MOVE_TYPE_FREETRF   - Same as PRO_D3_MOVE_TYPE_FREE, but
                                          instead of storing final position,
                                          tranformation matrix is stored.

   Note-5  : PRO_E_D3ELEM_MOVE_VALUE: Mandatory.
             ==================================

             Value ranges:
               For linear move types  : [-1e6,1e6]
               For angular move types : [0,360]

==============================================================================*/

/* PRO_E_D3ELEM_LOCATION Possible Values */
#define PRO_D3_LOCATION_MOVING     0
#define PRO_D3_LOCATION_FIXED      1

/* PRO_E_D3ELEM_MOVE_TYPE Possible Values */
#define PRO_D3_MOVE_TYPE_UNDEFINED 0
#define PRO_D3_MOVE_TYPE_XMOVE     1
#define PRO_D3_MOVE_TYPE_YMOVE     2
#define PRO_D3_MOVE_TYPE_ZMOVE     3
#define PRO_D3_MOVE_TYPE_XROTATE   4
#define PRO_D3_MOVE_TYPE_YROTATE   5
#define PRO_D3_MOVE_TYPE_ZROTATE   6
#define PRO_D3_MOVE_TYPE_SURF      7
#define PRO_D3_MOVE_TYPE_EDGE      8
#define PRO_D3_MOVE_TYPE_FREE      9
#define PRO_D3_MOVE_TYPE_FREETRF   10


/* D3Elem API Prototypes */

extern ProError ProFeatureD3elemUvSet( ProElement elem_move, 
                                       ProUvParam position_uv );
/*
   Purpose:  Set the position UV parameter for PRO_E_D3ELEM_MOVE_VALUE 
             element on a surface or plane.

   Input Arguments:
      elem_move       -  The PRO_E_D3ELEM_MOVE_VALUE id element.
      position_uv     -  The position UV parameter on surface or plane.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function succeeded. 
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProFeatureD3elemUvGet( ProElement elem_move, 
                                       ProUvParam position_uv );
/*
   Purpose:  Get the position UV parameter for PRO_E_D3ELEM_MOVE_VALUE 
             element on a surface or plane.

   Input Arguments:
      elem_move       -  The PRO_E_D3ELEM_MOVE_VALUE id element.	  

   Output Arguments:
      position_uv     -  The position UV parameter on surface or plane.

   Return Values:
      PRO_TK_NO_ERROR       - The function succeeded. 
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProFeatureD3elemRatioSet( ProElement elem_move, 
                                          double     ratio );
/*
   Purpose:  Set the position ratio for PRO_E_D3ELEM_MOVE_VALUE element on an 
             edge or entity.

   Input Arguments:
      elem_move       -  The PRO_E_D3ELEM_MOVE_VALUE id element.
      ratio           -  The position ratio on edge or entity.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function succeeded. 
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProFeatureD3elemRatioGet( ProElement elem_move, 
                                          double*    ratio );
/*
   Purpose:  Get the position ratio for PRO_E_D3ELEM_MOVE_VALUE element on 
             an edge or entity.

   Input Arguments:
      elem_move       -  The PRO_E_D3ELEM_MOVE_VALUE id element.

   Output Arguments:
      ratio           -  The position ratio on edge or entity.

   Return Values:
      PRO_TK_NO_ERROR       - The function succeeded. 
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid
      PRO_TK_GENERAL_ERROR  - The function failed.
*/


extern ProError ProFeatureD3elemMatrixSet( ProElement elem_move, 
                                           ProMatrix  delta );
/*
   Purpose:  Set the position delta matrix for PRO_E_D3ELEM_MOVE_VALUE element

   Input Arguments:
      elem_move       -  The PRO_E_D3ELEM_MOVE_VALUE id element.
      delta           -  The position delta matrix.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR       - The function succeeded. 
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProFeatureD3elemMatrixGet( ProElement elem_move, 
                                           ProMatrix  delta );
/*
   Purpose:  Get the position delta matrix for PRO_E_D3ELEM_MOVE_VALUE element

   Input Arguments:
      elem_move       -  The PRO_E_D3ELEM_MOVE_VALUE id element.	  

   Output Arguments:
      delta           -  The position delta matrix.

   Return Values:
      PRO_TK_NO_ERROR       - The function succeeded. 
      PRO_TK_BAD_INPUTS     - One or more of the input arguments are invalid
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

PRO_END_C_DECLS

#endif

