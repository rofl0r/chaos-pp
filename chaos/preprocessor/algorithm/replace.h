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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_REMOVE_H
# define CHAOS_PREPROCESSOR_ALGORITHM_REMOVE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_REPLACE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPLACE(i, g, ...) CHAOS_PP_REPLACE_BYPASS(CHAOS_PP_LIMIT_EXPR, i, g, __VA_ARGS__)
#    define CHAOS_PP_REPLACE_ CHAOS_PP_LAMBDA(CHAOS_PP_REPLACE_ID)()
# else
#    define CHAOS_PP_REPLACE(i, g, x) CHAOS_PP_REPLACE_BYPASS(CHAOS_PP_LIMIT_EXPR, i, g, x)
# endif
#
# define CHAOS_PP_REPLACE_ID() CHAOS_PP_REPLACE
#
# /* CHAOS_PP_REPLACE_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPLACE_BYPASS(s, i, g, ...) CHAOS_IP_REPLACE_BYPASS_U(s, i, g, (__VA_ARGS__))
#    define CHAOS_PP_REPLACE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_REPLACE_BYPASS_ID)()
# else
#    define CHAOS_PP_REPLACE_BYPASS(s, i, g, x) CHAOS_IP_REPLACE_BYPASS_U(s, i, g, (x))
# endif
#
# define CHAOS_PP_REPLACE_BYPASS_ID() CHAOS_PP_REPLACE_BYPASS
#
# define CHAOS_IP_REPLACE_BYPASS_U(s, i, g, px) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_REPLACE_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), i, g, px)) \
    /**/
# define CHAOS_IP_REPLACE_INDIRECT() CHAOS_IP_REPLACE_I
# define CHAOS_IP_REPLACE_I(_, s, i, g, px) \
    CHAOS_PP_IF _(i)( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_REPLACE_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(i), CHAOS_PP_REST _(g), px \
            )), \
            CHAOS_PP_FIRST _(g) \
        ), \
        CHAOS_PP_CONS _(CHAOS_PP_REST _(g), CHAOS_PP_REM px) \
    ) \
    /**/
#
# endif
