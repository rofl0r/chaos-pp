# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_SUB_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_SUB_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/and.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/exponential.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_SUB */
#
# define CHAOS_PP_SUB(x, y) CHAOS_PP_SUB_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_SUB_ID() CHAOS_PP_SUB
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB)
# endif
#
# /* CHAOS_PP_SUB_BYPASS */
#
# define CHAOS_PP_SUB_BYPASS(s, x, y) \
    CHAOS_PP_SPLIT(0, CHAOS_PP_EXPR_S(s)(CHAOS_IP_SUB_1(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), x, y))) \
    /**/
# define CHAOS_PP_SUB_BYPASS_ID() CHAOS_PP_SUB_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB_BYPASS)
# endif
#
# define CHAOS_IP_SUB_INDIRECT(n) CHAOS_IP_SUB_ ## n
# define CHAOS_IP_SUB_0(s, im) CHAOS_IP_SUB_1(CHAOS_PP_OBSTRUCT(), s, im)
# define CHAOS_IP_SUB_1(_, s, x, y) \
    CHAOS_PP_IIF _( \
        CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(s))(CHAOS_PP_AND(x)(y)) \
    )( \
        CHAOS_PP_EXPONENTIAL(s, CHAOS_PP_PREV, CHAOS_IP_SUB_INDIRECT, CHAOS_PP_DEC(x) CHAOS_PP_COMMA() CHAOS_PP_DEC(y)), \
        x CHAOS_PP_COMMA _() y \
    ) \
    /**/
#
# endif
