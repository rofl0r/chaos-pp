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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/planar.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOLD_RIGHT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT(op, g, ...) CHAOS_PP_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_RIGHT_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT(op, g, state) CHAOS_PP_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, g, state)
# endif
#
# define CHAOS_PP_FOLD_RIGHT_ID() CHAOS_PP_FOLD_RIGHT
#
# /* CHAOS_PP_FOLD_RIGHT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT_S(s, op, g, ...) CHAOS_IP_FOLD_RIGHT_U(s, op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_RIGHT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_S_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT_S(s, op, g, state) CHAOS_IP_FOLD_RIGHT_U(s, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_RIGHT_S_ID() CHAOS_PP_FOLD_RIGHT_S
#
# define CHAOS_IP_FOLD_RIGHT_U(s, op, g, ps) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOLD_RIGHT_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), \
        op, CHAOS_PP_PLANAR(op), CHAOS_PP_TYPEOF(g), g, ps \
    )) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_INDIRECT() CHAOS_IP_FOLD_RIGHT_I
# define CHAOS_IP_FOLD_RIGHT_I(s, o, op, _o, type, g, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_RIGHT_II, CHAOS_PP_REM ps CHAOS_PP_TUPLE_EAT(8) \
    )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, type, g, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_II(_, s, o, op, _o, type, g, ps) \
    _o()(o, op) \
        CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(g)), \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_RIGHT_INDIRECT _()( \
            CHAOS_PP_NEXT(s), o, op, _o, type, CHAOS_PP_TAIL(g), ps \
        )) \
    CHAOS_PP_PLANAR_CLOSE() \
    /**/
#
# endif
