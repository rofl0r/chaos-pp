# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MOD_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MOD_H
#
# include <chaos/preprocessor/arithmetic/div.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/not.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/elem.h>
#
# /* CHAOS_PP_MOD */
#
# define CHAOS_PP_MOD(x, y) CHAOS_PP_MOD_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_MOD_ID() CHAOS_PP_MOD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD)
# endif
#
# /* CHAOS_PP_MOD_BYPASS */
#
# define CHAOS_PP_MOD_BYPASS(s, x, y) \
    CHAOS_PP_EXPR_IIF(CHAOS_PP_NOT(y))(CHAOS_PP_FAILURE()) \
    CHAOS_PP_TUPLE_ELEM( \
        4, 1, \
        (CHAOS_PP_EXPR_S(s)(CHAOS_IP_DIV_1(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), 0, x, y, 0))) \
    ) \
    /**/
# define CHAOS_PP_MOD_BYPASS_ID() CHAOS_PP_MOD_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_BYPASS)
# endif
#
# endif
