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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_SUB_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_SUB_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_SUB_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_MACHINE(x, y) CHAOS_PP_SUB_MACHINE_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_SUB_MACHINE_ID() CHAOS_PP_SUB_MACHINE
#    define CHAOS_PP_SUB_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB_MACHINE)
# endif
#
# /* CHAOS_PP_SUB_MACHINE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_MACHINE_S(s, x, y) CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xSUB), x, y, 0xCHAOS(0xSTOP),)))
#    define CHAOS_PP_SUB_MACHINE_S_ID() CHAOS_PP_SUB_MACHINE_S
#    define CHAOS_PP_SUB_MACHINE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB_MACHINE_S)
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xSUB(s, p, x, y, k, ...) \
        CHAOS_PP_IF(y)( \
            (, 0xCHAOS(0xSUB), CHAOS_PP_DEC(x), CHAOS_PP_DEC(y), k, p ## __VA_ARGS__), \
            (, k, x, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
