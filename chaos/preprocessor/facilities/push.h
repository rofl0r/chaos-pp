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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_PUSH_H
# define CHAOS_PREPROCESSOR_FACILITIES_PUSH_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/whitespace.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_PUSH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PUSH(a, ...) CHAOS_PP_CLEAN(a)CHAOS_PP_CLEAN(__VA_ARGS__)
#    define CHAOS_PP_PUSH_ CHAOS_PP_LAMBDA(CHAOS_PP_PUSH_ID)()
# else
#    define CHAOS_PP_PUSH(a, b) CHAOS_IP_PUSH_I(a)CHAOS_IP_PUSH_I(b)
# endif
#
# if !CHAOS_PP_VARIADICS
#    define CHAOS_IP_PUSH_I(x) x
# endif
#
# define CHAOS_PP_PUSH_ID() CHAOS_PP_PUSH
#
# endif
