

#ifndef PRORMDT_H
#define PRORMDT_H

#include <ProMfg.h>

PRO_BEGIN_C_DECLS

typedef enum pro_rmdt_mirror
{
   MOLD_LAYOUT_MIRROR_NONE = 0,
   MOLD_LAYOUT_MIRROR_X    = 1,
   MOLD_LAYOUT_MIRROR_Y    = 2
} ProRmdtMirror;
   
typedef enum pro_rmdt_cavity_layout
{
   CAVITY_LAYOUT_DEFAULT   = 0,
   CAVITY_LAYOUT_SINGLE    = 1,
   CAVITY_LAYOUT_MULTIPLE  = 2,
   CAVITY_LAYOUT_RADIAL    = 3,
   CAVITY_LAYOUT_MANUAL    = 4,
   CAVITY_LAYOUT_REFERENCE = 5
} ProRmdtCavityLayout;
   
typedef struct MOLD_ASSEM* ProMoldLayout;

typedef struct
{
   int         cavity_layout_type;
   ProBoolean  is_symmetric;
   int         mirror_type;
   int         num, num_x, num_y;
   double      offset_x, offset_y;
   double      inc_x, inc_y;
   double      r_dist, start_angle, inc_angle;
} ProDlgCavityLayoutData;

typedef struct
{
   ProBoolean IsRect,
              IsSym;
   ProVector  rect_dim,
              rect_offset;
   double     radial_z,
              radial_offset,
	      radial_diam;
   ProVector  allowance[2];
   int        size_ref_by_id;
} ProDlgWorkpieceData;

extern ProError ProMfgMoldLayoutGet ( PRO_CONST_ARG ProMfg mfg_handle, 
                                      ProMoldLayout* p_mold_layout);
/* 
   Purpose:  Retrieves the mold layout of the specified manufacturing model.

   Input Arguments:
      mfg_handle         - The handle to the manufacturing model

   Output Arguments:
      p_mold_layout      - The handle to the mold layout

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_E_NOT_FOUND - The mold layout handle of the specified 
                           manufacturing was not found.
*/


extern ProError ProRmdtRefModelInfoGet ( ProMoldLayout mold_layout, 
                                         int index,
                                         double xyz_plus[3],
                                         double xyz_minus[3],
                                         double xyz_total[3]);
/* 
   Purpose:  Retrieves the reference model information for the 
             specified mold layout.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      index              - The index of the reference model

   Output Arguments:
      xyz_plus           - The upper boundaries of the reference model
      xyz_minus          - The lower boundaries of the reference model
      xyz_total          - The outline size of the reference model

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError ProRmdtWorkpieceInfoGet ( ProMoldLayout mold_layout, 
                                   int index,
                                   double xyz_plus[3],
                                   double xyz_minus[3], 
                                   double xyz_total[3]);
/* 
   Purpose:  Retrieves the workpiece information for the 
             specified mold layout.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      index              - The index of the workpiece

   Output Arguments:
      xyz_plus           - The upper boundaries of the workpiece
      xyz_minus          - The lower boundaries of the workpiece
      xyz_total          - The outline size of the workpiece

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the input arguments are invalid.
*/


extern ProError ProRmdtMoldBaseInfoGet ( ProMoldLayout mold_layout,
                                         char ***p_param_names, 
                                         wchar_t ***p_param_values,
                                         int *p_param_num,
                                         int *p_corner);
/* 
   Purpose:  Retrieves the mold base information for the 
             specified mold layout.  The function reuses memory.

   Input Arguments:
      mold_layout        - The handle to the mold layout.

   Output Arguments:
      p_param_names      - The array of parameter names of the mold base.
      p_param_values     - The array of parameter values of the mold base.
      p_param_num        - The number of parameters of the mold base.
      p_corner           - The corner of the mold base:
			   <ul>
                           <li>Corner 0 is the top-left corner.
                           <li>Corner 1 is the top-right corner.
                           <li>Corner 2 is the bottom-right corner.
                           <li>Corner 3 is the bottom-left corner.
			   </ul>

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError ProRmdtMaterialInfoGet ( ProMoldLayout mold_layout,
                                         char ***p_param_names, 
                                         wchar_t ***p_param_values, 
                                         int *p_param_num);
/* 
   Purpose:  Retrieves the material information for the specified
             mold layout.  The function reuses memory.

   Input Arguments:
      mold_layout        - The handle to the mold layout

   Output Arguments:
      p_param_names      - The array of parameter names of the material
      p_param_values     - The array of parameter values of the material
      p_param_num        - The number of parameters of the material

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError ProRmdtImmInfoGet ( ProMoldLayout mold_layout, 
                                    wchar_t      **p_machine_name,
                                    char        ***p_param_names, 
                                    wchar_t     ***p_param_values, 
                                    int           *p_param_num);
/* 
   Purpose:  Retrieves the injection module machine (IMM) information 
             for the specified mold layout.  The function reuses the memory.

   Input Arguments:
      mold_layout        - The handle to the mold layout

   Output Arguments:
      p_machine_name     - The name of the IMM 
      p_param_names      - The array of parameter names of the IMM 
      p_param_values     - The array of parameter values of the IMM 
      p_param_num        - The number of parameters of the IMM 

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully retrieved the
                           information.
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
*/


extern ProError ProRmdtDlgMaterialSet ( ProMoldLayout mold_layout,
				        wchar_t      *generic_type,
				        wchar_t      *mfg,
				        wchar_t      *trade_name,
				        wchar_t      *grade);
/* 
   Purpose:  Sets the default information for the mold layout material dialog.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      generic_type       - The generic type 
      mfg                - The manufacturing
      trade_name         - The trade name 
      grade              - The grade 

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the information for
                           the dialog.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProRmdtDlgCavityLayoutSet ( ProMoldLayout          mold_layout,
					    ProDlgCavityLayoutData *p_dlg_data);
/* 
   Purpose:  Sets the default information for the mold cavity layout dialog.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      p_dlg_data         - The cavity layout dialog data

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProRmdtDlgImmSet ( ProMoldLayout mold_layout,
				   wchar_t      *machine_name);
/* 
   Purpose:  Sets the default information for the mold layout IMM dialog.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      machine_name       - The machine name of the IMM dialog

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProRmdtDlgRefModelOrientSet ( ProMoldLayout mold_layout,
				              ProMatrix     orient);
/* 
   Purpose:  Sets the default information for the dialog for the 
	     reference model orientation of the mold layout. 

   Input Arguments:
      mold_layout        - The handle to the mold layout
      orient             - The orientation matrix 

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProRmdtDlgMoldBaseSet ( ProMoldLayout mold_layout,
				        wchar_t       *vendor,
				        wchar_t       *series,
				        wchar_t       *length,
				        wchar_t       *width);
/* 
   Purpose:  Sets the default information for the mold layout dialog for
	     the mold base.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      vendor             - The vendor 
      series             - The series
      length             - The length
      width              - The width

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


extern ProError ProRmdtDlgWorkpieceSet ( ProMoldLayout          mold_layout,
					 ProDlgWorkpieceData   *p_dlg_data);
/* 
   Purpose:  Sets the default information for the mold layout workpiece dialog.

   Input Arguments:
      mold_layout        - The handle to the mold layout
      p_dlg_data         - The workpiece dialog data

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully set the
                           information.
      PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
*/


typedef ProError (*ProRmdtCreateImmPreAction) (ProMoldLayout mold_layout);

/*
   Purpose: This is the notification function called before creating 
            injection module machining.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the the notify type 
            PRO_RMDT_CREATE_IMM_PRE.

   Input Arguments:
      mold_layout     - The handle to the mold layout

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. IMM creation will
                        be stopped.

   See Also:
      ProNotificationSet()

*/

typedef ProError (*ProRmdtBoundBoxPreAction) (ProMoldLayout mold_layout);

/*
   Purpose: This is the notification function called before the bounding 
	    box dialog.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_RMDT_BOUND_BOX_PRE.

   Input Arguments:
      mold_layout     - The handle to the mold layout

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. The bounding box dialog
                        will not be called.

   See Also:
      ProNotificationSet()
*/

typedef ProError (*ProRmdtCavLayoutPreAction) (ProMoldLayout mold_layout);

/*
   Purpose: This is the notification function called before the cavity 
	    layout dialog.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_RMDT_CAV_LAYOUT_PRE.

   Input Arguments:
      mold_layout     - The handle to the mold layout

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. The cavity layout dialog
                        will not be called.

   See Also:
      ProNotificationSet()

*/


typedef ProError (*ProRmdtCreateWpPreAction) (ProMoldLayout mold_layout);

/*
   Purpose: This is the notification function called before the create 
	    workpiece dialog.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_RMDT_CREATE_WP_PRE.

   Input Arguments:
      mold_layout     - The handle to the mold layout

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. The create workpiece dialog
                        will not be called.

   See Also:
      ProNotificationSet()
*/


typedef ProError (*ProRmdtMaterialPreAction) (ProMoldLayout mold_layout);

/*
   Purpose: This is the notification function called before the material 
	    dialog.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_RMDT_MATERIAL_PRE.

   Input Arguments:
      mold_layout     - The handle to the mold layout

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. The material dialog
                        will not be called.

   See Also:
      ProNotificationSet()
*/


typedef ProError (*ProRmdtMBaseSelectPreAction) (ProMoldLayout mold_layout);

/*
   Purpose: This is the notification function called before the mold base 
	    selection dialog.
<p>
            This function is to be supplied by the user by calling
            <b>ProNotificationSet()</b> with the notify type 
            PRO_RMDT_MBASE_SELECT_PRE.

   Input Arguments:
      mold_layout     - The handle to the mold layout

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR - Successful exit from this function.
      Other           - An error was encountered. The mold base selection
                        dialog will not be called.

   See Also:
      ProNotificationSet()
*/


PRO_END_C_DECLS

#endif

