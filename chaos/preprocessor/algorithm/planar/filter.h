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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PLANAR_FILTER_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PLANAR_FILTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/invoke.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FILTER_PLANAR */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_PLANAR(pred, g, ...) CHAOS_PP_FILTER_PLANAR_S(CHAOS_PP_STATE(), pred, g, __VA_ARGS__)
#    define CHAOS_PP_FILTER_PLANAR_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_PLANAR_ID)()
# else
#    define CHAOS_PP_FILTER_PLANAR(pred, g, data) CHAOS_PP_FILTER_PLANAR_S(CHAOS_PP_STATE(), pred, g, data)
# endif
#
# define CHAOS_PP_FILTER_PLANAR_ID() CHAOS_PP_FILTER_PLANAR
#
# /* CHAOS_PP_FILTER_PLANAR_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_PLANAR_S(s, pred, g, ...) CHAOS_IP_FILTER_PLANAR_U(s, pred, CHAOS_PP_IS_VARIADIC(pred), g, (__VA_ARGS__))
#    define CHAOS_PP_FILTER_PLANAR_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_PLANAR_S_ID)()
# else
#    define CHAOS_PP_FILTER_PLANAR_S(s, pred, g, data) CHAOS_IP_FILTER_PLANAR_U(s, pred, 0, g, (data))
# endif
#
# define CHAOS_PP_FILTER_PLANAR_S_ID() CHAOS_PP_FILTER_PLANAR_S
#
# define CHAOS_IP_FILTER_PLANAR_U(s, pred, v, g, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FILTER_PLANAR_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), pred, \
        CHAOS_PP_IIF(v)(CHAOS_PP_INVOKE_S, pred), CHAOS_PP_IIF(v)(pred CHAOS_PP_COMMA, CHAOS_PP_EMPTY), \
        CHAOS_PP_TYPEOF(g), g, pd \
    )) \
    /**/
# define CHAOS_IP_FILTER_PLANAR_INDIRECT() CHAOS_IP_FILTER_PLANAR_I
# define CHAOS_IP_FILTER_PLANAR_I(s, o, pred, a, b, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FILTER_PLANAR_II, CHAOS_PP_NIL(type) CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), s, o, pred, a, b, type, g, pd) \
    /**/
# define CHAOS_IP_FILTER_PLANAR_II(_, s, o, pred, a, b, type, g, pd) \
    CHAOS_PP_IIF _(CHAOS_PP_EXPR_S _(o)(a _(o, b() CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)), CHAOS_PP_UNPACK pd)))( \
        CHAOS_PP_CONS, CHAOS_IP_FILTER_PLANAR_III \
    )( \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_FILTER_PLANAR_INDIRECT)()( \
            CHAOS_PP_NEXT(s), o, pred, a, b, type, CHAOS_PP_REST(g), pd \
        )), \
        CHAOS_PP_FIRST(g) \
    ) \
    /**/
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_FILTER_PLANAR_III(g, ...) g
# else
#    define CHAOS_IP_FILTER_PLANAR_III(g, x) g
# endif
#
# endif
