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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_RANGE_H
# define CHAOS_PREPROCESSOR_ALGORITHM_RANGE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_RANGE */
#
# define CHAOS_PP_RANGE(i, len, g) CHAOS_PP_RANGE_BYPASS(CHAOS_PP_LIMIT_EXPR, i, len, g)
# define CHAOS_PP_RANGE_ID() CHAOS_PP_RANGE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_RANGE_ CHAOS_PP_LAMBDA(CHAOS_PP_RANGE_ID)()
# endif
#
# /* CHAOS_PP_RANGE_BYPASS */
#
# define CHAOS_PP_RANGE_BYPASS(s, i, len, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_RANGE_1(CHAOS_PP_PREV(s), i, len, g)) \
    /**/
# define CHAOS_PP_RANGE_BYPASS_ID() CHAOS_PP_RANGE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_RANGE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_RANGE_BYPASS_ID)()
# endif
#
# define CHAOS_IP_RANGE_INDIRECT(n) CHAOS_IP_RANGE_ ## n
# define CHAOS_IP_RANGE_1(s, i, len, g) \
    CHAOS_PP_IF(i)( \
        CHAOS_IP_RANGE_1_I, CHAOS_IP_RANGE_2 \
    )(CHAOS_PP_OBSTRUCT(), s, i, len, g) \
    /**/
# define CHAOS_IP_RANGE_1_I(_, s, i, len, g) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_RANGE_INDIRECT _(1)( \
        CHAOS_PP_PREV(s), CHAOS_PP_DEC(i), len, CHAOS_PP_REST(g) \
    )) \
    /**/
# define CHAOS_IP_RANGE_2(_, s, i, len, g) \
    CHAOS_PP_IF _(len)( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_RANGE_INDIRECT _(2)( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), i, CHAOS_PP_DEC(len), CHAOS_PP_REST _(g) \
            )), \
            CHAOS_PP_FIRST _(g) \
        ), \
        CHAOS_PP_NIL _(CHAOS_PP_TYPEOF _(g)) \
    ) \
    /**/
#
# endif
