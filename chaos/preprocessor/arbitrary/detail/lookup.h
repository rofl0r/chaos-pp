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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_LOOKUP_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_LOOKUP_H
#
# include <chaos/preprocessor/cat.h>
#
# /* CHAOS_PP_ARBITRARY_LOOKUP */
#
# define CHAOS_PP_ARBITRARY_LOOKUP(n, tuple) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_ARBITRARY_LOOKUP_, n) tuple
#
# define CHAOS_IP_ARBITRARY_LOOKUP_0(a, b, c, d, e, f, g, h, i, j) a
# define CHAOS_IP_ARBITRARY_LOOKUP_1(a, b, c, d, e, f, g, h, i, j) b
# define CHAOS_IP_ARBITRARY_LOOKUP_2(a, b, c, d, e, f, g, h, i, j) c
# define CHAOS_IP_ARBITRARY_LOOKUP_3(a, b, c, d, e, f, g, h, i, j) d
# define CHAOS_IP_ARBITRARY_LOOKUP_4(a, b, c, d, e, f, g, h, i, j) e
# define CHAOS_IP_ARBITRARY_LOOKUP_5(a, b, c, d, e, f, g, h, i, j) f
# define CHAOS_IP_ARBITRARY_LOOKUP_6(a, b, c, d, e, f, g, h, i, j) g
# define CHAOS_IP_ARBITRARY_LOOKUP_7(a, b, c, d, e, f, g, h, i, j) h
# define CHAOS_IP_ARBITRARY_LOOKUP_8(a, b, c, d, e, f, g, h, i, j) i
# define CHAOS_IP_ARBITRARY_LOOKUP_9(a, b, c, d, e, f, g, h, i, j) j
#
# endif
