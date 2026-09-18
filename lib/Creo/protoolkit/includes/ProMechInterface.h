#ifndef PROMECHINTERFACE_H
#define PROMECHINTERFACE_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef enum 
{
  PRO_MECH_INTERFACE_BOND_STRUCT    = 0,
  PRO_MECH_INTERFACE_BONDED         = PRO_MECH_INTERFACE_BOND_STRUCT, /* old */
  PRO_MECH_INTERFACE_FREE_STRUCT    = 1,
  PRO_MECH_INTERFACE_FREE           = PRO_MECH_INTERFACE_FREE_STRUCT, /* old */
  PRO_MECH_INTERFACE_BOND_THERM     = 2,
  PRO_MECH_INTERFACE_FREE_THERM     = 3,
  PRO_MECH_INTERFACE_CONTACT_STRUCT = 4,
  PRO_MECH_INTERFACE_RESIST_THERM   = 5
}
ProMechInterfaceType;

typedef enum 
{
  PRO_MECH_INTERFACE_FRICTION_NONE     = PRO_VALUE_UNUSED,
  PRO_MECH_INTERFACE_FRICTION_INFINITE = 0,
  PRO_MECH_INTERFACE_FRICTION_FINITE   = 1
}
ProMechInterfaceFrictionType;

/* To access model's default interface data,
 * use ProMechItem with one of the following IDs : */
#define PRO_MECH_INTERFACE_DEFAULT_STRUCT_ID (-1)
#define PRO_MECH_INTERFACE_DEFAULT_THERM_ID (-2)

typedef struct pro_connection_prop_bond * ProMechInterfaceBondData;
typedef struct pro_connection_prop_free* ProMechInterfaceFreeData;
typedef struct pro_connection_prop_contact* ProMechInterfaceContactData;
typedef struct pro_connection_prop_thr_resist* ProMechInterfaceThrresistData;


extern ProError ProMechinterfaceReferencesGet (ProMechItem* item, ProMechGeomref** references);
/*
    Purpose: Obtains the references used by this interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        references - ProArray of references. Free this using 
                     ProMechgeomrefProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechinterfaceReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the references used by this interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.
        references - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechinterfaceTypeGet (ProMechItem* item, ProMechInterfaceType* type);
/*
    Purpose: Obtains the type of the interface 
             (Bonded/Free/Contact/ThermalResistance). 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        type - The type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechinterfaceBonddataGet (ProMechItem* item, ProMechInterfaceBondData* data);
/*
    Purpose: Obtains the handle to bonded interface data from the object 
             handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        data - The handle to the interface data. Free this using 
               ProMechinterfaceBonddataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechinterfacebonddataAlloc (ProMechInterfaceBondData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate bonded interface data handle. 
             

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechinterfacebonddataFree (ProMechInterfaceBondData data);
/*
    Purpose: Frees the memory for a Creo Simulate bonded interface data handle. 

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

extern ProError ProMechinterfaceBonddataSet (ProMechItem* item, ProMechInterfaceBondData data);
/*
    Purpose: Assigns bonded interface data to the interface object.
             

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.
        data - handle to the interface data

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered. 
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechinterfaceFreedataGet (ProMechItem* item, ProMechInterfaceFreeData* data);
/*
    Purpose: Obtains the handle to free Interface data from the object handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        data - The handle to the Free interface data. Free this using 
               ProMechinterfaceFreedataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechinterfacefreedataAlloc (ProMechInterfaceFreeData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate free interface data handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechinterfacefreedataFree (ProMechInterfaceFreeData data);
/*
    Purpose: Frees the memory for a Creo Simulate free interface data handle. 

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

extern ProError ProMechinterfaceFreedataSet (ProMechItem* item, ProMechInterfaceFreeData data);
/*
    Purpose: Assigns the free interface data to the interface object. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.
        data - handle to the interface data

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechinterfaceContactdataGet (ProMechItem* item, ProMechInterfaceContactData* data);
/*
    Purpose: Obtains the handle to contact interface data from the object 
             handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        data - The handle to the interface data. Free this using 
               ProMechinterfaceContactdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechinterfacecontactdataAlloc (ProMechInterfaceContactData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate contact interface data 
             handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechinterfacecontactdataFree (ProMechInterfaceContactData data);
/*
    Purpose: Frees the memory for a Creo Simulate contact interface data handle. 

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

extern ProError ProMechinterfaceContactdataSet (ProMechItem* item, ProMechInterfaceContactData data);
/*
    Purpose: Assigns the contact interface data to the interface object. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.
        data - handle to the interface data

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechinterfaceThrresistdataGet (ProMechItem* item, ProMechInterfaceThrresistData* data);
/*
    Purpose: Obtains the handle to the thermal resistance interface data from 
             the object handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        data - The handle to the interface data. Free this using 
               ProMechinterfaceThrresistdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechinterfacethrresistdataAlloc (ProMechInterfaceThrresistData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate thermal resistance interface 
             data handle. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechinterfacethrresistdataFree (ProMechInterfaceThrresistData data);
/*
    Purpose: Frees the memory for a Creo Simulate thermal resistance interface data 
             handle. 

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

extern ProError ProMechinterfaceThrresistdataSet (ProMechItem* item, ProMechInterfaceThrresistData data);
/*
    Purpose: Assigns the thermal resistance interface data to the interface 
             object. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.
        data - The handle to the interface data

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE -  Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered. 
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.

*/

extern ProError ProMechbondinterfacedataMergenodesGet (ProMechInterfaceBondData data, ProBoolean* merge_nodes);
/*
    Purpose: Obtains whether or not this bonded interface should merge 
             coincident nodes. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        merge_nodes - PRO_B_TRUE to merge nodes, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechbondinterfacedataMergenodesSet (ProMechInterfaceBondData data, ProBoolean merge_nodes);
/*
    Purpose: Assigns whether or not this bonded interface should merge 
             coincident nodes. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        merge_nodes - PRO_B_TRUE to merge nodes, PRO_B_FALSE otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechfreeinterfacedataSplitsurfacesGet (ProMechInterfaceFreeData data, ProBoolean* split_srf);
/*
    Purpose: Obtains whether or not this free interface should split surfaces. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        split_srf - PRO_B_TRUE to split surfaces, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechfreeinterfacedataSplitsurfacesSet (ProMechInterfaceFreeData data, ProBoolean split_srf);
/*
    Purpose: Sets whether or not this free interface should split surfaces. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        split_srf - PRO_B_TRUE to split surfaces, PRO_B_FALSE otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSplitsurfacesGet (ProMechInterfaceContactData data, ProBoolean* split_srf);
/*
    Purpose: Obtains whether or not this contact interface should split surfaces.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        split_srf - PRO_B_TRUE to split surfaces, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSplitsurfacesSet (ProMechInterfaceContactData data, ProBoolean split_srf);
/*
    Purpose: Sets whether or not this contact interface should split surfaces.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        split_srf - PRO_B_TRUE to split surfaces, PRO_B_FALSE otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataCompatiblemeshGet (ProMechInterfaceContactData data, ProBoolean* compatible_mesh);
/*
    Purpose: Obtains whether or not this contact interface should create 
             compatible mesh. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        compatible_mesh - PRO_B_TRUE for compatible meshes, PRO_B_FALSE 
                          otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataCompatiblemeshSet (ProMechInterfaceContactData data, ProBoolean compatible_mesh);
/*
    Purpose: Sets whether or not this contact interface should create 
             compatible mesh. 
             Setting this attribute also sets "split surfaces" attribute.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        compatible_mesh - PRO_B_TRUE for compatible meshes, PRO_B_FALSE 
                          otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataInfiniteFrictionGet (ProMechInterfaceContactData data, ProBoolean * infinite_friction);
/*
	DEPRECATED: Since Creo 3
    SUCCESSORS: ProMechcontactinterfacedataFrictionGet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechcontactinterfacedataFrictionGet() instead.
             <P>
             Obtains whether or not this contact interface should use infinite 
             friction between pairs of nodes. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        infinite_friction - PRO_B_TRUE for infinite friction, PRO_B_FALSE 
                            otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataFrictionGet (ProMechInterfaceContactData data, ProMechInterfaceFrictionType * friction_type);
/*
    Purpose: Obtains the type of Friction at the contact interface

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        friction_type - ProMechInterfaceFrictionType

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataInfiniteFrictionSet (ProMechInterfaceContactData data, ProBoolean infinite_friction);
/*
	DEPRECATED: Since Creo 3
    SUCCESSORS: ProMechcontactinterfacedataFrictionSet
    Purpose: <B>Note</B>: This function is deprecated.
             Use ProMechcontactinterfacedataFrictionSet() instead.
             <P>
             Sets whether or not this contact interface should use infinite 
             friction between pairs of nodes. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        infinite_friction - PRO_B_TRUE for infinite friction, PRO_B_FALSE 
                            otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataFrictionSet (ProMechInterfaceContactData data, ProMechInterfaceFrictionType friction_type);
/*
    Purpose: Sets the type of Friction at the contact interface

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        friction_type - ProMechInterfaceFrictionType

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSlippageGet (ProMechInterfaceContactData data, ProBoolean * slippage);
/*
    Purpose: Obtains whether or not this contact interface should check for 
             slippage between pairs of nodes. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        slippage - PRO_B_TRUE to check for slippage, PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSlippageSet (ProMechInterfaceContactData data, ProBoolean slippage);
/*
    Purpose: Sets the flag whether or not this contact interface should check 
             for slippage between pairs of nodes. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        slippage - PRO_B_TRUE to check for slippage, PRO_B_FALSE otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.

*/

extern ProError ProMechcontactinterfacedataCoefffrictionGet (ProMechInterfaceContactData data, ProMechExpression coeff_friction);
/*
    Purpose: Obtains the coefficient of friction for this contact type 
             interface. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        coeff_friction - The coefficient of friction.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataDynamicCoefffrictionGet (ProMechInterfaceContactData data, ProMechExpression dyn_coeff_friction);
/*
    Purpose: Obtains the dynamic coefficient of friction for this contact type 
             interface. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        dyn_coeff_friction - The dynamic coefficient of friction.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataCoefffrictionSet (ProMechInterfaceContactData data, ProMechExpression coeff_friction);
/*
    Purpose: Sets the coefficient of friction for this contact type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        coeff_friction - The coefficient of friction.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.

*/

extern ProError ProMechcontactinterfacedataDynamicCoefffrictionSet (ProMechInterfaceContactData data, ProMechExpression dyn_coeff_friction);
/*
    Purpose: Sets the dynamic coefficient of friction for this contact type interface. 
             The value being set should be less than or equal to the value of static coefficient of friction for this interface.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        dyn_coeff_friction - The dynamic coefficient of friction.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.

*/

extern ProError ProMechcontactinterfacedataDynamicCoeffSameAsStaticGet (ProMechInterfaceContactData data, ProBoolean * same_as_static);
/*
    Purpose: Obtains whether or not the dynamic coefficient of friction is
              same as the static coefficient of friction.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        same_as_static - PRO_B_TRUE if the dynamic coefficient of friction is
                         same as static coefficient of friction else PRO_B_FALSE

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataDynamicCoeffSameAsStaticSet (ProMechInterfaceContactData data, ProBoolean same_as_static);
/*
    Purpose: Sets whether or not the dynamic coefficient of friction is
              same as the static coefficient of friction.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        same_as_static - PRO_B_TRUE if the dynamic coefficient of friction is
                         same as static coefficient of friction
                         PRO_B_FALSE otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.

*/

extern ProError ProMechcontactinterfacedataUseSelectionFilterTolGet (ProMechInterfaceContactData data, ProBoolean * use_sel_filter_tol);
/*
    Purpose: Obtains whether or not this contact interface should use the
              selection filter tolerances between contact surfaces

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        use_sel_filter_tol - PRO_B_TRUE if Use Selection Filter Tolerances is ON
                             PRO_B_FALSE otherwise

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataUseSelectionFilterTolSet (ProMechInterfaceContactData data, ProBoolean use_sel_filter_tol);
/*
    Purpose: Obtains whether or not this contact interface should use the
              selection filter tolerances between contact surfaces

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        use_sel_filter_tol - PRO_B_TRUE if Use Selection Filter Tolerances is ON
                             PRO_B_FALSE otherwise

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSeparationdistanceGet (ProMechInterfaceContactData data, double* sep_dist);
/*
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechcontactinterfacedataSeparationdistanceExprGet
    Purpose: <B>Note</B>: This function is deprecated.
           Use ProMechcontactinterfacedataSeparationdistanceExprGet() instead.
             <p>
             Obtains the separation distance for selection filter tolerance for 
             creating contacts between surfaces in a component-component type 
             interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        sep_dist - The Separation distance.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSeparationdistanceExprGet (ProMechInterfaceContactData data, ProMechExpression sep_dist);
/*
    Purpose: Obtains the separation distance for selection filter tolerance for 
             creating contacts between surfaces in a component-component type 
             interface. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        sep_dist - The Separation distance.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSeparationdistanceSet (ProMechInterfaceContactData data, double sep_dist);
/*
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechcontactinterfacedataSeparationdistanceExprSet
    Purpose: <B>Note</B>: This function is deprecated.
           Use ProMechcontactinterfacedataSeparationdistanceExprSet() instead.
              <p>
             Sets the separation distance for selection filter tolerance while 
             creating runtime contacts between surfaces in a 
             component-component type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        sep_dist - The Separation distance.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataSeparationdistanceExprSet (ProMechInterfaceContactData data, ProMechExpression sep_dist);
/*
    Purpose: Sets the separation distance for selection filter tolerance while 
             creating runtime contacts between surfaces in a 
             component-component type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        sep_dist - The Separation distance.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataAnglebetweensurfacesGet (ProMechInterfaceContactData data, double* angle);
/*
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechcontactinterfacedataAnglebetweensurfacesExprGet
    Purpose: <B>Note</B>: This function is deprecated.
           Use ProMechcontactinterfacedataAnglebetweensurfacesExprGet() instead.
             <p>
             Obtains the angle between surfaces for selection filter tolerance 
             while creating runtime contacts between surfaces in a 
             component-component type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        angle - The angle in degrees.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataAnglebetweensurfacesExprGet (ProMechInterfaceContactData data, ProMechExpression angle);
/*
    Purpose: Obtains the angle between surfaces for selection filter tolerance 
             while creating runtime contacts between surfaces in a 
             component-component type interface. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        angle - The angle in degrees.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataAnglebetweensurfacesSet (ProMechInterfaceContactData data, double angle);
/*
	DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProMechcontactinterfacedataAnglebetweensurfacesExprSet
    Purpose: <B>Note</B>: This function is deprecated.
           Use ProMechcontactinterfacedataAnglebetweensurfacesExprSet() instead.
             <p>
             Sets the angle between surfaces for selection filter tolerance 
             while creating contacts between surfaces in a component-component 
             type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        angle - The angle in degrees.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechcontactinterfacedataAnglebetweensurfacesExprSet (ProMechInterfaceContactData data, ProMechExpression angle);
/*
    Purpose: Sets the angle between surfaces for selection filter tolerance 
             while creating contacts between surfaces in a component-component 
             type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        angle - The angle in degrees.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataCheckonlyplanarGet (ProMechInterfaceContactData data, ProBoolean* planar_only);
/*
    Purpose: Obtains whether to check for contact between planar surfaces only, 
             for selection filter tolerance while creating runtime contacts 
             between surfaces in a component-component type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        planar_only - PRO_B_TRUE to check for planar surface only, PRO_B_FALSE 
                      otherwise.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechcontactinterfacedataCheckonlyplanarSet (ProMechInterfaceContactData data, ProBoolean planar_only);
/*
    Purpose: Sets whether to check for contact between planar surfaces only, 
             for selection filter tolerance for creating contacts between 
             surfaces in a component-component type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        planar_only - PRO_B_TRUE to check for planar surface only, PRO_B_FALSE 
                      otherwise.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechthrresistinterfacedataConductivityGet (ProMechInterfaceThrresistData data, ProMechExpression conductivity);
/*
    Purpose: Obtains the conductivity for the thermal resistance type 
             interface. 
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.

    Output Arguments:
        conductivity - The conductivity.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechthrresistinterfacedataConductivitySet (ProMechInterfaceThrresistData data, ProMechExpression conductivity);
/*
    Purpose: Sets the conductivity for the thermal resistance type interface. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The interface data.
        conductivity - The conductivity.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechinterfaceCompatiblemeshGet (ProMechItem* item, ProBoolean* compatible_mesh);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechinterfaceFreedataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechinterfaceFreedataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications.
             <P>Obtains whether or not this Free interface should create 
             compatible mesh (split surfaces). 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        compatible_mesh - the flag for compatible meshes.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechinterfaceUselinksGet (ProMechItem* item, ProBoolean* use_links);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechinterfaceBonddataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechinterfaceBonddataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications. 
             <P>Obtains whether or not this Bonded interface should use links.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The interface.

    Output Arguments:
        use_links - the flag for use links.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechinterfaceDefaultGet (ProSolid owner, ProMechInterfaceType* default_type);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechinterfaceTypeGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechinterfaceTypeGet() using a ProMechitem with the 
             appropriate special id. PTC recommends using the new function in 
             place of this function in all new or updated user applications.
             <P>Obtains the default interface connecton type. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        owner - The solid model.

    Output Arguments:
        default_type - The default type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechinterfaceDefaultUselinksGet (ProSolid owner, ProBoolean* use_links);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechinterfaceBonddataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechinterfaceBonddataGet() using a ProMechitem with the 
             appropriate special id. PTC recommends using the new function in 
             place of this function in all new or updated user applications.
             <P>Obtains whether or not Bonded default interface should use 
             links.  

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        owner - The solid model.

    Output Arguments:
        use_links - the flag for use links.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of interface.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

PRO_END_C_DECLS

#endif /* PROMECHINTERFACE_H */
