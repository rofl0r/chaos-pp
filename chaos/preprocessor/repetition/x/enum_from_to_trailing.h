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
# ifndef CHAOS_PREPROCESSOR_REPETITION_X_ENUM_FROM_TO_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_X_ENUM_FROM_TO_TRAILING_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/x/enum_from_to.h>
#
# /* CHAOS_PP_ENUM_FROM_TO_TRAILING_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_X(size, from, to, ...) CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S(CHAOS_PP_STATE(), size, from, to, __VA_ARGS__)
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_X_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_FROM_TO_TRAILING_X_ID)()
# else
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_X(size, from, to, macro, data) CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S(CHAOS_PP_STATE(), size, from, to, macro, data)
# endif
#
# define CHAOS_PP_ENUM_FROM_TO_TRAILING_X_ID() CHAOS_PP_ENUM_FROM_TO_TRAILING_X
#
# /* CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S(s, size, from, to, ...) CHAOS_PP_COMMA_IF(CHAOS_PP_NOT_EQUAL(from, to)) CHAOS_PP_ENUM_FROM_TO_X_S(s, size, from, to, __VA_ARGS__)
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S_ID)()
# else
#    define CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S(s, size, from, to, macro, data) CHAOS_PP_COMMA_IF(CHAOS_PP_NOT_EQUAL(from, to)) CHAOS_PP_ENUM_FROM_TO_X_S(s, size, from, to, macro, data)
# endif
#
# define CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S_ID() CHAOS_PP_ENUM_FROM_TO_TRAILING_X_S
#
# endif
