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
# ifndef CHAOS_PREPROCESSOR_EXTENDED_VARIADIC_CAT_H
# define CHAOS_PREPROCESSOR_EXTENDED_VARIADIC_CAT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_VARIADIC_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_CAT(...) CHAOS_IP_VARIADIC_CAT_I(__VA_ARGS__,,,,,,,,,,,,,,,,,,,,,,,,,)
#    define CHAOS_PP_VARIADIC_CAT_ID() CHAOS_PP_VARIADIC_CAT
#    define CHAOS_PP_VARIADIC_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_CAT_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_VARIADIC_CAT_I(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) \
        a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## m ## n ## o ## p ## q ## r ## s ## t ## u ## v ## w ## x ## y \
        /**/
# endif
#
# endif
