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
# define CHAOS_PP_ARBITRARY_NEGATE(x) CHAOS_IP_ARBITRARY_NEGATE_I(CHAOS_PP_ARBITRARY_FIX(x))
# define CHAOS_PP_ARBITRARY_NEGATE_ID() CHAOS_PP_ARBITRARY_NEGATE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_NEGATE_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_NEGATE)
# endif
#
# define CHAOS_IP_ARBITRARY_NEGATE_I(x) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_PP_REM x, CHAOS_PP_ARBITRARY_FIX((x)) \
    ) \
    /**/
#
# endif
