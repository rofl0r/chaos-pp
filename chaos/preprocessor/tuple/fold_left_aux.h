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
# ifndef CHAOS_PREPROCESSOR_TUPLE_FOLD_LEFT_AUX_H
# define CHAOS_PREPROCESSOR_TUPLE_FOLD_LEFT_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/planar.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_FOLD_LEFT_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FOLD_LEFT_AUX(op, tuple, data, ...) CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S(CHAOS_PP_STATE(), op, tuple, data, __VA_ARGS__)
#    define CHAOS_PP_TUPLE_FOLD_LEFT_AUX_ID() CHAOS_PP_TUPLE_FOLD_LEFT_AUX
#    define CHAOS_PP_TUPLE_FOLD_LEFT_AUX_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FOLD_LEFT_AUX_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S(s, op, tuple, data, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1( \
            CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), op, CHAOS_PP_PLANAR(op), tuple, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(data))(CHAOS_PP_REM) data \
        ) __VA_ARGS__ CHAOS_IP_TUPLE_FOLD_LEFT_AUX_3(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), tuple)) \
        /**/
#    define CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S_ID() CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S
#    define CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FOLD_LEFT_AUX_S_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_INDIRECT(n) CHAOS_IP_TUPLE_FOLD_LEFT_AUX_ ## n
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1(s, o, op, _o, tuple, ...) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1_I, CHAOS_IP_TUPLE_FOLD_LEFT_AUX_2 \
        )(s, o, op, _o, tuple, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1_I(s, o, op, _o, tuple, ...) \
        CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1_II(s, o, op, _o, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple), __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1_II(...) CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1_III(CHAOS_PP_OBSTRUCT(), __VA_ARGS__)
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_1_III(_, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple, ...) \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(1)( \
            CHAOS_PP_NEXT(s), o, op, _o, tuple, __VA_ARGS__ \
        )) \
        _o()(o, op) j, __VA_ARGS__, _o()(o, op) i, __VA_ARGS__, _o()(o, op) h, __VA_ARGS__, _o()(o, op) g, __VA_ARGS__, _o()(o, op) f, __VA_ARGS__, \
        _o()(o, op) e, __VA_ARGS__, _o()(o, op) d, __VA_ARGS__, _o()(o, op) c, __VA_ARGS__, _o()(o, op) b, __VA_ARGS__, _o()(o, op) a, __VA_ARGS__, \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_2(s, o, op, _o, tuple, ...) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_IP_TUPLE_FOLD_LEFT_AUX_2_I, CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, tuple, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_2_I(_, s, o, op, _o, tuple, ...) \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(2)( \
            CHAOS_PP_NEXT(s), o, op, _o, CHAOS_PP_TUPLE_TAIL(tuple), __VA_ARGS__ \
        )) \
        _o()(o, op) CHAOS_PP_TUPLE_HEAD(tuple), __VA_ARGS__, \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_3(_, s, tuple) \
        CHAOS_PP_IIF _(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() \
            CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() CHAOS_PP_PLANAR_CLOSE _() \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(3)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_TUPLE_SANS_BATCH _(10, tuple) \
            )), \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(4)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), tuple \
            )) \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_FOLD_LEFT_AUX_4(_, s, tuple) \
        CHAOS_PP_INLINE_WHEN _(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_PP_PLANAR_CLOSE _() \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(4)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_TUPLE_TAIL _(tuple) \
            )) \
        ) \
        /**/
# endif
#
# endif
