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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_FIX_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_FIX_H
#
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/bool.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_FIX_HP */
#
# define CHAOS_PP_FIX_HP(x) \
    CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_SIGN_HP(x))(CHAOS_PP_COMPL(CHAOS_PP_BOOL_HP(x))))( \
        (CHAOS_PP_BINARY(0) x, 0), x \
    ) \
    /**/
#
# endif
