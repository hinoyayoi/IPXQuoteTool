#ifndef PROSHELLH
#define PROSHELLH



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Feature element tree

   PRO_E_FEATURE_TREE
      |
      |-- PRO_E_FEATURE_TYPE
      |
      |-- PRO_E_STD_FEATURE_NAME
      |
      |-- PRO_E_SHELL_SRF
      |
      |-- PRO_E_SHELL_THICK
      |
      |-- PRO_E_SHELL_FLIP
      |
      |-- PRO_E_STD_SURF_COLLECTION_APPL
      |
      |-- PRO_E_SHELL_LACE_BNDRY
      |
      |-- PRO_E_SHELL_ALT_CUT_METHOD
      |
      |-- PRO_E_ST_SHELL_LOCL_LIST
           |
           |-- PRO_E_ST_SHELL_LOCL_CMPD
                |
                |-- PRO_E_ST_SHELL_SPEC_SRF
                |
                |-- PRO_E_ST_SHELL_SPEC_THCK

===============================================================================

(2) Feature elements table

-------------------------------------------------------------------------------
Element Id                     Element Name     Data Type                 Valid Values
-------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type     PRO_VALUE_TYPE_INT        Note-1
PRO_E_STD_FEATURE_NAME         Feature Name     PRO_VALUE_TYPE_WSTRING    Note-2
PRO_E_SHELL_SRF                Remove Surfaces  PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_ST_SHELL_THICK           Main Thickness   PRO_VALUE_TYPE_DOUBLE     Note-4
PRO_E_SHELL_FLIP               Flip             PRO_VALUE_TYPE_INT        ProShellSide
PRO_E_STD_SURF_COLLECTION_APPL Exclude surfaces PRO_VALUE_TYPE_SELECTION  Note-7
PRO_E_SHELL_LACE_BNDRY         Lace boundary    PRO_VALUE_TYPE_INT        ProShellLace
PRO_E_SHELL_ALT_CUT_METHOD     Alternate cut    PRO_VALUE_TYPE_INT        ProShellAltCut
PRO_E_ST_SHELL_LOCL_LIST       Local Thickness  Array
PRO_E_ST_SHELL_LOCL_CMPD       Local Thickness  Compound
PRO_E_ST_SHELL_SPEC_SRF        Surface          PRO_VALUE_TYPE_SELECTION  Note-5
PRO_E_ST_SHELL_SPEC_THCK       Thickness        PRO_VALUE_TYPE_DOUBLE     Note-6

===============================================================================

(3) Notes

   Note-1 : PRO_FEAT_SHELL

   Note-2 : Shell feature name. 

   Note-3 : Select the surfaces to be removed from the part to create shell
            feature. Multiple selection allowed. This element is optional.

   Note-4 : Default thickness for the shell.
            Should be positive and bigger than zero.

   Note-5 : Select a surface to specify a local thickness value.
            Only single selection is allowed.
            Cannot select any of the "Remove Surfaces".

   Note-6 : Local thickness value for surface selected in Note-6.
            Should be positive and bigger than zero.

   Note-7 : Select surfaces to be excluded during shell.
            Use Lace boundary to specify closure of excluded part.
            Use Alternate cut to specify cut method for extracting interior.

==============================================================================*/

/* PRO_E_SHELL_FLIP values */

typedef enum
{
   PRO_SHELL_OUTSIDE = -1,
   PRO_SHELL_INSIDE  = 1
} ProShellSide;

typedef enum
{
   PRO_SHELL_LACE       = 0,
   PRO_SHELL_DONT_LACE  = 1
} ProShellLace;

typedef enum
{
   PRO_SHELL_ALT_CUT_METHOD_NO  = 0,
   PRO_SHELL_ALT_CUT_METHOD_YES = 1
} ProShellAltCut;

PRO_END_C_DECLS

#endif
