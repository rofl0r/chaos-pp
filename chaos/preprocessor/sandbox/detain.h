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
# ifndef CHAOS_PREPROCESSOR_SANDBOX_DETAIN_H
# define CHAOS_PREPROCESSOR_SANDBOX_DETAIN_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_DETAIN */
#
# define CHAOS_PP_DETAIN(pred, macro) \
    CHAOS_PP_IIF_SHADOW(pred())( \
        CHAOS_PP_DETAIN_ID CHAOS_PP_OBSTRUCT()()(pred, macro), \
        macro \
    ) \
    /**/
# define CHAOS_PP_DETAIN_ID() CHAOS_PP_DETAIN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DETAIN_ CHAOS_PP_LAMBDA(CHAOS_PP_DETAIN)
# endif
#
# endif
