

#ifndef PRO_UDF_H
#define PRO_UDF_H

#include <ProGroup.h>
#include <ProObjects.h>
#include <ProSolid.h>

PRO_BEGIN_C_DECLS

typedef struct pro_udf_data_new* ProUdfdata;
                        
/* Declarations for Groups */
typedef ProError (*ProGroupFilterAction)(
    ProGroup *group,
    ProAppData   data);
/*
   Purpose: Prototype of the caller-supplied function which is called
            for every feature group.
 
   Input Arguments:
      group          -  The group being visited.
      data           -  Caller-supplied data
 
   Output Arguments:
      None
 
   Return Values:
        PRO_TK_CONTINUE  - Skip this group, do not call
                           the visit function.
        Other            - Pass this error status into the
                           visit function.
*/
 
typedef ProError (*ProGroupVisitAction)(
    ProGroup  *group,
    ProError       status,
    ProAppData     data);
/*
   Purpose: Prototype of the caller-supplied function which is called
            for every feature group approved by the filter function.
 
   Input Arguments:
      group          -  The feature group being visited.
      status         -  Error status from the filter function.
      data           -  Caller-supplied data
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR    - Continue visiting.
         other           - Visiting will stop and this error will be
                           returned back by the visit function.
*/

extern ProError ProSolidGroupVisit(
    ProSolid               solid,
    ProGroupVisitAction  visit,
    ProGroupFilterAction filter,
    ProAppData             data);
/*
   Purpose: Visit groups (inlcuding UDFs) in the solid. 
 
   Input Arguments:
      solid          - The solid
      visit          - The visit function
      filter         - The filter function. If NULL, all UDFs are  
                       visited using the action function.
      data           - User defined data passed to the visit and filter
                        functions.  Can be NULL.
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR    - All groups were visited
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND - No groups exist in the solid
      Other              - Visiting was terminated by an error from the
                                action function.
*/


extern  ProError   ProSolidGroupsCollect(
        ProSolid       solid,
        ProGroup**     groups);
/* 
Purpose: Collect groups (including UDFs) in the solid. 
 
   Input Arguments:
      solid          - The solid
 
   Output Arguments:
      groups         - ProArray of groups. Free this memory 
                       using ProArrayFree().
   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND - No groups exist in the solid
      Other              - Visiting was terminated by an error from the
                                action function.
*/

 
extern ProError ProUdfNameGet(
    ProGroup  *udf,
    ProName    name,
    ProName    instance);
/*
   Purpose: Give the name of the UDF which was used to place the specified group.
 
   Input Arguments:
      udf                - The UDF.
 
   Output Arguments:
      name               - The name of the UDF
      instance           - The name of the instance in the UDF family table of
                           which this is an instance. An empty string if
                           the UDF is the generic, or has no family table.
 
   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_GENERAL_ERROR - The group is not a UDF
*/
 
extern ProError ProFeatureGroupGet(ProFeature             *member,
                                    ProGroup               *group);
/*
 Purpose: Return the group that contains a given feature.
 
   Input Arguments:
      member                - The feature.
    
   Output Arguments:
      group                 - The group in which the feature is a member.

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid. 
      PRO_TK_E_NOT_FOUND   - The feature is not part of a group
      PRO_TK_GENERAL_ERROR - The function failed.

   See Also:
      ProFeatureGroupStatusGet()
*/


extern ProError ProGroupFeatureVisit(
    ProGroup              *group,
    ProFeatureVisitAction  visit,
    ProFeatureFilterAction filter,
    ProAppData             data);
/*
   Purpose: Visits the features in a group.
 
   Input Arguments:
      group              - The UDF or local group
      visit              - The visit function
      filter             - The filter function. If NULL, all the features
                           in a group are visited using the action function.  
      data               - User defined data passed to the visit and filter
                                functions.  Can be NULL.
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR - All members of the group were visited.  
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      Other - The visit was terminated by an error from the visit function
*/

extern ProError ProGroupFeaturesCollect(
    ProGroup              *group,
    ProFeature**           feats);
/*
   Purpose: Collect the features in a group
 
   Input Arguments:
      group             - The UDF or local group
      
   Output Arguments:
      feats             - ProArray of group members. Free this using 
                          ProArrayFree.
 
   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


extern ProError ProGroupIsTabledriven(
    ProGroup   *group,
    ProBoolean *table_driven);

/*
   Purpose: Reports whether the group is table-driven.
 
   Input Arguments:
      group             - The group
 
   Output Arguments:
      table_driven       - Whether the group is table-driven
 
   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.  
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid. 
      PRO_TK_BAD_CONTEXT - The feature is not part of a UDF
*/

extern ProError ProUdfDimensionVisit(
    ProGroup                    *udf,
    ProDimensionVisitAction  visit,
    ProDimensionFilterAction filter,
    ProAppData               data);

/*
   Purpose: Visit the variable dimensions in a UDF
 
   Input Arguments:
      udf                - The udf group
      visit              - The visit function
      filter             - The filter function. If NULL, all variables in 
                           a UDF are visited using the action function. 
      data               - User defined data passed to the visit and filter
                           functions.  Can be NULL.
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR - Visiting terminated successfully.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_E_NOT_FOUND - The group is not a UDF, or does not have variable 
                           dimensions.
      Other - The visit was terminated by an error from the visit function.
*/

extern ProError ProUdfDimensionsCollect(
    ProGroup                    *udf,
    ProDimension                **dims);

/*
   Purpose: Collects the variable dimensions in a UDF.
 
   Input Arguments:
      udf                - The UDF group
     
   Output Arguments:
      dims               - ProArray of dimensions. Free this using 
                           ProArrayFree().
 
   Return Values:
      PRO_TK_NO_ERROR - The functions succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_E_NOT_FOUND - The group is not a UDF, or does not have variable 
                           dimensions.  
*/

extern ProError ProUdfDimensionNameGet(
    ProGroup     *udf,
    ProDimension *dimension,
    ProLine      name);

/*
   Purpose: Retrieves the dimension name in a user-defined feature (UDF). This
            is the symbol of the dimension in the original model at the time 
            the group was created. It is the same in all UDFs made from the 
            same group.  This symbol is needed when placing a new instance
            of the UDF using Creo Parametric TOOLKIT.
            <P>
            If you want the unique dimension symbol, use 
            <b>ProDimensionSymbolGet</b>.  
 
   Input Arguments:
      udf                - The UDF group.
      dimension          - The dimension.

   Output Arguments:
      name               - The symbol for the dimension in the UDF reference 
                           model.
 
   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_BAD_CONTEXT - The group is not a UDF.
      Other - The visit was terminated by an error from the visit function
*/

typedef struct copied_mdl_names *ProUdfmdlNames;

extern ProError ProUdfmdlNamesAlloc(
      ProName         old_name,
      ProName         new_name,
      ProUdfmdlNames *name_pair);

/*
   DEPRECATED: Since Creo 3
   SUCCESSORS: ProUdfmdlMdlnamesAlloc
   Purpose: <b>Note:</b> This function is deprecated
            Use ProUdfmdlMdlnamesAlloc instead.

            Allocate and set a ProUdfMdlName structure which identifies
            a copied component model and its corresponding orignal.  This 
            strucutre is used for UDF placement.

   Input Arguments:
      old_name                - Name of component model being copied.
      new_name                - Name of copied component model.

   Output Arguments:
      name_pair               - The structure that contains both names.

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUdfmdlMdlnamesAlloc(
      ProMdlName      old_name,
      ProMdlName      new_name,
      ProUdfmdlNames *name_pair);

/*
   Purpose: Allocate and set a ProUdfMdlName structure which identifies
            a copied component model and its corresponding orignal.  This 
            strucutre is used for UDF placement.

            <b>Note: </b> In Creo 3 this function does not differ in behavior
            from superseded ProUdfmdlNamesAlloc. In particular, new_name
            can be only of ProName length. This function is reserved for future
            use.
   
   Input Arguments:
      old_name                - Name of component model being copied.
      new_name                - Name of copied component model.

   Output Arguments:
      name_pair               - The structure that contains both names.

   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
      PRO_TK_LINE_TOO_LONG - Argument new_name is too long.
*/

extern ProError ProUdfmdlNamesSet(
      ProUdfdata data,
      ProUdfmdlNames mdl_names);

/* 

   Purpose: Add a ProUdfMdlNames structure to the UDF placement data.

   Input Arguments:
      data                    - UDF data.
      mdl_names               - The UDF model names object.

   Output Arguments:
      data

   Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

typedef struct pro_udf_var_dim_new *ProUdfvardim;
typedef struct pro_udf_reference_new *ProUdfreference;
typedef struct pro_udf_asm_intersection *ProUdfintersection;

typedef enum
{
    PROUDFDEPENDENCY_INDEPENDENT,
    PROUDFDEPENDENCY_UDF_DRIVEN
} ProUdfdependency;

typedef enum
{
    PROUDFSCALETYPE_SAME_SIZE,
    PROUDFSCALETYPE_SAME_DIMS,
    PROUDFSCALETYPE_USER
} ProUdfscaletype;

typedef enum
{
    PROUDFDIMDISP_NORMAL,
    PROUDFDIMDISP_READONLY,
    PROUDFDIMDISP_BLANK
} ProUdfdimdisplay;

typedef enum
{
    PROUDFORIENT_INTERACTIVE = -1,
    PROUDFORIENT_NO_FLIP,
    PROUDFORIENT_FLIP
} ProUdforientation;

typedef enum
{
    PROUDFOPT_EDIT_MENU,        /* Display UDF placement user interface.
                                   Normally this UI will not be displayed */
    PROUDFOPT_NCSEQ_MENU,       /* For manufacturing UDFs only,
                                   display MOD NC SEQ menu. Normally this
                                   menu will not be displayed. */
    PROUDFOPT_NO_EXISTING_TOOLS,/* Obsoleted */
    PROUDFOPT_NO_REDEFINE,      /* Disable redefine menu for feature with
                                   variable elements */
    PROUDFOPT_FIX_MODEL_UI_OFF  /* Fix model UI won't be available */
} ProUdfCreateOption;

typedef enum
{
    PROUDFVARTYPE_DIM,
    PROUDFVARTYPE_IPAR
} ProUdfVardimType;


extern ProError ProUdfdataAlloc(
    ProUdfdata *data);

/*
   Purpose: Allocate an empty ProUdfdata structure to be
        used as input to ProUdfCreate()
 
   Input Arguments:
      None

   Output Arguments:
      data               - The UDF data
 
   Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUdfdataNameSet(
    ProUdfdata data,
    ProName    udf_name,
    ProName    instance);

/*
   Purpose: Sets the name and instance name of the UDF in the UDF data
 
   Input Arguments:
      data               - The UDF data
      udf_name           - The name of the UDF
      instance           - The family table instance name to be used,
                                or an empty string, or NULL.
 
   Output Arguments:
      None
 
   Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/
 

extern ProError ProUdfdataDependencySet(
    ProUdfdata       data,
    ProUdfdependency dependency);

/*
   Purpose: Sets the UDF dependency in the UDF data
 
   Input Arguments:
      data               - The UDF data
      dependency         - The dependency
 
   Output Arguments:
      None
 
   Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUdfdataScaleSet(
    ProUdfdata      data,
    ProUdfscaletype type,
    double          scale);
/*
   Purpose: Sets the UDF scale type and scale in the UDF data
 
   Input Arguments:
      data               - The UDF data
      type               - The scale type
      scale              - The scale factor, if type == PROUDFSCALETYPE_USER
 
   Output Arguments:
      None
 
   Return Values:
     PRO_TK_NO_ERROR - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUdfvardimAlloc(
    ProName      dim_name,
    double       value,
    ProUdfVardimType type,
    ProUdfvardim *vardim);

/*
   Purpose: Allocate and set a UDFvardim structure which describes a
            variable dimension setting for a UDF
 
   Input Arguments:
      dim_name           - The name of the variant dimension in the UDF 
                           definition
      value              - The new value of the variable dimension
      type               - The type of the variant dimension structure 
                           (dimension or pattern parameter)
 
   Output Arguments:
      vardim             - The allocated ProUdfvardim structure
 
   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/

extern ProError ProUdfvardimFree (ProUdfvardim var_dim);
/*
    Purpose: Frees the UDF variant dimension handle.

    Input Arguments:
        var_dim - The variant dimension handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfdataUdfvardimAdd(
    ProUdfdata   data,
    ProUdfvardim vardim);

/*
   Purpose: Adds a variable dimension structure to the UDF data
 
   Input Arguments:
      data               - The UDF data
      vardim             - The variable dimension data

   Output Arguments:
      None
 
   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfdataDimdisplaySet(
    ProUdfdata data,
    ProUdfdimdisplay dim_display);
 
/*
   Purpose: Sets the dimension display option in the UDF data
 
   Input Arguments:
      data               - The UDF data
      dim_display        - The dimension display option
 
   Output Arguments:
      None
 
   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfreferenceAlloc(
    ProLine         prompt,
    ProSelection    ref_item,
    ProBoolean      external,
    ProUdfreference *reference);
/*
   Purpose: Allocate and set a ProUdfreference structure which describes a
        reference for a UDF
 
   Input Arguments:
      prompt             - The prompt defined for the reference in the UDF
      ref_item           - The item to be referenced. Allowed to be NULL only
                           if this is a Annotation Element reference which
                           will be left as incomplete after UDF placement
      external           - Whether the reference is to an item which is 
                           referenced though a parent assembly of the
                           solid owning the UDF
 
   Output Arguments:
      reference          - The allocated ProUdfreference structure
 
   Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
      PRO_TK_INVALID_TYPE - The selected item is an embedded datum and cannot be
                            used as UDF reference.

    See Also:
        ProUdfdataReferenceAdd()
*/

extern ProError ProUdfreferenceFree (ProUdfreference reference);
/*
    Purpose: Frees the UDF reference handle.

    Input Arguments:
        reference - The reference handle

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUdfdataReferenceAdd(
    ProUdfdata      data,
    ProUdfreference reference);
 
/*
   Purpose: Adds a reference structure to the UDF data.
 
   Input Arguments:
      data               - The UDF data
      reference          - The reference data
 
   Output Arguments:
      None
 
   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfintersectionAlloc(
    ProAsmcomppath     *intersect_part,
    int                visibility_level,
    ProName            *instance_names,
    ProUdfintersection *intersection);
/*
   Purpose: Allocate and set a ProUdfintersection structure which
     describes an assembly intersections of a solid feature in an
     assembly
 
   Input Arguments:
      intersect_part     - The part to be intersected
      visibility_level   - The level at which the feature is to be visible
                           in the selected part.  Values can be:
                           <UL>
                           <LI>0 = visible only in the top level assembly
                           <LI>1 = visible in the top level assembly and
                               the subassembly below it
                           <LI>...
                           <LI>table_num in intersect part = visible in 
                           all levels of the assembly
      instance_names     - A ProArray of instance names to be used to create
                           the internal family table instances created
                           to represent the UDF geometry between the
                           UDF owner and the visibility level. The number
                           of names in the array should be equal to 
                           visibility_level. If NULL, Creo Parametric will
                           generate the instance names by default.
   
   Output Arguments:
      intersection       - The allocated intersection data structure
 
   Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfintersectionFree (ProUdfintersection intersection);
/*
    Purpose: Frees the UDF intersection handle.

    Input Arguments:
        intersection - The UDF intersection handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUdfdataIntersectionAdd(
    ProUdfdata         data,
    ProUdfintersection intersection);
/*
   Purpose: Adds an intersection structure to the UDF data
 
   Input Arguments:
      data               - The UDF data
      intersection       - The intersection data
 
   Output Arguments:
      None
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfdataOrientationAdd(
    ProUdfdata        data,
    ProUdforientation orientaton);
/*
   Purpose: Adds an orientation to the UDF data
 
   Input Arguments:
      data               - The UDF data
      orientaton         - The orientation
 
   Output Arguments:
      None
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfdataQuadrantAdd(
    ProUdfdata data,
    ProPoint3d quadrant);
/*
   Purpose: Adds a quadrant to the UDF data
 
   Input Arguments:
      data               - The UDF data
      quadrant           - The quadrant
 
   Output Arguments:
      None
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProUdfdataFree(
    ProUdfdata data);

/*
   Purpose: Frees a UDF data structure
 
   Input Arguments:
      data               - the UDF data
 
   Output Arguments:
      None
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/
 
extern ProError ProUdfCreate(
    ProSolid           solid,
    ProUdfdata         data,
    ProAsmcomppath     *asm_reference,
    ProUdfCreateOption *options,
    int                n_options,
    ProGroup          *udf);
/*
   Purpose: Creates an instance of a UDF in a solid
   <P>NOTE: From Creo3 onwards, features have backup reference information that 
   allows their missing references to be visited, hence the additional reference
   information may be shown through ProFeatureAnnotationelemsVisit and similar 
   calls. This new functionality can be disabled by setting config option 
   backup_reference_information to no.
 
   Input Arguments:
      solid            - The solid which will contain the UDF
      data             - The data which described the placement and
                         geometry of the UDF
      asm_reference    - The assembly and member component path from
                         the root assembly to the model on which
                         the UDF will be created.
                         NULL if the UDF is not placed in assembly mode, or
                         if the UDF is placed in the top-level assembly.
      options          - Array of placement options
      n_options        - The number of options
 
   Output Arguments:
      udf              - The resultant UDF group
 
   Return Values:
       PRO_TK_NO_ERROR - The function succeeded.
       PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
       PRO_TK_GENERAL_ERROR - Unable to place the new UDF instance.
       PRO_TK_UNSUPPORTED   - The input model is Multi-CAD model. 
*/

typedef struct pro_udf_var_param *ProUdfvarparam;
typedef struct pro_udf_ext_dim *ProUdfextdim;
typedef struct pro_udf_ext_param *ProUdfextparam;
typedef struct pro_udf_required_ref *ProUdfRequiredRef;
typedef struct pro_udf_ext_symbol *ProUdfextsymbol;

typedef enum
{
    PROUDFEXTSYMTYPE_DIM,
    PROUDFEXTSYMTYPE_PAR
} ProUdfextsymbolType;

extern ProError ProUdfdataPathSet ( ProUdfdata data, ProPath path );
/*
    Purpose: Sets the path to the UDF .gph file.  If this function is used, it 
             supersedes the name assigned by ProUdfdataNameSet().

    Input Arguments:
        data - The UDF data
        path - The full path to the UDF .gph  file

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

    See Also:
        ProUdfdataNameSet()
*/

extern ProError ProUdfvarparamAlloc (ProName name, ProModelitem* item,
                                               ProUdfvarparam* param);

/*
   Purpose: Allocates a UDF variable parameter or annotation structure which
            describes a variable parameter or annotation.
 
   Input Arguments:
      name           - The parameter name.
      item           - The owner item. This item must have type and id filled out.
                       The owner field is ignored by Creo Parametric. The following
                       types are allowed here:
                       <UL>
                       <LI>PRO_FEATURE</LI>
                       <LI>PRO_ANNOTATION_ELEM</LI>
                       </UL>
                       
   Output Arguments:
      param          - The variant parameter handle.
 
   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_NO_LICENSE  - No license is available for this function.

   See Also:
      ProUdfdataVarparamAdd()
      ProUdfvarparamValueSet()
*/

extern ProError ProUdfvarparamFree (ProUdfvarparam var_param);
/*
   Purpose: Frees the UDF variant paramter handle.
   
   Input Arguments:
      var_param          - The variant parameter handle.
       
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataVarparamAdd (ProUdfdata data, ProUdfvarparam param);

/*
   Purpose: Adds information about a variable parameter assignment to
            the UDF data.
 
   Input Arguments:
      data               - The UDF data
      param              - The variable parameter structure

   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_NO_LICENSE  - No license is available for this function.

   See Also:
      ProUdfvarparamAlloc()
*/

extern ProError ProUdfextparamAlloc (ProLine prompt, ProParameter* parameter,
                                                  ProUdfextparam* ext_param);

/*
   Purpose: Allocates and sets a ProUdfextparam structure which
            describes an external symbol referencing a parameter.
 
   Input Arguments:
      prompt         - The prompt for the external parameter symbol.
      parameter      - The parameter used as this external symbol.
                       
   Output Arguments:
      ext_param      - The newly allocated ProUdfextparam structure.
 
   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_NO_LICENSE  - No license is available for this function.

   See Also:
      ProUdfdataExtparamAdd()
*/

extern ProError ProUdfextparamFree (ProUdfextparam ext_param);
/*
   Purpose: Frees the UDF external paramter handle.
   
   Input Arguments:
      ext_param          - The external parameter handle.
       
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataExtparamAdd (ProUdfdata data,
                                       ProUdfextparam ext_param);

/*
   Purpose: Adds information about an external symbol parameter to
            the UDF data.
 
   Input Arguments:
      data               - The UDF data
      ext_param          - The UDF external symbol parameter handle

   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR    - The function succeeded.
      PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
      PRO_TK_NO_LICENSE  - No license is available for this function.

   See Also:
      ProUdfextparamAlloc()
*/

extern ProError ProUdfextdimAlloc (ProLine prompt, ProDimension* dimension,
                                                    ProUdfextdim* ext_dim);
/*
    Purpose: Allocates and sets a  structure which describes an external 
             dimension symbol required by the UDF.

    Input Arguments:
        prompt - The prompt used for this external symbol.
        dimension - The dimension  handle to use for the external symbol.

    Output Arguments:
        ext_dim - The handle to the ProUdfextdim structure.

    Return Values:
        PRO_TK_BAD_CONTEXT - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

   See Also:
      ProUdfdataExtdimAdd()
*/

extern ProError ProUdfextdimFree (ProUdfextdim ext_dim);
/*
    Purpose: Frees the UDF dimension external symbol handle.

    Input Arguments:
        ext_dim - The dimension external symbol handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataExtdimAdd (ProUdfdata data, ProUdfextdim ext_dim);
/*
    Purpose: Adds information about a required external dimension symbol to the 
             UDF data.

    Input Arguments:
        data - The UDF data
        ext_dim - The UDF dimension external symbol handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

   See Also:
      ProUdfextdimAlloc()
*/

extern ProError ProUdfrequiredrefFree (ProUdfRequiredRef required_ref);
/*
    Purpose: Frees a handle to a required reference for a UDF.

    Input Arguments:
        required_ref - The required reference handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfrequiredrefProarrayFree (ProUdfRequiredRef* required_ref);
/*
    Purpose: Frees a ProArray of handles to required references for a UDF.

    Input Arguments:
        required_ref - The required reference array.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfrequiredrefPromptGet (ProUdfRequiredRef reference,
                                            ProLine prompt);
/*
    Purpose: Obtains the reference prompt for a UDF reference.

    Input Arguments:
        reference - The UDF required reference handle.

    Output Arguments:
        prompt - The reference prompt for this reference.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfrequiredrefTypeGet (ProUdfRequiredRef reference,
                                          ProType* type);
/*
    Purpose: Obtains the type of object that should be supplied for this 
             reference.

    Input Arguments:
        reference - The UDF required reference handle.

    Output Arguments:
        type - The type of object that should be supplied for this reference.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfrequiredrefIsannotationref (ProUdfRequiredRef reference,
                                                 ProBoolean* is_annotation_ref);
/*
    Purpose: Obtains if the reference is an annotation reference (and thus is 
             allowed to be left incomplete).

    Input Arguments:
        reference - The UDF required reference handle.

    Output Arguments:
        is_annotation_ref - PRO_B_TRUE if the reference is an annotation 
                            reference; PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataRequiredreferencesGet (ProUdfdata data,
                                       ProUdfRequiredRef** required_references);
/*
    Purpose: Obtains the references required to be set for UDF placement.

    Input Arguments:
        data - The UDF data

    Output Arguments:
        required_references - The references required to be set for UDF 
                              placement.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - Cannot access the UDF references because the name 
                             or file path has not been set in this data.
        PRO_TK_CANT_OPEN   - Cannot find the UDF file in based on the information 
                             specified in the data.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvarparamProarrayFree (ProUdfvarparam* var_param);
/*
    Purpose: Frees an array of  variant UDF parameter or annotation value 
             handles.

    Input Arguments:
        var_param - ProArray of  variant UDF items.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvarparamOwnerGet (ProUdfvarparam var_param, ProModelitem* owner);
/*
    Purpose: Obtains the feature or annotation element that owns this variant 
             parameter or annotation value.
             

    Input Arguments:
        var_param - The UDF variant item.

    Output Arguments:
        owner - The feature or annotation element that owns this variant item.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NOT_VALID   - If the variant item type is not parameter or 
                             annotation.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvarparamNameGet (ProUdfvarparam var_param, ProName name);
/*
    Purpose: Obtains the name or symbol of the variant parameter or annotation 
             value.

    Input Arguments:
        var_param - The UDF variant item

    Output Arguments:
        name - The name of the variant item.  For PRO_UDFVARITEM_DIMENSION, 
               this is the dimension symbol that should be used in 
               ProUdfvardimAlloc()

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvarparamDefaultvalueGet (ProUdfvarparam var_param, ProParamvalue* default_value);
/*
    Purpose: Obtains the default value for the variant parameter or annotation 
             value.

    Input Arguments:
        var_param - The UDF variant item.

    Output Arguments:
        default_value - The default value for this variant item.

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE - No license is available for this function.

*/

extern ProError ProUdfvarparamValueSet (ProUdfvarparam var_param, ProParamvalue* value);
/*
    Purpose: Assigns the value to use for a variable parameter or annotation 
             value when the UDF is placed.
             <P>NOTE: The variant parameter must be added to the UDF data 
             structure using ProUdfdataVarparamAdd in order for it to be used 
             during placement.

    Input Arguments:
        var_param - The UDF variant item.
        value - The value to use for the UDF placement.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE - No license is available for this function.

*/

extern ProError ProUdfdataVarparamsGet (ProUdfdata data, ProUdfvarparam** variant_params);
/*
    Purpose: Obtains an array of available variant parameters or annotation 
             values that may be set when placing this UDF.
             <P>NOTE: Handles obtained from this function call are not 
             automatically assigned to the UDF for placment.  In order to place 
             the UDF with a user-defined variant parameter or annotation value, 
             you must use ProUdfdataVarparamAdd.  

    Input Arguments:
        data - The UDF data

    Output Arguments:
        variant_params - ProArray of variant items that may be set upon 
                         placement of this UDF.  Free this using 
                         ProUdfvarparamProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - Cannot access the UDF data because the name and 
                             path have not been set.
        PRO_TK_CANT_OPEN   - Cannot access the UDF .gph file at the path 
                             specified.
        PRO_TK_E_NOT_FOUND - This UDF does not have any variable items.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvardimProarrayFree (ProUdfvardim* var_dim_array);
/*
    Purpose: Frees an array of an array of variant dimension handles for UDFs.

    Input Arguments:
        var_dim_array - ProArray of variant dimension handles.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvardimNameGet (ProUdfvardim var_dim, ProName name);
/*
    Purpose: Obtains the symbol of the variant dimension.  This is the symbol 
             of the dimension in reference model that should be used in 
             ProUdfvardimAlloc().

    Input Arguments:
        var_dim - The UDF variant dimension.

    Output Arguments:
        name - The symbol of the variant item. 

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvardimPromptGet (ProUdfvardim var_dim, ProLine prompt);
/*
    Purpose: Obtains the prompt of the variant dimension.  

    Input Arguments:
        var_dim - The UDF variant dimension.

    Output Arguments:
        prompt - The prompt of the variant item. 

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvardimDefaultvalueGet (ProUdfvardim var_dim, ProUdfVardimType* value_type, double* dim_value);
/*
    Purpose: Obtains the default value for the variant dimension value.

    Input Arguments:
        var_dim - The UDF variant dimension.

    Output Arguments:
        value_type - The value type.
        dim_value - The default dimension value.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfvardimValueSet (ProUdfvardim var_dim, double value);
/*
    Purpose: Assigns the value to use for a variable dimension value when the 
             UDF is placed.
             <P>NOTE: The variant parameter must be added to the UDF data 
             structure using ProUdfdataVardimAdd in order for it to be used 
             during placement.

    Input Arguments:
        var_dim - The UDF variant dimension.
        value - The value to use for the UDF placement.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataVardimsGet (ProUdfdata data, ProUdfvardim** variant_dims);
/*
    Purpose: Obtains an array of available variant dimensions  that may be set 
             when placing this UDF.
             <P>NOTE: Handles obtained from this function call are not 
             automatically assigned to the UDF for placment.  In order to place 
             the UDF with a user-defined variant dimension value, you must use 
             ProUdfdataVardimAdd.  

    Input Arguments:
        data - The UDF data

    Output Arguments:
        variant_dims - ProArray of variant dimensions that may be set upon 
                       placement of this UDF.  Free this using 
                       ProUdfvarparamProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - Cannot access the UDF data because the name and 
                             path have not been set.
        PRO_TK_CANT_OPEN   - Cannot access the UDF .gph file at the path 
                             specified.
        PRO_TK_E_NOT_FOUND - This UDF does not have any variable dimensions.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataInstancenamesGet (ProUdfdata data, ProName** instance_names);
/*
    Purpose: Obtains an array of the instance names that may be used when 
             placing this UDF.

    Input Arguments:
        data - The UDF data.

    Output Arguments:
        instance_names - ProArray of instance names available in this UDF.  
                         Free this array using ProArrayFree().

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND - This UDF does not have stored instances.
        PRO_TK_BAD_CONTEXT - Cannot access the UDF data because the name and 
                             path have not been set.
        PRO_TK_CANT_OPEN   - Cannot access the UDF .gph file at the path 
                             specified.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataInstancenameSet (ProUdfdata data, ProName instance_name);
/*
    Purpose: Assigns the instance to be used when placing this UDF.

    Input Arguments:
        data - The UDF data.
        instance_name - The instance name to use when placing this UDF.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfdataExternalsymbolsGet (ProUdfdata data, ProUdfextsymbol** external_symbols);
/*
    Purpose: Obtains an array of external symbols required by this UDF.

    Input Arguments:
        data - The UDF data

    Output Arguments:
        external_symbols - ProArray of external symbols required for this UDF.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_BAD_CONTEXT - Cannot access the UDF data because the name and 
                             path have not been set.
        PRO_TK_CANT_OPEN   - Cannot access the UDF .gph file at the path 
                             specified.
        PRO_TK_E_NOT_FOUND - No required external symbols were found in the 
                             UDF.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfextsymbolFree (ProUdfextsymbol external_symbol);
/*
    Purpose: Frees a UDF external symbol handle.

    Input Arguments:
        external_symbol - The UDF external symbol handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfextsymbolProarrayFree (ProUdfextsymbol* external_symbol);
/*
    Purpose: Frees an array of a UDF external symbol handle.

    Input Arguments:
        external_symbol - The UDF external symbol handle.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfextsymbolTypeGet (ProUdfextsymbol external_symbol, ProUdfextsymbolType* type);
/*
    Purpose: Obtains the type of external symbol required.

    Input Arguments:
        external_symbol - The external symbol.

    Output Arguments:
        type - The type of external symbol required.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

extern ProError ProUdfextsymbolPromptGet (ProUdfextsymbol external_symbol, ProLine prompt);
/*
    Purpose: Obtains the prompt used for this external symbol.

    Input Arguments:
        external_symbol - The external symbol

    Output Arguments:
        prompt - The prompt used for this external symbol.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/

/* Commenting following function for want of 
   get_parameter_from_name ( external_symbol->name, &param_value ); */

extern ProError ProUdfextsymbolParametertypeGet (ProUdfextsymbol external_symbol, ProParamvalueType* parameter_type);
/*
    Purpose: Obtains the expected parameter type for an external symbol, if the 
             type is PROUDFEXTSYMTYPE_PAR.

    Input Arguments:
        external_symbol - The external symbol

    Output Arguments:
        parameter_type - the expected parameter type.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_NOT_VALID   - If the external symbol type is not parameter.
        PRO_TK_NO_LICENSE  - No license is available for this function.

*/


typedef ProError (*ProUdfLibraryCompletePostAction) (ProName name,
                                                     ProFeature* features);
/*
    Purpose: This is the prototype for a notification function that is called 
             whenever a UDF is created or modified.
                          
             This function is to be supplied by the user by calling 
             <B>ProNotificationSet()</B> with the notify type 
             PRO_UDF_LIB_COMPLETE_POST. 
             

    Input Arguments:
        name - The UDF name.
        features - ProArray of features included in this UDF.
        <P><B>Note:</B>If the UDF being modified does not
        contain a reference part, this array will be empty.

    Output Arguments:
        none

    Return Values:
        Return values are not interpreted by Creo Parametric.    

    See Also:
       ProNotificationSet()
       ProNotificationUnset()

*/

extern ProError ProUdfUpdate (ProGroup* udf);
/*
    Purpose: Update a dependent UDF to the latest version of the .gph file.  
             The .gph file must be able to be located from within the session 
             or by the search path.

    Input Arguments:
        udf - The dependent UDF group to update.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR     - The function succeeded.
        PRO_TK_BAD_INPUTS   - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - The UDF is not dependent.
        PRO_TK_E_NOT_FOUND  - Could not locate the .gph file to use to update 
                              UDF.

*/

extern ProError ProUdfReplace (ProGroup* udf, ProUdfdata new_udf_data, 
                                                    ProGroup* replacement_udf);
/*
    Purpose: Replaces a UDF with a similar UDF (the two UDF's must use the same 
             reference types).

    Input Arguments:
        udf - The UDF.
        new_udf_data - UDF data describing the replacement UDF.  The dimension 
                       display, scale, name, instance name and path can be set 
                       in this structure.

    Output Arguments:
        replacement_udf - The handle to the new replacement UDF.

    Return Values:
        PRO_TK_NO_ERROR    - The function succeeded.
        PRO_TK_BAD_INPUTS  - One or more input arguments was invalid.
        PRO_TK_E_AMBIGUOUS - Cannot replace the current UDF with the new 
                             version because the reference scheme does not 
                             match.
        PRO_TK_BAD_CONTEXT - The argument new_udf_data does not contain the 
                             name or path.
        PRO_TK_CANT_OPEN   - Cannot access the new UDF .gph file at the provided 
                             path.

*/


PRO_END_C_DECLS
 
#endif
