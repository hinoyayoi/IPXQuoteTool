#ifndef PROMECHMATERIALORIENT_H
#define PROMECHMATERIALORIENT_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSizeConst.h>

#include <ProMechValue.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_MATLORI_OBJ_NONE = PRO_VALUE_UNUSED,

  PRO_MECH_MATLORI_MODEL    = 1,
  PRO_MECH_MATLORI_SURFACE  = 2
} ProMechMaterialOrientObjType;

typedef enum
{
  PRO_MECH_MATLORI_NONE          = PRO_VALUE_UNUSED,

  PRO_MECH_MATLORI_COORD_SYSTEM  = 1,
  PRO_MECH_MATLORI_1_DIR         = 2,
  PRO_MECH_MATLORI_2_DIR         = 3,
  PRO_MECH_MATLORI_3_DIR         = 4, /* not used */
  PRO_MECH_MATLORI_PROJ_VECTOR   = 5
} ProMechMaterialOrientType;

typedef enum
{
  PRO_MECH_MATLORI_CSYS_PROJ_NONE     = PRO_VALUE_UNUSED,

  PRO_MECH_MATLORI_CSYS_PROJ_CLOSEST  = 0,
  PRO_MECH_MATLORI_CSYS_PROJ_X        = 1,
  PRO_MECH_MATLORI_CSYS_PROJ_Y        = 2,    /* not used for now */
  PRO_MECH_MATLORI_CSYS_PROJ_Z        = 3     /* not used for now */
} ProMechMaterialOrientCsysProjType;

typedef enum
{
  PRO_MECH_MATLORI_PROJ_NONE    = PRO_VALUE_UNUSED,

  PRO_MECH_MATLORI_PROJ_XYZ     = 1,
  PRO_MECH_MATLORI_PROJ_POINTS  = 2
} ProMechMaterialOrientProjType;

typedef struct pro_matlorient_data* ProMechMaterialOrientData;
typedef struct pro_matlorient_csys* ProMechMaterialOrientCsys;
typedef struct pro_matlorient_proj* ProMechMaterialOrientProj;
typedef double ProMechMaterialOrientRotation[3];

typedef enum 
{
  PRO_MECH_MATLORI_CSYS_AXIS_X = 0,
  PRO_MECH_MATLORI_CSYS_AXIS_Y = 1,
  PRO_MECH_MATLORI_CSYS_AXIS_Z = 2
} ProMechMaterialOrientCsysAxis;


extern ProError  ProMechmaterialorientDescriptionGet (ProMechItem* item,
                ProComment description);
/*
    Purpose: Obtains the description of the material orientation object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material orientation.

    Output Arguments:
        description    - The description.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechmaterialorientObjecttypeGet (ProMechItem* item,
                ProMechMaterialOrientObjType* type);
/*
    Purpose: Obtains the type of object for the material orientation object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material orientation.

    Output Arguments:
        type    - The object type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechmaterialorientDataGet (ProMechItem* item,
                ProMechMaterialOrientData* data);
/*
    Purpose: Obtains the data for the material orientation object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item    - The material orientation.

    Output Arguments:
        data    - The data.  Free this using 
                   ProMechmaterialorientdataFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechmaterialorientdataTypeGet (ProMechMaterialOrientData data,
                ProMechMaterialOrientType* type);
/*
    Purpose: Obtains the type of material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation data.

    Output Arguments:
        type    - The material orientation type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmaterialorientdataCsysdataGet (ProMechMaterialOrientData data,
                ProMechMaterialOrientCsys* csys_data);
/*
    Purpose: Obtains the coordinate system orientation data for the material orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation data.

    Output Arguments:
        csys_data    - The csys data.  Free this using 
                          ProMechmaterialorientcsysFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The data does not contain this type of material orientation.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
         
        See Also:
            ProMechmaterialorientdataTypeGet()
*/

extern ProError  ProMechmaterialorientdataProjectiondataGet (ProMechMaterialOrientData data,
                ProMechMaterialOrientProj* proj_data);
/*
    Purpose: Obtains the projection orientation data for the material orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation data.

    Output Arguments:
        proj_data    - The projection data.  Free this using
                          ProMechmaterialorientprojFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The data does not contain this type of material orientation.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
         
        See Also:
            ProMechmaterialorientdataTypeGet()
*/

extern ProError  ProMechmaterialorientdataRotationGet (ProMechMaterialOrientData data,
                ProMechMaterialOrientRotation rotation);
/*
    Purpose: Obtains the rotation angles for the material orientation of type PRO_MECH_MATLORI_MODEL.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation data.

    Output Arguments:
        rotation    - The angles.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_E_NOT_FOUND - The material orientation data does not contain a rotation.
        PRO_TK_INVALID_TYPE - The material orientation data type is not PRO_MECH_MATLORI_MODEL.
*/

extern ProError  ProMechmaterialorientdataFree (ProMechMaterialOrientData data);
/*
    Purpose: Frees the memory for a Creo Simulate material orientation data handle.

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

extern ProError  ProMechmaterialorientcsysCsysGet (ProMechMaterialOrientCsys data,
                ProMechGeomref* csys);
/*
    Purpose: Obtains the coordinate system used in the material orientation csys data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation csys data.

    Output Arguments:
        csys    - The coordinate system.  Free this using 
                  ProMechgeomrefFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError  ProMechmaterialorientcsysXaxisGet (ProMechMaterialOrientCsys data,
                ProMechMaterialOrientCsysAxis* x_axis);
/*
    Purpose: Obtains the coordinate system axis mapped to the the X-axis of the material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation csys data.

    Output Arguments:
        x_axis    - The X-axis.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmaterialorientcsysYaxisGet (ProMechMaterialOrientCsys data,
                ProMechMaterialOrientCsysAxis* y_axis);
/*
    Purpose: Obtains the coordinate system axis mapped to the the Y-axis of the material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation csys data.

    Output Arguments:
        y_axis    - The Y-axis.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmaterialorientcsysZaxisGet (ProMechMaterialOrientCsys data,
                ProMechMaterialOrientCsysAxis* z_axis);
/*
    Purpose: Obtains the coordinate system axis mapped to the the Z-axis of the material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation csys data.

    Output Arguments:
        z_axis    - The Z-axis.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmaterialorientcsysProjectiontypeGet (ProMechMaterialOrientCsys data,
                ProMechMaterialOrientCsysProjType* type);
/*
    Purpose: Obtains the projection type for the csys material orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation csys data.

    Output Arguments:
        type    - The projection type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmaterialorientcsysFree (ProMechMaterialOrientCsys data);
/*
    Purpose: Frees the memory for a Creo Simulate material orientation data handle.

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

extern ProError  ProMechmaterialorientprojTypeGet (ProMechMaterialOrientProj data,
                ProMechMaterialOrientProjType* type);
/*
    Purpose: Obtains the type of projection assigned to the material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation projection data.

    Output Arguments:
        type    - The projection type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechmaterialorientprojXyzvectorGet (ProMechMaterialOrientProj data,
                ProVector vector);
/*
    Purpose: Obtains the vector used for projection of the material orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation projection data.

    Output Arguments:
        vector    - The vector.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The data does not contain this type of projection.
*/

extern ProError  ProMechmaterialorientprojPointsGet (ProMechMaterialOrientProj data,
                ProMechGeomref** points);
/*
    Purpose: Obtains the two points used for projection in this material orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data    - The material orientation projection data.

    Output Arguments:
        points    - ProArray of points used for projection.  Free this
                  using ProMechgeomrefProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_TYPE - The data does not contain this type of projection.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
*/

extern ProError  ProMechmaterialorientprojFree (ProMechMaterialOrientProj data);
/*
    Purpose: Frees the memory for a Creo Simulate material orientation data handle.

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

extern ProError ProMechmaterialorientdataObjecttypeGet (ProMechMaterialOrientData   data,
                                        ProMechMaterialOrientObjType* type);
/*
        Purpose: Obtains the type of object for the material orientation object.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The material orientation data.

        Output Arguments:
                type    - The object type.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
tion.
*/

extern ProError ProMechmaterialorientdataSurfacerotationGet (ProMechMaterialOrientData data, double *rotation);
/*
         Purpose: Obtains the rotation angle for the material orientation if the orientation type is
                  PRO_MECH_MATLORI_SURFACE.

         Licensing Requirement:
          TOOLKIT for Mechanica

         Input Arguments:
              data - The material orientation data.

         Output Arguments:
              rotation - The rotation angle.

         Return Values:
             PRO_TK_NO_ERROR - The function succeeded.
             PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
             PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
             PRO_TK_INVALID_TYPE - The material orientation data type is not PRO_MECH_MATLORI_SURFACE.
             PRO_TK_E_NOT_FOUND - The material orientation data does not contain a rotation.
*/

extern ProError ProMechmaterialorientDescriptionSet (ProMechItem* item, ProComment description);
/*
    Purpose: Sets the description of the material orientation object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The material orientation.
        description - The description.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

*/

extern ProError ProMechmaterialorientDataSet (ProMechItem* item, ProMechMaterialOrientData data);
/*
    Purpose: Sets the data for the material orientation object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The material orientation.
        data - The data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error was encountered.
        PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
        PRO_TK_CANT_MODIFY - Cannot modify the item.

*/

extern ProError ProMechmaterialorientdataCsysdataSet (ProMechMaterialOrientData data, ProMechMaterialOrientCsys csys_data);
/*
    Purpose: Sets the coordinate system orientation data for the material 
             orientation data.

             In FEM mode, this data should be compulsorily set and
             ProMechMaterialOrientCsysProjType should be set to 
             PRO_MECH_MATLORI_CSYS_PROJ_X.

             In Native mode, if ProMechMaterialOrientObjType is 
             PRO_MECH_MATLORI_MODEL, then, this data should be compulsorily 
             set and ProMechMaterialOrientCsysProjType should be set to 
             PRO_MECH_MATLORI_CSYS_PROJ_CLOSEST.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation data.
        csys_data - The csys data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmaterialorientdataProjectiondataSet (ProMechMaterialOrientData data, ProMechMaterialOrientProj proj_data);
/*
    Purpose: Sets the projection orientation data for the material orientation 
             data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation data.
        proj_data - The projection data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechmaterialorientdataFirstdirectionSet  (ProMechMaterialOrientData data);
/*
  
     Purpose: Sets the material orient data to use first direction as its orientation type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/     

extern ProError ProMechmaterialorientdataSeconddirectionSet  (ProMechMaterialOrientData data);
/*
  
     Purpose: Sets the material orient data to use second direction as its orientation type. 

    Licensing Requirement:     
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation data.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientdataRotationSet (ProMechMaterialOrientData data, ProMechMaterialOrientRotation rotation);
/*
    Purpose: Sets the rotation angles for the material orientation of type PRO_MECH_MATLORI_MODEL.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation data.
        rotation - The angles.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.

*/

extern ProError ProMechmaterialorientdataAlloc (ProMechMaterialOrientData* data);
/*
    Purpose: Allocates the memory for a Creo Simulate material orientation data 
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

extern ProError ProMechmaterialorientcsysCsysSet (ProMechMaterialOrientCsys data, ProMechGeomref csys);
/*
    Purpose: Sets the coordinate system used in the material orientation csys 
             data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation csys data.
        csys - The coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientcsysXaxisSet (ProMechMaterialOrientCsys data, ProMechMaterialOrientCsysAxis x_axis);
/*
    Purpose: Sets the coordinate system axis mapped to the the X-axis of the 
             material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation csys data.
        x_axis - The Xaxis.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientcsysYaxisSet (ProMechMaterialOrientCsys data, ProMechMaterialOrientCsysAxis y_axis);
/*
    Purpose: Sets the coordinate system axis mapped to the the Y-axis of the 
             material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation csys data.
        y_axis - The Yaxis.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientcsysZaxisSet (ProMechMaterialOrientCsys data, ProMechMaterialOrientCsysAxis z_axis);
/*
    Purpose: Sets the coordinate system axis mapped to the the Z-axis of the 
             material orientation.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation csys data.
        z_axis - The Zaxis.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientcsysProjectiontypeSet (ProMechMaterialOrientCsys data, ProMechMaterialOrientCsysProjType type);
/*
    Purpose: Sets the projection type for the csys material orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation csys data.
        type - The projection type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientcsysAlloc (ProMechMaterialOrientCsys* data);
/*
    Purpose: Allocates the memory for a Creo Simulate material orientation data 
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

extern ProError ProMechmaterialorientprojXyzvectorSet (ProMechMaterialOrientProj data, ProVector vector);
/*
    Purpose: Sets the vector used for projection of the material orientation 
             data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation projection data.
        vector - The vector.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientprojPointsSet (ProMechMaterialOrientProj data, ProMechGeomref* points);
/*
    Purpose: Sets the two points used for projection in this material
             orientation data.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation projection data.
        points - ProArray of points used for projection.
                 (NOTE: Only PRO_MECH_POINT_SINGLE, PRO_MECH_VERTEX_EDGE_START 
                  and PRO_MECH_VERTEX_EDGE_END type points are allowed)

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientprojAlloc (ProMechMaterialOrientProj* data);
/*
    Purpose: Allocates the memory for a Creo Simulate material orientation data 
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

extern ProError ProMechmaterialorientdataObjecttypeSet (ProMechMaterialOrientData data, ProMechMaterialOrientObjType   type);
/*
    Purpose: Sets the type of object for the material orientation object.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        data - The material orientation data.
        type - The object type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechmaterialorientdataSurfacerotationSet (ProMechMaterialOrientData data, double rotation);
/*
     Purpose: Assigns the rotation angle for the material orientation if the orientation type is
                PRO_MECH_MATLORI_SURFACE.

     Licensing Requirement:
          TOOLKIT for Mechanica

     Input Arguments:
           data - The material orientation data.
           rotation - The rotation angle.

     Output Arguments:
           none

     Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.
*/

extern ProError ProMechmaterialorientdataSurfacerotationUnset (ProMechMaterialOrientData data);
/*
    Purpose: Removes the rotation angle for the material orientation if the orientation type is
             PRO_MECH_MATLORI_SURFACE.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         data - The material orientation data.

    Output Arguments:
         none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_CANT_WRITE - Subtype cannot be changed.

*/
PRO_END_C_DECLS

#endif /* PROMECHMATERIALORIENT_H */
