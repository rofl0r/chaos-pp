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
# ifndef CHAOS_PREPROCESSOR_COMPARISON_MAX_H
# define CHAOS_PREPROCESSOR_COMPARISON_MAX_H
#
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_MAX */
#
# define CHAOS_PP_MAX(x, y) CHAOS_PP_IIF(CHAOS_PP_LESS(x, y))(y, x)
# define CHAOS_PP_MAX_ID() CHAOS_PP_MAX
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MAX_ CHAOS_PP_LAMBDA(CHAOS_PP_MAX)
# endif
#
# endif
