#ifndef PROFEATFORM_H
#define PROFEATFORM_H






#include <ProToolkit.h>


PRO_BEGIN_C_DECLS


typedef enum Pro_FeatFormType
{
  PRO_NOTYPE    = 0,
  PRO_EXTRUDE   = 1,
  PRO_REVOLVE   = 2,
  PRO_SWEEP     = 4,
  PRO_THIN      = 128,
  PRO_USE_SURFS = 512,
  PRO_FLAT      = 1024,
  PRO_COPY      = 4096,
  PRO_SHUT      = 1<<18, /* Form type for the shutoff surface feature. */
  PRO_SKIRT_EXT  = 1<<19,  /* Form type for the skirt surface extension feature. */
  PRO_SKIRT_FILL = 1<<20,  /* Form type for the skirt surface fill feature. */
  PRO_PRTSPLIT   = 1<<21   /* Form type for the parting split feature. */
}  ProFeatFormType;
 


PRO_END_C_DECLS
 
#endif
