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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_ADD_H
# define CHAOS_PREPROCESSOR_ARBITRARY_ADD_H
#
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/namespace.h>
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/arbitrary/sub.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/highprec/detail/plus.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
# include <chaos/preprocessor/seq/reverse.h>
#
# /* CHAOS_PP_ADD_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_AP(x, y) CHAOS_PP_ADD_AP_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_ADD_AP_ID() CHAOS_PP_ADD_AP
#    define CHAOS_PP_ADD_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD_AP)
# endif
#
# /* CHAOS_PP_ADD_AP_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_AP_S(s, x, y) CHAOS_IP_ADD_AP_I(s, CHAOS_PP_SUPER_CLEAN_AP(x), CHAOS_PP_SUPER_CLEAN_AP(y))
#    define CHAOS_PP_ADD_AP_S_ID() CHAOS_PP_ADD_AP_S
#    define CHAOS_PP_ADD_AP_S_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD_AP_S)
#    define CHAOS_IP_ADD_AP_I(s, x, y) \
        CHAOS_PP_VARIADIC_CAT(CHAOS_IP_ADD_AP_S_, CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y)( \
            s, CHAOS_PP_BINARY(1) x, CHAOS_PP_BINARY(1) y \
        ) \
        /**/
#    define CHAOS_IP_ADD_AP_S_00(s, x, y) (0, CHAOS_PP_ADD_AP_INTERNAL(s, x, y))
#    define CHAOS_IP_ADD_AP_S_01(s, x, y) CHAOS_IP_ADD_AP_S_10(s, y, x)
#    define CHAOS_IP_ADD_AP_S_10(s, x, y) \
        CHAOS_PP_CLEAN_AP(CHAOS_PP_IIF(CHAOS_PP_LESS_EQUAL_AP_INTERNAL(s, x, y))( \
            (0, CHAOS_PP_SUB_AP_INTERNAL(s, y, x)), \
            (1, CHAOS_PP_SUB_AP_INTERNAL(s, x, y)) \
        )) \
        /**/
#    define CHAOS_IP_ADD_AP_S_11(s, x, y) (1, CHAOS_PP_ADD_AP_INTERNAL(s, x, y))
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_AP_INTERNAL(s, x, y) CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xARBITRARY(0xADD)), x, y, 0xCHAOS(0xSTOP),)))
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xADD(s, p, x, y, k, ...) \
        (, 0xCHAOS(0xARBITRARY(0xMERGE)), p ## x, p ## y, CHAOS_IP_ADD_AP_M, 0, 1, 0xCHAOS(0xARBITRARY(0xADD2)), k, p ## __VA_ARGS__) \
        /**/
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xADD2(s, p, merge, k, ...) \
        (, k, CHAOS_PP_CLEAN_AP_INTERNAL(CHAOS_PP_SEQ_REVERSE(CHAOS_IP_ADD_AP_M(0) merge())), p ## __VA_ARGS__) \
        /**/
#    define CHAOS_IP_ADD_AP_M(x) CHAOS_IP_ADD_AP_ ## x
#    define CHAOS_IP_ADD_AP_0(x, y) CHAOS_IP_ADD_AP_A(CHAOS_PP_PLUS(x, y))
#    define CHAOS_IP_ADD_AP_1(x, y) CHAOS_IP_ADD_AP_B(CHAOS_PP_PLUS(x, y), 1)
#    define CHAOS_IP_ADD_AP_A(bin) (CHAOS_PP_BINARY(1) bin) CHAOS_PP_INDIRECT(CHAOS_PP_BINARY(0) bin)
#    define CHAOS_IP_ADD_AP_B(bin, n) CHAOS_IP_ADD_AP_C(CHAOS_PP_BINARY(0) bin, CHAOS_PP_PLUS(CHAOS_PP_BINARY(1) bin, n))
#    define CHAOS_IP_ADD_AP_C(a, bin) (CHAOS_PP_BINARY(1) bin) CHAOS_PP_INDIRECT(CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_PLUS(a, CHAOS_PP_BINARY(0) bin)))
# endif
#
# endif
