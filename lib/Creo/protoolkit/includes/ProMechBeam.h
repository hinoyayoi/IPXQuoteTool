#ifndef PROMECHBEAM_H
#define PROMECHBEAM_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechGeomref.h>
#include <ProMechYDirection.h>

PRO_BEGIN_C_DECLS

typedef struct pro_beam_prop_beam* ProMechBeamData;  
typedef struct pro_beam_prop_truss* ProMechTrussData; 
typedef struct pro_beam_prop_side* ProMechBeamSide;

typedef enum
{
  PRO_MECH_BEAM_BEAM  = 0,
  PRO_MECH_BEAM_TRUSS = 1
} ProMechBeamType;

extern ProError ProMechbeamReferencesGet (ProMechItem* item,
                                ProMechGeomref** references);
/*
        Purpose: Obtains the beam references.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam.

        Output Arguments:
                references      - ProArray of beam entities. The function allocates 
                                  memory for this argument. Use ProMechgeomrefProarrayFree() to 
                                  free it.
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamMaterialGet (ProMechItem* item,
                                ProName name);
/*
        Purpose: Obtains the name of the material for the beam.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam.

        Output Arguments:
                name    - The material name.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamMaterialIdGet (ProMechItem* item,
                int* matl_id);
/*
        Purpose: Obtains the id of the material for the beam.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam.

        Output Arguments:
                matl_id - The material id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamTypeGet (ProMechItem* item,
                                ProMechBeamType* value);
/*
        Purpose: Obtains the type of beam.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam.

        Output Arguments:
                value   - The type.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamBeamdataGet (ProMechItem* item,
                                ProMechBeamData* value);
/*
        Purpose: Obtains the beam data from this beam object.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam.

        Output Arguments:
                value   - The beam-related data.   Free this using ProMechbeamdataFree().

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_INVALID_TYPE - This item does not contain this type of data. 

        See Also:
                ProMechbeamTypeGet()
*/

extern ProError  ProMechbeamTrussdataGet (ProMechItem* item,
                                ProMechTrussData* value);
/*
        Purpose: Obtains the truss data from this beam object.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                item    - The beam.

        Output Arguments:
                value   - The truss-related data.  Free this using ProMechtrussdataFree().

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_INVALID_TYPE - This item does not contain this type of data. 

        See Also:
                ProMechbeamTypeGet()
*/

extern ProError  ProMechbeamdataYdirectionGet (ProMechBeamData data,
                                ProMechYDirection* y_dir);
/*
        Purpose: Obtains the beam Orientation handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments: 
            data    - The beam data

        Output Arguments:
            y_dir   - The Orientation handle.  Free this using ProMechydirectionFree(),
     
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechbeamdataSidesGet (ProMechBeamData data,
                                ProMechBeamSide** sides);
/*
        Purpose: Obtains the two sides of the beam data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam data.

        Output Arguments:
                sides   - ProArray of beam sides. The function allocates memory for 
                          this argument. Use ProMechbeamsideProarrayFree to free it.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechbeamdataXyshearGet (ProMechBeamData data,
                                double* shear_rel_xy);
/*
        Purpose: Obtains the shear relative to the XY plane.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam data

        Output Arguments:
                shear_rel_xy    - the shear value.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamdataXzshearGet (ProMechBeamData data,
                                double* shear_rel_xz);
/*
        Purpose: Obtains the shear relative to the XZ plane.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam data

        Output Arguments:
                shear_rel_xz    - the shear value.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamdataStressrecoveryGet (ProMechBeamData data,
                                ProBoolean* value);
/*
        Purpose: Obtains whether or not Creo Simulate will include beam stress recovery points in analyses (FEM mode only). 

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam data

        Output Arguments:
                value   - The stress recovery flag for the beam.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamdataCompcrvrelGet (ProMechBeamData data,
                                ProBoolean* value);
/*
        Purpose: Obtains whether the beam releases are applied to the ends of the 
            individual segments of the selected composite curves (PRO_B_TRUE)
            or only to the ends of the composite curves themselves (PRO_B_FALSE).

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam data

        Output Arguments:
                value   - The composite curve release flag for the beam.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamdataFree (ProMechBeamData data);
/*
        Purpose: Frees the memory for a Creo Simulate beam data handle.

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

extern ProError  ProMechbeamsideSectionGet (ProMechBeamSide handle,
                                int* section);
/*
        Purpose: Obtains the beam section id for this beam side.

        Licensing Requirement:
          TOOLKIT for Mechanica


        Input Arguments:
                handle  - The beam side.

        Output Arguments:
                section - The beam section id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamsideOrientGet (ProMechBeamSide handle,
                                int* orient);
/*
        Purpose: Obtains the beam orientation id for this beam side.

        Licensing Requirement:
          TOOLKIT for Mechanica


        Input Arguments:
                handle  - The beam side.

        Output Arguments:
                orient  - The beam orientation id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamsideReleaseGet (ProMechBeamSide handle,
                                int* release);
/*
        Purpose: Obtains the beam release id for this beam side.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                handle  - The beam side.

        Output Arguments:
                release - The beam release id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamsideFree (ProMechBeamSide handle);
/*
        Purpose: Frees the memory for a Creo Simulate beam side handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                handle  - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamsideProarrayFree (ProMechBeamSide* handle);
/*
        Purpose: Frees the memory for a ProArray of Creo Simulate beam side handles.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                handle  - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtrussdataSectionGet (ProMechTrussData data,
                                int* section);
/*
        Purpose: Obtains the beam section id for the truss data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The truss data.

        Output Arguments:
                section - The beam section id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechtrussdataFree (ProMechTrussData data);
/*
        Purpose: Frees the memory for a Creo Simulate truss data handle.

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

extern ProError ProMechbeamReferencesSet (ProMechItem* item, ProMechGeomref* references);
/*
        Purpose: Sets the beam references.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            item - The beam.
            references - ProArray of beam entities.
    
        Output Arguments:
            none
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechbeamMaterialIdSet (ProMechItem* item, int matl_id);
/*
        Purpose: Sets the beam material id into this beam object.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            item - The beam.
            matl_id - The material id.
    
        Output Arguments:
            none
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechbeamBeamdataSet (ProMechItem* item, ProMechBeamData data);
/*
        Purpose: Sets the beam data from this beam object.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            item - The beam.
            data - The beam data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
                PRO_TK_CANT_WRITE - Subtype cannot be changed.
*/

extern ProError ProMechbeamTrussdataSet (ProMechItem* item, ProMechTrussData data);
/*
        Purpose: Sets the truss data from this beam object.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            item - The beam.
            data - The beam truss data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
                PRO_TK_CANT_WRITE - Subtype cannot be changed.
*/

extern ProError ProMechbeamdataYdirectionSet (ProMechBeamData data, ProMechYDirection y_dir);
/*
        Purpose: Sets the beam Orientation handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam data
            y_dir - The Orientation handle.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamdataSidesSet (ProMechBeamData data, ProMechBeamSide* sides);
/*
        Purpose: Sets the two sides of the beam data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam data.
            sides - ProArray of beam sides. 

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamdataXyshearSet (ProMechBeamData data, double shear_rel_xy);
/*
        Purpose: Sets the shear relative to the XY plane.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam data
            shear_rel_xy - the shear value.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamdataXzshearSet (ProMechBeamData data, double shear_rel_xz);
/*
        Purpose: Sets the shear relative to the XZ plane.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam data
            shear_rel_xz - the shear value.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamdataStressrecoverySet (ProMechBeamData data, ProBoolean value);
/*
        Purpose: Sets whether or not Creo Simulate will include beam stress recovery points 
                 in analyses (FEM mode only).
    
        Licensing Requirement:
          TOOLKIT for Mechanica
    
        Input Arguments:
            data - The beam data
            value - ???
    
        Output Arguments:
            none
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechbeamdataCompcrvrelSet (ProMechBeamData data,
                                ProBoolean value);
/*
        Purpose: Sets whether the beam releases are applied to the ends of the 
                individual segments of the selected composite curves (PRO_B_TRUE)
                or only to the ends of the composite curves themselves (PRO_B_FALSE).

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The beam data
                value   - The composite curve release flag for the beam.

        Output Arguments:
        none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamdataAlloc ( ProMechBeamData* data);
/*
        Purpose: Allocates the memory for a Creo Simulate beam data handle.

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

extern ProError ProMechbeamsideSectionSet (ProMechBeamSide handle, int section);
/*
        Purpose: Sets the beam section id for this beam side.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            handle - The beam side.
            section - The beam section id.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamsideOrientSet (ProMechBeamSide handle, int orient);
/*
        Purpose: Sets the beam orientation id for this beam side.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            handle - The beam side.
            orient - The beam orientation id.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamsideReleaseSet (ProMechBeamSide handle, int release);
/*
        Purpose: Sets the beam release id for this beam side.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            handle - The beam side.
            release - The beam release id.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechbeamsideAlloc (ProMechBeamSide* handle);
/*
        Purpose: Allocates the memory for a Creo Simulate beam side handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            handle - The handle.
    
        Output Arguments:
            none
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechtrussdataSectionSet (ProMechTrussData data, int section);
/*
        Purpose: Sets the beam section id for the truss data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The truss data.
            section - The beam section id.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechtrussdataAlloc (ProMechTrussData* data);
/*
        Purpose: Allocates the memory for a Creo Simulate truss data handle.

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
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/


PRO_END_C_DECLS

#endif /* PROMECHBEAM_H */
