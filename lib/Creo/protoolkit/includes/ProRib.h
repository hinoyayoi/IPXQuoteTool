#ifndef PRO_RIB_H
#define PRO_RIB_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |--PRO_E_FEATURE_TYPE
      |
      |--PRO_E_FEATURE_FORM
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_RIB_SECTION_COMP
      |      | 
      |      |-- PRO_E_STD_SECTION
      |      |
      |      |-- PRO_E_STD_MATRLSIDE
      |
      |-- PRO_E_RIB_THICKNESS
      |
      |-- PRO_E_RIB_SIDE_OPTS

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
 Element Id                Element Name       Data Type             Valid Values
-------------------------------------------------------------------------------
 PRO_E_FEATURE_TYPE        Feature Type       PRO_VALUE_TYPE_INT        Note-1
 PRO_E_FEATURE_FORM        Feature Form       PRO_VALUE_TYPE_INT        Note-2
 PRO_E_STD_FEATURE_NAME    Feature Name       PRO_VALUE_TYPE_WSTRING    Note-3
 PRO_E_RIB_SECTION_COMP    Sketch Compound    Compound                  Note-4
 PRO_E_STD_SECTION         Rib Section        Compound                  Note-5
 PRO_E_STD_MATRLSIDE       Material Side      PRO_VALUE_TYPE_INT        Note-6
 PRO_E_RIB_THICKNESS       Rib Thickness      PRO_VALUE_TYPE_DOUBLE     Note-7
 PRO_E_RIB_SIDE_OPTS       Side Options       PRO_VALUE_TYPE_INT        Note-8

===============================================================================

(3) Notes

   Note-1 : PRO_FEAT_RIB

   Note-2 : PRO_EXTRUDE

   Note-3 : Rib feature name.
            Default value is "RIB".

   Note-4 : Compound element that hold section related elements.

   Note-5 : This compound element is standard section. 
            Please, see files ProSection.h and ProStdSection.h

   Note-6 : Material side options of Rib: Side One ( PRO_RIB_SEC_SIDE_ONE ),
            Side Two ( PRO_RIB_SEC_SIDE_TWO ). 
            Important: The element PRO_E_STD_MATRLSIDE is directly
            dependent upon the presence of a fully defined PRO_E_STD_SECTION
            element tree. Value assigned to this element before fully 
            defining the PRO_E_STD_SECTION will be ignored. Default value 
            depends on the sketch under the PRO_E_STD_SECTION element.

   Note-7 : Thickness for the rib.
            Should be positive and bigger than zero.
            Default value is provided and depends on part epsilon.

   Note-8 : Side options of Rib: Symmetric ( PRO_RIB_SYMMETRIC ),
            Side One ( PRO_RIB_SIDE_ONE ) or Side Two ( PRO_RIB_SIDE_TWO ).
            Default value is PRO_RIB_SYMMETRIC.

==============================================================================*/


/* ==================== */
/* Side options of Rib: */
/* ==================== */

typedef enum 
{
 PRO_RIB_SYMMETRIC    = 1, /* Rib will be symmetric to the sketch    */
 PRO_RIB_SIDE_ONE     = 2, /* Rib will be on Side One of the sketch  */
 PRO_RIB_SIDE_TWO     = 3  /* Rib will be on Side Two of the sketch  */
} ProRibSideOption;

/* ===================== */
/* Material Side of Rib: */
/* ===================== */

typedef enum
{
 PRO_RIB_SEC_SIDE_ONE = 1, /* Rib will be on side one of the section */
 PRO_RIB_SEC_SIDE_TWO = 2  /* Rib will be on side two of the section */
} ProRibSectionSideOption;



PRO_END_C_DECLS
#endif /* PRO_RIB_H */
