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
# ifndef CHAOS_PREPROCESSOR_SEQ_FOLD_LEFT_AUX_H
# define CHAOS_PREPROCESSOR_SEQ_FOLD_LEFT_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/fold_right_aux.h>
# include <chaos/preprocessor/seq/reverse.h>
#
# /* CHAOS_PP_SEQ_FOLD_LEFT_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_LEFT_AUX(op, seq, data, ...) CHAOS_PP_SEQ_FOLD_LEFT_AUX_S(CHAOS_PP_STATE(), op, seq, data, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOLD_LEFT_AUX_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_LEFT_AUX_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_LEFT_AUX(op, seq, data, state) CHAOS_PP_SEQ_FOLD_LEFT_AUX_S(CHAOS_PP_STATE(), op, seq, data, state)
# endif
#
# define CHAOS_PP_SEQ_FOLD_LEFT_AUX_ID() CHAOS_PP_SEQ_FOLD_LEFT_AUX
#
# /* CHAOS_PP_SEQ_FOLD_LEFT_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_LEFT_AUX_S(s, op, seq, data, ...) CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(s, op, CHAOS_PP_SEQ_REVERSE(seq), data, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOLD_LEFT_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_LEFT_AUX_S_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_LEFT_AUX_S(s, op, seq, data, state) CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(s, op, CHAOS_PP_SEQ_REVERSE(seq), data, state)
# endif
#
# define CHAOS_PP_SEQ_FOLD_LEFT_AUX_S_ID() CHAOS_PP_SEQ_FOLD_LEFT_AUX_S
#
# endif
