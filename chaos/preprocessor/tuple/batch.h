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
# ifndef CHAOS_PREPROCESSOR_TUPLE_BATCH_H
# define CHAOS_PREPROCESSOR_TUPLE_BATCH_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_IS_BATCH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_IS_BATCH(n, tuple) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            CHAOS_PP_SPLIT( \
                0, \
                CHAOS_PP_SPLIT( \
                    1, \
                    CHAOS_IP_TUPLE_IS_BATCH_A(n, CHAOS_IP_TUPLE_IS_BATCH_B, CHAOS_PP_REM tuple), \
                    1, 1 \
                ) \
            ), \
            0 \
        ) \
        /**/
#    define CHAOS_PP_TUPLE_IS_BATCH_ID() CHAOS_PP_TUPLE_IS_BATCH
#    define CHAOS_PP_TUPLE_IS_BATCH_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_IS_BATCH)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_IS_BATCH_A(n, b, im) \
        CHAOS_IP_TUPLE_IS_BATCH_ ## n( \
            im, \
            b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b() \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_IS_BATCH_B() 0, 0
#    define CHAOS_IP_TUPLE_IS_BATCH_1(...) 1, 1
#    define CHAOS_IP_TUPLE_IS_BATCH_2(a, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_3(a, b, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_4(a, b, c, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_5(a, b, c, d, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_6(a, b, c, d, e, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_7(a, b, c, d, e, f, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_8(a, b, c, d, e, f, g, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_9(a, b, c, d, e, f, g, h, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_10(a, b, c, d, e, f, g, h, i, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_11(a, b, c, d, e, f, g, h, i, j, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_12(a, b, c, d, e, f, g, h, i, j, k, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_13(a, b, c, d, e, f, g, h, i, j, k, l, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_14(a, b, c, d, e, f, g, h, i, j, k, l, m, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, _, ...) _
#    define CHAOS_IP_TUPLE_IS_BATCH_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, _, ...) _
# endif
#
# /* CHAOS_PP_TUPLE_BATCH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_BATCH(n, tuple) \
        CHAOS_PP_EXPAND( \
            CHAOS_PP_DEFER(CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_BATCH_, n))( \
                CHAOS_PP_REM tuple, \
            ) \
        ) \
        /**/
#    define CHAOS_PP_TUPLE_BATCH_ID() CHAOS_PP_TUPLE_BATCH
#    define CHAOS_PP_TUPLE_BATCH_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_BATCH_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_BATCH_1(a, ...) (a)
#    define CHAOS_IP_TUPLE_BATCH_2(a, b, ...) (a, b)
#    define CHAOS_IP_TUPLE_BATCH_3(a, b, c, ...) (a, b, c)
#    define CHAOS_IP_TUPLE_BATCH_4(a, b, c, d, ...) (a, b, c, d)
#    define CHAOS_IP_TUPLE_BATCH_5(a, b, c, d, e, ...) (a, b, c, d, e)
#    define CHAOS_IP_TUPLE_BATCH_6(a, b, c, d, e, f, ...) (a, b, c, d, e, f)
#    define CHAOS_IP_TUPLE_BATCH_7(a, b, c, d, e, f, g, ...) (a, b, c, d, e, f, g)
#    define CHAOS_IP_TUPLE_BATCH_8(a, b, c, d, e, f, g, h, ...) (a, b, c, d, e, f, g, h)
#    define CHAOS_IP_TUPLE_BATCH_9(a, b, c, d, e, f, g, h, i, ...) (a, b, c, d, e, f, g, h, i)
#    define CHAOS_IP_TUPLE_BATCH_10(a, b, c, d, e, f, g, h, i, j, ...) (a, b, c, d, e, f, g, h, i, j)
#    define CHAOS_IP_TUPLE_BATCH_11(a, b, c, d, e, f, g, h, i, j, k, ...) (a, b, c, d, e, f, g, h, i, j, k)
#    define CHAOS_IP_TUPLE_BATCH_12(a, b, c, d, e, f, g, h, i, j, k, l, ...) (a, b, c, d, e, f, g, h, i, j, k, l)
#    define CHAOS_IP_TUPLE_BATCH_13(a, b, c, d, e, f, g, h, i, j, k, l, m, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m)
#    define CHAOS_IP_TUPLE_BATCH_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n)
#    define CHAOS_IP_TUPLE_BATCH_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)
#    define CHAOS_IP_TUPLE_BATCH_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)
#    define CHAOS_IP_TUPLE_BATCH_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)
#    define CHAOS_IP_TUPLE_BATCH_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)
#    define CHAOS_IP_TUPLE_BATCH_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)
#    define CHAOS_IP_TUPLE_BATCH_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)
#    define CHAOS_IP_TUPLE_BATCH_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u)
#    define CHAOS_IP_TUPLE_BATCH_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v)
#    define CHAOS_IP_TUPLE_BATCH_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w)
#    define CHAOS_IP_TUPLE_BATCH_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x)
#    define CHAOS_IP_TUPLE_BATCH_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
# endif
#
# /* CHAOS_PP_TUPLE_SANS_BATCH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_SANS_BATCH(n, tuple) \
        CHAOS_PP_TUPLE_REST(CHAOS_PP_EXPAND( \
            CHAOS_PP_DEFER(CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_SANS_BATCH_, n))( \
                CHAOS_PP_REM tuple \
            ) \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_SANS_BATCH_ID() CHAOS_PP_TUPLE_SANS_BATCH
#    define CHAOS_PP_TUPLE_SANS_BATCH_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_SANS_BATCH_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_SANS_BATCH_1(...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_2(a, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_3(a, b, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_4(a, b, c, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_5(a, b, c, d, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_6(a, b, c, d, e, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_7(a, b, c, d, e, f, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_8(a, b, c, d, e, f, g, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_9(a, b, c, d, e, f, g, h, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_10(a, b, c, d, e, f, g, h, i, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_11(a, b, c, d, e, f, g, h, i, j, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_12(a, b, c, d, e, f, g, h, i, j, k, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_13(a, b, c, d, e, f, g, h, i, j, k, l, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_14(a, b, c, d, e, f, g, h, i, j, k, l, m, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, ...) (__VA_ARGS__)
#    define CHAOS_IP_TUPLE_SANS_BATCH_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, ...) (__VA_ARGS__)
# endif
#
# endif
