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
# ifndef CHAOS_PREPROCESSOR_TUPLE_REST_N_H
# define CHAOS_PREPROCESSOR_TUPLE_REST_N_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/comparison/greater_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
#
# /* CHAOS_PP_TUPLE_REST_N */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REST_N(n, tuple) CHAOS_PP_TUPLE_REST_N_BYPASS(CHAOS_PP_LIMIT_EXPR, n, tuple)
#    define CHAOS_PP_TUPLE_REST_N_ID() CHAOS_PP_TUPLE_REST_N
#    define CHAOS_PP_TUPLE_REST_N_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REST_N_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_REST_N_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REST_N_BYPASS(s, n, tuple) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_REST_N_0( \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), n, tuple \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_REST_N_BYPASS_ID() CHAOS_PP_TUPLE_REST_N_BYPASS
#    define CHAOS_PP_TUPLE_REST_N_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REST_N_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_REST_N_INDIRECT(n) CHAOS_IP_TUPLE_REST_N_ ## n
#    define CHAOS_IP_TUPLE_REST_N_0(_, s, n, tuple) \
        CHAOS_PP_IIF _(CHAOS_PP_GREATER_EQUAL(n, 10))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_REST_N_INDIRECT _(0)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), \
                CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _( \
                    CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _( \
                        n \
                    ))))) \
                ))))), \
                CHAOS_PP_TUPLE_SANS_BATCH _(10, tuple) \
            )), \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_REST_N_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), n, tuple \
            )) \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_REST_N_1(_, s, n, tuple) \
        CHAOS_PP_IF _(n)( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_REST_N_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(n), CHAOS_PP_TUPLE_REST _(tuple) \
            )), \
            tuple \
        ) \
        /**/
# endif
#
# endif
