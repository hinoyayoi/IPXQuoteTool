#ifndef PROELEMIDH
#define PROELEMIDH
 





typedef int ProElemId;

#define PRO_E_SECTION                                 1
        /* 2 is not used */
#define PRO_E_EXT_DEPTH                               3
#define PRO_E_THICKNESS                               4
#define PRO_E_MATRLSIDE                               5
#define PRO_E_REV_ANGLE                               6
#define PRO_E_ATTRIBUTES                              7
#define PRO_E_DIRECTION                               8
#define PRO_E_BLN_TANGENCY                            9
#define PRO_E_QUILT                                  10
#define PRO_E_TRIM_QUILT                             11
#define PRO_E_TRAJECTORY                             12
#define PRO_E_PIVOT_DIR                              13
#define PRO_E_XVEC_TRAJ                              14
#define PRO_E_OPT_TRAJ                               15
#define PRO_E_AREA_GRAPH                             16
#define PRO_E_HSWP_PITCH                             17
#define PRO_E_SECTOSRF_SRFS                          18
#define PRO_E_SRFTOSRF_SRF1                          19
#define PRO_E_SRFTOSRF_SRF2                          20
#define PRO_E_IMP_BLN_CSYS                           21
#define PRO_E_IMP_BLN_SEC                            22
#define PRO_E_IMP_SEC_FLIP                           23
#define PRO_E_SRF_OFFS_SRF                           24
#define PRO_E_SRF_OFFS_OFFSET                        25
#define PRO_E_SRF_COPY_SRFS                          26
#define PRO_E_PATTERN                                27
#define PRO_E_BLEND_DEPTH                            28
#define PRO_E_SIL_TRM_PLANE                          29
#define PRO_E_SIL_TRM_SIDE                           30
#define PRO_E_INT_PARTS                              31
#define PRO_E_BLEND_ITEMS                            32
#define PRO_E_CONIC_PARAM                            33
#define PRO_E_CTRL_POINT                             34
#define PRO_E_TANGENCY                               35
#define PRO_E_SMOOTHNESS                             36
#define PRO_E_NUM_U_PATCH                            37
#define PRO_E_NUM_V_PATCH                            38
#define PRO_E_BOUNDARIES                             39

#define PRO_E_CRV_DRFT_REF_DIR                       40
#define PRO_E_DRFT_SRFS                              41
#define PRO_E_DRFT_NEUT_CRV1                         42
#define PRO_E_DRFT_NEUT_CRV2                         43
#define PRO_E_DRFT_PARTING_SRF                       44
#define PRO_E_DRFT_SIDE                              45
#define PRO_E_CRV_DRFT_PNTS                          46
#define PRO_E_CRV_DRFT_ANGLES                        47
#define PRO_E_DRFT_NEUT_PLN                          48
#define PRO_E_DRFT_DIR                               49
#define PRO_E_PLN_DRFT_REF_DIR                       50
#define PRO_E_DRFT_SECTION                           51
#define PRO_E_PLN_DRFT_PNTS                          52
#define PRO_E_PLN_DRFT_ANGLES                        53
        /* 54 not used */

        /* PRO_E_ for free form */
#define PRO_E_FFRM_BASE_SRF                          55
#define PRO_E_FFRM_GRID                              56
#define PRO_E_FFRM_MANIPULATE                        57
        /* 58 not used */

        /* PRO_E_ for trim by curve surface */
#define PRO_E_CRV_TRIM_QLT                           59
#define PRO_E_CRV_TRIM_CRV                           60
#define PRO_E_CRV_TRIM_DIR                           61
        /* 62 not used */

        /* PRO_E_ for trim by fillet surface */
#define PRO_E_FILLET_TRIM_VERT                       63
#define PRO_E_FILLET_TRIM_RADIUS                     64
        /* 65 not used */

        /* PRO_E_ for edge chamfers */
#define PRO_E_EDGE_CHAMF_SCHEME                      66
#define PRO_E_EDGE_CHAMF_SRF                         67
#define PRO_E_EDGE_CHAMF_EDGES                       68
        /* 69 not used */

        /* PRO_E_ for corner chamfers */
#define PRO_E_CORNER_CHAMF_CORNER                    70
#define PRO_E_CORNER_CHAMF_DIMS                      71
        /* 72 not used */

        /* PRO_E_ for shell */
#define PRO_E_SHELL_SRF                              73
#define PRO_E_SHELL_THICK                            74
#define PRO_E_SHELL_SPEC_THICK                       75

        /* PRO_E_ for spring back */
#define PRO_E_CRV_EDGE_CHAIN                         76
#define PRO_E_SPRGBK_DIR                             77
#define PRO_E_SPRGBK_SIDE                            78

        /* PRO_E_ for hole & shaft */
#define PRO_E_PLACETYPE                              79
#define PRO_E_PLACEREFS                              80
#define PRO_E_SIDES                                  81
#define PRO_E_DIAMETER                               82

        /* UIE_ for trim line */
#define PRO_E_TMLN_MAP_QLT                           83
#define PRO_E_TMLN_DIE_QLT                           84
#define PRO_E_TMLN_HINGE_CRV                         85
#define PRO_E_TMLN_MAP_CRV                           86
#define PRO_E_TMLN_EXPRESSION                        87
#define PRO_E_TMLN_MATERL_THK                        88
#define PRO_E_TMLN_MATERL_SIDE                       89
#define PRO_E_TMLN_SPINE_CRV                         90
#define PRO_E_TMLN_DIRECTION                         91
#define PRO_E_TMLN_RND_FACTOR                        92

        /* Round */
#define PRO_E_ROUND_TYPE                             93
#define PRO_E_ROUND_SETS                             94
#define PRO_E_RNDSET_ATTR                            95
#define PRO_E_RNDSET_REFS                            96
#define PRO_E_RNDSET_SPINE                           97
#define PRO_E_RNDSET_RAD_PNTS                        98
#define PRO_E_RNDSET_RAD_VAL                         99
#define PRO_E_RND_TRANSITIONS                       100
#define PRO_E_RND_ATTACH_TYPE                       101

        /* PRO_E_ for cosmetic thread */
#define PRO_E_THREAD_SURF                           102
#define PRO_E_THRD_STRT_SRF                         103
#define PRO_E_NOTE_PARAMS                           104

        /* PRO_E_ for surf copy */
#define PRO_E_SRF_COPY_EXCL                         106
#define PRO_E_SRF_COPY_FILL                         107

        /* PRO_E_ for Draft Offset */
#define PRO_E_DFT_OFFSET_SRFS                       108
#define PRO_E_PROFILE_TYPE                          109
#define PRO_E_OFFSET_VALUE                          110
#define PRO_E_BEVEL_ANGLE                           111
#define PRO_E_MIN_ANGLE                             112
#define PRO_E_PULL_DIR                              113

        /* for surf offset and use quilt--thin */
#define PRO_E_SRF_LEAVE_OUT                         115
#define PRO_E_SRF_LIMIT_SRF                         116

#define PRO_E_CUT_DEF                               150
#define PRO_E_FEAT_NAME                             151
#define PRO_E_COMMENTS                              152
#define PRO_E_TOOL                                  153
#define PRO_E_PARAMS                                154
#define PRO_E_CSYS                                  155
#define PRO_E_RETRACT                               156
#define PRO_E_VOLUME                                157
#define PRO_E_SURFACES                              158
#define PRO_E_4AXIS_PLANE                           159
#define PRO_E_CUTLINE_SURFS                         160
#define PRO_E_EXCLUDE_SURFS                         161
#define PRO_E_TOP_SURFS                             162
#define PRO_E_APPR_WALLS                            163
#define PRO_E_THREAD_CYL                            164
#define PRO_E_START_POINT                           165
#define PRO_E_START_CUTLINE                         166
#define PRO_E_END_CUTLINE                           167
#define PRO_E_INNER_CUTLINE                         168
#define PRO_E_SYNCHRONIZE                           169
#define PRO_E_CUT_DIRECTION                         170
#define PRO_E_BNDRY_CONTRS                          171
#define PRO_E_ORDER                                 172
#define PRO_E_AXIS_DEFN                             173
#define PRO_E_CHECK_SURFS                           174
#define PRO_E_REF_GROOVE                            175
#define PRO_E_REF_SEQ                               176
#define PRO_E_CORNER_EDGES                          177
#define PRO_E_STOCK_BOUND                           178
#define PRO_E_AREA                                  179
#define PRO_E_MFG_TRAJECTORY                        180
#define PRO_E_CORNERS                               181
#define PRO_E_THREAD                                182
#define PRO_E_HOLES                                 183
#define PRO_E_END_PLANE                             184
#define PRO_E_XY_PLANE                              185
#define PRO_E_UV_PLANE                              186
#define PRO_E_START                                 187
#define PRO_E_END                                   188
#define PRO_E_SYNC_HEAD1                            189
#define PRO_E_WCELL                                 190
#define PRO_E_MACH_CSYS                             191
#define PRO_E_FROM_PNT                              192
#define PRO_E_HOME_PNT                              193
#define PRO_E_INTER_CUT                             194
#define PRO_E_CUT_ENDS                              195
#define PRO_E_CUT_CORNERS                           196
#define PRO_E_SHAKEAWAY                             197
#define PRO_E_BUILD_CUT                             198
#define PRO_E_CUT_TO_DEPTH                          199
#define PRO_E_CUT_FROM_DEPTH                        200
#define PRO_E_CUT_PLANE                             201
#define PRO_E_BUILD_SLICE                           202
#define PRO_E_BUILD_PASS                            203
#define PRO_E_TOOLING                               204
#define PRO_E_WCELL_TOOL                            205
#define PRO_E_TOOL_TABLE                            206
#define PRO_E_TURRET                                207
#define PRO_E_OPERATION                             208
#define PRO_E_CUTLIN_DEF                            209
#define PRO_E_ENDS                                  210
#define PRO_E_SCALLOP_SRFS                          211
#define PRO_E_FIXTURE                               212
#define PRO_E_GATHER_SELECT                         213
#define PRO_E_GATHER_EXCLUDE                        214
#define PRO_E_GATHER_FILL                           215
#define PRO_E_GATHER_CLOSE                          216
#define PRO_E_TAPER_ANGLE                           217
#define PRO_E_NC_BUILD_CUT                          218
#define PRO_E_GEOM_REFS                             219
#define PRO_E_POINTS                                220
#define PRO_E_PATH                                  221
#define PRO_E_CMM_FEAT_NAME                         222
#define PRO_E_CMM_CON_TYPE                          223
#define PRO_E_CMM_CON_FEATS                         224
#define PRO_E_CMM_VER_TOL                           225
#define PRO_E_CMM_VER_DATUMS                        226
#define PRO_E_CMM_VER_FEATS                         227

#define PRO_E_SPLIT_SRFS                            228
#define PRO_E_SPLIT_CLASSIFY                        229

        /* sheet metall */

#define PRO_E_STEP_SECTION                          230
#define PRO_E_STEP_SURFACE                          231
#define PRO_E_STEP_EDGE                             232
#define PRO_E_STEP_BEND_TBL                         233
#define PRO_E_STEP_RADIUS_TYPE                      234
#define PRO_E_STEP_ATTACH_EDGE                      235
#define PRO_E_STEP_WALL_ANGLE                       236
#define PRO_E_STEP_START_POINT                      237
#define PRO_E_STEP_SKETCH                           238
#define PRO_E_STEP_RELIEF                           239
#define PRO_E_STEP_WALL_TRANS_AREAS                 240
#define PRO_E_STEP_BEND_ANGLE                       241
#define PRO_E_STEP_RADIUS_VAL                       242
#define PRO_E_STEP_EXTR_DEPTH                       243
#define PRO_E_STEP_PL_BND_SIDE                      244
#define PRO_E_STEP_REF_SURFACE                      245
#define PRO_E_STEP_WALL_TRAJ                        246
#define PRO_E_STEP_FIXED_GEOM                       247
#define PRO_E_STEP_UNBND_GEOM                       248
#define PRO_E_STEP_FIXED_EDGE                       249
#define PRO_E_STEP_XSECT_CURV                       250
#define PRO_E_STEP_FIXED_SIDE                       251
#define PRO_E_STEP_TRANS_AREA                       252
#define PRO_E_STEP_TRANS_DEF                        253
#define PRO_E_STEP_BB_FIXED_GEOM                    254
#define PRO_E_STEP_BENDBACK_GEOM                    255
#define PRO_E_STEP_EXTEND_WALL_EDGE                 256
#define PRO_E_STEP_EXTEND_WALL_DIST                 257
#define PRO_E_STEP_TWIST_ATTACH_EDGE                258
#define PRO_E_STEP_TWIST_AXIS                       259
#define PRO_E_STEP_START_WIDTH                      260
#define PRO_E_STEP_END_WIDTH                        261
#define PRO_E_STEP_WALL_LENGTH                      262
#define PRO_E_STEP_TWIST_ANGLE                      263
#define PRO_E_STEP_DEVEL_LENGTH                     264
#define PRO_E_STEP_BENDBACK_FIXED_GEOM              265
#define PRO_E_STEP_BENDBACK_BB_GEOM                 266
#define PRO_E_STEP_EXL_SURF                         267

#define PRO_E_DIM_TYPE                              268

#define PRO_E_STEP_BREAK_PNT                        269
#define PRO_E_STEP_EDGE_RIP                         270
#define PRO_E_STEP_RIP_CONN                         271
#define PRO_E_STEP_EDGE_BEND                        272

        /* cav fit features */
#define PRO_E_FIT_NAME                              273
#define PRO_E_FIT_SC_SET                            274
#define PRO_E_FIT_SURF                              275

#define PRO_E_STEP_SEP_BENDS                        276
#define PRO_E_STEP_DRVSRF                           277
        /* constants for process step */
#define PRO_E_COMPONENTS                            278
#define PRO_E_DESCRIPTION                           279
#define PRO_E_SIMPLFD_REP                           280
#define PRO_E_EXPLODE_STATE                         281
#define PRO_E_POSITION                              282
#define PRO_E_GEN_STEP_TYPE                         283
#define PRO_E_GEN_STEP_REFS                         284
#define PRO_E_TIME_ESTIMATE                         285
#define PRO_E_COST_ESTIMATE                         286

#define PRO_E_PLACMNT_PLANE                         287
#define PRO_E_CNTRBR                                288

#define PRO_E_SCANSET_FILE                          289
#define PRO_E_SCANSET_UNITS                         290

#define PRO_E_TAN_DFT_DRAFT_LINE                    291
#define PRO_E_TAN_DFT_PULL_DIR                      292
#define PRO_E_TAN_DFT_TOP_REF_SURF                  293
#define PRO_E_TAN_DFT_BTM_REF_SURF                  294
#define PRO_E_TAN_DFT_REF_SURF                      295
#define PRO_E_TAN_DFT_TERM_REF_SURFS                296
#define PRO_E_TAN_DFT_DRAFT_SIDE                    297

#define PRO_E_CRV_GET_CSYS                          298
#define PRO_E_CRV_GET_CSYS_TYPE                     299
#define PRO_E_CRV_ENTER_EQUATION                    300

#define PRO_E_CRV_PNTS                              301
#define PRO_E_CRV_TANG                              302

#define PRO_E_CRV_SILH_NAME                         303
#define PRO_E_CRV_SILH_SEL_SURF                     304
#define PRO_E_CRV_SILH_DIRECTION                    305

#define PRO_E_CRV_DL_AUTO_FIRST_REF_CURVE           306
#define PRO_E_CRV_DL_AUTO_SECOND_REF_CURVE          307
#define PRO_E_CRV_DL_AUTO_OUTSIDE_DIR               308
#define PRO_E_CRV_DL_AUTO_RAD_OF_CRV                309

#define PRO_E_CRV_DFT_DFT_ANGLE                     310
#define PRO_E_CRV_DFT_DFT_SEL_SURF                  311
#define PRO_E_CRV_DFT_DFT_FLIP                      312

#define PRO_E_CRV_DL_EXCLUDE_REF_CURVES             313

#define PRO_E_PROJ_CRV_CURVE                        314
#define PRO_E_PROJ_CRV_SURFS                        315
#define PRO_E_PROJ_CRV_DIR                          316

#define PRO_E_CRV_DL_SPLIT_CRV                      317
#define PRO_E_CRV_DL_SPLIT_DIVIDER                  318
#define PRO_E_CRV_DL_SPLIT_FLIP                     319

        /* cav deviation features */
#define PRO_E_DEV_NAME                              320
#define PRO_E_DEV_REF_FIT                           321
#define PRO_E_DEV_TYPE                              322
#define PRO_E_DEV_SURF                              323

#define PRO_E_POINTS_N_PATH                         324

#define PRO_E_CMM_REFCSYS_TRF                       325
#define PRO_E_CMM_REFCSYS_TRF_REF                   326
#define PRO_E_CMM_REFCSYS_NAME                      327
#define PRO_E_CMM_REFCSYS_CSYS                      328

#define PRO_E_STEP_SEL_FORM                         329
#define PRO_E_STEP_TREAT_EDGE                       330

#define PRO_E_TOOL_MODEL                            331

#define PRO_E_FIXT_COMPONENTS                       332
#define PRO_E_SETUP_TIME                            333

#define PRO_E_MACH_WINDOW                           334
#define PRO_E_MACH_DEPTH                            335
#define PRO_E_MACH_PLANE                            336
#define PRO_E_WIND_CSYS                             337
#define PRO_E_TURN_PROF                             338

#define PRO_E_CMM_COMMENTS                          339

#define PRO_E_CRV_PNTS_TWEAK                        340
#define PRO_E_BLEND_CONTROL                         341

#define PRO_E_GRV_EDGES                             342
#define PRO_E_GRV_OFFSET                            343
#define PRO_E_GRV_NORM_SURF                         344

#define PRO_E_CMM_SAVE                              345
#define PRO_E_FIT_SUPPR_PNTS                        346

#define PRO_E_TOOL_SIDE                             347

#define PRO_E_RNDSET_EXTENT                         348

#define PRO_E_CMM_CLR_PLANE                         349

#define PRO_E_REF_SITES                             350

#define PRO_E_STEP_MERGE_REF                        351
#define PRO_E_STEP_MERGE_GEOM                       352
#define PRO_E_STEP_MERGE_EDGE                       353
#define PRO_E_STEP_MERGE_LINES                      354
#define PRO_E_GEN_FEAT_NAME                         355

#define PRO_E_LOC_MACH_SURFS                        356
#define PRO_E_PREV_TOOL                             357

#define PRO_E_FFRM_BASE_SRFS                        358
#define PRO_E_CRV_EDGE_MULT_CHAIN                   359

#define PRO_E_GCPY_OBJS                             361
#define PRO_E_GCPY_CLIP                             362

        /* ***** Patterns ***** */
#define PRO_E_PAT_TYPE                              363
#define PRO_E_PAT_REF                               364
#define PRO_E_PAT_REGEN_METHOD                      365
#define PRO_E_PAT_FIRST_DIR                         366
#define PRO_E_PAT_SECOND_DIR                        367
#define PRO_E_PAT_TABLE_DIMS                        368
#define PRO_E_PAT_TABLE_LIST                        369
#define PRO_E_PAT_TABLE_NAME                        370

#define PRO_E_PAT_DIR_LIST                          371
#define PRO_E_PAT_DIR_LIST_ELEM                     372
#define PRO_E_PAT_DIR_SHOW_DIMS                     373
#define PRO_E_PAT_DIR_SWITCH_DIMS                   374
#define PRO_E_PAT_FIRST_DIR_NUM_INST                375
#define PRO_E_PAT_SECOND_DIR_NUM_INST               376

#define PRO_E_PAT_DIR_DIMENSION                     377
#define PRO_E_PAT_DIR_VAR_TYPE                      378
#define PRO_E_PAT_DIR_VAR_VALUE                     379
#define PRO_E_PAT_RELATION_EDIT                     380

#define PRO_E_PAT_TABLE_EDIT                        382
#define PRO_E_PAT_TABLE_SET_ACTIVE                  383
#define PRO_E_PAT_TABLE_WRITE                       384
#define PRO_E_PAT_TABLE_READ                        385
        /* *** End Patterns *** */

#define PRO_E_FEATURE_TREE                          386
#define PRO_E_FEATURE_TYPE                          387
#define PRO_E_FEATURE_FORM                          388

#define PRO_E_ATTR_DTMCRV_SKET                      389
#define PRO_E_ATTR_DTMCRV_COMP                      390
#define PRO_E_ATTR_DFTOFF_DIR                       391
#define PRO_E_ATTR_DFTOFF_TRANS                     392
#define PRO_E_ATTR_HLCSWP_PITCH                     393
#define PRO_E_ATTR_HLCSWP_ORIENT                    394
#define PRO_E_ATTR_HLCSWP_DIR                       395
#define PRO_E_ATTR_SPRGBK_SPLIT                     396
#define PRO_E_ATTR_SPRGBK_ANGLE                     397
#define PRO_E_ATTR_ALLBLND_CONN                     398
#define PRO_E_ATTR_ROTBLND_SHAPE                    399

#define PRO_E_SHADOW_CRV_PARTS                      400
#define PRO_E_SHADOW_WRK_SEL                        401
#define PRO_E_SHADOW_CRV_DIR                        402
#define PRO_E_SHADOW_CLP_PLN                        403
#define PRO_E_SHADOW_SHUT_EXT                       404
#define PRO_E_SHADOW_SHUT_PLANE                     405
#define PRO_E_SHADOW_DRFT_ANG                       406
#define PRO_E_SHADOW_LOOP_CLS                       407

        /* Datum Plane */
#define PRO_E_DTMPLN_CONSTRAINTS                    410
#define PRO_E_DTMPLN_CONSTRAINT                     411
#define PRO_E_DTMPLN_CONSTR_TYPE                    412
#define PRO_E_DTMPLN_CONSTR_REF                     413
#define PRO_E_DTMPLN_CONSTR_REF_OFFSET              414
#define PRO_E_DTMPLN_CONSTR_REF_ANGLE               415
#define PRO_E_DTMPLN_SEC_IND                        416
#define PRO_E_DTMPLN_OFF_CSYS                       417
#define PRO_E_DTMPLN_OFF_CSYS_OFFSET                418
#define PRO_E_DTMPLN_FIT                            419
#define PRO_E_DTMPLN_FIT_TYPE                       420
#define PRO_E_DTMPLN_FIT_REF                        421
#define PRO_E_DTMPLN_FIT_DTM_RAD                    422

#define PRO_E_GEN_SEL_DIR_DRAFT                     423
#define PRO_E_DIR_REF                               424
#define PRO_E_CSYS_AXIS                             425
#define PRO_E_GEN_DIR_FLIP                          426
#define PRO_E_DIR_PNT                               427

#define PRO_E_EXT_DEPTH_FROM                        428
#define PRO_E_EXT_DEPTH_TO                          429
#define PRO_E_EXT_DEPTH_FROM_TYPE                   430
#define PRO_E_EXT_DEPTH_FROM_VALUE                  431
#define PRO_E_EXT_DEPTH_FROM_REF                    432
#define PRO_E_EXT_DEPTH_TO_TYPE                     433
#define PRO_E_EXT_DEPTH_TO_VALUE                    434
#define PRO_E_EXT_DEPTH_TO_REF                      435
#define PRO_E_STD_DIRECTION                         436

#define PRO_E_REV_ANGLE_FROM                        437
#define PRO_E_REV_ANGLE_TO                          438
#define PRO_E_REV_ANGLE_FROM_TYPE                   439
#define PRO_E_REV_ANGLE_TO_TYPE                     440
#define PRO_E_REV_ANGLE_FROM_VAL                    441
#define PRO_E_REV_ANGLE_TO_VAL                      442
#define PRO_E_REV_ANGLE_FROM_REF                    443
#define PRO_E_REV_ANGLE_TO_REF                      444

/* 445, 446 NOT used */

#define PRO_E_STD_SECTION                           447
#define PRO_E_STD_SECTION_PLANE                     448
#define PRO_E_STD_SEC_PLANE_USE_PREV                449
#define PRO_E_STD_SEC_SETUP_PLANE                   450
#define PRO_E_STD_SEC_PLANE                         451
#define PRO_E_STD_SEC_PLANE_VIEW_DIR                452
#define PRO_E_STD_SEC_PLANE_SKET_ORIENT             453
#define PRO_E_STD_SEC_PLANE_ORIENT_DIR              454
#define PRO_E_STD_SEC_PLANE_ORIENT_REF              455
#define PRO_E_STD_SEC_PLANE_CSYS_AXIS               456
#define PRO_E_STD_SEC_PLANE_ORIENT_FLIP             457
#define PRO_E_SKETCHER                              458

#define PRO_E_BNBLN_TAN_COND                        459
#define PRO_E_BNBLN_TNC_BNDRY                       460
#define PRO_E_BNBLN_TAN_COND_TYPE                   461
#define PRO_E_BNBLN_TAN_REF_TYPE                    462
#define PRO_E_BNBLN_TNC_SEL_BNDRY                   463
#define PRO_E_BNBLN_TNC_SEL_ENTITY                  464
#define PRO_E_BNBLN_TAN_REF_SEL                     465
#define PRO_E_BNBLN_TAN_FLD                         466
#define PRO_E_BNBLN_TNFLD_BNDRY                     467
#define PRO_E_BNBLN_TAN_FLD_TYPE                    468
#define PRO_E_BNBLN_ADVANCED                        469
#define PRO_E_BNBLN_ADV_BNDRY                       470
#define PRO_E_BNBLN_ADV_VIA_CRV                     471
#define PRO_E_BNBLN_ADV_INN_EDGS                    472
#define PRO_E_BNBLN_ADV_GHST_2DIR                   473
#define PRO_E_BNBLN_STRETCH                         474
#define PRO_E_NPCH_CURVES                           475
#define PRO_E_NPCH_CRV_BNDRY                        476
#define PRO_E_NPCH_CRV_REF                          477
#define PRO_E_SWAP_SIDE                             478

#define PRO_E_GCPY_SURF_REFS                        479
#define PRO_E_GCPY_EDGE_REFS                        480
#define PRO_E_GCPY_CRV_REFS                         481

        /* Further Manufacturing elements */
#define PRO_E_NUM_AXES                              482
#define PRO_E_WCELL_TYPE                            483
#define PRO_E_NCSEQ_TYPE                            484
#define PRO_E_LATHE_DIR                             485
#define PRO_E_MACH_NUM_HEADS                        486
#define PRO_E_MFG_PARAMS                            487
#define PRO_E_MFG_PARAM                             488
#define PRO_E_MFG_PARAM_NAME                        489
#define PRO_E_MFG_PARAMVAL                          490
#define PRO_E_TOOL_TABLES                           491
#define PRO_E_MACH_HEAD                             492
#define PRO_E_MFG_TABLE                             493
#define PRO_E_MFG_TABLE_ROW                         494
#define PRO_E_MFG_TABLE_CELL                        495
#define PRO_E_MFG_TABLE_CELL_TYPE                   496
#define PRO_E_MFG_TABLE_CELL_VALUE                  497
#define PRO_E_SITE_NAMES                            498
#define PRO_E_STD_MATRLSIDE                         499
#define PRO_E_MACH_HEAD1                            500
#define PRO_E_MACH_HEAD2                            501
#define PRO_E_FROM_POINTS                           502
#define PRO_E_FROM_POINT                            503
#define PRO_E_HOME_POINTS                           504
#define PRO_E_HOME_POINT                            505
#define PRO_E_POINT_SEL                             506
#define PRO_E_HOLEMAKING_TYPE                       507
#define PRO_E_HOLE_CYCLE_TYPE                       508
#define PRO_E_PECK_TYPE                             509
#define PRO_E_MFG_TOOL_TABLE                        510
#define PRO_E_CURVE_TYPE                            511
#define PRO_E_BNBLN_ADV_INN_EDGS1                   512
#define PRO_E_BNBLN_ADV_INN_EDGS2                   513
        /* sides and depth for standard elements */
#define PRO_E_STD_SIDES                             514
#define PRO_E_STD_EXT_DEPTH                         515
#define PRO_E_ATTR_SRF_END_COND                     516
#define PRO_E_CLOSE_HOLES                           517
#define PRO_E_PROJ_CRV_PROJ_TYPE                    518
        /* Odui Object Id. Use this number for root specification */
#define PRO_E_ODUI_OBJECT_TREE                      519
        /* turning stock allow */
#define PRO_E_TURN_STKLW                            520
#define PRO_E_TWIST_AXIS_SEL                        521
#define PRO_E_TWIST_AXIS_TYPE                       522
#define PRO_E_TWIST_AXIS_CR                         523
#define PRO_E_TWIST_AXIS_VAL                        524
#define PRO_E_TWIST_AXIS_OFF_TYPE                   525
#define PRO_E_EDGE_RIP_LIST                         526
#define PRO_E_RIP_CONN_LIST                         527
#define PRO_E_EDGE_BEND_LIST                        528
#define PRO_E_SELECT_RIP_EDGE                       529
#define PRO_E_SELECT_BEND_EDGE                      530
#define PRO_E_CORNER_TYPE                           531
#define PRO_E_CORNER_OVER_TYPE                      532
#define PRO_E_CORNER_FLIP                           533
#define PRO_E_FIRST_END                             534
#define PRO_E_SECON_END                             535
#define PRO_E_BEND_RADIUS                           536
#define PRO_E_BEND_TBL_TYPE                         537
#define PRO_E_BEND_TBL_SELECT                       538
#define PRO_E_ENTER_RADIUS_VALUE                    539
#define PRO_E_RADIUS_FROM_TABLE                     540
#define PRO_E_Z_TRAJECTORY                          541
#define PRO_E_MINOR_DIAMETER                        542
#define PRO_E_THREAD_SURFACES                       543
#define PRO_E_THREAD_SURF_NEW                       544
#define PRO_E_THRD_STRT_SRF_NEW                     545
#define PRO_E_THREAD_PARAMS                         546
#define PRO_E_THREAD_PITCH                          547
#define PRO_E_THREAD_PITCH_UNITS                    548
#define PRO_E_THREAD_NUM_STARTS                     549
#define PRO_E_THREAD_FORM                           550
#define PRO_E_THREAD_CLASS                          551
#define PRO_E_THREAD_PLACEMENT                      552
#define PRO_E_THREAD_MSYS                           553

/* New Rel 19.0 shell elements */
#define PRO_E_ST_SHELL_SRF                          554
#define PRO_E_ST_SHELL_THICK                        555
#define PRO_E_ST_SHELL_LOCL_LIST                    556
#define PRO_E_ST_SHELL_SPEC_SRF                     557
#define PRO_E_ST_SHELL_SPEC_THCK                    558

/* New pattern ODUI elements. */
#define PRO_E_PAT_DIR_DIM_COMPOUND                  559
#define PRO_E_PAT_TABLE                             560

/* WaterLines elements */
#define PRO_E_WTLN_COMP                             561
#define PRO_E_WTLN_SK                               562
#define PRO_E_WTLN_CONDS                            563
#define PRO_E_WTLN_NAME                             564
#define PRO_E_WTLN_TYPE                             565
#define PRO_E_WTLN_DIAMETER                         566

#define PRO_E_NCL_COMMAND                           567
#define PRO_E_NCL_COMMANDS                          568
#define PRO_E_REF_NCSEQ                             569

/* Rel 19.0 parallel blend depth elems */
#define PRO_E_BLN_DPTH_ARR                          570
#define PRO_E_BLN_DPTH_CMPD                         571
#define PRO_E_BLN_DPTH_TYPE                         572
#define PRO_E_BLN_DPTH_FROMTO                       573
#define PRO_E_BLN_DPTH_FROMREF                      574
#define PRO_E_BLN_DPTH_TOREF                        575
#define PRO_E_BLN_DPTH_VAL                          576

/* datum axis */
#define PRO_E_DTMAXIS_TYPE                          577
#define PRO_E_DTMAXIS_REFS                          578
#define PRO_E_DTMAXIS_PNTVTX1                       579
#define PRO_E_DTMAXIS_PNTVTX2                       580
#define PRO_E_DTMAXIS_PLANE1                        581
#define PRO_E_DTMAXIS_PLANE2                        582
#define PRO_E_DTMAXIS_EDGE_SRF_CSYS                 583
#define PRO_E_DTMAXIS_CSYS_AXIS                     584
#define PRO_E_DTMAXIS_CURVE_EDGE                    585
#define PRO_E_DTMAXIS_PNTVTX                        586
#define PRO_E_DTMAXIS_PLANE                         587
#define PRO_E_DTMAXIS_DIM_REF1                      588
#define PRO_E_DTMAXIS_DIM_REF_DIST1                 589
#define PRO_E_DTMAXIS_DIM_REF2                      590
#define PRO_E_DTMAXIS_DIM_REF_DIST2                 591
#define PRO_E_DTMAXIS_PNT                           592
#define PRO_E_DTMAXIS_SURF                          593
     
        
/* New Rel 19.0 chamfer elements */
#define PRO_E_STD_EDGE_CHAMF_SCHEME                 594
#define PRO_E_STD_EDGE_CHAMF_SRF                    595
#define PRO_E_STD_EDGE_CHAMF_EDGES                  596
#define PRO_E_STD_EDGE_CHAMF_DIM1                   597
#define PRO_E_STD_EDGE_CHAMF_DIM2                   598
#define PRO_E_STD_EDGE_CHAMF_ANGLE                  599
        
#define PRO_E_STD_CORNER_CHAMF_CORNER               600
#define PRO_E_STD_CORNER_CHAMF_EDGE1                601
#define PRO_E_STD_CORNER_CHAMF_EDGE2                602
#define PRO_E_STD_CORNER_CHAMF_EDGE3                603

/* Pattern 19.0 root element */
#define PRO_E_PATTERN_ROOT                          604

/*component assembly standard elements */
#define PRO_E_COMPONENT_CONSTRAINTS                 605
#define PRO_E_COMPONENT_CONSTRAINT                  606
#define PRO_E_COMPONENT_CONSTR_TYPE                 607
#define PRO_E_COMPONENT_COMP_CONSTR_REF             608
#define PRO_E_COMPONENT_ASSEM_CONSTR_REF            609
#define PRO_E_COMPONENT_CONSTR_REF_OFFSET           610
#define PRO_E_COMPONENT_INIT_POS                    611
#define PRO_E_COMPONENT_MODEL                       612

#define PRO_E_PROCESS_STEP_TYPE                     613

/* New CAV */   
#define PRO_E_FIT_REF_FIT                           614

/* More GeomCopy elements */
#define PRO_E_GCPY_CSYS_PLACE                       615
#define PRO_E_GCPY_EXT_CSYS                         616
#define PRO_E_GCPY_LOC_CSYS                         617
#define PRO_E_GCPY_EXT_MDL                          618
/* curves */
#define PRO_E_DTMCRV_DISPLAY_HATCH                  619
#define PRO_E_DTMCRV_HATCH_DENSITY                  620
#define PRO_E_CRV_TANG_OFFSET_CURVE                 621
#define PRO_E_CRV_TANG_OFFSET_SURF                  622
#define PRO_E_CRV_TANG_OFFSET_DIST                  623
#define PRO_E_CRV_TANG_OFFSET_DIR                   624
#define PRO_E_CRV_OFFSET_CURVE                      625
#define PRO_E_CRV_OFFSET_START_PNT                  626
#define PRO_E_CRV_OFFSET_SURFACE                    627
#define PRO_E_CRV_OFFSET_DIRECTION                  628
#define PRO_E_CRV_OFFSET_GRAPH                      629
#define PRO_E_CRV_OFFSET_SCALE                      630
#define PRO_E_STD_CRV_SPLIT_CRV                     631
#define PRO_E_STD_CRV_SPLIT_DIVIDER                 632
#define PRO_E_STD_CRV_SPLIT_SIDE                    633

#define PRO_E_REV_ANGLE_FROM_LIMIT                  634
#define PRO_E_REV_ANGLE_TO_LIMIT                    635
#define PRO_E_OLD_EXT_DEPTH                         636

#define PRO_E_ST_SHELL_LOCL_CMPD                    637

/* Boundary blend elements */
#define PRO_E_CTRL_CURVE                            638
#define PRO_E_CTRL_TYPE                             639
#define PRO_E_REF_CURVE                             640
#define PRO_E_CTRL_PTS_1DIR                         641
#define PRO_E_CTRL_PTS_SET                          642
#define PRO_E_CTRL_PTS_CURVE                        643
#define PRO_E_CTRL_PTS_REF                          644
#define PRO_E_CTRL_PTS_2DIR                         645
#define PRO_E_BLEND_TYPE                            646
#define PRO_E_CTRL_PTS_SETDUM                       647
#define PRO_E_CTRL_PTS_CURVEDUM                     647
#define PRO_E_REFERENCE_CURVES                      649
#define PRO_E_CHAIN_CURVES                          650
#define PRO_E_BNBLN_1DIR                            651
#define PRO_E_BNBLN_2DIR                            652
#define PRO_E_APPROX_DIR_CURVES                     653
#define PRO_E_APPROX_CURVES                         654
#define PRO_E_APPROX_PARAMETERS                     655
#define PRO_E_APPROX_DIR                            656
#define PRO_E_BNBLN_DIR_CURVES                      657
#define PRO_E_CONIC_CURVES                          658
#define PRO_E_CONIC_BNDRY1                          659
#define PRO_E_CONIC_BNDRY2                          660
#define PRO_E_BNBLN_CURVES                          661
#define PRO_E_CTRL_PTS                              662
#define PRO_E_APPROX_SMOOTHNESS                     663
#define PRO_E_APPROX_NUM_U_PATCH                    664
#define PRO_E_APPROX_NUM_V_PATCH                    665
#define PRO_E_BNBLN_TAN_COND_19                     666
#define PRO_E_BNBLN_TAN_FLD_19                      667
#define PRO_E_BNBLN_TNC_SEL_BNDRY_19                668
#define PRO_E_BNBLN_TNC_BNDRY_19                    669
#define PRO_E_BNBLN_TAN_COND_TYPE_19                670
#define PRO_E_BNBLN_TAN_REF_TYPE_19                 671
#define PRO_E_BNBLN_TNC_SEL_ENTITY_19               672
#define PRO_E_BNBLN_TAN_REF_SEL_19                  673
#define PRO_E_BNBLN_TNFLD_BNDRY_19                  674
#define PRO_E_BNBLN_TAN_FLD_TYPE_19                 675

#define PRO_E_TWIST_OFFSET_PLN                      676

/* Analysis elements */
#define PRO_E_ANALYSIS_NAME                         677
#define PRO_E_ANALYSIS_DEF                          678
#define PRO_E_ANALYSIS_ORDER                        679
#define PRO_E_ANALYSIS_REF                          680

#define PRO_E_COMPONENT_MISC_ATTR                   681
        
#define PRO_E_ANALYSIS_REG_REQUEST                  682
        
#define PRO_E_HSWP_PITCH_DOUBLE                     684
#define PRO_E_HSWP_PITCH_GRAPH                      685

#define PRO_E_CONIC_PARAM_19                        686

#define PRO_E_STD_DRAFT_SURFACES                    687
#define PRO_E_STD_DRAFT_SPLIT_ATTR                  688
#define PRO_E_STD_DRAFT_PIVOT_TYPE                  689
#define PRO_E_STD_DRAFT_PIVOT_PLANE                 690
#define PRO_E_STD_DRAFT_PIVOT_CURVE_1               691
#define PRO_E_STD_DRAFT_PIVOT_CURVE_2               692
#define PRO_E_STD_DRAFT_PARTING_SRF                 693

/* New Hole elements */
#define PRO_E_HLE_OPTS                              694
#define PRO_E_HLE_TYPE                              695
#define PRO_E_HLE_PL_TYPE                           696
#define PRO_E_HLE_PL_REFS                           697
#define PRO_E_HLE_AXIS                              698
#define PRO_E_HLE_EJ_PIN_PNTS                       699
#define PRO_E_HLE_PL_PLANE                          700
#define PRO_E_HLE_PL_SURF                           701
#define PRO_E_HLE_REF_PLANE                         702
#define PRO_E_HLE_REF_ANG                           703
#define PRO_E_HLE_DIM_REF1                          704
#define PRO_E_HLE_DIM_TYPE                          705
#define PRO_E_HLE_DIM_DIST1                         706
#define PRO_E_HLE_DIM_REF2                          707
#define PRO_E_HLE_DIM_DIST2                         708
#define PRO_E_HLE_DIM_DIA                           709
#define PRO_E_HLE_DIM_RAD                           710
#define PRO_E_HLE_DIM_LIN                           711
#define PRO_E_HLE_NORM_PLA                          712
#define PRO_E_HLE_NORM_OFFST                        713
#define PRO_E_HLE_POINT                             714
#define PRO_E_HLE_DIAMETER                          715
#define PRO_E_HLE_CNTRBR                            716
#define PRO_E_HLE_CNTRBR_DIA                        717
#define PRO_E_HLE_CNTRBR_DEPTH                      718
#define PRO_E_HLE_SKETCHER                          719

        /* For general sections */
#define PRO_E_STD_SECTIONS                          721
#define PRO_E_STD_TRAJS                             722
#define PRO_E_STD_TRAJ                              723
#define PRO_E_STD_SEC_SETUP                         724
#define PRO_E_STD_SEC_METHOD                        725
#define PRO_E_STD_SEC_SELECT                        726
#define PRO_E_STD_SEC_PLANE_LOC                     727
#define PRO_E_STD_SEC_LOCATION                      728
#define PRO_E_STD_SEC_ROTATION                      729
#define PRO_E_STD_SEC_SEL_CHAIN                     730
#define PRO_E_STD_SEC_TAN_SURFS                     731
#define PRO_E_STD_SEC_BLN_VERTS                     732
#define PRO_E_STD_SCHEME                            733

/* New elements for Get Surface From Chain utility */

#define PRO_E_SURF_CHAIN_CMPND                      734
#define PRO_E_SURF_CHAIN_METHOD                     735
#define PRO_E_SURF_CHAIN_REF_SURFS                  736
#define PRO_E_SURF_CHAIN_SURF                       737
#define PRO_E_SURF_CHAIN_REF                        738

/* Interchange elements */
#define PRO_E_INTCHG_SUBS_STEP                      739
#define PRO_E_INTCHG_MP_STEP                        740
#define PRO_E_INTCHG_PLACE_STEP                     741
#define PRO_E_INTCHG_FUNC_NODE_STEP                 742
#define PRO_E_INTCHG_COMP_STEP                      743
#define PRO_E_INTCHG_MP_TYPE_STEP                   744
#define PRO_E_INTCHG_MP_DRV_STEP                    745


#define PRO_E_CHOOSE_SURFACES                       746
#define PRO_E_DEFINE_CURVE                          747
#define PRO_E_CHOOSE_EDGES                          748
#define PRO_E_TRAJ_DIR                              749
#define PRO_E_AXIS_DEF                              750
#define PRO_E_HEIGHT                                751
#define PRO_E_OFFSET                                752
#define PRO_E_MATRL_SIDE                            753
        
        /**** Use Quilt 19.0 ****/
#define PRO_E_STD_USEQLT_QLT                        754
#define PRO_E_STD_USEQLT_SIDE                       755
#define PRO_E_STD_USEQLT_THK                        756
 
#define PRO_E_SHADOW_SLIDES                         757

#define PRO_E_STD_REPLACED_SURF                     758
#define PRO_E_STD_REPLACEMENT_SURF                  759
#define PRO_E_STD_KEEP_QUILT                        760
#define PRO_E_STD_CRV_EDGE_CHAIN                    761
#define PRO_E_STD_EDGE_CHAMF_DIM                    762

/* another component element for each plin */
#define PRO_E_COMPONENT_USER_DATA                   763
        
#define PRO_E_PROJ_BLN_DPTH                         764


        /* for plunge milling */
#define PRO_E_START_AXES                            765
      
#define PRO_E_STD_PROJ_CRV_SURFS                    766
#define PRO_E_STD_FORM_CRV_SURF                     767
#define PRO_E_STD_FORM_CRV_TMP                      768

#define PRO_E_STD_CRV_INTSRF_SURFS1                 769
#define PRO_E_STD_CRV_INTSRF_SURFS2                 770

#define PRO_E_CTRL_PTS_BNDRIES                      771

/* Datum Points Elements */
#define PRO_E_DTMPNT_PNTS                           772
#define PRO_E_DTMPNT_PNT                            773
#define PRO_E_DTMPNT_TYPE                           774
#define PRO_E_DTMPNT_DEPENDENCY                     775
#define PRO_E_DTMPNT_PLACE_SURF                     776
#define PRO_E_DTMPNT_DIM_REF1                       777
#define PRO_E_DTMPNT_DIM_REF2                       778
#define PRO_E_DTMPNT_DIM_DIST1                      779
#define PRO_E_DTMPNT_DIM_DIST2                      780
#define PRO_E_DTMPNT_OFFSET_DIST                    781
#define PRO_E_DTMPNT_CXS_CURVE                      782
#define PRO_E_DTMPNT_CXS_SURF                       783
#define PRO_E_DTMPNT_ONV_VTX                        784
#define PRO_E_DTMPNT_3SRF_SURF1                     785
#define PRO_E_DTMPNT_3SRF_SURF2                     786
#define PRO_E_DTMPNT_3SRF_SURF3                     787
#define PRO_E_DTMPNT_ATCENT_REF                     788

/* Csys */
#define PRO_E_CSYS_METHOD                           789
#define PRO_E_CSYS_REFS                             790
#define PRO_E_CSYS_PLANE1                           791
#define PRO_E_CSYS_PLANE2                           792
#define PRO_E_CSYS_PLANE3                           793
#define PRO_E_CSYS_PLANE                            794
#define PRO_E_CSYS_REF1                             795
#define PRO_E_CSYS_REF2                             796
#define PRO_E_CSYS_DIR                              797
#define PRO_E_CSYS_ORIGIN                           798
#define PRO_E_CSYS_DIR1                             799
#define PRO_E_CSYS_DIR2                             800
#define PRO_E_CSYS_CSYS                             801
#define PRO_E_CSYS_TRAN_FILE                        802
#define PRO_E_CSYS_MOVES                            803
#define PRO_E_CSYS_MOVES_VIEW                       804
#define PRO_E_CSYS_MOVE                             805
#define PRO_E_CSYS_MOVE_METHOD                      806
#define PRO_E_CSYS_MOVE_VALUE                       807
#define PRO_E_CSYS_ROT                              808
#define PRO_E_CSYS_1ROT                             809
#define PRO_E_CSYS_2ROT                             810
#define PRO_E_CSYS_SEL_AXES                         811
#define PRO_E_CSYS_X_DIR                            812
#define PRO_E_CSYS_Y_DIR                            813

#define PRO_E_PAT_TABLE_DATA                        814
#define PRO_E_STD_DRAFT_DIR_TYPE                    815
#define PRO_E_STD_DRAFT_ANGLE_TYPE                  816
#define PRO_E_STD_DRAFT_ANGLE_COMPOUND              817
#define PRO_E_STD_DRAFT_SYMMETRIC                   818
#define PRO_E_STD_DRAFT_ANGLE1_ATTR                 819
#define PRO_E_STD_DRAFT_ANGLE1                      820

/* swept blend */
#define PRO_E_SWP_BLN_SPINE                         821
#define PRO_E_SWP_BLN_SECTIONS                      822
#define PRO_E_STD_USEQLT_LVOUT                      823
#define PRO_E_STD_USEQLT_SCALCSYS                   824

#define PRO_E_STD_CRV_GET_CSYS                      825
#define PRO_E_STD_CRV_CSYS                          826
#define PRO_E_STD_CRV_GET_CSYS_TYPE                 827
#define PRO_E_STD_CRV_ENTER_EQUATION                828
       
#define PRO_E_STD_CRV_PROJ_SECTION                  829
#define PRO_E_STD_TWO_PROJ_SEC1                     830
#define PRO_E_STD_TWO_PROJ_SEC2                     831

#define PRO_E_PAT_MULT_TABLE_DIMS                   832
#define PRO_E_STD_SRFOFF_SRF                        833

#define PRO_E_BNBLN_CONNECT_SURF_CHAIN              834

/* Surface Offset */

#define PRO_E_SRF_OFFS_TYPE                         835
#define PRO_E_SRF_OFFS_METHOD                       836
#define PRO_E_SRF_OFFS_SCALINGCSYS                  837
#define PRO_E_SRF_OFFS_TRANSLATION                  838
#define PRO_E_SRF_OFFS_XAXIS                        839
#define PRO_E_SRF_OFFS_YAXIS                        840
#define PRO_E_SRF_OFFS_ZAXIS                        841
    
#define PRO_E_SECTION_TYPE                          842

   /* round */
#define PRO_E_RND_TYPE_CMP                          843
#define PRO_E_RND_TMPGEOM_OPT                       844
#define PRO_E_RND_EXTENT_CMP                        845
#define PRO_E_RND_EXT_ABLEND                        846
#define PRO_E_RND_EXT_TRMSRF                        847
#define PRO_E_RND_EXT_REFS                          848

#define PRO_E_RND_ATTR_CMP                          849
#define PRO_E_RND_ATTR_BALL                         850
#define PRO_E_RND_ATTR_TRDEF                        851
#define PRO_E_RND_ATTR_VARRAD                       852
#define PRO_E_RND_ATTR_SHAPE                        853
#define PRO_E_RND_ATTR_CONPAR                       854

#define PRO_E_RND_SETS_ARR                          855
#define PRO_E_RND_SETS_CMP                          856
#define PRO_E_RNDSET_SHAPE                          857
#define PRO_E_RNDSET_REFTYP                         858
#define PRO_E_RNDSET_REFS_CMP                       859
#define PRO_E_RNDSET_REF_CHAIN                      860
#define PRO_E_RNDSET_REF_EDG1                       861
#define PRO_E_RNDSET_REF_SRF1                       862
#define PRO_E_RNDSET_REF_EDG2                       863
#define PRO_E_RNDSET_REF_SRF2                       864
#define PRO_E_RNDSET_REF_REPLSRF                    865
         /* spine */
#define PRO_E_RNDSET_SPINECRV                       866
         /* round thru curve */
#define PRO_E_RNDSET_RADCRV_CMP                     867
#define PRO_E_RNDSET_RADCRV_REF                     868
#define PRO_E_RNDSET_RADCRV_SRFS                    869
         /* round set radius elements */
#define PRO_E_RNDRAD_ARR                            870
#define PRO_E_RNDRAD_CMP                            871
#define PRO_E_RNDRAD_PNTREF                         872
#define PRO_E_RNDRAD_RADCMP                         873
#define PRO_E_RNDRAD_RADTYP                         874
#define PRO_E_RNDRAD_RADVAL                         875
#define PRO_E_RNDRAD_EDGREF                         876
#define PRO_E_RNDRAD_PNTVTX                         877

#define PRO_E_RND_TRNS_LIST                         878
#define PRO_E_RND_TRN_COMP                          879
#define PRO_E_RND_TRN_TYPE                          880

#define PRO_E_RND_TRN_REFS_LST                      881
#define PRO_E_RND_TRN_REF_CMP                       882
#define PRO_E_RND_TRN_REF                           883
#define PRO_E_RND_TRN_SPHDIST                       884
            /* sphere radius element */
#define PRO_E_RND_TRN_SPHRAD                        885
            /* stop transition reference */
#define PRO_E_RND_TRNST_REFS                        886
            /* patch transition elements */
#define PRO_E_RND_TRN_FILTS_LST                     887
#define PRO_E_RND_TRN_FILTS_CMP                     888
#define PRO_E_RND_TRN_FLTSRF                        889
#define PRO_E_RND_TRN_FLTRAD                        890

#define PRO_E_PAT_TABLE_INSTANCES                   891
#define PRO_E_PAT_TABLE_INSTANCE                    892
#define PRO_E_PAT_TABLE_INSTANCE_INDEX              893
#define PRO_E_PAT_TABLE_INSTANCE_DIMS               894
#define PRO_E_PAT_TABLE_INSTANCE_DIM_VALUE          895

#define PRO_E_SWEEP_SPINE                           896
#define PRO_E_SWEEP_SECTION                         897

/* curve thru points */
#define PRO_E_STD_CRV_CONN_TYPE                     898
#define PRO_E_STD_CRV_SEL_TYPE                      899
#define PRO_E_18_ATTR_HLCSWP_ORIENT                 900
#define PRO_E_19_TRAJECTORY                         901
#define PRO_E_OLD_ROOT_ELEMENT                      902
#define PRO_E_STD_CRV_ON_SURF                      1000
#define PRO_E_STD_CRV_PNTS_REF                     1001
#define PRO_E_STD_CRV_PNTS_TWEAK                   1002
#define PRO_E_STD_CRV_TANG_COND                    1003
#define PRO_E_STD_CRV_PNTS_RAD                     1004
#define PRO_E_STD_CRV_PNTS                         1005
#define PRO_E_STD_CRV_TANG                         1006
#define PRO_E_STD_CRV_PNTS_LIST                    1007
#define PRO_E_STD_CRV_PNTS_ON_SURF_REF             1008
#define PRO_E_STD_CRV_PNTS_ATTR                    1009
#define PRO_E_STD_CRV_TANG_SUB                     1010
#define PRO_E_FOREIGN_CURVE_CLASS                  1011
#define PRO_E_FOREIGN_CURVE_CSYS_REF               1012
#define PRO_E_FOREIGN_CURVE_CONTINUITY             1013
#define PRO_E_FOREIGN_CURVE_DATA_VAL               1014
#define PRO_E_RUNNER_DEF_SIZE                      1015
#define PRO_E_RUNNER_SHAPE                         1016
#define PRO_E_RUNNER_SEGMENT_SIZES                 1017

#define PRO_E_START_HEIGHT                         1018
#define PRO_E_GCPY_FEAT_NAME                       1019

/* Component Constraint Attributes */
#define PRO_E_COMPONENT_CONSTR_ATTR                1020

#define PRO_E_CONTOUR2                             1021
#define PRO_E_SIDESURF                             1022
#define PRO_E_CONTOUR1                             1023
#define PRO_E_SYNC                                 1024
#define PRO_E_TRAJ_PREVIEW                         1025

/* Orient attributes */
#define PRO_E_COMPONENT_COMP_ORIENT                1026
#define PRO_E_COMPONENT_ASSM_ORIENT                1027

#define PRO_E_HOLESETS                             1028
#define PRO_E_DRILL_PART_DATA                      1029
#define PRO_E_DRILL_PARTS                          1030
#define PRO_E_AUTO_SEL_DRILL_PARTS                 1031
#define PRO_E_HOLESET                              1032
#define PRO_E_HOLESET_ID                           1033
#define PRO_E_HOLESET_DEPTH                        1034
#define PRO_E_HOLESET_DEPTH_BY_TYPE                1035
#define PRO_E_HOLESET_DEPTH_TYPE                   1036
#define PRO_E_HOLESET_DEPTH_PLATES                 1037
#define PRO_E_HOLESET_DEPTH_PLATE                  1038
#define PRO_E_HOLESET_PLATE_START                  1039
#define PRO_E_HOLESET_PLATE_END                    1040
#define PRO_E_HOLESET_PLATE_DEPTH                  1041
#define PRO_E_HOLESET_PLATE_CDIAM                  1042
#define PRO_E_HOLESET_PLATE_BRKOUT                 1043
#define PRO_E_HOLESET_SELECTION_RULES              1044
#define PRO_E_HOLESET_TYPE                         1045
#define PRO_E_HOLESET_SEL_AUTO_CHAMFER             1046
#define PRO_E_HOLESET_SEL_INDIV_AXES               1047
#define PRO_E_HOLESET_SEL_AXIS_PATTS               1048
#define PRO_E_HOLESET_SEL_DRILL_GROUPS             1049
#define PRO_E_HOLESET_SEL_BY_DIAMETERS             1050
#define PRO_E_HOLESET_SEL_BY_SURFACES              1052
#define PRO_E_HOLESET_SEL_BY_PARAMS                1053
#define PRO_E_HOLESET_SEL_BY_PARAM                 1054
#define PRO_E_HOLESET_SEL_PARAM_NAME               1055
#define PRO_E_HOLESET_SEL_PARAM_VAL                1056
#define PRO_E_HOLESET_SEL_PARAM_REL                1057
#define PRO_E_HOLESET_START_HOLE                   1058
#define PRO_E_HOLESET_FLIPPED_AXES                 1059
#define PRO_E_HOLESET_UNFLIPPED_AXES               1060
#define PRO_E_HOLESET_SEL_UNSEL_AXES               1061
#define PRO_E_BEND_DIRECTION                       1062
#define PRO_E_GCPY_PUBD_GEOM                       1063

/* Movement Element, part of component assembly */

#define PRO_E_COMPONENT_MOVEMENTS                  1064
#define PRO_E_COMPONENT_MOVEMENT                   1065
#define PRO_E_COMPONENT_MOVEMENT_TYPE              1066
#define PRO_E_COMPONENT_MOVEMENT_REF               1067
#define PRO_E_COMPONENT_MOVEMENT_VALUE             1068

#define PRO_E_WIND_SEC_PLN                         1069
#define PRO_E_WIND_COMP                            1070
#define PRO_E_WIND_FROM_TO                         1071
#define PRO_E_PAT_TABLE_DIM                        1072
#define PRO_E_SPLIT_SURF_CURVE                     1073
#define PRO_E_SPLIT_SURFS                          1074
#define PRO_E_SPLIT_SURFS_SECTION                  1075

#define PRO_E_WLD_PREP_TYPE                        1076
#define PRO_E_WLD_PREP_CONTACT_SRFS                1077
#define PRO_E_WLD_PREP_EDGE_SETS                   1078
#define PRO_E_WLD_PREP_DIMS                        1079
#define PRO_E_NUMBER_OF_FACES                      1080
#define PRO_E_MIN_SRF_CLR                          1081
#define PRO_E_ROUGH_SRFS                           1082
#define PRO_E_STOCK_BOUND_SKETCH                   1083
#define PRO_E_STOCK_BOUND_WP_SEL                   1084
#define PRO_E_TURN_PROF_CRV                        1085
#define PRO_E_TURN_PROF_ST_EXT                     1086
#define PRO_E_TURN_PROF_EN_EXT                     1087
#define PRO_E_SLOPE_MILL_ANGLE                     1088
#define PRO_E_SLOPE_MILL_DIR                       1089
#define PRO_E_SLOPE_SIDE_CHOICE                    1090
#define PRO_E_WALL_DEPTH                           1091
#define PRO_E_WIND_BOTTOM                          1092

#define PRO_E_DTMPNT_DIRECTION                     1093
#define PRO_E_DTMPNT_EDGE                          1094
#define PRO_E_DTMPNT_PLNNORM                       1095
#define PRO_E_DTMPNT_LN1PNT                        1096
#define PRO_E_DTMPNT_LN2PNT                        1097
#define PRO_E_DTMPNT_POINT                         1098
#define PRO_E_DTMPNT_OFFSET_X                      1099
#define PRO_E_DTMPNT_OFFSET_Y                      1100
#define PRO_E_DTMPNT_OFFSET_Z                      1101
#define PRO_E_DTMPNT_CSYSTYPE                      1102
#define PRO_E_DTMPNT_CSYS                          1103
#define PRO_E_DTMPNT_X                             1104
#define PRO_E_DTMPNT_Y                             1105
#define PRO_E_DTMPNT_Z                             1106
#define PRO_E_DTMPNT_RADIUS                        1107
#define PRO_E_DTMPNT_THETA                         1108
#define PRO_E_DTMPNT_PHI                           1109
#define PRO_E_DTMPNT_DIMENSIONS                    1110
#define PRO_E_DTMPNT_OFFSET_PNT_DIST               1111
#define PRO_E_DTMPNT_CSYS_VEC                      1112


#define PRO_E_GCPY_LOCATION                        1113

#define PRO_E_SRF_MRG_PRNT_QLT                     1114
#define PRO_E_SRF_MRG_ADTL_QLT                     1115
#define PRO_E_SRF_MRG_TYPE                         1116
#define PRO_E_SRF_MRG_PRNT_QLT_SIDE                1117
#define PRO_E_SRF_MRG_ADTL_QLT_SIDE                1118

/* Feature Intersections */
#define PRO_E_FEATURE_INTERSECTION                 1119
#define PRO_E_FEATURE_INTERSECT_PART               1120
#define PRO_E_FEATURE_INTERSECT_LEVEL              1121

/* Feature Mach Area */
#define PRO_E_MILLED_SRFS                          1122
#define PRO_E_CHECK_SRFS                           1123
#define PRO_E_TOOL_RADIUS                          1124
#define PRO_E_MACH_SRFS_OPTION                     1125

#define PRO_E_CSYS_TYPE                            1126
#define PRO_E_TOOL_AXIS                            1127
#define PRO_E_CSYS_THETA_DIR                       1128
#define PRO_E_CSYS_PHI_DIR                         1129
#define PRO_E_CSYS_Z_DIR                           1130
/* Non redef dtm srf type */
#define PRO_E_DTM_SRF_TYPE                         1131

/* Analysis Feature 19_odui */
#define PRO_E_ANALYSIS_TYPE                        1132
#define PRO_E_ANALYSIS_RES_PARM_UI                 1133
#define PRO_E_ANALYSIS_RES_DATM_UI                 1134
#define PRO_E_ANALYSIS_RESULT_UI                   1135
#define PRO_E_ANALYSIS_RESULT_UI_DATMS             1136
#define PRO_E_ANALYSIS_Y_NO_OPT                    1137
#define PRO_E_ANALYSIS_PARM_NAME                   1138
        
/* Additional Surface Offset and Thin Use Quilt elements. */
#define PRO_E_SRF_OFFS_ACTION                      1139
#define PRO_E_SRF_OFFS_HANDLINGS                   1140
#define PRO_E_SRF_OFFS_HANDLING                    1141
#define PRO_E_SRF_OFFS_REF_SEL                     1142
#define PRO_E_SRF_OFFS_REFQUILT                    1143
#define PRO_E_SRF_OFFS_AXISES                      1144
#define PRO_E_SRF_OFFS_CTRLFIT                     1145

#define PRO_E_MATERIAL_SIDE                        1146
#define PRO_E_TRIM_QLT_SIDE                        1147
 
#define PRO_E_RUNNER_SK                            1148
#define PRO_E_RUNNER_DIR                           1149

#define PRO_E_WLD_PREP_AFF_MDLS                    1150

#define PRO_E_CRV_SILH_LOOP_SEL                    1151

#define PRO_E_FEAT_VIEW                            1152

/* Shadow21 steps */
#define PRO_E_SHADOW_REF_MODEL                     1153
#define PRO_E_SHADOW_CURVES                        1154
#define PRO_E_SHADOW_CRV_SMNT                      1155

#define PRO_E_OLD_ATTRIBUTES                       1156
#define PRO_E_OLD_REV_ANGLE                        1157
#define PRO_E_HOLESET_SEL_BY_TABLE                 1158

/*** Frames, swept blends and sweeps   ***/
       
#define PRO_E_FRAME_SETUP                          1159
#define PRO_E_END_SRF_ATTR                         1160
#define PRO_E_FAKE_SWPBLN_SEC_SETUP                1161
#define PRO_E_SWPBLN_CNTRL_SETUP                   1162
#define PRO_E_FAKE_SWPBLN_TANGENCY                 1163
#define PRO_E_SWPBLN_CNTRL_TYPE                    1164
#define PRO_E_SWPBLN_CNTRL_ELEM                    1165
#define PRO_E_SWPBLN_CENTER_LINE                   1166
#define PRO_E_SWPBLN_AREA_GRAPH_UI                 1167
#define PRO_E_SWP_SEC_TYPE                         1168
#define PRO_E_SWP_SEC_UI                           1169
#define PRO_E_FRM_NORMAL                           1170
#define PRO_E_FRM_ORIENT                           1171
#define PRO_E_FRM_PIVOT_DIR                        1172
#define PRO_E_FRM_TRAJ_UI                          1173
#define PRO_E_FRM_X_TRAJ                           1174
#define PRO_E_FRM_Z_TRAJ                           1175
#define PRO_E_FRM_OPT_TRAJ                         1176
#define PRO_E_VSWP_SEC_SETUP                       1177
#define PRO_E_HOLESET_EDGE_BREAK                   1178
#define PRO_E_SRF_OFFS_DIRECTION                   1179
#define PRO_E_USEQLT_SOLID_SIDE                    1180

#define PRO_E_STOCK_BOUND_COMP                     1181
#define PRO_E_TURN_PROF_COMP                       1182
#define PRO_E_TURN_OPTION                          1183
#define PRO_E_WLD_PREP_NEUT_PLN                    1184
#define PRO_E_TRAJ_SKETCH                          1185
#define PRO_E_WLD_PREP_FILL                        1186
#define PRO_E_START_WALL                           1187
#define PRO_E_CRV_SILH_SLIDES_VOL                  1188
#define PRO_E_CRV_SILH_GAP_CLOSURE                 1189
#define PRO_E_TRIM1S_DIR                           1190
#define PRO_E_TRIM1S_ATTR                          1191
#define PRO_E_MFG_TRIM_OPT_TRIM1S                  1192
#define PRO_E_GEN_DIR                              1193
#define PRO_E_GEN_DIR_USE_AUX                      1194
#define PRO_E_GEN_DIR_FIRST_REF                    1195
#define PRO_E_GEN_DIR_CSYS_OPT                     1196
#define PRO_E_GEN_DIR_CSYS_AXIS                    1197
#define PRO_E_GEN_DIR_X_TRAN                       1198
#define PRO_E_GEN_DIR_Y_TRAN                       1199
#define PRO_E_GEN_DIR_Z_TRAN                       1200
#define PRO_E_GEN_DIR_SECOND_REF                   1201
#define PRO_E_GEN_DIR_OPT                          1202
#define PRO_E_GEN_DIR_ORIENT_PNT                   1203
#define PRO_E_GEN_DIR_SIDE                         1204

#define PRO_E_STEP_CORNER_RELIEF                   1205
#define PRO_E_BNBLN_RULED                          1206

#define PRO_E_ROT_ENVLP                            1207
#define PRO_E_EDIT_CURVE                           1208
#define PRO_E_FROM_SURFACE                         1209
#define PRO_E_TO_SURFACE                           1210
#define PRO_E_MFG_MATERIAL_SIDE                    1211
#define PRO_E_FEATURE_NAME                         1212
#define PRO_E_DSHARE_BASE_MODEL                    1213
#define PRO_E_DRVD_VAR_DIMS                        1214
#define PRO_E_TRIM1S_REF_PART                      1215
#define PRO_E_AUTO_NCL_COMMAND_BEFORE_LOADTL       1216
#define PRO_E_AUTO_NCL_COMMAND_AFTER_FROM          1217
#define PRO_E_AUTO_NCL_COMMAND_AFTER_GOHOME        1218
#define PRO_E_AUTO_NCL_COMMAND_BEFORE_EACH_PASS    1219
#define PRO_E_AUTO_NCL_COMMAND_AFTER_EACH_PASS     1220
#define PRO_E_AUTO_NCL_COMMAND_LAST_RETRACT        1221
#define PRO_E_AUTO_NCL_COMMAND_AFTER_SPINDLE       1222
#define PRO_E_AUTO_NCL_COMMAND_AFTER_LOADTL        1223


/* FT_SLDBEND */
#define PRO_E_SLDBEND_FQ                           1292
/*
#define PRO_E_SLDBEND_DIR                          1293
*/
#define PRO_E_SLDBEND_OPTS                         1294
#define PRO_E_SLDBEND_CRVS                         1295
/* end FT_SLDBEND */
#define PRO_E_GCPY_SW_OPTIONS                      1296
#define PRO_E_GCPY_SW_DEP                          1297
#define PRO_E_GCPY_SW_COMP                         1298
      
/* FT_FLATQLT */
#define PRO_E_FLATQLT_QLT                          1299
#define PRO_E_FLATQLT_PNT                          1300
#define PRO_E_FLATQLT_PAR_MET                      1301
#define PRO_E_FLATQLT_PAR_PNTS                     1302
#define PRO_E_FLATQLT_PAR_SRF                      1303
#define PRO_E_FLATQLT_PLOPT                        1304
#define PRO_E_FLATQLT_CSYS                         1305
#define PRO_E_FLATQLT_X_PNT                        1306
#define PRO_E_FLATQLT_N1                           1307
#define PRO_E_FLATQLT_N2                           1308
/* End: FT_FLATQLT */

#define PRO_E_GCPY_EXTERNALIZE                     1310
#define PRO_E_SRF_OFFS_SIDEQUILT                   1312

#define PRO_E_START_LEAD_POINT                     1313

#define PRO_E_STEP_DEFORM_CONTROL                  1314
#define PRO_E_STEP_DEFORM_TYPE                     1315
#define PRO_E_STEP_DEFORM_SKETCH                   1316

#define PRO_E_DRVD_VAR_FEATS                       1317
#define PRO_E_DRVD_EXT_PLACE                       1318
#define PRO_E_GCPY_NOTES                           1319

/* Std ODUI Copy Geom */
#define PRO_E_STD_GCPY_FEAT_NAME                   1320
#define PRO_E_STD_GCPY_REFS_COLS                   1321
#define PRO_E_STD_GCPY_SURF_REFS                   1322
#define PRO_E_STD_GCPY_EDGE_REFS                   1323
#define PRO_E_STD_GCPY_CRV_REFS                    1324
#define PRO_E_STD_GCPY_MISC_REFS                   1325
#define PRO_E_STD_GCPY_PUBD_GEOM                   1326
#define PRO_E_STD_GCPY_CSYS_PLACE                  1327
#define PRO_E_STD_GCPY_LOCATION_EXT_CSYS           1328
#define PRO_E_STD_GCPY_LOCATION_LOC_CSYS           1329
#define PRO_E_STD_GCPY_EXT_MDL                     1330
#define PRO_E_STD_GCPY_EXTERNALIZE                 1331
#define PRO_E_STD_GCPY_UPDT_PLACE                  1332
#define PRO_E_STD_GCPY_LOCATION                    1333
#define PRO_E_STD_GCPY_OPT_DEFD                    1334
#define PRO_E_STD_GCPY_DEP                         1335
#define PRO_E_STD_GCPY_SW_OPTIONS                  1336
#define PRO_E_STD_GCPY_SW_DEP                      1337
#define PRO_E_STD_GCPY_SW_COMP                     1338

#define PRO_E_SRF_END_ATTRIBUTES                   1339

#define PRO_E_HLE_PLACEMENT                        1340
#define PRO_E_HLE_PRIM_REF                         1341
#define PRO_E_HLE_GEOMETRY                         1342
#define PRO_E_HLE_WORKFLOW                         1343
#define PRO_E_HLE_PREDEFHOLE                       1344
#define PRO_E_HLE_DEPTHVAL                         1345
#define PRO_E_HLE_FASTENPRM                        1346
#define PRO_E_HLE_HOLEDIAM                         1347
#define PRO_E_HLE_DRILLANGLE                       1348
#define PRO_E_HLE_CBOREDEPTH                       1349
#define PRO_E_HLE_CBOREDIAM                        1350
#define PRO_E_HLE_CSINKDIAM                        1351
#define PRO_E_HLE_CSINKANGLE                       1352
#define PRO_E_HLE_THRDDIAM                         1353
#define PRO_E_HLE_THRDDEPTH                        1354
#define PRO_E_HLE_CREATDIR                         1355
#define PRO_E_HLE_THRDSERIS                        1356
#define PRO_E_HLE_THRDCLASS                        1357
#define PRO_E_HLE_SCREWSIZE                        1358
#define PRO_E_HLE_THRDPINCH                        1359

#define PRO_E_APPEX                                1360

#define PRO_E_STD_GCPY_EXT_MDL_SEL                 1361
#define PRO_E_STD_GCPY_LOCATION_TYPE               1362

        /* For Group */
#define PRO_E_GROUP_NAME                           1363
#define PRO_E_GROUP_FEATS                          1364
#define PRO_E_GROUP_CONSTRUCTION                   1365
#define PRO_E_GROUP_RESULT                         1366

        /* Hull features */
#define PRO_E_FRSYS_REF_QUILT                      1367
#define PRO_E_FRSYS_REF_CRD                        1368
#define PRO_E_FRSYS_REF_CSYS                       1369
#define PRO_E_FRSYS_INIT_OFFS                      1370
#define PRO_E_FRSYS_SPNG_TBL                       1371
#define PRO_E_FRSYS_SPNG_DATA                      1372
#define PRO_E_FRSYS_UPTO_FR                        1373
#define PRO_E_FRSYS_SPACING                        1374
#define PRO_E_COAMING_NAME                         1375
#define PRO_E_COAMING_HEIGHT                       1376
#define PRO_E_COAMING_PLACEMENT                    1377
#define PRO_E_COAMING_OFFSET                       1378
#define PRO_E_COAMING_SELECT                       1379
#define PRO_E_COMPARTMENT_QUILT_UP                 1380
#define PRO_E_COMPARTMENT_QUILT_LOW                1381
#define PRO_E_COMPARTMENT_QUILT_PORT               1382
#define PRO_E_COMPARTMENT_QUILT_STARB              1383
#define PRO_E_COMPARTMENT_QUILT_FORD               1384
#define PRO_E_COMPARTMENT_QUILT_AFT                1385
#define PRO_E_REFS_FT_TYPE                         1386
#define PRO_E_REFS_FT_REFS                         1387

/*Added Entries for proship module */ 

#define PRO_E_STOBJ_REF                            1388
#define PRO_E_STOBJ_THICKNESS                      1389
#define PRO_E_STOBJ_CUTOUT_MODE                    1390
#define PRO_E_STOBJ_CUTOUT_SEL                     1391
#define PRO_E_STOBJ_CUTOUT_IDFY                    1392
#define PRO_E_STOBJ_OBJ_ARR                        1393
#define PRO_E_STOBJ_PEN_OBJLIST                    1394
#define PRO_E_STOBJ_ID_CUT_TYPE                    1395
#define PRO_E_STOBJ_CUTOUT_DISP                    1396
#define PRO_E_STOBJ_CUTOUT_LAYER                   1397
#define PRO_E_STOBJ_CUTOUT_STIFF_REF               1398
#define PRO_E_STOBJ_CUTOUT_OBJLIST_REF             1399

/* Structural Hole ODUI */

#define PRO_E_HULL_HOLE_ROOT                       1400
#define PRO_E_HULL_HOLE_MODE                       1401
#define PRO_E_HULL_HOLE_SKETCH                     1402

#define PRO_E_HULL_HOLE_ROTATION_ANGLE             1403

#define PRO_E_HULL_HOLE_STD_SEC                    1404
#define PRO_E_HULL_HOLE_STD_SEC_ID                 1405
#define PRO_E_HULL_HOLE_ORIENTATION                1406

#define PRO_E_HULL_HOLE_SURFACE                    1407
#define PRO_E_HULL_HOLE_PLACEMENT                  1408

#define PRO_E_HULL_HOLE_EXISTING_EDGES             1409
#define PRO_E_HULL_HOLE_EDGES                      1410

#define PRO_E_HULL_HOLE_UV                         1411

/* vrahangd added for stiffener. */

#define PRO_E_STIFF_GEOM                           1412
#define PRO_E_STIFF_SECT                           1413
#define PRO_E_STIFF_SECTYPE                        1414
#define PRO_E_STIFF_SECNAME                        1415

#define PRO_E_STIFF_REFPLT                         1416
#define PRO_E_STIFF_TRJCT                          1417
#define PRO_E_STIFF_ENDCONS                        1418
#define PRO_E_STIFF_END1CONSREF                    1419
#define PRO_E_STIFF_SETBACK1VAL                    1420
#define PRO_E_STIFF_END2CONSREF                    1421
#define PRO_E_STIFF_SETBACK2VAL                    1422
        
#define PRO_E_STIFF_END1VAL                        1423
#define PRO_E_STIFF_END2VAL                        1424
#define PRO_E_STIFF_THICKDIR                       1425
#define PRO_E_STIFF_WEBOFSTVAL                     1426
#define PRO_E_STIFF_WEBROTOPT                      1427
#define PRO_E_STIFF_IDENTIFY                       1428
#define PRO_E_STIFF_CLASSIFIC                      1429
#define PRO_E_HULL_MATCODE                         1430
#define PRO_E_STIFF_COUTYPE                        1431
#define PRO_E_STIFF_COLLTYPE                       1432
#define PRO_E_STIFF_ORIENT                         1433
#define PRO_E_STIFF_WEBORNT                        1434
#define PRO_E_STIFF_FLNGORNT                       1435
#define PRO_E_STIFF_ROTATE                         1436
#define PRO_E_STIFF_ROTOPT                         1437
#define PRO_E_STIFF_ROTVAL                         1438
#define PRO_E_STIFF_ROTEND1                        1439
#define PRO_E_STIFF_ROTEND2                        1440
#define PRO_E_STIFF_SELARR                         1441
#define PRO_E_STIFF_SELREF                         1442
#define PRO_E_STIFF_SELANG                         1443

#define PRO_E_DATUM_CURVE_SURF                     1444
#define PRO_E_STIFF_SEL_ROT_ENDREF                 1445

#define PRO_E_STIFF_END1_CONFIGURE_OPTS            1446
#define PRO_E_STIFF_END2_CONFIGURE_OPTS            1447
#define PRO_E_STIFF_END1_TAPER_OPTS                1448
#define PRO_E_STIFF_END2_TAPER_OPTS                1449
#define PRO_E_STIFF_END1_TAPER_VALUE               1450
#define PRO_E_STIFF_END2_TAPER_VALUE               1451

/* Plate related changes begin here */

#define PRO_E_PLATE_BOUND_CMP                      1462
#define PRO_E_PLATE_BOUND_TAB                      1463
#define PRO_E_PLATE_SPLIT_SELBOUND                 1464
#define PRO_E_PLATE_SELQUILT                       1465
#define PRO_E_PLATE_SELBOUND                       1466
#define PRO_E_PLATE_THICKOPT                       1467
#define PRO_E_PLATE_VALTHICK                       1468
#define PRO_E_PLATE_LISTTHICK                      1469
#define PRO_E_PLATE_THICKORIENT                    1470
#define PRO_E_PLATE_OFFSTMOLDSRF                   1471
#define PRO_E_PLATE_KNUCKRAD                       1472

#define PRO_E_PLATE_MATCODE                        1473
#define PRO_E_PLATE_IDENTIFY                       1474
#define PRO_E_PLATE_GEOMETRY                       1475
#define PRO_E_PLATE_SHP_PARAMETER                  1476
#define PRO_E_PLATE_EXTEND_EDGE                    1477
#define PRO_E_PLATE_EXTEND_DIST                    1478

/* Plate related changes end here */


#define PRO_E_DATUM_CURVE_CURVE_MENU               1484
#define PRO_E_DATUM_CURVE_REF_TO_CRV               1485
#define PRO_E_DATUM_CURVE_REF_CURVE                1486
#define PRO_E_DATUM_CURVE_FIRST_CURVE              1487
#define PRO_E_DATUM_CURVE_SECOND_CURVE             1488
#define PRO_E_DATUM_CURVE_DIRECTION                1489
#define PRO_E_DATUM_CURVE_IS_CONSTANT              1490
#define PRO_E_DATUM_CURVE_REF_POINT                1491
#define PRO_E_DATUM_CURVE_OFFSET_VAL               1492
#define PRO_E_DATUM_CURVE_NO_OF_CURVES             1493
#define PRO_E_DATUM_CURVE_M_DIR                    1494
#define PRO_E_DATUM_CURVE_REF_PLANE                1495
#define PRO_E_DATUM_CURVE_IS_ASSIGN                1496
#define PRO_E_DATUM_CURVE_VAR_OFFSET_TAB           1497
#define PRO_E_DATUM_CURVE_VAR_OFFSET_CMP           1498
#define PRO_E_DATUM_CURVE_VAR_OFFSET_REF           1499
#define PRO_E_DATUM_CURVE_VAR_OFFSET_VAL           1500

#define PRO_E_BEAM_GEOM_TRAJECT                    1501

        /* Added for User Defined Gravity Point Option */
#define PRO_E_GRAVITY_POINT                        1502
#define PRO_E_USER_DEF_GP                          1503

        /* Unused constants between 1502 -1508 removed in J-01 */

#define PRO_E_BEAM_ORIENT                          1509
#define PRO_E_BEAM_ORNT_WEB                        1510
#define PRO_E_BEAM_ORNT_FLANGE                     1511
#define PRO_E_BEAM_ORNT_ALONG_WEB_DBL              1512
#define PRO_E_BEAM_ORNT_ALONG_FLANGE_DBL           1513
#define PRO_E_BEAM_IDENTIFY                        1514
#define PRO_E_BEAM_IDENT_CLASSIFY                  1515
#define PRO_E_BEAM_IDENT_MAT_CODE                  1516
#define PRO_E_BEAM_GEOM                            1517
#define PRO_E_BEAM_TRJOPT                          1518
#define PRO_E_BEAM_TRJLOC                          1519
#define PRO_E_BEAM_WEBORNT                         1520

#define PRO_E_FIT_OFFSET                           1544
#define PRO_E_TRIM1S_OFFSET                        1545
#define PRO_E_TRIM1S_REF_TYPE                      1546
#define PRO_E_HULL_FEAT_NAME                       1547

#define PRO_E_FRSYS_LBP                            1548
#define PRO_E_FRSYS_DIRECTION                      1549

/* ship deck surface */

#define PRO_E_DECK_NAME                            1550
#define PRO_E_DECK_HEIGHT_REF                      1551
#define PRO_E_DECK_HEIGHT_VALUE                    1552
#define PRO_E_DECK_BOUND_SRF                       1553
#define PRO_E_DECK_EXTENT                          1554
#define PRO_E_DECK_EXTENT_FWD                      1555
#define PRO_E_DECK_EXTENT_AFT                      1556
#define PRO_E_DECK_EXTENT_PORT                     1557
#define PRO_E_DECK_EXTENT_STBD                     1558
#define PRO_E_DECK_FWD_SHEER                       1559
#define PRO_E_DECK_SHEER_FWD_TYPE                  1560
#define PRO_E_DECK_SHEER_FWD_VALUE                 1561
#define PRO_E_DECK_SHEER_FWD_EXT_REF               1562
#define PRO_E_DECK_SHEER_FWD_EXT_VALUE             1563
#define PRO_E_DECK_SHEER_AFT_TYPE                  1564
#define PRO_E_DECK_SHEER_AFT_VALUE                 1565
#define PRO_E_DECK_SHEER_AFT_EXT_REF               1566
#define PRO_E_DECK_SHEER_AFT_EXT_VALUE             1567
#define PRO_E_DECK_CAMBER                          1568
#define PRO_E_DECK_CAMBER_TYPE                     1569
#define PRO_E_DECK_CAMBER_VALUE                    1570
#define PRO_E_DECK_FLAT_OF_CROWN                   1571

#define PRO_E_COMPARTMENT_ATTRS                    1572
#define PRO_E_COMPARTMENT_EXTENT                   1573
#define PRO_E_COMPARTMENT_ATTRS_DATA               1574
#define PRO_E_COMPARTMENT_TANK_TYPE                1575
#define PRO_E_COMPARTMENT_GRAVITY                  1576
#define PRO_E_COMPARTMENT_FILL_RATIO               1577
#define PRO_E_COMPARTMENT_PERMEABILITY             1578

#define PRO_E_HULL_BHD_BULKHEAD_INPUTS             1579
#define PRO_E_HULL_BHD_BULKHEAD_NAME               1580
#define PRO_E_HULL_BHD_ORIENTATION                 1581
#define PRO_E_HULL_BHD_BULKHEAD_TYPE               1582
#define PRO_E_HULL_BHD_BULKHEAD_LOCATION           1583
#define PRO_E_HULL_BHD_DEFINITION_METHOD           1584
#define PRO_E_HULL_BHD_FWD_SECTION                 1585
#define PRO_E_HULL_BHD_AFT_SECTION                 1586
#define PRO_E_HULL_BHD_EXTENTS                     1587
#define PRO_E_HULL_BHD_BULKHEAD_PLANE              1588
#define PRO_E_HULL_BHD_PORT                        1589
#define PRO_E_HULL_BHD_STARBOARD                   1590
#define PRO_E_HULL_BHD_FORWARD                     1591
#define PRO_E_HULL_BHD_AFT                         1592
#define PRO_E_HULL_BHD_TOP                         1593
#define PRO_E_HULL_BHD_BOTTOM                      1594
#define PRO_E_HULL_BHD_CORRUGATION_SWEDGE          1595
#define PRO_E_HULL_BHD_STOOL_LOW_H2                1596
#define PRO_E_HULL_BHD_STOOL_LOW_H1                1597
#define PRO_E_HULL_BHD_PITCH                       1598
#define PRO_E_HULL_BHD_FILLET_RADIUS               1599
#define PRO_E_HULL_BHD_DEPTH                       1600
#define PRO_E_HULL_BHD_STOOL_UP_H1                 1601
#define PRO_E_HULL_BHD_STOOL_UP_H2                 1602
#define PRO_E_HULL_BHD_STOOL_UP_WIDTH              1603
#define PRO_E_HULL_BHD_L                           1604
#define PRO_E_HULL_BHD_STOOL_LOW_WIDTH             1605
#define PRO_E_HULL_BHD_STOOL_SEL_DIR               1606
#define PRO_E_HULL_BHD_STOOL_SEL_PARAMS            1607
#define PRO_E_HULL_BHD_STOOL_SEL_SRF               1608
#define PRO_E_HULL_BHD_STOOL_BND_SRF               1609
#define PRO_E_HULL_BHD_STOOL_SIT_SRF               1610
#define PRO_E_HULL_BHD_STOOL_DEF_PLN               1611
#define PRO_E_SHELL_QUILT                          1612
#define PRO_E_SHELL_FRAME                          1613
#define PRO_E_SHELL_HULLPART                       1614
#define PRO_E_SHELL_REFER                          1615
#define PRO_E_SHELL_OFFREF                         1616
#define PRO_E_SHELL_UPTO                           1617
#define PRO_E_SHELL_OFFUPTO                        1618
#define PRO_E_SHELL_CURVE                          1619
#define PRO_E_SHELL_CRVSELECT                      1620
#define PRO_E_MLDVOL_NAME                          1621
#define PRO_E_STD_GCPY_SW_ADV                      1622
#define PRO_E_STD_DRVD_BASE_MODEL                  1623
#define PRO_E_STD_DRVD_VAR_DIMS                    1624
#define PRO_E_STD_DRVD_VAR_FEATS                   1625

#define PRO_E_DECK_AFT_SHEER                       1626
#define PRO_E_COAMING_OPTION                       1627
#define PRO_E_COAMING_SKETCH                       1628
#define PRO_E_COAMING_SURFACE                      1629
#define PRO_E_COPYTRIM_QUILT                       1630
#define PRO_E_COPYTRIM_CURVES                      1631
#define PRO_E_COPYTRIM_CURVE_TBL                   1632
#define PRO_E_COPYTRIM_CURVE_DATA                  1633
#define PRO_E_COPYTRIM_CURVE                       1634
#define PRO_E_COMPARTMENT_ID                       1635
#define PRO_E_COMPARTMENT_VOLUME                   1636
#define PRO_E_HULL_BHD_SWEDGED_SEL_DIR             1637
#define PRO_E_HULL_BHD_CORRUGATED_SEL_DIR          1638
#define PRO_E_HULL_BHD_FILLET_RADIUS_1             1639
#define PRO_E_HULL_BHD_FILLET_RADIUS_2             1640
#define PRO_E_HULL_BHD_L_1                         1641
#define PRO_E_HULL_BHD_L_2                         1642
#define PRO_E_HULL_BHD_DIST_TO_SIDES               1643
#define PRO_E_HULL_BHD_PLN_OFFSET                  1644

#define PRO_E_HULL_SECT_TYPE                       1645
#define PRO_E_HULL_SECT_NAME                       1646

#define PRO_E_FRM_CONST_Z                          1647
#define PRO_E_FRM_START_X                          1648
#define PRO_E_FRM_USER_X                           1649
#define PRO_E_FRM_NORM_SURF                        1650
#define PRO_E_SWP_ATTR                             1651
#define PRO_E_SWP_INNER_SRF                        1652
#define PRO_E_SWP_MERGE_ENDS                       1653
#define PRO_E_SWP_BLN_SEC                          1654
#define PRO_E_FRM_NORM_SURF_SIDE                   1655
#define PRO_E_FRM_X_CHOICE_BTN                     1656
#define PRO_E_FRM_Z_CHOICE_BTN                     1657
#define PRO_E_SWP_SEC_PNT                          1658
#define PRO_E_SWP_SEC_PNT_CHOICE                   1659
#define PRO_E_SWP_SEC_PNT_REF                      1660
#define PRO_E_HLE_FITTYPE                          1661
#define PRO_E_HLE_DEPTH                            1662
#define PRO_E_HLE_DRILLDEPTH                       1663
#define PRO_E_HLE_UPTODEPTHREF                     1664
#define PRO_E_STIFF_PLT_OFFST                      1665

#define PRO_E_DECK_HULL_BREADTH                    1666
#define PRO_E_DECK_HULL_LBP                        1667

#define PRO_E_SPLIT_VOL_SEL                        1668
#define PRO_E_SPLIT_GEOM_OPT                       1669
#define PRO_E_HLE_HOLEID                           1670
#define PRO_E_HLE_COM                              1671
#define PRO_E_HLE_TYPE_NEW                         1672
#define PRO_E_HLE_STAN_TYPE                        1673
#define PRO_E_HLE_ADD_THREAD                       1674
#define PRO_E_HLE_ADD_CBORE                        1675
#define PRO_E_HLE_ADD_CSINK                        1676
#define PRO_E_HLE_PLCMNT_PLANE                     1677
#define PRO_E_HLE_REF_PLANE_1                      1678
#define PRO_E_HLE_REF_ANG_1                        1679
#define PRO_E_HLE_THRD_DEPTH                       1680
#define PRO_E_GROUP_CE_UPDATE                      1681
#define PRO_E_GROUP_CE_INDEPENDENT                 1682
#define PRO_E_CMD_BLEND_TYPE                       1683
#define PRO_E_HOLE_STD_DEPTH                       1684
#define PRO_E_HOLE_DEPTH_FROM                      1685
#define PRO_E_HOLE_DEPTH_TO                        1686
#define PRO_E_HOLE_DEPTH_FROM_TYPE                 1687
#define PRO_E_HOLE_DEPTH_TO_TYPE                   1688
#define PRO_E_HLE_CRDIR_FLIP                       1689
#define PRO_E_COAMING_FWD_DTM                      1690
#define PRO_E_COAMING_AFT_DTM                      1691
#define PRO_E_COAMING_FWD_VALUE                    1692
#define PRO_E_COAMING_AFT_VALUE                    1693
#define PRO_E_COAMING_PORT_VALUE                   1694
#define PRO_E_COAMING_STBD_VALUE                   1695

#define PRO_E_HULL_BHD_STOOL_SEL_PARAMS_1          1696
#define PRO_E_HULL_BHD_STOOL_SEL_PARAMS_2          1697
#define PRO_E_HULL_BHD_STOOL_UP_W1                 1698
#define PRO_E_HULL_BHD_STOOL_UP_W2                 1699
#define PRO_E_HULL_BHD_STOOL_LOW_W1                1700
#define PRO_E_HULL_BHD_STOOL_LOW_W2                1701
#define PRO_E_HULL_BHD_CORRUGATION_PARAMS          1702
#define PRO_E_HULL_BHD_CORRU_PARAMS_1              1703
#define PRO_E_HULL_BHD_CORRU_PARAMS_2              1704
#define PRO_E_HULL_BHD_CORRU_DIST_1                1705
#define PRO_E_HULL_BHD_CORRU_DIST_2                1706
#define PRO_E_HULL_BHD_SWEDGE_PARAMS               1707
#define PRO_E_HULL_BHD_SWEDGE_PARAMS_1             1708
#define PRO_E_HULL_BHD_SWEDGE_PARAMS_2             1709
#define PRO_E_HULL_BHD_TRANS_CORRUG_DIR            1710
#define PRO_E_HULL_BHD_LONGI_CORRUG_DIR            1711
#define PRO_E_HULL_BHD_TRANS_SWEDGE_DIR            1712
#define PRO_E_HULL_BHD_LONGI_SWEDGE_DIR            1713
#define PRO_E_CLASS_TYPE                           1714
#define PRO_E_CLASS_SEL_CLASS                      1715
#define PRO_E_CLASS_SEL_OPT_APPLY                  1716
#define PRO_E_CLASS_SEL_OLD_CLASS                  1717
#define PRO_E_CLASS_SEL_OLD_VALUE                  1718
#define PRO_E_CLASS_SEL_OLD_CLASS_REM              1719
#define PRO_E_HULL_STD_HULL_CLASSIFICATION         1720
#define PRO_E_STIFF_ORNT_PLN                       1721

#define PRO_E_HULL_ENDCUT_STIFFENERS               1722
#define PRO_E_HULL_ENDCUT_TABLE                    1723
#define PRO_E_HULL_ENDCUT_TABLE_ELEMENTS           1724

#define PRO_E_HULL_ENDCUT_WEB_END1                 1725
#define PRO_E_HULL_ENDCUT_WEB_END2                 1726
#define PRO_E_HULL_ENDCUT_FLANGE_END1              1727
#define PRO_E_HULL_ENDCUT_FLANGE_END2              1728

#define PRO_E_HULL_ENDCUT_WEBEND1_OPTS             1729
#define PRO_E_HULL_ENDCUT_WEBEND2_OPTS             1730
#define PRO_E_HULL_ENDCUT_FLGEND1_OPTS             1731
#define PRO_E_HULL_ENDCUT_FLGEND2_OPTS             1732

#define PRO_E_PLATE_KNUCK_RAD_TAB                  1733
#define PRO_E_PLATE_KNUCK_RAD_CMP                  1734
#define PRO_E_PLATE_KNUCK_RAD_REF                  1735
#define PRO_E_PLATE_KNUCK_RAD_VAL                  1736
#define PRO_E_WLD_FLANGE_TRAJECT                   1737
#define PRO_E_WLD_FLANGE_ALIGN                     1738
#define PRO_E_WLD_FLANGE_ROT                       1739
#define PRO_E_WLD_FLANGE_TYPE                      1740
#define PRO_E_WLD_FLANGE_OFFSET                    1741
#define PRO_E_WLD_FLANGE_GEOM                      1742
#define PRO_E_WLD_FLANGE_ORIENT                    1743
#define PRO_E_DSHARE_DEPENDENCY                    1744
#define PRO_E_AUTO_BEND_EDGES                      1745

#define PRO_E_COLLAR_CUTOUT_ARR                    1746
#define PRO_E_COLLAR_CUTOUT_LIST                   1747
#define PRO_E_COLLAR_CUTOUT_REF                    1748
#define PRO_E_COLLAR_MODE                          1749
#define PRO_E_COLLAR_IDFY                          1750
#define PRO_E_COLLAR_STIFF_SIDE                    1751
#define PRO_E_COLLAR_THICK                         1752
#define PRO_E_COLLAR_PLATE_SIDE                    1753
#define PRO_E_COLLAR_SEL                           1754
#define PRO_E_DSHARE_COPY_DATUMS                   1755
#define PRO_E_DSHARE_REFIT_DATUMS                  1756

 /* 1757 - 1764 Used by Brackets in J-01 is no longer in use */ 

#define PRO_E_REP_STRUCT_OBJ_IDENT                 1765
#define PRO_E_FRSYS_PNT_X_REF                      1766
#define PRO_E_FRSYS_PNT_Y_REF                      1767
#define PRO_E_FRSYS_PNT_Z_REF                      1768
#define PRO_E_FRSYS_PNT_X_OFFSET                   1769
#define PRO_E_FRSYS_PNT_Y_OFFSET                   1770
#define PRO_E_FRSYS_PNT_Z_OFFSET                   1771
#define PRO_E_FRSYS_PNT_X_DIR                      1772
#define PRO_E_FRSYS_PNT_Y_DIR                      1773
#define PRO_E_FRSYS_PNT_Z_DIR                      1774

#define PRO_E_SMT_WLD_SPLIT_ARR                    1775
#define PRO_E_SMT_WLD_SPLIT_CMPND                  1776
#define PRO_E_SMT_WLD_SPLIT_CHAIN                  1777
#define PRO_E_SMT_WLD_SPLIT_DIR                    1778
#define PRO_E_SMT_WLD_DRV_SRF_ARR                  1779
#define PRO_E_SMT_WLD_DRV_SRF_SEL                  1780
#define PRO_E_SMT_WLD_THICKNESS                    1781
          
#define PRO_E_REP_STRUCT_OBJ_CPY_TYPE              1782
#define PRO_E_REP_STRUCT_OBJ_BASE_OBJ              1783
    
#define PRO_E_PLATE_SELQUILT_MULT                  1784
#define PRO_E_CUSTOM_CYCLE                         1785

#define PRO_E_SMT_HEM_TRAJECTORY                   1786
#define PRO_E_SMT_HEM_SHAPE                        1787
#define PRO_E_SMT_HEM_SECTION                      1789
#define PRO_E_SMT_HEM_DIM1                         1790
#define PRO_E_SMT_HEM_DIM2                         1791
#define PRO_E_SMT_HEM_DIM3                         1792
#define PRO_E_SMT_HEM_DIM4                         1793
#define PRO_E_SMT_HEM_DIM5                         1794
#define PRO_E_SMT_HEM_DIM6                         1795
#define PRO_E_SMT_HEM_DIM7                         1796
#define PRO_E_SMT_HEM_FLIP                         1797
/* Bulk Feature */
#define PRO_E_BULK_FEAT_MSR_ARRAY                  1798
#define PRO_E_BULK_FEAT_MSR                        1799
#define PRO_E_BULK_TEMPLATE                        1800
#define PRO_E_SMT_EXTRACT_ASM_NAME                 1815
#define PRO_E_SMT_EXTRACT_SKEL_NAME                1816
#define PRO_E_UIE_SMT_EXTRACT_VOL_ARR              1817
#define PRO_E_SMT_EXTRACT_ONE_VOL                  1818
#define PRO_E_SMT_EXTRACT_VOL_IDX                  1819
#define PRO_E_SMT_EXTRACT_VOL_NAME                 1820
#define PRO_E_SMT_EXTRACT_VOL_THICK                1821
#define PRO_E_COMPARTMENT_IDENTITY                 1822
#define PRO_E_COMPARTMENT_ID_STRING                1823
#define PRO_E_COMPARTMENT_ID_SERIAL                1824

/* Folded Flange */

#define PRO_E_HULL_FOLDED_FLG_EDGE                 1825
#define PRO_E_HULL_FOLDED_FLG_WIDTH                1826
#define PRO_E_HULL_FOLDED_FLG_ANGLE                1827
#define PRO_E_HULL_FOLDED_FLG_RADIUS               1828
#define PRO_E_HULL_FOLDED_FLG_END1_SETBACK         1829
#define PRO_E_HULL_FOLDED_FLG_END2_SETBACK         1830
#define PRO_E_HULL_FOLDED_FLG_COMPOUND             1831
#define PRO_E_HULL_FOLDED_FLG_FLIP                 1832

#define PRO_E_RIBBON_BASE_CRV                      1833
#define PRO_E_RIBBON_REF_CRV                       1834
#define PRO_E_RIBBON_WIDTH                         1835

/* DS Optimization Feature */
#define PRO_E_DS_OPTIM_NAME                        1836
#define PRO_E_DS_OPTIM_DEF                         1837
#define PRO_E_DS_OPTIM_REG_REQUEST                 1838
        
#define PRO_E_RIB_START                            1839
#define PRO_E_RNDSET_AMBIGUITY                     1840
#define PRO_E_HULL_BHD_FWDSKETCH_PLANE             1841
#define PRO_E_HULL_BHD_SECTION_NUM                 1842
#define PRO_E_COAMING_FILLET_VALUE1                1843
#define PRO_E_WLD_FLANGE_CENTER                    1844
#define PRO_E_CUTOUT_COLLAR_IDFY                   1845
#define PRO_E_CUTOUT_COLLAR_MODE                   1846
#define PRO_E_COAMING_FILLET_VALUE2                1847
#define PRO_E_COAMING_STANDARD                     1848
#define PRO_E_PLATE_SELQUILT_SINGLE                1849

#define PRO_E_FRSYS_PNT_NAME                       1850
#define PRO_E_COLLAR_PIECE                         1851
#define PRO_E_STOBJ_CUTOUT_EDGE                    1852
#define PRO_E_WLD_FLANGE_IDENTIFY                  1853
        
#define PRO_E_WLD_PREP_DEPENDENCY                  1854
#define PRO_E_STIFF_DEF_COLLAR                     1855
#define PRO_E_REP_STRUCT_OBJ_PREFIX                1856
#define PRO_E_COAMING_OPENING                      1857
#define PRO_E_LOC_MACH_AREA                        1858
/*bracket related */
#define PRO_E_BKT_GEOM_PG                          1859
#define PRO_E_BKT_GEOM_OPT                         1860
#define PRO_E_BKT_DIM_OPT                          1861
#define PRO_E_BKT_FAM_GENIRICSEL                   1862
#define PRO_E_BKT_FAM_SEC_SEL                      1863
#define PRO_E_BKT_PLACE_PG                         1864
#define PRO_E_BKT_CON_OBJ_1                        1865
#define PRO_E_BKT_CON_OBJ_2                        1866
#define PRO_E_BKT_CON_OBJ_3                        1867
#define PRO_E_BKT_CON_OBJ_4                        1868
#define PRO_E_BKT_INS_PLN                          1869
#define PRO_E_BKT_OFFSET_VAL                       1870
#define PRO_E_BKT_NAME_THK_PG                      1871
#define PRO_E_BKT_THK_VAL                          1872
#define PRO_E_BKT_QUADR_FLIP_OPT                   1873
#define PRO_E_BKT_FLANGE_MAIN_PG                   1874
#define PRO_E_BKT_FLANGE_OPT                       1875
#define PRO_E_BKT_FLANGE_DIR                       1876
#define PRO_E_BKT_FLANGE_WIDTH                     1877
#define PRO_E_BKT_BEND_RADIUS                      1878
#define PRO_E_BKT_FLANGE_ANGLE                     1879
#define PRO_E_BKT_FLG_END1_SETBACK                 1880
#define PRO_E_BKT_FLG_END2_SETBACK                 1881
#define PRO_E_BKT_FLANGE_CUT_PG1                   1882
#define PRO_E_BKT_ENDCUT_FLGEND1_OPTS              1883
#define PRO_E_BKT_FLANGE_CUT_PG2                   1884
#define PRO_E_BKT_ENDCUT_FLGEND2_OPTS              1885

        /* hull block */
#define PRO_E_BLKDEF_LONG_PLN                      1886
#define PRO_E_BLKDEF_TRAV_PLN                      1887
#define PRO_E_BLKDEF_HORIZ_PLN                     1888
#define PRO_E_HULL_ASSEM_COPY_SEL_ASM              1889
#define PRO_E_HULL_ASSEM_COPY_SEL_COMP             1890
#define PRO_E_HULL_ASSEM_COPY_CUR_EXTREF           1891
#define PRO_E_HULL_ASSEM_COPY_SEL_EXTREF           1892
#define PRO_E_HULL_ASM_COPY_PART_NAME              1893
#define PRO_E_HULL_ASM_COPY_PNAME_IP               1894
        
#define PRO_E_COLLAR_NAME                          1895
/* asagarwa added for weld. */  
#define PRO_E_HULL_WELD_GEOM                       1896
#define PRO_E_HULL_WELD_TYPE                       1897
#define PRO_E_HULL_WELD_CODE                       1898
#define PRO_E_HULL_BEVEL_CODE                      1899
#define PRO_E_HULL_WELD_PRIMARY_OBJ                1900
#define PRO_E_HULL_WELD_LIST_PRI_OBJ               1901
#define PRO_E_HULL_WELD_SECONDARY_OBJ              1902
#define PRO_E_HULL_WELD_OPENING                    1903
#define PRO_E_HULL_WELD_FLIP                       1904
#define PRO_E_HULL_WELD_POSITION                   1905
#define PRO_E_HULL_WELD_NAME                       1906

#define PRO_E_BULK_PARAMS_ARRAY                    1907
#define PRO_E_BULK_ONE_PARAM                       1908
#define PRO_E_BULK_PARAM_TYPE                      1909
#define PRO_E_BULK_PARAM_VAL                       1910
#define PRO_E_BULK_PARAM_INT_VAL                   1911
#define PRO_E_BULK_PARAM_REAL_VAL                  1912
#define PRO_E_BULK_PARAM_WSTRING_VAL               1913
#define PRO_E_BULK_PARAM_BOOL_VAL                  1914
#define PRO_E_BULK_PARAM_REF                       1915

#define PRO_E_ROUTE_EXTEND_MAINREF                 1916
#define PRO_E_ROUTE_SETSTART_MAINREF               1917
        
#define PRO_E_HULL_NOTCH_CODE_OPTIONLIST           1918
#define PRO_E_HULL_NOTCH_FLIP_OPTION               1919
#define PRO_E_HULL_NOTCH_WELD_SEL_LIST             1920
#define PRO_E_HULL_NOTCH_ASSEMBLY_SEL              1921


#define PRO_E_WLD_ASM_NOTCH_REF_FT                 1922
#define PRO_E_WLD_ASM_NOTCH_TYPE                   1923
#define PRO_E_WLD_ASM_NOTCH_DIMS                   1924
#define PRO_E_WLD_ASM_NOTCH_SEC                    1925
#define PRO_E_WLD_ASM_NOTCH_TRAJ                   1926
#define PRO_E_WLD_ASM_NOTCH_ORIENT                 1927
#define PRO_E_BLKDEF_BOUNDARY                      1928
#define PRO_E_CUTOUT_CR_PROFILE                    1929
#define PRO_E_CUTOUT_ORIENT                        1930

#define PRO_E_DRVD_VAR_SHRINK                      1931

#define PRO_E_SMT_BNDTBL_ASSIGN                    1932
#define PRO_E_SMT_BNDTBL_SRCOPT                    1933
#define PRO_E_SMT_BNDTBL_PATH                      1934
#define PRO_E_SMT_SHARPSTOBEND                     1935
#define PRO_E_SMT_USERADIUS                        1936
#define PRO_E_SMT_ATT_EDGE                         1937
#define PRO_E_SMT_BENDTBL                          1938
#define PRO_E_SMT_BEND_RELIEF_SIDE1                1939
#define PRO_E_SMT_BEND_RELIEF_SIDE2                1940
#define PRO_E_SMT_BEND_RELIEF                      1941
#define PRO_E_SMT_BEND_ANGLE                       1942
#define PRO_E_SMT_BEND_RADIUS                      1943
#define PRO_E_SMT_BEND_RAD_TYPE                    1944
#define PRO_E_SMT_BEND_RAD_VALUE                   1945
#define PRO_E_BEND_RELIEF_TYPE                     1946
#define PRO_E_BEND_RELIEF_WIDTH                    1947
#define PRO_E_BEND_RELIEF_DEPTH                    1948
#define PRO_E_BEND_RELIEF_ANGLE                    1949
#define PRO_E_SMT_KEEP_WALL_HEIGHT                 1950
        
 /* Mold Slider Feature */
#define PRO_E_REF_PART_SEL                         1951
#define PRO_E_DEFAULT_DIR                          1952
#define PRO_E_CUSTOM_DIR                           1953
#define PRO_E_SLIDER_CLASS                         1954
#define PRO_E_PROJ_PLANE_SEL                       1955
        
#define PRO_E_EXT_SURF_CUT_SOLID_TYPE              1956

#define PRO_E_FORM_PLACE                           1957
#define PRO_E_FORM_BOUND                           1958
#define PRO_E_FORM_SEED                            1959
#define PRO_E_FORM_SIDE                            1960
#define PRO_E_FORM_EXCL_SRF                        1961
#define PRO_E_FORM_CSYS                            1962
#define PRO_E_FORM_TOOLNAME                        1963

#define PRO_E_STD_FEATURE_NAME                     1964

#define PRO_E_RIB_THICKNESS                        1965

#define PRO_E_PLATE_EXTEND_TAB                     1966
#define PRO_E_PLATE_EXTEND_TAB_CMP                 1967
#define PRO_E_PLATE_CONST_OPTION                   1968

#define PRO_E_PAD_PILLAR_SEL_PG                    1969
#define PRO_E_PAD_PILLAR_SEL                       1970
#define PRO_E_PAD_GEOM_PG                          1971
#define PRO_E_PAD_HT                               1972
#define PRO_E_PAD_WIDTH                            1973
#define PRO_E_PAD_THK                              1974
#define PRO_E_PAD_BOT_OPT                          1975
#define PRO_E_PAD_TOP_OPT                          1976
#define PRO_E_TOP_PAD_HT                           1977
#define PRO_E_TOP_PAD_WIDTH                        1978
#define PRO_E_TOP_PAD_THK                          1979
#define PRO_E_RED_END_OPT                          1980
#define PRO_E_TOP_PAD_SEC_SUB_PG                   1981
#define PRO_E_PAD_NAME_PG                          1982
        
/* Mold Tangent Draft Feature */

#define PRO_E_PULL_DIR_OPTS                        1983
#define PRO_E_PULL_DIR_SEL                         1984
#define PRO_E_PULL_DIR_FLIP                        1985
#define PRO_E_TANDFT_MATERIAL                      1986
#define PRO_E_TANDFT_GEOMETRY                      1987
#define PRO_E_TANDFT_SIDE                          1988
#define PRO_E_TANDFT_DRAFT_LINE_SEL                1989
#define PRO_E_TANDFT_PART_SURF_SEL                 1990
#define PRO_E_TANDFT_DRAFT_ANGLE                   1991
#define PRO_E_TANDFT_DRAFT_RADIUS                  1992
#define PRO_E_TANDFT_CLOSING_SURFACES              1993
#define PRO_E_TANDFT_CAP_ANGLE                     1994
#define PRO_E_TANDFT_CURVE_CONTROL                 1995
#define PRO_E_TANDFT_SPINE_CURVES                  1996
#define PRO_E_TANDFT_TYPE                          1997

#define PRO_E_FRCRVS_REF_QUILT                     1998
#define PRO_E_FRCRVS_REF_FRSYS                     1999
#define PRO_E_FRCRVS_PREFIX                        2000

        /* new elements for pad */
#define PRO_E_PAD_SEC_SUB_PG                       2001
#define PRO_E_PAD_TOP_NAME_PG                      2002
#define PRO_E_PAD_CORN_RAD                         2003
#define PRO_E_TOP_PAD_CORN_RAD                     2004

#define PRO_E_CUTOUT_PLATE_REF                     2005
#define PRO_E_CUTOUT_PLATE_OBJLIST                 2006
#define PRO_E_CUTOUT_PLATE_OBJLIST_REF             2007
#define PRO_E_COLLAR_IDENTIFY                      2008
#define PRO_E_HULL_PART_NAME                       2009

#define PRO_E_DRVD_VAR_REFS                        2010

#define PRO_E_HULL_MITRE_SEL_FIRST                 2011
#define PRO_E_HULL_MITRE_SEL_SECOND                2012
#define PRO_E_HULL_MITRE_JOINT_TYPE                2013

#define PRO_E_WLD_PREP_GEOMTYPE                    2014

#define PRO_E_DTMAXIS_CONSTRAINTS                  2015
#define PRO_E_DTMAXIS_CONSTRAINT                   2016
#define PRO_E_DTMAXIS_CONSTR_TYPE                  2017
#define PRO_E_DTMAXIS_CONSTR_REF                   2018
#define PRO_E_DTMAXIS_DIM_CONSTRAINTS              2019
#define PRO_E_DTMAXIS_DIM_CONSTRAINT               2020
#define PRO_E_DTMAXIS_DIM_CONSTR_REF               2021
#define PRO_E_DTMAXIS_DIM_CONSTR_VAL               2022
#define PRO_E_REMOVE_MATERIAL                      2023
        
#define PRO_E_AUTO_BEND_NOTES                      2024

        
#define PRO_E_RNDCH_SETS                           2101
#define PRO_E_RNDCH_SET                            2102
#define PRO_E_RNDCH_DIMENSIONAL_SCHEMA             2103
#define PRO_E_RNDCH_REFERENCE_SURFACE              2104
#define PRO_E_RNDCH_REFERENCE_EDGES                2105
#define PRO_E_RNDCH_LEG1                           2106
#define PRO_E_RNDCH_LEG2                           2107
#define PRO_E_RNDCH_LEG_TYPE                       2108
#define PRO_E_RNDCH_LEG_VALUE                      2109
#define PRO_E_RNDCH_REFERENCE_EDGE                 2110
#define PRO_E_RNDCH_REFERENCE_POINT                2111
#define PRO_E_RNDCH_ATTACH_ATTR                    2112
#define PRO_E_RNDCH_TRANSITIONS                    2113
#define PRO_E_RNDCH_TRANSITION                     2114
#define PRO_E_RNDCH_TRANS_REFERENCES               2115
#define PRO_E_RNDCH_TRANS_TYPE                     2116
#define PRO_E_RNDCH_TRANS_PATCH_RAD_OPT            2117
#define PRO_E_RNDCH_TRANS_CAP                      2118
#define PRO_E_RNDCH_CONIC_TYPE                     2119
#define PRO_E_RNDCH_CONIC_VALUE                    2120
#define PRO_E_RNDCH_REFERENCES                     2121
#define PRO_E_RNDCH_RADIUS                         2122
#define PRO_E_RNDCH_RADII                          2123
#define PRO_E_STD_CURVE_COLLECTION_APPL            2124
#define PRO_E_SECT_USE_SKETCH                      2125 /* Obsolete */

#define PRO_E_SURF_EXTEND_CHAIN_OF_EDGES           2126
#define PRO_E_SURF_EXTEND_TYPE                     2127
#define PRO_E_SURF_EXTEND_DIST_STATE               2128
#define PRO_E_SURF_EXTEND_WAY_OF_MEASURING         2129
#define PRO_E_SURF_EXTEND_REFER_PLANE              2130
#define PRO_E_SURF_EXTEND_SINGLE_DIST_VALUE        2131
#define PRO_E_SURF_EXTEND_START_COND               2132
#define PRO_E_SURF_EXTEND_END_COND                 2133

#define PRO_E_CSYS_ORIGIN_CONSTRS                  2134
#define PRO_E_CSYS_ORIGIN_CONSTR                   2135
#define PRO_E_CSYS_ORIGIN_CONSTR_REF               2136
#define PRO_E_CSYS_ORIENTMOVES                     2137
#define PRO_E_CSYS_ORIENTMOVE                      2138
/*unused: 2139, 2146 */
#define PRO_E_CSYS_ORIENTMOVE_MOVE_TYPE            2140
#define PRO_E_CSYS_ORIENTMOVE_MOVE_VAL             2141
#define PRO_E_CSYS_ORIENTSELAXIS1_REF              2142
#define PRO_E_CSYS_ORIENTSELAXIS1_OPT              2143
#define PRO_E_CSYS_ORIENTSELAXIS2_REF              2144
#define PRO_E_CSYS_ORIENTSELAXIS2_OPT              2145
#define PRO_E_CSYS_OFFSET_TYPE                     2147

#define PRO_E_DRAFT_NEUTRAL_OBJECT                 2148
#define PRO_E_DRAFT_DRAFTED_SURFACES               2149
#define PRO_E_DRAFT_CONSTANT_OR_VARIABLE           2150
#define PRO_E_DRAFT_ANGLE                          2151
#define PRO_E_DRAFT_DIRECTION_REF_OBJECT           2152

#define PRO_E_DRAFT_TWEAK_OR_INTERSEC              2153


#define PRO_E_DRAFT_SPLIT                          2154
#define PRO_E_DRAFT_SECOND_NEURAL_OBJECT           2155

#define PRO_E_DRAFT_SPLIT_SURFACE                  2156
#define PRO_E_DRAFT_SPLIT_GEOM                     PRO_E_DRAFT_SPLIT_SURFACE


#define PRO_E_DRAFT_NEED_SECOND_NEUT               2157

#define PRO_E_DRAFT_ONE_SIDE                       2158
#define PRO_E_DRAFT_DEPENDENT                      2159
#define PRO_E_DRAFT_SEC_ANGLE                      2160

#define PRO_E_DRAFT_NEURAL_OBJECT_TYPE             2161 /* FB_ADD */
#define PRO_E_DRAFT_NEUTRAL_PLANE                  2162 /* FB_ADD */
#define PRO_E_DRAFT_NEUTRAL_CURVE                  2163 /* FB_ADD */
#define PRO_E_DRAFT_SIDE_1                         2164 /* FB_ADD */
#define PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE            2165 /* FB_ADD */
#define PRO_E_DRAFT_SIDE_2                         2166 /* FB_ADD */
        
#define PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_1          2167
#define PRO_E_DRAFT_ANGLE_1                        2168
#define PRO_E_DRAFT_NEUTRAL_PLANE_1                2169
#define PRO_E_DRAFT_NEUTRAL_CURVE_1                2170
#define PRO_E_DRAFT_DEPENDENT_1                    2171
        
#define PRO_E_DRAFT_NEUTRAL_OBJECT_TYPE_2          2172
#define PRO_E_DRAFT_ANGLE_2                        2173
#define PRO_E_DRAFT_NEUTRAL_PLANE_2                2174
#define PRO_E_DRAFT_NEUTRAL_CURVE_2                2175
#define PRO_E_DRAFT_DEPENDENT_2                    2176
        
#define PRO_E_RNDCH_COMPOUND_CONIC                 2177
#define PRO_E_RNDCH_SHAPE_OPTIONS                  2178
#define PRO_E_RNDCH_REFERENCE_TYPE                 2179
#define PRO_E_RNDCH_REFERENCE_SURFACE2             2180
#define PRO_E_RNDCH_REFERENCE_EDGE1                2181
#define PRO_E_RNDCH_REFERENCE_EDGE2                2182
#define PRO_E_RNDCH_REPLACE_SURFACE                2183
        
#define PRO_E_RNDCH_RAD_CURVE                      2184
#define PRO_E_RNDCH_AUTO_BLEND                     2185
#define PRO_E_RNDCH_COMPOUND_EXT_OPTIONS           2186
#define PRO_E_RNDCH_TERM_SURFACE                   2187
#define PRO_E_RNDCH_BALL_SPINE                     2188
#define PRO_E_RNDCH_VARIABLE_RADIUS                2189
#define PRO_E_RNDCH_COMPOUND_SPINE                 2190
#define PRO_E_RNDCH_SPINE_CHAIN                    2191
#define PRO_E_RNDCH_SPINE_CURVE                    2192
#define PRO_E_RNDCH_REFERENCE_SURFACE1             2193
       
        
               
#define PRO_E_SHELL_FLIP                           2194

#define PRO_E_SEC_USE_SKETCH                       2195

#define PRO_E_RIB_SIDE_OPTS                        2196
#define PRO_E_STD_POINT_COLLECTION_APPL            2197
        
#define PRO_E_SURF_EXTEND_VAR_DIST_POINT_ARRAY     2198
#define PRO_E_SURF_EXTEND_POINT_DIST_COMPOUND      2199
#define PRO_E_SURF_EXTEND_REF_POINT                2200
#define PRO_E_SURF_EXTEND_DIST_TYPE                2201
#define PRO_E_SURF_EXTEND_REF_EDGE_1               2202
#define PRO_E_SURF_EXTEND_DIST_VALUE_1             2203
#define PRO_E_SURF_EXTEND_DIST_1_COMPOUND          2204
#define PRO_E_SURF_EXTEND_REF_EDGE_2               2205
#define PRO_E_SURF_EXTEND_DIST_VALUE_2             2206
#define PRO_E_SURF_EXTEND_DIST_2_COMPOUND          2207
#define PRO_E_SURF_EXTEND_START_REF_EDGE           2208
#define PRO_E_SURF_EXTEND_END_REF_EDGE             2209
#define PRO_E_SURF_EXTEND_START_COND_COMPOUND      2210
#define PRO_E_SURF_EXTEND_END_COND_COMPOUND        2211
#define PRO_E_SURF_EXTEND_FLIP                     2212

#define PRO_E_STD_SURF_COLLECTION_APPL             2213

#define PRO_E_SRF_COPY_TYPE                        2214
#define PRO_E_STD_SEGM_COLLECTION_APPL             2215
 
#define PRO_E_HULL_WELD_FILLET_PARAMS              3000
#define PRO_E_HULL_WELD_OFFSET                     3001
#define PRO_E_HULL_WELD_SPACE                      3002
#define PRO_E_HULL_WELD_LENGTH                     3003
#define PRO_E_HULL_WELD_LEG_1                      3004
#define PRO_E_HULL_WELD_LEG_2                      3005
#define PRO_E_HULL_WELD_BUTT_PARAMS                3006
#define PRO_E_HULL_WELD_GAP                        3007
#define PRO_E_HULL_WELD_CAP_TOP                    3008
#define PRO_E_HULL_WELD_CAP_BOT                    3009
#define PRO_E_WIND_OFFSET                          3010
#define PRO_E_WIND_INSIDE_LOOPS                    3011

#define PRO_E_MIRRGEOM_SELECT_PLAIN                3012

#define PRO_E_AREA_OFS_TYPE                        3013
#define PRO_E_AREA_OFS_AREA_TYPE                   3014
#define PRO_E_AREA_OFS_SURF                        3015
#define PRO_E_AREA_OFS_PROJ_TYPE                   3016
#define PRO_E_AREA_OFS_USING_SLD_OR_QLT            3017
#define PRO_E_AREA_OFS_TRANS_DIR_REF               3018
#define PRO_E_AREA_OFS_CSYS_AXIS                   3019
#define PRO_E_AREA_OFS_EXCL_LOOP                   3020
#define PRO_E_AREA_OFS_PROF_TYPE                   3021
#define PRO_E_AREA_OFS_BEVEL_ANGLE                 3022

#define PRO_E_PATCH_QUILT                          3023
#define PRO_E_PATCH_TYPE                           3024
#define PRO_E_PATCH_MATERIAL_SIDE                  3025

#define PRO_E_SRF_TR_SURF_SELECTION                3026
#define PRO_E_SRF_TR_MOVE_TYPE                     3027
#define PRO_E_SRF_TR_VAL_ELEM                      3028

#define PRO_E_DPOINT_POINTS_ARRAY                  3029
#define PRO_E_DPOINT_POINT                         3030
#define PRO_E_DPOINT_POINT_NAME                    3031
#define PRO_E_DPOINT_PLA_CONSTRAINTS               3032
#define PRO_E_DPOINT_PLA_CONSTRAINT                3033
#define PRO_E_DPOINT_PLA_CONSTR_REF                3034
#define PRO_E_DPOINT_PLA_CONSTR_TYPE               3035
#define PRO_E_DPOINT_PLA_CONSTR_VAL                3036
#define PRO_E_DPOINT_DIM_CONSTRAINTS               3037
#define PRO_E_DPOINT_DIM_CONSTRAINT                3038
#define PRO_E_DPOINT_DIM_CONSTR_REF                3039
#define PRO_E_DPOINT_DIM_CONSTR_TYPE               3040
#define PRO_E_DPOINT_DIM_CONSTR_VAL                3041
#define PRO_E_RNDCH_ATTACH_TYPE                    3042

#define PRO_E_PATTERN_METHOD                       3043
#define PRO_E_PATTERN_SECTION                      3044
#define PRO_E_PATTERN_TEMPLATE                     3045
#define PRO_E_PATTERN_SPACING                      3046
#define PRO_E_PATTERN_ALLOWANCE                    3047
#define PRO_E_PATTERN_SKIP_ID                      3048
#define PRO_E_PATTERN_RADIUS_INC                   3049

#define PRO_E_CSYS_ORIENT_BY_METHOD                3050
#define PRO_E_CSYS_TYPE_MECH                       3051
#define PRO_E_CSYS_ORIENTSELAXIS1_FLIP             3052
#define PRO_E_CSYS_ORIENTSELAXIS2_FLIP             3053
#define PRO_E_CSYS_NORMAL_TO_SCREEN                3054
#define PRO_E_CTRL_PTS_SETS                        3055
#define PRO_E_CTRL_PTS_SETHOLDER                   3056
#define PRO_E_CTRL_PTS_REFHOLDER                   3057
#define PRO_E_STD_CHAIN_HOLDER                     3058

#define PRO_E_OFFSET_FEATURE_TYPE                  3059
#define PRO_E_DRVD_ATTRIBUTES                      3060
#define PRO_E_DRVD_DETAIL_ITEM                     3061
        
#define PRO_E_CRV_IP_REF_TYPE                      3062
#define PRO_E_CRV_IP_REF1                          3063
#define PRO_E_CRV_IP_REF2                          3064
#define PRO_E_CRV_IP_COMP_SEC1                     3065
#define PRO_E_CRV_IP_COMP_SEC2                     3066
#define PRO_E_CRV_IP_REF_SEL1_TYPE                 3067
#define PRO_E_CRV_IP_REF_SEL2_TYPE                 3068
#define PRO_E_CRV_IP_COMP_REF1                     3069
#define PRO_E_CRV_IP_COMP_REF2                     3070
#define PRO_E_CRV_TRIM_SPLIT_SIDE                  3071
#define PRO_E_CRV_TRIM_SPLIT_CURVE                 3072
#define PRO_E_CRV_TRIM_DIVIDER                     3073
#define PRO_E_CRV_WRAP_SRF_TYPE                    3074
#define PRO_E_CRV_WRAP_SRF                         3075
#define PRO_E_CRV_COMPST_CRV_TYPE                  3076
#define PRO_E_CRV_PROJ_TYPE                        3077
#define PRO_E_CRV_PROJCRV_TYPE                     3078
#define PRO_E_CRV_PROJ_SKETCH_DIR_TYPE             3079
#define PRO_E_CRV_PROJ_SEL_DIR_TYPE                3080
#define PRO_E_CRV_OFFS_FEAT_TYPE                   3081
#define PRO_E_CRV_OFFS_CRV_REF                     3082
#define PRO_E_CRV_OFFS_SRF_REF                     3083
#define PRO_E_CRV_OFFS_DIR_FLIP                    3084
#define PRO_E_CRV_OFFS_GRAPH_REF                   3085
#define PRO_E_CRV_OFFS_ST_END                      3086
#define PRO_E_SURF_TRIM_TYPE                       3087
#define PRO_E_PRIMARY_QLTSIDE                      3088
#define PRO_E_THIN_QLT_SIDE                        3089
#define PRO_E_THIN_TRIM_OPT                        3090
#define PRO_E_KEEP_TRIM_SURF_OPT                   3091

#define PRO_E_THICKEN_TYPE                         3092

#define PRO_E_RNDCH_TRANS_SPHERE_RADIUS            3093
#define PRO_E_RNDCH_TRANS_LEG1_VALUE               3094
#define PRO_E_RNDCH_TRANS_LEG2_VALUE               3095
#define PRO_E_RNDCH_TRANS_LEG3_VALUE               3096
#define PRO_E_RNDCH_TRANS_SPHERE_DATA              3097
#define PRO_E_RNDCH_TRANS_PATCH_REF_SURF           3098
#define PRO_E_RNDCH_TRANS_ARC_RADIUS               3099
#define PRO_E_RNDCH_TRANS_PATCH_DATA               3100
#define PRO_E_RNDCH_TRANS_STOP_DATA                3101
#define PRO_E_RNDCH_TRANS_STOP_CAP                 3102
#define PRO_E_RNDCH_TRANS_STOP_REF_TYPE            3103
#define PRO_E_RNDCH_TRANS_STOP_REFERENCE           3104
#define PRO_E_RNDCH_TRANS_RADIUS_OPTIONS           3105
#define PRO_E_RNDCH_TRANS_LEG1_OPTIONS             3106
#define PRO_E_RNDCH_TRANS_LEG2_OPTIONS             3107
#define PRO_E_RNDCH_TRANS_LEG3_OPTIONS             3108

#define PRO_E_RIB_SECTION_COMP                     3109

#define PRO_E_HLE_ADD_EXIT_CSINK                   3110
#define PRO_E_HLE_EXIT_CSINKDIAM                   3111
#define PRO_E_HLE_EXIT_CSINKANGLE                  3112

#define PRO_E_DPOINT_OFST_CSYS_TYPE                3113
#define PRO_E_DPOINT_OFST_CSYS_REF                 3114
#define PRO_E_DPOINT_OFST_CSYS_WITH_DIMS           3115
#define PRO_E_DPOINT_OFST_CSYS_PNT_NAME            3116
#define PRO_E_DPOINT_OFST_CSYS_DIR1_VAL            3117
#define PRO_E_DPOINT_OFST_CSYS_DIR2_VAL            3118
#define PRO_E_DPOINT_OFST_CSYS_DIR3_VAL            3119
#define PRO_E_DPOINT_OFST_CSYS_PNT                 3120
#define PRO_E_DPOINT_OFST_CSYS_PNTS_ARRAY          3121
#define PRO_E_DPOINT_FIELD_REF                     3122

#define PRO_E_DTMPLN_FLIP_DIR                      3123
        
#define PRO_E_GENPAT_TYPE                          3124
#define PRO_E_GENPAT_DIM                           3125
#define PRO_E_GENPAT_TABLE                         3126
#define PRO_E_GENPAT_REF                           3127
#define PRO_E_GENPAT_FILL                          3128
#define PRO_E_GENPAT_DIR                           3129
#define PRO_E_GENPAT_AXIS                          3130
#define PRO_E_GENPAT_REGEN_METHOD                  3131
#define PRO_E_GENPAT_REF_TYPE                      3132

#define PRO_E_GENPAT_DIM_FIRST_DIR                 3133
#define PRO_E_GENPAT_DIM_FIRST_DIR_NUM_INST        3134
#define PRO_E_GENPAT_DIM_SECOND_DIR                3135
#define PRO_E_GENPAT_DIM_SECOND_DIR_NUM_INST       3136
#define PRO_E_GENPAT_DIM_DIR_COMPOUND              3137
#define PRO_E_GENPAT_DIR_DIMENSION                 3138
#define PRO_E_GENPAT_DIR_VAR_TYPE                  3139
#define PRO_E_GENPAT_DIR_VAR_VALUE                 3140
#define PRO_E_GENPAT_RELATION_EDIT                 3141

#define PRO_E_GENPAT_FILL_SKETCH                   3142
#define PRO_E_GENPAT_FILL_TEMPLATE_TYPE            3143
#define PRO_E_GENPAT_FILL_SPACING                  3144
#define PRO_E_GENPAT_FILL_BORDERING                3145
#define PRO_E_GENPAT_FILL_RADIUS_INC               3146

#define PRO_E_GENPAT_TABLE_DIMS                    3147
#define PRO_E_GENPAT_TABLE_DIM_ENTRY               3148
#define PRO_E_GENPAT_TABLE_DIM                     3149
#define PRO_E_GENPAT_TABLE_LIST                    3150
#define PRO_E_GENPAT_TABLE_ENTRY                   3151
#define PRO_E_GENPAT_TABLE_NAME                    3152
#define PRO_E_GENPAT_TABLE_EDIT                    3153
#define PRO_E_GENPAT_TABLE_READ                    3154
#define PRO_E_GENPAT_TABLE_WRITE                   3155
#define PRO_E_GENPAT_TABLE_SET_ACTIVE              3156

#define PRO_E_DRAFT_ANGLES                         3157
#define PRO_E_DRAFT_ANG_PNT                        3158
        
#define PRO_E_DRVD_VAR_PARAMS                      3159
#define PRO_E_RNDCH_AMBIGUITY                      3160

#define PRO_E_MIRROR_REF_ITEMS                     3161
#define PRO_E_MIRROR_REF_PLANE                     3162
#define PRO_E_COPY_NO_COPY                         3163

#define PRO_E_SWEEP_PROF_COMP                      3164
#define PRO_E_SWEEP_FRAME_COMP                     3165

#define PRO_E_TANDFT_TANGENT_TO                    3166

#define PRO_E_CSYS_ORIENTSELAXIS1_REF_OPT          3167
#define PRO_E_CSYS_ORIENTSELAXIS2_REF_OPT          3168
#define PRO_E_GENPAT_FILL_ROT_ANG                  3169

#define PRO_E_BBL_APPENDIX                         3170

#define PRO_E_RNDCH_CONIC_DEP_OPT                  3171

#define PRO_E_FRM_TRAJS_APPENDIX                   3172
#define PRO_E_CRV_WRAP_FLIP                        3173
#define PRO_E_CRV_WRAP_COORD_SYS                   3174
#define PRO_E_BBL_ADD_CLOSED                       3175
  
#define PRO_E_FEAT_FORM_IS_THIN                    3176

#define PRO_E_DRAFT_INCLUDE_TANGENT                3177
#define PRO_E_DRAFT_SKETCHER                       3178
#define PRO_E_DPOINT_TYPE                          3179
#define PRO_E_SURFACE_SIDE                         3180
#define PRO_E_SURF_FLIP_NORMAL                     3181
#define PRO_E_SRF_TRANS_TYPE                       3182
#define PRO_E_CRV_PROJ_CURVES                      3183
#define PRO_E_RNDCH_CHAMFER_SHAPE                  3184
#define PRO_E_CRV_PROJ_FOLLOW_SRF_OPT              3185

#define PRO_E_POCKET_NUMBER                        3186
#define PRO_E_CUT_MOTION_SUB_TYPE                  3187
#define PRO_E_THRDMILL_THREAD_METHOD               3188
#define PRO_E_THRDMILL_CUT_STYLE                   3189
#define PRO_E_THRDMILL_PICKUP_OVERLAP              3190
#define PRO_E_THRDMILL_THREAD_OVERLAP              3191
#define PRO_E_THRDMILL_ANGULAR_OVERLAP             3192
#define PRO_E_THRDMILL_HOLESET_INFO                3193
#define PRO_E_HLE_PLC_ALIGN_OPT1                   3194
#define PRO_E_HLE_PLC_ALIGN_OPT2                   3195
#define PRO_E_MOVE_WITH_COPY                       3196
#define PRO_E_TRAJECTORY_CURVE                     3197
#define PRO_E_TRAJECTORY_CURVE_FEAT                3198

#define PRO_E_WLD_PREP_DIM_ATTACH                  3199
#define PRO_E_HOLESET_TIP_CTRL_PNT                 3200
#define PRO_E_DTMAXIS_FIT                          3201
#define PRO_E_DTMAXIS_FIT_TYPE                     3202
#define PRO_E_DTMAXIS_FIT_REF                      3203
#define PRO_E_DTMAXIS_FIT_LEN                      3204
#define PRO_E_NCSEQ_ADAPTER                        3205

#define PRO_E_SHRINK_FORMULA                       3207
#define PRO_E_SHRINK_SEL_CSYS                      3208
#define PRO_E_SHRINK_FACTOR_X                      3209
#define PRO_E_SHRINK_FACTOR_Y                      3210
#define PRO_E_SHRINK_FACTOR_Z                      3211
#define PRO_E_SHRINK_FORWARD                       3212
#define PRO_E_SHRINK_BY_DIM_SHRINK_FORMULA         3213
#define PRO_E_SHRINK_ALL_DIM                       3214
#define PRO_E_SHRINK_DIMENSIONS                    3215
#define PRO_E_SHRINK_BY_DIM_AFTER_BEFORE           3216

#define PRO_E_FEAT_FORM_ALWAYS_THIN                3217
#define PRO_E_SRF_TRIM_TYPE                        3218

#define PRO_E_ANNOT_ELEM_NAME                      3219
#define PRO_E_ANNOTATION_TYPE                      3220
#define PRO_E_ANNOTATION_ID                        3221
#define PRO_E_ANNOT_ELEM_REFERENCE_TYPE            3222 /*Obsolete*/
#define PRO_E_ANNOT_ELEM_SINGLE_REF                3223
#define PRO_E_ANNOT_ELEM_STRONG_REF_FLAG           3224
#define PRO_E_ANNOT_ELEM_REFERENCE                 3225
#define PRO_E_ANNOT_ELEM_REFERENCES                3226
#define PRO_E_ANNOTATION                           3227
#define PRO_E_ANNOT_ELEM_COPY_FLAG                 3228
#define PRO_E_ANNOT_ELEM_DEPENDENT_FLAG            3229 /*Obsolete*/
#define PRO_E_ANNOT_ELEM                           3230
#define PRO_E_ANNOTATION_REFERENCES                3231
#define PRO_E_ANNOT_ELEM_REF_INDEX                 3232 /*Obsolete*/
#define PRO_E_ANNOT_ELEM_PUBLISH_REF_FLAG          3233
#define PRO_E_ANNOT_ELEM_ARRAY                     3234
#define PRO_E_CRV_WRAP_TRIM                        3235
#define PRO_E_CRV_WRAP_STAY_ON_SURF                3236
#define PRO_E_STD_HOLE_DEPTH_REF                   3237
#define PRO_E_TRIM_SILH_PLANE                      3238
#define PRO_E_GROUP_COPY_REF_ITEMS                 3239
#define PRO_E_GROUP_MIRROR_REF_PLANE               3240
#define PRO_E_GROUP_COPY_TECHNIQUE                 3241
#define PRO_E_MOVE_FEATS_MOVE_VALUE                3242
#define PRO_E_MOVE_FEATS_MOVE_TYPE                 3243
#define PRO_E_ANNOTATION_CONSUMED                  3244
#define PRO_E_ANNOT_ELEM_APPL                      3245
#define PRO_E_ANNOT_ELEM_APPL_TYPE                 3246
#define PRO_E_ANNOT_ELEM_APPL_DATA                 3247
#define PRO_E_ANNOT_ELEM_APPL_CONSUMED             3248
#define PRO_E_ANNOT_ELEM_APPL_REFERENCES           3249
#define PRO_E_ANNOT_ELEM_DESC_REF                  3250
#define PRO_E_ANNOT_ELEM_ARRAY_NO_ACCESS           3251

#define PRO_E_DIRECTION_COMPOUND                   3252
#define PRO_E_DIRECTION_REFERENCE                  3253
#define PRO_E_DIRECTION_FLIP                       3254

#define PRO_E_SMT_FLANGE_DEPTH                     3255
#define PRO_E_SMT_FLANGE_SIDE_2_DEPTH              3256
#define PRO_E_SMT_FLANGE_SIDE_1_DEPTH              3257
#define PRO_E_SMT_FLANGE_DEPTH_TYPE                3258
#define PRO_E_SMT_FLANGE_DEPTH_OFFSET              3259
#define PRO_E_SMT_FLANGE_DEPTH_REF                 3260
#define PRO_E_SMT_WALL_THICKNESS_FLIP              3261
#define PRO_E_SMT_WALL_SHARPS_TO_BENDS             3262
#define PRO_E_SMT_FLANGE_SEC_FLIP                  3263

#define PRO_E_SMT_DEV_LEN_SOURCE                   3264
#define PRO_E_SMT_DEV_LEN_Y_FACTOR_VALUE           3265
#define PRO_E_SMT_DEV_LEN_Y_FACTOR_TYPE            3266
#define PRO_E_SMT_DEV_LEN_Y_FACTOR                 3267
#define PRO_E_SMT_DEV_LEN_BEND_TABLE               3268
#define PRO_E_SMT_DEV_LEN_CALCULATION              3269
#define PRO_E_SMT_FILLETS_SIDE                     3270
#define PRO_E_SMT_FILLETS_VALUE                    3271
#define PRO_E_SMT_FILLETS                          3272
#define PRO_E_GENPAT_AXIS_REF                      3273
#define PRO_E_GENPAT_DIR1_INC                      3274
#define PRO_E_GENPAT_DIR2_INC                      3275
#define PRO_E_GENPAT_AXIS1_INC                     3276
#define PRO_E_GENPAT_AXIS2_INC                     3277
#define PRO_E_SMT_FILLETS_USE_RAD                  3278
#define PRO_E_REVOLVE_AXIS                         3279
#define PRO_E_REVOLVE_AXIS_OPT                     3280
#define PRO_E_DTMPLN_FIT_OUTLINE                   3281
#define PRO_E_AREA_OFS_EXCL                        3282
#define PRO_E_WIND_GEOMETRY_TYPE                   3283

#define PRO_E_SMT_FLAT_WALL_ANGLE_TYPE             3284
#define PRO_E_SMT_FLAT_WALL_ANGLE_VAL              3285
#define PRO_E_SMT_FLAT_WALL_ANGLE_FLIP             3286 
#define PRO_E_SMT_FLAT_WALL_ANGLE                  3287
#define PRO_E_SMT_FLAT_WALL_ATT_EDGE               3288

#define PRO_E_SMT_FLANGE_TYPE                      3289
#define PRO_E_DSHARE_COPY_ANNOT                    3290

#define PRO_E_GENPAT_DIR1                          3291
#define PRO_E_GENPAT_DIR2                          3292

#define PRO_E_MERGED_REF_NCSEQ_ARR                 3293
#define PRO_E_NCSEQ_PREREQUISITE_ARR               3294
#define PRO_E_PARENT_HOLESET_ID                    3295
#define PRO_E_PARENT_FEAT_ID                       3296

#define PRO_E_GENPAT_AXIS_ANG_WHOLE                3297

#define PRO_E_SMT_FLANGE_TRAJ_CRV_NORM             3298

#define PRO_E_MOVE_FEATS_TRF_ARR                   3299
#define PRO_E_MOVE_FEATS_TRF                       3300
#define PRO_E_MOVE_GEOM_TRF_ARR                    3301
#define PRO_E_MOVE_GEOM_TRF                        3302

#define PRO_E_SMT_WALL_TYPE                        3303

#define PRO_E_ASSEM_SETUP_TYPE                     3304
#define PRO_E_DRAFT_EXTEND                         3305

#define PRO_E_DTMREF_INTENT_CHAIN                  3306

#define PRO_E_DIR_PAT_DIR1_FLIP                    3307
#define PRO_E_DIR_PAT_DIR2_FLIP                    3308
#define PRO_E_AXIS_PAT_DIR1_FLIP                   3309

#define PRO_E_SMT_WALL_HEIGHT                      3310
#define PRO_E_SMT_WALL_HEIGHT_TYPE                 3311
#define PRO_E_SMT_WALL_HEIGHT_VALUE                3312
#define PRO_E_SWPBLN_TANG_OPTION                   3313
#define PRO_E_SWPBLN_TANG_COND                     3314
#define PRO_E_SWPBLN_END_TNC                       3315
#define PRO_E_SWPBLN_CONNECT_SURF_CHAIN            3316

#define PRO_E_AXIS_PAT_DIR2_FLIP                   3318
#define PRO_E_GANG_DRILL_LEADER                    3319
#define PRO_E_MFG_APPL_TYPE                        3320
#define PRO_E_MILL_VOL_CUT_ORDER                   3321

#define PRO_E_HOLESET_CUSTOM_PLATES                3322
#define PRO_E_HOLESET_CUSTOM_PLATE                 3323
#define PRO_E_HOLESET_CUSTOM_REFERENCE             3324
#define PRO_E_HOLESET_CUSTOM_SURFACE               3325
#define PRO_E_HOLESET_CUSTOM_REF_ID                3326
#define PRO_E_HOLESET_CUSTOM_Z_OFFSET              3327
#define PRO_E_HOLESET_CUSTOM_VALUE                 3328


#define PRO_E_SMT_CUT_NORMAL_DIR                   3329
#define PRO_E_IS_SMT_CUT                           3330

#define PRO_E_IS_UNATTACHED_WALL                   3331
#define PRO_E_STD_SMT_THICKNESS                    3332
#define PRO_E_STD_SMT_SWAP_DRV_SIDE                3333

#define PRO_E_COMPONENT_SETS                       3340
#define PRO_E_COMPONENT_SET                        3341
#define PRO_E_COMPONENT_SET_ID                     3342
#define PRO_E_COMPONENT_SET_TYPE                   3343
#define PRO_E_COMPONENT_SET_NAME                   3344
#define PRO_E_COMPONENT_CONSTR_SET_ID              3345

#define PRO_E_COMP_INTERFACE_NAME                  3350

#define PRO_E_COMP_INTERFACE_CONSTRAINTS           3360
#define PRO_E_COMP_INTERFACE_CONSTRAINT            3361
#define PRO_E_COMP_INTERFACE_CONSTR_TYPE           3362
#define PRO_E_COMP_INTERFACE_CONSTR_REF            3363
#define PRO_E_COMP_INTERFACE_CONSTR_REF_OFFSET     3364
#define PRO_E_COMP_INTERFACE_CONSTR_SET_ID         3365
#define PRO_E_COMP_INTERFACE_CONSTR_RULE           3366
#define PRO_E_COMP_INTERFACE_CONSTR_ATTR           3367

#define PRO_E_COMPONENT_INTERFACE_SETS             3370
#define PRO_E_COMPONENT_INTERFACE_SET              3371
#define PRO_E_COMPONENT_INTERFACE_SET_ID           3372
#define PRO_E_COMPONENT_INTERFACE_SET_TYPE         3373
#define PRO_E_COMPONENT_INTERFACE_SET_NAME         3374
#define PRO_E_COMP_INTERFACE_RULE                  3380

#define PRO_E_MIRROR_PLANE                         3381
#define PRO_E_MIRROR_CUT_CONDS                     3382

#define PRO_E_STD_SEC_LOC_OPTION                   3383
#define PRO_E_STD_SEC_LOC_PARAM                    3384
#define PRO_E_SWPBLN_SEC_X_DIR                     3385

#define PRO_E_GMRG_FEAT_TYPE                       3386
#define PRO_E_GMRG_MATERIAL_OPT                    3387

#define PRO_E_DSF_REF_MDL                          3388
#define PRO_E_DSF_EXT_LOCAL_TYPE                   3389
#define PRO_E_DSF_SEL_REF_MDL                      3390
#define PRO_E_DSF_PLACEMENT                        3391
#define PRO_E_DSF_DEPENDENCY                       3392
#define PRO_E_DSF_ANNOT_CPY_ALL                    3393
#define PRO_E_DSF_DTM_SELECTION                    3394
#define PRO_E_DSF_ANNOT_DEPEND_ALL                 3395
#define PRO_E_DSF_ANNOT_AUTO_CPY_DTM               3396
#define PRO_E_DSF_ANNOT_SEL_ANNOTS                 3397
#define PRO_E_DSF_ANNOT_CPY_STATUS                 3398
#define PRO_E_DSF_ANNOT_DEPENDENCY                 3399
#define PRO_E_DSF_ANNOT_SELECTION                  3400
#define PRO_E_DSF_ANNOT_SELECTIONS                 3401
#define PRO_E_DSF_PROPAGATE_ANNOTS                 3402
#define PRO_E_DSF_DTM_FIT                          3403
#define PRO_E_DSF_DTMS_FIT                         3404

#define PRO_E_CG_LOCATION                          3405
#define PRO_E_CG_PLC_LOCAL_CSYS                    3406
#define PRO_E_CG_PLC_EXT_CSYS                      3407
#define PRO_E_CG_CSYS_PLACE                        3408
#define PRO_E_CG_PLACEMENT                         3409 
#define PRO_E_CG_PUBD_GEOM                         3410
#define PRO_E_CG_OBJS_COLL                         3411 
#define PRO_E_CG_REFS_COLL                         3412 
#define PRO_E_CG_PG_OR_REFS                        3413 
#define PRO_E_CG_SRFS_COPY                         3414 
#define PRO_E_CG_PLACE_TYPE                        3415 
#define PRO_E_GMRG_VARIED_ITEMS                    3416
#define PRO_E_GMRG_COPY_DATUMS                     3417
#define PRO_E_CG_REFS_TYPE                         3418 
#define PRO_E_COMPONENT_SET_FLIP                   3419

#define PRO_E_COMPONENT_JAS_ZERO_TYPE              3420
#define PRO_E_COMPONENT_JAS_ORANGE_REF             3421
#define PRO_E_COMPONENT_JAS_GREEN_REF              3422
#define PRO_E_COMPONENT_JAS_REFS                   3424
#define PRO_E_COMPONENT_JAS_REGEN_VALUE_FLAG       3425
#define PRO_E_COMPONENT_JAS_REGEN_VALUE            3426
#define PRO_E_COMPONENT_JAS_REGEN_VALUE_GROUP      3427
#define PRO_E_COMPONENT_JAS_MIN_LIMIT_FLAG         3428
#define PRO_E_COMPONENT_JAS_MIN_LIMIT_VAL          3429 
#define PRO_E_COMPONENT_JAS_MIN_LIMIT              3430
#define PRO_E_COMPONENT_JAS_MAX_LIMIT_FLAG         3431
#define PRO_E_COMPONENT_JAS_MAX_LIMIT_VAL          3432
#define PRO_E_COMPONENT_JAS_MAX_LIMIT              3433
#define PRO_E_COMPONENT_JAS_RESTITUTION_FLAG       3434
#define PRO_E_COMPONENT_JAS_RESTITUTION_COEF       3435
#define PRO_E_COMPONENT_JAS_RESTITUTION            3436
#define PRO_E_COMPONENT_JAS_CONE_FLIP_FLAG         3437
#define PRO_E_COMPONENT_JAS_FRICTION_FLAG          3438 
#define PRO_E_COMPONENT_JAS_STATIC_FRIC_COEF       3439 
#define PRO_E_COMPONENT_JAS_KINEM_FRIC_COEF        3440 
#define PRO_E_COMPONENT_JAS_RADIUS_VALUE           3441  
#define PRO_E_COMPONENT_JAS_FRICTION               3442 
#define PRO_E_COMPONENT_JAS_SET                    3443 
#define PRO_E_COMPONENT_JAS_SETS                   3444

#define PRO_E_DSF_NOTIFY_UPDATE                    3445
#define PRO_E_DSF_UPDATE_GEOMETRY                  3446

#define PRO_E_SW_OPTIONS                           3448
#define PRO_E_SW_QUALITY                           3449
#define PRO_E_SW_FILL_HOLES                        3450
#define PRO_E_SW_COLLECT_QUILTS                    3451

#define PRO_E_SW_SKIP_SURF_SIZE                    3453
#define PRO_E_SW_COLLECT_ORDER                     3454
#define PRO_E_SW_COMP_SUBSET                       3455
#define PRO_E_SW_COMPONENT                         3456
#define PRO_E_SW_INCLUDE_COMP                      3457
#define PRO_E_SW_SEL_COMPONENT                     3458
#define PRO_E_SW_REFS_COLL                         3459 

#define PRO_E_SHELL_LACE_BNDRY                     3460

#define PRO_E_SMT_CORNERS_ARR                      3461
#define PRO_E_SMT_CORNER                           3462
#define PRO_E_SMT_CORNER_RELIEF                    3463
#define PRO_E_SMT_CORNER_RELIEF_TYPE               3464
#define PRO_E_SMT_CORNER_RELIEF_WIDTH              3465
#define PRO_E_SMT_CORNER_RELIEF_WIDTH_TYPE         3466
#define PRO_E_SMT_CORNER_RELIEF_WIDTH_VAL          3467
#define PRO_E_SMT_CORNER_RELIEF_DEPTH              3468
#define PRO_E_SMT_CORNER_RELIEF_DEPTH_TYPE         3469
#define PRO_E_SMT_CORNER_RELIEF_DEPTH_VAL          3470

#define PRO_E_SMT_EDGE_RIP                         3471
#define PRO_E_SMT_EDGE_RIP_TYPE                    3472
#define PRO_E_SMT_EDGE_RIP_DIM_1                   3473
#define PRO_E_SMT_EDGE_RIP_DIM_1_TYPE              3474
#define PRO_E_SMT_EDGE_RIP_DIM_1_VAL               3475
#define PRO_E_SMT_EDGE_RIP_DIM_2                   3476
#define PRO_E_SMT_EDGE_RIP_DIM_2_TYPE              3477
#define PRO_E_SMT_EDGE_RIP_DIM_2_VAL               3478
#define PRO_E_SMT_EDGE_RIP_FLIP                    3479
#define PRO_E_SMT_EDGE_RIP_ADD_GAP                 3480

#define PRO_E_SMT_MTR_CUTS                         3481
#define PRO_E_SMT_MTR_CUTS_WIDTH                   3482
#define PRO_E_SMT_MTR_CUTS_WIDTH_TYPE              3483
#define PRO_E_SMT_MTR_CUTS_WIDTH_VAL               3484
#define PRO_E_SMT_MTR_CUTS_OFFSET                  3485
#define PRO_E_SMT_MTR_CUTS_OFFSET_TYPE             3486
#define PRO_E_SMT_MTR_CUTS_OFFSET_VAL              3487
#define PRO_E_SMT_MTR_CUTS_ADD                     3488

#define PRO_E_CG_FEAT_SUB_TYPE                     3489

#define PRO_E_MFG_MOTIONS                          3490
#define PRO_E_TOOL_MOTIONS                         3491
#define PRO_E_TOOL_MOTION_GOTO_POINT               3492
#define PRO_E_TOOL_MOTION_GO_DELTA                 3493
#define PRO_E_TOOL_MOTION_GO_RETRACT               3494
#define PRO_E_TOOL_MOTION_CL_COMMAND               3495
#define PRO_E_TOOL_MOTION_FOLLOW_CURVE             3496
#define PRO_E_TOOL_MOTION_GOTO_SURFACE             3497
#define PRO_E_TOOL_MOTION_GOTO_AXIS                3498
#define PRO_E_TOOL_MOTION_AUTOMATIC_CUT            3499
#define PRO_E_TOOL_MOTION_NORMAL_APPROACH          3500
#define PRO_E_TOOL_MOTION_TANGENT_APPROACH         3501
#define PRO_E_TOOL_MOTION_TANGENT_EXIT             3502
#define PRO_E_TOOL_MOTION_POINT                    3503
#define PRO_E_TOOL_MOTION_OFFSET                   3504
#define PRO_E_TOOL_MOTION_AXIS                     3505
#define PRO_E_TOOL_MOTION_CL_COMMAND_STR           3506
#define PRO_E_TOOL_MOTION_CURVE                    3507
#define PRO_E_TOOL_MOTION_SURFACE                  3508
#define PRO_E_TOOL_MOTION_SUB_FEAT_ID              3509
#define PRO_E_TOOL_MOTION_AXIS_MOVES               3510
#define PRO_E_TOOL_MOTION_CURVE_DIR                3511
#define PRO_E_TOOL_MOTION_NORMAL_EXIT              3512
#define PRO_E_TOOL_MOTION_SPINDLE_SENSE            3513
#define PRO_E_TOOL_MOTION_SPINDLE_MAX_RPM          3514
#define PRO_E_TOOL_MOTION_TBL_REC                  3515
#define PRO_E_TOOL_MOTION_RAMP_APPROACH            3516
#define PRO_E_TOOL_MOTION_RAMP_EXIT                3517
#define PRO_E_TOOL_MOTION_CONNECT                  3518
#define PRO_E_SMT_AUTO_EXLD_EDGE                   3519


/* MILL WINDOW */
#define PRO_E_MILLWIN_WINDOW_TYPE                  3520
#define PRO_E_MILLWIN_REF_PLANE                    3521
#define PRO_E_MILLWIN_REF_PART                     3522
#define PRO_E_MILLWIN_DEFAULT_DEPTH                3523
#define PRO_E_MILLWIN_DEPTH_COMPOUND               3524
#define PRO_E_MILLWIN_DEPTH_CSYS                   3525
#define PRO_E_MILLWIN_DEPTH_TYPE                   3526
#define PRO_E_MILLWIN_DEPTH_VALUE                  3527
#define PRO_E_MILLWIN_DEPTH_REFERENCE              3528
#define PRO_E_MILLWIN_OPTIONS_COMPOUND             3529
#define PRO_E_MILLWIN_TOOL_SIDE                    3530
#define PRO_E_MILLWIN_KEEP_INSIDE_LOOPS            3531
#define PRO_E_MILLWIN_ADJUST_GEOMETRY              3532
#define PRO_E_MILLWIN_DEFAULT_OFFSET               3533
#define PRO_E_MILLWIN_OFFSET_COMPOUND              3534
#define PRO_E_MILLWIN_OFFSET_VALUE                 3535
#define PRO_E_MILLWIN_OFFSET_DIRECTION             3536

#define PRO_E_COMPONENT_SLOT_EXTRA_CRV_REFS        3537
#define PRO_E_COMPONENT_SLOT_EXTRA_CRV_REF         3538
#define PRO_E_COMPONENT_JAS_MIN_LIMIT_REF          3539 
#define PRO_E_COMPONENT_JAS_MAX_LIMIT_REF          3540


#define PRO_E_ANNOT_DRIVING_SINGLE_REF              3560
#define PRO_E_ANNOT_DRIVING_REF                     3561
#define PRO_E_ANNOT_DRIVING_REF_ARRAY               3562
#define PRO_E_ANNOT_PROP_STATE                      3563
#define PRO_E_ANNOT_FEAT_REFERENCE_TYPE             3564
#define PRO_E_ANNOT_FEAT_REF_INDEX                  3565
#define PRO_E_FEAT_PROP_COPY_ALL                    3566
#define PRO_E_FEAT_PROP_DEP_ALL                     3567
#define PRO_E_FEAT_PROP_STATUS                      3568
#define PRO_E_ANNOT_ELEM_DIM_ORIGIN                 3569

 /* 3582-3584 are taken, see below */

#define PRO_E_COMP_PLACE_INTERFACE                 3600
#define PRO_E_COMP_PLACE_INTERFACE_TYPE            3601
#define PRO_E_COMP_PLACE_INTERFACE_COMP            3602
#define PRO_E_COMP_PLACE_INTERFACE_ASSEMS          3603
#define PRO_E_COMP_PLACE_INTERFACE_ASSEM           3604
#define PRO_E_COMP_PLACE_INTERFACE_ASSEM_REF       3605

#define PRO_E_COMPONENT_SET_MISC_ATTR              3606

#define PRO_E_SWPBLN_AREA_CNTRL                    3607
#define PRO_E_SWPBLN_AREA_ELEM                     3608
#define PRO_E_SWPBLN_AREA_LOC                      3609
#define PRO_E_SWPBLN_AREA_VAL                      3610

#define PRO_E_TURNPROF_TYPE                        3611
#define PRO_E_TURNPROF_REF_CSYS                    3612
#define PRO_E_TURNPROF_REF_FEAT                    3613
#define PRO_E_TURNPROF_REF_PART                    3614
#define PRO_E_TURNPROF_FROM_VERTEX                 3615
#define PRO_E_TURNPROF_TO_VERTEX                   3616
#define PRO_E_TURNPROF_LOOP_SIDE                   3617
#define PRO_E_TURNPROF_TOOL_SIDE                   3618
#define PRO_E_TURNPROF_MATERIAL_SIDE               3619
#define PRO_E_TURNPROF_SURFACES                    3620
#define PRO_E_TURNPROF_FROM_SURFACE                3621
#define PRO_E_TURNPROF_TO_SURFACE                  3622

#define PRO_E_SWPBLN_SECTIONS_METHOD               3623

#define PRO_E_COMPONENT_LOCATIONS                  3624
#define PRO_E_COMPONENT_LOCATION                   3625

/* ECAD Area */

#define PRO_E_ECAD_AREA_TYPE                       3626
#define PRO_E_ECAD_AREA_3D_VOLUME                  3627
#define PRO_E_ECAD_AREA_DEPTH_TYPE                 3628
#define PRO_E_ECAD_AREA_DEPTH                      3629
#define PRO_E_ECAD_AREA_DEPTH2                     3630
#define PRO_E_ECAD_AREA_XHATCH                     3631

#define PRO_E_GENPAT_CURVE                         3632
#define PRO_E_GENPAT_CRV_PNT_REF                   3633
#define PRO_E_GENPAT_CRV_SPACING                   3634
#define PRO_E_GENPAT_CRV_NUMBER                    3635
#define PRO_E_GENPAT_CRV_FLIP                      3636
#define PRO_E_GENPAT_CRV_OR_TYPE                   3637
#define PRO_E_GENPAT_CRV_PLC_TYPE                  3638

#define PRO_E_TURNPROF_ENV_TYPE                    3639
#define PRO_E_TURNPROF_ADJ_ARRAY                   3640
#define PRO_E_TURNPROF_ADJ_SEGMENT                 3641

#define PRO_E_COMP_INTERFACE_RECEIVE_TYPE          3642
#define PRO_E_COMP_INTERFACE_TYPE                  3643
#define PRO_E_COMP_INTERFACE_DEFAULT               3644
#define PRO_E_COMP_INTERFACE_DESCRIPTION           3645
#define PRO_E_LIN_HOLE_DIR_REF                     3646

#define PRO_E_RETRACT_SURFACE                      3647
#define PRO_E_RETRACT_SURFACE_TYPE                 3648
#define PRO_E_RETRACT_SURFACE_REF                  3649
#define PRO_E_RETRACT_SURFACE_ORIENT               3650
#define PRO_E_RETRACT_SURFACE_VALUE                3651

#define PRO_E_SRF_OFFS_MFG_TOOL_RAD                3652
 
#define PRO_E_AUTODRILL_CSINK_DIAM                 3653
#define PRO_E_AUTODRILL_CBORE_DIAM                 3654
#define PRO_E_AUTODRILL_THREAD_DIAM                3655
#define PRO_E_AUTODRILL_DEPTH                      3656
#define PRO_E_AUTODRILL_CBORE_HEIGHT               3657
#define PRO_E_AUTODRILL_THREAD_LENGTH              3658
#define PRO_E_AUTODRILL_CSINK_ANGLE                3659
#define PRO_E_AUTODRILL_POINT_ANGLE                3660
#define PRO_E_AUTODRILL_UPPER_TOL                  3661
#define PRO_E_AUTODRILL_LOWER_TOL                  3662
#define PRO_E_AUTODRILL_STRATEGY_NAME              3663
#define PRO_E_AUTODRILL_STRATEGY_PATH              3664
#define PRO_E_AUTODRILL_PITCH                      3665
#define PRO_E_AUTODRILL_ID                         3666
#define PRO_E_AUTODRILL_SEQ_IDX                    3667
#define PRO_E_AUTODRILL_DEPTH_BY_TABLE             3668
#define PRO_E_AUTODRILL_LOCAL_PATH                 3669
#define PRO_E_AUTODRILL_TPI                        3670
#define PRO_E_AUTODRILL_DIAM                       3671

#define PRO_E_MFG_RETRACT                          3672

#define PRO_E_BELONGS_TO_MFG_VOL                   3673

#define PRO_E_MILLWIN_SILH_CONTOUR                 3674

#define PRO_E_SPRING_DAMPER_TYPE                   3675 
#define PRO_E_SPRING_DAMPER_REF                    3676 
#define PRO_E_DMP_CVAL                             3677 


#define PRO_E_AUTOMATIC_CUT_OPTION                 3678
#define PRO_E_TOOL_MOTION_CURVE_TRAJECTORY         3679
#define PRO_E_TOOL_MOTION_SURF_TRAJECTORY          3680
#define PRO_E_TOOL_MOTION_EDGE_TRAJECTORY          3681
#define PRO_E_TRAJECTORY_FIT_EDGE                  3682
#define PRO_E_THREADMILL_DEPTH                     3683
#define PRO_E_THREADMILL_END_PLANE                 3684
#define PRO_E_OUTSIDE_THREAD_MILL                  3685

#define PRO_E_SHELL_ALT_CUT_METHOD                 3686

#define PRO_E_IS_ECAD_AREA                         3687

#define PRO_E_RNDALL_SCOPE                         3688
#define PRO_E_RNDALL_CONVEXITY                     3689
#define PRO_E_RNDALL_GEOM_SCOPE                    3690
#define PRO_E_RNDALL_QUILT                         3691
#define PRO_E_RNDALL_RADII                         3692
#define PRO_E_RNDALL_CONVEX_RAD                    3693
#define PRO_E_RNDALL_CONCAVE_RAD                   3694
#define PRO_E_RNDALL_CR_METHOD                     3695

#define PRO_E_DTMREF_DATUM_COLLECTION_APPL         3696

#define PRO_E_THREAD_DEPTH                         3697

#define PRO_E_TOOL_MOTION_LEAD_IN                  3698
#define PRO_E_TOOL_MOTION_LEAD_OUT                 3699
#define PRO_E_TOOL_MOTION_HELICAL_APPROACH         3700
#define PRO_E_TOOL_MOTION_HELICAL_EXIT             3701
#define PRO_E_TOOL_MOTION_PLUNGE                   3702
#define PRO_E_TOOL_MOTION_GOHOME                   3703
#define PRO_E_TOOL_MOTION_TLAXIS_APPROACH          3704
#define PRO_E_TOOL_MOTION_TLAXIS_EXIT              3705
#define PRO_E_TOOL_MOTION_DRL_CONNECT              3706
#define PRO_E_TOOL_MOTION_FOLLOW_CUT               3707
#define PRO_E_SPRING_U                             3708

#define PRO_E_TURNPROF_ADJ_TYPE                    3709
#define PRO_E_TURNPROF_ADJ_FROM                    3710
#define PRO_E_TURNPROF_ADJ_TO                      3711
#define PRO_E_TURNPROF_DIRECTION                   3712

#define PRO_E_DSGNTAREA_SET_APPENDIX               3713
#define PRO_E_DSGNTAREA_CREATION                   3714
#define PRO_E_DSGNTAREA_CREATION_TYPE              3715
#define PRO_E_DSGNTAREA_LIE_ON                     3716
#define PRO_E_DSGNTAREA_CREATION_FLIP              3717
#define PRO_E_DSGNTAREA_SETS                       3718
#define PRO_E_DSGNTAREA_SET                        3719
#define PRO_E_DSGNTAREA_SET_REFS                   3720

#define PRO_E_SRF_MRG_QUILT_REF                    3721
#define PRO_E_SRF_MRG_QUILT_CMPD                   3722
#define PRO_E_SRF_MRG_QUILT_ARR                    3723

#define PRO_E_RM_SURF_REF_TYPE                     3724
#define PRO_E_RM_SURF_ATTACH_TYPE                  3725
#define PRO_E_RM_SURF_SRF_REFS                     3726
#define PRO_E_RM_SURF_CRV_REFS                     3727
#define PRO_E_SW_EXCLUDE_SURF_COLL_APPL            3728 
#define PRO_E_SRF_MRG_QUILT_SIDE                   3729
#define PRO_E_SPRING_DIAMETER                      3730
#define PRO_E_SPRING_USE_DIAMETER                  3731
#define PRO_E_DTMREF_INTENT_CHAIN_FLIP             3732

#define PRO_E_RNDCH_AUTO_CONTINUE                  3733

#define PRO_E_PROJ_CRV_ONESRF_REF                  3734

#define PRO_E_STD_EXCL_CNTRS                       3735

#define PRO_E_TURNPROF_ADJ_FLIP                    3736
#define PRO_E_TURNPROF_ADJ_RAD                     3737
#define PRO_E_TURNPROF_ADJ_DIST                    3738
#define PRO_E_TURNPROF_REF_SURF                    3739
#define PRO_E_DTMREF_APPENDIX                      3740
#define PRO_E_HLE_DEPTH_DIM_TYPE                   3741
#define PRO_E_MOVE_NO_COPY                         3742

#define PRO_E_INTERCH_TAG_REFS                     3743
#define PRO_E_TOOL_MOTION_AUTO_PLUNGE              3744

#define PRO_E_INTENT_NAME_CHECK                    3745
#define PRO_E_INTENT_NAME                          3746
#define PRO_E_INTENT_INSTANCE                      3747
#define PRO_E_DTMAXIS_DIM_CONSTR_TYPE              3748
#define PRO_E_DTMAXIS_DIM_ORIENT_REF               3749

#define PRO_E_HLE_ADD_NOTE                         3750
#define PRO_E_HOLE_NOTE                            3751

#define PRO_E_CMM_SEGMENTS                         3752
#define PRO_E_TOOL_MOTION_LINKS                    3753

#define PRO_E_STD_EXCL_CNTR_SRF_REF                3754
#define PRO_E_STD_EXCL_CNTR_EDGE_REF               3755
#define PRO_E_STD_EXCL_CNTRS_ONE_CNTR              3756

#define PRO_E_DTMREF_SINGLE_OBJ			   3757
#define PRO_E_DTMREF_INTENT_COLL		   3758

#define PRO_E_IDD_RMVSRF_GAPS_SLIVERS_REFS         3759
#define PRO_E_IDD_RMVSRF_GAPS_SLIVERS              3760 

#define PRO_E_RETRACT_SURFACE_TRAVERSE             3761

#define PRO_E_LWPLN_ASSOC                          3762
#define PRO_E_LWPLN_GRID                           3763
#define PRO_E_LWPLN_TRANSFORM                      3764
#define PRO_E_LWPLN_GUIDES                         3765
#define PRO_E_LWPLN_GUIDE_COM                      3766
#define PRO_E_LWPLN_GUIDE                          3767

#define PRO_E_TOOL_MOTION_CL_COMMAND_LOC_TYPE      3768
#define PRO_E_TOOL_MOTION_CL_COMMAND_PARAM         3769
#define PRO_E_TOOL_MOTION_REF_ID                   3770
#define PRO_E_TOOL_MOTION_ID                       3771
#define PRO_E_TOOL_MOTION_UI_ID                    3772
#define PRO_E_TOOL_MOTION_REF_INDEX                3773

#define PRO_E_SMT_MTR_CUTS_KEEP_DEF_AREAS	   3774

#define PRO_E_COMPONENT_JAS_0_OFFSET_VAL           3775

#define PRO_E_SPRING_K                             3776

#define PRO_E_CHECK_SURF_COLL                      3777
#define PRO_E_ADD_REF_PARTS                        3778
#define PRO_E_USE_MILL_STK                         3779
#define PRO_E_SW_FILL_CNTRS_ARR                    3780
#define PRO_E_SW_FILL_CNTRS                        3781
#define PRO_E_SW_FILL_CNTRS_SRF_SEL                3782

#define PRO_E_RNDALL_GROUP_OPTIONS                 3783
#define PRO_E_RNDALL_DIMS_DEPENDENT                3784
#define PRO_E_RNDALL_KEEP_RELATIONS                3785

/*
#define PRO_E_WELD_STANDARD                          see below 
*/
#define PRO_E_WELD_MATERIAL                          3786 
#define PRO_E_WELD_PROCESS                           3787 
#define PRO_E_WELD_PARAMS                            3788 
/*
#define PRO_E_WELD_SYMMETRICAL                       see below 
*/
#define PRO_E_WELD_GEOM_TYPE                         3789 
#define PRO_E_WELD_LW_TRAJ_CRV_COLL                  3790 
#define PRO_E_WELD_IS_CONTACT_SURF                   3791    
#define PRO_E_WELD_SURF_SURF                          3792
#define PRO_E_WELD_XSEC_AREA                          3793
#define PRO_E_WELD_XSEC_AREA_OPT                      3794
#define PRO_E_WELD_XSEC_AREA_VAL                      3795
#define PRO_E_WELD_XSEC_AREA_REF                      3796
#define PRO_E_WELD_X_SEC_SHAPE                        3797
#define PRO_E_WELD_ANSI                               3798
#define PRO_E_WELD_L_X_L                              3799
#define PRO_E_WELD_L_X_L_LEG_OPT                      3800
#define PRO_E_WELD_L_X_L_LEG_VAL                      3801
#define PRO_E_WELD_L_X_L_LEG_REF                      3802
#define PRO_E_WELD_L1_X_L2                            3803
#define PRO_E_WELD_L1_LEG_OPT                         3804
#define PRO_E_WELD_L1_LEG_VAL                         3805
#define PRO_E_WELD_L1_LEG_REF                         3806
#define PRO_E_WELD_L2_LEG_OPT                         3807
#define PRO_E_WELD_L2_LEG_VAL                         3808
#define PRO_E_WELD_L2_LEG_REF                         3809
#define PRO_E_WELD_ISO                                3810
#define PRO_E_WELD_A                                  3811
#define PRO_E_WELD_A_LEG_OPT                          3812
#define PRO_E_WELD_A_LEG_VAL                          3813
#define PRO_E_WELD_A_LEG_REF                          3814
#define PRO_E_WELD_Z                                  3815
#define PRO_E_WELD_Z_LEG_OPT                          3816
#define PRO_E_WELD_Z_LEG_VAL                          3817
#define PRO_E_WELD_Z_LEG_REF                          3818
#define PRO_E_WELD_SURF_CRV                           3820
#define PRO_E_WELD_ANGLE                              3821
#define PRO_E_WELD_CRV_CRV                            3822
#define PRO_E_WELD_TRAJ_DIR                           3823
#define PRO_E_WELD_REF_SET_ARR                        3824
#define PRO_E_WELD_REF_SET                            3825
/*
#define PRO_E_WELD_COLLECTIONS                        see below
*/
#define PRO_E_WELD_SIDE1_CRV_COLL                     3826
#define PRO_E_WELD_SIDE1_SURF_COLL                    3827
#define PRO_E_WELD_SIDE2_CRV_COLL                     3828
#define PRO_E_WELD_SIDE2_SURF_COLL                    3829
#define PRO_E_WELD_JOINT_ARR                           3830       
#define PRO_E_WELD_JOINT_SEG                           3831                                              
/*#define PRO_E_WELD_JOINT_IDX                         3832
#define PRO_E_WELD_JOINT_SWAP_ENDS                     3833*/                                                 
/*
#define PRO_E_WELD_JOINT_IS_INCLUDED                   see below
#define PRO_E_WELD_JOINT_IS_SYM_ATTACH                 see below
*/
#define PRO_E_WELD_JOINT_START_OPT                     3834
#define PRO_E_WELD_JOINT_START_VAL                     3835
#define PRO_E_WELD_JOINT_START_REF                     3836
#define PRO_E_WELD_JOINT_END_OPT                       3837
#define PRO_E_WELD_JOINT_END_VAL                       3838
#define PRO_E_WELD_JOINT_END_REF                       3839
/*
#define PRO_E_WELD_JOINT_STATUS                        see below
*/
#define PRO_E_WELD_INTERMITTENT                       3840
/*
#define PRO_E_WELD_IS_INTER                           see below
#define PRO_E_WELD_INTER_WELD_SPACING                 see below
*/
#define PRO_E_WELD_INTER_OPTS                         3841
/*
#define PRO_E_WELD_INTER_LIN_ANG_OPT                  see below
*/
#define PRO_E_WELD_INTER_TYPE                         3842
#define PRO_E_WELD_INTER_SEG_LEN_LIN                  3843
#define PRO_E_WELD_INTER_SEG_NUM                      3845
#define PRO_E_WELD_INTER_SEG_PITCH_LIN                3846
/*
#define PRO_E_WELD_INTER_STAGGERED                    see below
*/
#define PRO_E_WELD_MATERIAL_SIDE                      3848
#define PRO_E_WELD_CONTOUR                            3849
#define PRO_E_WELD_FIELD_WELD                         3850
#define PRO_E_WELD_FINISH                             3851
/*
#define PRO_E_WELD_IDENT_LINE                         see below
#define PRO_E_WELD_IDENT_LINE_POS                     see below
#define PRO_E_WELD_OTHER_SIDE_SYMB                    see below
#define PRO_E_WELD_NEXT_LEADER_OPT                    see below
#define PRO_E_WELD_NEXT_LEADER_REF                    see below
#define PRO_E_WELD_GR_BACK                            see below
#define PRO_E_WELD_GR_BACK_TYPE                       see below
#define PRO_E_WELD_GR_BACKING                         see below
#define PRO_E_WELD_GR_BACK_CONTOUR                    see below
#define PRO_E_WELD_GR_BACK_FINISH                     see below
#define PRO_E_WELD_GR_BACK_SIZE                       see below
#define PRO_E_WELD_GR_BACK_SIZE_OPT                   see below
#define PRO_E_WELD_GR_BACK_SIZE_VAL                   see below
*/
#define PRO_E_WELD_FRST_LEG_SIMP_SEL                  3852
#define PRO_E_WELD_SEC_LEG_SIMP_SEL                   3853
#define PRO_E_WELD_INTER_SEG_PITCH_ANG                3854
#define PRO_E_WELD_INTER_SEG_LEN_ANG                  3855
#define PRO_E_WELD_TRAJ_FLIP_ENDS                     3856


#define PRO_E_WELD_COMBINE_TYPE                      3858
#define PRO_E_WELD_COMBINE_FIRST_COLL                3859
#define PRO_E_WELD_COMBINE_SECOND_COLL               3860
/*
#define PRO_E_WELD_FIX_INDEX                         see below
#define PRO_E_WELD_PLUGSLOT_SLOT_LENGTH              see below
#define PRO_E_WELD_MEASURES                          see below 
*/

#define PRO_E_SW_COLLECTION_TYPE                     3861

#define PRO_E_SURFREG_SPLITTING_OPTION               3862

#define PRO_E_BELT_PLANE                           3863
#define PRO_E_BELT_PULLEYS                         3864
#define PRO_E_BELT_PULLEY_RECORD                   3865
#define PRO_E_BELT_PULLEY_SEL                      3866
#define PRO_E_BELT_PULLEY_WRAP_SIDE                3867
#define PRO_E_BELT_PULLEY_DIAMETER                 3868
#define PRO_E_BELT_PULLEY_CONN_NUM                 3869
#define PRO_E_BELT_PULLEY_FLIP_CONN_BODIES         3870
#define PRO_E_BELT_PULLEY_NUM_WRAPS                3871
#define PRO_E_BELT_DEFINE_CUSTOM_U_LENGTH          3872
#define PRO_E_BELT_UNSTRETCHED_LENGTH              3873
#define PRO_E_BELT_THICKNESS_COEFF                 3874
#define PRO_E_BELT_STIFFNESS_COEFF                 3875

#define PRO_E_NCSEQ_HAS_TOOL_MTNS                  3877
#define PRO_E_NCSEQ_CLASSIC_STYLE                  3878

#define PRO_E_TOOL_MOTION_AREA_TURNING             3880
#define PRO_E_TOOL_MOTION_GROOVE_TURNING           3881
#define PRO_E_TOOL_MOTION_PROF_TURNING             3882
#define PRO_E_TOOL_MOTION_TURN_PROFILE             3883
#define PRO_E_TOOL_MOTION_TURN_STOCK_BOUND         3884
#define PRO_E_TOOL_MOTION_TURN_START_EXT           3885
#define PRO_E_TOOL_MOTION_TURN_END_EXT             3886

#define PRO_E_HLE_MAKE_LIGHTWT                     3887

#define PRO_E_SMT_WALL_DIM_SCHEME                  3888

#define PRO_E_FORM_PUNCH_SIDE			   3889
#define PRO_E_FORM_TOOL_CSYS			   3890
#define PRO_E_FORM_TOOL_NAME			   3891


#define PRO_E_C3D_REF1                             3892
#define PRO_E_C3D_MAT_OPTION1                      3893
#define PRO_E_C3D_MAT_NAME1                        3894
#define PRO_E_C3D_POISSON1                         3895
#define PRO_E_C3D_YOUNG1                           3896
#define PRO_E_C3D_DAMPING1                         3897
#define PRO_E_C3D_REF2                             3898
#define PRO_E_C3D_MAT_OPTION2                      3899
#define PRO_E_C3D_MAT_NAME2                        3900
#define PRO_E_C3D_POISSON2                         3901
#define PRO_E_C3D_YOUNG2                           3902
#define PRO_E_C3D_DAMPING2                         3903
#define PRO_E_C3D_FRICTION                         3904
#define PRO_E_C3D_STATIC_FRIC_COEF                 3905
#define PRO_E_C3D_KINEM_FRIC_COEF                  3906

#define PRO_E_TBEND_RADIUS                         3907
#define PRO_E_TBEND_CRV_OPTION			   3908
#define PRO_E_TBEND_TYPE_OPTION			   3909
#define PRO_E_TBEND_SOLID_OPTION                   3910
#define PRO_E_TBEND_QUILT_REF			   3911
#define PRO_E_TBEND_CRV_REF                        3912
#define PRO_E_TBEND_AXIS_REF                       3913
#define PRO_E_TBEND_PROFILE_SEC                    3914
#define PRO_E_TBEND_NORM_SEC                       3915
#define PRO_E_TBEND_SRF1                           3916
#define PRO_E_TBEND_SRF2                           3917
#define PRO_E_TBEND_SKET_OPTION                    3918

#define PRO_E_TOOL_RS_GEN_TYPE                     3919
#define PRO_E_TOOL_RS_GEN_SEL_MDL                  3920
#define PRO_E_TOOL_RS_GEN_SEL_SEGMENT              3921

/* Cabling Location */
#define PRO_E_CBL_LOCS                             3922
#define PRO_E_CBL_LOC                              3923
#define PRO_E_CBL_LOC_TYPE                         3924
#define PRO_E_CBL_LOC_PACK_TYPE                    3925
#define PRO_E_CBL_LOC_CONSTR_TYPE                  3926
#define PRO_E_CBL_LOC_CONSTR_REF                   3927
#define PRO_E_CBL_LOC_DIM_CONSTRS                  3928
#define PRO_E_CBL_LOC_DIM_CONSTR                   3929
#define PRO_E_CBL_LOC_DIM_CONSTR_REF               3930
#define PRO_E_CBL_LOC_DIM_CONSTR_VAL               3931
/* end of cabling location */

#define PRO_E_CSYS_FOLLOW_SRF_OPT                  3932

#define PRO_E_HOLESET_START			   3933
#define PRO_E_HOLESET_START_TYPE		   3934
#define PRO_E_HOLESET_START_SURFACE		   3935
#define PRO_E_HOLESET_END			   3936
#define PRO_E_HOLESET_END_TYPE			   3937
#define PRO_E_HOLESET_END_SURFACE		   3938
#define PRO_E_HOLESET_DEPTH_VALUE		   3939
#define PRO_E_HOLESET_CSINK_DIAM		   3940
#define PRO_E_HOLESET_USE_BRKOUT_DIST		   3941

#define PRO_E_HOLESET_SEL_PNTS_ON_SURFACES	   3942
#define PRO_E_HOLESET_SEL_INDIV_PNTS		   3943
#define PRO_E_HOLESET_SEL_PNTS_BY_FEATURE	   3944
#define PRO_E_HOLESET_SEL_PROJECT_SURFACES	   3945
#define PRO_E_HOLESET_SEL_UNSEL_PNTS		   3946
#define PRO_E_HOLESET_SEL_MAX_PROJECT_DIST 	   3947
#define PRO_E_HOLESET_END_MEASURE_BY	 	   3948
#define PRO_E_AUTODRILL_INFO			   3949

#define PRO_E_FORM_PUNCH_QUILT                     3950
#define PRO_E_FORM_PUNCH_MATERIAL_SIDE             3951
#define PRO_E_FORM_PUNCH_HIDE_QUILT                3952

#define PRO_E_CSYS_ONSURF_TYPE                     3953
#define PRO_E_CSYS_DIM_CONSTRS                     3954                   
#define PRO_E_CSYS_DIM_CONSTR                      3955
#define PRO_E_CSYS_DIM_CONSTR_REF                  3956
#define PRO_E_CSYS_DIM_CONSTR_VAL                  3957

#define PRO_E_SW_RES_GEOM_OPT                      3958
/*
#define PRO_E_SW_FAILED_SLD_OPT                    see below
*/

#define PRO_E_SPRING_ATTACH_POINTS                 3959
#define PRO_E_SPRING_ATTACH_REF                    3960
#define PRO_E_MACHINE_ASSEM                        3961
#define PRO_E_MACHINE_CAPABILITY                   3962
#define PRO_E_WELD_SYMMETRICAL                     3963
#define PRO_E_WELD_JOINT_IS_SYM_ATTACH              3964

#define PRO_E_GENPAT_PROJECT                       3965
#define PRO_E_GENPAT_PROJ_OPT                      3966
#define PRO_E_GENPAT_PROJ_SRF_REF                  3582
#define PRO_E_GENPAT_PROJ_OR_TYPE                  3583
#define PRO_E_GENPAT_WRAP_OPT                      3584
#define PRO_E_GENPAT_ALT_ORIG                      3967
#define PRO_E_GENPAT_ALT_ORG_OPT                   3968
#define PRO_E_GENPAT_ORG_REF                       3969
#define PRO_E_GENPAT_POINT                         3970
#define PRO_E_GENPAT_POINT_REF_TYPE                3971
#define PRO_E_GENPAT_POINT_REF                     3972 
#define PRO_E_GENPAT_OFFSET_FROM_SKET              3973


#define PRO_E_UDF_OPTION                           3980
#define PRO_E_UDF_FAMTBL_INST_NAME                 3981
#define PRO_E_UDF_SCALE                            3982
#define PRO_E_UDF_SCALE_TYPE                       3983
#define PRO_E_UDF_SCALE_VALUE                      3984
#define PRO_E_UDF_DIM_DISPLAY                      3985
#define PRO_E_UDF_DEPENDENCY                       3986
#define PRO_E_UDF_REDEF_FEATS                      3987
#define PRO_E_UDF_REDEF_FEAT                       3988
#define PRO_E_UDF_PREVIEW_STOP_FEAT                3989
#define PRO_E_UDF_PLACEMENT                        3990
#define PRO_E_UDF_REFS                             3991
#define PRO_E_UDF_REF                              3992
#define PRO_E_UDF_CSYS                             3993
#define PRO_E_UDF_VARIABLE                         3994
#define PRO_E_UDF_VAR_DIMS                         3995
#define PRO_E_UDF_VAR_DIM_VALUE                    3996
#define PRO_E_UDF_VAR_PARAMS                       3997
#define PRO_E_UDF_VAR_PARAM_VALUE                  3998
#define PRO_E_UDF_VAR_AE_ITEMS                     3999
#define PRO_E_UDF_VAR_AE_ITEM_VALUE                4000
#define PRO_E_UDF_RELATION                         4001
#define PRO_E_UDF_EXT_DIMS                         4002
#define PRO_E_UDF_EXT_DIM                          4003
#define PRO_E_UDF_EXT_PARAMS                       4004
#define PRO_E_UDF_EXT_PARAM                        4005
#define PRO_E_UDF_EXT_PARAM_SEL_OPT                4006
#define PRO_E_UDF_EXT_PARAM_SEL_IDX                4007
#define PRO_E_UDF_EXT_PARAM_NAME                   4008
#define PRO_E_UDF_EXT_PARAM_VALUE                  4009
#define PRO_E_UDF_ADJUSTMENT                       4010
#define PRO_E_UDF_ADJ_ITEMS                        4011
#define PRO_E_UDF_ADJ_ITEM_VALUE                   4012
#define PRO_E_UDF_APPLICATION                      4013
#define PRO_E_UDF_ASSOC_MDLS                       4014
#define PRO_E_UDF_ASSOC_MDL_NAME                   4015
#define PRO_E_UDF_KKB_NAME                         4016

#define PRO_E_PIPE_FOLLOW_MAIN_REF_TYPE            4017
#define PRO_E_PIPE_FOLLOW_MAIN_REF                 4018
#define PRO_E_PIPE_FOLLOW_MAIN_REF_AXIS            4019
#define PRO_E_PIPE_ROUTE_ENDS                      4020
#define PRO_E_PIPE_ROUTE_END_FIRST                 4021
#define PRO_E_PIPE_ROUTE_END_SECOND                4022
#define PRO_E_PIPE_ROUTE_END_OPT                   4023
#define PRO_E_PIPE_ROUTE_END_LENGTH                4024
#define PRO_E_PIPE_ROUTE_END_REF                   4025

#define PRO_E_DIR_PAT_DIR1_OPT                     4026
#define PRO_E_DIR_PAT_DIR2_OPT                     4027
#define PRO_E_DIR1_X_OFFSET                        4028
#define PRO_E_DIR1_Y_OFFSET                        4029
#define PRO_E_DIR1_Z_OFFSET                        4030
#define PRO_E_DIR2_X_OFFSET                        4031
#define PRO_E_DIR2_Y_OFFSET                        4032
#define PRO_E_DIR2_Z_OFFSET                        4033
#define PRO_E_DIR_PAT_CSYS1_REF                    4034
#define PRO_E_DIR_PAT_CSYS2_REF                    4035

#define PRO_E_TOOL_MOTION_TURN_START_VALUE         4036
#define PRO_E_TOOL_MOTION_TURN_START_REF           4037
#define PRO_E_TOOL_MOTION_TURN_START_ORIENT        4038
#define PRO_E_TOOL_MOTION_TURN_END_VALUE           4039
#define PRO_E_TOOL_MOTION_TURN_END_REF             4040
#define PRO_E_TOOL_MOTION_TURN_END_ORIENT          4041
#define PRO_E_TOOL_MOTION_FULL_DEPTH_CUT           4042
#define PRO_E_TOOL_MOTION_FROM_TO_DEPTH_CUT        4043
#define PRO_E_TOOL_MOTION_TO_DEPTH_CUT             4044
#define PRO_E_TOOL_MOTION_ONE_SLICE_CUT            4045

#define PRO_E_WELD_JOINT_IS_INCLUDED                4046
#define PRO_E_WELD_GR_BACK_TYPE                    4047
#define PRO_E_WELD_INTER_STAGGERED                 4048

#define PRO_E_WELD_SPOT_DEFINITION                 4050
#define PRO_E_WELD_SPOT_PLACEMENT_TYPE             4051
#define PRO_E_WELD_SPOT_POINTS                     4052
#define PRO_E_WELD_SPOT_DIR_OPTS                   4053
#define PRO_E_WELD_SPOT_NUM_WELDS                  4056
#define PRO_E_WELD_SPOT_SPACING                    4057
#define PRO_E_WELD_SPOT_DIAMETER                   4058
#define PRO_E_WELD_COMMON_OPTS                     4059
#define PRO_E_WELD_SPOT_DIM_SCHEME                 4061
#define PRO_E_WELD_SPOT_SIDE_SIGNIFICANCE          4062
#define PRO_E_WELD_SPOT_PLACEMENT                  4063
#define PRO_E_WELD_SPOT_DIM_SCHEME_TYPE            4064
#define PRO_E_STD_PIPE_LINE                        4065
#define PRO_E_WELD_SPOT_STRENGTH                   4066

#define PRO_E_WELD_SYMBOL                          4070
#define PRO_E_WELD_SYMB_NOTE                       4071


#define PRO_E_CBL_LOC_BEND_RAD                     4072
#define PRO_E_CBL_LOC_PACK_ANGLE                   4073
#define PRO_E_CBL_LOC_SEG_SHAPE                    4074

#define PRO_E_PIPE_CONNECT_END_ANGLE               4075
#define PRO_E_PIPE_CONNECT_FROM_MAIN_REF           4076
#define PRO_E_PIPE_CONNECT_TO_MAIN_REF             4077

#define PRO_E_TBEND_CHAIN_HOLDER                   4078

#define PRO_E_SPRING_FLIP_U_ANGLE                  4079

#define PRO_E_PAT_APPLICATIONS                     4080
#define PRO_E_PAT_MFG_TOOL_PATH                    4081
#define PRO_E_PAT_MFG_ORD_LEADER                   4082
#define PRO_E_PAT_MFG_ORDER_OPT                    4083
#define PRO_E_PAT_MFG_FIX_OFFSET                   4084
#define PRO_E_PAT_MFG_FIX_OFF_INIT                 4085
#define PRO_E_PAT_MFG_FIX_OFF_INCR                 4086

#define PRO_E_PLRIB_COMP_THICK                     4087
#define PRO_E_PLRIB_THICK_VAL                      4088
#define PRO_E_PLRIB_COMP_ANGLE                     4089
#define PRO_E_PLRIB_ANGLE                          4090
#define PRO_E_PLRIB_ANG_VAL                        4091
#define PRO_E_PLRIB_COMP_BOTTOM_ROUND              4092
#define PRO_E_PLRIB_BOTTOM_ROUND                   4093
#define PRO_E_PLRIB_BOTTOM_RND_VAL                 4094
#define PRO_E_PLRIB_COMP_TOP_ROUND                 4095
#define PRO_E_PLRIB_TOP_ROUND                      4096
#define PRO_E_PLRIB_ROUND_SHAPE                    4097
#define PRO_E_PLRIB_TOP_RND_VAL                    4098
#define PRO_E_PLRIB_FLIP                           4099
#define PRO_E_PLRIB_BOTTOM_SHAPE                   4100
#define PRO_E_PLRIB_EXT_ROUNDS                     4101

#define PRO_E_RNDCH_TRANS_HDL_DATA                 4102
#define PRO_E_RNDCH_TRANS_HDL_SURF                 4103
#define PRO_E_RNDCH_TRANS_HDL_SIDE_OPT             4104
#define PRO_E_RNDCH_TRANS_HDL_CONIC_OPT            4105
#define PRO_E_RNDCH_TRANS_HDL_CONIC_VAL            4106
#define PRO_E_RNDCH_TRANS_HDL_DIST1_OPT            4107
#define PRO_E_RNDCH_TRANS_HDL_DIST1_VAL            4108
#define PRO_E_RNDCH_TRANS_HDL_DIST2_OPT            4109
#define PRO_E_RNDCH_TRANS_HDL_DIST2_VAL            4110
#define PRO_E_RNDCH_TRANS_HDL_LEG1_OPT             4111
#define PRO_E_RNDCH_TRANS_HDL_LEG1_VAL             4112
#define PRO_E_RNDCH_TRANS_HDL_LEG2_OPT             4113
#define PRO_E_RNDCH_TRANS_HDL_LEG2_VAL             4114
#define PRO_E_APPR_AXIS                		   4115
#define PRO_E_EXIT_AXIS              		   4116
#define PRO_E_FIRST_SLICE_ONLY                     4117
#define PRO_E_LAST_SLICE_ONLY                      4118
#define PRO_E_WELD_COLLECTIONS                     4119
#define PRO_E_WELD_INTER_WELD_SPACING              4120
#define PRO_E_TOOL_RS_GEN_DEF_CSYS                 4121

#define PRO_E_CSYS_DIM_CONSTR_TYPE                 4122
#define PRO_E_CSYS_ORIENTSELAXIS2_ROT_OPT          4123
#define PRO_E_CSYS_ORIENTSELAXIS2_ROT              4124

#define PRO_E_PIPE_TO_POINT_MAIN_REF               4125

#define PRO_E_PAT_MFG_ORD_REVERSE                  4126
#define PRO_E_PAT_MFG_ORD_ALT_ROWS                 4127
#define PRO_E_PAT_MFG_ORD_ALT_DIR                  4128
#define PRO_E_PAT_MFG_ORD_SHARED                   4129


#define PRO_E_VPDD_PULL_DIR_REF                    4130
#define PRO_E_VPDD_PULL_DIR_FLIP                   4131
#define PRO_E_VPDD_ATTACH_OPTS                     4132
#define PRO_E_VPDD_END_SRFS_OPTS                   4133
#define PRO_E_VPDD_EXTENT_CMP                      4134
#define PRO_E_VPDD_EXT_OPTS                        4135
#define PRO_E_VPDD_EXT_LENGTH                      4136
#define PRO_E_VPDD_EXT_REF                         4137
#define PRO_E_VPDD_SETS_ARR                        4138
#define PRO_E_VPDD_SET_CMP                         4139
#define PRO_E_VPDD_HINGES_ARR                      4140
#define PRO_E_VPDD_HINGE_CMP                       4141
#define PRO_E_VPDD_SPLIT_SRFS_OPTS                 4142
#define PRO_E_VPDD_SPLIT_SRFS_REFS                 4143
#define PRO_E_VPDD_CONST_OR_VAR_OPTS               4144
#define PRO_E_VPDD_ANGLES_AND_POINTS_ARR           4145
#define PRO_E_VPDD_POINT_AND_ANGLES_CMP            4146
#define PRO_E_VPDD_ANGLES_ARR                      4147
#define PRO_E_VPDD_ONE_ANGLE_CMP                   4148
#define PRO_E_VPDD_ANG_VAL                         4149                                                    
#define PRO_E_VPDD_PULL_DIR_CMP                    4150
                                                      
#define PRO_E_CBL_LOC_DEF_TYPE                     4151
#define PRO_E_CBL_REGULAR_LOC                      4152
#define PRO_E_CBL_SPAWN_LOC                        4153
#define PRO_E_CBL_LOC_MAIN_SPAWN_REF               4154
#define PRO_E_CBL_LOC_PREV_SPAWN_REF               4155
#define PRO_E_CBL_LOC_NEXT_SPAWN_REF               4156
#define PRO_E_MFG_APPR_EXIT			   4157
#define PRO_E_STEP_APPR_EXIT                       4158
                         
#define PRO_E_TOOL_MOTION_TURN_CORNERS             4159
#define PRO_E_TOOL_MOTION_TURN_CHAMFER_CORNER      4160
#define PRO_E_TOOL_MOTION_TURN_FILLET_CORNER       4161
#define PRO_E_TOOL_MOTION_TURN_SHARP_CORNER        4162
#define PRO_E_TOOL_MOTION_TURN_PREV_ENT_ID         4163
#define PRO_E_TOOL_MOTION_TURN_NEXT_ENT_ID         4164
#define PRO_E_TOOL_MOTION_TURN_CUT_OPT_ATTRS       4165

#define PRO_E_WCELL_INPROCESS_PROBING              4166

#define PRO_E_SW_FILL_CNTRS_DISP_CRV               4167
#define PRO_E_WELD_GR_TYPE                         4168
#define PRO_E_WELD_GR_PENETRATION                  4169
#define PRO_E_WELD_GR_PENETR_OPT                   4170
#define PRO_E_WELD_GR_ROOT_PENETR                  4171
#define PRO_E_WELD_GR_WELD_SIZE                    4172
#define PRO_E_WELD_IS_TAN_PROP                     4173
#define PRO_E_WELD_GR_SHAPE                        4174
/*
#define PRO_E_WELD_GR_WIDTH                        see below
*/
#define PRO_E_WELD_GR_FACE_OFFSET                  4175
#define PRO_E_WELD_GR_ROOT_OPEN                    4176
#define PRO_E_WELD_GR_PREP_ANG                     4177
#define PRO_E_WELD_GR_PREP_DEPTH                   4178
#define PRO_E_WELD_GR_FLARE_SIZE                   4179
/*
#define PRO_E_WELD_GR_IS_EDGE_PREP_ALLOWED         see below
*/
#define PRO_E_WELD_GR_EDGE_PREP                    4180
#define PRO_E_WELD_GR_SIDE1_REF_OPT                4181
#define PRO_E_WELD_GR_SIDE2_REF_OPT                4182
#define PRO_E_WELD_GR_BACK                         4183
#define PRO_E_WELD_GR_BACKING                      4184
#define PRO_E_WELD_GR_BACK_CONTOUR                 4185
#define PRO_E_WELD_GR_BACK_FINISH                  4186

#define PRO_E_C3D_VERT_RAD                         4187

#define PRO_E_TOOL_RS_GEN_DIRECTION                4188
#define PRO_E_TOOL_RS_GEN_DIR_FLAG                 4189
#define PRO_E_TOOL_RS_GEN_ROTATE                   4190

#define PRO_E_STD_PIP_PREV_FEAT                    4191

#define PRO_E_PIPE_FOLLOW_PIPE                     4192
#define PRO_E_PIPE_FOLLOW_PIPE_FIRST_MAIN_ENTRY    4193
#define PRO_E_PIPE_FOLLOW_PIPE_SECOND_MAIN_ENTRY   4194
#define PRO_E_PIPE_FOLLOW_PIPE_MAIN_REF            4195
#define PRO_E_PIPE_FOLLOW_PIPE_MAIN_OPT            4196
#define PRO_E_PIPE_FOLLOW_PIPE_TRANS_CONSTRAINT    4197
#define PRO_E_PIPE_FOLLOW_PIPE_TRANS_REF           4198
#define PRO_E_PIPE_FOLLOW_PIPE_TRANS_LENGTH        4199   

#define PRO_E_BELT_PULLEY_DIAM_COINCIDENT          4200

#define PRO_E_WELD_PLUGSLOT_TYPE                   4201
#define PRO_E_WELD_PLUGSLOT_REFERENCES             4202
#define PRO_E_WELD_PLUGSLOT_BASE_PLANE             4203                                   
#define PRO_E_WELD_PLUGSLOT_SIDE_PLACEMENT         4204
#define PRO_E_WELD_PLUGSLOT_SIDE_PLACEMENT_TYPE    4205
#define PRO_E_WELD_PLUGSLOT_SIDE_SURFS             4206
#define PRO_E_WELD_PLUGSLOT_CONTOUR                4207
#define PRO_E_WELD_PLUGSLOT_CONTOUR_REFS           4208
#define PRO_E_WELD_PLUGSLOT_FOLLOW_PATTERN         4209
#define PRO_E_WELD_PLUGSLOT_DEPTH                  4210
#define PRO_E_WELD_PLUGSLOT_DEPTH_TYPE             4211
#define PRO_E_WELD_PLUGSLOT_DEPTH_VAL              4212
#define PRO_E_WELD_PLUGSLOT_DIAMETER               4213
#define PRO_E_WELD_PLUGSLOT_COUNTERSINK            4214

#define PRO_E_HOLESET_CUSTOM_CYCLE_PLATES          4215
#define PRO_E_HOLESET_CUSTOM_CYCLE_REFERENCES      4216
#define PRO_E_HOLESET_CUSTOM_CYCLE_REF             4217
#define PRO_E_HOLESET_CUSTOM_CYCLE_PLATE_NAME      4218
#define PRO_E_HOLESET_CUSTOM_CYCLE_REF_OPT         4219
#define PRO_E_HOLESET_CUSTOM_CYCLE_REF_SEL         4220
#define PRO_E_HOLESET_CUSTOM_CYCLE_REF_Z_OFFSET    4221
#define PRO_E_HOLESET_CUSTOM_CYCLE_VARIABLES       4222
#define PRO_E_HOLESET_CUSTOM_CYCLE_VAR             4223
#define PRO_E_HOLESET_CUSTOM_CYCLE_VAR_VALUE       4224
#define PRO_E_GMRG_SMT_TYPE			   4225
#define PRO_E_GMRG_FORM_AUTO_ROUNDS		   4226
#define PRO_E_FORM_PLACEMENT_TYPE		   4227
#define PRO_E_FORM_CSYS_PLACE	   		   4228



#define PRO_E_SMT_FILLET_INTERSECT                 4229
#define PRO_E_SMT_FILLET_QUILT                     4230
#define PRO_E_SMT_FILLET_BORDER                    4231
#define PRO_E_SMT_FILLET_SELECT                    4232
#define PRO_E_SMT_FILLET_RADIUS_VALUE              4233
#define PRO_E_SMT_FILLET_RADIUS_SIDE               4234
#define PRO_E_SMT_FILLET_RADIUS_USEFLAG            4235


#define PRO_E_WELD_LW_AUTO                         4236

#define PRO_E_SRF_OFFSET_ATTACH_APPROX_SRF         4237

#define PRO_E_HOLESET_ORIENT_REF                   4238

#define PRO_E_MFG_COMBINED_SURFACES                4239
#define PRO_E_STEP_COMBINED_SURFACES               4240

#define PRO_E_DRILL_MODE			   4241

#define PRO_E_VPDD_HINGE_FLIP                      4242

#define PRO_E_PIPE_FOLLOW_PIPE_STRATEGY            4243

#define PRO_E_CG_SOLIDIFY                          4244 


#define PRO_E_HOLESET_ORIENT_TYPE                  4245


#define PRO_E_WELD_IS_INTER                        4246
#define PRO_E_WELD_STANDARD                        4247 

#define PRO_E_GEOMPAT_SOLIDIFY_OPT                 4248


#define PRO_E_CBL_MULTILOC_SEGS                    4250
#define PRO_E_CBL_MULTILOC_SEG                     4251
#define PRO_E_CBL_MULTILOC_CABLE_ID                4252
#define PRO_E_CBL_MULTILOC_SEG_DATA                4253
#define PRO_E_CBL_LOCATION_FEATURE_ARRAY           4254
#define PRO_E_CBL_LOCATION_FEATURE                 4255
#define PRO_E_CBL_RS_FEAT_GEN_TOOL_MODE            4256
#define PRO_E_CBL_LOCATION_SEG_SEL                 4257
#define PRO_E_WELD_GR_WIDTH                        4258
#define PRO_E_WELD_GR_IS_EDGE_PREP_ALLOWED         4259

#define PRO_E_GENPAT_TABLE_INSTANCES               4260
#define PRO_E_GENPAT_TABLE_INSTANCE                4261
#define PRO_E_GENPAT_TABLE_INSTANCE_INDEX          4262
#define PRO_E_GENPAT_TABLE_INSTANCE_DIMS           4263
#define PRO_E_GENPAT_TABLE_INSTANCE_DIM_VALUE      4264


#define PRO_E_PIPE_CONNECT_DIMS_SCHEME             4265

#define PRO_E_CBL_NETWORK_SEG                      4266
#define PRO_E_CBL_NETWORK_SEGS_ARRAY               4267

#define PRO_E_SW_FAILED_SLD_OPT                    4268

#define PRO_E_TOOL_RS_GEN_PORT_SEL                 4269

#define PRO_E_WELD_JOINT_STATUS                    4270
#define PRO_E_MACH_SURFS                           4271
#define PRO_E_MACH_SCALLOP_SURFS                   4272
#define PRO_E_MACH_SURF_REF                        4273
#define PRO_E_MACH_SURF_REF_TYPE                   4274
#define PRO_E_MACH_SURF_PREV_STEP                  4275
#define PRO_E_MILL_WINDOW                          4276
#define PRO_E_MILL_SRF_FLIP                        4277
#define PRO_E_NC_SRF_SIDE_ARR                      4278
#define PRO_E_NC_SRF_SIDE                          4279
#define PRO_E_NC_SRF_SIDE_REF                      4280
#define PRO_E_NC_SRF_SIDE_VAL                      4281
#define PRO_E_MFG_MACH_SURFS                       4282 
#define PRO_E_MFG_MACH_SCALLOP_SURFS               4283
#define PRO_E_MACH_SRF_FLIP                        4284
#define PRO_E_MACH_SURF_COMP                       4285
#define PRO_E_MACH_SURF_OPT                        4286

/* D3Elem elements */
#define PRO_E_D3ELEM_SETS                          4300
#define PRO_E_D3ELEM_SET                           4301
#define PRO_E_D3ELEM_PLACEMENT_REFERENCE           4302
#define PRO_E_D3ELEM_ORIENTATION_REFERENCE         4303
#define PRO_E_D3ELEM_MOVES                         4306
#define PRO_E_D3ELEM_MOVE                          4307
#define PRO_E_D3ELEM_MOVE_TYPE                     4308
#define PRO_E_D3ELEM_MOVE_VALUE                    4309

/* FlexMove feature */
#define PRO_E_FLEXMOVE_EXCLUDED_GEOMETRY           4310

#define PRO_E_WELD_INTER_LIN_ANG_OPT               4311
#define PRO_E_CBL_DEFINED_CACHE                    4312
#define PRO_E_WELD_MEASURES                        4313
#define PRO_E_WELD_FIX_INDEX                       4314
#define PRO_E_WELD_PLUGSLOT_SLOT_LENGTH            4315

/* Curve from Equation feature */
#define PRO_E_CRV_FR_EQ_REF_CSYS                   4316
#define PRO_E_CRV_FR_EQ_CSYS_TYPE                  4317
#define PRO_E_CRV_FR_EQ_PARAM_MIN                  4318
#define PRO_E_CRV_FR_EQ_PARAM_MAX                  4319

/* MFG features */
#define PRO_E_CUTLINE_TP_OPTIONS                   4320
#define PRO_E_CUTLINE_TP_METHOD_OPT                4321
#define PRO_E_CUTLINE_TP_TOOL_CENTER_OPT           4323
#define PRO_E_CUTLINE_TP_EXTEND_OPT                4324
#define PRO_E_CUTLINE_CUT_DEFINITION               4325
#define PRO_E_CUTLINE_CUT_PLACEMENT_OPT            4327
#define PRO_E_CUTLINE_REF_ARR                      4328
#define PRO_E_CUTLINE_REF_ITEM                     4329
#define PRO_E_CUTLINE_REF_TYPE                     4330
#define PRO_E_CUTLINE_REF_DRIVE_SURF               4331
#define PRO_E_CUTLINE_REF_DTM_CURVE                4332
#define PRO_E_CUTLINE_ID                           4334
#define PRO_E_CUTLINE_ALT_SRFS                     4335
#define PRO_E_CUTLINE_USE_ALT_SRFS                 4336
#define PRO_E_CUTLINE_PROJ_PLN                     4337
#define PRO_E_CUTLINE_SYNC_ARR                     4338
#define PRO_E_CUTLINE_SYNC_ITEM                    4339
#define PRO_E_CUTLINE_SYNC_ID                      4340
#define PRO_E_CUTLINE_SYNC_NAME                    4341
#define PRO_E_CUTLINE_SYNC_TYPE                    4342
#define PRO_E_CUTLINE_SYNC_POINT_ARR               4343
#define PRO_E_CUTLINE_SYNC_POINT                   4344
#define PRO_E_CUTLINE_SYNC_POINT_REF_ID            4345
#define PRO_E_CUTLINE_SYNC_POINT_RATIO             4346
#define PRO_E_CUTLINE_SYNC_REF                     4347

#define PRO_E_NCSEQ_CSYS                           4350
#define PRO_E_OPER_CSYS                            4351
#define PRO_E_RETR_SURF                            4352
#define PRO_E_RETR_SURF_TYPE                       4353
#define PRO_E_RETR_SURF_REF                        4354
#define PRO_E_RETR_SURF_ORIENT                     4355
#define PRO_E_RETR_SURF_VALUE                      4356
#define PRO_E_OPER_SUBSP_CSYS                      4358

#define PRO_E_MFG_TOOL_REF_COMPOUND                4370
#define PRO_E_MFG_TOOL_REF_POCKET                  4371
#define PRO_E_MFG_TOOL_REF_ID                      4372
#define PRO_E_MFG_TOOL_REF_HEAD_NUM                4373

#define PRO_E_MFG_TOOL_ADAPTER_NAME                4378
#define PRO_E_MFG_PREV_TOOL_ID                     4379

#define PRO_E_MACH_SRFS                            4380
#define PRO_E_TURN_PROFILE                         4381
#define PRO_E_MFG_START_PNT                        4382
#define PRO_E_MFG_END_PNT                          4383
#define PRO_E_MFG_OPER_REF                         4384
#define PRO_E_MFG_WCELL_REF                        4385
#define PRO_E_MFG_SEQ_NUM_AXES_OPT                 4386
#define PRO_E_DRILL_HOLESETS_OPT                   4387
#define PRO_E_MFG_TOOL_MOTIONS_OPT                 4388
#define PRO_E_SCALLOP_SURF_COLL                    4389

#define PRO_E_MFG_CMP_APPROACH_EXIT		   4390
#define PRO_E_MFG_CMP_APPROACH    		   4391
#define PRO_E_MFG_APPROACH_AXIS			   4392
#define PRO_E_MFG_FIRST_SLICE_ONLY		   4393
#define PRO_E_MFG_CMP_EXIT 			   4394
#define PRO_E_MFG_EXIT_AXIS 			   4395
#define PRO_E_MFG_LAST_SLICE_ONLY		   4396

#define PRO_E_MFG_4_AXIS_PLANE                     4397

#define PRO_E_MFG_START_HEIGHT                     4398
#define PRO_E_MFG_HEIGHT                           4399

#define PRO_E_MFG_CMP_MILL_WIND 		   4400
#define PRO_E_MFG_MILL_WIND 			   4401
#define PRO_E_MFG_EXCL_SRF_COLL                    4402

#define PRO_E_MFG_PREV_SEQ 			   4403

#define PRO_E_MFG_COMMENTS                         4404

#define PRO_E_MFG_CMP_CLOSED_LOOPS                 4405
#define PRO_E_MFG_CLOSED_LOOPS_ARR                 4406
#define PRO_E_MFG_CLOSED_LOOP_REF_ITEM             4407
#define PRO_E_MFG_CLOSED_LOOP_ID                   4408

#define PRO_E_MFG_MILL_WIND_SRF                    4410

#define PRO_E_TOOL_MTN_ARR                         4500
#define PRO_E_TOOL_MTN                             4501
#define PRO_E_TOOL_MTN_TYPE                        4502
#define PRO_E_TOOL_MTN_ID                          4503
#define PRO_E_TOOL_MTN_APPL_DATA                   4504
#define PRO_E_TOOL_MTN_PNT_REF                     4505
#define PRO_E_TOOL_MTN_OFFSET                      4506
#define PRO_E_TOOL_MTN_X_OFFSET                    4507
#define PRO_E_TOOL_MTN_Y_OFFSET                    4508
#define PRO_E_TOOL_MTN_Z_OFFSET                    4509
#define PRO_E_TOOL_MTN_AXIS_MOVES                  4510
#define PRO_E_TOOL_MTN_AXIS_DIR                    4511
#define PRO_E_TOOL_MTN_REF_IDX                     4512
#define PRO_E_TOOL_MTN_CRV_REF                     4513
#define PRO_E_TOOL_MTN_CRV_DIR                     4514
#define PRO_E_TOOL_MTN_SRF_REF                     4515
#define PRO_E_TOOL_MTN_AXIS_REF                    4516
#define PRO_E_TOOL_MTN_CL_CMD                      4517
#define PRO_E_TOOL_MTN_CL_CMD_STR                  4518
#define PRO_E_TOOL_MTN_CL_CMD_LOC_TYPE             4519
#define PRO_E_TOOL_MTN_CL_CMD_PARAM                4520
#define PRO_E_TOOL_MTN_TURN_PROF                   4521
#define PRO_E_TOOL_MTN_TURN_PROF_REF               4522
#define PRO_E_TOOL_MTN_TURN_PROF_S_VAL             4523
#define PRO_E_TOOL_MTN_TURN_PROF_E_VAL             4524
#define PRO_E_TOOL_MTN_TURN_PROF_S_REF             4525
#define PRO_E_TOOL_MTN_TURN_PROF_E_REF             4526
#define PRO_E_TOOL_MTN_TURN_CORNER_TYPE	           4527
#define PRO_E_TOOL_MTN_TURN_CORNER_ARR             4528
#define PRO_E_TOOL_MTN_TURN_CORNER                 4529
#define PRO_E_TOOL_MTN_TURN_PREV_ENT_ID            4530
#define PRO_E_TOOL_MTN_TURN_NEXT_ENT_ID            4531
#define PRO_E_TOOL_MTN_TURN_CORNER_VAL             4532
#define PRO_E_TOOL_MTN_TURN_STK_BND_REF            4533
#define PRO_E_TOOL_MTN_TURN_EXT                    4534
#define PRO_E_TOOL_MTN_TURN_S_EXT                  4535
#define PRO_E_TOOL_MTN_TURN_E_EXT                  4536
#define PRO_E_TOOL_MTN_REF_ID                      4537
#define PRO_E_TOOL_MTN_PROFILE_TYPE                4538
#define PRO_E_TOOL_MTN_PARENT_REF_ID		   4539
#define PRO_E_TOOL_MTN_GOTO_AXIS_REF               4540
#define PRO_E_TOOL_MTN_FEED_TYPE                   4541

#define PRO_E_MFG_PARAM_ARR                        4570
#define PRO_E_MFG_PARAM_COMPOUND                   4571
#define PRO_E_MFG_PRM_NAME                         4572
#define PRO_E_MFG_PRM_VAL_DBL                      4573
#define PRO_E_MFG_PRM_VAL_STR                      4574
#define PRO_E_MFG_PRM_ATTR                         4575

#define PRO_E_DRILL_GRP_PARAM_RULE_OPT             4577
#define PRO_E_DRILL_GRP_DIAM_TYPE_OPT              4578
#define PRO_E_DRILL_GRP_PARAM_VAL_BOOL             4579
#define PRO_E_DRILL_GRP_AXES_INDIV                 4580
#define PRO_E_DRILL_GRP_AXES_EXCL                  4581
#define PRO_E_DRILL_GRP_AXES_PATTERN               4582
#define PRO_E_DRILL_GRP_SURFACES                   4583
#define PRO_E_DRILL_GRP_CSYS                       4584
#define PRO_E_DRILL_GRP_DIAM_ARR                   4585
#define PRO_E_DRILL_GRP_DIAM_COPMPOUND             4586
#define PRO_E_DRILL_GRP_DIAM                       4587
#define PRO_E_DRILL_GRP_PARAM_ARR                  4588
#define PRO_E_DRILL_GRP_PARAM_COMPOUND             4589
#define PRO_E_DRILL_GRP_PARAM_NAME                 4590
#define PRO_E_DRILL_GRP_PARAM_DATA_TYPE            4591
#define PRO_E_DRILL_GRP_PARAM_OPER                 4592
#define PRO_E_DRILL_GRP_PARAM_VAL_INT              4594
#define PRO_E_DRILL_GRP_PARAM_VAL_DBL              4595
#define PRO_E_DRILL_GRP_PARAM_VAL_WSTR             4596
#define PRO_E_DRILL_GRP_RULES_COMPOUND             4597
#define PRO_E_DRILL_GRP_AXES_COMPOUND              4598

#define PRO_E_MFG_FROM1_PNT                        4599
#define PRO_E_MFG_HOME1_PNT                        4600
#define PRO_E_MFG_FROM2_PNT                        4601
#define PRO_E_MFG_HOME2_PNT                        4602

#define PRO_E_TURN_THREAD_LOCATION_TYPE            4650
#define PRO_E_TURN_THREAD_OUTPUT_TYPE              4651
#define PRO_E_TURN_THREAD_FORM_TYPE                4652

#define PRO_E_MFG_WCELL_ENABLE_MILL_OPT		   4671
#define PRO_E_MFG_WCELL_NUM_AXES                   4672
#define PRO_E_MFG_LATHE_DIR_OPT                    4673
#define PRO_E_MFG_MILLTURN_HEADS                   4674
#define PRO_E_MFG_MILLTURN_HEAD_1                  4675
#define PRO_E_WCELL_HEAD_MILL_OPT                  4676
#define PRO_E_WCELL_HEAD_FLASH_OPT                 4677
#define PRO_E_WCELL_HEAD_ROT_POS_OPT               4678
#define PRO_E_MFG_MILLTURN_HEAD_2                  4679
#define PRO_E_MILLTURN_TOOL_ROT_DIR_OPT            4680
#define PRO_E_MFG_WCELL_NUM_HEADS                  4681
#define PRO_E_MFG_WCELL_ENABLE_CMM_OPT		   4683
#define PRO_E_MFG_WCELL_NUM_SPINDLES	           4684
#define PRO_E_MFG_WCELL_ENABLE_TURN_OPT		   4685
#define PRO_E_MFG_MILLTURN_HEAD_3                  4686
#define PRO_E_MFG_MILLTURN_HEAD_4                  4687
#define PRO_E_WCELL_HEAD_TURN_OPT                  4688
#define PRO_E_WCELL_HEAD_BELOW_CLINE               4689

#define PRO_E_MFG_CURVE_FEAT                       4730

/* Bushing load feature (Pro/MECHANISM) */
#define PRO_E_BUSHLD_REF                           4820
#define PRO_E_BUSHLD_T1_DMP_COEFF                  4821
#define PRO_E_BUSHLD_T2_DMP_COEFF                  4822
#define PRO_E_BUSHLD_T3_DMP_COEFF                  4823
#define PRO_E_BUSHLD_R1_DMP_COEFF                  4824
#define PRO_E_BUSHLD_R2_DMP_COEFF                  4825
#define PRO_E_BUSHLD_R3_DMP_COEFF                  4826
#define PRO_E_BUSHLD_T1_STF_COEFF                  4827
#define PRO_E_BUSHLD_T2_STF_COEFF                  4828
#define PRO_E_BUSHLD_T3_STF_COEFF                  4829
#define PRO_E_BUSHLD_R1_STF_COEFF                  4830
#define PRO_E_BUSHLD_R2_STF_COEFF                  4831
#define PRO_E_BUSHLD_R3_STF_COEFF                  4832

#define PRO_E_CRV_FROM_XSEC_REF_XSEC               4833 
/* New cosmetic thread elements */
#define PRO_E_THRD_DIAM_NEW                        4900
#define PRO_E_THRD_START_REF_NEW                   4901
#define PRO_E_THRD_SURF_NEW                        4902
#define PRO_E_THRD_DEP_COMP_NEW                    4903
#define PRO_E_THRD_DEP_OPT_NEW                     4904
#define PRO_E_THRD_FLIP_OPT_NEW                    4905
#define PRO_E_THRD_DEP_VAL_NEW                     4906
#define PRO_E_THRD_END_REF                         4907
#define PRO_E_THRD_NOTE_PARAMS_NEW                 4908

#define PRO_E_REF_ATTACH_PRIM_QLT                  4909
#define PRO_E_REF_ATTACH_MERG_QLT                  4910
#define PRO_E_OPT_ATTACH_OPER                      4911
#define PRO_E_FLXSUBST_SUBSTING_QUILT              4912
#define PRO_E_FLXSUBST_RCR_RND_FLAG                4913
#define PRO_E_OPT_ATTACH_RMV_MAT                   4914

#define PRO_E_SMT_RIP_TYPE                         4915
#define PRO_E_OPT_ATTACH_PQ_DIR                    4916
#define PRO_E_OPT_ATTACH_MGQ_DIR                   4917

/* New Axis Control elements */
#define PRO_E_CUTLINE_AXIS_CTRL                    4919
#define PRO_E_CUTLINE_CTRL_PLANE                   4920
#define PRO_E_TOOL_AXIS_DEF                        4921
#define PRO_E_TOOL_AXIS_REF                        4922
#define PRO_E_TOOL_AXIS_LOC_ARR                    4923
#define PRO_E_TOOL_AXIS_LOC_ITEM                   4924
#define PRO_E_TOOL_AXIS_LOC_SRF_REF                4925
#define PRO_E_TOOL_AXIS_LOC_ID                     4926
#define PRO_E_TOOL_AXIS_LOC_TYPE                   4927
#define PRO_E_TOOL_AXIS_LOC_CUT_ID                 4928
#define PRO_E_TOOL_AXIS_LOC_RAT                    4929
#define PRO_E_TOOL_AXIS_LOC_PNT_REF                4930
#define PRO_E_TOOL_AXIS_LOC_ENDS                   4931

/* Helical Sweep */
#define PRO_E_HLSWP_SK_ORIENT_OPT 		   4932
#define PRO_E_HLSWP_TRIM_QUILT 			   4933
#define PRO_E_HLSWP_ARR 			   4934
#define PRO_E_HLSWP_PITCH_VAL 		           4935
#define PRO_E_HLSWP_PITCH_REF_OPT 		   4936
#define PRO_E_HLSWP_DBL_PARAM 			   4937
#define PRO_E_HLSWP_PITCH_REF 			   4938
#define PRO_E_HLSWP_SWP_SECTION 		   4939
#define PRO_E_HLSWP_CMPS			   4940
#define PRO_E_HLSWP_REF_VALUE			   4941
#define PRO_E_HLSWP_SEC_OPT                        4942
#define PRO_E_HLSWP_HAND_OPT                       4943
#define PRO_E_HLSWP_SKET_FLIP_OPT                  4944

#define PRO_E_MFG_GEOM_REF 			   4949
#define PRO_E_REF_START 			   4950
#define PRO_E_REF_END			   	   4951
#define PRO_E_REF_CLSPLN 			   4952
#define PRO_E_OPT_ATTR			 	   4953
#define PRO_E_MFG_USER_DEF_PNT 			   4954
#define PRO_E_OPT_REFCSYS 			   4955
#define PRO_E_MFG_SELTYP 			   4956
#define PRO_E_MFG_CLS_PLN_OPT 			   4957
#define PRO_E_MFG_U_PNT 			   4958
#define PRO_E_MFG_V_PNT 		           4959
#define PRO_E_MFG_EDIT_PNT			   4960
#define PRO_E_MFG_UDP_COL 			   4961
#define PRO_E_MFG_UDL_COL 			   4962

#define PRO_E_SMT_DIMENSION_TYPE                  4963
#define PRO_E_SMT_DIMENSION_VALUE                 4964

#define PRO_E_SMT_EDGE_REFERENCES                 4965
#define PRO_E_SMT_EDGE_RIP_ARRAY                  4966
#define PRO_E_SMT_EDGE_RIP_SET                    4967
 
#define PRO_E_SMT_EDGE_BEND_ARRAY                 4968
#define PRO_E_SMT_EDGE_BEND_SET                   4969

/* Corner Chamfer */
#define PRO_E_CRN_CHMF_CORNER                      PRO_E_STD_CORNER_CHAMF_CORNER
#define PRO_E_CRN_CHMF_DIM1                        PRO_E_STD_CORNER_CHAMF_EDGE1
#define PRO_E_CRN_CHMF_DIM2                        PRO_E_STD_CORNER_CHAMF_EDGE2
#define PRO_E_CRN_CHMF_DIM3                        PRO_E_STD_CORNER_CHAMF_EDGE3

#define PRO_E_THRD_TYPE_OPT_NEW                    4974
#define PRO_E_THRD_SERIES_NEW                      4975
#define PRO_E_THRD_SCREWSIZE_NEW                   4976


/* Vertex Round */
#define PRO_E_VERTEX_ROUND_VERT                    4977
#define PRO_E_VERTEX_ROUND_RADIUS                  4978

/* Modify Round elements */
#define PRO_E_MODRND_RAD_VAL                       4979

/* New Axis Control elements */
#define PRO_E_CLAC_TYPE                            4980
#define PRO_E_CLAC_PNT_REF                         4981
#define PRO_E_CLAC_CRV_REF                         4982
#define PRO_E_CLAC_SYNC_ARR                        4983
#define PRO_E_CLAC_SYNC_ITEM                       4984
#define PRO_E_CLAC_SYNC_ID                         4985
#define PRO_E_CLAC_SYNC_CRV_REF                    4986
#define PRO_E_CLAC_SYNC_CRV_RATIO                  4987
#define PRO_E_CLAC_SYNC_CUT_REF                    4988
#define PRO_E_CLAC_SYNC_CUT_ID                     4989
#define PRO_E_CLAC_SYNC_CUT_RATIO                  4990
#define PRO_E_CLAC_LOC_CTRL                        4991
#define PRO_E_CLAC_DRV_SRF_ARR                     4992
#define PRO_E_CLAC_DRV_SRF_ITEM                    4993
#define PRO_E_CLAC_DRV_SRF_ID                      4994
#define PRO_E_CLAC_LOC_ARR                         4995
#define PRO_E_CLAC_LOC_ITEM                        4996
#define PRO_E_CLAC_LOC_ID                          4997
#define PRO_E_CLAC_LOC_SRF_ID                      4998
#define PRO_E_CLAC_DIR_FLIP                        4999
#define PRO_E_CLAC_LOC_TYPE                        5000
#define PRO_E_CLAC_LOC_CUT_REF                     5001
#define PRO_E_CLAC_LOC_CUT_ID                      5002
#define PRO_E_CLAC_LOC_CUT_RATIO                   5003
#define PRO_E_CLAC_LOC_PNT_REF                     5004
#define PRO_E_CLAC_LOC_CRV_REF                     5005
#define PRO_E_CLAC_LOC_CRV_RATIO                   5006
#define PRO_E_CLAC_LOC_CRV_ENDS                    5007
#define PRO_E_CLAC_DIR_TYPE                        5008
#define PRO_E_CLAC_DIR_PNT_REF                     5009
#define PRO_E_CLAC_DIR_ORTS                        5010
#define PRO_E_CLAC_DIR_I_VAL                       5011
#define PRO_E_CLAC_DIR_J_VAL                       5012
#define PRO_E_CLAC_DIR_K_VAL                       5013
#define PRO_E_CLAC_DIR_CRV_REF                     5014
#define PRO_E_CLAC_DIR_CRV_RATIO                   5015

/* import feature dash element */
#define PRO_E_IMP_FEAT_REF_CSYS                    5016
#define PRO_E_IMP_FEAT_MK_SOLID_OPT                5017

#define PRO_E_CORNER_RELIEFS 		           5018
#define PRO_E_CORNER_RELIEFS_CR_STATE  		   5019
#define PRO_E_CORNER_RELIEFS_DIM_SCHEME		   5020
#define PRO_E_CORNER_RELIEFS_ARR  		   5021
#define PRO_E_CORNER_RELIEF_SET  		   5022
#define PRO_E_CORNER_RELIEF_REF_ARR		   5023
#define PRO_E_CORNER_RELIEF_REF_SET        	   5024
#define PRO_E_CORNER_RELIEF_REF_TYPE       	   5025
#define PRO_E_CORNER_RELIEF_REF_FLAT  		   5026
#define PRO_E_CORNER_RELIEF_REF_BND_1  		   5027
#define PRO_E_CORNER_RELIEF_REF_BND_2  		   5028
#define PRO_E_CORNER_RELIEF_REF_EDGE_1 		   5029
#define PRO_E_CORNER_RELIEF_REF_EDGE_PRM	   5030
#define PRO_E_CORNER_RELIEF_DEFINE 		   5032

/* Modify Analytic Geometry elements   */
#define PRO_E_MAG_ANGLE_VAL                        5033
#define PRO_E_MAG_RADII_VAL                        5034
#define PRO_E_MAG_RADII2_VAL                       5035

#define PRO_E_FIXTURE_COMPONENT_ARR                5036
#define PRO_E_FIXTURE_COMPONENT                    5037
#define PRO_E_FIXTURE_COMPONENT_REF                5038

#define PRO_E_MFG_TRAJ_CRV                         5039
#define PRO_E_MFG_TRAJ_DIR_FLIP                    5040
#define PRO_E_MFG_TRAJ_OFFSET                      5041
#define PRO_E_MFG_TRAJ_MAT_SIDE                    5042

#define PRO_E_MAG_ATTACHMENT                       5043

#define PRO_E_SMT_EXTEND_WALL_EDGE                 5044
#define PRO_E_SMT_EXTEND_WALL_DIST                 5045
#define PRO_E_SMT_EXTEND_DIST_TYPE                 5046
#define PRO_E_SMT_EXTEND_DIST_VALUE                5047
#define PRO_E_SMT_EXTEND_DIST_REF                  5048
#define PRO_E_SMT_EXTEND_ADJUST_SRF                5049

/* Bend feature */
#define PRO_E_SMT_BEND_FORM 			   5050
#define PRO_E_SMT_BEND_DIRECTION 		   5051
#define PRO_E_SMT_BEND_FIXED_SIDE   		   5052
#define PRO_E_SMT_BEND_LOCATION  		   5053
#define PRO_E_SMT_BEND_LINE 			   5054
#define PRO_E_SMT_BEND_LINE_TYPE 		   5055
#define PRO_E_SMT_BEND_CURVE 			   5056
#define PRO_E_SMT_BEND_CURVE_USE_OFFSET		   5057	
#define PRO_E_SMT_BEND_CURVE_OFFSET_VALUE	   5058
#define PRO_E_SMT_BEND_REF_SURFACE 		   5059
#define PRO_E_SMT_BEND_TRANS_AREAS 		   5060
#define PRO_E_SMT_BEND_TRANS_FLIP 		   5061
#define PRO_E_SMT_BEND_ANGLE_TYPE 		   5062
#define PRO_E_SMT_BEND_ANGLE_VALUE		   5063
#define PRO_E_SMT_BEND_TRANS_SET 		   5064



/* Shut off srf feature dash elements. */
#define PRO_E_SHUT_SRF_SRF_REFS                    5069
#define PRO_E_SHUT_SRF_CRV_REFS                    5070
#define PRO_E_SHUT_SRF_REF_TYPE                    5071
#define PRO_E_SHUT_SRF_CLOSE_ALL                   5072
#define PRO_E_SHUT_SRF_CAP_SRFS                    5073
#define PRO_E_SHUT_SRF_ARR_COLL_CRV                5074
#define PRO_E_SHUT_SRF_COLL_CRV_CMP                5075


/* Mirror Geometry feature  */
#define PRO_E_MGF_MIRROR_PLANE                     5076
#define PRO_E_MGF_REMOVE_GEOM                      5077
#define PRO_E_MGF_CLOSE_GEOM                       5078
#define PRO_E_MGF_ATTACH_GEOM                      5079
#define PRO_E_MGF_CREATE_RND_GEOM                  5080


/* Bend feature - internal bend line elements */
#define PRO_E_SMT_BEND_LINE_INTERNAL	 	   5081
#define PRO_E_SMT_BEND_LINE_REF_END1		   5082
#define PRO_E_SMT_BEND_LINE_REF_END2		   5083
#define PRO_E_SMT_BEND_LINE_REF_OFFSET1	           5084
#define PRO_E_SMT_BEND_LINE_REF_OFFSET2	           5085
#define PRO_E_SMT_BEND_LINE_REF_OFFSET1_VALUE      5086  
#define PRO_E_SMT_BEND_LINE_REF_OFFSET2_VALUE      5087

/* import feature additional elements */
#define PRO_E_IMP_FEAT_RMV_MATERIAL_OPT            5088

#define PRO_E_SMT_FLATTEN_REF_TYPE                 5089
#define PRO_E_STEP_STAMPED_TREAT_EDGE              5090

#define PRO_E_TOOL_MTN_TURN_PROF_S_ORIENT          5091
#define PRO_E_TOOL_MTN_TURN_PROF_E_ORIENT          5092
#define PRO_E_TOOL_MTN_TURN_PROF_OFFSET_CUT        5093
#define PRO_E_TOOL_MTN_TURN_DFLT_CORNER_TYPE       5094

#define PRO_E_MFG_TRAJ_SRFS                        5095

/* Tapered Extrude */
#define PRO_E_EXT_COMP_DRFT_ANG                    5096
#define PRO_E_EXT_DRFT_ANG                         5097
#define PRO_E_EXT_DRFT_ANG_VAL                     5098

#define PRO_E_SMT_PUNCH_TOOL_ATTR                  5099
#define PRO_E_SMT_PUNCH_TOOL_NAME                  5100
#define PRO_E_SMT_PUNCH_TOOL_DATA                  5101

#define PRO_E_SMT_MERGE_AUTO                       5102
#define PRO_E_SMT_MERGE_KEEP_LINES                 5103
#define PRO_E_SMT_MERGE_DATA                       5104

/* advanced contact steps */
#define PRO_E_C3D_REF1_RECS                        5105
#define PRO_E_C3D_REF2_RECS                        5106
#define PRO_E_C3D_REF_REC                          5107
#define PRO_E_C3D_REF                              5108
#define PRO_E_C3D_REF_FULL_GEOM                    5109
#define PRO_E_C3D_REF_FLIP                         5110

#define PRO_E_SMT_DRV_SURF                         5111
#define PRO_E_SMT_PUNCH_AXIS_PNT                   5112

/* Curve Through Points */
#define PRO_E_CRV_TP_ON_SURF                       5120
#define PRO_E_CRV_TP_ON_SURF_REF                   5121
#define PRO_E_CRV_TP_TWEAK                         5122
#define PRO_E_CRV_TP_PNTS                          5123
#define PRO_E_CRV_TP_PNT                           5124
#define PRO_E_CRV_TP_PNT_REF                       5125
#define PRO_E_CRV_TP_PNT_CONN_TYPE                 5126
#define PRO_E_CRV_TP_PNT_RAD_VAL                   5127
#define PRO_E_CRV_TP_START                         5128
#define PRO_E_CRV_TP_START_TYPE                    5129
#define PRO_E_CRV_TP_START_REF                     5130
#define PRO_E_CRV_TP_START_FLIP                    5131
#define PRO_E_CRV_TP_START_PERP                    5132
#define PRO_E_CRV_TP_START_PERP_REF                5133
#define PRO_E_CRV_TP_START_PERP_FLIP               5134
#define PRO_E_CRV_TP_END                           5135
#define PRO_E_CRV_TP_END_TYPE                      5136
#define PRO_E_CRV_TP_END_REF                       5137
#define PRO_E_CRV_TP_END_FLIP                      5138
#define PRO_E_CRV_TP_END_PERP                      5139
#define PRO_E_CRV_TP_END_PERP_REF                  5140
#define PRO_E_CRV_TP_END_PERP_FLIP                 5141


/* Smt Extend Wall*/
#define PRO_E_SMT_EXTEND_WALL_EXTENSIONS_CMP       5142
#define PRO_E_SMT_EXTEND_SIDE1_EXTENSION_CMP       5143
#define PRO_E_SMT_EXTEND_EXTENSION_TYPE_OPT        5144
#define PRO_E_SMT_EXTEND_SIDE2_EXTENSION_CMP       5145

#define PRO_E_CORNER_RELIEF_DESIGNATE       	   5146


/* FLXMDL 'Force Attach Option' Chaincoll related elems */
#define PRO_E_FLEX_ATT_CHNS_CMP                    5149
#define PRO_E_FLEX_SIDE_SRFS_CMP                   5150
#define PRO_E_FLEX_EXT_INT_CMP                     5151
#define PRO_E_FLEX_SOL_INDEX                       5152

/* FLXMDL Offset Geometry */
#define PRO_E_OGF_OFFSET_VAL                       5147
#define PRO_E_OGF_DIR_OPT                          5148
#define PRO_E_OGF_FLX_OPTS                         5153
#define PRO_E_OGF_CLOSEGEOM                        5154
#define PRO_E_OGF_ATT_OFFST                        5155
#define PRO_E_OGF_CR_RND_GEOM                      5156
#define PRO_E_OGF_KEEP_PATNSYM                     5157

/* Edit Reference elements */
#define PRO_E_ER_REFERENCE_SETS                    5158
#define PRO_E_ER_REFERENCE_SET                     5159
#define PRO_E_ER_REFERENCE                         5160
#define PRO_E_ER_UBF_ATTRS                         5161
#define PRO_E_ER_UBF_ATTR                          5162

#define PRO_E_UDF_VAR_DIM                          5163
#define PRO_E_UDF_VAR_DIM_VIS                      5164

/* Additional element for Sketched feature (formerly Sketched Curve) / Cosmetic Sketch */
#define PRO_E_SKFEAT_HATCH_ANGLE                   5165

#define PRO_E_MFG_APPR_EXIT_DIR                    5166

#define PRO_E_MIRROR_FULL_DEP_COPY                 5167

#define PRO_E_SMT_PROJ_DIR                         5168

#define PRO_E_UDF_EXT_PARAM_MODEL                  5170
/* Mfg MfgPTMMatRem Feature elements */
#define PRO_E_MFGPTM_SEQ_REF                       5171
#define PRO_E_MFGPTM_CONSTR_REF                    5172
#define PRO_E_MFGPTM_RESOL_DBL                     5173

/* CE component steps */

#define PRO_E_SMT_FLATTEN_PROJ_CUTS                5174
#define PRO_E_SMT_UNBEND_TYPE                      5175
#define PRO_E_SMT_UNBEND_SUB_TYPE                  5176
#define PRO_E_SMT_PRIMARY_FIXED_GEOM               5177
#define PRO_E_SMT_FIXED_REF                        5178
#define PRO_E_SMT_FIXED_REF_SIDE                   5179
#define PRO_E_SMT_UNBEND_REF_ARR                   5180
#define PRO_E_SMT_UNBEND_REF                       5181
#define PRO_E_SMT_UNBEND_SINGLE_REF                5182
#define PRO_E_SMT_DEFORM_SURFACES                  5183
#define PRO_E_SMT_DISTINCT_AREAS_ARR               5184
#define PRO_E_SMT_ADD_FIXED_GEOM                   5185
#define PRO_E_SMT_DEFORM_AREAS_ARR                 5186
#define PRO_E_SMT_DEFORM_AREA                      5187
#define PRO_E_SMT_DEFORM_GEOMS_ARR                 5188
#define PRO_E_SMT_DEFORM_GEOM                      5189
#define PRO_E_SMT_SINGLE_DEFORM_GEOM               5190
#define PRO_E_SMT_DEFORM_AREA_TYPE                 5191
#define PRO_E_SMT_ADD_CORNER_RELIEFS               5192
#define PRO_E_SMT_FLATTEN_ALL_FORMS                5193

#define PRO_E_FLXSUBST_MNTN_PAT_FLAG               5194
#define PRO_E_FLXSUBST_KEEP_QUILT                  5195

#define PRO_E_MGF_DATUMS                           5196

/*Elements for CMM REFCSYS*/
#define PRO_E_CMM_REF_CSYS_TRF_OPT		   5197
#define PRO_E_CMM_PARENT_CSYS_SEL		   5198
#define PRO_E_CMM_STEP_PRIMARY_CSYS_COMP	   5199
#define PRO_E_CMM_STEP_ALIGN_AXIS_OPTION	   5200
#define PRO_E_CMM_STEP_PRIMARY_FEAT_SEL		   5201
#define PRO_E_CMM_STEP_TRANS_CSYS_COMP		   5202
#define PRO_E_CMM_STEP_TRANS_X_COMP		   5203
#define PRO_E_CMM_STEP_TRANS_X_INPUT		   5204
#define PRO_E_CMM_STEP_TRANS_X_FEAT_SEL		   5205
#define PRO_E_CMM_STEP_TRANS_Y_COMP		   5206
#define PRO_E_CMM_STEP_TRANS_Y_INPUT		   5207
#define PRO_E_CMM_STEP_TRANS_Y_FEAT_SE		   5208
#define PRO_E_CMM_STEP_TRANS_Z_COMP 		   5209
#define PRO_E_CMM_STEP_TRANS_Z_INPUT		   5210
#define PRO_E_CMM_STEP_TRANS_Z_FEAT_SEL		   5211
#define PRO_E_CMM_STEP_ROTATE_CSYS_COMP		   5212
#define PRO_E_CMM_STEP_ROTATE_INPUT		   5213
#define PRO_E_CMM_STEP_ROTATE_FEAT_SEL		   5214
#define PRO_E_CMM_STEP_ROTATE_AXIS_OPT		   5215
#define PRO_E_CMM_STEP_ROT_ALIGN_OPT		   5216
#define PRO_E_CMM_STEP_CUSTOM_CSYS_COMP		   5217
#define PRO_E_CMM_STEP_CUSTOM_FUNC_NAME		   5218
#define PRO_E_CMM_STEP_CUSTOM_FUNCTION_A	   5219
#define PRO_E_CMM_STEP_CUSTOM_FEAT_SEL		   5220
#define PRO_E_CMM_REF_CSYS_ALIGN_REF_OPT	   5221
#define PRO_E_CMM_STEP_THEO_CSYS_COMP		   5222
#define PRO_E_CMM_THEO_DATUM_CSYS_SEL		   5223
#define PRO_E_CMP_CMM_DRAGGER		   	   5224
#define PRO_E_CMM_FLIP_OPT			   5225
#define PRO_E_CMM_CUSTOM_DOF_COMP		   5226
#define PRO_E_CMM_CUSTOM_DOF_X_DIR		   5227
#define PRO_E_CMM_CUSTOM_DOF_Y_DIR		   5228
#define PRO_E_CMM_CUSTOM_DOF_Z_DIR 		   5229
#define PRO_E_CMM_CUSTOM_DOF_X_ROT 		   5230
#define PRO_E_CMM_CUSTOM_DOF_Y_ROT 		   5231
#define PRO_E_CMM_CUSTOM_DOF_Z_ROT 		   5232

#define PRO_E_CMM_PNT_DATA_ARR                     5233
#define PRO_E_CMM_PNT_DATA_COMPOUND                5234
#define PRO_E_CMM_SUBFEAT_ID                       5235
#define PRO_E_CMM_PNT_TYPE                         5236
#define PRO_E_CMM_PNT_REF                          5237
#define PRO_E_CMM_PNT_RULE_IDX_U 		   5238
#define PRO_E_CMM_PNT_RULE_IDX_V 		   5239
#define PRO_E_CMM_CLEARANCE_COMP 		   5240
#define PRO_E_CMM_PNT_CLEAR_DIST 		   5241
#define PRO_E_CMM_PNT_PULLOUT_DIST 		   5242

/* import feature additional elements */
#define PRO_E_IMP_FEAT_LOCATION_METHOD_OPT         5243

#define PRO_E_SMT_AUTO_DEFORM_REF_ARR              5244
#define PRO_E_SMT_AUTO_DEFORM_REF                  5245
#define PRO_E_SMT_AUTO_DEFORM_SINGLE_REF           5246
#define PRO_E_SMT_DISTINCT_AREA                    5247

#define PRO_E_MFG_ENTRY_PNT_REF                    5248


#define PRO_E_SMT_RIP_CONNECT_SETS                 5249
#define PRO_E_SMT_RIP_CONNECT_SET                  5250
#define PRO_E_SMT_RIP_CONN_REFS                    5251
#define PRO_E_SMT_RIP_CONN_REF                     5252
#define PRO_E_SMT_RIP_CONN_END                     5253
#define PRO_E_SMT_BEND_BACK_SUB_TYPE               5254
#define PRO_E_SMT_BBACK_REF_ARR                    5255
#define PRO_E_SMT_BBACK_REF                        5256
#define PRO_E_SMT_BBACK_SINGLE_REF                 5257
#define PRO_E_SMT_BBACK_FLAT_CONTOURS_AR           5258
#define PRO_E_SMT_GEOM_CONTOUR                     5259
#define PRO_E_SMT_GEOM_CONTOUR_GEOM                5260
#define PRO_E_SMT_GEOM_CONTOUR_EDGE                5261

#define PRO_E_MFG_CUST_CYCLE_PLATE_NAME            5270
#define PRO_E_MFG_CUST_CYCLE_VAR_NAME              5271
#define PRO_E_MFG_HSET_DRILL_GROUP_REF             5272
#define PRO_E_MFG_HSET_DIAM_ARR                    5273
#define PRO_E_MFG_HSET_DIAM_COMPOUND               5274
#define PRO_E_MFG_HSET_HOLE_DIAM                   5275
#define PRO_E_MFG_HSET_PARAM_ARR                   5276
#define PRO_E_MFG_HSET_PARAM_COMPOUND              5277
#define PRO_E_MFG_HSET_PARAM_NAME                  5278
#define PRO_E_MFG_HSET_PARAM_DTYPE                 5279
#define PRO_E_MFG_HSET_PARAM_VAL_DBL               5280
#define PRO_E_MFG_HSET_PARAM_VAL_INT               5281
#define PRO_E_MFG_HSET_PARAM_VAL_STR               5282
#define PRO_E_MFG_HSET_START_HOLE_REF              5283
#define PRO_E_MFG_THRM_HOLESET_ARR                 5284
#define PRO_E_MFG_THRM_HOLESET_COMPOUND            5285
#define PRO_E_MFG_THRM_HSET_END_COMPOUND           5286
#define PRO_E_MFG_THRM_HSET_HOLES_COMP             5287
#define PRO_E_MFG_HSET_THREAD_DESCR_ARR            5288
#define PRO_E_MFG_HSET_THREAD_DESCR_COMP           5289
#define PRO_E_MFG_HSET_THREAD_DESCR                5290
#define PRO_E_MFG_HSET_PARAM_OPER_OPT              5291
#define PRO_E_MFG_HSET_PARAM_VAL_BOOL              5292
#define PRO_E_HOLESET_PLATE_END_OPT                5293
#define PRO_E_MFG_CUSTOM_CYCLE_NAME                5294
#define PRO_E_MFG_LOOP_SURF_REF                    5295
#define PRO_E_FF_TRAJ_FLIP_OPT                     5296
#define PRO_E_MFG_HSET_DIAM_TYPE_OPT               5297
#define PRO_E_MFG_HSET_PARAM_RULE_OPT              5298

#define PRO_E_OPERATION_NAME			   5301
#define PRO_E_WCELL_NAME			   5302
#define PRO_E_REF_SEQ_NAME			   5303
#define PRO_E_FIXTURE_NAME			   5304

#define PRO_E_MFG_OFFSET 			   5305
#define PRO_E_MFG_OFFSET_CUT 			   5307
#define PRO_E_MFG_MAT_TO_RMV 			   5308

#define PRO_E_SMT_CORNER_RELIEF_ROTATE             5309
#define PRO_E_SMT_CORNER_RELIEF_ROTATE_ADD         5310
#define PRO_E_SMT_CORNER_RELIEF_ROTATE_VAL         5311
#define PRO_E_SMT_CORNER_RELIEF_OFFSET             5312
#define PRO_E_SMT_CORNER_RELIEF_OFFSET_ADD         5313
#define PRO_E_SMT_CORNER_RELIEF_OFFSET_VAL         5314

#define PRO_E_MGF_REFS                             5315
#define PRO_E_MGF_OPTS                             5316

#define PRO_E_MODRND_OPTS                          5317
#define PRO_E_MODRND_ATTACH                        5318
#define PRO_E_MODRND_CLOSEGEOM                     5319
#define PRO_E_MODRND_RMV_INTERF_RND                5320
#define PRO_E_MODRND_REMOVE                        5321

#define PRO_E_SSRF_REF_SEL_TYPE                    5322
#define PRO_E_SSRF_CR_SRF_TYPE                     5323

#define PRO_E_CMM_GEOM_REF                         5354
#define PRO_E_GEOM_REF_IDSURF_ARR                  5355
#define PRO_E_GEOM_REF_IDSURF_COMP                 5356
#define PRO_E_GEOM_REF_IDSURF                      5357
#define PRO_E_CMM_START_SURF                       5358

#define PRO_E_MFG_WCELL_CUST_CYCLE_ARR             5360
#define PRO_E_MFG_WCELL_CUST_CYCLE_COMP            5361
#define PRO_E_MFG_WCELL_CUST_CYCLE_NAME            5362
#define PRO_E_MFG_MILL_THREAD_TYPE_OPT             5363
#define PRO_E_MFG_NORM_SRFS                        5364
#define PRO_E_MFG_MACH_CRVS                        5365
#define PRO_E_CECOMP_CHOOSER                       5366

#define PRO_E_BLEND_SEC_ARRAY                      5367
#define PRO_E_BLEND_CMP                            5368
#define PRO_E_BLEND_LOC_OPTION                     5369
#define PRO_E_BLEND_OFFSET                         5370
#define PRO_E_BLEND_OFFSET_INDX                    5371
#define PRO_E_BLEND_SEC_LOC_REF                    5372
#define PRO_E_BLEND_SKETSEL_OPT                    5373
#define PRO_E_BLEND_OFFSET_OPTION                  5374
#define PRO_E_BLEND_AXIS                           5375

/*Elements for CMM CONSTRUCT*/
#define PRO_E_CMM_CONSTRUCT_TYPE 		   5377
#define PRO_E_CMM_CONS_REF_FEAT 		   5378

/*Elements for CMM VERIFY*/
#define PRO_E_CMM_VERIFY_ATTR 			   5379
#define PRO_E_CMM_VERIFY_TOL 			   5380
#define PRO_E_CMM_VERIFY_FEAT 			   5381
#define PRO_E_CMM_VERIFY_DATUM 			   5382

#define PRO_E_DRAFT_NEUTRAL_QUILT_1                5383
#define PRO_E_DRAFT_NEUTRAL_QUILT_2                5384
#define PRO_E_BLEND_SECTION			   5385
#define PRO_E_CRV_TP_PNT_RAD_GROUP                 5386

#define PRO_E_PAT_GPRF 			           5387
#define PRO_E_PAT_GPRF_TYPE		           5388
#define PRO_E_PAT_GPRF_TRF_TYPE		           5389
#define PRO_E_PAT_GPRF_DIR1_TRF		           5390
#define PRO_E_PAT_GPRF_DIR1_NUM_INST               5391
#define PRO_E_PAT_GPRF_DIR1_SPACING                5392
#define PRO_E_PAT_GPRF_DIR2_TRF		           5393
#define PRO_E_PAT_GPRF_DIR2_NUM_INST               5394
#define PRO_E_PAT_GPRF_DIR2_SPACING                5395
#define PRO_E_DIR_GPRF_MOVE_OPT		           5396
#define PRO_E_PAT_GPRF_USE_SRF                     5397
#define PRO_E_PAT_GPRF_SRF_REF                     5398
#define PRO_E_PAT_GPRF_USE_SEC		           5399

#define PRO_E_FLEXMOVE_DEFINE_METHOD               5400

#define PRO_E_MFG_NORM_GEOM                        5401
#define PRO_E_PSR_PLN_REF                          5402

#define PRO_E_STD_FLEX_PROPAGATION                 5404

#define PRO_E_BLEND_SURF_OPTION                    5405
#define PRO_E_SMT_EDGE_BEND_REFERENCES             5406
#define PRO_E_SMT_EDGE_RIP_REFERENCES              5407
#define PRO_E_MFG_PARAM_SITE_NAME                  5408
#define PRO_E_BLEND_END_SECTIONS_OPEN              5409
#define PRO_E_BLEND_TANG_COND                      5410
#define PRO_E_BLEND_END_TNC                        5411
#define PRO_E_BLEND_TANG_OPTION                    5412
#define PRO_E_BLEND_CONNECT_SURF_CHAIN             5413

/* SMT bend relief */
#define PRO_E_BEND_RELIEF_DEPTH_TYPE		   5414 
#define PRO_E_BEND_RELIEF_DEPTH_OLD		   5415
#define PRO_E_SMT_CONVERSION_AUTO_BENDS            5416
#define PRO_E_SMT_CONVERSION_AUTO_BENDS_USE        5417
#define PRO_E_SMT_CONVERSION_AUTO_BENDS_TYPE       5418

#define PRO_E_D3ELEM_LOCATION                      5419

#define PRO_E_MFG_WCELL_HEAD_1                     5420
#define PRO_E_MFG_WCELL_HEAD_2                     5421
#define PRO_E_MFG_WCELL_HEAD_TYPE                  5422
#define PRO_E_MFG_WCELL_TOOL_SETUP_ARR             5423
#define PRO_E_MFG_WCELL_TOOL_SETUP                 5424
#define PRO_E_MFG_WCELL_TOOL_POCKET_NUM            5425
#define PRO_E_MFG_WCELL_TOOL_ID                    5426
#define PRO_E_MFG_WCELL_TOOL_OUTPUT_TIP            5427
#define PRO_E_MFG_TOOL_TIP_ARR                     5428
#define PRO_E_MFG_TOOL_TIP_COMPOUND                5429
#define PRO_E_MFG_TOOL_TIP_REGISTER                5430
#define PRO_E_MFG_TOOL_TIP_COMMENT                 5431
#define PRO_E_MFG_TOOL_TIP_OFFSET_Z                5432
#define PRO_E_MFG_TOOL_TIP_OFFSET_X                5433
#define PRO_E_MFG_TOOL_TIP_OFFSET_ANGLE            5434
#define PRO_E_MFG_TOOL_TIP_FLASH_OPT               5435
#define PRO_E_MFG_TOOL_TIP_FLSH_REGISTER           5436
#define PRO_E_MFG_TOOL_TIP_FLSH_COMMENT            5437
#define PRO_E_MFG_TOOL_TIP_FLSH_OFFSET_Z           5438
#define PRO_E_MFG_TOOL_TIP_FLSH_OFFSET_X           5439
#define PRO_E_MFG_WCELL_CMM_HEAD                   5440
#define PRO_E_MFG_CMM_TOOL_SETUP_ARR               5441
#define PRO_E_MFG_CMM_TOOL_SETUP                   5442
#define PRO_E_MFG_CMM_TOOL_POCKET_NUM              5443
#define PRO_E_MFG_CMM_TOOL_TOOL_ID                 5444
#define PRO_E_MFG_CMM_TOOL_TIP_NUM                 5445
#define PRO_E_MFG_CMM_TOOL_REGISTER                5446
#define PRO_E_MFG_CMM_TOOL_COMMENT                 5447
#define PRO_E_MFG_CMM_TOOL_PITCH_ANGLE             5448
#define PRO_E_MFG_CMM_TOOL_ROLL_ANGLE              5449

#define PRO_E_FLEXMOVE_DIMS_COMPOUND               5450
#define PRO_E_FLEXMOVE_DIMS_ARRAY                  5451
#define PRO_E_FLEXMOVE_DIM_COMPOUND                5452
#define PRO_E_FLEXMOVE_DIM_VALUE                   5453
#define PRO_E_FLEXMOVE_DIM_TYPE                    5454
#define PRO_E_FLEXMOVE_DIM_REFS                    5455

#define PRO_E_NCD_CURVE_POINT                      5457
#define PRO_E_NCD_CURVE_POINT_REF                  5458
#define PRO_E_NCD_CURVE_POINT_OFFSET_TYPE          5459
#define PRO_E_NCD_CURVE_POINT_OFFSET               5460

#define PRO_E_TOOL_MTN_TRIM_START_VAL              5461
#define PRO_E_TOOL_MTN_TRIM_END_VAL                5462
#define PRO_E_TOOL_MTN_TRIM_VAL_OPT                5463
#define PRO_E_TOOL_MTN_TRIM_FLIP_DIR               5464

#define PRO_E_KEEP_REMOVED_SRFS_OPT                5465

#define PRO_E_PSR_DTM_REF                          5466
#define PRO_E_PSR_RCG_OPT                          5467

#define PRO_E_MFG_PREREQUISITE_ARR                 5468
#define PRO_E_MFG_PREREQUISITE_COMPOUND            5469
#define PRO_E_MFG_PREREQUISITE_ID                  5470

#define PRO_E_FLEXMOVE_MOVED_GEOMETRY              5471
#define PRO_E_FLEXMOVE_DTM_REF                     5472

#define PRO_E_FLEX_CLOSE_GEOM                      5473
#define PRO_E_FLEX_ATTACH_GEOM                     5474
#define PRO_E_FLEX_CR_RND_GEOM                     5475
#define PRO_E_FLEX_KEEP_ORIG_GEOM                  5476
#define PRO_E_FLEX_SPLIT_EXT_SRFS                  5477
#define PRO_E_FLEX_OPTS_CMPND                      5478
#define PRO_E_CMP_SUBSTITUTED                      5479
#define PRO_E_CMP_SUBTITUTING                      5480
#define PRO_E_FLXSUBST_KEEP_SURFS                  5481

#define PRO_E_CMM_SAVE_OPT                         5482

#define PRO_E_CECOMP_TAGS_COLL                     5483

#define PRO_E_MFG_OPER_STOCK_MATERIAL              5484

#define PRO_E_SEC_USE_COSM_SKETCH                  5485

#define PRO_E_FLEX_SPLIT_EXT_SURFS_CMP             5486
#define PRO_E_FLEX_EXT_SRFS_CMP                    5487
#define PRO_E_FLEX_SPT_SRFS_CMP                    5488
#define PRO_E_FLEX_FLIP_SPLIT_DIR                  5489

#define PRO_E_MFG_FIXTURE_REF                      5491

#define PRO_E_REF_SSRF_SRF                         5492
#define PRO_E_SSRF_INC_ELEMS                       5493
#define PRO_E_SSRF_EXCL_ELEMS                      5494
#define PRO_E_CECOMP_REF_MODEL                     5495

#define PRO_E_TOOL_MOTION_APPR_ALONG_TOOL_AXIS     5496
#define PRO_E_TOOL_MOTION_EXIT_ALONG_TOOL_AXIS     5497

#define PRO_E_TOOL_MTN_CL_CMD_GEOM_REF             5498
#define PRO_E_TOOL_MTN_CL_CMD_SRF_OPT              5499
#define PRO_E_TOOL_MTN_CL_CMD_ON_EXIST_PNT         5500

#define PRO_E_MFG_FEAT_VIEW_NAME                   5501
#define PRO_E_MFG_SIMP_REP_NAME                    5502
#define PRO_E_MFG_PROCESS_REF                      5503
#define PRO_E_MFG_TIME_ESTIMATE                    5504
#define PRO_E_MFG_TIME_ACTUAL                      5505
#define PRO_E_MFG_COST_ESTIMATE                    5506

#define PRO_E_SLDBEND_QUILT                        5507
#define PRO_E_SLDBEND_CRVPNTS                      5508
#define PRO_E_SLDBEND_TYPE_OPT                     5509
#define PRO_E_SLDBEND_CHAIN_ARRAY		   5510

#define PRO_E_MFG_WCELL_ASSEM_COMPOUND             5511
#define PRO_E_MFG_WCELL_ASSEMBLY_NAME              5512
#define PRO_E_MFG_WCELL_LOCAL_CSYS_REF             5513

#define PRO_E_SMT_ADD_CORNER_RELIEFS_OPTS          5514
#define PRO_E_SMT_ADD_CORNER_RELIEFS_TYPE          5515

#define PRO_E_FLEX_BOUND_EDGES_CMP                 5516

#define PRO_E_MFG_SURF_SIDE_COMPOUND               5517
#define PRO_E_MFG_SURF_SIDE_TOLERANCE              5518
#define PRO_E_MFG_SURF_SIDE_FLIP_QUILTS            5519

#define PRO_E_OPT_SUBST_SRF_NORM_SIDE              5520

#define PRO_E_MFG_HOLEMAKING_CYCLE_TYPE            5521

#define PRO_E_SMT_RIP_CONNECT_COMP                 5522
#define PRO_E_SMT_RIP_CONN_GAP_COMP_BEG            5523
#define PRO_E_SMT_RIP_CONN_GAP_COMP                5524
#define PRO_E_SMT_RIP_CONN_ADD_GAP                 5525
#define PRO_E_SMT_RIP_CONN_GAP_VAL                 5526

#define PRO_E_PAT_GPRF_GEOM_REFS                   5527

#define PRO_E_SWEEP_TYPE                           5528

/* Acceptance Criteria feature */
#define PRO_E_AC_CONSTRAINTS                       5529

/* Remove surface feature */
#define PRO_E_RM_SURF_LEAVE_OPEN_OPT               5530

#define PRO_E_TOOL_MTN_INH_CLEAR_DIST              5531

#define PRO_E_MFG_DRV_SRF_DIR                      5532

/* Sheet metal unbend feature */
#define PRO_E_SMT_MERGE_SAME_SIDES                 5533

#define PRO_E_PAT_GPRF_DTM_REFS                    5534
#define PRO_E_FLEX_SPLIT_SURFS                     5535
#define PRO_E_FLEX_MAINTAIN_TOPO                   5536

#define PRO_E_HOLESET_START_Z_OFFSET		   5541
#define PRO_E_HOLESET_END_Z_OFFSET		   5542
#define PRO_E_HOLESET_CUSTOM_CYCLE_REF_DEPTH	   5543
#define PRO_E_HOLESET_AUTODRILL_REF_INDEX	   5544
#define PRO_E_HOLESET_PLATE_START_Z_OFFSET	   5545
#define PRO_E_HOLESET_PLATE_END_Z_OFFSET	   5546

/* Sheet metal sketch form feature */

#define PRO_E_SKETCH_FORM_EXCL_SRF_ARR             5547
#define PRO_E_SKETCH_FORM_EXCL_SRF_CMP             5548
#define PRO_E_SKETCH_FORM_EXCL_SRF                 5549

#define PRO_E_SKETCH_FORM_TYPE                     5550
#define PRO_E_SKETCH_FORM_DEPTH_PUNCH              5551
#define PRO_E_SKETCH_FORM_DIR                      5552

/* Xsec feature */
#define PRO_E_XSEC_DTM_CSYS_BEGIN                  5553
#define PRO_E_XSEC_DTM_CSYS_END                    5554
#define PRO_E_XSEC_DTM_FIELD_BEGIN                 5555
#define PRO_E_XSEC_DTM_FIELD_END                   5556
#define PRO_E_XSEC_DTM_PNT_BEGIN                   5557
#define PRO_E_XSEC_DTM_PNT_END                     5558
#define PRO_E_XSEC_DTM_AXIS_BEGIN                  5559
#define PRO_E_XSEC_DTM_AXIS_END                    5560
#define PRO_E_XSEC_DTM_PLN_BEGIN                   5561
#define PRO_E_XSEC_DTM_PLN_END                     5562
#define PRO_E_XSEC_FLIP                            5563
#define PRO_E_XSEC_PLANE                           5564
#define PRO_E_XSEC_SRF_COLOR                       5565
/* Wall Intersect feat */
#define PRO_E_SMT_WALL_JOIN_FLIP                   5566

#define PRO_E_CUTLINE_AUTO_OUTER_OPT               5567
#define PRO_E_CUTLINE_INNER_POINT                  5568


#define PRO_E_SMT_WALL_JOIN_REFS_CMPND             5569
#define PRO_E_SMT_WALL_JOIN_REFS                   5570
#define PRO_E_SMT_WALL_JOIN_REFS_SRF               5571
#define PRO_E_SMT_BEND_RELIEF_CMPND                5572

#define PRO_E_XSEC_FEAT_TYPE                       5573
#define PRO_E_SMT_WALL_JOIN_TRIM                   5574
#define PRO_E_MFG_HELICAL_CUT_OPT                  5575
#define PRO_E_XSEC_LOCK                            5576
#define PRO_E_CUTLINE_INNER_FIRST_OPT              5577
#define PRO_E_COLLAPSE_FEAT_GEOMETRY_OPTS          5578
#define PRO_E_COLLAPSE_FEAT_ATTACH_OPT             5579
#define PRO_E_SKETCH_FORM_DEPTH_PIERCING           5580
#define PRO_E_XSEC_MODEL_REFS_OPT                  5581
#define PRO_E_XSEC_MODEL_REFS_ARR                  5582
#define PRO_E_XSEC_QUILT_REFS_OPT                  5583
#define PRO_E_XSEC_QUILT_REF_SEL                   5584

#define PRO_E_SMT_FLAT_PAT_BBOX_DIMS               5585

#define PRO_E_MFG_TM_TOOL_AXIS_COMPOUND            5586
#define PRO_E_MFG_TM_TOOL_AXIS_OPT                 5587
#define PRO_E_MFG_TM_TOOL_AXIS_REF                 5588
#define PRO_E_MFG_TM_TOOL_AXIS_FLIP_OPT            5589
#define PRO_E_COLLAPSE_FEAT_CPY_GEOMETRY_OPT       5590
#define PRO_E_COLLAPSE_FEAT_MERGE_GMTRY_OPT        5591

#define PRO_E_XSEC_SKETCH_SIDE1                    5592
#define PRO_E_XSEC_SKETCH_SIDE2                    5593


#define PRO_E_COMP_PLACEMENT_OFFSET                5594
#define PRO_E_ECAD_AREA_TRIM_BNDRS                 5595
#define PRO_E_XSEC_INTERFERENCE_COLOR              5596

#define PRO_E_FLXSLV_CONSTRS                       5597
#define PRO_E_FLXSLV_CONSTR                        5598
#define PRO_E_FLXSLV_CONSTR_REFS                   5599
#define PRO_E_FLXSLV_CONSTR_TYPE                   5600
#define PRO_E_FLXSLV_CONSTR_COND                   5601
#define PRO_E_FLXSLV_CONSTR_SYMREF                 5602
#define PRO_E_FLXSLV_CONSTR_DIM1                   5603
#define PRO_E_FLXSLV_CONSTR_DIM2                   5604
#define PRO_E_FLXSLV_ATTACH_LIST_REF               5605

#define PRO_E_HOLESET_GANG_TOOL_INFO               5606
#define PRO_E_HSET_GANG_TOOL_PARENT_ID             5607
#define PRO_E_HSET_IS_GANG_TOOL_LEADER             5608
#define PRO_E_MFG_MILL_THREAD_TAPER_OPT            5609
#define PRO_E_MFG_CUT_START_PNT_REF                5610
#define PRO_E_MFG_FIXTURE_TYPE                     5611

#define PRO_E_FLEX_PROPAGATE_TANGENCY              5612
#define PRO_E_FLEX_DFLT_CONDITIONS                 5613

#define PRO_E_MFG_AXIS_DEF_COMP                    5614
#define PRO_E_MFG_AXIS_DEF_TYPE                    5615
#define PRO_E_MFG_AXIS_DEF_PIVOT_REF               5616
#define PRO_E_MFG_AXIS_DEF_LOCATION_ARR            5617
#define PRO_E_MFG_AXIS_DEF_LOCATION                5618
#define PRO_E_MFG_AXIS_DEF_ORIGIN_REF              5619
#define PRO_E_MFG_AXIS_DEF_ORIENT_COMP             5620
#define PRO_E_MFG_AXIS_DEF_ORIENT_TYPE             5621
#define PRO_E_MFG_AXIS_DEF_ORIENT_REF              5622
#define PRO_E_MFG_AXES_DEF_ANGLE_X                 5623
#define PRO_E_MFG_AXES_DEF_ANGLE_Y                 5624
#define PRO_E_MFG_AXIS_DEF_LOC_FLIP_OPT            5625
#define PRO_E_MFG_AXIS_DEF_CURVE_COMP              5626
#define PRO_E_MFG_AXIS_DEF_SYNC_ARR                5627
#define PRO_E_MFG_AXIS_DEF_SYNC_COMP               5628
#define PRO_E_MFG_AXIS_DEF_SYNC_PNT_1              5629
#define PRO_E_MFG_AXIS_DEF_SYNC_PNT_2              5630
#define PRO_E_MFG_AXIS_DEF_FLIP_OPT                5631
#define PRO_E_MFG_AXIS_DEF_NORM_SRF_COMP           5632
#define PRO_E_ECAD_AREA_COLOR                      5633
#define PRO_E_SMT_WALL_JOIN_EXTEND                 5634
#define PRO_E_MFG_ROUGHING_TYPE                    5635
#define PRO_E_REORDER_SRC_FEAT_REFS                5636
#define PRO_E_REORDER_SRC_FEAT_REF_CMP             5637
#define PRO_E_REORDER_SRC_FEAT_REF                 5638
#define PRO_E_REORDER_INSERT_OPT                   5639
#define PRO_E_REORDER_TRG_FEAT_REF                 5640

#define PRO_E_SPBND_DEPTH                          5641
#define PRO_E_SPBND_UPTO_REF                       5642
#define PRO_E_SPBND_DEPTH_OPT                      5643
#define PRO_E_SPBND_SLD_OPT                        5644
#define PRO_E_SPBND_QUILT                          5645
#define PRO_E_SPBND_XSEC_OPT                       5646
#define PRO_E_SPBND_CTRL_TYPE                      5647
#define PRO_E_SPBND_GRAPH_REF                      5648
#define PRO_E_MFG_TRAJ_FROM_TO_CRV                 5649

#define PRO_E_PAT_GEOM_REFS                        5650
#define PRO_E_PAT_CRV_DTM_REFS                     5651

#define PRO_E_SKIRT_REF_MODEL                      5652
#define PRO_E_SKIRT_PULL_DIR_COMPOUND              5653
#define PRO_E_SKIRT_BOUNDARY_REF                   5654
#define PRO_E_SKIRT_DRAFT_ANGLE                    5656
#define PRO_E_SKIRT_SHUTOFF_EXT_COMPOUND           5657
#define PRO_E_SKIRT_SHUTOFF_EXT_TYPE               5658
#define PRO_E_SKIRT_SHUTOFF_EXT_DIST               5659
#define PRO_E_SKIRT_SHUTOFF_CURVE_COMP             5660
#define PRO_E_SKIRT_SHUTOFF_PLANE_REF              5661
#define PRO_E_SKIRT_FILL_SET_ARR                   5662
#define PRO_E_SKIRT_FILL_SET_COMPOUND              5663
#define PRO_E_SKIRT_FILL_CURVES_COMPOUND           5664
#define PRO_E_SKIRT_FILL_TYPE                      5665
#define PRO_E_SKIRT_FILL_PLANE                     5666
#define PRO_E_SKIRT_FILL_SURF_COMPOUND             5667
#define PRO_E_SKIRT_FILL_LOOP_OFFSET               5668
#define PRO_E_SKIRT_EXT_SET_ARR                    5669
#define PRO_E_SKIRT_EXT_SET_COMPOUND               5670
#define PRO_E_SKIRT_EXT_SET_REF_IDX                5671
#define PRO_E_SKIRT_EXT_SET_TYPE                   5672
#define PRO_E_SKIRT_EXT_SET_CURVE_COMP             5673
#define PRO_E_SKIRT_EXT_SET_DIR_COMPOUND           5674
#define PRO_E_SPBND_APPENDIX                       5675
#define PRO_E_SPBND_CSYS_CMP			   5676

#define PRO_E_CBL_LOC_OVERLAP_VAL                  5677

#define PRO_E_MFG_MILL_WIND_APPR_WALLS             5678
#define PRO_E_MFG_ROUGHING_REF_TYPE                5679
#define PRO_E_MFG_MILL_VOL_COMPOUND                5680
#define PRO_E_MFG_MILL_VOL_REF                     5681
#define PRO_E_MFG_MILL_VOL_TOP_SURF_REF            5682
#define PRO_E_MFG_MILL_VOL_APPR_WALLS              5683
#define PRO_E_MFG_MILL_VOL_EXCL_SRF_COMP           5684
#define PRO_E_SPBND_RELATIONS			   5685
#define PRO_E_SPBND_SECTION                        5686

#define PRO_E_MODRND_DIMENSIONAL_SCHEMA            5687
#define PRO_E_MODRND_DIM2_VAL                      5688
#define PRO_E_MODRND_DIM_REF_SURFACE               5689
#define PRO_E_FLEX_PROP_ALL_TANGENCY               5690
#define PRO_E_FORM_DIE_POCKET_GEOM_CMP             5691

#define PRO_E_MFG_SYNCH_ARR           		   5692
#define PRO_E_MFG_SYNCH_COMP               	   5693
#define PRO_E_MFG_SYNCH_SFT_ID               	   5694
#define PRO_E_MFG_SYNCH_DRV_HEAD_NO   		   5695
#define PRO_E_MFG_SYNCH_HEAD_ARR      		   5696
#define PRO_E_MFG_SYNCH_HEAD_SEQ_COMP      	   5697
#define PRO_E_MFG_SYNCH_HEAD_NO   		   5698
#define PRO_E_MFG_SYNCH_SEQ_ARR       		   5699
#define PRO_E_MFG_SYNCH_SEQ_COMP       		   5700
#define PRO_E_MFG_SYNCH_SEQ			   5701
#define PRO_E_MFG_SYNCH_PNT_ARR           	   5702
#define PRO_E_MFG_SYNCH_PNT_COMP      		   5703
#define PRO_E_MFG_SYNCH_PNT_SFT_ID    		   5704

#define PRO_E_MFG_AXES_DEF_ANGLE_Z                 5705

#define PRO_E_HOLESET_SEL_INDIV_GEOMETRY           5706
#define PRO_E_HOLESET_SEL_UNSEL_GEOMETRY           5707
#define PRO_E_SPBND_CSYS_SECTION                   5708

#define PRO_E_MFG_SUB_SPINDLE_OPT                  5709
#define PRO_E_SUBSP_RETR_SURF                      5710
#define PRO_E_SUBSP_RETR_SURF_TYPE                 5711
#define PRO_E_SUBSP_RETR_SURF_REF                  5712
#define PRO_E_SUBSP_RETR_SURF_ORIENT               5713
#define PRO_E_SUBSP_RETR_SURF_VALUE                5714

#define PRO_E_MFG_SYNCH_PNT_LOC_TYPE		   5715
#define PRO_E_MFG_SYNCH_PNT_PARAM		   5716
#define PRO_E_MFG_SYNCH_MATCH_PNT_ARR	   	   5717
#define PRO_E_MFG_SYNCH_MATCH_PNT_COMP	   	   5718
#define PRO_E_MFG_SYNCH_MATCH_PNT_SFT_ID	   5719
#define PRO_E_MFG_SYNCH_MATCH_SEQ		   5720
#define PRO_E_MFG_SYNCH_MATCH_HEAD_NO		   5721

#define PRO_E_REORDER_INC_DEP_OPT                  5722

#define PRO_E_PAT_ATTACHMENT_OPTS                  5723
#define PRO_E_PAT_ATTACH_OPT                       5724
#define PRO_E_PAT_ROUND_OPT                        5725

#define PRO_E_FLXSLV_PROP_CONSTRS                  5726
#define PRO_E_MFG_AXIS_DEF_NORM_SRF                5727
#define PRO_E_SKIRT_FILL_SET_REF_IDX               5728
#define PRO_E_SPBND_UNBENT_OPT                     5729

#define PRO_E_FLXSLV_ATT_GEOM_TYPE                 5730
#define PRO_E_PAT_MAINTAIN_TOP_OPT                 5731
#define PRO_E_SKIRT_EXT_SET_NEXT_DIR_OPT           5732

#define PRO_E_FLATQLT_SYM_PLANE                    5733
#define PRO_E_FLATQLT_PLACE_OPT                    5734

#define PRO_E_MFG_TRAJ_CORNER_COND                 5735
#define PRO_E_MFG_TRAJ_CORNER_DFLT_TYPE            5736
#define PRO_E_MFG_TRAJ_CORNER_ARR                  5737
#define PRO_E_MFG_TRAJ_CORNER                      5738
#define PRO_E_MFG_TRAJ_CORNER_TYPE                 5739
#define PRO_E_MFG_TRAJ_CORNER_PREV_ID              5740
#define PRO_E_MFG_TRAJ_CORNER_NEXT_ID              5741
#define PRO_E_MFG_TRAJ_CORNER_VAL                  5742

#define PRO_E_FLEX_PULL_OPTION                     5743
#define PRO_E_MODRND_CONIC_OPT                     5744
#define PRO_E_MODRND_CONIC_VAL                     5745

#define PRO_E_SKIRT_CREATE_TRANS_OPT               5746

#define PRO_E_MFG_WIN_VOL_REF_COMPOUND             5748
#define PRO_E_MFG_WIN_VOL_REF                      5749
#define PRO_E_MFG_WIN_VOL_EXCL_SURF_COMP           5750
#define PRO_E_MFG_APPR_WALLS_SURF_COMP             5751
#define PRO_E_MFG_APPR_WALLS_CHAIN_COMP            5752

#define PRO_E_MFG_AXIS_DEF_SYNC_FLIP_OPT           5753
#define PRO_E_MFG_AXDEF_NORM_SURF_DIR              5755

#define PRO_E_PIPE_TO_POINTS                       5756
#define PRO_E_PIPE_TO_POINT                        5757

#define PRO_E_MFG_AXIS_DEF_SYNC_PARAM_1_OPT        5758
#define PRO_E_MFG_AXIS_DEF_SYNC_PARAM_2_OPT        5759

#define PRO_E_MFG_AXIS_DEF_LOC_ALIGN_Z             5760

#define PRO_E_ER_UBF_ADJUSTMENTS                   5761
#define PRO_E_ER_UBF_ADJUSTMENT                    5762

#define PRO_E_CMP_RNDCHMREC_REM                    5763
#define PRO_E_RNDCHREC_RND                         5764
#define PRO_E_RNDCHREC_ANG_NUM                     5765
#define PRO_E_RNDCHREC_LIN_DIM                     5766
#define PRO_E_RNDCHREC_RHO_NUM                     5767

#define PRO_E_VOL_MILL_REGION_ARR                  5768
#define PRO_E_VOL_MILL_REGION                      5769
#define PRO_E_VOL_MILL_REGION_IDX                  5770
#define PRO_E_VOL_MILL_REGION_SKIP_OPT             5771

#define PRO_E_MFG_WCELL_HEAD_3                     5772
#define PRO_E_MFG_WCELL_HEAD_4                     5773
#define PRO_E_MFG_FROM3_PNT                        5774
#define PRO_E_MFG_HOME3_PNT                        5775
#define PRO_E_MFG_FROM4_PNT                        5776
#define PRO_E_MFG_HOME4_PNT                        5777

#define PRO_E_SPBND_LOCK_LENGTH_OPT                5778

#define PRO_E_VOL_MILL_AP_EX_ARR                   5779
#define PRO_E_VOL_MILL_AP_EX_TYPE                  5780
#define PRO_E_VOL_MILL_AP_EX                       5781
#define PRO_E_VOL_MILL_AP_EX_REGION_IDX            5782
#define PRO_E_VOL_MILL_AP_EX_REF                   5783
#define PRO_E_VOL_MILL_AP_REF                      5784
#define PRO_E_VOL_MILL_EX_REF                      5785

#define PRO_E_AXIS_DEF_DRV_SRF_COMP                5786

#define PRO_E_RNDCHREC_RND_REC_SRF_CMP             5787
#define PRO_E_RNDCHREC_RND_REM_SRF_CMP             5788
#define PRO_E_RNDCHREC_CHM_REC_SRF_CMP             5789
#define PRO_E_RNDCHREC_CHM_REM_SRF_CMP             5790

#define PRO_E_CUTLINE_AUTO_OUTER_FLIP              5791

#define PRO_E_SMT_FLATTEN_FORM_WALLS               5792
#define PRO_E_FLEX_TRF_SEL_ATT_GEOM                5793

#define PRO_E_TRAV_SURF                            5794
#define PRO_E_TRAV_SURF_REF                        5795
#define PRO_E_TRAV_SURF_VALUE                      5796
#define PRO_E_SWPBLN_ADJUST_TANGENCY               5797
#define PRO_E_RM_SURF_LIMIT_SOLN_OPT               5798
#define PRO_E_GMRG_COPY_QUILTS                     5799
#define PRO_E_RM_SURF_MAINTAIN_TOPO                5800

#define PRO_E_SURFS_REF_SEQ                        5801
#define PRO_E_SURFS_REF_SEQ_NAME                   5802

#define PRO_E_TURN_STK_ALLW_PROF_ARR               5810
#define PRO_E_TURN_STK_ALLW_ROUGH_ARR              5811
#define PRO_E_TURN_STK_ALLOWANCE                   5812
#define PRO_E_TURN_STK_ALLW_FIRST_ENT_ID           5813
#define PRO_E_TURN_STK_ALLW_LAST_ENT_ID            5814
#define PRO_E_TURN_STK_ALLOWANCE_VAL               5815

#define PRO_E_DRLGRP_HOLES                         5816
#define PRO_E_BBL_VARI_RECALC                      5817
#define PRO_E_BBL_HDS_CONTROL                      5818
#define PRO_E_ECAD_AREA_USER_DEF_TYPE              5819

#define PRO_E_STD_PIPE_LINE_ENV                    5820
#define PRO_E_STD_PIPE_LINE_ID                     5821
#define PRO_E_STD_PIPE_LINE_LNSTK                  5822
#define PRO_E_STD_PIPE_LINE_CORNER_TYPE            5823
#define PRO_E_STD_PIPE_LINE_BEND_RAD               5824
#define PRO_E_STD_PIPE_LINE_MITER_NUM              5825
#define PRO_E_STD_PIPE_LINE_MITER_LEN              5826


#define PRO_E_MFG_CONVENTIONAL_CUT_COMP            5840
#define PRO_E_MFG_CONV_CUT_DIR_OPT                 5841
#define PRO_E_MFG_CONV_CUT_DIR_REF_COMP            5842
#define PRO_E_MFG_CONV_CUT_DIR_REF                 5843
#define PRO_E_MFG_CONV_CUT_DIR_FLIP_OPT            5844

/* Thin ExtRev Feats */
#define PRO_E_FEAT_THIN                            5845
#define PRO_E_FEAT_THIN_STRT                       5846
#define PRO_E_FEAT_THIN_STRT_OPT                   5847
#define PRO_E_FEAT_THIN_STRT_REF                   5848
#define PRO_E_FEAT_THIN_END                        5849
#define PRO_E_FEAT_THIN_END_OPT                    5850
#define PRO_E_FEAT_THIN_END_REF                    5851

#define PRO_E_SMT_TWIST_ATT_EDGE                   5860
#define PRO_E_SMT_TWIST_TYPE                       5861
#define PRO_E_SMT_TWIST_TRIM_EDGES                 5862
#define PRO_E_SMT_TWIST_SIDE_1_OFFSET              5863
#define PRO_E_SMT_TWIST_OFFSET_TYPE                5864
#define PRO_E_SMT_TWIST_OFFSET_VAL                 5865
#define PRO_E_SMT_TWIST_SIDE_2_OFFSET              5866
#define PRO_E_SMT_TWIST_AXIS_POINT                 5867
#define PRO_E_SMT_TWIST_START_WIDTH_VAL            5868
#define PRO_E_SMT_TWIST_ATT_POINT_REF              5869
#define PRO_E_SMT_TWIST_ANGLE_VAL                  5870
#define PRO_E_SMT_TWIST_WALL_LENGTH_VAL            5871
#define PRO_E_SMT_TWIST_END_WIDTH                  5872
#define PRO_E_SMT_TWIST_END_WIDTH_TYPE             5873
#define PRO_E_SMT_TWIST_END_WIDTH_VAL              5874
#define PRO_E_SMT_TWIST_DEV_LEN_VAL                5875
#define PRO_E_SMT_TWIST_POINT_TYPE                 5876

/* Pro/MECHANISM motor elements */
#define PRO_E_MOTOR_MOTION_TYPE                    5877
#define PRO_E_MOTOR_DRIVEN_ENT_REF                 5878
#define PRO_E_MOTOR_GEOM_REF_DATA                  5879
#define PRO_E_MOTOR_REF_ENT                        5880
#define PRO_E_MOTOR_FLIP_DIR                       5881
#define PRO_E_MOTOR_PROFILE                        5882
#define PRO_E_MOTOR_DRIVEN_QUANTITY                5883
#define PRO_E_MOTOR_INIT_STATE_DATA                5884
#define PRO_E_MOTOR_USE_CURR_POS                   5885
#define PRO_E_MOTOR_INIT_POS                       5886
#define PRO_E_MOTOR_INIT_VEL                       5887
#define PRO_E_MOTOR_FUNC_TYPE                      5888
#define PRO_E_MOTOR_PRIM_VAR                       5889
#define PRO_E_MOTOR_FUNC_COEFF_A                   5890
#define PRO_E_MOTOR_FUNC_COEFF_B                   5891
#define PRO_E_MOTOR_FUNC_COEFF_C                   5892
#define PRO_E_MOTOR_FUNC_COEFF_D                   5893
#define PRO_E_MOTOR_FUNC_COEFF_L                   5894
#define PRO_E_MOTOR_FUNC_COEFF_H                   5895
#define PRO_E_MOTOR_FUNC_COEFF_T                   5896
#define PRO_E_MOTOR_TABLE_DATA                     5897
#define PRO_E_MOTOR_TBL_INTERPOL_TYPE              5898
#define PRO_E_MOTOR_TBL_ROWS                       5899
#define PRO_E_MOTOR_TBL_ROW                        5900
#define PRO_E_MOTOR_TBL_VAR_VAL                    5901
#define PRO_E_MOTOR_TBL_FUNC_VAL                   5902
#define PRO_E_MOTOR_TBL_DERIV_GIVEN                5903
#define PRO_E_MOTOR_TBL_DERIV_VAL                  5904
#define PRO_E_MOTOR_TBL_FILE_DATA                  5905
#define PRO_E_MOTOR_TBL_DEPEND_ON_FILE             5906
#define PRO_E_MOTOR_TBL_FILE_NAME                  5907
#define PRO_E_MOTOR_UD_PROFILE_DATA                5908
#define PRO_E_MOTOR_UD_EXPR_ARR                    5909
#define PRO_E_MOTOR_UD_EXPR_DATA                   5910
#define PRO_E_MOTOR_UD_EXPR                        5911
#define PRO_E_MOTOR_UD_DOM_TYPE                    5912
#define PRO_E_MOTOR_UD_DOM_LOWER_BOUND             5913
#define PRO_E_MOTOR_UD_DOM_UPPER_BOUND             5914
#define PRO_E_MOTOR_CUST_LOAD_NAME                 5915

#define PRO_E_SMT_BND_RLF_RCG                      5916
#define PRO_E_SMT_PIO_SCOPE                        5917

#define PRO_E_MOLD_CUTOUT_WP_COMP                  5920
#define PRO_E_MOLD_CUTOUT_WP_REF                   5921
#define PRO_E_MOLD_CUTOUT_REFPART_COMP             5922
#define PRO_E_MOLD_CUTOUT_ALL_PARTS_OPT            5923
#define PRO_E_MOLD_CUTOUT_REFPART_REF              5924
#define PRO_E_MOLD_CUTOUT_ALL_WP_OPT               5925

#define PRO_E_MOLD_SPLIT_VOL_REF                   5930
#define PRO_E_MOLD_SPLIT_SURF_REF                  5931
#define PRO_E_MOLD_SPLIT_GEOM_OPT                  5932
#define PRO_E_MOLD_SPLIT_VOLUME_ARR                5933
#define PRO_E_MOLD_SPLIT_VOLUME_COMP               5934
#define PRO_E_MOLD_SPLIT_VOLUME_KEY                5935
#define PRO_E_MOLD_SPLIT_VOLUME_NAME               5936

#define PRO_E_PRTSPLIT_MODEL_SURF_COMP             5940
#define PRO_E_PRTSPLIT_SURF_FLIP_OPT               5941
#define PRO_E_PRTSPLIT_PULLDIR_COMP                5942
#define PRO_E_PRTSPLIT_VERT_FACE_OPT               5943
#define PRO_E_PRTSPLIT_CORE_SURF_COMP              5944
#define PRO_E_PRTSPLIT_CAVITY_SURF_COMP            5945
#define PRO_E_PRTSPLIT_UNDERCUT_SURF_COMP          5946

/*ECAD Cuts feat*/
#define PRO_E_ECAD_CUTS_FT_TYPE                    5947
#define PRO_E_ECAD_CUTS_OBJ_ARRAY                  5948
#define PRO_E_ECAD_CUT_OBJ                         5949
#define PRO_E_TOOL_RS_GEN_GAP_SEG_SEL              5950
#define PRO_E_TOOL_RS_GEN_GAP_DIM                  5951

#define PRO_E_MOLD_SILH_SRF                        5952
#define PRO_E_MOLD_SILH_DIR                        5953
#define PRO_E_MOLD_SILH_SLIDES                     5954
#define PRO_E_MOLD_SILH_SLIDE_PARTS                5955
#define PRO_E_MOLD_SILH_SLIDE_PART                 5956
#define PRO_E_MOLD_SILH_SLIDE_PART_REF             5957
#define PRO_E_MOLD_SILH_SLIDE_VOLS                 5958
#define PRO_E_MOLD_SILH_SLIDE_VOL                  5959
#define PRO_E_MOLD_SILH_SLIDE_VOL_REF              5960
#define PRO_E_MOLD_SILH_GAP_CLOSURE                5961
#define PRO_E_MOLD_SILH_GAP_CLOSURE_GTYPE          5962
#define PRO_E_MOLD_SILH_GAP_CLOSURE_ITEMS          5963
#define PRO_E_MOLD_SILH_GAP_CLOSURE_ITEM           5964
#define PRO_E_MOLD_SILH_GAP_CLOSURE_REF            5965
#define PRO_E_MOLD_SILH_GAP_CLOSURE_TYPE           5966
#define PRO_E_MOLD_SILH_GAP_CLOSURE_IDX            5967
#define PRO_E_MOLD_SILH_LOOPS                      5968
#define PRO_E_MOLD_SILH_LOOP_GTYPE                 5969
#define PRO_E_MOLD_SILH_CHAIN_GTYPE                5970
#define PRO_E_MOLD_SILH_LOOP_SELECTIONS            5971
#define PRO_E_MOLD_SILH_LOOP_SELECTION             5972
#define PRO_E_MOLD_SILH_LOOP_SEL                   5973
#define PRO_E_MOLD_SILH_LOOP_TYPE                  5974
#define PRO_E_MOLD_SILH_LOOP_ID2                   5975
#define PRO_E_MOLD_SILH_LOOP_ID2_2                 5976
#define PRO_E_MOLD_SILH_CHAIN_SELECTIONS           5977
#define PRO_E_MOLD_SILH_CHAIN_SELECTION            5978
#define PRO_E_MOLD_SILH_CHAIN_SEL                  5979
#define PRO_E_MOLD_SILH_CHAIN_TYPE                 5980
#define PRO_E_MOLD_SILH_CHAIN_ID2                  5981
#define PRO_E_MOLD_SILH_CHAIN_ID2_2                5982
#define PRO_E_MOLD_SILH_IS_CHAIN                   5983

#define PRO_E_PAT_MFG_SUB_OUTPUT                   5984
#define PRO_E_PAT_MFG_SUB_OUT_MODE                 5985
#define PRO_E_PAT_MFG_SUB_OUT_MULTAX               5986
#define PRO_E_WELD_DISP_SEQ_ID                     5987

#define PRO_E_SMT_CRN_RLF_RCG                      5988
#define PRO_E_SMT_BEND_RCG                         5989
#define PRO_E_SMT_CRN_SEAM_RCG                    5990
#define PRO_E_SMT_FORM_RCG                         5991
#define PRO_E_SMT_BND_RLF_UNRCG                    5992
#define PRO_E_SMT_CRN_RLF_UNRCG                    5993
#define PRO_E_SMT_BEND_UNRCG                       5994
#define PRO_E_SMT_CRN_SEAM_UNRCG                  5995
#define PRO_E_SMT_FORM_UNRCG                       5996
#define PRO_E_SMT_RECOGNITION_SEL_TYPE             5997
#define PRO_E_SMT_EDGE_RIP_CLOSE_CORNER            5998

#define PRO_E_PRTSPLIT_SPLIT_SURF_OPT              6001
#define PRO_E_PRTSPLIT_CAVITY_COMP                 6002
#define PRO_E_PRTSPLIT_CORE_COMP                   6003
#define PRO_E_PRTSPLIT_SLIDER_QLT_ARR              6004
#define PRO_E_PRTSPLIT_QUILT_COMP                  6005
#define PRO_E_PRTSPLIT_QUILT_KEY                   6006
#define PRO_E_PRTSPLIT_QUILT_TYPE                  6007
#define PRO_E_PRTSPLIT_QUILT_NAME                  6008
#define PRO_E_DRAFT_KEEP_ORIG                      6009

#define PRO_E_SHAPEVOL_VOLUME_REF                  6010
#define PRO_E_SHAPEVOL_PARTING_SURF_REF            6011
#define PRO_E_EXT_DEPTH_FROM_REF_TRF               6012
#define PRO_E_EXT_DEPTH_TO_REF_TRF                 6013
#define PRO_E_EXT_DEPTH_FROM_REF_TRF_VAL           6014
#define PRO_E_EXT_DEPTH_TO_REF_TRF_VAL             6015

#define PRO_E_FLEXMOVE_MOVED_COMPS                 6016
#define PRO_E_WLDCMB_OPTIONS                       6017

#define PRO_E_LATTICE_TYPE                         6018
#define PRO_E_LATTICE_PROPAGATION_TYPE             6019
#define PRO_E_LATTICE_GEOM_REP                     6020
#define PRO_E_LATTICE_SEED_LOCATION                6021
#define PRO_E_LATTICE_CELL_NUMBER                  6022
#define PRO_E_LATTICE_PATCH_OPEN_AREA              6023
#define PRO_E_LATTICE_CELL_TYPE                    6024
#define PRO_E_LATTICE_REGULAR_SHAPE                6025
#define PRO_E_LATTICE_X_SCALE                      6026
#define PRO_E_LATTICE_Y_SCALE                      6027
#define PRO_E_LATTICE_Z_SCALE                      6028
#define PRO_E_LATTICE_SKEWING_ANGLE                6029
#define PRO_E_LATTICE_RND_CONCAVE_EDGE             6030
#define PRO_E_LATTICE_ROUND_RADIUS                 6031
#define PRO_E_LATTICE_INNER_HORIZ_BEAM             6032
#define PRO_E_LATTICE_INNER_VERT_BEAM              6033
#define PRO_E_LATTICE_OUTER_HORIZ_BEAM             6034
#define PRO_E_LATTICE_OUTER_VERT_BEAM              6035
#define PRO_E_LATTICE_ANGULAR_BEAM                 6036
#define PRO_E_LATTICE_BALL_ON_BEAM                 6037
#define PRO_E_LATTICE_BALL_DIAMETER                6038
#define PRO_E_LATTICE_RMV_DANGLE_BEAM              6039
#define PRO_E_LATTICE_WALL_THICKNESS               6040
#define PRO_E_LATTICE_ADD_DRAIN_HOLE               6041
#define PRO_E_LATTICE_DRAIN_HOLE_DIAMETE           6042
#define PRO_E_LATTICE_DRAIN_HOLE_LENGTH            6043
#define PRO_E_LATTICE_DRAIN_HOLE_SPACING           6044
#define PRO_E_LATTICE_XSEC_TYPE                    6045
#define PRO_E_LATTICE_XSEC_SIZE                    6046
#define PRO_E_LATTICE_PROFILE_TYPE                 6047
#define PRO_E_LATTICE_PARABOLIC_RADIUS             6048
#define PRO_E_LATTICE_PROFILE_COEFF                6049

#define PRO_E_HLE_UV_PARAM                         6050
#define PRO_E_HLE_FT_DIR_REF                       6051
#define PRO_E_HLE_FT_DIR_OPT                       6052
#define PRO_E_HLE_TOP_CLEARANCE                    6053
#define PRO_E_HLE_FOLLOW_AXIS_OPT                  6054
#define PRO_E_EDIT_BEND_RELIEF                     6055
#define PRO_E_EDIT_BEND_RELIEF_SEL_MODE            6056
#define PRO_E_EDIT_BEND_RELIEF_GEOMS               6057
#define PRO_E_EDIT_BEND_RELIEF_SHAPE               6058
#define PRO_E_EDIT_BEND_RELIEF_TABLE               6059
#define PRO_E_BEND_RELIEF_RMV_SETTINGS             6060
#define PRO_E_BEND_RELIEF_RMV_SIDES                6061
#define PRO_E_BEND_RELIEF_RMV_DEFAULT              6062
#define PRO_E_BEND_RELIEF_RMV_METHOD               6063
#define PRO_E_BEND_RELIEF_RMV_REF_TYPE             6064
#define PRO_E_EDIT_CORNER_RELIEF                   6065
#define PRO_E_EDIT_CORNER_RELIEF_SEL_OPT           6066
#define PRO_E_EDIT_CORNER_RELIEF_GEOMS             6067
#define PRO_E_EDIT_CORNER_RELIEF_TABLE             6068
#define PRO_E_EDIT_CORNER_RELEIF_RMV               6069
#define PRO_E_EDIT_CORNER_RELEIF_BOUND             6070

#define PRO_E_LATTICE_CONVERT_SOLID                6071
#define PRO_E_LATTICE_TRIM_BOUNDARY                6072
#define PRO_E_LATTICE_MAX_BEAM_LENGTH              6073
#define PRO_E_LATTICE_MIN_BEAM_LENGTH              6074
#define PRO_E_LATTICE_MESH_TYPE                    6075
#define PRO_E_LATTICE_BOUND_TYPE                   6076
#define PRO_E_MOLD_INS_REFSRFS_CMP                 6077
#define PRO_E_MOLD_INS_CSYS                        6078
#define PRO_E_MOLD_INS_SHAPE_OPT                   6079
#define PRO_E_MOLD_INS_SIZE_OPT                    6080
#define PRO_E_MOLD_INS_OFFSET                      6081
#define PRO_E_MOLD_INS_BILLET_OFF_ARR              6082
#define PRO_E_MOLD_INS_BILLET_OFF_SET              6083
#define PRO_E_MOLD_INS_X_POS                       6084
#define PRO_E_MOLD_INS_X_NEG                       6085
#define PRO_E_MOLD_INS_Y_POS                       6086
#define PRO_E_MOLD_INS_Y_NEG                       6087
#define PRO_E_MOLD_INS_Z_POS                       6088
#define PRO_E_MOLD_INS_Z_NEG                       6089
#define PRO_E_MOLD_INS_BAR_OFF_ARR                 6090
#define PRO_E_MOLD_INS_BAR_OFF_SET                 6091
#define PRO_E_MOLD_INS_DIA_POS                     6092
#define PRO_E_MOLD_INS_LEN_POS                     6093
#define PRO_E_MOLD_INS_LEN_NEG                     6094
#define PRO_E_MOLD_INS_BILLET_SIZ_ARR              6095
#define PRO_E_MOLD_INS_BILLET_SIZ_SET              6096
#define PRO_E_MOLD_INS_X_TOT                       6097
#define PRO_E_MOLD_INS_Y_TOT                       6098
#define PRO_E_MOLD_INS_Z_TOT                       6099
#define PRO_E_MOLD_INS_BAR_SIZ_ARR                 6100
#define PRO_E_MOLD_INS_BAR_SIZ_SET                 6101
#define PRO_E_MOLD_INS_DIA_TOT                     6102
#define PRO_E_MOLD_INS_LEN_TOT                     6103
#define PRO_E_MOLD_INS_ROT_ARR                     6104
#define PRO_E_MOLD_INS_ROT_SET                     6105
#define PRO_E_MOLD_INS_X_ROT                       6106
#define PRO_E_MOLD_INS_Y_ROT                       6107
#define PRO_E_MOLD_INS_Z_ROT                       6108

#define PRO_E_TIEWRAP_LOC_REF                      6109
#define PRO_E_TIEWRAP_CABLE_REF                    6110
#define PRO_E_TIEWRAP_OPTION                       6111
#define PRO_E_TIEWRAP_LIB                          6112
#define PRO_E_TIEWRAP_INFO                         6113
#define PRO_E_TIEWRAP_DISTANCE                     6114
#define PRO_E_TIEWRAP_WIDTH                        6115
#define PRO_E_TIEWRAP_LENGTH                       6116
#define PRO_E_TIEWRAP_THICK                        6117

/* Marker feat*/
#define PRO_E_REF_MAIN_SEG                         6118
#define PRO_E_REF_MARKER_ALL_SEG                   6119
#define PRO_E_MARKER_OPT_COMP                      6120
#define PRO_E_OPT_MARKER_OFFSET                    6121
#define PRO_E_REF_MARKER_PNT_LOC                   6122
#define PRO_E_MARKER_DISTANCE                      6123
#define PRO_E_INT_MARKER_END_OFFSET_REF            6124
#define PRO_E_CMP_MARKER_PROP                      6125
#define PRO_E_DBL_MARKER_LENGTH                    6126
#define PRO_E_MARKERS_THICKNESS                    6127
#define PRO_E_DBL_MARKER_EXP                       6128
#define PRO_E_DBL_MARKER_REDU                      6129
#define PRO_E_ECAD_CUT_OBJ_TYPE                    6130
#define PRO_E_ECAD_CUTS_SRF_REF                    6131
#define PRO_E_BEND_RELIEF_VERTEX                   6132

/* Datum Csys Display Elements */
#define PRO_E_CSYS_NAME_DISPLAY_OPT                6133
#define PRO_E_CSYS_NAME_DISPLAY_PLN                6134
#define PRO_E_CSYS_NAME_DISPLAY_PNT_OFFSET         6135
#define PRO_E_CSYS_NAME_DISPLAY_PNT_OFFSET_X       6136
#define PRO_E_CSYS_NAME_DISPLAY_PNT_OFFSET_Y       6137
#define PRO_E_CSYS_NAME_DISPLAY_PNT_OFFSET_Z       6138
#define PRO_E_CSYS_AXIS_LENGTH                     6139
#define PRO_E_CSYS_DISPLAY_ZOOM_DEP_OPT            6140

#define PRO_E_EDIT_CORNER_SEAM                     6141
#define PRO_E_EDIT_CORNER_SEAM_SEL_MODE            6142
#define PRO_E_EDIT_CORNER_SEAM_GEOMS               6143
#define PRO_E_REMOVE_CORNER_SEAM                   6144
#define PRO_E_EDIT_CORNER_SEAM_SHAPE               6145
#define PRO_E_SMT_EDGE_RIP_GAP                     6146
#define PRO_E_EDIT_CORNER_SEAM_TABLE               6147
#define PRO_E_CORNER_SEAM_RMV_SETTINGS             6148
#define PRO_E_EDIT_CORNER_SEAM_RMV_REFS            6149
#define PRO_E_CORNER_SEAM_RMV_FLAT                 6150
#define PRO_E_CORNER_SEAM_RMV_BEND_1               6151
#define PRO_E_CORNER_SEAM_RMV_BEND_2               6152
#define PRO_E_CORNER_SEAM_RMV_SIDE_1               6153
#define PRO_E_CORNER_SEAM_RMV_DEFAUT               6154
#define PRO_E_CORNER_SEAM_RMV_METHOD               6155
#define PRO_E_CORNER_SEAM_RMV_SIDE_2               6156
#define PRO_E_CORNER_SEAM_BOUNDARIES               6157

#define PRO_E_SWEEP_3D_CONTAINER                   6158
#define PRO_E_SWEEP_2D3D                           6159
#define PRO_E_SWEEP_3D_ADJUSTMENTS                 6160
#define PRO_E_SWEEP_3D_ADJUSTMENT_HOLDER           6161
#define PRO_E_SWEEP_3D_ADJUSTMENT_VAL              6162
#define PRO_E_SWEEP_3D_USE_START_ADJ_REF           6163
#define PRO_E_SWEEP_3D_USE_END_ADJ_REF             6164
#define PRO_E_SWEEP_3D_ADJUSTMENT_REF_START        6165
#define PRO_E_SWEEP_3D_ADJUSTMENT_REF_END          6166

#define PRO_E_FLXSUBST_METHOD                      6167
#define PRO_E_FLXSUBST_CAPLOOPS                    6168
#define PRO_E_RM_SURF_AUTO_SPLIT_SRF               6169
#define PRO_E_SHAPEVOL_SURF_FLIP_OPT               6170
#define PRO_E_FLXSUBST_EDGELOOPS                   6171

#define PRO_E_LATTICE_KEEP_SHELL                   6172
#define PRO_E_LATTICE_THICKNESS                    6173
#define PRO_E_LATTICE_SHELL_SIDE                   6174

#define PRO_E_TOOL_RS_GEN_GAP_REMOVE               6175
#define PRO_E_TOOL_RS_GEN_ENABLE_CONN              6176
#define PRO_E_TOOL_RS_GEN_ENABLE_ROTATE            6177
#define PRO_E_TOOL_RS_GEN_AUTO_BRAN_EXC            6178
#define PRO_E_ECAD_CUT_OBJ_REF                     6179

#define PRO_E_LATTICE_EXCL_SRFS                    6180
#define PRO_E_LATTICE_ATTACH_SIDE           	   6181
#define PRO_E_WELD_IDENT_LINE                      6182
#define PRO_E_WELD_IDENT_LINE_POS                  6183
#define PRO_E_LATTICE_BNDSRFS_FLIPS                6184

/* non-standard direction elems for geometric force motors (forces/torques) */
#define PRO_E_MOTOR_DIR_MODE                       6185
#define PRO_E_MOTOR_VEC_DIR_DATA                   6186
#define PRO_E_MOTOR_VEC_DIR_CSYS                   6187
#define PRO_E_MOTOR_VEC_DIR_X                      6188
#define PRO_E_MOTOR_VEC_DIR_Y                      6189
#define PRO_E_MOTOR_VEC_DIR_Z                      6190
#define PRO_E_MOTOR_PT_TO_PT_DIR                   6191
#define PRO_E_MOTOR_DIR_RELATIVITY                 6192

#define PRO_E_SENSOR_MODE                          6193
#define PRO_E_SENSOR_DATA_SOURCE                   6194

#define PRO_E_LATTICE_MC_SETS                      6195
#define PRO_E_LATTICE_MC_SET                       6196
#define PRO_E_LATTICE_MC_REFS                      6197
#define PRO_E_LATTICE_MC_USE_GLOBAL                6198
#define PRO_E_LATTICE_MC_MAX_VALUE                 6199
#define PRO_E_LATTICE_MC_MIN_VALUE                 6200
#define PRO_E_EDIT_BEND                            6201
#define PRO_E_EDIT_BEND_SEL_MODE                   6202
#define PRO_E_EDIT_BEND_GEOMS                      6203
#define PRO_E_EDIT_BEND_DEFINITION                 6204
#define PRO_E_EDIT_BEND_REMOVE                     6205
#define PRO_E_EDIT_BEND_REMOVE_RLF                 6206
#define PRO_E_EDIT_BEND_ANCH_BND_APEX              6207
#define PRO_E_EDIT_BEND_OPTS                       6208
#define PRO_E_EDIT_BEND_ADJ_COND                   6209
#define PRO_E_EDIT_BEND_RCR_BND_RLF                6210
#define PRO_E_EDIT_BEND_BND_RLF_OPTS               6211
#define PRO_E_EDIT_BEND_RCR_CRNR                   6212
#define PRO_E_EDIT_BEND_CRNR_RLF_OPTS              6213
#define PRO_E_EDIT_BEND_CRNR_SEAMS_OPTS            6214

#define PRO_E_FUNC_FEATURE_SCHEMA                  6215
#define PRO_E_FUNC_FEATURE_ID                      6216
#define PRO_E_FUNC_FEATURE_TYPE                    6217
#define PRO_E_FUNC_FEATURE_SURFS                   6218
#define PRO_E_FUNC_FEATURE_SURF                    6219
#define PRO_E_FUNC_FEATURE_ANNOTS                  6220
#define PRO_E_FUNC_FEATURE_ANNOT                   6221
#define PRO_E_FUNC_FEATURE_ANNOT_ID                6222
#define PRO_E_FUNC_FEATURE_ANNOT_TYPE              6223
#define PRO_E_DRF_AES                              6224
#define PRO_E_DRF_AE                               6225
#define PRO_E_DRF_AE_ID                            6226
#define PRO_E_DRF_AE_TYPE                          6227
#define PRO_E_LINKED_FUNC_AES                      6228
#define PRO_E_LINKED_FUNC_AE                       6229
#define PRO_E_LINKED_FUNC_AE_ID                    6230
/* Sensor Feature Elements */
#define PRO_E_SENSOR_PARAMS_ARR                    6231
#define PRO_E_SENSOR_PARAM                         6232
#define PRO_E_SENSOR_PARAM_VALUE                   6233
#define PRO_E_WSTRING_MARKER_DSGNTLBL	           6234

/* New mirror reapply transformation */
#define PRO_E_GROUP_REAPPLY_TRF                    6235

#define PRO_E_PULL_WALL                            6236
#define PRO_E_PULL_WALL_GEOMS                      6237
#define PRO_E_PULL_WALL_DEFINITION                 6238
#define PRO_E_PULL_WALL_DIST                       6239
#define PRO_E_PULL_WALL_EXT_BOUND_SIDES            6240
#define PRO_E_PULL_WALL_CUT_N_FORM_SRF             6241
#define PRO_E_PULL_WALL_DIST_DIR                   6242
#define PRO_E_EDIT_BEND_RCR_CRNR_SEAM              6243

#define PRO_E_WELD_OTHER_SIDE_SYMB                 6244
#define PRO_E_WELD_NEXT_LEADER_OPT                 6245
#define PRO_E_WELD_NEXT_LEADER_REF                 6246

/* Motor elements for interaction with series params */
#define PRO_E_MOTOR_TBL_DEPEND_ON_SERIES           6247
#define PRO_E_MOTOR_TBL_SERIES_NAME                6248

#define PRO_E_LATTICE_EXCL_BDY_SRFS                6249
#define PRO_E_LATTICE_MESH_TYPE2                   6250
#define PRO_E_LATTICE_Z_ORIENTATION                6251
#define PRO_E_LATTICE_XSEC_SETS                    6252
#define PRO_E_LATTICE_XSEC_SET                     6253
#define PRO_E_LATTICE_XSEC_REFS                    6254
#define PRO_E_LATTICE_XSEC_RANGE                   6256
#define PRO_E_LATTICE_XSEC_LOCALSIZE               6257
#define PRO_E_LATTICE_SCALE                        6258

#define PRO_E_SMT_FORM_BOUND_REFS		               6259
#define PRO_E_SMT_RCG_FORM_AS_ONE                  6260
#define PRO_E_TOOL_RS_GEN_SINGLE_MOVE              6261
#define PRO_E_FUNC_AE_NAME                         6262
#define PRO_E_LATTICE_XSEC_TAPERED                 6263

#define PRO_E_LATTICE_XSEC_FACTOR                  6264
#define PRO_E_LATTICE_CUTOFF_SIZE                  6265

#define PRO_E_OPT_ATTACH_PIO                       6266
#define PRO_E_OPT_ATTACH_RNDCH                     6267

#define PRO_E_PRTSPLIT_TRANS_SURF_OPT              6268
#define PRO_E_LATTICE_RMV_FAILED_GEOM              6269

#define PRO_E_WELD_GR_BACK_SIZE                    6270
#define PRO_E_WELD_GR_BACK_SIZE_OPT                6271
#define PRO_E_WELD_GR_BACK_SIZE_VAL                6272
#define PRO_E_PAT_MFG_SUB_OUT_COPYCL               6273

#define PRO_E_TMCOMP_PLC_TYPE                      6274
#define PRO_E_TMCOMP_PLC_ORIG                      6275
#define PRO_E_TMCOMP_SCALE                         6276

/* Sensor Feature Element */
#define PRO_E_SENSOR_DISPLAY_PLACE                 6277

       



/* Maximum limit for elements that are hashed for quick retrieval.
   This value need not be changed when new elements are added for
   ODUI 19 */
#define MAX_ELEM_HASH 1250

/* Reserved RTFEAT elem ids */
#define PRO_E_RTFEAT_OPT_ELEMS                     30000
#define PRO_E_RTFEAT_INT_ELEMS                     30050
#define PRO_E_RTFEAT_DBL_ELEMS                     30100
#define   PRO_E_RTFEAT_DBL_ELEM_1                  30101
#define   PRO_E_RTFEAT_DBL_ELEM_2                  30102
#define   PRO_E_RTFEAT_DBL_ELEM_3                  30103
#define   PRO_E_RTFEAT_DBL_ELEM_4                  30104
#define   PRO_E_RTFEAT_DBL_ELEM_5                  30105
#define   PRO_E_RTFEAT_DBL_ELEM_6                  30106
#define   PRO_E_RTFEAT_DBL_ELEM_7                  30107
#define   PRO_E_RTFEAT_DBL_ELEM_8                  30108
#define   PRO_E_RTFEAT_DBL_ELEM_9                  30109
#define   PRO_E_RTFEAT_DBL_ELEM_10                 30110
#define PRO_E_RTFEAT_WCH_ELEMS                     30150
#define PRO_E_RTFEAT_CMP_ELEMS                     30200
#define PRO_E_RTFEAT_ARR_ELEMS                     30250
#define PRO_E_RTFEAT_REF_ELEMS                     30300
#define   PRO_E_RTFEAT_REF_ELEM_1                  30301
#define   PRO_E_RTFEAT_REF_ELEM_2                  30302
#define   PRO_E_RTFEAT_REF_ELEM_3                  30303
#define   PRO_E_RTFEAT_REF_ELEM_4                  30304
#define   PRO_E_RTFEAT_REF_ELEM_5                  30305
#define   PRO_E_RTFEAT_REF_ELEM_6                  30306
#define   PRO_E_RTFEAT_REF_ELEM_7                  30307
#define   PRO_E_RTFEAT_REF_ELEM_8                  30308
#define   PRO_E_RTFEAT_REF_ELEM_9                  30309
#define   PRO_E_RTFEAT_REF_ELEM_10                 30310

#define RTFEAT_ELEMS_PER_TYPE                      50


/*
   **********  B E W A R E ******************************
   THESE VALUES MUST BE THE SAME ACROSS ALL PROE VERSIONS
   ******************************************************
*/
/*****************************************************************************/

#include <ProToolkitErrors.h>
#include <ProSizeConst.h>

PRO_BEGIN_C_DECLS

extern ProError ProElemIdStringGet( ProElemId elem_id, ProCharLine name );
/*
        Purpose: Obtains the name of the element id

        Input Arguments:
                elem_id            - The element id.

        Output Arguments:
                name               - The name of element id.

        Return Values:
                PRO_TK_NO_ERROR    - The function succeeded.
                PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
                PRO_TK_E_NOT_FOUND - The given element id was not found.
*/

PRO_END_C_DECLS

#endif  /* PROELEMIDH */
