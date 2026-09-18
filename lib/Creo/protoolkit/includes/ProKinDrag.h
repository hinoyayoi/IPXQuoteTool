#ifndef PRO_KIN_DRAG_H
#define PRO_KIN_DRAG_H



#include <ProToolkit.h>
#include <ProANSI.h>
#include <ProObjects.h>
#include <ProSelection.h>

PRO_BEGIN_C_DECLS

typedef enum proKinDragType
{
  PRO_KIN_POINT_DRAG,
  PRO_KIN_BODY_DRAG,
  PRO_KIN_ADVANCED_TRANS_X,
  PRO_KIN_ADVANCED_TRANS_Y,
  PRO_KIN_ADVANCED_TRANS_Z,
  PRO_KIN_ADVANCED_ROT_X,
  PRO_KIN_ADVANCED_ROT_Y,
  PRO_KIN_ADVANCED_ROT_Z
} ProKinDragType;

extern ProError ProKinDragStart (void);
/*
   Purpose: this function starts a drag session it should be called before any
            other Kinematic drag or Snapshot function is called. All subsequent
            functions will work with the Snapshots of the window assembly. All
            ProAsmcomppath should start from this assembly. All transforms 
            belong to this assembly. The function can be called for design 
            assemblies in Standard Assembly and Mechanism modes. It cannot be 
            used if assembly is exploded, if sketcher is active, when component
            placement is active or when drag dialog is on screen.

   Input Arguments:
      none

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR          - The function was successful.
      PRO_TK_CHECKOUT_CONFLICT - The function was successful, but some of 
                                 models are read only and can not be dragged.
      PRO_TK_GENERAL_ERROR     - The function cannot be called at this moment.
                                 For example, kin drag is not available in the
                                 current mode, some component is activated
                                 instead of top assembly, some dialog is 
                                 active on screen.
*/

extern ProError ProKinDragStop (void);
/*
   Purpose: this function will stop drag session. Function ProWindowRefresh() 
            should be performed to see the change of the graphic window scale
            according to updated outline.

   Input Arguments:
      none

   Output Arguments:
      none
   
   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_GENERAL_ERROR    - The function ProKinDragStart was not called
                                before.
*/

extern ProError ProKinDragSessionInquire (void);
/*
   Purpose: this function checks if drag session is on. The drag session may
            exist automatically in some cases: redefine, regeneration, window
            switch, representation mode chage etc.

   Input Arguments:
      none

   Output Arguments:
      none
   
   Return Values:
      PRO_TK_NO_ERROR         - The drag session is active.
      PRO_TK_GENERAL_ERROR    - The drag session is closed.
*/

extern ProError ProKinDragSnapshotsNamesGet (ProName **snap_names, 
       ProAsmcomppath **path_arr);
/* 
   Purpose: this function will bring all snapshots belonging to the window 
            assembly and its subassemblies.

   Input Arguments:
      none
      
   Output Arguments:
      snap_names              - The array of snapshot names.  The function 
                                allocates the memory for this argument. To free
                                the memory, call ProArrayFree().
      path_arr                - The array of ProAsmcomppath. The function
                                allocates the memory for this argument. To free
                                the memory, call ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_GENERAL_ERROR    - The function ProKinDragStart has not been called
                                before.
*/

extern ProError ProKinDragEnvironmentSet (const ProName snap_name,
       const ProAsmcomppath *path, const ProKinDragType type, 
       const ProSelection refobject);
/*
   Purpose: this function setups the environment for subsequenmt dragging and
            reconnect operations. Environment can be set / reset several times
            after ProKinDragStart() is called.

   Input Arguments: 
      snap_name - name of the existing snapshot which constraints will be active
                  during drag. NULL can be passed instead. The snapshot will be
                  checked for status (good / outdated /incomplete);
      path      - ProAsmcomppath of snapshot. NULL can be passed for top level 
                  snapshots. 
      type      - type of the drag to be performed.
      refobject - a selection represented coordinate system (PRO_CSYS),
                  part (PRO_PART) or body (PRO_MDO_BODY) for advanced drag. It
                  is relevant for advanced drag types only. For all other drag
                  types it is ignored, NULL should be passed instead. In part 
                  selection case takes coordinates of corresponded body.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_OUTDATED         - The environment has been set, but the snapshot
                                is outdated.
      PRO_TK_INCOMPLETE       - The environment has been set, but the snapshot
                                is incomplete.
      PRO_TK_CHECK_OMITTED    - The environment has been set, but the snapshot
                                validity check has not been performed, because
                                outdated or incomplete snapshot has earlier been
                                applied.
      PRO_TK_BAD_INPUTS       - One of the input parameters is bogus.
      PRO_TK_GENERAL_ERROR    - The function ProKinDragStart has not been called
                                before.
*/

extern ProError ProKinDragPerformMove (const ProSelection dragpoint, 
       const Pro2dPnt *screenx_y);
/*
   Purpose: this function bring to drag this selected object. Displays a
            hook point around the point. Performs a drag according to
            the environment set in ProKinDragEnvironmentSet().
            For dragging use constraints from current snapshot, if it set.
            After end of the movement the hook point is removed.

   Input Arguments:
      dragpoint               - A geometrical object (PRO_POINT, 
                                PRO_SURFACE_PNT, PRO_AXIS, PRO_EDGE, PRO_CURVE,
                                PRO_DATUM_PLANE, PRO_SRF_PLANE_PNT, PRO_SURFACE 
                                for PRO_KIN_POINT_DRAG, or PRO_PART, 
                                PRO_MDO_BODY for all other drag types) to be 
                                dragged. Set the selected-point using 
                                ProSelectionPoint3dSet(), otherwise the hook 
                                point will be wrong and movement result will be
                                wrong as well.
      screenx_y               - ProArray array of Pro2dPnt X and Y screen 
                                coordinates we want our dragpoint to be moved 
                                to.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_BAD_INPUTS       - Dragpoint cannot be used for dragging. For 
                                example, it may belong to Ground  or undefined
                                body.
      PRO_TK_NOT_VALID        - Connect failed. The model is left unchanged.
      PRO_TK_GENERAL_ERROR    - The function ProKinDragStart has not been 
                                called before.
*/

extern ProError ProKinDragReconnect (void);
/*
   Purpose: reconnect is performed taking into account constraints (but not
            transforms) from the snapshot specified in 
            ProKinDragEnvironmentSet(). Function ProWindowRefresh() should be 
            performed to see the changes in components positions.

   Input Arguments:
      none

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_NOT_VALID        - Connect failed. The model is left unchanged.
      PRO_TK_GENERAL_ERROR    - The function ProKinDragStart has not been called
                                before.
*/

extern ProError ProSnapshotApply (void);
/*
   Purpose: applies the transforms of the active snapshot. Unlike UI, no attempt
            to reconnect is performed here. User should call 
            ProKinDragReconnect() if reconnect is necessary. Function 
            ProWindowRefresh() should be performed to see the changes in 
            components positions.
            
   Input Arguments:
      none
 
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_OUTDATED         - The snapshot has been applied despite it is
                                outdated. All subsequent snapshot validity
                                checks will be omitted till next assembly 
                                regeneration (see also return code
                                PRO_TK_CHECK_OMITTED of 
                                ProKinDragEnvironmentSet()).
      PRO_TK_INCOMPLETE       - The snapshot has been applied despite it is
                                incomplete. All subsequent snapshot validity
                                checks will be omitted till next assembly 
                                regeneration (see also return code 
                                PRO_TK_CHECK_OMITTED of 
                                ProKinDragEnvironmentSet()).
      PRO_TK_GENERAL_ERROR    - No current snapshot is set.
*/

extern ProError ProSnapshotCreate (const ProName snap_name);
/*  
   Purpose: creates a top assembly level snapshot from the current position on
            screen. Constraints will be copied from the active snapshot.
            The newly created snapshot will become the active one.

   Input Arguments:
      snap_name               - Name of the snapshot to be created.

   Output Arguments:
      none 

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_INVALID_NAME     - The name specified is invalid or already used.
      PRO_TK_INVALID_ITEM     - Some of constraints could not be copied from
                                the active snapshot.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotUpdate (const ProName snap_name);
/*   
   Purpose: updates components transformation matrices in a snapshot from the 
            current position on screen. Constraints will be copied from the 
            active snapshot. The newly updated snapshot will become the active 
            one. Available for top level snapshot only.

   Input Arguments:
      snap_name               - Name of the snapshot to be updated.

   Output Arguments:
      none 

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotRename (const ProName new_snap_name);
/*   
   Purpose: renames the active snapshot.
            Available for top level snapshot only.

   Input Arguments:
      new_snap_name           - The new name of the snapshot.

   Output Arguments:
      none 

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_INVALID_NAME     - The name specified is invalid or already used.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotDelete (const ProName snap_name,
       const ProAsmcomppath *path);
/*   
   Purpose: delete a snapshot.

   Input Arguments:
      snap_name               - Name of the snapshot to be deleted.
      path                    - ProAsmcomppath of snapshot. NULL can be passed 
                                for top level. 

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotTrfsGet (const ProName snap_name,
       const ProAsmcomppath *path, ProAsmcomppath **path_arr, 
       ProMatrix **trf_arr);
/*
   Purpose: brings transformation paths and transformation matrices for all
            components in the snapshot versus top level assembly.

   Input Arguments:
      snap_name               - Name of the snapshot.
      path                    - ProAsmcomppath of snapshot. NULL can be passed 
                                for top level snapshot. 

   Output Arguments:
      path_arr                - The array of ProAsmcomppath calculated from top
                                assembly. The function allocates the memory for
                                this argument. To free the memory, call 
                                ProArrayFree().
      trf_arr                 - The array of transformation matrices showing 
                                transformation from specified component to the
                                top level assembly. The function allocates the
                                memory for this argument. To free the memory,
                                call ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/


extern ProError ProSnapshotTrfsUpdate (const ProName snap_name,
       const ProAsmcomppath *path_arr, const ProMatrix *trf_arr);
/*
   Purpose: updates transformation matrices for several components in the
            snapshot. Display is left unchanged. Available for top level 
            snapshot only.

   Input Arguments:
      snap_name               - Name of the snapshot to be updated.
      path_arr                - The array of ProAsmcomppath.
      trf_arr                 - The array of transformation matrices for these
                                paths.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotAllowedInDrawingSet (const ProBool allow);
/*
   Purpose: makes active snapshot available / unavailable in drawings.
            Available for top level snapshot only.

   Input Arguments:
      allow                   - Make available if allow is PRO_B_TRUE 
                                and unavailable otherwise. 
   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotAllowedInDrawingGet (ProBool *p_is_allowed);
/*
   Purpose: finds if the active snapshot is allowed in drawing or not. 

   Input Arguments:
      none

   Output Arguments:
      p_is_allowed            - PRO_B_TRUE if snapshot is allowed in drawing 
                                or PRO_B_FALSE otherwise. 

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

typedef enum proSnapshotConstraintType
{
  PRO_SNAP_UNSUPPORTED = -1,
  /* Standard constraints types supported in Drag dialog UI. */
  PRO_SNAP_ALIGN,                  
  PRO_SNAP_MATE,                        
  PRO_SNAP_ORIENT,
  PRO_SNAP_MOTION_AXIS_POS,
  PRO_SNAP_BODY_LOCK,        
  PRO_SNAP_CONNECTION_DISABLE, 
  PRO_SNAP_PARALLEL_VIEW_PLANE, /* Constraints of this type is temporary, and
                                   live only during current drag API session.*/
                                   
  PRO_SNAP_CAM_LIFTOFF_ENABLE,
  PRO_SNAP_CAM_LIFTOFF_DISABLE
} ProSnapshotConstraintType;

/*
  Permitted selections types corresponding to ProSnapshotConstraintType
  
  PRO_SNAP_ALIGN     - PRO_POINT, PRO_SURFACE_PNT, PRO_AXIS, PRO_EDGE, 
                       PRO_CURVE, PRO_DATUM_PLANE, PRO_SRF_PLANE_PNT, 
                       PRO_SURFACE.
  PRO_SNAP_MATE,   
  PRO_SNAP_ORIENT    - PRO_DATUM_PLANE, PRO_SRF_PLANE_PNT, PRO_SURFACE.
  PRO_SNAP_MOTION_AXIS_POS
                     - PRO_MDO_CONN_AXIS_ROT_1/2/3, PRO_MDO_CONN_AXIS_TR_1/2/3,
                       PRO_MDO_SLOT_AXIS.
  PRO_SNAP_BODY_LOCK - PRO_PART, PRO_MDO_BODY.
  PRO_SNAP_CONNECTION_DISABLE
                     - PRO_MDO_CONN, PRO_MDO_CAM_CONN, PRO_MDO_SLOT_CONN, 
                       PRO_MDO_GEAR_CONN.
  PRO_SNAP_PARALLEL_VIEW_PLANE
                     - PRO_POINT, PRO_SURFACE_PNT, PRO_EDGE_START, PRO_EDGE_END,
                       PRO_CRV_START, PRO_CRV_END, PRO_AXIS, PRO_EDGE, 
                       PRO_CURVE, PRO_SRF_PLANE_PNT, PRO_SURFACE, 
                       PRO_DATUM_PLANE.
                       (All types of the selections will be interpreted as a 
                        point. In line and surface cases, the point is 
                        evaluated using the UV parameters.)
  PRO_SNAP_CAM_LIFTOFF_ENABLE/_DISABLE 
                     - PRO_MDO_CAM_CONN.
*/

typedef struct proSnapshotConstraint
{
  ProSnapshotConstraintType   type;
  ProSelection               *sel_array;  /* ProArray of selections.
    Number of selection depends on the constraint type. 1 selection is needed
    for PRO_SNAP_MOTION_AXIS_POS, PRO_SNAP_CONNECTION_DISABLE, 
    PRO_SNAP_PARALLEL_VIEW_PLANE, PRO_SNAP_CAM_LIFTOFF_ENABLE/DISABLE; 
    2 selections are needed for PRO_SNAP_ALIGN, PRO_SNAP_MATE, PRO_SNAP_ORIENT,
    2 or more selections can be used for PRO_SNAP_BODY_LOCK. */
  double                      value;      /* Meaningful for 
    PRO_SNAP_MOTION_AXIS_POS, and also for plane references used in 
    PRO_SNAP_ALIGN, PRO_SNAP_MATE, PRO_SNAP_ORIENT. */
  ProBool                     user_active; /* Turns constraint on or off. */
  ProBool                     valid;       /* The values are 
    PRO_B_TRUE  - the constraint is valid (active), 
    PRO_B_FALSE - the constraint is invalid (supressed) */
} ProSnapshotConstraint;

extern ProError ProSnapshotConstraintsGet (const ProName snap_name,
       const ProAsmcomppath *path, ProSnapshotConstraint **constraints);

/*
   Purpose: brings all constraints from a snapshot.

   Input Arguments:
      snap_name               - Name of the snapshot.
      path                    - ProAsmcomppath of snapshot. NULL can be passed 
                                for top level. 

   Output Arguments:
      constraints             - The array of snapshot constraints. The function
                                allocates the memory for this argument. To free
                                the memory, call ProSelectionarrayFree() for
                                sel_array in each constraint and then
                                ProArrayFree() for the constraints.

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotConstraintAdd (const ProName snap_name,
       const ProSnapshotConstraint *constraint);
/*
   Purpose: adds a constraint to a snapshot.
            Available for top level snapshot only.

   Input Arguments:
      snap_name               - Name of the snapshot.
      constraint              - Pointer of the constraint to be added.
                                The field constraint->valid is ignored.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_E_FOUND          - The similar constraint exists in the snapshot.
      PRO_TK_OUT_OF_RANGE     - The constraint->value is out of range.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotConstraintDelete (const ProName snap_name, 
       const int ndx);
/*
   Purpose: deletes  a constraint from a snapshot.
            Available for top level snapshot only.

   Input Arguments:
      snap_name               - Name of the snapshot.
      ndx                     - Index of the constraint from the constraints
                                array (as brought by 
                                ProSnapshotConstraintsGet()) to be deleted.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_BAD_INPUTS       - The specified index is wrong.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError ProSnapshotConstraintUpdate  (const ProName snap_name, 
       const int ndx, const ProSnapshotConstraint *constraint);
/*
   Purpose: updates a constraint in a snapshot.
            Available for top level snapshot only.
   
   Input Arguments:
      snap_name               - Name of the snapshot.
      ndx                     - Index of the constraint from the constraints
                                array (as brought by
                                ProSnapshotConstraintsGet()) to be updated.
      constraint              - Pointer to the new constraint to be used instead
                                of the old one. The field constraint->valid is 
                                ignored.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_E_NOT_FOUND      - The snapshot with specified name is not found.
      PRO_TK_BAD_INPUTS       - The specified index is wrong.
      PRO_TK_E_FOUND          - The similar constraint exists in the snapshot.
      PRO_TK_OUT_OF_RANGE     - The constraint->value is out of range.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/

extern ProError 
ProSnapshotConstraintEvaluate (const ProSnapshotConstraint *constraint, 
                               double *position);
/*
   Purpose: evaluate a constraint of type PRO_SNAP_MOTION_AXIS_POS for the model
            shown on screen. The function does not depend on the current
            snapshot, and it is not important whether the snapshot contains the
            constraint or not.

   Input Arguments:
      constraint              - Pointer to the constraint of type 
                                PRO_SNAP_MOTION_AXIS_POS with sel_array field
                                filled up before calling the function. The 
                                fields constraint->user_active and 
                                constraint->valid are ignored.
   Output Arguments:
      position                - The current motion axis position.
      
   Return Values:
      PRO_TK_NO_ERROR         - The function was successful.
      PRO_TK_BAD_INPUTS       - The constraint is incorrect or it is not of type
                                PRO_SNAP_MOTION_AXIS_POS.
      PRO_TK_GENERAL_ERROR    - The function failed.
*/


PRO_END_C_DECLS

#endif

