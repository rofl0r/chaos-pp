# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_SIGN_H
# define CHAOS_PREPROCESSOR_ARBITRARY_SIGN_H
#
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_SIGN_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SIGN_AP(x) CHAOS_PP_BINARY_CTOR(0, CHAOS_PP_SUPER_CLEAN_AP(x))
#    define CHAOS_PP_SIGN_AP_ID() CHAOS_PP_SIGN_AP
#    define CHAOS_PP_SIGN_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_SIGN_AP)
# endif
#
# endif
