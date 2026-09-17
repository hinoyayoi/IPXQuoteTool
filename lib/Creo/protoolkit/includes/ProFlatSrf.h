#ifndef PROFLATSRF_H
#define PROFLATSRF_H

/*
   Creo Parametric TOOLKIT declarations related related to flat datum surface feature
*/



#include <ProToolkit.h>


PRO_BEGIN_C_DECLS

/********************************************************************\

1. Feature Element Tree (Used for Pro/Engineer 2002 and onward)
-----------------------

  PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEATURE_TYPE
     |
     |--PRO_E_FEATURE_FORM
     |
     |--PRO_E_STD_SECTION   ( Sketch )
     |
     |--PRO_E_STD_FEATURE_NAME (Optional Element)
     |
     |  ( Under SheetMetal mode : )
     |
     |--PRO_E_IS_UNATTACHED_WALL
     |
     |--PRO_E_STD_DIRECTION
     |
     |--PRO_E_STD_SMT_THICKNESS
     |
     |--PRO_E_STD_SMT_SWAP_DRV_SIDE

\********************************************************************/
/********************************************************************\

2. Feature elements table
-----------------------------------------------------------

----------------------------------------------------------------------
Element Id             Element Name   Data Type            
----------------------------------------------------------------------

PRO_E_FEATURE_TYPE             Feature Type       PRO_VALUE_TYPE_INT   
PRO_E_FEATURE_FORM             Feature Form       PRO_VALUE_TYPE_INT   
PRO_E_STD_SECTION              Sketch             Compound Element. 
PRO_E_STD_FEATURE_NAME         Feature Name       PRO_VALUE_TYPE_WSTRING (Optional)

PRO_E_IS_UNATTACHED_WALL       Is Smt wall        PRO_VALUE_TYPE_INT     (Optional)
PRO_E_STD_DIRECTION            Material direction PRO_VALUE_TYPE_INT     (Optional)
PRO_E_STD_SMT_THICKNESS        Wall thickness     PRO_VALUE_TYPE_DOUBLE  (Optional)
PRO_E_STD_SMT_SWAP_DRV_SIDE    Swap side          PRO_VALUE_TYPE_INT     (Optional)

----------------------------------------------------------------------

\********************************************************************/
/********************************************************************\

Table 3  : elements used for Surface Fill and their values.
/=====================================================================\
| Element Id                 |  Value                                 |
|=====================================================================|
|                            |                                        |
| PRO_E_FEATURE_FORM         | Feature Form : PRO_FLAT                |
|                            |                                        |
|---------------------------------------------------------------------|
|                            |                                        |
| PRO_E_FEATURE_TYPE         | Feature Type : PRO_FEAT_DATUM_SURF     |
|                            |                                        |
|---------------------------------------------------------------------|
|                            |                                        |
| PRO_E_STD_SECTION          | Please refer to ProStdSection.h for    | 
|                            | more information.                      |
|                            |                                        |
|---------------------------------------------------------------------|
|                            |                                        |
| PRO_E_STD_FEATURE_NAME     | Default given by application depending |
|                            | on feature type.                       |
|                            |                                        |
\=====================================================================/

Table 4  : elements used for SMT first and unattached wall and their values.
/=========================================================================\
| Element Id                     |  Value                                 |
|=========================================================================|
|                                |                                        |
| PRO_E_IS_UNATTACHED_WALL       | Controls Flat Surface / SMT wall       |
|                                | PRO_B_TRUE / PRO_B_FALSE               |
|                                |                                        |
|-------------------------------------------------------------------------|
|                                |                                        |
| PRO_E_STD_DIRECTION            | Specify the wall material direction    |
|                                |                                        |
|-------------------------------------------------------------------------|
|                                |                                        |
| PRO_E_STD_SMT_THICKNESS        | The first wall thickness.              |
|                                |                                        |
|-------------------------------------------------------------------------|
|                                |                                        |
| PRO_E_STD_SMT_SWAP_DRV_SIDE    | Whether to Swap sides.                 |
|                                |                                        |
\=========================================================================/

\*****************************************************************************/

PRO_END_C_DECLS

#endif
