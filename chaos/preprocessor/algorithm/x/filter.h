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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_X_FILTER_H
# define CHAOS_PREPROCESSOR_ALGORITHM_X_FILTER_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FILTER_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_X(size, pred, ...) CHAOS_PP_FILTER_X_S(CHAOS_PP_STATE(), size, pred, __VA_ARGS__)
#    define CHAOS_PP_FILTER_X_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_X_ID)()
# else
#    define CHAOS_PP_FILTER_X(size, pred, g, data) CHAOS_PP_FILTER_X_S(CHAOS_PP_STATE(), size, pred, g, data)
# endif
#
# define CHAOS_PP_FILTER_X_ID() CHAOS_PP_FILTER_X
#
# /* CHAOS_PP_FILTER_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_X_S(s, size, pred, ...) \
        CHAOS_IP_FILTER_X_U(s, size, pred, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FILTER_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_X_S_ID)()
# else
#    define CHAOS_PP_FILTER_X_S(s, size, pred, g, data) CHAOS_IP_FILTER_X_U(s, size, pred, g, (data))
# endif
#
# define CHAOS_PP_FILTER_X_S_ID() CHAOS_PP_FILTER_X_S
#
# define CHAOS_IP_FILTER_X_U(s, size, pred, g, pd) \
    CHAOS_IP_FILTER_X_I( \
        CHAOS_PP_NEXT(s), (CHAOS_PP_NEXT(s)), CHAOS_PP_FIXED_S(s, size), \
        0, pred, CHAOS_PP_CALL(pred), CHAOS_PP_TYPEOF(g), g, CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)), pd \
    ) \
    /**/
# define CHAOS_IP_FILTER_X_INDIRECT() CHAOS_IP_FILTER_X_I
# define CHAOS_IP_FILTER_X_I(s, jump, fix, mode, pred, _p, type, g, res, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, fix))( \
        CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
            CHAOS_IP_FILTER_X_II, CHAOS_IP_FILTER_X_III \
        ), \
        CHAOS_IP_FILTER_X_V \
    )(CHAOS_PP_PHASE(0), s, jump, fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define CHAOS_IP_FILTER_X_II(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_FILTER_X_III(_, s, (CHAOS_PP_NEXT(s)) jump, fix, mode, pred, _p, type, g, res, pd) \
    ) \
    /**/
# define CHAOS_IP_FILTER_X_III(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FILTER_X_ ## mode, \
        CHAOS_PP_IIF(mode)( \
            res CHAOS_PP_TUPLE_EAT(11), \
            CHAOS_IP_FILTER_X_IV \
        ) \
    )(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define CHAOS_IP_FILTER_X_IV(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(res))( \
        CHAOS_IP_FILTER_X_1, res CHAOS_PP_TUPLE_EAT(11) \
    )(_, s, jump, fix, 1, pred, _p, type, res, g, pd) \
    /**/
# define CHAOS_IP_FILTER_X_V(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    CHAOS_IP_FILTER_X_VI(CHAOS_PP_SEQ_HEAD(jump), CHAOS_PP_SEQ_TAIL(jump), fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define CHAOS_IP_FILTER_X_VI(s, jump, fix, mode, pred, _p, type, g, res, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
        CHAOS_IP_FILTER_X_II, CHAOS_IP_FILTER_X_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define CHAOS_IP_FILTER_X_0(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FILTER_X_INDIRECT)()( \
        CHAOS_PP_NEXT(s), jump, fix, mode, pred, _p, type, CHAOS_PP_TAIL(g), \
        _(1, CHAOS_PP_IIF)(_(0, _p)()(s, pred, CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(g)) _(0, CHAOS_PP_EXPOSE)(pd)))( \
            _(1, CHAOS_PP_CONS)(res, CHAOS_PP_HEAD(g)), res \
        ), \
        pd \
    )) \
    /**/
# define CHAOS_IP_FILTER_X_1(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FILTER_X_INDIRECT)()( \
        CHAOS_PP_NEXT(s), jump, fix, mode, pred, _p, type, CHAOS_PP_TAIL(g), CHAOS_PP_CONS(res, CHAOS_PP_HEAD(g)), pd \
    )) \
    /**/
#
# endif
