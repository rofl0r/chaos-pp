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
# ifndef CHAOS_PREPROCESSOR_CONTROL_INLINE_WHEN_H
# define CHAOS_PREPROCESSOR_CONTROL_INLINE_WHEN_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_INLINE_WHEN */
#
# define CHAOS_PP_INLINE_WHEN(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_INLINE_WHEN_, bit)
# define CHAOS_PP_INLINE_WHEN_ID() CHAOS_PP_INLINE_WHEN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INLINE_WHEN_ CHAOS_PP_LAMBDA(CHAOS_PP_INLINE_WHEN)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_INLINE_WHEN_0(...)
#    define CHAOS_IP_INLINE_WHEN_1(...) __VA_ARGS__
# else
#    define CHAOS_IP_INLINE_WHEN_0(x)
#    define CHAOS_IP_INLINE_WHEN_1(x) x
# endif
#
# endif
