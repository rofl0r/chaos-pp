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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FILTER_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FILTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FILTER_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_PARAMETRIC(size, pred, g, ...) CHAOS_PP_FILTER_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, g, __VA_ARGS__)
#    define CHAOS_PP_FILTER_PARAMETRIC_ID() CHAOS_PP_FILTER_PARAMETRIC
#    define CHAOS_PP_FILTER_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_FILTER_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FILTER_PARAMETRIC_S(s, size, pred, g, ...) \
        CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_FILTER_PARAMETRIC_A_INDIRECT, size, \
            CHAOS_PP_DEFER, pred, CHAOS_PP_CALL(pred), CHAOS_PP_TYPEOF(g), g, CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)), __VA_ARGS__ \
        ) \
        /**/
#    define CHAOS_PP_FILTER_PARAMETRIC_S_ID() CHAOS_PP_FILTER_PARAMETRIC_S
#    define CHAOS_PP_FILTER_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FILTER_PARAMETRIC_S_ID)()
#    define CHAOS_IP_FILTER_PARAMETRIC_A_INDIRECT() CHAOS_IP_FILTER_PARAMETRIC_A
#    define CHAOS_IP_FILTER_PARAMETRIC_A(s, id, para, _, pred, _p, type, g1, g2, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g1))( \
            CHAOS_IP_FILTER_PARAMETRIC_A_I, CHAOS_IP_FILTER_PARAMETRIC_B \
        )(s, id, para, _, pred, _p, type, g1, g2, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_FILTER_PARAMETRIC_A_I(s, id, para, _, pred, _p, type, g1, g2, ...) \
        _(CHAOS_PP_EXPR_S(s))(_(id)()( \
            s, CHAOS_IP_FILTER_PARAMETRIC_A_INDIRECT, para, _, pred, _p, type, CHAOS_PP_REST(g1), \
            _(CHAOS_PP_IIF)(_p()(s, pred, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g1)), __VA_ARGS__))( \
                _(CHAOS_PP_CONS)(g2, _(CHAOS_PP_FIRST)(g1)), g2 \
            ), __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_FILTER_PARAMETRIC_B_INDIRECT() CHAOS_IP_FILTER_PARAMETRIC_B
#    define CHAOS_IP_FILTER_PARAMETRIC_B(s, id, para, _, pred, _p, type, g1, g2, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g2))( \
            CHAOS_IP_FILTER_PARAMETRIC_B_I, g1 CHAOS_PP_TUPLE_EAT(?) \
        )(s, id, para, CHAOS_PP_OBSTRUCT(), g1, g2) \
        /**/
#    define CHAOS_IP_FILTER_PARAMETRIC_B_I(s, id, para, _, g1, g2) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_FILTER_PARAMETRIC_B_INDIRECT, para,,,,, CHAOS_PP_CONS(g1, CHAOS_PP_FIRST(g2)), CHAOS_PP_REST(g2), \
        )) \
        /**/
# endif
#
# endif
