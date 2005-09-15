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
# ifndef CHAOS_PREPROCESSOR_SLOT_COUNTER_H
# define CHAOS_PREPROCESSOR_SLOT_COUNTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/slot/slot.h>
#
# /* CHAOS_PP_COUNTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_COUNTER CHAOS_IP_COUNTER_I()
#    define CHAOS_PP_COUNTER_ CHAOS_PP_LAMBDA(CHAOS_PP_COUNTER_ID)()
# else
#    define CHAOS_PP_COUNTER CHAOS_PP_EXPAND(CHAOS_IP_COUNTER_I())
# endif
#
# define CHAOS_PP_COUNTER_ID() CHAOS_PP_COUNTER
#
# ifndef CHAOS_PP_SEED
#    define CHAOS_PP_SEED 0
# endif
#
# define CHAOS_IP_COUNTER_I() CHAOS_PP_SEED
#
# /* CHAOS_PP_UPDATE_COUNTER */
#
# define CHAOS_PP_UPDATE_COUNTER() "chaos/preprocessor/slot/detail/counter.h"
# define CHAOS_PP_UPDATE_COUNTER_ID() CHAOS_PP_UPDATE_COUNTER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_UPDATE_COUNTER_ CHAOS_PP_LAMBDA(CHAOS_PP_UPDATE_COUNTER)
# endif
#
# endif
