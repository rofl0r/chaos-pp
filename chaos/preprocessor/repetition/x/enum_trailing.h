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
# ifndef CHAOS_PREPROCESSOR_REPETITION_X_ENUM_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_X_ENUM_TRAILING_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/x/enum.h>
#
# /* CHAOS_PP_ENUM_TRAILING_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_TRAILING_X(size, count, ...) CHAOS_PP_ENUM_TRAILING_X_S(CHAOS_PP_STATE(), size, count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_TRAILING_X_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_TRAILING_X_ID)()
# else
#    define CHAOS_PP_ENUM_TRAILING_X(size, count, macro, data) CHAOS_PP_ENUM_TRAILING_X_S(CHAOS_PP_STATE(), size, count, macro, data)
# endif
#
# define CHAOS_PP_ENUM_TRAILING_X_ID() CHAOS_PP_ENUM_TRAILING_X
#
# /* CHAOS_PP_ENUM_TRAILING_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_TRAILING_X_S(s, size, count, ...) CHAOS_PP_COMMA_IF(count) CHAOS_PP_ENUM_X_S(s, size, count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_TRAILING_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_TRAILING_X_S_ID)()
# else
#    define CHAOS_PP_ENUM_TRAILING_X_S(s, size, count, macro, data) CHAOS_PP_COMMA_IF(count) CHAOS_PP_ENUM_X_S(s, size, count, macro, data)
# endif
#
# define CHAOS_PP_ENUM_TRAILING_X_S_ID() CHAOS_PP_ENUM_TRAILING_X_S
#
# endif
