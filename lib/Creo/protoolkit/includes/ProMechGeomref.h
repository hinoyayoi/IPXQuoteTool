#ifndef PROMECHGEOMREF_H
#define PROMECHGEOMREF_H



#include <ProToolkit.h>
#include <ProObjects.h>

typedef enum 
{
  PRO_MECH_GEOMREF_UNUSED = PRO_VALUE_UNUSED,

  PRO_MECH_POINT         = 0,
  PRO_MECH_EDGE          = 1,
  PRO_MECH_SURFACE       = 2,
  PRO_MECH_VERTEX        = 3,
  PRO_MECH_QUILT         = 4,
  PRO_MECH_BOUNDARY      = 5,    /* All Surfaces */
  PRO_MECH_CURVE         = 6,
  PRO_MECH_MODEL         = 7,    /* Whole Part / Assembly */
  PRO_MECH_AXIS          = 8,
  PRO_MECH_COORD_SYSTEM  = 9,
  PRO_MECH_LAYER         = 10,
  PRO_MECH_VOLUME        = 11,
  PRO_MECH_INT_PNT       = 12,
  PRO_MECH_INT_CURVE     = 13,
  PRO_MECH_INT_EDGE      = 14,
  PRO_MECH_INT_SURFACE   = 15,
  PRO_MECH_FEAT          = 16
}
ProMechGeomrefType;

typedef enum 
{
  PRO_MECH_GEOMREF_SUBTYPE_UNUSED = PRO_VALUE_UNUSED,

                                     /* Point sub-types */
  PRO_MECH_POINT_SINGLE      = 0,
  PRO_MECH_POINT_FEATURE     = 1,
  PRO_MECH_POINT_PATTERN     = 2,
  PRO_MECH_POINT_LATT_SINGLE = 3,    /* Reserved for internal use */
  PRO_MECH_POINT_LATT_SET    = 4,    /* Reserved for internal use */

                                     /* Vertex sub-types */
  PRO_MECH_VERTEX_EDGE_START = 10,
  PRO_MECH_VERTEX_EDGE_END   = 11,

                                     /* Coordinate System sub-types */
  PRO_MECH_CSYS_CARTESIAN    = 20,
  PRO_MECH_CSYS_CYLINDRICAL  = 21,
  PRO_MECH_CSYS_SPHERICAL    = 22,

                                     /* Surfaces sub-types */
  PRO_MECH_SURFACE_NORMAL    = PRO_MECH_GEOMREF_SUBTYPE_UNUSED,
  PRO_MECH_SURFACE_REVERSED  = 31,

                                     /* Edge/Curve sub-types */
  PRO_MECH_CURVE_NORMAL      = PRO_MECH_GEOMREF_SUBTYPE_UNUSED,
  PRO_MECH_CURVE_REVERSED    = 41,

                                     /* Edge sub-types */
  PRO_MECH_EDGE_SURF_0       = 50,
  PRO_MECH_EDGE_SURF_1       = 51
}
ProMechGeomrefSubType;

#define PRO_MECH_WCS (-2) /* use it as Csys "id" for referencing WCS */

typedef struct pro_sim_entity* ProMechGeomref;

PRO_BEGIN_C_DECLS

extern ProError  ProMechgeomrefTypeGet (ProMechGeomref entity,
				ProMechGeomrefType* type);
/*
	Purpose: Obtains the entity type.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		entity	- The entity.

	Output Arguments:
		type	- The type. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechgeomrefTypeSet (ProMechGeomref entity, ProMechGeomrefType type);
/*
    Purpose: Sets the entity type.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entity - The entity.
        type - The type.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/

extern ProError  ProMechgeomrefSubtypeGet (ProMechGeomref entity,
				ProMechGeomrefSubType* sub_type);
/*
	Purpose: Obtains the entity subtype.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		entity	- The entity.

	Output Arguments:
		sub_type	- The subtype.
		
	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechgeomrefSubtypeSet (ProMechGeomref entity, ProMechGeomrefSubType sub_type);
/*
    Purpose: Sets the entity subtype.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entity - The entity.
        sub_type - The subtype.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/

extern ProError  ProMechgeomrefIdGet (ProMechGeomref entity,
				int* id);
/*
	Purpose: Obtains the entity id.  

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		entity	- The entity.

	Output Arguments:
		id	- The entity id.  Creo Simulate uses PRO_MECH_WCS as the id of the 
				default world coordinate system. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/
extern ProError ProMechgeomrefIdSet (ProMechGeomref entity, int id);
/*
    Purpose: Sets the entity id.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entity - The entity.
        id - The entity id.  Creo Simulate uses PRO_MECH_WCS as the id of the
             default world coordinate system.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/

extern ProError  ProMechgeomrefPathGet (ProMechGeomref entity,
				ProAsmcomppath* path);
/*
	Purpose: Obtains the component path to the entity.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		entity	- The entity.

	Output Arguments:
		path	- The component path. 

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError ProMechgeomrefPathSet (ProMechGeomref entity, ProAsmcomppath* path);
/*
    Purpose: Sets the component path to the entity.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        entity - The entity.
        path - The component path.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/

extern ProError ProMechgeomrefAlloc (ProMechGeomref* entity);
/*
    Purpose: Allocates the memory for a Creo Simulate geometric entity.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
         none

    Output Arguments:
         entity - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
        PRO_TK_NO_LICENSE - No license was available to enable this function.

*/
extern ProError  ProMechgeomrefFree (ProMechGeomref entity);
/*
	Purpose: Frees the memory for a Creo Simulate geometric entity.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		entity	- The handle.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/

extern ProError  ProMechgeomrefProarrayFree (ProMechGeomref* entity);
/*
	Purpose: Frees the memory for a ProArray of Creo Simulate geometric entities.

	Licensing Requirement:
          TOOLKIT for Mechanica

	Input Arguments:
		entity	- The array.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_BAD_CONTEXT - The Creo Simulate session was not initialized.
		PRO_TK_NO_LICENSE - No license was available to enable this function.
*/


PRO_END_C_DECLS

#endif /* PROMECHGEOMREF_H */
