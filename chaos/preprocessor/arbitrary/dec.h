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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DEC_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DEC_H
#
# include <chaos/_preprocessor/arbitrary/detail/fix.h>
# include <chaos/_preprocessor/arbitrary/detail/scan.h>
# include <chaos/_preprocessor/arbitrary/detail/special.h>
# include <chaos/_preprocessor/arbitrary/inc.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_DEC_AP */
#
# define CHAOS_PP_DEC_AP(x) CHAOS_IP_DEC_AP_I(CHAOS_PP_FIX_AP(x))
# define CHAOS_PP_DEC_AP_ID() CHAOS_PP_DEC_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEC_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_DEC_AP)
# endif
#
# define CHAOS_IP_DEC_AP_I(x) \
    CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(x))( \
        (CHAOS_PP_INC_AP_INTERNAL(CHAOS_PP_REM x)), \
        CHAOS_PP_IIF(CHAOS_PP_BOOL_AP_INTERNAL(x))( \
            CHAOS_PP_DEC_AP_INTERNAL(x), ((1)) \
        ) \
    ) \
    /**/
#
# /* CHAOS_PP_DEC_AP_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEC_AP_INTERNAL(x) \
        CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_SCAN(1)(CHAOS_IP_DEC_AP_A x(00), CHAOS_IP_DEC_AP_IV CHAOS_PP_SPECIAL_CLOSE(x)) \
        )) \
        /**/
# else
#    define CHAOS_PP_DEC_AP_INTERNAL(x) \
        CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_SPLIT( \
            0, \
            CHAOS_PP_SCAN(1)(CHAOS_IP_DEC_AP_A x(00) CHAOS_PP_EMPTY CHAOS_PP_DEFER(CHAOS_PP_COMMA)() CHAOS_IP_DEC_AP_IV CHAOS_PP_SPECIAL_CLOSE(x)) \
        )()) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_DEC_AP_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_DEC_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_DEC_AP_B)
#    define CHAOS_IP_DEC_AP_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_DEC_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit, CHAOS_IP_DEC_AP_A)
#    define CHAOS_IP_DEC_AP_II(...) CHAOS_IP_DEC_AP_III(__VA_ARGS__)
# else
#    define CHAOS_IP_DEC_AP_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_DEC_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_DEC_AP_B)
#    define CHAOS_IP_DEC_AP_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_DEC_AP_II CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() digit CHAOS_PP_COMMA() CHAOS_IP_DEC_AP_A)
#    define CHAOS_IP_DEC_AP_II(digit, im) CHAOS_IP_DEC_AP_III(digit, im)
# endif
#
# define CHAOS_IP_DEC_AP_III(digit, res, op) op(digit)(res)
# define CHAOS_IP_DEC_AP_IV(digit) CHAOS_IP_DEC_AP_ ## digit
# define CHAOS_IP_DEC_AP_V(digit) (digit) CHAOS_IP_DEC_AP_VI
# define CHAOS_IP_DEC_AP_VI(res) res, CHAOS_IP_DEC_AP_V
#
# define CHAOS_IP_DEC_AP_0(res) (9) res, CHAOS_IP_DEC_AP_IV
# define CHAOS_IP_DEC_AP_1(res) (0) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_2(res) (1) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_3(res) (2) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_4(res) (3) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_5(res) (4) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_6(res) (5) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_7(res) (6) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_8(res) (7) res, CHAOS_IP_DEC_AP_V
# define CHAOS_IP_DEC_AP_9(res) (8) res, CHAOS_IP_DEC_AP_V
#
# endif
