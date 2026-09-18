#ifndef PRONCSEQELEM_H
#define PRONCSEQELEM_H

/* ProNcseqElem.h:  defines the action functions setting NC seq elems */


#include <ProToolkit.h>
#include <ProParamval.h>
#include <ProSelection.h>
#include <ProWcell.h>
#include <ProMfgOptions.h>




/*****************************************************************************\

WARNING: Methods in this header are related to the Feature element tree described
in ProNcseq.h - that element tree is deprecated and will be removed in subsequent
releases. Check ProNcseq.h for possible replacements.
\******************************************************************************/

PRO_BEGIN_C_DECLS


typedef                struct Pro_Elem  *ProNcseqElem;
typedef PRO_CONST_ARG  struct Pro_Elem  *ProConstNcseqElem;


typedef enum Pro_HolesetDirection  {
  PRO_HS_DIR_NATURAL = -1,
  PRO_HS_DIR_FLIP    =  1
}  ProHolesetDirection;

extern ProError  ProNcseqElemMillsurfSet  (ProNcseqElem  elem,
                                           ProBoolean    flip,
                                           int           mill_surf_id);
/*
   Purpose:  Stores the mill surface identifier and the normal sense in a 
             <i>ProNCseqElem</i> data structure.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_SURFACES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      flip           - Specifies whether to flip the normal sense of a 
                       surface reference
      mill_surf_id   - The identifier of a mill surface

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemSurfaceAdd (ProNcseqElem                elem,
                                         PRO_CONST_ARG ProSelection srf);
/*
   Purpose:  Stores the surface selections in a <i>ProNcseqElem</i> 
	     data structure.
<p>
   NOTE:
<p>
      When you call the function <b>ProFeatureWithoptionsRedefine()</b>, the system 
      replaces the existing surface selections in the feature with the 
      selections stored in the <i>ProNcseqElem</i> data structure.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_SURFACES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      srf            - The surface selection

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.

   See Also:
      ProFeatureWithoptionsRedefine()
*/


extern ProError  ProNcseqElemSurfaceflipSet  (ProNcseqElem  elem,
                                              ProBoolean    flip);
/*
   Purpose:  Stores a surface flip in a <i>ProNCseqElem</i> data structure.
<p>
   NOTE:
<p>
        This function is useful when you are redefining the "flip" of a
        mill surface reference of a sequence.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_SURFACES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      flip           - Specifies whether to flip the normal sense of a surface 
                       reference

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemVolumeSet  (ProNcseqElem  elem,
                                         int           mill_vol_id);
/*
   Purpose:  Stores a mill volume identifier in a <i>ProNcseqElem</i> data
             structure.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_SURFACES
<p>
      PRO_E_VOLUME

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      mill_vol_id    - The identifier of the mill volume

   Output Arguments:
      None 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemWindowSet   (ProNcseqElem  elem,
                                          int           mill_wind_id);
/* 
   Purpose:  Stores a mill window identifier in a <i>ProNcseqElem</i> data
             structure.
<p>
   Applicable Element Id(s):
<p>
      PRO_E_MACH_WINDOW

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      mill_wind_id   - The identifier of the mill window

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError  ProNcseqElemHolesetAdd  (ProNcseqElem  elem,
                                          int          *r_set_nmb);
/*
   Purpose:  Adds storage for another hole set to a <i>ProNcseqElem</i> data
             structure.  <b>Please note that this routine and the associated
             PRO_E_HOLES element are provided solely for compatibility with
             existing Creo Parametric TOOLKIT code.  Wherever possible the more powerful
             PRO_E_HOLESETS element should be used instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information.

   Output Arguments:
      r_set_nmb      - If this is not NULL and storage was successful, 
                       this is the number of the hole set that was added.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError  ProNcseqElemHolesetDepthTypeSet (ProNcseqElem       elem,
                                                  int                set_nmb,
                                                  ProDrillDepthType  dt);
/*
   Purpose:  Stores the type of drill depth for the specified hole set
             in a <i>ProNcseqElem</i> data structure. <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided
             solely for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      dt             - The type of drill depth

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetDepthBySet  (ProNcseqElem         elem, 
                                                int                  set_nmb,
                                                ProDrillDepthByType  db);
/*
   Purpose:  Stores the depth-by type for the specified hole set in a 
             <i>ProNcseqElem</i> data structure.  <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      db             - The depth-by type

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetStartSet (ProNcseqElem                 elem,
                                              int                          set_nmb,
                                              PRO_CONST_ARG ProSelection  start_pln);
/*
   Purpose:  Stores the start plane for the specified hole set in a 
             <i>ProNcseqElem</i> data structure.  <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      start_pln      - The start plane selection

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetEndSet (ProNcseqElem                 elem,
                                          int                          set_nmb,
                                          PRO_CONST_ARG ProSelection   end_pln);
/*
   Purpose:  Stores the end plane selection for the specified hole set in a 
             <i>ProNcseqElem</i> data structure.  <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      end_pln        - The end plane selection

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetDepthSet (ProNcseqElem elem, 
                                              int          set_nmb,
                                              double       hs_depth);
/*
   Purpose:  Stores the depth value for the specified hole set in a 
             <i>ProNcseqElem</i> data structure.  <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      hs_depth       - The depth of the hole set

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetDirectionSet  (ProNcseqElem        elem,
                                                 int                 set_nmb,
                                                 ProHolesetDirection dir);
/*
   Purpose:  Stores the direction for the specified hole set in a 
             <i>ProNcseqElem</i> data structure. <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      dir            - The drilling direction

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetAxisAdd  (ProNcseqElem                 elem,
                                              int                          set_nmb,
                                              PRO_CONST_ARG ProSelection   axis);
/*
   Purpose:  Stores an axis to be machined for the specified hole set
             in a <i>ProNcseqElem</i> data structure.  <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information 
      set_nmb        - The number of the hole set on which to operate
      axis           - The axis to be machined

   Output Arguments:
      None       

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetDrillpartAdd (ProNcseqElem                 elem,
                                                  int                          set_nmb,
                                                   PRO_CONST_ARG ProSelection   drl_part);
/*
   Purpose:  Stores the part to be drilled for the specified hole set
             in a <i>ProNcseqElem</i> data structure.  <b>Please note that this
             routine and the associated PRO_E_HOLES element are provided solely
             for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      drl_part       - The part to be machined

   Output Arguments:
      None        

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemHolesetCsinkdiamSet  (ProNcseqElem   elem,
                                                int            set_nmb,
                                                double         csink_diameter);
/*
   Purpose:  Stores the countersink diameter for the specified hole set
             in a <i>ProNcseqElem</i> data structure.  <b>Please note that
             this routine and the associated PRO_E_HOLES element are provided
             solely for compatibility with existing Creo Parametric TOOLKIT code.  Wherever
             possible the more powerful PRO_E_HOLESETS element should be used
             instead.</b>
<p>
   Applicable Element Id(s):
<p>
      PRO_E_HOLES

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      set_nmb        - The number of the hole set on which to operate
      csink_diameter - The countersink diameter

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError  ProNcseqElemStartPntSet (ProNcseqElem   elem,
                                           ProMachHead    head,
                                           ProSelection  point);

/*
   Purpose:  Stores the start point selection 
             in a <i>ProNcseqElem</i> data structure.
<p>
   Applicable Element Id(s):
<p>
   PRO_E_START

   Input Arguments:
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      head           - The machining head information
      point          - The selected point

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully stored the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/

extern ProError  ProNcseqElemEndPntSet (ProNcseqElem   elem,
                                           ProMachHead    head,
                                           ProSelection  point);
 
/* 
   Purpose:  Stores the end point selection 
             in a <i>ProNcseqElem</i> data structure.<p> 
   Applicable Element Id(s): 
<p> 
   PRO_E_END 
 
   Input Arguments: 
      elem           - The <i>ProNcseqElem</i> handle in which to store the
                       information
      head           - The machining head information
      point          - The selected point 
 
   Output Arguments:
      None

   Return Values: 
      PRO_TK_NO_ERROR    - The function successfully stored the 
                           information. 
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid. 
*/

PRO_END_C_DECLS


#endif  /* PRONCSEQELEM_H */
