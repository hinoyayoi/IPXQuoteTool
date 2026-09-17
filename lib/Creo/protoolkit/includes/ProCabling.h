




#ifndef PRO_CABLING_H
#define PRO_CABLING_H

/*----------------------------------------------------------*\
    Headers
\*----------------------------------------------------------*/

#include <ProToolkit.h>
#include <ProMdl.h>
#include <ProModelitem.h>
#include <ProSelection.h>
#include <ProArray.h>
#include <ProParamval.h>
#include <ProColor.h>
#include <ProSurface.h>

PRO_BEGIN_C_DECLS

/*----------------------------------------------------------*\
    Data types
\*----------------------------------------------------------*/
typedef struct sld_part* ProHarness;

/* ProCable and ProCablelocation are defined as ProFeature.
   (See protoolkit/includes/ProObjects.h) */
typedef struct pro_model_item ProCable;
typedef struct pro_model_item ProCablelocation;

typedef struct pro_sub_harness
{
    int     id;
    ProName name;
    ProAssembly owner;
} ProSubharness;

typedef struct pro_spool
{
    ProName name;
    ProAssembly owner;
} ProSpool;

typedef enum
{
    PRO_CABLETYPE_CABLE = 0,
    PRO_CABLETYPE_BUNDLE,
    PRO_CABLETYPE_WIRE,
    PRO_CABLETYPE_CONDUCTOR
} ProCableType;

typedef enum
{
    PRO_BUNDLE_NONE = -1,
    PRO_BUNDLE_SHRINK,
    PRO_BUNDLE_TUBE,
    PRO_BUNDLE_TAPE
} ProBundleType;

typedef ProAsmcomppath  ProConnector;

/* struct procbl_cable_segment is defined 
   in prodevelop/includes/prodgmstruc.h */
typedef struct procbl_cable_segment *ProCablesegment;
typedef struct procbl_cable_segment_info *ProCablesegmentInfo;

typedef enum
{
    PRO_LOC_CONNECTOR = 0,
    PRO_LOC_POINT,
    PRO_LOC_FREE,
    PRO_LOC_DEPENDENT,
    PRO_LOC_AXIS,
    PRO_LOC_USE_DIR,
    PRO_LOC_OFFSET,
    PRO_LOC_SPLICE,
    PRO_LOC_LOC,
    PRO_LOC_OFFSET_CSYS,
    PRO_LOC_OFFSET_AXIS
} ProCablelocationType;

/* struct procbl_cable_segment is defined 
   in prodevelop/includes/prodgmstruc.h */
typedef struct procbl_loc_ref *ProCablelocationref;

typedef enum
{
    PRO_PARAMVAL_SINGLE,
    PRO_PARAMVAL_MULTIPLE
} ProParamvalNumber;

typedef struct  pro_cable_param_member {
	ProName   name;
	ProParamvalue  value;
} ProCableparammember;

typedef struct  pro_cable_parameter { 
	ProName    name;
        ProParamvalNumber  value_number;
	union {
		ProParamvalue    value;
		ProCableparammember*  members; /* ProArray of cable parameters*/
	}  param_value;
}  ProCableparam;

typedef enum {
	PRO_BNDLCBL_LEVEL_ALL = -1,  
	                   /*  Retrieve all the cables  */
	PRO_BNDLCBL_LEVEL_INPUT = 1, 
                           /* Retrieve cables in the input bundle only  */
	PRO_BNDLCBL_LEVEL_FIRST = 2     
                           /*  Retrieve cables in the first-level 
			           bundles (if any).  */
} ProBundleCableLevel;     

typedef void* ProRouting;

/* =================================================================== *\
          Logical reference name functions
\* =================================================================== */

extern ProError ProCablesFromLogicalGet(
    ProAssembly assy,
    ProName     **p_cable_names);
/*
  Purpose: Returns list of imported but not created cables

  Input Arguments:
     assy                 - The handle to the assembly that contains the cable.

   Output Arguments:
     p_cable_names        - Pointer to ProArray of names.
                            The function allocates memory for this argument.
                            To free it, call the function ProArrayFree. 

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully get list of  cables.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments was invalid
      PRO_TK_E_NOT_FOUND   - No cables imported from logical or all 
			     already created.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablesFromLogicalCreate(
    ProAssembly     assy,
    ProHarness      harness,
    ProName         *p_cable_names);
/*
  Purpose: Creates cables from logical
             If corresponding spools are not created they are also created by
             this function.

  Input Arguments:
     assy                  - The assembly
     harness               - The harness handle.
     p_cable_names         - ProArray of  cables' names.

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully create cables.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments was invalid
      PRO_TK_E_FOUND       - Specified cables not imported from logical or
                             already created.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablesFromLogicalAllCreate( ProAssembly      assy,
                                               ProHarness       harness,
                                               ProName         *p_cable_names,
                                               ProCable       **r_crt_cbls );
/*
  Purpose: Creates cables from logical references.
           It creates also the conductors of the given cable.
           If corresponding spools are not created they are also created by
           this function.

  Input Arguments:
     assy                  - The assembly
     harness               - The harness handle.
     p_cable_names         - ProArray of  cables' names.

   Output Arguments:
     r_crt_cbls            - ProArray of ProCable of the created cables including conductors.
	                         To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully create cables.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments was invalid
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorsFromLogicalGet (
    ProAssembly asm_mdl,
    ProName     **p_w_name);
/*
  Purpose: Returns list of imported, but not yet designated connectors

  Input Arguments:
    asm_mdl                - The handle of cablings assembly.

   Output Arguments:
    p_w_name               - Pointer to ProArray of logical connectors  names.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved parameters.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments was invalid
      PRO_TK_E_NOT_FOUND   - no cables imported from logical or
                             all already created
      PRO_TK_GENERAL_ERROR - Other errors.

*/

extern ProError ProSpoolsFromLogicalGet (
    ProAssembly assy,
    ProName     **p_w_name);
/*
  Purpose: Return list of imported, but not created spools

   Input Arguments:
    assy                   - The handle of assembly

   Output Arguments:
    p_w_name               - Pointer to ProArray of names.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieves parameters.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments was invalid.
      PRO_TK_E_FOUND       - no spools imported from logica or
                             all already created. 
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProSpoolsFromLogicalCreate (
    ProAssembly assy,
    ProName     *p_w_name,
    ProSpool    **p_spools);
/*
  Purpose: creates spools from logical
           after finishing the call, now reset the current model back to its 
           status before the call.

   Input Arguments:
    assy                   - The handle of assembly
    p_w_name               - ProArray of spool names.

   Output Arguments:
    p_spools               - Pointer to ProArray of spools.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieves parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_FOUND       - specified spools not imported from or
                             already created.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

/*-----------------------------------------------------------------------*\
    Functions to manage spools.
\*-----------------------------------------------------------------------*/
extern ProError ProAssemblySpoolsCollect(
    ProAssembly     asm_mdl,
    ProSpool        **p_spool);
/*
  Purpose: Collect spools in specified assembly

   Input Arguments:
    asm_mdl                - Assembly owner of the spool

   Output Arguments:
    p_spool                - ProArray of spool's handles. Function allocate
                             memory for this argument.
                             Use ProArrayFree to free it.
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully initialize spool.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUN    - No spool found.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSpoolCreate(
    ProAssembly     assy,
    ProName         w_name,
    ProCableType    cable_type,
    ProBundleType  sheath_type,
    ProSpool        *p_spool);
/*
   Purpose: Creates new spool.

   Input Arguments:
    assy                  - The handle of spools assembly owner.
    w_name                - The spool name.
    cable_type            - The type of created spool.
    sheath_type           - The type of bundle.

   Output Arguments:
    p_spool               - The handle of created spool.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully creates new spool.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_FOUND       - A spool with this name already exists.
			     (<b>Note</b>: in this case p_spool will contain
			     the spool information; this is an exception to
			     the rule that all information in output arguments
			     is unreliable if a function returns anything
			     other than PRO_TK_NO_ERROR.)
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSpoolParametersCollect(
    ProSpool                *spool,
    ProCableparam           **p_params);
/*
  Purpose: Retrieves parameters of specified spool

   Input Arguments:
    spool                  - Handle of spool.

   Output Arguments:
    p_params               - ProArray of parameters.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - A spool with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSpoolParameterGet(
    ProSpool                *spool,
    ProName                 w_param_name,
    ProCableparam           *p_param);
/*
  Purpose: Retrieves one parameter of specified spool

   Input Arguments:
    spool                  - Handle of spool.
    w_param_name           - Name of retrieved parameter
    
   Output Arguments:
    p_param                - Parameter handle.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSpoolCablesLengthGet(
    ProSpool                *spool,
    ProHarness               harness_ptr,
    double                  *p_length);
/*
  Purpose: Get the total length of all cables in the input harness using this specified spool

   Input Arguments:
    spool                  - Handle of spool.
    harness_ptr            - Handle of the specified harness part 
    
   Output Arguments:
    p_length               - total length of the cables.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully returned the length.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSpoolParametersSet(
    ProSpool                *spool,
    ProCableparam           *p_params);
/*
  Purpose: Set parameters for specified spool

   Input Arguments:
    spool                  - Handle of spool.
    p_params               - ProArray of new parameters.

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully sets new parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Spool with this name does not exist, or array
      			     does not contain required params, or read only
                             params are changed.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSpoolParameterDelete(
    ProSpool        *spool,
    ProName         w_param_name);
/*
  Purpose: Deletes parameter in specified spool

   Input Arguments:
    spool                  - Handle of spool.
    w_param_name           - Name of retrieved parameter
    
   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully delete parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Spool with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

/*=====================================================================*\
        Connector functions
\*=====================================================================*/
extern ProError ProAssemblyConnectorsGet(
    ProAssembly         assy,
    ProConnector   **p_cons);
/*
  Purpose: Returns list of connectors in the assembly.

  Input Arguments:
    assy                  - The handle of cabling assembly.

   Output Arguments:
    p_cons                 - Pointer to ProArray of logical connectors.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.

*/

extern ProError ProConnectorWithAllParamsDesignate(
    ProAsmcomppath   *p_connector,
    ProName           name,
    ProBool           from_logical);
/*
  Purpose: Designate the specified component as an assembly connector with
           all the logical parameters.

  Input Arguments:
    p_connector            - Handle of connector to designate
    name                   - Name of the reference designator. 
                             It can be NULL when the designation is not from 
                             logical reference.
    from_logical           - PRO_B_TRUE for designation from logical reference. 
                             PRO_B_FALSE for default designation.
   
  Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully designate.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_FOUND       - The given  name of the reference designator is 
                             already used by other connector
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorDesignate(
    ProAsmcomppath   *p_connector,
    ProName             name);
/*
  Purpose: Designate the specified component as an assembly connector 

  Input Arguments:
    p_connector            - Handle of connector to designate
    name                   - Name of logical reference designator for the 
                             logical connector (can be NULL)
   
  Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully designate.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorUndesignate(
    ProConnector  *p_connector);
/*
  Purpose: Undesignate the specified connector

  Input Arguments:
    p_connector            - Handle of connector to undesignate

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully undesignate.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorEntryPortsGet  (
    ProConnector   *p_connector,
    ProCsys         **p_csys_array);
/*
  Purpose: Retrieves the entry ports for the specified connector.

  Input Arguments:
    p_connector            - Handle of connector.

   Output Arguments:
    p_csys_array           - ProArray of csys.
                             Function allocate memory for this argument.
                             User must free it with ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorParamGet(
    ProConnector    *p_connector,
    ProName         w_param_name,
    ProCableparam   *p_param);
/*
  Purpose: Gets connector's parameter

  Input Arguments:
     p_connector           - The connectors handle.
     w_param_name          - Parameter's name.

   Output Arguments:
     p_param               - The parameter handle.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully gets parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorParamDelete(
    ProConnector    *p_connector,
    ProName         w_param_name);
/*
  Purpose: Deletes parameter of specified connector

  Input Arguments:
     p_connector          - The connectors handle.
     w_param_name         - The name of parameter.

   Output Arguments:
     None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully deletes parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Connector or parameter with this name does
                             not exist, parameter is required.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorParamsCollect(
    ProConnector    *p_connector,
    ProCableparam    **p_params);
/*
  Purpose: Retrives parameters of specified connector

  Input Arguments:
     p_connector           - The connectors handle.

   Output Arguments:
     p_params              - Pointer to ProArray of parameters.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree. 

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieves parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProConnectorParamsSet(
    ProConnector    *p_connector,
    ProCableparam   *params);
/*
  Purpose: Sets parameters of specified connector

  Input Arguments:
     p_connector           - The connectors handle.
     params                - The new parameters. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully set parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - The specified assembly is invalid or
                             the member is not a connector
      PRO_TK_GENERAL_ERROR - Other errors.

*/

/*-----------------------------------------------------------------------*\
    Functions to manage harnesses.
\*-----------------------------------------------------------------------*/

extern ProError ProAssemblyHarnessesCollect(
    ProAssembly     asm_mdl,
    ProHarness      **p_harness);
/*
  Purpose: Retrieves the array of harnesses for specified assembly and its
           subassemblies.

  Input Arguments:
    asm_mdl                - Handle of connector's assembly.

   Output Arguments:
    p_harness              - ProArray of harnesses.
                             Function allocates memory for this argument.
                             User must free it with ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Harness not found in assembly.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProAssemblyHarnessesTopCollect(
    ProAssembly     asm_mdl,
    ProHarness      **p_harness);
/*
  Purpose: Retrieves the array of harnesses for specified assembly.

  Input Arguments:
    asm_mdl                - Handle of connector's assembly.

   Output Arguments:
    p_harness              - ProArray of harnesses.
                             Function allocates memory for this argument.
                             User must free it with ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Harness not found in assembly.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProHarnessCreate(
    ProAssembly     asm_mdl,
    ProName         w_name,
    ProHarness      *p_harness);
/*
  Purpose: Creates new harness

  Input Arguments:
    asm_mdl                - The cabling assembly's handle.
    w_name                 - Harness name.

   Output Arguments:
    p_harness              - The harness handle.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully create harness.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_FOUND       - Harness with same name already exists.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProHarnessCablesCollect(
    ProHarness  harness,
    ProCable    **p_cables);
/*
  Purpose: Retrive the cables for specified harness

   Input Arguments:
    harness                - The handle of harness.

   Output Arguments:
    p_cables               - ProArray of cables's handles. Function allocates
                             memory for this argument. User must free it's 
                             using ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved cables.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProSubharnessCablesCollect(
    ProSubharness  *p_sub_harness,
    ProCable    **p_cables);
/*
  Purpose: Retrieve the cables for specified sub harness

   Input Arguments:
    p_sub_harness         - The pointer to the sub harness.

   Output Arguments:
    p_cables               - ProArray of cables's handles. Function allocates
                             memory for this argument. User must free it 
                             using ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved cables.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProHarnessLocationsCollect(
    ProAssembly         assy,
    ProHarness          harness,
    ProCablelocation    **p_location_array);
/*
  Purpose: Retrive the locations for specified harness

   Input Arguments:
    assy                   - The assembly.
    harness                - The handle of harness.

   Output Arguments:
    p_location_array       - ProArray of cables. Function allocates 
                             memory for this argument. User must free it
                             using ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved locations.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments was invalid
      PRO_TK_GENERAL_ERROR - Other error.
*/

/*==========================================================================*\
        Cable functions
\*==========================================================================*/

extern ProError ProCableHarnessesGet (
    ProAssembly assy,
    ProName    w_cable_name,
    ProHarness  **p_harnesses);
/*
  Purpose: Retrieves the harnesses in the assembly that contain the given cable.

 Input Arguments:
    assy            - The assembly handle
    w_cable_name    - The cable's name.

 Output Arguments:
    p_harnesses     - ProArray of harnesses. Function allocates memory for
                      this argument. User must free memory by ProArrayFree

  Return Values:
    PRO_TK_NO_ERROR        - The function successfully retrieved harnesses.
    PRO_TK_BAD_INPUTS      - One or more of the arguments was invalid.
    PRO_TK_NOT_FOUND       - No harnesses were found.
    PRO_TK_GENERAL_ERROR   - Other error.
*/

extern ProError ProCableColorGet (
    ProCable        *p_cable,      
    ProColor        *p_color);
/*
  Purpose: Returns the cable color.

  Input Arguments:
      p_cable             - The handle of cable.

  Output Arguments:
      p_color             - The cable's color.

  Return Values:   
      PRO_TK_NO_ERROR     - The function successfully retrieved color.
      PRO_TK_BAD_INPUTS   - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProCableLengthGet (
    ProCable        *p_cable,
    double          *p_length);
/*
  Purpose: Retrieves the length of the specified wire

 Input Arguments:
    p_cable               - The cable handle.
  
 Output Arguments:
    p_length              - The wire length.

  Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved length.
    PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
*/


extern ProError ProCableByNameGet (
     ProHarness  p_harness,
     ProName     name,
     ProCable    *p_cable);
/*
  Purpose: Returns the cable handle, given its name

   Input Arguments:
    p_harness             - The cabling harness.
    name                  - The name.

  Output Arguments:
    p_cable               - The handle of cable.
 
  Return Values:
    PRO_TK_NO_ERROR       - The function successfully initialized the cable.
    PRO_TK_BAD_INPUTS     - One or more of the arguments was invalid.
    PRO_TK_E_NOT_FOUND    - The function failed to find the cable.
    PRO_TK_GENERAL_ERROR  - The function failed.
*/

extern ProError ProCableNameGet (
    ProCable    *p_cable,
    ProName     name);
/*
  Purpose: Returns the cable name

  Input Arguments:
    p_cable               - The handle of cable.

  Output Arguments:
    name                  - The name.

  Return Values:
      PRO_TK_NO_ERROR     - The function successfully initialized the cable.
      PRO_TK_BAD_INPUTS   - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR- Other error.
*/

extern ProError ProCableTypeGet (
    ProCable        *p_cable,
    ProCableType    *p_type);
/*
  Purpose: Returns the cable type (normal cable, wire, conductor or bundle)

  Input Arguments:
      p_cable             - The handle of cable.

  Output Arguments:
      p_type              - The cable's type.

  Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved type.
      PRO_TK_BAD_INPUTS   - One or more of the arguments was invalid.
      PRO_TK_INVALID_TYPE - Invalid cable type.
      PRO_TK_GENERAL_ERROR- Other error.
*/

extern ProError ProCableCreate(
    ProHarness  harness,
    ProSpool    *spool, 
    ProName     cable_name,
    ProCable    *p_cable);
/*
  Purpose: 
	Creates new cable or wire in specified harness. The type of the cable 
        corresponds to the spool type.
      	Required parameters will be created with default values, unless the 
        cable name has been imported from a logical reference, in which case
        the parameters from the reference are used instead.
        after finishing the call, now reset the current model back to its status
        before the call

   Input Arguments:
      harness              - The handle of harness
      spool                - The spool handle
      cable_name           - The cable name

   Output Arguments:
      p_cable              - The handle of  new cable

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the new cable.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_FOUND       - Cable already exists.
      PRO_TK_E_NOT_FOUND   - Spool does not exist yet.
      PRO_TK_GENERAL_ERROR - Other error.
*/    


extern ProError ProBundleCreate(
    ProHarness      harness,
    ProSpool        *spool, 
    ProName         bundle_name,
    ProCable        *p_cables,
    ProBoolean      is_flat,
    ProCable        *p_bundle);
/*
    Purpose: Creates new bundle in specified harness
             after finishing the call, now reset the current model back to its 
             status before the call.

   Input Arguments:
      harness              - The harness handle
      spool                - The spool
      bundle_name          - The bundles name
      p_cables             - The ProArray of cables to add
      is_flat              - If PRO_B_TRUE, the bundle is flat.  
                             If PRO_B_FALSE, the bundle is round.

   Output Arguments:
      p_bundle             - The created bundle

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the new bundle.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_FOUND       - Bundle already exists.
      PRO_TK_E_NOT_FOUND   - Spool does not exist.
      PRO_TK_GENERAL_ERROR - Other error.

*/

extern ProError ProBundleCablesCollect(
    ProCable  *p_bundle,
    ProBundleCableLevel   level,
    ProCable    **p_cables);
/*
  Purpose: Retrieves cables

   Input Arguments:
      p_bundle             - bundle handle
      level                - determines which set of cables to get.

   Output Arguments:
     p_cables              - ProArray of bundles. Function allocates memory 
                             for this argument. User must free it
                             using ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully collected cables.
      PRO_TK_INVALID_TYPE  - Invalid type of specified cable (bundle);
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProCableLogicalEndsGet(
    ProAssembly     assy,
    ProCable        *p_cable,
    ProSelection    *log_end_1,
    ProSelection    *log_end_2);
/*  
  Purpose: Retrieves logical ends of specified cable

  Input Arguments:
     assy                  - The assembly
     p_cable               - The handle of cable

   Output Arguments:
      log_end_1            - The first logical endpoint allocated by the function.  
      log_end_2            - The second logical endpoint allocated by the function.  

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully get parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - one or both ends are not defined.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCableIsComplete (
    ProCable        *p_cable,
    ProBoolean      *is_complete);
/*
 Purpose: Identifies if a cable is complete.

  Input Arguments:
    p_cable                - The cable.

  Output Arguments:
    is_complete            - Whether the cable is complete.

  Return Values:
      PRO_TK_NO_ERROR      - The function successfully got the cable data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCableParameterGet(
    ProAssembly             assy,
    ProCable                *p_cable,
    ProName                 param_name,
    ProCableparam           *p_param);
/*
  Purpose: Retrieves one parameter for the specified cable. The cable 
	parameter must be single valued. Requesting a multi-valued parameter 
        will return PRO_TK_E_NOT_FOUND.

   Input Arguments:
      assy                 - The assembly
      p_cable              - The cable
      param_name           - The parameter name

   Output Arguments:
      p_param                - The handle of cable parameter

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the parameter.
      PRO_TK_E_NOT_FOUND   - cable or parameter with this name does not exist,
                             or the parameter requested is multi-valued.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error
*/

extern ProError ProCableParameterDelete(
    ProAssembly assy,
    ProCable    *p_cable,
    ProName     param_name);

/*
  Purpose: Deletes one parameter for specified cable

   Input Arguments:
      assy                 - The assembly
      p_cable              - The handle of cable
      param_name           - The name of the parameter to delete

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully delete parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error

*/

extern ProError ProCableParametersCollect(
    ProAssembly             assy,
    ProCable                *p_cable,
    ProCableparam           **p_params);
/*
  Purpose: Retrieves the parameters, including all values associated with
             multi-valued parameters, for the specified cable

  Input Arguments:
     assy                  - The assembly
     p_cable               - The handle of cable. It should be one of the
                             following types returned from ProCableTypeGet(): 
                             PRO_CABLETYPE_CABLE, PRO_CABLETYPE_WIRE,
                             PRO_CABLETYPE_BUNDLE.

   Output Arguments:
     p_params              - Pointer to ProArray of parameters.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieves parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Spool with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCableParametersSet(
    ProAssembly             assy,
    ProCable                *p_cable,
    ProCableparam           *params);
/*
  Purpose: Sets parameters for the specified cable

   Input Arguments:
      assy                 - The assembly
      p_cable              - The handle of cable
      params               - ProArray of parameters

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully set parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_E_NOT_FOUND   - Array does not contain required params or
                             read only params are changed.
      PRO_TK_GENERAL_ERROR - Other errors.
*/




extern ProError ProCableClearanceCompute (
    ProSelection    sel1,
    ProSelection    sel2,
    ProBoolean      *interference,
    ProPoint3d      pnt_arr[2]);
/*
  Purpose: Determines the clearance of the specified cable, and reports if
             interference was found

  Input Arguments:
    sel1                  - The first selection.
    sel2                  - The second selection.

   Output Arguments:
    interference          - The interference. This is PRO_B_TRUE if there is no
                            interference; otherwise, this is PRO_B_FALSE.
    pnt_arr               - The coordinates of the closest points.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully clearance.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCableSegmentsGet (
    ProCable        *p_cable,
    ProCablesegment **p_segs);
/*
 Purpose: Collect cable segments.

  Input Arguments:
    p_cable                - The cable.

  Output Arguments:
    p_segs                 - ProArray of cable segments. The function allocates
                             memory, user must free it by ProArrayFree.

  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablesegmentPointsGet (
    ProCablesegment segment,
    ProPoint3d      **p_pnts,
    ProVector       **p_tangents);
/*
  Purpose: Get cable segment points.
 
  Input Arguments:
  
    segment                - The cable segment.
    
  Output Arguments:
    p_pnts                 - ProArray of segment points. User must free memory
                             by ProArrayFree.
    p_tangents             - ProArray of segment tangents. User must free
                             memory by ProArrayFree.
                            
  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable segment data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
    
*/

extern ProError ProCablesegmentIsInBundle (
    ProCablesegment segment,
    ProBoolean      *is_in_bundle,
    ProName          bundle_name);
/*
  Purpose: Identifies whether the cable segment runs into a bundle.
 
  Input Arguments:
  
    segment                - The cable segment.
    
  Output Arguments:
  
    is_in_bundle           - Whether the cable runs into a bundle.
    bundle_name            - The name of the bundle that the segments runs into, 
                             if is_in_bundle is PRO_B_TRUE. If not, this output 
                             should be ignored.
                            
  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable segment data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
    
*/

extern ProError ProCablesegmentIsNew (
    ProCablesegment segment,
    ProBoolean      *is_new);
/*
  Purpose: Identifies whether the cable segment is connected to the previous
             segment.
 
  Input Arguments:
  
    segment                 - The cable segment.
    
  Output Arguments:
  
    is_new                  - Whether the cable is not connected to the 
                              previous segment.
 
  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable segment data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
    
*/

extern ProError ProCablesegmentInfosGet (
    ProCable        *p_cable,
    ProCablesegmentInfo **p_segs);
/*
 Purpose: Collect cable segments with location ids inside the segments.

  Input Arguments:
    p_cable                - The cable.

  Output Arguments:
    p_segs                 - ProArray of cable segments. The function allocates
                             memory, user must free it by ProArrayFree.

  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablesegmentInfoPointsGet (
    ProCablesegmentInfo segment,
    ProPoint3d      **p_pnts,
    ProVector       **p_tangents,
    int             **p_loc_ids);
/*
  Purpose: Get cable segment points, tangents and location ids.
 
  Input Arguments:
  
    segment                - The cable segment.
    
  Output Arguments:
    p_pnts                 - ProArray of segment points. User must free memory
                             by ProArrayFree.
    p_tangents             - ProArray of segment tangents. User must free
                             memory by ProArrayFree.
    p_loc_ids              - ProArray of location ids. User must free
                             memory by ProArrayFree.
                            
  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable segment data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
    
*/

extern ProError ProCablesegmentInfoIsInBundle (
    ProCablesegmentInfo segment,
    ProBoolean      *is_in_bundle,
    ProName          bundle_name);
/*
  Purpose: Identifies whether the cable segment with location information runs into a bundle.
 
  Input Arguments:
  
    segment                - The cable segment.
    
  Output Arguments:
  
    is_in_bundle           - Whether the cable runs into a bundle.
    bundle_name            - The name of the bundle that the segments runs into, 
                             if is_in_bundle is PRO_B_TRUE. If not, this output 
                             should be ignored.
                            
  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable segment data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
    
*/

extern ProError ProCablesegmentInfoIsNew (
    ProCablesegmentInfo segment,
    ProBoolean      *is_new);
/*
  Purpose: Identifies whether the cable segment with location information is
             connected to the previous segment.
 
  Input Arguments:
  
    segment                 - The cable segment.
    
  Output Arguments:
  
    is_new                  - Whether the cable is not connected to the 
                              previous segment.
 
  Return Values:
      PRO_TK_NO_ERROR      - The function successfully get cable segment data.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
    
*/

extern ProError ProCableLocationsCollect(
    ProAssembly         assy,
    ProCable            *p_cable,
    ProCablelocation    **p_location_array);
/*
  Purpose: Finds the locations for the specified cable or wire

  Input Arguments:
     assy                  - The handle to the assembly that contains the cable.
     p_cable               - The cable's handle. 

   Output Arguments:
     p_location_array      - Pointer to ProArray of locations.
                             The function allocates memory for this argument.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully get list of ids.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablelocationCablesGet(
    ProCablelocation    *p_loc,
    ProCable            **p_cables);
/*
 Purpose: Find cables at the specified location

  Input Arguments:
     p_harness             - The harness's handle.  
     p_loc                 - The location.

   Output Arguments:
     p_cables              - Pointer to ProArray of cables.
                             The function allocates memory for this argument.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully get list of  cables.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablelocationTypeGet(
    ProCablelocation        *location,
    ProCablelocationType    *p_type);
/*
  Purpose: Retrive the location's type for specified harness

   Input Arguments:
    location               - The cable location.

   Output Arguments:
    p_type                 - The cable location type.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved locations.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProCablelocationPointGet(
    ProCablelocation    *location,
    ProPoint3d          pnt,
    ProVector           tan);
/*
  Purpose: Retrive the location's point for specified harness

   Input Arguments:
    location               - The cable location.

   Output Arguments:
    pnt                    - The cable location's point.
    tan                    - The cable location's vector.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved locations.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

/*=====================================================================*\
        Routing functions
\*=====================================================================*/
extern ProError ProCableRoutingStart (
    ProAssembly         assy,
    ProCable            *p_cables,
    ProRouting  *p_cable_route_data);
/*
  Purpose: Initializes routing procedure
           This function will set the current model to the cabling harness part
           ProCableRoutingEnd() will reset the current model back to its status 
           before the call

   Input Arguments:
    assy                  - The assembly
    p_cables              - The ProArray of cables to route.

  Output Arguments:
    p_cable_route_data    - The cable routing data required for subsequent
                            function calls to route cables through locations.
                            The function allocates the space for this argument.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully start routing.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCablelocationrefAlloc (
    ProCablelocationType    type,
    ProSelection            *refs,
    ProBoolean              with_axis_dir,
    ProVector               offset,
    ProCablelocationref     *ref);
/*
  Purpose: Allocates and initializes memory for location reference
  
  Input Arguments:
    type                - The location reference type
    refs                - The ProArray of ProSelections  (If the type is 
                          PRO_LOC_TYPE_CONNECTOR, PRO_LOC_TYPE_POINT, 
                          PRO_LOC_TYPE_AXIS, PRO_LOC_TYPE_OFFSET, or
                          PRO_LOC_TYPE_LOC, one reference is sufficient).
    with_axis_dir       - If PRO_B_TRUE, follow the axis direction. 
                          If PRO_B_FALSE, go in the opposite direction.
    offset              - The offset
    
  Output Arguments:
    ref                 - The location reference
    
  Return Values:
    PRO_TK_NO_ERROR     - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS   - One or more of the arguments was invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/
  
extern ProError ProCablelocationrefFree (
    ProCablelocationref      ref);
/*
  Purpose: Releases memory that allocated by ProCablelocationrefAlloc
  
  Input Arguments:
    ref                 - The location reference.
    
  Output Arguments:
    None
    
  Return Values:
    PRO_TK_NO_ERROR      - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    
*/

extern ProError ProCableThruLocationRoute (
    ProRouting     cable_route_data,
    ProCablelocationref ref,
    ProCablelocation    *p_location,
    ProCablelocation    *second_axis_location);
/*
  Purpose: Finds or creates a cable location feature, and routes cables through it

   Input Arguments:
    cable_route_data       - The cable routing data required for subsequent
    ref                    - The reference used for the routing, obtained from
								ProCablelocationrefAlloc().

  Output Arguments:
    p_location            - The location.
    second_axis_location  - If routing through an axis, the route generates 
                           two locations. Otherwise,this is NULL.
                             
                            
   Return Values:
      PRO_TK_NO_ERROR      - The function routed the cable.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

extern ProError ProCableRoutingEnd (
    ProRouting     cable_route_data);
/*
  Purpose: Ends the cable routing
           this function will reset the current model back to its status 
           before the call to ProCableRoutingStart()

   Input Arguments:
    cable_route_data     -  The cable routing data.

  Output Arguments:
    None.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully ends routing.
      PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
      PRO_TK_GENERAL_ERROR - Other errors.
*/

typedef enum {
  PRO_CABLECOSMTYPE_TAPE,
  PRO_CABLECOSMTYPE_MARKER,
  PRO_CABLECOSMTYPE_TIE_WRAP
} ProCableCosmeticType;

extern ProError ProCableCosmeticFeatureCreate (ProCableCosmeticType type,
                                               ProSelection reference,
                                               ProName      feature_name,
                                               ProName      spool_name,
                                               ProFeature  *cosm_feature);
/*
 Purpose:
  Create a cabling cosmetic feature (a tape, marker, or tie wrap).

 Input Arguments:
  type         - The type of cabling cosmetic feature to create
  reference    - The selected cable location or cable segment point to use for
                 the feature creation. If creating a tape feature this must
                 contain a cable location. If creating a marker, this must
                 contain a point on a cable segment. If creating a tie wrap,
                 this could be a cable location or a point on a cable segment.
  feature_name - The name of the cosmetic feature, can not be NULL.
  spool_name   - The name of the spool to be used for tape feature. NULL for
                 tie wrapper and marker.

 Output Arguments:
  cosm_feature - The new cosmetic feature.

 Return Values:
  PRO_TK_NO_ERROR     - The function created the cosmetic feature.
  PRO_TK_BAD_INPUTS   - One or more of the arguments was invalid.
  PRO_TK_INVALID_TYPE - The type of the reference selection is not valid for
                        the type of cosmetic feature to be created.
  PRO_TK_E_FOUND      - A feature with the same name already exists in
                        the model.
*/

extern ProError ProCableTapeWindsSet (ProFeature* tape_feat, int num_winds);
/*
  Purpose:  Sets the number of winds in a cabling cosmetic tape feature.

  Input Arguments:
          tape_feat - The tape feature.
          num_winds - The number of winds.

  Output Arguments:
          none

   Return Values:
          PRO_TK_NO_ERROR   - The function succeeded.
          PRO_TK_BAD_INPUTS - One or more of the arguments was invalid.
*/

extern ProError ProCableTapeWindsGet (ProFeature* tape_feat, int* num_winds);
/*
  Purpose:  Gets the number of winds in a cabling cosmetic tape feature.

  Input Arguments:
          tape_feat - The tape feature.

  Output Arguments:
          num_winds - The number of winds.

   Return Values:
          PRO_TK_NO_ERROR   - The function succeeded.
          PRO_TK_BAD_INPUTS - The input argument was invalid.
*/

typedef ProCablelocation ProCablelocationPair [2];

extern ProError ProCableSectionsDelete (ProCablelocationPair boundaries,
                                        ProCable* cable_array);
/*
 Purpose:
  Deletes the sections of the designated cables which lie between the designated
  locations. Does not delete loom bundle cable sections.

 Input Arguments:
  boundaries      - array of two cable locations.
  cable_array     - ProArray of cables from which to delete sections.
                    If NULL, all cable sections between the two locations will 
                    be deleted.

 Output Arguments:
  none.

 Return Values:
  PRO_TK_NO_ERROR      - The function successfully deleted the cable sections.
  PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
  PRO_TK_BAD_CONTEXT   - One or more input cables do not pass through the 
                         supplied locations.
  PRO_TK_INVALID_ITEM  - A fixed-length cable section could not be deleted
                         because it extended beyond the cable location.
  PRO_TK_GENERAL_ERROR - A regeneration failure occurred and the deletion was
                         aborted.
  PRO_TK_NO_LICENSE    - The Pro/CABLING license was not available.
*/


extern ProError ProHarnessTessellationGet (ProHarness harness,
                                           ProSurfaceTessellationInput input_data,
                                           ProTessellation* tessellation);
/*
    Purpose: Obtains the tessellation for the thick cables in the cable 
             harness.

    Input Arguments:
        harness - The harness.
        input_data - The input data used for the tessellation.

    Output Arguments:
        tessellation - The tessellation for the harness cables.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

LIB_COREUTILS_API  ProError ProCableparammemberFree(ProCableparam *cable_param);
/*
  Purpose: Free any allocated memory in a ProCableparam.
           Frees array of ProCableparammember* inside ProCableparam.

  Input Arguments:
          cable_param - Pointer of ProCableparam type.

  Output Arguments:
      None

  Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - The input argument was invalid.
*/

LIB_COREUTILS_API  ProError ProCableparamproarrayFree(ProCableparam **cable_params);
/*
  Purpose: Free any allocated memory in array of ProCableparam.
           Also frees ProCableparammember* inside each ProCableparam.

  Input Arguments:
          cable_params - The address of the array of ProCableparam type.

   Output Arguments:
      None

   Return Values:
          PRO_TK_NO_ERROR - The function succeeded.
          PRO_TK_BAD_INPUTS - The input argument was invalid.
*/

extern ProError ProAsmcompIsHarness (ProAsmcomppath *p_comp, ProBoolean *p_is_harness);
/*
    Purpose: check if the component is a harness part.

    Input Arguments:
        p_comp - The component.

    Output Arguments:
        p_is_harness - TRUE if the component is a harness.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProAsmcompIsConnector (ProAsmcomppath *p_comp, ProBoolean *p_is_connector);
/*
    Purpose: check if the component is a cabling connector.

    Input Arguments:
        p_comp - The component.

    Output Arguments:
        p_is_connector - TRUE if the component is a cabling connector.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProFeatureIsCableCosmetic (ProFeature *cosm_feature, ProBoolean *p_is_cosm_feat);
/*
    Purpose: check if the feature is a cabling cosmetic feature.

    Input Arguments:
        cosm_feature - The feature pointer.

    Output Arguments:
        p_is_cosm_feat - TRUE if the feature is a cabling cosmetic feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProCablelocationIsAttachToHarness (ProCablelocation *p_location, ProBoolean *p_is_att_loc);
/*
    Purpose: check if the location is a cabling "attach to harness" location.

    Input Arguments:
        p_location - The location pointer.

    Output Arguments:
        p_is_att_loc - TRUE if the location is a cabling "attach to harness" location.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProCablelocationAttachToHarnessComponentGet (ProCablelocation *p_location, ProAsmcomppath *p_comp, int *p_ent_id);
/*
    Purpose: Return the component which the "attach to harness" location was
             dependent on.

    Input Arguments:
        p_location - The feature pointer.

    Output Arguments:
        p_comp - The component of the "attach to harness" location.
        p_ent_id - the geometry (csys or axis) id in the component where the
                    the location was created on.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/
extern ProError ProCableTessellationGet (ProCable *cable,
                                         ProSurfaceTessellationInput input_data,
                                         ProTessellation* tessellation);
/*
    Purpose: Obtains the tessellation for the input cable.
    
    <p><b>NOTE: </b> Set config option "display_thick_cables" to "yes" before using this API. </p>

    Input Arguments:
        cable - The input cable.
        input_data - The input data used for the tessellation.

    Output Arguments:
        tessellation - The tessellation for the cable.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
extern ProError ProCableCosmeticfeatureEntityGet(
    ProCable   *cosm_feature,
    ProCurve    **p_ent);
/*
    Purpose: Obtains the entity pointer for the input cable cosmetic feature.

    Input Arguments:
        cosm_feature - The input cable cosmetic feature pointer.

    Output Arguments:
        p_ent - The entity for the cosmetic feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
extern ProError ProCableCosmeticfeatureThicknessGet(
    ProCable   *cosm_feature,
    double       *p_thickness);
/*
    Purpose: Obtains the thickness for the input cable cosmetic feature.

    Input Arguments:
        cosm_feature - The input cable cosmetic feature pointer.

    Output Arguments:
        p_thickness - The thickness for the cosmetic feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
extern ProError ProCableCosmeticfeatureReferencethicknessGet(
    ProCable   *cosm_feature,
    double       *p_ref_thickness);
/*
    Purpose: Obtains the thickness of the cable(s) wrapped by the input cable cosmetic feature.

    Input Arguments:
        cosm_feature - The input cable cosmetic feature pointer.

    Output Arguments:
        p_ref_thickness - The reference thickness for the cosmetic feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
extern ProError ProHarnessSubharnessesCollect(
    ProAssembly    p_assem,
    ProHarness     p_harness,
    ProSubharness  **p_sub_harnesses);
/*
    Purpose: Collect all subharnesses in the input harness part.

    Input Arguments:
        p_assem - The input assembly.
        p_harness - The input harness part.

    Output Arguments:
     p_sub_harnesses    - Pointer to ProArray of ProSubharness.
                          The function allocates memory for this argument.
                          Use ProArrayFree to free it.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProCablingNeutralwirelistImport (ProAssembly    p_assem,
                                                 ProPath        filename );
/*
   Purpose: Import neutral wire list from file.

   Input Arguments:
      p_assem   - The input assembly.
      filename  - The input file name, including the extension.
                  this can be the full path to the file.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully processed the
                             file.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.

*/

extern ProError ProCableLocationsOnSegEndGet (
  ProCable cable,
  ProCablelocationPair **p_boundries);
/*
 Purpose:
  Get the locations in the end of each cable segment of the cable

 Input Arguments:
  cable           - The cable for which the end locations will be returned

 Output Arguments:
  p_boundries     - pointer to ProArray of two cable locations, start and end 
                    location of each cable segment.

 Return Values:
  PRO_TK_NO_ERROR      - The function successfully return the boundries
  PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
  PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
  
*/


extern ProError ProCablingIsHarness (ProMdl *p_mdl, ProBoolean *p_is_harness);
/*
    Purpose: check if the model handle is a harness part.

    Input Arguments:
        p_mdl - The model handle.

    Output Arguments:
        p_is_harness - TRUE if the model is a harness.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/




extern ProError ProCableTapeFeatSpoolGet (ProFeature *tape_feat,
                                          ProSpool   *p_spool);
/*
 Purpose:
  Get tape feature spool

 Input Arguments:
   tape_feat      - The tape feature.

 Output Arguments:
   p_spool       - Will be filled with the tape feat spool data.

 Return Values:
  PRO_TK_NO_ERROR      - The function successfully return the spool
  PRO_TK_BAD_INPUTS    - One or more of the arguments was invalid.
  PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
  
*/


PRO_END_C_DECLS

#endif  /* PRO_CABLING_H */

