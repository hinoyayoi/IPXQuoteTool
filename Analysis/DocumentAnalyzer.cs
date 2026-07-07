using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using IPXQuoteTool.Analysis.Assemblies;
using IPXQuoteTool.Analysis.Drawings;
using IPXQuoteTool.Analysis.Parts;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IPXQuoteTool.Analysis
{
    public class DocumentAnalyzer
    {
        private readonly IReadOnlyList<IDocumentMetricExtractor> _extractors;

        public DocumentAnalyzer()
            : this(new IDocumentMetricExtractor[]
            {
                new PartMetricExtractor(),
                new AssemblyMetricExtractor(),
                new DrawingMetricExtractor()
            })
        {
        }

        public DocumentAnalyzer(IEnumerable<IDocumentMetricExtractor> extractors)
        {
            _extractors = extractors.ToList();
        }

        public DocumentInfo Analyze(ModelDoc2 model)
        {
            var documentType = (swDocumentTypes_e)model.GetType();
            var info = new DocumentInfo
            {
                FileName = Path.GetFileName(model.GetPathName()),
                FilePath = model.GetPathName(),
                DocumentType = documentType,
                ConfigurationCount = SolidWorksDocumentMetrics.GetConfigurationCount(model)
            };

            var context = new DocumentAnalysisContext(model, documentType);
            var extractor = _extractors.FirstOrDefault(x => x.SupportedDocumentType == documentType);
            extractor?.Extract(context, info);

            return info;
        }
    }
}
