#ifndef PROELEMPATHH
#define PROELEMPATHH





PRO_BEGIN_C_DECLS


/* tmp */

typedef struct _UiElemId *ProElempath;


typedef enum
{
   PRO_ELEM_PATH_ITEM_TYPE_ID = 1,
   PRO_ELEM_PATH_ITEM_TYPE_INDEX
} ProElempathItemtype;
 
 
typedef struct path
{
   ProElempathItemtype type;
   union
   {
      int       elem_id;
      int       elem_index;
   } path_item;
} ProElempathItem;
 


extern ProError ProElempathAlloc ( ProElempath    *p_elem_path );
/*
    Purpose:
        Allocates an element path.

    Input Arguments:
	None

    Output Arguments:
	p_elem_path          -  A pointer to the allocated element path

    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully allocated
                                the element path.
	PRO_TK_OUT_OF_MEMORY -	The system ran out of memory.
   
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

extern ProError ProElempathFree ( ProElempath    *p_elem_path );
/*
    Purpose:
        Releases the specified element path.

    Input Arguments:
	p_elem_path          -  A pointer to the element path

    Output Arguments:
        none

    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully released
                                the element path and <I>*p_elem_path</I> 
                                is now NULL.
	PRO_TK_BAD_INPUTS    -	The input argument is invalid.
   
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


extern ProError ProElempathDataSet ( ProElempath       elem_path,
                                     ProElempathItem  *elempath_data,
                                     int               path_size);
/*
    Purpose:
        Assigns element path data to the specified element path.

    Input Arguments:
	elem_path            -  The element path.
        elempath_data        -  The element path data. This is an array of
                                <I>ProElempathItem</I> data structures.
        path_size            -  The size of the array <I>elempath_data</I>.
        
    Output Arguments:
        None
 
    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully assigned
                                element path data to the element path.
	PRO_TK_BAD_INPUTS    -	One or more of the arguments are invalid.
   
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


extern ProError ProElempathDataGet (ProElempath       elem_path,
                                    ProElempathItem **p_elempath_data);
/*
    Purpose:
        Retrieves the element path data from the specified element path.

    Input Arguments:
	elem_path            -  The element path.

    Output Arguments:
        p_elempath_data      -  The element path data that is an array of
                                <I>ProElempathItem</I> data structures. You 
                                must preallocate this array using the function
                                <B>ProArrayAlloc()</B>. If you reuse the array,
				new elements will be appended to the existing
				elements unless you reset the array size to 0 with
				ProArraySizeSet.
    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully retrieved
                                element path data from the element path.
	PRO_TK_BAD_INPUTS    -	The input argument is invalid.

    See Also:
       ProArrayAlloc() 
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



extern ProError ProElempathCopy (ProElempath  elem_path_from,
                                 ProElempath  elem_path_to);
/*
    Purpose:
        Copies the specified element path.

    Input Arguments:
	elem_path_from       -  The source element path.

    Output Arguments:
	elem_path_to         -  The target element path. You must 
                                preallocate the memory
                                for this argument.

    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully copied
                                the element path.
	PRO_TK_BAD_INPUTS    -	The input argument is invalid.
   
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



extern ProError ProElempathCompare (ProElempath  elem_path1,
                                    ProElempath  elem_path2,
                                    ProBoolean  *p_same);
/*
    Purpose:
        Compares two element paths.

    Input Arguments:
	elem_path1           -  The source element path.
	elem_path2           -  The target element path. You must preallocate
                                the memory for this argument.

    Output Arguments:
	p_same               -  If both paths are the same, this is PRO_B_TRUE;
                                otherwise, this is PRO_B_FALSE.

    Return Values:
	PRO_TK_NO_ERROR      - 	The function successfully compared
                                the element paths.
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

extern ProError ProElempathSizeGet (ProElempath   elem_path,
                                    int          *p_size);
/*
    Purpose:
        Retrieves the size of the element path. 
 
    Input Arguments:
        elem_path            -  The element path
 
    Output Arguments:
        p_size               -  The size of the element path
 
    Return Values:
        PRO_TK_NO_ERROR      -  The function successfully retrieved
                                the size of the path.
        PRO_TK_BAD_INPUTS    -  The input argument is invalid.
   
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


PRO_END_C_DECLS

#endif
