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
# ifndef CHAOS_PREPROCESSOR_REPETITION_ENUM_SHIFTED_TRAILING_PARAMS_H
# define CHAOS_PREPROCESSOR_REPETITION_ENUM_SHIFTED_TRAILING_PARAMS_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/repetition/enum_shifted_params.h>
#
# /* CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS(count, ...) CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(CHAOS_PP_LIMIT_EXPR, count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_ID)()
# else
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS(count, param) CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(CHAOS_PP_LIMIT_EXPR, count, param)
# endif
#
# define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_ID() CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS
#
# /* CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(s, count, ...) CHAOS_PP_COMMA_IF(CHAOS_PP_DEC(count)) CHAOS_PP_ENUM_SHIFTED_PARAMS_BYPASS(s, count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS_ID)()
# else
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(s, count, param) CHAOS_PP_COMMA_IF(CHAOS_PP_DEC(count)) CHAOS_PP_ENUM_SHIFTED_PARAMS_BYPASS(s, count, param)
# endif
#
# define CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS_ID() CHAOS_PP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS
#
# endif
