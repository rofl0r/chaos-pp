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
# ifndef CHAOS_PREPROCESSOR_RECURSION_DELAY_H
# define CHAOS_PREPROCESSOR_RECURSION_DELAY_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_DELAY */
#
# define CHAOS_PP_DELAY(count, macro) \
    CHAOS_PP_IF_SHADOW(count)( \
        CHAOS_PP_DELAY_ID CHAOS_PP_OBSTRUCT()()(CHAOS_PP_DEC(count), macro), \
        macro \
    ) \
    /**/
# define CHAOS_PP_DELAY_ID() CHAOS_PP_DELAY
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELAY_ CHAOS_PP_LAMBDA(CHAOS_PP_DELAY)
# endif
#
# endif
