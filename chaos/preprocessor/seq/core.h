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
# ifndef CHAOS_PREPROCESSOR_SEQ_CORE_H
# define CHAOS_PREPROCESSOR_SEQ_CORE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ */
#
# define CHAOS_PP_SEQ CHAOS_PP_SEQ
#
# /* CHAOS_PP_SEQ_TAG */
#
# define CHAOS_PP_SEQ_TAG(tag) tag
# define CHAOS_PP_SEQ_TAG_ID() CHAOS_PP_SEQ_TAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TAG)
# endif
#
# /* CHAOS_PP_SEQ_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_NIL()
# else
#    define CHAOS_PP_SEQ_NIL() ~
#    define CHAOS_PP_SEQ_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_NIL)
# endif
#
# define CHAOS_PP_SEQ_NIL_ID() CHAOS_PP_SEQ_NIL
#
# /* CHAOS_PP_SEQ_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_CONS(seq, ...) (__VA_ARGS__) seq
#    define CHAOS_PP_SEQ_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_CONS_ID)()
# else
#    define CHAOS_PP_SEQ_CONS(seq, x) (x) CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_UNARY(seq))(seq)
# endif
#
# define CHAOS_PP_SEQ_CONS_ID() CHAOS_PP_SEQ_CONS
#
# /* CHAOS_PP_SEQ_ITEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_ITEM(...) __VA_ARGS__
#    define CHAOS_PP_SEQ_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_ITEM_ID)()
# else
#    define CHAOS_PP_SEQ_ITEM(x) x
# endif
#
# define CHAOS_PP_SEQ_ITEM_ID() CHAOS_PP_SEQ_ITEM
#
# /* CHAOS_PP_SEQ_HEAD */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_HEAD(seq) CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_SPLIT(0, CHAOS_IP_SEQ_HEAD_I seq))
#    define CHAOS_PP_SEQ_HEAD_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_HEAD_ID)()
# else
#    define CHAOS_PP_SEQ_HEAD(seq) CHAOS_PP_SPLIT(0, CHAOS_IP_SEQ_HEAD_I seq)
# endif
#
# define CHAOS_PP_SEQ_HEAD_ID() CHAOS_PP_SEQ_HEAD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_HEAD_I(...) (__VA_ARGS__),
# else
#    define CHAOS_IP_SEQ_HEAD_I(x) x, ~
# endif
#
# /* CHAOS_PP_SEQ_TAIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TAIL(seq) CHAOS_PP_EAT seq
#    define CHAOS_PP_SEQ_TAIL_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TAIL_ID)()
# else
#    define CHAOS_PP_SEQ_TAIL(seq) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(CHAOS_PP_EAT seq ~))( \
            CHAOS_PP_EAT seq, CHAOS_PP_SEQ_NIL() \
        ) \
        /**/
# endif
#
# define CHAOS_PP_SEQ_TAIL_ID() CHAOS_PP_SEQ_TAIL
#
# /* CHAOS_PP_SEQ_IS_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_IS_CONS(seq) CHAOS_PP_IS_VARIADIC(seq)
#    define CHAOS_PP_SEQ_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_IS_CONS)
# else
#    define CHAOS_PP_SEQ_IS_CONS(seq) CHAOS_PP_IS_UNARY(seq)
# endif
#
# define CHAOS_PP_SEQ_IS_CONS_ID() CHAOS_PP_SEQ_IS_CONS
#
# /* CHAOS_PP_SEQ_IS_NIL */
#
# define CHAOS_PP_SEQ_IS_NIL(seq) CHAOS_PP_COMPL(CHAOS_PP_SEQ_IS_CONS(seq))
# define CHAOS_PP_SEQ_IS_NIL_ID() CHAOS_PP_SEQ_IS_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_IS_NIL)
# endif
#
# endif
