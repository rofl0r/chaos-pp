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
# ifndef CHAOS_PREPROCESSOR_DEBUG_DIVISION_BY_ZERO_H
# define CHAOS_PREPROCESSOR_DEBUG_DIVISION_BY_ZERO_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_DIVISION_BY_ZERO */
#
# define CHAOS_PP_DIVISION_BY_ZERO() CHAOS_IP_DIVISION_BY_ZERO_I(!)
# define CHAOS_PP_DIVISION_BY_ZERO_ID() CHAOS_PP_DIVISION_BY_ZERO
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIVISION_BY_ZERO_ CHAOS_PP_LAMBDA(CHAOS_PP_DIVISION_BY_ZERO)
# endif
#
# define CHAOS_IP_DIVISION_BY_ZERO_I() CHAOS_IP_DIVISION_BY_ZERO_I
#
# endif
