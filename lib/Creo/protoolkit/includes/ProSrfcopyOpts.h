#ifndef PRO_SRFCOPYOPTS_H
#define PRO_SRFCOPYOPTS_H



PRO_BEGIN_C_DECLS

/* ============================= */
/* Type options of Surface Copy: */
/* ============================= */
#define PRO_SRFCOPY_AS_IS            1  /* Copy surfaces As Is  */
#define PRO_SRFCOPY_EXCLD_FILL       2  /* Exlude surface loops and Fill loops */
#define PRO_SRFCOPY_INSIDE_BNDRY     3  /* Copy surface trimmed by a boundary */
#define PRO_SRFCOPY_UNTRIM_TO_ENVLP  4  /* Copy surface un-trimmed to envelope */
#define PRO_SRFCOPY_UNTRIM_TO_DOMAIN 5  /* Copy surface un-trimmed to domain of definition */

PRO_END_C_DECLS

#endif /* PRO_SRFCOPYOPTS_H */
