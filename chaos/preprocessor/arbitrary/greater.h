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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_GREATER_H
# define CHAOS_PREPROCESSOR_ARBITRARY_GREATER_H
#
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_ARBITRARY_GREATER */
#
# define CHAOS_PP_ARBITRARY_GREATER(x, y) CHAOS_PP_COMPL(CHAOS_PP_ARBITRARY_LESS_EQUAL(x, y))
# define CHAOS_PP_ARBITRARY_GREATER_ID() CHAOS_PP_ARBITRARY_GREATER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_GREATER_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_GREATER)
# endif
#
# /* CHAOS_PP_ARBITRARY_GREATER_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_GREATER_INTERNAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y))
#
# endif
