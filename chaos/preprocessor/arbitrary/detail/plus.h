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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_PLUS_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_PLUS_H
#
# include <chaos/preprocessor/arbitrary/detail/lookup.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/indirect.h>
#
# /* CHAOS_PP_PLUS */
#
# define CHAOS_PP_PLUS(a, b) \
    CHAOS_PP_LOOKUP(b, CHAOS_PP_LOOKUP(a, ( \
        ((0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9)), \
        ((0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0)), \
        ((0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1)), \
        ((0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2)), \
        ((0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3)), \
        ((0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4)), \
        ((0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5)), \
        ((0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6)), \
        ((0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7)), \
        ((0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (1, 8)) \
    ))) \
    /**/
#
# /* CHAOS_PP_PLUS_3RD */
#
# define CHAOS_PP_PLUS_3RD(mode) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PLUS_3RD_, mode)
#
# define CHAOS_IP_PLUS_3RD_0(bin) (CHAOS_PP_BINARY(1) bin) CHAOS_PP_INDIRECT(CHAOS_PP_BINARY(0) bin)
# define CHAOS_IP_PLUS_3RD_1(bin, n) CHAOS_IP_PLUS_3RD_2(CHAOS_PP_BINARY(0) bin, CHAOS_PP_PLUS(CHAOS_PP_BINARY(1) bin, n))
# define CHAOS_IP_PLUS_3RD_2(a, bin) (CHAOS_PP_BINARY(1) bin) CHAOS_PP_INDIRECT(CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_PLUS(a, CHAOS_PP_BINARY(0) bin)))
#
# endif
