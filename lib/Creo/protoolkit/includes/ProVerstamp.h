#ifndef PROVERSTAMP_H
#define PROVERSTAMP_H

/* Creo Parametric TOOLKIT declarations for ProAsmcomp objects */

#include <ProObjects.h>



PRO_BEGIN_C_DECLS

typedef  struct Pro_Verstamp *ProWVerstamp;

/*===========================================================================*/
extern ProError ProVerstampAlloc  (ProWVerstamp *p_stamp);
/*
   Purpose:  Allocates space for the <i>ProVerstamp</i> structure.

   Input Arguments:
      None

   Output Arguments:
      p_stamp           - The allocated stamp

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully allocated the memory.
      PRO_TK_BAD_INPUTS - There was bad input. 
*/


extern ProBoolean ProVerstampEqual (ProWVerstamp   stamp1,
                                    ProWVerstamp   stamp2);
/*
   Purpose:  Compares two version stamps. 

   Input Arguments:
      stamp1		- The first version stamp
      stamp2            - The second version stamp

   Output Arguments:
      None

   Return Values:
      PRO_B_TRUE  - The two stamps are equal. 
      PRO_B_FALSE - The two stamps are not equal.
*/


extern ProError ProVerstampStringGet (ProWVerstamp   stamp, 
                                      char         **string);
/*
   Purpose:  Retrieves an ASCII string that corresponds to the version
             stamp (for permanent storage).

   Input Arguments:
      stamp               - The version stamp.

   Output Arguments:
      string              - The string representation. The function allocates the
                            memory for this argument. Use the function
                            <b>ProVerstampStringFree()</b> to free this memory.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the 
                          information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProVerstampStringFree()
*/


extern ProError ProStringVerstampGet (char          *string, 
                                      ProWVerstamp  *p_stamp);
/*
   Purpose: Retrieves the version stamp, given the corresponding ASCII
            string.
<p>
            This function is the opposite of <b>ProVerstampStringGet()</b>. 

   Input Arguments:
      string               - The version string

   Output Arguments:
      p_stamp              - The string representation

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProVerstampStringGet()
*/

extern ProError ProVerstampFree (ProWVerstamp *p_stamp);
/*
   Purpose: Frees the input version stamp.

   Input Arguments:
      p_stamp           - The version string
 
   Output Arguments:
      None	
	
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the memory.
      PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProVerstampStringFree  (char **string);
/*
   Purpose:  Frees the space allocated by a previous call to the
             <b>ProVerstampStringGet()</b> function.

   Input Arguments:
      string            - The version string

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the space.
      PRO_TK_BAD_INPUTS - The argument is invalid.

   See Also:
      ProVerstampStringGet()
*/




PRO_END_C_DECLS
#endif /* PROVERSTAMP_H */
