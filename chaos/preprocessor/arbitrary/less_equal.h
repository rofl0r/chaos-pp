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
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/merge.h>
# include <chaos/preprocessor/arbitrary/detail/rel.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_LESS_EQUAL */
#
# define CHAOS_PP_ARBITRARY_LESS_EQUAL(x, y) CHAOS_IP_ARBITRARY_LESS_EQUAL_I(CHAOS_PP_ARBITRARY_FIX(x), CHAOS_PP_ARBITRARY_FIX(y))
# define CHAOS_PP_ARBITRARY_LESS_EQUAL_ID() CHAOS_PP_ARBITRARY_LESS_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_LESS_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_LESS_EQUAL)
# endif
#
# define CHAOS_IP_ARBITRARY_LESS_EQUAL_I(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(y))( \
            CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(CHAOS_PP_REM y, CHAOS_PP_REM x), \
            1 \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(y))( \
            0, \
            CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y) \
        ) \
    ) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y) \
    CHAOS_PP_COMPL(CHAOS_PP_SCAN(1)( \
        CHAOS_IP_ARBITRARY_LESS_EQUAL_M(1) CHAOS_PP_ARBITRARY_FMERGE(x, y, CHAOS_IP_ARBITRARY_LESS_EQUAL_M, 0)(CHAOS_PP_DEC) \
    )) \
    /**/
#
# define CHAOS_IP_ARBITRARY_LESS_EQUAL_M(x) CHAOS_IP_ARBITRARY_LESS_EQUAL_ ## x
# define CHAOS_IP_ARBITRARY_LESS_EQUAL_0(a, b) CHAOS_PP_INDIRECT(0)
# define CHAOS_IP_ARBITRARY_LESS_EQUAL_1(a, b) CHAOS_PP_INDIRECT(CHAOS_PP_ARBITRARY_REL(a, b))
# define CHAOS_IP_ARBITRARY_LESS_EQUAL_2(a, b) CHAOS_PP_INDIRECT(2)
#
# endif
