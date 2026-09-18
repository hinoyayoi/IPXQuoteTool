#ifndef PROMATERIAL_H
#define PROMATERIAL_H



 

#include    <ProToolkit.h>
#include    <ProObjects.h>
#include    <ProParamval.h>
#include    <ProMdlUnits.h>

typedef struct pro_material
{
 ProName     matl_name;
 ProSolid    part;
} ProMaterial;

typedef struct pro_material_props
{
  double   young_modulus;
  double   poisson_ratio;
  double   shear_modulus;
  double   mass_density;
  double   therm_exp_coef;
  double   therm_exp_ref_temp;
  double   struct_damp_coef;
  double   stress_lim_tension;
  double   stress_lim_compress;
  double   stress_lim_shear;
  double   therm_conductivity;
  double   emissivity;
  double   specific_heat;
  double   hardness;
  ProName  condition;
  double   init_bend_y_factor;
  ProName  bend_table;
} ProMaterialProps, ProMaterialdata;

typedef enum
{
  PRO_MATPROP_TYPE = 0,                 /*Enumeration, see ProMtrlType */
  PRO_MATPROP_MATERIAL_DESCRIPTION,              /*String*/
  PRO_MATPROP_FAILURE_CRITERION_TYPE,            /*String*/ 
  PRO_MATPROP_FATIGUE_TYPE,                      /*String*/ 
  PRO_MATPROP_FATIGUE_MATERIAL_TYPE,             /*String*/ 
  PRO_MATPROP_FATIGUE_MATERIAL_FINISH,           /*String*/
  PRO_MATPROP_FATIGUE_STRENGTH_REDUCTION_FACTOR, /*Double*/ 
  PRO_MATPROP_TSAI_WU_INTERACTION_TERM_F12,      /*Double*/
  PRO_MATPROP_TENSILE_YIELD_STRESS,              /*Double*/ 
  PRO_MATPROP_TENSILE_ULTIMATE_STRESS_ST1,       /*Double*/
  PRO_MATPROP_TENSILE_ULTIMATE_STRESS_ST2,       /*Double*/ 
  PRO_MATPROP_COMPRESSION_ULTIMATE_STRESS_SC1,   /*Double*/ 
  PRO_MATPROP_COMPRESSION_ULTIMATE_STRESS_SC2,   /*Double*/ 
  PRO_MATPROP_POISSON_RATIO_NU21,                /*Double*/ 
  PRO_MATPROP_POISSON_RATIO_NU31,                /*Double*/ 
  PRO_MATPROP_POISSON_RATIO_NU32,                /*Double*/ 
  PRO_MATPROP_YOUNG_MODULUS_E1,                  /*Double*/ 
  PRO_MATPROP_YOUNG_MODULUS_E2,                  /*Double*/ 
  PRO_MATPROP_YOUNG_MODULUS_E3,                  /*Double*/ 
  PRO_MATPROP_SHEAR_MODULUS_G12,                 /*Double*/ 
  PRO_MATPROP_SHEAR_MODULUS_G13,                 /*Double*/ 
  PRO_MATPROP_SHEAR_MODULUS_G23,                 /*Double*/ 
  PRO_MATPROP_THERMAL_EXPANSION_COEFFICIENT_A1,  /*Double*/ 
  PRO_MATPROP_THERMAL_EXPANSION_COEFFICIENT_A2,  /*Double*/ 
  PRO_MATPROP_THERMAL_EXPANSION_COEFFICIENT_A3,  /*Double*/ 
  PRO_MATPROP_THERMAL_CONDUCTIVITY_K1,           /*Double*/ 
  PRO_MATPROP_THERMAL_CONDUCTIVITY_K2,           /*Double*/ 
  PRO_MATPROP_THERMAL_CONDUCTIVITY_K3,           /*Double*/ 
  PRO_MATPROP_HARDNESS_TYPE,                     /*String*/ 
  PRO_MATPROP_XHATCH_FILE,                       /*String*/ 
  PRO_MATPROP_STRESS_LIMIT_FOR_FATIGUE,          /*Double*/ 
  PRO_MATPROP_TEMPERATURE,                       /*Double*/ 
  PRO_MATPROP_YOUNG_MODULUS,                     /*Double*/ 
  PRO_MATPROP_POISSON_RATIO,                     /*Double*/ 
  PRO_MATPROP_MASS_DENSITY,                      /*Double*/ 
  PRO_MATPROP_THERMAL_EXPANSION_COEFFICIENT,     /*Double*/ 
  PRO_MATPROP_TENSILE_ULTIMATE_STRESS,           /*Double*/ 
  PRO_MATPROP_COMPRESSION_ULTIMATE_STRESS,       /*Double*/ 
  PRO_MATPROP_SHEAR_ULTIMATE_STRESS,             /*Double*/ 
  PRO_MATPROP_THERMAL_CONDUCTIVITY,              /*Double*/ 
  PRO_MATPROP_SPECIFIC_HEAT,                     /*Double*/ 
  PRO_MATPROP_HARDNESS,                          /*Double*/ 
  PRO_MATPROP_CONDITION,                         /*String*/
  PRO_MATPROP_INITIAL_BEND_Y_FACTOR,             /*Double*/ 
  PRO_MATPROP_BEND_TABLE,                        /*String*/ 
  PRO_MATPROP_SHEAR_MODULUS,                     /*Double*/ 
  PRO_MATPROP_THERM_EXPANSION_REF_TEMPERATURE,   /*Double*/ 
  PRO_MATPROP_STRUCTURAL_DAMPING_COEFFICIENT,    /*Double*/ 
  PRO_MATPROP_EMISSIVITY,                        /*Double*/
  PRO_MATPROP_COST_TYPE,                         /*double*/
  PRO_MATPROP_FATIGUE_CUT_OFF_CYCLES,            /*Double*/
  PRO_MATPROP_STRESS_LIMIT_FOR_TENSION,          /*Double*/
  PRO_MATPROP_STRESS_LIMIT_FOR_COMPRESSION,      /*Double*/
  PRO_MATPROP_STRESS_LIMIT_FOR_SHEAR,            /*Double*/
  PRO_MATPROP_MODEL,                             /*String*/
  PRO_MATPROP_SUB_TYPE,                          /*String*/
  PRO_MATPROP_MODEL_DEF_BY_TESTS,                /*Boolean*/
  PRO_MATPROP_MODEL_COEF_MU,                     /*Double*/
  PRO_MATPROP_MODEL_COEF_LM,                     /*Double*/
  PRO_MATPROP_MODEL_COEF_C01,                    /*Double*/
  PRO_MATPROP_MODEL_COEF_C02,                    /*Double*/
  PRO_MATPROP_MODEL_COEF_C10,                    /*Double*/
  PRO_MATPROP_MODEL_COEF_C11,                    /*Double*/
  PRO_MATPROP_MODEL_COEF_C20,                    /*Double*/
  PRO_MATPROP_MODEL_COEF_C30,                    /*Double*/
  PRO_MATPROP_MODEL_COEF_D,                      /*Double*/
  PRO_MATPROP_MODEL_COEF_D1,                     /*Double*/
  PRO_MATPROP_MODEL_COEF_D2,                     /*Double*/
  PRO_MATPROP_MODEL_COEF_D3,                     /*Double*/
  PRO_MATPROP_HARDENING,                         /*Double*/
  PRO_MATPROP_HARDENING_DEF_BY_TESTS,            /*Boolean*/
  PRO_MATPROP_TANGENT_MODULUS,                   /*Double*/
  PRO_MATPROP_MODIFIED_MODULUS,                  /*Double*/
  PRO_MATPROP_POWER_LAW_EXPONENT,                /*Double*/
  PRO_MATPROP_EXP_LAW_EXPONENT,                  /*Double*/
  PRO_MATPROP_HARDENING_LIMIT,                   /*Double*/
  PRO_MATPROP_THERMAL_SOFTENING_COEF,            /*Double*/
  PRO_MATPROP_MECHANISMS_DAMPING,                /*Double*/

  PRO_MATPROP_MAX_TYPE
} ProMaterialPropertyType;

typedef enum
{
  PRO_MATERIAL_TYPE_UNKNOWN                     =  0,
  PRO_MATERIAL_TYPE_STRUCTURAL_ISOTROPIC        = (1 << 0),
  PRO_MATERIAL_TYPE_STRUCTURAL_ORTHOTROPIC      = (1 << 1),
  PRO_MATERIAL_TYPE_STRUCTURAL_TRANS_ISOTROPIC  = (1 << 2),
  PRO_MATERIAL_TYPE_THERMAL_ISOTROPIC           = (1 << 3),
  PRO_MATERIAL_TYPE_THERMAL_ORTHOTROPIC         = (1 << 4),
  PRO_MATERIAL_TYPE_THERMAL_TRANS_ISOTROPIC     = (1 << 5)
} ProMtrlType;

/* values for failure and fatigue properties */
#define  PRO_MATERIAL_FAILURE_NONE              L"NONE"
#define  PRO_MATERIAL_FAILURE_DISTORTION_ENERGY L"DISTORTION ENERGY (VON MISES)"
#define  PRO_MATERIAL_FAILURE_MAX_SHEAR_STRESS  L"MAXIMUM SHEAR STRESS (TRESCA)"
#define  PRO_MATERIAL_FAILURE_MODIFIED_MOHR     L"MODIFIED MOHR"
#define  PRO_MATERIAL_FAILURE_MAX_STRAIN        L"MAXIMUM STRAIN"
#define  PRO_MATERIAL_FAILURE_MAX_STRESS        L"MAXIMUM STRESS"
#define  PRO_MATERIAL_FAILURE_TSAI_WU           L"TSAI-WU"

#define  PRO_MATERIAL_FATIGUE_TYPE_NONE          L"NONE"
#define  PRO_MATERIAL_FATIGUE_TYPE_UML           L"UNIFIED MATERIAL LAW (UML)"
#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_UNKNOWN          L"UNKNOWN"

#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_TITANIUM_ALLOYS  L"TITANIUM"
#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_ALUMINIUM_ALLOYS L"ALUMINIUM"
#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_FERROUS          L"FERROUS"
#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_OTHER            L"OTHER"

/* Following two fatigue material types are no longer supported.*/
/* Use PRO_MATERIAL_FATIGUE_MAT_TYPE_FERROUS instead */
#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_UNALLOYED_STEELS L"UNALLOYED STEELS"
#define  PRO_MATERIAL_FATIGUE_MAT_TYPE_LOW_ALLOY_STEELS L"LOW ALLOY STEELS"

#define  PRO_MATERIAL_FATIGUE_FINISH_POLISHED           L"POLISHED"
#define  PRO_MATERIAL_FATIGUE_FINISH_GROUND             L"GROUND"
#define  PRO_MATERIAL_FATIGUE_FINISH_GOOD_MACHINED      L"GOOD MACHINED"
#define  PRO_MATERIAL_FATIGUE_FINISH_AVERAGE_MACHINED   L"AVERAGE MACHINED"
#define  PRO_MATERIAL_FATIGUE_FINISH_POOR_MACHINED      L"POOR MACHINED"
#define  PRO_MATERIAL_FATIGUE_FINISH_HOT_ROLLED         L"HOT ROLLED"
#define  PRO_MATERIAL_FATIGUE_FINISH_CAST               L"CAST"
#define  PRO_MATERIAL_FATIGUE_FINISH_COLD_ROLLED        L"COLD ROLLED"

/* Following five fatigue material types are no longer supported */
#define  PRO_MATERIAL_FATIGUE_FINISH_FORGED             L"FORGED"
#define  PRO_MATERIAL_FATIGUE_FINISH_WATER_CORRODED     L"WATER CORRODED"
#define  PRO_MATERIAL_FATIGUE_FINISH_SEA_WATER_CORRODED L"SEA WATER CORRODED"
#define  PRO_MATERIAL_FATIGUE_FINISH_NITIRIDED          L"NITRIDED"
#define  PRO_MATERIAL_FATIGUE_FINISH_SHOT_PEENED        L"SHOT PEENED"

#define  PRO_MATERIAL_MODEL_ARRUDA_BOYCE                L"ARRUDA-BOYCE"
#define  PRO_MATERIAL_MODEL_MOONEY_RIVLIN               L"MOONEY-RIVLIN"
#define  PRO_MATERIAL_MODEL_NEO_HOOKEAN                 L"NEO-HOOKEAN"
#define  PRO_MATERIAL_MODEL_POLYNOMIAL                  L"POLYNOMIAL ORDER 2"
#define  PRO_MATERIAL_MODEL_REDUCED_POLYNOMIAL          L"REDUCED POLY. ORDER 2"
#define  PRO_MATERIAL_MODEL_YEOH                        L"YEOH"

#define  PRO_MATERIAL_HARDENING_PERFECT_PLASTICITY      L"PERFECT PLASTICITY"
#define  PRO_MATERIAL_HARDENING_LINEAR_HARDENING        L"LINEAR HARDENING"
#define  PRO_MATERIAL_HARDENING_POWER_LAW               L"POWER LAW"
#define  PRO_MATERIAL_HARDENING_EXPONENTIAL_LAW         L"EXPONENTIAL LAW"

#define  PRO_MATERIAL_SUB_TYPE_LINEAR                   L"LINEAR"
#define  PRO_MATERIAL_SUB_TYPE_HYPERELASTIC             L"HYPERELASTIC"
#define  PRO_MATERIAL_SUB_TYPE_ELASTOPLASTIC            L"ELASTOPLASTIC"

PRO_BEGIN_C_DECLS

extern ProError ProPartMaterialsGet (ProSolid         part,
                                    ProName      **p_matl_names_arr);
/*

  Purpose: Gets the array of material names existing in the part.

  Input Arguments:
     part		- The part.

  Output Arguments:
     p_matl_names_arr	- The material names array. You 
                          must preallocate this array using
                          the function <b>ProArrayAlloc()</b>.

  Return Values:
     PRO_TK_NO_ERROR	- The function successfully returned the
                          material names.
     PRO_TK_BAD_INPUTS	- The input argument is invalid.

  See Also:
     ProArrayAlloc()

*/

extern ProError ProMaterialCreate (ProSolid           part,
                                  ProName           matl_name,
			          ProMaterialdata  *p_matl_data,
                                  ProMaterial	     *p_material);
/*    
 
  Purpose: Creates a material of the specified name in the part.

  Input Arguments:
     part               - The part
     matl_name		- The material name
     p_matl_data        - The material properties to set. This argument is
                          deprecated. Pass NULL to create an empty material
                          item whose properties can be set by
                          ProMaterialPropertySet.
     
  Output Arguments:
     p_material		- The resultant material handle

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully created the material
                          in the part.
     PRO_TK_E_FOUND	- The material name already exists.
     PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.

  See Also:
     ProModelitemByNameInit()
     ProMaterialPropertySet() 
*/

extern ProError ProMaterialDataSet (ProMaterial *p_material,
                                    ProMaterialdata *p_matl_data);
/* 
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProMaterialPropertySet
  Purpose: This function is deprecated. Use ProMaterialPropertySet() for the
           individual material properties that should be defined in this
           material.  
	   <P><B> Note:</B></P> If the material's type is not entirely
	   isotropic, this function will create only those properties
           which are not dependent on type.  It will not change the type
           of the material.

           <P>Sets the material properties.

  Input Arguments: 
     p_material		- The material handle
     p_matl_data	- The material properties to set. Note: the material values
                      must all fall within the correct ranges. The values are
                      assumed to be in the units of the owner model for the
                      material, regardless of the units used by the property
                      within this material.

  Output Arguments:                         
     None

  Return Values:
     PRO_TK_NO_ERROR    - The function successfully set the values.
     PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProMaterialDataGet (ProMaterial      *p_material,
                                   ProMaterialdata *p_matl_data);
/*
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProMaterialPropertyGet
  Purpose: This function is deprecated. Use ProMaterialPropertyGet() for the
           individual material properties that should be defined in this
           material.
    
           <P> Gets the material properties for the specified  
           material in the part.
 
  Input Arguments:
     p_material		- The handle to the part material.
 
  Output Arguments:
     p_matl_data	- The material properties. Note: the values returned are
                      in the units of the owner model for the material, 
                      regardless of the units used by the property within
                      this material.
 
  Return Values:
     PRO_TK_NO_ERROR     - The function successfully retrieved the
                           information.
     PRO_TK_INVALID_TYPE - The model handle you passed to the function
                           is not a part.
     PRO_TK_BAD_INPUTS   - Either the part or material properties is NULL.
     PRO_TK_INVALID_NAME - The material name you specified is invalid
                           (for example, if you passed NULL).
     PRO_TK_E_NOT_FOUND  - The specified material name was not found in the
                           part.
*/

extern ProError ProMaterialCurrentSet (ProMaterial  *p_material);
/*
  Purpose: Sets the specified material to be current. This material will
           be used to analyze calculations of the part. <p><b>Note: </b>By 
           default, while assigning a material to a sheetmetal part, the 
           function ProMaterialCurrentSet() modifies the values of the 
           sheetmetal properties such as Y factor and/or bend table as per the 
           material file definition. This triggers a regeneration and a 
           modification of the developed length calculations of the sheetmetal 
           part. However, you can avoid this behavior by setting the value of 
           the config option "material_update_smt_bend_table" to 
           "never_replace".

  Input Arguments:
     p_material		- The material handle

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR	- The function successfully set the specified 
                          material as current.

     PRO_TK_BAD_INPUTS	- The argument is invalid.
*/


extern ProError ProMaterialCurrentGet (ProSolid       part,
                                      ProMaterial  *p_material);
/* 
  Purpose: Gets the current material setting for the part.

  Input Arguments: 
     part		- The part

  Output Arguments: 
     p_material         - The handle to the current material 

  Return Values: 
     PRO_TK_NO_ERROR    - The function successfully retrieved the information. 
     PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError ProMaterialDelete (ProMaterial      *p_material);
/*
  Purpose: Deletes the specified material from the part's database.

  Input Arguments:   
     p_material		- The material to delete 

  Output Arguments:
     None

  Return Values:                                  
     PRO_TK_NO_ERROR     - The function successfully deleted the material.
     PRO_TK_BAD_INPUTS   - You specified an invalid material handle.
*/


extern ProError ProMaterialfileRead (ProSolid         part,
                                    ProName     matl_name);
/*
  Purpose: Reads the named material properties from file and
           adds (or updates) the specified material name to the part's
           database.
 
  Input Arguments:
     part		- The part
     matl_name	        - The name of the material properties (without
                          the extension).  The function will look for
			  'matl_name'.mtl (a modern material file) first,
			  and then 'matl_name'.mat.
 
  Output Arguments:
     None
 
  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully read the material 
                            to the part.
     PRO_TK_INVALID_TYPE  - The model handle you passed to the function
                            is not a part.
     PRO_TK_GENERAL_ERROR - There is an error in the material properties
                            file.
     PRO_TK_E_NOT_FOUND   - The specifed file was not found on the drive.
 
*/

extern ProError ProMaterialfileWrite (ProMaterial   *p_material,
                                     ProFileName    out_matl_file);
/*
  Purpose: Writes the specified part material to a file.

  Input Arguments:   
     p_material		- The material handle
     out_matl_file	- The output material file name

  Output Arguments:                                                
     None

  Return Values:
     PRO_TK_NO_ERROR	- The function successfully wrote out a 
                          material file for the specified material.
     PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
     PRO_TK_BAD_CONTEXT - The function is not available in 
        		  Design Test Mode.      
*/

extern ProError ProMaterialDescriptionSet (ProMaterialItem *p_material,
                                           wchar_t      *description);
/*
  Purpose: Set the material description
 
  Input Arguments:
     p_material             - The material
     description            - The new material description. Maximum acceptable
                              length PRO_LINE_SIZE - 1.

  Output Arguments:                                                
     None

  Return Values:
     PRO_TK_NO_ERROR      - The function succeded.
     PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
     PRO_TK_LINE_TOO_LONG - The length of the description is more than
                            PRO_LINE_SIZE - 1.
     PRO_TK_GENERAL_ERROR - An error occurred during setting of description
*/

extern ProError ProMaterialDescriptionGet (ProMaterialItem *p_material,  
                                           wchar_t      **p_description);
/*
  Purpose: Get the material description
 
  Input Arguments:
     p_material             - The material
  
  Output Arguments:
     p_description          - The material description. Free this using 
                              ProWstringFree().

  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
     PRO_TK_GENERAL_ERROR - An error occurred during obtaining of description
*/

extern ProError ProMaterialPropertySet (ProMaterialItem *p_material,
                                        ProMaterialPropertyType prop_type,
                                        ProParamvalue    *p_value,
                                        ProUnititem      *p_units);
/*
  Purpose: Create or set a material property value.

<P>The following combinations of arguments are permitted for p_value and p_units:
<table border=1 cellpadding=0>
 <tr>
  <td><p align=center><b>p_value</b></p></td>
  <td><p align=center><b>p_units</b></p></td>
  <td><p align=center><b>Is the property created in the material already?</b></p></td>
  <td><p align=center><b>Result</b></p></td>
</tr>
 <tr>
  <td><p align=center>Any value</p></td>
  <td><p align=center>Appropriate units for this property, or NULL, if the property is unitless</p></td>
  <td><p align=center>NO</p></td>
  <td><p align=center>Property is created with the given units and value.</p></td>
 </tr>
 <tr>
  <td><p align=center>Any value</p></td>
  <td><p align=center>NULL</p></td>
  <td><p align=center>NO</p></td>
  <td><p align=center>Property is created with the given value using the appropriate units from the owner model.</p></td>
 </tr>
 <tr>
  <td><p align=center>Any value</p></td>
  <td><p align=center>Current units for this property, or NULL, if the property is unitless</p></td>
  <td><p align=center>YES</p></td>
  <td><p align=center>Property value is changed to the new value.</p></td>
 </tr>
 <tr>
  <td><p align=center>Any value</p></td>
  <td><p align=center>NULL</p></td>
  <td><p align=center>YES</p></td>
  <td><p align=center>Property value is changed to the new value (which is interpreted as being in the units from the owner model)</p></td>
 </tr>
 <tr>
  <td><p align=center>The current value</p></td>
  <td><p align=center >New appropriate units</p></td>
  <td><p align=center >YES</p></td>
  <td><p align=center >Property units are changed but the value is interpreted as being for the new units.</p></td>
 </tr>
 <tr>
  <td><p align=center >NULL</p></td>
  <td><p align=center >New appropriate units</p></td>
  <td><p align=center >YES</p></td>
  <td><p align=center >Property units are changed and the current value is converted to the new units.</p></td>
 </tr>
</table>
 
  Input Arguments:
     p_material             - The material.
     prop_type              - The material property type.
     p_value                - The material property value.  Can be NULL, see the 
                              table above.  
     p_units                - The material property units.  Can be NULL, see the 
                              table above. 

  Output Arguments:
      none 

  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
     PRO_TK_BAD_CONTEXT   - This property cannot be created on the material 
                            (because other properties assigned to the material 
                            already do not permit it).
     PRO_TK_NOT_VALID     - The new value for the property lies outside the 
                            permitted ranges for the property.
     PRO_TK_INVALID_TYPE  - The new units for the property are not correct for 
                            this property type.
     PRO_TK_CANT_MODIFY   - Cannot change the value of the property because
                            it is driven by a parameter, relation or function.
     PRO_TK_GENERAL_ERROR - The value type is incorrect for the property.
*/

extern ProError ProMaterialPropertyDelete (ProMaterialItem *p_material,
                                           ProMaterialPropertyType prop_type);
/*
  Purpose: Remove a material property.

  Input Arguments:
     p_material             - The material.
     prop_type              - The material property type.       

  Output Arguments:
      none

  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
     PRO_TK_E_NOT_FOUND   - This property does not exist on the material.
     PRO_TK_BAD_CONTEXT   - This property cannot be deleted on the material 
                            (because other properties assigned to the material 
                            already do not permit it).
*/


extern ProError ProMaterialPropertyGet (ProMaterialItem *p_material,
                                        ProMaterialPropertyType prop_type,
                                        ProParamvalue    *p_value,
                                        ProUnititem      *p_units);
/*
  Purpose: Get the value and units for the material property
 
  Input Arguments:
     p_material             - The material.
     prop_type              - The material property type.
  
  Output Arguments:
     p_value                - The material property value.
     p_units                - The units for the value returned.  

  Return Values:
     PRO_TK_NO_ERROR      - The function succeeded.
     PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
     PRO_TK_E_NOT_FOUND   - The material does not have this property assigned.
     PRO_TK_GENERAL_ERROR - An error occurred during obtaining of the property.
*/

PRO_END_C_DECLS
 
#endif

