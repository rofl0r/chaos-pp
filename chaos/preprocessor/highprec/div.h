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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DIV_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DIV_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/bool.h>
# include <chaos/preprocessor/highprec/demote.h>
# include <chaos/preprocessor/highprec/detail/digit.h>
# include <chaos/preprocessor/highprec/detail/divide.h>
# include <chaos/preprocessor/highprec/detail/fix.h>
# include <chaos/preprocessor/highprec/detail/length.h>
# include <chaos/preprocessor/highprec/detail/minus.h>
# include <chaos/preprocessor/highprec/detail/plus.h>
# include <chaos/preprocessor/highprec/less_equal.h>
# include <chaos/preprocessor/highprec/mul.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/highprec/sub.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitxor.h>
# include <chaos/preprocessor/logical/not.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/to_tuple.h>
#
# /* CHAOS_PP_AUTO_DIV */
#
# define CHAOS_PP_AUTO_DIV(x, y) CHAOS_PP_AUTO_DIV_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_AUTO_DIV_ID() CHAOS_PP_AUTO_DIV
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_DIV_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_DIV)
# endif
#
# /* CHAOS_PP_AUTO_DIV_BYPASS */
#
# define CHAOS_PP_AUTO_DIV_BYPASS(s, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_DIV_HP_BYPASS(s, x, y), \
            CHAOS_PP_DIV_HP_BYPASS(s, x, CHAOS_PP_PROMOTE_HP(y)) \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_DIV_HP_BYPASS(s, CHAOS_PP_PROMOTE_HP(x), y), \
            CHAOS_PP_DEMOTE_HP(CHAOS_PP_DIV_HP_BYPASS(s, CHAOS_PP_PROMOTE_HP(x), CHAOS_PP_PROMOTE_HP(y))) \
        ) \
    ) \
    /**/
# define CHAOS_PP_AUTO_DIV_BYPASS_ID() CHAOS_PP_AUTO_DIV_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_DIV_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_DIV_BYPASS)
# endif
#
# /* CHAOS_PP_DIV_HP */
#
# define CHAOS_PP_DIV_HP(x, y) CHAOS_PP_DIV_HP_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_DIV_HP_ID() CHAOS_PP_DIV_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_HP)
# endif
#
# /* CHAOS_PP_DIV_HP_BYPASS */
#
# define CHAOS_PP_DIV_HP_BYPASS(s, x, y) \
    CHAOS_PP_FIX_HP(( \
        CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_DIV_HP_INTERNAL(s, CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y)), \
        CHAOS_PP_BITXOR(CHAOS_PP_SIGN_HP(x))(CHAOS_PP_SIGN_HP(y)) \
    )) \
    /**/
# define CHAOS_PP_DIV_HP_BYPASS_ID() CHAOS_PP_DIV_HP_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_HP_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_HP_BYPASS)
# endif
#
# define CHAOS_PP_DIV_HP_INTERNAL(s, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_BOOL_HP_INTERNAL(y))( \
        CHAOS_PP_IIF(CHAOS_PP_LESS_EQUAL_HP_INTERNAL(y, x))( \
            CHAOS_IP_DIV_HP_1(s, x, y), \
            (x, (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)) \
        ), \
        CHAOS_PP_FAILURE() \
    ) \
    /**/
# define CHAOS_IP_DIV_HP_1(s, x, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_DEFER(CHAOS_IP_DIV_HP_4)( \
        CHAOS_PP_PREV(s), CHAOS_IP_DIV_HP_2(CHAOS_PP_LENGTH_HP_INTERNAL(x), CHAOS_PP_LENGTH_HP_INTERNAL(y), x, y) \
    )) \
    /**/
# define CHAOS_IP_DIV_HP_2(lx, ly, x, y) \
    CHAOS_IP_DIV_HP_3( \
        lx, ly, \
        CHAOS_PP_MINUS(CHAOS_PP_DEC(lx), CHAOS_PP_DEC(ly)), \
        CHAOS_PP_MINUS(9, CHAOS_PP_DEC(lx)), \
        CHAOS_PP_DEC(ly), \
        x, y \
    ) \
    /**/
# define CHAOS_IP_DIV_HP_3(lx, ly, shift, zx, zy, x, y) \
    zy, ly, CHAOS_PP_DIGIT(zy, y), \
    CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_MINUS( \
        9, CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_PLUS(CHAOS_PP_BINARY(1) zx, zy)) \
    )), \
    CHAOS_PP_CAT(CHAOS_IP_DIV_HP_SHIFT_, CHAOS_PP_BINARY(1) shift) x, x, y \
    /**/
# define CHAOS_IP_DIV_HP_SHIFT_0(a, b, c, d, e, f, g, h, i, j) (a, b, c, d, e, f, g, h, i, j)
# define CHAOS_IP_DIV_HP_SHIFT_1(a, b, c, d, e, f, g, h, i, j) (0, a, b, c, d, e, f, g, h, i)
# define CHAOS_IP_DIV_HP_SHIFT_2(a, b, c, d, e, f, g, h, i, j) (0, 0, a, b, c, d, e, f, g, h)
# define CHAOS_IP_DIV_HP_SHIFT_3(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, a, b, c, d, e, f, g)
# define CHAOS_IP_DIV_HP_SHIFT_4(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, 0, a, b, c, d, e, f)
# define CHAOS_IP_DIV_HP_SHIFT_5(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, 0, 0, a, b, c, d, e)
# define CHAOS_IP_DIV_HP_SHIFT_6(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, 0, 0, 0, a, b, c, d)
# define CHAOS_IP_DIV_HP_SHIFT_7(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, 0, 0, 0, 0, a, b, c)
# define CHAOS_IP_DIV_HP_SHIFT_8(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, 0, 0, 0, 0, 0, a, b)
# define CHAOS_IP_DIV_HP_SHIFT_9(a, b, c, d, e, f, g, h, i, j) (0, 0, 0, 0, 0, 0, 0, 0, 0, a)
#
# define CHAOS_IP_DIV_HP_4(s, zy, ly, first, digit, rem, x, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DIV_HP_5( \
        CHAOS_PP_PREV(s), CHAOS_IP_DIV_HP_JUMPER_ ## digit, digit, zy, ly, first, rem, x, y \
    )) \
    /**/
# define CHAOS_IP_DIV_HP_JUMPER_9(x) (x)
# define CHAOS_IP_DIV_HP_JUMPER_8 (0)
# define CHAOS_IP_DIV_HP_JUMPER_7 (0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_6 (0)(0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_5 (0)(0)(0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_4 (0)(0)(0)(0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_3 (0)(0)(0)(0)(0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_2 (0)(0)(0)(0)(0)(0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_1 (0)(0)(0)(0)(0)(0)(0)(0)
# define CHAOS_IP_DIV_HP_JUMPER_0 (0)(0)(0)(0)(0)(0)(0)(0)(0)
#
# define CHAOS_IP_DIV_HP_BRING(a, b, c, d, e, f, g, h, i, j) b, c, d, e, f, g, h, i, j
#
# define CHAOS_IP_DIV_HP_5_INDIRECT() CHAOS_IP_DIV_HP_5
# define CHAOS_IP_DIV_HP_5(s, r, d, zy, ly, first, rem, x, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_DEFER(CHAOS_PP_IF(d)(CHAOS_IP_DIV_HP_6, CHAOS_IP_DIV_HP_7))( \
        CHAOS_PP_PREV(s), r, CHAOS_PP_DEC(d), rem, CHAOS_IP_DIV_HP_C1(s, zy, ly, first, rem, y), zy, ly, first, x, y \
    )) \
    /**/
# define CHAOS_IP_DIV_HP_6(s, r, d, rem, digit, res, zy, ly, first, x, y) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_DIV_HP_5_INDIRECT)()( \
        CHAOS_PP_PREV(s), r(digit), d, zy, ly, first, \
        (CHAOS_PP_EXPR_S(s)(CHAOS_IP_DIV_HP_BRING CHAOS_PP_SUB_HP_INTERNAL(rem, res)), CHAOS_PP_DIGIT(d, x)), x, y \
    )) \
    /**/
# define CHAOS_IP_DIV_HP_7(s, r, d, rem, digit, res, zy, ly, first, x, y) \
    (CHAOS_PP_SUB_HP_INTERNAL(rem, res), CHAOS_PP_SEQ_TO_TUPLE(r(digit))) \
    /**/
#
# define CHAOS_IP_DIV_HP_C1(s, zy, ly, first, rem, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DIV_HP_C2(s, CHAOS_PP_DIVIDE(CHAOS_PP_DIGIT(ly, rem), CHAOS_PP_DIGIT(zy, rem), first), y, rem)) \
    /**/
# define CHAOS_IP_DIV_HP_C2_INDIRECT() CHAOS_IP_DIV_HP_C2
# define CHAOS_IP_DIV_HP_C2(s, initial, y, rem) \
    CHAOS_IP_DIV_HP_C3(CHAOS_PP_OBSTRUCT(), s, CHAOS_IP_DIV_HP_MUL(s, CHAOS_IP_MUL_HP_F_M, initial, CHAOS_PP_TUPLE_REM(10) y), y, rem, initial) \
    /**/
# define CHAOS_IP_DIV_HP_C3(_, s, res, y, rem, initial) \
    CHAOS_PP_IIF _( \
        CHAOS_PP_IIF _(CHAOS_PP_BINARY(1) res)( \
            CHAOS_PP_LESS_EQUAL_HP_INTERNAL _(CHAOS_PP_BINARY(0) res, rem), 0 \
        ) \
    )( \
        CHAOS_PP_TUPLE_REM(2) _(initial, CHAOS_PP_BINARY(0) res), \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_DIV_HP_C2_INDIRECT _()( \
            CHAOS_PP_PREV(s), CHAOS_PP_DEC(initial), y, rem \
        )) \
    ) \
    /**/
#
# define CHAOS_IP_DIV_HP_MUL(s, _, fx, im) CHAOS_IP_DIV_HP_MUL_I(s, _, fx, im)
# define CHAOS_IP_DIV_HP_MUL_I(s, _, fx, a, b, c, d, e, f, g, h, i, j) \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_DEFER(CHAOS_IP_DIV_HP_MUL_II)( \
        _(0) \
        (fx, j)(_)(fx, i)(_)(fx, h)(_)(fx, g)(_)(fx, f)(_) \
        (fx, e)(_)(fx, d)(_)(fx, c)(_)(fx, b)(_)(fx, a)(CHAOS_PP_NOT) \
    )) \
    /**/
# define CHAOS_IP_DIV_HP_MUL_II(j, i, h, g, f, e, d, c, b, a, overflow) ((a, b, c, d, e, f, g, h, i, j), overflow)
#
# endif
