
#ifndef PROPDFH
#define PROPDFH

#include <ProToolkit.h>
#include <ProWchar.h>

PRO_BEGIN_C_DECLS

typedef struct _pdfconfig* ProPDFOptions;

typedef enum
{
    PRO_PDF_ARCHIVE_1 ,    /* ONLY for PRO_PDF_2D_DRAWING
                              Forces the following:
                              ProPDFLayerMode will be forced to PRO_PDF_LAYERS_NONE, 
                              PRO_PDFOPT_HYPERLINKS will be forced to FALSE
                              Shaded views will not have Transparency and may overlap other data
                              PRO_PDFOPT_PASSWORD_TO_OPEN = NULL,
                              PRO_PDFOPT_MASTER_PASSWORD = NULL
                           */
    PRO_PDF_FULL           /* default */ 
} ProPDFSaveMode;

typedef enum
{
    PRO_PDF_EXCLUDE_ANNOTATION, /*Use PRO_PDFOPT_INCL_ANNOT option to include or 
                                exclude annotation while exporting to PDF U3D.
                                Use PRO_PDF_INCLUDE_ANNOTATION to include annotation. 
                                Use PRO_PDF_EXCLUDE_ANNOTATION to exclude annotation.
	                            If no option is used, PRO_PDF_EXCLUDE_ANNOTATION is default*/                 
    
  	PRO_PDF_INCLUDE_ANNOTATION  /*Use PRO_PDF_INCLUDE_ANNOTATION to include annotation*/  
} ProPDFAnnotMode;

typedef enum
{
    PRO_PDF_STROKE_ALL_FONTS,
    PRO_PDF_USE_TRUE_TYPE_FONTS,
    PRO_PDF_STROKE_NON_TTF_FONTS  /* Reserved for internal use */
} ProPDFFontStrokeMode;

typedef enum
{
    PRO_PDF_CD_COLOR,
    PRO_PDF_CD_GRAY,
    PRO_PDF_CD_MONO
} ProPDFColorDepth;

typedef enum
{
    PRO_PDF_HLM_SOLID,
    PRO_PDF_HLM_DASHED
} ProPDFHiddenLineMode;

typedef enum
{
    PRO_PDF_PRINTING_LOW_RES,
    PRO_PDF_PRINTING_HIGH_RES
} ProPDFPrintingMode;

typedef enum
{
    PRO_PDF_LAYERS_ALL,
    PRO_PDF_LAYERS_VISIBLE,
    PRO_PDF_LAYERS_NONE
} ProPDFLayerMode;

typedef enum
{
    PRO_PDF_PARAMS_ALL,
    PRO_PDF_PARAMS_DESIGNATED,
    PRO_PDF_PARAMS_NONE
} ProPDFParameterMode;

typedef enum
{
    PRO_PDF_RESTRICT_NONE,
    PRO_PDF_RESTRICT_FORMS_SIGNING,
    PRO_PDF_RESTRICT_INSERT_DELETE_ROTATE,
    PRO_PDF_RESTRICT_COMMENT_FORM_SIGNING,
    PRO_PDF_RESTRICT_EXTRACTING
} ProPDFRestrictOperationsMode;

typedef enum
{
	PRO_PDF_LINECAP_BUTT,
	PRO_PDF_LINECAP_ROUND,
	PRO_PDF_LINECAP_PROJECTING_SQUARE
} ProPDFLinecap;

typedef enum
{
	PRO_PDF_LINEJOIN_MITER,
	PRO_PDF_LINEJOIN_ROUND,
	PRO_PDF_LINEJOIN_BEVEL
} ProPDFLinejoin;

typedef enum
{
	PRO_PDF_2D_DRAWING,
	PRO_PDF_3D_AS_NAMED_VIEWS,
	PRO_PDF_3D_AS_U3D_PDF,
	PRO_PDF_3D_AS_U3D /* Ignores PRO_PDFOPT values; output is *.u3d file  */
} ProPDFExportMode;

typedef enum
{
   PRO_PDF_U3D_LIGHT_NONE,
   PRO_PDF_U3D_LIGHT_WHITE,
   PRO_PDF_U3D_LIGHT_DAY,
   PRO_PDF_U3D_LIGHT_BRIGHT,
   PRO_PDF_U3D_LIGHT_PRIMARY,
   PRO_PDF_U3D_LIGHT_NIGHT,
   PRO_PDF_U3D_LIGHT_BLUE,
   PRO_PDF_U3D_LIGHT_RED,
   PRO_PDF_U3D_LIGHT_CUBE,
   PRO_PDF_U3D_LIGHT_CAD,
   PRO_PDF_U3D_LIGHT_HEADLAMP
} ProPDFU3DLightingMode;

typedef enum
{
   PRO_PDF_U3D_RENDER_BOUNDING_BOX,
   PRO_PDF_U3D_RENDER_TRANSPARENT_BOUNDING_BOX,
   PRO_PDF_U3D_RENDER_TRANSPARENT_BOUNDING_BOX_OUTLINE,
   PRO_PDF_U3D_RENDER_VERTICES,
   PRO_PDF_U3D_RENDER_SHADED_VERTICES,
   PRO_PDF_U3D_RENDER_WIREFRAME,
   PRO_PDF_U3D_RENDER_SHADED_WIREFRAME,
   PRO_PDF_U3D_RENDER_SOLID,
   PRO_PDF_U3D_RENDER_TRANSPARENT,
   PRO_PDF_U3D_RENDER_SOLID_WIREFRAME,
   PRO_PDF_U3D_RENDER_TRANSPARENT_WIREFRAME,
   PRO_PDF_U3D_RENDER_ILLUSTRATION,
   PRO_PDF_U3D_RENDER_SOLID_OUTLINE,
   PRO_PDF_U3D_RENDER_SHADED_ILLUSTRATION,
   PRO_PDF_U3D_RENDER_HIDDEN_WIREFRAME
} ProPDFU3DRenderMode;

typedef enum
{
   PRO_PDF_VIEW_SELECT_CURRENT,
   PRO_PDF_VIEW_SELECT_ALL,
   PRO_PDF_VIEW_SELECT_BY_NAME
} ProPDFSelectedViewMode;

typedef enum
{
	PRO_PDFOPT_FONT_STROKE,                /* Enum, ProPDFFontStrokeMode, 
										      default PRO_PDF_USE_TRUETYPE_FONTS */
	PRO_PDFOPT_COLOR_DEPTH,                /* Enum, ProPDFColorDepth,
										      default PRO_PDF_CD_COLOR */
	PRO_PDFOPT_HIDDENLINE_MODE,            /* Enum, ProPDFHiddenLineMode,
										      default PRO_PDF_HLM_DASHED */
	PRO_PDFOPT_SEARCHABLE_TEXT,            /* Boolean, default TRUE */
	PRO_PDFOPT_RASTER_DPI,                 /* Int, Range 100 - 600, default 300 */
	PRO_PDFOPT_LAUNCH_VIEWER,              /* Boolean, default TRUE */
	PRO_PDFOPT_LAYER_MODE,                 /* Enum, ProPDFLayerMode,
										      default PRO_PDF_LAYERS_ALL */
	PRO_PDFOPT_PARAM_MODE,                 /* Enum, ProPDFParamMode,
										      default PRO_PDF_PARAMS_ALL */
	PRO_PDFOPT_HYPERLINKS,                 /* Boolean, default TRUE */
	PRO_PDFOPT_BOOKMARK_ZONES,             /* Boolean, default TRUE */
	PRO_PDFOPT_BOOKMARK_VIEWS,             /* Boolean, default TRUE */
	PRO_PDFOPT_BOOKMARK_SHEETS,            /* Boolean, default TRUE */
	PRO_PDFOPT_BOOKMARK_FLAG_NOTES,        /* Boolean, default TRUE */
	PRO_PDFOPT_TITLE,                      /* String, default "" */
	PRO_PDFOPT_AUTHOR,                     /* String, default <current user name> */
	PRO_PDFOPT_SUBJECT,                    /* String, default "" */
	PRO_PDFOPT_KEYWORDS,                   /* String, default "" */
	PRO_PDFOPT_PASSWORD_TO_OPEN,           /* String, default NULL, which means that 
					                          the document may be opened by anyone */
	PRO_PDFOPT_MASTER_PASSWORD,            /* String, default NULL,
										      which means that anyone may perform 
											  any change regardless
                                              of any of the modification flags 
											  PRO_PDFOPT_ALLOW_* listed below */
    PRO_PDFOPT_RESTRICT_OPERATIONS,        /* Boolean, default FALSE
                                              set to TRUE to use PRO_PDFOPT_ALLOW_*
	                                          to use ProPDFRestrictOperationsMode */
	PRO_PDFOPT_ALLOW_PRINTING,             /* Boolean, default TRUE */
	PRO_PDFOPT_ALLOW_PRINTING_MODE,        /* Enum, ProPDFPrintingMode,
	                                          default PRO_PDF_PRINTING_HIGH_RES */
	PRO_PDFOPT_ALLOW_MODE,                 /* Enum, ProPDFRestrictOperationsMode,
                                              default PRO_PDF_RESTRICT_NONE */
	PRO_PDFOPT_ALLOW_COPYING,              /* Boolean, default TRUE */
	PRO_PDFOPT_ALLOW_ACCESSIBILITY,        /* Boolean, default TRUE
                                              allows visually impaired screen reader
                                              devices to extract data independent of
                                              RestrictOperationsMode */
	PRO_PDFOPT_PENTABLE,                   /* Boolean, default FALSE */
	PRO_PDFOPT_LINECAP,                    /* Enum, ProPDFLinecap
	                                          default PRO_PDF_LINECAP_BUTT */
	PRO_PDFOPT_LINEJOIN,                   /* Enum, ProPDFLinejoin
	                                          default PRO_PDF_LINEJOIN_MITER */
	PRO_PDFOPT_SHEETS,                     /* Enum, ProPrintSheets
	                                          default PRINT_ALL_SHEETS 
	                                          which sheets to export; (see ProPrint.h) */
	PRO_PDFOPT_SHEET_RANGE,                /* String, overrides PRO_PDFOPT_SHEETS
	                                          to PRINT_SELECTED_SHEETS */
	PRO_PDFOPT_EXPORT_MODE,                /* Enum, ProPDFExportMode
                                              default PRO_PDF_2D_DRAWING; */
    PRO_PDFOPT_LIGHT_DEFAULT,              /* Enum, ProPDFU3DLightingMode
                                              default PRO_PDF_U3D_LIGHT_CAD
                                              - only valid for PRO_PDF_3D_AS_U3D */
	PRO_PDFOPT_RENDER_STYLE_DEFAULT,       /* Enum, ProPDFU3DRenderMode
                                              default PRO_PDF_U3D_RENDER_SOLID
                                              - only valid for PRO_PDF_3D_AS_U3D */
	PRO_PDFOPT_SIZE,					   /* Enum, ProPlotPaperSize, (see ProUtil.h)
	                                          default A_SIZE_PLOT 
	                                          usage of VARIABLE_SIZE_PLOT:
	                                          usage of VARIABLE_SIZE_IN_MM_PLOT:
	                                          set height, width and orientation below */
	PRO_PDFOPT_HEIGHT,                     /* Double, default . Used only if 
	                                          PRO_PDFOPT_SIZE is VARIABLE_SIZE_PLOT */
	PRO_PDFOPT_WIDTH,                      /* Double, default . Used only if
	                                          PRO_PDFOPT_SIZE is VARIABLE_SIZE_PLOT */
	PRO_PDFOPT_ORIENTATION,                /* Enum, ProSheetOrientation, (see ProDrawing.h)
	                                          default PRO_ORIENTATION_PORTRAIT */

	PRO_PDFOPT_TOP_MARGIN,                 /* Double, default 0.0 */
	PRO_PDFOPT_LEFT_MARGIN,                /* Double, default 0.0 */
	PRO_PDFOPT_BACKGROUND_COLOR_RED,       /* Double, default 1.0; range 0.0, 1.0 */
	PRO_PDFOPT_BACKGROUND_COLOR_GREEN,     /* Double, default 1.0; range 0.0, 1.0 */
	PRO_PDFOPT_BACKGROUND_COLOR_BLUE,      /* Double, default 1.0; range 0.0, 1.0 */
	PRO_PDFOPT_ADD_VIEWS,                  /* Boolean, default TRUE */
	PRO_PDFOPT_VIEW_TO_EXPORT,             /* Enum ProPDFSelectedViewMode
	                                          default PRO_PDF_VIEW_SELECT_ALL */
	PRO_PDFOPT_SELECTED_VIEW,              /* String, default "". Sets
	                                          PRO_PDFOPT_VIEW_TO_EXPORT to
	                                          PRO_PDF_VIEW_SELECT_BY_NAME if 
	                                          Successful in finding view */
    PRO_PDFOPT_PDF_SAVE,                    /* Enum ProPDFSaveMode
										      default PRO_PDF_FULL */
	PRO_PDFOPT_INCL_ANNOT					/*To include annotation while exporting to PDF U3D 
											Use ProPDFAnnotMode as the option value. 
											Default is PRO_PDF_EXCLUDE_ANNOTATION */

} ProPDFOptionType;

extern ProError ProPDFExport (ProMdl model,  ProPath output_file, ProPDFOptions options);
/*
	Purpose: Exports a file to PDF format.

	Input Arguments:
		model       - The model to export.  The model must be displayed in 
                      a window.  This model must be loaded.
		output_file - The full path to the output file, including 
                      the extension.
		options     - The options used to generate the PDF file.

	Output Arguments:
	    none

	Return Values: 
	    PRO_TK_NO_ERROR      - The function succeeded.
		PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE  - Invalid model type specified.
		PRO_TK_NOT_DISPLAYED - Model not displayed
		PRO_TK_CANT_WRITE    - Cannot find or write to the directory specified.
		PRO_TK_NO_LICENSE    - License for PDF export is not available.
		PRO_TK_GENERAL_ERROR - Error occured while processing PDF creation.
		PRO_TK_UNSUPPORTED   - Support not available on this platform.
		PRO_TK_NO_PERMISSION - The function does not have permission to operate
			   		           on this model.
		PRO_TK_BAD_CONTEXT   - PRO_PDF_ARCHIVE_1 passed for non 2D drawing export
                		       and/or Design Test Mode is active - The function is 
                                       not available in this mode.
*/

extern ProError ProPDFWithProfileExport (ProMdl model,  
                                         ProPath output_file, 
                                         ProPath profile);
/*
	Purpose: Exports a file to PDF format using profile.
	Input Arguments:
		model          - The model to export.  
                         The model must be displayed in
                         a window.  Currently, this model   
                         must be a drawing.
                         This model must be loaded.
		output_file    - The full path to the output file, 
                         including the extension.
		profile        - profile path.
	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE  - Invalid model type specified.
        PRO_TK_NOT_DISPLAYED - Model not displayed
        PRO_TK_CANT_WRITE    - Cannot find or write to the directory specified.
        PRO_TK_NO_LICENSE    - License for PDF export is not available.
        PRO_TK_GENERAL_ERROR - Error occurred while processing PDF creation.
		PRO_TK_UNSUPPORTED   - Support not available on this platform.
		PRO_TK_NOT_EXIST     - No profile found. 
                               (For NULL profile returns PRO_TK_BAD_INPUTS.)
		PRO_TK_INVALID_FILE  - profile is not readable.
		PRO_TK_BAD_CONTEXT   - PRO_PDF_ARCHIVE_1 passed for non 2D drawing export.
*/

extern ProError ProPDFoptionsAlloc (ProPDFOptions* options);
/*
	Purpose: Allocates a PDF options structure.

	Input Arguments:
		none

	Output Arguments:
	    options - The structure to be allocated.

	Return Values: 
	    PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProPDFoptionsIntpropertySet (ProPDFOptions options, ProPDFOptionType type, int value);
/*
	Purpose: Sets the value for an integer or enum property to the PDF options structure.

	Input Arguments:
		options - The options structure.
		type -    The option type.
		value -   The option value.

	Output Arguments:
	    none

	Return Values: 
	    PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - This option type is not an integer value type.
*/

extern ProError ProPDFoptionsBoolpropertySet (ProPDFOptions options, ProPDFOptionType type, ProBoolean value);
/*
	Purpose: Sets the value for a boolean property to the PDF options structure.

	Input Arguments:
		options - The options structure.
		type -    The option type.
		value -   The option value.

	Output Arguments:
	    none

	Return Values: 
	    PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - This option type is not a boolean value type.
*/

extern ProError ProPDFoptionsStringpropertySet (ProPDFOptions options, ProPDFOptionType type, wchar_t* value);
/*
	Purpose: Sets the value for a string property to the PDF options structure.

	Input Arguments:
		options - The options structure.
		type -    The option type.
		value -   The option value.  Can be NULL.

	Output Arguments:
	    none

	Return Values: 
	    PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - This option type is not a string value type.
*/

extern ProError ProPDFoptionsDoublepropertySet(ProPDFOptions options, ProPDFOptionType type,double value);
/*
	Purpose: Sets the value for a double property to the PDF options structure.
	
	Input Arguments:
		options - The options structure.
		type -    The option type.
		value -   The option value.

	Output Arguments:
		none

	Return Values:
		PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
		PRO_TK_INVALID_TYPE - This option type is not a double value type.
*/

extern ProError ProPDFoptionsFree (ProPDFOptions options);
/*
	Purpose: Frees a PDF options structure.

	Input Arguments:
		options - The structure to be allocated.

	Output Arguments:
	    none

	Return Values: 
	    PRO_TK_NO_ERROR - The function succeeded.
		PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/
PRO_END_C_DECLS

#endif /* PROPDFH */

