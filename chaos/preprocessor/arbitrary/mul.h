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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_MUL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_MUL_H
#
# include <chaos/preprocessor/arbitrary/add.h>
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/plus.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/detail/special.h>
# include <chaos/preprocessor/arbitrary/detail/times.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitxor.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/elem.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_MUL */
#
# define CHAOS_PP_ARBITRARY_MUL(x, y) CHAOS_IP_ARBITRARY_MUL_I(CHAOS_PP_ARBITRARY_FIX(x), CHAOS_PP_ARBITRARY_FIX(y))
# define CHAOS_PP_ARBITRARY_MUL_ID() CHAOS_PP_ARBITRARY_MUL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_MUL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_MUL)
# endif
#
# define CHAOS_IP_ARBITRARY_MUL_I(x, y) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_BITXOR(CHAOS_PP_ARBITRARY_SIGN(x))(CHAOS_PP_ARBITRARY_SIGN(y)))( \
        CHAOS_PP_REM \
    )(CHAOS_PP_ARBITRARY_MUL_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(x))(CHAOS_PP_REM) x, \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(y))(CHAOS_PP_REM) y \
    )) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_MUL_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_MUL_INTERNAL(x, y) \
        CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_SCAN(2)(CHAOS_IP_ARBITRARY_MUL_A x(00), y,, CHAOS_PP_BINARY(1) CHAOS_PP_SPECIAL_CLOSE(x)) \
        ) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_MUL_INTERNAL(x, y) \
        CHAOS_PP_TUPLE_ELEM( \
            4, 0, \
            (CHAOS_PP_SCAN(2)( \
                CHAOS_IP_ARBITRARY_MUL_A x(00) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM)(4)(~, y, (), CHAOS_PP_BINARY(1)) CHAOS_PP_SPECIAL_CLOSE(x) \
            )) \
        ) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARBITRARY_MUL_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_MUL_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_MUL_B)
#    define CHAOS_IP_ARBITRARY_MUL_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_MUL_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_MUL_A)
#    define CHAOS_IP_ARBITRARY_MUL_II(...) CHAOS_IP_ARBITRARY_MUL_III(__VA_ARGS__)
#    define CHAOS_IP_ARBITRARY_MUL_III(digit, res, y, shift, add) \
        add( \
            res, \
            CHAOS_PP_ARBITRARY_FIX_INTERNAL( \
                CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
                    CHAOS_IP_ARBITRARY_MUL_M(0) CHAOS_PP_RMERGE(y, (digit), CHAOS_IP_ARBITRARY_MUL_M, digit)() \
                )) \
                shift \
            ) \
        ), \
        y, shift(0), CHAOS_PP_ARBITRARY_ADD_INTERNAL \
        /**/
# else
#    define CHAOS_IP_ARBITRARY_MUL_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_MUL_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_MUL_B)
#    define CHAOS_IP_ARBITRARY_MUL_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_MUL_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_MUL_A)
#    define CHAOS_IP_ARBITRARY_MUL_II(digit, im) CHAOS_IP_ARBITRARY_MUL_III(digit, im)
#    define CHAOS_IP_ARBITRARY_MUL_III(digit, res, y, shift, add) \
        add( \
            res, \
            CHAOS_PP_ARBITRARY_FIX_INTERNAL( \
                CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
                    CHAOS_IP_ARBITRARY_MUL_M(0) CHAOS_PP_RMERGE(y, (digit), CHAOS_IP_ARBITRARY_MUL_M, digit)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
                )) \
                CHAOS_PP_EMPTY shift \
            ) \
        ), \
        y, shift(0), CHAOS_PP_ARBITRARY_ADD_INTERNAL \
        /**/
# endif
#
# define CHAOS_IP_ARBITRARY_MUL_M(carry) CHAOS_IP_ARBITRARY_MUL_ ## carry
# define CHAOS_IP_ARBITRARY_MUL_0(x, y) CHAOS_PP_PLUS_3RD(0)(CHAOS_PP_TIMES(x, y))
# define CHAOS_IP_ARBITRARY_MUL_1(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 1)
# define CHAOS_IP_ARBITRARY_MUL_2(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 2)
# define CHAOS_IP_ARBITRARY_MUL_3(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 3)
# define CHAOS_IP_ARBITRARY_MUL_4(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 4)
# define CHAOS_IP_ARBITRARY_MUL_5(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 5)
# define CHAOS_IP_ARBITRARY_MUL_6(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 6)
# define CHAOS_IP_ARBITRARY_MUL_7(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 7)
# define CHAOS_IP_ARBITRARY_MUL_8(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 8)
#
# endif
