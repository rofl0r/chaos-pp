# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_PARAMS_H
# define CHAOS_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_PARAMS_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/repetition/delineate_params.h>
#
# /* CHAOS_PP_DELINEATE_TRAILING_PARAMS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_TRAILING_PARAMS(count, sep, ...) CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS(CHAOS_PP_LIMIT_EXPR, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_TRAILING_PARAMS_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_TRAILING_PARAMS_ID)()
# else
#    define CHAOS_PP_DELINEATE_TRAILING_PARAMS(count, sep, param) CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS(CHAOS_PP_LIMIT_EXPR, count, sep, param)
# endif
#
# define CHAOS_PP_DELINEATE_TRAILING_PARAMS_ID() CHAOS_PP_DELINEATE_TRAILING_PARAMS
#
# /* CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS(s, count, sep, ...) CHAOS_PP_WHEN(count)(sep()) CHAOS_PP_DELINEATE_PARAMS_BYPASS(s, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS_ID)()
# else
#    define CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS(s, count, sep, param) CHAOS_PP_WHEN(count)(sep()) CHAOS_PP_DELINEATE_PARAMS_BYPASS(s, count, sep, param)
# endif
#
# define CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS_ID() CHAOS_PP_DELINEATE_TRAILING_PARAMS_BYPASS
#
# endif
