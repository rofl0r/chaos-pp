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
# /* CHAOS_PP_MUL_AP */
#
# define CHAOS_PP_MUL_AP(x, y) CHAOS_IP_MUL_AP_I(CHAOS_PP_FIX_AP(x), CHAOS_PP_FIX_AP(y))
# define CHAOS_PP_MUL_AP_ID() CHAOS_PP_MUL_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_AP)
# endif
#
# define CHAOS_IP_MUL_AP_I(x, y) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_BITXOR(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_SIGN_AP(y)))( \
        CHAOS_PP_REM \
    )(CHAOS_PP_MUL_AP_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(x))(CHAOS_PP_REM) x, \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(y))(CHAOS_PP_REM) y \
    )) \
    /**/
#
# /* CHAOS_PP_MUL_AP_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_AP_INTERNAL(x, y) \
        CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_SCAN(2)(CHAOS_IP_MUL_AP_A x(00), y,, CHAOS_PP_BINARY(1) CHAOS_PP_SPECIAL_CLOSE(x)) \
        ) \
        /**/
# else
#    define CHAOS_PP_MUL_AP_INTERNAL(x, y) \
        CHAOS_PP_TUPLE_ELEM( \
            4, 0, \
            (CHAOS_PP_SCAN(2)( \
                CHAOS_IP_MUL_AP_A x(00) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM)(4)(~, y, (), CHAOS_PP_BINARY(1)) CHAOS_PP_SPECIAL_CLOSE(x) \
            )) \
        ) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_MUL_AP_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_MUL_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_MUL_AP_B)
#    define CHAOS_IP_MUL_AP_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_MUL_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_MUL_AP_A)
#    define CHAOS_IP_MUL_AP_II(...) CHAOS_IP_MUL_AP_III(__VA_ARGS__)
#    define CHAOS_IP_MUL_AP_III(digit, res, y, shift, add) \
        add( \
            res, \
            CHAOS_PP_FIX_AP_INTERNAL( \
                CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
                    CHAOS_IP_MUL_AP_M(0) CHAOS_PP_RMERGE(y, (digit), CHAOS_IP_MUL_AP_M, digit)() \
                )) \
                shift \
            ) \
        ), \
        y, shift(0), CHAOS_PP_ADD_AP_INTERNAL \
        /**/
# else
#    define CHAOS_IP_MUL_AP_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_MUL_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_MUL_AP_B)
#    define CHAOS_IP_MUL_AP_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_MUL_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_MUL_AP_A)
#    define CHAOS_IP_MUL_AP_II(digit, im) CHAOS_IP_MUL_AP_III(digit, im)
#    define CHAOS_IP_MUL_AP_III(digit, res, y, shift, add) \
        add( \
            res, \
            CHAOS_PP_FIX_AP_INTERNAL( \
                CHAOS_PP_SEQ_REVERSE(CHAOS_PP_SCAN(1)( \
                    CHAOS_IP_MUL_AP_M(0) CHAOS_PP_RMERGE(y, (digit), CHAOS_IP_MUL_AP_M, digit)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
                )) \
                CHAOS_PP_EMPTY shift \
            ) \
        ), \
        y, shift(0), CHAOS_PP_ADD_AP_INTERNAL \
        /**/
# endif
#
# define CHAOS_IP_MUL_AP_M(carry) CHAOS_IP_MUL_AP_ ## carry
# define CHAOS_IP_MUL_AP_0(x, y) CHAOS_PP_PLUS_3RD(0)(CHAOS_PP_TIMES(x, y))
# define CHAOS_IP_MUL_AP_1(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 1)
# define CHAOS_IP_MUL_AP_2(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 2)
# define CHAOS_IP_MUL_AP_3(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 3)
# define CHAOS_IP_MUL_AP_4(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 4)
# define CHAOS_IP_MUL_AP_5(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 5)
# define CHAOS_IP_MUL_AP_6(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 6)
# define CHAOS_IP_MUL_AP_7(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 7)
# define CHAOS_IP_MUL_AP_8(x, y) CHAOS_PP_PLUS_3RD(1)(CHAOS_PP_TIMES(x, y), 8)
#
# endif
