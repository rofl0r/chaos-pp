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
# ifndef CHAOS_PREPROCESSOR_LIMITS_H
# define CHAOS_PREPROCESSOR_LIMITS_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_LIMIT_EXPR */
#
# define CHAOS_PP_LIMIT_EXPR 512
# define CHAOS_PP_LIMIT_EXPR_ID() CHAOS_PP_LIMIT_EXPR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_EXPR_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_EXPR_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_MAG */
#
# define CHAOS_PP_LIMIT_MAG 512
# define CHAOS_PP_LIMIT_MAG_ID() CHAOS_PP_LIMIT_MAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_MAG_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_MAG_ID)()
# endif
#
# endif
