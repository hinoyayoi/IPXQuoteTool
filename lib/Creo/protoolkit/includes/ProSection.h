

#ifndef PROSECTION_H
#define PROSECTION_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSelection.h>
#include <ProItemerr.h>
#include <Pro2dEntdef.h>
#include <ProSecdimType.h>
#include <ProSecerror.h>
#include <ProSecConstr.h>

PRO_BEGIN_C_DECLS

typedef struct section_data *ProSection;
typedef struct section_data *ProSection3d;
typedef struct section_data *ProSection2d;

typedef struct sec_info     * ProWSecinfo;

typedef enum 
{
   PRO_SEC_ORIENT_BOTTOM, 
   PRO_SEC_ORIENT_TOP, 
   PRO_SEC_ORIENT_LEFT,
   PRO_SEC_ORIENT_RIGHT
} ProSecOrient ;

typedef enum
{
   PRO_SECSHAPE_EMPTY,               /* empty section             */
   PRO_SECSHAPE_POINTS,              /* points only               */
   PRO_SECSHAPE_1_OPEN_LOOP,         /* one open loop             */
   PRO_SECSHAPE_1_CLOSED_LOOP,       /* one closed loop           */
   PRO_SECSHAPE_MIXED_LOOPS,         /* open and closed loops     */
   PRO_SECSHAPE_MULTI_OPEN_LOOPS,    /* several open loops        */
   PRO_SECSHAPE_MULTI_CLOSED_LOOPS,  /* several closed loops      */
   PRO_SECSHAPE_INTERSECTING         /* self-intersections        */
} ProSectionShape;

extern ProError ProSection2DAlloc (ProSection *p_2d_section);
/* 
   Purpose:
        Allocates a two-dimensional section.

   Input Arguments:
        None

   Output Arguments:
        p_2d_section - The new <i>ProSection</i>

   Return Values:                                                            
        PRO_TK_NO_ERROR     - The function successfully allocated the handle. 
        PRO_TK_BAD_INPUTS   - The input argument is invalid.
        PRO_TK_OUT_OF_MEMORY - There was a memory error.
*/

extern ProError ProSectionFree (ProSection *section);

/* 
   Purpose:
        Frees the specified section.

   Input Arguments:
        section    - The section to free 

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully freed the section.
        PRO_TK_BAD_INPUTS    - The argument is invalid.
        PRO_TK_OUT_OF_MEMORY  - There was a memory error.
*/
        

extern ProError ProSectionSolve (ProSection section, ProWSecerror *sec_errors);
/* 
   Purpose:
        Solves the specified section.
<p>
	This function shouldn't be called if Intent Manager mode is used
	for the section (see ProSectionIntentManagerModeSet())

   Input Arguments:
        section     - The handle to an unsolved section
                                          
   Output Arguments:
        sec_errors - The section errors filled out by the function. Before
                     calling this function, allocate the pointer to
                     ProWSecerror using ProSecerrorAlloc().
                     This array is populated if the function returns a value 
                     other than PRO_TK_NO_ERROR.
                     Free the allocated memory later using the function
                     ProSecerrorFree().

   Return Values:
        PRO_TK_NO_ERROR    - The function successfully solved the section.
        PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
	PRO_TK_BAD_CONTEXT - Intent Manager mode is used for the section
        Other              - Another error occurred and the function failed.
*/

extern ProError ProSectionSolveRigid (ProSection section, 
				      ProWSecerror *sec_errors);
/* 
   Purpose:
        Solves the specified section by fixing the coordinates of all the
        entities with respect to a coordinate system. The coordinate system
        is taken to be the first coordinate system in the section.
<p>
	This function shouldn't be called if Intent Manager mode is used
	for the section (see ProSectionIntentManagerModeSet())

   Input Arguments:
        section     - The handle to an unsolved section
                                          
   Output Arguments:
        sec_errors - The section errors filled out by the function. Before
                     calling this function, allocate the pointer to
                     ProWSecerror using ProSecerrorAlloc().
                     This array is populated if the function returns a value
                     other than PRO_TK_NO_ERROR.
                     Free the allocated memory later using the function
                     ProSecerrorFree().

   Return Values:
        PRO_TK_NO_ERROR        - The function successfully solved the section.
        PRO_TK_BAD_INPUTS      - One or more of the input arguments are invalid.
	PRO_TK_BAD_CONTEXT     - Intent Manager mode is used for the section
	PRO_TK_NO_COORD_SYSTEM - A coordinate system must be supplied for this
                                 operation, but none was found.
        Other                  - Another error occurred and the function failed.
*/

extern ProError ProSectionRegenerate (ProSection section, 
				      ProWSecerror *sec_errors);
/* 
   Purpose:
        Regenerates the specified section.
<p>
	This function shouldn't be called if Intent Manager mode is used
	for the section (see ProSectionIntentManagerModeSet())

   Input Arguments:
        section -    The solved section

   Output Arguments:
        sec_errors - The section errors filled out by the function. Before
                     calling this function, allocate the pointer to 
                     ProWSecerror using ProSecerrorAlloc().
                     This array is populated if the function returns a value
                     other than PRO_TK_NO_ERROR. 
                     Free the allocated memory later using the function
                     ProSecerrorFree(). 

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully regenerated the section.
        PRO_TK_BAD_INPUTS    - The input argument is invalid.
	PRO_TK_BAD_CONTEXT   - Intent Manager mode is used for the section
        PRO_TK_OUT_OF_MEMORY - There was a memory error.
        Other                - Another error occurred and the function failed.
*/

extern ProError ProSectionAutodim (ProSection section, 
				   ProWSecerror *sec_errors);
/*
   Purpose:
        Adds dimensions to the section as needed to make it fully constrained.
<p>
	This function shouldn't be called if Intent Manager mode is used
	for the section (see ProSectionIntentManagerModeSet())

   Input Arguments:
        section -    The solved section. This cannot be NULL.

   Output Arguments:
        sec_errors - The section errors filled out by the function,
		     if any. Before calling this function, allocate the 
                     pointer to ProWSecerror using ProSecerrorAlloc().
                     This array is populated if the function returns a value
                     other than PRO_TK_NO_ERROR. 
                     Free the allocated memory later using the function
                     ProSecerrorFree().

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully regenerated the section.
        PRO_TK_BAD_INPUTS    - The input argument is invalid.
	PRO_TK_BAD_CONTEXT   - Intent Manager mode is used for the section
        PRO_TK_OUT_OF_MEMORY - There was a memory error.
        Other                - Another error occurred and the function failed.
*/

extern ProError ProSectionDimensionIdsGet(ProSection section,
                                          ProIntlist *sec_dim_id_list,
                                          ProIntlist *solid_dim_id_list,
                                          int *p_num_ids);
/*
   Purpose:
        Returns corresponding arrays of section dimension identifiers and solid
        dimension identifiers.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        sec_dim_id_list   - The returned array of section dimension 
                            identifiers that have
                            corresponding dimensions in the solid.
                            Release the memory using <b>ProArrayFree()</b>.
        solid_dim_id_list - The returned array of solid dimension identifiers.  
                            Release the memory using <b>ProArrayFree()</b>.
        p_num_ids         - The size of the two returned lists.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
	PRO_TK_NOT_EXIST      - Solid model does not exist or 
	                        number of dimensions does not match
                                in section and solid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionNameGet (ProSection section, ProName r_name);
/* 
   Purpose:
         Returns the name of the specified section.

   Input Arguments:
        section   - The section.

   Output Arguments:
        r_name    - The name of the section. To keep this data, you
                    must copy it.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                name of the section.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
*/

extern ProError ProSectionNameSet (ProSection section, wchar_t new_name[]);
/* 
   Purpose:
        Sets the name of the specified section.

   Input Arguments:
        section   - The section
        new_name  - The new name for the section

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully set the name.
        PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_E_FOUND        - Could not rename the section because another section with this 
                                name already exists.                                
*/

extern ProError ProSectionEntityAdd (ProSection section,
				     Pro2dEntdef *entity2d,
				     int *r_ent_id);
/* 
   Purpose:
        Adds an entity to the specified section.

   Input Arguments:
        section        - The section 
        entity2d       - The entity to add to the section

   Output Arguments:
        r_ent_id       - The assigned identifier of the entity

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully added the entity.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY  - There was a memory error.
	PRO_TK_LINE_TOO_LONG - In the case of a <i>Pro2dTextdef</i> being 
                               added, the text string exceeded the internal 
                               limitation of Creo Parametric.
        PRO_TK_INVALID_NAME  - In the case of a <i>Pro2dTextdef</i> being 
                               added, the text font is not supported by 
			       Creo Parametric.
*/


extern ProError ProSectionEntityDelete (ProSection section, int entity_id);

/* 
   Purpose:
        Deletes an entity from the specified section.

   Input Arguments:
        section    - The section
        entity_id  - The identifier of the entity

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR    - The function successfully deleted the entity.
        PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError ProSectionEntityReplace (ProSection section,
					 int orig_entity_id,
					 int new_entity_id);
/* 
   Purpose:
        Replaces an entity from the specified section with another entity
        from the same section (for redefine purposes).

   Input Arguments:
        section    - The section
        orig_entity_id  - The identifier of the entity to be replaced
        new_entity_id   - The identifier of the entity to replace the old one

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully deleted the entity.
        PRO_TK_NOT_EXIST     - Either of the two input identifiers are invalid.
        PRO_TK_GENERAL_ERROR - Replacement could not be completed.
*/

extern ProError ProSectionEntityGet (ProSection section, int ent_id,
				     Pro2dEntdef **POutEnt);

/*
   Purpose:
        Retrieves a user entity from the specified section.

   Input Arguments:
        section         - The section
        ent_id          - The assigned identifier of the entity

   Output Arguments:
        POutEnt         - A pointer to a static copy of the entity

   Return Values:
        PRO_TK_NO_ERROR     - The function successfully retrieved the entity.
        PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
        PRO_TK_OUT_OF_MEMORY - There was a memory error.
	PRO_TK_LINE_TOO_LONG - In the case of <i>Pro2dTextdef</i>, the text
                              string exceeded the internal limitation of 
                              Creo Parametric.
        PRO_TK_INVALID_NAME - In the case of <i>Pro2dTextdef</i>, the text
                              font name violated the <i>Pro2dTextdef</i> 
                              conventions.
        PRO_TK_INVALID_TYPE - This Creo Parametric entity type is not available in
                              Creo Parametric TOOLKIT environment.
        PRO_TK_GENERAL_ERROR - An unexpected problem occured.
*/


extern ProError ProSectionEpsilonSet (ProSection section,
				      double section_eps);

/* 
   Purpose:
        Sets the sketch epsilon.

   Input Arguments:
        section      - The section 
        section_eps  - The epsilon value 

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR        - The function successfully set the value.
        PRO_TK_BAD_INPUTS      - One or more of the arguments are invalid.
        PRO_TK_GENERAL_ERROR   - A general error occurred and the function
                                 failed.
*/


extern ProError ProSectionEpsilonGet (ProSection section,
				      double *r_section_eps);
/* 
   Purpose:
        Retrieves the epsilon value of the specified sketch.

   Input Arguments:
        section        - The section

   Output Arguments:
        r_section_eps  - The epsilon value 

   Return Values:                                                            
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
*/

extern ProError ProSectionEntityEval (ProSection section,
                                      int ent_id, double param,
                                      ProVector point,
                                      ProVector derivative,
                                      ProVector derivate_2nd);
/*
   Purpose:
         Evaluates the coordinates, and the first and second derivatives 
         of a point on an entity.
        
   Input Arguments:
        section  - The section
        ent_id   - The identifier of an entity in the section
        param    - The parameter of the point
        
   Output Arguments:
        point            - The point coordinates
        derivative       - The first derivative
        derivate_2nd     - The second derivative

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully evaluated the point.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_NOT_FOUND      - The specified entity was not found. 
*/

extern ProError ProSectionEntityTranslate( ProSection section,
					   int ent_id, 
					   ProVector translation_vector);
/*
   Purpose:
         Translates the entity by the specified vector.
        
   Input Arguments:
        section             - The section
        ent_id              - The identifier of the entity in the section
        translation_vector  - The translation vector
        
   Output Arguments:
        None

   Return Values:
        PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
        PRO_TK_NO_ERROR    - The function successfully translated the entity.
*/

extern ProError ProSectionEntityIdsGet(ProSection section,
                                       ProIntlist *p_id_list,
                                       int *p_num_ids);
/*
   Purpose:
        Returns an array of valid section entity identifiers.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        p_id_list - The array of identifiers. The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityFromProjection (ProSection   section,
					        ProSelection ref_geometry,
					        int         *r_ent_id);
/*
   Purpose:
        Creates a known entity in the section by projecting the 
        reference geometry (a surface or an edge) onto the sketching
	plane.
<p>
	If the function is successful, it returns the identifier of the 
        known entity.


   Input Arguments:
        section       - The section
        ref_geometry  - The selected geometry

   Output Arguments:
        r_ent_id      - The identifier of the known entity

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully created the known
                                entity.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                                invalid.
*/

extern ProError ProSectionEntityIsProjection (ProSection   section,
					      int          entity_id,
					      ProBoolean  *is_projection);
/*
   Purpose:
        Determines whether the specified entity in the section is created
        by projection.
<p>
	If the function is successful, it returns the answer in
        the argument <i>is_projection</i>.

   Input Arguments:
        section       - The section
        entity_id     - The entity to be queried

   Output Arguments:
        is_projection - The answer

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully created the known
                                entity.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - One or more of the input arguments are
                                invalid.
*/

extern ProError ProSectionLocationGet (ProSection section,
				       ProMatrix  location_matrix );
/*
   Purpose:  Returns the location of the section with respect
             to its owner (a part or an assembly).

   Input Arguments:   
       section        -  The section belonging to a feature

   Output Arguments:                                                 
       location_matrix - The location matrix that gives the transformation
                         from the section to its owner
 
   Return Values:                     
      PRO_TK_NO_ERROR     -  The function successfully retrieved the
                             information.
      PRO_TK_BAD_INPUTS   -  The input argument is invalid.
*/

extern ProError ProSectionConstraintsGet( ProSection    section,
					  int           constraint_id,
					  ProConstraintType *type,
					  ProConstraintStatus *status,
					  int           *num_refs,
					  int           **p_ent_ids,
					  ProSectionPointType **p_senses );
/*
   Purpose:  Returns information about the specified section constraint. 

   Input Arguments:   
       section        -  The section that belongs to a feature.
       constraint_id  -  The constraint identifier for which the information
                         is requested.

   Output Arguments:                                                 
       type           -  The constraint type.
       status         -  The status of the constraint. 
       num_refs       -  The number of section entities referenced 
                         by the constraint.
       p_ent_ids      -  A pointer to the array of size <i>num_refs</i> that 
                         contains the referenced entity identifiers.
			 The function allocates the memory for this argument.
			 Call <b>ProArrayFree</b>((ProArray*)p_ent_ids) to 
                         free the memory.
       p_senses       -  A pointer to the array of size <i>num_refs</i> 
                         that contains the codes for which part of the 
                         corresponding entity is affected by the constraint.
			 The function allocates the memory for this argument.
			 Call <b>ProArrayFree</b>((ProArray*)p_senses) to 
                         free the memory. 

   Return Values:                     
      PRO_TK_NO_ERROR     -  The function successfully retrieved the 
                             information.
      PRO_TK_BAD_INPUTS   -  The input argument is invalid.

   See Also:
      ProArrayFree()

*/

extern ProError ProSectionConstraintDeny( ProSection section,
					  int constraint_id );

/*
   Purpose:  Denies the specified section constraint.
<p>
             This function shouldn't be called if Intent Manager mode is used
	     for the section (see ProSectionIntentManagerModeSet())

   Input Arguments:   
       section        -  The section 
       constraint_id  -  The identifier of the constraint to deny

   Output Arguments:                                                 
        None

   Return Values:                     
      PRO_TK_NO_ERROR     -  The function successfully denied the constraint.
      PRO_TK_BAD_INPUTS   -  One or more of the input arguments are invalid.
      PRO_TK_BAD_CONTEXT  -  Intent Manager mode is used for the section
*/

extern ProError ProSectionConstraintsIdsGet(ProSection section,
					    ProIntlist *sec_constr_id_list,
                                            int *p_num_ids);
/*
   Purpose:
        Returns the array of section constraint identifiers.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        sec_constr_id_list - The returned array of section constraint
                            identifiers.
                            Release the memory using <b>ProArrayFree()</b>.
        p_num_ids         - The size of the returned list.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionSubsectionActiveIndexGet(ProSection section,
                                                   int *p_active_subsec);
/*
   Purpose:
        Returns the index of the currently active subsection.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        p_active_subsec - The index of the active subsection.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

*/

extern ProError ProSectionSubsectionToggle(ProSection section,
					   int *p_active_subsec);
/*
   Purpose:
        Activates a subsequent subsection or adds an empty one.
        Returns the index of the activated subsection.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        p_active_subsec - The index of the activated subsection.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

*/

extern ProError ProSectionSubsectionEntityIdsGet(ProSection section,
						 ProIntlist *p_id_list,
                                                 int *p_num_ids);
/*
   Purpose:
        Returns an array of valid section entity identifiers restricted to
        the currently active subsection.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        p_id_list - The array of identifiers. The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionSubsectionCount(ProSection section,
					  int *p_num_subsec);
/*
   Purpose:
        Returns the number of subsections.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        p_num_subsec - The number of subsections.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

*/

extern ProError ProSectionSubsectionStartGet(
				    ProSection section,
				    int *p_start_ent_id,
				    ProSectionPointType *p_start_ent_pnt_type);
/*
   Purpose:
        Returns the vertex in the subsection that hosts the start point,
	and the subsection contour orientation.
        
   Input Arguments:
        section   - The section.

   Output Arguments:
        p_start_ent_id       - The id of the host entity of the start point.
        p_start_ent_pnt_type - The end of the host entity where the start point
	                       is attached (pointing towards the other end).

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

*/

extern ProError ProSectionSubsectionStartSet(
				      ProSection section,
				      int start_ent_id,
				      ProSectionPointType start_ent_pnt_type);
/*
   Purpose:
        Specifies the vertex in the subsection that will host the start point,
	and the subsection contour orientation.
        
   Input Arguments:
        section            - The section.
        start_ent_id       - The id of the host entity of the start point.
        start_ent_pnt_type - The end of the host entity where the start point
	                     will be attached (pointing towards the other end).

   Output Arguments:
        none

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

*/

extern ProError ProSectionSubsectionBlendVertexSet(
				        ProSection section,
				        int host_ent_id,
				        ProSectionPointType host_ent_pnt_type,
				        int *p_vertex_ent_id);
/*
   Purpose:
        Specifies the vertex in the subsection that will host a blend vertex.
        
   Input Arguments:
        section           - The section.
        host_ent_id       - The id of the host entity of the blend vertex.
        host_ent_pnt_type - The end of the host entity where the blend vertex
	                    will be attached.

   Output Arguments:
        p_vertex_ent_id   - The id of the created blend vertex entity.

   Return Values:
        PRO_TK_NO_ERROR       - The function successfully retrieved the
                                information.
        PRO_TK_GENERAL_ERROR  - A general error occurred and the function
                                failed.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.

*/

extern ProError ProSectionEntityUseEdge (ProSection section,
					 ProSelection ref_edge,
					 int *r_ent_id);
/* 
   Purpose:
        Adds an entity to the specified section creating it from projection of 
   an edge of a solid.  Simulates behavior of 
                 Sketcher/Geom Tools/Use Edge/Sel Edge
   sketcher command.

   Input Arguments:
        section        - The section 
        ref_edge       - Referenced edge from which to create the entity.

   Output Arguments:
        r_ent_id       - The assigned identifier of created entity (may be NULL)

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully added the entity.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

*/

extern ProError ProSectionEntityUseEdgeLoop (ProSection section,
					     ProSelection ref_geom,
					     ProSelection ref_edge,
					     ProIntlist *p_id_list,
					     int *p_num_ids);
/* 
   Purpose:
        Adds loop of entities to the specified section creating them from
   projections of bounding edges of a solid model surface.  Simulates
   behavior of
                 Sketcher/Geom Tools/Use Edge/Sel Loop
   sketcher command.

   Input Arguments:
        section   - The section 
        ref_geom  - Referenced surface from whose contour the loop of 
                    entities should be created     
        ref_edge  - Edge belonging to the contour of the surface.

   Output Arguments:
        p_id_list - The array of identifiers. The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully added the entity.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityUseEdgeChain (ProSection section,
					      ProSelection ref_geom,
					      ProSelection ref_edge1,
					      ProSelection ref_edge2,
					      ProSelection ref_vertex,
					      ProIntlist *p_id_list,
					      int *p_num_ids);
/* 
   Purpose:
        Adds chain of entities to the specified section creating them from
   projections of a portion of a bounding contour of a solid model surface.
   Simulates behavior of "Sketcher/Geom Tools/Use Edge/Sel Chain" sketcher
   command.  The chain is defined by specifying the surface, two edges which
   delimit the chain and a vertex at the chain end (to select one of two
   possible chains connecting the two edges).

   Input Arguments:
        section    - The section 
        ref_geom   - Referenced surface from whose contour the chain of 
                     entities should be created.
        ref_edge1  - First edge delimiting the chain.
        ref_edge2  - Second edge delimiting the chain.
        ref_vertex - Vertex at the end of the chain.

   Output Arguments:
        p_id_list - The array of identifiers of entities added. 
                    The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully added the entity.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityUseCurveLoop(ProSection section,
					     ProSelection ref_ent,
					     ProIntlist *p_id_list,
					     int *p_num_ids);
/* 
   Purpose:
        Adds loop of entities to the specified section creating them
   from projections of 3D curve segments (datum curve, IGES, or pipe
   segments can be selected) .  Simulates behavior of
                 Sketcher/Geom Tools/Use Edge/Sel Loop
   sketcher command.

   Input Arguments:
        section   - The section 
        ref_ent   - Referenced curve segment belonging to the contour from which 
                    the loop of entities should be created     

   Output Arguments:
        p_id_list - The array of identifiers. The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully added the entity.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityUseCurveChain (ProSection section,
					       ProSelection ref_ent1,
					       ProSelection ref_ent2,
					       ProSelection ref_vertex,
					       ProIntlist *p_id_list,
					       int *p_num_ids);
/* 
   Purpose:
        Adds chain of entities to the specified section creating them
   from projections of 3D curve segments (datum curve, IGES, or pipe
   segments can be selected) .  Simulates behavior of
                 Sketcher/Geom Tools/Use Edge/Sel Loop
   sketcher command.

   Input Arguments:
        section    - The section 
        ref_ent1   - First referenced curve segment belonging to the
                     contour from which the loop of entities should be
                     created (start of the chain)
        ref_ent2   - Second referenced curve segment (end of the chain)
        ref_vertex - Vertex at the end of the chain.

   Output Arguments:
        p_id_list - The array of identifiers. The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory.
        p_num_ids - The size of the <i>p_id_list</i> array.

   Return Values:
        PRO_TK_NO_ERROR      - The function successfully added the entity.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityUseOffset (ProSection section,
                                           ProSelection ref_sel,
                                           double offset_val,
                                           int *p_dim_id,
                                           int **p_id_list,
                                           int *p_num_ids);
/* 
   Purpose:
        Adds an entity to the specified section creating it at an offset distance
        from projection :
          of an edge of a solid;
          of 3D curve segment (datum curve or pipe segments can be selected).

        It simulates the behavior of Sketcher/Edge/Offset/... command.

   Input Arguments:
        section        - The section.
        ref_sel        - Referenced object from which to create the entity.
        offset_val     - Offset distance.

   Output Arguments:
        p_dim_id  - Offset dimension ID. May be NULL.
        p_id_list - The array of identifiers. The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory. May be NULL.
        p_num_ids - The size of the <i>p_id_list</i> array. May be NULL.


   Return Values:
        PRO_TK_NO_ERROR      - Successfully added the entity with the offset value.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityUseOffsetChain (ProSection section,
                                                ProSelection ref_sel1,
                                                ProSelection ref_sel2,
                                                ProSelection ref_vertex,
                                                double offset_val,
                                                int *p_dim_id,
                                                int **p_id_list,
                                                int *p_num_ids);
/* 
   Purpose:
        Adds chain of entities to the specified section and create them at an
        offset distance from the projection:
          of an edges of a solid;
          of 3D curve segments (datum curve or pipe segments can be selected).

        The chain is defined by specifying the two edges or 3D curves which delimit
        the chain and a vertex at the chain end (to select one of two possible
        chains connecting selections).

        It simulates the behavior of Sketcher/Edge/Offset/... command. 

   Input Arguments:
        section    - The section.
        ref_sel1   - First object delimiting the chain.
        ref_sel2   - Second object delimiting the chain.
        ref_vertex - Vertex at the end of the chain.
        offset_val - Offset distance.

   Output Arguments:
        p_dim_id  - Offset dimension ID. May be NULL.
        p_id_list - The array of identifiers of entities added. 
                    The function allocates the
                    memory for this argument. Call the function
                    <b>ProArrayFree()</b> to release the memory. May be NULL.
        p_num_ids - The size of the <i>p_id_list</i> array. May be NULL.

   Return Values:
        PRO_TK_NO_ERROR      - Successfully added the entity with the offset value.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionEntityUseOffsetLoop (ProSection section,
                                               ProSelection ref_sel1,
                                               ProSelection ref_sel2,
                                               double offset_val,
                                               int *p_dim_id,
                                               int **p_id_list,
                                               int *p_num_ids);
/* 
   Purpose:
        Adds loop of entities to the specified section creating them at an offset distance from
   projections of:
     bounding edges of a solid model surface;
     3D curve segments.
     
     It simulates the behavior of Sketcher/Edge/Offset/... command.

   Input Arguments:
        section    - The section.
        ref_sel1   - First edge belonging to the contour of the surface or 3D curve segment. 
        ref_sel2   - Second edge belonging to the contour of the surface or NULL for
                     3D curve segment as ref_sel1.
        offset_val - Offset distance.

   Output Arguments:
        p_dim_id   - Offset dimension ID. May be NULL.
        p_id_list  - The array of identifiers. The function allocates the
                     memory for this argument. Call the function
                     <b>ProArrayFree()</b> to release the memory. May be NULL.
        p_num_ids  - The size of the <i>p_id_list</i> array. May be NULL.

   Return Values:
        PRO_TK_NO_ERROR      - Successfully added the entity with the offset value.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.

   See Also:
        ProArrayFree()
*/

extern ProError ProSectionShapeGet( ProSection section, 
				    ProSectionShape *shape );

/* 
   Purpose:
        Determines the current shape of a given section. The shape of
   the section can be a controlling factor in permitting or preventing 
   some types of features to use the section.

   Input Arguments: 
        section - The section handle. The section must be regenerated
	          before executing this check.

   Output Arguments: 
        shape   - The number and type of loops in the section.

   Return Values:
        PRO_TK_NO_ERROR         - The function succeeded.
        PRO_TK_BAD_INPUTS       - One or more arguments is invalid.
        PRO_TK_GENERAL_ERROR    - The section was not regenerated
*/

extern ProError ProSectionEntityReferenceGet( ProSection section, int ent_id,
					      ProSelection* reference);
/*
   Purpose:
        Return the geometry referenced by a projection entity.

   Input Arguments:
        section   - The section handle.
        ent_id    - The projected entity id.

   Output Arguments:
        reference - The 3D geometric entity referenced by the projected entity.

   Return Values:
        PRO_TK_NO_ERROR         - The function succeeded.
        PRO_TK_BAD_INPUTS       - One or more arguments is invalid.
        PRO_TK_INVALID_TYPE     - The entity is not a projected entity.
*/

extern ProError ProSectionIsActive( ProBoolean* is_active );
/*
   Purpose:
        Identifies if sketcher is currently active. This works even if the current model is a part or an assembly.

   Input Arguments:
        none

   Output Arguments:
        is_active - PRO_B_TRUE if sketcher is currently active, PRO_B_FALSE otherwise.

   Return Values:
        PRO_TK_NO_ERROR         - The function succeeded.
        PRO_TK_BAD_INPUTS       - One or more arguments is invalid.
*/

extern ProError ProSectionEntityIsConstruction(ProSection handle,
                                               int entity_id,
                                               ProBoolean *is_construction);
/*
    Purpose: checks if the section entity is construction type

    Input Arguments:
        handle - The section handle
        entity_id - The section entity identifier.

    Output Arguments:
        is_construction - PRO_B_TRUE, if the section entity is construction type

    Return Values:
        PRO_TK_NO_ERROR - The function completed successfully.
        PRO_TK_BAD_INPUTS - Invalid input argument(s).

*/


extern ProError ProSectionEntityConstructionSet(ProSection handle,
                                                int entity_id,
                                                ProBoolean construction);
/*
    Purpose: 
        Marks the section entity to be construction type

    Input Arguments:
        handle - The section handle
        entity_id - The entity identifier.
        construction - PRO_B_TRUE, if the section entity is to set construction type entity

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function completed successfully.
        PRO_TK_BAD_INPUTS - Invalid input argument(s).

*/

extern ProError ProSectionEntityIntersectionGet( ProSection     section,
                                                 int            ent_id_1,
                                                 int            ent_id_2,
                                                 Pro2dPnt       **intersect_pnts );
/*
    Purpose: 
        Get the intersection points of the two entities.

    Input Arguments:
        section - The section
        ent_id_1 - The first entity 
        ent_id_2 - The second entity

    Output Arguments:
        intersect_pnts - ProArray of points. 
                         Will be allocated by function.
                         Release the memory using <b>ProArrayFree()</b>.

    Return Values:
        PRO_TK_NO_ERROR - The function successfully executed.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

*/

extern ProError ProSectionEntityParamEval( ProSection  section,
                                           int         ent_id,
                                           Pro2dPnt    xy_point,
                                           double      *p_param );
/*
    Purpose: 
        Finds the corresponding normalized parameter value on the curve, 
	given the XY point. Its value ranges from 0 to 1.

    Input Arguments:
        section  - The section
        ent_id - The entity identifier
        xy_point - The XY point. The point does not necessarily have to lie 
                    on the entity. If the point is off the entity, the function 
                    finds the closest point.

    Output Arguments:
        p_param - The corresponding normalized parameter on the entity geometry.

    Return Values:
        PRO_TK_NO_ERROR - The function successfully evaluated the point.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_E_AMBIGUOUS - More than one param value found. 
*/

extern ProError ProSectionEntityGetSelected( ProSection          handle,
                                             int                 entity_id,
                                             ProSectionPointType pnt_type,
                                             Pro2dPnt            pnt,
                                             int                 idx_pnt,
                                             ProSelection        *p_ref_entity );
/*
    Purpose: 
        Get the selection reference of the entity 

    Input Arguments:
        handle - The section handle
        entity_id - The entity identifier
        pnt_type - selected point type.
        pnt - location on the entity geometry (may be NULL)
        idx_pnt - Index of interpolation spline point 
                (PRO_VALUE_UNUSED if not a spline entity)
                Used interpolation point instead pnt in creation ProSelection 
                if idx_pnt is set up.                  

    Output Arguments:
        p_ref_entity - The allocated selection object.

    Return Values:
        PRO_TK_NO_ERROR - The function successfully executed.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

*/

extern ProError ProSectionEntityCorner( ProSection      section,
                                        ProSelection    sel_1,
                                        ProSelection    sel_2 );
/*
    Purpose: 
        Trim or extend the entity.

    Input Arguments:
        section  -   The section
        sel_1 - The first selection entity
        sel_2 - The second selection entity

    Output Arguments:
        N/A

    Return Values:
        PRO_TK_NO_ERROR - The function successfully executed.
        PRO_TK_NOT_VALID - Trim or extend is not possible
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.

*/

extern ProError ProSectionEntityDivide( ProSection      section,
                                        ProSelection    sel,
                                        int             *new_id );
/*
    Purpose: 
        Divide the entity into two pieces.
	Please note that some dimensions and constraints may be 
	deleted as a result of this function.

    Input Arguments:
        section  -   The section
        sel - The selection entity to divide

    Output Arguments:
        new_id   - The new entity identifier created after division

    Return Values:
        PRO_TK_NO_ERROR - The function successfully divided the entity.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_E_AMBIGUOUS - Elaborate more during the implementation 
*/

extern ProError ProSectionConstraintCreate( ProSection          handle,
                                            ProSelection        *ref_ent,
                                            int                 num_ents,
                                            ProConstraintType   constr_type,
                                            int                 *constr_id );

/*
    Purpose: 
        Create the constraints with the entities in the specified section to each other.
<p>
	This function should only be called if Intent Manager mode is used
	for the section (see ProSectionIntentManagerModeSet())

    Input Arguments:
        handle - The section handle
        ref_ent - An array of selection of entities
        num_ents - Number of selection entities. 
        constr_type - The constraint type.

    Output Arguments:
        constr_id - Created constraint id
        
    Return Values:
        PRO_TK_NO_ERROR     - The function successfully creates the constraints.
        PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.
	PRO_TK_BAD_CONTEXT  - Intent Manager mode is not used for the section
        PRO_TK_E_FOUND      - The constraint exists.
        PRO_TK_INVALID_TYPE - Constraint creation is not possible with the give input.
*/

extern ProError ProSectionConstraintDelete( ProSection section, 
                                            int constraint_id );
/*
    Purpose: 
        Delete the specified section constraint.

    Input Arguments:
        section - The section
        constraint_id - The identifier of the constraint to delete

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function successfully deleted the constraint.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
        PRO_TK_INVALID_TYPE - Constraint could not be deleted
*/

extern ProError ProSectionIntentManagerModeGet( ProSection section, 
						ProBoolean *intent_manager_is_used );
/*  
    Purpose: 
        Check if Intent Manager mode is used for the specified
        section for Creo Parametric TOOLKIT functions.

    Input Arguments:
        section - The section handle

    Output Arguments:
        intent_manager_is_used - PRO_B_TRUE if Intent Manager is used

    Return Values:
        PRO_TK_NO_ERROR   - Success
        PRO_TK_BAD_INPUTS - Invalid section
*/

extern ProError ProSectionIntentManagerModeSet( ProSection section, 
						ProBoolean use_intent_manager );
/*  
    Purpose: 
        Switches Intent Manager mode on/off for the specified
        section for Creo Parametric TOOLKIT functions.
        Section conversion invoking section resolve is done here.
<p>
        By default Intent Manager is off.

    Input Arguments:
        section - The section handle
	use_intent_manager - PRO_B_TRUE to switch Intent Manager mode on

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR   - Success
        PRO_TK_BAD_INPUTS - Invalid section
	PRO_TK_GENERAL_ERROR - Section can not be converted
*/

extern ProError ProSectionActiveGet( ProSection *p_section );
/*  
    Purpose: 
        Returns a <b>copy</b> of the current active sketcher section.
	Note that if Intent Manager mode is supposed to be used for this section,
	the call ProSectionIntentManagerModeSet( section, PRO_B_TRUE )
	must follow the call to ProSectionActiveGet().

    Input Arguments:
        none

    Output Arguments:
        p_section - copy of the current sketcher section

    Return Values:
        PRO_TK_NO_ERROR      - success
	PRO_TK_BAD_INPUTS    - invalid argument
        PRO_TK_GENERAL_ERROR - section can not be returned
*/

extern ProError ProSectionActiveSet( ProSection section );
/*  
    Purpose: 
        Set a <b>copy</b> of the section to be a current active sketcher section. 
	Caller is responsible for the section validity.
	This section will also be added to Undo/Redo stack.
	The section must be solved or to be in Intent Manager mode.

    Input Arguments:
        section - section that its copy will be set as the active section

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success
	PRO_TK_BAD_INPUTS    - Invalid section
        PRO_TK_GENERAL_ERROR - Section can not be set active
*/

PRO_END_C_DECLS

#endif
