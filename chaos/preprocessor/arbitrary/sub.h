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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_SUB_H
# define CHAOS_PREPROCESSOR_ARBITRARY_SUB_H
#
# include <chaos/_preprocessor/arbitrary/add.h>
# include <chaos/_preprocessor/arbitrary/detail/fix.h>
# include <chaos/_preprocessor/arbitrary/detail/merge.h>
# include <chaos/_preprocessor/arbitrary/detail/minus.h>
# include <chaos/_preprocessor/arbitrary/detail/scan.h>
# include <chaos/_preprocessor/arbitrary/less_equal.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitor.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SUB_AP */
#
# define CHAOS_PP_SUB_AP(x, y) CHAOS_IP_SUB_AP_I(CHAOS_PP_FIX_AP(x), CHAOS_PP_FIX_AP(y))
# define CHAOS_PP_SUB_AP_ID() CHAOS_PP_SUB_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB_AP)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SUB_AP_I(x, y) \
        CHAOS_PP_VARIADIC_CAT(CHAOS_IP_SUB_AP_S_, CHAOS_PP_SIGN_AP(x), CHAOS_PP_SIGN_AP(y))( \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_REM) x, \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(y))(CHAOS_PP_REM) y \
        ) \
        /**/
# else
#    define CHAOS_IP_SUB_AP_I(x, y) \
        CHAOS_PP_CAT(CHAOS_IP_SUB_AP_S_, CHAOS_PP_CAT(CHAOS_PP_SIGN_AP(x), CHAOS_PP_SIGN_AP(y)))( \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_REM) x, \
            CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(y))(CHAOS_PP_REM) y \
        ) \
        /**/
# endif
#
# define CHAOS_IP_SUB_AP_S_00(x, y) CHAOS_IP_SUB_AP_S_11(y, x)
# define CHAOS_IP_SUB_AP_S_01(x, y) CHAOS_PP_ADD_AP_INTERNAL(x, y)
# define CHAOS_IP_SUB_AP_S_10(x, y) (CHAOS_PP_ADD_AP_INTERNAL(x, y))
# define CHAOS_IP_SUB_AP_S_11(x, y) \
    CHAOS_PP_FIX_AP(CHAOS_PP_IIF(CHAOS_PP_LESS_EQUAL_AP_INTERNAL(x, y))( \
        CHAOS_PP_SUB_AP_INTERNAL(y, x), (CHAOS_PP_SUB_AP_INTERNAL(x, y)) \
    )) \
    /**/
#
# /* CHAOS_PP_SUB_AP_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_AP_INTERNAL(x, y) \
        CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_SUB_AP_M(0) CHAOS_PP_RMERGE(x, y, CHAOS_IP_SUB_AP_M, 0)() \
        ))) \
        /**/
# else
#    define CHAOS_PP_SUB_AP_INTERNAL(x, y) \
        CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_SUB_AP_M(0) CHAOS_PP_RMERGE(x, y, CHAOS_IP_SUB_AP_M, 0)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
        ))) \
        /**/
# endif
#
# define CHAOS_IP_SUB_AP_M(borrow) CHAOS_IP_SUB_AP_ ## borrow
# define CHAOS_IP_SUB_AP_0(x, y) CHAOS_IP_SUB_AP_II(CHAOS_PP_MINUS(x, y), 0)
# define CHAOS_IP_SUB_AP_1(x, y) CHAOS_IP_SUB_AP_II(CHAOS_PP_MINUS(x, y), 1)
# define CHAOS_IP_SUB_AP_II(bin, c) CHAOS_IP_SUB_AP_III(CHAOS_PP_BINARY(0) bin, CHAOS_PP_MINUS(CHAOS_PP_BINARY(1) bin, c))
# define CHAOS_IP_SUB_AP_III(b, bin) (CHAOS_PP_BINARY(1) bin) CHAOS_PP_INDIRECT(CHAOS_PP_BITOR(b)(CHAOS_PP_BINARY(0) bin))
#
# endif
