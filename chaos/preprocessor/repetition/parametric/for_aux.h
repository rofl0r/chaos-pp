# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_FOR_AUX_H
# define CHAOS_PREPROCESSOR_REPETITION_PARAMETRIC_FOR_AUX_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOR_AUX_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_AUX_PARAMETRIC(size, pred, op, macro, data, ...) CHAOS_PP_FOR_AUX_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, macro, data, __VA_ARGS__)
#    define CHAOS_PP_FOR_AUX_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_AUX_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_FOR_AUX_PARAMETRIC(size, pred, op, macro, data, state) CHAOS_PP_FOR_AUX_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, macro, data, state)
# endif
#
# define CHAOS_PP_FOR_AUX_PARAMETRIC_ID() CHAOS_PP_FOR_AUX_PARAMETRIC
#
# /* CHAOS_PP_FOR_AUX_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_AUX_PARAMETRIC_S(s, size, pred, op, macro, data, ...) \
        CHAOS_IP_FOR_AUX_PARAMETRIC_U(s, size, pred, op, macro, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(data))(CHAOS_PP_REM)(data), (__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_AUX_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_AUX_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_FOR_AUX_PARAMETRIC_S(s, size, pred, op, macro, data, state) \
        CHAOS_IP_FOR_AUX_PARAMETRIC_U(s, size, pred, op, macro, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_UNARY(data))(CHAOS_PP_REM)(data), (state)) \
        /**/
# endif
#
# define CHAOS_PP_FOR_AUX_PARAMETRIC_S_ID() CHAOS_PP_FOR_AUX_PARAMETRIC_S
#
# define CHAOS_IP_FOR_AUX_PARAMETRIC_U(s, size, pred, op, macro, data, ps) CHAOS_IP_FOR_AUX_PARAMETRIC_I(CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER_S(s, size), pred, op, macro, data, ps)
# define CHAOS_IP_FOR_AUX_PARAMETRIC_I(s, buffer, pred, op, macro, data, ps) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_IP_FOR_AUX_PARAMETRIC_II( \
        s, s, buffer, buffer, \
        pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), \
        macro, CHAOS_PP_TRAMPOLINE(macro), data, ps \
    )) \
    /**/
# define CHAOS_IP_FOR_AUX_PARAMETRIC_INDIRECT() CHAOS_IP_FOR_AUX_PARAMETRIC_II
# define CHAOS_IP_FOR_AUX_PARAMETRIC_II(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, data, ps) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR))( \
        CHAOS_IP_FOR_AUX_PARAMETRIC_III, CHAOS_IP_FOR_AUX_PARAMETRIC_IV \
    )(CHAOS_PP_PHASE(0), s, o, buffer, shelf, pred, _p, op, _o, macro, _m, data, ps) \
    /**/
# define CHAOS_IP_FOR_AUX_PARAMETRIC_III(_, s, o, buffer, shelf, pred, _p, op, _o, macro, _m, data, ps) \
    _(1, CHAOS_PP_IIF)(_(0, _p)()(s, pred, CHAOS_PP_REM data _(0, CHAOS_PP_COMMA)() CHAOS_PP_REM ps))( \
        _(1, CHAOS_PP_EXPR_S)(s), CHAOS_PP_EAT \
    )( \
        _(1, _m)()(CHAOS_PP_NEXT(o), macro, CHAOS_PP_REM data _(1, CHAOS_PP_COMMA)() CHAOS_PP_REM ps) \
        _(1, CHAOS_IP_FOR_AUX_PARAMETRIC_INDIRECT)()( \
            CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, op, _o, macro, _m, data, (_(0, _o)()(s, op, CHAOS_PP_REM data _(0, CHAOS_PP_COMMA)() CHAOS_PP_REM ps)) \
        ) \
    ) \
    /**/
# define CHAOS_IP_FOR_AUX_PARAMETRIC_IV(_, s, o, buffer, shelf, pred, _p, op, _o, macro, _m, data, ps) \
    _(3, CHAOS_PP_EXPR_S)(o)(CHAOS_IP_FOR_AUX_PARAMETRIC_III( \
        CHAOS_PP_PHASE(2), o, o, shelf, shelf, pred, _p, op, _o, macro, _m, data, ps \
    )) \
    /**/
#
# endif
