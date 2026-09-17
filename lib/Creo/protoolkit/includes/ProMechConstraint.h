#ifndef PROMECHCONSTRAINT_H
#define PROMECHCONSTRAINT_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechGeomref.h>
#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef struct pro_displacement* ProMechDisplacementData;
typedef struct pro_mech_displacement_regular_constr*
                                             ProMechDisplacementRegularConstr;
typedef ProMechDisplacementRegularConstr ProMechDisplacementConstr;
/*<B>Note:</B> The handle ProMechDisplacementConstr is deprecated.
   Use the handle, ProMechDisplacementRegularConstr, instead */

typedef struct pro_mech_displacement_pin_constr* ProMechDisplacementPinConstr;

typedef struct pro_symmetry* ProMechSymmetryData;
typedef struct pro_temperature* ProMechTemperatureData;
typedef struct pro_convection* ProMechConvectionData;
typedef struct pro_radiation* ProMechRadiationData;

typedef enum
{
                                          /* Structure Constraints */
    PRO_MECH_CONSTR_DISPLACEMENT           = 0,
    PRO_MECH_CONSTR_SYMMETRY               = 1,
                                          /* Thermal Constraints */
    PRO_MECH_CONSTR_TEMPERATURE            = 30,
    PRO_MECH_CONSTR_CONVECTION             = 31,
    PRO_MECH_CONSTR_RADIATION              = 32,
    PRO_MECH_CONSTR_SYMMETRY_THERM         = 33
} ProMechConstrType;

typedef enum
{
    PRO_MECH_DISPLACEMENT_NONE            = PRO_VALUE_UNUSED,

    PRO_MECH_DISPLACEMENT_REGULAR         = 0,
    PRO_MECH_DISPLACEMENT_PLANE           = 1,
    PRO_MECH_DISPLACEMENT_CYL_ANGULAR     = 2, /* Deprecated, R = 0, Theta = 0*/
    PRO_MECH_DISPLACEMENT_CYL_AXIAL       = 3, /* Deprecated, R = 0, Z = 0 */
    PRO_MECH_DISPLACEMENT_CYL_RADIAL_ONLY = 4, /* Deprecated, R = 0 */
    PRO_MECH_DISPLACEMENT_PIN             = 5,
    PRO_MECH_DISPLACEMENT_BALL            = 6
} ProMechDisplacementType;


typedef enum
{
    PRO_MECH_DISPLACEMENT_CONSTR_NONE = PRO_VALUE_UNUSED,

    PRO_MECH_DISPLACEMENT_FREE        = 0,
    PRO_MECH_DISPLACEMENT_FIXED       = 1,
    PRO_MECH_DISPLACEMENT_ENFORCED    = 2
} ProMechDisplacementConstrType;


typedef enum
{
PRO_MECH_SYMMETRY_NONE = PRO_VALUE_UNUSED,
PRO_MECH_SYMMETRY_CYCLIC = 0,
PRO_MECH_SYMMETRY_MIRROR = 1

} ProMechSymmetryType;

extern ProError  ProMechconstrReferencesGet (ProMechItem* constr,
                ProMechGeomref** geomrefs);
/*
    Purpose: Obtains the constraint geomrefs.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        constr    - The constraint.

    Output Arguments:
        geomrefs - ProArray of constraint geomrefs.  The function 
                  allocates memory for this argument. Use 
                          ProMechgeomrefProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/

extern ProError  ProMechconstrTypeGet (ProMechItem* constr,
                ProMechConstrType* value);
/*
    Purpose: Obtains the type of constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        constr    - The constraint.

    Output Arguments:
        value    - The type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechconstrDisplacementdataGet (ProMechItem* item,
                ProMechDisplacementData* value);
/*
    Purpose: Obtains the handle to the displacement data from the 
            Creo Simulate constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The constraint.

    Output Arguments:
        value    - The displacement data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of constraint.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechconstrTypeGet()
*/

extern ProError  ProMechdisplacementdataTypeGet (ProMechDisplacementData data,
                ProMechDisplacementType* value);
/*
    Purpose: Obtains the type of the displacement constraint data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The displacement type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdisplacementdataTranslationconstrsGet (ProMechDisplacementData data,
                ProMechDisplacementRegularConstr** value);
/*
    Purpose: Obtains the translation component of the displacement (3 values assigned
                to the three potential directions of translation).
             <B>Note</B>: The type should be PRO_MECH_DISPLACEMENT_REGULAR.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - ProArray of the translation options of the constraint.  The function 
                  allocates memory for this argument. Use 
                  ProMechdisplacementregularconstrProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError ProMechdisplacementdataTranslationinterpretinradiansflagGet (
                                              ProMechDisplacementData   data,
                                              ProBoolean              * value);
/*
    Purpose: Obtains the flag for interpreting the angular translations in radians.
             <B>Note</B>: Applicable only for PRO_MECH_DISPLACEMENT_REGULAR type 
                             with a non-Cartesian coordinate system selected.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - PRO_B_TRUE  :Angular translations are interpreted in radians.
                 - PRO_B_FALSE :Angular translations are not interpreted in radians.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdisplacementdataRotationconstrsGet (
                ProMechDisplacementData data,
                ProMechDisplacementRegularConstr** value);
/*
    Purpose: Obtains the rotation component of the displacement (3 values assigned
                to the three potential axes of rotation).
             <B>Note</B>: The type should be PRO_MECH_DISPLACEMENT_REGULAR.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - ProArray of the rotation options of the constraint. The function 
                  allocates memory for this argument. Use 
                 ProMechdisplacementregularconstrProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechdisplacementdataPinconstrGet (ProMechDisplacementData 
                data, ProMechDisplacementPinConstr* value);
/*
    Purpose: Obtains the pin constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - pin constraint. The function 
                  allocates memory for this argument. Use 
                  ProMechdisplacementpinconstrFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate the handle.

    See Also:
        ProMechdisplacementdataPinaxialconstrTypeGet()
        ProMechdisplacementdataPinangularconstrTypeGet()
*/

extern ProError ProMechdisplacementdataPinaxialconstrTypeGet (ProMechDisplacementPinConstr data, ProMechDisplacementConstrType* type);
/*
    Purpose: Gets the axial constraint for pin constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        type - The constraint type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementdataPinangularconstrTypeGet().
*/

extern ProError ProMechdisplacementdataPinangularconstrTypeGet (ProMechDisplacementPinConstr data, ProMechDisplacementConstrType* type);
/*
    Purpose: Gets the angular constraint for pin constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        type - The constraint type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementdataPinaxialconstrTypeGet().
*/

extern ProError  ProMechdisplacementdataCsysGet (ProMechDisplacementData data,
                ProMechGeomref* value);
/*
    Purpose: Obtains the coordinate system used for the displacement.
             <B>Note</B>: The type should be PRO_MECH_DISPLACEMENT_REGULAR.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The coordinate system.  Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechdisplacementdataFree (ProMechDisplacementData data);
/*
    Purpose: Frees the memory for a Creo Simulate displacement constraint data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdisplacementconstrTypeGet (ProMechDisplacementConstr data,
                ProMechDisplacementConstrType* type);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechdisplacementregularconstrTypeGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechdisplacementregularconstrTypeGet() instead.
             <p>
             Obtains the type of the constraint (free, fixed, or enforced).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The constraint.

    Output Arguments:
        type    - The constraint type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementregularconstrTypeGet()
*/

extern ProError  ProMechdisplacementregularconstrTypeGet (ProMechDisplacementConstr 
                data, ProMechDisplacementConstrType* type);
/*
     Purpose: Obtains the type of the constraint (free, fixed, or enforced).

     Licensing Requirement:
          TOOLKIT for Mechanica

     Input Arguments:
          data - The constraint.

     Output Arguments:
          type - The constraint type.

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
          PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdisplacementconstrValueGet (ProMechDisplacementConstr data,
                ProMechValue* value);
/*
      DEPRECATED: Since Wildfire 5.0
      SUCCESSORS: ProMechdisplacementregularconstrValueGet
      Purpose: <B>Note</B>: This function is deprecated.
              Use ProMechdisplacementregularconstrValueGet() instead.
              <p>
              Obtains the variation settings of the displacement,
              if the type is "Enforced".

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The variation.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechdisplacementregularconstrTypeGet()
        ProMechdisplacementregularconstrValueGet()
*/

extern ProError  ProMechdisplacementregularconstrValueGet (ProMechDisplacementRegularConstr data,
                ProMechValue* value);
/*
    Purpose: Obtains the variation settings of the displacement, if the type is 
                "Enforced".

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The variation.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechdisplacementregularconstrTypeGet()
*/

extern ProError  ProMechdisplacementconstrFree (ProMechDisplacementConstr data);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechdisplacementregularconstrFree
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechdisplacementregularconstrFree() instead.
             <p>
             Frees the memory for a Creo Simulate displacement constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The constraint.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementregularconstrFree()
*/

extern ProError  ProMechdisplacementregularconstrFree (ProMechDisplacementRegularConstr data);
/*
     Purpose: Frees the memory for a Creo Simulate regular displacement constraint.

     Licensing Requirement:
          TOOLKIT for Mechanica

     Input Arguments:
          data - The constraint.

     Output Arguments:
          none 

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
          PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdisplacementpinconstrFree (ProMechDisplacementPinConstr data);
/*
     Purpose: Frees the memory for a Creo Simulate pin constraint.

     Licensing Requirement:
          TOOLKIT for Mechanica

     Input Arguments:
          data - The constraint.

     Output Arguments:
          none 

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
          PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechdisplacementconstrProarrayFree (ProMechDisplacementConstr* data);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechdisplacementregularconstrProarrayFree
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechdisplacementregularconstrProarrayFree() instead.
             <p>
             Frees the memory for a Creo Simulate displacement constraint array.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The array.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementregularconstrProarrayFree()
*/

extern ProError  ProMechdisplacementregularconstrProarrayFree (ProMechDisplacementRegularConstr* data);
/*
     Purpose: Frees the memory for a Creo Simulate regular displacement constraint array.

     Licensing Requirement:
          TOOLKIT for Mechanica

     Input Arguments:
          data - The array.

     Output Arguments:
          none

     Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
          PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/
extern ProError  ProMechconstrSymmetrydataGet (ProMechItem* item,
                ProMechSymmetryData* value);
/*
    Purpose: Obtains the handle to the symmetry data from the Creo Simulate constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The constraint.

    Output Arguments:
        value    - The symmetry data.  Free this using ProMechsymmetrydataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of constraint.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechconstrTypeGet()
*/

extern ProError  ProMechsymmetrydataSide1Get (ProMechSymmetryData data,
                ProMechGeomref** geomrefs);
/*
    Purpose: Obtains an array of geomrefs  assigned to side 1 of the  symmetry 
                constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        geomrefs - ProArray of references. The function allocates memory for this argument.
                    Use ProMechgeomrefProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechsymmetrydataSide2Get (ProMechSymmetryData data,
                ProMechGeomref** geomrefs);
/*
    Purpose: Obtains an array of geomrefs assigned to side 2 of the  symmetry constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
            geomrefs - ProArray of references. The function allocates memory for this argument.
                    Use ProMechgeomrefProarrayFree() to free it.
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechsymmetrydataAxisGet (ProMechSymmetryData data,
                ProMechGeomref* axis);
/*
    Purpose: Obtains the axis of the symmetry constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        axis    - The axis.  Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechsymmetrydataFree (ProMechSymmetryData data);
/*
    Purpose: Frees the memory for a Creo Simulate symmetry constraint data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconstrThermalsymmetrydataGet (ProMechItem* item,
                ProMechSymmetryData* value);
/*
    Purpose: Obtains the handle to the thermal symmetry data from the Creo Simulate constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The constraint.

    Output Arguments:
        value    - The symmetry data.  Free this using ProMechsymmetrydataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of constraint.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechconstrTypeGet()
*/

extern ProError ProMechsymmetrydataTypeGet (ProMechSymmetryData data, ProMechSymmetryType* type);
/*
       Purpose: Gets the type of the symmetry constraint.
  
       Licensing Requirement:
          TOOLKIT for Mechanica
  
       Input Arguments:
           data - The data.
  
       Output Arguments:
           type - The symmetry type.
  
       Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
          PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconstrTemperaturedataGet (ProMechItem* item,
                ProMechTemperatureData* value);
/*
    Purpose: Obtains the handle to the temperature constratint data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The temperature constraint data.  Free this using 
                   ProMechtemperaturedataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of constraint.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechconstrTypeGet()
*/

extern ProError  ProMechtemperaturedataValueGet (ProMechTemperatureData data,
                ProMechValue* value);
/*
    Purpose: Obtains the value of the temperature constraint data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechtemperaturedataFree (ProMechTemperatureData data);
/*
    Purpose: Frees the memory for a Creo Simulate temperature constraint data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconstrConvectiondataGet (ProMechItem* item,
                ProMechConvectionData* value);
/*
    Purpose: Obtains the handle to the convection constratint data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The convection constraint data.  Free this using 
                    ProMechconvectiondataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

    See Also:
        ProMechconstrTypeGet()
*/

extern ProError  ProMechconvectiondataFilmcoefficientGet (ProMechConvectionData data,
                ProMechValue* value);
/*
    Purpose: Obtains the value of the film coefficient.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechconvectiondataBulktempGet (ProMechConvectionData data,
                ProMechValue* value);
/*
    Purpose: Obtains the value of the bulk temperature.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechconvectiondataFemneutralfileGet (ProMechConvectionData data,
                ProPath value);
/*
    Purpose: <B>Note</B>: This function is deprecated.  Creo Simulate now permits
             separate external files to be used for the film coefficient and
             bulk temperature values. See

                 ProMechconvectiondataBulktempGet()
                 ProMechconvectiondataFilmcoefficientGet()
                 ProMechvariationTypeGet()
                 ProMechvariationExternalfielddataGet()
                 ProMechexternalfielddataFileGet()

             <p>
             In the case where both the bulk temperature and film coefficient
             are governed by the same external file, this function will return
             that value.  Otherwise, this function will return an error, and
             you should look at the ProMechVariation property of the
             ProMechValue extracted for both the bulk temperature and film
             coefficient.  If either of these is set to
             PRO_MECH_VARIATION_EXTERNAL_FIELD, then that property is governed by
             an external file.
             <p>
             Obtains the path to the FEM neutral file for this convection data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The path.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_E_NOT_FOUND - Neither the bulk temperature nor the film 
                             coefficient are governed by an external file.
        PRO_TK_E_AMBIGUOUS - The properties of the bulk temperature and film
                             coefficient are not equivalent; this function
                             cannot return the data requested.  See Purpose for
                             a detailed explanation.

*/

extern ProError  ProMechconvectiondataCsysGet (ProMechConvectionData data,
                ProMechGeomref* csys);
/*
    Purpose: <B>Note</B>: This function is deprecated.  Creo Simulate now permits
             separate csys references to be used for the film coefficient and
             bulk temperature values governed by external files. See

                 ProMechconvectiondataBulktempGet()
                 ProMechconvectiondataFilmcoefficientGet()
                 ProMechvariationTypeGet()
                 ProMechvariationExternalfielddataGet()
                 ProMechexternalfielddataCsysGet()

             <p>
             In the case where both the bulk temperature and film coefficient
             are governed by the same csys reference, this function will return
             that value.  Otherwise, this function will return an error, and
             you should look at the ProMechVariation property of the
             ProMechValue extracted for both the bulk temperature and film
             coefficient.  If either of these is set to
             PRO_MECH_VARIATION_EXTERNAL_FIELD, then that property is governed by
             an external file referencing the given csys.
             <p>
             Obtains the coordinate system used to determine the convection data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        csys    - The coordinate system.  Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_E_NOT_FOUND - Neither the bulk temperature nor the film
                             coefficient are governed by an external file.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

*/

extern ProError  ProMechconvectiondataTimefunctionidGet (ProMechConvectionData data,
                int* function_id);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechconvectiondataTemporalvariationGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechconvectiondataTemporalvariationGet() instead.
             <p>
             Obtains the time function that governs the convection constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        function_id    - The time function id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconvectiondataFree (ProMechConvectionData data);
/*
    Purpose: Frees the memory for a Creo Simulate temperature constraint data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechconstrConstrsetsGet (ProMechItem* item,
                                            int** pp_constr_ids);
/*
  Purpose: Obtains the ConstraintSet id's for the given constraint.

  Licensing Requirement:
          TOOLKIT for Mechanica

  Input Arguments:
    item    - The constraint.

  Output Arguments:
    pp_constr_ids - ProArray of Constraintset id's corresponding to the 
                    constraint. The function allocates memory for this argument.
                    Use ProArrayFree() to free it.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
      PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.
      PRO_TK_E_NOT_FOUND - The constraint is not associated with any constraintset
      PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
      PRO_TK_GENERAL_ERROR - A general error was encountered.
*/


extern ProError ProMechconstrReferencesSet (ProMechItem* constr, ProMechGeomref* geomrefs);
/*
    Purpose: Sets the constraint geomrefs.

    Licensing Requirement:
          TOOLKIT for Mechanica


    Input Arguments:
        constr - The constraint.
        geomrefs - ProArray of constraint geomrefs.  
                   Multiple point references are not allowed for creating 
                   convection constraints.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.

*/

extern ProError ProMechconstrDisplacementdataSet (ProMechItem* item, ProMechDisplacementData value);
/*
    Purpose: Sets the handle to the displacement data from the Creo Simulate 
             constraint.


    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The constraint.
        value - The displacement data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_INVALID_PTR - The ProMechItem's owner solid is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Unable to Modify.
*/

extern ProError ProMechdisplacementdataTypeSet (ProMechDisplacementData data, ProMechDisplacementType value);
/*
Purpose: <B>Note</B>: The deprecated enums PRO_MECH_DISPLACEMENT_CYL_ANGULAR,
         PRO_MECH_DISPLACEMENT_CYL_AXIAL and PRO_MECH_DISPLACEMENT_CYL_RADIAL_ONLY will be set
         as PRO_MECH_DISPLACEMENT_PIN.
         <p>
         Sets the type of the displacement constraint data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The displacement type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechdisplacementdataTranslationconstrsSet (ProMechDisplacementData data, ProMechDisplacementRegularConstr* value);
/*
    Purpose: Sets the translation component of the displacement (3 values 
             assignedto the three potential directions of translation).
             <B>Note</B>:Applicable for PRO_MECH_DISPLACEMENT_REGULAR type only.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - ProArray of the translation options of the constraint.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.

*/

extern ProError ProMechdisplacementdataTranslationinterpretinradiansflagSet (
                                                ProMechDisplacementData data,
                                                ProBoolean              value);
/*
    Purpose: Sets whether angular translations are interpreted in radians.
             <B>Note</B>:Applicable only for PRO_MECH_DISPLACEMENT_REGULAR type 
                              with a non-Cartesian coordinate system selected.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - PRO_B_TRUE  : Interpret angular translations in radians.
                PRO_B_FALSE : Do not interpret angular translations in radians.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechdisplacementdataRotationconstrsSet (ProMechDisplacementData data, ProMechDisplacementRegularConstr * value);
/*
    Purpose: Sets the rotation component of the displacement (3 values 
             assignedto the three potential axes of rotation).
             <B>Note</B>:Applicable for PRO_MECH_DISPLACEMENT_REGULAR type only.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - ProArray of the rotation options of the constraint.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.

*/

extern ProError ProMechdisplacementdataPinconstrSet (ProMechDisplacementData data, ProMechDisplacementPinConstr value);
/*
    Purpose: Sets the pin constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The pin constraint data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementdataPinaxialconstrTypeSet().
        ProMechdisplacementdataPinangularconstrTypeSet().
*/

extern ProError ProMechdisplacementdataPinangularconstrTypeSet (ProMechDisplacementPinConstr data, ProMechDisplacementConstrType type);
/*
    Purpose: Sets the angular constraint for pin constraint.
             <B>Note</B>: The type can not be PRO_MECH_DISPLACEMENT_ENFORCED.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        type - The constraint type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementdataPinaxialconstrTypeSet().
*/

extern ProError ProMechdisplacementdataPinaxialconstrTypeSet (ProMechDisplacementPinConstr data, ProMechDisplacementConstrType type);
/*
    Purpose: Sets the axial constraint for pin constraint.
             <B>Note</B>: The type can not be PRO_MECH_DISPLACEMENT_ENFORCED.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        type - The constraint type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementdataPinangularconstrTypeSet().
*/

extern ProError ProMechdisplacementdataCsysSet (ProMechDisplacementData data, ProMechGeomref value);
/*
    Purpose: Sets the coordinate system used for the displacement.
             <B>Note</B>:Applicable for PRO_MECH_DISPLACEMENT_REGULAR type only.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechdisplacementdataAlloc (ProMechDisplacementData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate displacement constraint 
             data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The data.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechdisplacementconstrTypeSet (ProMechDisplacementConstr data, ProMechDisplacementConstrType type);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechdisplacementregularconstrTypeSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechdisplacementregularconstrTypeSet() instead.
             <p>
             Sets the type of the constraint (free, fixed, or enforced).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The constraint.
        type - The constraint type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechdisplacementregularconstrTypeSet()
*/

extern ProError ProMechdisplacementregularconstrTypeSet (ProMechDisplacementRegularConstr data, ProMechDisplacementConstrType type);
/*
    Purpose: Sets the type of the constraint (free, fixed, or enforced).

    Licensing Requirement:     
          TOOLKIT for Mechanica

    Input Arguments:  
        data - The regular constraint.
        type - The constraint type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechdisplacementconstrValueSet (ProMechDisplacementConstr data, ProMechValue value);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechdisplacementregularconstrValueSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechdisplacementregularconstrValueSet() instead.
             <p>
             Sets the variation settings of the displacement, if the type is    
                      "Enforced".

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The variation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The displacement does not contain this type of value.

    See Also:
        ProMechdisplacementregularconstrTypeSet()
        
*/

extern ProError ProMechdisplacementregularconstrValueSet (ProMechDisplacementRegularConstr data, ProMechValue value);
/*
    Purpose: Sets the variation settings of the displacement, if the type is
                      "Enforced".

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The variation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The displacement does not contain this type of value.

    See Also:
        ProMechdisplacementregularconstrTypeSet()
*/

extern ProError ProMechdisplacementconstrAlloc (ProMechDisplacementConstr* data);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechdisplacementregularconstrAlloc
    Purpose: <B>Note</B>: This function is deprecated.  Use ProMechdisplacementregularconstrAlloc() instead.
             <p>
             Allocates the memory for a Creo Simulate displacement constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The constraint.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechdisplacementregularconstrAlloc()

*/

extern ProError ProMechdisplacementregularconstrAlloc (ProMechDisplacementRegularConstr* data);
/*
    Purpose: Allocates the memory for a Creo Simulate regular displacement constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The constraint.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechdisplacementpinconstrAlloc (ProMechDisplacementPinConstr* data);
/*
    Purpose: Allocates the memory for a Creo Simulate pin constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The constraint.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechconstrSymmetrydataSet (ProMechItem* item, ProMechSymmetryData value);
/*
    Purpose: Sets the handle to the symmetry data from the Creo Simulate 
             constraint.
    <B>Note:</B> If you are creating a new symmetry data constraint,
    you should assign the model as a reference using the function
    ProMechconstrReferencesSet(). For mirror symmetry set geometry reference(s) 
    for side1 using ProMechsymmetrydataSide1Set().

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The constraint.
        value - The symmetry data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechsymmetrydataSide1Set (ProMechSymmetryData data, ProMechGeomref* geomrefs);
/*
    Purpose: Sets an array of geomrefs  assigned to side 1 of the  symmetry 
             constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        geomrefs - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error was encountered.

*/

extern ProError ProMechsymmetrydataSide2Set (ProMechSymmetryData data, ProMechGeomref* geomrefs);
/*
    Purpose: Sets an array of geomrefs assigned to side 2 of the  symmetry 
             constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        geomrefs - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error was encountered.

*/

extern ProError ProMechsymmetrydataAxisSet (ProMechSymmetryData data, ProMechGeomref axis);
/*
    Purpose: Sets the axis of the symmetry constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        axis - The axis.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsymmetrydataTypeSet (ProMechSymmetryData data, ProMechSymmetryType type);
/*
    Purpose: Sets the type of the symmetry constraint.
  
    Licensing Requirement:
          TOOLKIT for Mechanica
  
    Input Arguments:
        data - The data.
        type - The symmetry type.
  
    Output Arguments:
        none
  
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
  */
extern ProError ProMechsymmetrydataAlloc (ProMechSymmetryData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate symmetry constraint data 
             handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechconstrThermalsymmetrydataSet (ProMechItem* item, ProMechSymmetryData value);
/*
    Purpose: Sets the handle to the thermal symmetry data from the Creo Simulate 
             constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The constraint.
        value - The symmetry data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechconstrTemperaturedataSet (ProMechItem* item, ProMechTemperatureData value);
/*
    Purpose: Sets the handle to the temperature constratint data from the 
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The temperature constraint data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechtemperaturedataValueSet (ProMechTemperatureData data, ProMechValue value);
/*
    Purpose: Sets the value of the temperature constraint data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechtemperaturedataAlloc (ProMechTemperatureData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate temperature constraint 
             data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechconstrConvectiondataSet (ProMechItem* item, ProMechConvectionData value);
/*
    Purpose: Sets the handle to the convection constratint data from the 
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The convection constraint data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechconvectiondataFilmcoefficientSet (ProMechConvectionData data, ProMechValue value);
/*
    Purpose: Sets the value of the film coefficient.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechconvectiondataFilmcoefficientUnset (ProMechConvectionData data);
/*
    Purpose: <B>Note: </B> This function is deprecated.  You can change the
             dependency of either the bulk temperature or film coefficient on
             an external file by changing the type of variation used for that
             property. See

                 ProMechconvectiondataBulktempSet()
                 ProMechconvectiondataFilmcoefficientSet()
                 ProMechvariationUniformSet()
                 ProMechvariationFunctionidSet()
                 ProMechvariationInterpolationSet()

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_OBSOLETE_FUNC - This function is deprecated.
*/

extern ProError ProMechconvectiondataBulktempSet (ProMechConvectionData data, ProMechValue value);
/*
    Purpose: Sets the value of the bulk temperature.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechconvectiondataBulktempUnset (ProMechConvectionData data);
/*
    Purpose: <B>Note: </B> This function is deprecated.  You can change the
             dependency of either the bulk temperature or film coefficient on
             an external file by changing the type of variation used for that
             property. See

                 ProMechconvectiondataBulktempSet()
                 ProMechconvectiondataFilmcoefficientSet()
                 ProMechvariationUniformSet()
                 ProMechvariationFunctionidSet()
                 ProMechvariationInterpolationSet()

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_OBSOLETE_FUNC - This function is deprecated.

*/


extern ProError ProMechconvectiondataFemneutralfileSet (ProMechConvectionData data, ProPath value);
/*
    Purpose: <B>Note: </B> This function is deprecated.  You can independently
             set the dependency of the bulk temperature or film coefficient to
             an external file by setting its ProMechVariation type to
             PRO_MECH_VARIATION_EXTERNAL_FIELD. See

                 ProMechconvectiondataBulktempSet()
                 ProMechconvectiondataFilmcoefficientSet()
                 ProMechvariationExternalfielddataSet()
                 ProMechexternalfielddataFileSet()

             <p>
             This function sets the path to the FEM neutral file for both the
             bulk temperature and film coefficient in this convection data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The path.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


extern ProError ProMechconvectiondataCsysSet (ProMechConvectionData data, ProMechGeomref csys);
/*
    Purpose: <B>Note: </B> This function is deprecated.  You can independently
             set the dependency of the bulk temperature or film coefficient to
             a different csys reference for an external file by setting its
             ProMechVariation type to PRO_MECH_VARIATION_EXTERNAL_FIELD. See

                 ProMechconvectiondataBulktempSet()
                 ProMechconvectiondataFilmcoefficientSet()
                 ProMechvariationExternalfielddataSet()
                 ProMechexternalfielddataCsysSet()

             <p>
             This function sets the coordinate system for both the
             bulk temperature and film coefficient in this convection data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        csys - The coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechconvectiondataTimefunctionidSet (ProMechConvectionData data, int function_id);
/*
    DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechconvectiondataTemporalvariationSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechconvectiondataTemporalvariationSet() instead.
             <p>
             Sets the time function that governs the convection constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        function_id - The time function id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechconvectiondataAlloc (ProMechConvectionData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate temperature constraint 
             data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechconstrConstrsetAssign (ProMechItem* item,
                                              int          constrsetid,
                                              ProBool      unassign);
/*
    Purpose: Associates constraint with given constraint set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         item        - The constraint to be added.
         constrsetid - Constraintset id to which the constraint is to be added.
         unassign    - PRO_B_TRUE :  Removes the constraint from previous 
                                     set(if any).
                       PRO_B_FALSE : Does not remove the constraint from 
                                     previous set.
                                     Currently PRO_B_FALSE is not supported.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
*/

extern ProError ProMechconvectiondataTemperaturedependenceSet (ProMechConvectionData data,
                ProMechVariation mechVar);
/*
    Purpose: Sets the temperature variation that governs the convection constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        mechVar - The temperature variation. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconvectiondataTemperaturedependenceGet (ProMechConvectionData data,
                 ProMechVariation *p_mechVar);
/*
    Purpose: Obtains the temperature variation that governs the convection constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        p_mechVar - The temperature variation. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechconvectiondataTemporalvariationSet (ProMechConvectionData data,
                ProMechVariation mechVar);
/*
    Purpose: Sets the temporal variation that governs the convection constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        mechVar - The temporal variation. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconvectiondataTemporalvariationGet (ProMechConvectionData data,
                 ProMechVariation *p_mechVar);
/*
    Purpose: Obtains the temporal variation that governs the convection constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        p_mechVar - The temporal variation. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechradiationdataAlloc (ProMechRadiationData * data);
/*
    Purpose: Allocates the memory for a Creo Simulate radiation constraint data
             handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechconstrRadiationdataSet (ProMechItem          * item,
                                               ProMechRadiationData   value);
/*
    Purpose: Sets the handle to the radiation constraint data from the
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The radiation constraint data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechconstrRadiationdataGet (ProMechItem* item,
                                ProMechRadiationData* value);
/*
    Purpose: Obtains the handle to the radiation constraint data from the
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value   - The radiation constraint data.  Free this
                  using ProMechradiationdataFree().

        Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
        ProMechconstrTypeGet()
*/

extern ProError ProMechradiationdataEmissivitySet (ProMechRadiationData data,
                ProMechValue value);
/*
    Purpose: Sets the value of the emissivity.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError  ProMechradiationdataEmissivityGet (ProMechRadiationData data,
                 ProMechValue* value);
/*
    Purpose: Obtains the value of the emissivity.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechradiationdataAmbienttempExprSet (ProMechRadiationData data,
                ProMechExpression value);
/*
    Purpose: Sets the value of the ambient temperature.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError  ProMechradiationdataAmbienttempExprGet (ProMechRadiationData data,
                 ProMechExpression value);
/*
    Purpose: Obtains the value of the ambient temperature.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechradiationdataTemperaturedependenceSet (ProMechRadiationData data,
               ProMechVariation mechVar);
/*
    Purpose: Sets the temperature variation that governs the radiation constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        mechVar - The temperature variation. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError  ProMechradiationdataTemperaturedependenceGet (ProMechRadiationData data,
                ProMechVariation *p_mechVar);
/*
    Purpose: Obtains the temperature variation that governs the radiation constraint.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        p_mechVar - The temperature variation. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechradiationdataFree (ProMechRadiationData data);
/*
    Purpose: Frees the memory for a Creo Simulate radiation constraint data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        none

        Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


PRO_END_C_DECLS

#endif /* PROMECHCONSTRAINT_H */
