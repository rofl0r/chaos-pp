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
# ifndef CHAOS_PREPROCESSOR_CONTROL_WHEN_H
# define CHAOS_PREPROCESSOR_CONTROL_WHEN_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
#
# /* CHAOS_PP_WHEN */
#
# define CHAOS_PP_WHEN(cond) CHAOS_PP_INLINE_WHEN(CHAOS_PP_BOOL(cond))
# define CHAOS_PP_WHEN_ID() CHAOS_PP_WHEN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WHEN_ CHAOS_PP_LAMBDA(CHAOS_PP_WHEN)
# endif
#
# endif
