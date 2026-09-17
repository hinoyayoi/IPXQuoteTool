#ifndef PROCONST_H
#define PROCONST_H




/*
  General Data Types
*/
#define PRO_INTEGER_TYPE        1
#define PRO_DOUBLE_TYPE         2
#define PRO_WIDE_STRING_TYPE    3
#define PRO_STREAM_TYPE         4
#define PRO_YES_NO_TYPE         5
#define PRO_MULTICELL_TYPE      6
#define PRO_CHAPTER_TYPE        7

/*
  Identifier Selection
  (note that the selection keys "&" properly with the bitmask flags)
*/

#define KEY_BY_ID               4097
#define KEY_BY_NAME             4098

typedef enum proe_term_type
{
   PROTERM_EXIT = 1,    /* normal exit */
   PROTERM_ABNORMAL,    /* exit with error exit status */
   PROTERM_SIGNAL       /* fatal signal raised */
           /* others to be added as appropriate */
} ProeTerminationStatus;
#define PRO_KILL_EXIT_CODE 1

#define PRO_CONNECTID_SIZE 256

/*---- DesignStudy ----*/

/* DesignStudy types */

#define   DS_UNUSED  -1
#define   DS_SENS     0
#define   DS_OPTIM    1
#define   DS_FEAS     2
#define   DS_MOPT     3
#define   DS_STAT     4
#define   DS_INIT    99         /* Reserved for internal use */

/* DesignStudy operations */

#define   DS_OK          0
#define   DS_REVERT      1
#define   DS_CANCEL      2
#define   DS_APPLY       3
#define   DS_OK_W_UPDATE 4

/*---------------------------------------------------------------------*\
  Clearance Types
  Drawing Tables
\*---------------------------------------------------------------------*/
#define PRO_TABLE_MAX_COLS   50
#define PRO_TABLE_MAX_ROWS   100

#endif /* PROCONST_H */ 

