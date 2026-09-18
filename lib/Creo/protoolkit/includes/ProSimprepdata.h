#ifndef PROSREPDATA_H
#define PROSREPDATA_H

/* Creo Parametric TOOLKIT declarations for ProSimprep related actions */

#include <ProObjects.h>



PRO_BEGIN_C_DECLS

/*
   Types of actions that can be applied to assembly components by a
   simplified representation
*/
typedef enum pro_simprep_actions
{
    PRO_SIMPREP_NONE,        /* No action is specified. */
    PRO_SIMPREP_REVERSE,     /* Reverse the default rule for this component
                                (for example, include it if the default rule
                                is exclude). */
    PRO_SIMPREP_INCLUDE,     /* Include this component in the simplified rep. */
    PRO_SIMPREP_EXCLUDE,     /* Exclude this component from the simplified 
                                rep. */
    PRO_SIMPREP_SUBSTITUTE,   /* Substitute the component in the simplified 
                                rep. */
    PRO_SIMPREP_GEOM,         /* Use Geom Only rep of the component */
    PRO_SIMPREP_GRAPHICS,     /* Use Graphics only rep */
    PRO_SIMPREP_SYMB,         /* Use Symbolic only rep */
    PRO_SIMPREP_BOUNDBOX,     /* Use Boundary Box rep */ /* obsolete */
    PRO_SIMPREP_DEFENV,       /* Use Default Envelope rep */
    PRO_SIMPREP_LIGHT_GRAPH,  /* Use Light Graphics rep */
    PRO_SIMPREP_ASSEM_ONLY    /* Reserved for internal use */
} ProSimprepActionType;


/*
   Types of substitutions that can used in the simplified representation
*/
typedef enum pro_simprep_subst_types
{
    PRO_SUBST_NONE,          /* No substitution is defined. */
    PRO_SUBST_INTERCHG,      /* Substitute using an interchange assembly or
                                a family table. */
    PRO_SUBST_PRT_REP,       /* Substitute a part with a simplified rep. */
    PRO_SUBST_ASM_REP,       /* Substitute an assembly with a simplified rep. */
    PRO_SUBST_ENVELOPE       /* Substitute with an envelope. */
} ProSubstType;

/*
   ProSimprepitemPath - Used to specify a simplified representation item.
*/
typedef struct pro_sr_item_path
{
    int        path_size;    /* Use PRO_VALUE_UNUSED to specify a feature, or
                                use the size of the comp_path array to specify
                                a component. */
    ProIdTable comp_path;    /* Not used for features. */
    int        feat_id;      /* Set to PRO_VALUE_UNUSED if you specify 
                                path_size. */
} ProSimprepitemPath;

/*
   ProSubstitution - Specifies the substitution type and substitute data. 
*/
typedef struct pro_substitution
{
    ProSubstType         type;        /* type of substitution */
    int                  path_size;   /* PRO_VALUE_UNUSED to specify
                                         substitute by a simplified rep. */
    ProIdTable           subst_path;  /* path to the substitute component */
    ProSimprep           simp_rep;    /* simplified rep. handle 
                                         (PRO_SUBST_PRT_REP or
                                         PRO_SUBST_ASM_REP */
} ProSubstitution;

/*
   ProSimprepAction - Specifies the action (exclude, include, substitute, etc.) 
                      to apply to the simplified representation items.
*/
typedef struct pro_simprep_act
{
    ProSimprepActionType type;        /* type of the action
                                         (such as PRO_SIMPREP_INCLUDE) */
    ProSubstitution      subst_data;  /* if type == PRO_SIMPREP_SUBSTITUTE */
} ProSimprepAction;


/*
   ProSimprepitem    - Defines the status of the component or feature in
                       a simplified representation.
*/  
typedef struct pro_sr_item_status
{
    ProSimprepitemPath  item_path;   /* Specifies the item to which to apply 
                                        the action. */
    ProSimprepAction    action;      /* The action to be applied. */
} ProSimprepitem;


/*
   ProSimprepdata - Specifies the internal data required to define a 
                    simplified representation.
*/
typedef struct pro_simprepdata
{
    ProName               name;   /* name of the simplified rep. */
    ProBoolean            temp;   /* PRO_B_TRUE if the rep is temporary */
    ProSimprepActionType  deflt;  /* default action to be applied to the
                                     components (PRO_SIMPREP_INCLUDE or
                                     PRO_SIMPREP_EXCLUDE ) */
    ProSimprepitem        *items; /* an array of actions to apply to the
                                     components or features in this simplified
                                     rep */
} ProSimprepdata;

/*===========================================================================*/

extern ProError ProSimprepActionInit (ProSimprepActionType action_type,
                                      ProSubstitution     *p_subst_data,
                                      ProSimprepAction    *p_action);
/*
   Purpose:  Fills the <i>ProSimprepAction</i> data structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      action_type       - The type of action
      p_subst_data      - The substitution data (if the <i>action_type</i> is 
                          PRO_SIMPREP_SUBSTITUTE)

   Output Arguments:
      p_action          - The filled action structure

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully filled the data structure.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProSimprepdataAlloc (ProName                name, 
                                     ProBoolean             temp,
                                     ProSimprepActionType   deflt,
                                     ProSimprepdata       **p_result);
/*
   Purpose:  Allocates a <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      name		- The name of the simplified representation.
      temp              - Set this to PRO_B_TRUE if the representation is
                          temporary. Otherwise, set this to PRO_B_FALSE. 
      deflt		- The default action to be applied to the items
                          (PRO_SIMP_INCLUDE or PRO_SIMPREP_EXCLUDE).

   Output Arguments:
      p_result          - The pointer to the allocated structure. To free
                          the memory, call <b>ProSimprepdataFree()</b>.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully allocated the structure.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

   See Also:
      ProSimprepdataFree()
*/

extern ProError ProSimprepdataDefltGet (ProSimprepdata       *p_data,
                                        ProSimprepActionType *p_action);
/*
   Purpose: Retrieves the default action from the <i>ProSimprepdata</i> 
            structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data            - The pointer to the <i>ProSimprepdata</i> structure

   Output Arguments:
      p_action          - The pointer to the default action type
                          (PRO_SIMPREP_INCLUDE or PRO_SIMPREP_EXCLUDE)

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProSimprepdataDefltSet  (ProSimprepdata      *p_data,
                                          ProSimprepActionType action);
/*
   Purpose: Sets the default action in the <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data            - The pointer to the <i>ProSimprepdata</i> structure
      action            - The default action type (PRO_SIMPREP_INCLUDE
                          or PRO_SIMPREP_EXCLUDE)

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully set the default action.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProSimprepdataNameGet  (ProSimprepdata *p_data, 
                                        ProName         name);
/*
   Purpose:  Retrieves the name from the <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data 		- The pointer to the <i>ProSimprepdata</i> structure

   Output Arguments:
      name              - The name of the simplified representation 
                          extracted from the <i>p_data</i>

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the name.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

*/


extern ProError ProSimprepdataNameSet  (ProSimprepdata *p_data,
                                        ProName         name);
/*
   Purpose: Sets the name of the simplified representation in the 
            <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments: 
      p_data	- The pointer to the <i>ProSimprepdata</i> structure
      name	- The name of the simplified representation

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully set the name.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.

*/

extern ProError ProSimprepdataTmpvalGet (ProSimprepdata *p_data,
                                         ProBoolean     *p_temp);
/*
   Purpose:  Retrieves the value of the <i>temp</i> field from the specified 
             <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data            - The pointer to the <i>ProSimprepdata</i> structure

   Output Arguments:
      p_temp 		- The pointer to the retrieved <i>temp</i> value

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the value.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProSimprepdataTmpvalSet (ProSimprepdata *p_data,
                                         ProBoolean      temp);
/*
   Purpose: Sets the value of the <i>temp</i> field in the specified 
            <i>ProSimprepdata</i> structure. 

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>             
             The temporary simplified representation value can be set 
             only for newly created representations. For existing 
             representations it is controlled by Creo.
<p>

   Input Arguments:
      p_data            - The pointer to the <i>ProSimprepdata</i> structure
      temp              - A Boolean value that indicates whether it is a 
                          temporary simplified representation (PRO_B_TRUE
                          if it is temporary)
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully set the value.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProSimprepdataitemAdd   (ProSimprepdata  *p_data,
                                         ProSimprepitem  *p_item);
/*
   Purpose: Adds a simplified representation data item to the specified 
            <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data		- The pointer to the <i>ProSimprepdata</i> structure
      p_item		- The item to add to the structure

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully added the information to 
                          the structure.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProSimprepdataitemDelete (ProSimprepdata  *p_data,
                                          ProSimprepitem  *p_item);
/*
   Purpose: Deletes the specified item from the <i>ProSimprepdata</i> 
            structure.

<p><b>
             NOTE:
<p></b>
             If an item is deleted from ProSimprepdata, its last status in the 
			 simplified representation will remain  unchanged after calling 
			 ProSimprepdataSet. This should not be confused with deleting the 
			 item from the simplified representation, which can be achieved by
			 setting the item action to PRO_SIMPREP_NONE.

<p>

   Input Arguments:
      p_data	- The pointer to the <i>ProSimprepdata</i> structure
      p_item	- The item to delete

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully deleted the item from 
                             the structure.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The function did not find the specified item in 
                             the structure.
*/

extern ProError ProSimprepdataitemInit (ProIdTable         compidtab,
                                        int                table_num, 
                                        int                feat_id, 
                                        ProSimprepAction  *p_action,
                                        ProSimprepitem    *p_item);
/*
   Purpose: Initializes the specified item in the <i>ProSimprepitem</i> 
            structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      compidtab 	- The component path (for assembly simplified
                          representations)
      table_num		- Size of the component path (for assembly simplified 
                          representations)
      feat_id 		- Not supported in this release. For part simplified
                          representations only. The feature identifier,
                          if <i>table_num</i> is PRO_VALUE_UNUSED
      p_action		- The action structure

   Output Arguments:
      p_item            - The filled structure

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully initialized the 
                             structure. 
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/

extern ProError ProSimprepdataitemsVisit  (ProSimprepdata *p_data, 
                                           ProFunction     filter,
                                           ProFunction     action,
                                           ProAppData      app_data);
/*
   Purpose: Visits the items in the <i>ProSimprepdata</i> 
            structure and executes the user-supplied action function.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data	- The handle to the <i>ProSimprepdata</i> structure.
      filter	- The filter function. If NULL, all items are 
                  visited using the action function.
      action	- The visiting function. If it returns anything other
                  than PRO_TK_NO_ERROR, visiting stops.
      app_data	- The application data passed to the filter 
                  and visiting functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function visited all the items.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      Other                - Any other value is the value returned by the 
                             action function (visiting stopped). 
*/

extern ProError ProSimprepdataFree   (ProSimprepdata   **p_data);

/*
   Purpose: Frees the memory occupied by the <i>ProSimprepdata</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      p_data		- The <i>ProSimprepdata</i> structure to be released

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully freed the memory.
      PRO_TK_BAD_INPUTS - The argument is invalid.
*/

extern ProError ProSubstitutionInit  (ProSubstType      type,
                                      int               path_size, 
                                      ProIdTable        subst_path,
                                      ProSimprep       *p_simp_rep,
                                      ProSubstitution  *p_subst);
/*
   Purpose: Initializes a <i>ProSubstitution</i> structure.

<p><b>
             NOTE:
<p></b>
             Operates on assemblies only, not parts.
<p>

   Input Arguments:
      type		- The type of substitution.
      path_size		- Set this to PRO_VALUE_UNUSED to specify
                          substitution with a simplified representation.
      subst_path	- The path to the substitution component.
      p_simp_rep	- The handle to the simplified representation
                          (used with PRO_SUBST_PRT_REP or 
                          PRO_SUBST_ASM_REP).

   Output Arguments:
      p_subst		- The initialized substitution data.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the structure.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/



PRO_END_C_DECLS
#endif /* PROSREPDATA_H */
