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
# ifndef CHAOS_PREPROCESSOR_REPETITION_FOR_AUX_H
# define CHAOS_PREPROCESSOR_REPETITION_FOR_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOR_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_AUX(pred, op, macro, data, ...) CHAOS_PP_FOR_AUX_S(CHAOS_PP_STATE(), pred, op, macro, data, __VA_ARGS__)
#    define CHAOS_PP_FOR_AUX_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_AUX_ID)()
# else
#    define CHAOS_PP_FOR_AUX(pred, op, macro, data, state) CHAOS_PP_FOR_AUX_S(CHAOS_PP_STATE(), pred, op, macro, data, state)
# endif
#
# define CHAOS_PP_FOR_AUX_ID() CHAOS_PP_FOR_AUX
#
# /* CHAOS_PP_FOR_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_AUX_S(s, pred, op, macro, data, ...) \
        CHAOS_IP_FOR_AUX_U(s, pred, op, macro, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(data))(CHAOS_PP_TUPLE_REM(?))(data), (__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_AUX_S_ID)()
# else
#    define CHAOS_PP_FOR_AUX_S(s, pred, op, macro, data, state) \
        CHAOS_IP_FOR_AUX_U(s, pred, op, macro, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_UNARY(data))(CHAOS_PP_TUPLE_REM(1))(data), (state)) \
        /**/
# endif
#
# define CHAOS_PP_FOR_AUX_S_ID() CHAOS_PP_FOR_AUX_S
#
# define CHAOS_IP_FOR_AUX_U(s, pred, op, macro, data, ps) CHAOS_IP_FOR_AUX_I(CHAOS_PP_NEXT(s), pred, op, macro, data, ps)
# define CHAOS_IP_FOR_AUX_I(s, pred, op, macro, data, ps) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_IP_FOR_AUX_II( \
        CHAOS_PP_OBSTRUCT(), s, CHAOS_PP_NEXT(s), \
        pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), \
        macro, CHAOS_PP_TRAMPOLINE(macro), data, ps \
    )) \
    /**/
# define CHAOS_IP_FOR_AUX_INDIRECT() CHAOS_IP_FOR_AUX_II
# define CHAOS_IP_FOR_AUX_II(_, s, o, pred, _p, op, _o, macro, _m, data, ps) \
    CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_REM data CHAOS_PP_COMMA() CHAOS_PP_REM ps))( \
        CHAOS_PP_EXPR_S(s), CHAOS_PP_TUPLE_EAT(1) \
    )( \
        _m _()(o, macro, CHAOS_PP_REM data CHAOS_PP_COMMA _() CHAOS_PP_REM ps) \
        CHAOS_IP_FOR_AUX_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), o, pred, _p, op, _o, macro, _m, data, (_o()(s, op, CHAOS_PP_REM data CHAOS_PP_COMMA() CHAOS_PP_REM ps)) \
        ) \
    ) \
    /**/
#
# endif
