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
# ifndef CHAOS_PREPROCESSOR_SEQ_VARIADIC_CORE_H
# define CHAOS_PREPROCESSOR_SEQ_VARIADIC_CORE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/core.h>
#
# /* CHAOS_PP_VARIADIC_SEQ */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ CHAOS_PP_VARIADIC_SEQ
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_TAG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_TAG(tag) CHAOS_PP_SEQ_TAG(tag)
#    define CHAOS_PP_VARIADIC_SEQ_TAG_ID() CHAOS_PP_VARIADIC_SEQ_TAG
#    define CHAOS_PP_VARIADIC_SEQ_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_TAG)
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_NIL() CHAOS_PP_SEQ_NIL()
#    define CHAOS_PP_VARIADIC_SEQ_NIL_ID() CHAOS_PP_VARIADIC_SEQ_NIL
#    define CHAOS_PP_VARIADIC_SEQ_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_NIL)
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_CONS(seq, ...) CHAOS_PP_SEQ_CONS(seq, __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_CONS_ID() CHAOS_PP_VARIADIC_SEQ_CONS
#    define CHAOS_PP_VARIADIC_SEQ_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_CONS_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_ITEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_ITEM(...) (__VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_ITEM_ID() CHAOS_PP_VARIADIC_SEQ_ITEM
#    define CHAOS_PP_VARIADIC_SEQ_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_ITEM_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_FIRST */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FIRST(seq) CHAOS_PP_SEQ_FIRST(seq)
#    define CHAOS_PP_VARIADIC_SEQ_FIRST_ID() CHAOS_PP_VARIADIC_SEQ_FIRST
#    define CHAOS_PP_VARIADIC_SEQ_FIRST_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FIRST_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_REST */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_REST(seq) CHAOS_PP_SEQ_REST(seq)
#    define CHAOS_PP_VARIADIC_SEQ_REST_ID() CHAOS_PP_VARIADIC_SEQ_REST
#    define CHAOS_PP_VARIADIC_SEQ_REST_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_REST_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_IS_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_IS_CONS(seq) CHAOS_PP_SEQ_IS_CONS(seq)
#    define CHAOS_PP_VARIADIC_SEQ_IS_CONS_ID() CHAOS_PP_VARIADIC_SEQ_IS_CONS
#    define CHAOS_PP_VARIADIC_SEQ_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_IS_CONS)
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_IS_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_IS_NIL(seq) CHAOS_PP_SEQ_IS_NIL(seq)
#    define CHAOS_PP_VARIADIC_SEQ_IS_NIL_ID() CHAOS_PP_VARIADIC_SEQ_IS_NIL
#    define CHAOS_PP_VARIADIC_SEQ_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_IS_NIL)
# endif
#
# endif
