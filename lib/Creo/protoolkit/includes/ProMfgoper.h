#ifndef PROMFGOPER_H
#define PROMFGOPER_H

/* ProMfgoper.h: This include file contains the following details of the
                 manufacturing operation feature:

                     * mfg operation definition
                     * some utility functions for the mfg operation feature
*/



#include <ProObjects.h>
#include <ProSelection.h>
#include <ProMfg.h>

/*****************************************************************************\

WARNING: This Feature element tree is deprecated and will be removed in subsequent
releases. Refer to this header for replacement:

ProMfgFeatOperation.h


Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEAT_TYPE
     |
     |--PRO_E_FEAT_NAME     Optional element
     |
     |--PRO_E_WCELL
     |
     |--PRO_E_FIXTURE
     |
     |--PRO_E_MACH_CSYS
     |
     |--PRO_E_COMMENTS      Optional element
     |
     |--PRO_E_MFG_PARAMS    Optional element
     |    |
     |    |--PRO_E_MFG_PARAM
     |         | 
     |         |--PRO_E_MFG_PARAM_NAME
     |         | 
     |         |--PRO_E_MFG_PARAMVAL
     |
     |--PRO_E_FROM_POINTS     Optional element, array of PRO_E_FROM_POINT
     |    |
     |    |--PRO_E_FROM_POINT
     |         |
     |         |--PRO_E_MACH_HEAD
     |         |
     |         |--PRO_E_POINT_SEL
     |
     |--PRO_E_HOME_POINTS     Optional element, array of PRO_E_HOME_POINT
          |
          |--PRO_E_HOME_POINT
               |
               |--PRO_E_MACH_HEAD
               |
               |--PRO_E_POINT_SEL



MFG OPERATION ELEMENTS TABLE
--------------------------------------------------------------------------------Element Id            Element Name     Data Type          Valid Values
                                       (PRO_VALUE_TYPE)
--------------------------------------------------------------------------------
PRO_E_FEAT_TYPE       Feature type     INT                PRO_FEAT_OPERATION

PRO_E_FEAT_NAME       Feature Name     WSTRING            Feature name

PRO_E_WCELL           Operation's
                      workcell         INT                Workcell feature id

PRO_E_FIXTURE         Operation's
                      default fixture  INT                Fixture feature id
                      
PRO_E_MACH_CSYS       Operation machine
                      csys             SELECTION          See note 1

PRO_E_COMMENTS        Comments         WSTRING ARRAY      Paragraph of text

PRO_E_MFG_PARAMS      Parameters       ARRAY

PRO_E_MFG_PARAM       Mfg param        COMPOUND

PRO_E_MFG_PARAM_NAME  Mfg param name   STRING             User-visible
                                                          mfg param names

PRO_E_MFG_PARAMVAL    Mfg param value  INT/DOUBLE/WSTRING See note 2

PRO_E_FROM_POINTS     "From" points    ARRAY              Array of from points

PRO_E_HOME_POINTS     "Home" points    ARRAY              Array of home points

PRO_E_FROM_POINT      "From" point     COMPOUND

PRO_E_HOME_POINT      "Home" point     COMPOUND

PRO_E_MACH_HEAD       Machining head   INT                ProMachHead

PRO_E_POINT_SEL         Point selection  SELECTION          See note 3
--------------------------------------------------------------------------------

NOTES:

1. The selection reference should be initialized to the coordinate system's
   identifier (NOT the feature identifier!).

2. This type of element can have an integer value, a double value or a
   wide string value. Please refer to manufacturing user's guide for
   appropriate values.

3. The selection reference should be initialized to the appropriate datum
   point's identifier (NOT the feature identifier!).


\******************************************************************************/

PRO_BEGIN_C_DECLS


typedef  struct pro_model_item  ProMfgoper;

extern ProError  ProMfgoperToolpathDisplay  ( PRO_CONST_ARG ProMfgoper* oper);
/*
   Purpose:  Displays the toolpath of the manufacturing operation on the screen.

   Input Arguments:
      oper            - The handle to a manufacturing operation feature

   Output Arguments: 
      none

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_GENERAL_ERROR - The toolpath display failed.
      PRO_TK_BAD_INPUTS    - The argument is invalid.
*/

extern ProError  ProMfgoperActiveGet  ( ProSolid mfg_solid,
                                        ProMfgoper *oper_feat);
/*
   Purpose:  Retrieves the current manufacturing operation.
 
   Input Arguments:
      mfg_solid            - The handle to the manufacturing solid

   Output Arguments:
      oper_feat            - The handle to a manufacturing operation feature
 
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_E_NOT_FOUND   - No active operation feature was found.
      PRO_TK_BAD_INPUTS    - The argument is invalid.
*/

PRO_END_C_DECLS


#endif /* PROMFGOPER_H */
