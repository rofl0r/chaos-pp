# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_BOOL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_BOOL_H
#
# include <chaos/_preprocessor/arbitrary/detail/fix.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_BOOL_AP */
#
# define CHAOS_PP_BOOL_AP(x) \
    CHAOS_PP_BOOL_AP_INTERNAL(CHAOS_PP_FIX_AP_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_AP(x))( \
            CHAOS_PP_REM \
        ) x \
    )) \
    /**/
#
# /* CHAOS_PP_BOOL_AP_INTERNAL */
#
# define CHAOS_PP_BOOL_AP_INTERNAL(x) \
    CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(CHAOS_IP_BOOL_AP_I x)) \
    /**/
#
# define CHAOS_IP_BOOL_AP_I(digit) CHAOS_IP_BOOL_AP_ ## digit
# define CHAOS_IP_BOOL_AP_0 ()
#
# endif
