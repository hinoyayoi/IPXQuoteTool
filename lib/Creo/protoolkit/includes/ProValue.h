#ifndef PROVALUEH
#define PROVALUEH

#include <ProToolkit.h>
#include <ProWchar.h>
#include <ProSelection.h>




PRO_BEGIN_C_DECLS

typedef enum pro_value_data_type
{
  PRO_VALUE_TYPE_INT           = 1,
  PRO_VALUE_TYPE_DOUBLE,
  PRO_VALUE_TYPE_POINTER,
  PRO_VALUE_TYPE_STRING,
  PRO_VALUE_TYPE_WSTRING,
  PRO_VALUE_TYPE_SELECTION,
  PRO_VALUE_TYPE_TRANSFORM,
  PRO_VALUE_TYPE_BOOLEAN
} ProValueDataType;

typedef struct pro_value_data
{
  ProValueDataType   type;
  union
  {
    int            i;   /* integer */
    double         d;   /* double  */
    void          *p;   /* pointer or reference */
    char          *s;   /* string  */
    wchar_t       *w;   /* wide string */
    ProSelection   r;   /* selection */
    double       **t;   /* transform a matrix of 4x4 */
    ProBoolean     b;	/* boolean */
  } v;
} ProValueData;
 

LIB_COREUTILS_API  ProError ProValuedataStringSet( ProValueData* value, char* string );
/*
   Purpose: Stores a string in a ProValueData.

   Input Arguments:
      value                - the ProValueData to store in.
      string               - the string to store.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The storage succeeded.
      PRO_TK_GENERAL_ERROR - The storage failed.
*/

LIB_COREUTILS_API  ProError ProValuedataWstringSet( ProValueData* value,
					wchar_t* wstring );
/*
   Purpose: Stores a widestring in a ProValueData.

   Input Arguments:
      value                - the ProValueData to store in.
      wstring              - the widestring to store.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The storage succeeded.
      PRO_TK_GENERAL_ERROR - The storage failed.
*/

LIB_COREUTILS_API  ProError ProValuedataTransformSet( ProValueData* value,
					  ProMatrix transform );
/*
   Purpose: Stores a transform in a ProValueData.

   Input Arguments:
      value                - the ProValueData to store in.
      transform            - the transform to store.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The storage succeeded.
      PRO_TK_GENERAL_ERROR - The storage failed.
*/

LIB_COREUTILS_API  ProError ProValuedataTransformGet( ProValueData* value,
					  ProMatrix transform );
/*
   Purpose: Extracts a transform from a ProValueData.

   Input Arguments:
      value                - the ProValueData to extract from

   Output Arguments:
      transform            - the ProMatrix to extract into.

   Return Values:
      PRO_TK_NO_ERROR      - The extraction succeeded.
      PRO_TK_BAD_INPUTS    - The ProValueData did not contain a transform
      PRO_TK_GENERAL_ERROR - The storage failed.
*/

/*
MECHANISM FOR SETTING THE VALUE OF ProArgument ARRAYS:
  ProArgument* args;
  ProArrayAlloc( #, sizeof(ProArgument), #, (ProArray*)&args );
	(use SizeSet if expansion necessary)

	this is example for string; wstring & transform parallel
  ProValuedataStringSet( &(args[#].value), char* );
OR
  ProArgument arg;
  ProArgument* args;
  ProArrayAlloc( 0, sizeof(ProArgument), 1, (ProArray*)&args );
  ProValuedataStringSet( &arg, char* );
  ProArrayObjectAdd( &args, 1, 0, &arg );
*/

typedef struct Pro_Value *ProValue;

/*----------------------- functions ---------------------------*/

extern ProError ProValueAlloc( ProValue *p_value ); 
/*
   DEPRECATED: Since Wildfire 2.0
   SUCCESSORS: CONTEXTUAL
   Purpose: <P><B>Note: </B>From release Wildfire 2.0 this function is superseded by
			the functions:
			<UL>
				<LI>ProElementValuetypeGet()
				<LI>ProElementReferenceSet()
				<LI>ProElementIntegerSet()
				<LI>ProElementDoubleSet()
				<LI>ProElementStringSet()
				<LI>ProElementWstringSet()
				<LI>ProElementBooleanSet()
				<LI>ProElementTransformSet()
				<LI>ProElementSpecialvalueSet()
				<LI>ProElementCollectionSet()
			</UL>							  
			PTC recommends using the new functions in place of this function in all 
			new or updated user applications.
					
			<P>Allocates the memory for the <i>ProValue</i>.

   Input Arguments:
      None

   Output Arguments:
      p_value         - The address of the <i>ProValue</i> object

   Return Values:
      PRO_TK_NO_ERROR - The function successfully allocated a <i>ProValue</i> object.
*/

extern ProError ProValueFree( ProValue value );
/*
   DEPRECATED: Since Wildfire 2.0
   SUCCESSORS: CONTEXTUAL
   Purpose:  <P><B>Note: </B>From release Wildfire 2.0 this function is superseded by
			the functions:
			<UL>
				<LI>ProElementValuetypeGet()
				<LI>ProElementReferenceGet()
				<LI>ProElementIntegerGet()
				<LI>ProElementDoubleGet()
				<LI>ProElementStringGet()
				<LI>ProElementWstringGet()
				<LI>ProElementBooleanGet()
				<LI>ProElementTransformGet()
				<LI>ProElementSpecialvalueGet()
				<LI>ProElementCollectionGet()
			</UL>							  
			PTC recommends using the new functions in place of this function in all 
			new or updated user applications.
					
			<P>Frees memory allocated by <b>ProValueAlloc()</b>.
             This function should not be used to free the value of a  
             PRO_E_SKETCHER element.

   Input Arguments:
      value - The handle to a <i>ProValue</i>(allocated by <b>ProValueAlloc()</b>)

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the memory. 
      PRO_TK_BAD_INPUTS - The argument is invalid. 

   See Also:
      ProValueAlloc()
*/



extern ProError ProValueDataGet( ProValue       value,
                                 ProValueData  *value_data );
/*
  DEPRECATED: Since Wildfire 2.0
  SUCCESSORS: CONTEXTUAL
  Purpose:  <P><B>Note: </B>From release Wildfire 2.0 this function is superseded by
			the functions:
			<UL>
				<LI>ProElementValuetypeGet()
				<LI>ProElementReferenceGet()
				<LI>ProElementIntegerGet()
				<LI>ProElementDoubleGet()
				<LI>ProElementStringGet()
				<LI>ProElementWstringGet()
				<LI>ProElementBooleanGet()
				<LI>ProElementTransformGet()
				<LI>ProElementSpecialvalueGet()
				<LI>ProElementCollectionGet()
			</UL>							  
			PTC recommends using the new functions in place of this function in all 
			new or updated user applications.
					
			<P>Retrieves the data of the value, and fills the 
                user-visible <i>ProValueData</i> structure.

  Input Arguments:
     value                - The value object

  Output Arguments:
     value_data           - The data in the value

  Return Values:
     PRO_TK_NO_ERROR      - The function successfully filled in the data
                            for the value.
     PRO_TK_BAD_INPUTS    - The input argument is invalid. 
*/

extern ProError ProValueDataSet( ProValue       value,
                                 ProValueData  *value_data );
/*
  DEPRECATED: Since Wildfire 2.0
  SUCCESSORS: CONTEXTUAL
  Purpose:  <P><B>Note: </B>From release Wildfire 2.0 this function is superseded by
			the functions:
			<UL>
				<LI>ProElementValuetypeGet()
				<LI>ProElementReferenceSet()
				<LI>ProElementIntegerSet()
				<LI>ProElementDoubleSet()
				<LI>ProElementStringSet()
				<LI>ProElementWstringSet()
				<LI>ProElementBooleanSet()
				<LI>ProElementTransformSet()
				<LI>ProElementSpecialvalueSet()
				<LI>ProElementCollectionSet()
			</UL>							  
			PTC recommends using the new functions in place of this function in all 
			new or updated user applications.
					
			<P>Sets the data of the value from the <i>ProValueData</i> supplied.

  Input Arguments:
    value                - The value object
    value_data           - The data to be assigned

  Output Arguments:
    None

  Return Values:
    PRO_TK_NO_ERROR      - The function successfully set the data.
    PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
*/



extern ProError ProWstringArrayToValueArray( ProLine   *wstring_array,
                                             int        n_lines,
                                             ProValue **p_value_array );
/*
   Purpose:   Converts an array of strings to an array of <i>ProValues</i>.

   Input Arguments:
      wstring_array     -  The input array of strings.
      n_lines           -  The number of lines.

   Output Arguments:
      p_value_array     -  The array of <i>ProValues</i>. The function allocates
                           the memory for this argument. Use the function
                           <b>ProArrayFree()</b> to free the memory.

   Return Values:
      PRO_TK_NO_ERROR   -   The function successfully converted the array of
                            strings to an array of values.
      PRO_TK_BAD_INPUTS -   One or more of the input arguments are invalid.

   See Also:
      ProArrayFree()
*/


extern ProError ProValueArrayToWstringArray( ProValue  *value_array,
                                             int        n_values,
                                             wchar_t ***p_wstring_array );
/*
   Purpose:     Extracts the data from an array of <i>ProValues</i> that contains
                wide-character strings into an array of wide-character
                strings. 

   Input Arguments:
      value_array       -  An array of values.
      n_values          -  The number of values in the array.

   Output Arguments:
      p_wstring_array   -  An array of wide-character strings. The function
                           allocates the memory for this array. Use the
                           function <b>ProArrayFree()</b> to free the memory.

   Return Values:
      PRO_TK_NO_ERROR   -   The function successfully converted the array of
                            <i>ProValues</i> to an array of strings.
      PRO_TK_BAD_INPUTS -   One or more of the input arguments are invalid.

   See Also:
      ProArrayFree()
*/



PRO_END_C_DECLS

#endif /* PROVALUEH */
