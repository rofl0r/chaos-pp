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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DIV_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DIV_H
#
# include <chaos/preprocessor/arbitrary/bool.h>
# include <chaos/preprocessor/arbitrary/detail/divide.h>
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/detail/special.h>
# include <chaos/preprocessor/arbitrary/equal.h>
# include <chaos/preprocessor/arbitrary/less.h>
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/arbitrary/mul.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/arbitrary/sub.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_DIV_AP */
#
# define CHAOS_PP_DIV_AP(x, y) CHAOS_IP_DIV_AP_I(CHAOS_PP_FIX_AP(x), CHAOS_PP_FIX_AP(y))
# define CHAOS_PP_DIV_AP_ID() CHAOS_PP_DIV_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_AP)
# endif
#
# define CHAOS_IP_DIV_AP_I(x, y) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_BITXOR(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_SIGN_AP(y)))( \
        CHAOS_PP_REM \
    )(CHAOS_PP_DIV_AP_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_REM) x, \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(y))(CHAOS_PP_REM) y \
    )) \
    /**/
#
# /* CHAOS_PP_DIV_AP_INTERNAL */
#
# define CHAOS_PP_DIV_AP_INTERNAL(x, y) \
    CHAOS_PP_FIX_AP(CHAOS_PP_BINARY_CTOR(0, CHAOS_IP_DIV_AP_1(x, y))) \
    /**/
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_DIV_AP_1(x, y) \
        CHAOS_PP_IIF(CHAOS_PP_BOOL_AP_INTERNAL(y))( \
            CHAOS_PP_IIF(CHAOS_PP_LESS_AP_INTERNAL(x, y))( \
                ((0), x), \
                CHAOS_PP_IIF(CHAOS_PP_EQUAL_AP_INTERNAL(x, y))( \
                    ((1), (0)), \
                    CHAOS_PP_SCAN(2)(CHAOS_PP_DEFER(CHAOS_IP_DIV_AP_3)( \
                        y, CHAOS_PP_SCAN(1)(CHAOS_IP_DIV_AP_A y(00) CHAOS_IP_DIV_AP_2(CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), x, y,) CHAOS_PP_SPECIAL_CLOSE(y)) \
                    )) \
                ) \
            ), \
            CHAOS_PP_FAILURE() \
        ) \
        /**/
#    define CHAOS_IP_DIV_AP_2(_, x, y, rem) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(y))( \
            CHAOS_IP_DIV_AP_INDIRECT _(2)( \
                CHAOS_PP_DEFER _(CHAOS_PP_OBSTRUCT)(), CHAOS_PP_EAT x, CHAOS_PP_EAT y, rem _(CHAOS_PP_SEQ_FIRST _(x)) \
            ), \
            CHAOS_PP_INLINE_UNLESS _(CHAOS_PP_IS_UNARY _(CHAOS_PP_EAT _ rem))((0)) rem, x \
        ) \
        /**/
#    define CHAOS_IP_DIV_AP_3(y, rem, pool) \
        CHAOS_PP_SCAN(3)(CHAOS_IP_DIV_AP_X (0)pool(00)(CHAOS_IP_DIV_AP_4(y, CHAOS_PP_SEQ_FIRST(y), rem, pool)) CHAOS_PP_SPECIAL_CLOSE((0)pool)) \
        /**/
#    define CHAOS_IP_DIV_AP_5(y, digit, est, rem, pool) \
        CHAOS_IP_DIV_AP_6( \
            y, digit, est, \
            CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
                CHAOS_IP_MUL_AP_M(0) CHAOS_PP_RMERGE(y, (est), CHAOS_IP_MUL_AP_M, est)() \
            ))), \
            rem, pool \
        ) \
        /**/
#    define CHAOS_IP_DIV_AP_7(y, digit, diff, pool) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(pool))( \
            CHAOS_IP_DIV_AP_INDIRECT CHAOS_PP_OBSTRUCT()(4)( \
                y, digit, diff(CHAOS_PP_SEQ_FIRST(pool)), CHAOS_PP_EAT pool \
            ), \
            , diff \
        ) \
        /**/
# else
#    define CHAOS_IP_DIV_AP_ID(x) (x)
#    define CHAOS_IP_DIV_AP_1(x, y) \
        CHAOS_PP_IIF(CHAOS_PP_BOOL_AP_INTERNAL(y))( \
            CHAOS_PP_IIF(CHAOS_PP_LESS_AP_INTERNAL(x, y))( \
                ((0), x), \
                CHAOS_PP_IIF(CHAOS_PP_EQUAL_AP_INTERNAL(x, y))( \
                    ((1), (0)), \
                    CHAOS_PP_SCAN(2)(CHAOS_PP_DEFER(CHAOS_IP_DIV_AP_3)( \
                        y, CHAOS_PP_SCAN(1)(CHAOS_IP_DIV_AP_A y(00) CHAOS_IP_DIV_AP_2(CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), x CHAOS_PP_EMPTY, y ~, CHAOS_IP_DIV_AP_ID) CHAOS_PP_SPECIAL_CLOSE(y)) \
                    )) \
                ) \
            ), \
            CHAOS_PP_FAILURE() \
        ) \
        /**/
#    define CHAOS_IP_DIV_AP_2(_, x, y, rem) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(y))( \
            CHAOS_IP_DIV_AP_INDIRECT _(2)( \
                CHAOS_PP_DEFER _(CHAOS_PP_OBSTRUCT)(), CHAOS_PP_EAT x, CHAOS_PP_EAT y, rem _(CHAOS_PP_SEQ_FIRST _(x)) \
            ), \
            CHAOS_PP_INLINE_UNLESS _(CHAOS_PP_IS_UNARY _(CHAOS_PP_EAT _ rem ~))((0)) rem CHAOS_PP_COMMA _() x \
        ) \
        /**/
#    define CHAOS_IP_DIV_AP_3(y, rem, pool) \
        CHAOS_PP_SCAN(3)(CHAOS_IP_DIV_AP_X (0)pool()(00) (CHAOS_IP_DIV_AP_4(y, CHAOS_PP_SEQ_FIRST(y), rem, pool() ~)) CHAOS_PP_SPECIAL_CLOSE((0)pool())) \
        /**/
#    define CHAOS_IP_DIV_AP_5(y, digit, est, rem, pool) \
        CHAOS_IP_DIV_AP_6( \
            y, digit, est, \
            CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
                CHAOS_IP_MUL_AP_M(0) CHAOS_PP_RMERGE(y, (est), CHAOS_IP_MUL_AP_M, est)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
            ))), \
            rem, pool \
        ) \
        /**/
#    define CHAOS_IP_DIV_AP_7(y, digit, diff, pool) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(pool))( \
            CHAOS_IP_DIV_AP_INDIRECT CHAOS_PP_OBSTRUCT()(4)( \
                y, digit, diff(CHAOS_PP_SEQ_FIRST(pool)), CHAOS_PP_EAT pool \
            ), \
            CHAOS_PP_COMMA() diff \
        ) \
        /**/
# endif
#
# define CHAOS_IP_DIV_MULTISCAN(x) \
    CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)( \
        CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(CHAOS_PP_SCAN(4)(x))))) \
    ))))) \
    /**/
#
# define CHAOS_IP_DIV_AP_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_SCAN(2) CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_DIV_AP_B)
# define CHAOS_IP_DIV_AP_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_SCAN(2) CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_DIV_AP_A)
# define CHAOS_IP_DIV_AP_X(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_DIV_MULTISCAN CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_DIV_AP_Y)
# define CHAOS_IP_DIV_AP_Y(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_DIV_MULTISCAN CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_DIV_AP_X)
#
# define CHAOS_IP_DIV_AP_INDIRECT(n) CHAOS_IP_DIV_AP_ ## n
#
# define CHAOS_IP_DIV_AP_4(y, digit, rem, pool) \
    CHAOS_IP_DIV_AP_5(y, digit, CHAOS_PP_DIVIDE(CHAOS_PP_SEQ_FIRST(rem), CHAOS_PP_SEQ_FIRST(CHAOS_PP_EAT rem), digit), rem, pool) \
    /**/
# define CHAOS_IP_DIV_AP_6(y, digit, est, trial, rem, pool) \
    CHAOS_PP_IIF(CHAOS_PP_LESS_EQUAL_AP_INTERNAL(trial, rem))( \
        (est) CHAOS_IP_DIV_AP_7, \
        CHAOS_IP_DIV_AP_INDIRECT CHAOS_PP_OBSTRUCT()(5)( \
            y, digit, CHAOS_PP_DEC(est), rem, pool \
        ) CHAOS_PP_TUPLE_EAT(4) \
    )(y, digit, CHAOS_PP_SUB_AP_INTERNAL(rem, trial), pool) \
    /**/
#
# endif
