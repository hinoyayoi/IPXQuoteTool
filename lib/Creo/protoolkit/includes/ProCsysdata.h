#ifndef PROCSYSDATA_H
#define PROCSYSDATA_H

#include   <ProObjects.h>

/*
   Function declarations and specific data structures for ProCsysdata
*/




PRO_BEGIN_C_DECLS

/*===========================================================================*/


typedef struct csys_data_struct
{
    ProVector   x_vector;
    ProVector   y_vector;
    ProVector   z_vector;
    ProVector   origin;
} ProCsysdata;


PRO_END_C_DECLS

#endif /* PROCSYSDATA_H */
