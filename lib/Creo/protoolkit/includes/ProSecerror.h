

#ifndef PROSECERRORDOTH
#define PROSECERRORDOTH

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSelection.h>
#include <ProItemerr.h>
#include <Pro2dEntdef.h>
#include <ProSecdimType.h>
#include <ProSizeConst.h>

PRO_BEGIN_C_DECLS

typedef struct pro_sec_error* ProWSecerror;

typedef wchar_t ProMsg[PRO_PATH_SIZE];
typedef int ProSecerrCode;
typedef int ProSecerrSever;
typedef int ProSecerrAttr;

extern ProError ProSecerrorAlloc (ProWSecerror *PUserErr);

/* 
   Purpose:
        Allocates a workspace table of section-solving and regeneration errors.

   Input Arguments:
        None

   Output Arguments:
        PUserErr - A pointer to the errors table

   Return Values:                                                            
        PRO_TK_NO_ERROR    - The function successfully allocated the errors
                             table.
        PRO_TK_BAD_INPUTS  - The pointer is NULL.
*/

extern ProError ProSecerrorFree (ProWSecerror *PUserErr);

/* 
   Purpose:
        Frees the workspace table of section-solving and regeneration errors.

   Input Arguments:
        PUserErr - A pointer to the errors table

   Output Arguments:
        None

   Return Values:                                                            
        PRO_TK_NO_ERROR   - The function successfully freed the memory.
        PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProSecerrorCount (ProWSecerror *PUserErr,
				  int *r_count);

/* 
   Purpose:
        Counts the number of entries in the table of section-solving 
        and regeneration errors.

   Input Arguments:
        PUserErr - A pointer to the errors table

   Output Arguments:
        r_count  - The number of entries in the table

   Return Values:                                                            
        PRO_TK_NO_ERROR   - The function successfully counted the number
                            of entries.
        PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProSecerrorAdd (ProWSecerror  *PUserErr,
				ProSecerrCode   user_error,
			        wchar_t        *msg,
			        ProSecerrSever  user_severity,
			        int             user_ent_id,
			        ProSecerrAttr   user_attribute);

/*
   Purpose:
        Adds a user-composed error to the errors table.

   Input Arguments:
        PUserErr       - The pointer to the errors table. You initialize
                         this table using the function 
                         <b>ProSecerrorAlloc()</b>.
        user_error     - An integer code for a particular type of error.
        msg            - A pointer to a user-created message in a wide 
                         (4 bytes per symbol) format. This input is not
                         altered or released. If the input string exceeds
                         the structure field, the function stores as many
                         symbols as the field holds.
        user_severity  - The assigned severity of the error.
        user_ent_id    - The identifier of the entity that generated the
                         error.
        user_attribute - The user-supplied attributes. 

   Output Arguments:
        None

   Return Values:                                                            
        PRO_TK_NO_ERROR       - The function successfully added the new
                                error to the table.
        PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                                invalid.
        PRO_TK_OUT_OF_MEMORY  - There was a memory error.

   See Also:
        ProSecerrorAlloc()
*/

extern ProError ProSecerrorMsgGet (ProWSecerror UserErr,
                                   int          ith,
				   ProMsg       PMsg);
/*
   Purpose:
        Retrieves the error message from the <i>i</i>th entry in the 
        error table.

   Input Arguments:
        UserErr   - A pointer to the errors table.
        ith       - The number of the table entry.

   Output Arguments:
        PMsg      - A pointer to the message string, in a wide
                    (4 bytes per a symbol) format. Because the string is
                    static, the contents will change upon the next
                    call.

   Return Values:                                                            
        PRO_TK_NO_ERROR    - The function successfully retrieved the
                             information.
        PRO_TK_BAD_INPUTS  - One or more of the input arguments are
                             invalid.
*/

extern ProError ProSecerrorItemGet (ProWSecerror UserErr,
                                    int          ith,
				    int         *r_item);
/*
   Purpose:
        Retrieves the entity that generated the error from the <i>i</i>th entry
        in the error table. 

   Input Arguments:
        UserErr   - A pointer to the errors table
        ith       - The number of the table entry

   Output Arguments:
        r_item    - The identifier of the entity that generated the error

   Return Values:                                                            
        PRO_TK_NO_ERROR   - The function successfully retrieved the
                            information.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

PRO_END_C_DECLS

#endif
