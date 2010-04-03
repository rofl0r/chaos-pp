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
# ifndef CHAOS_PREPROCESSOR_EXTENDED_PARTIAL_CAT_H
# define CHAOS_PREPROCESSOR_EXTENDED_PARTIAL_CAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_PARTIAL_CAT */
#
# define CHAOS_PP_PARTIAL_CAT(i, j) CHAOS_PP_CAT(CHAOS_IP_PARTIAL_CAT_, CHAOS_PP_PRIMITIVE_CAT(i, j))
# define CHAOS_PP_PARTIAL_CAT_ID() CHAOS_PP_PARTIAL_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_PARTIAL_CAT_00(a, ...) CHAOS_PP_PRIMITIVE_CAT(CHAOS_PP_PARTIAL ## a, __VA_ARGS__ ## CHAOS_PP_PARTIAL)
#    define CHAOS_IP_PARTIAL_CAT_01(a, ...) CHAOS_PP_PRIMITIVE_CAT(CHAOS_PP_PARTIAL ## a, __VA_ARGS__)
#    define CHAOS_IP_PARTIAL_CAT_10(a, ...) CHAOS_PP_PRIMITIVE_CAT(a, __VA_ARGS__ ## CHAOS_PP_PARTIAL)
#    define CHAOS_IP_PARTIAL_CAT_11(a, ...) CHAOS_PP_PRIMITIVE_CAT(a, __VA_ARGS__)
# else
#    define CHAOS_IP_PARTIAL_CAT_00(a, b) CHAOS_PP_PRIMITIVE_CAT(CHAOS_PP_PARTIAL ## a, b ## CHAOS_PP_PARTIAL)
#    define CHAOS_IP_PARTIAL_CAT_01(a, b) CHAOS_PP_PRIMITIVE_CAT(CHAOS_PP_PARTIAL ## a, b)
#    define CHAOS_IP_PARTIAL_CAT_10(a, b) CHAOS_PP_PRIMITIVE_CAT(a, b ## CHAOS_PP_PARTIAL)
#    define CHAOS_IP_PARTIAL_CAT_11(a, b) CHAOS_PP_PRIMITIVE_CAT(a, b)
# endif
#
# define CHAOS_PP_PARTIALCHAOS_PP_PARTIAL
#
# /* CHAOS_PP_PARTIAL */
#
# define CHAOS_PP_PARTIAL
#
# /* CHAOS_PP_PARTIAL_CAT_II */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARTIAL_CAT_II(i, j) CHAOS_PP_VARIADIC_CAT(CHAOS_IP_PARTIAL_CAT_II_, i, j)
#    define CHAOS_PP_PARTIAL_CAT_II_ID() CHAOS_PP_PARTIAL_CAT_II
#    define CHAOS_IP_PARTIAL_CAT_II_00(p, ...) CHAOS_PP_PRIMITIVE_CAT(p ## __VA_ARGS__)
#    define CHAOS_IP_PARTIAL_CAT_II_01(p, a, ...) CHAOS_PP_PRIMITIVE_CAT(p ## a, __VA_ARGS__)
#    define CHAOS_IP_PARTIAL_CAT_II_10(p, a, ...) CHAOS_PP_PRIMITIVE_CAT(a, p ## __VA_ARGS__)
#    define CHAOS_IP_PARTIAL_CAT_II_11(p, ...) CHAOS_PP_PRIMITIVE_CAT(__VA_ARGS__)
# endif
#
# endif
