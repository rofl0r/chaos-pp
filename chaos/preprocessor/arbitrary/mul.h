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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_MUL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_MUL_H
#
# include <chaos/preprocessor/arbitrary/add.h>
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/arbitrary/detail/is_shorter.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/namespace.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/detail/times.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitxor.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/seq/spec.h>
#
# /* CHAOS_PP_MUL_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_AP(x, y) CHAOS_PP_MUL_AP_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_MUL_AP_ID() CHAOS_PP_MUL_AP
#    define CHAOS_PP_MUL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_AP)
# endif
#
# /* CHAOS_PP_MUL_AP_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_AP_S(s, x, y) CHAOS_IP_MUL_AP_I(s, CHAOS_PP_SUPER_CLEAN_AP(x), CHAOS_PP_SUPER_CLEAN_AP(y))
#    define CHAOS_PP_MUL_AP_S_ID() CHAOS_PP_MUL_AP_S
#    define CHAOS_PP_MUL_AP_S_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_AP_S)
#    define CHAOS_IP_MUL_AP_I(s, x, y) \
        CHAOS_PP_CLEAN_AP((CHAOS_PP_BITXOR(CHAOS_PP_BINARY(0) x)(CHAOS_PP_BINARY(0) y), CHAOS_PP_MUL_AP_INTERNAL(s, CHAOS_PP_BINARY(1) x, CHAOS_PP_BINARY(1) y))) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_AP_INTERNAL(s, x, y) CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xARBITRARY(0xMUL)), x, y, 0xCHAOS(0xSTOP),)))
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMUL(s, p, x, y, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xIS_SHORTER)), p ## x, p ## y, 0xCHAOS(0xARBITRARY(0xMUL2)), p ## x, p ## y, k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMUL2(s, p, bit, x, y, k, ...) \
        CHAOS_PP_IIF(bit)( \
            (, 0xCHAOS(0xARBITRARY(0xMUL3)), (0),, p ## y, CHAOS_PP_SEQ_REVERSE(p ## x), k, p ## __VA_ARGS__), \
            (, 0xCHAOS(0xARBITRARY(0xMUL3)), (0),, p ## x, CHAOS_PP_SEQ_REVERSE(p ## y), k, p ## __VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMUL3(s, p, res, z, x, ry, k, ...) \
        CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(ry))( \
            (, 0xCHAOS(0xARBITRARY(0xMERGE)), p ## x,, CHAOS_IP_MUL_AP_M, CHAOS_PP_SEQ_FIRST(p ## ry), 1, 0xCHAOS(0xARBITRARY(0xMUL4)), p ## res, p ## z, p ## x, CHAOS_PP_SEQ_REST(p ## ry), k, p ## __VA_ARGS__), \
            (, k, p ## res, p ## __VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xMUL4(s, p, merge, res, z, x, ry, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xADD)), res, CHAOS_PP_CLEAN_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_IP_MUL_AP_M(0) p ## merge()) p ## z), 0xCHAOS(0xARBITRARY(0xMUL3)), p ## z(0), p ## x, p ## ry, k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_IP_MUL_AP_M(x) CHAOS_IP_MUL_AP_ ## x
#    define CHAOS_IP_MUL_AP_0(x, y) CHAOS_IP_ADD_AP_A(CHAOS_PP_TIMES(x, y))
#    define CHAOS_IP_MUL_AP_1(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 1)
#    define CHAOS_IP_MUL_AP_2(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 2)
#    define CHAOS_IP_MUL_AP_3(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 3)
#    define CHAOS_IP_MUL_AP_4(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 4)
#    define CHAOS_IP_MUL_AP_5(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 5)
#    define CHAOS_IP_MUL_AP_6(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 6)
#    define CHAOS_IP_MUL_AP_7(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 7)
#    define CHAOS_IP_MUL_AP_8(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_TIMES(x, y), 8)
# endif
#
# endif
