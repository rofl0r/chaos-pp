# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_LOGICAL_AND_H
# define CHAOS_PREPROCESSOR_LOGICAL_AND_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
#
# /* CHAOS_PP_AND */
#
# define CHAOS_PP_AND(p) CHAOS_PP_CAT(CHAOS_IP_AND_, CHAOS_PP_BOOL(p))
# define CHAOS_PP_AND_ID() CHAOS_PP_AND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AND_ CHAOS_PP_LAMBDA(CHAOS_PP_AND)
# endif
#
# define CHAOS_IP_AND_0(q) 0
# define CHAOS_IP_AND_1(q) CHAOS_PP_BOOL(q)
#
# endif
