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
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_ARBITRARY_EQUAL */
#
# define CHAOS_PP_ARBITRARY_EQUAL(x, y) CHAOS_IP_ARBITRARY_EQUAL_I(CHAOS_PP_ARBITRARY_FIX(x), CHAOS_PP_ARBITRARY_FIX(y))
# define CHAOS_PP_ARBITRARY_EQUAL_ID() CHAOS_PP_ARBITRARY_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_EQUAL)
# endif
#
# define CHAOS_IP_ARBITRARY_EQUAL_I(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(y))( \
            CHAOS_PP_ARBITRARY_EQUAL_INTERNAL(CHAOS_PP_REM x, CHAOS_PP_REM y), \
            0 \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(y))( \
            0, \
            CHAOS_PP_ARBITRARY_EQUAL_INTERNAL(x, y) \
        ) \
    ) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_EQUAL_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_EQUAL_INTERNAL(x, y) \
        CHAOS_PP_IS_UNARY(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_ARBITRARY_EQUAL_M(0) CHAOS_PP_FMERGE(x, y, CHAOS_IP_ARBITRARY_EQUAL_M, 0)() \
        )) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_EQUAL_INTERNAL(x, y) \
        CHAOS_PP_IS_UNARY(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_ARBITRARY_EQUAL_M(0) CHAOS_PP_FMERGE(x, y, CHAOS_IP_ARBITRARY_EQUAL_M, 0)(CHAOS_PP_DEFER(CHAOS_PP_EMPTY)()) \
        )) \
        /**/
# endif
#
# define CHAOS_IP_ARBITRARY_EQUAL_M(x) CHAOS_IP_ARBITRARY_EQUAL_II
# define CHAOS_IP_ARBITRARY_EQUAL_II(x, y) CHAOS_IP_ARBITRARY_EQUAL_ ## x ## y CHAOS_PP_INDIRECT(0)
# define CHAOS_IP_ARBITRARY_EQUAL_00
# define CHAOS_IP_ARBITRARY_EQUAL_11
# define CHAOS_IP_ARBITRARY_EQUAL_22
# define CHAOS_IP_ARBITRARY_EQUAL_33
# define CHAOS_IP_ARBITRARY_EQUAL_44
# define CHAOS_IP_ARBITRARY_EQUAL_55
# define CHAOS_IP_ARBITRARY_EQUAL_66
# define CHAOS_IP_ARBITRARY_EQUAL_77
# define CHAOS_IP_ARBITRARY_EQUAL_88
# define CHAOS_IP_ARBITRARY_EQUAL_99
#
# endif
