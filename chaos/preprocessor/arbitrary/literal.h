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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_LITERAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_LITERAL_H
#
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/string/core.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_ARBITRARY_LITERAL */
#
# define CHAOS_PP_ARBITRARY_LITERAL(literal) CHAOS_PP_ARBITRARY_LITERAL_BYPASS(CHAOS_PP_LIMIT_EXPR, literal)
# define CHAOS_PP_ARBITRARY_LITERAL_ID() CHAOS_PP_ARBITRARY_LITERAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_LITERAL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_LITERAL)
# endif
#
# /* CHAOS_PP_ARBITRARY_LITERAL_BYPASS */
#
# define CHAOS_PP_ARBITRARY_LITERAL_BYPASS(s, literal) \
    CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(literal))( \
        CHAOS_PP_ARBITRARY_FIX((CHAOS_PP_EXPR_S(s)(CHAOS_IP_ARBITRARY_LITERAL_I( \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_EAT literal \
        )))), \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_ARBITRARY_LITERAL_I( \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), literal \
        )) \
    ) \
    /**/
# define CHAOS_PP_ARBITRARY_LITERAL_BYPASS_ID() CHAOS_PP_ARBITRARY_LITERAL_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_LITERAL_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_LITERAL_BYPASS)
# endif
#
# define CHAOS_IP_ARBITRARY_LITERAL_INDIRECT() CHAOS_IP_ARBITRARY_LITERAL_I
# define CHAOS_IP_ARBITRARY_LITERAL_I(_, s, literal) \
    CHAOS_PP_INLINE_WHEN _(CHAOS_PP_STRING_IS_CONS(literal))( \
        (CHAOS_PP_STRING_HEAD _(literal)) \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_ARBITRARY_LITERAL_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_TAIL _(literal) \
        )) \
    ) \
    /**/
#
# endif
