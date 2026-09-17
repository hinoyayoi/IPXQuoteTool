#ifndef PRORELSET_H
#define PRORELSET_H

#include <ProObjects.h>
#include <ProParamval.h>
#include <ProWstring.h>
#include <ProMdlUnits.h>



PRO_BEGIN_C_DECLS



typedef enum pro_relobj_types
{
 PRO_RELOBJ_UNUSED      = PRO_TYPE_UNUSED,
 PRO_RELOBJ_PART	= PRO_PART,
 PRO_RELOBJ_ASSEMBLY	= PRO_ASSEMBLY,
 PRO_RELOBJ_DRAWING	= PRO_DRAWING,
 PRO_RELOBJ_REPORT      = PRO_REPORT,
 PRO_RELOBJ_DIAGRAM     = PRO_DIAGRAM,
 PRO_RELOBJ_DWGFORM     = PRO_DWGFORM,
 PRO_RELOBJ_UDF         = PRO_UDF,
 PRO_RELOBJ_FEATURE	= PRO_FEATURE,
 PRO_RELOBJ_SURFACE	= PRO_SURFACE,
 PRO_RELOBJ_EDGE	= PRO_EDGE,

 PRO_RELOBJ_WELD_PARAMS = PRO_WELD_PARAMS,
 PRO_RELOBJ_BND_TABLE   = PRO_BND_TABLE,
 PRO_RELOBJ_EXTOBJ      = PRO_EXTOBJ,

 PRO_RELOBJ_PAT_DIR1    = PRO_PATREL_FIRST_DIR, /* rel set owner is a pattern */
                                      /* dimension in the 1st dir  */
                                      /* model_item.id ==              */
                                      /*  pat. leader's dim id     */
 PRO_RELOBJ_PAT_DIR2    = PRO_PATREL_SECOND_DIR,/* rel set owner is a pattern */
                                      /* dimension in the 2nd dir  */
                                      /* model_item.id ==          */
                                      /*  pat. leader's dim id     */
 PRO_RELOBJ_QUILT       = PRO_QUILT,
 PRO_RELOBJ_CRV         = PRO_CURVE,
 PRO_RELOBJ_COMP_CRV    = PRO_COMP_CRV,
 PRO_RELOBJ_ANNOT_ELEM  = PRO_ANNOTATION_ELEM,
 PRO_RELOBJ_MDO_CONN    = PRO_MDO_CONN,
 PRO_RELOBJ_RP_MATERIAL = PRO_RP_MATERIAL,
 PRO_RELOBJ_NC_STEP_OBJECT  = PRO_NC_STEP_OBJECT,
 PRO_RELOBJ_NC_STEP_MODEL  = PRO_NC_STEP_MODEL
}	ProRelObjType;

#define RELOBJTYPE_TO_PROTYPE( rel_obj_type, pro_type ) \
   switch( rel_obj_type )                               \
   {                                                    \
      case PRO_RELOBJ_PART:                             \
	 ( pro_type ) = PRO_PART;                       \
	 break;                                         \
      case PRO_RELOBJ_ASSEMBLY:                         \
	 ( pro_type ) = PRO_ASSEMBLY;                   \
	 break;                                         \
      case PRO_RELOBJ_DRAWING:                          \
	 ( pro_type ) = PRO_DRAWING;                    \
	 break;                                         \
      case PRO_RELOBJ_REPORT:                           \
	 ( pro_type ) = PRO_REPORT;                     \
	 break;                                         \
      case PRO_RELOBJ_DIAGRAM:                          \
	 ( pro_type ) = PRO_DIAGRAM;                    \
	 break;                                         \
      case PRO_RELOBJ_DWGFORM:                          \
	 ( pro_type ) = PRO_DWGFORM;                    \
	 break;                                         \
      case PRO_RELOBJ_UDF:                              \
	 ( pro_type ) = PRO_UDF;                        \
	 break;                                         \
      case PRO_RELOBJ_FEATURE:                          \
	 ( pro_type ) = PRO_FEATURE;                    \
	 break;                                         \
      case PRO_RELOBJ_SURFACE:                          \
	 ( pro_type ) = PRO_SURFACE;                    \
	 break;                                         \
      case PRO_RELOBJ_EDGE:                             \
	 ( pro_type ) = PRO_EDGE;                       \
	 break;                                         \
      case PRO_RELOBJ_WELD_PARAMS:                      \
	 ( pro_type ) = PRO_WELD_PARAMS;                \
	 break;                                         \
      case PRO_RELOBJ_BND_TABLE:                        \
	 ( pro_type ) = PRO_BND_TABLE;                  \
	 break;                                         \
      case PRO_RELOBJ_EXTOBJ:                           \
	 ( pro_type ) = PRO_EXTOBJ;                     \
	 break;                                         \
      case PRO_RELOBJ_PAT_DIR1:                         \
	 ( pro_type ) = PRO_PATREL_FIRST_DIR;           \
	 break;                                         \
      case PRO_RELOBJ_PAT_DIR2:                         \
	 ( pro_type ) = PRO_PATREL_SECOND_DIR;          \
	 break;                                         \
      case PRO_RELOBJ_QUILT:                            \
	 ( pro_type ) = PRO_QUILT;                      \
	 break;                                         \
      case PRO_RELOBJ_CRV:                              \
	 ( pro_type ) = PRO_CURVE;                      \
	 break;                                         \
      case PRO_RELOBJ_COMP_CRV:                         \
	 ( pro_type ) = PRO_COMP_CRV;                   \
	 break;                                         \
      case PRO_RELOBJ_ANNOT_ELEM:                       \
	 ( pro_type ) = PRO_ANNOTATION_ELEM;            \
	 break;                                         \
      case PRO_RELOBJ_MDO_CONN:                         \
	 ( pro_type ) = PRO_MDO_CONN;                   \
         break;                                         \
      case PRO_RELOBJ_RP_MATERIAL:                      \
	 ( pro_type ) = PRO_RP_MATERIAL;                \
         break;                                         \
      case PRO_RELOBJ_NC_STEP_OBJECT:                   \
	 ( pro_type ) = PRO_NC_STEP_OBJECT;             \
	 break;                                         \
      case PRO_RELOBJ_NC_STEP_MODEL:                   \
	 ( pro_type ) = PRO_NC_STEP_MODEL;             \
	 break;                                         \
      default:                                          \
	 ( pro_type ) = PRO_TYPE_UNUSED;                \
	 break;                                         \
    }

#define PROTYPE_TO_RELOBJTYPE( pro_type, rel_obj_type ) \
   switch( pro_type )                                   \
   {                                                    \
      case PRO_PART:                                    \
	 ( rel_obj_type ) = PRO_RELOBJ_PART;            \
	 break;                                         \
      case PRO_ASSEMBLY:                                \
	 ( rel_obj_type ) = PRO_RELOBJ_ASSEMBLY;        \
	 break;                                         \
      case PRO_DRAWING:                                 \
	 ( rel_obj_type ) = PRO_RELOBJ_DRAWING;         \
	 break;                                         \
      case PRO_REPORT:                                  \
	 ( rel_obj_type ) = PRO_RELOBJ_REPORT;          \
	 break;                                         \
      case PRO_DIAGRAM:                                 \
	 ( rel_obj_type ) = PRO_RELOBJ_DIAGRAM;         \
	 break;                                         \
      case PRO_DWGFORM:                                 \
	 ( rel_obj_type ) = PRO_RELOBJ_DWGFORM;         \
	 break;                                         \
      case PRO_UDF:                                     \
	 ( rel_obj_type ) = PRO_RELOBJ_UDF;             \
	 break;                                         \
      case PRO_FEATURE:                                 \
	 ( rel_obj_type ) = PRO_RELOBJ_FEATURE;         \
	 break;                                         \
      case PRO_SURFACE:                                 \
	 ( rel_obj_type ) = PRO_RELOBJ_SURFACE;         \
	 break;                                         \
      case PRO_EDGE:                                    \
	 ( rel_obj_type ) = PRO_RELOBJ_EDGE;            \
	 break;                                         \
      case PRO_WELD_PARAMS:                             \
	 ( rel_obj_type ) = PRO_RELOBJ_WELD_PARAMS;     \
	 break;                                         \
      case PRO_BND_TABLE:                               \
	 ( rel_obj_type ) = PRO_RELOBJ_BND_TABLE;       \
	 break;                                         \
      case PRO_EXTOBJ:                                  \
	 ( rel_obj_type ) = PRO_RELOBJ_EXTOBJ;          \
	 break;                                         \
      case PRO_PATREL_FIRST_DIR:                        \
	 ( rel_obj_type ) = PRO_RELOBJ_PAT_DIR1;        \
	 break;                                         \
      case PRO_PATREL_SECOND_DIR:                       \
	 ( rel_obj_type ) = PRO_RELOBJ_PAT_DIR2;        \
	 break;                                         \
      case PRO_QUILT:                                   \
	 ( rel_obj_type ) = PRO_RELOBJ_QUILT;           \
	 break;                                         \
      case PRO_CURVE:                                   \
	 ( rel_obj_type ) = PRO_RELOBJ_CRV;             \
	 break;                                         \
      case PRO_COMP_CRV:                                \
	 ( rel_obj_type ) = PRO_RELOBJ_COMP_CRV;        \
	 break;                                         \
      case PRO_ANNOTATION_ELEM:                         \
	 ( rel_obj_type ) = PRO_RELOBJ_ANNOT_ELEM;      \
	 break;                                         \
      case PRO_MDO_CONN:                                \
	 ( rel_obj_type ) = PRO_RELOBJ_MDO_CONN;        \
	 break;                                         \
      case PRO_RP_MATERIAL:                             \
	 ( rel_obj_type ) = PRO_RELOBJ_RP_MATERIAL;     \
	 break;                                         \
      case PRO_NC_STEP_OBJECT:                          \
	 ( rel_obj_type ) = PRO_RELOBJ_NC_STEP_OBJECT;  \
	 break;                                         \
      case PRO_NC_STEP_MODEL:                          \
	 ( rel_obj_type ) = PRO_RELOBJ_NC_STEP_MODEL;  \
	 break;                                         \
      default:                                          \
	 ( rel_obj_type ) = PRO_RELOBJ_UNUSED;          \
	 break;                                         \
    }

typedef struct pro_model_item  ProRelset;  /* a Creo Parametric relation set         */

#define PRO_RELSET_POST_REGEN_ID  -2   /* Id to use for the "Post-Regeneration"
                                          relations set.  Use this id
				          in the modelitem handle passed to
				          ProModelitemToRelset() */

extern ProError ProModelitemToRelset (ProModelitem    *p_item,
                                      ProRelset       *p_relset);
/*
   Purpose: Gets the relation set associated to the specified
            model item. 
<p>
            NOTE: 
<p>
            Only those model items whose
            types are specified by <i>ProRelObjType</i> are
            supported.

   Input Arguments:
       p_item           - The model item

   Output Arguments:
       p_relset	        - The associated relation set

   Return Values:
       PRO_TK_NO_ERROR	- The relation set was found and returned.
       Other            - The relation set does not exist.
*/

extern ProError ProRelsetToModelitem (ProRelset      *p_relset,
			              ProModelitem   *p_item);
/*
   Purpose: Gets the model item that owns the specified
            relation set. 
<p>
            NOTE: 
<p>
            Only those model items whose
            types are specified by <i>ProRelObjType</i> are
            supported.

   Input Arguments:
       p_relset	  - The associated relation set

   Output Arguments:
       p_item     - The model item

   Return Values:
       PRO_TK_NO_ERROR	- The owner was found and returned.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
       PRO_TK_INVALID_ITEM - The input relation set was not valid.
*/

typedef ProError (*ProSolidRelsetVisitAction) (ProRelset   	*p_relset,
					       ProAppData	 caller_data);
/* 
   Purpose: This is the user-supplied function invoked for each relation
            set owned by the model.

   Input Arguments:
       p_relset	    - The relation set
       caller_data  - The user-supplied data

  Output Arguments:                             
       None

   Return Values:
       PRO_TK_NO_ERROR	- Continue visiting.
       Other            - Stop visiting, and send this error up.
*/

extern ProError ProSolidRelsetVisit (ProMdl			model,
       			             ProSolidRelsetVisitAction action,
                                     ProAppData		caller_data);
/*
   Purpose: Visits all the relation sets owned by the specified 
            model. Currently, the supported model types are
            PRO_PART and  PRO_ASSEMBLY.

   Input Arguments:
       model            - The model that owns the relations
       action           - The supplied function to be invoked for
                          each relation set
       caller_data      - The user-supplied data
 
  Output Arguments:
       None
 
   Return Values:
       PRO_TK_NO_ERROR   - The function successfully visited all the
                           relation sets owned by the model.
       Other             - Visiting stopped due to the error returned by
                           user-supplied visiting function, or some other
                           internal error.
*/

extern ProError ProRelsetRegenerate (ProRelset   *p_relset);

/*
   Purpose: Regenerates the specified relation set.

   Input Arguments:
       p_relset		- The relation set

  Output Arguments:
       None
 
   Return Values:
       PRO_TK_NO_ERROR	- The relation set was regenerated successfully.
       Other		- An error occurred and the function failed. 
*/

extern ProError ProRelsetCreate (ProModelitem    *p_item,
                                 ProRelset       *p_relset);
/*
   Purpose: Creates a new relation set.

   Input Arguments:
       p_item           - The model item for which to create the  
                          relation set 

  Output Arguments:
       p_relset         - The relation set

   Return Values:
       PRO_TK_NO_ERROR  - The function successfully created the new relation 
                          set.
       PRO_TK_E_FOUND   - The relation set already exists.
       Other            - There was an internal error, and the function did
                          not create the relation set.
*/

extern ProError ProRelsetDelete (ProRelset   *p_relset);
/*
   Purpose: Deletes all relations in specified relation set. 

   Input Arguments:
       p_relset         - The relation set, containing relations to delete. 

  Output Arguments:
       None
 
   Return Values:
       PRO_TK_NO_ERROR    -  The function deleted all relations from the set. 
       Other              -  An error occurred and the function failed.
*/
       
extern ProError ProRelsetRelationsGet (ProRelset    *p_relset,
                                       ProWstring  **p_line_array);
/*
   Purpose: Returns the relation strings for the specified relation set.

   Input Arguments:
       p_relset         - The relation set.

  Output Arguments:
       p_line_array	- The address to a user-allocated array of 
                          <i>ProWstring</i>.
                          Use the functions <b>ProArrayAlloc()</b>
                          and <b>ProWstringproarrayFree()</b> to allocate 
                          and free this array. Do not reuse the array.

   Return Values:
       PRO_TK_NO_ERROR  - The function successfully returned the relations.
       Other            - An error occurred and the function failed. 

   See Also:
       ProArrayAlloc()
       ProArrayFree()

*/
                          
extern ProError ProRelsetRelationsSet (ProRelset     *p_relset,
                                       ProWstring    *line_array,
                                       int            n_lines);
/*
   Purpose: Sets new values for existing relations of the relation set.

   Input Arguments:
       p_relset         - The relation set
       line_array       - The relations assigned to this
                          relation set
       n_lines          - The number of lines in the relations

  Output Arguments: 
       None

   Return Values: 
       PRO_TK_NO_ERROR  - The function successfully set the new values. 
       Other            - There was an error and the function failed. 
*/

extern ProError ProRelationEval (ProRelset        *p_relset,
                                 ProLine           rhs_expr,
                                 ProParamvalue    *p_value);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProRelationEvalWithUnits
   Purpose: <b>Note:</b> This function is deprecated. Use ProRelationEvalWithUnits().
   
            Evaluates the supplied right-hand side of a typical expression
            (lhs = rhs) and returns the value in the form of
            a parameter value.

   Input Arguments:
       p_relset		- The relation set
       rhs_expr		- The right-hand side of any relation line in
                          the relation set

  Output Arguments:
       p_value		- The evaluated result in the form of a parameter
                          value

   Return Values:
       PRO_TK_NO_ERROR  - The function successfully evaluated the expression.
       PRO_TK_GENERAL_ERROR - An error occurred and the function failed. 
*/

extern ProError ProRelationEvalWithUnits( ProRelset        *p_relset,
                                          ProLine           rhs_expr,
                                          ProParamvalue    *p_value,
                                          ProUnititem      *units,
                                          ProBool           consider_units );
/*
   Purpose: Evaluates the supplied right-hand side of a typical expression
            (lhs = rhs) and returns the value in the form of
            a parameter value.

   Input Arguments:
       p_relset		   - The relation set
       rhs_expr		   - The right-hand side of any relation line in
                             the relation set
	   consider_units  - Specifies if units should be considered

  Output Arguments:
       p_value		- The evaluated result in the form of a parameter
                          value
       units        - The units of the evaluated result

   Return Values:
       PRO_TK_NO_ERROR  - The function successfully evaluated the expression.
       PRO_TK_BAD_INPUTS    - One or more inputs is invalid
       PRO_TK_GENERAL_ERROR - An error occurred and the function failed. 
*/


typedef enum rel_func_arg_attr
{
   PRO_RELF_ATTR_NONE     = 0,
   PRO_RELF_ATTR_OPTIONAL = 1<<0   /* Argument is optional */
}  ProRelfuncAttr;

typedef struct rel_func_arg
{
   ProParamvalueType   type;
   ProRelfuncAttr      attributes;
}  ProRelfuncArg;


typedef ProError (*ProRelationReadFunction) (ProRelset      *pro_relset, 
					  ProMdl          pro_model, 
					  char           *extfunc_name, 
					  ProParamvalue  *pro_args,
					  ProAppData     app_data,
					  ProParamvalue  *pro_result );
/*
  Purpose:  This is the function called to evaluate a custom relation
            function invoked on the right hand side of a relation.

  Input Arguments:
         pro_relset - The relation set.
	 pro_model  - The model that owns the relation set.
	 extfunc_name - The name of the external function.
	 pro_args - ProArray of argument values.
	 app_data - The application data passed to registration function.
	 
  Output Arguments:
         pro_result - The result of the relation function calculation.

  Return Values:
         PRO_TK_NO_ERROR - The calculation succeeded.
	 Any other error - The calculation failed; the relation has an error.

*/

	 

typedef ProError (*ProRelationWriteFunction) (ProRelset      *pro_relset, 
					      ProMdl          pro_model, 
					      char           *extfunc_name, 
					      ProParamvalue  *pro_args, 
					      ProParamvalue  *pro_input,
					      ProAppData     app_data);
/*
  Purpose:  This is the function called to evaluate a custom relation
            function invoked on the left hand side of a relation.

  Input Arguments:
         pro_relset - The relation set.
	 pro_model  - The model that owns the relation set.
	 extfunc_name - The name of the external function.
	 pro_args - ProArray of argument values.
	 pro_input - The value of the right hand side of the relation 
	             expression.
	 app_data - The application data passed to registration function.
	 
  Output Arguments:
         none

  Return Values:
         PRO_TK_NO_ERROR - The calculation succeeded.
	 Any other error - The calculation failed; the relation has an error.

*/


typedef ProError (*ProRelationArgscheckFunction) (ProRelset      *pro_relset,
					       ProMdl          pro_model,
					       char           *extfunc_name,
					       ProParamvalue  *pro_args,
					       ProAppData     app_data);
/*
  Purpose:  This is the function called to validate the arguments of a custom 
            relation function before it is invoked.

  Input Arguments:
         pro_relset - The relation set.
	 pro_model  - The model that owns the relation set.
	 extfunc_name - The name of the external function.
	 pro_args - ProArray of argument values.
	 app_data - The application data passed to registration function.
	 
  Output Arguments:
         none

  Return Values:
         PRO_TK_NO_ERROR - The arguments are valid. 
	 Any other error - The arguments are invalid;the relation has an error.

*/



extern ProError ProRelationFunctionRegister( char             *extfunc_name,
					     ProRelfuncArg     *arg_descr_arr,
					     ProRelationReadFunction read_func,
					     ProRelationWriteFunction write_func,
					     ProRelationArgscheckFunction check_func,
					     ProBoolean        dis_type_ctrl,
					     ProAppData        app_data);

/*
   Purpose:     Register an external function to be used in relations.

   Input Arguments:
      extfunc_name      - name of new relation function used in the relations.
      arg_descr_arr     - argument description ProArray. Can be NULL if:
                            <OL>
			    <LI>no arguments should be supplied to the new function.
			    <LI>you don't want Creo Parametric to check the validity of arguments (in conjunction with 'dis_type_ctrl' = PRO_B_TRUE).
			    </OL>
      read_func         - function that implements read-access of external
			  function; can be NULL;
      write_func        - function that implements write-access of external
			  function; can be NULL;
      check_func        - function to check arguments of external function;
			  can be NULL;
      dis_type_ctrl     - PRO_B_TRUE to disable type checking for arguments.
                          PRO_B_FALSE indicates that the arguments will be 
			  checked.
      app_data          - application data passed to the relation callbacks.
                          Can be NULL.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more inputs was invalid.
      PRO_TK_E_FOUND     - Function with the given name was already found.     
*/


extern ProError ProRelsetConstraintsGet (ProRelset    *relset,
                                         wchar_t    ***constraints);
/*
  Purpose: Obtains the constraints applied to a given relation set.
           Constraints may be assigned when one or more parameters of the set is
           governed by an external parameter file. They act as read-only 
           relations.

  Input Arguments:
     relset - The relation set.

  Output Arguments:
      constraints - ProArray of constraints assigned to the parameters in the
                    given relation set.

  Return Values:
     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProRelsetPostregenerationInit (ProMdl           pro_model,
                                               ProRelset       *p_relset);
/*
   Purpose: Initializes a <i>ProRelset</i> data structure for 
            post-regeneration relations. 
            <p><b>Note:</b> This function complements ProModelitemToRelset, 
            which is not applicable for post-regeneration relations.  
            The obtained post regeneration ProRelset data can be used in 
            ProRelsetRelationsGet, ProRelsetRelationsSet, ProRelsetRegenerate 
            and ProRelsetDelete.

   Input Arguments:
       pro_model           - The model  

  Output Arguments:
       p_relset         - The post regeneration relation set

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded. 
       PRO_TK_E_NOT_FOUND - The post regeneration relation set was not found.
       PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
*/

extern ProError ProRelsetIsUnitsSensitive (ProRelset  *p_relset,
                                           ProBool    *p_is_units_sensitive);
/*
   Purpose: Gets the p_is_units_sensitive attribute of the given relation set.

   Input Arguments:
       p_relset              - The relation set.

  Output Arguments:
       p_is_units_sensitive  - A Boolean stating if the relation set should
	                           be set as units sensitive.

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded. 
       PRO_TK_E_NOT_FOUND - The post regeneration relation set was not found.
       PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
*/

extern ProError ProRelsetUnitsSensitiveSet (ProRelset  *p_relset,
                                            ProBool     p_is_units_sensitive);
/*
   Purpose: Sets the p_is_units_sensitive attribute of the given relation set.

   Input Arguments:
       p_relset              - The relation set.
	   p_is_units_sensitive  - A Boolean stating if the relation set should
	                           be set as units sensitive.

  Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR    - The function succeeded. 
       PRO_TK_E_NOT_FOUND - The post regeneration relation set was not found.
       PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
*/

PRO_END_C_DECLS
 
#endif /* PRORELSET_H */
