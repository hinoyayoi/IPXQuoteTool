#ifndef PRORIBBON_H
#define PRORIBBON_H

#include <ProToolkit.h>

/* PRORIBBON.H */




PRO_BEGIN_C_DECLS


typedef enum {
 PRO_RBNCONTEXT_DWG_NONE       = 0,
 PRO_RBNCONTEXT_DWG_LAYOUT     = 1,
 PRO_RBNCONTEXT_DWG_TABLE      = 2,
 PRO_RBNCONTEXT_DWG_ANNOTATE   = 3,
 PRO_RBNCONTEXT_DWG_SKETCH     = 4,
 PRO_RBNCONTEXT_DWG_AUTOBUILDZ = 5,
 PRO_RBNCONTEXT_DWG_REVIEW     = 6,
 PRO_RBNCONTEXT_DWG_PUBLISH    = 7
} ProRibbonContext;


extern ProError ProRibbonContextSet( int win_id,
                                     ProRibbonContext context);
/*
Purpose: Set the current context for the specified window.

Input Arguments:
    win_id -  the window id. You may use PRO_VALUE_UNUSED to indicate the
              current window.  Currently, only the current window is supported.
    context - the ribbon context.

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProRibbonContextGet( int win_id,
                                     ProRibbonContext* context);
/*
Purpose: Get the current context for the specified window.

Input Arguments:
    win_id -  the window id. You may use PRO_VALUE_UNUSED to indicate the
              current window.  Currently, only the current window is supported.

Output Arguments:
    context - the ribbon context.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/


PRO_END_C_DECLS

#endif /* PRORIBBON_H */
