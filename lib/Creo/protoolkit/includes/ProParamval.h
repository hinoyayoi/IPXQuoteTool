#ifndef PROPARAMVAL
#define PROPARAMVAL

#include <ProToolkit.h>





PRO_BEGIN_C_DECLS


typedef enum  param_value_types  {
   PRO_PARAM_DOUBLE  = 50, /* use d_val from ProParamvalueValue to set value */
   PRO_PARAM_STRING  = 51, /* use s_val from ProParamvalueValue to set value */
   PRO_PARAM_INTEGER = 52, /* use i_val from ProParamvalueValue to set value */
   PRO_PARAM_BOOLEAN = 53, /* use l_val from ProParamvalueValue to set value */
   PRO_PARAM_NOTE_ID = 54, /* use i_val from ProParamvalueValue to set value */
   PRO_PARAM_VOID    = 57,
   PRO_PARAM_NOT_SET = 58
}  ProParamvalueType;

typedef union param_value_values {
    double  d_val;
    int     i_val;
    short   l_val;
    ProLine s_val;
}  ProParamvalueValue;

typedef struct  Pro_Param_Value  {
  ProParamvalueType  	type;
  ProParamvalueValue    value;
}  ProParamvalue;

typedef struct proParamInfo {
   ProName      	param_name;
  
   int                  owner_id;	/* may be PRO_VALUE_UNUSED */
   int                  owner_type;	/* may be PRO_VALUE_UNUSED */
   ProParamvalue        param_value;
} ProParamInfo; 

extern ProError  ProParamvalueSet  (ProParamvalue      *p_handle,
                                    PRO_CONST_ARG void *p_value, 
                                    ProParamvalueType   type);
/*
   Purpose:  Sets the fields of a <i>ProParamvalue</i> data structure.

   Input Arguments:
      p_handle   - The pointer to the <i>ProParamvalue</i> to be set.
      p_value    - The pointer to the data to be placed in the <i>value</i> 
                   field. The data passed should be a pointer to a
                   double, int, short, or <i>wchar_t</i>*.
      type       - The type of data to be stored.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the fields.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProParamvalueValueGet (PRO_CONST_ARG  ProParamvalue  *p_handle,
                                     ProParamvalueType              type,
                                     void                          *r_value);
/*
   Purpose:  Retrieves the <i>value</i> field of a <i>ProParamvalue</i> 
             data structure.

   Input Arguments:
      p_handle       - The pointer to the <i>ProParamvalue</i> to be queried.
      type           - The type of data stored in the <i>ProParamvalue</i>. 
                       You retrieve this information by calling the
                       function <b>ProParamvalueTypeGet()</b>. 

   Output Arguments:
      r_value        - The pointer to the memory in which the value should 
                       be placed. The <i>r_value</i> should point to an int, 
                       double, short, or <i>ProLine</i>, as appropriate for 
                       the <i>type</i> specified.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.

   See Also:
      ProParamvalueTypeGet()
*/


extern ProError  ProParamvalueTypeGet (PRO_CONST_ARG  ProParamvalue *p_handle,
                                        ProParamvalueType            *r_type);
/*
   Purpose:  Retrieves the <i>type</i> field of a <i>ProParamvalue</i> 
             data structure.

   Input Arguments:
      p_handle       - The pointer to the <i>ProParamvalue</i> to be queried

   Output Arguments:
      r_type         - The <i>type</i> field of the <i>ProParamvalue</i> 
                       structure

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


PRO_END_C_DECLS


#endif /* PROPARAMVAL */
