using SolidWorks.Interop.sldworks;
using SolidWorks.Interop.swconst;
using IPXQuoteTool;
using IPXQuoteTool.Cad.SolidWorks;
using IPXQuoteTool.Cad.SolidWorks.Analysis.Assemblies;
using IPXQuoteTool.Cad.SolidWorks.Analysis.Drawings;
using IPXQuoteTool.Cad.SolidWorks.Analysis.Parts;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IPXQuoteTool.Cad.SolidWorks.Analysis
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
                DocumentType = SolidWorksCadDocumentTypeMapper.ToCadDocumentType(documentType),
                ConfigurationCount = SolidWorksDocumentMetrics.GetConfigurationCount(model)
            };

            var context = new DocumentAnalysisContext(model, documentType);
            var extractor = _extractors.FirstOrDefault(x => x.SupportedDocumentType == documentType);
            extractor?.Extract(context, info);

            return info;
        }
    }
}

