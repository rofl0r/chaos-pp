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
# ifndef CHAOS_PREPROCESSOR_REPETITION_REPEAT_H
# define CHAOS_PREPROCESSOR_REPETITION_REPEAT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/repetition/delineate.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_REPEAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT(count, ...) CHAOS_PP_REPEAT_S(CHAOS_PP_STATE(), count, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_ID)()
# else
#    define CHAOS_PP_REPEAT(count, macro, data) CHAOS_PP_REPEAT_S(CHAOS_PP_STATE(), count, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_ID() CHAOS_PP_REPEAT
#
# /* CHAOS_PP_REPEAT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_S(s, count, ...) CHAOS_PP_DELINEATE_S(s, count, CHAOS_PP_EMPTY, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_S_ID)()
# else
#    define CHAOS_PP_REPEAT_S(s, count, macro, data) CHAOS_PP_DELINEATE_S(s, count, CHAOS_PP_EMPTY, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_S_ID() CHAOS_PP_REPEAT_S
#
# endif
