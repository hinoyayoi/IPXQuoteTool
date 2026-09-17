#ifndef PROMIRRORH
#define PROMIRRORH
 

 
#include <ProToolkit.h>
#include <ProFeature.h>
 
PRO_BEGIN_C_DECLS
 
 
/*****************************************************************************\
 
Feature element tree
 
  PRO_E_FEATURE_TREE
    |
    |--PRO_E_FEATURE_TYPE
    |
    |--PRO_E_SRF_TRANS_TYPE
    |
    |--PRO_E_STD_FEATURE_NAME
    |
    |--PRO_E_MIRROR_REF_ITEMS
    |
    |--PRO_E_MIRROR_REF_PLANE
    |
    |--PRO_E_COPY_NO_COPY


Feature elements table
 
------------------------------------------------------------------------------
Element Id                	Element Name          	Data Type        		
------------------------------------------------------------------------------
PRO_E_FEATURE_TYPE            Feature Type        PRO_VALUE_TYPE_INT

PRO_E_SRF_TRANS_TYPE          Transform Type      PRO_VALUE_TYPE_INT

PRO_E_STD_FEATURE_NAME    	Feature Name  		PRO_VALUE_TYPE_WSTRING

PRO_E_MIRROR_REF_ITEMS		Mirror Items 		PRO_VALUE_TYPE_SELECTION
						        ( Multivalued Element )

PRO_E_MIRROR_REF_PLANE	 	Mirror Plane		PRO_VALUE_TYPE_SELECTION

PRO_E_COPY_NO_COPY		copy no copy		PRO_VALUE_TYPE_INT


------------------------------------------------------------------------------


Table Mirror:1 Common values of elements required for Mirror
-------------------------------------------------------------------------
| Element Id               | Value                                      |
|-----------------------------------------------------------------------|
|                          |                                            |
| PRO_E_FEATURE_TYPE       | = PRO_FEAT_SRF_MDL,if geometry is selected |
|                          | = PRO_FEAT_GEN_MERGE, if part is selected  |
|                          |                                            |
|-----------------------------------------------------------------------|
|                          |                                            |
| PRO_E_SRF_TRANS_TYPE     | = PRO_SURF_TRANS_TYPE_MIRROR                |
|                          |    if geometry is selected                 |
|                          | = PRO_SURF_TRANS_TYPE_PART_MIRROR           |
|                          |    if part is selected                     |
|                          |                                            |
|-----------------------------------------------------------------------|
|                          |                                            |
| PRO_E_MIRROR_REF_ITEMS   | PRO_CURVE, PRO_COMP_CRV, PRO_AXIS,         |
|                          | PRO_QUILT, PRO_DATUM_PLANE, PRO_CSYS,      |
|                          | PRO_POINT, PRO_PART (Refer Note#1)         |
|                          |                                            |
|-----------------------------------------------------------------------|
|                          |                                            |
| PRO_E_MIRROR_REF_PLANE   | PRO_DATUM_PLANE , PRO_SURFACE ( only       |
|                          | plane surfaces allowed )                   |
|                          |                                            |
|-----------------------------------------------------------------------|
|                          |                                            |
| PRO_E_COPY_NO_COPY       | = PRO_MIRROR_KEEP_ORIGINAL                 |
|                          |                                            |
|                          | = PRO_MIRROR_HIDE_ORIGINAL                 |
|                          |                                            |
-------------------------------------------------------------------------


Table Mirror:2 Elements required for Mirror
-------------------------------------------------------------------------
| Element Id                 	| Comment                                 |
-------------------------------------------------------------------------
| PRO_E_FEATURE_TYPE          : Mandatory                               |
-------------------------------------------------------------------------
| PRO_E_SRF_TRANS_TYPE        : Mandatory                               |
-------------------------------------------------------------------------
| PRO_E_STD_FEATURE_NAME      : Optional                                |
-------------------------------------------------------------------------
| PRO_E_MIRROR_REF_ITEMS      : Mandatory                               |
-------------------------------------------------------------------------
| PRO_E_MIRROR_REF_PLANE      : Mandatory                               |
-------------------------------------------------------------------------
| PRO_E_COPY_NO_COPY          : Mandatory                               |
|                             :                                         |
|                             : This element's value will not have any  |
|                             : meaning in the case where part is       |
|                             : selected as reference item for          |
|                             : mirroring.                              |
-------------------------------------------------------------------------



Note 1 : In Pro/ENGINEER Wildfire 2.0, the PRO_E_MIRROR_REF_ITEMS of 
         PRO_FEATURE type are not supported. 

\*****************************************************************************/

typedef enum pro_mirror_copy
{
   PRO_MIRROR_KEEP_ORIGINAL	= 0,
   PRO_MIRROR_HIDE_ORIGINAL	= 1

} ProMirrorCopy;


PRO_END_C_DECLS
 
#endif
