# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_FOR_H
# define CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_FOR_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_PARAMETRIC(size, pred, op, macro, ...) CHAOS_PP_FOR_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_PARAMETRIC_ID() CHAOS_PP_FOR_PARAMETRIC
#    define CHAOS_PP_FOR_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_FOR_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_PARAMETRIC_S(s, size, pred, op, macro, ...) \
        CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_FOR_PARAMETRIC_A_INDIRECT, size, \
            pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), macro, CHAOS_PP_CALL(macro), __VA_ARGS__ \
        ) \
        /**/
#    define CHAOS_PP_FOR_PARAMETRIC_S_ID() CHAOS_PP_FOR_PARAMETRIC_S
#    define CHAOS_PP_FOR_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_PARAMETRIC_S_ID)()
#    define CHAOS_IP_FOR_PARAMETRIC_A_INDIRECT() CHAOS_IP_FOR_PARAMETRIC_A
#    define CHAOS_IP_FOR_PARAMETRIC_A(s, id, para, pred, _p, op, _o, macro, _m, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)()( \
            s, CHAOS_IP_FOR_PARAMETRIC_B_INDIRECT, para, _p()(s, pred, __VA_ARGS__), \
            pred, _p, op, _o, macro, _m, __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_FOR_PARAMETRIC_B_INDIRECT() CHAOS_IP_FOR_PARAMETRIC_B
#    define CHAOS_IP_FOR_PARAMETRIC_B(s, id, para, res, ...) \
        CHAOS_PP_IIF(res)( \
            CHAOS_IP_FOR_PARAMETRIC_B_I, CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_FOR_PARAMETRIC_B_I(_, s, id, para, pred, _p, op, _o, macro, _m, ...) \
        _m()(s, macro, __VA_ARGS__) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_FOR_PARAMETRIC_A_INDIRECT, para, pred, _p, op, _o, macro, _m, \
            _o()(s, op, __VA_ARGS__) \
        )) \
        /**/
# endif
#
# endif
