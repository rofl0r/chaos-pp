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
# ifndef CHAOS_PREPROCESSOR_TUPLE_FILTER_H
# define CHAOS_PREPROCESSOR_TUPLE_FILTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/binary.h>
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
# /* CHAOS_PP_TUPLE_FILTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FILTER(pred, ...) CHAOS_PP_TUPLE_FILTER_S(CHAOS_PP_STATE(), pred, __VA_ARGS__)
#    define CHAOS_PP_TUPLE_FILTER_ID() CHAOS_PP_TUPLE_FILTER
#    define CHAOS_PP_TUPLE_FILTER_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FILTER_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_FILTER_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_FILTER_S(s, pred, ...) CHAOS_IP_TUPLE_FILTER_I(s, pred, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))
#    define CHAOS_PP_TUPLE_FILTER_S_ID() CHAOS_PP_TUPLE_FILTER_S
#    define CHAOS_PP_TUPLE_FILTER_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_FILTER_S_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_FILTER_I(s, pred, tuple, pd) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_FILTER_1( \
            CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), pred, CHAOS_PP_TRAMPOLINE(pred), tuple, pd \
        )) \
        /**/
#    define CHAOS_IP_TUPLE_FILTER_INDIRECT(n) CHAOS_IP_TUPLE_FILTER_ ## n
#    define CHAOS_IP_TUPLE_FILTER_1(s, o, pred, _p, tuple, pd) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_IP_TUPLE_FILTER_1_I, CHAOS_IP_TUPLE_FILTER_2 \
        )(s, o, pred, _p, tuple, pd) \
        /**/
#    define CHAOS_IP_TUPLE_FILTER_1_I(s, o, pred, _p, tuple, pd) \
        CHAOS_IP_TUPLE_FILTER_1_II(s, o, pred, _p, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple), pd) \
        /**/
#    define CHAOS_IP_TUPLE_FILTER_1_II(...) CHAOS_IP_TUPLE_FILTER_1_III(CHAOS_PP_OBSTRUCT(), __VA_ARGS__)
#    define CHAOS_IP_TUPLE_FILTER_1_III(_, s, o, pred, _p, a, b, c, d, e, f, g, h, i, j, tuple, pd) \
        CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, a CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, b CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, c CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, d CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, e CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, f CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, g CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, h CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, i CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, j CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )(CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FILTER_INDIRECT _(1)( \
            CHAOS_PP_NEXT(s), o, pred, _p, tuple, pd \
        )), j), i), h), g), f), e), d), c), b), a) \
        /**/
#    define CHAOS_IP_TUPLE_FILTER_2(s, o, pred, _p, tuple, pd) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_IP_TUPLE_FILTER_2_I, CHAOS_PP_TUPLE_NIL() CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, o, pred, _p, tuple, pd) \
        /**/
#    define CHAOS_IP_TUPLE_FILTER_2_I(_, s, o, pred, _p, tuple, pd) \
        CHAOS_PP_OBSTRUCT(CHAOS_PP_IIF)(_p()(o, pred, CHAOS_PP_TUPLE_FIRST(tuple) CHAOS_PP_EXPOSE(pd)))( \
            CHAOS_PP_TUPLE_CONS, CHAOS_PP_BINARY(0) \
        )( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_FILTER_INDIRECT _(2)( \
                CHAOS_PP_NEXT(s), o, pred, _p, CHAOS_PP_TUPLE_REST(tuple), pd \
            )), \
            CHAOS_PP_TUPLE_FIRST(tuple) \
        ) \
        /**/
# endif
#
# endif
