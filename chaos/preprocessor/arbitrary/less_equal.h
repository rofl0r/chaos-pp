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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_LESS_EQUAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_LESS_EQUAL_H
#
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/namespace.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/highprec/detail/digit_comp.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_LESS_EQUAL_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LESS_EQUAL_AP(x, y) CHAOS_PP_LESS_EQUAL_AP_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_LESS_EQUAL_AP_ID() CHAOS_PP_LESS_EQUAL_AP
#    define CHAOS_PP_LESS_EQUAL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_LESS_EQUAL_AP)
# endif
#
# /* CHAOS_PP_LESS_EQUAL_AP_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LESS_EQUAL_AP_S(s, x, y) CHAOS_IP_LESS_EQUAL_AP_I(s, CHAOS_PP_SUPER_CLEAN_AP(x), CHAOS_PP_SUPER_CLEAN_AP(y))
#    define CHAOS_IP_LESS_EQUAL_AP_I(s, x, y) \
        CHAOS_PP_VARIADIC_CAT(CHAOS_IP_LESS_EQUAL_AP_S_, CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y)( \
            s, CHAOS_PP_BINARY(1) x, CHAOS_PP_BINARY(1) y \
        ) \
        /**/
#    define CHAOS_IP_LESS_EQUAL_AP_S_00(s, x, y) CHAOS_PP_LESS_EQUAL_AP_INTERNAL(s, x, y)
#    define CHAOS_IP_LESS_EQUAL_AP_S_01(s, x, y) 0
#    define CHAOS_IP_LESS_EQUAL_AP_S_10(s, x, y) 1
#    define CHAOS_IP_LESS_EQUAL_AP_S_11(s, x, y) CHAOS_PP_LESS_EQUAL_AP_INTERNAL(s, y, x)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LESS_EQUAL_AP_INTERNAL(s, x, y) CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xARBITRARY(0xLESS_EQUAL)), x, y, 0xCHAOS(0xSTOP),)))
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xLESS_EQUAL(s, p, x, y, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xMERGE)), p ## x, p ## y, CHAOS_IP_LESS_EQUAL_AP_M, 0, 0, 0xCHAOS(0xARBITRARY(0xLESS_EQUAL2)), k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xLESS_EQUAL2(s, p, merge, k, ...) \
        (, k, CHAOS_PP_COMPL(CHAOS_IP_LESS_EQUAL_AP_M(1) merge(CHAOS_PP_DEC)), p ## __VA_ARGS__) \
        /**/
#    define CHAOS_IP_LESS_EQUAL_AP_M(x) CHAOS_IP_LESS_EQUAL_AP_ ## x
#    define CHAOS_IP_LESS_EQUAL_AP_0(a, b) CHAOS_PP_INDIRECT(0)
#    define CHAOS_IP_LESS_EQUAL_AP_1(a, b) CHAOS_PP_INDIRECT(CHAOS_PP_DIGIT_COMP(a, b))
#    define CHAOS_IP_LESS_EQUAL_AP_2(a, b) CHAOS_PP_INDIRECT(2)
# endif
#
# endif
