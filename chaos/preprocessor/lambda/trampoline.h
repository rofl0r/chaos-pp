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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_TRAMPOLINE_H
# define CHAOS_PREPROCESSOR_LAMBDA_TRAMPOLINE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/execute.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/parse.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_TRAMPOLINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TRAMPOLINE(x) CHAOS_PP_CAT(CHAOS_IP_TRAMPOLINE_, CHAOS_PP_IS_VARIADIC(x))
#    define CHAOS_PP_TRAMPOLINE_ CHAOS_PP_LAMBDA(CHAOS_PP_TRAMPOLINE)
#    define CHAOS_IP_TRAMPOLINE_0() CHAOS_IP_TRAMPOLINE_00
#    define CHAOS_IP_TRAMPOLINE_1() CHAOS_IP_TRAMPOLINE_11
#    define CHAOS_IP_TRAMPOLINE_00(s, o, macro, ...) CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(macro CHAOS_PP_OBSTRUCT()(o, __VA_ARGS__))
#    define CHAOS_IP_TRAMPOLINE_11(s, o, expr, ...) \
        CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(CHAOS_PP_DEFER(CHAOS_PP_EXECUTE)(CHAOS_PP_DEFER(CHAOS_IP_PARSE_BACKDOOR)(s, o, expr, __VA_ARGS__))) \
        /**/
# else
#    define CHAOS_PP_TRAMPOLINE(x) CHAOS_IP_TRAMPOLINE_I
#    define CHAOS_IP_TRAMPOLINE_I() CHAOS_IP_TRAMPOLINE_II
#    define CHAOS_IP_TRAMPOLINE_II(s, o, macro, im) CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(macro CHAOS_PP_OBSTRUCT()(o, im))
# endif
#
# define CHAOS_PP_TRAMPOLINE_ID() CHAOS_PP_TRAMPOLINE
#
# endif
