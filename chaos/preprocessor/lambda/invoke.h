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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_INVOKE_H
# define CHAOS_PREPROCESSOR_LAMBDA_INVOKE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/execute.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/parse.h>
# include <chaos/preprocessor/limits.h>
#
# /* CHAOS_PP_INVOKE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INVOKE(...) CHAOS_PP_INVOKE_BYPASS(CHAOS_PP_LIMIT_EXPR, __VA_ARGS__)
#    define CHAOS_PP_INVOKE_ID() CHAOS_PP_INVOKE
#    define CHAOS_PP_INVOKE_ CHAOS_PP_LAMBDA(CHAOS_PP_INVOKE_ID)()
# endif
#
# /* CHAOS_PP_INVOKE_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INVOKE_BYPASS(s, ...) CHAOS_PP_EXECUTE(CHAOS_PP_PARSE_BYPASS(s, __VA_ARGS__))
#    define CHAOS_PP_INVOKE_BYPASS_ID() CHAOS_PP_INVOKE_BYPASS
#    define CHAOS_PP_INVOKE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_INVOKE_BYPASS_ID)()
# endif
#
# endif
