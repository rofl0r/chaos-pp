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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_NOT_EQUAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_NOT_EQUAL_H
#
# include <chaos/preprocessor/arbitrary/equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_ARBITRARY_NOT_EQUAL */
#
# define CHAOS_PP_ARBITRARY_NOT_EQUAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_ARBITRARY_EQUAL(x, y))
# define CHAOS_PP_ARBITRARY_NOT_EQUAL_ID() CHAOS_PP_ARBITRARY_NOT_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_NOT_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_NOT_EQUAL)
# endif
#
# /* CHAOS_PP_ARBITRARY_NOT_EQUAL_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_NOT_EQUAL_INTERNAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_ARBITRARY_EQUAL_INTERNAL(x, y))
#
# endif
