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
# ifndef CHAOS_PREPROCESSOR_ARRAY_TO_STRING_H
# define CHAOS_PREPROCESSOR_ARRAY_TO_STRING_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/to_string.h>
#
# /* CHAOS_PP_ARRAY_TO_STRING */
#
# define CHAOS_PP_ARRAY_TO_STRING(array) CHAOS_PP_TUPLE_TO_STRING array
# define CHAOS_PP_ARRAY_TO_STRING_ID() CHAOS_PP_ARRAY_TO_STRING
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_TO_STRING_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_TO_STRING_ID)()
# endif
#
# endif
