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
# ifndef CHAOS_PREPROCESSOR_TUPLE_TRANSFORM_H
# define CHAOS_PREPROCESSOR_TUPLE_TRANSFORM_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_TRANSFORM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_TRANSFORM(op, ...) CHAOS_PP_TUPLE_TRANSFORM_S(CHAOS_PP_STATE(), op, __VA_ARGS__)
#    define CHAOS_PP_TUPLE_TRANSFORM_ID() CHAOS_PP_TUPLE_TRANSFORM
#    define CHAOS_PP_TUPLE_TRANSFORM_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_TRANSFORM_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_TRANSFORM_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_TRANSFORM_S(s, op, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_TRANSFORM_1( \
            CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), op, CHAOS_PP_TRAMPOLINE(op), CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__) \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_TRANSFORM_S_ID() CHAOS_PP_TUPLE_TRANSFORM_S
#    define CHAOS_PP_TUPLE_TRANSFORM_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_TRANSFORM_S_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_TRANSFORM_INDIRECT(n) CHAOS_IP_TUPLE_TRANSFORM_ ## n
#    define CHAOS_IP_TUPLE_TRANSFORM_1(s, o, op, _o, tuple, pd) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_IP_TUPLE_TRANSFORM_1_I, CHAOS_IP_TUPLE_TRANSFORM_2 \
        )(s, o, op, _o, tuple, pd) \
        /**/
#    define CHAOS_IP_TUPLE_TRANSFORM_1_I(s, o, op, _o, tuple, pd) \
        CHAOS_IP_TUPLE_TRANSFORM_1_II(s, o, op, _o, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple), pd) \
        /**/
#    define CHAOS_IP_TUPLE_TRANSFORM_1_II(...) CHAOS_IP_TUPLE_TRANSFORM_1_III(CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), __VA_ARGS__)
#    define CHAOS_IP_TUPLE_TRANSFORM_1_III(_, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple, pd) \
        CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _( \
        CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _( \
            CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_PP_DEFER(CHAOS_IP_TUPLE_TRANSFORM_INDIRECT)(1)( \
                CHAOS_PP_NEXT(s), o, op, _o, tuple, pd \
            )), \
            _o()(o, op, j CHAOS_PP_EXPOSE(pd))), _o()(o, op, i CHAOS_PP_EXPOSE(pd))), _o()(o, op, h CHAOS_PP_EXPOSE(pd))), _o()(o, op, g CHAOS_PP_EXPOSE(pd))), _o()(o, op, f CHAOS_PP_EXPOSE(pd))), \
            _o()(o, op, e CHAOS_PP_EXPOSE(pd))), _o()(o, op, d CHAOS_PP_EXPOSE(pd))), _o()(o, op, c CHAOS_PP_EXPOSE(pd))), _o()(o, op, b CHAOS_PP_EXPOSE(pd))), _o()(o, op, a CHAOS_PP_EXPOSE(pd))) \
        /**/
#    define CHAOS_IP_TUPLE_TRANSFORM_2(s, o, op, _o, tuple, pd) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_IP_TUPLE_TRANSFORM_2_I, CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, tuple, pd) \
        /**/
#    define CHAOS_IP_TUPLE_TRANSFORM_2_I(_, s, o, op, _o, tuple, pd) \
        CHAOS_PP_OBSTRUCT(CHAOS_PP_TUPLE_CONS)( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_TRANSFORM_INDIRECT _(1)( \
                CHAOS_PP_NEXT(s), o, op, _o, CHAOS_PP_TUPLE_TAIL(tuple), pd \
            )), \
            _o()(o, op, CHAOS_PP_TUPLE_HEAD(tuple) CHAOS_PP_EXPOSE(pd)) \
        ) \
        /**/
# endif
#
# endif
