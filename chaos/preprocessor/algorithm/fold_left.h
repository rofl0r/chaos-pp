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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOLD_LEFT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/planar.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOLD_LEFT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT(op, g, ...) CHAOS_PP_FOLD_LEFT_S(CHAOS_PP_STATE(), op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_LEFT_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT(op, g, state) CHAOS_PP_FOLD_LEFT_S(CHAOS_PP_STATE(), op, g, state)
# endif
#
# define CHAOS_PP_FOLD_LEFT_ID() CHAOS_PP_FOLD_LEFT
#
# /* CHAOS_PP_FOLD_LEFT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_S(s, op, g, ...) CHAOS_IP_FOLD_LEFT_U(s, op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_LEFT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_S_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT_S(s, op, g, state) CHAOS_IP_FOLD_LEFT_U(s, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_LEFT_S_ID() CHAOS_PP_FOLD_LEFT_S
#
# define CHAOS_IP_FOLD_LEFT_U(s, op, g, ps) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOLD_LEFT_1( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), \
        op, CHAOS_PP_PLANAR(op), CHAOS_PP_TYPEOF(g), g \
    ) CHAOS_PP_REM ps CHAOS_IP_FOLD_LEFT_2(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), g)) \
    /**/
# define CHAOS_IP_FOLD_LEFT_INDIRECT(n) CHAOS_IP_FOLD_LEFT_ ## n
# define CHAOS_IP_FOLD_LEFT_1(s, o, op, _o, type, g) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_LEFT_1_I, CHAOS_PP_TUPLE_EAT(7) \
    )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, type, g) \
    /**/
# define CHAOS_IP_FOLD_LEFT_1_I(_, s, o, op, _o, type, g) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_LEFT_INDIRECT _(1)( \
        CHAOS_PP_NEXT(s), o, op, _o, type, CHAOS_PP_TAIL(g) \
    )) \
    _o()(o, op) CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(g)), \
    /**/
# define CHAOS_IP_FOLD_LEFT_2(_, s, g) \
    CHAOS_PP_INLINE_WHEN _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_PLANAR_CLOSE _() \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_LEFT_INDIRECT _(2)( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_TAIL _(g) \
        )) \
    ) \
    /**/
#
# endif
