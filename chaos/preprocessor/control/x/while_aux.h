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
# ifndef CHAOS_PREPROCESSOR_CONTROL_X_WHILE_AUX_H
# define CHAOS_PREPROCESSOR_CONTROL_X_WHILE_AUX_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* WHILE_AUX_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_AUX_X(size, pred, op, data, ...) CHAOS_PP_WHILE_AUX_X_S(CHAOS_PP_STATE(), size, pred, op, data, __VA_ARGS__)
#    define CHAOS_PP_WHILE_AUX_X_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_AUX_X_ID)()
# else
#    define CHAOS_PP_WHILE_AUX_X(size, pred, op, data, state) CHAOS_PP_WHILE_AUX_X_S(CHAOS_PP_STATE(), size, pred, op, data, state)
# endif
#
# define CHAOS_PP_WHILE_AUX_X_ID() CHAOS_PP_WHILE_AUX_X
#
# /* CHAOS_PP_WHILE_AUX_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHILE_AUX_X_S(s, size, pred, op, data, ...) CHAOS_IP_WHILE_AUX_X_U(s, size, pred, op, data, (__VA_ARGS__))
#    define CHAOS_PP_WHILE_AUX_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_WHILE_AUX_X_S_ID)()
# else
#    define CHAOS_PP_WHILE_AUX_X_S(s, size, pred, op, data, state) CHAOS_IP_WHILE_AUX_X_U(s, size, pred, op, data, (state))
# endif
#
# define CHAOS_PP_WHILE_AUX_X_S_ID() CHAOS_PP_WHILE_AUX_X_S
#
# define CHAOS_IP_WHILE_AUX_X_U(s, size, pred, op, data, ps) \
    CHAOS_IP_WHILE_AUX_X_I( \
        CHAOS_PP_NEXT(s), (CHAOS_PP_NEXT(s)), CHAOS_PP_FIXED_S(s, size), \
        pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), data, ps \
    ) \
    /**/
# define CHAOS_IP_WHILE_AUX_X_INDIRECT() CHAOS_IP_WHILE_AUX_X_I
# define CHAOS_IP_WHILE_AUX_X_I(s, jump, fix, pred, _p, op, _o, data, ps) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, fix))( \
        CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
            CHAOS_IP_WHILE_AUX_X_II, CHAOS_IP_WHILE_AUX_X_III \
        ), \
        CHAOS_IP_WHILE_AUX_X_IV \
    )(CHAOS_PP_PHASE(0), s, jump, fix, pred, _p, op, _o, data, ps) \
    /**/
# define CHAOS_IP_WHILE_AUX_X_II(_, s, jump, fix, pred, _p, op, _o, data, ps) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_WHILE_AUX_X_III(_, s, (CHAOS_PP_NEXT(s)) jump, fix, pred, _p, op, _o, data, ps) \
    ) \
    /**/
# define CHAOS_IP_WHILE_AUX_X_III(_, s, jump, fix, pred, _p, op, _o, data, ps) \
    _(1, CHAOS_PP_IIF)(_(0, _p)()(s, pred, CHAOS_PP_UNPACK data _(0, CHAOS_PP_COMMA)() CHAOS_PP_UNPACK ps))( \
        _(1, CHAOS_PP_EXPR_S)(s), CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(1) \
    )( \
        _(1, CHAOS_IP_WHILE_AUX_X_INDIRECT)()( \
            CHAOS_PP_NEXT(s), jump, fix, pred, _p, op, _o, data, \
            (_(0, _o)()(s, op, CHAOS_PP_UNPACK data _(0, CHAOS_PP_COMMA)() CHAOS_PP_UNPACK ps)) \
        ) \
    ) \
    /**/
# define CHAOS_IP_WHILE_AUX_X_IV(_, s, jump, fix, pred, _p, op, _o, data, ps) \
    CHAOS_IP_WHILE_AUX_X_V(CHAOS_PP_SEQ_FIRST(jump), CHAOS_PP_SEQ_REST(jump), fix, pred, _p, op, _o, data, ps) \
    /**/
# define CHAOS_IP_WHILE_AUX_X_V(s, jump, fix, pred, _p, op, _o, data, ps) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
        CHAOS_IP_WHILE_AUX_X_II, CHAOS_IP_WHILE_AUX_X_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), fix, pred, _p, op, _o, data, ps) \
    /**/
#
# endif
