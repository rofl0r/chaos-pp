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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_CLEAN_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_CLEAN_H
#
# include <chaos/preprocessor/arbitrary/bool.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/seq/spec.h>
#
# /* CHAOS_PP_CLEAN_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CLEAN_AP(x) CHAOS_IP_CLEAN_AP_I(CHAOS_PP_BINARY(0) x, CHAOS_PP_CLEAN_AP_INTERNAL(CHAOS_PP_BINARY(1) x))
#    define CHAOS_IP_CLEAN_AP_I(s, x) (CHAOS_PP_BITAND(s)(CHAOS_PP_BOOL_AP_INTERNAL(x)), x)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CLEAN_AP_INTERNAL(x) CHAOS_IP_CLEAN_AP_II(CHAOS_IP_CLEAN_AP_A x)
#    define CHAOS_IP_CLEAN_AP_II(c) CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(c))(c, (0))
#    define CHAOS_IP_CLEAN_AP_A(x) CHAOS_PP_IF(x)((x), CHAOS_IP_CLEAN_AP_B)
#    define CHAOS_IP_CLEAN_AP_B(x) CHAOS_PP_IF(x)((x), CHAOS_IP_CLEAN_AP_A)
# endif
#
# /* CHAOS_PP_SUPER_CLEAN_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUPER_CLEAN_AP(x) \
        CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(CHAOS_PP_SPLIT(1, CHAOS_PP_SEQ_FIRST(x),)))( \
            CHAOS_PP_CLEAN_AP(x), (0, CHAOS_PP_CLEAN_AP_INTERNAL(x)) \
        ) \
        /**/
# endif
#
# endif
