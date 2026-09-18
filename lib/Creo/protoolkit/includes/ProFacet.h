#ifndef PROFACET_H_
#define PROFACET_H_

#include <ProToolkit.h>
#include <ProObjects.h>



PRO_BEGIN_C_DECLS

typedef struct pro_model_item ProFacetSet;

typedef struct new_facet* ProFacet;

typedef struct new_vtx_and_data* ProFacetVertex;   

typedef ProError (*ProFacetFilterAction) (ProFacet facet, 
                                          ProAppData app_data);
/*
    Purpose: Filter action for a facet in the faceted geometry set.

    Input Arguments:
        facet - The facet.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Skip visiting this item.
        Any other value - Visit this item and pass this error code to the visit 
                          action.

*/

typedef ProError (*ProFacetVisitAction) (ProFacet facet, 
                                         ProError error, 
					 ProAppData app_data);
/*
    Purpose: Visit action for a facet in the faceted geometry set.

    Input Arguments:
        facet - The facet.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and return this error code from the 
                          visit function.

*/

typedef ProError (*ProFacetsetFilterAction) (ProFacetSet* facet_set, 
                                             ProAppData app_data);
/*
    Purpose: Filter action for visiting the facet sets in a solid model.

    Input Arguments:
        facet_set - The facet set.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Skip visiting this item.
        Any other value - Visit this item and pass this error code to 
	                  the visit action.

*/

typedef ProError (*ProFacetsetVisitAction) (ProFacetSet* facet_set, 
                                            ProError error, 
					    ProAppData app_data);
/*
    Purpose: Visit action for visiting the facet sets found in a solid model.   

    Input Arguments:
        facet_set - The facet set.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and return this error code from the 
                          visit function.

*/

extern ProError ProSolidFacetsetVisit (ProSolid solid, 
                                       ProFacetsetVisitAction action, 
				       ProFacetsetFilterAction filter, 
				       ProAppData app_data);
/*
    Purpose: Visits each of the facet sets found in the given solid model.

    Input Arguments:
        solid - The part or assembly.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No items were found.
        Any other value - Visiting stopped due to this error return 
	                  from the visit action.

*/

extern ProError ProFacetsetFacetVisit (ProFacetSet* facet_set, 
                                       ProFacetVisitAction action, 
				       ProFacetFilterAction filter, 
				       ProAppData app_data);
/*
    Purpose: Visits the facets in the faceted geometry set.

    Input Arguments:
        facet_set - The set of facetted geometry.
        action - The visit action
        filter - The filter action
        app_data - Application data passed to the action functions.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No items were found.
        Any other value - Visiting stopped due to this error return from 
	                  the visit action.

*/

extern ProError ProFacetVerticesGet (ProFacet facet, 
                                     ProFacetVertex vertices[3]);
/*
    Purpose: Obtains the vertices for the given facet.

    Input Arguments:
        facet - The facet.

    Output Arguments:
        vertices - The facet vertices.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProFacetvertexPointGet (ProFacetVertex vertex, 
                                        ProPoint3d point);
/*
    Purpose: Obtains the facet vertex location.

    Input Arguments:
        vertex - The facet vertex

    Output Arguments:
        point - The location of the vertex.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProFacetNormalGet (ProFacet facet, 
                                   ProVector normal);
/*
    Purpose: Obtains the facet's normal vector.

    Input Arguments:
        facet - The facet.

    Output Arguments:
        normal - The normal for the given facet.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProFacetverticesFree (ProFacetVertex vertices[3]);
/*
    Purpose: Frees the memory allocated for the vertices of a facet.
    
    Input Arguments:
        vertices - The facet vertices
    
    Output Arguments:
        none
	
    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/
    	
PRO_END_C_DECLS

#endif
