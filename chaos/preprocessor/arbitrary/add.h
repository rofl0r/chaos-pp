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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_ADD_H
# define CHAOS_PREPROCESSOR_ARBITRARY_ADD_H
#
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/plus.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/arbitrary/sub.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_ADD */
#
# define CHAOS_PP_ARBITRARY_ADD(x, y) CHAOS_IP_ARBITRARY_ADD_I(CHAOS_PP_ARBITRARY_FIX(x), CHAOS_PP_ARBITRARY_FIX(y))
# define CHAOS_PP_ARBITRARY_ADD_ID() CHAOS_PP_ARBITRARY_ADD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_ADD_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_ADD)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARBITRARY_ADD_I(x, y) \
        CHAOS_PP_VARIADIC_CAT(CHAOS_IP_ARBITRARY_ADD_S_, CHAOS_PP_ARBITRARY_SIGN(x), CHAOS_PP_ARBITRARY_SIGN(y))( \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(x))(CHAOS_PP_REM) x, \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(y))(CHAOS_PP_REM) y \
        ) \
        /**/
# else
#    define CHAOS_IP_ARBITRARY_ADD_I(x, y) \
        CHAOS_PP_CAT(CHAOS_IP_ARBITRARY_ADD_S_, CHAOS_PP_CAT(CHAOS_PP_ARBITRARY_SIGN(x), CHAOS_PP_ARBITRARY_SIGN(y)))( \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(x))(CHAOS_PP_REM) x, \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(y))(CHAOS_PP_REM) y \
        ) \
        /**/
# endif
#
# define CHAOS_IP_ARBITRARY_ADD_S_00(x, y) CHAOS_PP_ARBITRARY_ADD_INTERNAL(x, y)
# define CHAOS_IP_ARBITRARY_ADD_S_01(x, y) CHAOS_IP_ARBITRARY_ADD_S_10(y, x)
# define CHAOS_IP_ARBITRARY_ADD_S_10(x, y) \
    CHAOS_PP_ARBITRARY_FIX(CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y))( \
        CHAOS_PP_ARBITRARY_SUB_INTERNAL(y, x), (CHAOS_PP_ARBITRARY_SUB_INTERNAL(x, y)) \
    )) \
    /**/
# define CHAOS_IP_ARBITRARY_ADD_S_11(x, y) (CHAOS_PP_ARBITRARY_ADD_INTERNAL(x, y))
#
# /* CHAOS_PP_ARBITRARY_ADD_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_ADD_INTERNAL(x, y) \
        CHAOS_PP_ARBITRARY_FIX_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_ARBITRARY_ADD_M(0) CHAOS_PP_ARBITRARY_RMERGE(x, y, CHAOS_IP_ARBITRARY_ADD_M, 0)() \
        ))) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_ADD_INTERNAL(x, y) \
        CHAOS_PP_ARBITRARY_FIX_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_ARBITRARY_ADD_M(0) CHAOS_PP_ARBITRARY_RMERGE(x, y, CHAOS_IP_ARBITRARY_ADD_M, 0)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
        ))) \
        /**/
# endif
#
# define CHAOS_IP_ARBITRARY_ADD_M(carry) CHAOS_IP_ARBITRARY_ADD_ ## carry
# define CHAOS_IP_ARBITRARY_ADD_0(x, y) CHAOS_PP_PLUS_3RD(0)(CHAOS_PP_PLUS(x, y))
# define CHAOS_IP_ARBITRARY_ADD_1(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_PLUS(x, y), 1)
#
# endif
