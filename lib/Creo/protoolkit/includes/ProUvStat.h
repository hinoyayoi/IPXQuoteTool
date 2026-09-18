#ifndef PROUVSTS_H
#define PROUVSTS_H




#include <ProANSI.h>

PRO_BEGIN_C_DECLS
 
/* ========================================================================= */
typedef enum uv_point_status
{
   PRO_UV_AMBIGUOUS  = -1,
   PRO_UV_OUTSIDE    =  0,
   PRO_UV_INSIDE     =  1
}  ProUvStatus;
/* ========================================================================= */

PRO_END_C_DECLS

#endif 
