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
# ifndef CHAOS_PREPROCESSOR_DEBUG_FAILURE_H
# define CHAOS_PREPROCESSOR_DEBUG_FAILURE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_FAILURE */
#
# define CHAOS_PP_FAILURE() CHAOS_IP_FAILURE_I(!)
# define CHAOS_PP_FAILURE_ID() CHAOS_PP_FAILURE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FAILURE_ CHAOS_PP_LAMBDA(CHAOS_PP_FAILURE)
# endif
#
# define CHAOS_IP_FAILURE_I() CHAOS_IP_FAILURE_I
#
# endif
