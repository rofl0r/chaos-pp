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
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_BOOL_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BOOL_AP(x) CHAOS_PP_BOOL_AP_INTERNAL(CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_SUPER_CLEAN_AP(x)))
#    define CHAOS_PP_BOOL_AP_ID() CHAOS_PP_BOOL_AP
#    define CHAOS_PP_BOOL_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_BOOL_AP)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BOOL_AP_INTERNAL(x) CHAOS_PP_IS_NULLARY(CHAOS_IP_BOOL_AP_A x)
#    define CHAOS_IP_BOOL_AP_A(x) CHAOS_PP_IF(x)((), CHAOS_IP_BOOL_AP_B)
#    define CHAOS_IP_BOOL_AP_B(x) CHAOS_PP_IF(x)((), CHAOS_IP_BOOL_AP_A)
# endif
#
# endif
