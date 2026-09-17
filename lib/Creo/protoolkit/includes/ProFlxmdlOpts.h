#ifndef PROFLXMDLOPTS_H
#define PROFLXMDLOPTS_H



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*===========================================================================
  Generic Flexible Modeling options branch. 

  The branch exists in: PRO_FEAT_FLEXMOVE
                        PRO_FEAT_FLX_OGF
                        PRO_FEAT_ANALYT_GEOM
                        PRO_FEAT_FLXATTACH
                        PRO_FEAT_FLEXSUBST
=============================================================================*/

/*===============================================================================================

(1) Element tree

   PRO_E_FLEX_OPTS_CMPND
      |
      |-- PRO_E_FLEX_TRF_SEL_ATT_GEOM
      |
      |-- PRO_E_FLEX_ATTACH_GEOM
      |
      |-- PRO_E_FLEX_CR_RND_GEOM
      |
      |-- PRO_E_FLEX_KEEP_ORIG_GEOM
      |
      |-- PRO_E_FLEX_PROPAGATE_TANGENCY
      |
      |-- PRO_E_FLEX_DFLT_CONDITIONS
      |
      |-- PRO_E_FLEX_BOUND_EDGES_CMP
      |      |
      |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |
      |-- PRO_E_FLEX_SOL_INDEX
      |
      |-- PRO_E_FLEX_MAINTAIN_TOPO
      |
      |-- PRO_E_FLEX_PULL_OPTION
      |
      |-- PRO_E_FLEX_ATT_CHNS_CMP
      |      |
      |      |-- PRO_E_FLEX_SIDE_SRFS_CMP
      |      |      |
      |      |      |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |      |
      |      |-- PRO_E_FLEX_EXT_INT_CMP
      |             |
      |             |-- PRO_E_STD_CURVE_COLLECTION_APPL
      |
      |-- PRO_E_FLEX_SPLIT_EXT_SURFS_CMP
             |
             |-- PRO_E_FLEX_EXT_SRFS_CMP
             |      |
             |      |-- PRO_E_STD_SURF_COLLECTION_APPL
             |
             |-- PRO_E_FLEX_SPT_SRFS_CMP
             |      |
             |      |-- PRO_E_FLEX_SPLIT_SURFS
             |
             |-- PRO_E_FLEX_FLIP_SPLIT_DIR

=================================================================================================

(2) Elements table

-------------------------------------------------------------------------------------------------
 Element Id                       Element Name               Data Type                Valid Values
-------------------------------------------------------------------------------------------------
 PRO_E_FLEX_OPTS_CMPND            FLX-MDL Options            Compound
 PRO_E_FLEX_TRF_SEL_ATT_GEOM      Transform Sel. Att. Geoms  PRO_VALUE_TYPE_INTEGER   Note-15
 PRO_E_FLEX_ATTACH_GEOM           Attach geometry            PRO_VALUE_TYPE_INTEGER   Note-1
 PRO_E_FLEX_CR_RND_GEOM           Create round geometry      PRO_VALUE_TYPE_INTEGER   Note-2
                               OR Store attachment properties PRO_VALUE_TYPE_INTEGER  Note-2
 PRO_E_FLEX_KEEP_ORIG_GEOM        Keep original geometry     PRO_VALUE_TYPE_INTEGER   Note-3
 PRO_E_FLEX_PROPAGATE_TANGENCY    Propagate tangency         PRO_VALUE_TYPE_INTEGER   Note-4
 PRO_E_FLEX_DFLT_CONDITIONS       Create default conditions  PRO_VALUE_TYPE_INTEGER   Note-14
 PRO_E_FLEX_BOUND_EDGES_CMP       Bounding Edges             Compound                
 PRO_E_STD_CURVE_COLLECTION_APPL  Bounding Edges Chain       Chain                    Note-5
 PRO_E_FLEX_SOL_INDEX             Solution info              Application              Note-6
 PRO_E_FLEX_MAINTAIN_TOPO         Maintain solution topology PRO_VALUE_TYPE_INTEGER   Note-16
 PRO_E_FLEX_PULL_OPTION           Pull option                PRO_VALUE_TYPE_INTEGER   Note-13
 PRO_E_FLEX_ATT_CHNS_CMP          Non default edge handling  Compound
 PRO_E_FLEX_SIDE_SRFS_CMP         Side surfaces              Compound
 PRO_E_STD_CURVE_COLLECTION_APPL  Side Surfaces Chain        Chain Collection         Note-7
 PRO_E_FLEX_EXT_INT_CMP           Extend and intersect       Compound
 PRO_E_STD_CURVE_COLLECTION_APPL  Extend Intersect Chain     Chain Collection         Note-8
 PRO_E_FLEX_SPLIT_EXT_SURFS_CMP   Split extending surfaces   Compound                 Note-9
 PRO_E_FLEX_EXT_SRFS_CMP          Extending surfaces         Compound               
 PRO_E_STD_SURF_COLLECTION_APPL   Extending surfaces set     Surface Collection       Note-10
 PRO_E_FLEX_SPT_SRFS_CMP          Splitting surfaces         Compound                
 PRO_E_FLEX_SPLIT_SURFS           Splitting surfaces set     PRO_VALUE_TYPE_SELECTION Note-11
 PRO_E_FLEX_FLIP_SPLIT_DIR        Flip split direction       PRO_VALUE_TYPE_INT       Note-12
 

=================================================================================================

(3) Notes

   Note-1  : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]

   Note-2  : Mandatory.

             When PRO_E_FLEX_ATTACH_GEOM is set to PRO_FLEXMODEL_OPT_YES, the option controls 
             creation of round geometry.

             When PRO_E_FLEX_ATTACH_GEOM is set to PRO_FLEXMODEL_OPT_NO, the option controls
             storing of attachment properties.

             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM,
                          PRO_FEAT_FLEXSUBST.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]

   Note-3  : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLEXSUBST.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]

   Note-4  : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_ANALYT_GEOM, PRO_FEAT_FLX_OGF.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]

   Note-5  : Optional.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM,
                          PRO_FEAT_FLEXSUBST, PRO_FEAT_FLEXATTACH. 
             Values     : Edges and Intent Edges which belong to the same geomery
                          list as the primary feature references, but do not belong
                          to the references themselves.

   Note-6  : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM,
                          PRO_FEAT_FLEXSUBST, PRO_FEAT_FLEXATTACH. 
             Inaccessible by Creo Parametric TOOLKIT.

   Note-7  : Optional.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM. 
             Values     : Edges and Intent Edges which belong to the feature's
                          referenced geometry

   Note-8  : Optional.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM. 
             Values     : Edges and Intent Edges which belong to the feature's
                          referenced geometry, and do not belong to
                          "Side Surfaces Chain"

   Note-9  : The "Split extending surfaces" compound.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM.

   Note-10 : Optional* (Used with "Splitting" surfaces set & "Flip Split" option)
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF.
             Please note: Ignored in PRO_FEAT_ANALYT_GEOM, in which the reference
                          surface is the only possible extending surface.
             Values     : Surfaces which belong to the Flexible Modeling feature's
                          references surface set.

   Note-11 : Optional* (Used with "Extending" surfaces set).
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM.
             Values     : Surfces which belong to the same geom list (solid/quilt) as
                          the Flexible Modeling feature's reference surfaces.
                          
   Note-12 : Optional* (Used with "Extending" & "Splitting" surfaces sets)
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]

   Note-13 : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE
             Values     : PRO_FLEXMODEL_PULL_NONE - 
                             Normal feature. "create side surfaces" & "extend and intersect"
                             chain collections will be used.

                          PRO_FLEXMODEL_PULL_CREATE_SURFS - 
                             Treat all reference geometry boundary edges as though they
                             were all selected in the "create side surfaces" chain 
                             collection.

                          PRO_FLEXMODEL_PULL_EXTEND_SURFS - 
                             Treat all reference geometry boundary edges as though they
                             were all selected in the "extend & intersect" chain 
                             collection.

   Note-14 : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]

   Note-15 : Mandatory.
             Relevant in: Creo 3 and above in PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, 
                          PRO_FEAT_FLEXSUBST,FlexMirror & FlexPattern.
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]
                        
             PRO_FLXMDL_OPT_YES - Round and chamfer surfaces selected as primary raferences, 
                                  and were identified as attachment (neighboring) geometries 
                                  will be treated like normal selected references.

             PRO_FLXMDL_OPT_NO  - Round and chamfer surfaces selected as primary raferences, 
                                  and were identified as attachment (neighboring) geometries 
                                  will be treated like neighboring surfaces: they will be
                                  removed and optionally recreated after the transformation
                                  of the other primary references. (i.e. these round/chamfer
                                  surfaces will be treated as if they were not selected as
                                  primary references at all).
   Note-16 : Mandatory.
             Relevant in: PRO_FEAT_FLEXMOVE, PRO_FEAT_FLX_OGF, PRO_FEAT_ANALYT_GEOM,
                          PRO_FEAT_FLEXSUBST, PRO_FEAT_FLEXATTACH. 
             Values     : [PRO_FLEXMODEL_OPT_YES, PRO_FLEXMODEL_OPT_NO]
                        
             PRO_FLXMDL_OPT_YES - The system will always attempt to generate feature geometry 
                                  that is topologically similar to the solution selected by the 
                                  user (The solution stored in PRO_E_FLEX_SOL_INDEX, and set
                                  using "Next/Previous" buttons in the feature UI). If
                                  such a solution cannot be created - the feature will fail.

             PRO_FLXMDL_OPT_NO  - The system will attempt to generate geometry that is
                                  topologically similar to the solution selected by the user,
                                  however if such a solution cannot be created - the system 
                                  will attempt to generate ANY successful solution. If no
                                  successful solution can be generated - the feature will 
                                  fail.

             Please note:         At the moment, solution selection itself is not supported 
                                  in Pro/TK.
    
==============================================================================*/

#define PRO_FLEXMODEL_OPT_YES 1
#define PRO_FLEXMODEL_OPT_NO  0

#define PRO_FLEXMODEL_PULL_NONE         0
#define PRO_FLEXMODEL_PULL_CREATE_SURFS 1
#define PRO_FLEXMODEL_PULL_EXTEND_SURFS 2

PRO_END_C_DECLS

#endif

