#ifndef PROMFGDB_H
#define PROMFGDB_H

/* Creo Parametric TOOLKIT functions and callback types for
   access to external Databases. */



#include <ProToolkit.h>
#include <ProToolinput.h>
#include <ProParamval.h>



PRO_BEGIN_C_DECLS

typedef struct mfgdb_data             *ProMfgdbData;
typedef struct mfgdb_name             *ProMfgdbName;
typedef struct mfgdb_search_option    *ProMfgdbSearchopt;
typedef struct mfgdb_match            *ProMfgdbMatch;
typedef struct query_node             *ProMfgdbQuerynode;
typedef struct search_expression      *ProMfgdbExpression;


typedef enum
{
    PROMFGDBCAT_UNUSED         = -1,
    PROMFGDBCAT_MFG_MODEL      =  1,
    PROMFGDBCAT_MACHINE_TOOL,
    PROMFGDBCAT_CUTTING_TOOL,
    PROMFGDBCAT_OPERATION,
    PROMFGDBCAT_TECHNOLOGY_DATA,
    PROMFGDBCAT_BOM_COMPONENTS,
    PROMFGDBCAT_STEP               /* NC SEQUENCE */
} ProMfgdbObjCategory;


typedef enum
{
    PROMFGDBTYPE_UNUSED      = -1,
    PROMFGDBTYPE_UNSPECIFIED =  0,
    PROMFGDBTYPE_GENERAL     =  1,
    PROMFGDBTYPE_NC_MFG      =  2,
    PROMFGDBTYPE_MILLING     = 10,
    PROMFGDBTYPE_DRILL,
    PROMFGDBTYPE_CENTER_DRL,
    PROMFGDBTYPE_CSINK,
    PROMFGDBTYPE_SIDE_MILL,
    PROMFGDBTYPE_PLUNGE_MILL,
    PROMFGDBTYPE_TAPER, 
    PROMFGDBTYPE_BACK_SPOT,
    PROMFGDBTYPE_GROOVE,
    PROMFGDBTYPE_MILL_THREAD,
    PROMFGDBTYPE_TAP,
    PROMFGDBTYPE_BORE,
    PROMFGDBTYPE_REAM,
    PROMFGDBTYPE_TURN,
    PROMFGDBTYPE_TURN_GRV,
    PROMFGDBTYPE_CHAMFERING,
    PROMFGDBTYPE_ROUNDING,
    PROMFGDBTYPE_HOLDER,
    PROMFGDBTYPE_INSERT,
    PROMFGDBTYPE_ADAPTER,
    PROMFGDBTYPE_END_MILL,
    PROMFGDBTYPE_BALL_MILL,
    PROMFGDBTYPE_BULL_MILL,
    PROMFGDBTYPE_BASIC_DRILL,
    PROMFGDBTYPE_SPOT_DRILL,
    PROMFGDBTYPE_KEY_CUTTER,
    PROMFGDBTYPE_LOLLIPOP,
    PROMFGDBTYPE_BORING_BAR,
    PROMFGDBTYPE_MULTI_TASK
} ProMfgdbObjType;


typedef enum
{
    PROLOGICOPER_NULL,
    PROLOGICOPER_AND,
    PROLOGICOPER_OR
} ProMfgdbLogicOper;


typedef enum
{
    PROMFGDBCOMPOP_EQUALS,
    PROMFGDBCOMPOP_LESS_THAN,
    PROMFGDBCOMPOP_GREATER_THAN,
    PROMFGDBCOMPOP_LESS_OR_EQUAL,
    PROMFGDBCOMPOP_GREATER_OR_EQUAL,
    PROMFGDBCOMPOP_CONTAINS,
    PROMFGDBCOMPOP_BEFORE,
    PROMFGDBCOMPOP_AFTER
} ProMfgdbCompOper;     /* comparison operation */


typedef ProError (*ProMfgdbSearchAction)(
    ProMfgdbQuerynode   root_node,
    int                 timeout,
    ProAppData          appdata,
    ProMfgdbMatch       **p_match_arr,
    ProLine             error);

/*
  Purpose: Type for callback used by Creo Parametric to initiate
           a query to search the database for objects.
           To register this user-specified function for use by 
           Creo Parametric, specify the function as an input argument 
           to ProMfgdbRegister().

  Input Arguments:

     root_node - Root node of the query tree. The memory for this tree
                 is allocated by Creo Parametric and will be automatically freed when 
                 the callback function returns. It is the user's 
                 responsibility to save any data for use in subsequent 
                 queries. 

     timeout   - The timeout period in seconds. If the database does
                 not respond during this period, the function
                 returns status PRO_TK_TIMED_OUT. Value -1 means no timeout.

     appdata   - Pointer to data specific to the Creo Parametric TOOLKIT application
                 which was passed in the call to ProMfgdbRegister().

  Output Arguments:

     p_match_arr  - The matching object description, to be stored
                    in an array of type ProArray.

     error        - Text of an error message that Creo Parametric will
                    display to the user if the function returns any
                    error status. To support more than one language,
                    provide a message file containing the translations, 
                    and use ProMessageToBuffer() to translate the string.

  Return Values:

      PRO_TK_NO_ERROR    - At least one successful match was found
      PRO_TK_BAD_INPUTS  - The query could be interpreted
      PRO_TK_E_NOT_FOUND - No matches were found
      PRO_TK_CANT_OPEN   - Database connection is lost - login required
      PRO_TK_TIMED_OUT   - The database could not be accessed within
                           the timeout period.
*/


typedef ProError (*ProMfgdbLoginAction)(
    ProName            dbname,
    ProName            user_name,
    ProName            password,
    int                timeout,
    ProAppData         appdata,
    ProLine            error);

/*
  Purpose: Type for callback used by Creo Parametric to initiate
           an access to the database. To register this user-specified function
           for use by Creo Parametric, specify the function as an input argument 
           to ProMfgdbRegister().

  Input Arguments:

     dbname    - A name used to identify the database.

     user_name - A user name for database access.

     password  - A password for database access.

     timeout   - The timeout period in seconds. If the database does
                 not respond during this period, the function
                 returns with status PRO_TK_TIMED_OUT.
                 The value -1 means no timeout.

     appdata  -  Pointer to data specific to the Creo Parametric TOOLKIT application
                 which was passed in the call to ProMfgdbRegister().
                 Database program can cache connection information into
                 the appdata for subsequent connection requests.

  Output Arguments:

     error    -  Text of an error message that Creo Parametric
                 displays to the user if the function
                 returns an error status. To support more than 
                 one language, provide a message file containing 
                 the translations and use ProMessageToBuffer() 
                 to translate the string.

  Return Values:

      PRO_TK_NO_ERROR    - Database access available.
      PRO_TK_BAD_INPUTS  - Database not found.
      PRO_TK_TIMED_OUT   - The database could not be accessed within
                           the timeout period.
*/


typedef ProError (*ProMfgdbLogoffAction)(
    ProName            dbname,
    int                timeout,
    ProAppData         appdata,
    ProLine            error);

/*
  Purpose: Type for callback used by Creo Parametric to close
           a connection to the database.To register this user-specified 
           function for use by Creo Parametric, specify the function as an input 
           argument to ProMfgdbRegister().

  Input Arguments:

     dbname    - A name used to identify the database.

     timeout   - The timeout period in seconds. If the database does
                 not respond during this period, the function returns
                 with status PRO_TK_TIMED_OUT. Value -1 means no timeout.

     appdata  -  Pointer to data specific to the Creo Parametric TOOLKIT application
                 which was passed in the call to ProMfgdbRegister().
                 Database programs can cache connection information into
                 the appdata for subsequent connection requests.

  Output Arguments:

     error    -  Text of an error message that Creo Parametric
                 displays to the user if the function
                 returns an error status. To support more than 
                 one language, provide a message file containing 
                 the translations, and use ProMessageToBuffer() to 
                 translate the string.

  Return Values:

      PRO_TK_NO_ERROR    - Database connection closed successfully.
      PRO_TK_BAD_INPUTS  - Connection to the specified database not found.
      PRO_TK_TIMED_OUT   - The database could not be accessed within
                           the timeout period.
*/


extern ProError ProMfgdbDataAlloc (  
    ProMfgdbData	       *p_mfgdb_data );
/*
   Purpose: Allocates memory to store optional, non-Creo Parametric-native
            search parameters and external tool database names for use 
            in creating queries.

   Input Arguments:

      None

   Output Arguments:

      p_mfgdb_data         - The allocated structure.

   Return Values:

      PRO_TK_BAD_INPUTS    - Invalid argument.
      PRO_TK_NO_ERROR      - The function successfully allocated 
                             the memory. 
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/


extern ProError ProMfgdbDataDbnameAdd (  
    ProMfgdbData	       mfgdb_data,
    ProName                db_external_name,
    ProCharName            db_internal_name,
    ProLine                db_name_help_text );
/*
   Purpose: Adds the name of  an external tool database to the structure 
            created by ProMfgdbDataAlloc. To add multiple names,
            make multiple calls to this function with each call specifying a
            new db_external_name.

   Input Arguments:


      mfgdb_data          - handle to the mfgdb_data.

      db_external_name    - database name; can be translated.
                            Can be NULL. db_internal_name is used if there
                            is no translation. 

      db_internal_name    - database name; never translated.

      db_name_help_text  -  help text line. This can  be translated. This can
                            also be NULL, in which case internal_name
                            is used without translation. 

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR    - The function successfully added database name data.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbDataSearchoptAdd (  
    ProMfgdbData	       mfgdb_data,
    ProMfgdbSearchopt      search_option );
/*
   Purpose: Adds definitions of an optional, non-Creo Parametric-native
            search parameter to the structure created by ProMfgdbDataAlloc.
            To add multiple names, make multiple calls to this function with
            each call specifying a new search_option name.


   Input Arguments:

      mfgdb_data           - handle to the database data.

      search_option        - option created by user for search UI.

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR    - The function successfully added database name data.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbSearchoptCreate (  
    ProName                external_name,
    ProCharName            internal_name,
    ProLine                help_text,
    ProParamvalueType      value_type,
    ProMfgdbName           group_name,
    ProMfgdbSearchopt	   *p_search_option );
/*
   Purpose: Allocates and initializes a structure for the user's optional, 
            non-Creo Parametric-native search parameters.

   Input Arguments:

      external_name     - name; can be translated.
                          Can be NULL. internal_name is used if there is
                          no translation. 

      internal_name     - name; never translated.

      help_text         - help line for the search option;  can be 
                          translated. Can be NULL. internal_name is
                          used if there is no translation. 

      value_type        - option value type.

      group_name        -  group name data, such as Geometry, General, or All,
                           in search UI. Each option can be associated 
                           with only one group of options in the search UI.
                           Can be NULL; group All used if specified as NULL.

   Output Arguments:

      p_search_option      - Allocated and initialized option for search UI;

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully allocated and 
                             initialized the option for search UI.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbSearchoptApplicDataAdd (  
    ProMfgdbSearchopt	   search_option,
    ProMfgdbObjCategory    category,
    ProMfgdbObjType        object_type );
/*
   Purpose: Adds applicability data to the optional, non-Creo Parametric-native
            search parameter. This data sets the category and object type for
            which the search option is valid. Use multiple calls to this 
            function if the option is valid for multiple categories or object
            types.

   Input Arguments:

      search_option        - user-specified option for search UI.

      category             - applicable object category.

      object_type          - applicable object type.

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully added 
                             applicability data to the option.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbSearchoptAllowedValueAdd (  
    ProMfgdbSearchopt      search_option,
    ProLine                external_value,
    ProCharLine            internal_value,
    ProLine                help_text );
/*
   Purpose:  Adds valid value for the optional, non-Creo Parametric-native 
            search parameter. Use multiple calls to this function if the 
            option has multiple valid values.

   Input Arguments:

      search_option        -  option, created by user for search UI.

      external_value       -  value; can be translated. Can be NULL.
                              nternal_value is used if there is
                              no translation. 

      internal_value       -  value; never translated.

      help_text            -  value help text; can be translated.
                              Can be NULL. internal_value
                              is used if there is no translation. 

   Output Arguments:

      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully added allowed value 
                             to the option.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbNameCreate (  
    ProName                  external_name,
    ProCharName              internal_name,
    ProLine                  help_text,
    ProMfgdbName             *p_mfgdb_name );
/*
   Purpose: Allocates and initializes a name structure for the groups into
            which optional, non-Creo Parametric-native search parameters are
            organized. Use multiple calls to this function to create multiple
            group structure names.

   Input Arguments:

      external_name        -  name; can be translated.  Can be NULL. 
                              internal_name is used if there is
                              no translation. 

      internal_name        -  name; never translated.

      help_text            -  help prompt for name; can be translated.  
                              Can be NULL. internal_name used if there is 
                              no translation. 

   Output Arguments:

      p_mfgdb_name           - handle to allocated and initialized 
                               name structure.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully allocated 
                             and initialized the name structure.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbMatchAlloc (  
    ProMfgdbMatch	       *p_mfgdb_match );
/*
   Purpose: Allocates memory for a structure to contain query matches.

   Input Arguments:

      None

   Output Arguments:

      p_mfgdb_match        - pointer to handle to allocated match structure.

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully allocated 
                             memory for match.
      PRO_TK_BAD_INPUTS    - Invalid argument.
      PRO_TK_OUT_OF_MEMORY - Insufficient memory.
*/


extern ProError ProMfgdbMatchParamAdd (  
    ProMfgdbMatch	       mfgdb_match,
    ProName                param_external_name,
    ProCharName            param_internal_name,
    ProLine                value_wstr,
    ProParamvalueType      value_type );
/*
   Purpose: Adds a parameter to the match in the structure allocated by
            ProMfgdbMatchAlloc().

   Input Arguments:

      mfgdb_match          -  match with parameter added.

      param_external_name  -  parameter name; can be translated.
                              Can be NULL.  param_internal_name used
                              if there is no translation.

      param_internal_name  -  parameter name; never translated.

      value_wstr           -  parameter value.

      value_type           -  value type ( PRO_PARAM_DOUBLE, 
                              PRO_PARAM_STRING...).
   Output Arguments:

      None

   Return Values:
      PRO_TK_NO_ERROR      -  The function successfully added the parameter
                              to the match.
      PRO_TK_BAD_INPUTS    -  One or more of the input arguments are invalid.
*/


extern ProError ProMfgdbRegister(
          ProMfgdbData          mfgdb_data,
          ProMfgdbLoginAction   login_callback,
          ProMfgdbLogoffAction  logoff_callback,
          ProMfgdbSearchAction  search_callback,
          ProAppData            appdata,
          ProMfgdbObjCategory   target);
/*
   Purpose:  Registers an external database with Creo Parametric. This function 
            sets the functions to be called to gain access to a database, to
            close a database, and the function that executes database queries.
            It also specifies any optional user data passed to the registered
            callbacks.

   Input Arguments:

      mfgdb_data      - information about the database.

      login_callback  - Pointer to the callback function that will
                        be executed to get access to the database.

      logoff_callback - Pointer to the callback function that will
                        be executed to close a connection to the database.

      search_callback - Pointer to the callback function that will
                        execute the database queries.

      appdata         - Pointer to data specific to the Creo Parametric TOOLKIT
                        application that will be passed as an
                        input the query callback.

      target          - category of object searched in database.

   Output Arguments:

      None

   Return Values:
      PRO_TK_NO_ERROR   - The database was registered.
      PRO_TK_BAD_INPUTS
*/


extern ProError ProMfgdbQueryTargetGet (
    ProMfgdbQuerynode           node,
    ProMfgdbObjCategory         *p_target );
/*
   Purpose: Return the target object searched for by the query tree that
            contains the specified node. All nodes in the same query tree
            return the same target. 

   Input Arguments:

      node              - The query node.

   Output Arguments:

      p_target          - The target of a query.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrived the target.
      PRO_TK_BAD_INPUTS - The node handle was invalid.
*/


extern ProError ProMfgdbQuerynodeIsLeaf( 
    ProMfgdbQuerynode       query_node,
    ProBoolean	            *leaf_node );
/*
   Purpose:   Allows the user to determine whether the given node is a 
              leaf (that is, a node that contains expressions).

   Input Arguments:

      query_node        -  The query node.

   Output Arguments:

      leaf_node	        - Node is a leaf.

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrived leaf_node flag.
      PRO_TK_BAD_INPUTS - The query_node handle was invalid.
*/


extern ProError ProMfgdbQuerynodeLeftChildGet (  
    ProMfgdbQuerynode 	        parent_node,
    ProMfgdbQuerynode	        *p_left_child );
/*
   Purpose: Return the left branch of a query node

   Input Arguments:

      parent_node       - The parent query node.

   Output Arguments:

      p_left_child      - The right child query node

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrived the left child.
      PRO_TK_BAD_INPUTS - The parent_node handle was invalid.
*/


extern ProError ProMfgdbQuerynodeRightChildGet (  
    ProMfgdbQuerynode 	        parent_node,
    ProMfgdbQuerynode	        *p_right_child );
/*
   Purpose: Return the right branch of a query node

   Input Arguments:

      parent_node       - The parent query node.

   Output Arguments:

      p_right_child     - The right child query node

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrived the right child.
      PRO_TK_BAD_INPUTS - The parent_node handle was invalid.
*/


extern ProError ProMfgdbQuerynodeLogicOperGet(
    ProMfgdbQuerynode           query,
    ProMfgdbLogicOper           *p_oper);

/*
   Purpose:  Returns from a node the logical operation (AND or OR) 
            applied to the specified query.

   Input Arguments:

      query     - The query.

   Output Arguments:

      p_oper	- The operation.


  Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrived the logical oper
      PRO_TK_BAD_INPUTS - The query_node handle was invalid or did not 
                          contain a logical operation.
*/


extern ProError ProMfgdbQuerynodeExprGet(
    ProMfgdbQuerynode      query_node,
    ProMfgdbExpression     *p_expression);

/*
   Purpose: Provides the expressions for the given query.  Note that 
            the query_node must be a leaf node.

   Input Arguments:

      query_node        - Handle to the node for which the expression is
                          retrieved.

   Output Arguments:

      p_expression      - Handle to output ProMfgdbExpression.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the handle
      PRO_TK_BAD_INPUTS - The query_node handle was invalid or did not 
      			  contain an expression.
*/


extern ProError ProMfgdbExprCategoryGet(
    ProMfgdbExpression   expression,
    ProMfgdbObjCategory  *p_category );

/*
   Purpose: Provides the category of the attribute contained in the
            specified expression in a leaf node.

   Input Arguments:

      expression        - The expression.

   Output Arguments:

      p_category        - The category.

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrived the category.
      PRO_TK_BAD_INPUTS - The expression handle was invalid or did not 
                          contain a category.
*/


extern ProError ProMfgdbExprNameGet(
    ProMfgdbExpression expression,
    ProName            name);

/*
   Purpose: Provides the name of the attribute contained in the 
            specified expression in a leaf node.

   Input Arguments:

      expression        - The expression.

   Output Arguments:

      name              - The attribute name.

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrived the name.
      PRO_TK_BAD_INPUTS - The expression handle was invalid or did not 
                          contain a name.
*/


extern ProError ProMfgdbExprValueGet(
    ProMfgdbExpression expression,
    ProLine value);

/*
   Purpose: Returns the value of the attribute contained in the 
            specified expression in a leaf node.

   Input Arguments:

      expression        - The expression.

   Output Arguments:

      value             - The attribute value.

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrived the value.
      PRO_TK_BAD_INPUTS - The expression handle was invalid or did not
                          contain a value.
*/


extern ProError ProMfgdbExprValueTypeGet(
    ProMfgdbExpression expression,
    ProParamvalueType  *p_value_type );

/*
   Purpose: Returns the value type of the attribute contained in the 
            specified expression so the user knows the data type of the
            search parameter. Use when defining a query, for example, search
            on Boolean, String, and so on.

   Input Arguments:

      expression        - The expression.

   Output Arguments:

      p_value_type      - The attribute value type 
                          ( PRO_PARAM_DOUBLE, PRO_PARAM_STRING... ).

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrived the value.
      PRO_TK_BAD_INPUTS - The expression handle was invalid or did not
                          contain a value.
*/


extern ProError ProMfgdbExprCompopGet(
    ProMfgdbExpression   expression,
    ProMfgdbCompOper     *p_comp_op);

/*
   Purpose: Provides the comparison operation (=, <, >, etc.) 
            contained in the specified expression.

   Input Arguments:

      expression        - The expression.

   Output Arguments:

      p_comp_op         - The comparison operation.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrived the comp oper.
      PRO_TK_BAD_INPUTS - The expression handle was invalid or did not
                          contain a comparison operation.
*/


extern ProError ProMfgdbDeregister( ProMfgdbObjCategory target );
/*
   Purpose: Deregisters an external database with Creo Parametric.
            It also calls any ProMfgdbLogoffAction action defined
            by the user.

   Input Arguments:

      target            - Category of the registered database.

   Output Arguments:

      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully deregistered the database.
      PRO_TK_BAD_INPUTS - Database of the input Category is not available.
*/

PRO_END_C_DECLS
#endif  /* PROMFGDB_H */
