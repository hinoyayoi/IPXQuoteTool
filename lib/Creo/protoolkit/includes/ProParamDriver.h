#ifndef PROPARAMDRIVER_H
#define PROPARAMDRIVER_H



#include 	<ProUserdefFunction.h>
#include 	<ProParameter.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_PARAMDRIVER_NONE,   /* No driver, just uses value */
  PRO_PARAMDRIVER_PARAM,
  PRO_PARAMDRIVER_FUNCTION,
  PRO_PARAMDRIVER_RELATION
} ProParameterDriver;

/*===========================================================================*/

extern ProError ProParameterDriverGet (ProParameter* material_parameter, 
                                       ProParameterDriver* driver);
/*
    Purpose: Obtains the type of driver for a model parameter.

    Input Arguments:
        material_parameter - The model parameter.

    Output Arguments:
        driver - The type of operation driving this value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProParameterValueGet()
        ProParameterDrivingparamGet()
        ProParameterDrivingfunctionGet()
*/

/*===========================================================================*/

extern ProError ProParameterDrivingparamGet (ProParameter* material_parameter, 
                                             ProParameter* driving_param);
/*
    Purpose: Obtains the driving parameter for a material parameter, if the
             driver type is PRO_PARAMDRIVER_PARAM.

    Input Arguments:
        material_parameter - The material parameter.

    Output Arguments:
        driving_param - The driving parameter.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The driver type is not 'parameter'.

*/

/*===========================================================================*/

extern ProError ProParameterDrivingparamSet (ProParameter* material_parameter, 
                                             ProParameter* driving_param);
/*
    Purpose: Assigns the driving parameter for a material parameter.  This will
             set the driver type to be PRO_PARAMDRIVER_PARAM.

    Input Arguments:
        material_parameter - The material parameter.
        driving_param - The driving parameter.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - This parameter cannot be driven by another
                             parameter.

*/

/*===========================================================================*/

extern ProError ProParameterDrivingFunctionGet (ProParameter* material_parameter, 
                                                ProUserdefFunction* driving_function);

/*
    Purpose: Obtains the driving function for the parameter, if the driver type
             is PRO_PARAMDRIVER_FUNCTION.

    Input Arguments:
        material_parameter - The material parameter.

    Output Arguments:
        driving_function - The driving function

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The driver type is not 'function'.

*/

/*===========================================================================*/

extern ProError ProParameterDrivingFunctionSet (ProParameter* material_parameter, 
                                                ProUserdefFunction* driving_function);
/*
    Purpose: Assigns the driving function for the parameter.  This will set the
             driver type to be PRO_PARAMDRIVER_FUNCTION.

    Input Arguments:
        material_parameter - The material parameter.
        driving_function - The driving function

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - This parameter cannot be driven by a function.

*/

PRO_END_C_DECLS

#endif
