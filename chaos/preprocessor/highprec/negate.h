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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_NEGATE_H
# define CHAOS_PREPROCESSOR_HIGHPREC_NEGATE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/detail/fix.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_NEGATE_HP */
#
# define CHAOS_PP_NEGATE_HP(x) CHAOS_PP_FIX_HP((CHAOS_PP_BINARY(0) x, CHAOS_PP_COMPL(CHAOS_PP_SIGN_HP(x))))
# define CHAOS_PP_NEGATE_HP_ID() CHAOS_PP_NEGATE_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NEGATE_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_NEGATE_HP)
# endif
#
# endif
