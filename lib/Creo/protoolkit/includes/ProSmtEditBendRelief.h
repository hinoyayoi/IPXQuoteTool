#ifndef PROEDITBENDRELIEF_H
#define PROEDITBENDRELIEF_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_STD_FEATURE_NAME
    |
    |--PRO_E_EDIT_BEND_RELIEF
         |
         |--PRO_E_EDIT_BEND_RELIEF_SEL_MODE
         |
         |--PRO_E_EDIT_BEND_RELIEF_GEOMS
         |
         |--PRO_E_EDIT_BEND_RELIEF_SHAPE
         |    |
         |    |--PRO_E_BEND_RELIEF_TYPE
         |    |
         |    |--PRO_E_BEND_RELIEF_WIDTH
         |    |
         |    |--PRO_E_BEND_RELIEF_DEPTH_TYPE
         |    |
         |    |--PRO_E_BEND_RELIEF_DEPTH
         |
         |--PRO_E_EDIT_BEND_RELIEF_TABLE
              |
              |--PRO_E_BEND_RELIEF_RMV_SETTINGS
                   |
                   |--PRO_E_BEND_RELIEF_VERTEX
                   |
                   |--PRO_E_BEND_RELIEF_RMV_SIDES
                   |
                   |--PRO_E_BEND_RELIEF_RMV_DEFAULT
                   |
                   |--PRO_E_BEND_RELIEF_RMV_METHOD
                   |
                   |--PRO_E_BEND_RELIEF_RMV_REF_TYPE

===============================================================================

(2) Feature elements table

------------------------------------------------------------------------------
  Element Id                      Element Name          Data Type
------------------------------------------------------------------------------  PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_EDIT_BEND_RELIEF	          Edit Bend Relief      Compound
PRO_E_EDIT_BEND_RELIEF_SEL_MODE   Selection Mode        PRO_VALUE_TYPE_INT
PRO_E_EDIT_BEND_RELIEF_GEOMS      Bend Relief Geometry  Multi Collector
PRO_E_EDIT_BEND_RELIEF_SHAPE      Bend Relief Shape     Compound
PRO_E_BEND_RELIEF_TYPE            Type                  PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_WIDTH           Width                 PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_DEPTH_TYPE      Depth Type            PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_DEPTH           Depth                 PRO_VALUE_TYPE_DOUBLE
PRO_E_EDIT_BEND_RELIEF_TABLE      Bend Reliefs List     Array
PRO_E_BEND_RELIEF_RMV_SETTINGS    Removal Settings      Compound
PRO_E_BEND_RELIEF_VERTEX          Bend Relief Vertex    PRO_VALUE_TYPE_SELECTION
PRO_E_BEND_RELIEF_RMV_SIDES       Bounding Sides        Multi Collector
PRO_E_BEND_RELIEF_RMV_DEFAULT     Default Removal       PRO_VALUE_TYPE_BOOLEAN
PRO_E_BEND_RELIEF_RMV_METHOD      Removal Method        PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_RMV_REF_TYPE    Removal Reference     PRO_VALUE_TYPE_INT
===============================================================================

(3) Element Values Table

-------------------------------------------------------------------------------
 Element Id                      Element Name           Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE		 Feature Type         PRO_FEAT_EDIT_BEND_RELIEF
PRO_E_STD_FEATURE_NAME           Feature Name                See Note 1
PRO_E_EDIT_BEND_RELIEF           Edit Bend Relief
PRO_E_EDIT_BEND_RELIEF_SEL_MODE  Selection Mode              See Note 2
PRO_E_EDIT_BEND_RELIEF_GEOMS     Bend Relief Geometry        See Note 3
PRO_E_EDIT_BEND_RELIEF_SHAPE     Bend Relief Shape
PRO_E_BEND_RELIEF_TYPE           Type                        See Note 4
PRO_E_BEND_RELIEF_WIDTH          Width                       See Note 5
PRO_E_BEND_RELIEF_DEPTH_TYPE     Depth Type                  See Note 6
PRO_E_BEND_RELIEF_DEPTH          Depth                       See Note 7
PRO_E_EDIT_BEND_RELIEF_TABLE     Bend Reliefs List           See Note 8
PRO_E_BEND_RELIEF_RMV_SETTINGS   Removal Settings            See Note 8
PRO_E_BEND_RELIEF_VERTEX         Bend Relief Vertex          See Note 8
PRO_E_BEND_RELIEF_RMV_SIDES      Bounding Sides              See Note 8
PRO_E_BEND_RELIEF_RMV_DEFAULT    Default Removal             See Note 8
PRO_E_BEND_RELIEF_RMV_METHOD     Removal Method              See Note 8
PRO_E_BEND_RELIEF_RMV_REF_TYPE   Removal Reference           See Note 8
===============================================================================

(4) Mapping Table

-------------------------------------------------------------------------------
 Element Name                    Comment
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE               Mandatory
PRO_E_STD_FEATURE_NAME           Mandatory
PRO_E_EDIT_BEND_RELIEF           Mandatory
PRO_E_EDIT_BEND_RELIEF_SEL_MODE  Mandatory
PRO_E_EDIT_BEND_RELIEF_GEOMS     See Note 3
PRO_E_EDIT_BEND_RELIEF_SHAPE     Mandatory
PRO_E_BEND_RELIEF_TYPE           Mandatory
PRO_E_BEND_RELIEF_WIDTH          See Note 5
PRO_E_BEND_RELIEF_DEPTH_TYPE     See Note 6
PRO_E_BEND_RELIEF_DEPTH          See Note 7
PRO_E_EDIT_BEND_RELIEF_TABLE     See Note 8
PRO_E_BEND_RELIEF_RMV_SETTINGS   See Note 8
PRO_E_BEND_RELIEF_VERTEX         See Note 8
PRO_E_BEND_RELIEF_RMV_SIDES      See Note 8
PRO_E_BEND_RELIEF_RMV_DEFAULT    See Note 8
PRO_E_BEND_RELIEF_RMV_METHOD     See Note 8
PRO_E_BEND_RELIEF_RMV_REF_TYPE   See Note 8
===============================================================================

(5) Notes

  Note-1  : Edit Bend Relief feature name. Default is "EDIT_BEND_RELIEF".

  Note-2  : Selection Mode might be
            PRO_SMT_RECOGNITION_MANUAL_SEL or PRO_SMT_RECOGNITION_AUTO_SEL.

  Note-3  : Bend Relief Geometry is unnecessary when Selection Type is
            PRO_SMT_RECOGNITION_AUTO_SEL and it is mandatory otherwise.
	    Existing bend reliefs, surfaces, intent surfaces, thickness
            edges or bend edge vertexes can be selected.
            Side surfaces have to belong to recognizable bend reliefs.
            Thickness edges have to exit bend edge vertexes. Thickness edges
            can not be used if a Bend Relief or a side surface can be selected.
            Vertexes can not be used if a Bend Relief, a side surface or
            a thickness edge can be selected.

  Note-4  : Type might be PRO_BEND_RLF_RIP, PRO_BEND_RLF_RECTANGULAR
            or PRO_BEND_RLF_OBROUND.

  Note-5  : Width is mandatory when Type is not PRO_BEND_RLF_RIP.
            Positive non zero values only are allowed.
  Note-6  : Depth Type is mandatory when Type is not PRO_BEND_RLF_RIP.
            It might be PRO_BEND_RLF_DEPTH_BLIND, PRO_BEND_RLF_DEPTH_UP_TO_BEND
            or PRO_BEND_RLF_DEPTH_TAN_TO_BEND.
	    PRO_BEND_RLF_DEPTH_TAN_TO_BEND is valid
            when Type is PRO_BEND_RLF_OBROUND.
  Note-7  : Depth is mandatory when Depth Type is PRO_BEND_RLF_DEPTH_BLIND.
            Positive or zero values only are allowed.
            Depth is measured from a bend edge.

  Note-8  : For internal usage only.

==============================================================================*/

typedef enum
{
  PRO_BR_RMV_METHOD_NOT_DEF     = -1,
  PRO_BR_RMV_METHOD_NONE        = 1,
  PRO_BR_RMV_METHOD_SAME        = 2,
  PRO_BR_RMV_METHOD_TANG        = 4,
  PRO_BR_RMV_METHOD_LINEAR      = 8

} ProBendRlfRmvMethod;

typedef enum
{
  PRO_BR_RMV_REF_NOT_DEF                = -1,
  PRO_BR_RMV_REF_UP_TO_BEND_SIDE        = 64,
  PRO_BR_RMV_REF_UP_TO_BEND_START       = 128,
  PRO_BR_RMV_REF_UP_TO_BEND_AXIS        = 256,
  PRO_BR_RMV_REF_UP_TO_BEND_END         = 512,
  PRO_BR_RMV_REF_UP_TO_BEND_APEX        = 1024

} ProBendRlfRmvRefType;


PRO_END_C_DECLS
#endif

