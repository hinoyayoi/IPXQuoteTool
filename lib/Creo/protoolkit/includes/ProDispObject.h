

#ifndef PRODISPOBJECT_H
#define PRODISPOBJECT_H

#include <ProSurface.h>


typedef void *ProDispObject;

typedef struct _ProTriVertex
{
  float pnt[3];
  float norm[3];
}ProTriVertex;


#define PRO_DISP_OBJECT_TWO_SIDED         (0x1<<0) /* ProDispObject with two sided display */
#define PRO_DISP_OBJECT_DYNAMIC_PREVIEW   (0x1<<1) /* ProDispObject is dynamic i.e. will be used for very little 
                                              time and deleted. */


PRO_BEGIN_C_DECLS

extern ProError ProDispObjectCreate(ProName object_name, int flag, int num_strips,
                                    int *strip_size, ProTriVertex **strips_array,
                                    ProDispObject *p_disp_obj);
/*
Purpose:  Create a Display Object. Display object is used to record application specific triangle data which 
          is then displayed by Creo using creo lighting and materials. Display objects are attached to creo scene graph
          using ProDispObjectAttach and are rendered along creo native scene.
          Display objects will not participate in creo HLR calculations. They will always be displayed in shaded mode
          irrespective of what current view display mode is.


   Input Arguments:

   object_name - Name of new object. Name must be unique. 
   flag        - Bit encoded flag to set property of display object

               0x0                      : If no bit is set display object will behave like a solid
               PRO_DISP_OBJECT_TWO_SIDED: When this bit is set object will behave like quilts
               PRO_DISP_OBJECT_DYNAMIC_PREVIEW: Object is temporary and will be deleted/recreated frequently. 
                                                If this flag is not set then creo will try to put the data on graphics card
                                                to speed up its display. But if the flag is set this optimization will not be 
                                                done because transferring data to graphics card will take more time than 
                                                performance gain we will achieve by such transfer.
                                                

   num_strips   - The number of triangle strips
   strip_size   - ProArray (of size num_strips) indicating the number
                  of triangles in each strip
   strips_array - An array of num_strips triangle strips.

   Output Arguments:

   p_disp_obj - a handle to the object that was created

   Return Values:
   PRO_TK_NO_ERROR   - The function succeeded.
   PRO_TK_E_FOUND    - Object with same name already exist. Delete previous object (or use new name)
   PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProDispObjectDelete(ProDispObject *obj);
/*

 Purpose: Delete a display object.
          Object must be detached before it is deleted.


 Input Arguments:
   obj - ProDisplayObject which will be deleted

 Output Arguments:
   None

 Return Values:
   PRO_TK_NO_ERROR - The function succeeded.
   PRO_TK_GENERAL_ERROR - One or more input arguments was invalid.
*/




extern ProError ProDispObjectAttach(int window, ProDispObject obj, int *key_list,
                                    int new_key, ProMatrix transform);
/*

 Purpose: Attach a display object to creo scene. Once attached display object
          will be rendered along with rest of creo graphics. 
          If scene is regenerated i.e. creo scene graph is recreated for some reason, 
          application must reattach them. This API is only for 3d mode (part/assembly etc)
          and won't work in 2D (drawings, sketch, CE).


 Input Arguments:
    window     - Identifier of window in which ProDispObject will be attached to Creo scene.
    obj        - Display object which will be attached to creo scene
    key_list   - ProArray containing member identifier table of the component
                 to which the display object will be attached. 
                 If the display object is to be attached on top level component
                 this should be NULL.
    new_key    - a unique(in the scope of key_list) identifier for the new node which will
                 contain the display object.
    transform  - transform from the parent(specified by key list)
                 to the new object node

 Output Arguments:

 Return Values:
   PRO_TK_NO_ERROR      - The function succeeded
   PRO_TK_E_NOT_FOUND   - Parent (attach point) doesn't exist
   PRO_TK_NOT_VALID     - new_key for ProDispObject is already in use.
   PRO_TK_BAD_INPUTS    - Invalid input arguments (bad window or NULL display object)
   PRO_TK_GENERAL_ERROR - One or more input arguments was invalid
   PRO_TK_UNSUPPORTED   - Function is not supported on given window(because it is 2D window, like drawing or sketcher).
*/



extern ProError ProDispObjectDetach(int window, int *key_list);
/*

 Purpose: Detach a display object that was added to creo scene. 
          Object must be detached before it is deleted.
          This API is only for 3d mode (part/assembly etc)
          and won't work in 2D (drawings, sketch, CE).


 Input Arguments:
   window   - Identifier of window in which ProDispObject will be detached from Creo scene
   key_list - ProArray containing member_identification table of ProDispObject which will be
              detached from scene graph. This is the "key_list" passed to ProDispObjectAttach 
              plus the "new_key"

 Output Arguments:

 Return Values:
   PRO_TK_NO_ERROR      - The function succeeded
   PRO_TK_BAD_INPUTS    - Invalid window
   PRO_TK_E_NOT_FOUND   - ProDispObject not found in the scene graph of window
   PRO_TK_GENERAL_ERROR - One or more input arguments was invalid
*/


extern ProError ProDispObjectSetTransform( int window, int *key_list,
                                           ProMatrix trf, ProMatrix old_trf );
/*

 Purpose: Sets the transform of an object relative to it's parent in
          creo scene. This API is only for 3d mode (part/assembly etc)
          and won't work in 2D (drawings, sketch, CE).


 Input Arguments:
   window   - Identifier of window in which ProDispObject will be detached from Creo scene
   key_list - ProArray containing member_identification table of ProDispObject which will be
              detached from scene graph. This is the "key_list" passed to ProDispObjectAttach 
              plus the "new_key
   trf      - new transform for this display object relative to its parent.

 Output Arguments:
   old_trf - old transform for this display object

 Return Values:
   PRO_TK_NO_ERROR      - The function succeeded
   PRO_TK_BAD_INPUTS    - Invalid window
   PRO_TK_E_NOT_FOUND   - ProDispObject not found in the scene graph of window
   PRO_TK_GENERAL_ERROR - One or more input arguments was invalid
   PRO_TK_UNSUPPORTED   - Function is not supported on given window(because it is 2D window, like drawing or sketcher).
*/




extern ProError ProDispObjectSetSurfaceAppearanceProps( int window, int *key_list,
                                                 ProSurfaceAppearanceProps  surf_appearance_props );

/*
 Purpose: Sets appearance prop of a disp object attached to scene. 
          This API is only for 3d mode (part/assembly etc)
          and won't work in 2D (drawings, sketch, CE).
          

 Input Arguments:
   window   - Identifier of window in which ProDispObject will be detached from Creo scene
   key_list - ProArray containing member_identification table of ProDispObject which will be
              detached from scene graph. This is the "key_list" passed to ProDispObjectAttach 
              plus the "new_key
   surf_appearance_props - New appearance property for display object.

 Output Arguments:

 Return Values:
   PRO_TK_NO_ERROR      - The function succeeded
   PRO_TK_BAD_INPUTS    - Invalid window
   PRO_TK_E_NOT_FOUND   - ProDispObject not found in the scene graph of window
   PRO_TK_GENERAL_ERROR - One or more input arguments was invalid
   PRO_TK_UNSUPPORTED   - Function is not supported on given window(because it is 2D window, like drawing or sketcher).

*/

PRO_END_C_DECLS

#endif /* PRODISPOBJECT_H */
