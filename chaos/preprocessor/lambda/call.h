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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_CALL_H
# define CHAOS_PREPROCESSOR_LAMBDA_CALL_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/invoke.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_CALL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CALL(x) CHAOS_PP_CAT(CHAOS_IP_CALL_, CHAOS_PP_IS_VARIADIC(x))
#    define CHAOS_PP_CALL_ CHAOS_PP_LAMBDA(CHAOS_PP_CALL)
#    define CHAOS_IP_CALL_0() CHAOS_IP_CALL_00
#    define CHAOS_IP_CALL_1() CHAOS_IP_CALL_11
#    define CHAOS_IP_CALL_00(s, macro, ...) CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_DEFER(macro)(s, __VA_ARGS__)))
#    define CHAOS_IP_CALL_11(s, expr, ...) CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_INVOKE(expr, s, __VA_ARGS__)))
# else
#    define CHAOS_PP_CALL(x) CHAOS_IP_CALL_I
#    define CHAOS_IP_CALL_I() CHAOS_IP_CALL_II
#    define CHAOS_IP_CALL_II(s, macro, im) CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_DEFER(macro)(s, im)))
# endif
#
# define CHAOS_PP_CALL_ID() CHAOS_PP_CALL
#
# endif
