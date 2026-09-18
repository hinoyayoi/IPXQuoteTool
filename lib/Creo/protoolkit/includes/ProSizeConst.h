#ifndef PRO_SIZE_CONST_H
#define PRO_SIZE_CONST_H

/* Creo Parametric TOOLKIT declarations of commonly needed sizes and sized arrays */

#include <ProToolkit.h>







PRO_BEGIN_C_DECLS


/*  Sizes include a NULL terminator  */

#define   PRO_LINE_SIZE         81
#define   PRO_PATH_SIZE         260
#define   PRO_COMMENT_SIZE      256
#define   PRO_VALUE_SIZE        256

#define   PRO_MDLNAME_SIZE      180	/*  Any Creo Parametric model name  */
#define   PRO_NAME_SIZE         32	/*  Any other Creo Parametric name  */
#define   PRO_TYPE_SIZE         4	/*  "prt", "asm", "drw", etc.  */
#define   PRO_EXTENSION_SIZE    4       /*  size 3;  plus NULL terminator  */
#define   PRO_MDLEXTENSION_SIZE 32
#define   PRO_VERSION_SIZE      4
#define   PRO_MAX_ASSEM_LEVEL   25
#define   PRO_FEATREF_KEY_SIZE  81

					/*  name.ext.#  */
#define   PRO_FILE_MDLNAME_SIZE      ( PRO_MDLNAME_SIZE + \
                                       PRO_MDLEXTENSION_SIZE + \
				       PRO_VERSION_SIZE )

#define   PRO_FILE_NAME_SIZE         (PRO_NAME_SIZE + \
				     PRO_EXTENSION_SIZE + \
				      PRO_VERSION_SIZE)

#define   PRO_FAMTAB_FIELDNAME_SIZE  (PRO_NAME_SIZE + \
				     PRO_EXTENSION_SIZE + \
				      PRO_VERSION_SIZE)

					/*  instance[generic]  */
#define   PRO_FAMILY_MDLNAME_SIZE  (PRO_MDLNAME_SIZE + PRO_MDLNAME_SIZE + 2)
#define   PRO_FAMILY_NAME_SIZE  (PRO_NAME_SIZE + PRO_NAME_SIZE + 2)


/* add other array size constants here */

typedef char	ProCharName[PRO_NAME_SIZE];

typedef char	ProCharPath[PRO_PATH_SIZE];

typedef wchar_t	ProLine[PRO_LINE_SIZE];

typedef wchar_t	ProPath[PRO_PATH_SIZE];

typedef wchar_t	ProMdlName[PRO_MDLNAME_SIZE];

typedef wchar_t	ProMdlExtension[PRO_MDLEXTENSION_SIZE];

typedef wchar_t	ProName[PRO_NAME_SIZE];

typedef wchar_t	ProMdlFileName[PRO_FILE_MDLNAME_SIZE];

typedef wchar_t	ProFileName[PRO_FILE_NAME_SIZE];

typedef wchar_t	ProFamtabClmDesc [PRO_FAMTAB_FIELDNAME_SIZE];

typedef wchar_t	ProFamilyMdlName[PRO_FAMILY_MDLNAME_SIZE];

typedef wchar_t	ProFamilyName[PRO_FAMILY_NAME_SIZE];

typedef wchar_t	ProComment[PRO_COMMENT_SIZE];

/* menu constants */
typedef char ProMenuName[PRO_NAME_SIZE];

typedef char ProMenufileName[PRO_NAME_SIZE];

typedef char ProMenubuttonName[PRO_NAME_SIZE];

/* PRO_MACRO_SIZE is no longer a limiting factor for macros loaded by
ProMacroLoad(). This symbol is maintained for application compatibility
reasons only; it is not used by any Creo Parametric TOOLKIT function. */
#define PRO_MACRO_SIZE 256

typedef wchar_t ProMacro[PRO_MACRO_SIZE];

/* message constant */
typedef char ProCharLine[PRO_LINE_SIZE];

PRO_END_C_DECLS


#endif  /* PRO_SIZE_CONST_H */
