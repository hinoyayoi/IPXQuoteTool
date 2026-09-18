#ifndef PROMFGELEMTHREADHOLESET_H
#define PROMFGELEMTHREADHOLESET_H
/*
   Creo Parametric TOOLKIT declarations related to mfg thread milling holeset
*/



#include <ProToolkit.h>
#include <ProMfgOptions.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree

     -- PRO_E_MFG_THRM_HOLESET_ARR
           |
           |-- PRO_E_MFG_THRM_HOLESET_COMPOUND
                  |
                  |-- PRO_E_HOLESET_ID
                  |
                  |-- PRO_E_HOLESET_START
                  |      |
                  |      |--PRO_E_HOLESET_START_TYPE
                  |      |
                  |      |--PRO_E_HOLESET_START_SURFACE
                  |
                  |-- PRO_E_MFG_THRM_HSET_END_COMPOUND
                  |      |
                  |      |--PRO_E_HOLESET_END_TYPE
                  |      |
                  |      |--PRO_E_HOLESET_END_SURFACE
                  |      |
                  |      |--PRO_E_HOLESET_DEPTH_VALUE
                  |
                  |-- PRO_E_DRILL_PART_DATA
                  |      |
                  |      |--PRO_E_DRILL_PARTS
                  |      |
                  |      |--PRO_E_AUTO_SEL_DRILL_PARTS
                  |
                  |
                  |-- PRO_E_MFG_THRM_HSET_HOLES_COMP
                  |      |
                  |      |--PRO_E_HOLESET_SEL_AXIS_PATTS
                  |      |
                  |      |--PRO_E_HOLESET_SEL_BY_SURFACES
                  |      |
                  |      |--PRO_E_MFG_HSET_DIAM_TYPE_OPT
                  |      |
                  |      |--PRO_E_MFG_HSET_DIAM_ARR
                  |      |     |
                  |      |     |--PRO_E_MFG_HSET_DIAM_COMPOUND
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_HOLE_DIAM
                  |      |
                  |      |--PRO_E_MFG_HSET_THREAD_DESCR_ARR
                  |      |     |
                  |      |     |--PRO_E_MFG_HSET_THREAD_DESCR_COMP
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_THREAD_DESCR
                  |      |
                  |      |--PRO_E_MFG_HSET_PARAM_RULE_OPT
                  |      |
                  |      |--PRO_E_MFG_HSET_PARAM_ARR
                  |      |     |
                  |      |     |--PRO_E_MFG_HSET_PARAM_COMPOUND
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_NAME
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_DTYPE
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_OPER
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_DBL
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_INT
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_STR
                  |      |           |
                  |      |           |--PRO_E_MFG_HSET_PARAM_VAL_BOOL
                  |      |
                  |      |--PRO_E_HOLESET_SEL_INDIV_AXES
                  |      |
                  |      |--PRO_E_HOLESET_SEL_UNSEL_AXES
                  |
                  |-- PRO_E_MFG_HSET_START_HOLE_REF

===============================================================================

(2) Elements table

---------------------------------------------------------------------------------------------------
Element Id                              Element Name         Data Type                 Valid Values
---------------------------------------------------------------------------------------------------
PRO_E_MFG_THRM_HOLESET_ARR              Thread Holesets      Array                     Note-1
PRO_E_MFG_THRM_HOLESET_COMPOUND         Thread Holeset       Compound                  Note-2
PRO_E_HOLESET_ID                        Holeset Id           PRO_VALUE_TYPE_INT        Note-3
PRO_E_HOLESET_TYPE                      Holeset Type         PRO_VALUE_TYPE_INT        Note-4
PRO_E_HOLESET_START                     Holeset Start        Compound                  Note-5
PRO_E_HOLESET_START_TYPE                Start Type           PRO_VALUE_TYPE_INT        Note-6
PRO_E_HOLESET_START_SURFACE             Start Surface        PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_MFG_THRM_HSET_END_COMPOUND        Thread Holeset End   Compound                  Note-8
PRO_E_HOLESET_END_TYPE                  Depth Type Option    PRO_VALUE_TYPE_INT        Note-9
PRO_E_HOLESET_END_SURFACE               End Surface          PRO_VALUE_TYPE_SELECTION  Note-10
PRO_E_HOLESET_DEPTH_VALUE               Depth Value          PRO_VALUE_TYPE_DOUBLE     Note-11
PRO_E_DRILL_PART_DATA                   Part Data            Compound                  Note-12
PRO_E_AUTO_SEL_DRILL_PARTS              Auto Option          PRO_VALUE_TYPE_INT        Note-13
PRO_E_DRILL_PARTS                       Parts                PRO_VALUE_TYPE_SELECTION  Note-14
PRO_E_MFG_THRM_HSET_HOLES_COMP          Thread Holes         Compound                  Note-15
PRO_E_HOLESET_SEL_AXIS_PATTS            Patterns             PRO_VALUE_TYPE_SELECTION  Note-16
PRO_E_HOLESET_SEL_BY_SURFACES           Surfaces with holes  PRO_VALUE_TYPE_SELECTION  Note-17
PRO_E_MFG_HSET_DIAM_ARR                 Diameter Array       Array                     Note-18
PRO_E_MFG_HSET_DIAM_COMPOUND            Diameter Compound    Compound                  Note-19
PRO_E_MFG_HSET_HOLE_DIAM                Diameter             PRO_VALUE_TYPE_DOUBLE     Note-20
PRO_E_MFG_HSET_THREAD_DESCR_ARR         Thread Descriptions  Array                     Note-21
PRO_E_MFG_HSET_THREAD_DESCR_COMP        Description Compoud  Compound                  Note-22
PRO_E_MFG_HSET_THREAD_DESCR             Thread Description   PRO_VALUE_TYPE_WSTRING    Note-23
PRO_E_MFG_HSET_PARAM_ARR                Parameter Array      Array                     Note-24
PRO_E_MFG_HSET_PARAM_COMPOUND           Parameter Compound   Compound                  Note-25
PRO_E_MFG_HSET_PARAM_NAME               Parameter Name       PRO_VALUE_TYPE_WSTRING    Note-26
PRO_E_MFG_HSET_PARAM_DTYPE              Data Type            PRO_VALUE_TYPE_INT        Note-27
PRO_E_MFG_HSET_PARAM_OPER               Operator             PRO_VALUE_TYPE_INT        Note-28
PRO_E_MFG_HSET_PARAM_VAL_DBL            Double Value         PRO_VALUE_TYPE_DOUBLE     Note-29
PRO_E_MFG_HSET_PARAM_VAL_INT            Integer Value        PRO_VALUE_TYPE_INT        Note-30
PRO_E_MFG_HSET_PARAM_VAL_STR            String Value         PRO_VALUE_TYPE_WSTRING    Note-31
PRO_E_MFG_HSET_PARAM_VAL_BOOL           Boolean Value        PRO_VALUE_TYPE_INT        Note-32
PRO_E_HOLESET_SEL_INDIV_AXES            Individual Axes      PRO_VALUE_TYPE_SELECTION  Note-33
PRO_E_HOLESET_SEL_UNSEL_AXES            Excluded Axes        PRO_VALUE_TYPE_SELECTION  Note-34
PRO_E_MFG_HSET_START_HOLE_REF           Start Hole           PRO_VALUE_TYPE_SELECTION  Note-35
PRO_E_MFG_HSET_DIAM_TYPE_OPT            Diameter Types       PRO_VALUE_TYPE_INT        Note-36
PRO_E_MFG_HSET_PARAM_RULE_OPT           Parameter Rule Opt   PRO_VALUE_TYPE_INT        Note-37

===============================================================================

(3) Notes

Note-1  : Array of thread holesets - specification of machining references.

Note-2  : Thread holeset definition.
          Mandatory (holeset array should have at least one member).

Note-3  : Holeset id.
          Internal use only. Should not be added or modified.

Note-4  : Holeset type - PRO_HOLESET_DRILL_AXES.
          Mandatory.

Note-5  : Holemaking start compound specification.
          Mandatory.

Note-6  : Start surface option.
          Values defined by ProDrillStartType.
          Mandatory.

Note-7  : Starting surface or quilt selection.
          Mandatory if PRO_E_HOLESET_START_TYPE is set to
          PRO_DRILL_FROM_SURFACE.  

Note-8  : Thread depth compound specification.
          Mandatory.

Note-9  : End type option.
            PRO_DRILL_UPTO_SURFACE,
            PRO_DRILL_AUTO_END,
            PRO_DRILL_OFFSET_FROM_START.
          Mandatory.

Note-10 : End surface or quilt selection.
          Mandatory if PRO_E_HOLESET_END_TYPE is set to PRO_DRILL_UPTO_SURFACE. 
          Ignored in all other cases.

Note-11 : Depth to cut thread from start.
          Mandatory if PRO_E_HOLESET_END_TYPE is set to 
          PRO_DRILL_OFFSET_FROM_START. Ignored in all other cases.

Note-12 : Compound information about components used in depth computation.
          Mandatory if start or end of machining has to be 
          computed - either (1) or (2) or (3):
          (1). PRO_E_HOLESET_START_TYPE is set to PRO_DRILL_AUTO_START. 
          (2). PRO_E_HOLESET_END_TYPE is set to PRO_DRILL_AUTO or 
               PRO_DRILL_THRU_ALL 
          (3). PRO_E_HOLESET_DEPTH_TYPE is set to PRO_DRILL_AUTO or 
               PRO_DRILL_THRU_ALL 

Note-13 : Option defines the way components are collected.
          TRUE  - all components of type "reference part" or "workpiece"
                  are considered for depth calculation.
          FALSE - Only selected components are considered in depth 
                  calculation.
          Mandatory.

Note-14 : Components selections.
          Element supports multiple selections.
          Mandatory if PRO_E_AUTO_SEL_DRILL_PARTS is set to FALSE. 
          Ignored if PRO_E_AUTO_SEL_DRILL_PARTS is set to FALSE.

Note-15 : Compound information about location of holes.
          Mandatory. At least one of the following children elements 
          has to be defined:
             PRO_E_HOLESET_SEL_INDIV_AXES,
             PRO_E_HOLESET_SEL_AXIS_PATTS,
             PRO_E_HOLESET_SEL_BY_SURFACES,
             PRO_E_MFG_HSET_THREAD_DESCR_ARR,
             PRO_E_MFG_HSET_DIAM_ARR,
             PRO_E_MFG_HSET_PARAM_ARR.

Note-16 : Selection of axes of patterned holes. 
          Element supports multiple selections.
	  If a pattern leader is selected, all holes in pattern
          will be collected. 
          Optional.

Note-17 : Selection of surfaces (or quilts) with holes.
          Element supports multiple selections.
          Optional.

Note-18 : Array of diameters of holes to machine.
          Optional.

Note-19 : Compound definition of a hole diameter.
          Optional.

Note-20 : Diameter of a hole to machine.
          Mandatory child of PRO_E_MFG_HSET_DIAM_COMPOUND element.

Note-21 : Array of thread descriptions of holes to machine.
          Optional.

Note-22 : Compound definition of a thread description.
          Optional.

Note-23 : Thread size string.
          Mandatory child of PRO_E_MFG_HSET_THREAD_DESCR_COMP element.

Note-24 : Array of search conditions to collect holes to machine.
          Optional.

Note-25 : Compound definition of a condition to match with hole features
          user defined parameters.
          Each condition defines expression with user defined parameter 
          name on the left side of the expression and value to compare on 
          the right side.
          Optional.

Note-26 : Name of user defined parameter.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element.

Note-27 : Data type of value.
          Values defined by ProParamvalueType.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element.

Note-28 : Type of expression operator.
          Values defined by ProDrillParamOper.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element.

Note-29 : Value of type double.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for double data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_DOUBLE).  Ignored for other data types.

Note-30 : Value of type integer.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for integer data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_INTEGER).  Ignored for other data types.

Note-31 : Value of type string.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for integer data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_STRING).  Ignored for other data types.

Note-32 : Value of type ProBoolean.
          Mandatory child of PRO_E_MFG_HSET_PARAM_COMPOUND element
          for integer data type (PRO_E_MFG_HSET_PARAM_DTYPE is set to 
          PRO_PARAM_BOOLEAN).  Ignored for other data types.

Note-33 : Selection of datum axes.
          Element supports multiple selections.
          Mandatory if none of the following elements is defined:
             PRO_E_HOLESET_SEL_AXIS_PATTS,
             PRO_E_HOLESET_SEL_BY_SURFACES,
             PRO_E_MFG_HSET_THREAD_DESCR_ARR,
             PRO_E_MFG_HSET_DIAM_ARR,
             PRO_E_MFG_HSET_PARAM_ARR.

Note-34 : Selection of axes of holes to be excluded for machining.
          Element supports multiple selections.
          Optional.

Note-35 : Axis selection for the hole to be machined first.
          Optional.
     
Note-36 : Type of diameters collected in PRO_E_MFG_HSET_DIAM_ARR.
          Values defined by ProHolesetDiamType.
          PRO_HSET_ALL_DIAMS - all diameter, including diameters of 
                               solid surfaces and diameters of 
                               cosmetic threads.
          PRO_HSET_HOLE_DIAMS - diameters of solid surfaces.
          PRO_HSET_THREAD_DIAMS - diameters of cosmetic threads.
          Optional (PRO_HSET_ALL_DIAMS is used if the element is not defined).

Note-37 : Type of query applied for search.
          Ignored for points holeset.
          Values defined by ProHsetParamRuleOpt.
          PRO_HSET_BOOL_OPER_OR  - Collects holes with at least one parameter.
          PRO_HSET_BOOL_OPER_AND - Collect holes with with combination of all 
                                   parameters.
          Optional (PRO_HSET_BOOL_OPER_OR is used if the element is not 
          defined).

=============================================================================*/


PRO_END_C_DECLS

#endif /* PROMFGELEMTHREADHOLESET_H */
