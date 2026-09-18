#ifndef PROFEATURE_H
#define PROFEATURE_H

/* Creo Parametric TOOLKIT declarations for ProFeature-related actions */

#include <ProObjects.h>
#include <ProSelection.h>
#include <ProItemerr.h>
#include <ProElement.h>
#include <ProSection.h>
#include <ProAsmcomppath.h>
#include <ProVerstamp.h>
#include <ProDimension.h>
#include <ProFeatForm.h>

 

PRO_BEGIN_C_DECLS

typedef int ProFeattype;       /* See ProFeatType.h for the allowed types. */ 

typedef enum pro_feat_status
{
  PRO_FEAT_INVALID              = -1,  /* input was invalid                */
  PRO_FEAT_ACTIVE               =  0,  /* feature is active                */
  PRO_FEAT_INACTIVE             =  1,  /* feature is inactive              */
  PRO_FEAT_FAMTAB_SUPPRESSED    =  2,  /* feature is suppressed by family  */
                                       /* table functionality              */
  PRO_FEAT_SIMP_REP_SUPPRESSED  =  3,  /* feature is suppressed by         */
                                       /* simplified reps functionality    */
  PRO_FEAT_PROG_SUPPRESSED      =  4,  /* feature is suppressed by         */
                                       /* Pro/PROGRAM functionality        */
  PRO_FEAT_SUPPRESSED           =  5,  /* feature is suppressed            */
  PRO_FEAT_UNREGENERATED        =  6   /* feature is active but            */
                                       /* unregenerated                    */
} ProFeatStatus;

#define   PRO_FEAT_STAT_INVALID              0       /* input was invalid                 */
#define   PRO_FEAT_STAT_INACTIVE             (1<<0)  /* feature is inactive, if the bit 0 then active  */
#define   PRO_FEAT_STAT_ACTIVE               (1<<1)  /* feature is active                 */
#define   PRO_FEAT_STAT_FAMTAB_SUPPRESSED    (1<<2)  /* feature is suppressed by family   */
                                                     /* table functionality               */
#define   PRO_FEAT_STAT_SIMP_REP_SUPPRESSED  (1<<3)  /* feature is suppressed by          */
                                                     /* simplified reps functionality     */
#define   PRO_FEAT_STAT_PROG_SUPPRESSED      (1<<4)  /* feature is suppressed by          */
                                                      /* Pro/PROGRAM functionality        */
#define   PRO_FEAT_STAT_SUPPRESSED           (1<<5)   /* feature is suppressed            */
#define   PRO_FEAT_STAT_UNREGENERATED        (1<<6)   /* feature is active but            */
                                                      /* unregenerated                    */
#define   PRO_FEAT_STAT_FAILED               (1<<7)   /* Failed feature                   */
#define   PRO_FEAT_STAT_CHILD_OF_FAILED      (1<<8)   /* Child of failed feature          */
#define   PRO_FEAT_STAT_CHILD_OF_EXT_FAILED  (1<<9)   /* Child of external failed feature */


typedef enum pro_pattern_status
{
  PRO_PATTERN_INVALID           = -1,  /* input was invalid                */
  PRO_PATTERN_NONE              =  0,  /* not part of a pattern            */
  PRO_PATTERN_LEADER	        =  1,  /* regular pattern leader           */
  PRO_PATTERN_MEMBER            =  2,  /* regular pattern member           */
  PRO_PATTERN_HEADER            =  3   /* regular pattern header           */
} ProPatternStatus;

typedef enum pro_pattern_class
{
  PRO_FEAT_PATTERN              = 0,   /* request info from a feat pattern  */
  PRO_GROUP_PATTERN             = 1    /* request info from a group pattern */
} ProPatternClass;

typedef enum pro_pat_dir
{
  PRO_PAT_DIR_ONE               = 1,
  PRO_PAT_DIR_TWO               = 2
} ProPatDir;

typedef enum pro_group_status
{
  PRO_GROUP_INVALID             = -1,  /* input was invalid                */
  PRO_GROUP_NONE                =  0,  /* not part of a group              */
  PRO_GROUP_MEMBER              =  1   /* is part of a group               */
} ProGroupStatus;

typedef enum pro_grppattern_status
{
  PRO_GRP_PATTERN_INVALID       = -1,  /* input was invalid                */
  PRO_GRP_PATTERN_NONE          =  0,  /* not part of a group pattern      */
  PRO_GRP_PATTERN_LEADER        =  1,  /* is group pattern leader          */
  PRO_GRP_PATTERN_MEMBER        =  2,  /* is group pattern member          */
  PRO_GRP_PATTERN_HEADER        =  3   /* is group pattern header          */
} ProGrppatternStatus;

typedef enum pro_feature_create_options
{
  PRO_FEAT_CR_NO_OPTS              = 0, /* no options                       */
  PRO_FEAT_CR_DEFINE_MISS_ELEMS    = 1, /* prompt user interface upon       */
                                        /* creation/redefinition if some    */
                                        /* of the required elements are     */
                                        /* missing                          */
                                            
  PRO_FEAT_CR_INCOMPLETE_FEAT      = 2, /* allow incomplete feature to be   */
                                        /* created                          */
  PRO_FEAT_CR_FIX_MODEL_ON_FAIL    = 3, /* if there is a feature failure    */
                                        /* then prompt fix model interface  */
  PRO_FEAT_CR_DO_NOT_DISPLAY       = 4, /* Do not redisplay model and model */
                                        /* tree after feature creation or   */
                                        /* redefinition.                    */
  PRO_FEAT_CR_CALLED_FROM_TK       = 5, /* Some features open for Toolkit,  */
                                        /* but still not open for UI        */
                                        /* pass check flag in availability  */
                                        /* function                         */
					/* ****INTERNAL only - Creo Parametric TOOLKIT  */
					/* users ignore                     */
  PRO_FEAT_CR_UNDO_IF_FAIL         = 6, /* do not create if failure occurs  */
					/* ****INTERNAL only - Creo Parametric TOOLKIT  */
					/* users ignore                     */
  PRO_FEAT_CR_ALLOW_CONFIRM        = 7  /* allows confirmation fail dialog  */
					/* ****INTERNAL only - Creo Parametric TOOLKIT  */
					/* users ignore                     */
} ProFeatureCreateOptions;

typedef enum pro_feat_elemtree_extract_opts
{
  PRO_FEAT_EXTRACT_NO_OPTS = 0          /* no options                       */

} ProFeatureElemtreeExtractOptions;

typedef enum pro_feature_delete_opts
{
  PRO_FEAT_DELETE_NO_OPTS          = 0,  /* delete/suppress features without */
                                         /* deleting/suppressing their       */
                                         /* dependent children features.     */
                                         /* Please note that this may result */
                                         /* in regeneration failures.        */
                                         /* PTC recommends using the option  */
                                         /* PRO_FEAT_DELETE_FIX or one of the*/
                                         /* CLIP options unless your         */
                                         /* application deals with the       */
                                         /* feature's dependent children     */
                                         /* in another way before            */
                                         /* regeneration takes place.        */
  PRO_FEAT_DELETE_CLIP             = 1,  /* delete/suppress features along   */
                                         /* with deleting/suppressing their  */
                                         /* dependent children features.     */
  PRO_FEAT_DELETE_FIX              = 2,  /* delete/suppress features without */
                                         /* deleting/suppressing their       */
                                         /* dependent children features.     */
                                         /* The fix model user interface     */
                                         /* will be prompted in case of      */
                                         /* regeneration failure.            */
  PRO_FEAT_DELETE_RELATION_DELETE  = 3,  /* delete relations with obsolete   */
                                         /* dimensions.                      */
  PRO_FEAT_DELETE_RELATION_COMMENT = 4,  /* change relations with obsolete   */
                                         /* dimensions into comments.        */
  PRO_FEAT_DELETE_CLIP_ALL         = 5,  /* delete/suppress features along   */
                                         /* with deleting/suppressing all    */
                                         /* the following features.          */
  PRO_FEAT_DELETE_INDIV_GP_MEMBERS = 6,  /* If this option is included,      */
                                         /* features to be deleted or        */
                                         /* suppressed, if they are members  */
                                         /* of groups, will be individually  */
                                         /* deleted out of the groups they   */
                                         /* belong to. If this option is not */
                                         /* included, the entire group       */
                                         /* containing the feature will be   */
                                         /* deleted.                         */
                                         /* For this option to work, option: */
                                         /* PRO_FEAT_DELETE_CLIP also has to */
                                         /* be supplied.                     */
  PRO_FEAT_DELETE_CLIP_INDIV_GP_MEMBERS = 7, /* If this option is included,  */
                                         /* children of features to be       */
                                         /* deleted or suppressed, if they   */
                                         /* are members of groups, will be   */
                                         /* individually deleted out of the  */
                                         /* groups they belong to. If this   */
                                         /* option is not included, the      */
                                         /* entire group containing the child*/
                                         /* will be deleted.                 */
                                         /* For this option to work, options:*/
                                         /* PRO_FEAT_DELETE_CLIP and         */
                                         /* PRO_FEAT_DELETE_INDIV_GP_MEMBERS */
                                         /* also have to be supplied.        */
  PRO_FEAT_DELETE_KEEP_EMBED_DATUMS = 8  /* This option will cause           */
                                         /* Creo Parametric to keep the embedded*/
                                         /* datums stored in a feature when  */
                                         /* using ProFeatureDelete() to      */
                                         /* delete the feature. If not used, */
                                         /* embedded datums will be deleted  */
                                         /* along with the parent feature.   */
} ProFeatureDeleteOptions;

typedef enum pro_feature_resume_opts
{
  PRO_FEAT_RESUME_NO_OPTS          = 0,  /* no options                       */
  PRO_FEAT_RESUME_INCLUDE_PARENTS  = 1,  /* suppressed parents of the feats  */
                                         /* to be resumed will also be       */
                                         /* resumed                          */
  PRO_FEAT_RESUME_ADD_TO_BUFFER    = 2   /* Add the resumed features to the 
					    selection buffer. 		     */
} ProFeatureResumeOptions;
     
typedef enum pro_featcopy_type
{
  PRO_FEATCOPY_NEWREFS  = 1,     /* feats were copied with new refs          */
  PRO_FEATCOPY_SAMEREFS = 2,     /* feats were copied with same refs         */
  PRO_FEATCOPY_MIRROR   = 3,     /* feats were mirrored                      */
  PRO_FEATCOPY_MOVE     = 4      /* feats were moved                         */
} ProFeatcopyType;

typedef enum
{
  PRO_USER_PARAM    =  0,
  PRO_DIM_PARAM     =  1,
  PRO_PATTERN_PARAM =  2,
  PRO_DIMTOL_PARAM  =  3,
  PRO_REFDIM_PARAM  =  4,
  PRO_ALL_PARAMS    =  5,
  PRO_GTOL_PARAM    =  6,
  PRO_SURFFIN_PARAM =  7
} ProParamType;

typedef enum pro_feat_copy_type
{
  PRO_FEATCOPY_NORMAL     = 1,  /* feat was copied by new or same refs  */
  PRO_FEATCOPY_BY_MIRROR  = 2,  /* feat was copied by mirroring         */
  PRO_FEATCOPY_BY_MOVE    = 3   /* feat was copied by moving            */
} ProFeatureCopyType;

typedef enum pro_feat_copy_dependency
{
  PRO_FEATCOPY_INDEPENDENT = 1, /* feat was copied independently */
  PRO_FEATCOPY_DEPENDENT   = 2  /* feat was copied dependently */
} ProFeatureCopyDependency;

typedef enum pro_surf_trans_type
{
   PRO_SURF_TRANS_TYPE_UNDEF       = 0,
   PRO_SURF_TRANS_TYPE_MIRROR      = 1, /*For Geom Mirror */
   PRO_SURF_TRANS_TYPE_MOVE        = 2, /*For Geom Move   */
   PRO_SURF_TRANS_TYPE_PART_MIRROR = 4 /* For Part Mirror */
} ProSurfTransType;


/*===========================================================================*/

extern ProError ProFeatureInit   (ProSolid     p_owner_handle, 
                                  int          feat_id, 
                                  ProFeature  *p_feat_handle);
/*
   Purpose: Initializes the <I>ProFeature</I> handle.

   Input Arguments:
      p_owner_handle    - The solid owner of the feature
      feat_id		- The feature identifier. Cannot be NULL

   Output Arguments:
      p_feat_handle     - The handle to initialize. Cannot be NULL

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NOT_EXIST  - Feature with such identifier does not exist.
*/

extern ProError ProFeatureSolidGet  (ProFeature  *p_feat_handle,
                                     ProSolid    *p_mdl_handle);
/*
   Purpose: Retrieves the solid owner of the feature.

   Input Arguments:
      p_feat_handle     - The feature handle

   Output Arguments:
      p_mdl_handle      - The solid owner of the feature

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the owner.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProFeatureCreate (ProSelection     model,
                                  ProElement       elemtree,
                                  ProFeatureCreateOptions options[],
                                  int              num_opts,
                                  ProFeature      *p_feature,
                                  ProErrorlist    *p_errors);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProFeatureWithoptionsCreate
    Purpose:
       Creates a feature from the element tree.
<p><b>
    NOTE:
<p></b>
       This function is deprecated. Use ProFeatureWithoptionsCreate() 
       with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.
	   Refer to the Creo Parametric Toolkit Release Notes for more information
	   on restrictions of using this function with Multi-CAD models.
 
    Input Arguments:
       model           - A selection object representing the part or assembly 
                         on which the feature is being created. The selection 
                         object must be constructed using a valid assembly
                         component path to the top level assembly if:
               <ul> 
                     <li>the feature contains external references to
                         geometry located outside of the solid model where it
                         will be constructed.
                     <li>or, the solid model in which the feature will be 
                         constructed is a member of the active Creo Parametric
                         assembly.
               </ul> 
       elemtree        - The element tree.
       options         - An array of user options.
       num_opts        - The number of options in the <I>options</I> array.
 
    Output Arguments:
       p_feature       - The feature handle.
       p_errors        - The list of errors.
 
    Return Values:
       PRO_TK_NO_ERROR      - The function successfully created
                              the feature.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The feature was not created. See p_errors for
			      the list of problems.
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/
 
extern ProError ProFeatureRedefine (ProAsmcomppath   *comp_path,
                                    ProFeature       *feature,
                                    ProElement        elemtree,
                                    ProFeatureCreateOptions options[],
                                    int               num_opts,
                                    ProErrorlist     *p_errors);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProFeatureWithoptionsRedefine
    Purpose:
        Redefines the feature from the element tree.
<p><b>
    NOTE:
<p></b>
        This function is deprecated. Use ProFeatureWithoptionsRedefine() 
        with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.
 
    Input Arguments:
        comp_path   - The path to the part to which the feature
                      belongs. This can be NULL when you are
                      redefining in Part mode, or when the feature
                      belongs to the top-level assembly. 
        feature     - The feature.
        elemtree    - The element tree.
        options     - An array of user options.
        num_opts    - The number of options.
 
    Output Arguments:
        p_errors    - The list of errors.
 
   Return Values:
        PRO_TK_NO_ERROR      -  The function successfully redefined
                                the feature.
        PRO_TK_BAD_INPUTS    -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProFeatureWithoptionsCreate (ProSelection             model,
                                             ProElement               elemtree,
                                             ProFeatureCreateOptions *options,
                                             int                      flags,
                                             ProFeature              *p_feature,
                                             ProErrorlist            *p_errors);
/*

    Purpose:
        Creates a feature from the element tree.

<p><b>
    NOTE:
<p></b>
	   Refer to the Creo Parametric Toolkit Release Notes for more information
	   on restrictions of using this function with Multi-CAD models.

    Input Arguments:
        model - A selection object representing the part or assembly
                on which the feature is being created. The selection
                object must be constructed using a valid assembly
                component path to the top level assembly if:

            <ul> 
               <li>the feature contains external references to
                   geometry located outside of the solid model where it
                   will be constructed.
               <li>or, the solid model in which the feature will be
                   constructed is a member of the active Creo Parametric
                   assembly.
            </ul>

        elemtree - The element tree.
        options  - A ProArray array of user options.
        flags    - The regeneration control flags. Pass as bitmask containing
                   one or more of the bit flags PRO_REGEN* defined in ProSolid.h

    Output Arguments:
        p_feature - The feature handle.
        p_errors  - The list of errors.

    Return Values:
        PRO_TK_NO_ERROR      - The function successfully created the feature.
        PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
        PRO_TK_GENERAL_ERROR - The feature was not created. See p_errors for
                               the list of problems.

*/


extern ProError ProFeatureWithoptionsRedefine (ProAsmcomppath        *comp_path,
                                               ProFeature            *feature,
                                               ProElement             elemtree,
                                               ProFeatureCreateOptions *options,
                                               int                    flags,
                                               ProErrorlist          *p_errors);
/*
    Purpose:
        Redefines the feature from the element tree.

    Input Arguments:
        comp_path - The path to the part to which the feature
                    belongs. This can be NULL when you are
                    redefining in Part mode, or when the feature
                    belongs to the top-level assembly.
        feature   - The feature.
        elemtree  - The element tree.
        options   - A ProArray of user options.
        flags     - The regeneration control flags. Pass as bitmask containing
                    one or more of the bit flags PRO_REGEN defined in ProSolid.h


    Output Arguments:
        p_errors  - The list of errors.

    Return Values:
        PRO_TK_NO_ERROR   - The function successfully redefined the feature.
        PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
*/

extern ProError ProFeatureElemtreeSet (ProAsmcomppath   *comp_path,
                                       ProFeature       *feature,
                                       ProElement        elem_tree,
                                       ProErrorlist     *p_errors);
/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProFeatureWithoptionsRedefine
    Purpose: <B>NOTE:</B>
<p>
             This function is <B>deprecated</B>.  It does not properly set up
	     the model to a point where it can accept a modification to
	     its feature element tree.  To properly modify a feature
	     tree, use ProFeatureWithoptionsRedefine.
<p>
             Assigns the information from the feature's definition 
             (<I>elem_tree</I>) into the feature database.
<p>
             

    Input Arguments:
        comp_path   - The path to the part to which the feature
                      belongs. This can be NULL when you are
                      redefining in Part mode, or when the feature
                      belongs to the top-level assembly.
        feature     - The feature whose database is to be altered.
        elem_tree   - The modified feature element tree to be assigned to
                      the feature.
 
    Output Arguments:
        p_errors    - The list of errors.
 
   Return Values:
        PRO_TK_NO_ERROR      -  The function successfully assigned the
                                specified data to the feature.
        PRO_TK_BAD_INPUTS    -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProFeatureDelete  (ProSolid    solid,
                                   int        *feat_ids,
	                           int         feat_count,
                                   ProFeatureDeleteOptions *delete_opts,
                                   int         num_opts);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProFeatureWithoptionsDelete
   Purpose:
      Deletes the specified features from the solid.
<p><b>
   NOTE:
<p></b>
      This function is deprecated. Use ProFeatureWithoptionsDelete() 
      with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.

   Input Arguments:
      solid          - The part or assembly to which the features belong
      feat_ids       - An array of feature identifiers to be deleted
      feat_count     - The size of the <I>feat_ids</I> array
      delete_opts    - An array of options for deleting features 
      num_opts       - The size of the <I>delete_opts</I> array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully deleted the features.
      PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
      PRO_TK_GENERAL_ERROR - The delete operation failed.
*/


extern ProError ProFeatureSuppress  (ProSolid    solid,
                                     int        *feat_ids,
				     int         feat_count, 
                                     ProFeatureDeleteOptions *suppress_opts,
                                     int         num_opts);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProFeatureWithoptionsSuppress
   Purpose:
      Suppresses the specified features in the solid.
<p><b>
   NOTE:
<p></b>
      This function is deprecated. Use ProFeatureWithoptionsSuppress() 
      with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.
 
   Input Arguments:
      solid             - The part or assembly to which the features belong
      feat_ids          - The array of feature identifiers to be suppressed
      feat_count	- The size of the <I>feat_ids</I> array
      suppress_opts     - The array of options for suppressing features 
      num_opts          - The size of the <I>suppress_opts</I> array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully suppressed the features.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
      PRO_TK_NOT_VALID     - One or more input features is not permitted
      			     to be suppressed.
      PRO_TK_GENERAL_ERROR - The suppress operation failed.
*/

extern ProError ProFeatureResume  (ProSolid    solid,
                                   int        *feat_ids,
                                   int         feat_count,
                                   ProFeatureResumeOptions  *resume_opts,
                                   int         num_opts);
/*
      DEPRECATED: Since Wildfire 5.0
      SUCCESSORS: ProFeatureWithoptionsResume
      Purpose: Resumes the specified features in the solid.
<p><b>
      NOTES:
<p></b>
      If the input feature array contains features that are already
      resumed, ProFeatureResume returns an error and does not resume
      suppressed features.

      This function is deprecated. Use ProFeatureWithoptionsResume() 
      with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.

   Input Arguments:
      solid             - The part or assembly to which the features belong
      feat_ids          - The array of feature identifiers to be resumed
      feat_count        - The size of the <I>feat_ids</I> array
      resume_opts       - The array of options for resuming features
      num_opts          - The size of the <I>resume_opts</I> array

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully resumed the features.
      PRO_TK_SUPP_PARENTS - Suppressed parents were found.
      PRO_TK_BAD_INPUTS   - One or more of the arguments are invalid.
*/

extern ProError ProFeatureWithoptionsDelete(ProSolid                 solid,
                                            int                     *feat_list,
                                            ProFeatureDeleteOptions *opts,
                                            int                      flags );
/*
   Purpose: Deletes the specified features from the solid.

   <p><b>NOTE:</b>Features of non-native models may or may not get deleted.

   Input Arguments:
       solid          -     The part or assembly to which the features belong
       feat_list      -     A ProArray of feature identifiers to be deleted
       opts           -     A ProArray of options for deleting features
       flags          -     The regeneration control flags. Pass as bitmask containing 
                            one or more of the bit flags PRO_REGEN* defined in ProSolid.h


   Output Arguments:
      None

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully deleted the features.
       PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
       PRO_TK_BAD_CONTEXT   - Invalid regeneration flag(s) for this function.
       PRO_TK_GENERAL_ERROR - The delete operation failed.
       
   See Also:
       ProArrayAlloc()
       ProArrayObjectAdd()
       ProArrayFree()    
*/

extern ProError ProFeatureWithoptionsSuppress(ProSolid                 solid,
                                              int                     *feat_list,
                                              ProFeatureDeleteOptions *opts,
                                              int                      flags );
/*
   Purpose: Suppresses the specified features in the solid.

   <p><b>NOTE:</b>Features of non-native models may or may not get suppressed.

   Input Arguments:
       solid          -     The part or assembly to which the features belong
       feat_list      -     The ProArray of feature identifiers to be suppressed
       opts           -     The ProArray of options for suppressing features
       flags          -     The regeneration control flags. Pass as bitmask containing 
       			    one or more of the bit flags PRO_REGEN* defined in ProSolid.h

   Output Arguments:
	None

   Return Values:
	PRO_TK_NO_ERROR       - The function successfully suppressed the features.
	PRO_TK_BAD_INPUTS     - One or more of the arguments are invalid.
        PRO_TK_BAD_CONTEXT    - Invalid regeneration flag(s) for this function.                        
       	PRO_TK_NOT_VALID      - One or more input features is not permitted to be suppressed.
       	PRO_TK_GENERAL_ERROR  - The suppress operation failed.
        
   See Also:
       ProArrayAlloc()
       ProArrayObjectAdd()
       ProArrayFree()    
        
*/

extern ProError ProFeatureWithoptionsReorder( ProSolid  pro_solid,
                                              int      *feat_ids,
                                              int       new_feat_num,
                                              int       flags );
/*
   Purpose: Reorders the supplied set of features such that the location of
            the first feature will be the <I>new_feat_num</I> after the
            reorder.

   Input Arguments:
	pro_solid    - The part or assembly that owns the features to be reordered.
	feat_ids     - The ProArray of feature identifiers that represents a
 			contiguous set of features in the model tree. If
			reordering a group, all the features in the group
			(including the Group Header feature) must be included
			in this array.
	new_feat_num - The intended location of the first feature in the
			specified set, upon reorder.
	flags 	     - The regeneration control flags. Pass as bitmask containing one or
		         more of the bit flags PRO_REGEN* defined in ProSolid.h

   Output Arguments:
	None

   Return Values:
	PRO_TK_NO_ERROR     - The function successfully reordered the features.
	PRO_TK_BAD_INPUTS   - The specified feature is invalid, or the location to
        		      which the reordering is requested is not valid.
        PRO_TK_BAD_CONTEXT  - Invalid regeneration flag(s) for this function.                            
                            
   See Also:
       ProArrayAlloc()
       ProArrayObjectAdd()
       ProArrayFree()    
                            
*/

extern ProError ProFeatureWithoptionsResume (ProSolid                 solid,
                                             int                     *feat_list,
                                             ProFeatureResumeOptions *opts,
                                             int                      flags);
/*
   Purpose: Resumes the specified features in the solid.

   <p><b>NOTE:</b>
   <p>  If the input feature array contains features that are already
        resumed, ProFeatureResume returns an error and does not resume
        suppressed features.

   Input Arguments:
	solid 	    - The part or assembly to which the features belong
	feat_list   - The ProArray of feature identifiers to be resumed
	opts        - The ProArray of options for resuming features
	flags       - The regeneration control flags. Bitmask containing one or more of
 		      the bit flags PRO_REGEN_* defined in ProSolid.h

   Output Arguments:
	None

   Return Values:
	PRO_TK_NO_ERROR     - The function successfully resumed the features.
	PRO_TK_SUPP_PARENTS - Suppressed parents were found.
	PRO_TK_BAD_INPUTS   - One or more of the arguments are invalid.
        PRO_TK_BAD_CONTEXT  - Invalid regeneration flag(s) for this function.        
        
   See Also:
       ProArrayAlloc()
       ProArrayObjectAdd()
       ProArrayFree()    
        
*/

extern ProError ProInsertmodeWithoptionsCancel (ProSolid   solid,
                                                ProBoolean resume,
                                                int        flags);
/*
   Purpose: Cancels insert mode in the specified part or assembly.

   Input Arguments:
	solid     -    The part or assembly.
	resume    -    Set this to PRO_B_TRUE if the suppressed features
 		 	are to be resumed once you cancel insert mode.
	flags     -    The regeneration control flags.Bitmask containing one or more of
			the bit flags PRO_REGEN_* defined in ProSolid.h


   Output Arguments:
	None

   Return Values:
	PRO_TK_NO_ERROR     -  The function successfully cancelled insert mode.
	PRO_TK_BAD_INPUTS   -  The specified feature is invalid.
        PRO_TK_BAD_CONTEXT  -  Invalid regeneration flag(s) for this function.        

   See Also:
	ProFeatureInsertModeActivate()
	ProInsertModeIsActive()
*/

extern ProError ProFeatureInsertmodeWithoptionsActivate(ProFeature *p_last_feat,
                                                        int         flags);
 /*
    Purpose:  Activates insert mode such that the specified feature
              becomes the last feature.
 
    Input Arguments:
       p_last_feat       - The feature that will be the last feature.
                           All the features after this feature will be detached.
                           Any features created after the activation of
                           insert mode will be created after this feature.
                           When you cancel the insert mode, the detached
                           features will be reappended at the end.
       flags             - The regeneration control flags. Pass as bitmask containing one
                           or more of the bit flags PRO_REGEN* defined in ProSolid.h


    Output Arguments:
       None
 
    Return Values:
       PRO_TK_NO_ERROR     - The function successfully activated insert mode.
       PRO_TK_BAD_INPUTS   - The specified feature is invalid.
       PRO_TK_BAD_CONTEXT  - Invalid regeneration flag(s) for this function.       
 
    See Also:
        ProInsertModeIsActive()
        ProInsertModeCancel()
 */
 
extern ProError ProFeatureGeomitemVisit    (ProFeature        *p_feat_handle,
                                            ProType            item_type,
	                                    ProGeomitemAction  action,
	                                    ProGeomitemFilter  filter,
		                            ProAppData         app_data);
/*
   Purpose: Visits all the geometry items created by the specified feature.
<p>
            The valid item types are as follows:
            <ul>
            <li>PRO_TYPE_UNUSED -- Visit all geometry.
            <li>PRO_SURFACE -- Visit surfaces only.
            <li>PRO_EDGE -- Visit edges only.
            <li>PRO_QUILT -- Visit quilts only.
            <li>PRO_CURVE -- Visit curves only.
            <li>PRO_POINT -- Visit points only.
            <li>PRO_AXIS -- Visit axes only.
            <li>PRO_CSYS -- Visit coordinate systems only.
            </ul>


   Input Arguments:
      p_feat_handle     - The feature handle.
      item_type		- The type of items to visit.
      action            - The visiting function. If it returns anything
                          other than PRO_TK_NO_ERROR, visiting stops. 
      filter            - The filter function. If NULL, all items
                          are visited using the action function. 
			  ProFeatureGeomitemVisit() will stop visiting if 
			  PRO_TK_GENERAL_ERROR is returned by the filter.
      app_data          - The application data passed to the filter
                          and visiting functions.
 
   Output Arguments:
      None
 
   Return Values:
 
      PRO_TK_NO_ERROR   - The function successfully visited all the items.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      Other             - The action function returned a value other than 
                          PRO_TK_NO_ERROR and visiting stopped.
*/

extern ProError ProFeatureParentsGet (ProFeature   *p_feat_handle,
				      int         **p_parents,
				      int          *p_count);

/*
  Purpose: Collects and returns all the parents of the specified feature.

  Input Arguments:
     p_feat_handle     - The feature handle.

  Output Arguments:
     p_parents         - An array of feature ids of parent features.
                         The function allocates the memory for this argument.
                         Use the function <B>ProArrayFree()</B> to free the
                         memory.
     p_count           - The size of the <I>p_parents</I> array.

  Return Values:
     PRO_TK_NO_ERROR   - The function successfully retrieved the parents.
     PRO_TK_BAD_INPUTS - The input argument is invalid.

  See Also:
     ProArrayFree()
*/    

  
extern ProError ProFeatureChildrenGet (ProFeature  *p_feat_handle,
                                       int        **p_children,
                                       int         *p_count); 

/*
   Purpose: Collects and returns all the children of the specified feature.
 
   Input Arguments:
      p_feat_handle      - The feature handle.
      
   Output Arguments:
      p_children         - An array of feature ids of children features.
                           The function allocates the memory for this 
                           argument. Use the function <B>ProArrayFree()</B> to
                           free the memory.  
      p_count            - The size of the <I>p_children</I> array.

   Return Values: 
      PRO_TK_NO_ERROR    - The function successfully retrieved the children.  
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProArrayFree()

*/

extern ProError ProFeatureStatusflagsGet  (ProFeature    *p_feat_handle,
				          unsigned int *p_status);
/*
   Purpose: Retrieves the bit status flag(s) of specified feature.
 
   Input Arguments:
      p_feat_handle      - The feature handle.
      
   Output Arguments:
      p_status           - The feature status bit flag(s).

   Return Values: 
      PRO_TK_NO_ERROR    - The function successfully feature status flag(s).  
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

*/

extern ProError ProFeatureStatusGet  (ProFeature    *p_feat_handle,
				      ProFeatStatus *p_status);
/*
   Purpose: Retrieves the status of the specified feature (active, suppressed,
            and so on).

   Input Arguments:
      p_feat_handle     - The feature for which to get the status 

   Output Arguments:
      p_status          - The status of the feature 

   Return Values:
      PRO_TK_NO_ERROR  	  -  The function successfully retrieved the
                             information. 
      PRO_TK_BAD_INPUTS   -  The input argument is invalid.
*/

extern ProError ProFeatureIsIncomplete (   ProFeature    *p_feat_handle,
                                           ProBoolean    *p_is_incomplete);
/*
   Purpose:  Determines whether the specified feature is incomplete.

   Input Arguments:
      p_feat_handle     - The feature to check for completeness.

   Output Arguments:
      p_is_incomplete   - If the feature is incomplete, this is PRO_B_TRUE.
                          Otherwise, this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR     -  The function successfully retrieved the
                             information.
      PRO_TK_BAD_INPUTS   -  The input argument is invalid.
*/

extern ProError ProFeaturePatternStatusGet ( ProFeature         *p_feat_handle,
                                             ProPatternStatus   *p_pattern_status);
/*
   Purpose: Retrieves the pattern status of the specified feature.

<p> 
            NOTE: 
<p>
            This function deals with simple patterns only.
 
   Input Arguments:
       p_feat_handle     -  The feature to process
      
   Output Arguments:
       p_pattern_status  -  The current pattern status of the feature
      
   Return Values: 
       PRO_TK_NO_ERROR   - The function successfully retrieved the 
                           information.  
       PRO_TK_BAD_INPUTS - The input argument is invalid. 
*/

extern ProError ProFeatureGroupStatusGet (ProFeature       *p_feat_handle,
                                          ProGroupStatus   *p_group_status);
/*
   Purpose: Retrieves the group status of the specified feature.

   Input Arguments:
       p_feat_handle     - The feature to process

   Output Arguments:
       p_group_status    - The current group status of the feature

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProFeatureGrppatternStatusGet (ProFeature   *p_feat_handle,
                                               ProGrppatternStatus   *p_grp_pattern_status);
/*
   Purpose: Retrieves the group pattern status of the specified feature.

   Input Arguments:
       p_feat_handle        - The feature to process

   Output Arguments:
       p_grp_pattern_status - The current group pattern status of the feature

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the
                           information.
       PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProFeatureVisibilityGet (ProFeature *p_feat_handle,
                                         ProBoolean *p_visible); 

/*
   Purpose: Reports whether the specified feature is public or internal.  
            Internal features are 'invisible' features and used internally 
     	    for construction purposes.

   <P>
   <B>NOTE:</B> This is useful primarily in the action/filter callbacks 
                of ProSolidFeatVisit(). 
 
   Input Arguments:
       p_feat_handle   -    The feature to process. 
      
   Output Arguments:
       p_visible       -    If the specified feature is public, this is
                            PRO_B_TRUE. If specified feature is internal,
                            this is PRO_B_FALSE.      
      
   Return Values: 
      PRO_TK_NO_ERROR   -  The function successfully verified the feature.    
      PRO_TK_BAD_INPUTS -  The input argument is invalid. 
      
   See Also:
      ProSolidFeatVisit() 
      
*/

extern ProError ProFeatureTypeGet  (ProFeature  *p_feat_handle,
				    ProFeattype *p_type);
/*
   Purpose: Retrieves the type of the specified feature.

   Input Arguments:
      p_feat_handle       - The feature  

   Output Arguments:
      p_type              - The feature type 

   Return Values:
      PRO_TK_NO_ERROR  	  - The function successfully retrieved the
                            information. 
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

   See Also:
      ProFeatType.h
*/

extern ProError ProFeatureSubtypeGet  (ProFeature  *feature,
                                               ProLine subtype);
/*
   Purpose: Retrieves the subtype of the specified feature.
 
   Input Arguments:
      feature             - The feature
 
   Output Arguments:
      subtype             - The feature subtype
 
   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the
                            information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.

   See Also:
      ProFeatType.h
*/

extern ProError ProFeatureTypenameGet ( ProFeature  *feature,
					ProName feattypename);
/*
   Purpose: Retrieves the type name of the specified feature.

   Input Arguments:
      feature           - The feature  

   Output Arguments:
      feattypename      - The feature type name 

   Return Values:
      PRO_TK_NO_ERROR  	   - The function successfully retrieved the
                             information. 
      PRO_TK_GENERAL_ERROR - An error occurred.
      PRO_TK_BAD_INPUTS    - The input argument is NULL or otherwise invalid.

   See Also:
      ProFeatType.h
*/

extern ProError ProFeatureSelectionGet  (ProFeature   *p_feature,
					 ProSelection *p_selection);
/*
   Purpose: Retrieves reference information for a feature created in Assembly 
            mode.
<p>
            The function fills in the following fields in the <I>ProSelection</I> 
            structure:
            
            <pre>p_selection -> sel_obj   - The p_feature</pre>

            <pre>p_selection -> comp_path.owner - The feature reference assembly</pre>

            <pre>p_selection -> comp_path.comp_id_table - The path from the</pre>
                           <pre>reference assembly to the part where the feature</pre> 
                           <pre>was created</pre>

            <pre>p_selection -> comp_path.table_num - The size of the comp_id_table</pre> 

<p>

   NOTE: 
<p>
        If the feature does not have a reference assembly (that is, it has
        local references only), the returned values are as follows:

             <pre>p_selection -> comp_path.owner.id = PRO_VALUE_UNUSED;</pre>
             <pre>p_selection -> comp_path.owner.type = PRO_TYPE_UNUSED;</pre>
             <pre>p_selection -> comp_path.table_num - PRO_VALUE_UNUSED;</pre>


   Input Arguments:
      p_feature            - The feature 

   Output Arguments:
     p_selection           - The data structure to be filled in
                   
   Return Values:
      PRO_TK_NO_ERROR      - The function successfully filled in the data
                             structure.
      PRO_TK_BAD_INPUTS    - The input argument is invalid.
      PRO_TK_BAD_CONTEXT   - The specified feature does not have a reference 
                             assembly. 
      PRO_TK_E_NOT_FOUND   - The reference assembly is not in session.
      PRO_TK_GENERAL_ERROR - A major problem occurred, usually object 
                             corruption. For example, the function may 
                             have found the reference assembly, but the
                             owner part does not match the component path. 
                             In this case, the <I>p_selection</I> will be 
			     initialized with the obtained data, but might
                             be invalid.
*/

extern ProError ProFeatureAnalysisGet( ProFeature *feature,
                                       ProAnalysis *analysis);
/*
    Purpose:
        Gets the analysis object associated with an analysis feature.
 
    Input Arguments:
        feature            - The analysis feature.
 
    Output Arguments:
        analysis           - The analysis object.
 
    Return Values:
        PRO_TK_NO_ERROR    -  The function successfully got the analysis
                              object.
        PRO_TK_BAD_INPUTS  -  The feature is not an analysis feature.
   
   See Also:
       ProAnalysis.h
       
*/


extern ProError ProFeatureElemtreeCreate (ProFeature *feature,
                                          ProElement *p_elem);

/*
    DEPRECATED: Since Wildfire 5.0
    SUCCESSORS: ProFeatureElemtreeExtract
    Purpose: <B>NOTE:</B>
<p>
        This function is <B>deprecated</B>. 
        It does not provide options to resolve
        the paths of external references of the feature. 
        Use ProFeatureElemtreeExtract() instead.
<p>
        Creates a copy of the feature element tree.
<p>
 
    Input Arguments:
        feature            - The feature
 
    Output Arguments:
        p_elem             - The root element of the feature element tree
 
    Return Values:
        PRO_TK_NO_ERROR    -  The function successfully created
                              the feature element tree.
        PRO_TK_BAD_INPUTS  -  The input argument is invalid.
        PRO_TK_INVALID_TYPE - Creation of the element tree is not supported
                              for this feature type.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProFeatureElemtreeExtract (ProFeature *feature,
                                           ProAsmcomppath *path,
                                          ProFeatureElemtreeExtractOptions opts,
                                           ProElement *p_elem);


/*
    Purpose: Creates a copy of the feature element tree.  Preferred over
             ProFeatureElemtreeCreate() Since it provides options to resolve
             the paths of external references of the feature.

    Input Arguments:
        feature - The feature.
        path - The path used to resolve references from the element tree.  Can
               be NULL, but trees which lack the proper external references may
               not be usable to redefine the feature with external references.
        opts - The options used for the extraction.
               Pass PRO_FEAT_EXTRACT_NO_OPTS for now.

    Output Arguments:
        p_elem - The root element of the feature element tree.  Free this using
                 ProFeatureElemtreeFree().

    Return Values:
        PRO_TK_NO_ERROR - The function successfully created the feature element
                          tree.
        PRO_TK_BAD_INPUTS - The input argument is invalid.
        PRO_TK_INVALID_TYPE - Extraction of the element tree is not supported
                              for this feature type.
    See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProFeatureElemtreeFree (ProFeature *feature,
                                        ProElement  p_elem);

/*
    Purpose:
        Frees a copy of the feature element tree.

    Input Arguments:
        feature            - The feature
        p_elem             - The root element of the feature element tree

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    -  The function successfully freed
                              the feature element tree.
        PRO_TK_BAD_INPUTS  -  The input argument is invalid.
  
*/

extern ProError ProFeatureElemValueGet (ProFeature    *feature,
                                        ProElempath    elempath,
                                        ProValue      *p_elemvalue );
/*
    DEPRECATED: Since Wildfire 2
    SUCCESSORS: CONTEXTUAL
    Purpose:
        Retrieves a single element value from the specified feature.
        Note that the element cannot be a compound element.
        <b>Note: </b>this function is deprecated, use ProElement<type>Get.
 
    Input Arguments:
        feature             - The feature
        elempath            - The path to the element
 
    Output Arguments:
        p_elemvalue         - The element value
 
    Return Values:
        PRO_TK_NO_ERROR     -  The function successfully retrieved
                               the feature element value.
        PRO_TK_BAD_INPUTS   -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


extern ProError ProFeatureElemValuesGet (ProFeature    *feature,
                                         ProElempath    elempath,
                                         ProValue     **p_elemvalues );
/*
    DEPRECATED: Since Wildfire 2
    SUCCESSORS: CONTEXTUAL
    Purpose:
        Retrieves the element values from the specified feature.
        Note that the element cannot be a compound element.
        <b>Note: </b>this function is deprecated, use ProElement<type>Get.
 
    Input Arguments:
        feature             - The feature.
        elempath            - The path to the element.
 
    Output Arguments:
        p_elemvalues        - The element values. You must allocate the 
                              memory for this argument using the function
                              <B>ProArrayAlloc()</B>.
 
    Return Values:
        PRO_TK_NO_ERROR     - The function successfully retrieved
                              the feature element values.
        PRO_TK_BAD_INPUTS   - One or more of the input arguments are invalid.

    See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


 
extern ProError ProFeatureElemDimensionIdGet (ProFeature *feature,
                                              ProElempath elempath,
                                              int        *p_dimension_id);
/*
    Purpose:
        Retrieves the dimension identifier of the specified element. Note that
        the element cannot be a compound element.
 
    Input Arguments:
        feature            - The feature
        elempath           - The path to the element
 
    Output Arguments:
        p_dimension_id     - The dimension identifier
 
    Return Values:
        PRO_TK_NO_ERROR    -  The function successfully retrieved
                               the dimension identifier.
        PRO_TK_BAD_INPUTS  -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


extern ProError ProFeatureElemIsVisible ( ProFeature  *feature,
                                          ProElempath  elempath,
                                          ProBool     *p_isvisible );
/*
    Purpose:
        Determines whether the element specified by the <i>elempath</i> 
        argument is visible.

    Input Arguments:
        feature              -  The feature.
        elempath             -  The path to the element.
 
    Output Arguments:
        p_isvisible          -  If the element is visible, this is
                                PRO_B_TRUE; otherwise, this is PRO_B_FALSE.
 
    Return Values:
        PRO_TK_NO_ERROR      -  The function successfully retrieved
                                the information.
        PRO_TK_BAD_INPUTS    -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


extern ProError ProFeatureElemIsIncomplete ( ProFeature  *feature,
                                             ProElempath  elempath,
                                             ProBool *p_isincomplete );
/*
    Purpose:
        Determines whether the element specified by the <i>elempath</i> 
        argument is incomplete.

    Input Arguments:
        feature              -  The feature.
        elempath             -  The path to the element.
 
    Output Arguments:
        p_isincomplete       -  If the element is incomplete, this is
                                PRO_B_TRUE; otherwise, this is PRO_B_FALSE.  
    Return Values:
        PRO_TK_NO_ERROR      -  The function successfully retrieved
                                the information.
        PRO_TK_BAD_INPUTS    -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProFeatureParamsDisplay (ProSelection feature_sel,
                                         ProParamType param_type);

/*
    Purpose:  Displays the same parameters shown by Creo Parametric when you
              modify a feature.

    Input Arguments:
        feature_sel          -  A <I>ProSelection</I> structure for the feature
        param_type           -  The parameter type to show

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      -  The function successfully displayed 
                                the information.
        PRO_TK_BAD_INPUTS    -  One or more of the arguments are invalid.
        PRO_TK_GENERAL_ERROR -  A general error occurred and the function
                                failed.
        PRO_TK_E_NOT_FOUND   -  The model is not the top-level model in
                                the window.
*/


extern ProError ProFeatureNumSectionsGet (ProFeature  *feat_handle,
                                          int         *p_n_sections);
/*
   Purpose:  Returns the number of sections owned by the specified 
             feature.
 
   Input Arguments:
       feat_handle        -  The feature
 
   Output Arguments:
       p_n_sections       -  The number of sections in the feature
 
   Return Values:
      PRO_TK_NO_ERROR     -  The function successfully retrieved the
                             information.
      PRO_TK_BAD_INPUTS   -  The input argument is invalid.
*/

extern ProError ProFeatureSectionCopy (ProFeature  *feat_handle,
                                       int          section_number,
                                       ProSection  *p_section);
/*
   Purpose:  Returns the copy of the requested section of the
             feature.
 
   Input Arguments:
       feat_handle    -  The feature.
       section_number -  The section number. The valid values are
                         0 to (<I>n</I>-1), where <I>n</I> is the number of
                         sections given by the function
                         <B>ProFeatureNumSectionsGet()</B>.
 
   Output Arguments:
       p_section      -  The copy of the requested feature section. The
                         function allocates the memory for this object. 
                         Use the function <B>ProSectionFree()</B> to free
                         the object.
 
   Return Values:
      PRO_TK_NO_ERROR     -  The function successfully retrieved the
                             information.
      PRO_TK_UNAV_SEC     -  The section is not available for use.
      PRO_TK_BAD_INPUTS   -  One or more of the input arguments are invalid.

   See Also:
      ProFeatureNumSectionsGet()
      ProSectionFree()
*/

extern ProError ProFeatureVerstampGet  (ProFeature  *feat_handle,
                                        ProWVerstamp  *p_stamp);
/*
   Purpose:  Retrieves the version stamp of the specified feature.

   Input Arguments:
      feat_handle         - The feature.

   Output Arguments:
      p_stamp             - The version stamp. The function allocates the memory
                            for this argument. To free the memory, use the
                            function <B>ProVerstampFree()</B>.
                       
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProVerstampFree()
*/

extern ProError ProFeatureNumberGet  (ProFeature  *p_feat_handle,
                                      int         *r_feat_num);
/*
   Purpose:  Returns the regeneration sequence number of a feature.
<p>
             NOTE: 
<p>
             Do not confuse this with a feature identifier.
             A feature identifier identifies a feature uniquely in
             a part or an assembly. The feature number tells you 
             the sequential location of the feature in the feature list 
             of the part or assembly.

   Input Arguments:
      p_feat_handle     - The feature

   Output Arguments:
      r_feat_num        - The sequence number of the supplied feature 
                          for regeneration

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The supplied feature is invalid.
*/

extern ProError ProFeatureReorder  (ProSolid  solid,
                                    int       *feat_ids,
                                    int       n_feats,
                                    int       new_feat_num);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProFeatureWithoptionsReorder
   Purpose:
      Reorders the supplied set of features such that the location of 
      the first feature will be the <I>new_feat_num</I> after the reorder.
<p><b>
   NOTE:
<p></b>
      This function is deprecated. Use ProFeatureWithoptionsReorder() 
      with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.

   Input Arguments:
      solid             - The part or assembly that owns the features to be 
                          reordered.
      feat_ids          - The array of feature identifiers that represents a 
                          contiguous set of features in the model tree. If 
                          reordering a group, all the features in the group 
                          (including the Group Header feature) must be included
                          in this array.
      n_feats           - The size of the <I>feat_ids</I> array.
      new_feat_num      - The intended location of the first feature in the 
                          specified set, upon reorder.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully reordered the features.
      PRO_TK_BAD_INPUTS - The specified feature is invalid, or the location to
                          which the reordering is requested is not valid. 
*/

extern ProError ProFeatureReadonlySet  (ProFeature  *p_last_feat);
/*
   Purpose:  Makes all the features up to the specified feature read only.

   Input Arguments:
      p_last_feat       - The last feature up to which the features are to be 
                          read only.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully made all features up to 
                          and including the specified feature read-only.
      PRO_TK_BAD_INPUTS - The specified feature is invalid.
      Other             - The read-only setting was aborted.
*/

extern ProError ProFeatureIsReadonly  (ProFeature  *p_feat_handle,
                                       ProBoolean  *r_is_read_only);
/*
   Purpose:  Determines whether the specified feature is read only.

   Input Arguments:
      p_feat_handle     - The feature.

   Output Arguments:
      r_is_read_only    - This is PRO_B_TRUE if the supplied feature is marked
                          read only; otherwise, this is PRO_B_FALSE. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully returned the 
                          requested information. 
      PRO_TK_BAD_INPUTS - The specified feature is invalid.
*/

extern ProError ProFeatureReadonlyUnset  (ProSolid  solid);
/*
   Purpose:  Removes the read-only setting of all the features owned by the 
             specified solid.

   Input Arguments:
      solid             - The solid whose read-only setting is to be cleared

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully cleared the read-only 
                          setting. 
      PRO_TK_BAD_INPUTS - The specified part or assembly is invalid.
*/

extern ProError ProFeatureIsEmbedded (ProFeature* feat, 
				      ProBoolean* is_embedded);
/*
   Purpose:  Identifies if the feature is an embedded feature or not. Embedded
             features are visible in the model tree but may not be used as the
             reference parents for features other than the feature into which
             they are embedded.

   Input Arguments:
      feat              - The feature.

   Output Arguments:
      is_embedded       - PRO_B_TRUE if the feature is embedded, PRO_B_FALSE
                          otherwise.

   Return Values:
      PRO_TK_NO_ERROR   - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProFeatureInsertModeActivate  (ProFeature  *p_last_feat);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProFeatureInsertmodeWithoptionsActivate
   Purpose:
      Activates insert mode such that the specified feature becomes
      the last feature.
<p><b>
   NOTE:
<p></b>
      This function is deprecated. Use ProFeatureInsertmodeWithoptionsActivate()
      with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.

   Input Arguments:
      p_last_feat       - The feature that will be the last feature.
                          All the features after this feature will be detached.
                          Any features created after the activation of 
                          insert mode will be created after this feature.
                          When you cancel the insert mode, the detached
                          features will be reappended at the end. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully activated insert mode. 
      PRO_TK_BAD_INPUTS - The specified feature is invalid.

   See Also:
       ProInsertModeIsActive()
       ProInsertModeCancel()
*/

extern ProError ProInsertModeIsActive  (ProSolid    solid,
                                        ProBoolean  *p_is_active);
/*
   Purpose:  Determines whether insert mode is active in the specified part 
             or assembly.

   Input Arguments:
      solid             - The part or assembly. 

   Output Arguments:
      p_is_active       - This is PRO_B_TRUE if insert mode is active; 
                          otherwise,
                          this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully returned the information.
      PRO_TK_BAD_INPUTS - The specified solid is invalid.

   See Also:
       ProFeatureInsertModeActivate()
       ProInsertModeCancel()
*/

extern ProError ProInsertModeCancel  (ProSolid    solid,
                                      ProBoolean  resume);
/*
   DEPRECATED: Since Wildfire 5.0
   SUCCESSORS: ProInsertmodeWithoptionsCancel
   Purpose: 
      Cancels insert mode in the specified part or assembly.
<p><b>
   NOTE:
<p></b>
      This function is deprecated. Use ProInsertmodeWithoptionsCancel()
      with flags equal to PRO_REGEN_NO_FLAGS for equivalent behavior.

   Input Arguments:
      solid             - The part or assembly.
      resume            - Set this to PRO_B_TRUE if the suppressed features 
                          are to be resumed once you cancel insert mode.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully cancelled insert mode.
      PRO_TK_BAD_INPUTS - The specified feature is invalid.

   See Also:
       ProFeatureInsertModeActivate()
       ProInsertModeIsActive()
*/

extern ProError ProFeatureHasGeomchks (ProFeature *p_feat_handle, 
    				       ProBoolean *p_has_gerrs );
/*
  Purpose:  Determines whether the specified feature in a
            part or assembly has geometry check items.
 
  Input Arguments:  
     p_feat_handle     - The feature to be checked.
 
  Output Arguments: 
     p_has_gerrs       -  If this is PRO_B_TRUE, the feature has geometry check
                          items. Otherwise, this is PRO_B_FALSE.
  Return Values:   
     PRO_TK_NO_ERROR   -  The function successfully retrieved the information. 
     PRO_TK_BAD_INPUTS -  The input argument is invalid.
*/
 
typedef ProError (*ProFeatureCreatePostAction) (ProFeature *feat_handle);

/*
  Purpose: This is the notification function called upon 
	   successful creation of a feature. 
<p>
           This function is to be supplied by the user by calling
           <B>ProNotificationSet()</B> with the notify type 
	   PRO_FEATURE_CREATE_POST.

  Input Arguments:
     feat_handle   -  The handle of the feature just created

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:  
      ProNotificationSet()
*/

typedef ProError (*ProFeatureCopyPostAction) (ProFeature      *from_feat,
                                              ProFeature      *to_feat,
                                              ProFeatcopyType  copy_type);

/*
  Purpose:  This is the notification function called upon 
	    successful copying of a feature.  
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type 
            PRO_FEATURE_COPY_POST.

  Input Arguments:
     from_feat     -  The handle of the reference feature from which the
                      copy was made.
     to_feat       -  The handle of the feature that is the result of the
                      copy.
     copy_type     -  The type of user action prompting the copying of 
                      features. See the enumerated type <I>ProFeatcopyType</I>.

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

typedef ProError (*ProFeatureDeletePreAction) (ProFeature      *del_feat);

/*
  Purpose:  This is the notification function called before a feature is 
            deleted.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type 
	    PRO_FEATURE_DELETE_PRE.

  Input Arguments:
     del_feat      -  The handle of the feature about to be deleted

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  The feature can be deleted. Proceed.
     Other            -  An error was encountered. The deletion action is 
                         aborted for all features.

  See Also:
     ProNotificationSet()
*/

typedef ProError (*ProFeatureDeletePostAction) (ProFeature      *del_feat);

/*
  Purpose:  This is the notification function called after a 
	    feature has been deleted from the solid.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type 
	    PRO_FEATURE_DELETE_POST.

  Input Arguments:
     del_feat      -  The handle of the deleted feature

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

typedef ProError (*ProFeatureSuppressPreAction) (ProFeature      *supp_feat);

/*
  Purpose:  This is the notification function called before a feature 
            is suppressed.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type 
	    PRO_FEATURE_SUPPRESS_PRE.

  Input Arguments:
     supp_feat     -  The handle of the feature about to be suppressed

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR  -  The feature can be suppressed. Proceed.
     Other            -  An error was encountered. The suppress action is 
                         aborted for all features.

  See Also:
     ProNotificationSet()
*/

typedef ProError (*ProFeatureSuppressPostAction) (ProFeature      *supp_feat);

/*
  Purpose:  This is the notification function called after a feature 
	    has been suppressed from a solid.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type 
	    PRO_FEATURE_SUPPRESS_POST.
 
  Input Arguments:
     supp_feat     -  The handle of the suppressed feature

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

typedef ProError (*ProFeatureRegenPreAction) (ProFeature   *feat_handle,
                                              ProElement   *p_elem_tree);
 
/*
  Purpose:  This is the notification function called before 
	    regenerating a feature.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
	    PRO_FEATURE_REGEN_PRE.
 
  Input Arguments:
     feat_handle   -  The handle to the feature about to be regenerated.
 
  Output Arguments:
     p_elem_tree   -  The new feature definition upon regeneration.
                      The argument will be initialized to NULL
                      (that is, <I>*p_elem_tree</I> = NULL). It will be used
                      only if the callback initializes it.
                      <p> 
                      Note that this argument is reserved for future use.
                      Values passed to this argument are currently ignored
                      by Creo Parametric.
 
  Return Values:
 
     PRO_TK_NO_ERROR  -  Proceed with regeneration.
     Other            -  An error was encountered. Regeneration is aborted.

  See Also:
     ProNotificationSet()
*/

typedef ProError (*ProFeatureRegenPostAction) (ProFeature   *feat_handle);

/*
  Purpose:  This is the notification function called after regenerating 
	    a feature.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type 
	    PRO_FEATURE_REGEN_POST.

  Input Arguments:
     feat_handle   -  The handle to the feature just regenerated

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet() 
*/

typedef ProError (*ProFeatureRegenFailureAction) (ProFeature  *p_feature);
/*
  Purpose:  This is the notification function called upon a feature failure 
	    event.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type
            PRO_FEATURE_REGEN_FAILURE.
 
  Input Arguments:
     p_feature          - The failed feature
 
  Output Arguments:
     None
 
  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()    
*/

typedef ProError (*ProFeatureNeedsRegenGet) (ProFeature  *p_feature);
/*
  Purpose:  This is the notification function called when checking if
	    a feature needs to be regnerated.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type
            PRO_FEATURE_NEEDS_REGEN_GET.
 
  Input Arguments:
     p_feature          - The failed feature
 
  Output Arguments:
     None
 
  Return Values:
      PRO_TK_OUTDATED  - return value if toolkit application wants to force
                         regeneration of feature.
      PRO_TK_NO_ERROR  - This application is NOT requesting that feature be
			 forced to regenerate.
      Note: Other return values are not interpreted by Creo Parametric and can
	    prevent other applications from properly affecting feature regen.

  See Also:
      ProNotificationSet()    
*/

typedef ProError (*ProFeatureCreatePreAction) (ProFeature *p_feature);
/*
  Purpose:  This is the notification function called before creating a feature.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type
            PRO_FEATURE_CREATE_PRE.

  Input Arguments:
     p_feature          - The new feature to be created

  Output Arguments:
     None

  Return Values:
     Return values are not interpreted by Creo Parametric.

  See Also:
     ProNotificationSet() 
*/

typedef ProError (*ProFeatureRedefinePreAction) (ProFeature *p_feature);
/*
  Purpose:  This is the notification function called before redefinition 
	    of a feature.
<p>
            This function is to be supplied by the user by calling
            <B>ProNotificationSet()</B> with the notify type
            PRO_FEATURE_REDEFINE_PRE.

  Input Arguments:
     p_feature          - The feature to be redefined

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR    - The feature can be redefined. Proceed.
     Other              - An error was encountered. The regeneration action
                          is aborted for all features.

  See Also:
     ProNotificationSet()
*/

typedef ProError (*ProFeatureRedefinePostAction) (ProFeature *p_feat);
/*
  Purpose: This is the notification function called after a feature is
           redefined in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the type PRO_FEATURE_REDEFINE_POST.

  Input Arguments:
        p_feat           - Feature which has been redefined.

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProFeatureReroutePreAction) (ProFeature *p_feat);
/*
  Purpose: This is the notification function called before a feature is
           rerouted in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the type PRO_FEATURE_REROUTE_PRE.

  Input Arguments:
        p_feat           - Feature which is going to be rerouted.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR    - The feature can be rerouted. Proceed.
     Other              - An error was encountered. The reroute action
                          is aborted for all features.
*/

typedef ProError (*ProFeatureReroutePostAction) (ProFeature *p_feat);
/*
  Purpose: This is the notification function called after a feature is
           rerouted in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the type PRO_FEATURE_REROUTE_POST.

  Input Arguments:
        p_feat           - Feature which has been rerouted.

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProFeatureReplacePreAction) (ProFeature *p_feat);
/*
  Purpose: This is the notification function called before a feature is
           replaced in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the type PRO_FEATURE_REPLACE_PRE.

  Input Arguments:
        p_feat           - Feature which is going to be replaced.

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR    - The feature can be replaced. Proceed.
     Other              - An error was encountered. The replace action
                          is aborted for all features.
*/

typedef ProError (*ProFeatureReplacePostAction) (ProFeature *p_feat);
/*
  Purpose: This is the notification function called after a feature is
           replaced in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the type PRO_FEATURE_REPLACE_POST.

  Input Arguments:
        p_feat           - Feature which has been replaced.

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.
*/


extern ProError ProFeatureDimensionVisit (
    ProFeature               *feature,
    ProDimensionVisitAction  visit,
    ProDimensionFilterAction filter,
    ProAppData               data);
/*
   Purpose: Visits dimensions belonging to the feature.
            
            NOTE: The dimensions values might depend on other feature’s 
            dimensions, e.g. sketch based features with shared/patterned or
            external sections, dependent copied or mirrored features.
            In many Creo operations such value dependent dimensions are 
            automatically substituted  by the parent dimension.
            If your application wishes to substitute value dependent 
            dimensions by the parent, see ProDimensionParentGet().
 
   Input Arguments:
      feature            - The feature 
      visit              - The visit function
      filter             - The filter function. If NULL, all dimensions are
                           visited using the action function.
      data               - User defined data passed to the visit and filter
		           functions.
   Output Arguments:
      None
 
   Return Values:
      	PRO_TK_NO_ERROR   - The function successfully visited all
			    the feature's dimensions.
	PRO_TK_BAD_INPUTS - The function failed because one or
			    more of the input arguments are invalid.
	PRO_TK_E_NOT_FOUND - No feature dimensions were visited.
	PRO_TK_GENERAL_ERROR - An error occurred while locating the dimensions.
	other	          - Visiting was stopped by the caller supplied
			    functions with this error return.
*/


extern ProError ProFeatureCopyinfoGet (ProFeature* feature,
                                       ProFeatureCopyType* copy_type,
                                       ProFeatureCopyDependency* dependency,
                                       ProFeature* source_feature,
                                       ProFeature** also_copied);
/*
   Purpose:   Retrieves information about a copied feature.

   Input Arguments:
      feature        - The feature.

   Output Arguments:
      copy_type      - The type of copy operation that created the feature.
                       Pass NULL if you are not interested in this information. 
      dependency     - Whether the copy is dependent or independent of the
                       parent feature.
                       NOTE: If a feature does not have any sections or
                       dimensions, it will always be an independent copy
                       regardless of the selection made when creating the copy.
                       Pass NULL if you are not interested in this information.
      source_feature - The feature that this feature was copied from.
                       source_feature is not available for independent copy.
                       Pass NULL if you are not interested in this information.
      also_copied    - ProArray of features that were copied with this feature.
                       If there were no accompanying features, this will
                       be NULL. If there are accompanying features, free this
                       array using ProArrayFree.
                       Pass NULL if you are not interested in this information.

   Return Values:
      PRO_TK_NO_ERROR    - The feature copy information was created successfully.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_BAD_CONTEXT - The feature is not a copied feature.
*/

extern ProError ProFeatureSketchAdd( ProFeature *incomplete_feature,
    				     ProSelection selection, 
				     int section_number  ); 
/*
    Purpose:
       Copies section from a sketched datum curve specified by selection 
       to the incomplete feature.

    Input Arguments:
            incomplete_feature     - The incomplete feature to which the 
	                             section needs to be added
				     Supports the following sketched features:
			         <ol><li>Fill / Flat Surface 
				     <li>Extrude 
				     <li>Revolve 
				     <li>Sketched Datum Curve 
		                     <li>Wrap Curve
                                 </ol>
 
            selection              - The selection of sketched datum curve 
                                     feature from which section needs to be
                                     copied ( composed of id = feat_id and type
                                      = PRO_FEATURE )
            section_number 	   - The section number. The valid values are
                         	     0 to (<I>n</I>-1), where <I>n</I> is the 
                                     number of sections given by the function
                                     <B>ProFeatureNumSectionsGet()</B>.

    Output Arguments:
      none


    Return Values:
      PRO_TK_NO_ERROR             - Successful in copying the section 
      PRO_TK_BAD_INPUTS           - Invalid inputs
      PRO_TK_NOT_EXIST            - section_number > max_section_number
      PRO_TK_BAD_CONTEXT          - incomplete_feature is already complete
      PRO_TK_INVALID_ITEM         - Improper selection object
      PRO_TK_ABORT         	  - selection contains feature other than a 
				    sketched datum curve 

*/

extern ProError ProFeatureSketchedCreate ( ProSelection     	model,
					   ProElement		elemtree, 
					   ProFeatureCreateOptions *options, 
					   int 			num_opts,
					   ProSelection 	*sketch_array, 
					   ProFeature		*p_feature, 
					   ProErrorlist		*p_errors );
/*
    DEPRECATED: Since Creo 4.0 
    SUCCESSORS: ProFeatureSketchedWithOptionsCreate
    Purpose:
       Creates a feature from the element tree and copies sketch(es) from 
       the feature(s) from sketch_array to the created feature.
       Supports creation of the following sketched features:
       <ol>
		<li>Fill / Flat Surface 
		<li>Extrude 
		<li>Revolve 
		<li>Sketched Datum Curve
                <li>Wrap Curve
      </ol> 

    Input Arguments:
       model           - The model on which the feature is being created.
                         If the feature is created in an assembly, you must
                         specify the component path.
       elemtree        - The element tree.
       options         - An array of user options.
       num_opts        - The number of options in the <I>options</I> array.
       sketch_array    - ProArray of selections of sketch datum curves 
                         containing sketches 

    Output Arguments:
       p_feature       - The feature handle to the created sketched feature.
       p_errors        - The list of errors.

    Return Values:
       PRO_TK_NO_ERROR      - The function successfully created
                              the feature.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The feature was not created successfully. The 
			      will feature  set as incomplete. See p_errors for
                              the list of problems. 			     
       PRO_TK_ABORT         - sketch_array contains feature other than a 
			      sketched datum curve 

	See Also:
       ProDtmCrv.h
       ProDtmPnt.h
       ProExtrude.h
       ProFlatSrf.h
       ProRevolve.h
       ProRib.h
*/ 

extern ProError ProFeatureSketchedWithOptionsCreate( ProSelection             model,
                                     ProElement               elemtree,
                                     ProFeatureCreateOptions *options,
                                     ProSelection            *sketch_array,
                                     int                      flags,
                                     ProFeature              *p_feature,
                                     ProErrorlist            *p_errors );
/*
    Purpose:
       Creates a feature from the element tree and copies sketch(es) from 
       the feature(s) from sketch_array to the created feature.
       Supports creation of the following sketched features:
       <ol>
		<li>Fill / Flat Surface 
		<li>Extrude 
		<li>Revolve 
		<li>Sketched Datum Curve
                <li>Wrap Curve
      </ol> 

    Input Arguments:
       model           - The model on which the feature is being created.
                         If the feature is created in an assembly, you must
                         specify the component path.
       elemtree        - The element tree.
       options         - ProArray of user options.
       sketch_array    - ProArray of selections of sketch datum curves 
                         containing sketches 
       flags           - The regeneration control flags. Pass as bitmask containing
                         one or more of the bit flags PRO_REGEN* defined in ProSolid.h

    Output Arguments:
       p_feature       - The feature handle to the created sketched feature.
       p_errors        - The list of errors.

    Return Values:
       PRO_TK_NO_ERROR      - The function successfully created
                              the feature.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - The feature was not created successfully. The 
			      will feature  set as incomplete. See p_errors for
                              the list of problems. 			     
       PRO_TK_ABORT         - sketch_array contains feature other than a 
			      sketched datum curve 

	See Also:
       ProDtmCrv.h
       ProDtmPnt.h
       ProExtrude.h
       ProFlatSrf.h
       ProRevolve.h
       ProRib.h
*/ 


extern ProError ProFeatureDtlsyminstGet (ProFeature    *symbol_owner,
                                         ProDrawing     drawing,
                                         ProDtlsyminst *symbol_instance);
/*
Purpose: Return the detail symbol instance that represents a shown solid model
         symbol.

Input Arguments:
  symbol_owner   - The feature (i.e. weld feature) that will produce the symbol.
  drawing        - The drawing where the note is displayed.

Output Arguments:
  symbol_instance - The symbol instance that displays the solid model symbol.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the symbol instance.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_BAD_CONTEXT - The solid model is not contained in the drawing.
  PRO_TK_E_NOT_FOUND - The symbol is not displayed in the drawing.
*/

typedef struct pro_asm_intr_comp* ProFeatintersection;

extern ProError ProFeatureAsmintersectionsCollect (ProFeature* feat,
                                                   ProFeatintersection** p_intersection_array);
/*
   Purpose: Collects and returns all the intersections 
            of the assembly feature.

   Input Arguments:
      feat                 - The assembly feature

   Output Arguments:
      p_intersection_array  - ProArray of intersections.  
                              Free this array using ProFeatintersecionProarrayFree().

   Return Values:
      PRO_TK_NO_ERROR   -  The function found and returned the intersections.
      PRO_TK_BAD_INPUTS -  One or more arguments is invalid.
      PRO_TK_E_NOT_FOUND - No intersections are found.
*/

extern ProError ProFeatintersectionDataGet (ProFeatintersection p_intersection,
                                            ProAsmcomppath*     p_component,
                                            int*                p_level,
                                            int*                p_feat_id);
/*
   Purpose: Returns the component intersected by the assembly feature,
                    visibility level and id of the feature on intersected part.

   Input Arguments:
      p_intersection  - The assembly feature intersection.

   Output Arguments:
      p_component     - Component path to the component.
          p_level     - The level at which the feature is visible in the assembly.

                      An example:

                      TOP                 level 0
                       |
                       |-SUB1             level 1
                       |   |
                       |   |-SUB2         level 2
                       |       |
                       |-FEAT  |-PART     level 3
                             
                        if level=0 the feature is visible in the TOP assembly only;
                        if level=table_num (from p_component) [in our example table_num=3]
                           the feature is visible in the TOP assembly, 
                           all subassemblies in the path and in the part itself;
                        if level=2, the feature is visible in the TOP assembly, SUB1 and SUB2.
        p_feat_id    - Id of the feature created on the intersected part.

   Return Values:
      PRO_TK_NO_ERROR   -  The function found and returned the intersections.
      PRO_TK_BAD_INPUTS -  One or more arguments is invalid.
*/

extern ProError ProFeatintersectionProarrayFree (ProFeatintersection* p_intersection_array);
/*
   Purpose: Frees the memory owned by a feature intersections ProArray.

   Input Arguments:
      p_intersection_array  - The assembly feature intersection ProArray.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR   -  Successfully released.
      PRO_TK_BAD_INPUTS -  One or more arguments is invalid.
*/

typedef enum
{
  UNKNOWN_INTERSECTION_TYPE = 0,
  REGULAR_INTERSECTION,
  PART_LEVEL_FULL_COPY
} ProFeatIntersectionType;

extern ProError ProFeatintersectionTypeGet (ProFeatintersection p_intersection,
                                            ProFeatIntersectionType* p_type);
/*
   Purpose: Returns the type of geometry created by the assembly feature intersection.

   Input Arguments:
      p_intersection  - The assembly feature intersection.

   Output Arguments:
      p_type          - Kind of the feature created on the intersected part.
                        Values can be: REGULAR_INTERSECTION = regular assembly cut feature;
                                       PART_LEVEL_FULL_COPY = full copy of the assembly 
                                                              feature on the intersected part.

   Return Values:
      PRO_TK_NO_ERROR   -  The function found and returned the intersections.
      PRO_TK_BAD_INPUTS -  One or more arguments is invalid.
*/


extern ProError ProFeatureReferenceEdit( ProSolid                 solid,
                                         ProFeature*              p_feat_handle,
                                         ProReference*            old_ref_arr,
                                         ProReference*            new_ref_arr,
                                         int                      flags );
/*
   Purpose: Edit the references of feature to replace the old reference 
            with new references.

    Input Arguments:
       solid           - The part or assembly to which the features belong.
       p_feat_handle   - The feature handle.
       old_ref_arr     - ProArray containing Old References
       new_ref_arr     - ProArray containing New References corresponding to old references
       flags           - The regeneration control flags. Pass as bitmask containing 
                         one or more of the bit flags PRO_REGEN* defined in ProSolid.h

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR      - The function successfully edited the references.
       PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
       PRO_TK_GENERAL_ERROR - Edit reference operation failed.
       PRO_TK_BAD_CONTEXT   - Invalid regeneration flag(s) for this function.
*/

extern ProError ProFeatureIsInFooter (ProFeature *p_feat_handle,ProBoolean *p_feat_is_in_footer);
/*
   Purpose: Reports if the given feature is currently located in model tree
            footer

   Input Arguments:
      p_feat_handle  - The feature handle.

   Output Arguments:
      p_feat_is_in_footer  -  whether feature is in model tree footer.
                        Values can be: PRO_B_TRUE  = feature is in footer.
                                       PRO_B_FALSE = feature is not infooter.

   Return Values:
      PRO_TK_NO_ERROR   -  The function found and returned the intersections.
      PRO_TK_BAD_INPUTS -  One or more arguments is invalid.
*/

/***************************************************************************/
extern ProError ProFeatureToFooterMove (ProFeature *feature, int *feat_num);
/*
  Purpose:  Move specified feature into the regeneration footer.
  
  Input Arguments:
      feature               - The feature to move.
  
  Output Arguments:
      feat_num              - The feature number AFTER it is moved into the footer.
  
  Return Values:
      PRO_TK_NO_ERROR       - The function succeeded.
      PRO_TK_BAD_INPUTS     - One or more input arguments was invalid.
      PRO_TK_INVALID_TYPE   - The specified feature is not permitted to be moved to footer.
      PRO_TK_E_FOUND        - The specified feature is already in the footer.
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

/******************************************************************************/
extern ProError ProFeatureFromFooterMove (ProFeature *feature, int *feat_num);
/*
  Purpose:  Move specified feature out of the regeneration footer.

  Input Arguments:
      feature               - The feature to move.

  Output Arguments:
      feat_num              - The feature number AFTER it is moved outside the footer.

  Return Values:
      PRO_TK_NO_ERROR       - The function succeeded.
      PRO_TK_BAD_INPUTS     - One or more input arguments was invalid.
      PRO_TK_E_FOUND        - The specified feature is already outside the footer.
      PRO_TK_INVALID_TYPE   - The specified feature is not permitted to be moved from footer.
      PRO_TK_GENERAL_ERROR  - The function failed.
*/

/******************************************************************************/
extern ProError ProMdlFeatBackupOwnerNamesGet (
                       ProMdl model,
                       ProFeature *feature,
                       ProMdlName **TopToOwnerModelNames
                    );
/*
  Purpose: Get model names from top to owner specified by own_ref_id and
           from top to reference from backup, mostly for the case
           some models are missing or not in session.

  Input Arguments:
      model                 - The owner model of the backup data.
      feature               - The referencing feature.

  Output Arguments:
      TopToOwnerModelNames  - ProArray of top to owner model names.
                              The function allocates the memory for this argument.
                              Use the function <B>ProArrayFree()</B> to free the memory.

  Return Values:
      PRO_TK_NO_ERROR       - The function succeeded.
      PRO_TK_BAD_INPUTS     - One or more arguments is invalid.
      PRO_TK_E_NOT_FOUND    - The model does not have backup reference data.
      PRO_TK_E_FOUND        - The model has backup reference data, but the
                              specified names are not found.
      PRO_TK_GENERAL_ERROR  - The function failed.

*/

/******************************************************************************/
extern ProError ProMdlFeatBackupRefMdlNamesGet (
                       ProMdl model,
                       ProFeature *feature,
                       int* path,
                       int ref_id,
                       ProMdlName **TopToRefModelNames
                    );
/*
  Purpose: Get model names from top to owner specified by own_ref_id and
           from top to reference from backup, mostly for the case
           some models are missing or not in session.

  Input Arguments:
      model                 - The owner model of the backup data.
      feature               - The referencing feature.
      path                  - A ProArray of the memb id (path) from the top to the reference owner model.
      ref_id                - The specified reference id.

  Output Arguments:
      TopToRefModelNames    - ProArray of top to ref model names.
                              The function allocates the memory for this argument.
                              Use the function <B>ProArrayFree()</B> to free the memory.

  Return Values:
      PRO_TK_NO_ERROR       - The function succeeded.
      PRO_TK_BAD_INPUTS     - One or more arguments is invalid.
      PRO_TK_E_NOT_FOUND    - The model does not have backup reference data.
      PRO_TK_E_FOUND        - The model has backup reference data, but the
                              specified names are not found.
      PRO_TK_GENERAL_ERROR  - The function failed.

*/

extern ProError ProFeatureIsShrinkwrapRefCopyGeom ( ProFeature *feature,
                                   ProBoolean *p_is_shrinkwrap_ref_cg_feat);

/*
   Purpose: Check is feat of kind Reference Copy geometry feature of
            Shrinkwrap feature
            
   Input Arguments:
       feature             - The feature handle.

   Output Arguments:
       p_is_shrinkwrap_ref_cg_feat  - The pointer on the logical variable which
                                   value can be:
                      PRO_B_TRUE  - feature is of kind Reference Copy 
                                     geometry feature of Shrinkwrap feature
                      PRO_B_FALSE - other
                      This argument is not allowed to be NULL.
 
   Return Values:
       PRO_TK_NO_ERROR      - The function successfully finished.
       PRO_TK_BAD_INPUTS    - input argument is invalid.
*/

extern ProError ProFeatureShrinkwrapGetRefCopyGeoms (ProFeature *feature,
                ProFeature **ShrinkWrapRefCopyGeoms);
/*
   Purpose: Collects Shrinkwrap feat Reference Copy geometry features
            
   Input Arguments:
       feature             - The feature handle.

   Output Arguments:
      ShrinkWrapRefCopyGeoms  - ProArray of Reference Copy geometry features.
                          The function allocates the memory for this argument.
                          Use the function <B>ProArrayFree()</B> to free the memory.
                      This argument is not allowed to be NULL.
 
   Return Values:
       PRO_TK_NO_ERROR      - The function successfully finished.
       PRO_TK_BAD_INPUTS    - input argument is invalid.
*/

extern ProError ProFeatureIsShrinkwrap( ProFeature *feature,
                                   ProBoolean *p_is_shrinkwrap_feat);

/*
   Purpose: Check is feat of kind Shrinkwrap feature
            
   Input Arguments:
       feature             - The feature handle.

   Output Arguments:
       p_is_shrinkwrap_feat  - The pointer on the logical variable which
                                   value can be:
                      PRO_B_TRUE  - feature is of kind Shrinkwrap feature
                      PRO_B_FALSE - other
                      This argument is not allowed to be NULL.
 
   Return Values:
       PRO_TK_NO_ERROR      - The function successfully finished.
       PRO_TK_BAD_INPUTS    - input argument is invalid.
*/

extern ProError ProFeatureRefCopyGeomShrinkwrapGet( ProFeature *feature,
                                   ProFeature *shrinkwrap);

/*
   Purpose: Get Shrinkwrap feature for a given Reference Copy geometry feature
            
   Input Arguments:
       feature             - The feature handle.

   Output Arguments:
       shrinkwrap  - Shrinkwrap feature for a given Reference Copy geometry 
                     feature.
                     This argument is not allowed to be NULL.
 
   Return Values:
       PRO_TK_NO_ERROR      - The function successfully finished.
       PRO_TK_BAD_INPUTS    - input argument is invalid.
*/

PRO_END_C_DECLS
#endif /* PROFEATURE_H */

