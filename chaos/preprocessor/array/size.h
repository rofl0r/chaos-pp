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
# ifndef CHAOS_PREPROCESSOR_ARRAY_SIZE_H
# define CHAOS_PREPROCESSOR_ARRAY_SIZE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARRAY_SIZE */
#
# define CHAOS_PP_ARRAY_SIZE(array) CHAOS_PP_SPLIT(0, CHAOS_PP_TUPLE_REM(2) array)
# define CHAOS_PP_ARRAY_SIZE_ID() CHAOS_PP_ARRAY_SIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_SIZE)
# endif
#
# endif
