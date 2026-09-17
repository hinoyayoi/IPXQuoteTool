#ifndef PROMECHMESHCONTROL_H
#define PROMECHMESHCONTROL_H


#include <ProToolkit.h>
#include <ProObjects.h>

#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_MC_MAX_ELEMENT_SIZE      = 0,
  PRO_MECH_MC_MIN_ELEMENT_SIZE      = 1, 
  PRO_MECH_MC_EDGE_DISTRIBUTION     = 2,
  PRO_MECH_MC_HARD_POINT            = 3,
  PRO_MECH_MC_HARD_CURVE            = 4,  /* No data, only references. */
  PRO_MECH_MC_MESH_NUMBERING        = 6,
  PRO_MECH_MC_DISPL_CSYS            = 7,
  PRO_MECH_MC_SUPPRESS              = 8,
  PRO_MECH_MC_IDS_OFFSET            = 9,
  PRO_MECH_MC_SHELL_CSYS            = 10,
  PRO_MECH_MC_AGEM_EDGE_DISTR       = 11,
  PRO_MECH_MC_AGEM_MIN_EDGE         = 12,
  PRO_MECH_MC_AGEM_ISOLATE_EXCLUDE  = 13,
  PRO_MECH_MC_AGEM_MAX_ELEMENT_SIZE = 14,
  PRO_MECH_MC_AGEM_EDGE_LEN_CRV     = 15,
  PRO_MECH_MC_AGEM_HARD_POINT       = 16,  /* No data, only references. */
  PRO_MECH_MC_AGEM_HARD_CURVE       = 17,  /* No data, only references. */
  PRO_MECH_MC_AGEM_SUPPRESS         = 18,

  PRO_MECH_MC_ALL                   = 50  /* Use in PRO_MC_SUPPRESS data only */
} ProMechMeshCntrlType;


typedef enum
{
  PRO_MECH_MC_SHELL_CS_DIR_NONE = PRO_VALUE_UNUSED,

  PRO_MECH_MC_SHELL_CS_DIR_1    = 0,
  PRO_MECH_MC_SHELL_CS_DIR_2    = 1,
  PRO_MECH_MC_SHELL_CS_DIR_3    = 2
} ProMechMCShellCsysDir;

typedef struct pro_mc_elem_size* ProMechMCElemSizeData;
typedef struct pro_mc_edge_distr* ProMechMCEdgeDistrData;
typedef struct pro_mc_hard_pnt* ProMechMCHardPntData;
typedef struct pro_mc_numbering* ProMechMCNumberingData;
typedef struct pro_mc_disp_csys* ProMechMCDisplacementCsysData;
typedef struct pro_mc_suppress* ProMechMCSuppressData;
typedef struct pro_mc_ids_offset* ProMechMCIdsOffsetData;
typedef struct pro_mc_shell_csys* ProMechMCShellCsysData;
typedef struct pro_mc_edge_distr* ProMechMCAutogemEdgeDistrData;
typedef struct pro_mc_min_edge* ProMechMCAutogemMinEdgeData;
typedef struct pro_mc_elem_size* ProMechMCAutogemElemSizeData;
typedef struct pro_mc_edge_len_by_crv* ProMechMCAutogemEdgeLenCrvData;



extern ProError  ProMechmeshcntrlReferencesGet (ProMechItem* item,
				ProMechGeomref** references);
/*
	Purpose: Obtains the references used by this mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		references	- ProArray of references.  Free this using 
		                  ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is
                                     invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform
                                       the operation.
*/

extern ProError  ProMechmeshcntrlTypeGet (ProMechItem* item,
				ProMechMeshCntrlType* type);
/*
	Purpose: Obtains the type of the mesh control.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		type	- The type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is
                                     invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechmeshcntrlElemsizedataGet (ProMechItem* item,
				ProMechMCElemSizeData* data);
/*
	Purpose: Obtains the elem size data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcelemsizeFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of
                                      data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is
                                     invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlEdgedistrdataGet (ProMechItem* item,
				ProMechMCEdgeDistrData* data);
/*
	Purpose: Obtains the edge distribution data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcedgedistrFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of
                                      data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is
                                     invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlHardpointGet (ProMechItem* item,
				ProMechMCHardPntData* data);
/*
	Purpose: Obtains the hard point data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmchardpntFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of
                                      data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is
                                     invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlNumberingGet (ProMechItem* item,
				ProMechMCNumberingData* data);
/*
	Purpose: Obtains the numbering data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcnumberingFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of
                                      data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is
                                     invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/


extern ProError  ProMechmeshcntrlDisplacementcsysGet (ProMechItem* item,
                                ProMechMCDisplacementCsysData* data);
/*
        Purpose: Obtains the displacement csys data for the mesh control item.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The mesh control item.

        Output Arguments:
                data    - The data.  Free this using ProMechmcdisplacementcsysFree()

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_INVALID_TYPE - This item does not contain this type of data.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
               ProMechmeshcntrlTypeGet()
*/


extern ProError  ProMechmeshcntrlSuppressGet (ProMechItem* item,
				ProMechMCSuppressData* data);
/*
	Purpose: Obtains the suppress data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcsuppressFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

    See Also:
	    ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlIdsoffsetGet (ProMechItem* item,
				ProMechMCIdsOffsetData* data);
/*
	Purpose: Obtains the offset ids data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcidsoffsetFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlShellcsysGet (ProMechItem* item,
				ProMechMCShellCsysData* data);
/*
	Purpose: Obtains the shell csys data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcshellcsysFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlAutogemedgedistrdataGet (ProMechItem* item,
				ProMechMCAutogemEdgeDistrData* data);
/*
	Purpose: Obtains the AutoGEM edge distribution data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcautogemedgedistrFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/


extern ProError  ProMechmeshcntrlAutogemminedgedataGet (ProMechItem* item,
				ProMechMCAutogemMinEdgeData* data);
/*
	Purpose: Obtains the AutoGEM min edge data for the mesh control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The mesh control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcautogemminedgeFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlAutogemedgelencrvdataGet (ProMechItem* item,
				ProMechMCAutogemEdgeLenCrvData* data);
/*
    Purpose: Obtains the AutoGEM edge length by curvature data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item  - The mesh control item.

    Output Arguments:
        data  - The data.  Free this using ProMechmcautogemedgelencrvFree()

    Return Values:
	    PRO_TK_NO_ERROR - The function succeeded.
	    PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
	    PRO_TK_INVALID_TYPE - This item does not contain this type of data.
	    PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
	    PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
	    PRO_TK_GENERAL_ERROR - A general error is encountered.
	    PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                   operation.

    See Also:
        ProMechmeshcntrlTypeGet()
        ProMechmcautogemedgelencrvRatioGet()
        ProMechmcautogemedgelencrvMinradiusGet()
        ProMechmcautogemedgelencrvIgnoreRadiusGet()
*/


extern ProError  ProMechmcelemsizeSizeGet (ProMechMCElemSizeData data,
				ProMechExpression size);
/*
	Purpose: Obtains the size of the elements for the mesh control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		size	- The element size.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcelemsizeFree (ProMechMCElemSizeData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control elem size data handle.

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

extern ProError  ProMechmcedgedistrNodesGet (ProMechMCEdgeDistrData data,
				int* num_nodes);
/*
	Purpose: Obtains the number of nodes for the mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		num_nodes	- The number of nodes. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcedgedistrRatioGet (ProMechMCEdgeDistrData data,
				ProMechExpression ratio);
/*
	Purpose: Obtains the ratio for the mesh control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		ratio	- The ratio. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcedgedistrStrictGet (ProMechMCEdgeDistrData data,
				ProBoolean* strict);
/*
	Purpose: Obtains whether or not to prevent additional nodes for the mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		strict	- "PRO_B_TRUE if the ratio is strict, PRO_B_FALSE otherwise." 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcedgedistrFree (ProMechMCEdgeDistrData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control edge distribution data handle.

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

extern ProError  ProMechmchardpntNodeGet (ProMechMCHardPntData data,
				int* node_id);
/*
	Purpose: Obtains the node id for the mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		node_id	- The node id. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmchardpntFree (ProMechMCHardPntData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control hard point data handle.

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

extern ProError  ProMechmcnumberingFirstGet (ProMechMCNumberingData data,
				int* first);
/*
	Purpose: Obtains the first value for the mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		first	- The first value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcnumberingIncrementGet (ProMechMCNumberingData data,
				int* increment);
/*
	Purpose: Obtains the increment value for the mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		increment	- The increment value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcnumberingLastGet (ProMechMCNumberingData data,
				int* last);
/*
	Purpose: Obtains the last value for the mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		last	- The last value. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcnumberingFree (ProMechMCNumberingData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control numbering data handle.

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

extern ProError  ProMechmcdisplacementcsysCsysGet (ProMechMCDisplacementCsysData data,
                                ProMechGeomref* csys);
/*
        Purpose: Obtains the csys for the mesh control data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The mesh control data.

        Output Arguments:
                csys    - The csys. Free this using ProMechgeomrefFree()

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the 
                                       operation.
*/


extern ProError  ProMechmcdisplacementcsysFree (ProMechMCDisplacementCsysData data);
/*
        Purpose: Frees the memory for a Creo Simulate mesh control displacement csys data handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/


extern ProError  ProMechmcsuppressTypeGet (ProMechMCSuppressData data,
				ProMechMeshCntrlType* suppress);
/*
	Purpose: Obtains the types of mesh control suppressed by this mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		suppress	- The types. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
	   ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmcsuppressFree (ProMechMCSuppressData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control suppress data handle.

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

extern ProError  ProMechmcidsoffsetOffsetGet (ProMechMCIdsOffsetData data,
				int* offset);
/*
	Purpose: Obtains the offset for this mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		offset	- The offset. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcidsoffsetFree (ProMechMCIdsOffsetData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control ids offset data handle.

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

extern ProError  ProMechmcshellcsysCsysGet (ProMechMCShellCsysData data,
				ProMechGeomref* csys);
/*
	Purpose: Obtains the csys for this mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		csys	- The csys. Free this using ProMechgeomrefFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.
*/

extern ProError  ProMechmcshellcsysDirectionGet (ProMechMCShellCsysData data,
				ProMechMCShellCsysDir* direction);
/*
	Purpose: Obtains the direction for this mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		direction	- The direction. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcshellcsysFree (ProMechMCShellCsysData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control shell csys data handle.

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

extern ProError  ProMechmcautogemedgedistrNodesGet (ProMechMCAutogemEdgeDistrData data,
				int* num_nodes);
/*
	Purpose: Obtains the number of nodes for the AutoGEM edge distribution mesh control
                 data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM edge distribution mesh control data.

	Output Arguments:
		num_nodes	- The number of nodes. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgedistrRatioGet (ProMechMCAutogemEdgeDistrData data,
				ProMechExpression ratio);
/*
	Purpose: Obtains the ratio for the AutoGEM edge distribution mesh control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM edge distribution mesh control data.

	Output Arguments:
		ratio	- The ratio. 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgedistrStrictGet (ProMechMCAutogemEdgeDistrData data,
				ProBoolean* strict);
/*
	Purpose: Obtains whether or not the ratio is strict for the AutoGEM edge distribution
                 mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM edge distribution mesh control data.

	Output Arguments:
		strict	- "PRO_B_TRUE if the ratio is strict, PRO_B_FALSE otherwise." 
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgedistrFree (ProMechMCAutogemEdgeDistrData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control edge distribution data handle.

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


extern ProError  ProMechmcautogemminedgeLengthGet (ProMechMCAutogemMinEdgeData data,
						   ProMechExpression edge_length, 
						   ProBoolean* is_percent);
/*
	Purpose: Obtains the minimum length of the edge for the AutoGEM min edge mesh
                 control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM min edge  mesh control data.

	Output Arguments:
		edge_length	- The edge length.
		is_percent      - PRO_B_TRUE if the expression is a percentage,
		                  PRO_B_FALSE if it represents a true 
				  measurement.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemminedgeEdgesGet (ProMechMCAutogemMinEdgeData data,
				ProMechGeomref** edges);
/*
	Purpose: Obtains the edges for the AutoGEM min edge  mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM min edge  mesh control data.

	Output Arguments:
		edges   - ProArray of edges.  Free this using 
		          ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_E_NOT_FOUND - No edges were found.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.
*/

extern ProError  ProMechmcautogemminedgeFree (ProMechMCAutogemMinEdgeData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control min edge  data handle.

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

extern ProError  ProMechmcautogemedgelencrvRatioGet (ProMechMCAutogemEdgeLenCrvData data,
				ProMechExpression crv_ratio);
/*
    Purpose: Obtains the edge length to radius of curvature ratio for the AutoGEM 
             edge length by curvature mesh control data.
             Use ProMathExpressionEvaluate() to evaluate it.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data  - The AutoGEM edge length by curvature mesh control data.

    Output Arguments:
        crv_ratio  - The ratio of edge length to radius of curvature. 

    Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgelencrvIgnoreRadiusGet (ProMechMCAutogemEdgeLenCrvData data,
                ProBoolean *ignore_roc_below);
/*
	Purpose: Obtains whether or not to ignore radius of curvature below a user input
                 value for the AutoGEM edge length by curvature mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data  - The AutoGEM edge length by curvature data.

	Output Arguments:
	        ignore_roc_below - PRO_B_TRUE if radius of curvature below a
                                   user input value is to be ignored.
                                   PRO_B_FALSE if radius of curvature is not to
                                   be ignored.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgelencrvMinradiusGet (ProMechMCAutogemEdgeLenCrvData data,
				ProMechExpression min_crv_radius,
                                ProBoolean *is_percent);
/*
	Purpose: Obtains the value of the minimum cutoff radius for the AutoGEM 
                 edge length by curvature mesh control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data  - The AutoGEM edge length by curvature mesh control data.

	Output Arguments:
                min_crv_radius - The cutoff value for local radius of curvature
                                 below which the mesh control will not be applied. 
                is_percent     - PRO_B_TRUE represents the expression as a
                                 percentage of model size.
		                 PRO_B_FALSE represents a true measurement in
                                 current units.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgelencrvFree (ProMechMCAutogemEdgeLenCrvData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control edge length 
                 by curvature data handle.

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

typedef enum
{
  PRO_MECH_MC_SHELL_ISOL_AUTO    = 0,
  PRO_MECH_MC_SHELL_ISOL_NONE    = 1,
  PRO_MECH_MC_SHELL_ISOL_MAXSIZE = 2
} ProMechMCShlIsolType;

typedef enum
{
  PRO_MECH_MC_SOLID_ISOL_NONE    = 0,
  PRO_MECH_MC_SOLID_ISOL_MAXSIZE = 1
} ProMechMCSldIsolType;

typedef struct pro_mc_prop_isolate_exclude* ProMechMCAutogemIsolateExcludeData;

extern ProError ProMechmeshcntrlReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the references used by this mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mesh control item.
        references - ProArray of references. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlElemsizedataSet (ProMechItem* item,ProMechMeshCntrlType control_type, ProMechMCElemSizeData data);
/*
    Purpose: Sets the elem size data for the mesh control item.
    <B>Note:</B> If you are creating a new mesh control using this type of
                 data, you should assign the model as a reference using the
                 function ProMechmeshcntrlReferencesSet().

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item         - The mesh control item.
        control_type - minimum or maximum element size.
                       (MIN_ELEMENT_SIZE or MAX_ELEMENT_SIZE)
        data         - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_TYPE - This item does not contain this type of data.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlEdgedistrdataSet (ProMechItem* item, ProMechMCEdgeDistrData data);
/*
    Purpose: Sets the edge distribution data for the mesh control item.
    <B>Note:</B> If you are creating a new mesh control using this type of
                 data, you should assign the model as a reference using the
                 function ProMechmeshcntrlReferencesSet().

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlHardpointSet (ProMechItem* item, ProMechMCHardPntData data);
/*
    Purpose: Sets the hard point data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlHardcurveSet (ProMechItem* item);
/*
    Purpose: Sets the mesh control item to be of type hard curve (the reference
             for the item will be used for the control).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
       item - The mesh control item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/


extern ProError ProMechmeshcntrlNumberingSet (ProMechItem* item, ProMechMCNumberingData data);
/*
    Purpose: Sets the numbering data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlDisplacementcsysSet (ProMechItem* item, ProMechMCDisplacementCsysData data);
/*
    Purpose: Sets the displacement csys data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlSuppressSet (ProMechItem* item, ProMechMCSuppressData data);
/*
    Purpose: Sets the suppress data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlIdsoffsetSet (ProMechItem* item, ProMechMCIdsOffsetData data);
/*
    Purpose: Sets the offset ids data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlShellcsysSet (ProMechItem* item, ProMechMCShellCsysData data);
/*
    Purpose: Sets the shell csys data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlAutogemedgedistrdataSet (ProMechItem* item, ProMechMCAutogemEdgeDistrData data);
/*
    Purpose: Sets the AutoGEM edge distribution data for the mesh control item.
    <B>Note:</B> If you are creating a new mesh control using this type of
                 data, you should assign the model as a reference using the
                 function ProMechmeshcntrlReferencesSet().

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlAutogemminedgedataSet (ProMechItem* item, ProMechMCAutogemMinEdgeData data);
/*
    Purpose: Sets the AutoGEM min edge data for the mesh control item.
    <B>Note:</B> If you are creating a new mesh control using this type of
                 data, you should assign the model as a reference using the
                 function ProMechmeshcntrlReferencesSet().

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed. 
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError ProMechmeshcntrlAutogemisolateexcludedataGet 
                              (ProMechItem*                        item,
				               ProMechMCAutogemIsolateExcludeData* data);
/*
	Purpose: Obtains the AutoGEM isolation for exclusion data for the mesh 
                 control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
	    item  - The mesh control item.

	Output Arguments:
	    data  - The data. Free this using ProMechmcautogemisolateexcludeFree()

	Return Values:
	    PRO_TK_NO_ERROR - The function succeeded.
	    PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
	    PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
	    PRO_TK_INVALID_TYPE - This item does not contain this type of data. 
	    PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
	    PRO_TK_GENERAL_ERROR - A general error is encountered.
	    PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                   operation.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError ProMechmeshcntrlAutogemisolateexcludedataSet 
                              (ProMechItem*                        item,
                               ProMechMCAutogemIsolateExcludeData  data);
/*
	Purpose: Sets the AutoGEM isolation for exclusion data for the mesh 
                 control item.
        <B>Note:</B> If you are creating a new mesh control using this type of
                     data, you should assign the model as a reference using the
                     function ProMechmeshcntrlReferencesSet().

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
             item - The mesh control item.
             data - The data.

	Output Arguments:
             None.

	Return Values:
             PRO_TK_NO_ERROR - The function succeeded.
             PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
             PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
             PRO_TK_CANT_WRITE - Subtype cannot be changed. 
             PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
             PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
             PRO_TK_GENERAL_ERROR - A general error is encountered.
             PRO_TK_CANT_MODIFY - Cannot modify the item.

        See Also:
	     ProMechmeshcntrlTypeGet()
*/

extern ProError ProMechmeshcntrlAutogemedgelencrvdataSet (ProMechItem* item, 
                                                          ProMechMCAutogemEdgeLenCrvData data);
/*
    Purpose: Assigns the AutoGEM edge length by curvature data for the mesh control item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The mesh control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed. 
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

    See Also:
        ProMechmcautogemedgelencrvRatioSet()
        ProMechmcautogemedgelencrvMinradiusSet()
        ProMechmcautogemedgelencrvIgnoreRadiusSet()
*/

extern ProError ProMechmcelemsizeSizeSet (ProMechMCElemSizeData data, ProMechExpression size);
/*
    Purpose: Sets the size of the elements for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        size - The element size.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcelemsizeAlloc (ProMechMCElemSizeData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control elem size 
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcedgedistrNodesSet (ProMechMCEdgeDistrData data, int num_nodes);
/*
    Purpose: Sets the number of nodes for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        num_nodes - The number of nodes.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcedgedistrRatioSet (ProMechMCEdgeDistrData data, ProMechExpression ratio);
/*
    Purpose: Sets the ratio for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        ratio - The ratio.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcedgedistrStrictSet (ProMechMCEdgeDistrData data, ProBoolean strict);
/*
    Purpose: Sets whether or not to prevent additional nodes for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        strict - "PRO_B_TRUE if the ratio is strict, PRO_B_FALSE otherwise."

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcedgedistrAlloc (ProMechMCEdgeDistrData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control edge 
             distribution data handle.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmchardpntNodeSet (ProMechMCHardPntData data, int node_id);
/*
    Purpose: Sets the node id for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        node_id - The node id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmchardpntAlloc (ProMechMCHardPntData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control hard point 
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcnumberingFirstSet (ProMechMCNumberingData data, int first);
/*
    Purpose: Sets the first value for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The mesh control data.
        first - The first value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcnumberingIncrementSet (ProMechMCNumberingData data, int increment);
/*
    Purpose: Sets the increment value for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The mesh control data.
        increment - The increment value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcnumberingLastSet (ProMechMCNumberingData data, int last);
/*
    Purpose: Sets the last value for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        last - The last value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcnumberingAlloc (ProMechMCNumberingData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control numbering 
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcdisplacementcsysCsysSet (ProMechMCDisplacementCsysData data, ProMechGeomref csys);
/*
    Purpose: Sets the csys for the mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The mesh control data.
        csys - The csys.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcdisplacementcsysAlloc (ProMechMCDisplacementCsysData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control displacement 
             csys data handle.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcsuppressTypeSet (ProMechMCSuppressData data, ProMechMeshCntrlType suppress);
/*
    Purpose: Sets the type of mesh control suppressed by this mesh control 
             data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The mesh control data.
        suppress - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcsuppressAlloc (ProMechMCSuppressData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control
             suppress data handle.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcidsoffsetOffsetSet (ProMechMCIdsOffsetData data, int offset);
/*
    Purpose: Sets the offset for this mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The mesh control data.
        offset - The offset.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcidsoffsetAlloc (ProMechMCIdsOffsetData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control ids offset 
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcshellcsysCsysSet (ProMechMCShellCsysData data, ProMechGeomref csys);
/*
    Purpose: Sets the csys for this mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        csys - The csys.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcshellcsysDirectionSet (ProMechMCShellCsysData data, ProMechMCShellCsysDir direction);
/*
    Purpose: Sets the direction for this mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The mesh control data.
        direction - The direction.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcshellcsysAlloc (ProMechMCShellCsysData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control shell csys 
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcautogemedgedistrNodesSet (ProMechMCAutogemEdgeDistrData data, int num_nodes);
/*
    Purpose: Sets the number of nodes for the AutoGEM edge distribution mesh 
             control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The AutoGEM edge distribution mesh control data.
        num_nodes - The number of nodes.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemedgedistrRatioSet (ProMechMCAutogemEdgeDistrData data, ProMechExpression ratio);
/*
    Purpose: Sets the ratio for the AutoGEM edge distribution mesh control 
             data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The AutoGEM edge distribution mesh control data.
        ratio - The ratio.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemedgedistrStrictSet (ProMechMCAutogemEdgeDistrData data, ProBoolean strict);
/*
    Purpose: Sets whether or not the ratio is strict for the AutoGEM edge 
             distribution mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The AutoGEM edge distribution mesh control data.
        strict - "PRO_B_TRUE if the ratio is strict, PRO_B_FALSE otherwise."

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemedgedistrAlloc (ProMechMCAutogemEdgeDistrData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control edge 
             distribution data handle.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcautogemminedgeLengthSet (ProMechMCAutogemMinEdgeData data, ProMechExpression edge_length, ProBoolean is_percent);
/*
    Purpose: Sets the minimum length of the edge for the AutoGEM min edge  mesh 
             control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The AutoGEM min edge  mesh control data.
        edge_length - The edge length.
        is_percent - PRO_B_TRUE if the expression is a percentage,              
                         PRO_B_FALSE if it represents a true   measurement.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemminedgeEdgesSet (ProMechMCAutogemMinEdgeData data, ProMechGeomref* edges);
/*
    Purpose: Sets the edges for the AutoGEM min edge mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The AutoGEM min edge  mesh control data.
        edges - ProArray of edges. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcautogemminedgeAlloc (ProMechMCAutogemMinEdgeData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control min edge  
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/


extern ProError  ProMechmcautogemisolateexcludeExcludeGet 
                      (ProMechMCAutogemIsolateExcludeData data,
				       ProBoolean* exclude);
/*
	Purpose: Obtains the value of exclude boolean for the AutoGEM isolation 
                 for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.

	Output Arguments:
		exclude   - value of exclude boolean.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeSolidIsolTypeGet 
                      (ProMechMCAutogemIsolateExcludeData data,
				       ProMechMCSldIsolType* type);
/*
	Purpose: Obtains the value of solid isolation type for the AutoGEM 
                 isolation for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.

	Output Arguments:
		type   - value of solid isolation type. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeSolidIsolMaxSizeGet 
                      (ProMechMCAutogemIsolateExcludeData data,
					   ProMechExpression max_elem_size, 
					   ProBoolean* is_max_elem_percent);
/*
	Purpose: Obtains the value of maximum element size of isolation of solids 
                 for the AutoGEM isolation for exclusion mesh control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.

	Output Arguments:
		max_elem_size	- value of maximum element size of isolation of solids.
		is_max_elem_percent - PRO_B_TRUE if the expression is a percentage,
		                      PRO_B_FALSE if it represents a true measurement.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeShellIsolTypeGet 
                      (ProMechMCAutogemIsolateExcludeData data,
				       ProMechMCShlIsolType* type);
/*
	Purpose: Obtains the value of shell isolation type for the AutoGEM 
                 isolation for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.

	Output Arguments:
		type   - value of shell isolation type. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeShellIsolMaxSizeGet 
                      (ProMechMCAutogemIsolateExcludeData data,
					   ProMechExpression max_elem_size, 
					   ProBoolean* is_max_elem_percent);
/*
	Purpose: Obtains the value of maximum element size of isolation of shells 
                 for the AutoGEM isolation for exclusion mesh control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.

	Output Arguments:
		max_elem_size	- value of maximum element size of isolation of shells.
		is_max_elem_percent - PRO_B_TRUE if the expression is a percentage,
		                      PRO_B_FALSE if it represents a true measurement.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeFree 
                                     (ProMechMCAutogemIsolateExcludeData data);
/*
	Purpose: Frees the memory for a Creo Simulate mesh control isolation for 
                 exclusion data handle.

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

extern ProError  ProMechmcautogemisolateexcludeExcludeSet 
                      (ProMechMCAutogemIsolateExcludeData data,
				       ProBoolean exclude);
/*
	Purpose: Sets the value of exclude boolean for the AutoGEM isolation 
                 for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.
		exclude   - value of exclude boolean.

	Output Arguments:
             None.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeSolidIsolTypeSet 
                      (ProMechMCAutogemIsolateExcludeData data,
				       ProMechMCSldIsolType type);
/*
	Purpose: Sets the value of solid isolation type for the AutoGEM isolation 
                 for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.
		type   - value of solid isolation type. 

	Output Arguments:
                none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeSolidIsolMaxSizeSet 
                      (ProMechMCAutogemIsolateExcludeData data,
					   ProMechExpression max_elem_size, 
					   ProBoolean is_max_elem_percent);
/*
	Purpose: Sets the value of maximum element size of isolation of solids 
                 for the AutoGEM isolation for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.
		max_elem_size	- value of maximum element size of isolation of solids.
		is_max_elem_percent - PRO_B_TRUE if the expression is a percentage,
		                      PRO_B_FALSE if it represents a true measurement.

	Output Arguments:
             none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeShellIsolTypeSet 
                      (ProMechMCAutogemIsolateExcludeData data,
				       ProMechMCShlIsolType type);
/*
	Purpose: Sets the value of shell isolation type for the AutoGEM isolation 
                 for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.
		type   - value of shell isolation type. 

	Output Arguments:
             none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemisolateexcludeShellIsolMaxSizeSet 
                      (ProMechMCAutogemIsolateExcludeData data,
					   ProMechExpression max_elem_size, 
					   ProBoolean is_max_elem_percent);
/*
	Purpose: Sets the value of maximum element size of isolation of shells for 
                 the AutoGEM isolation for exclusion mesh control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM isolation for exclusion mesh control data.
		max_elem_size	- value of maximum element size of isolation of shells.
		is_max_elem_percent - PRO_B_TRUE if the expression is a percentage,
		                      PRO_B_FALSE if it represents a true measurement.

	Output Arguments:
             none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemisolateexcludeAlloc 
                                   (ProMechMCAutogemIsolateExcludeData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control isolation 
             for exclusion data handle.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError  ProMechmeshcntrlAutogemelemsizedataGet (ProMechItem* item,
				ProMechMCAutogemElemSizeData* data);
/*
	Purpose: Obtains the elem size data for the AutoGEM control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
	    item - The AutoGEM control item.

	Output Arguments:
	    data - The data. Free this using ProMechmcelemsizeFree().

	Return Values:
	    PRO_TK_NO_ERROR - The function succeeded.
	    PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
	    PRO_TK_INVALID_TYPE - This item does not contain this type of data.
	    PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
	    PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
	    PRO_TK_GENERAL_ERROR - A general error is encountered.
	    PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                   operation.

        See Also:
	    ProMechmeshcntrlTypeGet()
*/

extern ProError ProMechmeshcntrlAutogemelemsizedataSet (ProMechItem* item, ProMechMCAutogemElemSizeData data);
/*
    Purpose: Sets the elem size data for the AutoGEM control item.
    <B>Note:</B> If you are creating a new mesh control using this type of
                 data, you should assign the model as a reference using the
                 function ProMechmeshcntrlReferencesSet().

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The AutoGEM control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
*/

extern ProError  ProMechmcautogemelemsizeSizeGet (ProMechMCAutogemElemSizeData data, ProMechExpression size);
/*
	Purpose: Obtains the size of the elements for the AutoGEM control data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM control data.

	Output Arguments:
		size	- The element size.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemelemsizeSizeSet (ProMechMCAutogemElemSizeData data, ProMechExpression size);
/*
    Purpose: Sets the size of the elements for the AutoGEM control data.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        data - The AutoGEM control data.
        size - The element size.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemelemsizeAlloc (ProMechMCAutogemElemSizeData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate AutoGEM control elem size 
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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError  ProMechmcautogemelemsizeFree (ProMechMCAutogemElemSizeData data);
/*
	Purpose: Frees the memory for a Creo Simulate AutoGEM control elem size data
                 handle.

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

extern ProError  ProMechmcautogemedgelencrvRatioSet (ProMechMCAutogemEdgeLenCrvData data,
				ProMechExpression crv_ratio);
/*
    Purpose: Sets the value of edge length to radius of curvature ratio for the AutoGEM 
             edge length by curvature mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data      - The AutoGEM edge length by curvature mesh control data.
        crv_ratio - The ratio of edge length to radius of curvature. 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgelencrvIgnoreRadiusSet (ProMechMCAutogemEdgeLenCrvData data,
                                                        ProBoolean ignore_roc_below);
/*
    Purpose: Sets whether or not to ignore radius of curvature below a user input
             value for the AutoGEM edge length by curvature mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data             - The AutoGEM edge length by curvature mesh control data.
        ignore_roc_below - PRO_B_TRUE if radius of curvature below a user input 
                           value is to be ignored.
                           PRO_B_FALSE if radius of curvature is not to be ignored.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemedgelencrvMinradiusSet (ProMechMCAutogemEdgeLenCrvData data,
                                                        ProMechExpression min_crv_radius,
                                                        ProBoolean is_percent);
/*
    Purpose: Sets the value for the minimum cutoff radius for the AutoGEM 
             edge length by curvature mesh control data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data           - The AutoGEM edge length by curvature mesh control data.
        min_crv_radius - The cutoff value for local radius of curvature below which 
                         the mesh control will not be applied.
        is_percent     - PRO_B_TRUE if the expression is a percentage.
                         PRO_B_FALSE if it represents true measurement in current units.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmcautogemedgelencrvAlloc 
                                   (ProMechMCAutogemEdgeLenCrvData * data);
/*
    Purpose: Allocates the memory for a Creo Simulate mesh control edge length 
             by curvature data handle.

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
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                               operation.
*/

extern ProError ProMechmcautogemHardpointSet (ProMechItem* item);
/*
    Purpose: Sets the mesh control item to be of type AutoGEM hard point
             (the reference for the item will be used for the control).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
       item - The mesh control item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_BAD_INPUTS - The input are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_WRITE - Could not modify the given item.
*/

extern ProError ProMechmcautogemHardcurveSet (ProMechItem* item);
/*
    Purpose: Sets the mesh control item to be of type AutoGEM hard curve
             (the reference for the item will be used for the control).

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
       item - The mesh control item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_BAD_INPUTS - The input are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_MODIFY - Cannot modify the item.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_WRITE - Could not modify the given item.
*/

extern ProError ProMechmeshcntrlAutogemsuppressSet (ProMechItem* item,
                                                    ProMechMCSuppressData data);
/*
    Purpose: Sets the suppress data for the AutoGEM control item.

    Licensing Requirement:
          TOOLKIT for Mechanica
    Input Arguments:
        item - The AutoGEM control item.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

        See Also:
	       ProMechmeshcntrlTypeGet()
*/

extern ProError  ProMechmeshcntrlAutogemsuppressGet (ProMechItem* item,
				ProMechMCSuppressData* data);
/*
	Purpose: Obtains the suppress data for the AutoGEM control item.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The AutoGEM control item.

	Output Arguments:
		data	- The data.  Free this using ProMechmcsuppressFree()

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_INVALID_TYPE - This item does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
		PRO_TK_INVALID_PTR - The input ProMechItem solid pointer is invalid.
		PRO_TK_GENERAL_ERROR - A general error is encountered.
		PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the
                                       operation.
*/

extern ProError ProMechmcautogemsuppressTypeSet (ProMechMCSuppressData data,
                                                 ProMechMeshCntrlType suppress);
/*
    Purpose: Sets the type of AutoGEM control suppressed by this AutoGEM control 
             data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The AutoGEM control data.
        suppress - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmcautogemsuppressTypeGet (ProMechMCSuppressData data,
				ProMechMeshCntrlType* suppress);
/*
	Purpose: Obtains the types of AutoGEM control suppressed by this
             AutoGEM control data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The AutoGEM control data.

	Output Arguments:
		suppress	- The types. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

    See Also:
	   ProMechmeshcntrlTypeGet()
*/

PRO_END_C_DECLS

#endif /* PROMECHMESHCONTROL_H */
