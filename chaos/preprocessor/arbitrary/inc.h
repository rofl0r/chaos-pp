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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_INC_H
# define CHAOS_PREPROCESSOR_ARBITRARY_INC_H
#
# include <chaos/preprocessor/arbitrary/dec.h>
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/detail/special.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_INC */
#
# define CHAOS_PP_ARBITRARY_INC(x) CHAOS_IP_ARBITRARY_INC_I(CHAOS_PP_ARBITRARY_FIX(x))
# define CHAOS_PP_ARBITRARY_INC_ID() CHAOS_PP_ARBITRARY_INC
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_INC_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_INC)
# endif
#
# define CHAOS_IP_ARBITRARY_INC_I(x) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_PP_ARBITRARY_FIX((CHAOS_PP_ARBITRARY_DEC_INTERNAL(CHAOS_PP_REM x))), \
        CHAOS_PP_ARBITRARY_INC_INTERNAL(x) \
    ) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_INC_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_INC_INTERNAL(x) \
        CHAOS_PP_ARBITRARY_FIX_INTERNAL(CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_INC_A (0)x(00), CHAOS_IP_ARBITRARY_INC_IV CHAOS_PP_SPECIAL_CLOSE((0)x)) \
        )) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_INC_INTERNAL(x) \
        CHAOS_PP_ARBITRARY_FIX_INTERNAL(CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_INC_A (0)x(00) CHAOS_PP_EMPTY CHAOS_PP_DEFER(CHAOS_PP_COMMA)() CHAOS_IP_ARBITRARY_INC_IV CHAOS_PP_SPECIAL_CLOSE((0)x)) \
        )()) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARBITRARY_INC_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_INC_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_INC_B)
#    define CHAOS_IP_ARBITRARY_INC_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_INC_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_ARBITRARY_INC_A)
#    define CHAOS_IP_ARBITRARY_INC_II(...) CHAOS_IP_ARBITRARY_INC_III(__VA_ARGS__)
# else
#    define CHAOS_IP_ARBITRARY_INC_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_INC_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_INC_B)
#    define CHAOS_IP_ARBITRARY_INC_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_INC_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_ARBITRARY_INC_A)
#    define CHAOS_IP_ARBITRARY_INC_II(digit, im) CHAOS_IP_ARBITRARY_INC_III(digit, im)
# endif
#
# define CHAOS_IP_ARBITRARY_INC_III(digit, res, op) op(digit)(res)
# define CHAOS_IP_ARBITRARY_INC_IV(digit) CHAOS_IP_ARBITRARY_INC_ ## digit
# define CHAOS_IP_ARBITRARY_INC_V(digit) (digit) CHAOS_IP_ARBITRARY_INC_VI
# define CHAOS_IP_ARBITRARY_INC_VI(res) res, CHAOS_IP_ARBITRARY_INC_V
#
# define CHAOS_IP_ARBITRARY_INC_0(res) (1) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_1(res) (2) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_2(res) (3) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_3(res) (4) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_4(res) (5) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_5(res) (6) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_6(res) (7) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_7(res) (8) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_8(res) (9) res, CHAOS_IP_ARBITRARY_INC_V
# define CHAOS_IP_ARBITRARY_INC_9(res) (0) res, CHAOS_IP_ARBITRARY_INC_IV
#
# endif
