#ifndef PROMFGELEMMACHSURF_H
#define PROMFGELEMMACHSURF_H
/*
   Creo Parametric TOOLKIT declarations related to specification of machining surfaces
*/



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
     
      -- PRO_E_MACH_SURFS
           |
	   |-- PRO_E_MACH_SURF_OPT
	   |
	   |-- PRO_E_MACH_SURF_COMP
	   |     |
           |     |-- PRO_E_MACH_SURF_REF_TYPE
	   |     |
	   |     |-- PRO_E_STD_SURF_COLLECTION_APPL
	   |
	   |-- PRO_E_MFG_MILL_WIND_SRF
	   |
	   |-- PRO_E_MACH_SURF_PREV_STEP
	   |
	   |-- PRO_E_MACH_SRF_FLIP
           |      
==============================================================================

(2) Elements table

------------------------------------------------------------------------------------------
Element Id                      Element Name            Data Type                 Valid Value
------------------------------------------------------------------------------------------
PRO_E_MACH_SURFS                Mach Surfaces              Compound                  Note-1 
PRO_E_MACH_SURF_OPT             Selection Type             PRO_VALUE_TYPE_INT        Note-2
PRO_E_MACH_SURF_COMP            Surface Collection General Compound                  Note-3
PRO_E_MACH_SURF_REF_TYPE        Reference Type             PRO_VALUE_TYPE_INT        Note-4 
PRO_E_STD_SURF_COLLECTION_APPL  Surface Collection         Surface Collection        Note-5
PRO_E_MFG_MILL_WIND_SRF         Window Selection           PRO_VALUE_TYPE_SELECTION  Note-6 
PRO_E_MACH_SURF_PREV_STEP       Previous Step              PRO_VALUE_TYPE_SELECTION  Note-7 
PRO_E_MACH_SRF_FLIP             Flip Quilt                 PRO_VALUE_TYPE_INT        Note-8 

==============================================================================

(3) Notes

Note-1  : Machine surfaces compound element.

Note-2  : Option controlling what object is to be selected.
    PRO_MACH_SURF_OPT_SURFACES, if Surface Collection will be defined;
    PRO_MACH_SURF_OPT_MILL_WIND, if Window Selection will be defined (for Face Milling);
    PRO_MACH_SURF_OPT_PREV_STEP, if  Previous Step will be defined (not for Face Milling);

Note-3  : Surface Collection General compound element.

Note-4  : Reference type

           PRO_SURF_REF_TYPE_REFPART      
           PRO_SURF_REF_TYPE_WORKPIECE
           PRO_SURF_REF_TYPE_MILL_VOLUME
           PRO_SURF_REF_TYPE_MILL_MVOLSRF
           PRO_SURF_REF_TYPE_PREV_STEP
           PRO_SURF_REF_TYPE_MILL_WINDOW
           PRO_SURF_REF_TYPE_TOP_ASSEM_SRF

  If PRO_E_STD_SURF_COLLECTION_APPL is defined, Reference Type should be 
  one of 
  (  PRO_SURF_REF_TYPE_REFPART, 
     PRO_SURF_REF_TYPE_WORKPIECE, 
     PRO_SURF_REF_TYPE_MILL_VOLUME,
     PRO_SURF_REF_TYPE_MILL_MVOLSRF, 
     PRO_SURF_REF_TYPE_TOP_ASSEM_SRF ).
  If PRO_E_MFG_MILL_WIND_SRF is defined, Reference Type should be 
     PRO_SURF_REF_TYPE_MILL_WINDOW.
  If PRO_E_MACH_SURF_PREV_STEP is defined, Reference Type should be
     PRO_SURF_REF_TYPE_PREV_STEP.

Note-5  : Collection of selected surfaces to be machined.
          Mandatory if neither PRO_E_MFG_MILL_WIND_SRF nor 
          PRO_E_MACH_SURF_PREV_STEP are defined.
          Must not be set otherwise.

Note-6  : Selection of a mill window feature.
          Mandatory if neither PRO_E_STD_SURF_COLLECTION_APPL nor 
          PRO_E_MACH_SURF_PREV_STEP are defined. 
          Must not be set otherwise.

Note-7  : Selection of a NC Step feature.
          Mandatory if neither PRO_E_STD_SURF_COLLECTION_APPL nor 
          PRO_E_MFG_MILL_WIND_SRF
          are defined. 
          Must not be set otherwise.



Note-8  :  Flip Quilt
 
          PRO_B_FALSE - surfaces are to be machined on the side defined by 
                        the default normal
          PRO_B_TRUE - surfaces are to be machined on the opposite side.

  Mandatory if PRO_E_MACH_SURFS is defined and Reference Type is set to
  PRO_SURF_REF_TYPE_MILL_MVOLSRF.

============================================================================*/


PRO_END_C_DECLS

#endif /*PROMFGELEMMACHSURF_H*/
