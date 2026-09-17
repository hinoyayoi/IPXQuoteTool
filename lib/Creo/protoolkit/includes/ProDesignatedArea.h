#ifndef _PRO_DDESIGNATED_AREA_
#define _PRO_DDESIGNATED_AREA_

#include <ProColor.h>

PRO_BEGIN_C_DECLS


 
/*****************************************************************************

PRO_E_FEATURE_TREE
  |
  |-- PRO_E_FEATURE_TYPE
  |
  |-- PRO_E_STD_FEATURE_NAME
  |
  |-- PRO_E_DSGNTAREA_CREATION
  |     |
  |     |--PRO_E_DSGNTAREA_CREATION_TYPE
  |     |
  |     |--PRO_E_DSGNTAREA_LIE_ON
  |     |
  |     |--PRO_E_DSGNTAREA_CREATION_FLIP
  |     |
  |-- PRO_E_DSGNTAREA_SETS
        |
        |--PRO_E_DSGNTAREA_SET
             |
             |--PRO_E_DSGNTAREA_SET_REFS
                  |
                  |--PRO_E_STD_CHAIN_HOLDER
                       |
                       |--PRO_E_STD_CURVE_COLLECTION_APPL
         


===============================================================================
Element Id                             Element Name             
===============================================================================
PRO_E_FEATURE_TYPE                     Feature Type
PRO_E_STD_FEATURE_NAME                 Target Area Name      
PRO_E_DSGNTAREA_CREATION               Creation Data         
PRO_E_DSGNTAREA_CREATION_TYPE          Creation Type       
PRO_E_DSGNTAREA_LIE_ON                 Lie On                
PRO_E_DSGNTAREA_CREATION_FLIP          Creation Flip         
PRO_E_DSGNTAREA_SETS                   Sets                  
PRO_E_DSGNTAREA_SET                    Set                   
PRO_E_DSGNTAREA_SET_REFS               Set References    
PRO_E_STD_CHAIN_HOLDER                 Chain Holder
PRO_E_STD_CURVE_COLLECTION_APPL        Curve Chain Reference 

===============================================================================
Element Id                             Data Type
===============================================================================
PRO_E_FEATURE_TYPE                     PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME                 PRO_VALUE_TYPE_WSTRING
PRO_E_DSGNTAREA_CREATION               Compound
PRO_E_DSGNTAREA_CREATION_TYPE          PRO_VALUE_TYPE_INT
PRO_E_DSGNTAREA_LIE_ON                 PRO_VALUE_TYPE_SELECTION
PRO_E_DSGNTAREA_CREATION_FLIP          PRO_VALUE_TYPE_BOOLEAN
PRO_E_DSGNTAREA_SETS                   Array
PRO_E_DSGNTAREA_SET                    Compound
PRO_E_DSGNTAREA_SET_REFS               Array
PRO_E_STD_CHAIN_HOLDER                 Compound
PRO_E_STD_CURVE_COLLECTION_APPL        PRO_VALUE_TYPE_SELECTION


===============================================================================
Element Id                             Valid Values
===============================================================================
PRO_E_FEATURE_TYPE                     PRO_FEAT_DSGNT_AREA
PRO_E_STD_FEATURE_NAME                      
PRO_E_DSGNTAREA_CREATION               N/A    
PRO_E_DSGNTAREA_CREATION_TYPE          Type from ProDACreationType
PRO_E_DSGNTAREA_LIE_ON                 Placement Reference of a Quilt
PRO_E_DSGNTAREA_CREATION_FLIP          True/False
PRO_E_DSGNTAREA_SETS                   
PRO_E_DSGNTAREA_SET 
PRO_E_DSGNTAREA_SET_REFS               
PRO_E_STD_CHAIN_HOLDER
PRO_E_STD_CURVE_COLLECTION_APPL        See notes in ProCrvcollection.h

*****************************************************************************/

typedef enum _ProDsgntACreationType_
{
  PRO_DSGNTA_CR_NONE,
  PRO_DSGNTA_CR_SOLID,
  PRO_DSGNTA_CR_QUILT,
  PRO_DSGNTA_CR_AIR
} ProDsgntACrType;
 
typedef enum
{
   PRO_DSGNTAREA_STATUS_INVALID            = PRO_VALUE_UNUSED,
   PRO_DSGNTAREA_STATUS_ACTIVE,
   PRO_DSGNTAREA_STATUS_INACTIVE,
   PRO_DSGNTAREA_STATUS_OUT_OF_COPIED_GEOM
} ProDesignatedAreaStatus;

 

extern ProError ProDesignatedareaStatusGet (ProGeomitem* designated_area_quilt,
					    ProDesignatedAreaStatus* status);
/*
    Purpose: Identifies if the geometry of this Designated Area feature is
             active,  inactive, or out of copied geometry.

    Input Arguments:
        designated_area_quilt - A quilt from the designated area feature 
                                ( or from a data sharing feature referening 
                                  the designated area ).

    Output Arguments:
        status - The designated area status.

    Return Values:
        PRO_TK_NO_ERROR     - The function succeeded.
        PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
        PRO_TK_INVALID_ITEM - The quilt is not from a designated area feature.
        PRO_TK_INVALID_TYPE - The quilt is a FLAT designated area feature, 
                              which cannot have a non-active status.
*/


extern ProError ProDesignatedareaLinestyleGet (ProFeature* designated_area, 
					       ProLinestyle* line_style);
/*
    Purpose: Obtains the line style used for the boundary of the designated 
             area.

    Input Arguments:
        designated_area - The designated area feature.

    Output Arguments:
        line_style - The line style used for the boundary of the designated 
                     area.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDesignatedareaLinestyleSet (ProFeature* designated_area, 
					       ProLinestyle line_style);
/*
    Purpose: Assigns the line style used for the boundary of the designated 
             area.

    Input Arguments:
        designated_area - The designated area feature.
        line_style - The line style used for the boundary of the designated 
                     area.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDesignatedareaColorGet (ProFeature* designated_area, 
					   ProColor* color);
/*
    Purpose: Obtains the color used for the boundary of the designated area.

    Input Arguments:
        designated_area - The designated area feature.

    Output Arguments:
        color - The color used for the boundary of the designated area.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProDesignatedareaColorSet (ProFeature* designated_area, 
					   ProColor* color);
/*
    Purpose: Assigns the color used for the boundary of the designated area.

    Input Arguments:
        designated_area - The designated area feature.
        color - The color used for the boundary of the designated area.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

PRO_END_C_DECLS

#endif
 
 

