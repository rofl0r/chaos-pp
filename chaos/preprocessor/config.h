#  /* (C) Copyright Paul Mensonides 2003 */
#
# ifndef CHAOS_PREPROCESSOR_CONFIG_H
# define CHAOS_PREPROCESSOR_CONFIG_H
#
# /* CHAOS_PP_VARIADICS */
#
# if !defined CHAOS_PP_VARIADICS
#    if !__cplusplus && __STDC_VERSION__ >= 199901L
#        define CHAOS_PP_VARIADICS 1
#    else
#        define CHAOS_PP_VARIADICS 0
#    endif
# elif !CHAOS_PP_VARIADICS + 1 < 2
#    undef CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADICS 1
# else
#    undef CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADICS 0
# endif
#
# endif
