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
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/namespace.h>
# include <chaos/preprocessor/arbitrary/detail/utility.h>
# include <chaos/preprocessor/arbitrary/equal.h>
# include <chaos/preprocessor/arbitrary/less.h>
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/arbitrary/mul.h>
# include <chaos/preprocessor/arbitrary/sub.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/detail/divide.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitxor.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DIV_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_AP(x, y) CHAOS_PP_DIV_AP_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_DIV_AP_ID() CHAOS_PP_DIV_AP
#    define CHAOS_PP_DIV_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_AP)
# endif
#
# /* CHAOS_PP_DIV_AP_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_AP_S(s, x, y) CHAOS_IP_DIV_AP_I(s, CHAOS_PP_SUPER_CLEAN_AP(x), CHAOS_PP_SUPER_CLEAN_AP(y))
#    define CHAOS_PP_DIV_AP_S_ID() CHAOS_PP_DIV_AP_S
#    define CHAOS_PP_DIV_AP_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_AP_S)
#    define CHAOS_IP_DIV_AP_I(s, x, y) \
        CHAOS_PP_CLEAN_AP((CHAOS_PP_BITXOR(CHAOS_PP_BINARY(0) x)(CHAOS_PP_BINARY(0) y), CHAOS_PP_DIV_AP_INTERNAL(s, CHAOS_PP_BINARY(1) x, CHAOS_PP_BINARY(1) y))) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_AP_INTERNAL(s, x, y) CHAOS_PP_BINARY_CTOR(0, CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xARBITRARY(0xDIV)), x, y, 0xCHAOS(0xSTOP),))))
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV(s, p, x, y, k, ...) \
        CHAOS_PP_IIF(CHAOS_PP_BOOL_AP_INTERNAL(y))( \
            (, 0xCHAOS(0xARBITRARY(0xLESS)), p ## x, p ## y, 0xCHAOS(0xIIF), \
                (, k, ( (0), p ## x ), p ## __VA_ARGS__), \
                (, 0xCHAOS(0xARBITRARY(0xEQUAL)), p ## x, p ## y, 0xCHAOS(0xIIF), \
                    (, k, (1), (0), p ## __VA_ARGS__), \
                    (, 0xCHAOS(0xARBITRARY(0xDIV2)), p ## x, p ## y,, 0xCHAOS(0xARBITRARY(0xDIV3)), CHAOS_PP_SEQ_FIRST(p ## y), p ## y,, k, p ## __VA_ARGS__), \
                    0xCHAOS(0xEVAL), \
                ), \
                0xCHAOS(0xEVAL), \
            ), \
            CHAOS_PP_FAILURE() \
        ) \
       /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV2(s, p, x, y, rem, k, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(p ## y))( \
            (, 0xCHAOS(0xARBITRARY(0xDIV2)), CHAOS_PP_TUPLE_EAT(?) p ## x, CHAOS_PP_TUPLE_EAT(?) p ## y, rem(CHAOS_PP_SEQ_FIRST(p ## x)), k, p ## __VA_ARGS__), \
            (, k, p ## rem, p ## x, p ## __VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV3(s, p, rem, pool, digit, y, res, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xDIV4)), CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(CHAOS_PP_TUPLE_EAT(?) p ## rem))(, (0)) p ## rem, p ## pool, digit, p ## y, p ## res, k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV4(s, p, rem, pool, digit, y, res, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xDIV5)), CHAOS_PP_DIVIDE(CHAOS_PP_SEQ_FIRST(p ## rem), CHAOS_PP_SEQ_FIRST(CHAOS_PP_SEQ_REST(p ## rem)), digit), p ## rem, p ## pool, digit, p ## y, p ## res, k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV5(s, p, est, rem, pool, digit, y, res, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xDIV6)), est, p ## y, 0xCHAOS(0xARBITRARY(0xDIV8)), est, p ## rem, p ## pool, digit, p ## y, p ## res, k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV6(s, p, digit, y, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xMERGE)), p ## y,, CHAOS_IP_MUL_AP_M, digit, 1, 0xCHAOS(0xARBITRARY(0xDIV7)), k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV7(s, p, merge, k, ...) \
        (, k, CHAOS_PP_CLEAN_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_IP_MUL_AP_M(0) p ## merge())), p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV8(s, p, try, est, rem, pool, digit, y, res, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xLESS_EQUAL)), p ## try, p ## rem, 0xCHAOS(0xIIF), \
            (, 0xCHAOS(0xARBITRARY(0xDIV9)), p ## try, est, p ## rem, p ## pool, digit, p ## y, p ## res, k, p ## __VA_ARGS__), \
            (, 0xCHAOS(0xARBITRARY(0xDIV5)), CHAOS_PP_DEC(est), p ## rem, p ## pool, digit, p ## y, p ## res, k, p ## __VA_ARGS__), \
            0xCHAOS(0xEVAL), \
        ) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV9(s, p, try, est, rem, pool, digit, y, res, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xSUB)), p ## rem, p ## try, 0xCHAOS(0xARBITRARY(0xDIV10)), p ## pool, digit, p ## y, p ## res(est), k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xDIV10(s, p, rem, pool, digit, y, res, k, ...) \
        CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(pool))( \
            (, 0xCHAOS(0xARBITRARY(0xDIV4)), p ## rem(CHAOS_PP_SEQ_FIRST(p ## pool)), CHAOS_PP_TUPLE_EAT(?) p ## pool, digit, p ## y, p ## res, k, p ## __VA_ARGS__), \
            (, k, (CHAOS_PP_CLEAN_AP_INTERNAL(p ## res), CHAOS_PP_CLEAN_AP_INTERNAL(p ## rem)), p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
