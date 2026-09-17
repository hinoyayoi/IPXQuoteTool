#ifndef PROMECHSHELLPROPS_H
#define PROMECHSHELLPROPS_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_SHLPROP_HOMOGENEOUS        = 0,
  PRO_MECH_SHLPROP_LAMINATE_STIFFNESS = 1,
  PRO_MECH_SHLPROP_LAMINATE_LAYUP     = 2
}
ProMechShellPropsType;

typedef enum
{
  PRO_MECH_LAMLAYUP_SYMMETRIC     = 0,
  PRO_MECH_LAMLAYUP_ANTISYMMETRIC = 1,
  PRO_MECH_LAMLAYUP_NEITHER       = 2
} ProMechShlpropLamLayupType;

typedef struct pro_shlprop_homogen_int* ProMechShlpropHomogeneous;
typedef struct pro_shlprop_lam_stiff_int* ProMechShlpropLaminateStiff;
typedef struct pro_shlprop_lam_layup_int* ProMechShlpropLaminateLayup;
typedef struct pro_sim_stiff_matrix* ProMechStiffMatrix;
typedef struct pro_sim_transv_shear* ProMechTransverseShear;
typedef struct pro_sim_therm_res_coeff* ProMechThermalResCoeff;
typedef struct pro_sim_str_calc_data* ProMechStressCalculationData ;
typedef struct pro_lam_layup_layer* ProMechShlpropLamLayupLayer;

extern ProError  ProMechshellpropsDescriptionGet (ProMechItem* item,
				ProComment description);
/*
	Purpose: Obtains the description for the shell properies item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell properties.

	Output Arguments:
		description	- The description.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellpropsTypeGet (ProMechItem* item,
				ProMechShellPropsType* type);
/*
	Purpose: Obtains the type of the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell properties.

	Output Arguments:
		type	- The shell properties type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechshellpropsHomogeneousdataGet (ProMechItem* item,
				ProMechShlpropHomogeneous* data);
/*
	Purpose: Obtains the homogeneous data for the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell properties.

	Output Arguments:
		data	- The homogeneous data.  Free this using 
		          ProMechshlprophomogeneousFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

        See Also:
                ProMechshellpropsTypeGet()
*/

extern ProError  ProMechshellpropsLaminatestiffdataGet (ProMechItem* item,
				ProMechShlpropLaminateStiff* data);
/*
	Purpose: Obtains the laminate stiffness data for the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell properties.

	Output Arguments:
		data	- The laminate stiffness data.  Free this using 
		          ProMechshlproplaminatestiffFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

        See Also:
                ProMechshellpropsTypeGet()
*/

extern ProError  ProMechshellpropsLaminatelayupdataGet (ProMechItem* item,
				ProMechShlpropLaminateLayup* data);
/*
	Purpose: Obtains the laminate layup data for the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The shell properties.

	Output Arguments:
		data	- The laminate layup data.  Free this using 
		          ProMechshlproplaminatelayupFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.

        See Also:
                ProMechshellpropsTypeGet()
*/

extern ProError  ProMechshlprophomogeneousThicknessGet (ProMechShlpropHomogeneous data,
				ProMechExpression thickness);
/*
	Purpose: Obtains the thickness for the shell properties.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The homogeneous data.

	Output Arguments:
		thickness	- The thickness.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlprophomogeneousFree (ProMechShlpropHomogeneous data);
/*
	Purpose: Frees the memory for a Creo Simulate homogeneous shell properties data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplaminatestiffExtensionalstiffnessGet (ProMechShlpropLaminateStiff data,
				ProMechStiffMatrix* extensional);
/*
	Purpose: Obtains the stiffness matrix for extensional loads.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		extensional	- The extensional stiffness matrix.  Free 
		                  this using ProMechstiffmatrixFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffCouplingstiffnessGet (ProMechShlpropLaminateStiff data,
				ProMechStiffMatrix* coupling);
/*
	Purpose: Obtains the stiffness matrix for coupling.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		coupling	- The coupling stiffness matrix.  Free 
		                  this using ProMechstiffmatrixFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffBendingstiffnessGet (ProMechShlpropLaminateStiff data,
				ProMechStiffMatrix* bending);
/*
	Purpose: Obtains the stiffness matrix for bending loads.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		bending	- The bending stiffness matrix.  Free 
		                  this using ProMechstiffmatrixFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffTansverseshearGet (ProMechShlpropLaminateStiff data,
				ProMechTransverseShear* transverse_shear);
/*
	Purpose: Obtains the transverse shear for the laminate stiffness properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.  Free 
		                  this using ProMechtransverseshearFree().

	Output Arguments:
		transverse_shear	- The transverse shear.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffMassperunitareaGet (ProMechShlpropLaminateStiff data,
				double* mass_per_unit_area);
/*
	Purpose: Obtains the mass per unit area for the laminate stiffness properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		mass_per_unit_area	- The mass per unit area.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplaminatestiffIntertiaperunitareaGet (ProMechShlpropLaminateStiff data,
				double* inertia_per_unit_area);
/*
	Purpose: Obtains the mass per unit area for the laminate stiffness properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		inertia_per_unit_area	- The mass per unit area.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplaminatestiffThermalresforceGet (ProMechShlpropLaminateStiff data,
				ProMechThermalResCoeff* trc_force);
/*
	Purpose: Obtains the thermal resultant coefficients for force for the laminate stiffness properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		trc_force	- The thermal resultant coefficients.  Free 
		                   this using ProMechthermalrescoeffFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffThermalresmomentGet (ProMechShlpropLaminateStiff data,
				ProMechThermalResCoeff* trc_moment);
/*
	Purpose: Obtains the thermal resultant coefficients for moment for the laminate stiffness properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		trc_moment	- The thermal resultant coefficients.  Free 
		                   this using ProMechthermalrescoeffFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffAppliedstressGet (ProMechShlpropLaminateStiff data,
				ProMechStressCalculationData** strcalc_data);
/*
	Purpose: Obtains the applied stress and strain calculations array. (Two members: the first is top, the second is bottom).

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate stiffness data.

	Output Arguments:
		strcalc_data	- ProArray containing the applied stress and 
		                  strain calculations.  The first entry of 
				  this array contains the "Top" location.  
				  The second entry contains the "Bottom" 
				  location.  Free this using 
				  ProMechstresscalcdataProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_E_NOT_FOUND - The stress and strain will be automatically calculated for this laminate stiffness data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatestiffFree (ProMechShlpropLaminateStiff data);
/*
	Purpose: Frees the memory for a Creo Simulate laminate stiffness shell properties data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplaminatelayupTypeGet (ProMechShlpropLaminateLayup data,
				ProMechShlpropLamLayupType* type);
/*
	Purpose: Obtains the type of laminate layup in the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup data.

	Output Arguments:
		type	- The type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplaminatelayupLayersGet (ProMechShlpropLaminateLayup data,
				ProMechShlpropLamLayupLayer** layers);
/*
	Purpose: Obtains the layers assigned to the laminate layup shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup data.

	Output Arguments:
		layers	- ProArray of layers. Free this using 
		          ProMechshlproplamlayuplayerProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechshlproplaminatelayupFree (ProMechShlpropLaminateLayup data);
/*
	Purpose: Frees the memory for a Creo Simulate laminate layup shell properties data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixEntry11Get (ProMechStiffMatrix data,
				double* value);
/*
	Purpose: Obtains the value of the entry '11' in the stiffness matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stiffness matrix.

	Output Arguments:
		value	- The value.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixEntry12Get (ProMechStiffMatrix data,
				double* value);
/*
	Purpose: Obtains the value of the entry '12' in the stiffness matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stiffness matrix.

	Output Arguments:
		value	- The value.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixEntry22Get (ProMechStiffMatrix data,
				double* value);
/*
	Purpose: Obtains the value of the entry '22' in the stiffness matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stiffness matrix.

	Output Arguments:
		value	- The value.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixEntry16Get (ProMechStiffMatrix data,
				double* value);
/*
	Purpose: Obtains the value of the entry '16' in the stiffness matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stiffness matrix.

	Output Arguments:
		value	- The value.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixEntry26Get (ProMechStiffMatrix data,
				double* value);
/*
	Purpose: Obtains the value of the entry '26' in the stiffness matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stiffness matrix.

	Output Arguments:
		value	- The value.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixEntry66Get (ProMechStiffMatrix data,
				double* value);
/*
	Purpose: Obtains the value of the entry '66' in the stiffness matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stiffness matrix.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstiffmatrixFree (ProMechStiffMatrix data);
/*
	Purpose: Frees the memory for a Creo Simulate stiffness matrix for a laminate stiffness shell properties handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtransverseshearEntry55Get (ProMechTransverseShear data,
				double* value);
/*
	Purpose: Obtains the value of the entry '55' in the transverse shear matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The transverse shear matrix.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtransverseshearEntry45Get (ProMechTransverseShear data,
				double* value);
/*
	Purpose: Obtains the value of the entry '45' in the transverse shear matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The transverse shear matrix.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtransverseshearEntry44Get (ProMechTransverseShear data,
				double* value);
/*
	Purpose: Obtains the value of the entry '44' in the transverse shear matrix.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The transverse shear matrix.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtransverseshearFree (ProMechTransverseShear data);
/*
	Purpose: Frees the memory for a Creo Simulate transverse shear handle for a laminate stiffness shell properties handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechthermalrescoeffEntry11Get (ProMechThermalResCoeff data,
				double* value);
/*
	Purpose: Obtains the value of the entry '11' in the thermal res coefficients.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The thermal res coefficient handle.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechthermalrescoeffEntry22Get (ProMechThermalResCoeff data,
				double* value);
/*
	Purpose: Obtains the value of the entry '22' in the thermal res coefficients.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The thermal res coefficient handle.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechthermalrescoeffEntry12Get (ProMechThermalResCoeff data,
				double* value);
/*
	Purpose: Obtains the value of the entry '12' in the thermal res coefficients.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The thermal res coefficient handle.

	Output Arguments:
		value	- The value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechthermalrescoeffFree (ProMechThermalResCoeff data);
/*
	Purpose: Frees the memory for a Creo Simulate thermal res coefficient matrix for a laminate stiffness shell properties handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstresscalcdataCzGet (ProMechStressCalculationData data,
				double* cz);
/*
	Purpose: Obtains the value of CZ for this stress and strain calculation.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stress calculation data handle.

	Output Arguments:
		cz	- The CZ value.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstresscalcdataPlyorientationGet (ProMechStressCalculationData data,
				double* ply_orient);
/*
	Purpose: Obtains the ply orientation for this stress and strain calculation.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stress calculation data handle.

	Output Arguments:
		ply_orient	- The ply orientation (in degrees).

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstresscalcdataMaterialGet (ProMechStressCalculationData data,
				ProName material);
/*
	Purpose: Obtains the material name for the stress calculation handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stress calculation data handle.

	Output Arguments:
		material	- The material name.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstresscalcdataMaterialIdGet (ProMechStressCalculationData data,
				int* matl_id);
/*
	Purpose: Obtains the material id for the stress calculation handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The stress calculation data handle.

	Output Arguments:
		matl_id	- The material id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstresscalcdataFree (ProMechStressCalculationData data);
/*
	Purpose: Frees the memory for a Creo Simulate stress calculation data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechstresscalcdataProarrayFree (ProMechStressCalculationData* data);
/*
	Purpose: Frees the memory for a Creo Simulate stress calculation data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerMaterialGet (ProMechShlpropLamLayupLayer data,
				ProName material);
/*
	Purpose: Obtains the material assigned to this layer in the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup layer handle.

	Output Arguments:
		material	- The material.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerMaterialIdGet (ProMechShlpropLamLayupLayer data,
				int* matl_id);
/*
	Purpose: Obtains the material id assigned to this layer in the shell properties.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup layer handle.

	Output Arguments:
		matl_id	- The material id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerShellpropsGet (ProMechShlpropLamLayupLayer data,
				int* shlprop_id);
/*
	Purpose: Obtains the shell properties for the given laminate layer.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup layer handle.

	Output Arguments:
		shlprop_id	- The shell properties id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerThicknessGet (ProMechShlpropLamLayupLayer data,
				ProMechExpression thickness);
/*
	Purpose: Obtains the thickness for the laminate layer.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup layer handle.

	Output Arguments:
		thickness	- The thickness.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerOrientationGet (ProMechShlpropLamLayupLayer data,
				ProCharLine orientation);
/*
	Purpose: Obtains "the orientation ( a string like "0/90/45").

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup layer handle.

	Output Arguments:
		orientation	- The orientation string.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerNumberGet (ProMechShlpropLamLayupLayer data,
				int* number);
/*
	Purpose: Obtains the number for the laminate layup layer.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The laminate layup layer handle.

	Output Arguments:
		number	- The number.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerFree (ProMechShlpropLamLayupLayer data);
/*
	Purpose: Frees the memory for a Creo Simulate laminate layup layer data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechshlproplamlayuplayerProarrayFree (ProMechShlpropLamLayupLayer* data);
/*
	Purpose: Frees the memory for a Creo Simulate laminate layup layer data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechshellpropsDescriptionSet (ProMechItem* item, ProComment description);
/*
    Purpose: Sets the description for the shell properies item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell properties.
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

extern ProError ProMechshellpropsHomogeneousdataSet (ProMechItem* item, ProMechShlpropHomogeneous data);
/*
    Purpose: Sets the homogeneous data for the shell properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell properties.
        data - The homogeneous data. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshellpropsLaminatestiffdataSet (ProMechItem* item, ProMechShlpropLaminateStiff data);
/*
    Purpose: Sets the laminate stiffness data for the shell properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell properties.
        data - The laminate stiffness data. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshellpropsLaminatelayupdataSet (ProMechItem* item, ProMechShlpropLaminateLayup data);
/*
    Purpose: Sets the laminate layup data for the shell properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The shell properties.
        data - The laminate layup data.  

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechshlprophomogeneousThicknessSet (ProMechShlpropHomogeneous data, ProMechExpression thickness);
/*
    Purpose: Sets the thickness for the shell properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The homogeneous data.
        thickness - The thickness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlprophomogeneousAlloc (ProMechShlpropHomogeneous* data);
/*
    Purpose: Allocates the memory for a Creo Simulate homogeneous shell 
             properties data handle.

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

extern ProError ProMechshlproplaminatestiffExtensionalstiffnessSet (ProMechShlpropLaminateStiff data, ProMechStiffMatrix extensional);
/*
    Purpose: Sets the stiffness matrix for extensional loads.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        extensional - The extensional stiffness matrix.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffCouplingstiffnessSet (ProMechShlpropLaminateStiff data, ProMechStiffMatrix coupling);
/*
    Purpose: Sets the stiffness matrix for coupling.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        coupling - The coupling stiffness matrix.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffBendingstiffnessSet (ProMechShlpropLaminateStiff data, ProMechStiffMatrix bending);
/*
    Purpose: Sets the stiffness matrix for bending loads.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        bending - The bending stiffness matrix.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffTansverseshearSet (ProMechShlpropLaminateStiff data, ProMechTransverseShear transverse_shear);
/*
    Purpose: Sets the transverse shear for the laminate stiffness properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        transverse_shear - The transverse shear.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffMassperunitareaSet (ProMechShlpropLaminateStiff data, double mass_per_unit_area);
/*
    Purpose: Sets the mass per unit area for the laminate stiffness properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        mass_per_unit_area - The mass per unit area.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffIntertiaperunitareaSet (ProMechShlpropLaminateStiff data, double inertia_per_unit_area);
/*
    Purpose: Sets the mass per unit area for the laminate stiffness properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        inertia_per_unit_area - The mass per unit area.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffThermalresforceSet (ProMechShlpropLaminateStiff data, ProMechThermalResCoeff trc_force);
/*
    Purpose: Sets the thermal resultant coefficients for force for the laminate 
             stiffness properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        trc_force - The thermal resultant coefficients.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffThermalresmomentSet (ProMechShlpropLaminateStiff data, ProMechThermalResCoeff trc_moment);
/*
    Purpose: Sets the thermal resultant coefficients for moment for the 
             laminate stiffness properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        trc_moment - The thermal resultant coefficients.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffAppliedstressSet (ProMechShlpropLaminateStiff data, ProMechStressCalculationData* strcalc_data);
/*
    Purpose: Sets the applied stress and strain calculations array. (Two 
             members: the first is top, the second is bottom).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate stiffness data.
        strcalc_data - ProArray containing the applied stress and               
                           strain calculations.  The first entry of   this 
                       array contains the "Top" location.    The second entry 
                       contains the "Bottom"   location.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatestiffAlloc (ProMechShlpropLaminateStiff* data);
/*
    Purpose: Allocates the memory for a Creo Simulate laminate stiffness shell 
             properties data handle.

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

extern ProError ProMechshlproplaminatelayupTypeSet (ProMechShlpropLaminateLayup data, ProMechShlpropLamLayupType type);
/*
    Purpose: Sets the type of laminate layup in the shell properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup data.
        type - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatelayupLayersSet (ProMechShlpropLaminateLayup data, ProMechShlpropLamLayupLayer* layers);
/*
    Purpose: Sets the layers assigned to the laminate layup shell properties.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup data.
        layers - ProArray of layers.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplaminatelayupAlloc (ProMechShlpropLaminateLayup* data);
/*
    Purpose: Allocates the memory for a Creo Simulate laminate layup shell 
             properties data handle.

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

extern ProError ProMechstiffmatrixEntry11Set (ProMechStiffMatrix data, double value);
/*
    Purpose: Sets the value of the entry '11' in the stiffness matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stiffness matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstiffmatrixEntry12Set (ProMechStiffMatrix data, double value);
/*
    Purpose: Sets the value of the entry '12' in the stiffness matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stiffness matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstiffmatrixEntry22Set (ProMechStiffMatrix data, double value);
/*
    Purpose: Sets the value of the entry '22' in the stiffness matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stiffness matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstiffmatrixEntry16Set (ProMechStiffMatrix data, double value);
/*
    Purpose: Sets the value of the entry '16' in the stiffness matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stiffness matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstiffmatrixEntry26Set (ProMechStiffMatrix data, double value);
/*
    Purpose: Sets the value of the entry '26' in the stiffness matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stiffness matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstiffmatrixEntry66Set (ProMechStiffMatrix data, double value);
/*
    Purpose: Sets the value of the entry '66' in the stiffness matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stiffness matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstiffmatrixAlloc (ProMechStiffMatrix* data);
/*
    Purpose: Allocates the memory for a Creo Simulate stiffness matrix for a 
             laminate stiffness shell properties handle.

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

extern ProError ProMechtransverseshearEntry55Set (ProMechTransverseShear data, double value);
/*
    Purpose: Sets the value of the entry '55' in the transverse shear matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The transverse shear matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechtransverseshearEntry45Set (ProMechTransverseShear data, double value);
/*
    Purpose: Sets the value of the entry '45' in the transverse shear matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The transverse shear matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechtransverseshearEntry44Set (ProMechTransverseShear data, double value);
/*
    Purpose: Sets the value of the entry '44' in the transverse shear matrix.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The transverse shear matrix.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechtransverseshearAlloc (ProMechTransverseShear* data);
/*
    Purpose: Allocates the memory for a Creo Simulate transverse shear handle 
             for a laminate stiffness shell properties handle.

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

extern ProError ProMechthermalrescoeffEntry11Set (ProMechThermalResCoeff data, double value);
/*
    Purpose: Sets the value of the entry '11' in the thermal res coefficients.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The thermal res coefficient handle.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechthermalrescoeffEntry22Set (ProMechThermalResCoeff data, double value);
/*
    Purpose: Sets the value of the entry '22' in the thermal res coefficients.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The thermal res coefficient handle.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechthermalrescoeffEntry12Set (ProMechThermalResCoeff data, double value);
/*
    Purpose: Sets the value of the entry '12' in the thermal res coefficients.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The thermal res coefficient handle.
        value - The value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechthermalrescoeffAlloc (ProMechThermalResCoeff* data);
/*
    Purpose: Allocates the memory for a Creo Simulate thermal res coefficient 
             matrix for a laminate stiffness shell properties handle.

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

extern ProError ProMechstresscalcdataCzSet (ProMechStressCalculationData data, double cz);
/*
    Purpose: Sets the value of CZ for this stress and strain calculation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stress calculation data handle.
        cz - The CZ value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstresscalcdataPlyorientationSet (ProMechStressCalculationData data, double ply_orient);
/*
    Purpose: Sets the ply orientation for this stress and strain calculation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stress calculation data handle.
        ply_orient - The ply orientation (in degrees).

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstresscalcdataMaterialIdSet (ProMechStressCalculationData data, int matl_id);
/*
    Purpose: Sets the material id for this stress and strain calculation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The stress calculation data handle.
        matl_id - The material id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechstresscalcdataAlloc (ProMechStressCalculationData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate stress calculation data 
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

extern ProError ProMechshlproplamlayuplayerMaterialIdSet (ProMechShlpropLamLayupLayer data, int matl_id);
/*
    Purpose: Sets the material id for the given laminate layer.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup layer handle.
        matl_id - The material id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplamlayuplayerShellpropsSet (ProMechShlpropLamLayupLayer data, int shlprop_id);
/*
    Purpose: Sets the shell properties for the given laminate layer.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup layer handle.
        shlprop_id - The shell properties id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplamlayuplayerThicknessSet (ProMechShlpropLamLayupLayer data, ProMechExpression thickness);
/*
    Purpose: Sets the thickness for the laminate layer.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup layer handle.
        thickness - The thickness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplamlayuplayerOrientationSet (ProMechShlpropLamLayupLayer data, ProCharLine orientation);
/*
    Purpose: Sets the orientation ( a string like "0/90/45").

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup layer handle.
        orientation - The orientation string.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplamlayuplayerNumberSet (ProMechShlpropLamLayupLayer data, int number);
/*
    Purpose: Sets the number for the laminate layup layer.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The laminate layup layer handle.
        number - The number.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechshlproplamlayuplayerAlloc (ProMechShlpropLamLayupLayer* data);
/*
    Purpose: Allocates the memory for a Creo Simulate laminate layup layer data 
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

PRO_END_C_DECLS

#endif /* PROMECHSHELLPROPS_H */
