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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_ENUMERATE_H
# define CHAOS_PREPROCESSOR_ALGORITHM_ENUMERATE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_ENUMERATE */
#
# define CHAOS_PP_ENUMERATE(g) CHAOS_PP_ENUMERATE_BYPASS(CHAOS_PP_LIMIT_EXPR, g)
# define CHAOS_PP_ENUMERATE_ID() CHAOS_PP_ENUMERATE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUMERATE_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUMERATE_ID)()
# endif
#
# /* CHAOS_PP_ENUMERATE_BYPASS */
#
# define CHAOS_PP_ENUMERATE_BYPASS(s, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_ENUMERATE_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_EMPTY, CHAOS_PP_COMMA, g)) \
    /**/
# define CHAOS_PP_ENUMERATE_BYPASS_ID() CHAOS_PP_ENUMERATE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUMERATE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUMERATE_BYPASS_ID)()
# endif
#
# define CHAOS_IP_ENUMERATE_INDIRECT() CHAOS_IP_ENUMERATE_I
# define CHAOS_IP_ENUMERATE_I(_, s, sep, ss, g) \
    CHAOS_PP_INLINE_WHEN _(CHAOS_PP_IS_CONS(g))( \
        sep _() CHAOS_PP_FIRST _(g) \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_ENUMERATE_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), ss, ss, CHAOS_PP_REST _(g) \
        )) \
    ) \
    /**/
#
# endif
