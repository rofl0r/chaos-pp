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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_ADD_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_ADD_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/exponential.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ADD */
#
# define CHAOS_PP_ADD(x, y) CHAOS_PP_ADD_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_ADD_ID() CHAOS_PP_ADD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD)
# endif
#
# /* CHAOS_PP_ADD_BYPASS */
#
# define CHAOS_PP_ADD_BYPASS(s, x, y) \
    CHAOS_PP_SPLIT(0, CHAOS_PP_EXPR_S(s)(CHAOS_IP_ADD_1(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), x, y))) \
    /**/
# define CHAOS_PP_ADD_BYPASS_ID() CHAOS_PP_ADD_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD_BYPASS)
# endif
#
# define CHAOS_IP_ADD_INDIRECT(n) CHAOS_IP_ADD_ ## n
# define CHAOS_IP_ADD_0(s, im) CHAOS_IP_ADD_1(CHAOS_PP_OBSTRUCT(), s, im)
# define CHAOS_IP_ADD_1(_, s, x, y) \
    CHAOS_PP_IIF _( \
        CHAOS_PP_BITAND \
            (CHAOS_PP_IS_VALID(s)) \
            (CHAOS_PP_BITAND(CHAOS_PP_BOOL(y))(CHAOS_PP_NOT_EQUAL(x, CHAOS_PP_LIMIT_MAG))) \
    )( \
        CHAOS_PP_EXPONENTIAL(s, CHAOS_PP_PREV, CHAOS_IP_ADD_INDIRECT, CHAOS_PP_INC(x) CHAOS_PP_COMMA() CHAOS_PP_DEC(y)), \
        x CHAOS_PP_COMMA _() y \
    ) \
    /**/
#
# endif
