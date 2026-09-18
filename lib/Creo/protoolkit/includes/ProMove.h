#ifndef PROMOVEH
#define PROMOVEH
 

 
#include <ProToolkit.h>
#include <ProDirection.h>
#include <ProFeature.h>
 
PRO_BEGIN_C_DECLS
 
 
 
/*****************************************************************************\
 
Feature element tree
 
  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_SRF_TRANS_TYPE
    |
    |--PRO_E_STD_FEATURE_NAME
    |
    |--PRO_E_SRF_TR_SURF_SELECTION
    |
    |--PRO_E_MOVE_WITH_COPY
    |
    |--PRO_E_MOVE_GEOM_TRF_ARR
         |
         |--PRO_E_MOVE_GEOM_TRF
              |
              |--PRO_E_SRF_TR_MOVE_TYPE
              |--PRO_E_DIRECTION_COMPOUND
              |--PRO_E_SRF_TR_VAL_ELEM




Feature elements table
 
------------------------------------------------------------------------------------------------
Element Id                	Element Name          	Data Type        		
------------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE            Feature Type        PRO_VALUE_TYPE_INT

PRO_E_SRF_TRANS_TYPE          Transform Type      PRO_VALUE_TYPE_INT

PRO_E_STD_FEATURE_NAME        Feature Name        PRO_VALUE_TYPE_WSTRING

PRO_E_SRF_TR_SURF_SELECTION   Surface Selection   PRO_VALUE_TYPE_SELECTION
                                                  ( Multivalued Element )

PRO_E_MOVE_WITH_COPY          move with copy      PRO_VALUE_TYPE_INT

PRO_E_MOVE_GEOM_TRF_ARR       Sets                Array

PRO_E_MOVE_GEOM_TRF           Set                 Compound

PRO_E_SRF_TR_MOVE_TYPE        move type           PRO_VALUE_TYPE_INT

PRO_E_DIRECTION_COMPOUND      Direction           Compound

PRO_E_SRF_TR_VAL_ELEM         offset_or_angle     PRO_VALUE_TYPE_DOUBLE


-------------------------------------------------------------------------
Table Move:1 : Common element for all type of Move and it's value
-------------------------------------------------------------------------
| Element Id              	| Value                                   |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_FEATURE_TYPE          | = PRO_FEAT_SRF_MDL                      |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_SRF_TRANS_TYPE        | = PRO_SURF_TRANS_TYPE_MOVE              |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_SRF_TR_SURF_SELECTION | PRO_CURVE, PRO_COMP_CRV, PRO_AXIS,      |
|                             | PRO_QUILT, PRO_DATUM_PLANE,             |
|                             | PRO_POINT, PRO_CSYS                     |
|                             | (Refer Note#1)                          |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_MOVE_WITH_COPY        | = PRO_MOVE_KEEP_ORIGINAL                |
|                             | = PRO_MOVE_HIDE_ORIGINAL                |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_MOVE_GEOM_TRF_ARR     | Array element                           |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_MOVE_GEOM_TRF         | Compound element                        |
|                             | One element per set present in          |
|                             | PRO_E_MOVE_GEOM_TRF_ARR                 |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_SRF_TR_MOVE_TYPE      | = PRO_MOVE_TYPE_TRANS                   |
|                             |   for Translate                         |
|                             | = PRO_MOVE_TYPE_ROT                     |
|                             |   for Rotate                            |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_DIRECTION_COMPOUND    | For more details refer ProDirection.h   |
|                             |                                         |
-------------------------------------------------------------------------
|                             |                                         |
| PRO_E_SRF_TR_VAL_ELEM       | Double Value                            |
|                             |                                         |
-------------------------------------------------------------------------

Table Move:2 Elements required for Move
-------------------------------------------------------------------------
|          | Element Id                      | Comment                  |
-------------------------------------------------------------------------
| Move     : PRO_E_FEATURE_TYPE              : Mandatory                |
|          : PRO_E_SRF_TRANS_TYPE            : Mandatory                |
|          : PRO_E_STD_FEATURE_NAME          : Optional                 |
|          : PRO_E_SRF_TR_SURF_SELECTION     : Mandatory                |
|          : PRO_E_MOVE_WITH_COPY            : Mandatory                |
|          : PRO_E_SRF_TR_MOVE_TYPE          : Mandatory                |
|          : PRO_E_DIRECTION_COMPOUND        : Mandatory                |
|          : PRO_E_SRF_TR_VAL_ELEM           : Mandatory                |
|-----------------------------------------------------------------------|


Note 1 : In Pro/ENGINEER Wildfire 2.0, the PRO_E_SRF_TR_SURF_SELECTION of 
         PRO_FEATURE type are not supported.

\*****************************************************************************/

typedef enum pro_move_type
{
   PRO_MOVE_TYPE_TRANS 	= 0,
   PRO_MOVE_TYPE_ROT 	= 1

} ProMoveType;


typedef enum pro_move_no_copy
{
   PRO_MOVE_NO_COPY	 	= 0,
   PRO_MOVE_MAKE_COPY		= 1

} ProMoveNoCopy;

typedef enum pro_move_with_copy
{
   PRO_MOVE_KEEP_ORIGINAL 	= 0,
   PRO_MOVE_HIDE_ORIGINAL	= 1

} ProMoveWithCopy;


PRO_END_C_DECLS
 
#endif
