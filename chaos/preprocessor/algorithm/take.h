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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_TAKE_H
# define CHAOS_PREPROCESSOR_ALGORITHM_TAKE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_TAKE */
#
# define CHAOS_PP_TAKE(n, g) CHAOS_PP_TAKE_BYPASS(CHAOS_PP_LIMIT_EXPR, n, g)
# define CHAOS_PP_TAKE_ID() CHAOS_PP_TAKE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TAKE_ CHAOS_PP_LAMBDA(CHAOS_PP_TAKE_ID)()
# endif
#
# /* CHAOS_PP_TAKE_BYPASS */
#
# define CHAOS_PP_TAKE_BYPASS(s, n, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_TAKE_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), n, g)) \
    /**/
# define CHAOS_PP_TAKE_BYPASS_ID() CHAOS_PP_TAKE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TAKE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TAKE_BYPASS_ID)()
# endif
#
# define CHAOS_IP_TAKE_INDIRECT() CHAOS_IP_TAKE_I
# define CHAOS_IP_TAKE_I(_, s, n, g) \
    CHAOS_PP_IF _(n)( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_TAKE_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(n), CHAOS_PP_TAIL _(g) \
            )), \
            CHAOS_PP_HEAD _(g) \
        ), \
        CHAOS_PP_NIL _(CHAOS_PP_TYPEOF _(g)) \
    ) \
    /**/
#
# endif
