#ifndef PROARRAY_H
#define PROARRAY_H

/* 
   Creo Parametric TOOLKIT declarations for ProArray related actions.
*/



#include <ProToolkit.h>

typedef void* ProArray;

PRO_BEGIN_C_DECLS

LIB_COREUTILS_API  ProError ProArrayAlloc (int n_objs,
                               int obj_size,
                               int reallocation_size,
                               ProArray* p_array);
/*
   Purpose:   Allocates an array of objects. The maximum memory allocated
              is approximately 2 Mb, except for alpha_unix (or other 64-bit
              platforms), where the maximum is twice that.

              Refer to ProArrayMaxCountGet for data on getting the maximum
              number of objects of obj_size that can be stored in a
              specified ProArray.

   Input Arguments:

      n_objs            - The initial number of objects allocated in the
      			  array.

      obj_size          - The size of each object in the array

      reallocation_size - The minimum number of objects added or deleted if
      			  Creo Parametric TOOLKIT resizes the array, e.g. on a call to
			  <b>ProArrayObjectAdd</b>.

   Output Arguments:

      p_array           - The allocated array

  
   Return Values:

      PRO_TK_NO_ERROR   - The function successfully allocated the array.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_OUT_OF_MEMORY - The array would be too big to allocate.
*/

LIB_COREUTILS_API  ProError ProArrayFree (ProArray* p_array);
/*
   Purpose:   Frees a preallocated array.

   Input Arguments:
      p_array   - The address of the array to be freed

   Output Arguments:
      None

   Return Values:
 
      PRO_TK_NO_ERROR   - The function successfully freed the array.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

LIB_COREUTILS_API  ProError ProArraySizeSet (ProArray* p_array,
                                 int       size);
/*
   Purpose:   Enables you to increase or decrease the size of an array.
<p>
              NOTE: 
<p>
              Because this call may cause the array to be reallocated,
              you must pass the address of the array.

   Input Arguments:
 
      p_array   - The address of the array whose size should be changed

      size      - The new size of the array

   Output Arguments:
      
      None

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully set the array size.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

LIB_COREUTILS_API  ProError ProArraySizeGet (ProArray array,
                                 int*     p_size);
/*
   Purpose:   Returns the size of the specified array.

   Input Arguments:
 
      array     - The array whose size is required
 
   Output Arguments:

      p_size    - The size of the array

   Return Values:
 
      PRO_TK_NO_ERROR   - The function successfully returned the array size.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

LIB_COREUTILS_API  ProError ProArrayObjectAdd (ProArray* p_array,
                                   int       index,
                                   int       n_objects,
                                   void*     p_object);
/*
   Purpose:   Adds an object at a specified location to the array,
              or appends an object to the end of an array.
<p>
              For example, if you want to insert one integer in an 
              integer array, call the function as follows: 
<pre>
                 ProArrayObjectAdd (&int_array, 0, 1, (void *)&int_val);
</pre>
<p>
              If you want to insert 3 doubles at the second position in 
              an array of doubles, call the function as follows: 
<pre>              
                 ProArrayObjectAdd (&dbl_array, 2, 3, (void *)dbl3_arr);
</pre>
<p>
              NOTE:
<p>
              Because this call may cause the array to be reallocated, 
              you must pass the address of the array.


   Input Arguments:

      p_array   - The address of the array.

      index     - The position at which to insert the objects in the array.
                  If you specify a value less than 0 (PRO_VALUE_UNUSED),
                  the function appends the objects to the end of the array.

      n_objects - The number of objects to add to the array.

      p_object  - The address from which a contiguous set of object data
                  is to be copied into the array.

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully added the objects 
                          to the array.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
      PRO_TK_OUT_OF_MEMORY - The array would be too big to allocate.
*/

LIB_COREUTILS_API  ProError ProArrayObjectRemove (ProArray *p_array,
                                      int       index,
                                      int       n_objects);
/*
   Purpose:   Removes an object from a specified location in the array.
<p>
              NOTE: 
<p>
              Because this call may cause the array to be reallocated,
              you must pass the address of the array.


   Input Arguments:

      p_array   - The address of the array.

      index     - The position at which to remove the objects from the array.
                  The index value can range from 0 to (<i>size of array</i>-1).
                  If the index is less than 0 (PRO_VALUE_UNUSED), the 
                  array shrinks by <i>n_objects</i>.

      n_objects - The number of objects to remove.

   Output Arguments:

      None

   Return Values:
 
      PRO_TK_NO_ERROR   - The function successfully removed the objects.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

LIB_COREUTILS_API  ProError ProArrayMaxCountGet(int obj_size,
                                    int *max_num_objs);
/*
    Purpose:    Calculates the maximum number of objects that can be
                stored in a ProArray with objects of size obj_size.

                Refer to ProArrayAlloc for data on specifying the ProArray.

    Input Arguments:

      obj_size     - The size of the object.

    Output Arguments:

      max_num_objs - The maximum number of objects of size obj_size
                     that can be stored in a ProArray.

    Return Values:

       PRO_TK_NO_ERROR - The function successfully calculated the 
                         maximum number of objects.
*/

PRO_END_C_DECLS

#endif /* PROARRAY_H */
