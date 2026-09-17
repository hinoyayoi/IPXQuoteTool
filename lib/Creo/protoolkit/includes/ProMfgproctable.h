#ifndef PROMFGPROCTABLE_H_
#define PROMFGPROCTABLE_H_



#include <ProToolkit.h>

PRO_BEGIN_C_DECLS

#include <ProUICmd.h>
#include <ProModelitem.h>
#include <ProNcseq.h>
#include <ProNcseqElem.h>
#include <ProNcseqElem.h>

typedef struct pro_model_item ProMfgprocItem;

typedef enum 
{
  PRO_MFGPROCITEM_STEP,
  PRO_MFGPROCITEM_OPERATION,
  PRO_MFGPROCITEM_WORKCELL
} ProMfgprocitemSubtype;

typedef enum
{
  PRO_MFGPROCTABLE_PROCESS,
  PRO_MFGPROCTABLE_WORKCELLS
} ProMfgproctableType;

typedef enum
{
  PRO_MFGPROP_EXTRACT_STATUS,
  PRO_MFGPROP_ACTUAL_MACHINING_TIME,
  PRO_MFGPROP_ACTUAL_MACHINING_LENGTH,
  PRO_MFGPROP_TEMPLATE_NAME,
  PRO_MFGPROP_GROUP_LEVEL_1,
  PRO_MFGPROP_GROUP_LEVEL_2

} ProMfgprocitemPropertyType;

typedef enum
{
  PRO_MFGSTEP_HOLESETEND_NOT_USED = PRO_VALUE_UNUSED,  /* The holeset is not of type PRO_DRILL_BLIND */
  PRO_MFGSTEP_HOLESETEND_REFERENCE,
  PRO_MFGSTEP_HOLESETEND_ALONG_AXIS
} ProMfgstepHolesetEndType;

typedef enum
{
  PRO_MFGPROCREORDER_CHECK_PARENT_CHILD =  0,
  PRO_MFGPROCREORDER_CHECK_PREREQUISITES = 1 << 0,
  PRO_MFGPROCREORDER_CHECK_PRIORITIES =    1 << 1
} ProMfgprocReorderCheckOptions;



#define PRO_MFG_EXTRACTION_POST  84



typedef ProError (*ProMfgprocitemFilterAction) ( ProMfgprocItem*  item, 
                                                 ProAppData       app_data );
/*
    Purpose: Filter action for the steps, operations and workcells in the 
             manufacturing process table.

    Input Arguments:
        item - The manufacturing process table step, operation or workcell.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_CONTINUE - Skip visiting this item.
        Any other value - Visit this item, passing the error status to the 
                          visit action.

*/

typedef ProError (*ProMfgprocitemVisitAction) ( ProMfgprocItem*   item, 
                                                ProError          error, 
                                                ProAppData        app_data );
/*
    Purpose: Visit action for the steps, operations and workcells in the 
             manufacturing process table.

    Input Arguments:
        item - The manufacturing process table step, operation or workcell.
        error - Error return passed from the filter action.
        app_data - Application data passed to the function.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting.
        Any other value - Stop visiting and return this error status from the 
                          visit function.

*/

extern ProError ProMfgProctableVisit ( ProMfg                      mfg, 
                                       ProMfgproctableType         table_type, 
                                       ProMfgprocitemVisitAction   action, 
                                       ProMfgprocitemFilterAction  filter, 
                                       ProAppData                  app_data );
/*
    Purpose: Visits the steps, operations and workcells in the manufacturing 
             process table.
             <P>
             Note: The steps and operations will be visited in the order that 
             they are listed in the table.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.
        table_type - The type of table to visit.
        action - The visit action.
        filter - The filter action.  Can be NULL.
        app_data - Application data passed to the action functions.  Can be 
                   NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().
        PRO_TK_E_NOT_FOUND - No steps were found in the manufacturing process 
                             table.
        Any other value - The error condition returned by the visit action, 
                          which caused the function to stop visiting.

*/

extern ProError ProMfgprocitemFeatureGet ( ProMfgprocItem*  item, 
                                           ProFeature*      feature);
/*
    Purpose: Obtains the manufacturing feature referenced by this process item.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing process item.

    Output Arguments:
        feature - The mfg feature.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - There is no feature associated to this item.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemAnnotationGet ( ProMfgprocItem*     item, 
                                              ProAnnotationElem*  annotation );
/*
    Purpose: Obtains the annotation element that created this process item.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing process item.

    Output Arguments:
        annotation - The annotation element.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - There is no annotation element associated to this 
                             item.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemCreate ( ProMfg               model, 
                                       ProMfgproctableType  table_type, 
                                       ProElement           elem_tree, 
                                       ProMfgprocItem*      predecessor, 
                                       ProMfgprocItem*      item, 
                                       ProErrorlist*        errors );
/*
    Purpose: Creates a new item in the manufacturing process table.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        model - The manfacturing model.
        table_type - The type of table to create new item.
        elem_tree - The element tree for the new manfacturing item.
        predecessor - Step or operation that should be immediately before the 
                      new item in the table.  To place an item at the top of 
                      the table, pass NULL.  To create a workcell, pass NULL.

    Output Arguments:
        item - The created manufacturing item.
        errors - Errors encountered during the item creation.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The item creation failed.   See the errors 
                               output for details of the possible problems.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemFromTemplateCreate ( 
                                           ProMfg mfg, 
                                           ProMfgproctableType  table_type, 
                                           ProPath              template_file, 
                                           ProMfgprocItem*      predecessor, 
                                           ProMfgprocItem**     new_items );
/*
    Purpose: Creates a new manufacturing process step or workcell from a 
             template file.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.
        table_type - The type of table to create new item.
        template_file - Full path to the template file.
        predecessor - The step item occurring just before this item in the 
                      table.  Pass NULL to place the step at the top of the 
                      table, or if creating a workcell.

    Output Arguments:
        new_items - ProArray of new items.  Free this output using 
                    ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - The manufacturing process table is not 
                             initialized.  See ProMfgProctableEnable().
        PRO_TK_E_NOT_FOUND - The template file could not be found.
        PRO_TK_GENERAL_ERROR - The template file could not be parsed 
                               successfully.

*/

extern ProError ProMfgprocitemRedefine ( ProMfgprocItem*  item, 
                                         ProElement       elem_tree, 
                                         ProErrorlist*    errors );
/*
    Purpose: Redefines an existing manufacturing item using an element tree.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing item.
        elem_tree - The element tree.

    Output Arguments:
        errors - Errors that prevented the redefinition from succeeding.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_FOUND - Cannot redefine the item because the item has an 
                         associated feature.  Redefine the feature instead.
        PRO_TK_GENERAL_ERROR - Redefinition failed.  Consult the errors output 
                               for more details on the failure.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemElemtreeGet ( ProMfgprocItem*  item, 
                                            ProElement*      elem_tree );
/*
    Purpose: Obtains the element tree for the manufacturing item.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing item.

    Output Arguments:
        elem_tree - The element tree.  Free this using 
                    ProMfgprocitemElemtreeFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_FOUND - The item is associated to a feature.  Get the tree 
                         from the associated feature instead.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemElemtreeFree ( ProMfgprocItem*  item, 
                                             ProElement       elem_tree );
/*
    Purpose: Frees the element tree extracted from a manufacturing item by 
             ProMfgprocitemElemtreeGet().

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing item.
        elem_tree - The element tree.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProMfgprocitemSubtypeGet ( ProMfgprocItem*         item, 
                                           ProMfgprocitemSubtype*  subtype );
/*
    Purpose: Obtains the subtype of a manufacturing process item.  This could 
             be a process step, operation, or workcell.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing process item.

    Output Arguments:
        subtype - The subtype of the item.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemDefaultfixturesetupstepGet (
                                         ProMfgprocItem*  operation, 
                                         ProMfgprocItem*  fixture_setup_step );
/*
    Purpose: Obtains the default fixture setup step automatically created for 
             the operation.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        operation - The operation item.

    Output Arguments:
        fixture_setup_step - The fixture setup step.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemDelete (ProMfgprocItem* item );
/*
    Purpose: Deletes the step, operation or workcell from the table.  If the 
             table item is associated to a feature this will also delete the 
             associated feature.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The step or operation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProMfgprocitemReorderlimitsGet (
                              ProMfgprocItem*               target_items, 
                              ProMfgprocReorderCheckOptions options, 
                              ProMfgprocItem*               first_predecessor,
                              ProMfgprocItem*               last_predecessor );
/*
    Purpose: Identifies the range of predecessor items in the manufacturing 
             process table to which the input item may potentially be 
             reordered.  Optionally you can determine this range for only the 
             parent/child relationships or for those relationships plus other 
             limiting factors.
             <P>
             NOTE: This function does not reorder the steps.  Use 
             ProMfgprocitemReorder() to accomplish that task.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        target_items - ProArray of steps which are potentially to be reordered.
        options - Bitmask containing one or more types of checks to use in this 
                  determination.

    Output Arguments:
        first_predecessor - The first possible predecessor item for the reorder 
                            operation.
        last_predecessor - The last possible predecessor item for the reorder 
                           operation. 

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_MODIFY - The indicated set of items cannot be reordered to 
                             any other location in the process table.
        PRO_TK_CANT_ACCESS - The manufacturing process table has not been 
                             initialized, see ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemReorder ( ProMfgprocItem*  items, 
                                        ProMfgprocItem*  item_before );
/*
    Purpose: Reorders steps within the process table.  This 
             could also result in moving a step into a different operation, 
             depending on the position indicated.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        items - ProArray of steps to be reordered.
        item_before - The item which should be just before the first 
                      reordered item.  
                      To move the steps to the top of an operation, 
                      pass the operation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - Cannot reorder the items to the indicated position.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemNextitemGet ( ProMfgprocItem*  item, 
                                            ProMfgprocItem*  next_item );
/*
    Purpose: Obtains the next item following this item in the process manager 
             table.  Applicable only to items taken from the 
             PRO_MFGPROCTABLE_PROCESS table.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The process manager item.

    Output Arguments:
        next_item - The next item.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The item is the last item in the table.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemPreviousitemGet ( ProMfgprocItem* item, 
                                                ProMfgprocItem* previous_item);
/*
    Purpose: Obtains the item listed just before this item in the process 
             manager table.  Applicable only to items taken from the 
             PRO_MFGPROCTABLE_PROCESS table.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The process manager item.

    Output Arguments:
        previous_item - The previous item.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The item is the first item in the table.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgproctableFeaturesCreate (ProMfg mfg);
/*
    Purpose: Creates features for all items currently in the process manager 
             table.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgproctableFeaturesDelete (ProMfg mfg);
/*
    Purpose: Deletes features associated to any items currently in the process 
             manager table.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgProctableWrite ( ProMfg              mfg, 
                                       ProMfgproctableType table_type, 
                                       ProLine             view_name, 
                                       ProPath             output_file );
/*
    Purpose: Writes the CSV file containing the contents of the manufacturing 
             process table.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.
        table_type - The type of table to output.
        view_name - The view name in the setup file; pass NULL to use the 
                    current view.
        output_file - The full path and name of the output file.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The process table is not initialized, see 
                             ProMfgProctableEnable().
        PRO_TK_CANT_WRITE - Could not write the output file to the designated 
                            file name or path.

*/

extern ProError ProMfgProctableSynchronize (ProMfg mfg, ProPath input_file);
/*
    Purpose: Synchronizes the manufacturing process table with the contents of 
             the input CSV file.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.
        input_file - The full path and name of the input file.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The process table is not initialized, see 
                             ProMfgProctableEnable().
        PRO_TK_INVALID_FILE - The input file does not have the correct format.
        PRO_TK_CANT_OPEN - Could not find or open the input file.

*/

extern ProError ProMfgprocitemHolesetdepthGet ( ProMfgprocItem* step, 
                                                double*         holeset_depth);
/*
    Purpose: Obtains the holeset depth for the step.  This function supports 
             only steps which contain a single holeset of type "Blind" and an 
             end reference type of "Along Axis".
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        step - The manufacturing process step.

    Output Arguments:
        holeset_depth - The holeset depth.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The manufacturing process table is not 
                             initialized, see ProMfgProctableEnable()
        PRO_TK_INVALID_TYPE - This process item is does not contain holesets.
        PRO_TK_E_AMBIGUOUS - This process step contains multiple holesets.  Use 
                             the element tree for the step to access this 
                             property instead of this function.
        PRO_TK_E_NOT_FOUND - The holeset depth is not specified as the type of 
                             holeset is not "Blind" and/or the end reference 
                             type is not "Along Axis"..
        PRO_TK_E_FOUND - This step is associated to a feature.  Use the feature 
                         element tree to access this information.

    See Also:
        ProMfgprocitemHolesetdepthtypeGet()
        ProMfgprocitemHolesetdepthSet()
*/

extern ProError ProMfgprocitemHolesetdepthSet ( ProMfgprocItem* step, 
                                                double          holeset_depth);
/*
    Purpose: Assigns the holeset depth for the step.  This function supports 
             steps with only a single holeset.  The holeset type must be 
             "Blind".  The end reference type will be changed to be "Along 
             Axis" after using this function.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        step - The manufacturing process step.
        holeset_depth - The holeset depth.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The manufacturing process table was not 
                             initialized, see ProMfgProctableEnable()
        PRO_TK_INVALID_TYPE - This type of item does not contain holesets.
        PRO_TK_E_AMBIGUOUS - The step contains multiple holesets, use the 
                             element tree for step to modify it instead of 
                             using this function.
        PRO_TK_CANT_MODIFY - The type of the holeset is not "Blind".
        PRO_TK_E_FOUND - This step is associated to a feature.  Use the feature 
                         element tree to access this value.

    See Also:
        ProMfgprocitemHolesetdepthtypeGet()
        ProMfgprocitemHolesetdepthGet()
*/

extern ProError ProMfgprocitemHolesetdepthtypeGet (
                                         ProMfgprocItem*            step, 
                                         ProDrillDepthType*         depth_type, 
                                         ProMfgstepHolesetEndType*  end_type );
/*
    Purpose: Gets the type of holeset and holeset end reference contained in 
             the manufacturing process step.  

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        step - The process step.

    Output Arguments:
        depth_type - The depth type.
        end_type - The end reference type, if the depth type is 
                   PRO_DRILL_BLIND.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The manufacturing process table is not 
                             initialized, see ProMfgProctableEnable().
        PRO_TK_INVALID_TYPE - This item type does not contain holesets.
        PRO_TK_E_AMBIGUOUS - This step contains more than one holeset.  Use the 
                             step element tree to extract this information 
                             instead of this function.
        PRO_TK_E_FOUND - This step is associated to a feature.  Use the feature 
                         element tree to access these values.

    See Also:
        ProMfgprocitemHolesetdepthGet()
        ProMfgprocitemHolesetdepthSet()
*/

extern ProError ProMfgProctablemodelGet ( ProMfg         mfg, 
                                          ProModelitem*  process_table_model );
/*
    Purpose: Obtains the process table model for the manufacturing model.  This
             item can be used to set default item parameters and overall table
             relations.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.

    Output Arguments:
        process_table_model - The process table model.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemTemplateparamGet ( ProMfgprocItem*  item, 
                                                 ProName          param_name, 
                                                 ProParamvalue*   value);
/*
    Purpose: Obtains the parameter value for a template parameter for the item.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The process manager item.
        param_name - The template parameter name.

    Output Arguments:
        value - The parameter value for the template parameter.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - The template parameter does not exist.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemPropertyGet ( 
                                     ProMfgprocItem*            item, 
                                     ProMfgprocitemPropertyType property_type, 
                                     ProParamvalue*             property);
/*
    Purpose: Obtains the value of a special property for the manufacturing 
             process manager step or operation.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing step or operation.
        property_type - The property type.

    Output Arguments:
        property - The property value.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - This property is not set on the given item.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgprocitemPropertySet ( 
                                    ProMfgprocItem*             item, 
                                    ProMfgprocitemPropertyType  property_type, 
                                    ProParamvalue*              property);
/*
    Purpose: Assigns the value of a special property for the manufacturing 
             process manager step or operation.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        item - The manufacturing step or operation.
        property_type - The property type.
        property - The property value.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_CANT_MODIFY - This property is readonly.
        PRO_TK_CANT_ACCESS - Access to the manufacturing process table is not 
                             enabled, use ProMfgProctableEnable().

*/

extern ProError ProMfgproctableDisplayUpdate ( void );
/*
    Purpose: Updates the display of the manufacturing process manager dialog, 
             applying any changes which have been made via Creo Parametric TOOLKIT 
             functions.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        none

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_CONTEXT - The manufacturing process manager dialog is not 
                             currently open. 

*/

extern ProError ProMfgproctableSelecteditemsGet (ProMfgproctableType table_type,
                                                 ProMfgprocItem**    items);
/*
    Purpose: Returns the currently selected items in the manufacturing process 
             table UI.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        none

    Output Arguments:
        table_type - The type of table to get selected item.
        items - ProArray of selected items.  Free this output using 
                ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - No selected items were found.
        PRO_TK_BAD_CONTEXT - The manufacturing process table UI is not 
                             currently open.

*/

extern ProError ProMfgproctableSelecteditemsSet (ProMfgproctableType table_type,
                                                 ProMfgprocItem* items);
/*
    Purpose: Sets the currently selected items in the process table.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        table_type - The type of table to set selected item.
        items - ProArray of items to select. Can be NULL to unselect all items.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - The manufacturing process table UI is not 
                             currently active.

*/

extern ProError ProMfgproctableMenuAdd ( char*    menu_name, 
                                         wchar_t* menu_label, 
                                         char*    parent_menu_name );
/*
    Purpose: Add a new user-defined menu to the manufacturing Process Manager 
             UI, or to a submenu in the UI.  This should be called before the 
             Process Manager dialog is shown.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        menu_name - The name of the menu.
        menu_label - The menu label.
        parent_menu_name - The name of the parent menu.  Can be NULL to add the 
                           menu to the top-level menubar.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef uiCmdAccessState (*ProMfgproctableItemAccessFunction) ( 
                                                     ProMfg      mfg, 
                                                     char*       button_name, 
                                                     ProAppData  app_data );
/*
    Purpose: This is the signature for the access function callback for a 
             button added by Creo Parametric TOOLKIT into the manufacturing process manager 
             dialog.

    Input Arguments:
        mfg - Manufacturing model being edited.
        button_name - Name of the added item in the dialog.
        app_data - Application data set during registration of this item.

    Output Arguments:
        none

    Return Values:
        One of the values of uiCmdAccessState, showing which access is 
        permitted.


*/

typedef ProError (*ProMfgproctableItemActionFunction) (ProMfg     mfg, 
                                                       char*      button_name, 
                                                       ProAppData appdata);
/*
    Purpose: This is the action function called when a user invokes the button 
             added to the manufacturing process manager dialog.
             

    Input Arguments:
        mfg - The manufacturing model being edited.
        button_name - The name of the item in the dialog.
        appdata - Application data that was set when the item was registered.

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are not interpreted by Creo Parametric.

*/

extern ProError ProMfgproctablePushbuttonAdd (
                           char*                             menu_name, 
                           char*                             button_name, 
                           wchar_t*                          button_label, 
                           wchar_t*                          button_helptext, 
                           ProMfgproctableItemAccessFunction access_function, 
                           ProMfgproctableItemActionFunction action_function, 
                           ProAppData                        application_data);
/*
    Purpose: Adds a new button to a menu in the manufacturing Process Manager 
             dialog.  The button is added to the end of the indicated menu.  
             This should be called before the Process Manager dialog is shown.
             

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        menu_name - The menu name.
        button_name - The button component name.
        button_label - The button label.
        button_helptext - The button help text.
        access_function - The access function for the button. 
        action_function - The action function for the button.
        application_data - Application data to pass to the access and action 
                           functions.   Can be NULL.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - Could not find the parent menu.
        PRO_TK_E_FOUND - A button with this name already exists.

*/

extern ProError ProMfgProctableEnable (ProMfg mfg);
/*
    Purpose: Ensures that the manufacturing process table has been initialized 
             properly, to allow Creo Parametric TOOLKIT functions to read and modify its 
             contents.
             <P>
             Note: this function needs to be called only if the process table 
             will be modified when the Process Manager dialog is not opened; if 
             the dialog is open the table is automatically ready for 
             modification via Creo Parametric TOOLKIT.

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_CHANGE - The process table was already enabled.

*/

extern ProError ProMfgProctableDisable (ProMfg mfg);
/*
    Purpose:  Completes any Creo Parametric TOOLKIT work on the manufacturing process table 
             from the given model.  Companion to ProMfgproctableEnable().

    Licensing Requirement:
          TOOLKIT for Advanced NC

    Input Arguments:
        mfg - The manufacturing model.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_CHANGE - The process table was not enabled.

*/

typedef ProError (*ProMfgproctableExtractionPostAction) (ProPath path);
/*
    Purpose: This is the required signature for a notification type that is 
             called when an extraction event takes place in manufacturing.  For 
             details of whether extraction succeeded or failed, parse the 
             extraction log file.
             

    Input Arguments:
        path - Path to the extraction log file.

    Output Arguments:
        none

    Return Values:
        Any other value - Return values are ignored by Creo Parametric.

*/


PRO_END_C_DECLS

#endif
