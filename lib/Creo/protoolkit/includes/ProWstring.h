
#include <ProToolkit.h>
#include <ProArray.h>
#include <ProWchar.h>




#ifndef PROWSTRING_H
#define PROWSTRING_H

PRO_BEGIN_C_DECLS

extern  ProError  ProWstringLengthGet (wchar_t* wstr, int* length);
/*
  Purpose: 
		Returns the length of a widestring.

  Input Arguments: 
		wstr - The wide string.

  Output Arguments:
        length - The length of the string, in wide characters.
 
  Return Values:
        PRO_TK_NO_ERROR - The information was returned successfully.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern  ProError  ProWstringCompare (wchar_t* wstr_1, wchar_t* wstr_2, int num_chars, int* result);
/*
   Purpose: 
		Compares two wide strings for equality.

  Input Arguments: 
       wstr_1 - The first wide string.
       wstr_2 - The second wide string.
       num_chars - The number of characters to compare.  Pass 
                    PRO_VALUE_UNUSED to compare the entire strings.

  Output Arguments:
       result - The comparison result (as per "strcmp()")
 
  Return Values:
       PRO_TK_NO_ERROR - The information was returned successfully.
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern  ProError  ProWstringCopy (wchar_t* source, wchar_t* target, int num_chars);
/*
   Purpose: 
         Copies a wide string into another buffer.

   Input Arguments: 
         source - The source wide string.
         target - The target wide string.  It is the caller's responsibility to
                 allocate enough memory for the copy operation.
         num_chars -  The number of wide strings to copy.  If PRO_VALUE_UNUSED,
                     the entire string will be copied.

   Output Arguments:
        none
 
   Return Values:
       PRO_TK_NO_ERROR - The information was returned successfully.
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern  ProError  ProWstringConcatenate (wchar_t* source, wchar_t* target, int num_chars);
/*
  Purpose: 
       Concatenates two wide strings.

  Input Arguments: 
       source - The source wide string.
       target - The target wide string. It is the caller's responsibility to 
		      allocate enough memory for the copy operation.
       num_chars -  The number of wide strings to concatenate.  If 
		             PRO_VALUE_UNUSED, the entire string will be added 
			     to the target string.

  Output Arguments:
       none
 
  Return Values:
       PRO_TK_NO_ERROR - The information was returned successfully.
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


/* The following functions are not widely used.  */

typedef wchar_t*    ProWstring;

/*
   The functions for ProWstring are derived from ProArray, and
   the following functions can be used from ProArray (the rest are overwritten):

   ProArrayAlloc
   ProArraySizeGet

*/

extern ProError ProWstringArrayFree ( ProWstring** p_array );
/*
   Purpose:   Frees the preallocated array.
 
   Input Arguments:
      p_array - The address of the array to be freed, previously allocated by
                <b>ProArrayAlloc()</b>

   Output Arguments:
      None

   Return Values:
      PRO_TK_BAD_INPUTS - Either <i>p_array</i> is NULL, or you specified an 
                          invalid <i>ProArray</i>.
      PRO_TK_NO_ERROR   - The function successfully freed the memory.

   See Also:
      ProArrayAlloc()
*/

extern ProError ProWstringArraySizeSet ( ProWstring** p_array, int size );
/*
   Purpose:   Enables you to increase or decrease the size of an array.
<p>
              NOTE: 
<p>
              Because this call may cause the array to be reallocated,
              you must pass the address of the array.


   Input Arguments:
      p_array - The address of the array whose size should be changed
      size    - The new size for the array

   Output Arguments:
      None

   Return Values:
      PRO_TK_BAD_INPUTS  - The size of the array is less than 0.
      PRO_TK_INVALID_PTR - The <i>*p_array</i> is NULL.
      PRO_TK_NO_ERROR    - The function successfully changed the size of the array. 
*/

extern ProError ProWstringArrayObjectAdd ( ProWstring** p_array, int index,
                                       int n_objects, ProWstring* p_objects );
/*
   Purpose:   Adds and allocates memory for wide strings at a specified 
              location to the array, or appends an object to the end of the 
              array.
<p>
              NOTE:
<p>
              Because this call may cause the array to be reallocated,
              you must pass the address of the array.
   
   Input Arguments:
      p_array -   The address of the array.
      index   -   The position at which to insert wide string in the array.
                  If you specify a value less than 0 (PRO_VALUE_UNUSED),
                  the function appends the wide strings to the end of the array.
      n_objects - The number of objects to add to the array.
      p_objects  - The address from which a contiguous set of wide strings is to be
                  copied into the array.

   Output Arguments:
      None

   Return Values:
      PRO_TK_BAD_INPUTS  - The size of the array is less than 0.
      PRO_TK_INVALID_PTR - The <i>*p_array</i> is NULL.
      PRO_TK_NO_ERROR    - The function successfully added the object.  
*/

extern ProError ProWstringArrayObjectRemove ( ProWstring** p_array, int index,
                                              int n_objects );
/*
   Purpose:   Removes a wide string from a specified location in the array.

   Input Arguments:
      p_array   - The address of the array.

      index     - The position at which to remove the objects from the array.
                  The index value can range from 0 to <i>(size of array-1)</i>.
                  If the index is less than 0 (PRO_VALUE_UNUSED), the
                  array shrinks by <i>n_objects</i>.

      n_objects - The number of objects to remove.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully removed the objects.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

PRO_END_C_DECLS

#endif /* PROWSTRING_H */

