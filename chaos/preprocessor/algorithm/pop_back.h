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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_POP_BACK_H
# define CHAOS_PREPROCESSOR_ALGORITHM_POP_BACK_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_POP_BACK */
#
# define CHAOS_PP_POP_BACK(g) CHAOS_PP_POP_BACK_BYPASS(CHAOS_PP_LIMIT_EXPR, g)
# define CHAOS_PP_POP_BACK_ID() CHAOS_PP_POP_BACK
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_POP_BACK_ CHAOS_PP_LAMBDA(CHAOS_PP_POP_BACK_ID)()
# endif
#
# /* CHAOS_PP_POP_BACK_BYPASS */
#
# define CHAOS_PP_POP_BACK_BYPASS(s, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_POP_BACK_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), g)) \
    /**/
# define CHAOS_PP_POP_BACK_BYPASS_ID() CHAOS_PP_POP_BACK_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_POP_BACK_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_POP_BACK_BYPASS_ID)()
# endif
#
# define CHAOS_IP_POP_BACK_INDIRECT() CHAOS_IP_POP_BACK_I
# define CHAOS_IP_POP_BACK_I(_, s, g) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(CHAOS_PP_REST(g)))( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_POP_BACK_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_REST(g) \
            )), \
            CHAOS_PP_FIRST(g) \
        ), \
        CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)) \
    ) \
    /**/
        
#
# endif
