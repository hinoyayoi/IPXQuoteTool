#ifndef PROSMTSKETCHFORM_H
#define PROSMTSKETCHFORM_H

/*
  Creo Parametric TOOLKIT declarations related to SheetMetal Sketch Form feature
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
     |--PRO_E_STD_SECTION             
     |
     |--PRO_E_SKETCH_FORM_TYPE       
     |
     |--PRO_E_SKETCH_FORM_DEPTH_PUNCH  
     |
     |--PRO_E_SKETCH_FORM_DEPTH_PIERCING  
     |
     |--PRO_E_SKETCH_FORM_DIR   
     |
     |--PRO_E_EXT_COMP_DRFT_ANG
     |    |
     |    |--PRO_E_EXT_DRFT_ANG      
     |    |
     |    |--PRO_E_EXT_DRFT_ANG_VAL   
     |
     |-- PRO_E_SRF_END_ATTRIBUTES  
     |
     |--PRO_E_FORM_PUNCH_MATERIAL_SIDE       
     |
     |--PRO_E_SMT_FILLET_INTERSECT  
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_USEFLAG
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_VALUE
     |
     |--PRO_E_SMT_FILLET_QUILT
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_USEFLAG
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_SIDE
     |    |
     |    |--PRO_E_SMT_FILLET_RADIUS_VALUE
     |

************************************************************************
================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_STD_SECTION                 Section               Compound (Mandatory)
PRO_E_SKETCH_FORM_TYPE            Sketch Form Type      PRO_VALUE_TYPE_INT
PRO_E_SKETCH_FORM_DEPTH_PUNCH     Depth Value           PRO_VALUE_TYPE_DOUBLE
                                                        See Note 1.
PRO_E_SKETCH_FORM_DEPTH_PIERCING  Depth Value           PRO_VALUE_TYPE_DOUBLE
                                                        See Note 1.
PRO_E_SKETCH_FORM_DIR 	 	        Flip Direction	      PRO_VALUE_TYPE_INT
PRO_E_EXT_COMP_DRFT_ANG           Draft                 Compound 
                                                        See Note 2.
PRO_E_EXT_DRFT_ANG                Add Draft             PRO_VALUE_TYPE_INT
                                                        See Note 2.
PRO_E_EXT_DRFT_ANG_VAL            Draft Angle           PRO_VALUE_TYPE_DOUBLE
                                                        See Note 2.
PRO_E_SRF_END_ATTRIBUTES          End Cap               PRO_VALUE_TYPE_INT
                                                        See Note 2.
PRO_E_FORM_PUNCH_MATERIAL_SIDE    Flip Material Side    PRO_VALUE_TYPE_INT
                                                        See Note 2.
PRO_E_SMT_FILLET_INTERSECT        Intersect fillet      Compound
PRO_E_SMT_FILLET_QUILT            Quilt fillet          Compound
PRO_E_SMT_FILLET_RADIUS_USEFLAG   Use Radius            PRO_VALUE_TYPE_INT
PRO_E_SMT_FILLET_RADIUS_SIDE      Radius Side           PRO_VALUE_TYPE_INT
                                                        See Note 2.
PRO_E_SMT_FILLET_RADIUS_VALUE     Radius Value          PRO_VALUE_TYPE_DOUBLE
================================================================================
Note 1.   - Depth Elements
The Element PRO_E_SKETCH_FORM_TYPE controls the Depth Elements:
when the type is:
A. PRO_SMT_SKETCH_FORM_TYPE_PUNCH    -> PRO_E_SKETCH_FORM_DEPTH_PUNCH  
                                                      is available.

B. PRO_SMT_SKETCH_FORM_TYPE_PIERCING -> PRO_E_SKETCH_FORM_DEPTH_PIERCING 
                                                      is available.

Note 2.   - Punch Elements only:
These Elements are valid when Element 
PRO_E_SKETCH_FORM_TYPE   is   PRO_SMT_SKETCH_FORM_TYPE_PUNCH  only.



================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_SMT_SKETCH_FORM
PRO_E_SKETCH_FORM_TYPE            ProSketchFormType 
PRO_E_SKETCH_FORM_DIR		          PRO_B_TRUE, PRO_B_FALSE
PRO_E_EXT_DRFT_ANG		            ProExtDrftAng       (See ProExtrude.h)
PRO_E_SRF_END_ATTRIBUTES	        ProExtSurfEndAttr   (See ProExtrude.h)
PRO_E_FORM_PUNCH_MATERIAL_SIDE    ProSmdPunchMatSide  (See ProSmtPunchQuilt.h)
PRO_E_SMT_FILLET_RADIUS_USEFLAG   PRO_B_TRUE, PRO_B_FALSE
PRO_E_SMT_FILLET_RADIUS_SIDE      ProSmdRadType( PRO_BEND_RAD_INSIDE,
                                                 PRO_BEND_RAD_OUTSIDE)

================================================================================
************************************************************************/



typedef enum _ProSketchFormType
{
  PRO_SMT_SKETCH_FORM_TYPE_PUNCH =  1,  
  PRO_SMT_SKETCH_FORM_TYPE_PIERCING = 2
} ProSketchFormType;



PRO_END_C_DECLS

#endif
