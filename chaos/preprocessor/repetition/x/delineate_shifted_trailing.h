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
# ifndef CHAOS_PREPROCESSOR_REPETITION_X_DELINEATE_SHIFTED_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_X_DELINEATE_SHIFTED_TRAILING_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/x/delineate_shifted.h>
#
# /* CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X(size, count, sep, ...) CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S(CHAOS_PP_STATE(), size, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_ID)()
# else
#    define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X(size, count, sep, macro, data) CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S(CHAOS_PP_STATE(), size, count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_ID() CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X
#
# /* CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S(s, size, count, sep, ...) CHAOS_PP_WHEN(CHAOS_PP_DEC(count))(sep()) CHAOS_PP_DELINEATE_SHIFTED_X_S(s, size, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S(s, size, count, sep, macro, data) CHAOS_PP_WHEN(CHAOS_PP_DEC(count))(sep()) CHAOS_PP_DELINEATE_SHIFTED_X_S(s, size, count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S_ID() CHAOS_PP_DELINEATE_SHIFTED_TRAILING_X_S
#
# endif
