#ifndef PROMDL_H
#define PROMDL_H


/* Creo Parametric TOOLKIT declarations for ProSolid object related actions */

#include <ProObjects.h>
#include <ProVerstamp.h>
#include <ProSelection.h>
#include <ProSimprepdata.h>
#include <ProSurface.h>



PRO_BEGIN_C_DECLS

typedef struct pro_object_info
{
   wchar_t name[80];
   wchar_t type[10];
   wchar_t path[PRO_PATH_SIZE];
   wchar_t device[20];
   wchar_t host[80];
   int version;
   int subclass;
} ProMdldata;

typedef struct promodel
{
   wchar_t name[80];
   wchar_t type[10];
} ProModel;

typedef struct
{
   ProMdlName name;
   ProMdlExtension type;
} ProMdlnameShortdata;

typedef enum
{
   PRO_MDL_UNUSED     = PRO_TYPE_UNUSED,
   PRO_MDL_ASSEMBLY   = PRO_ASSEMBLY,
   PRO_MDL_PART       = PRO_PART,
   PRO_MDL_DRAWING    = PRO_DRAWING,
   PRO_MDL_3DSECTION  = PRO_3DSECTION,
   PRO_MDL_2DSECTION  = PRO_2DSECTION,
   PRO_MDL_LAYOUT     = PRO_LAYOUT,     /* (*.lay file)  Notebook model.
                                           Formerly known as Layout model */
   PRO_MDL_DWGFORM    = PRO_DWGFORM,
   PRO_MDL_MFG        = PRO_MFG,
   PRO_MDL_REPORT     = PRO_REPORT,
   PRO_MDL_MARKUP     = PRO_MARKUP,
   PRO_MDL_DIAGRAM    = PRO_DIAGRAM,
   PRO_MDL_CE_SOLID   = PRO_CE_SOLID,   /* Layout model; NOTE: this type is read-only, 
                                           passing it back to Creo may lead to unpredictable behavior */
   PRO_MDL_CE_DRAWING = PRO_CE_DRAWING, /* reserved for internal use */
   PRO_MDL_DRW_SOLID  = PRO_DRW_SOLID   /* reserved for internal use */
} ProMdlType;

typedef enum
{
   PROMDLSTYPE_NONE = 0,
   PROMDLSTYPE_BULK,                     /*  Bulk items  */
   PROMDLSTYPE_PART_SOLID,               /* Solid Part */
   PROMDLSTYPE_PART_COMPOSITE,           /* Composite Part */ 
   PROMDLSTYPE_PART_SHEETMETAL,          /* Sheetmetal part */
   PROMDLSTYPE_PART_CONCEPT_MODEL,       /* Concept Model */
   PROMDLSTYPE_ASM_DESIGN,               /* Design Assembly */
   PROMDLSTYPE_ASM_INTERCHANGE, /* Interchange Assembly (both func & subst) */
   PROMDLSTYPE_ASM_INTCHG_SUBST, /* Substutional interchange */
   PROMDLSTYPE_ASM_INTCHG_FUNC,  /* Functional interchange  */
   PROMDLSTYPE_ASM_CLASS_CAV,             /* CAV */
   PROMDLSTYPE_ASM_VERIFY,   /* Verify */
   PROMDLSTYPE_ASM_PROCPLAN, /* Assembly Manufacturing plan */
   PROMDLSTYPE_ASM_NCMODEL,  /* NC Model */
   PROMDLSTYPE_MFG_NCASM,    /* Manufacturing Assembly */
   PROMDLSTYPE_MFG_NCPART,   /* Part Manufacturing */
   PROMDLSTYPE_MFG_EXPMACH,  /* Expert Machinist */
   PROMDLSTYPE_MFG_CMM,       /* CMM Manufacturing */
   PROMDLSTYPE_MFG_SHEETMETAL,/* sheet metal */
   PROMDLSTYPE_MFG_CAST,      /* cast */
   PROMDLSTYPE_MFG_MOLD,      /* mold design */
   PROMDLSTYPE_MFG_DIEFACE,   /* diaface */
   PROMDLSTYPE_MFG_HARNESS,   /* Harness Manufacture */
   PROMDLSTYPE_MFG_PROCPLAN,  /* Manufacturing Process */
   PROMDLSTYPE_REGEN_BACKUP,  /* Regeneration Backup */
   PROMDLSTYPE_OLD_REG_MFG,   /* Regular Manufacturing (outdated) */
   PROMDLSTYPE_ASM_CLASS_SCAN_SET, /* CAV scan set part */
   PROMDLSTYPE_ASM_EXT_SIMP_REP,   /* External Simplify Representation */
   PROMDLSTYPE_ASM_FIGURE,         /* Figure Assembly */
   PROMDLSTYPE_MANIKIN_TOP,        /* Top level Manikin assembly */
   PROMDLSTYPE_MANIKIN_SEG,        /* Sub-assembly/part Manikin  */
   PROMDLSTYPE_ASM_CONFIGURE_ASM,  /* Configure Assembly */
   PROMDLSTYPE_CE_SOLID,
   PROMDLSTYPE_CREO_INTRCH,       /* Creo Container Model (interchange) */
   PROMDLSTYPE_CREO_CNF_FACTORY,  /* Creo conf. structure (variation factory) */
   PROMDLSTYPE_ECAD_ASM,          /* Ecad assembly */
   PROMDLSTYPE_ECAD_BOARD_PART,   /* Ecad board part */
   PROMDLSTYPE_TRAY_ASSEM,         /* Tray Assembly */
   PROMDLSTYPE_INSTR_ASM        /* Instrumented Assembly */  
} ProMdlsubtype;


typedef enum
{
   PRO_MDLFILE_UNUSED        = PRO_TYPE_UNUSED,
   PRO_MDLFILE_ASSEMBLY      = PRO_MDL_ASSEMBLY,
   PRO_MDLFILE_PART          = PRO_MDL_PART,
   PRO_MDLFILE_DRAWING       = PRO_MDL_DRAWING,
   PRO_MDLFILE_3DSECTION     = PRO_MDL_3DSECTION,
   PRO_MDLFILE_2DSECTION     = PRO_MDL_2DSECTION,
   PRO_MDLFILE_NOTEBOOK      = PRO_MDL_LAYOUT,
   PRO_MDLFILE_DWGFORM       = PRO_MDL_DWGFORM,
   PRO_MDLFILE_MFG           = PRO_MDL_MFG,
   PRO_MDLFILE_REPORT        = PRO_MDL_REPORT,
   PRO_MDLFILE_MARKUP        = PRO_MDL_MARKUP,
   PRO_MDLFILE_DIAGRAM       = PRO_MDL_DIAGRAM,
   PRO_MDLFILE_CE_DRAWING    = PRO_MDL_CE_DRAWING,  /* reserved for internal use */
   PRO_MDLFILE_CE_SOLID      = PRO_MDL_CE_SOLID,    /* Layout model; NOTE: this type is read-only,
                                                       passing it back to Creo may lead to unpredictable behavior */
   PRO_MDLFILE_CATIA_MODEL   = PRO_CATIA_MODEL, 
   PRO_MDLFILE_UG            = PRO_UG,
   PRO_MDLFILE_SW_PART       = PRO_SW_PART,
   PRO_MDLFILE_SW_ASSEM      = PRO_SW_ASSEM,
   PRO_MDLFILE_CATIA_PART    = PRO_CATIA_PART,  
   PRO_MDLFILE_CATIA_PRODUCT = PRO_CATIA_PRODUCT, 
   PRO_MDLFILE_CATIA_CGR     = PRO_CATIA_CGR,
   PRO_MDLFILE_CC_ASSEMBLY   = PRO_CC_ASSEMBLY, 
   PRO_MDLFILE_CC_PART       = PRO_CC_PART		
} ProMdlfileType;

typedef enum
{
    PRO_RETRIEVE_OP_NO		= 0,
    PRO_RETRIEVE_OP_NORMAL,
    PRO_RETRIEVE_OP_SIMP_REP,
    PRO_RETRIEVE_OP_VIEW_ONLY
} ProFileRetrieveOpt;  
  
/*===========================================================================*/
extern ProError ProMdlInit  (ProName     name, 
                             ProMdlType  type,
                             ProMdl     *p_mdl_handle);
/*
   @UNDO: SAFE
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlnameInit
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlnameInit instead.

                Initializes the <i>ProMdl</i> handle.

   Input Arguments:
      name              - The model name 
      type              - The model type 

   Output Arguments:
      p_mdl_handle      - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND - Unable to find the required model.
*/

extern ProError ProMdlnameInit ( ProMdlName  name, 
                                 ProMdlfileType  type,
                                 ProMdl     *p_mdl_handle);
/*
   Purpose:     Initializes the <i>ProMdl</i> handle.

			<b>Note:</b> In Creo 3 this function does not support names longer 
			than 80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for longer names will be added in a future release. 

   Input Arguments:
      name              - The model name 
      type              - The model type 

   Output Arguments:
      p_mdl_handle      - The handle to initialize

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully initialized the handle.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND - Unable to find the required model.
*/

extern ProError ProMdlRename   (ProMdl     handle, 
                                ProName    new_name);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlnameRename
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlnameRename instead.

               Renames the specified model. 

   Input Arguments:
      handle      -  The model handle
      new_name    -  The new name to assign to the model

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully renamed the model.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_BAD_CONTEXT - The function is not available in 
                           Design Test Mode.      
      PRO_TK_UNSUPPORTED - Unsupported model. For instance, models which come 
                           from Multi-CAD model approach,
                           are not supported in this release.


   See Also:
      ProMdlCurrentGet()
      ProMdlSave()
      ProMdlModificationVerify()
*/

extern ProError ProMdlnameRename( ProMdl     handle, 
                                  ProMdlName new_name);
/*
   Purpose:    Renames the specified model. 

			<b>Note: </b> In Creo 3 this function does not differ in behavior from 
			superseded ProMdlRename. In particular, new_name can be only of 
			ProName length. This function is reserved for future use.

   Input Arguments:
      handle      -  The model handle
      new_name    -  The new name to assign to the model

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully renamed the model.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
      PRO_TK_BAD_CONTEXT - The function is not available in 
        		   Design Test Mode.      
      PRO_TK_UNSUPPORTED - Unsupported model. For instance, models which come 
                           from Multi-CAD model approach,
                           are not supported in this release.


   See Also:
      ProMdlCurrentGet()
      ProMdlSave()
      ProMdlModificationVerify()
*/

extern ProError ProMdlCopy  (ProMdl      handle,
                             ProName     new_name,
                             ProMdl     *p_new_handle);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlnameCopy
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlnameCopy instead.

              Copies the specified model to the new one. 

   Input Arguments:
      handle             - The handle of the model to be copied.
      new_name           - The new name.

   Output Arguments:
      p_new_handle       - The new model handle to be initialized. This
                           can be NULL. 

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully copied the model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.
      PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come 
                             from Multi-CAD model approach,
                             are not supported in this release.
*/

extern ProError ProMdlnameCopy( ProMdl      handle,
                                   ProMdlName  new_name,
                             ProMdl     *p_new_handle);
/*
   Purpose:   Copies the specified model to the new one. 

			<b>Note: </b> In Creo 3 this function does not differ in behavior 
			from superseded ProMdlCopy. In particular, new_name can be only of 
			ProName length. This function is reserved for future use.


   Input Arguments:
      handle             - The handle of the model to be copied.
      new_name           - The new name.

   Output Arguments:
      p_new_handle       - The new model handle to be initialized. This
                           can be NULL. 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully copied the model.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.
      PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come 
                             from Multi-CAD model approach,
                             are not supported in this release.
*/

extern ProError ProMdlSave  (ProMdl    handle);
/*
   Purpose:    Stores the specified model to disk.

   Input Arguments:
      handle      - The model to store. ProMdlDisplay should be called before
                    this so that graphics/preview data is savedn case of
                    drawings, sketch etc. 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully stored the model along with
                          all its subordinate models, according to their 
                          modification status and the configuration option 
                          'save_objects'.
      PRO_TK_CANT_WRITE - Failed to save the model or at least one of its 
                          subordinate models due to unresolved non-overridable
                          conflicts in the target location. To obtain the exact
                          list of models that were not saved a notification on 
                          PRO_MDL_DBMS_FAILURE event can be applied.
      PRO_TK_GENERAL_ERROR - The entire operation failed.
      PRO_TK_BAD_INPUTS - The argument is invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.  
      PRO_TK_BAD_CONTEXT   - The function is not available in 
        		     Design Test Mode.      

   See Also:
      ProMdlCurrentGet()
      
*/

extern ProError ProMdlBackup (ProMdl    handle,
                              ProMdldata* model_info);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlnameBackup
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlnameBackup instead.

              Makes a backup of an object in memory to a disk in a 
              specified directory.  This function is equivalent to the 
              Creo Parametric command File, Backup.
<p>
              You can pass NULL as the handle, in which case you must 
              fill the name and type fields in <i>model_info</i>
              to specify which object in session will be backed up.
<p>
              The path field can a directory name or set to empty string.
              If the path is empty, the backup of the object is made in the
              current directory.
              NOTE 1:  Only path is used, host and device are ignored,
                       put everything in the path, "c:\\temp" for example.
              NOTE 2:  The name of the file created is the same as the model.
               
   Input Arguments:
      handle      - The model to back up 
      model_info  - The path information

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully made a backup of the 
                             model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_INVALID_PTR   - The handle is not correct, or the name and type
                             are invalid (for example, the object is not in 
                             memory).
      PRO_TK_INVALID_TYPE  - The specified type is invalid.
      PRO_TK_CANT_WRITE    - The system could not write to the specified 
                             directory.
      PRO_TK_INVALID_DIR   - The specified directory (path) is invalid.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed. 
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.
      PRO_TK_BAD_CONTEXT   - The function is not available in 
        		     Design Test Mode.      

*/

extern ProError ProMdlnameBackup (ProMdl    handle,
                                     ProPath   backup_dir);
/*
   Purpose:   Makes a backup of an object in memory to a disk in a 
              specified directory.  This function is equivalent to the 
              Creo Parametric command File, Backup.
<p>
              You can pass NULL as the handle, in which case the <i>backup_dir</i>
              path must contain filename of object in session to be backed up.
<p>
              If the <i>backup_dir</i> is empty, the backup of the object 
              is made in the current directory.
              NOTE 1:  The name of the file created is the same as the model.
               
			<b>Note:</b> In Creo 3 this function does not support names longer than 
			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for longer names will be added in a future release. 

   Input Arguments:
      handle      - The model to back up 
      backup_dir  - The backup path information

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully made a backup of the 
                             model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_INVALID_PTR   - The handle is not correct, or the name and type
                             are invalid (for example, the object is not in 
                             memory).
      PRO_TK_INVALID_TYPE  - The specified type is invalid.
      PRO_TK_CANT_WRITE    - The system could not write to the specified 
                             directory.
      PRO_TK_INVALID_DIR   - The specified directory (path) is invalid.
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed. 
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.
      PRO_TK_BAD_CONTEXT   - The function is not available in 
                             Design Test Mode.      

*/

extern ProError ProMdlRetrieve  (ProFamilyName name, 
				 ProMdlType    type,
                                 ProMdl       *p_handle); 
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlnameRetrieve
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlnameRetrieve instead.

              Retrieves the specified model and initializes the handle.
              <p>
              The function retrieves the model
              into memory, but neither displays the model nor
              makes it the current model.
              <p>
              If retrieving an assembly, and errors occur in regeneration,
              the assembly will include suppressed features.  The function
              ProSolidRetrievalErrorsGet identifies if errors occurred.


   Input Arguments:
      name         -  The name of the model to retrieve
      type         -  The type of the model to retrieve

   Output Arguments:
      p_handle     -  The handle to the retrieved model

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The model was not found in the current directory.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.

   See Also:
      ProSolidRetrievalErrorsGet()
*/

extern ProError ProMdlnameRetrieve  (ProFamilyMdlName name, 
                                     ProMdlfileType    type,
                                     ProMdl       *p_handle); 
/*
   Purpose:   Retrieves the specified model and initializes the handle.
	      <p>
	      The function retrieves the model
	      into memory, but neither displays the model nor
	      makes it the current model.
	      <p>
	      If retrieving an assembly, and errors occur in regeneration,
	      the assembly will include suppressed features.  The function
	      ProSolidRetrievalErrorsGet identifies if errors occurred.

		  <b>Note:</b> In Creo 3 this function does not support names longer than 
		  80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
		  The support for ProFamilyMdlName will be added in a future release. 

   Input Arguments:
      name         -  The name of the model to retrieve
      type         -  The type of the model to retrieve

   Output Arguments:
      p_handle     -  The handle to the retrieved model

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid.
      PRO_TK_E_NOT_FOUND   - The model was not found in the current directory.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.
      PRO_TK_BAD_CONTEXT  -  The Multi-CAD model is not being retrieved from an 
      			     active Windchill server.

   See Also:
      ProSolidRetrievalErrorsGet()
*/

extern ProError ProMdlLoad  (ProPath      full_path, 
                             ProMdlType   type,
                             ProBoolean   ask_user_about_reps, 
                             ProMdl       *p_handle); 
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlFiletypeLoad
   Purpose: <b>Note:</b> This function is deprecated
	      Use ProMdlFiletypeLoad instead.

	      Retrieves the specified model and initializes the handle.
          
	      <p>
	      The function retrieves the model
	      into memory, but neither displays the model nor
	      makes it the current model. Differs from ProMdlRetrieve
              in that the caller can specify the location of the model
              in addition to its name.
	      <p>
	      If retrieving an assembly, and errors occur in regeneration,
	      the assembly will include suppressed features.  The function
	      ProSolidRetrievalErrorsGet identifies if errors occurred.


   Input Arguments:
      full_path    -  The full path of the model to be retrieved,
                      including the name, and optionally the location
                      and extension.
      type         -  The type of the model to retrieve, or PRO_MDL_UNUSED
                      if full_path includes an extension.
      ask_user_about_reps - If TRUE, the Open Rep dialog may be presented,
                            allowing the user to specify which simplified
                            representation of the model should be retrieved.

   Output Arguments:
      p_handle     -  The handle to the retrieved model

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_CANT_OPEN  - The model exists but is not readable.
      PRO_TK_E_NOT_FOUND   - The model does not exist, or was not found
      PRO_TK_INVALID_FILE  - The model is not a Creo Parametric model.
      PRO_TK_INVALID_NAME  - The model name is too long.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.
      PRO_TK_GENERAL_ERROR - The model could not be retrieved.

    See Also:
      ProSolidRetrievalErrorsGet()
*/

extern ProError ProMdlMultipleRetrieve ( ProName* names, ProBoolean ui_flag);
/*
   DEPRECATED: Since Wildfire 3
   SUCCESSORS: NONE
   Purpose:
              <b>Note:</b> Use of this function is deprecated due to the limit
              on the length of the model names.
	 <p>
              Retrieves the models specified in the names list and
              initializes their handles.
	 <p>
	      If retrieving an assembly, and errors occur in regeneration,
	      the assembly will include suppressed features.  The function
	      ProSolidRetrievalErrorsGet identifies if errors occurred.

   Input Arguments:
       names            -   A list of the model names to be retrieved. Names
       			    must include type suffix (e.g., ".prt"); version
			    numbers will be ignored.
       ui_flag          -   When true, this flag indicates that retrieved
                            models will be displayed.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved all of the models.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on these models.
      Any positive integer - Some retrievals failed. The value of this error
                             indicates how many of the input objects failed
                             to retrieve.

   See Also:
      ProSolidRetrievalErrorsGet()   
*/

extern ProError ProMdlErase  (ProMdl    handle);
/*
   Purpose: Erases the specified model from memory. When erasing the 
            active model, graphic display is cleared immediately, but 
            data is not cleared until the next command gets processed.
			<p> <b>
            NOTE:
			<p> </b>
			The erasing action caused by this function will be finished only 
			after the execution control is returned to Creo Parametric. Therefore, 
			calling other functions after this function without returning the control may 
			lead to an unpredicted behavior.

   Input Arguments:
      handle       - The model to erase 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully erased the model.
      PRO_TK_BAD_INPUTS - The argument is invalid.
      PRO_TK_E_DEADLOCK - The Creo Parametric user interface is not prepared
                          to handle this request (because it is blocked by
                          another process such as an OLE container activation).
*/

extern ProError ProMdlEraseAll(
ProMdl model);

/*
  Purpose: Erases a model and all the models that it uses, except
           those also used by other models in session. For example, it
           erases recursively all subassemblies of an assembly, and
           all solids referenced from a drawing.  It also works in
           cases where some of the models to be erased have mutual
           dependencies. When erasing the active model, graphic display 
           is cleared immediately, but data is not cleared until the 
           next command gets processed.
		   	<p> <b>
            NOTE:
			<p> </b>
		   	The erasing action caused by this function will be finished only 
			after the execution control is returned to Creo Parametric. Therefore, 
			calling other functions after this function without returning the control may 
			lead to an unpredicted behavior.

  Input Arguments:
     model - The model to be erased 

  Output Arguments:
     None

  Return Values:
     PRO_TK_NO_ERROR
     PRO_TK_BAD_INPUTS
     PRO_TK_BAD_CONTEXT - Current User Interface context does not allow
                          erasure of models (for example, when the 
                          Erase button is grayed out).
     PRO_TK_E_IN_USE - The model could not be erased because it is in use,
                       for example by another model in the session.
*/

extern ProError ProMdlEraseNotDisplayed( void );
/*
   Purpose:  Erases all models not referenced in windows from session. 

   Input Arguments:
      None 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully erased the models.
      PRO_TK_E_BUSY        - Creo Parametric is in a state where erase isn't allowed.
      PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProMdlDelete  (ProMdl    handle);
/*
   Purpose:  Deletes the specified model from memory and disk. 

   Input Arguments:
      handle       - The model to delete 

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully deleted the model.
      PRO_TK_BAD_INPUTS - The argument is invalid.
      PRO_TK_BAD_CONTEXT - The function is not available in 
          		   Design Test Mode.      

*/

extern ProError ProMdlfileCopy ( ProMdlType   mdl_type,
                                 ProName      from_name,
                                 ProName      to_name );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlfileMdlnameCopy
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlfileMdlnameCopy instead.

             Copies the disk file for a specified object to another named file.

   Input Arguments:
      mdl_type  - The model type 
      from_name - The model to be copied from
      to_name   - The model copied to

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully copied the file. 
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid. 
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed. 
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.
      PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come 
                             from Multi-CAD model approach,
                             are not supported in this release.
*/

extern ProError ProMdlfileMdlnameCopy ( ProMdlfileType   mdl_type,
                                        ProMdlName   from_name,
                                        ProMdlName   to_name );
/*
   Purpose:  Copies the disk file for a specified object to another named file.

			<b>Note: </b> In Creo 3 this function does not differ in behavior from 
			superseded ProMdlfileCopy. In particular, from_name and to_name can be 
			only of ProName length. This function is reserved for future use.


   Input Arguments:
      mdl_type  - The model type 
      from_name - The model to be copied from
      to_name   - The model copied to

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully copied the file. 
      PRO_TK_BAD_INPUTS    - One or more of the arguments are invalid. 
      PRO_TK_GENERAL_ERROR - A general error occurred and the function failed. 
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.
	  PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come 
                             from Multi-CAD model approach,
                             are not supported in this release.
*/

extern ProError ProMdlDisplay ( ProMdl model );
/*
   Purpose:  Displays the specified model in the current view.
             <b>Note</b>:
<ul>
             <li>If no model is displayed, the specified model is placed in the
               base window.
             <li>If the specified model has been assigned a new window, the model
               will be displayed in the new window.
</ul>
 
             If <i>model</i> is NULL, the
             function displays the object in the current window.  The
             valid types of model that can be displayed are as follows:
<ul>
             <li>PRO_MDL_ASSEMBLY 
             <li>PRO_MDL_PART 
	     <li>PRO_MDL_2DSECTION
             <li>PRO_MDL_DRAWING 
             <li>PRO_MDL_LAYOUT
             <li>PRO_MDL_DWGFORM 
             <li>PRO_MDL_MFG 
             <li>PRO_MDL_REPORT 
             <li>PRO_MDL_MARKUP
             <li>PRO_MDL_DIAGRAM
</ul>
             <b>Note: </b>Calling this function will update the display, but may not
             activate the UI. To achieve it, the model window should be activated 
             (for instance, by the user).

   Input Arguments:
      model   - The model to display

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully displayed the model.
      PRO_TK_E_NOT_FOUND   - The <i>model</i> is NULL, and there is no 
                             current object.
      PRO_TK_INVALID_PTR   - The specified model is not in memory.
      PRO_TK_GENERAL_ERROR - There was a general error and the function
                             failed.
      PRO_TK_INVALID_TYPE  - You specified an invalid model type.
*/

extern ProError ProMdlNameGet  (ProMdl     handle, 
                                ProName    name);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlMdlnameGet
   @UNDO: SAFE
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlMdlnameGet instead.

               Retrieves the name of the specified model. 

   Input Arguments:
      handle       -  The model handle.

   Output Arguments:
      name         -  The address of the memory area to be filled
                      in with the model name. You must allocate the space
                      for this argument.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the name.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProMdlMdlnameGet  (ProMdl     handle, 
                                       ProMdlName name);
/*
   Purpose:    Retrieves the name of the specified model. 

   			<b>Note:</b> In Creo 3 this function does not support names longer than
   			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlName will be added in a future release. 

   Input Arguments:
      handle       -  The model handle.

   Output Arguments:
      name         -  The address of the memory area to be filled
                      in with the model name. Free this argument using
                      ProWstringFree.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the name.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProMdlDisplaynameGet  (ProMdl          handle,
                                       ProBoolean      include_ext,
                                       ProMdlFileName  display_name);
/*
   Purpose:    Retrieves the display name of the model. 

   			<b>Note:</b> This name may be different from the name returned by
                        ProMdlMdlnameGet. For example, when the active model is an instance
                        of a native model, the display name will be the instance name.
                        For instances or configurations of non-native models, the display
                        name will consist of the model name and the instance name
                        or configuration name.

   			<b>Note:</b> In Creo 3 this function does not support names longer than
   			80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
			The support for ProMdlFileName will be added in a future release. 

   Input Arguments:
      handle       -  The model handle.
      include_ext  -  Indicates whether the name should include the file extension.
                      Use PRO_B_TRUE to use extension. Otherwise, use PRO_B_FALSE.

   Output Arguments:
      display_name -  The display name of the model.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the name.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProMdlDataGet  (ProMdl      handle,
                                ProMdldata *p_data);
/*
   @UNDO: SAFE
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlMdlnameGet, ProMdlExtensionGet, ProMdlOriginGet, ProFileMdlnameParse
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlMdlnameGet, ProMdlExtensionGet, 
            ProMdlOriginGet, ProFileMdlnameParse instead.

             Retrieves information about the file from which the specified model was retrieved. 

   Input Arguments:
      handle       -  The model handle.

   Output Arguments:
      p_data       -  The <i>ProMdldata</i> structure to be filled in. You must
                      allocate the memory for this argument.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS    - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - The information could not be obtained.
      PRO_TK_UNSUPPORTED   - Unsupported model. For instance, models which come 
                             from Multi-CAD model approach,
                             are not supported in this release.
*/

extern ProError ProMdlExtensionGet (ProMdl handle, ProMdlExtension ext);
/*
   @UNDO: SAFE
   Purpose: Retrieves the file extension from which the specified model was retrieved.

   Input Arguments:
      handle       -  The model handle.

   Output Arguments:
      ext          -  Buffer where file extension will be copied into.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - The information could not be obtained.
*/

extern ProError ProMdlDirectoryPathGet (ProMdl handle, ProPath dir_path);
/*
   Purpose: Retrieves path to the directory where the model will be saved.
            It is the target (not origin) home directory of the model.

   Input Arguments:
      handle       -  The model handle.

   Output Arguments:
      dir_path     -  Path to the directory where the model will be saved.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
      PRO_TK_GENERAL_ERROR - The information could not be obtained.
*/


extern ProError ProMdlCurrentGet    (ProMdl     *p_handle);
/*
   @UNDO: SAFE
   Purpose:  Initializes the <i>p_handle</i> with the current Creo Parametric 
             object. 

   Input Arguments:
      None

   Output Arguments:
      p_handle     - The model handle
 
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully initialized the handle.
      PRO_TK_BAD_CONTEXT - The current Creo Parametric object is not set.
     
*/

extern ProError ProMdlModificationVerify (ProMdl       handle, 
                                          ProBoolean  *p_modified);
/*
   Purpose:  Verifies whether the specified model has been modified since the 
             last save. 

   Input Arguments:
      handle       -  The <i>ProMdl</i> to verify. 

   Output Arguments:
      p_modified   -  This is PRO_B_TRUE if the model has been modified.
                      Otherwise, this is PRO_B_FALSE.  
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully verified the model.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProMdlVerstampGet  (ProMdl      model,
                                    ProWVerstamp *p_stamp);
/*
   Purpose:  Retrieves the version stamp of the specified model.
            
   Input Arguments:
      model             - The model from which to retrieve the stamp.
 
   Output Arguments:
      p_stamp           - The version stamp. The function allocates the
                          memory for the version stamp. To free the memory, 
                          call <b>ProVerstampFree()</b>.
   
   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the stamp.
      PRO_TK_BAD_INPUTS - The input argument is invalid.

   See Also:
      ProVerstampFree()
*/ 

extern ProError ProMdlTypeGet ( ProMdl model, 
                                ProMdlType* p_type );
/*
   @UNDO: SAFE
   Purpose: Returns the type of model (such as 
            PRO_PART or PRO_ASSEMBLY).
   
   Input Arguments:
      model - A model pointer whose type needs to returned.
 
   Output Arguments:
      p_type - The type of model. If the function fails, this is 
               set to PRO_TYPE_UNUSED. 

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the type
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProMdlSubtypeGet( ProMdl model,
                                           ProMdlsubtype *subtype);
/*

   Purpose: Returns the subtype of a model 

   Input Arguments: 
       model     - A model pointer whose subtype needs to returned

   Output Arguments:
       subtype   - The type of model. If the function fails, this is
                   set to PROMDLSTYPE_NONE.   
 

   Return Values:
        PRO_TK_NO_ERROR   - The function successfully retrieved the type
        PRO_TK_BAD_INPUTS - The input argument is invalid.
        PRO_TK_BAD_CONTEXT - the model has no subtype
*/

extern ProError ProFileSubtypeGet(ProPath file, ProMdlfileType *file_type,
                                  ProMdlType *type, ProMdlsubtype *subtype);

/*

  Purpose: Returns the file_type, model_type and/or subtype of a file.
           For native Creo models, file_type == type.

  Input Arguments:
     file - The path to the file.

  Output Arguments:
     file_type - The type of the file.
     type -      The type of the model the file will be in Creo session.
     subtype -   The subtype of the model, PROMDLSTYPE_NONE for types which
                 do not have subtypes.  Each of these can be NULL.

  Return Values:
     PRO_TK_NO_ERROR   - The values were successfully determined.
     PRO_TK_BAD_INPUTS - file was NULL, empty, or invalid.
     PRO_TK_NOT_EXIST  - The file could not be found.
     PRO_TK_CANT_OPEN  - The file could not be opened, or could not be read. 

*/

extern ProError ProMdlIdGet ( ProMdl model, 
                              int* p_id );
/*
   @UNDO: SAFE
   Purpose: Returns the identifier of the model.
   
   Input Arguments:
      model - A model pointer whose identifier needs to returned.
 
   Output Arguments:
      p_id - The identifier of the model. If the function fails,
             this is set to PRO_VALUE_UNUSED.  

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the identifier.
      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProMdlDeclaredList (ProMdl model,
                                    ProModel **p_declared_list,
                                    int* p_count);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlDeclaredDataList
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlDeclaredDataList instead.

            Finds all the first-level objects declared for the
            specified object.  For example, if notebook A is declared
            in notebook B and notebook B is declared in part P, only notebook
            B will be returned.
   
   Input Arguments:
      model - The part, assembly or notebook.
 
   Output Arguments:
      p_declared_list - A <i>ProArray</i> of <i>ProModel</i> declared object
                        names and types. The function allocates
                        memory for this argument, but you must free 
                        it. To free the memory, call the function 
                        <b>ProArrayFree()</b>.
      p_count         - The number of objects in <i>p_declared_list</i>.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the 
                           information.
      PRO_TK_E_NOT_FOUND - No objects were found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProArrayFree()
*/

extern ProError ProMdlDeclaredDataList (ProMdl model,
                                        ProMdlnameShortdata **p_declared_list,
                                        ProMdlfileType **model_file_types,
                                        int* p_count);
/*
   Purpose: Finds all the first-level objects declared for the
            specified object.  For example, if notebook A is declared
            in notebook B and notebook B is declared in part P, only notebook
            B will be returned.
   
            <b>Note:</b> In Creo 3 this function does not support names longer than 
            80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
            The support for longer names will be added in a future release. 

   Input Arguments:
      model - The part, assembly or notebook. Cannot be NULL.
 
   Output Arguments:
      p_declared_list  - A <i>ProArray</i> of <i>ProModel</i> declared object
                         names and types. Call ProArrayFree 
                         to free this memory. Cannot be NULL.
      model_file_types - A ProArray of dependency types, same length as p_dependencies_list
                         and in the same order of dependencies.
                           Cannot be NULL.
      p_count          - The number of objects in <i>p_declared_list</i>.
                         Cannot be NULL.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the 
                           information.
      PRO_TK_E_NOT_FOUND - No objects were found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProArrayFree()
*/


extern ProError ProMdlDependenciesList (ProMdl model,
                                        ProModel **p_dependencies_list,
                                       int* p_count );
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlDependenciesDataList
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlDependenciesDataList instead.

            Finds the first-level dependencies for an object in
            the Creo Parametric workspace. Be sure to cleanup dependencies
            database by calling ProMdlDependenciesCleanup() to ensure up to date
            results.

   Input Arguments:
      model - A valid model pointer.

   Output Arguments:
      p_dependencies_list - An array of dependencies. The function
                            allocates the memory for this argument. To free the
                            memory, call the function <b>ProArrayFree()</b>.
                            This list is sorted with primary key being type
                            and secondary key being model name.
      p_count             - The number of objects in the 
                            <i>p_dependencies_list</i>.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_E_NOT_FOUND - No dependencies were found.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProArrayFree()
*/

extern ProError ProMdlDependenciesDataList (ProMdl model,
                                            ProMdlnameShortdata **p_dependencies_list,
                                            ProMdlfileType **model_file_types,
                                            int* p_count );
/*
   Purpose: Finds the first-level dependencies for an object in
            the Creo Parametric workspace. Be sure to cleanup dependencies
            database by calling ProMdlDependenciesCleanup() to ensure up to date
            results.

            <b>Note:</b> The returned dependencies are not sorted.

            <b>Note:</b> In Creo 3 this function does not support names longer than 
            80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
            The support for longer names will be added in a future release. 

   Input Arguments:
      model - A valid model pointer. Cannot be NULL.

   Output Arguments:
      p_dependencies_list - A ProArray of dependencies.
                            Call ProArrayFree to free this
                            memory. Cannot be NULL.

      model_file_types   - A ProArray of dependency types, same length as p_dependencies_list
                           and in the same order of dependencies.
                           Cannot be NULL.

      p_count             - The number of objects in the 
                            <i>p_dependencies_list</i> 
                            (or less if returns PRO_TK_BAD_CONTEXT).
                            Cannot be NULL.
 
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_E_NOT_FOUND - No dependencies were found.
      PRO_TK_BAD_CONTEXT - Some dependencies could not be processed and were skipped.
                           In this case p_count will be less than 
                           the length of both ProArrays.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProArrayFree()
*/

extern ProError ProMdlDependenciesCleanup (ProMdl p_model);
/*
   Purpose: Forces cleaning up dependencies database of an object in
            the Creo Parametric workspace. This function should not be called
            during reference altering operations like feature create, edit
            definition or restructure.

   Input Arguments:
      p_model - A valid model pointer.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully cleaned up the database.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_NOT_VALID   - The supplied solid is in the state, not allowing
                           to cleanup dependencies i.e. inside feature creation.
*/

extern ProError ProMdlWindowGet ( ProMdl mdl,
                                  int* window_id );
/*
   Purpose:     Finds the window with the specified model as the 
		top-level object.

   Input Arguments:
        mdl        - The model that is a top-level object

   Output Arguments:

	window_id  - The window identifier

   Return Values:
        PRO_TK_NO_ERROR     - The function successfully found the window.
        PRO_TK_E_NOT_FOUND  - The function was not able to find the window.
*/

extern ProError ProSessionMdlList (ProMdlType  model_type,
                                   ProMdl    **p_model_array,
                                   int        *p_count);
/*
   Purpose: Retrieves the list of objects of the specified type in
            the Creo Parametric workspace.

   Input Arguments:
      model_type  - A valid model type (PRO_PART, PRO_ASSEMBLY, and so on).

   Output Arguments:
      p_model_array - An array of objects found. The function
                      allocates the memory for this argument. To free it,
                      call the function <b>ProArrayFree()</b>.
      p_count       - The number of models in <i>p_model_array</i>.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_E_NOT_FOUND - No objects were found in the workspace.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:
      ProArrayFree()
*/

extern ProError ProMdlToModelitem ( ProMdl mdl, 
                                    ProModelitem* p_model_item );
/*
   Purpose: Converts a <i>ProMdl</i> to a <i>ProModelitem</i>.

   Input Arguments:
     mdl          - The handle to a valid model

   Output Arguments:
     p_model_item - The <i>ProModelitem</i> 

   Return Values:
      PRO_TK_NO_ERROR     - The function was successful.
      PRO_TK_BAD_INPUTS   - An argument is NULL.
      PRO_TK_INVALID_PTR  - The handle is invalid. 
*/


extern ProError ProTreetoolRefresh (ProMdl model);
/*
   Purpose:     Refreshes the display of the model tree.
 
   Input Arguments:
        model                   - The model whose tree is to be refreshed

   Output Arguments:
        None

   Return Values:
        PRO_TK_NO_ERROR         - The function successfully refreshed the tree.
        PRO_TK_BAD_INPUTS       - The input argument is invalid.
        PRO_TK_E_NOT_FOUND      - The model tree is not present.
*/


typedef ProError (*ProMdlSavePreAction) (ProModel *r_model_name);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelSavePreAction 
   Purpose: <b>Note:</b> This function is deprecated. 
	          Use ProModelSavePreAction instead.
            
            This is the notification function called before saving a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type PRO_MDL_SAVE_PRE.
            If the model name is initialized by this function, the
            saving utility will not interactively prompt for the model name
            to be saved.
<p>
            If this function returns an error, the saving action will be
            aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_model_name    - The user-supplied function should initialize this
                        variable to the model name to be saved. If it is not
                        initialized, the system prompts for the model name 
                        interactively.

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. Model saving will be stopped.

   See Also:
      ProNotificationSet()
*/

typedef ProError (*ProModelSavePreAction) (ProPath r_model_path);

/*
   Purpose: This is the notification function called before saving a model.
<p>
            Users must supply this function by calling <b>ProNotificationSet()</b>
            with the notify type PRO_MODEL_SAVE_PRE.
            If the model name is initialized by this function, the
            saving utility will not interactively prompt for the model name
            to be saved.
<p>
            If this function returns an error, the saving action will be
            aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_model_path    - The user-supplied function should initialize this
                        variable to the path to the model to be saved. If it
                        is not initialized, the system prompts for the model
                        path interactively.

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. Model saving will be stopped.

   See Also:
      ProNotificationSet()
*/

typedef ProError (*ProModelSavePreAllAction) (ProMdl p_mdl);

/*
   Purpose: This is the notification function called before saving each model.
<p>
            Users must supply this function by calling <b>ProNotificationSet()</b>
            with the notify type PRO_MODEL_SAVE_PRE_ALL.
<p>
            If this function returns an error, the saving action will be
            aborted by Creo Parametric for this model.

            This is called for kinds of user actions (Save A Copy, Checkin)
            which do NOT call ProModelSavePreAction.
            May be called more than once due to conflict resolution.

   Input Arguments:
      p_mdl           - The model being saved.
      
   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. Model saving will be stopped.

   See Also:
      ProNotificationSet()
*/

typedef ProError (*ProMdlSavePostAction) (ProMdldata *p_model_data);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelSavePostAction 
   Purpose: <b>Note:</b> This function is deprecated. 
        	  Use ProModelSavePostAction instead.

            This is the notification function called after an explicit
            save of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_SAVE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on saves of models dependent
            upon the model explicitly called.            

   Input Arguments:
      p_model_data    - The information for the model that was just saved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlSavePostAllAction()

*/

typedef ProError (*ProModelSavePostAction) (ProPath model_path,
                                            ProMdlfileType model_file_type);

/*
   Purpose: This is the notification function called after an explicit
            save of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_SAVE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on saves of models dependent
            upon the model explicitly called.            

   Input Arguments:
      model_path      - Path to the model that was just saved
      model_file_type - Model file type that was just saved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelSavePostAllAction()

*/

typedef ProError (*ProMdlSavePostAllAction) (ProMdldata *p_model_data);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelSavePostAllAction 
   Purpose: <b>Note:</b> This function is deprecated. 
        	  Use ProModelSavePostAllAction instead.

            This is the notification function called after a save of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProMdlSavePostAction()</b> in that it
            is called only once, even if a top-level model save causes a recur-
            sive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_SAVE_POST_ALL.

   Input Arguments:
      p_model_data    - The information for the top-level model that was just
                        saved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlSavePostAction()

*/

typedef ProError (*ProModelSavePostAllAction) (ProPath model_path,
                                               ProMdlfileType model_file_type);

/*
   Purpose: This is the notification function called after a save of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProModelSavePostAction()</b> in
            that it is called only once, even if a top-level model save causes
            a recursive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_SAVE_POST_ALL.

   Input Arguments:
      model_path      - Path the top-level model that was just saved
      model_file_type - Model file type that was just saved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelSavePostAction()

*/

typedef ProError (*ProMdlCopyPreAction) (ProModel *r_from, ProModel *r_to);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelCopyPreAction 
   Purpose: <b>Note:</b> This function is deprecated.
            Use ProModelCopyPreAction instead.

            This is the notification function called before copying a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type PRO_MDL_COPY_PRE.
<p>
            If the function supplies the model to be copied (<i>r_from</i>)
            and the model to be copied to (<i>r_to</i>), the interactive
            prompting of this information is skipped.
            If this function returns an error, the copying action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_from          - The data of the model to be copied
      r_to            - The model to which to copy

   Return Values:
      PRO_TK_NO_ERROR - Successful exit, proceed.
      Other           - An internal error was encountered, so the copy 
                        action will be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProModelCopyPreAction) (ProMdl *r_from, ProPath r_to);

/*
   Purpose: This is the notification function called before copying a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type PRO_MODEL_COPY_PRE.
<p>
            If the function supplies the model to be copied (<i>r_from</i>)
            and the model path to be copied to (<i>r_to</i>), the interactive
            prompting of this information is skipped.
            If this function returns an error, the copying action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_from          - The data of the model to be copied
      r_to            - The model path to which to copy

   Return Values:
      PRO_TK_NO_ERROR - Successful exit, proceed.
      Other           - An internal error was encountered, so the copy 
                        action will be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlCopyPostAction) (ProModel *p_from, ProModel *p_to);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelCopyPostAction 
   Purpose: <b>Note:</b> This function is deprecated. 
	          Use ProModelCopyPostAction instead.

            This is the notification function called after an explicit
            copy of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_COPY_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on copies of models dependent
            upon the model explicitly called.            

   Input Arguments:
      p_from          - The model data from which the copy was made
      p_to            - The data of model to which the copy was made
 
   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlCopyPostAllAction()

*/

typedef ProError (*ProModelCopyPostAction) (ProMdl from, ProPath to, ProMdlfileType to_model_type);

/*
   Purpose: This is the notification function called after an explicit
            copy of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_COPY_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on copies of models dependent
            upon the model explicitly called.            

   Input Arguments:
      from            - The model data from which the copy was made
      to              - The path of model to which the copy was made
      to_model_type   - The type of model to which the copy was made
 
   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelCopyPostAllAction()

*/

typedef ProError (*ProMdlCopyPostAllAction) (ProModel *p_from, ProModel *p_to);
 
/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelCopyPostAllAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelCopyPostAllAction instead.

            This is the notification function called after a copy of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProMdlCopyPostAction()</b> in that it
            is called only once, even if a top-level model save causes a recur-
            sive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_COPY_POST_ALL.
 
   Input Arguments:
      p_from          - The top-level model data from which the copy was made
      p_to            - The model to which the copy was made
 
   Output Arguments:
      None
 
   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlCopyPostAction()

*/

typedef ProError (*ProModelCopyPostAllAction) (ProMdl from, ProPath to, ProMdlfileType to_model_type);
 
/*
   Purpose: This is the notification function called after a copy of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProMdlCopyPostAction()</b> in that it
            is called only once, even if a top-level model save causes a recur-
            sive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_COPY_POST_ALL.
 
   Input Arguments:
      from            - The top-level model data from which the copy was made
      to              - The model to which the copy was made
      to_model_type   - The type of model to which the copy was made
 
   Output Arguments:
      None
 
   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelCopyPostAction()

*/

typedef ProError (*ProMdlRenamePreAction) (ProModel *r_from, ProModel *r_to);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelRenamePreAction 
   Purpose: <b>Note:</b> This function is deprecated. 
	          Use ProModelRenamePreAction instead.

            This is the notification function called before renaming a model.
 <p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify 
	    type PRO_MDL_RENAME_PRE.
<p>
            If the function does not supply the model to be renamed 
            (<i>r_from</i>) and the model to be renamed to (<i>r_to</i>),
            the system prompts interactively for this information.
<p> 
            If this function returns an error, the renaming action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_from          - The model to be renamed
      r_to            - The new name of the model 

   Return Values:
      PRO_TK_NO_ERROR - Successful exit, proceed.
      Other           - An internal error was encountered, so the
                        rename action will be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProModelRenamePreAction) (ProMdl *r_from,
                                             ProMdlFileName r_to);

/*
   Purpose: This is the notification function called before renaming a model.
 <p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify 
	        type PRO_MODEL_RENAME_PRE.
<p>
            If the function does not supply the model to be renamed 
            (<i>r_from</i>) and the model file name to be renamed to
            (<i>r_to</i>), the system prompts interactively for this
            information.
<p> 
            If this function returns an error, the renaming action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_from          - The model to be renamed
      r_to            - The new name of the model 

   Return Values:
      PRO_TK_NO_ERROR - Successful exit, proceed.
      Other           - An internal error was encountered, so the
                        rename action will be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlRenamePostAction) (ProModel *p_from, ProModel *p_to);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelRenamePostAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelRenamePostAction instead.

            This is the notification function called after renaming a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_RENAME_POST.

   Input Arguments:
      p_from          - The data of the model to be renamed
      p_to            - The data of the model to which renaming was done

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProModelRenamePostAction) (ProMdl model, ProMdlFileName old_name);

/*
   Purpose: This is the notification function called after renaming a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_RENAME_POST.

   Input Arguments:
      model            - The data of the renamed model
      old_name              - The old name of the model that was renamed

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProModelRenamePostAllAction) (ProMdl model,
                                                 ProMdlFileName old_name);

/*
   Purpose: This is the notification function called after renaming each model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_RENAME_POST_ALL.

   Input Arguments:
      model            - The data of the renamed model
      old_name         - The old name of the model that was renamed

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlErasePreAction) ( void );

/*
   Purpose: This is the notification function called before erasing a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type PRO_MDL_ERASE_PRE.
<p>
            If this function returns an error, the erasing action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. Model erasing will be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlErasePostAction) (ProModel *p_erased_mdl);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelErasePostAction 
   Purpose: <b>Note:</b> This function is deprecated. 
	          Use ProModelErasePostAction instead.

            This is the notification function called after an explicit
            erase of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_ERASE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on erases of models dependent
            upon the model explicitly called.            

   Input Arguments:
      p_erased_mdl    - The information for the model that was just erased

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlErasePostAllAction()

*/

typedef ProError (*ProModelErasePostAction) (ProMdl p_erased_mdl);

/*
   Purpose: This is the notification function called after an explicit
            erase of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_ERASE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on erases of models dependent
            upon the model explicitly called.            

   Input Arguments:
      p_erased_mdl    - The information for the model that was just erased

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelErasePostAllAction()

*/

typedef ProError (*ProMdlErasePostAllAction) (ProMdldata *p_model_data);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelErasePostAllAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelErasePostAllAction instead.

            This is the notification function called after an erase of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProMdlErasePostAction()</b> in that it
            is called only once, even if a top-level model save causes a recur-
            sive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_ERASE_POST_ALL.

   Input Arguments:
      p_model_data    - The information for the top-level model that was just
                        erased
 
   Output Arguments:
      None
 
   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlErasePostAction()
*/

typedef ProError (*ProModelErasePostAllAction) (ProMdl p_model_data);

/*
   Purpose: This is the notification function called after an erase of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProModelErasePostAction()</b> in
            that it is called only once, even if a top-level model save causes
            a recursive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_ERASE_POST_ALL.

   Input Arguments:
      p_model_data    - The information for the top-level model that was just
                        erased
 
   Output Arguments:
      None
 
   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelErasePostAction()
*/

typedef ProError (*ProMdlPurgePreAction) (ProModel *r_model_name);

/*
   Purpose: This is the notification function called before purging a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type PRO_MDL_PURGE_PRE.
<p>
            If the model name is initialized by this function, the
            purging utility will not interactively prompt for the model name
            to be purged.
<p>
            If this function returns an error, the purging action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      r_model_name    - The user-supplied function should initialize this
                        variable to the model name to be purged. If this 
                        is not initialized, the system prompts 
                        for the model name interactively. 

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. Model purging will be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlPurgePostAction) (ProModel *p_purged_mdl);

/*
   Purpose: This is the notification function called after purging a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_PURGE_POST.

   Input Arguments:
      p_purged_mdl    - The information for the model that was just purged

   Output Arguments:
      None
 
   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet()

*/
 
typedef ProError (*ProMdlDeletePreAction) ( void );
 
/*
   Purpose: This is the notification function called before deleting a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_DELETE_PRE.
<p>
            If this function returns an error, the deleting action
            will be aborted by Creo Parametric.

   Input Arguments:
      None

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. Model deletion will 
                        be stopped.
   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlDeletePostAction) (ProModel *p_deleted_mdl);

/*
   Purpose: This is the notification function called after an explicit
            delete of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_DELETE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on deletes of models dependent
            upon the model explicitly called.            
 
   Input Arguments:
      p_deleted_mdl    - The information for the model that was just deleted
 
   Output Arguments:
      None
 
   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlDeletePostAllAction()
*/
 
typedef ProError (*ProMdlDeletePostAllAction) (ProMdldata *p_model_data);
 
/*
   Purpose: This is the notification function called after a delete of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProMdlDeletePostAction()</b> in that
            it is called only once, even if a top-level model save causes a 
            recursive saving action.
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_DELETE_POST_ALL.

   Input Arguments:
      p_model_data    - The information for the top-level model that was just
                        deleted

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlDeletePostAction()

*/

typedef ProError (*ProMdlRetrievePreAction)  (
                    ProPath     path,
                    ProFileName file_name,
                    ProFileRetrieveOpt **p_retr_options_arr);
/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelRetrievePreAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelRetrievePreAction instead.

            This is the notification function called before retrieving a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type
            PRO_MDL_RETRIEVE_PRE.

<p> 
            <b>NOTE:</b> 
            This function is not called on retrieval of models using 
	    drag or double click in browser window. 
	    It gets called only when user clicks <b>File -> Open</b> button.
<p> 
            <b>Warning:</b>
            This notification blocks Creo Parametric's standard file open dialog.
	        It is developer's responsibility to substitute it with his own
            dialog through this function.

   Input Arguments:
	None

   Output Arguments:
	path                - The full path to the file
	file_name           - The complete file name 
			      (name + extension + version)
	p_retr_options_arr  - The retrieval options

   Return Values:
      Return values are not interpreted by Creo Parametric.
 
   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProModelRetrievePreAction)  (
                    ProPath     path,
                    ProFileRetrieveOpt **p_retr_options_arr);
/*
   Purpose: This is the notification function called before retrieving a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type
            PRO_MODEL_RETRIEVE_PRE.

<p> 
            <b>NOTE:</b> 
            This function is not called on retrieval of models using 
	    drag or double click in browser window. 
	    It gets called only when user clicks <b>File -> Open</b> button.
<p> 
            <b>Warning:</b>
            This notification blocks Creo Parametric's standard file open dialog.
	        It is developer's responsibility to substitute it with his own
            dialog through this function.

   Input Arguments:
	None

   Output Arguments:
	path                - Specify the full path to the model file to be retrieved. 
	                      This must be a valid path that includes the filename, 
						  extension, and version of the model.Do not use this
						  argument if you do not want the Creo Parametric Toolkit 
						  application to retrieve any model.

	p_retr_options_arr  - ProArray that contains the options to retrieve the model.
						  The Creo Parametric Toolkit application should allocate 
						  the memory for the retrieval options.


   Return Values:
    PRO_TK_NO_ERROR  -  The Toolkit application will send a request to Creo Parametric 
						  to retrieve the model specified by the arguments.
						  
    Other            -  Creo Parametric will not retrieve the model.
 
   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlRetrievePostAction) (ProModel *p_retrieved_mdl);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelRetrievePostAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelRetrievePostAction instead.

            This is the notification function called after explicit
            retrieval of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_RETRIEVE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on retrieval of models dependent
            upon the model explicitly called.            


   Input Arguments:
      p_retrieved_mdl    - The information for the model that was just 
                           retrieved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlRetrievePostAllAction()

*/

typedef ProError (*ProModelRetrievePostAction) (ProMdl p_retrieved_mdl);

/*
   Purpose: This is the notification function called after explicit
            retrieval of a model. 
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_RETRIEVE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on retrieval of models dependent
            upon the model explicitly called.            


   Input Arguments:
      p_retrieved_mdl    - The information for the model that was just 
                           retrieved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelRetrievePostAllAction()

*/

typedef ProError (*ProMdlRetrievePostAllAction) (ProMdldata *p_model_data);
 
/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelRetrievePostAllAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelRetrievePostAllAction instead.

            This is the notification function called after retrieval of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProMdlRetrievePostAction()</b> in that
            it is called only once, even if a top-level model retrieve causes a 
            recursive retrieval of a particular model. 
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_RETRIEVE_POST_ALL.

   Input Arguments:
      p_model_data    - The information for the top-level model that was just
                        retrieved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProMdlRetrievePostAction()

*/

typedef ProError (*ProModelRetrievePostAllAction) (ProMdl p_model_data);
 
/*
   Purpose: This is the notification function called after retrieval of any
            model, including models dependant on the model explicitly called.
            This function differs from <b>ProModelRetrievePostAction()</b> in
            that it is called only once, even if a top-level model retrieve
            causes a recursive retrieval of a particular model. 
<p>
            The user supplies this function by calling  
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_RETRIEVE_POST_ALL.

   Input Arguments:
      p_model_data    - The information for the top-level model that was just
                        retrieved

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet(), ProModelRetrievePostAction()

*/

typedef ProError (*ProMdlCreatePreAction)  (ProMdlType  mdl_type,
                                            int         sub_type,
                                            ProName     r_model_name,
                                            ProBoolean *r_allow_override);
/*
   Purpose: This is the notification function called before creating a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_CREATE_PRE.
<p>
            This function is invoked after the user specifies the type
            and subtype of a Creo Parametric model.


   Input Arguments:
      mdl_type - The model type (PRO_MDL_PART, PRO_MDL_ASSEMBLY, and so on)
      sub_type - The model subtype

    Output Arguments:
      r_model_name     - The model name assigned by the callback.
      r_allow_override - If this is PRO_B_FALSE, the supplied model name
                         cannot be overridden by the user.

    Return Values:
      PRO_TK_NO_ERROR  - Successful exit from this function.
      Other            - An error was encountered.  Model creation will be 
                         stopped.

    See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlStartAction)(ProName		name,
                                      ProMdlType	type,
                                      ProMdlsubtype	subtype);

/*

   Purpose:  Type for callback function for notification option
		PRO_MDL_START. The function is called after the
		user selects OK on the New dialog, if the option
		"Use default template" is unselected, and the
		notification has been defined by a call to
		ProNotificationSet(). The callback replaces
		Creo Parametric's interaction by which the user
		selects the start-part and defines its parameters.


   Input Arguments:
      name	- The name of the new model entered by the user on the New dialog.
      type	- The type of the new model
      subtype	- The subtype of the new model

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR	- The Creo Parametric TOOLKIT callback successfully created
			    the new model.
      PRO_TK_CONTINUE	- Creo Parametric should use the regular user interface
			    for defining the model.
      PRO_TK_USER_ABORT	- The user quit from the interaction controlled
			    by the callback. The File New command will
			    terminate.
      Other		- Some other error prevented the Creo Parametric TOOLKIT
                            application from creating the model.
                            The File New command will be teminated.
*/

typedef ProError (*ProMdlCreatePostAction) (ProModel *p_created_mdl);

/*
   Purpose: This is the notification function called after creating a model.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_CREATE_POST.

   Input Arguments:
      p_created_mdl   - The information for the model that was just created

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlDbmsFailureAction) (char       *dbms_action_string,
                                             ProMdldata *p_mdl1_data,
                                             ProMdldata *p_mdl2_data,
                                             ProError    status);

/*
   DEPRECATED: Since Creo 3.0
   SUCCESSORS: ProModelDbmsFailureAction 
   Purpose: <b>Note:</b> This function is deprecated. 
            Use ProModelDbmsFailureAction instead.

            This is the notification function called whenever any file
            management functionality was invoked and failed.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MDL_DBMS_FAILURE.
<p>
            The general format for the action (the argument 
            <i>dbms_action_string</i>) is as follows:
<pre>
                "menu_dbms_<action>_object"
</pre>
<p>
            Therefore, the possible failures are as follows:
<ul>
            <li>"menu_dbms_create_object" -- Creation failure
            <li>"menu_dbms_purge_object" -- Purge failure
            <li>"menu_dbms_rename_object" -- Rename failure
            <li>"menu_dbms_save_object" -- Save failure
            <li>"menu_dbms_copy_object" -- Copy failure
            <li>"dbms_save_object_all" -- Failure saving a list of models,
            <li>"dbms_copy_object_all" -- Failure copying a list of models,
            <li>"dbms_retrieve_object_all" -- Failure retrieving a list 
                 of models.
</ul>

   Input Arguments:
      dbms_action_string  -  The file management action that failed.

      p_mdl1_data         -  The data for the main model.

      p_mdl2_data         -  The data for the auxiliary model. This is 
                             initialized only in cases like copy and
                             rename.

      status              -  The internal error generated.

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:  
      ProNotificationSet()

*/

typedef ProError (*ProModelDbmsFailureAction) (char          *dbms_action_string,
                                               ProPath        mdl1_path,
                                               ProMdlfileType mdl1_file_type,
                                               ProPath        mdl2_path,
                                               ProMdlfileType mdl2_file_type,
                                               ProError       status);

/*
   Purpose: This is the notification function called whenever any file
            management functionality was invoked and failed.
<p>
            Users must supply this function by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_MODEL_DBMS_FAILURE.
<p>
            The general format for the action (the argument 
            <i>dbms_action_string</i>) is as follows:
<pre>
                "menu_dbms_<action>_object"
</pre>
<p>
            Therefore, the possible failures are as follows:
<ul>
            <li>"menu_dbms_create_object" -- Creation failure
            <li>"menu_dbms_purge_object" -- Purge failure
            <li>"menu_dbms_rename_object" -- Rename failure
            <li>"menu_dbms_save_object" -- Save failure
            <li>"menu_dbms_copy_object" -- Copy failure
            <li>"dbms_save_object_all" -- Failure saving a list of models,
            <li>"dbms_copy_object_all" -- Failure copying a list of models,
            <li>"dbms_retrieve_object_all" -- Failure retrieving a list 
                 of models.
</ul>

   Input Arguments:
      dbms_action_string  -  The file management action that failed.

      mdl1_path           -  Path the main model.

      mdl1_file_type      -  File type for the main model.

      mdl2_path           -  Path to the auxiliary model. This is 
                             initialized only in cases like copy and
                             rename.

      mdl2_file_type      -  File type for the auxiliary model. This is 
                             initialized only in cases like copy and
                             rename.

      status              -  The internal error generated.

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:  
      ProNotificationSet()

*/

typedef ProError (*ProMdlDisplayPreAction) (ProMdl mdl_handle);
 
/*
  Purpose: This is the notification function called before starting 
	   to display a model.
 <p>
           Users must supply this function by calling
           <b>ProNotificationSet()</b> with the notify type 
           PRO_MDL_DISPLAY_PRE.

  Input Arguments:
     mdl_handle      -  The model about to be displayed

  Output Arguments:
     None

  Return Values:
      Return values are not interpreted by Creo Parametric.

  See Also:
      ProNotificationSet()

*/

typedef ProError (*ProMdlDisplayPostAction) ( void );
 
/*
  Purpose: This is the notification function called after 
	   displaying a model.
 <p>
           Users must supply this function by calling
           <b>ProNotificationSet()</b> with the notify type 
           PRO_MDL_DISPLAY_POST.
 
  Input Arguments:
     None
 
  Output Arguments:
     None
 
  Return Values:
     Return values are not interpreted by Creo Parametric.

  See Also:
     ProNotificationSet()

*/

typedef ProError (*ProGtolVisitAction) ( ProGtol *gtol,
                                         ProError filter_status,
                                         ProAppData data );

/*
   Purpose:  Specifies function type for gtol visit action.

   Input Arguments:
      gtol          - The gtol being visited
      filter_status - The return value from the preceding call to the
                      the visit filter function
      data          - The application data passed to ProMdlGtolVisit()

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Continue visiting.
      other                - Stop visiting and return from ProMdlGtolVisit()
                             with this value.
*/


typedef ProError (*ProGtolFilterAction) ( ProGtol *gtol,
                                          ProAppData data );
/*
   Purpose:  Specifies function type for gtol filter action.

   Input Arguments:
      gtol          - The gtol being visited
      data          - The application data passed to ProMdlGtolVisit()

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR      - Calls the visit function if not NULL.
      PRO_TK_CONTINUE      - Skips to next gtol.
      PRO_TK_GENERAL_ERROR - Stops visiting.
*/

extern ProError ProMdlGtolVisit( ProMdl model,
                                 ProGtolVisitAction visit_action,
                                 ProGtolFilterAction filter_action,
                                 ProAppData data );
/*
   Purpose:    Visits all gtols stored in the specified model.

   Input Arguments:
      model         - The model that contains the gtols to be visited
      visit_action  - The visit action function
      filter_action - The filter action. If NULL, all gtols are visited 
                      using the action function.
      data          - Pointer to application-specific data to be passed
                      to the action functions.

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - The function visited all the items.
      PRO_TK_BAD_INPUTS - One or more inputs was invalid.
      PRO_TK_GENERAL_ERROR - Visiting was stopped by the return from the
                            visit action.
      PRO_TK_E_NOT_FOUND - There are no valid gtols in the model.
*/


extern ProError ProMdlIsModifiable(ProMdl p_model,
                                   ProBoolean show_ui,
                                   ProBoolean* can_modify);
/*
   Purpose: Check if given model is modifiable, indicating that the model 
            could be saved (without checking for any subordinate models). 
            For a generic model, if show_ui is PRO_B_TRUE, all its instances 
            are also checked.

   Input Arguments:
     p_model      - model to check access to.
     show_ui      - Indicates whether the Conflicts dialog should be shown to
                    user to resolve conflicts (if they are detected); when set
                    to PRO_B_FALSE no UI is enabled and the model is considered
                    as modifiable if there are no conflicts that could not be
                    overridden or resolved by default resolution actions.
                              
   Output Arguments:
      can_modify - The access status. If it is PRO_B_TRUE, the model is 
                   modifiable.
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more arguments are invalid.
      PRO_TK_GENERAL_ERROR - The function could not check access to the model.
*/

extern ProError ProMdlIsSaveAllowed(ProMdl p_model,
                                  ProBoolean show_ui,
                                  ProBoolean* save_allowed);
/*
   Purpose: Check if given model can be saved along with all its subordinate
            models that are to be saved together with it according to their
            modification status and the configuration option 'save_objects'.
            Note this will also check the current UI context to see if it is
            currently safe to save the model, and so calling this function at
            different times might return different results. A negative result
            indicates that ProMdlSave() would fail for this model.

   Input Arguments:
     p_model      - Model to check access to.
     show_ui      - Indicates whether the Conflicts dialog should be shown to
                    user to resolve conflicts (if they are detected); when set
                    to PRO_B_FALSE no UI is enabled and the model is considered
                    as modifiable if there are no conflicts that could not be
                    overridden or resolved by default resolution actions.

   Output Arguments:
      save_allowed - The save access status. If it is PRO_B_TRUE, the check is
                     successful. If it is PRO_B_FALSE, the model or at least
                     one of its subordinate models can not be saved due to
                     remaining unresolved non-overridable conflicts. Conflicts
                     will not be shown if the model currently cannot be saved
                     due to UI restrictions; the function will return
                     PRO_B_FALSE regardless of this flag.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more arguments are invalid.
      PRO_TK_GENERAL_ERROR - The function could not check access to the model.
*/

extern ProError ProMdlLocationIsStandard(ProMdl model, ProBoolean *is_standard);
/*
   Purpose: Check if given model is to be saved to a standard disk location.

   Input Arguments:
     model      - Model to check.

   Output Arguments: 
     is_standard - PRO_B_TRUE if the storage path is
                     one that would be expected to work with normal OS commands.

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS  - One or more arguments are invalid.
*/

extern ProError ProMdlCommonnameGet (ProMdl model, wchar_t** common_name, 
                                     ProBoolean* is_modifiable);
 /*
    Purpose: Obtains a model common name. This is the name to identify
             a PDM object containing this model file.

    Input Arguments:
      model - The model.

    Output Arguments:
      common_name   - The model common name. Free this string using 
                      ProWstringFree().
      is_modifiable - PRO_B_TRUE if the common name can be modified, 
                      PRO_B_FALSE if it has been locked by PDM and cannot be 
                      modified. This argiment can be NULL if not interested.

    Return Values:
      PRO_TK_NO_ERROR       - The function succeeded.
      PRO_TK_BAD_INPUTS     - One or more input arguments was invalid.
      PRO_TK_GENERAL_ERROR  - The function failed.

 */

 extern ProError ProMdlCommonnameSet (ProMdl model, wchar_t* common_name);
 /*
    Purpose: Assigns a model common name. This is the name to identify
             a PDM object containing this model file.

    Input Arguments:
      model       - The model.
      common_name - The common name.

    Output Arguments:
      none

    Return Values:
      PRO_TK_NO_ERROR      - The function succeeded.
      PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
      PRO_TK_CANT_MODIFY   - The common name for the given model has been locked
                             by PDM and cannot be modified.
      PRO_TK_GENERAL_ERROR - The function failed.

 */

extern ProError ProMdlRepresentationLoad (ProPath assembly_file,
                                          ProMdlType type,
                                          ProName simprep_name,
                                          ProSimprepdata *p_simp_rep_data,
                                          ProMdl *result);
/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProMdlRepresentationFiletypeLoad
   Purpose: <b>Note:</b> This function is deprecated
            Use ProMdlRepresentationFiletypeLoad instead.

            Retrieves the specified simplified representation.

<p><b>
             NOTE:
<p></b>
              The function ProSolidRetrievalErrorsGet identifies errors if occurred.


   Input Arguments:
      assembly_file     - The assembly file location. Cannot be NULL.
                          May include: generic name,
                          instance name, file extension, file version,
                          absolute or relative path to a local folder or
                          a url. 
                          Example: wtpub://asm_1<gen_asm_1>.asm.3
                          Example: just gen_asm_1 (will look for a file in
                          the current dirrectory; in this case the type must be 
                          passed in).
      type              - Model type. May be PRO_MDL_UNUSED if assembly_file 
                          includes file extension
      simprep_name      - The name of the simplified representation. 
                          Must be NULL if not user-defined (if not NULL, it is 
                          considered to be user-defined).
      p_simp_rep_data   - The simplified representation data. Can be NULL for 
                          a user defined represenation. The instructions in
                          the data will be used to create a new representation
                          on the fly if such representation does not exist.

   Output Arguments:      
      result            - The handle to the model. Cannot be NULL.
                          <p><b>Note:</b> The function retrieves the model
                          into memory, but neither displays the model nor
                          makes it the current model. If during retrieving 
                          an assembly errors occur on regeneration then 
                          the assembly will include suppressed features. 
                          <p>Use ProSolidRetrievalErrorsGet to get the errors.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid
                             
      PRO_TK_E_NOT_FOUND   - The file was not found.
      PRO_TK_CANT_OPEN     - The file exists but is not readable.
      PRO_TK_EMPTY         - The specified representation was not stored 
                             in the file (for non user-defined representations).
      PRO_TK_INVALID_FILE  - The model is not a Creo Parametric model.
      PRO_TK_GENERAL_ERROR - The model could not be retrieved.
      PRO_TK_LINE_TOO_LONG - The model name is too long.
      PRO_TK_INVALID_NAME  - The specified user defined representation was 
                             not found (in which case it may be created 
                             on the fly following instructions in p_simp_rep_data - 
                             check p_result for being not NULL)
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.

      See Also:
      ProSolidRetrievalErrorsGet()
*/


extern ProError ProMdlObjectdefaultnameGet (ProType object_type, ProLine name);
/*
   Purpose:  Returns the next available default name for given object type

   Input Arguments:       
      object_type     - only these types are allowed:
<ul>
                          <li>PRO_PART
                          <li>PRO_ASSEMBLY
                          <li>PRO_CABLE
                          <li>PRO_DRAWING
                          <li>PRO_REPORT
                          <li>PRO_2DSECTION
                          <li>PRO_3DSECTION
                          <li>PRO_LAYOUT
                          <li>PRO_DWGFORM
                          <li>PRO_MARKUP
</ul>

   Output Arguments:  
      name            - resulting name.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully created the name.
      PRO_TK_UNSUPPORTED   - the type is not supported.
*/

extern ProError ProMdlDetailOptionGet(ProMdl mdl, ProName option, ProLine value);
/*
    Purpose: Get the model detail option

    Input Arguments:
        mdl    - The model
        option - The detail option name

    Output Arguments:
        value  - The value of the detail option

    Return Values: 
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed
        PRO_TK_E_NOT_FOUND   - The option string is not a valid detail option name for this model.
        PRO_TK_NO_LICENSE    - The option is restricted by a license the user does not have.
        PRO_TK_BAD_CONTEXT   - The detail option is not available in this application type (e.g. assembly, part)
*/

extern ProError ProMdlDetailOptionSet(ProMdl mdl, ProName option, ProLine value);
/*
    Purpose: Set the model detail option

    Input Arguments:
        mdl    - The model
        option - The detail option name
        value  - The value of the detail option

    Output Arguments:

    Return Values: 
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed
        PRO_TK_E_NOT_FOUND   - The option string is not a valid detail option name for this model.
        PRO_TK_NO_LICENSE    - The option is restricted by a license the user does not have.
        PRO_TK_BAD_CONTEXT   - The detail option is not available in this application type (e.g. assembly, part)
*/

extern ProError ProMdlFiletypeGet (ProMdl model, ProMdlfileType *filetype);
/*
  @UNDO: SAFE
  Purpose: provides ProMdlfileType for a given model.

  Input Arguments:
       model - the model. Not allowed to be NULL.

  Output Arguments:
       filetype - file type. Not allowed to be NULL.

  Return Values: 
       PRO_TK_NO_ERROR    - the function successfully provided the filetype.
       PRO_TK_BAD_INPUTS  - the model argument is NULL.
       PRO_TK_INVALID_PTR - the model argument does not represent a correct model.
*/

extern ProError ProMdlFiletypeLoad  (ProPath      full_path, 
                                     ProMdlfileType type,
                                     ProBoolean   ask_user_about_reps, 
                                     ProMdl       *p_handle);
/*
   Purpose:   Retrieves the specified model and initializes the handle.
	      <p>
	      The function retrieves the model
	      into memory, but neither displays the model nor
	      makes it the current model. Differs from ProMdlnameRetrieve
              in that the caller can specify the location of the model
              in addition to its name.
	      <p>
	      If retrieving an assembly, and errors occur in regeneration,
	      the assembly will include suppressed features.  The function
	      ProSolidRetrievalErrorsGet identifies if errors occurred.


   Input Arguments:
      full_path    -  The full path of the model to be retrieved,
                      including the name, and optionally the location
                      and extension.
      type         -  The type of the model to retrieve, or PRO_MDLFILE_UNUSED
                      if full_path includes an extension.
      ask_user_about_reps - If TRUE, the Open Rep dialog may be presented,
                            allowing the user to specify which simplified
                            representation of the model should be retrieved.

   Output Arguments:
      p_handle     -  The handle to the retrieved model

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS - One or more of the input arguments are invalid.
      PRO_TK_CANT_OPEN  - The model exists but is not readable.
      PRO_TK_E_NOT_FOUND   - The model does not exist, or was not found
      PRO_TK_INVALID_FILE  - The model is not a Creo Parametric model.
      PRO_TK_INVALID_NAME  - The model name is too long.
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
			     on this model.
      PRO_TK_BAD_CONTEXT   - The Multi-CAD model is not being retrieved from an 
      			     active Windchill server.           
      PRO_TK_GENERAL_ERROR - The model could not be retrieved.

    See Also:
      ProSolidRetrievalErrorsGet()
*/

extern ProError ProMdlRepresentationFiletypeLoad (ProPath assembly_file,
                                          ProMdlfileType type,
                                          ProName simprep_name,
                                          ProSimprepdata *p_simp_rep_data,
                                          ProMdl *result);
/*
   Purpose:  Retrieves the specified simplified representation of an assembly.

<p><b>
             NOTE:
<p></b>
              The function ProSolidRetrievalErrorsGet identifies errors if occurred.


   Input Arguments:
      assembly_file     - The assembly file location. Cannot be NULL.
                          May include: generic name,
                          instance name, file extension, file version,
                          absolute or relative path to a local folder or
                          a url. 
                          Example: wtpub://asm_1<gen_asm_1>.asm.3
                          Example: just gen_asm_1 (will look for a file in
                          the current dirrectory; in this case the type must be 
                          passed in).
      type              - Model type. May be PRO_MDLFILE_UNUSED if assembly_file 
                          includes file extension
      simprep_name      - The name of the simplified representation. 
                          Must be NULL if not user-defined (if not NULL, it is 
                          considered to be user-defined).
      p_simp_rep_data   - The simplified representation data. Can be NULL for 
                          a user defined represenation. The instructions in
                          the data will be used to create a new representation
                          on the fly if such representation does not exist.

   Output Arguments:      
      result            - The handle to the model. Cannot be NULL.
                          <p><b>Note:</b> The function retrieves the model
                          into memory, but neither displays the model nor
                          makes it the current model. If during retrieving 
                          an assembly errors occur on regeneration then 
                          the assembly will include suppressed features. 
                          <p>Use ProSolidRetrievalErrorsGet to get the errors.

   Return Values:
      PRO_TK_NO_ERROR      - The function successfully retrieved the model.
      PRO_TK_BAD_INPUTS    - One or more of the input arguments are invalid
                             
      PRO_TK_E_NOT_FOUND   - The file was not found.
      PRO_TK_CANT_OPEN     - The file exists but is not readable.
      PRO_TK_EMPTY         - The specified representation was not stored 
                             in the file (for non user-defined representations).
      PRO_TK_INVALID_FILE  - The model is not a Creo Parametric model.
      PRO_TK_GENERAL_ERROR - The model could not be retrieved.
      PRO_TK_LINE_TOO_LONG - The model name is too long.
      PRO_TK_INVALID_NAME  - The specified user defined representation was 
                             not found (in which case it may be created 
                             on the fly following instructions in p_simp_rep_data - 
                             check p_result for being not NULL)
      PRO_TK_NO_PERMISSION - The function does not have permission to operate
                             on this model.

      See Also:
      ProSolidRetrievalErrorsGet()
*/


extern ProError ProMdlOriginGet(ProMdl handle, ProPath origin);
/*
   @UNDO: SAFE
   Purpose:  Retrieves the full path from which the model was retrieved.
             Returns an empty string for models which are new in session.
             Returns the full path of the generic for instances.

             You can call ProFileMdlnameParse with the output origin to get
             just the location of the file.

   Input Arguments:
      handle       -  The model handle.

   Output Arguments:
      origin       -  The address where the full path will be written. You must
                      allocate the memory for this argument.

   Return Values:
      PRO_TK_NO_ERROR   - The function successfully retrieved the information.
      PRO_TK_BAD_INPUTS - The input arguments are invalid.
      PRO_TK_GENERAL_ERROR - The origin of the model could not be found.
*/

typedef ProError (*ProModelReplacePostAction) (ProMdl p_replaced_mdl);

/*
   Purpose: This is the notification function called after replace of a model.
<p>
            The user supplies this function by calling
            <b>ProNotificationSet()</b> with the notify type
            PRO_MODEL_REPLACE_POST.
<p> <b>
            NOTE:
<p> </b>
            This function is not called on replace of models dependent
            upon the model explicitly called.            

   Input Arguments:
      p_replaced_mdl    - The information for the model that was just replaced

   Output Arguments:
      None

   Return Values:
      Return values are not interpreted by Creo Parametric.

   See Also:
      ProNotificationSet()
*/

extern ProError ProMdlVisibleAppearancepropsGet(ProAsmitem *item, ProSurfaceAppearanceProps *appearance_properties);
/*
Purpose: Gets the appearance properties of the part, assembly component, 
         subassembly, quilt or surface.
	 <b>Note</b> : In case of assembly model, set the modelitem's owner to
         top-level assembly.

Input Arguments:
    item - The asmitem representing the part, assembly component, 
           subassembly, quilt or surface.

Output Arguments:
    appearance_properties - Structure containing appearance related properties.
Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_NOT_EXIST - The property does not exists.
*/

extern ProError ProMdlVisibleAppearancepropsSet(ProAsmitem* item, ProSurfaceAppearanceProps *appearance_properties);
/*
Purpose: Sets the appearance properties of the part, assembly component, 
         subassembly, quilt or surface. These may or may not
         be visible depending on the properties set by
         the higher level assembly. Call ProWindowRepaint() after this API 
         to see the changes in UI.

Input Arguments:
    item - The asmitem representing the part, assembly component, 
           subassembly, quilt or surface.
    appearance_properties - Structure containing surface appearance properties.
                            Pass NULL to set default surface appearance 
                            properties.

Output Arguments:
    none
    
Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    
*/

extern ProError ProMdlVisibleTextureplacementpropsGet(ProAsmitem *item,
				  ProSurfaceTexturePlacementProps **texture_placement_properties);
/*

Purpose: Gets the texture placement related properties of the part, assembly component, 
         subassembly, quilt or surface.
	 <b>Note</b> : In case of assembly model, set the modelitem's owner to
         top-level assembly.

Input Arguments:
    item - The asmitem representing the part, assembly component,
           subassembly, quilt or surface.

Output Arguments:
    texture_placement_properties - ProArray of structures containing texture 
                         placement properties. The function allocates memory
                         for this argument. To free it, call the function
                         ProArrayFree.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_NOT_EXIST - Properties does not exist on item.

*/

extern ProError ProMdlVisibleTextureplacementpropsSet(ProAsmitem *item, 
				ProSurfaceTexturePlacementProps *texture_placement_properties);
/*

Purpose: Sets the texture placement placement properties of the part, 
	 assembly component, subassembly, quilt or surface.
         These may or may not be visible depending on the properties set by
         the higher level assembly. Call ProWindowRepaint() 
         after this API to see the changes in UI.
	 <B>Note</B>: Call ProMdlVisibleTexturepropsSet() before this API.

Input Arguments:
    item - The asmitem representing the part, assembly component, subassembly,
           quilt or surface.
    texture_placement_properties - ProArray of structures containing texture
                                   placement properties.

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProMdlVisibleTexturepropsGet(ProAsmitem *item, ProSurfaceTextureProps *texture_properties);
/*

Purpose: Gets the texture related properties of the part, 
	 assembly component, subassembly, quilt or surface.
	 <b>Note</b> : In case of assembly model, set the modelitem's owner to
         top-level assembly. 

Input Arguments:
    item - The asmitem representing the part, assembly component,
           subassembly, quilt or surface.

Output Arguments:
    texture_properties - Pointer to structure containing texture 
                         related properties.

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
    PRO_TK_NOT_EXIST - Properties does not exist on item.

*/

extern ProError ProMdlVisibleTexturepropsSet(ProAsmitem *item, ProSurfaceTextureProps *texture_properties);
/*

Purpose: Sets the texture related properties of the part, 
	 assembly component, subassembly, quilt or surface. These may
         or may not be visible depending on the properties set by
         the higher level assembly. Call ProWindowRepaint() after this API 
         to see the changes in UI.

Input Arguments:
    item - The asmitem representing the part, assembly component, subassembly,
           quilt or surface.
    texture_properties - Structure containing texture related properties. 

Output Arguments:
    none

Return Values:
    PRO_TK_NO_ERROR - The function succeeded.
    PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

PRO_END_C_DECLS
#endif  /* PROMODEL_H */
