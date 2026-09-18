#ifndef PROINTFDATA_H
#define PROINTFDATA_H

#include   <ProSurfacedata.h>
#include   <ProQuiltdata.h>
#include   <ProEdgedata.h>
#include   <ProDatumdata.h>

/*
   Function declarations and specific data structures for ProIntfData
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef	enum pro_accu_type
 {
	PRO_ACCU_NONE = 0,
	PRO_ACCU_RELATIVE,	/* accuracy is relative */
	PRO_ACCU_ABSOLUTE	/* accuracy is absolute */
 } ProAccuracytype;

typedef enum pro_intf_type
 {
	PRO_INTF_NONE = 0,
	PRO_INTF_NEUTRAL,
	PRO_INTF_NEUTRAL_FILE,
	PRO_INTF_IGES,
	PRO_INTF_STEP,
	PRO_INTF_VDA,
	PRO_INTF_SET,             /* This type is obsolete.*/
	PRO_INTF_PDGS,	          /* This type is obsolete.*/ 
	PRO_INTF_CATIA,		      /* This type is obsolete.*/ 
	PRO_INTF_DESKTOP,         /* This type is obsolete.*/
	PRO_INTF_ICEM,			  /* This type is obsolete.*/
	PRO_INTF_ACIS,
	PRO_INTF_DXF,
	PRO_INTF_CDRS,
	PRO_INTF_STL,
 	PRO_INTF_VRML,
	PRO_INTF_PARASOLID,
	PRO_INTF_AI,
	PRO_INTF_CATIA_PART,
	PRO_INTF_UG,
	PRO_INTF_IDEAS_DESIGN,    /* This type is obsolete.*/
	PRO_INTF_IDEAS_PACKAGE,   /* This type is obsolete.*/
	PRO_INTF_PRODUCTVIEW,
	PRO_INTF_CATIA_PRODUCT,
	PRO_INTF_CATIA_CGR,
	PRO_INTF_JT,
	PRO_INTF_INVENTOR_PART,
	PRO_INTF_INVENTOR_ASM,
	PRO_INTF_NEUTRAL_PV,      /* Reserved for internal use.*/
	PRO_INTF_RHINO,           /* Reserved for future use.*/
        PRO_INTF_IBL,
        PRO_INTF_PTS,
        PRO_INTF_CC,		  /* Reserved for future use.*/
	PRO_INTF_SW_PART,         /* Reserved for future use.*/
	PRO_INTF_SW_ASM,          /* Reserved for future use.*/
	PRO_INTF_SE_PART,
	PRO_INTF_SE_SHEETMETAL_PART, 
	PRO_INTF_SE_ASM           /* Reserved for future use.*/
} ProIntfType;

typedef struct pro_intf_data
{
ProAccuracytype		accu_type;	/* Accuracy type */
double			accuracy;	/* Accuracy */
ProOutline		xyz_outline;    /* Outline */
ProSurfacedata	*surf_array;		/* Array of surface data structures */
					/* Attention! Access to individual */
					/* data items only through */
					/* ProIntfDataSurfaceGet and */
					/* ProIntfDataSurfaceAppend */
ProQuiltdata	*quilt_array;		/* Array of quilt data structures */
					/* Attention! Access individual data */
					/* items only through */
					/* ProIntfDataQuiltGet and */
 					/* ProIntfDataQuiltAppend */
ProEdgedata	*edge_array;		/* Array of edge data structures */
					/* Attention! Access individual data */
					/* items only through */
					/* ProIntfDataEdgeGet and */
               				/* ProIntfDataEdgeAppend */
ProDatumdata	*datum_array;		/* Array of datum data structures */
					/* Attention! Access individual data */
					/* items only through */
					/* ProIntfDataDatumGet and */
               				/* ProIntfDataDatumAppend */
} ProIntfData;

typedef enum pro_intf_data_source_type
 {
	PRO_INTF_DATA_SOURCE_NONE = 0,
	PRO_INTF_DATA_SOURCE_FILE,
	PRO_INTF_DATA_SOURCE_MEMORY
 } ProIntfDataSourceType;

typedef struct pro_intf_data_source
 {
	/* Source of data; depends on intf_type */
	ProIntfType	intf_type;
	union
	 {
		wchar_t		*filename;
		ProIntfData	*p_pro_intf_data;	/* PRO_INTF_NEUTRAL */
	 } choice;
 } ProIntfDataSource;

typedef enum pro_part_curve_conversion_option
 {
	PRO_PART_CURVES_AS_DEFAULT = 0,
	PRO_PART_SPLINES_AS_BSPLINES,
	PRO_PART_CURVES_AS_BSPLINES
 } ProPartCurveConversionOption;

typedef enum pro_part_surface_conversion_option
 {
	PRO_PART_SURFACES_AS_DEFAULT = 0,
	PRO_PART_SPL_SURFACES_AS_BSPL_SURFACES,
	PRO_PART_SURFACES_AS_BSPL_SURFACES
 } ProPartSurfaceConversionOption;

typedef struct pro_part_conversion_options
 {
	/* Method of edge representation; can be combined */
	struct
	 {
		unsigned int	uv_points:1;
		unsigned int	uv_curves:1;
		unsigned int	xyz_curve:1;
	 } edge_representation;

	ProPartCurveConversionOption	curve_representation;
	ProPartSurfaceConversionOption	surface_representation;

 } ProPartConversionOptions;

LIB_PTK_INTF_API  ProError ProIntfDataSourceInit ( ProIntfType		intf_type,
					void			*p_source,
					ProIntfDataSource	*p_pro_intf_data_source );
/*
   Purpose:	Initializes a <i>ProIntfDataSource</i> structure.

   Input Arguments:
      intf_type		- The type of interface.
      p_source		- The pointer to the data source.
			  The type of the data source depends on the type of interface.
			  The macro PRO_INTF_TYPE_TO_INTF_DATA_SOURCE_TYPE and function
			  <b>ProIntfTypeToIntfDataSourceType()</b> provide information about
			  the connection between the type of data source and type of
                          interface.

   Output Arguments:
      p_pro_intf_data_source	- The pointer to the <i>ProIntfDataSource</i>
				  to be initialized.

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully initialized
			  the <i>ProIntfDataSource</i>.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

   See Also:
      ProIntfTypeToIntfDataSourceType()
      ProIntfDataSourceClean()
*/

#define	PRO_INTF_TYPE_TO_INTF_DATA_SOURCE_TYPE( intf_type ) \
	( ( intf_type == PRO_INTF_NEUTRAL ) ? PRO_INTF_DATA_SOURCE_MEMORY \
					    : PRO_INTF_DATA_SOURCE_FILE	)

LIB_PTK_INTF_API  ProIntfDataSourceType ProIntfTypeToIntfDataSourceType ( ProIntfType intf_type );
/*
   Purpose:	Determines the type of <i>ProIntfDataSource</i> to be used,
		depending on the type of interface. This is an auxiliary
		function that helps you determine what
		kind of data source the function <b>ProIntfDataSourceInit()</b>
		expects you to pass in the argument <i>p_source</i>.

   Input Arguments:	

       intf_type         - The type of interface

   Output Arguments:

       None

   Return Values:
      ProIntfDataSourceType	- The type of <i>ProIntfDataSource</i>

   See Also:
      ProIntfDataSourceInit()
*/

LIB_PTK_INTF_API  ProError ProIntfDataAlloc ( ProIntfData **pp_intfdata );
/*
   Purpose:     Allocates memory for the interface data.

   Input Arguments:
      None

   Output Arguments:
      pp_intfdata	- The interface data structure

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully allocated memory for the data 
                             structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - The input is invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataFree ( ProIntfData *p_intfdata );
/*
   Purpose:     Frees the memory used by the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully freed the memory.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataSurfaceCount ( ProIntfData *p_intfdata,
					  int *n_surfaces );
/*
   Purpose:     Determines the number of surfaces in the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      n_surfaces	- The number of surfaces

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully evaluated the number of surfaces.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataSurfaceGet ( ProIntfData *p_intfdata,
					int index,
					ProSurfacedata **pp_surfdata );
/*
   Purpose:     Gets the specified surface from the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      index		- The index (from 0 to (<i>number - 1</i>)) of the surface in the 
                          interface data

    Output Arguments:
      pp_surfdata	- The surface. Release the memory using
                            ProSurfacedataMemoryFree

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully found the surface.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataSurfaceAppend ( ProIntfData *p_intfdata,
					   ProSurfacedata *p_surfdata );
/*
   Purpose: Appends the specified surface to the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      p_surfdata	- The surface

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully appended the surface.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataQuiltCount ( ProIntfData *p_intfdata,
					int *n_quilts );
/*
   Purpose:     Determines the number of quilts in the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      n_quilts		- The number of quilts

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully evaluated the number of quilts.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataQuiltGet ( ProIntfData *p_intfdata,
				      int index,
				      ProQuiltdata **pp_quiltdata );
/*
   Purpose:   Retrieves the specified quilt from the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      index		- The index (from 0 to (<i>number - 1</i>)) of the quilt in the interface 
                          data

   Output Arguments:
      pp_quiltdata	- The quilt. Release the memory using ProQuiltdataMemoryFree

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully found the quilt.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataQuiltAppend ( ProIntfData *p_intfdata,
					 ProQuiltdata *p_quiltdata );
/*
   Purpose:     Appends the quilt to the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      p_quiltdata	- The quilt

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully appended the quilt.
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataEdgeCount ( ProIntfData *p_intfdata,
				       int *n_edges );
/*
   Purpose:     Determines the number of edges in the interface data.
   
   Input Arguments:
      p_intfdata        - The interface data

   Output Arguments:
      n_edges           - The number of edges

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully evaluated the number of edges.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataEdgeGet ( ProIntfData *p_intfdata,
				     int index,
				     ProEdgedata **pp_edgedata );
/*
   Purpose:     Gets the specified edge from the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      index		- The index (from 0 to (<i>number - 1)</i>) of the surface in the 
                          interface data

   Output Arguments:
      pp_edgedata	- The edge. Release the memory using ProEdgedataMemoryFree

   Return Values:
      PRO_TK_NO_ERROR	   - The function successfully found the edge.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS	   - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataEdgeAppend ( ProIntfData *p_intfdata,
					ProEdgedata *p_edgedata );
/*
   Purpose:     Appends the edge to the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      p_edgedata	- The edge

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully appended the edge.
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataDatumCount ( ProIntfData *p_intfdata,
					int *n_datumobjs );
/*
   Purpose:     Determines the number of datum objects in the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      n_datumobjs	- The number of datum objects

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully evaluated the number of datum objects.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataDatumGet ( ProIntfData *p_intfdata,
				      int index,
				      ProDatumdata **pp_datumdata );
/*
   Purpose:     Gets the specified datum object from the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      index		- The index (from 0 to (<i>number - 1</i>)) of the datum object
			  in the interface data

   Output Arguments:
      pp_datumdata	- The datum object data structure. Release the memory
                            using ProDatumdataMemoryFree

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully found the datum object.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/

LIB_PTK_INTF_API  ProError ProIntfDataDatumAppend ( ProIntfData *p_intfdata,
					 ProDatumdata *p_datumdata );
/*
   Purpose: Appends the specified datum object to the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      p_datumdata	- The datum object data structure

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully appended the datum object.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProIntfDataAccuracytypeGet ( ProIntfData *p_intfdata,
					     ProAccuracytype *p_accu_type );
/*
   Purpose:     Gets the accuracy type of the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      p_accu_type	- The accuracy type

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully found the accuracy type.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProIntfDataAccuracytypeSet ( ProIntfData *p_intfdata,
					     ProAccuracytype accu_type );
/*
   Purpose:     Sets the accuracy type of the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      accu_type		- The accuracy type

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully set the accuracy type.
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

extern ProError ProIntfDataAccuracyGet ( ProIntfData *p_intfdata,
					 double *p_accuracy );
/*
   Purpose:     Gets the accuracy of the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      p_accuracy	- The accuracy

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully found the accuracy.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProIntfDataAccuracySet ( ProIntfData *p_intfdata,
					 double	accuracy );
/*
   Purpose:     Sets the accuracy of the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      accuracy		- The accuracy

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully set the accuracy.
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/

extern ProError ProIntfDataOutlineGet ( ProIntfData *p_intfdata,
					ProOutline	xyz_outline );
/*
   Purpose:     Gets the outline of the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data

   Output Arguments:
      xyz_outline	- The coordinates of box that contains the interface data

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully found the outline.
      PRO_TK_BAD_INPUTS	- The input argument is invalid.
*/

extern ProError ProIntfDataOutlineSet ( ProIntfData *p_intfdata,
					ProOutline	xyz_outline );
/*
   Purpose:     Sets the outline of the interface data.
   
   Input Arguments:
      p_intfdata	- The interface data
      xyz_outline	- The coordinates of box that contains the interface data

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully set outline.
      PRO_TK_BAD_INPUTS	- One or more of the arguments are invalid.
*/


LIB_PTK_INTF_API  ProError ProPartToProIntfData ( ProPart	ptk_part,
				       ProPartConversionOptions	*p_cnv_opts,
				       ProIntfData *p_intfdata );
/*
   Purpose:     Converts a <i>ProPart</i> structure to a <i>ProIntfData</i> structure.

   Input Arguments:
      ptk_part	        - The <i>ProPart</i> data structure.
      p_cnv_opts	- The options for the conversion.

   Output Arguments:
      p_intfdata	- The interface data. You must preallocate the memory for this 
			  argument by calling the function <b>ProIntfDataAlloc()</b>.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully converted the <i>ProPart</i> structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
      ProIntfDataAlloc()
*/

LIB_PTK_INTF_API  ProError ProIntfDataSourceClean ( ProIntfDataSource *p_pro_intf_data_source );
/*
   Purpose:	Frees allocated memory from a <i>ProIntfDataSource</i> structure.

   Input Arguments:
      p_pro_intf_data_source	- The pointer to the <i>ProIntfDataSource</i>
				  to be cleaned.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR	- The function successfully cleaned
			  the <i>ProIntfDataSource</i>.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

   See Also:
      ProIntfDataSourceInit()
*/

PRO_END_C_DECLS

#endif /* PROINTFDATA_H */
