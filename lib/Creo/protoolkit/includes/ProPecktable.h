#ifndef PROPECKTABLE_H
#define PROPECKTABLE_H

/* ProPecktable.h: definitions and action functions for ProPecktable objects */

#include <ProMfg.h>





PRO_BEGIN_C_DECLS


/* TYPEDEFS, ETC */

/* the type 'ProPeckTable' is defined in "ProMfg.h" */

typedef struct  Pro_PeckTableRange  
{
  double  low_dia, high_dia;
  int     n_pecks;
  double  *peck_depth_ratios;    /* parallel arrays with n_pecks elements */
  double  *feed_rates;
} ProPecktableRange;

typedef struct  Pro_PeckTableData  
{
  int                n_ranges;
  ProPecktableRange  *ranges;
} ProPecktableData;

/*===========================================================================*/

extern ProError  ProPecktableCreate (PRO_CONST_ARG  ProPecktableData  *pt_data,
                             ProPecktable                     *r_peck_table);
/*
   Purpose:  Creates (allocates and initializes) a new peck table handle from
             the user-specified data.
<p>
   NOTE:
<p>
        If you specify a feed rate value of less than zero, that cell will
        be left blank. 

   Input Arguments:
      pt_data        - The user-specified peck table data

   Output Arguments:
      r_peck_table   - The handle to the peck table that was created

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully created the peck table.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError  ProPecktableFree  (ProPecktable peck_table);
/*
   Purpose:  Releases the memory occupied by a peck table.

   Input Arguments:
      peck_table     - The handle to the peck table to be freed

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully released the memory.
      PRO_TK_BAD_INPUTS  - The argument is invalid.
*/


PRO_END_C_DECLS


#endif  /* PROPECKTABLE_H_FILE */
