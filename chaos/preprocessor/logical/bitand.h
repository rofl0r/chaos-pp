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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITAND_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITAND_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_BITAND */
#
# define CHAOS_PP_BITAND(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITAND_, x)
# define CHAOS_PP_BITAND_ID() CHAOS_PP_BITAND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITAND_ CHAOS_PP_LAMBDA(CHAOS_PP_BITAND)
# endif
#
# define CHAOS_IP_BITAND_0(y) 0
# define CHAOS_IP_BITAND_1(y) y
#
# endif
