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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_OR_H
# define CHAOS_PREPROCESSOR_LOGICAL_OR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
#
# /* CHAOS_PP_OR */
#
# define CHAOS_PP_OR(p) CHAOS_PP_CAT(CHAOS_IP_OR_, CHAOS_PP_BOOL(p))
# define CHAOS_PP_OR_ID() CHAOS_PP_OR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OR_ CHAOS_PP_LAMBDA(CHAOS_PP_OR)
# endif
#
# define CHAOS_IP_OR_0(q) CHAOS_PP_BOOL(q)
# define CHAOS_IP_OR_1(q) 1
#
# endif
