#ifndef PRO_ELEMENT_OPTIONS_H
#define PRO_ELEMENT_OPTIONS_H



PRO_BEGIN_C_DECLS

#include <ProToolkit.h>

typedef void* ProElementReferenceOptions;

typedef void* ProElementIntegerOptions;

typedef void* ProElementDoubleOptions;

typedef void* ProElementWstringOptions;

typedef void* ProElementStringOptions;

typedef void* ProElementSpecialOptions;

typedef void* ProElementBooleanOptions;

typedef void* ProElementTransformOptions;

/*===========================================================================*/
/*===========================================================================*/



/*===========================================================================*/
extern ProError ProElementwstroptsAlloc (ProElementWstringOptions* options);
/*
   Purpose: Allocates the options used to retrieve string values.

   Input Arguments:
         none

   Output Arguments:
         options            - The options.

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.

   See Also:
		ProElementWstringGet()

*/

/*===========================================================================*/
extern ProError ProElementwstroptsExpressionsSet (
                                  ProElementWstringOptions options,
                                  ProBoolean               as_expression);
/*
   Purpose: Sets the options to retrieve values as expressions or
            relations instead of string representations of the actual
            value, if they exist. Applicable to double value elements only.

   Input Arguments:
         options            - The options.
         as_expression      - PRO_B_TRUE to obtain values as expression
                            if possible.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.

   See Also:
		ProElementWstringGet()
*/

/*===========================================================================*/
extern ProError ProElementwstroptsSignoptionsSet(
                                  ProElementWstringOptions options,
                                  ProBoolean               as_positive,
                                  ProBoolean               with_sign);
/*
   Purpose: Sets the options to retrieve values as positive or 
            with/without sign. Applicable to double and integer 
            value elements only.

   Input Arguments:
         options            - The options.
         as_positive        - PRO_B_TRUE if retrive absolute value only or
                            PRO_B_FALSE if retrive value as is.
         with_sign          - PRO_B_TRUE if retrive with value sign (+/-) or
                            PRO_B_FALSE if retrive value as is
                            (positive without sign, negative with sign)

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.

   See Also:
		ProElementWstringGet()
*/

/*===========================================================================*/
extern ProError ProElementwstroptsFree (ProElementWstringOptions options);
/*
   Purpose: Frees the options used to retrieve string values.

   Input Arguments:
         options            - The options.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR    - The function succeeded.
         PRO_TK_BAD_INPUTS  - One or more arguments was invalid.

   See Also:
		ProElementWstringGet()
*/

PRO_END_C_DECLS
#endif /* PRO_ELEMENT_OPTIONS_H */
