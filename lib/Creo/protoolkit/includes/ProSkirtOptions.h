#ifndef PROSKIRTOPTIONS_H
#define PROSKIRTOPTIONS_H
/*
   Creo Parametric TOOLKIT declarations of skirt surface options.
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS


typedef enum Pro_SkirtShutoffExtType
{
  PRO_SKIRT_EXT_SHUTOFF_BY_DIST     = 1,
  PRO_SKIRT_EXT_SHUTOFF_BY_BOUND    = 2,
  PRO_SKIRT_EXT_SHUTOFF_NONE        = 3

}  ProSkirtShutoffExtType;

typedef enum Pro_SkirtExtType
{
  PRO_SKIRT_EXT_TYPE_NORMAL     = 1,
  PRO_SKIRT_EXT_TYPE_PARALLEL   = 2,
  PRO_SKIRT_EXT_TYPE_TANGENT    = 3,
  PRO_SKIRT_EXT_TYPE_USER       = 4,
  PRO_SKIRT_EXT_TYPE_NORMAL_TO_BNDRY = 5

}  ProSkirtExtType;

typedef enum Pro_SkirtFillType
{
  PRO_SKIRT_FILL_STANDARD       = 0,
  PRO_SKIRT_FILL_MID_PLANE      = 1,
  PRO_SKIRT_FILL_MID_SURF       = 2,
  PRO_SKIRT_FILL_CAP_PLANE      = 3,
  PRO_SKIRT_FILL_CAP_SURF       = 4,
  PRO_SKIRT_FILL_NONE           = 5,
  PRO_SKIRT_FILL_NEAREST_PLANE  = 6

}  ProSkirtFillType;

typedef enum Pro_SkirtExtNextDirOpt
{
  PRO_SKIRT_EXT_NEXT_DIR_DEFAULT   = 1,
  PRO_SKIRT_EXT_NEXT_DIR_ALTERNATE = 2

}  ProSkirtExtNextDirOpt;

#define PRO_SKIRT_EXT_CREATE_TRANS_AUTO   4

PRO_END_C_DECLS

#endif /*PROSKIRTOPTIONS_H*/
