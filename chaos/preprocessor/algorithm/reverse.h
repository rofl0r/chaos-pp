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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_REVERSE_H
# define CHAOS_PREPROCESSOR_ALGORITHM_REVERSE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_REVERSE */
#
# define CHAOS_PP_REVERSE(g) CHAOS_PP_REVERSE_BYPASS(CHAOS_PP_LIMIT_EXPR, g)
# define CHAOS_PP_REVERSE_ID() CHAOS_PP_REVERSE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REVERSE_ CHAOS_PP_LAMBDA(CHAOS_PP_REVERSE_ID)()
# endif
#
# /* CHAOS_PP_REVERSE_BYPASS */
#
# define CHAOS_PP_REVERSE_BYPASS(s, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_REVERSE_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)), g)) \
    /**/
# define CHAOS_PP_REVERSE_BYPASS_ID() CHAOS_PP_REVERSE_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REVERSE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_REVERSE_BYPASS_ID)()
# endif
#
# define CHAOS_IP_REVERSE_INDIRECT() CHAOS_IP_REVERSE_I
# define CHAOS_IP_REVERSE_I(_, s, r, g) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g))( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_REVERSE_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_CONS _(r, CHAOS_PP_FIRST _(g)), CHAOS_PP_REST _(g) \
        )), \
        r \
    ) \
    /**/
#
# endif
