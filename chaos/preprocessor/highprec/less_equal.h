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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_LESS_EQUAL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_LESS_EQUAL_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/highprec/detail/digit.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_AUTO_LESS_EQUAL */
#
# define CHAOS_PP_AUTO_LESS_EQUAL(x, y) \
    CHAOS_PP_LESS_EQUAL_HP( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))(x, CHAOS_PP_PROMOTE_HP(x)), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))(y, CHAOS_PP_PROMOTE_HP(y)) \
    ) \
    /**/
# define CHAOS_PP_AUTO_LESS_EQUAL_ID() CHAOS_PP_AUTO_LESS_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_LESS_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_LESS_EQUAL)
# endif
#
# /* CHAOS_PP_LESS_EQUAL_HP */
#
# define CHAOS_PP_LESS_EQUAL_HP(x, y) \
    CHAOS_PP_CAT( \
        CHAOS_IP_LESS_EQUAL_HP_S_, CHAOS_PP_CAT( \
            CHAOS_PP_SIGN_HP(x), CHAOS_PP_SIGN_HP(y) \
        ) \
    )(CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y) \
    /**/
# define CHAOS_PP_LESS_EQUAL_HP_ID() CHAOS_PP_LESS_EQUAL_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LESS_EQUAL_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_LESS_EQUAL_HP)
# endif
#
# define CHAOS_IP_LESS_EQUAL_HP_S_00(x, y) CHAOS_PP_LESS_EQUAL_HP_INTERNAL(x, y)
# define CHAOS_IP_LESS_EQUAL_HP_S_01(x, y) 0
# define CHAOS_IP_LESS_EQUAL_HP_S_10(x, y) 1
# define CHAOS_IP_LESS_EQUAL_HP_S_11(x, y) CHAOS_PP_LESS_EQUAL_HP_INTERNAL(y, x)
#
# define CHAOS_PP_LESS_EQUAL_HP_INTERNAL(x, y) \
    CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_LESS_EQUAL_HP_I)( \
        CHAOS_IP_LESS_EQUAL_HP_M, CHAOS_PP_TUPLE_REM(10) x, CHAOS_PP_TUPLE_REM(10) y \
    )) \
    /**/
# define CHAOS_IP_LESS_EQUAL_HP_I(_, x9, x8, x7, x6, x5, x4, x3, x2, x1, x0, y9, y8, y7, y6, y5, y4, y3, y2, y1, y0) \
    CHAOS_PP_COMPL( \
        _(1) \
        (x9, y9)(_)(x8, y8)(_)(x7, y7)(_)(x6, y6)(_)(x5, y5)(_) \
        (x4, y4)(_)(x3, y3)(_)(x2, y2)(_)(x1, y1)(_)(x0, y0)(CHAOS_PP_DEC) \
    ) \
    /**/
# define CHAOS_IP_LESS_EQUAL_HP_M(x) CHAOS_IP_LESS_EQUAL_HP_ ## x
# define CHAOS_IP_LESS_EQUAL_HP_0(a, b) CHAOS_PP_INDIRECT(0)
# define CHAOS_IP_LESS_EQUAL_HP_1(a, b) CHAOS_PP_INDIRECT(CHAOS_IP_LESS_EQUAL_HP_C(a, b))
# define CHAOS_IP_LESS_EQUAL_HP_2(a, b) CHAOS_PP_INDIRECT(2)
#
# define CHAOS_IP_LESS_EQUAL_HP_C(a, b) \
    CHAOS_PP_DIGIT(a, CHAOS_PP_DIGIT(b, \
        ( \
            (1, 0, 0, 0, 0, 0, 0, 0, 0, 0), \
            (2, 1, 0, 0, 0, 0, 0, 0, 0, 0), \
            (2, 2, 1, 0, 0, 0, 0, 0, 0, 0), \
            (2, 2, 2, 1, 0, 0, 0, 0, 0, 0), \
            (2, 2, 2, 2, 1, 0, 0, 0, 0, 0), \
            (2, 2, 2, 2, 2, 1, 0, 0, 0, 0), \
            (2, 2, 2, 2, 2, 2, 1, 0, 0, 0), \
            (2, 2, 2, 2, 2, 2, 2, 1, 0, 0), \
            (2, 2, 2, 2, 2, 2, 2, 2, 1, 0), \
            (2, 2, 2, 2, 2, 2, 2, 2, 2, 1) \
        ) \
    )) \
    /**/
#
# endif
