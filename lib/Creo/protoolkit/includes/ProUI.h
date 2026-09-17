#ifndef PROUI_H
#define PROUI_H

#include <ProObjects.h>



/*===========================================================================*/

PRO_BEGIN_C_DECLS

/* Component class types */
#define PRO_UI_CASCADE_BUTTON               "CascadeButton"
#define PRO_UI_CHECK_BUTTON                 "CheckButton"
#define PRO_UI_DIALOG                       "Dialog"
#define PRO_UI_DRAWING_AREA                 "DrawingArea"
#define PRO_UI_INPUT                        "InputPanel"
#define PRO_UI_LABEL                        "Label"
#define PRO_UI_LAYOUT                       "Layout"
#define PRO_UI_LIST                         "List"
#define PRO_UI_MENUBAR                      "MenuBar"
#define PRO_UI_MENUPANE                     "MenuPane"
#define PRO_UI_OPTION_MENU                  "OptionMenu"
#define PRO_UI_PROGRESSBAR                  "ProgressBar"
#define PRO_UI_PUSH_BUTTON                  "PushButton"
#define PRO_UI_RADIO_GROUP                  "RadioGroup"
#define PRO_UI_SEPARATOR                    "Separator"
#define PRO_UI_SLIDER                       "Slider"
#define PRO_UI_SPINBOX                      "SpinBox"
#define PRO_UI_TAB                          "Tab"
#define PRO_UI_TABLE                        "Table"
#define PRO_UI_TEXTAREA                     "TextArea"
#define PRO_UI_THUMBWHEEL                   "ThumbWheel"
#define PRO_UI_TREE                         "Tree"

#define PRO_UI_INSERT_NEW_ROW (-1);
#define PRO_UI_INSERT_NEW_COLUMN (-1);
#define PRO_UI_USE_DEVICE_OFFSET (-1);

typedef struct pro_ui_grid
{
  int row;                /* The row in which to place a component.  Use
			     PRO_UI_INSERT_NEW_ROW to add a new row above any 
			     existing rows. */
  int column;             /* The column in which to place a component.  Use
			     PRO_UI_INSERT_NEW_COLUMN to add a new column
			     to the left of any existing columns. */
  int horz_cells;         /* The number of rows occupied by the component. */
  int vert_cells;         /* The number of columns occupied by the component.*/
  ProBoolean horz_resize; /* Whether or not to resize horizontally */
  ProBoolean vert_resize; /* Whether or not to resize vertically */
  ProBoolean attach_top;  /* Attach the item to the top neighbor */
  ProBoolean attach_bottom; /* Attach the item to the bottom neighbor */
  ProBoolean attach_left;  /* Attach the item to the left neighbor */
  ProBoolean attach_right; /* Attach the item to the right neighbor */
  int top_offset;          /* Offset to the top neighbor */
  int bottom_offset;       /* Offset to the bottom neighbor */
  int left_offset;         /* Offset to the left neighbor */
  int right_offset;        /* Offset to the right neighbor */
} ProUIGridopts;


/* Default macro for initialization of ProUIGridopts fields */
#define PRO_UI_GRIDOPTS_DEFAULT(opts) \
opts.row = PRO_UI_INSERT_NEW_ROW; \
opts.column = PRO_UI_INSERT_NEW_COLUMN; \
opts.horz_cells = 1; \
opts.vert_cells = 1; \
opts.horz_resize = PRO_B_TRUE; \
opts.vert_resize = PRO_B_TRUE; \
opts.attach_top = PRO_B_TRUE; \
opts.attach_bottom = PRO_B_TRUE; \
opts.attach_left = PRO_B_TRUE; \
opts.attach_right = PRO_B_TRUE; \
opts.top_offset = PRO_UI_USE_DEVICE_OFFSET; \
opts.bottom_offset = PRO_UI_USE_DEVICE_OFFSET; \
opts.left_offset = PRO_UI_USE_DEVICE_OFFSET; \
opts.right_offset = PRO_UI_USE_DEVICE_OFFSET;

/* Color support */
typedef int ProUIColor;

typedef enum
{
    PRO_UI_COLOR_BLACK = 0,                 /* 0 */
    PRO_UI_COLOR_DK_RED,                    /* 1 */
    PRO_UI_COLOR_DK_GREEN,                  /* 2 */
    PRO_UI_COLOR_DK_YELLOW,                 /* 3 */
    PRO_UI_COLOR_DK_BLUE,                   /* 4 */
    PRO_UI_COLOR_DK_MAGENTA,                /* 5 */
    PRO_UI_COLOR_DK_CYAN,                   /* 6 */
    PRO_UI_COLOR_LT_GREY,                   /* 7 */
    PRO_UI_COLOR_DK_GREY,                   /* 8 */
    PRO_UI_COLOR_RED,                       /* 9 */
    PRO_UI_COLOR_GREEN,                     /* 10 */
    PRO_UI_COLOR_YELLOW,                    /* 11 */
    PRO_UI_COLOR_BLUE,                      /* 12 */
    PRO_UI_COLOR_MAGENTA,                   /* 13 */
    PRO_UI_COLOR_CYAN,                      /* 14 */
    PRO_UI_COLOR_WHITE,                     /* 15 */

    PRO_UI_COLOR_3D_VERY_LIGHT_SHADOW,      /* 16 */
    PRO_UI_COLOR_3D_LIGHT_SHADOW,           /* 17 */
    PRO_UI_COLOR_3D_DARK_SHADOW,            /* 18 */
    PRO_UI_COLOR_3D_VERY_DARK_SHADOW,       /* 19 */

    PRO_UI_COLOR_WINDOW_BACKGROUND,         /* 20 */
    PRO_UI_COLOR_WINDOW_TEXT,               /* 21 */

    PRO_UI_COLOR_SUNKEN_BACKGROUND,         /* 22 */
    PRO_UI_COLOR_GREY_TEXT,                 /* 23 */

    PRO_UI_COLOR_MENU_BACKGROUND,           /* 24 */
    PRO_UI_COLOR_MENU_TEXT,                 /* 25 */

    PRO_UI_COLOR_SELECTED_BACKGROUND,       /* 26 */
    PRO_UI_COLOR_SELECTED_TEXT,             /* 27 */

    PRO_UI_COLOR_POPUPHELP_BACKGROUND,      /* 28 */
    PRO_UI_COLOR_POPUPHELP_TEXT,            /* 29 */

    PRO_UI_COLOR_ACTIVE_TITLEBAR,           /* 30 */
    PRO_UI_COLOR_ACTIVE_TITLEBAR_TEXT,      /* 31 */
    PRO_UI_COLOR_ACTIVE_WINDOW_BORDER,      /* 32 */

    PRO_UI_COLOR_INACTIVE_TITLEBAR,         /* 33 */
    PRO_UI_COLOR_INACTIVE_TITLEBAR_TEXT,    /* 34 */
    PRO_UI_COLOR_INACTIVE_WINDOW_BORDER,    /* 35 */

    PRO_UI_COLOR_3D_TEXT,                   /* 36 */
    PRO_UI_COLOR_SCROLLBAR_BACKGROUND,      /* 37 */

    PRO_UI_COLOR_GREY_BACKGROUND,           /* 38 */
    PRO_UI_COLOR_2D_VERY_LIGHT_SHADOW,      /* 39 */
    PRO_UI_COLOR_2D_LIGHT_SHADOW,           /* 40 */
    PRO_UI_COLOR_2D_DARK_SHADOW,            /* 41 */
    PRO_UI_COLOR_2D_VERY_DARK_SHADOW,       /* 42 */
    PRO_UI_COLOR_HOVER_TEXT,                /* 43 */
    PRO_UI_COLOR_HOVER_EFFECT,              /* 44 */

    PRO_UI_COLOR_TRANSPARENT = 255

} ProUIColorType;

#define PRO_UI_COLOR_RGB_FLAG               (1 << 24)
#define PRO_UI_COLOR_TRANSPARENT_RGB_FLAG   (1 << 25)

#define PRO_UI_COLOR_RGB(r,g,b)             (((r) & 0xff) | (((g) & 0xff) << 8) | (((b) & 0xff) << 16) | PRO_UI_COLOR_RGB_FLAG)
#define PRO_UI_COLOR_TRANSPARENT_RGB(r,g,b) (PRO_UI_COLOR_RGB (r, g, b) | PRO_UI_COLOR_TRANSPARENT_RGB_FLAG)

#define PRO_UI_COLOR_IS_RGB(c)              ((c) & PRO_UI_COLOR_RGB_FLAG ? PRO_B_TRUE : PRO_B_FALSE)
#define PRO_UI_COLOR_IS_TRANSPARENT_RGB(c)  ((c) & PRO_UI_COLOR_TRANSPARENT_RGB_FLAG ? PRO_B_TRUE : PRO_B_FALSE)

#define PRO_UI_COLOR_RED_VALUE(c)           ((c) & 0xff)
#define PRO_UI_COLOR_GREEN_VALUE(c)         (((c) >> 8) & 0xff)
#define PRO_UI_COLOR_BLUE_VALUE(c)          (((c) >> 16) & 0xff)
#define PRO_UI_COLOR_RGB_FLAGS(c)           (((c) >> 24) & 0xff)


/* Tree Nodetype declaration */

typedef void* ProUITreeNodeType;

typedef enum
{
  PROUI_SET = PRO_B_TRUE,
  PROUI_UNSET = PRO_B_FALSE,
  PROUI_MIXED = 2
} ProUIMixedState;

typedef enum
{
    PROUI_BEFORE = 0,
    PROUI_AFTER  = 1
} ProUIPosition;

typedef enum
{
    PROUIDEFAULT_LOCATION =0,
    PROUITOP_LEFT = 1,
    PROUITOP_MIDDLE = 2,
    PROUITOP_RIGHT  = 3,
    PROUIMIDDLE_LEFT = 4,
    PROUIMIDDLE_MIDDLE = 5,
    PROUIMIDDLE_RIGHT = 6,
    PROUIBOTTOM_LEFT = 7,
    PROUIBOTTOM_MIDDLE = 8,
    PROUIBOTTOM_RIGHT = 9
} ProUIAnchor, ProUIStartLocation;

typedef enum
{
    PROUILISTTYPE_STANDARD	= 0,
    PROUILISTTYPE_TABULATED	= 1,
    PROUILISTTYPE_CHECk		= 2
} ProUIListtype;
 
typedef enum
{
    PROUIMESSAGE_ERROR   = 0,
    PROUIMESSAGE_WARNING = 1,
    PROUIMESSAGE_INFO    = 2,
    PROUIMESSAGE_QUESTION= 3
} ProUIMessageType;

typedef enum
{
    PROUIALIGNMENT_LEFT   = 0,
    PROUIALIGNMENT_RIGHT  = 1,
    PROUIALIGNMENT_CENTER = 2
} ProUIAlignment;

typedef enum
{
    PROUIMESSAGE_ABORT    = (1 << 0),
    PROUIMESSAGE_RETRY    = (1 << 1),
    PROUIMESSAGE_IGNORE   = (1 << 2),
    PROUIMESSAGE_CONFIRM  = (1 << 3),
    PROUIMESSAGE_YES      = (1 << 4),
    PROUIMESSAGE_NO       = (1 << 5),
    PROUIMESSAGE_OK       = (1 << 6),
    PROUIMESSAGE_CANCEL   = (1 << 7)
} ProUIButton;

typedef enum
{
    PROUIINPUTTYPE_STRING   = 0,
    PROUIINPUTTYPE_WSTRING  = 1,
    PROUIINPUTTYPE_INTEGER  = 2,
    PROUIINPUTTYPE_DOUBLE   = 3,
    PROUIINPUTTYPE_FRACTION = 4,
    PROUIINPUTTYPE_RELATION = 5
} ProUIInputtype;

typedef enum
{
    PROUISELPOLICY_NONE     = 0,
    PROUISELPOLICY_SINGLE   = 1,
    PROUISELPOLICY_BROWSE   = 2,
    PROUISELPOLICY_MULTIPLE = 3,
    PROUISELPOLICY_EXTENDED = 4
} ProUISelectionpolicy;

typedef enum
{
    PROUI_LEFT   = 0,
    PROUI_RIGHT  = 1,
    PROUI_CENTER = 2
} ProUIHorzPosition;

typedef enum
{
    PROUI_MIDDLE = 2,
    PROUI_TOP   = 3,
    PROUI_BOTTOM  = 4
} ProUIVertPosition;


typedef enum
{
    PROUIPROGRESS_NOTEXT    = 0,
    PROUIPROGRESS_VALUE     = 1,
    PROUIPROGRESS_PERCENT   = 2,
    PROUIPROGRESS_INTERVALS = 3
} ProUIProgressstyle;

typedef enum
{
    PROUI_HORIZONTAL = 0,
    PROUI_VERTICAL = 1
} ProUIOrientation;

typedef enum
{
    PROUIARCDIR_CLOCKWISE          = 0,
    PROUIARCDIR_COUNTERCLOCKWISE   = 1
} ProUIArcDirection;

typedef enum
{
    PROUIARCFILL_PIE                = 0,
    PROUIARCFILL_CHORD              = 1
} ProUIArcFillMode;

typedef enum
{
    PROUIDRWMODE_COPY               = 0,
    PROUIDRWMODE_NOT                = 1,
    PROUIDRWMODE_AND                = 2,
    PROUIDRWMODE_OR                 = 3,
    PROUIDRWMODE_XOR                = 4
} ProUIDrawingMode;

typedef enum
{
    PROUIFILLMODE_SOLID               = 0,
    PROUIFILLMODE_LIGHT_STIPPLE       = 1,
    PROUIFILLMODE_MEDIUM_STIPPLE      = 2,
    PROUIFILLMODE_HEAVY_STIPPLE       = 3
} ProUIFillMode;

typedef enum
{
    PROUIFONTCLASS_DEFAULT      = 0,
    PROUIFONTCLASS_MENU          = 1,
    PROUIFONTCLASS_POPUPHELP     = 2,
    PROUIFONTCLASS_MESSAGE       = 3,
    PROUIFONTCLASS_TITLEBAR      = 4,
    PROUIFONTCLASS_FIXED         = 5
} ProUIFontClass;

typedef enum
{   
    PROUIFONTSTYLE_REGULAR           = (1 << 0),
    PROUIFONTSTYLE_CONDENSED         = (1 << 1),
    PROUIFONTSTYLE_ITALIC            = (1 << 2),
    PROUIFONTSTYLE_BOLD              = (1 << 3),
    PROUIFONTSTYLE_UNDERLINED        = (1 << 15)
} ProUIFontStyle;

typedef enum
{
    PROUILINESTYLE_SOLID             = 0,
    PROUILINESTYLE_DOTTED            = 1,
    PROUILINESTYLE_DASHED            = 2
} ProUILineStyle;

typedef enum
{
    PROUIPOLYGONFILL_WINDING         = 0,
    PROUIPOLYGONFILL_ALTERNATE       = 1
} ProUIPolygonFillMode;

typedef enum
{
    PROUISHADOWSTYLE_IN           = 0,
    PROUISHADOWSTYLE_OUT          = 1,
    PROUISHADOWSTYLE_BUTTON_IN    = 2,
    PROUISHADOWSTYLE_BUTTON_OUT   = 3,
    PROUISHADOWSTYLE_ETCHED_IN    = 4,
    PROUISHADOWSTYLE_ETCHED_OUT   = 5
} ProUIShadowStyle, ProUIDecoratedStyle;

typedef enum
{
    PROUITREECOL_LEFT  = 1,
    PROUITREECOL_CENTER = 2,
    PROUITREECOL_RIGHT  = 3
} ProUITreeColumnJustification;

typedef enum
{
    PROUIPOSITIONING_UNUSED = -32768,
    PROUIPOSITIONING_ABSOLUTE = 0,
    PROUIPOSITIONING_RELATIVE = 1
} ProUIPositioningMethod;

typedef enum
{
    PROUICASCADEDIR_TOP_LEFT =0,
    PROUICASCADEDIR_TOP_RIGHT =1,
    PROUICASCADEDIR_BOTTOM_LEFT =2,
    PROUICASCADEDIR_BOTTOM_RIGHT =3
} ProUICascadeDirection;

typedef enum
{
    PROUIDIALOGSTYLE_MENU_MODAL = 0,
    PROUIDIALOGSTYLE_MODELESS =1,
    PROUIDIALOGSTYLE_PARENT_MODAL =2,
    PROUIDIALOGSTYLE_APPLICATION_MODAL =3,
    PROUIDIALOGSTYLE_MESSAGE_MODELESS =4,
    PROUIDIALOGSTYLE_MENU_MODELESS =5,
    PROUIDIALOGSTYLE_WORKING =6
}ProUIDialogStyle;

typedef enum
{
  PROUIBUTTONSTYLE_CHECK = 0,
  PROUIBUTTONSTYLE_TOGGLE = 1,
  PROUIBUTTONSTYLE_TOOL = 2,
  PROUIBUTTONSTYLE_FLAT = 3,
  PROUIBUTTONSTYLE_LINK = 4
} ProUIButtonStyle;


typedef struct
{
    int x;
    int y;
    int width;
    int height;

} ProUIRectangle;

typedef struct
{
    int x;
    int y;

} ProUIPoint;

typedef struct
{
    int width;
    int height;

} ProUISize;

typedef struct
{
    ProUIRectangle   rect;
    ProUIPoint  start;
    ProUIPoint  end;

} ProUIArc;


typedef void (*ProUIAction)(
	char* dialog,
	char *component,
	ProAppData appdata);

/*
   Purpose:  Callback function implemented when user takes action in the UI.
 
   Input Arguments:

     	dialog    - UI dialog box name. Creo Parametric will reuse this string for
                    other UI functions. You must make a copy of it before
                    accessing another dialog.

        component - Name of component acted upon. Creo Parametric will reuse
                    this string for other UI functions. You must make a 
                    copy of it before accessing another dialog.

        appdata   - Application data passed to the function that registered
                    the callback function.
 
   Output Arguments:
    
         None 

   Return Values:
         none

*/

extern ProError ProUIBeep( void );

/*
   Purpose: Sounds the system beep.
 
   Input Arguments:
      None
 
   Output Arguments:
      None
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful

   <!-- Objectname: ProUI -->
*/

extern ProError ProUIDesktopsizeGet (ProUIRectangle* size);
/*
   Purpose: Get the size of the desktop.
 
   Input Arguments:
      None
 
   Output Arguments:
      size - Size of the desktop.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR - The function failed.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.


*/

extern ProError ProUIScreensizeGet (ProUIRectangle* size);
/*
   Purpose: Get the size of the window screen.
 
   Input Arguments:
      None
 
   Output Arguments:
      size - Size of the screen.
 
   Return Values:
      PRO_TK_NO_ERROR   - The function was successful
      PRO_TK_GENERAL_ERROR - The function failed.
      PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProUIComponentClassnameGet (char* dialog, char* component, 
					    char** class_name);
/*
  Purpose: Gets the class name (type) for a given component.

  Input Arguments:
      dialog - The dialog name.
      component - The layout name.

  Output Arguments:
      class_name - The component class name. Free this using ProStringFree()

  Return Values:
      PRO_TK_NO_ERROR - The function succeeded.
      PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProUITranslationFilesEnable ( void ); 
/* 
    Purpose: Sets this application to use the newer organization of translated
             UI dialog resource files.  In the default organization, a copy of the
             resource file containing translated labels and messages must be
             provided for each text/[language]/resource directory supported by
             the application. When using the new translation system, the
             resource file is provided only once, in text/resource; a
             text file containing only the translated entities and the
             the translations, in the format used for ProMessageDisplay(),
	     should be provided in text/resource/[language] for each
	     additional language that the application supports.  The 
             translation file should identify the component and attribute for 
             each translated item in line #1, the English text in line #2, and
	     the translation in line #3, and line #4 left blank.
             <p>
             This function should be called before any call is made to another
             ProUI function; usually it should be called early in the 
             application's user_initialize(). 
             <p>
	     For an example of an application using this approach to dialog
	     translation, see the pt_install_test directory in the loadpoint.

    Input Arguments: 
        none 

    Output Arguments: 
        none 

    Return Values: 
        PRO_TK_NO_ERROR - The function succeeded. 
        PRO_TK_GENERAL_ERROR - Unable to make the switch to the new translation 
                               system. 
*/

extern ProError ProUIColorSelectionShow (
	const wchar_t*	title,
	ProUIColor	default_rgb_color,
	ProUIColor*	selected_rgb_color
);
/*
    Purpose: Show the standard rgb color selection dialog.
	
    Input Arguments:
	title - The title of the selection dialog. If NULL, a default will be used.
	default_rgb_color - The default selection, upon dialog display.
		
    Output Arguments:
	selected_rgb_color - The color that the user selected in the dialog.
		
    Return Values:
	PRO_TK_NO_ERROR - A color was selected by the user.
	PRO_TK_BAD_INPUTS - The selected_rgb_color parameter is NULL.
	PRO_TK_INCOMPLETE - No color selection was made.
*/

PRO_END_C_DECLS
 
#endif  /* PROUI_H */
