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
# ifndef CHAOS_PREPROCESSOR_ARRAY_ELEM_H
# define CHAOS_PREPROCESSOR_ARRAY_ELEM_H
#
# include <chaos/preprocessor/array/size.h>
# include <chaos/preprocessor/array/to_tuple.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/elem.h>
#
# /* CHAOS_PP_ARRAY_ELEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_ELEM(i, array) CHAOS_PP_TUPLE_ELEM(?, i, CHAOS_PP_ARRAY_TO_TUPLE(array))
#    define CHAOS_PP_ARRAY_ELEM_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_ELEM_ID)()
# else
#    define CHAOS_PP_ARRAY_ELEM(i, array) CHAOS_PP_TUPLE_ELEM(CHAOS_PP_ARRAY_SIZE(array), i, CHAOS_PP_ARRAY_TO_TUPLE(array))
# endif
#
# define CHAOS_PP_ARRAY_ELEM_ID() CHAOS_PP_ARRAY_ELEM
#
# endif
