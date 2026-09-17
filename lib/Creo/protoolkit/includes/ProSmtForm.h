#ifndef PROSMTFORM_H
#define PROSMTFORM_H

/*
   Creo Parametric TOOLKIT declarations related to SheetMetal Form feature
*/





#include <ProToolkit.h>
#include <ProSheetmetal.h>

PRO_BEGIN_C_DECLS

/*****************************************************************************\

 PRO_E_FEATURE_TREE
 |
 |-PRO_E_FEATURE_TYPE
 |-PRO_E_STD_FEATURE_NAME
 |-PRO_E_GMRG_SMT_TYPE
 |-PRO_E_GMRG_FEAT_TYPE
 |-PRO_E_DSF_REF_MDL
 |   |--PRO_E_DSF_SEL_REF_MDL
 |-PRO_E_COMP_PLACE_INTERFACE
 |-PRO_E_COMPONENT_CONSTRAINTS
 |-PRO_E_GMRG_VARIED_ITEMS
 |-PRO_E_DSF_DEPENDENCY
 |-PRO_E_FORM_PUNCH_SIDE                     ( Punch Form Only )
 |-PRO_E_STD_SURF_COLLECTION_APPL
 |-PRO_E_FORM_DIE_POCKET_GEOM_CMP            ( Die Form Only )
      |--PRO_E_STD_SURF_COLLECTION_APPL
 |-PRO_E_FORM_TOOL_CSYS
 |-PRO_E_FORM_TOOL_NAME
 |-PRO_E_GMRG_FORM_AUTO_ROUNDS
 |-PRO_E_SMT_FILLET_INTERSECT
 |   |--PRO_E_SMT_FILLET_RADIUS_USEFLAG
 |   |--PRO_E_SMT_FILLET_RADIUS_SIDE
 |   |--PRO_E_SMT_FILLET_RADIUS_VALUE

Feature elements table

-------------------------------------------------------------------------------
Element Id			Element Name		Data Type
				Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE		Feature Type		PRO_VALUE_TYPE_INT
				PRO_FEAT_GEN_MERGE

PRO_E_STD_FEATURE_NAME		Feature Name		PRO_VALUE_TYPE_WSTRING

PRO_E_GMRG_SMT_TYPE		Sheet Metal Form	PRO_VALUE_TYPE_INT
				See Note 1.

PRO_E_GMRG_FEAT_TYPE		Gen Merge feat type	PRO_VALUE_TYPE_INT
				ProGenMergeType. See Note 6 ( Note 2 is outdated ).

PRO_E_DSF_REF_MDL		Reference Model	compound

PRO_E_DSF_SEL_REF_MDL		Select Reference Model	PRO_VALUE_TYPE_SELECTION
				Any Part model.

PRO_E_COMP_PLACE_INTERFACE	Placement Interface compound
				See ProAsmcomp.h

PRO_E_COMPONENT_CONSTRAINTS	Placement constraints compound
				See ProAsmcomp.h

PRO_E_GMRG_VARIED_ITEMS		Inheritance Varied Items Dlg
				See ProDataShareFeat.h

PRO_E_DSF_DEPENDENCY		Dependency		PRO_VALUE_TYPE_INT
				ProDsfDependency. See Note 6 ( Note 2 is outdated).

PRO_E_FORM_PUNCH_SIDE		Creation Side		PRO_VALUE_TYPE_INT
				ProSmtSurfType. See Note 3.

PRO_E_STD_SURF_COLLECTION_APPL	Excluded Surfaces	PRO_VALUE_TYPE_SELECTION
				Standard surface collection. See Note 4.

PRO_E_FORM_DIE_POCKET_GEOM_CMP  Pocket Geometry compound
       See Note 5.

PRO_E_STD_SURF_COLLECTION_APPL Pocket Geometry PRO_VALUE_TYPE_SELECTION
   				Standard surface collection. See Note 4.

PRO_E_FORM_TOOL_CSYS		Punch Tool Csys		PRO_VALUE_TYPE_SELECTION
				Any csys from the reference model.

PRO_E_FORM_TOOL_NAME		Punch ToolName		PRO_VALUE_TYPE_WSTRING

PRO_E_GMRG_FORM_AUTO_ROUNDS	Round Sharp Edges	PRO_VALUE_TYPE_BOOLEAN
				ProBoolean

PRO_E_SMT_FILLET_INTERSECT	Intersect fillet	Compound

PRO_E_SMT_FILLET_RADIUS_USEFLAG	Use Radius		PRO_VALUE_TYPE_BOOLEAN
				ProBoolean

PRO_E_SMT_FILLET_RADIUS_SIDE	Radius Side		PRO_VALUE_TYPE_INT
				ProSmdRadType(PRO_BEND_RAD_INSIDE,
					      PRO_BEND_RAD_OUTSIDE)

PRO_E_SMT_FILLET_RADIUS_VALUE	Radius Value		PRO_VALUE_TYPE_DOUBLE


-------------------------------------------------------------------------------
Note 1.
  PRO_E_GMRG_SMT_TYPE is of type ProGenMergeSmtType .

-------------------------------------------------------------------------------
Note 2.
  PRO_E_GMRG_FEAT_TYPE is related to PRO_E_DSF_DEPENDENCY.
  Two combinations of these elements are valid in a Form feature:
  PRO_GEN_MERGE_TYPE_MERGE	 & PRO_DSF_DEPENDENT	and
  PRO_GEN_MERGE_TYPE_INHERITANCE & PRO_DSF_INDEPENDENT.

-------------------------------------------------------------------------------
Note 3.
  PRO_SMT_SURF_FACE or PRO_SMT_SURF_OFFSET only are allowed
  as a value of PRO_E_FORM_PUNCH_SIDE element.

-------------------------------------------------------------------------------
Note 4.
  See ProSrfcollection.h and ProElementCollection*() API in ProElement.h
-------------------------------------------------------------------------------
Note 5.
 Element PRO_E_FORM_DIE_POCKET_GEOM_CMP is Available only if 
 ProGenMergeSmtType is of type PRO_GEN_MERGE_SMT_TYPE_FORM_DIE.

-------------------------------------------------------------------------------
Note 6.
  PRO_E_GMRG_FEAT_TYPE & PRO_E_DSF_DEPENDENCY are not related,and can be set 
  separately.
  
  PRO_E_DSF_DEPENDENCY supports PRO_DSF_UPDATE_AUTOMATICALLY,
  PRO_DSF_UPDATE_MANUALLY & PRO_DSF_NO_DEPENDENCY.

  For legacy issues, 
  PRO_DSF_UPDATE_AUTOMATICALLY = PRO_DSF_DEPENDENT
  PRO_DSF_UPDATE_MANUALLY = PRO_DSF_INDEPENDENT

  Currently, for PRO_GEN_MERGE_TYPE_MERGE , only
  PRO_DSF_UPDATE_AUTOMATICALLY is allowed.
******************************************************************************/


typedef enum ProGenMergeSmtTypes
{
  PRO_GEN_MERGE_SMT_TYPE_NOT_SMT    	= 0,
  PRO_GEN_MERGE_SMT_TYPE_FORM 		    = 1,  /* Pre Creo3 Parts for Punch */
  PRO_GEN_MERGE_SMT_TYPE_FORM_PUNCH		= 1,
  PRO_GEN_MERGE_SMT_TYPE_FORM_DIE    	= 2

} ProGenMergeSmtType;


PRO_END_C_DECLS

#endif	/* PROSMTFORM_H */
