#ifndef PROPIPING_H
#define PROPIPING_H

#include <ProParamval.h>
#include <ProObjects.h>
#include <ProSelection.h>
#include <ProAsmcomp.h>
#include <ProAsmcomppath.h>
#include <ProSelection.h>



PRO_BEGIN_C_DECLS

/*##############################################################################
  Functions/Data Definition for Linestock
##############################################################################*/

typedef enum 
{
  PROLNSTKPRM_SINGLE,
  PROLNSTKPRM_MULTIPLE
  
} ProLnstkParamType;

typedef struct pro_lnstk
{
  ProName            name;
  ProAssembly        owner;
  
} ProLnstk;


typedef struct _pro_lnstk_param_memb_
{
  ProName            name;
  ProParamvalue      value;
  
} ProLnstkParamMemb;


typedef struct _pro_lnstk_param_
{
  ProName            name;
  ProLnstkParamType  param_type;
  union {
           ProParamvalue         value;
           ProLnstkParamMemb    *members;
        } lnstk_param_value;
} ProLnstkParam;


/*--------------------------------------------------------------------*\
  Values of enumerable line stock parameters
\*--------------------------------------------------------------------*/

/* Values of Section Type parameter */

typedef enum 
{
  PROLNSTKPIPESECT_HOLLOW,                     /*   Hollow     */
  PROLNSTKPIPESECT_SOLID                       /*   Solid      */
} ProLnstkPipeSection;


/* Values of X Section parameter    */ 
 
typedef enum 
{
  PROLNSTKPIPEXSECT_CIRCULAR,                   /*   Circular    */
  PROLNSTKPIPEXSECT_RECTANGULAR                 /*   Rectangular */
} ProLnstkPipeXSection;
 

/* Values of Shape Type parameter   */

typedef enum 
{
  PROLNSTKPIPESHAPE_STRT,                      /*   Straight    */ 
  PROLNSTKPIPESHAPE_FLXBL                      /*   Flexible    */
} ProLnstkPipeShape;
 

/* Values of Corner Type parameter  */      

typedef enum 
{
  PROLNSTKPIPECRNR_FIT,                         /*  Fitting     */
  PROLNSTKPIPECRNR_MCUT,                        /*  Miter Cut   */
  PROLNSTKPIPECRNR_BEND                         /*  Bend        */
} ProLnstkPipeCrnrType;

/*-----------------------------------------------------------------------*\
    Functions to manage linestocks.
\*-----------------------------------------------------------------------*/


extern ProError ProAssemblyLnstksCollect( ProAssembly assy,
					  ProLnstk  **pro_lnstks);

/*
  Purpose: Collect linestocks in specified assembly

   Input Arguments:
    assy                - Assembly owner of the linestock

   Output Arguments:
    pro_lnstks          - ProArray of linestock's handles.
                             Function allocates memory for this argument.
                             Use ProArrayFree to free it.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully initialize linestock.
      PRO_TK_BAD_INPUTS    - The some arguments is invalid.
      PRO_TK_E_NOT_FOUND   - No linestock found.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProPipelineLnstkGet( ProFeature *pipeline,
				     ProLnstk   *pro_lnstk);

/*
   Purpose: Get linestock assigned to pipeline feature.

   Input Arguments:
    pipeline              - The pipeline feature.

   Output Arguments:
    pro_lnstk             - The linestock handle.

   Return Values:
      PRO_TK_NO_ERROR      - The linestock assigned to pipeline found.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProPipelineLnstkSet( ProFeature *pipeline,
				     ProLnstk   *pro_lnstk);

/*
   Purpose: Assign linestock to pipeline feature.

   Input Arguments:
    pipeline              - The pipeline feature.
    pro_lnstk             - The linestock handle.

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The linestock successfully assigned to pipeline.
      PRO_TK_NO_CHANGE     - The linestock is already set to pipeline.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND   - New line stock does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProLnstkParametersCollect( ProLnstk       *lnstk,
					   ProLnstkParam **p_params);

/*
  Purpose: Retrieves parameters of specified linestock

   Input Arguments:
    lnstk                  - Handle of linestock.

   Output Arguments:
    p_params               - ProArray of parameters.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND   - Lnestock with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProLnstkParametersSet( ProLnstk      *lnstk,
				       ProLnstkParam *p_params);

/*
  Purpose: Set parameters for specified linestock

   Input Arguments:
    lnstk                  - Handle of linestock.
    p_params               - ProArray of new parameters.

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully sets new parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND   - Linestock with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProLnstkCreate( ProAssembly assy,
				ProName     w_name );

/*
  Purpose: Creates new linestock

   Input Arguments:
    assy                  - The handle of linestocks assembly owner.
    w_name                - The linestock name.

   Output Arguments:
      None     

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully creates new linestock.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_FOUND       - Linestock with this name already exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProLnstkParameterAdd( ProLnstk      *lnstk,
				      ProLnstkParam *p_param );

/*
  Purpose: Add parameter in specified linestock

   Input Arguments:
    lnstk                  - Handle of linestock.
    p_param                - Parameter handle.

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully add parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND   - Linestock with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProLnstkParameterDelete( ProLnstk *lnstk,
					 ProName   w_param_name);

/*
  Purpose: Deletes parameter in specified linestock

   Input Arguments:
    lnstk                  - Handle of linestock.
    w_param_name           - Name of retrieved parameter
    
   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully delete parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_E_NOT_FOUND   - Linestock with this name does not exist.
      PRO_TK_GENERAL_ERROR - Other error.
*/

/*##############################################################################
  Functions/Data Definition for Pipeline feature
##############################################################################*/

typedef enum
{
  PROPIPINGSPEC_RIGID,
  PROPIPINGSPEC_HOSE      /* not supported in creo2.0 */

} ProPipingSpecType;


typedef struct pro_piping_rigid_spec_params__
{
  ProName schedule;  /* SCHEDULE from specdb. */

} ProPipingRigidSpecParams;

typedef struct pro_piping_hose_spec_params_
{
  ProName pressure;  

} ProPipingHoseSpecParams;

typedef struct _PipeSpecParams_
{
  ProName spec;                           /* pipe specification               */
  ProName size;                           /* pipe size from specdb            */
  ProName grade;                          /* material code (grade)            */
  ProName category;                       /* pipe category (PIPE/FLEX_PIPE)   */

  ProPipingSpecType catalog_type;                /* PROPIPINGSPEC_RIGID/HOSE  */
  union {
           ProPipingRigidSpecParams rigid_params;
           ProPipingHoseSpecParams  hose_params;
        } t;
 
} ProPipingSpecParams;

extern ProError ProPipelineSpecDrivenCreate( ProSelection model,
                                             ProPipingSpecParams spec_params,
                                             ProName Mnemonic,
                                             ProName number,
                                             ProName insulation, 
                                             ProBool CreateSubAsm, 
                                             ProName SubAsmName, 
                                             ProSelection csys_reference,
                                             ProLnstk *pro_lnstk, 
                                             ProFeature *pro_pipeline,
                                             ProSelection *pro_new_model );
/*
   Purpose: Creates a linestock feature according to the spec parameters, and
            a pipeline feature with those spec params, referencing the linestock.
            The pipeline features name would be generated according to the spec
            params and config option "pipeline_label_format".
            The linestock features name would be generated according to the 
            spec params.

   Input Arguments:
       model          -    The model where the pipeline will be create in.
                           Must be a spec driven model or under confic option 
                           piping_design_method spec driven.

       spec_params    -    The parameters according to which the pipeline and
                           linestock features will be created.

       Mnemonic       -    May be NULL or empty. If NULL then the default 
                           mnemonic will be used, according to the spec params.
                           (use an empty string to specify that no mnemonic 
                           shall be used).

       number         -    May be NULL or empty.

       insulation     -    May be NULL or empty. If NULL then the default 
                           insulation will be used, according to the spec params.
                           (use an empty string to specify that no insulation
                           shall be used).

       CreateSubAsm   -    If PRO_B_TRUE then the sub assembly will be created
                           for that pipeline (using a template model defined in
                           config option pipeline_start_assembly_name).

       SubAsmName     -    The name of the sub assembly. 
                           Used if CreateSubAsm is TRUE.
                           May be NULL. If NULL or empty, then the name of the 
                           sub assembly will be generated according to the 
                           config option pipeline_assembly_name_format.

       csys_reference -    A csys in the given model, to which the sub assembly 
                           will reference. 
                           May be NULL. If NULL then the first csys of the model
                           will be used for placement reference.


   Output Arguments:
       pro_lnstk      -    The linestock created during this process.

       pro_pipeline   -    The pipeline created during this process.

       pro_new_model  -    The sub assembly created during this process 
                           (if CreateSubAsm is TRUE).


   Return Values:

  PRO_TK_NO_ERROR      - The function successfully creates the pipeline, the
                         linestock, and the sub assembly (when relevant).

  PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.

  PRO_TK_E_FOUND       - Pipeline with those exact params already exists or
                         Sub assembly with the given name or the generated 
                         names exists.

  PRO_TK_E_NOT_FOUND     One of the spec parameters was not found. Some examples:
                         SPEC not found in pipe_spec_directory_file.
                         SIZE not found in the related auto select file.
                         A specific message will be prompt to Creo window.

  PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProPipelineCreateFromXML( ProSelection model, 
                                          ProPath xml_file,
                                          ProName pipeline_label,
                                          ProBool insulation, 
                                          ProBool CreateSubAsm, 
                                          ProName SubAsmName, 
                                          ProSelection csys_reference,
                                          ProLnstk *pro_lnstk,
                                          ProFeature *pro_pipeline, 
                                          ProSelection *pro_new_model );
/*
   Purpose: Given XML file and a pipeline label, creates linestock feature and
            pipeline feature, according to the spec params taken from the XML
            for the specific label.
            
            The pipeline features name would be generated according to the spec
            params and config option "pipeline_label_format".
            The linestock features name would be generated according to the 
            spec params.

   Input Arguments:
       model          -    The model where the pipeline will be create in.
                           Must be a spec driven model or under confic option 
                           piping_design_method spec driven.

       xml_file       -    A path to XML file for schematic driven pipelines.

       pipeline_label -    A label of a pipeline for the above XML file.
                           The spec parameters will be filled from the XML file
                           for that label: SPEC, SIZE, SCHEDULE, MNEMONIC, 
                           NUMBER and INSULATION. Category is PIPE. 
                           GRADE (Material code) will be taken from the related
                           spec according to the other spec params.

       insulation     -    if TRUE then insualtion will be created for the
                           pipeline according to parameter INSULATION taken form
                           the XML file.

       CreateSubAsm   -    If PRO_B_TRUE then the sub assembly will be created
                           for that pipeline (using a template model defined in
                           config option pipeline_start_assembly_name).

       SubAsmName     -    The name of the sub assembly. 
                           Used if CreateSubAsm is TRUE.
                           May be NULL. If NULL or empty, then the name of the 
                           sub assembly will be generated according to the 
                           config option pipeline_assembly_name_format.

       csys_reference -    A csys in the given model, to which the sub assembly 
                           will reference. 
                           May be NULL. If NULL then the first csys of the model
                           will be used for placement reference.


   Output Arguments:
       pro_lnstk      -    The linestock created during this process.

       pro_pipeline   -    The pipeline created during this process.

       pro_new_model  -    The sub assembly created during this process 
                           (if CreateSubAsm is TRUE).


   Return Values:

  PRO_TK_NO_ERROR      - The function successfully creates the pipeline, the
                         linestock, and the sub assembly (when relevant).

  PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.

  PRO_TK_INVALID_FILE  - XML file was not found or invalid.

  PRO_TK_E_NOT_FOUND     The given label was not found in the XML file OR
                         one of the spec parameters was not found. Some examples:
                         spec is not found in pipe_spec_directory_file.
                         size is not found in the related auto select file.
                         A specific message will be prompt to Creo window.

  PRO_TK_E_FOUND       - Pipeline with those exact params already exists or
                         Sub assembly with the given name or the generated 
                         names exists.

  PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProPipelineCreate ( ProSelection model,
                                    ProLnstk    *lnstk,
                                    ProName      pipeline_name,                                    
                                    ProFeature  *pro_pipeline);
/*
   Purpose: Creates a non spec driven pipeline feature. 

   The feature will be created under the given model, with the given 
   name pipeline_name, referencing pro_lnstk.
   
   Input Arguments:
     model               - the model where the pipeline will be create in.
                           must be a non spec driven model.
     lnstk               - the linestocl to which the pipeline will reference.
	                       must belong to the input model.
     pipeline_name       - the name of the pipeline.
	 
   Output Arguments:						   
     pro_pipeline        - the newly created pipeline feature.
	 
   Return Values:
     PRO_TK_NO_ERROR      - The function successfully creates the pipeline.
     PRO_TK_BAD_INPUTS      One or more of the arguments are invalid 
	      (Model is invalid OR the linestocks owner is different than model).
     PRO_TK_E_NOT_FOUND     Linestock was not found for the specific ProLnstk 
     	                    data (owner and name).
     PRO_TK_INVALID_NAME  - Pipeline with this name already exist.
     PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProPipelineParametersCollect( ProFeature    *pipeline,
                                              ProLnstkParam **p_params );
/*
  Purpose: Retrieves parameters of specified pipeline.

   Input Arguments:
    pipeline               - Handle of pipeline feature.

   Output Arguments:
    p_params               - ProArray of parameters.
                             The function allocates memory for these arguments.
                             To free it, call the function ProArrayFree.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/


extern ProError ProPipelineParameterAdd( ProFeature    *pipeline,
                                         ProLnstkParam *p_param );
/*
  Purpose: Add parameter in specified pipeline.

   Input Arguments:
    pipeline               - Handle of pipeline feature.
    p_param                - Parameter handle.

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully add parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/


extern ProError ProPipelineParameterDelete( ProFeature    *pipeline,
                                            ProName        param_name );
/*
  Purpose: Deletes parameter in specified pipeline.

   Input Arguments:
    pipeline               - Handle of pipeline feature.
    param_name             - Name of retrieved parameter

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully delete parameter.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/

extern ProError ProPipelineParametersSet( ProFeature    *pipeline,
                                          ProLnstkParam *p_params );

/*
  Purpose: Set parameters for specified pipeline.

   Input Arguments:
    pipeline               - Handle of pipeline feature.
    p_params               - ProArray of new parameters.

   Output Arguments:
    None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully sets new parameters.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - Other error.
*/


/*##############################################################################
  Functions/Data Definition for Pipe Network Building/Visiting/Data Retrieving
##############################################################################*/

/* Pipe Network terminology and structure
-----------------------------------------

Hierarchy of items...

Network contains a list of
    Extension contains a list of
        Member can be
            Terminator contains one
                Feature
                or
                nothing
            or
            Series contains a list of
                Object can be
                    Segment
                    or
                    Fitting
            or
            Juntion contains one
                Object can be 
                    Fitting
                    or
                    Stubin

Pipeline is set of interconnecting pipes and fitments.

A Pipeline feature is a feature which names the pipeline,
    and to which all the other features in a pipeline
    refer, as a way to show their grouping. It does not
    contain any geometry of its own.
  
Network is a data structure which contains references
    to the pipline objects, structured to show their
    connectivity and sequence in relation to the flow. A pipeline
    consists of a main extension, plus other extensions which
    branch from it, then others which branch from those, and
    so on recursively

Extension is a non-branching sequence of pipeline members,
    which terminates at open ends (i.e. no further pipeline items
    attached)non-open ends (i.e. equipment nozzles or other
    pipelines) or junctions.
    At a branch (or Junction), pipes are grouped into
    extensions such that the extension which continues
    across the branch has a continuous direction of
    flow, and, if that criterion leaves a choice, has
    the smallest change of direction
    possible for that branch. Other pipes which join
    that branch then form the end points of other
    extensions.

Member (of an extension) is a terminator or a series or a junction.

Terminator is the open or non-open ends of the pipeline.

Series is a non-branching sequence of pipeline objects.

Junction is a fitting or a stubin which represents
    a part which joins three or more pipe segments,

Object is a Segment or a Fitting or a Stubin or a Selection or a Group.

Segment is a section of pipe, either straight, or
    arced in which case it is manufactured by taking
    a straight section of tube and bending it.

Fitting is a component that connects with pipe segments,
    e.g. to form a corner where space does not allow a
    bent pipe segment, or to represent an item such as
    a valve.

Stubin is a datum point which joints three or more series.

Selection is a feature that is normally at the termination of the pipeline.

Group is a set of fittings that are inserted as one component, such as vent. */

/*##############################################################################
  Data Definition
##############################################################################*/

typedef struct PipeNetworkInfo *ProPnetwork;
typedef struct PExtension      *ProPextension;
typedef struct PMember         *ProPmember;
typedef struct PSeries         *ProPseries;
typedef struct PJunction       *ProPjunction;
typedef struct PObject         *ProPobject;
typedef struct PSegment        *ProPsegment;
typedef struct PFitting        *ProPfitting;
typedef struct PStubin         *ProPstubin;
typedef struct PTerminator     *ProPterminator;
typedef struct PSelection      *ProPselection;
typedef struct PGroup          *ProPgroup;

typedef enum
{
  PROPFLOWDIRECTION_UNKNOWN = 0,
  PROPFLOWDIRECTION_NORMAL  = 1,  /* Member sequence is the same as flow dir  */
  PROPFLOWDIRECTION_REVERSE = 2   /* Member sequence is opposite to the flow  */
} ProPflowDirection;

typedef enum
{
    PROPMEMBERTYPE_UNKNOWN    = 0,
    PROPMEMBERTYPE_SERIES     = 1,
    PROPMEMBERTYPE_JUNCTION   = 2,
    PROPMEMBERTYPE_TERMINATOR = 3
}ProPmemberType;

typedef enum
{
    PROPOBJECTTYPE_UNKNOWN   = 0,
    PROPOBJECTTYPE_SEGMENT   = 1,
    PROPOBJECTTYPE_FITTING   = 2,
    PROPOBJECTTYPE_STUBIN    = 3,
    PROPOBJECTTYPE_SELECTION = 4,
    PROPOBJECTTYPE_GROUP     = 5
} ProPobjectType;

typedef enum
{
    PROPSEGMENTTYPE_UNKNOWN     = 0,
    PROPSEGMENTTYPE_STRAIGHT   = 1, /* Straight pipe segment without bend     */
    PROPSEGMENTTYPE_BEND       = 2  /* Pipe segment with bend(s)              */
}ProPsegmentType;

typedef enum
{
    PROPENTITYTYPE_UNKNOWN    = 0,
    PROPENTITYTYPE_STRAIGHT   = 1, /* Straight pipe entity                    */
    PROPENTITYTYPE_BEND       = 2, /* Bend     pipe entity                    */
    PROPENTITYTYPE_MITER      = 3  /* Miter    pipe entity                    */
}ProPentityType;

typedef enum
{
  PROPTERMINATORTYPE_UNKNOWN = 0,
  PROPTERMINATORTYPE_IN      = 1,   /* Flow is in to this terminator          */
  PROPTERMINATORTYPE_OUT     = 2    /* Flow is out from this terminator       */
}ProPterminatorType;

/*##############################################################################
  Function Definition
##############################################################################*/

extern ProError ProPipelineNetworkEval(
    ProFeature *pipeline,
    ProPnetwork *network);
/*
   Purpose:     Evaluates the network defined by the
		specified pipeline feature. This is first
		step in evaluating the geometry and other
		properties of a pipeline.

   Input Arguments:
      pipeline      - The feature handle of the pipeline feature

   Output Arguments:
      network	    -   The handle of the network structure. The
			handle is an opaque pointer to a structure
			which is accessed by functions starting with
			ProPnetwork.
			The data in the underlying data structure is allocated
			by the function and should be freed when no
			longer needed by calling ProPnetworkFree().

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT - The feature was not a pipeline.
      PRO_TK_NO_LICENSE  - No Pro/PIPING license is available.
*/

/*============================================================================*/
extern ProError ProPnetworkFree(
    ProPnetwork network);

/*
   Purpose:     Frees the structure underlying a pipeline network.

   Input Arguments:
      network		- The network

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPnetworkLabelGet(
    ProPnetwork network,
    ProLine label);

/*
   Purpose:     Outputs the label for a pipeline network

   Input Arguments:
      network           - The pipeline network

   Output Arguments:
      label		- The label

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPnetworkSizeGet(
    ProPnetwork network,
    ProLine size);
/*
   Purpose:     Gets the size indicated in the label of the specified
        pipeline network

   Input Arguments:
      network		- The pipeline network.

   Output Arguments:
      size		- The size string

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPnetworkSpecGet(
    ProPnetwork network,
    ProLine spec);

/*
   Purpose:     Gets the specification indicated in the label of the specified
		pipeline network

   Input Arguments:
      network		- The pipeline network.

   Output Arguments:
      spec		- The specification string

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
typedef ProError (*ProPextensionVisitAction)(
    ProPextension extension,
    ProError status,
    ProAppData data);

/*
   Purpose:  This is the generic visit action function
	 for visiting a pipeline extension

   Input Arguments:
       extension -  The pipeline extension
       status   -  The status from the filter function
       data -  The application data passed to the visit function 

   Output Arguments:
       None

   Return Values:
     PRO_TK_NO_ERROR - Continue visiting items
     Other	     - Do not visit any further items.
*/

/*============================================================================*/
typedef ProError (*ProPextensionFilterAction)(
    ProPextension extension,
    ProAppData data);

/*
   Purpose:  This is the generic filter action function
	 for visiting a pipeline extension

   Input Arguments:
       extension -  The pipeline extension
       data -  The application data passed to the visit function 

   Output Arguments:
       None

   Return Values:
     PRO_TK_CONTINUE - Skip the call to the action function for this
			item, but continue with visiting later items.
     Other	     - Call the action function for this item with
			this value as the status input argument.
*/

/*============================================================================*/
extern ProError ProPnetworkExtensionVisit(
    ProPnetwork network,
    ProPextensionVisitAction visit_action,
    ProPextensionFilterAction filter_action, 
    ProAppData data);

/*
   Purpose:     The visit function for visiting the extensions
		in a pipeline network.

   Input Arguments:
      network		- The network
      visit_action	- The visit action function
      filter_action	- The filter action function. If NULL, 
                          all extensions in a pipeline network
                          are visited using the action function.
      data		- Application data being passed to
		          filter and action functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_E_NOT_FOUND - No extensions
*/

/*============================================================================*/
extern ProError ProPextensionFlowGet(
    ProPextension extension,
    ProPflowDirection *flow);

/*
   Purpose:     Outputs the flow direction of the specified pipe extension

   Input Arguments:
      extension		- The extension

   Output Arguments:
      flow		- The flow direction

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
typedef ProError (*ProPmemberVisitAction)(
    ProPmember member,
    ProError status,
    ProAppData data);

/*
   Purpose:  This is the generic visit action function
	 for visiting a pipeline extension member

   Input Arguments:
       member	-  The pipeline extension member
       status   -  The status from the filter function
       data     -  The application data passed to the visit function 

   Output Arguments:
       None

   Return Values:
     PRO_TK_NO_ERROR - Continue visiting items
     Other	     - Do not visit any further items.
*/

/*============================================================================*/
typedef ProError (*ProPmemberFilterAction)(
    ProPmember member,                                                
    ProAppData data);

/*
   Purpose:  This is the generic filter action function
	 for visiting a pipeline extension member 

   Input Arguments:
       member	-  The pipeline extension member
       data     -  The application data passed to the visit function 

   Output Arguments:
       None

   Return Values:
     PRO_TK_CONTINUE - Skip the call to the action function for this
			item, but continue with visiting later items.
     Other	     - Call the action function for this item with
			this value as the status input argument.
*/

/*============================================================================*/
extern ProError ProPextensionMemberVisit(
    ProPextension extension,
    ProPmemberVisitAction visit_action,
    ProPmemberFilterAction filter_action,
    ProAppData data);

/*
   Purpose:     The visit function for visiting the members
		in a pipeline extension.

   Input Arguments:
      extension		- The extension
      visit_action	- The visit action function
      filter_action	- The filter action function. If NULL, 
                          all members in a pipeline extension 
                          are visited using the action function. 
      data		- Application data to pass to the
			  filter and action functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_E_NOT_FOUND - No members
*/

/*============================================================================*/
extern ProError ProPmemberTypeGet(
    ProPmember member,
    ProPmemberType *type);

/*
   Purpose:     Outputs the type of the specified pipeline extension member

   Input Arguments:
      member	- The extension member

   Output Arguments:
      type		- The type of the extension member

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPmemberSeriesGet(
    ProPmember member,
    ProPseries *series);

/*
   Purpose:     Outputs the series of the specified pipeline extension member

   Input Arguments:
      member	- The extension member

   Output Arguments:
      series	- The series

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT - The member was not of type series.
*/

/*============================================================================*/
extern ProError ProPmemberJunctionGet(
    ProPmember member,
    ProPjunction *junction);

/*
   Purpose:     Outputs the junction of the specified pipeline extension member

   Input Arguments:
      member	- The extension member

   Output Arguments:
      junction	- The junction

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT - The member was not of type junction.
*/

/*============================================================================*/
extern ProError ProPmemberTerminatorGet(
    ProPmember member,
    ProPterminator *terminator);

/*
   Purpose:     Outputs the terminator of the specified pipeline
        extension member

   Input Arguments:
      member	- The extension member

   Output Arguments:
      terminator	- The terminator

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT - The member was not of type terminator.
*/

/*============================================================================*/
extern ProError ProPterminatorTypeGet(
    ProPterminator terminator,
    ProPterminatorType *type);

/*
   Purpose:     Outputs the type of the specified pipeline terminator

   Input Arguments:
      terminator	- The terminator

   Output Arguments:
      type		- The type of the terminator

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
typedef ProError (*ProPobjectVisitAction)(
    ProPobject object,
    ProError status,
    ProAppData data);

/*
   Purpose:  This is the generic visit action function
	 for visiting pipeline objects

   Input Arguments:
       object	-  The pipeline object
       status   -  The status from the filter function
       data	-  The application data passed to the visit function 

   Output Arguments:
       None

   Return Values:
     PRO_TK_NO_ERROR - Continue visiting items
     Other	     - Do not visit any further items.
*/

/*============================================================================*/
typedef ProError (*ProPobjectFilterAction)(
    ProPobject object,
    ProAppData data);

/*
   Purpose:  This is the generic filter action function
	 for visiting pipeline objects

   Input Arguments:
       object	-  The pipeline object
       data	-  The application data passed to the visit function 

   Output Arguments:
       None

   Return Values:
     PRO_TK_CONTINUE - Skip the call to the action function for this
			item, but continue with visiting later items.
     Other	     - Call the action function for this item with
			this value as the status input argument.
*/

/*============================================================================*/
extern ProError ProPseriesObjectVisit(
    ProPseries series,
    ProPobjectVisitAction visit_action,
    ProPobjectFilterAction filter_action,
    ProAppData data);
/*
   Purpose:     The visit function for visiting the objects
		in a pipeline series.

   Input Arguments:
      series		- The series
      visit_action	- The visit action function
      filter_action	- The filter action function. If NULL,
                          all objects in a pipeline series are
                          visited using the action function.
      data		- Application data to be passed to the
			  filter and action functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_E_NOT_FOUND - No objects
*/

/*============================================================================*/
extern ProError ProPjunctionObjectGet(
    ProPjunction junction,
    ProPobject *object);
/*
   Purpose:     Outputs the object contained by a
		 pipeline junction.

   Input Arguments:
      junction		- The junction

   Output Arguments:
      object		- The object contained by the junction

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPterminatorObjectGet(
    ProPterminator terminator,
    ProPobject *object);

/*
   Purpose:     Outputs the object contained by a
		 pipeline terminator.

   Input Arguments:
      terminator		- The terminator

   Output Arguments:
      object		- The object contained by the terminator

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPobjectTypeGet(
    ProPobject object,
    ProPobjectType *type);

/*
   Purpose:     Outputs the type of the specified pipeline object.

   Input Arguments:
      object		- The pipeline object.

   Output Arguments:
      type		- The object type.     

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPobjectSegmentGet(
    ProPobject object,
    ProPsegment *segment);

/*
   Purpose:     Outputs the segment object for a
		pipeline object whose type is segment.

   Input Arguments:
      object		- The pipeline object.

   Output Arguments:
      segment		- The segment

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT
*/

/*============================================================================*/
extern ProError ProPobjectFittingGet(
    ProPobject object,
    ProPfitting *fitting);

/*
   Purpose:     Outputs the fitting object for a
		pipeline object whose type is fitting.

   Input Arguments:
      object		- The pipeline object.

   Output Arguments:
      fitting		- The fitting

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT
*/

/*============================================================================*/
extern ProError ProPobjectStubinGet(
    ProPobject object,
    ProPstubin *stubin);

/*
   Purpose:     Outputs the stubin object for a
		pipeline object whose type is stubin.

   Input Arguments:
      object		- The pipeline object.

   Output Arguments:
      stubin		- The stubin

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT
*/

/*============================================================================*/
extern ProError ProPobjectSelectionGet(
    ProPobject object,
    ProPselection *selection);

/*
   Purpose:     Outputs the selection object for a
		pipeline object whose type is selection.

   Input Arguments:
      object		- The pipeline object.

   Output Arguments:
      selection		- The selection

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT
*/

/*============================================================================*/
extern ProError ProPsegmentTypeGet(
    ProPsegment segment,
    ProPsegmentType *type);

/*
   Purpose:     Outputs the type of a pipeline segment

   Input Arguments:
      segment		- The segment

   Output Arguments:
      type		- The segment type (straight or bend)

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPsegmentLinestockGet(
    ProPsegment segment,
    ProLnstk    *linestock);
/*
   Purpose:     Outputs the linestock for a specified
		pipeline segment

   Input Arguments:
      segment		- The segment

   Output Arguments:
      linestock		- The linestock

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_BAD_CONTEXT
*/

/*============================================================================*/
extern ProError ProPsegmentLengthGet(
    ProPsegment segment,
    double *length);
/*
   Purpose:     Outputs the length of a specified
		pipeline segment

   Input Arguments:
      segment		- The segment

   Output Arguments:
      length		- The length

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPsegmentCurvesGet(
    ProPsegment segment,
    ProCurve **curves);
/*
   Purpose:     Outputs an array of curves which describe the
		geometry of a specified pipeline segment

   Input Arguments:
      segment		- The segment

   Output Arguments:
      curves		- A ProArray of the curves. Access the
			curve geometry using ProCurveDataGet().
			The array is allocated by the function,
			and should be freed after use by calling
			ProArrayFree(). The curves are
			opaque pointers to data inside Creo Parametric.

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_E_NOT_FOUND - No curves
*/

/*============================================================================*/
extern ProError ProPstubinPointGet(
    ProPstubin stubin,
    ProPoint *point);
/*
   Purpose:     Outputs the point entity which holds the stubin branch

   Input Arguments:
      stubin		- The stubin

   Output Arguments:
      point		- A ProPoint of the stubin.

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
      PRO_TK_E_NOT_FOUND - No point
*/

/*============================================================================*/
extern ProError ProPfittingAsmcompGet(
    ProPfitting fitting,
    ProAsmcomp *asmcomp);
/*
   Purpose:     Outputs the assembly component that
		forms the specified pipeline fitting.

   Input Arguments:
      fitting		- The fitting

   Output Arguments:
      asmcomp		- The assembly component

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPselectionSelectionGet(
    ProPselection selection,
    ProSelection *pro_selection);

/*
   Purpose:     Outputs the ProSelection of the specified ProPselection.

   Input Arguments:
      selection		- The ProPselection

   Output Arguments:
      pro_selection		- The ProSelection. Its memory are allocated by
            the function and should be freed using ProSelectionFree().

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPjunctionSeriesIdsGet(
    ProPjunction junction,
    int **in_series_ids,
    int **out_series_ids);

/*
   Purpose:     Outputs ids of the series connect to at the specified junction

   Input Arguments:
      junction		- The junction

   Output Arguments:
      in_series_ids	- A ProArray of ids of the series that flow in to this
            junction. If NULL is given, no in series ids will be returned.
            The ProArray is allocated by the function and should be
			freed using	ProArrayFree().
      out_series_ids - A ProArray of ids of the series that flow out from this
            junction. If NULL is given, no out series ids will be returned.
            The ProArray is allocated by the function and should be
			freed using	ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPseriesIdGet( 
    ProPseries series, 
    int *series_id );

/*
   Purpose:     Outputs the series id of the specified series. Series id is
        a sequential number that is used to identify a series.

   Input Arguments:
      series	- The series 

   Output Arguments:
      series_id	- The series id

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProSelectionPipelineGet(
    ProSelection selection,
    ProFeature *pipeline);

/*
   Purpose:     Outputs the pipeline feature representing
		the pipeline to which the specified pipeline
		selection belongs.

   Input Arguments:
      selection		- The selection. It must be a piping routing feature or 
        the pipeline feature itself.

   Output Arguments:
      pipeline		- The pipeline feature

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

/*============================================================================*/
extern ProError ProPobjectPipelineGet(
    ProSelection selection,
    ProFeature *pipeline);
/*
  
   Purpose:     Outputs the pipeline feature representing
		the pipeline to which the specified pipeline
		selection belongs.
 
  NOTE: This function has been replaced by ProSelectionPipelineGet(). Please
         do NOT use it, use ProSelectionPipelineGet() instead.
  
  Input Arguments:
      selection		- The selection

   Output Arguments:
      pipeline		- The pipeline feature

   Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

PRO_END_C_DECLS

#endif
