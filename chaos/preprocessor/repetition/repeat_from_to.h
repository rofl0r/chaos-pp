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
# ifndef CHAOS_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_H
# define CHAOS_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/delineate_from_to.h>
#
# /* CHAOS_PP_REPEAT_FROM_TO */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_FROM_TO(from, to, ...) CHAOS_PP_REPEAT_FROM_TO_S(CHAOS_PP_STATE(), from, to, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_FROM_TO_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_FROM_TO_ID)()
# else
#    define CHAOS_PP_REPEAT_FROM_TO(from, to, macro, data) CHAOS_PP_REPEAT_FROM_TO_S(CHAOS_PP_STATE(), from, to, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_FROM_TO_ID() CHAOS_PP_REPEAT_FROM_TO
#
# /* CHAOS_PP_REPEAT_FROM_TO_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_FROM_TO_S(s, from, to, ...) CHAOS_PP_DELINEATE_FROM_TO_S(s, from, to, CHAOS_PP_EMPTY, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_FROM_TO_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_FROM_TO_S_ID)()
# else
#    define CHAOS_PP_REPEAT_FROM_TO_S(s, from, to, macro, data) CHAOS_PP_DELINEATE_FROM_TO_S(s, from, to, CHAOS_PP_EMPTY, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_FROM_TO_S_ID() CHAOS_PP_REPEAT_FROM_TO_S
#
# endif
