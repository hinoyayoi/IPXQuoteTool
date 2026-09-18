

#ifndef PROSECDIMDOTH
#define PROSECDIMDOTH

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSelection.h>
#include <ProSection.h>
#include <ProItemerr.h>
#include <Pro2dEntdef.h>
#include <ProSecdimType.h>

PRO_BEGIN_C_DECLS

extern ProError ProSecdimCreate  (ProSection handle,
                                 int           entity_ids[],
                                 ProSectionPointType point_types[],
                                 int           num_ids,
                                 ProSecdimType dim_type,
                                 Pro2dPnt      place_pnt,
                                 int          *r_dim_id);
/* 
   Purpose:
        Dimensions the entities in the specified section to each other.

   Input Arguments:
        handle      - The section handle
        entity_ids  - An array of entity identifiers
        point_types - An array of point types (PRO_ENT_...)
        num_ids     - The length of the <i>entity_ids</i> array
        dim_type    - The dimension type (linear, angular, length, and so on)
        place_pnt   - The placement point

   Output Arguments:
        r_dim_id - The identifier of the section dimension
        
   Return Values:
        PRO_TK_NO_ERROR     - The function successfully dimensioned the 
                              entities. 
        PRO_TK_BAD_INPUTS   - One or more of the input arguments are
                              invalid.
        PRO_TK_MEMORY_ERROR - There was a memory error.
*/

extern ProError ProSecdimValueSet (ProSection handle,
                                   int dim_id,
                                   double value);
/* 
   Purpose:
   Changes the value of the specified dimension in the section.
   
   Input Arguments:
        handle        - The section handle
        dim_id        - The identifier of the dimension to be modified
        value         - The new value of the dimension

   Output Arguments:
        None

   Return Values:                                                            
        PRO_TK_NO_ERROR       - The function successfully set the new value.
        PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function 
                                failed.
*/



extern ProError ProSecdimDelete (ProSection handle,
                                 int        dim_id);
/* 
   Purpose:
        Deletes a dimension from the specified section.

   Input Arguments:
        handle     - The section handle
        dim_id     - The identifier of the dimension

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully deleted the dimension.
        PRO_TK_GENERAL_ERROR  - One or more of the arguments are invalid.
*/

extern ProError ProSecdimValueGet (ProSection handle,
                                   int        dim_id,
                                   double    *r_value);
/* 
   Purpose:
   Retrieves the value of the specified dimension in the section.
   
   Input Arguments:
        handle        - The section handle
        dim_id        - The identifier of the dimension


   Output Arguments:
        r_value       - The value of the dimension

   Return Values:                                                            
        PRO_TK_NO_ERROR      - The function successfully retrieved the
                               information.
        PRO_TK_GENERAL_ERROR - A general error occurred and the function
                               failed.
*/

extern ProError ProSecdimTypeGet (ProSection     section,
                                  int            dim_id,
                                  ProSecdimType *r_type);
/* 
   Purpose:
   Retrieves the type of the specified dimension in the section.
   
   Input Arguments:
        section       - The section handle
        dim_id        - The identifier of the dimension

   Output Arguments:
        r_type        - The type of the dimension

   Return Values:                                                            
        PRO_TK_NO_ERROR      - The function successfully retrieved the
                               information.
        PRO_TK_GENERAL_ERROR - A general error occurred and the function
                               failed.
*/

extern ProError ProSecdimLocationGet (
                                     ProSection handle,
                                     int        dim_id,
                                     Pro2dPnt   location);
/* 
   Purpose:
   Retrieves the location of the specified dimension in the section.
   
   Input Arguments:
        handle        - The section handle
        dim_id        - The identifier of the dimension

   Output Arguments:
        location      - The location of the dimension in section coordinates

   Return Values:                                                            
        PRO_TK_NO_ERROR      - The function successfully retrieved the
                               information.
        PRO_TK_GENERAL_ERROR - A general error occurred and the function
                               failed.
*/

extern ProError ProSecdimReferencesGet (
                                       ProSection handle,
                                       int        dim_id,
                                       int                 **entity_ids,
                                       ProSectionPointType **point_types,
                                       int *p_num_refs);

/* 
   Purpose:
   Retrieves the references of the specified dimension in the section.
   
   Input Arguments:
        handle        - The section handle.
        dim_id        - The identifier of the dimension.

   Output Arguments:
           entity_ids - An array of entity identifiers referenced by the 
                        section dimension. Free this memory using 
                        <b>ProArrayFree()</b>.
          point_types - The corresponding array of <i>point_types</i> 
                        for each entity.
                        Free this memory using <b>ProArrayFree()</b>.
           p_num_refs - The returned size of the arrays.

   Return Values:                                                            
        PRO_TK_NO_ERROR      - The function successfully retrieved the
                               information.
        PRO_TK_GENERAL_ERROR - A general error occurred and the function
                               failed.
 
   See Also:
        ProArrayFree()
*/

extern ProError ProSecdimIdsGet (ProSection  handle,
                                 ProIntlist *p_id_list,
                                 int        *p_num_ids );
/* 
   Purpose:
        Returns an array of valid dimension identifiers for the specified
        section.
        
   Input Arguments:
        handle    - The section handle.

   Output Arguments:
        p_id_list - The array of identifiers. The function allocates the
                    memory for this array. Call the function 
                    <b>ProArrayFree()</b>to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSecdimDiameterSet (ProSection handle, 
                                      int dim_id);
/* 
   Purpose:
        Converts section dimension between a centerline and another entity 
        into a "diameter dimension".
        
   Input Arguments:
        handle    - The section handle.
        dim_id    - ID of a dimension to convert

   Output Arguments:
        
        NONE
   
   Return Values:
        PRO_TK_NO_ERROR       - The dimension was successfully converted.
        PRO_TK_BAD_INPUTS     - The input arguments are invalid.
                                ( invalid handle, invalid dimension ID, or
                                  dimension doesn't reference exactly one 
                                  centerline )
*/

extern ProError ProSecdimDiameterClear (ProSection handle, 
                                        int dim_id);

/* 
   Purpose:
        Converts a "diameter" section dimension (between a centerline and
        another entity) into a regular one.
        
   Input Arguments:
        handle    - The section handle.
        dim_id    - ID of a dimension to convert

   Output Arguments:
        
        NONE
   
   Return Values:
        PRO_TK_NO_ERROR       - The dimension was successfully converted.
        PRO_TK_BAD_INPUTS     - The input arguments are invalid.
                                ( invalid handle, invalid dimension ID, or
                                  or the dimension doesn't reference exactly one 
                                  centerline )
*/


extern ProError ProSecdimDiameterInquire (ProSection handle, 
                                          int dim_id,
                                          ProBoolean *dim_is_diameter);

/* 
   Purpose:
        To determine whether a dimension has the "diameter" property.
        
   Input Arguments:
        handle           - The section handle.
        dim_id           - ID of a dimension to get info about

   Output Arguments:
        dim_is_diameter  - TRUE, if the dimension is a "diameter" one.
                           FALSE, otherwise.
   
   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_BAD_INPUTS     - The input arguments are invalid.
                                ( invalid handle, or invalid dimension ID )

*/

extern ProError ProSecdimStrengthen ( ProSection section,
                                      int dim_id );
/*
    Purpose: Make a strong dimension.

    Input Arguments:
        section - The section
        dim_id - The dimension identifier 

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function successfully strengthen the entity.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_INVALID_TYPE - Dimension can not be made strong.
        PRO_TK_E_FOUND - Dimension is already a strong dimension.
*/


extern ProError ProSecdimLockSet( ProSection section,
                                  int dim_id,
                                  ProBoolean is_locked );
/*
    Purpose: Lock or unlock the dimension entity.

    Input Arguments:
        section - The section
        dim_id - The dimension identifier 
        is_locked - PRO_B_TRUE, means lock the dimension.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function successfully locked/ unlocked the entity.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_INVALID_TYPE - Dimension can not be locked or unlocked.
*/


extern ProError ProSecdimIsLocked( ProSection section,
                                   int dim_id,
                                   ProBoolean *is_locked );
/*
    Purpose: Determine whether or not the dimension is locked.

    Input Arguments:
        section - The section
        dim_id - The dimension identifier 
       
    Output Arguments:
       is_locked - PRO_B_TRUE, means locked dimension status.

    Return Values:
        PRO_TK_NO_ERROR - The function successfully executed.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

PRO_END_C_DECLS

#endif

