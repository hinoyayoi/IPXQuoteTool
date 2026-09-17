

#ifndef PRONOTIFY_H
#define PRONOTIFY_H




#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMdl.h>
#include <ProParamval.h>

PRO_BEGIN_C_DECLS

typedef enum pro_notify_type
{
   PRO_NOTIFY_NOT_USED = -1,
   PRO_NOTIFY_UNASSIGNED = 0,

   /* ProMdlSavePreAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_SAVE_PRE 
      This enum is deprecated. Use PRO_MODEL_SAVE_PRE instead
   */
   PRO_MDL_SAVE_PRE = 1,

   /* ProMdlSavePostAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_SAVE_POST 
      This enum is deprecated. Use PRO_MODEL_SAVE_POST instead
   */
   PRO_MDL_SAVE_POST = 2,

   /* ProMdlSavePostAllAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_SAVE_POST_ALL 
      This enum is deprecated. Use PRO_MODEL_SAVE_POST_ALL instead
   */
   PRO_MDL_SAVE_POST_ALL = 3,

   /* ProMdlCopyPreAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_COPY_PRE 
      This enum is deprecated. Use PRO_MODEL_COPY_PRE instead
   */
   PRO_MDL_COPY_PRE = 4,

   /* ProMdlCopyPostAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_COPY_POST 
      This enum is deprecated. Use PRO_MODEL_COPY_POST instead
   */
   PRO_MDL_COPY_POST = 5,

   /* ProMdlCopyPostAllAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_COPY_POST_ALL 
      This enum is deprecated. Use PRO_MODEL_COPY_POST_ALL instead
   */
   PRO_MDL_COPY_POST_ALL = 6,

   /* ProMdlRenamePreAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_RENAME_PRE 
      This enum is deprecated. Use PRO_MODEL_RENAME_PRE instead
   */
   PRO_MDL_RENAME_PRE = 7,

   /* ProMdlRenamePostAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_RENAME_POST 
      This enum is deprecated. Use PRO_MODEL_RENAME_POST instead
   */
   PRO_MDL_RENAME_POST = 8,

   /* ProMdlErasePreAction */
   PRO_MDL_ERASE_PRE = 9,

   /* ProMdlErasePostAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_ERASE_POST 
      This enum is deprecated. Use PRO_MODEL_ERASE_POST instead
   */
   PRO_MDL_ERASE_POST = 10,

   /* ProMdlErasePostAllAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_ERASE_POST_ALL 
      This enum is deprecated. Use PRO_MODEL_ERASE_POST_ALL instead
   */
   PRO_MDL_ERASE_POST_ALL = 11,

   /* ProMdlPurgePreAction */
   PRO_MDL_PURGE_PRE = 12,

   /* ProMdlPurgePostAction */
   PRO_MDL_PURGE_POST = 13,

   /* ProMdlDeletePreAction */
   PRO_MDL_DELETE_PRE = 14,

   /* ProMdlDeletePostAction */
   PRO_MDL_DELETE_POST = 15,

   /* ProMdlDeletePostAllAction */
   PRO_MDL_DELETE_POST_ALL = 16,

   /* ProMdlRetrievePreAction18 */
   PRO_DUMMY_NOTIFY_1 = 17,

   /* ProMdlRetrievePostAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_RETRIEVE_POST 
      This enum is deprecated. Use PRO_MODEL_RETRIEVE_POST instead
   */
   PRO_MDL_RETRIEVE_POST = 18,

   /* ProMdlRetrievePostAllAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_RETRIEVE_POST_ALL 
      This enum is deprecated. Use PRO_MODEL_RETRIEVE_POST_ALL instead
   */
   PRO_MDL_RETRIEVE_POST_ALL = 19,

   /* ProMdlDbmsFailureAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_DBMS_FAILURE 
      This enum is deprecated. Use PRO_MODEL_DBMS_FAILURE instead
   */
   PRO_MDL_DBMS_FAILURE = 20,

   /* ProSolidRegeneratePreAction */
   PRO_SOLID_REGEN_PRE = 21,

   /* ProSolidRegeneratePostAction */
   PRO_SOLID_REGEN_POST = 22,

   /* ProDirectoryChangePostAction */
   PRO_DIRECTORY_CHANGE_POST = 23,

   /* ProWindowChangePostAction */
   PRO_WINDOW_CHANGE_POST = 24,

   /* ProMdlDisplayPreAction */
   PRO_MDL_DISPLAY_PRE = 25,

   /* ProMdlDisplayPostAction */
   PRO_MDL_DISPLAY_POST = 26,

   /* ProNcseqClPostAction */
   PRO_NCSEQ_CL_POST = 27,

   /* ProMfgoperClPostAction */
   PRO_MFGOPER_CL_POST = 28,

   /* ProFeatureCreatePostAction */
   PRO_FEATURE_CREATE_POST = 29,

   /* ProFeatureCopyPostAction */
   PRO_FEATURE_COPY_POST = 30,

   /* ProFeatureDeletePreAction */
   PRO_FEATURE_DELETE_PRE = 31,

   /* ProFeatureDeletePostAction */
   PRO_FEATURE_DELETE_POST = 32,

   /* ProFeatureSuppressPreAction */
   PRO_FEATURE_SUPPRESS_PRE = 33,

   /* ProFeatureSuppressPostAction */
   PRO_FEATURE_SUPPRESS_POST = 34,

   /* ProFeatureRegenPreAction */
   PRO_FEATURE_REGEN_PRE = 35,

   /* ProFeatureRegenPostAction */
   PRO_FEATURE_REGEN_POST = 36,

   /* ProParameterCreatePreAction
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_PARAM_CREATE_W_UNITS_PRE 
      This enum is deprecated. Use PRO_PARAM_CREATE_W_UNITS_PRE instead
   */
   PRO_PARAM_CREATE_PRE = 37,

   /* ProParameterModifyPreAction
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_PARAM_MODIFY_W_UNITS_PRE 
      This enum is deprecated. Use PRO_PARAM_MODIFY_W_UNITS_PRE instead
   */
   PRO_PARAM_MODIFY_PRE = 38,

   /* ProParameterDeletePreAction */
   PRO_PARAM_DELETE_PRE = 39,

   /* ProMdlCreatePreAction18 */
   PRO_DUMMY_NOTIFY_2 = 40,

   /* ProMdlCreatePostAction */
   PRO_MDL_CREATE_POST = 41,
 
   /* ProFeatureRegenFailureAction */
   PRO_FEATURE_REGEN_FAILURE = 42,

   /* ProClCommandExpandAction */
   PRO_NCL_COMMAND_EXPAND = 43,

   /* ProClCommandGetLocAction */
   PRO_NCL_COMMAND_GET_LOC = 44,

   /* ProRmdtCreateImmPreAction */  
   PRO_RMDT_CREATE_IMM_PRE = 45,

   /* ProRmdtBoundBoxPreAction */
   PRO_RMDT_BOUND_BOX_PRE = 46,

   /* ProRmdtCavLayoutPreAction */
   PRO_RMDT_CAV_LAYOUT_PRE = 47,

   /* ProRmdtCreateWpPreAction */
   PRO_RMDT_CREATE_WP_PRE = 48,

   /* ProRmdtMaterialPreAction */
   PRO_RMDT_MATERIAL_PRE = 49,

   /* ProRmdtMBaseSelectPreAction */
   PRO_RMDT_MBASE_SELECT_PRE = 50,

   /* ProFeatureCreatePreAction */
   PRO_FEATURE_CREATE_PRE = 51,

   /* ProFeatureRedefinePreAction */
   PRO_FEATURE_REDEFINE_PRE = 52,

   /* ProFileOpenOKAction */
   PRO_FILE_OPEN_OK = 53,

   /* ProMdlCreatePreAction */
   PRO_MDL_CREATE_PRE = 54,

   /* ProMdlRetrievePreAction 
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_MODEL_RETRIEVE_PRE 
      This enum is deprecated. Use PRO_MODEL_RETRIEVE_PRE instead
   */
   PRO_MDL_RETRIEVE_PRE = 55,

   /* ProMdlBackupPreAction is obsolete */
   PRO_MDL_BACKUP_PRE = 56,

   /* ProMdlBackupPostAction is obsolete */
   PRO_MDL_BACKUP_POST = 57,
   
   /* ProSolidUnitConvertPreAction */
   PRO_SOLID_UNIT_CONVERT_PRE = 58,

   /* ProSolidUnitConvertPostAction */
   PRO_SOLID_UNIT_CONVERT_POST = 59,

   /* ProDrawingWeldSympathGetAction */
   PRO_DRAWING_WELD_SYMPATH_GET = 60,

   /* ProDrawingWeldGroupsGetAction */
   PRO_DRAWING_WELD_GROUPS_GET = 61,

   /* ProDrawingWeldSymtextGetAction */
   PRO_DRAWING_WELD_SYMTEXT_GET = 62,

   /* ProMdlCreateCancelAction */
   PRO_MDL_CREATE_CANCEL = 63,

   /* ProDimModifyValuePreAction */
   PRO_DIM_MODIFY_VALUE_PRE = 64,

   /* ProFeatureRedefinePostAction */
   PRO_FEATURE_REDEFINE_POST = 65,

   /* ProFeatureReroutePreAction */
   PRO_FEATURE_REROUTE_PRE = 66,

   /* ProFeatureReroutePostAction */
   PRO_FEATURE_REROUTE_POST = 67,

   /* ProFeatureReplacePreAction */
   PRO_FEATURE_REPLACE_PRE = 68,

   /* ProFeatureReplacePostAction */
   PRO_FEATURE_REPLACE_POST = 69,

   /* ProMdlStartAction */
   PRO_MDL_START = 70,
   
   /* ProGlobalInterfCalcPostAction */
   PRO_GLOBAL_INTERF_CALC_POST = 71,

   /* ProPopupmenuCreatePostAction */
   PRO_POPUPMENU_CREATE_POST = 72,

   /* ProPopupmenuDestroyPreAction */
   PRO_POPUPMENU_DESTROY_PRE = 73,

   /* ProAsmcompActivatePreAction */
   PRO_ASMCOMP_ACTIVATE_PRE = 74,

   /* ProAsmcompActivatePostAction */
   PRO_ASMCOMP_ACTIVATE_POST = 75,

   /* ProSolidPrincSysUnitsRenamedPostAction */
   PRO_SOLID_PRINC_SYS_UNITS_RENAMED_POST = 76,

   /* ProGroupUngroupPreAction        */
   PRO_GROUP_UNGROUP_PRE  =   77, 

   /* ProGroupUngroupPostAction       */
   PRO_GROUP_UNGROUP_POST  =  78, 
   
   /* ProUdfLibraryCompletePostAction */
   PRO_UDF_LIB_COMPLETE_POST =  79,

   /* ProParameterCreatePostAction  */
   PRO_PARAM_CREATE_POST  =   80, 

   /* ProParameterModifyPostAction
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_PARAM_MODIFY_W_UNITS_POST 
      This enum is deprecated. Use PRO_PARAM_MODIFY_W_UNITS_POST instead
   */
   PRO_PARAM_MODIFY_POST  =  81, 

   /* ProParameterDeletePostAction
      DEPRECATED: Since Creo 3.0
      SUCCESSORS: PRO_PARAM_DELETE_W_UNITS_POST 
      This enum is deprecated. Use PRO_PARAM_DELETE_W_UNITS_POST instead
   */
   PRO_PARAM_DELETE_POST =  82 ,
   
   /* ProCheckinUIPreAction */
   PRO_CHECKIN_UI_PRE = 83,

   
 
   /* ProDwgtableDeletePreAction */
   PRO_DWGTABLE_DELETE_PRE = 85,
 
   /* ProDwgtableDeletePostAction */
   PRO_DWGTABLE_DELETE_POST = 86,

   

   /* ProDwgtableRowDeletePreAction */
   PRO_DWGTABLE_ROW_DELETE_PRE = 88,
 
   /* ProDwgtableRowDeletePostAction */
   PRO_DWGTABLE_ROW_DELETE_POST = 89,


   /* ProWindowOccupyPostAction */
   PRO_WINDOW_OCCUPY_POST  = 90,

   /* ProWindowVacatePreAction  */
   PRO_WINDOW_VACATE_PRE  = 91,

   /* ProFeatureNeedsRegenGet */
   PRO_FEATURE_NEEDS_REGEN_GET = 92,

   

   /* ProRibbonTabSwitchAction */
   PRO_RIBBON_TAB_SWITCH  = 94,

   

   /* ProModelSavePostAction */
   PRO_MODEL_SAVE_POST = 97,

   /* ProModelSavePostAllAction */
   PRO_MODEL_SAVE_POST_ALL = 98,

   /* ProModelErasePostAllAction */
   PRO_MODEL_ERASE_POST_ALL = 99,

   /* ProModelRetrievePostAllAction */
   PRO_MODEL_RETRIEVE_POST_ALL = 100,

   /* ProModelDbmsFailureAction */
   PRO_MODEL_DBMS_FAILURE = 101,

   /* ProModelRetrievePreAction */
   PRO_MODEL_RETRIEVE_PRE = 102,

   /* ProModelSavePreAction */
   PRO_MODEL_SAVE_PRE = 103,

   /* ProModelCopyPreAction */
   PRO_MODEL_COPY_PRE = 104,

   /* ProModelCopyPostAction */
   PRO_MODEL_COPY_POST = 105,

   /* ProModelCopyPostAllAction */
   PRO_MODEL_COPY_POST_ALL = 106,

   /* ProModelRenamePreAction */
   PRO_MODEL_RENAME_PRE = 107,

   /* ProModelRenamePostAction */
   PRO_MODEL_RENAME_POST = 108,

   /* ProModelErasePostAction */
   PRO_MODEL_ERASE_POST = 109,

   /* ProModelRetrievePostAction */
   PRO_MODEL_RETRIEVE_POST = 110,

   /* ProParameterCreateWithUnitsPreAction */
   PRO_PARAM_CREATE_W_UNITS_PRE = 111,
   
   /* ProParameterModifyWithUnitsPreAction */
   PRO_PARAM_MODIFY_W_UNITS_PRE = 112,
   
   /* ProParameterModifyWithUnitsPostAction */
   PRO_PARAM_MODIFY_W_UNITS_POST = 113,
   
   /* ProParameterDeleteWithUnitsPostAction */
   PRO_PARAM_DELETE_W_UNITS_POST = 114,

   

   /* ProModelReplacePostAction */
   PRO_MODEL_REPLACE_POST = 117,

   /*  ProModelSavePreAllAction */
   PRO_MODEL_SAVE_PRE_ALL = 118,

   

   /* ProModelRenamePostAllAction */
   PRO_MODEL_RENAME_POST_ALL = 122
   
} ProNotifyType;

extern ProError ProNotificationSet ( ProNotifyType type,
                                     ProFunction   notify_function);
/*
   Purpose:     Sets the notification function to be called for the 
                specified action.
 
                NOTE:  If you call ProNotificationSet() more than once with the 
                       same event type, the existing callback is overwritten 
                       with the one supplied in the later call.

   Input Arguments:
      type              - The action for which you want to be notified
      notify_function   - The function to be called for the action

   Output Arguments:
      None

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully set the function.
      PRO_TK_GENERAL_ERROR - There was a general error.
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid.
*/



extern ProError ProNotificationUnset ( ProNotifyType type );
/*

   Purpose:  Removes the value of the specified notification.


   Input Arguments:

      type    -  The notification type

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully set the function.
      PRO_TK_GENERAL_ERROR - There was a general error.
      PRO_TK_BAD_INPUTS    - The argument is invalid.

*/



typedef ProError (*ProFileOpenOKAction) (ProMdlType mdl_type,
                                         int        sub_type,
                                         ProName    model_name);
/*
  Purpose: This is the notification function called after the new file has
           been successfully selected in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type PRO_FILE_OPEN_OK.
 
  Input Arguments:
     mdl_type       - The model type (PRO_PART, PRO_ASSEMBLY, and so on)
     sub_type       - The model subtype
     model_name     - The model name
 
  Output Arguments:
     None
 
  Return Values:
      PRO_TK_NO_ERROR -  The user specifications are valid.
                         Proceed with model creation.
      Other           -  The user specifications are invalid.
                         Do not exit the dialog.
*/



typedef ProError (*ProDirectoryChangePostAction) ( ProPath new_path );
 
/*
  Purpose: This is the notification function called 
	   after the current directory has
           been successfully changed in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type 
           PRO_DIRECTORY_CHANGE_POST.
 
  Input Arguments:
     new_path         - The new path to which the directory was changed
 
  Output Arguments:
     None
 
  Return Values:
      Return Values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/
 
typedef ProError (*ProWindowChangePostAction) ( void );

/*
  Purpose: This is the notification function called upon successfully 
           changing the window in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type 
           PRO_WINDOW_CHANGE_POST.
<p>
           NOTE: 
<p>
           The functions <b>ProMdlCurrentGet()</b>, 
           <b>ProWindowCurrentGet()</b>,
           and <b>ProModeCurrentGet()</b> can be used in this function.
                

  Input Arguments:
     None

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProMdlCurrentGet()
      ProModeCurrentGet()
      ProNotificationSet()
      ProWindowCurrentGet()
*/

typedef ProError (*ProNcseqClPostAction) (ProMdldata *p_cl_file_info);
 
/*
  Purpose: This is the notification function called upon successful computation
           of the NC sequence's toolpath.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type PRO_NCSEQ_CL_POST.
 
  Input Arguments:
     p_cl_file_info   -  The information (name, extension, and path)
                         for the CL file in which the toolpath was
                         written is supplied through this argument.
 
  Output Arguments:
     None
 
  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

typedef ProError (*ProMfgoperClPostAction) (ProMdldata *p_cl_file_info);

/*
  Purpose: This is the notification function called upon successful computation
           of a manufacturing operation's toolpath.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the notify type PRO_MFGOPER_CL_POST.

  Input Arguments:
     p_cl_file_info   -  The information (name, extension, and path)
                         for the CL file in which the toolpath was
                         written is supplied through this argument.

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()
*/

typedef ProError (*ProSolidUnitConvertPreAction) (ProSolid  solid_handle,
                                                  int       convert_numbers);

/*
 
   Purpose:
        This is the notification function called before unit conversion of a
        solid.
<p>
        This function is to be supplied by the user by calling
        <b>ProNotificationSet()</b> with the notify type PRO_UNIT_CONVERT_PRE
                                           
   Input Arguments:
        solid_handle     -  The handle to the solid about to be converted
        convert_numbers - TRUE if quantities are converted,
                            FALSE if quantities are reinterpreted.
                                                      
   Output Arguments:
        None
                                                                 
   Return Values:
        Return values are not interpreted by Creo Parametric.
                                                                            
   See Also:
        ProNotificationSet()
                                                                                       
*/

typedef ProError (*ProSolidUnitConvertPostAction) (ProSolid  solid_handle,
                                                   int       convert_numbers);

/*

   Purpose:
        This is the notification function called after unit conversion of a
        solid.
<p>
        This function is to be supplied by the user by calling
        <b>ProNotificationSet()</b> with the notify type PRO_UNIT_CONVERT_POST
                                           
   Input Arguments:
        solid_handle     -  The handle to the solid about to be converted
        convert_numbers - TRUE if quantities are converted,
                            FALSE if quantities are reinterpreted.
                                                      
   Output Arguments:
        None
                                                                 
   Return Values:
        Return values are not interpreted by Creo Parametric.
                                                                            
   See Also:
        ProNotificationSet()
                                                                               
*/

typedef ProError (*ProMdlCreateCancelAction)( void );
/*
  Purpose: This is the notification function called after the new file
           creation been cancelled in Creo Parametric.
<p>
           This function is to be supplied by the user by calling
           <b>ProNotificationSet()</b> with the type PRO_MDL_CREATE_CANCEL.

  Input Arguments:
     None

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR
*/

typedef ProError (*ProGlobalInterfCalcPostAction) (ProAssembly assembly);
/*
  Purpose: This notification is called after a global interference check
           has been run on an assembly.

  Input Arguments:
       assembly  -  The assembly where the interference check was run.

  Output Arguments:
       none

  Return Values:
       Return values are not interpreted by Creo Parametric.
*/

typedef ProError (*ProSolidPrincSysUnitsRenamedPostAction) (ProSolid  solid_handle,
                                                            ProName   old_name, 
                                                            ProName   new_name);

/*
   Purpose:
        This is the notification function called after principal system of 
        units was renamed
 <p>
        This function is to be supplied by the user by calling
        <b>ProNotificationSet()</b> with the notify type 
        PRO_SOLID_PRINC_SYS_UNITS_RENAMED_POST
                                           
   Input Arguments:
        solid_handle     -  The handle to the solid about to be converted
        old_name         -  Old name of principal system of units
        new_name         -  New name of principal system of units
        
   Output Arguments:
        None
                                                                 
   Return Values:
        Return values are not interpreted by Creo Parametric.
                                                                            
   See Also:
        ProNotificationSet()
*/

typedef ProError (*ProCheckinUIPreAction) ( void );
/*
    Purpose: This is the function prototype that will be called when the user 
             has just selected File->Auto Checkin, File->Custom Checkin, or
             the corresponding menu choices on the Model Tree menu.  It is
             called before any of the actions executed by this button
             take place.

    Input Arguments:
        none

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue checking in.
        Any other value - Cancel the checkin activity. The application is 
                          responsible for informing the user why the action
                          was cancelled.

*/

typedef ProError (*ProRibbonTabSwitchAction) ( char *from_tab, char *to_tab );
/*
  Purpose: This is the notification function called when switching from one ribbon tab to another
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type
            PRO_RIBBON_TAB_SWITCH.

    Input Arguments:
        from_tab      - Name of the ribbon tab switching from.
        to_tab        - Name of the ribbon tab switching to.

    Output Arguments:
        None

    Return Values:
        Must return PRO_TK_NO_ERROR.

    See Also:
        ProNotificationSet()

*/

PRO_END_C_DECLS

#endif /* PRONOTIFY_H */
