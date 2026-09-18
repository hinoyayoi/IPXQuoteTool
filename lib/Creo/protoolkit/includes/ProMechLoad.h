#ifndef PROMECHLOAD_H
#define PROMECHLOAD_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechGeomref.h>
#include <ProMechValue.h>
#include <ProMechObjectref.h>


PRO_BEGIN_C_DECLS

typedef struct pro_force* ProMechForceData;
typedef struct pro_pressure* ProMechPressureData;
typedef struct pro_bearing* ProMechBearingData;
typedef struct pro_centrifugal* ProMechCentrifugalData;
typedef struct pro_gravity* ProMechGravityData;
typedef struct pro_struct_temp* ProMechGlobaltempData;  /* deprecated */
typedef struct pro_struct_temp* ProMechStructtempData;
typedef struct pro_mect_temp* ProMechMecttempData;
typedef struct pro_struct_temp* ProMechExttempData;     /* deprecated */
typedef struct pro_heat* ProMechHeatData;

typedef enum
{
            /* Structure loads */
    PRO_MECH_LOAD_FORCE                  = 10,
    PRO_MECH_LOAD_PRESSURE               = 11,
    PRO_MECH_LOAD_BEARING                = 12,
    PRO_MECH_LOAD_CENTRIFUGAL            = 13,
    PRO_MECH_LOAD_GRAVITY                = 14,
    PRO_MECH_LOAD_STRUCTURAL_TEMPERATURE = 15,
    PRO_MECH_LOAD_GLOBAL_TEMPERATURE     = 16, /* deprecated */
    PRO_MECH_LOAD_MECT_TEMPERATURE       = 17,
    PRO_MECH_LOAD_EXTERNAL_TEMPERATURE   = 18, /* deprecated */
            /* Thermal loads */
    PRO_MECH_LOAD_HEAT                   = 40
} ProMechLoadType;

typedef enum
{
        PRO_MECH_FORCE_NONE               = PRO_VALUE_UNUSED,

    PRO_MECH_FORCE_AT_POINT           = 0,
    PRO_MECH_FORCE_TOTAL              = 1,
    PRO_MECH_FORCE_TOTAL_AT_POINT     = 2,
    PRO_MECH_FORCE_PER_UNIT           = 3,
    PRO_MECH_FORCE_TLAP_UNASSOCIATED  = 4,    /* TLAPs with no geometry references */
    PRO_MECH_FORCE_TBLAP              = 5
} ProMechForceType;

typedef enum
{
  PRO_MECH_HEAT_NONE      = PRO_VALUE_UNUSED,

  PRO_MECH_HEAT_TOTAL     = 0,
  PRO_MECH_HEAT_PER_UNIT  = 1,
  PRO_MECH_HEAT_AT_POINT  = 2
}
ProMechHeatType;

extern ProError  ProMechloadReferencesGet (ProMechItem* load,
                ProMechGeomref** geomrefs);
/*
    Purpose: Obtains the load geomrefs.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        load    - The load.

    Output Arguments:
        geomrefs - ProArray of load geomrefs. The function allocates
                   memory for this argument. Use
               ProMechgeomrefProarrayFree() to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechloadTypeGet (ProMechItem* load,
                ProMechLoadType* value);
/*
    Purpose: Obtains the type of load contained in this item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        load    - The load.

    Output Arguments:
        value    - The type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechloadForcedataGet (ProMechItem* item,
                ProMechForceData* value);
/*
    Purpose: Obtains the value of the force data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The force data.  Free this using ProMechforcedataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechforcedataTypeGet (ProMechForceData data,
                ProMechForceType* value);
/*
    Purpose: Obtains the type of the force load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechforcedataForceGet (ProMechForceData data,
                ProMechVectoredValue* value);
/*
    Purpose: Obtains the force component of the load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The force component.  Free this using ProMechvectoredvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechforcedataMomentGet (ProMechForceData data,
                ProMechVectoredValue* value);
/*
    Purpose: Obtains the moment component of the load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The moment component.  Free this using ProMechvectoredvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechforcedataRefpntGet (ProMechForceData data,
                ProMechGeomref* value);
/*
    Purpose: Obtains the reference point for the force.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The reference point. Free this using ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechforcedataAxialForceIgnoreflagGet (ProMechForceData   data,
                                                     ProBool          * force_opt);
/*
    Purpose: Obtains the flag for ignoring axial tractions in case of TBLAP

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         data      - The load

    Output Arguments:
         force_opt  - PRO_B_TRUE  : Ignore Axial Tractions for TBLAP Load.
                      PRO_B_FALSE : Do Not Ignore Axial Tractions for TBLAP Load

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataAxialMomentIgnoreflagGet (ProMechForceData   data,
                                                      ProBool          * moment_opt);
/*
    Purpose: Obtains the flag for ignoring circumferential tractions in case of TBLAP

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         data      -   The load

    Output Arguments:
         moment_opt  - PRO_B_TRUE  : Ignore Circumferential Tractions for TBLAP Load.
                       PRO_B_FALSE : Do Not Ignore Circumferential Tractions for TBLAP Load

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.

*/

extern ProError  ProMechforcedataFree (ProMechForceData data);
/*
    Purpose: Frees the memory for a Creo Simulate force load data handle.

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

extern ProError  ProMechloadPressuredataGet (ProMechItem* item,
                ProMechPressureData* value);
/*
    Purpose: Obtains the value of the pressure data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The pressure data.  Free this using ProMechpressuredataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechpressuredataValueGet (ProMechPressureData data,
                ProMechValue* value);
/*
    Purpose: Obtains the value of the pressure load.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechpressuredataFree (ProMechPressureData data);
/*
    Purpose: Frees the memory for a Creo Simulate pressure load data handle.

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

extern ProError  ProMechloadBearingdataGet (ProMechItem* item,
                ProMechBearingData* value);
/*
    Purpose: Obtains the value of the bearing data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The bearing data.  Free this using ProMechbearingdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechbearingdataValueGet (ProMechBearingData data,
                ProMechVectoredValue* value);
/*
    Purpose: Obtains the value of the bearing load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvectoredvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechbearingdataFree (ProMechBearingData data);
/*
    Purpose: Frees the memory for a Creo Simulate bearing load data handle.

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

extern ProError  ProMechloadCentrifugaldataGet (ProMechItem* item,
                ProMechCentrifugalData* value);
/*
    Purpose: Obtains the value of the centrifugal data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The centrifugal load data.  Free this using
                    ProMechcentrifugaldataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechcentrifugaldataVelocityGet (ProMechCentrifugalData data,
                ProMechVectoredValue* value);
/*
    Purpose: Obtains the value of the centrifugal velocity.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The velocity.  Free this using ProMechvectoredvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechcentrifugaldataAccelerationGet (ProMechCentrifugalData data,
                ProMechVectoredValue* value);
/*
    Purpose: Obtains the value of the centrifugal acceleration.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The acceleration.  Free this using ProMechvectoredvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechcentrifugaldataFree (ProMechCentrifugalData data);
/*
    Purpose: Frees the memory for a Creo Simulate centrifugal load data handle.

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

extern ProError  ProMechloadGravitydataGet (ProMechItem* item,
                ProMechGravityData* value);
/*
    Purpose: Obtains the value of the gravity data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The gravity data.  Free this using ProMechgravitydataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechgravitydataValueGet (ProMechGravityData data,
                ProMechVectoredValue* value);
/*
    Purpose: Obtains the value of the gravity load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The value.  Free this using ProMechvectoredvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechgravitydataFree (ProMechGravityData data);
/*
    Purpose: Frees the memory for a Creo Simulate grravity load data handle.

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

extern ProError  ProMechloadGlobaltempdataGet (ProMechItem* item,
                ProMechGlobaltempData* value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechloadStructtempdataGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechloadStructtempdataGet() instead.
             <P>
             Obtains the handle to the global temperature data from
             the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The global temperature data.  Free this using
                  ProMechglobaltempdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet().
*/

extern ProError  ProMechglobaltempdataValueGet (ProMechGlobaltempData data,
                ProMechValue* value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechstructtempdataValueGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataValueGet() instead.
             <P>
             Obtains the value of the global temperature data.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechglobaltempdataReftempGet (ProMechGlobaltempData data,
                ProMechExpression value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechstructtempdataReftempGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataReftempGet() instead.
             <P>
             Obtains the reference temperature of the global temperature data.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The reference temperature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechglobaltempdataFree (ProMechGlobaltempData data);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechstructtempdataFree
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataFree() instead.
             <P>
             Frees the memory for a Creo Simulate global temperature load
             data handle.

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

extern ProError  ProMechloadStructtempdataGet (ProMechItem* item,
                ProMechStructtempData* value);
/*
    Purpose: Obtains the handle to the structural temperature data from the
                Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The structural temperature data.  Free this using
                    ProMechstructtempdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechstructtempdataValueGet (ProMechStructtempData data,
                ProMechValue* value);
/*
    Purpose: Obtains the value of the structural temperature data.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechstructtempdataReftempGet (ProMechStructtempData data,
                ProMechExpression value);
/*
    Purpose: Obtains the reference temperature of the structural temperature data.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The reference temperature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstructtempdataFree (ProMechStructtempData data);
/*
    Purpose: Frees the memory for a Creo Simulate structural temperature load data
                handle.

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

extern ProError  ProMechloadMecttempdataGet (ProMechItem* item,
                ProMechMecttempData* value);
/*
    Purpose: Obtains the MEC/T temperature data from the Creo Simulate load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The MEC/T temperature data.  Free this using
                     ProMechmecttempdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechmecttempdataAnalysisidGet (ProMechMecttempData data,
                int* analysis_id);
/*
    Purpose: Obtains the analysis id for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        analysis_id    - The analysis id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmecttempdataLoadsetidGet (ProMechMecttempData data,
                int* value);
/*
    Purpose: Obtains the load set id for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The load set id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmecttempdataReftempGet (ProMechMecttempData data,
                ProMechExpression value);
/*
    Purpose: Obtains the reference temperature for the MEC/T temperature data.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The reference temperature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmecttempdataLoadsetGet (ProMechMecttempData data, ProMechObjectref* objectref);
/*
    Purpose: Obtains the load set for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        objectref - The load set.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechmecttempdataDesignstudyGet (ProMechMecttempData data, ProName value);
/*
    Purpose: Obtains the selected design study for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        value - The selected design study.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmecttempdataTimestepGet (ProMechMecttempData data,
                int* value);
/*
    Purpose: Obtains the time step value for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The time step value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmecttempdataFree (ProMechMecttempData data);
/*
    Purpose: Frees the memory for the MEC/T temperature data.

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

extern ProError  ProMechloadExttempdataGet (ProMechItem* item,
                ProMechExttempData* value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechloadStructtempdataGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechloadStructtempdataGet() instead.
             <P>
             Obtains the handle to the external temperature data from the
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The external temperature data.  Free this
                    using ProMechexttempdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechexttempdataFemneutralfileGet (ProMechExttempData data,
                ProPath value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMechloadStructtempdataGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechloadStructtempdataGet() instead.
             <P>
             Obtains the path to the FEM neutral file for this external
             temperature data.

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
*/

extern ProError  ProMechexttempdataReftempGet (ProMechExttempData data,
                ProMechExpression value);
/*
	DEPRECATED: Since Creo 1
    SUCCESSORS: ProMathExpressionEvaluate
    Purpose: <B>Note</B>: This function is deprecated.
             <P>
             Obtains the reference temperature of the external temperature data.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The reference temperature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechexttempdataCsysGet (ProMechExttempData   data,
                                            ProMechGeomref     * csys);
/*
		DEPRECATED: Since Creo 1
		SUCCESSORS: ProMechloadStructtempdataGet
        Purpose: <B>Note</B>: This function is deprecated.
                Use ProMechloadStructtempdataGet() instead.
                <P>
                Obtains the coordinate system of the external temperature data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The data.

        Output Arguments:
                csys   - The coordinate system of the external temperature.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechexttempdataFree (ProMechExttempData data);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechstructtempdataFree
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataFree() instead.
             <P>
             Frees the memory for a Creo Simulate external temperature load
             data handle.

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

extern ProError  ProMechloadHeatdataGet (ProMechItem* item,
                ProMechHeatData* value);
/*
    Purpose: Obtains the handle to the heat load data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The item.

    Output Arguments:
        value    - The heat load data.  Free this using ProMechheatdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_INVALID_TYPE - The item does not contain this type of load.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechloadTypeGet()
*/

extern ProError  ProMechheatdataTypeGet (ProMechHeatData data,
                ProMechHeatType* type);
/*
    Purpose: Obtains the type of the heat load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        type    - The heat load type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechheatdataValueGet (ProMechHeatData data,
                ProMechValue* value);
/*
    Purpose: Obtains the value of the heat load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The heat load value.  Free this using ProMechvalueFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechheatdataTimefunctionidGet (ProMechHeatData data,
                int* value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechheatdataTemporalvariationGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechheatdataTemporalvariationGet() instead.
             <P>
             Obtains the time function that governs the heat load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.

    Output Arguments:
        value    - The time function id.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechheatdataTemporalvariationGet (ProMechHeatData data,
                                                     ProMechVariation *variation);
/*
    Purpose: Gets the time variation that governs the heat load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.

    Output Arguments:
        variation - Pointer to the time variation.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError  ProMechheatdataFree (ProMechHeatData data);
/*
    Purpose: Frees the memory for a Creo Simulate heat load data handle.

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

extern ProError ProMechloadLoadsetsGet (ProMechItem* item,
                                        int** pp_load_ids);
/*
  Purpose: Obtains the LoadSet id's for the given load.

  Licensing Requirement:
          TOOLKIT for Mechanica

  Input Arguments:
    item    - The load.

  Output Arguments:
    pp_load_ids - ProArray of LoadSet id's corresponding to the load.
                  The function allocates memory for this argument.
                  Use ProArrayFree() to free it.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
      PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.
      PRO_TK_GENERAL_ERROR - A general error was encountered.
      PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
      PRO_TK_E_NOT_FOUND - The load is not associated with any loadset.
*/


extern ProError ProMechloadReferencesSet (ProMechItem* load, ProMechGeomref* geomrefs);
/*
    Purpose: Sets the load geomrefs.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        load - The load.
        geomrefs - ProArray of load geomrefs.
                   Multiple point references are not allowed for creating
                   heat loads in Native mode.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

*/

extern ProError ProMechloadForcedataSet (ProMechItem* item, ProMechForceData data);
/*
    Purpose: Sets the value of the force data from the Creo Simulate item.

             If both force and moment directions are definded by vectors,
             the variation and coordinate system used in the force data
             will be used for the load; the variation and coordinate
             system used in the moment data will be ignored.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        data - The force data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                                                   operation.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechforcedataTypeSet (ProMechForceData data, ProMechForceType type);
/*
    Purpose: Sets the type of the force load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        type - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataForceSet (ProMechForceData data, ProMechVectoredValue value);
/*
    Purpose: Sets the force component of the load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The force component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataMomentSet (ProMechForceData data, ProMechVectoredValue value);
/*
    Purpose: Sets the moment component of the load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The moment component.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataRefpntSet (ProMechForceData data, ProMechGeomref value);
/*
    Purpose: Sets the reference point for the force.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The reference point.
                (NOTE: Only PRO_MECH_POINT_SINGLE type points and
                        PRO_MECH_VERTEX's are allowed)

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataAxialForceIgnoreflagSet (ProMechForceData data,
                                                     ProBool          force_opt);
/*
    Purpose: Sets whether the axial tractions for TBLAP Load should be ignored

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         data      - The load
         force_opt  - PRO_B_TRUE  : Ignore Axial Tractions for TBLAP Load.
                      PRO_B_FALSE : Do Not Ignore Axial Tractions for TBLAP Load

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataAxialMomentIgnoreflagSet (ProMechForceData data,
                                                      ProBool          moment_opt);
/*
    Purpose: Sets whether the circumferential tractions for TBLAP Load should be ignored

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         data      -   The load
         moment_opt  - PRO_B_TRUE  : Ignore Circumferential Tractions for TBLAP Load.
                       PRO_B_FALSE : Do Not Ignore Circumferential Tractions for TBLAP Load

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.

*/

extern ProError ProMechforcedataAlloc (ProMechForceData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate force load data handle.

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

extern ProError ProMechloadPressuredataSet (ProMechItem* item, ProMechPressureData value);
/*
    Purpose: Sets the value of the pressure data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The pressure data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechpressuredataValueSet (ProMechPressureData data, ProMechValue value);
/*
    Purpose: Sets the value of the pressure load.

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

extern ProError ProMechpressuredataAlloc (ProMechPressureData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate pressure load data handle.

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

extern ProError ProMechloadBearingdataSet (ProMechItem* item, ProMechBearingData value);
/*
    Purpose: Sets the value of the bearing data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The bearing data.

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

extern ProError ProMechbearingdataValueSet (ProMechBearingData data, ProMechVectoredValue value);
/*
    Purpose: Sets the value of the bearing load.

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

extern ProError ProMechbearingdataAlloc (ProMechBearingData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate bearing load data handle.

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

extern ProError ProMechloadCentrifugaldataSet (ProMechItem* item, ProMechCentrifugalData value);
/*
    Purpose: Sets the value of the centrifugal data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The centrifugal load data.

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

extern ProError ProMechcentrifugaldataVelocitySet (ProMechCentrifugalData data, ProMechVectoredValue value);
/*
    Purpose: Sets the value of the centrifugal velocity.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The velocity.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcentrifugaldataAccelerationSet (ProMechCentrifugalData data, ProMechVectoredValue value);
/*
    Purpose: Sets the value of the centrifugal acceleration.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The acceleration.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcentrifugaldataAlloc (ProMechCentrifugalData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate centrifugal load data
             handle.

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

extern ProError ProMechloadGravitydataSet (ProMechItem* item, ProMechGravityData value);
/*
    Purpose: Sets the value of the gravity data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The gravity data.

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

extern ProError ProMechgravitydataValueSet (ProMechGravityData data, ProMechVectoredValue value);
/*
    Purpose: Sets the value of the gravity load.

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

extern ProError ProMechgravitydataAlloc (ProMechGravityData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate gravity load data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         none

    Output Arguments:
        data - The data

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechloadGlobaltempdataSet (ProMechItem* item, ProMechGlobaltempData value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechloadStructtempdataSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechloadStructtempdataSet() instead.
             <P>
             Sets the handle to the global temperature data from the
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The global temperature data.

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

extern ProError ProMechglobaltempdataValueSet (ProMechGlobaltempData data, ProMechValue value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechstructtempdataValueSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataValueSet() instead.
             <P>
             Sets the value of the global temperature data.

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

extern ProError ProMechglobaltempdataReftempSet (ProMechGlobaltempData data, ProMechExpression value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechstructtempdataReftempSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataReftempSet() instead.
             <P>
             Sets the reference temperature of the global temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The reference temperature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechglobaltempdataAlloc (ProMechGlobaltempData* data);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechstructtempdataAlloc
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataAlloc() instead.
             <P>
             Allocates the memory for a Creo Simulate global temperature load
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

extern ProError ProMechloadStructtempdataSet (ProMechItem* item, ProMechStructtempData value);
/*
    Purpose: Sets the handle to the structural temperature data from the
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The structural temperature data.

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

extern ProError ProMechstructtempdataValueSet (ProMechStructtempData data, ProMechValue value);
/*
    Purpose: Sets the value of the structural temperature data.

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

extern ProError ProMechstructtempdataReftempSet (ProMechStructtempData data, ProMechExpression value);
/*
    Purpose: Sets the reference temperature of the structural temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The reference temperature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstructtempdataAlloc (ProMechStructtempData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate structural temperature
             load data handle.

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

extern ProError ProMechloadMecttempdataSet (ProMechItem* item, ProMechMecttempData value);
/*
    Purpose: Sets the MEC/T temperature data from the Creo Simulate load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The MEC/T temperature data.

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

extern ProError ProMechmecttempdataAnalysisidSet (ProMechMecttempData data, int analysis_id);
/*
    Purpose: Sets the analysis id for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        analysis_id - The analysis id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmecttempdataLoadsetidSet (ProMechMecttempData data, int value);
/*
    Purpose: Sets the load set id for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The load set id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmecttempdataReftempSet (ProMechMecttempData data, ProMechExpression value);
/*
    Purpose: Sets the reference temperature for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The reference temperature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError  ProMechmecttempdataLoadsetSet (ProMechMecttempData data, ProMechObjectref objectref);
/*
    Purpose: Sets the load set for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.
        objectref    - The load set.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmecttempdataDesignstudySet (ProMechMecttempData data, ProName value);
/*
    Purpose: Sets the design study for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The data.
        value    - The design study.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmecttempdataTimestepSet (ProMechMecttempData data, int value);
/*
    Purpose: Sets the time step value for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The time step value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmecttempdataAlloc (ProMechMecttempData* data);
/*
    Purpose: Allocates the memory for the MEC/T temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The data

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechloadExttempdataSet (ProMechItem* item, ProMechExttempData value);
/*
    Purpose: Sets the handle to the external temperature data from the
             Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The external temperature data.

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

extern ProError ProMechexttempdataFemneutralfileSet (ProMechExttempData data, ProPath value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechloadStructtempdataGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechloadStructtempdataGet() instead.
             <P>
             Sets the path to the FEM neutral file for this external
             temperature data.

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

extern ProError ProMechexttempdataReftempSet (ProMechExttempData data, ProMechExpression value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechstructtempdataReftempSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataReftempSet() instead.
             <P>
             Sets the reference temperature of the external temperature data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The reference temperature.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechexttempdataCsysSet (ProMechExttempData data,
                                           ProMechGeomref     csys);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechloadStructtempdataGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechloadStructtempdataGet() instead.
             <P>
             Sets the coordinate system of the external temperature data.

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

extern ProError ProMechexttempdataAlloc (ProMechExttempData* data);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechstructtempdataAlloc
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechstructtempdataAlloc() instead.
             <P>
             Allocates the memory for a Creo Simulate external temperature load
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

extern ProError ProMechloadHeatdataSet (ProMechItem* item, ProMechHeatData value);
/*
    Purpose: Sets the handle to the heat load data from the Creo Simulate item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The item.
        value - The heat load data.

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

extern ProError ProMechheatdataTypeSet (ProMechHeatData data, ProMechHeatType type);
/*
    Purpose: Sets the type of the heat load data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        type - The heat load type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/
extern ProError ProMechheatdataValueSet (ProMechHeatData data, ProMechValue value);
/*
    Purpose: Sets the value of the heat load data.
             <B>Note</B>: If a combined function(temporal+spatial) id is set in 
             ProMechHeatData, the same function Id should be set in the 
             temporal variation also (using ProMechheatdataTemporalvariationSet)
             <P>

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The heat load value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechheatdataTimefunctionidSet (ProMechHeatData data, int value);
/*
	DEPRECATED: Since Creo 1
	SUCCESSORS: ProMechheatdataTemporalvariationSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechheatdataTemporalvariationSet() instead.
             <P>
             Sets the time function that governs the heat load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        value - The time function id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechheatdataTemporalvariationSet (ProMechHeatData data,
                                                     ProMechVariation variation);
/*
    Purpose: Sets the time function that governs the heat load.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        variation - The time variation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechheatdataAlloc (ProMechHeatData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate heat load data handle.

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

extern ProError ProMechloadLoadsetAssign (ProMechItem* item,
                                          int          loadsetid,
                                          ProBool      unassign);
/*
    Purpose: Associates load with given load set.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         item      - The load to be added.
         loadsetid - Loadset id to which the load is to be added.
         unassign  - PRO_B_TRUE  : Removes the load from previous set (if any).
                     PRO_B_FALSE : Does not remove the load from previous set.
                                   Currently PRO_B_FALSE is not supported.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/


PRO_END_C_DECLS

#endif /* PROMECHLOAD_H */
