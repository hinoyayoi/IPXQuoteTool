#ifndef PRO_MECH_FEATURE
#define PRO_MECH_FEATURE



#include <ProToolkit.h>
#include <ProAsmcomp.h>
#include <ProFeature.h>

PRO_BEGIN_C_DECLS

extern ProError ProMechFeaturePromote (ProFeature      * pro_feature,
                                       ProAsmcomppath  * comp_path);

/*
   Purpose:
        Promotes the Creo Simulate specific feature making it accessible in Creo Parametric.
        Note that a promoted feature cannot be transferred back to Creo Simulate.

   Licensing Requirement:
          TOOLKIT for Mechanica

   Input Arguments:
        pro_feature - The Creo Simulate specific feature to be promoted
        comp_path   - The path to the part to which the feature belongs.
                      This can be NULL when you are promoting in Part mode or
                      when the feature belongs to the top-level assembly.

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR - The function successfully promoted the feature.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_INVALID_PTR - The Input ProFeature Solid pointer is invalid.
        PRO_TK_E_NOT_FOUND - The Input ProFeature Solid could not be retrieved.
        PRO_TK_BAD_CONTEXT - Promote command is not applicable for the input feature.
        PRO_TK_GENERAL_ERROR - Feature could not be promoted or a general error is encountered.
*/

PRO_END_C_DECLS

#endif
