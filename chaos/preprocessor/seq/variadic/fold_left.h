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
# ifndef CHAOS_PREPROCESSOR_SEQ_VARIADIC_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_SEQ_VARIADIC_FOLD_LEFT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/fold_left.h>
# include <chaos/preprocessor/seq/zip.h>
#
# /* CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT(op, seq, ...) CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S(CHAOS_PP_STATE(), op, seq, __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_ID() CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S(s, op, seq, ...) CHAOS_PP_SEQ_FOLD_LEFT_S(s, op, CHAOS_PP_SEQ_ZIP(seq), __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S_ID() CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S
#    define CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FOLD_LEFT_S_ID)()
# endif
#
# endif
