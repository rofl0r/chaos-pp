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
# ifndef CHAOS_PREPROCESSOR_ARRAY_REVERSE_H
# define CHAOS_PREPROCESSOR_ARRAY_REVERSE_H
#
# include <chaos/preprocessor/array/size.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/reverse.h>
#
# /* CHAOS_PP_ARRAY_REVERSE */
#
# define CHAOS_PP_ARRAY_REVERSE(array) (CHAOS_PP_ARRAY_SIZE(array), CHAOS_PP_TUPLE_REVERSE array)
# define CHAOS_PP_ARRAY_REVERSE_ID() CHAOS_PP_ARRAY_REVERSE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_REVERSE_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_REVERSE_ID)()
# endif
#
# endif
