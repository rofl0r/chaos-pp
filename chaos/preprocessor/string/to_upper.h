# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_STRING_TO_UPPER_H
# define CHAOS_PREPROCESSOR_STRING_TO_UPPER_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/string/spec.h>
# include <chaos/preprocessor/string/to_lower.h>
#
# /* CHAOS_PP_TO_UPPER */
#
# define CHAOS_PP_TO_UPPER(c) CHAOS_PP_SPLIT(1, CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TO_LOWER_, c))
# define CHAOS_PP_TO_UPPER_ID() CHAOS_PP_TO_UPPER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TO_UPPER_ CHAOS_PP_LAMBDA(CHAOS_PP_TO_UPPER_ID)()
# endif
#
# /* CHAOS_PP_STRING_TO_UPPER */
#
# define CHAOS_PP_STRING_TO_UPPER(string) CHAOS_PP_STRING_TO_UPPER_BYPASS(CHAOS_PP_LIMIT_EXPR, string)
# define CHAOS_PP_STRING_TO_UPPER_ID() CHAOS_PP_STRING_TO_UPPER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_TO_UPPER_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_TO_UPPER_ID)()
# endif
#
# /* CHAOS_PP_STRING_TO_UPPER_BYPASS */
#
# define CHAOS_PP_STRING_TO_UPPER_BYPASS(s, string) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_STRING_TO_UPPER_I( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), string \
    )) \
    /**/
# define CHAOS_PP_STRING_TO_UPPER_BYPASS_ID() CHAOS_PP_STRING_TO_UPPER_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRING_TO_UPPER_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_STRING_TO_UPPER_BYPASS_ID)()
# endif
#
# define CHAOS_IP_STRING_TO_UPPER_INDIRECT() CHAOS_IP_STRING_TO_UPPER_I
# define CHAOS_IP_STRING_TO_UPPER_I(_, s, string) \
    CHAOS_PP_EXPR_IIF _(CHAOS_PP_STRING_IS_CONS(string))( \
        CHAOS_PP_TO_UPPER _(CHAOS_PP_STRING_FIRST _(string)) \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_STRING_TO_UPPER_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_REST _(string) \
        )) \
    ) \
    /**/
#
# endif
