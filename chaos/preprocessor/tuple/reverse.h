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
# ifndef CHAOS_PREPROCESSOR_TUPLE_REVERSE_H
# define CHAOS_PREPROCESSOR_TUPLE_REVERSE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_REVERSE */
#
# define CHAOS_PP_TUPLE_REVERSE(size, tuple) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_REVERSE_, size) tuple
# define CHAOS_PP_TUPLE_REVERSE_ID() CHAOS_PP_TUPLE_REVERSE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REVERSE_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REVERSE_ID)()
# endif
#
# define CHAOS_IP_TUPLE_REVERSE_0() ()
# define CHAOS_IP_TUPLE_REVERSE_1(a) (a)
# define CHAOS_IP_TUPLE_REVERSE_2(a, b) (b, a)
# define CHAOS_IP_TUPLE_REVERSE_3(a, b, c) (c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_4(a, b, c, d) (d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_5(a, b, c, d, e) (e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_6(a, b, c, d, e, f) (f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_7(a, b, c, d, e, f, g) (g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_8(a, b, c, d, e, f, g, h) (h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_9(a, b, c, d, e, f, g, h, i) (i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_10(a, b, c, d, e, f, g, h, i, j) (j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_11(a, b, c, d, e, f, g, h, i, j, k) (k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_12(a, b, c, d, e, f, g, h, i, j, k, l) (l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define CHAOS_IP_TUPLE_REVERSE_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
#
# /* CHAOS_PP_TUPLE_REVERSE_ALT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REVERSE_ALT(tuple) CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS(CHAOS_PP_LIMIT_EXPR, tuple)
#    define CHAOS_PP_TUPLE_REVERSE_ALT_ID() CHAOS_PP_TUPLE_REVERSE_ALT
#    define CHAOS_PP_TUPLE_REVERSE_ALT_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REVERSE_ALT_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS(s, tuple) \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_TUPLE_IS_CONS(tuple))( \
            (CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_REVERSE_ALT_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), tuple, CHAOS_PP_EMPTY \
            ))) \
        ) \
        /**/
#    define CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS_ID() CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS
#    define CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REVERSE_ALT_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_REVERSE_ALT_INDIRECT(n) CHAOS_IP_TUPLE_REVERSE_ALT_I
#    define CHAOS_IP_TUPLE_REVERSE_ALT_I(_, s, tuple, sep) \
        CHAOS_PP_IIF _(CHAOS_PP_TUPLE_IS_BATCH(25, tuple))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_REVERSE_ALT_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_SANS_BATCH _(25, tuple), CHAOS_PP_COMMA \
            )) \
            CHAOS_PP_TUPLE_REM_CTOR _(?, CHAOS_PP_TUPLE_REVERSE _(25, CHAOS_PP_TUPLE_BATCH _(25, tuple))) sep _(), \
            CHAOS_PP_INLINE_WHEN _(CHAOS_PP_TUPLE_IS_CONS _(tuple))( \
                CHAOS_PP_TUPLE_REM_CTOR _(?, CHAOS_PP_TUPLE_REVERSE _(CHAOS_PP_TUPLE_BATCH_FORK _(25, tuple), tuple)) sep() \
            ) \
        ) \
        /**/
# endif
#
# endif
