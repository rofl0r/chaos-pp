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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_ELEM_H
# define CHAOS_PREPROCESSOR_ALGORITHM_ELEM_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_ELEM */
#
# define CHAOS_PP_ELEM(i, g) CHAOS_PP_ELEM_BYPASS(CHAOS_PP_LIMIT_EXPR, i, g)
# define CHAOS_PP_ELEM_ID() CHAOS_PP_ELEM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ELEM_ CHAOS_PP_LAMBDA(CHAOS_PP_ELEM_ID)()
# endif
#
# /* CHAOS_PP_ELEM_BYPASS */
#
# define CHAOS_PP_ELEM_BYPASS(s, i, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_ELEM_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), i, g)) \
    /**/
# define CHAOS_PP_ELEM_BYPASS_ID() CHAOS_PP_ELEM_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ELEM_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_ELEM_BYPASS_ID)()
# endif
#
# define CHAOS_IP_ELEM_INDIRECT() CHAOS_IP_ELEM_I
# define CHAOS_IP_ELEM_I(_, s, i, g) \
    CHAOS_PP_IF _(i)( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_ELEM_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(i), CHAOS_PP_REST _(g) \
        )), \
        CHAOS_PP_FIRST _(g) \
    ) \
    /**/
#
# endif
