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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_CAST_H
# define CHAOS_PREPROCESSOR_ALGORITHM_CAST_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/is_type.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_CAST */
#
# define CHAOS_PP_CAST(type, g) CHAOS_PP_CAST_BYPASS(CHAOS_PP_LIMIT_EXPR, type, g)
# define CHAOS_PP_CAST_ID() CHAOS_PP_CAST
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CAST_ CHAOS_PP_LAMBDA(CHAOS_PP_CAST_ID)()
# endif
#
# /* CHAOS_PP_CAST_BYPASS */
#
# define CHAOS_PP_CAST_BYPASS(s, type, g) \
    CHAOS_PP_IIF(CHAOS_PP_IS_TYPE(type, g))( \
        g, \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_CAST_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), type, g)) \
    ) \
    /**/
# define CHAOS_PP_CAST_BYPASS_ID() CHAOS_PP_CAST_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CAST_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_CAST_BYPASS_ID)()
# endif
#
# define CHAOS_IP_CAST_INDIRECT() CHAOS_IP_CAST_I
# define CHAOS_IP_CAST_I(_, s, type, g) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_CAST_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), type, CHAOS_PP_TAIL _(g) \
            )), \
            CHAOS_PP_HEAD _(g) \
        ), \
        CHAOS_PP_NIL(type) \
    ) \
    /**/
#
# endif
