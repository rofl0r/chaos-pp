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
# ifndef CHAOS_PREPROCESSOR_RECURSION_BUFFER_H
# define CHAOS_PREPROCESSOR_RECURSION_BUFFER_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_BUFFER */
#
# define CHAOS_PP_BUFFER(s, size) CHAOS_PP_EXPR_S(s)(CHAOS_IP_BUFFER_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), size))
# define CHAOS_PP_BUFFER_ID() CHAOS_PP_BUFFER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BUFFER_ CHAOS_PP_LAMBDA(CHAOS_PP_BUFFER)
# endif
#
# define CHAOS_IP_BUFFER_INDIRECT() CHAOS_IP_BUFFER_I
# define CHAOS_IP_BUFFER_I(_, s, size) \
    CHAOS_PP_IF _(size)( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_BUFFER_INDIRECT _()(CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), CHAOS_PP_DEC(size))), \
        CHAOS_PP_PREV(s) \
    ) \
    /**/
#
# endif
