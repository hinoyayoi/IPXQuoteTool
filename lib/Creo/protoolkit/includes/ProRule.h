#ifndef PRORULE_H
#define PRORULE_H

/* Creo Parametric TOOLKIT declarations for ProSimpreprule related actions */

#include <ProObjects.h>



PRO_BEGIN_C_DECLS

/*
   Types of rules used to evaluate inclusion/exclusion in a simplified rep
*/
typedef enum pro_simprep_rule_types
{
    PRO_RULE_NONE,        /* No rule is defined. */
    PRO_RULE_NAME,        /* Substitute by name. */
    PRO_RULE_ZONE,        /* Select items by zone. */
    PRO_RULE_EXPR,        /* Select items by expression. */
    PRO_RULE_SIZE,        /* Select items by size. */
    PRO_RULE_DIST,        /* Select items by distance. */
    PRO_RULE_SIMP_REP     /* Select items active in the specified 
                             representation. */
} ProRuleType;

typedef ProLine *ProExpression;

typedef struct pro_rule_size
{
    ProBoolean  absolute;  /* PRO_B_TRUE to compare absolute size of the model
                              otherwise - compare relative size (0.0 - 1.0)
                              with respect to the assembly */
    ProBoolean  greater;   /* PRO_B_TRUE to collect models that are larger than
                              the specified size, otherwise collect the smaller
                              ones */ 
    double      value;     /* Size to compare against (valid range is 
                               0.0 to 1.0 if absolute == PRO_B_FALSE) */
    ProBoolean  incl_datums; /* if TRUE - use bbox, FALSE - regen outline */

}   ProRuleSize;

typedef struct pro_rule_dist
{
    ProVector   center;    /* Center point from which to measure the
                              distance (in the coordinates of the top 
                              assembly */
    double      distance;  /* Distance value to compare against */
    ProBoolean  incl_datums; /* if TRUE - use bbox, FALSE - regen outline */

} ProRuleDist;

/*
   ProRule - Specifies the rule type and data to support various
                    flavors of the simplified representation rules.
*/
typedef struct pro_rule
{
   ProRuleType         type;
   union                         
   {
       ProName       name_mask;     /* PRO_RULE_NAME - name mask to compare */
       ProRuleSize   size_data;     /* PRO_RULE_SIZE - size data */
       ProExpression expression;    /* PRO_RULE_EXPR - expression to evaluate */
       ProFeature    zone_feat;     /* PRO_RULE_ZONE - zone feature */
       ProSimprep    simp_rep;      /* PRO_RULE_SIMP_REP - simplified 
                                       representation to evaluate */
       ProRuleDist   dist_data;     /* PRO_RULE_DIST - distance data */ 
   }   rule_data;
}  ProRule;

extern ProError ProRuleInitName (ProName name_mask, ProRule *rule);

/*
   Purpose:  Initializes the <i>ProRule</i> data structure.

   Input Arguments:
      name_mask         - The data specific to the rule type being initialized
      
   Output Arguments:
      rule           	- The <i>ProRule</i> data structure to be filled in

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data 
                          structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProRuleInitExpr (ProExpression expr, 
				 ProRule *rule);
/*

   Purpose:  Initializes the <i>ProRule</i> data structure for the specified
             expression.

   Input Arguments:
      expr              - The expression
      
   Output Arguments:
      rule           	- The <i>ProRule</i> data structure to be filled in

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data 
                          structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProRuleInitZone (ProFeature  *zone_feat, 
				 ProRule *rule);
/*
   Purpose:  Initializes the <i>ProRule</i> data structure according to the
             specified data.

   Input Arguments:
      zone_feat         - The data specific to the rule type being initialized
      
   Output Arguments:
      rule           	- The <i>ProRule</i> data structure to be filled in

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data 
                          structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProRuleInitDist (ProRuleDist *dist_data, 
				 ProRule *rule);
/*

   Purpose:  Initializes the <i>ProRule</i> data structure according to the
             specified data.

   Input Arguments:
      dist_data         - The data specific to the rule type being initialized
      
   Output Arguments:
      rule           	- The <i>ProRule</i> data structure to be filled in

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data 
                          structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProRuleInitSize (ProRuleSize *size_data, 
				 ProRule *rule);
/*

   Purpose:  Initializes the <i>ProRule</i> data structure according to the
             specified data.

   Input Arguments:
      size_data         - The data specific to the rule type being initialized
      
   Output Arguments:
      rule           	- The <i>ProRule</i> data structure to be filled in

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data 
                          structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProRuleInitRep  (ProSimprep  *simp_rep,  
				 ProRule *rule);

/*
   Purpose:  Initializes the <i>ProRule</i> data structure according to the
             specified data.

   Input Arguments:
      simp_rep          - The data specific to the rule type being initialized
      
   Output Arguments:
      rule           	- The <i>ProRule</i> data structure to be filled in

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the data 
                          structure.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProRuleEval (ProSolid         p_solid,
                             ProRule         *p_rule,
                             ProAsmcomppath  **p_comp_list,
                             int             *p_list_size);
/*
   Purpose:  Returns a list of components that satisfy the specified rule.

   Input Arguments:
      p_solid           - The solid to evaluate.
      p_rule            - The rule data to evaluate.

   Output Arguments:
      p_comp_list       - The list of components that satisfy the rule.
                          Use <b>ProArrayFree()</b> to free the 
                          allocated memory.
                          
      p_list_size       - The size of the returned list of components.
                          May be NULL.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully completed the rule 
                           evaluation.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.

   See Also:
      ProArrayFree()
*/

PRO_END_C_DECLS
#endif /* PRORULE_H */
