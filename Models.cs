using SolidWorks.Interop.swconst;

namespace IPXQuoteTool
{
    /// <summary>
    /// 文档基础信息
    /// </summary>
    public class DocumentInfo
    {
        public string FileName { get; set; }
        public string FilePath { get; set; }
        public swDocumentTypes_e DocumentType { get; set; }
        
        // 通用
        public int ConfigurationCount { get; set; }
        public int ExpressionCount { get; set; }
        
        // 零件特有
        public int FeatureCount { get; set; }
        
        // 装配体特有
        public int ComponentCount { get; set; }
        public int MateCount { get; set; }
        public int AssemblyFeatureCount { get; set; }
        
        // 工程图特有
        public int ViewCount { get; set; }
        public int NoteCount { get; set; }
        public int DimensionCount { get; set; }
        public int TableCount { get; set; }

        // 报表示例图
        public byte[] PreviewImageBytes { get; set; }

        public string Category => DocumentType switch
        {
            swDocumentTypes_e.swDocPART => "零件",
            swDocumentTypes_e.swDocASSEMBLY => "装配",
            swDocumentTypes_e.swDocDRAWING => "工程图",
            _ => "未知"
        };
    }

    /// <summary>
    /// 组件信息
    /// </summary>
    public class ComponentInfo
    {
        public string Name { get; set; }
        public string Configuration { get; set; }
        public int Level { get; set; }
        public int Quantity { get; set; }
    }

    /// <summary>
    /// 工程图信息
    /// </summary>
    public class DrawingInfo
    {
        public string SheetName { get; set; }
        public int ViewCount { get; set; }
        public int NoteCount { get; set; }
        public int DimensionCount { get; set; }
        public int TableCount { get; set; }
    }
}
