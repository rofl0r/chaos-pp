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
# ifndef CHAOS_PREPROCESSOR_GENERICS_TYPEOF_H
# define CHAOS_PREPROCESSOR_GENERICS_TYPEOF_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_TYPEOF */
#
# define CHAOS_PP_TYPEOF(g) CHAOS_PP_SPLIT(0, CHAOS_IP_TYPEOF_I g)
# define CHAOS_PP_TYPEOF_ID() CHAOS_PP_TYPEOF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TYPEOF_ CHAOS_PP_LAMBDA(CHAOS_PP_TYPEOF)
# endif
#
# define CHAOS_IP_TYPEOF_I(type) type, ~
#
# endif
