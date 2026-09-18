#ifndef PROCSYS_H
#define PROCSYS_H


#include   <ProObjects.h>
#include   <ProGeomitem.h>

/*
   Function declarations for ProCsys.
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

extern ProError ProCsysInit     (ProSolid   owner_handle,
 				   int        csys_id,
            			 ProCsys   *p_handle);
/*
   Purpose: Initializes the <i>ProCsys</i> handle.

   Input Arguments:
      owner_handle      - The solid owner of the coordinate system 
      csys_id           - The identifier of the coordinate system

   Output Arguments:
      p_handle          - The handle being initialized

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


extern ProError ProCsysIdGet (ProCsys   csys,
                               int       *p_id);

/*
   Purpose: Gets the identifier of the coordinate system object.

<p>
            NOTE:
<p>
            Although the pointer can be reallocated, the identifier will not 
            change.

   Input Arguments:
      csys            - The coordinate system handle

   Output Arguments:
      p_id             - The returned identifier of the coordinate
                         system object

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/


#define ProCsysDatatypeGet()  (PRO_CSYS)

extern ProError ProCsysDataGet  (ProCsys            p_csys,
				 ProGeomitemdata  **p_data_ptr);

/*
   Purpose: Retrieves the geometric representation data for the 
            specified coordinate system.

   Input Arguments:
      p_csys            - The handle to the coordinate system. 

   Output Arguments:
      p_data_ptr        - The coordinate system data. The function allocates
                          the memory for this argument. Use the function
                          <b>ProGeomitemdataFree()</b> to free the memory. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProGeomitemdataFree()
 
*/


/*===========================================================================*/
				   
PRO_END_C_DECLS
#endif /* PROCSYS_H */

