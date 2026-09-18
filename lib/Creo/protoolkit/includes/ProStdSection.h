#ifndef PROSECODUIH
#define PROSECODUIH

#include <ProToolkit.h>





PRO_BEGIN_C_DECLS

/************************************************************************
Generic std section element tree model for Pro/ENGINEER Wildfire
Dashboard UI and Pro/TOOLKIT (Excluding simple sweep). 
-------------------------------------------------------------------

     PRO_E_STD_SECTION (PRO_E_STD_TRAJ)
       |
       |--PRO_E_SEC_USE_SKETCH
       |
       |--PRO_E_STD_SEC_SETUP_PLANE
       |    |
       |    |--PRO_E_STD_SEC_PLANE
       |    |
       |    |--PRO_E_STD_SEC_PLANE_VIEW_DIR
       |    |
       |    |--PRO_E_STD_SEC_PLANE_ORIENT_DIR
       |    |
       |    |--PRO_E_STD_SEC_PLANE_ORIENT_REF
       |
       |--PRO_E_SKETCHER


---------------------------------------------------------------------------------------
Element Id                       Element Name    Data Type                Valid Values
---------------------------------------------------------------------------------------
PRO_E_STD_SECTION/PRO_E_STD_TRAJ Section         Compound
PRO_E_SEC_USE_SKETCH             Reference Sketch  PRO_VALUE_TYPE_SELECTION PRO_FEATURE
PRO_E_STD_SEC_SETUP_PLANE        Section Plane   Compound
PRO_E_STD_SEC_PLANE              Plane           PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_STD_SEC_PLANE_VIEW_DIR     View Dir        PRO_VALUE_TYPE_INT       ProSecViewDirType
PRO_E_STD_SEC_PLANE_ORIENT_DIR   Orient Dir      PRO_VALUE_TYPE_INT       ProSecOrientDirType
PRO_E_STD_SEC_PLANE_ORIENT_REF   Reference       PRO_VALUE_TYPE_SELECTION PRO_EDGE, PRO_SURFACE
PRO_E_SKETCHER                   Sketch          PRO_VALUE_TYPE_POINTER

*************************************************************************/



/************************************************************************


Maximum std section element tree used by Pro/TOOLKIT in R20 and by simple
sweep feature in Pro/Engineer Wildfire.
------------------------------------------------------------

     PRO_E_STD_SECTION (PRO_E_STD_TRAJ)
       |
       |--PRO_E_STD_SEC_SETUP
       |    |
       |    |--PRO_E_STD_SEC_METHOD (Only PRO_SEC_SKETCH supported)
       |    |
       |    |--PRO_E_STD_SECTION_PLANE  (For non-first features only)
       |        |
       |        |--PRO_E_STD_SEC_PLANE
       |        |
       |        |--PRO_E_STD_SEC_PLANE_VIEW_DIR
       |        |
       |        |--PRO_E_STD_SEC_PLANE_ORIENT_DIR
       |        |
       |        |--PRO_E_STD_SEC_PLANE_ORIENT_REF
       |
       |--PRO_E_SKETCHER (Section handle)
       |
       |--PRO_E_STD_MATRLSIDE (For cuts and slots)


---------------------------------------------------------------------------------------
Element Id                       Element Name    Data Type                Valid Values
---------------------------------------------------------------------------------------
PRO_E_STD_SECTION                Section         Compound
PRO_E_STD_TRAJ                                   Compound
PRO_E_STD_SETUP                  Setup           Compound
PRO_E_STD_METHOD                 Method          PRO_VALUE_TYPE_INT       ProSecMethod
PRO_E_STD_SECTION_PLANE          Section Plane   Compound
PRO_E_STD_SEC_PLANE              Plane           PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_STD_SEC_PLANE_VIEW_DIR     View Dir        PRO_VALUE_TYPE_INT       ProSecViewDirType
PRO_E_STD_SEC_PLANE_ORIENT_DIR   Orient Dir      PRO_VALUE_TYPE_INT       ProSecOrientDirType
PRO_E_STD_SEC_PLANE_ORIENT_REF   Reference       PRO_VALUE_TYPE_SELECTION PRO_EDGE, PRO_SURFACE
PRO_E_SKETCHER                   Sketch          PRO_VALUE_TYPE_POINTER
PRO_E_STD_MATRLSIDE              Material Side   PRO_VALUE_TYPE_INT


 ************************************************************************
 **                                                                    **
 **     Information below shows the element tree for reference purposes**
 **     only. It should not be used for any feature creation in        **
 **      Pro/ENGINEER or  Pro/ENGINEER Wildfire.                       **
 **                                                                    **
 ************************************************************************ 

Generic std section element tree model for ongoing development R21+ 
-------------------------------------------------------------------

PRO_E_STD_SECTIONS (PRO_E_STD_TRAJS)
  |
  |--PRO_E_STD_SECTION (PRO_E_STD_TRAJ)
       |
       |--PRO_E_STD_SEC_SETUP
       |    |
       |    |--PRO_E_STD_SEC_METHOD
       |    |
       |    |--PRO_E_STD_SECTION_PLANE
       |    |    |
       |    |    |--PRO_E_STD_SEC_PLANE
       |    |    |
       |    |    |--PRO_E_STD_SEC_PLANE_VIEW_DIR
       |    |    |
       |    |    |--PRO_E_STD_SEC_PLANE_ORIENT_DIR
       |    |    |
       |    |    |--PRO_E_STD_SEC_PLANE_ORIENT_REF
       |    |
       |    |--PRO_E_STD_SEC_PLANE_LOC
       |    |    |
       |    |    |--PRO_E_STD_SEC_LOCATION
       |    |    |
       |    |    |--PRO_E_STD_SEC_ROTATION
       |    |
       |    |--PRO_E_STD_SEC_SELECT
       |
       |--PRO_E_SKETCHER
       |
       |--PRO_E_STD_MATRLSIDE

---------------------------------------------------------------------------------------
Element Id                       Element Name    Data Type                Valid Values
---------------------------------------------------------------------------------------
PRO_E_STD_SECTIONS               Sections        Compound
PRO_E_STD_TRAJS                                  Compound
PRO_E_STD_SECTION                Section         Compound
PRO_E_STD_TRAJ                                   Compound
PRO_E_STD_SETUP                  Setup           Compound
PRO_E_STD_METHOD                 Method          PRO_VALUE_TYPE_INT       ProSecMethod
PRO_E_STD_SECTION_PLANE          Section Plane   Compound
PRO_E_STD_SEC_PLANE              Plane           PRO_VALUE_TYPE_SELECTION PRO_SURFACE
PRO_E_STD_SEC_PLANE_VIEW_DIR     View Dir        PRO_VALUE_TYPE_INT       ProSecViewDirType
PRO_E_STD_SEC_PLANE_ORIENT_DIR   Orient Dir      PRO_VALUE_TYPE_INT       ProSecOrientDirType
PRO_E_STD_SEC_PLANE_ORIENT_REF   Reference       PRO_VALUE_TYPE_SELECTION PRO_EDGE, PRO_SURFACE
PRO_E_STD_SEC_PLANE_LOC          Sec Location    Compound
PRO_E_STD_SEC_LOCATION           Location        PRO_VALUE_TYPE_SELECTION  
PRO_E_STD_SEC_ROTATION           Rotation        PRO_VALUE_TYPE_DOUBLE  
PRO_E_STD_SEC_SELECT             Sel Section     Compound
PRO_E_SKETCHER                   Sketch          PRO_VALUE_TYPE_POINTER
PRO_E_STD_MATRLSIDE              Material Side   PRO_VALUE_TYPE_INT

*************************************************************************/


/* PRO_E_STD_SEC_METHOD */
 
typedef enum pro_sec_method
{
   PRO_SEC_SKETCH     = 25,
   PRO_SEC_SELECT     = 26
} ProSecMethod;

/* PRO_E_STD_SEC_PLANE_VIEW_DIR */

typedef enum pro_sec_view_dir_type
{
   PRO_SEC_VIEW_DIR_SIDE_ONE     = 1,
   PRO_SEC_VIEW_DIR_SIDE_TWO     = -1
} ProSecViewDirType;

/* PRO_E_STD_SEC_PLANE_ORIENT_DIR */

typedef enum pro_sec_orient_dir_type
{
   PRO_SEC_ORIENT_DIR_UP      = 1,
   PRO_SEC_ORIENT_DIR_DOWN    = 2, 
   PRO_SEC_ORIENT_DIR_LEFT    = 3, 
   PRO_SEC_ORIENT_DIR_RIGHT   = 4,
   PRO_SEC_ORIENT_DIR_NONE    = 5
} ProSecOrientDirType;

PRO_END_C_DECLS

#endif

