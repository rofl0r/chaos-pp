# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_NEG_H
# define CHAOS_PREPROCESSOR_ARBITRARY_NEG_H
#
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# define CHAOS_PP_ARBITRARY_NEG(x) CHAOS_IP_ARBITRARY_NEG_I(CHAOS_PP_ARBITRARY_FIX(x))
# define CHAOS_PP_ARBITRARY_NEG_ID() CHAOS_PP_ARBITRARY_NEG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_NEG_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_NEG)
# endif
#
# define CHAOS_IP_ARBITRARY_NEG_I(x) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_PP_REM x, CHAOS_PP_ARBITRARY_FIX((x)) \
    ) \
    /**/
#
# endif
