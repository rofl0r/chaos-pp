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
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/string/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_LITERAL_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LITERAL_AP(literal) CHAOS_PP_LITERAL_AP_BYPASS(CHAOS_PP_LIMIT_EXPR, literal)
#    define CHAOS_PP_LITERAL_AP_ID() CHAOS_PP_LITERAL_AP
#    define CHAOS_PP_LITERAL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_LITERAL_AP)
# endif
#
# /* CHAOS_PP_LITERAL_AP_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LITERAL_AP_BYPASS(s, literal) \
        CHAOS_PP_CLEAN_AP(CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(literal))( \
            (1, CHAOS_PP_EXPR_S(s)(CHAOS_IP_LITERAL_AP_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_EAT(?) literal \
            ))), \
            (0, CHAOS_PP_EXPR_S(s)(CHAOS_IP_LITERAL_AP_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), literal \
            ))) \
        )) \
        /**/
#    define CHAOS_PP_LITERAL_AP_BYPASS_ID() CHAOS_PP_LITERAL_AP_BYPASS
#    define CHAOS_PP_LITERAL_AP_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_LITERAL_AP_BYPASS)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_LITERAL_AP_INDIRECT() CHAOS_IP_LITERAL_AP_I
#    define CHAOS_IP_LITERAL_AP_I(_, s, string) \
        CHAOS_PP_INLINE_WHEN _(CHAOS_PP_STRING_IS_CONS(string))( \
            (CHAOS_PP_STRING_FIRST _(string)) \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_LITERAL_AP_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_REST _(string) \
            )) \
        ) \
        /**/
# endif
#
# endif
