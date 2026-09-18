#ifndef PROCRVCOLLECTION_H
#define PROCRVCOLLECTION_H



#include        <ProToolkit.h>
#include        <ProCollect.h>
#include        <ProReference.h>

PRO_BEGIN_C_DECLS

/* ========================================================================= */
/* ======================= Instruction Types =============================== */
/* ========================================================================= */

typedef enum {
 PRO_CURVCOLL_EMPTY_INSTR       = 100,
 PRO_CURVCOLL_ADD_ONE_INSTR     = 101,
 /* Application - Create "One by One" chain.  */

 PRO_CURVCOLL_TAN_INSTR         = 102,
 /* Application - Create "Tangent" chain */

 PRO_CURVCOLL_CURVE_INSTR       = 103,
 /* Application - Create "Curve" chain */

 PRO_CURVCOLL_SURF_INSTR        = 104,
 /* Application - Create "Surface Loop" chain */

 PRO_CURVCOLL_BNDRY_INSTR       = 105,
 /* Application - Create "Boundary Loop"  chain */

 PRO_CURVCOLL_LOG_OBJ_INSTR     = 106,
 /* Application - Create "Logical Object" chain */

 PRO_CURVCOLL_PART_INSTR        = 107,
 /* Application - Create chain on all possible references, or choose from
    convex/concave only.  */

 PRO_CURVCOLL_FEATURE_INSTR     = 108,
 /* Application - Create chain from feature curves. */

 PRO_CURVCOLL_FROM_TO_INSTR     = 109,
 /* Application - Create "From-To" chain.  */

 PRO_CURVCOLL_EXCLUDE_ONE_INSTR = 110,
 /* Application - Exclude entity from the chain. */

 PRO_CURVCOLL_TRIM_INSTR        = 111,
 /* Application - Trim chain.  */

 PRO_CURVCOLL_EXTEND_INSTR      = 112,
 /* Application - Extend chain.  */ 

 PRO_CURVCOLL_START_PNT_INSTR   = 113,
 /* Application - Set chain start point.  */

 PRO_CURVCOLL_ADD_TANGENT_INSTR = 114,
 /* Application - Add all edges tangent to the ends of the chain.  */

 PRO_CURVCOLL_ADD_POINT_INSTR   = 115,
 /* Application - Add selected point or points to the collection.  */

 PRO_CURVCOLL_OPEN_CLOSE_LOOP_INSTR   = 116,
 /* Application - Chain has closed loop that is considered open */

 PRO_CURVCOLL_QUERY_INSTR       = 117,
 /* Application - Create "Query" chain. */

 PRO_CURVCOLL_CNTR_INSTR        = 118,
 /* Application - Collect contour. */

 PRO_CURVCOLL_RESERVED_INSTR
} ProCurvcollinstrType, ProCrvcollinstrType;

/* ========================================================================= */
/* ======================= Instruction Attributes ========================== */
/* ========================================================================= */
typedef enum {

 PRO_CURVCOLL_NO_ATTR         = 0,

 PRO_CURVCOLL_ALL             = 1,
 /* Application    -   Use all edges.
    Applicable for -   PRO_CURVCOLL_TAN_INSTR & PRO_CURVCOLL_PART_INSTR */

 PRO_CURVCOLL_CONVEX          = 2,
 /* Application    -   Use convex edges.
    Applicable for -   PRO_CURVCOLL_TAN_INSTR & PRO_CURVCOLL_PART_INSTR */

 PRO_CURVCOLL_CONCAVE         = 3,
 /* Application    -   Use concave edges.
    Applicable for -   PRO_CURVCOLL_TAN_INSTR & PRO_CURVCOLL_PART_INSTR
 */

 PRO_CURVCOLL_RESERVED_ATTR = 16 

} ProCurvcollinstrAttr, ProCrvcollinstrAttr;

/* ========================================================================= */
/* ======================= Curve Collection Instruction ==================== */
/* ========================================================================= */

typedef void* ProCrvcollinstr;

/* ========================================================================= */
/* ======================= Curve Collection Instruction API ================ */
/* ========================================================================= */
extern ProError ProCrvcollinstrAlloc( ProCrvcollinstrType type,
                                      ProCrvcollinstr*    r_instr );
/*
   Purpose: Allocates a curve collection instruction

   Input Arguments:
       type -               The instruction type.

   Output Arguments:
       r_instr -            Pointer to curve collection instruction

   Return Values:
       PRO_TK_NO_ERROR      - The function succeeded.
       PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
       PRO_TK_OUT_OF_MEMORY - Memory allocation failure.     
*/

extern ProError ProCrvcollinstrFree ( ProCrvcollinstr instr );
/*
   Purpose: Releases curve collection instruction

   Input Arguments:
       instr -            The curve collection instruction
  
   Output Arguments:
        none

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded.     
       PRO_TK_BAD_INPUTS  - The argument was invalid. 
*/

extern ProError ProCrvcollinstrArrayFree ( ProCrvcollinstr* instrs );
/*
   Purpose: Releases a ProArray of curve collection instructions

   Input Arguments:
       instrs -            The curve collection instruction array
  
   Output Arguments:
        none

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded.     
       PRO_TK_BAD_INPUTS  - The argument was invalid. 
*/

extern ProError ProCrvcollinstrTypeGet (ProCrvcollinstr    instr,
                                        ProCrvcollinstrType* type);
/*
   Purpose: Gets the curve collection instruction type

   Input Arguments:
       instr -             Curve collection instruction
       
   Output Arguments:
       type -               The instruction type.

   Return Values:
       PRO_TK_NO_ERROR   - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProCrvcollinstrReferenceAdd( ProCrvcollinstr instr,
                                             ProReference    reference );
/*
   Purpose: Adds a reference to curve collection instruction references

   Input Arguments:
       instr -             Curve collection instruction
       reference -         The object reference

   Output Arguments:
        none

   Return Values:
       PRO_TK_NO_ERROR     - The function succeeded.   
       PRO_TK_BAD_INPUTS   - One or more arguments was invalid. 
       PRO_TK_INVALID_ITEM - Invalid item for this type of instruction.      
*/


extern ProError ProCrvcollinstrReferenceRemove( ProCrvcollinstr instr,
                                                int     index );
/*
   Purpose: Removes a reference to curve collection instruction references

   Input Arguments:
       instr -             Curve collection instruction
       index -             The index of the selection to remove

   Output Arguments:
        none

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded.   
       PRO_TK_BAD_INPUTS  - One or more arguments was invalid. 
       PRO_TK_E_NOT_FOUND - Invalid index for the instruction.

   See Also:    ProCrvcollinstrReferencesGet()
*/

extern ProError ProCrvcollinstrReferencesGet( ProCrvcollinstr instr,
                                       ProReference**    reference_array );
/*
   Purpose: Returns the references contained in a curve collection instruction

   Input Arguments:
       instr -             Curve collection instruction
       
   Output Arguments:
       reference_array -   ProArray of references.  
                           Free this array using ProReferencearrayFree().


   Return Values:
       PRO_TK_NO_ERROR     - The function succeeded.   
       PRO_TK_BAD_INPUTS   - One or more arguments was invalid. 
       PRO_TK_INVALID_ITEM - Invalid item for this type of instruction.      
*/

extern ProError ProCrvcollinstrAttributeSet( ProCrvcollinstr instr,
                                             ProCrvcollinstrAttr attr );
/*
   Purpose: Adds an attribute to a curve collection instruction

   Input Arguments:
       instr -              Curve collection instruction
       attr -               Attribute to add

  Output Arguments:
       none

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded.   
       PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
       PRO_TK_BAD_CONTEXT - The attribute cannot be set for the given
                            instruction type.
       PRO_TK_E_AMBIGUOUS - Invalid combination of attributes.
*/

extern ProError ProCrvcollinstrAttributeUnset( ProCrvcollinstr instr,
                                               ProCrvcollinstrAttr attr );
/*
   Purpose: Removes an attribute to a curve collection instruction

   Input Arguments:
       instr -              Curve collection instruction
       attr -               Attribute to remove

  Output Arguments:
       none

   Return Values:
       PRO_TK_NO_ERROR   - The function succeeded.   
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProCrvcollinstrAttributeIsSet ( ProCrvcollinstr instr, 
                                                ProCrvcollinstrAttr attr,
                                                ProBoolean*         r_is_set );
/*
   Purpose: Checks that attribute of curve collection instruction is set

   Input Arguments:
       instr -               Curve collection instruction
       attr -                Attribute to check

   Output Arguments:
       r_is_set -           PRO_B_TRUE if attribute is set, 
                            PRO_B_FALSE if attribute is not set

   Return Values:
       PRO_TK_NO_ERROR   - The function succeeded.   
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProCrvcollinstrValueSet( ProCrvcollinstr instr, 
                                         double           value );
/*
   Purpose: Sets curve collection instruction value

   Input Arguments:
       instr -             Curve collection instruction
       value -             Value

   Output Arguments:
       none

   Return Values:
       PRO_TK_NO_ERROR   - The function succeeded.   
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/
extern ProError ProCrvcollinstrValueGet( ProCrvcollinstr instr, 
                                         double*         value );
/*
   Purpose: Gets curve collection instruction value

   Input Arguments:
       instr -             Curve collection instruction

   Output Arguments:
       value -             Value

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded.   
       PRO_TK_BAD_INPUTS  - One or more arguments was invalid.
*/

/* ========================================================================= */
/* ======================= Curve Collection API ============================ */
/* ========================================================================= */

extern ProError ProCrvcollectionAlloc( ProCollection* r_collection );
/*
   Purpose: Allocates a curve collection 
 
   Input Arguments:
       none

   Output Arguments:
       r_collection -       Pointer to curve collection

   Return Values:
       PRO_TK_NO_ERROR      - The function succeeded.
       PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
       PRO_TK_OUT_OF_MEMORY - Memory allocation failure. 

   See Also:   
       ProCollectionFree()
*/

extern ProError ProCrvcollectionCopy( ProCollection  source,
                                      ProCollection* target);
/*
   Purpose: Copies a curve collection.

   Input Arguments:
       source -             Curve collection 
			    If the type is PRO_COLLECTION_LEGACY, the input 
			    legacy curve collection will be copied into a 
			    standard style curve collection of type 
			    PRO_COLLECTION_CRVCOLL.  
			    If the type is PRO_COLLECTION_CRVCOLL, 
			    the output will be an identical copy of the input.

   Output Arguments:
       target -             The copy of the curve collection. 
                            This will be a newly allocated collection that
                            should be freed by ProCollectionFree().

   Return Values:
       PRO_TK_NO_ERROR      - The function succeeded.
       PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
       PRO_TK_OUT_OF_MEMORY - Memory allocation failure.  
       PRO_TK_INVALID_TYPE  - The collection contains instructions for surfaces.

   See Also:   
       ProCollectionFree()   
*/

extern ProError ProCrvcollectionInstructionAdd( ProCollection collection,
                                                ProCrvcollinstr  instr );
/*
   Purpose: Adds instruction to curve collection

   Input Arguments:
       collection -         Curve collection
       instr -              Instruction to add

   Output Arguments:
           none

   Return Values:
       PRO_TK_NO_ERROR     - The function succeeded.
       PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
       PRO_TK_INVALID_TYPE - The collection contains instructions for surfaces.
*/

extern ProError ProCrvcollectionInstructionRemove ( ProCollection collection,
                                                    int index );
/*
   Purpose: Removes instruction from curve collection

   Input Arguments:
       collection -         Curve collection
       index -              Index of the instruction to remove.

   Output Arguments:
           none

   Return Values:
       PRO_TK_NO_ERROR     - The function succeeded.
       PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
       PRO_TK_E_NOT_FOUND  - Invalid index for the instruction.
       PRO_TK_INVALID_TYPE - The collection contains instructions for surfaces.
*/

extern ProError ProCrvcollectionInstructionsGet ( ProCollection collection,
                                           ProCrvcollinstr** instrs_array );
/*
   Purpose: Gets instructions from curve collection

   Input Arguments:
       collection -         Curve collection
       
   Output Arguments:
       instrs_array -  ProArray of instructions. 
                       Free this array using ProCrvcollinstrArrayFree().

   Return Values:
       PRO_TK_NO_ERROR     - The function succeeded.
       PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
       PRO_TK_E_NOT_FOUND  - Invalid index for the instruction.
       PRO_TK_INVALID_TYPE - The collection contains instructions for surfaces.
*/

extern ProError ProCrvcollectionRegenerate (ProCollection    collection,
                            ProSelection        **r_result_sellist,
                            int                 *r_result_sel_num);
/*
   Purpose:  Generate the selection based on the instructions set in the curve
             collection. <p><b>Note: </b>This function will not be able to 
extract geometry, if some or all of the resulting geometry is inactive due to 
material removal features occuring in the model. In order to extract the 
reference geometry for such a collection, use ProFeatureInsertModeActivate() to 
roll back the model before the material removal feature.

   Input Arguments:
        collection - The curve collection.

   Output Arguments:
        r_result_sellist - ProArray of selections allocated by the function. Use
                          <B>ProSelectionarrayFree()</B> to free the memory. 
       <b>Note</b>: For curve collections containing one or more "Extend"
                    instructions, the ProArray returned will include at least
                    one invalid selection.  This selection represents the 
                    entity  that is created by extension of a selected curve or
                    edge beyond its actual boundary. The invalid selection 
                    can be identified by ProSelectionVerify(), which returns
                    PRO_TK_INVALID_TYPE for this type of selection.
        r_result_sel_num - Number of selections made.

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully generated the
                               collection.
        PRO_TK_OUT_OF_MEMORY - There was a memory error.
        PRO_TK_BAD_INPUTS    - The input argument is invalid.
        PRO_TK_GENERAL_ERROR - There was a general error.
        PRO_TK_E_AMBIGUOUS   - The curve collection chain cannot be 
                               regenerated
                               because there is an ambiguity which could not
                               be resolved.
        PRO_TK_E_NOT_FOUND   - The curve collection chain cannot be regenerated
                               because a reference could not be found while
                               collecting edges/curves/points.
        PRO_TK_NOT_VALID     - The checking of the curve collection failed.   

*/

PRO_END_C_DECLS

#endif /* PROCRVCOLLECTION_H */
