#ifndef PROCOLLECT_H
#define PROCOLLECT_H

#include <ProSelection.h>

PRO_BEGIN_C_DECLS




typedef enum pro_coll_type
{
  PRO_COLLECTION_LEGACY = 1,
  PRO_COLLECTION_SRFCOLL,
  PRO_COLLECTION_CRVCOLL
} ProCollectionType;

typedef void* ProCollectionGetOptions;

extern ProError ProCollectionTypeGet (ProCollection      collection,
                                      ProCollectionType *type);
/*
    Purpose:    Get the type of a ProCollection.

    Input Arguments:
        collection             - The collection object.
    
    Output Arguments:
        type                   - The type of the collection.

    Return Values:
        PRO_TK_NO_ERROR        - The function succeded.
        PRO_TK_BAD_INPUTS      - One or more arguments is invalid.
        PRO_TK_BAD_CONTEXT     - The type of collection has not been
                                 established.
*/

extern ProError ProCollectionFree(ProCollection     *p_coll);
/*
    Purpose:    Frees a ProCollection object.

    Input Arguments:
        p_coll                 - pointer to the collection

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
*/

typedef enum pro_coll_instr_type
{
 PRO_SURFCOLL_SINGLE_SURF      = 1,
 PRO_SURFCOLL_SEED_N_BND       = 2,
 PRO_SURFCOLL_QUILT_SRFS       = 3,
 PRO_SURFCOLL_ALL_SOLID_SRFS   = 4,
 PRO_SURFCOLL_NEIGHBOR         = 5,
 PRO_SURFCOLL_NEIGHBOR_INC     = 6,
 PRO_SURFCOLL_ALL_QUILT_SRFS   = 7,  /* Not supported for use in the surface collection UI, 
                                        or in feature element trees. */
 PRO_SURFCOLL_ALL_MODEL_SRFS   = 8,  /* Not supported for use in the surface collection UI, 
                                        or in feature element trees. */
 PRO_SURFCOLL_LOGOBJ_SRFS      = 9,
 PRO_SURFCOLL_DTM_PLN          = 10, /* Not supported for use in the surface collection UI, 
                                        or in feature element trees. */
 
   /* surface collection behaviors */
   PRO_SURFCOLL_DISALLOW_QLT       = 11,
   PRO_SURFCOLL_DISALLOW_SLD       = 12,
   PRO_SURFCOLL_DONT_MIX           = 13,
   PRO_SURFCOLL_SAME_SRF_LST       = 14,
   PRO_SURFCOLL_USE_BACKUP         = 15,
   PRO_SURFCOLL_DONT_BACKUP        = 16,
   PRO_SURFCOLL_DISALLOW_LOBJ      = 17,
   PRO_SURFCOLL_ALLOW_DTM_PLN      = 18,
   PRO_SURFCOLL_SEED_N_BND_INC_BND = 19,
   PRO_SURFCOLL_QUERY              = 20,
   PRO_SURFCOLL_ALLOW_QUERY        = 21, 
   
   PRO_SURFCOLL_GEOM_RULE          = 23,
   PRO_SURFCOLL_TANG_SRF           = 24,
   PRO_SURFCOLL_SHAPE_BASED        = 25,

 PRO_CURVCOLL_ONE_BY_ONE       = 101,
 PRO_CURVCOLL_TAN_CHAIN        = 102,
 PRO_CURVCOLL_CURVE_CHAIN      = 103,
 PRO_CURVCOLL_BNDRY_CHAIN      = 104,
 PRO_CURVCOLL_SURF_CHAIN       = 105,
 PRO_CURVCOLL_LOG_EDGE         = 106,
 PRO_CURVCOLL_ALL_EDGES        = 107,
 PRO_CURVCOLL_CONVEX_EDGES     = 108,
 PRO_CURVCOLL_CONCAVE_EDGES    = 109
} ProCollectioninstrType;

typedef enum pro_coll_ref_type
{
 PRO_SURFCOLL_REF_SINGLE        = 1,
 PRO_SURFCOLL_REF_SINGLE_EDGE   = 2,
 PRO_SURFCOLL_REF_SEED          = 3,
 PRO_SURFCOLL_REF_BND           = 4,
 PRO_SURFCOLL_REF_SEED_EDGE     = 5,
 PRO_SURFCOLL_REF_NEIGHBOR      = 6,
 PRO_SURFCOLL_REF_NEIGHBOR_EDGE = 7,
 PRO_SURFCOLL_REF_GENERIC       = 8,

 PRO_CURVCOLL_REF_EDGE          = 101,
 PRO_CURVCOLL_REF_ALL           = 102,
 PRO_CURVCOLL_REF_FROM_TO       = 103,
 PRO_CURVCOLL_REF_FROM_TO_FLIP  = 104,
 PRO_CURVCOLL_REF_FROM          = 105,
 PRO_CURVCOLL_REF_TO            = 106
} ProCollectionrefType;
 
typedef enum pro_coll_instr_attr
{
 PRO_REF_INCLUDE       = 1,
 PRO_REF_EXCLUDE       = 2
} ProCollectioninstrAttr;

typedef enum pro_chain_coll_ui_control
{
    PRO_CHAINCOLLUI_ONE_BY_ONE                  = 101,
    PRO_CHAINCOLLUI_TAN_CHAIN                   = 102,
    PRO_CHAINCOLLUI_CURVE_CHAIN                 = 103,
    PRO_CHAINCOLLUI_BNDRY_CHAIN                 = 104,
    PRO_CHAINCOLLUI_SURF_CHAIN                  = 105,
    PRO_CHAINCOLLUI_LOG_EDGE                    = 106,
    PRO_CHAINCOLLUI_FROM_TO                     = 110,
    PRO_CHAINCOLLUI_ALLOW_LENGTH_ADJUSTMENT     = 111,
    PRO_CHAINCOLLUI_ALLOW_ALL                   = 112,
    PRO_CHAINCOLLUI_ALLOW_EXCLUDED              = 113,
    PRO_CHAINCOLLUI_ALLOW_APPENDED              = 114
} ProChaincollUIControl;

/*** Opaque handles ***/

typedef struct pro_coll_instr_ref *ProCollectionref;  /* Collection reference */

typedef struct pro_coll_instr *ProCollectioninstr;  /* Collection instruction */


extern ProError ProCollectionAlloc(ProCollection    *r_coll);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProCrvcollectionAlloc, ProSrfcollectionAlloc
    Purpose:    <B>Note:</B> This function accesses a legacy version of the ProCollection
                 interface. It has been superseded by the functions:
				 <UL>
					<LI>ProCrvcollectionAlloc()
					<LI>ProSrfcollectionAlloc()
				</UL>
		 Please consult the Creo Parametric TOOLKIT user's guide chapter on "Collections" 
                 for more information.
				 <P>Allocates a ProCollection object
    
    Input Arguments:
        none
    
    Output Arguments:
        r_coll                 - pointer to new collection

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_OUT_OF_MEMORY
*/

extern ProError ProCollectioninstrAlloc(ProCollectioninstrType  instr_type,
                                        ProCollectioninstrAttr  attr,
                                        ProCollectioninstr      *r_instr);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				  Allocates a ProCollectioninstr object
    <P>

    Input Arguments:
        instr_type              - the instruction type
        attr                    - the instruction attribute
    
    Output Arguments:
        r_instr                 - pointer to new instruction

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_OUT_OF_MEMORY
*/

extern ProError ProCollectioninstrFree(ProCollectioninstr *p_instr);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Frees a ProCollectioninstr object.
  
    Input Arguments:
        p_instr                 - pointer to the instruction

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
*/

extern ProError ProCollectioninstrTypeGet(ProCollectioninstr instruction,
                                          ProCollectioninstrType *r_type);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 
				 <P>To get the type of a collection instruction

    Input Arguments:
        instruction     - The collection instruction

    Output Arguments:
        r_type          - The type of the collection instruction

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS

*/

extern ProError ProCollectioninstrTypeSet(ProCollectioninstr instruction,
                                           ProCollectioninstrType type);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:   <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 To get the type of a collection instruction
 
    Input Arguments:
        instruction     - The collection instruction
        type            - The type of the collection instruction

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS

*/

extern ProError ProCollectionrefAlloc(ProCollectionrefType type,
                                      ProSelection         selection,
                                      ProCollectionref     *r_ref);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				  Allocate a new ProCollectionRef object

    Input Arguments:
        type            - Type of the reference
        selection       - Selection identifying the target of the reference

    Output Arguments:
        r_ref           - Pointer to the new collection reference object

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
        PRO_TK_OUT_OF_MEMORY

*/

extern ProError ProCollectionrefFree(ProCollectionref     *p_ref);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				  Free a collection reference object

    Input Arguments:
        p_ref           - Pointer to the collection reference object

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
*/

extern ProError ProCollectioninstrRefAdd(ProCollectioninstr    instruction,
                                         ProCollectionref      reference);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:  <B>Note:</B> This function accesses an older version of the ProCollection
               interface. It has been superseded. Please consult the 
               Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
               information.
			<P>
				Adds a new reference to a collection instruction

    Input Arguments:
        instruction             - the instruction object to contain the new reference
        reference               - the ProCollectionref object to be added to the
                                  instruction
                                  
    Output Arguments:
        none
        
    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
        PRO_TK_OUT_OF_MEMORY
*/

extern ProError ProCollectioninstrRefRemove(ProCollectioninstr instruction,
                                            ProCollectionref   reference);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:   <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 
				  <P>To remove the specified reference from the specified
                collection instruction

    Input Arguments:
        instruction             - The collection instruction object
        reference               - The collection reference object.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS       - The instruction and/or reference was invalid.
        PRO_TK_BAD_CONTEXT      - The reference was not found in the instruction

*/

extern ProError ProCollectionrefTypeGet (ProCollectionref     reference,
                                         ProCollectionrefType *r_type);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:  <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 
			  <P>Get the type of a specified collection reference

    Input Arguments:
        reference       - The collection reference object

    Output Arguments:
        r_type          - The reference type

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS

*/

extern ProError ProCollectionrefTypeSet(ProCollectionref     reference,
                                        ProCollectionrefType type);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 
				<P>Sets the type of a specified collection reference

    Input Arguments:
        reference               - The collection reference object
        type                    - The reference type

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS

*/

extern ProError ProCollectionrefSelectionGet(ProCollectionref    reference,
                                             ProSelection        *r_selection);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				  Gets the selection of a specified collection reference object.

    Input Arguments:
        reference               - The collection reference object

    Output Arguments:
        r_selection             - The selection structure for the reference

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS

*/

extern ProError ProCollectionrefSelectionSet(ProCollectionref    reference,
                                             ProSelection        selection);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:   <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				   Sets the selection of a specified collection reference object.

    Input Arguments:
        reference               - The collection reference object
        selection               - The selection structure for the reference

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS

*/

typedef ProError (*ProCollectionrefAction)(ProCollectionref   ref,
                                           ProError           status,
                                           ProAppData         app_data);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:   <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Type for action callback function for ProCollectioninstrRefVisit()

    Input Arguments:
        ref                     - The reference object for which the function
                                  is called.
        status                  - The return value from the preceding call to
                                  the filter function.
        app_data                - The user-defined data passed to
                                  ProCollectioninstrRefVisit).

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - continue visiting
        PRO_TK_CONTINUE         - continue visiting
        other                   - terminate visiting and return this value from
                                  ProCollectioninstrRefVisit()
*/

typedef ProError (*ProCollectionrefFilter)(ProCollectionref  ref,
                                           ProAppData        app_data);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				  Type for filter callback function for ProCollectioninstrRefVisit().

    Input Arguments:
        ref                     - The reference object for which the function
                                  is called.
        app_data                - The user-defined data passed to
                                  ProCollectioninstrRefVisit().
        
    Output Arguments:
        None
        

    Return Values:
        PRO_TK_CONTINUE         - Skip the call to the action function for this
                                  reference, but continue visiting.
        Other                   - Call the action function and pass this value
                                  as the input status argument.

*/

extern ProError ProCollectioninstrRefVisit(ProCollectioninstr       instruction,
                                           ProCollectionrefAction   action,
                                           ProCollectionrefFilter   filter,
                                           ProAppData               app_data);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				  To visit all the references in a ProCollectioninstr object.

    Input Arguments:
        instruction             - The collection instruction object
        action                  - The action function to be called for each
                                  reference
        filter                  - The filter function to be called for each
                                  reference. If NULL, visits all references
                                  using the action function.
        app_data                - A pointer to any data to be passed down to
                                  the filter and action functions.
        

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - Finished visiting all the references.
	PRO_TK_BAD_INPUTS       - Invalid arguments, or no references found.
        Other                   - The value returned from the last call to
                                  the action function.

*/

extern ProError ProCollectionInstrAdd(ProCollection      collection,
                                      ProCollectioninstr instruction);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Add an instruction to a collection.

    Input Arguments:
        collection              - The collection
        instruction             - The instruction

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
        PRO_TK_OBSOLETE_FUNC    - A newer type of ProCollection was passed.

*/
extern ProError ProCollectionInstrRemove(ProCollection      collection,
                                         ProCollectioninstr instruction);

/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:    <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Remove an instruction from a collection

    Input Arguments:
        collection              - The collection
        instruction             - The instruction

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_BAD_INPUTS
        PRO_TK_OBSOLETE_FUNC    - A newer type of ProCollection was passed.
*/

typedef ProError (*ProCollectioninstrFilter)(ProCollectioninstr instruction,
                                             ProAppData         app_data);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:  <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Type for filter callback function for ProCollectionInstrVisit().

    Input Arguments:
        instruction             - The instruction for which the function is
                                  called.
        app_data                - The user-defined data passed to
                                  ProCollectionInstrVisit().
        
    Output Arguments:
        None

    Return Values:
        PRO_TK_CONTINUE         - Skip the call to the action function for 
                                  this reference, but continue visiting.
        Other                   - Call the action function and pass this value
                                  as the input status argument.

*/

typedef ProError (*ProCollectioninstrAction)(ProCollectioninstr instruction,
                                             ProError           filt_status,
                                             ProAppData         app_data);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:   <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Type for action callback function for ProCollectionInstrVisit().

    Input Arguments:
        instruction             - The instruction for which the function is
                                  called.
        filt_status             - The status from the previous call to the 
                                  filter function.
        app_data                - The user-defined data passed to
                                  ProCollectionInstrVisit().

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - continue visiting
        PRO_TK_CONTINUE         - continue visiting
        other                   - terminate visiting and return this value
                                  from ProCollectionInstrVisit().

*/

extern ProError ProCollectionInstrVisit(ProCollection             collection,
                                        ProCollectioninstrFilter  filter,
                                        ProCollectioninstrAction  action,
                                        ProAppData                app_data);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:  <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				 Visit the instructions in a collection

    Input Arguments:
        collection              - The collection
        filter                  - Filter function for instructions. If NULL, 
                                  visits all instructions using the action 
                                  function.
        action                  - Action function to be called for each 
                                  instruction.
        app_data                - Pointer to data to be passed to filter 
                                  and action functions.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR         - Finished visiting all the instructions.
        PRO_TK_BAD_INPUTS       - Invalid arguments, or the collection 
	                          contained no items.
        PRO_TK_OBSOLETE_FUNC    - A newer type of ProCollection was passed.
        Other                   - The value returned from the last call to
                                  the action function.

*/
extern ProError ProCrvcollectionInstrRegen(ProCollectioninstr      instruction,
                                        ProSelection            **r_sel_list,
                                        int                     *n_sel);
/*
    DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: CONTEXTUAL
    Purpose:   <B>Note:</B> This function accesses an older version of the ProCollection
                 interface. It has been superseded. Please consult the 
                 Creo Parametric TOOLKIT user's guide chapter on "Collections" for more
                 information.
				 <P>
				   To regenerate a collection instruction and provide a list of the
                resulting surfaces, curves and edges.

    Input Arguments:
        instruction             - The collection instruction object

    Output Arguments:
        r_sel_list              - Pointer to a ProArray (allocated by the 
                                  function) of ProSelection objects describing
                                  the surfaces, curves and edges resulting
                                  from the collection.
        n_sel                   - Number of entries in sel_list.
        errors                  - Pointer to a ProArray, allocated by the 
                                  function, of errors, each identify an error 
                                  error type and a collection reference which
                                  cause the error.

    Return Values:
        PRO_TK_NO_ERROR
        PRO_TK_GENERAL_ERROR    - The regeneration failed.

*/

typedef ProError (*ProCollFilter) (ProSelection **sels,
                                   ProSelection   cur_sel,
                                   ProAppData   app_data);
/*
   Purpose:  Post filter function for surface collection

   Input Arguments:
        sels     - Previously selected items.
        cur_sel  - Current selection. Filter function determines
                    whether cur_sel is accepted.
        app_data - Application data

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR      - Accept current selection.
        PRO_TK_GENERAL_ERROR - Reject current selection.
        
*/


typedef ProError (*ProCrvcollFilter) (ProSelection   cur_sel,
                                      ProAppData   app_data);
/*
   Purpose:  Post filter function for chain collection

   Input Arguments:
        cur_sel  - Current selection. Filter function determines
                    whether cur_sel is accepted.
        app_data - Application data

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR      - Accept current selection.
        some other value     - Reject current selection.
        
*/

extern ProError ProCurvesCollect(ProChaincollUIControl *types,
                                 int                    n_types,
                                 ProCrvcollFilter          filter_func, 
                                 ProAppData             app_data,
                                 ProCollection          *collection,
                                 ProSelection           **sel_list,
                                 int                    *n_sel);
/*
    Purpose:    Asks the user to interactively create a collection of chains

   Input Arguments:
      types       - Array allocated by the Creo Parametric TOOLKIT application defining
                    which portion of the user interface that the Creo Parametric
                    user will be allowed to use while in the dialog.

                    Following instruction types are supported:
<UL>
<LI> PRO_CHAINCOLLUI_ONE_BY_ONE
<LI> PRO_CHAINCOLLUI_TAN_CHAIN
<LI> PRO_CHAINCOLLUI_CURVE_CHAIN
<LI> PRO_CHAINCOLLUI_BNDRY_CHAIN
<LI> PRO_CHAINCOLLUI_SURF_CHAIN
<LI> PRO_CHAINCOLLUI_LOG_EDGE
<LI> PRO_CHAINCOLLUI_FROM_TO
<LI> PRO_CHAINCOLLUI_ALLOW_LENGTH_ADJUSTMENT
<LI> PRO_CHAINCOLLUI_ALLOW_ALL
<LI> PRO_CHAINCOLLUI_ALLOW_EXCLUDED
<LI> PRO_CHAINCOLLUI_ALLOW_APPENDED

        n_types     - The number of instruction types in the array.
        filter_func - The filter function called just after each selection of
                      a curve or edge Pass NULL to skip this filter.
        app_data    - Application data passed to the filter function.  Can be
                      NULL.
        collection  - The resulting collection object.  This pointer must be
                      allocated by calling ProCrvcollectionAlloc().  If the
                      input collection contains instructions already, they
                      will be appended into the details shown by the dialog.

    Output Arguments:
        sel_list    - Pointer to a ProArray (allocated by the function) of
                      ProSelection objects describing the curves and edges
                      resulting from the collection.  Free this array using
                      ProSelectionarrayFree().  Pass NULL if not interested
                      in this information at this time.
                      <P>
                      <B>NOTE</B>: If using a collection that
                      permits "extended" and "trimmed" chains, the selection
                      list might not be 100% accurate (because there will be
                      no selection representing the extended and trimmed
                      item(s)). 
        n_sel       - Number of entries in sel_list, if sel_list is not NULL.

   Return Values:
       PRO_TK_NO_ERROR  - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more arguments is invalid.
       PRO_TK_USER_ABORT - The user aborted the collection activity.
       PRO_TK_BAD_CONTEXT - The input ProCollection contains instructions that
                            cannot be resolved into a single chain.
    See Also:
        ProCrvcollectionAlloc()

*/

extern ProError ProSurfacesCollect(ProCollectioninstrType *types,
                                   int                    n_types,
                                   ProCollFilter          filter_func,
                                   ProAppData             app_data,
                                   ProCollection          collection,
                                   ProSelection           **sel_list,
                                   int                    *n_sel);
/*
    Purpose:    Asks the user to interactively create a collection of surfaces.

    Input Arguments:
        types                   - Array defining the instruction types 
                                  the Creo Parametric user will be allowed to use.
        n_types                 - The size of the types array
        filter_func             - Filter function called before each 
                                  selection is made. Can be NULL.
        app_data                - Application data passed to the filter 
                                  function.  Can be NULL.
        collection              - The resulting collection object, this pointer
                                  is allocated by calling ProCollectionAlloc
                                  and NULL can also be passed.
                                  <B>Note:</B>If this collection already contains selected items,
                                  the dialog will display those contents to be edited
                                  interactively in the dialog. The ProCollection will point to
                                  the modified contents once the dialog OK button is chosen.
 
    Output Arguments:
        sel_list                - Pointer to a ProArray (allocated by the
                                  function) of ProSelection objects describing
                                  the surfaces resulting from the collection.
                                  Free this using ProSelectionarrayFree().
        n_sel                   - Number of entries in sel_list.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed.
*/

PRO_END_C_DECLS

#endif /* PROCOLLECT_H */
