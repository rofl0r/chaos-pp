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
# ifndef CHAOS_PREPROCESSOR_TUPLE_DROP_H
# define CHAOS_PREPROCESSOR_TUPLE_DROP_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/comparison/greater.h>
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
# /* CHAOS_PP_TUPLE_DROP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_DROP(n, tuple) CHAOS_PP_TUPLE_DROP_BYPASS(CHAOS_PP_LIMIT_EXPR, n, tuple)
#    define CHAOS_PP_TUPLE_DROP_ID() CHAOS_PP_TUPLE_DROP
#    define CHAOS_PP_TUPLE_DROP_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_DROP_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_DROP_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_DROP_BYPASS(s, n, tuple) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_DROP_0( \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), n, tuple \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_DROP_BYPASS_ID() CHAOS_PP_TUPLE_DROP_BYPASS
#    define CHAOS_PP_TUPLE_DROP_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_DROP_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_DROP_INDIRECT(n) CHAOS_IP_TUPLE_DROP_ ## n
#    define CHAOS_IP_TUPLE_DROP_0(_, s, n, tuple) \
        CHAOS_PP_IIF _(CHAOS_PP_GREATER(n, 9))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_DROP_INDIRECT _(0)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), \
                CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _( \
                    CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _(CHAOS_PP_DEC _( \
                        n \
                    ))))) \
                ))))), \
                CHAOS_PP_TUPLE_SANS_BATCH _(10, tuple) \
            )), \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_DROP_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), n, tuple \
            )) \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_DROP_1(_, s, n, tuple) \
        CHAOS_PP_IF _(n)( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_DROP_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(n), CHAOS_PP_TUPLE_TAIL _(tuple) \
            )), \
            tuple \
        ) \
        /**/
# endif
#
# endif
