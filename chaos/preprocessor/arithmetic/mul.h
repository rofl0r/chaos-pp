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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MUL_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MUL_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/exponential.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/elem.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_MUL */
#
# define CHAOS_PP_MUL(x, y) CHAOS_PP_MUL_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_MUL_ID() CHAOS_PP_MUL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL)
# endif
#
# /* CHAOS_PP_MUL_BYPASS */
#
# define CHAOS_PP_MUL_BYPASS(s, x, y) \
    CHAOS_PP_TUPLE_ELEM( \
        4, 0, \
        (CHAOS_PP_EXPR_S(s)(CHAOS_IP_MUL_1(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), 0, x, y, 0))) \
    ) \
    /**/
# define CHAOS_PP_MUL_BYPASS_ID() CHAOS_PP_MUL_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_BYPASS)
# endif
#
# define CHAOS_IP_MUL_INDIRECT(n) CHAOS_IP_MUL_ ## n
# define CHAOS_IP_MUL_0(s, im) CHAOS_IP_MUL_1(CHAOS_PP_OBSTRUCT(), s, im)
# define CHAOS_IP_MUL_1(_, s, r, x, y, z) \
    CHAOS_PP_IIF _( \
        CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(s))(CHAOS_PP_NOT_EQUAL(r, CHAOS_PP_LIMIT_MAG)) \
    )( \
        CHAOS_PP_IF _(z)( \
            CHAOS_PP_EXPONENTIAL(s, CHAOS_PP_PREV, CHAOS_IP_MUL_INDIRECT, CHAOS_PP_TUPLE_REM(4)(CHAOS_PP_INC(r), x, y, CHAOS_PP_DEC(z))), \
            CHAOS_PP_IF _(y)( \
                CHAOS_PP_EXPONENTIAL(s, CHAOS_PP_PREV, CHAOS_IP_MUL_INDIRECT, CHAOS_PP_TUPLE_REM(4)(r, x, CHAOS_PP_DEC(y), x)), \
                CHAOS_PP_TUPLE_REM(4) _(r, x, y, z) \
            ) \
        ), \
        CHAOS_PP_TUPLE_REM(4) _(r, x, y, z) \
    ) \
    /**/
#
# endif
