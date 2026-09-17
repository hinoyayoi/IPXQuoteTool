

#ifndef PROATB_H
#define PROATB_H

#include <ProObjects.h>

PRO_BEGIN_C_DECLS

extern ProError ProATBVerify(ProMdl model,
                             int *feat_ids,
                             ProPath *search_paths,
                             ProFileName **models_out_of_date,
                             ProFileName **models_unlinked,
                             ProFileName **models_old_version);
/*
DEPRECATED: Since Creo 3
SUCCESSORS: ProATBMdlnameVerify
Purpose: <b>Note:</b> This function is deprecated
         Use ProATBMdlnameVerify instead.

         To Verify if the ATB models are out of date. This function will first
          check to see if the model specified is a TIM (of some master model).
          If model is not a TIM, it will check to see if the model contains one
          or more features which are TIM representations of some model from
          ICEM.

Input Arguments:

        model   -  Creo Parametric Part or Assembly that is
                   a) A TIM representation of a model imported from the ATB
                      interface such as CADDS/CATIA
                   b) A Creo Parametric Assembly containing one or more components which
                      are model imported from an ATB Interface such as
                      CADDS/CATIA
                   c) A Creo Parametric Part containing an Import Feature that is imported
                      from an ATB Interface such as ICEM.

        feat_ids - ProArray of feature id(s). Indicates one or more ATB-Enabled
                   feature(s) in the model. In that case, the ATB Verify
                   operation will only work on the Feature(s) specified.
                   If NULL, then the function will attempt to verify the entire
                   model (TIM from CADDS/CATIA).

        search_paths - ProArray of ProPath(s) indicating the set of additional
                      directories to be searched for the master model. If NULL, then
                      the function will search in current working directory or locations
                      set in config-option atb_search_path.


Output Arguments:

        models_out_of_date - ProArray of ProFileName(s) to represent the set of
                             models out of date, which can be relinked. This
                             maps to the models that show up as RED in the UI.
                             The function allocates space for this ProArray.
                             User must call ProArrayFree() to free the array of
                             ProFileName(s). Pass NULL if not interested.

        models_unlinked    - ProArray of ProFileName(s) to represent the set of
                             unlinked models. This maps to the models that show
                             up as YELLOW in the UI (with the broken link). The
                             function allocates space for this ProArray. User
                             must call ProArrayFree() to free the array of
                             ProFileName(s). Pass NULL if not interested.

        models_old_version - ProArray of ProFileName(s) to represent the set of
                             models of older version. This maps to the models
                             that show up as YELLOW in the UI (with the broken
                             link). The function allocates space for this
                             ProArray. User must call ProArrayFree() to free the
                             array of ProFileName(s). Pass NULL if not interested


Return Values:

PRO_TK_NO_CHANGE   -    The function successfully verified the model and
                        didn't find any ATB models out of date nor any models
                        of old version nor any models with broken link.
PRO_TK_NO_ERROR    -    The function successfully verified the model and
                        found ONE or more models out of date.
PRO_TK_NOT_VALID   -     The function successfully verified the model,
                        found ONE or more models of older version and found no
                        ATB models out of date.                        
PRO_TK_BAD_CONTEXT -     The function successfully verified the model,
                        found ONE or more models with broken link and found no
                        ATB models out of date and no ATB models of older version
PRO_TK_BAD_INPUTS  -    The function could not execute, since one or more
                        REQUIRED inputs were missing or incorrect.
*/

extern ProError ProATBMdlnameVerify(ProMdl model,
                             int *feat_ids,
                             ProPath *search_paths,
                             ProMdlFileName** models_out_of_date,
                             ProMdlFileName** models_unlinked,
                             ProMdlFileName** models_old_version);
/*
Purpose: To Verify if the ATB models are out of date. This function will first
          check to see if the model specified is a TIM (of some master model).
          If model is not a TIM, it will check to see if the model contains one
          or more features which are TIM representations of some model from
          ICEM.

		  <b>Note:</b> In Creo 3 this function does not support names longer 
		  than 80 characters. It will return PRO_TK_BAD_INPUTS for longer names. 
		  The support for ProMdlFileName will be added in a future release. 

Input Arguments:

        model   -  Creo Parametric Part or Assembly that is
                   a) A TIM representation of a model imported from the ATB
                      interface such as CADDS/CATIA
                   b) A Creo Parametric Assembly containing one or more components which
                      are model imported from an ATB Interface such as
                      CADDS/CATIA
                   c) A Creo Parametric Part containing an Import Feature that is imported
                      from an ATB Interface such as ICEM.

        feat_ids - ProArray of feature id(s). Indicates one or more ATB-Enabled
                   feature(s) in the model. In that case, the ATB Verify
                   operation will only work on the Feature(s) specified.
                   If NULL, then the function will attempt to verify the entire
                   model (TIM from CADDS/CATIA).

        search_paths - ProArray of ProPath(s) indicating the set of additional
                      directories to be searched for the master model. If NULL, then
                      the function will search in current working directory or locations
                      set in config-option atb_search_path.


Output Arguments:

        models_out_of_date - ProArray of ProMdlFileName(s) to represent the set of
                             models out of date, which can be relinked. This
                             maps to the models that show up as RED in the UI.
                             Pass NULL if not interested.
                             Free this argument using ProArrayFree.

        models_unlinked    - ProArray of ProMdlFileName(s) to represent the set of
                             unlinked models. This maps to the models that show
                             up as YELLOW in the UI (with the broken link).
                             Pass NULL if not interested.
                             Free this argument using ProArrayFree.

        models_old_version - ProArray of ProMdlFileName(s) to represent the set of
                             models of older version. This maps to the models
                             that show up as YELLOW in the UI (with the broken
                             link). Pass NULL if not interested.
                             Free this argument using ProArrayFree.

Return Values:

PRO_TK_NO_CHANGE   -    The function successfully verified the model and
                        didn't find any ATB models out of date nor any models
                        of old version nor any models with broken link.
PRO_TK_NO_ERROR    -    The function successfully verified the model and
                        found ONE or more models out of date.
PRO_TK_NOT_VALID   -     The function successfully verified the model,
                        found ONE or more models of older version and found no
                        ATB models out of date.                        
PRO_TK_BAD_CONTEXT -     The function successfully verified the model,
                        found ONE or more models with broken link and found no
                        ATB models out of date and no ATB models of older version
PRO_TK_BAD_INPUTS  -    The function could not execute, since one or more
                        REQUIRED inputs were missing or incorrect.
PRO_TK_UNSUPPORTED -    The input model is Multi-CAD model. 
*/


extern ProError ProATBMarkAsOutOfDate(ProMdl model,
                                      int *feat_ids);
/*
Purpose: Mark the ATB model/feature as out of date.

Input Arguments:

        model   -  Creo Parametric Part or Assembly that is
                   a) A TIM representation of a model imported from the ATB
                      interface such as CADDS/CATIA
                   b) A Creo Parametric Assembly containing one or more components which
                      are model imported from an ATB Interface such as
                      CADDS/CATIA
                   c) A Creo Parametric Part containing an Import Feature that is imported
                      from an ATB Interface such as ICEM.

        feat_ids - ProArray of feature id(s). Used to indicate one or more
                   ABT-Enabled feature(s) in the model. In that case, the
                   specified feature(s) will be considered as out of date for
                   the ATB Update operation. If NULL, then the model will be
                   considered as out of date for the ATB Update operation.
Output Arguments:

        NONE

Return Values:

PRO_TK_NO_ERROR   - The function run successfully.
PRO_TK_BAD_INPUTS - The function could not run, since one or more REQUIRED
                    inputs were missing or incorrect.
PRO_TK_UNSUPPORTED - The input model is Multi-CAD model. 
*/

extern ProError ProATBUpdate(ProMdl model,
                             int *feat_ids,
                             ProPath *search_paths);
/*
   Purpose: Update the ATB model(s)/feature(s).

   Input Arguments:

        model   -  Creo Parametric Part or Assembly that is
                   a) A TIM representation of a model imported from the ATB
                      interface such as CADDS/CATIA
                   b) A Creo Parametric Assembly containing one or more components which
                      are model imported from an ATB Interface such as
                      CADDS/CATIA
                   c) A Creo Parametric Part containing an Import Feature that is imported
                      from an ATB Interface such as ICEM.

        feat_ids - ProArray of feature id(s). Used to indicate one or more
                   ATB-Enabled feature(s) in the model. In that case, the ATB
                   Update operation will only work on the Feature(s) specified.
                   If NULL, then the function will attempt to update the entire
                   model (TIM from CADDS/CATIA).

        search_paths - ProArray of ProPath(s) indicating the set of additional
                      directories to be searched for the master model. If NULL, then
                      the function will search in current working directory or locations
                      set in config-option atb_search_path.

   Output Arguments:

        NONE

   Return Values:

PRO_TK_NO_CHANGE     -  The function runs successfully and found no ATB models
                        out of date.
PRO_TK_NO_ERROR      -  The function successfully updated the model and found
                        ONE or more models out of date.
PRO_TK_CANT_MODIFY   -  During ATB update the regeneration failed.
PRO_TK_BAD_INPUTS    -  The function could not execute, since one or more
                        REQUIRED inputs were missing or incorrect.
PRO_TK_BAD_CONTEXT   -  There are non-displayed models in the session.
PRO_TK_NOT_DISPLAYED -  The input model is not displayed.
PRO_TK_E_AMBIGUOUS   -  Both: there are non-displayed models in the session AND
                              the input model is not displayed.
PRO_TK_UNSUPPORTED   -  The input model is Multi-CAD model. 
*/


extern ProError ProATBRelink(ProMdl model,
                             int feat_id,
                             ProPath master_model_path);
/*
   Purpose: Relink the model/feature that have lost the link to the master
             model. Relinking a model here will represent searching for the
             master model (using the master model name) in the location
             specified in the 'master_model_path' arguement. If the master model
             with the same name is found, the Creo Parametric TIM model is linked to that
             master model.

   Input Arguments:

        model   -  Creo Parametric Part or Assembly that is
                   a) A TIM representation of a model imported from the ATB 
                      interface such as CADDS/CATIA
                   b) A Creo Parametric Assembly containing one or more components which
                      are model imported from an ATB Interface such as
                      CADDS/CATIA
                   c) A Creo Parametric Part containing an Import Feature that is imported
                      from an ATB Interface such as ICEM.

        feat_id - Indicates a ABT-Enabled feature in the model. In that case,
                  the ATB Relink operation will only work on the Feature
                  specified. If PRO_VALUE_UNUSED, then the function will attempt
                  to relink the entire model (TIM from CADDS/CATIA).

        master_model_path - ProPath indicating the fully qualified path to the
                            new master model to be relinked.

   Output Arguments:

        NONE

   Return Values:

PRO_TK_NO_ERROR   - The function run successfully.
PRO_TK_BAD_INPUTS - The function could not run, since one or more REQUIRED
                    inputs were missing or incorrect.            
PRO_TK_UNSUPPORTED - The input model is Multi-CAD model. 
*/

extern ProError ProModelIsTIM(ProMdl model,
                              ProBoolean *isTIM);
/*
   Purpose: Utility function to check if the model is a TIM or not.

   Input Arguments:

        model   -  Creo Parametric Part or Assembly.

   Output Arguments:

        isTIM   -  Boolean value to represent if the model is a TIM or not.
                   Return PRO_B_TRUE if model is a TIM.
                   Return PRO_B_FALSE, if model is not a TIM.

   Return Values:

PRO_TK_NO_ERROR   - The function run successfully.
PRO_TK_BAD_INPUTS - The function could not run, since one or more REQUIRED
                    inputs were missing or incorrect.
*/

extern ProError ProModelHasTIMFeature(ProMdl model,
                                      ProBoolean *hasTIMFeature);
/*
   Purpose: Utility function to check if the model has a TIM Feature. A TIM
             Feature is a model imported from ICEM or Neutral.

   Input Arguments:

        model  -  Creo Parametric Part or Assembly.

   Output Arguments:

        hasTIMFeature  -  returns false if it is a TIM-model, returns true if 
						  is a non-TIM model and it has ATB features.

   Return Values:
                
PRO_TK_NO_ERROR   - The function run successfully.
PRO_TK_BAD_INPUTS - The function could not run, since one or more REQUIRED
                    inputs were missing or incorrect.
*/

extern ProError ProModelListTIMFeatures(ProMdl model, int **p_feat_ids);
/*
   Purpose: Utility function to list the feature ids of all the ATB-Enabled
             TIM Features in a Model. A TIM Feature is a model imported from
             ICEM or Neutral. This utility function can be run
             after determining if a Model has one or more TIM feature(s), using
             the utility function ProModelHasTIMFeature(...)

   Input Arguments:

        model  -  Creo Parametric Part or Assembly.

   Output Arguments:

        p_feat_ids - returns the list of ids of ATB-enabled features.
                     If NO TIM Features can be found in the model, the return
                     value *p_feat_ids is NULL.
                     The function allocates space for this ProArray. User must
                     call ProArrayFree() to free the array of integer(s).

   Return Values:
  
PRO_TK_NO_ERROR   - The function run successfully.
PRO_TK_BAD_INPUTS - The function could not run, since one or more REQUIRED
                    inputs were missing or incorrect.
*/

PRO_END_C_DECLS

#endif /* PROATB_H */
