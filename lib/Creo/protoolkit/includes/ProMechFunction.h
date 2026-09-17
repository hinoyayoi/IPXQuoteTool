#ifndef PROMECHFUNCTION_H
#define PROMECHFUNCTION_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechGeomref.h>

typedef enum
{
  PRO_MECH_FUNC_UNIVERSAL       = PRO_VALUE_UNUSED,

  PRO_MECH_FUNC_COORD           = 0,
  PRO_MECH_FUNC_TIME            = 2,
  PRO_MECH_FUNC_TEMPERATURE     = 3,
  PRO_MECH_FUNC_DEFLECTION      = 4,
  PRO_MECH_FUNC_ARCLENGTH       = 5,
  PRO_MECH_FUNC_COORDS_TIME     = 6,
  PRO_MECH_FUNC_ARCLENGTH_TIME  = 7
}
ProMechfuncVarType;

typedef enum
{
  PRO_MECH_FUNCTION_NONE     = PRO_VALUE_UNUSED,

  PRO_MECH_FUNCTION_SYMBOLIC = 0,
  PRO_MECH_FUNCTION_TABLE    = 1
}
ProMechfuncType;

typedef enum
{
  PRO_MECH_INDEP_VAR_NONE        = PRO_VALUE_UNUSED,

  PRO_MECH_INDEP_VAR_X           = 0,
  PRO_MECH_INDEP_VAR_Y           = 1,
  PRO_MECH_INDEP_VAR_Z           = 2,
  PRO_MECH_INDEP_VAR_R           = 3,
  PRO_MECH_INDEP_VAR_THETA       = 4,
  PRO_MECH_INDEP_VAR_PHI         = 5,
  PRO_MECH_INDEP_VAR_TIME        = 6,
  PRO_MECH_INDEP_VAR_TEMPERATURE = 7,
  PRO_MECH_INDEP_VAR_DEFLECTION  = 8,
  PRO_MECH_INDEP_VAR_ARCLENGTH   = 9,
  PRO_MECH_INDEP_VAR_FREQUENCY   = 10
}
ProMechIndepvarType;

#define PRO_MAX_FUNC_EXPR_LENGTH 1024

typedef wchar_t ProMechFuncExpression[PRO_MAX_FUNC_EXPR_LENGTH];

typedef enum
{
  PRO_MECH_TABLE_NONE        = PRO_VALUE_UNUSED,

  PRO_MECH_TABLE_LINEAR      = 0,
  PRO_MECH_TABLE_LOGARITHMIC = 1
}
ProMechfuncTableInterpType;

typedef struct pro_sim_func_data* ProMechFuncData;
typedef struct pro_sim_func_table_entry* ProMechfuncTableEntry;

PRO_BEGIN_C_DECLS

extern ProError  ProMechfuncCsysGet (ProMechItem* item,
                                     ProMechGeomref* csys);
/*
    Purpose: Obtains the reference csys (if this is the function of coordinates ).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The function.

    Output Arguments:
        csys    - The reference csys.  Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechfuncDescriptionGet (ProMechItem* item,
                                           ProComment description);
/*
    Purpose: Obtains the function description.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        description     - The description.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
*/

extern ProError  ProMechfuncVartypeGet (ProMechItem* item,
                                        ProMechfuncVarType* value);
/*
    Purpose: Obtains the value of the function Var Type from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value   - The function Var Type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.

*/

extern ProError  ProMechfuncDataGet (ProMechItem* item,
                                     ProMechFuncData* value);
/*
    Purpose: Obtains the value of the function data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value   - The function data.  Free this using ProMechfuncdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError  ProMechfuncdataTypeGet (ProMechFuncData data,
                                         ProMechfuncType* value);
/*
    Purpose: Obtains the function type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - The type of function.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechfuncdataExpressionGet (ProMechFuncData data,
                                               ProMechFuncExpression value);
/*
    Purpose: Obtains the symbolic expression for the function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - The symbolic expression.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The Function data does not contain this type of function.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeGet()
*/

extern ProError  ProMechfuncdataIndependentvarGet (ProMechFuncData data,
                                                   ProMechIndepvarType* value);
/*
    Purpose: Obtains the type of independent variable for a tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - The independent variable type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The Function data does not contain this type of function.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeGet()
*/

extern ProError  ProMechfuncdataIndepvarinterpGet (ProMechFuncData data,
                                             ProMechfuncTableInterpType* value);
/*
    Purpose: Obtains the type of interpolation for the function value.  Valid only for a tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - The interpolation type for the function value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The Function data does not contain this type of function.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeGet()
*/

extern ProError  ProMechfuncdataFuncvalueinterpGet (ProMechFuncData data,
                                             ProMechfuncTableInterpType* value);
/*
    Purpose: Obtains the type of interpolation for the independent variable.  Valid only for a tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - The interpolation type for the independent variable.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The Function data does not contain this type of function.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeGet()
*/

extern ProError  ProMechfuncdataFunctableGet (ProMechFuncData data,
                                              ProMechfuncTableEntry** value);
/*
    Purpose: Obtains the table entries for the tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - ProArray of table entries.  Free this
                using ProMechtablentryProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The Function data does not contain this type of function.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.

    See Also:
                ProMechfuncdataTypeGet()
*/

extern ProError  ProMechfuncdataFree (ProMechFuncData data);
/*
    Purpose: Frees the memory for a Creo Simulate function data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtablentryFunctionvalueGet (ProMechfuncTableEntry entry,
                                                   double* value);
/*
    Purpose: Obtains the function value in this table entry.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entry   - The function table entry.

    Output Arguments:
        value   - The value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtablentryFree (ProMechfuncTableEntry entry);
/*
    Purpose: Frees the memory for a Creo Simulate tabular function entry.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entry   - The function table entry.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtablentryProarrayFree (ProMechfuncTableEntry* array);
/*
    Purpose: Frees the memory for a Creo Simulate tabular function entry array.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        array   - The function table entry array.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtablentryIndependentvarGet (ProMechfuncTableEntry entry,
                                                    double* value);
/*
    Purpose: Obtains the independent variable value for this table entry.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entry   - The function table entry.

    Output Arguments:
        value   - The value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechfuncdataMirrordeflectionflagGet (ProMechFuncData   data,
                                                        ProBool         * value);
/*
    Purpose: Obtains the mirror flag value.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.

    Output Arguments:
        value   - Mirror flag.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechfuncCsysSet (ProMechItem* item, ProMechGeomref csys);
/*
    Purpose: Sets the reference csys (if this is the function of coordinates).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The function.
        csys - The reference csys.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechfuncDescriptionSet (ProMechItem* item,
                                           ProComment description);
/*
    Purpose: Sets the function description.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        description - The description.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechfuncDataSet (ProMechItem* item, ProMechFuncData data);
/*
    Purpose: Sets the value of the function data from the function item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        data - The function data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechfuncVartypeSet (ProMechItem* item, ProMechfuncVarType value);
/*
    Purpose: Sets the value of the function Var Type to the function item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The function Var Type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechfuncdataTypeSet (ProMechFuncData data,
                                        ProMechfuncType type);
/*
    Purpose: Sets the function type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The function data.
        type - The type of function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechfuncdataExpressionSet (ProMechFuncData data,
                                              ProMechFuncExpression value);
/*
    Purpose: Sets the symbolic expression for the function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The function data.
        value - The symbolic expression.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The function is not of symbolic type.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeSet()
*/

extern ProError ProMechfuncdataIndependentvarSet (ProMechFuncData data,
                                                  ProMechIndepvarType value);
/*
    Purpose: Sets the type of independent variable for a tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The function data.
        value - The independent variable type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The function is not of tabular type.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeSet()
*/

extern ProError ProMechfuncdataIndepvarinterpSet (ProMechFuncData data,
                                               ProMechfuncTableInterpType type);
/*
    Purpose: Sets the type of interpolation for the function value.  Valid only
             for a tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The function data.
        type - The interpolation type for the function value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The function is not of tabular type.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeSet()
*/

extern ProError ProMechfuncdataFuncvalueinterpSet (ProMechFuncData data,
                                               ProMechfuncTableInterpType type);
/*
    Purpose: Sets the type of interpolation for the independent variable.
             Valid only for a tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The function data.
        type - The interpolation type for the independent variable.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This function is not of tabular type.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechfuncdataTypeSet()
*/

extern ProError ProMechfuncdataFunctableSet (ProMechFuncData data,
                                             ProMechfuncTableEntry* value);
/*
    Purpose: Sets the table entries for the tabular function.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The function data.
        value - ProArray of table entries.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The function is not of tabular type.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechfuncdataAlloc (ProMechFuncData* data);
/*
    Purpose: Allocates the memory for a function data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         none.

    Output Arguments:
        data - The function data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechtablentryIndependentvarSet (ProMechfuncTableEntry entry,
double value);
/*
    Purpose: Sets the independent variable value for this table entry.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entry - The function table entry.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechtablentryFunctionvalueSet (ProMechfuncTableEntry entry,
                                                  double value);
/*
    Purpose: Sets the function value in this table entry.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entry - The function table entry.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechtablentryAlloc (ProMechfuncTableEntry* entry);
/*
    Purpose: Allocates the memory for a Creo Simulate tabular function entry.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         none

    Output Arguments:
         entry - The function table entry.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechfuncdataMirrordeflectionflagSet (ProMechFuncData data,
                                                        ProBool         value);
/*
    Purpose: Sets the mirror flag value.
             <B>Note</B>: Used only for PRO_MECH_FUNC_DEFLECTION type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The function data.
        value   - Mirror flag.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

PRO_END_C_DECLS

#endif /* PROMECHFUNCTION_H */
