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
# ifndef CHAOS_PREPROCESSOR_SEQ_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_SEQ_FOLD_LEFT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/fold_right.h>
# include <chaos/preprocessor/seq/reverse.h>
#
# /* CHAOS_PP_SEQ_FOLD_LEFT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_LEFT(op, seq, ...) CHAOS_PP_SEQ_FOLD_LEFT_S(CHAOS_PP_STATE(), op, seq, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOLD_LEFT_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_LEFT_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_LEFT(op, seq, state) CHAOS_PP_SEQ_FOLD_LEFT_S(CHAOS_PP_STATE(), op, seq, state)
# endif
#
# define CHAOS_PP_SEQ_FOLD_LEFT_ID() CHAOS_PP_SEQ_FOLD_LEFT
#
# /* CHAOS_PP_SEQ_FOLD_LEFT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_LEFT_S(s, op, seq, ...) CHAOS_PP_SEQ_FOLD_RIGHT_S(s, op, CHAOS_PP_SEQ_REVERSE(seq), __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOLD_LEFT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_LEFT_S_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_LEFT_S(s, op, seq, state) CHAOS_PP_SEQ_FOLD_RIGHT_S(s, op, CHAOS_PP_SEQ_REVERSE(seq), state)
# endif
#
# define CHAOS_PP_SEQ_FOLD_LEFT_S_ID() CHAOS_PP_SEQ_FOLD_LEFT_S
#
# endif
