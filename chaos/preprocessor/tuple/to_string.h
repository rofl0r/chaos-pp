# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_TUPLE_TO_STRING_H
# define CHAOS_PREPROCESSOR_TUPLE_TO_STRING_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_TUPLE_TO_STRING */
#
# define CHAOS_PP_TUPLE_TO_STRING(size, tuple) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_TO_STRING_, size) tuple
# define CHAOS_PP_TUPLE_TO_STRING_ID() CHAOS_PP_TUPLE_TO_STRING
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_TO_STRING_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_TO_STRING_ID)()
# endif
#
# define CHAOS_IP_TUPLE_TO_STRING_0()
# define CHAOS_IP_TUPLE_TO_STRING_1(a) a
# define CHAOS_IP_TUPLE_TO_STRING_2(a, b) a b
# define CHAOS_IP_TUPLE_TO_STRING_3(a, b, c) a b c
# define CHAOS_IP_TUPLE_TO_STRING_4(a, b, c, d) a b c d
# define CHAOS_IP_TUPLE_TO_STRING_5(a, b, c, d, e) a b c d e
# define CHAOS_IP_TUPLE_TO_STRING_6(a, b, c, d, e, f) a b c d e f
# define CHAOS_IP_TUPLE_TO_STRING_7(a, b, c, d, e, f, g) a b c d e f g
# define CHAOS_IP_TUPLE_TO_STRING_8(a, b, c, d, e, f, g, h) a b c d e f g h
# define CHAOS_IP_TUPLE_TO_STRING_9(a, b, c, d, e, f, g, h, i) a b c d e f g h i
# define CHAOS_IP_TUPLE_TO_STRING_10(a, b, c, d, e, f, g, h, i, j) a b c d e f g h i j
# define CHAOS_IP_TUPLE_TO_STRING_11(a, b, c, d, e, f, g, h, i, j, k) a b c d e f g h i j k
# define CHAOS_IP_TUPLE_TO_STRING_12(a, b, c, d, e, f, g, h, i, j, k, l) a b c d e f g h i j k l
# define CHAOS_IP_TUPLE_TO_STRING_13(a, b, c, d, e, f, g, h, i, j, k, l, m) a b c d e f g h i j k l m
# define CHAOS_IP_TUPLE_TO_STRING_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a b c d e f g h i j k l m n
# define CHAOS_IP_TUPLE_TO_STRING_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a b c d e f g h i j k l m n o
# define CHAOS_IP_TUPLE_TO_STRING_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a b c d e f g h i j k l m n o p
# define CHAOS_IP_TUPLE_TO_STRING_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a b c d e f g h i j k l m n o p q
# define CHAOS_IP_TUPLE_TO_STRING_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a b c d e f g h i j k l m n o p q r
# define CHAOS_IP_TUPLE_TO_STRING_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a b c d e f g h i j k l m n o p q r s
# define CHAOS_IP_TUPLE_TO_STRING_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a b c d e f g h i j k l m n o p q r s t
# define CHAOS_IP_TUPLE_TO_STRING_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a b c d e f g h i j k l m n o p q r s t u
# define CHAOS_IP_TUPLE_TO_STRING_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a b c d e f g h i j k l m n o p q r s t u v
# define CHAOS_IP_TUPLE_TO_STRING_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a b c d e f g h i j k l m n o p q r s t u v w
# define CHAOS_IP_TUPLE_TO_STRING_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a b c d e f g h i j k l m n o p q r s t u v w x
# define CHAOS_IP_TUPLE_TO_STRING_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a b c d e f g h i j k l m n o p q r s t u v w x y
#
# endif
