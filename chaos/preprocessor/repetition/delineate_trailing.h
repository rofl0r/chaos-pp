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
# ifndef CHAOS_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/delineate.h>
#
# /* CHAOS_PP_DELINEATE_TRAILING */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_TRAILING(count, sep, ...) CHAOS_PP_DELINEATE_TRAILING_S(CHAOS_PP_STATE(), count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_TRAILING_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_TRAILING_ID)()
# else
#    define CHAOS_PP_DELINEATE_TRAILING(count, sep, macro, data) CHAOS_PP_DELINEATE_TRAILING_S(CHAOS_PP_STATE(), count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_TRAILING_ID() CHAOS_PP_DELINEATE_TRAILING
#
# /* CHAOS_PP_DELINEATE_TRAILING_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_TRAILING_S(s, count, sep, ...) CHAOS_PP_WHEN(count)(sep()) CHAOS_PP_DELINEATE_S(s, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_TRAILING_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_TRAILING_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_TRAILING_S(s, count, sep, macro, data) CHAOS_PP_WHEN(count)(sep()) CHAOS_PP_DELINEATE_S(s, count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_TRAILING_S_ID() CHAOS_PP_DELINEATE_TRAILING_S
#
# endif
