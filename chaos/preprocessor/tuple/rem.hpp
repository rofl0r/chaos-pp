# /* (C) Copyright Paul Mensonides 2003 */
#
# ifndef CHAOS_PREPROCESSOR_TUPLE_REM_HPP
# define CHAOS_PREPROCESSOR_TUPLE_REM_HPP
#
# include <chaos/preprocessor/cat.hpp>
# include <chaos/preprocessor/config.hpp>
# include <chaos/preprocessor/lambda/ops.hpp>
#
# /* CHAOS_PP_TUPLE_REM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REM(size) CHAOS_IP_TUPLE_REM_I
#    define CHAOS_PP_TUPLE_REM_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REM)
#    define CHAOS_IP_TUPLE_REM_I(...) __VA_ARGS__
# else
#    define CHAOS_PP_TUPLE_REM(size) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_REM_, size)
#    define CHAOS_IP_TUPLE_REM_0()
#    define CHAOS_IP_TUPLE_REM_1(a) a
#    define CHAOS_IP_TUPLE_REM_2(a, b) a, b
#    define CHAOS_IP_TUPLE_REM_3(a, b, c) a, b, c
#    define CHAOS_IP_TUPLE_REM_4(a, b, c, d) a, b, c, d
#    define CHAOS_IP_TUPLE_REM_5(a, b, c, d, e) a, b, c, d, e
#    define CHAOS_IP_TUPLE_REM_6(a, b, c, d, e, f) a, b, c, d, e, f
#    define CHAOS_IP_TUPLE_REM_7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
#    define CHAOS_IP_TUPLE_REM_8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
#    define CHAOS_IP_TUPLE_REM_9(a, b, c, d, e, f, g, h, i) a, b, c, d, e, f, g, h, i
#    define CHAOS_IP_TUPLE_REM_10(a, b, c, d, e, f, g, h, i, j) a, b, c, d, e, f, g, h, i, j
#    define CHAOS_IP_TUPLE_REM_11(a, b, c, d, e, f, g, h, i, j, k) a, b, c, d, e, f, g, h, i, j, k
#    define CHAOS_IP_TUPLE_REM_12(a, b, c, d, e, f, g, h, i, j, k, l) a, b, c, d, e, f, g, h, i, j, k, l
#    define CHAOS_IP_TUPLE_REM_13(a, b, c, d, e, f, g, h, i, j, k, l, m) a, b, c, d, e, f, g, h, i, j, k, l, m
#    define CHAOS_IP_TUPLE_REM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a, b, c, d, e, f, g, h, i, j, k, l, m, n
#    define CHAOS_IP_TUPLE_REM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
#    define CHAOS_IP_TUPLE_REM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
#    define CHAOS_IP_TUPLE_REM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q
#    define CHAOS_IP_TUPLE_REM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r
#    define CHAOS_IP_TUPLE_REM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s
#    define CHAOS_IP_TUPLE_REM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t
#    define CHAOS_IP_TUPLE_REM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u
#    define CHAOS_IP_TUPLE_REM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v
#    define CHAOS_IP_TUPLE_REM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w
#    define CHAOS_IP_TUPLE_REM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x
#    define CHAOS_IP_TUPLE_REM_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y
# endif
#
# define CHAOS_PP_TUPLE_REM_ID() CHAOS_PP_TUPLE_REM
#
# /* CHAOS_PP_TUPLE_REM_CTOR */
#
# define CHAOS_PP_TUPLE_REM_CTOR(size, tuple) CHAOS_PP_TUPLE_REM(size) tuple
# define CHAOS_PP_TUPLE_REM_CTOR_ID() CHAOS_PP_TUPLE_REM_CTOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REM_CTOR_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REM_CTOR_ID)()
# endif
#
# endif