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
# ifndef CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_ENUM_FROM_TO_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_ENUM_FROM_TO_TRAILING_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/parametric/enum_from_to.h>
#
# /* CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC(from, to, ...) CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(CHAOS_PP_STATE(), from, to, __VA_ARGS__)
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC(from, to, macro, data) CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(CHAOS_PP_STATE(), from, to, macro, data)
# endif
#
# define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_ID() CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC
#
# /* CHAOS_PP_ENUM_FROM_TO_TRAILING_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(s, from, to, ...) CHAOS_PP_COMMA_IF(CHAOS_PP_NOT_EQUAL(from, to)) CHAOS_PP_ENUM_FROM_TO_PARAMETRIC_S(s, from, to, __VA_ARGS__)
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(s, from, to, macro, data) CHAOS_PP_COMMA_IF(CHAOS_PP_NOT_EQUAL(from, to)) CHAOS_PP_ENUM_FROM_TO_PARAMETRIC_S(s, from, to, macro, data)
# endif
#
# define CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S_ID() CHAOS_PP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S
#
# endif
