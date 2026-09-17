

#ifndef PROBOMBALLOON_H
#define PROBOMBALLOON_H

#include <ProToolkit.h>

#include <ProObjects.h>
#include <ProSelection.h>
#include <ProView.h>

PRO_BEGIN_C_DECLS

/*-----------------------------------------------------------------*/
extern ProError ProDwgtableCellRegionGet(
   ProDrawing   pro_drawing,
   ProDwgtable *pro_table,
   int          column,
   int          row,
   int         *r_region_id );
/*
   Purpose: Get region id from table cell.

   Input Arguments:
      pro_drawing       - BOM balloon will be created at this drawing.
      pro_table         - The detail table define the bill of material.
      column            - column belong to region which id is requested.
      row               - row belong to region which id is requested.

   Output Arguments:
      r_region_id       - The region id.

   Return Values:
      PRO_TK_NO_ERROR    - The function found region from cell.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TO_E_NOT_FOUND - The table cell doesn't belong to any region.
      
*/

/*-----------------------------------------------------------------*/
extern ProError ProBomballoonCreate( 
   ProDrawing   pro_drawing,
   ProDwgtable *pro_table,
   int          region_id,
   ProView      pro_view );
/*
   Purpose: Create <I>BOM Balloon</I> at specific view. 

   Input Arguments:
      pro_drawing       - BOM balloon will be created at this drawing.
                          This must be displayed in the window.
      pro_table         - The detail table define the bill of material.
      region_id         - The region of the table contain the BOM definition,
                          If region_id is equal -1, use region 0 of the table.
      pro_view          - The view where the BOM balloon will be create. 

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created the BOM balloons.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - The Drawing is not displayed.
   See Also:
      ProMdlDisplay()
*/


/*-----------------------------------------------------------------*/
extern ProError ProBomballoonAllCreate(
   ProDrawing   pro_drawing,
   ProDwgtable *pro_table,
   int          region_id );
/*
   Purpose: Create All <I>BOM Balloon</I> at first view. 

   Input Arguments:
      pro_drawing       - BOM balloons will be created at this drawing.
                          This must be displayed in the window.
      pro_table         - The detail table define the bill of material.
      region_id         - The region of the table contain the BOM definition.
                          If region_id is equal -1, use region 0 of the table.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created the BOM balloons.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - The Drawing is not displayed.
   See Also:
      ProMdlDisplay()
*/


/*-----------------------------------------------------------------*/
extern ProError ProBomballoonByComponentCreate( 
   ProDrawing    pro_drawing,
   ProDwgtable  *pro_table,
   int           region_id,
   ProView       pro_view,
   int          *component_memb_id_tab );
/*
   Purpose: Create <I>BOM Balloon</I> at selected comp and view. 

   Input Arguments:
      pro_drawing       - BOM balloons will be created at this drawing.
                          This must be displayed in the window.
      pro_table         - The detail table define the bill of material.
      region_id         - The region of the table contain the BOM definition.
                          If region_id is equal -1, use region 0 of the table.
      pro_view          - The view where the BOM balloons will be create. 
                          If view parameter is NULL, use first view.       
                          (Possible: NULL) 
      component_memb_id_tab - ProArray: member id tab to component.
                              BOM balloons will be created at this component.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created the BOM balloons.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - The Drawing is not displayed.
   See Also:
      ProMdlDisplay()
*/


/*-----------------------------------------------------------------*/
extern ProError ProBomballoonByRecordCreate(
   ProDrawing    pro_drawing,
   ProDwgtable  *pro_table,
   int           region_id,
   ProView       pro_view,
   int           table_record_index,
   int          *reference_memb_id_tab,
   int           reference_id,
   ProType       reference_type, 
   double       *attach_note_location );
/*
   Purpose: Create <I>BOM Balloon</I> at detail table record. 

   Input Arguments:
      pro_drawing           - BOM balloons will be created at this drawing.
                              This must be displayed in the window.
      pro_table             - The detail table define the bill of material.
      region_id             - The region of the table contain the BOM 
                              definition, If region_id is equal -1, use 
                              region 0 of the table.
      pro_view              - The view where the BOM balloons will be create. 
                              Use for BOM balloon creation without leader.
      table_record_index    - BOM balloons will be created at first component
                              match to this table record. 
							  <b>Indices start with 0.</b>
      reference_memb_id_tab - ProArray: member id tab to component 
                              contain the reference for the leader.
      reference_id          - reference id. 
                              If it set to PRO_VALUE_UNUSED attach without leader.
      reference_type        - reference type.
      attach_note_location  - ProArray: free attachment point for the BOM balloon.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created the BOM balloons.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - The Drawing is not displayed.
*/


/*-----------------------------------------------------------------*/
extern ProError ProBomballoonClean( 
   ProDrawing    pro_drawing,
   ProView       pro_view,
   ProBool       clean_pos,
   ProBool       existing_snap_lines,
   double        offset_from_view_outline,
   ProBool       stagger,
   double        stagger_val,
   ProBool       create_stagger_snap_lines,
   double        interballoons_distance,
   ProBool       attach_to_surface );
/*
   Purpose: Clean <I>BOM Balloon</I> from view.

   Input Arguments:
      pro_drawing               - BOM balloons will be created at this drawing.
                                  This must be displayed in the window.
      pro_view                  - BOM balloons exist at this view.
      clean_pos                 - Cleanup BOM balloon position.
      existing_snap_lines       - Use existing snap lines.
      offset_from_view_outline  - Offset from view outline
      stagger                   - Staggers balloons at different offset distances
                                  from view border if necessary.
      stagger_val               - increment between snap lines
      create_stagger_snap_lines - create snap lines
      interballoons_distance    - BOM balloons space size.
      attach_to_surface         - If value set to PRO_B_TRUE attach to surface,
                                  otherwise attach to edge.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully created the BOM balloons.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_DISPLAYED - The Drawing is not displayed.
*/

PRO_END_C_DECLS 
#endif /* PROBOMBALLOON_H */
