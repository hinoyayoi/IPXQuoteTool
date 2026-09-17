#ifndef PROFIXTURE_H
#define PROFIXTURE_H

/* ProFixture.h:  defines actions specific to fixtures */

#include <ProObjects.h>



/*****************************************************************************\

WARNING: This Feature element tree is deprecated and will be removed in subsequent
releases. Refer to this header for replacement:

ProMfgFeatFixture.h


Feature element tree

   PRO_E_FEATURE_TREE
     |
     |--PRO_E_FEAT_TYPE               Non-redefinable
     |
     !--PRO_E_ASSEM_SETUP_TYPE        Non-redefinable
     |
     |--PRO_E_OPERATION
     |
     |--PRO_E_FEAT_NAME               Optional element
     |
     |--PRO_E_FIXT_COMPONENTS         Optional element - multiple values
     |
     |--PRO_E_SETUP_TIME              Optional element

FEATURE ELEMENTS TABLE

--------------------------------------------------------------------------------
Element Id             Element Name       Data Type           Valid Values
                                          (PRO_VALUE_TYPE)
--------------------------------------------------------------------------------
PRO_E_FEAT_TYPE        Feature type       INT                 PRO_FEAT_FIXSETUP
PRO_E_ASSEM_SETUP_TYPE Assem setup type   INT                 ProAssemSetupType
PRO_E_OPERATION        Mfg operation      INT                 Operation feature id
PRO_E_FEAT_NAME        Feature Name       WSTRING             Feature name
PRO_E_FIXT_COMPONENTS  Fixture components INT ARRAY           Fixt component ids
PRO_E_SETUP_TIME       Setup time         DOUBLE              Number of minutes
--------------------------------------------------------------------------------

NOTES:

\******************************************************************************/

typedef enum
{
   PRO_FIXTURE_SETUP,
   PRO_REF_MODEL_SETUP,
   PRO_WORKPIECE_SETUP
} ProAssemSetupType;

#endif /* PROFIXTURE_H */
