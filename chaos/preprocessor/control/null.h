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
# ifndef CHAOS_PREPROCESSOR_CONTROL_NULL_H
# define CHAOS_PREPROCESSOR_CONTROL_NULL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_NULL */
#
# define CHAOS_PP_NULL() "chaos/preprocessor/control/detail/null.h"
# define CHAOS_PP_NULL_ID() CHAOS_PP_NULL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NULL_ CHAOS_PP_LAMBDA(CHAOS_PP_NULL)
# endif
#
# endif
