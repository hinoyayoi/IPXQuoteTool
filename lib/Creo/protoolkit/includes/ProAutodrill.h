


/*
 *      INCLUDES: ProAutoDrill.h
 */

#ifndef PROAUTODRILL_H
#define PROAUTODRILL_H

#include <ProMfg.h>

PRO_BEGIN_C_DECLS


extern ProError ProAutodrillSeqOrderAlloc( ProMfg       mfg,
					   int		consider_csys );
/*
   Purpose: Setup the necessary data for reordering autodrilling sequences.
	    It will group autodrilling sequences which are created inside
	    the same operation and consequtively together. If consider_csys
	    is not zero, then two sequences with nonparallel z-axis ( of 
	    their coordinate systems ) will not be grouped together. 

   Input Arguments:
      mfg             - The manufacturing object.
      consider_csys   - A flag, if nonzero, then sequences with different
			nonparallel coordinate systems will not  be grouped
			together.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the information.
      Other           - The input argument is invalid.

*/


extern ProError ProAutodrillSeqOrderFree( ProMfg       mfg );
/*
   Purpose: Release the data allocated by ProAutodrillSeqOrderAlloc(). 

   Input Arguments:
      mfg             - The manufacturing object.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function successfully releases data.
      Other           - The input argument is invalid.

*/


extern ProError ProAutodrillSegmentNumGet( ProMfg       mfg,
					   int		*p_num_of_segments );
/*
   Purpose: Returns the number of groups created by 
				ProAutodrillSeqOrderAlloc().

   Input Arguments:
      mfg             - The manufacturing object.

   Output Arguments:
      p_num_of_segments - The number of groups created by 
				ProAutodrillSeqOrderAlloc().

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the information.
      Other           - The input argument is invalid.

*/


extern ProError ProAutodrillSegmentGet( ProMfg		mfg,
					int		segment_index,
					int		**p_segment );
/*
   Purpose: Returns one of the groups( id's of its sequences) created by
	    ProAutodrillSeqOrderAlloc().

   Input Arguments:
      mfg		- The manufacturing object.
      segment_index	- index of the segment.

   Output Arguments:
      p_segment		- address of the segment. *p_segment is a
			  pre_allocated array.

   Return Values:
      PRO_TK_NO_ERROR - The function successfully retrieved the information.
      Other           - The input argument is invalid.

*/

extern ProError ProAutodrillSegmentSet( ProMfg		mfg,
					int		segment_index,
					int		*segment );
/*
   Purpose: Reorder one of the groups( id's of its sequences) created by
	    ProAutodrillSeqOrderAlloc(). It does not reorder features by
	    itself. It only store the new ordering for future call to
	    ProAutodrillReorder().

   Input Arguments:
      mfg		- The manufacturing object.
      segment_index	- index of the segment.
      segment		- The new ordering for the selected segment.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set data.
      Other           - The input argument is invalid.

*/

extern ProError ProAutodrillSegmentReset( ProMfg		mfg,
					  int		segment_index );
/*
   Purpose: Restore one of the groups( id's of its sequences) created by
	    ProAutodrillSeqOrderAlloc(), in case it was changed by a
	    call to ProAutodrillSegmentSet().

   Input Arguments:
      mfg		- The manufacturing object.
      segment_index	- index of the segment.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function successfully set data.
      Other           - The input argument is invalid.


*/

extern ProError ProAutodrillReorder( ProMfg		mfg );
/*
   Purpose: Reorder autodrilling features using data set by 		
		ProAutodrillSegmentSet().

   Input Arguments:
      mfg		- The manufacturing object.

   Output Arguments:
      none

   Return Values:
      PRO_TK_NO_ERROR - The function successfully reorder sequences.
      Other           - The input argument is invalid.

*/



PRO_END_C_DECLS

#endif
