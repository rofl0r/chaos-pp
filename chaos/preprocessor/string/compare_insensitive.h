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
# ifndef CHAOS_PREPROCESSOR_STRING_COMPARE_INSENSITIVE_H
# define CHAOS_PREPROCESSOR_STRING_COMPARE_INSENSITIVE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/compare.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/string/core.h>
# include <chaos/preprocessor/string/to_lower.h>
#
# /* CHAOS_PP_STRING_COMPARE_INSENSITIVE */
#
# define CHAOS_PP_STRING_COMPARE_INSENSITIVE(a, b) CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS(CHAOS_PP_LIMIT_EXPR, a, b)
# define CHAOS_PP_STRING_COMPARE_INSENSITIVE_ID() CHAOS_PP_STRING_COMPARE_INSENSITIVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_COMPARE_INSENSITIVE_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_COMPARE_INSENSITIVE)
# endif
#
# /* CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS */
#
# define CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS(s, a, b) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_STRING_COMPARE_INSENSITIVE_I( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), a, b \
    )) \
    /**/
# define CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS_ID() CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_COMPARE_INSENSITIVE_BYPASS)
# endif
#
# define CHAOS_IP_STRING_COMPARE_INSENSITIVE_INDIRECT() CHAOS_IP_STRING_COMPARE_INSENSITIVE_I
# define CHAOS_IP_STRING_COMPARE_INSENSITIVE_I(_, s, a, b) \
    CHAOS_PP_IIF _(CHAOS_PP_STRING_IS_CONS(a))( \
        CHAOS_PP_IIF _(CHAOS_PP_STRING_IS_CONS _(b))( \
            CHAOS_PP_IIF _(CHAOS_PP_COMPARE _(CHAOS_PP_TO_LOWER _(CHAOS_PP_STRING_HEAD _(a)), CHAOS_PP_TO_LOWER _(CHAOS_PP_STRING_HEAD _(b))))( \
                CHAOS_PP_EXPR_S _(s)(CHAOS_IP_STRING_COMPARE_INSENSITIVE_INDIRECT _()( \
                    CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_TAIL _(a), CHAOS_PP_STRING_TAIL _(b) \
                )), \
                0 \
            ), \
            0 \
        ), \
        CHAOS_PP_COMPL _(CHAOS_PP_STRING_IS_CONS _(b)) \
    ) \
    /**/
#
# endif
