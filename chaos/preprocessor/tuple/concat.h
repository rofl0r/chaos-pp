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
# ifndef CHAOS_PREPROCESSOR_TUPLE_CONCAT_H
# define CHAOS_PREPROCESSOR_TUPLE_CONCAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
#
# /* CHAOS_PP_TUPLE_CONCAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_CONCAT(tuple) CHAOS_PP_TUPLE_CONCAT_BYPASS(CHAOS_PP_LIMIT_EXPR, tuple)
#    define CHAOS_PP_TUPLE_CONCAT_ID() CHAOS_PP_TUPLE_CONCAT
#    define CHAOS_PP_TUPLE_CONCAT_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_CONCAT_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_CONCAT_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_CONCAT_BYPASS(s, tuple) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_CONCAT_0( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), tuple, \
            ) \
        ) \
        /**/
#    define CHAOS_PP_TUPLE_CONCAT_BYPASS_ID() CHAOS_PP_TUPLE_CONCAT_BYPASS
#    define CHAOS_PP_TUPLE_CONCAT_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_CONCAT_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_CONCAT_INDIRECT(n) CHAOS_IP_TUPLE_CONCAT_ ## n
#    define CHAOS_IP_TUPLE_CONCAT_0(_, s, tuple, res) \
        CHAOS_PP_IIF _(CHAOS_PP_TUPLE_IS_BATCH(10, tuple))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_CONCAT_INDIRECT _(0)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_SANS_BATCH _(10, tuple), CHAOS_PP_CAT _(res, CHAOS_PP_EXPR_S _(s)(CHAOS_PP_VARIADIC_CAT CHAOS_PP_TUPLE_BATCH _(10, tuple))) \
            )), \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_CONCAT_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), tuple, res \
            )) \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_CONCAT_1(_, s, tuple, res) \
        CHAOS_PP_IIF _(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_CONCAT_INDIRECT _(1)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_REST _(tuple), CHAOS_PP_CAT _(res, CHAOS_PP_TUPLE_FIRST _(tuple)) \
            )), \
            res \
        ) \
        /**/
# endif
#
# endif
