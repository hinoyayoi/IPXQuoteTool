#ifndef PROSMTJOINWALLS_H
#define PROSMTJOINWALLS_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Join Walls feature
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/* ***************************************************************************


Feature element tree :

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME 
     |
     |--PRO_E_SMT_WALL_JOIN_TRIM
     |
     |--PRO_E_SMT_WALL_JOIN_EXTEND
     |
     |--PRO_E_SMT_WALL_JOIN_REFS
     |    |
     |    |--PRO_E_SMT_WALL_JOIN_REFS_CMPND
     |         |
     |         |--PRO_E_SMT_WALL_JOIN_REFS_SRF
     |         |
     |         |--PRO_E_SMT_WALL_JOIN_FLIP
     |
     |--PRO_E_SMT_FILLETS               
     |    |
     |    |--PRO_E_SMT_FILLETS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLETS_VALUE
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
     |


==============================================================================
Element Id                     Element Name             Data Type
==============================================================================

PRO_E_FEATURE_TYPE             Feature Type            PRO_VALUE_TYPE_INT
                                See Note 1.

PRO_E_STD_FEATURE_NAME         Feature Name            PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_WALL_JOIN_TRIM       Trim type                PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_JOIN_EXTEND     Extend type              PRO_VALUE_TYPE_INT
PRO_E_SMT_WALL_JOIN_REFS       Surfaces                 Array
                               See note 3
PRO_E_SMT_WALL_JOIN_REFS_CMPND    Surface Cmpnd         Compound
PRO_E_SMT_WALL_JOIN_REFS_SRF      Surface               PRO_ELEM_TYPE_SELECT
                               See note 4
PRO_E_SMT_WALL_JOIN_FLIP       Flip                     PRO_VALUE_TYPE_INT
                               see note 5 
PRO_E_SMT_FILLETS                 Fillets               Compound
PRO_E_SMT_FILLETS_SIDE            Radius Side           PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE           Radius Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_RELIEF             Bend Relief           Compound
PRO_E_SMT_BEND_RELIEF_SIDE1       Side 1 Relief         Compound
PRO_E_BEND_RELIEF_TYPE            Relief Type           PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_WIDTH           Relief Width          PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_DEPTH_TYPE      Relief Depth type     PRO_VALUE_TYPE_INT
                                                        See Note 2.
PRO_E_BEND_RELIEF_DEPTH           Relief Depth value    PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_ANGLE           Relief Angle          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_DEV_LEN_CALCULATION     Developed Length      Compound
PRO_E_SMT_DEV_LEN_SOURCE          Dev Length Source     PRO_VALUE_TYPE_INT 
PRO_E_SMT_DEV_LEN_Y_FACTOR        Dev Length Y Factor   Compound
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   Y Factor Type         PRO_VALUE_TYPE_INT
PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE  Y Factor Value        PRO_VALUE_TYPE_DOUBLE  
PRO_E_SMT_DEV_LEN_BEND_TABLE      Dev Length Bend Table PRO_VALUE_TYPE_INT



-------------------------------------------------------------------------------
Note 1.
  PRO_E_FEATURE_TYPE must be of PRO_FEAT_JOIN_WALLS

-------------------------------------------------------------------------------
Note 2.
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

Note 3.
PRO_E_SMT_WALL_JOIN_REFS - Array of exactly two elements.

Note 4.
PRO_E_SMT_WALL_JOIN_REFS_SRF - Should be plane. Should be in geometry.
                      There are two of them, they should not be parallel,
                      If they are part of the same distinct piece, 
                      they should not be of different smt sides
Note5.
PRO_E_SMT_WALL_JOIN_FLIP - govern which part of intersected surface is removed
 
                                
================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_SMT_WALL_JOIN_TRIM          ProSmtJoinWallsTrimType (See below)
PRO_E_SMT_WALL_JOIN_EXTEND        ProSmtJoinWallsExtType  (See below)
PRO_E_SMT_WALL_JOIN_FLIP          ProBoolean
PRO_E_SMT_FILLETS_SIDE            ProSmdRadType       (See ProSmtFlangeWall.h)
PRO_E_BEND_RELIEF_TYPE            ProBendRlfType      (See ProSmtFlangeWall.h)
PRO_E_BEND_RELIEF_DEPTH_TYPE      ProBendRlfDepthType (See ProSmtFlangeWall.h)
PRO_E_SMT_DEV_LEN_SOURCE          ProDvlLenSrcType    (See ProSmtFlangeWall.h)
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   ProDvlLenFactor     (See ProSmtFlangeWall.h)
PRO_E_SMT_DEV_LEN_BEND_TABLE      int (bend table ID)

================================================================================


*****************************************************************************/

typedef enum Pro_intwalls_trim_type
{
 PRO_INTWLS_TRIM_OPEN_CUTS   = 0,   /* Cut planes normal to int lines        */
 PRO_INTWLS_TRIM_BNDR_EXTS   = 1,   /* Extend int lines to plane boundaries  */
 PRO_INTWLS_TRIM_BEND_LINE   = 2    /* Trim by bend surface                  */

}ProSmtJoinWallsTrimType;

typedef enum Pro_intwalls_ext_type
{
 PRO_INTWLS_EXT_LINE_TO_INT  = 0,   /* Extend intersection line to int area  */
 PRO_INTWLS_EXT_LINE_TO_ALL  = 1    /* Extend intersection line to all plane */

}ProSmtJoinWallsExtType;

PRO_END_C_DECLS

#endif /* PROSMTJOINWALLS_H */

