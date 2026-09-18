#ifndef PRO_PRTSPLIT_OPTIONS_H
#define PRO_PRTSPLIT_OPTIONS_H

/*
   Creo Parametric TOOLKIT declarations of parting split options.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS


typedef enum Pro_PrtSplitVertfaceType
{
  PRO_PRTSPLIT_VERTFACE_CAVITY   = 1,
  PRO_PRTSPLIT_VERTFACE_CORE     = 2

}  ProPrtSplitVertfaceType;

typedef enum Pro_PrtSplitQltType
{
  PRO_PRTSPLIT_QLT_TYPE_CAVITY   = 1,
  PRO_PRTSPLIT_QLT_TYPE_CORE     = 2,
  PRO_PRTSPLIT_QLT_TYPE_SLIDER   = 3

}  ProPrtSplitQltType;


PRO_END_C_DECLS

#endif /*PRO_PRTSPLIT_OPTIONS_H*/
