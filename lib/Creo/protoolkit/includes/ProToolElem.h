#ifndef PROTOOLELEM_H_FILE
#define PROTOOLELEM_H_FILE

/* ProToolElem.h: definitions and action functions for ProToolElem objects */

#include <ProElement.h>
#include <ProParamval.h>





PRO_BEGIN_C_DECLS


typedef struct Pro_Elem  *ProToolElem;


extern ProError  ProToolElemParamAdd (ProToolElem                   elem,
                                      PRO_CONST_ARG ProParamvalue  *param_value,
                                      PRO_CONST_ARG ProCharName     param_name);
/*
   Purpose:  Stores an additional parameter in a <i>ProToolElem</i> data
             structure.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_PARAMS

   Input Arguments:
      elem           - The <i>ProToolElem</i> in which to store the parameter
      param_value    - The value of the parameter to add
      param_name     - The name of the parameter to add

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully added the parameter.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProToolElemAttrSet  (ProToolElem   elem, 
                                      int           attrs);
/*
   Purpose:  Stores the specified tool attributes in a <i>ProToolElem</i> data 
             structure.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_ATTRIBUTES

   Input Arguments:
      elem           - The <i>ProToolElem</i> in which to store the attributes 
      attrs          - The attributes to be stored

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the attributes.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProToolElemModelSet (ProToolElem            elem,
                                      PRO_CONST_ARG  ProMdl  tool_model);
/*
   Purpose:  Stores the specified reference to a tool model in a 
             <i>ProToolElem</i> data structure.  
 
<p>
   Applicable Element Id(s):
<p>
      PRO_E_TOOL_MODEL

   Input Arguments:
      elem           - The <i>ProToolElem</i> in which to store the tool model 
                       reference.
      tool_model     - The handle to the model. Currently, this must be a
                       solid.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the reference.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


PRO_END_C_DECLS


#endif  /* PROTOOLELEM_H_FILE */
