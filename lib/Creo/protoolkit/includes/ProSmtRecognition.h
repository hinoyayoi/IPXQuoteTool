#ifndef PROSMTRECOGNITION_H
#define PROSMTRECOGNITION_H

/*
  Creo Parametric TOOLKIT declarations related to SheetMetal 
  Recognition and UnRecognition Tools
*/






#include <ProToolkit.h>


PRO_BEGIN_C_DECLS

/************************************************************************

Feature element tree :

     PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_STD_FEATURE_NAME
     |
     |--PRO_E_SMT_BND_RLF_RCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE          
     |
     |--PRO_E_SMT_CRN_RLF_RCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE       
     |
     |--PRO_E_SMT_BEND_RCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE          
     |
     |--PRO_E_SMT_CRN_SEAM_RCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE       
     |
     |--PRO_E_SMT_FORM_RCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_RCG_FORM_AS_ONE
     |    |
     |    |--PRO_E_STD_SURF_COLLECTION_APPL 
     |    |
     |    |---PRO_E_SMT_FORM_BOUND_REFS
     |
     |--PRO_E_SMT_BND_RLF_UNRCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE          
     |
     |--PRO_E_SMT_CRN_RLF_UNRCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE       
     |
     |--PRO_E_SMT_BEND_UNRCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE          
     |
     |--PRO_E_SMT_CRN_SEAM_UNRCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE       
     |
     |--PRO_E_SMT_FORM_UNRCG
     |    |
     |    |--PRO_E_SMT_RECOGNITION_SEL_TYPE
     |    |
     |    |--PRO_E_SMT_RCG_FORM_AS_ONE
     |    |
     |    |--PRO_E_SMT_PIO_SCOPE
     |    |
     |    |--PRO_E_SMT_FORM_BOUND_REFS

************************************************************************
================================================================================
Element Id                        Element Name          Data Type
================================================================================
PRO_E_FEATURE_TYPE                Feature Type          PRO_VALUE_TYPE_INT
PRO_E_STD_FEATURE_NAME            Feature Name          PRO_VALUE_TYPE_WSTRING
PRO_E_SMT_BND_RLF_RCG             bend relief cmp       Compound
PRO_E_SMT_CRN_RLF_RCG             corner relief cmp     Compound
PRO_E_SMT_BEND_RCG                bend cmp              Compound
PRO_E_SMT_CRN_SEAM_RCG            edge connection cmp   Compound
PRO_E_SMT_FORM_RCG                form cmp              Compound
PRO_E_SMT_BND_RLF_UNRCG           bend relief cmp       Compound
PRO_E_SMT_CRN_RLF_UNRCG           corner relief cmp     Compound
PRO_E_SMT_BEND_UNRCG              bend cmp              Compound
PRO_E_SMT_CRN_SEAM_UNRCG          edge connection cmp   Compound
PRO_E_SMT_FORM_UNRCG              form cmp              Compound

PRO_E_SMT_RECOGNITION_SEL_TYPE    selection type        PRO_VALUE_TYPE_INT
PRO_E_SMT_PIO_SCOPE               Multi Collector       PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_RCG_FORM_AS_ONE         Form as one object    PRO_VALUE_TYPE_BOOLEAN
PRO_E_STD_SURF_COLLECTION_APPL    Surface Collector     PRO_VALUE_TYPE_SELECTION
PRO_E_SMT_FORM_BOUND_REFS	  Multi Collector	PRO_VALUE_TYPE_SELECTION


================================================================================



================================================================================
Element Id                        Valid Values
================================================================================
PRO_E_FEATURE_TYPE                PRO_FEAT_SMT_RECOGNITION
PRO_E_SMT_PIO_SCOPE               See Note 1
PRO_E_SMT_RCG_FORM_AS_ONE         ProBoolean
PRO_E_SMT_RECOGNITION_SEL_TYPE    ProRecognitionSel          
PRO_E_SMT_FORM_BOUND_REFS	  See Note 2


================================================================================
Note 1

Valid Value of PRO_E_SMT_PIO_SCOPE depends on it's compound element.

The following is valid for PRO_E_SMT_BEND_RCG:
  Cylindrical bend surface, Intent Surface that contains a cylindrical Bend or
  Not Bend design object.

The following is valid for PRO_E_SMT_BEND_UNRCG:
  Cylindrical bend surface, planar bend area, Intent Surface that contains
  a cylindrical bend or a planar bend area, Bend design object.

The following is valid for PRO_E_SMT_BND_RLF_RCG:
  Driven or Offset sheetmetal surface, Intent Surface that contain at least one
  side of bend relief, Not Bend Relief design object, thickness edge (if bed
  relief does not contain any surface), bend relief vertex (if bed relief
  does not contain any surface or edge).

The following is valid for PRO_E_SMT_BND_RLF_UNRCG:
  Driven or Offset sheetmetal surface, Intent Surface that contain at least one
  side of bend relief, Bend Relief design object, thickness edge (if bed
  relief does not contain any surface), bend relief vertex (if bed relief
  does not contain any surface or edge).

The following is valid for PRO_E_SMT_CRN_RLF_RCG:
  TODO.
The following is valid for PRO_E_SMT_CRN_RLF_UNRCG:
  TODO.
The following is valid for PRO_E_SMT_crn_SEAM_RCG:
  TODO.
The following is valid for PRO_E_SMT_CRN_SEAM_UNRCG:
  TODO.

================================================================================
Note 2

The following is valid for PRO_E_SMT_FORM_BOUND_REFS:

Driven or Offset sheetmetal surfaces or Intent Surfaces that contain
Driven or Offset sheetmetal surfaces.


================================================================================
************************************************************************/

typedef enum _ProRecognitionSel
{
  PRO_SMT_RECOGNITION_MANUAL_SEL =  0,
  PRO_SMT_RECOGNITION_AUTO_SEL = 1

} ProRecognitionSel;






PRO_END_C_DECLS

#endif
