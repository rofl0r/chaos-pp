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
# ifndef CHAOS_PREPROCESSOR_TUPLE_EAT_H
# define CHAOS_PREPROCESSOR_TUPLE_EAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_TUPLE_EAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_EAT(size) CHAOS_IP_TUPLE_EAT_I
#    define CHAOS_PP_TUPLE_EAT_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_EAT)
# else
#    define CHAOS_PP_TUPLE_EAT(size) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_EAT_, size)
# endif
#
# define CHAOS_PP_TUPLE_EAT_ID() CHAOS_PP_TUPLE_EAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_EAT_I(...)
# else
#    define CHAOS_IP_TUPLE_EAT_0()
#    define CHAOS_IP_TUPLE_EAT_1(a)
#    define CHAOS_IP_TUPLE_EAT_2(a, b)
#    define CHAOS_IP_TUPLE_EAT_3(a, b, c)
#    define CHAOS_IP_TUPLE_EAT_4(a, b, c, d)
#    define CHAOS_IP_TUPLE_EAT_5(a, b, c, d, e)
#    define CHAOS_IP_TUPLE_EAT_6(a, b, c, d, e, f)
#    define CHAOS_IP_TUPLE_EAT_7(a, b, c, d, e, f, g)
#    define CHAOS_IP_TUPLE_EAT_8(a, b, c, d, e, f, g, h)
#    define CHAOS_IP_TUPLE_EAT_9(a, b, c, d, e, f, g, h, i)
#    define CHAOS_IP_TUPLE_EAT_10(a, b, c, d, e, f, g, h, i, j)
#    define CHAOS_IP_TUPLE_EAT_11(a, b, c, d, e, f, g, h, i, j, k)
#    define CHAOS_IP_TUPLE_EAT_12(a, b, c, d, e, f, g, h, i, j, k, l)
#    define CHAOS_IP_TUPLE_EAT_13(a, b, c, d, e, f, g, h, i, j, k, l, m)
#    define CHAOS_IP_TUPLE_EAT_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)
#    define CHAOS_IP_TUPLE_EAT_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)
#    define CHAOS_IP_TUPLE_EAT_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)
#    define CHAOS_IP_TUPLE_EAT_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)
#    define CHAOS_IP_TUPLE_EAT_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)
#    define CHAOS_IP_TUPLE_EAT_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)
#    define CHAOS_IP_TUPLE_EAT_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)
#    define CHAOS_IP_TUPLE_EAT_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u)
#    define CHAOS_IP_TUPLE_EAT_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v)
#    define CHAOS_IP_TUPLE_EAT_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w)
#    define CHAOS_IP_TUPLE_EAT_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x)
#    define CHAOS_IP_TUPLE_EAT_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
# endif
#
# /* CHAOS_PP_EAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EAT(...)
#    define CHAOS_PP_EAT_ CHAOS_PP_LAMBDA(CHAOS_PP_EAT)
# else
#    define CHAOS_PP_EAT(x)
# endif
#
# define CHAOS_PP_EAT_ID() CHAOS_PP_EAT
#
# endif
