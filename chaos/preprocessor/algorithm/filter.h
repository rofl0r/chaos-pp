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
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FILTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER(pred, ...) CHAOS_PP_FILTER_S(CHAOS_PP_STATE(), pred, __VA_ARGS__)
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
#    define CHAOS_PP_FILTER_S(s, pred, ...) CHAOS_IP_FILTER_U(s, pred, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))
#    define CHAOS_PP_FILTER_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_S_ID)()
# else
#    define CHAOS_PP_FILTER_S(s, pred, g, data) CHAOS_IP_FILTER_U(s, pred, g, (data))
# endif
#
# define CHAOS_PP_FILTER_S_ID() CHAOS_PP_FILTER_S
#
# define CHAOS_IP_FILTER_U(s, pred, g, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FILTER_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), pred, CHAOS_PP_TRAMPOLINE(pred), CHAOS_PP_TYPEOF(g), g, pd \
    )) \
    /**/
# define CHAOS_IP_FILTER_INDIRECT() CHAOS_IP_FILTER_I
# define CHAOS_IP_FILTER_I(s, o, pred, _p, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FILTER_II, g CHAOS_PP_TUPLE_EAT(8) \
    )(CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), s, o, pred, _p, type, g, pd) \
    /**/
# define CHAOS_IP_FILTER_II(_, s, o, pred, _p, type, g, pd) \
    CHAOS_PP_IIF _(_p()(o, pred, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_EXPOSE(pd)))( \
        CHAOS_PP_CONS, CHAOS_IP_FILTER_III \
    )( \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_FILTER_INDIRECT)()( \
            CHAOS_PP_NEXT(s), o, pred, _p, type, CHAOS_PP_REST(g), pd \
        )), \
        CHAOS_PP_FIRST(g) \
    ) \
    /**/
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_FILTER_III(g, ...) g
# else
#    define CHAOS_IP_FILTER_III(g, x) g
# endif
#
# endif
