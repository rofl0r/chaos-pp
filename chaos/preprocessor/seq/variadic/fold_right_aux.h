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
# ifndef CHAOS_PREPROCESSOR_SEQ_VARIADIC_FOLD_RIGHT_AUX_H
# define CHAOS_PREPROCESSOR_SEQ_VARIADIC_FOLD_RIGHT_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/fold_right_aux.h>
# include <chaos/preprocessor/seq/zip.h>
#
# /* CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX(op, seq, data, ...) CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S(CHAOS_PP_STATE(), op, seq, data, __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_ID() CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S(s, op, seq, data, ...) CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(s, op, CHAOS_PP_SEQ_ZIP(seq), data, __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S_ID() CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S_ID)()
# endif
#
# endif
