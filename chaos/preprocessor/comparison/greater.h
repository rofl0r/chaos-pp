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
# ifndef CHAOS_PREPROCESSOR_COMPARISON_GREATER_H
# define CHAOS_PREPROCESSOR_COMPARISON_GREATER_H
#
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_GREATER */
#
# define CHAOS_PP_GREATER(x, y) CHAOS_PP_LESS(y, x)
# define CHAOS_PP_GREATER_ID() CHAOS_PP_GREATER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_GREATER_ CHAOS_PP_LAMBDA(CHAOS_PP_GREATER)
# endif
#
# endif
