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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_XOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_XOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/logical/not.h>
#
# /* CHAOS_PP_XOR */
#
# define CHAOS_PP_XOR(p) CHAOS_PP_CAT_SHADOW(CHAOS_IP_XOR_, CHAOS_PP_BOOL(p))
# define CHAOS_PP_XOR_ID() CHAOS_PP_XOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_XOR_ CHAOS_PP_LAMBDA(CHAOS_PP_XOR)
# endif
#
# define CHAOS_IP_XOR_0(q) CHAOS_PP_BOOL(q)
# define CHAOS_IP_XOR_1(q) CHAOS_PP_NOT(q)
#
# endif
