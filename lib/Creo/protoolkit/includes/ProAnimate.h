#ifndef PROANIMATE_H
#define PROANIMATE_H

#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProSelection.h>




#define PRO_AT_STOP  1
#define PRO_AT_PLAY  2
#define PRO_AT_PAUSE 3

#define PRO_AT_BUTTON_PLAY               1
#define PRO_AT_BUTTON_PLAY_REV           2
#define PRO_AT_BUTTON_STOP               3
#define PRO_AT_BUTTON_SKIP_TO_END        4
#define PRO_AT_BUTTON_SKIP_TO_BEGINING   5
#define PRO_AT_BUTTON_FRAME_FOR          6
#define PRO_AT_BUTTON_FRAME_REV          7
#define PRO_AT_BUTTON_SLIDER_MOVE        8

PRO_BEGIN_C_DECLS
 

typedef int (*ProAnimButtonCb)(void *window, int curr_frame, int anim_button,
                               int play_state);

/*

Purpose: Signature of notification callback function performed when a button 
         in the animation dialog is picked.  <p>

     <b>NOTE:</b> The callback is registered using the generic Creo Parametric TOOLKIT
                  notification method, and is called whenever a button is
                  pressed on the animation dialog. </p>

Input Arguments:
   window      - The window that is animating
   curr_frame  - The frame that is currently displayed in the window
   anim_button - The button that was pressed to cause this callback
   play_state  - The play state of the animation: either playing or stopped

Output Arguments:

   None

Return Values:
  Return values are not interpreted by Creo Parametric
 */



typedef struct Pro_Animobj      *ProAnimObj;   /* opaque handle for animation */
                                               /* object pointer              */

typedef struct Pro_Animframe    *ProAnimFrame; /* opaque handle for animation */
                                               /* frame pointer containing    */
                                               /* several animation objects   */

typedef struct Pro_Animmovie    *ProAnimMovie; /* opaque handle for animation */
                                               /* movie containing several    */
                                               /* animation frames            */

typedef struct Pro_Animquality  *ProAnimQuality; /* opaque handle to specify  */
                                                 /* quality for animation     */
                                                 /* to be detailed (CK/KMR)   */

typedef struct Pro_SingleAnim      *ProSingleAnim;

/* definition of animation objects */

extern ProError ProAnimobjectCreate(ProSelection  p_select, 
                                    ProMatrix     position,
                                    ProAnimObj   *anim_obj);
/*
   Purpose: Prepares an animation object.

<p>    <b>NOTE:</b>  This function does not support external objects.

   Input Arguments:

      p_select  - The item to be animated. Currently, this can be 
                  a part or an assembly only.

      position  - Indicates the location of the animation item with respect
                  to its immediate parent.

   Output Arguments:

      anim_obj  - The handle to the newly created object for animation.

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully created the object.

      PRO_TK_BAD_INPUTS - The specified object type is not supported.
*/

extern ProError ProAnimobjectDelete (ProAnimObj   anim_obj);

/*
   Purpose: Deletes the specified animation object.

   Input Arguments:

      anim_obj - The handle to the animation object to be deleted

   Output Arguments:

      None

   Return Values:
  
      PRO_TK_NO_ERROR   - The function successfully deleted the object.
*/

/* definition of an animation frame */

extern ProError ProAnimframeCreate (ProMatrix     frame_view,
                                   ProAnimFrame *anim_frame);
/*
   Purpose: Creates an animation frame.

   Input Arguments:

      frame_view  - This is the transformation from the root assembly;
                    therefore, it is an absolute location in the top
                    model coordinate system.

   Output Arguments:

      anim_frame  - The handle to the newly created animation frame.

   Return Values:

      PRO_TK_NO_ERROR - The function successfully created the frame.
*/

extern ProError ProAnimframeDelete (ProAnimFrame  anim_frame);
/*
   Purpose: Deletes the specified animation frame.

   Input Arguments:

      anim_frame - The handle to the animation frame to be deleted

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR - The function successfully deleted the animation frame.
*/

extern ProError ProAnimframeObjAdd (ProAnimFrame anim_frame,
                                    ProAnimObj   anim_obj);
/*
   Purpose: Adds the specified animation object to the animation frame.

   Input Arguments:

      anim_frame - The handle to the animation frame

      anim_obj   - The handle to the animation object to be added

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR - The function successfully added the object.
*/

extern ProError ProAnimframeObjRemove(ProAnimFrame anim_frame, 
                                      ProAnimObj   anim_obj);
/*
   Purpose: Removes the specified animation object from the animation frame.

   Input Arguments:

      anim_frame - The handle to the animation frame

      anim_obj   - The handle to the animation object to be removed

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR - The function successfully removed the object.
      PRO_TK_E_NOT_FOUND - amin_obj is not in the frame.
*/

typedef ProError (*ProAnimObjAct)(ProAnimObj anim_obj,
                                 ProAppData app_data);
/*
   Purpose: This is the generic function for visiting animation objects.

   Input Arguments:

      anim_obj   - The handle to the animation object

      app_data   - The application data passed to the
                   function <b>ProAnimframeObjVisit()</b>

  Output Arguments:
     none

  Return Values:
     PRO_TK_NO_ERROR - If this is the filter function, proceed to the visit action. 
     Any other value - If this is the filter function, skip this item.

     If this is the visit action, return values are not interpreted by Creo Parametric
*/


extern ProError ProAnimframeObjVisit(ProAnimFrame     anim_frame, 
                                     ProAnimObjAct    visit_action,
                                     ProAnimObjAct    filter_action,
                                     ProAppData       app_data);
/*
   Purpose: Visits the animation objects in an animation frame.

   Input Arguments:

      anim_frame    - The handle to the animation frame

      visit_action  - The application-supplied function to be invoked for each
                      animation object

      filter_action - The application-supplied function to be invoked for each
                      animation object that decides whether the animation
                      object should be visited. If NULL, all animation objects
                      are visited using the action function. 

      app_data      - The application-supplied data to be passed to the
                      visit and filter functions

   Output Arguments:

      None

   Return Values:
      PRO_TK_NO_ERROR - The function successfully visited all the objects.

*/ 

/*
   Animation at frame level.
   Here the intention is that the user does not have
   all the frames set up (it may depend on future
   user interaction, for example).
   Termed as Single Animation.
 */

extern ProError ProSingleAnimationInit(ProMdl         top_model,
                                      ProAnimFrame   anim_frame,
                                      ProSingleAnim *single_anim_obj);
/*
   Purpose: Initializes an animation in single mode.

   Input Arguments:

      top_model       - The top-level model being animated
      anim_frame      - The first animation frame

   Output Arguments:

      single_anim_obj - The handle for single mode animation

   Return Values:

      PRO_TK_NO_ERROR - The function successfully initialized the
                        animation.
*/

extern ProError ProSingleAnimationPlay (ProSingleAnim  single_anim_obj,
                                      ProAnimFrame   anim_frame);
/*
   Purpose: Performs a single mode animation.

   Input Arguments:

      single_anim_obj - The handle for single mode animation

      anim_frame      - The animation frame to be played

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR      - The function successfully drew the frame.

      PRO_TK_GENERAL_ERROR - The function could not draw the frame. 
*/


extern ProError ProSingleAnimationClear(ProSingleAnim  single_anim_obj);
/*
   Purpose: Clears the data generated for single mode animation.

   Input Arguments:

      single_anim_obj - The handle for single mode animation

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR - The function successfully cleared the data.
*/


/* definition of an animation movie */

extern ProError ProAnimmovieCreate (ProMdl         top_model,
                                   ProAnimMovie  *anim_movie);
/*
   Purpose: Creates an animation movie.

   Input Arguments:

      top_model    - The top-level model being animated

   Output Arguments:

      anim_movie   - The handle to the newly created animation movie

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully created the animation
                          movie.

      PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProAnimmovieDelete (ProAnimMovie anim_movie); 
/*
   Purpose: Deletes the specified animation movie.

   Input Arguments:

      anim_movie - The handle to the animation movie to be deleted

   Output Arguments:

      None

   Return Values: 

      PRO_TK_NO_ERROR - The function successfully deleted the animation
                        movie.
*/


extern ProError ProAnimmovieFrameAdd (ProAnimMovie  anim_movie,
                                     ProAnimFrame  anim_frame);
/*
   Purpose: Adds the specified animation frame to a movie.

   Input Arguments:

      anim_movie - The handle to the animation movie

      anim_frame - The handle to the animation frame to be added

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR - The function successfully added the frame.
*/

extern ProError ProAnimmovieFrameRemove(ProAnimMovie  anim_movie, 
                                        ProAnimFrame  anim_frame);
/*
   Purpose: Removes the specified animation frame from a movie.

   Input Arguments:

      anim_movie - The handle to the animation movie

      anim_frame - The handle to the animation frame to be removed

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR    - The function successfully removed the frame.

      PRO_TK_E_NOT_FOUND - The function did not remove the frame because
                           the specified frame was not set in the
                           animation movie.
*/

typedef ProError (*ProAnimFrameAct)(ProAnimFrame anim_frame,
                                   ProAppData   app_data);
/*
   Purpose: This is the generic function definition for visiting animation
            frames.

   Input Arguments:

      anim_frame - The handle to the animation frame being visited

      app_data   - The application data passed to the function
                   <b>ProAnimmovieFrameVisit()</b>

   Output Arguments:
      None
  
   Return Values:
     PRO_TK_NO_ERROR - If this is the filter function, proceed to the visit action. 
     Any other value - If this is the filter function, skip this item.

     If this is the visit action, return values are not interpreted by Creo Parametric.
*/


extern ProError ProAnimmovieFrameVisit (ProAnimMovie      anim_movie,
				        ProAnimFrameAct   visit_action,
                                        ProAnimFrameAct   filter_action,
                                        ProAppData        app_data);
/*
   Purpose: Visits animation frames in an animation movie.

   Input Arguments:

      anim_movie    - The handle to the animation movie

      visit_action  - The application-supplied function to be invoked for each
                      animation frame

      filter_action - The application-supplied function to be invoked for each
                      animation frame that decides whether the animation
                      frame should be visited. If NULL, all frames are visited 
                      using the action function. 

      app_data      - The application-supplied data passed to the
                      visit and filter functions

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR - The function successfully visited all the
                        animation frames. 
*/


/* 
   Animation at movie level.
   Here the animation frames are known prior to animation.
   Termed as Batch Animation.
 */

typedef ProError (*ProBatchAnimAct) (ProAnimFrame  anim_frame,
                                   int           frame_no,
                                   ProAppData    app_data);
/*
   Purpose: This is the generic function for callbacks in the
            middle of a batch animation.

   Input Arguments:
      anim_frame - The handle to the animation frame about to be displayed
      frame_no   - The frame number being displayed
      app_data   - The application data passed to the function
                   <b>ProBatchAnimationStart()</b>

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR  -  Continue with batch animation.
      Other            -  Stop batch animation.
*/

extern ProError ProBatchAnimationStart (ProAnimMovie      anim_movie,
                                       ProBatchAnimAct   callback,
                                       ProAppData        app_data);
/*
   Purpose: Starts a batch animation process.

   Input Arguments:

      anim_movie - The handle to the animation movie

      callback   - The callback function called before each frame
                   is displayed

      app_data   - The application data to be passed to the callback when 
                   it is invoked

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR      - The batch animation was successful.
      PRO_TK_GENERAL_ERROR - There was an error starting the animation. 

*/

extern ProError ProAnimmovieSpinflagSet (ProAnimMovie animMovie,
                                         ProBoolean   spinFlag);
/*
   Purpose: To set spin flag for a batch animation process. When the animation
            includes view modifications, the flag should be set false,
	    otherwise true.

   Input Arguments: 
      animMovie - Handle to the animation movie.
      spinFlag  - Flag for allowing spin.

   Output Arguments:
      None.

   Return Values:
      PRO_TK_NO_ERROR      - Flag setting successful.
      PRO_TK_GENERAL_ERROR - There was an error setting the flag.
      PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
*/

PRO_END_C_DECLS

#endif  /* PRO_ANIMATE_H */

