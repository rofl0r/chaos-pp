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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_PLUS_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_PLUS_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/highprec/detail/digit.h>
#
# /* CHAOS_PP_PLUS */
#
# define CHAOS_PP_PLUS(a, b) \
    CHAOS_PP_DIGIT(b, CHAOS_PP_DIGIT(a, \
        ( \
            ((1, 8), (1, 7), (1, 6), (1, 5), (1, 4), (1, 3), (1, 2), (1, 1), (1, 0), (0, 9)), \
            ((1, 7), (1, 6), (1, 5), (1, 4), (1, 3), (1, 2), (1, 1), (1, 0), (0, 9), (0, 8)), \
            ((1, 6), (1, 5), (1, 4), (1, 3), (1, 2), (1, 1), (1, 0), (0, 9), (0, 8), (0, 7)), \
            ((1, 5), (1, 4), (1, 3), (1, 2), (1, 1), (1, 0), (0, 9), (0, 8), (0, 7), (0, 6)), \
            ((1, 4), (1, 3), (1, 2), (1, 1), (1, 0), (0, 9), (0, 8), (0, 7), (0, 6), (0, 5)), \
            ((1, 3), (1, 2), (1, 1), (1, 0), (0, 9), (0, 8), (0, 7), (0, 6), (0, 5), (0, 4)), \
            ((1, 2), (1, 1), (1, 0), (0, 9), (0, 8), (0, 7), (0, 6), (0, 5), (0, 4), (0, 3)), \
            ((1, 1), (1, 0), (0, 9), (0, 8), (0, 7), (0, 6), (0, 5), (0, 4), (0, 3), (0, 2)), \
            ((1, 0), (0, 9), (0, 8), (0, 7), (0, 6), (0, 5), (0, 4), (0, 3), (0, 2), (0, 1)), \
            ((0, 9), (0, 8), (0, 7), (0, 6), (0, 5), (0, 4), (0, 3), (0, 2), (0, 1), (0, 0)) \
        ) \
    )) \
    /**/
#
# /* CHAOS_PP_PLUS_3RD */
#
# define CHAOS_PP_PLUS_3RD(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PLUS_3RD_, bit)
# define CHAOS_IP_PLUS_3RD_0(bin) CHAOS_PP_BINARY(1) bin, CHAOS_PP_INDIRECT(CHAOS_PP_BINARY(0) bin)
# define CHAOS_IP_PLUS_3RD_1(bin, n) CHAOS_IP_PLUS_3RD_2(CHAOS_PP_BINARY(0) bin, CHAOS_PP_PLUS(CHAOS_PP_BINARY(1) bin, n))
# define CHAOS_IP_PLUS_3RD_2(a, bin) CHAOS_PP_BINARY(1) bin, CHAOS_PP_INDIRECT(CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_PLUS(a, CHAOS_PP_BINARY(0) bin)))
#
# endif
