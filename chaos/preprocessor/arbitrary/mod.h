# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
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
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/div.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_MOD */
#
# define CHAOS_PP_ARBITRARY_MOD(x, y) CHAOS_IP_ARBITRARY_MOD_I(CHAOS_PP_ARBITRARY_FIX(x), CHAOS_PP_ARBITRARY_FIX(y))
# define CHAOS_PP_ARBITRARY_MOD_ID() CHAOS_PP_ARBITRARY_MOD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_MOD_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_MOD)
# endif
#
# define CHAOS_IP_ARBITRARY_MOD_I(x, y) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_PP_REM \
    )(CHAOS_PP_ARBITRARY_MOD_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(x))(CHAOS_PP_REM) x, \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(y))(CHAOS_PP_REM) y \
    )) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_MOD_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_MOD_INTERNAL(x, y) CHAOS_PP_BINARY_CTOR(1, CHAOS_IP_ARBITRARY_DIV_1(x, y))
#
# endif
