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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_SIZE_H
# define CHAOS_PREPROCESSOR_ALGORITHM_SIZE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_SIZE */
#
# define CHAOS_PP_SIZE(g) CHAOS_PP_SIZE_BYPASS(CHAOS_PP_LIMIT_EXPR, g)
# define CHAOS_PP_SIZE_ID() CHAOS_PP_SIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_SIZE)
# endif
#
# /* CHAOS_PP_SIZE_BYPASS */
#
# define CHAOS_PP_SIZE_BYPASS(s, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_SIZE_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), g, 0)) \
    /**/
# define CHAOS_PP_SIZE_BYPASS_ID() CHAOS_PP_SIZE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SIZE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SIZE_BYPASS)
# endif
#
# define CHAOS_IP_SIZE_INDIRECT() CHAOS_IP_SIZE_I
# define CHAOS_IP_SIZE_I(_, s, g, size) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_SIZE_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_REST _(g), CHAOS_PP_INC(size) \
        )), \
        size \
    ) \
    /**/
#
# endif
