# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_TUPLE_ELEM_H
# define CHAOS_PREPROCESSOR_TUPLE_ELEM_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_VARIADIC_ELEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_ELEM(i, ...) CHAOS_PP_TUPLE_ELEM(?, i, (__VA_ARGS__))
#    define CHAOS_PP_VARIADIC_ELEM_ID() CHAOS_PP_VARIADIC_ELEM
#    define CHAOS_PP_VARIADIC_ELEM_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_ELEM_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_ELEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_ELEM(size, i, tuple) CHAOS_IP_TUPLE_ELEM_I(i, CHAOS_IP_TUPLE_ELEM_A tuple)
#    define CHAOS_PP_TUPLE_ELEM_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_ELEM_ID)()
#    define CHAOS_IP_TUPLE_ELEM_A(...) CHAOS_IP_TUPLE_ELEM_B(__VA_ARGS__,,,,,,,,,,,,,,,,,,,,,,,,,)
#    define CHAOS_IP_TUPLE_ELEM_B(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) \
        (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) \
        /**/
# else
#    define CHAOS_PP_TUPLE_ELEM(size, i, tuple) \
        CHAOS_IP_TUPLE_ELEM_I( \
            i, \
            CHAOS_PP_EXPAND( \
                CHAOS_PP_DEFER(CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_ELEM_E_, size)) \
                    (CHAOS_PP_OBSTRUCT CHAOS_PP_COMMA_IF(size) CHAOS_PP_TUPLE_REM(size) tuple) \
            ) \
        ) \
        /**/
#    define CHAOS_IP_TUPLE_ELEM_E_0(_) (_(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_1(_, a) (a, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_2(_, a, b) (a, b, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_3(_, a, b, c) (a, b, c, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_4(_, a, b, c, d) (a, b, c, d, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_5(_, a, b, c, d, e) (a, b, c, d, e, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_6(_, a, b, c, d, e, f) (a, b, c, d, e, f, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_7(_, a, b, c, d, e, f, g) (a, b, c, d, e, f, g, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_8(_, a, b, c, d, e, f, g, h) (a, b, c, d, e, f, g, h, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_9(_, a, b, c, d, e, f, g, h, i) (a, b, c, d, e, f, g, h, i, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_10(_, a, b, c, d, e, f, g, h, i, j) (a, b, c, d, e, f, g, h, i, j, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_11(_, a, b, c, d, e, f, g, h, i, j, k) (a, b, c, d, e, f, g, h, i, j, k, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_12(_, a, b, c, d, e, f, g, h, i, j, k, l) (a, b, c, d, e, f, g, h, i, j, k, l, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_13(_, a, b, c, d, e, f, g, h, i, j, k, l, m) (a, b, c, d, e, f, g, h, i, j, k, l, m, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_14(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_15(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_16(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_17(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, _(), _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_18(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, _(), _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_19(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, _(), _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_20(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, _(), _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_21(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, _(), _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_22(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, _(), _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_23(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, _(), _())
#    define CHAOS_IP_TUPLE_ELEM_E_24(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, _())
#    define CHAOS_IP_TUPLE_ELEM_E_25(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
# endif
#
# define CHAOS_PP_TUPLE_ELEM_ID() CHAOS_PP_TUPLE_ELEM
#
# define CHAOS_IP_TUPLE_ELEM_I(i, tuple) CHAOS_IP_TUPLE_ELEM_ ## i tuple
# define CHAOS_IP_TUPLE_ELEM_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a
# define CHAOS_IP_TUPLE_ELEM_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) b
# define CHAOS_IP_TUPLE_ELEM_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) c
# define CHAOS_IP_TUPLE_ELEM_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) d
# define CHAOS_IP_TUPLE_ELEM_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) e
# define CHAOS_IP_TUPLE_ELEM_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) f
# define CHAOS_IP_TUPLE_ELEM_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) g
# define CHAOS_IP_TUPLE_ELEM_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) h
# define CHAOS_IP_TUPLE_ELEM_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) i
# define CHAOS_IP_TUPLE_ELEM_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) j
# define CHAOS_IP_TUPLE_ELEM_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) k
# define CHAOS_IP_TUPLE_ELEM_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) l
# define CHAOS_IP_TUPLE_ELEM_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) m
# define CHAOS_IP_TUPLE_ELEM_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) n
# define CHAOS_IP_TUPLE_ELEM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) o
# define CHAOS_IP_TUPLE_ELEM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) p
# define CHAOS_IP_TUPLE_ELEM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) q
# define CHAOS_IP_TUPLE_ELEM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) r
# define CHAOS_IP_TUPLE_ELEM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) s
# define CHAOS_IP_TUPLE_ELEM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) t
# define CHAOS_IP_TUPLE_ELEM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) u
# define CHAOS_IP_TUPLE_ELEM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) v
# define CHAOS_IP_TUPLE_ELEM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) w
# define CHAOS_IP_TUPLE_ELEM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) x
# define CHAOS_IP_TUPLE_ELEM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) y
#
# endif
