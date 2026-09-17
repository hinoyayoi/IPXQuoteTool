#ifndef   PROMDLCHK_H
#define   PROMDLCHK_H

#include  <ProToolkitErrors.h>
#include  <ProObjects.h>
#include  <ProWstring.h>



PRO_BEGIN_C_DECLS

typedef enum
{
   PRO_MODELCHECK_GRAPHICS  = 0,
   PRO_MODELCHECK_NO_GRAPHICS = 1
} ProMCMode;



extern ProError ProModelcheckExecute (ProMdl  mdl, 
                                      ProBoolean show_ui, 
                                      ProMCMode mc_mode, 
                                      ProPath config_dir,
                                      ProPath output_dir,
                                      int     *errors,
                                      int     *warnings,
                                      ProBoolean *model_saved);
  
/*

  Purpose:      To run ModelCheck and extract the results.

  Input Arguments:
    mdl                 - The model on which ModelCheck is to be executed
    show_ui             - PRO_B_TRUE to show the ModelCheck results in the
                          browser, PRO_B_FALSE to skip this
    mc_mode             - The mode used to execute ModelCheck.
    config_dir          - The location of the ModelCheck configuration 
                          directory.  The configuration directory should be
                          named 'config'.  If  NULL, the default ModelCheck 
                          config direcytory will be used.
    output_dir          - The directory to which the reports files should be
                          written.  If NULL, the default 
                          ModelCheck output directory will be used.

  Output Arguments:
    errors              - The number of errors found
    warnings            - The number of warnings found
    model_saved         - PRO_B_TRUE if the model is saved with updates and 
                          PRO_B_FALSE otherwise.


  Return Values:
    PRO_TK_NO_ERROR     -   The function succeeded.
    PRO_TK_BAD_INPUTS   -   One or more input arguments was invalid.
    PRO_TK_E_NOT_FOUND  -   The function failed to find config directoy 
                            specified. 
    PRO_TK_GENERAL_ERROR -   Failure due to any other reasons
    PRO_TK_NO_LICENSE   -   Creo Parametric is missing the license to execute
                            ModelCheck.

*/


typedef struct pro_mdlchk_tk_options* ProModelcheckOptions;

typedef enum 
{
  PRO_MC_REPORT_INFO, 
  PRO_MC_REPORT_PARAM, 
  PRO_MC_REPORT_LAYER, 
  PRO_MC_REPORT_FEAT, 
  PRO_MC_REPORT_RELAT, 
  PRO_MC_REPORT_DATUM, 
  PRO_MC_REPORT_VIEW,     /* only valid for drawing reports */ 
  PRO_MC_REPORT_NOTE,     /* only valid for drawing reports */ 
  PRO_MC_REPORT_MISC
} ProModelcheckReportTab;

typedef ProError (*ProModelcheckCheckFunction) (ProCharName name,
						ProMdl mdl,
						ProAppData appdata,
						int* results_count,
						wchar_t** results_url,
						wchar_t*** results_table);
/*
    Purpose: This is the callback that is called to evaluate a ModelCheck 
             externally defined check.

    Input Arguments:
        name - The name of the check.  This also corresponds to the ModelCheck 
               configuration option name.
        mdl - The model being checked during this run.
        appdata - Application data that was registered for the check.

    Output Arguments:
        results_count - Numerical count to be shown in the ModelCheck report 
                        for this check.
        results_url - URL to a page that provides details on the results of 
                      this check.  Can be NULL, in which case the check will be 
                      listed with no extra information besides the count.  
                      Memory for this argument should be allocated and 
                      maintained by the application.  It can be freed from the 
                      cleanup action for the ModelCheck check.
        results_table - A ProArray of strings to show for details of each found 
                        item.  Can be NULL.  The memory for this argument 
                        should be allocated and maintained in the application.  
                         It can be freed in the cleanup action for the 
                        ModelCheck check.

    Return Values:
        PRO_TK_NO_ERROR - The check succeeded with no errors found.
        PRO_TK_E_FOUND - The check succeeded and errors were found.
        Any other value - Unable to perform the check.

*/

typedef ProError (*ProModelcheckUpdateFunction) (ProCharName name,
						 ProMdl mdl,
						 wchar_t* selected_item,
						 ProAppData appdata);
/*
    Purpose: This is the callback that is called to update or repair an item 
             found by a custom check.
             

    Input Arguments:
        name - The name of the check.  This also corresponds to the ModelCheck 
               configuration option name.
        mdl - The model being checked during this run.
        selected_item - Label of the item that was selected from the table, if 
                        applicable.  Can be NULL if no item was 
                        selected.
        appdata - Application data that was passed when the custom check was 
                  registered.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Return values are not interpreted by Creo Parametric.

*/

typedef ProError (*ProModelcheckCleanupFunction) (ProCharName name,
						  ProMdl mdl,
						  ProAppData appdata);
/*
    Purpose: This is the callback that is called to indicate that the results 
             of a check can be discarded.

    Input Arguments:
        name - The name of the check.  This also corresponds to the ModelCheck 
               configuration option name.
        mdl - The model being checked during this run.
        appdata - Application data that was passed to Creo Parametric during 
                  registration.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Return values are not interpreted by Creo Parametric.

*/

extern ProError ProModelcheckCheckRegister( ProCharName name, wchar_t* label,
				 ProModelcheckOptions options,
				 ProModelcheckCheckFunction check_function,
				 ProModelcheckCleanupFunction cleanup_function,
				 wchar_t* action_label,
				 ProModelcheckUpdateFunction action_function,
				 wchar_t* update_label,
				 ProModelcheckUpdateFunction update_function,
				 ProAppData appdata );
/*
    Purpose: Registers an external check that can be included in any ModelCheck 
             execution.
             

    Input Arguments:
        name - The name of the check.  This also corresponds to the ModelCheck 
               configuration option name.
        label - The label for the check, in the localized language.
        options - Options to be used for the check registration.  Can be NULL.
        check_function - The function to be called when executing the check.
        cleanup_function - The function to be called when ModelCheck is ready 
                           to discard the results of the check.  Can be NULL.
        action_label - Label for the button used to perform an action for an 
                       item found by the check.  Pass NULL to not provide this 
                       button.
        action_function - The function to be called to perform an action on
                        model based on the results of the check.  Can be NULL.
        update_label - Label for the button used to update the model for an 
                       item found by the check.  Pass NULL to not provide this 
                       button.
        update_function - The function to be called when updating the model 
                          based on the results of the check.  Can be NULL.
        appdata - Application data to be passed to the callback functions.  Can 
                  be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_FOUND - Check with this name already exists.
        PRO_TK_BAD_CONTEXT - ModelCheck is not enabled in session.

*/

PRO_END_C_DECLS

#endif
