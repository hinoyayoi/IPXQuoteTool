#ifndef PRODTLITEM_H 
#define PRODTLITEM_H
			

#include <ProANSI.h>
#include <ProObjects.h> 
#include <ProColor.h>

PRO_BEGIN_C_DECLS

typedef ProModelitem ProDtlsymdef;  /* type = PRO_SYMBOL_DEFINITION */
typedef ProModelitem ProDtlgroup;   /* type = PRO_DRAFT_GROUP       */
typedef ProModelitem ProDtlentity;  /* type = PRO_DRAFT_ENTITY      */
typedef ProModelitem ProDtlitem;    /* type = any of the above     */

typedef struct pro_dtlsymgroup
{
  ProDtlsymdef symbol_def;
  int sym_group_id;
} ProDtlsymgroup;

typedef ProError (*ProDtlitemVisitAction)(
 ProDtlitem *item,
 ProError filt_status,
 ProAppData appdata);

/*

Purpose: Action function called while visiting a Creo Parametric detail item 
         with one of the following functions:
         ProDrawingDtlentityVisit(), ProDrawingDtlnoteVisit,
         ProDrawingDtlgroupVisit(), ProDrawingDtlsyminstVisit, or 
         ProDrawingDtlsymdefVisit(). 

Input Arguments:

        item        -  Input detail item
        filt_status -  Return value from filter action function
        appdata     -  Application data passed to one of the functions 
                       listed in the Purpose section. 
                         
Output Arguments:

       None

Return Values:

       PRO_TK_NO_ERROR - Continue visiting detail items.
       Other           - Stop visiting detail items.

 */


typedef ProError (*ProDtlitemFilterAction)(
 ProDtlitem *item,
 ProAppData appdata);


/*

Purpose: Filter function called while visiting a Creo Parametric detail item 
         with one of the following functions: 
	 ProDrawingDtlentityVisit(), ProDrawingDtlnoteVisit,
         ProDrawingDtlgroupVisit(), ProDrawingDtlsyminstVisit, or 
         ProDrawingDtlsymdefVisit().

Input Arguments:

      item          -  Input detail item
      appdata       -  Application data passed to one of the functions 
                       listed in the Purpose section.  
        
Output Arguments:

      None

Return Values:

      PRO_TK_CONTINUE - Do not call visit action function for this detail item.
      Other           - Call visit action function for this detail item.

*/



PRO_END_C_DECLS

#endif /* PRODTLITEM_H */

