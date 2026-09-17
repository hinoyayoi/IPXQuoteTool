#ifndef PROGEOMITEMDATA_H
#define PROGEOMITEMDATA_H

#include   <ProObjects.h>
#include   <ProCurvedata.h>
#include   <ProSurfacedata.h>
#include   <ProCsysdata.h>

/*
   Function declarations and specific data structures for ProGeomitem
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/


typedef struct geom_item_data_struct
{
    ProType     obj_type;
    union 
    {
	ProCurvedata     *p_curve_data;
	ProSurfacedata   *p_surface_data;
	ProCsysdata      *p_csys_data;
    } data;
} ProGeomitemdata;
     
#define PRO_CURVE_DATA(p_data) p_data  == NULL ? NULL : \
			        p_data -> data.p_curve_data

#define PRO_SURF_DATA(p_data)  p_data  == NULL ? NULL : \
				p_data -> data.p_surface_data

#define PRO_CSYS_DATA(p_data)  p_data  == NULL ? NULL : \
				p_data -> data.p_csys_data


extern ProError ProGeomitemdataGet ( ProGeomitem      *p_item,
		     ProGeomitemdata **p_data_ptr );
/*
   Purpose:     Retrieves the geometric representation data of the specified
                geometry item.
<p>
                The following types of Geomitems are supported:
<ul>
                <li>PRO_EDGE
                <li>PRO_EDGE_START
                <li>PRO_EDGE_END
                <li>PRO_CURVE
                <li>PRO_CRV_START
                <li>PRO_CRV_END
                <li>PRO_AXIS
                <li>PRO_SURFACE
                <li>PRO_CSYS
</ul>

   Input Arguments:
      p_item            - The item handle.

   Output Arguments:
      p_data_ptr        - The item data. The function allocates the memory 
                          for this argument. Use the function 
                          <b>ProGeomitemdataFree()</b> to free the memory.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProGeomitemdataFree()
*/


extern ProError ProGeomitemdataFree ( ProGeomitemdata **to_free );

/*
   Purpose:     Frees the geometry item data allocated 
                by <b>ProGeomitemdataGet()</b>
		(or any of the <b>Pro*dataGet()</b> functions).
 
   Input Arguments:
      to_free           - The pointer to the data pointer
 
   Output Arguments:
      None
 
   Return Values: 
      PRO_TK_NO_ERROR   - The function successfully freed the data.
      PRO_TK_BAD_INPUTS - The argument is invalid.

   See Also:
      ProCurveDataGet()
      ProEdgeVertexdataGet()
      ProGeomitemdataGet()
*/

PRO_END_C_DECLS

#endif /* PROGEOMITEMDATA_H */
