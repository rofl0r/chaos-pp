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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_LESS_EQUAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_LESS_EQUAL_H
#
# include <chaos/_preprocessor/arbitrary/detail/fix.h>
# include <chaos/_preprocessor/arbitrary/detail/merge.h>
# include <chaos/_preprocessor/arbitrary/detail/rel.h>
# include <chaos/_preprocessor/arbitrary/detail/scan.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_LESS_EQUAL_AP */
#
# define CHAOS_PP_LESS_EQUAL_AP(x, y) CHAOS_IP_LESS_EQUAL_AP_I(CHAOS_PP_FIX_AP(x), CHAOS_PP_FIX_AP(y))
# define CHAOS_PP_LESS_EQUAL_AP_ID() CHAOS_PP_LESS_EQUAL_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LESS_EQUAL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_LESS_EQUAL_AP)
# endif
#
# define CHAOS_IP_LESS_EQUAL_AP_I(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(x))( \
        CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(y))( \
            CHAOS_PP_LESS_EQUAL_AP_INTERNAL(CHAOS_PP_REM y, CHAOS_PP_REM x), \
            1 \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(y))( \
            0, \
            CHAOS_PP_LESS_EQUAL_AP_INTERNAL(x, y) \
        ) \
    ) \
    /**/
#
# /* CHAOS_PP_LESS_EQUAL_AP_INTERNAL */
#
# define CHAOS_PP_LESS_EQUAL_AP_INTERNAL(x, y) \
    CHAOS_PP_COMPL(CHAOS_PP_SCAN(1)( \
        CHAOS_IP_LESS_EQUAL_AP_M(1) CHAOS_PP_FMERGE(x, y, CHAOS_IP_LESS_EQUAL_AP_M, 0)(CHAOS_PP_DEC) \
    )) \
    /**/
#
# define CHAOS_IP_LESS_EQUAL_AP_M(x) CHAOS_IP_LESS_EQUAL_AP_ ## x
# define CHAOS_IP_LESS_EQUAL_AP_0(a, b) CHAOS_PP_INDIRECT(0)
# define CHAOS_IP_LESS_EQUAL_AP_1(a, b) CHAOS_PP_INDIRECT(CHAOS_PP_REL(a, b))
# define CHAOS_IP_LESS_EQUAL_AP_2(a, b) CHAOS_PP_INDIRECT(2)
#
# endif
