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
# ifndef CHAOS_PREPROCESSOR_INSERTION_SORT_H
# define CHAOS_PREPROCESSOR_INSERTION_SORT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_INSERTION_SORT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSERTION_SORT(pred, ...) CHAOS_PP_INSERTION_SORT_S(CHAOS_PP_STATE(), pred, __VA_ARGS__)
#    define CHAOS_PP_INSERTION_SORT_ CHAOS_PP_LAMBDA(CHAOS_PP_INSERTION_SORT_ID)()
# else
#    define CHAOS_PP_INSERTION_SORT(pred, g, data) CHAOS_PP_INSERTION_SORT_S(CHAOS_PP_STATE(), pred, g, (data))
# endif
#
# define CHAOS_PP_INSERTION_SORT_ID() CHAOS_PP_INSERTION_SORT
#
# /* CHAOS_PP_INSERTION_SORT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSERTION_SORT_S(s, pred, ...) \
        CHAOS_IP_INSERTION_SORT_U(s, pred, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_INSERTION_SORT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_INSERTION_SORT_S_ID)()
# else
#    define CHAOS_PP_INSERTION_SORT_S(s, pred, g, data) CHAOS_IP_INSERTION_SORT_U(s, pred, g, data)
# endif
#
# define CHAOS_PP_INSERTION_SORT_S_ID() CHAOS_PP_INSERTION_SORT_S
#
# define CHAOS_IP_INSERTION_SORT_U(s, pred, g, pd) \
    CHAOS_IP_INSERTION_SORT_1( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), \
        CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)), CHAOS_PP_TYPEOF(g), g, pd \
    ) \
    /**/
# define CHAOS_IP_INSERTION_SORT_INDIRECT(n) CHAOS_IP_INSERTION_SORT_ ## n
# define CHAOS_IP_INSERTION_SORT_1(_, s, pred, _p, sorted, type, g, pd) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_INSERTION_SORT_INDIRECT _(1)( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_INSERTION_SORT_2 _( \
                CHAOS_PP_NEXT(s), pred, _p, sorted, type, (CHAOS_PP_HEAD _(g)), pd \
            )), \
            type, CHAOS_PP_TAIL _(g), pd \
        )), \
        sorted \
    ) \
    /**/
# define CHAOS_IP_INSERTION_SORT_2(s, pred, _p, sorted, type, key, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(sorted))( \
        CHAOS_IP_INSERTION_SORT_3, CHAOS_PP_CONS(CHAOS_PP_NIL(type), CHAOS_PP_REM key) CHAOS_PP_TUPLE_EAT(8) \
    )(CHAOS_PP_OBSTRUCT(), s, pred, _p, sorted, type, key, pd) \
    /**/
# define CHAOS_IP_INSERTION_SORT_3(_, s, pred, _p, sorted, type, key, pd) \
    CHAOS_PP_IIF _( \
        _p()(s, pred, CHAOS_PP_ITEM(type, CHAOS_PP_REM key) CHAOS_PP_COMMA() CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(sorted)) CHAOS_PP_EXPOSE(pd)) \
    )( \
        CHAOS_PP_CONS _(sorted, CHAOS_PP_REM _ key), \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_INSERTION_SORT_INDIRECT _(2)( \
                CHAOS_PP_NEXT(s), pred, _p, CHAOS_PP_TAIL _(sorted), type, key, pd \
            )), \
            CHAOS_PP_HEAD _(sorted) \
        ) \
    ) \
    /**/
#
# endif
