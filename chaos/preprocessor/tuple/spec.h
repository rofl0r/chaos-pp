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
# ifndef CHAOS_PREPROCESSOR_TUPLE_SPEC_H
# define CHAOS_PREPROCESSOR_TUPLE_SPEC_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE CHAOS_PP_TUPLE
# endif
#
# /* CHAOS_PP_TUPLE_TAG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_TAG(tag) tag
#    define CHAOS_PP_TUPLE_TAG_ID() CHAOS_PP_TUPLE_TAG
#    define CHAOS_PP_TUPLE_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_TAG)
# endif
#
# /* CHAOS_PP_TUPLE_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_NIL()
#    define CHAOS_PP_TUPLE_NIL_ID() CHAOS_PP_TUPLE_NIL
#    define CHAOS_PP_TUPLE_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_NIL)
# endif
#
# /* CHAOS_PP_TUPLE_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_CONS(tuple, x) \
        (x CHAOS_PP_EXPR_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))(, CHAOS_PP_TUPLE_REM(?) tuple)) \
        /**/
#    define CHAOS_PP_TUPLE_CONS_ID() CHAOS_PP_TUPLE_CONS
#    define CHAOS_PP_TUPLE_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_CONS_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_ITEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_ITEM(x) x
#    define CHAOS_PP_TUPLE_ITEM_ID() CHAOS_PP_TUPLE_ITEM
#    define CHAOS_PP_TUPLE_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_ITEM_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_FIRST */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FIRST(tuple) CHAOS_PP_SPLIT(0, CHAOS_PP_TUPLE_REM(?) tuple,)
#    define CHAOS_PP_TUPLE_FIRST_ID() CHAOS_PP_TUPLE_FIRST
#    define CHAOS_PP_TUPLE_FIRST_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FIRST_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_REST */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REST(tuple) \
        CHAOS_PP_EXPR_IIF( \
            CHAOS_PP_COMPL(CHAOS_PP_IS_EMPTY_NON_FUNCTION(CHAOS_PP_SPLIT(1, CHAOS_PP_TUPLE_REM(?) tuple,))) \
        )((CHAOS_PP_SPLIT(1, CHAOS_PP_TUPLE_REM(?) tuple))) \
        /**/
#    define CHAOS_PP_TUPLE_REST_ID() CHAOS_PP_TUPLE_REST
#    define CHAOS_PP_TUPLE_REST_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REST_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_IS_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_IS_CONS(tuple) CHAOS_PP_IS_VARIADIC(tuple)
#    define CHAOS_PP_TUPLE_IS_CONS_ID() CHAOS_PP_TUPLE_IS_CONS
#    define CHAOS_PP_TUPLE_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_IS_CONS)
# endif
#
# /* CHAOS_PP_TUPLE_IS_NIL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_IS_NIL(tuple) CHAOS_PP_COMPL(CHAOS_PP_TUPLE_IS_CONS(tuple))
#    define CHAOS_PP_TUPLE_IS_NIL_ID() CHAOS_PP_TUPLE_IS_NIL
#    define CHAOS_PP_TUPLE_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_IS_NIL)
# endif
#
# endif
