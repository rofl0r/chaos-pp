# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_CONTROL_WHILE_AUX_H
# define CHAOS_PREPROCESSOR_CONTROL_WHILE_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_WHILE_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_AUX(pred, op, data, ...) CHAOS_PP_WHILE_AUX_S(CHAOS_PP_STATE(), pred, op, data, __VA_ARGS__)
#    define CHAOS_PP_WHILE_AUX_() CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_AUX_ID)()
# else
#    define CHAOS_PP_WHILE_AUX(pred, op, data, state) CHAOS_PP_WHILE_AUX_S(CHAOS_PP_STATE(), pred, op, data, state)
# endif
#
# define CHAOS_PP_WHILE_AUX_ID() CHAOS_PP_WHILE_AUX
#
# /* CHAOS_PP_WHILE_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_AUX_S(s, pred, op, data, ...) CHAOS_IP_WHILE_AUX_U(s, pred, op, data, (__VA_ARGS__))
#    define CHAOS_PP_WHILE_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_AUX_S_ID)()
# else
#    define CHAOS_PP_WHILE_AUX_S(s, pred, op, data, state) CHAOS_IP_WHILE_AUX_U(s, pred, op, data, (state))
# endif
#
# define CHAOS_PP_WHILE_AUX_S_ID() CHAOS_PP_WHILE_AUX_S
#
# define CHAOS_IP_WHILE_AUX_U(s, pred, op, data, ps) \
    CHAOS_IP_WHILE_AUX_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), data, ps) \
    /**/
# define CHAOS_IP_WHILE_AUX_INDIRECT() CHAOS_IP_WHILE_AUX_I
# define CHAOS_IP_WHILE_AUX_I(_, s, pred, _p, op, _o, data, ps) \
    CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_UNPACK data CHAOS_PP_COMMA() CHAOS_PP_UNPACK ps))( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_WHILE_AUX_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, op, _o, data, (_o()(s, op, CHAOS_PP_UNPACK data CHAOS_PP_COMMA() CHAOS_PP_UNPACK ps)) \
        )), \
        CHAOS_PP_UNPACK ps \
    ) \
    /**/
#
# endif
