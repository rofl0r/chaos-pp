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
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/type.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
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
# /* CHAOS_PP_FILTER_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_PARAMETRIC(size, pred, g, ...) CHAOS_PP_FILTER_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, g, __VA_ARGS__)
#    define CHAOS_PP_FILTER_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_FILTER_PARAMETRIC(size, pred, g, data) CHAOS_PP_FILTER_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, g, data)
# endif
#
# define CHAOS_PP_FILTER_PARAMETRIC_ID() CHAOS_PP_FILTER_PARAMETRIC
#
# /* CHAOS_PP_FILTER_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_PARAMETRIC_S(s, size, pred, g, ...) CHAOS_IP_FILTER_PARAMETRIC_U(s, size, pred, g, (__VA_ARGS__))
#    define CHAOS_PP_FILTER_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_FILTER_PARAMETRIC_S(s, size, pred, g, data) CHAOS_IP_FILTER_PARAMETRIC_U(s, size, pred, g, (data))
# endif
#
# define CHAOS_PP_FILTER_PARAMETRIC_S_ID() CHAOS_PP_FILTER_PARAMETRIC_S
#
# define CHAOS_IP_FILTER_PARAMETRIC_U(s, size, pred, g, pd) CHAOS_IP_FILTER_PARAMETRIC_I(CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), pred, CHAOS_PP_TYPEOF(g), g, pd)
# define CHAOS_IP_FILTER_PARAMETRIC_I(s, buffer, pred, type, g, pd) CHAOS_IP_FILTER_PARAMETRIC_II(00, s, s, buffer, buffer, pred, CHAOS_PP_CALL(pred), type, g, CHAOS_PP_NIL(type), pd)
# define CHAOS_IP_FILTER_PARAMETRIC_INDIRECT() CHAOS_IP_FILTER_PARAMETRIC_II
# define CHAOS_IP_FILTER_PARAMETRIC_II(id, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(buffer))(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR)))( \
        CHAOS_IP_FILTER_PARAMETRIC_ ## id, CHAOS_IP_FILTER_PARAMETRIC_P \
    )(id, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    /**/
# define CHAOS_IP_FILTER_PARAMETRIC_00(id, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FILTER_PARAMETRIC_01, CHAOS_IP_FILTER_PARAMETRIC_10 \
    )(CHAOS_PP_OBSTRUCT(), s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    /**/
# define CHAOS_IP_FILTER_PARAMETRIC_01(_, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FILTER_PARAMETRIC_INDIRECT _()( \
        00, CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, type, CHAOS_PP_REST(g), \
        CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd))( \
            CHAOS_PP_CONS _(r, CHAOS_PP_FIRST _(g)), r \
        ), pd \
    )) \
    /**/
# define CHAOS_IP_FILTER_PARAMETRIC_10(id, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(r))( \
        CHAOS_IP_FILTER_PARAMETRIC_11, g CHAOS_PP_TUPLE_EAT(11) \
    )(CHAOS_PP_OBSTRUCT(), s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    /**/
# define CHAOS_IP_FILTER_PARAMETRIC_11(_, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FILTER_PARAMETRIC_INDIRECT _()( \
        10, CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, type, CHAOS_PP_CONS(g, CHAOS_PP_FIRST(r)), CHAOS_PP_REST(r), pd \
    )) \
    /**/
# define CHAOS_IP_FILTER_PARAMETRIC_P(id, s, o, buffer, shelf, pred, _p, type, g, r, pd) \
    CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(CHAOS_IP_FILTER_PARAMETRIC_ ## id CHAOS_PP_OBSTRUCT()( \
        id, CHAOS_PP_NEXT(o), o, CHAOS_PP_NEXT(shelf), shelf, pred, _p, type, g, r, pd \
    )) \
    /**/
#
# endif
