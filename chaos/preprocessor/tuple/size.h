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
# ifndef CHAOS_PREPROCESSOR_TUPLE_SIZE_H
# define CHAOS_PREPROCESSOR_TUPLE_SIZE_H
#
# include <chaos/preprocessor/arithmetic/in_range.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
#
# /* CHAOS_PP_TUPLE_QUICK_SIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_QUICK_SIZE(tuple) \
        CHAOS_IP_TUPLE_QUICK_SIZE_I(CHAOS_PP_TUPLE_BATCH_FORK(CHAOS_PP_LIMIT_TUPLE, tuple)) \
        /**/
#    define CHAOS_PP_TUPLE_QUICK_SIZE_ID() CHAOS_PP_TUPLE_QUICK_SIZE
#    define CHAOS_PP_TUPLE_QUICK_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_QUICK_SIZE)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_QUICK_SIZE_I(fork) \
        CHAOS_PP_IIF(CHAOS_PP_IS_EMPTY_NON_FUNCTION(fork))( \
            CHAOS_PP_LIMIT_TUPLE, fork \
        ) \
        /**/
# endif
#
# /* CHAOS_PP_TUPLE_SIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_SIZE(tuple) CHAOS_PP_TUPLE_SIZE_BYPASS(CHAOS_PP_LIMIT_EXPR, tuple)
#    define CHAOS_PP_TUPLE_SIZE_ID() CHAOS_PP_TUPLE_SIZE
#    define CHAOS_PP_TUPLE_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_SIZE)
# endif
#
# /* CHAOS_PP_TUPLE_SIZE_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_SIZE_BYPASS(s, tuple) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_SIZE_0(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), tuple, 0)) \
        /**/
#    define CHAOS_PP_TUPLE_SIZE_BYPASS_ID() CHAOS_PP_TUPLE_SIZE_BYPASS
#    define CHAOS_PP_TUPLE_SIZE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_SIZE_BYPASS)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_SIZE_INDIRECT(n) CHAOS_IP_TUPLE_SIZE_ ## n
#    define CHAOS_IP_TUPLE_SIZE_0(_, s, tuple, x) \
        CHAOS_PP_IIF _(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_SIZE_INDIRECT _(0)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_SANS_BATCH _(10, tuple), CHAOS_PP_INC(x) \
            )), \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_SIZE_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), tuple, \
                CHAOS_PP_IF _(x)( \
                    CHAOS_PP_IIF _(CHAOS_PP_IN_RANGE _(x ## 0))( \
                        x ## 0, \
                        CHAOS_PP_LIMIT_MAG \
                    ), \
                    0 \
                ) \
            )) \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_SIZE_1(_, s, tuple, x) \
        CHAOS_PP_IIF _(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_SIZE_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_TAIL _(tuple), CHAOS_PP_INC(x) \
            )), \
            x \
        ) \
        /**/
# endif
#
# /* CHAOS_PP_VARIADIC_SIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SIZE(...) CHAOS_PP_TUPLE_SIZE((__VA_ARGS__))
#    define CHAOS_PP_VARIADIC_SIZE_ID() CHAOS_PP_VARIADIC_SIZE
#    define CHAOS_PP_VARIADIC_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SIZE)
# endif
#
# endif
