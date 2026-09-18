/*----------------------------------------------------------------------*\
   ProComm.h: communications-related definitions needed by 
   		Creo Parametric TOOLKIT
\*----------------------------------------------------------------------*/



#ifndef _PROCOMM_H
#define _PROCOMM_H

#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

/* Communcations status values */

typedef enum
{
    PDEV_COMM_STATUS_OK = 0,
    PDEV_COMM_STATUS_DEADLOCK,
    PDEV_COMM_STATUS_ADDRESSEE_DEAD,
    PDEV_COMM_STATUS_COMM_BROKEN,
    PDEV_COMM_STATUS_REMOTE_ERROR,
    PDEV_COMM_STATUS_SESS_CANCEL,
    PDEV_COMM_STATUS_SESS_ABORT,
    PDEV_COMM_PEER_BUSY,
    PDEV_COMM_INTERNAL_ERROR,
    PDEV_COMM_LAYER_SHUTDOWN,
    PDEV_COMM_TIMEOUT
} Prodev_comm_status;

typedef int Prodev_sync_status;

#define PRODEV_SYNC_OK            0
#define PRODEV_SYNC_ERR_INTERNAL -1
#define PRODEV_SYNC_ERR_COMM_ERR -2
#define PRODEV_SYNC_ERR_CALLBACK -3

/* PeerIdx defined here because it is needed by both Creo Parametric and
   Creo Parametric TOOLKIT */

typedef struct PeerIdxTag
{
    int                      array_index;
    long                     auth_key;
}  PeerIdx;

/* temporary definition of not-yet-used data type */

typedef int PdevAddress;

PRO_END_C_DECLS

#endif /* _PROCOMM_H */
