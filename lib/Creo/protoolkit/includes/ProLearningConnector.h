

#ifndef PRO_LEARNING_CONNECTOR_H
#define PRO_LEARNING_CONNECTOR_H

#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

extern ProError ProLearningconnectorNotify(const char* module, const char* module_info);
/*
Purpose: Notifies the LearningConnector (LC) of the occurrence of an event
  triggered from a Creo Toolkit application. LC can be configured to deliver
  organization specific training whenever events with a specific module and
  module_info are received. Refer to the LC documentation before using this
  functionality.

Input Arguments:
    module - specifies the name of the calling module. Cannot be null or an 
        empty string. 
    module_info - specifies optional information of the calling module. 
        You may add any information that can be used later in the custom made
        LC event-handling function. 

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - The input arguments are invalid.
*/

PRO_END_C_DECLS

#endif /* PRO_LEARNING_CONNECTOR_H */
