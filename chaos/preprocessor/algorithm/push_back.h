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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PUSH_BACK_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PUSH_BACK_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_PUSH_BACK */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PUSH_BACK(g, ...) CHAOS_PP_PUSH_BACK_BYPASS(CHAOS_PP_LIMIT_EXPR, g, __VA_ARGS__)
#    define CHAOS_PP_PUSH_BACK_ CHAOS_PP_LAMBDA(CHAOS_PP_PUSH_BACK_ID)()
# else
#    define CHAOS_PP_PUSH_BACK(g, x) CHAOS_PP_PUSH_BACK_BYPASS(CHAOS_PP_LIMIT_EXPR, g, x)
# endif
#
# define CHAOS_PP_PUSH_BACK_ID() CHAOS_PP_PUSH_BACK
#
# /* CHAOS_PP_PUSH_BACK_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PUSH_BACK_BYPASS(s, g, ...) CHAOS_IP_PUSH_BACK_U(s, g, (__VA_ARGS__))
#    define CHAOS_PP_PUSH_BACK_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_PUSH_BACK_BYPASS_ID)()
# else
#    define CHAOS_PP_PUSH_BACK_BYPASS(s, g, x) CHAOS_IP_PUSH_BACK_U(s, g, (x))
# endif
#
# define CHAOS_PP_PUSH_BACK_BYPASS_ID() CHAOS_PP_PUSH_BACK_BYPASS
#
# define CHAOS_IP_PUSH_BACK_U(s, g, px) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_PUSH_BACK_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), g, px)) \
    /**/
# define CHAOS_IP_PUSH_BACK_INDIRECT() CHAOS_IP_PUSH_BACK_I
# define CHAOS_IP_PUSH_BACK_I(_, s, g, px) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_PUSH_BACK_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_REST _(g), px \
            )), \
            CHAOS_PP_FIRST _(g) \
        ), \
        CHAOS_PP_CONS _(g, CHAOS_PP_REM px) \
    ) \
    /**/
#
# endif
