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
# ifndef CHAOS_PREPROCESSOR_COMPARISON_MIN_H
# define CHAOS_PREPROCESSOR_COMPARISON_MIN_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_MIN */
#
# define CHAOS_PP_MIN(x, y) CHAOS_PP_IIF(CHAOS_PP_LESS(y, x))(y, x)
# define CHAOS_PP_MIN_ID() CHAOS_PP_MIN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MIN_ CHAOS_PP_LAMBDA(CHAOS_PP_MIN)
# endif
#
# endif
