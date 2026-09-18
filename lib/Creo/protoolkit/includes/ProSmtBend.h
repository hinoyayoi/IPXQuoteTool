#ifndef PROSMTBEND_H
#define PROSMTBEND_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Bend feature
*/



#include <ProToolkit.h>
#include <ProSmtFlangeWall.h>

PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :


   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_BEND_FORM			     
     |
     |--PRO_E_SMT_BEND_LINE	    		
     |    |
     |    |--PRO_E_SMT_BEND_LINE_TYPE	   
     |    |
     |    |--PRO_E_SMT_BEND_REF_SURFACE
     |    |
     |    |--PRO_E_STD_SECTION		 
     |    |
     |    |--PRO_E_SMT_BEND_CURVE	
     |    |    |
     |    |    |--PRO_E_STD_CURVE_COLLECTION_APPL     
     |    |    |
     |	  |    |--PRO_E_SMT_BEND_CURVE_USE_OFFSET	 
     |    |    |
     |    |    |--PRO_E_SMT_BEND_CURVE_OFFSET_VALUE	 
     |    |
     |    |--PRO_E_SMT_BEND_LINE_INTERNAL	
     |    |    |
     |    |    |--PRO_E_SMT_BEND_LINE_REF_END1		 
     |    |    |
     |    |    |--PRO_E_SMT_BEND_LINE_REF_END2		 
     |    |    |
     |    |    |--PRO_E_SMT_BEND_LINE_REF_OFFSET1	    
     |    |    |
     |    |    |--PRO_E_SMT_BEND_LINE_REF_OFFSET2	     
     |    |    |
     |    |    |--PRO_E_SMT_BEND_LINE_REF_OFFSET1_VALUE       
     |    |    |
     |    |    |--PRO_E_SMT_BEND_LINE_REF_OFFSET2_VALUE   
     |
     |--PRO_E_SMT_BEND_FIXED_SIDE 	
     |					
     |--PRO_E_SMT_BEND_LOCATION		
     |
     |--PRO_E_SMT_BEND_DIRECTION		
     |
     |--PRO_E_SMT_BEND_ANGLE	       		     
     |    |
     |    |--PRO_E_SMT_BEND_ANGLE_TYPE	        
     |    |
     |    |--PRO_E_SMT_BEND_ANGLE_VALUE	        
     |
     |--PRO_E_SMT_BEND_TRANS_FLIP	
     |   
     |--PRO_E_SMT_BEND_TRANS_AREAS		 
     |    |
     |    |--PRO_E_SMT_BEND_TRANS_SET			 
     |         |
     |         |--PRO_E_STD_SECTION
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
     |    |--PRO_E_SMT_BEND_RELIEF_SIDE2
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
     |
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

************************************************************************


================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_BEND_FORM	          Bend Form 		PRO_VALUE_TYPE_INT
PRO_E_SMT_BEND_LINE		  Bend Line		Compound
PRO_E_SMT_BEND_LINE_TYPE	  Bend Line Type	PRO_VALUE_TYPE_INT
                                                        See Note 1.
PRO_E_SMT_BEND_REF_SURFACE	  Bend line ref surface PRO_VALUE_TYPE_SELECTION
                                                        See Note 1.
PRO_E_SMT_BEND_CURVE		  Bend Curve            Compound
                                                        See Note 1.
PRO_E_STD_CURVE_COLLECTION_APPL	  Bend Line Chain       PRO_VALUE_TYPE_POINTER
PRO_E_SMT_BEND_CURVE_USE_OFFSET	  Bend Curve offset     PRO_VALUE_TYPE_INT
PRO_E_SMT_BEND_CURVE_OFFSET_VALUE Bend Curve offset val PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_LINE_INTERNAL	  Internal Bend Line    Compound
                                                        See Note 1.
PRO_E_SMT_BEND_LINE_REF_END1	  Bend line edge ref	PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_BEND_LINE_REF_END2	  Bend line edge ref    PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_BEND_LINE_REF_OFFSET1	  Bend line offset ref  PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_BEND_LINE_REF_OFFSET2   Bend line offset ref  PRO_VALUE_TYPE_SELECTION
                                                        See Note 2.
PRO_E_SMT_BEND_LINE_REF_OFFSET1_VALUE   offset value    PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_LINE_REF_OFFSET2_VALUE	offset value	PRO_VALUE_TYPE_DOUBLE
                                                        See Note 2.
PRO_E_SMT_BEND_FIXED_SIDE   	  Bend Fixed Side	PRO_VALUE_TYPE_INT
PRO_E_SMT_BEND_LOCATION	    	  Bend Side		PRO_VALUE_TYPE_INT
PRO_E_SMT_BEND_DIRECTION       	  Bend Direction	PRO_VALUE_TYPE_INT
PRO_E_SMT_BEND_ANGLE              Bend Angle            Compound
                                                        See Note 3.
PRO_E_SMT_BEND_ANGLE_TYPE    	  Bend Angle Type	PRO_VALUE_TYPE_INT
PRO_E_SMT_BEND_ANGLE_VALUE    	  Bend Angle Value	PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_TRANS_FLIP         Bend Trans flip	PRO_VALUE_TYPE_INT
                                                        See Note 4.
PRO_E_SMT_BEND_TRANS_AREAS        Bend Trans. Areas     Array (Optional)
PRO_E_SMT_BEND_TRANS_SET          Bend Trans. Set       Compound 
PRO_E_SMT_FILLETS                 Fillets               Compound
PRO_E_SMT_FILLETS_SIDE            Radius Side           PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLETS_VALUE           Radius Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_SMT_BEND_RELIEF             Bend Relief           Compound
PRO_E_SMT_BEND_RELIEF_SIDE1       Side 1 Relief         Compound
PRO_E_SMT_BEND_RELIEF_SIDE2       Side 2 Relief         Compound
PRO_E_BEND_RELIEF_TYPE            Relief Type           PRO_VALUE_TYPE_INT
PRO_E_BEND_RELIEF_WIDTH           Relief Width          PRO_VALUE_TYPE_DOUBLE
PRO_E_BEND_RELIEF_DEPTH_TYPE      Relief Depth type     PRO_VALUE_TYPE_INT
                                                        See Note 5.
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
 
The Element PRO_E_SMT_BEND_LINE_TYPE controls how the bend line is constructed :
when the type is:		     then the element:
A. PRO_SMT_BEND_LINE_CURVE - 	     PRO_E_SMT_BEND_CURVE 	   is available
B. PRO_SMT_BEND_LINE_INTERNAL_LINE - PRO_E_SMT_BEND_LINE_INTERNAL  is available
C. PRO_SMT_BEND_LINE_SKETCH	   - PRO_E_STD_SECTION		   is available

Also, 
The Element PRO_E_SMT_BEND_REF_SURFACE is availble when PRO_E_SMT_BEND_LINE_TYPE
is PRO_SMT_BEND_LINE_INTERNAL_LINE  OR  PRO_SMT_BEND_LINE_SKETCH . 

-------------------------------------------------------------------------------
Note 2.

Elements PRO_E_SMT_BEND_LINE_REF_OFFSET1, PRO_E_SMT_BEND_LINE_REF_OFFSET1_VALUE 
are available when PRO_E_SMT_BEND_LINE_REF_END1 has an EDGE reference .

Elements PRO_E_SMT_BEND_LINE_REF_OFFSET2, PRO_E_SMT_BEND_LINE_REF_OFFSET2_VALUE 
are available when PRO_E_SMT_BEND_LINE_REF_END2 has an EDGE reference .

-------------------------------------------------------------------------------
Note 3.

The Compound PRO_E_SMT_BEND_ANGLE is available when the Element 
PRO_E_SMT_BEND_FORM is set to PRO_SMT_BEND_FORM_ANGLE

-------------------------------------------------------------------------------
Note 4.

The Element PRO_E_SMT_BEND_TRANS_FLIP is available only if there is one 
transition set in the feature.

-------------------------------------------------------------------------------
Note 5.
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

================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_BEND
PRO_E_SMT_BEND_FORM	          ProBendForm
PRO_E_SMT_BEND_LINE_TYPE	  ProBendLineType
PRO_E_SMT_BEND_CURVE_USE_OFFSET   PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_BEND_REF_SURFACE	  Surface
PRO_E_SMT_BEND_LINE_REF_END1      Edge
PRO_E_SMT_BEND_LINE_REF_END2      Edge
PRO_E_SMT_BEND_LINE_REF_OFFSET1   Edge
PRO_E_SMT_BEND_LINE_REF_OFFSET2   Edge
PRO_E_SMT_BEND_FIXED_SIDE   	  PRO_SMT_BEND_SIDE_ONE, PRO_SMT_BEND_SIDE_TWO
PRO_E_SMT_BEND_LOCATION	    	  ProBendSide
PRO_E_SMT_BEND_DIRECTION    	  PRO_SMT_BEND_SIDE_ONE, PRO_SMT_BEND_SIDE_TWO
PRO_E_SMT_BEND_ANGLE_TYPE    	  ProBendAngleType
PRO_E_SMT_BEND_TRANS_FLIP	  PRO_SMT_BEND_SIDE_ONE, PRO_SMT_BEND_SIDE_TWO
PRO_E_SMT_FILLETS_SIDE            ProSmdRadType       (See ProSmtFlangeWall.h)
PRO_E_BEND_RELIEF_TYPE            ProBendRlfType      (See ProSmtFlangeWall.h)
PRO_E_BEND_RELIEF_DEPTH_TYPE      ProBendRlfDepthType (See ProSmtFlangeWall.h)
PRO_E_SMT_DEV_LEN_SOURCE          ProDvlLenSrcType    (See ProSmtFlangeWall.h)
PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE   ProDvlLenFactor     (See ProSmtFlangeWall.h)
PRO_E_SMT_DEV_LEN_BEND_TABLE      int (bend table ID)

================================================================================

************************************************************************/

typedef enum _ProBendForm
{
  PRO_SMT_BEND_FORM_ANGLE =  1,  
  PRO_SMT_BEND_FORM_ROLL = 2
} ProBendForm;


typedef enum _ProBendSide 
{
  PRO_SMT_BEND_SIDE_ONE = 0,
  PRO_SMT_BEND_SIDE_TWO = 1,
  PRO_SMT_BEND_BOTH_SIDES = 2
} ProBendSide;

typedef enum _ProBendAngleType   
{
  PRO_SMT_BEND_ANGLE_INTERNAL = 0,
  PRO_SMT_BEND_ANGLE_EXTERNAL = 1   		/* Default */

} ProBendAngleType;

typedef enum _ProBendLineType  
{
  PRO_SMT_BEND_LINE_NOT_DEFINED =  -1,
  PRO_SMT_BEND_LINE_SKETCH =  0,
  PRO_SMT_BEND_LINE_CURVE = 1,
  PRO_SMT_BEND_LINE_INTERNAL_LINE = 2

} ProBendLineType;


PRO_END_C_DECLS

#endif
