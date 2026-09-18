

#ifndef PROUTIL_H
#define PROUTIL_H

#include <ProToolkit.h>
#include <ProSizeConst.h>
#include <ProObjects.h>
#include <ProMdl.h>
#include <ProWchar.h>
#include <ProArray.h>

typedef struct
{
   double xoffset;       /* valid values are b/w 0.0 and 1.0 */
   double yoffset;       /* valid values are b/w 0.0 and 1.0 */
} ProInfoWindowLocation;

typedef struct
{
   int rows;             /* valid values are b/w 6 & 33 */
   int columns;          /* valid values are b/w 8 and 80 */
} ProInfoWindowSize;

typedef enum
{
   A_SIZE_PLOT         =   0,
   B_SIZE_PLOT         =   1,
   C_SIZE_PLOT         =   2,
   D_SIZE_PLOT         =   3,
   E_SIZE_PLOT         =   4,
   A4_SIZE_PLOT        =   5,
   A3_SIZE_PLOT        =   6,
   A2_SIZE_PLOT        =   7,
   A1_SIZE_PLOT        =   8,
   A0_SIZE_PLOT        =   9,
   F_SIZE_PLOT         =  10,
   CE_EMPTY_PLOT       =  11,
   CE_EMPTY_PLOT_MM    =  12,
   VARIABLE_SIZE_IN_MM_PLOT = 99,  /* Use this when you are using mm units */
   VARIABLE_SIZE_PLOT  = 100       /* Use this when you are using Inch units */
} ProPlotPaperSize;



typedef struct pro_plot_options
{
  ProCharName plotter_name;    /* c.f. The print dialog for support names  
                                eg: POSTSCRIPT, COLORPOSTSC
                                Note: MS_PRINT_MGR is not supported */
  ProPlotPaperSize paper_size; /* A_SIZE_PLOT, ... VARIABLE_SIZE_PLOT, above */
  double paper_size_xy[2];     /* X, Y paper dimensions */
                               /* only for variable paper size */

  int output_quality;          /* integer range [1 - 3] */
  double user_scale;           /* a positive non-zero numeric value */
  int pen_slew;                /* 1 No pen slew; 2 Slew */
  double pen_velocity[2];      /* X, then Y pen velocity  */
  int page_range_choice;       /* Drawings */
                               /* 1 - ALL, 2 - Current, 3 - Range of pages */

  int page_range[2];           /* rage: 1 - 99 */
  int segmented_output;        /* If output is larger than paper */
                               /* PRO_YES/NO_TYPE */
  /* Note:  this option may only be set to YES if plotting a single page.  */

  int label_plot;              /* PRO_YES/NO_TYPE */
  int separate_plot_files;     /* if multiple sheets;  PRO_YES/NO_TYPE */
} ProPlotOptions;


typedef   void *    Pro2dExportdata;

typedef struct pro_productview_export_options* ProProductviewExportOptions;

typedef enum
{
   PRO_PV_FORMAT_PVS          = 1,
   PRO_PV_FORMAT_ED           = 2,
   PRO_PV_FORMAT_EDZ          = 3,
   PRO_PV_FORMAT_PVZ          = 4
} ProProductviewFormat;    /* Creo Parametric to Creo View Export Format Types */

typedef enum
{
   PRO_UNDEFINED_FILE          =  -1,
   PRO_RELATION_FILE           =   1,                 /* Import & Export */
   PRO_IGES_SECTION            =   2,                 /* Import */
   PRO_FEATURE_INFO            =   3,                 /* Export */
   PRO_MODEL_INFO              =   PRO_FEATURE_INFO,  /* Export */
   PRO_PROGRAM_FILE            =   4,                 /* Import & Export */
   PRO_CONFIG_FILE             =   5,                 /* Import */
   PRO_TABLE_FILE              =   6,                 /* N/A */
   PRO_ASCII_FILE              =   7,                 /* N/A */
   PRO_IGES_FILE               =   8,                 /* Import & Export */
   PRO_DXF_FILE                =   9,                 /* Import & Export */
   PRO_RENDER_FILE             =  10,                 /* Export */
   PRO_SLA_ASCII_FILE          =  11,                 /* Export */
   PRO_SLA_BINARY_FILE         =  12,                 /* Export */
   PRO_CATIAFACETS_FILE        =  13,                 /* Export */
   PRO_BOM_FILE                =  14,                 /* Export */
   PRO_DWG_SETUP_FILE          =  15,                 /* Import & Export */
   PRO_FEAT_INFO               =  16,                 /* Export */
   PRO_SPOOL_FILE              =  17,                 /* Import */
   PRO_MFG_OPER_CL             =  18,                 /* Export */
   PRO_MFG_FEAT_CL             =  19,                 /* Export */
   PRO_MATERIAL_FILE           =  20,                 /* Export */
   PRO_IGES_3D_FILE            =  21,                 /* Export */
   PRO_STEP_FILE               =  22,                 /* Import & Export */
   PRO_VDA_FILE                =  23,                 /* Export */
   PRO_SET_FILE                =  24,                 /* Import & Export */ /* This type is obsolete.*/
   PRO_CGM_FILE                =  25,                 /* Export */
   PRO_INVENTOR_FILE           =  26,                 /* Export */
   PRO_FIAT_FILE               =  27,                 /* Export */
   PRO_CONNECTOR_PARAMS_FILE   =  28,                 /* Export */
   PRO_CATIA_FILE              =  29,                 /* Export */  /* This type is obsolete.*/
   PRO_CABLE_PARAMS_FILE       =  30,                 /* Export */
   PRO_ASSEM_TREE_CFG_FILE     =  31,                 /* Import */
   PRO_OPTEGRA_VIS_FILE        =  32,              /* Export supported through*/
                                               /*ProIntfSliceFileExport() only*/
   PRO_WIRELIST_FILE           =  33,                 /* Import */
   PRO_DWG_FILE                =  34,                 /* Import & Export */ 
   PRO_OPTEGRA_VIS_BINARY_FILE =  35,                 /* Export */
   PRO_ACIS_FILE               =  36,                 /* Export */
   PRO_CATIA_DIRECT_FILE       =  37,                 /* Export */
   PRO_MEDUSA_FILE             =  38,                 /* Export & Import */
   PRO_DIFF_REPORT_FILE        =  39,                 /* Export */
   PRO_STHENO_FILE             =  40,                 /* Export */
   PRO_SNAP_TIFF_FILE          =  41,                 /* Export */ 
   PRO_CCD_DRAWING_FILE        =  42,                 /* Import, CoCreate Drafting drawing */
   PRO_AMF_FILE                =  43                  /* Export */
} ProImportExportFile;

typedef enum
{
   PRO_CADAM_FILE              =  35,                /* Import */ /* Reserved for internal use */
   PRO_CADAM_DIRECT_FILE       =  36,                /* Import */ /* Reserved for internal use */
   PRO_CADAM_CPTR_FILE         =  37                 /* Import */ /* Reserved for internal use */
} ProImportCadam ;

typedef enum
{
    PRORASTERDEPTH_8  = 1,
    PRORASTERDEPTH_24 = 2
} ProRasterDepth;

typedef enum {
   PRORASTERTYPE_BMP,
   PRORASTERTYPE_TIFF,
   PRORASTERTYPE_EPS,
   PRORASTERTYPE_JPEG
} ProRasterType;

typedef enum {
   PRORASTERDPI_100 = 100,
   PRORASTERDPI_200 = 200,
   PRORASTERDPI_300 = 300,
   PRORASTERDPI_400 = 400,
   PRORASTERDPI_500 = 500,
   PRORASTERDPI_600 = 600
} ProDotsPerInch;

typedef enum
{
PRO2DEXPORT_CURRENT_TO_MODEL_SPACE,   /* Default , export only the drawing's
                                         current sheet  to model space */
PRO2DEXPORT_CURRENT_TO_PAPER_SPACE, /* Export only the drawing's current 
                                       sheet to paper space.
                                       This is the same as 
                                       PRO2DEXPORT_CURRENT_TO_MODEL_SPACE for 
                                       formats which do not support the concept
                                       of model and paper space. */
PRO2DEXPORT_ALL,      /* Export all sheets to single file (as paper space, 
                         if applicable to that format type). */
PRO2DEXPORT_SELECTED   /* Export selected sheets to the file as paper space (set
                          using Pro2dExportdataSheetsSet()), and/or one sheet to
                          model space (set using 
                          Pro2dExportdataModelspacesheetSet()). */
} Pro2dExportSheetOption;

typedef enum {
   PROCGMTYPE_CLEAR_TEXT = 1,
   PROCGMTYPE_MIL_SPEC,
   PROCGMTYPE_ABSTRACT,
   PROCGMTYPE_METRIC
} ProCGMType;

/*===========================================================================*/

PRO_BEGIN_C_DECLS

LIB_COREUTILS_API  ProError ProConfigoptSet (ProName option,
                                      ProPath option_value );

/*

  Purpose: Sets the value of the specified configuration file option.
           If the option is a multi-string option (e.g. search_path)
           the function adds a new entry for this option without modifying
           existing entries.

  Input Arguments:
     option         - The keyword string. This can include uppercase
                      and lowercase letters.
     option_value   - The value of the keyword string, as it must appear
                      in the configuration file.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR     - The function successfully set the value.
     PRO_TK_E_NOT_FOUND  - The specified option was not found.
     PRO_TK_BAD_INPUTS   - You cannot set the specified option.

*/

LIB_COREUTILS_API  ProError ProConfigoptGet (ProName option,
                                 ProLine option_value );
/*
   DEPRECATED: Since Creo 4
   SUCCESSORS: ProConfigoptionGet
  Purpose: Retrieves the current value for the specified configuration
           file option. This function truncates the results of the query
           to PRO_LINE_SIZE-1 characters. <p><b>Note: </b>While retrieving
           the value of an option that may have multiple values, use 
           ProConfigoptArrayGet() instead of this function. To get the
           value of an option with path-length string, use ProConfigoptionGet().

  Input Arguments:
     option       - The keyword string. This can include uppercase and
                    lowercase letters.

  Output Arguments:
     option_value - The value of the keyword string, as it appears in
                    the configuration file. 

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully retrieved
                             the information.
     PRO_TK_BAD_INPUTS     - Either the specified option or the option
                             value is NULL.
     PRO_TK_E_NOT_FOUND    - The specified option was not found.
     PRO_TK_LINE_TOO_LONG  - The function returned the option value,
                             but the option is longer than the
                             maximum <i>ProLine</i>.

*/

LIB_COREUTILS_API  ProError ProConfigoptionGet (ProName option,
                                 ProPath option_value );
/*

  Purpose: Retrieves the current value for the specified configuration
           file option. This function truncates the results of the query
           to PRO_PATH_SIZE-1 characters. <p><b>Note: </b>While retrieving
           the value of an option that may have multiple values, use 
           ProConfigoptArrayGet() instead of this function.

  Input Arguments:
     option       - The keyword string. This can include uppercase and
                    lowercase letters.

  Output Arguments:
     option_value - The value of the keyword string, as it appears in
                    the configuration file. 

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully retrieved
                             the information.
     PRO_TK_BAD_INPUTS     - Either the specified option or the option
                             value is NULL.
     PRO_TK_E_NOT_FOUND    - The specified option was not found.
     PRO_TK_LINE_TOO_LONG  - The function returned the option value,
                             but the option is longer than the
                             maximum <i>ProPath</i>.

*/

LIB_COREUTILS_API  ProError  ProConfigoptArrayGet (ProName option, ProPath** value_array);
/*

  Purpose: Retrieves the current value for the specified configuration file
           option. This function supports multi-string options
           (e.g. search_path). <p><b>Note: </b>Use this function instead of
           ProConfigoptGet() while retrieving the value of an option that may
           have multiple values or a path-length string.

  Input Arguments:
     option       - The keyword string. This can include uppercase and
                    lowercase letters.

  Output Arguments:
     value_array - The option value(s), in a ProArray. The function allocates
                    this array, free it with ProArrayFree().

  Return Values:
     PRO_TK_NO_ERROR       - The function successfully retrieved
                             the information.
     PRO_TK_BAD_INPUTS     - The arguments provided are invalid.
     PRO_TK_E_NOT_FOUND    - The specified option was not found.
     PRO_TK_LINE_TOO_LONG  - The function returned the option value,
                             but the option is longer than the
                             maximum <i>ProPath</i>.

*/

extern ProError ProInfoWindowDisplay ( ProPath file_name,
                                       ProInfoWindowLocation* location,
                                       ProInfoWindowSize* size );
/*
   Purpose:  Creates a window and shows the text of the file 
             specified by <i>file_name</i>.
<p>
             NOTE: 
<p>
             On UNIX machines, file names are case sensitive.

   Input Arguments:
      file_name - The file name.  The name can include the directory
                  path.
      location  - The location of the window. If this is NULL, the
                  function uses the default window position settings.
      size      - The size of the window, in the number of lines and columns.
                  If this is NULL, the function uses the default values.
                  The default value for rows is 24, and the default
                  for columns is 80.
                  The valid values for rows is between 6 and 33. The
                  valid values for columns is between 8 and 80. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the window.
      PRO_TK_BAD_INPUTS    - The specified file name is NULL, or is empty.
      PRO_TK_GENERAL_ERROR - The function cannot open the file, or cannot
                             find it.
*/


extern ProError ProFileEdit ( ProPath file_name );
/*
   Purpose:  Opens an edit window for the specified file using the
             default text editor.

   Input Arguments:
      file_name - The full file name, including the path, of the file to be
                  edited

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR  - The file was successfully edited.
      PRO_TK_NO_CHANGE - The user quit from the editor.
*/


extern ProError ProToolkitApplExecPathGet ( ProPath exec_path );
/*
   Purpose:  Retrieves the <i>exec_path</i> information.

   Input Arguments:
      None

   Output Arguments:
      exec_path - The path and the name of the executable 
                   where the <i>exec_file</i> is located

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the 
                          information.
      PRO_TK_BAD_INPUTS - The <i>text_path</i> argument is NULL
*/

extern ProError ProToolkitApplTextPathGet ( ProPath text_path );

/*
   Purpose:  Retrieves the path to the directory containing the "text"
             directory for the application.

   Input Arguments:
      None

   Output Arguments:
      text_path - The path to where the text files (message and menu files)
                  are located

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrieved the 
                          information.
      PRO_TK_BAD_INPUTS - The <i>text_path</i> argument is NULL.
*/

extern ProError ProDirectoryChange ( ProPath path );
/*
   Purpose:  Changes Creo Parametric to another working directory.
             The directory can be relative or absolute.
<p>
             You can use this function in conjuction with the file 
             management functionality to save and retrieve objects.

   Input Arguments:
      path - The path to the new directory


   Output Arguments:
      None


   Return Values:

      PRO_TK_NO_ERROR     - The function successfully changed the 
                            directory.
      PRO_TK_BAD_INPUTS   - The specified path is invalid.
      PRO_TK_CANT_ACCESS  - You are unable to access the specified 
                            directory.
      PRO_TK_INVALID_NAME - You specified an invalid name.

*/

   
extern ProError ProDirectoryCurrentGet ( ProPath path );
/*
  Purpose:  Gets the absolute path name of the current working
            directory for Creo Parametric.

  Input Arguments:
     None

   Output Arguments:
     path - The absolute path name of the current working directory

   Return Values:

     PRO_TK_NO_ERROR    - The function successfully retrieved the 
                          information.
     PRO_TK_E_NOT_FOUND - The function was unable to find 
                          current working directory.
*/


extern ProError ProOptionOrderedVerify ( ProCharName option,
                                         ProBoolean* p_option_exist );
/*
   Purpose:  Determines whether the specified option is available, such as 
             Pro/MESH.

   Input Arguments:
      option - The option name.

   Output Arguments:
      p_option_exist - This is PRO_B_TRUE if the option is available.
                       Otherwise, this is PRO_B_FALSE. 

   Return Values:

      PRO_TK_NO_ERROR    - The function successfully returned the 
                           information.
      PRO_TK_BAD_INPUTS  - The specified option is invalid.
      PRO_TK_E_NOT_FOUND - The specified option was not found.
*/


extern wchar_t* ProStringToWstring ( wchar_t* wstr, char* str );
/*
   Purpose:  Converts a multibyte character string to a wide string.
<p>
             NOTES: 
<ul>
             <li>This function accepts only strings only in the active 
                             encoding of the Creo Parametric TOOLKIT application. Strings
                                 from other encodings may not be properly converted.
             <li>This function does not change the encoding of the
                 string during the conversion.
             <li>This function replicates the performance of 
                         <i>strtows</i>, which exists on some operating systems.
</ul>

   Input Arguments:
      str  - The character string to convert, terminated by NULL character

   Output Arguments:
      wstr  - The buffer to contain the widestring.  The caller must
                  declare or allocate enough memory for this argument.

   Return Values:
      The wide string
*/


extern char* ProWstringToString ( char* str, wchar_t* wstr );
/*
   Purpose:  Converts a wide string to a multibyte character string.
<p>
             NOTES: 
<ul>
            <li>This function accepts strings only in the active 
                             encoding of the Creo Parametric TOOLKIT application. Strings
                                 from other encodings may not be properly converted.
             <li>This function does not change the encoding of the
                 string during the conversion.
             <li>This function replicates the performance of 
                         <i>wstostr</i>, which exists on some operating systems.
             <li>Each wide-string character is either 2 or 4 bytes, depending
                 on the machine. For applications to be used in
                 a multi-byte environment, PTC recommends providing enough
                 memory in the "str" buffer to store 3 * the length of the
                 "wstr" input.
</ul> 

   Input Arguments:
      wstr - The wide string, terminated by WNULL character
   
   Output Arguments:
      str  - The buffer to contain the multibyte character string.  The 
                 caller must declare or allocate enough memory for this argument.

   Return Values:
      The multibyte character string
*/

extern ProError ProWcharSizeVerify ( int application_size_of_wchar,
                                     int* proe_size_of_wchar );
/*
   Purpose:  Compares the size of <i>wchar_t</i> in the application with 
             the size of <i>wchar_t</i> in Creo Parametric.

   Input Arguments:
      application_size_of_wchar - The size of <i>wchar_t</i> in the application.
                           Use <i>sizeof(wchar_t)</i> to get the size.
   
   Output Arguments:
      proe_size_of_wchar - The size of <i>wchar_t</i> in Creo Parametric.

   Return Values:

      PRO_TK_NO_ERROR       - Both sizes are the same.
      PRO_TK_GENERAL_ERROR  - The sizes are different.
*/


extern ProError ProWstringToNativewstring (wchar_t* result, int result_size,
                                           wchar_t* input, int input_size,
                                           wchar_t out_of_encoding_char,
                                           ProBoolean* out_of_encoding);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a Creo Parametric UNICODE-encoded widestring to a
             native-encoded widestring.   Use this function when you need to
             pass a widestring obtained from Creo Parametric to an application
             which expects a native-encoded widestring.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The UNICODE-encoded widestring.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.
        out_of_encoding_char - The character to use when the conversion
                               encounters an out-of-encoding character in the
                               input.

    Output Arguments:
        result - The native-encoded widestring.  The application must supply
                 sufficient memory to hold the output.
        out_of_encoding - Flag indicating if the out-of-encoding character was
                          used during the conversion process.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProWstringToLegacystring (char* result, int result_size,
                                          wchar_t* input, int input_size,
                                          char out_of_encoding_char,
                                          ProBoolean* out_of_encoding);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a Creo Parametric UNICODE-encoded widestring to the legacy
             encoding used by Pro/ENGINEER prior to Wildfire 4.0.   Use this
             function when you need to use a widestring obtained from
             Creo Parametric to a file which might need to be read by Creo Parametric
             or a Creo Parametric TOOLKIT application running in an older version of Pro/E.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The Creo Parametric widestring.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.
        out_of_encoding_char - The character to use when the conversion
                               encounters an out-of-encoding character in the
                               input.

    Output Arguments:
        result - The legacy-encoded string.  The application must provide
                 enough memory for this output.
        out_of_encoding - Flag indicating if the out-of-encoding character was
                          used during the conversion process.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProWstringToNativestring (char* result, int result_size,
                                          wchar_t* input, int input_size,
                                          char out_of_encoding_char,
                                          ProBoolean* out_of_encoding);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a Creo Parametric UNICODE-encoded widestring to a native
             multibyte string.   Use this function when you need to convert a
             widestring obtained from Creo Parametric to an external interface
             expecting a native-encoded multibyte string.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The Creo Parametric widestring.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.
        out_of_encoding_char - The character to use when the conversion
                               encounters an out-of-encoding character in the
                               input.

    Output Arguments:
        result - The native-encoded string.  The application must provide
                 enough memory for this output.
        out_of_encoding - Flag indicating if the out-of-encoding character was
                          used during the conversion process.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProStringToNativewstring (wchar_t* result, int result_size,
                                          char* input, int input_size,
                                          wchar_t out_of_encoding_char,
                                          ProBoolean* out_of_encoding);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a Creo Parametric UNICODE-encoded multibyte string to a
             native-encoded widestring.   Use this function when you need to
             pass a string obtained from Creo Parametric to an application which
             expects a native-encoded widestring.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The UNICODE-encoded string.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.
        out_of_encoding_char - The character to use when the conversion
                               encounters an out-of-encoding character in the
                               input.

    Output Arguments:
        result - The native-encoded widestring.  The application must supply
                 sufficient memory to hold the output.
        out_of_encoding - Flag indicating if the out-of-encoding character was
                          used during the conversion process.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProStringToLegacystring (char* result, int result_size,
                                         char* input, int input_size,
                                         char out_of_encoding_char,
                                         ProBoolean* out_of_encoding);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a Creo Parametric UNICODE-encoded multibyte string to the
             legacy encoding used by Pro/ENGINEER prior to Wildfire 4.0. Use
             this function when you need to use a string obtained from
             Creo Parametric to a file which might need to be read by Creo Parametric
             or a Creo Parametric TOOLKIT application running in an older version of Pro/E.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The Creo Parametric string.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.
        out_of_encoding_char - The character to use when the conversion
                               encounters an out-of-encoding character in the
                               input.

    Output Arguments:
        result - The legacy-encoded string.  The application must provide
                 enough memory for this output.
        out_of_encoding - Flag indicating if the out-of-encoding character was
                          used during the conversion process.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProStringToNativestring (char* result, int result_size,
                                         char* input, int input_size,
                                         char out_of_encoding_char,
                                         ProBoolean* out_of_encoding);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a Creo Parametric UNICODE-encoded multibyte string to a
             native multibyte string.   Use this function when you need to
             convert a string obtained from Creo Parametric to an external
             interface expecting a native-encoded multibyte string.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The Creo Parametric widestring.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.
        out_of_encoding_char - The character to use when the conversion
                               encounters an out-of-encoding character in the
                               input.

    Output Arguments:
        result - The native-encoded string.  The application must provide
                 enough memory for this output.
        out_of_encoding - Flag indicating if the out-of-encoding character was
                          used during the conversion process.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProNativewstringToWstring (wchar_t* result, int result_size,
                                           wchar_t* input, int input_size);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a native-encoded widestring to a Creo Parametric compatible
             UNICODE-encoded widestring.  Use this function when you have the
             output of an external interface returning a native encoded
             widestring that needs to sent to Creo Parametric.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The native-encoded widestring.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.

    Output Arguments:
        result - The UNICODE-encoded widestring.  The application must supply
                 sufficient memory to hold the output.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProNativewstringToString (char* result, int result_size,
                                          wchar_t* input, int input_size);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a native-encoded widestring to a Creo Parametric compatible
             UNICODE-encoded multibyte string.  Use this function when you have
             the output of an external interface returning a native encoded
             widestring that needs to sent to Creo Parametric as a char*.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The native-encoded widestring.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.

    Output Arguments:
         result - The UNICODE-encoded widestring.  The function must supply
                 enough memory for this result.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProLegacystringToWstring (wchar_t* result, int result_size,
                                          char* input, int input_size);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a legacy-encoded multibyte string to a Creo Parametric
             compatible UNICODE-encoded widestring.  Use this function when you
             have a multibyte string from a file written by or for any release
             of Pro/ENGINEER older than Wildfire 4.0 that needs to sent to
             Creo Parametric.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The legacy-encoded string.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.

    Output Arguments:
        result - The UNICODE-encoded widestring.  The function must supply
                 enough memory for this result.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProLegacystringToString (char* result, int result_size,
                                         char* input, int input_size);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a legacy-encoded multibyte string to a Creo Parametric
             compatible UNICODE-encoded multibyte string.  Use this function
             when you have a multibyte string from a file written by or for any
             release of Pro/ENGINEER older than Wildfire 4.0 that needs to sent
             to Creo Parametric as a char*.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The legacy-encoded string.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.

    Output Arguments:
        result - The UNICODE-encoded string.  The function must supply enough
                 memory for this result.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProNativestringToWstring (wchar_t* result, int result_size,
                                          char* input, int input_size);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a native-encoded multibyte string to a Creo Parametric
             compatible UNICODE-encoded widestring.  Use this function when you
             have a native-encoded multibyte string from an external interface
             that needs to sent to Creo Parametric.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The legacy-encoded string.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.

    Output Arguments:
        result - The UNICODE-encoded widestring.  The function must supply
                 enough memory for this result.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/

extern ProError ProNativestringToString (char* result, int result_size,
                                         char* input, int input_size);
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Converts a native-encoded multibyte string to a Creo Parametric
             compatible UNICODE-encoded multibyte string.  Use this function
             when you have a native-encoded multibyte string from an external
             interface that needs to sent to Creo Parametric as a char*.
             <P>
             The resulting string will always be NULL-terminated as long as the
             result buffer has sufficient space for this.

    Input Arguments:
        result_size - The size of the buffer supplied for conversion.
        input - The legacy-encoded string.
        input_size - The size of the input widestring supplied for conversion.
                     If this is PRO_VALUE_UNUSED, the entire input string
                     should be converted.

    Output Arguments:
        result - The UNICODE-encoded widestring.  The function must supply
                 enough memory for this result.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_LINE_TOO_LONG - The supplied input string length was too long
                               for the available space in the result string.
                               Only a partial conversion was performed.

*/


extern ProError ProOutputFileWrite ( ProMdl      model,
                                     ProFileName name,
                                     ProImportExportFile   file_type,
                                     ProAppData  arg1,
                                     ProAppData  arg2,
                                     ProAppData  arg3,
                                     ProAppData  arg4 );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProOutputFileMdlnameWrite
   Purpose: <b>Note:</b> This function is deprecated
            Use ProOutputFileMdlnameWrite instead.

             Exports a file from Creo Parametric onto the disk. The file format
             is the same as the one created by an interactive  
             Creo Parametric session.

   Input Arguments:

      model     - A pointer to the model.
                  <ul>
                  <li>PRO_IGES_FILE and PRO_DXF_FILE work for drawings only.
                  <li>PRO_PROGRAM_FILE works for parts and assemblies only.
                  <li>For CL data, this pointer must reference a manufacturing model.
                  </ul>
      name      - The name of the file to be created (with the extension, but
                  not the version). Must not be NULL or an empty string.
                  If <i>file_type</i> is PRO_IGES_FILE or PRO_DXF_FILE, do not
                  include the extension; it is added automatically.
      file_type - The type of file to be created.
                  The valid values are as follows:
                  <ul>
                  <li>PRO_RELATION_FILE
                  <li>PRO_FEATURE_INFO 
                  <li>PRO_PROGRAM_FILE
                  <li>PRO_IGES_FILE
                  <li>PRO_DXF_FILE
                  <li>PRO_DWG_FILE
                  <li>PRO_DWG_SETUP_FILE
                  <li>PRO_FEAT_INFO
                  <li>PRO_RENDER_FILE
                  <li>PRO_SLA_ASCII_FILE
                  <li>PRO_SLA_BINARY_FILE
                  <li>PRO_INVENTOR_FILE
                  <li>PRO_CATIAFACETS_FILE
                  <li>PRO_BOM_FILE
                  <li>PRO_MFG_OPER_CL
                  <li>PRO_MFG_FEAT_CL
                  <li>PRO_MATERIAL_FILE
                  <li>PRO_IGES_3D_FILE
                  <li>PRO_STEP_FILE
                  <li>PRO_VDA_FILE
                  <li>PRO_FIAT_FILE
                  <li>PRO_CATIA_DIRECT_FILE
                  <li>PRO_ACIS_FILE
                  <li>PRO_CGM_FILE
                  <li>PRO_SPOOL_FILE
                  <li>PRO_CONNECTOR_PARAMS_FILE                  
                  <li>PRO_CABLE_PARAMS_FILE                  
                  <li>PRO_DIFF_REPORT_FILE                         
                  </ul>
      arg1      - If <i>file_type</i> is PRO_RENDER_FILE, PRO_INVENTOR_FILE,
                  PRO_CATIAFACETS_FILE, PRO_SLA_ASCII_FILE or 
                  PRO_SLA_BINARY_FILE <i>arg1</i> is a <i>wchar_t*</i> to a 
                  coordinate system name. If this is NULL, the function uses
                  the default coordinate system.
                  If <i>file_type</i> is PRO_SPOOL_FILE, <i>arg1</i> is a
                  <i>wchar_t*</i> to the spool name.
                  If <i>file_type</i> is PRO_CONNECTOR_PARAMS_FILE, <i>arg1</i>
                  is a <i>int*</i> pointing to a ProIdTable (ProIdTable is
                  an integer array of component identifiers). 
                  If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, <i>arg1</i> is
                  the <i>ProSolid</i> (part pointer).
      arg2      - If <i>file_type</i> is PRO_FEAT_INFO, PRO_MFG_OPER_CL or 
                  PRO_MFG_FEAT_CL <i>arg2</i> is a <i>int*</i> to the 
                  feature ID. 
                  If <i>file_type</i> is PRO_RELATION_FILE, <i>arg2</i> is a
                  <i>int*</i> to the feature ID, to get the relations 
                  contained in the feature. Pass NULL to get relations 
                  contained in the model.
                  If <i>file_type</i> is PRO_IGES_3D_FILE, PRO_STEP_FILE,
                  PRO_VDA_FILE, PRO_FIAT_FILE, 
                  PRO_CATIA_DIRECT_FILE or PRO_ACIS_FILE <i>arg2</i> is a 
                  <i>int*</i> pointing to the number.
                  If <i>file_type</i> is PRO_CGM_FILE, <i>arg2</i> is a  
                  <i>int*</i> pointing to the export type (PROCGMTYPE_CLEAR_TEXT
                  or PROCGMTYPE_MIL_SPEC ie 1 or 2).
                  If <i>file_type</i> is PRO_CONNECTOR_PARAMS_FILE, <i>arg2</i>
                  is a <i>int*</i> pointing to the number, which is equal to the
                  number of component identifier(s).
                  If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, <i>arg2</i> is
                  the <i>wchar_t*</i> pointing to the cable name.
                  <p>
                  Please note that the previous use of arg2 and arg3 for quality
                  control is deprecated - use ProIntfSliceFileWithOptionsExport 
                  instead.      
      arg3      - If <i>file_type</i> is PRO_CGM_FILE, <i>arg3</i> is a
                  <i>int*</i> pointing to the scale type (PROCGMTYPE_ABSTRACT
                  or PROCGMTYPE_METRIC ie 3 or 4)
      arg4      - If <i>file_type</i> is PRO_DIFF_REPORT_FILE, this is the 
                  model to which the input model will be compared for 
                  generation of the difference report.
      
   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully exported the file.
       PRO_TK_GENERAL_ERROR - The function failed.
       PRO_TK_E_NOT_FOUND   - An entity named in arg1 or arg2 does not exist.
       PRO_TK_BAD_INPUTS    - Some input was incorrect. e.g.:
<ul>
                              <li><i>file_type</i> was PRO_CGM_FILE but
                              <i>mdl</i> was not a drawing;
                              <li>assembly did not contain specified part;
                              <li>quality was outside limits.
</ul>
       PRO_TK_OBSOLETE_FUNC - The file format selected is no longer 
                              supported on this platform.
       PRO_TK_BAD_CONTEXT   - The function is not available in 
                              Design Test Mode.      
                              
                                
*/

extern ProError ProOutputFileMdlnameWrite ( ProMdl      model,
                                            ProMdlFileName name,
                                            ProImportExportFile   file_type,
                                            ProAppData  arg1,
                                            ProAppData  arg2,
                                            ProAppData  arg3,
                                            ProAppData  arg4 );
/*
   Purpose:  Exports a file from Creo Parametric onto the disk. The file format
             is the same as the one created by an interactive  
             Creo Parametric session.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release. 

   Input Arguments:

      model     - A pointer to the model.
                  <ul>
                  <li>PRO_IGES_FILE and PRO_DXF_FILE work for drawings only.
                  <li>PRO_PROGRAM_FILE works for parts and assemblies only.
                  <li>For CL data, this pointer must reference a manufacturing model.
                  </ul>
      name      - The name of the file to be created (with the extension, but
                  not the version). Must not be NULL or an empty string.
                  If <i>file_type</i> is PRO_IGES_FILE or PRO_DXF_FILE, do not
                  include the extension; it is added automatically.
      file_type - The type of file to be created.
                  The valid values are as follows:
                  <ul>
                  <li>PRO_RELATION_FILE
                  <li>PRO_FEATURE_INFO 
                  <li>PRO_PROGRAM_FILE
                  <li>PRO_IGES_FILE
                  <li>PRO_DXF_FILE
                  <li>PRO_DWG_FILE
                  <li>PRO_DWG_SETUP_FILE
                  <li>PRO_FEAT_INFO
                  <li>PRO_RENDER_FILE
                  <li>PRO_SLA_ASCII_FILE
                  <li>PRO_SLA_BINARY_FILE
                  <li>PRO_INVENTOR_FILE
                  <li>PRO_CATIAFACETS_FILE
                  <li>PRO_BOM_FILE
                  <li>PRO_MFG_OPER_CL
                  <li>PRO_MFG_FEAT_CL
                  <li>PRO_MATERIAL_FILE
                  <li>PRO_IGES_3D_FILE
                  <li>PRO_STEP_FILE
                  <li>PRO_VDA_FILE
                  <li>PRO_FIAT_FILE
                  <li>PRO_CATIA_DIRECT_FILE
                  <li>PRO_ACIS_FILE
                  <li>PRO_CGM_FILE
                  <li>PRO_SPOOL_FILE
                  <li>PRO_CONNECTOR_PARAMS_FILE                  
                  <li>PRO_CABLE_PARAMS_FILE                  
                  <li>PRO_DIFF_REPORT_FILE                         
                  </ul>
      arg1      - If <i>file_type</i> is PRO_RENDER_FILE, PRO_INVENTOR_FILE,
                  PRO_CATIAFACETS_FILE, PRO_SLA_ASCII_FILE or 
                  PRO_SLA_BINARY_FILE <i>arg1</i> is a <i>wchar_t*</i> to a 
                  coordinate system name. If this is NULL, the function uses
                  the default coordinate system.
                  If <i>file_type</i> is PRO_SPOOL_FILE, <i>arg1</i> is a
                  <i>wchar_t*</i> to the spool name.
                  If <i>file_type</i> is PRO_CONNECTOR_PARAMS_FILE, <i>arg1</i>
                  is a <i>int*</i> pointing to a ProIdTable (ProIdTable is
                  an integer array of component identifiers). 
                  If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, <i>arg1</i> is
                  the <i>ProSolid</i> (part pointer).
      arg2      - If <i>file_type</i> is PRO_FEAT_INFO, PRO_MFG_OPER_CL or 
                  PRO_MFG_FEAT_CL <i>arg2</i> is a <i>int*</i> to the 
                  feature ID. 
                  If <i>file_type</i> is PRO_RELATION_FILE, <i>arg2</i> is a
                  <i>int*</i> to the feature ID, to get the relations 
                  contained in the feature. Pass NULL to get relations 
                  contained in the model.
                  If <i>file_type</i> is PRO_IGES_3D_FILE, PRO_STEP_FILE,
                  PRO_VDA_FILE, PRO_FIAT_FILE, 
                  PRO_CATIA_DIRECT_FILE or PRO_ACIS_FILE <i>arg2</i> is a 
                  <i>int*</i> pointing to the number.
                  If <i>file_type</i> is PRO_CGM_FILE, <i>arg2</i> is a  
                  <i>int*</i> pointing to the export type (PROCGMTYPE_CLEAR_TEXT
                  or PROCGMTYPE_MIL_SPEC ie 1 or 2).
                  If <i>file_type</i> is PRO_CONNECTOR_PARAMS_FILE, <i>arg2</i>
                  is a <i>int*</i> pointing to the number, which is equal to the
                  number of component identifier(s).
                  If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, <i>arg2</i> is
                  the <i>wchar_t*</i> pointing to the cable name.
                  <p>
                  Please note that the previous use of arg2 and arg3 for quality
                  control is deprecated - use ProIntfSliceFileWithOptionsExport 
                  instead.      
      arg3      - If <i>file_type</i> is PRO_CGM_FILE, <i>arg3</i> is a
                  <i>int*</i> pointing to the scale type (PROCGMTYPE_ABSTRACT
                  or PROCGMTYPE_METRIC ie 3 or 4)
      arg4      - If <i>file_type</i> is PRO_DIFF_REPORT_FILE, this is the 
                  model to which the input model will be compared for 
                  generation of the difference report.
      
   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully exported the file.
       PRO_TK_GENERAL_ERROR - The function failed.
       PRO_TK_E_NOT_FOUND   - An entity named in arg1 or arg2 does not exist.
       PRO_TK_BAD_INPUTS    - Some input was incorrect. e.g.:
<ul>
                              <li><i>file_type</i> was PRO_CGM_FILE but
                              <i>mdl</i> was not a drawing;
                              <li>assembly did not contain specified part;
                              <li>quality was outside limits.
</ul>
       PRO_TK_OBSOLETE_FUNC - The file format selected is no longer 
                              supported on this platform.
       PRO_TK_BAD_CONTEXT   - The function is not available in 
                              Design Test Mode.      
                              
                                
*/

extern ProError ProPlotfileWrite ( ProMdl         model,
                                   ProFileName        filename,
                                   ProPlotOptions* plot_options );
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProPrintExecute
   Purpose:  Outputs a standard Creo Parametric plot output file.
             The model to be plotted must be displayed in a window.
             <b>Note:</b>This function has been superseded by ProPrintExecute().
 
   Input Arguments:
      model        - A valid object in memory
      filename     - An output filename, including the extension
      plot_options - Information for the plot file

   Output Arguments:
      None
   
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the plot file.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.
*/

extern ProError ProRasterFileWrite ( int            window_id,
                                     ProRasterDepth depth,
                                     double         width,
                                     double         height,
                                     ProDotsPerInch dots_per_inch,
                                     ProRasterType  type,
                                     ProPath        output_file );
/*
   Purpose:  Outputs a standard Creo Parametric raster output file.
             <b>Note</b>:Use this function to export a solid model only. To
             convert drawings to the specified formats, use the function
             <b>ProPrintExecute()</b>.

   Input Arguments:
      window_id     - the handle of the window that will be exported
      depth         - the depth of the output image
      width         - the width of the output image in inches
      height        - the height of the output image in inches
      dots_per_inch - the dots per inch of the output image
      type          - the output image type
      output_file   - An output filename, including the extension

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the raster file.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.
      PRO_TK_BAD_CONTEXT   - The function is not available in Design Test Mode.
                             
*/

extern ProError ProExportVRML ( ProBoolean direct,
                                ProMdl model,
                                ProPath input_file,
                                ProPath output_path );

/*
   Purpose: Exports a solid from Creo Parametric, or a Creo Parametric solid 
            from disk, into VRML format. This works in the same way as the
            Pro/BATCH module.
<p>
            The exported file tree is the same as after a Creo Parametric
            Export VRML operation.
<p>
            ProExportVRML supports creation of multiple output files from
            either parts or assemblies. If you export an assembly, the 
            function creates an output file for each member of the assembly
            and one for the assembly itself. Default file names are:
            asm1_a.wrl, asm2_a.wrl, ... asmN_a.wrl, where asm is the assembly
            name.
<p>
            If you export parts, ProExportVRML creates an output file for each
            part. Default names are part_p.wrl, where part is the part name.
 
   Input Arguments:
      direct      - PRO_B_TRUE if the VRML is to be extracted from
                        a disk file containing a Creo Parametric model;
                    PRO_B_FALSE if the VRML is to be extracted from
                        a model now in session
      model       - The model in session to be exported. Ignored if
                          direct == PRO_B_TRUE.
      input_file  - The name of the Creo Parametric model file to be extracted.
                    Ignored if direct == PRO_B_FALSE.
      output_path - Output path for directory where VRML tree will be
                    created.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The export succeeded.
      PRO_TK_GENERAL_ERROR - The export failed.
      PRO_TK_BAD_CONTEXT - The function is not available in 
                           Design Test Mode.      
      

*/

extern ProError ProInputFileRead ( ProMdl         model,
                                   ProPath        filename,
                                   ProImportExportFile    file_type,
                                   ProAppData     arg1,
                                   ProAppData     arg2,
                                   ProAppData     arg3,
                                   ProAppData     arg4 );
/*
   Purpose:  Reads a file into Creo Parametric.  The format must be the
             same as if these files were created by Creo Parametric.
<p>
             NOTES: 
<ul>
             <li>If <i>file_type</i> is PRO_CONFIG_FILE, the <i>model</i>
               argument is ignored.
             <li>If <i>file_type</i> is PRO_RELATION_FILE, this function 
               does not regenerate after reading the file; it checks for
               syntax errors. To regenerate the object, use 
               <b>ProSolidRegenerate()</b>. 
             <li>If <i>file_type</i> is PRO_DWG_SETUP_FILE, the function 
               does not repaint the screen. If the model is NULL, the function
               uses the current drawing.
             <li>If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, 
               PRO_CONNECTOR_PARAMS_FILE, PRO_DWG_SETUP_FILE, or PRO_SPOOL_FILE
               the <i>filename</i> argument should be a file name and extension
               only, not a full path.
             <li>If <i>file_type</i> is PRO_IGES_SECTION, this operates only
               on an active section model.  The user will have to place the
               imported section geometry in the active section with a mouse
               click.
</ul>

   Input Arguments:
      model     - A  valid object in memory.
      filename  - The input file name, including the extension.  
                  For some options, this can be the full path to the file.
      file_type - The type of file to be read in.
                  The valid values are as follows:
                  <ul>
                  <li>PRO_RELATION_FILE
                  <li>PRO_IGES_SECTION
                  <li>PRO_PROGRAM_FILE
                  <li>PRO_CONFIG_FILE
                  <li>PRO_DWG_SETUP_FILE
                  <li>PRO_SPOOL_FILE
                  <li>PRO_CABLE_PARAMS_FILE
                  <li>PRO_CONNECTOR_PARAMS_FILE
                  <li>PRO_ASSEM_TREE_CFG_FILE
                  <li>PRO_WIRELIST_FILE
                  <li>SLD_VARIANT_FILE
                  </ul>
      arg1      - The application data.
                  If <i>file_type</i> is PRO_CONNECTOR_PARAMS_FILE, <i>arg1</i>
                  is a <i>int*</i> pointing to a ProIdTable (ProIdTable is an
                  integer array of component identifiers).
                  If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, <i>arg1</i> is
                  the <i>ProSolid</i> (part pointer).
      arg2      - The application data.
                  If <i>file_type</i> is PRO_CONNECTOR_PARAMS_FILE, <i>arg2</i>
                  is a <i>int*</i> pointing to the number, which is equal to the
                  number of component identifier(s).
                  If <i>file_type</i> is PRO_CABLE_PARAMS_FILE, <i>arg2</i> is
                  a <i>wchar_t*</i> to the cable name.
                  If <i>file_type</i> is PRO_RELATION_FILE, <i>arg2</i> is
                  the <i>int*</i> pointing to feature ID. Pass it NULL to get 
                  relations of model. 
      arg3      - The application data.
                  If <i>file_type</i> PRO_RELATION_FILE,  <i>arg3</i> is a
                  <i>int*</i>. If it points to 1 then relations in the file
                  should be added to the current relations, else the relations
                  in the file should replace the current relations.
      arg4      - Unused.

   Output Arguments:
      None
   
   Return Values:

      PRO_TK_NO_ERROR      - The function successfully processed the 
                             file.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed.
      PRO_TK_LINE_TOO_LONG - The input filename length is too long for this 
                             import file type.
      PRO_TK_OBSOLETE_FUNC - The file format selected is no longer 
                             supported on this platform.

   See Also:
      ProSolidRegenerate()
*/

extern ProError ProTrailfileCommentWrite ( ProComment comment );
/*
   Purpose:  Appends a comment to the specified trail file.
            
   Input Arguments:
      comment       - The comment to add to the trail file. The length of the
                      comment should be <i>(PRO_COMMENT_SIZE - 2)</i>. If the
                      message is too long, the function strips the comment
                      after <i>(PRO_COMMENT_SIZE - 2)</i>.
                      <p>
                      Note that the comment should not have any trailing '\n'
                      or nonprintable characters.
   
   Output Arguments:
      None

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully added the comment.
      PRO_TK_LINE_TOO_LONG - The specified comment was too long.
      PRO_TK_GENERAL_ERROR - A general error occurred and the
                             function could not add the comment to
                             the trail file.
*/

extern ProError ProFileOpen (
        ProName         dialog_label,
        ProLine         filter_string,
        ProPath        *shortcut_path_arr,
        ProName        *shortcut_name_arr,
        ProPath         default_path,
        ProFileName     pre_sel_file_name,
        ProPath         r_selected_file 
   );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProFileMdlnameOpen, ProFileMdlfiletypeOpen
   Purpose: <b>Note:</b> This function is deprecated
            Use ProFileMdlnameOpen or ProFileMdlfiletypeOpen instead.

             Prompts the standard file browser interface of Creo Parametric.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default 
                          label, "Open."
      filter_string     - The user-supplied filter string for file extensions.
                          The extensions must be specified with wildcards and
                          separated by commas; for example, "*.prt,*.txt"
                          (converted to wide-character string). If NULL or
                          empty string, the browser will show all files.
      shortcut_path_arr - A ProArray of shortcut paths. Pass NULL to not supply
                          shortcuts to the user in the dialog.
      shortcut_name_arr - A ProArray of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Pass NULL to not supply 
                          shortcuts to the user in the dialog.
      default_path      - The default path to start browsing. If this is 
                          NULL, the function uses the current directory.
      pre_sel_file_name - If supplied and existing in the default file name
                          this name is preselected. If this is NULL, nothing is
                          preselected.

   Output Arguments:

      r_selected_file   - The selected file.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a file and picked "Ok".
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid, or 
                          the size of shortcut_path_arr and shortcut_name_arr
                          is not the same.
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileMdlnameOpen (
        ProName         dialog_label,
        ProLine         filter_string,
        ProPath        *shortcut_path_arr,
        ProName        *shortcut_name_arr,
        ProPath         default_path,
        ProMdlFileName  pre_sel_file_name,
        ProPath         r_selected_file 
   );
/*
   Purpose:  Prompts the standard file browser interface of Creo Parametric.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release. 
                        <br>
                        This function cannot be used for NX models in the current release.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default 
                          label, "Open."
      filter_string     - The user-supplied filter string for file extensions.
                          The extensions must be specified with wildcards and
                          separated by commas; for example, "*.prt,*.txt"
                          (converted to wide-character string). If NULL or
                          empty string, the browser will show all files.
      shortcut_path_arr - A ProArray of shortcut paths. Pass NULL to not supply
                          shortcuts to the user in the dialog.
      shortcut_name_arr - A ProArray of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Pass NULL to not supply 
                          shortcuts to the user in the dialog.
      default_path      - The default path to start browsing. If this is 
                          NULL, the function uses the current directory.
      pre_sel_file_name - If supplied and existing in the default file name
                          this name is preselected. If this is NULL, nothing is
                          preselected.

   Output Arguments:

      r_selected_file   - The selected file.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a file and picked "Ok".
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid, or 
                          the size of shortcut_path_arr and shortcut_name_arr
                          is not the same.
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileMdlfiletypeOpen (
        ProName         dialog_label,
        ProMdlfileType *file_types,
        ProPath        *shortcut_path_arr,
        ProName        *shortcut_name_arr,
        ProPath         default_path,
        ProMdlFileName  pre_sel_file_name,
        ProPath         r_selected_file 
   );
/*
   Purpose:  Prompts the standard file browser interface of Creo Parametric.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release. 
                        <br>
                        This function cannot be used for NX models in the current release.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default 
                          label, "Open."
      file_types        - The user-allocated ProArray of file types. If NULL,
                          the browser will show all files.
      shortcut_path_arr - A ProArray of shortcut paths. Pass NULL to not supply
                          shortcuts to the user in the dialog.
      shortcut_name_arr - A ProArray of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Pass NULL to not supply 
                          shortcuts to the user in the dialog.
      default_path      - The default path to start browsing. If this is 
                          NULL, the function uses the current directory.
      pre_sel_file_name - If supplied and existing in the default file name
                          this name is preselected. If this is NULL, nothing is
                          preselected.

   Output Arguments:

      r_selected_file   - The selected file.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a file and picked "Ok".
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid, or 
                          the size of shortcut_path_arr and shortcut_name_arr
                          is not the same.
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileSave (
        ProName         dialog_label,
        ProLine         filter_string,
        ProPath         *shortcut_path_arr,
        ProName         *shortcut_name_arr,
        ProPath         default_path,
        ProFileName     pre_sel_file_name,
        ProPath         r_selected_file
    );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProFileMdlnameSave, ProFileMdlfiletypeSave
   Purpose: <b>Note:</b> This function is deprecated
            Use ProFileMdlnameSave or ProFileMdlfiletypeSave instead.

             Prompts the standard file browser interface of Creo Parametric.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default
                          label, "Save."
      filter_string     - The user-supplied filter string for file extensions.
                          The extensions must be specified with wildcards and
                          separated by commas; for example, "*.prt,*.txt"
                          (converted to wide-character string).
      shortcut_path_arr - A ProArray of shortcut paths. Pass NULL to not supply
                          shortcuts to the user in the dialog.
      shortcut_name_arr - A ProArray of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Pass NULL to not supply 
                          shortcuts to the user in the dialog.
      default_path      - The default path to start browsing. If this is
                          NULL, the function uses the current directory.
      pre_sel_file_name - If supplied and existing in the default file name
                          this name is preselected. If this is NULL, nothing is
                          preselected.

   Output Arguments:

      r_selected_file   - The selected file.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a file and picked "Save".
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileMdlnameSave (
        ProName         dialog_label,
        ProLine         filter_string,
        ProPath         *shortcut_path_arr,
        ProName         *shortcut_name_arr,
        ProPath         default_path,
        ProMdlFileName  pre_sel_file_name,
        ProPath         r_selected_file
    );
/*
   Purpose:  Prompts the standard file browser interface of Creo Parametric.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release.
                        <p>
                        For Multi-CAD objects, this function does not support local disk saving 
                        location in a Windchill connected session.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default
                          label, "Save."
      filter_string     - The user-supplied filter string for file extensions.
                          The extensions must be specified with wildcards and
                          separated by commas; for example, "*.prt,*.txt"
                          (converted to wide-character string).
      shortcut_path_arr - A ProArray of shortcut paths. Pass NULL to not supply
                          shortcuts to the user in the dialog.
      shortcut_name_arr - A ProArray of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Pass NULL to not supply 
                          shortcuts to the user in the dialog.
      default_path      - The default path to start browsing. If this is
                          NULL, the function uses the current directory.
      pre_sel_file_name - If supplied and existing in the default file name
                          this name is preselected. If this is NULL, nothing is
                          preselected.

   Output Arguments:

      r_selected_file   - The selected file.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a file and picked "Save".
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileMdlfiletypeSave (
        ProName         dialog_label,
        ProMdlfileType  *file_types,
        ProPath         *shortcut_path_arr,
        ProName         *shortcut_name_arr,
        ProPath         default_path,
        ProMdlFileName  pre_sel_file_name,
        ProPath         r_selected_file
    );
/*
   Purpose:  Prompts the standard file browser interface of Creo Parametric.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release. 
                        <p>
                        For Multi-CAD objects, this function does not support local disk saving 
                        location in a Windchill connected session.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default
                          label, "Save."
      file_types        - The user-allocated ProArray of file types. If NULL,
                          the browser will show all files.
      shortcut_path_arr - A ProArray of shortcut paths. Pass NULL to not supply
                          shortcuts to the user in the dialog.
      shortcut_name_arr - A ProArray of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Pass NULL to not supply 
                          shortcuts to the user in the dialog.
      default_path      - The default path to start browsing. If this is
                          NULL, the function uses the current directory.
      pre_sel_file_name - If supplied and existing in the default file name
                          this name is preselected. If this is NULL, nothing is
                          preselected.

   Output Arguments:

      r_selected_file   - The selected file.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a file and picked "Save".
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileselectionDocNameGet(ProPath document_name);
/*
   Purpose:  If the most recent file selected in ProFileOpen() or one
             of the related ProFile...Open() functions was secondary
             content, returns the primary document name.

   Input Arguments:
      None

   Output Arguments:
      document_name      - The name and extension of the primary document.

   Return Values:
      PRO_TK_NO_ERROR    - The most recent selection was secondary.
      PRO_TK_E_NOT_FOUND - The most recent selection was NOT secondary.
      PRO_TK_BAD_INPUTS  - document_name was NULL.
   
*/

extern ProError ProDirectoryChoose (ProName         dialog_label,
        ProPath        *shortcut_path_arr,
        ProName        *shortcut_name_arr,
        ProPath         default_path,
        ProPath         r_selected_path
   );
/*
   Purpose:  Prompts the standard file browser interface of Creo Parametric, set up
for the purpose of
                    allowing the user to select a directory.

      Input Arguments:

      dialog_label      - The user-specified label for the dialog box.
                          If this is NULL, the function uses the default
                          label, "Select Directory".
      shortcut_path_arr - An array of shortcut paths. Use
                          <b>ProArrayAlloc()</b> to allocate this array.
                            This can be NULL.
      shortcut_name_arr - An array of shortcut labels that correspond to
                          <i>shortcut_path_arr</i>. Use <b>ProArrayAlloc()</b>
                          to allocate this array.  This can be NULL.
      default_path      - The default path to start browsing. If this is
                          NULL, the function uses the current directory.

  Output Arguments:

      r_selected_path   - The selected directory path.

   Return Values:
      PRO_TK_NO_ERROR   - The user selected a directory and picked "Ok".
      PRO_TK_USER_ABORT - The user aborted from the user interface.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProFileCopyFromWS (ProPath source_file, 
                                   ProPath target_directory); 
/* 

   Purpose: Copies a file from a Windchill workspace 
            to a disk location. 

   Input Arguments: 
       source_file - The path to the file, provided by functions such 
                     as ProFileMdlnameOpen() and ProFileMdlfiletypeOpen().
                     This must begin with wtws://. 
       target_directory - The location on the local disk indicating where 
                         to copy the file. 

   Output Arguments: 
       none 

   Return Values: 
       PRO_TK_NO_ERROR - The function succeeded. 
       PRO_TK_BAD_INPUTS - One or more inputs was invalid. 
       PRO_TK_INVALID_FILE - The input file was not found or improper. 
       PRO_TK_INVALID_DIR - The output location was not found.
       PRO_TK_CANT_ACCESS - No permission to read the input file, or to
                            write to the target directory.
*/ 

extern ProError ProFileCopyFromWSDocument (ProPath source_file,
                                           ProPath document_name,
                                           ProPath target_directory); 
/* 

   Purpose: Copies a file, either primary or secondary, from a Windchill 
            workspace to a disk location. 

   Input Arguments: 
       source_file - The path to the file, provided by functions such 
                     as ProFileMdlnameOpen() and ProFileMdlfiletypeOpen().
                     This must begin with wtws://.
       document_name - If present, the name of the document, with source_file
                       being the name of the secondary content on the document.
                       If NULL, read the primary content of source_file.
       target_directory - The location on the local disk indicating where 
                         to copy the file. 

   Output Arguments: 
       none 

   Return Values: 
       PRO_TK_NO_ERROR - The function succeeded. 
       PRO_TK_BAD_INPUTS - One or more inputs was invalid. 
       PRO_TK_INVALID_FILE - The input file was not found or improper. 
       PRO_TK_INVALID_DIR - The output location was not found.
       PRO_TK_CANT_ACCESS - No permission to read the input file, or to
                            write to the target directory.
*/ 


extern ProError ProFileCopyToWS (ProPath source_file,
                                 ProPath target_workspace,
                                 ProPath primary_content);
/*
   Purpose: Copies a file from local disk to a Windchill
            workspace; either as a primary document or as secondary
            content of an existing document in the workspace.
            <P>
            NOTE: The config option "dm_upload_objects" can cause an upload 
            after each save.
            


   Input Arguments: 
       source_file - The path to the file, provided by functions such 
                     as ProFileMdlnameOpen() and ProFileMdlfiletypeOpen().
       target_workspace - The destination workspace.
       primary_content - The document which the copy will be attached to,
                         "box7.prt" for example.  Pass NULL to simply 
                         copy the file to the workspace.
   Output Arguments: 
       none 

   Return Values: 
       PRO_TK_NO_ERROR - The function succeeded. 
       PRO_TK_BAD_INPUTS - One or more inputs was invalid. 
       PRO_TK_INVALID_FILE - An input file was not found or improper.
       PRO_TK_BAD_CONTEXT - There was a problem setting primary_content.
       PRO_TK_CANT_WRITE - The workspace file is not writable.
*/

extern ProError ProDocumentFileContentsRead (ProPath source_file,
                                             ProPath document_name,
                                             ProArray *contents);
/*

   Purpose: Reads the contents of a short file from a location on disk
            or in Windchill.
            <p><b>Note:</b> Not intended for CAD model files.

   Input Arguments:
       source_file - The path to the file, provided by functions such
                     as ProFileMdlnameOpen() and ProFileMdlfiletypeOpen().
       document_name - If present, the name of the document, with source_file
                       being the name of the secondary content on the document.
                       If NULL, read the primary content of source_file.
                       Ignored for non-Windchill locations.
   Output Arguments:
       contents    - A ProArray of chars from the file, which caller must
                     free using ProArrayFree().

   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more inputs was invalid.
       PRO_TK_INVALID_FILE - The input file was not found or improper.
       PRO_TK_MAX_LIMIT_REACHED - File was longer than
                                  ProArrayMaxCountGet(sizeof(char)).
       PRO_TK_CANT_ACCESS - No permission to read the input file.
       PRO_TK_UNSUPPORTED - Not supported for CAD models.
       PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProIntfSliceFileExport (ProMdl model,
        ProFileName out_file_name,
        ProImportExportFile file_type,
        double quality[2],
        ProMatrix transf,
        ProAsmcomppath *comp_path);


/*
   DEPRECATED: Since Creo 2
   SUCCESSORS: ProIntfSliceFileWithOptionsMdlnameExport
   Purpose:  Exports 5 of the 7 "slice" formats (STL, Render, 
             Inventor, CatiaFacets, Optegra Visualizer).
             
<p>
             NOTE: 
<p>
             On UNIX machines, file names are case sensitive.
<p>
             This API is deprecated. Use
             ProIntfSliceFileWithOptionsMdlnameExport instead.
             This API is equivalent to ProIntfSliceFileWithOptionsMdlnameExport 
             with only PRO_FACET_STEP_SIZE_OFF set for config_flags.

   Input Arguments:
      model          - The pointer to the model to export.
      out_file_name  - The name of the output file.
      file_type      - The type of file to export (STL, Inventor,
                       and so on).
      quality        - The array that contains the maximum chord 
                       height and angle control.  If quality[0] &lt; 0.0,
                       the minimum chord height will be used.
      transf         - The transformation matrix.
      comp_path      - The component path, in the case of an 
                       assembly component. If the model is a part, set  
                       this to NULL.

   Output Arguments:
      None

   Return Values:

   PRO_TK_NO_ERROR      - The function successfully exported the file. 
   PRO_TK_BAD_INPUTS    - You specified incorrect quality settings, or
                          a nonexistent file type.
   PRO_TK_GENERAL_ERROR - There was a triangulation failure.
   PRO_TK_NO_LICENSE    - You do not have a license.
   PRO_TK_BAD_CONTEXT   - The function is not available in 
                          Design Test Mode.      
   
*/


/* bit flags to control facet export */

#define PRO_FACET_STEP_SIZE_ADJUST      (1<<0)  /* adjust step size to a component size      */
#define PRO_FACET_CHORD_HEIGHT_ADJUST   (1<<1)  /* adjust chord height to a component size   */

#define PRO_FACET_USE_CONFIG            (1<<2)  /* use Creo Parametric config options              */

/* If PRO_FACET_USE_CONFIG flag is set, the flags PRO_FACET_STEP_SIZE_OFF,
PRO_FACET_STEP_SIZE_ADJUST and PRO_FACET_CHORD_HEIGHT_ADJUST will be ignored and
the facet export will use Creo Parametric config options to turn on/off the use of step size,
the step size adjustment and the chord height adjustment.

Otherwise these options are governed by PRO_FACET_STEP_SIZE_OFF, PRO_FACET_STEP_SIZE_ADJUST
and PRO_FACET_CHORD_HEIGHT_ADJUST.              */


#define PRO_FACET_CHORD_HEIGHT_DEFAULT  (1<<3)  /* find the default chord height and use it  */
#define PRO_FACET_ANGLE_CONTROL_DEFAULT (1<<4)  /* find the default angle control and use it */
#define PRO_FACET_STEP_SIZE_DEFAULT     (1<<5)  /* find the default step size and use it     */

/* If any of these flags are set then the value of that control will be ignored -
instead it will be set to its default value as shown in the Creo Parametric facet control dialog box.

Use these flags to get a good facet quality without providing explicit control settings.

PRO_FACET_USE_CONFIG has no interference with these flags.              */


#define PRO_FACET_STEP_SIZE_OFF         (1<<6)  /* turn off the step size control            */

#define PRO_FACET_FORCE_INTO_RANGE      (1<<7)  /* force out-of-range parameters into range;
                                                   as above, if any of PRO_FACET_*_DEFAULT is set
                                                   then PRO_FACET_FORCE_INTO_RANGE will not act 
                                                   on that parameter */
#define PRO_FACET_INCLUDE_QUILTS        (1<<8)  /* include quilts (tesselate them) in export */

#define PRO_EXPORT_INCLUDE_ANNOTATIONS	(1<<9)	/* include annotations. Note: Model needs to be displayed in
												order to export annotations*/

extern ProError ProIntfSliceFileWithOptionsExport (ProMdl model,
        ProFileName         out_file_name,
        ProImportExportFile file_type,
        double              *parameters,
        int                 config_flags,
        ProMatrix           transf,
        ProAsmcomppath      *comp_path);

/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProIntfSliceFileWithOptionsMdlnameExport
   Purpose: <b>Note:</b> This function is deprecated
            Use ProIntfSliceFileWithOptionsMdlnameExport instead.

             Exports 5 of the 7 "slice" formats (STL, Render, 
             Inventor, CatiaFacets, Optegra Visualizer).
             
<p>
             NOTE: 
<p>
             On UNIX machines, file names are case sensitive.

   Input Arguments:
      model          - The pointer to the model to export. 
                       If NULL the current model will be used.
      out_file_name  - The name of the output file.
      file_type      - The type of file to export (STL, Inventor,
                       and so on).
      parameters     - ProArray of parameters to be set; 
                       in this version this array always has 3 elements,
                       which are interpreted as: 
                       chord_height, angle_control, step_size
                       (in future this array may be expanded).

                       angle_control must be from 0.0 to 1.0

                       Setting chord_height or step_size to values too big or
                       too small (for instance, bigger than the model
                       size or smaller than the model absolute accuracy)
                       may cause an error.

                       If angle_control is out of bounds it will be changed
                       to the closest limit without returning an error.
      config_flags   - Bit flags (PRO_FACET_STEP_SIZE_ADJUST and others) to control
                       facet export. See comments against these flags
                       for how to use them.
      transf         - The transformation matrix.
                       If NULL, no transformation will be applied.
      comp_path      - The component path, in the case of an 
                       assembly component. If the model is a part, set  
                       this to NULL.

   Output Arguments:
      None

   Return Values:

   PRO_TK_NO_ERROR      - The function successfully exported the file. 
   PRO_TK_BAD_INPUTS    - parameters array is NULL or its size is not 3;
                          or flags values are incorrect;
                          or you specified a nonexistent file type.
   PRO_TK_GENERAL_ERROR - There was a triangulation failure.
   PRO_TK_NO_LICENSE    - You do not have a license.
   PRO_TK_BAD_CONTEXT   - The function is not available in 
                          Design Test Mode.      
   
*/

extern ProError ProIntfSliceFileWithOptionsMdlnameExport (ProMdl model,
        ProMdlFileName      out_file_name,
        ProImportExportFile file_type,
        double              *parameters,
        int                 config_flags,
        ProMatrix           transf,
        ProAsmcomppath      *comp_path);

/*
   Purpose:  Exports 5 of the 7 "slice" formats (STL, Render, 
             Inventor, CatiaFacets, Optegra Visualizer).
             
<p>
             NOTE: 
<p>
             On UNIX machines, file names are case sensitive.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release. 

   Input Arguments:
      model          - The pointer to the model to export. 
                       If NULL the current model will be used.
      out_file_name  - The name of the output file.
      file_type      - The type of file to export (STL, Inventor,
                       and so on).
      parameters     - ProArray of parameters to be set; 
                       in this version this array always has 3 elements,
                       which are interpreted as: 
                       chord_height, angle_control, step_size
                       (in future this array may be expanded).

                       angle_control must be from 0.0 to 1.0

                       Setting chord_height or step_size to values too big or
                       too small (for instance, bigger than the model
                       size or smaller than the model absolute accuracy)
                       may cause an error.

                       If angle_control is out of bounds it will be changed
                       to the closest limit without returning an error.
      config_flags   - Bit flags (PRO_FACET_STEP_SIZE_ADJUST and others) to control
                       facet export. See comments against these flags
                       for how to use them.
      transf         - The transformation matrix.
                       If NULL, no transformation will be applied.
      comp_path      - The component path, in the case of an 
                       assembly component. If the model is a part, set  
                       this to NULL.

   Output Arguments:
      None

   Return Values:

   PRO_TK_NO_ERROR      - The function successfully exported the file. 
   PRO_TK_BAD_INPUTS    - parameters array is NULL or its size is not 3;
                          or flags values are incorrect;
                          or you specified a nonexistent file type.
   PRO_TK_GENERAL_ERROR - There was a triangulation failure.
   PRO_TK_NO_LICENSE    - You do not have a license.
   PRO_TK_BAD_CONTEXT   - The function is not available in 
                          Design Test Mode.      
   
*/

/********** file list api prototype. **********/ 
 
typedef enum pro_file_list_option
{
 PRO_FILE_LIST_ALL = 0,            /* list all the versions of a file        */
 PRO_FILE_LIST_LATEST,             /* list only the latest version of a file */
 PRO_FILE_LIST_ALL_SORTED,         /* list all the versions of a file (& sort) */
 PRO_FILE_LIST_LATEST_SORTED,      /* list only the latest version of a file (& sort) */
 PRO_FILE_LIST_ALL_INST,           /* same as LIST_ALL & show instances for PDM locations */
 PRO_FILE_LIST_LATEST_INST,        /* same as LIST_LATEST & show instances for PDM locations */ 
 PRO_FILE_LIST_ALL_SORTED_INST,    /* same as LIST_ALL_SORTED & show instances for PDM locations */
 PRO_FILE_LIST_LATEST_SORTED_INST  /* same as LIST_LATEST_SORTED & show instances for PDM locations */
}       ProFileListOpt;
 
extern ProError ProFilesList (ProPath            directory_path,
                       ProLine            filter,
                       ProFileListOpt     listing_option,
                       ProPath          **p_file_name_array,
                       ProPath          **p_subdir_name_array);
/*
   Purpose:  Lists the files in the specified directory. You can pass specific 
             filters to get files with those extensions only.
 
   Input Arguments:
 
     directory_path     -  The directory in which to look for
                           the files to be listed. If this is NULL, 
                           the files from the current directory will be
                           listed.
 
     filter             -  The user-supplied filter string for file
                           extensions. Each filter must be separated
                           by a comma. For example, "*.prt,*.txt"
                           (converted to a wide-character string).
                           Each individual element in the filter must
                           be less than PRO_NAME_SIZE characters.
 
     listing_option     -  Specifies whether all versions or only the
                           latest versions are being requested, and whether or
                           not the list should be sorted alphabetically.

                           <b>Note: </b>Passing any of _INST options 
                           in Wildfire 4.0 M100 and earlier will have the same
                           effect as passing PRO_FILE_LIST_LATEST.
 
   Output Arguments:
 
     p_file_name_array  -   The array of files found. You must preallocate
                            this array using <b>ProArrayAlloc()</b>; if you
                            reuse the array, new elements will be appended to
                            the existing elements unless you reset the array
                            size to 0 with ProArraySizeSet.

     p_subdir_name_array -  The array of all subdirectories found,
                            regardless of whether they match the filter.
                            You must preallocate this array using 
                            <b>ProArrayAlloc()</b>; if you reuse the array,
                            new elements will be appended to the existing
                            elements unless you reset the array size to 0 with
                            ProArraySizeSet.
 
   Return Values:
 
     PRO_TK_NO_ERROR    - The function successfully returned the files. 
     PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
	 PRO_TK_INVALID_DIR - Invalid directory.

   See Also:
     ProArrayAlloc() 
*/
 
extern ProError ProFilenameParse (ProPath       file_name_w_path,
                           ProPath       r_path,
                           ProName       r_file_name,
                           ProName       r_extension,
                           int          *r_version);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProFileMdlnameParse
   Purpose: <b>Note:</b> This function is deprecated
            Use ProFileMdlnameParse instead.

             Parses the specified file name into its components.
 
   Input Arguments:
 
     file_name_w_path   - The full file name, composed of the path, name,
                          extension, and version.
 
   Output Arguments:
 
     r_path             - The directory path. This argument is
                          optional (can be NULL).
 
     r_file_name        - The file name. This argument is
                          optional (can be NULL). Free this argument using
                          ProWstringFree.
 
     r_extension        - The file extension. This argument is
                          optional (can be NULL). Free this argument using
                          ProWstringFree.
 
     r_version          - The file version. This argument is
                          optional (can be NULL).
 
   Return Values:
 
     PRO_TK_NO_ERROR    -  The function successfully parsed the file name.
     PRO_TK_BAD_INPUTS  -  The specified file name was invalid.
*/

extern ProError ProFileMdlnameParse (ProPath       file_name_w_path,
                           ProPath         r_path,
                           ProMdlName      r_file_name,
                           ProMdlExtension r_extension,
                           int          *  r_version);
/*
   Purpose: Parses the specified file name into its components.
 
			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
 
     file_name_w_path   - The full file name, composed of the path, name,
                          extension, and version.
 
   Output Arguments:
 
     r_path             - The directory path. This argument is
                          optional (can be NULL).
 
     r_file_name        - The file name. This argument is
                          optional (can be NULL).
 
     r_extension        - The file extension. This argument is
                          optional (can be NULL).
 
     r_version          - The file version. This argument is
                          optional (can be NULL).
 
   Return Values:
 
     PRO_TK_NO_ERROR    -  The function successfully parsed the file name.
     PRO_TK_BAD_INPUTS  -  The specified file name was invalid.
*/

extern ProError Pro2dImportCreate(
     ProImportExportFile format,
     ProPath filename, 
     ProName name,
     ProMdlType mtype,
     ProBoolean import_2d_views,
     ProBoolean scale_to_fit,
     ProBoolean fit_left_corner,
     ProMdl *new_model) ;
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: Pro2dImportMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use Pro2dImportMdlnameCreate instead.

            Creates a new 2d Creo Parametric model by importing a 2d geometry file.

   Input Arguments:

       format             - The type of file to be imported. The following
                            values are supported:
                            <UL>
                             <LI>PRO_STEP_FILE
                             <LI>PRO_IGES_FILE
                             <LI>PRO_DXF_FILE
                             <LI>PRO_DWG_FILE
                             <LI>PRO_CGM_FILE 
                             <LI>PRO_MEDUSA_FILE 
                             <LI>PRO_CCD_DRAWING_FILE 
                             </UL>
                            Note: To import the 2d MEDUSA file set the config
                            option "allow_medusa_draw_import" to yes.

       filename          -  The name (absolute path or relative path) of the file to be imported.
                            The name of the MEDUSA files must have the format
                            s.objectname.

       name              -  The name of the model to be created.

       mtype             -  The type of model to create.
                            Must be PRO_MDL_DRAWING,
                            PRO_MDL_LAYOUT,
                            PRO_MDL_DIAGRAM or
                            PRO_MDL_DWGFORM.

       import_2d_views   -  Whether to import 2d drawing views.

       scale_to_fit      -  If the current model has a different sheet size from
                            that specified by the imported file, scale_to_fit
                            should be TRUE to retain the current sheet size, or
                            FALSE to adopt the new one.

       fit_left_corner   - If the imported file retain its original sheet size, 
                            the bottom left corner of the file will be adjusted
                            to the bottom left corner of the current model 
                            for PRO_B_TRUE, 
                            and imported "as is" for PRO_B_FALSE.

   Output Arguments:

       new_model         - The new model that Creo Parametric created.

   Return Values:
      PRO_TK_NO_ERROR     - Imported file appended successfuly to the current model.
      PRO_TK_BAD_INPUTS   - Illegal model type or import file type.
      PRO_TK_INVALID_FILE - The input file could not be found, or contained unrecoverable 
                            errors.
      PRO_TK_NO_LICENSE   - There is no license for this import option.
      PRO_TK_CANT_OPEN    - Failed to create drawing.
      PRO_TK_OBSOLETE_FUNC- The file format selected is no longer 
                            supported on this platform.
*/

extern ProError Pro2dImportMdlnameCreate(
     ProImportExportFile format,
     ProPath filename, 
     ProMdlName name,
     ProMdlType mtype,
     ProBoolean import_2d_views,
     ProBoolean scale_to_fit,
     ProBoolean fit_left_corner,
     ProMdl *new_model) ;
/*
   Purpose: Creates a new 2d Creo Parametric model by importing a 2d geometry file.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:

       format             - The type of file to be imported. The following
                            values are supported:
                            <UL>
                             <LI>PRO_STEP_FILE
                             <LI>PRO_IGES_FILE
                             <LI>PRO_DXF_FILE
                             <LI>PRO_DWG_FILE
                             <LI>PRO_CGM_FILE 
                             <LI>PRO_MEDUSA_FILE 
                             <LI>PRO_CCD_DRAWING_FILE 
                             </UL>
                            Note: To import the 2d MEDUSA file set the config
                            option "allow_medusa_draw_import" to yes.

       filename          -  The name (absolute path or relative path) of the file to be imported.
                            The name of the MEDUSA files must have the format
                            s.objectname.

       name              -  The name of the model to be created.

       mtype             -  The type of model to create.
                            Must be PRO_MDL_DRAWING,
                            PRO_MDL_LAYOUT,
                            PRO_MDL_DIAGRAM or
                            PRO_MDL_DWGFORM.

       import_2d_views   -  Whether to import 2d drawing views.

       scale_to_fit      -  If the current model has a different sheet size from
                            that specified by the imported file, scale_to_fit
                            should be TRUE to retain the current sheet size, or
                            FALSE to adopt the new one.

       fit_left_corner   - If the imported file retain its original sheet size, 
                            the bottom left corner of the file will be adjusted
                            to the bottom left corner of the current model 
                            for PRO_B_TRUE, 
                            and imported "as is" for PRO_B_FALSE.

   Output Arguments:

       new_model         - The new model that Creo Parametric created.

   Return Values:
      PRO_TK_NO_ERROR     - Imported file appended successfuly to the current model.
      PRO_TK_BAD_INPUTS   - Illegal model type or import file type.
      PRO_TK_INVALID_FILE - The input file could not be found, or contained unrecoverable 
                            errors.
      PRO_TK_NO_LICENSE   - There is no license for this import option.
      PRO_TK_CANT_OPEN    - Failed to create drawing.
      PRO_TK_OBSOLETE_FUNC- The file format selected is no longer 
                            supported on this platform.
      PRO_TK_INVALID_NAME - Length of the new model name is more than 31 chars.                            
*/

extern ProError Pro2dImportAppend(
     ProImportExportFile format,
     ProPath filename, 
     ProMdl model,
     ProBoolean scale_to_fit,
     ProBoolean fit_left_corner) ;

/*
   Purpose: Imports a 2d geometry file into an existing 2d Creo Parametric model.

   Input Arguments:

       format               -   The type of file to be imported. The following 
                                values are supported:
                                <UL>
                                 <LI>PRO_STEP_FILE
                                 <LI>PRO_IGES_FILE
                                 <LI>PRO_DXF_FILE
                                 <LI>PRO_DWG_FILE
                                 <LI>PRO_CGM_FILE
                                 <LI>PRO_MEDUSA_FILE
                                 <LI>PRO_CCD_DRAWING_FILE 
                                </UL>

       filename             -   The name (absolute path or relative path ) of the file to be imported.

       model                -   The model into which to append the data.

       scale_to_fit         -   If the current model has a different sheet size from
                                that specified by the imported file, scale_to_fit
                                should be TRUE to retain the current sheet size, or
                                FALSE to adopt the new one .

       fit_left_corner      -   If the imported file retain his original sheet size, 
                                the bottom left corner of the file will be adjusted to 
                                bottom left corner of the current model for PRO_B_TRUE, 
                                and imported "as is" for PRO_B_FALSE.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - Imported file appended successfuly to the current model.
      PRO_TK_BAD_INPUTS   - Illegal model type or import file type.
      PRO_TK_INVALID_FILE - The input file could not be found, or contained unrecoverable 
                            errors.
      PRO_TK_NO_LICENSE   - There is no license for this import option.
      PRO_TK_OBSOLETE_FUNC- The file format selected is no longer 
                            supported on this platform.
*/


extern ProError Pro2dExport(ProImportExportFile     format,
                            ProPath                 filename,
                            ProMdl                  model,
                            Pro2dExportdata         data);

/*
    Purpose: Exports 2d models to a file. The following output formats are 
             supported: 
             <UL> 
             <LI> PRO_STEP_FILE 
             <LI> PRO_IGES_FILE 
             <LI> PRO_MEDUSA_FILE 
             <LI> PRO_DXF_FILE
             <LI> PRO_DWG_FILE
             <LI> PRO_CGM_FILE
             <LI> PRO_STHENO_FILE
             <LI> PRO_SNAP_TIFF_FILE
             </UL>
             Note that the output can be controlled by a combination of the 
             input argument 'data' and several Creo Parametric configuration 
             options related to entity type export options.

    Input Arguments:
        format - The type of file to be exported.
        filename - The name and absolute path of the export file to be created.
        model - The 2d model from which the information is to be exported.
        data - The instructions used for the export.  Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - Illegal import file type.
        PRO_TK_BAD_CONTEXT - The model was not a 2D model.
        PRO_TK_NO_LICENSE - There is no license for this import option.
        PRO_TK_OBSOLETE_FUNC - The file format selected is no longer 
                               supported on this platform.
        PRO_TK_BAD_CONTEXT   - The function is not available in 
                               Design Test Mode.      
                               

*/


extern ProError Pro2dExportdataAlloc (Pro2dExportdata* export_data);
/*
    Purpose: Allocates the handle containing 2D export options and flags, to be 
             used in Pro2dExport().

    Input Arguments:
        none

    Output Arguments:
        export_data - The handle.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError Pro2dExportdataFree (Pro2dExportdata export_data);
/*
    Purpose: Frees the handle containing 2D export options and flags, to be 
             used in Pro2dExport().

    Input Arguments:
        export_data - The handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError Pro2dExportdataSheetoptionSet (Pro2dExportdata export_data, Pro2dExportSheetOption sheet_option);
/*
    Purpose: Assigns the sheet export option for the export to a 2D format.

    Input Arguments:
        export_data - The 2D export data.
        sheet_option - The sheet export option.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError Pro2dExportdataSheetsSet (Pro2dExportdata export_data, int* sheets);
/*
    Purpose: Assigns the sheet numbers to export to the 2D export format file.  
             Used only if the sheet option is set to PRO2DEXPORT_SELECTED.  
             Sheet numbers range from 1 to the number of sheets. All the 
             selected sheets will be exported to paper space. If a sheet has to 
             be exported to model space, use Pro2dExportdataModelspacesheetSet()
             to assign it.

    Input Arguments:
        export_data - The export data.
        sheets - ProArray of the sheet numbers to export.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/




extern ProError Pro2dExportdataModelspacesheetSet (Pro2dExportdata export_data, int model_space_sheet);
/*
    Purpose: Assigns the sheet number to be exported to model space.  Used only 
             if the export format supports the concept of model space and paper 
             space, and if the sheet option is PRO2DEXPORT_SELECTED.  Sheet 
             numbers range from 1 to the number of sheets. Export other sheets 
             to paper space using Pro2dExportdataSheetsSet().

    Input Arguments:
        export_data - The export data.
        model_space_sheet - The sheet number to export to model space.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/



extern ProError ProPathCreate(ProPath       path,
			      ProName       file_name,
			      ProName       extension,
			      int           version,
			      ProPath       r_file_name_w_path);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProPathMdlnameCreate
   Purpose: <b>Note:</b> This function is deprecated
            Use ProPathMdlnameCreate instead.

             Builds a path, given its components.
 
   Input Arguments:
 
     path               - The directory path. This argument is
                          optional (can be NULL).
 
     file_name          - The file name. This argument is
                          optional (can be NULL).
 
     extension          - The file extension. This argument is
                          optional (can be NULL).
 
     version            - The file version. This argument is
                          optional (can be PRO_VALUE_UNUSED).
 
   Output Arguments:
 
     r_file_name_w_path - The full file name, composed of the path, name,
                          extension, and version.
 
   Return Values:
 
     PRO_TK_NO_ERROR    - The function successfully built the path.
     PRO_TK_BAD_INPUTS  - The specified file name was invalid.
*/

extern ProError ProPathMdlnameCreate(ProPath       path,
				     ProMdlName    file_name,
				     ProMdlExtension extension,
				     int           version,
				     ProPath       r_file_name_w_path);
/*
   Purpose:  Builds a path, given its components.
 
 			<b>Note:</b> In Creo 3 this function does not support names longer than 
 			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
 
     path               - The directory path. This argument is
                          optional (can be NULL).
 
     file_name          - The file name. This argument is
                          optional (can be NULL).
 
     extension          - The file extension. This argument is
                          optional (can be NULL).
 
     version            - The file version. This argument is
                          optional (can be PRO_VALUE_UNUSED).
 
   Output Arguments:
 
     r_file_name_w_path - The full file name, composed of the path, name,
                          extension, and version.
 
   Return Values:
 
     PRO_TK_NO_ERROR    - The function successfully built the path.
     PRO_TK_BAD_INPUTS  - The specified file name was invalid.
*/

LIB_COREUTILS_API  ProError ProStringCopy (char* string, char** to);
/*
  Purpose: Copies a string into memory allocated by Creo Parametric.  This allows you
           to free the string with ProStringFree() and allows Creo Parametric to
           free this string if necessary.

  Input Arguments:
      string - The original string.

  Output Arguments:
      to - The copy of the string.  Creo Parametric allocates memory for this
           argument.

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_OUT_OF_MEMORY - The function failed to allocate memory for the new string.
*/

LIB_COREUTILS_API  ProError ProStringFree( char* string );
/*
   Purpose: free a string returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      string               - The string

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

LIB_COREUTILS_API  ProError ProIntarrayFree( int* plain_array );
/*
   Purpose: Free a plain integer array returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      plain_array               - The plain integer array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

LIB_COREUTILS_API  ProError ProStringarrayFree( char** str_arr, int ct );
/*
   Purpose: free an array of strings returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      str_arr              - The array of strings
      ct                   - The number of strings in the array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

LIB_COREUTILS_API  ProError ProStringproarrayFree( char** str_arr );
/*
   Purpose: free a ProArray of strings returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      str_arr              - The array of strings

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

LIB_COREUTILS_API  ProError ProWstringFree( wchar_t* wstring );
/*
   Purpose: free a wide-string returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      wstring              - The wide-string

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

LIB_COREUTILS_API  ProError ProWstringarrayFree( wchar_t** wstr_arr, int ct );
/*
   Purpose: free an array of wide-strings returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      wstr_arr             - The array of wide-strings
      ct                   - The number of strings in the array
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

LIB_COREUTILS_API  ProError ProWstringproarrayFree( wchar_t** wstr_arr );
/*
   Purpose: free a ProArray of wide-strings returned by a Creo Parametric TOOLKIT function

   Input Arguments:
      wstr_arr             - The array of wide-strings

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The memory was freed
      PRO_TK_GENERAL_ERROR - The memory was not freed, e.g. due to bad address
*/

extern ProError ProProductviewExport( ProMdl mdl,
                                      ProPath export_dir,
                                      ProName filename );
/*

  DEPRECATED: Since Wildfire 5.0
  SUCCESSORS: ProProductviewFormattedMdlnameExport
  Purpose: <b>NOTE:</b>
  <p>
  This function is <b>deprecated</b>. 
  Use ProProductviewFormattedMdlnameExport() instead.
  <p>  
  Exports a part, assembly or drawing to a Creo View format.

  Input Arguments:
     mdl                  - The model handle. If mdl is a drawing, it must be displayed in a window.
                            Depending upon the model type, following
                            output files are created: 

                            <UL>
                            <LI> Part     :  .ed file, .ol file
                            <LI> Assembly :  .ed file, seperate .ol file for each part contained in the assembly
                            <LI> Drawing  :  .ed file, .plt file
                            </UL>

     export_dir           - The location where the export file(s) will be produced.
                            If NULL, the Creo Parametric working directory is used.
     filename             - The root of the filename to export (without the extension).
                            If NULL, the Creo Parametric model name is used as the root.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The export succeeded.
     PRO_TK_BAD_INPUTS    - One or more input arguments is invalid.
     PRO_TK_NOT_DISPLAYED - Model not displayed in any window.
     PRO_TK_E_NOT_FOUND   - pro2prod_view.dll not found 
     PRO_TK_BAD_CONTEXT   - pro2prod_view.dll could not be loaded 
     PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.
*/


extern ProError ProProductviewexportoptsAlloc (
                        ProProductviewExportOptions* opts);
/*
    Purpose: Allocates a new set of Creo View Export options. 

    Input Arguments:
        none

    Output Arguments:
        opts - The Creo View Export options.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/

extern ProError ProProductviewexportoptsFree (ProProductviewExportOptions opts);
/*
    Purpose: Frees a set of Creo View Export options.

    Input Arguments:
        opts - The Creo View Export options.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.

*/


extern ProError ProProductviewexportoptsFormatSet (
         ProProductviewExportOptions opts, ProProductviewFormat format);
/*

  Purpose: Sets the flag specifying the Creo View export format.


  Input Arguments:
       opts        - The Creo View export options.
       format      - The export format to use.
 
     Output Arguments:
         none
 
     Return Values:
         PRO_TK_NO_ERROR - The function succeeded.
         PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 
*/


extern ProError ProProductviewFormattedExport( ProMdl mdl,
                                      ProPath export_dir,
                                      ProName filename,
                                      ProProductviewExportOptions opts );
/*
  DEPRECATED: Since Creo 3
  SUCCESSORS: ProProductviewFormattedMdlnameExport
  Purpose: <b>Note:</b> This function is deprecated
           Use ProProductviewFormattedMdlnameExport instead.

           Exports a part, assembly or drawing to a user-specified
           Creo View format.

  Input Arguments:
     mdl                  - The model handle. If mdl is a drawing, it must be displayed in a window.
                            Depending upon the model type and export options, following
                            output files are created: 

                            <UL>
                            
                            <P>PRO_PV_FORMAT_PVS:
                            <LI> Part     :  .pvs file, .ol file
                            <LI> Assembly :  .pvs file, separate .ol file for
                                             each part contained in the assembly
                            <LI> Drawing  :  .pvs file, .plt file
    
                            <P>PRO_PV_FORMAT_ED:
                            <LI> Part     :  .ed file, .ol file
                            <LI> Assembly :  .ed file, separate .ol file for
                                             each part contained in the assembly
                            <LI> Drawing  :  .ed file, .plt file
 
                            <P>PRO_PV_FORMAT_EDZ: .edz file
                            
                            <P>PRO_PV_FORMAT_PVZ: .pvz file 
                            
                            </UL>

     export_dir           - The location where the export file(s) will be produced.
                            If NULL, the Creo Parametric working directory is used.
     filename             - The root of the filename to export (without the extension).
                            If NULL, the Creo Parametric model name is used as the root.
     opts                 - The export options handle.
  
  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The export succeeded.
     PRO_TK_BAD_INPUTS    - One or more input arguments is invalid.
     PRO_TK_NOT_DISPLAYED - Model not displayed in any window.
     PRO_TK_E_NOT_FOUND   - pro2prod_view.dll not found 
     PRO_TK_BAD_CONTEXT   - pro2prod_view.dll could not be loaded and/or
                            Design Test Mode is active - the function
                            is not available in this mode.
*/

extern ProError ProProductviewFormattedMdlnameExport( ProMdl mdl,
                                      ProPath export_dir,
                                      ProMdlName filename,
                                      ProProductviewExportOptions opts );
/*
  Purpose: Exports a part, assembly or drawing to a user-specified
           Creo View format.

			<b>Note:</b> In Creo 3 this function does not support names longer than 
			31 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

  Input Arguments:
     mdl                  - The model handle. If mdl is a drawing, it must be displayed in a window.
                            Depending upon the model type and export options, following
                            output files are created: 

                            <UL>
                            
                            <P>PRO_PV_FORMAT_PVS:
                            <LI> Part     :  .pvs file, .ol file
                            <LI> Assembly :  .pvs file, separate .ol file for
                                             each part contained in the assembly
                            <LI> Drawing  :  .pvs file, .plt file
    
                            <P>PRO_PV_FORMAT_ED:
                            <LI> Part     :  .ed file, .ol file
                            <LI> Assembly :  .ed file, separate .ol file for
                                             each part contained in the assembly
                            <LI> Drawing  :  .ed file, .plt file
 
                            <P>PRO_PV_FORMAT_EDZ: .edz file
                            
                            <P>PRO_PV_FORMAT_PVZ: .pvz file 
                            
                            </UL>

     export_dir           - The location where the export file(s) will be produced.
                            If NULL, the Creo Parametric working directory is used.
     filename             - The root of the filename to export (without the extension).
                            If NULL, the Creo Parametric model name is used as the root.
     opts                 - The export options handle.
  
  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR      - The export succeeded.
     PRO_TK_BAD_INPUTS    - One or more input arguments is invalid.
     PRO_TK_NOT_DISPLAYED - Model not displayed in any window.
     PRO_TK_E_NOT_FOUND   - pro2prod_view.dll not found 
     PRO_TK_BAD_CONTEXT   - pro2prod_view.dll could not be loaded and/or
                            Design Test Mode is active - the function
                            is not available in this mode.
*/


extern ProError ProEngineerDisplaydatecodeGet( char** display_datecode );
/*
  Purpose:  Returns the Creo Parametric session's customer visible datecode, as
             shown in Creo Parametric Help information.  If it is necessary to
             show an identifier for the Creo Parametric version to the user from
             an application, this value should be used, rather than the value
             passed in to the application's user_initialize().

  Input Arguments:
     none

  Output Arguments:
     display_datecode - The datecode string.  Free this string using ProStringFree.

  Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
*/

extern ProError ProTexturePathGet( ProName      texture_name,  
                                   ProBoolean   create_temp_file, 
                                   ProBoolean  *p_was_embedded, 
                                   ProPath      texture_path);
/*
  Purpose: Looks up the full path to the texture, decal, or bump map file
           indicated.  If the texture is embedded inside a Creo Parametric model,
           instead of being loaded from the texture path, this function will
           write a temporary copy of the file if "create_temp_file" is set to
           true.

  Input Arguments:
     texture_name     - The texture file name.
     create_temp_file - PRO_B_TRUE to have Creo Parametric write a temporary copy
                        of the texture file if its is embedded in a model.
                        PRO_B_FALSE to skip writing the file.
  Output Arguments:
     p_was_embedded  - PRO_B_TRUE if the texture file was embedded. If
                       create_temp_file is also true a copy of the
                       file was written.  The user application is
                       responsible for deleting the copy.  Can be
                       NULL.
     texture_path    - The full path to the texture file. Can be NULL
                       if create_temp_file is PRO_B_FALSE.

  Return Values:
     PRO_TK_NO_ERROR    - The function succeeded.
     PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
     PRO_TK_E_NOT_FOUND - The texture file could not be found on disk or in memory.
     PRO_TK_CANT_WRITE  - The temporary texture file could not be written.
*/

LIB_COREUTILS_API  ProError ProEngineerMultithreadModeEnable( void );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: NONE
   Purpose: <b>Note:</b> This function is deprecated.
	  Call this function from your Creo Parametric TOOLKIT DLL user_initialize() if 
      your application creates additional threads to do processing. 
      Calling this function notifies Creo Parametric that it should run in 
      multi-thread enabled mode. Running in this mode will remove the
      possibility of a memory corruption due to the interaction between 
      Creo Parametric's thread libraries and application-created threads. 
      <P>
      <B>NOTE: </B>In spawn and asynchronous mode, this function can be 
      called but will not have any effect. 
      <P>
      <B>NOTE:</B> Running Creo Parametric in multi-thread enabled mode may 
      slow performance, so this function should be used only for 
      applications that actually create multiple threads.
      <P>
      <B> IMPORTANT NOTE: </B> Calling Creo Parametric TOOLKIT functions from within 
      multiple threads of any application in any mode is not supported. 
      Extra threads may be created by applications only to do tasks 
      which do not directly call Creo Parametric TOOLKIT functions.

   Input Arguments:
      none

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.

*/


extern ProError ProToolkitUnicodeencodingIsEnabled( ProBoolean* unicode_encoding );
/*
    DEPRECATED: Since Creo 3
    SUCCESSORS: NONE
    Purpose: Identifies if this Creo Parametric TOOLKIT application is running with legacy 
             or Unicode encoding.  

    Input Arguments:
        none

    Output Arguments:
        unicode_encoding - PRO_B_TRUE if the application is using Unicode 
                          encoding (the default), PRO_B_FALSE if using legacy 
                          encoding (due to registry file setting or 
                          ProToolkitUnicodeencodingDisable())

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProToolkitUnicodeencodingDisable()
*/


typedef ProBoolean (*ProFileSaveAccessFunction) (wchar_t* file_type,
                                                 ProMdl model, 
                                                 ProAppData app_data );
/*
    Purpose: Callback function to decide if the file type should be selectable
             in File 'Save a Copy' dialog or not.
    Input Arguments:
        file_type - File type
        model - The handle of the model being saved
        app_data - The application data 
    Output Arguments:
        none
    Return Values:
        PRO_B_TRUE - File type should be added in the file dialog.
        PRO_B_FALSE - File type should not be added in the the dialog.
*/

typedef ProError (*ProFileSaveOperationAction) (wchar_t* file_type,
                                                ProMdl model,
                                                ProPath file_path,
                                                ProAppData app_data );
/*
    Purpose: Callback action on pressing OK button in File 'Save a Copy' dialog 
             for the new registered type.
    Input Arguments:
        file_type - File type
        model - The model handle
        file_path - The full file path
        app_data - The application data
    Output Arguments:
        none
    Return Values:
        PRO_TK_NO_ERROR - Callback succeeded.
        PRO_TK_GENERAL_ERROR - Problem in processing this function.
*/

typedef ProBoolean (*ProFileOpenAccessFunction) (wchar_t* file_type,
                                                 ProAppData app_data );
/*
    Purpose: Callback function to evaluate the file type should be selectable
             in the File Open dialog or not.
    Input Arguments:
        file_type - File type
        app_data - The application data 
    Output Arguments:
        none
    Return Values:
        PRO_B_TRUE - File type should be added in the file dialog.
        PRO_B_FALSE - File type should not be added in the the dialog.
*/

typedef ProError (*ProFileOpenOperationAction) (wchar_t* file_type,
                                                ProPath file_path,
                                                ProAppData app_data );
/*
    Purpose: Callback action on pressing open button for the new registered type.
    Input Arguments:
        file_type - File type
        file_path - The full file path
        app_data - The application data 
    Output Arguments:
        none
    Return Values:
        PRO_TK_NO_ERROR - Callback succeeded.
        PRO_TK_GENERAL_ERROR - Problem in processing this function.
*/

extern ProError ProFileSaveRegister (wchar_t* file_type,
                                     wchar_t* file_description,
                                     ProFileSaveAccessFunction access_function,
                                     ProFileSaveOperationAction oper_action,
                                     ProAppData app_data);

/*
    Purpose: Register a file type in the 'File->Save a Copy' dialog interface
    of Creo Parametric.
    <P>
    NOTE: The ProFileSave API opens a standard file dialog. ProFileSaveRegister
    does not work with this API. 

    Input Arguments:
        file_type - File type 
        file_description - Short description of the file.
        access_function - File Access function; NULL is always available
        oper_action - Action on selection of the file type
        app_data -  The application data, may be NULL
    Output Arguments:
        None
    Return Values:
        PRO_TK_NO_ERROR - File type is registered in the dialog.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_OUT_OF_MEMORY - Couldn't allocate memory for new type.
        PRO_TK_E_IN_USE - Already registered by this app.
        PRO_TK_GENERAL_ERROR - Failed to register type.
        PRO_TK_BAD_CONTEXT - The function is not available in 
                             Design Test Mode.      
        
*/

extern ProError ProFileOpenRegister (wchar_t* file_type,
                                     wchar_t* file_description,
                                     ProFileOpenAccessFunction access_function,
                                     ProFileOpenOperationAction oper_action,
                                     ProAppData app_data);

/*
    Purpose: Register a file type with the 'File -> Open' dialog interface
    of Creo Parametric.
    <P>
    NOTE: The ProFileMdlnameOpen OR ProFileMdlfiletypeOpen API opens a standard 
	file dialog. ProFileOpenRegister does not work with this API.

    Input Arguments:
        file_type - File type 
        file_description - Short description of the file.
        access_function - File Access function; NULL is always available
        oper_action - Action on selection of the file type
        app_data -  The application data, may be NULL
    Output Arguments:
        None
    Return Values:
        PRO_TK_NO_ERROR - File type is registered in the dialog.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_OUT_OF_MEMORY - Couldn't allocate memory for new type.
        PRO_TK_E_IN_USE - Already registered by this app.
        PRO_TK_GENERAL_ERROR - Failed to register type.
*/

extern ProError ProEngineerReleaseNumericversionGet( int* ver );
/*
    Purpose: return the integer major version number of the Creo Parametric
             executable that the Creo Parametric TOOLKIT application is
             connected to. This is an absolute number counting from the first
             shipment of PTC's MCAD software; for Creo Parametric 3.0 it
             is 33.

    Input Arguments:
       None

    Output Arguments:
       ver                 - the version

    Return Values:
      PRO_TK_NO_ERROR      - The returned value is valid
      PRO_TK_GENERAL_ERROR - A valid numeric version could not be found.
*/

PRO_END_C_DECLS

#endif  /* PROUTIL_H */
