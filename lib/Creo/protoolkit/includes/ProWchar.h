#ifndef PROWCHART_H
#define PROWCHART_H




#include <ProHardware.h>    		/*  Hardware definitions  */



#if PRO_MACHINE == SUN4			/*  SUN4  */
# ifdef SOLARIS
#   include <stddef.h>
# else
#    include <sys/stdtypes.h>
# endif   /*  SOLARIS  */


#else					/*  As Specified Here  */
#if PRO_MACHINE == HP700      || PRO_MACHINE == DG
#   include <stddef.h>
#else					/*  As Specified Here  */
#if PRO_MACHINE == NEC_RISC || PRO_MACHINE == NEC_MIPS || PRO_MACHINE == HITACHI
#   include <stddef.h>
#else					/*  As Specified Here  */
#if PRO_MACHINE == ALPHA_UNIX || PRO_MACHINE == IBM_RIOS || PRO_MACHINE == LINUX || PRO_MACHINE == X86E_LINUX64 || PRO_MACHINE == APPLE_OSX
#   include <stddef.h>
#else					/*  As Specified Here  */
#if (PRO_MACHINE == SGI_R4K)
    /* SGI on IRIX 5 */
#   include <stddef.h>
#else					/*  All Others  */
#     if (!defined (PRO_WCHAR_T_H) && !defined (_WCHAR_T) && !defined(_WCHAR_T_DEFINED))
      typedef unsigned short   wchar_t; /*  Use a 2 byte definition  */
#     endif

#endif  				/*  As Specified Here  */
#endif  				/*  As Specified Here  */
#endif  				/*  As Specified Here  */
#endif  				/*  As Specified Here  */
#endif  				/*  SUN4  */

					/*  Define these variants  */
# ifndef WCHAR_T
# define WCHAR_T
# endif
# ifndef _WCHAR_T
# define _WCHAR_T
# endif
# ifndef _WCHAR_T_
# define _WCHAR_T_
# endif
# ifndef __WCHAR_T
# define __WCHAR_T
# endif
# ifndef _WCHAR_T_DEFINED
# define _WCHAR_T_DEFINED
# endif


#endif 	/*  PROWCHART_H  */
