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
# ifndef CHAOS_PREPROCESSOR_CONTROL_PARAMETRIC_WHILE_H
# define CHAOS_PREPROCESSOR_CONTROL_PARAMETRIC_WHILE_H
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
# /* CHAOS_PP_WHILE_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_PARAMETRIC(size, pred, op, ...) CHAOS_PP_WHILE_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, __VA_ARGS__)
#    define CHAOS_PP_WHILE_PARAMETRIC_ID() CHAOS_PP_WHILE_PARAMETRIC
#    define CHAOS_PP_WHILE_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_WHILE_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_PARAMETRIC_S(s, size, pred, op, ...) \
        CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_WHILE_PARAMETRIC_A_INDIRECT, size, \
            pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), __VA_ARGS__ \
        ) \
        /**/
#    define CHAOS_PP_WHILE_PARAMETRIC_S_ID() CHAOS_PP_WHILE_PARAMETRIC_S
#    define CHAOS_PP_WHILE_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_PARAMETRIC_S_ID)()
#    define CHAOS_IP_WHILE_PARAMETRIC_A_INDIRECT() CHAOS_IP_WHILE_PARAMETRIC_A
#    define CHAOS_IP_WHILE_PARAMETRIC_A(s, id, para, pred, _p, op, _o, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)()( \
            s, CHAOS_IP_WHILE_PARAMETRIC_B_INDIRECT, para, _p()(s, pred, __VA_ARGS__), \
            pred, _p, op, _o, __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_WHILE_PARAMETRIC_B_INDIRECT() CHAOS_IP_WHILE_PARAMETRIC_B
#    define CHAOS_IP_WHILE_PARAMETRIC_B(s, id, para, res, pred, _p, op, _o, ...) \
        CHAOS_PP_IIF(res)( \
            CHAOS_IP_WHILE_PARAMETRIC_B_I, __VA_ARGS__ CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, pred, _p, op, _o, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_WHILE_PARAMETRIC_B_I(_, s, id, para, pred, _p, op, _o, ...) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_WHILE_PARAMETRIC_A_INDIRECT, para, pred, _p, op, _o, \
            _o()(s, op, __VA_ARGS__) \
        )) \
        /**/
# endif
#
# endif
