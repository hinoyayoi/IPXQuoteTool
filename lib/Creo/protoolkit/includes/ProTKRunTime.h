



#ifndef PROTKRUNTIME_H_DEFINED
#define PROTKRUNTIME_H_DEFINED


#include <ProToolkit.h>
#include <ProHardware.h>
#include <stdarg.h>

PRO_BEGIN_C_DECLS


extern int ProTKPrintf (
			const char* format_string, ...
			);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             printf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The data will
			 be transcoded to native encoding, which may result in out-of-locale 
			 characters in the results.
             
    Input Arguments:
        format_string - The format string.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters sent to stdout.

*/


extern int ProTKWprintf (
			 const wchar_t* format_string, ...
			 );
/*

    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             wprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The data will
			 be transcoded to native encoding, which may result in out-of-locale 
			 characters in the results.
             
    Input Arguments:
        format_string - The format string.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters sent to stdout.

*/


extern int ProTKFprintf (
			 FILE* file, const char* format_string, ...
			 );

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             fprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The file
			 will receive the data as UNICODE-encoded data.
             
    Input Arguments:
	    file - The file to which the characters will be written.
        format_string - The format string.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters copied into the file.

*/		


extern int ProTKFwprintf (
			  FILE* file, const wchar_t* format_string, ...
			  );

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             fwprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The file
			 will receive the data as UNICODE-encoded data.		 
             
    Input Arguments:
	    file - The file to which the characters will be written.
        format_string - The format string.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters copied into the file.

*/





extern int ProTKSprintf (
			 char* buffer, const char* format_string, ...
			 );

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             sprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The output
             buffer will contain UNICODE data.
             
    Input Arguments:
        format_string - The format string.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
          buffer - The buffer into which the output will be printed.

    Return Values:
        Value - The number of characters copied into the buffer.

*/


extern int ProTKSwprintf (
			  wchar_t* buffer, const wchar_t* format_string, ...
			  );


/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             swprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The output
             buffer will contain UNICODE data.
             
    Input Arguments:
        format_string - The format string.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
          buffer - The buffer into which the output will be printed.

    Return Values:
        Value - The number of characters copied into the buffer.

*/



extern int ProTKSnprintf (
			  char* buffer, size_t size, const char* format_string, ...
			  );

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             snprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The output
             buffer will contain UNICODE data.
             
    Input Arguments:
        format_string - The format string.
		size - The size of the otuput buffer.
        ... - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
          buffer - The buffer into which the output will be printed.

    Return Values:
        Value - The number of characters copied into the buffer.

*/





extern int ProTKVprintf (const char* format_string, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The data will
			 be transcoded to native encoding, which may result in out-of-locale 
			 characters in the results.
             
    Input Arguments:
        format_string - The format string.
        args - The variant values to replace the format specifiers included in 
               the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters sent to stdout.

*/



extern int ProTKVwprintf (const wchar_t* format_string, va_list args);

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vwprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The data will
			 be transcoded to native encoding, which may result in out-of-locale 
			 characters in the results.
             
    Input Arguments:
        format_string - The format string.
        args - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters sent to stdout.

*/



extern int ProTKVfprintf (FILE* file, const char* format_string, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vfprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The file
			 will receive the data as UNICODE-encoded data.
             
    Input Arguments:
	    file - The file to which the characters will be written.
        format_string - The format string.
        args - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters copied into the file.

*/





extern int ProTKVfwprintf (FILE* file, const wchar_t* format_string, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vfwprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The data will
			 be transcoded to native encoding, which may result in out-of-locale 
			 characters in the results.
             
    Input Arguments:
		file - The file to which the characters will be written.
        format_string - The format string.
        args - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
        none

    Return Values:
        Value - The number of characters sent to stdout.

*/






extern int ProTKVsprintf (char* buffer, const char* format_string, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vsprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The output
             buffer will contain UNICODE data.
             
    Input Arguments:
        format_string - The format string.
        args - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
          buffer - The buffer into which the output will be printed.

    Return Values:
        Value - The number of characters copied into the buffer.
*/





extern int ProTKVsnprintf (char* buffer, size_t size, const char* format_string, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vsnprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The output
             buffer will contain UNICODE data.
             
    Input Arguments:
        format_string - The format string.
		size - The number of characters that may be written in the output buffer.
        args - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
          buffer - The buffer into which the output will be printed.

    Return Values:
        Value - The number of characters copied into the buffer.
*/


extern int ProTKVswprintf (wchar_t* buffer, size_t size,const wchar_t* format_string, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vswprintf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The output
             buffer will contain UNICODE data.
             
    Input Arguments:
        format_string - The format string.
		size - The number of characters that may be written in the output buffer.
        args - The variant values to replace the format specifiers included in 
              the string.

    Output Arguments:
          buffer - The buffer into which the output will be printed.

    Return Values:
        Value - The number of characters copied into the buffer.
*/





extern int ProTKScanf (
			    const char* format, ...
			    );

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             scanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        format - The format string used for parsing.

    Output Arguments:
        ... - The parsed contents of the input from stdin.

    Return Values:
        Value - The number of characters parsed by the function.

*/

extern int ProTKWscanf (			 
			     const wchar_t* format, ...
			     );
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             wscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        format - The format string used for parsing.

    Output Arguments:
        ... - The parsed contents of the input from stdin.

    Return Values:
        Value - The number of characters parsed by the function.

*/




extern int ProTKFscanf (
			     FILE* file, const char* format, ...
			     );

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             fscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
	    file - The file from which to read data.
        format - The format string used for parsing.

    Output Arguments:
        ... - The parsed contents of the input from the file.

    Return Values:
        Value - The number of characters parsed by the function.

*/

extern int ProTKFwscanf (		
			      FILE* file, const wchar_t* format, ...
			      );
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             fwscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
	    file - The file from which to read data.
        format - The format string used for parsing.

    Output Arguments:
        ... - The parsed contents of the input from the file.

    Return Values:
        Value - The number of characters parsed by the function.

*/



extern int ProTKSscanf (		
			     const char* input, const char* format, ...
			     );
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             sscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        input - The input string to be parsed by the function.
        format - The format string used for parsing.

    Output Arguments:
        ... - The parsed contents of the input string.

    Return Values:
        Value - The number of characters parsed by the function.

*/


extern int ProTKSwscanf (		
			      const wchar_t* input, const wchar_t* format, ...
			      );
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             swscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        input - The input string to be parsed by the function.
        format - The format string used for parsing.

    Output Arguments:
        ... - The parsed contents of the input string.

    Return Values:
        Value - The number of characters parsed by the function.

*/



extern int ProTKVscanf (const char* format, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        format - The format string used for parsing.

    Output Arguments:
        args - The parsed contents of the input from stdin.

    Return Values:
        Value - The number of characters parsed by the function.

*/




extern int ProTKVwscanf (const wchar_t* format, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vwscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        format - The format string used for parsing.

    Output Arguments:
        args - The parsed contents of the input from stdin.

    Return Values:
        Value - The number of characters parsed by the function.

*/





extern int ProTKVfscanf (FILE* file, const char* format, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vfscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        file - The file from which to read data.
        format - The format string used for parsing.

    Output Arguments:
        args - The parsed contents of the input from the file.

    Return Values:
        Value - The number of characters parsed by the function.

*/



extern int ProTKVfwscanf (FILE* file, const wchar_t* format, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vfwscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        file - The file from which to read data.
        format - The format string used for parsing.

    Output Arguments:
        args - The parsed contents of the input string.

    Return Values:
        Value - The number of characters parsed by the function.

*/



extern int ProTKVsscanf (const char* input, const char* format, va_list args);

/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vsscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        input - The input string to be parsed by the function.
        format - The format string used for parsing.

    Output Arguments:
        args - The parsed contents of the input string.

    Return Values:
        Value - The number of characters parsed by the function.

*/



extern int ProTKVswscanf (const wchar_t* input, const wchar_t* format, va_list args);
/*
    Purpose: Provides a UNICODE-supported equivalent to the C run time function 
             vswscanf().  This function supports all format specifiers and 
             modifiers as are supported by the C-language specification.  The 
             output data which are of string or character format will be in the 
             UNICODE encoding.
             

    Input Arguments:
        input - The input string to be parsed by the function.
        format - The format string used for parsing.

    Output Arguments:
        args - The parsed contents of the input string.

    Return Values:
        Value - The number of characters parsed by the function.

*/


PRO_END_C_DECLS

#endif
