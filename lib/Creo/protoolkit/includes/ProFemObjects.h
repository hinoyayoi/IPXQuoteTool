#ifndef  PRO_FEM_OBJECTS_H
#define  PRO_FEM_OBJECTS_H

/* Creo Parametric TOOLKIT declarations for FEM Mesh Export parameters */



PRO_BEGIN_C_DECLS

/******************************************************************************/

typedef enum pro_fem_mesh_type
{
  PRO_FEM_SOLID_MESH    = 0,
  PRO_FEM_SHELL_MESH    = 1,
  PRO_FEM_MIXED_MESH    = 2,
  PRO_FEM_QUILT_MESH    = 3,
  PRO_FEM_BOUNDARY_MESH = 4,
  PRO_FEM_BAR_MESH      = 5
}
ProFemmeshType;

typedef enum pro_fem_shell_mesh_type
{
  PRO_FEM_SHELL_MESH_TRIANGLE   = 0,
  PRO_FEM_SHELL_MESH_QUADRANGLE = 1
}
ProFemshellmeshType;

typedef enum pro_fem_analysis_type
{
  PRO_FEM_ANALYSIS_STRUCTURAL = 0,
  PRO_FEM_ANALYSIS_MODAL      = 1,
  PRO_FEM_ANALYSIS_THERMAL    = 2,
  PRO_FEM_ANALYSIS_FLOW       = 3     /* obsoleted */
}
ProFemanalysisType;

typedef enum pro_fem_elem_shape_type
{
  PRO_FEM_MIDPNT_LINEAR          = 0,
  PRO_FEM_MIDPNT_PARABOLIC       = 1,
  PRO_FEM_MIDPNT_PARABOLIC_FIXED = 2
}
ProFemelemshapeType;

typedef enum pro_fem_solver_type
{
  PRO_FEM_FEAS_NONE        = 0,
  PRO_FEM_FEAS_NEUTRAL     = 1,
  PRO_FEM_FEAS_ANSYS       = 2,
  PRO_FEM_FEAS_COSMOS      = 3,   /* obsoleted */
  PRO_FEM_FEAS_NASTRAN     = 4,
  PRO_FEM_FEAS_PATRAN      = 5,   /* obsoleted */
  PRO_FEM_FEAS_SUPERTAB    = 6,   /* obsoleted */
  PRO_FEM_FEAS_C_MOLD      = 7,   /* obsoleted */
  PRO_FEM_FEAS_ABAQUS      = 8,
  PRO_FEM_FEAS_NEI_NASTRAN = 9
}
ProFemsolverType;

/******************************************************************************/

PRO_END_C_DECLS

#endif  /* PRO_FEM_OBJECTS_H */
