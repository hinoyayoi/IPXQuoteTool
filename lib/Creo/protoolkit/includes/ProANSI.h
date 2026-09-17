#ifndef PROANSI_H
#define PROANSI_H

/* Creo Parametric TOOLKIT compatibility macros for ANSI C/C++ language features */



/* The following #ifdefs and #defines determine which language features are
   to be made available throughout the code.  Platform or compiler specific
   checks should be made here.
*/

/*
 * NOTE: macros PRO_PROTO and PRO_CONST_ARG are \\obsolete//, as all compilers
 * for both PTC products and Creo Parametric TOOLKIT applications are required to be
 * ANSI-qualified. The definitions are still here so that old code will
 * still build; the macros should not be used in any future code.
 */
  
#ifdef __cplusplus
#define PRO_USE_PROTO               /* defines for C++ compile */
#define PRO_USE_CONST_ARG
#  ifndef PRO_CPLUSPLUS_COMPILE
#    define PRO_CPLUSPLUS_COMPILE
#  endif
#else
#ifdef __STDC__
#define PRO_USE_PROTO               /* defines for ANSI C compile */
#define PRO_USE_CONST_ARG
#endif  /*  __STDC__   */
#endif  /* __cplusplus */

/* PRO_PROTO allows "prototypes" to be used with both K&R and ANSI compilers.
     For example,
       extern char *foocpy PRO_PROTO(( char *s1, char *s2 ));
     becomes
       extern char *foocpy ( char *s1, char *s2 );        for ANSI compilers
     and
       extern char *foocpy ();                            for K&R compilers

NOTE: This macro is obsolete, as all compilers for both PTC products
and Creo Parametric TOOLKIT applications are required to be ANSI-qualified. The
definitions are still here so that old code will still build; the
macros should not be used in any future code.
*/
#ifdef PRO_USE_PROTO
#define PRO_PROTO(s)  s
#else
#define PRO_PROTO(s)  ()
#endif

/* CPP_PROTO addresses the case when too much C code depends on a function
   NOT being prototyped (i.e. on only an empty declaration being provided),
   but the same header is to be included by C++ code which needs a full
   prototype.  Except for hinging on C++ vs. C compilation rather than ANSI vs.
   K&R compilation, this macro operates the same as PRO_PROTO defined above.
*/
#ifdef PRO_CPLUSPLUS_COMPILE
#define CPP_PROTO(s)  s
#else
#define CPP_PROTO(s)  ()
#endif

/* PRO_CONST_ARG allows variables to be declared as 'const' in argument lists,
   typdefs, declarations, etc, without sacrificing K&R C compatibility.  Of
   course the K&R C compilers will not actually see this declaration.
NOTE: This macro is obsolete, as all compilers for both PTC products
and Creo Parametric TOOLKIT applications are required to be ANSI-qualified. The
definitions are still here so that old code will still build; the
macros should not be used in any future code.
*/
#ifdef PRO_USE_CONST_ARG
#define PRO_CONST_ARG const
#else
#define PRO_CONST_ARG
#endif

/* PRO_BEGIN_C_DECLS and PRO_END_C_DECLS allow C functions and declarations
   between them to be used from C++ though they are compiled with a C compiler.
*/
#ifdef PRO_CPLUSPLUS_COMPILE
#define PRO_BEGIN_C_DECLS  extern "C" {
#define PRO_END_C_DECLS    }
#else
#define PRO_BEGIN_C_DECLS
#define PRO_END_C_DECLS
#endif

#endif  /* PROANSI_H */
