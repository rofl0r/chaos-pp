# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_MOD_H
# define CHAOS_PREPROCESSOR_ARBITRARY_MOD_H
#
# include <chaos/_preprocessor/arbitrary/detail/fix.h>
# include <chaos/_preprocessor/arbitrary/div.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_MOD_AP */
#
# define CHAOS_PP_MOD_AP(x, y) CHAOS_IP_MOD_AP_I(CHAOS_PP_FIX_AP(x), CHAOS_PP_FIX_AP(y))
# define CHAOS_PP_MOD_AP_ID() CHAOS_PP_MOD_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_AP)
# endif
#
# define CHAOS_IP_MOD_AP_I(x, y) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_SIGN_AP(x))( \
        CHAOS_PP_REM \
    )(CHAOS_PP_MOD_AP_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_REM) x, \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(y))(CHAOS_PP_REM) y \
    )) \
    /**/
#
# /* CHAOS_PP_MOD_AP_INTERNAL */
#
# define CHAOS_PP_MOD_AP_INTERNAL(x, y) CHAOS_PP_BINARY_CTOR(1, CHAOS_IP_DIV_AP_1(x, y))
#
# endif
