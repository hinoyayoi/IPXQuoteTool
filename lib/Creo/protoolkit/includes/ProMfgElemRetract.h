#ifndef PROMFGELEMRETRACT_H
#define PROMFGELEMRETRACT_H

/*
   Creo Parametric TOOLKIT declarations related to mfg retract specification.
*/



PRO_BEGIN_C_DECLS

/*==============================================================================

(1) Element tree

       -- PRO_E_RETR_SURF
             |
             |-- PRO_E_RETR_SURF_TYPE
             |   
             |-- PRO_E_RETR_SURF_REF
             |
             |-- PRO_E_RETR_SURF_ORIENT
             |
             |-- PRO_E_RETR_SURF_VALUE
      
================================================================================

(2) Elements table

-----------------------------------------------------------------------------------------
Element Id              Element Name               Data Type                 Valid Values
-----------------------------------------------------------------------------------------
PRO_E_RETR_SURF         Retract Surface            Compound                  Note-1
PRO_E_RETR_SURF_TYPE    Retract Surface Type       PRO_VALUE_TYPE_INT        Note-2
PRO_E_RETR_SURF_REF     Retract Surface Reference  PRO_VALUE_TYPE_SELECTION  Note-3
PRO_E_RETR_SURF_ORIENT  Orient Direction           PRO_VALUE_TYPE_INT        Note-4
PRO_E_RETR_SURF_VALUE   Offset/Radius Value        PRO_VALUE_TYPE_DOUBLE     Note-5

================================================================================

(3) Notes

Note-1  : Retract surface compound specification.
          Mandatory for sequence.
          Optional for operation.

Note-2  : Type of retract surface:

             PRO_RETR_SURF_UNDEFINED - retract surface is not defined;
             PRO_RETR_SURF_PLANE     - plane;
             PRO_RETR_SURF_CYLINDER  - cylinder;
             PRO_RETR_SURF_SPHERE    - sphere;
             PRO_RETR_SURF_REVOLVED  - revolved suface.

          PRO_RETR_SURF_UNDEFINED is applicable for operations only.
          Cylinder, sphere and revolved surfaces are not applicable for
          3-axis sequences and operations with 3-axis workcell.
          Mandatory.
   
Note-2  : Selection of retract surface. Type of reference depends on
          PRO_E_RETR_SURF_TYPE value. 

          Plane retract: datum plane, planar surface, planar quilt,
          csys.  For 3-axis sequence (operation): 
            - planar surface has to be normal to Z axis of 
              sequence (operation) csys.
            - Z axis of selected datum csys has to be alligned with Z axis of 
              sequence (operation) csys.

          Cylinder retract: datum axis, csys.
          Sphere retract: datum point, csys.
          Revolved surface retract: revolved quilt.
          Mandatory.

Note-3  : Orientation of axis of retract cylinder if csys is selected as
          retract reference: 
             PRO_RETR_SURF_X_DIR; 
             PRO_RETR_SURF_Y_DIR; 
             PRO_RETR_SURF_Z_DIR.
          Mandatory if csys is selected for cylindrical retract reference. 
          Ingnored in all other cases.
   
Note-4  : Offset value for planar retract, or radius for cylinder and sphere.
          Mandatory.
  
==============================================================================*/
   
PRO_END_C_DECLS

#endif /*PROMFGELEMRETRACT_H */
