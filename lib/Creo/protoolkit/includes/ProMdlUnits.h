#ifndef PROMDLUNITS_H
#define PROMDLUNITS_H

#include <ProObjects.h>



PRO_BEGIN_C_DECLS

/******************************************************************************/

/* System of units object */
typedef enum
{
  PRO_UNITSYSTEM_MLT = 1,
  PRO_UNITSYSTEM_FLT = 2
}
ProUnitsystemType;

typedef struct
{
  ProMdl  owner;
  ProName name;
}
ProUnitsystem;

/* Quantity types */
typedef enum
{
  /* BASIC QUANTITIES */
  PRO_UNITTYPE_LENGTH                      = 0,   /* L */
  PRO_UNITTYPE_MASS                        = 1,   /* M */
  PRO_UNITTYPE_FORCE                       = 2,   /* F */
  PRO_UNITTYPE_TIME                        = 3,   /* T */
  PRO_UNITTYPE_TEMPERATURE                 = 4,   /* D */
  PRO_UNITTYPE_ANGLE                       = 5,   /* R */

  /* OTHER QUANTITIES */

  PRO_UNITTYPE_AREA                        = 6,   /* L^2                 */
  PRO_UNITTYPE_VOLUME                      = 7,   /* L^3                 */
  PRO_UNITTYPE_VELOCITY                    = 8,   /* L/T                 */
  PRO_UNITTYPE_ACCELERATION                = 9,   /* L/T^2               */
  PRO_UNITTYPE_ROTATIONAL_VELOCITY         = 10,  /* R/T                 */
  PRO_UNITTYPE_ROTATIONAL_ACCELERATION     = 11,  /* R/T^2               */
  PRO_UNITTYPE_FREQUENCY                   = 12,  /* Q = 1/T             */
  PRO_UNITTYPE_DENSITY                     = 13,  /* M/L^3               */
  PRO_UNITTYPE_TORQUE_MOMENT               = 14,  /* FL                  */
  PRO_UNITTYPE_FORCE_ALONG_CURVE           = 15,  /* F/L                 */
  PRO_UNITTYPE_FORCE_PER_LENGTH            = PRO_UNITTYPE_FORCE_ALONG_CURVE,
  PRO_UNITTYPE_MOMENT_ALONG_CURVE          = 16,  /* F                   */
  PRO_UNITTYPE_MOMENT_PER_LENGTH           = PRO_UNITTYPE_MOMENT_ALONG_CURVE,
  PRO_UNITTYPE_FORCE_OVER_SURFACE          = 17,  /* F/L^2               */
  PRO_UNITTYPE_FORCE_PER_AREA              = PRO_UNITTYPE_FORCE_OVER_SURFACE,
  PRO_UNITTYPE_MOMENT_PER_VOLUME           = PRO_UNITTYPE_FORCE_PER_AREA,
  PRO_UNITTYPE_PRESSURE                    = 18,  /* F/L^2               */
  PRO_UNITTYPE_STRESS                      = 19,  /* F/L^2               */
  PRO_UNITTYPE_YOUNG_MODULUS               = 20,  /* F/L^2               */
  PRO_UNITTYPE_MOMENT_OVER_SURFACE         = 21,  /* F/L                 */
  PRO_UNITTYPE_MOMENT_PER_AREA             = PRO_UNITTYPE_MOMENT_OVER_SURFACE,
  PRO_UNITTYPE_TRANSLATIONAL_STIFFNESS     = 22,  /* F/L                 */
  PRO_UNITTYPE_ROTATIONAL_STIFFNESS        = 23,  /* FL/R                */
  PRO_UNITTYPE_THERMAL_EXPANSION_COEFF     = 24,  /* 1/D                 */
  PRO_UNITTYPE_MOMENT_OF_INERTIA_SECTION   = 25,  /* L^4                 */
  PRO_UNITTYPE_MASS_MOMENT_OF_INERTIA      = 26,  /* ML^2                */
  PRO_UNITTYPE_ENERGY                      = 27,  /* E = FL              */
  PRO_UNITTYPE_WORK                        = 28,  /* FL                  */
  PRO_UNITTYPE_HEAT                        = 29,  /* FL                  */
  PRO_UNITTYPE_POWER                       = 30,  /* P = E/T = FL/T      */
  PRO_UNITTYPE_HEAT_TRANSFER_RATE          = 31,  /* E/T = FL/T          */
  PRO_UNITTYPE_TEMPERATURE_GRADIENT        = 32,  /* D/L                 */
  PRO_UNITTYPE_HEAT_FLUX                   = 33,  /* P/L^2 = F/(TL)      */
  PRO_UNITTYPE_HEAT_FLUX_PER_LENGTH        = 34,  /* P/L = F/T           */
  PRO_UNITTYPE_THERMAL_CONDUCTIVITY        = 35,  /* P/(LD) = F/(TD)     */
  PRO_UNITTYPE_CONVECTION_COEFF            = 36,  /* P/(L^2D) = F/(TLD)  */
  PRO_UNITTYPE_CONVECTION_COEFF_PER_AREA   = PRO_UNITTYPE_CONVECTION_COEFF,
  PRO_UNITTYPE_SPECIFIC_HEAT               = 37,  /* E/(MD) = L^2/(T^2D) */
  PRO_UNITTYPE_THERM_RES_FORCE             = 38,  /* F/(LD)              */
  PRO_UNITTYPE_THERM_RES_MOMENT            = 39,  /* F/D                 */
  PRO_UNITTYPE_WARPING_COEFFICIENT         = 40,  /* L^6                 */
  PRO_UNITTYPE_MASS_PER_LENGTH             = 41,  /* M/L                 */
  PRO_UNITTYPE_MASS_INERTIA_PER_LENGTH     = 42,  /* ML                  */
  PRO_UNITTYPE_DAMPING_COEFFICIENT         = 43,  /* FT/L = M/T          */
  PRO_UNITTYPE_HEAT_RATE_PER_LENGTH        = 44,  /* P/L = F/T           */
  PRO_UNITTYPE_DIMENSIONLESS               = 45,  /* 1                   */
  PRO_UNITTYPE_MASS_PER_AREA               = 46,  /* M/L^2               */
  PRO_UNITTYPE_ROT_DAMPING_COEFF           = 47,  /* FLT/R = ML^2/(TR)   */
  PRO_UNITTYPE_VOLUME_HEAT_GEN             = 48,  /* P/L^3 = F/(TL^2)    */
  PRO_UNITTYPE_TRANS_STIFF_PER_AREA        = 49,  /* F/L^3               */
  PRO_UNITTYPE_FORCE_PER_VOLUME            = PRO_UNITTYPE_TRANS_STIFF_PER_AREA,
  PRO_UNITTYPE_CURVATURE                   = 50,  /* 1/L                 */
  PRO_UNITTYPE_CURVATURE_SQ                = 51,  /* 1/L^2               */
  PRO_UNITTYPE_LINEAR_MOMENTUM             = 52,  /* ML/T                */
  PRO_UNITTYPE_ANGULAR_MOMENTUM            = 53,  /* ML^2/T              */
  PRO_UNITTYPE_INV_STRESS                  = 54,  /* L^2/F               */
  PRO_UNITTYPE_TRANS_STIFF_PER_LENGTH      = 55,  /* F/L^2               */
  PRO_UNITTYPE_ROT_STIFF_PER_LENGTH        = 56,  /* F/R                 */
  PRO_UNITTYPE_DAMPING_COEFF_PER_LENGTH    = 57,  /* FT/L^2              */
  PRO_UNITTYPE_INV_VELOCITY                = 58,  /* T/L                 */
  PRO_UNITTYPE_CONVECTION_COEFF_PER_VOLUME = 59,  /* P/(L^3D) = F/(TL^2D) */
  PRO_UNITTYPE_CONVECTION_COEFF_PER_LENGTH = 60,  /* P/(LD) = F/(TD)     */
  PRO_UNITTYPE_CONVECTION_COEFF_PER_POINT  = 61,  /* P/D = FL/(TD)       */
  PRO_UNITTYPE_RADIATION_COEFF_PER_VOLUME  = 62,  /* P/(L^3D^4) = F/(TL^2D^4) */
  PRO_UNITTYPE_RADIATION_COEFF_PER_AREA    = 63,  /* P/(L^2D^4) = F/(TLD^4)   */
  PRO_UNITTYPE_RADIATION_COEFF_PER_LENGTH  = 64,  /* P/(LD^4) = F/(TD^4)      */
  PRO_UNITTYPE_RADIATION_COEFF_PER_POINT   = 65,  /* P/D^4 = FL/(TD^4)        */
  PRO_UNITTYPE_ENERGY_PER_VOLUME           = 66,  /* E/(L^3)             */
  PRO_UNITTYPE_ENERGY_PER_AREA             = 67,  /* E/(L^2)             */
  PRO_UNITTYPE_ENERGY_PER_LENGTH           = 68,  /* E/L                 */
  PRO_UNITTYPE_LENGTH_SPECTDENS            = 69,  /* L^2/(Q) = L^2T     */
  PRO_UNITTYPE_VELOCITY_SPECTDENS          = 70,  /* L^2/(T^2Q) = L^2/T */
  PRO_UNITTYPE_ACCELERATION_SPECTDENS      = 71,  /* L^2/(T^4Q) = L^2/T^3 */
  PRO_UNITTYPE_STRESS_SPECTDENS            = 72,  /* F^2/(L^4Q) = F^2T/L^4 */
  PRO_UNITTYPE_STRAIN_SPECTDENS            = 73,  /* 1/(Q) = T          */
  PRO_UNITTYPE_ROTATIONAL_VELOCITY_SPECTDENS = 74,/* R^2/(T^2Q) = R^2/T */
  PRO_UNITTYPE_ROTATIONAL_ACCELERATION_SPECTDENS = 75, /* R^2/(T^4Q) = R^2/T^3 */
  PRO_UNITTYPE_FORCE_SPECTDENS             = 76,  /* F^2/(Q) = F^2T     */
  PRO_UNITTYPE_MOMENT_SPECTDENS            = 77,   /* F^2L^2/(Q) = F^2L^2T^1 */
  PRO_UNITTYPE_ROTATIONAL_LENGTH_SPECTDENS = 78 /* R^2/Q = R^2T */
}
ProUnitType;


typedef enum                            /* LENGTH */
{
  PRO_UNITLENGTH_NONE   = PRO_VALUE_UNUSED,
  PRO_UNITLENGTH_MICRON = 0,
  PRO_UNITLENGTH_MM     = 1,
  PRO_UNITLENGTH_CM     = 2,
  PRO_UNITLENGTH_M      = 3,
  PRO_UNITLENGTH_IN     = 4,
  PRO_UNITLENGTH_MIL    = 5,
  PRO_UNITLENGTH_FT     = 6,
  PRO_UNITLENGTH_NM		= 7,
  PRO_UNITLENGTH_KM		= 8,
  PRO_UNITLENGTH_MILE	= 9,
  MAX_LENGTH_UNIT
}
ProUnitLength;

typedef enum                            /* MASS */
{
  PRO_UNITMASS_NONE     = PRO_VALUE_UNUSED,
  PRO_UNITMASS_MG       = 0,
  PRO_UNITMASS_G        = 1,
  PRO_UNITMASS_KG       = 2,
  PRO_UNITMASS_TONNE    = 3,
  PRO_UNITMASS_OUNCE_M  = 4,
  PRO_UNITMASS_SLUG     = 5,
  PRO_UNITMASS_LBM      = 6,
  PRO_UNITMASS_TON_M    = 7,
  MAX_MASS_UNIT
}
ProUnitMass;

typedef struct
{
  double scale;
  double offset;   /* Temperature only */
}
ProUnitConversion;

typedef struct
{
  ProMdl  owner;
  ProName name;
}
ProUnititem;

/******************************************************************************/

/* Access units as systems */

extern ProError ProUnitsystemTypeGet (ProUnitsystem*     system,
                                      ProUnitsystemType* type);
/*
    Purpose: Returns the system of units type.

    Input Arguments:
        system - The unit system.

    Output Arguments:
        type - The unit system type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUnitsystemRename (ProUnitsystem* system, ProName new_name);
/*
    Purpose: Renames a system of units.

    Input Arguments:
        system - The unit system.
        new_name - The new name.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_MODIFY - The unit system cannot be modified because if is
                             standard, or new_name already exists, or the model
                             cannot be modified.
*/

extern ProError ProUnitsystemDelete (ProUnitsystem* system);
/*
    Purpose: Deletes a system of units.

    Input Arguments:
        system - The unit system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_MODIFY - The unit system cannot be modified because if is
                             standard, or is the principal system, or the model
                             cannot be modified.
*/

extern ProError ProUnitsystemIsStandard (ProUnitsystem* system,
                                         ProBoolean*    is_standard);
/*
    Purpose: Identifies if a unit system is a Creo Parametric standard system.

    Input Arguments:
        system - The unit system.

    Output Arguments:
        is_standard - PRO_B_TRUE if the system is standard,
                      PRO_B_FALSE if it's user-defined

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProMdlUnitsystemsCollect (ProMdl mdl, ProUnitsystem** systems);
/*
    Purpose: Retrieves the systems of units available to the model.

    Input Arguments:
        mdl - The model handle.

    Output Arguments:
        systems - ProArray of unit systems.  Free this array using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProMdlPrincipalunitsystemGet (ProMdl          mdl,
                                              ProUnitsystem* principal_system);
/*
    Purpose: Retrieves the principal system of units assigned to the model.

    Input Arguments:
        mdl - The model handle.

    Output Arguments:
        principal_system - The principal system of units for the model.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProMdlUnitsystemCreate (ProMdl            mdl,
                                        ProUnitsystemType type,
                                        ProName           name,
                                        ProUnititem*      units,
                                        ProUnitsystem*    new_system);
/*
    Purpose: Creates a new system of units in the model.

    Input Arguments:
        mdl - The model handle.
        type - The type of the new unit system.
        name - The name of the new unit system.
        units - The units for the new system.  Should include at most one
                occurrence of each basic unit type. If a unit of a basic type
                is missing then a corresponding one is taken from the standard
                system 'Creo Parametric Default'.

    Output Arguments:
        new_system - The new system of units in the model. May be NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_E_AMBIGUOUS - The units argument contains multiple units for a type.
*/

/******************************************************************************/

/* Access individual units (L, M, F, time, Temperature) */

extern ProError ProUnitTypeGet (ProUnititem* unit, ProUnitType* type);
/*
    Purpose: Returns the unit type.

    Input Arguments:
        unit - The unit.

    Output Arguments:
        type - The unit type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUnitConversionGet (ProUnititem*       unit,
                                      ProUnitConversion* conversion,
                                      ProUnititem*       ref_unit);
/*
    Purpose: Retrieves the conversion factor for a unit.
             Works only with basic quantities:
                PRO_UNITTYPE_LENGTH, PRO_UNITTYPE_MASS, PRO_UNITTYPE_FORCE,
                PRO_UNITTYPE_TIME, PRO_UNITTYPE_TEMPERATURE, PRO_UNITTYPE_ANGLE.

    Input Arguments:
        unit - The unit.

    Output Arguments:
        conversion - The conversion factor for the unit.
        ref_unit - The reference unit for the unit.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUnitConversionCalculate (ProUnititem       * unit_from,
                                            ProUnititem       * unit_to,
                                            ProUnitConversion * conversion);
/*
    Purpose: This function calculates conversion factors from one
             ProUnititem to another; these can belong to the same
             model or two different models.

    Input Arguments:
        unit_from - The unit from which to convert.
        unit_to - The unit to convert to.

    Output Arguments:
        conversion - The conversion factor.
                     If it is NULL, the function will just check if
                     unit conversion is possible.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_GENERAL_ERROR - Conversion failed.
*/

extern ProError ProUnitDelete (ProUnititem* unit);
/*
    Purpose: Deletes a unit.

    Input Arguments:
        unit - The unit.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_MODIFY - The unit referenced from another unit or system
                             of units and cannot be deleted.
*/

extern ProError ProUnitModify (ProUnititem*       unit,
                               ProUnitConversion* conversion,
                               ProUnititem*       ref_unit);
/*
    Purpose: Modifies a unit.
    Works only with basic quantities:
                PRO_UNITTYPE_LENGTH, PRO_UNITTYPE_MASS, PRO_UNITTYPE_FORCE,
                PRO_UNITTYPE_TIME, PRO_UNITTYPE_TEMPERATURE, PRO_UNITTYPE_ANGLE.

    Input Arguments:
        unit - The unit.
        conversion - The conversion factor for the unit.
        ref_unit - The reference unit for the unit.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_MODIFY - The unit cannot be modified because it is referenced
                             from the principal system of units or it is
                             referenced from ref_unit.
*/

extern ProError ProUnitModifyByExpression (ProUnititem* unit,
                                           ProPath      expression);
/*
    Purpose: Modifies a derived unit.

    Input Arguments:
        unit - The unit.
        expression - The unit expression.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_MODIFY - The unit cannot be modified because it is referenced
                             from the principal system of units or it is
                             referenced from ref_unit.
*/

extern ProError ProUnitRename (ProUnititem* unit, ProName new_name);
/*
    Purpose: Renames a unit.

    Input Arguments:
        unit - The unit.
        new_name - The new name.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_CANT_MODIFY - The unit is referenced from the principal system
                             of units and cannot be modified.
*/

extern ProError ProUnitIsStandard (ProUnititem* unit, ProBoolean* is_standard);
/*
    Purpose: Identifies if a unit is a Creo Parametric standard unit.

    Input Arguments:
        unit - The unit.

    Output Arguments:
        is_standard - PRO_B_TRUE if the unit is standard,
                      PRO_B_FALSE if it's user-defined.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProMdlUnitsCollect (ProMdl         mdl,
                                    ProUnitType    type,
                                    ProUnititem** units);
/*
    Purpose: Retrieves the units available to the model.

    Input Arguments:
        mdl - The model handle.
        type - The type of unit to retrieve.

    Output Arguments:
        units - ProArray of units.  Free this array using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUnitsystemUnitGet (ProUnitsystem* system,
                                      ProUnitType     type,
                                      ProUnititem*   unit);
/*
    Purpose: Retrieves the unit used by a particular system of units.

    Input Arguments:
        system - The system of units.
        type - The type of unit to retrieve.

    Output Arguments:
        unit - The unit.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND - system does not contain a unit of the
                             requested type.
*/

extern ProError ProUnitInit (ProMdl        mdl,
                             ProName       unit_name,
                             ProUnititem*  unit);
/*
    Purpose: Retrieves the unit structure for a basic unit.

    Input Arguments:
        mdl - The model owner.
        unit_name - The name of the unit to retrieve.

    Output Arguments:
        unit - The unit.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND - The indicated unit name does not exist in the model.
*/

extern ProError ProUnitInitByExpression (ProMdl        mdl,
                                         ProPath       expression,
                                         ProUnititem* unit);
/*
   Purpose:  Returns a ProUnititem given a unit-based expression, like "N/m2".

   Input Arguments:
        mdl                   - The model owning the units.
        expression            - The unit expression.

   Output Arguments:
        unit                  - The unit item.

   Return Values:
        PRO_TK_NO_ERROR       - The function succeeded.
        PRO_TK_BAD_INPUTS     - One or more arguments was
invalid.
        PRO_TK_GENERAL_ERROR  - The expression cannot be parsed.
*/

extern ProError ProUnitCreate (ProMdl              mdl,
                               ProName             unit_name,
                               ProUnitConversion*  conversion,
                               ProName             ref_unit,
                               ProUnititem*        new_unit);
/*
    Purpose: Creates a custom unit.
             Works only with basic quantities:
                PRO_UNITTYPE_LENGTH, PRO_UNITTYPE_MASS, PRO_UNITTYPE_FORCE,
                PRO_UNITTYPE_TIME, PRO_UNITTYPE_TEMPERATURE, PRO_UNITTYPE_ANGLE.

    Input Arguments:
        mdl - The model handle.
        unit_name - The unit name.
        conversion - The conversion factor for the unit.
        ref_unit - The reference unit for the unit.

    Output Arguments:
        new_unit - The new unit handle. May be NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND - The reference unit was not found in the model.
*/

extern ProError ProUnitCreateByExpression (ProMdl       mdl,
                                           ProName      unit_name,
                                           ProPath      expression,
                                           ProUnititem* new_unit);
/*
    Purpose: Creates a derived unit.

    Input Arguments:
        mdl - The model handle.
        unit_name - The unit name.
        expression - The unit expression.

    Output Arguments:
        new_unit - The new unit handle. May be NULL.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND - The reference unit was not found in the model.
*/

/******************************************************************************/

/* Model unit conversion */

typedef enum
{
  PRO_UNITCONVERT_SAME_DIMS,
  PRO_UNITCONVERT_SAME_SIZE
}
ProUnitConvertType;

extern ProError ProMdlPrincipalunitsystemSet (ProMdl             mdl,
                                              ProUnitsystem*     new_system,
                                              ProUnitConvertType type,
                                              ProBoolean         ignore_param_units,
                                              int                regeneration_flags);
/*
    Purpose: Sets the current system of units assigned to the model.
<p>
<b>Note:</b> this will regenerate the model.

    Input Arguments:
        mdl - The model handle.
        new_system - The principal system of units for the model.
        type - PRO_UNITCONVERT_SAME_DIMS to convert the model using the same
               dimension values.
               PRO_UNITCONVERT_SAME_SIZE to convert the model using the same size.
        ignore_param_units - PRO_B_TRUE to ignore parameter units during
                             conversion (maintain current values and unit types).
                             PRO_B_FALSE to use the unit conversion type to
                             govern conversion of units in parameters.
        regeneration_flags - This argument is reserved for future use.  Pass
                             PRO_VALUE_UNUSED to avoid application behavioral
                             changes once this argument becomes interpreted by the
                             function.  The current implementation for the
                             function will invoke the Fix Model UI if the
                             conversion causes a regeneration failure.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUnitExpressionGet (ProUnititem*  unit,
                                      ProPath       expression);
/*
   Purpose:  Returns a user-friendly unit description: the name (i.e. "ksi") for
   ordinary units and the expression (i.e. N/m^3) for system-generated units.

   Input Arguments:
        unit                  - The unit item.

   Output Arguments:
        expression            - The unit expression.

   Return Values:
        PRO_TK_NO_ERROR       - The function succeeded.
        PRO_TK_BAD_INPUTS     - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND    - The unit type was not recognized.
*/

extern ProError ProUnitNameGet (ProUnititem*  unit,
                                ProName       name);
/*
   Purpose:  Returns a unit name or error code if unit was created by 
   system automatically.

   Input Arguments:
        unit                  - The unit item.

   Output Arguments:
        name                  - The unit name.

   Return Values:
        PRO_TK_NO_ERROR       - The function succeeded.
        PRO_TK_BAD_INPUTS     - One or more arguments was invalid.
        PRO_TK_E_NOT_FOUND    - The unit type was not recognized.
        PRO_TK_NOT_DISPLAYED - System created unit,has no user-friendly name.
*/

PRO_END_C_DECLS

#endif /* PROMDLUNITS_H */

