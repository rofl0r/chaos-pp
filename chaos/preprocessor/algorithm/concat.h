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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_CONCAT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_CONCAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_CONCAT */
#
# define CHAOS_PP_CONCAT(g) CHAOS_PP_CONCAT_BYPASS(CHAOS_PP_LIMIT_EXPR, g)
# define CHAOS_PP_CONCAT_ID() CHAOS_PP_CONCAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CONCAT_ CHAOS_PP_LAMBDA(CHAOS_PP_CONCAT_ID)()
# endif
#
# /* CHAOS_PP_CONCAT_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CONCAT_BYPASS(s, g) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_CONCAT_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), g,)) \
        /**/
#    define CHAOS_PP_CONCAT_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_CONCAT_BYPASS_ID)()
#    define CHAOS_IP_CONCAT_I(_, s, g, ...) \
        CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_CONCAT_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_REST _(g), CHAOS_PP_VARIADIC_CAT _(__VA_ARGS__, CHAOS_PP_FIRST _(g)) \
            )), \
            __VA_ARGS__ \
        ) \
        /**/
# else
#    define CHAOS_PP_CONCAT_BYPASS(s, g) \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_CONS(g))( \
            CHAOS_PP_EXPR_S(s)(CHAOS_IP_CONCAT_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_REST(g), CHAOS_PP_FIRST(g))) \
        ) \
        /**/
#    define CHAOS_IP_CONCAT_I(_, s, g, res) \
        CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_CONCAT_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_REST _(g), CHAOS_PP_CAT _(res, CHAOS_PP_FIRST _(g)) \
            )), \
            res \
        ) \
        /**/
# endif
#
# define CHAOS_PP_CONCAT_BYPASS_ID() CHAOS_PP_CONCAT_BYPASS
#
# define CHAOS_IP_CONCAT_INDIRECT() CHAOS_IP_CONCAT_I
#
# endif
