#ifndef PROHOLE_H
#define PROHOLE_H

/* 
  Element Tree changes for Release 2002:
  
  1. PRO_E_HLE_SKETCHER element has been replaced by standard sketcher element - PRO_E_SKETCHER.
  2. Multi-valued elements, as in PRO_E_HLE_DIM_REF1 and PRO_E_HLE_DIM_REF2,
     are no longer needed and hence not supported. 
  3. Hole feature has been enhanced by addition of Exit Countersink option. 
*/

/*
   Creo Parametric TOOLKIT declarations related to hole feature.
*/



#include <ProFeature.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS


/*****************************************************************************

Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_FEATURE_FORM
     |   
     |--PRO_E_HLE_COM
     |    |--PRO_E_HLE_TYPE_NEW 
     |    |--PRO_E_HLE_STAN_TYPE
     |    |--PRO_E_HLE_THRDSERIS
     |    |--PRO_E_HLE_FITTYPE  
     |    |--PRO_E_HLE_SCREWSIZE
     |    |--PRO_E_HLE_ADD_THREAD 
     |    |--PRO_E_HLE_ADD_CBORE
     |    |--PRO_E_HLE_ADD_CSINK
     |    |--PRO_E_HLE_MAKE_LIGHTWT
     |    |
     |    |--PRO_E_DIAMETER
     |    |
     |    |--PRO_E_HOLE_STD_DEPTH
     |    |    |--PRO_E_HOLE_DEPTH_TO
     |    |    |    |--PRO_E_HOLE_DEPTH_TO_TYPE
     |    |    |    |--PRO_E_EXT_DEPTH_TO_VALUE
     |    |    |    |--PRO_E_EXT_DEPTH_TO_REF
     |    |    |--PRO_E_HOLE_DEPTH_FROM
     |    |         |--PRO_E_HOLE_DEPTH_FROM_TYPE
     |    |         |--PRO_E_EXT_DEPTH_FROM_VALUE
     |    |         |--PRO_E_EXT_DEPTH_FROM_REF
     |    |
     |    |--PRO_E_HLE_HOLEDIAM
     |    |--PRO_E_HLE_DEPTH
     |    |--PRO_E_HLE_CSINKANGLE
     |    |--PRO_E_HLE_CBOREDEPTH
     |    |--PRO_E_HLE_CBOREDIAM
     |    |--PRO_E_HLE_CSINKDIAM
     |    |--PRO_E_HLE_DEPTH_DIM_TYPE
     |    |--PRO_E_HLE_THRD_DEPTH
     |    |--PRO_E_HLE_THRDDEPTH
     |    |--PRO_E_HLE_DRILLANGLE
     |    |--PRO_E_HLE_DRILLDEPTH
     |    |--PRO_E_STD_HOLE_DEPTH_REF
     |    |--PRO_E_SKETCHER
     |    |--PRO_E_HLE_CRDIR_FLIP
     |    |--PRO_E_HLE_ADD_EXIT_CSINK
     |    |--PRO_E_HLE_EXIT_CSINKANGLE
     |    |--PRO_E_HLE_EXIT_CSINKDIAM
     |    |--PRO_E_HLE_ADD_NOTE
     |    |--PRO_E_HOLE_NOTE
     |    |--PRO_E_HLE_TOP_CLEARANCE
     |
     |--PRO_E_HLE_PLACEMENT
     |    |--PRO_E_HLE_PRIM_REF
     |    |--PRO_E_HLE_PL_TYPE  
     |    |--PRO_E_HLE_DIM_REF1 
     |    |--PRO_E_HLE_PLC_ALIGN_OPT1
     |    |--PRO_E_HLE_DIM_DIST1
     |    |--PRO_E_HLE_DIM_REF2
     |    |--PRO_E_HLE_PLC_ALIGN_OPT2
     |    |--PRO_E_HLE_DIM_DIST2
     |    |--PRO_E_LIN_HOLE_DIR_REF
     |    |--PRO_E_HLE_AXIS     
     |    |--PRO_E_HLE_REF_PLANE
     |    |--PRO_E_HLE_REF_ANG
     |    |--PRO_E_HLE_DIM_DIA  
     |    |--PRO_E_HLE_DIM_RAD  
     |    |--PRO_E_HLE_DIM_LIN  
     |    |--PRO_E_HLE_NORM_PLA 
     |    |--PRO_E_HLE_NORM_OFFST   
     |    |--PRO_E_HLE_PLCMNT_PLANE   
     |    |--PRO_E_HLE_REF_PLANE_1
     |    |--PRO_E_HLE_REF_ANG_1
     |    |--PRO_E_HLE_FT_DIR_REF
     |    |--PRO_E_HLE_FT_DIR_OPT
     |
     |--PRO_E_INT_PARTS
     |
     |--PRO_E_PATTERN
     |
     |--PRO_E_STD_FEATURE_NAME


Feature elements table

------------------------------------------------------------------------
Element Id                  Element Name         Data Type     
------------------------------------------------------------------------

PRO_E_FEATURE_TYPE          Feature Type         PRO_VALUE_TYPE_INT  
PRO_E_FEATURE_FORM          Feature Form         PRO_VALUE_TYPE_INT
PRO_E_HLE_COM               Hole                 Compound 
PRO_E_HLE_TYPE_NEW          Hole Type            PRO_VALUE_TYPE_INT
PRO_E_HLE_STAN_TYPE         Standard Type        PRO_VALUE_TYPE_INT
PRO_E_HLE_THRDSERIS         Thread Series        PRO_VALUE_TYPE_INT
PRO_E_HLE_FITTYPE           Fit Type             PRO_VALUE_TYPE_INT
PRO_E_HLE_SCREWSIZE         Screw Size           PRO_VALUE_TYPE_INT
PRO_E_HLE_ADD_THREAD        Add Thread           PRO_VALUE_TYPE_INT
PRO_E_HLE_ADD_CBORE         Add Counterbore      PRO_VALUE_TYPE_INT
PRO_E_HLE_ADD_CSINK         Add Countersink      PRO_VALUE_TYPE_INT
PRO_E_HLE_MAKE_LIGHTWT      Make light weight    PRO_VALUE_TYPE_INT
PRO_E_DIAMETER              Diameter             PRO_VALUE_TYPE_DOUBLE
PRO_E_HOLE_STD_DEPTH        Depth Element        Compound 
PRO_E_HOLE_DEPTH_TO         Depth Two            Compound 
PRO_E_HOLE_DEPTH_TO_TYPE    Depth Two            PRO_VALUE_TYPE_INT
PRO_E_EXT_DEPTH_TO_VALUE    Depth Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_EXT_DEPTH_TO_REF      Reference            PRO_VALUE_TYPE_SELECTION
PRO_E_HOLE_STD_DEPTH        Depth                Compound
PRO_E_HOLE_DEPTH_FROM       Depth One            Compound 
PRO_E_HOLE_DEPTH_FROM_TYPE  Depth One            PRO_VALUE_TYPE_INT
PRO_E_EXT_DEPTH_FROM_VALUE  Depth Value          PRO_VALUE_TYPE_DOUBLE
PRO_E_EXT_DEPTH_FROM_REF    Reference            PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_HOLEDIAM          Diameter             PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_DRILLANGLE        Drillhead Angle      PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_CSINKANGLE        Csink Angle          PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_CBOREDEPTH        Counterbore Depth    PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_CBOREDIAM         Counterbore Diameter PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_CSINKDIAM         Csink Diameter       PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_THRDDEPTH         Thread Depth         PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_DRILLDEPTH        Drill Depth          PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_THRD_DEPTH        Thread Depth         PRO_VALUE_TYPE_INT
PRO_E_HLE_DEPTH             Depth                PRO_VALUE_TYPE_INT
PRO_E_STD_HOLE_DEPTH_REF    Reference            PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_DEPTH_DIM_TYPE    Depth dim scheme     PRO_VALUE_TYPE_INT
PRO_E_SKETCHER              Sketcher             N/A
PRO_E_HLE_CRDIR_FLIP        Creation Direction   PRO_VALUE_TYPE_INT
PRO_E_HLE_ADD_EXIT_CSINK    Use Exit Countersink PRO_VALUE_TYPE_INT
PRO_E_HLE_EXIT_CSINKANGLE   Exit Csink Angle     PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_EXIT_CSINKDIAM    Exit Csink Diameter  PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_ADD_NOTE          Add Hole Note        PRO_VALUE_TYPE_INT
PRO_E_HOLE_NOTE             Hole Note            The element is not accessible 
                                                 through Creo Parametric TOOLKIT
PRO_E_HLE_TOP_CLEARANCE     Top Clearance        PRO_VALUE_TYPE_INT
PRO_E_HLE_PLACEMENT         Placement            N/A
PRO_E_HLE_PRIM_REF          Primary Reference    PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_PL_TYPE           Placement Options    PRO_VALUE_TYPE_INT
PRO_E_HLE_DIM_REF1          Dimension  Ref 1     PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_PLC_ALIGN_OPT1    Ref Align option1    PRO_VALUE_TYPE_INT
PRO_E_HLE_DIM_DIST1         Distance 1           PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_DIM_REF2          Dimension  Ref 2     PRO_VALUE_TYPE_SELECTION      
PRO_E_HLE_PLC_ALIGN_OPT2    Ref Align option2    PRO_VALUE_TYPE_INT
PRO_E_HLE_DIM_DIST2         Distance 2           PRO_VALUE_TYPE_DOUBLE
PRO_E_LIN_HOLE_DIR_REF      Ref Dir Reference    PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_AXIS              Axis                 PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_REF_PLANE         Reference Plane      PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_REF_ANG           Angle                PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_DIM_DIA           Diameter             PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_DIM_RAD           Radius               PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_DIM_LIN           Linear Distance      PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_NORM_PLA          Normal Plane         PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_NORM_OFFST        Offset               PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_PLCMNT_PLANE      Placement Plane      PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_REF_PLANE_1       Reference Plane      PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_REF_ANG_1         Angle                PRO_VALUE_TYPE_DOUBLE
PRO_E_HLE_FT_DIR_REF        Direction reference  PRO_VALUE_TYPE_SELECTION
PRO_E_HLE_FT_DIR_OPT        Direction option     PRO_VALUE_TYPE_INT
PRO_E_INT_PARTS             Intsct Parts         N/A
PRO_E_PATTERN               Pattern              N/A
PRO_E_STD_FEATURE_NAME      Feature Name         PRO_VALUE_TYPE_WSTRING

--------------------------------------------------------------------------------
Table Hole:1 : Common element for all type of hole and it's value
-------------------------------------------------------------------
| Element Id               | Value                                |
-------------------------------------------------------------------
| PRO_E_FEATURE_TYPE       | PRO_FEAT_HOLE                        |
|.................................................................|
| PRO_E_FEATURE_FORM       | of type ProHleType                   |
|                          | = PRO_HLE_TYPE_STRAIGHT              |
|                          |        for straight hole             |
|                          | = PRO_HLE_TYPE_SKETCHED              |
|                          |        for other type of hole        |
-------------------------------------------------------------------
--------------------------------------------------------------------------------
Table Hole:2 Elements required for PRO_E_HLE_COM compound element for
             different type of holes 
------------------------------------------------------------------------------
|          | Element Id                 | Comment                            |
------------------------------------------------------------------------------
| Straight : PRO_E_HLE_TYPE_NEW         : Mandatory                          |
|   Hole   : PRO_E_HLE_MAKE_LIGHTWT     : Mandatory                          |
|          : PRO_E_DIAMETER             : Mandatory                          |
|          : PRO_E_HOLE_STD_DEPTH       : Mandatory                          |
|          : PRO_E_HOLE_DEPTH_TO        : Mandatory                          |
|          : PRO_E_HOLE_DEPTH_TO_TYPE   : Mandatory                          |
|          : PRO_E_EXT_DEPTH_TO_VALUE   : Depends on PRO_E_HOLE_DEPTH_TO_TYPE|
|          : PRO_E_EXT_DEPTH_TO_REF     : Depends on PRO_E_HOLE_DEPTH_TO_TYPE|
|          : PRO_E_HOLE_DEPTH_FROM      : Mandatory                          |
|          : PRO_E_HOLE_DEPTH_FROM_TYPE : Mandatory                          |
|          : PRO_E_EXT_DEPTH_FROM_VALUE : Depends on PRO_E_HOLE_DEPTH_FROM_TYPE
|          : PRO_E_EXT_DEPTH_FROM_REF   : Depends on PRO_E_HOLE_DEPTH_FROM_TYPE
|          : PRO_E_HLE_TOP_CLEARANCE    : Mandatory                          |
|..........:............................:....................................|
| Sketch   : PRO_E_HLE_TYPE_NEW         : Mandatory                          |
|  Hole    : PRO_E_SKETCHER             : Mandatory                          |
|          : PRO_E_HLE_CRDIR_FLIP       : Mandatory                          |
|          : PRO_E_HLE_TOP_CLEARANCE    : Mandatory                          |
|..........:............................:....................................|
| Standard : PRO_E_HLE_TYPE_NEW         : Mandatory                          |
|  Tapped  : PRO_E_HLE_STAN_TYPE        : Mandatory                          |
|   Hole   : PRO_E_HLE_THRDSERIS        : Mandatory                          |
|          : PRO_E_HLE_FITTYPE          : Mandatory == PRO_HLE_CLOSE_FIT     |
|          : PRO_E_HLE_SCREWSIZE        : Mandatory                          |
|          : PRO_E_HLE_ADD_THREAD       : Mandatory                          |
|          : PRO_E_HLE_ADD_CBORE        : Mandatory                          |
|          : PRO_E_HLE_ADD_CSINK        : Mandatory                          |
|          : PRO_E_HLE_HOLEDIAM         : Mandatory                          |
|          : PRO_E_HLE_DRILLANGLE       : Required for variable depth hole   |
|          : PRO_E_HLE_CSINKANGLE       : Required for countersink option    |
|          : PRO_E_HLE_CBOREDEPTH       : Required for counterbore option    |
|          : PRO_E_HLE_CBOREDIAM        : Required for counterbore option    |
|          : PRO_E_HLE_CSINKDIAM        : Required for countersink option    |
|          : PRO_E_HLE_THRDDEPTH        : Mandatory ( even for a non threaded|
|          :                            : hole, or a thru threaded hole, for |
|          :                            : above two cases, element may not   |
|          :                            : have vaild value,required for UI ) |
|          : PRO_E_HLE_DRILLDEPTH       : Mandatory ( even for a thruall hole|
|          :                            : for this case, element may not     |
|          :                            : have vaild value,required for UI ) |
|          : PRO_E_HLE_THRD_DEPTH       : Required for threaded hole         |
|          : PRO_E_HLE_DEPTH            : Mandatory                          |
|          : PRO_E_STD_HOLE_DEPTH_REF   : Depends on PRO_E_HLE_DEPTH         |
|          : PRO_E_HLE_DEPTH_DIM_TYPE   : Depends on PRO_E_HLE_DEPTH         |
|          : PRO_E_HLE_CRDIR_FLIP       : Mandatory                          |
|          : PRO_E_HLE_ADD_EXIT_CSINK   : Required for Thru all hole         |
|          : PRO_E_HLE_EXIT_CSINKANGLE  : Required for exit countersink option
|          : PRO_E_HLE_EXIT_CSINKDIAM   : Required for exit countersink option
|          : PRO_E_HLE_ADD_NOTE         : Required for Hole note             |
|          : PRO_E_HOLE_NOTE            : Depends on PRO_E_HLE_ADD_NOTE      |
|          : PRO_E_HLE_TOP_CLEARANCE    : Mandatory                          |
|..........:............................:....................................|
| Standard : PRO_E_HLE_TYPE_NEW         : Mandatory                          |
| Clearance: PRO_E_HLE_STAN_TYPE        : Mandatory                          |
|   Hole   : PRO_E_HLE_THRDSERIS        : Mandatory                          |
|          : PRO_E_HLE_FITTYPE          : Mandatory                          |
|          : PRO_E_HLE_SCREWSIZE        : Mandatory                          |
|          : PRO_E_HLE_ADD_THREAD       : Mandatory                          |
|          : PRO_E_HLE_ADD_CBORE        : Mandatory                          |
|          : PRO_E_HLE_ADD_CSINK        : Mandatory                          |
|          : PRO_E_HLE_HOLEDIAM         : Mandatory                          |
|          : PRO_E_HLE_DRILLANGLE       : Required for variable depth hole   |
|          : PRO_E_HLE_CSINKANGLE       : Required for countersink option    |
|          : PRO_E_HLE_CBOREDEPTH       : Required for counterbore option    |
|          : PRO_E_HLE_CBOREDIAM        : Required for counterbore option    |
|          : PRO_E_HLE_CSINKDIAM        : Required for countersink option    |
|          : PRO_E_HLE_DEPTH            : Mandatory                          |
|          : PRO_E_HLE_CRDIR_FLIP       : Mandatory                          |
|          : PRO_E_HLE_ADD_EXIT_CSINK   : Required for Thru all hole         |
|          : PRO_E_HLE_EXIT_CSINKANGLE  : Required for exit countersink option
|          : PRO_E_HLE_EXIT_CSINKDIAM   : Required for exit countersink option
|          : PRO_E_HLE_ADD_NOTE         : Required for Hole note             |
|          : PRO_E_HOLE_NOTE            : Depends on PRO_E_HLE_ADD_NOTE      |
|          : PRO_E_HLE_TOP_CLEARANCE    : Mandatory                          |
|..........:............................:....................................|
| Custom   : PRO_E_HLE_TYPE_NEW         : Mandatory                          |
|  Hole    : PRO_E_HLE_ADD_CBORE        : Mandatory                          |
|          : PRO_E_HLE_ADD_CSINK        : Mandatory                          |
|          : PRO_E_HLE_HOLEDIAM         : Mandatory                          |
|          : PRO_E_HLE_DRILLANGLE       : Required for variable depth hole   |
|          : PRO_E_HLE_CSINKANGLE       : Required for countersink option    |
|          : PRO_E_HLE_CBOREDEPTH       : Required for counterbore option    |
|          : PRO_E_HLE_CBOREDIAM        : Required for counterbore option    |
|          : PRO_E_HLE_CSINKDIAM        : Required for countersink option    |
|          : PRO_E_HLE_DEPTH            : Mandatory                          |
|          : PRO_E_HLE_DEPTH_DIM_TYPE   : Depends on PRO_E_HLE_DEPTH         |
|          : PRO_E_HLE_CRDIR_FLIP       : Mandatory                          |
|          : PRO_E_HLE_ADD_EXIT_CSINK   : Required for Thru all hole         |
|          : PRO_E_HLE_EXIT_CSINKANGLE  : Required for exit countersink option
|          : PRO_E_HLE_EXIT_CSINKDIAM   : Required for exit countersink option
|          : PRO_E_HLE_TOP_CLEARANCE    : Mandatory                          |
|----------------------------------------------------------------------------|

--------------------------------------------------------------------------------

Table Hole:3 : Which subelements of PRO_E_HLE_COMP is valid and when ?
------------------------------------------------------------------------------
|          | Element Id                 | Comment                            |
------------------------------------------------------------------------------
| Straight : PRO_E_HLE_TYPE_NEW         : = PRO_HLE_NEW_TYPE_STRAIGHT        |
|   Hole   :.................................................................| 
|          : PRO_E_HLE_MAKE_LIGHTWT     : = PRO_HLE_REGULAR                  |
|          :                            : ( For regular hole )               |
|          :                            : = PRO_HLE_LIGHTWT                  |
|          :                            : ( For lightweight hole )           |
|          :.................................................................|
|          : PRO_E_DIAMETER             : Stores the diameter double value   |
|          :.................................................................|
|          : PRO_E_HOLE_STD_DEPTH       : Depth compound Element             |
|          :                            :....................................|
|          : PRO_E_HOLE_DEPTH_TO        : First Side depth info              |
|          :                            : ( compound element )               |
|          : PRO_E_HOLE_DEPTH_TO_TYPE   : of type ProHleStraightDepType      |
|          : PRO_E_EXT_DEPTH_TO_VALUE   : Stores variable depth double value |
|          :                            : when PRO_E_HOLE_DEPTH_TO_TYPE      |
|          :                            :      == PRO_HLE_STRGHT_BLIND_DEPTH |
|          : PRO_E_EXT_DEPTH_TO_REF     : Stores the upto reference          |
|          :                            : when PRO_E_HOLE_DEPTH_TO_TYPE      |
|          :                            :  != PRO_HLE_STRGHT_BLIND_DEPTH and |
|          :                            :  != PRO_HLE_STRGHT_NONE_DEPTH      |
|          :                            :....................................|
|          : PRO_E_HOLE_DEPTH_FROM      : Second Side depth info             |
|          :                            : ( Compound Element  )              |
|          : PRO_E_HOLE_DEPTH_FROM_TYPE : of ProHleStraightDepType           |
|          : PRO_E_EXT_DEPTH_FROM_VALUE : Stores variable depth double value |
|          :                            : when PRO_E_HOLE_DEPTH_FROM_TYPE    |
|          :                            :      == PRO_HLE_STRGHT_BLIND_DEPTH |
|          : PRO_E_EXT_DEPTH_FROM_REF   : stores the upto reference          |
|          :                            : when PRO_E_HOLE_DEPTH_FROM_TYPE    |
|          :                            :  != PRO_HLE_STRGHT_BLIND_DEPTH  and|
|          :                            :  != PRO_HLE_STRGHT_NONE_DEPTH   and|
|          :                            :  != PRO_HLE_STRGHT_SYM_DEPTH       |
|..........:............................:....................................|
| Sketch   : PRO_E_HLE_TYPE_NEW         : = PRO_HLE_NEW_TYPE_SKETCH          |
|  Hole    :.................................................................|
|          : PRO_E_SKETCHER             : It is a 2D Sketcher Element        |
|          :.................................................................|
|          : PRO_E_HLE_CRDIR_FLIP       : Direction of creation.             |
|          :                            : Of type ProHleCrDir                |
|..........:............................:....................................|
| Standard : PRO_E_HLE_TYPE_NEW         : = PRO_HLE_NEW_TYPE_STANDARD        |
|   Hole   :............................:....................................|
|          : PRO_E_HLE_STAN_TYPE        : Of type ProHleStandType            |
|          :............................:....................................| 
|          : PRO_E_HLE_THRDSERIS        : It is an integer. The *.hol files  |
|          :                            : get loaded as specified in Notes(1)|
|          :                            : From the *.hol files, different    |
|          :                            : THREAD_SERIES information are gath-|
|          :                            : ered and a list is formed.This ele-|
|          :                            : ment stores the current index to   |
|          :                            : the list.                          |
|          :............................:....................................|
|          : PRO_E_HLE_FITTYPE          : Of type ProHleFittype              |
|          :                            : Available for clearance hole       |
|          :                            : i.e. When PRO_E_HLE_STAN_TYPE ==   |
|          :                            : PRO_HLE_CLEARANCE_TYPE             |
|          :............................:....................................|
|          : PRO_E_HLE_SCREWSIZE        : It is an integer.It stores an index|
|          :                            : to the screw_size list. Selecting  |
|          :                            : a thread series, choose one of the |
|          :                            : .hol files. From that file screw-  |
|          :                            : size list is extracted.            |
|          :............................:....................................|
|          : PRO_E_HLE_ADD_THREAD       : It is an option for addding thread.|
|          :                            : Available for tapped hole,i.e when |
|          :                            : PRO_E_HLE_STAN_TYPE ==             |
|          :                            : PRO_HLE_TAPPED_TYPE                |
|          :                            : Of type ProHleAddThrdFlag.         |
|          :                            : For add thread option it's value is|
|          :                            : PRO_HLE_ADD_THREAD. For no thread  |
|          :                            : option,  the value  is             |
|          :                            : PRO_HLE_NO_THREAD.                 |
|          :............................:....................................|
|          : PRO_E_HLE_ADD_CBORE        : It is an option for Counter Bore.  |
|          :                            : Of type ProHleAddCboreFlag.        |
|          :                            : For counter bore it's value is     |
|          :                            : PRO_HLE_ADD_CBORE. For no counter  |
|          :                            : bore option,  the value is         |
|          :                            : PRO_HLE_NO_CBORE  .                |
|          :............................:....................................|
|          : PRO_E_HLE_ADD_CSINK        : It is an option for Counter Sink.  |
|          :                            : Of type ProHleAddCsinkFlag         |
|          :                            : For counter sink it's value is     |
|          :                            : PRO_HLE_ADD_CSINK. For no counter  |
|          :                            : sink, value is PRO_HLE_NO_CSINK    |
|          :............................:....................................|
|          : PRO_E_HLE_HOLEDIAM         : Stores Drill Diameter double value.|
|          :                            : Refer Note # 5                     |
|          :............................:....................................|
|          : PRO_E_HLE_DRILLANGLE       : Stores Drill Angle double value.   |
|          :                            : Avaialable for tapped hole with    |
|          :                            : variable depth. i.e. when          |
|          :                            : PRO_E_HLE_STAN_TYPE ==             |
|          :                            :       PRO_HLE_TAPPED_TYPE      and |
|          :                            : PRO_E_HLE_DEPTH ==                 |
|          :                            :       PRO_HLE_STD_VAR_DEPTH        |
|          :............................:....................................|
|          : PRO_E_HLE_CSINKANGLE       : Stores counter sink angle double   |
|          :                            : value. Available for countersink   |
|          :                            : option i.e. PRO_E_HLE_ADD_CSINK == |
|          :                            : PRO_HLE_ADD_CSINK .                |
|          :............................:....................................|
|          : PRO_E_HLE_CBOREDEPTH       : Stores counter bore depth double   |
|          :                            : value. Available for counterbore   |
|          :                            : option i.e. PRO_E_HLE_ADD_CBORE == |
|          :                            : PRO_HLE_ADD_CBORE.                 |
|          :............................:....................................|
|          : PRO_E_HLE_CBOREDIAM        : Stores counterbore diameter double |
|          :                            : value. Available for counterbore   |
|          :                            : option i.e. PRO_E_HLE_ADD_CBORE == |
|          :                            : PRO_HLE_ADD_CBORE.                 |
|          :............................:....................................|
|          : PRO_E_HLE_CSINKDIAM        : Stores countersink diameter double |
|          :                            : value. Available for countersink   |
|          :                            : option i.e. PRO_E_HLE_ADD_CSINK == |
|          :                            : PRO_HLE_ADD_CSINK .                |
|          :............................:....................................|
|          : PRO_E_HLE_THRDDEPTH        : Stores thread depth double value.  |
|          :                            : Available for tapped hole, with    |
|          :                            : variable thread option. i.e.       |
|          :                            : PRO_E_HLE_STAN_TYPE ==             |
|          :                            :       PRO_HLE_TAPPED_TYPE      and |
|          :                            : PRO_E_HLE_ADD_THREAD ==            |
|          :                            :       PRO_HLE_ADD_THREAD       and |
|          :                            : PRO_E_HLE_THRD_DEPTH ==            |
|          :                            :       PRO_HLE_VARIABLE_THREAD.     |
|          :............................:....................................|
|          : PRO_E_HLE_DRILLDEPTH       : Stores drill depth double value.   |
|          :                            : Available for tapped hole , with   |
|          :                            : variable depth option. i.e.        |
|          :                            : PRO_E_HLE_STAN_TYPE ==             |
|          :                            :       PRO_HLE_TAPPED_TYPE      and |
|          :                            : PRO_E_HLE_DEPTH ==                 |
|          :                            :       PRO_HLE_STD_VAR_DEPTH        |
|          :............................:....................................|
|          : PRO_E_HLE_THRD_DEPTH       : It is an option for different type |
|          :                            : of thread depth.                   |
|          :                            : Of type ProHleThrdDepType          |
|          :                            : Available for tapped hole with     |
|          :                            : thread option.i.e.                 |
|          :                            : PRO_E_HLE_STAN_TYPE ==             |
|          :                            :       PRO_HLE_TAPPED_TYPE      and |
|          :                            : PRO_E_HLE_ADD_THREAD ==            |
|          :                            :       PRO_HLE_ADD_THREAD           |
|          :                            : Note :For part level variable drill|
|          :                            : depth and assembly level tapped    |
|          :                            : threaded hole PRO_HLE_THRU_THREAD  |
|          :                            : value for this element is invalid. |
|          :............................:....................................|
|          : PRO_E_HLE_DEPTH            : It is an option for different type |
|          :                            : drill depth type.                  |
|          :                            : Of type ProHleStdDepType           |
|          :                            : Note : PRO_HLE_STD_VAR_DEPTH is not|
|          :                            : available for clearance hole i.e   |
|          :                            : not for PRO_E_HLE_STAN_TYPE ==     |
|          :                            : PRO_HLE_CLEARANCE_TYPE             |
|          :............................:....................................|
|          : PRO_E_STD_HOLE_DEPTH_REF   : Stores reference ,                 |
|          :                            : when PRO_E_HLE_DEPTH               |
|          :                            :   == PRO_HLE_STD_THRU_UNTIL_DEPTH  |
|          :                            :                 OR                 |
|          :                            :   == PRO_HLE_STD_TO_SEL_DEPTH      |
|          :............................:....................................|
|          : PRO_E_HLE_DEPTH_DIM_TYPE   : Available when PRO_E_HLE_DEPTH is  |
|          :                            : PRO_HLE_STD_VAR_DEPTH              |
|          :                            : Stores the information of blind    |
|          :                            : drill depth dimensioning scheme.   |
|          :                            : PRO_HLE_DEP_SHOULDER_DIM_SCHEME is |
|          :                            : default. PRO_HLE_DEP_TIP_DIM_SCHEME|
|          :                            : can be used to dimension till tip. |
|          :............................:....................................|
|          : PRO_E_HLE_CRDIR_FLIP       : Direction of creation.             |
|          :                            : Of type ProHleCrDir                |
|          :............................:....................................|
|          : PRO_E_HLE_ADD_EXIT_CSINK   : An option for Exit Counter Sink.   |
|          :                            : Of type ProHleAddExitCsinkFlag     |
|          :                            : For exit counter sink it's value is|
|          :                            : PRO_HLE_ADD_EXIT_CSINK. For no     |
|          :                            : countersink, value is              |
|          :                            : PRO_HLE_NO_EXIT_CSINK              |
|          :                            : Not available for assembly mode.   |
|          :                            : In part mode will fail if entry and 
|          :                            : exit surfaces of hole are non-planar 
|          :                            : and non-parallel                   |
|          :............................:....................................|
|          : PRO_E_HLE_EXIT_CSINKANGLE  : Stores exit countersink angle double
|          :                            : value. Available for exit countersink
|          :                            : option i.e.                        |
|          :                            : PRO_E_HLE_ADD_EXIT_CSINK ==        |
|          :                            : PRO_HLE_ADD_EXIT_CSINK             |
|          :............................:....................................|
|          : PRO_E_HLE_EXIT_CSINKDIAM   : Stores exit countersink diameter   |
|          :                            : double value. Available for exit   |
|          :                            : countersink option i.e.            |
|          :                            : PRO_E_HLE_ADD_EXIT_CSINK ==        |
|          :                            : PRO_HLE_ADD_EXIT_CSINK             |
|          :............................:....................................|
|          : PRO_E_HLE_ADD_NOTE         : It is an option for add note.      |
|          :                            : Of type ProHleAddNoteFlag          |
|          :                            : The default value is add note, i.e.|
|          :                            : PRO_HOLE_ADD_NOTE_FLAG. For no note|
|          :                            : the value is PRO_HOLE_NO_NOTE_FLAG.|
|          :............................:....................................|
|          : PRO_E_HOLE_NOTE            : This element is not accessible     |
|          :                            : through Creo Parametric TOOLKIT.   |
|          :                            : Default note will be created, when |
|          :                            : PRO_E_HLE_ADD_NOTE ==              |
|          :                            : PRO_HOLE_ADD_NOTE_FLAG             |
|..........:............................:....................................|
| Custom   : PRO_E_HLE_TYPE_NEW         : = PRO_HLE_CUSTOM_TYPE              |
|   Hole   :............................:....................................|
|          : PRO_E_HLE_ADD_CBORE        : The description of these           |
|          :............................: items are same as                  |
|          : PRO_E_HLE_ADD_CSINK        : described in                       |
|          :............................: Standard hole section.             |
|          : PRO_E_HLE_HOLEDIAM         :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_DRILLANGLE       :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_CSINKANGLE       :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_CBOREDEPTH       :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_CBOREDIAM        :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_CSINKDIAM        :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_DRILLDEPTH       :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_DEPTH            :                                    |
|          :............................:                                    |
|          : PRO_E_STD_HOLE_DEPTH_REF   :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_DEPTH_DIM_TYPE   :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_CRDIR_FLIP       :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_ADD_EXIT_CSINK   :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_EXIT_CSINKANGLE  :                                    |
|          :............................:                                    |
|          : PRO_E_HLE_EXIT_CSINKDIAM   :                                    |
|          :............................:....................................|
------------------------------------------------------------------------------

Table Hole:4 : Which subelements of PRO_E_HLE_PLACEMENT is valid and when ?
   The following type of placements are possible
      Case A: A linear Hole on a plane
      Case B: A Radial hole on a plane with radial dimensioning
      Case C: A Radial hole on a plane with diameter dimensoining
      Case D: A Radial hole on a plane with linear dimensioning
              Available under the config option
              radial_hole_linear_dim "YES"
      Case E: A Radial hole on a conic ( Cone or Cylinder )
      Case F: A Coaxial hole ,whose primary reference is an axis
      case G: A Coaxial hole ,whose primary reference is not an axis
      Case H: An onpoint hole,whose primary reference is 
              a surface datum point
      Case I: An onpoint hole,whose primary reference is any type of datum point
              and it also require a surface, to which the point will be projected.
              The hole depth is measured from the projected point.
      Case J: An onpoint hole,whose primary reference is any type of datum point.
              The direction of the hole is defined using direction elements.
              The hole depth is measured from datum point as it is in case H.
--------------------------------------------------------------------------------
|       | Element Id             | Comment                                     |
--------------------------------------------------------------------------------
|Case A :PRO_E_HLE_PRIM_REF      :Primary Selection,planar surface/datum plane |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_LIN                        |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_REF1      :First Secondary selection.Plane,edge,axis    |
|       :                        :If edge/axis is normal to placement plane    |
|       :                        :another selection is required for dimension- |
|       :                        :ing it. Hence this can be take two selections|
|       :                        :                                             |
|       :PRO_E_HLE_PLC_ALIGN_OPT1:Aligned Flag wrt PRO_E_HLE_DIM_REF1.         |
|       :                        :With default value PRO_HLE_PLC_NOT_ALIGN.    |
|       :                        :Optional for not aligned linear hole, where  |
|       :                        :offset is specified by PRO_E_HLE_DIM_DIST1.  |
|       :                        :If set to PRO_HLE_PLC_ALIGN, takes precedence|
|       :                        :over PRO_E_HLE_DIM_DIST1.                    |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_DIST1     :Distance wrt PRO_E_HLE_DIM_REF1              |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_REF2      :Second Secondary selection.Plane,edge,axis   |
|       :                        :If edge/axis is normal to placement plane    |
|       :                        :another selection is required for dimension- |
|       :                        :ing it. Hence this can be take two selections|
|       :                        :                                             |
|       :PRO_E_HLE_PLC_ALIGN_OPT2:Aligned Flag wrt PRO_E_HLE_DIM_REF2.         |
|       :                        :With default value PRO_HLE_PLC_NOT_ALIGN.    |
|       :                        :Optional for not aligned linear hole, where  |
|       :                        :offset is specified by PRO_E_HLE_DIM_DIST2.  |
|       :                        :If set to PRO_HLE_PLC_ALIGN, takes precedence|
|       :                        :over PRO_E_HLE_DIM_DIST2.                    |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_DIST2     :Distance wrt PRO_E_HLE_DIM_REF2              |
|       :                        :                                             |
|       :PRO_E_LIN_HOLE_DIR_REF  :Uses the reference for direction.            |
|       :                        :This element is available if the secondary   |
|       :                        :element contains ONE reference and           |
|       :                        :reference is an axis, which is normal to     |
|       :                        :current hole's primary reference.            |
|       :                        :                                             |
|.......:........................:.............................................|
|Case B :PRO_E_HLE_PRIM_REF      :Primary Selection,planar surface/datum plane |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_RAD                        |
|       :                        :                                             |
|       :PRO_E_HLE_AXIS          :Axis for radial hole                         |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_RAD       :Radial distance wrt PRO_E_HLE_AXIS           |
|       :                        :                                             |
|       :PRO_E_HLE_REF_PLANE_1   :Reference plane against which angular        |
|       :                        :distance will be measured                    |
|       :                        :                                             |
|       :PRO_E_HLE_REF_ANG_1     :Angular distance wrt PRO_E_HLE_REF_PLANE_1   |
|.......:........................:.............................................|
|Case C :PRO_E_HLE_PRIM_REF      :Primary Selection,planar surface/datum plane |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_RAD_DIA_DIM                |
|       :                        :                                             |
|       :PRO_E_HLE_AXIS          :Axis for radial hole                         |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_DIA       :Diameter distance wrt PRO_E_HLE_AXIS         |
|       :                        :                                             |
|       :PRO_E_HLE_REF_PLANE_1   :Reference plane against which angular        |
|       :                        :distance will be measured                    |
|       :                        :                                             |
|       :PRO_E_HLE_REF_ANG_1     :Angular distance wrt PRO_E_HLE_REF_PLANE_1   |
|.......:........................:.............................................|
|Case D :PRO_E_HLE_PRIM_REF      :Primary Selection,planar surface/datum plane |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_RAD_LIN_DIM                |
|       :                        :                                             |
|       :PRO_E_HLE_AXIS          :Axis for radial hole                         |
|       :                        :                                             |
|       :PRO_E_HLE_DIM_LIN       :Linear distance wrt PRO_E_HLE_AXIS           |
|       :                        :                                             |
|       :PRO_E_HLE_REF_PLANE_1   :Reference plane against which angular        |
|       :                        :distance will be measured                    |
|       :                        :                                             |
|       :PRO_E_HLE_REF_ANG_1     :Angular distance wrt PRO_E_HLE_REF_PLANE_1   |
|.......:........................:.............................................|
|Case E :PRO_E_HLE_PRIM_REF      :Primary Selection,Cone or Cylinder           |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_RAD                        |
|       :                        :                                             |
|       :PRO_E_HLE_REF_PLANE     :Reference plane against which angular        |
|       :                        :distance will be measured                    |
|       :                        :                                             |
|       :PRO_E_HLE_REF_ANG       :Angular distance wrt PRO_E_HLE_REF_PLANE     |
|       :                        :                                             |
|       :PRO_E_HLE_NORM_PLA      :Reference plane for linear measurement       |
|       :                        :                                             |
|       :PRO_E_HLE_NORM_OFFST    :Distance wrt PRO_E_HLE_NORM_PLA              |
|.......:........................:.............................................|
|Case F :PRO_E_HLE_PRIM_REF      :Primary Selection,Axis                       |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_COAX                       |
|       :                        :                                             |
|       :PRO_E_HLE_PLCMNT_PLANE  :Placement surface                            |
|.......:........................:.............................................|
|Case G :PRO_E_HLE_PRIM_REF      :Primary Selection, a surface                 |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_COAX                       |
|       :                        :                                             |
|       :PRO_E_HLE_AXIS          :Axis                                         |
|.......:........................:.............................................|
|Case H :PRO_E_HLE_PRIM_REF      :Primary Selection,                           |
|       :                        :On Surface Created Datum Point               |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_ON_PNT                     |
|       :                        :                                             |
|.......:........................:.............................................|
|Case I :PRO_E_HLE_PRIM_REF      :Primary Selection,Datum Point                |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_ON_PNT                     |
|       :                        :                                             |
|       :PRO_E_HLE_PLCMNT_PLANE  :Placement surface                            |
|       :                        :                                             |
|.......:........................:.............................................|
|Case J :PRO_E_HLE_PRIM_REF      :Primary Selection,Datum Point                |
|       :                        :                                             |
|       :PRO_E_HLE_PL_TYPE       := PRO_HLE_PL_TYPE_ON_PNT                     |
|       :                        :                                             |
|       :PRO_E_HLE_FT_DIR_REF    :Orientation reference                        |
|       :                        :                                             |
|       :PRO_E_HLE_FT_DIR_OPT    :Orientation option                           |
|       :                        :                                             |
|------------------------------------------------------------------------------|

Notes:
1) The *.hol file, hole parameter file gets loaded in following order :-
     -  Directory , specified in config option "hole_parameter_file_path"
     -  Current Directory
     -  System hole parameter directory i.e. {PROE DIR}/text/hole
2) Please follow, the order of adding elements as given in the table-2 or 
   as mentioned in the main element tree.
3) All the angle elements are in degree.
4) The drill diameter ( PRO_E_HLE_HOLEDIAM ) has to be smaller than 
   the thread diameter  calculated from the .hol file for the threaded hole. 
   ( Thread diameter is the element corresponding to BASIC_DIAM column and 
     selected screw size row in the table,specified in the selected .hol file)
5) There are some differences in placement of hole created 
   using UI and Creo Parametric TOOLKIT, for PLACEMENT CASES for 
   Radial Placement :  B,C,D, & E.

   Hence the result may not be consistent, if a feature is created 
   programmatically , using the same references as used in 
   UI, for radial placement of the hole. 

   In Creo Parametric TOOLKIT, the angle will be measured with respect to 
   a vector (VEC1 ) , obtained by cross product of axis vector and 
   the normal to the reference plane vector.

   In UI, since the pick position is ALWAYS one of the parameter, the
   angle is measured with respect to +ve VEC1 or -ve VEC1 
   to obtain an acute angle.

6) Straight hole with symmetric depth option has changed 
   in Pro/ENGINEER Wildfire 1.0.

   The following elements need to be set: 
   PRO_E_HOLE_DEPTH_TO_TYPE   -> PRO_HLE_STRGHT_SYM_DEPTH
   PRO_E_HOLE_DEPTH_FROM_TYPE -> PRO_HLE_STRGHT_NONE_DEPTH
   PRO_E_EXT_DEPTH_FROM_VALUE -> The symmetric depth double value
   Other depth related elements are ignored.

7) Hole's orientation will depend on optional direction elements:
   PRO_E_HLE_FT_DIR_REF, PRO_E_HLE_FT_DIR_OPT.

8) Hole's orientation elements (as described in Note 7), is not available
   for co-axial hole.

9) More types are enumerated below:

*****************************************************************************/

typedef enum pro_hle_type
{
   PRO_HLE_TYPE_STRAIGHT = PRO_EXTRUDE,
   PRO_HLE_TYPE_SKETCHED = PRO_REVOLVE
} ProHleType;


 /* PRO_E_HLE_TYPE_NEW */
 typedef enum pro_hle_new_type
 {
   PRO_HLE_NEW_TYPE_SKETCH   =  6,  /* Sketch hole   */
   PRO_HLE_CUSTOM_TYPE       =  7,  /* Custom hole   */
   PRO_HLE_NEW_TYPE_STRAIGHT = 16,  /* Straight hole */
   PRO_HLE_NEW_TYPE_STANDARD = 24   /* Standard hole */
 } ProHleNewType;


 /* PRO_E_HLE_STAN_TYPE , standard type of hole */
 typedef enum pro_hle_stand_type
 {
   PRO_HLE_TAPPED_TYPE    = 14,    /* Tapped hole */
   PRO_HLE_CLEARANCE_TYPE = 15,    /* Clearance hole */
   PRO_HLE_DRILLED_TYPE   = 17,    /* Drilled hole */
   PRO_HLE_TAPERED_TYPE   = 25     /* Tapered  hole */
 }ProHleStandType;

 /* PRO_E_HLE_FITTYPE */
 typedef enum pro_hle_fittype
 {
   PRO_HLE_CLOSE_FIT  = 0,  /* Close Fit */
   PRO_HLE_FREE_FIT   = 1,  /* Free Fit  */
   PRO_HLE_MEDIUM_FIT = 2   /* Medium Fit */
 } ProHleFittype;

 /* PRO_E_HLE_ADD_THREAD */
 typedef enum pro_hle_add_thrd_flag
 {
   PRO_HLE_NO_THREAD   = -1, /* No thread for standard hole  */
   PRO_HLE_ADD_THREAD  = 26  /* Add thread for standard hole */
 }ProHleAddThrdFlag;


 /* PRO_E_HLE_ADD_CBORE */
 typedef enum pro_hle_add_cbore_flag
 {
   PRO_HLE_NO_CBORE   = -1,  /* No cbore for standard hole */
   PRO_HLE_ADD_CBORE  = 27   /* Add cbore for standard hole */
 }ProHleAddCboreFlag;

 /* PRO_E_HLE_ADD_CSINK */
 typedef enum pro_hle_add_csink_flag
 {
   PRO_HLE_NO_CSINK  = -1,  /* No csink for standard hole */
   PRO_HLE_ADD_CSINK = 28   /* Add csink for standard hole */
 }ProHleAddCsinkFlag;

 /* PRO_E_HLE_MAKE_LIGHTWT */
 typedef enum pro_hle_light_wt_flag
 {
   PRO_HLE_REGULAR = -1,    /* Regular hole */
   PRO_HLE_LIGHTWT = 10     /* Light weight hole */ 
 }ProHleLightWtFlag;

 /* PRO_E_HOLE_DEPTH_TO_TYPE , PRO_E_HOLE_DEPTH_FROM_TYPE */
 typedef enum pro_hle_straight_dep_type
 {
   PRO_HLE_STRGHT_BLIND_DEPTH      = 1, /* Blind */
   PRO_HLE_STRGHT_THRU_NEXT_DEPTH  = 2, /* Thru Next */
   PRO_HLE_STRGHT_THRU_ALL_DEPTH   = 3, /* Thru All */
   PRO_HLE_STRGHT_THRU_UNTIL_DEPTH = 4, /* Thru Until */
   PRO_HLE_STRGHT_UPTO_REF_DEPTH   = 5, /* Upto Ref */
   PRO_HLE_STRGHT_NONE_DEPTH       = 6, /* None  */ 
   PRO_HLE_STRGHT_SYM_DEPTH        = 7  /* Symetric */
 }ProHleStraightDepType;

/* PRO_E_HLE_THRD_DEPTH */
typedef enum pro_hle_thrd_dep_type
{
   PRO_HLE_THRU_THREAD     = 32,  /* Thru thread */
   PRO_HLE_VARIABLE_THREAD = 33   /* Variable thread */
}ProHleThrdDepType;

/* PRO_E_HLE_DEPTH */
typedef enum pro_hle_std_dep_type
{
   PRO_HLE_STD_VAR_DEPTH       = 29, /* Blind std hole */
   PRO_HLE_STD_THRU_NEXT_DEPTH = 30, /* Thru Next std hole */
   PRO_HLE_STD_THRU_ALL_DEPTH  = 31, /* thru all std hole */
   PRO_HLE_STD_THRU_UNTIL_DEPTH = 40,/* Thru until std hole */
   PRO_HLE_STD_TO_SEL_DEPTH     = 41 /* To selected std hole */
}ProHleStdDepType;

/* PRO_E_HLE_DEPTH_DIM_TYPE */
typedef enum pro_hle_dep_dim_scheme
{
  PRO_HLE_DEP_SHOULDER_DIM_SCHEME = -1, /* Dimension till shoulder */
  PRO_HLE_DEP_TIP_DIM_SCHEME      = 18  /* Dimension till tip */
}ProHleDepDimScheme;

/* PRO_E_HLE_CRDIR_FLIP */
typedef enum pro_hle_cr_dir
{
  PRO_HLE_CR_IN_SIDE_ONE = -1,     /* Std/sketch hole creation in side 1 */
  PRO_HLE_CR_IN_SIDE_TWO = 34      /* Std/sketch hole creation in side 2 */
}ProHleCrDir;

/* PRO_E_HLE_ADD_EXIT_CSINK */
 typedef enum pro_hle_add_exit_csink_flag
 {
   PRO_HLE_NO_EXIT_CSINK = -1, /* No exit csink for standard hole */
   PRO_HLE_ADD_EXIT_CSINK = 38 /* Add exit csink for standard hole */
 }ProHleAddExitCsinkFlag;

/* PRO_E_HLE_ADD_NOTE */
 typedef enum pro_hle_add_note_flag
 {
   PRO_HOLE_ADD_NOTE_FLAG = -1, /* Standard hole can have note */
   PRO_HOLE_NO_NOTE_FLAG  = 9   /* No note for standard hole   */
 }ProHleAddNoteFlag;

/* PRO_E_HLE_TOP_CLEARANCE */
 typedef enum pro_hle_top_clrnc_flag
 {
   PRO_HOLE_GEN_CLRNCE        = -1, /* No specific hole entry clearance */
   PRO_HOLE_EXPLICIT_CLRNCE   = 43  /* Explicit hole entry clearance    */
 }ProHleTopClrncFlag;


/* ProHoleProperty */
typedef enum
{
    PRO_HOLE_METRIC_SIZE = 1,
    PRO_HOLE_THREAD_SERIES = 2
} ProHoleProperty;

/* PRO_E_HLE_PLC_ALIGN_OPT1, PRO_E_HLE_PLC_ALIGN_OPT2 */
 typedef enum pro_hle_plc_algn_flag
 {
   PRO_HLE_PLC_NOT_ALIGN = 0,  /* Not Align with given reference   */
   PRO_HLE_PLC_ALIGN     = 1   /* Aligned with the given reference */
 }ProHlePlcAlgnFlag;

/**********************************************************************
 * Because of change in the element tree and change in the placement type
 * of the hole the following new type of enums are used 
 * Previously only PRO_HLE_PL_TYPE_LIN = 1, PRO_HLE_PL_TYPE_COAX = 3,
 * PRO_HLE_PL_TYPE_ON_PNT = 4 was used 
 **********************************************************************/
 /* PRO_E_HLE_PL_TYPE */
typedef enum pro_hle_pl_type
{
   PRO_HLE_PL_TYPE_LIN         = 1, /* linear */
   PRO_HLE_PL_TYPE_RAD         = 2, /* Radial hole on a conic, or a radial hole
                                       on a plane with radial dimension */
   PRO_HLE_PL_TYPE_RAD_DIA_DIM = 3, /* Radial hole on a plane with 
                                       dia dimension */
   PRO_HLE_PL_TYPE_ON_PNT      = 4, /* on point */
   PRO_HLE_PL_TYPE_COAX        = 5, /* coaxial */
   PRO_HLE_PL_TYPE_RAD_LIN_DIM = 6  /* Radial hole on a plane with linear
                                       dimension */

} ProHlePlType;

 /* PRO_E_HLE_FT_DIR_OPT */
typedef enum pro_hle_dir_option
{
  PRO_HLE_FT_PARALLEL_DIR = 0,
  PRO_HLE_FT_PERPENDICULAR_DIR
}ProHleDirOption;

/* API */

extern ProError ProHolePropertyGet (ProFeature* hole, ProHoleProperty property,
                             ProParamvalue* value);

/*
     Purpose:  Retrieves the value of the indicated hole feature property.

     Input Arguments: 
            hole - The hole feature.
            property - The hole property type to retrieve.

     Output Arguments:
            value - The property value.

     Return Values:
            PRO_TK_NO_ERROR   - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 */

extern ProError ProElementHoleThreadSeriesGet ( ProElement   elemtree,
                                                ProMdl       model,
                                                wchar_t    **r_thread_name );
/*
     Purpose:  Retrieves the thread name from the element tree.

     Input Arguments: 
            elemtree  - The hole element tree
            model     - Handle to the model

     Output Arguments:
            r_thread_name - The thread name in wide-string.
                            This should be freed using ProWstringFree().

     Return Values:
            PRO_TK_NO_ERROR   - The function succeeded.
            PRO_TK_NOT_EXIST  - The hole file that is referred in the element
                                with id PRO_E_HLE_THRDSERIS did not exist.
            PRO_TK_INCOMPLETE - The element tree did not have a valid element
                                with id PRO_E_HLE_THRDSERIS.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 */

extern ProError ProElementHoleThreadSeriesSet ( ProElement  elemtree,
                                                ProMdl      model,
                                                wchar_t    *thread_name );
/*
     Purpose:  Updates the thread name in the element tree.
               This updates PRO_E_HLE_THRDSERIS element.
               After this call, use ProElementHoleScrewSizeSet() to
               set the screw size ( fastener id ).

     Input Arguments: 
            elemtree    - The hole element tree
            model       - Handle to the model
            thread_name - The thread name in wide-string.

     Output Arguments:
            none

     Return Values:
            PRO_TK_NO_ERROR   - The function succeeded.
            PRO_TK_NOT_EXIST  - The hole file that is referred in thread_name 
                                did not exist.
            PRO_TK_INCOMPLETE - The element tree did not have a valid element
                                with id PRO_E_HLE_THRDSERIS.
            PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
 */


extern ProError ProElementHoleScrewSizeGet ( ProElement   elemtree,
                                             ProMdl       model,
                                             wchar_t    **r_screw_size_name );
/*
     Purpose:  Retrieves the screw size ( fastener id)  from the element tree.
               This uses PRO_E_HLE_THRDSERIS and PRO_E_HLE_SCREWSIZE elements.

     Input Arguments: 
            elemtree  - The hole element tree
            model     - Handle to the model

     Output Arguments:
            r_screw_size_name - The screw size ( fastener id) in wide-string.
                                This should be freed using ProWstringFree().

     Return Values:
            PRO_TK_NO_ERROR     - The function succeeded.
            PRO_TK_NOT_EXIST    - The hole file that is referred in the element
                                  with id PRO_E_HLE_THRDSERIS did not exist.
            PRO_TK_INCOMPLETE   - The element tree did not have valid elements
                                  with id PRO_E_HLE_THRDSERIS and 
                                  PRO_E_HLE_SCREWSIZE.
            PRO_TK_INVALID_ITEM - The screw size that is referred in the 
                                  element with element id PRO_E_HLE_SCREWSIZE 
                                  did not exist in the hole file which is 
                                  mentioned in the element with id 
                                  PRO_E_HLE_THRDSERIS. 
            PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
 */

extern ProError ProElementHoleScrewSizeSet  ( ProElement   elemtree,
                                              ProMdl       model,
                                              wchar_t     *screw_size_name );
/*
     Purpose:  Updates the screw size ( fasten id ) in the element tree.
               This updates PRO_E_HLE_SCREWSIZE element.
               This depends on the value in PRO_E_HLE_THRDSERIS element.i
               Hence the value in PRO_E_HLE_THRDSERIS should be set using
               ProElementHoleThreadSeriesSet, prior to this call.

     Input Arguments: 
            elemtree        - The hole element tree
            model           - Handle to the model
            screw_size_name - The screw size ( fasten id ) in wide-string.

     Output Arguments:
            none

     Return Values:
            PRO_TK_NO_ERROR     - The function succeeded.
            PRO_TK_NOT_EXIST    - The hole file that is referred in the element
                                  with id PRO_E_HLE_THRDSERIS did not exist.
            PRO_TK_INCOMPLETE   - The element tree did not have valid elements
                                  with id PRO_E_HLE_THRDSERIS and 
                                  PRO_E_HLE_SCREWSIZE.
            PRO_TK_INVALID_NAME - The screw size that is referred in 
                                  screw_size_name did not exist in the hole 
                                  file which is mentioned in the element with 
                                  id PRO_E_HLE_THRDSERIS. 
            PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
 */

PRO_END_C_DECLS

#endif
