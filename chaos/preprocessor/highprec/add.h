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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_ADD_H
# define CHAOS_PREPROCESSOR_HIGHPREC_ADD_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/highprec/demote.h>
# include <chaos/preprocessor/highprec/detail/digit.h>
# include <chaos/preprocessor/highprec/detail/fix.h>
# include <chaos/preprocessor/highprec/detail/plus.h>
# include <chaos/preprocessor/highprec/less_equal.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/highprec/sub.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_AUTO_ADD */
#
# define CHAOS_PP_AUTO_ADD(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_ADD_HP(x, y), \
            CHAOS_PP_ADD_HP(x, CHAOS_PP_PROMOTE_HP(y)) \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_ADD_HP(CHAOS_PP_PROMOTE_HP(x), y), \
            CHAOS_PP_DEMOTE_HP(CHAOS_PP_ADD_HP(CHAOS_PP_PROMOTE_HP(x), CHAOS_PP_PROMOTE_HP(y))) \
        ) \
    ) \
    /**/
# define CHAOS_PP_AUTO_ADD_ID() CHAOS_PP_AUTO_ADD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_ADD_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_ADD)
# endif
#
# /* CHAOS_PP_ADD_HP */
#
# define CHAOS_PP_ADD_HP(x, y) \
    CHAOS_PP_FIX_HP(CHAOS_PP_CAT( \
        CHAOS_IP_ADD_HP_S_, CHAOS_PP_CAT( \
            CHAOS_PP_SIGN_HP(x), CHAOS_PP_SIGN_HP(y) \
        ) \
    )(CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y)) \
    /**/
# define CHAOS_PP_ADD_HP_ID() CHAOS_PP_ADD_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD_HP)
# endif
#
# define CHAOS_IP_ADD_HP_S_00(x, y) (CHAOS_PP_ADD_HP_INTERNAL(x, y), 0)
# define CHAOS_IP_ADD_HP_S_01(x, y) CHAOS_IP_ADD_HP_S_10(y, x)
# define CHAOS_IP_ADD_HP_S_10(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_LESS_EQUAL_HP_INTERNAL(x, y))( \
        (CHAOS_PP_SUB_HP_INTERNAL(y, x), 0), (CHAOS_PP_SUB_HP_INTERNAL(x, y), 1) \
    ) \
    /**/
# define CHAOS_IP_ADD_HP_S_11(x, y) (CHAOS_PP_ADD_HP_INTERNAL(x, y), 1)
#
# define CHAOS_PP_ADD_HP_INTERNAL(x, y) \
    CHAOS_PP_EXPAND(CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_ADD_HP_I)( \
        CHAOS_IP_ADD_HP_M, CHAOS_PP_TUPLE_REM(10) x, CHAOS_PP_TUPLE_REM(10) y \
    ))) \
    /**/
# define CHAOS_IP_ADD_HP_I(_, x9, x8, x7, x6, x5, x4, x3, x2, x1, x0, y9, y8, y7, y6, y5, y4, y3, y2, y1, y0) \
    CHAOS_PP_DEFER(CHAOS_IP_ADD_HP_II)( \
        _(0) \
        (x0, y0)(_)(x1, y1)(_)(x2, y2)(_)(x3, y3)(_)(x4, y4)(_) \
        (x5, y5)(_)(x6, y6)(_)(x7, y7)(_)(x8, y8)(_)(x9, y9)(CHAOS_PP_TUPLE_REM(1)) \
    ) \
    /**/
# define CHAOS_IP_ADD_HP_II(j, i, h, g, f, e, d, c, b, a, overflow) \
    CHAOS_PP_EXPR_IIF(overflow)(CHAOS_PP_FAILURE())(a, b, c, d, e, f, g, h, i, j) \
    /**/
# define CHAOS_IP_ADD_HP_M(x) CHAOS_IP_ADD_HP_ ## x
# define CHAOS_IP_ADD_HP_0(x, y) CHAOS_PP_PLUS_3RD(0)(CHAOS_PP_PLUS(x, y))
# define CHAOS_IP_ADD_HP_1(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_PLUS(x, y), 1)
#
# endif
