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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOLD_LEFT_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
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
# /* CHAOS_PP_FOLD_LEFT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT(op, g, ...) CHAOS_PP_FOLD_LEFT_S(CHAOS_PP_STATE(), op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_LEFT_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT(op, g, state) CHAOS_PP_FOLD_LEFT_S(CHAOS_PP_STATE(), op, g, state)
# endif
#
# define CHAOS_PP_FOLD_LEFT_ID() CHAOS_PP_FOLD_LEFT
#
# /* CHAOS_PP_FOLD_LEFT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_S(s, op, g, ...) CHAOS_IP_FOLD_LEFT_U(s, op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_LEFT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_S_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT_S(s, op, g, state) CHAOS_IP_FOLD_LEFT_U(s, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_LEFT_S_ID() CHAOS_PP_FOLD_LEFT_S
#
# define CHAOS_IP_FOLD_LEFT_U(s, op, g, ps) CHAOS_IP_FOLD_LEFT_I(CHAOS_PP_NEXT(s), op, CHAOS_PP_CALL(op), CHAOS_PP_TYPEOF(g), g, ps)
# define CHAOS_IP_FOLD_LEFT_INDIRECT() CHAOS_IP_FOLD_LEFT_I
# define CHAOS_IP_FOLD_LEFT_I(s, op, _o, type, g, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_LEFT_II, CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(7) \
    )(CHAOS_PP_OBSTRUCT(), s, op, _o, type, g, ps) \
    /**/
# define CHAOS_IP_FOLD_LEFT_II(_, s, op, _o, type, g, ps) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_LEFT_INDIRECT _()( \
        CHAOS_PP_NEXT(s), op, _o, type, CHAOS_PP_REST(g), \
        (_o()(s, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK ps)) \
    )) \
    /**/
#
# /* CHAOS_PP_FOLD_LEFT_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC(size, op, g, ...) CHAOS_PP_FOLD_LEFT_PARAMETRIC_S(CHAOS_PP_STATE(), size, op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC(size, op, g, state) CHAOS_PP_FOLD_LEFT_PARAMETRIC_S(CHAOS_PP_STATE(), size, op, g, state)
# endif
#
# define CHAOS_PP_FOLD_LEFT_PARAMETRIC_ID() CHAOS_PP_FOLD_LEFT_PARAMETRIC
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S(s, size, op, g, ...) CHAOS_IP_FOLD_LEFT_PARAMETRIC_U(s, size, op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S(s, size, op, g, state) CHAOS_IP_FOLD_LEFT_PARAMETRIC_U(s, size, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S_ID() CHAOS_PP_FOLD_LEFT_PARAMETRIC_S
#
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_U(s, size, op, g, ps) CHAOS_IP_FOLD_LEFT_PARAMETRIC_I(CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), op, g, ps)
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_I(s, buffer, op, g, ps) CHAOS_IP_FOLD_LEFT_PARAMETRIC_II(s, s, buffer, buffer, op, CHAOS_PP_CALL(op), CHAOS_PP_TYPEOF(g), g, ps)
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_INDIRECT() CHAOS_IP_FOLD_LEFT_PARAMETRIC_II
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_II(s, o, buffer, shelf, op, _o, type, g, ps) \
    CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(buffer))(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR)))( \
        CHAOS_IP_FOLD_LEFT_PARAMETRIC_III, CHAOS_IP_FOLD_LEFT_PARAMETRIC_P \
    )(s, o, buffer, shelf, op, _o, type, g, ps) \
    /**/
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_III(s, o, buffer, shelf, op, _o, type, g, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_LEFT_PARAMETRIC_IV, CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(10) \
    )(CHAOS_PP_OBSTRUCT(), s, o, buffer, shelf, op, _o, type, g, ps) \
    /**/
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_IV(_, s, o, buffer, shelf, op, _o, type, g, ps) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_LEFT_PARAMETRIC_INDIRECT _()( \
        CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, op, _o, type, CHAOS_PP_REST(g), \
        (_o()(s, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK ps)) \
    )) \
    /**/
# define CHAOS_IP_FOLD_LEFT_PARAMETRIC_P(s, o, buffer, shelf, op, _o, type, g, ps) \
    CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(CHAOS_IP_FOLD_LEFT_PARAMETRIC_INDIRECT CHAOS_PP_OBSTRUCT()()( \
        CHAOS_PP_NEXT(o), o, CHAOS_PP_NEXT(shelf), shelf, op, _o, type, g, ps \
    )) \
    /**/
#
# endif
