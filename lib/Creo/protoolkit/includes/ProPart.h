

#ifndef PROPART_H
#define PROPART_H

#include <ProToolkit.h>
#include <ProMaterial.h>
#include <ProObjects.h>

typedef int ProTriangle[3];

typedef struct
{
ProSurface surface;
int n_vertices;
ProVector* vertices;
ProVector* normals;
int n_facets;
ProTriangle* facets;
} ProSurfaceTessellationData;

PRO_BEGIN_C_DECLS 

extern ProError ProPartMaterialNameGet ( ProPart part,
                                         ProName material_name );

/* 
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProMaterialCurrentGet
  Purpose: This function is deprecated.  Use ProMaterialCurrentGet().
          
          <P>Retrieves the material assigned to the specified part.

  Input Arguments:
     part             - The part.

  Output Arguments:
     material_name    - The name of the material. If you have not
                        assigned a material, this will be empty.

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully retrieved the
                           information.
     PRO_TK_BAD_INPUTS   - Either the part or material name is NULL.
     PRO_TK_INVALID_TYPE - The model handle you passed to the function
                           is not a part.
     PRO_TK_E_NOT_FOUND  - No material was set.

*/

extern ProError ProPartMaterialSet ( ProPart part,
                                     ProName material_name );

/*

  Purpose: This function is obsoleted.  
           Use ProMaterialfileRead() and ProMaterialCurrentSet().
          
           <P>Assigns a material and its associated properties to a part.

  Input Arguments:
     part           - The part
     material_name  - The name of the material properties file

  Output Arguments:
     None

  Return Values:
     PRO_TK_OBSOLETE_FUNC - The function is obsoleted.

*/

extern ProError ProPartMaterialdataGet (ProPart           part,
                                        ProName           material_name,
                                        ProMaterialProps* material_prop );

/*
  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProMaterialPropertyGet
  Purpose: This function is deprecated. Use ProMaterialPropertyGet() for the
           individual material properties that should be defined in this
           material.
          
           <P>Retrieves the material properties for the specified part.

  Input Arguments:
     part            - The part
     material_name   - The material name
     
  Output Arguments:
     material_prop   - The material properties

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

extern ProError ProPartTessellate (ProPart part,
				   double chord_ht,
				   double angle_cntrl,
				   ProBoolean include_quilts,
				   ProSurfaceTessellationData **output);
			     
/*

 Purpose: Returns a tessellation (also called a triangulation) of each
           surface of the specified part. For parts, acts on all surfaces.
           For assemblies, acts only on surfaces of the assembly, not
           components.
  
<p>    NOTE: Use function ProPartTessellationFree() to release memory
             allocated by this function.

  Input Arguments:
     part            - The part
     chord_ht        - The maximum allowable chord height ( > 0 )
     angle_cntrl     - The angle control (between 0.0 and 1.0)
     include_quilts  - Include quilts and facets or not
 
  Output Arguments:
     output          - Pointer to a ProArray of ProSurfaceTessellationData,
                          one for each surface of the part.
     
  Return Values:  
     PRO_TK_NO_ERROR       - The function successfully tessellated each 
                             surface. 
     PRO_TK_BAD_INPUTS     - One or more of the input arguments were invalid.
     PRO_TK_GENERAL_ERROR  - A tessellation error occurred.

*/

extern ProError ProPartTessellationFree (ProSurfaceTessellationData **tess);

/*

  Purpose: Frees the memory allocated by ProPartTessellate().
  
  Input Arguments:
     tess             - Pointer to ProArray of ProSurfaceTessellationData

  Output Arguments:
     none

  Return Values:  
     PRO_TK_NO_ERROR     - The function successfully freed the tessellation.
     PRO_TK_BAD_INPUTS   - The input argument was invalid.

*/

extern ProError ProPartDensityGet (ProPart part, double* density);

/*
Purpose:  Determines the density of the part.

Input Arguments:  
      part - The part handle.

Output Arguments:
      density - The part density (in the units of the model).  
                If the part has been assigned a material, this is the 
                density for the material.


Return Values:
      PRO_TK_NO_ERROR - The function retrieved the density.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The part has not been assigned a density value.
*/

extern ProError ProPartDensitySet (ProPart part, double density);

/*
Purpose:  Sets the density of the part.

Input Arguments:  
      part - The part handle.
      density - The part density (in the units of the model).  If the part 
                has been assigned a material, this will modify the density 
                of the material.

Output Arguments:
      none

Return Values:
      PRO_TK_NO_ERROR - The function retrieved the density.
      PRO_TK_BAD_INPUTS - One or more input arguments is invalid.
*/

PRO_END_C_DECLS

#endif
