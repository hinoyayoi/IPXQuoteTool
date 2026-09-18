#ifndef PROANALYSIS_H
#define PROANALYSIS_H

#include <ProToolkit.h>
#include <ProCsysdata.h>
#include <ProObjects.h>
#include <ProParamval.h>
#include <ProQuiltdata.h>
#include <ProSelection.h>
#include <ProSurfacedata.h>



/*****************************************************************************

Element tree for creation of external analysis features using ProFeatureCreate():

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_ANALYSIS_NAME
     |
     |--PRO_E_ANALYSIS_TYPE
     |
     |--PRO_E_ANALYSIS_DEF

--------------------------------------------------------------------------------------------
Element Id                     Element Name   Data Type                Valid Values
--------------------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE             Feature Type   PRO_VALUE_TYPE_INT       PRO_FEAT_ANALYSIS
PRO_E_FEATURE_NAME             Feature Name   PRO_VALUE_TYPE_WSTRING   Name unique among features
PRO_E_ANALYSIS_TYPE            Analysis class PRO_VALUE_TYPE_INT       ProAnalysisClass
PRO_E_ANALYSIS_DEF             Analysis defn  PRO_VALUE_TYPE_POINTER   ProAnalysisDefinition
--------------------------------------------------------------------------------------------

\*****************************************************************************/

typedef enum analysis_class
{
    PRO_ANALYSIS_CLASS_EXTERNAL	= 8
} ProAnalysisClass;

typedef struct analysis_definition *ProAnalysisDefinition;

typedef enum
{
    PRO_ANALYSIS_SURFACE    = PRO_SURFACE,
    PRO_ANALYSIS_QUILT      = PRO_QUILT,
    PRO_ANALYSIS_CURVE      = PRO_CURVE,
    PRO_ANALYSIS_AXIS       = PRO_AXIS,
    PRO_ANALYSIS_DATUM_PLANE= PRO_DATUM_PLANE,
    PRO_ANALYSIS_CSYS       = PRO_CSYS,
    PRO_ANALYSIS_POINT      = PRO_POINT,
    PRO_ANALYSIS_COMP_CRV   = PRO_COMP_CRV
} ProAnalysisEntityType;

typedef enum
{
    PROANALYSIS_COMPUTE_OFF = 1 << 0
} ProAnalysisAttribute;

typedef struct  proAnalysisSrfData
     {
      ProEdgedata    *edge_data;
      ProSurfacedata *pro_surface;
     }ProAnalysisSrfData;

typedef union
{
    ProAnalysisSrfData    *surface;/* If type == PRO_ANALYSIS_SURFACE ||
					 type == PRO_ANALYSIS_DATUM_PLANE */
    ProQuiltdata          *quilt;  /* If type == PRO_ANALYSIS_QUILT */
    ProCurvedata          *curve;  /* If type == PRO_ANALYSIS_CURVE ||
					 type == PRO_ANALYSIS_AXIS ||
					 type == PRO_ANALYSIS_POINT ||
					 type == PRO_ANALYSIS_COMP_CRV */
    ProCsysdata           csys;    /* If type == PRO_ANALYSIS_CSYS */
} ProAnalysisEntity;

typedef struct analysis_geom
{  
    ProName name;		/* Name to be given to new entity in Creo Parametric */
    ProBoolean create;          /* TRUE = means created by default */
    ProAnalysisEntityType type;
    ProAnalysisEntity *shapes;  /* ProArray of entities of same
				 type, sharing same name root. 
				 Types supported at present :
					PRO_ANALYSIS_CURVE
					PRO_ANALYSIS_POINT
					PRO_ANALYSIS_COMP_CRV
					PRO_ANALYSIS_CSYS
					PRO_ANALYSIS_SURFCURVE
				 Must be set to NULL if not used.
				*/
} ProAnalysisGeomitem;

typedef struct analysis_param
{
    ProName	  name;
    ProBoolean    create; /* TRUE = means created by default */
    ProLine	  description;
    ProParamvalue *values;  /* ProArray of parameter values,
				sharing same name root. */
			    /* Only type PRO_PARAM_DOUBLE supported
							at present
			       Must be set to NULL if not used. */
} ProAnalysisParameter;

/*===========================================================================*/

PRO_BEGIN_C_DECLS


typedef ProError (*ProAnalysisUiAction)(ProAnalysis analysis);

/*
  Purpose: This is the notification function called at the start
	    of creation of an External Analysis, and is used
	    to ask the user for inputs necessary to define the
	    analysis.

            Set the notification by calling ProAnalysisTypeRegister.

  Input Arguments:
     analysis   -  The analysis being created

  Output Arguments:
     None

  Return Values:
      PRO_TK_NO_ERROR - The analysis feature was fully defined.
      PRO_TK_USER_ABORT - The user chose to abort from the feature
			  create. If this value is returned, Creo Parametric
			  will not create the feature.

*/

typedef ProError (*ProAnalysisDimsAction)(ProAnalysis analysis,
					  double **dims);

/*
  Purpose: This notification function is called during the
            creation of an External Analysis Feature, and is
            used to specify to Creo Parametric the values of
            dimensions that should be added to each new
            feature of that type. If the Creo Parametric TOOLKIT
            application needs to access the resulting
            dimensions of an Analysis Feature, it should
            do this using the regular Creo Parametric TOOLKIT
            functions for that purpose.
            The notification is set by calling
            ProAnalysisTypeRegister()

  Input Arguments:
     analysis   -  The analysis being created

  Output Arguments:
     dims       - Pointer to ProArray of dimension values

  Return Values:
      PRO_TK_NO_ERROR - The analysis feature was fully defined.
      PRO_TK_USER_ABORT - The user chose to abort from the feature
                        create. If this value is returned, Creo Parametric
                        will not create the feature.

*/

typedef ProError (*ProAnalysisComputecheckAction)(ProAnalysis analysis);

/*
  Purpose: This notification function is called at the start
	    of computation of an External Analysis, and is used
	    to tell Creo Parametric whether the analysis can be
	    computed.

	    Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being computed

  Output Arguments:
     None

  Return Values:
      PRO_TK_NO_ERROR - The analysis can be computed.
      other           - The analysis can not be computed.

*/

typedef ProError (*ProAnalysisComputeAction)(ProAnalysis analysis);

/*
  Purpose: This is the notification function that performs
	   the computation of an External Analysis.

           Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being computed 

  Output Arguments:
     None

  Return Values:
     Creo Parametric ignores the return value.

*/

typedef ProError (*ProAnalysisDisplayAction)(ProAnalysis analysis);

/*
  Purpose: This notification function is called after
	    computation of an External Analysis, and
	    should be used to add any items to the
	    Creo Parametric display (for example by using
	    3d display lists) to show the geometrical
	    result of the analysis computation.

            Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being computed

  Output Arguments:
     None

  Return Values:
     Creo Parametric ignores the return value.

*/

typedef ProError (*ProAnalysisOutputAction)(ProAnalysis analysis,
                                            ProLine **lines);

/*
  Purpose: This notification function is called after
	    computation of an External Analysis, and
	    is used by the Creo Parametric TOOLKIT application
	    to provide text information which
	    is to displayed in the Analysis dialog
	    to show the result of the computation.

            Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being computed

  Output Arguments:
     lines	- Pointer to ProArray of lines of text,
                  allocated and freed by Creo Parametric.

  Return Values:
      Creo Parametric ignores the return value.

*/

typedef ProError (*ProAnalysisSavecheckAction)(ProAnalysis analysis);

/*
  Purpose: This notification function is called after
	    a request to save the analysis, and is
	    used to tell Creo Parametric whether the
	    analysis can be saved.

            Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being saved.

  Output Arguments:
    None

  Return Values:
      PRO_TK_NO_ERROR - The analysis can be saved.
      Other	      - The analysis can not be saved.

*/

typedef ProError (*ProAnalysisInfosaveAction)(ProAnalysis  analysis,
                                              ProFeature   *feature,
                                              ProSelection **references);

/*
  Purpose: This notification function is called after
            a request to save the analysis, and is
            used to tell Creo Parametric what references
	    to geometric entities the analysis contains.

            Set the notification by calling ProAnalysisTypeRegister().


  Input Arguments:
     analysis   -  The analysis being saved.
     feature    -  The feature that owns the analysis.
			(If the Analysis is not part of an explicit
			Creo Parametric Analysis feature, this argument is
			nevertheless set and refers to an internal
			feature.)

  Output Arguments:
     references -  Pointer to ProArray of ProSelection
		    objects describing the entities
		    to be referenced by the analysis.
		    The array is allocated and freed by
		    Creo Parametric.

  Return Values:
      PRO_TK_NO_ERROR - The analysis can be saved.
      Other	      - The analysis can not be saved.

*/

typedef ProError (*ProAnalysisInfoallocAction)(ProAnalysis analysis);
/*
  Purpose: This notification function is called 
	    when a Creo Parametric model containing
	    an analysis is retrieved. It should
	    be used to allocate any special data
	    the Creo Parametric TOOLKIT application needs to
	    describe the analysis.

            Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being retrieved.

  Output Arguments:
     None

  Return Values:
      PRO_TK_NO_ERROR - The analysis feature was fully defined.
      PRO_TK_USER_ABORT - The user chose to abort from the feature
			create. If this value is returned, Creo Parametric
			will not create the feature.

*/

typedef ProError (*ProAnalysisInforetrieveAction)(ProAnalysis  analysis,
                                                  ProFeature   *feature,
                                                  ProSelection *references);

/*
  Purpose: This notification function is called 
	    when a Creo Parametric model containing
	    an analysis is retrieved, but after
	    the infoalloc_action function. It is
	    used to fill any special data structures
	    the application needs to describe the
	    analysis, using the list of references
	    supplied by Creo Parametric.

            Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis being retrieved.
     feature    -  The feature that owns the analysis.
                   If the Analysis is not part of an explicit
                   Creo Parametric Analysis feature, this argument is
                   nevertheless set and refers to an internal
                   feature.)
     references -  A ProArray of ProSelection structures
		   describing the references to geometry
		   entities that Creo Parametric has stored
		   with the analysis.

  Output Arguments:
     None

  Return Values:
     Creo Parametric ignores the return value.

*/

typedef ProError (*ProAnalysisInfocopyAction)(ProAnalysis from,
					                ProAnalysis to);

/*
  Purpose: This notification function is called 
	    when an existing external analysis feature is
	    copied by the Creo Parametric user. It gives the toolkit
	    application the opportunity to set up its
	    application data for the new feature, whether
	    by copying from the original feature, or by
	    any other means.

  Input Arguments:
     from       - The analysis in the feature being copied
     to 	- The analysis in the feature being created

  Output Arguments:
     None

  Return Values:
      The return value is ignored by Creo Parametric

*/

typedef ProError (*ProAnalysisInfofreeAction)(ProAnalysis analysis);

/*
  Purpose: This notification is called when the
	    analysis is no longer needed, and
	    the application's description of
	    it can be freed, for example
	    when the model is erased, or the
	    analysis is deleted.

            Set the notification by calling ProAnalysisTypeRegister().


  Input Arguments:
     analysis   -  The analysis

  Output Arguments:
     None

  Return Values:
      The return value is ignored by Creo Parametric
*/
 

typedef ProError (*ProAnalysisResultAction)(ProAnalysis         analysis,
                                           ProBoolean           names_only,
                                           ProAnalysisParameter **parameters,
                                           ProAnalysisGeomitem  **geometry);

/*
   Purpose: This notification is called during
	    creation or regeneration of an
	    Analysis Feature, to give Creo Parametric
	    the parameters and geometry items to
	    be created in that feature. It can be
	    called sometimes before the compute
	    callback, when Creo Parametric needs to
	    know which parameters and entities will
	    be created. In this case the arg
	    names_only will be true, and the output
	    arrays should contain the parameter
	    and entity names only.
	    
            Set the notification by calling ProAnalysisTypeRegister().

  Input Arguments:
     analysis   -  The analysis
    names_only  -  PRO_B_TRUE if only the parameter and entity names
                   are required.
  Output Arguments:
     parameters	- A ProArray of descriptions of feature parameters
                  to be created/modified on the analysis
                  feature. Allocated and freed by Creo Parametric.
     geometry   - A ProArray of sets of geometry items to be
                  added to the analysis feature.
                  Each time the analysis feature is
                  regenerated, geometry items which may
                  be referenced from later features
                  should be put in the same index of
                  the geometry array, so that Creo Parametric
                  can preserve the reference. A geometry
                  item that contains no geometry on a
                  particular call should be kept in the
                  array with a NULL geomitems pointer,
                  to maintain the sequence of the other items.
                  Creo Parametric allocates and frees the geometry array.

  Return Values:
      The return value is ignored by Creo Parametric
*/


extern ProError ProAnalysisInfoGet(ProAnalysis analysis,
                                   ProAppData  *info);
/*
  Purpose: Outputs the info structure for a specified analysis.

  Input Arguments:
     analysis   - The analysis

  Output Arguments:
     info       - The info

  Return Values:
    PRO_TK_NO_ERROR
    PRO_TK_BAD_INPUTS
*/

extern ProError ProAnalysisInfoSet(ProAnalysis analysis,
                                   ProAppData  info);
/*
  Purpose: Sets the info structure for a specified analysis.

  Input Arguments:
     analysis   - The analysis
     info       - The info

  Output Arguments:
     None

  Return Values:
    PRO_TK_NO_ERROR
    PRO_TK_BAD_INPUTS
*/

extern ProError ProAnalysisNameGet(ProAnalysis analysis,
                                   ProName     name);
/*
  Purpose: Gets the name of a specified analysis.

  Input Arguments:
     analysis   - The analysis

  Output Arguments:
     name       - The name

  Return Values:
    PRO_TK_NO_ERROR
    PRO_TK_BAD_INPUTS
*/
extern ProError ProAnalysisTypeGet(ProAnalysis analysis,
                                   ProName     type);
                                   
/*
  Purpose: Gets the type of a specified analysis

  Input Arguments:
     analysis   - The analysis

  Output Arguments:
     type       - The external application name

  Return Values:
    PRO_TK_NO_ERROR
    PRO_TK_BAD_INPUTS
*/
                                   
extern ProError ProAnalysisAttrSet( ProAnalysis analysis,
                                    ProAnalysisAttribute attribute,
                                    ProBoolean anlattrset);
/*
  Purpose: Sets or unsets the value of the specified analysis attribute.

  Input Arguments:
    analysis    - The analysis
    attribute   - The analysis attribute
    anlattrset         - Set or unset

  Output Arguments:
    None

  Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

extern ProError ProAnalysisAttrIsSet( ProAnalysis analysis,
                                      ProAnalysisAttribute attribute,
                                      ProBoolean *anlattrset);
/*
  Purpose: Outputs whether a specified analysis attribute is set.

  Input Arguments:
    analysis    - The analysis
    attribute   - The analysis attribute

  Output Arguments:
    anlattrset         - Set or unset

  Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS
*/

typedef struct analysis_funcs_data
{
    ProName                         type;
    ProAnalysisUiAction             ui_action;
    ProAnalysisDimsAction           dims_action;
    ProAnalysisInfoallocAction      infoalloc_action;
    ProAnalysisInfofreeAction       infofree_action;
    ProAnalysisComputecheckAction   compcheck_action;
    ProAnalysisComputeAction        compute_action;
    ProAnalysisDisplayAction        display_action;
    ProAnalysisOutputAction         output_action;
    ProAnalysisSavecheckAction      savecheck_action;
    ProAnalysisInfosaveAction       infosave_action;
    ProAnalysisInforetrieveAction   inforetrieve_action;
    ProAnalysisInfocopyAction       infocopy_action;
    ProAnalysisResultAction         result_action;
} ProAnalysisFuncsData;

extern ProError ProAnalysisTypeRegister(ProAnalysisFuncsData *data);
/*
  Purpose: Registers an external analysis type with Creo Parametric.
           Normally be called in user_initialize().

  Input Arguments:
     data   -  A description of the analysis type being registered.
               Contains the name of the analysis type and pointers
               to the callbacks used to implement it.

  Output Arguments:
     None

  Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_BAD_INPUTS

*/

extern ProError ProAnalysisDefnAlloc( ProName type,
				      ProAppData  info,
				      ProAnalysisDefinition *definition);
/*
  Purpose: Allocate and initialize memory for a
	    ProAnalysisDefinition object, as the value
	    of the PRO_E_ANALYSIS_DEF element in the feature
	    element tree.

  Input Arguments:
    type        - The type as registered by a call to
		  ProAnalysisTypeRegister()
    
    info        - Pointer to application data needed by the feature

  Output Arguments:
     definition	 - The resulting definition. Assign this value directly to
		   the element PRO_E_ANALYSIS_DEF in the element tree when
		   creating an external analysis feature.

  Return Values:
      PRO_TK_NO_ERROR
      PRO_TK_OUT_OF_MEMORY

*/

LIB_COREUTILS_API  ProError ProAnalysissrfdataAlloc (ProAnalysisSrfData **data);
/*

  Purpose: Allocates a ProAnalysisSrfData handle.

  Input Arguments:
    none

  Output Arguments:
    data        - The allocated handle.

  Return Values:
    PRO_TK_NO_ERROR       - The function succeeded.
    PRO_TK_OUT_OF_MEMORY  - No allocation done.
    PRO_TK_BAD_INPUTS     - Bad inputs.
    
*/


PRO_END_C_DECLS

#endif /* PROANALYSIS_H */
