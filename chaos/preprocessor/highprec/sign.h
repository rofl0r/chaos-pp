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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_SIGN_H
# define CHAOS_PREPROCESSOR_HIGHPREC_SIGN_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_SIGN_HP */
#
# define CHAOS_PP_SIGN_HP(x) CHAOS_PP_BINARY(1) x
# define CHAOS_PP_SIGN_HP_ID() CHAOS_PP_SIGN_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SIGN_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_SIGN_HP)
# endif
#
# endif
