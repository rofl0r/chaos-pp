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
# ifndef CHAOS_PREPROCESSOR_CONTROL_WHILE_H
# define CHAOS_PREPROCESSOR_CONTROL_WHILE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
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
    CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_REM ps))( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_WHILE_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, op, _o, (_o()(s, op, CHAOS_PP_REM ps)) \
        )), \
        CHAOS_PP_REM ps \
    ) \
    /**/
#
# endif
