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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_GREATER_EQUAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_GREATER_EQUAL_H
#
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_ARBITRARY_GREATER_EQUAL */
#
# define CHAOS_PP_ARBITRARY_GREATER_EQUAL(x, y) CHAOS_PP_ARBITRARY_LESS_EQUAL(y, x)
# define CHAOS_PP_ARBITRARY_GREATER_EQUAL_ID() CHAOS_PP_ARBITRARY_GREATER_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_GREATER_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_GREATER_EQUAL)
# endif
#
# /* CHAOS_PP_ARBITRARY_GREATER_EQUAL_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_GREATER_EQUAL_INTERNAL(x, y) CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(y, x)
#
# endif
