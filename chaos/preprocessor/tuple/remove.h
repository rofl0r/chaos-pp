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
# ifndef CHAOS_PREPROCESSOR_TUPLE_REMOVE_H
# define CHAOS_PREPROCESSOR_TUPLE_REMOVE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/comparison/greater.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_REMOVE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REMOVE(i, tuple) CHAOS_PP_TUPLE_REMOVE_BYPASS(CHAOS_PP_LIMIT_EXPR, i, tuple)
#    define CHAOS_PP_TUPLE_REMOVE_ID() CHAOS_PP_TUPLE_REMOVE
#    define CHAOS_PP_TUPLE_REMOVE_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REMOVE_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_REMOVE_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REMOVE_BYPASS(s, i, tuple) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_REMOVE_1( \
            CHAOS_PP_PREV(s), i, tuple \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_REMOVE_BYPASS_ID() CHAOS_PP_TUPLE_REMOVE_BYPASS
#    define CHAOS_PP_TUPLE_REMOVE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REMOVE_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_REMOVE_INDIRECT(n) CHAOS_IP_TUPLE_REMOVE_ ## n
#    define CHAOS_IP_TUPLE_REMOVE_1(s, n, tuple) \
        CHAOS_PP_IIF(CHAOS_PP_GREATER(n, 9))( \
            CHAOS_IP_TUPLE_REMOVE_1_I, CHAOS_IP_TUPLE_REMOVE_2 \
        )(s, n, tuple) \
        /**/
#    define CHAOS_IP_TUPLE_REMOVE_1_I(s, n, tuple) \
        CHAOS_IP_TUPLE_REMOVE_1_II(s, n, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple)) \
        /**/
#    define CHAOS_IP_TUPLE_REMOVE_1_II(...) CHAOS_IP_TUPLE_REMOVE_1_III(CHAOS_PP_OBSTRUCT(), __VA_ARGS__)
#    define CHAOS_IP_TUPLE_REMOVE_1_III(_, s, n, a, b, c, d, e, f, g, h, i, j, tuple) \
        CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _( \
        CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_REMOVE_INDIRECT _(1)( \
                CHAOS_PP_PREV(s), \
                CHAOS_PP_DEC(CHAOS_PP_DEC(CHAOS_PP_DEC(CHAOS_PP_DEC(CHAOS_PP_DEC( \
                    CHAOS_PP_DEC(CHAOS_PP_DEC(CHAOS_PP_DEC(CHAOS_PP_DEC(CHAOS_PP_DEC( \
                        n \
                    ))))) \
                ))))), \
                tuple \
            )), \
            j), i), h), g), f), e), d), c), b), a) \
        /**/
#    define CHAOS_IP_TUPLE_REMOVE_2(s, n, tuple) \
        CHAOS_PP_IF(n)( \
            CHAOS_IP_TUPLE_REMOVE_2_I, CHAOS_PP_TUPLE_REST(tuple) CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, n, tuple) \
        /**/
#    define CHAOS_IP_TUPLE_REMOVE_2_I(_, s, n, tuple) \
        CHAOS_PP_TUPLE_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_REMOVE_INDIRECT _(2)( \
                CHAOS_PP_PREV(s), CHAOS_PP_DEC(n), CHAOS_PP_TUPLE_REST(tuple) \
            )), \
            CHAOS_PP_TUPLE_FIRST(tuple) \
        ) \
        /**/
# endif
#
# endif
