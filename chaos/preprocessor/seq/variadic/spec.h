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
# ifndef CHAOS_PREPROCESSOR_SEQ_VARIADIC_SPEC_H
# define CHAOS_PREPROCESSOR_SEQ_VARIADIC_SPEC_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/spec.h>
#
# /* CHAOS_PP_VARIADIC_SEQ_TAG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_TAG(x) CHAOS_PP_SEQ_TAG(x)
#    define CHAOS_PP_VARIADIC_SEQ_TAG_ID() CHAOS_PP_VARIADIC_SEQ_TAG
#    define CHAOS_PP_VARIADIC_SEQ_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_TAG)
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_NIL CHAOS_PP_SEQ_NIL
#    define CHAOS_PP_VARIADIC_SEQ_NIL_ID CHAOS_PP_SEQ_NIL_ID
#    define CHAOS_PP_VARIADIC_SEQ_NIL_ CHAOS_PP_SEQ_NIL_
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_CONS CHAOS_PP_SEQ_CONS
#    define CHAOS_PP_VARIADIC_SEQ_CONS_ID CHAOS_PP_SEQ_CONS_ID
#    define CHAOS_PP_VARIADIC_SEQ_CONS_ CHAOS_PP_SEQ_CONS_
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
#    define CHAOS_PP_VARIADIC_SEQ_FIRST CHAOS_PP_SEQ_FIRST
#    define CHAOS_PP_VARIADIC_SEQ_FIRST_ID CHAOS_PP_SEQ_FIRST_ID
#    define CHAOS_PP_VARIADIC_SEQ_FIRST_ CHAOS_PP_SEQ_FIRST_
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_REST */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_REST CHAOS_PP_SEQ_REST
#    define CHAOS_PP_VARIADIC_SEQ_REST_ID CHAOS_PP_SEQ_REST_ID
#    define CHAOS_PP_VARIADIC_SEQ_REST_ CHAOS_PP_SEQ_REST_
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_IS_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_IS_CONS CHAOS_PP_SEQ_IS_CONS
#    define CHAOS_PP_VARIADIC_SEQ_IS_CONS_ID CHAOS_PP_SEQ_IS_CONS_ID
#    define CHAOS_PP_VARIADIC_SEQ_IS_CONS_ CHAOS_PP_SEQ_IS_CONS_
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_IS_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_IS_NIL CHAOS_PP_SEQ_IS_NIL
#    define CHAOS_PP_VARIADIC_SEQ_IS_NIL_ID CHAOS_PP_SEQ_IS_NIL_ID
#    define CHAOS_PP_VARIADIC_SEQ_IS_NIL_ CHAOS_PP_SEQ_IS_NIL_
# endif
#
# endif
