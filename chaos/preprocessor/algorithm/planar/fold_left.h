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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PLANAR_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PLANAR_FOLD_LEFT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/invoke.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOLD_LEFT_PLANAR */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_PLANAR(op, g, ...) CHAOS_PP_FOLD_LEFT_PLANAR_S(CHAOS_PP_STATE(), op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_LEFT_PLANAR_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_PLANAR_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT_PLANAR(op, g, state) CHAOS_PP_FOLD_LEFT_PLANAR_S(CHAOS_PP_STATE(), op, g, state)
# endif
#
# define CHAOS_PP_FOLD_LEFT_PLANAR_ID() CHAOS_PP_FOLD_LEFT_PLANAR
#
# /* CHAOS_PP_FOLD_LEFT_PLANAR_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_PLANAR_S(s, op, g, ...) CHAOS_IP_FOLD_LEFT_PLANAR_U(s, CHAOS_PP_IS_VARIADIC(op), op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_LEFT_PLANAR_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_PLANAR_S_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT_PLANAR_S(s, op, g, state) CHAOS_IP_FOLD_LEFT_PLANAR_U(s, 0, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_LEFT_PLANAR_S_ID() CHAOS_PP_FOLD_LEFT_PLANAR_S
#
# define CHAOS_IP_FOLD_LEFT_PLANAR_U(s, v, op, g, ps) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOLD_LEFT_PLANAR_I(CHAOS_PP_NEXT(s), v, op, g, ps)) \
    /**/
# define CHAOS_IP_FOLD_LEFT_PLANAR_I(s, v, op, g, ps) \
    CHAOS_IP_FOLD_LEFT_PLANAR_1( \
        s, s, op, CHAOS_PP_IIF(v)(CHAOS_PP_INVOKE_S, op), CHAOS_PP_IIF(v)(pred CHAOS_PP_COMMA, CHAOS_PP_EMPTY), CHAOS_PP_TYPEOF(g), g \
    ) \
    CHAOS_PP_UNPACK CHAOS_PP_OBSTRUCT() ps CHAOS_IP_FOLD_LEFT_PLANAR_2(CHAOS_PP_OBSTRUCT(), s, g) \
    /**/
# define CHAOS_IP_FOLD_LEFT_PLANAR_INDIRECT(n) CHAOS_IP_FOLD_LEFT_PLANAR_ ## n
# define CHAOS_IP_FOLD_LEFT_PLANAR_1(s, o, op, _a, _b, type, g) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_LEFT_PLANAR_1_I, CHAOS_PP_TUPLE_EAT(8) \
    )(CHAOS_PP_OBSTRUCT(), s, o, op, _a, _b, type, g) \
    /**/
# define CHAOS_IP_FOLD_LEFT_PLANAR_1_I(_, s, o, op, _a, _b, type, g) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_LEFT_PLANAR_INDIRECT _(1)( \
        CHAOS_PP_NEXT(s), o, op, _a, _b, type, CHAOS_PP_REST(g) \
    )) \
    CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(_a CHAOS_PP_OBSTRUCT()(o, _b() CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)), \
    /**/
# define CHAOS_IP_FOLD_LEFT_PLANAR_2(_, s, g) \
    CHAOS_PP_EXPR_IIF _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_RPAREN _() CHAOS_PP_RPAREN _() \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_LEFT_PLANAR_INDIRECT _(2)( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_REST _(g) \
        )) \
    ) \
    /**/
#
# endif
