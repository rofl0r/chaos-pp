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
# ifndef CHAOS_PREPROCESSOR_CONTROL_LOOP_H
# define CHAOS_PREPROCESSOR_CONTROL_LOOP_H
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
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_LOOP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LOOP(size, pred, op, ...) CHAOS_PP_LOOP_S(CHAOS_PP_STATE(), size, pred, op, __VA_ARGS__)
#    define CHAOS_PP_LOOP_ CHAOS_PP_LAMBDA(CHAOS_PP_LOOP_ID)()
# else
#    define CHAOS_PP_LOOP(size, pred, op, state) CHAOS_PP_LOOP_S(CHAOS_PP_STATE(), size, pred, op, state)
# endif
#
# define CHAOS_PP_LOOP_ID() CHAOS_PP_LOOP
#
# /* CHAOS_PP_LOOP_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LOOP_S(s, size, pred, op, ...) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM_CTOR)(?, CHAOS_IP_LOOP_U(s, size, pred, op, (__VA_ARGS__)))
#    define CHAOS_PP_LOOP_S_ CHAOS_PP_LAMBDA(CHAOS_PP_LOOP_S_ID)()
# else
#    define CHAOS_PP_LOOP_S(s, size, pred, op, state) CHAOS_PP_DEFER(CHAOS_PP_TUPLE_REM_CTOR)(1, CHAOS_IP_LOOP_U(s, size, pred, op, (state)))
# endif
#
# define CHAOS_PP_LOOP_S_ID() CHAOS_PP_LOOP_S
#
# define CHAOS_IP_LOOP_U(s, size, pred, op, ps) \
    CHAOS_IP_LOOP_I( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), \
        pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), ps \
    ) \
    /**/
# define CHAOS_IP_LOOP_INDIRECT() CHAOS_IP_LOOP_I
# define CHAOS_IP_LOOP_I(_, s, buffer, pred, _p, op, _o, ps) \
    CHAOS_PP_IIF _( \
        CHAOS_PP_BITAND _(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR))(_p()(s, pred, CHAOS_PP_UNPACK ps)) \
    )( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_LOOP_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(buffer), pred, _p, op, _o, \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_LOOP_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(buffer), pred, _p, op, _o, (_o()(s, op, CHAOS_PP_UNPACK ps)) \
            )) \
        )), \
        ps \
    ) \
    /**/
#
# endif
