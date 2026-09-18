#ifndef PROUSERDEFFUNC_H
#define PROUSERDEFFUNC_H



#include 	<ProObjects.h>

PRO_BEGIN_C_DECLS

typedef struct prouserdeffunc
{
  ProName       func_name;
  ProMdl        owner;  /* NULL means the Function from Library */
} ProUserdefFunction;
/*===========================================================================*/

extern ProError ProUserdefFunctionInit (ProMdl              owner,
                                        ProName             func_name,
                                        ProUserdefFunction *func);
/*
    Purpose:	Initializes a User Defined Function data structure.

    Input Arguments:
         owner		- The model to which the Function belongs.
                          NULL means the Function belongs to a Library.
         func_name      - The name of the Function.

    Output Arguments:
         func           - The initialized ProUserdefFunction handle.

   Return Values:
	PRO_TK_NO_ERROR		- The function successfully initialized
                                  the handle.
	PRO_TK_BAD_INPUTS	- One or more of the input arguments are
                                  invalid.
	PRO_TK_E_NOT_FOUND	- The Function was not found within the
                                  owner.

*/

PRO_END_C_DECLS

#endif
