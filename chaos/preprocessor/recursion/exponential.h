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
# ifndef CHAOS_PREPROCESSOR_RECURSION_EXPONENTIAL_H
# define CHAOS_PREPROCESSOR_RECURSION_EXPONENTIAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_EXPONENTIAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXPONENTIAL(s, step, id, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)(0)( \
            step(s), CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)(1)( \
                CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), step(s), __VA_ARGS__ \
            )) \
        )) \
        /**/
#    define CHAOS_PP_EXPONENTIAL_ CHAOS_PP_LAMBDA(CHAOS_PP_EXPONENTIAL_ID)()
# else
#    define CHAOS_PP_EXPONENTIAL(s, step, id, args) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)(0)( \
            step(s), CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)(1)( \
                CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), step(s), args \
            )) \
        )) \
        /**/
# endif
#
# define CHAOS_PP_EXPONENTIAL_ID() CHAOS_PP_EXPONENTIAL
#
# endif
