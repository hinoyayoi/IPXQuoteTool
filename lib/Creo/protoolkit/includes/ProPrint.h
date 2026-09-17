

#ifndef PROPRINT_H
#define PROPRINT_H

#include <ProUtil.h>

typedef struct pro_print_size
{
  ProPlotPaperSize size;    /* A_SIZE_PLOT, VARIABLE_SIZE_PLOT, etc */
  double  width;            /* In inches, if size == VARIABLE_SIZE_PLOT */
  double  height;           /* In inches, if size == VARIABLE_SIZE_PLOT */
} ProPrintSize;

typedef enum
{
  PRINT_SAVE_NULL = 0,
  PRINT_SAVE_SINGLE_FILE,
  PRINT_SAVE_MULTIPLE_FILE,
  PRINT_SAVE_APPEND_TO_FILE
} ProPrintSaveMethod;
 
typedef enum
{
  PRINT_CURRENT_SHEET = 0,
  PRINT_ALL_SHEETS,
  PRINT_SELECTED_SHEETS
} ProPrintSheets;

/* ================================================================
 Printer Options : setup the printer
 ================================================================= */
typedef struct _prnprinter
{
  ProCharName printer_type;             /* POSTSCRIPT: generic postscript 
                                           COLORPOSTSC: color postscript 
                                           MS_PRINT_MGR: MS Print Manager 
                                           c.f. the list in Add Printer */ 
  /* --- File related options --- */
  ProBoolean         save_to_file;      /* save the plot to file */
  ProPrintSaveMethod save_method;       /* Append, single or multiple file */
  ProPath            filename;
  ProBoolean         delete_after;      /* file is deleted after print command
                                           is executed */
 
  /* --- Print command options --- */
  ProBoolean     send_to_printer;       /* Send the plot to printer directly */
  ProPath        print_command;         /* command to print */
 
  ProPath        pen_table;             /* file containing pen table */
 
  ProPrintSize   paper_size;            /* Size of the paper to be printed */
 
  int            quantity;              /* how many copies */
 
  /* --- Printer specific options --- */
  ProBoolean     sw_handshake;          /* TRUE: software, FALSE: hardware */
  ProBoolean     roll_media;            /* TRUE: roll-media, FALSE: cut sheet */
  ProBoolean     use_ttf;               /* TRUE: use TTF, FALSE: stroke text  */
  double         slew;                  /* velocity in x and y directions */
  ProBoolean     rotate_plot;           /* rotate plot 90 degrees */
 
} ProPrintPrinterOpts;
 
/* ================================================================
 Model Options : setup the model
 ================================================================= */
typedef struct _prnobject
{
  ProMdl         mdl;                   /* model to be printed */
 
  int            quality;               /* 0 (No line check)
                                           1 (No overlap check)
                                           2 (Simple overlap check)
                                           3 (Complex overlap check) */
 
  /* --- Options available only with solid objects --- */
  ProBoolean     use_solid_scale;       /* Print using solid scale */
 
  /* --- Options available only with drawing objects --- */
  ProBoolean     use_drawing_size;      /* override paper_size in
					 ProPrintPrinterOptions
                                         with the size of the drawing */
  ProBoolean     draw_format;           /* Drawing format is also printed */
  
  ProBoolean     segmented;             /* Segmented plots of the drawing  
					   Allowed to be PRO_B_TRUE only if 
					   plotting a single page  */
 
  ProBoolean     layer_only;            /* Print only a particular layer */
  ProName        layer_name;            /* name of the layer */
 
  ProPrintSheets sheets;
  int            range[2];              /* start and end sheets of a drawing */
 
} ProPrintMdlOpts;
 
/* ================================================================
 Placement Options : setup the object placement
 ================================================================= */
typedef struct _prnplacement
{
  double     scale;
  double     offset[2];           /* Offset from lower-left corner of the plot
                                     (in inches) */
 
  ProBoolean keep_panzoom;        /* maintain window panzoom */
 
  /* --- options for clipping --- */
  ProBoolean clip_plot;           /* whether or not we want to clip the plot */
  ProBoolean shift_to_ll_corner;  /* shift the clip area to lower-left corner */
  double     clip_area[2][2];     /* range is from 0.0 to 1.0 */
 
  /* --- options for label --- */
  ProBoolean place_label;
  double     label_height;        /* in inches */
 
} ProPrintPlacementOpts;

/*===========================================================================*/
 
PRO_BEGIN_C_DECLS

extern ProError ProPrintPrinterOptionsGet(ProCharName printer_type,
                                          ProPrintPrinterOpts *options);

/*
 
  Purpose: Get printer options for a specified printer
 
  Input Arguments:
     printer_type    - Name of the printer type.
 
  Output Arguments:
     options         - Initialized printer options
 
  Return Values:
     PRO_TK_NO_ERROR     - The function completed successfully.
     PRO_TK_BAD_INPUTS   - One or more arguments is bad.
     PRO_TK_E_NOT_FOUND  - The printer type was not recognized
 
*/

extern ProError ProPrintMdlOptionsGet(ProMdl model,
				      ProPrintMdlOpts *options);

/*
 
  Purpose: Get model options for a specified model
 
  Input Arguments:
     model   - Model
 
  Output Arguments:
     options - Initialized model options
 
  Return Values:
     PRO_TK_NO_ERROR
     PRO_TK_BAD_INPUTS
 
*/

extern ProError ProPrintPlacementOptionsGet(ProPrintPlacementOpts *options);

/*
 
  Purpose: Get the current print placement options 
 
  Input Arguments:
     None
 
  Output Arguments:
     options - Initialized placement options
 
  Return Values:
     PRO_TK_NO_ERROR
*/

extern ProError ProPrintPCFOptionsGet(ProPath pcf_filename, ProMdl model,
				      ProPrintPrinterOpts *printer_options,
				      ProPrintMdlOpts *mdl_options,
				      ProPrintPlacementOpts *place_options);

/*
 
  Purpose: Get the print options from a specified PCF file.
 
  Input Arguments:
    pcf_filename        - The name of the PCF file
    model               - Model to be printed
 
  Output Arguments:
    printer_options     - The printer options
    mdl_options         - The model options
    place_options       - The placement options
 
  Return Values:
    PRO_TK_NO_ERROR
    PRO_TK_E_NOT_FOUND  - The PCF file does not exist
    PRO_TK_BAD_INPUTS
 
*/

extern ProError ProPrintExecute(int window_id,
                                ProPrintPrinterOpts *printer_options,
			        ProPrintMdlOpts *mdl_options,
			        ProPrintPlacementOpts *place_options);

/*
 
  Purpose: Print a window using the specified options
            <P> The mdl in the window must match the mdl in mdl_options.
	    <P> All the options should be first initialized by the
		apropriate ProPrintInit functions above.
            <P> The filename must contain the full path or be the name of
		a file in plot_dir or current directory. If file already
		exists there, it will be overwritten.
	    <P> The mdl in the the mdl_options should be the object loaded
                to the window to be printed. The window can be a non-graphics
                window.
	    <P> This function generates a wireframe plot of the object in
	        either vector or raster format.
            <P> The correct ProPrintExecute printer_type is defined by the
                plotter value on the first line of the plotter configuration
                file. This file is available in the
                <Creo Parametric Load Point>/text/plot_config folder.
                For the list of supported printers, please refer to the list
                in "Add Printer" in Creo Parametric's print dialog. </P>
 

  Input Arguments:
    window_id           - The handle to the Creo Parametric window
    printer_options     - The printer options
    mdl_options         - The model options
    place_options       - The placement options
 
  Output Arguments:
    none
 
  Return Values:
    PRO_TK_NO_ERROR      - Window printed successfully
    PRO_TK_BAD_INPUTS    - One or more arguments is bad
    PRO_TK_BAD_CONTEXT   - Print is not available in Design Test mode
    PRO_TK_E_NOT_FOUND   - Incomplete input data 
    PRO_TK_GENERAL_ERROR - Problem during data conversion
    PRO_TK_INVALID_NAME  - Wrong file name
    PRO_TK_CANT_WRITE    - No write access for target file
 
*/

PRO_END_C_DECLS
 
#endif  /* PROPRINT_H */

