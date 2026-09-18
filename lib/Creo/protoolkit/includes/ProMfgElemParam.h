#ifndef PROMFGELEMPARAM_H
#define PROMFGELEMPARAM_H
/*
   Creo Parametric TOOLKIT declarations related to mfg parameters specification
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree

  -- PRO_E_MFG_PARAM_ARR
        |
        |-- PRO_E_MFG_PARAM_COMPOUND
               |
               |-- PRO_E_MFG_PRM_NAME
               |
               |-- PRO_E_MFG_PRM_ATTR
               |
               |-- PRO_E_MFG_PRM_VAL_DBL
               |
               |-- PRO_E_MFG_PRM_VAL_STR

==============================================================================

(2) Elements table

------------------------------------------------------------------------------
Element Id                Element Name     Data Type               Valid Value
------------------------------------------------------------------------------
PRO_E_MFG_PARAM_ARR       Mfg Param Arr    Array                   Note-1 
PRO_E_MFG_PARAM_COMPOUND  Mfg Parameter    Compound                Note-2 
PRO_E_MFG_PRM_NAME        Param Name       PRO_VALUE_TYPE_WSTRING  Note-3 
PRO_E_MFG_PRM_ATTR        Param Attribute  PRO_VALUE_TYPE_INT      Note-4 
PRO_E_MFG_PRM_VAL_DBL     Double Value     PRO_VALUE_TYPE_DOUBLE   Note-5 
PRO_E_MFG_PRM_VAL_STR     String Value     PRO_VALUE_TYPE_WSTRING  Note-6 

==============================================================================

(3) Notes

Note-1 : Array of applicable manufacturing parameters.
         For new features: if parameter is not defined in array - default 
         value is going to be assigned to the corresponding manufacturing 
         parameter of the created feature. 

         Default values for manufacturing parameters of tool motions are 
         copied from corresponding parameters of parent sequence. 

         Default values for manufacturing parameters of features are 
         copied from site information if site name is specified by 
         PRO_E_MFG_PARAM_SITE_NAME element. Otherwise values are assigned 
         based on system defaults (if such defaults exist).

Note-2 : Compound element - defines parameter name, attribute and value.
         Value data type and parameter name dependency is hardcoded.
         Mandatory - for applicable parameters with undefined default values 
         ("CUT_FEED", "SPINDLE_SPEED", etc.).

Note-3 : Untranslated parameter name - from the list predefined names.
         Mandatory child of PRO_E_MFG_PARAM_COMPOUND element.

Note-4 : Option to define logic for parameter value assignment.
         Values defined by ProMfgParamAttr:

         PRO_MFG_PRM_ATTR_MODIFIED   - Value from PRO_E_MFG_PRM_VAL_DBL or
                                       PRO_E_MFG_PRM_VAL_STR is going to be
                                       assigned to the corresponding mfg 
                                       parameter.
         PRO_MFG_PRM_ATTR_DEFAULT    - Default value (supplied by Pro/NC) 
                                       is going to be assigned to the 
                                       corresponding mfg parameter.
                                       Use PRO_MFG_PRM_ATTR_DEFAULT to set 
                                       param value to dash (if applicable).
                                       Value from PRO_E_MFG_PRM_VAL_DBL or
                                       PRO_E_MFG_PRM_VAL_STR is ignored.
         PRO_MFG_PRM_ATTR_INHERITED  - Value from site or parent sequence 
                                       (for tool motion parameters) is going 
                                       to be assigned to the corresponding 
                                       mfg parameter. 
                                       Value from PRO_E_MFG_PRM_VAL_DBL or
                                       PRO_E_MFG_PRM_VAL_STR is going to be 
                                       used only if site with corresponding 
                                       name doesn't exist in mfg model (site 
                                       name is specified by 
                                       PRO_E_MFG_PARAM_SITE_NAME element in 
                                       sequence elem tree).
                                       specification in sequence elem tree).
         PRO_MFG_PRM_ATTR_AUTOMATIC  - Value will be assigned automatically: 
                                       either from site (if exists), or from
                                       system defaults.
                                       Value from PRO_E_MFG_PRM_VAL_DBL or
                                       PRO_E_MFG_PRM_VAL_STR is ignored.

         Mandatory child of PRO_E_MFG_PARAM_COMPOUND element.

Note-5 : Value of type double.
         Mandatory for "double data type" parameters with attribute (see 
         above) set to PRO_MFG_PRM_ATTR_MODIFIED. Ignored for othere data
         types.

Note-6 : Value of type string. 
         Mandatory for "string data type" parameters with attribute (see 
         above) set to PRO_MFG_PRM_ATTR_MODIFIED. Ignored for othere data
         types.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMPARAM_H*/
