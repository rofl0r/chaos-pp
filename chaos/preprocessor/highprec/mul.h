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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_MUL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_MUL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/highprec/demote.h>
# include <chaos/preprocessor/highprec/detail/digit.h>
# include <chaos/preprocessor/highprec/detail/fix.h>
# include <chaos/preprocessor/highprec/detail/plus.h>
# include <chaos/preprocessor/highprec/detail/times.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitxor.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/size.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_AUTO_MUL */
#
# define CHAOS_PP_AUTO_MUL(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_MUL_HP(x, y), \
            CHAOS_PP_MUL_HP(x, CHAOS_PP_PROMOTE_HP(y)) \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_MUL_HP(CHAOS_PP_PROMOTE_HP(x), y), \
            CHAOS_PP_DEMOTE_HP(CHAOS_PP_MUL_HP(CHAOS_PP_PROMOTE_HP(x), CHAOS_PP_PROMOTE_HP(y))) \
        ) \
    ) \
    /**/
# define CHAOS_PP_AUTO_MUL_ID() CHAOS_PP_AUTO_MUL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_MUL_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_MUL)
# endif
#
# /* CHAOS_PP_MUL_HP */
#
# define CHAOS_PP_MUL_HP(x, y) \
    CHAOS_PP_FIX_HP(( \
        CHAOS_PP_MUL_HP_INTERNAL(CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y), \
        CHAOS_PP_BITXOR(CHAOS_PP_SIGN_HP(x))(CHAOS_PP_SIGN_HP(y)) \
    )) \
    /**/
#
# define CHAOS_PP_MUL_HP_INTERNAL(x, y) \
    CHAOS_IP_MUL_HP_I( \
        CHAOS_IP_MUL_HP_OPT_M, CHAOS_IP_MUL_HP_COL_M, \
        CHAOS_IP_MUL_HP_F(0, x, y), CHAOS_IP_MUL_HP_F(1, x, y), CHAOS_IP_MUL_HP_F(2, x, y), CHAOS_IP_MUL_HP_F(3, x, y), CHAOS_IP_MUL_HP_F(4, x, y), \
        CHAOS_IP_MUL_HP_F(5, x, y), CHAOS_IP_MUL_HP_F(6, x, y), CHAOS_IP_MUL_HP_F(7, x, y), CHAOS_IP_MUL_HP_F(8, x, y), CHAOS_IP_MUL_HP_F(9, x, y) \
    ) \
    /**/
# define CHAOS_IP_MUL_HP_I(o, _, a, b, c, d, e, f, g, h, i, j) CHAOS_IP_MUL_HP_II(o, _, a, b, c, d, e, f, g, h, i, j)
# define CHAOS_IP_MUL_HP_II( \
        o, _, \
        a9, a8, a7, a6, a5, a4, a3, a2, a1, a0, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, \
        c9, c8, c7, c6, c5, c4, c3, c2, c1, c0, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, \
        e9, e8, e7, e6, e5, e4, e3, e2, e1, e0, f9, f8, f7, f6, f5, f4, f3, f2, f1, f0, \
        g9, g8, g7, g6, g5, g4, g3, g2, g1, g0, h9, h8, h7, h6, h5, h4, h3, h2, h1, h0, \
        i9, i8, i7, i6, i5, i4, i3, i2, i1, i0, j9, j8, j7, j6, j5, j4, j3, j2, j1, j0 \
    ) \
    CHAOS_IP_MUL_HP_OVERFLOW_L2( \
        CHAOS_IP_MUL_HP_OVERFLOW_L2_ \
        ## b9 ## c9 ## c8 ## d9 ## d8 ## d7 ## e9 ## e8 ## e7 \
        ## e6 ## f9 ## f8 ## f7 ## f6 ## f5 ## g9 ## g8 ## g7 \
        ## g6 ## g5 ## g4 ## h9 ## h8 ## h7 ## h6 ## h5 ## h4 \
        ## h3 ## i9 ## i8 ## i7 ## i6 ## i5 ## i4 ## i3 ## i2 \
        ## j9 ## j8 ## j7 ## j6 ## j5 ## j4 ## j3 ## j2 ## j1 \
    ) \
    CHAOS_IP_MUL_HP_III( \
        o(0) \
        ((a0))(o) \
        ((a1)(_)(b0))(o) \
        ((a2)(_)(b1)(_)(c0))(o) \
        ((a3)(_)(b2)(_)(c1)(_)(d0))(o) \
        ((a4)(_)(b3)(_)(c2)(_)(d1)(_)(e0))(o) \
        ((a5)(_)(b4)(_)(c3)(_)(d2)(_)(e1)(_)(f0))(o) \
        ((a6)(_)(b5)(_)(c4)(_)(d3)(_)(e2)(_)(f1)(_)(g0))(o) \
        ((a7)(_)(b6)(_)(c5)(_)(d4)(_)(e3)(_)(f2)(_)(g1)(_)(h0))(o) \
        ((a8)(_)(b7)(_)(c6)(_)(d5)(_)(e4)(_)(f3)(_)(g2)(_)(h1)(_)(i0))(o) \
        ((a9)(_)(b8)(_)(c7)(_)(d6)(_)(e5)(_)(f4)(_)(g3)(_)(h2)(_)(i1)(_)(j0))(CHAOS_PP_BOOL) \
    ) \
    /**/
# define CHAOS_IP_MUL_HP_III(im) (CHAOS_IP_MUL_HP_F_II(im))
#
# define CHAOS_IP_MUL_HP_OVERFLOW()
#
# define CHAOS_IP_MUL_HP_OVERFLOW_L2(x) CHAOS_IP_MUL_HP_OVERFLOW(x)
# define CHAOS_IP_MUL_HP_OVERFLOW_L2_000000000000000000000000000000000000000000000
#
# define CHAOS_IP_MUL_HP_F(d, x, y) \
    CHAOS_PP_EXPAND(CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_MUL_HP_F_I)( \
        CHAOS_PP_DIGIT(d, y), CHAOS_PP_TUPLE_REM(10) x, CHAOS_IP_MUL_HP_F_M \
    ))) \
    /**/
# define CHAOS_IP_MUL_HP_F_I(fx, a, b, c, d, e, f, g, h, i, j, _) \
    CHAOS_PP_DEFER(CHAOS_IP_MUL_HP_F_II)( \
        _(0) \
        (fx, j)(_)(fx, i)(_)(fx, h)(_)(fx, g)(_)(fx, f)(_) \
        (fx, e)(_)(fx, d)(_)(fx, c)(_)(fx, b)(_)(fx, a)(CHAOS_PP_BOOL) \
    ) \
    /**/
# define CHAOS_IP_MUL_HP_F_II(j, i, h, g, f, e, d, c, b, a, overflow) \
    CHAOS_PP_EXPR_IIF(overflow)(CHAOS_IP_MUL_HP_OVERFLOW(!)) \
    a, b, c, d, e, f, g, h, i, j \
    /**/
#
# define CHAOS_IP_MUL_HP_F_M(x) CHAOS_IP_MUL_HP_ ## x
# define CHAOS_IP_MUL_HP_0(f, x) CHAOS_PP_PLUS_3RD(0)(CHAOS_PP_TIMES(f, x))
# define CHAOS_IP_MUL_HP_1(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 1)
# define CHAOS_IP_MUL_HP_2(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 2)
# define CHAOS_IP_MUL_HP_3(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 3)
# define CHAOS_IP_MUL_HP_4(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 4)
# define CHAOS_IP_MUL_HP_5(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 5)
# define CHAOS_IP_MUL_HP_6(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 6)
# define CHAOS_IP_MUL_HP_7(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 7)
# define CHAOS_IP_MUL_HP_8(f, x) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(f, x), 8)
#
# define CHAOS_IP_MUL_HP_COL_M(x) CHAOS_IP_MUL_HP_COL_ ## x
# define CHAOS_IP_MUL_HP_COL_0(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 0))
# define CHAOS_IP_MUL_HP_COL_1(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 1))
# define CHAOS_IP_MUL_HP_COL_2(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 2))
# define CHAOS_IP_MUL_HP_COL_3(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 3))
# define CHAOS_IP_MUL_HP_COL_4(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 4))
# define CHAOS_IP_MUL_HP_COL_5(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 5))
# define CHAOS_IP_MUL_HP_COL_6(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 6))
# define CHAOS_IP_MUL_HP_COL_7(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 7))
# define CHAOS_IP_MUL_HP_COL_8(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 8))
# define CHAOS_IP_MUL_HP_COL_9(x) CHAOS_IP_MUL_HP_COL_I(CHAOS_PP_PLUS(x, 9))
#
# define CHAOS_IP_MUL_HP_COL_I(bin) CHAOS_PP_EXPR_IIF(CHAOS_PP_BINARY(0) bin)((+)) CHAOS_PP_INDIRECT(CHAOS_PP_BINARY(1) bin)
#
# define CHAOS_IP_MUL_HP_OPT_M(x) CHAOS_IP_MUL_HP_OPT_ ## x
# define CHAOS_IP_MUL_HP_OPT_0(col) CHAOS_IP_MUL_HP_OPT_I(0, col)
# define CHAOS_IP_MUL_HP_OPT_1(col) CHAOS_IP_MUL_HP_OPT_I(1, col)
# define CHAOS_IP_MUL_HP_OPT_2(col) CHAOS_IP_MUL_HP_OPT_I(2, col)
# define CHAOS_IP_MUL_HP_OPT_3(col) CHAOS_IP_MUL_HP_OPT_I(3, col)
# define CHAOS_IP_MUL_HP_OPT_4(col) CHAOS_IP_MUL_HP_OPT_I(4, col)
# define CHAOS_IP_MUL_HP_OPT_5(col) CHAOS_IP_MUL_HP_OPT_I(5, col)
# define CHAOS_IP_MUL_HP_OPT_6(col) CHAOS_IP_MUL_HP_OPT_I(6, col)
# define CHAOS_IP_MUL_HP_OPT_7(col) CHAOS_IP_MUL_HP_OPT_I(7, col)
# define CHAOS_IP_MUL_HP_OPT_8(col) CHAOS_IP_MUL_HP_OPT_I(8, col)
# define CHAOS_IP_MUL_HP_OPT_9(col) CHAOS_IP_MUL_HP_OPT_I(9, col)
#
# define CHAOS_IP_MUL_HP_OPT_I(n, col) CHAOS_IP_MUL_HP_OPT_II((+) CHAOS_IP_MUL_HP_COL_ ## n col(CHAOS_PP_COMMA() CHAOS_PP_TUPLE_REM(1)))
# define CHAOS_IP_MUL_HP_OPT_II(im) CHAOS_IP_MUL_HP_OPT_III(im)
# define CHAOS_IP_MUL_HP_OPT_III(seq, digit) digit, CHAOS_PP_INDIRECT(CHAOS_PP_SEQ_SIZE(CHAOS_PP_TUPLE_EAT(1) seq))
#
# endif
