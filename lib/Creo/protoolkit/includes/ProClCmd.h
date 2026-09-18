#ifndef PROCLCMD_H
#define PROCLCMD_H


#include <ProObjects.h>




typedef struct usr_cl_cmd_data
{
   Pro3dPnt   location;
   ProVector  axis;
   double     feed;
}  ProClCmdData;



PRO_BEGIN_C_DECLS

/*===========================================================================*/

typedef ProError (*ProClCommandExpandAction) (ProFeature *pro_feat,
		      wchar_t (*command)[512], int num_cmd_lines,
		      ProClCmdData **r_output_arr, int *output_num);

/*
Purpose: This is the callback to interpret the user's CL commands.
	 <p>
	 If you do not supply a callback, the system uses the CL
	 command location.

Input Arguments:
         pro_feat      - The feature.
         command       - The CL command. This is an array of lines.
         num_cmd_lines - The number of lines in the command.

Output Arguments:
         r_output_arr  - The resultant array. 
         output_num    - The number if items in the array
			 <i>r_output_arr</i>.

Return Values:

         PRO_TK_NO_ERROR      - The function was successful. 
	 PRO_TK_GENERAL_ERROR - A general error occurred and the function
				failed.
	 PRO_TK_E_NOT_FOUND   - The specified CL command was not found.

*/


/*===========================================================================*/

typedef ProBoolean (*ProClCommandGetLocAction) (ProFeature     *pro_feat, 
                                          wchar_t        (*command)[512],
                                          int            num_cmd_lines,
                                          ProPoint3d     location );

/*

  Purpose: Gets the location of the specified CL command.

  Input Arguments:

    pro_feat      - The feature
    command       - The CL command whose location to get
    num_cmd_lines - The number of lines in the CL command

  Output Arguments:

    location      - The location

  Return Values:

    PRO_B_TRUE  - The function found the specified CL command and return 
                  its location.
    PRO_B_FALSE - The function did not find the specified CL command.

*/

PRO_END_C_DECLS

#endif
