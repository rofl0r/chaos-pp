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
# ifndef CHAOS_PREPROCESSOR_ARRAY_SPEC_H
# define CHAOS_PREPROCESSOR_ARRAY_SPEC_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/array/elem.h>
# include <chaos/preprocessor/array/size.h>
# include <chaos/preprocessor/array/to_tuple.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/logical/not.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
# include <chaos/preprocessor/tuple/spec.h>
#
# /* CHAOS_PP_ARRAY */
#
# define CHAOS_PP_ARRAY CHAOS_PP_ARRAY
#
# /* CHAOS_PP_ARRAY_TAG */
#
# define CHAOS_PP_ARRAY_TAG(tag) tag
# define CHAOS_PP_ARRAY_TAG_ID() CHAOS_PP_ARRAY_TAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_TAG)
# endif
#
# /* CHAOS_PP_ARRAY_NIL */
#
# define CHAOS_PP_ARRAY_NIL() (0, ())
# define CHAOS_PP_ARRAY_NIL_ID() CHAOS_PP_ARRAY_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_NIL)
# endif
#
# /* CHAOS_PP_ARRAY_CONS */
#
# define CHAOS_PP_ARRAY_CONS(array, x) \
    CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_ARRAY_CONS_I)( \
        CHAOS_PP_TUPLE_REM(2) array, x \
    )) \
    /**/
# define CHAOS_PP_ARRAY_CONS_ID() CHAOS_PP_ARRAY_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_CONS_ID)()
# endif
#
# define CHAOS_IP_ARRAY_CONS_I(size, tuple, x) \
    (CHAOS_PP_INC(size), (x CHAOS_PP_COMMA_IF(size) CHAOS_PP_TUPLE_REM(size) tuple)) \
    /**/
#
# /* CHAOS_PP_ARRAY_ITEM */
#
# define CHAOS_PP_ARRAY_ITEM(x) x
# define CHAOS_PP_ARRAY_ITEM_ID() CHAOS_PP_ARRAY_ITEM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_ITEM_ID)()
# endif
#
# /* CHAOS_PP_ARRAY_FIRST */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_FIRST(array) CHAOS_PP_TUPLE_FIRST(CHAOS_PP_ARRAY_TO_TUPLE(array))
#    define CHAOS_PP_ARRAY_FIRST_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_FIRST_ID)()
# else
#    define CHAOS_PP_ARRAY_FIRST(array) CHAOS_PP_ARRAY_ELEM(0, array)
# endif
#
# define CHAOS_PP_ARRAY_FIRST_ID() CHAOS_PP_ARRAY_FIRST
#
# /* CHAOS_PP_ARRAY_REST */
#
# define CHAOS_PP_ARRAY_REST(array) \
    CHAOS_PP_IF(CHAOS_PP_DEC(CHAOS_PP_ARRAY_SIZE(array)))( \
        CHAOS_IP_ARRAY_REST_I array, CHAOS_PP_ARRAY_NIL() \
    ) \
    /**/
# define CHAOS_PP_ARRAY_REST_ID() CHAOS_PP_ARRAY_REST
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_REST_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_REST_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARRAY_REST_I(size, tuple) (CHAOS_PP_DEC(size), (CHAOS_PP_SPLIT(1, CHAOS_PP_REM tuple)))
# else
#    define CHAOS_IP_ARRAY_REST_II(size, tuple) CHAOS_IP_ARRAY_REST_ ## size tuple
#    define CHAOS_IP_ARRAY_REST_I(size, tuple) CHAOS_IP_ARRAY_REST_ ## size tuple
#    define CHAOS_IP_ARRAY_REST_2(a, b) (1, (b))
#    define CHAOS_IP_ARRAY_REST_3(a, b, c) (2, (b, c))
#    define CHAOS_IP_ARRAY_REST_4(a, b, c, d) (3, (b, c, d))
#    define CHAOS_IP_ARRAY_REST_5(a, b, c, d, e) (4, (b, c, d, e))
#    define CHAOS_IP_ARRAY_REST_6(a, b, c, d, e, f) (5, (b, c, d, e, f))
#    define CHAOS_IP_ARRAY_REST_7(a, b, c, d, e, f, g) (6, (b, c, d, e, f, g))
#    define CHAOS_IP_ARRAY_REST_8(a, b, c, d, e, f, g, h) (7, (b, c, d, e, f, g, h))
#    define CHAOS_IP_ARRAY_REST_9(a, b, c, d, e, f, g, h, i) (8, (b, c, d, e, f, g, h, i))
#    define CHAOS_IP_ARRAY_REST_10(a, b, c, d, e, f, g, h, i, j) (9, (b, c, d, e, f, g, h, i, j))
#    define CHAOS_IP_ARRAY_REST_11(a, b, c, d, e, f, g, h, i, j, k) (10, (b, c, d, e, f, g, h, i, j, k))
#    define CHAOS_IP_ARRAY_REST_12(a, b, c, d, e, f, g, h, i, j, k, l) (11, (b, c, d, e, f, g, h, i, j, k, l))
#    define CHAOS_IP_ARRAY_REST_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (12, (b, c, d, e, f, g, h, i, j, k, l, m))
#    define CHAOS_IP_ARRAY_REST_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (13, (b, c, d, e, f, g, h, i, j, k, l, m, n))
#    define CHAOS_IP_ARRAY_REST_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (14, (b, c, d, e, f, g, h, i, j, k, l, m, n, o))
#    define CHAOS_IP_ARRAY_REST_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (15, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p))
#    define CHAOS_IP_ARRAY_REST_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (16, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q))
#    define CHAOS_IP_ARRAY_REST_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (17, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r))
#    define CHAOS_IP_ARRAY_REST_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (18, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s))
#    define CHAOS_IP_ARRAY_REST_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (19, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t))
#    define CHAOS_IP_ARRAY_REST_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (20, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u))
#    define CHAOS_IP_ARRAY_REST_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (21, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v))
#    define CHAOS_IP_ARRAY_REST_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (22, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w))
#    define CHAOS_IP_ARRAY_REST_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (23, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x))
#    define CHAOS_IP_ARRAY_REST_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (24, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y))
# endif
#
# /* CHAOS_PP_ARRAY_IS_CONS */
#
# define CHAOS_PP_ARRAY_IS_CONS(array) CHAOS_PP_COMPL(CHAOS_PP_ARRAY_IS_NIL(array))
# define CHAOS_PP_ARRAY_IS_CONS_ID() CHAOS_PP_ARRAY_IS_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_IS_CONS)
# endif
#
# /* CHAOS_PP_ARRAY_IS_NIL */
#
# define CHAOS_PP_ARRAY_IS_NIL(array) CHAOS_PP_NOT(CHAOS_PP_ARRAY_SIZE(array))
# define CHAOS_PP_ARRAY_IS_NIL_ID() CHAOS_PP_ARRAY_IS_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_IS_NIL)
# endif
#
# endif
