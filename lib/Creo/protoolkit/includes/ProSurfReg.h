#ifndef PRO_SURFREG_H
#define PRO_SURFREG_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SURFREG_SPLITTING_OPTION
      |
      |-- PRO_E_STD_SECTION
      |
      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |
      |-- PRO_E_STD_SURF_COLLECTION_APPL

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
Element Id                      Element Name      Data Type         Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type      PRO_VALUE_TYPE_INT       Note1
PRO_E_STD_FEATURE_NAME          Feature Name      PRO_VALUE_TYPE_WSTRING   Note2
PRO_E_SURFREG_SPLITTING_OPTION  Splitting Option  PRO_VALUE_TYPE_INT       Note3
PRO_E_STD_SECTION               Splitting Section Compound                 Note4
PRO_E_STD_CURVE_COLLECTION_APPL Splitting Chain   PRO_VALUE_TYPE_SELECTION Note5
PRO_E_STD_SURF_COLLECTION_APPL  Split surfaces    PRO_VALUE_TYPE_SELECTION Note6
===============================================================================

(3) Notes

   Note1 : PRO_FEAT_SPLIT_SURF

   Note2 : Surface Region feature name.
           Default value is "Surface Region".

   Note3 : Splitting options: Sketch ( PRO_SURFREG_SKETCH ) or
           Chain ( PRO_SURFREG_CHAIN ).
           Default value is PRO_SURFREG_SKETCH.

   Note4 : This compound element is standard section. 
           Please, see files ProSection.h and ProStdSection.h

   Note5 : This is standard curve collection.

   Note6 : This is standard surface collection.

==============================================================================*/


/* ================== */
/* Splitting options: */
/* ================== */

typedef enum 
{
 PRO_SURFREG_SKETCH = 1, /* Surface region will use sketch to split surface */
 PRO_SURFREG_CHAIN  = 2  /* Surface region will use chain to split surface  */
} ProSeurfRegSplittingOption;

PRO_END_C_DECLS

#endif /* PRO_SURFREG_H */
