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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_FIX_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_FIX_H
#
# include <chaos/_preprocessor/arbitrary/bool.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FIX_AP */
#
# define CHAOS_PP_FIX_AP(x) \
    CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(x))( \
        CHAOS_IP_FIX_AP_I(CHAOS_PP_FIX_AP_INTERNAL(CHAOS_PP_REM x)), \
        CHAOS_PP_FIX_AP_INTERNAL(x) \
    ) \
    /**/
#
# define CHAOS_IP_FIX_AP_I(x) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_BOOL_AP_INTERNAL(x))( \
        CHAOS_PP_REM \
    )(x) \
    /**/
#
# /* CHAOS_PP_FIX_AP_INTERNAL */
#
# define CHAOS_PP_FIX_AP_INTERNAL(x) CHAOS_IP_FIX_AP_II(CHAOS_IP_FIX_AP_A x)
#
# define CHAOS_IP_FIX_AP_II(c) CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(c))(c, (0))
# define CHAOS_IP_FIX_AP_A(digit) CHAOS_PP_IF(digit)((digit), CHAOS_IP_FIX_AP_B)
# define CHAOS_IP_FIX_AP_B(digit) CHAOS_PP_IF(digit)((digit), CHAOS_IP_FIX_AP_A)
#
# endif
