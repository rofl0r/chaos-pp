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
# ifndef CHAOS_PREPROCESSOR_REPETITION_FOR_H
# define CHAOS_PREPROCESSOR_REPETITION_FOR_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOR */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR(pred, op, macro, ...) CHAOS_PP_FOR_S(CHAOS_PP_STATE(), pred, op, macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_ID)()
# else
#    define CHAOS_PP_FOR(pred, op, macro, state) CHAOS_PP_FOR_S(CHAOS_PP_STATE(), pred, op, macro, state)
# endif
#
# define CHAOS_PP_FOR_ID() CHAOS_PP_FOR
#
# /* CHAOS_PP_FOR_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_S(s, pred, op, macro, ...) CHAOS_IP_FOR_U(s, pred, op, macro, (__VA_ARGS__))
#    define CHAOS_PP_FOR_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_S_ID)()
# else
#    define CHAOS_PP_FOR_S(s, pred, op, macro, state) CHAOS_IP_FOR_U(s, pred, op, macro, (state))
# endif
#
# define CHAOS_PP_FOR_S_ID() CHAOS_PP_FOR_S
#
# define CHAOS_IP_FOR_U(s, pred, op, macro, ps) \
    CHAOS_IP_FOR_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), macro, CHAOS_PP_CALL(macro), ps) \
    /**/
# define CHAOS_IP_FOR_INDIRECT() CHAOS_IP_FOR_I
# define CHAOS_IP_FOR_I(_, s, pred, _p, op, _o, macro, _m, ps) \
    CHAOS_PP_EXPR_IIF _(_p()(s, pred, CHAOS_PP_UNPACK ps))( \
        _m()(s, macro, CHAOS_PP_UNPACK ps) \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOR_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, op, _o, macro, _m, (_o()(s, op, CHAOS_PP_UNPACK ps)) \
        )) \
    ) \
    /**/
#
# endif
