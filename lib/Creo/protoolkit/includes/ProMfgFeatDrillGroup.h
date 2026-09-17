#ifndef PROMFGFEATDRILLGROUP_H
#define PROMFGFEATDRILLGROUP_H
/*
   Creo Parametric TOOLKIT declarations related to mfg drill group feature.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Feature element tree

 PRO_E_FEATURE_TREE
    |   
    |-- PRO_E_FEATURE_TYPE
    |
    |-- PRO_E_STD_FEATURE_NAME
    |
    |-- PRO_E_DRILL_GRP_CSYS
    |
    |-- PRO_E_DRILL_GRP_AXES_COMPOUND
           |
           |-- PRO_E_DRILL_GRP_AXES_EXCL
           |
           |-- PRO_E_DRILL_GRP_AXES_PATTERN
           |
           |-- PRO_E_DRILL_GRP_RULES_COMPOUND
           |      |
           |      |-- PRO_E_DRILL_GRP_SURFACES
           |      |
           |      |----PRO_E_DRILL_GRP_DIAM_TYPE_OPT
           |      |
           |      |-- PRO_E_DRILL_GRP_DIAM_ARR
           |      |      |
           |      |      |-- PRO_E_DRILL_GRP_DIAM_COPMPOUND
           |      |             |
           |      |             |-- PRO_E_DRILL_GRP_DIAM
           |      |
           |      |-- PRO_E_DRILL_GRP_PARAM_RULE_OPT
           |      |
           |      |-- PRO_E_DRILL_GRP_PARAM_ARR
           |             |
           |             |-- PRO_E_DRILL_GRP_PARAM_COMPOUND
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_NAME
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_DATA_TYPE
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_OPER
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_VAL_INT
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_VAL_DBL
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_VAL_WSTR
           |                    |
           |                    |-- PRO_E_DRILL_GRP_PARAM_VAL_BOOL
           |
           |-- PRO_E_DRILL_GRP_AXES_INDIV

===============================================================================

(2) Elements table

-------------------------------------------------------------------------------------------
Element Id                      Element Name         Data Type                 Valid Values
-------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE              Feature Type         PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME          Feature Name         PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_DRILL_GRP_CSYS            Coordinate System    PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_DRILL_GRP_AXES_COMPOUND   Holes Compound       Compound                  Note-4
PRO_E_DRILL_GRP_AXES_INDIV      Individual Axes      PRO_VALUE_TYPE_SELECTION  Note-5
PRO_E_DRILL_GRP_AXES_EXCL       Excluded Axes        PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_DRILL_GRP_AXES_PATTERN    Patterns             PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_DRILL_GRP_RULES_COMPOUND  Holes by Rules       Compound                  Note-8
PRO_E_DRILL_GRP_SURFACES        Surfaces with holes  PRO_VALUE_TYPE_SELECTION  Note-9
PRO_E_DRILL_GRP_DIAM_ARR        Diameter Array       Array                     Note-10
PRO_E_DRILL_GRP_DIAM_COPMPOUND  Diameter Compound    Compound                  Note-11
PRO_E_DRILL_GRP_DIAM            Diameter             PRO_VALUE_TYPE_DOUBLE     Note-12
PRO_E_DRILL_GRP_PARAM_ARR       Parameter Array      Array                     Note-13
PRO_E_DRILL_GRP_PARAM_COMPOUND  Parameter Compound   Compound                  Note-14
PRO_E_DRILL_GRP_PARAM_NAME      Parameter Name       PRO_VALUE_TYPE_WSTRING    Note-15
PRO_E_DRILL_GRP_PARAM_DATA_TYPE Data Type            PRO_VALUE_TYPE_INT        Note-16
PRO_E_DRILL_GRP_PARAM_OPER      Operator             PRO_VALUE_TYPE_INT        Note-17
PRO_E_DRILL_GRP_PARAM_VAL_INT   Integer Value        PRO_VALUE_TYPE_INT        Note-18
PRO_E_DRILL_GRP_PARAM_VAL_DBL   Double Value         PRO_VALUE_TYPE_DOUBLE     Note-19
PRO_E_DRILL_GRP_PARAM_VAL_WSTR  String Value         PRO_VALUE_TYPE_WSTRING    Note-20
PRO_E_DRILL_GRP_PARAM_VAL_BOOL  Boolean Value        PRO_VALUE_TYPE_INT        Note-21
PRO_E_DRILL_GRP_DIAM_TYPE_OPT   Diameter Types       PRO_VALUE_TYPE_INT        Note-22
PRO_E_DRILL_GRP_PARAM_RULE_OPT  Parameter Rule Opt   PRO_VALUE_TYPE_INT        Note-23

===============================================================================

(3) Notes

Note-1  : PRO_FEAT_DRL_GRP
          Mandatory.

Note-2  : Feature name.
          Optional.

Note-3  : Selection of datum csys.
          Not implemented.

Note-4  : Compound information about location of holes to drill.
          Mandatory. At least one of the following children elements
          has to be defined:
             PRO_E_DRILL_GRP_AXES_INDIV,
             PRO_E_DRILL_GRP_AXES_PATTERN,
             PRO_E_DRILL_GRP_SURFACES,
             PRO_E_DRILL_GRP_DIAM_ARR,
             PRO_E_DRILL_GRP_PARAM_ARR.

Note-5  : Selection of datum axes.
          Element supports multiple selections.
          Mandatory if none of the following elements is defined:
             PRO_E_DRILL_GRP_AXES_PATTERN,
             PRO_E_DRILL_GRP_SURFACES,
             PRO_E_DRILL_GRP_DIAM_ARR,
             PRO_E_DRILL_GRP_PARAM_ARR.

Note-6  : Selection of axes of holes to be excluded for machining.
          Element supports multiple selections.
          Optional.

Note-7  : Selection of axes of patterned holes.
          Element supports multiple selections.
          If a pattern leader is selected, all holes in pattern
          will be collected.
          Optional.

Note-8  : Compound information about hole search rules.
          Optional.

Note-9  : Selection of surfaces (or quilts) with holes.
          Element supports multiple selections.
          Optional.

Note-10 : Array of diameters of holes to machine.
          Optional.

Note-11 : Compound definition of a hole diameter.
          Optional.

Note-12 : Diameter of a hole to machine.
          Mandatory child of PRO_E_DRILL_GRP_DIAM_COPMPOUND element.

Note-13 : Array of search conditions to collect holes to machine.
          Optional.

Note-14 : Compound definition of a condition to match with hole features
          user defined parameters.
          Each condition defines expression with user defined parameter
          name on the left side of the expression and value to compare on
          the right side.
          Optional.

Note-15 : Name of user defined parameter.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element.

Note-16 : Data type of value.
          Values defined by ProParamvalueType.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element.

Note-17 : Type of expression operator.
          Values defined by ProDrillParamOper.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element.

Note-18 : Value of type double.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element
          for double data type (PRO_E_DRILL_GRP_PARAM_DATA_TYPE is set to
          PRO_PARAM_DOUBLE).  Ignored for other data types.

Note-19 : Value of type integer.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element
          for integer data type (PRO_E_DRILL_GRP_PARAM_DATA_TYPE is set to
          PRO_PARAM_INTEGER).  Ignored for other data types.

Note-20 : Value of type string.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element
          for integer data type (PRO_E_DRILL_GRP_PARAM_DATA_TYPE is set to
          PRO_PARAM_STRING).  Ignored for other data types.

Note-21 : Value of type ProBoolean.
          Mandatory child of PRO_E_DRILL_GRP_PARAM_COMPOUND element
          for integer data type (PRO_E_DRILL_GRP_PARAM_DATA_TYPE is set to
          PRO_PARAM_BOOLEAN).  Ignored for other data types.

Note-22 : Type of diameters collected in PRO_E_DRILL_GRP_DIAM_ARR.
          Values defined by ProHolesetDiamType.
          PRO_HSET_ALL_DIAMS - all diameter, including diameters of 
                               solid surfaces and diameters of 
                               cosmetic threads.
          PRO_HSET_HOLE_DIAMS - diameters of solid surfaces.
          PRO_HSET_THREAD_DIAMS - diameters of cosmetic threads.
          Optional (PRO_HSET_ALL_DIAMS is used if the element is not defined).

Note-23 : Type of query applied for search.
          Ignored for points holeset.
          Values defined by ProHsetParamRuleOpt.
          PRO_HSET_BOOL_OPER_OR  - Collects holes with at least one parameter.
          PRO_HSET_BOOL_OPER_AND - Collect holes with with combination of all 
                                   parameters.
          Optional (PRO_HSET_BOOL_OPER_OR is used if the element is not 
          defined).

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGFEATDRILLGROUP_H */
