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
# ifndef CHAOS_PREPROCESSOR_TUPLE_FOLD_RIGHT_H
# define CHAOS_PREPROCESSOR_TUPLE_FOLD_RIGHT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/planar.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_FOLD_RIGHT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FOLD_RIGHT(op, tuple, ...) CHAOS_PP_TUPLE_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, tuple, __VA_ARGS__)
#    define CHAOS_PP_TUPLE_FOLD_RIGHT_ID() CHAOS_PP_TUPLE_FOLD_RIGHT
#    define CHAOS_PP_TUPLE_FOLD_RIGHT_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FOLD_RIGHT_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_FOLD_RIGHT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FOLD_RIGHT_S(s, op, tuple, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_FOLD_RIGHT_1( \
            CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), op, CHAOS_PP_PLANAR(op), tuple, __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_FOLD_RIGHT_S_ID() CHAOS_PP_TUPLE_FOLD_RIGHT_S
#    define CHAOS_PP_TUPLE_FOLD_RIGHT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FOLD_RIGHT_S_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_INDIRECT(n) CHAOS_IP_TUPLE_FOLD_RIGHT_ ## n
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_1(s, o, op, _o, tuple, ...) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_IP_TUPLE_FOLD_RIGHT_1_I, CHAOS_IP_TUPLE_FOLD_RIGHT_2 \
        )(s, o, op, _o, tuple, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_1_I(s, o, op, _o, tuple, ...) \
        CHAOS_IP_TUPLE_FOLD_RIGHT_1_II(s, o, op, _o, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple), __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_1_II(...) CHAOS_IP_TUPLE_FOLD_RIGHT_1_III(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PLANAR_CLOSE, __VA_ARGS__)
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_1_III(_, cl, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple, ...) \
        _o()(o, op) a, _o()(o, op) b, _o()(o, op) c, _o()(o, op) d, _o()(o, op) e, \
        _o()(o, op) f, _o()(o, op) g, _o()(o, op) h, _o()(o, op) i, _o()(o, op) j, \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_RIGHT_INDIRECT _(1)( \
            CHAOS_PP_NEXT(s), o, op, _o, tuple, __VA_ARGS__ \
        )) \
        cl() cl() cl() cl() cl() cl() cl() cl() cl() cl()
        /**/
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_2(s, o, op, _o, tuple, ...) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_IP_TUPLE_FOLD_RIGHT_2_I, __VA_ARGS__ CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, tuple, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_RIGHT_2_I(_, s, o, op, _o, tuple, ...) \
        _o()(o, op) CHAOS_PP_TUPLE_HEAD(tuple), \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_RIGHT_INDIRECT _(2)( \
            CHAOS_PP_NEXT(s), o, op, _o, CHAOS_PP_TUPLE_TAIL(tuple), __VA_ARGS__ \
        )) \
        CHAOS_PP_PLANAR_CLOSE() \
        /**/
# endif
#
# endif
