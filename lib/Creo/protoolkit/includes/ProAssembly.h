



#ifndef PROASSEMBLY_H
#define PROASSEMBLY_H

#include <ProObjects.h>

PRO_BEGIN_C_DECLS

extern ProError ProAssemblyExplode ( ProAssembly assembly );
/*
   Purpose:     Explodes the specified assembly.  The function invalidates
                the display list, but the application needs to repaint the
                window.

   Input Arguments:

      assembly          - The assembly to explode

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully exploded the assembly.
      PRO_TK_BAD_INPUTS - The specified assembly is not an assembly, or is NULL. 
      PRO_TK_NO_CHANGE  - The specified assembly is already exploded.
*/

extern ProError ProAssemblyUnexplode ( ProAssembly assembly );

/*
   Purpose:     Unexplodes the specified assembly.  The function invalidates
                the display list, but the application needs to repaint the
                window.

   Input Arguments:

      assembly          - The assembly to unexplode

   Output Arguments:

      None

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully unexploded the assembly.
      PRO_TK_BAD_INPUTS - The specified assembly is not an assembly, or
                          is NULL.
      PRO_TK_NO_CHANGE  - The specified assembly is already unexploded. 
*/


extern ProError ProAssemblyIsExploded ( ProAssembly assembly,
                                        ProBoolean *p_is_exploded);
/*
   Purpose:     Determines whether the specified assembly is exploded.

   Input Arguments:

      assembly          - The assembly whose state is to be determined.

   Output Arguments:

      p_is_exploded     - If this is PRO_B_TRUE, the assembly is exploded.
                          If this is PRO_B_FALSE, the assembly is unexploded.

   Return Values:

      PRO_TK_NO_ERROR   - The function successfully retrieved the information. 
      PRO_TK_BAD_INPUTS - The specified assembly is not an assembly,
                          or is NULL.
*/

extern ProError ProAssemblyDynPosGet ( ProAssembly top_assem,
                                       ProBoolean *p_enable);
/*
   Purpose:     Determines whether dynamic component positioning is enabled or
                disabled for the specified assembly.

   Input Arguments:
      top_assem         - The top-level assembly for which to determine
                          the status of dynamic positioning
   Output Arguments:
      p_enable          - If this is PRO_B_TRUE, the specified assembly 
                          currently has dynamic positioning enabled. 
                          If this is PRO_B_FALSE, the specified
                          assembly currently has dynamic
                          positioning disabled.

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully retrieved the value.
       PRO_TK_BAD_INPUTS - The input argument is invalid.
*/

extern ProError ProAssemblyDynPosSet ( ProAssembly top_assem,
                                       ProBoolean  enable);
/*
   Purpose:     Enables or disables dynamic component positioning. When
                enabled, all the components can have a unique
                transformation with respect to the top-level assembly.

   Input Arguments:
      top_assem         - The top-level assembly for which to enable
                          dynamic positioning
      enable            - The Boolean value that enables or disables
                          positioning
 
   Output Arguments:
      none

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully set the new value.
       PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
*/

extern ProError ProMdlActiveGet    (ProMdl     *p_handle);
/*
   Purpose:  Initializes the <i>p_handle</i> with the active Creo Parametric 
             object. 

   Input Arguments:
      None

   Output Arguments:
      p_handle     - The model handle
 
   Return Values:
      PRO_TK_NO_ERROR    - The function successfully initialized the handle.
      PRO_TK_BAD_CONTEXT - The active Creo Parametric object is not set.
     
*/

extern ProError ProAssemblyAutointerchange (
			ProAssembly assembly,
			int         *component_ids,
			ProMdl      replacement_model
			);
/*
 Purpose:     Performs the automatic replacement of an assembly member, 
              in the manner of Creo Parametric.
              <p>
              Note that Creo Parametric enables automatic replacement of 
              assembly members using the following methods:
              <ul>
              <li>Interchange groups
              <li>Instances of family tables
              <li>Global reference datums in layouts
              </ul>
 Input Arguments:
      assembly          - The assembly or subassembly.
      component_ids     - The ProArray of component identifiers from the
                          assembly node <i>assembly</i> that identifies the
                          replaced members. 
      replacement_model - The replacement component. This can be a part
                          or subassembly.  

 Output Arguments:
     none

 Return Values:
     PRO_TK_NO_ERROR       - The function succeeded
     PRO_TK_BAD_INPUTS     - One or more arguments are invalid.
     PRO_TK_GENERAL_ERROR  - A general error occurred and the function failed.
*/

PRO_END_C_DECLS

#endif /* PROASSEMBLY_H */
