#pragma once

#include <string>
#include <vector>

#include <ProAsmcomp.h>
#include <ProFeature.h>
#include <ProFeatType.h>
#include <ProMdl.h>
#include <ProPattern.h>
#include <ProSolid.h>

namespace CreoQuotePlugin
{
    struct CreoQuoteAssemblyComponent
    {
        ProFeature feature = {};
        ProFeattype featureType = 0;
        std::string category;
        int constraintCount = 0;
        std::string constraintSource;
        int patternStatus = 0;
        int groupPatternStatus = 0;
        bool groupMember = false;
        bool placed = false;
        bool packaged = false;
        bool unplaced = false;
        bool frozen = false;
        bool bulkItem = false;
        bool substitute = false;
        bool underconstrained = false;
        bool readOnly = false;
        bool incomplete = false;
        bool statusFlagsAvailable = false;
        unsigned int statusFlags = 0;
        std::string placementDefinitionFilterReason;
        ProAsmcompType componentType = PRO_ASM_COMP_TYPE_NONE;
        bool componentMiscAttributesAvailable = false;
        int componentMiscAttributes = 0;
        ProMdlType modelType = PRO_MDL_UNUSED;
    };

    struct CreoQuoteAssemblyFeature
    {
        ProFeature feature = {};
        ProFeattype featureType = 0;
        std::string category;
        int patternStatus = 0;
        int groupPatternStatus = 0;
        bool groupMember = false;
    };

    struct CreoQuoteAssemblyCounts
    {
        int componentCount = 0;
        int constraintCount = 0;
        int assemblyFeatureCount = 0;
        std::vector<CreoQuoteAssemblyComponent> components;
        std::vector<CreoQuoteAssemblyFeature> assemblyFeatures;
    };

    CreoQuoteAssemblyCounts CollectQuoteAssemblyCounts(ProSolid solid);
}

