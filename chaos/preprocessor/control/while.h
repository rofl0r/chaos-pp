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
# ifndef CHAOS_PREPROCESSOR_CONTROL_WHILE_H
# define CHAOS_PREPROCESSOR_CONTROL_WHILE_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_WHILE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE(pred, op, ...) CHAOS_PP_WHILE_S(CHAOS_PP_STATE(), pred, op, __VA_ARGS__)
#    define CHAOS_PP_WHILE_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_ID)()
# else
#    define CHAOS_PP_WHILE(pred, op, state) CHAOS_PP_WHILE_S(CHAOS_PP_STATE(), pred, op, state)
# endif
#
# define CHAOS_PP_WHILE_ID() CHAOS_PP_WHILE
#
# /* CHAOS_PP_WHILE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_S(s, pred, op, ...) CHAOS_IP_WHILE_U(s, pred, op, (__VA_ARGS__))
#    define CHAOS_PP_WHILE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_S_ID)()
# else
#    define CHAOS_PP_WHILE_S(s, pred, op, state) CHAOS_IP_WHILE_U(s, pred, op, (state))
# endif
#
# define CHAOS_PP_WHILE_S_ID() CHAOS_PP_WHILE_S
#
# define CHAOS_IP_WHILE_U(s, pred, op, ps) \
    CHAOS_IP_WHILE_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), ps) \
    /**/
# define CHAOS_IP_WHILE_INDIRECT() CHAOS_IP_WHILE_I
# define CHAOS_IP_WHILE_I(_, s, pred, _p, op, _o, ps) \
    CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_UNPACK ps))( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_WHILE_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, op, _o, (_o()(s, op, CHAOS_PP_UNPACK ps)) \
        )), \
        CHAOS_PP_UNPACK ps \
    ) \
    /**/
#
# /* CHAOS_PP_WHILE_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_PARAMETRIC(size, pred, op, ...) CHAOS_PP_WHILE_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, __VA_ARGS__)
#    define CHAOS_PP_WHILE_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_WHILE_PARAMETRIC(size, pred, op, state) CHAOS_PP_WHILE_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, state)
# endif
#
# define CHAOS_PP_WHILE_PARAMETRIC_ID() CHAOS_PP_WHILE_PARAMETRIC
#
# /* CHAOS_PP_WHILE_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_PARAMETRIC_S(s, size, pred, op, ...) CHAOS_IP_WHILE_PARAMETRIC_U(s, size, pred, op, (__VA_ARGS__))
#    define CHAOS_PP_WHILE_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_WHILE_PARAMETRIC_S(s, size, pred, op, state) CHAOS_IP_WHILE_PARAMETRIC_U(s, size, pred, op, (state))
# endif
#
# define CHAOS_PP_WHILE_PARAMETRIC_S_ID() CHAOS_PP_WHILE_PARAMETRIC_S
#
# define CHAOS_IP_WHILE_PARAMETRIC_U(s, size, pred, op, ps) \
    CHAOS_IP_WHILE_PARAMETRIC_I(CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), pred, op, ps) \
    /**/
# define CHAOS_IP_WHILE_PARAMETRIC_I(s, buffer, pred, op, ps) \
    CHAOS_IP_WHILE_PARAMETRIC_II(s, s, buffer, buffer, pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), ps) \
    /**/
# define CHAOS_IP_WHILE_PARAMETRIC_INDIRECT() CHAOS_IP_WHILE_PARAMETRIC_II
# define CHAOS_IP_WHILE_PARAMETRIC_II(s, o, buffer, shelf, pred, _p, op, _o, ps) \
    CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(buffer))(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR)))( \
        CHAOS_IP_WHILE_PARAMETRIC_III, CHAOS_IP_WHILE_PARAMETRIC_P \
    )(s, o, buffer, shelf, pred, _p, op, _o, ps) \
    /**/
# define CHAOS_IP_WHILE_PARAMETRIC_III(s, o, buffer, shelf, pred, _p, op, _o, ps) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_PP_IIF)(_p()(s, pred, CHAOS_PP_UNPACK ps))( \
        CHAOS_IP_WHILE_PARAMETRIC_IV, \
        CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, op, _o, ps)) \
    /**/
# define CHAOS_IP_WHILE_PARAMETRIC_IV(s, o, buffer, shelf, pred, _p, op, _o, ps) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_WHILE_PARAMETRIC_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, op, _o, (_o()(s, op, CHAOS_PP_UNPACK ps)) \
    )) \
    /**/
# define CHAOS_IP_WHILE_PARAMETRIC_P(s, o, buffer, shelf, pred, _p, op, _o, ps) \
    CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(CHAOS_IP_WHILE_PARAMETRIC_INDIRECT CHAOS_PP_OBSTRUCT()()( \
        CHAOS_PP_NEXT(o), o, CHAOS_PP_NEXT(shelf), shelf, pred, _p, op, _o, ps \
    )) \
    /**/
#
# endif
