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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_INVOKE_H
# define CHAOS_PREPROCESSOR_LAMBDA_INVOKE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/execute.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/parse.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_INVOKE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INVOKE(expr, ...) CHAOS_PP_INVOKE_S(CHAOS_PP_STATE(), expr, __VA_ARGS__)
#    define CHAOS_PP_INVOKE_ID() CHAOS_PP_INVOKE
#    define CHAOS_PP_INVOKE_ CHAOS_PP_LAMBDA(CHAOS_PP_INVOKE_ID)()
# endif
#
# /* CHAOS_PP_INVOKE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INVOKE_S(s, expr, ...) CHAOS_PP_EXECUTE(CHAOS_PP_PARSE_S(s, expr, __VA_ARGS__))
#    define CHAOS_PP_INVOKE_S_ID() CHAOS_PP_INVOKE_S
#    define CHAOS_PP_INVOKE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_INVOKE_S_ID)()
# endif
#
# endif
