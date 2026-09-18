

#ifndef PRO_MESSAGE_DOTH
#define PRO_MESSAGE_DOTH

#include <ProSizeConst.h>

PRO_BEGIN_C_DECLS

extern ProError ProMessageDisplay(
#ifdef PRO_USE_VAR_ARGS
				  ProFileName file_name, 
				  ProCharLine message_name,
				  ...
#endif
);

/*
 Purpose: Prints a text message to the Creo Parametric message area, then 
          scrolls previous messages to make room for the new message.
  	  The function looks for the message name in the specified message
	  file, which provides a mapping between the message name and the
	  actual text of the message to be displayed.

     <p> This function takes 0 to 10 additional arguments to be
	  substituted for conversion specifiers in the text of the message,
          similar to <i>printf()</i>.

<ul>
     <li>Default Values
     <p>  Specify default values in the call to ProMessageDisplay(), using the
          separator ||| in the format string in the message file. (See the 
          Creo Parametric TOOLKIT User's Guide section Contents of the Message File for 
          the specific placement of the ||| separator.)

     <li>Message Classifications

     <p>  Messages displayed in Creo Parametric include a symbol which identifies
          the message type. Each message type is identified by a 
          classification which begins with the characters %C. A message 
          classification requires that the message key (line 1 in the message
          file) be proceeded by the classification code. 

      <p><b>Note:</b>The message key string used in the code should NOT contain
                     the classification. 

        <p>Creo Parametric TOOLKIT applications can now display any or all of these message
           symbols:

<ul>
    <li>
          Prompt--the Creo Parametric message displayed is preceded by a green  
          arrow. The user must respond to this message type (to either input 
          information, accept the default value offered, or cancel the 
          application). Without such action, no progress can be made. The 
          response may be either textual or in the form of a selection. The 
          classification code for Prompt messages is %CP.
    <li>
          Info--the Creo Parametric message displayed is preceded by a blue dot. 
          This message type contains information such as user requests or 
          feedback from either Creo Parametric or the Creo Parametric TOOLKIT application.
          The classification code for Info messages is %CI.
   <p>      
   <b>Note:</b> Do not classify as Info any message which informs users of a 
                problem with an operation or process. Classify these messages 
                as Warnings.
   <li>
          Warning--the Creo Parametric message displayed is preceded by a tri-
          angle containing an exclamation point. Warnings alert the user to 
          situations which may lead to potentially erroneous situations at a 
          later stage, for example, possible process restrictions imposed or a
          suspected data problem. However, warnings do not prevent or 
          interrupt task completion, nor should they be used to indicate a 
          failed operation. Warnings only caution the user that the operation 
          has been completed, but may not have been performed in a completely 
          desirable way. The classification code for Warning messages is %CW.
     <li>
          Error--the Creo Parametric message displayed is preceded by a broken 
          square. This message type informs the user when a required task was
          not successfully completed. It may or may not require intervention or
          correction before work can continue, depending on the application. 
          Whenever possible, provide a workaround. The classification code 
          for Error messages is %CE.
     <li>
          Critical--the Creo Parametric message displayed is preceded by a red X. 
          This message type informs the user of extremely serious situations, 
          especially those which could cause the loss of user data. Options 
          for redressing the situation (if available) should be provided with 
          the message. The classification code for Critical messages is %CC.
</ul>

</ul>

  Input Arguments:
     file_name		- The name of the file that contains the message
     message_name	- The name of the message in the file
     ...                - The subsequent arguments for the values inserted
                          into the format string are pointers, not values. 
                          These values can be data inserted into the message
                          or default values for the data to be read from user
                          input. Although the list of arguments for the values
                          is variable in number, there is a maximum of 10.

  Output Arguments:

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully printed the message.
     PRO_TK_E_NOT_FOUND   - The specified message file was not found.
     PRO_TK_CANT_OPEN	  - The system could not read the message file.
     PRO_TK_MSG_NOT_FOUND - The specified message was not found in the 
                            message file.
     PRO_TK_MSG_NO_TRANS  - The message text (in the current language of
     			    the user interface) was not found.
     PRO_TK_MSG_FMT_ERROR - There was a format error in the message text.
     PRO_TK_MSG_TOO_LONG  - The message was longer than (PRO_LINE_SIZE - 1)
     			    characters and has been truncated to fit.
     PRO_TK_E_FOUND       - The message file had been read in before this call
			    and the message was not in it.
     PRO_TK_GENERAL_ERROR - The message was not printed.
*/


extern ProError ProMessageWstringbufferAlloc(
#ifdef PRO_USE_VAR_ARGS
                                        wchar_t**  translated_msg,  
                                        ProFileName file_name,
                                        ProCharLine message_name,
                                        ...
#endif                                        
);

/*
  Purpose: Places the translated contents of a formatted message into the
           specified output buffer. This function works just like
	   <b>ProMessageDisplay()</b>, except the message is written to a 
	   wstring instead of the message area.
<p>
	   This function takes 0 to 10 additional arguments to be
	   substituted for conversion specifiers in the text of the message,
	   similar to <i>printf()</i>.
<p>
           NOTE:
<p>           
           This is an exception to the Creo Parametric TOOLKIT standard of putting
           output arguments after input arguments, due to the variable 
           number of input arguments.
           

  Input Arguments:
     file_name		- The name of the file that contains the message
     message_name	- The name of the message in the file
     ...                - 0 through 9 values of input variants. 

  Output Arguments:
     translated_msg     - The formatted and translated message, 
                          Free this string using ProWstringFree().

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully printed the message.  
     PRO_TK_MSG_NOT_FOUND - The specified message was not found in the      
                            message file.
     PRO_TK_MSG_FMT_ERROR - There was a format error in the message text.    
     PRO_TK_BAD_INPUTS    - Output parameter is NULL.
*/

extern ProError ProMessageToBuffer(
#ifdef PRO_USE_VAR_ARGS
				   ProLine translated_msg,
				   ProFileName file_name,
				   ProCharLine message_name,
				   ... 
#endif
);

/*
  Purpose: Places the translated contents of a formatted message into the
           specified output buffer. This function works just like
	   <b>ProMessageDisplay()</b>, except the message is written to a 
	   string instead of the message area.
<p>
	   This function takes 0 to 10 additional arguments to be
	   substituted for conversion specifiers in the text of the message,
	   similar to <i>printf()</i>.
<p>
           NOTE:
<p>           
           This is an exception to the Creo Parametric TOOLKIT standard of putting
           output arguments after input arguments, due to the variable 
           number of input arguments.
           

  Input Arguments:
     file_name		- The name of the file that contains the message
     message_name	- The name of the message in the file
     ...                - 0 through 9 values of input variants. 

  Output Arguments:
     translated_msg	- The formatted and translated message

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully printed the message.
     PRO_TK_E_NOT_FOUND   - The specified message file was not found.
     PRO_TK_CANT_OPEN	  - The system could not read the message file.
     PRO_TK_MSG_NOT_FOUND - The specified message was not found in the 
                            message file.
     PRO_TK_MSG_NO_TRANS  - The message text (in the current language of
     			    the user interface) was not found.
     PRO_TK_MSG_FMT_ERROR - There was a format error in the message text.
     PRO_TK_MSG_TOO_LONG  - The message was longer than (PRO_LINE_SIZE - 1)
     			    characters and has been truncated to fit.
     PRO_TK_E_FOUND       - The specified message was not found in memory and
                            the message file was read previously. This may
			    indicate that there are two different message files
			    with the same name; avoid this problem by
			    including the application name in the file name.
     PRO_TK_GENERAL_ERROR - The message was not printed.
*/

extern void ProMessageClear( void );
/*
  Purpose:  
          Scrolls the text in the message area up one line <b>after</b>
          a call to ProMessageDisplay(). This command produces only one
          carriage return; if called multiple times the command is ignored.
	
  Input Arguments:

    None

  Output Arguments:

    None

  Return Values:

    None
*/

extern ProError ProMessageIntegerRead( int range[2], int* answer );
/*
  Purpose: Reads an integer from the keyboard. If the user types an invalid
	   string, or a value outside the range of values, the function asks
	   the user to enter the value again.

           Specify default values in the call to ProMessageDisplay(), using the
           separator ||| in the format string in the message file. (See the 
           Creo Parametric TOOLKIT User's Guide section Contents of the Message File for 
           the specific placement of the ||| separator.)

		   <p><b>NOTE:</b>Call ProMessageDisplay before calling this function.

  Input Arguments:
     range		- The lower and upper bounds allowed for the input. 
     			  If this is NULL, any values are acceptable.

  Output Arguments:
     answer		- The user's input.

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully read an integer.
     PRO_TK_MSG_USER_QUIT - The user canceled input by typing &ltESC&gt.
     PRO_TK_GENERAL_ERROR - The function failed to read an integer.
*/

extern ProError ProMessageDoubleRead( double range[2], double* answer );
/*
  Purpose: Reads a double-precision, floating-point number from the keyboard.
	   If the user types an invalid string, or a value outside the range
	   of values, the function asks the user to enter the value again.

           Specify default values in the call to ProMessageDisplay(), using the
           separator ||| in the format string in the message file. (See the 
           Creo Parametric TOOLKIT User's Guide section Contents of the Message File for 
           the specific placement of the ||| separator.)

		   <p><b>NOTE:</b>Call ProMessageDisplay before calling this function.

  Input Arguments:
     range		- The lower and upper bounds allowed for the input.
     			  If this is NULL, any values are acceptable.

  Output Arguments:
     answer		- The user's input.

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully read a number.
     PRO_TK_MSG_USER_QUIT - The user canceled input by typing &ltESC&gt.
     PRO_TK_GENERAL_ERROR - The function failed to read a number.
*/

extern ProError ProMessageStringRead( int max_buffer_length,
				      wchar_t* buffer );
/*
  Purpose: Reads a line of keyboard input and returns the contents as a
	   wide string.

           Specify default values in the call to ProMessageDisplay(), using the
           separator ||| in the format string in the message file. (See the 
           Creo Parametric TOOLKIT User's Guide section Contents of the Message File for 
           the specific placement of the ||| separator.)

		   <p><b>NOTE:</b>Call ProMessageDisplay before calling this function.

  Input Arguments:
     max_buffer_length - The maximum length (up to 127 characters) of the string put into <i>buffer</i>

  Output Arguments:
     buffer            - The user's input

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully read a string.
     PRO_TK_MSG_USER_QUIT - The user canceled input by typing &ltESC&gt.
     PRO_TK_GENERAL_ERROR - The function failed to read a string. This includes
     			    the case of the user entering &ltCR&gt without 
			    typing any characters.

*/

extern ProError ProMessagePasswordRead( int max_password_length, 
					wchar_t* password );
/*
  Purpose: Reads user input in the form of character strings. The input is
	   not visible in the message area.

           Specify default values in the call to ProMessageDisplay(), using the
           separator ||| in the format string in the message file. (See the 
           Creo Parametric TOOLKIT User's Guide section Contents of the Message File for 
           the specific placement of the ||| separator.)

		   <p><b>NOTE:</b>Call ProMessageDisplay before calling this function.

  Input Arguments:
     max_password_length - The maximum length (up to 127 characters) of the string put into password

  Output Arguments:
     password            - The user's input

  Return Values:
     PRO_TK_NO_ERROR	  - The function successfully read a string.
     PRO_TK_MSG_USER_QUIT - The user canceled input by typing &ltESC&gt.
     PRO_TK_GENERAL_ERROR - The function failed to read a string. This includes
     			    the case of the user entering &ltCR&gt without 
			    typing any characters.)

*/

PRO_END_C_DECLS

#endif	/* PRO_MESSAGE_DOTH */
