#ifndef PROBROWSER_H
#define PROBROWSER_H



#include <ProToolkit.h>
PRO_BEGIN_C_DECLS

extern ProError ProBrowserAuthenticate(wchar_t* username , wchar_t* password);

/*
   Purpose: Preset username and password to allow automatic login into 
            HTTP servers 
            that require authentication
   
   Input Arguments:
       username -            The name of user to be used 
       password -            The password of the user to be used

   Output Arguments:
      None

   Return Values:
     PRO_TK_NO_ERROR  - The function successfully set the credentials.
                        Note that if authentication fails with these
                        credentials the user may be prompted for authentication.
*/

PRO_END_C_DECLS

#endif
