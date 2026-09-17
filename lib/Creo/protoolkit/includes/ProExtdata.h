

#ifndef PROEXTDATA_H
#define PROEXTDATA_H

/* Include Files.
*/
#include        <ProANSI.h>
#include        <ProMdl.h>
#include        <ProConst.h>


PRO_BEGIN_C_DECLS

/*
--------------------------------------------------------------------------------
 Define New typdefs
--------------------------------------------------------------------------------
*/

typedef ProName * ProExtdataNamesList;
typedef int     * ProExtdataIdsList;

/*
--------------------------------------------------------------------------------
 Define New Structures for ProExtdata usage.
-------------------------------------------------------------------------------

<p><b>Note: </b>
      Although class and slot names are individually limited to a length of 
      PRO_NAME_SIZE, they must also have a combined length shorter than 
      PRO_NAME_SIZE. Attempting to use combined names longer than 
      PRO_NAME_SIZE results in an error.
-
*/
typedef struct pro_extdata_class 
{
  ProMdl   p_model;
  ProName  class_name;
  /* int   total_slots; */
} ProExtdataClass;

typedef struct pro_extdata_slot 
{
  ProExtdataClass *p_class;
  ProName         slot_name;
  int             slot_id;
} ProExtdataSlot;


/*
--------------------------------------------------------------------------------
 Define Error Codes.
--------------------------------------------------------------------------------
*/
/*14 Give error codes NEW names.
 */
typedef enum proappdata_error_status
{
	PROEXTDATA_TK_NO_ERROR			=  0,
	PROEXTDATA_TK_INVALID_OBJ_OR_CLASS	= -1,
	PROEXTDATA_TK_CLASS_OR_SLOT_EXISTS	= -2,
	PROEXTDATA_TK_NAMES_TOO_LONG		= -3,
	PROEXTDATA_TK_SLOT_NOT_FOUND		= -4,
	PROEXTDATA_TK_BAD_KEY_BY_FLAG		= -5,
	PROEXTDATA_TK_INVALID_OBJ_TYPE		= -6,
	PROEXTDATA_TK_EMPTY_SLOT		= -7,
	PROEXTDATA_TK_BAD_DATA_ARGS		= -8,
	PROEXTDATA_TK_STREAM_TOO_LARGE		= -9,
	PROEXTDATA_TK_INVALID_SLOT_NAME		= -10,
        PROEXTDATA_TK_ERROR                     = -11,
        PROEXTDATA_TK_MAX_SLOTS_IN_MODEL        = -12
        
} ProExtdataErr;



/* Maximum number of slots that can be added to a given model, in all
   ProExtdata classes.  Checked in ProExtdataSlotCreate() */
#define PRO_EXTDATA_MAX_SLOTS 11800



/*
--------------------------------------------------------------------------------
 Function prototyping for all the Pro/AppData Toolkit API.
--------------------------------------------------------------------------------
*/


extern	ProExtdataErr  ProExtdataInit ( ProMdl   p_model);	

/*
   Purpose: Performs the initial setup for the generic application
            data operation.

   Input Arguments:
      p_model           - The model handle


   Output Arguments:
      None

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully performed
                                            the setup. 
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model is invalid. 

*/


extern	ProExtdataErr ProExtdataTerm ( ProMdl   p_model);			
/*
   Purpose: Cleans up the setup required for the generic application
            data operations for the specified model.

   Input Arguments:
      p_model           - The model handle

   Output Arguments:
      None

   Return Values:
      PROEXTDATA_TK_NO_ERROR              -  The function successfully 
                                             performed the cleanup. 
      PROEXTDATA_TK_ERROR                 -  The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  -  The specified model is invalid. 
*/



extern	ProExtdataErr	ProExtdataClassRegister
(
	ProMdl		p_model,
	ProName		class_name,
        ProExtdataClass *r_p_extclass
);
/*
   Purpose: Registers a class for the specified model.

<p><b>Note: </b>
      Although class and slot names are individually limited to a length of 
      PRO_NAME_SIZE, they must also have a combined length shorter than 
      PRO_NAME_SIZE. Attempting to use combined names longer than 
      PRO_NAME_SIZE results in an error.

   Input Arguments:
      p_model           - The model handle
      class_name        - The name of the class to register

   Output Arguments:
      r_p_extclass      - The handle to the newly registered class

   Return Values: 
      PROEXTDATA_TK_NO_ERROR   -           The function successfully registered
                                           the class.
      PROEXTDATA_TK_ERROR      -           The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS - The specified model or class name 
                                           is invalid.
      PROEXTDATA_TK_CLASS_OR_SLOT_EXISTS - The specified class name already 
                                           exists.
      PROEXTDATA_TK_NAMES_TOO_LONG -       The specified class name exceeds 
                                           the length PRO_NAME_SIZE. 
*/



extern	ProExtdataErr	ProExtdataClassUnregister
(
	ProExtdataClass *p_extclass
);
/*
   Purpose: Unregisters the specified class, if it has been registered.

   Input Arguments:
      p_extclass        - The class handle

   Output Arguments:
      None

   Return Values:
      PROEXTDATA_TK_NO_ERROR             - The function successfully 
                                           unregistered the class.
      PROEXTDATA_TK_ERROR                - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS - The specified model or  
                                           class name is invalid.
*/



extern	ProExtdataErr	ProExtdataSlotCreate
(
	ProExtdataClass *p_extclass,
	ProName         slot_name,
	ProExtdataSlot  *r_p_extslot
);
/*
   Purpose: Creates a data slot for the specified class.

<p><b>Note: </b>
      Although class and slot names are individually limited to a length of 
      PRO_NAME_SIZE, they must also have a combined length shorter than 
      PRO_NAME_SIZE. Attempting to use combined names longer than 
      PRO_NAME_SIZE results in an error.

   Input Arguments:
      p_extclass        - The class handle 
      slot_name         - The name of the data slot to create. Pass NULL to 
                          automatically create a slot with a name related to the 
                          next available id.

   Output Arguments:
      r_p_extslot       - The handle to the newly created data slot

   Return Values:
      PROEXTDATA_TK_NO_ERROR  -            The function successfully created 
                                           the data slot.
      PROEXTDATA_TK_ERROR                - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS - The specified model or class name 
                                           is invalid.
      PROEXTDATA_TK_CLASS_OR_SLOT_EXISTS - The specified slot already exists 
                                           in the specified class.
      PROEXTDATA_TK_NAMES_TOO_LONG       - The specified slot or class name 
                                           exceeds the length PRO_NAME_SIZE.
      PROEXTDATA_TK_MAX_SLOTS_IN_MODEL   - Model already contains
                                           PRO_EXTDATA_MAX_SLOTS slots.
*/



extern	ProExtdataErr	ProExtdataSlotWrite
(
	ProExtdataSlot  *p_extslot,
	int             key_by_flag,
	int             data_type,
	int             data_size,
	void            *p_data
);
/*
   Purpose: Writes data to the specified data slot.

   Input Arguments:
      p_extslot         - The handle to the data slot.
      key_by_flag       - The key-by flag -- either KEY_BY_ID or KEY_BY_NAME.
      data_type         - The data type. The valid types are PRO_INTEGER_TYPE, 
                          PRO_DOUBLE_TYPE, PRO_WIDE_STRING_TYPE, 
                          PRO_STREAM_TYPE, PRO_CHAPTER_TYPE.
                          PRO_CHAPTER_TYPE behaves similar to PRO_STREAM_TYPE but
                          has no data length limit.

      data_size         - The size of the data. This argument applies to
                          PRO_STREAM_TYPE only.
      p_data            - The handle to the data to be written in 
                          the specified slot.

   Output Arguments:
      None

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully wrote 
                                            data to the data slot.
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model or class name 
                                            is invalid.
      PROEXTDATA_TK_BAD_KEY_BY_FLAG       - The specified <i>key_by_flag</i> 
                                            is invalid.
      PROEXTDATA_TK_SLOT_NOT_FOUND        - The specified slot was not found. 
      PROEXTDATA_TK_STREAM_TOO_LARGE      - The stream data size is greater 
                                            than 524288 bytes.
      PROEXTDATA_TK_BAD_DATA_ARGS         - The specified <i>data_type</i> is 
                                            invalid.
*/


extern	ProExtdataErr	ProExtdataSlotRead
(
	ProExtdataSlot *p_extslot,
	int            key_by_flag,
	int            *data_type,
	int            *data_size,
	void           **r_p_data
);
/*
   Purpose: Reads the data from the specified slot.

   Input Arguments:
      p_extslot         - The handle to the data slot.
      key_by_flag       - The key-by flag -- either KEY_BY_ID or
                          KEY_BY_NAME.

   Output Arguments:
      r_p_data          - The returned data handle.

      data_type         - The data type. The valid types are 
                          PRO_INTEGER_TYPE, PRO_DOUBLE_TYPE,
                          PRO_WIDE_STRING_TYPE, PRO_STREAM_TYPE, PRO_CHAPTER_TYPE.
                          PRO_CHAPTER_TYPE behaves similar to PRO_STREAM_TYPE but
                          has no data length limit.

      data_size         - The size of the data. This argument applies 
                          to PRO_STREAM_TYPE only.

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully read 
                                            data from the specified slot. 
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model or class name 
                                            is invalid.
      PROEXTDATA_TK_BAD_KEY_BY_FLAG       - The specified <i>key_by_flag</i> is 
                                            invalid.
      PROEXTDATA_TK_SLOT_NOT_FOUND        - The specified slot was not found. 
      PROEXTDATA_TK_BAD_DATA_ARGS         - The <i>data_size</i> is NULL.
      PROEXTDATA_TK_EMPTY_SLOT            - No data exists in the slot.
*/


extern	ProExtdataErr	ProExtdataSlotDelete
(
	ProExtdataSlot  *p_extslot,
	int             key_by_flag 
);
/*
   Purpose: Deletes the specified data slot.

   Input Arguments:
      p_extslot         - The handle to the data slot
      key_by_flag       - The key-by flag -- either KEY_BY_ID or KEY_BY_NAME

   Output Arguments:
      None

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully 
                                            deleted the slot.
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model or class name 
                                            is invalid.
      PROEXTDATA_TK_BAD_KEY_BY_FLAG       - The specified <i>key_by_flag</i>  
                                            is invalid.
      PROEXTDATA_TK_SLOT_NOT_FOUND        - The specified slot was not found. 
*/



extern	ProExtdataErr	ProExtdataLoadAll
(
	ProMdl		p_model
);
/*
   Purpose: Loads all the generic application data for the specified
            model.

   Input Arguments:
      p_model           - The model handle

   Output Arguments:
      None

   Return Values:
      PROEXTDATA_TK_NO_ERROR             - The function successfully 
                                           loaded all the generic application 
                                           data for the model.
      PROEXTDATA_TK_ERROR                - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS - The specified model is invalid.
*/



extern	ProExtdataErr	ProExtdataClassNamesList
(
	ProMdl			p_model,
	int			*r_num_of_classes,
	ProExtdataNamesList	*r_class_names
);
/*
   Purpose: Generates a list of all the classes registered for the 
            specified model. 

   Input Arguments:
      p_model           - The model handle

   Output Arguments:
      r_num_of_classes  - The number of classes in the generated list
      r_class_names     - The list of all the registered classes

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully created
                                            a list of all the classes.
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model is invalid. 
*/



extern	ProExtdataErr	ProExtdataSlotIdsList
(
        ProExtdataClass 	*p_extclass,
	int			*r_num_of_slots,
	ProExtdataIdsList	*r_slot_ids
);
/*
   Purpose: Generates a list of all the slot identifiers for the 
            specified class.

   Input Arguments:
      p_extclass        - The class handle

   Output Arguments:
      r_num_of_slots    - The number of slots in the class
      r_slot_ids        - The list of slots identifiers for the class

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully created 
                                            a list of all the slot identifiers.
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model is invalid. 
      PROEXTDATA_TK_BAD_DATA_ARGS         - The argument <i>r_slot_ids</i> is 
                                            invalid.
*/



extern	ProExtdataErr	ProExtdataSlotNamesList
(
	ProExtdataClass		*p_extclass,
	int			*r_num_of_slots,
	ProExtdataNamesList	*r_slot_names
);
/*
   Purpose: Generates a list of all the slot names for the 
            specified class.

   Input Arguments:
      p_extclass        - The class handle

   Output Arguments:
      r_num_of_slots    - The number of slots in the class
      r_slot_names      - The list of slot names 

   Return Values:
      PROEXTDATA_TK_NO_ERROR              - The function successfully returned 
                                            the information.
      PROEXTDATA_TK_ERROR                 - The function failed.
      PROEXTDATA_TK_INVALID_OBJ_OR_CLASS  - The specified model is invalid. 
      PROEXTDATA_TK_BAD_DATA_ARGS         - The argument <i>r_slot_names</i> 
                                            is invalid. 
*/

extern ProExtdataErr ProExtdataFree
(
 void **p_extdata
);
/*
   Purpose: Frees the memory allocated by the <i>ProExtdata</i> API.

   Input Arguments:
      p_extdata        - The handle to the external data

   Output Arguments:
      None 

   Return Values:
      PROEXTDATA_TK_NO_ERROR  - The function successfully freed the memory.
*/



PRO_END_C_DECLS
#endif /* PROEXTDATA_H */

