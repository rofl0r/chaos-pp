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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_BINARY_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_BINARY_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_BINARY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_BINARY(...) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_BINARY_C __VA_ARGS__)
#    define CHAOS_PP_IS_BINARY_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_BINARY)
# else
#    define CHAOS_PP_IS_BINARY(x) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_BINARY_C x)
# endif
#
# define CHAOS_PP_IS_BINARY_ID() CHAOS_PP_IS_BINARY
#
# define CHAOS_IP_IS_BINARY_C(a, b) ()
#
# endif
