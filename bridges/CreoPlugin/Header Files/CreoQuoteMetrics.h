#pragma once

#include <string>
#include <vector>
#include <ProToolkit.h>
#include <ProMdl.h>

namespace CreoQuotePlugin
{
    struct CreoQuoteFeatureDiagnostic
    {
        int id = 0;
        int type = 0;
        std::wstring name;
        std::string category;
        bool counted = false;
        int constraintCount = 0;
        int patternStatus = 0;
        int groupPatternStatus = 0;
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
        int componentType = 0;
        int modelType = 0;
        std::string placementDefinitionFilterReason;
        bool componentMiscAttributesAvailable = false;
        int componentMiscAttributes = 0;
        std::string constraintSource;
    };

    struct CreoQuoteMetrics
    {
        ProError status = PRO_TK_NO_ERROR;
        std::string errorMessage;
        std::wstring filePath;
        std::wstring fileName;
        std::wstring modelName;
        std::wstring modelExtension;
        std::string documentKind = "Unknown";
        int featureCount = 0;
        int configurationCount = 0;
        int expressionCount = 0;
        int componentCount = 0;
        int mateCount = 0;
        int assemblyFeatureCount = 0;
        int drawingSheetCount = 0;
        int viewCount = 0;
        int noteCount = 0;
        int dimensionCount = 0;
        int tableCount = 0;
        std::vector<std::wstring> parameterNames;
        std::vector<std::wstring> parameterDiagnosticMessages;
        std::vector<std::wstring> filteredParameterMessages;
        std::vector<std::wstring> familyInstanceNames;
        std::wstring configurationSource;
        std::vector<std::wstring> configurationProbeMessages;
        bool previewImageSucceeded = false;
        std::wstring previewImagePath;
        std::string previewImageFormat;
        std::string previewImageError;
        std::vector<CreoQuoteFeatureDiagnostic> featureDiagnostics;
    };

    CreoQuoteMetrics CollectCurrentModelMetrics();
    CreoQuoteMetrics CollectFileMetrics(const std::wstring& filePath, const std::wstring& previewOutputPath = std::wstring());
    std::string MetricsToJson(const CreoQuoteMetrics& metrics);
    std::wstring GetDefaultMetricsPath();
    bool WriteMetricsJson(const CreoQuoteMetrics& metrics, const std::wstring& outputPath);
}
