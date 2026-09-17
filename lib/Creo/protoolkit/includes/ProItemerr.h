#ifndef PROITEMERR
#define PROITEMERR



#include <ProToolkit.h>


PRO_BEGIN_C_DECLS


typedef enum  ProErritemTypes
{
   PRO_ERRITEM_NONE = -1,
   PRO_ERRITEM_FEATELEM = 1
} ProErritemType;

typedef struct
{
   int                  err_item_id;
   ProErritemType       err_item_type;
   ProError               error;
} ProItemerror;

typedef struct
{
   ProItemerror         *error_list;
   int                  error_number;
} ProErrorlist;


PRO_END_C_DECLS

#endif
