#ifndef PROELEMENT_H
#define PROELEMENT_H

#include <ProObjects.h>
#include <ProValue.h>
#include <ProArray.h>
#include <ProElempath.h>
#include <ProElemId.h>
#include <ProReference.h>
#include <ProCollect.h>
#include <ProElemoptions.h>




PRO_BEGIN_C_DECLS

typedef               struct Pro_Elem  *ProElement;

#define PRO_ELEMTREE_MAX_LEVEL 256
 
#define PRO_ELEM_INDEX_PACK(index)  (-((index) + 1))
#define PRO_ELEM_INDEX_UNPACK(proelemindex)  (-(proelemindex) - 1)
 

/*---------------------- FUNCTIONS ---------------------------*/


/* Constructor -- following C++ convention, see ProValue.h */

extern ProError ProElementAlloc (ProElemId name_id,
                                 ProElement *p_elem);

/*
   Purpose: Allocates memory with the specified element identifier.

   Input Arguments:
      name_id           - The element identifier

   Output Arguments:
      p_elem            - The allocated element object

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully allocated the element. 
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


/* Destructor -- following C++ convention, see ProValue.h */

extern ProError ProElementFree (ProElement     *p_elem );   
/*
   Purpose: Frees the memory for the specified element.

   Input Arguments:
      p_elem           - The address of the element to be freed

   Output Arguments:
      None

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully freed the element.
      PRO_TK_BAD_INPUTS  - The argument is invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementIdGet (ProElement   elem, 
                                 ProElemId *p_name_id);	
/*
   Purpose:  Retrieves the specified element identifier.

   Input Arguments:
       elem                  - The <i>ProElement</i> object

   Output Arguments:
       p_name_id             - The element identifier

   Return Values:
       PRO_TK_NO_ERROR    - The function successfully retrieved the
                            information. 
       PRO_TK_BAD_INPUTS  - The input argument is invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


extern ProError ProElementIdSet (ProElement  elem,
                                 ProElemId elem_id);
/*
   Purpose: Sets the identifier of the specified element.

   Input Arguments:
       elem            - The <i>ProElement</i> pointer
       elem_id         - The element identifier

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR    - The function successfully set the value.
       PRO_TK_BAD_INPUTS  - One or more of the arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/



extern ProError ProElemtreeElementGet (ProElement   elemtree,
                                       ProElempath  elempath,
                                       ProElement  *p_elem);
/*
    Purpose:
       Retrieves the element specified by the <i>elempath</i> argument.

    Input Arguments:
       elemtree             -   The element tree
       elempath             -   The path to the element

    Output Arguments:
       p_elem               -   The element at the specified path
 
    Return Values:
       PRO_TK_NO_ERROR      -   The function successfully returned
                                the element.
       PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


extern ProError ProElemtreeElementAdd (ProElement    elemtree,
                                       ProElempath   elempath,
                                       ProElement    elem);
/*
    Purpose:
        Links the element at the location specified by the 
        <i>elempath</i> argument.

    Input Arguments:
        elemtree     -   The element tree
        elempath     -   The path to the location where the element 
                         should be linked
        elem         -   The element to link

    Output Arguments:
        None

     Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully linked
	                        the element.
	PRO_TK_BAD_INPUTS    -	One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElemtreeElementRemove (ProElement      elemtree,
                                          ProElempath     elempath,
                                          ProElement     *p_elem);
/*
    Purpose:
        Unlinks the element specified by the <i>elempath</i> argument, 
        and returns its handle. 

    Input Arguments:
        elemtree             -   The element tree
        elempath             -   The path to the element

    Output Arguments:
        p_elem               -   The unlinked element
 
    Return Values: 
        PRO_TK_NO_ERROR      -   The function successfully unlinked
	                         the element.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementIsMultival (ProElement    elemtree,
                                      ProElempath   elempath,
                                      ProBoolean   *p_is_multi_value_elem);
/*
   Purpose:  Determines whether the input element can have multiple
             values.

   Input Arguments:
        elemtree               -  The element tree.
        elempath               -  The path to the element.

   Output Arguments:
        p_is_multi_value_elem  -  If the input element can have multiple values,
                                  this is PRO_B_TRUE. Otherwise, this is
                                  PRO_B_FALSE.

   Return Values:
      PRO_TK_NO_ERROR     -  The function successfully determined whether
                             the element can have multiple values.
      PRO_TK_BAD_INPUTS   -  One or more of the input arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementIsCompound (ProElement    elemtree,
                                      ProElempath   elempath,
                                      ProBoolean   *p_is_compound);
/*
    Purpose:
        Determines whether the element specified by the <i>elempath</i>
        argument is a compound element. 

    Input Arguments:
        elemtree             -   The element tree.
        elempath             -   The path to the element.

    Output Arguments:
        p_is_compound        -   If the element is a compound element, 
                                 this is PRO_B_TRUE.Otherwise,
                                 this is PRO_B_FALSE.

    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully determined
	                         whether the element is a compound element.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/


extern ProError ProElementChildrenSet (ProElement      elemtree,
                                       ProElempath  elempath,
                                       ProElement   *child_elems,
                                       int          n_elems);
/*
    Purpose:
        Sets the children of the element specified by the <i>elempath</i>
        argument.

    Input Arguments:
        elemtree             -   The element tree
        elempath             -   The path to the element
        child_elems          -   The element children
        n_elems              -   The number of elements

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully set the
	                         element children.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementChildrenGet (ProElement   elemtree,
                                       ProElempath  elempath,
                                       ProElement **p_child_elems);
/*
    Purpose:
        Retrieves the children of the element specified by the <i>elempath</i>
        argument.

    Input Arguments:
        elemtree             -   The element tree.
        elempath             -   The path to the element.

    Output Arguments:
        p_child_elems        -   The array of child elements. Note that
                                 you must preallocate the array
                                 using <b>ProArrayAlloc()</b>.

    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully retrieved
	                         the element children.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.

    See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementIsArray (ProElement    elemtree,
                                   ProElempath   elempath,
                                   ProBoolean   *p_is_array);
/*
    Purpose:
        Determines whether the element specified by the <i>elempath</i> 
        argument contains an array of elements. 

    Input Arguments:
        elemtree             -   The element tree.
        elempath             -   The path to the element.

    Output Arguments:
        p_is_array           -   If the element is an array, this is PRO_B_TRUE.
                                 Otherwise, this is PRO_B_FALSE.
    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully determined
                                 whether the element contains an array 
                                 of elements.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementArraySet (ProElement   elemtree,
                                    ProElempath  elempath,
                                    ProElement  *array_elems);
/*
    Purpose:
        Sets the children of the specified array element.

    Input Arguments:
        elemtree             -   The element tree.
        elempath             -   The path to the array element.
        array_elems          -   The element array. You must create this array 
                                 using <b>ProArrayAlloc()</b>.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully set
                                 the element array.
        PRO_TK_BAD_INPUTS    -   One or more of the arguments are 
                                 invalid.

    See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementArrayGet (ProElement      elemtree,
                                    ProElempath     elempath,
                                    ProElement    **p_array_elems);
/*
    Purpose:
        Retrieves the child elements of an array element.

    Input Arguments:
        elemtree             -   The element tree.
        elempath             -   The path to the array element.

    Output Arguments:
        p_array_elems        -   The child elements of the array element.
                                 You must preallocate this array using
                                 <b>ProArrayAlloc()</b>. If you reuse the array,
				 new elements will be appended to the existing
				 elements unless you reset the array size to 0 with
				 ProArraySizeSet.

    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully retrieved
                                 the element array.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.

    See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementArrayCount (ProElement    elemtree,
                                      ProElempath   elempath,
                                      int          *p_array_count);
/*
    Purpose:
        Counts the number of elements in the specified array.

    Input Arguments:
        elemtree             -   The element tree
        elempath             -   The path to the element

    Output Arguments:
        p_array_count        -   The number of elements

    Return Values:
        PRO_TK_NO_ERROR      -   The function successfully counted the number
                                 of elements.
        PRO_TK_BAD_INPUTS    -   One or more of the input arguments are 
                                 invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/* The filter prototype for filtering elements */

typedef ProError (*ProElemtreeVisitFilter) (ProElement  elem_tree,
                                            ProElement  elem,
                                            ProElempath elem_path,
                                            ProAppData  appdata);
/*
   Purpose:  This is the generic user function for filtering subelements
             in an element tree.

   Input Arguments:
      elem_tree - The handle to the element tree
      elem      - The handle to the element
      elem_path - The handle to <i>elem_path</i>
      appdata   - The user data passed to <b>ProElemtreeElementVisit()</b>

   Output Arguments:
      None
 

   Return Values:
      PRO_TK_NO_ERROR - Visit the next subtree.
      PRO_TK_CONTINUE - Do not call action function for the current element.
      Other           - Stop visiting. The function 
                        <b>ProElemtreeElementVisit()</b> 
                         returns with that status.
*/

/* The action prototype for visiting elements */

typedef ProError (*ProElemtreeVisitAction) (ProElement  elem_tree,
                                            ProElement  elem,
                                            ProElempath elem_path,
                                            ProAppData  appdata);
/*
   Purpose:  This is the generic user function for visiting subelements
             in an element tree.

   Input Arguments:
      elem_tree  - The handle to the element tree
      elem       - The handle to the element
      elem_path  - The handle to the <i>elem_path</i>
      appdata    - The user data passed to <b>ProElemtreeElementVisit()</b>

   Output Arguments:
      None
 

   Return Values:
      PRO_TK_NO_ERROR - Visit the next subtree.
      Other           - Stop visiting. The function 
                        <b>ProElemtreeElementVisit()</b> 
                        returns with that status.
*/


extern ProError ProElemtreeElementVisit (ProElement      elemtree,
                                             ProElempath            elempath,
                                             ProElemtreeVisitFilter filterfunc,
                                             ProElemtreeVisitAction visitfunc,
                                             ProAppData             appdata);
/*
    Purpose:
        Recursively visits the subelements of the specified element in the 
        element tree. Note that the element must be an array, and the 
        element path cannot contain an index to visit subelements for
        each index.
<p>        
        The visit function is called if the filter function is PRO_TK_NO_FUNCTION, 
        or if it returns an error code other than PRO_TK_NO_ERROR.
<p>
        Traversal continues until all the elements have been visited, or
        if the visit function returns an error code other than PRO_TK_NO_ERROR,
        or filter function returns an error code other than PRO_TK_NO_ERROR and
        PRO_TK_CONTINUE.



    Input Arguments:
	elemtree             -   The element tree
	elempath             -   The path to the element
	filterfunc           -   The filter function. If NULL, 
	                         all elements are visited 
                                 using the action function.
	visitfunc            -   The visit function
        appdata              -   The user data passed to the visit and 
                                 filter functions

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully visited
                                all the subelements.
	PRO_TK_BAD_INPUTS    -	One or more of the arguments are invalid.
	PRO_TK_E_NOT_FOUND   -  Visit function was never called.
        Other                -  Any other value is the error code returned by 
                                the visit or filter function (visiting stopped).
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
/* Functions used for accessing element values. */
/*===========================================================================*/

extern ProError ProElementValuetypeGet( ProElement                  element, 
                                        ProValueDataType*           type );
/*
   Purpose: Returns the nominal value type for the element.  
      
   Input Arguments:
         element              - The element.
 
   Output Arguments:
         type                 - The type of value stored in the element.
 
   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_EMPTY         - The element does not have a value yet.
         PRO_TK_INVALID_TYPE  - The element is compound or array, 
                                use ProElementIsCompound or ProElementIsArray.
								
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementReferenceGet ( ProElement                 element,
                                         ProElementReferenceOptions options,
                                         ProReference*              reference);
/*
   Purpose: Returns a single reference value for the element.

   Input Arguments:
         element              - The element.
         options              - Options for how the reference should be obtained.
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         reference            - The reference value.

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_EMPTY         - The element does not contain reference.
         PRO_TK_INVALID_TYPE  - The element does not contain a value that can 
                              be represented as a single reference element.
							  
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementReferenceSet ( ProElement   element,
                                         ProReference reference);
/*
   Purpose: Sets the reference value for the element.

   Input Arguments:
         element              - The element.
         reference            - The reference value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.
		 
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementReferencesGet (ProElement                 element,
                                         ProElementReferenceOptions options,
                                         ProReference**             references);
/*
   Purpose: Returns an array of reference values for the element.

   Input Arguments:
         element              - The element.
         options              - Options for how the references should be obtained.
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         references           - The reference array (a ProArray).
                              - Free this output using ProReferencearrayFree.

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value that can 
                              be represented as an array of references.
         PRO_TK_EMPTY         - The element does not contain references.
							  
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementReferencesSet (ProElement    element,
                                         ProReference* references);
/*
   Purpose: Sets the multiple reference values for the element.

   Input Arguments:
         element              - The element.
         references           - The references ProArray.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.
		 
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementIntegerGet (ProElement               element, 
                                      ProElementIntegerOptions options, 
                                      int*                     value);
/*
   Purpose: Returns an integer value representation for the element.  
        
   Input Arguments:
         element              - The element.
         options              - Options for how the integer should be obtained. 
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         value                - The integer value.

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value 
                              that can be represented as a this type.
							  
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementIntegerSet (ProElement element, int value);
/*
   Purpose: Sets the integer value for the element.  
        
   Input Arguments:
         element              - The element.
         value                - The integer value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.
		 
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementDoubleGet (ProElement              element, 
                                     ProElementDoubleOptions options, 
				     double*                 value);
/*
   Purpose: Returns a double value representation for the element.  
        
   Input Arguments:
         element              - The element.
         options              - Options for how the double should be obtained.  
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         value                - The double value.

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value 
                              that can be represented as a this type.
							  
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/
 
/*===========================================================================*/
extern ProError ProElementDoubleSet (ProElement element, double value);
/*
   Purpose: Sets the double value for the element. <p><b>Note: </b>Before using 
this function, use ProElementDecimalsSet() to assign the number of decimal places 
to be used for the double value. 
        
   Input Arguments:
         element              - The element.
         value                - The double value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.
         PRO_TK_CANT_WRITE    - The element is relation driven
		 
   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementWstringGet (ProElement               element, 
                                      ProElementWstringOptions options, 
                                      wchar_t**                value);
/*
   Purpose: Returns a string value representation for the element.  

   <P><B>Note: </B> 

     When called on an element driven by relations, the function will return 
     the first appropriate relations string involving this element value. 
     The relation string should be used only to identify that the element is 
     driven by relations, and should not be used to calculate the element 
     value.  This is because the element value may be driven by more than 
     one relation simultaneously in the feature's relation set.  
     Refer to ProRelSet.h for more details about relations and relation sets.
        
   Input Arguments:
         element              - The element.
         options              - Options for how the string should be obtained.
                              Can be NULL.

   Output Arguments:
         value                - The wide-string value.
                              Free this string using ProWstringFree().

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value 
                              that can be represented as a this type.
							  
   See Also:    
       ProElementwstroptsAlloc()
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementWstringSet (ProElement element, wchar_t* value);
/*
   Purpose: Sets the string value for the element.  
        
   Input Arguments:
         element              - The element.
         value                - The wide-string value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.
         PRO_TK_CANT_WRITE    - The element is relation driven.

   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementStringGet (ProElement              element, 
                                     ProElementStringOptions options, 
                                     char**                  value);
/*
   Purpose: Returns an ASCII string value representation for the element.  
        
   Input Arguments:
         element              - The element.
         options              - Options for how the string should be obtained.  
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         value                - The ASCII string value.
                              Free this string using ProStringFree().

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value
                              that can be represented as a this type.

   See Also:     
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementStringSet (ProElement element, char* value);
/*
   Purpose: Sets the ASCII string value for the element.  
        
   Input Arguments:
         element              - The element.
         value                - The ASCII string value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.

   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementSpecialvalueGet (ProElement               element, 
                                           ProElementSpecialOptions options, 
                                           ProAppData*              value);  
/*
   Purpose: Returns the pointer representation for the element.  
        
   Input Arguments:
         element              - The element.
         options              - Options for how the pointer should be obtained. 
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         value                - The pointer value.  

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value
                              that can be represented as a this type.

   See Also:    
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementSpecialvalueSet (ProElement element, 
                                           ProAppData value);
/*
   Purpose: Sets the pointer value for the element.  
        
   Input Arguments:
         element              - The element.
         value                - The pointer value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.

   See Also:     
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementBooleanGet( ProElement               element, 
                                      ProElementBooleanOptions options, 
                                      ProBoolean*              value); 
/*
   Purpose: Returns the boolean representation for the element.  
        
   Input Arguments:
         element              - The element.
         options              - Options for how the boolean should be obtained.
                              Reserved for future use: pass NULL for now.

   Output Arguments:
         value                - The boolean value.  

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value 
                              that can be represented as a this type.

   See Also:     
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementBooleanSet (ProElement element, ProBoolean value);
/*
   Purpose: Sets the boolean value for the element.  
        
   Input Arguments:
         element              - The element.
         value                - The boolean value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.

   See Also:      
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementTransformGet ( ProElement                 element, 
                                         ProElementTransformOptions options, 
                                         ProMatrix                  value); 
/*
   Purpose: Returns the transform representation for the element.  
        
   Input Arguments:
         element              - The element.
         options              - Options for how the transform should be 
                                obtained.  Reserved for future use; pass NULL 
                                for now.

   Output Arguments:
         value                - The transform value.  

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not contain a value  
                              that can be represented as a this type.

   See Also:     
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

/*===========================================================================*/
extern ProError ProElementTransformSet (ProElement element, ProMatrix value);
/*
   Purpose: Sets the transform value for the element.  
        
   Input Arguments:
         element              - The element.
         value                - The transform value.

   Output Arguments:
         none

   Return Values:
         PRO_TK_NO_ERROR      - The function succeeded.
         PRO_TK_BAD_INPUTS    - One or more arguments is invalid.
         PRO_TK_INVALID_TYPE  - The element does not allow this type of value.

   See Also:   
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError   ProElementCollectionGet (ProElement element, 
                                           ProCollectionGetOptions opts,
                                           ProCollection* collection);
/*
   Purpose:  Extracts a collection from a feature element tree element of type
             PRO_E_STD_CURVE_COLLECTION_APPL, PRO_E_STD_SURF_COLLECTION_APPL.

   Input Arguments: 
        element - The element.
        opts    - Options to use when extracting the element.
                  Reserved for future use; pass NULL in this release.
 
   Output Arguments:
	collection -  A copy of the collection object.
                      Free this using ProCollectionFree().

   Return Values:
	PRO_TK_NO_ERROR     - The function succeeded.
	PRO_TK_BAD_INPUTS   - One or more arguments is invalid.
	PRO_TK_INVALID_TYPE - This element does not contain a collection.
*/

extern ProError   ProElementCollectionSet (ProElement element,
                                           ProCollection collection);
/*
   Purpose:  Assigns a collection object to an element of type 
             PRO_E_STD_CURVE_COLLECTION_APPL, PRO_E_STD_SURF_COLLECTION_APPL.

   Input Arguments:  
	element    - The element.
	collection - The collection object.

   Output Arguments:
	none

   Return Values:
	PRO_TK_NO_ERROR     - The function succeeded.
	PRO_TK_BAD_INPUTS   - One or more arguments is invalid.
	PRO_TK_INVALID_TYPE - This element does not accept a collection.
*/

extern ProError   ProElementCollectionProcess (ProElement element,
                                               ProReference** reference_array);
/*
        Purpose:  Processes the collection contained in a given element
                  according to the rules of the feature it belongs to. Unlike
                  ProSrfcollectionRegenerate() and ProCrvcollectionRegenerate(),
                  the results of this function are a true picture of which
                  items are referenced by the collection stored in the feature.
                  <p><b>Note: </b>This function will not be able to extract geometry, 
if some or all of the resulting geometry is inactive due to material removal features 
occuring in the model. In order to extract the reference geometry for such a collection,
use ProFeatureInsertModeActivate() to roll back the model before the material removal 
feature.

        Input Arguments:
                element - The PRO_E_STD_CURVE_COLLECTION_APPL or 
                          PRO_E_STD_SURFACE_COLLECTION_APPL element.  If this
                          element was extracted from an existing feature tree
                          using ProFeatureElemtreeCreate(), the results will
                          use the feature rules to determine the collected
                          references.  If this element is newly created and
                          not yet assigned to a feature, the default rules are
                          used like ProCrvcollectionRegenerate() and 
                          ProSrfcollectionRegenerate().
        
        Output Arguments:
              reference_array - ProArray of references collected by the
                                collection in the element.  Free this array
                                using ProReferencearrayFree() when finished 
                                with it.

        Return Values:
               PRO_TK_NO_ERROR      - The function succeeded.
               PRO_TK_EMPTY         - If the collection in element is empty.
               PRO_TK_BAD_INPUTS    - One or more inputs was invalid.
               PRO_TK_GENERAL_ERROR - Error evaluating the collected references.
*/



extern ProError ProElementValuesGet (ProElement       elem,
                                     ProValue       **p_values);
/*
   DEPRECATED: Since Wildfire 2
   SUCCESSORS: CONTEXTUAL
   Purpose: Retrieves all the values of the specified element.
            <P><B>Warning: </B>Starting with Wildfire 2.0, tree elements
	    with multiple values are considered to be deprecated and will be
            gradually superseded with reference elements or type-specific
            elements - for which either ProElementReferencesGet or 
            ProElement<type>Get should be used. See also the comment for 
            ProElementValueGet.
 
   Input Arguments:
       elem               - The element.
 
   Output Arguments:
       p_values           - The array of values belonging to the element.
                            You must preallocate the array using 
                            the function <b>ProArrayAlloc()</b>.
 
   Return Values:
       PRO_TK_NO_ERROR    - The function successfully retrieved the values.
       PRO_TK_BAD_INPUTS  - The input argument is invalid.

   See Also:       
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementValueGet (ProElement       elem,
                                    ProValue        *p_value);
/*
   DEPRECATED: Since Wildfire 2.0
   SUCCESSORS: CONTEXTUAL
   Purpose: <P><B>Note: </B>From release Wildfire 2.0 this function is superseded by
			the function ProElementValuetypeGet() followed by one of the following:
			<UL>
				<LI>ProElementReferenceGet()
				<LI>ProElementIntegerGet()
				<LI>ProElementDoubleGet()
				<LI>ProElementStringGet()
				<LI>ProElementWstringGet()
				<LI>ProElementBooleanGet()
				<LI>ProElementTransformGet()
				<LI>ProElementSpecialvalueGet()
				<LI>ProElementCollectionGet()
			</UL>								  
			PTC recommends using the new functions in place of this function in all 
			new or updated user applications.
			
			<P>Retrieves the single value of the specified element. 

   Input Arguments:
       elem                  - The element

   Output Arguments:
       p_value               - The value of the element 

   Return Values:
       PRO_TK_NO_ERROR    - The function successfully retrieved the value.
       PRO_TK_BAD_INPUTS  - The input argument is invalid.  
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementValuesSet (ProElement  elem,
                                     ProValue    values[],
                                     int         value_num);
/*
   DEPRECATED: Since Wildfire 2.0
   SUCCESSORS: CONTEXTUAL
   Purpose: Sets the values of the specified element.
            <P><B>Warning: </B>Starting with Wildfire 2.0, tree elements
	    with multiple values are considered to be deprecated and will be
            gradually superseded with reference elements or type-specific
            elements - for which either ProElementReferencesSet or 
            ProElement<type>Set should be used. See also the comment for 
            ProElementValueSet.
 
   Input Arguments:
       elem             - The element 
       values           - The array of values
       value_num        - The number of values
 
   Output Arguments:
       None
 
   Return Values:
       PRO_TK_NO_ERROR   - The function successfully set the values.
       PRO_TK_BAD_INPUTS - One or more of the arguments are invalid.
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementValueSet (ProElement  elem,
                                    ProValue    value);
/*
   DEPRECATED: Since Wildfire 2.0
   SUCCESSORS: CONTEXTUAL
   Purpose: <P><B>Note: </B>From release Wildfire 2.0 this function is superseded by
			the function ProElementValuetypeGet() followed by one of the following:
			<UL>
				<LI>ProElementReferenceSet()
				<LI>ProElementIntegerSet()
				<LI>ProElementDoubleSet()
				<LI>ProElementStringSet()
				<LI>ProElementWstringSet()
				<LI>ProElementBooleanSet()
				<LI>ProElementTransformSet()
				<LI>ProElementSpecialvalueSet()
				<LI>ProElementCollectionSet()
			</UL>								  
			PTC recommends using the new functions in place of this function in all 
			new or updated user applications.
   
			<P>Sets the single value of the specified element.

   Input Arguments:
       elem             - The element 
       value            - The value to set

   Output Arguments:
       None

   Return Values:
       PRO_TK_NO_ERROR   - The function successfully set the value.
       PRO_TK_BAD_INPUTS - One or more of the arguments are invalid. 
   
   See Also:
       ProAnalysis.h
       ProAsmcomp.h
       ProBeltFeat.h
       ProChamfer.h
       ProContact3dFeat.h
       ProDamperFeat.h
       ProDesignatedArea.h
       ProDraft.h
       ProDtmAxis.h
       ProDtmCrv.h
       ProDtmCsys.h
       ProDtmPln.h
       ProDtmPnt.h
       ProElemId.h
       ProExtrude.h
       ProFeatIntr.h
       ProFixture.h
       ProFlatSrf.h
       ProForeignCurve.h
       ProHole.h
       ProMfgoper.h
       ProMerge.h
       ProMirror.h
       ProMove.h
       ProNcseq.h
       ProNcseqElem.h
       ProPattern.h
       ProProcstep.h
       ProReplace.h
       ProRevolve.h
       ProRib.h
       ProRound.h
       ProShell.h
       ProSmtFlangeWall.h
       ProSmtFlatWall.h
       ProSmtForm.h
       ProSolidify.h
       ProSmtPunchQuilt.h
       ProStdSection.h
       ProSurfReg.h
       ProSweep.h
       ProThicken.h
       ProTrim.h
       ProToolElem.h
       ProValue.h
       ProWcell.h
*/

extern ProError ProElementDecimalsGet (ProElement element, int* decimals);
/*
    Purpose: Obtains the number of decimals places to used for a double value 
             in the feature.  

    Input Arguments:
        element - The element.

    Output Arguments:
        decimals - The number of decimal places to be used.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - The element is not a double element.

    See Also:
        ProElementDoubleGet()
        ProElementDoubleSet()
        ProElementDecimalsSet()
*/

extern ProError ProElementDecimalsSet (ProElement element, int decimals);
/*
    Purpose: Assigns the number of decimals places to used for a double value 
             in the feature.   This value will be used in the part dimension 
             related to this element.  
             <P>
             <b>Notes:</b> 
             <UL>
             <LI>Creo Parametric has a limit of 0-9 to nine decimal places for feature 
             dimensions.
             <LI>This function should be used before ProElementDoubleSet to 
             ensure that the value is assigned with the correct intended number 
             of decimal places.
             <LI>Relations referring to the related dimension will not be 
             affected by the decimal places setting.
             <LI>This will have no effect on the related dimension if it is 
             created as fractional.
             </UL>
             

    Input Arguments:
        element - The element.
        decimals - The number of decimal places to be used.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_INVALID_TYPE - The element is not a double element.
        PRO_TK_CANT_WRITE    - The element is relation driven

    See Also:
        ProElementDoubleGet()
        ProElementDoubleSet()
        ProElementDecimalsGet()
*/

typedef void* ProElemdiagnostic;

typedef enum 
{
   PRO_ELEM_INFO    = 0,
   PRO_ELEM_WARNING = 1,
   PRO_ELEM_ERROR   = 2
} ProDiagnosticSeverity;

extern ProError ProReferenceDiagnosticsCollect(ProReference reference,
                                               ProElemdiagnostic** diagnostics);
/*
    Purpose: Obtains a list of the reference diagnostics for the reference
             handle.  These contain warnings and errors regarding the state
             of the reference, within the context of the feature.

    Input Arguments:
        reference - The reference handle.

    Output Arguments:
        diagnostics - A ProArray containing any potential problems associated
                      to this reference handle. Free this using
                      ProElemdiagnosticProarrayFree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_E_NOT_FOUND -The size of diagnostic array is zero.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProElementDiagnosticsCollect (ProElement element,
                                              ProElemdiagnostic** diagnostics);
/*
    Purpose: Obtains a list of the element diagnostics for the element. These 
             contain warnings and errors regarding the value of the element, 
             within the context of the feature and remainder of the element 
             tree.

    Input Arguments:
        element - The element.

    Output Arguments:
        diagnostics - A ProArray containing any potential problems associated 
                      to this element or its value. Free this using 
                      ProElemdiagnosticProarrayFree.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
	PRO_TK_E_NOT_FOUND -The size of diagnostic array is zero. 
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProElemdiagnosticSeverityGet (ProElemdiagnostic diagnostic,
                                              ProDiagnosticSeverity* severity);
/*
    Purpose: Obtains the severity of the diagnostic item.

    Input Arguments:
        diagnostic - The element diagnostic item.

    Output Arguments:
        severity - The severity.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProElemdiagnosticMessageGet (ProElemdiagnostic diagnostic, 
                                             ProComment message);
/*
    Purpose: Obtains the message describing the diagnostic item. This will be 
             in the user's localized language.

    Input Arguments:
        diagnostic - The diagnostic item.

    Output Arguments:
        message - The message.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProElemdiagnosticFree (ProElemdiagnostic diagnostic);
/*
    Purpose: Frees a diagnostic item.

    Input Arguments:
        diagnostic - The diagnostic item.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProElemdiagnosticProarrayFree (ProElemdiagnostic* diag_array);
/*
    Purpose: Frees an array of an array of diagnostic items returned from 
             ProElementDiagnosticsCollect.

    Input Arguments:
        diag_array - The diagnostic ProArray.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

extern ProError ProElemtreeVerify (ProSolid solid, 
                                   ProAsmcomppath* assembly_reference, 
                                   ProElement elemtree);
/*
    Purpose: Verifies the contents of the element tree. This will parse the 
             element tree and determine, where possible, if any elements have 
             potentially incorrect values. The results of this verification can 
             be obtained from two different paths: 
             <OL> 
             <LI> Use ProElementDiagnosticsCollect() to see if any diagnostic 
             items were added to certain elements in the tree. 
             <LI> Use ProReferenceStatusGet() to see if certain references in 
             the tree now show a missing or error status. 
             </OL> This function is primarily intended for new element trees 
             created in order to create a new feature in the model. Trees which 
             are extracted using ProFeatureElemtreeCreate() will already have 
             diagnostics information embedded based on the owner model state at 
             the time of extraction.

    Input Arguments:
        solid - The solid model where the element tree will be used.
        assembly_reference - Path from the top level assembly to the solid 
                             model, if the feature will be created with 
                             external assembly references.
        elemtree - The element tree.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.

*/

typedef enum pro_elemtree_type { 
        PRO_ELEMTREE_XML = 1 
} ProElemtreeFormat ;

extern ProError   ProElemtreeWrite ( 
                     ProElement         elemtree, 
                     ProElemtreeFormat  format,
                     ProPath            output_file 
                );

/*
    Purpose:
            Writes the Element Tree in the specified file in XML format

    Input Arguments:
            elemtree              - root element of the element tree to be printed
            format                - pass PRO_ELEMTREE_XML 
            output_file           - Full path to the output file, 
				    including extension.

    Output Arguments:
            none

    Return Values:
      PRO_TK_NO_ERROR            - Successful in writing the element tree 
      PRO_TK_BAD_INPUTS          - Invalid inputs
      PRO_TK_GENERAL_ERROR       - Errors in generating the output
*/


typedef enum pro_xml_errortype {
        PRO_XML_WARNING,
        PRO_XML_ERROR,
        PRO_XML_FATALERROR, 
        PRO_XML_OTHERERROR
} ProXMLErrorType;

typedef struct pro_xml_errorlist {
        ProXMLErrorType         error_type;
        ProPath                 error_source;
        int                     line_number;
        int                     column_number;
        wchar_t*                message;
} ProXMLErrorlist;

extern ProError   ProElemtreeFromXMLCreate (
                     ProPath            xml_file,
                     ProElement         *elemtree,
                     ProXMLErrorlist    **p_errors
                );
/*
    Purpose:
       Reads in the xml file and converts into an element tree. This element tree
       can be used as an input to ProFeatureWithoptionsCreate or
       ProFeatureWithoptionsRedefine

    Input Arguments:
            xml_file               - the name of the xml file with location
                                    this can be a relative or absolute path to the xml file
                                    or a URL ( http or file ) for the xml file

    Output Arguments:
            elemtree               - root element of the created element tree
				     Memory allocated by the function and to be freed by
				     caller using ProElementFree()
            p_errors               - ProArray of errors. The memory allocated by the function
                                     has to be freed by using the function 
				     ProXmlerrorlistProarrayFree().

    Return Values:
      PRO_TK_NO_ERROR            - Successful in creating the element tree 
      PRO_TK_BAD_INPUTS          - Invalid inputs
      PRO_TK_GENERAL_ERROR       - Errors in the XML file; The function 
                                   populates the ProArray p_errors to hold 
                                   the errors ( refer all fields ) 
      PRO_TK_OUT_OF_MEMORY       - XML Parser failed to initialize
      PRO_TK_CANT_ACCESS   	 - XML Parser failed during parsing
      PRO_TK_CANT_OPEN  	 - XML Parser failed opening DOM Tree
      PRO_TK_NOT_VALID  	 - XML Parser failed due to other errors
      PRO_TK_E_AMBIGUOUS  	 - Error occurred during creation of output 
                                   transcoder
      PRO_TK_BAD_CONTEXT   	 - Function failed to create the element tree 
				   due to an error in the ProElemId, ProType, 
				   or Enum Value in the XML file
				   The function populates the ProArray 
                                   p_errors to hold the errors ( refer to 
                                   fields: 
				   <UL>
				   <LI>error_type  = PRO_XML_OTHERERROR
				   <LI>line_number =  sr. no. of Element in file
				   <LI>message     = name of Element 
				   <LI>column_number = elem_id of Element 
				   </UL>
				   )

*/

LIB_COREUTILS_API  ProError   ProXmlerrorlistProarrayFree ( ProXMLErrorlist** errors_array ); 

/* 

   Purpose: Frees errors_array returned by ProElemtreeFromXMLCreate in 
	    error conditions

   Input Arguments:
      errors_array      - ProArray of ProXMLErrorlist 

   Output Arguments:

   Return Values:
      PRO_TK_NO_ERROR    - The function successfully freed errors_array
      PRO_TK_BAD_INPUTS  - The input argument is invalid.
      PRO_TK_BAD_CONTEXT - Problem with errors_array 

*/ 
PRO_END_C_DECLS

#endif /* PROELEMENT_H */

