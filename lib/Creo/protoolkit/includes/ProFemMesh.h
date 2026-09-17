#ifndef  PRO_FEM_MESH_H
#define  PRO_FEM_MESH_H

/* Creo Parametric TOOLKIT declarations for exporting the FEM mesh to FEA solvers */

#include  <ProToolkit.h>
#include  <ProObjects.h>

#include  <ProFemObjects.h>




PRO_BEGIN_C_DECLS


/******************************************************************************/

typedef struct pro_fem_geom_ref
{
  int                    id;
  ProAsmcomppath         path;
}
ProFemquiltref, ProFemcsysref;


typedef struct pro_femmesh_data
{
  ProFemmeshType         mesh_type;
  ProFemshellmeshType    shell_type;

  int                    num_quilts;
  ProFemquiltref       * pro_quilt_ref_arr;

  ProFemanalysisType     analysis;
  ProFemelemshapeType    elem_shape;
  ProFemsolverType       solver;

  ProFemcsysref          csys_ref;   /* if id is PRO_VALUE_UNUSED - not used */

  int                    num_aux_csys;
  ProFemcsysref        * aux_csys_ref_arr;
}
ProFemmeshData;

/******************************************************************************/

extern  ProError  ProFemmeshExport ( ProSolid           pro_solid,
                                     ProFemmeshData* p_mesh_data,
                                     ProPath            file_name    );
 
/*
   Purpose:
        Generates the Finite Element Mesh based on the given parameters, and
        exports it to the specified file. Prior to calling this function, the
        model (pro_solid) should be displayed in the graphics window.
 
   Input Arguments:
        pro_solid       - The handle of a Creo Parametric model (part or assembly).
        p_mesh_data     - The pointer to the data structure containing
                          the mesh generation parameters.
        file_name       - The file name to export mesh to.
 
   Output Arguments:
        None
 
   Return Values:
        Creo Parametric TOOLKIT error code.
*/

/******************************************************************************/


PRO_END_C_DECLS


#endif  /* PRO_FEM_MESH_H */
