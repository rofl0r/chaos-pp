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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_BITOR */
#
# define CHAOS_PP_BITOR(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITOR_, x)
# define CHAOS_PP_BITOR_ID() CHAOS_PP_BITOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITOR_ CHAOS_PP_LAMBDA(CHAOS_PP_BITOR)
# endif
#
# define CHAOS_IP_BITOR_0(y) y
# define CHAOS_IP_BITOR_1(y) 1
#
# endif
