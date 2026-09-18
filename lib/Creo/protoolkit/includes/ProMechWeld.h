#ifndef PROMECHWELD_H
#define PROMECHWELD_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_WELD_MTL_BASE    = -2,
  PRO_MECH_WELD_MTL_DOUBLER = -3
}
ProMechWeldSplMat;

typedef enum
{
  PRO_MECH_WELD_NONE       = PRO_VALUE_UNUSED,

  PRO_MECH_WELD_PERIMETER  = 0,
  PRO_MECH_WELD_END        = 1,
  PRO_MECH_WELD_SPOT       = 2,
  PRO_MECH_WELD_FEAT       = 3
}
ProMechWeldType;

typedef enum
{
  PRO_MECH_WELD_END_NONE             = PRO_VALUE_UNUSED,

  PRO_MECH_WELD_END_SINGLE_TO_SINGLE = 0,
  PRO_MECH_WELD_END_MANY_TO_SINGLE   = 1,
  PRO_MECH_WELD_END_SINGLE_TO_MANY   = 2
}
ProMechWeldEndType;

typedef struct pro_sim_weld_perimeter* ProMechWeldPerimeter;
typedef struct pro_sim_weld_edgedata*  ProMechWeldEdgeData;
typedef struct pro_sim_weld_spot*      ProMechWeldSpot;
typedef struct pro_sim_weld_end*       ProMechWeldEnd;
typedef struct pro_sim_weld_feature*   ProMechWeldFeature;


extern ProError  ProMechweldReferencesGet (ProMechItem* item,
				ProMechGeomref** references);
/*
	Purpose: Obtains the references used by this weld.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The weld.

	Output Arguments:
		references	- ProArray of references.  Free this using
		                  ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldTypeGet (ProMechItem* item,
				ProMechWeldType* type);
/*
	Purpose: Obtains the type of the weld.

	Input Arguments:
		item	- The weld.

	Output Arguments:
		type	- The type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldendTypeGet (ProMechWeldEnd data,
				ProMechWeldEndType* type);
/*
	Purpose: Obtains the type of the end weld.

	Input Arguments:
		data	- The end weld.

	Output Arguments:
		type	- The type.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldendExtendAdjacentSurfacesGet (ProMechWeldEnd data,
				ProBool* flag);
/*
	Purpose: Obtains the "Extend Adjacent Surfaces" flag of the end weld.

	Input Arguments:
		data	- The end weld.

	Output Arguments:
		flag	- The flag.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError ProMechweldEnddataGet (ProMechItem* item,
				ProMechWeldEnd* data);
/*
	Purpose: Obtains the end data for the weld.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The weld.

	Output Arguments:
		data	- The data.  Free this using ProMechweldEndFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - The weld does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
                PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechweldPerimeterdataGet (ProMechItem* item,
				ProMechWeldPerimeter* data);
/*
	Purpose: Obtains the perimeter data for the weld.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The weld.

	Output Arguments:
		data	- The data.  Free this using ProMechweldperimeterFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - The weld does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
                PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

	See Also:
	        ProMechweldTypeGet()
*/

extern ProError  ProMechweldperimeterEdgesGet (ProMechWeldPerimeter data,
				ProMechWeldEdgeData** edges);
/*
	Purpose: Obtains the edges in the perimeter weld data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The mesh control data.

	Output Arguments:
		edges	- ProArray of edges.  Free this using
		          ProMechweldedgeProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
                PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechweldendFree (ProMechWeldEnd data);
/*
	Purpose: Frees the memory for a Creo Simulate end weld data handle.

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldperimeterFree (ProMechWeldPerimeter data);
/*
	Purpose: Frees the memory for a Creo Simulate perimeter weld data handle.

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldedgeEdgeGet (ProMechWeldEdgeData data,
				int* edge_id);
/*
	Purpose: Obtains the edge id for this data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The weld edge data.

	Output Arguments:
		edge_id	- The id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldedgeThicknessGet (ProMechWeldEdgeData data,
				ProMechExpression thickness);
/*
	Purpose: Obtains the thickness for the weld edge data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The weld edge data.

	Output Arguments:
		thickness	- The thickness.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldedgeMaterialidGet (ProMechWeldEdgeData data,
                                               int* matl_id);
/*
        Purpose: Obtains the material id for the weld edge data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The weld edge data.

        Output Arguments:
                matl_id - The material id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldedgeFree (ProMechWeldEdgeData data);
/*
	Purpose: Frees the memory for a Creo Simulate  weld edge data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldedgeProarrayFree (ProMechWeldEdgeData* data);
/*
	Purpose: Frees the memory for a Creo Simulate  weld edge data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldSpotdataGet (ProMechItem* item,
  				 ProMechWeldSpot* data);
/*
	Purpose: Obtains the data for the spot weld.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The weld.

	Output Arguments:
		data	- The data.  Free this using ProMechweldspotFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - The weld does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
                PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

	See Also:
	        ProMechweldTypeGet()
*/

extern ProError  ProMechweldspotPointsGet (ProMechWeldSpot data,
                                           ProMechGeomref  ** references);
/*
	Purpose: Obtains the points in the Spot weld data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The spot weld data.

	Output Arguments:
		references	- ProArray of points.  Free this using
                      ProMechgeomrefProarrayFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
                PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.
*/

extern ProError  ProMechweldspotFree (ProMechWeldSpot data);
/*
	Purpose: Frees the memory for a Creo Simulate spot weld data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldspotDiameterGet (ProMechWeldSpot data,
		  		 ProMechExpression diameter);
/*
	Purpose: Obtains the diameter for the spot weld data.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The spot weld data.

	Output Arguments:
		diameter	- The diameter.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldspotMaterialIdGet (ProMechWeldSpot data,
		  		 int* matl_id);
/*
	Purpose: Obtains the material id for the spot weld data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The spot weld data.

	Output Arguments:
		matl_id	- The material id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldFeaturedataGet (ProMechItem* item,
  				 ProMechWeldFeature* data);
/*
	Purpose: Obtains the data for the feature weld.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		item	- The weld.

	Output Arguments:
		data	- The data.  Free this using ProMechweldfeatureFree().

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - The weld does not contain this type of data.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
                PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate data.

	See Also:
	        ProMechweldTypeGet()
*/

extern ProError  ProMechweldfeatureOverrideflagGet (ProMechWeldFeature data,
                                                    ProBoolean * override_flag);
/*
	Purpose: Obtains the Override flag in the Feature weld data.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The Feature weld data.

	Output Arguments:
                override_flag - PRO_B_TRUE to Override settings,
                                PRO_B_FALSE otherwise.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldfeatureFree (ProMechWeldFeature data);
/*
	Purpose: Frees the memory for a Creo Simulate feature weld data handle.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
*/

extern ProError  ProMechweldfeatureThicknessGet (ProMechWeldFeature data,
		  		 ProMechExpression thickness);
/*
	Purpose: Obtains the thickness for the feature weld data if
                 override flag is true.
                 Use ProMathExpressionEvaluate() to evaluate it.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The feature weld data.

	Output Arguments:
		thickness	- The thickness.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldfeatureMaterialidGet (ProMechWeldFeature data,
		  		 int* matl_id);
/*
	Purpose: Obtains the material id for the feature weld data if
                 override flag is true.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		data	- The feature weld data.

	Output Arguments:
		matl_id	- The material id.

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
    Purpose: Sets the references used by this weld.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The weld.
        references - ProArray of references.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Object can't be accessed in current mode.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/

extern ProError ProMechweldendTypeSet (ProMechWeldEnd data, ProMechWeldEndType type);
/*
    Purpose: Sets the type of the End Weld.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        type - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.

*/

extern ProError ProMechweldendExtendAdjacentSurfacesSet (ProMechWeldEnd data,
                                                         ProBool flag);
/*
    Purpose: Sets the "Extend Adjacent Surfaces" flag for the end weld

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The data.
        flag - The flag.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.

*/

extern ProError ProMechweldEnddataSet (ProMechItem* item, ProMechWeldEnd data);
/*
    Purpose: Sets the end data for the weld.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The weld.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_CANT_ACCESS - Object can't be accessed in current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldPerimeterdataSet (ProMechItem* item, ProMechWeldPerimeter data);
/*
    Purpose: Sets the perimeter data for the weld.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The weld.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Object can't be accessed in current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldperimeterEdgesSet (ProMechWeldPerimeter data, ProMechWeldEdgeData* edges);
/*
    Purpose: Sets the edges in the perimeter weld data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The mesh control data.
        edges - ProArray of edges.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldendAlloc (ProMechWeldEnd* data);
/*
    Purpose: Allocates the memory for a Creo Simulate end weld data
             handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate the handle.
*/

extern ProError ProMechweldperimeterAlloc (ProMechWeldPerimeter* data);
/*
    Purpose: Allocates the memory for a Creo Simulate perimeter weld data
             handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate the handle.
*/

extern ProError ProMechweldedgeEdgeSet (ProMechWeldEdgeData data, int edge_id);
/*
    Purpose: Sets the edge id for this data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The weld edge data.
        edge_id - The id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldedgeThicknessSet (ProMechWeldEdgeData data, ProMechExpression thickness);
/*
    Purpose: Sets the thickness for the weld edge data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The weld edge data.
        thickness - The thickness.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldedgeMaterialidSet (ProMechWeldEdgeData data,
                                              int                 matl_id);
/*
        Purpose: Assigns the material for the weld edge data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The weld edge data.
        matl_id - The material id.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechweldedgeAlloc (ProMechWeldEdgeData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate  weld edge data handle.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate the handle.
*/

extern ProError  ProMechweldSpotdataSet (ProMechItem     * item,
                                         ProMechWeldSpot   data);

/*
        Purpose: Assigns the data for the spot weld.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The weld.
                 data    - The data.

        Output Arguments:
                 none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_CANT_ACCESS - Object can't be accessed in current mode.
                PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
        See Also:
                ProMechweldTypeGet()
*/

extern ProError ProMechweldspotAlloc (ProMechWeldSpot* data);

/*
    Purpose: Allocates the memory for a Creo Simulate weld spot.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - Input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_OUT_OF_MEMORY - Not enough memory to allocate the handle.
*/


extern ProError ProMechweldspotPntsSet (ProMechWeldSpot   data,
                                        ProMechGeomref  * references);

/*
        Purpose: Assigns the points in the Spot weld data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The spot weld data.
                references      - ProArray of points.

        Output Arguments:
                 none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldspotDiameterSet (ProMechWeldSpot   data,
                                      ProMechExpression diameter);

/*
        Purpose: Assigns the diameter for the spot weld data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The spot weld data.
                diameter        - The diameter.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldspotMaterialIdSet (ProMechWeldSpot   data,
                                               int               matl_id);

/*
        Purpose: Assigns the material for the spot weld data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The spot weld data.
                matl_id - The material id.

        Output Arguments:
                none
                
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldFeaturedataSet (ProMechItem     * item,
                                         ProMechWeldFeature   data);
                                  
/*
        Purpose: Assigns the data for the feature weld.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The weld.
                data    - The data.

        Output Arguments:
                 none 
                 
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_CANT_ACCESS - Object can't be accessed in current mode.
                PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.  
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.

        See Also:
                ProMechweldTypeGet()
*/

extern ProError ProMechweldfeatureAlloc (ProMechWeldFeature* data);

/*
    Purpose: Allocates the memory for a Creo Simulate weld feature.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        none

    Output Arguments:
        data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - Input arguments was invalid.

*/                                  


extern ProError ProMechweldfeatureOverrideflagSet (ProMechWeldFeature   data,
                                                   ProBoolean override_flag);
                                  
/*
        Purpose: Sets the Override flag in the Feature weld data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The feature weld data.
                override_flag - PRO_B_TRUE to override flag,
                                PRO_B_FALSE otherwise (default).

        Output Arguments:
                 none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/
                                  
extern ProError  ProMechweldfeatureThicknessSet (ProMechWeldFeature  data,
                                                 ProMechExpression thickness);
/*
        Purpose: Assigns the thickness to the feature weld data if
                 override flag is true.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The feature weld data.
                thickness - The thickness.

        Output Arguments:
                none
                
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/
                                      
extern ProError  ProMechweldfeatureMaterialidSet (ProMechWeldFeature   data,
                                                  int               matl_id);
/*
        Purpose: Assigns the material for the feature weld data if
                 override flag is true.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The feature weld data.
                matl_id - The material id.

        Output Arguments:
                none
                
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
                PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechweldendSet (ProMechItem* item);
/*
    Purpose: Sets the weld end.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The weld.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Object can't be accessed in current mode.
        PRO_TK_CANT_WRITE - Subtype of item is not allowed to change.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/
PRO_END_C_DECLS

#endif /* PROMECHWELD_H */
