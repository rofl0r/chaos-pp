# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MOD_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MOD_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/arithmetic/machine/sub.h>
# include <chaos/preprocessor/comparison/less_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/debug/division_by_zero.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/not.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_MOD_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_MACHINE(x, y) CHAOS_PP_MOD_MACHINE_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_MOD_MACHINE_ID() CHAOS_PP_MOD_MACHINE
#    define CHAOS_PP_MOD_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_MACHINE)
# endif
#
# /* CHAOS_PP_MOD_MACHINE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_MACHINE_S(s, x, y) \
        CHAOS_PP_EXPR_IIF(CHAOS_PP_NOT(y))(CHAOS_PP_DIVISION_BY_ZERO()) \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xMOD), x, y, 0xCHAOS(0xSTOP),))) \
        /**/
#    define CHAOS_PP_MOD_MACHINE_S_ID() CHAOS_PP_MOD_MACHINE_S
#    define CHAOS_PP_MOD_MACHINE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_MACHINE_S)
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xMOD(s, p, x, y, k, ...) (, 0xCHAOS(0xMOD2), x, y, 0, k, __VA_ARGS__)
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xMOD2(s, p, x, y, r, k, ...) \
        CHAOS_PP_IIF(CHAOS_PP_LESS_EQUAL(y, x))( \
            (, 0xCHAOS(0xSUB), x, y, 0xCHAOS(0xMOD2), y, CHAOS_PP_INC(r), k, p ## __VA_ARGS__), \
            (, k, x, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
