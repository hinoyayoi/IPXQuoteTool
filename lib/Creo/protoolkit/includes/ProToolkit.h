#ifndef PROTOOLKIT_H
#define PROTOOLKIT_H

/* Creo Parametric TOOLKIT default includes and declarations */



#include        <ProLibAPI.h>
#include        <ProANSI.h>

/* To define  WCHAR_T */
#include        <ProWchar.h>

/* Standard system header files */
#include        <stdio.h>
#include        <string.h>


/* Additional Standard definitions */
#ifdef __STDC__
#include        <stddef.h>
#include        <stdlib.h>
#endif

#include        <ProConst.h>
#include        <ProSizeConst.h>
#include        <ProToolkitErrors.h>  /* Extracted from this file I-01-16 */

PRO_BEGIN_C_DECLS


#define PRO_VALUE_UNUSED (-1)
#define PRO_VALUE_DEFAULT (-5)

typedef enum  ProBooleans  
   {
      PRO_B_FALSE = 0,
      PRO_B_TRUE  = 1
   } ProBoolean, ProBool;


typedef enum
{
      PRO_COLOR_UNDEFINED	= PRO_VALUE_UNUSED,
      PRO_COLOR_LETTER		= 0,
      PRO_COLOR_HIGHLITE	= 1,
      PRO_COLOR_DRAWING		= 2,
      PRO_COLOR_BACKGROUND 	= 3,
      PRO_COLOR_HALF_TONE	= 4,
      PRO_COLOR_EDGE_HIGHLIGHT	= 5,
      PRO_COLOR_DIMMED		= 6,
      PRO_COLOR_ERROR		= 8,
      PRO_COLOR_WARNING		= 9,

      PRO_COLOR_SHEETMETAL      = 10,
      PRO_COLOR_CURVE           = 12,

      PRO_COLOR_PRESEL_HIGHLIGHT = 18,
      PRO_COLOR_SELECTED = 19,
      PRO_COLOR_SECONDARY_SELECTED = 20,
      PRO_COLOR_PREVIEW_GEOM = 21,
      PRO_COLOR_SECONDARY_PREVIEW = 22,
      PRO_COLOR_DATUM = 23,
      PRO_COLOR_QUILT = 24,
      PRO_COLOR_LWW = 25,
      PRO_COLOR_SHADED_EDGE = 28,
      PRO_COLOR_SS_HAS_FROZEN_FEAT = 29,
      PRO_COLOR_SS_FROZEN_COMPONENT = 30,
      PRO_COLOR_SS_FAILED_ITEMS = 31,
      PRO_COLOR_SS_PACKAGED = 32,
      PRO_COLOR_SS_RECENT_SEARCH = 33,
      PRO_COLOR_SS_INTCH_GROUP_MEMBERS = 34,
      PRO_COLOR_SS_REPLACED_COMPS = 35,
      PRO_COLOR_SS_FT_INSTANCES = 36,
      PRO_COLOR_SS_FT_GENERICS = 37,
      PRO_COLOR_SS_HAS_PROPROGRAM = 38,
      PRO_COLOR_SS_HAS_PROPROGRAM_INPUT = 39,
      PRO_COLOR_SS_DRIVEN_BY_PROPROGRAM = 40,
      PRO_COLOR_SS_MODULE_NODES = 41,
      PRO_COLOR_SS_CURRENT_DESIGN_SOL = 42,
      PRO_COLOR_SS_NONCURRENT_DESIGN_SOL = 43,
      PRO_COLOR_SS_REPRESENTATIVE_DESIGN_SOL = 44,
      PRO_COLOR_SS_CONF_ASM_NODES = 45,
      PRO_COLOR_SS_CHILD_OF_MODIFIED_IN_DMA = 46,
      PRO_COLOR_MODCHK_HIGHLIGHT = 47,
      PRO_COLOR_MODCHK_PARENT_HIGHLIGHT = 48,
      PRO_COLOR_SS_UPD_CONTROL_GROUP = 49,
      PRO_COLOR_SS_CONTAINS_MATHCAD_WORKSHEET = 50,

      PRO_COLOR_MAX                     /* maximum color value */
} ProColortype;

PRO_END_C_DECLS


#endif  /* PROTOOLKIT_H */
