#ifndef PROMFGELEMAPROACHEXIT_H
#define PROMFGELEMAPROACHEXIT_H




#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/*============================================================================

(1) Element tree
    
    -- PRO_E_MFG_CMP_APPROACH_EXIT
          |
          |-- PRO_E_MFG_CMP_APPROACH
          |      |
          |      |-- PRO_E_MFG_APPROACH_AXIS
          |      |
          |      |-- PRO_E_MFG_FIRST_SLICE_ONLY
          |
          |-- PRO_E_MFG_CMP_EXIT
          |      |
          |      |-- PRO_E_MFG_EXIT_AXIS
          |      |
          |      |-- PRO_E_MFG_LAST_SLICE_ONLY

===============================================================================

(2) Elements table

----------------------------------------------------------------------------------------------
Element Id                    Element Name              Data Type                 Valid Values
----------------------------------------------------------------------------------------------

PRO_E_MFG_CMP_APPROACH_EXIT   Approach/Exit            Compound                  Note-1
PRO_E_MFG_CMP_APPROACH        Approach                 Compound                  Note-2
PRO_E_MFG_APPROACH_AXIS       Approach Axis Selection  PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_MFG_FIRST_SLICE_ONLY    First Slice Only         PRO_VALUE_TYPE_INT        Note-4
PRO_E_MFG_CMP_EXIT            Exit                     Compound                  Note-5 
PRO_E_MFG_EXIT_AXIS           Exit Axis Selection      PRO_VALUE_TYPE_SELECTION  Note-6
PRO_E_MFG_LAST_SLICE_ONLY     Last Slice Only          PRO_VALUE_TYPE_INT        Note-7
==============================================================================================

(3) Notes

Note-1  :  Approach/Exit compound.

Note-2  :  Approach compound. Combines approach axis and First Slice Only.
           Optional.

Note-3  :  Selection of a vertical datum axis.
           Optional.

Note-4  :  Flag (True/False). 
           Mandatory if PRO_E_MFG_APPROACH_AXIS is set. Not used otherwise.

Note-5  :  Exit compound. Combines exit axis and Last Slice Only.
 
Note-6  :  Selection of a vertical datum axis.
           Optional.

Note-7  :  Flag (True/False). 
           Mandatory if PRO_E_MFG_EXIT_AXIS is set. Not used otherwise.

==============================================================================*/

PRO_END_C_DECLS

#endif /* PROMFGELEMAPROACHEXIT_H */
