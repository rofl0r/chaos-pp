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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_BINARY_H
# define CHAOS_PREPROCESSOR_FACILITIES_BINARY_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_BINARY */
#
# define CHAOS_PP_BINARY(i) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BINARY_, i)
# define CHAOS_PP_BINARY_ID() CHAOS_PP_BINARY
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BINARY_ CHAOS_PP_LAMBDA(CHAOS_PP_BINARY)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_BINARY_0(a, ...) a
#    define CHAOS_IP_BINARY_1(a, ...) __VA_ARGS__
# else
#    define CHAOS_IP_BINARY_0(a, b) a
#    define CHAOS_IP_BINARY_1(a, b) b
# endif
#
# /* CHAOS_PP_BINARY_CTOR */
#
# define CHAOS_PP_BINARY_CTOR(i, bin) CHAOS_PP_BINARY(i) bin
# define CHAOS_PP_BINARY_CTOR_ID() CHAOS_PP_BINARY_CTOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BINARY_CTOR_ CHAOS_PP_LAMBDA(CHAOS_PP_BINARY_CTOR_ID)()
# endif
#
# endif
