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
# ifndef CHAOS_PREPROCESSOR_LIST_CORE_H
# define CHAOS_PREPROCESSOR_LIST_CORE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_LIST */
#
# define CHAOS_PP_LIST CHAOS_PP_LIST
#
# /* CHAOS_PP_LIST_TAG */
#
# define CHAOS_PP_LIST_TAG(tag) tag
# define CHAOS_PP_LIST_TAG_ID() CHAOS_PP_LIST_TAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_TAG)
# endif
#
# /* CHAOS_PP_LIST_NIL */
#
# define CHAOS_PP_LIST_NIL() ...
# define CHAOS_PP_LIST_NIL_ID() CHAOS_PP_LIST_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_NIL)
# endif
#
# /* CHAOS_PP_LIST_CONS */
#
# define CHAOS_PP_LIST_CONS(list, x) (x, list)
# define CHAOS_PP_LIST_CONS_ID() CHAOS_PP_LIST_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_CONS_ID)()
# endif
#
# /* CHAOS_PP_LIST_ITEM */
#
# define CHAOS_PP_LIST_ITEM(x) x
# define CHAOS_PP_LIST_ITEM_ID() CHAOS_PP_LIST_ITEM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_ITEM_ID)()
# endif
#
# /* CHAOS_PP_LIST_HEAD */
#
# define CHAOS_PP_LIST_HEAD(list) CHAOS_PP_SPLIT(0, CHAOS_PP_TUPLE_REM(2) list)
# define CHAOS_PP_LIST_HEAD_ID() CHAOS_PP_LIST_HEAD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_HEAD_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_HEAD_ID)()
# endif
#
# /* CHAOS_PP_LIST_TAIL */
#
# define CHAOS_PP_LIST_TAIL(list) CHAOS_PP_SPLIT(1, CHAOS_PP_TUPLE_REM(2) list)
# define CHAOS_PP_LIST_TAIL_ID() CHAOS_PP_LIST_TAIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_TAIL_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_TAIL_ID)()
# endif
#
# /* CHAOS_PP_LIST_IS_CONS */
#
# define CHAOS_PP_LIST_IS_CONS(list) CHAOS_PP_IS_BINARY(list)
# define CHAOS_PP_LIST_IS_CONS_ID() CHAOS_PP_LIST_IS_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_IS_CONS)
# endif
#
# /* CHAOS_PP_LIST_IS_NIL */
#
# define CHAOS_PP_LIST_IS_NIL(list) CHAOS_PP_COMPL(CHAOS_PP_LIST_IS_CONS(list))
# define CHAOS_PP_LIST_IS_NIL_ID() CHAOS_PP_LIST_IS_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_IS_NIL)
# endif
#
# endif
