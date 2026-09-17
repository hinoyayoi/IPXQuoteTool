#ifndef PROMECHBEAMSECTION_H
#define PROMECHBEAMSECTION_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechItem.h>
#include <ProMechValue.h>
#include <ProMechVector.h>
#include <ProMechMatrix.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_BEAMSECTION_SKETCHED_FEATURE_ID       = 0,  /* int */
  PRO_MECH_BEAMSECTION_SKETCHED_SHEARCENTER      = 1,  /* ProMechVector (2) [Dy, Dz] */
  PRO_MECH_BEAMSECTION_SKETCHED_ORIENTTYPE       = 2,  /* ProMechSketchedSectionOrient (int) */

  PRO_MECH_BEAMSECTION_SQUARE_DIMENSION          = 3,  /* ProMechExpression [a] */

  PRO_MECH_BEAMSECTION_RECTANGLE_DIMENSION       = 4,  /* ProMechVector (2) [b, d] */

  PRO_MECH_BEAMSECTION_HOLLOWRECTANGLE_DIMENSION = 5,  /* ProMechVector (4) [b, d, bi, di] */

  PRO_MECH_BEAMSECTION_CHANNEL_DIMENSION         = 6,  /* ProMechVector (4) [b, t, di, tw] */
  PRO_MECH_BEAMSECTION_CHANNEL_SHEARFACTOR       = 7,  /* ProMechVector (2) [Fy, Fz] */

  PRO_MECH_BEAMSECTION_IBEAM_DIMENSION           = 8,  /* ProMechVector (4) [b, t, di, tw] */

  PRO_MECH_BEAMSECTION_LSECTION_DIMENSION        = 9,  /* ProMechVector (4) [b, t, di, tw] */
  PRO_MECH_BEAMSECTION_LSECTION_SHEARFACTOR      = 10, /* ProMechVector (2) [Fy, Fz] */

  PRO_MECH_BEAMSECTION_DIAMOND_DIMENSION         = 11, /* ProMechVector (2) [b, d] */

  PRO_MECH_BEAMSECTION_SOLIDCIRCLE_DIMENSION     = 12, /* ProMechExpression [R] */

  PRO_MECH_BEAMSECTION_HOLLOWCIRCLE_DIMENSION    = 13, /* ProMechVector (2) [R, Ri] */

  PRO_MECH_BEAMSECTION_SOLIDELLIPSE_DIMENSION    = 14, /* ProMechVector (2) [a, b]*/

  PRO_MECH_BEAMSECTION_HOLLOWELLIPSE_DIMENSION   = 15, /* ProMechVector (3) [a, b, ai] */
  PRO_MECH_BEAMSECTION_HOLLOWELLIPSE_SHEARFACTOR = 16, /* ProMechVector (2) [Fy, Fz] */

  PRO_MECH_BEAMSECTION_GENERAL_AREA              = 17, /* ProMechExpression [Area] */
  PRO_MECH_BEAMSECTION_GENERAL_INERTIA           = 18, /* ProMechMatrix (2x2, symmetrical)
                                                          [ Ixx  Ixy ]
                                                          [      Iyy ]
                                                       */
  PRO_MECH_BEAMSECTION_GENERAL_TORSIONSTIFFNESS  = 19, /* ProMechExpression [j] */
  PRO_MECH_BEAMSECTION_GENERAL_SHEARFACTOR       = 20, /* ProMechVector (2) [Fy, Fz] */
  PRO_MECH_BEAMSECTION_GENERAL_SHEARCENTER       = 21, /* ProMechVector (2) [Dy, Dz] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_1           = 22, /* ProMechVector (2) [y1, z1] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_2           = 23, /* ProMechVector (2) [y2, z2] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_3           = 24, /* ProMechVector (2) [y3, z3] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_4           = 25, /* ProMechVector (2) [y4, z4] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_5           = 26, /* ProMechVector (2) [y5, z5] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_6           = 27, /* ProMechVector (2) [y6, z6] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_7           = 28, /* ProMechVector (2) [y7, z7] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_8           = 29, /* ProMechVector (2) [y8, z8] */
  PRO_MECH_BEAMSECTION_GENERAL_POINT_9           = 30, /* ProMechVector (2) [y9, z9] */

  PRO_MECH_BEAMSECTION_WARPCOEFFICIENT           = 31, /* ProMechExpression [Warp Coefficient] */
  PRO_MECH_BEAMSECTION_NONSTRUCTMASS             = 32, /* ProMechExpression [Non-Str Mass] */
  PRO_MECH_BEAMSECTION_NONSTRUCTMASSMOMENT       = 33, /* ProMechExpression [Non-Str Mass Moment] */
  PRO_MECH_BEAMSECTION_CENTERGRAVITY             = 34  /* ProMechVector (2) [cg:y, cg:z] */
}
ProMechBeamsectionPropertyType;

typedef struct pro_mech_beam_section_data* ProMechSectionData;

typedef enum
{
  PRO_MECH_BEAM_SECTION_SKETCHED         = 1,
  PRO_MECH_BEAM_SECTION_SQUARE           = 2,
  PRO_MECH_BEAM_SECTION_RECTANGLE        = 3,
  PRO_MECH_BEAM_SECTION_HOLLOW_RECTANGLE = 4,
  PRO_MECH_BEAM_SECTION_CHANNEL          = 5,
  PRO_MECH_BEAM_SECTION_I_BEAM           = 6,
  PRO_MECH_BEAM_SECTION_L_SECTION        = 7,
  PRO_MECH_BEAM_SECTION_DIAMOND          = 8,
  PRO_MECH_BEAM_SECTION_SOLID_CIRCLE     = 9,
  PRO_MECH_BEAM_SECTION_HOLLOW_CIRCLE    = 10,
  PRO_MECH_BEAM_SECTION_SOLID_ELLIPSE    = 11,
  PRO_MECH_BEAM_SECTION_HOLLOW_ELLIPSE   = 12,
  PRO_MECH_BEAM_SECTION_GENERAL          = 13
}
ProMechBeamSectionType;

typedef enum
{
  PRO_MECH_BEAM_SECTION_SKET_NONE      = PRO_VALUE_UNUSED,

  PRO_MECH_BEAM_SECTION_SKET_XY_AS_YZ  = 0,  /* old FEM convention */
  PRO_MECH_BEAM_SECTION_SKET_XY_AS_ZY  = 1
}
ProMechSketchedSectionOrient;

typedef struct pro_mech_sketched_section_data* ProMechSketchedSectionData; /* deprecated */

typedef double ProMechBeamSectShearFactor [2]; /* deprecated */
typedef double ProMechBeamSectShearCenter [2]; /* deprecated */
typedef double ProMechSectionMoments [2]; /* deprecated */

typedef struct 
{
  double   a;
} ProMechSquareSectionData; /* deprecated */

typedef struct 
{
  double   b;
  double   d;
} ProMechRectangleSectionData; /* deprecated */

typedef struct
{
  double   b;
  double   d;
  double   bi;
  double   di;
} ProMechHollowRectangleSectionData;  /* deprecated */

typedef struct 
{
  double   b;
  double   t;
  double   tw;
  double   di;

  ProMechBeamSectShearFactor   shear_factor;
} ProMechChannelSectionData;  /* deprecated */

typedef struct
{
  double   b;
  double   t;
  double   tw;
  double   di;
} ProMechIBeamSectionData; /* deprecated */

typedef struct
{
  double   b;
  double   t;
  double   tw;
  double   di;

  ProMechBeamSectShearFactor   shear_factor;
} ProMechLSectionData; /* deprecated */

typedef struct
{
  double   b;
  double   d;
} ProMechDiamondSectionData; /* deprecated */

typedef struct 
{
  double   r;
} ProMechCircleSectionData; /* deprecated */

typedef struct
{
  double   r;
  double   ri;
} ProMechHollowCircleSectionData; /* deprecated */

typedef struct
{
  double   a;
  double   b;
} ProMechEllipseSectionData; /* deprecated */

typedef struct
{
  double   a;
  double   b;
  double   ai;

  ProMechBeamSectShearFactor   shear_factor;
} ProMechHollowEllipseSectionData; /* deprecated */

typedef struct pro_mech_general_section_data* ProMechGeneralSectionData; /* deprecated */


extern ProError  ProMechbeamsectionDescriptionGet (ProMechItem* b_section,
                                ProComment description);
/*
        Purpose: Obtains the beam section description.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                b_section       - The beam section.

        Output Arguments:
                description     - The description.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechbeamsectionDataGet (ProMechItem* b_section,
                                ProMechSectionData* data);
/*
        Purpose: Obtains the beam section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            b_section       - The beam section.

        Output Arguments:
            data    - The data.  Free this using ProMechsectiondataFree().

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
            PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
            PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError  ProMechsectiondataSectiontypeGet (ProMechSectionData data,
                                ProMechBeamSectionType* sk_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionTypeGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionTypeGet() to get the type of
                 the beam section.
                 <p>
                 Obtains the type of section stored in this section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                sk_sect_data    - The section type.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsectiondataWarpcoeffGet (ProMechSectionData data,
                                double * warp_coeff);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the
                 warp coefficient of the beam section.
                 <p>
                 Obtains the beam section warp coefficient.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                warp_coeff      - The warp coefficient.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechsectiondataNonstructmassGet (ProMechSectionData data,
                                double * nsm);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the non-structural mass 
                 per unit length of the beam section.
                 <p>
                 Obtains the non-structural mass  per unit length of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                nsm     - The non-structural mass moment per unit length.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechsectiondataNonstructmomentGet (ProMechSectionData data,
                                double * nsm_mom);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the non-structural mass
                 moment per unit length of the beam section.
                 <p>
                 Obtains the non-structural mass moment per unit length of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                nsm_mom - The non-structural mass per unit length.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechsectiondataNonstructcogGet (ProMechSectionData data,
                                Pro2dPnt nsm_cog);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the non-struct mass
                 center of gravity of the beam section.
                 <p>
                 Obtains the non-struct mass center of gravity.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                nsm_cog - The non-struct mass center of gravity.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechsectiondataFree (ProMechSectionData data);
/*
        Purpose: Frees the memory for a Creo Simulate section data handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data    - The handle.

        Output Arguments:
            none

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsectiondataSketchedsectdataGet (ProMechSectionData data,
                                ProMechSketchedSectionData* sk_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionPropertyType
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionPropertyType to get the corresponding
                 property of the sketched beam section.
                 <p>
                 Obtains the sketched section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                sk_sect_data    - The sketched section data.  Free this using
                                                ProMechsketchedsctndataFree().

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

        See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsketchedsctndataFeatureidGet (ProMechSketchedSectionData data,
                                int* feature_id);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionIntegerGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionIntegerGet() to get the id of the sketch
                 feature used by the sketched beam section.
                 <p>
                 Obtains the beam sketch feature used by the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The sketched section data handle.

        Output Arguments:
                feature_id      - The sketch feature id.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsketchedsctndataShearcenterGet (ProMechSketchedSectionData data,
                                ProMechBeamSectShearCenter shear_center);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the shear center of
                 the sketched beam section.
                 <p>
                 Obtains the shear center of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The sketched section data handle.

        Output Arguments:
                shear_center    - The shear center.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechsketchedsctndataOrienttypeGet (ProMechSketchedSectionData data,
                                ProMechSketchedSectionOrient* type);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionIntegerGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionIntegerGet() to get the type of orientation
                 of the sketched beam section.
                 <p>
                 Obtains the type of orientation used for this sketched beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The sketched section data handle.

        Output Arguments:
                type    - The orienation.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsketchedsctndataFree (ProMechSketchedSectionData data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: CONTEXTUAL
        Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Frees the memory for a Creo Simulate sketched section data handle.

        Input Arguments:
                data    - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsectiondataSquaresectdataGet (ProMechSectionData data,
                                ProMechSquareSectionData * sq_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the sqaure data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                sq_sect_data    - The square section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataRectanglesectdataGet (ProMechSectionData data,
                                ProMechRectangleSectionData * rect_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the rectangle data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                rect_sect_data  - The rectangular section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/


extern ProError  ProMechsectiondataChannelsectdataGet (ProMechSectionData data,
                                ProMechChannelSectionData * chan_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the channel data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                chan_sect_data  - The channel section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataIbeamsectdataGet (ProMechSectionData data,
                                ProMechIBeamSectionData * ibeam_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the I beam data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                ibeam_sect_data - The I beam section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataLsectionsectdataGet (ProMechSectionData data,
                                ProMechLSectionData * l_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the L section data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                l_sect_data     - The L-section section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataDiamondsectdataGet (ProMechSectionData data,
                                ProMechDiamondSectionData * diam_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the diamond data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                diam_sect_data  - The diamond section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataCirclesectdataGet (ProMechSectionData data,
                                ProMechCircleSectionData * circ_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the circle data
                 of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                circ_sect_data  - The circular section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataHollowcirclesectdataGet (ProMechSectionData data,
                                ProMechHollowCircleSectionData * hc_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the hollow circle
                 data of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                hc_sect_data    - The hollow circle section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataEllipsesectdataGet (ProMechSectionData data,
                                ProMechEllipseSectionData * ell_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the hollow circle
                 data of the beam section.
                 <p>
                 Obtains the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                ell_sect_data   - The elliptical section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechsectiondataGeneralsectdataGet (ProMechSectionData data,
                                ProMechGeneralSectionData* gen_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionPropertyType
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionPropertyType to get the corresponding
                 property of the beam section.
                 <p>
                 Obtains the general section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                gen_sect_data   - The general section data.  Free this using 
                                  ProMechgeneralsctndataFree().

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/

extern ProError  ProMechgeneralsctndataAreaGet (ProMechGeneralSectionData data,
                                double* area);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the area of the
                 general beam section.
                 <p>
                 Obtains the section area.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                area    - The area.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechgeneralsctndataMomentsGet (ProMechGeneralSectionData data,
                                ProMechSectionMoments moments);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionMatrixGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionMatrixGet() to get the Iyy, Iyz and Izz
                 of the general beam section.
                 <p>
                 Obtains the moments of intertia (Iyy, Izz)

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                moments - The moments of inertia.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechgeneralsctndataAreaproductGet (ProMechGeneralSectionData data,
                                double* area_product);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionMatrixGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionMatrixGet() to get the Iyy, Iyz and Izz
                 of the general beam section.
                 <p>
                 Obtains the area product of intertia (Iyz)

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                area_product    - The area product.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.

*/

extern ProError  ProMechgeneralsctndataTorsionstiffnessGet (ProMechGeneralSectionData data,
                                double* torsion_stiffness);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionGet() to get the torsion
                 stiffness (J parameter) of the general beam section.
                 <p>
                 Obtains the torsion stiffness (J parameter) of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                torsion_stiffness       - The torsion stiffness.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechgeneralsctndataShearfactorGet (ProMechGeneralSectionData data,
                                ProMechBeamSectShearFactor shear_factor);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the shear factors of
                 the general beam section.
                 <p>
                 Obtains the shear factors of beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                shear_factor    - The shear factors.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechgeneralsctndataShearcenterGet (ProMechGeneralSectionData data,
                                ProMechBeamSectShearCenter shear_center);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the shear center
                 of the general beam section.
                 <p>
                 Obtains the shear center of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                shear_center    - The shear center.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
*/

extern ProError  ProMechgeneralsctndataFree (ProMechGeneralSectionData data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: CONTEXTUAL
        Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Frees the memory for a Creo Simulate general section data handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The handle.

        Output Arguments:
                none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError  ProMechsectiondataHollowrectsectdataGet (ProMechSectionData data,
                                ProMechHollowRectangleSectionData * hr_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the
                 hollow rectangular data of the beam section.
                 <p>
                 Obtains the hollow rectangular section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                hr_sect_data    - The hollow rectangular section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/
extern ProError  ProMechsectiondataHollowellipsesectdataGet (ProMechSectionData data,
                                ProMechHollowEllipseSectionData * he_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the hollow elliptical
                 data of the beam section.
                 <p>
                 Obtains the hollow  elliptical section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The section data.

        Output Arguments:
                he_sect_data    - The hollow elliptical section data.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_TYPE - The section does not contain this type of section shape data.

    See Also:
                ProMechsectiondataSectiontypeGet()
*/
extern ProError  ProMechgeneralsctndataStressrecoverypntsGet (ProMechGeneralSectionData data,
                                Pro2dPnt** recovery_points);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorGet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorGet() to get the stress recovery
                 point data of the general beam section.
                 <p>
                 Obtains the stress recovery points of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
                data    - The general section data handle.

        Output Arguments:
                recovery_points - ProArray of stress recovery points.

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_E_NOT_FOUND - This parameter is not defined for this beam section.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
*/


extern ProError ProMechbeamsectionDescriptionSet (ProMechItem* b_section, ProComment description);
/*
        Purpose: Sets the beam section description.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            b_section - The beam section.
            description - The description.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
                PRO_TK_GENERAL_ERROR - A general error is encountered.
                PRO_TK_CANT_MODIFY - Cannot modify the item.
                PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechbeamsectionDataSet (ProMechItem* b_section, ProMechSectionData data);
/*
        Purpose: Sets the beam section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            b_section - The beam section.
            data - The data.

        Output Arguments:
            none

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_INVALID_PTR  - The Input ProMechItem Solid pointer is invalid.
            PRO_TK_GENERAL_ERROR - A general error is encountered.
            PRO_TK_CANT_MODIFY - Cannot modify the item.
            PRO_TK_CANT_ACCESS - Cannot access the object in the current mode.
*/

extern ProError ProMechsectiondataWarpcoeffSet (ProMechSectionData data, double warp_coeff);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the
                 warp coefficient of the beam section.
                 <p>
                 Sets the beam section warp coefficient.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            warp_coeff - The warp coefficient.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataNonstructmassSet (ProMechSectionData data, double nsm);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the
                 non-structural mass per unit length of the beam section.
                 <p>
                 Sets the non-structural mass  per unit length of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            nsm - The nonstructural mass moment per unit length.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataNonstructmomentSet (ProMechSectionData data, double nsm_mom);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the
                 non-structural mass moment per unit length of the beam section.
                 <p>
                 Sets the non-structural mass moment per unit length of the beam 
                 section.
    
        Licensing Requirement:
          TOOLKIT for Mechanica
    
        Input Arguments:
            data - The section data.
            nsm_mom - The nonstructural mass per unit length.
    
        Output Arguments:
            none
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataNonstructcogSet (ProMechSectionData data, Pro2dPnt nsm_cog);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the non-structural
                 mass center of gravity of the beam section.
                 <p>
                 Sets the non-struct mass center of gravity.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            nsm_cog - The nonstruct mass center of gravity.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataAlloc (ProMechSectionData* data);
/*
        Purpose: Allocates the memory for a Creo Simulate section data handle.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            none
    
        Output Arguments:
            data - The handle.
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechsectiondataSketchedsectdataSet (ProMechSectionData data, ProMechSketchedSectionData sk_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionPropertyType
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionPropertyType to set the corresponding
                 property of the beam section.
                 <p>
                 Sets the sketched section data.

        Licensing Requirement:
          TOOLKIT for Mechanica
        Input Arguments:
            data - The section data.
            sk_sect_data - The sketched section data.  Alloc this using 
                           ProMechsketchedsctndataAlloc().

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.

*/

extern ProError ProMechsketchedsctndataShearcenterSet (ProMechSketchedSectionData data, ProMechBeamSectShearCenter shear_center);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the shear center
                 of the sketched beam section.
                 <p>
                 Sets the shear center of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The sketched section data handle.
            shear_center - The shear center.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsketchedsctndataOrienttypeSet (ProMechSketchedSectionData data, ProMechSketchedSectionOrient type);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionIntegerSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionIntegerSet() to set the type of
                 orientation of the sketched beam section.
                 <p>
                 Sets the type of orientation used for this sketched beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The sketched section data handle.
            type - The orienation.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsketchedsctndataAlloc (ProMechSketchedSectionData* data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: CONTEXTUAL
        Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Allocates the memory for a Creo Simulate sketched section data 
                 handle.
    
        Licensing Requirement:
          TOOLKIT for Mechanica
    
        Input Arguments:
            data - The handle.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechsectiondataSquaresectdataSet (ProMechSectionData data, ProMechSquareSectionData *sq_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the
                 square data of the beam section.
                 <p>
                 Sets the square section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            sq_sect_data - The square section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataRectanglesectdataSet (ProMechSectionData data, ProMechRectangleSectionData *rect_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the
                 rectangular data of the beam section.
                 <p>
                 Sets the rectangular section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            rect_sect_data - The rectangular section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataChannelsectdataSet (ProMechSectionData data, ProMechChannelSectionData *chan_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the channel data
                 of the beam section.
                 <p>
                 Sets the channel section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            chan_sect_data - The channel section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataIbeamsectdataSet (ProMechSectionData data, ProMechIBeamSectionData *ibeam_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the I beam data
                 of the beam section.
                 <p>
                 Sets the I beam section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            ibeam_sect_data - The I beam section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataLsectionsectdataSet (ProMechSectionData data, ProMechLSectionData *l_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the L section data
                 of the beam section.
                 <p>
                 Sets the L section section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            l_sect_data - The Lsection section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataDiamondsectdataSet (ProMechSectionData data, ProMechDiamondSectionData *diam_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the diamond data
                 of the beam section.
                 <p>
                 Sets the diamond section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            diam_sect_data - The diamond section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataCirclesectdataSet (ProMechSectionData data, ProMechCircleSectionData *circ_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the
                 solid circle data of the beam section.
                 <p>
                 Sets the circular section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            circ_sect_data - The circular section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataHollowcirclesectdataSet (ProMechSectionData data, ProMechHollowCircleSectionData *hc_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the hollow circle
                 data of the beam section.
                 <p>
                 Sets the hollow circle section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            hc_sect_data - The hollow circle section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataEllipsesectdataSet (ProMechSectionData data, ProMechEllipseSectionData *ell_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the elliptical data
                 of the beam section.
                 <p>
                 Sets the elliptical section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            ell_sect_data - The elliptical section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataGeneralsectdataSet (ProMechSectionData data, ProMechGeneralSectionData gen_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionPropertyType
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionPropertyType to set the corresponding
                 property of the beam section.
                 <p>
                 Sets the general section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            gen_sect_data - The general section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataAreaSet (ProMechGeneralSectionData data, double area);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the 
                 area of the general beam section.
                 <p>
                 Sets the section area.
 
        Licensing Requirement:
          TOOLKIT for Mechanica
 
        Input Arguments:
            data - The general section data handle.
            area - The area.
 
        Output Arguments:
            none
 
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataMomentsSet (ProMechGeneralSectionData data, ProMechSectionMoments moments);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionMatrixSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionMatrixSet() to set the moments of
                 inertia, Ixx, Ixy and Iyz of the general beam section.
                 <p>
                 Sets the moments of intertia (Iyy, Izz)

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The general section data handle.
            moments - The moments of inertia.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataAreaproductSet (ProMechGeneralSectionData data, double area_product);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionMatrixSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionMatrixSet() to set the moments of
                 inertia, Ixx, Ixy and Iyz of the general beam section.
                 <p>
                 Sets the area product of intertia (Iyz)

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The general section data handle.
            area_product - The area product.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataTorsionstiffnessSet (ProMechGeneralSectionData data, double torsion_stiffness);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionExpressionSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionExpressionSet() to set the
                 torsion stiffnes (J parameter) of the beam section.
                 <p>
                 Sets the torsion stiffness (J parameter) of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The general section data handle.
            torsion_stiffness - The torsion stiffness.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataShearfactorSet (ProMechGeneralSectionData data, ProMechBeamSectShearFactor shear_factor);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the
                 shear factor of the general beam section.
                 <p>
                 Sets the shear factors of beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The general section data handle.
            shear_factor - The shear factors.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataShearcenterSet (ProMechGeneralSectionData data, ProMechBeamSectShearCenter shear_center);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the 
                 shear center of the general beam section.
                 <p>
                 Sets the shear center of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The general section data handle.
            shear_center - The shear center.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechgeneralsctndataStressrecoverypntsSet (ProMechGeneralSectionData data, Pro2dPnt *recovery_points);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the 
                 recovery points of the general beam section.
                 <p>
                 Sets the stress recovery points of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The general section data handle.
            recovery_points - ProArray of stress recovery points.
                              Size of ProArray must be 9. 
    
        Output Arguments:
            none
    
        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/
extern ProError ProMechgeneralsctndataAlloc (ProMechGeneralSectionData* data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: CONTEXTUAL
        Purpose: <B>Note</B>: This function is deprecated.
                 <p>
                 Allocates the memory for a Creo Simulate general section data 
                 handle.
    
        Licensing Requirement:
          TOOLKIT for Mechanica
    
        Input Arguments:
            data - The handle.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
                PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechsectiondataHollowrectsectdataSet (ProMechSectionData data, ProMechHollowRectangleSectionData *hr_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the
                 hollow rectangular data of the beam section.
                 <p>
                 Sets the hollow rectangular section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            hr_sect_data - The hollow rectangular section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechsectiondataHollowellipsesectdataSet (ProMechSectionData data, ProMechHollowEllipseSectionData *he_sect_data);
/*
		DEPRECATED: Since Creo 1
        SUCCESSORS: ProMechBeamsectionVectorSet
        Purpose: <B>Note</B>: This function is deprecated.
                 Use ProMechBeamsectionVectorSet() to set the
                 hollow elliptical data of the beam section.
                 <p>
                 Sets the hollow  elliptical section data from the section data.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The section data.
            he_sect_data - The hollow elliptical section data.

        Output Arguments:
            none

        Return Values:
                PRO_TK_NO_ERROR - The function succeeded.
                PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
                PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionTypeSet (ProMechSectionData     data,
                                           ProMechBeamSectionType type);
/*
        Purpose: Sets the section type for the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The section type.

        Output Arguments:
            none.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionTypeGet (ProMechSectionData       data,
                                           ProMechBeamSectionType * type);
/*
        Purpose: Obtains the section type of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.

        Output Arguments:
            type - The section type.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionIntegerSet (
                                          ProMechSectionData             data,
                                          ProMechBeamsectionPropertyType type,
                                          int                            value);
/*
        Purpose: Sets the integer value corresponding to 'type' of
                 the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.
            value - The property value.

        Output Arguments:
            none.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionIntegerGet (
                                       ProMechSectionData              data,
                                       ProMechBeamsectionPropertyType  type,
                                       int                            *value);
/*
        Purpose: Obtains the integer value corresponding to 'type' of
                 the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam sectiona data.
            type - The property type.

        Output Arguments:
            value - The property value.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionExpressionSet (
                                          ProMechSectionData             data,
                                          ProMechBeamsectionPropertyType type,
                                          ProMechExpression              expr);
/*
        Purpose: Sets the expression corresponding to 'type' of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.
            expr - The property value.

        Output Arguments:
            none.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_NO_LICENSE - No license was available to enable this function.
            PRO_TK_GENERAL_ERROR - A general error is encountered.
            PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
*/

extern ProError ProMechBeamsectionExpressionGet (
                                          ProMechSectionData             data,
                                          ProMechBeamsectionPropertyType type,
                                          ProMechExpression              expr);
/*
        Purpose: Obtains the expression corresponding to 'type' of the beam section.
                 Use ProMathExpressionEvaluate() to evaluate the expression.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.

        Output Arguments:
            expr - The property value.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_NO_LICENSE - No license was available to enable this function.
            PRO_TK_GENERAL_ERROR - A general error is encountered.
            PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
            PRO_TK_E_NOT_FOUND - This property type is not defined for this beam section.
*/

extern ProError ProMechBeamsectionVectorSet (
                                         ProMechSectionData             data,
                                         ProMechBeamsectionPropertyType type,
                                         ProMechVector                  vector);
/*
        Purpose: Sets the vector corresponding to 'type' of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.
            vector - The property value.

        Output Arguments:
            none.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionVectorGet (
                                         ProMechSectionData              data,
                                         ProMechBeamsectionPropertyType  type,
                                         ProMechVector                  *vector);
/*
        Purpose: Obtains the vector corresponding to 'type' of the beam section.
                 Use ProMathExpressionEvaluate() to evaluate each component.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.

        Output Arguments:
            vector - The property value.
                     The function allocates memory for this argument.
                     Use ProMechVectorFree() to free it.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_NO_LICENSE - No license was available to enable this function.
            PRO_TK_GENERAL_ERROR - A general error is encountered.
            PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
            PRO_TK_E_NOT_FOUND - This property type is not defined for this beam section.
*/

extern ProError ProMechBeamsectionMatrixSet (
                                         ProMechSectionData             data,
                                         ProMechBeamsectionPropertyType type,
                                         ProMechMatrix                  matrix);
/*
        Purpose: Sets the matrix corresponding to 'type' of the beam section.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.
            matrix - The property value.

        Output Arguments:
            none.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
*/

extern ProError ProMechBeamsectionMatrixGet (
                                          ProMechSectionData              data,
                                          ProMechBeamsectionPropertyType  type,
                                          ProMechMatrix                  *matrix);
/*
        Purpose: Obtains the matrix corresponding to 'type' of the beam section.
                 Use ProMathExpressionEvaluate() to evaluate each component.

        Licensing Requirement:
          TOOLKIT for Mechanica

        Input Arguments:
            data - The beam section data.
            type - The property type.

        Output Arguments:
            matrix - The property value.
                     The function allocates memory for this argument.
                     Use ProMechMatrixFree() to free it.

        Return Values:
            PRO_TK_NO_ERROR - The function succeeded.
            PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
            PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
            PRO_TK_NO_LICENSE - No license was available to enable this function.
            PRO_TK_GENERAL_ERROR - A general error is encountered.
            PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
            PRO_TK_E_NOT_FOUND - This property type is not defined for this beam section.
*/

PRO_END_C_DECLS

#endif /* PROMECHBEAMSECTION_H */
