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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_NEGATE_H
# define CHAOS_PREPROCESSOR_ARBITRARY_NEGATE_H
#
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# define CHAOS_PP_NEGATE_AP(x) CHAOS_IP_NEGATE_AP_I(CHAOS_PP_FIX_AP(x))
# define CHAOS_PP_NEGATE_AP_ID() CHAOS_PP_NEGATE_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NEGATE_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_NEGATE_AP)
# endif
#
# define CHAOS_IP_NEGATE_AP_I(x) \
    CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(x))( \
        CHAOS_PP_REM x, CHAOS_PP_FIX_AP((x)) \
    ) \
    /**/
#
# endif
