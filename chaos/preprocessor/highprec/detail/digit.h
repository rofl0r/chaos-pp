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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_DIGIT_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_DIGIT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DIGIT */
#
# define CHAOS_PP_DIGIT(n, rep) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_DIGIT_, n) rep
#
# define CHAOS_IP_DIGIT_0(a, b, c, d, e, f, g, h, i, j) j
# define CHAOS_IP_DIGIT_1(a, b, c, d, e, f, g, h, i, j) i
# define CHAOS_IP_DIGIT_2(a, b, c, d, e, f, g, h, i, j) h
# define CHAOS_IP_DIGIT_3(a, b, c, d, e, f, g, h, i, j) g
# define CHAOS_IP_DIGIT_4(a, b, c, d, e, f, g, h, i, j) f
# define CHAOS_IP_DIGIT_5(a, b, c, d, e, f, g, h, i, j) e
# define CHAOS_IP_DIGIT_6(a, b, c, d, e, f, g, h, i, j) d
# define CHAOS_IP_DIGIT_7(a, b, c, d, e, f, g, h, i, j) c
# define CHAOS_IP_DIGIT_8(a, b, c, d, e, f, g, h, i, j) b
# define CHAOS_IP_DIGIT_9(a, b, c, d, e, f, g, h, i, j) a
# define CHAOS_IP_DIGIT_10 0 CHAOS_PP_TUPLE_EAT(10)
#
# endif
