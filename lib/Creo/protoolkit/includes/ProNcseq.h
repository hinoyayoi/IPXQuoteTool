#ifndef PRONCSEQ_H
#define PRONCSEQ_H

/* ProNcseq.h:  this include file contains the following details of NC Sequences

                 * NC Sequence feature definition
                 * some utility functions for the NC Sequence feature
*/

#include <ProObjects.h>
#include <ProMfgoper.h>
#include <ProWcell.h>
#include <ProMfgOptions.h>




/*****************************************************************************\

WARNING: This Feature element tree is deprecated and will be removed in subsequent
releases. Refer to these headers for replacement:

ProMfgFeat2xCurvTraj.h
ProMfgFeatCornerFinishing.h
ProMfgFeatFacing.h
ProMfgFeatFinishing.h
ProMfgFeatHolemaking.h
ProMfgFeatManualCycle.h
ProMfgFeatProfMilling.h
ProMfgFeatReroughing.h
ProMfgFeatRoughing.h
ProMfgFeatThreadMilling.h
ProMfgFeatTrajectory.h
ProMfgFeatTurnThread.h
ProMfgFeatTurning.h


Feature element tree
 
   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEAT_TYPE              Non-redefinable
     |
     |--PRO_E_NCSEQ_TYPE             Non-redefinable
     |
     |--PRO_E_HOLEMAKING_TYPE        Holemaking only, Non-redefinable
     |
     |--PRO_E_HOLE_CYCLE_TYPE        Holemaking only, Non-redefinable
     |
     |--PRO_E_PECK_TYPE              Holemaking only, with CYCLE_TYPE == DEEP
     |                               Non-redefinable
     |
     |--PRO_E_DRILL_MODE	     Optional element, applicable when workcell
     |				     is MILL_N_TRN Non-redefinable
     |	
     |--PRO_E_NUM_AXES               Non-redefinable, Optional element
     |
     |--PRO_E_MACH_HEAD              Optional element, applicable when workcell
     |                               is multi-axis LATHE or MILL_N_TRN
     |                               Non-redefinable
     |
     |--PRO_E_TURN_OPTION	     Non-redefinable
     |				     For turning: outside, inside and face
     |
     |--PRO_E_OPERATION
     |
     |--PRO_E_FIXTURE                 Optional element
     |
     |--PRO_E_FEAT_NAME               Optional element
     |
     |--PRO_E_COMMENTS                Optional element
     |
     |--PRO_E_TOOL
     |
     |--PRO_E_CUSTOM_CYCLE
     |
     |--PRO_E_MFG_PARAMS
     |    |
     |    |--PRO_E_MFG_PARAM
     |         |
     |         |--PRO_E_MFG_PARAM_NAME
     |         |
     |         |--PRO_E_MFG_PARAMVAL
     |
     |--PRO_E_CSYS
     |
     |--PRO_E_RETRACT
     |
     |--PRO_E_RETRACT_SURFACE
     |    |
     |    |-- PRO_E_RETRACT_SURFACE_TYPE
     |    |
     |	  |-- PRO_E_RETRACT_SURFACE_REF
     |	  |
     |	  |-- PRO_E_RETRACT_SURFACE_ORIENT
     |	  |
     |	  |-- PRO_E_RETRACT_SURFACE_VALUE
     |
     |
     |--PRO_E_VOLUME                  Required for volume milling sequences
     |
     |--PRO_E_SURFACES                Required for surface milling sequences
     |
     |--PRO_E_HOLESETS                Required for holemaking sequences
     |    |                             (see note 6 for further description)
     |    |--PRO_E_HOLESET
     |         |    
     |         |--PRO_E_HOLESET_ID
     |         |
     |         |--PRO_E_HOLESET_TYPE
     |         |
     |         |--PRO_E_HOLESET_START
     |         |    |
     |         |    |--PRO_E_HOLESET_START_TYPE
     |         |    |
     |         |    |--PRO_E_HOLESET_START_SURFACE
     |         |
     |         |--PRO_E_HOLESET_END
     |         |    |
     |         |    |--PRO_E_HOLESET_END_TYPE
     |         |    |
     |         |    |--PRO_E_HOLESET_END_MEASURE_BY
     |         |    |
     |         |    |--PRO_E_HOLESET_END_SURFACE
     |         |    |
     |         |    |--PRO_E_HOLESET_DEPTH_VALUE
     |         |    |
     |         |    |--PRO_E_HOLESET_CSINK_DIAM
     |         |    |
     |         |    |--PRO_E_HOLESET_USE_BRKOUT_DIST
     |         |
     |         |--PRO_E_HOLESET_DEPTH
     |         |    |
     |         |    |--PRO_E_HOLESET_DEPTH_TYPE
     |         |    |
     |         |    |--PRO_E_HOLESET_DEPTH_BY_TYPE
     |         |    |
     |         |    |--PRO_E_HOLESET_DEPTH_PLATES
     |         |    |    |
     |         |    |    |--PRO_E_HOLESET_DEPTH_PLATE
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_PLATE_START
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_PLATE_END
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_PLATE_DEPTH
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_PLATE_CDIAM
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_PLATE_BRKOUT
     |         |    |
     |         |    |--PRO_E_HOLESET_EDGE_BREAK
     |         | 
     |         |--PRO_E_HOLESET_CUSTOM_CYCLE_PLATES
     |         |    |
     |         |    |--PRO_E_HOLESET_CUSTOM_CYCLE_REFERENCES
     |         |    |    |
     |         |    |    |--PRO_E_HOLESET_CUSTOM_CYCLE_REF
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_CUSTOM_CYCLE_PLATE_NAME
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_SEL
     |         |    |         |
     |         |    |         |--PRO_E_HOLESET_CUSTOM_CYCLE_REF_Z_OFFSET
     |         |    |
     |         |    |--PRO_E_HOLESET_CUSTOM_CYCLE_VARIABLES
     |         |         |
     |         |         |--PRO_E_HOLESET_CUSTOM_CYCLE_VAR
     |         |              |
     |         |              |--PRO_E_HOLESET_CUSTOM_CYCLE_PLATE_NAME
     |         |              |
     |         |              |--PRO_E_HOLESET_CUSTOM_CYCLE_VAR_VALUE
     |         |
     |         |--PRO_E_DRILL_PART_DATA
     |         |    |
     |         |    |--PRO_E_DRILL_PARTS
     |         |    |
     |         |    |--PRO_E_AUTO_SEL_DRILL_PARTS
     |         |
     |         |--PRO_E_HOLESET_SELECTION_RULES
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_BY_TABLE
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_PNTS_ON_SURFACES
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_INDIV_PNTS
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_PNTS_BY_FEATURE
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_PROJECT_SURFACES
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_MAX_PROJECT_DIST
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_UNSEL_PNTS
     |         |    |
     |	       |    |--PRO_E_HOLESET_SEL_BY_TABLE
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_AUTO_CHAMFER
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_INDIV_AXES
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_UNSEL_AXES
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_AXIS_PATTS
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_DRILL_GROUPS
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_BY_DIAMETERS
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_BY_SURFACES
     |         |    |
     |         |    |--PRO_E_HOLESET_SEL_BY_PARAMS
     |         |         |
     |         |         |--PRO_E_HOLESET_SEL_BY_PARAM
     |         |              |
     |         |              |--PRO_E_HOLESET_SEL_PARAM_NAME
     |         |              |
     |         |              |--PRO_E_HOLESET_SEL_PARAM_VAL
     |         |              |
     |         |              |--PRO_E_HOLESET_SEL_PARAM_REL
     |         |          
     |         |--PRO_E_HOLESET_TIP_CTRL_PNT
     |         |
     |         |--PRO_E_HOLESET_START_HOLE
     |         |
     |         |--PRO_E_HOLESET_UNFLIPPED_AXES
     |         |
     |         |--PRO_E_HOLESET_FLIPPED_AXES
     |
     |--PRO_E_REF_NCSEQ
     |
     |--PRO_E_NCL_COMMANDS
     |     |
     |     |--PRO_E_NCL_COMMAND
     |
     |--PRO_E_STOCK_BOUND_COMP
     |     |
     |     |--PRO_E_STOCK_BOUND_SKETCH
     |     |
     |     |--PRO_E_STOCK_BOUND_WP_SEL
     |
     |--PRO_E_TURN_PROF_COMP
     |     |
     |     |--PRO_E_TURN_PROF_CRV
     |     |
     |     |--PRO_E_TURN_PROF_ST_EXT
     |     |
     |     |--PRO_E_TURN_PROF_EN_EXT
     |
     |--PRO_E_START
     |
     |--PRO_E_END

NC Sequence Elements Table
--------------------------------------------------------------------------------
Element Id             Element Name     Data Type             Valid Values
                                        (PRO_VALUE_TYPE)
--------------------------------------------------------------------------------
PRO_E_FEAT_TYPE       Feature type          INT           PRO_FEAT_MILL
                                                          PRO_FEAT_DRILL

PRO_E_NCSEQ_TYPE      NC Sequence Type      INT           ProNcseqType

PRO_E_HOLEMAKING_TYPE Holemaking type       INT           ProHolemakingType

PRO_E_HOLE_CYCLE_TYPE Holemaking cycle      INT           ProHolemakingCycleType
                      type

PRO_E_PECK_TYPE       Peck type             INT           ProHolemakingPeckType

PRO_E_DRILL_MODE      Drill Mode            INT           ProHolemakingMode

PRO_E_NUM_AXES        Number of axes        INT           See note 1

PRO_E_MACH_HEAD       Machine head          INT           ProMachHead

PRO_E_TURN_OPTION     turn option type	    INT		  ProTurnOptionType

PRO_E_OPERATION       Mfg operation         INT           Operation feature id

PRO_E_FIXTURE         Fixture setup         INT           Fixture setup feature
                                                          id
PRO_E_FEAT_NAME       Feature Name          WSTRING       Feature name

PRO_E_COMMENTS        Comments              WSTRING ARRAY Paragraph of text

PRO_E_TOOL            Tool                  WSTRING       Tool ID

PRO_E_CUSTOM_CYCLE    Cycle Type	    WSTRING       Customized cycle Name

PRO_E_MFG_PARAMS      Sequence params       ARRAY

PRO_E_MFG_PARAM       Mfg param             COMPOUND

PRO_E_MFG_PARAM_NAME  Mfg param name        STRING        User-visible
                                                          mfg param names
PRO_E_MFG_PARAMVAL    Mfg param value  INT/DOUBLE/WSTRING See note 2

PRO_E_CSYS            Sequence Csys         SELECTION     NC Seq Csys selection

PRO_E_RETRACT         Retraction Plane      INT           Retraction plane id

PRO_E_RETRACT_SURFACE Retraction Surface    COMPOUND      See note 9

PRO_E_RETRACT_SURFACE_TYPE                  INT           ProRetractSurfaceType

PRO_E_RETRACT_SURFACE_REF                   SELECTION     See note 9

PRO_E_RETRACT_SURFACE_ORIENT                INT           ProRetractSurfaceOrient

PRO_E_RETRACT_SURFACE_VALUE                 DOUBLE        See note 9

PRO_E_VOLUME          Volume                INT           Volume base feature id

PRO_E_SURFACES        Surfaces              POINTER       Pointer using API

PRO_E_START           Sequence start point  SELECTION     See note 3

PRO_E_END             Sequence end point    SELECTION     See note 3

PRO_E_HOLESETS        Hole Sets             ARRAY         See notes 4 and 6

PRO_E_HOLESET                               COMPOUND

PRO_E_HOLESET_ID                            INT

PRO_E_HOLESET_TYPE                          INT           ProHolesetType

PRO_E_HOLESET_START                         COMPOUND

PRO_E_HOLESET_START_TYPE		    INT		  ProDrillStartType

PRO_E_HOLESET_START_SURFACE                 SELECTION     surfaces/quilts

PRO_E_HOLESET_END                           COMPOUND

PRO_E_HOLESET_END_TYPE			    INT		  ProDrillEndType

PRO_E_HOLESET_END_MEASURE_BY                INT           ProDrillDepthByType

PRO_E_HOLESET_END_SURFACE                   SELECTION     surfaces/quilts

PRO_E_HOLESET_DEPTH_VALUE                   DOUBLE        positive numbers

PRO_E_HOLESET_CSINK_DIAM                    DOUBLE        positive numbers

PRO_E_HOLESET_USE_BRKOUT_DIST		    BOOLEAN

PRO_E_HOLESET_DEPTH                         COMPOUND

PRO_E_HOLESET_DEPTH_BY_TYPE                 INT           ProDrillDepthByType

PRO_E_HOLESET_DEPTH_TYPE                    INT           ProDrillDepthType

PRO_E_HOLESET_DEPTH_PLATES                  ARRAY

PRO_E_HOLESET_DEPTH_PLATE                   COMPOUND

PRO_E_HOLESET_PLATE_START                   SELECTION     surfaces/quilts

PRO_E_HOLESET_PLATE_END                     SELECTION     surfaces/quilts

PRO_E_HOLESET_PLATE_DEPTH                   DOUBLE        positive numbers

PRO_E_HOLESET_PLATE_CDIAM                   DOUBLE        positive numbers

PRO_E_HOLESET_PLATE_BRKOUT                  BOOLEAN

PRO_E_DRILL_PART_DATA                       COMPOUND

PRO_E_HOLESET_EDGE_BREAK                    DOUBLE        positive numbers

PRO_E_DRILL_PARTS                           SELECTION ARRAY       solids

PRO_E_AUTO_SEL_DRILL_PARTS                  BOOLEAN

PRO_E_HOLESET_SELECTION_RULES               COMPOUND

PRO_E_HOLESET_SEL_PNTS_ON_SURFACES	    SELECTION ARRAY       surfaces

PRO_E_HOLESET_SEL_INDIV_PNTS                SELECTION ARRAY       points

PRO_E_HOLESET_SEL_UNSEL_PNTS                SELECTION ARRAY       points

PRO_E_HOLESET_SEL_PNTS_BY_FEATURE	    SELECTION ARRAY    datum point featuress

PRO_E_HOLESET_SEL_PROJECT_SURFACES	    SELECTION ARRAY       surfaces

PRO_E_HOLESET_SEL_MAX_PROJECT_DIST	    DOUBLE        positive numbers

PRO_E_HOLESET_SEL_AUTO_CHAMFER              BOOLEAN

PRO_E_HOLESET_SEL_INDIV_AXES                SELECTION ARRAY       axes

PRO_E_HOLESET_SEL_UNSEL_AXES                SELECTION ARRAY       axes

PRO_E_HOLESET_SEL_AXIS_PATTS                SELECTION ARRAY       axes

PRO_E_HOLESET_SEL_DRILL_GROUPS              INT ARRAY   drill group feature ids

PRO_E_HOLESET_SEL_BY_DIAMETERS              DOUBLE ARRAY  positive numbers

PRO_E_HOLESET_SEL_BY_TABLE		    COMPOUND

PRO_E_HOLESET_SEL_BY_SURFACES               SELECTION ARRAY       surfaces

PRO_E_HOLESET_SEL_BY_PARAMS                 ARRAY

PRO_E_HOLESET_SEL_BY_PARAM                  COMPOUND

PRO_E_HOLESET_SEL_PARAM_NAME                WSTRING

PRO_E_HOLESET_SEL_PARAM_VAL                 INT/BOOL/DOUBLE/WSTRING

PRO_E_HOLESET_SEL_PARAM_REL                 INT           ProHolesetParamRels

PRO_E_HOLESET_TIP_CTRL_PNT		    INT

PRO_E_HOLESET_START_HOLE                    SELECTION

PRO_E_HOLESET_UNFLIPPED_AXES                SELECTION ARRAY   axes   See note 7.

PRO_E_HOLESET_FLIPPED_AXES                  SELECTION ARRAY   axes   See note 7.

PRO_E_HOLESET_CUSTOM_PLATES                 ARRAY

PRO_E_HOLESET_CUSTOM_PLATE                  COMPOUND

PRO_E_HOLESET_CUSTOM_REFERENCE              BOOLEAN

PRO_E_HOLESET_CUSTOM_SURFACE                SELECTION     surfaces

PRO_E_HOLESET_CUSTOM_REF_ID		    INT

PRO_E_HOLESET_CUSTOM_Z_OFFSET               DOUBLE        positive numbers

PRO_E_HOLESET_CUSTOM_VALUE                  DOUBLE 

PRO_E_HOLESET_CUSTOM_CYCLE_PLATES           COMPOUND

PRO_E_HOLESET_CUSTOM_CYCLE_REFERENCES       ARRAY

PRO_E_HOLESET_CUSTOM_CYCLE_REF              COMPOUND

PRO_E_HOLESET_CUSTOM_CYCLE_PLATE_NAME	    WSTRING

PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT	    INT		  ProCustomRefOption

PRO_E_HOLESET_CUSTOM_CYCLE_REF_SEL	    SELECTION     surfaces/quilts

PRO_E_HOLESET_CUSTOM_CYCLE_REF_Z_OFFSET     DOUBLE        positive numbers

PRO_E_HOLESET_CUSTOM_CYCLE_VARIABLES        ARRAY

PRO_E_HOLESET_CUSTOM_CYCLE_VAR		    COMPOUND

PRO_E_HOLESET_CUSTOM_CYCLE_PLATE_NAME	    WSTRING

PRO_E_HOLESET_CUSTOM_CYCLE_VAR_VALUE	    DOUBLE        positive numbers

PRO_E_HOLES           Holes                 POINTER       See note 5.

PRO_E_NCL_COMMANDS                          ARRAY          

PRO_E_REF_NCSEQ                             INT

PRO_E_STOCK_BOUND			    COMPOUND

PRO_E_STOCK_BOUND_SKETCH		    POINTER	Sketch section

PRO_E_STOCK_BOUND_WP_SEL		    SELECTION 	workpiece selection

PRO_E_TURN_PROF				    COMPOUND	

PRO_E_TURN_PROF_CRV			    int		turn profile feature id

PRO_E_TURN_PROF_ST_EXT			    int		turn profile start 
							extension direction
PRO_E_TURN_PROF_EN_EXT			    int		turn profile end 
							extension direction
				( Both have values of type ProTurnProfExtType )	    
--------------------------------------------------------------------------------

NOTES:

1. The range of valid num axes is dependent on the sequence's workcell.
   Please refer to the manufacturing user's guide for valid settings in
   the user interface.

2. This type of element can have an integer value, a double value or a
   wide string value. Please refer to manufacturing user's guide for
   appropriate values.
------------------------------------------------
   User Interface        Programmatic Value
------------------------------------------------
     2 axis                     2
     3 axis                     3
     4 axis                     4
     5 axis                     5

3. Selection should be initialized to the datum point's identifier
   (NOT the feature identifier!).

4. PRO_E_HOLESETS gives much more powerful control than PRO_E_HOLES, but its
   support of drill points sets is still limited.  Through PRO_E_HOLESETS it
   is possible to determine which drill point sets exist in a feature, delete
   them, or overwrite them with drill axes sets.

5. PRO_E_HOLES is provided solely for compatibility with old code.  Such code
   should be updated to the more complete and easier to use PRO_E_HOLESETS
   element.

6. Adequate descriptions for the PRO_E_HOLESETS sub-elements could not be
   fit into the element tree above and are therefore given here.  Note that
   basic element type information is still found in the table above.

     PRO_E_HOLESETS                 contains data for all sequence holesets
     PRO_E_HOLESET                  data for a single holeset
     PRO_E_HOLESET_ID               id of a holeset
     PRO_E_HOLESET_TYPE             type of a holeset
     PRO_E_HOLESET_DEPTH            depth data for a holeset of a web drilling
     PRO_E_HOLESET_DEPTH_BY_TYPE    whether depth is calculated by the tool's
                                    tip or its shoulder
     PRO_E_HOLESET_DEPTH_TYPE       depth algorithm to use
     PRO_E_HOLESET_DEPTH_PLATES     set of PRO_E_HOLESET_DEPTH_PLATE elements
                                      - not used for auto or thru-all depth
                                        types
                                      - contains only one pair if not web
                                        drilling
     PRO_E_HOLESET_DEPTH_PLATE      start and end feed height data; contains
                                    PRO_E_HOLESET_PLATE_START and one of the
                                    following:
                                      PRO_E_HOLESET_PLATE_END
                                      PRO_E_HOLESET_PLATE_DEPTH
                                      PRO_E_HOLESET_PLATE_CDIAM
                                    may also optionally contain
                                      PRO_E_HOLESET_PLATE_BRKOUT
     PRO_E_HOLESET_PLATE_START      starting surface or quilt
     PRO_E_HOLESET_PLATE_END        ending surface of quilt
     PRO_E_HOLESET_PLATE_DEPTH      depth to drill from start
     PRO_E_HOLESET_PLATE_CDIAM      countersink diameter (applicable to
                                    countersink sequences only)
     PRO_E_HOLESET_PLATE_BRKOUT     whether to drill an additional
                                    BREAKOUT_DISTANCE [a manufacturing sequence
                                    parameter] deeper (not applicable to
                                    countersink sequences)
     PRO_E_HOLESET_EDGE_BREAK       amount by which to break edges for a by
                                    edge-break holeset (applicable to
                                    countersink sequences only)


     PRO_E_HOLESET_START	    drilling start data for a holeset
     PRO_E_HOLESET_START_TYPE	    start surface algorithm to use
     PRO_E_HOLESET_START_SURFACE    starting surface or quilt
     PRO_E_HOLESET_END		    depth data for a holeset
     PRO_E_HOLESET_END_TYPE	    depth algorithm to use
     PRO_E_HOLESET_END_MEASURE_BY   whether depth is calculated by the tool's
                                    tip or its shoulder
     PRO_E_HOLESET_END_SURFACE	    ending surface of quilt
     PRO_E_HOLESET_DEPTH_VALUE	    depth to drill from start
     PRO_E_HOLESET_CSINK_DIAM	    countersink diameter (applicable to
                                    countersink sequences only)
     PRO_E_HOLESET_USE_BRKOUT_DIST  whether to drill an additional
                                    BREAKOUT_DISTANCE [a manufacturing sequence
                                    parameter] deeper (not applicable to
                                    countersink sequences)
     PRO_E_DRILL_PART_DATA          which parts to consider for auto and
                                    thru-all depth calculations
     PRO_E_DRILL_PARTS              a list of individual parts
     PRO_E_AUTO_SEL_DRILL_PARTS     whether to select all appropriate parts
                                    automatically; if true PRO_E_DRILL_PARTS is
                                    ignored
     PRO_E_HOLESET_SELECTION_RULES  rules by which to select axes/points;
				    point and axes rules should not be mixed.
				    whether you can use point or axes will
				    be decided by PRO_E_HOLESET_TYPE.
				    except as noted below, axes must satisfy
				    all specified rules in order to be selected
     PRO_E_HOLESET_SEL_PNTS_ON_SURFACES select points which lie on selected
					surfaces
     PRO_E_HOLESET_SEL_INDIV_PNTS   individual point selections
     PRO_E_HOLESET_SEL_PNTS_BY_FEATURE individual datum point feature selections
     PRO_E_HOLESET_SEL_PROJECT_SURFACES required only for five-axis, and if
				        we have some individual point selection.
					point will be allowed only if it lie 
					on the surface, and surface normal will
					be user for drilling direction.
     PRO_E_HOLESET_SEL_MAX_PROJECT_DIST accuracy used to determine whether a 
					point lie on a surface.
     PRO_E_HOLESET_SEL_UNSEL_PNTS   individual points to exclude; reject even
				    if selected by feature/surface rule.
     PRO_E_HOLESET_SEL_AUTO_CHAMFER select axes with chamfers matching the
                                    sequence's tool (countersink sequences only)
     PRO_E_HOLESET_SEL_INDIV_AXES   individual axis selections; axes selected
                                    this way do not have to meet other selection
                                    criteria
     PRO_E_HOLESET_SEL_UNSEL_AXES   individual axes to exclude; reject even if
                                    selected by another rule
     PRO_E_HOLESET_SEL_AXIS_PATTS   axis pattern selections; axes selected this
                                    way do not have to meet other selection
                                    criteria
     PRO_E_HOLESET_SEL_DRILL_GROUPS select axes contained in drill groups
     PRO_E_HOLESET_SEL_BY_DIAMETERS select axes for surfaces of given diameters
     PRO_E_HOLESET_SEL_BY_TABLE     whether hole selection is by auto hole table
     PRO_E_HOLESET_SEL_BY_SURFACES  select axes of holes on given surfaces
     PRO_E_HOLESET_SEL_BY_PARAMS    select axes of features which match one of
                                    the specified parameter criteria
     PRO_E_HOLESET_SEL_BY_PARAM     a parameter criteria
     PRO_E_HOLESET_SEL_PARAM_NAME   parameter name
     PRO_E_HOLESET_SEL_PARAM_VAL    parameter value
     PRO_E_HOLESET_SEL_PARAM_REL    criteria relation
     PRO_E_HOLESET_START_HOLE       hole to drill first
     PRO_E_HOLESET_UNFLIPPED_AXES   list of axes that should be drilled as per
                                    orientation of the axis entities; see note 7
     PRO_E_HOLESET_FLIPPED_AXES     list of axes that should be drilled opposite
                                    of the orientation of the axis entities;
                                    see note 7

7. The elements PRO_E_HOLESET_FLIPPED_AXES and PRO_E_HOLESET_UNFLIPPED_AXES
   only apply to 5-axis drilling.  In 5-axis drilling, the system will attempt
   (usually successfully) to determine the appropriate machining approach
   directions for all selected axes whose approach direction is not specified
   by these elements.  These elements therefore usually do not need to be
   specified.  NOTE: Axes listed by these elements are only drilled if they
   meet the critera specified by PRO_E_HOLESET_SELECTION_RULES.

8. The PRO_NCSEQ_TRAJ_MILL NC Sequence type is not fully supported in 
   Creo Parametric TOOLKIT yet.
   
9. PRO_E_RETRACT_SURFACE can be used instead of PRO_E_RETRACT.

   --------------------------------------------------------
    PRO_E_RETRACT_SURFACE_TYPE  | PRO_E_RETRACT_SURFACE_REF
   --------------------------------------------------------
   PRO_RETRACT_SURFACE_PLANE    |  csys,face(plane)
   PRO_RETRACT_SURFACE_CYLINDER |     axis,csys
   PRO_RETRACT_SURFACE_SPHERE   |     point,csys
   
   PRO_E_RETRACT_SURFACE_ORIENT is applicable to 
   PRO_RETRACT_SURFACE_CYLINDER only.

   PRO_E_RETRACT_SURFACE_VALUE is an offset for PRO_E_RETRACT_SURFACE_PLANE and
                               a radius for PRO_RETRACT_SURFACE_CYLINDER or
                                            PRO_RETRACT_SURFACE_SPHERE
\******************************************************************************/


PRO_BEGIN_C_DECLS


typedef                struct pro_model_item  ProNcseq;

typedef enum  Pro_HolemakingCycleType  {
  PRO_HOLE_MK_CYCLE_STD        = 4,
  PRO_HOLE_MK_CYCLE_DEEP       = 5,
  PRO_HOLE_MK_CYCLE_FIXED      = 7,
  PRO_HOLE_MK_CYCLE_FLOATING   = 11,
  PRO_HOLE_MK_CYCLE_BREAK_CHIP = 12,
  PRO_HOLE_MK_CYCLE_WEB        = 15,
  PRO_HOLE_MK_CYCLE_BACK       = 17
}  ProHolemakingCycleType;
 
typedef enum  Pro_HolemakingPeckType  {
  PRO_HOLE_MK_PECK_DEFAULT  = -1,
  PRO_HOLE_MK_PECK_CONSTANT = 0,
  PRO_HOLE_MK_PECK_VARIABLE = 14
}  ProHolemakingPeckType;

typedef enum Pro_HolesetParamRels  {
  PRO_HOLESET_PARAM_REL_EQUAL     = 1,
  PRO_HOLESET_PARAM_REL_NOT_EQUAL = 2,
  PRO_HOLESET_PARAM_REL_LARGER    = 3,
  PRO_HOLESET_PARAM_REL_SMALLER   = 4
}  ProHolesetParamRels;

typedef enum Pro_TurnProfExtType  {
  PRO_E_TURN_PROF_EXT_NONE        = 0,
  PRO_E_TURN_PROF_EXT_PARALLEL    = 1,
  PRO_E_TURN_PROF_EXT_PERPEND     = 2
}  ProTurnProfExtType;

typedef enum Pro_TurnProfMaterialSide  {
  PRO_E_TURN_PROF_MAT_ON_RIGHT = 0,
  PRO_E_TURN_PROF_MAT_ON_LEFT  = 1
}  ProTurnProfMaterialSide;

typedef enum Pro_RetractSurfaceType  {
  PRO_RETRACT_SURFACE_UNDEF_TYPE = -1,
  PRO_RETRACT_SURFACE_PLANE      =  0,
  PRO_RETRACT_SURFACE_CYLINDER   =  1,
  PRO_RETRACT_SURFACE_SPHERE     =  2,
  PRO_RETRACT_SURFACE_REVOLVED   =  3
}  ProRetractSurfaceType;

typedef enum Pro_RetractSurfaceOrient {
   PRO_RETRACT_SURFACE_UNDEF_DIR = -1,
   PRO_RETRACT_SURFACE_X_DIR     =  0,
   PRO_RETRACT_SURFACE_Y_DIR     =  1,
   PRO_RETRACT_SURFACE_Z_DIR     =  2	       
} ProRetractSurfaceOrient;
    
/*  PRO_HOLE_MK_ON_MILL = 0 represent drilling on mill for 5-axis_mil_turn &
    PRO_HOLE_MK_ON_TURN = 1 represent drilling on turn for 5-axis_mil_turn*/

typedef enum Pro_HolemakingMode {
   PRO_HOLE_MK_ON_MILL =  0,
   PRO_HOLE_MK_ON_TURN =  1
} ProHolemakingMode;

extern ProError  ProFeatureIsNcseq (PRO_CONST_ARG  ProFeature  *feat,
                                                     ProBoolean  *p_is_ncseq);
/*
   Purpose:  Determines whether a feature is an NC sequence.

   Input Arguments:
      feat          - The handle to a feature.

   Output Arguments:
      p_is_ncseq    - This is PRO_B_TRUE if the feature is an NC sequence.
                      Otherwise, this is PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR     - The function successfully retrieved the
                            information.
      PRO_TK_BAD_INPUTS   - The input argument is invalid.
      PRO_TK_INVALID_TYPE - The specified handle is not a feature.
*/

extern ProError  ProNcseqTypeGet ( PRO_CONST_ARG ProNcseq         *seq,  
                                            ProLine           r_type_name);
/*
   Purpose:  Retrieves the type name of the specified NC sequence.

   Input Arguments:
      seq            - The handle to an NC sequence feature

   Output Arguments:
      r_type_name    - The type name of the NC sequence 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProFeatureIsNcseq()
*/


extern ProError  ProNcseqNumGet  ( PRO_CONST_ARG ProNcseq  *seq,
                                               int       *r_seq_num);
/*
   Purpose:  Retrieves the number of the specified NC sequence.

   Input Arguments:
      seq            - The handle to an NC sequence feature

   Output Arguments:
      r_seq_num      - The number of the NC sequence

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProFeatureIsNcseq() 

*/

extern ProError  ProNcseqCutTimeGet   ( PRO_CONST_ARG ProNcseq  *seq,
                                                       double    *r_time);
/*
   Purpose: Retrieves the cutting time for the specified NC sequence feature.

   Input Arguments:
      seq            - The handle to an NC sequence feature

   Output Arguments:
      r_time         - The cutting time

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The cutting time information was not present.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProFeatureIsNcseq()
*/


extern ProError  ProNcseqRemovedVolGet  (PRO_CONST_ARG ProNcseq   *seq,
                                                          double      *r_vol);
/*
   Purpose:  Retrieves the volume of material removed by the specified
             NC sequence feature.

   Input Arguments:
      seq            - The handle to an NC sequence feature

   Output Arguments:
      r_vol          - The volume of material removed

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_E_NOT_FOUND - The data for the volume of material removed was
                           not present.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProFeatureIsNcseq()
*/


extern ProError  ProNcseqToolpathDisplay  ( PRO_CONST_ARG ProNcseq *seq);
/*
   Purpose:  Displays the toolpath of the specified NC sequence on the screen.

   Input Arguments:
      seq            - The handle to an NC sequence feature

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the
                             information.
      PRO_TK_GENERAL_ERROR - The toolpath display failed.
      PRO_TK_BAD_INPUTS    - The argument is invalid.

   See Also:
      ProFeatureIsNcseq()

*/

PRO_END_C_DECLS


#endif /* PRONCSEQ_H */
