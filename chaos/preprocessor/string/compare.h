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
# ifndef CHAOS_PREPROCESSOR_STRING_COMPARE_H
# define CHAOS_PREPROCESSOR_STRING_COMPARE_H
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
#
# /* CHAOS_PP_STRING_COMPARE */
#
# define CHAOS_PP_STRING_COMPARE(a, b) CHAOS_PP_STRING_COMPARE_BYPASS(CHAOS_PP_LIMIT_EXPR, a, b)
# define CHAOS_PP_STRING_COMPARE_ID() CHAOS_PP_STRING_COMPARE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_COMPARE_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_COMPARE)
# endif
#
# /* CHAOS_PP_STRING_COMPARE_BYPASS */
#
# define CHAOS_PP_STRING_COMPARE_BYPASS(s, a, b) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_STRING_COMPARE_I( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), a, b \
    )) \
    /**/
# define CHAOS_PP_STRING_COMPARE_BYPASS_ID() CHAOS_PP_STRING_COMPARE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_COMPARE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_COMPARE_BYPASS)
# endif
#
# define CHAOS_IP_STRING_COMPARE_INDIRECT() CHAOS_IP_STRING_COMPARE_I
# define CHAOS_IP_STRING_COMPARE_I(_, s, a, b) \
    CHAOS_PP_IIF _(CHAOS_PP_STRING_IS_CONS(a))( \
        CHAOS_PP_IIF _(CHAOS_PP_STRING_IS_CONS _(b))( \
            CHAOS_PP_IIF _(CHAOS_PP_COMPARE _(CHAOS_PP_STRING_HEAD _(a), CHAOS_PP_STRING_HEAD _(b)))( \
                CHAOS_PP_EXPR_S _(s)(CHAOS_IP_STRING_COMPARE_INDIRECT _()( \
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
