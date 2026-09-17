#ifndef PROMECHGAP_H
#define PROMECHGAP_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechValue.h>
#include <ProMechContact.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_GAP_DISTR_TOTAL    = PRO_MECH_CONTACT_DISTR_TOTAL,
  PRO_MECH_GAP_DISTR_PER_UNIT = PRO_MECH_CONTACT_DISTR_PER_UNIT 
}
ProMechGapDistrType;

typedef enum
{
  PRO_MECH_GAP_NONE          = PRO_VALUE_UNUSED,

  PRO_MECH_GAP_SIMPLE        = 1
}
ProMechGapType;

typedef struct pro_gap_simple* ProMechSimpleGapData;


extern ProError ProMechgapReferencesGet (ProMechItem* item, ProMechGeomref** references);
/*
    Purpose: Obtains the references used by this gap.

    Input Arguments:
        item - The gap.

    Output Arguments:
        references - ProArray of references. Free this array using 
                     ProMechgeomrefProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
*/

extern ProError ProMechgapReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the references used by this gap. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The gap.
        references - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechgapTypeGet (ProMechItem* item, ProMechGapType* type);
/*
    Purpose: Obtains the gap type. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The gap.

    Output Arguments:
        type - The gap type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechgapSimpledataGet (ProMechItem* item, ProMechSimpleGapData* data);
/*
    Purpose: Obtains the simple data for the gap. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The ontact.

    Output Arguments:
        data - The data. Free this using ProMechsimplegapdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - The item does not contain this type of gap.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
        ProMechgapTypeGet()
*/

extern ProError ProMechsimplegapdataAlloc (ProMechSimpleGapData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate gap data handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT -The Creo Simulate session is not initialized. 
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechsimplegapdataFree (ProMechSimpleGapData data);
/*
    Purpose: Frees the memory for a Creo Simulate gap data handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgapSimpledataSet (ProMechItem* item, ProMechSimpleGapData data);
/*
    Purpose: Sets the data for the gap. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The gap.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechsimplegapdataYdirectionGet (ProMechSimpleGapData data, ProMechYDirection* y_dir);
/*
    Purpose: Obtains the Orientation for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.

    Output Arguments:
        y_dir - The Orientation. Free this output using 
                ProMechydirectionFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechsimplegapdataYdirectionSet (ProMechSimpleGapData data, ProMechYDirection y_dir);
/*
    Purpose: Sets the Orientation for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.
        y_dir - The Orientation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplegapdataDistributiontypeGet (ProMechSimpleGapData data, ProMechGapDistrType* type);
/*
    Purpose: Obtains the distribution type for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.

    Output Arguments:
        type - The distribution type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplegapdataDistributiontypeSet (ProMechSimpleGapData data, ProMechGapDistrType type);
/*
    Purpose: Sets the distribution type for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.
        type - The distribution type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsimplegapdataClearanceGet (ProMechSimpleGapData data, ProMechExpression clearance);
/*
    Purpose: Obtains the clearance for the gap data. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.

    Output Arguments:
        clearance - The clearance.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplegapdataClearanceSet (ProMechSimpleGapData data, ProMechExpression clearance);
/*
    Purpose: Sets the clearance for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.
        clearance - The clearance.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsimplegapdataAxialstiffnessGet (ProMechSimpleGapData data, ProMechExpression axial_stiff);
/*
    Purpose: Obtains the axial stiffness for the gap data. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.

    Output Arguments:
        axial_stiff - The axial stiffness.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplegapdataAxialstiffnessSet (ProMechSimpleGapData data, ProMechExpression axial_stiff);
/*
    Purpose: Sets the axial stiffness for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.
        axial_stiff - The axial stiffness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplegapdataTransversestiffnessGet (ProMechSimpleGapData data, ProMechExpression transv_stiff);
/*
    Purpose: Obtains the transverse stiffness for the gap data. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.

    Output Arguments:
        transv_stiff - The transverse stiffness.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsimplegapdataTransversestiffnessSet (ProMechSimpleGapData data, ProMechExpression transv_stiff);
/*
    Purpose: Sets the transverse stiffness for the gap data. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The gap data.
        transv_stiff - The transverse stiffness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

PRO_END_C_DECLS

#endif /* PROMECHGAP_H */
