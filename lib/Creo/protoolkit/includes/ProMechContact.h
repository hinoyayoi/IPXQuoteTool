#ifndef PROMECHCONTACT_H
#define PROMECHCONTACT_H


#include <ProToolkit.h>
#include <ProObjects.h>
#include <ProMechValue.h>
#include <ProMechYDirection.h>

PRO_BEGIN_C_DECLS

typedef enum
{
  PRO_MECH_CONTACT_DISTR_TOTAL    = 0,
  PRO_MECH_CONTACT_DISTR_PER_UNIT = 1 
}
ProMechContactDistrType;

extern ProError ProMechcontactReferencesGet (ProMechItem* item, ProMechGeomref** references);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechgapReferencesGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechgapReferencesGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications.
             <P>Obtains the references used by this contact. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The Gap or Interface.

    Output Arguments:
        references - ProArray of references. Free this array using 
                     ProMechgeomrefProarrayFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR  -  The Input ProMechItem Solid pointer is invalid.
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.

*/

extern ProError ProMechcontactYdirectionGet (ProMechItem* item, ProMechYDirection* y_dir);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechgapSimpledataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechgapSimpledataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications.
             <P>Obtains the Orientation for the contact item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The contact item.

    Output Arguments:
        y_dir - The Orientation. Free this output using 
                ProMechydirectionFree().

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid .
        PRO_TK_OUT_OF_MEMORY - There is not enough memory to perform the operation.
*/

extern ProError ProMechcontactDistributiontypeGet (ProMechItem* item, ProMechContactDistrType* type);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechgapSimpledataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechgapSimpledataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications.
             <P>Obtains the distribution type for the contact item.
             

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The contact item.

    Output Arguments:
        type - The distribution type.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
*/

extern ProError ProMechcontactClearanceGet (ProMechItem* item, ProMechExpression clearance);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechgapSimpledataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechgapSimpledataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications.
             <P>Obtains the clearance for the contact item. 

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The contact item.

    Output Arguments:
        clearance - The clearance.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        RO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontactAxialstiffnessGet (ProMechItem* item, ProMechExpression axial_stiff);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechgapSimpledataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechgapSimpledataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications.
             <P>Obtains the axial stiffness for the contact item.

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The contact item.

    Output Arguments:
        axial_stiff - The axial stiffness.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

extern ProError ProMechcontactTransversestiffnessGet (ProMechItem* item, ProMechExpression transv_stiff);
/*
	DEPRECATED: Since Wildfire 4.0
    SUCCESSORS: ProMechgapSimpledataGet
    Purpose: <B>Note:</B> From release Wildfire 4.0 this function is superseded 
             by ProMechgapSimpledataGet(). PTC recommends using the new 
             function in place of this function in all new or updated user 
             applications. 
             <P>Obtains the transverse stiffness.  

    Licensing Requirement:
          TOOLKIT for Mechanica

    Input Arguments:
        item - The contact item.

    Output Arguments:
        transv_stiff - The transverse stiffness.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments are invalid.
        PRO_TK_BAD_CONTEXT - The Creo Simulate session is not initialized.
        PRO_TK_INVALID_PTR - The Input ProMechItem Solid pointer is invalid.
        PRO_TK_GENERAL_ERROR - A general error is encountered.
*/

PRO_END_C_DECLS

#endif /* PROMECHCONTACT_H */
