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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_TRANSFORM_H
# define CHAOS_PREPROCESSOR_ALGORITHM_TRANSFORM_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_TRANSFORM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TRANSFORM(op, g, ...) CHAOS_PP_TRANSFORM_S(CHAOS_PP_STATE(), op, g, __VA_ARGS__)
#    define CHAOS_PP_TRANSFORM_ CHAOS_PP_LAMBDA(CHAOS_PP_TRANSFORM_ID)()
# else
#    define CHAOS_PP_TRANSFORM(op, g, data) CHAOS_PP_TRANSFORM_S(CHAOS_PP_STATE(), op, g, data)
# endif
#
# define CHAOS_PP_TRANSFORM_ID() CHAOS_PP_TRANSFORM
#
# /* CHAOS_PP_TRANSFORM_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TRANSFORM_S(s, op, g, ...) CHAOS_IP_TRANSFORM_U(s, op, g, (__VA_ARGS__))
#    define CHAOS_PP_TRANSFORM_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TRANSFORM_S_ID)()
# else
#    define CHAOS_PP_TRANSFORM_S(s, op, g, data) CHAOS_IP_TRANSFORM_U(s, op, g, (data))
# endif
#
# define CHAOS_PP_TRANSFORM_S_ID() CHAOS_PP_TRANSFORM_S
#
# define CHAOS_IP_TRANSFORM_U(s, op, g, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_TRANSFORM_I(CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), op, CHAOS_PP_TRAMPOLINE(op), CHAOS_PP_TYPEOF(g), g, pd)) \
    /**/
# define CHAOS_IP_TRANSFORM_INDIRECT() CHAOS_IP_TRANSFORM_I
# define CHAOS_IP_TRANSFORM_I(s, o, op, _o, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_TRANSFORM_II, \
        g CHAOS_PP_TUPLE_EAT(8) \
    )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, type, g, pd) \
    /**/
# define CHAOS_IP_TRANSFORM_II(_, s, o, op, _o, type, g, pd) \
    CHAOS_PP_CONS CHAOS_PP_OBSTRUCT()( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_TRANSFORM_INDIRECT _()( \
            CHAOS_PP_NEXT(s), o, op, _o, type, CHAOS_PP_REST(g), pd \
        )), \
        _o()(s, o, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd) \
    ) \
    /**/
#
# endif
