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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_EQUAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_EQUAL_H
#
# include <chaos/_preprocessor/arbitrary/detail/fix.h>
# include <chaos/_preprocessor/arbitrary/detail/merge.h>
# include <chaos/_preprocessor/arbitrary/detail/scan.h>
# include <chaos/_preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_EQUAL_AP */
#
# define CHAOS_PP_EQUAL_AP(x, y) CHAOS_IP_EQUAL_AP_I(CHAOS_PP_FIX_AP(x), CHAOS_PP_FIX_AP(y))
# define CHAOS_PP_EQUAL_AP_ID() CHAOS_PP_EQUAL_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EQUAL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_EQUAL_AP)
# endif
#
# define CHAOS_IP_EQUAL_AP_I(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(x))( \
        CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(y))( \
            CHAOS_PP_EQUAL_AP_INTERNAL(CHAOS_PP_REM x, CHAOS_PP_REM y), \
            0 \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_SIGN_AP(y))( \
            0, \
            CHAOS_PP_EQUAL_AP_INTERNAL(x, y) \
        ) \
    ) \
    /**/
#
# /* CHAOS_PP_EQUAL_AP_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EQUAL_AP_INTERNAL(x, y) \
        CHAOS_PP_IS_UNARY(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_EQUAL_AP_M(0) CHAOS_PP_FMERGE(x, y, CHAOS_IP_EQUAL_AP_M, 0)() \
        )) \
        /**/
# else
#    define CHAOS_PP_EQUAL_AP_INTERNAL(x, y) \
        CHAOS_PP_IS_UNARY(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_EQUAL_AP_M(0) CHAOS_PP_FMERGE(x, y, CHAOS_IP_EQUAL_AP_M, 0)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
        )) \
        /**/
# endif
#
# define CHAOS_IP_EQUAL_AP_M(x) CHAOS_IP_EQUAL_AP_II
# define CHAOS_IP_EQUAL_AP_II(x, y) CHAOS_IP_EQUAL_AP_ ## x ## y CHAOS_PP_INDIRECT(0)
# define CHAOS_IP_EQUAL_AP_00
# define CHAOS_IP_EQUAL_AP_11
# define CHAOS_IP_EQUAL_AP_22
# define CHAOS_IP_EQUAL_AP_33
# define CHAOS_IP_EQUAL_AP_44
# define CHAOS_IP_EQUAL_AP_55
# define CHAOS_IP_EQUAL_AP_66
# define CHAOS_IP_EQUAL_AP_77
# define CHAOS_IP_EQUAL_AP_88
# define CHAOS_IP_EQUAL_AP_99
#
# endif
