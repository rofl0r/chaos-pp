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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FILTER_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FILTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FILTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER(pred, g, ...) CHAOS_PP_FILTER_S(CHAOS_PP_STATE(), pred, g, __VA_ARGS__)
#    define CHAOS_PP_FILTER_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_ID)()
# else
#    define CHAOS_PP_FILTER(pred, g, data) CHAOS_PP_FILTER_S(CHAOS_PP_STATE(), pred, g, data)
# endif
#
# define CHAOS_PP_FILTER_ID() CHAOS_PP_FILTER
#
# /* CHAOS_PP_FILTER_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_S(s, pred, g, ...) CHAOS_IP_FILTER_U(s, pred, g, (__VA_ARGS__))
#    define CHAOS_PP_FILTER_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_S_ID)()
# else
#    define CHAOS_PP_FILTER_S(s, pred, g, data) CHAOS_IP_FILTER_U(s, pred, g, (data))
# endif
#
# define CHAOS_PP_FILTER_S_ID() CHAOS_PP_FILTER_S
#
# define CHAOS_IP_FILTER_U(s, pred, g, pd) \
    CHAOS_IP_FILTER_I(CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), CHAOS_PP_TYPEOF(g), g, pd) \
    /**/
# define CHAOS_IP_FILTER_INDIRECT() CHAOS_IP_FILTER_I
# define CHAOS_IP_FILTER_I(s, pred, _p, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FILTER_II, CHAOS_PP_NIL(type) CHAOS_PP_TUPLE_EAT(7) \
    )(CHAOS_PP_OBSTRUCT(), s, pred, _p, type, g, pd) \
    /**/
# define CHAOS_IP_FILTER_II(_, s, pred, _p, type, g, pd) \
    CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd))( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FILTER_INDIRECT _()( \
                CHAOS_PP_NEXT(s), pred, _p, type, CHAOS_PP_REST _(g), pd \
            )), \
            CHAOS_PP_FIRST _(g) \
        ), \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FILTER_INDIRECT _()( \
            CHAOS_PP_NEXT(s), pred, _p, type, CHAOS_PP_REST _(g), pd \
        )) \
    ) \
    /**/
#
# endif
