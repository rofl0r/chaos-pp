# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
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
# include <chaos/preprocessor/lambda/ops.h>
#
# define CHAOS_PP_VARIADICS_ID() CHAOS_PP_VARIADICS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADICS_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADICS_ID)()
# endif
#
# endif
