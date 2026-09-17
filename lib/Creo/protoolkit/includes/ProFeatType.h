#ifndef PROFEATTYPEH
#define PROFEATTYPEH




#define PRO_FEAT_FIRST_FEAT   0       /* This feature is a protrusion */

#define PRO_FEAT_HOLE		911
#define PRO_FEAT_SHAFT		912
#define PRO_FEAT_ROUND		913
#define PRO_FEAT_CHAMFER	914
#define PRO_FEAT_SLOT		915
#define PRO_FEAT_CUT		916
#define PRO_FEAT_PROTRUSION	917
#define PRO_FEAT_NECK		918
#define PRO_FEAT_FLANGE		919
#define PRO_FEAT_RIB		920
#define PRO_FEAT_EAR		921
#define PRO_FEAT_DOME		922
#define PRO_FEAT_DATUM		923
#define PRO_FEAT_LOC_PUSH	924
/* #define PRO_FEAT_PATTERN	925 */

#define PRO_FEAT_UDF          925

#define PRO_FEAT_DATUM_AXIS   926
#define PRO_FEAT_DRAFT        927
#define PRO_FEAT_SHELL	928
#define PRO_FEAT_DOME2	929
#define PRO_FEAT_CORN_CHAMF	930
#define PRO_FEAT_DATUM_POINT	931
#define PRO_FEAT_IMPORT	932
#define PRO_FEAT_IGES		PRO_FEAT_IMPORT /* Don't use PRO_FEAT_IGES */
#define PRO_FEAT_COSMETIC     933
#define PRO_FEAT_ETCH         934
#define PRO_FEAT_MERGE        935
#define PRO_FEAT_MOLD         936
#define PRO_FEAT_SAW          937
#define PRO_FEAT_TURN         938
#define PRO_FEAT_MILL         939
#define PRO_FEAT_DRILL        940
#define PRO_FEAT_OFFSET       941
#define PRO_FEAT_DATUM_SURF   942
#define PRO_FEAT_REPLACE_SURF 943
#define PRO_FEAT_GROOVE       944
#define PRO_FEAT_PIPE         945
#define PRO_FEAT_DATUM_QUILT  946
#define PRO_FEAT_ASSEM_CUT    947
#define PRO_FEAT_UDF_THREAD   948
#define PRO_FEAT_CURVE        949
#define PRO_FEAT_SRF_MDL      950
#define PRO_FEAT_WALL         952
#define PRO_FEAT_BEND         953
#define PRO_FEAT_UNBEND       954
#define PRO_FEAT_CUT_SMT      955
#define PRO_FEAT_FORM         956
#define PRO_FEAT_THICKEN      957
#define PRO_FEAT_BEND_BACK    958
#define PRO_FEAT_UDF_NOTCH    959
#define PRO_FEAT_UDF_PUNCH    960
#define PRO_FEAT_INT_UDF      961
#define PRO_FEAT_SPLIT_SURF   962
#define PRO_FEAT_GRAPH        963
#define PRO_FEAT_SMT_MFG_PUNCH 964
#define PRO_FEAT_SMT_MFG_CUT  965
#define PRO_FEAT_FLATTEN      966
#define PRO_FEAT_SET          967	/* PRO_FEAT_SET & PRO_FEAT_VDA are old types */
#define PRO_FEAT_VDA          968
#define PRO_FEAT_SMT_MFG_FORM 969
#define PRO_FEAT_SMT_PUNCH_PNT 970
#define PRO_FEAT_LIP          971
#define PRO_FEAT_MANUAL       972
#define PRO_FEAT_MFG_GATHER	973
#define PRO_FEAT_MFG_TRIM	974
#define PRO_FEAT_MFG_USEVOL   975
#define PRO_FEAT_LOCATION     976
#define PRO_FEAT_CABLE_SEGM   977
#define PRO_FEAT_CABLE        978
#define PRO_FEAT_CSYS         979
#define PRO_FEAT_CHANNEL      980
#define PRO_FEAT_WIRE_EDM     PRO_FEAT_SAW
#define PRO_FEAT_AREA_NIBBLE	981
#define PRO_FEAT_PATCH        982
#define PRO_FEAT_PLY          983
#define PRO_FEAT_CORE         984
#define PRO_FEAT_EXTRACT	985
#define PRO_FEAT_MFG_REFINE   986
#define	PRO_FEAT_SILH_TRIM	987
#define PRO_FEAT_SPLIT	988
#define	PRO_FEAT_EXTEND	989
#define PRO_FEAT_SOLIDIFY     990
#define PRO_FEAT_INTERSECT    991
#define PRO_FEAT_ATTACH       992
#define PRO_FEAT_XSEC		993
#define	PRO_FEAT_UDF_ZONE	994
#define	PRO_FEAT_UDF_CLAMP	995
#define PRO_FEAT_DRL_GRP	996
#define PRO_FEAT_ISEGM        997
#define PRO_FEAT_CABLE_COSM	998
#define	PRO_FEAT_SPOOL	999

#define PRO_FEAT_COMPONENT   1000

#define	PRO_FEAT_MFG_MERGE   1001
#define	PRO_FEAT_FIXSETUP    1002
#define	PRO_FEAT_SETUP	PRO_FEAT_FIXSETUP
#define	PRO_FEAT_FLAT_PAT    1003
#define PRO_FEAT_CONT_MAP    1004
#define PRO_FEAT_EXP_RATIO   1005
#define PRO_FEAT_RIP         1006
#define PRO_FEAT_OPERATION   1007
#define PRO_FEAT_WORKCELL    1008

#define PRO_FEAT_CUT_MOTION  1009
#define PRO_FEAT_PUNCH_QUILT 1010
#define PRO_FEAT_BLD_PATH    1013
#define PRO_FEAT_CUSTOMIZE   PRO_FEAT_BLD_PATH
#define PRO_FEAT_DRV_TOOL_SKETCH  1014
#define PRO_FEAT_DRV_TOOL_EDGE    1015
#define PRO_FEAT_DRV_TOOL_CURVE   1016
#define PRO_FEAT_DRV_TOOL_SURF    1017

#define PRO_FEAT_MAT_REMOVAL 1018
#define PRO_FEAT_TORUS       1019

#define PRO_FEAT_PIPE_SET_START  1020
#define PRO_FEAT_PIPE_PNT_PNT    1021
#define PRO_FEAT_PIPE_EXT        1022
#define PRO_FEAT_PIPE_TRIM       1023
#define PRO_FEAT_PIPE_FOLL       1024
#define PRO_FEAT_PIPE_JOIN       1025


#define PRO_FEAT_AUXILIARY    1026

#define PRO_FEAT_PIPE_LINE       1027
#define PRO_FEAT_LINE_STOCK      1028

#define PRO_FEAT_SLD_PIPE	   1029
#define PRO_FEAT_BULK_OBJECT     1030
#define PRO_FEAT_SHRINKAGE   	   1031

#define PRO_FEAT_PIPE_JOINT	   1032
#define PRO_FEAT_PIPE_BRANCH	   1033

#define PRO_FEAT_DRV_TOOL_TWO_CNTR	1034

#define PRO_FEAT_SUBHARNESS      1035

#define PRO_FEAT_SMT_OPTIMIZE    1036

#define PRO_FEAT_DECLARE         1037

#define PRO_FEAT_SMT_POPULATE    1038

#define PRO_FEAT_OPER_COMP       1039

#define PRO_FEAT_MEASURE         1040

#define PRO_FEAT_DRAFT_LINE      1041

#define PRO_FEAT_REMOVE_SURFS    1042

#define PRO_FEAT_RIBBON_CABLE    1043

#define PRO_FEAT_ATTACH_VOLUME   1046
#define	PRO_FEAT_BLD_OPERATION   1047

#define PRO_FEAT_UDF_WRK_REG     1048
#define PRO_FEAT_SPINAL_BEND     1049

#define PRO_FEAT_TWIST           1050

#define PRO_FEAT_FREE_FORM       1051

#define PRO_FEAT_ZONE            1052


#define PRO_FEAT_WELDING_ROD     1053
#define PRO_FEAT_WELD_FILLET     1054
#define PRO_FEAT_WELD_GROOVE     1055
#define PRO_FEAT_WELD_PLUG_SLOT  1056
#define PRO_FEAT_WELD_SPOT       1057

#define PRO_FEAT_SMT_SHEAR       1058

#define PRO_FEAT_PATH_SEGM       1059
#define PRO_FEAT_RIBBON_SEGM     1060
#define PRO_FEAT_RIBBON_PATH     PRO_FEAT_PATH_SEGM
#define PRO_FEAT_RIBBON_EXTEND   PRO_FEAT_RIBBON_SEGM

#define PRO_FEAT_ASMCUT_COPY     1061

#define PRO_FEAT_DEFORM_AREA     1062

#define PRO_FEAT_RIBBON_SOLID      1063
#define PRO_FEAT_FLAT_RIBBON_SEGM  1064
#define PRO_FEAT_POSITION_FOLD     1065

#define PRO_FEAT_SPRING_BACK       1066
#define PRO_FEAT_BEAM_SECTION      1067
#define PRO_FEAT_SHRINK_DIM        1068

/* #1069 unused */

#define PRO_FEAT_THREAD            1070

#define PRO_FEAT_SMT_CONVERSION    1071

#define PRO_FEAT_CMM_MEASSTEP      1072
#define PRO_FEAT_CMM_CONSTR        1073
#define PRO_FEAT_CMM_VERIFY        1074

#define PRO_FEAT_CAV_SCAN_SET      1075

#define PRO_FEAT_CAV_FIT           1076
#define PRO_FEAT_CAV_DEVIATION     1077

#define PRO_FEAT_SMT_ZONE          1078
#define PRO_FEAT_SMT_CLAMP         1079

#define PRO_FEAT_PROCESS_STEP      1080

#define PRO_FEAT_EDGE_BEND         1081       

#define PRO_FEAT_DRV_TOOL_PROF     1082

#define PRO_FEAT_EXPLODE_LINE      1083

#define PRO_FEAT_GEOM_COPY         1084

#define PRO_FEAT_ANALYSIS          1085

#define PRO_FEAT_WATER_LINE        1086

#define PRO_FEAT_UDF_RMDT          1087

#define PRO_FEAT_VOL_SPLIT         1088

#define PRO_FEAT_WLD_EDG_PREP      1089

#define PRO_FEAT_SMM_OFFSET        1090 
#define PRO_FEAT_SMM_MATREM        1091
#define PRO_FEAT_SMM_COSMETIC      1092
#define PRO_FEAT_SMM_APPROACH      1093
#define PRO_FEAT_SMM_SLOT          1094
#define PRO_FEAT_SMM_SHAPE         1095
#define PRO_FEAT_IPM_QUILT         1096  
#define PRO_FEAT_DRVD              1097
#define PRO_FEAT_SMT_CRN_REL       1098
#define PRO_FEAT_SLDBEND           1101
#define PRO_FEAT_FLATQLT	   1102
#define PRO_FEAT_DRV_TOOL_TURN	   1103

#define PRO_FEAT_GROUP_HEAD        1104

#define PRO_FEAT_FR_SYS            1105
#define PRO_FEAT_HULL_COMPT        1106
#define PRO_FEAT_REFERENCE         1107
#define PRO_FEAT_SHELL_EXP         1108
#define PRO_FEAT_FREEFORM          1109     /* Style feature */
#define PRO_FEAT_KERNEL		   1110
#define PRO_FEAT_WELD_PROCESS      1111

#define PRO_FEAT_HULL_REP_TMP      1112

#define PRO_FEAT_INSULATION        1113
#define PRO_FEAT_SLD_PIP_INSUL     1114

#define PRO_FEAT_SMT_EXTRACT       1115
#define PRO_FEAT_ASSY_MERGE        1116  

#define PRO_FEAT_DS_OPTIMIZE       1117

#define PRO_FEAT_COMP_INTERFACE    1118

#define PRO_FEAT_OLE               1119

#define PRO_FEAT_TERMINATOR        1120

#define PRO_FEAT_WLD_NOTCH         1121  
#define PRO_FEAT_ASSY_WLD_NOTCH    1122  
#define PRO_FEAT_ROUTE_MANAGER     1123
#define PRO_FEAT_HULL_WLD_NOTCH    1124

#define PRO_FEAT_SMM_SLIT          1125
#define PRO_FEAT_SMM_HOLE          1126
#define PRO_FEAT_SMM_NEST          1127
#define PRO_FEAT_SMM_GROOVE        1128
#define PRO_FEAT_SMM_ETCH          1129
#define PRO_FEAT_ROUTE_PATH        1130

#define PRO_FEAT_HULL_PLATE        1211
#define PRO_FEAT_HULL_HOLE 	   1212
#define PRO_FEAT_HULL_CUTOUT       1213
#define PRO_FEAT_HULL_STIFFENER    1214
#define PRO_FEAT_HULL_BEAM         1215
#define PRO_FEAT_HULL_ENDCUT       1216
#define PRO_FEAT_HULL_WLD_FLANGE   1217
#define PRO_FEAT_HULL_COLLAR       1218
#define PRO_FEAT_HULL_DRAW         1219
#define PRO_FEAT_HULL_BRACKET      1220
#define PRO_FEAT_HULL_FOLDED_FLG   1221
#define PRO_FEAT_HULL_BLOCK        1222 
#define PRO_FEAT_HULL_BLOCK_DEF    1223 
#define PRO_FEAT_HULL_SPLIT_BOUND  1224
#define PRO_FEAT_SUPERQUILT        1225
#define PRO_FEAT_MLD_SLIDER        1226
#define PRO_FEAT_HULL_PAD          1227
#define PRO_FEAT_ROUTE_SPOOL       1228
#define PRO_FEAT_GLOBAL_MODEL      1229
#define PRO_FEAT_HULL_MITRE        1230
#define PRO_FEAT_HULL_SLOTCUT      1231

#define PRO_FEAT_PATTERN_HEAD      1232
#define PRO_FEAT_FLEX_MUTATOR      1233
#define PRO_FEAT_ANNOTATION        1234
#define PRO_FT_GR_REMOVE_SURFS     1235
#define PRO_FT_GR_TAPER_EXTR       1236
#define PRO_FT_GR_TOOL_COMP        1237
#define PRO_FEAT_GEN_MERGE         1238
#define PRO_FEAT_PM_DAMPER         1239
#define PRO_FEAT_PM_SPRING         1240
#define PRO_FEAT_AUTO_ROUND        1241
#define PRO_FEAT_DSGNT_AREA        1242
#define PRO_FEAT_RM_SURF           1243
#define PRO_FEAT_ARTWORK	       1244
#define PRO_FEAT_PM_BELT           1245
#define PRO_FEAT_WELD_COMBINE      1246
#define PRO_FEAT_PM_CONTACT3D      1247
#define PRO_FEAT_RS_GENERATOR      1248
#define PRO_FEAT_RS_TRJ_MOVE       1249
#define PRO_FEAT_PLASTIC_RIB       1250
#define PRO_FEAT_PM_BELT_CURVE     1251
#define PRO_FEAT_VPDD              1252 /* Variable Pull Direction Draft */
#define PRO_FEAT_SUBDIVISION	   1253
#define PRO_FEAT_FLEXMOVE          1254
#define PRO_FEAT_PM_BUSHING_LD     1255
#define PRO_FEAT_FLXATTACH         1256
#define PRO_FEAT_FLEXSUBST         1257
#define PRO_FEAT_MOD_ROUND         1258
#define PRO_FEAT_CE_GEOM           1259
#define PRO_FEAT_ANALYT_GEOM       1260
#define PRO_FEAT_STAMPED_AREA      1262
#define PRO_FEAT_FLX_OGF           1263
#define PRO_FEAT_CE_COMP           1264
#define	PRO_FEAT_MFGPTM_MATREM	   1265
#define PRO_FEAT_SPLIT_SRF_RGN     1266
#define PRO_FEAT_DERIVED_MEMBER    1267
#define PRO_FEAT_ACCEPT_CRITERIA   1268
#define PRO_MOLD_SHUTOFF_SRF       1269
#define PRO_FEAT_SMT_SKETCH_FORM   1270
#define PRO_FEAT_JOIN_WALLS        1271
#define PRO_FEAT_FLX_SOLVER        1272
#define PRO_FEAT_CE_SKET           1273
#define PRO_MOLD_SKIRT_EXT_FEAT    1274
#define PRO_MOLD_SKIRT_FILL_FEAT   1275
#define PRO_FEAT_MOD_CHAMFER       1276
#define PRO_FEAT_RCG_ROUND         1277
#define PRO_FEAT_RCG_CHAMFER       1278
#define PRO_FEAT_UNRCG_ROUND       1279
#define PRO_FEAT_UNRCG_CHAMFER     1280
#define PRO_FEAT_ECAD_CU_AREAS     1281
#define PRO_FEAT_REFPART_CUTOUT    1282 /* reserved for internal use */
#define PRO_FEAT_PM_MOTOR          1283 /* reserved for internal use */
#define PRO_FEAT_PRTSPLIT          1284 /* reserved for internal use */
#define PRO_FEAT_ECAD_CUTS         1285 /* reserved for internal use */
#define PRO_FEAT_SMT_RECOGNITION   1286 /* reserved for internal use */
#define PRO_FEAT_LATTICE           1287 /* reserved for internal use */
#define PRO_FEAT_EDIT_BEND         1288 /* reserved for internal use */
#define PRO_FEAT_EDIT_BEND_RELIEF  1289 /* reserved for internal use */
#define PRO_FEAT_EDIT_CORNER_RELIEF 1290 /* reserved for internal use */
#define PRO_FEAT_MOLD_INSERT        1291 /* reserved for internal use */
#define PRO_FEAT_EDIT_CORNER_SEAM   1292 /* reserved for internal use */
#define PRO_FEAT_CUSTOM             1294
#define PRO_FEAT_CUSTOM_GRANITE     1295
#define PRO_FEAT_SENSOR             1296 /* reserved for internal use */
#define PRO_FEAT_PART_COMP          1297 /* reserved for internal use */
#define PRO_FEAT_PULL_WALL          1298 /* reserved for internal use */

#define PRO_FEAT_USER_FEAT         2000  




#endif
